// spcinv.c
// Generated by decompiling spcinv.sav
// using Reko decompiler version 0.8.0.0.

#include "spcinv.h"

// 0200: void fn0200(Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
void fn0200(Eq_2 r4, Eq_3 * r5, Eq_4 * pc)
{
	do
	{
		PRINT(&globals->b0F9A);
		ptr16 sp_119 = fp;
		word16 r2_29 = 0x02;
		Eq_14 r3_115 = 0x00;
		do
		{
			word16 r0_14;
		} while (TTYIN(out r0_14));
		do
		{
			word16 r0_19;
		} while (TTYIN(out r0_19));
		do
		{
			word16 r0_21;
		} while (TTYIN(out r0_21));
		if (0xF0A8 == 0x00)
		{
			PRINT(&globals->b0FDA);
			do
			{
				word16 r0_406;
			} while (TTYIN(out r0_406));
			break;
		}
		r2_29 = 0x01;
		r3_115.u0 = 0x01;
		if (~0x0F50 == 0x00)
			break;
		r2_29 = 0x00;
		r3_115.u0 = 0x02;
	} while (61611 != 0x00);
	globals->w0F06 = r2_29;
	globals->u0F08 = r3_115;
	globals->w0024 = globals->w0024 | 0x1040;
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	globals->w0AB4 = globals->w1170;
	globals->w0B5E = 0x00;
	globals->w1166 = 0x0101;
	globals->w1168 = 4446;
	FnSubfn(&globals->w1166);
	if (true)
	{
		globals->w1166 = 0x0801;
		globals->w1168 = 0x00;
		globals->w116A = 0x0B5E;
		globals->w116C = 0x01;
		globals->w116E = 0x00;
		FnSubfn(&globals->w1166);
		__syscall(0x88FC);
	}
	ptr16 r2_118;
	ptr16 r1_110 = fn0BD6(out r2_118);
l02A2:
	fn0C20(r3_115, r5, pc);
	while (true)
	{
		Eq_155 r0_90;
		if (!TTYIN(out r0_90) && globals->ptr0EFA == 0x00)
			break;
		globals->w1166 = 0x1100;
		globals->w1168 = 4464;
		FnSubfn(&globals->w1166);
		ci16 r0_101 = globals->w1170 - globals->w1172;
		if (r0_101 >= 0x00)
		{
			globals->w1174 = globals->w1170;
			pc->w0E52 = pc->w0E52 + 0x01;
			globals->w0EF6 = ~globals->w0EF4;
			if (v49 == 0x00)
				globals->w0EF8 = ~globals->w0EF6;
			if (globals->ptr0EFA != 0x00)
			{
				globals->w0EFC = globals->ptr0EFA - 0x01;
				if (v55 != 0x00)
					goto l0370;
				if (globals->w0F18 == 0x00)
					goto l03AE;
				Eq_2 r4_327;
				struct Eq_3 * r5_328;
				Eq_14 r3_329 = fn0486(r3_115, r4, r5, bArg00, out r4_327, out r5_328);
				globals->w0F16 = 0x02;
				r4 = fn0470(r2_118, r3_329, r4_327, r5_328, bArg00);
				globals->w0F18 = 0x78;
			}
			if (globals->w0EF8 == 0x00)
			{
				if (0x08 - globals->w0F14 >= 0x00)
					goto l0370;
				globals->w0F18 = globals->w0F16 - 0x01;
				if (v91 > 0x00)
					goto l0370;
				globals->ptr0EFA = 1110;
			}
			word16 r2_292;
			byte NZ_293;
			bool V_294;
			word16 r3_295;
			bool C_296;
			bool N_297;
			bool Z_298;
			word16 r0_299;
			word16 r1_300;
			byte NZVC_301;
			byte NZV_302;
			byte ZC_305;
			word16 r5_306;
			globals->ptr0EFA();
l0370:
			Eq_2 r4_244;
			struct Eq_3 * r5_245;
			Eq_267 r1_246 = fn04A0(r4, pc, out r4_244, out r5_245);
			Eq_14 r3_248;
			Eq_2 r4_249;
			struct Eq_3 * r5_250;
			ptr16 r1_251 = fn07A6(fn06D6(r1_246, r4_244, r5_245, pc), pc, out r3_248, out r4_249, out r5_250);
			r1_110 = fn0998(r1_251, r3_248, r4_249, r5_250, pc, bArg00, out r2_118, out r3_115, out r4, out r5);
			if (0x1178 - r4 != 0x00)
				goto l038E;
			if (globals->w0F12 != 0x00)
				continue;
			if (globals->w0F02 != 0x00)
				goto l0392;
			if (true)
			{
				globals->w0F1A = globals->w0F18 + 0x01;
				goto l02A2;
			}
l03AE:
			cup16 v67_163 = globals->w0B5A - globals->w0B5A;
			if (v67_163 > 0x00)
			{
				globals->w0B5E = globals->w0B5A;
				globals->w1166 = 0x0101;
				globals->w1168 = 4446;
				FnSubfn(&globals->w1166);
				if (v67_163 < 0x00)
				{
					globals->w1166 = 0x0201;
					globals->w1168 = 4446;
					globals->w116A = 0x01;
					FnSubfn(&globals->w1166);
					if (v67_163 >= 0x00)
						goto l03E6;
				}
				else
				{
l03E6:
					globals->w1166 = 0x0901;
					globals->w1168 = 0x00;
					globals->w116A = 0x0B5E;
					globals->w116C = 0x01;
					globals->w116E = 0x00;
					FnSubfn(&globals->w1166);
					__syscall(0x88FC);
				}
			}
			Eq_2 r4_178;
			struct Eq_3 * r5_179;
			Eq_14 r3_180 = fn0486(r3_115, r4, r5, bArg00, out r4_178, out r5_179);
			struct Eq_392 * sp_181 = sp_119 - 0x01;
			sp_181->b0000 = 0x01;
			sp_181->b0001 = 0x18;
			Eq_2 r4_187;
			struct Eq_3 * r5_188;
			fn0AB6(r3_180, r4_178, r5_179, out r4_187, out r5_188);
			Eq_2 r4_191;
			struct Eq_3 * r5_192;
			fn0AE8(r4_187, r5_188, wLoc02, out r4_191, out r5_192);
			*(r1_110 - 0x02) = (union Eq_2 *) r4_191;
			word16 r4_199;
			word16 r5_200;
			fn0AE8(r4_191, r5_192, wLoc02, out r4_199, out r5_200);
		}
		if (0x1178 - r4 == 0x00)
			continue;
l038E:
		r3_115 = fn0AF6(r3_115, r4, r5, bArg00, out r4, out r5);
l0392:
	}
	globals->u02CB = r0_90;
	word16 * r1_354 = &globals->w02C6;
	do
	{
		r1_354 = r1_408 + 0x01;
		word16 * r1_408 = r1_354;
	} while (*r1_408 - r0_90 != 0x00);
	struct Eq_171 * r1_364 = r1_354 - 711 << 0x01;
	word16 sp_366;
	word16 r2_367;
	byte NZ_368;
	bool V_369;
	word16 r3_370;
	bool C_371;
	bool N_372;
	bool Z_373;
	word16 r0_374;
	word16 r1_375;
	byte NZVC_376;
	byte NZV_377;
	word16 pc_378;
	word16 r4_379;
	byte ZC_380;
	word16 r5_381;
	r1_364->ptr02CC();
}

