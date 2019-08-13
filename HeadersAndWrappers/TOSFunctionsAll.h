#ifndef TOS_FUCTIONS_ALL_H
#define TOS_FUCTIONS_ALL_H

#include "HolyCTypeWrappers.h"

#define IS_0_ARG	0
#define IS_1_ARG	1
#define IS_2_ARG	2
#define IS_V_ARG	3

#define IST_NULL	0
#define IST_DEREF	1
#define IST_ASSIGN	2
#define IST_CMP		3

typedef struct CIntermediateStruct
{
U8 arg_cnt,res_cnt,type;
Bool fpop,not_const,pad[3];
U8 *name;
} CIntermediateStruct;

#define IC_END			0x00
#define IC_NOP1			0x01
#define IC_END_EXP		0x02
#define IC_NOP2			0x03
#define IC_LABEL		0x04
#define IC_CALL_START		0x05
#define IC_CALL_END		0x06
#define IC_CALL_END2		0x07
#define IC_RETURN_VAL		0x08
#define IC_RETURN_VAL2		0x09
#define IC_IMM_I64		0x0A
#define IC_IMM_F64		0x0B
#define IC_STR_CONST		0x0C
#define IC_ABS_ADDR		0x0D
#define IC_ADDR_IMPORT		0x0E
#define IC_HEAP_GLBL		0x0F
#define IC_SIZEOF		0x10
#define IC_TYPE			0x11
#define IC_GET_LABEL		0x12
#define IC_RBP			0x13
#define IC_REG			0x14
#define IC_FS			0x15
#define IC_MOV_FS		0x16
#define IC_GS			0x17
#define IC_MOV_GS		0x18

#define IC_LEA			0x19
#define IC_MOV			0x1A

#define IC_TO_I64		0x1B
#define IC_TO_F64		0x1C
#define IC_TO_BOOL		0x1D
#define IC_TOUPPER		0x1E
#define IC_HOLYC_TYPECAST	0x1F

#define IC_ADDR			0x20
#define IC_COM			0x21
#define IC_NOT			0x22
#define IC_UNARY_MINUS		0x23

#define IC_DEREF		0x24
#define IC_DEREF_PP		0x25
#define IC_DEREF_MM		0x26
#define IC__PP			0x27
#define IC__MM			0x28
#define IC_PP_			0x29
#define IC_MM_			0x2A

#define IC_SHL			0x2B
#define IC_SHR			0x2C
#define IC_SHL_CONST		0x2D
#define IC_SHR_CONST		0x2E
#define IC_POWER		0x2F

#define IC_MUL			0x30
#define IC_DIV			0x31
#define IC_MOD			0x32

#define IC_AND			0x33

#define IC_OR			0x34
#define IC_XOR			0x35

#define IC_ADD			0x36
#define IC_SUB			0x37
#define IC_ADD_CONST		0x38
#define IC_SUB_CONST		0x39

#define IC_EQU_EQU		0x3A
#define IC_NOT_EQU		0x3B
#define IC_LESS			0x3C
#define IC_GREATER_EQU		0x3D
#define IC_GREATER		0x3E
#define IC_LESS_EQU		0x3F
#define IC_PUSH_CMP		0x40

#define IC_AND_AND		0x41

#define IC_OR_OR		0x42
#define IC_XOR_XOR		0x43

#define IC_ASSIGN		0x44
#define IC_ASSIGN_PP		0x45
#define IC_ASSIGN_MM		0x46

#define IC_SHL_EQU		0x47
#define IC_SHR_EQU		0x48
#define IC_MUL_EQU		0x49
#define IC_DIV_EQU		0x4A
#define IC_MOD_EQU		0x4B
#define IC_AND_EQU		0x4C
#define IC_OR_EQU		0x4D
#define IC_XOR_EQU		0x4E
#define IC_ADD_EQU		0x4F
#define IC_SUB_EQU		0x50

#define IC_JMP			0x51
#define IC_SUB_CALL		0x52
#define IC_SWITCH		0x53
#define IC_NOBOUND_SWITCH		0x54

#define IC_ADD_RSP		0x55
#define IC_ADD_RSP1		0x56
#define IC_ENTER		0x57
#define IC_PUSH_REGS		0x58
#define IC_POP_REGS		0x59
#define IC_LEAVE		0x5A
#define IC_RET			0x5B

#define IC_CALL			0x5C
#define IC_CALL_INDIRECT	0x5D
#define IC_CALL_INDIRECT2	0x5E
#define IC_CALL_IMPORT		0x5F
#define IC_CALL_EXTERN		0x60

#define IC_ASM			0x61
#define IC_PUSH			0x62
#define IC_POP			0x63

#define IC_CLFLUSH		0x64
#define IC_INVLPG		0x65

#define IC_IN_U8		0x66
#define IC_IN_U16		0x67
#define IC_IN_U32		0x68
#define IC_OUT_U8		0x69
#define IC_OUT_U16		0x6A
#define IC_OUT_U32		0x6B

#define IC_GET_RFLAGS		0x6C
#define IC_CARRY		0x6D
#define IC_SET_RFLAGS		0x6E
#define IC_GET_RAX		0x6F
#define IC_SET_RAX		0x70
#define IC_GET_RBP		0x71
#define IC_SET_RBP		0x72
#define IC_GET_RSP		0x73
#define IC_SET_RSP		0x74
#define IC_RIP			0x75

#define IC_RDTSC		0x76

#define IC_BT			0x77
#define IC_BTS			0x78
#define IC_BTR			0x79
#define IC_BTC			0x7A
#define IC_LBTS			0x7B
#define IC_LBTR			0x7C
#define IC_LBTC			0x7D
#define IC_BSF			0x7E
#define IC_BSR			0x7F

#define IC_QUE_INIT		0x80
#define IC_QUE_INS		0x81
#define IC_QUE_INS_REV		0x82
#define IC_QUE_REM		0x83

#define IC_STRLEN		0x84

#define IC_BR_ZERO		0x85
#define IC_BR_NOT_ZERO		0x86
#define IC_BR_CARRY		0x87
#define IC_BR_NOT_CARRY		0x88

#define IC_BR_EQU_EQU		0x89
#define IC_BR_NOT_EQU		0x8A
#define IC_BR_LESS		0x8B
#define IC_BR_GREATER_EQU	0x8C
#define IC_BR_GREATER		0x8D
#define IC_BR_LESS_EQU		0x8E

#define IC_BR_EQU_EQU2		0x8F
#define IC_BR_NOT_EQU2		0x90
#define IC_BR_LESS2		0x91
#define IC_BR_GREATER_EQU2	0x92
#define IC_BR_GREATER2		0x93
#define IC_BR_LESS_EQU2		0x94

#define IC_BR_AND_ZERO		0x95
#define IC_BR_AND_NOT_ZERO	0x96
#define IC_BR_MM_ZERO		0x97
#define IC_BR_MM_NOT_ZERO	0x98
#define IC_BR_AND_AND_ZERO	0x99
#define IC_BR_AND_AND_NOT_ZERO	0x9A
#define IC_BR_OR_OR_ZERO	0x9B
#define IC_BR_OR_OR_NOT_ZERO	0x9C

#define IC_BR_BT		0x9D
#define IC_BR_BTS		0x9E
#define IC_BR_BTR		0x9F
#define IC_BR_BTC		0xA0
#define IC_BR_NOT_BT		0xA1
#define IC_BR_NOT_BTS		0xA2
#define IC_BR_NOT_BTR		0xA3
#define IC_BR_NOT_BTC		0xA4

#define IC_SWAP_U8		0xA5
#define IC_SWAP_U16		0xA6
#define IC_SWAP_U32		0xA7
#define IC_SWAP_I64		0xA8

#define IC_ABS_I64		0xA9
#define IC_SIGN_I64		0xAA
#define IC_MIN_I64		0xAB
#define IC_MIN_U64		0xAC
#define IC_MAX_I64		0xAD
#define IC_MAX_U64		0xAE
#define IC_MOD_U64		0xAF
#define IC_SQR_I64		0xB0
#define IC_SQR_U64		0xB1
#define IC_SQR			0xB2
#define IC_ABS			0xB3
#define IC_SQRT			0xB4
#define IC_SIN			0xB5
#define IC_COS			0xB6
#define IC_TAN			0xB7
#define IC_ATAN			0xB8
#define IC_ICS_NUM		0xB9

#define KW_INCLUDE	0
#define KW_DEFINE	1
#define KW_UNION	2
#define KW_CATCH	3
#define KW_CLASS	4
#define KW_TRY		5
#define KW_IF		6
#define KW_ELSE		7
#define KW_FOR		8
#define KW_WHILE	9
#define KW_EXTERN	10
#define KW__EXTERN	11
#define KW_RETURN	12
#define KW_SIZEOF	13
#define KW__INTERN	14
#define KW_DO		15
#define KW_ASM		16
#define KW_GOTO		17
#define KW_EXE		18
#define KW_BREAK	19
#define KW_SWITCH	20
#define KW_START	21
#define KW_END		22
#define KW_CASE		23
#define KW_DFT		24
#define KW_PUBLIC	25
#define KW_OFFSET	26
#define KW_IMPORT	27
#define KW__IMPORT	28
#define KW_IFDEF	29
#define KW_IFNDEF	30
#define KW_IFAOT	31
#define KW_IFJIT	32
#define KW_ENDIF	33
#define KW_ASSERT	34
#define KW_REG		35
#define KW_NOREG	36
#define KW_LASTCLASS	37
#define KW_NO_WARN	38
#define KW_HELP_INDEX	39
#define KW_HELP_FILE	40
#define KW_STATIC	41
#define KW_LOCK		42
#define KW_DEFINED	43
#define KW_INTERRUPT	44
#define KW_HASERRCODE	45
#define KW_ARGPOP	46
#define KW_NOARGPOP	47

#define AKW_ALIGN	64
#define AKW_ORG		65
#define AKW_I0		66
#define AKW_I8		67
#define AKW_I16		68
#define AKW_I32		69
#define AKW_I64		70
#define AKW_U0		71
#define AKW_U8		72
#define AKW_U16		73
#define AKW_U32		74
#define AKW_U64		75
#define AKW_F64		76
#define AKW_DU8		77
#define AKW_DU16	78
#define AKW_DU32	79
#define AKW_DU64	80
#define AKW_DUP		81
#define AKW_USE16	82
#define AKW_USE32	83
#define AKW_USE64	84
#define AKW_IMPORT	85
#define AKW_LIST	86
#define AKW_NOLIST	87
#define AKW_BINFILE	88
#define KW_KWS_NUM	89

#define CMP_TEMPLATE_INC	0x00
#define CMP_TEMPLATE_DEC	0x01
#define CMP_TEMPLATE_MOD	0x02
#define CMP_TEMPLATE_LESS	0x03
#define CMP_TEMPLATE_GREATER	0x04
#define CMP_TEMPLATE_LESS_EQU	0x05
#define CMP_TEMPLATE_GREATER_EQU 0x06
#define CMP_TEMPLATE_STRLEN	0x07
#define CMP_TEMPLATE_RDTSC	0x08
#define CMP_TEMPLATE_SIGN_I64	0x09
#define CMP_TEMPLATE_FSTP	0x0A
#define CMP_TEMPLATE_FLD	0x0B
#define CMP_TEMPLATE_SQR	0x0C
#define CMP_TEMPLATE_ABS	0x0D
#define CMP_TEMPLATE_SQRT	0x0E
#define CMP_TEMPLATE_SIN	0x0F
#define CMP_TEMPLATE_COS	0x10
#define CMP_TEMPLATE_TAN	0x11
#define CMP_TEMPLATE_ATAN	0x12

#define ASSOCF_LEFT	1
#define ASSOCF_RIGHT	2
#define ASSOC_MASK	3

#define PREC_NULL		0x00
#define PREC_TERM		0x04
#define PREC_UNARY_POST		0x08
#define PREC_UNARY_PRE		0x0C
#define PREC_EXP		0x10
#define PREC_MUL		0x14
#define PREC_AND		0x18
#define PREC_XOR		0x1C
#define PREC_OR			0x20
#define PREC_ADD		0x24
#define PREC_CMP		0x28
#define PREC_CMP2		0x2C
#define PREC_AND_AND		0x30
#define PREC_XOR_XOR		0x34
#define PREC_OR_OR		0x38
#define PREC_ASSIGN		0x3C

#define PREC_MAX		0x40


#define FSF_PUBLIC		0x01
#define FSF_ASM			0x02
#define FSF_STATIC		0x04
#define FSF__			0x08
#define FSF_INTERRUPT		(1<<Ff_INTERRUPT)
#define FSF_HASERRCODE		(1<<Ff_HASERRCODE)
#define FSF_ARGPOP		(1<<Ff_ARGPOP)
#define FSF_NOARGPOP		(1<<Ff_NOARGPOP)
#define FSG_FUN_FLAGS1 (FSF_INTERRUPT|FSF_HASERRCODE|FSF_ARGPOP|FSF_NOARGPOP)
#define FSG_FUN_FLAGS2 (FSG_FUN_FLAGS1|FSF_PUBLIC)


#define PRS0_NULL		0x000000
#define PRS0__EXTERN		0x000001
#define PRS0__INTERN		0x000002
#define PRS0__IMPORT		0x000003
#define PRS0_EXTERN		0x000004
#define PRS0_IMPORT		0x000005
#define PRS0_TYPECAST		0x000006


#define PRS1B_NULL		0
#define PRS1_NULL		0x000000
#define PRS1B_LOCAL_VAR		1
#define PRS1_LOCAL_VAR		0x000100
#define PRS1B_FUN_ARG		2
#define PRS1_FUN_ARG		0x000200
#define PRS1B_CLASS		3
#define PRS1_CLASS		0x000300
#define PRS1B_STATIC_LOCAL_VAR	4
#define PRS1_STATIC_LOCAL_VAR	0x000400
#define PRS1B__EXTERN_IMPORT	5
#define PRS1_NOT_REALLY__EXTERN	0x000500

#define PRSF_UNION		0x010000

typedef struct COptReg
{
I64	offset;
CMemberLst *m;
} COptReg;

#define CMPF_ASM_BLK		1
#define CMPF_ONE_ASM_INS	2
#define CMPF_LEX_FIRST		4
#define CMPF_PRS_SEMICOLON	8

