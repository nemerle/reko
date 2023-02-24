// fft_normal.c
// Generated by decompiling fft.hex
// using Reko decompiler version 0.11.4.0.

#include "fft.h"

// 0115: Register Eq_n reverse(Register Eq_n gp0, Register out (ptr16 Eq_n) gp14Out)
// Called from:
//      fn0100
//      init_fft
Eq_n reverse(Eq_n gp0, struct Eq_n & gp14Out)
{
	struct Eq_n * fp;
	Eq_n gp0_n = 0x00;
	word16 gp1_n = 0x00;
	do
	{
		ci16 gp1_n = -gp1_n;
		if ((__shift_arithmetic<word16,word16>(gp0, gp1_n) & 0x01) != 0x00)
			gp0_n |= __shift_logical<word16,word16>(0x01, 0x03 - gp1_n);
		gp1_n = gp1_n + 0x01;
	} while (gp1_n <= 0x02);
	gp14Out = fp;
	return gp0_n;
}

// 012E: Register int16 init_fft(Register out ptr16 gp4Out)
// Called from:
//      main
int16 init_fft(ptr16 & gp4Out)
{
	ptr16 fp;
	struct Eq_n * gp14_n = fp - 0x01;
	Eq_n gp3_n = 0x00;
	do
	{
		gp14_n[1] = (struct Eq_n) gp3_n;
		ui16 gp0_n = reverse(gp3_n, out gp14_n);
		Eq_n gp3_n = gp14_n[1];
		g_aFFFF8030[gp0_n] = (struct Eq_n) (&g_tFFFF8000)[gp3_n *16 0x03];
		real48 gp4_gp5_gp6_n = g_tFFFF8000.t0000;
		g_aFFFF8060[gp0_n] = (struct Eq_n) gp4_gp5_gp6_n;
		ptr16 gp4_n = SLICE(gp4_gp5_gp6_n, word16, 32);
		gp3_n = (word16) gp3_n.u0 + 1;
	} while (gp3_n <= 0x0E);
	gp4Out = gp4_n;
	return (word16) gp3_n.u0 + 1;
}

// 014E: Register (ptr16 Eq_n) compute_output()
// Called from:
//      main
struct Eq_n * compute_output()
{
	ptr16 fp;
	struct Eq_n * gp14_n = fp - 0x02;
	uint16 gp9_n = 0x00;
	do
	{
		ui16 gp8_n = gp9_n * 0x03;
		real48 gp5_gp6_gp7_n = g_aFFFF8030[gp9_n];
		real48 gp2_gp3_gp4_n = g_aFFFF8060[gp9_n];
		gp14_n[1] = (struct Eq_n) SEQ(gp8_n, gp9_n);
		real48 gp5_gp6_gp7_n = gp5_gp6_gp7_n * gp5_gp6_gp7_n + gp2_gp3_gp4_n * gp2_gp3_gp4_n;
		*((word16) gp14_n[1].w0002 + 0x0000808E) = (struct Eq_n) sqrt((word32) gp5_gp6_gp7_n, (word16) gp5_gp6_gp7_n, out gp14_n);
		ci16 gp9_n = gp14_n[2];
		gp9_n = gp9_n + 0x01;
	} while (gp9_n <= 0x0E);
	return gp14_n;
}

