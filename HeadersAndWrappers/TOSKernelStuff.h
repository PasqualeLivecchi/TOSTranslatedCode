#ifndef TOS_KERNEL_STUFF
#define TOS_KERNEL_STUFF

#include "HolyCTypeWrappers.h"

struct CAOT;
struct CAOTHeapGlbl;
struct CAOTImportExport;
struct CCPU;
struct CDC;
struct CDirContext;
struct CDoc;
struct CFile;
struct CHashClass;
struct CHashFun;
struct CHeapCtrl;
struct CIntermediateCode;
struct CJobCtrl;
struct CTask;
struct CMathODE;

// lots of stuff below are very crude hacks which need to be re-done!
#define MEM_MAPPED_SPACE ( 2 << 31 )
#define NULL	0
#define TRUE	true
#define FALSE	false
#define ON	1
#define OFF	0
#define I8_MIN (-0x80)
#define I8_MAX 0x7F
#define U8_MIN 0
#define U8_MAX 0xFF
#define I16_MIN (-0x8000)
#define I16_MAX 0x7FFF
#define U16_MIN 0
#define U16_MAX 0xFFFF
#define I32_MIN (-0x80000000)
#define I32_MAX 0x7FFFFFFF
#define U32_MIN 0
#define U32_MAX 0xFFFFFFFF
#define MAX_U32 0xFFFFFFFF
#define I64_MIN (-0x8000000000000000)
#define I64_MAX 0x7FFFFFFFFFFFFFFF
#define U64_MIN 0
#define U64_MAX 0xFFFFFFFFFFFFFFFF
#define INVALID_PTR	I64_MAX
#define STR_LEN 144



#define U64_F64_MAX (0x43F0000000000000(F64))
#define F64_MAX (0x7FEFFFFFFFFFFFFF(F64))
#define F64_MIN (0xFFEFFFFFFFFFFFFF(F64))
#define inf	(0x7FF0000000000000(F64))
#define pi	(0x400921FB54442D18(F64))
#define exp_1	(0x4005BF0A8B145769(F64))
#define log2_10 (0x400A934F0979A371(F64))
#define log2_e	(0x3FF71547652B82FE(F64))
#define log10_2	(0x3FD34413509F79FF(F64))
#define loge_2	(0x3FE62E42FEFA39EF(F64))
#define sqrt2	(0x3FF6A09E667F3BCD(F64))
#define eps	(0x3CB0000000000000(F64))

/*HolyC union structure is treated as a
whole if no member is specified,
similar to bit fields.

See $LK,"EndianI64",A="MN:EndianI64"$() and $LK,"::/Demo/SubIntAccess.HC"$.
*/
union U16i
{
I8i	i8[2];
U8i	u8[2];
};

union I16i
{
I8i	i8[2];
U8i	u8[2];
};

union U32i
{
I8i	i8[4];
U8i	u8[4];
I16	i16[2];
U16	u16[2];
};

union I32i
{
I8i	i8[4];
U8i	u8[4];
I16	i16[2];
U16	u16[2];
};

union U64i
{
I8i	i8[8];
U8i	u8[8];
I16	i16[4];
U16	u16[4];
I32	i32[2];
U32	u32[2];
};

union I64i
{
I8i	i8[8];
U8i	u8[8];
I16	i16[4];
U16	u16[4];
I32	i32[2];
U32	u32[2];
};

typedef struct Complex
{
F64	x,y;
} Complex;

typedef struct CQue
{
struct CQue	*next,*last;
} CQue;

typedef struct CD3I32
{
I32	x,y,z;
} CD3I32;
typedef struct CQueD3I32
{
struct CQueD3I32	*next,*last;
struct CD3I32	p;
} CQueD3I32;
typedef struct CD2I32
{
I32	x,y;
} CD2I32;
typedef struct CD2I64
{
I64	x,y;
} CD2I64;
typedef struct CD3I64
{
I64	x,y,z;
} CD3I64;
typedef struct CD2
{
F64	x,y;
} CD2;

typedef struct CD3
{
F64	x,y,z;
} CD3;

#define QUE_VECT_U8_CNT		512
typedef struct CQueVectU8
{
struct CQueVectU8	*next,*last;
I64	total_cnt,node_cnt,min_idx;
U8	body[QUE_VECT_U8_CNT];
} CQueVectU8;

typedef struct CFifoU8
{
U8	*buf;
I64	mask,in_ptr,out_ptr;
} CFifoU8;
typedef struct CFifoI64
{
I64	*buf;
I64	mask,in_ptr,out_ptr;
} CFifoI64;

#define CDATE_YEAR_DAYS		365.24225
#define CDATE_YEAR_DAYS_INT	36524225
#define CDATE_BASE_DAY_OF_WEEK	0
typedef struct CDate
{
U32	time;
I32	date;
} CDate;

typedef struct CDateStruct
{
U8	sec10000,sec100,sec,min,hour,
day_of_week,day_of_mon,mon;
I32	year;
} CDateStruct;

typedef struct COrder2D3
{
F64	x,y,z,
DxDt,DyDt,DzDt;
} COrder2D3;

#define MSF_INACTIVE		1
#define MSF_FIXED		2
typedef struct CMass
{
struct CMass	*next,*last;
struct COrder2D3 *state,
*DstateDt;

U0	start;
U32	flags,num;
F64	mass,drag_profile_factor;
U0	saved_state;
F64	x,y,z,
DxDt,DyDt,DzDt;
U0	end;
} CMass;

#define SSF_INACTIVE		1
#define SSF_NO_COMPRESSION	2
#define SSF_NO_TENSION		4
typedef struct CSpring
{
struct CSpring *next,*last;
struct CMass	*end1,*end2;
F64	f,displacement;

U0	start;
U32	flags,num, end1_num,end2_num;
F64	springconst,rest_len;
U0	end;
} CSpring;


#define ODEF_HAS_MASSES	1
#define ODEF_PAUSED	2
#define ODEF_STARTED	4
#define ODEF_BUSY	8

#define ODEf_HAS_MASSES	0
#define ODEf_PAUSED	1
#define ODEf_STARTED	2
#define ODEf_BUSY	3



#define IDTET_TASK		0x05
#define IDTET_IRQ		0x0E
#define IDTET_TRAP		0x0F



#define I_DIV_ZERO		0x00
#define I_SINGLE_STEP		0x01
#define I_NMI			0x02
#define I_BPT			0x03
#define I_PAGE_FAULT		0x0E

#define I_TIMER			0x20

#define I_MP_CRASH		0x30
#define I_WAKE			0x31
#define I_DBG			0x32




#define I_USER			0x40

#define MP_PROCESSORS_NUM	128

#define SYS_START_CR0		0x0031

#define RFLAGf_CARRY		0
#define RFLAGf_PARITY		2
#define RFLAGf_AUX_CARRY	4
#define RFLAGf_ZERO		6
#define RFLAGf_SIGN		7
#define RFLAGf_TRAP		8
#define RFLAGf_INT		9
#define RFLAGf_DIR		10
#define RFLAGf_OVERFLOW		11
#define RFLAGf_IOPL0		12
#define RFLAGf_IOPL1		13
#define RFLAGf_NESTED_TASK	14
#define RFLAGf_RESUME		16
#define RFLAGf_V8086		17
#define RFLAGf_ALIGN_CHECK	18
#define RFLAGf_VINT		19
#define RFLAGf_VINT_PENDING	20
#define RFLAGf_ID		21

#define RFLAGG_START		0x0000
#define RFLAGG_NORMAL		(1<<RFLAGf_INT)


typedef struct CGDTEntry
{
U64	lo,hi;
} CGDTEntry;

typedef struct CGDT
{
struct CGDTEntry null;
struct CGDTEntry boot_ds;
struct CGDTEntry boot_cs;
struct CGDTEntry cs32;
struct CGDTEntry cs64;
struct CGDTEntry cs64_ring3;
struct CGDTEntry ds;
struct CGDTEntry ds_ring3;
struct CGDTEntry tr[MP_PROCESSORS_NUM];
struct CGDTEntry tr_ring3[MP_PROCESSORS_NUM];
} CGDT;

typedef struct CSysLimitBase
{
U16	limit;
U8	*base;
} CSysLimitBase;

#define MEM_E820_ENTRIES_NUM	48
typedef struct CMemE820
{
U8	*base;
I64	len;
U8	type,pad[3];
} CMemE820;


#define LDF_NO_ABSS		1
#define LDF_JUST_LOAD		2
#define LDF_SILENT		4

#define BIN_SIGNATURE_VAL	'TOSB'
typedef struct CBinFile
{
U16	jmp;
U8	module_align_bits,
reserved;
U32	bin_signature;
I64	org,
patch_table_offset,
file_size;
} CBinFile;

typedef struct CPatchTableAbsAddr
{
U8	eit_abs_addr;
U32	abs_addres_cnt;
U8	zero;
U32	abs_addres[1];
} CPatchTableAbsAddr;


#define IET_END			0

#define IET_REL_I0		2
#define IET_IMM_U0		3
#define IET_REL_I8		4
#define IET_IMM_U8		5
#define IET_REL_I16		6
#define IET_IMM_U16		7
#define IET_REL_I32		8
#define IET_IMM_U32		9
#define IET_REL_I64		10
#define IET_IMM_I64		11
#define IEF_IMM_NOT_REL		1

#define IET_REL32_EXPORT	16
#define IET_IMM32_EXPORT	17
#define IET_REL64_EXPORT	18
#define IET_IMM64_EXPORT	19
#define IET_ABS_ADDR		20
#define IET_CODE_HEAP		21
#define IET_ZEROED_CODE_HEAP	22
#define IET_DATA_HEAP		23
#define IET_ZEROED_DATA_HEAP	24
#define IET_MAIN		25

typedef struct CKernel
{
struct CBinFile h;
U32	jmp,
boot_src,
boot_blk,
boot_patch_table_base,
sys_run_level;
struct CDate	compile_time;

U0	start;
U32	boot_base;
U16	mem_E801[2];
struct CMemE820 mem_E820[MEM_E820_ENTRIES_NUM];
U64	mem_physical_space;
struct CSysLimitBase sys_gdt_ptr;
U16	sys_pci_busses;
struct CGDT	sys_gdt;
} CKernel;


#define RLf_16BIT		0
#define RLf_VGA			1
#define RLf_32BIT		2
#define RLf_PATCHED		3
#define RLf_16MEG_SYS_CODE_BP	4
#define RLf_64BIT		5
#define RLf_16MEG_ADAM_HEAP_CTRL 6
#define RLf_FULL_HEAPS		7
#define RLf_RAW			8
#define RLf_INTERRUPTS		9
#define RLf_BLKDEV		10
#define RLf_MP			11
#define RLf_COMPILER		12
#define RLf_DOC			13
#define RLf_WINMGR		14
#define RLf_REGISTRY		15
#define RLf_HOME		16
#define RLf_AUTO_COMPLETE	17
#define RLf_ADAM_SERVER		18
#define RLf_ONCE_ADAM		19
#define RLf_ONCE_USER		20

#define RLF_16BIT		0x000001
#define RLF_VGA			0x000002
#define RLF_32BIT		0x000004
#define RLF_PATCHED		0x000008
#define RLF_16MEG_SYS_CODE_BP	0x000010
#define RLF_64BIT		0x000020
#define RLF_16MEG_ADAM_HEAP_CTRL 0x000040
#define RLF_FULL_HEAPS		0x000050
#define RLF_RAW			0x000100
#define RLF_INTERRUPTS		0x000200
#define RLF_BLKDEV		0x000400
#define RLF_MP			0x000800
#define RLF_COMPILER		0x001000
#define RLF_DOC			0x002000
#define RLF_WINMGR		0x004000
#define RLF_REGISTRY		0x008000
#define RLF_HOME		0x010000
#define RLF_AUTO_COMPLETE	0x020000
#define RLF_ADAM_SERVER		0x040000
#define RLF_ONCE_ADAM		0x080000
#define RLF_ONCE_USER		0x100000

#define LAPIC_BASE		0xFEE00000

#define LAPIC_APIC_ID		(LAPIC_BASE+0x020)
#define LAPIC_APIC_VERSION	(LAPIC_BASE+0x030)
#define LAPIC_TASK_PRIORITY	(LAPIC_BASE+0x080)
#define LAPIC_ARIBITRATION_PRIORITY (LAPIC_BASE+0x090)
#define LAPIC_PROCESSOR_PRIORITY (LAPIC_BASE+0x0A0)
#define LAPIC_EOI		(LAPIC_BASE+0x0B0)
#define LAPIC_LOG_DST		(LAPIC_BASE+0x0D0)
#define LAPIC_DFR		(LAPIC_BASE+0x0E0)
#define LAPIC_LDR		(LAPIC_BASE+0x0D0)

#define LAPICF_APIC_ENABLED	0x100
#define LAPIC_SVR		(LAPIC_BASE+0x0F0)

#define LAPIC_ISR		(LAPIC_BASE+0x100)
#define LAPIC_TMR		(LAPIC_BASE+0x180)
#define LAPIC_IRR		(LAPIC_BASE+0x200)
#define LAPIC_ICR_LOW		(LAPIC_BASE+0x300)
#define LAPIC_ICR_HIGH		(LAPIC_BASE+0x310)

#define LAPIC_LVT_TIMER		(LAPIC_BASE+0x320)
#define LAPIC_LVT_THERMAL	(LAPIC_BASE+0x330)
#define LAPIC_LVT_PERF		(LAPIC_BASE+0x340)
#define LAPIC_LVT_LINT0		(LAPIC_BASE+0x350)
#define LAPIC_LVT_LINT1		(LAPIC_BASE+0x360)
#define LAPIC_LVT_ERR		(LAPIC_BASE+0x370)

#define MPN_VECT		0x97
#define MP_VECT_ADDR		(MPN_VECT*0x1000)


#define IOAPIC_REG		0xFEC00000
#define IOAPIC_DATA		0xFEC00010

#define IOAPICID		0x00
#define IOAPICVER		0x01
#define IOAPICARB		0x02
#define IOREDTAB		0x10


#define IA32F_SCE	0x001
#define IA32F_LME	0x100
#define IA32_LAPIC_BASE	0x01B
#define IA32_EFER	0xC0000080
#define IA32_FS_BASE	0xC0000100
#define IA32_GS_BASE	0xC0000101

typedef struct CAP16BitInit
{
U32	jmp;
struct CSysLimitBase ap_gdt_ptr;
} CAP16BitInit;


#define HPET_GCAP_ID	(0xFED00000+0x00)
#define HPET_GEN_CONF	(0xFED00000+0x10)
#define HPET_MAIN_CNT	(0xFED00000+0xF0)

typedef struct CCntsGlbls
{
I64	jiffies,
timer,
time_stamp_freq,
time_stamp_kHz_freq,
time_stamp_freq_initial,
HPET_freq,
HPET_kHz_freq,
HPET_initial;
Bool	time_stamp_calibrated;
} CCntsGlbls;

#define JIFFY_FREQ		1000
#define CDATE_FREQ		49710
#define SYS_TIMER_FREQ		(18333*65536/1000)
#define SYS_TIMER0_PERIOD	(65536*182/10/JIFFY_FREQ)


#define SF_RBP	0x00
#define SF_RIP	0x08
#define SF_ARG1	0x10
#define SF_ARG2	0x18
#define SF_ARG3	0x20
#define SF_ARG4	0x28
#define SF_ARG5	0x30
#define SF_ARG6	0x38
#define SF_ARG7	0x40
#define SF_ARG8	0x48

