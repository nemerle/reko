// test.h
// Generated by decompiling test
// using Reko decompiler version 0.11.6.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals"
		(400416 code t400416)
		(400426 code t400426)
		(400436 code t400436)
		(40053D Eq_19 t40053D)
		(400550 Eq_22 t400550)
		(4005C0 Eq_23 t4005C0)
		(600E10 (arr (ptr64 code)) a600E10)
		(600E20 word64 qw600E20)
		(600FF8 (ptr64 code) __gmon_start___GOT)
		(601018 (ptr64 code) putchar_GOT)
		(601020 (ptr64 code) __libc_start_main_GOT)
		(601028 (ptr64 code) __gmon_start___GOT)
		(601040 byte b601040))
	globals_t (in globals : (ptr64 (struct "Globals")))
Eq_6: (fn word64 ())
	T_6 (in __gmon_start__ @ 00000000004003F0 : ptr64)
Eq_9: (fn void ())
	T_9 (in rdx @ 00000000004003F0 : (ptr64 Eq_9))
	T_24 (in rtld_fini @ 0000000000400464 : (ptr64 (fn void ())))
Eq_12: (fn void ((ptr64 (ptr64 char))))
	T_12 (in __align_stack<word64> @ 0000000000400449 : ptr32)
	T_13 (in signature of __align_stack : void)
Eq_17: (fn int32 ((ptr64 Eq_19), int32, (ptr64 (ptr64 char)), (ptr64 Eq_22), (ptr64 Eq_23), (ptr64 Eq_9), (ptr64 void)))
	T_17 (in __libc_start_main @ 0000000000400464 : ptr64)
	T_18 (in signature of __libc_start_main : void)
Eq_19: (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))
	T_19 (in main @ 0000000000400464 : (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))))
	T_26 (in 0x40053D<64> @ 0000000000400464 : word64)
Eq_22: (fn void ())
	T_22 (in init @ 0000000000400464 : (ptr64 (fn void ())))
	T_30 (in 0x400550<64> @ 0000000000400464 : word64)
Eq_23: (fn void ())
	T_23 (in fini @ 0000000000400464 : (ptr64 (fn void ())))
	T_31 (in 0x4005C0<64> @ 0000000000400464 : word64)
Eq_34: (fn void ())
	T_34 (in __halt @ 0000000000400469 : ptr32)
	T_35 (in signature of __halt : void)
Eq_47: (fn void ())
	T_47 (in deregister_tm_clones @ 00000000004004ED : ptr64)
	T_48 (in signature of deregister_tm_clones @ 0000000000400470 : void)
Eq_57: (fn void (uint64))
	T_57 (in fn0000000000000000 @ 000000000040051D : ptr64)
Eq_61: (fn void ())
	T_61 (in register_tm_clones @ 0000000000400520 : ptr64)
	T_62 (in signature of register_tm_clones @ 00000000004004A0 : void)
	T_64 (in register_tm_clones @ 0000000000400528 : ptr64)
Eq_67: (fn int32 (int32))
	T_67 (in putchar @ 000000000040053C : ptr64)
	T_68 (in signature of putchar : void)
Eq_72: (fn word32 ())
	T_72 (in f @ 0000000000400546 : ptr64)
	T_73 (in signature of f @ 000000000040052D : void)
Eq_80: (fn void ())
	T_80 (in _init @ 000000000040057E : ptr64)
	T_81 (in signature of _init @ 00000000004003E0 : void)
Eq_83: (union "Eq_83" (int64 u0) (ptr64 u1))
	T_83 (in 0000000000600E18 @ 0000000000400571 : ptr64)
Eq_87: (union "Eq_87" (int64 u0) (uint64 u1))
	T_87 (in 0<u64> @ 0000000000400574 : uint64)
	T_88 (in rbx_33 @ 0000000000400574 : Eq_87)
	T_97 (in rbx_33 + 1<64> @ 000000000040059D : word64)
	T_98 (in rbp_31 >> 3<64> @ 00000000004005A4 : word64)
// Type Variables ////////////
globals_t: (in globals : (ptr64 (struct "Globals")))
  Class: Eq_1
  DataType: (ptr64 Eq_1)
  OrigDataType: (ptr64 (struct "Globals"))
T_2: (in __gmon_start__ @ 00000000004003EE : ptr64)
  Class: Eq_2
  DataType: word64
  OrigDataType: 
T_3: (in signature of __gmon_start__ : void)
  Class: Eq_3
  DataType: Eq_3
  OrigDataType: 
