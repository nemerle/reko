// MachO-OSX-x64-ls_TEXT_text.c
// Generated by decompiling MachO-OSX-x64-ls
// using Reko decompiler version 0.11.2.0.

#include "MachO-OSX-x64-ls.h"

// 0000000100001778: void fn0000000100001778(Stack word32 dwArg04)
void fn0000000100001778(word32 dwArg04)
{
	ptr64 fp;
	word64 qwArg04;
	__align_stack<word64>(fp - 4);
	int32 edi_n = (word32) qwArg04;
	word64 * rcx_n = (uint64) (edi_n + 0x01 << 0x03) + (fp + 0x0C);
	while (*rcx_n != 0x00)
		++rcx_n;
	fn00000001000026A0(fp + 0x0C, edi_n);
}

// 0000000100001B4A: Register word64 fn0000000100001B4A(Register (ptr64 Eq_n) rsi, Register (ptr64 Eq_n) rdi, Register out Eq_n ebxOut, Register out (ptr64 Eq_n) rbpOut)
// Called from:
//      fn00000001000023B0
word64 fn0000000100001B4A(struct Eq_n * rsi, struct Eq_n * rdi, union Eq_n & ebxOut, struct Eq_n & rbpOut)
{
	ptr64 fp;
	struct Eq_n * rbp;
	char bLoc6A;
	char bLoc5D;
	char bLoc50;
	word64 rax_n;
	word64 rax_n = *__stack_chk_guard;
	if (rsi == null)
	{
l0000000100002322:
		rax_n = *__stack_chk_guard;
		if (rax_n == rax_n)
		{
l0000000100002379:
			ebxOut.u0 = <invalid>;
			rbpOut = rbp;
			return rax_n;
		}
		else
			__stack_chk_fail();
	}
	word32 dwLoc011C_n;
	if (g_dw6574 != 0x00 || (g_dw6578 != 0x00 || g_dw6598 != 0x00))
		dwLoc011C_n = 0x01;
	else
		dwLoc011C_n = 0x00;
	uint64 rcx_n;
	Eq_n rax_n = getenv("LS_COLWIDTHS");
	Eq_n qwLocB8_n = 0x00;
	word32 dwLocE4_n = 0x00;
	word32 dwLocE8_n = 0x00;
	word32 dwLocEC_n = 0x00;
	uint64 qwLocD0_n = 0x00;
	uint64 qwLocC8_n = 0x00;
	uint64 qwLocE0_n = 0x00;
	uint64 qwLocC0_n = 0x00;
	if (rax_n == 0x00)
	{
l0000000100001E77:
		struct Eq_n * qwLoc0110_n = rsi;
		word32 dwLoc0120_n = 0x00;
		struct Eq_n * rbx_n;
		Eq_n qwLocF8_n = 0x00;
		for (rbx_n = rsi; rbx_n != null; rbx_n = rbx_n->ptr0010)
		{
			word16 ax_n = rbx_n->w0058;
			if (ax_n != 0x07 && ax_n != 0x0A)
			{
				byte al_n;
				if (rdi == null)
				{
					if (ax_n != 0x01)
						goto l0000000100001F1A;
					al_n = g_b65C0;
					goto l0000000100001EFB;
				}
				if (rbx_n->b0068 == 0x2E)
				{
					al_n = g_b65D1;
l0000000100001EFB:
					if (al_n != 0x00)
						goto l0000000100001F1A;
					rbx_n->qw0018 = 0x01;
				}
				else
				{
l0000000100001F1A:
					uint64 rax_n = (uint64) rbx_n->w0042;
					if (rax_n > qwLocC8_n)
						qwLocC8_n = rax_n;
					if (g_dw6588 != 0x00 || g_dw658C != 0x00)
					{
						uint64 rax_n = fn0000000100004AFA((word32) rbx_n->w0042, &rbx_n->b0068);
						if (rax_n > qwLocC8_n)
							qwLocC8_n = rax_n;
					}
					if (dwLoc011C_n != 0x00)
					{
						struct Eq_n * r14_n = rbx_n->ptr0060;
						uint64 rax_n = r14_n->qw0068;
						if (rax_n > qwLocC0_n)
							qwLocC0_n = rax_n;
						uint64 rax_n = r14_n->qw0008;
						if (rax_n > qwLocE0_n)
							qwLocE0_n = rax_n;
						uint64 rax_n = (uint64) r14_n->w0006;
						if (rax_n > qwLocD0_n)
							qwLocD0_n = rax_n;
						Eq_n rax_n = r14_n->t0060;
						if (rax_n > qwLocB8_n)
							qwLocB8_n = rax_n;
						if (g_dw6578 != 0x00)
						{
							Eq_n qwLoc0100_n;
							Eq_n r15_n;
							if (g_dw6584 != 0x00)
							{
								snprintf("%u", 0x0D, &bLoc6A);
								snprintf("%u", 0x0D, &bLoc5D);
								qwLoc0100_n = &bLoc6A;
								r15_n = &bLoc5D;
							}
							else
							{
								user_from_uid();
								group_from_gid();
								&qwLoc0100_n.u0->b0000 = 0x100006584;
								&r15_n.u0->b0000 = 0x100006584;
							}
							Eq_n rax_n = strlen(qwLoc0100_n);
							word32 eax_n = (word32) rax_n;
							if (rax_n > (uint64) dwLocEC_n)
								dwLocEC_n = eax_n;
							Eq_n rax_n = strlen(r15_n);
							word32 r12d_n = (word32) rax_n;
							if (rax_n > (uint64) dwLocE8_n)
								dwLocE8_n = r12d_n;
							Eq_n rax_n;
							Eq_n rax_n = 0x100006568;
							if (g_t6568 == 0x00)
								rax_n.u1 = 0x00;
							else
							{
								fflagstostr();
								if (0x100006568 != 0x00 && g_t6568 == 0x00)
								{
									free(0x100006568);
									rax_n = strdup("-");
								}
								word56 rax_56_8_n = SLICE(rax_n, word56, 8);
								qwLocF8_n = rax_n;
								if (rax_n == 0x00)
								{
									err();
									rax_n = SEQ(rax_56_8_n, 0x00);
									goto l0000000100002379;
								}
								rax_n = strlen(rax_n);
								word32 eax_n = (word32) rax_n;
								if (rax_n > (int64) dwLocE4_n)
									dwLocE4_n = eax_n;
							}
							Eq_n rax_n = malloc((word64) rax_n.u1 + 36);
							if (rax_n == 0x00)
								goto l0000000100002337;
							*rax_n = (word64) rax_n + 24;
							strcpy(qwLoc0100_n, (word64) rax_n + 24);
							Eq_n rdi_n = (word64) rax_n + ((word64) rax_n + 25);
							*((word64) rax_n + 8) = rdi_n;
							strcpy(r15_n, rdi_n);
							ui32 eax_n = (word32) r14_n->w0004 & 0xF000;
							if (eax_n == 0x2000 || eax_n == 0x6000)
								;
							if (g_t6568 != 0x00)
							{
								*((word64) rax_n + 16) = (word64) rax_n + 26;
								strcpy(qwLocF8_n, (word64) rax_n + 26);
								free(qwLocF8_n);
							}
							rbx_n->t0020 = rax_n;
						}
					}
					++dwLoc0120_n;
				}
			}
			else
			{
				strerror(rbx_n->dw0038);
				warnx();
				rbx_n->qw0018 = 0x01;
				g_b65D0 = 0x01;
			}
		}
		if (dwLoc0120_n != 0x00)
		{
			struct Eq_n * rsi_n = rsi;
			if (dwLoc011C_n != 0x00)
			{
				snprintf("%qu", 0x18, &bLoc50);
				strlen(&bLoc50);
				snprintf("%llu", 0x18, &bLoc50);
				strlen(&bLoc50);
				snprintf("%lu", 0x18, &bLoc50);
				strlen(&bLoc50);
				snprintf("%qu", 0x18, &bLoc50);
				strlen(&bLoc50);
				rsi_n = (struct Eq_n *) 0x18;
			}
			word64 rcx_n;
			word64 rdx_n;
			word64 r8_n;
			word64 r9_n;
			g_ptr65D8();
			g_b65E0 = 0x01;
			if (g_dw6578 != 0x00)
			{
				do
				{
					free(qwLoc0110_n->t0020);
					struct Eq_n * rbx_n = qwLoc0110_n->ptr0010;
					qwLoc0110_n = rbx_n;
				} while (rbx_n != null);
			}
		}
		goto l0000000100002322;
	}
	Eq_n r14b_n = *rax_n;
	if (r14b_n == 0x00)
		goto l0000000100001E77;
	Eq_n rax_n = strlen(rax_n);
	Eq_n rax_n = malloc((word64) rax_n + ((word64) rax_n + 2));
	if (rax_n != 0x00)
	{
		struct Eq_n * rax_n;
		if (r14b_n == 0x3A)
		{
			*rax_n = 0x3A30;
			*((word64) rax_n + 2) = 0x00;
			rax_n = (word64) rax_n + 2;
		}
		else
		{
			*rax_n = r14b_n;
			*((word64) rax_n + 1) = 0x00;
			rax_n = (word64) rax_n + 1;
		}
		byte cl_n = *((word64) rax_n + 1);
		if (cl_n != 0x00)
		{
			struct Eq_n * rbx_n = (word64) rax_n + 2;
			do
			{
				if (rbx_n->bFFFFFFFE == 0x3A && cl_n == 0x3A)
				{
					rax_n->b0000 = 0x30;
					rax_n[1] = (struct Eq_n) rbx_n->bFFFFFFFF;
					rax_n[3] = (struct Eq_n) 0x00;
					rax_n += 2;
				}
				else
				{
					rax_n->b0000 = cl_n;
					rax_n[2] = (struct Eq_n) 0x00;
					++rax_n;
				}
				cl_n = rbx_n->b0000;
				++rbx_n;
			} while (cl_n != 0x00);
		}
		if (rax_n->bFFFFFFFF == 0x3A)
			rax_n->b0000 = (byte) 0x30;
		sscanf();
		g_dw6580 = 0x01;
		up32 eax_n = SEQ(SLICE(fp - 232, word24, 8), 0x00);
		if (eax_n <= 0x08)
		{
			<anonymous> * rax_n = (int64) g_a238C[(uint64) eax_n * 0x04] + 0x10000238C;
			word64 rax_n;
			word64 rdx_n;
			word64 r8_n;
			word64 r9_n;
			rax_n();
			ebxOut.u0 = <invalid>;
			rbpOut = fp - 8;
			return rax_n;
		}
		word64 rax_n = 0x00;
		if (false)
		{
			uint64 rcx_n = 0x01;
			do
			{
				ui64 rcx_n = rcx_n * 0x02;
				--rax_n;
				rcx_n = rcx_n * 0x05;
			} while (rax_n != 0x00);
			rcx_n = rcx_n * 0x05 - 0x01;
l0000000100001DEF:
			uint64 rcx_n;
			qwLocE0_n = rcx_n;
			uint64 rax_n = qwLocC0_n;
			if (qwLocC0_n != 0x00)
			{
				uint64 rcx_n = 0x01;
				do
				{
					ui64 rcx_n = rcx_n * 0x02;
					--rax_n;
					rcx_n = rcx_n * 0x05;
				} while (rax_n != 0x00);
				rcx_n = rcx_n * 0x05 - 0x01;
			}
			else
				rcx_n = 0x00;
			uint64 rcx_n;
			qwLocC0_n = rcx_n;
			uint64 rax_n = qwLocD0_n;
			if (qwLocD0_n != 0x00)
			{
				uint64 rcx_n = 0x01;
				do
				{
					ui64 rcx_n = rcx_n * 0x02;
					--rax_n;
					rcx_n = rcx_n * 0x05;
				} while (rax_n != 0x00);
				rcx_n = rcx_n * 0x05 - 0x01;
			}
			else
				rcx_n = 0x00;
			Eq_n rcx_n;
			qwLocD0_n = rcx_n;
			Eq_n rax_n = qwLocB8_n;
			if (qwLocB8_n != 0x00)
			{
				uint64 rcx_n = 0x01;
				do
				{
					ui64 rcx_n = rcx_n * 0x02;
					--rax_n;
					rcx_n = rcx_n * 0x05;
				} while (rax_n != 0x00);
				rcx_n = rcx_n * 0x05 - 0x01;
			}
			else
				rcx_n.u1 = 0x00;
			qwLocB8_n = rcx_n;
			goto l0000000100001E77;
		}
	}
	else
	{
l0000000100002337:
		err();
	}
	rcx_n = 0x00;
	goto l0000000100001DEF;
}