typedef struct CRAXRBCRCXRDX
{
I64	rax,rbx,rcx,rdx;
} CRAXRBCRCXRDX;



#define EXT_WIN_TO_TOP		0
#define EXT_WIN_FOCUS		1
#define EXT_HEAPLOG_MALLOC	2
#define EXT_HEAPLOG_FREE	3
#define EXT_DBG_RESUME		4
#define EXT_EXTS_NUM		5

#define DFT_CACHE_LINE_WIDTH	128


typedef struct CSema
{
Bool	val,pad[DFT_CACHE_LINE_WIDTH-1];
} CSema;
#define SEMA_DEBUG		0
#define SEMA_RECORD_MACRO	1
#define SEMA_SYS_TIMER		2
#define SEMA_SYS_DATE		3
#define SEMA_DBG_MODE		4
#define SEMA_SND		5
#define SEMA_HEAPLOG_ACTIVE	6
#define SEMA_HEAPLOG_LOCK	7
#define SEMA_REFRESH_IN_PROGRESS 8
#define SEMA_FLUSH_VGA_IMAGE	9
#define SEMA_SINGLE_USER	10
#define SEMA_DSK_CACHE		11
#define SEMA_FAR_CALL32		12
#define SEMA_DEV_MEM		13
#define SEMA_VGA		14
#define SEMA_UPDATE_WIN_Z_BUF	15
#define SEMA_TT			16
#define SEMA_MUTE		17
#define SEMA_JUST_PUMP_MSGS	18
#define SEMA_TMBEAT		19
#define SEMA_FIX		20
#define SEMA_SEMAS_NUM		21

#define CTRL_ALT_DEL		0
#define CTRL_ALT_C		1
#define CTRL_ALT_X		2
#define CTRL_ALT_TAB		3

typedef struct CHash
{
struct CHash	*next;
U8	*str;
U32	type,
use_cnt;
} CHash;

typedef struct CHashTable
{
struct CHashTable *next;
I64	mask,locked_flags;
struct CHash	**body;
} CHashTable;


#define HTt_EXPORT_SYS_SYM	0
#define HTt_IMPORT_SYS_SYM	1
#define HTt_DEFINE_STR		2
#define HTt_GLBL_VAR		3
#define HTt_CLASS		4
#define HTt_INTERNAL_TYPE	5
#define HTt_FUN			6
#define HTt_WORD		7
#define HTt_DICT_WORD		8
#define HTt_KEYWORD		9
#define HTt_ASM_KEYWORD		10
#define HTt_OPCODE		11
#define HTt_REG			12
#define HTt_FILE		13
#define HTt_MODULE		14
#define HTt_HELP_FILE		15
#define HTt_FRAME_PTR		16
#define HTt_TYPES_NUM		17

#define HTf_PRIVATE		23
#define HTf_PUBLIC		24
#define HTf_EXPORT		25
#define HTf_IMPORT		26
#define HTf_IMM			27
#define HTf_GOTO_LABEL		28
#define HTf_RESOLVED		29
#define HTf_UNRESOLVED		30
#define HTf_LOCAL		31

#define HTT_INVALID		0
#define HTT_EXPORT_SYS_SYM	0x00001
#define HTT_IMPORT_SYS_SYM	0x00002
#define HTT_DEFINE_STR		0x00004
#define HTT_GLBL_VAR		0x00008
#define HTT_CLASS		0x00010
#define HTT_INTERNAL_TYPE	0x00020
#define HTT_FUN			0x00040
#define HTT_WORD		0x00080
#define HTT_DICT_WORD		0x00100
#define HTT_KEYWORD		0x00200
#define HTT_ASM_KEYWORD		0x00400
#define HTT_OPCODE		0x00800
#define HTT_REG			0x01000
#define HTT_FILE		0x02000
#define HTT_MODULE		0x04000
#define HTT_HELP_FILE		0x08000
#define HTT_FRAME_PTR		0x10000
#define HTG_TYPE_MASK		0x1FFFF

#define HTF_PRIVATE		0x00800000
#define HTF_PUBLIC		0x01000000
#define HTF_EXPORT		0x02000000
#define HTF_IMPORT		0x04000000
#define HTF_IMM			0x08000000
#define HTF_GOTO_LABEL		0x10000000
#define HTF_RESOLVE		0x20000000
#define HTF_UNRESOLVED		0x40000000
#define HTF_LOCAL		0x80000000
#define HTG_FLAGS_MASK		0xFF000000

#define HTG_SRC_SYM	(HTT_DEFINE_STR|HTT_GLBL_VAR|HTT_FUN|HTT_CLASS|\
HTT_EXPORT_SYS_SYM|HTT_HELP_FILE)
#define HTG_ALL 		-1

#define KERNEL_MODULE_NAME	"/Kernel/Kernel"

typedef struct CDbgInfo
{
U32	min_line,max_line;
U32	body[1];
} CDbgInfo;

typedef struct CHashSrcSym
{
U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;


} CHashSrcSym;

typedef struct CHashGeneric
{
I64	user_data0,user_data1,user_data2;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;


} CHashGeneric;

#define REGT_NONE	0
#define REGT_R8		1
#define REGT_R16	2
#define REGT_R32	3
#define REGT_R64	4
#define REGT_SEG	5
#define REGT_FSTK	6
#define REGT_MM		7
#define REGT_XMM	8

typedef struct CHashReg
{
U8	reg_num,reg_type;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;


} CHashReg;

typedef struct CHashAC
{
I32	num;
U32	hits;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;


} CHashAC;

typedef struct CHashExport
{
I64	val;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;



} CHashExport;

typedef struct CHashImport
{
U8	*module_base,
*module_header_entry;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;



} CHashImport;

#define PTR_STARS_NUM	4


#define MLF_DFT_AVAILABLE	1
#define MLF_LASTCLASS		2
#define MLF_STR_DFT_AVAILABLE	4
#define MLF_FUN			8
#define MLF_DOT_DOT_DOT		16
#define MLF_NO_UNUSED_WARN	32
#define MLF_STATIC		64

typedef struct CArrayDim
{
struct CArrayDim *next;
I64	cnt,total_cnt;
} CArrayDim;

#define MLMF_IS_STR	1
typedef struct CMemberLstMeta
{
struct CMemberLstMeta *next;
U8	*str;
I64	flags,
user_data;
} CMemberLstMeta;

typedef struct CMemberLst
{
struct CMemberLst *next,*left,*right,
*left_class_base,*right_class_base;
U8	*str;
struct CHashClass *member_class,*member_class_base;
struct CMemberLstMeta *meta;
U32	use_cnt;
U16	flags;
I8	reg,pad;
I64	offset,size;
struct CArrayDim dim;
U8	*static_data;
I64	static_data_rip;
I64 dft_val;
struct CHashFun *fun_ptr;
} CMemberLst;

typedef struct CExternUsage
{
struct CExternUsage *next;
I64	rip;
} CExternUsage;

typedef struct CHashDefineStr
{
U8	*data,**sub_idx;
I64	cnt;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;



} CHashDefineStr;

#define Cf_EXTERN		0
#define Cf_INTERNAL_TYPE	1

typedef struct CHashClass
{
I64	size,neg_offset;
U32	member_cnt;
U8	ptr_stars_cnt,raw_type;
U16	flags;
struct CMemberLst *member_lst_and_root,
*member_class_base_root,
*last_in_member_lst;
struct CHashClass	*base_class,
*fwd_class;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;



} CHashClass;


#define Ff_INTERRUPT		8
#define Ff_HASERRCODE		9
#define Ff_ARGPOP		10
#define Ff_NOARGPOP		11
#define Ff_INTERNAL		12
#define Ff__EXTERN		13
#define Ff_DOT_DOT_DOT		14
#define Ff_RET1			15

typedef struct CHashFun
{
struct CHashClass *return_class;
U32	arg_cnt,pad,
used_reg_mask,clobbered_reg_mask;
U8	*exe_addr;
struct CExternUsage *ext_lst;

I64	size,neg_offset;
U32	member_cnt;
U8	ptr_stars_cnt,raw_type;
U16	flags;
struct CMemberLst *member_lst_and_root,
*member_class_base_root,
*last_in_member_lst;
struct CHashClass	*base_class,
*fwd_class;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;




} CHashFun;


#define GVF_FUN		1
#define GVF_IMPORT	2
#define GVF_EXTERN	4
#define GVF_DATA_HEAP	8
#define GVF_ALIAS	16
#define GVF_ARRAY	32

typedef struct CHashGlblVar
{
I64	size,flags;
struct CHashClass *var_class;
struct CHashFun *fun_ptr;
struct CArrayDim dim;
U8	*data_addr;
I64	data_addr_rip;
struct CAOTHeapGlbl *heap_glbl;

U8	*src_link,
*idx;
struct CDbgInfo *dbg_info;
U8	*import_name;
struct CAOTImportExport *ie_lst;

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;



} CHashGlblVar;


#define ATTRF_BLINK	0x10000000
#define ATTRF_INVERT	0x20000000
#define ATTRF_SEL	0x40000000
#define ATTRF_UNDERLINE	0x80000000

#define ATTRf_BLINK		28
#define ATTRf_INVERT		29
#define ATTRf_SEL		30
#define ATTRf_UNDERLINE		31


#define DOCT_TEXT		0
#define DOCT_NEW_LINE		1
#define DOCT_SOFT_NEW_LINE	2
#define DOCT_TAB		3
#define DOCT_PAGE_BREAK		4
#define DOCT_CURSOR		5
#define DOCT_MARKER		6
#define DOCT_PMT		7
#define DOCT_CLEAR		8
#define DOCT_PAGE_LEN		9
#define DOCT_LEFT_MARGIN	10
#define DOCT_RIGHT_MARGIN	11
#define DOCT_HEADER		12
#define DOCT_FOOTER		13
#define DOCT_INDENT		14
#define DOCT_FOREGROUND		15
#define DOCT_BACKGROUND		16
#define DOCT_DFT_FOREGROUND	17
#define DOCT_DFT_BACKGROUND	18
#define DOCT_WORD_WRAP		19
#define DOCT_HIGHLIGHT		20
#define DOCT_BLINK		21
#define DOCT_INVERT		22
#define DOCT_UNDERLINE		23
#define DOCT_SHIFTED_X		24
#define DOCT_SHIFTED_Y		25
#define DOCT_CURSOR_MOVEMENT	26
#define DOCT_ANCHOR		27
#define DOCT_LINK		28
#define DOCT_BTTN		29
#define DOCT_DATA		30
#define DOCT_CHECK_BOX		31
#define DOCT_LST		32
#define DOCT_MACRO		33
#define DOCT_MENU_VAL		34
#define DOCT_HEX_ED		35
#define DOCT_TREE		36
#define DOCT_SPRITE		37
#define DOCT_INS_BIN		38
#define DOCT_INS_BIN_SIZE	39
#define DOCT_SONG		40
#define DOCT_HTML_CODE		41
#define DOCT_ERROR		42

#define DOCT_TYPES_NUM		43


#define DOCET_BLINK		ATTRF_BLINK
#define DOCET_INVERT		ATTRF_INVERT
#define DOCET_SEL		ATTRF_SEL
#define DOCET_UNDERLINE		ATTRF_UNDERLINE
#define DOCG_BL_IV_UL		0xB0000000

#define DOCEt_BLINK		ATTRf_BLINK
#define DOCEt_INVERT		ATTRf_INVERT
#define DOCEt_SEL		ATTRf_SEL
#define DOCEt_UNDERLINE		ATTRf_UNDERLINE

#define DOCG_DBL_BUF_FLAGS	(DOCF_OVERSTRIKE|DOCF_PLAIN_TEXT|\
DOCF_PLAIN_TEXT_TABS|DOCF_SIZE_MIN|DOCF_NO_CURSOR|\
DOCF_FORM|DOCF_DBL_DOLLARS|DOCF_DONT_SWAP_OUT|\
DOCF_DO_FULL_REFRESH|DOCF_BORDER_DOC|DOCF_HIDE_CURSOR|\
DOCF_DONT_HIGHLIGHT_CURSOR|DOCF_CARRIAGE_RETURN)


#define DOCEF_TAG		1
#define DOCEF_LEN		2
#define DOCEF_AUX_STR		4
#define DOCEF_DEFINE		8
#define DOCEF_HTML_LINK		0x10
#define DOCEF_LEFT_EXP		0x20
#define DOCEF_LEFT_MACRO	0x40
#define DOCEF_RIGHT_EXP		0x80
#define DOCEF_RIGHT_MACRO	0x100
#define DOCEF_HAS_BIN		0x200
#define DOCEF_BIN_PTR_LINK	0x400
#define DOCEF_RAW_TYPE		0x800
#define DOCEF_SHIFTED_X		0x1000
#define DOCEF_SHIFTED_Y		0x2000
#define DOCEF_SCROLLING_X	0x4000
#define DOCEF_USER_DATA		0x8000


#define DOCEF_LEFT_CB		0x10000
#define DOCEF_LEFT_IN_STR	0x20000
#define DOCEF_RIGHT_CB		0x40000
#define DOCEF_RIGHT_IN_STR	0x80000
#define DOCEF_LEFT_X		0x100000
#define DOCEF_CENTER_X		0x200000
#define DOCEF_RIGHT_X		0x400000
#define DOCEF_TOP_Y		0x800000
#define DOCEF_CENTER_Y		0x1000000
#define DOCEF_BOTTOM_Y		0x2000000

#define DOCEF_TAG_CB		0x100000000
#define DOCEF_PAGE_REL_Y	0x200000000
#define DOCEF_MARGIN_REL_X	0x400000000
#define DOCEF_WIN_REL		0x800000000
#define DOCEF_LINK		0x1000000000
#define DOCEF_ESC		0x2000000000
#define DOCEF_QUIT		0x4000000000
#define DOCEF_FROM_START	0x8000000000
#define DOCEF_HAS_BORDER	0x10000000000
#define DOCEF_SOLID_BORDER	0x20000000000
#define DOCEF_BORDER_PLOT	0x40000000000
#define DOCEF_CHECKED_COLLAPSED 0x80000000000
#define DOCEF_CHECK_COLLAPSABLE 0x100000000000
#define DOCEF_REFRESH_DATA	0x200000000000
#define DOCEF_UPDATE_DATA	0x400000000000


#define DOCEF_DEREF_DATA	0x800000000000
#define DOCEF_REMALLOC_DATA	0x1000000000000
#define DOCEF_HAS_TERMINATOR	0x2000000000000
#define DOCEF_ZERO_BASED	0x4000000000000
#define DOCEF_HOLD		0x8000000000000
#define DOCEF_TREE		0x10000000000000
#define DOCEF_LST		0x20000000000000
#define DOCEF_SKIP		0x40000000000000
#define DOCEF_POPUP		0x80000000000000
#define DOCEF_SKIP_IN_FORM	0x100000000000000
#define DOCEF_FILTER_SKIP	0x200000000000000
#define DOCEF_NO_CLICK_ON	0x400000000000000
#define DOCEF_DONT_DRAW		0x800000000000000
#define DOCEF_DFT_LEN		0x1000000000000000
#define DOCEF_DFT_RAW_TYPE	0x2000000000000000

