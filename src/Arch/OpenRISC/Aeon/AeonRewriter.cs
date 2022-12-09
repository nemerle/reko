#region License
/* 
 * Copyright (C) 1999-2022 John Källén.
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
using Reko.Core.Collections;
using Reko.Core.Expressions;
using Reko.Core.Intrinsics;
using Reko.Core.Machine;
using Reko.Core.Memory;
using Reko.Core.Rtl;
using Reko.Core.Services;
using Reko.Core.Types;
using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Data.Common;
using System.Diagnostics;
using System.Linq;
using System.Security.AccessControl;
using System.Text.RegularExpressions;

namespace Reko.Arch.OpenRISC.Aeon
{
    public class AeonRewriter : IEnumerable<RtlInstructionCluster>
    {
        private readonly AeonArchitecture arch;
        private readonly EndianImageReader rdr;
        private readonly ProcessorState state;
        private readonly IStorageBinder binder;
        private readonly IRewriterHost host;
        private readonly LookaheadEnumerator<AeonInstruction> dasm;
        private readonly List<RtlInstruction> rtls;
        private readonly RtlEmitter m;
        private AeonInstruction instr;
        private Address addrInstr;
        private InstrClass iclass;

        public AeonRewriter(AeonArchitecture arch, EndianImageReader rdr, ProcessorState state, IStorageBinder binder, IRewriterHost host)
        {
            this.arch = arch;
            this.rdr = rdr;
            this.state = state;
            this.binder = binder;
            this.host = host;
            dasm = new LookaheadEnumerator<AeonInstruction>(new AeonDisassembler(arch, rdr));
            rtls = new List<RtlInstruction>();
            m = new RtlEmitter(rtls);
            instr = default!;
            addrInstr = default!;
        }

        public IEnumerator<RtlInstructionCluster> GetEnumerator()
        {
            while (dasm.MoveNext())
            {
                this.instr = dasm.Current;
                this.addrInstr = instr.Address;
                iclass = instr.InstructionClass;
                switch (instr.Mnemonic)
                {
                default:
                    EmitUnitTest();
                    iclass = InstrClass.Invalid;
                    m.Invalid();
                    break;
                case Mnemonic.bt_add__:
                case Mnemonic.bn_add: RewriteArithmetic(m.IAdd); break;
                case Mnemonic.l_add____: RewriteArithmetic(m.IAdd); break;
                case Mnemonic.bt_addi__:
                case Mnemonic.bn_addi:
                case Mnemonic.bg_addi: RewriteAddi(); break;
                case Mnemonic.bn_and: RewriteArithmetic(m.And); break;
                case Mnemonic.bn_andi:
                case Mnemonic.bg_andi: RewriteLogicalImm(m.And); break;
                case Mnemonic.bn_beqi__:
                case Mnemonic.bg_beqi__: RewriteBxxi(m.Eq); break;
                case Mnemonic.bn_bf:
                case Mnemonic.bg_bf: RewriteBf(true); break;
                case Mnemonic.bgtu__: RewriteBxx(m.Gt); break;
                case Mnemonic.bgtui__: RewriteBxxi(m.Gt); break;
                case Mnemonic.bn_ble__i__: RewriteBxxi(m.Le); break;
                case Mnemonic.bg_blti__: RewriteBxxi(m.Lt); break;
                case Mnemonic.bn_bnf__: RewriteBf(false); break;
                case Mnemonic.bne__: RewriteBxxi(m.Ne); break;
                case Mnemonic.bn_bnei__: RewriteBxxi(m.Ne); break;
                case Mnemonic.bt_trap: RewriteUnknown(); break;
                case Mnemonic.l_cmov____: RewriteCmov(); break;
                case Mnemonic.l_cmovi____: RewriteCmov(); break;
                case Mnemonic.bn_divu: RewriteArithmetic(m.UDiv); break;
                case Mnemonic.bn_entri__: RewriteUnknown(); break;
                case Mnemonic.bg_flush_line: RewriteFlushLine(); break;
                case Mnemonic.bg_invalidate_line: RewriteInvalidateLine(); break;
                case Mnemonic.bt_j:
                case Mnemonic.bg_j: RewriteJ(); break;
                case Mnemonic.bg_jal: RewriteJal(); break;
                case Mnemonic.bt_jr: RewriteJr(); break;
                case Mnemonic.bg_lbz__: RewriteLoadZex(PrimitiveType.Byte); break;
                case Mnemonic.bn_lhz:
                case Mnemonic.bg_lhz__: RewriteLoadZex(PrimitiveType.UInt16); break;
                case Mnemonic.bn_lwz__:
                case Mnemonic.bg_lwz__: RewriteLoadZex(PrimitiveType.Word32); break;
                case Mnemonic.bg_mfspr: RewriteIntrinsic(l_mfspr_intrinsic); break;
                case Mnemonic.bt_mov__: RewriteMov(); break;
                case Mnemonic.bt_movi__: RewriteMovi(); break;
                case Mnemonic.l_movhi: RewriteMovhi(); break;
                case Mnemonic.l_movhi__: RewriteMovhi(); break;
                case Mnemonic.bg_mtspr: RewriteSideEffect(l_mtspr_intrinsic); break;
                case Mnemonic.bn_nand__: RewriteNand(); break;
                case Mnemonic.bt_nop: 
                case Mnemonic.bn_nop: RewriteNop(); break;
                case Mnemonic.bn_mul: RewriteArithmetic(m.IMul); break;
                case Mnemonic.bn_or: RewriteArithmetic(m.Or); break;
                case Mnemonic.l_ori: RewriteOri(m.Or); break;
                case Mnemonic.bn_sfeqi: RewriteSfxx(m.Eq); break;
                case Mnemonic.bn_sfgeu: RewriteSfxx(m.Uge); break;
                case Mnemonic.bn_sfgtui: RewriteSfxx(m.Ugt); break;
                case Mnemonic.bn_sfleui__: RewriteSfxx(m.Ule); break;
                case Mnemonic.bn_sfltu: RewriteSfxx(m.Ult); break;
                case Mnemonic.bn_sfne: RewriteSfxx(m.Ne); break;
                case Mnemonic.bg_sfnei__: RewriteSfxx(m.Ne); break;
                case Mnemonic.bn_sb__:
                case Mnemonic.bg_sb__: RewriteStore(PrimitiveType.Byte); break;
                case Mnemonic.bn_sh__: 
                case Mnemonic.bg_sh__: RewriteStore(PrimitiveType.Word16); break;
                case Mnemonic.bn_sll__: RewriteShift(m.Shl); break;
                case Mnemonic.bn_slli__: RewriteShifti(m.Shl); break;
                case Mnemonic.bn_srl__: RewriteShift(m.Shr); break;
                case Mnemonic.bn_srai__: RewriteShifti(m.Sar); break;
                case Mnemonic.bn_srli__: RewriteShifti(m.Shr); break;
                case Mnemonic.bn_sub: RewriteArithmetic(m.ISub); break;
                case Mnemonic.bn_sw:
                case Mnemonic.bg_sw:
                case Mnemonic.bg_sw__: RewriteStore(PrimitiveType.Word32); break;
                case Mnemonic.bg_syncwritebuffer: RewriteSideEffect(syncwritebuffer_intrinsic); break;
                case Mnemonic.bn_xor__: RewriteArithmetic(m.Xor); break;
                    //$TODO: when all instructions are known this code can be removed.
                case Mnemonic.Nyi:
                    instr.Operands = Array.Empty<MachineOperand>();
                    RewriteUnknown();
                    break;
                }
                // Account for instruction fused into l.movhi
                var instrLength = (int) ((instr.Address - addrInstr) + instr.Length);
                yield return m.MakeCluster(addrInstr, instrLength, iclass);
                rtls.Clear();
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

        private void EmitUnitTest()
        {
            var testgenSvc = arch.Services.GetService<ITestGenerationService>();
            testgenSvc?.ReportMissingRewriter("AeonRw", instr, instr.Mnemonic.ToString(), rdr, "");
        }

        private Expression EffectiveAddress(MemoryOperand mem)
        {
            Expression ea = binder.EnsureRegister(mem.Base!);
            if (mem.Offset != 0)
            {
                ea = m.AddSubSignedInt(ea, mem.Offset);
            }
            return ea;
        }

        private void MaybeSlice(DataType dt, Expression dst, Expression src)
        {
            if (dt.BitSize < src.DataType.BitSize)
            {
                var tmp = binder.CreateTemporary(dt);
                m.Assign(tmp, m.Slice(src, dt));
                src = tmp;
            }
            m.Assign(dst, src);
        }

        private void MaybeZeroExtend(DataType dt, Expression dst, Expression src)
        {
            if (src.DataType.BitSize < 32)
            {
                var tmp = binder.CreateTemporary(dt);
                m.Assign(tmp, src);
                m.Assign(dst, m.Convert(tmp, tmp.DataType, dst.DataType));
            }
            else
            {
                m.Assign(dst, src);
            }
        }

        private Expression Op(int iop)
        {
            var op = instr.Operands[iop];
            switch (op)
            {
            case RegisterStorage reg:
                return binder.EnsureRegister(reg);
            case ImmediateOperand imm:
                return imm.Value;
            case AddressOperand addr:
                return addr.Address;
            case MemoryOperand mem:
                var ea = EffectiveAddress(mem);
                return m.Mem(mem.Width, ea);
            default:
                throw new NotImplementedException($"Not impemented: {op.GetType().Name}.");
            }
        }

        private Expression OpOrZero(int iop)
        {
            var op = instr.Operands[iop];
            switch (op)
            {
            case RegisterStorage reg:
                if (reg.Number == 0)
                    return m.Word32(0);
                return binder.EnsureRegister(reg);
            case ImmediateOperand imm:
                return imm.Value;
            case AddressOperand addr:
                return addr.Address;
            case MemoryOperand mem:
                var ea = EffectiveAddress(mem);
                return m.Mem(mem.Width, ea);
            default:
                throw new NotImplementedException($"Not impemented: {op.GetType().Name}.");
            }
        }

        private void RewriteAddi()
        {
            Expression left;
            int right;
            if (instr.Operands.Length == 2)
            {
                left = Op(0);
                right = ((ImmediateOperand) instr.Operands[1]).Value.ToInt32();
            }
            else
            {
                left = OpOrZero(1);
                right = ((ImmediateOperand) instr.Operands[2]).Value.ToInt32();
            }
            Expression src;
            if (left.IsZero)
            {
                src = m.Int32(right);
            }
            else
            {
                src = m.AddSubSignedInt(left, right);
            }
            m.Assign(Op(0), src);
        }

        private void RewriteArithmetic(Func<Expression, Expression, Expression> fn)
        {
            Expression left;
            Expression right;
            if (instr.Operands.Length == 2)
            {
                left = Op(0);
                right = OpOrZero(1);
            }
            else
            {
                left = OpOrZero(1);
                right = OpOrZero(2);
            }
            var dst = Op(0);
            m.Assign(dst, fn(left, right));
        }

        private void RewriteBf(bool condition)
        {
            Expression c = binder.EnsureFlagGroup(Registers.F);
            if (!condition)
            {
                c = m.Not(c);
            }
            m.Branch(c, (Address) Op(0));
        }

        private void RewriteBxx(Func<Expression, Expression, Expression> cmp)
        {
            var left = OpOrZero(0);
            var right = OpOrZero(1);
            var target = ((AddressOperand) instr.Operands[2]).Address;
            m.Branch(cmp(left, right), target);
        }

        private void RewriteBxxi(Func<Expression, Expression, Expression> cmp)
        {
            var left = OpOrZero(0);
            var right = Op(1);
            var target = ((AddressOperand) instr.Operands[2]).Address;
            m.Branch(cmp(left, right), target);
        }

        private void RewriteCmov()
        {
            var cond = binder.EnsureFlagGroup(Registers.F);
            var thenOp = OpOrZero(1);
            var elseOp = OpOrZero(2);
            var dst = Op(0);
            m.Assign(dst, m.Conditional(dst.DataType, cond, thenOp, elseOp));
        }

        private void RewriteLoadZex(PrimitiveType dt)
        {
            var src = Op(1);
            var dst = Op(0);
            MaybeZeroExtend(dt, dst, src);
        }

        private void RewriteMov()
        {
            var src = OpOrZero(1);
            var dst = Op(0);
            m.Assign(dst, src);
        }

        private void RewriteMovi()
        {
            var imm = ((ImmediateOperand) instr.Operands[1]).Value.ToUInt32();
            var dst = Op(0);
            m.Assign(dst, m.Word32(imm));
        }

        private void RewriteMovhi()
        {
            var movhi = this.instr;
            var immHi = ((ImmediateOperand) instr.Operands[1]).Value.ToUInt32();
            var regHi = (RegisterStorage) instr.Operands[0];
            var dst = binder.EnsureRegister(regHi);
            m.Assign(dst, m.Word32(immHi << 16));

            if (dasm.TryPeek(1, out var lowInstr))
            {
                switch (lowInstr!.Mnemonic)
                {
                case Mnemonic.bg_lbz__:
                case Mnemonic.bn_lhz:
                case Mnemonic.bg_lhz__:
                case Mnemonic.bn_lwz__:
                case Mnemonic.bg_lwz__:
                    var memLd = (MemoryOperand) lowInstr.Operands[1];
                    if (memLd.Base != regHi)
                        return;
                    dasm.MoveNext();
                    this.instr = dasm.Current;
                    uint uFullWord = MovhiSequenceFuser.AddFullWord(movhi.Operands[1], memLd.Offset);
                    var ea = Address.Ptr32(uFullWord);
                    MaybeZeroExtend(memLd.Width, Op(0), m.Mem(memLd.Width, ea));
                    break;
                case Mnemonic.bn_sb__:
                case Mnemonic.bg_sb__:
                case Mnemonic.bn_sh__:
                case Mnemonic.bg_sh__:
                case Mnemonic.bn_sw:
                case Mnemonic.bg_sw:
                case Mnemonic.bg_sw__:
                    var memSt = (MemoryOperand) lowInstr.Operands[0];
                    if (memSt.Base != regHi)
                        return;
                    dasm.MoveNext();
                    this.instr = dasm.Current;
                    uFullWord = MovhiSequenceFuser.AddFullWord(movhi.Operands[1], memSt.Offset);
                    ea = Address.Ptr32(uFullWord);
                    MaybeSlice(memSt.Width, m.Mem(memSt.Width, ea), Op(1));
                    break;
                case Mnemonic.bt_addi__:
                case Mnemonic.bn_addi:
                case Mnemonic.bg_addi:
                    var addReg = (RegisterStorage) lowInstr.Operands[1];
                    if (addReg != regHi)
                        return;
                    dasm.MoveNext();
                    this.instr = dasm.Current;
                    var iop = lowInstr.Operands.Length == 2 ? 1 : 2;
                    var addImm = (ImmediateOperand) lowInstr.Operands[iop];
                    uFullWord = MovhiSequenceFuser.AddFullWord(movhi.Operands[1], addImm.Value.ToInt32());
                    m.Assign(Op(0), m.Word32(uFullWord));
                    break;
                case Mnemonic.l_ori:
                    var orReg = (RegisterStorage) lowInstr.Operands[1];
                    if (orReg != regHi)
                        return;
                    dasm.MoveNext();
                    this.instr = dasm.Current;
                    iop = lowInstr.Operands.Length == 2 ? 1 : 2;
                    var orImm = (ImmediateOperand) lowInstr.Operands[iop];
                    uFullWord = MovhiSequenceFuser.OrFullWord(movhi.Operands[1], orImm.Value.ToUInt32());
                    m.Assign(Op(0), m.Word32(uFullWord));
                    break;
                }
            }
        }

        private void RewriteNand()
        {
            var left = OpOrZero(1);
            var right = OpOrZero(2);
            var dst = Op(0);
            Expression exp;
            if (left == right)
            {
                exp = left;
            } else {
                exp = m.And(left, right);
            }
            m.Assign(dst, m.Comp(exp));
        }

        private void RewriteNop()
        {
            m.Nop();
        }


        private void RewriteOri(Func<Expression, Expression, Expression> fn)
        {
            Expression left;
            Expression right;
            if (instr.Operands.Length == 2)
            {
                left = Op(0);
                right = m.Word32(((ImmediateOperand) instr.Operands[1]).Value.ToUInt32());
            }
            else
            {
                left = OpOrZero(1);
                right = m.Word32(((ImmediateOperand) instr.Operands[2]).Value.ToUInt32());
            }
            Expression src;
            if (left.IsZero)
            {
                src = right;
            }
            else
            {
                src = fn(left, right);
            }
            m.Assign(Op(0), src);
        }

        private void RewriteLogicalImm(Func<Expression, Expression, Expression> fn)
        {
            var left = OpOrZero(1);
            var right = ((ImmediateOperand) instr.Operands[2]).Value.ToUInt32();
            var dst = Op(0);
            m.Assign(dst, fn(left, m.Word32(right)));
        }

        private void RewriteFlushLine()
        {
            var ea = m.AddrOf(PrimitiveType.Ptr32, Op(0));
            var way = Op(1);
            m.SideEffect(m.Fn(l_flush_line_intrinsic, ea, way));
        }
        private void RewriteInvalidateLine()
        {
            var ea = m.AddrOf(PrimitiveType.Ptr32, Op(0));
            var way = Op(1);
            m.SideEffect(m.Fn(l_invalidate_line_intrinsic, ea, way));
        }

        private void RewriteJ()
        {
            var target = Op(0);
            m.Goto(target);
        }

        private void RewriteJal()
        {
            var target = Op(0);
            m.Call(target, 0);
        }

        private void RewriteJr()
        {
            var op0 = (Identifier)Op(0);
            if ((int)op0.Storage.Domain == 9)
            {
                //$REVIEW: this is a weird encoding for a return
                iclass = InstrClass.Transfer | InstrClass.Return;
                m.Return(0, 0);
                return;
            }
            //$REVIEW: could be a call, r9 seems to be used as a link register.
            m.Goto(op0);
        }

        private void RewriteSfxx(Func<Expression, Expression, Expression> fn) 
        {
            var left = OpOrZero(0);
            var right = OpOrZero(1);
            var dst = binder.EnsureFlagGroup(Registers.F);
            m.Assign(dst, fn(left, right));
        }

        private void RewriteShift(Func<Expression, Expression, Expression> fn)
        {
            var left = OpOrZero(1);
            var right = OpOrZero(2);
            var dst = Op(0);
            m.Assign(dst, fn(left, right));
        }

        private void RewriteShifti(Func<Expression, Expression, Expression> fn)
        {
            var left = OpOrZero(1);
            var right = ((ImmediateOperand) instr.Operands[2]).Value.ToInt32();
            var dst = Op(0);
            m.Assign(dst, fn(left, m.Int32(right)));
        }

        private void RewriteSideEffect(IntrinsicProcedure intrinsic)
        {
            var args = new List<Expression> { };
            for (int iop = 0; iop < instr.Operands.Length; ++iop)
            {
                args.Add(OpOrZero(iop));
            }
            m.SideEffect(m.Fn(intrinsic, args.ToArray()));
        }

        private void RewriteIntrinsic(IntrinsicProcedure intrinsic)
        {
            var args = new List<Expression> { };
            for (int iop = 1; iop < instr.Operands.Length; ++iop)
            {
                args.Add(OpOrZero(iop));
            }
            m.Assign(Op(0), m.Fn(intrinsic, args.ToArray()));
        }

        private void RewriteStore(PrimitiveType dt)
        {
            var src = OpOrZero(1);
            var dst = Op(0);
            MaybeSlice(dt, dst, src);
        }

        //$TODO: remove this once all instructions are known. It
        // is a globally mutable cache, which will cause race
        // conditions in multithreaded environments.
        private readonly static ConcurrentDictionary<Mnemonic, IntrinsicProcedure> intrinsics = new();

        private void RewriteUnknown()
        {
            var args = new List<Expression> { };
            for (int iop = 0; iop < instr.Operands.Length; ++iop)
            {
                args.Add(Op(iop));
            }
            IntrinsicProcedure? intrinsic;
            while (!intrinsics.TryGetValue(instr.Mnemonic, out intrinsic))
            {
                var ib = new IntrinsicBuilder(instr.MnemonicAsString, true);
                foreach (var e in args)
                {
                    ib.Param(e.DataType);
                }
                intrinsic = ib.Void();
                if (intrinsics.TryAdd(instr.Mnemonic, intrinsic))
                    break;
            }
            m.SideEffect(m.Fn(intrinsic, args.ToArray()));
        }

        private static readonly IntrinsicProcedure l_flush_line_intrinsic = new IntrinsicBuilder("__flush_line", true)
            .Param(PrimitiveType.Ptr32)
            .Param(PrimitiveType.UInt32)
            .Void();

        private static readonly IntrinsicProcedure l_invalidate_line_intrinsic = new IntrinsicBuilder("__invalidate_line", true)
            .Param(PrimitiveType.Ptr32)
            .Param(PrimitiveType.UInt32)
            .Void();

        private static readonly IntrinsicProcedure l_mfspr_intrinsic = new IntrinsicBuilder("__move_from_spr", true)
            .Param(PrimitiveType.Word32)
            .Param(PrimitiveType.Word32)
            .Returns(PrimitiveType.Word32);

        private static readonly IntrinsicProcedure l_mtspr_intrinsic = new IntrinsicBuilder("__move_to_spr", true)
            .Param(PrimitiveType.Word32)
            .Param(PrimitiveType.Word32)
            .Param(PrimitiveType.Word32)
            .Void();

        private static readonly IntrinsicProcedure syncwritebuffer_intrinsic = new IntrinsicBuilder("__syncwritebuffer", true)
            .Void();
    }
}