// 016F: void fft(Register uint16 gp3, Register uint16 gp4)
// Called from:
//      main
void fft(uint16 gp3, uint16 gp4)
{
	ptr16 fp;
	struct Eq_n * gp14_n = fp - 0x0F;
	do
	{
		gp14_n->w0001 = gp14_n->w0002 << 0x01;
		gp14_n->w0003 = 0x00;
		if (gp14_n->w0003 < gp14_n->w0002)
		{
			gp14_n->r000A = (real48) (SEQ(gp14_n->w0002, gp3) >> 0x10);
			do
			{
				real48 gp3_gp4_gp5_n = (real48) (SEQ(gp14_n->w0003, gp4) >> 0x10) * g_rFFFF8003 / gp14_n->r000A;
				gp14_n->r000D = gp3_gp4_gp5_n;
				struct Eq_n * gp14_n;
				gp14_n->t0004.u0 = (real48) cos((word32) gp3_gp4_gp5_n, (word16) gp3_gp4_gp5_n, out gp14_n);
				real48 gp3_gp4_gp5_n = gp14_n->r000D;
				gp14_n->t0007.u0 = (real48) sin((word32) gp3_gp4_gp5_n, (word16) gp3_gp4_gp5_n, out gp3, out gp4, out gp14_n);
				int16 gp0_n;
				for (gp0_n = gp14_n->w0003; gp0_n < 0x10; gp0_n += gp14_n->w0001)
				{
					real48 * gp11_n = (gp14_n->w0002 + gp0_n) * 0x03 + 0x8060;
					real48 gp8_gp9_gp10_n = gp14_n->r0004 * (g_aFFFF8030)[0].r0000 - (gp14_n->t0007).u0 * *gp11_n;
					real48 gp5_gp6_gp7_n = gp14_n->t0007.u0 * (g_aFFFF8030)[0].r0000 + gp14_n->r0004 * *gp11_n;
					g_aFFFF8030[0].r0000 = (real48) (g_aFFFF8030[0].r0000 - gp8_gp9_gp10_n);
					real48 gp2_gp3_gp4_n = g_aFFFF8060[gp0_n] - gp5_gp6_gp7_n;
					*gp11_n = gp2_gp3_gp4_n;
					g_aFFFF8030[0].r0000 = (real48) (gp8_gp9_gp10_n + (g_aFFFF8030)[0].r0000);
					g_aFFFF8060[gp0_n] = (struct Eq_n) (gp5_gp6_gp7_n + g_aFFFF8060[gp0_n]);
					gp3 = SLICE(gp2_gp3_gp4_n, word16, 16);
					gp4 = (word16) gp2_gp3_gp4_n;
				}
				++gp14_n->w0003;
			} while (gp14_n->w0003 < gp14_n->w0002);
		}
		int16 gp8_n = gp14_n->w0001;
		gp14_n->w0002 = gp8_n;
	} while (gp8_n < 0x10);
}

// 01EE: void main()
void main()
{
	int16 gp3_n;
	for (gp3_n = 0x00; gp3_n <= 0x07; ++gp3_n)
		(&g_tFFFF8000)[gp3_n * 0x03] = (struct Eq_n) *((char *) &g_rFFFF8003 + 3);
	int16 gp3_n;
	for (gp3_n = 0x08; gp3_n <= 0x0F; ++gp3_n)
		(&g_tFFFF8000)[gp3_n * 0x03] = (struct Eq_n) g_rFFFF8009;
	uint16 gp4_n;
	fft(init_fft(out gp4_n), gp4_n);
	struct Eq_n * gp14_n = compute_output();
	Eq_n gp3_n = 0x00;
	do
	{
		real48 gp0_gp1_gp2_n = ((Eq_n[]) 0x8090)[gp3_n].r0000;
		gp14_n[1] = (struct Eq_n) gp3_n;
		gp14_n = pr_fp_num((word32) gp0_gp1_gp2_n);
		Eq_n gp3_n = gp14_n[1];
		gp3_n = (word32) gp3_n + 1;
	} while (gp3_n <= 0x07);
}

// 0226: Register cui16 frex(Register cui16 gp1, Register (ptr16 (ptr16 Eq_n)) gp3)
// Called from:
//      sqrt
cui16 frex(cui16 gp1, struct Eq_n ** gp3)
{
	struct Eq_n * gp5_n = *gp3;
	cui16 gp1_n = gp1 & 0xFF00;
	cu16 gp4_n = gp1 & 0xFF;
	if (Test(NE,(gp1 & 0xFF & 0x0100) == 0x00))
		gp4_n = gp1 & 0xFF | 0xFF00;
	if (Test(NE,(gp4_n & 0x8000) == 0x00))
	{
		++gp4_n;
		gp1_n = gp1 & 0xFF00 | 0xFF;
	}
	gp5_n->w0001 = (gp4_n >> 0x01 & 0xFF) + 0x01 & 0xFF;
	gp5_n->w0002 = 0x00;
	gp5_n->w0000 = 0x4000;
	return gp1_n;
}