#define DOCEG_HAS_ALLOC		(DOCEF_TAG|DOCEF_AUX_STR|DOCEF_DEFINE|\
DOCEF_HTML_LINK|DOCEF_LEFT_MACRO|DOCEF_RIGHT_MACRO|DOCEF_BIN_PTR_LINK|\
DOCEF_REMALLOC_DATA)

#define DOCEG_HAS_ARG		((DOCEG_HAS_ALLOC&~DOCEF_REMALLOC_DATA)|\
DOCEF_LEN|DOCEF_LEFT_EXP|DOCEF_RIGHT_EXP|DOCEF_HAS_BIN|DOCEF_RAW_TYPE|\
DOCEF_SHIFTED_X|DOCEF_SHIFTED_Y|DOCEF_SCROLLING_X|DOCEF_USER_DATA)

#define DOCEG_DONT_EDIT	(DOCEF_DEFINE|DOCEF_HTML_LINK|\
DOCEF_AUX_STR|DOCEF_BIN_PTR_LINK|DOCEF_SCROLLING_X|DOCEF_TAG_CB)


#define DOCEF_HIGHLIGHT		0x4000000
#define DOCEF_WORD_WRAP		0x8000000
#define DOCEF_BLINK		ATTRF_BLINK
#define DOCEF_INVERT		ATTRF_INVERT
#define DOCEF_SEL		ATTRF_SEL
#define DOCEF_UNDERLINE		ATTRF_UNDERLINE
#define DOCEf_HIGHLIGHT		26
#define DOCEf_WORD_WRAP		27
#define DOCEf_BLINK		ATTRf_BLINK
#define DOCEf_INVERT		ATTRf_INVERT
#define DOCEf_SEL		ATTRf_SEL
#define DOCEf_UNDERLINE		ATTRf_UNDERLINE


#define DOCEf_TAG		0
#define DOCEf_LEN		1
#define DOCEf_AUX_STR		2
#define DOCEf_DEFINE		3
#define DOCEf_HTML_LINK		4
#define DOCEf_LEFT_EXP		5
#define DOCEf_LEFT_MACRO	6
#define DOCEf_RIGHT_EXP		7
#define DOCEf_RIGHT_MACRO	8
#define DOCEf_HAS_BIN		9
#define DOCEf_BIN_PTR_LINK	10
#define DOCEf_RAW_TYPE		11
#define DOCEf_SHIFTED_X		12
#define DOCEf_SHIFTED_Y		13
#define DOCEf_SCROLLING_X	14
#define DOCEf_USER_DATA		15


#define DOCEf_LEFT_CB		16
#define DOCEf_LEFT_IN_STR	17
#define DOCEf_RIGHT_CB		18
#define DOCEf_RIGHT_IN_STR	19
#define DOCEf_LEFT_X		20
#define DOCEf_CENTER_X		21
#define DOCEf_RIGHT_X		22
#define DOCEf_TOP_Y		23
#define DOCEf_CENTER_Y		24
#define DOCEf_BOTTOM_Y		25

#define DOCEf_TAG_CB		32
#define DOCEf_PAGE_REL_Y	33
#define DOCEf_MARGIN_REL_X	34
#define DOCEf_WIN_REL		35
#define DOCEf_LINK		36
#define DOCEf_ESC		37
#define DOCEf_QUIT		38
#define DOCEf_FROM_START	39
#define DOCEf_HAS_BORDER	40
#define DOCEf_SOLID_BORDER	41
#define DOCEf_BORDER_PLOT	42
#define DOCEf_CHECKED_COLLAPSED 43
#define DOCEf_CHECK_COLLAPSABLE 44
#define DOCEf_REFRESH_DATA	45
#define DOCEf_UPDATE_DATA	46
#define DOCEf_DEREF_DATA	47
#define DOCEf_REMALLOC_DATA	48
#define DOCEf_HAS_TERMINATOR	49
#define DOCEf_ZERO_BASED	50
#define DOCEf_HOLD		51
#define DOCEf_TREE		52
#define DOCEf_LST		53
#define DOCEf_SKIP		54
#define DOCEf_POPUP		55
#define DOCEf_SKIP_IN_FORM	56
#define DOCEf_FILTER_SKIP	57
#define DOCEf_NO_CLICK_ON	58
#define DOCEf_DONT_DRAW		59
#define DOCEf_DFT_LEN		60
#define DOCEf_DFT_RAW_TYPE	61
#define DOCEf_FLAGS_NUM		62

typedef struct CDocBin
{
struct CDocBin *next,*last;
I32	tmp_use_cnt,renum_num;
U8	*tag;
U0	start;
U32	num,flags,size,use_cnt;
U0	end;
U8	*data;
} CDocBin;

#define DOC_SCROLL_SPEED	8

#define DOCSS_NORMAL		0
#define DOCSS_SINGLE_QUOTE	1
#define DOCSS_DBL_QUOTE		2
#define DOCSS_COMMENT		3
#define DOCSS_CPP_Z_COMMENT	4

#define DOC_ATTR_DFT_TEXT	WHITE<<4+BLACK
#define DOC_COLOR_ALT_TEXT	LTGRAY
#define DOC_COLOR_LINK		RED
#define DOC_COLOR_MACRO		LTBLUE
#define DOC_COLOR_ANCHOR	DKGRAY
#define DOC_COLOR_TREE		PURPLE
#define DOC_COLOR_PMT		GREEN
#define DOC_COLOR_COMMENT	GREEN
#define DOC_COLOR_BIN		LTGREEN
#define DOC_COLOR_STR		BROWN
#define DOC_COLOR_CHAR_CONST	BROWN
#define DOC_COLOR_EXPORT_SYS_SYM LTPURPLE
#define DOC_COLOR_DEFINE_STR	CYAN
#define DOC_COLOR_GLBL_VAR	LTCYAN
#define DOC_COLOR_CLASS		LTBLUE
#define DOC_COLOR_FUN		PURPLE
#define DOC_COLOR_KEYWORD	BLUE
#define DOC_COLOR_REG		LTRED

typedef struct CDocSettings
{
U32	final_u32_attr;
I16	left_margin,right_margin,indent;
U16	page_len,header,footer;
I8	shifted_x,shifted_y;
U8	state,comment_depth,paren_depth,brace_depth,
cur_text_attr,dft_text_attr;
} CDocSettings;

#define DOC_DFT 		I32_MIN

typedef struct CDocEntryBase
{



struct CDocEntryBase *next,*last;
U8	*tag;
U8	type_u8;
U32 type;
I32	page_line_num;
I64	de_flags;
I32	x,y;
U32	min_col,max_col;
struct CDocSettings settings;
I64	user_data;
} CDocEntryBase;

#define DOCE_LEN_DFT	64

typedef struct CDocEntry
{
I64 attr;
I64 cursor_x_offset;
I64 (*left_cb)(struct CDoc *doc,struct CDocEntry *doc_e);
I64 left_exp;
U8	*left_macro;

I64 cursor_y_offset;
I64 (*right_cb)(struct CDoc *doc,struct CDocEntry *doc_e);
I64 right_exp;
U8	*right_macro;

U8	*(*tag_cb)(struct CDoc *doc,struct CDocEntry *doc_e,struct CTask *mem_task);
U8	*define_str,
*aux_str,
*bin_ptr_link,
*html_link,
*my_fmt_data;
I64	hex_ed_width;
I32	scroll_len,
len,
bin_num;
U8	raw_type,pad[3];
struct CDocBin *bin_data;
U8	*data;




struct CDocEntryBase *next,*last;
U8	*tag;
U8	type_u8;
U32 type;
I32	page_line_num;
I64	de_flags;
I32	x,y;
U32	min_col,max_col;
struct CDocSettings settings;
I64	user_data;


} CDocEntry;


#define	DOF_SIZE_MIN		0x01
#define	DOF_INTERCEPT_TASK_END	0x02
#define DOF_DONT_HOME		0x04
#define DOF_WIN_MAX		0x08
#define DOF_DONT_TEXT_ATTR	0x10
#define DOF_DONT_WINMGR_SYNC	0x20
#define DOF_DONT_SHOW		0x40


typedef struct CEdFindText
{
U8	find_text[STR_LEN];// format "$$DA-P,"
//"A=\"Find        :%s\"$$\n",
U8 replace_text[STR_LEN];// format "$$DA-P,"
//"A=\"Replace     :%s\"$$\n";
Bool	replace;//			format "$$CB,\"Replace\"$$\n",
Bool scan_fwd;//		format "$$CB,\"Fwd\"$$\n",
Bool scan_sel_text;//		format "$$CB,\"Selection\"$$\n",
Bool match_case;//		format "$$CB,\"Match Case\"$$\n",
Bool whole_labels;//		format "$$CB,\"Whole Labels\"$$\n",
Bool local_var;//		format "$$CB,\"Rename Local Var\"$$\n",
Bool pmt,pad;
I64	filter_lines;//		format "$$DA,A=\"Filter Lines:%d\"$$\n";
} CEdFindText;

typedef struct CEdFileName
{
struct CDirContext *dirc;
U8	name[256]; // format "$$DA-P,LEN=255,A=\"FileName:%s\"$$";
} CEdFileName;


#define EDF_BAIL		0x100
#define EDF_COLLAPSE		0x200
#define EDF_UNCOLLAPSE		0x400
#define EDF_WAS_WRITE		0x800


#define EDf_BAIL		8
#define EDf_COLLAPSE		9
#define EDf_UNCOLLAPSE		10
#define EDf_WAS_WRITE		11


#define DOCF_PLAIN_TEXT 	0x1
#define DOCF_PLAIN_TEXT_TABS	0x2
#define DOCF_AUTO_SAVE		0x4
#define DOCF_NO_CURSOR		0x8
#define DOCF_CARRIAGE_RETURN	0x10
#define DOCF_DBL_DOLLARS	0x20
#define DOCF_COLOR_NAMES	0x40

#define DOCF_BORDER_DOC		0x100
#define DOCF_FORM		0x200
#define DOCF_SIZE_MIN		0x400
#define DOCF_HIDE_CURSOR	0x800
#define DOCF_DONT_HIGHLIGHT_CURSOR 0x1000
#define DOCF_NO_SCROLL_BARS	0x2000
#define DOCF_ALLOW_UNDO		0x4000
#define DOCF_DONT_SHOW		0x8000
#define DOCF_HAS_SONG		0x10000
#define DOCF_MORE		0x20000
#define DOCF_BWD_MOVEMENT	0x40000
#define DOCF_NULL_GRAB_SCROLL	0x80000
#define DOCF_DONT_SWAP_OUT	0x100000
#define DOCF_DO_FULL_REFRESH	0x200000
#define DOCF_BREAK_UNLOCKED	0x400000

#define DOCF_HIGHLIGHT		DOCEF_HIGHLIGHT
#define DOCF_WORD_WRAP		DOCEF_WORD_WRAP
#define DOCF_BLINK		DOCEF_BLINK
#define DOCF_INVERT		DOCEF_INVERT
#define DOCF_SEL		DOCEF_SEL
#define DOCF_UNDERLINE		DOCEF_UNDERLINE

#define DOCF_OVERSTRIKE 	0x100000000
#define DOCF_IN_DOLLAR		0x200000000
#define DOCF_SUPERSCRIPT_MODE	0x400000000
#define DOCF_SUBSCRIPT_MODE	0x800000000
#define DOCF_UNDO_DIRTY		0x1000000000

#define DOCf_PLAIN_TEXT 	0
#define DOCf_PLAIN_TEXT_TABS	1
#define DOCf_AUTO_SAVE		2
#define DOCf_NO_CURSOR		3
#define DOCf_CARRIAGE_RETURN	4
#define DOCf_DBL_DOLLARS	5
#define DOCf_COLOR_NAMES	6

#define DOCf_BORDER_DOC		8
#define DOCf_FORM		9
#define DOCf_SIZE_MIN		10
#define DOCf_HIDE_CURSOR	11
#define DOCf_DONT_HIGHLIGHT_CURSOR 12
#define DOCf_NO_SCROLL_BARS	13
#define DOCf_ALLOW_UNDO		14
#define DOCf_DONT_SHOW		15
#define DOCf_HAS_SONG		16
#define DOCf_MORE		17
#define DOCf_BWD_MOVEMENT	18
#define DOCf_NULL_GRAB_SCROLL	19
#define DOCf_DONT_SWAP_OUT	20
#define DOCf_DO_FULL_REFRESH	21
#define DOCf_BREAK_UNLOCKED	22


#define DOCf_HIGHLIGHT		DOCEf_HIGHLIGHT
#define DOCf_WORD_WRAP		DOCEf_WORD_WRAP
#define DOCf_BLINK		DOCEf_BLINK
#define DOCf_INVERT		DOCEf_INVERT
#define DOCf_SEL		DOCEf_SEL
#define DOCf_UNDERLINE		DOCEf_UNDERLINE

#define DOCf_OVERSTRIKE 	32
#define DOCf_IN_DOLLAR		33
#define DOCf_SUPERSCRIPT_MODE	34
#define DOCf_SUBSCRIPT_MODE	35
#define DOCf_UNDO_DIRTY		36


#define DOClf_LOCKED		0
typedef struct CDocUndo
{
struct CDocUndo *next,*last;
I64	size,doc_flags,time_stamp;
U8	*body;
} CDocUndo;


#define DOCM_CANCEL		(-1)

#define DOC_SIGNATURE_VAL	'DocS'

#define RECALCt_NORMAL		0x00
#define RECALCt_FIND_CURSOR	0x01
#define RECALCt_TO_SCRN		0x02
#define RECALCG_MASK		0xFF

#define RECALCF_HAS_CURSOR	0x100
#define RECALCF_ADD_CURSOR	0x200
#define RECALCF_TO_HTML		0x400

typedef struct CDoc
{
struct CDocEntryBase head;
I64	flags,locked_flags;
struct CDocEntry *cur_entry,*old_cur_entry;
I32	cur_col,old_cur_col,
line_start_col,top_line_num,
dollar_buf_size,dollar_buf_ptr;
U8	*dollar_buf;

struct CTask *win_task,*mem_task,*owning_task;
I32	page_line_num,undo_cnt,
x,y,min_x,max_x,min_y,max_y;
I64	line,col,best_d,
old_win_top,old_win_bottom,
old_win_left,old_win_right,
cmd_U8;
U32	doc_signature,cur_bin_num;
I64	max_entries,
updates_cnt;
struct CEdFindText *find_replace;

struct CEdFileName filename;
I64	file_attr;
I64	(*left_click_link)(struct CDoc *doc,struct CDocEntry *doc_e);
I64	(*right_click_link)(struct CDoc *doc,struct CDocEntry *doc_e);


U8	*user_put_data;
Bool	(*user_put_key)(struct CDoc *doc,U8 *data,I64 ch,I64 sc);
Bool	(*user_put_s)(struct CDoc *doc,U8 *data,U8 *st);

struct CDoc	*parent_doc;
U64	desc;

struct CDocBin bin_head;
struct CDocSettings settings_head;
struct CDocUndo undo_head;

I64	user_data;
} CDoc;

/*
Fs->win_inhibit mask

Some inhibit actions on the task itself.
Some inhibit actions if the focus task
tries to do something.
*/
#define WIF_SELF_FOCUS		0x0001

#define WIF_SELF_CTRLS		0x0004
#define WIF_SELF_MS_L		0x0008

#define WIF_SELF_MS_R		0x0020