// 00000001000023B0: void fn00000001000023B0()
// Called from:
//      fn00000001000026A0
void fn00000001000023B0()
{
	fts_open$INODE64();
	if (false)
	{
		fts_children$INODE64();
		word64 rbx_n = <invalid>;
		word32 ebx_n;
		struct Eq_n * rbp_n;
		word56 rax_56_8_n = SLICE(fn0000000100001B4A(null, null, out ebx_n, out rbp_n), word56, 8);
		byte bl_n = (byte) rbx_n;
		ui32 ebx_n = (word32) rbx_n;
		if (g_b65C0 != 0x01)
		{
			byte al_n = g_b65E2;
			struct Eq_n * rax_n = SEQ(rax_56_8_n, al_n);
			if (al_n == 0x00 && (bl_n & 0x08) != 0x00)
				rbp_n->dwFFFFFFD4 = 0x0100;
			else
				rbp_n->dwFFFFFFD4 = 0x00;
			fts_read$INODE64();
			if (rax_n != null)
			{
				ui32 ebx_n = ebx_n & 0x02;
				do
				{
					word64 rax_n;
					rax_n = (uint64) rax_n->w0058;
					int32 eax_n = (word32) rax_n;
					if (eax_n <= 0x0C)
					{
						rax_n = (uint64) (eax_n - 0x01);
						up32 eax_n = (word32) rax_n;
						if (eax_n <= 0x06)
						{
							rax_n = (int64) g_a2684[rax_n * 0x04] + 0x100002684;
							word32 rax_32_32_n = SLICE(rax_n, word32, 32);
							word56 rax_56_8_n = SLICE(rax_n, word56, 8);
							switch (eax_n)
							{
							case 0x00:
								if (rax_n->w0056 != 0x00 && rax_n->b0068 == 0x2E)
								{
									byte al_n = g_b65D1;
									rax_n = SEQ(rax_56_8_n, al_n);
									if (al_n == 0x01)
										goto l000000010000250A;
								}
								else
								{
l000000010000250A:
									byte al_n = g_b65E0;
									struct Eq_n * rax_n = SEQ(SLICE(rax_n, word56, 8), al_n);
									if (al_n == 0x01)
										rax_n = SEQ(rax_32_32_n, printf("\n%s:\n"));
									else if (rbp_n->dwFFFFFFD0 >= 0x02)
									{
										word32 eax_n = printf("%s:\n");
										g_b65E0 = 0x01;
										rax_n = SEQ(rax_32_32_n, eax_n);
									}
									fts_children$INODE64();
									compat_mode();
									if ((byte) 0x100005340 != 0x00 && (ebx_n != 0x00 && rax_n != null))
									{
										struct Eq_n * rax_n = rax_n;
										do
										{
											if (rax_n->w0058 == 0x0D)
												rax_n->qw0018 = 0x01;
											rax_n = rax_n->ptr0010;
										} while (rax_n != null);
									}
									word32 ebx_n;
									rax_n = fn0000000100001B4A(rax_n, rax_n, out ebx_n, out rbp_n);
									word64 rbx_n = <invalid>;
									word56 rax_56_8_n = SLICE(rax_n, word56, 8);
									ebx_n = (word32) rbx_n;
									if (rax_n != null)
									{
										byte al_n = g_b65E2;
										rax_n = SEQ(rax_56_8_n, al_n ^ 0x01);
										if (((al_n ^ 0x01) & 0x01) != 0x00)
											fts_set$INODE64();
									}
								}
								break;
							case 0x01:
								warnx();
								compat_mode();
								rax_n = SEQ(rax_56_8_n, 0x00);
								if (false)
									goto l00000001000024BB;
								break;
							case 0x02:
							case 0x04:
							case 0x05:
								break;
							case 0x03:
							case 0x06:
								rax_n = strerror(rax_n->dw0038);
								goto l00000001000024DF;
							}
						}
					}
					else if (eax_n == 0x0D)
					{
						compat_mode();
						rax_n = (struct Eq_n *) &g_t5340;
						if ((byte) 0x100005340 != 0x00 && ebx_n != 0x00)
						{
							uint64 rdi_n = (uint64) rax_n->dw0038;
							word32 rdi_32_32_n = SLICE(rdi_n, word32, 32);
							if ((word32) rdi_n == 0x00)
								rdi_n = SEQ(rdi_32_32_n, 0x02);
							rax_n = strerror((word32) rdi_n);
l00000001000024DF:
							warnx();
							rax_n = SEQ(SLICE(rax_n, word56, 8), 0x00);
l00000001000024BB:
							g_b65D0 = 0x01;
						}
					}
					fts_read$INODE64();
				} while (rax_n != null);
			}
			__error();
			word32 ebx_n = rax_n->dw0000;
			fts_close$INODE64();
			__error();
			rax_n->dw0000 = ebx_n;
			__error();
			if (rax_n->dw0000 != 0x00)
				err();
			return;
		}
	}
	else
		err();
	fts_close$INODE64();
}