// 0470: Register Eq_2 fn0470(Register ptr16 r2, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00)
Eq_2 fn0470(ptr16 r2, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00)
{
	word16 wLoc02_6 = DPB(wLoc02, globals->w0F14, 8);
	Eq_2 r4_14;
	struct Eq_3 * r5_15;
	fn0AB6(r3, r4, r5, out r4_14, out r5_15);
	Eq_2 r4_17;
	word16 r5_18;
	fn0AE8(r4_14, r5_15, wLoc02_6, out r4_17, out r5_18);
	*(r2 - 0x02) = (union Eq_2 *) r4_17;
	return r4_17;
}

// 0486: Register Eq_14 fn0486(Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_14 fn0486(Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r4Out, ptr16 & r5Out)
{
	Eq_2 r4_12;
	struct Eq_3 * r5_13;
	Eq_14 r3_14 = fn0AB6(r3, r4, r5, out r4_12, out r5_13);
	word16 r4_15;
	word16 r5_16;
	fn0A74(r4_12, r5_13, out r4_15, out r5_16);
	return r3_14;
}

// 04A0: Register Eq_267 fn04A0(Register Eq_2 r4, Register (ptr Eq_4) pc, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_267 fn04A0(Eq_2 r4, Eq_4 * pc, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4Out = r4;
	*r5Out = r5;
	cui16 v5_4 = pc->w0A52 & globals->w0EF4;
	pc->w0A52 = v5_4;
	struct Eq_621 * sp_1 = fp;
	if (v5_4 != 0x00)
		return r1;
	struct Eq_3 * r5_100 = globals->ptr0F04;
	do
	{
		Eq_14 r3_54 = (int16) r5_100[0x0778];
		if (r3_54 != 0x00)
		{
			globals->u0F0C = r3_54;
			Eq_635 r0_92 = (int16) r5_100->b0EF3;
			sp_1 = sp_1 - 0x01;
			sp_1->b0000 = (byte) r3_54;
			sp_1->b0001 = (byte) r0_92;
			byte * r4_99;
			Eq_14 r3_101 = fn0AB6(r3_54, r4, r5_100, out r4_99, out r5_100);
			*r4_99 = 0x20;
			r4 = r4_99 + 0x01;
			*r4Out = r4;
			int16 r0_105 = r0_92 - 0x01;
			if (true && 0x04 - (r0_92 - 0x01) <= 0x00 || 0x02 - (r0_92 - 0x01) == 0x00)
			{
l0584:
				r5_100[0x0778] = (struct Eq_3) 0x00;
				goto l0588;
			}
			r5_100->b0EF3 = (byte) (r0_92 - 0x01);
			if (22 - (r0_92 - 0x01) >= 0x00 && fn067C(r0_92 - 0x01, r3_101, r4_99 + 0x01, r5_100, bLoc02, out r0_105, out r1, out r3_101, out r4, out r5_100))
				goto l0584;
			r1 = r0_105 + 0x01;
			if (0x03 - r0_105 == 0x00 && (true && fn05D4(r1, r3_101, r4, r5_100, pc, bLoc02, out r0_105, out r1, out r3_101, out r4, out r5_100)))
				goto l0584;
			word16 r0_155;
			if (fn064A(r0_105, r1, r3_101, r4, r5_100, out r0_155, out r4, out r5_100))
				goto l0584;
			struct Eq_750 * r2_159 = null;
			do
			{
				if (r2_159[0x06DC] - r0_155 == 0x00)
				{
l0524:
					Eq_427 r0_222 = r2_159[0x06D6];
					r1.u0 = 0x08;
					do
					{
						Eq_14 r3_232 = *r0_222;
						if (r3_232 != 0x00)
						{
							if (true)
							{
								if ((word16) r3_232 + 0x04 - r5_100[0x0778] <= 0x00)
								{
									if (*r0_222 - r5_100[0x0778] < 0x00)
										break;
									Eq_267 r1_265 = *r0_222;
									*r0_222 = *r0_222 | 0x8000;
									struct Eq_924 * r0_268 = r0_222 - r2_159[0x06D6];
									globals->ptr0F0A = r0_268;
									r0_268->w0DC4 = r0_268->w0DC4 - 0x01;
									sp_1 = sp_1 - 0x01;
									sp_1->b0000 = (byte) r1_265;
									sp_1->b0001 = (byte) r2_159[0x06DC];
									byte * r4_278;
									struct Eq_3 * r5_279;
									fn0AB6((word16) r3_232 + 0x04, r4, r5_100, out r4_278, out r5_279);
									Eq_2 r4_281;
									struct Eq_3 * r5_282;
									ptr16 r1_283 = fn0A7C(r1_265, r4_278, r5_279, pc, out r4_281, out r5_282);
									pc->w05F2 = (word16) r2_159[1770] + pc->w05F2;
									word16 r3_289;
									fn0B1A(r1_283, r4_281, r5_282, bLoc02, out r1, out r3_289, out r4, out r5_100);
									globals->w0F14 = globals->w0F12 - 0x01;
									if (v79 <= 0x00 && true)
									{
										globals->ptr0EFA = 0x00;
										globals->w0EFC = 0x05;
									}
									goto l0584;
								}
							}
							else
							{
								struct Eq_839 * sp_308 = sp_1 - 0x01;
								sp_308->b0000 = (byte) *r0_222;
								sp_308->t0001 = r2_159[0x06DC];
								Eq_2 r4_314;
								struct Eq_3 * r5_315;
								fn0AB6(r3_232, r4, r5_100, out r4_314, out r5_315);
								Eq_2 r4_317;
								struct Eq_3 * r5_318;
								r0_222 = fn0A74(r4_314, r5_315, out r4_317, out r5_318);
								*r0_222 = 0x00;
								int16 r3_323 = (int16) r5_318[0x0778];
								*(sp_308 - 0x01) = (union Eq_877 *) (r3_323 + 0x01);
								sp_308->b0000 = r5_318->b0EF3;
								fn0AB6(r3_323 + 0x01, r4_317, r5_318, out r4, out r5_100);
								sp_1 = sp_308 - 0x01;
							}
						}
						r0_222 = (word32) r0_222 + 0x02;
						r1 = r1 - 0x01;
					} while (r1 != 0x00);
					break;
				}
				cup16 v43_334 = r2_159[0x06DC] - r1;
				if (v43_334 < 0x00)
					break;
				if (v43_334 == 0x00)
					goto l0524;
				r2_159 = r2_159 + 0x01;
			} while (0x0A - r2_159 <= 0x00);
			Eq_2 r4_189;
			struct Eq_3 * r5_190;
			fn0AE8(r4, r5_100, wLoc02, out r4_189, out r5_190);
			sp_1->b0000 = (byte) r4_189;
			byte * r4_197;
			struct Eq_3 * r5_198;
			fn0AE8(r4_189, r5_190, wLoc02, out r4_197, out r5_198);
			byte ** r1_200 = r1 - 0x02;
			*r1_200 = (byte **) r4_197;
			*r4_197 = globals->b1159;
			fn0AE8(r4_197 + 0x01, r5_198, wLoc02, out r4, out r5_100);
			*(r1_200 - 0x02) = (union Eq_2 *) r4;
			sp_1 = sp_1 + 0x01;
			r1 = r1_200 - 0x02;
		}
		else
		{
l0588:
		}
		r5_100 = r5_100 - 0x01;
		*r5Out = r5_100;
	} while (r5_100 >= null);
	return r1;
}