#define WIF_SELF_MS_WHEEL	0x0080
#define WIF_SELF_BORDER		0x0100
#define WIF_SELF_GRAB_SCROLL	0x0200
#define WIF_SELF_DOC		0x0400
#define WIF_SELF_ODE		0x0800
#define WIF_SELF_KEY_DESC	0x1000

#define WIF_FOCUS_TASK_MENU	0x00020000
#define WIF_FOCUS_TASK_CTRLS	0x00040000
#define WIF_FOCUS_TASK_MS_L	0x00080000
#define WIF_FOCUS_TASK_MS_L_D	0x00100000
#define WIF_FOCUS_TASK_MS_R	0x00200000
#define WIF_FOCUS_TASK_MS_R_D	0x00400000
#define WIF_FOCUS_TASK_MS_WHEEL	0x00800000
#define WIF_FOCUS_TASK_BORDER	0x01000000
#define WIF_FOCUS_TASK_GRAB_SCROLL 0x02000000

#define WIG_DBL_CLICK		(WIF_FOCUS_TASK_MS_L_D|WIF_FOCUS_TASK_MS_R_D)
#define WIG_TASK_DFT		(WIF_FOCUS_TASK_MENU|WIG_DBL_CLICK|\
0xFFFF-WIF_SELF_DOC-WIF_SELF_ODE)
#define WIG_NO_FOCUS_TASK_DFT	(WIG_TASK_DFT-WIF_SELF_BORDER\
-WIF_SELF_MS_L-WIF_SELF_MS_R-WIG_DBL_CLICK)
#define WIG_USER_TASK_DFT	WIF_SELF_KEY_DESC

#define WIf_SELF_FOCUS		0
#define WIf_SELF_CTRLS		2
#define WIf_SELF_MS_L		3
#define WIf_SELF_MS_R		5
#define WIf_SELF_MS_WHEEL	7
#define WIf_SELF_BORDER		8
#define WIf_SELF_GRAB_SCROLL	9
#define WIf_SELF_DOC		10
#define WIf_SELF_ODE		11
#define WIf_SELF_KEY_DESC	12
#define WIf_FOCUS_TASK_MENU	17
#define WIf_FOCUS_TASK_CTRLS	18
#define WIf_FOCUS_TASK_MS_L	19
#define WIf_FOCUS_TASK_MS_L_D	20
#define WIf_FOCUS_TASK_MS_R	21
#define WIf_FOCUS_TASK_MS_R_D	22
#define WIf_FOCUS_TASK_MS_WHEEL	23
#define WIf_FOCUS_TASK_BORDER	24
#define WIf_FOCUS_TASK_GRAB_SCROLL 25

typedef struct CWinMgrTimingGlbls
{
I64	last_total_jiffies,
last_idle_pt_hits[MP_PROCESSORS_NUM],
last_swap_cnter[MP_PROCESSORS_NUM];
F64	last_calc_idle_time,calc_idle_delta_time;
I64	calc_idle_cnt;
} CWinMgrTimingGlbls;

#define WINMGR_FPS	(30000.0/1001)
#define WINMGR_PERIOD	(1001/30000.0)

typedef struct CWinMgrGlbls
{
I64	updates;
F64	ode_time,
last_ode_time,
fps,
ideal_refresh_tS,
last_refresh_tS;
struct CWinMgrTimingGlbls *t;
Bool	show_menu,grab_scroll,grab_scroll_closed;
} CWinMgrGlbls;

#define ACf_INIT_IN_PROGRESS	0
#define AC_FILLINS_NUM 10
typedef struct CAutoCompleteGlbls
{
I64	num_words;
struct CHashTable *hash_table;
U8	*cur_word;
I64	flags;
struct CTask	*task;
I64	partial_len,num_fillins,
fillin_hits	[AC_FILLINS_NUM+1];
struct CHashAC *fillin_matches[AC_FILLINS_NUM+1];
} CAutoCompleteGlbls;

#define ACD_WORD_FILENAME	"/Adam/AutoComplete/ACWords.DATA.Z"
#define ACD_DEF_FILENAME	"/Adam/AutoComplete/ACDefs.DATA"
#define ACD_DEF_FILENAME_Z	"/Adam/AutoComplete/ACDefs.DATA.Z"

#define ACD_H1			0
#define ACD_H1_END		1
#define ACD_DEF			2
#define ACD_DEF_END		3
#define ACD_PRONUNCIATION	4
#define ACD_PRONUNCIATION_END	5
#define ACD_POS			6
#define ACD_POS_END		7
#define ACD_EXTRA		8
#define ACD_EXTRA_END		9
#define ACD_BLK_SIZE		0x4000

#define ACD_END_CHAR		0x00
#define ACD_WORD_CHAR		0x01
#define ACD_DEF_CHAR		0x02
#define ACD_PRONUNCIATION_CHAR	0x03
#define ACD_POS_CHAR		0x04
#define ACD_EXTRA_CHAR		0x05

#define ACD_FILLINS_NUM 10
typedef struct CAutoCompleteDictGlbls
{
U8	*word_lst;
I64	word_lst_size,num_words,num_fillins;
U8	*fillins[ACD_FILLINS_NUM];
Bool	has_words,has_defs;
} CAutoCompleteDictGlbls;





#define OPTf_ECHO		0x00
#define OPTf_TRACE		0x01
#define OPTf_WARN_UNUSED_VAR	0x10
#define OPTf_WARN_PAREN		0x11
#define OPTf_WARN_DUP_TYPES	0x12
#define OPTf_WARN_HEADER_MISMATCH 0x13
#define OPTf_EXTERNS_TO_IMPORTS	0x20
#define OPTf_KEEP_PRIVATE	0x21
#define OPTf_NO_REG_VAR		0x22
#define OPTf_GLBLS_ON_DATA_HEAP	0x23

#define OPTf_NO_BUILTIN_CONST	0x24
#define OPTf_USE_IMM64		0x25

#define OPTF_ECHO		(1<<OPTf_ECHO)


#define RT_I0		2
#define RT_U0		3
#define RT_I8		4
#define RT_U8		5
#define RT_I16		6
#define RT_U16		7
#define RT_I32		8
#define RT_U32		9
#define RT_I64		10
#define RT_PTR		10
#define RT_U64		11
#define RT_F32		12
#define RT_UF32		13
#define RT_F64		14
#define RT_UF64		15
#define RT_RTS_NUM	16
#define RTF_UNSIGNED	1
#define RTG_MASK	0xFF

#define MDf_STK		8
#define MDf_IMM		9
#define MDf_REG		10
#define MDf_DISP	11
#define MDf_SIB		12
#define MDf_RIP_DISP32	13

#define MDF_NULL	0x0000
#define MDF_STK		0x0100
#define MDF_IMM		0x0200
#define MDF_REG		0x0400
#define MDF_DISP	0x0800
#define MDF_SIB		0x1000
#define MDF_RIP_DISP32	0x2000
#define MDG_MASK	0xFF00
#define MDG_REG_DISP_SIB	(MDF_REG|MDF_DISP|MDF_SIB)
#define MDG_DISP_SIB_RIP	(MDF_DISP|MDF_SIB|MDF_RIP_DISP32)
#define MDG_REG_DISP_SIB_RIP	(MDF_REG|MDG_DISP_SIB_RIP)

#define ICF_RES_TO_F64			0x000000001
#define ICF_RES_TO_INT			0x000000002
#define ICF_ARG1_TO_F64			0x000000004
#define ICF_ARG1_TO_INT			0x000000008
#define ICF_ARG2_TO_F64			0x000000010
#define ICF_ARG2_TO_INT			0x000000020
#define ICF_USE_F64			0x000000040
#define ICF_USE_UNSIGNED		0x000000080
#define ICF_USE_INT			0x000000100
#define ICF_RES_NOT_USED		0x000000200
#define ICF_CODE_FINAL			0x000000400
#define ICF_BY_VAL			0x000000800
#define ICF_SHORT_JMP			0x000001000
#define ICF_PUSH_RES			0x000002000
#define ICF_PASS_TRACE			0x000004000
#define ICF_RES_WAS_STK			0x000008000
#define ICF_ARG1_WAS_STK		0x000010000
#define ICF_ARG2_WAS_STK		0x000020000
#define ICF_PUSH_CMP			0x000040000
#define ICF_POP_CMP			0x000080000
#define ICF_SWAP			0x000100000
#define ICf_DONT_PUSH_FLOAT0		21
#define ICf_DONT_POP_FLOAT0		24
#define ICF_ALT_TEMPLATE		0x008000000
#define ICF_LOCK			0x010000000
#define ICf_LOCK			28
#define ICF_NO_RIP			0x020000000
#define ICF_DEL_PREV_INS		0x040000000
#define ICF_PREV_DELETED		0x080000000
#define ICF_DONT_RESTORE		0x100000000
#define ICG_NO_CVT_MASK			0x1FFFFFF00

#define IC_BODY_SIZE			0x83

#define ECF_HAS_PUSH_CMP		0x01

typedef struct CICType
{
U8	raw_type,mode;
} CICType;

typedef struct CICArg
{
struct CICType type;
U16	reg;
I64	disp;
} CICArg;

typedef struct CICTreeLinks
{
struct CHashClass *arg1_class,*arg2_class;
struct CIntermediateCode *arg1_tree,*arg2_tree;
struct CHashClass *class2;
} CICTreeLinks;

typedef struct CIntermediateCodeBase
{
struct CIntermediateCode *next,*last;
U16	ic_code,
ic_precedence;
I16	ic_cnt,
ic_last_start;
} CIntermediateCodeBase;

typedef struct CIntermediateCode
{
I64	ic_flags,
ic_data,
ic_line;
struct CHashClass *ic_class,*ic_class2;
struct CICArg arg1,arg2,res;
U8	arg1_type_pointed_to;
U8 ic_body[IC_BODY_SIZE];








struct CICTreeLinks t;

struct CIntermediateCode *next,*last;
U16	ic_code,
ic_precedence;
I16	ic_cnt,
ic_last_start;


} CIntermediateCode;

typedef struct CPrsStk
{
I64	ptr,
stk[255],
ptr2,
stk2[255];
} CPrsStk;

#define CMT_LABEL		0
#define CMT_ASM_LABEL		1
#define CMT_GOTO_LABEL		2
#define CMT_STR_CONST		3
#define CMT_JMP_TABLE		4
#define CMT_FLOAT_CONSTS	5
#define CMT_ARRAY_DIM		6
#define CMT_HASH_ENTRY		7

#define CMF_POP_CMP		0x01
#define CMF_DEFINED		0x02
#define CMF_I8_JMP_TABLE	0x04
#define CMF_U8_JMP_TABLE	0x08
#define CMF_I16_JMP_TABLE	0x10
#define CMF_U16_JMP_TABLE	0x20

#define CM_CONSTS_NUM		16

typedef struct CCodeMisc
{
struct CCodeMisc *next,*last,*fwd,*dft,*begin;
U8	*str;
U32	type,flags;
I64	use_cnt;
U8	*addr;
I64 st_len;
I64 num_consts;
I64 range;
I64 rip;
struct CCodeMisc **jmp_table;
F64	*float_consts;
struct CArrayDim *dim;
struct CHash *h;
} CCodeMisc;

#define IEF_OP_SIZE16		0x001
#define IEF_OP_SIZE32		0x002
#define IEF_PLUS_OPCODE		0x004
#define IEF_DONT_SWITCH_MODES	0x008
#define IEF_DFT			0x010
#define IEF_NOT_IN_64_BIT	0x020
#define IEF_48_REX		0x040
#define IEF_REX_ONLY_R8_R15	0x080
#define IEF_REX_XOR_LIKE	0x100
#define IEF_STI_LIKE		0x200
#define IEF_ENDING_ZERO		0x400


#define SV_R_REG	8
#define SV_I_REG	9
#define SV_STI_LIKE	10
#define SV_NONE		11
typedef struct CInst
{
U8	ins_entry_num,
opcode_cnt,
opcode[4];
U16	flags;
U8	slash_val,uasm_slash_val,opcode_modifier,
arg1,arg2,
size1,size2,
pad;
} CInst;


#define OC_OP_SIZE_PREFIX	0x66
#define OC_ADDR_SIZE_PREFIX	0x67
#define OC_LOCK_PREFIX		0xF0
#define OC_NOP			0x90
#define OC_BPT			0xCC
#define OC_CALL			0xE8
#define OC_JMP_REL8		0xEB
#define OC_NOP2			(OC_NOP<<8+OC_OP_SIZE_PREFIX)

#define PUSH_C_REGS PUSH RAX PUSH RCX PUSH RDX PUSH RBX PUSH R8 PUSH R9
#define POP_C_REGS POP R9 POP R8 POP RBX POP RDX POP RCX POP RAX

#define PUSH_REGS PUSH RAX PUSH RCX PUSH RDX PUSH RBX PUSH RBP PUSH RSI \
PUSH RDI PUSH R8 PUSH R9 PUSH R10 PUSH R11 PUSH R12 PUSH R13 PUSH R14 PUSH R15
#define POP_REGS POP R15 POP R14 POP R13 POP R12 POP R11 POP R10 POP R9 \
POP R8 POP RDI POP RSI POP RBP POP RBX POP RDX POP RCX POP RAX

#define REG_RAX		0
#define REG_RCX		1
#define REG_RDX		2
#define REG_RBX		3
#define REG_RSP		4
#define REG_RBP		5
#define REG_RSI		6
#define REG_RDI		7
#define REG_R8		8
#define REG_REGS_NUM	16

#define REG_RIP		16

#define REG_NONE	32
#define REG_ALLOC	33
#define REG_UNDEF	I8_MIN

#define REGG_CLOBBERED		0x013F
#define REGG_SAVED		0x0030
#define REGG_STK_TMP		0x0200
#define REGG_LOCAL_VARS		0xCCC0
#define REGG_LOCAL_NON_PTR_VARS	0x3000

#define AOT_BIN_BLK_BITS 16
#define AOT_BIN_BLK_SIZE (1<<AOT_BIN_BLK_BITS)

typedef struct CAOTBinBlk
{
struct CAOTBinBlk *next;
U8	body[AOT_BIN_BLK_SIZE];
} CAOTBinBlk;

typedef struct CAbsCntsI64
{
U16	abs_addres,
c_addres;
U32	externs;
} CAbsCntsI64;

typedef struct CAsmUndefHash
{
struct CAsmUndefHash	*next;
struct CHashExport	*hash;
} CAsmUndefHash;

typedef struct CAsmNum
{
I64	i;
U8	*machine_code;
struct CAsmUndefHash	*local_asm_undef_hash,*glbl_asm_undef_hash;
struct CAbsCntsI64 abs_cnts;
} CAsmNum;

typedef struct CAsmNum2
{
struct CAsmNum num;
I64	U8_cnt,rel;
Bool	imm_flag;
} CAsmNum2;

typedef struct CAsmIns
{
struct CInst *tmpins;
struct CAsmNum2 imm,disp;
I64	U8_cnt,last_opcode_U8,
REX,ModrM,SIB;
Bool	has_REX,has_ModrM,has_SIB,
has_addr_prefix,
has_operand_prefix,
is_dft,pad[2];
} CAsmIns;

typedef struct CAsmArg
{
struct CAsmNum num;
I64	seg,size,
reg1,reg2,
reg1_type,reg2_type,
scale;
Bool	indirect,imm_or_off_present,just_seg,pad[5];
} CAsmArg;

