// hello_m68k_CRTHEAP.c
// Generated by decompiling hello_m68k.exe
// using Reko decompiler version 0.11.6.0.

#include "hello_m68k.h"

// 000024B0: void fn000024B0(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04)
void fn000024B0(struct Eq_n * a5, Eq_n dwArg04)
{
	fn000024C4(a5, dwArg04);
}

// 000024C4: Register word32 fn000024C4(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04)
// Called from:
//      fn000024B0
word32 fn000024C4(struct Eq_n * a5, Eq_n dwArg04)
{
	ptr32 fp;
	ptr32 a7_n = fp - 0x0C;
	if (dwArg04 > -32)
	{
		word32 a6;
		return a6;
	}
	Eq_n d3_n = SEQ(SLICE((word32) dwArg04.u1 + 3, word16, 16), (word16) dwArg04 + 0x03 & ~0x03);
	struct Eq_n * a7_n;
	struct Eq_n * a5_n;
	word32 * a6_n;
	do
	{
		union Eq_n * a7_n = a7_n - 4;
		a7_n->u0 = (word32 *) d3_n;
		a7_n = (struct Eq_n *) <invalid>;
		word32 d4_n;
		if (fn00002510(a5, a7_n->u0, out d3_n, out d4_n, out a5_n, out a6_n) != 0x00 || d4_n == 0x00)
			return *a6_n;
		a7_n->t0000.u0 = (word32 *) d3_n;
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		a7_n = &a7_n->t0004.u0;
	} while (fn00002644(a5_n, a7_n->t0000.u0, out a5, out a6_n) != 0x00);
	return *a6_n;
}

// 00002510: Register int32 fn00002510(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Register out Eq_n d3Out, Register out ptr32 d4Out, Register out (ptr32 Eq_n) a5Out, Register out (ptr32 word32) a6Out)
// Called from:
//      fn000024C4
int32 fn00002510(struct Eq_n * a5, Eq_n dwArg04, union Eq_n & d3Out, ptr32 & d4Out, struct Eq_n & a5Out, word32 & a6Out)
{
	word32 a0_n;
	ptr32 fp;
	Eq_n a0_n;
	struct Eq_n * d0_n = fn000027B0(a5, dwArg04, out a0_n);
	word32 ** a6_n = fp - 0x04;
	Eq_n d3_n = dwArg04;
	struct Eq_n * a7_n = fp - 0x0C;
	struct Eq_n * a2_n = d0_n;
	ptr32 d4;
	if (d0_n == null)
	{
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		if (fn000028A0(a0_n, d0_n, a5, dwArg04, out d3_n, out d4, out a5, out a6_n) == -1)
		{
			word32 * a6_n = *a6_n;
			d3Out.u0 = a7_n->t0008.u0;
			d4Out = d4;
			a5Out = a5;
			a6Out = a6_n;
			return 0;
		}
		a7_n->t0000.u0 = (word32 *) d3_n;
		struct Eq_n * d0_n = fn000027B0(a5, a7_n->t0000.u0, out a0_n);
		a7_n = (struct Eq_n *) &a7_n->t0004.u0;
		a2_n = d0_n;
		if (d0_n == null)
		{
			a5 = fn000027A0(a5, a6_n, out a6_n);
			a7_n = (struct Eq_n *) <invalid>;
		}
	}
	Eq_n d0_n;
	d0_n.u2 = a2_n->t0000.u1->t0004.u2;
	uipr32 d1_n = a2_n->dw0004;
	if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - d3_n != 4)
	{
		struct Eq_n * a7_n = a7_n - 4;
		a7_n->t0000.u0 = (word32 *) d3_n;
		a7_n->ptrFFFFFFFC = a2_n;
		struct Eq_n * d0_n = fn000025B4(a5, a7_n->ptrFFFFFFFC, a7_n->t0000.u0);
		if (d0_n != null)
		{
			Eq_n d0_n;
			__bclr<word32>(d0_n->t0004.u2, 0x01, out d0_n);
			Eq_n d0_n;
			__bset<word16>(d0_n, 0x00, out d0_n);
			d0_n->t0004.u2 = (struct Eq_n *) d0_n;
		}
	}
	uipr32 d0_n = a2_n->dw0004;
	a2_n->dw0004 = SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03);
	a5->tFFFFFACC.u1 = a2_n->t0000.u1;
	uipr32 d0_n = a2_n->dw0004;
	word32 * a6_n = *a6_n;
	d3Out.u0 = a7_n->t0004.u0;
	d4Out = d4;
	a5Out = a5;
	a6Out = a6_n;
	return SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) + 0x04;
}