// 05D4: FlagGroup bool fn05D4(Register Eq_267 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Stack byte bArg00, Register out Eq_739 r0Out, Register out Eq_740 r1Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out (ptr Eq_743) r5Out)
bool fn05D4(Eq_267 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, Eq_4 * pc, byte bArg00, Eq_739 & r0Out, Eq_740 & r1Out, ptr16 & r3Out, ptr16 & r4Out, Eq_743 * & r5Out)
{
	*r3Out = r3;
	*r1Out = r1;
	*r4Out = r4;
	*r5Out = r5;
	*r0Out = r0;
	word16 v9_6 = r3 - globals->w0F02;
	cup16 v12_10 = 0x04 - v9_6;
	bool Z_120 = cond(v12_10);
	if (v12_10 <= 0x00)
	{
		byte * r4_50;
		struct Eq_3 * r5_51;
		fn0AB6(r3, r4, r5, out r4_50, out r5_51);
		Eq_2 r4_54;
		struct Eq_3 * r5_55;
		ptr16 r1_56 = fn0A7C(r1, r4_50, r5_51, pc, out r4_54, out r5_55);
		fn0A94();
		ui16 r3_60 = __rol(0x00, 0x00);
		ui16 r3_62 = __rol(r3_60, r3_60);
		word16 r0_124 = globals->a0F2A[r3_62 * 0x02];
		Eq_1080 v25_65 = pc->t090A >> 0x01;
		pc->t090A = v25_65;
		if (v25_65 >= 0x00)
			r0_124 = r0_124 + 200;
		pc->w054A = pc->w054A + r0_124;
		*(fp - 0x02) = globals->w0F02;
		*(fp - 0x01) = 0x04;
		Eq_2 r4_80;
		struct Eq_3 * r5_81;
		fn0AB6(r3_62 << 0x01, r4_54, r5_55, out r4_80, out r5_81);
		byte * r4_83;
		struct Eq_3 * r5_84;
		Eq_427 r0_85 = fn0AE8(r4_80, r5_81, v9_6, out r4_83, out r5_84);
		*(r1_56 - 0x02) = (byte **) r4_83;
		*r4_83 = 0x28;
		byte * r4_94;
		fn0B60(r0_85, 0x03, r4_83 + 0x01, out r4_94);
		*r4_94 = 0x29;
		Eq_2 r4_101;
		struct Eq_3 * r5_102;
		fn0AE8(r4_94 + 0x01, r5_84, v9_6, out r4_101, out r5_102);
		*(r1_56 - 0x04) = (union Eq_2 *) r4_101;
		word16 r1_110;
		word16 r3_111;
		word16 r4_112;
		word16 r5_113;
		word16 r0_114;
		*r0Out = fn0B1A(r1_56 - 0x04, r4_101, r5_102, bLoc02, out r1_110, out r3_111, out r4_112, out r5_113);
		globals->b0F05 = ~0x00;
		Z_120 = true;
	}
	return Z_120;
}

// 064A: FlagGroup bool fn064A(Register int16 r0, Register Eq_267 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r0Out, Register out ptr16 r4Out, Register out (ptr Eq_725) r5Out)
bool fn064A(int16 r0, Eq_267 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, ptr16 & r0Out, ptr16 & r4Out, Eq_725 * & r5Out)
{
	*r5Out = r5;
	*r0Out = r0;
	*r4Out = r4;
	struct Eq_1193 * r2_10 = globals->w0F06;
	do
	{
		bool Z_30;
		if (r2_10[0x0EE6] - r3 == 0x00 && r2_10[0x0EEC] >= 0x00)
		{
			if (r2_10[0x0EE9] - r1 != 0x00)
			{
				if (r2_10[0x0EE9] - r0 != 0x00)
					goto l0676;
				byte * r4_76;
				word16 r5_77;
				word16 r0_78;
				*r0Out = fn0AE8(r4, r5, wLoc02, out r4_76, out r5_77);
				*fp = (byte **) r4_76;
				*r4_76 = 0x20;
				word16 r4_84;
				*r4Out = r4_76 + 0x01;
			}
			r2_10[0x0EE6] = (struct Eq_1193) 0x00;
			Z_30 = true;
			return Z_30;
		}
l0676:
		r2_10 = r2_10 - 0x01;
		Z_30 = cond(r2_10);
	} while (r2_10 >= null);
	return Z_30;
}