typedef struct CAsmUnresolvedRef
{
struct CAsmUnresolvedRef *next;
I64	type,line_num;
U8	*machine_code;
I64	rip,rel_rip;
struct CAOT	*aot;
U8	*str;
struct CAsmUndefHash *asm_undef_hash;
Bool	U8_avail,
imm_flag;
} CAsmUnresolvedRef;


#define OM_NO 0
#define OM_CB 1
#define OM_CW 2
#define OM_CD 3
#define OM_CP 4
#define OM_IB 5
#define OM_IW 6
#define OM_ID 7

#define ARGT_NONE	0
#define ARGT_REL8	1
#define ARGT_REL16	2
#define ARGT_REL32	3

#define ARGT_IMM8	4
#define ARGT_IMM16	5
#define ARGT_IMM32	6
#define ARGT_IMM64	7

#define ARGT_UIMM8	8
#define ARGT_UIMM16	9
#define ARGT_UIMM32	10
#define ARGT_UIMM64	11

#define ARGT_R8		12
#define ARGT_R16	13
#define ARGT_R32	14
#define ARGT_R64	15

#define ARGT_RM8	16
#define ARGT_RM16	17
#define ARGT_RM32	18
#define ARGT_RM64	19

#define ARGT_M8		20
#define ARGT_M16	21
#define ARGT_M32	22
#define ARGT_M64	23

#define ARGT_M1632	24
#define ARGT_M16N32	25
#define ARGT_M16N16	26
#define ARGT_M32N32	27

#define ARGT_MOFFS8	28
#define ARGT_MOFFS16	29
#define ARGT_MOFFS32	30
#define ARGT_MOFFS64	31

#define ARGT_AL		32
#define ARGT_AX		33
#define ARGT_EAX	34
#define ARGT_RAX	35

#define ARGT_CL		36
#define ARGT_DX		37
#define ARGT_SREG	39

#define ARGT_SS		40
#define ARGT_DS		41
#define ARGT_ES		42
#define ARGT_FS		43

#define ARGT_GS		44
#define ARGT_CS		45
#define ARGT_ST0	46
#define ARGT_STI	47

#define ARGT_MM		48
#define ARGT_MM32	49
#define ARGT_MM64	50
#define ARGT_XMM	51

#define ARGT_XMM32	52
#define ARGT_XMM64	53
#define ARGT_XMM128	54
#define ARGT_XMM0	55

#define OCF_ALIAS	1
typedef struct CHashOpcode
{
U16	inst_entry_cnt,
oc_flags,pad[2];
struct CInst ins[1];

struct CHash	*next;
U8	*str;
U32	type,
use_cnt;


} CHashOpcode;

#define IEF_GOTO_LABEL		1
typedef struct CAOTImportExport
{
struct CAOTImportExport *next,*last;
I64	rip,flags;
struct CAOT	*aot;
U8	*str,
*src_link,
type,pad[7];
} CAOTImportExport;

#define AAT_ADD_U8		0
#define AAT_SUB_U8		1
#define AAT_ADD_U16		2
#define AAT_SUB_U16		3
#define AAT_ADD_U32		4
#define AAT_SUB_U32		5
#define AAT_ADD_U64		6
#define AAT_SUB_U64		7
typedef struct CAOTAbsAddr
{
struct CAOTAbsAddr *next;
I64	rip;
U8	type,pad[7];
} CAOTAbsAddr;

typedef struct CAOTHeapGlblRef
{
struct CAOTHeapGlblRef *next;
I64	rip;
} CAOTHeapGlblRef;

typedef struct CAOTHeapGlbl
{
struct CAOTHeapGlbl *next;
U8	*str;
I64	size;
struct CAOTHeapGlblRef *references;
} CAOTHeapGlbl;

typedef struct CAOT
{
struct CAOT	*next,*last;
U8	*buf;
I64	rip,rip2,
aot_U8s,
max_align_bits,org;
struct CAOT	*parent_aot;
struct CAOTImportExport *next_ie,*last_ie;
struct CAOTAbsAddr *abss;
struct CAOTHeapGlbl *heap_glbls;
} CAOT;

typedef struct CStreamBlk
{
struct CStreamBlk *next,*last;
U8	*body;
} CStreamBlk;

typedef struct CCodeCtrl
{
struct CCodeCtrl *coc_next;
struct CCodeMisc *coc_next_misc,*coc_last_misc;
struct CIntermediateCodeBase	coc_head;
} CCodeCtrl;


#define LFSF_DOC	1
#define LFSF_DEFINE	2
typedef struct CLexFile
{
struct CLexFile *next;
U8	*buf,
*buf_ptr;
I64	line_num,flags;
U8	*full_name,
*line_start;
struct CDoc	*doc;
struct CDocEntry *cur_entry;
I32	depth;
U8	last_U16,pad[3];
} CLexFile;

typedef struct CAOTCtrl
{
I64	rip;
struct CAsmArg arg1,arg2;
struct CAOTBinBlk *bin;
I64	num_bin_U8s,
max_align_bits,org;
struct CAsmUnresolvedRef *local_unresolved,*glbl_unresolved;
struct CAOTAbsAddr *abss;
struct CAOTHeapGlbl *heap_glbls;
I64	lst_col,lst_last_rip;
U8	*last_label,*lst_last_line;
struct CLexFile *lst_last_lfn;
I64	seg_size;
Bool	lst;
} CAOTCtrl;


#define TK_EOF		0
#define TK_SUPERSCRIPT	0x001
#define TK_SUBSCRIPT	0x002
#define TK_NORMALSCRIPT	0x003
#define TK_IDENT	0x100
#define TK_STR		0x101
#define TK_I64		0x102
#define TK_CHAR_CONST	0x103
#define TK_F64		0x104
#define TK_PLUS_PLUS	0x105
#define TK_MINUS_MINUS	0x106
#define TK_DEREFERENCE	0x107
#define TK_DBL_COLON	0x108
#define TK_SHL		0x109
#define TK_SHR		0x10A
#define TK_EQU_EQU	0x10B
#define TK_NOT_EQU	0x10C
#define TK_LESS_EQU	0x10D
#define TK_GREATER_EQU	0x10E
#define TK_AND_AND	0x10F
#define TK_OR_OR	0x110
#define TK_XOR_XOR	0x111
#define TK_SHL_EQU	0x112
#define TK_SHR_EQU	0x113
#define TK_MUL_EQU	0x114
#define TK_DIV_EQU	0x115
#define TK_AND_EQU	0x116
#define TK_OR_EQU	0x117
#define TK_XOR_EQU	0x118
#define TK_ADD_EQU	0x119
#define TK_SUB_EQU	0x11A
#define TK_IF		0x11B
#define TK_IFDEF	0x11C
#define TK_IFNDEF	0x11D
#define TK_IFAOT	0x11E
#define TK_IFJIT	0x11F
#define TK_ENDIF	0x120
#define TK_ELSE		0x121
#define TK_MOD_EQU	0x122
#define TK_DOT_DOT	0x123
#define TK_ELLIPSIS	0x124
#define TK_INS_BIN	0x125
#define TK_INS_BIN_SIZE 0x126
#define TK_TKS_NUM	0x127

typedef struct CLexHashTableContext
{
struct CLexHashTableContext *next;
I64	old_flags,hash_mask;
struct CHashFun *local_var_lst,
*fun;
struct CHashTable *hash_table_lst,
*define_hash_table,
*local_hash_table,
*glbl_hash_table;
} CLexHashTableContext;


#define CCF_CMD_LINE		0x001
#define CCF_PMT			0x002
#define CCf_PMT			1
#define CCF_QUESTION_HELP	0x004
#define CCF_DONT_FREE_BUF	0x008
#define CCF_NO_DEFINES		0x010
#define CCF_IN_IF		0x020
#define CCF_JUST_LOAD		0x040
#define CCF_KEEP_NEW_LINES	0x080
#define CCF_KEEP_DOT		0x100
#define CCF_KEEP_SIGN_NUM	0x200
#define CCF_KEEP_AT_SIGN	0x400
#define CCF_NO_CHAR_CONST	0x800
#define CCf_PASS_TRACE_PRESENT	12
#define CCF_NOT_CONST		0x0000020000
#define CCF_NO_REG_OPT		0x0000040000
#define CCF_IN_QUOTES		0x0000080000
#define CCF_EXE_BLK		0x0000100000
#define CCF_HAS_MISC_DATA	0x0000200000
#define CCF_HAS_RETURN		0x0000400000
#define CCF_ASM_EXPRESSIONS	0x0000800000
#define CCF_UNRESOLVED		0x0001000000
#define CCF_LOCAL		0x0002000000
#define CCF_FUN_EXP		0x0004000000
#define CCf_FUN_EXP		26
#define CCF_POSTINC		0x0008000000
#define CCF_POSTDEC		0x0010000000
#define CCF_PREINC		0x0020000000
#define CCF_PREDEC		0x0040000000
#define CCF_ARRAY		0x0080000000
#define CCF_RAX			0x0100000000
#define CCF_USE_LAST_U16	0x0200000000
#define CCf_USE_LAST_U16	33
#define CCF_LAST_WAS_DOT	0x0400000000
#define CCF_AOT_COMPILE		0x0800000000
#define CCf_AOT_COMPILE		35
#define CCF_NO_ABSS		0x1000000000
#define CCF_PAREN		0x2000000000
#define CCf_PAREN		37
#define CCF_CLASS_DOL_OFFSET	0x4000000000
#define CCF_DONT_MAKE_RES	0x8000000000

typedef struct CCmpCtrl
{
struct CCmpCtrl *next,*last;
I64	token,
flags,
cur_i64;
F64	cur_f64;
U8	*cur_str;
I64	cur_str_len,
class_dol_offset;
U8	*dollar_buf;
I64	dollar_cnt;
U8	*cur_help_idx;
I64	last_U16,
min_line,max_line,last_line_num,
lock_cnt;
U32	*char_bmp_alpha_numeric;
struct CLexHashTableContext htc;
struct CHashGeneric *hash_entry;
struct CAbsCntsI64 abs_cnts;
struct CAsmUndefHash *asm_undef_hash;
struct CMemberLst *local_var_entry;
struct CCodeMisc *lb_leave;
U8	*cur_buf_ptr;
struct CLexFile *lex_include_stk,
*lex_prs_stk,
*fun_lex_file;
struct CStreamBlk *next_stream_blk,*last_stream_blk;
struct CAOT	*aot;

I64	pass,opts,pass_trace,saved_pass_trace,
error_cnt,warning_cnt;


I64	cur_ic_float_op_num,last_ic_float_op_num;
struct CIntermediateCode *last_float_op_ic;
Bool	last_dont_pushable,last_dont_popable,last_float_op_pos,
dont_push_float,pad[4];

struct CCodeCtrl coc;
struct CPrsStk *ps;
struct CAOTCtrl *aotc;
I64	aot_depth,pmt_line;
} CCmpCtrl;

typedef struct CCmpGlbls
{
struct CHashTable *asm_hash;
struct CHashClass *internal_types[RT_RTS_NUM];
struct CIntermediateCode ic_nop;
U32	*dual_U16_tokens1,*dual_U16_tokens2,*dual_U16_tokens3,
*binary_ops;
I64	num_reg_vars,num_non_ptr_vars,
stk_tmps_mask,reg_vars_mask,non_ptr_vars_mask;
U8	*to_reg_vars_map,*non_ptr_vars_map;
I64	size_arg_mask[9],
compiled_lines;
} CCmpGlbls;

typedef struct CUAsmGlbls
{
struct CInst **table_16_32,**table_64;
I64	table_16_32_entries,
table_64_entries,
ins64_arg_mask,
signed_arg_mask,
mem_arg_mask;
} CUAsmGlbls;

typedef struct CPCIDev
{
struct CPCIDev *next,*last;
U16	vendor,dev_id;
U8	bus,dev,fun,pad0,
sub_code,base_code,pad1[6],
*vendor_str,*dev_id_str;
} CPCIDev;

typedef struct CATARep
{
struct CATARep *next;
I64	num,type,base0,base1,unit,irq;
} CATARep;


#define ATA_NOP			0x00
#define ATA_DEV_RST		0x08
#define ATA_PACKET		0xA0
#define ATA_READ_NATIVE_MAX	0xF8
#define ATA_READ_NATIVE_MAX_EXT	0x27
#define ATA_SET_MAX		0xF9
#define ATA_SET_MAX_EXT		0x37
#define ATA_READ_MULTI		0xC4
#define ATA_READ_MULTI_EXT	0x29
#define ATA_WRITE_MULTI		0xC5
#define ATA_WRITE_MULTI_EXT	0x39
#define ATA_ID_DEV		0xEC

#define ATAS_ERR	0x01
#define ATAS_DRQ	0x08
#define ATAS_DF		0x20
#define ATAS_DRDY	0x40
#define ATAS_BSY	0x80

#define ATAR0_DATA	0
#define ATAR0_FEAT	1
#define ATAR0_NSECT	2
#define ATAR0_SECT	3
#define ATAR0_LCYL	4
#define ATAR0_HCYL	5
#define ATAR0_SEL	6
#define ATAR0_STAT	7
#define ATAR0_CMD	7
#define ATAR1_CTRL	2

#define FILEMASK_JIT	"*.HC*;*.HH*"
#define FILEMASK_AOT	"*.HC*;*.HH*;*.PRJ*"
#define FILEMASK_SRC	"*.HC*;*.HH*;*.IN*;*.PRJ*"
#define FILEMASK_DD	FILEMASK_SRC ";*.DD*"
#define FILEMASK_TXT	FILEMASK_DD ";*.TXT*"
#define FILEMASK_GR	"*.GR*"

#define BLK_SIZE_BITS	9
#define BLK_SIZE	(1<<BLK_SIZE_BITS)
#define DVD_BLK_SIZE	(4*BLK_SIZE)
#define DVD_BOOT_LOADER_SIZE	DVD_BLK_SIZE*1
#define INVALID_CLUS (-1)

typedef struct CMBRPrt
{
U8	active,
start_head;
U16	start_cyl;
U8	type,
end_head;
U16	end_cyl;
U32	offset,
size;
} CMBRPrt;

typedef struct CMasterBoot
{
U8	code[440];
U32	media_id;
U16	zero;
struct CMBRPrt p[4];
U16	signature;
} CMasterBoot;

typedef struct CRedSeaBoot
{
U8	jump_and_nop[3],
signature,reserved[4];
I64	drv_offset,
sects,
root_clus,
bitmap_sects,
unique_id;
U8	code[462];
U16	signature2;
} CRedSeaBoot;

typedef struct CFAT32Boot
{
U8	jump_and_nop[3],
oem_name[8];
U16	bytes_per_sect;
U8	sects_per_clus;
U16	reserved_sects;
U8	copies_of_fat;
U16	max_root_dir_entries,
old_sects_in_drv;
U8	media_desc;
U16	old_sects_per_fat,
sects_per_track,
num_heads;
U32	hidden_sects,
sects,
sects_per_fat;
U16	flags,
version;
U32	root_clus;
U16	file_system_info_sect,
backup_boot_sect;
U8	reserved[12],
log_drv_num,
unused,
ext_signature;
U32	serial_num;
U8	vol_name[11],
fat_name[8],
code[420];
U16	signature;
} CFAT32Boot;

