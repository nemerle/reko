// test.h
// Generated by decompiling test
// using Reko decompiler version 0.11.6.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals"
		(FFFFFFFF code tFFFFFFFF)
		(0 code t0000)
		(A58 word32 _IO_stdin_used)
		(10A60 (ptr32 code) ptr10A60)
		(10A68 <unknown> t10A68)
		(10A98 (ptr32 code) main_GOT)
		(10A9C (ptr32 code) __libc_csu_init_GOT)
		(10AA0 (ptr32 code) __libc_csu_fini_GOT)
		(10AA4 Eq_47 t10AA4)
		(10AAC (ptr32 word32) ptr10AAC)
		(10AB0 int32 dw10AB0)
		(10AB4 ptr32 ptr10AB4)
		(10AB8 (ptr32 code) _init_GOT)
		(10ABC (ptr32 (ptr32 code)) ptr10ABC)
		(10AD0 (ptr32 code) calloc_GOT)
		(10AD4 (ptr32 code) ptr10AD4)
		(10AD8 (ptr32 code) memset_GOT)
		(10ADC (ptr32 code) __libc_start_main_GOT)
		(10AE0 (ptr32 code) __gmon_start___GOT)
		(10AE4 (ptr32 code) ptr10AE4)
		(10AE8 (ptr32 code) __cxa_finalize_GOT)
		(10AEC word32 dw10AEC)
		(10AF0 byte b10AF0)
		(10AF4 Eq_84 dtor_idx.6258))
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_15: (fn void ())
	T_15 (in __gmon_start__ @ 000005B0 : ptr32)
Eq_23: (union "Eq_23" (ui32 u0) (ptr32 u1))
	T_23 (in fp @ 00000640 : Eq_23)
Eq_27: (struct "Eq_27" (10 word32 dw0010) (14 word32 dw0014) (18 (ptr32 Eq_27) ptr0018))
	T_27 (in (fp & -8<i32>) + -32<i32> @ 00000640 : word32)
	T_28 (in sp_17 @ 00000640 : (ptr32 Eq_27))
	T_43 (in Mem23[sp_17 + 0x18<32>:word32] @ 00000654 : word32)
Eq_47: (union "Eq_47" (int32 u0) (ptr32 u1))
	T_47 (in Mem0[0x10AA4<32>:word32] @ 00000688 : word32)
	T_48 (in 0x00010A84<p32> @ 00000688 : ptr32)
	T_56 (in Mem0[0x10AA4<32>:word32] @ 000006C4 : word32)
Eq_57: (union "Eq_57" (int32 u0) (ptr32 u1))
	T_57 (in 0x00010A84<p32> @ 000006C4 : ptr32)
Eq_60: (union "Eq_60" (int32 u0) (uint32 u1))
	T_60 (in g_t10AA4.u0 - 0x00010A84<p32> >> 2<8> @ 000006C4 : word32)
	T_61 (in r5_12 @ 000006C4 : Eq_60)
Eq_63: (union "Eq_63" (int32 u0) (uint32 u1))
	T_63 (in r5_12 >> 0x1F<8> @ 000006D4 : word32)
Eq_64: (union "Eq_64" (int32 u0) (uint32 u1))
	T_64 (in (r5_12 >>u 0x1F<8>) + r5_12 @ 000006D4 : word32)
Eq_84: (union "Eq_84" (int32 u0) (uint32 u1))
	T_84 (in Mem19[0x00010AF4<p32>:word32] @ 0000075C : word32)
	T_85 (in r2_40 @ 0000075C : Eq_84)
	T_93 (in (g_dw10AB0 - 0x00010A68<p32> >> 2<8>) + -1<i32> @ 00000764 : word32)
	T_94 (in r16_42 @ 00000764 : Eq_84)
	T_115 (in r2_40 + 1<i32> @ 00000774 : word32)
	T_116 (in r2_47 @ 00000774 : Eq_84)
	T_118 (in Mem50[0x00010AF4<p32>:word32] @ 0000077C : word32)
	T_128 (in Mem50[0x00010AF4<p32>:word32] @ 00000790 : word32)
	T_257
Eq_88: (union "Eq_88" (int32 u0) (ptr32 u1))
	T_88 (in 0x00010A68<p32> @ 00000764 : ptr32)
Eq_99: (fn void (word32))
	T_99 (in __cxa_finalize @ 00000738 : ptr32)
Eq_108: (fn void ())
	T_108 (in deregister_tm_clones @ 000007A8 : ptr32)
	T_109 (in signature of deregister_tm_clones @ 00000670 : void)
Eq_114: (union "Eq_114" (int32 u0) (up32 u1))
	T_114 (in 1<i32> @ 00000774 : int32)
Eq_133: (fn void ())
	T_133 (in register_tm_clones @ 000007E8 : ptr32)
	T_134 (in signature of register_tm_clones @ 000006A8 : void)
Eq_136: (fn (ptr32 void) ((ptr32 word32), int32, Eq_140))
	T_136 (in memset @ 00000830 : ptr32)
	T_137 (in signature of memset : void)
Eq_140: size_t
	T_140 (in num @ 00000830 : size_t)
	T_145 (in SLICE(5<i32>, size_t, 0) @ 00000830 : size_t)
	T_149 (in num @ 0000084C : size_t)
	T_150 (in size @ 0000084C : size_t)
	T_152 (in SLICE(1<i32>, size_t, 0) @ 0000084C : size_t)
	T_154 (in SLICE(5<i32>, size_t, 0) @ 0000084C : size_t)
Eq_155: (struct "Eq_155" (0 Eq_160 t0000) (1 word32 dw0001) (4 byte b0004))
	T_155 (in calloc((size_t) 1<i32>, (size_t) 5<i32>) @ 0000084C : (ptr32 void))
	T_156 (in r2_38 @ 0000084C : (ptr32 Eq_155))
	T_184 (in Mem58[&dwLoc14 + 1<i32>:word32] @ 0000089C : word32)
	T_189 (in r2_43 @ 0000085C : (ptr32 Eq_155))
	T_190 (in r2_52 @ 00000880 : (ptr32 Eq_155))
	T_191 (in r2_57 @ 00000894 : (ptr32 Eq_155))
