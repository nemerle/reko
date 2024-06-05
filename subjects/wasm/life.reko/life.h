// life.h
// Generated by decompiling life.wasm
// using Reko decompiler version 0.11.6.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals")
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_11: (union "Eq_11" (ui32 u0) (ptr32 u1))
	T_11 (in arg0 * 0x2710<32> + 0x10<32> @ 000C006C : word32)
	T_12 (in loc1_131 @ 000C006C : Eq_11)
	T_92 (in loc1_131 + 0x64<32> @ 000C013E : word32)
Eq_91: (union "Eq_91" (ui32 u0) (ptr32 u1))
	T_91 (in 0x64<32> @ 000C013E : word32)
Eq_95: (union "Eq_95" (bool u0) (word32 u1))
	T_95 (in v17_24 == 0x64<32> @ 000C014F : bool)
	T_96 (in 0<32> @ 000C014F : word32)
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in  : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_3: (in arg0 : word32)
  Class: Eq_3
  DataType: word32
  OrigDataType: word32
T_4: (in arg1 : word32)
  Class: Eq_4
  DataType: word32
  OrigDataType: word32
T_5: (in arg2 : word32)
  Class: Eq_5
  DataType: word32
  OrigDataType: word32
T_6: (in <invalid> @ 000C005F : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_7: (in arg0 @ 000C005F : ui32)
  Class: Eq_7
  DataType: ui32
  OrigDataType: ui32
T_8: (in 0x2710<32> @ 000C006C : word32)
  Class: Eq_8
  DataType: ui32
  OrigDataType: ui32
T_9: (in arg0 * 0x2710<32> @ 000C006C : word32)
  Class: Eq_9
  DataType: ui32
  OrigDataType: ui32
T_10: (in 0x10<32> @ 000C006C : word32)
  Class: Eq_10
  DataType: word32
  OrigDataType: word32
T_11: (in arg0 * 0x2710<32> + 0x10<32> @ 000C006C : word32)
  Class: Eq_11
  DataType: Eq_11
  OrigDataType: ui32
T_12: (in loc1_131 @ 000C006C : Eq_11)
  Class: Eq_11
  DataType: Eq_11
  OrigDataType: (union (ui32 u0) (ptr32 u1))
T_13: (in 1<32> @ 000C007B : word32)
  Class: Eq_13
  DataType: ui32
  OrigDataType: ui32
T_14: (in 1<32> - arg0 @ 000C007B : word32)
  Class: Eq_14
  DataType: ui32
  OrigDataType: ui32
T_15: (in 0x2710<32> @ 000C007B : word32)
  Class: Eq_15
  DataType: ui32
  OrigDataType: ui32
T_16: (in (1<32> - arg0) * 0x2710<32> @ 000C007B : word32)
  Class: Eq_16
  DataType: ui32
  OrigDataType: ui32
T_17: (in 0x10<32> @ 000C007B : word32)
  Class: Eq_17
  DataType: word32
  OrigDataType: word32
T_18: (in (1<32> - arg0) * 0x2710<32> + 0x10<32> @ 000C007B : word32)
  Class: Eq_18
  DataType: (ptr32 (arr byte))
  OrigDataType: ui32
T_19: (in loc2_135 @ 000C007B : (ptr32 (arr byte)))
  Class: Eq_18
  DataType: (ptr32 (arr byte))
  OrigDataType: (ptr32 (struct (0 (arr T_105) a0000)))
T_20: (in 0xFFFFFFFF<32> @ 000C007F : word32)
  Class: Eq_20
  DataType: word32
  OrigDataType: word32
T_21: (in arg0_139 @ 000C007F : word32)
  Class: Eq_20
  DataType: word32
  OrigDataType: word32
T_22: (in 1<32> @ 000C0089 : word32)
  Class: Eq_22
  DataType: word32
  OrigDataType: word32
T_23: (in arg0_139 + 1<32> @ 000C0089 : word32)
  Class: Eq_20
  DataType: word32
  OrigDataType: word32
T_24: (in v17_24 @ 000C0089 : word32)
  Class: Eq_20
  DataType: word32
  OrigDataType: word32
T_25: (in 0x64<32> @ 000C0094 : word32)
  Class: Eq_20
  DataType: word32
  OrigDataType: word32
T_26: (in v17_24 == 0x64<32> @ 000C0094 : bool)
  Class: Eq_26
  DataType: bool
  OrigDataType: bool
T_27: (in 0<32> @ 000C0094 : word32)
  Class: Eq_27
  DataType: word32
  OrigDataType: word32
T_28: (in v17_24 == 0x64<32> ? 0<32> : v17_24 @ 000C0094 : word32)
  Class: Eq_28
  DataType: ui32
  OrigDataType: word32
T_29: (in v16_30 @ 000C0094 : ui32)
  Class: Eq_28
  DataType: ui32
  OrigDataType: ui32
T_30: (in 0<32> @ 000C009B : word32)
  Class: Eq_30
  DataType: word32
  OrigDataType: word32
T_31: (in arg0_139 + 0<32> @ 000C009B : word32)
  Class: Eq_31
  DataType: int32
  OrigDataType: word32
T_32: (in v16_34 @ 000C009B : int32)
  Class: Eq_31
  DataType: int32
  OrigDataType: int32
T_33: (in 0<32> @ 000C00A4 : word32)
  Class: Eq_33
  DataType: int32
  OrigDataType: word32
T_34: (in loc12_39 @ 000C00A4 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_35: (in 0<32> @ 000C00AA : word32)
  Class: Eq_35
  DataType: word32
  OrigDataType: word32
T_36: (in loc13_102 @ 000C00AA : word32)
  Class: Eq_35
  DataType: word32
  OrigDataType: word32
T_37: (in arg0 * 0x2710<32> @ 000C00B4 : word32)
  Class: Eq_37
  DataType: ui32
  OrigDataType: ui32
T_38: (in 0x10<32> @ 000C00B4 : word32)
  Class: Eq_38
  DataType: word32
  OrigDataType: word32
T_39: (in arg0 * 0x2710<32> + 0x10<32> @ 000C00B4 : word32)
  Class: Eq_39
  DataType: ui32
  OrigDataType: ui32
T_40: (in v16_45 @ 000C00B4 : ui32)
  Class: Eq_39
  DataType: ui32
  OrigDataType: ui32
T_41: (in 1<32> @ 000C00C8 : word32)
  Class: Eq_41
  DataType: word32
  OrigDataType: word32
T_42: (in loc12_39 + 1<32> @ 000C00C8 : word32)
  Class: Eq_33
  DataType: int32
  OrigDataType: word32
T_43: (in v18_58 @ 000C00C8 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: word32
T_44: (in 0x64<32> @ 000C00BD : word32)
  Class: Eq_44
  DataType: int32
  OrigDataType: int32
T_45: (in v16_34 % 0x64<32> @ 000C00BD : word32)
  Class: Eq_45
  DataType: int32
  OrigDataType: int32
T_46: (in 0x64<32> @ 000C00BD : word32)
  Class: Eq_46
  DataType: ui32
  OrigDataType: ui32
T_47: (in v16_34 % 0x64<32> * 0x64<32> @ 000C00BD : word32)
  Class: Eq_47
  DataType: ui32
  OrigDataType: ui32
T_48: (in v16_45 + (v16_34 % 0x64<32>) * 0x64<32> @ 000C00BD : word32)
  Class: Eq_48
  DataType: (ptr32 (arr byte))
  OrigDataType: ui32
T_49: (in v16_51 @ 000C00BD : (arr byte))
  Class: Eq_48
  DataType: (ptr32 (arr byte))
  OrigDataType: (union ((ptr32 (arr Eq_99)) u0) (ptr32 u1))
T_50: (in 0x63<32> @ 000C00D1 : word32)
  Class: Eq_33
  DataType: int32
  OrigDataType: word32
T_51: (in loc12_39 == 0x63<32> @ 000C00D1 : bool)
  Class: Eq_51
  DataType: bool
  OrigDataType: bool
T_52: (in 0<32> @ 000C00D1 : word32)
  Class: Eq_52
  DataType: word32
  OrigDataType: word32
T_53: (in loc12_39 == 0x63<32> ? 0<32> : v18_58 @ 000C00D1 : word32)
  Class: Eq_53
  DataType: int32
  OrigDataType: word32
T_54: (in v17_63 @ 000C00D1 : int32)
  Class: Eq_53
  DataType: int32
  OrigDataType: int32
T_55: (in 0xFFFFFFFF<32> @ 000C00DE : word32)
  Class: Eq_55
  DataType: word32
  OrigDataType: word32
T_56: (in loc12_39 + 0xFFFFFFFF<32> @ 000C00DE : word32)
  Class: Eq_56
  DataType: int32
  OrigDataType: word32
T_57: (in v18_72 @ 000C00DE : int32)
  Class: Eq_56
  DataType: int32
  OrigDataType: int32
T_58: (in 0x64<32> @ 000C00F2 : word32)
  Class: Eq_58
  DataType: ui32
  OrigDataType: ui32
T_59: (in v16_30 * 0x64<32> @ 000C00F2 : word32)
  Class: Eq_59
  DataType: ui32
  OrigDataType: ui32
T_60: (in v16_45 + v16_30 * 0x64<32> @ 000C00F2 : word32)
  Class: Eq_60
  DataType: (ptr32 (arr byte))
  OrigDataType: ui32
T_61: (in v17_85 @ 000C00F2 : (arr byte))
  Class: Eq_60
  DataType: (ptr32 (arr byte))
  OrigDataType: (ptr32 (struct (0 (arr T_101) a0000)))
T_62: (in v16_51 + v17_63 @ 000C0104 : word32)
  Class: Eq_62
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_63 t0000)))
T_63: (in Mem66[v16_51 + v17_63:byte] @ 000C0104 : byte)
  Class: Eq_63
  DataType: byte
  OrigDataType: byte
