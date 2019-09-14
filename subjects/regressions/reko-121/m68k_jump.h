// m68k_jump.h
// Generated by decompiling m68k_jump.bin
// using Reko decompiler version 0.8.2.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals" (FF0F04 int32 dwFF0F04) (FF0F08 int32 dwFF0F08))
	globals_t (in globals : (ptr32 (struct "Globals")))
Eq_2: (struct "Eq_2" (0 int32 dw0000) (4 (arr byte) a0004))
	T_2 (in a0 : (ptr32 Eq_2))
// Type Variables ////////////
globals_t: (in globals : (ptr32 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr32 Eq_1)
  OrigDataType: (ptr32 (struct "Globals"))
T_2: (in a0 : (ptr32 Eq_2))
  Class: Eq_2
  DataType: (ptr32 Eq_2)
  OrigDataType: (ptr32 (struct (0 T_6 t0000) (4 T_76 t0004)))
T_3: (in a1 : (ptr32 word32))
  Class: Eq_3
  DataType: (ptr32 word32)
  OrigDataType: word32
T_4: (in 0x00000000 : word32)
  Class: Eq_4
  DataType: word32
  OrigDataType: word32
T_5: (in a0 + 0x00000000 : word32)
  Class: Eq_5
  DataType: word32
  OrigDataType: word32
T_6: (in Mem0[a0 + 0x00000000:word32] : word32)
  Class: Eq_6
  DataType: int32
  OrigDataType: word32
T_7: (in 00FF0F08 : ptr32)
  Class: Eq_7
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_8 t0000)))
T_8: (in Mem54[0x00FF0F08:word32] : word32)
  Class: Eq_6
  DataType: int32
  OrigDataType: word32
T_9: (in 0 : int32)
  Class: Eq_9
  DataType: int32
  OrigDataType: int32
T_10: (in 00FF0F04 : ptr32)
  Class: Eq_10
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_11 t0000)))
T_11: (in Mem57[0x00FF0F04:word32] : word32)
  Class: Eq_9
  DataType: int32
  OrigDataType: word32
T_12: (in a6_127 : (ptr32 word32))
  Class: Eq_3
  DataType: (ptr32 word32)
  OrigDataType: (ptr32 (struct 0004 (0 word32 dw0000)))
T_13: (in a4_105 : int32)
  Class: Eq_13
  DataType: int32
  OrigDataType: int32
T_14: (in 0 : int32)
  Class: Eq_13
  DataType: int32
  OrigDataType: int32
T_15: (in 00FF0F04 : ptr32)
  Class: Eq_15
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_16 t0000)))
T_16: (in Mem57[0x00FF0F04:word32] : word32)
  Class: Eq_9
  DataType: int32
  OrigDataType: int32
T_17: (in 00FF0F08 : ptr32)
  Class: Eq_17
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_18 t0000)))
T_18: (in Mem57[0x00FF0F08:word32] : word32)
  Class: Eq_6
  DataType: int32
  OrigDataType: int32
T_19: (in globals->dwFF0F04 - globals->dwFF0F08 : word32)
  Class: Eq_19
  DataType: int32
  OrigDataType: int32
T_20: (in 0x00000000 : word32)
  Class: Eq_19
  DataType: int32
  OrigDataType: int32
T_21: (in globals->dwFF0F04 - globals->dwFF0F08 < 0x00000000 : bool)
  Class: Eq_21
  DataType: bool
  OrigDataType: bool
T_22: (in d3_108 : ui32)
  Class: Eq_22
  DataType: ui32
  OrigDataType: ui32
T_23: (in SLICE(a4_105, word24, 8) : word24)
  Class: Eq_23
  DataType: word24
  OrigDataType: word24
T_24: (in 4 : int32)
  Class: Eq_24
  DataType: int32
  OrigDataType: int32
T_25: (in a0 + 4 : word32)
  Class: Eq_25
  DataType: (ptr32 (arr byte))
  OrigDataType: (ptr32 (struct (0 (arr T_75) a0000)))
T_26: (in a0 + 4 + a4_105 : word32)
  Class: Eq_26
  DataType: (ptr32 byte)
  OrigDataType: (ptr32 (struct (0 T_27 t0000)))
T_27: (in Mem57[a0 + 4 + a4_105:byte] : byte)
  Class: Eq_27
  DataType: byte
  OrigDataType: byte
T_28: (in SEQ(SLICE(a4_105, word24, 8), Mem57[a0 + 4 + a4_105:byte]) : uip32)
  Class: Eq_22
  DataType: ui32
  OrigDataType: uip32
T_29: (in d0_113 : uipr32)
  Class: Eq_29
  DataType: uipr32
  OrigDataType: uipr32
T_30: (in 0x000000FF : word32)
  Class: Eq_30
  DataType: ui32
  OrigDataType: ui32
T_31: (in d3_108 & 0x000000FF : word32)
  Class: Eq_31
  DataType: ui32
  OrigDataType: ui32
T_32: (in SLICE(d3_108 & 0x000000FF, word16, 16) : word16)
  Class: Eq_32
  DataType: word16
  OrigDataType: word16
T_33: (in d3_108 & 0x000000FF : word32)
  Class: Eq_33
  DataType: ui32
  OrigDataType: ui32
T_34: (in SLICE(d3_108 & 0x000000FF, word16, 0) : word16)
  Class: Eq_34
  DataType: cui16
  OrigDataType: cui16
T_35: (in 0x00F0 : word16)
  Class: Eq_35
  DataType: cui16
  OrigDataType: cui16
T_36: (in (word16) (d3_108 & 0x000000FF) & 0x00F0 : word16)
  Class: Eq_36
  DataType: cui16
  OrigDataType: cui16