Eq_160: (union "Eq_160" (byte u0) (word32 u1))
	T_160 (in Mem42[&dwLoc14 + 0<32>:word32] @ 00000868 : word32)
	T_163 (in Mem45[r2_38 + 0<32>:word32] @ 00000868 : word32)
	T_168 (in 0xC<8> @ 0000087C : byte)
	T_171 (in Mem51[r2_38 + 0<32>:byte] @ 0000087C : byte)
Eq_181: (struct "Eq_181" (0 word32 dw0000) (1 (ptr32 Eq_155) ptr0001))
	T_181 (in &dwLoc14 @ 0000089C : (ptr32 word32))
Eq_195: (fn void ())
	T_195 (in _init @ 000008FC : ptr32)
	T_196 (in signature of _init @ 00000588 : void)
Eq_234: (struct "Eq_234" (FFFF8010 (ptr32 code) ptrFFFF8010))
	T_234 (in r28 @ 000009B4 : (ptr32 Eq_234))
Eq_239: (struct "Eq_239" (FFFF8010 (ptr32 code) ptrFFFF8010))
	T_239 (in r28 @ 000009D8 : (ptr32 Eq_239))
Eq_244: (struct "Eq_244" (FFFF8010 (ptr32 code) ptrFFFF8010))
	T_244 (in r28 @ 000009E8 : (ptr32 Eq_244))
Eq_249: (fn void ())
	T_249 (in _fini @ 00000A0C : ptr32)
	T_250 (in signature of _fini @ 00000A10 : void)
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in __gmon_start__ @ 000005A4 : ptr32)
  Class: Eq_2
  DataType: word32
  OrigDataType: 
T_3: (in signature of __gmon_start__ : void)
  Class: Eq_3
  DataType: Eq_3
  OrigDataType: 
T_4: (in 0<32> @ 000005A4 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_5: (in __gmon_start__ == 0<32> @ 000005A4 : bool)
  Class: Eq_5
  DataType: bool
  OrigDataType: bool
T_6: (in 00010AB4 @ 000005CC : ptr32)
  Class: Eq_6
  DataType: (ptr32 ptr32)
  OrigDataType: (ptr32 (struct (0 T_7 t0000)))
T_7: (in Mem10[0x00010AB4<p32>:word32] @ 000005CC : word32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: word32
T_8: (in r25_16 @ 000005CC : ptr32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: ptr32
T_9: (in 2004<i32> @ 000005D4 : int32)
  Class: Eq_9
  DataType: int32
  OrigDataType: int32
T_10: (in r25_16 + 2004<i32> @ 000005D4 : word32)
  Class: Eq_10
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_11: (in Mem10[0x00010AB4<p32>:word32] @ 000005F0 : word32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: word32
T_12: (in r25_24 @ 000005F0 : ptr32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: ptr32
T_13: (in 2416<i32> @ 000005F8 : int32)
  Class: Eq_13
  DataType: int32
  OrigDataType: int32
T_14: (in r25_24 + 2416<i32> @ 000005F8 : word32)
  Class: Eq_14
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_15: (in __gmon_start__ @ 000005B0 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_17 ()))
T_16: (in signature of __gmon_start__ : void)
  Class: Eq_16
  DataType: Eq_16
  OrigDataType: 
T_17: (in __gmon_start__() @ 000005B0 : void)
  Class: Eq_17
  DataType: void
  OrigDataType: void
T_18: (in r2 @ 000005B0 : word32)
  Class: Eq_18
  DataType: word32
  OrigDataType: word32
T_19: (in dwArg00 @ 000005B0 : word32)
  Class: Eq_19
  DataType: word32
  OrigDataType: word32
T_20: (in 00010A98 @ 0000062C : ptr32)
  Class: Eq_20
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 T_21 t0000)))
T_21: (in Mem0[0x00010A98<p32>:word32] @ 0000062C : word32)
  Class: Eq_21
  DataType: word32
  OrigDataType: word32
T_22: (in r4_12 @ 0000062C : word32)
  Class: Eq_21
  DataType: word32
  OrigDataType: word32
T_23: (in fp @ 00000640 : Eq_23)
  Class: Eq_23
  DataType: Eq_23
  OrigDataType: (union (ui32 u1) (ptr32 u0))
T_24: (in -8<i32> @ 00000640 : int32)
  Class: Eq_24
  DataType: int32
  OrigDataType: int32
T_25: (in fp & -8<i32> @ 00000640 : word32)
  Class: Eq_25
  DataType: ui32
  OrigDataType: ui32
T_26: (in -32<i32> @ 00000640 : int32)
  Class: Eq_26
  DataType: int32
  OrigDataType: int32
T_27: (in (fp & -8<i32>) + -32<i32> @ 00000640 : word32)
  Class: Eq_27
  DataType: (ptr32 Eq_27)
  OrigDataType: ui32
T_28: (in sp_17 @ 00000640 : (ptr32 Eq_27))
  Class: Eq_27
  DataType: (ptr32 Eq_27)
  OrigDataType: (ptr32 (struct (10 T_37 t0010) (14 T_40 t0014) (18 T_43 t0018)))
T_29: (in 00010A9C @ 00000644 : ptr32)
  Class: Eq_29
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 T_30 t0000)))
T_30: (in Mem0[0x00010A9C<p32>:word32] @ 00000644 : word32)
  Class: Eq_30
  DataType: word32
  OrigDataType: word32
T_31: (in r7_18 @ 00000644 : word32)
  Class: Eq_30
  DataType: word32
  OrigDataType: word32
T_32: (in 00010AA0 @ 00000648 : ptr32)
  Class: Eq_32
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 T_33 t0000)))
T_33: (in Mem0[0x00010AA0<p32>:word32] @ 00000648 : word32)
  Class: Eq_33
  DataType: word32
  OrigDataType: word32
T_34: (in r8_19 @ 00000648 : word32)
  Class: Eq_33
  DataType: word32
  OrigDataType: word32
T_35: (in 0x10<32> @ 0000064C : word32)
  Class: Eq_35
  DataType: word32
  OrigDataType: word32
T_36: (in sp_17 + 0x10<32> @ 0000064C : word32)
  Class: Eq_36
  DataType: ui32
  OrigDataType: ui32