T_64: (in 0x64<32> @ 000C0104 : word32)
  Class: Eq_64
  DataType: int32
  OrigDataType: int32
T_65: (in v18_72 % 0x64<32> @ 000C0104 : word32)
  Class: Eq_65
  DataType: int32
  OrigDataType: int32
T_66: (in v16_51 + v18_72 %s 0x64<32> @ 000C0104 : word32)
  Class: Eq_66
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_67 t0000)))
T_67: (in Mem66[v16_51 + v18_72 %s 0x64<32>:byte] @ 000C0104 : byte)
  Class: Eq_67
  DataType: byte
  OrigDataType: byte
T_68: (in v16_51[v17_63] + v16_51[v18_72 % 0x64<32>] @ 000C0104 : byte)
  Class: Eq_68
  DataType: byte
  OrigDataType: byte
T_69: (in v18_72 % 0x64<32> @ 000C0104 : word32)
  Class: Eq_69
  DataType: int32
  OrigDataType: int32
T_70: (in v17_85 + v18_72 %s 0x64<32> @ 000C0104 : word32)
  Class: Eq_70
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_71 t0000)))
T_71: (in Mem66[v17_85 + v18_72 %s 0x64<32>:byte] @ 000C0104 : byte)
  Class: Eq_71
  DataType: byte
  OrigDataType: byte
