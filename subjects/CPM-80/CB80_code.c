// CB80_code.c
// Generated by decompiling CB80.COM
// using Reko decompiler version 0.11.6.0.

#include "CB80.h"

ui16 g_w0103 = 0x5A00; // 0103
word16 g_w0108 = 5888; // 0108
char g_b02A3 = 'd'; // 02A3
// 0387: void fn0387()
// Called from:
//      fn0483
//      fn061B
//      fn075C
//      fn100A
//      fn1229
void fn0387()
{
	<anonymous> * hl_n = g_ptr1648;
	hl_n();
}

// 0390: void fn0390(Register byte b, Register Eq_n c, Register byte e, Stack byte bArg02)
// Called from:
//      fn0990
void fn0390(byte b, Eq_n c, byte e, byte bArg02)
{
	g_b1656 = e;
	g_b1655 = b;
	g_t1654.u0 = (byte) c;
	word16 wArg02;
	g_b1653 = (byte) wArg02;
	while (true)
	{
		byte a_n = g_b1653;
		g_b1653 = a_n - 0x01;
		if (a_n == 0x00)
			break;
		*g_t1654.u1 = g_b1656;
		++g_t1654.u1;
	}
}

// 03BB: FlagGroup bool fn03BB(Register Eq_n c, Register out Eq_n aOut)
// Called from:
//      fn03CB
//      fn03E6
bool fn03BB(Eq_n c, union Eq_n & aOut)
{
	g_t1657.u0 = (uint8) c;
	byte a_n = SLICE(0x1A - (uint16) (g_t1657.u0 - 0x61), byte, 8);
	aOut = ~a_n;
	return (bool) cond(a_n);
}

// 03CB: Register word16 fn03CB(Register Eq_n c)
// Called from:
//      fn0990
word16 fn03CB(Eq_n c)
{
	g_t1658.u0 = (uint8) c;
	byte a_n = ~SLICE(0x19 - (uint16) (g_t1658.u0 - 0x41), byte, 8);
	byte a_n;
	fn03BB(g_t1658.u0, out a_n);
	byte f;
	return SEQ(a_n | a_n, f);
}

// 03E6: Register Eq_n fn03E6(Register Eq_n c)
// Called from:
//      fn0990
Eq_n fn03E6(Eq_n c)
{
	g_t1659.u0 = (uint8) c;
	byte a_n;
	if (__rcr<byte,byte>(a_n, 0x01, fn03BB(g_t1659.u0, out a_n)) >= 0x00)
		return g_t1659.u0;
	return g_t1659.u0 + 0x5F;
}

// 0400: void fn0400()
void fn0400()
{
	g_w1640 = g_w0006;
	g_ptr164E = (struct Eq_n *) &g_b0080;
}

// 040D: void fn040D(Register byte b, Register Eq_n c, Register cu8 e, Stack word16 wArg02)
// Called from:
//      fn0BE4
void fn040D(byte b, Eq_n c, cu8 e, word16 wArg02)
{
	g_b165E = e;
	g_b165D = b;
	g_t165C.u0 = (byte) c;
	g_b165B = SLICE(wArg02, byte, 8);
	g_t165A.u0 = (byte) (byte) wArg02;
	while (g_b165E > 0x00)
	{
		F_DMAOFF(g_t165C.u1);
		if (F_READ(g_t165A.u1) == 0x00)
		{
			--g_b165E;
			g_t165C.u1 += 0x0080;
		}
		else
		{
			*g_t165C.u1 = 0x1A;
			g_b165E = 0x00;
		}
	}
}

// 045B: Register byte fn045B()
// Called from:
//      fn100A
//      fn1229
//      fn1262
//      fn1279
//      fn12D8
byte fn045B()
{
	if (g_b0080 == 0x00)
		return 0x00;
	--g_b0080;
	struct Eq_n * hl_n = g_ptr164E;
	g_ptr164E = (struct Eq_n *) &hl_n->b0001;
	return hl_n->b0001;
}

// 0473: Register char fn0473(Register char c)
// Called from:
//      fn0483
//      fn056B
char fn0473(char c)
{
	g_b165F = c;
	C_WRITE(g_b165F);
	return 0x02;
}

// 0483: Register word16 fn0483(Register byte b, Register Eq_n c, Register byte d, Register Eq_n e, Stack word16 wArg02)
// Called from:
//      fn0534
word16 fn0483(byte b, Eq_n c, byte d, Eq_n e, word16 wArg02)
{
	byte l_n;
	g_b1665 = d;
	g_t1664.u0 = (byte) e;
	g_b1663 = b;
	g_t1662.u0 = (byte) c;
	byte b_n = SLICE(wArg02, byte, 8);
	g_b1661 = b_n;
	g_t1660.u0 = (byte) (byte) wArg02;
	struct Eq_n * hl_n = (struct Eq_n *) <invalid>;
	byte c_n = fn1326(0x07, g_t1664.u1 + 0x7F, out l_n);
	g_b1667 = (byte) hl_n;
	word16 bc_n = SEQ(b_n, c_n);
	while (true)
	{
		byte b_n = SLICE(bc_n, byte, 8);
		if (g_b1667 <= 0x00)
			break;
		F_DMAOFF(g_t1662.u1);
		bc_n = SEQ(b_n, 0x15);
		if (F_WRITE(g_t1660.u1) == 0x00)
		{
			--g_b1667;
			g_t1662.u1 += 0x0080;
		}
		else
		{
			g_ptr1668 = &g_b02A3;
			while (*g_ptr1668 != 0x24)
			{
				fn0473(*g_ptr1668);
				++g_ptr1668;
			}
			if (*g_t1660.u1 == 0x00)
				*g_t1660.u1 = DRV_GET() + 0x01;
			fn0473(*g_t1660.u1 + 0x60);
			byte c_n = fn0473(0x3A);
			fn0387();
			bc_n = SEQ(b_n, c_n);
		}
	}
	return bc_n;
}

// 0524: Register char fn0524(Register char c)
// Called from:
//      fn056B
char fn0524(char c)
{
	g_b166A = c;
	L_WRITE(g_b166A);
	return 0x05;
}