// 000025B4: Register Eq_n fn000025B4(Register (ptr32 Eq_n) a5, Stack (ptr32 Eq_n) dwArg04, Stack Eq_n dwArg08)
// Called from:
//      fn00002510
Eq_n fn000025B4(struct Eq_n * a5, struct Eq_n * dwArg04, Eq_n dwArg08)
{
	word32 a0_n;
	Eq_n a0_n;
	a0_n.u1 = dwArg04->t0000.u1;
	Eq_n d0_n;
	d0_n.u2 = a0_n.u1->t0004.u2;
	uipr32 d1_n = dwArg04->dw0004;
	if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - 0x04 <= dwArg08)
		return 0;
	Eq_n d0_n = fn0000273C(a0_n, a5, out a0_n);
	if (d0_n == 0x00)
		return 0;
	uipr32 d0_n = dwArg04->dw0004;
	struct Eq_n * d0_n = (struct Eq_n *) ((char *) dwArg08.u0 + SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03));
	d0_n.u1->t0004.u2 = (struct Eq_n *) &d0_n->t0004.u0;
	d0_n->t0004.u1 = (struct Eq_n *) d0_n;
	d0_n.u1->dw0000 = dwArg04->t0000.u1;
	dwArg04->t0000.u1 = (struct Eq_n *) d0_n;
	return d0_n;
}

// 00002610: void fn00002610(Register (ptr32 Eq_n) a5, Stack word32 dwArg04)
void fn00002610(struct Eq_n * a5, word32 dwArg04)
{
	a5->dwFFFFFD34 = dwArg04;
}

// 00002644: Register int32 fn00002644(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Register out (ptr32 Eq_n) a5Out, Register out (ptr32 word32) a6Out)
// Called from:
//      fn000024C4
int32 fn00002644(struct Eq_n * a5, Eq_n dwArg04, struct Eq_n & a5Out, word32 & a6Out)
{
	ptr32 fp;
	word32 ** a6_n = fp - 0x04;
	<anonymous> * a0_n = a5->ptrFFFFFD34;
	if (a0_n != null)
	{
		a0_n();
		word32 d0_n;
		if (d0_n != 0x00)
		{
			word32 * a6_n = *a6_n;
			a5Out = a5;
			a6Out = a6_n;
			return 1;
		}
	}
	word32 * a6_n = *a6_n;
	a5Out = a5;
	a6Out = a6_n;
	return 0;
}

// 0000273C: Register Eq_n fn0000273C(Register Eq_n a0, Register (ptr32 Eq_n) a5, Register out Eq_n a0Out)
// Called from:
//      fn000025B4
//      fn00002BB4
Eq_n fn0000273C(Eq_n a0, struct Eq_n * a5, union Eq_n & a0Out)
{
	Eq_n d0_n;
	Eq_n a0_n;
	if (a5->tFFFFFAD0.u1 == 0x00)
	{
		d0_n = fn0000275C(a0, a5, out a0_n);
		if (d0_n == 0x00)
		{
l00002758:
			a0Out = a0_n;
			return d0_n;
		}
	}
	d0_n.u1 = a5->tFFFFFAD0.u1;
	a5->tFFFFFAD0.u1 = d0_n.u1->dw0000;
	a0_n = d0_n;
	goto l00002758;
}

// 0000275C: Register int32 fn0000275C(Register Eq_n a0, Register (ptr32 Eq_n) a5, Register out Eq_n a0Out)
// Called from:
//      fn0000273C
int32 fn0000275C(Eq_n a0, struct Eq_n * a5, union Eq_n & a0Out)
{
	__syscall<word16>(0xA11E);
	if (a0 != 0x00)
	{
		a5->tFFFFFAD0.u1 = (struct Eq_n *) a0;
		Eq_n d0_n = a0;
		Eq_n d1_n;
		d1_n.u1 = (word32) a0 + 8;
		if (true)
		{
			Eq_n d1_n;
			do
			{
				d0_n.u1->dw0000 = (word32) d1_n;
				d0_n = d1_n;
				d1_n.u1 = (word32) d1_n + 8;
				d1_n = d1_n;
			} while (&a0.u1->dw0FF8 > d1_n);
		}
		a0.u1->dw0FF8 = 0;
		a0Out.u1 = &a0.u1->dw0FF8;
		return 1;
	}
	else
	{
		a0Out = a0;
		return 0;
	}
}