// 00000001000026A0: void fn00000001000026A0(Register (ptr64 (ptr64 char)) rsi, Register int32 edi)
// Called from:
//      fn0000000100001778
void fn00000001000026A0(char ** rsi, int32 edi)
{
	word16 wLoc36;
	if (edi <= 0x00)
		fn000000010000488B();
	word32 ebx_n;
	setlocale("", 0x00);
	if (isatty(0x01) == 0x00)
	{
		Eq_n rax_n = getenv("COLUMNS");
		if (rax_n != 0x00)
			g_dw62B0 = atoi(rax_n);
		ebx_n = 0x01;
l000000010000277D:
		if (getuid() == 0x00)
			g_b65D1 = 0x01;
		word32 eax_n = 0x00;
		word32 dwLoc0658_n = 0x00;
		ui32 r15d_n = 0x00;
		ui32 dwLoc064C_n = 0x00;
		word32 dwLoc0650_n = 0x00;
		while (true)
		{
l0000000100002B5E:
			Eq_n eax_n = getopt("1@ABCFGHLOPRSTUWabcdefghiklmnopqrstuvwx", rsi, edi);
			if (eax_n <= 0x30)
				break;
			if (eax_n > ~0x77)
				goto l0000000100002B56;
			word32 * rax_n;
			word32 * rax_n;
			word32 * rax_n;
			word32 * rax_n;
			word32 * rax_n;
			word32 * rax_n;
			eax_n = 0x01;
			eax_n = eax_n;
			switch ((word32) eax_n)
			{
			case 0x31:
				g_dw6578 = 0x00;
				g_dw65A8 = 0x00;
				ebx_n = 0x01;
				break;
			case 0x32:
			case 0x33:
			case 0x34:
			case 0x35:
			case 0x36:
			case 55:
			case 0x38:
			case 0x39:
			case 0x3A:
			case 0x3B:
			case 0x3C:
			case 0x3D:
			case 0x3E:
			case 0x3F:
			case 0x44:
			case 0x45:
			case 0x49:
			case 0x4A:
			case 0x4B:
			case 77:
			case 0x4E:
			case 0x51:
			case 0x56:
			case 88:
			case 0x59:
			case 0x5A:
			case 0x5B:
			case 0x5C:
			case 0x5D:
			case 0x5E:
			case 0x5F:
			case 0x60:
			case 0x6A:
				goto l0000000100002B56;
			case 0x40:
				rax_n = &g_dw65B0;
				goto l00000001000029DA;
			case 0x41:
				goto l0000000100002958;
			case 66:
				g_dw657C = 0x00;
				g_dw6588 = 0x01;
				goto l0000000100002A95;
			case 0x43:
				g_dw6578 = 0x00;
				rax_n = &g_dw65A0;
				goto l0000000100002831;
			case 0x46:
				g_dw65AC = 0x01;
				rax_n = &g_dw659C;
				goto l0000000100002A9C;
			case 0x47:
				setenv();
				break;
			case 0x48:
				compat_mode();
				break;
			case 0x4C:
				compat_mode();
				break;
			case 0x4F:
				goto l0000000100002B4A;
			case 0x50:
				break;
			case 0x52:
				g_b65E2 = 0x01;
				break;
			case 0x53:
				r15d_n = 0x01;
				break;
			case 0x54:
				rax_n = &g_dw6594;
				goto l00000001000029DA;
			case 0x55:
				g_dw6560 = 0x01;
				rax_n = &g_dw6558;
				goto l0000000100002878;
			case 0x57:
				dwLoc0650_n = 0x01;
				break;
			case 0x61:
l0000000100002958:
				g_b65D1 = 0x01;
				break;
			case 0x62:
				g_dw657C = 0x00;
				g_dw6588 = 0x00;
				rax_n = &g_dw658C;
				goto l00000001000029DA;
			case 99:
				g_dw65A4 = 0x01;
				g_dw6560 = 0x00;
				rax_n = &g_dw6558;
				goto l0000000100002A9C;
			case 100:
				g_b65C0 = 0x01;
				g_b65E2 = 0x00;
				break;
			case 101:
				rax_n = &g_dw655C;
				goto l00000001000029DA;
			case 0x66:
				g_b65E1 = 0x01;
				compat_mode();
				if (true)
					g_b65D1 = 0x01;
				break;
			case 0x67:
				compat_mode();
				if (true)
				{
					rax_n = &g_dw656C;
					goto l00000001000029CB;
				}
				break;
			case 0x68:
				rax_n = &g_dw6570;
				goto l00000001000029DA;
			case 0x69:
				rax_n = &g_dw6574;
				goto l00000001000029DA;
			case 0x6B:
				goto l0000000100002B5E;
			case 0x6C:
				goto l0000000100002A22;
			case 0x6D:
				rax_n = &g_dw65A8;
				goto l0000000100002824;
			case 110:
				g_dw6584 = 0x01;
				compat_mode();
				if ((byte) 0x100006584 != 0x00)
					goto l0000000100002A22;
				break;
			case 111:
				compat_mode();
				if (false)
				{
l0000000100002B4A:
					rax_n = (word32 *) &g_t6568;
					goto l00000001000029DA;
				}
				else
				{
					rax_n = &g_dw6590;
l00000001000029CB:
					*rax_n = 0x01;
l0000000100002A22:
					g_dw6578 = 0x01;
					rax_n = &g_dw65A8;
					goto l0000000100002831;
				}
			case 0x70:
				g_dw659C = 0x01;
				rax_n = &g_dw65AC;
				goto l00000001000029DA;
			case 113:
				g_dw657C = 0x01;
				goto l0000000100002A88;
			case 114:
				dwLoc0658_n = 0x01;
				break;
			case 115:
				rax_n = &g_dw6598;
l00000001000029DA:
				*rax_n = 0x01;
				break;
			case 116:
				dwLoc064C_n = 0x01;
				break;
			case 117:
				g_dw6558 = 0x01;
				rax_n = &g_dw6560;
l0000000100002878:
				*rax_n = 0x00;
				rax_n = &g_dw65A4;
				goto l0000000100002A9C;
			case 118:
				rax_n = &g_dw657C;
				goto l0000000100002A9C;
			case 0x77:
				g_dw657C = 0x00;
l0000000100002A88:
				g_dw6588 = 0x00;
l0000000100002A95:
				rax_n = &g_dw658C;
l0000000100002A9C:
				*rax_n = 0x00;
				break;
			case 0x78:
				rax_n = &g_dw65A0;
l0000000100002824:
				*rax_n = 0x01;
				rax_n = &g_dw6578;
l0000000100002831:
				*rax_n = 0x00;
				ebx_n = 0x00;
				break;
			}
			eax_n = eax_n;
		}
		if (eax_n != ~0x00)
		{
l0000000100002B56:
			fn000000010000488B();
		}
		int64 rax_n = (int64) *optind;
		if (getenv("CLICOLOR") != 0x00 && (isatty(0x01) != 0x00 || getenv("CLICOLOR_FORCE") != 0x00))
		{
			Eq_n rax_n = getenv("TERM");
			tgetent();
			if ((word32) rax_n == 0x01)
			{
				tgetstr();
				g_t6538 = rax_n;
				tgetstr();
				g_t6528 = rax_n;
				tgetstr();
				g_t6540 = rax_n;
				tgetstr();
				g_t6550 = rax_n;
				tgetstr();
				g_t6530 = rax_n;
				if (rax_n == 0x00)
				{
					tgetstr();
					g_t6530 = rax_n;
				}
				if (g_t6538 != 0x00 && (g_t6528 != 0x00 && rax_n != 0x00))
				{
					g_dw6564 = 0x01;
l0000000100002D0A:
					g_dw6580 = 0x01;
					signal(&g_t319B, 0x02);
					signal(&g_t319B, 0x03);
					fn000000010000328E(getenv("LSCOLORS"));
l0000000100002D4C:
					ui32 eax_n = g_dw6578;
					if (eax_n != 0x00 || (eax_n != 0x00 || g_dw6598 != 0x00))
					{
						if (eax_n != 0x00)
							g_t6548.u0 = 0x02;
						else
						{
							getbsize();
							Eq_n rax_n = g_t6548;
							Mem591[0x0000000100006548<p64>:word64] = (rax_n >> 0x3F >>u 55) + rax_n >> 0x09;
						}
					}
					ptr64 rax_n;
					if (dwLoc0658_n != 0x00)
					{
						if (r15d_n != 0x00)
							rax_n = 0x100001830;
						else if (dwLoc064C_n == 0x00)
							rax_n = 0x1000017C6;
						else if (g_dw6558 != 0x00)
							rax_n = 0x1000018C8;
						else if (g_dw65A4 != 0x00)
							rax_n = 0x100001873;
						else if (g_dw6560 != 0x00)
							rax_n = 0x1000017DB;
						else
							rax_n = 0x10000191D;
					}
					else if (r15d_n != 0x00)
						rax_n = 0x1000019BE;
					else if (dwLoc064C_n == 0x00)
						rax_n = 0x1000017B4;
					else if (g_dw6558 != 0x00)
						rax_n = 0x100001A44;
					else if (g_dw65A4 != 0x00)
						rax_n = 0x1000019F8;
					else if (g_dw6560 != 0x00)
						rax_n = 0x100001972;
					else
						rax_n = 0x100001A90;
					<anonymous> * rax_n;
					g_ptr65C8 = rax_n;
					if (ebx_n != 0x00)
						rax_n = &g_t30C8;
					else if (g_dw6578 != 0x00)
						rax_n = &g_t3BF3;
					else if (g_dw65A8 != 0x00)
						rax_n = &g_t36BE;
					else
						rax_n = &g_t37EC;
					g_ptr65D8 = rax_n;
					fn00000001000023B0();
					exit((word32) g_b65D0);
				}
			}
		}
		if (g_dw6564 == 0x00)
			goto l0000000100002D4C;
		goto l0000000100002D0A;
	}
	word32 eax_n;
	g_dw62B0 = 0x50;
	Eq_n rax_n = getenv("COLUMNS");
	if (rax_n != 0x00 && *rax_n != 0x00)
		eax_n = atoi(rax_n);
	else
	{
		if (ioctl(0x40087468, 0x01) == ~0x00)
			goto l0000000100002748;
		eax_n = (word32) wLoc36;
		if (eax_n == 0x00)
		{
l0000000100002748:
			g_dw657C = 0x01;
			ebx_n = 0x00;
			goto l000000010000277D;
		}
	}
	g_dw62B0 = eax_n;
	goto l0000000100002748;
}

