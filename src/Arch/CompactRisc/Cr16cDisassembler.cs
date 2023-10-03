#region License
/* 
 * Copyright (C) 1999-2023 John Källén.
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
using Reko.Core.Expressions;
using Reko.Core.Lib;
using Reko.Core.Machine;
using Reko.Core.Memory;
using Reko.Core.Services;
using Reko.Core.Types;
using System;
using System.Collections.Generic;

namespace Reko.Arch.CompactRisc
{
    using Decoder = Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction>;

    public class Cr16cDisassembler : DisassemblerBase<Cr16Instruction, Mnemonic>
    {
        private static readonly Decoder rootDecoder;

        private readonly Cr16Architecture arch;
        private readonly EndianImageReader rdr;
        private readonly List<MachineOperand> ops;
        private Address addr;

        public Cr16cDisassembler(Cr16Architecture arch, EndianImageReader rdr)
        {
            this.arch = arch;
            this.rdr = rdr;
            this.ops = new List<MachineOperand>();
            this.addr = rdr.Address;
        }

        public override Cr16Instruction? DisassembleInstruction()
        {
            if (!rdr.TryReadLeUInt16(out ushort uInstr))
                return null;
            var instr = rootDecoder.Decode(uInstr, this);
            var addrNew = rdr.Address;
            instr.Address = this.addr;
            instr.Length = (int) (addrNew - this.addr);
            this.addr = addrNew;
            this.ops.Clear();
            return instr;
        }

        public override Cr16Instruction MakeInstruction(InstrClass iclass, Mnemonic mnemonic)
        {
            return new Cr16Instruction
            {
                InstructionClass = iclass,
                Mnemonic = mnemonic,
                Operands = ops.ToArray()
            };
        }

        public override Cr16Instruction CreateInvalidInstruction()
        {
            return new Cr16Instruction
            {
                InstructionClass = InstrClass.Invalid,
                Mnemonic = Mnemonic.Invalid,
                Operands = Array.Empty<MachineOperand>(),
            };
        }

        public override Cr16Instruction NotYetImplemented(string message)
        {
            var testGenSvc = arch.Services.GetService<ITestGenerationService>();
            testGenSvc?.ReportMissingDecoder("Cr16Dasm", this.addr, this.rdr, message);
            return CreateInvalidInstruction();
        }

        #region Mutators

        private static readonly Bitfield bf4_3 = new Bitfield(4, 3);
        private static readonly Bitfield[] bf_abs24 = Bf((0, 4), (8, 4), (16, 16));
        private static readonly Bitfield[] bf_disp20 = Bf((8, 4), (16, 16));
        private static readonly Bitfield[] bf8_4_0_4 = Bf((8, 4), (0, 4));
        private static readonly Bitfield[] bf0_1_16_8_1_15 = Bf((0, 1), (16, 8), (1, 15));

        private static Mutator<Cr16cDisassembler> Imm(int bitpos, int bitlen, int sign, PrimitiveType dt)
        {
            var immField = new Bitfield(bitpos, bitlen);
            return (u, d) =>
            {
                var imm = (ushort) immField.Read(u);
                if (imm == 9)
                {
                    imm = 0xFFFF;
                }
                else if (imm == 11)
                {
                    if (!d.rdr.TryReadLeUInt16(out imm))
                        return false;
                }
                Constant c = Constant.Create(dt, sign * (short) imm);
                d.ops.Add(ImmediateOperand.Create(c));
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> imm4_l = Imm(4, 4, 1, PrimitiveType.Word32);
        private static readonly Mutator<Cr16cDisassembler> imm4_b = Imm(4, 4, 1, PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> neg_imm4_l = Imm(4, 4, -1, PrimitiveType.Int32);
        private static readonly Mutator<Cr16cDisassembler> imm5_l = Imm(4, 5, 1, PrimitiveType.Int32);
        private static readonly Mutator<Cr16cDisassembler> neg_imm5_l = Imm(4, 5, -1, PrimitiveType.Int32);

        private static bool imm32(uint uInstr, Cr16cDisassembler dasm)
        {
            if (!dasm.rdr.TryReadUInt32(out var imm32))
                return false;
            dasm.ops.Add(ImmediateOperand.Word32(imm32));
            return true;
        }


        private static Mutator<Cr16cDisassembler> imm4_16(PrimitiveType dt)
        {
            return (uint u, Cr16cDisassembler d) =>
            {
                var immCode = (u >> 4) & 0xF;
                Constant c;
                if (immCode == 11)
                {
                    if (!d.rdr.TryReadUInt16(out var imm16))
                        return false;
                    c = Constant.Create(dt, imm16);
                }
                else if (immCode == 9)
                {
                    c = Constant.Create(dt, -1L);
                }
                else
                {
                    c = Constant.Create(dt, immCode);
                }
                d.ops.Add(ImmediateOperand.Create(c));
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> imm4_16_b = imm4_16(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> imm4_16_w = imm4_16(PrimitiveType.Word16);
        private static readonly Mutator<Cr16cDisassembler> imm4_16_l = imm4_16(PrimitiveType.Word32);


        private static bool Imm3_pushpop(uint uInstr, Cr16cDisassembler dasm)
        {
            var imm = (int)bf4_3.Read(uInstr);
            dasm.ops.Add(ImmediateOperand.Int32(imm));
            return true;
        }

        private static Mutator<Cr16cDisassembler> Imm20(int bitpos)
        {
            var immField = new Bitfield(bitpos, 4);
            return (u, d) =>
            {
                var high = immField.Read(u);
                if (!d.rdr.TryReadLeUInt16(out var low))
                    return false;
                var imm = (high << 16) | low;
                d.ops.Add(new ImmediateOperand(Constant.Create(Cr16Architecture.Word24, imm)));
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> Imm20_0 = Imm20(0);


        private static bool bitpos_b(uint uInstr, Cr16cDisassembler dasm)
        {
            var bitpos = (byte)(uInstr & 0x7);
            dasm.ops.Add(ImmediateOperand.Byte(bitpos));
            return true;
        }

        private static bool bitpos_w(uint uInstr, Cr16cDisassembler dasm)
        {
            var bitpos = (byte) (uInstr & 0xF);
            dasm.ops.Add(ImmediateOperand.Byte(bitpos));
            return true;
        }

        private static Mutator<Cr16cDisassembler> abs20(PrimitiveType dt)
        {
            return (u, d) =>
            {
                if (!d.rdr.TryReadLeUInt16(out var low))
                    return false;
                uint uAddr = ((u & 0xF) << 16) | low;
                d.ops.Add(MemoryOperand.Absolute(dt, uAddr));
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> abs20_b = abs20(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> abs20_w = abs20(PrimitiveType.Word16);
        private static readonly Mutator<Cr16cDisassembler> abs20_d = abs20(PrimitiveType.Word32);

        private static Mutator<Cr16cDisassembler> abs20_rel(PrimitiveType dt)
        {
            return (uint uInstr, Cr16cDisassembler dasm) =>
            {
                if (!dasm.rdr.TryReadLeUInt16(out var low))
                    return false;
                uint uAddr = ((uInstr & 0xF) << 16) | low;
                var reg = Registers.GpRegisters[(uInstr >> 4) & 0xF];
                var mem = MemoryOperand.Relative(dt, reg, (int)uAddr);
                dasm.ops.Add(mem);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> abs20_rel_b = abs20_rel(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> abs20_rel_w = abs20_rel(PrimitiveType.Word16);
        private static readonly Mutator<Cr16cDisassembler> abs20_rel_d = abs20_rel(PrimitiveType.Word32);


        private static Mutator<Cr16cDisassembler> abs24(PrimitiveType dt)
        {
            return (u, d) =>
            {
                var uAddr = Bitfield.ReadFields(bf_abs24, u);
                d.ops.Add(MemoryOperand.Absolute(dt, uAddr));
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> abs24_b = abs24(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> abs24_w = abs24(PrimitiveType.Word16);
        private static readonly Mutator<Cr16cDisassembler> abs24_d = abs24(PrimitiveType.Word32);

        private static Mutator<Cr16cDisassembler> rp_disp0(PrimitiveType dt)
        {
            return (u, d) =>
            {
                var reg = (Storage) Registers.RegisterPairs[u & 0xF];
                var mem = MemoryOperand.Relative(dt, reg, 0);
                d.ops.Add(mem);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> rp_disp0_b = rp_disp0(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> rp_disp0_w = rp_disp0(PrimitiveType.Word16);

        private static Mutator<Cr16cDisassembler> rp_disp16(PrimitiveType dt)
        {
            return (u, d) =>
            {
                if (!d.rdr.TryReadLeUInt16(out ushort disp16))
                    return false;
                var reg = (Storage) Registers.RegisterPairs[u & 0xF];
                var mem = MemoryOperand.Relative(dt, reg, disp16);
                d.ops.Add(mem);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> rp_disp16_w = rp_disp16(PrimitiveType.Word16);

        private static Mutator<Cr16cDisassembler> rp_disp20(PrimitiveType dt)
        {
            return (u, d) =>
            {
                var disp20 = (int) Bitfield.ReadFields(bf_disp20, u);
                var rp = (Storage) Registers.RegisterPairs[(u >> 4) & 0xF];
                var mem = MemoryOperand.Relative(dt, rp, disp20);
                d.ops.Add(mem);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> rp_disp20_b = rp_disp20(PrimitiveType.Byte);
        private static readonly Mutator<Cr16cDisassembler> rp_disp20_w = rp_disp20(PrimitiveType.Word16);
        private static readonly Mutator<Cr16cDisassembler> rp_disp20_d = rp_disp20(PrimitiveType.Word32);

        /// <summary>
        /// 4-bit PC-relative positive displacement, translated by 1 and scaled by 2.
        /// </summary>
        /// <returns></returns>
        private static bool disp2xp1_4(uint uInstr, Cr16cDisassembler dasm)
        {
            var disp = 1 + (uInstr >> 4) & 0xF;
            var addrDst = dasm.addr + (disp << 1);
            dasm.ops.Add(AddressOperand.Create(addrDst));
            return true;
        }

        /// <summary>
        /// 8-bit PC-relative displacement, shifted left by 1 position
        /// </summary>
        private static bool disp8(uint uInstr, Cr16cDisassembler dasm)
        {
            var disp = (long)Bitfield.ReadSignedFields(bf8_4_0_4, uInstr);
            var addrDst = dasm.addr + (disp << 1);
            dasm.ops.Add(AddressOperand.Create(addrDst));
            return true;
        }

        /// <summary>
        /// 16-bit PC-relative displacement, shifted left by 1 position
        /// </summary>
        private static bool disp16(uint uInstr, Cr16cDisassembler dasm)
        {
            if (!dasm.rdr.TryReadInt16(out short disp))
                return false;
            var addrDst = dasm.addr + (disp << 1);
            dasm.ops.Add(AddressOperand.Create(addrDst));
            return true;
        }

        private static bool disp24(uint uInstr, Cr16cDisassembler dasm)
        {
            if (!dasm.rdr.TryReadUInt16(out ushort low))
                return false;
            uint codedDisp = (uInstr << 16) | low;
            var disp24 = Bitfield.ReadSignedFields(bf0_1_16_8_1_15, codedDisp);
            var addrDst = dasm.addr + (disp24 << 1);
            dasm.ops.Add(AddressOperand.Create(addrDst));
            return true;
        }

        /// <summary>
        /// 24-bit displacement from extension words already read.
        /// </summary>
        private static bool edisp24(uint uInstr, Cr16cDisassembler dasm)
        {
            var disp24 = Bitfield.ReadSignedFields(bf0_1_16_8_1_15, uInstr);
            var addrDst = dasm.addr + (disp24 << 1);
            dasm.ops.Add(AddressOperand.Create(addrDst));
            return true;
        }

        private static Mutator<Cr16cDisassembler> Reg(int bitpos)
        {
            var regfield = new Bitfield(bitpos, 4);
            return (u, d) =>
            {
                var ireg = regfield.Read(u);
                d.ops.Add(Registers.GpRegisters[ireg]);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> R0 = Reg(0);
        private static readonly Mutator<Cr16cDisassembler> R4 = Reg(4);

        private static Mutator<Cr16cDisassembler> Register(RegisterStorage reg)
        {
            return (u, d) =>
            {
                d.ops.Add(reg);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> RA = Register(Registers.GpRegisters[14]);

        private static Mutator<Cr16cDisassembler> RegPair(int bitpos)
        {
            var regfield = new Bitfield(bitpos, 4);
            return (u, d) =>
            {
                var ireg = regfield.Read(u);
                d.ops.Add(Registers.RegisterPairs[ireg]);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> rp0 = RegPair(0);
        private static readonly Mutator<Cr16cDisassembler> rp4 = RegPair(4);

        private static readonly (RegisterStorage, Storage)[] rrp = new (RegisterStorage, Storage)[16]
        {
            (R(12), Seq(1,0)),
            (R(12), Seq(3,2)),
            (R(12), Seq(5,4)),
            (R(12), Seq(7,6)),
            (R(12), Seq(9,8)),
            (R(12), Seq(11,10)),
            (R(12), Seq(4,3)),
            (R(12), Seq(6,5)),
            (R(13), Seq(1,0)),
            (R(13), Seq(3,2)),
            (R(13), Seq(5,4)),
            (R(13), Seq(7,6)),
            (R(13), Seq(9,8)),
            (R(13), Seq(11,10)),
            (R(13), Seq(4,3)),
            (R(13), Seq(6,5))
        };

        private static RegisterStorage R(int iReg) => Registers.GpRegisters[iReg];
        private static SequenceStorage Seq(int iHi, int iLo) =>
            new SequenceStorage(Registers.GpRegisters[iHi], Registers.GpRegisters[iLo]);

        private static bool pr4(uint uInstr, Cr16cDisassembler dasm)
        {
            var pr = Registers.ProcessorRegisters[(uInstr >> 4) & 0xF];
            dasm.ops.Add(pr);
            return true;
        }

        private static Mutator<Cr16cDisassembler> Cache(CacheFlag cacheFlag)
        {
            var cop = new CacheFlagOperand(cacheFlag);
            return (u, d) =>
            {
                d.ops.Add(cop);
                return true;
            };
        }


        private static Mutator<Cr16cDisassembler> Mem(PrimitiveType dt, int displacementScale)
        {
            return (u, d) =>
            {
                var op = (u >> 8) & 0xF;

                //1001 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  loadw(prp) disp0 4 src(prp) 4 dest reg 4E
                //1001 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  loadw(rp) disp16 4 src(rp)  4 dest reg 4F 16 src disp
                //1001 xxxx xxxx xxxx Fmt18 1 ZZ loadw(rp) disp4  4 src(rp)  4 dest reg 4  src disp*2


                //1101 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  storw(prp) disp0  4 dest(prp) 4 src reg 4E
                //1101 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  storw(rp)  disp16 4 dest(rp)  4 src reg 4F 16 dest disp
                //1101 xxxx xxxx xxxx  Fmt18 1 ZZ storw(rp) disp4 4 dest(rp) 4 src reg 4 dest disp*2
                // 18 param444    1 4 opcode4 p3_4 p2_4 p1_4
                // 19 param444_16 2 4 opcode4 p3_4 p2_4 p1_4..p4_1

                MemoryOperand mem;
                if (op == 0xE)
                {
                    // PRP: //$TODO this depends on a flag CFG.SR

                    if (true)// CFG.SR)
                    {
                        var (i, b) = rrp[u & 0xF];
                        mem = MemoryOperand.Indexed(dt, i, b, 0);
                    }
                    //else
                    //{
                    //    mem = MemoryOperand.Relative(dt, R((int)u & 0xF), 0);
                    //    d.ops.Add(mem);
                    //}
                    return true;
                }
                else if (op == 0xF)
                {
                    if (!d.rdr.TryReadLeUInt16(out ushort disp16))
                        return false;
                    var rp = (Storage) Registers.RegisterPairs[u & 0xF];
                    mem = MemoryOperand.Relative(dt, rp, disp16 * displacementScale);
                }
                else
                {
                    var rp = (Storage) Registers.RegisterPairs[u & 0xF];
                    mem = MemoryOperand.Relative(dt, rp, (int) op * displacementScale);
                }
                d.ops.Add(mem);
                return true;
            };
        }
        private static readonly Mutator<Cr16cDisassembler> Memb = Mem(PrimitiveType.Byte, 1);
        private static readonly Mutator<Cr16cDisassembler> Memw = Mem(PrimitiveType.Word16, 2);
        private static readonly Mutator<Cr16cDisassembler> Memd = Mem(PrimitiveType.Word32, 2);

        #endregion

        #region Decoders

        private class Next32Decoder : Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction>
        {
            public readonly Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> decoder;

            public Next32Decoder(Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> decoder)
            {
                this.decoder = decoder;
            }

            public override Cr16Instruction Decode(uint wInstr, Cr16cDisassembler dasm)
            {
                if (!dasm.rdr.TryReadLeUInt32(out uint uInstr))
                    return dasm.CreateInvalidInstruction();
                return decoder.Decode(uInstr, dasm);
            }
        }

        private static Decoder Next32(Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> decoder)
        {
            return new Next32Decoder(decoder);
        }

        private static Decoder Nyi(string message)
        {
            return new NyiDecoder<Cr16cDisassembler, Mnemonic, Cr16Instruction>(message);
        }

        #endregion

        private static Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> Instr(
            Mnemonic mnemonic,
            params Mutator<Cr16cDisassembler>[] mutators)
        {
            return Instr(mnemonic, InstrClass.Linear, mutators);
        }

        private static Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> Instr(
            Mnemonic mnemonic,
            InstrClass iclass,
            params Mutator<Cr16cDisassembler>[] mutators)
        {
            return new InstrDecoder<Cr16cDisassembler, Mnemonic, Cr16Instruction>(
                iclass,
                mnemonic,
                mutators);
        }

        private static Decoder<Cr16cDisassembler, Mnemonic, Cr16Instruction> param0(
            Mnemonic mnemonic,
            InstrClass iclass = InstrClass.Linear)
        {
            return new InstrDecoder<Cr16cDisassembler, Mnemonic, Cr16Instruction>(iclass, mnemonic);
        }

        static Cr16cDisassembler()
        {
            var invalid = Instr(Mnemonic.res, InstrClass.Invalid);

            var decode000 = Mask(0, 4, "  000",
                param0(Mnemonic.res, InstrClass.Invalid),
                param0(Mnemonic.res, InstrClass.Invalid),
                param0(Mnemonic.res, InstrClass.Invalid),
                param0(Mnemonic.retx, InstrClass.Transfer | InstrClass.Return),

                param0(Mnemonic.di, InstrClass.Invalid),
                param0(Mnemonic.ei, InstrClass.Invalid),
                param0(Mnemonic.wait, InstrClass.Invalid),
                param0(Mnemonic.eiwait, InstrClass.Invalid),

                param0(Mnemonic.res, InstrClass.Invalid),
                param0(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.cinv, Cache(CacheFlag.I)),
                Instr(Mnemonic.cinv, Cache(CacheFlag.I | CacheFlag.U)),

                Instr(Mnemonic.cinv, Cache(CacheFlag.D)),
                Instr(Mnemonic.cinv, Cache(CacheFlag.D | CacheFlag.U)),
                Instr(Mnemonic.cinv, Cache(CacheFlag.D | CacheFlag.I)),
                Instr(Mnemonic.cinv, Cache(CacheFlag.D | CacheFlag.I | CacheFlag.U)));

            var decode0010 = Mask(12, 4, "  0010",
                Mask(4, 4, "  b?? disp24",
                    Instr(Mnemonic.beq, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bne, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bcs, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bcc, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bhi, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bls, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bgt, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.ble, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bfs, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bfc, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.blo, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bhs, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.blt, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.bge, InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.br , InstrClass.ConditionalTransfer, edisp24),
                    Instr(Mnemonic.br,  InstrClass.ConditionalTransfer, edisp24)),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Nyi("Fmr3a 3 bal (rp) disp24 24 dest disp*2 4 link rp  4 ope 2"),
                Instr(Mnemonic.res, InstrClass.Invalid),

                Nyi("Fmt2 3 ZZ ope 4  cbitb (reg) disp20 4 dest (reg) 3 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 5  cbitb (rp)  disp20 4 dest (rp)  3 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 6  cbitb (rrp) disp20 4 dest (rrp) 3 pos imm 20 dest disp 4"),
                Instr(Mnemonic.cbitb, bitpos_b, abs24_b),

                Nyi("Fmt2 3 ZZ ope 8  sbitb (reg) disp20 4 dest (reg) 3 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 9  sbitb (rp) disp20 4 dest (rp) 3 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 10  sbitb (rrp) disp20 4 dest (rrp) 3 pos imm 20 dest disp 4"),
                Instr(Mnemonic.sbitb, bitpos_b, abs24_b),

                Nyi("Fmt2 3 ZZ ope 12  tbitb (reg) disp20 4 dest (reg) 3 pos imm 20 dest disp 4"),
                Instr(Mnemonic.tbitb, bitpos_b, rp_disp20_b),
                Nyi("Fmt2 3 ZZ ope 14  tbitb (rrp) disp20 4 dest (rrp) 3 pos imm 20 dest disp 4"),
                Nyi("Fmt3 3 ZZ ope 15  tbitb abs24 24 dest abs 3 pos imm 4"));

            var decode0011 = Mask(12, 4, "  0011",
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Nyi("Fmt2 3 ZZ ope 4  cbitw(reg)  disp20 4 dest(reg) 4 pos imm 20 dest disp 4"),
                Instr(Mnemonic.cbitw, bitpos_w, rp_disp20_w),
                Nyi("Fmt2 3 ZZ ope 6  cbitw(rrp)  disp20 4 dest(rrp) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt3 3 ZZ ope 7  cbitw abs24 24 dest abs 4 pos imm 4"),
                Nyi("Fmt2 3 ZZ ope 8  sbitw(reg)  disp20 4 dest(reg) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 9  sbitw(rp)   disp20 4 dest(rp) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 10  sbitw(rrp) disp20 4 dest(rrp) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt3 3 ZZ ope 11  sbitw abs24 24 dest abs 4 pos imm 4"),
                Nyi("Fmt2 3 ZZ ope 12  tbitw(reg) disp20 4 dest(reg) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 13  tbitw(rp)  disp20 4 dest(rp) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 14  tbitw(rrp) disp20 4 dest(rrp) 4 pos imm 20 dest disp 4"),
                Nyi("Fmt3 3 ZZ ope 15  tbitw abs24 24 dest abs 4 pos imm 4"));

            var decode0012 = Mask(12, 4, "  0012",
                Nyi("Fmt2 3 ZZ ope 0  storb imm(reg) disp20 4 dest(reg) 4 src imm 20 dest disp 4"),
                Instr(Mnemonic.storb, R4, rp_disp20_b),
                Nyi("Fmt2 3 ZZ ope 2  storb imm(rrp) disp20 4 dest(rrp) 4 src imm 20 dest disp 4"),
                Nyi("Fmt3 3 ZZ ope 3  storb imm abs24 24 dest abs 4 src imm 4"),
                Nyi("Fmt2 3 ZZ ope 4  loadb (reg) disp20 4 src (reg) 4 dest reg 20 src disp 4"),
                Instr(Mnemonic.loadb, rp_disp20_b, R4),
                Nyi("Fmt2 3 ZZ ope 6  loadb (rrp) disp20 4 src (rrp) 4 dest reg 20 src disp 4"),
                Instr(Mnemonic.loadb, abs24_b, R4),
                Nyi("Fmt2 3 ZZ ope 8  loadd (reg) disp20 4 src (reg) 4 dest rp 20 src disp 4"),
                Instr(Mnemonic.loadd, rp_disp20_d, R4),
                Nyi("Fmt2 3 ZZ ope 10  loadd (rrp) disp20 4 src (rrp) 4 dest rp 20 src disp 4"),
                Instr(Mnemonic.loadd, abs24_d, R4),
                Nyi("Fmt2 3 ZZ ope 12  loadw (reg) disp20 4 src (reg) 4 dest reg 20 src disp 4"),
                Instr(Mnemonic.loadw, rp_disp20_w, R4),
                Nyi("Fmt2 3 ZZ ope 14  loadw (rrp) disp20 4 src (rrp) 4 dest reg 20 src disp 4"),
                Instr(Mnemonic.loadw, abs24_w, R4));

            var decode0013 = Mask(12, 4, "  0013",
                Nyi("Fmt2 3 ZZ ope 0  storw imm (reg) disp20 4 dest (reg) 4 src imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 1  storw imm (rp)  disp20 4 dest (rp)  4 src imm 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 2  storw imm (rrp) disp20 4 dest (rrp) 4 src imm 20 dest disp 4"),
                Instr(Mnemonic.storw, R4, abs24_w),
                Nyi("Fmt2 3 ZZ ope 4  storb (reg) disp20 4 dest (reg) 4 src reg 20 dest disp 4"),
                Instr(Mnemonic.storb, R4, rp_disp20_b),
                Nyi("Fmt2 2 ZZ ope 6  storb (rrp) disp20 4 dest (rrp) 4 src reg 20 dest disp 4"),
                Instr(Mnemonic.storb, R4, abs24_b),

                Nyi("Fmt2 3 ZZ ope 8  stord (reg) disp20 4 dest (reg) 4 src rp 20 dest disp 4"),
                Instr(Mnemonic.stord, R4, rp_disp20_d),
                Nyi("Fmt2 3 ZZ ope 10  stord (rrp) disp20 4 dest (rrp) 4 src rp 20 dest disp 4"),
                Instr(Mnemonic.stord, rp4, abs24_d),

                Nyi("Fmt2 3 ZZ ope 12  storw (reg) disp20 4 dest (reg) 4 src reg 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 13  storw (rp) disp20 4 dest (rp) 4 src reg 20 dest disp 4"),
                Nyi("Fmt2 3 ZZ ope 14  storw (rrp) disp20 4 dest (rrp) 4 src reg 20 dest disp 4"),
                Instr(Mnemonic.storb, R4, abs24_b));

            var decode0014 = Mask(12, 4, "  0014",
                Instr(Mnemonic.lpr, InstrClass.Linear |InstrClass.Privileged, R0, pr4),
                Instr(Mnemonic.lprd, InstrClass.Linear|InstrClass.Privileged, rp0, pr4),
                Instr(Mnemonic.spr, InstrClass.Linear |InstrClass.Privileged, pr4, R0),
                Instr(Mnemonic.sprd, InstrClass.Linear|InstrClass.Privileged, pr4, rp0),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),
                Instr(Mnemonic.res, InstrClass.Invalid),

                Nyi("Instr(mnemonic.jal, InstrClass.Transfer|InstrClass.Call,  Fmt1 2 ZZ ope 8  jal(rp, rp) 4 link rp 4 dest rp * 2 4 res 0 4"),
                Nyi("Fmt1 2 ZZ ope 9  ord rp, rp 4 dest rp 4 src rp 4"),
                Nyi("Fmt1 2 ZZ ope 10  xord rp, rp 4 dest rp 4 src rp 4"),
                Nyi("Fmt1 2 ZZ ope 11  andd rp, rp 4 dest rp 4 src rp 4"),

                Instr(Mnemonic.subd, rp0, rp4),
                Nyi("Fmt1 2 ZZ ope 13  macqw 4 src2 reg 4 src1 reg 4 dest rp 4"),
                Nyi("Fmt1 2 ZZ ope 14  macuw 4 src2 reg 4 src1 reg 4 dest rp 4"),
                Nyi("Fmt1 2 ZZ ope 15  macsw 4 src2 reg 4 src1 reg 4 dest rp 4"));

            var decode0018 = Sparse(12, 4, "  0018", invalid,
                (4, Nyi("loadb(reg) - disp20 4 src(reg) 4 dest reg 20 src disp 4")),
                (5, Nyi("loadb(rp) - disp20 4 src(rp) 4 dest reg 20 src disp 4")),
                (8, Nyi("loadd(reg) - disp20 4 src(reg) 4 dest rp 20 src disp 4")),
                (9, Nyi("loadd(rp) - disp20 4 src(rp) 4 dest rp 20 src disp 4")),
                (12, Nyi(" loadw(reg) - disp20 4 src(reg) 4 dest reg 20 src disp 4")),
                (13, Nyi(" loadw(rp) - disp20 4 src(rp) 4 dest reg 20 src disp 4")));

            var decode0019 = Sparse(12, 4, "  0019", invalid,
                (4, Nyi("storb(reg) - disp20 4 dest(reg) 4 src reg 20 dest disp 4")),
                (5, Nyi("storb(rp) - disp20 4 dest(rp) 4 src reg 20 dest disp 4")),
                (8, Nyi("stord(reg) - disp20 4 dest(reg) 4 src rp 20 dest disp 4")),
                (9, Nyi("stord(rp) - disp20 4 dest(rp) 4 src rp 20 dest disp 4")),
                (12, Nyi("storw(reg) - disp20 4 dest(reg) 4 src reg 20 dest disp 4")),
                (13, Nyi("storw(rp) - disp20 4 dest(rp) 4 src reg 20 dest disp 4")));

            var decode001 = Mask(0, 4, "  001",
                Next32(decode0010),
                Next32(decode0011),
                Next32(decode0012),
                Next32(decode0013),

                Next32(decode0014),
                invalid,
                invalid,
                invalid,

                decode0018,
                decode0019,
                invalid,
                invalid,

                invalid,
                invalid,
                invalid,
                invalid);

            var decode00 = Mask(4, 4, "  00",
                decode000,
                decode001,
                Instr(Mnemonic.addd, imm32, rp0),
                Instr(Mnemonic.subd, imm32, rp0),

                Instr(Mnemonic.andd, imm32,rp0),
                Instr(Mnemonic.ord, imm32,rp0),
                Instr(Mnemonic.xord, imm32,rp0),
                Instr(Mnemonic.movd, imm32, rp0),

                invalid, // - undefined trap for coprocessor inst 4 ci imm 32 cinst imm"),
                Instr(Mnemonic.cmpd, imm32, rp0),
                Mask(3, 1, " 00A",
                    Nyi("Fmt6 1 ZZ  loadm (reg) 3 count imm"),
                    Nyi("Fmt6 1 ZZ  loadmp (rp) 3 count imm")),
                Mask(3, 1, " 00B",
                    Nyi("Fmt6 1 ZZ  storm (reg) 3 count imm"),
                    Nyi("Fmt6 1 ZZ  stormp (rp) 3 count imm")),

                Nyi("Fmt11 1 ZZ  excp 4 vect imm"),
                Instr(Mnemonic.jal, InstrClass.Transfer|InstrClass.Call, RA, rp0),
                invalid,
                invalid);
            var decode0 = Mask(8, 4,
                decode00,
                Mask(7, 1, "  01",
                    Instr(Mnemonic.push, Imm3_pushpop,R0),
                    Instr(Mnemonic.push, Imm3_pushpop,R0,RA)),
                Mask(7, 1, "  02",
                    Instr(Mnemonic.pop, Imm3_pushpop, R0),
                    Instr(Mnemonic.pop, Imm3_pushpop, R0, RA)),
                Mask(7, 1, "  03",
                    Instr(Mnemonic.popret, Imm3_pushpop, R0),
                    Instr(Mnemonic.popret, Imm3_pushpop, R0, RA)),

                Instr(Mnemonic.addd, Imm20_0, rp4),
                Instr(Mnemonic.movd, Imm20_0, rp4),
                Instr(Mnemonic.tbit, bitpos_b, R4),
                Instr(Mnemonic.tbit, R0, R4),

                Nyi("Fmt15 1 ZZ  Scond (reg) 4 dest reg 4 cond imm"),
                Mask(7, 1, "  09",
                    invalid, //        0000 1001 0xxx xxxx  ZZ res - undefined trap 2
                    Nyi("Fmt9 1 ZZ  lshb cnt(right -), reg 4 dest reg 3 count imm")),
                Mask(4, 4, "  0A",
                    Instr(Mnemonic.jeq, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jne, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jcs, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jcc, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jhi, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jls, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jgt, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jle, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jfs, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jfc, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jlo, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jhs, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jlt, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jge, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jr, InstrClass.ConditionalTransfer, rp0),
                    Instr(Mnemonic.jr, InstrClass.ConditionalTransfer, rp0)),
                Nyi("Fmt15 1 ZZ  mulsb reg,reg 4 dest reg 4 src reg"),

                Instr(Mnemonic.beq0b, R0, disp2xp1_4),
                Instr(Mnemonic.bne0b, R0, disp2xp1_4),
                Instr(Mnemonic.beq0w, R0, disp2xp1_4),
                Instr(Mnemonic.bne0w, R0, disp2xp1_4));

            var decode2 = Mask(8, 4,
                Instr(Mnemonic.andb, imm4_16_b, R4),
                Instr(Mnemonic.andb, R0, R4),
                Instr(Mnemonic.andw, imm4_16_w, R4),
                Instr(Mnemonic.andw, R0, R4),

                Instr(Mnemonic.orb, imm4_16_b, R4),
                Instr(Mnemonic.orb, R0, R4),
                Instr(Mnemonic.orw, imm4_16_w, R4),
                Instr(Mnemonic.orw, R0, R4),

                Instr(Mnemonic.xorb, imm4_16_w, R4),
                Instr(Mnemonic.xorb, R0, R4),
                Instr(Mnemonic.xorw, imm4_16_w, R4),
                Instr(Mnemonic.xorw, R0, R4),

                Instr(Mnemonic.addub, imm4_b, R4),
                Instr(Mnemonic.addub, R0, R4),
                Instr(Mnemonic.adduw, imm4_16_w, R4),
                Instr(Mnemonic.adduw, R0, R4));

            var decode3 = Mask(8, 4, "  03",
                Instr(Mnemonic.addb, imm4_16_w, R4),
                Instr(Mnemonic.addb, R0, R4),
                Instr(Mnemonic.addw, imm4_16_w, R4),
                Instr(Mnemonic.addw, R0, R4),

                Instr(Mnemonic.addcb, imm4_16_w, R4),
                Instr(Mnemonic.addcb, R0, R4),
                Instr(Mnemonic.addcw, imm4_16_w, R4),
                Instr(Mnemonic.addcw, R0, R4),

                Instr(Mnemonic.subb, imm4_16_w, R4),
                Instr(Mnemonic.subb, R0, R4),
                Instr(Mnemonic.subw, imm4_16_w, R4),
                Instr(Mnemonic.subw, R0, R4),

                Instr(Mnemonic.subcb, imm4_16_w, R4),
                Instr(Mnemonic.subcb, R0, R4),
                Instr(Mnemonic.subcw, imm4_16_w, R4),
                Instr(Mnemonic.subcw, R0, R4));

            var decode4 = Mask(8, 4, "  4",
                Mask(7, 1, "  40",
                    Nyi("0100 0000 0xxx xxxx  Fmt9 1 ZZ  ashub cnt(left +), reg 4 dest reg 3 count imm"),
                    Nyi("0100 0000 1xxx xxxx  Fmt9 1 ZZ  ashub cnt(right -), reg 4 dest reg 3 count imm")),
                Nyi("0100 0001 xxxx xxxx  Fmt15 1 ZZ  ashub reg, reg 4 dest reg 4 count reg"),
                Nyi("0100 0010 xxxx xxxx  Fmt15 1 ZZ  ashuw cnt(left +), reg 4 dest reg 4 count imm"),
                Nyi("0100 0011 xxxx xxxx  Fmt15 1 ZZ  ashuw cnt(right -), reg 4 dest reg 4 count imm"),

                Nyi("0100 0100 xxxx xxxx  Fmt15 1 ZZ  lshb reg, reg 4 dest reg 4 count reg"),
                Nyi("0100 0101 xxxx xxxx  Fmt15 1 ZZ  ashuw reg, reg 4 dest reg 4 count reg"),
                Nyi("0100 0110 xxxx xxxx  Fmt15 1 ZZ  lshw reg, reg 4 dest reg 4 count reg"),
                Nyi("0100 0111 xxxx xxxx  Fmt15 1 ZZ  lshd reg, rp 4 dest rp 4 count reg"),

                Instr(Mnemonic.ashud, R4, rp0),
                Instr(Mnemonic.lshw, neg_imm4_l, R0),
                Nyi("0100 101x xxxx xxxx  Fmt20 1 ZZ  lshd cnt(right -), rp 4 dest rp 5 count imm"),
                Nyi("0100 101x xxxx xxxx  Fmt20 1 ZZ  lshd cnt(right -), rp 4 dest rp 5 count imm"),

                Instr(Mnemonic.ashud, imm5_l, rp0),    // right +
                Instr(Mnemonic.ashud, imm5_l, rp0),    // right +
                Instr(Mnemonic.ashud, neg_imm5_l, rp0),    // right -
                Instr(Mnemonic.ashud, neg_imm5_l, rp0));    // right -
            var decode5 = Mask(8, 4, "  5",
                Instr(Mnemonic.cmpb, imm4_16_b, R0),
                Instr(Mnemonic.cmpb, R0, R4),
                Instr(Mnemonic.cmpw, imm4_16_w, R0),
                Instr(Mnemonic.cmpw, R0, R4),

                Nyi("ZZ movd imm4 / imm16, rp 4 dest rp 4 src imm 15 / 16 1 / 2"),
                Instr(Mnemonic.movd, rp0, rp4),
                Instr(Mnemonic.cmpd, imm4_16_l, rp0),
                Instr(Mnemonic.cmpd, rp0,rp4),

                Instr(Mnemonic.movb, imm4_16_b, R0),
                Instr(Mnemonic.movb, R4, R0),
                Instr(Mnemonic.movw, imm4_16_w, R0),
                Instr(Mnemonic.movw, R4, R0),

                Instr(Mnemonic.movxb, R4, rp0),
                Instr(Mnemonic.movzb, R4, rp0),
                Instr(Mnemonic.movxw, R4, rp0),
                Instr(Mnemonic.movzw, R4, rp0));
            var decode6 = Mask(8, 4, "  6",
                Instr(Mnemonic.addd, imm4_16_l, rp0),
                Instr(Mnemonic.addd, rp4, rp0),
                Nyi("Fmt15 1 ZZ  mulsw reg, rp 4 dest rp 4 src reg"),
                Nyi("Fmt15 1 ZZ  muluw reg, rp 4 dest rp 4 src reg"),

                Instr(Mnemonic.mulb, imm4_16_b, R0),
                Instr(Mnemonic.mulb, R4, R0),
                Instr(Mnemonic.mulw, imm4_16_w, R0),
                Instr(Mnemonic.mulw, R4, R0),

                Instr(Mnemonic.cbitb, R4, abs20_b),
                Instr(Mnemonic.cbitw, bitpos_w, rp_disp16_w),
                Mask(6, 2, "  6A",
                    Nyi("Fmt9 1 ZZ  cbitb(rp) disp0 4 dest(rp) 3 pos imm"),
                    Nyi("Fmt9 1 ZZ  cbitb(rp) disp0 4 dest(rp) 3 pos imm"),
                    Nyi("Fmt17 2 ZZ  cbitb(prp) disp14 4 dest(prp) 3 pos imm 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  cbitw(prp) disp14 4 dest(prp) 4 pos imm 14 dest disp")),
                Mask(7, 1, "  6B",
                    Nyi("Fmt10 2 ZZ  cbitb(rp) disp16 4 dest(rp) 3 pos imm 16 dest disp"),
                    Instr(Mnemonic.cbitb, bitpos_b, abs20_b)),

                Instr(Mnemonic.cbitw, bitpos_w, abs20_rel_w),
                Instr(Mnemonic.cbitw, bitpos_w, abs20_rel_w),
                Instr(Mnemonic.cbitw, bitpos_w, rp_disp0_w),
                Instr(Mnemonic.cbitw, bitpos_w, abs20_w));

            var decode7 = Mask(8, 4, "  7",
                Instr(Mnemonic.sbitb, bitpos_b, abs20_rel_b),
                Nyi("Fmt16 2 ZZ  sbitw(rp) disp16 4 dest(rp) 4 pos imm 16 dest disp"),
                Mask(6, 2, "  72",
                    Instr(Mnemonic.sbitb, bitpos_b, rp_disp0_b),
                    Instr(Mnemonic.sbitb, bitpos_b, rp4),
                    Nyi("Fmt17 2 ZZ  sbitb(prp) disp14 4 dest(prp) 3 pos imm 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  sbitw(prp) disp14 4 dest(prp) 4 pos imm 14 dest disp")),
                Mask(7, 1, "  73",
                    Nyi("Fmt10 2 ZZ  sbitb(rp) disp16 4 dest(rp) 3 pos imm 16 dest disp"),
                    Instr(Mnemonic.sbitb, bitpos_b, abs20_b)),

                Instr(Mnemonic.sbitw, bitpos_w, abs20_rel_w),
                Instr(Mnemonic.sbitw, bitpos_w, abs20_rel_w),
                Instr(Mnemonic.sbitw, bitpos_w, rp_disp0_w),
                Instr(Mnemonic.sbitw, bitpos_w, abs20_w),

                Nyi("Fmt8 2 ZZ  tbitb abs20 rel 20 dest abs 3 pos imm 1 dest rs"),
                Instr(Mnemonic.tbitw, bitpos_w, rp_disp16_w),
                Mask(6, 2, "  7A",
                    Nyi("Fmt9 1 ZZ  tbitb(rp) disp0 4 dest(rp) 3 pos imm"),
                    Nyi("Fmt9 1 ZZ  tbitb(rp) disp0 4 dest(rp) 3 pos imm"),
                    Nyi("Fmt17 2 ZZ  tbitb(prp) disp14 4 dest(prp) 3 pos imm 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  tbitw(prp) disp14 4 dest(prp) 4 pos imm 14 dest disp")),
                Mask(7, 1, "  7B",
                    Nyi("Fmt10 2 ZZ  tbitb(rp) disp16 4 dest(rp) 3 pos imm 16 dest disp"),
                    Nyi("Fmt7 2 ZZ  tbitb abs20 20 dest abs 3 pos imm")),

                Instr(Mnemonic.tbitw, bitpos_w, abs20_rel_w),
                Instr(Mnemonic.tbitw, bitpos_w, abs20_rel_w),
                Nyi("Fmt15 1 ZZ  tbitw(rp) disp0 4 dest(rp) 4 pos imm"),
                Instr(Mnemonic.tbitw, bitpos_w, abs20_w));

            var decode8 = Mask(8, 4, "  8",

                Nyi("Fmt15 1 ZZ  res - undefined trap"),
                Nyi("Fmt12 2 ZZ  storb imm abs20 20 dest abs 4 src imm"),
                Nyi("Fmt15 1 ZZ  storb imm(rp) disp0 4 dest(rp) 4 src imm"),
                Nyi("Fmt16 2 ZZ  storb imm(rp) disp16 4 dest(rp) 4 src imm 16 dest disp"),

                Nyi("Fmt13 2 ZZ  storb imm abs20 rel 20 dest abs 4 src imm 1 dest rs"),
                Nyi("Fmt13 2 ZZ  storb imm abs20 rel 20 dest abs 4 src imm 1 dest rs"),
                Mask(6, 2, "  86",
                    Nyi("Fmt17 2 ZZ  storb imm(prp) disp14 4 dest(prp) 4 src imm 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  loadb(prp) disp14 4 src(prp) 4 dest reg 14 src disp"),
                    Nyi("Fmt17 2 ZZ  loadd(prp) disp14 4 src(prp) 4 dest rp 14 src disp"),
                    Nyi("Fmt17 2 ZZ  loadw(prp) disp14 4 src(prp) 4 dest reg 14 src disp")),
                Instr(Mnemonic.loadd, abs20_d, R4),

                Instr(Mnemonic.loadb, abs20_b, R4),
                Instr(Mnemonic.loadw, abs20_w, R4),
                Instr(Mnemonic.loadb, abs20_rel_b, R4),
                Instr(Mnemonic.loadb, abs20_rel_b, R4),

                Instr(Mnemonic.loadd, abs20_rel_d, R4),
                Instr(Mnemonic.loadd, abs20_rel_d, R4),
                Instr(Mnemonic.loadw, abs20_rel_w, R4),
                Instr(Mnemonic.loadw, abs20_rel_w, R4));

            var decodeC = Mask(8, 4, "  C",
                Instr(Mnemonic.bal, InstrClass.Transfer|InstrClass.Call, RA, disp24),
                Nyi("Fmt12 2 ZZ  storw imm abs20 20 dest abs 4 src imm"),
                Nyi("Fmt15 1 ZZ  storw imm(rp) disp0 4 dest(rp) 4 src imm"),
                Nyi("Fmt16 2 ZZ  storw imm(rp) disp16 4 dest(rp) 4 src imm 16 dest disp"),

                Nyi("Fmt13 2 ZZ  storw imm abs20 rel 20 dest abs 4 src imm 1 dest rs"),
                Nyi("Fmt13 2 ZZ  storw imm abs20 rel 20 dest abs 4 src imm 1 dest rs"),
                Mask(6, 2, "  C6",
                    Nyi("Fmt17 2 ZZ  storw imm(prp) disp14 4 dest(prp) 4 src imm 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  storb(prp) disp14 4 dest(prp) 4 src reg 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  stord(prp) disp14 4 dest(prp) 4 src rp 14 dest disp"),
                    Nyi("Fmt17 2 ZZ  storw(prp) disp14 4 dest(prp) 4 src reg 14 dest disp")),

                Nyi("Fmt12 2 ZZ  stord abs20 20 dest abs 4 src rp"),
                Instr(Mnemonic.storb, R4, abs20_b),
                Instr(Mnemonic.storw, R4, abs20_w),
                Nyi("Fmt13 2 ZZ  storb abs20 rel 20 dest abs 4 src reg 1 dest rs"),
                Nyi("Fmt13 2 ZZ  storb abs20 rel 20 dest abs 4 src reg 1 dest rs"),
                Nyi("Fmt13 2 ZZ  stord abs20 rel 20 dest abs 4 src rp 1 dest rs"),
                Nyi("Fmt13 2 ZZ  stord abs20 rel 20 dest abs 4 src rp 1 dest rs"),
                Nyi("Fmt13 2 ZZ  storw abs20 rel 20 dest abs 4 src reg 1 dest rs"),
                Nyi("Fmt13 2 ZZ  storw abs20 rel 20 dest abs 4 src reg 1 dest rs"));

            rootDecoder = Mask(12, 4, "CR16C",
                decode0,
                Select(u => (u & 0xF0F) == 0x800,
                    Mask(4, 4, " br disp16",
                        Instr(Mnemonic.beq, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bne, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bcs, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bcc, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bhi, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bls, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bgt, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.ble, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bfs, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bfc, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.blo, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bhs, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.blt, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.bge, InstrClass.ConditionalTransfer, disp16),
                        Instr(Mnemonic.br, InstrClass.Transfer, disp16),
                        Instr(Mnemonic.br, InstrClass.Transfer, disp16)),
                    Mask(4, 4, "  1xxx",
                        Instr(Mnemonic.beq, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bne, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bcs, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bcc, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bhi, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bls, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bgt, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.ble, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bfs, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bfc, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.blo, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bhs, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.blt, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.bge, InstrClass.ConditionalTransfer, disp8),
                        Instr(Mnemonic.br, InstrClass.Transfer, disp8),
                        Instr(Mnemonic.br, InstrClass.Transfer, disp8))),
                decode2,
                decode3,

                decode4,
                decode5,
                decode6,
                decode7,

                decode8,
                Instr(Mnemonic.loadw, Memw, R4),
                Instr(Mnemonic.loadd, Memd, rp4),
                Instr(Mnemonic.loadb, Memb, R4),

                decodeC,
                Instr(Mnemonic.storw, R4, Memw),
                Instr(Mnemonic.stord, rp4, Memd),
                If(u => u != 0xFFFF, Instr(Mnemonic.storb, R4, Memb)));
        }
        /*
        1001 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  loadw (prp) disp0 4 src (prp) 4 dest reg 4E 
        1001 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  loadw (rp) disp16 4 src (rp) 4 dest reg 4F 16 src disp 
        1001 xxxx xxxx xxxx  Fmt18 1 ZZ  loadw (rp) disp4 4 src (rp) 4 dest reg 4 src disp*2 

        1010 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  loadd (prp) disp0 4 src (prp) 4 dest rp 4E 
        1010 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  loadd (rp) disp16 4 src (rp) 4 dest rp 4F 16 src disp 
        1010 xxxx xxxx xxxx  Fmt18 1 ZZ  loadd (rp) disp4 4 src (rp) 4 dest rp 4 src disp*2 

        1011 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  loadb (prp) disp0 4 src (prp) 4 dest reg 4E 
        1011 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  loadb (rp) disp16 4 src (rp) 4 dest reg 4F 16 src disp 
        1011 xxxx xxxx xxxx  Fmt18 1 ZZ  loadb (rp) disp4 4 src (rp) 4 dest reg 4 src disp 

        1101 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  storw (prp) disp0 4 dest (prp) 4 src reg 4E 
        1101 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  storw (rp) disp16 4 dest (rp) 4 src reg 4F 16 dest disp 
        1101 xxxx xxxx xxxx  Fmt18 1 ZZ  storw (rp) disp4 4 dest (rp) 4 src reg 4 dest disp*2 

        1110 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  stord (prp) disp0 4 dest (prp) 4 src rp 4E 
        1110 1111 xxxx xxxx  Fmt19 2 ZZ ope 0  stord (rp) disp16 4 dest (rp) 4 src rp 4F 16 dest disp 
        1110 xxxx xxxx xxxx  Fmt18 1 ZZ  stord (rp) disp4 4 dest (rp) 4 src rp 4 dest disp*2 

        1111 1110 xxxx xxxx  Fmt18 1 ZZ ope 0  storb (prp) disp0 4 dest (prp) 4 src reg 4E 
        1111 1111 xxxx xxxx  Fmt19 2 ZZ  storb (rp) disp16 4 dest (rp) 4 src reg 4 ope  0F 16 dest disp 
        1111 xxxx xxxx xxxx  Fmt18 1 ZZ  storb (rp) disp4a 4 dest (rp) 4 src reg 4 dest disp 
        1111 1111 1111 1111  Fmt1 2 ZZ  res - undefined trap 
        */
    }
}