// 000027A0: Register (ptr32 Eq_n) fn000027A0(Register (ptr32 Eq_n) a5, Register (ptr32 (ptr32 word32)) a6, Register out (ptr32 Eq_n) a6Out)
// Called from:
//      fn00002510
//      fn00002A54
//      fn00002B18
//      fn00002BB4
struct Eq_n * fn000027A0(struct Eq_n * a5, word32 ** a6, struct Eq_n & a6Out)
{
	(*((char *) &a5->dwFFFFFAF4 + 0x0566))();
	struct Eq_n ** a6_n;
	a6Out = (struct Eq_n *) *a6_n;
	struct Eq_n * a5_n;
	return a5_n;
}

// 000027B0: Register Eq_n fn000027B0(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Register out Eq_n a0Out)
// Called from:
//      fn00002510
Eq_n fn000027B0(struct Eq_n * a5, Eq_n dwArg04, union Eq_n & a0Out)
{
	Eq_n a2_n;
	a2_n.u1 = a5->tFFFFFACC.u1;
	Eq_n a1_n;
	a1_n.u0 = 0x00;
	Eq_n a0;
	if ((char *) &a5->tFFFFFAD0 + 4 != a2_n)
	{
		do
		{
			ui32 * a4_n = (ui32 *) &a2_n.u1->t0004.u0;
			if ((*a4_n & 3) == 0x01)
			{
				while (true)
				{
					a0.u1 = a2_n.u1->dw0000;
					Eq_n d0_n;
					d0_n.u2 = a0.u1->t0004.u2;
					ui32 d3_n = *a4_n;
					if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - SEQ(SLICE(d3_n, word16, 16), (word16) d3_n & ~0x03) - 0x04 >= dwArg04)
						break;
					if ((d0_n & 3) != 0x01)
						goto l0000280C;
					a2_n.u1->dw0000 = a0.u1->dw0000;
					a0.u1->dw0000 = a5->tFFFFFAD0.u1;
					a5->tFFFFFAD0.u1 = (struct Eq_n *) a0;
				}
l00002880:
				a1_n = a2_n;
				goto l00002882;
			}
l0000280C:
			a2_n.u1 = a2_n.u1->dw0000;
		} while (a2_n != (char *) (&a5->tFFFFFAD0) + 4);
	}
	a2_n.u1 = a5->tFFFFFAC8.u1;
	if (a2_n == (a5->tFFFFFACC).u1)
	{
l00002882:
		a0Out = a0;
		return a1_n;
	}
	else
	{
		do
		{
			ui32 * a3_n = (ui32 *) &a2_n.u1->t0004.u0;
			if ((*a3_n & 3) == 0x01)
			{
				do
				{
					a0.u1 = a2_n.u1->dw0000;
					Eq_n d3_n;
					d3_n.u2 = a0.u1->t0004.u2;
					ui32 d1_n = *a3_n;
					if (SEQ(SLICE(d3_n, word16, 16), (word16) d3_n & ~0x03) - SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - 0x04 >= dwArg04)
						goto l00002880;
					if ((d3_n & 3) != 0x01)
						goto l0000288C;
					a2_n.u1->dw0000 = a0.u1->dw0000;
					a0.u1->dw0000 = a5->tFFFFFAD0.u1;
					a5->tFFFFFAD0.u1 = (struct Eq_n *) a0;
				} while (a0 != (a5->tFFFFFACC).u1);
				a5->tFFFFFACC.u1 = (struct Eq_n *) a2_n;
				a0.u1 = a2_n.u1->dw0000;
				Eq_n d0_n;
				d0_n.u2 = a0.u1->t0004.u2;
				ui32 d1_n = *a3_n;
				if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - 0x04 >= dwArg04)
					goto l00002880;
				goto l00002882;
			}
l0000288C:
			a2_n.u1 = a2_n.u1->dw0000;
		} while (a2_n != (a5->tFFFFFACC).u1);
		a0Out = a0;
		return 0x00;
	}
}

