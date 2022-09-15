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

using Reko.Core.Expressions;
using Reko.Core.Types;
using System;

namespace Reko.Core.Operators
{
	public class SarOperator : BinaryOperator
	{
        internal SarOperator() : base(OperatorType.Sar) { }

        public override Constant ApplyConstants(Constant c1, Constant c2)
		{
            if (!ValidArgs(c1, c2))
                return InvalidConstant.Create(c1.DataType);
            return Constant.Create(
                PrimitiveType.Create(Domain.SignedInt, c1.DataType.BitSize),
                c1.ToInt64() >> c2.ToInt32());
        }

        public override string AsCompound()
        {
            return " >>= ";
        }

        public override string ToString()
		{
			return " >> ";
		}
	}
}