// 0245: Sequence real48 sqrt(Sequence int32 gp0_gp1, Register word16 gp2, Register out (ptr16 Eq_n) gp14Out)
// Called from:
//      compute_output
//      asin
real48 sqrt(int32 gp0_gp1, word16 gp2, struct Eq_n & gp14Out)
{
	ptr16 fp;
	real48 rLoc02;
	word16 gp0 = SLICE(gp0_gp1, word16, 16);
	cui16 gp1 = (word16) gp0_gp1;
	word16 gp2_n;
	word16 gp1_n;
	word16 gp0_n;
	if (gp0_gp1 >= 0x00)
	{
		word16 gp1_n = frex(gp1, (struct Eq_n **) 0x01);
		real48 gp2_gp3_gp4_n = g_rFFFF8012 - g_rFFFF800F / (SEQ(gp0, gp1_n, gp2) + g_tFFFF800C.t0000);
		real48 gp2_gp3_gp4_n = (gp2_gp3_gp4_n + SEQ(gp0, gp1_n, gp2) / gp2_gp3_gp4_n) *48 *((char *) (&g_rFFFF8012) + 3);
		real48 gp2_gp3_gp4_n = (gp2_gp3_gp4_n + SEQ(gp0, gp1_n, gp2) / gp2_gp3_gp4_n) *48 *((char *) (&g_rFFFF8012) + 3);
		real48 gp0_gp1_gp2_n = SEQ((word32) gp2_gp3_gp4_n, (word16) gp2_gp3_gp4_n) * rLoc02;
		gp0_n = SLICE(gp0_gp1_gp2_n, word16, 32);
		gp1_n = SLICE(gp0_gp1_gp2_n, word16, 16);
		gp2_n = (word16) gp0_gp1_gp2_n;
	}
	else
	{
		real48 gp0_gp1_gp2_n = g_rFFFF8018;
		gp0_n = SLICE(gp0_gp1_gp2_n, word16, 32);
		gp1_n = SLICE(gp0_gp1_gp2_n, word16, 16);
		gp2_n = (word16) gp0_gp1_gp2_n;
	}
	gp14Out = fp - 0x03;
	return SEQ(gp0_n, gp1_n, gp2_n);
}

// 0273: Sequence word32 auxasin(Sequence Eq_n gp0_gp1_gp2, Register out ptr16 gp2Out, Register out ptr16 gp14Out)
// Called from:
//      asin
word32 auxasin(Eq_n gp0_gp1_gp2, ptr16 & gp2Out, ptr16 & gp14Out)
{
	ptr16 fp;
	real48 gp5_gp6_gp7_n = gp0_gp1_gp2 * gp0_gp1_gp2;
	word16 gp7_n = (word16) gp5_gp6_gp7_n;
	real48 gp0_gp1_gp2_n = gp0_gp1_gp2 * ((SEQ((word32) gp5_gp6_gp7_n, gp7_n) *48 g_tFFFF801B.t0000) / ((SEQ((word32) gp5_gp6_gp7_n, gp7_n) + g_rFFFF801E) + g_rFFFF8024 / (gp5_gp6_gp7_n + *((char *) (&g_rFFFF801E) + 3))) + *((char *) (&g_rFFFF8024) + 3));
	gp2Out = (word16) gp0_gp1_gp2_n;
	gp14Out = fp - 0x03;
	return SLICE(gp0_gp1_gp2_n, word32, 16);
}