T_37: (in Mem20[sp_17 + 0x10<32>:word32] @ 0000064C : word32)
  Class: Eq_33
  DataType: word32
  OrigDataType: word32
T_38: (in 0x14<32> @ 00000650 : word32)
  Class: Eq_38
  DataType: word32
  OrigDataType: word32
T_39: (in sp_17 + 0x14<32> @ 00000650 : word32)
  Class: Eq_39
  DataType: ptr32
  OrigDataType: ptr32
T_40: (in Mem22[sp_17 + 0x14<32>:word32] @ 00000650 : word32)
  Class: Eq_18
  DataType: word32
  OrigDataType: word32
T_41: (in 0x18<32> @ 00000654 : word32)
  Class: Eq_41
  DataType: word32
  OrigDataType: word32
T_42: (in sp_17 + 0x18<32> @ 00000654 : word32)
  Class: Eq_42
  DataType: ptr32
  OrigDataType: ptr32
T_43: (in Mem23[sp_17 + 0x18<32>:word32] @ 00000654 : word32)
  Class: Eq_27
  DataType: (ptr32 Eq_27)
  OrigDataType: word32
T_44: (in 00010ADC @ 0000065C : ptr32)
  Class: Eq_44
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct (0 T_45 t0000)))
T_45: (in Mem23[0x00010ADC<p32>:word32] @ 0000065C : word32)
  Class: Eq_45
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_46: (in 0x10AA4<32> @ 00000688 : word32)
  Class: Eq_46
  DataType: (ptr32 Eq_47)
  OrigDataType: (ptr32 (struct (0 T_47 t0000)))
T_47: (in Mem0[0x10AA4<32>:word32] @ 00000688 : word32)
  Class: Eq_47
  DataType: Eq_47
  OrigDataType: word32
T_48: (in 0x00010A84<p32> @ 00000688 : ptr32)
  Class: Eq_47
  DataType: ptr32
  OrigDataType: ptr32
T_49: (in g_t10AA4.u0 == 0x00010A84<p32> @ 00000688 : bool)
  Class: Eq_49
  DataType: bool
  OrigDataType: bool
T_50: (in r25_12 @ 00000690 : (ptr32 code))
  Class: Eq_50
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_51: (in 0<32> @ 00000690 : word32)
  Class: Eq_50
  DataType: (ptr32 code)
  OrigDataType: word32
T_52: (in r25_12 == null @ 00000690 : bool)
  Class: Eq_52
  DataType: bool
  OrigDataType: bool
T_53: (in 0x10AE4<32> @ 0000068C : word32)
  Class: Eq_53
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct (0 T_54 t0000)))
T_54: (in Mem0[0x10AE4<32>:word32] @ 0000068C : word32)
  Class: Eq_50
  DataType: (ptr32 code)
  OrigDataType: word32
T_55: (in 0x10AA4<32> @ 000006C4 : word32)
  Class: Eq_55
  DataType: (ptr32 Eq_47)
  OrigDataType: (ptr32 (struct (0 T_56 t0000)))
T_56: (in Mem0[0x10AA4<32>:word32] @ 000006C4 : word32)
  Class: Eq_47
  DataType: Eq_47
  OrigDataType: int32
T_57: (in 0x00010A84<p32> @ 000006C4 : ptr32)
  Class: Eq_57
  DataType: int32
  OrigDataType: (union (int32 u0) (ptr32 u1))
T_58: (in g_t10AA4.u0 - 0x00010A84<p32> @ 000006C4 : word32)
  Class: Eq_58
  DataType: int32
  OrigDataType: int32
T_59: (in 2<8> @ 000006C4 : byte)
  Class: Eq_59
  DataType: byte
  OrigDataType: byte
T_60: (in g_t10AA4.u0 - 0x00010A84<p32> >> 2<8> @ 000006C4 : word32)
  Class: Eq_60
  DataType: Eq_60
  OrigDataType: int32
T_61: (in r5_12 @ 000006C4 : Eq_60)
  Class: Eq_60
  DataType: Eq_60
  OrigDataType: (union (int32 u1) (uint32 u0))
T_62: (in 0x1F<8> @ 000006D4 : byte)
  Class: Eq_62
  DataType: byte
  OrigDataType: byte
T_63: (in r5_12 >> 0x1F<8> @ 000006D4 : word32)
  Class: Eq_63
  DataType: Eq_63
  OrigDataType: (union (int32 u1) (uint32 u0))
T_64: (in (r5_12 >>u 0x1F<8>) + r5_12 @ 000006D4 : word32)
  Class: Eq_64
  DataType: Eq_64
  OrigDataType: (union (int32 u1) (uint32 u0))
T_65: (in 1<8> @ 000006D4 : byte)
  Class: Eq_65
  DataType: byte
  OrigDataType: byte
T_66: (in (r5_12 >>u 0x1F<8>) + r5_12 >> 1<8> @ 000006D4 : word32)
  Class: Eq_66
  DataType: int32
  OrigDataType: int32
T_67: (in 0<32> @ 000006D4 : word32)
  Class: Eq_66
  DataType: int32
  OrigDataType: word32
T_68: (in (r5_12 >>u 0x1F<8>) + r5_12 >> 1<8> == 0<32> @ 000006D4 : bool)
  Class: Eq_68
  DataType: bool
  OrigDataType: bool
T_69: (in 0x10AD4<32> @ 000006D8 : word32)
  Class: Eq_69
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct (0 T_70 t0000)))
T_70: (in Mem0[0x10AD4<32>:word32] @ 000006D8 : word32)
  Class: Eq_70
  DataType: (ptr32 code)
  OrigDataType: word32
T_71: (in r25_17 @ 000006D8 : (ptr32 code))
  Class: Eq_70
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_72: (in 0<32> @ 000006DC : word32)
  Class: Eq_70
  DataType: (ptr32 code)
  OrigDataType: word32
T_73: (in r25_17 == null @ 000006DC : bool)
  Class: Eq_73
  DataType: bool
  OrigDataType: bool