// 0000000100003201: Register word32 fn0000000100003201(Register ui32 edi)
// Called from:
//      fn00000001000035A9
//      fn0000000100003AA8
word32 fn0000000100003201(ui32 edi)
{
	word64 rdi;
	ui32 edi = (word32) rdi;
	byte dil_n = (byte) edi;
	uint64 rdi_n;
	if (g_dw659C != 0x00)
	{
		if ((edi & 0xF000) != 0x4000)
			return 0x00;
		goto l000000010000321F;
	}
	if ((edi & 0xF000) <= 0x3FFF)
	{
		if ((edi & 0xF000) == 0x1000)
		{
			rdi_n = 0x7C;
			goto l0000000100003224;
		}
	}
	else if ((edi & 0xF000) <= 0x9FFF)
	{
		if ((edi & 0xF000) == 0x4000)
		{
l000000010000321F:
			rdi_n = 0x2F;
			goto l0000000100003224;
		}
	}
	else
	{
		if ((edi & 0xF000) == 0xA000)
		{
			rdi_n = 0x40;
			goto l0000000100003224;
		}
		if ((edi & 0xF000) == 0xC000)
		{
			rdi_n = 0x3D;
			goto l0000000100003224;
		}
		if ((edi & 0xF000) == 0xE000)
		{
			rdi_n = 0x25;
			goto l0000000100003224;
		}
	}
	if ((dil_n & 0x49) == 0x00)
		return 0x00;
	rdi_n = 0x2A;
l0000000100003224:
	putchar((word32) rdi_n);
	return 0x01;
}