// 000028A0: Register int32 fn000028A0(Register Eq_n a0, Register (ptr32 Eq_n) a2, Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Register out Eq_n d3Out, Register out Eq_n d4Out, Register out (ptr32 Eq_n) a5Out, Register out ptr32 a6Out)
// Called from:
//      fn00002510
int32 fn000028A0(Eq_n a0, struct Eq_n * a2, struct Eq_n * a5, Eq_n dwArg04, union Eq_n & d3Out, union Eq_n & d4Out, struct Eq_n & a5Out, ptr32 & a6Out)
{
	ptr32 * a6_n;
	struct Eq_n * a5_n;
	ptr32 fp;
	int32 d4_n = a5->dwFFFFFAF4;
	ptr32 * a6_n = fp - 0x04;
	struct Eq_n * a7_n = fp - 0x1C;
	uipr32 a2_n = SEQ(SLICE(a2, word16, 16), 0x10);
	int32 d5_n = -1;
	up32 d3_n = SEQ(SLICE((word32) dwArg04 + 7, word16, 16), (word16) dwArg04 + 0x07 & ~0x03);
	if (d4_n < a5->dwFFFFFAE0)
	{
		int32 d7_n = d4_n << 0x04;
		do
		{
			if (*((char *) &a5->tFFFFFADC.u1->a0000[0].u1->a0000[0].u1 + d7_n) != 0x00)
			{
				struct Eq_n * a7_n = a7_n - 4;
				a7_n->dw0000 = d3_n;
				a7_n->dwFFFFFFFC = d4_n;
				struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
				a7_n = (struct Eq_n *) &a7_n->t0008.u0;
				if (fn00002A54(a5, a7_n->dwFFFFFFFC, a7_n->dw0000, out d3_n, out d4_n, out d5_n, out a2_n, out a5, out a6_n) != -1)
				{
					a5->dwFFFFFAF4 = d4_n;
					Eq_n d4_n;
					d4_n.u2 = a7_n->t000C.u2;
					ptr32 a6_n = *a6_n;
					d3Out.u0 = a7_n->t0008.u0;
					d4Out = d4_n;
					a5Out = a5;
					a6Out = a6_n;
					return 0;
				}
			}
			a0.u1 = a5->tFFFFFADC.u1->a0000[0].u1;
			if (*((word128) a0 + d7_n) == 0x00)
			{
				d5_n = d4_n;
				break;
			}
			++d4_n;
			d7_n += a2_n;
		} while (d4_n < a5->dwFFFFFAE0);
	}
	if (d5_n != -1)
	{
l000029B4:
		struct Eq_n * a7_n = a7_n - 4;
		a7_n->dw0000 = d3_n;
		a7_n->dwFFFFFFFC = d5_n;
		int32 d0_n = fn000029C8(a0, a5, a7_n->dwFFFFFFFC, a7_n->dw0000, out a5_n, out a6_n);
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		Eq_n d4_n;
		d4_n.u2 = a7_n->t000C.u2;
		ptr32 a6_n = *a6_n;
		d3Out.u0 = a7_n->t0008.u0;
		d4Out = d4_n;
		a5Out = a5_n;
		a6Out = a6_n;
		return d0_n;
	}
	if (a5->tFFFFFADC.u1 != 0x00)
	{
		a0.u1 = a5->tFFFFFADC.u1;
		__syscall<word16>(0xA024);
	}
	if (a5->tFFFFFADC.u1 != 0x00)
	{
		a0.u1 = a5->tFFFFFAF0.u1;
		if (*a0 == 0x00)
			goto l00002974;
	}
	__syscall<word16>(0xA122);
	if (a0 == 0x00)
	{
		Eq_n d4_n;
		d4_n.u2 = a7_n->t0004.u2;
		ptr32 a6_n = *a6_n;
		d3Out.u0 = a7_n->t0000.u0;
		d4Out = d4_n;
		a5Out = a5;
		a6Out = a6_n;
		return -1;
	}
	__syscall<word16>(41001);
	if (a5->tFFFFFADC.u1 != 0x00)
	{
		__syscall<word16>(0xA02E);
		__syscall<word16>(0xA023);
	}
	a5->tFFFFFADC.u1 = (struct Eq_n *) a0;
l00002974:
	a0.u1 = a5->tFFFFFADC.u1->a0000[0].u1 + a5->dwFFFFFAE0 * 4;
	int32 d0_n = 7;
	word16 v30_n;
	do
	{
		a0->u1 = 0;
		struct Eq_n * a0_n = (struct Eq_n *) (a0.u1 + 1);
		a0_n->dw0000 = 0;
		a0_n->dw0004 = 0;
		a0_n->dw0008 = 0;
		a0_n->dw000C = 0;
		a0_n->dw0010 = 0;
		a0_n->dw0014 = 0;
		a0_n->dw0018 = 0;
		a0_n->dw001C = 0;
		a0_n->dw0020 = 0;
		a0_n->dw0024 = 0;
		a0_n->dw0028 = 0;
		a0_n->dw002C = 0;
		a0_n->dw0030 = 0;
		a0_n->dw0034 = 0;
		a0_n->dw0038 = 0;
		v30_n = (word16) d0_n;
		a0.u1 = &a0_n->dw0038 + 1;
		d0_n = SEQ(SLICE(d0_n, word16, 16), v30_n - 1);
	} while (v30_n != 0x00);
	d5_n = a5->dwFFFFFAE0;
	a5->dwFFFFFAE0 += 32;
	goto l000029B4;
}