T_4: (in 0<64> @ 00000000004003EE : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_5: (in __gmon_start__ == 0<64> @ 00000000004003EE : bool)
  Class: Eq_5
  DataType: bool
  OrigDataType: bool
T_6: (in __gmon_start__ @ 00000000004003F0 : ptr64)
  Class: Eq_6
  DataType: (ptr64 Eq_6)
  OrigDataType: (ptr64 (fn T_8 ()))
T_7: (in signature of __gmon_start__ : void)
  Class: Eq_7
  DataType: Eq_7
  OrigDataType: 
T_8: (in __gmon_start__() @ 00000000004003F0 : word64)
  Class: Eq_8
  DataType: word64
  OrigDataType: word64
T_9: (in rdx @ 00000000004003F0 : (ptr64 Eq_9))
  Class: Eq_9
  DataType: (ptr64 Eq_9)
  OrigDataType: (ptr64 (fn void ()))
T_10: (in dwArg00 @ 00000000004003F0 : word32)
  Class: Eq_10
  DataType: word32
  OrigDataType: word32
T_11: (in ptrArg08 @ 00000000004003F0 : (ptr64 char))
  Class: Eq_11
  DataType: (ptr64 char)
  OrigDataType: (ptr64 char)
T_12: (in __align_stack<word64> @ 0000000000400449 : ptr32)
  Class: Eq_12
  DataType: (ptr32 Eq_12)
  OrigDataType: (ptr32 (fn T_16 (T_15)))
T_13: (in signature of __align_stack : void)
  Class: Eq_12
  DataType: (ptr32 Eq_12)
  OrigDataType: 
T_14: (in p1 @ 0000000000400449 : word64)
  Class: Eq_14
  DataType: (ptr64 (ptr64 char))
  OrigDataType: 
T_15: (in &ptrArg08 @ 0000000000400449 : (ptr64 (ptr64 char)))
  Class: Eq_14
  DataType: (ptr64 (ptr64 char))
  OrigDataType: (ptr64 (ptr64 char))
T_16: (in __align_stack<word64>(&ptrArg08) @ 0000000000400449 : void)
  Class: Eq_16
  DataType: void
  OrigDataType: void
T_17: (in __libc_start_main @ 0000000000400464 : ptr64)
  Class: Eq_17
  DataType: (ptr64 Eq_17)
  OrigDataType: (ptr64 (fn T_33 (T_26, T_28, T_29, T_30, T_31, T_9, T_32)))
T_18: (in signature of __libc_start_main : void)
  Class: Eq_17
  DataType: (ptr64 Eq_17)
  OrigDataType: 
T_19: (in main @ 0000000000400464 : (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char))))))
  Class: Eq_19
  DataType: (ptr64 Eq_19)
  OrigDataType: 
T_20: (in argc @ 0000000000400464 : int32)
  Class: Eq_20
  DataType: int32
  OrigDataType: 
T_21: (in ubp_av @ 0000000000400464 : (ptr64 (ptr64 char)))
  Class: Eq_21
  DataType: (ptr64 (ptr64 char))
  OrigDataType: 
T_22: (in init @ 0000000000400464 : (ptr64 (fn void ())))
  Class: Eq_22
  DataType: (ptr64 Eq_22)
  OrigDataType: 
T_23: (in fini @ 0000000000400464 : (ptr64 (fn void ())))
  Class: Eq_23
  DataType: (ptr64 Eq_23)
  OrigDataType: 
T_24: (in rtld_fini @ 0000000000400464 : (ptr64 (fn void ())))
  Class: Eq_9
  DataType: (ptr64 Eq_9)
  OrigDataType: 
T_25: (in stack_end @ 0000000000400464 : (ptr64 void))
  Class: Eq_25
  DataType: (ptr64 void)
  OrigDataType: 
T_26: (in 0x40053D<64> @ 0000000000400464 : word64)
  Class: Eq_19
  DataType: (ptr64 Eq_19)
  OrigDataType: (ptr64 (fn int32 (int32, (ptr64 (ptr64 char)), (ptr64 (ptr64 char)))))
T_27: (in qwArg00 @ 0000000000400464 : word64)
  Class: Eq_27
  DataType: word64
  OrigDataType: word64
T_28: (in SLICE(qwArg00, int32, 0) @ 0000000000400464 : int32)
  Class: Eq_20
  DataType: int32
  OrigDataType: int32