// 0294: void asin(Sequence int32 gp0_gp1, Register uint16 gp2)
void asin(int32 gp0_gp1, uint16 gp2)
{
	real48 gp8_gp9_gp10_n = g_rFFFF802A;
	word16 gp10_n = (word16) gp8_gp9_gp10_n;
	real48 gp2_gp3_gp4_n = SEQ(gp0_gp1, gp2);
	if (gp0_gp1 < 0x00)
		gp2_gp3_gp4_n = SEQ((word32) gp8_gp9_gp10_n, gp10_n) - SEQ(gp0_gp1, gp2);
	if (gp2_gp3_gp4_n <= *((char *) (&g_rFFFF802A) + 3))
	{
		Eq_n gp5_gp6_gp7_n = SEQ(gp0_gp1, gp2);
		if (gp0_gp1 < 0x00)
		{
			real48 gp2_gp3_gp4_n = g_rFFFF802A - SEQ(gp0_gp1, gp2);
			gp5_gp6_gp7_n = SEQ((word32) gp2_gp3_gp4_n, (word16) gp2_gp3_gp4_n);
		}
		struct Eq_n * gp14_n;
		if (gp5_gp6_gp7_n <= (g_aFFFF8030)[0].r0000)
		{
			word16 gp2_n;
			auxasin(gp5_gp6_gp7_n, out gp2_n, out gp14_n);
		}
		else
		{
			real48 gp2_gp3_gp4_n = *((char *) &g_rFFFF802A + 3) - gp5_gp6_gp7_n;
			real48 gp0_gp1_gp2_n = SEQ((word32) gp2_gp3_gp4_n, (word16) gp2_gp3_gp4_n) * (g_aFFFF8030)[0].r0000;
			word16 gp14_n;
			word16 gp2_n;
			auxasin(sqrt((word32) gp0_gp1_gp2_n, (word16) gp0_gp1_gp2_n, out gp14_n), out gp2_n, out gp14_n);
		}
		gp14_n->w0001 == 0x00;
	}
}

// 02E1: void rsin()
void rsin()
{
}

// 02FA: void rcos()
void rcos()
{
}

// 0311: Register word16 sincos(Register ci16 gp1, Register word16 gp4, Register out ptr16 gp1Out, Register out ptr16 gp2Out, Register out ptr16 gp3Out, Register out ptr16 gp4Out, Register out ptr16 gp14Out)
// Called from:
//      sin
//      cos
word16 sincos(ci16 gp1, word16 gp4, ptr16 & gp1Out, ptr16 & gp2Out, ptr16 & gp3Out, ptr16 & gp4Out, ptr16 & gp14Out)
{
	ptr16 fp;
	ci16 gp2_n = gp1;
	if (gp1 < 0x00)
		gp2_n = gp1 + 0x07;
	struct Eq_n * gp2_n = gp2_n & ~0x07;
	if ((uint32) (gp1 - gp2_n) > 0x07)
	{
		real48 gp3_gp4_gp5_n = g_rFFFF8051;
		gp1Out = (word16) gp3_gp4_gp5_n;
		gp2Out = (word16) gp3_gp4_gp5_n;
		gp3Out = SLICE(gp3_gp4_gp5_n, word16, 32);
		gp4Out = SLICE(gp3_gp4_gp5_n, word16, 16);
		gp14Out = fp;
		return SLICE(gp3_gp4_gp5_n, word16, 16);
	}
	else
	{
		<anonymous> * gp2_n = gp2_n->ptr032C;
		ptr16 gp14_n;
		ptr16 gp4_n;
		ptr16 gp1_n;
		word16 gp0_n;
		ptr16 gp2_n;
		ptr16 gp3_n;
		gp2_n();
		gp1Out = gp1_n;
		gp2Out = gp2_n;
		gp3Out = gp3_n;
		gp4Out = gp4_n;
		gp14Out = gp14_n;
		return gp0_n;
	}
}