// 000029C8: Register int32 fn000029C8(Register Eq_n a0, Register (ptr32 Eq_n) a5, Stack int32 dwArg04, Stack up32 dwArg08, Register out (ptr32 Eq_n) a5Out, Register out ptr32 a6Out)
// Called from:
//      fn000028A0
int32 fn000029C8(Eq_n a0, struct Eq_n * a5, int32 dwArg04, up32 dwArg08, struct Eq_n & a5Out, ptr32 & a6Out)
{
	ptr32 fp;
	word32 d4_n = a5->dwFFFFFAEC;
	up32 d4_n = SEQ(SLICE(d4_n + 0x0FFF, word16, 16), (word16) d4_n + 0x0FFF & 0xF000);
	ptr32 * a6_n = fp - 0x04;
	if (d4_n < dwArg08)
		d4_n = dwArg08;
	__syscall<word16>(0xA11E);
	int32 d0_n;
	if (a0 != 0x00)
	{
		Eq_n a1_n;
		a1_n.u1 = a5->tFFFFFADC.u1->a0000[0].u1;
		if (((word16) a0 & 0x03) != 0x00)
			*((word128) a1_n + dwArg04 * 0x10) = SEQ(SLICE((word128) a0 + 3, word16, 16), (word16) a0 + 0x03 & ~0x03);
		else
			*((word128) a1_n + dwArg04 * 0x10) = a0;
		struct Eq_n * a1_n = (struct Eq_n *) (a1_n.u1 + dwArg04 * 4);
		a1_n->t000C.u1 = (struct Eq_n *) a0;
		a1_n->dw0008 = d4_n;
		a1_n->dw0004 = 0;
		word32 d3_n;
		word32 d4_n;
		Eq_n d5_n;
		word32 a2_n;
		d0_n = fn00002A54(a5, dwArg04, dwArg08, out d3_n, out d4_n, out d5_n, out a2_n, out a5, out a6_n);
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		if (d0_n == 0x00)
		{
l00002A4C:
			ptr32 a6_n = *a6_n;
			a5Out = a5;
			a6Out = a6_n;
			return d0_n;
		}
		a7_n->t0004.u0 = (word32 *) d5_n;
		fn00002AE0(a5, a7_n->t0004.u0);
	}
	d0_n = -1;
	goto l00002A4C;
}

