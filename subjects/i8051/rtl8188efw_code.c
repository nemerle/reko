// rtl8188efw_code.c
// Generated by decompiling rtl8188efw.bin
// using Reko decompiler version 0.11.6.0.

#include "rtl8188efw.h"

// 0000: void fn0000(Register (ptr16 Eq_n) __data)
void fn0000(struct Eq_n * __data)
{
	__data->b001D = 0x00;
	fn4EF3();
	selector __data_n;
	__data_n->b0157 = 0x05;
	if ((__data_n->b80EA >> 0x02 & 0x01) == 0x00)
		fn4AC0();
}

