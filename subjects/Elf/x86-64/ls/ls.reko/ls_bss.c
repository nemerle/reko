// ls_bss.c
// Generated by decompiling ls
// using Reko decompiler version 0.11.5.0.

#include "ls.h"

char * __progname = &g_strC34C00; // 000000000061A600
FILE * stdout = &g_tC34C10; // 000000000061A610
word32 g_dw61A620 = 0x00C34C20; // 000000000061A620
Eq_n optarg = // 000000000061A640
	{
		0x40
	};
Eq_n __progname_full = // 000000000061A648
	{
		0x48
	};
FILE * stderr = &g_tC34C50; // 000000000061A650
Eq_n g_t61A660 = // 000000000061A660
	{
		0x00
	};
word64 g_qw61A668 = 0x00; // 000000000061A668
word64 g_qw61A670 = 0x00; // 000000000061A670
word64 g_qw61A678 = 0x00; // 000000000061A678
struct jmp_buf g_t61A680 = // 000000000061A680
	{
		0x00,
	};
up64 g_qw61A748 = 0x00; // 000000000061A748
Eq_n g_t61A760 = // 000000000061A760
	{
		0x00,
		0x00,
	};
Eq_n g_t61AF00 = // 000000000061AF00
	{
	};
up32 g_dw61AF10 = 0x00; // 000000000061AF10
Eq_n g_t61AF18 = // 000000000061AF18
	{
		0x00
	};
int64 g_qw61AF20 = 0; // 000000000061AF20
Eq_n g_t61AF60 = // 000000000061AF60
	{
	};
Eq_n g_t61AF78 = // 000000000061AF78
	{
		0x00
	};
word64 * g_ptr61AF80 = null; // 000000000061AF80
Eq_n g_t61AFC0 = // 000000000061AFC0
	{
	};
Eq_n g_t61B018 = // 000000000061B018
	{
		0x00
	};
Eq_n g_t61B020 = // 000000000061B020
	{
		0x00
	};
Eq_n g_t61B028 = // 000000000061B028
	{
		0x00
	};
int32 g_dw61B030 = 0; // 000000000061B030
word32 g_dw61B034 = 0x00; // 000000000061B034
int32 g_dw61B038 = 0; // 000000000061B038
Eq_n g_t61B040 = // 000000000061B040
	{
		0x00,
	};
byte g_b61B0C0 = 0x00; // 000000000061B0C0
byte g_b61B0C1 = 0x00; // 000000000061B0C1
Eq_n g_t61B0C8 = // 000000000061B0C8
	{
		0x00
	};
byte g_b61B0D0 = 0x00; // 000000000061B0D0
uint64 g_qw61B0D8 = 0x00; // 000000000061B0D8
struct Eq_n * g_ptr61B0E0 = null; // 000000000061B0E0
struct Eq_n * g_ptr61B0E8 = null; // 000000000061B0E8
byte g_b61B0F0 = 0x00; // 000000000061B0F0
Eq_n g_t61B0F8 = // 000000000061B0F8
	{
		0x00
	};
Eq_n g_t61B100 = // 000000000061B100
	{
		0x00
	};
word32 g_dw61B108 = 0x00; // 000000000061B108
byte g_b61B10C = 0x00; // 000000000061B10C
byte g_b61B10D = 0x00; // 000000000061B10D
byte g_b61B10E = 0x00; // 000000000061B10E
uint32 g_dw61B110 = 0x00; // 000000000061B110
byte g_b61B114 = 0x00; // 000000000061B114
byte g_b61B115 = 0x00; // 000000000061B115
Eq_n g_t61B118 = // 000000000061B118
	{
		0x00
	};
Eq_n g_t61B120 = // 000000000061B120
	{
		0x00
	};
byte g_b61B128 = 0x00; // 000000000061B128
byte g_b61B129 = 0x00; // 000000000061B129
up32 g_dw61B12C = 0x00; // 000000000061B12C
byte g_b61B130 = 0x00; // 000000000061B130
ui32 g_dw61B134 = 0x00; // 000000000061B134
Eq_n g_t61B138 = // 000000000061B138
	{
		0
	};
ui32 g_dw61B140 = 0x00; // 000000000061B140
byte g_b61B144 = 0x00; // 000000000061B144
byte g_b61B145 = 0x00; // 000000000061B145
byte g_b61B146 = 0x00; // 000000000061B146
byte g_b61B147 = 0x00; // 000000000061B147
word32 g_dw61B148 = 0x00; // 000000000061B148
up32 g_dw61B14C = 0x00; // 000000000061B14C
up32 g_dw61B150 = 0x00; // 000000000061B150
int32 g_dw61B154 = 0; // 000000000061B154
int32 g_dw61B158 = 0; // 000000000061B158
int32 g_dw61B15C = 0; // 000000000061B15C
int32 g_dw61B160 = 0; // 000000000061B160
int32 g_dw61B164 = 0; // 000000000061B164
int32 g_dw61B168 = 0; // 000000000061B168
int32 g_dw61B16C = 0; // 000000000061B16C
int32 g_dw61B170 = 0; // 000000000061B170
int32 g_dw61B174 = 0; // 000000000061B174
int32 g_dw61B178 = 0; // 000000000061B178
byte g_b61B17C = 0x00; // 000000000061B17C
byte g_b61B17D = 0x00; // 000000000061B17D
int64 g_qw61B180 = 0; // 000000000061B180
Eq_n g_t61B188 = // 000000000061B188
	{
		0
	};
Eq_n g_t61B190 = // 000000000061B190
	{
		0x00
	};
byte g_b61B198 = 0x00; // 000000000061B198
uint64 g_qw61B1A0 = 0x00; // 000000000061B1A0
Eq_n g_t61B1A8 = // 000000000061B1A8
	{
		0x00
	};
Eq_n g_t61B1B0 = // 000000000061B1B0
	{
		0x00
	};
Eq_n g_t61B1B8 = // 000000000061B1B8
	{
		0x00
	};
Eq_n g_t61B1C0 = // 000000000061B1C0
	{
		0x00
	};
struct Eq_n * g_ptr61B1C8 = null; // 000000000061B1C8
Eq_n g_t61B1E8 = // 000000000061B1E8
	{
		0x00
	};
Eq_n g_t61B1F8 = // 000000000061B1F8
	{
		0x00
	};
Eq_n g_t61B200 = // 000000000061B200
	{
		0x00
	};
word64 g_qw61B320 = 0x00; // 000000000061B320
word64 g_qw61B328 = 0x00; // 000000000061B328
word64 g_qw61B330 = 0x00; // 000000000061B330
word64 g_qw61B338 = 0x00; // 000000000061B338
word64 g_qw61B340 = 0x00; // 000000000061B340
word64 g_qw61B348 = 0x00; // 000000000061B348
word64 g_qw61B350 = 0x00; // 000000000061B350
struct Eq_n * g_ptr61B358 = null; // 000000000061B358