T_37: (in SEQ(SLICE(d3_108 & 0x000000FF, word16, 16), SLICE(d3_108 & 0x000000FF, word16, 0) & 0x00F0) : uipr32)
  Class: Eq_29
  DataType: uipr32
  OrigDataType: uipr32
T_38: (in d0_116 : uip32)
  Class: Eq_38
  DataType: uip32
  OrigDataType: uip32
T_39: (in SLICE(d0_113, word24, 8) : word24)
  Class: Eq_39
  DataType: word24
  OrigDataType: word24
T_40: (in SLICE(d0_113, byte, 0) : byte)
  Class: Eq_40
  DataType: bcu8
  OrigDataType: bcu8
T_41: (in 0x02 : byte)
  Class: Eq_41
  DataType: byte
  OrigDataType: byte
T_42: (in (byte) d0_113 >> 0x02 : byte)
  Class: Eq_42
  DataType: uint8
  OrigDataType: uint8
T_43: (in SEQ(SLICE(d0_113, word24, 8), SLICE(d0_113, byte, 0) >>u 0x02) : uip32)
  Class: Eq_38
  DataType: uip32
  OrigDataType: uip32
T_44: (in 1 : int32)
  Class: Eq_44
  DataType: int32
  OrigDataType: int32
T_45: (in a4_105 + 1 : word32)
  Class: Eq_13
  DataType: int32
  OrigDataType: int32
T_46: (in SLICE(d0_116, word16, 0) : word16)
  Class: Eq_46
  DataType: ci16
  OrigDataType: ci16
T_47: (in 0x002C : word16)
  Class: Eq_46
  DataType: ci16
  OrigDataType: ci16
T_48: (in (word16) d0_116 > 0x002C : bool)
  Class: Eq_48
  DataType: bool
  OrigDataType: bool
T_49: (in SLICE(d0_116, word16, 0) : word16)
  Class: Eq_49
  DataType: word16
  OrigDataType: word16
T_50: (in d3_123 : ui32)
  Class: Eq_50
  DataType: ui32
  OrigDataType: ui32
T_51: (in d3_108 & 0x000000FF : word32)
  Class: Eq_51
  DataType: ui32
  OrigDataType: ui32
T_52: (in 15 : int32)
  Class: Eq_52
  DataType: int32
  OrigDataType: int32
T_53: (in d3_108 & 0x000000FF & 15 : word32)
  Class: Eq_53
  DataType: ui32
  OrigDataType: ui32
T_54: (in 0x00000001 : word32)
  Class: Eq_54
  DataType: word32
  OrigDataType: word32
T_55: (in (d3_108 & 0x000000FF & 15) + 0x00000001 : word32)
  Class: Eq_50
  DataType: ui32
  OrigDataType: ui32
T_56: (in v36_128 : word16)
  Class: Eq_56
  DataType: word16
  OrigDataType: word16
T_57: (in SLICE(d3_123, word16, 0) : word16)
  Class: Eq_56
  DataType: word16
  OrigDataType: word16
T_58: (in SLICE(d3_123, word16, 16) : word16)
  Class: Eq_58
  DataType: word16
  OrigDataType: word16
T_59: (in 1 : int16)
  Class: Eq_59
  DataType: int16
  OrigDataType: int16
T_60: (in v36_128 - 1 : word16)
  Class: Eq_60
  DataType: word16
  OrigDataType: word16
T_61: (in SEQ(SLICE(d3_123, word16, 16), v36_128 - 1) : uipr32)
  Class: Eq_50
  DataType: ui32
  OrigDataType: uipr32
T_62: (in 0x0000 : word16)
  Class: Eq_56
  DataType: word16
  OrigDataType: word16
T_63: (in v36_128 != 0x0000 : bool)
  Class: Eq_63
  DataType: bool
  OrigDataType: bool
T_64: (in 0 : int32)
  Class: Eq_64
  DataType: int32
  OrigDataType: int32
T_65: (in 0x00000000 : word32)
  Class: Eq_65
  DataType: word32
  OrigDataType: word32
T_66: (in a6_127 + 0x00000000 : word32)
  Class: Eq_66
  DataType: word32
  OrigDataType: word32
T_67: (in Mem133[a6_127 + 0x00000000:word32] : word32)
  Class: Eq_64
  DataType: int32
  OrigDataType: word32
T_68: (in 00FF0F04 : ptr32)
  Class: Eq_68
  DataType: (ptr32 int32)
  OrigDataType: (ptr32 (struct (0 T_9 t0000)))
T_69: (in Mem133[0x00FF0F04:word32] : word32)
  Class: Eq_9
  DataType: int32
  OrigDataType: word32
T_70: (in 0x00000004 : word32)
  Class: Eq_70
  DataType: word32
  OrigDataType: word32
T_71: (in globals->dwFF0F04 + 0x00000004 : word32)
  Class: Eq_9
  DataType: int32
  OrigDataType: word32
T_72: (in Mem136[0x00FF0F04:word32] : word32)
  Class: Eq_9
  DataType: int32
  OrigDataType: word32
T_73: (in 4 : int32)
  Class: Eq_73
  DataType: int32
  OrigDataType: int32
T_74: (in a6_127 + 4 : word32)
  Class: Eq_3
  DataType: (ptr32 word32)
  OrigDataType: ptr32
T_75:
  Class: Eq_75
  DataType: byte
  OrigDataType: (struct 0001 (0 T_27 t0000))
T_76:
  Class: Eq_76
  DataType: (arr byte)
  OrigDataType: (arr T_75)
*/
typedef struct Globals {
	int32 dwFF0F04;	// FF0F04
	int32 dwFF0F08;	// FF0F08
} Eq_1;

typedef struct Eq_2 {
	int32 dw0000;	// 0
	byte a0004[];	// 4
} Eq_2;