// 067C: FlagGroup bool fn067C(Register Eq_696 r0, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out Eq_701 r0Out, Register out Eq_702 r1Out, Register out (ptr Eq_703) r3Out, Register out ptr16 r4Out, Register out (ptr Eq_705) r5Out)
bool fn067C(Eq_696 r0, Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00, Eq_701 & r0Out, Eq_702 & r1Out, Eq_703 * & r3Out, ptr16 & r4Out, Eq_705 * & r5Out)
{
	*r3Out = r3;
	*r0Out = r0;
	*r5Out = r5;
	*r4Out = r4;
	struct Eq_1258 * r1_7 = (word32) r0 + (r3 - 0x01 << 0x01);
	*r1Out = r1_7;
	byte v11_9 = r1_7->b0E2A;
	bool Z_12 = cond(v11_9);
	if (v11_9 != 0x00)
	{
		r1_7->b0E2A = r1_7->b0E2A - 0x01;
		struct Eq_1281 * r1_39 = (int16) r1_7->b0E2A;
		*r1Out = r1_39;
		byte * r4_46;
		word16 r5_47;
		word16 r3_48;
		*r3Out = fn0AB6(r3, r4, r5, out r4_46, out r5_47);
		byte v23_49 = r1_39->b0EE0;
		*r4_46 = v23_49;
		word16 r4_51;
		*r4Out = r4_46 + 0x01;
		Z_12 = cond(v23_49);
	}
	return Z_12;
}

// 06A2: void fn06A2()
void fn06A2()
{
	if (globals->ptr0F0A != 0x00)
	{
		struct Eq_1313 * r5_25 = globals->ptr0F04;
		do
		{
			if (r5_25[0x0EF0] == 0x00)
			{
				cup16 r0_37 = globals->w0F14;
				if (0x08 - r0_37 >= 0x00)
				{
					r5_25[0x0EF0] = (struct Eq_1313) (r0_37 + 0x02);
					r5_25[0x0EF3] = (struct Eq_1313) 0x18;
					globals->u0F0C = 0x00;
				}
				return;
			}
			r5_25 = r5_25 - 0x01;
		} while (r5_25 >= null);
	}
}

// 06D6: Register Eq_2 fn06D6(Register Eq_267 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
Eq_2 fn06D6(Eq_267 r1, Eq_2 r4, Eq_3 * r5, Eq_4 * pc)
{
	struct Eq_1350 * sp_1 = fp;
	struct Eq_1352 * r2_25 = globals->w0F06;
	do
	{
		Eq_14 r3_28 = (int16) r2_25[0x0EE6];
		if (r3_28 != 0x00)
		{
			cui16 v12_49 = pc->w0812 & globals->w0EF4;
			pc->w0812 = v12_49;
			if (v12_49 == 0x00 && (false || globals->w0EF4 - globals->w0EF4 == 0x00))
				goto l07A0;
			Eq_14 r3_134;
			Eq_1376 r0_57 = (int16) r2_25[0x0EE9];
			if (r2_25[0x0EEC] >= 0x00)
			{
				sp_1 = sp_1 - 0x01;
				sp_1->b0000 = (byte) r3_28;
				sp_1[0x01] = (struct Eq_1350) r0_57;
				byte * r4_186;
				r3_134 = fn0AB6(r3_28, r4, r5, out r4_186, out r5);
				*r4_186 = 0x20;
				r4 = r4_186 + 0x01;
			}
			else
			{
				sp_1 = sp_1 - 0x01;
				sp_1->b0000 = (byte) ((word16) r3_28 + 0x01);
				sp_1[0x01] = (struct Eq_1350) r0_57;
				r3_134 = fn0AB6((word16) r3_28 + 0x01, r4, r5, out r4, out r5) - 0x01;
				r2_25[0x0EEC] = (struct Eq_1352) (r2_25[0x0EEC] & ~0x80);
			}
			r2_25[0x0EE9] = (struct Eq_1352) ((byte) r2_25[0x0EE9] + 0x01);
			if (0x19 - ((word32) r0_57 + 0x01) != 0x00)
			{
				if (0x18 - ((word32) r0_57 + 0x01) != 0x00)
				{
					if (22 - ((word32) r0_57 + 0x01) < 0x00)
						goto l078A;
					word16 r0_132;
					if (!fn067C((word32) r0_57 + 0x01, r3_134, r4, r5, bLoc02, out r0_132, out r1, out r3_134, out r4, out r5))
						goto l0784;
					goto l078A;
				}
				if (globals->ptr0EFA == 0x00 && globals->w0F14 - r3_134 >= 0x00)
				{
					r3_134 = r3_134 - 0x04;
					if (globals->w0F14 - r3_134 > 0x00)
						goto l078A;
					sp_1 = sp_1 - 0x01;
					sp_1->b0000 = globals->w0F14;
					sp_1[0x01] = (struct Eq_1350) 0x18;
					byte * r4_157;
					struct Eq_3 * r5_158;
					fn0AB6(r3_134, r4, r5, out r4_157, out r5_158);
					Eq_2 r4_160;
					struct Eq_3 * r5_161;
					ptr16 r1_162 = fn0A7C(r1, r4_157, r5_158, pc, out r4_160, out r5_161);
					globals->ptr0EFA = 0x00;
					globals->w0EFC = 0x05;
					globals->w0F1A = globals->w0F18 - 0x01;
					Eq_2 r4_169;
					struct Eq_3 * r5_170;
					fn0AE8(r4_160, r5_161, wLoc02, out r4_169, out r5_170);
					*(r1_162 - 0x02) = (union Eq_2 *) r4_169;
					r1 = fn0B3A(r1_162 - 0x02, r4_169, r5_170, bLoc02, out r4, out r5);
					goto l0784;
				}
l078A:
				Eq_2 r4_102;
				struct Eq_3 * r5_103;
				fn0AE8(r4, r5, wLoc02, out r4_102, out r5_103);
				**r3_134 = r4_102;
				byte * r4_110;
				struct Eq_3 * r5_111;
				fn0AE8(r4_102, r5_103, wLoc02, out r4_110, out r5_111);
				byte ** r1_113 = r1 - 0x02;
				*r1_113 = (byte **) r4_110;
				*r4_110 = globals->b115A;
				fn0AE8(r4_110 + 0x01, r5_111, wLoc02, out r4, out r5);
				*(r1_113 - 0x02) = (union Eq_2 *) r4;
				r1 = r1_113 - 0x02;
			}
			else
			{
l0784:
				r2_25[0x0EE6] = (struct Eq_1352) 0x00;
			}
		}
l07A0:
		r2_25 = r2_25 - 0x01;
	} while (r2_25 >= null);
	return r4;
}