// 00002A54: Register int32 fn00002A54(Register (ptr32 Eq_n) a5, Stack int32 dwArg04, Stack up32 dwArg08, Register out Eq_n d3Out, Register out Eq_n d4Out, Register out Eq_n d5Out, Register out ptr32 a2Out, Register out (ptr32 Eq_n) a5Out, Register out (ptr32 word32) a6Out)
// Called from:
//      fn000028A0
//      fn000029C8
int32 fn00002A54(struct Eq_n * a5, int32 dwArg04, up32 dwArg08, union Eq_n & d3Out, union Eq_n & d4Out, union Eq_n & d5Out, ptr32 & a2Out, struct Eq_n & a5Out, word32 & a6Out)
{
	struct Eq_n * a2_n = (struct Eq_n *) (a5->tFFFFFADC.u1->a0000[0].u1 + dwArg04 * 4);
	uipr32 d4_n = a2_n->dw0008;
	word32 d1_n = a2_n->dw0004;
	Eq_n d0_n = d4_n - d1_n;
	Eq_n d3_n = SEQ(SLICE(dwArg08 + 0x03, word16, 16), (word16) dwArg08 + 0x03 & ~0x03);
	Eq_n a1_n = a2_n->dw0000 + d1_n;
	if (d3_n > d0_n)
	{
		__syscall<word16>(0xA020);
		word32 d4_n = (word32) d3_n.u1 + (d4_n - d0_n);
		uipr32 d4_n = SEQ(SLICE(d4_n + 0x04, word16, 16), (word16) d4_n + 0x04 & ~0x03);
		a2_n = (struct Eq_n *) (a5->tFFFFFADC.u1->a0000[0].u1 + dwArg04 * 4);
		if (a5->tFFFFFAF0.u1->a0000[0].u0 != 0x00)
		{
			Eq_n d3;
			d3Out = d3;
			Eq_n d4;
			d4Out = d4;
			Eq_n d5;
			d5Out = d5;
			ptr32 a2;
			a2Out = a2;
			a5Out = a5;
			word32 * a6;
			a6Out = a6;
			return -1;
		}
		a2_n->dw0008 = d4_n;
		a1_n = a2_n->dw0000 + a2_n->dw0004;
	}
	a2_n->dw0004 = (word32) d3_n.u1 + a2_n->dw0004;
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	struct Eq_n * a7_n = (struct Eq_n *) &a7_n->t0008.u0;
	struct Eq_n * a5_n;
	word32 ** a6_n;
	if (fn00002BB4(a5, a1_n, d3_n, out a5_n, out a6_n) != 0x00)
	{
		a5_n = fn000027A0(a5_n, a6_n, out a6_n);
		a7_n = (struct Eq_n *) <invalid>;
	}
	struct Eq_n * a7_n = (struct Eq_n *) &a7_n->t0004.u0;
	Eq_n d4_n;
	d4_n.u0 = a7_n->t0000.u0;
	Eq_n d5_n;
	d5_n.u0 = a7_n->t0004.u0;
	ptr32 a2_n = a7_n->ptr0008;
	word32 * a6_n = *a6_n;
	d3Out.u0 = a7_n->t0000.u0;
	d4Out = d4_n;
	d5Out = d5_n;
	a2Out = a2_n;
	a5Out = a5_n;
	a6Out = a6_n;
	return 0;
}

// 00002AE0: void fn00002AE0(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04)
// Called from:
//      fn000029C8
void fn00002AE0(struct Eq_n * a5, Eq_n dwArg04)
{
	if (a5->tFFFFFADC.u1->a0000[0].u1[dwArg04 * 4] != 0x00)
		__syscall<word16>(0xA01F);
	Eq_n a0_n;
	a0_n.u1 = a5->tFFFFFADC.u1->a0000[0].u1;
	((word128) a0_n + dwArg04 * 0x10)->u0 = 0;
	((word128) a0_n + (dwArg04 * 0x10 + 4))->u1 = 0;
	((word128) a0_n + (dwArg04 * 0x10 + 8))->u1 = 0;
}

// 00002B18: void fn00002B18(Register (ptr32 Eq_n) a5, Stack (ptr32 Eq_n) dwArg04)
void fn00002B18(struct Eq_n * a5, struct Eq_n * dwArg04)
{
	if (dwArg04 != null)
	{
		Eq_n a2_n;
		a2_n.u1 = dwArg04->tFFFFFFFC.u1;
		Eq_n d1_n;
		d1_n.u2 = a2_n.u1->t0004.u2;
		if (SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) != dwArg04 - 0x04)
		{
			ptr32 fp;
			word32 a6_n;
			a5 = fn000027A0(a5, fp - 0x04, out a6_n);
		}
		Eq_n d0_n;
		__bclr<word32>(a2_n.u1->t0004.u2, 0x01, out d0_n);
		Eq_n d0_n;
		__bset<word16>(d0_n, 0x00, out d0_n);
		a2_n.u1->t0004.u2 = (struct Eq_n *) d0_n;
		if (a5->tFFFFFAE4.u0 != -1 && d0_n < (((a5->tFFFFFACC).u1)->t0004).u2)
		{
			word32 d1_n = *((word32) a2_n.u1->dw0000 + 4);
			if (SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - 0x04 >= (a5->tFFFFFAE4).u0)
				a5->tFFFFFACC.u1 = (struct Eq_n *) a2_n;
		}
	}
}