// 0534: Register word16 fn0534(Register char c)
// Called from:
//      fn056B
word16 fn0534(char c)
{
	word16 bc;
	c = (byte) bc;
	g_b166B = c;
	*((word16) g_ptr14BC + g_w14BE) = (ptr16) g_b166B;
	int16 hl_n = g_w14BE;
	g_w14BE = hl_n + 0x01;
	word16 bc_n = bc;
	if (!fn1335(hl_n + 0x01, 0x0200))
	{
		ptr16 hl_n = g_ptr14BC;
		bc_n = fn0483(SLICE(hl_n, byte, 8), (byte) hl_n, 0x02, 0x00, 0x14C0);
		g_w14BE = 0x00;
	}
	return bc_n;
}

// 056B: FlagGroup bool fn056B(Register ptr16 bc, Register out ptr16 bcOut)
// Called from:
//      fn05CE
//      fn05EF
//      fn0722
//      fn0745
//      fn075C
//      fn07B3
//      fn0814
//      fn100A
//      fn1229
bool fn056B(ptr16 bc, ptr16 & bcOut)
{
	char c = (byte) bc;
	byte b = SLICE(bc, byte, 8);
	g_b166C = c;
	ptr16 bc_n;
	switch (g_b14F3)
	{
	case 0x01:
		bc_n = SEQ(b, fn0524(g_b166C));
		break;
	case 0x02:
		bc_n = SEQ(b, fn0473(g_b166C));
		break;
	default:
		bc_n = bc;
		if (g_b14F3 == 0x04)
			bc_n = fn0534(g_b166C);
		break;
	}
	char a_n = g_b166C;
	bool C_n = (bool) cond(a_n - 0x0D);
	if (a_n == 0x0D)
		g_b14F6 = 0x01;
	else
	{
		char a_n = g_b166C;
		C_n = (bool) cond(a_n - 0x0A);
		if (a_n == 0x0A)
		{
			cu8 a_n = g_b14F3;
			C_n = (bool) cond(a_n - 0x00);
			if (a_n != 0x00)
				++g_b14FD;
		}
		else
			++g_b14F6;
	}
	bcOut = bc_n;
	return C_n;
}

// 05CE: Register byte fn05CE(Register Eq_n bc)
// Called from:
//      fn061B
//      fn075C
//      fn07B3
//      fn0BE4
//      fn100A
//      fn1229
byte fn05CE(Eq_n bc)
{
	byte b = SLICE(bc, byte, 8);
	Eq_n c = (byte) bc;
	g_b166E = b;
	g_t166D.u0 = (byte) c;
	Eq_n bc_n = bc;
	while (true)
	{
		byte b_n = SLICE(bc_n, byte, 8);
		if (*g_t166D.u1 == 0x24)
			break;
		fn056B(SEQ(b_n, *g_t166D.u1), out bc_n);
		++g_t166D.u1;
	}
	return SLICE(bc_n, byte, 8);
}

// 05EF: FlagGroup bool fn05EF(Register Eq_n bc, Register out Eq_n bOut)
// Called from:
//      fn061B
//      fn06CE
//      fn07B3
bool fn05EF(Eq_n bc, union Eq_n & bOut)
{
	byte b = SLICE(bc, byte, 8);
	Eq_n c = (byte) bc;
	g_b1670 = b;
	g_t166F.u0 = (byte) c;
	g_b1671 = 0x01;
	Eq_n bc_n = bc;
	bool C_n;
	do
	{
		uint8 a_n = g_t166F.u1[0];
		byte b_n = SLICE(bc_n, byte, 8);
		C_n = (bool) cond(a_n - g_b1671);
		if (a_n < g_b1671)
			break;
		C_n = fn056B(SEQ(b_n, g_t166F.u1[(uint16) g_b1671]), out bc_n);
		++g_b1671;
	} while (g_b1671 != 0x00);
	bOut.u1 = <invalid>;
	return C_n;
}

// 061B: FlagGroup bool fn061B(Register byte b, Register Eq_n c, Register byte d, Register Eq_n e)
// Called from:
//      fn082F
bool fn061B(byte b, Eq_n c, byte d, Eq_n e)
{
	byte b_n;
	g_b1675 = d;
	g_t1674.u0 = (byte) e;
	g_b1673 = b;
	g_t1672.u0 = (byte) c;
	g_b14F3 = 0x02;
	fn05CE(g_t1672.u1);
	bool C_n = fn05EF(g_t1674.u1, out b_n);
	fn0387();
	return C_n;
}

// 063E: void fn063E(Register byte b, Register Eq_n c, Register byte d, Register Eq_n e)
// Called from:
//      fn06CE
void fn063E(byte b, Eq_n c, byte d, Eq_n e)
{
	g_b1679 = d;
	g_t1678.u0 = (byte) e;
	g_b1677 = b;
	g_t1676.u0 = (byte) c;
	g_b167B = 0x00;
	g_t1678.u1[0] = 0x00;
	g_b167A = 0x00;
	while (g_b167A <= 0x03)
	{
		g_b167C = 0x30;
		Eq_n C_n;
		while (true)
		{
			word16 de_n;
			word16 hl_n;
			C_n = fn1348(&g_t1676, (uint16) g_b167A * 0x02 + 0x0227, out de_n, out hl_n);
			if (C_n)
				break;
			struct Eq_n * de_n;
			word16 hl_n;
			fn1348(&g_t1676, (uint16) g_b167A * 0x02 + 0x0227, out de_n, out hl_n);
			de_n->wFFFFFFFF = hl_n;
			g_b167B = 0x01;
			++g_b167C;
		}
		if (__rcr<byte,byte>(g_b167B, 0x01, C_n) < 0x00)
		{
			Eq_n hl_n;
			hl_n.u1 = g_t1678.u1;
			byte a_n = (byte) *hl_n;
			hl_n->u0 = a_n + 0x01;
			g_t1678.u1[(uint16) (a_n + 0x01)] = g_b167C;
		}
		++g_b167A;
		if (g_b167A == 0x00)
			break;
	}
	Eq_n hl_n;
	hl_n.u1 = g_t1678.u1;
	Eq_n hl_n;
	hl_n.u1 = g_t1676.u1;
	byte a_n = (byte) *hl_n;
	hl_n->u0 = a_n + 0x01;
	g_t1678.u1[(uint16) (a_n + 0x01)] = (byte) hl_n + 0x30;
}