T_74: (in 0x00010AF0<p32> @ 00000724 : ptr32)
  Class: Eq_74
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_75 t0000)))
T_75: (in Mem19[0x00010AF0<p32>:byte] @ 00000724 : byte)
  Class: Eq_75
  DataType: byte
  OrigDataType: byte
T_76: (in CONVERT(Mem19[0x00010AF0<p32>:byte], byte, word32) @ 00000724 : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_77: (in 0<32> @ 00000724 : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_78: (in (word32) g_b10AF0 != 0<32> @ 00000724 : bool)
  Class: Eq_78
  DataType: bool
  OrigDataType: bool
T_79: (in __cxa_finalize @ 0000072C : ptr32)
  Class: Eq_79
  DataType: word32
  OrigDataType: 
T_80: (in signature of __cxa_finalize : void)
  Class: Eq_80
  DataType: Eq_80
  OrigDataType: 
T_81: (in 0<32> @ 0000072C : word32)
  Class: Eq_79
  DataType: word32
  OrigDataType: word32
T_82: (in __cxa_finalize == 0<32> @ 0000072C : bool)
  Class: Eq_82
  DataType: bool
  OrigDataType: bool
T_83: (in 0x00010AF4<p32> @ 0000075C : ptr32)
  Class: Eq_83
  DataType: (ptr32 Eq_84)
  OrigDataType: (ptr32 (struct (0 T_84 t0000)))
T_84: (in Mem19[0x00010AF4<p32>:word32] @ 0000075C : word32)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: word32
T_85: (in r2_40 @ 0000075C : Eq_84)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: up32
T_86: (in 0x10AB0<32> @ 00000764 : word32)
  Class: Eq_86
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_87 t0000)))
T_87: (in Mem19[0x10AB0<32>:word32] @ 00000764 : word32)
  Class: Eq_87
  DataType: int32
  OrigDataType: int32
T_88: (in 0x00010A68<p32> @ 00000764 : ptr32)
  Class: Eq_88
  DataType: int32
  OrigDataType: (union (int32 u0) (ptr32 u1))
T_89: (in g_dw10AB0 - 0x00010A68<p32> @ 00000764 : word32)
  Class: Eq_89
  DataType: int32
  OrigDataType: int32
T_90: (in 2<8> @ 00000764 : byte)
  Class: Eq_90
  DataType: byte
  OrigDataType: byte
T_91: (in g_dw10AB0 - 0x00010A68<p32> >> 2<8> @ 00000764 : word32)
  Class: Eq_91
  DataType: int32
  OrigDataType: int32
T_92: (in -1<i32> @ 00000764 : int32)
  Class: Eq_92
  DataType: int32
  OrigDataType: int32
T_93: (in (g_dw10AB0 - 0x00010A68<p32> >> 2<8>) + -1<i32> @ 00000764 : word32)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: int32
T_94: (in r16_42 @ 00000764 : Eq_84)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: (union (int32 u0) (up32 u1))
T_95: (in r2_40 < r16_42 @ 0000076C : bool)
  Class: Eq_95
  DataType: bool
  OrigDataType: bool
T_96: (in CONVERT(r2_40 <u r16_42, bool, word32) @ 0000076C : word32)
  Class: Eq_96
  DataType: word32
  OrigDataType: word32
T_97: (in 0<32> @ 0000076C : word32)
  Class: Eq_96
  DataType: word32
  OrigDataType: word32
T_98: (in (word32) (r2_40 < r16_42) == 0<32> @ 0000076C : bool)
  Class: Eq_98
  DataType: bool
  OrigDataType: bool
T_99: (in __cxa_finalize @ 00000738 : ptr32)
  Class: Eq_99
  DataType: (ptr32 Eq_99)
  OrigDataType: (ptr32 (fn T_105 (T_104)))
T_100: (in signature of __cxa_finalize : void)
  Class: Eq_100
  DataType: Eq_100
  OrigDataType: 
T_101: (in r2_24 @ 00000738 : (ptr32 word32))
  Class: Eq_101
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 T_104 t0000)))
T_102: (in 0<32> @ 00000738 : word32)
  Class: Eq_102
  DataType: word32
  OrigDataType: word32
T_103: (in r2_24 + 0<32> @ 00000738 : word32)
  Class: Eq_103
  DataType: word32
  OrigDataType: word32
T_104: (in Mem19[r2_24 + 0<32>:word32] @ 00000738 : word32)
  Class: Eq_104
  DataType: word32
  OrigDataType: word32
T_105: (in __cxa_finalize(*r2_24) @ 00000738 : void)
  Class: Eq_105
  DataType: void
  OrigDataType: void
T_106: (in 0x10AAC<32> @ 00000730 : word32)
  Class: Eq_106
  DataType: (ptr32 (ptr32 word32))
  OrigDataType: (ptr32 (struct (0 T_107 t0000)))
T_107: (in Mem19[0x10AAC<32>:word32] @ 00000730 : word32)
  Class: Eq_101
  DataType: (ptr32 word32)
  OrigDataType: word32
T_108: (in deregister_tm_clones @ 000007A8 : ptr32)
  Class: Eq_108
  DataType: (ptr32 Eq_108)
  OrigDataType: (ptr32 (fn T_110 ()))
T_109: (in signature of deregister_tm_clones @ 00000670 : void)
  Class: Eq_108
  DataType: (ptr32 Eq_108)
  OrigDataType: 
T_110: (in deregister_tm_clones() @ 000007A8 : void)
  Class: Eq_110
  DataType: void
  OrigDataType: void
T_111: (in 1<8> @ 000007B4 : byte)
  Class: Eq_75
  DataType: byte
  OrigDataType: byte
T_112: (in 0x00010AF0<p32> @ 000007B4 : ptr32)
  Class: Eq_112
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_113 t0000)))
T_113: (in Mem76[0x00010AF0<p32>:byte] @ 000007B4 : byte)
  Class: Eq_75
  DataType: byte
  OrigDataType: byte
T_114: (in 1<i32> @ 00000774 : int32)
  Class: Eq_114
  DataType: int32
  OrigDataType: (union (int32 u0) (up32 u1))