// 037C: Sequence word48 sin(Sequence int32 gp0_gp1, Register word16 gp2, Register out Eq_n gp3Out, Register out Eq_n gp4Out, Register out (ptr16 Eq_n) gp14Out)
// Called from:
//      fft
word48 sin(int32 gp0_gp1, word16 gp2, union Eq_n & gp3Out, union Eq_n & gp4Out, struct Eq_n & gp14Out)
{
	real48 gp5_gp6_gp7_n = SEQ(gp0_gp1, gp2);
	if (gp0_gp1 < 0x00)
	{
		real48 gp2_gp3_gp4_n = *((char *) &g_rFFFF8051 + 3);
		gp5_gp6_gp7_n = SEQ((word32) gp2_gp3_gp4_n, (word16) gp2_gp3_gp4_n) - SEQ(gp0_gp1, gp2);
	}
	real48 gp5_gp6_gp7_n = gp5_gp6_gp7_n * g_rFFFF8057;
	int32 gp0_gp1_n = (int32) gp5_gp6_gp7_n;
	real48 gp5_gp6_gp7_n = gp5_gp6_gp7_n - (real48) gp0_gp1_n;
	word16 gp7_n = (word16) gp5_gp6_gp7_n;
	word16 gp4_n = gp7_n;
	if (gp5_gp6_gp7_n < 0.0)
	{
		gp4_n = (word16) (SEQ((word32) gp5_gp6_gp7_n, gp7_n) + *((char *) (&g_rFFFF8057) + 3));
		gp0_gp1_n += g_dwFFFF805D;
	}
	ci16 gp1_n = (word16) gp0_gp1_n;
	if (gp0_gp1 < 0x00)
		gp1_n = *((char *) &g_dwFFFF805D + 2) + (word16) gp0_gp1_n /16 0x00008090;
	word16 gp1_n;
	struct Eq_n * gp14_n;
	word16 gp2_n;
	Eq_n gp3_n;
	Eq_n gp4_n;
	word16 gp0_n = sincos(gp1_n, gp4_n, out gp1_n, out gp2_n, out gp3_n, out gp4_n, out gp14_n);
	gp3Out = gp3_n;
	gp4Out = gp4_n;
	gp14Out = gp14_n;
	return SEQ(gp0_n, gp1_n, gp2_n);
}

// 03A0: Sequence word48 cos(Sequence int32 gp0_gp1, Register word16 gp2, Register out ptr16 gp14Out)
// Called from:
//      fft
word48 cos(int32 gp0_gp1, word16 gp2, ptr16 & gp14Out)
{
	real48 gp5_gp6_gp7_n = SEQ(gp0_gp1, gp2);
	if (gp0_gp1 < 0x00)
	{
		real48 gp2_gp3_gp4_n = g_rFFFF8061 - SEQ(gp0_gp1, gp2);
		gp5_gp6_gp7_n = SEQ((word32) gp2_gp3_gp4_n, (word16) gp2_gp3_gp4_n);
	}
	real48 gp5_gp6_gp7_n = gp5_gp6_gp7_n * g_rFFFF8064;
	int32 gp0_gp1_n = (int32) gp5_gp6_gp7_n;
	real48 gp5_gp6_gp7_n = gp5_gp6_gp7_n - (real48) gp0_gp1_n;
	word16 gp7_n = (word16) gp5_gp6_gp7_n;
	word16 gp4_n = gp7_n;
	if (gp5_gp6_gp7_n < 0.0)
	{
		gp4_n = (word16) (SEQ((word32) gp5_gp6_gp7_n, gp7_n) + *((char *) (&g_rFFFF8064) + 3));
		gp0_gp1_n += g_dwFFFF806A;
	}
	word16 gp1_n;
	ptr16 gp14_n;
	word16 gp2_n;
	word16 gp3_n;
	word16 gp4_n;
	word16 gp0_n = sincos((word16) gp0_gp1_n + g_wFFFF806C, gp4_n, out gp1_n, out gp2_n, out gp3_n, out gp4_n, out gp14_n);
	gp14Out = gp14_n;
	return SEQ(gp0_n, gp1_n, gp2_n);
}