// 06CE: Register byte fn06CE(Register byte b, Register Eq_n c)
// Called from:
//      fn075C
//      fn07B3
//      fn0BE4
byte fn06CE(byte b, Eq_n c)
{
	g_b167E = b;
	g_t167D.u0 = (byte) c;
	Eq_n hl_n;
	hl_n.u1 = g_t167D.u1;
	fn063E(SLICE(hl_n, byte, 8), (byte) hl_n, 22, 44);
	byte b_n;
	fn05EF(5676, out b_n);
	struct Eq_n * bc_n = (struct Eq_n *) <invalid>;
	return SLICE(bc_n, byte, 8);
}

// 0722: void fn0722(Register cu8 c, Register byte b)
void fn0722(cu8 c, byte b)
{
	g_b1681 = c;
	if (g_b1681 > 0x09)
	{
		word16 bc_n;
		fn056B(SEQ(b, g_b1681 + 0x57), out bc_n);
	}
	else
	{
		word16 bc_n;
		fn056B(SEQ(b, g_b1681 + 0x30), out bc_n);
	}
}

// 0745: void fn0745(Register word16 bc)
// Called from:
//      fn07B3
void fn0745(word16 bc)
{
	cu8 c = (byte) bc;
	g_b1682 = c;
	word16 bc_n = bc;
	while (true)
	{
		byte b_n = SLICE(bc_n, byte, 8);
		if (g_b14F6 >= g_b1682)
			break;
		fn056B(SEQ(b_n, 0x20), out bc_n);
	}
}

// 075C: void fn075C(Register byte b, Register Eq_n c, Register byte d, Register Eq_n e)
// Called from:
//      fn0BE4
//      fn0D84
void fn075C(byte b, Eq_n c, byte d, Eq_n e)
{
	g_b1686 = d;
	g_t1685.u0 = (byte) e;
	g_b1684 = b;
	g_t1683.u0 = (byte) c;
	g_b14F3 = 0x02;
	if (g_b14F6 != 0x01)
	{
		word16 bc_n;
		fn056B(SEQ(b, 0x0D), out bc_n);
		word16 bc_n;
		fn056B(SEQ(SLICE(bc_n, byte, 8), 0x0A), out bc_n);
	}
	fn05CE(0x0260);
	Eq_n hl_n;
	hl_n.u1 = g_t1683.u1;
	word16 bc_n;
	fn056B(SEQ(SLICE((uint16) fn06CE(SLICE(hl_n, byte, 8), (byte) hl_n), byte, 8), 0x0D), out bc_n);
	word16 bc_n;
	fn056B(SEQ(SLICE(bc_n, byte, 8), 0x0A), out bc_n);
	struct Eq_n * hl_n = (struct Eq_n *) <invalid>;
	byte l_n;
	if ((fn1353(0x00, &g_t1685, out l_n) | (byte) hl_n) != 0x00)
	{
		fn05CE(0x034E);
		Eq_n hl_n;
		hl_n.u1 = g_t1685.u1;
		fn06CE(SLICE(hl_n, byte, 8), (byte) hl_n);
	}
	fn0387();
}

// 07B3: void fn07B3(Register cu8 b)
// Called from:
//      fn0814
//      fn100A
void fn07B3(cu8 b)
{
	word16 bc;
	b = SLICE(bc, byte, 8);
	Eq_n C;
	if (__rcr<byte,byte>(g_b14F9, 0x01, C) < 0x00)
	{
		word16 bc_n;
		fn056B(SEQ(b, 0x0D), out bc_n);
		byte b_n = SLICE(bc_n, byte, 8);
		while (g_b14FD < g_b14F7)
		{
			word16 bc_n;
			fn056B(SEQ(b_n, 0x0D), out bc_n);
			word16 bc_n;
			fn056B(SEQ(SLICE(bc_n, byte, 8), 0x0A), out bc_n);
			b_n = SLICE(bc_n, byte, 8);
		}
		word16 bc_n;
		fn056B(SEQ(b_n, 0x0D), out bc_n);
		word16 bc_n;
		fn056B(SEQ(SLICE(bc_n, byte, 8), 0x0A), out bc_n);
		fn05CE(0x02B7);
		byte b_n;
		fn05EF(0x14FF, out b_n);
		struct Eq_n * bc_n = (struct Eq_n *) <invalid>;
		fn0745(SEQ(SLICE(bc_n, byte, 8), g_b14F8 - 0x0A));
		fn05CE(0x02FC);
		fn06CE(0x00, g_t14FE.u0);
		g_t14FE.u0 = (byte) (g_t14FE.u0 + 0x01);
		byte b_n;
		fn05EF(898, out b_n);
	}
	g_b14FD = 0x03;
}

// 0814: void fn0814(Register byte b)
// Called from:
//      fn0BE4
void fn0814(byte b)
{
	word16 bc_n;
	fn056B(SEQ(b, 0x0D), out bc_n);
	word16 bc_n;
	fn056B(SEQ(SLICE(bc_n, byte, 8), 0x0A), out bc_n);
	cu8 a_n = g_b14F7;
	if (g_b14FD >= a_n - 0x03)
		fn07B3(a_n - 0x03);
}