T_115: (in r2_40 + 1<i32> @ 00000774 : word32)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: up32
T_116: (in r2_47 @ 00000774 : Eq_84)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: uint32
T_117: (in 0x00010AF4<p32> @ 0000077C : ptr32)
  Class: Eq_117
  DataType: (ptr32 Eq_84)
  OrigDataType: (ptr32 (struct (0 T_118 t0000)))
T_118: (in Mem50[0x00010AF4<p32>:word32] @ 0000077C : word32)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: word32
T_119: (in 2<8> @ 00000780 : byte)
  Class: Eq_119
  DataType: byte
  OrigDataType: byte
T_120: (in r2_47 << 2<8> @ 00000780 : word32)
  Class: Eq_120
  DataType: ui32
  OrigDataType: ui32
T_121: (in 0x00010A68<p32> @ 00000780 : ptr32)
  Class: Eq_121
  DataType: ptr32
  OrigDataType: ptr32
T_122: (in (r2_47 << 2<8>) + 0x00010A68<p32> @ 00000780 : word32)
  Class: Eq_122
  DataType: (ptr32 (ptr32 code))
  OrigDataType: ui32
T_123: (in r2_52 @ 00000780 : (ptr32 (ptr32 code)))
  Class: Eq_122
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct (0 T_126 t0000)))
T_124: (in 0<32> @ 00000788 : word32)
  Class: Eq_124
  DataType: word32
  OrigDataType: word32
T_125: (in r2_52 + 0<32> @ 00000788 : word32)
  Class: Eq_125
  DataType: ui32
  OrigDataType: ui32
T_126: (in Mem50[r2_52 + 0<32>:word32] @ 00000788 : word32)
  Class: Eq_126
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_127: (in 0x00010AF4<p32> @ 00000790 : ptr32)
  Class: Eq_127
  DataType: (ptr32 Eq_84)
  OrigDataType: (ptr32 (struct (0 T_128 t0000)))
T_128: (in Mem50[0x00010AF4<p32>:word32] @ 00000790 : word32)
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: word32
T_129: (in r2_40 < r16_42 @ 00000798 : bool)
  Class: Eq_129
  DataType: bool
  OrigDataType: bool
T_130: (in CONVERT(r2_40 <u r16_42, bool, word32) @ 00000798 : word32)
  Class: Eq_130
  DataType: word32
  OrigDataType: word32
T_131: (in 0<32> @ 00000798 : word32)
  Class: Eq_130
  DataType: word32
  OrigDataType: word32
T_132: (in (word32) (r2_40 < r16_42) != 0<32> @ 00000798 : bool)
  Class: Eq_132
  DataType: bool
  OrigDataType: bool
T_133: (in register_tm_clones @ 000007E8 : ptr32)
  Class: Eq_133
  DataType: (ptr32 Eq_133)
  OrigDataType: (ptr32 (fn T_135 ()))
T_134: (in signature of register_tm_clones @ 000006A8 : void)
  Class: Eq_133
  DataType: (ptr32 Eq_133)
  OrigDataType: 
T_135: (in register_tm_clones() @ 000007E8 : void)
  Class: Eq_135
  DataType: void
  OrigDataType: void
T_136: (in memset @ 00000830 : ptr32)
  Class: Eq_136
  DataType: (ptr32 Eq_136)
  OrigDataType: (ptr32 (fn T_146 (T_142, T_143, T_145)))
T_137: (in signature of memset : void)
  Class: Eq_136
  DataType: (ptr32 Eq_136)
  OrigDataType: 
T_138: (in r4 @ 00000830 : (ptr32 void))
  Class: Eq_138
  DataType: (ptr32 word32)
  OrigDataType: 
T_139: (in value @ 00000830 : int32)
  Class: Eq_139
  DataType: int32
  OrigDataType: 
T_140: (in num @ 00000830 : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: 
T_141: (in dwLoc14 @ 00000830 : word32)
  Class: Eq_141
  DataType: word32
  OrigDataType: word32
T_142: (in &dwLoc14 @ 00000830 : (ptr32 word32))
  Class: Eq_138
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 word32)
T_143: (in 0<32> @ 00000830 : word32)
  Class: Eq_139
  DataType: int32
  OrigDataType: int32
T_144: (in 5<i32> @ 00000830 : int32)
  Class: Eq_144
  DataType: int32
  OrigDataType: int32
T_145: (in SLICE(5<i32>, size_t, 0) @ 00000830 : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: size_t
T_146: (in memset(&dwLoc14, 0<32>, (size_t) 5<i32>) @ 00000830 : (ptr32 void))
  Class: Eq_146
  DataType: (ptr32 void)
  OrigDataType: (ptr32 void)
T_147: (in calloc @ 0000084C : ptr32)
  Class: Eq_147
  DataType: ptr32
  OrigDataType: ptr32
T_148: (in signature of calloc : void)
  Class: Eq_147
  DataType: ptr32
  OrigDataType: 
T_149: (in num @ 0000084C : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: 
T_150: (in size @ 0000084C : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: 
T_151: (in 1<i32> @ 0000084C : int32)
  Class: Eq_151
  DataType: int32
  OrigDataType: int32
T_152: (in SLICE(1<i32>, size_t, 0) @ 0000084C : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: size_t
T_153: (in 5<i32> @ 0000084C : int32)
  Class: Eq_153
  DataType: int32
  OrigDataType: int32
T_154: (in SLICE(5<i32>, size_t, 0) @ 0000084C : size_t)
  Class: Eq_140
  DataType: Eq_140
  OrigDataType: size_t
T_155: (in calloc((size_t) 1<i32>, (size_t) 5<i32>) @ 0000084C : (ptr32 void))
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: (ptr32 void)
T_156: (in r2_38 @ 0000084C : (ptr32 Eq_155))
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: (ptr32 (struct (0 T_160 t0000) (1 T_175 t0001) (4 T_167 t0004)))
T_157: (in &dwLoc14 @ 00000868 : (ptr32 word32))
  Class: Eq_157
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 word32 dw0000)))
T_158: (in 0<32> @ 00000868 : word32)
  Class: Eq_158
  DataType: word32
  OrigDataType: word32
T_159: (in &dwLoc14 + 0<32> @ 00000868 : word32)
  Class: Eq_159
  DataType: ptr32
  OrigDataType: ptr32
T_160: (in Mem42[&dwLoc14 + 0<32>:word32] @ 00000868 : word32)
  Class: Eq_160
  DataType: Eq_160
  OrigDataType: word32
T_161: (in 0<32> @ 00000868 : word32)
  Class: Eq_161
  DataType: word32
  OrigDataType: word32
T_162: (in r2_38 + 0<32> @ 00000868 : word32)
  Class: Eq_162
  DataType: ptr32
  OrigDataType: ptr32
T_163: (in Mem45[r2_38 + 0<32>:word32] @ 00000868 : word32)
  Class: Eq_160
  DataType: Eq_160
  OrigDataType: word32
T_164: (in bLoc10 @ 00000870 : byte)
  Class: Eq_164
  DataType: byte
  OrigDataType: byte
T_165: (in 4<32> @ 00000870 : word32)
  Class: Eq_165
  DataType: word32
  OrigDataType: word32
T_166: (in r2_38 + 4<32> @ 00000870 : word32)
  Class: Eq_166
  DataType: ptr32
  OrigDataType: ptr32
T_167: (in Mem48[r2_38 + 4<32>:byte] @ 00000870 : byte)
  Class: Eq_164
  DataType: byte
  OrigDataType: byte
T_168: (in 0xC<8> @ 0000087C : byte)
  Class: Eq_160
  DataType: byte
  OrigDataType: byte
T_169: (in 0<32> @ 0000087C : word32)
  Class: Eq_169
  DataType: word32
  OrigDataType: word32
T_170: (in r2_38 + 0<32> @ 0000087C : word32)
  Class: Eq_170
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 word32)
T_171: (in Mem51[r2_38 + 0<32>:byte] @ 0000087C : byte)
  Class: Eq_160
  DataType: Eq_160
  OrigDataType: word32
