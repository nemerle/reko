// hello_m68k_CRTSTART.c
// Generated by decompiling hello_m68k.exe
// using Reko decompiler version 0.11.5.0.

#include "hello_m68k.h"

// 000021F0: void fn000021F0(Register (ptr32 Eq_n) a5)
void fn000021F0(struct Eq_n * a5)
{
	struct Eq_n * d0_n = a5->ptrFFFFFAA0->ptr001C;
	struct Eq_n * a1_n = d0_n;
	if (d0_n != null)
	{
		int32 d1_n;
		for (d1_n = 0; d1_n < 3; ++d1_n)
		{
			word32 d0_n = *a1_n->ptr0004;
			if (d0_n != 0x45434F4E)
			{
				if (d0_n == 0x46535953)
				{
					a5->aFFFFF958[d1_n] |= 0x01;
					struct Eq_n * a0_n = (struct Eq_n *) *a1_n->ptr0008;
					a5->aFFFFF998[d1_n] = SEQ(SLICE(a0_n, word16, 16), a0_n->w0002);
				}
			}
			else
			{
				a5->aFFFFF958[d1_n] |= 0x41;
				a5->aFFFFF998[d1_n] = a1_n;
			}
			++a1_n;
		}
	}
}

// 00002264: void fn00002264(Stack (ptr32 byte) dwArg04)
void fn00002264(byte * dwArg04)
{
	if (dwArg04 != null)
	{
		byte v13_n = *dwArg04;
		if (v13_n != 0x00)
		{
			byte * a2_n = dwArg04;
			uint32 d0_n;
			byte * a1_n = dwArg04 + 1;
			for (d0_n = (uint32) v13_n; d0_n != 0x00; --d0_n)
			{
				*a2_n = *a1_n;
				++a1_n;
				++a2_n;
			}
			*a2_n = 0x00;
		}
	}
}

// 00002294: void fn00002294(Register (ptr32 Eq_n) a5)
void fn00002294(struct Eq_n * a5)
{
	fn00002354(a5, 0, 0x00);
}

// 000022C4: void fn000022C4(Register word32 a2, Register ptr32 a5)
void fn000022C4(word32 a2, ptr32 a5)
{
	struct Eq_n * a7_n;
	fn000023B4(a5 + -744, a5 + -740);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->t0004.u0 = (word32 *) (a5 + -748);
	a7_n->t0000.u0 = (word32 *) (a5 + -752);
	struct Eq_n * a6_n = fn000023B4(a7_n->t0000.u0, a7_n->t0004.u0);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->w0002 = ~0x5760;
	a7_n->b0001 = 0x01;
	(*((word32) a5 + 0x00C2))();
	word32 v10_n = a7_n->dw0000;
	a7_n->wFFFFFFFE = 0xA1AD;
	0x00 = 0x00;
	ptr32 a5_n;
	(*((word32) a5_n + 0x00C2))();
	word32 a2_n;
	word32 * a7_n;
	if (a2_n != *a7_n)
	{
		__syscall<word16>(0xA1AD);
		struct Eq_n * a6_n;
		word32 a0_n;
		a6_n->dwFFFFFFFC = a0_n;
		if (false)
		{
			struct Eq_n * a5_n;
			a5_n->dwFFFFF948 = a6_n->dwFFFFFFFC;
		}
	}
}

// 00002354: Register word32 fn00002354(Register (ptr32 Eq_n) a5, Stack int32 dwArg08, Stack byte bArg0F)
// Called from:
//      fn00002294
word32 fn00002354(struct Eq_n * a5, int32 dwArg08, byte bArg0F)
{
	ptr32 fp;
	a5->bFFFFFA9C = bArg0F;
	ptr32 a7_n = fp - 0x04;
	if (dwArg08 == 0x00)
	{
		if (a5->tFFFFFD3C.u0 != 0x00)
		{
			fn000023B4(a5->tFFFFFD3C.u0, a5->tFFFFFD38.u0);
			struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
			a7_n = &a7_n->t0008.u0;
		}
		struct Eq_n * a7_n = a7_n - 4;
		a7_n->t0000.u0 = (word32 *) ((char *) &a5->ptrFFFFFAA0 + 0x0288);
		a7_n->tFFFFFFFC.u0 = (word32 *) ((char *) &a5->ptrFFFFFAA0 + 640);
		fn000023B4(a7_n->tFFFFFFFC.u0, a7_n->t0000.u0);
		struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
		a7_n = &a7_n->t0008.u0;
	}
	struct Eq_n * a7_n = a7_n - 4;
	a7_n->t0000.u0 = (word32 *) ((char *) &a5->ptrFFFFFAA0 + 656);
	a7_n->tFFFFFFFC.u0 = (word32 *) ((char *) &a5->ptrFFFFFAA0 + 652);
	struct Eq_n * a6_n = fn000023B4(a7_n->tFFFFFFFC.u0, a7_n->t0000.u0);
	if (a6_n->dw0010 == 0x00)
	{
		if (a5->ptrFFFFFAA0 != null)
			a5->ptrFFFFFAA0->dw000E = a6_n->dw0008;
		(*((char *) &a5->tFFFFFD3C + 806))();
	}
	return a6_n->dw0000;
}