// 082F: Register uint8 fn082F(Register uint8 f, Register byte b, Register Eq_n c, Register byte e, Stack word16 wArg02, Stack word16 wArg04)
// Called from:
//      fn0BE4
uint8 fn082F(uint8 f, byte b, Eq_n c, byte e, word16 wArg02, word16 wArg04)
{
	word16 af_n;
	g_b168D = e;
	g_b168C = b;
	g_t168B.u0 = (byte) c;
	g_b168A = SLICE(wArg02, byte, 8);
	g_t1689.u0 = (byte) (byte) wArg02;
	g_b1688 = SLICE(wArg04, byte, 8);
	g_t1687.u0 = (byte) (byte) wArg04;
	g_b168F = 0x00;
	g_b1690 = 0x00;
	g_b1691 = 0x00;
	byte a_n = __rol<byte,byte>(g_b168D, 0x01);
	if (__rcr<byte,byte>(a_n, 0x01, cond(a_n)) < 0x00)
		g_b1690 = 0x01;
	else
	{
		byte a_n = __rol<byte,byte>(g_b168D, 0x02);
		if (__rcr<byte,byte>(a_n, 0x01, cond(a_n)) < 0x00)
			g_b1691 = 0x01;
		else
		{
			byte a_n = __rol<byte,byte>(g_b168D, 0x03);
			if (__rcr<byte,byte>(a_n, 0x01, cond(a_n)) < 0x00)
				g_b168F = 0x01;
		}
	}
	byte a_n = __rol<byte,byte>(g_b168D, 0x04);
	if (__rcr<byte,byte>(a_n, 0x01, cond(a_n)) < 0x00)
		g_b168E = 0x01;
	g_b168D += 0x0F;
	Eq_n hl_n;
	hl_n.u1 = g_t1687.u1;
	Eq_n hl_n;
	hl_n.u1 = g_t1689.u1;
	cu8 a_n = __rcr<byte,byte>(~SLICE(af_n, byte, 8), 0x01, fn0990(f, SLICE(hl_n, byte, 8), (byte) hl_n, SLICE(hl_n, byte, 8), (byte) hl_n, out af_n));
	uint8 f_n = (byte) af_n;
	Eq_n C_n = cond(a_n);
	if (a_n < 0x00)
	{
		Eq_n hl_n;
		hl_n.u1 = g_t1687.u1;
		C_n = fn061B(0x02, 0x4C, SLICE(hl_n, byte, 8), (byte) hl_n);
	}
	cu8 a_n = __rcr<byte,byte>(g_b1690, 0x01, C_n);
	Eq_n C_n = cond(a_n);
	if (a_n >= 0x00)
	{
		cu8 a_n = __rcr<byte,byte>(g_b1691, 0x01, C_n);
		Eq_n C_n = cond(a_n);
		if (a_n >= 0x00)
		{
			if (__rcr<byte,byte>(g_b168F, 0x01, C_n) >= 0x00)
			{
				fn0920();
				return f_n;
			}
			else if (g_b1520 == 0x00)
			{
				*g_t168B.u1 = (Fcb *) g_b151F;
				fn0920();
				return f_n;
			}
			else
			{
				*g_t168B.u1 = (Fcb *) g_b1520;
				fn0920();
				return f_n;
			}
		}
		else if (g_b151E == 0x00)
			*g_t168B.u1 = (Fcb *) g_b151F;
		else
		{
			fn08EC();
			return f_n;
		}
	}
	else
	{
		if (*g_t168B.u1 == 0x00)
		{
			if (g_b151D == 0x00)
				*g_t168B.u1 = (Fcb *) g_b151F;
			else
				*g_t168B.u1 = (Fcb *) g_b151D;
		}
		fn0920();
		return f_n;
	}
}

// 08EC: void fn08EC()
// Called from:
//      fn082F
void fn08EC()
{
	*g_t168B.u1 = (Fcb *) g_b151E;
	fn08EC();
}

// 08FD: void fn08FD()
// Called from:
//      fn082F
void fn08FD()
{
	fn08FD();
}

// 0920: void fn0920()
// Called from:
//      fn082F
void fn0920()
{
	F_DMAOFF(0x80);
	if (g_b168D == 0x00)
	{
		byte b_n;
		byte h_n;
		cu8 a_n;
		byte l_n;
		S_BDOSVER(out b_n, out h_n, out a_n, out l_n);
		if (((byte) (a_n < 0x30) - 1 & g_b168E) >> 0x01 < 0x00)
			*((char *) g_t168B.u1 + 7) = (Fcb *) (*((char *) g_t168B.u1 + 7) | 0x80);
		if (F_OPEN(g_t168B.u1) == ~0x00)
		{
			Eq_n hl_n;
			hl_n.u1 = g_t1687.u1;
			fn061B(0x02, 0x36, SLICE(hl_n, byte, 8), (byte) hl_n);
		}
	}
	else
	{
		F_DELETE(g_t168B.u1);
		if (F_MAKE(g_t168B.u1) == ~0x00)
		{
			Eq_n hl_n;
			hl_n.u1 = g_t1687.u1;
			fn061B(0x02, 0x87, SLICE(hl_n, byte, 8), (byte) hl_n);
		}
	}
}