T_172: (in 0<32> @ 00000888 : word32)
  Class: Eq_172
  DataType: word32
  OrigDataType: word32
T_173: (in 1<32> @ 00000888 : word32)
  Class: Eq_173
  DataType: word32
  OrigDataType: word32
T_174: (in r2_38 + 1<32> @ 00000888 : word32)
  Class: Eq_174
  DataType: ptr32
  OrigDataType: ptr32
T_175: (in Mem53[r2_38 + 1<32>:word32] @ 00000888 : word32)
  Class: Eq_172
  DataType: word32
  OrigDataType: word32
T_176: (in 0x42<8> @ 00000890 : byte)
  Class: Eq_176
  DataType: byte
  OrigDataType: byte
T_177: (in &dwLoc14 @ 00000890 : (ptr32 word32))
  Class: Eq_177
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct (0 word32 dw0000)))
T_178: (in 0<32> @ 00000890 : word32)
  Class: Eq_178
  DataType: word32
  OrigDataType: word32
T_179: (in &dwLoc14 + 0<32> @ 00000890 : word32)
  Class: Eq_179
  DataType: ptr32
  OrigDataType: ptr32
T_180: (in Mem56[&dwLoc14 + 0<32>:byte] @ 00000890 : byte)
  Class: Eq_176
  DataType: byte
  OrigDataType: byte
T_181: (in &dwLoc14 @ 0000089C : (ptr32 word32))
  Class: Eq_181
  DataType: (ptr32 Eq_181)
  OrigDataType: (ptr32 (struct (0 word32 dw0000) (1 T_184 t0001)))
T_182: (in 1<i32> @ 0000089C : int32)
  Class: Eq_182
  DataType: int32
  OrigDataType: int32
T_183: (in &dwLoc14 + 1<i32> @ 0000089C : word32)
  Class: Eq_183
  DataType: ptr32
  OrigDataType: ptr32
T_184: (in Mem58[&dwLoc14 + 1<i32>:word32] @ 0000089C : word32)
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: word32
T_185: (in fp @ 00000808 : ptr32)
  Class: Eq_185
  DataType: ptr32
  OrigDataType: ptr32
T_186: (in -48<i32> @ 00000808 : int32)
  Class: Eq_186
  DataType: int32
  OrigDataType: int32
T_187: (in fp + -48<i32> @ 00000808 : word32)
  Class: Eq_187
  DataType: ptr32
  OrigDataType: ptr32
T_188: (in r30_12 @ 00000808 : ptr32)
  Class: Eq_187
  DataType: ptr32
  OrigDataType: ptr32
T_189: (in r2_43 @ 0000085C : (ptr32 Eq_155))
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: (ptr32 (struct (0 T_160 t0000) (1 T_175 t0001) (4 T_167 t0004)))
T_190: (in r2_52 @ 00000880 : (ptr32 Eq_155))
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: (ptr32 (struct (0 T_160 t0000) (1 T_175 t0001) (4 T_167 t0004)))
T_191: (in r2_57 @ 00000894 : (ptr32 Eq_155))
  Class: Eq_155
  DataType: (ptr32 Eq_155)
  OrigDataType: (ptr32 (struct (0 T_160 t0000) (1 T_175 t0001) (4 T_167 t0004)))
T_192: (in r4 @ 000008B4 : word32)
  Class: Eq_192
  DataType: word32
  OrigDataType: word32
T_193: (in r5 @ 000008B4 : word32)
  Class: Eq_193
  DataType: word32
  OrigDataType: word32
T_194: (in r6 @ 000008B4 : word32)
  Class: Eq_194
  DataType: word32
  OrigDataType: word32
T_195: (in _init @ 000008FC : ptr32)
  Class: Eq_195
  DataType: (ptr32 Eq_195)
  OrigDataType: (ptr32 (fn T_197 ()))
T_196: (in signature of _init @ 00000588 : void)
  Class: Eq_195
  DataType: (ptr32 Eq_195)
  OrigDataType: 
T_197: (in _init() @ 000008FC : void)
  Class: Eq_197
  DataType: void
  OrigDataType: void
T_198: (in 0x10ABC<32> @ 00000908 : word32)
  Class: Eq_198
  DataType: (ptr32 (ptr32 (ptr32 code)))
  OrigDataType: (ptr32 (struct (0 T_199 t0000)))
T_199: (in Mem30[0x10ABC<32>:word32] @ 00000908 : word32)
  Class: Eq_199
  DataType: (ptr32 (ptr32 code))
  OrigDataType: word32