// 03BF: Register (ptr16 Eq_n) cvia(Register (ptr16 Eq_n) gp0, Register (ptr16 Eq_n) gp1)
// Called from:
//      pr_dec_word
struct Eq_n * cvia(struct Eq_n * gp0, struct Eq_n * gp1)
{
	gp0->w0000 = 0x2020;
	gp0[1] = (struct Eq_n) 0x2020;
	gp0[2] = (struct Eq_n) 0x2020;
	gp0[3] = (struct Eq_n) 0x00;
	struct Eq_n * gp11_n = gp0;
	cui16 gp13_n = 0x00;
	word16 gp10_n = 0x20;
	struct Eq_n * gp1_n = gp1;
	if (gp1 < null)
	{
		gp10_n = 0x2D;
		gp1_n = -gp1;
	}
	cui16 gp9_n = 0x00;
	do
	{
		++gp9_n;
		struct Eq_n * gp1_n = gp1_n / 0x0A;
		gp13_n |= 0x30;
		if ((gp9_n & 0x8000) != 0x00)
			gp11_n[2] = (struct Eq_n) SEQ(gp11_n[2], (byte) gp13_n);
		else
		{
			gp11_n[2] = (struct Eq_n) SEQ((byte) gp13_n, gp11_n[2]);
			--gp11_n;
		}
		gp1_n = gp1_n;
	} while (gp1_n != null);
	if ((gp9_n & 0x8000) != 0x00)
		gp11_n[2] = (struct Eq_n) SEQ((byte) gp10_n, gp11_n[2]);
	else
		gp11_n[2] = (struct Eq_n) SEQ(gp11_n[2], (byte) gp10_n);
	return gp1;
}

// 03ED: Register (ptr16 Eq_n) cvla(Sequence int32 gp12_gp13, Register (ptr16 Eq_n) gp0, Register (ptr16 Eq_n) gp1, Register uint16 gp2)
// Called from:
//      pr_long_word
struct Eq_n * cvla(int32 gp12_gp13, struct Eq_n * gp0, struct Eq_n * gp1, uint16 gp2)
{
	struct Eq_n * gp11_n = gp0;
	cui16 gp9_n;
	for (gp9_n = 0x06; gp9_n != 0x00; --gp9_n)
	{
		gp11_n->w0000 = 0x2020;
		++gp11_n;
	}
	gp11_n->wFFFFFFFF = SEQ(gp11_n[1], (byte) gp9_n);
	byte * gp11_n = gp11_n - 0x01;
	word16 gp10_n = 0x20;
	struct Eq_n * gp1_n = gp1;
	if (gp1 < null)
	{
		gp10_n = 0x2D;
		if (gp1 == &g_tFFFF8000 && gp2 == 0x00)
			++gp2;
		word32 gp1_gp2_n = -gp2;
		gp1_n = SLICE(gp1_gp2_n, word16, 16);
		gp2 = (word16) gp1_gp2_n;
	}
	int32 gp12_gp13_n = gp12_gp13;
	do
	{
		ui32 gp2_gp3_n = gp2 /32 0x0A * 0x0A;
		++gp9_n;
		gp2 = SLICE(gp2_gp3_n, word16, 16);
		uint16 gp5_n = gp2 - (word16) gp2_gp3_n;
		if ((gp9_n & 0x8000) != 0x00)
		{
			*gp11_n = (byte) SEQ((byte) gp5_n + 0x30, *gp11_n);
			--gp11_n;
		}
		else
			*gp11_n = (byte) SEQ(*gp11_n, (byte) gp5_n + 0x30);
		gp12_gp13_n = gp12_gp13_n / 0x0A;
		gp12_gp13_n = gp12_gp13_n;
	} while (gp12_gp13_n / 0x0A != 0x00);
	if (Test(EQ,(gp9_n + 0x01 & 0x8000) == 0x00))
		*gp11_n = (byte) SEQ(*gp11_n, (byte) gp10_n);
	else
		*gp11_n = (byte) SEQ((byte) gp10_n, *gp11_n);
	return gp1;
}

// 0426: Register (ptr16 Eq_n) cvfa(Sequence word32 gp1_gp2, Register (ptr16 Eq_n) gp0, Register out ptr16 gp14Out)
// Called from:
//      pr_fp_num
struct Eq_n * cvfa(word32 gp1_gp2, struct Eq_n * gp0, ptr16 & gp14Out)
{
	struct Eq_n * gp1 = SLICE(gp1_gp2, word16, 16);
	gp0[7] = (struct Eq_n) 0x00;
	gp14Out = fn043E(SEQ(gp1_gp2, 0x00), 0x00, 0x06, gp0);
	return gp1;
}