// 0990: FlagGroup Eq_n fn0990(Register uint8 f, Register byte b, Register Eq_n c, Register byte d, Register Eq_n e, Register out Eq_n afOut)
// Called from:
//      fn082F
Eq_n fn0990(uint8 f, byte b, Eq_n c, byte d, Eq_n e, union Eq_n & afOut)
{
	g_b1695 = d;
	g_t1694.u0 = (byte) e;
	g_b1693 = b;
	g_t1692.u0 = (byte) c;
	Eq_n hl_n;
	hl_n.u1 = g_t168B.u1;
	fn0390(SLICE((word16) hl_n + 1, byte, 8), (byte) hl_n + 0x01, 0x20, 11);
	g_t1696.u0 = g_t1692.u1->a0000[0].u0;
	Eq_n hl_n;
	hl_n.u1 = g_t1692.u1;
	g_t1692.u1 = (word16) hl_n + 1;
	struct Eq_n * sp_n = (struct Eq_n *) <invalid>;
	if (hl_n.u1->b0002 == 0x3A)
	{
		Eq_n af_n = fn03CB(g_t1692.u1->a0000[0].u0);
		Eq_n hl_n;
		hl_n.u1 = g_t1692.u1;
		sp_n->tFFFFFFFE.u1 = (byte *) af_n;
		f = (byte) af_n;
		sp_n->tFFFFFFFE.u1 = (byte *) SEQ(0x00 - (byte) (*hl_n < 0x41) | sp_n->b0003, f);
		bcu8 a_n = SLICE(0x02 - (uint16) g_t1696.u0, byte, 8) & sp_n->b0003;
		Eq_n C_n = cond(a_n >> 0x01);
		if (a_n >> 0x01 >= 0x00)
		{
			afOut.u0 = (uint16) f;
			return C_n;
		}
		*g_t168B.u1 = (Fcb *) (g_t1692.u1->a0000[0].u0 & 0x1F);
		Eq_n hl_n;
		hl_n.u1 = g_t168B.u1;
		Eq_n C_n = (bool) cond(0x10 - *hl_n.u1);
		if (*hl_n.u1 > 0x10)
		{
			afOut.u0 = (uint16) f;
			return C_n;
		}
		g_t1692.u1 = (struct Eq_n *) &g_t1692.u1->b0002;
		g_t1696.u0 = (uint8) (g_t1696.u0 - 0x01);
		g_t1696.u0 = (uint8) (g_t1696.u0 - 0x01);
	}
	else
		*g_t168B.u1 = (Fcb *) 0x00;
	g_b1697 = 0x00;
	while (true)
	{
		sp_n->tFFFFFFFE.u1 = (byte *) SEQ(~SLICE(0x07 - (uint16) g_b1697, byte, 8), f);
		word16 af_n = fn0B74();
		f = (byte) af_n;
		if ((SLICE(af_n, byte, 8) & sp_n->b0003) >> 0x01 >= 0x00)
			break;
		sp_n->tFFFFFFFE.u1 = (byte *) (&g_t1692.u1->a0000->u0 + (uint16) g_b1697);
		byte a_n = *sp_n->tFFFFFFFE.u1;
		Mem429[Mem415[5771:word16] + (CONVERT(Mem415[0x1697:byte], uint8, uint16) + 0x01):byte] = a_n;
		Eq_n C_n = (bool) cond(a_n - 0x2A);
		if (a_n == 0x2A)
		{
			afOut.u0 = (uint16) f;
			return C_n;
		}
		fn0B91();
	}
	cu8 * hl_n = (cu8 *) (&g_t1692.u1->a0000->u0 + (uint16) g_b1697);
	sp_n->tFFFFFFFE.u1 = (byte *) SEQ(SLICE(0x01 - (uint16) g_t1696.u0, byte, 8), f);
	byte b_n;
	if ((0x00 - (byte) (*hl_n < 0x2F) & sp_n->b0003) >> 0x01 < 0x00)
	{
		fn0B91();
		Eq_n C_n = (bool) cond(0x03 - g_t1696.u0);
		if (g_t1696.u0 > 0x03)
		{
			afOut.u0 = (uint16) f;
			return C_n;
		}
		sp_n->tFFFFFFFE.u1 = g_t1696.u1;
		sp_n->ptrFFFFFFFC = (byte *) (&g_t1692.u1->a0000->u0 + (uint16) g_b1697);
		byte * de_n = (char *) g_t168B.u1 + 9;
		byte * bc_n = sp_n->ptrFFFFFFFC;
		byte l_n = sp_n->b0002;
		do
		{
			*de_n = *bc_n;
			++bc_n;
			b_n = SLICE(bc_n, byte, 8);
			++de_n;
			--l_n;
		} while (l_n != 0x00);
	}
	else
	{
		cu8 * hl_n = (cu8 *) (&g_t1692.u1->a0000->u0 + (uint16) g_b1697);
		sp_n->tFFFFFFFE.u1 = (byte *) SEQ(0x00 - (byte) (g_t1696.u0 < 0x01), f);
		bcu8 a_n = 0x00 - (byte) (*hl_n < 0x2F) | sp_n->b0003;
		Eq_n C_n = cond(a_n >> 0x01);
		if (a_n >> 0x01 >= 0x00)
		{
			afOut.u0 = (uint16) f;
			return C_n;
		}
		Eq_n hl_n;
		hl_n.u1 = g_t1694.u1;
		sp_n->tFFFFFFFE.u1 = (byte *) SEQ(SLICE(hl_n, byte, 8), *hl_n.u1);
		sp_n->ptrFFFFFFFC = g_t1694.u1 + 1;
		byte * de_n = (char *) g_t168B.u1 + 9;
		byte * bc_n = sp_n->ptrFFFFFFFC;
		byte l_n = sp_n->b0002;
		do
		{
			*de_n = *bc_n;
			++bc_n;
			b_n = SLICE(bc_n, byte, 8);
			++de_n;
			--l_n;
		} while (l_n != 0x00);
	}
	sp_n->tFFFFFFFE.u1 = (byte *) SEQ(b_n, 0x03);
	Eq_n hl_n;
	hl_n.u1 = g_t168B.u1;
	fn0390(SLICE((word16) hl_n + 0x0C, byte, 8), (byte) hl_n + 0x0C, 0x00, sp_n->b0002);
	*((char *) g_t168B.u1 + 32) = (Fcb *) 0x00;
	g_b1697 = 0x00;
	while (g_b1697 <= 0x07)
	{
		Mem354[Mem320[5771:word16] + (CONVERT(Mem320[0x1697:byte], uint8, uint16) + 0x01):byte] = fn03E6(Mem320[Mem320[5771:word16] + (CONVERT(Mem320[0x1697:byte], uint8, uint16) + 0x01):byte]);
		uint8 a_n = g_b1697;
		g_b1697 = a_n + 0x01;
		if (a_n == ~0x00)
			break;
	}
	g_b1697 = 0x00;
	Eq_n C_n;
	uint8 a_n;
	do
	{
		C_n = (bool) cond(0x02 - g_b1697);
		if (g_b1697 > 0x02)
			break;
		byte a_n = fn03E6(Mem364[Mem364[5771:word16] + (CONVERT(Mem364[0x1697:byte], uint8, uint16) + 0x09):byte]);
		byte * hl_n = (char *) g_t168B.u1 + ((uint16) g_b1697 + 0x09);
		*hl_n = a_n;
		a_n = g_b1697;
		g_b1697 = a_n + 0x01;
		C_n = (bool) cond(hl_n);
	} while (a_n != ~0x00);
	afOut = SEQ(0x01, f);
	return C_n;
}

// 0B74: Register word16 fn0B74()
// Called from:
//      fn0990
word16 fn0B74()
{
	byte f;
	return SEQ(0x00 - (byte) (g_t1696.u0 < 0x01) & 0x00 - (byte) ((&(((g_t1692.u1)->a0000))[0].u0)[(uint16) g_b1697] < 0x2F), f);
}

// 0B91: void fn0B91()
// Called from:
//      fn0990
void fn0B91()
{
	++g_b1697;
	g_t1696.u0 = (uint8) (g_t1696.u0 - 0x01);
}