// 07A6: Register (ptr Eq_1623) fn07A6(Register Eq_2 r4, Register (ptr Eq_4) pc, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_1623 * fn07A6(Eq_2 r4, Eq_4 * pc, ptr16 & r3Out, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4Out = r4;
	*r5Out = r5;
	*r3Out = r3;
	globals->w0F1E = globals->w0F1C - 0x01;
	struct Eq_1639 * sp_1 = fp;
	if (v5 == 0x00)
	{
		globals->w0F1E = globals->w0F26;
		struct Eq_3 * r5_166;
		*r5Out = 0x00;
		do
		{
			struct Eq_1678 * r2_182 = globals->w0F1A;
			Eq_427 r0_183 = r2_182->t0DB8;
			if (r0_183 != 0x00)
			{
				if (globals->w0EFC != 0x00)
				{
					struct Eq_1623 * r1_395 = r2_182->ptr0DAC;
					Eq_14 r3_396 = 0x08;
					do
					{
						if (r1_395->t0000 != 0x00)
						{
							sp_1 = sp_1 - 0x01;
							sp_1->b0000 = (byte) r1_395->t0000;
							sp_1[0x01] = (struct Eq_1639) r0_183;
							Eq_2 r4_438;
							struct Eq_3 * r5_439;
							r3_396 = fn0AB6(r3_396, r4, r5_166, out r4_438, out r5_439);
							r0_183 = fn0A74(r4_438, r5_439, out r4, out r5_166);
							if (r1_395->t0000 <= 0x00)
								r1_395->t0000.u0 = 0x00;
						}
						r1_395 = r1_395 + 0x01;
						r3_396 = r3_396 - 0x01;
					} while (r3_396 != 0x00);
					r2_182->t0DB8 = (word32) r2_182->t0DB8 + 0x01;
					r0_183 = (word16) r0_183 + 0x01;
				}
				r1 = r2_182->ptr0DAC;
				Eq_14 r3_266 = 0x08;
				do
				{
					if (true)
					{
						r1->t0000 = (word32) r1->t0000 + globals->w0F20;
						if (0x08 - r1->t0000 <= 0x00 || 0x48 - r1->t0000 >= 0x00)
							globals->ptr0F00 = sp_1;
						if (0x17 - r0_183 == 0x00)
							globals->w0F02 = sp_1;
						if (22 - r0_183 >= 0x00)
							fn093C(r0_183, r1);
						sp_1 = sp_1 - 0x01;
						sp_1->b0000 = (byte) r1->t0000;
						sp_1[0x01] = (struct Eq_1639) r0_183;
						Eq_2 r4_339;
						struct Eq_3 * r5_340;
						ptr16 r3_342 = fn096A(fn0AB6(r3_266, r4, (char *) &r5_166->ptr0000 + 0x01, out r4_339, out r5_340));
						r0_183 = fn0AE8(r4_339, r5_340, wLoc02, out r4, out r5_166);
						**(r3_342 - 0x02) = (union Eq_2 **) r4;
						r3_266 = r3_342 - 0x02;
					}
					else if (true && globals->w0EFC == 0x00)
					{
						sp_1 = sp_1 - 0x01;
						sp_1->b0000 = (byte) r1->t0000;
						sp_1[0x01] = (struct Eq_1639) r0_183;
						Eq_2 r4_383;
						struct Eq_3 * r5_384;
						r3_266 = fn0AB6(r3_266, r4, r5_166, out r4_383, out r5_384);
						r0_183 = fn0A74(r4_383, r5_384, out r4, out r5_166);
						r1->t0000 = 0x00;
					}
					r1 = r1 + 0x01;
					r3_266 = r3_266 - 0x01;
					*r3Out = r3_266;
				} while (r3_266 != 0x00);
				if (r5_166 == null)
					r2_182->t0DB8.u0 = 0x00;
			}
			ci16 v80_200 = pc->w06AE - 0x02;
			pc->w06AE = v80_200;
			if (v80_200 < 0x00)
			{
				globals->w0F1C = 0x0A;
				globals->w0DAA = ~globals->w0DA8;
				if (globals->w0EFC != 0x00)
					globals->w0EFE = 0x00;
				else if (globals->w0EFE != 0x00)
				{
					globals->w0F22 = -globals->w0F20;
					if (globals->ptr0F00 == 0x00)
						globals->w0EFE = 0x01;
				}
				globals->ptr0F00 = 0x00;
				globals->w0F02 = 0x00;
				goto l08B2;
			}
		} while (r5_166 == null);
		globals->ptr0F28 = r5_166;
	}
l08B2:
	if (globals->w0F12 != 0x00)
	{
		cui16 v38_48 = pc->w063A & globals->w0EF4;
		pc->w063A = v38_48;
		if (v38_48 != 0x00)
		{
			struct Eq_1741 * r2_53 = globals->w0F06;
			do
			{
				if (r2_53[0x0EE6] == 0x00)
				{
					do
					{
						if ((fn0A94() & globals->w0F0E) != 0x00)
							return r1;
						cui16 r0_88 = fn0A94();
						r1 = globals->u0F08;
						if (r1 >= null && (true && r0_88 << 0x01 < 0x00))
							break;
						ui16 r1_134 = __rol(0x00, 0x00);
						ui16 r1_136 = __rol(r1_134, r1_134);
						r1 = __rol(r1_136, r1_136) << 0x01;
					} while (false);
					struct Eq_1791 * r0_100 = globals->a0DB8;
					do
					{
						r0_100 = r0_100 - 0x02;
						byte * r3_103 = r1 + r0_100->w0000 / 0x02;
					} while (false);
					int16 r3_110 = (int16) *r3_103;
					r2_53[0x0EE6] = (struct Eq_1741) (r3_110 + 0x02);
					r2_53[0x0EE9] = (struct Eq_1741) r0_100[0x06];
					r2_53[0x0EEC] = (struct Eq_1741) 0x80;
					word16 r3_111;
					*r3Out = r3_110 + 0x02;
					if (3500 - r0_100 == 0x00 || (fn0A94() & globals->u0F0C) == 0x00)
						r2_53[0x0EEC] = (struct Eq_1741) ((byte) r2_53[0x0EEC] + 0x01);
					return r1;
				}
				r2_53 = r2_53 - 0x01;
			} while (r2_53 >= null);
		}
	}
	return r1;
}