T_29: (in &ptrArg08 @ 0000000000400464 : (ptr64 (ptr64 char)))
  Class: Eq_21
  DataType: (ptr64 (ptr64 char))
  OrigDataType: (ptr64 (ptr64 char))
T_30: (in 0x400550<64> @ 0000000000400464 : word64)
  Class: Eq_22
  DataType: (ptr64 Eq_22)
  OrigDataType: (ptr64 (fn void ()))
T_31: (in 0x4005C0<64> @ 0000000000400464 : word64)
  Class: Eq_23
  DataType: (ptr64 Eq_23)
  OrigDataType: (ptr64 (fn void ()))
T_32: (in fp @ 0000000000400464 : (ptr64 void))
  Class: Eq_25
  DataType: (ptr64 void)
  OrigDataType: (ptr64 void)
T_33: (in __libc_start_main(&g_t40053D, (int32) qwArg00, &ptrArg08, &g_t400550, &g_t4005C0, rdx, fp) @ 0000000000400464 : int32)
  Class: Eq_33
  DataType: int32
  OrigDataType: int32
T_34: (in __halt @ 0000000000400469 : ptr32)
  Class: Eq_34
  DataType: (ptr32 Eq_34)
  OrigDataType: (ptr32 (fn T_36 ()))
T_35: (in signature of __halt : void)
  Class: Eq_34
  DataType: (ptr32 Eq_34)
  OrigDataType: 
T_36: (in __halt() @ 0000000000400469 : void)
  Class: Eq_36
  DataType: void
  OrigDataType: void
T_37: (in true @ 0000000000400483 : bool)
  Class: Eq_37
  DataType: bool
  OrigDataType: bool
T_38: (in true @ 000000000040048F : bool)
  Class: Eq_38
  DataType: bool
  OrigDataType: bool
T_39: (in 0<u64> @ 0000000000400497 : uint64)
  Class: Eq_39
  DataType: (ptr64 code)
  OrigDataType: (ptr64 code)
T_40: (in false @ 00000000004004C0 : bool)
  Class: Eq_40
  DataType: bool
  OrigDataType: bool
T_41: (in true @ 00000000004004CC : bool)
  Class: Eq_41
  DataType: bool
  OrigDataType: bool
T_42: (in 0<u64> @ 00000000004004D7 : uint64)
  Class: Eq_42
  DataType: (ptr64 code)
  OrigDataType: (ptr64 code)
T_43: (in 0000000000601040 @ 00000000004004E7 : ptr64)
  Class: Eq_43
  DataType: (ptr64 byte)
  OrigDataType: (ptr64 (struct (0 T_44 t0000)))
T_44: (in Mem0[0x0000000000601040<p64>:byte] @ 00000000004004E7 : byte)
  Class: Eq_44
  DataType: byte
  OrigDataType: byte
T_45: (in 0<8> @ 00000000004004E7 : byte)
  Class: Eq_44
  DataType: byte
  OrigDataType: byte
T_46: (in g_b601040 != 0<8> @ 00000000004004E7 : bool)
  Class: Eq_46
  DataType: bool
  OrigDataType: bool
T_47: (in deregister_tm_clones @ 00000000004004ED : ptr64)
  Class: Eq_47
  DataType: (ptr64 Eq_47)
  OrigDataType: (ptr64 (fn T_49 ()))
T_48: (in signature of deregister_tm_clones @ 0000000000400470 : void)
  Class: Eq_47
  DataType: (ptr64 Eq_47)
  OrigDataType: 
T_49: (in deregister_tm_clones() @ 00000000004004ED : void)
  Class: Eq_49
  DataType: void
  OrigDataType: void
T_50: (in 1<8> @ 00000000004004F3 : byte)
  Class: Eq_44
  DataType: byte
  OrigDataType: byte
T_51: (in Mem20[0x0000000000601040<p64>:byte] @ 00000000004004F3 : byte)
  Class: Eq_44
  DataType: byte
  OrigDataType: byte
T_52: (in 0000000000600E20 @ 0000000000400508 : ptr64)
  Class: Eq_52
  DataType: (ptr64 word64)
  OrigDataType: (ptr64 (struct (0 T_53 t0000)))
T_53: (in Mem0[0x0000000000600E20<p64>:word64] @ 0000000000400508 : word64)
  Class: Eq_53
  DataType: word64
  OrigDataType: word64
T_54: (in 0<64> @ 0000000000400508 : word64)
  Class: Eq_53
  DataType: word64
  OrigDataType: word64
