#region License
/* 
 * Copyright (C) 1999-2023 Pavel Tomin.
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

using Reko.Analysis;
using Reko.Core;
using Reko.Core.Code;
using Reko.Core.Expressions;
using Reko.Core.Intrinsics;
using Reko.Core.Operators;
using System;
using System.Diagnostics.CodeAnalysis;

namespace Reko.Arch.X86.Analysis
{
    /// <summary>
    /// Rewrites x86 strcpy chain. Expression coalescing should be done before.
    /// </summary>
    /// <remarks>
    /// Many x86 binaries contanains strcpy(&lt;dst&gt;, &lt;src&gt;) compiled
    /// as scasb/movsd/movsb sequence:
    /// <code>
    ///     mov edi,&lt;dst&gt;
    ///     mov edx,&lt;src&gt;
    ///     or ecx,0FFh
    ///     xor eax,eax
    ///     repne scasb
    ///     not ecx
    ///     sub edi,ecx
    ///     mov esi,edi
    ///     mov eax,ecx
    ///     mov edi,edx
    ///     shr ecx,2h
    ///     rep movsd
    ///     mov ecx,eax
    ///     and ecx,3h
    ///     rep movsb
    ///     ret
    /// </code>
    /// </remarks>
    public class StrcpyChainRewiter : IAnalysis<SsaState>
    {
        private readonly AnalysisContext ctx;
        private readonly ExpressionEmitter m;
        private readonly ExpressionValueComparer cmp;

        public StrcpyChainRewiter(AnalysisContext ctx)
        {
            this.ctx = ctx;
            this.m = new();
            this.cmp = new();
        }

        public string Id => "strcpy-chain-rewiter";

        public string Description => "Rewite scasb/movsd/movsb sequence as strcpy";

        public (SsaState, bool) Transform(SsaState subject)
        {
            bool changed = false;
            foreach (var block in subject.Procedure.ControlGraph.Blocks)
            {
                var stms = block.Statements.ToArray();
                for (int i = 0; i < stms.Length - 1; i++)
                {
                    if (TryRewriteStrcpy(subject, stms[i], stms[i + 1]))
                    {
                        changed = true;
                        i++;
                    }
                }
            }
            return (subject, changed);
        }

        private bool TryRewriteStrcpy(
            SsaState ssa, Statement firstStm, Statement lastStm)
        {
            if (!AsMemcpy(
                    firstStm,
                    out var firstDst,
                    out var firstSrc,
                    out var firstSize))
                return false;
            if (!AsMemcpy(
                    lastStm,
                    out var lastDst,
                    out var lastSrc,
                    out var lastSize))
                return false;
            if (!IsAdjacent(firstDst, lastDst, firstSize))
                return false;
            if (!IsAdjacent(firstSrc, lastSrc, firstSize))
                return false;
            if (!IsStrSize(ssa, firstSize, lastSize, firstSrc))
                return false;
            firstStm.Instruction = new SideEffect(
                m.Fn(Strcpy(ssa), firstDst, firstSrc));
            ssa.RemoveUses(firstStm, firstSize);
            ssa.DeleteStatement(lastStm);
            return true;
        }

        private bool IsAdjacent(Expression first, Expression last, Expression size)
        {
            if (last is not BinaryExpression bin)
                return false;
            if (bin.Operator.Type != OperatorType.IAdd)
                return false;
            if (cmp.Equals(bin.Left, first) && cmp.Equals(bin.Right, size))
                return true;
            if (cmp.Equals(bin.Right, first) && cmp.Equals(bin.Left, size))
                return true;
            return false;
        }

        private bool IsStrSize(
            SsaState ssa, Expression firstSize, Expression lastSize,
            Expression str)
        {
            firstSize = GetDefiningExpression(ssa, firstSize);
            lastSize = GetDefiningExpression(ssa, lastSize);
            if (!IsAlignment4(firstSize, out var strSize1))
                return false;
            if (!IsModulo4(lastSize, out var strSize2))
                return false;
            if (!cmp.Equals(strSize1, strSize2))
                return false;
            var strSize = GetDefiningExpression(ssa, strSize1);
            if (!IsStrlenInc1(strSize, str))
                return false;
            return true;
        }

        private bool IsAlignment4(
            Expression e,
            [MaybeNullWhen(false)] out Expression value)
        {
            value = null;
            if (e is not BinaryExpression bin)
                return false;
            if (bin.Operator.Type != OperatorType.SMul &&
                bin.Operator.Type != OperatorType.UMul &&
                bin.Operator.Type != OperatorType.IMul)
                return false;
            if (bin.Right is not Constant cRight || cRight.ToInt64() != 4)
                return false;
            if (bin.Left is not BinaryExpression leftBin)
                return false;
            if (leftBin.Operator.Type != OperatorType.Shr)
                return false;
            if (leftBin.Right is not Constant cShr || cShr.ToInt64() != 2)
                return false;
            value = leftBin.Left;
            return true;
        }

        private bool IsModulo4(
            Expression e,
            [MaybeNullWhen(false)] out Expression value)
        {
            value = null;
            if (e is not BinaryExpression bin)
                return false;
            if (bin.Operator.Type != OperatorType.And)
                return false;
            if (bin.Right is not Constant cAnd || cAnd.ToInt64() != 3)
                return false;
            value = bin.Left;
            return true;
        }

        private bool IsStrlenInc1(Expression e, Expression str)
        {
            if (e is not BinaryExpression bin)
                return false;
            if (bin.Operator.Type != OperatorType.IAdd)
                return false;
            if (!IsCallToIntrinsicProcedure(
                bin.Left, CommonOps.Strlen, out var app)
            )
                return false;
            if (!cmp.Equals(str, app.Arguments[0]))
                return false;
            if (bin.Right is not Constant c || !c.IsIntegerOne)
                return false;
            return true;
        }

        private Expression GetDefiningExpression(SsaState ssa, Expression e)
        {
            if (e is not Identifier id)
                return e;
            var defStm = ssa.Identifiers[id].DefStatement;
            if (defStm is null)
                return e;
            if (defStm.Instruction is not Assignment ass)
                return e;
            return ass.Src;
        }

        private bool AsMemcpy(
            Statement stm,
            [MaybeNullWhen(false)] out Expression dst,
            [MaybeNullWhen(false)] out Expression src,
            [MaybeNullWhen(false)] out Expression size)
        {
            src = null;
            dst = null;
            size = null;
            if (stm.Instruction is not SideEffect side)
                return false;
            if (!IsCallToIntrinsicProcedure(
                side.Expression, CommonOps.Memcpy, out var app)
            )
                return false;
            dst = app.Arguments[0];
            src =  app.Arguments[1];
            size = app.Arguments[2];
            return true;
        }

        private bool IsCallToIntrinsicProcedure(
            Expression e,
            IntrinsicProcedure intrinsic,
            [MaybeNullWhen(false)] out Application app)
        {
            app = null;
            if (e is not Application foundApp)
                return false;
            if (foundApp.Procedure is not ProcedureConstant pc)
                return false;
            if (pc.Procedure is not IntrinsicProcedure foundIntrinsic)
                return false;
            if (foundIntrinsic.Name != intrinsic.Name)
                return false;
            app = foundApp;
            return true;
        }

        private IntrinsicProcedure Strcpy(SsaState ssa)
        {
            return CommonOps.Strcpy.ResolvePointers(
                ssa.Procedure.Architecture.PointerType.BitSize);
        }
    }
}