// 093C: void fn093C(Register Eq_427 r0, Register (ptr Eq_1623) r1)
void fn093C(Eq_427 r0, Eq_1623 * r1)
{
	word16 r3_7 = r1->t0000;
	cui16 r3_17 = r3_7 - 0x01;
	if (globals->w0F20 >= 0x00)
		r3_17 = r3_7 - 0x02;
	struct Eq_2079 * r3_21 = (word32) r0 + (r3_17 << 0x01) - 22 + 0x0E40;
	word16 wLoc04_24 = 0x07;
	do
	{
		r3_21->b0000 = 0x00;
		word16 v21_33 = wLoc04_24 - 0x01;
		r3_21 = r3_21 + 0x01;
		wLoc04_24 = v21_33;
	} while (v21_33 != 0x00);
}

// 096A: Register Eq_14 fn096A(Register Eq_14 r3)
Eq_14 fn096A(Eq_14 r3)
{
	if ((r3 & 0x01) == 0x00)
	{
		if (globals->w0DA8 == 0x00)
		{
l0976:
			globals->b112D = 0x2F;
			globals->b1131 = 0x5C;
			return r3 & 0x01;
		}
	}
	else if (globals->w0DA8 != 0x00)
		goto l0976;
	globals->b112D = 0x5C;
	globals->b1131 = 0x2F;
	return r3 & 0x01;
}

// 0998: Register ptr16 fn0998(Register ptr16 r1, Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Stack byte bArg00, Register out ptr16 r2Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out ptr16 r5Out)
ptr16 fn0998(ptr16 r1, Eq_14 r3, Eq_2 r4, Eq_3 * r5, Eq_4 * pc, byte bArg00, ptr16 & r2Out, ptr16 & r3Out, ptr16 & r4Out, ptr16 & r5Out)
{
	*r3Out = r3;
	*r4Out = r4;
	*r5Out = r5;
	Eq_2143 r2_109 = globals->w0F02;
	*r2Out = r2_109;
	if (true)
	{
		globals->w0F20 = globals->w0F1E - 0x01;
		if (v10 != 0x00)
		{
			if (r2_109 == 0x00 || 0x28 - globals->w0F1E > 0x00)
				return r1;
			goto l0A2A;
		}
		globals->w0F20 = 100;
		globals->w0F12 = 0x01;
		globals->w0A6A = 4404;
		cui16 r0_164 = fn0A94();
		*r2Out = 0x01;
		r1 = 0x00;
		int16 r0_165 = r0_164 << 0x01;
		if (r0_164 << 0x01 < 0x00)
		{
			r0_165 = r0_164 << 0x02;
			if (r0_164 << 0x02 < 0x00)
			{
				globals->w0F12 = globals->w0F10 + 0x01;
				globals->w0A6A = 0x113D;
				r1 = 0x0A;
			}
		}
		if (r0_165 <= 0x00)
		{
			globals->w0F12 = -globals->w0F10;
			pc->w008A = pc->w008A + r1;
			*r2Out = 0x4A;
		}
	}
	if (globals->w0EF4 != 0x00 || globals->w0EF6 != 0x00)
	{
l0A18:
		globals->ptr0F04 = r2_109;
		return r1;
	}
	if (globals->w0F10 >= 0x00)
	{
		if (0x49 - r2_109 != 0x00)
		{
l0A04:
			*r2Out = (word16) r2_109.u1 + globals->w0F10;
			Eq_2 r4_142;
			struct Eq_3 * r5_143;
			word16 r3_144;
			*r3Out = fn0AB6(r3, r4, r5, out r4_142, out r5_143);
			fn0A60(r1, r4_142, r5_143);
			goto l0A18;
		}
	}
	else if (0x02 - r2_109 != 0x00)
		goto l0A04;
l0A2A:
	Eq_2 r4_61;
	struct Eq_3 * r5_62;
	Eq_14 r3_63 = fn0AB6(r3, r4, r5, out r4_61, out r5_62);
	Eq_2 r4_64;
	struct Eq_3 * r5_65;
	fn0A74(r4_61, r5_62, out r4_64, out r5_65);
	*(fp - 0x02) = (union Eq_2143 *) r2_109;
	*(fp - 0x01) = 0x04;
	Eq_2 r4_73;
	struct Eq_3 * r5_74;
	word16 r3_75;
	*r3Out = fn0AB6(r3_63, r4_64, r5_65, out r4_73, out r5_74);
	word16 r4_76;
	word16 r5_77;
	fn0A74(r4_73, r5_74, out r4_76, out r5_77);
	globals->ptr0F04 = 0x00;
	if (true)
	{
		globals->ptr0EFA = 0x00;
		globals->w0EFC = 0x05;
	}
	return r1;
}

// 0A60: void fn0A60(Register ptr16 r1, Register Eq_2 r4, Register (ptr Eq_3) r5)
void fn0A60(ptr16 r1, Eq_2 r4, Eq_3 * r5)
{
	Eq_2 r4_5;
	struct Eq_3 * r5_6;
	fn0AE8(r4, r5, wLoc02, out r4_5, out r5_6);
	*(r1 - 0x02) = (union Eq_2 *) r4_5;
	word16 r4_14;
	word16 r5_15;
	fn0AE8(r4_5, r5_6, wLoc02, out r4_14, out r5_15);
	__halt();
}

// 0A74: Register Eq_427 fn0A74(Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_427 fn0A74(Eq_2 r4, Eq_3 * r5, ptr16 & r4Out, ptr16 & r5Out)
{
	word16 r4_5;
	struct Eq_2369 * r5_6;
	Eq_427 r0_7 = fn0AE8(r4, r5, wLoc02, out r4_5, out r5_6);
	r5_6->ptr0000 = r5_6;
	word16 r5_10;
	*r5Out = (char *) &r5_6->ptr0000 + 0x02;
	return r0_7;
}