T_55: (in g_qw600E20 == 0<64> @ 0000000000400508 : bool)
  Class: Eq_55
  DataType: bool
  OrigDataType: bool
T_56: (in true @ 0000000000400512 : bool)
  Class: Eq_56
  DataType: bool
  OrigDataType: bool
T_57: (in fn0000000000000000 @ 000000000040051D : ptr64)
  Class: Eq_57
  DataType: (ptr64 Eq_57)
  OrigDataType: (ptr64 (fn T_60 (T_59)))
T_58: (in signature of fn0000000000000000 : void)
  Class: Eq_58
  DataType: Eq_58
  OrigDataType: 
T_59: (in 0x600E20<u64> @ 000000000040051D : uint64)
  Class: Eq_59
  DataType: uint64
  OrigDataType: uint64
T_60: (in fn0000000000000000(0x600E20<u64>) @ 000000000040051D : void)
  Class: Eq_60
  DataType: void
  OrigDataType: void
T_61: (in register_tm_clones @ 0000000000400520 : ptr64)
  Class: Eq_61
  DataType: (ptr64 Eq_61)
  OrigDataType: (ptr64 (fn T_63 ()))
T_62: (in signature of register_tm_clones @ 00000000004004A0 : void)
  Class: Eq_61
  DataType: (ptr64 Eq_61)
  OrigDataType: 
T_63: (in register_tm_clones() @ 0000000000400520 : void)
  Class: Eq_63
  DataType: void
  OrigDataType: void
T_64: (in register_tm_clones @ 0000000000400528 : ptr64)
  Class: Eq_61
  DataType: (ptr64 Eq_61)
  OrigDataType: (ptr64 (fn T_65 ()))
T_65: (in register_tm_clones() @ 0000000000400528 : void)
  Class: Eq_63
  DataType: void
  OrigDataType: void
T_66: (in eax @ 0000000000400528 : int32)
  Class: Eq_66
  DataType: int32
  OrigDataType: word32
T_67: (in putchar @ 000000000040053C : ptr64)
  Class: Eq_67
  DataType: (ptr64 Eq_67)
  OrigDataType: (ptr64 (fn T_71 (T_70)))
T_68: (in signature of putchar : void)
  Class: Eq_67
  DataType: (ptr64 Eq_67)
  OrigDataType: 
T_69: (in c @ 000000000040053C : int32)
  Class: Eq_69
  DataType: int32
  OrigDataType: 
T_70: (in 120<i32> @ 000000000040053C : int32)
  Class: Eq_69
  DataType: int32
  OrigDataType: int32
T_71: (in putchar(120<i32>) @ 000000000040053C : int32)
  Class: Eq_66
  DataType: int32
  OrigDataType: int32
T_72: (in f @ 0000000000400546 : ptr64)
  Class: Eq_72
  DataType: (ptr64 Eq_72)
  OrigDataType: (ptr64 (fn T_74 ()))
T_73: (in signature of f @ 000000000040052D : void)
  Class: Eq_72
  DataType: (ptr64 Eq_72)
  OrigDataType: 
T_74: (in f() @ 0000000000400546 : word32)
  Class: Eq_74
  DataType: word32
  OrigDataType: word32
T_75: (in rdx @ 000000000040054C : word64)
  Class: Eq_75
  DataType: word64
  OrigDataType: word64
T_76: (in rsi @ 000000000040054C : word64)
  Class: Eq_76
  DataType: word64
  OrigDataType: word64
T_77: (in edi @ 000000000040054C : word32)
  Class: Eq_77
  DataType: word32
  OrigDataType: word32
T_78: (in rdi @ 0000000000400550 : word64)
  Class: Eq_78
  DataType: word64
  OrigDataType: word64
T_79: (in SLICE(rdi, word32, 0) @ 0000000000400550 : word32)
  Class: Eq_77
  DataType: word32
  OrigDataType: word32
T_80: (in _init @ 000000000040057E : ptr64)
  Class: Eq_80
  DataType: (ptr64 Eq_80)
  OrigDataType: (ptr64 (fn T_82 ()))
T_81: (in signature of _init @ 00000000004003E0 : void)
  Class: Eq_80
  DataType: (ptr64 Eq_80)
  OrigDataType: 
T_82: (in _init() @ 000000000040057E : void)
  Class: Eq_82
  DataType: void
  OrigDataType: void
T_83: (in 0000000000600E18 @ 0000000000400571 : ptr64)
  Class: Eq_83
  DataType: int64
  OrigDataType: (union (int64 u0) (ptr64 u1))