T_200: (in r16_35 @ 00000908 : (ptr32 (ptr32 code)))
  Class: Eq_199
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct 0004 (0 (ptr32 code) ptr0000)))
T_201: (in 0x10ABC<32> @ 00000910 : word32)
  Class: Eq_201
  DataType: (ptr32 (ptr32 (ptr32 code)))
  OrigDataType: (ptr32 (struct (0 T_202 t0000)))
T_202: (in Mem30[0x10ABC<32>:word32] @ 00000910 : word32)
  Class: Eq_199
  DataType: (ptr32 (ptr32 code))
  OrigDataType: word32
T_203: (in g_ptr10ABC - r16_35 @ 00000910 : word32)
  Class: Eq_203
  DataType: int32
  OrigDataType: word32
T_204: (in r18_37 @ 00000910 : int32)
  Class: Eq_203
  DataType: int32
  OrigDataType: int32
T_205: (in 2<8> @ 00000918 : byte)
  Class: Eq_205
  DataType: byte
  OrigDataType: byte
T_206: (in r18_37 >> 2<8> @ 00000918 : word32)
  Class: Eq_206
  DataType: int32
  OrigDataType: int32
T_207: (in 0<32> @ 00000918 : word32)
  Class: Eq_206
  DataType: int32
  OrigDataType: word32
T_208: (in r18_37 >> 2<8> == 0<32> @ 00000918 : bool)
  Class: Eq_208
  DataType: bool
  OrigDataType: bool
T_209: (in 0<32> @ 00000930 : word32)
  Class: Eq_209
  DataType: word32
  OrigDataType: word32
T_210: (in r16_35 + 0<32> @ 00000930 : word32)
  Class: Eq_210
  DataType: word32
  OrigDataType: word32
T_211: (in Mem30[r16_35 + 0<32>:word32] @ 00000930 : word32)
  Class: Eq_211
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_212: (in r17_40 @ 00000924 : int32)
  Class: Eq_212
  DataType: int32
  OrigDataType: word32
T_213: (in 1<i32> @ 00000924 : int32)
  Class: Eq_213
  DataType: int32
  OrigDataType: int32
T_214: (in r17_40 + 1<i32> @ 00000924 : word32)
  Class: Eq_212
  DataType: int32
  OrigDataType: word32
T_215: (in r18_37 >> 2<8> @ 00000938 : word32)
  Class: Eq_212
  DataType: int32
  OrigDataType: int32
T_216: (in r18_37 >> 2<8> != r17_40 @ 00000938 : bool)
  Class: Eq_216
  DataType: bool
  OrigDataType: bool
T_217: (in 0<32> @ 0000091C : word32)
  Class: Eq_212
  DataType: int32
  OrigDataType: word32
T_218: (in 4<i32> @ 0000093C : int32)
  Class: Eq_218
  DataType: int32
  OrigDataType: int32
T_219: (in r16_35 + 4<i32> @ 0000093C : word32)
  Class: Eq_199
  DataType: (ptr32 (ptr32 code))
  OrigDataType: ptr32
T_220: (in 0x00010A60<p32> @ 00000998 : ptr32)
  Class: Eq_220
  DataType: (ptr32 (ptr32 code))
  OrigDataType: (ptr32 (struct (0 T_221 t0000)))
T_221: (in Mem17[0x00010A60<p32>:word32] @ 00000998 : word32)
  Class: Eq_221
  DataType: (ptr32 code)
  OrigDataType: word32
T_222: (in r25_18 @ 00000998 : (ptr32 code))
  Class: Eq_221
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_223: (in -1<i32> @ 0000099C : int32)
  Class: Eq_221
  DataType: (ptr32 code)
  OrigDataType: int32
T_224: (in r25_18 == (<anonymous> *) -1<i32> @ 0000099C : bool)
  Class: Eq_224
  DataType: bool
  OrigDataType: bool
T_225: (in 0x00010A60<p32> @ 000009A4 : ptr32)
  Class: Eq_225
  DataType: (ptr32 word32)
  OrigDataType: ptr32
T_226: (in r16_21 @ 000009A4 : (ptr32 word32))
  Class: Eq_225
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct 0004 (0 word32 dw0000)))
T_227: (in -4<i32> @ 000009A8 : int32)
  Class: Eq_227
  DataType: int32
  OrigDataType: int32
T_228: (in r16_21 + -4<i32> @ 000009A8 : word32)
  Class: Eq_225
  DataType: (ptr32 word32)
  OrigDataType: ptr32
T_229: (in 0<32> @ 000009B0 : word32)
  Class: Eq_229
  DataType: word32
  OrigDataType: word32
T_230: (in r16_21 + 0<32> @ 000009B0 : word32)
  Class: Eq_230
  DataType: ptr32
  OrigDataType: ptr32
T_231: (in Mem17[r16_21 + 0<32>:word32] @ 000009B0 : word32)
  Class: Eq_221
  DataType: (ptr32 code)
  OrigDataType: word32
T_232: (in -1<i32> @ 000009B4 : int32)
  Class: Eq_221
  DataType: (ptr32 code)
  OrigDataType: int32
T_233: (in r25_18 != (<anonymous> *) -1<i32> @ 000009B4 : bool)
  Class: Eq_233
  DataType: bool
  OrigDataType: bool
T_234: (in r28 @ 000009B4 : (ptr32 Eq_234))
  Class: Eq_234
  DataType: (ptr32 Eq_234)
  OrigDataType: (ptr32 (struct (FFFF8010 T_238 tFFFF8010)))
T_235: (in ra @ 000009B4 : word32)
  Class: Eq_235
  DataType: word32
  OrigDataType: word32
T_236: (in -32752<i32> @ 000009D8 : int32)
  Class: Eq_236
  DataType: int32
  OrigDataType: int32
T_237: (in r28 + -32752<i32> @ 000009D8 : word32)
  Class: Eq_237
  DataType: word32
  OrigDataType: word32
T_238: (in Mem0[r28 + -32752<i32>:word32] @ 000009D8 : word32)
  Class: Eq_238
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_239: (in r28 @ 000009D8 : (ptr32 Eq_239))
  Class: Eq_239
  DataType: (ptr32 Eq_239)
  OrigDataType: (ptr32 (struct (FFFF8010 T_243 tFFFF8010)))