// 0A7C: Register Eq_267 fn0A7C(Register Eq_267 r1, Register (ptr byte) r4, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_267 fn0A7C(Eq_267 r1, byte * r4, Eq_3 * r5, Eq_4 * pc, ptr16 & r4Out, ptr16 & r5Out)
{
	*r4 = globals->b0F24;
	Eq_2 r4_11;
	struct Eq_3 * r5_12;
	fn0AE8(r4 + 0x01, r5, wLoc02, out r4_11, out r5_12);
	*(r1 - 0x02) = (union Eq_2 *) r4_11;
	Eq_2 r4_20;
	struct Eq_3 * r5_21;
	fn0AE8(r4_11, r5_12, wLoc02, out r4_20, out r5_21);
	pc->ptr0000 = r5_21;
	word16 r4_28;
	word16 r5_29;
	fn0AE8(r4_20, r5_21, wLoc02, out r4_28, out r5_29);
	*(r1 - 0x04) = r4_28;
	return r1 - 0x04;
}

// 0A94: Register ui16 fn0A94()
ui16 fn0A94()
{
	ui16 r0_10 = ((DPB(__swab(globals->w0AB2), 0x00, 0) << 0x01) + globals->w0AB2 << 0x02) + globals->w0AB2;
	globals->w0AB4 = r0_10 + 0x3619;
	return r0_10 + 0x3619;
}

// 0AB6: Register Eq_14 fn0AB6(Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Register out ptr16 r4Out, Register out (ptr Eq_411) r5Out)
Eq_14 fn0AB6(Eq_14 r3, Eq_2 r4, Eq_3 * r5, ptr16 & r4Out, Eq_411 * & r5Out)
{
	byte * r4_5;
	word16 r5_6;
	Eq_427 r0_7 = fn0AE8(r4, r5, wLoc02, out r4_5, out r5_6);
	*fp->t0000 = r4_5;
	fp->t0000 = r0_7;
	*(fp - 0x02) = (union Eq_14 *) r3;
	byte * r4_20;
	fn0B60((int16) fp->b0005, ~0x01, r4_5, out r4_20);
	*r4_20 = 0x3B;
	byte * r4_29;
	fn0B60((int16) fp->t0004, ~0x01, r4_20 + 0x01, out r4_29);
	*r4_29 = 0x48;
	Eq_14 v19_34 = *(fp - 0x02);
	fp->t0004 = fp->t0002;
	word16 r4_33;
	*r4Out = r4_29 + 0x01;
	return v19_34;
}

// 0AE8: Register word16 fn0AE8(Register Eq_2 r4, Register (ptr Eq_3) r5, Stack word16 wArg00, Register out ptr16 r4Out, Register out (ptr Eq_423) r5Out)
word16 fn0AE8(Eq_2 r4, Eq_3 * r5, word16 wArg00, ptr16 & r4Out, Eq_423 * & r5Out)
{
	byte * r0_14 = r5->ptr0000;
	do
	{
		byte v9_15 = *r0_14;
		r4->u0 = v9_15;
		r0_14 = r0_14 + 0x01;
		r4 = (word32) r4 + 0x01;
	} while (v9_15 != 0x00);
	word16 sp_33;
	word16 r0_34;
	byte NZ_35;
	bool V_36;
	word16 r5_37;
	word16 r4_38;
	bool Z_39;
	byte NZV_40;
	r5[0x01]();
	return r0_34;
}

// 0AF6: Register Eq_14 fn0AF6(Register Eq_14 r3, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r4Out, Register out ptr16 r5Out)
Eq_14 fn0AF6(Eq_14 r3, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r4Out, ptr16 & r5Out)
{
	byte * r4_15;
	word16 r5_16;
	Eq_14 r3_17 = fn0AB6(r3, r4, r5, out r4_15, out r5_16);
	*r4_15 = 0x80;
	PRINT(&globals->b1178);
	word16 r4_21;
	*r4Out = 0x1178;
	return r3_17;
}

// 0B1A: Register Eq_427 fn0B1A(Register ptr16 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out Eq_990 r1Out, Register out ptr16 r3Out, Register out ptr16 r4Out, Register out (ptr Eq_993) r5Out)
Eq_427 fn0B1A(ptr16 r1, Eq_2 r4, Eq_3 * r5, byte bArg00, Eq_990 & r1Out, ptr16 & r3Out, ptr16 & r4Out, Eq_993 * & r5Out)
{
	word16 wLoc02_8 = DPB(wLoc02, 0x2B, 8);
	Eq_2 r4_15;
	struct Eq_3 * r5_16;
	Eq_14 r3_17 = fn0AB6(0x05, r4, r5, out r4_15, out r5_16);
	byte * r4_18;
	struct Eq_3 * r5_19;
	Eq_427 r0_20 = fn0AE8(r4_15, r5_16, wLoc02_8, out r4_18, out r5_19);
	*(r1 - 0x02) = (byte **) r4_18;
	Eq_2 r4_27;
	fn0B60(r0_20, r3_17, r4_18, out r4_27);
	Eq_427 r0_29 = globals->w0F18;
	*(fp - 0x02) = 0x1F;
	*(fp - 0x01) = 0x02;
	byte * r4_37;
	struct Eq_3 * r5_38;
	Eq_14 r3_39 = fn0AB6(0x03, r4_27, r5_19, out r4_37, out r5_38);
	Eq_2 r4_40;
	word16 r3_41;
	*r3Out = fn0B60(r0_29, r3_39, r4_37, out r4_40);
	word16 r4_42;
	word16 r5_43;
	Eq_427 r0_44 = fn0AE8(r4_40, r5_38, wLoc02_8, out r4_42, out r5_43);
	*(r1 - 0x04) = r4_42;
	word16 r1_45;
	*r1Out = r1 - 0x04;
	return r0_44;
}

// 0B3A: Register ptr16 fn0B3A(Register ptr16 r1, Register Eq_2 r4, Register (ptr Eq_3) r5, Stack byte bArg00, Register out ptr16 r4Out, Register out ptr16 r5Out)
ptr16 fn0B3A(ptr16 r1, Eq_2 r4, Eq_3 * r5, byte bArg00, ptr16 & r4Out, ptr16 & r5Out)
{
	Eq_427 r0_3 = globals->w0F18;
	byte * r4_15;
	struct Eq_3 * r5_16;
	Eq_14 r3_17 = fn0AB6(0x03, r4, r5, out r4_15, out r5_16);
	Eq_2 r4_18;
	fn0B60(r0_3, r3_17, r4_15, out r4_18);
	word16 r4_20;
	word16 r5_21;
	fn0AE8(r4_18, r5_16, DPB(wLoc02, 0x1F, 8), out r4_20, out r5_21);
	*(r1 - 0x02) = r4_20;
	return r1 - 0x02;
}