T_72: (in v16_51[v17_63] + v16_51[v18_72 % 0x64<32>] + v17_85[v18_72 % 0x64<32>] @ 000C0104 : byte)
  Class: Eq_72
  DataType: byte
  OrigDataType: byte
T_73: (in v17_85 + v17_63 @ 000C0104 : word32)
  Class: Eq_73
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_74 t0000)))
T_74: (in Mem66[v17_85 + v17_63:byte] @ 000C0104 : byte)
  Class: Eq_71
  DataType: byte
  OrigDataType: byte
T_75: (in v16_51[v17_63] + v16_51[v18_72 % 0x64<32>] + v17_85[v18_72 % 0x64<32>] + v17_85[v17_63] @ 000C0104 : byte)
  Class: Eq_75
  DataType: byte
  OrigDataType: byte
T_76: (in CONVERT(Mem66[v16_51 + v17_63:byte] + Mem66[v16_51 + v18_72 %s 0x64<32>:byte] + Mem66[v17_85 + v18_72 %s 0x64<32>:byte] + Mem66[v17_85 + v17_63:byte], byte, word32) @ 000C0104 : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_77: (in v16_97 @ 000C0104 : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_78: (in 3<32> @ 000C010A : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_79: (in v16_97 == 3<32> @ 000C010A : bool)
  Class: Eq_79
  DataType: bool
  OrigDataType: bool
T_80: (in 2<32> @ 000C0111 : word32)
  Class: Eq_76
  DataType: word32
  OrigDataType: word32
T_81: (in v16_97 != 2<32> @ 000C0111 : bool)
  Class: Eq_81
  DataType: bool
  OrigDataType: bool
T_82: (in loc1_131 + loc12_39 @ 000C011B : word32)
  Class: Eq_82
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_83 t0000)))
T_83: (in Mem66[loc1_131 + loc12_39:byte] @ 000C011B : byte)
  Class: Eq_83
  DataType: byte
  OrigDataType: byte
