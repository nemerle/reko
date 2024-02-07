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

namespace Reko.Arch.RiscV
{
    public enum Mnemonic
    {
        invalid,

        add,
        addi,
        addiw,
        addw,
        amoadd_d,
        amoadd_w,
        amoand_d,
        amoand_w,
        amomax_d,
        amomax_w,
        amomaxu_d,
        amomaxu_w,
        amomin_d,
        amomin_w,
        amominu_d,
        amominu_w,
        amoor_d,
        amoor_w,
        amoswap_d,
        amoswap_w,
        amoxor_d,
        amoxor_w,
        and,
        andi,
        auipc,
        beq,
        bge,
        bgeu,
        blt,
        bltu,
        bne,
        c_add,
        c_addi,
        c_addi16sp,
        c_addi4spn,
        c_addiw,
        c_addw,
        c_and,
        c_andi,
        c_beqz,
        c_bnez,
        c_ebreak,
        c_fld,
        c_fldsp,
        c_flw,
        c_flwsp,
        c_fsd,
        c_fsdsp,
        c_fsw,
        c_fswsp,
        c_j,
        c_jal,
        c_jalr,
        c_jr,
        c_ld,
        c_ldsp,
        c_li,
        c_lqsp,
        c_lui,
        c_lw,
        c_lwsp,
        c_mv,
        c_nop,
        c_or,
        c_sd,
        c_sdsp,
        c_slli,
        c_srai,
        c_srli,
        c_sub,
        c_subw,
        c_sw,
        c_swsp,
        c_xor,
        csrrc,
        csrrci,
        csrrs,
        csrrsi,
        csrrw,
        csrrwi,
        div,
        divu,
        divuw,
        divw,
        ebreak,
        ecall,
        fabs_d,
        fabs_h,
        fabs_q,
        fabs_s,
        fadd_d,
        fadd_h,
        fadd_q,
        fadd_s,
        fclass_d,
        fclass_h,
        fclass_q,
        fclass_s,
        fcvt_d_h,
        fcvt_d_l,
        fcvt_d_lu,
        fcvt_d_q,
        fcvt_d_s,
        fcvt_d_w,
        fcvt_d_wu,
        fcvt_h_d,
        fcvt_h_l,
        fcvt_h_lu,
        fcvt_h_q,
        fcvt_h_s,
        fcvt_h_w,
        fcvt_h_wu,
        fcvt_l_d,
        fcvt_l_h,
        fcvt_l_q,
        fcvt_l_s,
        fcvt_lu_d,
        fcvt_lu_h,
        fcvt_lu_q,
        fcvt_lu_s,
        fcvt_q_d,
        fcvt_q_h,
        fcvt_q_l,
        fcvt_q_lu,
        fcvt_q_s,
        fcvt_q_w,
        fcvt_q_wu,
        fcvt_s_d,
        fcvt_s_h,
        fcvt_s_l,
        fcvt_s_lu,
        fcvt_s_q,
        fcvt_s_w,
        fcvt_s_wu,
        fcvt_w_d,
        fcvt_w_h,
        fcvt_w_q,
        fcvt_w_s,
        fcvt_wu_d,
        fcvt_wu_h,
        fcvt_wu_q,
        fcvt_wu_s,
        fdiv_d,
        fdiv_h,
        fdiv_q,
        fdiv_s,
        fence,
        fence_i,
        fence_tso,
        feq_d,
        feq_h,
        feq_q,
        feq_s,
        fld,
        fle_d,
        fle_h,
        fle_q,
        fle_s,
        flh,
        fli_d,
        fli_h,
        fli_q,
        fli_s,
        flq,
        flt_d,
        flt_h,
        flt_q,
        flt_s,
        flw,
        fmadd_d,
        fmadd_h,
        fmadd_q,
        fmadd_s,
        fmax_d,
        fmax_h,
        fmax_q,
        fmax_s,
        fmaxm_d,
        fmaxm_h,
        fmaxm_q,
        fmaxm_s,
        fmin_d,
        fmin_h,
        fmin_q,
        fmin_s,
        fminm_d,
        fminm_h,
        fminm_q,
        fminm_s,
        fmsub_d,
        fmsub_h,
        fmsub_q,
        fmsub_s,
        fmul_d,
        fmul_h,
        fmul_q,
        fmul_s,
        fmv_d,
        fmv_d_x,
        fmv_h,
        fmv_h_x,
        fmv_q,
        // fmv_q_x, //$TODO: this will be part of RV128
        fmv_s,
        fmv_w_x,
        fmv_x_d,
        fmv_x_h,
        // fmv_x_q, //$TODO: this will be part of RV128
        fmv_x_w,
        fneg_d,
        fneg_h,
        fneg_q,
        fneg_s,
        fnmadd_d,
        fnmadd_h,
        fnmadd_q,
        fnmadd_s,
        fnmsub_d,
        fnmsub_h,
        fnmsub_q,
        fnmsub_s,
        fround_d,
        fround_h,
        fround_q,
        fround_s,
        froundnx_d,
        froundnx_h,
        froundnx_q,
        froundnx_s,
        fsd,
        fsgnj_d,
        fsgnj_h,
        fsgnj_q,
        fsgnj_s,
        fsgnjn_d,
        fsgnjn_h,
        fsgnjn_q,
        fsgnjn_s,
        fsgnjx_d,
        fsgnjx_h,
        fsgnjx_q,
        fsgnjx_s,
        fsh,
        fsq,
        fsqrt_d,
        fsqrt_h,
        fsqrt_q,
        fsqrt_s,
        fsub_d,
        fsub_h,
        fsub_q,
        fsub_s,
        fsw,
        hfence_gvma,
        hfence_vvma,
        hinval_gvma,
        hinval_vvma,
        hlv_b,
        hlv_bu,
        hlv_d,
        hlv_w,
        hlv_wu,
        hlv_du,
        hlv_h,
        hlv_hu,
        hlvx_h,
        hlvx_hu,
        hlvx_wu,
        hsv_b,
        hsv_bu,
        hsv_d,
        hsv_du,
        hsv_h,
        hsv_hu,
        hsv_w,
        jal,
        jalr,
        lb,
        lbu,
        ld,
        lh,
        lhu,
        lr_d,
        lr_h,
        lr_q,
        lr_w,
        lui,
        lw,
        lwu,
        mret,
        mul,
        mulh,
        mulhsu,
        mulhu,
        mulw,
        or,
        ori,
        pause,
        rem,
        remu,
        remuw,
        remw,
        sb,
        sc_d,
        sc_h,
        sc_w,
        sd,
        sfence_inval,
        sfence_inval_ir,
        sfence_vm,
        sfence_vma,
        sfence_w_inval,
        sh,
        sinval_vma,
        sll,
        slli,
        slliw,
        sllw,
        slt,
        slti,
        sltiu,
        sltu,
        sra,
        srai,
        sraiw,
        sraw,
        sret,
        srl,
        srli,
        srliw,
        srlw,
        sub,
        subw,
        sw,
        uret,
        wfi,
        xor,
        xori,
    }
}