T_240: (in ra @ 000009D8 : word32)
  Class: Eq_240
  DataType: word32
  OrigDataType: word32
T_241: (in -32752<i32> @ 000009E8 : int32)
  Class: Eq_241
  DataType: int32
  OrigDataType: int32
T_242: (in r28 + -32752<i32> @ 000009E8 : word32)
  Class: Eq_242
  DataType: word32
  OrigDataType: word32
T_243: (in Mem0[r28 + -32752<i32>:word32] @ 000009E8 : word32)
  Class: Eq_243
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_244: (in r28 @ 000009E8 : (ptr32 Eq_244))
  Class: Eq_244
  DataType: (ptr32 Eq_244)
  OrigDataType: (ptr32 (struct (FFFF8010 T_248 tFFFF8010)))
T_245: (in ra @ 000009E8 : word32)
  Class: Eq_245
  DataType: word32
  OrigDataType: word32
T_246: (in -32752<i32> @ 000009F8 : int32)
  Class: Eq_246
  DataType: int32
  OrigDataType: int32
T_247: (in r28 + -32752<i32> @ 000009F8 : word32)
  Class: Eq_247
  DataType: word32
  OrigDataType: word32
T_248: (in Mem0[r28 + -32752<i32>:word32] @ 000009F8 : word32)
  Class: Eq_248
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_249: (in _fini @ 00000A0C : ptr32)
  Class: Eq_249
  DataType: (ptr32 Eq_249)
  OrigDataType: (ptr32 (fn T_251 ()))
T_250: (in signature of _fini @ 00000A10 : void)
  Class: Eq_249
  DataType: (ptr32 Eq_249)
  OrigDataType: 
T_251: (in _fini() @ 00000A0C : void)
  Class: Eq_251
  DataType: void
  OrigDataType: void
T_252: (in Mem10[0x00010AB4<p32>:word32] @ 00000A3C : word32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: word32
T_253: (in r25_15 @ 00000A3C : ptr32)
  Class: Eq_7
  DataType: ptr32
  OrigDataType: ptr32
T_254: (in 1780<i32> @ 00000A44 : int32)
  Class: Eq_254
  DataType: int32
  OrigDataType: int32
T_255: (in r25_15 + 1780<i32> @ 00000A44 : word32)
  Class: Eq_255
  DataType: (ptr32 code)
  OrigDataType: (ptr32 code)
T_256:
  Class: Eq_256
  DataType: word32
  OrigDataType: word32
T_257:
  Class: Eq_84
  DataType: Eq_84
  OrigDataType: word32
*/
typedef struct Globals {
	<anonymous> tFFFFFFFF;	// FFFFFFFF
	<anonymous> t0000;	// 0
	word32 _IO_stdin_used;	// A58
	<anonymous> * ptr10A60;	// 10A60
	<unknown> t10A68;	// 10A68
	<anonymous> * main_GOT;	// 10A98
	<anonymous> * __libc_csu_init_GOT;	// 10A9C
	<anonymous> * __libc_csu_fini_GOT;	// 10AA0
	Eq_47 t10AA4;	// 10AA4
	word32 * ptr10AAC;	// 10AAC
	int32 dw10AB0;	// 10AB0
	ptr32 ptr10AB4;	// 10AB4
	<anonymous> * _init_GOT;	// 10AB8
	<anonymous> ** ptr10ABC;	// 10ABC
	<anonymous> * calloc_GOT;	// 10AD0
	<anonymous> * ptr10AD4;	// 10AD4
	<anonymous> * memset_GOT;	// 10AD8
	<anonymous> * __libc_start_main_GOT;	// 10ADC
	<anonymous> * __gmon_start___GOT;	// 10AE0
	<anonymous> * ptr10AE4;	// 10AE4
	<anonymous> * __cxa_finalize_GOT;	// 10AE8
	word32 dw10AEC;	// 10AEC
	byte b10AF0;	// 10AF0
	Eq_84 dtor_idx.6258;	// 10AF4
} Eq_1;

typedef void (Eq_15)();

typedef union Eq_23 {
	ui32 u0;
	ptr32 u1;
} Eq_23;

typedef struct Eq_27 {
	word32 dw0010;	// 10
	word32 dw0014;	// 14
	struct Eq_27 * ptr0018;	// 18
} Eq_27;

typedef union Eq_47 {
	int32 u0;
	ptr32 u1;
} Eq_47;

typedef union Eq_57 {
	int32 u0;
	ptr32 u1;
} Eq_57;

typedef union Eq_60 {
	int32 u0;
	uint32 u1;
} Eq_60;

typedef union Eq_63 {
	int32 u0;
	uint32 u1;
} Eq_63;

typedef union Eq_64 {
	int32 u0;
	uint32 u1;
} Eq_64;

typedef union Eq_84 {
	int32 u0;
	uint32 u1;
} Eq_84;

typedef union Eq_88 {
	int32 u0;
	ptr32 u1;
} Eq_88;

typedef void (Eq_99)(word32);

typedef void (Eq_108)();

typedef union Eq_114 {
	int32 u0;
	up32 u1;
} Eq_114;

typedef void (Eq_133)();

typedef void (Eq_136)(word32 *, int32, size_t);

typedef size_t Eq_140;

typedef struct Eq_155 {
	Eq_160 t0000;	// 0
	word32 dw0001;	// 1
	byte b0004;	// 4
} Eq_155;

typedef union Eq_160 {
	byte u0;
	word32 u1;
} Eq_160;

typedef struct Eq_181 {
	word32 dw0000;	// 0
	struct Eq_155 * ptr0001;	// 1
} Eq_181;

typedef void (Eq_195)();

typedef struct Eq_234 {
	<anonymous> * ptrFFFF8010;	// FFFF8010
} Eq_234;

typedef struct Eq_239 {
	<anonymous> * ptrFFFF8010;	// FFFF8010
} Eq_239;

typedef struct Eq_244 {
	<anonymous> * ptrFFFF8010;	// FFFF8010
} Eq_244;

typedef void (Eq_249)();

