// retpoline_stripped_text.c
// Generated by decompiling retpoline_stripped.elf
// using Reko decompiler version 0.11.1.0.

#include "retpoline_stripped.h"

// 0000000000400480: void fn0000000000400480(Register (ptr64 Eq_n) rdx, Stack word32 dwArg00, Stack (ptr64 char) ptrArg08)
void fn0000000000400480(void (* rdx)(), word32 dwArg00, char * ptrArg08)
{
	void * fp;
	word64 qwArg00;
	__align_stack<word64>(&ptrArg08);
	__libc_start_main(&g_t400660, (int32) qwArg00, &ptrArg08, &g_t400710, &g_t400780, rdx, fp);
	__halt();
}

// 00000000004004B0: void fn00000000004004B0()
void fn00000000004004B0()
{
	if (true || true)
		return;
	null();
}

// 0000000000400560: void fn0000000000400560(Register word32 esi, Register word32 edi)
void fn0000000000400560(word32 esi, word32 edi)
{
	calloc((int64) edi, (int64) esi);
}

Eq_n g_t400660 = ??/* Unexpected function type (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char)))) */ ; // 0000000000400660
// 00000000004006F0: void fn00000000004006F0()
void fn00000000004006F0()
{
	fn0000000000400700();
	while (true)
		__pause();
}

// 0000000000400700: void fn0000000000400700()
// Called from:
//      fn00000000004006F0
void fn0000000000400700()
{
}

Eq_n g_t400710 = ??/* Unexpected function type (fn void ()) */ ; // 0000000000400710
Eq_n g_t400780 = ??/* Unexpected function type (fn void ()) */ ; // 0000000000400780