Bool AsmStoreNum(CCmpCtrl *cc,CAsmNum2 *num2,I64 cnt,Bool U8_avail);
Bool ATAGetRes(CBlkDev *bd,F64 timeout,U8 *buf,I64 cnt,I64 _avail,Bool one_read);
Bool ATANop(CBlkDev *bd,F64 timeout);
Bool ATAPISeek(CBlkDev *bd,I64 native_blk);
Bool ATAPISetMaxSpeed(CBlkDev *bd);
Bool ATAPIStartStop(CBlkDev *bd,F64 timeout,Bool start);
Bool ATAPIWritePktWord(CBlkDev *bd,F64 timeout,...);
Bool ATARepExitAllApplications();
Bool ATAWaitDRQ(CBlkDev *bd,F64 timeout);
Bool ATAWaitNotBUSY(CBlkDev *bd,F64 timeout);
Bool BgtPutKey(CDoc *doc,U8 *,I64 ch,I64 sc);
Bool BlkDevLock(CBlkDev *bd);
Bool BlkRead(CDrv *dv,U8 *buf,I64 blk,I64 cnt);
Bool BlkWrite(CDrv *dv,U8 *buf,I64 blk,I64 cnt);
Bool BootDVDProbeAll(CBlkDev *bd);
Bool BootDVDProbe(CBlkDev *bd);
Bool CFileNameTo(U8 *dst,U8 *src);
Bool CheckMap(I64 x,I64 y);
Bool CheckOverlap();
Bool CheckWinner(I64 player);
Bool ChkCodePtr(U8 *ptr);
Bool ChkDskConfirm(Bool *_fix,Bool *_confirm);
Bool ChkPtr(U8 *ptr);
Bool CopySingle(U8 *f1,U8 *f2);
Bool CopySingleZ(U8 *f1,U8 *f2);
Bool CTPlot(CDC *dc,I64 x,I64 y,I64);
Bool CtrlInside(CCtrl *c,I64 x,I64 y);
Bool CtrlInsideRect(CCtrl *c,I64 x,I64 y);
Bool CursorInWin(CTask *task,I64 x,I64 y);
Bool DiffBins(CDoc *doc1,CDoc *doc2);
Bool DiffSub(CDoc *doc,I64 *_df_flags,I64 j1_lo,I64 j1_hi,I64 j2_lo,I64 j2_hi,I64 cnt1,I64 cnt2,CDocEntry **doc_sorted1,CDocEntry **doc_sorted2,CDocEntry **doc_unsorted1,CDocEntry **doc_unsorted2);
Bool DirLongNameFill(CDirEntry *tmpde,CFAT32DirEntryLong *de,I64 *xsum);
Bool DocFileEd(I64 _type,U8 *filename,U8 *needle_str,I64 *_num,I64 edf_dof_flags);
Bool DocGoToLine(CDoc *doc,I64 line_num);
Bool DocLock(CDoc *doc);
Bool DocUnlock(CDoc *doc);
Bool DrvLock(CDrv *dv);
Bool Drv(U8 drv_let);
Bool FAT32CDirFill(CDirEntry *tmpde,CFAT32DirEntry *de,CDate _local_time_offset);
Bool FAT32DirFill(CFAT32DirEntry *de,CDirEntry *tmpde,I64 *_de_cnt,CDate _local_time_offset);
Bool FAT32DirNew(CDrv *dv,U8 *cur_dir,CDirEntry *tmpde,Bool free_old_chain);
Bool FireMissile(I64 n);
Bool GetLink(I64 type,U8 **_tag,U8 **_link,Bool *_pop_up,Bool *_quote,U8 **_html_link);
Bool GrPlot0(CDC *dc,I64 x,I64 y);
Bool HostChgDsk(U8 *iso_filename);
Bool InSetMsPlot(I64 mS,I64 x,I64 y,I64 z);
Bool IPNumTreeAdd(struct LogStruct **_head,struct LogStruct *tmplg);
Bool IsBlocked(struct BlockedStruct *head,U32 ip_num);
Bool IsDbgMode();
Bool IsDir(U8 *dir_name);
Bool IsDownLoad(struct LogStruct *tmplg);
Bool IsEditableText(CDocEntry *doc_e);
Bool IsIndex(struct LogStruct *tmplg);
Bool IsKeeper(struct LogStruct *tmplg,CDate dstart,CDate dend);
Bool IsLexExpression2Bin(CCmpCtrl *cc,U8 **_machine_code);
Bool ISOInit(CDrv *dv,I64 blk);
Bool IsRaw();
Bool LaserPlot(struct CDC *dc,I64 x,I64 y,I64);
Bool LexDollar(CCmpCtrl *cc,CDoc *doc,CDocEntry *doc_e);
Bool LOS(I64 r1,I64 c1,I64 r2,I64 c2);
Bool LOS(I64 x1,I64 y1,I64 x2,I64 y2);
//Bool LOSPlot(struct LOSCtrl *l,I64 x,I64 y,I64 z);
//Bool LOSPlot(U8 *,I64 x,I64 y,I64);
Bool Mem32DevIns(CMemRange *tmpmr);
Bool MPVisRecalc(struct MPCtrl1 *job);
Bool OptIC4(CIntermediateCode *tmpi);
Bool OptIC6(CIntermediateCode *tmpi);
Bool PopUpExtents(I64 *_x1,I64 *_x2,I64 *_y1,I64 *_y2);
Bool PopUpTransform(I64 *r);
Bool PrepPoly(struct CD3I32 *p,I64 *r,I64 cx,I64 h,struct CD3I32 *poly);
Bool Prompt(I64 i);
Bool PrsAsmImm(CCmpCtrl *cc,CAsmArg *arg);
Bool PrsAsmInst(CCmpCtrl *cc,CHashOpcode *tmpo,I64 argcnt);
Bool Quit();
Bool RedSeaDirNew(CDrv *dv,U8 *cur_dir,CDirEntry *tmpde,Bool free_old_chain);
Bool RedSeaValidate(U8 drv_let);
Bool RegCache();
Bool RegWrite(U8 *path,U8 *fmt,...);
Bool SpriteSelUnselShiftPts(U8 *elems,I64 x,I64 y,I64 *_cur_elem_num,I64 mode);
Bool SuggestSpelling(U8 *word);
Bool TaskValidate(CTask *task);
Bool TestSameSlope(I64 x,I64 y,I64 w,I64 h);
Bool TestSumFact(I64 n,I64 target_sf,I64 sqrt_primes,I64 cbrt_primes,struct Prime *p);
Bool UnitMovePlot(U0,I64 x,I64 y,I64);
Bool UnitMove(struct Unit *tmpu,I64 x2,I64 y2);
//Bool UnitMove(Unit *tmpu,I64 x,I64 y);
Bool View();
CBGR48 GrPaletteColorGet(I64 color_num);
struct CBgtEntry *BgtEntryCopy(struct CBgtEntry *tmpb,Bool periodic_copy);
CBlkDev *BlkDevNextFreeSlot(U8 first_drv_let,I64 type);
CCacheBlk *DskCacheFind(CDrv *dv,I64 blk);
CCodeMisc *OptLabelFwd(CCodeMisc *lb);
CColorROPU16 Str2ColorU16(U8 *st);
CColorROPU32 Str2ColorU32(U8 *st);
CCtrl *CtrlFindUnique(CTask *haystack_task,I64 needle_type);
CCtrl *SliderNew();
CCtrl *TermBttnNew();
CDate Dos2CDate(U16 t,U16 d);
CDate Now();
CDate Struct2Date(CDateStruct *_ds);
CDirEntry *FilesFind2(U8 *files_find_mask,I64 fuf_flags);
CDirEntry *FMRebuildDocDrv(U8 drv_let,CDoc *doc,CDirEntry **_head,Bool init);
CDirEntry MGFind(CDirEntry *needle_entry,CDirEntry *haystack_lst);
CDocBin *DocBinFindNum(CDoc *haystack_doc,I64 needle_num);
CDocBin *DocBinFindTag(CDoc *haystack_doc,U8 *needle_tag);
CDoc *Doc2TXT(CDoc *doc_in);
CDoc *DocBorderNew(CDoc *pdoc);
CDoc *DocCopy(CDoc *doc,CDocEntry *start,CDocEntry *end);
CDocEntry *DocEntryCopy(CDoc *doc,CDocEntry *doc_e);
CDocEntry *DocPutS(CDoc *doc,U8 *st);
CDocEntry *DocSplitTag(CDoc *doc,CDocEntry *doc_e,I64 i,I64 x,I64 y,I64 type_u8);
CDocEntry *DocWordWrapAdd(CDoc *doc,CDocEntry *doc_e,I64 *_k,I64 left,I64 right_margin,I64 x,I64 y);
CDocEntry *PrsDollarCmd(CDoc *doc,U8 *st);
CDoc *KCfgAddDev(struct CKCfg *c);
struct CEdSprite *EdSpriteNew(I64 type,struct CSprite *tmpg);
//struct CFMUncollapsedLst *FMCollectUncollapsedLst(CDoc *doc);
CHashAC *ACHashAdd(U8 *w);
CHashClass *OptClassFwd(CHashClass *tmpc);
CHashClass *PrsClass(CCmpCtrl *cc,I64 keyword,I64 fsp_flags,Bool is_extern);
CHashClass *PrsClassNew();
CHashClass *PrsType(CCmpCtrl *cc,CHashClass **_tmpc1,I64 *_mode,CMemberLst *tmpm,U8 **_ident,CHashFun **_fun_ptr,CHashExport **_tmpex,CArrayDim *tmpad,I64 fsp_flags);
CHashDefineStr *DefineLoad(U8 *dname,U8 *st);
CHashDefineStr *DefineLstLoad(U8 *dname,U8 *lst);
CHashFun *PrsFunJoin(CCmpCtrl *cc,CHashClass *tmp_return,U8 *name,I64 fsp_flags);
CHashFun *PrsFunNew();
CHash *FunSegFind(U8 *addr,I64 *_offset);
CInst *InstEntryFind(U8 *rip,I64 opsize,I64 seg_size);
CIntermediateCode *OptBrNotZero(CCmpCtrl *cc,CIntermediateCode *tmpi);
CIntermediateCode *OptBrZero(CCmpCtrl *cc,CIntermediateCode *tmpi);
CIntermediateCode *OptPass012(CCmpCtrl *cc);
CIntermediateCode *PrsAddOp(CCmpCtrl *cc,I64 stk_op,CHashClass *tmpc);
CJob *TaskMsg(CTask *_srv,CTask *master,I64 msg_code,I64 arg1,I64 arg2,I64 flags);
//CKCfg *KCfgNew();
CLexFile *LexFilePop(struct CCmpCtrl *cc);
CLexFile *LexFilePush(struct CCmpCtrl *cc);
struct CMacroTmp *Cmd2MT(struct CJob *tmpc);
CMathODE *SpanNew();
CMemberLst *MemberClassBaseFind(CHashClass *needle_class,CHashClass *haystack_class);
CMemberLst *MemberFind(U8 *needle_str,CHashClass *haystack_class);
CMemberLst *MemberLstNew(I64 _reg);
CMemberLstMeta *MemberMetaFind(U8 *needle_str,CMemberLst *haystack_member_lst);
CMenuEntry *MenuEntryFind(CMenu *haystack_menu,U8 *needle_full_name);
CMenuEntry *MenuNewSub(CCmpCtrl *cc,CTask *task);
CMenuEntry *MenuSubEntryFind(CMenuEntry *haystack_first,U8 *needle_entry_name);
CMenu *MenuFilePush(U8 *filename);
CMenu *MenuPush(U8 *st);
Complex *PoleZeroFind(I64 x,I64 y);
struct CSprite *SMArrow(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMCircle(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMEllipse(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMLine(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMPlanarSymmetry(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2);
struct CSprite *SMPolygon(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,I64 sides,CColorROPU32 color);
struct CSprite *SMPolyLineFamily(I64 eletype,CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMPolyPoint(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMRect(CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color);
struct CSprite *SMScrnBitMap(I64 eletype,CDC *dc,CDC *dc2,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 bm_bkcolor);
struct CSprite *SpriteSideBar2SpriteQue(CDoc *doc,struct CSprite *head,I64 *_cur_elem_num);
CTask *MenuTask();
CTask *Noise(I64 mS,F64 min_ona,F64 max_ona);
CTask *Sweep(I64 mS,F64 ona1,F64 ona2);
struct CTemplateCS *CtrlSliderGet();
//_extern _TASK_END_NOW U0 TaskEndNow();
U0 TaskEndNow();
//_extern _YIELD U0 Yield();
U0 Yield();
F64 Beat();
F64 Caw(F64 t,F64 period);
F64 Clamp(F64 d,F64 lo,F64 hi);
F64 CompileDemo(U8 *st);
F64 Cost(CMathODE *ode);
F64 F(Complex *x);
F64 FullCaw(F64 t,F64 period);
F64 FullSaw(F64 t,F64 period);
F64 FullTri(F64 t,F64 period);
F64 Max(F64 n1,F64 n2);
F64 Min(F64 n1,F64 n2);
F64 MPDraw(CTask *task);
F64 MyCos(F64 d);
F64 MySin(F64 d);
F64 PopUpDuration();
F64 Pow10I64(I64 i);
F64 Rand();
F64 Saw(F64 t,F64 period);
F64 SpanTime();
F64 Test(I64 n,I64 my_mp_cnt);
F64 tM();
F64 Tri(F64 t,F64 period);
F64 tS();
F64 VGAPattern(I64 p);
I16 RandI16();
I32 RandI32();
I64 ACDCompareWords(U8 *e1,U8 *e2);
I64 ACDNextCmd(U8 **_ptr);
I64 ACPriorWordInStr(U8 *src,U8 *dst,I64 len,I64 buf_size);
I64 ACSkipCrap(U8 *src,I64 len);
//I64 AddTri(struct BallDefineStruct *,I64 c,I64 n0,I64 n1,I64 n2);
//I64 AddTri(struct ManDefineStruct *,I64 c,I64 n0,I64 n1,I64 n2);
//I64 AddVertex(struct BallDefineStruct *,I64 x,I64 y,I64 z);
//I64 AddVertex(struct ManDefineStruct *md,I64 x,I64 y,I64 z);
//I64 AnimateTask(struct CTask *);
I64 AsmLexExpression(CCmpCtrl *cc);
I64 AsmMakeArgMask(CCmpCtrl *cc,CAsmArg *arg);
I64 ATAGetDevId(CBlkDev *bd,F64 timeout,Bool keep_id_record);
I64 ATAReadNativeMax(CBlkDev *bd,F64 timeout);
I64 Bcd2Bin(U64 b);
I64 BCnt(I64 d);
I64 BgtAcctColor(U8 *st);
I64 BIOSTotalMem();
I64 BlkDevsSize();
I64 BmpPeek(U8 *bmp,I64 x,I64 y);
I64 CeilI64(I64 num,I64 to);
I64 CmpRawType(CHashClass *tmpc);
I64 CmpRawTypePointed(CHashClass *tmpc);
I64 Compare(I64 e1,I64 e2);
I64 CopyVideo();
I64 DayOfWeek(I64 i);
I64 DefineCnt(U8 *dname);
I64 DEPtrCompare(CDocEntry **e1,CDocEntry **e2);
I64 DiffEntriesCompare(CDocEntry *doc_e1,CDocEntry *doc_e2);
I64 DipY(I64 x,I64 z);
I64 DirTreeSerializeFill(CDirEntry *tmpde,U8 *dst);
I64 DirTreeSerializeSize(CDirEntry *tmpde);
I64 DocBinPtrRst(CDoc *doc,CDocEntry *doc_e);
I64 DocCharDist(CDoc *doc,I64 x,I64 y);
I64 DocTmpAttr(CDoc *doc,CDocEntry *doc_e,I64 cur_u8_attr);
I64 DocWordWrapDel(CDoc *doc,CDocEntry *doc_e,Bool full_refresh,Bool same_win,I64 left_margin,I64 right_margin,CDocEntry **_best_doc_e,I64 *_best_col);
I64 DrvsSize();
I64 DskCacheHash(I64 blk);
I64 EdCurU8(CDoc *doc);
I64 EdLeftClickLink(CDoc *doc,CDocEntry *doc_e);
I64 EndianI64(I64 d);
I64 FacingChg(I64 f1,I64 f2);
I64 FAT32AllocClus(CDrv *dv,I64 c,I64 cnt);
I64 FAT32AllocContiguousClus(CDrv *dv,I64 cnt);
I64 FAT32ChkDskLst(CDrv *dv,CDirEntry *tmpde1,U8 *bits,U32 *bits2,I64 size,I64 bpc);
I64 FAT32ChkDsk(U8 drv_let,Bool *_fix,Bool *_confirm);
I64 FindFile(U8 *needle_str,U8 *haystack_filename,I64 *_fuf_flags,U8 *replace_text);
I64 FindWiz();
I64 FirstDayOfMon(I64 i);
I64 FirstDayOfYear(I64 i);
I64 FloorI64(I64 num,I64 to);
I64 FSize(CFile *f);
I64 GodDoodleBits(I64 num_bits);
I64 GrBlot3(CDC *dc,I64 x1,I64 y1,I64 z1,CDC *img);
I64 GrFloodFillRay(CDC *dc,I64 x,I64 y,I64 z,I32 *db);
I64 HashEntrySize2(CHashSrcSym *tmph);
I64 HashEntrySize(CHashSrcSym *tmph);
I64 HashTableSize2(CHashTable *table);
I64 HashTypeNum(CHash *tmph);
I64 HashVal(CHash *tmph);
I64 HasLower(U8 *src);
I64 HexMoveOneCost(struct Unit *tmpu,I64 r,I64 c,I64 facing);
I64 HexMoveOne(I64 *_row,I64 *_col,F64 x,F64 y);
I64 HPET();
I64 ICModr1(I64 r,CICType t2,I64 r2,I64 d2);
I64 InstEntriesCompare(CInst *tmpins1,CInst *tmpins2);
I64 LastDayOfMon(I64 i);
I64 LastDayOfYear(I64 i);
I64 Let2BlkDevType(U8 drv_let);
I64 Lex(CCmpCtrl *cc);
I64 LexExpression(CCmpCtrl *cc);
I64 LexGetChar(CCmpCtrl *cc);
I64 LineRep1(CDirEntry *tmpde);
I64 LinkChkDoc(CDoc *doc,I64 *_fuf_flags);
I64 LinkChkFile(U8 *filename,I64 *_fuf_flags);
I64 MagicPairs(I64 N);
I64 *Mat4x4IdentEqu(I64 *r);
I64 MemberMetaData(U8 *needle_str,CMemberLst *haystack_member_lst);
I64 MorseWaitKey();
I64 MPSum(I64 my_mp_cnt);
I64 MyLeftCB1(CDoc *,CDocEntry *);
I64 MyLeftCB2(CDoc *,CDocEntry *);
I64 MyUtilDoc(CDoc *doc,I64 fuf_flags);
I64 MyUtilFile(U8 *filename,I64 fuf_flags);
I64 MyUtilLst(CDirEntry *tmpde,I64 fuf_flags);
I64 Name2DirClus(CDrv *dv,U8 *dirname);
I64 Name2ParentDirClus(CDrv *dv,U8 *dirname);
I64 ObjCompare(struct Obj *o1,struct Obj *o2);
I64 OptMVCompare(struct COptMemberVar *mv1, struct COptMemberVar *mv2);
I64 OptPass789A(struct CCmpCtrl *cc,struct COptReg*reg_offsets,U8 *buf,struct CDbgInfo **_dbg);
I64 OtherPole(I64 pole1,I64 pole2);
I64 PenBrushesSize();
I64 PhaseDo();
I64 PopUpColorType();
I64 PopUpDiffMenu();
I64 PopUpFindMenu();
I64 PopUpFreq();
I64 PopUpLinkType(Bool include_anchor);
I64 PopUpPageSettingType();
I64 PopUpPickLst(U8 *lst);
I64 PopUpSpriteBitMap(CColorROPU32 color,I64 width);
I64 PopUpSpriteMain(struct CSprite **_head,I64 *_cur_elem_num,CDoc *_doc,CDocEntry *_doc_e);
I64 PopUpSpriteType();
I64 PopUpTermRight(U8 *header);
I64 PopUpWidgetType();
I64 PosInStk(I64 pole,I64 disk);
I64 Primes(I64 range,I64 _my_mp_cnt);
I64 *PrimesNew(I64 N,I64 *_sqrt_primes,I64 *_cbrt_primes);
I64 PrsDocFlags(CCmpCtrl *cc,I64 *_de_flags,U32 *_type);
I64 PrsDocFlagSingle(CCmpCtrl *cc,I64 *_de_flags,U32 *_type,Bool turn_on);
I64 PrsKeyWord(CCmpCtrl *cc);
I64 PrsPop2(CPrsStk *ps);
I64 PrsPop(CPrsStk *ps);
I64 PrsUnaryModifier(CCmpCtrl *cc,CPrsStk *ps,CMemberLst **_local_var,CArrayDim **_tmpad,I64 *unary_post_prec);
I64 PrsUnaryTerm(CCmpCtrl *cc,CPrsStk *ps,CMemberLst **_local_var,CArrayDim **_tmpad,I64 *max_prec,I64 *unary_pre_prec,I64 *paren_prec);
I64 RandI64();
I64 Recurse2(I64 n);
I64 Recurse3(I64 n,I64 lo,I64 hi);
I64 Recurse(I64 n);
I64 RedSeaAllocClus(CDrv *dv,I64 cnt);
I64 RedSeaChkDskLst(CDrv *dv,CDirEntry *tmpde1,U8 *bits,U8 *bits2,I64 size,I64 bpc);
I64 RedSeaChkDsk(U8 drv_let,Bool *_fix,Bool *_confirm);
I64 RedSeaISOPass1(CDirEntry *tmpde);
I64 RoundI64(I64 num,I64 to);
I64 ScrnZoomTablesSize();
I64 SpriteBitMapEd(CDoc *,CDocEntry *doc_e,CDC *dc,I64 *_xx1,I64 *_yy1,I64 *_xx2,I64 *_yy2,CDC **_img,CColorROPU32 bkcolor);
I64 SpriteEd(CDoc *doc,CDocEntry *doc_ce,I64 x,I64 y,struct CSprite **_head,I64 *_cur_elem_num);
I64 SpriteElemQuedBaseSize(I64 type);
I64 SpriteElemSize(struct CSprite *tmpg);
I64 SpriteSize(U8 *elems);
I64 SpriteTypeMask(U8 *elems);
I64 SumFact(I64 n,I64 sqrt_primes,struct Prime *p);
I64 Sum(I64 n,I64 my_mp_cnt);
I64 SysTimerRead();
I64 TaskInit(CTask *task,I64 stk_size);
I64 TaskQueSize(CTask *task);
I64 TaskStkSize(CTask *task);
I64 TermRightClickLink(CDoc *doc,CDocEntry *doc_e);
I64 TestCoreRange(struct RangeJob *r);
I64 TestCoreSubRange(struct RangeJob *r);
I64 TimeCal();
I64 TopDisk(I64 pole);
I64 TSSSize(CTSS *tss);
I64 Tweaked();
I64 WordsCompare(U8 *e1,U8 *e2);
I64 YearStartDate(I64 year);
//I8i Option(I64i num,I8i val);
Bool DocUnlock(CDoc *doc);
CDocEntry *DocPutLine(CDoc *doc,CDocEntry *doc_e);
I64 DocSize(CDoc *doc);
U0 DocBinsValidate(CDoc *doc);
U0 DocDel(CDoc *doc);
U0 DocLoad(CDoc *doc,U8 *src2,I64 size);
U8 *Doc2PlainText(CDoc *doc,CDocEntry *doc_e);
U0 IntBeepOff();
U0 IntBeepOn();
U0 IntMy40();
U0 IntMy41();
U0 IntMy42();
U0 IntMy43();
U0 IRQComm3();
U0 IRQComm4();
struct LogStruct *PrsLogFiles(U8 *files_find_mask,CDate *_dstart,CDate *_dend);
struct MyMass *PlaceMass(I64 type,I64 x,I64 y,F64 r,F64 dx,F64 dy,F64 mass,CTask *mem_task);
//struct MyMass *PlaceMass(I64 x,I64 y);
struct MySpring PlaceSpring(struct MyMass *tmpm1,struct MyMass *tmpm2);
//struct MySpring *PlaceSpring(struct MyMass *tmpm1,struct MyMass *tmpm2,I64 type);
struct PickFrame *Init();
struct PObj *PCircleNew(struct PickFrame *pf,I64 p_num,I64 r);
//struct PObj *Pstruct CSpriteNew(struct PickFrame *pf,U8 *img,I64 p_num,I64 *r,I64 *dr);
struct PObj *PLineNew(struct PickFrame *pf,I64 p1_num,I64 p2_num);
struct PObj *PObjNew(struct PickFrame *pf,I64 type,I64 color);
struct PObj *PPtFind(struct PickFrame *pf,I64 x,I64 y);
struct PObj *PPtNew(struct PickFrame *pf,I64 x,I64 y);
struct PObj *PPtNum(struct PickFrame *pf,I64 num);
struct PowPrime *PowPrimesNew(I64 N,I64 sqrt_primes,struct Prime *primes,I64 *_num_powprimes);
struct CComm *CommInit8n1(I64 port,I64 baud);
struct CCtrl *CtrlPanelNew();
struct CCtrl *SliderNew();
struct CCtrl *TempoNew();
struct CDate MyStr2Date(U8 *st);
struct CDC *DrawHexMap(I64 *_w,I64 *_h);
struct Explosion *ExplosionNew(I64 x,I64 y);
struct Obj *FishFind(I64 x1,I64 y1,I64 *_dd);
struct Photon *PhotonNew();
struct Ship *ShipNew(I64 x,I64 y,I64 type);
struct Ship TargetGet(struct Missile *tmpmi);
struct Track *TrackFind(struct Track *_tmpt,I64 x,I64 z);
struct Unit *UnitFind(I64 x,I64 y,I64 player);
U0 ACDDictWordsAdd(U8 *st);
U0 ACDFillin(I64 n);
U0 ACDGen(U8 *in_file);
U0 ACDocRst(I64 left,I64 top);
U0 ACDPreprocess(U8 *in_name,U8 *out_name);
U0 ACDWordsLoad();
U0 ACFillInAdd(CHashAC *tmpw);
U0 ACFillIn(I64 n);
U0 ACMainFileLstTraverse(U8 *files_find_mask);
U0 ACProgressTask(Bool *_start_flag);
U0 ACPutChoices(CDoc *focus_l,CDocEntry *doc_e,CTask *focus_task,Bool force_refresh);
U0 ACSingleFileAdd(U8 *buf);
U0 ACTaskAlt(I64 sc,I64 last_sc,CTask *,CTask *original_focus_task);
U0 ACTaskCtrl(I64 sc,I64 last_sc,CTask *focus_task,CTask *original_focus_task);
U0 ACTaskEndCB();
U0 ACTask(I64);
U0 ACTaskNormal(I64 sc,I64 last_sc,CTask *focus_task,CTask *original_focus_task);
U0 AdamErr(U8 *fmt,...);
U0 AdamLog(U8 *fmt,...);
U0 AddBox(struct ManDefineStruct *md,I64 c,I64 x1,I64 y1,I64 z1,F64 w,F64 h,F64 d,F64 h2,F64 h3,F64 az,F64 ay,F64 ax,I64 *ox,I64 *oy,I64 *oz);
U0 AdjustLoads(CMathODE *ode);
U0 AlienGame();
U0 AllDel(struct CMathODE *ode);
U0 AnimateEndCB();
/*
U0AnimateTask(I64);
U0AnimateTask(struct SpanAnimateStruct *a);
U0AnimateTask(struct CTask *parent);
U0AnimateTask(struct CTask *parent_task);
*/
U0 AnimationDelaySet();
U0 AOTGlblsResolve(CCmpCtrl *cc,CAOT *tmpaot);
U0 AOTLocalsResolve(CCmpCtrl *cc);
U0 AOTStoreCodeU32(CCmpCtrl *cc,U32 d);
U0 AOTStoreCodeU64(CCmpCtrl *cc,U64 q);
U0 AOTStoreCodeU8At(CCmpCtrl *cc,I64 rip,...);
U0 AOTStoreCodeU8(CCmpCtrl *cc,U8 b);
U0 ASCIIOrgan();
U0 AsmAndC3();
U0 AsmHashLoad();
U0 AsmLineLst(CCmpCtrl *cc);
U0 AsmPrsInsFlags(CCmpCtrl *cc,CInst *tmpins);
U0 AsmResolve(CCmpCtrl *cc,CAsmUnresolvedRef *tmpu,U8 *label,Bool undefined);
U0 AsmUnresolvedAdd(CCmpCtrl *cc,U8 *machine_code,I64 type,I64 rip,I64 rel_rip,CAsmUndefHash *local_asm_undef_hash,CAsmUndefHash *glbl_asm_undef_hash,I64 line_num,Bool U8_avail);
U0 ATABlkSel(CBlkDev *bd,I64 blk,I64 cnt);
U0 ATACmd(CBlkDev *bd,U8 cmd);
U0 ATARepEntry(I64 base0,I64 base1,I64 unit,U8 *msg,CATARep **_head,I64 *num_hints);
//U0 AttackHeader(Unit *tmpu,U8 *st,Unit *target);
U0 Balloon();
U0 BDCorrect(struct BallDefineStruct *bd);
U0 BDInit(struct BallDefineStruct *bd);
U0 BgtAcctsRead();
U0 BgtAcctsUpdate();
U0 BgtAcctsWrite();
U0 BgtDataRead();
U0 BgtDataWrite();
U0 BgtDel();
U0 BgtEntryDel2(struct CBgtEntry *tmpb);
U0 BgtEntryDel(struct CBgtEntry *tmpb);
U0 BgtIns(struct CBgtEntry *tmpb);
U0 BgtRegen();
U0 BgtTemplateDel(struct CBgtTemplate *tmpt);
U0 BgtTemplatePurge(struct CBgtTemplate *tmpt);
U0 BibleInit();
U0 BigCnt();
U0 BigGuns();
U0 BigShift();
U0 BlackDiamond();
U0 BlkDevLockFwdingSet(CBlkDev *bd);
U0 BlkDevRep();
U0 BlkDevsInitAll();
U0 BlkDevsRelease();
U0 BlkPoolAdd(CBlkPool *bp,CMemBlk *m,I64 pags);
U0 BlkPoolInit(CBlkPool *bp,I64 pags);
U0 BlkPoolsInit();
U0 BlkWriteZero(CDrv *dv,I64 blk,I64 cnt);
U0 BlockedStructAdd(struct BlockedStruct *head,U32 ip_num);
U0 BlockIPNuip(struct LogStruct *head);
U0 BmpLine(U8 *bmp,F64 x1,F64 y1,F64 x2,F64 y2);
U0 BmpPlot(U8 *bmp,I64 x,I64 y,I64);
U0 BombDrop(F64 x,F64 y);
U0 BomberGolf();
U0 BombHit(struct Bomb *tmpb);
U0 BootMHDOldRead(U8 src_drv,U8 dst_drv);
U0 BootMHDOldWrite(U8 src_drv,U8 dst_drv);
U0 BootMHDZero(U8 dst_drv);
U0 Bounce();
U0 Box();
U0 Branch();
U0 BreakConnectors();
U0 BSplineDemo();
U0 BuddySel(I64 i);
U0 BurnTrees();
U0 CalcNormals();
U0 Cartesian();
U0 CastleFrankenstein();
U0 CDate2Dos(U16 *t,U16 *d,CDate cdt);
U0 CenterMasses();
U0 CFTransform(struct CDC *dc,I64 *x,I64 *y,I64 *z);
U0 CharDemo();
U0 CharDo(U8 ch);
U0 CheckBugs(CTask *task);
U0 CheckCollisions();
U0 CheckDamage();
U0 Circle2S(I64 *_x,I64 *_y);
U0 CircleTrace();
U0 ClawDraw(struct CDC *dc,I64 x1,I64 y1,I64 x2,I64 y2,I64 w,I64 segments,Bool talon);
//U0 ClawsDraw(struct CTask *task,struct CDC *dc);
U0 CleanUp();
U0 CleanUp(CMathODE *ode);
U0 CleanUp(struct PickFrame *pf);
U0 ClickCallBack();
U0 ClipCopy(CDoc *doc);
U0 ClipCut(CDoc *doc);
U0 ClipDel();
U0 ClipPaste(CDoc *doc);
U0 CmpF1PushPop(CIntermediateCode *tmpi,CIntermediateCode *tmpi2);
U0 CmpF2PushPop(CIntermediateCode *tmpi,CIntermediateCode *tmpi1,CIntermediateCode *tmpi2);
U0 CmpFillTables();
U0 CmpLoadDefines();
U0 CmpMinTypePointed(CIntermediateCode *tmpi,I64 pt1);
U0 CmpNoteFloatOp(CCmpCtrl *cc,CIntermediateCode *tmpi,Bool dont_pushable,Bool dont_popable,I64 pos);
U0 CmpSetFloatOpPushPop(CCmpCtrl *cc,CIntermediateCode *tmpi,Bool *dont_push_float,Bool *dont_pop_float);
U0 CollectWords(I64 dx,I64 dy,I64 *_n);
U0 Collision();
U0 CommHndlr(I64 port);
U0 CommInit();
U0 CommPrint(I64 port,U8 *fmt,...);
U0 CommPutBlk(I64 port,U8 *buf,I64 cnt);
U0 CommPutChar(I64 port,U8 b);
U0 CommPutS(I64 port,U8 *st);
U0 Core0Talons();
//U0 CoreAPTalonsTask(struct CTask *master_task);
U0 CoupleEnds();
U0 CtrlAltA(I64);
U0 CtrlAltL(I64);
U0 CtrlAltS(I64);
U0 CtrlAltZ(I64 sc);
U0 CtrlPanelDel(struct CCtrl *c);
U0 CtrlsUpdate(CTask *task);
U0 CursorMovementDemo();
U0 CursorRemFile(U8 *filename);
U0 CursorUpdate(CTask *task,I64 x,I64 y);
U0 D1();
U0 D2();
U0 DatabaseDemo();
U0 DataDemo();
U0 Date2Struct(CDateStruct *_ds,CDate cdt);
U0 DbgDemo();
U0 DbgHelp();
U0 DCBlotColor8(CDC *dc,CDC *img);
U0 DCTransform(CDC *dc,I64 *_x,I64 *_y,I64 *_z);
U0 DelMass(struct MyMass *tmpm);
U0 DelScrnShots();
U0 DelSpring(struct MySpring *tmps);
U0 Demo();
U0 DiffSel(CDoc *doc,I64 *_df_flags,I64 j1_lo,I64 j1_hi,I64 j2_lo,I64 j2_hi,I64 cnt1,I64 cnt2,CDocEntry **doc_unsorted1,CDocEntry **doc_unsorted2);
U0 Digits();
U0 Directives();
U0 DirFileDoc(CDoc *doc,CDirEntry *tmpde);
U0 DirLinksIns();
U0 Display();
U0 DisplayWords(I64 n);
U0 DocBinDel(CDoc *doc,CDocBin *b);
U0 DocBinsValidate(CDoc *doc);
U0 DocBorderLstDraw(CDoc *doc);
U0 DocCut(CDoc *doc,CDocEntry *start,CDocEntry *end);
U0 DocDel(CDoc *doc);
U0 DocDelToEntry(CDoc *doc,CDocEntry *clear_entry,Bool clear_holds);
U0 DocDelToNum(CDoc *doc,I64 num);
U0 DocEntryDel(CDoc *doc,CDocEntry *doc_e);
U0 DocEntryToggle(CDoc *doc);
U0 DocFlagsToggle(CDoc *doc,I64 tog_flags);
U0 DocHelpIdx(CDoc *doc,U8 *idx);
U0 DocInit();
U0 DocInsEntry(CDoc *doc,CDocEntry *doc_e);
U0 DocLoad(CDoc *doc,U8 *src2,I64 size);
U0 DocProfile(U8 *filename,I64 flags);
U0 DocRecalcXY(CDoc *doc,CDocEntry *doc_e,I64 k,I64 left,I64 width,I64 height,I64 left_margin,I64 right_margin,I64 x0,I64 y0,I64 *_x,I64 *_y);
U0 DocRst(CDoc *doc,Bool is_old);
U0 DocTermNew();
U0 DocUpdateTaskDocs(CTask *task);
U0 DoGame();
U0 DoIt();
U0 Doodle();
U0 DownLoadRep(struct LogStruct *head,CDate dstart,CDate dend);
U0 Draw();
U0 DrawBoard(I64 player);
U0 DrawCtrlBttn(CDC *dc,CCtrl *c);
U0 DrawCtrlPanelCtrl(struct CDC *dc,struct CCtrl *c);
U0 DrawCtrls(CTask *task);
U0 DrawCtrlSlider(CDC *dc,CCtrl *c);
U0 DrawCtrlSlider(struct CDC *dc,struct CCtrl *c);
U0 DrawDots();
//U0 DrawDrops(struct CTask *,struct CDC *dc);
//U0 DrawFrame(struct CTask *task,struct CDC *dc);
U0 DrawGrabMs(CDC *dc,I64 x,I64 y,Bool closed);
U0 DrawHexes();
U0 DrawHorizon(struct CDC *dc);
/*
U0 DrawIt(CTask *,CDC *dc);
U0 DrawIt(CTask *,CDC *dc2);
U0 DrawIt(CTask *task,CDC *);
U0 DrawIt(CTask *task,CDC *dc);
U0 DrawIt(struct CTask *,struct CDC *dc);
U0 DrawIt(struct CTask *task,struct CDC *dc);
*/
U0 DrawMan(CDC *dc);
U0 DrawMap();
U0 DrawMs(CDC *dc);
U0 DrawMyMs(CDC *dc,I64 x,I64 y);
U0 DrawObj(struct CDC *dc,struct Obj *o,F64 tt);
U0 DrawO(CDC *dc,I64 x,I64 y);
U0 DrawRivers();
U0 DrawRoads();
U0 DrawRunningWolf(CDC *dc,I64 i);
U0 DrawShadow(CTask *task);
U0 DrawSpring(CDC *dc,struct MyMass *tmpm,I64 x,I64 y);
U0 DrawTempoCtrl(struct CDC *dc,struct CCtrl *c);
U0 DrawTermBttn(CDC *dc,CCtrl *c);
U0 DrawTerrain();
U0 DrawUpperChairLift(CDC *dc);
U0 DrawViewAnglesCtrl(CDC *dc,CCtrl *c);
U0 DrawWaitMs(CDC *dc,I64 x,I64 y);
U0 DrawWinScroll(CDC *dc,CCtrl *c);
U0 DrawX(CDC *dc,I64 x,I64 y);
U0 DrvBlkDevDel(CBlkDev *bd);
U0 DrvsRelease();
U0 DskCacheAdd(CDrv *dv,U8 *buf,I64 blk,I64 cnt);
U0 DskCacheInit(I64 size_in_U8s);
U0 DskCacheInvalidate2(CDrv *dv);
U0 DskCacheInvalidate(CDrv *dv);
U0 DskCacheQueIns(CCacheBlk *tmpc);
U0 DskCacheQueRem(CCacheBlk *tmpc);
U0 DumpIn();
U0 DumpOut();
U0 DVDImageRead(U8 dvd_drv_let,U8 *out_name);
U0 DVDImageWriteTask(struct CDualBuf *d);
U0 EdCodeTools(CDoc *doc);
U0 EdGoToLine(CDoc *doc);
U0 EdInsBin(I64 bin_num,I64 type);
U0 EdInsBttn();
U0 EdInsCheckBox();
U0 EdInsColor();
U0 EdInsCursorMovement();
U0 EdInsData();
U0 EdInsHexEd();
U0 EdInsHtml();
U0 EdInsLink();
U0 EdInsLst();
U0 EdInsMacroMenu(Bool is_macro);
U0 EdInsPageSetting();
U0 EdInsSong();
U0 EdInsText();
U0 EdInsTree();
U0 EdInsWidgetWiz();
U0 EditShip();
U0 EdLiteUpdate(struct CLine *head,struct CLine *cur_line,I64 cur_col,I64 line_start_col);
U0 EDTransform(struct CDC *dc,I64 *x,I64 *y,I64 *z);
U0 EdUndoFilter(CDoc *doc);
U0 ElephantWalk();
U0 Exit();
U0 ExplosionDo(I64 x,I64 y,I64 scroll_y);
U0 ExplosionDraw(struct CDC *dc,struct Explosion *tmpe,I64 y);
U0 Explosion(struct MyMass *tmpm1,struct MyMass *tmpm2,F64 tons);
U0 ExtendedASCII();
U0 Extents();
U0 FancyWordSearch();
U0 FAT32Init(CDrv *dv);
U0 FClose(CFile *f);
U0 FESave(Bool pmt);
U0 FileLinkIns();
U0 FileRep(struct LogStruct *head,CDate dstart,CDate dend);
U0 FileTreeAdd(struct LinkStruct **_root,struct LogStruct *tmplg);
U0 FileTreeDel(struct LinkStruct *root);
U0 FileTreeTraverse(struct LinkStruct *root);
U0 FillU16Palindrome(CPalindromeU16 *dst,U16 w);
U0 FillU32Palindrome(CPalindromeU32 *dst,I64 d);
U0 FindNormal(U8 *bmp,struct Photon *tmpp);
U0 Fire();
U0 FireBullet();
U0 FireTask(I64);
U0 FlapBat();
U0 FMBurnISO(CDoc *doc);
U0 FMChgDsk(CDoc *doc);
U0 FMCopy(CDoc *doc);
U0 FMDelete(CDoc *doc);
U0 FMDelUncollapsedLst(struct CFMUncollapsedLst *tmpc);
U0 FMFinalScrnUpdate(CDC *dc);
U0 FMFmtDrv(CDoc *doc);
U0 FMMakeISO(CDoc *doc);
U0 FMMarkUncollapsed(CDoc *doc,struct CFMUncollapsedLst *tmpc,U8 *cur_entry,U8 *next_entry);
U0 FMMkDir(CDoc *doc);
U0 FMMountISO(CDoc *doc);
U0 FMRebuildDoc(CDoc **_doc,CDirEntry **_head,I64 mode);
U0 FMRename(CDoc *doc);
U0 FMUnmount(CDoc *doc);
//U0 Follow(struct CTask *,struct Peasant *tmpp);
U0 FontEd();
U0 FormDemo();
U0(*fp_old_final_scrn_update)(CDC *dc);
U0(*fp_update_ctrls)(CTask *task);
U0 FreshenBlog();
U0 FunDraw1(CDC *dc,F64(*f)(F64 t));
U0 FunDraw2(CDC *dc,F64(*f)(F64 t,F64 p),F64 T);
U0 FunSegCacheAdd(CHash *tmps,U8 *addr);
U0 Game();
U0 GetWord(U8 *dst,I64 x,I64 y,I64 dx,I64 dy);
U0 GodBitsIns(I64 num_bits,I64 n);
U0 GodDoodleBitsIns(I64 num_bits,I64 n);
U0 GodDoodleDraw(CTask *task,CDC *dc);
U0 GodDoodleHexIns(U8 *st);
U0 GodDoodleSmooth(I64 num);
U0 GodSong();
U0 GodVideoDigits(U8 *title,U8 *webpage,U8 *rnd,I64 digits,U8 *filename);
U0 GodVideoU32(U32 rand_u32,U8 *filename);
U0 GodWordBatch(struct CHexWordForm *gm,I64 radix,I64 digits);
U0 GrBitMapEdAddOutline(CDC *img,I64 width,CColorROPU32 color,CColorROPU32 bkcolor);
U0 GrBitMapEdEtch(CDC *img,I64 width,CColorROPU32 bkcolor);
U0 GrBitMapEdPrepPersistentDC(CDC *dc,I64 xx1,I64 yy1,CDC *img);
U0 GrBitMapEdTrimToExtents(CDC **_img,I64 *_xx1,I64 *_yy1,I64 *_xx2,I64 *_yy2,CColorROPU32 bkcolor);
U0 GrBlackLighting(CDC *dc,CD3I32 *,CD3I32 *,CD3I32 *,CColorROPU32);
U0 GrDemo();
U0 GrFixZoomScale();
U0 GridDemo();
U0 GridInit();
U0 GrInit1();
U0 GrInit2();
U0 GrInit4();
U0 GrPaletteColorSet(I64 color_num,CBGR48 bgr48);
U0 GrPaletteGet(CBGR48 *bgr48);
U0 GrPaletteIndicesSet();
U0 GrPaletteSet(CBGR48 *bgr48);
U0 GrScaleZoom(F64 scale);
U0 GrSetUpTables();
U0 GrUpdateScrn();
U0 GrUpdateTaskODEs(CTask *task);
U0 GrUpdateTasks();
U0 GrUpdateTaskWin(CTask *task);
U0 GrUpdateTextBG();
U0 GrUpdateTextFG();
U0 GrUpdateTextModeText();
U0 GrUpdateVGAGraphics();
U0 GrZoomInScrn();
U0 Halogen();
U0 Hanoi();
U0 HashFunSegFind(CHashTable *h,U8 *addr,Bool *_has_lower,U64 *_best,CHash **_res);
U0 HeapLogFree(U8 *addr);
U0 HeapLogMAlloc(U8 *addr);
U0 HexCentersCalc();
U0 HomeSet(U8 *dirname);
U0 HoseNew();
U0 ICAddEct(CIntermediateCode *tmpi,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,CICType t3,I64 r3,I64 d3,I64 op,I64 rip);
U0 ICAddSubEctEqu(CIntermediateCode *tmpi,U8 type_pointed_to,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,CICType t3,I64 r3,I64 d3,I64 op,I64 rip);
U0 ICAddSubEctImm(CIntermediateCode *tmpi,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,I64 d,I64 op,I64 rip);
U0 ICAndAnd(CIntermediateCode *tmpi,I64 rip);
U0 ICAndBranch(CIntermediateCode *tmpi,I64 rip,I64 is,U8 *buf,I64 rip2);
U0 ICAndEqu(CIntermediateCode *tmpi,I64 rip2);
U0 ICAssign(CIntermediateCode *tmpi,I64 rip);
U0 ICAssignPostIncDec(CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICBitOps(CIntermediateCode *tmpi,CICArg *arg1,CICArg *arg2,CIntermediateCode *tmpi2,I64 op,I64 op_imm,I64 rip);
U0 ICBrBitOps(CIntermediateCode *tmpi,I64 rip,I64 op,I64 op_imm,I64 is,U8 *buf,I64 rip2);
U0 ICCmpAndBranch(CIntermediateCode *tmpi,Bool has_res,I64 rip,I64 us,I64 is,I64 not_us,I64 not_is,U8 *buf,I64 rip2);
U0 ICCmp(CIntermediateCode *tmpi,I64 us,I64 is,I64 rip);
U0 ICCopyTemplate(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,Bool off_the_record,Bool dont_pushable,Bool dont_popable,I64 pos);
U0 ICDerefPostIncDec(CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICDiv(CIntermediateCode *tmpi,I64 rip);
U0 ICDivEqu(CIntermediateCode *tmpi,Bool is_mod,I64 rip);
U0 ICFAdd(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf,I64 rip);
U0 ICFCmpAndBranch(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 rip,I64 us,I64 not_us,U8 *buf,I64 rip2);
U0 ICFCmp(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICFCvt2(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 r1,CICType t2,I64 r2,I64 d2,Bool to_int,I64 rip);
U0 ICFCvt(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 r1,CICType t2,I64 r2,I64 d2,Bool to_int,I64 pos,I64 rip);
U0 ICFDiv(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf,I64 rip);
U0 ICFlagBranch(CIntermediateCode *tmpi,I64 rip,I64 is,U8 *buf);
U0 ICFMod(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 rip);
U0 ICFModEqu(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 rip);
U0 ICFMul(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf,I64 rip);
U0 ICFOp(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,U8 *buf2,I64 rip);
U0 ICFOpEqu(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,U8 *buf2,I64 rip);
U0 ICFPostIncDec(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICFPow(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf,I64 rip);
U0 ICFPreIncDec(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICFSub(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf,I64 rip);
U0 ICFTemplateFun(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICFUnaryMinus(CCmpCtrl *cc,CIntermediateCode *tmpi,U8 *buf2,I64 rip);
U0 ICLocalVarInit(CIntermediateCode *tmpi);
U0 ICMinMax(CIntermediateCode *tmpi,I64 op,I64 rip2);
U0 ICMod(CIntermediateCode *tmpi,I64 rip);
U0 ICModU64(CIntermediateCode *tmpi,I64 rip2);
U0 ICMul(CIntermediateCode *tmpi,I64 rip);
U0 ICMulEqu(CIntermediateCode *tmpi,I64 rip);
U0 ICNot(CIntermediateCode *tmpi,I64 rip);
U0 ICOpSizeRex(CIntermediateCode *tmpi,U8 b);
U0 ICOrEqu(CIntermediateCode *tmpi,I64 rip2);
U0 ICOrOr(CIntermediateCode *tmpi,I64 rip);
U0 ICPostIncDec(CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICPreIncDec(CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICQueInit(CIntermediateCode *tmpi,I64 rip2);
U0 ICQueIns(CIntermediateCode *tmpi,I64 rip2);
U0 ICQueInsRev(CIntermediateCode *tmpi,I64 rip2);
U0 ICQueRem(CIntermediateCode *tmpi,I64 rip2);
U0 ICRex(CIntermediateCode *tmpi,U8 b);
U0 ICShift(CIntermediateCode *tmpi,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,CICType t3,I64 r3,I64 d3,I64 us,I64 is,I64 rip);
U0 ICShiftEqu(CIntermediateCode *tmpi,U8 type_pointed_to,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,CICType t3,I64 r3,I64 d3,I64 us,I64 is,I64 rip);
U0 ICSqr(CIntermediateCode *tmpi,I64 op,I64 rip2);
U0 ICSub(CIntermediateCode *tmpi,CICType t1,I64 r1,I64 d1,CICType t2,I64 r2,I64 d2,CICType t3,I64 r3,I64 d3,I64 rip);
U0 ICSwap(CIntermediateCode *tmpi,I64 rip2);
U0 ICSwitch(CIntermediateCode *tmpi,I64 rip,Bool nobound,CCmpCtrl *cc,U8 *buf,I64 rip2);
U0 ICTestAndBranch(CIntermediateCode *tmpi,I64 rip,I64 is,U8 *buf,I64 rip2);
U0 ICToBool(CCmpCtrl *,CIntermediateCode *tmpi,I64 rip);
U0 ICToF64(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 rip);
U0 ICToI64(CCmpCtrl *cc,CIntermediateCode *tmpi,I64 rip);
U0 ICToUpper(CIntermediateCode *tmpi,I64 rip);
U0 ICU16(CIntermediateCode *tmpi,U16 w);
U0 ICU24(CIntermediateCode *tmpi,U32 d);
U0 ICU32(CIntermediateCode *tmpi,U32 d);
U0 ICU64(CIntermediateCode *tmpi,U64 q);
U0 ICU8(CIntermediateCode *tmpi,U8 b);
U0 ICUnaries(CIntermediateCode *tmpi,I64 op,I64 rip);
U0 ICXorEqu(CIntermediateCode *tmpi,I64 rip2);
U0 ICXorXor(CIntermediateCode *tmpi,I64 rip);
U0 IndexRep(struct LogStruct *head,CDate dstart,CDate dend);
U0 InGetStr(U8 *st);
//U0 Init();
U0 InitBushes();
//U0 Init(CDC *dc);
U0 InitDatabase();
U0 InitDefines();
U0 InitElevations();
U0 InitKey();
U0 InitMap();
//U0 Init(struct SpanAnimateStruct *a);
U0 InitTrack();
U0 InitUnits();
U0 InputFilterTask();
U0 InSetMsDemo();
U0 InsNote(struct CMakeSongSettings*mss,U8 *buf,I64 k,I64 *j);
U0 IntCore0TimerHndlr(CTask *);
U0 IntTest();
U0 Job1(I64);
U0 Job2(I64);
U0 Job3(I64);
U0 Job(CDoc *doc);
U0 JobCtrlInit(CJobCtrl *ctrl);
U0 JobDel(CJob *tmpc);
U0 JobQueDel(CJob *head);
U0 JukeSongPuppet(CTask *juke_task,I64 passes,I64 song_num,U8 *name);
U0 KCfgDel(struct CKCfg *c);
U0 KCfgOptions(struct CKCfg *c);
U0 KeepAway();
U0 KeyDownBitMapDemo();
U0 KillsChk(I64 x1,I64 y1,I64 player);
U0 Lattice();
U0 LeftClickCtrlBttn(CCtrl *c,I64,I64,Bool down);
U0 LeftClickCtrlPanel(struct CCtrl *c,I64 x,I64 y,Bool);
U0 LeftClickHWinScroll(CCtrl *c,I64 x,I64,Bool down);
U0 LeftClickSlider(CCtrl *c,I64 x,I64 y,Bool);
U0 LeftClickSlider(struct CCtrl *c,I64 x,I64 y,Bool);
U0 LeftClickTempo(struct CCtrl *c,I64 x,I64 y,Bool);
U0 LeftClickTermBttn(CCtrl *,I64,I64,Bool down);
U0 LeftClickViewAngles(CCtrl *c,I64 x,I64 y,Bool);
U0 LeftClickVWinScroll(CCtrl *c,I64,I64 y,Bool down);
U0 LexBackupLastChar(CCmpCtrl *cc);
U0 LexPopNoRestore(CCmpCtrl *cc);
U0 LexPopRestore(CCmpCtrl *cc);
U0 LexPush(CCmpCtrl *cc);
U0 LexPutPos(CCmpCtrl *cc);
U0 LexPutToken(CCmpCtrl *cc);
U0 LexSkipEol(CCmpCtrl *cc);
U0 Life();
U0 Lighting(CDC *dc,CD3I32 *ls,CD3I32 *poly,I64 color);
U0 LightTable();
U0 LineRep2(CDoc *doc,CDirEntry *tmpde);
U0 LinkedLstDel(U8 **_lst);
U0 LinkTreeAdd(struct LinkStruct **_root,struct LogStruct *tmplg);
U0 LinkTreeDel(struct LinkStruct *root);
U0 LinkTreeTraverse(struct LinkStruct *root);
U0 LoadDocDefines();
U0 LoadOneImport(U8 **_src,U8 *module_base,I64 ld_flags);
U0 LoadPass1(U8 *src,U8 *module_base,I64 ld_flags);
U0 LoadPass2(U8 *src,U8 *module_base,I64);
U0 LockedInc();
U0 LogLstDel(struct LogStruct *head);
U0 LogScrambleDemo();
U0 LogScrambleFile(U8 *name);
//U0LogStructDel(struct LogStruct *tmplg);
U0 LowPassFilterDemo();
U0 LTMenuSet(I64 mode);
U0 Main();
U0 MakeAll();
U0 MakeMyISO(U8 *_out_iso_filename);
U0 MakeRivers();
U0 MakeRoads();
U0 MakeTerrain(U8 color,I64 cnt,I64 clus_lo,I64 clus_hi);
U0 ManageShots();
U0 ManDie(struct Unit *tmpu,Bool by_human);
U0 MapFileWrite(CHashTable *h,U8 *map_name,U8 drv_let);
U0 MassSpringDemo();
U0 Mat4x4MulXYZ(I64 *r,I64 *_x,I64 *_y,I64 *_z);
U0 Maze();
U0 MDCorrect(struct ManDefineStruct *md);
U0 MDInit(struct ManDefineStruct *md);
U0 Mem32DevFree(U8 *base);
U0 Mem32DevInit();
U0 Mem64DevFree(U8 *base,I64 pages1Gig);
U0 MemberAdd(CCmpCtrl *cc,CMemberLst *tmpm,CHashClass *tmpc,I64 mode);
U0 MemBIOSRep();
U0 MemDemo();
U0 MemPageRep();
U0 MenFight(I64 phase_group);
U0 MenMove(I64 phase_group);
U0 MenuBttn();
U0 MenuPop();
U0 MenuSprite();
U0 Merge2(CDirEntry *tmpde1,CDirEntry *tmpde2,I64 *_fuf_flags,I64 *_df_flags);
U0 MGCircle(I64 x,I64 y,F64 r);
U0 MGHLine(I64 x1,I64 x2,I64 y);
U0 MGInit();
U0 MGLine(I64 x1,I64 y1,I64 x2,I64 y2);
U0 MGPlot(I64 x,I64 y);
U0 MGUpdate();
U0 MiniGrLibDemo();
U0 Mirror(struct Photon *tmpp);
U0 MissileDel(struct Missile *tmpmi);
U0 MissileNew(struct Ship *tmpsp,I64 n);
U0 Models();
U0 Morse();
U0 MorseTable();
U0 Mouse();
U0 MoveDisks(I64 src_pole,I64 dst_pole,I64 num);
U0 MoveMass(struct MyMass *tmpm,I64 x,I64 y);
U0 MoveNozzleTaskX(I64 sign);
U0 MoveNozzleTaskY(I64 sign);
U0 MoveTask(I64);
U0 MPAdd();
//U0 MPstruct AnimateTask(I64);
U0 MPCPURep(struct CCPURep *cr);
//U0 MPDoPanels(struct CTask *task);
//U0 MPDrawIt(struct CTask *task);
//U0 MPDrawIt(struct CTask *task,struct CDC *dc);
U0 MPEnd();
U0 MPLockedInc(I64);
U0 MPMenDraw(struct CDC *dc2);
U0 MPPrintDemo();
U0 MPRoutine(CDoc *doc);
U0 MPUnlockedInc(I64);
U0 MPUpdateWin(struct CDC *dc2);
U0 MsgLoop();
U0 MsHardSet(I64 x,I64 y,I64 z,I64 l,I64 r);
U0 MsUpdate(I64 x,I64 y,I64 z,Bool l,Bool r);
//U0 MyDerivative(CMathODE *,F64,COrder2D3 *,COrder2D3 *);
//U0 MyDerivative(CMathODE *,F64,F64 *state,F64 *DstateDt);
//U0 MyDerivative(CMathODE *ode,F64,COrder2D3 *,COrder2D3 *);
//U0 MyDerivative(CMathODE *ode,F64 t,COrder2D3 *,COrder2D3 *);
//U0 MyDerivative(CMathODE *ode,F64 t,COrder2D3 *state,COrder2D3 *DstateDt);
//U0 MyDerivative(struct CMathODE *ode,F64,struct COrder2D3 *,struct COrder2D3 *);
U0 MyGame();
U0 MyRead(U8 *filename);
U0 MySleep();
U0 NetOfDots();
U0 NowDateTimeStruct(CDateStruct *_ds);
U0 NullCase();
U0 NullSpring(struct MySpring *tmps,F64 scale);
U0 NullSprings();
U0 NumBible();
U0 ODEsUpdate(CTask *task);
U0 OffsetDemo1();
U0 OffsetDemo2();
U0 OnceDemo();
U0 OptFixSizeOf(CIntermediateCode *tmpi1,CIntermediateCode *tmpi_push,CHashClass *tmpcc);
U0 OptPass3(CCmpCtrl *cc,struct COptReg*reg_offsets);
U0 OptPass4(CCmpCtrl *cc,struct COptReg*reg_offsets,I64 *_type);
U0 OptPass5(CCmpCtrl *cc);
U0 OptPass6(CCmpCtrl *cc);
U0 OptPass6Lag(CCmpCtrl *cc,CPrsStk *ps,CIntermediateCode *tmpi,I64 *_stk_ptr,I64 reg_stk_size,I64 *_clobbered_reg_mask);
U0 OptSetNOP1(CIntermediateCode *tmpi);
U0 OutLine();
U0 OutStr(U8 *ptr,U8 **_buf,U8 **_dst,I64 len,I64 flags);
U0 PaletteDemo();
U0 PaletteSetStd();
U0 PanText();
U0 PCILookUpDevs();
U0 PCILookUpSingle(CDoc *doc,I64 m,I64 d,U8 **_vendor,U8 **_dev);
U0 PCIRep();
U0 PDAnswer(U8 *a,I64 len);
U0 PDNormalize();
U0 PhaseNew();
U0 PhoneNumWords(U8 *num);
U0 Pick();
U0 Pick3D();
//U0 PlaceMass(I64 x,I64 y);
U0 PlaceShip(I64 type);
//U0 PlaceSpring(struct MyMass *tmpm1,struct MyMass *tmpm2);
U0 PlayerDirect();
U0 PlayerIndirect();
U0 PlayerMove();
U0 PlayerPick(U8 *dirname,I64 player);
U0 PlayShip();
U0 PlotTrajectory(CTask *parent);
U0 PlotXY(I64 x,I64 y);
U0 PNWDemo();
U0 PObjDel(struct PickFrame *pf,struct PObj *tmpo);
U0 PoleZeros();
U0 PopUpJiffiesCallBack(I64 i);
U0 PortNop();
U0 PostCleanUp();
U0 PredatorPrey();
U0 PreInit();
U0 PrimesJob(I64 i);
U0 PrintDigit(U8 ch);
U0 PrintErr(U8 *fmt,...);
U0 PrintPattern(U8 *st);
U0 Print(U8 *fmt,...);
U0 PrintWarn(U8 *fmt,...);
U0 ProfTimerInt(CTask *task);
U0 PromptDemo();
U0 PrsArrayDims(CCmpCtrl *cc,I64 mode,CArrayDim *dim);
U0 PrsAsmArg(CCmpCtrl *cc,CAsmArg *arg,Bool rel);
U0 PrsAsmBlk(CCmpCtrl *cc,I64 cmp_flags);
U0 PrsAsmDefine(CCmpCtrl *cc,I64 U8_cnt);
U0 PrsBinFile(CCmpCtrl *cc);
U0 PrsDotDotDot(CCmpCtrl *cc,CHashFun *tmpf,I64 _reg);
U0 PrsDoWhile(CCmpCtrl *cc,I64 try_cnt);
U0 PrsExpression2(CCmpCtrl *cc,I64 *_max_prec,CPrsStk *ps);
U0 PrsFor(CCmpCtrl *cc,I64 try_cnt);
U0 PrsFun(CCmpCtrl *cc,CHashClass *tmp_return,U8 *name,I64 fsp_flags);
U0 PrsGlblInit(CCmpCtrl *cc,CHashGlblVar *tmpg,I64 pass);
U0 PrsGlblVarLst(CCmpCtrl *cc,I64 saved_mode,CHashClass *saved_tmpc,I64 saved_val,I64 fsp_flags);
U0 PrsIf(CCmpCtrl *cc,I64 try_cnt,CCodeMisc *lb_break);
U0 PrsNoWarn(CCmpCtrl *cc);
U0 PrsPopDeref(CPrsStk *ps);
U0 PrsPush2(CPrsStk *ps,I64 val);
U0 PrsPush(CPrsStk *ps,I64 val);
U0 PrsSingleLogFile(struct LogStruct *head,U8 *name,CDate *_dstart,CDate *_dend);
U0 PrsStaticInit(CCmpCtrl *cc,CMemberLst *tmpm,I64 pass);
U0 PrsStreamBlk(CCmpCtrl *cc);
U0 PrsSwitch(CCmpCtrl *cc,I64 try_cnt);
U0 PrsTryBlk(CCmpCtrl *cc,I64 try_cnt);
U0 PrsVarInit2(CCmpCtrl *cc,U8 **_dst,CHashClass *tmpc,CArrayDim *tmpad,U8 *data_addr_rip,U8 **_base,Bool data_heap,I64 pass);
U0 PrsVarInit(CCmpCtrl *cc,U8 **_dst,CHashClass *tmpc,CArrayDim *tmpad,U8 *data_addr_rip,U8 **_base,Bool data_heap,I64 pass);
U0 PrsWhile(CCmpCtrl *cc,I64 try_cnt);
U0 PsmDownKey(I64 x,I64 y);
U0 PsmLeftClick(I64 x,I64 y);
U0 PsmLeftClickPickMeterBox(I64 top,I64 bottom);
U0 PsmLeftClickPickNoteBox(I64 duration);
U0 PsmLeftClickStaffBox(I64 x,I64 y);
U0 PsmLeftClickStaffPtr(I64 x,I64 y);
U0 PsmPopMode();
U0 PsmPushMode(I64 psm_octave);
U0 PsmRightClick(I64 x,I64 y);
U0 PsmUpKey(I64 x,I64 y);
U0 PullDownMenuDemo();
U0 PutChars(U64 ch);
U0 PutFactors(I64 n);
U0 PutS(U8 *st);
U0 QSort2a(U8 **base,I64 num,I64(*fp_compare)(U8 **_e1,U8 **_e2));
U0 QSort2b(U8 *base,I64 num,I64 width,I64(*fp_compare)(U8 *e1,U8 *e2),U8 *tmp);
U0 QSortI64(I64 *base,I64 num,I64(*fp_compare)(I64 e1,I64 e2));
U0 QSort(U8 *base,I64 num,I64 width,I64(*fp_compare)(U8 *e1,U8 *e2));
U0 RadixSort();
U0 RainDrops();
U0 RandDemo();
U0 RandomBurst();
U0 RandPts();
U0 RankOut(I64 i);
U0 RawHide();
U0 RawPutChar(I64 ch);
U0 RayBurst(I64 x1,I64 y1,I64 x2,I64 y2);
U0 RCache(CDrv *dv,U8 **_buf,I64 *_blk,I64 *_cnt);
U0 ReadAcct();
U0 RedrawGate();
U0 RedSeaFreeFreeLst(CDrv *dv);
U0 RedSeaFreeLstBuild(CDrv *dv);
U0 RedSeaInit(CDrv *dv);
U0 RedSeaISO9660Stage1(U8 *iso_filename,U8 *stage2_filename);
U0 RedSeaISO9660(U8 *iso_filename,U8 drv_let);
U0 RegOneTimePopUp(I64 flag_num,U8 *msg);
U0 ReInit();
U0 Rev(U8 *in_name,U8 *out_name);
U0 RiverDel();
U0 RiverDropsDel();
U0 RiverDropsDraw(struct CDC *dc,I64 cx,I64 cy);
//U0 RiverDropsNext(struct CTask *mem_task);
U0 RiverMake();
U0 RiverNew();
U0 Rocket();
U0 RocketScience();
U0 RotateMan(F64 d);
U0 RotateTank();
U0 RowCol2XY(F64 *_x,F64 *_y,I64 row,I64 col);
U0 S2Circle(I64 *_x,I64 *_y);
//U0 S2W(F64 sx,F64 sy,F64 *_wx,F64 *_wy);
//U0 S2W(I64 *_x,I64 *_y);
U0 SafePutChar(U8 ch);
U0 Scrn2Clip(I64);
U0 ScrnCodes();
U0 ScrollBars();
U0 ScrollTaskX(I64 sign);
U0 ScrollTaskY(I64 sign);
U0 Search(I64 dx,I64 dy);
U0 SerializeTree();
U0 SetDisksRestXY();
U0 SetMenu();
U0 Shadow();
U0 ShipDel(struct Ship *tmpsp);
U0 Shoot(struct Obj *o);
U0 ShowTree(struct CDC *dc, struct Node *tmpn,I64 *_node_x,I64 *_tree_x,I64 y);
U0 ShowWorkingDir();
U0 SimpleWordSearch();
U0 SliderDel(CCtrl *c);
U0 SliderDel(struct CCtrl *c);
U0 SMTextFamily(I64 eletype,CDoc *doc,CDocEntry *doc_ce,struct CSprite *head,CDC *dc,I64 x,I64 y,I64 arg1,I64 arg2,CColorROPU32 color,I64 *_cur_elem_num,I64 old_de_flags);
U0 SndMathDemo();
U0 SndTaskEndCB();
U0 SnellsLaw(struct Photon *tmpp,I64 last,I64 next);
U0 SolveMaze(I64 x,I64 y);
U0 Song();
U0 SongPuppet(CTask *task,I64 passes);
U0 SongTask(I64);
U0 Sort();
U0 SoundEffectEndTaskCB();
U0 SoundEffectTask(struct CSoundEffectFrame *ns);
U0 Span();
U0 SpanBridge1Init(CMathODE *);
U0 SpanDel(CMathODE *ode);
U0 SpeedLineDemo();
U0 SpriteCtrlPtsDraw(CDC *dc,struct CEdSprite *head);
U0 SpriteCtrlPtsMove(struct CEdSprite *head,I64 dx,I64 dy);
U0 SpriteElem2Code(CDoc *doc,struct CSprite *tmpg);
U0 SpritePlot();
U0 SpritePlot3D();
U0 SpritePtQueNew(U8 *elems,I64 x,I64 y,struct CEdSprite *head);
U0 SpritePut();
U0 SpritePutExt();
U0 SpriteRawDemo();
U0 SpriteScrnInit(CDC *dc,I64,I64);
U0 SpriteSelAll(U8 *elems,Bool val);
U0 SpriteSideBarPickNew(CDoc *doc,struct CSprite *head,I64 old_num);
U0 SpriteSideBarTask2(CTask *grand_parent);
U0 SpriteSideBarTask(CTask *parent,struct CSprite **_head,I64 *_cur_elem_num);
U0 SpriteText(U8 *elems);
U0 SPutChar(U8 **_dst,U8 ch,U8 **_buf);
U0 Spy();
U0 SpyCallerRep(CTask *task);
U0 SpyStkRep(CTask *task);
U0 SquadronIns(struct Obj *o,struct Obj *pred);
U0 SquadronRem(struct Obj *o);
U0 Squirt();
U0 SrcExample();
U0 SrvStartUp();
U0 Stadium();
U0 StadiumGen();
U0 StartUpTasks();
U0 Steps(struct State *s);
U0 StkGrowDemo();
U0 StrPrintFunSeg(U8 *buf,I64 addr,I64 field_len,I64 flags);
U0 Strut();
U0 SubSwitch();
U0 SuggestSpellingDemo();
U0 SunMoon();
U0 SymmetryDemo();
U0 SysBadFree(I64 *ptr);
U0 SysBadMAlloc(I64 *ptr);
U0 SysMacroStripKey(CJob *macro_head,I64 arg1,I64 arg2);
U0 SysSymImportsResolve(U8 *st_ptr,I64 ld_flags);
U0 TakeTurn(I64 player);
U0 Talons();
U0 TaskEndCB();
U0 TaskRep();
U0 TaskRepTask(CTask *task,I64 indent);
U0 TemplateCtrlSlider(CDoc *doc);
U0 TempoDel(struct CCtrl *c);
U0 TheDead();
U0 TicTacToe();
U0 TimeEntriesDel(struct TimeEntry *header);
U0 TimeFileRead(struct TimeEntry *header);
U0 TimeFileWrite(struct TimeEntry *header);
U0 TimeIns();
U0 Titanium();
U0 Tmp();
U0 TOSBookLines(U8 *book_filename,I64 book_lines,U8 *st,I64 num_lines,I64 radix,Bool modulo,Bool plus_one);
U0 TOSDbgDistro1();
U0 TOSDbgDistro2();
U0 TOSInit();
U0 TOSPreRegen();
U0 TOSProgress(U8 *st);
U0 TOSRegen();
U0 TOSRegen2();
U0 TOSTheme();
U0 ToTheFront();
U0 Toward(I64 *_row,I64 *_col,I64 direction);
U0 TreeAdd(struct Node **_root,struct Node *tmpn);
U0 TreeCheckers();
U0 TreeCommonAncestor();
U0 TreeCommonAncestorFind(struct Node *root);
U0 TreeDemo();
U0 TreeNew();
U0 TreeSub(CDoc *doc,CDirEntry *tmpde);
U0 TurnNew();
U0 TurtleInit(struct Turtle *t);
U0 TurtleMicroMove(struct Turtle *t,F64 dt);
U0 TurtleMove(struct CDC *dc,struct Turtle *t,CColorROPU16 edge,CColorROPU16 middle);
U0 TurtlePlot(struct CDC *dc,struct Turtle *t,CColorROPU16 edge,CColorROPU16 middle);
U0 TXTPutS(CDoc *doc,U8 *st,I64 *_col);
U0 UAsmHashLoad();
U0 UncachedAliasAlloc();
U0 UndefinedDefine(U8 *dname);
U0 UndoIt();
//U0 UnitDraw(CDC *dc,Unit *tmpu,I64 x,I64 y,F64 f);
//U0 UnitMoveAnimation(Unit *tmpu,I64 r,I64 c,I64 facing);
U0 UnitsDraw(CDC *dc);
U0 UnlockedInc();
U0 UnusedDefineScan();
U0 UnusedSpaceRep();
//U0 UpdateCurBase(struct CTask *task,struct CDC *dc);
U0 UpdateDerivedCtrlPanelCtrl(struct CCtrl *c);
U0 UpdateDerivedCtrlSlider(CCtrl *c);
U0 UpdateDerivedCtrlSlider(struct CCtrl *c);
U0 UpdateDerivedTempoCtrl(struct CCtrl *c);
U0 UpdateDerivedViewAnglesCtrl(CCtrl *c);
U0 UpdateGlblTask(I64);
U0 UpdateRoad();
U0 UserChk();
U0 UserStartUp();
U0 UserTaskCont();
U0 Varoom();
U0 VGAFlush();
U0 ViewPlayerSet(I8 p);
U0 VocabQuiz();
U0 VRMerge(I64 player);
U0 VRSetUp(I64 player);
U0 VRTransform(struct CDC *dc,I64 *x,I64 *y,I64 *z);
U0 W2S(F64 wx,F64 wy,F64 *_sx,F64 *_sy);
U0 WallPaper(CTask *_task);
U0 WallPaperInit();
U0 WaterFowl();
U0 WebLogRep(U8 *mask,U8 *output_filename);
U0 WebLogScramble(U8 *files_find_mask);
U0 Wenceslas();
U0 Whap();
U0 WheelChangeWinScroll(CCtrl *c,I64 delta);
U0 WinDerivedScrollValsUpdate(CCtrl *c);
U0 WinDerivedValsUpdate(CTask *task);
U0 WinFinalUpdate(CDC *dc);
U0 WinMsUpdate();
U0 WinScrollNull(CTask *task,CD3I64 *s);
U0 WinScrollRestore(CTask *task,CD3I64 *s);
U0 WinScrollsInit(CTask *task);
U0 WinZBufFill(CTask *task);
U0 WinZBufUpdate();
U0 WordSearch();
U0 WrapAngles();
U0 WriteAcct();
U0 XTalk(CTask *task,U8 *fmt,...);
U0 XY2RowCol(I64 *_row,I64 *_col,F64 x,F64 y);
U0 Zing();
U0 ZoneOut();
U0 Zoom(F64 d);
U0 ZOTransform(struct CDC *dc,I64 *x,I64 *y,I64 *z);
U16 EndianU16(U16 d);
U16 RandU16();
U32 *DocHighlight(CDocEntry *doc_e,U8 *src,I64 len,I64 _tmp_u32_attr);
U32 EndianU32(U32 d);
U32 RandU32();
U64 CeilU64(U64 num,U64 to);
U64 FloorU64(U64 num,U64 to);
U64 RandU64();
U8 *ACDNextEntry(U8 **_ptr);
U8 *ACDSortWords(U8 *start,I64 size,I64 word_cnt);
//U8 *Ball2struct CSprite();
U8 *BallGen();
U8 *CatPrint(U8 *_dst,U8 *fmt,...);
U8 *CmdLinePmt();
U8 *CurTimeCB(CDoc *,CDocEntry *,CTask *mem_task);
U8 *DC2Sprite(CDC *tmpb);
U8 *DefineSub(I64 sub,U8 *dname);
U8 *Define(U8 *dname);
U8 *Doc2PlainText(CDoc *doc,CDocEntry *doc_e);
U8 *DocEntryLink(CDoc *doc,CDocEntry *doc_e);
U8 *EdAutoSaveCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdDollarCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdDollarTypeCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdFilterCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdMoreCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdOverStrikeCB(CDoc *,CDocEntry *doc_e,CTask *mem_task);
U8 *EdSprite(I64 bin_num);
U8 *EdSpriteLink(Bool *_pop_up,U8 **_html_link);
U8 *ExtDft(U8 *filename,U8 *extension);
U8 *FileExtDot(U8 *src);
U8 *FunSegCacheFind(U8 *addr,I64 *_offset);
U8 *GodSongStr();
U8 *GrBitMap4ToBitMap8(U8 *dst,U8 *src,I64 src_size,I64 bkcolor);
U8 *KbdMsTimeCB(CDoc *,CDocEntry *,CTask *mem_task);
U8 *LexPutLine(CCmpCtrl *cc,U8 *start);
//U8 *Man2struct CSprite();
U8 *ManGen();
U8 *Mem32DevAlloc(I64 size,I64 alignment);
U8 *Mem64DevAlloc(I64 *_pages1Gig);
U8 *MorseTimes(CDoc *,CDocEntry *,CTask *mem_task);
U8 Mount2(U8 boot_drv_let,CDoc *_doc,Bool _caller_is_prtdsk);
U8 *MPrintDate(CDate cdt);
U8 *MPrintq(U8 *ptr,I64 flags);
U8 *MPrintQ(U8 *ptr,I64 flags);
U8 *MPrintTime(CDate cdt);
U8 *MStrPrint(U8 *fmt,...);
U8 *MusicSetMeter(U8 *st);
U8 *MusicSetNoteLen(U8 *st);
U8 *MusicSetOctave(U8 *st);
U8 PsmCvtDuration(F64 d);
U8 *RandVocabWord();
U8 *ScaleIndent(U8 *src,F64 indent_scale_factor);
U8 *SpriteElem2Summary(struct CSprite *tmpg);
U8 *SpriteTransform(U8 *elems,I64 *r);
U8 *StrPrintJoin(U8 *dst,U8 *fmt,I64 argc,I64 *argv);
U8 *StrPrint(U8 *dst,U8 *fmt,...);
U8 *SuggestMatchForm(U8 *src);
U8 *SysMacro2Str(CJob *macro_head);
U8 *Tabs2Spaces(U8 *src);
U8 *TimeStampCB(CDoc *,CDocEntry *,CTask *mem_task);
U8 TOSGetDrv();
U8 *tSCB(CDoc *,CDocEntry *,CTask *mem_task);
//Unit *UnitFind(I64 row,I64 col);
F64 tS();
I64 SysTimerRead();
I64 HPET();
I64 YearStartDate(I64 year);
I64 LastDayOfYear(I64 i);
I64 LastDayOfMon(I64 i);
I64 FirstDayOfYear(I64 i);
I64 FirstDayOfMon(I64 i);
I64 DayOfWeek(I64 i);
CDate Struct2Date(CDateStruct *_ds);
CDate Now();
U8 *MPrintTime(CDate cdt);
U8 *MPrintDate(CDate cdt);
U0 Date2Struct(CDateStruct *_ds,CDate cdt);
U0 WinDerivedValsUpdate(CTask *task);
//U0(*fp_update_ctrls)(CTask *task);
U0 SleepUntil(I64 wake_jiffy);
U0 Sleep(I64 mS);
I64 TimeCal();
U0 PortNop();
U0 Busy(I64 S);
U0 Yield();
U0 UserCmdLine();
Bool TaskValidate(CTask *task);
U0 TaskQueRem(CTask *task);
U0 TaskKillDying();
U0 TaskEndNow();
U0 TaskContextRestore();
U0 Exit();
U0 SndRst();
F64 Ona2Freq(I64 ona);
Bool Mute(Bool val);
Bool IsMute();
I8 Freq2Ona(F64 freq);
U8 *IntEntryGet(I64 irq);
U0 PCIWriteU8(I64 bus,I64 dev,I64 fun,I64 rg,I64 val);
U0 PCIWriteU32(I64 bus,I64 dev,I64 fun,I64 rg,I64 val);
U0 PCIWriteU16(I64 bus,I64 dev,I64 fun,I64 rg,I64 val);
U8 PCIReadU8(I64 bus,I64 dev,I64 fun,I64 rg);
U32 PCIReadU32(I64 bus,I64 dev,I64 fun,I64 rg);
U16 PCIReadU16(I64 bus,I64 dev,I64 fun,I64 rg);
I64 PCIClassFind(I64 class_code,I64 n);
U0 MPHalt();
U0 MPNMInt();
U0 MPIntAll(U8 num);
U0 CoreAPSethTask();
U0 Core0StartMP();
U0 MsUpdate(I64 x,I64 y,I64 z,Bool l,Bool r);
U0 MsInit();
U0 GridInit();
U0 QSortI64(I64 *base,I64 num,I64(*fp_compare)(I64 e1,I64 e2));
U0 QSort(U8 *base,I64 num,I64 width,I64(*fp_compare)(U8 *e1,U8 *e2));
U32 EndianU32(U32 d);
U16 EndianU16(U16 d);
I64 EndianI64(I64 d);
U0 InputFilterTask();
I64 *MemPageTable(U8 *a);
U0 HeapCtrlDel(CHeapCtrl *hc);
I64 MSize2(U8 *src);
I64 MSize(U8 *src);
CHeapCtrl *MHeapCtrl(U8 *src);
U0 Free(U8 *addr);
U0 BlkPoolInit(CBlkPool *bp,I64 pags);
U0 BlkPoolAdd(CBlkPool *bp,CMemBlk *m,I64 pags);
U8 *AMAllocIdent(U8 *src);
U8 *AMAlloc(I64 size);
U8 *ACAlloc(I64 size);
I64 RoundI64(I64 num,I64 to);
U64 RandU64();
U32 RandU32();
U16 RandU16();
I64 RandI64();
I32 RandI32();
I16 RandI16();
F64 Rand();
F64 Pow10I64(I64 i);
F64 Min(F64 n1,F64 n2);
F64 Max(F64 n1,F64 n2);
U64 FloorU64(U64 num,U64 to);
I64 FloorI64(I64 num,I64 to);
F64 Clamp(F64 d,F64 lo,F64 hi);
U64 CeilU64(U64 num,U64 to);
I64 CeilI64(I64 num,I64 to);
Bool YorN();
I64 ScanChar();
I64 PressAKey();
Bool MsHardDrvrInstall();
U0 KbdTypeMatic(U8 delay);
I64 KbdMsgsQue();
U0 KbdMsInit();
U0 KbdMsHndlr(Bool poll_kbd,Bool poll_ms);
I64 KbdMsEvtTime();
U0 KbdInit();
Bool AreYouSure();
U0 KeyDevRem(CKeyDevEntry *tmpk);
U0 KeyDescSet(U8 *fmt,...);
CJob *TaskMsg(CTask *srv,CTask *master,I64 msg_code,I64 arg1,I64 arg2,I64 flags);
U0 XTalkWait(CTask *task,U8 *fmt,...);
U0 XTalkStrWait(CTask *task,U8 *fmt,...);
U0 XTalkStr(CTask *task,U8 *fmt,...);
U0 XTalk(CTask *task,U8 *fmt,...);
U0 InStr(U8 *fmt,...);
U0 InFile(U8 *filename);
U0 In(U8 *fmt,...);
CJob *TaskText(CTask *srv,CTask *master,U8 *data,I64 flags);
I64 PopUpPrint(U8 *fmt,...);
I64 Adam(U8 *fmt,...);
U0 UserTaskCont();
CJob *TaskExe(CTask *srv,CTask *master,U8 *data,I64 flags);
U0 SrvTaskCont();
U0 SrvCmdLine();
U0 JobDel(CJob *tmpc);
I64 ExeCmdLine(CCmpCtrl *cc);
U0 AdamLog(U8 *fmt,...);
U0 AdamErr(U8 *fmt,...);
Bool DrvEnable(U8 drv_let,Bool val);
CATARep *ATARepFind(CATARep *haystack_head,I64 needle_num);
U0 DrvRep();
U0 Help();
I64 HashDefineLstAdd(U8 *dname,I64 type,CHashTable *table);
I64 HashLstAdd(U8 *lst,I64 type,CHashTable *table);
I64 HashVal(CHash *tmph);
I64 HashTypeNum(CHash *tmph);
I64 HashTablePurge(CHashTable *table);
U0 HashTableDel(CHashTable *table);
U0 HashDel(CHashSrcSym *tmph);
I64 HashStr(U8 *st);
CHash **HashBucketFind(U8 *needle_str,CHashTable *haystack_table);
U0 HashAddAfter(CHash *tmph,CHash *pred,CHashTable *table);
U0 HashAdd(CHash *tmph,CHashTable *table);
CColorROPU32 Str2ColorU32(U8 *st);
CColorROPU16 Str2ColorU16(U8 *st);
U8 *Color2Str(U8 *buf,CColorROPU32 c);
U0(*fp_set_std_palette)();
I64 MountIDEAuto();
U0 DskCacheInvalidate(CDrv *dv);
U0 DskCacheInit(I64 size_in_U8s);
U0 ATAWriteBlks(CBlkDev *bd,U8 *buf,I64 blk,I64 cnt);
U0 ATAReadBlks(CBlkDev *bd,U8 *buf,I64 blk,I64 cnt);
I64 ATAProbe(I64 base0,I64 base1,I64 unit);
Bool ATAPIStartStop(CBlkDev *bd,F64 timeout,Bool start);
CBlkDev *ATAMount(U8 first_drv_let,I64 type,I64 base0,I64 base1,I64 unit);
CATARep *ATAIDDrvs(CATARep *head,CATARep **_ata_drv,CATARep **_atapi_drv);
U0 DirTreeDel2(CDirEntry *tmpde);
U0 DirTreeDel(CDirEntry *tmpde);
U0 DirEntryDel2(CDirEntry *tmpde);
U0 DirEntryDel(CDirEntry *tmpde);
U0 RedSeaFreeClus(CDrv *dv,I64 c,I64 cnt);
I64 Name2ParentDirClus(CDrv *dv,U8 *dirname);
I64 Name2DirClus(CDrv *dv,U8 *dirname);
I64 Let2BlkDevType(U8 drv_let);
U0 FAT32FreeClus(CDrv *dv,I64 c);
U0 DrvsRelease();
CDrv *DrvMakeFreeSlot(U8 drv_let);
Bool DrvLock(CDrv *dv);
U0 DrvDel(CDrv *dv);
Bool CopySingle(U8 *f1,U8 *f2);
I64 ClusWrite(CDrv *dv,U8 *buf,I64 c,I64 cnt);
I64 ClusRead(CDrv *dv,U8 *buf,I64 c,I64 cnt);
I64 ClusBlkWrite(CDrv *dv,U8 *buf,I64 c,I64 blks);
I64 ClusBlkRead(CDrv *dv,U8 *buf,I64 c,I64 blks);
I64 Clus2Blk(CDrv *dv,I64 c);
U0 BlkWriteZero(CDrv *dv,I64 blk,I64 cnt);
Bool BlkWrite(CDrv *dv,U8 *buf,I64 blk,I64 cnt);
Bool BlkRead(CDrv *dv,U8 *buf,I64 blk,I64 cnt);
U0 BlkDevsRelease();
CBlkDev *BlkDevNextFreeSlot(U8 first_drv_let,I64 type);
Bool BlkDevLock(CBlkDev *bd);
U0 BlkDevDel(CBlkDev *bd);
U8 *FileNameTmpTxt();
U8 *ToggleZorNotZ(U8 *name);
U0 ToFileLine(U8 *_fl_file_line,U8 **_filename,I64 *_linenum);
Bool IsDotZ(U8 *filename);
Bool IsDotC(U8 *filename);
Bool IsDir(U8 *dir_name);
Bool FileNameChk(U8 *filename);
U8 *FileExtDot(U8 *src);
U8 *ExtDft(U8 *filename,U8 *extension);
U8 *ExtChg(U8 *filename,U8 *extension);
U8 *DirNameAbs(U8 *dirname);
CDirEntry *Cd2DirEntry(CDirEntry *tmpde,U8 *abs_name);
Bool DrvMap(U8 drv_let,CDrv *dv);
U0 HomeSet(U8 *dirname);
Bool Drv(U8 drv_let);
I64 FSize(CFile *f);
U0 DVDImageRead(U8 dvd_drv_let,U8 *out_name);
U0 SysUntry();
U0 SysTry(U8 *start_label,U8 *skip_label);
U0 Break();
U0 Mem64DevFree(U8 *base,I64 pages1Gig);
U8 *Mem64DevAlloc(I64 *_pages1Gig);
U0 Mem32DevFree(U8 *base);
U8 *Mem32DevAlloc(I64 size,I64 alignment);
U8 *DefineSub(I64 sub,U8 *dname);
CHashDefineStr *DefineLstLoad(U8 *dname,U8 *lst);
I64 DefineCnt(U8 *dname);
U0 DefinePrint(U8 *dname,U8 *src,...);
CHashDefineStr *DefineLoad(U8 *dname,U8 *st);
U8 *Define(U8 *dname);
U0 VGAFlush();
U0 RawPutChar(I64 ch);
Bool Raw(Bool val);
Bool IsRaw();
CHash *FunSegFind(U8 *addr,I64 *_offset);
I64 *TaskRegAddr(CTask *task,I64 reg_num);
Bool IsDbgMode();
U0 FixSet(U8 *filename,I64 line);
Bool DbgMode(Bool val);
Bool SysDbg(Bool val);
Bool SingleUser(Bool val);
Bool IsSysDbg();
Bool IsSingleUser();
Bool ChkPtr(U8 *ptr);
Bool ChkCodePtr(U8 *ptr);
U0 QueVectU8Put(CQueVectU8 *v,I64 idx,U8 ch);
I64 QueVectU8Get(CQueVectU8 *v,I64 idx);
U0 QueVectU8Del(CQueVectU8 *v);
I64 LinkedLstSize(U8 **_lst);
U0 LinkedLstDel(U8 **_lst);
I64 LinkedLstCnt(U8 **_lst);
Bool FifoU8Rem(CFifoU8 *f,U8 *_b);
Bool FifoU8Peek(CFifoU8 *f,U8 *_b);
Bool FifoU8Ins(CFifoU8 *f,U8 b);
U0 FifoU8Flush(CFifoU8 *f);
U0 FifoU8Del(CFifoU8 *f);
I64 FifoU8Cnt(CFifoU8 *f);
Bool FifoI64Rem(CFifoI64 *f,I64 *_q);
Bool FifoI64Peek(CFifoI64 *f,I64 *_q);
Bool FifoI64Ins(CFifoI64 *f,I64 q);
U0 FifoI64Flush(CFifoI64 *f);
U0 FifoI64Del(CFifoI64 *f);
I64 FifoI64Cnt(CFifoI64 *f);
I64 QueSize(CQue *head);
I64 QueCnt(CQue *head);
Bool ArcFinishCompression(CArcCtrl *c);
U0 ArcExpandBuf(CArcCtrl *c);
U0 ArcCtrlDel(CArcCtrl *c);
U0 ArcCompressBuf(CArcCtrl *c);
U0 PutS(U8 *st);
U0 PutHex(I64 num,I64 width);
U0 PutChars(U64 ch);
U0 PrintWarn(U8 *fmt,...);
U0 PrintErr(U8 *fmt,...);
U0 Print(U8 *fmt,...);
Bool IsSilent();
U0 GetOutOfDollar();
U8 *AStrNew(U8 *buf);
U8 *StrNew(U8 *buf);
U8 *CatPrint(U8 *dst,U8 *fmt,...);
Bool WildMatch(U8 *test_str,U8 *wild_str);
U8 *Tabs2Spaces(U8 *src);
U8 *StrUtil(U8 *_src,I64 flags);
U8 *StrPrintJoin(U8 *dst,U8 *fmt,I64 argc,I64 *argv);
U8 *StrPrint(U8 *dst,U8 *fmt,...);
I64 StrOcc(U8 *src,U8 ch);
I64 StrNICmp(U8 *st1,U8 *st2,I64 n);
I64 StrNCmp(U8 *st1,U8 *st2,I64 n);
U8 *StrMatch(U8 *needle,U8 *haystack_str);
U8 *StrLastOcc(U8 *src,U8 *marker);
U8 *StrIMatch(U8 *needle,U8 *haystack_str);
I64 StrICmp(U8 *st1,U8 *st2);
U8 *StrFirstOcc(U8 *src,U8 *marker);
U0 StrCpy(U8 *dst,U8 *src);
I64 StrCmp(U8 *st1,U8 *st2);
I64 Spaces2Tabs(U8 *dst,U8 *src);
U8 *ScaleIndent(U8 *src,F64 indent_scale_factor);
U8 *MStrPrint(U8 *fmt,...);
U8 *LstSub(I64 sub,U8 *lst);
U8 *StrPrintFlags(U8 *dst,U8 *lst,I64 flags);
U0 ScanFlags(U8 *_dst_flags,U8 *lst,U8 *src);
CDate Str2Date(U8 *src);
U8 *StrScan(U8 *src,U8 *fmt,...);
U8 *ScanCode2KeyName(I64 sc);
U8 ScanCode2Char(I64 sc);
Bool FarCall32(U0(*fp_addr)());
I64 CallStkGrow(I64 stk_size_threshold,I64 stk_size,I64(*fp_addr)(...),...);
U0 Reboot();
I64 BCnt(I64 d);
I64 GetTSC();
CTask *Fs();
U0 InvlPg(U8 *a);
U0 CLFlush(U8 *a);
U8 XchgU8(U8 *dst,U8 d);
U32 XchgU32(U32 *dst,U32 d);
U16 XchgU16(U16 *dst,U16 d);
I64 XchgI64(I64 *dst,I64 d);
U0 SysHlt();
U0 SetMSR(I64 model_specific_reg,I64 val);
U8 LXchgU8(U8 *dst,U8 d);
U32 LXchgU32(U32 *dst,U32 d);
U16 LXchgU16(U16 *dst,U16 d);
I64 LXchgI64(I64 *dst,I64 d);
U0 CPUId(U32 rax,CRAXRBCRCXRDX *res);
U0 SetRSP(U8 *d);
U0 SetRFlags(I64 d);
U0 SetRBP(U8 *d);
U0 SetRAX(I64 d);
U0 Push(I64 d);
I64 Pop();
U8 *GetRSP();
I64 GetRFlags();
U8 *GetRBP();
I64 GetRAX();
I64 Carry();
CCPU *Gs();
U8 *MemSetU8(U8 *dst,I64 val,I64 U8cnt);
U32 *MemSetU32(U32 *dst,I64 val,I64 U32cnt);
U16 *MemSetU16(U16 *dst,I64 val,I64 U16cnt);
I64 *MemSetI64(I64 *dst,I64 val,I64 I64cnt);
U8 *MemSet(U8 *dst,I64 val,I64 cnt);
U8 *MemCpy(U8 *dst,U8 *src,I64 cnt);
I64 MemCmp(U8 *ptr1,U8 *ptr2,I64 cnt);
CD3 *D3Zero(CD3 *dst);
CD3 *D3Unit(CD3 *d);
CD3 *D3SubEqu(CD3 *diff,CD3 *d);
CD3 *D3Sub(CD3 *diff,CD3 *d1,CD3 *d2);
F64 D3NormSqr(CD3 *d);
F64 D3Norm(CD3 *d);
CD3 *D3MulEqu(CD3 *prod,F64 s);
CD3 *D3Mul(CD3 *prod,F64 s,CD3 *d);
F64 D3Dot(CD3 *d1,CD3 *d2);
CD3 *D3DivEqu(CD3 *quot,F64 s);
CD3 *D3Div(CD3 *quot,CD3 *d,F64 s);
F64 D3DistSqr(CD3 *d1,CD3 *d2);
F64 D3Dist(CD3 *d1,CD3 *d2);
CD3 *D3Cross(CD3 *prod,CD3 *d1,CD3 *d2);
CD3 *D3Copy(CD3 *dst,CD3 *src);
CD3 *D3AddEqu(CD3 *sum,CD3 *d);
CD3 *D3Add(CD3 *sum,CD3 *d1,CD3 *d2);
F64 Trunc(F64 d);
F64 Sign(F64 d);
F64 Round(F64 d);
F64 Pow10(F64 d);
F64 Pow(F64 base,F64 power);
F64 Log2(F64 d);
F64 Log10(F64 d);
F64 Ln(F64 d);
U16 Fstsw();
U16 Fstcw();
F64 Floor(F64 d);
U0 Fldcw(U16 w);
U0 Fclex();
F64 Exp(F64 d);
U64 ClampU64(U64 num,U64 lo,U64 hi);
I64 ClampI64(I64 num,I64 lo,I64 hi);
F64 Ceil(F64 d);
F64 Arg(F64 x,F64 y);
I64 ToI64(F64 d);
F64 ToF64(I64 i);
Bool ToBool(I64 i);
F64 Tan(F64 d);
U0 SwapU8(U8 *n1,U8 *n2);
U0 SwapU32(U32 *n1,U32 *n2);
U0 SwapU16(U16 *n1,U16 *n2);
U0 SwapI64(I64 *n1,I64 *n2);
F64 Sqrt(F64 d);
U64 SqrU64(U64 i);
I64 SqrI64(I64 i);
F64 Sqr(F64 d);
F64 Sin(F64 d);
I64 SignI64(I64 i);
U64 ModU64(U64 *q,U64 d);
U64 MinU64(U64 n1,U64 n2);
I64 MinI64(I64 n1,I64 n2);
U64 MaxU64(U64 n1,U64 n2);
I64 MaxI64(I64 n1,I64 n2);
F64 Cos(F64 d);
I64 AbsI64(I64 i);
F64 Abs(F64 d);
F64 ATan(F64 d);
U0 RepOutU8(U8 *buf,I64 cnt,I64 port);
U0 RepOutU32(U8 *buf,I64 cnt,I64 port);
U0 RepOutU16(U8 *buf,I64 cnt,I64 port);
U0 RepInU8(U8 *buf,I64 cnt,I64 port);
U0 RepInU32(U8 *buf,I64 cnt,I64 port);
U0 RepInU16(U8 *buf,I64 cnt,I64 port);
U0 OutU8(I64 port,I64 val);
U0 OutU32(I64 port,I64 val);
U0 OutU16(I64 port,I64 val);
U8 InU8(I64 port);
U32 InU32(I64 port);
U16 InU16(I64 port);
U0 QueRem(CQue *entry);
U0 QueInsRev(CQue *entry,CQue *succ);
U0 QueIns(CQue *entry,CQue *pred);
U0 QueInit(CQue *head);
I64 StrLen(U8 *st);
I64 ToUpper(U8 ch);
I64 CallExtNum(I64 num,...);
I64(**ext)(...);
I64 CallInd(I64(*fp_addr)(...),...);
I64 CallExtStr(U8 *name,...);
I64 Call(U8 *machine_code);
Bool LBEqu(U8 *bit_field,I64 bit,Bool val);
U0 BFieldOrU32(U8 *bit_field,I64 bit,U32 pattern);
U32 BFieldExtU32(U8 *bit_field,I64 bit,I64 size);
Bool BEqu(U8 *bit_field,I64 bit,Bool val);
Bool LBts(U8 *bit_field,I64 bit);
Bool LBtr(U8 *bit_field,I64 bit);
Bool LBtc(U8 *bit_field,I64 bit);
Bool Bts(U8 *bit_field,I64 bit);
Bool Btr(U8 *bit_field,I64 bit);
Bool Btc(U8 *bit_field,I64 bit);
Bool Bt(U8 *bit_field,I64 bit);
I64 Bsr(I64 bit_field_val);
I64 Bsf(I64 bit_field_val);
U0 CmpCtrlDel(CCmpCtrl *cc);
struct CCmpCtrl *CmpCtrlNew(U8 *buf=NULL,I64 flags=0,U8 *filename=NULL);
U8 *Doc2PlainText(CDoc *doc,CDocEntry *doc_e);
U0 DocBinsValidate(CDoc *doc);
U0 DocDel(CDoc *doc);
U0 DocLoad(CDoc *doc,U8 *src2,I64 size);
struct CDoc *DocNew(U8 *filename=NULL,CTask *task=NULL);
//TODO is added default format fmt "" correct?
struct CDocEntry *DocPrint(CDoc *doc=NULL,U8 *fmt="",...);
struct CDocEntry *DocPutLine(CDoc *doc,CDocEntry *doc_e);
I64 DocSize(CDoc *doc);
Bool DocWrite(CDoc *doc,Bool prompt=FALSE);
U8 *CmdLinePmt();
I64 HashEntrySize2(CHashSrcSym *tmph);
Bool IsLexExpression2Bin(CCmpCtrl *cc,U8 **_machine_code);
I64 Lex(CCmpCtrl *cc);
I64 LexExpression(CCmpCtrl *cc);
I64 LexGetChar(CCmpCtrl *cc);
CCodeMisc *OptLabelFwd(CCodeMisc *lb);
CIntermediateCode *OptPass012(CCmpCtrl *cc);
U0 OptPass3(CCmpCtrl *cc,COptReg *reg_offsets);
U0 OptPass4(CCmpCtrl *cc,COptReg *reg_offsets,I64 *_type);
U0 OptPass5(CCmpCtrl *cc);
U0 OptPass6(CCmpCtrl *cc);
I64 OptPass789A(
        CCmpCtrl *cc,COptReg *reg_offsets,U8 *buf,CDbgInfo **_dbg);
CHashClass *PrsClass(
        CCmpCtrl *cc,I64 keyword,I64 fsp_flags,Bool is_extern);
CHashFun *PrsFunJoin(
        CCmpCtrl *cc,CHashClass *tmp_return,U8 *name,I64 fsp_flags);
I64 PrsKeyWord(CCmpCtrl *cc);
Bool PrsStmt(CCmpCtrl *cc,I64 try_cnt=0,
        CCodeMisc *lb_break=NULL,I64 cmp_flags=CMPF_PRS_SEMICOLON);
U0 PrsStreamBlk(CCmpCtrl *cc);
CHashClass *PrsType(CCmpCtrl *cc,CHashClass **_tmpc1,
        I64 *_mode,CMemberLst *tmpm,U8 **_ident,CHashFun **_fun_ptr,
        CHashExport **_tmpex,CArrayDim *tmpad,I64 fsp_flags);
I64 PrsUnaryModifier(CCmpCtrl *cc,CPrsStk *ps,
        CMemberLst **_local_var,CArrayDim **_tmpad,I64 *unary_post_prec);
I64 PrsUnaryTerm(
        CCmpCtrl *cc,CPrsStk *ps,CMemberLst **_local_var,CArrayDim **_tmpad,
        I64 *max_prec,I64 *unary_pre_prec,I64 *paren_prec);
U0 PrsVarInit2(CCmpCtrl *cc,U8 **_dst,CHashClass *tmpc,
        CArrayDim *tmpad,U8 *data_addr_rip,U8 **_base,Bool data_heap,I64 pass);
U8 *FileNameAbs(U8 *filename,I64 fuf_flags=0);
#endif
