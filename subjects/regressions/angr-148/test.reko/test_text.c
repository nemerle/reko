// test_text.c
// Generated by decompiling test
// using Reko decompiler version 0.10.2.0.

#include "test.h"

// 0000000000400440: void _start(Register (ptr64 Eq_n) rdx, Stack word32 dwArg00)
void _start(void (* rdx)(), word32 dwArg00)
{
	__align_stack<word64>((char *) fp + 8);
	__libc_start_main(&g_t40053D, (int32) qwArg00, (char *) fp + 8, &g_t400550, &g_t4005C0, rdx, fp);
	__hlt();
}

// 0000000000400470: void deregister_tm_clones()
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 00000000004004A0: void register_tm_clones()
// Called from:
//      frame_dummy
void register_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 00000000004004E0: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (g_b601040 == 0x00)
	{
		deregister_tm_clones();
		g_b601040 = 0x01;
	}
}

// 0000000000400500: void frame_dummy()
void frame_dummy()
{
	if (g_qw600E20 == 0x00 || true)
		register_tm_clones();
	else
	{
		fn0000000000000000();
		register_tm_clones();
	}
}

// 000000000040052D: Register int32 f()
// Called from:
//      main
int32 f()
{
	return putchar(0x0078);
}

// 000000000040053D: void main()
void main()
{
	f();
}

// 0000000000400550: void __libc_csu_init(Register word64 rdx, Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rdx, word64 rsi, word32 edi)
{
	word32 edi = (word32) rdi;
	_init();
	int64 rbp_n = 0x00600E18 - 0x00600E10;
	Eq_n rbx_n = 0x00;
	if (rbp_n >> 0x03 != 0x00)
	{
		do
		{
			(*((char *) g_a600E10 + rbx_n * 0x08))();
			rbx_n = (word64) rbx_n.u1 + 1;
		} while (rbx_n != rbp_n >> 0x03);
	}
}

// 00000000004005C0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