typedef struct CFAT32FileInfoSect
{
U32	signature1;
U8	unknown[480];
U32	signature2,
free_clus,
most_recently_alloced;
U8	reserved[12];
U32	signature3;
} CFAT32FileInfoSect;

typedef struct CFAT32DirEntry
{
U8	name[11],
attr,
NTres,
CrtTimeTenth;
U16	CrtTime,
CrtDate,
LstAccDate,
clus_hi,
WrtTime,
WrtDate,
clus_lo;
U32	size;
} CFAT32DirEntry;

typedef struct CFAT32DirEntryLong
{
U8	ord;
U16	name1[5];
U8	attr,
type,
xsum;
U16	name2[6],
zero,
name3[2];
} CFAT32DirEntryLong;

#define FAT32_ENTRIES_PER_BLK	(BLK_SIZE/sizeof(CFAT32DirEntry))
#define FAT32_ENTRIES_BITS	Bsf(FAT32_ENTRIES_PER_BLK)

typedef struct CPalindromeU16
{
U16	little,big;
} CPalindromeU16;

typedef struct CPalindromeU32
{
U32	little,big;
} CPalindromeU32;

typedef struct CATAPITrack
{
U16	track_info_len;
U8	track_lo,
session_lo,
reserved;
U16	misc1;
U8	misc2;
U32	track_start,
next_writable,
free_blks;
U32 fixed_packet_size;
U32 blocking_factor;
U32 track_size;
U32 rzone_end;
U32	last_recorded;
U8	track_hi,
session_hi;
U16	reserved1;
U32	read_compatibility,
next_layer_jmp,
last_layer_jmp;
} CATAPITrack;


#define ISOT_BOOT_RECORD	0
#define ISOT_PRI_VOL_DESC	1
#define ISOT_SUPPLEMENTARY_DESC	2
#define ISOT_VOL_DRV_DESC	3
#define ISOT_TERMINATOR		255

typedef struct CISODirEntry
{
U8 pad[2];
struct CPalindromeU32 loc;
U8 pad1[24];
} CISODirEntry;

typedef struct CISOPriDesc
{
U8	type,
id[5],
version,
pad[73];
struct CPalindromeU32 vol_space_size;
U8	pad1[32];
struct CPalindromeU16 vol_set_size;
struct CPalindromeU16 vol_seq_num;
struct CPalindromeU16 log_block_size;
U8	pad2[20];
struct CISODirEntry root_dir_record;
U8	pad3[128],
publisher_id[128],
pad4[435],
file_structure_version,
pad5[1166];
} CISOPriDesc;



#define RS_ATTR_READ_ONLY	0x01
#define RS_ATTR_HIDDEN		0x02
#define RS_ATTR_SYSTEM		0x04
#define RS_ATTR_VOL_ID		0x08
#define RS_ATTR_DIR		0x10
#define RS_ATTR_ARCHIVE		0x20
#define RS_ATTR_LONG_NAME	(RS_ATTR_READ_ONLY|RS_ATTR_HIDDEN|\
RS_ATTR_SYSTEM|RS_ATTR_VOL_ID)
#define RS_ATTR_LONG_NAME_MASK	(RS_ATTR_LONG_NAME|RS_ATTR_DIR|RS_ATTR_ARCHIVE)
#define RS_ATTR_DELETED		0x100
#define RS_ATTR_RESIDENT	0x200
#define RS_ATTR_COMPRESSED	0x400
#define RS_ATTR_CONTIGUOUS	0x800
#define RS_ATTR_FIXED		0x1000


#define MT_CD		1
#define MT_DVD		2


#define CDIR_FILENAME_LEN	38
typedef struct CDirEntry
{
struct CDirEntry *next,*parent,*sub;
U8	*full_name;
I64	user_data,user_data2;

U0	start;
U16	attr;
U8	name[CDIR_FILENAME_LEN];
I64	clus,size;
struct CDate datetime;
} CDirEntry;
#define CDIR_SIZE (sizeof(CDirEntry)-offset(CDirEntry.start))



#define FUf_RECURSE		0
#define FUf_DIFF		1
#define FUf_DEL			1
#define FUf_IGNORE		2
#define FUf_ALL			3
#define FUf_CANCEL		4
#define FUf_REPLACE		5
#define FUf_RISKY		5
#define FUf_PUBLIC		6
#define FUf_MAP			7
#define FUf_EXPAND		8
#define FUf_SINGLE		9
#define FUf_JUST_DIRS		10
#define FUf_JUST_FILES		11
#define FUf_JUST_TXT		12
#define FUf_JUST_DD		13
#define FUf_JUST_SRC		14
#define FUf_JUST_AOT		15
#define FUf_JUST_JIT		16
#define FUf_JUST_GR		17
#define FUf_Z_OR_NOT_Z		18
#define FUf_CLUS_ORDER	19
#define FUf_SCAN_PARENTS	20
#define FUf_FLATTEN_TREE	21
#define FUf_WHOLE_LABELS	22
#define FUf_WHOLE_LABELS_BEFORE	23
#define FUf_WHOLE_LABELS_AFTER	24

#define FUF_RECURSE		0x0000001
#define FUF_DIFF		0x0000002
#define FUF_DEL			0x0000002
#define FUF_IGNORE		0x0000004
#define FUF_ALL			0x0000008
#define FUF_CANCEL		0x0000010
#define FUF_REPLACE		0x0000020
#define FUF_RISKY		0x0000020
#define FUF_PUBLIC		0x0000040
#define FUF_MAP			0x0000080
#define FUF_EXPAND		0x0000100
#define FUF_SINGLE		0x0000200
#define FUF_JUST_DIRS		0x0000400
#define FUF_JUST_FILES		0x0000800
#define FUF_JUST_TXT		0x0001000
#define FUF_JUST_DD		0x0002000
#define FUF_JUST_SRC		0x0004000
#define FUF_JUST_AOT		0x0008000
#define FUF_JUST_JIT		0x0010000
#define FUF_JUST_GR		0x0020000
#define FUF_Z_OR_NOT_Z		0x0040000
#define FUF_CLUS_ORDER	0x0080000
#define FUF_SCAN_PARENTS	0x0100000
#define FUF_FLATTEN_TREE	0x0200000
#define FUF_WHOLE_LABELS	0x0400000
#define FUF_WHOLE_LABELS_BEFORE	0x0800000
#define FUF_WHOLE_LABELS_AFTER	0x1000000

#define FUG_FILES_FIND	(FUF_RECURSE|FUF_SINGLE|FUF_CLUS_ORDER|\
FUF_JUST_DIRS|FUF_JUST_FILES|FUF_JUST_TXT|FUF_JUST_DD|\
FUF_JUST_SRC|FUF_JUST_AOT|FUF_JUST_JIT|FUF_JUST_GR|FUF_FLATTEN_TREE)
#define FUG_FILE_FIND	(FUF_JUST_DIRS|FUF_JUST_FILES|FUF_Z_OR_NOT_Z|\
FUF_SCAN_PARENTS)


#define BDT_NULL		0
#define BDT_RAM			1
#define BDT_ATA			2
#define BDT_ISO_FILE_READ	3
#define BDT_ISO_FILE_WRITE	4
#define BDT_ATAPI		5
#define BDT_TYPES_NUM		6

#define BDF_REMOVABLE		0x001
#define BDF_INITIALIZED		0x002
#define BDF_READ_ONLY		0x004
#define BDF_READ_ONLY_OVERRIDE	0x008
#define BDF_LAST_WAS_WRITE	0x010
#define BDF_READ_CACHE		0x020
#define BDF_FMT			0x040
#define BDF_INIT_IN_PROGRESS	0x080
#define BDF_EXT_SIZE		0x100

#define BDf_REMOVABLE		0
#define BDf_INITIALIZED		1
#define BDf_READ_ONLY		2
#define BDf_READ_ONLY_OVERRIDE	3
#define BDf_LAST_WAS_WRITE	4
#define BDf_READ_CACHE		5
#define BDf_FMT			6
#define BDf_INIT_IN_PROGRESS	7
#define BDf_EXT_SIZE		8


#define BDlf_LOCKED		0

#define BLKDEVS_NUM		26
#define BD_SIGNATURE_VAL	'BDSV'
typedef struct CBlkDev
{
struct CBlkDev *lock_fwding;
I64	locked_flags;
U32	bd_signature,
type,flags;
U8	first_drv_let,unit,pad[2];
U32	base0,base1,
blk_size;
I64	drv_offset,init_root_dir_blks,
max_blk;
U16	*dev_id_record;
U8	*RAM_dsk,
*file_dsk_name;
struct CFile *file_dsk;
struct CTask *owning_task;
F64	last_time;
U32	max_reads,max_writes;
} CBlkDev;


#define DVlf_LOCKED	0


#define FSt_NULL	0
#define FSt_REDSEA	1
#define FSt_FAT32	2
#define FSt_ISO9660	3
#define FSt_NTFS	4
#define FSt_UNKNOWN	5
#define FSt_TYPES_NUM	6
#define FSG_TYPE_MASK	0x7FFF

#define FStf_DISABLE	15

#define MBR_PT_FAT12	0x01
#define MBR_PT_FAT32a	0x0B
#define MBR_PT_FAT32b	0x0C
#define MBR_PT_FAT32c	0x1B
#define MBR_PT_FAT32d	0x1C
#define MBR_PT_FAT32e	0x8B
#define MBR_PT_FAT32f	0x8C
#define MBR_PT_NTFS	0x07
#define MBR_PT_REDSEA	0x88

typedef struct CFreeLst
{
struct CFreeLst *next,*last;
I64	start,size;
} CFreeLst;

#define DRVS_NUM		26

#define DRV_SIGNATURE_VAL	'DVSV'
typedef struct CDrv
{


I64	locked_flags;
U32	dv_signature;
U8	drv_let,pad;
U16	fs_type;
I64	drv_offset,
size,
prt_num,
file_system_info_sect,
fat1,fat2,
root_clus,
data_area,
spc;
struct CDate fat32_local_time_offset;
struct CTask *owning_task;
struct CBlkDev *bd;

struct CFAT32FileInfoSect *fis;
I64	fat_blk_dirty,
cur_fat_blk_num;
U32	*cur_fat_blk;
struct CFreeLst *next_free,*last_free;
} CDrv;

#define DSK_CACHE_HASH_SIZE	0x2000

typedef struct CCacheBlk
{
struct CCacheBlk *next_lru,*last_lru;
struct CCacheBlk *next_hash,*last_hash;
struct CDrv	*dv;
I64	blk;
U8	body[BLK_SIZE];
} CCacheBlk;

#define DFT_ISO_FILENAME	"::/Tmp/CDDVD.ISO"
#define DFT_ISO_C_FILENAME	"::/Tmp/CDDVD.ISO.C"

typedef struct CBlkDevGlbls
{
struct CBlkDev *blkdevs;
U8	*dft_iso_filename;
U8	*dft_iso_c_filename;
U8	*tmp_filename;
U8	*home_dir;
struct CCacheBlk *cache_base,*cache_ctrl,**cache_hash_table;
I64	cache_size,read_cnt,write_cnt;
struct CDrv	*drvs,*let_to_drv[32];
I64	mount_ide_auto_cnt,
ins_base0,ins_base1;
U8	boot_drv_let,first_hd_drv_let,first_dvd_drv_let;
Bool	dvd_boot_is_good,ins_unit,pad[3];
} CBlkDevGlbls;

typedef struct CDirContext
{
struct CDrv	*old_dv,*dv;
U8	*old_dir,*mask;
} CDirContext;

#define FFB_NEXT_BLK		I64_MAX

#define FF_WRITE		1
#define FF_NEW_FILE		2
#define FF_BUF_DIRTY		4
#define FF_NEEDS_WRITE		8
#define FF_CONTIGUOUS		16
#define FF_USE_OLD_DATETIME	32

typedef struct CFile
{
I64	flags;
struct CDirEntry de;
struct CDrv	*dv;
I64	fblk_num,clus,file_clus_num,max_blk;
U8	*clus_buf;
} CFile;

#define _CFG_HEAP_DBG FALSE

#if _CFG_HEAP_DBG
typedef struct CMemUnused
{
struct CHeapCtrl *hc;
U8	*caller1,*caller2;
struct CMemUnused *next;
I64	size;
} CMemUnused;
typedef struct CMemUsed
{
struct CHeapCtrl *hc;
U8	*caller1,*caller2;
struct CMemUsed *next,*last;
I64	size;
U0	start;
} CMemUsed;
#else
typedef struct CMemUnused
{
U0	hc;
U0	*caller1,*caller2;
struct CMemUnused *next;
I64	size;
} CMemUnused;
typedef struct CMemUsed
{
struct CHeapCtrl *hc;
U0	*caller1,*caller2;
U0	*next,*last;
I64	size;
U0	start;
} CMemUsed;
#endif


#define MBS_USED_SIGNATURE_VAL		'MBUs'
#define MBS_UNUSED_SIGNATURE_VAL	'MBUn'
typedef struct CMemBlk
{
struct CMemBlk *next,*last;
U32	mb_signature,pags;
} CMemBlk;

#define MRT_UNUSED	0
#define MRT_RAM		1
#define MRT_DEV		2

typedef struct CMemRange
{
struct CMemRange *next,*last;
U32	type,flags;
U8	*base;
I64	size;
} CMemRange;

#define MEM_PAG_BITS		9
#define MEM_PAG_SIZE		(1<<MEM_PAG_BITS)
#define MEM_HEAP_HASH_SIZE	1024
#define MEM_FREE_PAG_HASH_SIZE	0x100


#define MEM_EXTRA_HASH2_PAGS	2

#define MEM_ADAM_STK		(MEM_PAG_SIZE*512)
#define MEM_SETH_STK		(MEM_PAG_SIZE*512)
#define MEM_INTERRUPT_STK	(MEM_PAG_SIZE*512)
#define MEM_DFT_STK		(MEM_PAG_SIZE*512)

#define TASK_HASH_TABLE_SIZE	(1<<10)


#define BPlf_LOCKED		0
typedef struct CBlkPool
{
I64	locked_flags,alloced_u8s,used_u8s;
struct CMemBlk *mem_free_lst,
*mem_free_2meg_lst,
*free_pag_hash[MEM_FREE_PAG_HASH_SIZE],
*free_pag_hash2[64-MEM_PAG_BITS];
} CBlkPool;


#define HClf_LOCKED		0

#define HEAP_CTRL_SIGNATURE_VAL	'HcSV'
typedef struct CHeapCtrl
{
struct CBlkPool *bp;
U32	hc_signature,pad;
I64	locked_flags,alloced_u8s,used_u8s;
struct CTask *mem_task;
struct CMemBlk *next_mem_blk,*last_mem_blk;
struct CMemBlk *last_mergable;
struct CMemUnused *malloc_free_lst;
struct CMemUsed *next_um,*last_um;
struct CMemUnused *heap_hash[MEM_HEAP_HASH_SIZE/sizeof(U8 *)];
} CHeapCtrl;

typedef struct CDevGlbls
{
I64	*idt;
U8	*mem64_ptr;
U8	*uncached_alias;
U8	mp_apic_ids[MP_PROCESSORS_NUM];
struct CMemRange mem32_head;
struct CPCIDev pci_head;
} CDevGlbls;


