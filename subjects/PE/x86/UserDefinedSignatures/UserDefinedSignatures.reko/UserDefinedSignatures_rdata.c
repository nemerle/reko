// UserDefinedSignatures_rdata.c
// Generated by decompiling UserDefinedSignatures.exe
// using Reko decompiler version 0.11.4.0.

#include "UserDefinedSignatures.h"

<anonymous> * __imp__SetUnhandledExceptionFilter = &g_t2538; // 00402000
<anonymous> * __imp__UnhandledExceptionFilter = &g_t251C; // 00402004
<anonymous> * __imp__GetCurrentProcess = &g_t2508; // 00402008
<anonymous> * __imp__TerminateProcess = &g_t24F4; // 0040200C
<anonymous> * __imp__GetSystemTimeAsFileTime = &g_t24DA; // 00402010
<anonymous> * __imp__GetCurrentProcessId = &g_t24C4; // 00402014
<anonymous> * __imp__GetCurrentThreadId = &g_t24AE; // 00402018
<anonymous> * __imp__GetTickCount = &g_t249E; // 0040201C
<anonymous> * __imp__QueryPerformanceCounter = &g_t2484; // 00402020
<anonymous> * __imp__InterlockedCompareExchange = &g_t2466; // 00402024
<anonymous> * __imp__Sleep = &g_t245E; // 00402028
<anonymous> * __imp__InterlockedExchange = &g_t2448; // 0040202C
<anonymous> * __imp__IsDebuggerPresent = &g_t2556; // 00402030
<anonymous> * __imp___configthreadlocale = &g_t233E; // 00402038
<anonymous> * __imp____setusermatherr = &g_t2354; // 0040203C
<anonymous> * __imp___adjust_fdiv = &g_t2368; // 00402040
<anonymous> * __imp____p__commode = &g_t2378; // 00402044
<anonymous> * __imp____p__fmode = &g_t2388; // 00402048
<anonymous> * __imp___encode_pointer = &g_t2396; // 0040204C
<anonymous> * __imp____set_app_type = &g_t23A8; // 00402050
<anonymous> * __imp___initterm_e = &g_t2330; // 00402054
<anonymous> * __imp____dllonexit = &g_t23C4; // 00402058
<anonymous> * __imp___lock = &g_t23D2; // 0040205C
<anonymous> * __imp___onexit = &g_t23DA; // 00402060
<anonymous> * __imp___decode_pointer = &g_t23E4; // 00402064
<anonymous> * __imp___except_handler4_common = &g_t23F6; // 00402068
<anonymous> * __imp___invoke_watson = &g_t2410; // 0040206C
<anonymous> * __imp___controlfp_s = &g_t2422; // 00402070
<anonymous> * __imp___crt_debugger_hook = &g_t2432; // 00402074
<anonymous> * __imp___initterm = &g_t2324; // 00402078
<anonymous> * __imp____initenv = &g_t2318; // 0040207C
<anonymous> * __imp__exit = &g_t2310; // 00402080
<anonymous> * __imp___XcptFilter = &g_t2302; // 00402084
<anonymous> * __imp___exit = &g_t22FA; // 00402088
<anonymous> * __imp___cexit = &g_t22F0; // 0040208C
<anonymous> * __imp____getmainargs = &g_t22E0; // 00402090
<anonymous> * __imp___amsg_exit = &g_t22D2; // 00402094
<anonymous> * __imp__strcmp = &g_t22BC; // 00402098
<anonymous> * __imp__atoi = &g_t22B4; // 0040209C
<anonymous> * __imp__atof = &g_t22AC; // 004020A0
<anonymous> * __imp__free = &g_t22A4; // 004020A4
<anonymous> * __imp___unlock = &g_t23BA; // 004020A8
<anonymous> * __imp__??2@YAPAXI@Z = &g_t2294; // 004020AC
char g_str4020D0[] = "i32"; // 004020D0
char g_str4020D4[] = "r32"; // 004020D4
char g_str4020D8[] = "r64"; // 004020D8
word32 g_dw4021E0 = 0x2538; // 004021E0
word32 g_dw4021E4 = 9500; // 004021E4
word32 g_dw4021E8 = 0x2508; // 004021E8
word32 g_dw4021EC = 0x24F4; // 004021EC
word32 g_dw4021F0 = 9434; // 004021F0
word32 g_dw4021F4 = 0x24C4; // 004021F4
word32 g_dw4021F8 = 9390; // 004021F8
word32 g_dw4021FC = 0x249E; // 004021FC
word32 g_dw402200 = 0x2484; // 00402200
word32 g_dw402204 = 0x2466; // 00402204
word32 g_dw402208 = 0x245E; // 00402208
word32 g_dw40220C = 0x2448; // 0040220C
word32 g_dw402210 = 0x2556; // 00402210
word32 g_dw402218 = 0x233E; // 00402218
word32 g_dw40221C = 9044; // 0040221C
word32 g_dw402220 = 0x2368; // 00402220
word32 g_dw402224 = 9080; // 00402224
word32 g_dw402228 = 0x2388; // 00402228
word32 g_dw40222C = 9110; // 0040222C
word32 g_dw402230 = 0x23A8; // 00402230
word32 g_dw402234 = 0x2330; // 00402234
word32 g_dw402238 = 0x23C4; // 00402238
word32 g_dw40223C = 0x23D2; // 0040223C
word32 g_dw402240 = 0x23DA; // 00402240
word32 g_dw402244 = 9188; // 00402244
word32 g_dw402248 = 0x23F6; // 00402248
word32 g_dw40224C = 9232; // 0040224C
word32 g_dw402250 = 0x2422; // 00402250
word32 g_dw402254 = 0x2432; // 00402254
word32 g_dw402258 = 0x2324; // 00402258
word32 g_dw40225C = 8984; // 0040225C
word32 g_dw402260 = 0x2310; // 00402260
word32 g_dw402264 = 0x2302; // 00402264
word32 g_dw402268 = 0x22FA; // 00402268
word32 g_dw40226C = 0x22F0; // 0040226C
word32 g_dw402270 = 0x22E0; // 00402270
word32 g_dw402274 = 0x22D2; // 00402274
word32 g_dw402278 = 0x22BC; // 00402278
word32 g_dw40227C = 8884; // 0040227C
word32 g_dw402280 = 0x22AC; // 00402280
word32 g_dw402284 = 8868; // 00402284
word32 g_dw402288 = 0x23BA; // 00402288
word32 g_dw40228C = 0x2294; // 0040228C