// 000000010000328E: void fn000000010000328E(Register Eq_n rdi)
// Called from:
//      fn00000001000026A0
void fn000000010000328E(Eq_n rdi)
{
	ptr64 fp;
	Eq_n rax_n = 0x100005410;
	if (rdi != 0x00)
		rax_n = rdi;
	struct Eq_n * qwLoc48_n = (word64) rax_n + 1;
	int32 eax_n = (word32) strlen(rax_n);
	word16 bx_n = 0x00;
	struct Eq_n * r14_n = &g_t65F8;
	uint64 qwLoc40_n = 0x00;
	struct Eq_n * r15_n = null;
	do
	{
		cu8 r12b_n;
		struct Eq_n * rax_n;
		r14_n->dw0000 = 0x00;
		int32 r15d_n = (word32) r15_n;
		if (eax_n <= r15d_n)
		{
			r12b_n = r15_n->b5411;
			rax_n = qwLoc40_n + 1 + qwLoc40_n + 0x100005411;
		}
		else
		{
			rax_n = qwLoc48_n;
			r12b_n = qwLoc48_n->bFFFFFFFF;
		}
		word24 eax_24_8_n = SLICE(rax_n, word24, 8);
		Eq_n r13_n = 0x00;
		while (true)
		{
			if (r12b_n <= 0xC9)
			{
				(r14_n - 8)[r13_n] = (int32) r12b_n + ~0x2F;
				if (bx_n == 0x00)
					fputs(*__stderrp, "warn: LSCOLORS should use characters a-h instead of 0-9 (see the manual page)\n");
				bx_n = 0x01;
			}
			else if (r12b_n <= 0x98)
				(r14_n - 8)[r13_n] = (int32) r12b_n + ~0x60;
			else if (r12b_n <= 0xB8)
			{
				(r14_n - 8)[r13_n] = (int32) r12b_n + ~0x40;
				r14_n->dw0000 = 0x01;
			}
			else
			{
				__tolower();
				if (SEQ(eax_24_8_n, (int8) (r12b_n == 0x78)) == 0x00)
					fprintf("error: invalid character '%c' in LSCOLORS env var\n", *__stderrp);
				(r14_n - 8)[r13_n] = ~0x00;
			}
			if (r13_n == 0x01)
				break;
			Eq_n rax_n = (word64) r13_n + 1;
			eax_24_8_n = SLICE(rax_n, word24, 8);
			r12b_n = Mem146[fp - 49 + r13_n:byte];
			r13_n = rax_n;
		}
		++qwLoc48_n;
		++r14_n;
		++qwLoc40_n;
		r15_n = SEQ(SLICE((char *) r15_n + 2, word32, 32), r15d_n + 0x02);
		r15_n = r15_n;
	} while (r15_n != (struct Eq_n *) 0x14);
}