#define ROPB_EQU			0x00
#define ROPB_XOR			0x01
#define ROPB_COLLISION			0x02
#define ROPB_MONO			0x03
#define ROPBF_HALF_RANGE_COLOR		0x10
#define ROPBF_TWO_SIDED			0x20
#define ROPBF_DITHER			0x40
#define ROPBF_PROBABILITY_DITHER	0x80

#define ROP_EQU				(ROPB_EQU<<8)
#define ROP_XOR				(ROPB_XOR<<8)
#define ROP_COLLISION			(ROPB_COLLISION<<8)
#define ROP_MONO			(ROPB_MONO<<8)



#define ROPF_HALF_RANGE_COLOR		0x1000
#define ROPF_TWO_SIDED			0x2000


#define ROPF_DITHER			0x40000000
#define ROPF_PROBABILITY_DITHER		0x80000000

#define TRANSPARENT		0xFF
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED			4
#define PURPLE			5
#define BROWN			6
#define LTGRAY			7
#define DKGRAY			8
#define LTBLUE			9
#define LTGREEN			10
#define LTCYAN			11
#define LTRED			12
#define LTPURPLE		13
#define YELLOW			14
#define WHITE			15

#define COLORS_NUM		16
#define COLOR_INVALID		16
#define COLOR_MONO		0xFF

typedef struct CColorROPU16
{
U8	color,rop;
} CColorROPU16;
typedef struct CColorROPU32
{
struct CColorROPU16 c0,c1;
} CColorROPU32;
#define COLORROP_COLORS_MASK	0x00FF00FF
#define COLORROP_NO_ROP0_MASK	0xFFFF00FF
#define COLORROP_BITS		16
typedef struct CBGR24
{
U8	b,g,r,pad;
} CBGR24;
typedef struct CBGR48
{
U16	b,g,r,pad;
} CBGR48;

#define KBD_PORT	0x60
#define KBD_CTRL	0x64
typedef struct CKbdStateGlbls
{
I64	scan_code,
last_down_scan_code,
cnt,
timestamp,
new_key_timestamp;
struct CFifoU8 *fifo,*fifo2;
struct CFifoI64 *scan_code_fifo;



U32	down_bitmap[8],

down_bitmap2[8];

Bool	rst,
irqs_working;
} CKbdStateGlbls;

typedef struct CMsHardStateGlbls
{
struct CD3I64 pos,
prescale;
struct CD3	scale;
F64	speed;
I64	timestamp,
install_attempts,
pkt_size;
struct CFifoU8 *fifo,*fifo2;
Bool	bttns[5],
has_wheel,
has_ext_bttns,
evt,
installed,
install_in_progress,
irqs_working;
} CMsHardStateGlbls;

typedef struct CMsStateGlbls
{
struct CD3I64 pos,
pos_text,
presnap,
offset;
struct CD3	scale;
F64	speed;
I64	timestamp;
F64	dbl_time,
left_dbl_time,
right_dbl_time;
Bool	lb,
rb,
show,
has_wheel,
left_dbl,
left_down_sent,
right_dbl,
right_down_sent;
} CMsStateGlbls;

typedef struct CGridGlbls
{
Bool	snap;//	format "$$CB,\"Snap Grid\"$$\n",
Bool show;//	format "$$CB,\"Show Grid\"$$\n",
Bool coord;//	format "$$CB,\"Show Coordinates\"$$\n";
U8	pad[5];
F64	x;//	format "$$DA-TRM,A=\"X Spacing:%6.3f\"$$\n",
F64 y;//	format "$$DA-TRM,A=\"Y Spacing:%6.3f\"$$\n",
F64 z;//	format "$$DA-TRM,A=\"Z Spacing:%6.3f\"$$\n",
F64 x_offset;// format "$$DA-TRM,A=\"X Offset :%6.3f\"$$\n",
F64 y_offset;// format "$$DA-TRM,A=\"Y Offset :%6.3f\"$$\n",
F64 z_offset;// format "$$DA-TRM,A=\"Z Offset :%6.3f\"$$\n",
F64 x_speed;//	format "$$DA-TRM,A=\"X Speed  :%6.3f\"$$\n",
F64 y_speed;//	format "$$DA-TRM,A=\"Y Speed  :%6.3f\"$$\n",
F64 z_speed;//	format "$$DA-TRM,A=\"Z Speed  :%6.3f\"$$\n";
} CGridGlbls;

#define CTRLT_GENERIC		0
#define CTRLT_WIN_HSCROLL	1
#define CTRLT_WIN_VSCROLL	2
#define CTRLT_VIEWING_ANGLES	3

#define CTRLF_SHOW		1
#define CTRLF_BORDER		2
#define CTRLF_CAPTURE_LEFT_MS	4
#define CTRLF_CAPTURE_RIGHT_MS	8
#define CTRLF_CLICKED		16

#define WSSf_SET_TO_POS		0

typedef struct CWinScroll
{
I64	min,pos,max;
U32	flags;
U8	color,pad[3];
} CWinScroll;

typedef struct CViewAngles
{
I64	sx,sy,sz;
F64	ax,ay,az;
struct CColorROPU32 cx,cy,cz,cbd,cbg,cfg;
} CViewAngles;

typedef struct CCtrl
{
struct CCtrl *next,*last;
struct CTask *win_task;
I64	type,flags;


I64	left,right,top,bottom;


I64	scrn_left,scrn_right,scrn_top,scrn_bottom;

U8	*state;


U0	(*update_derived_vals)(struct CCtrl *c);
U0	(*draw_it)(struct CDC *dc,struct CCtrl *c);

Bool	(*inside_ctrl)(struct CCtrl *c,I64 x,I64 y);
U0	(*left_click)(struct CCtrl *c,I64 x,I64 y,Bool down);
U0	(*right_click)(struct CCtrl *c,I64 x,I64 y,Bool down);
U0	(*wheel_chg)(struct CCtrl *c,I64 delta);
} CCtrl;

typedef struct CMenuEntry
{
struct CMenuEntry *next;
struct CMenuEntry *sub;
U8	name[32];
I64	msg_code,arg1,arg2;
Bool	checked,dir,pad[6];
} CMenuEntry;

typedef struct CMenu
{
struct CMenu *next;
struct CMenuEntry *sub;
struct CTask *task;
I64	flags;
U8	attr,pad[7];
} CMenu;

typedef struct CBpt
{
struct CBpt	*next;
U8	*addr,
val,pad[7];
} CBpt;

typedef struct CExcept
{
struct CExcept *next,*last;
I64	hndlr_catch,hndlr_untry,
rsp,rbp,rflags,rsi,rdi,r10,r11,r12,r13,r14,r15;
} CExcept;

typedef struct CFPU
{
U8	body[512];
} CFPU;

#define JOBf_WAKE_MASTER	0
#define JOBf_FOCUS_MASTER	1
#define JOBf_EXIT_ON_COMPLETE	2
#define JOBf_DONT_FILTER	3
#define JOBf_HIGHEST_PRIORITY	4

#define JOBf_DONE		5
#define JOBf_DISPATCHED		6
#define JOBf_FREE_ON_COMPLETE	7
#define JOBf_ADD_TO_QUE		8

#define JOBT_TEXT_INPUT		0
#define JOBT_MSG		1
#define JOBT_EXE_STR		2

#define JOBT_CALL		3
#define JOBT_SPAWN_TASK		4

typedef struct CJob
{
struct CJob *next,*last;
struct CJobCtrl *ctrl;
I64	job_code,flags,msg_code;

I64	(*addr)(U8 *fun_arg);
U8	*fun_arg;

U8	*aux_str;
I64	aux1,aux2,
res;

struct CTask	*spawned_task,
*master_task;
} CJob;

#define JOBCf_LOCKED		0
typedef struct CJobCtrl
{
struct CJob *next_waiting,*last_waiting;
struct CJob *next_done,*last_done;
I64	flags;
} CJobCtrl;


#define MSG_NULL		0
#define MSG_CMD			1
#define MSG_KEY_DOWN		2
#define MSG_KEY_UP		3
#define MSG_MS_MOVE		4
#define MSG_MS_L_DOWN		5
#define MSG_MS_L_UP		6
#define MSG_MS_L_D_DOWN 	7
#define MSG_MS_L_D_UP		8
#define MSG_MS_R_DOWN		9
#define MSG_MS_R_UP		10
#define MSG_MS_R_D_DOWN 	11
#define MSG_MS_R_D_UP		12


#define MSG_KEY_DOWN_UP		-2
#define MSG_MS_L_DOWN_UP	-5
#define MSG_MS_L_D_DOWN_UP	-7
#define MSG_MS_R_DOWN_UP	-9
#define MSG_MS_R_D_DOWN_UP	-11

#define TSF_SAME_SONG	1
typedef struct CTaskSettings
{
struct CTaskSettings *next;
U8	*cur_dir;
I64	left,right,top,bottom;
U0	(*draw_it)(struct CTask *task,struct CDC *dc);
U0	(*task_end_cb)();
struct CTask *song_task,*animate_task;
I64	scroll_x,scroll_y,scroll_z;
struct CBGR48 palette[COLORS_NUM];
U32	win_inhibit;
U8	text_attr,title_src,
border_attr,border_src,
task_title[STR_LEN];
Bool	border,hide_cursor,highlight_cursor,scroll,autocomplete,pad[3];
} CTaskSettings;


#define BDS_CONST		0
#define BDS_CUR_DRV		1
#define BDS_ED_FILENAME_DRV	2


#define TTS_CONST		0
#define TTS_LOCKED_CONST	1
#define TTS_TASK_NAME		2
#define TTS_ED_FILENAME		3
#define TTS_CUR_LEX		4


#define TASKf_TASK_LOCK		0
#define TASKf_KILL_TASK		1
#define TASKf_SUSPENDED		2
#define TASKf_IDLE		3
#define TASKf_CMD_LINE_PMT	4
#define TASKf_INPUT_FILTER_TASK	5
#define TASKf_FILTER_INPUT	6
#define TASKf_HAS_SONG		7
#define TASKf_DISABLE_BPTS	8
#define TASKf_AWAITING_MSG	9
#define TASKf_BREAK_LOCKED	10
#define TASKf_PENDING_BREAK	11
#define TASKf_BREAK_TO_SHIFT_ESC 12
#define TASKf_KILL_AFTER_DBG	13

#define TASKf_NONTIMER_RAND	14


#define DISPLAYf_SHOW			0
#define DISPLAYf_NOT_RAW		1
#define DISPLAYf_SILENT			2
#define DISPLAYf_NO_BORDER		3
#define DISPLAYf_WIN_ON_TOP		4
#define DISPLAYf_CHILDREN_NOT_ON_TOP	5

#define TASK_SIGNATURE_VAL		'TskS'
#define TASK_NAME_LEN			32
#define TASK_EXCEPT_CALLERS		8
typedef struct CTaskStk
{
struct CTaskStk *next_stk;
I64	stk_size,stk_ptr;
U0	stk_base;
} CTaskStk;

#define DYING_JIFFIES	ToI64(JIFFY_FREQ/5)
typedef struct CTaskDying
{
struct CTask *next,*last;
I64	wake_jiffy;
} CTaskDying;

typedef struct CTask
{
struct CTask *addr;
U32	task_signature,win_inhibit;
I64	wake_jiffy;
U32	task_flags,display_flags;

struct CHeapCtrl *code_heap,*data_heap;

struct CDoc	*put_doc,*display_doc,
*border_doc;
I64	win_left,win_right,win_top,win_bottom;

struct CDrv	*cur_dv;
U8	*cur_dir;

struct CTask *parent_task,
*next_task,*last_task,
*next_input_filter_task,*last_input_filter_task,
*next_sibling_task,*last_sibling_task,
*next_child_task,*last_child_task;


I64	win_width,win_height,
pix_left,pix_right,pix_width,
pix_top,pix_bottom,pix_height,
scroll_x,scroll_y,scroll_z;



I64	rip,rflags,rsp,rsi,rax,rcx,rdx,rbx,rbp,rdi,
r8,r9,r10,r11,r12,r13,r14,r15;
struct CCPU	*gs;
struct CFPU	*fpu_mmx;
I64	swap_cnter;

U0	(*draw_it)(struct CTask *task,struct CDC *dc);

U8	task_title[STR_LEN],
task_name[TASK_NAME_LEN],
wallpaper_data[STR_LEN],

title_src,border_src,
text_attr,border_attr;
U16	win_z_num,pad;

struct CTaskStk *stk;

struct CExcept *next_except,*last_except;
I64	except_rbp,
except_ch;
U8	*except_callers[TASK_EXCEPT_CALLERS];

Bool	catch_except;
Bool	new_answer;
U8	answer_type,pad1[5];
I64	answer;
F64	answer_time;
struct CBpt	*bpt_lst;
struct CCtrl	*next_ctrl,*last_ctrl;
struct CMenu	*cur_menu;
struct CTaskSettings *next_settings;
struct CMathODE *next_ode,*last_ode;
F64	last_ode_time;
struct CHashTable *hash_table;

struct CJobCtrl srv_ctrl;
struct CCmpCtrl *next_cc,*last_cc;
struct CHashFun *last_fun;

U0	(*task_end_cb)();
struct CTask *song_task,*animate_task;
I64	rand_seed,
task_num,
fault_num,fault_err_code;
struct CTask *popup_task,
*dbg_task;
struct CWinScroll horz_scroll,vert_scroll;

I64	user_data;
} CTask;

typedef struct CTSS
{
U32	res1;
I64	rsp0,rsp1,rsp2,res2,
ist1,ist2,ist3,ist4,ist5,ist6,ist7,res3;
U16	res4,io_map_offset;
U8	io_map[0x10000/8];
I64	*st0,*st1,*st2;
U16	tr,tr_ring3;
} CTSS;

#define ans	(Fs->answer)
#define ansf	(Fs->answer(F64))

#define _RAX Fs->rax
#define _RBX Fs->rbx
#define _RCX Fs->rcx
#define _RDX Fs->rdx
#define _RSI Fs->rsi
#define _RDI Fs->rdi
#define _RBP Fs->rbp
#define _RSP Fs->rsp
#define _RIP Fs->rip
#define _R8  Fs->r8
#define _R9  Fs->r9
#define _R10 Fs->r10
#define _R11 Fs->r11
#define _R12 Fs->r12
#define _R13 Fs->r13
#define _R14 Fs->r14
#define _R15 Fs->r15

#define CPUf_RAN_A_TASK		0
#define CPUf_DYING_TASK_QUE	1

typedef struct CCPU
{
struct CCPU	*addr;
I64	num,cpu_flags,
startup_rip,
idle_pt_hits;
F64	idle_factor;
I64	total_jiffies;
struct CTask *seth_task,*idle_task;
I64	tr,
swap_cnter;
U0	(*profiler_timer_irq)(struct CTask *task);
struct CTaskDying *next_dying,*last_dying;
I64	kill_jiffy;
struct CTSS	*tss;
I64	start_stk[16];
} CCPU;

#define MEM_MIN_MEG		512

#define SYS_FIXED_AREA		0x100000
#define SYS_16MEG_AREA_LIMIT	0x1000000
typedef struct CSysFixedArea
{
struct CFPU	init_fpu_mmx;
struct CCPU	boot_cpu;
struct CTask	adam;
struct CBlkPool sys_code_bp;
struct CHeapCtrl adam_hc;
//$$=($$+0x1000-1)&-0x1000;
} CSysFixedArea;

