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

namespace Reko.Arch.zSeries
{
    public enum Mnemonic
    {
        invalid,

        a,
        ad,
        adb,
        adr,
        ae,
        aeb,
        aer,
        afi,
        ag,
        agf,
        agfi,
        agfr,
        aghi,
        aghik,
        agr,
        agrk,
        agsi,
        ah,
        ahhhr,
        ahhlr,
        ahi,
        ahik,
        ahy,
        aih,
        al,
        alc,
        alcg,
        alcgr,
        alcr,
        alfi,
        alg,
        algf,
        algfi,
        algfr,
        alghsik,
        algr,
        algrk,
        algsi,
        alhhhr,
        alhhlr,
        alhsik,
        alr,
        alrk,
        alsi,
        alsih,
        alsihn,
        aly,
        ap,
        ar,
        ark,
        asi,
        au,
        aur,
        aw,
        awr,
        axr,
        ay,
        b,
        bakr,
        bal,
        balr,
        bas,
        basr,
        bassm,
        bct,
        bctg,
        bctgr,
        bctr,
        be,
        ber,
        bh,
        bhe,
        bher,
        bhr,
        bl,
        ble,
        bler,
        blh,
        blhr,
        blr,
        bne,
        bner,
        bnh,
        bnhe,
        bnher,
        bnhr,
        bnl,
        bnle,
        bnler,
        bnlh,
        bnlhr,
        bnlr,
        bno,
        bnor,
        bo,
        bor,
        bpp,
        bprp,
        br,
        brasl,
        brc,
        brcl,
        brctg,
        brcth,
        brxh,
        brxhg,
        brxle,
        brxlg,
        bsa,
        bsg,
        bsm,
        bxh,
        bxhg,
        bxle,
        bxleg,
        c,
        cd,
        cdb,
        cdftr,
        cdlftr,
        cdlgtr,
        cdpt,
        cdr,
        cds,
        cdsg,
        cdsy,
        cdzt,
        ce,
        ceb,
        cer,
        cfc,
        cfdtr,
        cfi,
        cfxtr,
        cg,
        cgf,
        cgfi,
        cgfr,
        cgfrl,
        cgh,
        cghi,
        cghrl,
        cgib,
        cgij,
        cgit,
        cgr,
        cgrb,
        cgrj,
        cgrl,
        cgrt,
        ch,
        chf,
        chhr,
        chi,
        chlr,
        chrl,
        chy,
        cib,
        cih,
        cij,
        cit,
        cksm,
        cl,
        clc,
        clcl,
        clcle,
        clclu,
        clfdtr,
        clfi,
        clfit,
        clfxtr,
        clg,
        clgdtr,
        clgf,
        clgfi,
        clgfr,
        clgfrl,
        clghrl,
        clgib,
        clgij,
        clgit,
        clgr,
        clgrb,
        clgrj,
        clgrl,
        clgrt,
        clgt,
        clgxtr,
        clhf,
        clhhr,
        clhlr,
        clhrl,
        cli,
        clib,
        clih,
        clij,
        cliy,
        clm,
        clmh,
        clmy,
        clr,
        clrb,
        clrj,
        clrl,
        clrt,
        clst,
        clt,
        cly,
        cmpsc,
        cp,
        cpdt,
        cpxt,
        cpya,
        cr,
        crb,
        crdte,
        crj,
        crl,
        crt,
        cs,
        csch,
        csg,
        csp,
        cspg,
        csst,
        csy,
        cu12,
        cu14,
        cu24,
        cu41,
        cu42,
        cuse,
        cutfu,
        cuutf,
        cvb,
        cvbg,
        cvby,
        cvd,
        cvdg,
        cvdy,
        cxftr,
        cxlftr,
        cxlgtr,
        cxpt,
        cxzt,
        cy,
        czdt,
        czxt,
        d,
        dd,
        ddb,
        ddr,
        de,
        deb,
        der,
        diag,
        dl,
        dlg,
        dlgr,
        dlr,
        dp,
        dr,
        dsg,
        dsgf,
        dsgfr,
        dsgr,
        dxr,
        ear,
        ecag,
        ectg,
        ed,
        edmk,
        epair,
        epar,
        epsw,
        ereg,
        eregg,
        esair,
        esar,
        esea,
        esta,
        etnd,
        ex,
        exrl,
        flogr,
        hdr,
        her,
        hsch,
        iac,
        ic,
        icm,
        icmh,
        icmy,
        icy,
        idte,
        iihh,
        iihl,
        iilh,
        iill,
        ipk,
        ipm,
        ipte,
        iske,
        ivsk,
        j,
        je,
        jg,
        jge,
        jgh,
        jghe,
        jgl,
        jgle,
        jglh,
        jgne,
        jgnh,
        jgnhe,
        jgnl,
        jgnle,
        jgnlh,
        jgno,
        jgo,
        jh,
        jhe,
        jl,
        jle,
        jlh,
        jne,
        jnh,
        jnhe,
        jnl,
        jnle,
        jnlh,
        jno,
        jo,
        kdb,
        keb,
        kimd,
        klmd,
        km,
        kmac,
        kmc,
        kmctr,
        kmf,
        kmo,
        l,
        la,
        laa,
        laag,
        laal,
        laalg,
        lae,
        laey,
        lam,
        lamy,
        lan,
        lang,
        lao,
        laog,
        larl,
        lat,
        lax,
        laxg,
        lay,
        lb,
        lbh,
        lbr,
        lcbb,
        lcdr,
        lceir,
        lcer,
        lcgfr,
        lcgr,
        lcr,
        lctl,
        lctlg,
        ld,
        lde,
        ldeb,
        ldgr,
        ldr,
        ldxr,
        ldy,
        le,
        ledr,
        ler,
        ley,
        lfas,
        lfh,
        lfhat,
        lfpc,
        lg,
        lgat,
        lgb,
        lgbr,
        lgdr,
        lgf,
        lgfr,
        lgfrl,
        lgh,
        lghi,
        lghr,
        lghrl,
        lgr,
        lgrl,
        lh,
        lhh,
        lhi,
        lhr,
        lhrl,
        lhy,
        llc,
        llch,
        llcr,
        llgc,
        llgcr,
        llgf,
        llgfat,
        llgfr,
        llgfrl,
        llgh,
        llghr,
        llghrl,
        llgt,
        llgtat,
        llgtr,
        llh,
        llhh,
        llhr,
        llhrl,
        llihh,
        llihl,
        llilh,
        llill,
        llzrgf,
        lm,
        lmd,
        lmg,
        lmh,
        lmy,
        lndr,
        lner,
        lngfr,
        lngr,
        lnr,
        loc,
        locfh,
        locfhr,
        locg,
        locghi,
        locgr,
        locgre,
        locgrh,
        locgrhe,
        locgrl,
        locgrle,
        locgrlh,
        locgrne,
        locgrnh,
        locgrnhe,
        locgrnl,
        locgrnle,
        locgrnlh,
        locgrno,
        locgrnv,
        locgro,
        lochhi,
        lochi,
        locr,
        locre,
        locrh,
        locrhe,
        locrl,
        locrle,
        locrlh,
        locrne,
        locrnh,
        locrnhe,
        locrnl,
        locrnle,
        locrnlh,
        locrno,
        locro,
        lpd,
        lpdg,
        lpdr,
        lper,
        lpgfr,
        lpgr,
        lpq,
        lpr,
        lpsw,
        lpswe,
        lptea,
        lr,
        lra,
        lrag,
        lray,
        lrl,
        lrv,
        lrvg,
        lrvgr,
        lrvh,
        lrvr,
        lt,
        ltdr,
        lter,
        ltg,
        ltgf,
        ltgfr,
        ltgr,
        ltr,
        lura,
        lurag,
        lxd,
        lxdb,
        lxe,
        lxeb,
        ly,
        lzrf,
        lzrg,
        m,
        mad,
        madb,
        mae,
        maeb,
        may,
        mayh,
        mayl,
        mc,
        md,
        mdb,
        mde,
        mdeb,
        mdr,
        medr,
        mee,
        meeb,
        meer,
        mfy,
        mghi,
        mh,
        mhi,
        mhy,
        ml,
        mlg,
        mlgr,
        mlr,
        mp,
        mr,
        ms,
        msch,
        msd,
        msdb,
        mse,
        mseb,
        msfi,
        msg,
        msgf,
        msgfi,
        msgfr,
        msgr,
        msr,
        msta,
        msy,
        mvc,
        mvcin,
        mvck,
        mvcl,
        mvcle,
        mvclu,
        mvcos,
        mvcp,
        mvcs,
        mvhi,
        mvi,
        mviy,
        mvo,
        mvpg,
        mvst,
        mvz,
        mxd,
        mxdb,
        mxdr,
        mxr,
        my,
        myh,
        myl,
        n,
        nc,
        ng,
        ngr,
        ngrk,
        ni,
        niai,
        nihh,
        nihl,
        nilh,
        nill,
        niy,
        nop,
        nopr,
        nr,
        nrk,
        ntstg,
        ny,
        o,
        oc,
        og,
        ogr,
        ogrk,
        oi,
        oihh,
        oihl,
        oilh,
        oill,
        oiy,
        or,
        ork,
        oy,
        pack,
        palb,
        pc,
        pcc,
        pckmo,
        pfd,
        pfdrl,
        pfmf,
        pgin,
        pgout,
        pka,
        pku,
        plo,
        popcnt,
        ppa,
        ppno,
        pr,
        pt,
        ptf,
        pti,
        ptlb,
        rchp,
        risbg,
        risbgn,
        risbhg,
        risblg,
        rll,
        rllg,
        rnsbg,
        rosbg,
        rp,
        rrbe,
        rrbm,
        rsch,
        rxsbg,
        s,
        sac,
        sacf,
        sal,
        sar,
        schm,
        sck,
        sckc,
        sd,
        sdb,
        sdr,
        se,
        seb,
        ser,
        sg,
        sgf,
        sgfr,
        sgr,
        sgrk,
        sh,
        shhhr,
        shhlr,
        shy,
        sigp,
        sl,
        sla,
        slag,
        slak,
        slb,
        slbg,
        slbgr,
        slbr,
        slda,
        sldl,
        sldt,
        slfi,
        slg,
        slgf,
        slgfi,
        slgfr,
        slgr,
        slgrk,
        slhhhr,
        slhhlr,
        sll,
        sllg,
        sllk,
        slr,
        slrk,
        slxt,
        sly,
        sp,
        spka,
        spm,
        spt,
        spx,
        sqd,
        sqdb,
        sqdr,
        sqe,
        sqeb,
        sqer,
        sr,
        sra,
        srag,
        srak,
        srda,
        srdl,
        srdt,
        srk,
        srl,
        srlg,
        srlk,
        srnm,
        srnmb,
        srnmt,
        srp,
        srst,
        srstu,
        srxt,
        ssair,
        ssar,
        ssch,
        sske,
        ssm,
        st,
        stam,
        stamy,
        stap,
        stc,
        stch,
        stck,
        stckc,
        stcke,
        stckf,
        stcm,
        stcmh,
        stcmy,
        stcps,
        stcrw,
        stctg,
        stctl,
        stcy,
        std,
        stdy,
        ste,
        stey,
        stfh,
        stfl,
        stfle,
        stfpc,
        stg,
        stgrl,
        sth,
        sthh,
        sthrl,
        sthy,
        stidp,
        stm,
        stmg,
        stmh,
        stmy,
        stnsm,
        stoc,
        stocfh,
        stocg,
        stosm,
        stpq,
        stpt,
        stpx,
        strl,
        strv,
        strvg,
        strvh,
        stsch,
        stsi,
        stura,
        sturg,
        sty,
        su,
        sur,
        svc,
        sw,
        swr,
        sxr,
        sy,
        tabort,
        tar,
        tb,
        tcdb,
        tceb,
        tcxb,
        tdcdt,
        tdcet,
        tdcxt,
        tdgdt,
        tdget,
        tdgxt,
        tend,
        tm,
        tmhh,
        tmhl,
        tmlh,
        tmll,
        tmy,
        to,
        tp,
        tpi,
        tr,
        trace,
        tracg,
        trap4,
        tre,
        troo,
        trot,
        trt,
        trte,
        trto,
        trtr,
        trtre,
        trtt,
        ts,
        tsch,
        unpk,
        unpka,
        unpku,
        va,
        vac,
        vacc,
        vaccc,
        vavg,
        vavgl,
        vcdg,
        vcdlg,
        vceq,
        vcgd,
        vch,
        vchl,
        vcksm,
        vclgd,
        vclz,
        vctz,
        vec,
        vecl,
        verim,
        verll,
        verllv,
        vesl,
        veslv,
        vesra,
        vesrav,
        vesrl,
        vesrlv,
        vfa,
        vfae,
        vfce,
        vfch,
        vfche,
        vfd,
        vfee,
        vfene,
        vfi,
        vfm,
        vfma,
        vfms,
        vfpso,
        vfs,
        vfsq,
        vftci,
        vgbm,
        vgef,
        vgeg,
        vgfm,
        vgfma,
        vgm,
        vistr,
        vl,
        vlbb,
        vlc,
        vlde,
        vleb,
        vled,
        vlef,
        vleg,
        vleh,
        vleib,
        vleif,
        vleig,
        vleih,
        vlgv,
        vll,
        vllez,
        vlm,
        vlp,
        vlr,
        vlrep,
        vlvg,
        vlvgp,
        vmae,
        vmah,
        vmal,
        vmale,
        vmalh,
        vmalo,
        vmao,
        vme,
        vmh,
        vml,
        vmle,
        vmlh,
        vmlo,
        vmn,
        vmnl,
        vmo,
        vmrh,
        vmrl,
        vmx,
        vmxl,
        vn,
        vnc,
        vno,
        vo,
        vpdi,
        vperm,
        vpk,
        vpkls,
        vpks,
        vpopct,
        vrep,
        vrepi,
        vs,
        vsbcbi,
        vsbi,
        vscbi,
        vscef,
        vsceg,
        vseg,
        vsel,
        vsl,
        vslb,
        vsldb,
        vsra,
        vsrab,
        vsrl,
        vsrlb,
        vst,
        vsteb,
        vstef,
        vsteg,
        vsteh,
        vstl,
        vstm,
        vstrc,
        vsum,
        vsumg,
        vsumq,
        vtm,
        vuph,
        vupl,
        vuplh,
        vupll,
        vx,
        wfc,
        wfk,
        x,
        xc,
        xg,
        xgr,
        xgrk,
        xi,
        xiy,
        xr,
        xrk,
        xsch,
        xy,
        zap,
    }
}