// 00000001000033F4: void fn00000001000033F4(Register word32 edi)
// Called from:
//      fn00000001000034AC
void fn00000001000033F4(word32 edi)
{
	word64 rdi;
	word32 edi = (word32) rdi;
	uint64 rax_n = (uint64) edi;
	if ((&g_t65F8)[rax_n] != 0x00)
		tputs();
	if (g_a65F0[rax_n] != ~0x00)
	{
		tgoto();
		if (0x100006538 != 0x00)
			tputs();
	}
	if (g_a65F4[rax_n] == ~0x00)
		return;
	tgoto();
	if (4294993192 == 0x00)
		return;
	tputs();
}

// 00000001000034AC: Register word32 fn00000001000034AC(Register ui32 edi)
// Called from:
//      fn00000001000035A9
//      fn0000000100003AA8
word32 fn00000001000034AC(ui32 edi)
{
	byte dil_n = (byte) edi;
	uint64 rdi_n;
	if ((edi & 0xF000) <= 0xBFFF)
	{
		if ((edi & 0xF000) <= 0x9FFF)
		{
			if ((edi & 0xF000) <= 0x5FFF)
			{
				if ((edi & 0xF000) == 0x1000)
				{
					rdi_n = 0x03;
					goto l00000001000034F3;
				}
				if ((edi & 0xF000) == 0x2000)
				{
					rdi_n = 0x06;
					goto l00000001000034F3;
				}
				if ((edi & 0xF000) == 0x4000)
				{
					if ((dil_n & 0x02) != 0x00)
					{
						if ((SLICE((uint64) edi, byte, 8) & 0x02) != 0x00)
							rdi_n = 0x09;
						else
							rdi_n = 0x0A;
					}
					else
						rdi_n = 0x00;
					goto l00000001000034F3;
				}
			}
			else if ((edi & 0xF000) == 0x6000)
			{
				rdi_n = 0x05;
				goto l00000001000034F3;
			}
		}
		else if ((edi & 0xF000) == 0xA000)
		{
			rdi_n = 0x01;
			goto l00000001000034F3;
		}
	}
	else if ((edi & 0xF000) == 0xC000)
	{
		rdi_n = 0x02;
		goto l00000001000034F3;
	}
	if ((dil_n & 0x49) == 0x00)
		return 0x00;
	if ((SLICE((uint64) edi, byte, 8) & 0x08) != 0x00)
		rdi_n = 0x07;
	else if ((SLICE((uint64) edi, byte, 8) & 0x04) != 0x00)
		rdi_n = 0x08;
	else
		rdi_n = 0x04;
l00000001000034F3:
	fn00000001000033F4((word32) rdi_n);
	return 0x01;
}

// 000000010000356F: Register word32 fn000000010000356F(Register Eq_n rdi, Register out ptr64 rbxOut, Register out ptr64 rbpOut, Register out Eq_n r12dOut, Register out ptr64 r14Out, Register out ptr64 r15Out)
// Called from:
//      fn00000001000035A9
//      fn0000000100003AA8
word32 fn000000010000356F(Eq_n rdi, ptr64 & rbxOut, ptr64 & rbpOut, union Eq_n & r12dOut, ptr64 & r14Out, ptr64 & r15Out)
{
	ptr64 rbp;
	ptr64 r15;
	ptr64 r14;
	ptr64 rbx;
	wchar_t wLocBC;
	Eq_n tLocB8;
	if (g_dw6588 != 0x00 || g_dw658C != 0x00)
	{
		ptr64 r14_n;
		ptr64 r15_n;
		ptr64 rbp_n;
		ptr64 rbx_n;
		word32 r12d_n;
		uint64 rax_n = (uint64) fn00000001000048AF(rdi, out rbx_n, out rbp_n, out r12d_n, out r14_n, out r15_n);
		rbxOut = rbx_n;
		rbpOut = rbp_n;
		r12dOut.u0 = <invalid>;
		r14Out = r14_n;
		r15Out = r15_n;
		return (word32) rax_n;
	}
	else if (g_dw657C != 0x00)
	{
		tLocB8 = (Eq_n) 0;
		word32 ebx_n = 0x00;
		Eq_n r14_n = rdi;
		while (true)
		{
			uint64 rax_n;
			Eq_n rax_n = mbrtowc(&tLocB8, 0x06, r14_n, &wLocBC);
			word32 eax_n = (word32) rax_n;
			if (rax_n == ~0x01)
				break;
			int32 r15d_n = (word32) rax_n;
			if (rax_n != ~0x00)
			{
				if (rax_n != 0x00)
				{
					ui32 eax_n;
					Eq_n rdi_n = (int64) wLocBC;
					if (rdi_n <= 0x7F)
						eax_n = _DefaultRuneLocale->a003C[rdi_n] >> 0x12 & 0x01;
					else
					{
						__maskrune();
						eax_n = (word32) (eax_n != 0x00);
					}
					if (eax_n != 0x00)
					{
						if (r15d_n > 0x00)
						{
							uint64 r12_n = (uint64) r15d_n;
							Eq_n r13_n = r14_n;
							do
							{
								putchar((word32) *r13_n);
								r13_n = (word64) r13_n + 1;
								--r12_n;
							} while (r12_n != 0x00);
						}
						r14_n += rax_n;
						ebx_n += wcwidth(wLocBC);
					}
					else
					{
						putchar(0x3F);
						r14_n += rax_n;
						++ebx_n;
					}
					continue;
				}
				else
				{
					rax_n = (uint64) ebx_n;
					goto l0000000100004D9B;
				}
			}
			putchar(0x3F);
			tLocB8 = (Eq_n) 0;
			++ebx_n;
			r14_n = (word64) r14_n + 1;
		}
		putchar(0x3F);
		rax_n = (uint64) (ebx_n + 0x01);
l0000000100004D9B:
		rbxOut = rbx;
		rbpOut = rbp;
		r12dOut.u0 = <invalid>;
		r14Out = r14;
		r15Out = r15;
		return (word32) rax_n;
	}
	else
	{
		uint64 rax_n = (uint64) fn0000000100004715(rdi);
		rbxOut = rbx;
		rbpOut = rbp;
		r12dOut.u0 = <invalid>;
		r14Out = r14;
		r15Out = r15;
		return (word32) rax_n;
	}
}

