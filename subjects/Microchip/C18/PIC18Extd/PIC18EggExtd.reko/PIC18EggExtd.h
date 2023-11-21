// PIC18EggExtd.h
// Generated by decompiling PIC18EggExtd.hex
// using Reko decompiler version 0.11.5.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals"
		(1 byte b0001)
		(C0 cu8 b00C0)
		(C1 cu8 b00C1)
		(C2 cu8 b00C2)
		(C3 cu8 b00C3)
		(C4 cu8 b00C4)
		(C5 cu8 b00C5)
		(C6 cu8 b00C6)
		(C7 byte b00C7)
		(C8 byte b00C8)
		(C9 byte b00C9)
		(CA byte b00CA))
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_7: (fn void (cu8, Eq_10, Eq_11))
	T_7 (in fn00000E @ 000144 : ptr32)
	T_8 (in signature of fn00000E @ 00000E : void)
Eq_10: (union "Eq_10" (word16 u0) ((ptr32 byte) u1))
	T_10 (in FSR0 @ 000144 : Eq_10)
	T_12 (in 0<16> @ 000144 : word16)
	T_109 (in FSR0 + 1<16> @ 00008A : word16)
Eq_11: (union "Eq_11" (ptr16 u0) (word24 u1))
	T_11 (in TBLPTR @ 000144 : Eq_11)
	T_13 (in 0<24> @ 000144 : word24)
	T_17 (in p1 @ 00001C : ptr16)
Eq_15: (fn void (Eq_11, byte))
	T_15 (in __tblrd @ 00001C : ptr32)
	T_16 (in signature of __tblrd : void)
	T_23 (in __tblrd @ 000022 : ptr32)
	T_37 (in __tblrd @ 000030 : ptr32)
	T_42 (in __tblrd @ 000036 : ptr32)
	T_47 (in __tblrd @ 00003C : ptr32)
	T_52 (in __tblrd @ 000042 : ptr32)
	T_55 (in __tblrd @ 000044 : ptr32)
	T_58 (in __tblrd @ 00004A : ptr32)
	T_61 (in __tblrd @ 000050 : ptr32)
	T_64 (in __tblrd @ 000052 : ptr32)
	T_67 (in __tblrd @ 000054 : ptr32)
	T_72 (in __tblrd @ 00005A : ptr32)
	T_77 (in __tblrd @ 000060 : ptr32)
	T_80 (in __tblrd @ 000062 : ptr32)
	T_98 (in __tblrd @ 000086 : ptr32)
Eq_132: (union "Eq_132" (bool u0) (byte u1))
	T_132 (in !(bool) cond(g_b00C5) @ 0000A6 : bool)
Eq_144: (struct "Eq_144" (FFFFFFFE byte bFFFFFFFE))
	T_144 (in FSR2 @ 0000AA : (ptr16 Eq_144))
Eq_176: (union "Eq_176" (word16 u0) ((ptr32 byte) u1))
	T_176 (in FSR0 @ 0000EC : Eq_176)
	T_183 (in FSR0 + 1<16> @ 00012C : word16)
	T_189 (in FSR0 + 1<16> @ 000136 : word16)
Eq_182: (union "Eq_182" (word16 u0) ((ptr32 byte) u1))
	T_182 (in 1<16> @ 00012C : word16)
Eq_186: (union "Eq_186" (word16 u0) ((ptr32 byte) u1))
	T_186 (in FSR0 + 0<16> @ 000136 : word16)
Eq_188: (union "Eq_188" (word16 u0) ((ptr32 byte) u1))
	T_188 (in 1<16> @ 000136 : word16)
Eq_191: (struct "Eq_191" 0001 (0 ptr32 ptr0000))
	T_191
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in TABLAT : cu8)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_3: (in 000148 @ 000144 : ptr32)
  Class: Eq_3
  DataType: ptr32
  OrigDataType: ptr32