// 0432: Register (ptr16 Eq_n) cvea(Sequence word32 gp1_gp2, Register (ptr16 Eq_n) gp0, Register word16 gp3)
// Called from:
//      pr_efp_num
struct Eq_n * cvea(word32 gp1_gp2, struct Eq_n * gp0, word16 gp3)
{
	struct Eq_n * gp1 = SLICE(gp1_gp2, word16, 16);
	gp0[0x0A] = (struct Eq_n) 0x00;
	fn043E(SEQ(gp1_gp2, gp3), 0x00, 11, gp0);
	return gp1;
}

// 043E: Register cui16 fn043E(Sequence Eq_n gp12_gp13_gp14, Register cui16 gp0, Register word16 gp1, Register (ptr16 Eq_n) gp11)
// Called from:
//      cvfa
//      cvea
cui16 fn043E(Eq_n gp12_gp13_gp14, cui16 gp0, word16 gp1, struct Eq_n * gp11)
{
	cui16 gp12 = SLICE(gp12_gp13_gp14, word16, 32);
	cui16 gp13 = SLICE(gp12_gp13_gp14, word16, 16);
	cui16 gp14 = (word16) gp12_gp13_gp14;
	word16 gp0_n;
	if ((gp12 & 0x01) != 0x00)
	{
		if ((gp12 & 0x02) != 0x00)
		{
			gp0_n = 0x2D20;
			gp12_gp13_gp14 *= g_r057F;
			goto l0458;
		}
	}
	else if ((gp0 | gp12 | gp13 | gp14) == 0x00 || (gp12 & 0x02) != 0x00)
	{
		gp0_n = 0x2B20;
l0458:
		word16 gp14_n;
		word16 gp0_n;
		gp11->t0000.u1 = gp0_n;
		int16 gp2_n = 0x00;
		gp12_gp13_n = gp12_gp13_gp14;
		Eq_n gp12_gp13_n = gp12_gp13_gp14;
		if (Test(EQ,(SLICE(gp12_gp13_gp14, word16, 16) & 0x0100) == 0x00))
		{
			while (true)
			{
				gp14_n = (word16) gp12_gp13_n;
				if (gp12_gp13_n < g_t0579.u1)
					break;
				gp12_gp13_n /= g_t0579.u1;
				++gp2_n;
			}
			gp0_n = 17707;
		}
		else
		{
			while (true)
			{
				gp14_n = (word16) gp12_gp13_n;
				if (gp12_gp13_n >= g_t057C.u1)
					break;
				gp12_gp13_n *= g_t0579.u1;
				++gp2_n;
			}
			gp0_n = 17709;
		}
		if (gp1 != 0x06)
			gp11[8] = (struct Eq_n) gp0_n;
		else
			gp11[5] = (struct Eq_n) gp0_n;
		int16 gp2_n = gp2_n / 0x0A;
		Eq_n gp2_n = __xbr(gp2_n) | gp2_n % 0x0A;
		if (gp1 != 0x06)
			gp11[9] = (struct Eq_n) (gp2_n | 0x3030);
		else
			gp11[6] = (struct Eq_n) (gp2_n | 0x3030);
		int32 gp2_gp3_n = (int32) SEQ(gp12_gp13_n, gp14_n);
		gp11->t0000.u1 = SEQ(gp11->t0000.u0, (byte) gp2_gp3_n + 0x30);
		gp11[1] = (struct Eq_n) SEQ(0x2E, gp11[1]);
		cui16 gp7_n = 0x00;
		real48 gp12_gp13_gp14_n = SEQ(gp12_gp13_n, gp14_n) - (real48) gp2_gp3_n;
		do
		{
			real48 gp12_gp13_gp14_n = gp12_gp13_gp14_n * g_t0579.u1;
			int32 gp2_gp3_n = (int32) SEQ((word32) gp12_gp13_gp14_n, (word16) gp12_gp13_gp14_n);
			gp12_gp13_gp14_n = gp12_gp13_gp14_n - (real48) gp2_gp3_n;
			word16 gp3_n = (word16) gp2_gp3_n;
			gp14 = (word16) gp12_gp13_gp14_n;
			++gp7_n;
			if ((gp7_n & 0x8000) != 0x00)
				gp11[1] = (struct Eq_n) SEQ((byte) gp3_n + 0x30, gp11[1]);
			else
			{
				gp11[1] = (struct Eq_n) SEQ(gp11[1], (byte) gp3_n + 0x30);
				++gp11;
			}
			--gp1;
		} while (gp1 != 0x00);
		gp11[1] = (struct Eq_n) 0x2020;
		return gp14;
	}
	__mov(gp11, 1410);
	return gp14;
}