// 00000001000035A9: void fn00000001000035A9(Register (ptr64 Eq_n) rdi)
void fn00000001000035A9(struct Eq_n * rdi)
{
	struct Eq_n * rbx_n = rdi->ptr0060;
	if (g_dw6574 != 0x00)
		printf("%*llu ");
	if (g_dw6598 != 0x00)
		printf("%*qu ");
	if (g_dw6564 != 0x00)
		fn00000001000034AC((word32) rbx_n->w0004);
	word64 r14_n;
	struct Eq_n * rbx_n;
	word64 r15_n;
	word32 r12d_n;
	word64 rbp_n;
	fn000000010000356F((char *) &rdi->ptr0060 + 8, out rbx_n, out rbp_n, out r12d_n, out r14_n, out r15_n);
	byte r14b_n = (byte) r14_n;
	if (g_dw6564 != 0x00 && (r14b_n & 0x01) != 0x00)
	{
		tputs();
		tputs();
	}
	if (g_dw65AC != 0x00)
		fn0000000100003201((word32) rbx_n->w0004);
}

// 0000000100003786: void fn0000000100003786()
// Called from:
//      fn0000000100003AA8
void fn0000000100003786()
{
	if (g_dw6570 != 0x00)
	{
		humanize_number();
		printf("%5s ");
	}
	else
		printf("%*jd ");
}

// 0000000100003AA8: void fn0000000100003AA8(Register int64 rdi)
// Called from:
//      fn0000000100003AA8
void fn0000000100003AA8(int64 rdi)
{
}

// 0000000100004715: Register word32 fn0000000100004715(Register Eq_n rdi)
// Called from:
//      fn000000010000356F
word32 fn0000000100004715(Eq_n rdi)
{
	wchar_t wLocBC;
	Eq_n tLocB8;
	tLocB8 = (Eq_n) 0;
	word32 dwLocC0_n = 0x00;
	Eq_n r14_n = rdi;
	while (true)
	{
		uint64 rax_n;
		Eq_n rax_n = mbrtowc(&tLocB8, 0x06, r14_n, &wLocBC);
		word32 eax_n = (word32) rax_n;
		if (rax_n == ~0x01)
			break;
		int32 r15d_n = (word32) rax_n;
		switch (rax_n)
		{
		case ~0x00:
		case 0x00:
			rax_n = (uint64) dwLocC0_n;
			return (word32) rax_n;
		default:
			if (r15d_n > 0x00)
			{
				uint64 r12_n = (uint64) r15d_n;
				Eq_n r13_n = r14_n;
				do
				{
					eax_n = putchar((word32) *r13_n);
					r13_n = (word64) r13_n + 1;
					--r12_n;
				} while (r12_n != 0x00);
			}
			ui32 eax_n;
			r14_n += rax_n;
			Eq_n rdi_n = (int64) wLocBC;
			if (rdi_n <= 0x7F)
				eax_n = _DefaultRuneLocale->a003C[rdi_n] >> 0x12 & 0x01;
			else
			{
				__maskrune();
				eax_n = (word32) (eax_n != 0x00);
			}
			if (eax_n != 0x00)
				dwLocC0_n += wcwidth(wLocBC);
			continue;
		}
		tLocB8 = (Eq_n) 0;
		putchar((word32) *r14_n);
		++dwLocC0_n;
		r14_n = (word64) r14_n + 1;
	}
	rax_n = (uint64) (printf("%s") + dwLocC0_n);
	return (word32) rax_n;
}

