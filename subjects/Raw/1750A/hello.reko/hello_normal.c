// hello_normal.c
// Generated by decompiling hello.hex
// using Reko decompiler version 0.11.6.0.

#include "hello.h"

// 0100: void hello()
void hello()
{
	puts(&g_t0111);
}

// 0105: void puts(Register (ptr16 Eq_n) gp0)
// Called from:
//      hello
void puts(struct Eq_n * gp0)
{
	struct Eq_n * gp1_n = gp0;
	while (true)
	{
		word16 gp0_n = gp1_n->w0000;
		if (gp0_n == 0x00)
			break;
		putchar(gp0_n);
		++gp1_n;
	}
}

// 010E: void putchar(Register word16 gp0)
// Called from:
//      puts
void putchar(word16 gp0)
{
	__console_output(gp0);
}

Eq_n g_t0111 = // 0111
	{
		0x48,
	};
