// ping_text_n.c
// Generated by decompiling ping
// using Reko decompiler version 0.11.5.0.

#include "ping.h"

// 00410110: Register Eq_n __fixunsdfsi(Register Eq_n r4, Register Eq_n r5)
// Called from:
//      printf_core
Eq_n __fixunsdfsi(Eq_n r4, Eq_n r5)
{
	Eq_n r6_n = __ext<word32,word32>(r5, 0x04, 11);
	Eq_n r9_n = __ext<word32,word32>(r5, 0x00, 0x14);
	if (r6_n <= 1022)
		return 0x00;
	if (r5 >> 0x1F != 0x00)
	{
		if (r6_n > 0x041D)
			return (r5 >> 0x1F) + ~0x00;
		return 0x00;
	}
	else
	{
		if (r6_n > 0x041E)
			return (r5 >> 0x1F) + ~0x00;
		int32 r5_n = 0x0433 - r6_n;
		if (r5_n >= 0x20)
			return (r9_n | 0x01000000) >> 0x0413 - r6_n;
		return (r9_n | 0x01000000) << (word32) r6_n - 0x0413 | r4 >> r5_n;
	}
}

// 00410170: Register Eq_n __floatsidf(Register Eq_n r4)
// Called from:
//      printf_core
//      __floatscan
Eq_n __floatsidf(Eq_n r4)
{
	Eq_n r6_n;
	Eq_n r8_n;
	Eq_n r7_n;
	Eq_n r4_n;
	if (r4 != 0x00)
	{
		Eq_n r4_n = (r4 ^ r4 >> 0x1F) - (r4 >> 0x1F);
		Eq_n r9_n = __count_leading_zeros<word32>(r4_n);
		r6_n = 0x041E - r9_n;
		r8_n = r4 >> 0x1F;
		int32 r5_n = 0x0433 - r6_n;
		if (r5_n < 0x20)
		{
			r7_n = r4_n >> 11 - r9_n;
			r4_n = r4_n << r5_n;
		}
		else
		{
			r7_n = r4_n << 0x0413 - r6_n;
			r4_n.u0 = 0x00;
		}
	}
	else
	{
		r7_n.u0 = 0x00;
		r4_n.u0 = 0x00;
		r6_n.u0 = 0x00;
		r8_n.u0 = 0x00;
	}
	__ins<word32,word32>(__ins<word32,word32>(__ins<word32,word32>(0x00, r7_n, 0x00, 0x01), r6_n, 0x04, 0x01), r8_n, 0x0F, 0x01);
	return r4_n;
}

// 004101D0: Register Eq_n __floatunsidf(Register Eq_n r4, Register out Eq_n r5Out)
// Called from:
//      printf_core
//      __floatscan
Eq_n __floatunsidf(Eq_n r4, union Eq_n & r5Out)
{
	Eq_n r6_n;
	Eq_n r7_n;
	Eq_n r4_n;
	if (r4 != 0x00)
	{
		Eq_n r8_n = __count_leading_zeros<word32>(r4);
		r6_n = 0x041E - r8_n;
		int32 r5_n = 0x0433 - r6_n;
		if (r5_n < 0x20)
		{
			r7_n = r4 >> 11 - r8_n;
			r4_n = r4 << r5_n;
		}
		else
		{
			r7_n = r4 << 0x0413 - r6_n;
			r4_n.u0 = 0x00;
		}
	}
	else
	{
		r7_n.u0 = 0x00;
		r4_n.u0 = 0x00;
		r6_n.u0 = 0x00;
	}
	r5Out = __ext<word32,word32>(__ins<word32,word32>(__ins<word32,word32>(0x00, r7_n, 0x00, 0x01), r6_n, 0x04, 0x01), 0x00, 0x1F);
	return r4_n;
}

// 00410220: void __truncdfsf2(Register Eq_n r4, Register Eq_n r5)
// Called from:
//      strtof_l
//      __isoc99_vfscanf
void __truncdfsf2(Eq_n r4, Eq_n r5)
{
	Eq_n r9_n = __ext<word32,word32>(r5, 0x00, 0x14);
	Eq_n r10_n = __ext<word32,word32>(r5, 0x04, 11);
	ui32 r9_n = r4 >> 0x1D | r9_n << 0x03;
	Eq_n r8_n;
	Eq_n r7_n;
	if ((r10_n.u7 + 1 & 0x07FF) >= 0x02)
	{
		r8_n.u3 = (word32) r10_n - 896;
		if (r10_n > 1150)
		{
			r7_n.u0 = 0x00;
			r8_n.u0 = 0xFF;
			goto l004102FC;
		}
		if (r10_n > 0x0380)
		{
			r7_n = r9_n << 0x03 | ((r4 << 0x03) >> 0x1D | (word32) (r4 << 0x06 > 0x00));
			goto l004102C8;
		}
		if (r10_n < 0x0369)
		{
			r7_n.u0 = 0x01;
			r8_n.u0 = 0x00;
			goto l00410336;
		}
		int32 r4_n = 0x1E - ((word32) r10_n - 896);
		if (r4_n < 0x20)
			r7_n = (word32) (r4 << 0x03 << (word32) r10_n - 894 > 0x00) | (r9_n | 0x08000000) << (word32) r10_n - 894 | (r4 << 0x03) >> r4_n;
		else
		{
			ui32 r11_n = 0x00;
			uint32 r8_n = (r9_n | 0x08000000) >> ~0x01 - ((word32) r10_n - 896);
			if (r4_n != 0x20)
				r11_n = (r9_n | 0x08000000) << (word32) r10_n - 862;
			r7_n = r8_n | (word32) ((r11_n | r4 << 0x03) > 0x00);
		}
	}
	else
	{
		r7_n = r9_n | r4 << 0x03;
		if (r10_n != 0x00)
		{
			r8_n.u0 = 0xFF;
			if (r7_n == 0x00)
				goto l004102FC;
			r7_n = r9_n << 0x03 | 0x20000000;
l004102C8:
			if ((r7_n & 0x07) == 0x00 || (r7_n & 0x0F) == 0x04)
				goto l004102FC;
l00410336:
			r7_n.u7->a0000 = r7_n.u7 + 4;
l004102FC:
			if (!__bit<word32,word32>(r7_n, 0x1A))
			{
				r8_n.u3 = (byte) r8_n.u0 + 1;
				r7_n = __ins<word32,word32>(r7_n, 0x00, 0x0A, 0x01);
				if (r8_n == 0xFF)
					r7_n.u0 = 0x00;
			}
			Eq_n r7_n = r7_n >> 0x03;
			if (r8_n == 0xFF && r7_n != 0x00)
				r7_n |= 0x04000000;
			__ins<word32,word32>(__ins<word32,word32>(__ins<word32,word32>(0x00, r7_n, 0x00, 0x01), r8_n, 0x07, 0x01), r5 >> 0x1F, 0x0F, 0x01);
			return;
		}
		r7_n.u3 = (word32) (r7_n > 0x00);
	}
	r8_n.u0 = 0x00;
	goto l004102C8;
}