// 000000010000488B: void fn000000010000488B()
// Called from:
//      fn00000001000026A0
void fn000000010000488B()
{
	fputs(*__stderrp, "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	exit(0x01);
}

// 00000001000048AF: Register word32 fn00000001000048AF(Register Eq_n rdi, Register out ptr64 rbxOut, Register out ptr64 rbpOut, Register out Eq_n r12dOut, Register out ptr64 r14Out, Register out ptr64 r15Out)
// Called from:
//      fn000000010000356F
//      fn000000010000488B
word32 fn00000001000048AF(Eq_n rdi, ptr64 & rbxOut, ptr64 & rbpOut, union Eq_n & r12dOut, ptr64 & r14Out, ptr64 & r15Out)
{
	ptr64 fp;
	ptr64 r14_n;
	ptr64 r15_n;
	ptr64 rbp_n;
	ptr64 rbx_n;
	word32 r12d_n;
	uint64 rax_n = (uint64) fn0000000100004ABB(rdi, fp - 8, out rbx_n, out rbp_n, out r12d_n, out r14_n, out r15_n);
	rbxOut = rbx_n;
	rbpOut = rbp_n;
	r12dOut.u0 = <invalid>;
	r14Out = r14_n;
	r15Out = r15_n;
	return (word32) rax_n;
}

// 0000000100004ABB: Register word32 fn0000000100004ABB(Register Eq_n rbx, Register (ptr64 Eq_n) rbp, Register out ptr64 rbxOut, Register out ptr64 rbpOut, Register out Eq_n r12dOut, Register out ptr64 r14Out, Register out ptr64 r15Out)
// Called from:
//      fn000000010000488B
//      fn00000001000048AF
word32 fn0000000100004ABB(Eq_n rbx, struct Eq_n * rbp, ptr64 & rbxOut, ptr64 & rbpOut, union Eq_n & r12dOut, ptr64 & r14Out, ptr64 & r15Out)
{
	ptr64 qwArg98;
	ptr64 qwArgB0;
	ptr64 qwArgB8;
	ptr64 qwArgC0;
	while (true)
	{
		Eq_n rax_n = mbrtowc(rbp - 0x00B0, 0x06, rbx, rbp - 0x00B4);
		word32 eax_n = (word32) rax_n;
		if (rax_n == 0x00)
			break;
		ui32 eax_n;
		int32 eax_n;
		int32 r14d_n = (word32) rax_n;
		if (rax_n <= ~0x02)
		{
			ui32 eax_n;
			Eq_n rdi_n = (int64) rbp->dwFFFFFF4C;
			if (rdi_n <= 0x7F)
				eax_n = _DefaultRuneLocale->a003C[rdi_n] >> 0x12 & 0x01;
			else
			{
				__maskrune();
				eax_n = (word32) (eax_n != 0x00);
			}
			if (eax_n != 0x00)
			{
				uint64 rdi_n = (uint64) rbp->dwFFFFFF4C;
				word32 edi_n = (word32) rdi_n;
				if (edi_n == 0x22 || edi_n == 0x5C)
					goto l00000001000049B7;
				if (r14d_n > 0x00)
				{
					uint64 r15_n = (uint64) r14d_n;
					Eq_n r12_n = rbx;
					do
					{
						putchar((word32) *r12_n);
						r12_n = (word64) r12_n + 1;
						--r15_n;
					} while (r15_n != 0x00);
					rdi_n = (uint64) rbp->dwFFFFFF4C;
				}
				eax_n = wcwidth((word16) rdi_n);
				goto l0000000100004AA2;
			}
l00000001000049B7:
			if (rax_n > ~0x02)
				goto l0000000100004A24;
			if (g_dw658C != 0x00)
			{
				int32 eax_n = rbp->dwFFFFFF4C;
				if (eax_n < 0x00 || eax_n > 0xFF)
					goto l0000000100004A19;
				memchr();
				if (0x100005770 == 0x00)
					goto l0000000100004A19;
				putchar(0x5C);
				putchar((int32) g_b5771);
				rbp->dwFFFFFF48 += 0x02;
				goto l0000000100004AA8;
			}
l0000000100004A19:
			if (rax_n > ~0x02)
				goto l0000000100004A24;
			eax_n = r14d_n;
			goto l0000000100004A39;
		}
l0000000100004A24:
		if (rax_n == ~0x00)
		{
			eax_n = 0x01;
			goto l0000000100004A3D;
		}
		eax_n = (word32) strlen(rbx);
l0000000100004A39:
		if (eax_n > 0x00)
		{
l0000000100004A3D:
			uint64 r15_n = (uint64) eax_n;
			rbp->dwFFFFFF44 = (word32) r15_n * 0x04;
			Eq_n r12_n = rbx;
			do
			{
				uint64 r13_n = (uint64) *r12_n;
				putchar(0x5C);
				bcu8 r13b_n = (byte) r13_n;
				putchar((word32) (r13b_n >> 0x06) + 0x30);
				putchar(((word32) (r13b_n >> 0x03) & 0x07) + 0x30);
				putchar(((word32) r13_n & 0x07) + 0x30);
				r12_n = (word64) r12_n + 1;
				--r15_n;
			} while (r15_n != 0x00);
			eax_n = rbp->dwFFFFFF44;
l0000000100004AA2:
			rbp->dwFFFFFF48 += eax_n;
		}
l0000000100004AA8:
		if (rax_n == ~0x00)
		{
			rbp->owFFFFFFC0 = 0;
			rbp->owFFFFFFB0 = 0;
			rbp->owFFFFFFA0 = 0;
			rbp->owFFFFFF90 = 0;
			rbp->owFFFFFF80 = 0;
			rbp->owFFFFFF70 = 0;
			rbp->owFFFFFF60 = 0;
			rbp->owFFFFFF50 = 0;
			rbx = (word64) rbx + 1;
			continue;
		}
		if (rax_n == ~0x01)
			break;
		rbx += rax_n;
	}
	uint64 rax_n = (uint64) rbp->dwFFFFFF48;
	rbxOut = qwArg98;
	rbpOut = qwArgC0;
	r12dOut.u0 = <invalid>;
	r14Out = qwArgB0;
	r15Out = qwArgB8;
	return (word32) rax_n;
}

// 0000000100004AFA: Register uint64 fn0000000100004AFA(Register word32 esi, Register Eq_n rdi)
// Called from:
//      fn0000000100001B4A
uint64 fn0000000100004AFA(word32 esi, Eq_n rdi)
{
	word64 rsi;
	wchar_t wLocBC;
	Eq_n tLocB8;
	word32 esi = (word32) rsi;
	tLocB8 = (Eq_n) 0;
	Eq_n rbx_n = (int64) esi;
	word32 ebx_n = (word32) rbx_n;
	ui32 dwLocC0_n = (word32) rbx_n * 0x04;
	uint64 r14_n = 0x00;
	Eq_n r15_n = rbx_n;
	Eq_n r12_n = rdi;
	while (true)
	{
		uint64 rax_n;
		if (ebx_n == 0x00)
			break;
		Eq_n rax_n = mbrtowc(&tLocB8, r15_n, r12_n, &wLocBC);
		word32 eax_n = (word32) rax_n;
		if (rax_n == ~0x01)
		{
			rax_n = (int64) dwLocC0_n + r14_n;
			return rax_n;
		}
		if (rax_n != ~0x00)
		{
			if (rax_n == 0x00)
				break;
			ui32 eax_n;
			Eq_n rdi_n = (int64) wLocBC;
			if (rdi_n <= 0x7F)
				eax_n = _DefaultRuneLocale->a003C[rdi_n] >> 0x12 & 0x01;
			else
			{
				__maskrune();
				eax_n = (word32) (eax_n != 0x00);
			}
			if (eax_n != 0x00)
				++r14_n;
			else
				r14_n += rax_n * 0x04;
			r12_n += rax_n;
			continue;
		}
		tLocB8 = (Eq_n) 0;
		--ebx_n;
		dwLocC0_n += ~0x03;
		--r15_n;
		r12_n = (word64) r12_n + 1;
		r14_n += 0x04;
	}
	rax_n = r14_n;
	return rax_n;
}