#define CH_CTRLA	0x01
#define CH_CTRLB	0x02
#define CH_CTRLC	0x03
#define CH_CTRLD	0x04
#define CH_CTRLE	0x05
#define CH_CTRLF	0x06
#define CH_CTRLG	0x07
#define CH_CTRLH	0x08
#define CH_CTRLI	0x09
#define CH_CTRLJ	0x0A
#define CH_CTRLK	0x0B
#define CH_CTRLL	0x0C
#define CH_CTRLM	0x0D
#define CH_CTRLN	0x0E
#define CH_CTRLO	0x0F
#define CH_CTRLP	0x10
#define CH_CTRLQ	0x11
#define CH_CTRLR	0x12
#define CH_CTRLS	0x13
#define CH_CTRLT	0x14
#define CH_CTRLU	0x15
#define CH_CTRLV	0x16
#define CH_CTRLW	0x17
#define CH_CTRLX	0x18
#define CH_CTRLY	0x19
#define CH_CTRLZ	0x1A
#define CH_CURSOR	0x05
#define CH_BACKSPACE	0x08
#define CH_ESC		0x1B
#define CH_SHIFT_ESC	0x1C
#define CH_SHIFT_SPACE	0x1F
#define CH_SPACE	0x20

#define ST_ERR_ST   "$$LTRED$$$$BK,1$$ERROR:$$FG$$$$BK,0$$ "
#define ST_WARN_ST  "$$RED$$$$BK,1$$WARNING:$$FG$$$$BK,0$$ "


#define SCf_E0_PREFIX	7
#define SCf_KEY_UP	8
#define SCf_SHIFT	9
#define SCf_CTRL	10
#define SCf_ALT 	11
#define SCf_CAPS	12
#define SCf_NUM 	13
#define SCf_SCROLL	14
#define SCf_NEW_KEY	15
#define SCf_MS_L_DOWN	16
#define SCf_MS_R_DOWN	17
#define SCf_DELETE	18
#define SCf_INS		19
#define SCf_NO_SHIFT	30
#define SCf_KEY_DESC	31
#define SCF_E0_PREFIX	(1<<SCf_E0_PREFIX)
#define SCF_KEY_UP	(1<<SCf_KEY_UP)
#define SCF_SHIFT	(1<<SCf_SHIFT)
#define SCF_CTRL	(1<<SCf_CTRL)
#define SCF_ALT		(1<<SCf_ALT)
#define SCF_CAPS	(1<<SCf_CAPS)
#define SCF_NUM		(1<<SCf_NUM)
#define SCF_SCROLL	(1<<SCf_SCROLL)
#define SCF_NEW_KEY	(1<<SCf_NEW_KEY)
#define SCF_MS_L_DOWN	(1<<SCf_MS_L_DOWN)
#define SCF_MS_R_DOWN	(1<<SCf_MS_R_DOWN)
#define SCF_DELETE	(1<<SCf_DELETE)
#define SCF_INS 	(1<<SCf_INS)
#define SCF_NO_SHIFT	(1<<SCf_NO_SHIFT)
#define SCF_KEY_DESC	(1<<SCf_KEY_DESC)




#define SC_ESC		0x01
#define SC_BACKSPACE	0x0E
#define SC_TAB		0x0F
#define SC_ENTER	0x1C
#define SC_SHIFT	0x2A
#define SC_CTRL		0x1D
#define SC_ALT		0x38
#define SC_CAPS		0x3A
#define SC_NUM		0x45
#define SC_SCROLL	0x46
#define SC_CURSOR_UP	0x48
#define SC_CURSOR_DOWN	0x50
#define SC_CURSOR_LEFT	0x4B
#define SC_CURSOR_RIGHT 0x4D
#define SC_PAGE_UP	0x49
#define SC_PAGE_DOWN	0x51
#define SC_HOME		0x47
#define SC_END		0x4F
#define SC_INS		0x52
#define SC_DELETE	0x53
#define SC_F1		0x3B
#define SC_F2		0x3C
#define SC_F3		0x3D
#define SC_F4		0x3E
#define SC_F5		0x3F
#define SC_F6		0x40
#define SC_F7		0x41
#define SC_F8		0x42
#define SC_F9		0x43
#define SC_F10		0x44
#define SC_F11		0x57
#define SC_F12		0x58
#define SC_PAUSE	0x61
#define SC_GUI		0xDB
#define SC_PRTSCRN1	0xAA
#define SC_PRTSCRN2	0xB7


#define RWF_IN_DOLLAR	1
#define RWF_LAST_DOLLAR	2
#define RWF_SHOW_DOLLAR	4
#define RWF_SCROLL	8

typedef struct CTextGlbls
{
I64	raw_col,raw_flags;
U8	*raw_scrn_image;
I64	rows,cols;
U64	*font,*aux_font;
U8	*vga_alias,*vga_text_alias;
U8	border_chars[16];
} CTextGlbls;

#define FONT_WIDTH	8
#define FONT_HEIGHT	8

#define GR_WIDTH	640
#define GR_HEIGHT	480




#define GR_Z_ALL	(I32_MAX/2)


#define DCF_COMPRESSED		1
#define DCF_PALETTE		2
#define DCF_NO_TRANSPARENTS	4

#define DCF_TRANSFORMATION	0x100


#define DCF_SYMMETRY		0x200



#define DCF_JUST_MIRROR		0x400

#define DCF_LOCATE_NEAREST	0x800
#define DCF_DONT_DRAW		0x1000
#define DCF_ALIAS		0x2000
#define DCF_SCRN_BITMAP		0x4000
#define DCF_FILL_NOT_COLOR	0x8000
#define DCF_RECORD_EXTENTS	0x10000
#define DCF_ON_TOP		0x20000


#define DCSF_COMPRESSED		1
#define DCSF_PALETTE_GET	2

#define DCS_SIGNATURE_VAL	'DvCS'

typedef struct CGrSym
{
I32	sx,sy,sz,pad;

I64	snx,sny,snz;
} CGrSym;

typedef struct CDC
{
U0	start;
struct CDate cdt;
I32	x0,y0,
width,width_internal,
height,
flags;
U0	end;
struct CBGR48 palette[COLORS_NUM];


struct CColorROPU32 color,
bkcolor,
color2;
struct CD3I32 ls;







U64 dither_probability_u16;

struct CDC *brush;


I64	*r,
r_norm;


I32	x,y,z,
thick;


U0	(*transform)(struct CDC *dc,I64 *x,I64 *y,I64 *z);


U0	(*lighting)(struct CDC *dc,struct CD3I32 *p1,struct CD3I32 *p2,
struct CD3I32 *p3,CColorROPU32 color);


struct CGrSym sym;

I32	cur_x,cur_y,cur_z,pad;
I64	collision_cnt;

I64	nearest_dist,
min_x,max_x,min_y,max_y;

U32	dc_signature,pad1;
struct CTask	*mem_task,*win_task;
struct CDC	*alias;
U8	*body;


I32	*depth_buf;
I64	db_z;
} CDC;


#define VGAM_GRAPHICS	0xA0000
#define VGAM_TEXT	0xB8000


#define VGAP_ATTR_INDEX		0x03C0
#define VGAP_ATTR_DATA_WRITE	0x03C0
#define VGAP_ATTR_DATA_READ	0x03C1
#define VGAP_MISC_OUTPUT	0x03C2
#define VGAP_IDX		0x03C4
#define VGAP_DATA		0x03C5
#define VGAP_PALETTE_MASK	0x03C6
#define VGAP_REG_READ		0x03C7
#define VGAP_REG_WRITE		0x03C8
#define VGAP_PALETTE_DATA	0x03C9
#define VGAP_CRTC_INDEX		0x03D4
#define VGAP_CRTC_DATA		0x03D5
#define VGAP_INPUT_STAT		0x03DA


#define VGAR_MAP_MASK		0x02

#define ARC_BITS_MAX	12
#define ARC_MAX_BITS	12

#define CT_NONE 	1
#define CT_7_BIT	2
#define CT_8_BIT	3
typedef struct CArcEntry
{
struct CArcEntry *next;
U16	basecode;
U8	ch,pad;
U32	pad1;
} CArcEntry;

typedef struct CArcCtrl
{
I64	src_pos,src_size,
dst_pos,dst_size;
U8	*src_buf,*dst_buf;
I64	min_bits,min_table_entry;
struct CArcEntry *cur_entry,*next_entry;
I64	cur_bits_in_use,next_bits_in_use;
U8	*stk_ptr,*stk_base;
I64	free_idx,free_limit,
saved_basecode,
entry_used,
last_ch;
struct CArcEntry compress[1<<ARC_BITS_MAX],
*hash[1<<ARC_BITS_MAX];
} CArcCtrl;

typedef struct CArcCompress
{
I64	compressed_size,expanded_size;
U8	compression_type;
U0	body;
} CArcCompress;

//#define "Char/Input;StdIn"

#define GSF_SHIFT_ESC_EXIT	1
#define GSF_WITH_NEW_LINE	2

//#define "Char/Operations"

#define SUF_REM_CTRL_CHARS	0x001
#define SUF_REM_LEADING		0x002
#define SUF_REM_TRAILING	0x004
#define SUF_REM_SPACES		0x008
#define SUF_SINGLE_SPACE	0x010
#define SUF_TO_UPPER		0x020
#define SUF_TO_LOWER		0x040
#define SUF_S2T			0x080
#define SUF_T2S			0x100
#define SUF_SCALE_INDENT	0x200
#define SUF_SAFE_DOLLAR		0x400


#define SFF_IGNORE_CASE		1
#define SFF_WHOLE_LABELS_BEFORE	2
#define SFF_WHOLE_LABELS_AFTER	4
#define SFG_WHOLE_LABELS	(SFF_WHOLE_LABELS_BEFORE|SFF_WHOLE_LABELS_AFTER)


#define LMF_IGNORE_CASE		1
#define LMF_EXACT		2

#define KDF_HAS_DESCS	1
typedef struct CKeyDevEntry
{
struct CKeyDevEntry *next,*last;
I64	priority,flags;
Bool	(*put_key)(I64 ch,I64 sc);
Bool	(*put_s)(U8 *st);
} CKeyDevEntry;

typedef struct CKeyDevGlbls
{
struct CKeyDevEntry put_key_head;
U0	(**fp_ctrl_alt_cbs)(I64 sc);
I64	ctrl_alt_in_irq_flags,
**ctrl_alt_ret_addr;
U8	**ctrl_alt_no_shift_descs,**ctrl_alt_shift_descs,
desc[STR_LEN],
*hndlr;
} CKeyDevGlbls;

typedef struct CAUData
{
struct CDate	cdt;
I8	ona;
} CAUData;

typedef struct CSndData
{
struct CSndData *next,*last;
F64	tS;
I8	ona;
} CSndData;

typedef struct CScrnCastGlbls
{
struct CSndData snd_head;
struct CDate	t0_now;
F64	t0_tS;
U8	*print_fmt;
struct CDC	*dc,*dc2_alias;
Bool	record,just_audio;
I8	ona;
} CScrnCastGlbls;

#define FUN_SEG_CACHE_SIZE	256
typedef struct CFunSegCache
{
I64	base,limit;
F64	time_stamp;
U8	str[1];
//$$=64;
} CFunSegCache;
#define FUN_SEG_CACHE_STR_LEN	(sizeof(CFunSegCache)-offset(CFunSegCache.str))

typedef struct CMPCrash
{
I64	cpu_num;
struct CTask *task;
I64	rip;
U8	*msg;
I64	msg_num;
} CMPCrash;

typedef struct CDbgGlbls
{
struct CTask *focus_task;
U8	*msg;
I64	msg_num;
struct CMPCrash *mp_crash;
U8	*int_fault_code,
*fix_file_line;
struct CFunSegCache *fun_seg_cache;
I64	fun_seg_cache_index;
Bool	panic;
} CDbgGlbls;


#define BOOT_RAM_BASE		0x07C00
#define BOOT_RAM_LIMIT		0x97000
#define BOOT_STK_SIZE		BLK_SIZE

#define BOOT_SRC_NULL		0
#define BOOT_SRC_ROM		1
#define BOOT_SRC_RAM		2
#define BOOT_SRC_HARDDRV	3
#define BOOT_SRC_DVD		4


#define STD_DISTRO_DVD_CFG	"TB\nScale2Mem(2048,0x40000)\nT \n\n\n\n"


#define ARf_FLOODFILL			0
#define ARf_CSPRITE_INS_CLIP		1
#define ARf_PLANAR_SYMMETRY		2
#define ARf_PSALMODY_JUKEBOX		3
#define ARf_MESH_ED			4
#define ARf_CSPRITE_PTS_RECTANGLES	5
#define ARf_MANAGE_SLIDER		6

#define PROGRESS_BARS_NUM	4
#define PROGRESS_DESC_LEN	(64-8-8)
typedef struct CProgress
{
I64	val,max;
F64	t0,tf;
U8	desc[PROGRESS_DESC_LEN];
} CProgress;

#define PRTF_PAD_ZERO		0x001
#define PRTF_LEFT_JUSTIFY	0x002
#define PRTF_TRUNCATE		0x004
#define PRTF_COMMA		0x008
#define PRTF_DOLLAR		0x010
#define PRTF_SLASH		0x020
#define PRTF_QUESTION		0x040
#define PRTF_AUX_FMT_NUM	0x080
#define PRTF_DECIMAL		0x100
#define PRTF_NEG		0x200
#define PRTF_NEG_E		0x400
#define PRTF_NEG_AUX_FMT_NUM	0x800


#define OS_OTHER	0
#define OS_NATIVE	1
#define OS_LINUX	2
#define OS_WINDOWS	3

#define VM_OTHER	0
#define VM_NATIVE	1
#define VM_VMWARE	2
#define VM_QEMU		3
#define VM_VIRTUALBOX	4

typedef struct CInsReg
{
Bool	registered;
I64	host_os; //		format "$$PURPLE$$Install Registration$$FG$$\n\n"
//"Host OS:$$LS,D=\"ST_HOST_OSES\"$$\n";
I64	host_vm; //		format "Host VM:$$LS,D=\"ST_HOST_VMS\"$$\n";
U8	initials[8];//	format "$$DA-P,A=\"Your Initials:%s\"$$\n";
I64	machine_num;//	format
//"$$DA-TRM,A=\"This Machine Num (Choose Any):%d\"$$\n";
} CInsReg;

typedef struct CMathODE
{
struct CMathODE *next,*last;
I64	flags,n,n_internal;
struct CMass	*next_mass,*last_mass;
struct CSpring *next_spring,*last_spring;
F64	drag_v,
drag_v2,
drag_v3,
acceleration_limit,
base_t,
t,t_scale,
h,h_min,h_max;





F64	min_tolerance,max_tolerance;

F64	tolerance_internal,
*array_base,
*state,
*state_internal,
*DstateDt,
*state_scale,
*initial_state,
*tmp0,*tmp1,*tmp2,*tmp3,
*tmp4,*tmp5,*tmp6,*tmp7;
struct CTask	*mem_task,*win_task;
U0	(*derive)(struct CMathODE *o,F64 t,F64 *state,F64 *DstateDt);
U0	(*mp_derive)(struct CMathODE *o,F64 t,
I64 cpu_num,F64 *state,F64 *DstateDt);
struct CTask **slave_tasks;
I64	mp_not_done_flags;
F64	mp_t,*mp_state,*mp_DstateDt;

I64	user_data;
} CMathODE;

#endif