// 0BE4: void fn0BE4(Register uint8 f)
// Called from:
//      fn100A
void fn0BE4(uint8 f)
{
	byte a_n = 0x00 - (byte) (g_b138A < 0x02);
	if ((0x00 - (byte) (g_b14F3 < 0x03) & a_n) >> 0x01 < 0x00)
	{
		if (g_b14F6 != 0x01)
			fn0814(a_n);
		fn05CE(662);
		fn0814(SLICE((uint16) fn06CE(0x00, g_b138A - 0x01), byte, 8));
	}
	struct Eq_n * hl_n = g_ptr1388;
	g_b1645 = g_b138A + 0x30;
	hl_n->wFFFFFFFE = 0x0231;
	hl_n->wFFFFFFFC = 0x1642;
	byte f_n = fn082F(f, 0x00, 0x5C, 0x10, hl_n->wFFFFFFFC, hl_n->wFFFFFFFE);
	hl_n->wFFFFFFFA = 0x5C;
	byte l_n;
	fn1326(0x07, fn1346(&g_w0108, &g_w0103), out l_n);
	struct Eq_n * hl_n = (struct Eq_n *) <invalid>;
	word16 hl_n = g_w0108;
	fn040D(SLICE(hl_n, byte, 8), (byte) hl_n, (byte) hl_n, hl_n->wFFFFFFFA);
	struct Eq_n * sp_n = (struct Eq_n *) <invalid>;
	sp_n->tFFFFFFFE.u1 = (byte *) SEQ(0x00 - (byte) (g_b138A < 0x01), f_n);
	if ((SLICE(0x03 - (uint16) g_b138A, byte, 8) | sp_n->b0003) >> 0x01 < 0x00)
		fn075C(0x00, 0x01, 0x00, 0x00);
	switch (g_b138A)
	{
	case 0x01:
		fn172D();
		return;
	case 0x02:
		fn177D();
		return;
	default:
		if (g_b138A != 0x03)
			return;
		fn1729();
		return;
	}
}

// 0C93: Register byte fn0C93()
// Called from:
//      fn0E63
byte fn0C93()
{
	return g_b138D + g_b138C + (&g_b138C)[(uint16) g_b138C] + 0x7F;
}

// 0D64: FlagGroup Eq_n fn0D64(Register out Eq_n aOut)
// Called from:
//      fn0D84
Eq_n fn0D64(union Eq_n & aOut)
{
	bcu8 a_n = g_t1521.u1->b0009;
	aOut = a_n >> 0x01;
	return cond(a_n >> 0x01);
}

// 0D6F: void fn0D6F()
void fn0D6F()
{
	Eq_n hl_n;
	hl_n.u1 = g_t1521.u1;
	hl_n.u1->b0009 |= 0x02;
}

// 0D84: void fn0D84()
void fn0D84()
{
	byte a_n;
	if (__rcr<byte,byte>(a_n, 0x01, fn0D64(out a_n)) < 0x00)
		fn075C(0x00, 0x02, 0x00, 0x00);
	Eq_n hl_n;
	hl_n.u1 = g_t1521.u1;
	hl_n.u1->b0009 |= 0x01;
}

// 0DB9: void fn0DB9()
void fn0DB9()
{
}

// 0DCB: void fn0DCB()
void fn0DCB()
{
	Eq_n hl_n;
	hl_n.u1 = g_t1521.u1;
	hl_n.u1->b0009 |= 0x08;
}

// 0E63: void fn0E63(Register byte c)
void fn0E63(byte c)
{
	g_b16A6 = c;
	union Eq_n * hl_n = (uint16) fn0C93() * 0x02 + 0x152C;
	g_t1521.u1 = hl_n->u1;
	while (true)
	{
		struct Eq_n * hl_n = (struct Eq_n *) <invalid>;
		byte l_n;
		if ((fn1353(0x00, &g_t1521, out l_n) | (byte) hl_n) == 0x00)
			break;
		byte a_n;
		if (g_b16A6 == (g_t1521.u1)->b0002 && __rcr<byte,byte>(a_n, 0x01, fn0EAB(out a_n)) < 0x00)
			return;
		Eq_n hl_n;
		hl_n.u1 = g_t1521.u1;
		g_t1521.u1 = (struct Eq_n *) *hl_n;
	}
}

// 0EAB: FlagGroup bool fn0EAB(Register out Eq_n aOut)
// Called from:
//      fn0E63
bool fn0EAB(union Eq_n & aOut)
{
	g_b16A7 = 0x00;
	bool C_n;
	while (true)
	{
		uint8 a_n = g_b138C;
		C_n = (bool) cond(a_n - g_b16A7);
		if (a_n < g_b16A7)
			break;
		struct Eq_n * hl_n = (uint16) g_b16A7;
		byte a_n = Mem24[Mem5[0x1521:word16] + (CONVERT(Mem5[5799:byte], uint8, uint16) + 0x0A):byte];
		bool C_n = (bool) cond(a_n - hl_n->b138C);
		if (a_n != hl_n->b138C)
		{
			aOut.u0 = 0x00;
			return C_n;
		}
		++g_b16A7;
	}
	aOut.u0 = 0x01;
	return C_n;
}

// 0FB8: void fn0FB8()
void fn0FB8()
{
}

// 100A: void fn100A(Register word16 af)
void fn100A(word16 af)
{
	uint8 f_n;
	while (true)
	{
		f_n = (byte) af;
		if ((0x00 - (byte) (g_b14FF < 0x0E) & (0x00 - (byte) (g_b16A8 < 0x01) & (0x00 - (byte) (g_b16A8 < ~0x02) & SLICE(af, byte, 8)))) >> 0x01 >= 0x00)
			break;
		cu8 a_n = g_b14FF;
		g_b14FF = a_n + 0x01;
		(&g_b14FF)[(uint16) (a_n + 0x01)] = g_b16A8;
		g_b16A8 = fn045B();
		af = SEQ(0x00 - (byte) (g_b16A8 < 33), f_n);
	}
	if (g_b14FF == 0x00)
	{
		fn05CE(0x0369);
		fn0387();
	}
	while ((0x00 - (byte) (g_b16A8 < 0x01) & 0x00 - (byte) (g_b16A8 < ~0x02)) >> 0x01 < 0x00)
		g_b16A8 = fn045B();
	g_b16A8 = fn045B();
	byte a_n;
	word16 bc_n;
	while (true)
	{
		a_n = 0x00 - (byte) (g_b16A8 < ~0x00);
		bc_n = SEQ(a_n, a_n);
		if ((0x00 - (byte) (g_b16A8 < 0x01) & a_n) >> 0x01 >= 0x00)
			break;
		if (g_b16A8 == 0x20)
			fn1262();
		switch (g_b16A8)
		{
		case 66:
			g_b14F3 = 0x00;
			break;
		case 0x43:
			word16 af_n = fn12D8();
			g_b151D = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		case 0x44:
			word16 af_n = fn1279();
			g_b138B = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		case 0x46:
			g_b14F3 = 0x04;
			break;
		case 0x49:
			g_b14FA = 0x01;
			break;
		case 0x4C:
			word16 af_n = fn1279();
			g_b14F7 = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		case 0x4E:
			g_b14FB = 0x01;
			break;
		case 0x4F:
			g_b14EF = 0x00;
			break;
		case 0x50:
			g_b14F3 = 0x01;
			break;
		case 0x52:
			word16 af_n = fn12D8();
			g_b1520 = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		case 0x53:
			g_b14F0 = 0x01;
			break;
		case 0x54:
			g_b14F5 = 0x01;
			break;
		case 0x55:
			g_b1529 = 0x01;
			break;
		case 0x56:
			g_b14FC = 0x01;
			break;
		case 0x57:
			word16 af_n = fn1279();
			g_b14F8 = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		case 88:
			word16 af_n = fn12D8();
			g_b151E = SLICE(af_n, byte, 8);
			f_n = (byte) af_n;
			break;
		default:
			fn1229();
			break;
		}
		g_b16A8 = fn045B();
		fn1262();
		switch (g_b16A8)
		{
		case 44:
			g_b16A8 = fn045B();
			break;
		case ~0x01:
			g_b16A8 = fn045B();
			fn1262();
			if (g_b16A8 != 252)
				g_b16A8 = 0x5D;
			else
				g_b16A8 = fn045B();
			break;
		}
	}
	if (g_b14F3 == 0x01)
	{
		fn056B(SEQ(a_n, 0x0C), out bc_n);
		g_b14F9 = 0x01;
	}
	g_b14F4 = g_b14F3;
	g_b14FD = g_b14F7 + 0x01;
	g_b138A = 0x01;
	fn07B3((byte) bc_n);
	fn0BE4(f_n);
	__ei();
	__halt();
}