// 04AC: void putchar(Register cui16 gp0)
// Called from:
//      puts
//      pr_nibble
void putchar(cui16 gp0)
{
	__console_output(gp0);
}

// 04AF: void puts(Register (ptr16 byte) gp0)
// Called from:
//      pr_dec_word
//      pr_long_word
//      pr_fp_num
//      pr_efp_num
void puts(byte * gp0)
{
	byte * gp11_n = gp0;
	cui16 gp0_n = 0x00;
	while (true)
	{
		cui16 gp0_n = SEQ(*gp11_n, (byte) gp0_n);
		if (gp0_n == 0x00)
			break;
		putchar(gp0_n);
		gp0_n = SEQ(*gp11_n, *gp11_n);
		if (gp0_n == 0x00)
			return;
		putchar(gp0_n);
		++gp11_n;
	}
}

// 04C0: void pr_nibble(Register Eq_n gp0)
// Called from:
//      pr_hex_byte
void pr_nibble(Eq_n gp0)
{
	cui16 gp0_n;
	if ((gp0 & 0x0F) < 0x09)
		gp0_n = (gp0 & 0x0F) + 0x30;
	else
		gp0_n = (gp0 & 0x0F) + 55;
	putchar(gp0_n);
}

// 04CE: Register Eq_n pr_hex_byte(Register Eq_n gp0)
// Called from:
//      pr_hex_word
Eq_n pr_hex_byte(Eq_n gp0)
{
	pr_nibble(gp0 >> 0x04);
	pr_nibble(gp0);
	return gp0;
}

// 04D8: void pr_hex_word(Register int16 gp0)
void pr_hex_word(int16 gp0)
{
	pr_hex_byte(pr_hex_byte(__xbr(gp0)));
}

// 04E2: void pr_dec_word(Register (ptr16 Eq_n) gp0)
void pr_dec_word(struct Eq_n * gp0)
{
	puts(cvia(&g_tFFFF806E, gp0));
}

// 04EC: void pr_long_word(Sequence word32 gp0_gp1, Sequence int32 gp12_gp13)
void pr_long_word(word32 gp0_gp1, int32 gp12_gp13)
{
	uint16 gp1 = (word16) gp0_gp1;
	struct Eq_n * gp0 = SLICE(gp0_gp1, word16, 16);
	puts(cvla(gp12_gp13, &g_tFFFF806E, gp0, gp1));
}

// 04F6: Register word16 pr_fp_num(Sequence word32 gp0_gp1)
// Called from:
//      main
word16 pr_fp_num(word32 gp0_gp1)
{
	word16 gp14_n;
	puts(cvfa(gp0_gp1, &g_tFFFF806E, out gp14_n));
	return gp14_n;
}

// 0500: void pr_efp_num(Sequence word32 gp0_gp1, Register word16 gp2)
void pr_efp_num(word32 gp0_gp1, word16 gp2)
{
	puts(cvea(gp0_gp1, &g_tFFFF806E, gp2));
}

Eq_n g_t0579 = // 0579
	{
		10.0F
	};
Eq_n g_t057C = // 057C
	{
		1.0F
	};
real48 g_r057F = -1.0; // 057F
