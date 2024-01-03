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
using Reko.Core.Machine;
using Reko.Core.Types;
using System;
using System.Collections.Generic;
using System.Text;

namespace Reko.Environments.SysV.ArchSpecific
{
    public class Avr32CallingConvention : CallingConvention
    {
        private IProcessorArchitecture arch;

        /*
* https://www.avrfreaks.net/forum/avr32-c-compiler-calling-conventions
* The CPU has 2+14 registers that can be grouped like this:

SR - Status Register, contains CPU flags and stuff (see documentation)
PC - Program Counter, shouldnâ€™t be modified directly unless you want to do something really crazy
LR - Link Register, for calling functions, can be used as a general purpose register
SP - Stack Pointer, can be used as a general purpose register if you donâ€™t care about the stack :P
R12 - General purpose register with special role in function calls
R11-R8 - General purpose registers, used in function calls, clobberable
R7-R0 - General purpose registers, mustnâ€™t be clobbered

A normal function call works like this:
- Function arguments are put in R12 to R8 (in that order); arguments 6+ are put on the stack in some way (not sure about order).
- One of the ?CALL instructions is used to call the function. This moves the PC of the following instruction into LR.
- Inside the function R8 to R12 may be used freely without having to care about previous contents. This means that if you call another function from your function, you canâ€™t rely on the contents of these registers any more (R12 is special. See below.)
- If you need more registers, especially for stuff that should persist over calls to sub-functions, you must push some of the registers R0 to R7 onto the stack. Then you can use those freely.
- If you call a function, you need to push LR too, as the ?CALL instruction will clobber it. You should push LR before R0 to R7, as mentioned below. PUSHM/STM can do that for you.
- When youâ€™re done, place the functionâ€™s return value in R12 (No idea about functions that return structs). The RET* instruction can do that for you if itâ€™s -1, 0 or 1.
- Restore any register (of R0 to R7) that you pushed onto the stack.
- If you pushed LR onto the stack first, pop it into PC. If you didnâ€™t call any functions and LRâ€™s contents are unmodified, call a flavour of the RET* instruction, which moves LRâ€™s contents to PC after setting R12â€™s return value for you.

Interrupt handlers are similar, but the CPU will push R8 to R12 and LR onto the stack for you so that you can use them freely. Other registers must be saved by you. ISRs must be exited via the RETE instruction to restore R8 to R12 and LR.

What the different instructions do is explained in the Atmel AVR 32-bit Architecture Manual. The following instructions should have some insightful information: ACALL, ICALL, MCALL, RCALL, RET{cond4}, LDM, STM, POPM, PUSHM. If you want to write your own functions in assembly code, you should probably read up on all the arithmetic, multiplication, logic, bit, shift and data transfer instructio*/

        public Avr32CallingConvention(IProcessorArchitecture arch)
        {
            this.arch = arch;
        }

        public void Generate(
            ICallingConventionEmitter ccr,
            int retAddressOnStack,
            DataType? dtRet,
            DataType? dtThis,
            List<DataType> dtParams)
        {
            ccr.LowLevelDetails(4, 0);
            foreach (var dt in dtParams)
            {
                ccr.StackParam(dt);
            }
            if (dtRet != null)
            {
                ccr.RegReturn(arch.GetRegister("r12")!);
            }
        }

        public bool IsArgument(Storage stg)
        {
            throw new NotImplementedException();
        }

        public bool IsOutArgument(Storage stg)
        {
            throw new NotImplementedException();
        }
    }
}