// 1229: void fn1229()
// Called from:
//      fn100A
//      fn1279
//      fn12D8
void fn1229()
{
	g_b14F3 = 0x02;
	byte b_n = SLICE((uint16) fn05CE(0x02D1), byte, 8);
	if (g_b16A8 != 0x00)
	{
		word16 bc_n;
		fn056B(SEQ(b_n, 0x3E), out bc_n);
		word16 bc_n;
		fn056B(SEQ(SLICE(bc_n, byte, 8), 0x20), out bc_n);
		while (true)
		{
			byte b_n = SLICE(bc_n, byte, 8);
			if (g_b16A8 == 0x00)
				break;
			fn056B(SEQ(b_n, g_b16A8), out bc_n);
			g_b16A8 = fn045B();
		}
	}
	fn0387();
}

// 1262: void fn1262()
// Called from:
//      fn100A
//      fn1279
//      fn12D8
void fn1262()
{
	if (g_b16A8 == 0x20)
	{
		cu8 a_n;
		do
		{
			a_n = fn045B();
			g_b16A8 = a_n;
		} while (a_n == 0x20);
	}
}

// 1279: Register word16 fn1279()
// Called from:
//      fn100A
word16 fn1279()
{
	g_b16A8 = fn045B();
	fn1262();
	if (g_b16A8 != 0x28)
		fn1229();
	g_b16AA = 0x00;
	while (true)
	{
		cu8 a_n = fn045B();
		g_b16A9 = a_n;
		if (a_n > 0x39 || a_n < 0x30)
			break;
		g_b16AA = g_b16A9 + 0x0F + (g_b16AA * 0x02 + g_b16AA * 0x08);
	}
	if (g_b16A9 == 0x20)
		fn1262();
	if (g_b16A9 != 0x29)
		fn1229();
	byte f;
	return SEQ(g_b16AA, f);
}

// 12D8: Register word16 fn12D8()
// Called from:
//      fn100A
word16 fn12D8()
{
	g_b16A8 = fn045B();
	fn1262();
	if (g_b16A8 == 0x28)
		g_b16AB = fn045B() + 0x1F;
	else
		fn1229();
	if ((SLICE(0x10 - (uint16) g_b16AB, byte, 8) | 0x00 - (byte) (fn045B() < 0x2A)) >> 0x01 < 0x00)
		fn1229();
	byte f;
	return SEQ(g_b16AB, f);
}

// 1315: void fn1315()
void fn1315()
{
}

// 1326: Register byte fn1326(Register byte c, Register uint16 hl, Register out Eq_n lOut)
// Called from:
//      fn0483
//      fn0BE4
byte fn1326(byte c, uint16 hl, union Eq_n & lOut)
{
	uint16 hl_n = hl;
	Eq_n l_n;
	do
	{
		uint16 v12_n = hl_n >> 0x01;
		l_n = (byte) v12_n;
		--c;
		hl_n = v12_n;
	} while (c != 0x00);
	lOut = l_n;
	return c;
}

// 1335: FlagGroup bool fn1335(Register word16 de, Register word16 hl)
// Called from:
//      fn0534
bool fn1335(word16 de, word16 hl)
{
	return (bool) cond(SLICE(de - hl, byte, 8));
}

// 133C: void fn133C()
void fn133C()
{
}

// 1346: Register word16 fn1346(Register (ptr16 ui16) bc, Register (ptr16 ui16) de)
// Called from:
//      fn0BE4
word16 fn1346(ui16 * bc, ui16 * de)
{
	word16 de_n;
	word16 hl_n;
	fn1348(de, bc, out de_n, out hl_n);
	return hl_n;
}

// 1348: FlagGroup bool fn1348(Register (ptr16 ui16) de, Register (ptr16 ui16) hl, Register out ptr16 deOut, Register out Eq_n hlOut)
// Called from:
//      fn063E
//      fn1346
bool fn1348(ui16 * de, ui16 * hl, ptr16 & deOut, union Eq_n & hlOut)
{
	Eq_n a_a_n = *de - *hl;
	deOut = (char *) de + 1;
	hlOut = a_a_n;
	return (bool) cond(SLICE(a_a_n, byte, 8));
}

// 1353: Register uint8 fn1353(Register uint8 a, Register (ptr16 byte) de, Register out Eq_n lOut)
// Called from:
//      fn075C
//      fn0E63
uint8 fn1353(uint8 a, byte * de, union Eq_n & lOut)
{
	uint16 hl_n = (uint16) a;
	fn1356(de, hl_n);
	lOut.u1 = (<unknown>*) <invalid>;
	uint8 a_n;
	return a_n;
}

