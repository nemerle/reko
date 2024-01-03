#region License
/* 
 * Copyright (C) 1999-2024 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Code;
using Reko.Core.Expressions;
using Reko.Core.Lib;
using Reko.Core.Services;
using Reko.Core.Types;
using Reko.Services;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace Reko.Analysis
{
    /// <summary>
    /// Rewrites a program, based on summary live-in and live-out
    /// information, so that all CALL codes are converted into 
    /// <see cref="Application"/>s, with the appropriate parameter lists.
    /// </summary>
    public class CallRewriter
	{
		private readonly ProgramDataFlow mpprocflow;
        private readonly IDecompilerEventListener listener;
        private readonly IPlatform platform;

        public CallRewriter(IPlatform platform, ProgramDataFlow mpprocflow, IDecompilerEventListener listener) 
		{
            this.platform = platform;
			this.mpprocflow = mpprocflow;
            this.listener = listener;
        }

		public static void Rewrite(
            IPlatform platform, 
            IReadOnlyCollection<SsaTransform> ssts,
            ProgramDataFlow summaries,
            IDecompilerEventListener eventListener)
		{
			var crw = new CallRewriter(platform, summaries, eventListener);
			foreach (SsaTransform sst in ssts)
			{
                if (eventListener.IsCanceled())
                    return;
                var proc = sst.SsaState.Procedure;
				ProcedureFlow flow = crw.mpprocflow[proc];
                flow.Dump(proc.Architecture);
				crw.EnsureSignature(sst.SsaState, flow);
			}

			foreach (SsaTransform sst in ssts)
			{
                if (eventListener.IsCanceled())
                    return;
                crw.RewriteCalls(sst.SsaState);
				crw.RewriteReturns(sst.SsaState);
                crw.RemoveStatementsFromExitBlock(sst.SsaState);
			}
		}

        /// <summary>
        /// Creates a signature for this procedure by looking at the storages
        /// modified in the exit block, and ensures that all the registers
        /// accessed by the procedure are in the procedure Frame.
        /// </summary>
        public void EnsureSignature(SsaState ssa, ProcedureFlow flow)
        {
            var proc = ssa.Procedure;
            // If we already have a signature, we don't need to do this work.
            if (!proc.Signature.ParametersValid)
            {
                var sig = MakeSignature(ssa, flow);
                flow.Signature = sig;
                proc.Signature = sig;
            }
        }

        /// <summary>
        /// Make a function signature based on the procedure flow <paramref name="flow"/>.
        /// </summary>
        /// <returns>A valid function signature.</returns>
        public FunctionType MakeSignature(SsaState ssa, ProcedureFlow flow)
        {
            var sb = new SignatureBuilder(ssa.Procedure.Frame, ssa.Procedure.Architecture);
            ProcessInputStorages(ssa, flow, sb);
            ProcessOutputStorages(ssa, flow, sb);
            var sig = sb.BuildSignature();
            if (ssa.Procedure.Signature.StackDelta != 0)
            {
                sig.StackDelta = ssa.Procedure.Signature.StackDelta;
            }
            var fpuStackDelta = flow.GetFpuStackDelta(ssa.Procedure.Architecture);
            if (fpuStackDelta != 0)
            {
                sig.FpuStackDelta = -fpuStackDelta;
            }
            return sig;
        }

        void ProcessInputStorages(SsaState ssa, ProcedureFlow flow, SignatureBuilder sb)
        {
            var frame = ssa.Procedure.Frame;
            var mayUseSeqs = flow.BitsUsed.Keys.OfType<SequenceStorage>().ToHashSet();
            var seqRegs = SequenceRegisters(flow.BitsUsed);

            //$TODO: inputs should be sorted by ABI register order, even if they are sequences.
            //$BUG: should be sorted by ABI register order. Need a new method
            // IPlatform.CreateAbiRegisterCollator().
            foreach (var seq in mayUseSeqs.OrderBy(r => r.Name))
            {
                sb.AddSequenceArgument(seq);
            }
            var mayUseRegs = flow.BitsUsed
                .Select(de => (Key: de.Key as RegisterStorage, de.Value))
                .Where(b =>
                {
                    return b.Key is RegisterStorage reg && !platform.IsImplicitArgumentRegister(reg);
                })
                .Select(MakeRegisterParameter)
                .ToDictionary(de => de.Item1, de => de.Item2);

            foreach (var (reg, _) in mayUseRegs.OrderBy(r => r.Key.Number))
            {
                if (!IsSubRegisterOfRegisters(reg, mayUseRegs) &&
                    !seqRegs.Contains(reg))
                {
                    sb.AddRegisterArgument(reg);
                }
            }

            foreach (var id in GetSortedStackArguments(frame, flow.BitsUsed))
            {
                sb.AddInParam(id.Item2);
            }

            foreach (var oFpu in flow.BitsUsed
                .Where(f => f.Key is FpuStackStorage)
                .OrderBy(r => ((FpuStackStorage) r.Key).FpuStackOffset))
            {
                var fpu = (FpuStackStorage) oFpu.Key;
                var id = frame.EnsureFpuStackVariable(fpu.FpuStackOffset, fpu.DataType);
                sb.AddFpuStackArgument(fpu.FpuStackOffset, id);
            }
        }

        void ProcessOutputStorages(SsaState ssa, ProcedureFlow flow, SignatureBuilder sb)
        {
            var frame = ssa.Procedure.Frame;
            var arch = ssa.Procedure.Architecture;

            var allLiveOut = flow.BitsLiveOut;
            var seqRegisters = SequenceRegisters(allLiveOut);
            RemoveSequenceOverlaps(allLiveOut);

            //$REVIEW: consider moving these into ProcedureFlow.
            var regsLiveOut = new Dictionary<RegisterStorage, BitRange>();
            var seqLiveOut = new Dictionary<SequenceStorage, BitRange>();
            var grfLiveOut = flow.grfLiveOut.Select(de => arch.GetFlagGroup(de.Key, de.Value)!);
            var fpuLiveOut = new Dictionary<FpuStackStorage, BitRange>();
            foreach (var de in allLiveOut)
            {
                switch (de.Key)
                {
                case RegisterStorage reg:
                    if (!seqRegisters.Contains(reg) &&
                        !platform.IsImplicitArgumentRegister(reg))
                    {
                        var (rega, regb) = MakeRegisterParameter((reg, de.Value));
                        regsLiveOut[rega] = regb;
                    }
                    break;
                case SequenceStorage seq:
                    seqLiveOut[seq] = de.Value;
                    break;
                case FpuStackStorage fpu:
                    fpuLiveOut[fpu] = de.Value;
                    break;
                }
            }

            // Prefer emitting in this order: [flags, sequences, registers, fpu args]
            // Sort the names in a stable way to avoid regression tests failing.

            foreach (var grf in grfLiveOut.OrderBy(g => g.Name))
            {
                sb.AddOutParam(frame.EnsureFlagGroup(grf));
            }

            foreach (var seq in seqLiveOut.OrderBy(r => r.Key.Name))
            {
                sb.AddOutParam(frame.EnsureSequence(seq.Key.DataType, seq.Key.Elements));
            }

            foreach (var reg in regsLiveOut.OrderBy(r => r.Key.Number).ThenBy(r => r.Key.BitAddress))
            {
                if (!IsSubRegisterOfRegisters(reg.Key, regsLiveOut))
                {
                    var regOut = sb.AddOutParam(frame.EnsureRegister(reg.Key));
                    if (regOut.Storage is OutArgumentStorage &&
                        !ssa.Identifiers.TryGetValue(regOut, out var sidOut))
                    {
                        // Ensure there are SSA identifiers for 'out' registers.
                        ssa.Identifiers.Add(regOut, null, false);
                    }
                }
            }
            foreach (var fpu in allLiveOut.Keys.OfType<FpuStackStorage>().OrderBy(r => r.FpuStackOffset))
            {
                sb.AddOutParam(frame.EnsureFpuStackVariable(fpu.FpuStackOffset, fpu.DataType));
            }
        }

        /// <summary>
        /// This method finds registers that are already present in one or 
        /// more sequences, and removes them.
        /// </summary>
        /// <param name="liveOut"></param>
        /// <returns></returns>
        private static Dictionary<Storage, BitRange> RemoveSequenceOverlaps(
            Dictionary<Storage, BitRange> liveOut)
        {
            var regsInSequences = SequenceRegisters(liveOut);
            foreach (var reg in regsInSequences)
            {
                liveOut.Remove(reg);
            }
            return liveOut;
        }

        /// <summary>
        /// Collects all registers that are part of sequences.
        /// </summary>
        private static HashSet<RegisterStorage> SequenceRegisters(Dictionary<Storage, BitRange> liveOut)
        {
            return liveOut.Keys
                .OfType<SequenceStorage>()
                .SelectMany(s => s.Elements)
                .OfType<RegisterStorage>()
                .ToHashSet();
        }

        private (RegisterStorage, BitRange) MakeRegisterParameter(
            (RegisterStorage?, BitRange) de)
        {
            var (reg, range) = de;
            var offsetWithinDomain = (int)reg!.BitAddress;
            var regParam = reg;
            if (range.Lsb != 0 || range.Msb != (int) reg.BitSize)
            {
                var regSliced = platform.Architecture.GetRegister(reg.Domain, range.Offset(offsetWithinDomain));
                regParam = regSliced ?? regParam;
            }
            return (regParam, range);
        }

        /// <summary>
        /// Make a function signature based on use and def information.
        /// </summary>
        /// <param name="ssa"></param>
        /// <param name="uses"></param>
        /// <param name="definitions"></param>
        /// <returns></returns>
        public FunctionType MakeSignature(SsaState ssa, IEnumerable<CallBinding> uses, IEnumerable<CallBinding> definitions)
        {
            var arch = ssa.Procedure.Architecture;
            var frame = arch.CreateFrame();
            var sb = new SignatureBuilder(frame, arch);

            var seqs = uses.Select(u => u.Storage as SequenceStorage)
                .Where(s => s != null)
                .OrderBy(s => s!.Name);
            foreach (var seq in seqs)
            {
                sb.AddSequenceArgument(seq!);
            }

            //$TODO: sort these by some ABI order?
            var regs = uses.Select(u => u.Storage as RegisterStorage)
                .Where(r => r is not null && !platform.IsImplicitArgumentRegister(r))
                .OrderBy(r => r!.Number);
            foreach (var reg in regs)
            {
                sb.AddRegisterArgument(reg!);
            }

            var stargs = uses.Select(u => u.Storage as StackStorage)
                .Where(s => s != null)
                .OrderBy(r => r!.StackOffset);
            foreach (var arg in stargs)
            {
                var id = frame.EnsureIdentifier(arg!);
                sb.AddInParam(id);
            }

            var outs = definitions.Select(d => d.Storage)
                .OfType<RegisterStorage>()
                .Where(r => !platform.IsImplicitArgumentRegister(r))
                .OrderBy(r => r.Number);
            foreach (var o in outs)
            {
                var id = frame.EnsureIdentifier(o);
                sb.AddOutParam(id);
            }
            var sig = sb.BuildSignature();
            return sig;
        }

        /// <summary>
        /// Returns a list of all stack arguments accessed, indexed by their offsets
        /// as seen by a caller. I.e. the first argument is at offset 0, &c.
        /// </summary>
        public IEnumerable<(int, Identifier)> GetSortedStackArguments(
            Frame frame,
            IEnumerable<KeyValuePair<Storage, BitRange>> mayuse)
        {
            return mayuse
                .Select(kv => (stg: kv.Key as StackStorage, range: kv.Value))
                .Where(item => item.stg != null)
                .OrderBy(item => item.stg!.StackOffset)
                .Select(item =>
                {
                    var id = frame.EnsureStackArgument(
                        item.stg!.StackOffset,
                        PrimitiveType.CreateWord(item.range.Extent));
                    return (item.stg.StackOffset - frame.ReturnAddressSize, id);
                });

        }

		/// <summary>
		/// Returns true if the register is a strict subregister of one of the registers in the bitset.
		/// </summary>
		/// <param name="r"></param>
		/// <param name="regs"></param>
		/// <returns></returns>
		private static bool IsSubRegisterOfRegisters(RegisterStorage rr, Dictionary<RegisterStorage, BitRange> regs)
		{
            //$TODO: move to sanitizer method RemoveSequenceOverlaps,
            // and call it RemoveStorageOverlaps
            foreach (var r2 in regs.Keys)
			{
				if (r2 is RegisterStorage rWide &&
                    rr.IsSubRegisterOf(rWide))
					return true;
			}
			return false;
		}

        public void RemoveStatementsFromExitBlock(SsaState ssa)
        {
            foreach (var stm in ssa.Procedure.ExitBlock.Statements.ToList())
            {
                ssa.DeleteStatement(stm);
            }
        }

        /// <summary>
        /// Rewrites CALL instructions to function applications.
        /// </summary>
        /// <remarks>
        /// Converts an instruction:
        /// <code>
        ///   call procExpr 
        /// </code>
        /// to one of:
        /// <code>
        ///	 ax = procExpr(bindings);
        ///  procEexpr(bindings);
        /// </code>
        /// </remarks>
        /// <param name="ssaCaller">SSA state of the procedure in which the CALL instruction exists</param>
        /// <param name="stm">The particular statement of the call instruction</param>
        /// <param name="call">The actual CALL instruction.</param>
        public bool RewriteCall(SsaState ssaCaller, Statement stm, CallInstruction call)
        {
            if (call.Callee is ProcedureConstant callee)
            {
                var procCallee = callee.Procedure;
                var sigCallee = procCallee.Signature;
                if (sigCallee is null || !sigCallee.ParametersValid)
                    return false;
                var fn = new ProcedureConstant(platform.PointerType, procCallee);
                var ab = new CallApplicationBuilder(ssaCaller, stm, call, false);
                ssaCaller.RemoveUses(stm);
                var instr = ab.CreateInstruction(fn, sigCallee, procCallee.Characteristics);
                stm.Instruction = instr;
                var ssam = new SsaMutator(ssaCaller);
                ssam.AdjustSsa(stm, call);
                return true;
            }
            else
            {
                return false;
#if NOT_READY_YET       //$TODO
                // We have an indirect call with an unknown signature. 
                // Use the guessed `uses` and `defs` to construct a signature.
                // It's likely going to be wrong, but it can be overridden with
                // user-provided metadata.
                var sigCallee = MakeSignature(ssaCaller, call.Uses, call.Definitions);
                var ab = CreateApplicationBuilder(ssaCaller, stm, call, call.Callee);
                var instr = ab.CreateInstruction(sigCallee, Core.Serialization.DefaultProcedureCharacteristics.Instance);
                stm.Instruction = instr;
                var ssam = new SsaMutator(ssaCaller);
                ssam.AdjustSsa(stm, call);
                return true;
#endif
            }
        }

        /// <summary>
        // Statements of the form:
        //		call	<ssaCaller-operand>
        // become redefined to 
        //		ret = <ssaCaller-operand>(bindings)
        // where ret is the return register (if any) and the
        // bindings are the bindings of the procedure.
        /// </summary>
        /// <param name="ssaCeller">SSA state of the calling procedure.</param>
        /// <returns>The number of calls that couldn't be converted</returns>
        public int RewriteCalls(SsaState ssaCaller)
        {
            int unConverted = 0;
            var calls = ssaCaller.Procedure.Statements
                .Where(s => s.Instruction is CallInstruction)
                .Select(s => (s, (CallInstruction) s.Instruction))
                .ToArray();
            foreach (var (stm, ci) in calls)
            {
                if (!RewriteCall(ssaCaller, stm, ci))
                    ++unConverted;
            }
            return unConverted;
        }

        /// <summary>
        /// Having identified the return variable -- if any -- rewrite all
        /// return statements to return that variable.
        /// </summary>
        /// <param name="ssa"></param>
        public void RewriteReturns(SsaState ssa)
        {
            // For each basic block reaching the exit block, get all reaching
            // definitions and then either replace the return expression or 
            // inject out variable assignments as Stores.

            var reachingBlocks = ssa.PredecessorPhiIdentifiers(ssa.Procedure.ExitBlock);
            var sig = ssa.Procedure.Signature;
            foreach (var (block, bindings) in reachingBlocks)
            {
                int insertPos = block.Statements.FindIndex(s => s.Instruction is ReturnInstruction);
                Debug.Assert(insertPos >= 0);
                var stm = block.Statements[insertPos];
                var idRet = sig.ReturnValue;
                if (idRet != null && idRet.DataType is not VoidType)
                {
                    Expression e;
                    if (idRet.Storage is SequenceStorage seq)
                    {
                        e = MakeReturnSequence(bindings, seq, idRet);
                    }
                    else
                    {
                        e = MakeReturnExpression(bindings, idRet.Storage, idRet);
                    }
                    stm.Instruction = new ReturnInstruction(e);
                    ssa.AddUses(stm);
                }
                foreach (var param in sig.Parameters!)
                {
                    if (param.Storage is OutArgumentStorage outStg)
                    {
                        Store store = MakeOutParameterStore(bindings, outStg, param);
                        var stmIns = block.Statements.Insert(insertPos, stm.Address, store);
                        ssa.AddUses(stmIns);
                        ++insertPos;
                    }
                }
            }
        }

        private static Expression MakeReturnExpression(
            CallBinding [] bindings,
            Storage reg,
            Identifier idRet)
        {
            var idStg = bindings
                .Where(cb => cb.Storage.Covers(reg))
                .FirstOrDefault();

            var e = idStg?.Expression ?? InvalidConstant.Create(idRet.DataType);

            if (idStg != null && idRet.DataType.BitSize < e.DataType.BitSize)
            {
                int offset = idStg.Storage.OffsetOf(idRet.Storage);
                e = new Slice(idRet.DataType, e, offset);
            }
            return e;
        }

        private static Expression MakeReturnSequence(
            CallBinding[] bindings,
            SequenceStorage seq,
            Identifier idRet)
        {
            var elements = seq.Elements.Select(e => (bindings
                .Where(b => b.Storage == e)
                .Select(b => b.Expression)
                .FirstOrDefault() ?? InvalidConstant.Create(e.DataType)))
                .ToArray();
            return new MkSequence(idRet.DataType, elements);
        }

        private static Store MakeOutParameterStore(
            CallBinding[] bindings,
            OutArgumentStorage outStg,
            Identifier param)
        {
            var idStg = bindings
                .Where(cb => cb.Storage == outStg.OriginalIdentifier.Storage)
                .FirstOrDefault();
            var store = new Store(
                param,
                idStg?.Expression ?? InvalidConstant.Create(param.DataType));
            return store;
        }
    }
}
