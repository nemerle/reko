// retpoline_text.c
// Generated by decompiling retpoline.elf
// using Reko decompiler version 0.11.5.0.

#include "retpoline.h"

// 0000000000400480: void _start(Register (ptr64 Eq_n) rdx, Stack word32 dwArg00, Stack (ptr64 char) ptrArg08)
void _start(void (* rdx)(), word32 dwArg00, char * ptrArg08)
{
	__align_stack<word64>(&ptrArg08);
	word64 qwArg00;
	void * fp;
	__libc_start_main(&g_t400660, (int32) qwArg00, &ptrArg08, &g_t400710, &g_t400780, rdx, fp);
	__halt();
}

// 00000000004004B0: void deregister_tm_clones()
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 00000000004004E0: void register_tm_clones()
// Called from:
//      frame_dummy
void register_tm_clones()
{
	if (true || true)
		return;
	null();
}

// 0000000000400520: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (g_b601040 != 0x00)
		return;
	deregister_tm_clones();
	g_b601040 = 0x01;
}

// 0000000000400550: void frame_dummy()
void frame_dummy()
{
	register_tm_clones();
}

// 0000000000400560: Register (ptr64 void) my1(Register int32 esi, Register int32 edi)
// Called from:
//      branches
void * my1(int32 esi, int32 edi)
{
	return calloc((int64) edi, (int64) esi);
}

// 0000000000400590: void my2(Register byte sil, Register (ptr64 byte) rdi)
void my2(byte sil, byte * rdi)
{
	*rdi = sil;
}

// 00000000004005B0: void branches(Register int32 esi, Register int32 edi)
void branches(int32 esi, int32 edi)
{
	word64 rdi;
	edi = (word32) rdi;
	if (edi < esi && (edi << 0x01 < esi << 0x01 && (edi *s 0x03 < esi *s 0x03 && (edi << 0x02 < esi << 0x02 && (int64) edi /32 0x02 < (int64) esi /32 0x02))))
		free(my1(esi, edi));
}

// 0000000000400660: void main()
void main()
{
	__llvm_retpoline_r11();
}

// 00000000004006F0: void __llvm_retpoline_r11()
// Called from:
//      main
void __llvm_retpoline_r11()
{
	fn0000000000400700();
	while (true)
		__pause();
}

// 0000000000400700: void fn0000000000400700()
// Called from:
//      __llvm_retpoline_r11
void fn0000000000400700()
{
}

// 0000000000400710: void __libc_csu_init(Register word64 rdx, Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rdx, word64 rsi, word32 edi)
{
	word64 rdi;
	edi = (word32) rdi;
	_init();
	int64 rbp_n = 0x00600E18 - g_a600E10;
	if (rbp_n >> 0x03 != 0x00)
	{
		Eq_n rbx_n;
		rbx_n.u1 = 0x00;
		do
		{
			(*((char *) g_a600E10 + rbx_n * 0x08))();
			rbx_n = (word64) rbx_n.u1 + 1;
		} while (rbp_n >> 0x03 != rbx_n);
	}
}

// 0000000000400780: void __libc_csu_fini()
void __libc_csu_fini()
{
}