T_84: (in 0000000000600E10 @ 0000000000400571 : ptr64)
  Class: Eq_84
  DataType: (ptr64 (arr (ptr64 code)))
  OrigDataType: (union ((ptr64 (arr Eq_100)) u1) ((ptr64 (arr Eq_100)) u0))
T_85: (in 0x600E18<u64> - g_a600E10 @ 0000000000400571 : word64)
  Class: Eq_85
  DataType: int64
  OrigDataType: int64
T_86: (in rbp_31 @ 0000000000400571 : int64)
  Class: Eq_85
  DataType: int64
  OrigDataType: int64
T_87: (in 0<u64> @ 0000000000400574 : uint64)
  Class: Eq_87
  DataType: uint64
  OrigDataType: uint64
T_88: (in rbx_33 @ 0000000000400574 : Eq_87)
  Class: Eq_87
  DataType: Eq_87
  OrigDataType: uint64
T_89: (in 3<64> @ 0000000000400586 : word64)
  Class: Eq_89
  DataType: word64
  OrigDataType: word64
T_90: (in rbp_31 >> 3<64> @ 0000000000400586 : word64)
  Class: Eq_90
  DataType: int64
  OrigDataType: int64
T_91: (in 0<64> @ 0000000000400586 : word64)
  Class: Eq_90
  DataType: int64
  OrigDataType: word64
T_92: (in rbp_31 >> 3<64> == 0<64> @ 0000000000400586 : bool)
  Class: Eq_92
  DataType: bool
  OrigDataType: bool
T_93: (in 8<64> @ 0000000000400599 : word64)
  Class: Eq_93
  DataType: ui64
  OrigDataType: ui64
T_94: (in rbx_33 * 8<64> @ 0000000000400599 : word64)
  Class: Eq_94
  DataType: ui64
  OrigDataType: ui64
T_95: (in 0x0000000000600E10<p64>[rbx_33 * 8<64>] @ 0000000000400599 : word64)
  Class: Eq_95
  DataType: (ptr64 code)
  OrigDataType: (ptr64 code)
T_96: (in 1<64> @ 000000000040059D : word64)
  Class: Eq_96
  DataType: word64
  OrigDataType: word64
T_97: (in rbx_33 + 1<64> @ 000000000040059D : word64)
  Class: Eq_87
  DataType: Eq_87
  OrigDataType: uint64
T_98: (in rbp_31 >> 3<64> @ 00000000004005A4 : word64)
  Class: Eq_87
  DataType: Eq_87
  OrigDataType: int64
T_99: (in rbx_33 != rbp_31 >> 3<64> @ 00000000004005A4 : bool)
  Class: Eq_99
  DataType: bool
  OrigDataType: bool
T_100:
  Class: Eq_100
  DataType: (ptr64 code)
  OrigDataType: (struct 0008 (0 T_95 t0000))
T_101:
  Class: Eq_101
  DataType: (arr (ptr64 code))
  OrigDataType: (arr T_100)
*/
typedef struct Globals {
	<anonymous> t400416;	// 400416
	<anonymous> t400426;	// 400426
	<anonymous> t400436;	// 400436
	Eq_19 t40053D;	// 40053D
	Eq_22 t400550;	// 400550
	Eq_23 t4005C0;	// 4005C0
	<anonymous> * a600E10[];	// 600E10
	word64 qw600E20;	// 600E20
	<anonymous> * __gmon_start___GOT;	// 600FF8
	<anonymous> * putchar_GOT;	// 601018
	<anonymous> * __libc_start_main_GOT;	// 601020
	<anonymous> * __gmon_start___GOT;	// 601028
	byte b601040;	// 601040
} Eq_1;

typedef word64 (Eq_6)();

typedef void (Eq_9)();

typedef void (Eq_12)(char * *);

typedef int32 (Eq_17)( *, int32, char * *,  *,  *,  *, void);

typedef int32 (Eq_19)(int32 rdi, char * * rsi, char * * rdx);

typedef void (Eq_22)();

typedef void (Eq_23)();

typedef void (Eq_34)();

typedef void (Eq_47)();

typedef void (Eq_57)(uint64);

typedef void (Eq_61)();

typedef int32 (Eq_67)(int32);

typedef word32 (Eq_72)();

typedef void (Eq_80)();

typedef union Eq_83 {
	int64 u0;
	ptr64 u1;
} Eq_83;

typedef union Eq_87 {
	int64 u0;
	uint64 u1;
} Eq_87;