T_4: (in Stack @ 000144 : (arr Eq_191))
  Class: Eq_4
  DataType: (ptr32 (arr Eq_191))
  OrigDataType: (ptr32 (struct (0 (arr T_191) a0000)))
T_5: (in 1<8> @ 000144 : byte)
  Class: Eq_5
  DataType: byte
  OrigDataType: byte
T_6: (in Stack[1<8>] @ 000144 : ptr32)
  Class: Eq_3
  DataType: ptr32
  OrigDataType: ptr32
T_7: (in fn00000E @ 000144 : ptr32)
  Class: Eq_7
  DataType: (ptr32 Eq_7)
  OrigDataType: (ptr32 (fn T_14 (T_2, T_12, T_13)))
T_8: (in signature of fn00000E @ 00000E : void)
  Class: Eq_7
  DataType: (ptr32 Eq_7)
  OrigDataType: 
T_9: (in TABLAT @ 000144 : cu8)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_10: (in FSR0 @ 000144 : Eq_10)
  Class: Eq_10
  DataType: Eq_10
  OrigDataType: (union ((ptr32 (struct 0001 (0 byte b0000))) u0) ((ptr32 byte) u1))
T_11: (in TBLPTR @ 000144 : Eq_11)
  Class: Eq_11
  DataType: Eq_11
  OrigDataType: (union (ptr16 u0) (word24 u1))
T_12: (in 0<16> @ 000144 : word16)
  Class: Eq_10
  DataType: word16
  OrigDataType: word16
T_13: (in 0<24> @ 000144 : word24)
  Class: Eq_11
  DataType: word24
  OrigDataType: word24
T_14: (in fn00000E(TABLAT, 0<16>, 0<24>) @ 000144 : void)
  Class: Eq_14
  DataType: void
  OrigDataType: void
T_15: (in __tblrd @ 00001C : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_20 (T_11, T_19)))
T_16: (in signature of __tblrd : void)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: 
T_17: (in p1 @ 00001C : ptr16)
  Class: Eq_11
  DataType: Eq_11
  OrigDataType: 
