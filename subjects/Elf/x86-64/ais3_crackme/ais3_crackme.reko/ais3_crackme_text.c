// ais3_crackme_text.c
// Generated by decompiling ais3_crackme
// using Reko decompiler version 0.10.2.0.

#include "ais3_crackme.h"

// 0000000000400410: void _start(Register (ptr64 Eq_n) rdx, Stack word32 dwArg00)
void _start(void (* rdx)(), word32 dwArg00)
{
	__align_stack<word64>((char *) fp + 8);
	__libc_start_main(&g_t4005C5, (int32) qwArg00, (char *) fp + 8, &g_t400620, &g_t4006B0, rdx, fp);
	__hlt();
}

// 000000000040043C: void call_gmon_start()
// Called from:
//      _init
void call_gmon_start()
{
	if (__gmon_start__ != 0x00)
		__gmon_start__();
}

// 0000000000400460: void deregister_tm_clones()
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 0000000000400490: void register_tm_clones()
// Called from:
//      frame_dummy
void register_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 00000000004004D0: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (g_b601038 == 0x00)
	{
		deregister_tm_clones();
		g_b601038 = 0x01;
	}
}

// 00000000004004F0: void frame_dummy()
void frame_dummy()
{
	if (g_qw600E08 == 0x00 || true)
		register_tm_clones();
	else
	{
		fn0000000000000000();
		register_tm_clones();
	}
}

// 0000000000400520: Register word32 verify(Register (arr byte) rdi)
// Called from:
//      main
word32 verify(byte rdi[])
{
	word32 dwLoc0C_n = 0x00;
	while (true)
	{
		uint64 rax_n;
		if (rdi[(int64) dwLoc0C_n] == 0x00)
			break;
		ui8 al_n = (byte) dwLoc0C_n ^ rdi[(int64) dwLoc0C_n];
		if (g_a601020[(int64) dwLoc0C_n] != ((byte) ((word32) al_n >> 0x08 - (((byte) dwLoc0C_n ^ 0x09) & 0x03)) | al_n << (((byte) dwLoc0C_n ^ 0x09) & 0x03)) + 0x08)
		{
			rax_n = 0x00;
			return (word32) rax_n;
		}
		++dwLoc0C_n;
	}
	rax_n = (uint64) (dwLoc0C_n == 0x17);
	return (word32) rax_n;
}

// 00000000004005C5: void main(Register (ptr64 Eq_n) rsi, Register word32 edi)
void main(struct Eq_n * rsi, word32 edi)
{
	if (edi != 0x02)
		puts("You need to enter the secret key!");
	else if (verify(rsi->ptr0008) != 0x00)
		puts("Correct! that is the secret key!");
	else
		puts("I'm sorry, that's the wrong secret key!");
}

// 0000000000400620: void __libc_csu_init(Register word64 rdx, Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rdx, word64 rsi, word32 edi)
{
	word32 edi = (word32) rdi;
	_init();
	int64 rbp_n = 0x00600E00 - 0x00600DF8;
	if (rbp_n >> 0x03 != 0x00)
	{
		Eq_n rbx_n = 0x00;
		do
		{
			(*((char *) g_a600DF8 + rbx_n * 0x08))();
			rbx_n = (word64) rbx_n.u1 + 1;
		} while (rbx_n != rbp_n >> 0x03);
	}
}

// 00000000004006B0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