// 000023B4: Register word32 fn000023B4(Stack Eq_n dwArg04, Stack Eq_n dwArg08)
// Called from:
//      fn000022C4
//      fn00002354
word32 fn000023B4(Eq_n dwArg04, Eq_n dwArg08)
{
	ptr32 fp;
	word32 * a6_n = fp - 0x04;
	<anonymous> * d5_n = (<anonymous> *) -1;
	Eq_n d4_n = dwArg08;
	Eq_n d3_n = dwArg04;
	if (dwArg08 > dwArg04)
	{
		do
		{
			<anonymous> * d0_n = *d3_n.u0;
			if (d0_n != null && d0_n != d5_n)
				d0_n();
			d3_n.u0 = (word32) d3_n + 4;
		} while (d4_n > d3_n);
	}
	return *a6_n;
}

// 000023F8: void fn000023F8(Register (ptr32 Eq_n) a5)
void fn000023F8(struct Eq_n * a5)
{
	word32 a6_n;
	struct Eq_n * a6_n;
	struct Eq_n * a5_n = fn00002418(a5, out a6_n);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->tFFFFFFFC.u0 = a6_n->t0008.u0;
	struct Eq_n * a5_n = fn0000243C(a5_n, a7_n->tFFFFFFFC.u0, out a6_n);
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	a7_n->t0000.u0 = 0xFF;
	a5_n->ptrFFFFFAF8();
}

// 00002418: Register (ptr32 Eq_n) fn00002418(Register (ptr32 Eq_n) a5, Register out ptr32 a6Out)
// Called from:
//      fn000023F8
struct Eq_n * fn00002418(struct Eq_n * a5, ptr32 & a6Out)
{
	ptr32 * a6_n;
	word32 a6_n;
	struct Eq_n * a7_n = (struct Eq_n *) <invalid>;
	struct Eq_n * a5_n = fn0000243C(a5, 252, out a6_n);
	word32 a7_n = &a7_n->t0004.u0;
	<anonymous> * a0_n = a5_n->ptrFFFFFC0C;
	if (a0_n != null)
		a0_n();
	union Eq_n * a7_n = a7_n - 4;
	a7_n->u0 = (word32 *) 0xFF;
	struct Eq_n * a5_n = fn0000243C(a5_n, a7_n->u0, out a6_n);
	a6Out = *a6_n;
	return a5_n;
}

// 0000243C: Register (ptr32 Eq_n) fn0000243C(Register (ptr32 Eq_n) a5, Stack Eq_n dwArg04, Register out ptr32 a6Out)
// Called from:
//      fn000023F8
//      fn00002418
struct Eq_n * fn0000243C(struct Eq_n * a5, Eq_n dwArg04, ptr32 & a6Out)
{
	ptr32 fp;
	ptr32 * a6_n = fp - 0x04;
	int32 d1_n = 0;
	struct Eq_n * d2_n = (struct Eq_n *) a5->aFFFFFBB4;
	while (dwArg04 != d2_n->dw0000)
	{
		++d2_n;
		++d1_n;
		if (d2_n >= &a5->ptrFFFFFC0C)
			break;
	}
	if (dwArg04 == (((a5->aFFFFFBB4))[d1_n].t0000).u0)
	{
		byte * a0_n = a5->aFFFFFBB4[d1_n].ptr0004;
		byte * a1_n = a0_n;
		byte * a1_n;
		do
		{
			a1_n = a1_n + 1;
			a1_n = a1_n;
		} while (*a1_n != 0x00);
		word32 a1_n = a1_n - (a0_n + 1);
		(*((char *) &a5->ptrFFFFFC0C + 1158))();
	}
	a6Out = *a6_n;
	return a5;
}