T_18: (in p2 @ 00001C : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: 
T_19: (in 1<8> @ 00001C : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_20: (in __tblrd(TBLPTR, 1<8>) @ 00001C : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_21: (in 00C5 @ 000020 : 16)
  Class: Eq_21
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_2 t0000)))
T_22: (in Data13[0x00C5<p16>:byte] @ 000020 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_23: (in __tblrd @ 000022 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_25 (T_11, T_24)))
T_24: (in 1<8> @ 000022 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_25: (in __tblrd(TBLPTR, 1<8>) @ 000022 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_26: (in 00C6 @ 000026 : 16)
  Class: Eq_26
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_2 t0000)))
T_27: (in Data16[0x00C6<p16>:byte] @ 000026 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_28: (in 6<8> @ 000010 : byte)
  Class: Eq_28
  DataType: byte
  OrigDataType: byte
T_29: (in TBLPTRL_4 @ 000010 : byte)
  Class: Eq_28
  DataType: byte
  OrigDataType: byte
T_30: (in 0<8> @ 000014 : byte)
  Class: Eq_30
  DataType: byte
  OrigDataType: byte
T_31: (in TBLPTRH_46 @ 000014 : byte)
  Class: Eq_30
  DataType: byte
  OrigDataType: byte
T_32: (in 0<8> @ 000018 : byte)
  Class: Eq_32
  DataType: byte
  OrigDataType: byte
T_33: (in TBLPTRU_49 @ 000018 : byte)
  Class: Eq_32
  DataType: byte
  OrigDataType: byte
T_34: (in 0<8> @ 000024 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_35: (in TABLAT != 0<8> @ 000024 : bool)
  Class: Eq_35
  DataType: bool
  OrigDataType: bool
T_36: (in v21_98 @ 000024 : bool)
  Class: Eq_35
  DataType: bool
  OrigDataType: bool
T_37: (in __tblrd @ 000030 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_39 (T_11, T_38)))
T_38: (in 1<8> @ 000030 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_39: (in __tblrd(TBLPTR, 1<8>) @ 000030 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_40: (in 00C0 @ 000034 : 16)
  Class: Eq_40
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_41 t0000)))
T_41: (in Data29[0x00C0<p16>:byte] @ 000034 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_42: (in __tblrd @ 000036 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_44 (T_11, T_43)))
T_43: (in 1<8> @ 000036 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_44: (in __tblrd(TBLPTR, 1<8>) @ 000036 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_45: (in 00C1 @ 00003A : 16)
  Class: Eq_45
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_46 t0000)))
T_46: (in Data31[0x00C1<p16>:byte] @ 00003A : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_47: (in __tblrd @ 00003C : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_49 (T_11, T_48)))
T_48: (in 1<8> @ 00003C : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_49: (in __tblrd(TBLPTR, 1<8>) @ 00003C : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_50: (in 00C2 @ 000040 : 16)
  Class: Eq_50
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_51 t0000)))
T_51: (in Data33[0x00C2<p16>:byte] @ 000040 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_52: (in __tblrd @ 000042 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_54 (T_11, T_53)))
T_53: (in 1<8> @ 000042 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_54: (in __tblrd(TBLPTR, 1<8>) @ 000042 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_55: (in __tblrd @ 000044 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_57 (T_11, T_56)))
T_56: (in 1<8> @ 000044 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_57: (in __tblrd(TBLPTR, 1<8>) @ 000044 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_58: (in __tblrd @ 00004A : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_60 (T_11, T_59)))
T_59: (in 1<8> @ 00004A : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_60: (in __tblrd(TBLPTR, 1<8>) @ 00004A : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_61: (in __tblrd @ 000050 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_63 (T_11, T_62)))
T_62: (in 1<8> @ 000050 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_63: (in __tblrd(TBLPTR, 1<8>) @ 000050 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_64: (in __tblrd @ 000052 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_66 (T_11, T_65)))
T_65: (in 1<8> @ 000052 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_66: (in __tblrd(TBLPTR, 1<8>) @ 000052 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_67: (in __tblrd @ 000054 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_69 (T_11, T_68)))
T_68: (in 1<8> @ 000054 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_69: (in __tblrd(TBLPTR, 1<8>) @ 000054 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_70: (in 00C3 @ 000058 : 16)
  Class: Eq_70
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_2 t0000)))
T_71: (in Data39[0x00C3<p16>:byte] @ 000058 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_72: (in __tblrd @ 00005A : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_74 (T_11, T_73)))
T_73: (in 1<8> @ 00005A : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_74: (in __tblrd(TBLPTR, 1<8>) @ 00005A : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_75: (in 00C4 @ 00005E : 16)
  Class: Eq_75
  DataType: (ptr16 cu8)
  OrigDataType: (ptr16 (struct (0 T_2 t0000)))
T_76: (in Data41[0x00C4<p16>:byte] @ 00005E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_77: (in __tblrd @ 000060 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_79 (T_11, T_78)))
T_78: (in 1<8> @ 000060 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_79: (in __tblrd(TBLPTR, 1<8>) @ 000060 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_80: (in __tblrd @ 000062 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_82 (T_11, T_81)))
T_81: (in 1<8> @ 000062 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_82: (in __tblrd(TBLPTR, 1<8>) @ 000062 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_83: (in 00C7 @ 000064 : ptr16)
  Class: Eq_83
  DataType: (ptr16 byte)
  OrigDataType: (ptr16 (struct (0 T_28 t0000)))
T_84: (in Data44[0x00C7<p16>:byte] @ 000064 : byte)
  Class: Eq_28
  DataType: byte
  OrigDataType: byte
T_85: (in 00C8 @ 000068 : ptr16)
  Class: Eq_85
  DataType: (ptr16 byte)
  OrigDataType: (ptr16 (struct (0 T_30 t0000)))
T_86: (in Data47[0x00C8<p16>:byte] @ 000068 : byte)
  Class: Eq_30
  DataType: byte
  OrigDataType: byte
T_87: (in 00C9 @ 00006C : ptr16)
  Class: Eq_87
  DataType: (ptr16 byte)
  OrigDataType: (ptr16 (struct (0 T_32 t0000)))
T_88: (in Data50[0x00C9<p16>:byte] @ 00006C : byte)
  Class: Eq_32
  DataType: byte
  OrigDataType: byte
T_89: (in Data50[0x00C3<p16>:byte] @ 00007E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_90: (in Data55[0x00C3<p16>:byte] @ 00007E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_91: (in Data55[0x00C3<p16>:byte] @ 00007E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_92: (in 0<8> @ 00007E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_93: (in g_b00C3 != 0<8> @ 00007E : bool)
  Class: Eq_93
  DataType: bool
  OrigDataType: bool
T_94: (in v24_101 @ 00007E : bool)
  Class: Eq_93
  DataType: bool
  OrigDataType: bool
T_95: (in Data19[0x00C5<p16>:byte] @ 00002A : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_96: (in 0<8> @ 00002A : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_97: (in g_b00C5 == 0<8> @ 00002A : bool)
  Class: Eq_97
  DataType: bool
  OrigDataType: bool
T_98: (in __tblrd @ 000086 : ptr32)
  Class: Eq_15
  DataType: (ptr32 Eq_15)
  OrigDataType: (ptr32 (fn T_100 (T_11, T_99)))
T_99: (in 1<8> @ 000086 : byte)
  Class: Eq_18
  DataType: byte
  OrigDataType: byte
T_100: (in __tblrd(TBLPTR, 1<8>) @ 000086 : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_101: (in 0<16> @ 00008A : word16)
  Class: Eq_101
  DataType: word16
  OrigDataType: word16
T_102: (in FSR0 + 0<16> @ 00008A : word16)
  Class: Eq_102
  DataType: word16
  OrigDataType: word16
T_103: (in Data77[FSR0 + 0<16>:byte] @ 00008A : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_104: (in Data77[0x00C3<p16>:byte] @ 00008C : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_105: (in 1<8> @ 00008C : byte)
  Class: Eq_105
  DataType: byte
  OrigDataType: byte
T_106: (in g_b00C3 - 1<8> @ 00008C : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_107: (in Data80[0x00C3<p16>:byte] @ 00008C : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_108: (in 1<16> @ 00008A : word16)
  Class: Eq_108
  DataType: (ptr32 byte)
  OrigDataType: (union ((ptr32 (struct 0001 (0 byte b0000))) u0) ((ptr32 byte) u1))
T_109: (in FSR0 + 1<16> @ 00008A : word16)
  Class: Eq_10
  DataType: Eq_10
  OrigDataType: (union ((ptr32 (struct 0001 (0 byte b0000))) u0) ((ptr32 byte) u1))
T_110: (in Data80[0x00C3<p16>:byte] @ 00008C : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_111: (in 0<8> @ 00008C : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_112: (in g_b00C3 != 0<8> @ 00008C : bool)
  Class: Eq_93
  DataType: bool
  OrigDataType: bool
T_113: (in Data80[0x00C3<p16>:byte] @ 00008E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: cu8
T_114: (in 0<8> @ 00008E : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: cu8
T_115: (in g_b00C3 < 0<8> @ 00008E : bool)
  Class: Eq_115
  DataType: bool
  OrigDataType: bool
T_116: (in Data59[0x00C4<p16>:byte] @ 000082 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_117: (in Data60[0x00C4<p16>:byte] @ 000082 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_118: (in Data60[0x00C4<p16>:byte] @ 000084 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_119: (in 0<8> @ 000084 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_120: (in g_b00C4 == 0<8> @ 000084 : bool)
  Class: Eq_120
  DataType: bool
  OrigDataType: bool
T_121: (in Data60[0x00C7<p16>:byte] @ 000094 : byte)
  Class: Eq_28
  DataType: byte
  OrigDataType: byte
T_122: (in Data60[0x00C8<p16>:byte] @ 000098 : byte)
  Class: Eq_30
  DataType: byte
  OrigDataType: byte
T_123: (in Data60[0x00C9<p16>:byte] @ 00009C : byte)
  Class: Eq_32
  DataType: byte
  OrigDataType: byte
T_124: (in Data60[0x00C5<p16>:byte] @ 0000A2 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_125: (in 1<8> @ 0000A2 : byte)
  Class: Eq_125
  DataType: byte
  OrigDataType: byte
T_126: (in g_b00C5 - 1<8> @ 0000A2 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_127: (in Data67[0x00C5<p16>:byte] @ 0000A2 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_128: (in Data67[0x00C6<p16>:byte] @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_129: (in Data67[0x00C5<p16>:byte] @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_130: (in cond(Data67[0x00C5<p16>:byte]) @ 0000A6 : byte)
  Class: Eq_130
  DataType: byte
  OrigDataType: byte
T_131: (in SLICE(cond(Data67[0x00C5<p16>:byte]), bool, 0) @ 0000A6 : bool)
  Class: Eq_131
  DataType: bool
  OrigDataType: bool
T_132: (in !(bool) cond(g_b00C5) @ 0000A6 : bool)
  Class: Eq_132
  DataType: Eq_132
  OrigDataType: (union (bool u0) (byte u1))
T_133: (in g_b00C6 - !((bool) cond(g_b00C5)) @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_134: (in Data71[0x00C6<p16>:byte] @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_135: (in Data71[0x00C6<p16>:byte] @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_136: (in 0<8> @ 0000A6 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_137: (in g_b00C6 != 0<8> @ 0000A6 : bool)
  Class: Eq_35
  DataType: bool
  OrigDataType: bool
T_138: (in Data80[0x00C4<p16>:byte] @ 000090 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_139: (in 1<8> @ 000090 : byte)
  Class: Eq_139
  DataType: byte
  OrigDataType: byte
T_140: (in g_b00C4 - 1<8> @ 000090 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_141: (in Data83[0x00C4<p16>:byte] @ 000090 : byte)
  Class: Eq_2
  DataType: cu8
  OrigDataType: byte
T_142: (in LATB @ 0000AA : byte)
  Class: Eq_142
  DataType: byte
  OrigDataType: byte
T_143: (in FSR2L @ 0000AA : byte)
  Class: Eq_143
  DataType: byte
  OrigDataType: byte
T_144: (in FSR2 @ 0000AA : (ptr16 Eq_144))
  Class: Eq_144
  DataType: (ptr16 Eq_144)
  OrigDataType: (ptr16 (struct (FFFFFFFE T_165 tFFFFFFFE)))
T_145: (in FSR1 @ 0000AA : (ptr16 byte))
  Class: Eq_145
  DataType: (ptr16 byte)
  OrigDataType: (ptr16 (struct (0 T_148 t0000)))
T_146: (in 0<16> @ 0000D0 : word16)
  Class: Eq_146
  DataType: word16
  OrigDataType: word16
T_147: (in FSR1 + 0<16> @ 0000D0 : word16)
  Class: Eq_147
  DataType: word16
  OrigDataType: word16
T_148: (in Data5[FSR1 + 0<16>:byte] @ 0000D0 : byte)
  Class: Eq_143
  DataType: byte
  OrigDataType: byte
T_149: (in 00CA @ 0000E0 : 16)
  Class: Eq_149
  DataType: (ptr16 byte)
  OrigDataType: (ptr16 (struct (0 T_150 t0000)))
T_150: (in Data12[0x00CA<p16>:byte] @ 0000E0 : byte)
  Class: Eq_150
  DataType: byte
  OrigDataType: byte
T_151: (in 1<8> @ 0000E0 : byte)
  Class: Eq_151
  DataType: byte
  OrigDataType: byte
T_152: (in g_b00CA & 1<8> @ 0000E0 : byte)
  Class: Eq_152
  DataType: byte
  OrigDataType: byte
T_153: (in 0<8> @ 0000E0 : byte)
  Class: Eq_152
  DataType: byte
  OrigDataType: byte
T_154: (in (g_b00CA & 1<8>) != 0<8> @ 0000E0 : bool)
  Class: Eq_154
  DataType: bool
  OrigDataType: bool
T_155: (in Data12[0x00CA<p16>:byte] @ 0000E4 : byte)
  Class: Eq_150
  DataType: byte
  OrigDataType: byte
T_156: (in 0xFE<8> @ 0000E4 : byte)
  Class: Eq_156
  DataType: byte
  OrigDataType: byte
T_157: (in g_b00CA & 0xFE<8> @ 0000E4 : byte)
  Class: Eq_150
  DataType: byte
  OrigDataType: byte
T_158: (in Data23[0x00CA<p16>:byte] @ 0000E4 : byte)
  Class: Eq_150
  DataType: byte
  OrigDataType: byte
T_159: (in 1<8> @ 0000EA : byte)
  Class: Eq_159
  DataType: byte
  OrigDataType: byte
T_160: (in LATB & 1<8> @ 0000EA : byte)
  Class: Eq_160
  DataType: byte
  OrigDataType: byte
T_161: (in 0<8> @ 0000EA : byte)
  Class: Eq_160
  DataType: byte
  OrigDataType: byte
T_162: (in (LATB & 1<8>) == 0<8> @ 0000EA : bool)
  Class: Eq_162
  DataType: bool
  OrigDataType: bool
T_163: (in -2<i8> @ 0000DC : int8)
  Class: Eq_163
  DataType: int8
  OrigDataType: int8
T_164: (in FSR2 + -2<i8> @ 0000DC : word16)
  Class: Eq_164
  DataType: word16
  OrigDataType: word16
T_165: (in Data12[FSR2 + -2<i8>:byte] @ 0000DC : byte)
  Class: Eq_165
  DataType: byte
  OrigDataType: byte
T_166: (in 0<8> @ 0000DC : byte)
  Class: Eq_165
  DataType: byte
  OrigDataType: byte
T_167: (in FSR2->bFFFFFFFE == 0<8> @ 0000DC : bool)
  Class: Eq_167
  DataType: bool
  OrigDataType: bool
T_168: (in 0x7F<8> @ 0000F0 : byte)
  Class: Eq_168
  DataType: byte
  OrigDataType: byte
T_169: (in LATB & 0x7F<8> @ 0000F0 : byte)
  Class: Eq_142
  DataType: byte
  OrigDataType: byte
T_170: (in 0x80<8> @ 0000EC : byte)
  Class: Eq_170
  DataType: byte
  OrigDataType: byte
T_171: (in LATB | 0x80<8> @ 0000EC : byte)
  Class: Eq_142
  DataType: byte
  OrigDataType: byte
T_172: (in WREG @ 0000EC : cu8)
  Class: Eq_172
  DataType: cu8
  OrigDataType: cu8
T_173: (in FSR0L @ 0000EC : cu8)
  Class: Eq_173
  DataType: cu8
  OrigDataType: cu8
T_174: (in FSR0H @ 0000EC : cu8)
  Class: Eq_172
  DataType: cu8
  OrigDataType: cu8
T_175: (in PRODL @ 0000EC : cu8)
  Class: Eq_173
  DataType: cu8
  OrigDataType: cu8
T_176: (in FSR0 @ 0000EC : Eq_176)
  Class: Eq_176
  DataType: Eq_176
  OrigDataType: word32
T_177: (in FSR0H < WREG @ 000128 : bool)
  Class: Eq_177
  DataType: bool
  OrigDataType: bool
T_178: (in 0<8> @ 00012C : byte)
  Class: Eq_178
  DataType: byte
  OrigDataType: byte
T_179: (in 0<16> @ 00012C : word16)
  Class: Eq_179
  DataType: word16
  OrigDataType: word16
T_180: (in FSR0 + 0<16> @ 00012C : word16)
  Class: Eq_180
  DataType: word16
  OrigDataType: word16
T_181: (in Data6[FSR0 + 0<16>:byte] @ 00012C : byte)
  Class: Eq_178
  DataType: byte
  OrigDataType: byte
T_182: (in 1<16> @ 00012C : word16)
  Class: Eq_182
  DataType: word16
  OrigDataType: (union (word16 u2) ((ptr32 byte) u1))
T_183: (in FSR0 + 1<16> @ 00012C : word16)
  Class: Eq_176
  DataType: Eq_176
  OrigDataType: (union (word16 u2) ((ptr32 byte) u1))
T_184: (in 0<8> @ 000136 : byte)
  Class: Eq_184
  DataType: byte
  OrigDataType: byte
T_185: (in 0<16> @ 000136 : word16)
  Class: Eq_185
  DataType: word16
  OrigDataType: word16
T_186: (in FSR0 + 0<16> @ 000136 : word16)
  Class: Eq_186
  DataType: Eq_186
  OrigDataType: (union (word16 u2) ((ptr32 byte) u1))
T_187: (in Data16[FSR0 + 0<16>:byte] @ 000136 : byte)
  Class: Eq_184
  DataType: byte
  OrigDataType: byte
T_188: (in 1<16> @ 000136 : word16)
  Class: Eq_188
  DataType: word16
  OrigDataType: (union (word16 u2) ((ptr32 byte) u1))
T_189: (in FSR0 + 1<16> @ 000136 : word16)
  Class: Eq_176
  DataType: Eq_176
  OrigDataType: (union (word16 u2) ((ptr32 byte) u1))
T_190: (in FSR0L < PRODL @ 000132 : bool)
  Class: Eq_190
  DataType: bool
  OrigDataType: bool
T_191:
  Class: Eq_191
  DataType: Eq_191
  OrigDataType: (struct 0001 (0 T_6 t0000))
T_192:
  Class: Eq_192
  DataType: (arr Eq_191)
  OrigDataType: (arr T_191)
*/
typedef struct Globals {
	byte b0001;	// 1
	cu8 b00C0;	// C0
	cu8 b00C1;	// C1
	cu8 b00C2;	// C2
	cu8 b00C3;	// C3
	cu8 b00C4;	// C4
	cu8 b00C5;	// C5
	cu8 b00C6;	// C6
	byte b00C7;	// C7
	byte b00C8;	// C8
	byte b00C9;	// C9
	byte b00CA;	// CA
} Eq_1;

typedef void (Eq_7)(cu8, Eq_10, Eq_11);

typedef union Eq_10 {
	word16 u0;
	byte * u1;
} Eq_10;

typedef union Eq_11 {
	ptr16 u0;
	word24 u1;
} Eq_11;

typedef void (Eq_15)(Eq_11, byte);

typedef union Eq_132 {
	bool u0;
	byte u1;
} Eq_132;

typedef struct Eq_144 {
	byte bFFFFFFFE;	// FFFFFFFE
} Eq_144;

typedef union Eq_176 {
	word16 u0;
	byte * u1;
} Eq_176;

typedef union Eq_182 {
	word16 u0;
	byte * u1;
} Eq_182;

typedef union Eq_186 {
	word16 u0;
	byte * u1;
} Eq_186;

typedef union Eq_188 {
	word16 u0;
	byte * u1;
} Eq_188;

typedef struct Eq_191 {	// size: 1 1
	ptr32 ptr0000;	// 0
} Eq_191;