// 1356: Register byte fn1356(Register (ptr16 byte) de, Register uint16 hl)
// Called from:
//      fn1353
byte fn1356(byte * de, uint16 hl)
{
	return *de - (byte) hl;
}

struct Eq_n * g_ptr1388 = null; // 1388
uint8 g_b138A = 0x00; // 138A
byte g_b138B = 0x00; // 138B
uint8 g_b138C = 0x00; // 138C
byte g_b138D = 0x00; // 138D
// 140B: void fn140B(Register byte a)
void fn140B(byte a)
{
	null = (byte *) a;
	fn156F();
}

ptr16 g_ptr14BC = 0x00; // 14BC
int16 g_w14BE = 0; // 14BE
byte g_b14EF = 0x01; // 14EF
byte g_b14F0 = 0x00; // 14F0
cu8 g_b14F3 = 0x02; // 14F3
cu8 g_b14F4 = 0x00; // 14F4
byte g_b14F5 = 0x00; // 14F5
cu8 g_b14F6 = 0x01; // 14F6
cu8 g_b14F7 = 66; // 14F7
byte g_b14F8 = 0x50; // 14F8
byte g_b14F9 = 0x00; // 14F9
byte g_b14FA = 0x00; // 14FA
byte g_b14FB = 0x00; // 14FB
byte g_b14FC = 0x00; // 14FC
cu8 g_b14FD = 0x00; // 14FD
Eq_n g_t14FE = // 14FE
	{
		0x01
	};
cu8 g_b14FF = 0x00; // 14FF
cu8 g_b151D = 0x00; // 151D
cu8 g_b151E = 0x00; // 151E
cu8 g_b151F = 0x00; // 151F
cu8 g_b1520 = 0x00; // 1520
Eq_n g_t1521 = // 1521
	{
		0x00
	};
byte g_b1529 = 0x00; // 1529
// 156F: void fn156F()
// Called from:
//      fn140B
void fn156F()
{
	fn15B0();
}

// 15B0: void fn15B0()
// Called from:
//      fn156F
void fn15B0()
{
	__halt();
}

word16 g_w1640 = 0x00; // 1640
byte g_b1645 = 0x30; // 1645
<anonymous> * g_ptr1648 = null; // 1648
struct Eq_n * g_ptr164E = &g_t1A1A; // 164E
byte g_b1653 = 0x1A; // 1653
Eq_n g_t1654 = // 1654
	{
		0x1A
	};
byte g_b1655 = 0x1A; // 1655
byte g_b1656 = 0x1A; // 1656
Eq_n g_t1657 = // 1657
	{
		0x1A
	};
Eq_n g_t1658 = // 1658
	{
		0x1A
	};
Eq_n g_t1659 = // 1659
	{
		0x1A
	};
Eq_n g_t165A = // 165A
	{
		0x1A
	};
byte g_b165B = 0x1A; // 165B
Eq_n g_t165C = // 165C
	{
		0x1A
	};
byte g_b165D = 0x1A; // 165D
cu8 g_b165E = 0x1A; // 165E
char g_b165F = '\x1A'; // 165F
Eq_n g_t1660 = // 1660
	{
		0x1A
	};
byte g_b1661 = 0x1A; // 1661
Eq_n g_t1662 = // 1662
	{
		0x1A
	};
byte g_b1663 = 0x1A; // 1663
Eq_n g_t1664 = // 1664
	{
		0x1A
	};
byte g_b1665 = 0x1A; // 1665
cu8 g_b1667 = 0x1A; // 1667
char * g_ptr1668 = &g_str1A1A; // 1668
char g_b166A = '\x1A'; // 166A
char g_b166B = '\x1A'; // 166B
char g_b166C = '\x1A'; // 166C
Eq_n g_t166D = // 166D
	{
		0x1A
	};
byte g_b166E = 0x1A; // 166E
Eq_n g_t166F = // 166F
	{
		0x1A
	};
byte g_b1670 = 0x1A; // 1670
uint8 g_b1671 = 0x1A; // 1671
Eq_n g_t1672 = // 1672
	{
		0x1A
	};
byte g_b1673 = 0x1A; // 1673
Eq_n g_t1674 = // 1674
	{
		0x1A
	};
byte g_b1675 = 0x1A; // 1675
Eq_n g_t1676 = // 1676
	{
		0x1A
	};
byte g_b1677 = 0x1A; // 1677
Eq_n g_t1678 = // 1678
	{
		0x1A
	};
byte g_b1679 = 0x1A; // 1679
uint8 g_b167A = 0x1A; // 167A
byte g_b167B = 0x1A; // 167B
byte g_b167C = 0x1A; // 167C
Eq_n g_t167D = // 167D
	{
		0x1A
	};
byte g_b167E = 0x1A; // 167E
cu8 g_b1681 = ~0x13; // 1681
cu8 g_b1682 = 0x08; // 1682
Eq_n g_t1683 = // 1683
	{
		~0x25
	};
byte g_b1684 = 0x94; // 1684
Eq_n g_t1685 = // 1685
	{
		0x14
	};
byte g_b1686 = ~0x32; // 1686
Eq_n g_t1687 = // 1687
	{
		11
	};
byte g_b1688 = 0x14; // 1688
Eq_n g_t1689 = // 1689
	{
		0x2A
	};
byte g_b168A = 0x52; // 168A
Eq_n g_t168B = // 168B
	{
		0x17
	};
byte g_b168C = ~0x14; // 168C
byte g_b168D = 0x3E; // 168D
byte g_b168E = 0x82; // 168E
byte g_b168F = ~0x48; // 168F
byte g_b1690 = 55; // 1690
byte g_b1691 = 0xC3; // 1691
Eq_n g_t1692 = // 1692
	{
		0x2A
	};
byte g_b1693 = 0x09; // 1693
Eq_n g_t1694 = // 1694
	{
		0x3A
	};
byte g_b1695 = 0x25; // 1695
Eq_n g_t1696 = // 1696
	{
		0x17
	};
uint8 g_b1697 = ~0x48; // 1697
byte g_b16A6 = 0x23; // 16A6
uint8 g_b16A7 = 0x7E; // 16A7
cu8 g_b16A8 = 0x23; // 16A8
cu8 g_b16A9 = 0x56; // 16A9
bui8 g_b16AA = 0x2A; // 16AA
uint8 g_b16AB = 229; // 16AB
