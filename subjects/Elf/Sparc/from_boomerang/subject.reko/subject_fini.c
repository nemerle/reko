// subject_fini.c
// Generated by decompiling subject.exe
// using Reko decompiler version 0.11.5.0.

#include "subject.h"

// 00010CB8: void _fini(Register word32 o0, Register word32 o1, Register word32 o2, Register word32 o3, Register word32 o4, Register word32 o5, Register (ptr32 Eq_n) o7)
void _fini(word32 o0, word32 o1, word32 o2, word32 o3, word32 o4, word32 o5, struct Eq_n * o7)
{
	ptr32 fp;
	fn00010CC8(o7, o0, o1, o2, o3, o4, o5, fp, o7);
}

// 00010CC8: void fn00010CC8(Register (ptr32 Eq_n) o7, Register word32 i0, Register word32 i1, Register word32 i2, Register word32 i3, Register word32 i4, Register word32 i5, Register ptr32 i6, Register (ptr32 Eq_n) i7)
// Called from:
//      _fini
void fn00010CC8(struct Eq_n * o7, word32 i0, word32 i1, word32 i2, word32 i3, word32 i4, word32 i5, ptr32 i6, struct Eq_n * i7)
{
	<anonymous> * l0_n = (<anonymous> *) *((char *) (o7 + o7->dw0008 / 0x0C) - 4);
	if (l0_n == null)
		return;
	l0_n();
}

