// simd_double_text.c
// Generated by decompiling simd_double
// using Reko decompiler version 0.11.6.0.

#include "simd_double.h"

// 0000000000000620: void _start(Register (ptr64 Eq_n) rdx, Stack word32 dwArg00, Stack (ptr64 char) ptrArg08)
void _start(void (* rdx)(), word32 dwArg00, char * ptrArg08)
{
	__align_stack<word64>(&ptrArg08);
	word64 qwArg00;
	void * fp;
	__libc_start_main(&g_t0898, (int32) qwArg00, &ptrArg08, &g_t0A70, &g_t0AE0, rdx, fp);
	__halt();
}

// 0000000000000650: void deregister_tm_clones()
// Called from:
//      __do_global_dtors_aux
void deregister_tm_clones()
{
	if (&g_b201048 == &g_b201048 || _ITM_deregisterTMCloneTable == null)
		return;
	_ITM_deregisterTMCloneTable();
}

// 0000000000000690: void register_tm_clones()
// Called from:
//      frame_dummy
void register_tm_clones()
{
	int64 rsi_n = &g_b201048 - &g_b201048;
	if ((rsi_n >> 0x03) + ((rsi_n >> 0x03) >>u 0x3F) >> 0x01 == 0x00 || _ITM_registerTMCloneTable == null)
		return;
	_ITM_registerTMCloneTable();
}

// 00000000000006E0: void __do_global_dtors_aux()
void __do_global_dtors_aux()
{
	if (g_b201048 != 0x00)
		return;
	if (__cxa_finalize != 0x00)
		__cxa_finalize(g_qw201040);
	deregister_tm_clones();
	g_b201048 = 0x01;
}

// 0000000000000720: void frame_dummy()
void frame_dummy()
{
	register_tm_clones();
}

// 000000000000072A: Register (ptr64 void) _mm_malloc(Register uint64 rsi, Register Eq_n rdi)
// Called from:
//      main
void * _mm_malloc(uint64 rsi, Eq_n rdi)
{
	uint64 qwLoc28_n = rsi;
	void * rax_n;
	if (rsi == 0x01)
		rax_n = malloc(rdi);
	else
	{
		if (rsi == 0x02 || rsi == 0x04)
			qwLoc28_n = 0x08;
		ptr64 fp;
		if ((word32) posix_memalign(qwLoc28_n, fp - 16, rdi, qwLoc28_n) == 0x00)
		{
			void * qwLoc10;
			rax_n = qwLoc10;
		}
		else
			rax_n = null;
	}
	return rax_n;
}

// 000000000000078D: void _mm_free(Register (ptr64 (arr Eq_n)) rdi)
// Called from:
//      main
void _mm_free(Eq_n (* rdi)[])
{
	free(rdi);
}

// 00000000000007A8: void vec_add(Register (arr Eq_n) rcx, Register (arr Eq_n) rdx, Register (arr Eq_n) rsi, Register word64 rdi)
// Called from:
//      main
void vec_add(Eq_n rcx[], Eq_n rdx[], Eq_n rsi[], word64 rdi)
{
	char ** fp;
	__align_stack<word64>(fp);
	uint64 rax_n = (uint128) rdi /u double_size.21529;
	uint64 qwLoc28_n;
	for (qwLoc28_n = 0x00; qwLoc28_n < rax_n; ++qwLoc28_n)
		(&rsi[qwLoc28_n].u1)[0] = (real64) __simd_fadd<real64[4]>((&rdx[qwLoc28_n].u1)[0], (&rcx[qwLoc28_n].u1)[0]);
}

// 0000000000000898: void main()
void main()
{
	Eq_n (* rax_n)[] = _mm_malloc(0x20, 0x2000);
	Eq_n (* rax_n)[] = _mm_malloc(0x20, 0x2000);
	Eq_n (* rax_n)[] = _mm_malloc(0x20, 0x2000);
	Eq_n qwLoc10_n;
	qwLoc10_n.u0 = 0x00;
	word128 xmm0;
	while (qwLoc10_n < 0x0400)
	{
		real64 * rcx_n = (real64 *) (&rax_n->u0 + qwLoc10_n);
		ui32 eax_n = (word32) qwLoc10_n;
		if (qwLoc10_n >= 0x00)
			xmm0 = SEQ(SLICE(xmm0, word64, 64), (real64) qwLoc10_n);
		else
		{
			real64 v27_n = (real64) (qwLoc10_n >> 0x01 | (uint64) (eax_n & 0x01));
			xmm0 = SEQ(0x00, v27_n + v27_n);
		}
		*rcx_n = (real64) xmm0;
		qwLoc10_n = (word64) qwLoc10_n + 1;
	}
	Eq_n qwLoc18_n;
	qwLoc18_n.u0 = 0x00;
	while (qwLoc18_n < 0x0400)
	{
		ui32 eax_n = (word32) qwLoc18_n + 0x01;
		real64 * rcx_n = (real64 *) (&rax_n->u0 + qwLoc18_n);
		if (qwLoc18_n >= ~0x00)
			xmm0 = SEQ(SLICE(xmm0, word64, 64), (real64) ((word64) qwLoc18_n + 1));
		else
		{
			real64 v22_n = (real64) ((word64) qwLoc18_n + 1 >> 0x01 | (uint64) (eax_n & 0x01));
			xmm0 = SEQ(0x00, v22_n + v22_n);
		}
		*rcx_n = (real64) xmm0;
		qwLoc18_n = (word64) qwLoc18_n + 1;
	}
	uint64 qwLoc20_n;
	for (qwLoc20_n = 0x00; qwLoc20_n < 0x0400; ++qwLoc20_n)
		(&rax_n[0].u0)[qwLoc20_n] = 0.0;
	vec_add(rax_n, rax_n, rax_n, 0x0400);
	uint64 qwLoc28_n;
	for (qwLoc28_n = 0x00; qwLoc28_n < 0x0400; ++qwLoc28_n)
		printf("%g\n", (&rax_n[0].u0)[qwLoc28_n]);
	_mm_free(rax_n);
	_mm_free(rax_n);
	_mm_free(rax_n);
}

// 0000000000000A70: void __libc_csu_init(Register word64 rdx, Register word64 rsi, Register word32 edi)
void __libc_csu_init(word64 rdx, word64 rsi, word32 edi)
{
	word64 rdi;
	edi = (word32) rdi;
	_init();
	int64 rbp_n = 0x00200DF0 - g_a200DE8;
	if (rbp_n >> 0x03 != 0x00)
	{
		Eq_n rbx_n;
		rbx_n.u1 = 0x00;
		do
		{
			(*((char *) g_a200DE8 + rbx_n * 0x08))();
			rbx_n = (word64) rbx_n.u1 + 1;
		} while (rbp_n >> 0x03 != rbx_n);
	}
}

// 0000000000000AE0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

