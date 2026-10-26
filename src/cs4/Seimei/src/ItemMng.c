#include "common.h"
extern u8 GameSt[];
static u16 s_aItemData[0x1400];
static u16 s_aMaxNumData[0x5];
static u32 s_aSeq[0x3c0];
static u16 s_aSeqSize[0xf];
static u8 s_aItemNum[0x280];
extern void * GetMyEquip(void *, signed int);
extern u32 MdlMng[];
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern int sprintf(char *, const char *, ...);
extern u32 GetGameTexList();
extern void * GetTexMngByName(void *, char *);
extern signed int ItemMng_Add_Direct(unsigned short, signed short);
extern void SFX_DeleteBySfxIdx(unsigned short);
extern signed int KnMenuMng_CallGetItemMenu(unsigned short, signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void SetMdlFade(void *, unsigned char, float);
extern void SetEventFlag(signed int);
extern void *memset(void *, int, unsigned int);
extern void _InitSequenceData(void);
extern void *memcpy();
unsigned short ItemMng_GetItemMaxNum(unsigned short a0 /* r4 */);
unsigned short ItemMng_GetPcEquip(unsigned short a0 /* r4 */);
signed int ItemMng_GetReadMark(unsigned short a0 /* r4 */);
void ItemMng_SetReadMark(unsigned short a0 /* r4 */, signed int a1 /* r5 */);
unsigned short ItemMng_GetDocumentPageNum(unsigned short a0 /* r4 */);
char * ItemMng_GetDocument(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
char * ItemMng_GetItemName_Direct(unsigned short a0 /* r4 */);
char * ItemMng_GetItemNote_Direct(unsigned short a0 /* r4 */);
char * ItemMng_GetItemNote(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
void * ItemMng_GetItemTex(unsigned short type_, unsigned short idx_);
unsigned short ItemMng_GetItemNum(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
signed int ItemMng_Add(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, signed short a2 /*
        r6 */);
signed int ItemMng_GetItemProc(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */, signed int a3 /* r7 */, signed int t0 /* r8 */);
void ItemMng_Clear(void);
u8 * ItemMng_GetCollectData(void);
void ItemMng_SetCollectData(u8 *a0 /* r4 */);





typedef struct ManualItemTexEntry { u16 id; u16 pad; u32 reserved; void *texture; u32 tail; } ManualItemTexEntry;
extern u32 s_aSeq[0x3c0];
void ItemMng_SetCollectData(u8 *a0 /* r4 */);
u8 * ItemMng_GetCollectData(void);
void ItemMng_Clear(void);
signed int ItemMng_GetItemProc(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */, signed int a3 /* r7 */, signed int t0 /* r8 */);
signed int ItemMng_Add(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, signed short a2 /*
        r6 */);
unsigned short ItemMng_GetItemNum(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
void * ItemMng_GetItemTex(unsigned short type_, unsigned short idx_);
char * ItemMng_GetItemNote(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
char *ItemMng_GetItemName(unsigned short Index, unsigned short Type);
unsigned short ItemMng_GetItemNum_Direct(unsigned short a0 /* r4 */);
void *ItemMng_GetItemTex_Direct(unsigned short id);
char * ItemMng_GetItemNote_Direct(unsigned short a0 /* r4 */);
char * ItemMng_GetItemName_Direct(unsigned short a0 /* r4 */);
signed int ItemMng_GetItemBySequence(unsigned short type, unsigned short sequence);
char * ItemMng_GetDocument(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */);
unsigned short ItemMng_GetDocumentPageNum(unsigned short a0 /* r4 */);
void ItemMng_SetReadMark(unsigned short a0 /* r4 */, signed int a1 /* r5 */);
signed int ItemMng_GetReadMark(unsigned short a0 /* r4 */);
unsigned short ItemMng_GetPcEquip(unsigned short a0 /* r4 */);
signed int ItemMng_CheckGetExperience(unsigned short a0);
unsigned short ItemMng_GetItemMaxNum(unsigned short a0 /* r4 */);
void _InitSequenceData(void);









/* ItemMng_Add_Direct @ 0x186800 */
typedef struct AddItemEntry { u16 id; u16 pad; u32 reserved; void *texture; u32 tail; } AddItemEntry;
struct ItemNumLo1 { unsigned char f : 1; };
struct ItemNumLo7 { unsigned char f : 7; };
struct ItemNumHi1 { unsigned char _pad : 7; unsigned char f : 1; };




/* ItemMng_ConsumeItem @ 0x1862E0 .. 0x18644C (0x16c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x186378 -> .L00186438
 *   cfg: kept goto: 0x186404 -> .L00186420
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SetHeartRate(void *, signed int, unsigned char);
extern signed int CheckItemUseEvent(unsigned short);

static inline unsigned short ConsumeItemNum(unsigned short a0) {
    s32 idx;
    s32 cat;

    cat = a0 / 10000;
    idx = a0 % 1000;
    if (cat == 2) {
        return s_aItemNum[(cat << 7) + idx] & 1;
    }
    return s_aItemNum[(cat << 7) + idx] & 0x7f;
}

static inline int ConsumeItemIsHeart(unsigned short a0) {
    return a0 / 10000 == 1 && a0 % 100 >= 0x18 && a0 % 100 < 0x1b;
}



/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ItemMng_SetCollectData(u8 *a0 );
u8 * ItemMng_GetCollectData(void);
void ItemMng_Clear(void);
void ItemMng_CallBack_FinishLoadFile_ItemList(void);
signed int ItemMng_GetItemProc(signed int a0 , signed int a1 , signed int a2 , signed int a3 , signed int t0 );
signed int ItemMng_Add(unsigned short a0 , unsigned short a1 , signed short a2 );
unsigned short ItemMng_GetItemNum(unsigned short a0 , unsigned short a1 );
void * ItemMng_GetItemTex(unsigned short type_, unsigned short idx_);
char * ItemMng_GetItemNote(unsigned short a0 , unsigned short a1 );
char *ItemMng_GetItemName(unsigned short Index, unsigned short Type);
signed int ItemMng_Add_Direct(unsigned short item_id_, signed short num_);
unsigned short ItemMng_GetItemNum_Direct(unsigned short a0 );
void *ItemMng_GetItemTex_Direct(unsigned short id);
char * ItemMng_GetItemNote_Direct(unsigned short a0 );
char * ItemMng_GetItemName_Direct(unsigned short a0 );
signed int ItemMng_GetItemBySequence(unsigned short type, unsigned short sequence);
char * ItemMng_GetDocument(unsigned short a0 , unsigned short a1 );
unsigned short ItemMng_GetDocumentPageNum(unsigned short a0 );
void ItemMng_SetReadMark(unsigned short a0 , signed int a1 );
signed int ItemMng_GetReadMark(unsigned short a0 );
unsigned short ItemMng_GetPcEquip(unsigned short a0 );
signed int ItemMng_ConsumeItem(unsigned short item_id_);
signed int ItemMng_CheckGetExperience(unsigned short a0);
unsigned short ItemMng_GetItemMaxNum(unsigned short a0 );
void _InitSequenceData(void);


/* ItemMng_SetCollectData @ 0x186FA0 .. 0x186FB4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memcpy at 0x186fac leaves the function
 *   return value dropped, call kept: the function is void
 */

void ItemMng_SetCollectData(u8 *a0 /* r4 */) {
    u32 a1;

    a1 = (u32)a0;
    a0 = (u8 *)s_aItemNum + 0x80;
    memcpy(a0, a1, 0x200);
    return;
}


/* ItemMng_GetCollectData @ 0x186F90 .. 0x186F9C (0xc bytes) */












u8 * ItemMng_GetCollectData(void) {
    return (u8 *)((u8 *)s_aItemNum + 0x80);
}


/* ItemMng_Clear @ 0x186F60 .. 0x186F90 (0x30 bytes, frame 0x10) */





void ItemMng_Clear(void) {
    memset((void *)s_aItemNum, 0, 0x280);
    _InitSequenceData();
    return;
}





/* ItemMng_CallBack_FinishLoadFile_ItemList @ 0x186DC0 .. 0x186F5C (0x19c bytes, frame 0x450) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1368 -> 0x22b2d0
 *   literal: @1721 is the string 'me_i%05d.tm2'
 *   stack: address of the slot at 0x50 escapes at 0x186e08
 *   stack: address of the slot at 0x50 escapes at 0x186e30
 *   stack: address of the slot at 0x430 escapes at 0x186f00
 *   cfg: loop body is not one contiguous region: .L00186EE8
 *   cfg: loop body is not one contiguous region: .L00186EF0
 */

void ItemMng_CallBack_FinishLoadFile_ItemList(void) {
    u32 t0;
    u32 a2;
    u32 a1;
    u_long128 v1_q;
    u_long128 v0_q;
    s32 i;
    s32 j;
    s32 id;
    u32 lo;
    u32 row;
    u16 *p;
    u8 *s2;
    u32 s1;
    u32 s0;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 magic_dividend_186e6c;
    u8 stackFrame_430[32] __attribute__((aligned(16)));
    

    a0 = (u32)s_aItemNum;
    memset((void *)s_aItemNum, 0, 0x280);
    _InitSequenceData();
    {
u32 stackFrame_50[0xf8] __attribute__((aligned(16))) = {
    (u32)"\210\352\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee1,
    (u32)"\223\361\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee2,
    (u32)"\216O\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee3,
    (u32)"\216l\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee4,
    (u32)"\214\334\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee5,
    (u32)"\230Z\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee6,
    (u32)"\216\265\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee7,
    (u32)"\224\252\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee8,
    (u32)"\213\343\211\360\216\364\202\314\214\214\225z\000\000\000", 0x2ee9,
    (u32)"\223\272\202\314\214\304\227\351\000\000\000\000\000\000\000", 0x3aa2,
    (u32)"\226\330\222\306\000\000\000", 0x2b03, (u32)"\224@\227\210\202\314\226\362\222\331",
    0x2b04, (u32)"\220_\213\276\000\000\000", 0x2b05,
    (u32)"\226\330\202\314\216\346\202\301\216\350\000\000\000\000\000", 0x2b06,
    (u32)"\214\214\220\365\202\337\202\314\212\231\000\000\000\000\000", 0x3aa7,
    (u32)"\210\240\202\314\215\235\214\242\000\000\000\000\000\000\000", 0x2b08,
    (u32)"\231\335\202\314\215\235\214\242\000\000\000\000\000\000\000", 0x2b09,
    (u32)"\216\\\202\314\226\330\224\302\000\000\000\000\000\000\000", 0x2ef2,
    (u32)"\351\353\202\314\226\330\224\302\000\000\000\000\000\000\000", 0x2ef3,
    (u32)"\211\363\202\352\202\275\226\330\224\302\000\000\000\000\000", 0x2ef4,
    (u32)"\221o\230Z\224\325\000", 0x2ef5, (u32)"\221o\230Z\202\314\213\356", 0x2ef6,
    (u32)"\223B\224\262\202\253\000", 0x3aaf, (u32)"\227\354\226\275\226\362\000", 0x32e1,
    (u32)"\227\354\226\275\220_\220\205", 0x32e2,
    (u32)"\223\261\202\253\202\314\220\205\217\273", 0x32e3,
    (u32)"\225\225\226\202\202\314\223B", 0x36cc, (u32)"\214`\221\343\217M\000", 0x36cd,
    (u32)"\223S\202\314\236\266\000", 0x3ab6, (u32)"\201u\211\256\225~\201v\202\314\222n\220}",
    0x2eff,
    (u32)"\201u\226\362\216t\223\260\201v\202\314\222n\220}\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x2f00,
    (u32)"\201u\216\320\202\314\223\271\201v\202\314\222n\220}\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x2f01,
    (u32)"\201u\216\\\202\314\216\320\201v\202\314\222n\220}\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x2f02,
    (u32)"\201u\226\232\202\314\223\271\201v\202\314\222n\220}\000\000\000\000\000\000\000",
    0x2f03, (u32)"\216t\202\314\223`\222B\217\221", 0x4e21,
    (u32)"\225\203\202\314\222u\216\350\216\206", 0x4e22,
    (u32)"\211\204\226\275\216w\223\354\201@\212\252\203m\210\353\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e23,
    (u32)"\211\204\226\275\216w\223\354\201@\212\252\203m\223\363\000\000\000\000\000\000\000",
    0x4e24, (u32)"\217\227\226[\202\314\212o\217\221\202\253", 0x4e25,
    (u32)"\217\274\227t\220F\202\314\217\221", 0x4e26,
    (u32)"\216\256\224\325\202\314\203p\203Y\203\213\202\360\211\360\202\255\212\252\225\250\201i\226v\201j\000\000\000",
    0x4e27,
    (u32)"\227\212\213\337\223@\214\237\225\252\217\221\201@\212\252\203m\210\353\000\000\000",
    0x4e28, (u32)"\216\\\202\314\213L\201@\212\252\203m\210\353", 0x4e29,
    (u32)"\216\\\202\314\213L\201@\212\252\203m\223\363", 0x4e2a,
    (u32)"\216\\\202\314\213L\201@\212\252\203m\216Q", 0x4e2b,
    (u32)"\223\361\227\225\220F\202\314\217\221", 0x4e2c,
    (u32)"\216O\227\307\212\333\202\314\217\221\225t\202\257\201@\210\353\000\000\000\000\000",
    0x4e2d, (u32)"\211\234\225\373\202\314\223\372\213L\201@\223\363", 0x4e2e,
    (u32)"\211\234\225\373\202\314\223\372\213L\201@\210\353", 0x4e2f,
    (u32)"\227\212\213\337\223@\214\237\225\252\217\221\201@\212\252\203m\223\363\000\000\000\000\000\000\000\000\000\000\000",
    0x4e30,
    (u32)"\227\212\213\337\223@\214\237\225\252\217\221\201@\212\252\203m\216Q\000\000\000",
    0x4e31, (u32)"\227\212\213\337\202\326\202\314\217\221\212\310", 0x4e32,
    (u32)"\342K\225\225\210\363\211\360\217\221", 0x4e33,
    (u32)"\224@\211b\202\314\216\350\213L\201@\212\252\203m\210\353\000\000\000\000\000",
    0x4e34, (u32)"\225\225\213S\212\357\346\235", 0x4e35,
    (u32)"\224@\211b\202\314\216\350\213L\201@\212\252\203m\223\363\000\000\000\000\000",
    0x4e36, (u32)"\226\362\216t\224@\227\210\211\217\213N", 0x4e37,
    (u32)"\211\251\225z\202\314\220\330\202\352\222[", 0x4e38,
    (u32)"\223\271\211\372\202\314\217\221\215\373\201@\210\353", 0x4e39,
    (u32)"\223\271\211\372\202\314\217\221\215\373\201@\223\363", 0x4e3a,
    (u32)"\223\271\211\372\202\314\217\221\215\373\201@\216Q", 0x4e3b,
    (u32)"\225\202\214\216\202\314\223\372\213L", 0x4e3c,
    (u32)"\213f\226\344\227l\202\314\223\372\213L", 0x4e3d,
    (u32)"\225\351\227t\202\314\223\372\213L", 0x4e3e,
    (u32)"\225\351\227t\202\314\223\372\213L", 0x4e3f,
    (u32)"\216\\\202\314\216\320\211\217\213N", 0x4e40,
    (u32)"\215g\227t\226\344\227l\202\314\223\372\213L", 0x4e41,
    (u32)"\223\271\226\236\202\314\217\221\201@\212\252\203m\210\353\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e42,
    (u32)"\216O\227\307\212\333\202\314\217\221\225t\202\257\201@\223\363\000\000\000\000\000",
    0x4e43, (u32)"\223\271\226\236\202\314\212o\217\221\202\253", 0x4e44,
    (u32)"\223\271\226\236\202\314\217\221\201@\212\252\203m\223\363\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e45,
    (u32)"\341\260\202\276\202\347\202\257\202\314\217\221\225t\202\257\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e46,
    (u32)"\223\271\226\236\202\314\217\221\201@\212\252\203m\216Q\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e47,
    (u32)"\216O\227\307\212\333\202\314\217\221\225t\202\257\201@\216l\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e48,
    (u32)"\223\271\226\236\202\314\217\221\201@\212\252\203m\214\336\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e49,
    (u32)"\216O\227\307\212\333\202\314\217\221\225t\202\257\201@\216Q\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e4a,
    (u32)"\223\271\226\236\202\314\217\221\201@\212\252\203m\216l\000\000\000\000\000\000\000",
    0x4e4b, (u32)"\220\257\226\274\220}\211\360\217\221", 0x4e4c,
    (u32)"\226k\223l\216\265\220\257\220\257\226\274\220}", 0x4e4d,
    (u32)"\217\\\223\361\216x\211\360\217\221", 0x4e4e,
    (u32)"\203J\203I\203i\203V\220\247\215\354\223\372\213L1\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e4f,
    (u32)"\203J\203I\203i\203V\220\247\215\354\223\372\213L2\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e50,
    (u32)"\203J\203I\203i\203V\220\247\215\354\223\372\213L3\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
    0x4e51, (u32)"\203J\203I\203i\203V\202\314\223\372\213L1", 0x4e52,
    (u32)"\203J\203I\203i\203V\202\314\223\372\213L2", 0x4e53,
    (u32)"\203J\203I\203i\203V\202\314\223\372\213L3", 0x4e54,
    (u32)"\211\234\225\373\202\326\202\314\217\221\222u\202\253\000", 0x4e55,
    (u32)"\211A\227z\216t\202\314\217\221\222u\202\253\000", 0x4e56,
    (u32)"\225P\214N\202\326\202\314\216\350\216\206\000\000\000", 0x4e57,
    (u32)"\225\351\227t\202\326\202\314\222u\216\350\216\206\000", 0x4e58,
    (u32)"\223\271\222\277\202\314\217\221\215\373\201@\210\353\000", 0x4e59,
    (u32)"\223\271\222\277\202\314\217\221\215\373\201@\223\363\000", 0x4e5a,
    (u32)"\225z\202\314\220\330\202\352\222[\000\000\000\000\000", 0x4e5b,
    (u32)"\223\271\222\277\202\314\217\221\215\373\201@\216Q\000", 0x4e5c,
    (u32)"\203\215\201[\211\354\213S\201i\226v\201j\000", 0x7531,
    (u32)"\216\256\225\204\201u\211\354\213S\201v\000\000\000", 0x7532,
    (u32)"\216\256\225\204\201u\220\205\211g\202\253\201v\000", 0x7533,
    (u32)"\216\256\225\204\201u\230\370\231S\217\227\201v\000", 0x7534,
    (u32)"\216\256\225\204\201u\216\314\222w\345\201\201v\000", 0x7535,
    (u32)"\216\256\225\204\201u\227\355\345\263\201v\000\000\000", 0x7536,
    (u32)"\216\256\225\204\201u\223y\217\343\214\313\201v\000", 0x7537,
    (u32)"\216\364\225\204\201u\220\347\210\363\220\341\211\324\201v\000\000\000\000\000\000\000",
    0x7538, (u32)"\216\364\225\204\201u\224\352\220j\201v", 0x7539,
    (u32)"\216\364\225\204\201u\213S\211\316\201v", 0x753a,
    (u32)"\216\364\225\204\201u\224\362\211\215\201v", 0x753c,
    (u32)"\216\256\225\204\201u\224\352\211\354\213S\201v", 0x753e,
    (u32)"\216\256\225\204\201u\213f\201v", 0x7542,
    (u32)"\216\256\225\204\201u\225s\223\256\224\233\201v", 0x7543,
    (u32)"\216\364\225\204\201u\225\225\225\266\201v", 0x7544,
    (u32)"\216\256\225\204\201u\202\334\202\265\202\347\201v", 0x7545,
    (u32)"\216\256\225\204\201u\211\205\217\227\201v", 0x7549,
    (u32)"\216\256\225\204\201u\213w\345\263\201v", 0x754a,
    (u32)"\216\256\225\204\201u\215\323\211\345\201v", 0x754b,
    (u32)"\216\256\225\204\201u\221P\213S\201v", 0x754d,
    (u32)"\216\256\225\204\201u\214\354\213S\201v", 0x754e,
    (u32)"\216\256\225\204\201u\225a\220l\201v", 0x7554,
    (u32)"\216\364\225\204\201u\211\316\227\264\201v", 0x7556,
    (u32)"\214\354\202\350\202\314\217\254\223\201", 0x9c41,
    (u32)"\225X\211J\202\314\227\354\223\201", 0x9c42,
    (u32)"\211\316\211e\202\314\220_\223\201", 0x9c43, (u32)"\211A\227z\220\356\000", 0x9c44,
    (u32)"\221\223\220\205\227\354\220\356\000\000\000\000\000\000\000", 0x9c45,
    (u32)"\220\324\222\351\220\324\227\264\220\356\000\000\000\000\000", 0x9c46,
    (u32)"\214\334\222\351\227\264\211\244\202\314\220_\221\204\000", 0x9c47
};

    for (i = 0; i < 0x7c; i++) {
        id = ((s32 (*)[2])stackFrame_50)[i][1];
        lo = (u16)id % 1000;
        lo = (u16)lo << 4;
        row = (u32)((ManualItemTexEntry *)s_aItemData + (u16)((u16)id / 10000) * 128);
        p = (u16 *)(row + lo);
        p[0] = id;
        *(u32 *)(p + 2) = (u32)KnMsgMng_GetMsgStr(i + 0x49444);
    }
    }
    v1 = 0x80;
    *(u16 *)s_aMaxNumData = v1;
    s_aMaxNumData[1] = v1;
    s_aMaxNumData[2] = v1;
    s_aMaxNumData[3] = v1;
    s_aMaxNumData[4] = v1;
    for (i = 1; i < 5; i++) {
        for (j = 0; j < 0x80; j++) {
            if (((u16 (*)[128][8])s_aItemData)[i][j][0] != 0) {
                sprintf((char *)stackFrame_430, "me_i%05d.tm2", ((u16 (*)[128][8])s_aItemData)[i][j][0]);
                *(u32 *)&((u16 (*)[128][8])s_aItemData)[i][j][4] = (u32)GetTexMngByName((void *)GetGameTexList(), (char *)stackFrame_430);
            }
        }
    }
}


/* ItemMng_GetItemProc @ 0x186C90 .. 0x186DB4 (0x124 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3ca3d70a at 0x186d74
 *   declaration vs inferred signature: return signed int vs inferred u32
 */












signed int ItemMng_GetItemProc(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */, signed int a3 /* r7 */, signed int t0 /* r8 */) {
    s32 s4;
    s32 s3;
    s32 s2;
    s32 s1;
    s32 s0;
    u32 v0;
    s32 v1;

    s4 = a0;
    s3 = a2;
    s2 = a3;
    s1 = t0;
    s0 = a1;
    a0 = 0x1f;
    SFX_DeleteBySfxIdx(a0);
    a0 = (u16)s4;
    a1 = s1;
    KnMenuMng_CallGetItemMenu(a0, a1);
    a0 = (u16)s4;
    a1 = (s16)s1;
    ItemMng_Add_Direct(a0, a1);
    v0 = -1;
    a0 = 0;
    if ((u32)s2 != v0) {
        v0 = 7;
        if ((u32)s3 != v0) {
            v0 = 1;
            switch ((u32)s3) {
            case 1:
                a0 = v0;
                a1 = s2;
                v0 = GetMdlMngIndexByCtrlId(a0, a1);
                a0 = v0 + 0x30;
                v0 = (u32)MdlMng;
                v1 = (u32)((u32)a0) * (u32)(0x1c0);
                a0 = (s32)((u8 *)MdlMng + v1);
                break;
            }
        } else {
            a0 = v0;
            a1 = s2;
            v0 = GetMdlMngIndexByCtrlId(a0, a1);
            a0 = v0 + 0x90;
            v0 = (u32)MdlMng;
            v1 = (u32)((u32)a0) * (u32)(0x1c0);
            a0 = (s32)((u8 *)MdlMng + v1);
        }
    }
    if ((u32)(s32)a0 != 0) {
        a1 = 2;
        SetMdlFade((void *)a0, a1, 0.0199999996f);
    }
    a0 = s0;
    if ((u32)s0 != 0) {
        SetEventFlag(a0);
    }
    v0 = 1;
    return v0;
}


/* ItemMng_Add @ 0x186B90 .. 0x186C84 (0xf4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x186bac writes a register its branch at 0x186ba8 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */










signed int ItemMng_Add(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */, signed short a2 /*
        r6 */) {
    u32 v0;
    u16 a0_2;
    s16 a1_2;

    v0 = 4;
    switch ((u32)(u16)a0) {
    case 0:
        a0_2 = a1;
        a1_2 = a2;
        v0 = ItemMng_Add_Direct(a0_2, a1_2);
        break;
    case 1:
        v0 = (u16)a1;
        v0 = v0 + 0x2710;
        a1_2 = a2;
        a0_2 = v0;
        v0 = ItemMng_Add_Direct(a0_2, a1_2);
        break;
    case 2:
        v0 = (u16)a1;
        v0 = v0 + 0x4e20;
        a1_2 = a2;
        a0_2 = v0;
        v0 = ItemMng_Add_Direct(a0_2, a1_2);
        break;
    case 3:
        v0 = (u16)a1;
        v0 = v0 + 0x7530;
        a1_2 = a2;
        a0_2 = v0;
        v0 = ItemMng_Add_Direct(a0_2, a1_2);
        break;
    case 4:
        v0 = (u16)a1;
        v0 = v0 + 0x7fff;
        a1_2 = a2;
        v0 = v0 + 0x1c41;
        a0_2 = v0;
        v0 = ItemMng_Add_Direct(a0_2, a1_2);
        break;
    default:
        v0 = 0;
    }
    return v0;
}


/* ItemMng_GetItemNum @ 0x186B10 .. 0x186B90 (0x80 bytes) */
/*
 * dcomp notes:
 *   delay: lui at 0x186b48 writes a register its branch at 0x186b44 reads
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */






unsigned short ItemMng_GetItemNum(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 v0;

    v0 = (u32)s_aMaxNumData;
    v0 = *(u16 *)(s32)((u8 *)s_aMaxNumData + (s32)((u32)a0 << 1));
    if ((s32)v0 < (s32)a1) {
        return 0;
    }
    v0 = 2;
    v0 = 0;
    if ((u32)a0 == 2) {
        v0 = (u32)s_aItemNum;
        return (u32)(*(u8 *)(s32)((u32)(a1) + (s32)((u8 *)s_aItemNum + (s32)((u32)a0 << 7)))) & 1;
    } else {
        v0 = (u32)s_aItemNum;
        return (u32)(*(u8 *)(s32)((u32)(a1) + (s32)((u8 *)s_aItemNum + (s32)((u32)a0 << 7)))) &
            0x7f;
    }
    return v0;
}








void * ItemMng_GetItemTex(unsigned short type_, unsigned short idx_) {
    char buff[64];

    if (s_aMaxNumData[type_] < idx_) {
        return 0;
    }
    sprintf(buff, "me_i%05d.tm2", ((u16 (*)[128][8])s_aItemData)[type_][idx_][0]);
    return GetTexMngByName((void *)GetGameTexList(), buff);
}


/* ItemMng_GetItemNote @ 0x186A40 .. 0x186A74 (0x34 bytes) */
/*
 * dcomp notes:
 *   tail: j KnMsgMng_GetMsgStr at 0x186a6c leaves the function
 *   declaration vs inferred signature: return char * vs inferred void
 */









char * ItemMng_GetItemNote(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 a0_word = a0;
    u32 v0;

    a0_word = a0_word << 0xb;
    v0 = (u32)s_aItemData;
    v0 = 0x30d40;
    return (char *)KnMsgMng_GetMsgStr((u32)(*(u16 *)(s32)(((u32)(u16)a1 << 4) + (u32)(s32)((u8
        *)s_aItemData + a0_word))) + 0x30d40);
}







char *ItemMng_GetItemName(unsigned short Index, unsigned short Type) {
    if (s_aMaxNumData[Index] < Type) {
        return 0;
    }
    return (char *)*(unsigned int *)((unsigned char *)(s_aItemData + 2) + (Index << 11) + ((unsigned int)Type << 4));
}

signed int ItemMng_Add_Direct(unsigned short item_id_, signed short num_) {
    u32 empty, invalid;
    u32 type;
    u8 *p;
    u16 idx;
    u16 cat;
    int ok;

    empty = 1;
    type = item_id_ / 10000;
    invalid = empty;
    if ((u16)type <= 5) {
        if ((u16)(item_id_ % 1000) <= 128) invalid = 0;
    }
    if (invalid == 0) {
        if (((AddItemEntry (*)[128])s_aItemData)[(u16)type][(u16)(item_id_ % 1000)].id != 0) empty = 0;
    }
    ok = !(empty != 0);
    if (ok) {} else return 0;
    cat = item_id_ / 10000;
    cat = (u16)cat;
    idx = item_id_ % 1000;
    if (cat == 2) {
        int num;
        p = s_aItemNum + cat * 0x80 + idx;
        num = num_ + (*p & 1);
        if (num > 1) num = 1;
        if (num < 0) num = 0;
        ((struct ItemNumLo1 *)p)->f = num;
    } else {
        int num;
        p = s_aItemNum + cat * 0x80 + idx;
        num = num_ + (*p & 0x7f);
        if (num > 99) num = 99;
        if (num < 0) num = 0;
        ((struct ItemNumLo7 *)p)->f = num;
    }
    if (0 < num_) {
        return ((struct ItemNumHi1 *)p)->f = 1;
    }
    return 1;
}






unsigned short ItemMng_GetItemNum_Direct(unsigned short a0 /* r4 */) {
    s32 idx;
    s32 cat;

    cat = a0 / 10000;
    idx = a0 % 1000;
    if (cat == 2) {
        return s_aItemNum[(cat << 7) + idx] & 1;
    }
    return s_aItemNum[(cat << 7) + idx] & 0x7f;
}



void *ItemMng_GetItemTex_Direct(unsigned short id) {
    u32 empty, invalid;
    u32 type;
    void *result;
    empty = 1;
    type = id / 10000;
    invalid = empty;
    if ((u16)type <= 5) {
        if ((u16)(id % 1000) <= 128) invalid = 0;
    }
    if (invalid == 0) {
        if (((ManualItemTexEntry (*)[128])s_aItemData)[(u16)type][(u16)(id % 1000)].id != 0) empty = 0;
    }
    if (empty != 0) result = 0;
    else result = *(void **)&((ManualItemTexEntry (*)[128])((u8 *)s_aItemData + 8))[(u16)type][(u16)(id % 1000)];
    return result;
}


/* ItemMng_GetItemNote_Direct @ 0x186660 .. 0x186674 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j KnMsgMng_GetMsgStr at 0x18666c leaves the function
 *   declaration vs inferred signature: return char * vs inferred void
 */










char * ItemMng_GetItemNote_Direct(unsigned short a0 /* r4 */) {
    u32 a0_word = a0;
    u32 v1;

    v1 = (u16)a0_word;
    a0_word = v1 + (u32)(0x30d40);
    return (char *)KnMsgMng_GetMsgStr(a0_word);
}


/* ItemMng_GetItemName_Direct @ 0x186610 .. 0x18665C (0x4c bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x186658 computes the return value
 *   declaration vs inferred signature: return char * vs inferred u32
 */






char * ItemMng_GetItemName_Direct(unsigned short a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = (u32)(u8 *)(s_aItemData + 2);
    v0 = 0x3e8;
    v0 = (s32)a0 / (s32)(0x2710);
    {
        u32 dcomp_tmp_0;
        dcomp_tmp_0 = v1 + (u32)(v0 << 0xb);
        v1 = dcomp_tmp_0;
    }
    v0 = (s32)a0 % (s32)(0x3e8);
    v0 = v0 << 4;
    return (char *)*(s32 *)(u32)(v0 + v1);
}


signed int ItemMng_GetItemBySequence(unsigned short type, unsigned short sequence) {
    int game;
    int result;
    game = GameSt[0x14];
    if (((u16 (*)[5])s_aSeqSize)[game][type] <= sequence) {
        result = -1;
    } else {
        result = ((u16 (*)[5][128])s_aSeq)[game][type][sequence];
    }
    return result;
}




/* ItemMng_GetDocument @ 0x186560 .. 0x18658C (0x2c bytes) */
/*
 * dcomp notes:
 *   tail: j KnMsgMng_GetMsgStr at 0x186584 leaves the function
 *   declaration vs inferred signature: return char * vs inferred void
 */










char * ItemMng_GetDocument(unsigned short a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 a0_word = a0;
    u32 a1_word = a1;
    s32 v0;
    s32 v1;

    v0 = (u16)a1_word;
    v1 = (u16)a0_word;
    a1_word = v0 + 1;
    v0 = 0x35b60;
    v1 = v1 + (u32)(0x35b60);
    v0 = (u32)((u32)v1) * (u32)(0xa);
    a0_word = a1_word + v0;
    return (char *)KnMsgMng_GetMsgStr(a0_word);
}


/* ItemMng_GetDocumentPageNum @ 0x1864F0 .. 0x186558 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */










unsigned short ItemMng_GetDocumentPageNum(unsigned short a0 /* r4 */) {
    u32 a0_word = a0;
    s32 v1;
    u32 v0;
    u32 s0;
    s32 s1;

    v1 = (u16)a0_word;
    v0 = 0x35b60;
    v1 = v1 + (u32)(0x35b60);
    v0 = (u32)((u32)v1) * (u32)(5);
    s0 = 0;
    s1 = (u32)((u32)v1) * (u32)(0xa);
    do {
        v0 = s0 + 1;
        a0_word = v0 + s1;
        s0 = s0 + 1;
        v0 = (u32)KnMsgMng_GetMsgStr(a0_word);
    } while (v0 != 0);
    v0 = s0 + -1;
    v0 = (u16)v0;
    return v0;
}


/* ItemMng_SetReadMark @ 0x1864C0 .. 0x1864F0 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */













void ItemMng_SetReadMark(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a0_2; // a2

    a0_2 = (u32)s_aItemNum;
    ((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)(((u32)(s32)((u8 *)s_aItemNum +
        a0) + 0x100)))->f = a1;
    return;
}


/* ItemMng_GetReadMark @ 0x1864A0 .. 0x1864C0 (0x20 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */










signed int ItemMng_GetReadMark(unsigned short a0 /* r4 */) {
    u32 v0;

    v0 = (u32)s_aItemNum;
    v0 = (s32)((u8 *)s_aItemNum + (u32)(u16)a0);
    return (u32)((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)((v0 + 0x100)))->f;
}


/* ItemMng_GetPcEquip @ 0x186450 .. 0x1864A0 (0x50 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */















unsigned short ItemMng_GetPcEquip(unsigned short a0 /* r4 */) {
    u32 a0_word = a0;
    u32 a1;
    u32 v0;
    u32 v1;

    a1 = (u16)a0_word;
    a0_word = (u32)((u8 *)MdlMng + 0x11800);
    v0 = (u32)GetMyEquip((void *)a0_word, a1);
    v1 = *(u8 *)v0;
    a0_word = *(s32 *)(((u8 *)v0 + 4));
    if (v1 == 0) {
        v0 = a0_word + 0x7fff;
        a0_word = v0 + 0x1c41;
    } else {
        v0 = 1;
        if (v1 == v0) {
            a0_word = a0_word + 0x7530;
        }
    }
    v0 = (u16)a0_word;
    return v0;
}

signed int ItemMng_ConsumeItem(unsigned short item_id_) {
    int bOk;

    if (ConsumeItemNum(item_id_) <= 0) {
        return 0;
    }
    if (ConsumeItemIsHeart(item_id_)) {
        SetHeartRate((void *)(MdlMng + 0x4600), (item_id_ % 1000 - 0x17) * 0x1e, 9);
        bOk = 1;
    } else if (item_id_ / 10000 == 1) {
        bOk = CheckItemUseEvent(item_id_);
    } else {
        return 0;
    }
    if (bOk) {
        ItemMng_Add_Direct(item_id_, -1);
    }
    return bOk;
}











signed int ItemMng_CheckGetExperience(unsigned short a0) {
    struct ExperienceBit {
        unsigned char _pad : 7;
        unsigned char f : 1;
    };
    u8 *address;

    __asm__ volatile(
        ".set noreorder\n"
        "lui $2,0x68db\n"
        "andi $6,$4,0xffff\n"
        "ori $2,$2,0x8bad\n"
        "addiu $3,$0,1000\n"
        "mult $2,$6\n"
        "srl $5,$6,31\n"
        "nop\n"
        "mfhi $4\n"
        "la $2,s_aItemNum\n"
        "div $6,$3\n"
        "sra $3,$4,12\n"
        "addu $3,$3,$5\n"
        "andi $3,$3,0xffff\n"
        "sll $3,$3,7\n"
        "addu $2,$2,$3\n"
        "mfhi $3\n"
        "andi $3,$3,0xffff\n"
        "addu %0,$3,$2\n"
        ".set reorder\n"
        : "=r"(address)
        :
        : "$3", "$4", "$5", "$6", "hi", "lo", "memory"
    );
    return ((struct ExperienceBit *)address)->f;
}


/* ItemMng_GetItemMaxNum @ 0x186240 .. 0x186274 (0x34 bytes) */
/*
 * dcomp notes:
 *   return: lhu at 0x186270 computes the return value
 *   declaration vs inferred signature: return unsigned short vs inferred u16
 */






unsigned short ItemMng_GetItemMaxNum(unsigned short a0 /* r4 */) {
    u16 v0;
    u8 a1;
    u32 v1;

    v0 = a0;
    a1 = GameSt[0x14];
    v1 = (u32)s_aSeqSize;
    return *(u16 *)(u32)((u32)((u32)v0 << 1) + (u32)(s32)((u8 *)s_aSeqSize +
        (u32)((u32)((u32)((u32)a1 << 2) + (u32)(a1)) << 1)));
}











void _InitSequenceData(void) {
    {
        u16 aP0_Tool[26] = {0x32e1, 0x32e2, 0x36cd, 0x2ee1, 0x2ee2, 0x2ee3, 0x2ee4, 0x2ee5, 0x2ee7, 0x2ee8, 0x2eff, 0x2f00, 0x2f02, 0x2f03, 0x2ef2, 0x2ef3, 0x2ef4, 0x2b08, 0x2b09, 0x36cc, 0x3aaf, 0x3aa2, 0x2b04, 0x3aa7, 0x2ef6, 0x3ab6};
        u16 aP0_Card[17] = {0x7539, 0x753c, 0x753a, 0x7538, 0x754b, 0x7535, 0x7543, 0x7537, 0x7536, 0x7534, 0x7544, 0x7542, 0x7532, 0x7533, 0x7549, 0x754a, 0x7554};
        u16 aP0_Weapon[3] = {0x9c41, 0x9c42, 0x9c43};
        u16 aP0_Book[28] = {0x4e22, 0x4e58, 0x4e23, 0x4e24, 0x4e55, 0x4e2c, 0x4e25, 0x4e57, 0x4e26, 0x4e56, 0x4e29, 0x4e2a, 0x4e2b, 0x4e33, 0x4e4e, 0x4e4c, 0x4e4d, 0x4e34, 0x4e36, 0x4e35, 0x4e37, 0x4e40, 0x4e3d, 0x4e41, 0x4e3e, 0x4e42, 0x4e49, 0x4e46};
        memcpy(((u16 (*)[5][128])s_aSeq)[0][1], aP0_Tool, 52);
        memcpy(((u16 (*)[5][128])s_aSeq)[0][3], aP0_Card, 34);
        memcpy(((u16 (*)[5][128])s_aSeq)[0][4], aP0_Weapon, 6);
        memcpy(((u16 (*)[5][128])s_aSeq)[0][2], aP0_Book, 56);
        ((u16 (*)[5])s_aSeqSize)[0][1] = 26;
        ((u16 (*)[5])s_aSeqSize)[0][3] = 17;
        ((u16 (*)[5])s_aSeqSize)[0][4] = 3;
        ((u16 (*)[5])s_aSeqSize)[0][2] = 28;
    }
    {
        u16 aP1_Tool[28] = {0x32e1, 0x32e2, 0x36cd, 0x2ee1, 0x2ee2, 0x2ee3, 0x2ee4, 0x2ee5, 0x2ee6, 0x2ee7, 0x2eff, 0x2f00, 0x2f01, 0x2f02, 0x2f03, 0x2ef2, 0x2ef3, 0x2ef4, 0x2b08, 0x2b09, 0x36cc, 0x3aaf, 0x3aa2, 0x2b03, 0x2b06, 0x2b05, 0x2ef5, 0x3ab6};
        u16 aP1_Card[15] = {0x7539, 0x753c, 0x7556, 0x753a, 0x7538, 0x7535, 0x7537, 0x7534, 0x7544, 0x7532, 0x7533, 0x7545, 0x7549, 0x754a, 0x7554};
        u16 aP1_Weapon[3] = {0x9c44, 0x9c45, 0x9c46};
        u16 aP1_Book[36] = {0x4e21, 0x4e23, 0x4e24, 0x4e5b, 0x4e32, 0x4e56, 0x4e28, 0x4e30, 0x4e31, 0x4e38, 0x4e59, 0x4e5a, 0x4e5c, 0x4e25, 0x4e57, 0x4e55, 0x4e2d, 0x4e43, 0x4e4a, 0x4e48, 0x4e33, 0x4e4e, 0x4e4c, 0x4e4d, 0x4e2f, 0x4e2e, 0x4e39, 0x4e3a, 0x4e3b, 0x4e40, 0x4e3c, 0x4e3f, 0x4e44, 0x4e46, 0x4e42, 0x4e49};
        memcpy(((u16 (*)[5][128])s_aSeq)[1][1], aP1_Tool, 56);
        memcpy(((u16 (*)[5][128])s_aSeq)[1][3], aP1_Card, 30);
        memcpy(((u16 (*)[5][128])s_aSeq)[1][4], aP1_Weapon, 6);
        memcpy(((u16 (*)[5][128])s_aSeq)[1][2], aP1_Book, 72);
        ((u16 (*)[5])s_aSeqSize)[1][1] = 28;
        ((u16 (*)[5])s_aSeqSize)[1][3] = 15;
        ((u16 (*)[5])s_aSeqSize)[1][4] = 3;
        ((u16 (*)[5])s_aSeqSize)[1][2] = 36;
    }
    {
        u16 aP2_Tool[6] = {0x32e1, 0x32e2, 0x36cd, 0x2eff, 0x2f03, 0x36cc};
        u16 aP2_Card[15] = {0x7539, 0x753c, 0x7556, 0x753a, 0x7538, 0x754d, 0x754e, 0x7535, 0x7543, 0x7534, 0x7544, 0x7532, 0x7549, 0x754a, 0x7554};
        u16 aP2_Weapon[1] = {0x9c47};
        u16 aP2_Book[3] = {0x4e45, 0x4e47, 0x4e4b};
        memcpy(((u16 (*)[5][128])s_aSeq)[2][1], aP2_Tool, 12);
        memcpy(((u16 (*)[5][128])s_aSeq)[2][3], aP2_Card, 30);
        memcpy(((u16 (*)[5][128])s_aSeq)[2][4], aP2_Weapon, 2);
        memcpy(((u16 (*)[5][128])s_aSeq)[2][2], aP2_Book, 6);
        ((u16 (*)[5])s_aSeqSize)[2][1] = 6;
        ((u16 (*)[5])s_aSeqSize)[2][3] = 15;
        ((u16 (*)[5])s_aSeqSize)[2][4] = 1;
        ((u16 (*)[5])s_aSeqSize)[2][2] = 3;
    }
}
