// strcpyEcxChain_code.c
// Generated by decompiling strcpyEcxChain.bin
// using Reko decompiler version 0.11.6.0.

#include "strcpyEcxChain.h"

// 12340000: void fn12340000(Register (ptr32 char) ecx)
void fn12340000(char * ecx)
{
	strcpy(&g_b12340034, ecx);
}

char g_b12340034 = 's'; // 12340034