// 0B60: Register Eq_14 fn0B60(Register Eq_427 r0, Register Eq_14 r3, Register (ptr byte) r4, Register out ptr16 r4Out)
Eq_14 fn0B60(Eq_427 r0, Eq_14 r3, byte * r4, ptr16 & r4Out)
{
	*r4Out = r4;
	word16 wLoc08_100 = 0x00;
	if (r3 >= 0x00)
		globals->w0BC8 = 0x20;
	else
	{
		globals->w0BC8 = 0x30;
		r3 = -r3;
	}
	if (r3 != 0x00)
	{
		word16 * r2_55 = 0x0BD4 - (r3 << 0x01);
		do
		{
			word16 r5_64 = 0x30;
			cup16 v22_67 = *r2_55;
			r2_55 = r2_55 + 0x01;
			if (v22_67 == 0x00)
				return r3;
			while (true)
			{
				r0 = r0 - v22_67;
				if (r0 < 0x00)
					break;
				r5_64 = r5_64 + 0x01;
			}
			Eq_2704 r5_106;
			r0 = (word32) r0 + v22_67;
			if (wLoc08_100 == 0x00)
			{
				if (r5_64 != ~0x2F)
				{
					wLoc08_100 = wLoc08_100 + 0x01;
					goto l0BB4;
				}
				if (0x01 - r3 == 0x00 || *r2_55 == 0x00)
					goto l0BB4;
				r5_106 = (int16) globals->b0BC6;
			}
			else
			{
l0BB4:
				r5_106 = r5_64 + 0x00;
			}
			*r4 = (byte) r5_106;
			*r4Out = r4 + 0x01;
			r3 = r3 - 0x01;
		} while (r3 != 0x00);
	}
	return r3;
}

// 0BD6: Register ptr16 fn0BD6(Register out ptr16 r2Out)
ptr16 fn0BD6(ptr16 & r2Out)
{
	globals->w0F1A = 0x03;
	globals->w0B5C = 0x00;
	globals->w0F0E = 0xF800;
	globals->w0F10 = 0xE000;
	byte * r1_14 = &globals->b0E56;
	word16 r0_18 = 0x06;
	do
	{
		word16 r2_19 = 0x0A;
		do
		{
			*r1_14 = 0x04;
			r1_14 = r1_14 + 0x01;
			r2_19 = r2_19 - 0x01;
			*r2Out = r2_19;
		} while (r2_19 != 0x00);
		r1_14 = r1_14 + 0x0A;
		r0_18 = r0_18 - 0x01;
	} while (r0_18 != 0x00);
	globals->w1166 = 0x1100;
	globals->w1168 = 4464;
	FnSubfn(&globals->w1166);
	globals->w1174 = globals->w1170;
	return r1_14 + 0x0A;
}

// 0C20: void fn0C20(Register Eq_14 r3, Register (ptr Eq_3) r5, Register (ptr Eq_4) pc)
void fn0C20(Eq_14 r3, Eq_3 * r5, Eq_4 * pc)
{
	word16 * r1_12 = globals->a0DB8;
	word16 r0_15 = 0x06;
	Eq_760 r2_13 = 0x05;
	do
	{
		*r1_12 = (word16) r2_13;
		r1_12 = r1_12 + 0x01;
		r2_13.u1 = (word16) r2_13.u1 + 0x02;
		r0_15 = r0_15 - 0x01;
	} while (r0_15 != 0x00);
	struct Eq_2828 * r1_18 = null;
	word16 r0_20 = 0x08;
	ptr16 r2_21 = 11;
	do
	{
		r1_18[1776] = (struct Eq_2828) r2_21;
		r1_18[0x06F8] = (struct Eq_2828) r2_21;
		r1_18[0x0700] = (struct Eq_2828) r2_21;
		r1_18[1800] = (struct Eq_2828) r2_21;
		r1_18[1808] = (struct Eq_2828) r2_21;
		r1_18[1816] = (struct Eq_2828) r2_21;
		r1_18[0x06E2] = (struct Eq_2828) 0x06;
		r1_18 = r1_18 + 0x01;
		r2_21 = r2_21 + 0x08;
		r0_20 = r0_20 - 0x01;
	} while (r0_20 != 0x00);
	word16 * r1_43 = globals->a0EE6;
	word16 r0_44 = 0x10;
	do
	{
		*r1_43 = (word16) 0x00;
		r1_43 = r1_43 + 0x01;
		r0_44 = r0_44 - 0x01;
	} while (r0_44 != 0x00);
	globals->ptr0F0A = ~0x00;
	globals->w0F14 = 0x30;
	globals->w0F16 = 0x02;
	globals->w0F18 = 0x78;
	globals->w0F1C = 0x0A;
	globals->w0F1E = 0x04;
	globals->ptr0F28 = 0x04;
	globals->w0F20 = 100;
	globals->w0F22 = 0x01;
	pc->w025E = pc->w025E << 0x01;
	ui16 v35_68 = pc->w025C << 0x01;
	pc->w025C = v35_68;
	if (v35_68 == 0x00)
		pc->w0256 = pc->w0256 >> 0x01;
	Eq_2 r4_78;
	struct Eq_3 * r5_79;
	fn0AE8(0x1178, r5, wLoc02, out r4_78, out r5_79);
	*r1_43 = (word16) r4_78;
	Eq_2 r4_86;
	struct Eq_3 * r5_87;
	fn0AE8(r4_78, r5_79, wLoc02, out r4_86, out r5_87);
	*r1_43 = (word16) r4_86;
	*(fp - 0x01) = 0x02;
	*fp = 0x18;
	Eq_2 r4_98;
	struct Eq_3 * r5_99;
	Eq_14 r3_100 = fn0AB6(r3, r4_86, r5_87, out r4_98, out r5_99);
	Eq_2 r4_101;
	struct Eq_3 * r5_102;
	fn0AE8(r4_98, r5_99, wLoc02, out r4_101, out r5_102);
	*(r2_21 - 0x02) = (union Eq_2 *) r4_101;
	*(fp - 0x02) = 0x02;
	*(fp - 0x01) = 0x02;
	Eq_2 r4_112;
	struct Eq_3 * r5_113;
	fn0AB6(r3_100, r4_101, r5_102, out r4_112, out r5_113);
	word16 r4_115;
	word16 r5_116;
	fn0AE8(r4_112, r5_113, wLoc02, out r4_115, out r5_116);
}