T_84: (in CONVERT(Mem66[loc1_131 + loc12_39:byte], byte, word32) @ 000C011B : word32)
  Class: Eq_35
  DataType: word32
  OrigDataType: word32
T_85: (in 1<32> @ 000C0122 : word32)
  Class: Eq_35
  DataType: word32
  OrigDataType: word32
T_86: (in SLICE(loc13_102, byte, 0) @ 000C012C : byte)
  Class: Eq_86
  DataType: byte
  OrigDataType: byte
T_87: (in loc2_135 + loc12_39 @ 000C012C : word32)
  Class: Eq_87
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_88 t0000)))
T_88: (in Mem122[loc2_135 + loc12_39:byte] @ 000C012C : byte)
  Class: Eq_86
  DataType: byte
  OrigDataType: byte
T_89: (in 0x64<32> @ 000C0135 : word32)
  Class: Eq_33
  DataType: int32
  OrigDataType: word32
T_90: (in v18_58 != 0x64<32> @ 000C0135 : bool)
  Class: Eq_90
  DataType: bool
  OrigDataType: bool
T_91: (in 0x64<32> @ 000C013E : word32)
  Class: Eq_91
  DataType: ui32
  OrigDataType: (union (ui32 u0) (ptr32 u1))
T_92: (in loc1_131 + 0x64<32> @ 000C013E : word32)
  Class: Eq_11
  DataType: Eq_11
  OrigDataType: (union (ui32 u0) (ptr32 u1))
T_93: (in 0x64<32> @ 000C0146 : word32)
  Class: Eq_93
  DataType: int32
  OrigDataType: int32
T_94: (in loc2_135 + 0x64<32> @ 000C0146 : word32)
  Class: Eq_18
  DataType: (ptr32 (arr byte))
  OrigDataType: ptr32
T_95: (in v17_24 == 0x64<32> @ 000C014F : bool)
  Class: Eq_95
  DataType: Eq_95
  OrigDataType: bool
T_96: (in 0<32> @ 000C014F : word32)
  Class: Eq_95
  DataType: word32
  OrigDataType: word32
T_97: (in v17_24 == 0x64<32> == 0<32> @ 000C014F : bool)
  Class: Eq_97
  DataType: bool
  OrigDataType: bool
T_98: (in  @ 000C0152 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_99:
  Class: Eq_99
  DataType: byte
  OrigDataType: (struct 0001 (0 T_67 t0000))
T_100:
  Class: Eq_100
  DataType: (arr byte)
  OrigDataType: (arr T_99)
T_101:
  Class: Eq_101
  DataType: byte
  OrigDataType: (struct 0001 (0 T_71 t0000))
T_102:
  Class: Eq_102
  DataType: (arr byte)
  OrigDataType: (arr T_101)
T_103:
  Class: Eq_101
  DataType: byte
  OrigDataType: (struct 0001 (0 T_74 t0000))
T_104:
  Class: Eq_104
  DataType: (arr byte)
  OrigDataType: (arr T_103)
T_105:
  Class: Eq_105
  DataType: byte
  OrigDataType: (struct 0001 (0 T_88 t0000))
T_106:
  Class: Eq_106
  DataType: (arr byte)
  OrigDataType: (arr T_105)
*/
typedef struct Globals {
} Eq_1;

typedef union Eq_11 {
	ui32 u0;
	ptr32 u1;
} Eq_11;

typedef union Eq_91 {
	ui32 u0;
	ptr32 u1;
} Eq_91;

typedef union Eq_95 {
	bool u0;
	word32 u1;
} Eq_95;