// 00002BB4: Register int32 fn00002BB4(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Stack Eq_n dwArg08, Register out (ptr32 Eq_n) a5Out, Register out ptr32 a6Out)
// Called from:
//      fn00002A54
int32 fn00002BB4(struct Eq_n * a5, Eq_n dwArg04, Eq_n dwArg08, struct Eq_n & a5Out, ptr32 & a6Out)
{
	Eq_n tLoc08;
	ptr32 fp;
	Eq_n tLoc1C = (Eq_n) (fp + ~0x17);
	struct Eq_n * a6_n = fp - 0x04;
	Eq_n a0_n;
	Eq_n a0_n;
	word32 a0_n;
	if (fn0000273C(fp + ~0x17, a5, out a0_n) != 0x00 && (fn0000273C(a0_n, a5, out a0_n) != 0x00 && fn0000273C(a0_n, a5, out a0_n) != 0x00))
	{
		Eq_n d0_n = fn00002EA8(a5, dwArg04, &tLoc08);
		Eq_n a3_n;
		if (d0_n == 0x00)
		{
			Eq_n a0_n;
			a0_n.u1 = tLoc08.u1;
			if ((a0_n.u1->t0004.u2 & 3) != 2)
				goto l00002DE8;
			a3_n = a0_n;
		}
		else
		{
			a3_n.u1 = *tLoc1C;
			tLoc1C = (Eq_n) ((word32) tLoc1C + 4);
		}
		a3_n.u1->t0004.u2 = (struct Eq_n *) dwArg04;
		Eq_n d1_n;
		__bclr<word32>(dwArg04, 0x01, out d1_n);
		Eq_n d1_n;
		__bset<word16>(d1_n, 0x00, out d1_n);
		a3_n.u1->t0004.u2 = (struct Eq_n *) d1_n;
		dwArg04.u2->t0000.u1 = (struct Eq_n *) a3_n;
		struct Eq_n * a7_n;
		if (d0_n <= 0x00)
		{
			switch ((word32) d0_n.u1)
			{
			case ~0x02:
				Mem356[a5 + -0x0528:word32] = dwArg04 + dwArg08;
				fn00002E18(a3_n, dwArg08, (char *) &a5->tFFFFFAD0 + 4, &tLoc1C);
				a5->tFFFFFACC.u1 = (struct Eq_n *) a3_n;
				a5->tFFFFFAC8.u1 = (struct Eq_n *) a3_n;
				break;
			case ~0x01:
				struct Eq_n * a7_n = fp - 0x24;
				if (fn00002EA8(a5, a5->ptrFFFFFAD8 - 1, &tLoc08) != 1)
				{
					a5 = fn000027A0(a5, fp - 0x04, out a6_n);
					a7_n = (struct Eq_n *) <invalid>;
				}
				word32 d1_n = a6_n->ptrFFFFFFFC->ptr0000->dw0004;
				word32 d0_n = a6_n->ptrFFFFFFFC->dw0004;
				a5->ptrFFFFFAD8 = &dwArg04.u2->t0000.u0 + a6_n->dw000C;
				a3_n.u1->dw0000 = (char *) &a5->tFFFFFAD0 + 4;
				struct Eq_n * a7_n = a7_n - 4;
				a7_n->ptr0000 = (char *) a6_n - 24;
				a7_n->tFFFFFFFC.u1 = (struct Eq_n *) a3_n;
				a7_n->dwFFFFFFF8 = SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03);
				a7_n->ptrFFFFFFF4 = a6_n->ptrFFFFFFFC;
				a7_n = a7_n - 0x0C;
				goto l00002DA4;
			case ~0x00:
				fn00002E18(a3_n, dwArg08, a5->tFFFFFAC8.u1, &tLoc1C);
				a5->tFFFFFAC8.u1 = (struct Eq_n *) a3_n;
				break;
			}
			goto l00002DAC;
		}
		struct Eq_n * a0_n = (struct Eq_n *) tLoc08;
		if ((a0_n->dw0004 & 3) == 2)
		{
			if ((char *) &a5->tFFFFFAD0 + 4 == a0_n->ptr0000)
			{
				Eq_n d0_n;
				d0_n.u2 = a3_n.u1->t0004.u2;
				ptr32 d0_n = (word32) dwArg08.u0 + SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03);
				if (d0_n > a5->ptrFFFFFAD8)
					a5->ptrFFFFFAD8 = d0_n;
			}
			fn00002E18(a3_n, dwArg08, *tLoc08, &tLoc1C);
			a7_n = fp - 0x34;
l00002DA4:
			fn00002E18(a7_n->t0000.u1, a7_n->t0004.u0, a7_n->t0008.u1, a7_n->ptr000C);
l00002DAC:
			Eq_n d0_n;
			d0_n.u2 = a5->tFFFFFACC.u1->t0004.u2;
			if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) > dwArg04)
			{
				word32 d0_n = *((word32) a3_n.u1->dw0000 + 4);
				Eq_n d1_n;
				d1_n.u2 = a3_n.u1->t0004.u2;
				if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) - SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) - 0x04 >= (a5->tFFFFFAE4).u0)
					a5->tFFFFFACC.u1 = (struct Eq_n *) a3_n;
			}
			ptr32 a6_n = a6_n->ptr0000;
			a5Out = a5;
			a6Out = a6_n;
			return 0;
		}
	}
