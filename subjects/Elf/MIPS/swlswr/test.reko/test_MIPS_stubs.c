// test_MIPS_stubs.c
// Generated by decompiling test
// using Reko decompiler version 0.11.6.0.

#include "test.h"

// 000009D0: void __libc_start_main(Register (ptr32 Eq_n) r28, Register word32 ra)
void __libc_start_main(struct Eq_n * r28, word32 ra)
{
	r28->ptrFFFF8010();
}

// 000009E0: void memset(Register (ptr32 Eq_n) r28, Register word32 ra)
void memset(struct Eq_n * r28, word32 ra)
{
	r28->ptrFFFF8010();
}

// 000009F0: void calloc(Register (ptr32 Eq_n) r28, Register word32 ra)
void calloc(struct Eq_n * r28, word32 ra)
{
	r28->ptrFFFF8010();
	_fini();
}

