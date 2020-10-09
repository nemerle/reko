#region License
/* 
 * Copyright (C) 1999-2019 John Källén.
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

namespace Reko.Arch.XCore
{
    public enum Mnemonic
    {
        Invalid,

        add,
        addi,
        and,
        andnot,
        ashr,
        bau,
        bitrev,
        bla,
        blacp,
        blat,
        blrb,
        blrf,
        brbf,
        brbt,
        brbu,
        brff,
        brft,
        brfu,
        bru,
        byterev,
        chkct,
        chkcti,
        clre,
        clrsr,
        clz,
        dcall,
        dualentsp,
        edu,
        eef,
        eet,
        eeu,
        endin,
        entsp,
        eq,
        eqi,
        extdp,
        extsp,
        freer,
        freet,
        geted,
        getet,
        getid,
        getkep,
        getksp,
        getps,
        getsr,
        getst,
        @in,
        inshr,
        kcalli,
        kentsp,
        ld16s,
        ld8u,
        ldapb,
        ldapf,
        ldawcp,
        ldawdp,
        ldawsp,
        ldc,
        ldsed,
        ldset,
        ldspc,
        ldssr,
        ldwcp,
        ldwdp,
        ldwi,
        ldwsp,
        lss,
        lsu,
        mjoin,
        mkmsk,
        mkmski,
        msync,
        neg,
        nop,
        or,
        @out,
        outct,
        outcti,
        outshr,
        outt,
        peek,
        retsp,
        setci,
        setd,
        setkep,
        setpsc,
        setsr,
        setv,
        shli,
        shri,
        ssync,
        stet,
        stsed,
        stspc,
        stssr,
        stwdp,
        stwi,
        stwsp,
        sub,
        subi,
        testct,
        testwct,
        tstart,
        waitef,
        waitet,
        waiteu,
    }
}