l00002DE8:
	while (*tLoc1C != 0x00)
	{
		**tLoc1C = (Eq_n) a5->tFFFFFAD0.u1;
		a5->tFFFFFAD0.u1 = (struct Eq_n *) *tLoc1C;
		tLoc1C = (Eq_n) ((word32) tLoc1C + 4);
	}
	a5Out = a5;
	ptr32 a6;
	a6Out = a6;
	return -1;
}

// 00002E18: void fn00002E18(Stack Eq_n dwArg04, Stack Eq_n dwArg08, Stack Eq_n dwArg0C, Stack (ptr32 (ptr32 Eq_n)) dwArg10)
// Called from:
//      fn00002BB4
void fn00002E18(Eq_n dwArg04, Eq_n dwArg08, Eq_n dwArg0C, union Eq_n ** dwArg10)
{
	Eq_n d2_n;
	d2_n.u2 = dwArg04.u1->t0004.u2;
	Eq_n a2_n = dwArg04;
	if ((d2_n & 3) != 2)
	{
		Eq_n d1_n;
		d1_n.u2 = dwArg0C.u1->t0004.u2;
		if ((d1_n & 0x03) == 0x02)
		{
			Eq_n d2_n;
			d2_n.u2 = (word32) dwArg08 + SEQ(SLICE(d2_n, word16, 16), (word16) d2_n & ~0x03);
			dwArg0C.u1->t0004.u2 = (struct Eq_n *) d2_n;
			Eq_n d2_n;
			__bclr<word32>(d2_n, 0x00, out d2_n);
			Eq_n d2_n;
			__bset<word16>(d2_n, 0x01, out d2_n);
			dwArg0C.u1->t0004.u2 = (struct Eq_n *) d2_n;
			dwArg04.u1->dw0000 = (word32) dwArg0C;
			return;
		}
		Eq_n d2_n;
		d2_n.u2 = (word32) dwArg08 + SEQ(SLICE(d2_n, word16, 16), (word16) d2_n & ~0x03);
		if (SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) != d2_n)
		{
			union Eq_n * a0_n = (union Eq_n *) *dwArg10;
			Eq_n v33_n;
			v33_n.u1 = a0_n->u1;
			*dwArg10 = (union Eq_n **) ((char *) a0_n + 4);
			v33_n.u1->t0004.u2 = (struct Eq_n *) d2_n;
			Eq_n d2_n;
			__bclr<word32>(d2_n, 0x00, out d2_n);
			Eq_n d2_n;
			__bset<word16>(d2_n, 0x01, out d2_n);
			v33_n.u1->t0004.u2 = (struct Eq_n *) d2_n;
			dwArg04.u1->dw0000 = (word32) v33_n;
			a2_n = v33_n;
		}
	}
	a2_n.u1->dw0000 = (word32) dwArg0C;
}

// 00002EA8: Register int32 fn00002EA8(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Stack (ptr32 Eq_n) dwArg08)
// Called from:
//      fn00002BB4
int32 fn00002EA8(struct Eq_n * a5, Eq_n dwArg04, union Eq_n * dwArg08)
{
	if ((char *) &a5->tFFFFFAD0 + 4 == (a5->tFFFFFAC8).u1)
		return -3;
	Eq_n d0_n;
	d0_n.u2 = a5->tFFFFFAC8.u1->t0004.u2;
	if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) > dwArg04)
		return -1;
	ptr32 d0_n = a5->ptrFFFFFAD8;
	if (SEQ(SLICE(d0_n, word16, 16), (word16) d0_n & ~0x03) <= dwArg04)
		return -2;
	Eq_n a1_n;
	a1_n.u1 = a5->tFFFFFAC8.u1;
	while (true)
	{
		Eq_n a0_n;
		a0_n.u1 = a1_n.u1->dw0000;
		Eq_n d1_n;
		d1_n.u2 = a0_n.u1->t0004.u2;
		if (SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) > dwArg04)
			break;
		a1_n = a0_n;
	}
	dwArg08->u1 = (struct Eq_n *) a1_n;
	Eq_n d1_n;
	d1_n.u2 = a1_n.u1->t0004.u2;
	int32 d0_n = 0;
	if (SEQ(SLICE(d1_n, word16, 16), (word16) d1_n & ~0x03) != dwArg04)
		d0_n = 1;
	return d0_n;
}

