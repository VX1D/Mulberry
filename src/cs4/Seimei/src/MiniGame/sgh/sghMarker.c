#include "common.h"

/* sghMarker_MarkerClear @ 0x20C950 .. 0x20C968 (0x18 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 MdlMng[];

struct dw_2835182 {
    unsigned char pos[25];
};

extern void sghEneThk_GetActIsPossible(void *, void *, unsigned int);
extern void sghMarker_SetTgtPos(unsigned char, unsigned char, unsigned char);


/* sghMarker_SetTgtPos @ 0x20CA70 .. 0x20CB70 (0x100 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a3 at 0x20cb00
 *   fpu: float literal 0x3cdd2f1b at 0x20cb04
 *   fpu: float literal 0x3dcccccd at 0x20cb24
 *   fpu: mtc1 reinterprets a2 at 0x20cb34
 *   declaration vs inferred signature: return void vs inferred float
 */

extern u32 sghMap_GetMainTblMap();

struct dw_2833636_fields;
struct dw_2835393_fields;
#ifndef PROTO_DW_2838783_FIELDS
#define PROTO_DW_2838783_FIELDS
struct dw_2838783_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2838579_FIELDS
#define PROTO_DW_2838579_FIELDS
struct dw_2838579_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2838257_FIELDS
#define PROTO_DW_2838257_FIELDS
struct dw_2838257_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2835393_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2835393_FIELDS
#define PROTO_DW_2835393_FIELDS
struct dw_2835393_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2833636_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2835393_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2838783_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2838579_fields flags; unsigned char _pad1[3]; struct dw_2838257_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_0__33CBB62D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_0__33CBB62D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_0__33CBB62D = (int)&(((struct dw_2835393_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_1__B94560E3_DEFINED
#define DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_1__B94560E3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_1__B94560E3 = (int)&(((struct dw_2835393_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_2__59A2B3DB_DEFINED
#define DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_2__59A2B3DB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_2__59A2B3DB = (int)&(((struct dw_2835393_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_3__00C9C137_DEFINED
#define DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_3__00C9C137_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_3__00C9C137 = (int)&(((struct dw_2835393_fields *)0)->Pos[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2835393_FIELDS_BERASE_391D21D5_DEFINED
#define DCOMP_OFF_STRUCT_DW_2835393_FIELDS_BERASE_391D21D5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2835393_FIELDS_BERASE_391D21D5 = (int)&(((struct dw_2835393_fields *)0)->bErase) - 0 };
#endif


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghMarker_SetTgtPos(unsigned char a0 , unsigned char a1 , unsigned char a2 );
void sghMarker_SetActPossible(unsigned char mkrID_, unsigned char komaID_, unsigned char dice_, unsigned char playerID_);
u32 sghMarker_GetTgtPosNum(void);
u8 * sghMarker_MarkerClear(void);

void sghMarker_SetTgtPos(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */, unsigned char a2 /* r6 */) {
    u8 *obj;
    u8 *tbl;
    s32 row;
    u32 xt1;
    s32 col;
    float *pos;
    u8 *posTbl;

    tbl = (u8 *)sghMap_GetMainTblMap();
    posTbl = tbl + 0x40;
    obj = MdlMng + ((((a0 + 0xbf)))) * 0x1c0;
    xt1 = *(tbl + ((s32)a2 << 5) + a1);
    row = xt1 >> 2;
    col = (xt1) & 3;
    if (a2 == 0) {
        xt1 = (u8)a1;
    } else {
        xt1 = 0x19 - a1;
    }
    pos = (float *)(posTbl + xt1 * 16);
    *(f32 *)(DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_0__33CBB62D + obj) = pos[0];
    *(f32 *)(DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_1__B94560E3 + obj) = pos[1] - 0.027f * (float)row;
    *(f32 *)(DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_2__59A2B3DB + obj) = pos[2] - 0.1f * (float)col;
    *(f32 *)(obj + DCOMP_OFF_STRUCT_DW_2835393_FIELDS_POS_3__00C9C137) = pos[3];
    *(u8 *)(obj + DCOMP_OFF_STRUCT_DW_2835393_FIELDS_BERASE_391D21D5) = 0;
}

void sghMarker_SetActPossible(unsigned char mkrID_, unsigned char komaID_, unsigned char dice_, unsigned char playerID_) {
    struct dw_2835182 tmplist = {0};

    tmplist.pos[1] = 0xff;
    tmplist.pos[0] = komaID_;
    sghEneThk_GetActIsPossible(tmplist.pos, tmplist.pos, dice_);
    if (tmplist.pos[0] != 0xff) {
        sghMarker_SetTgtPos(mkrID_, (unsigned char)(komaID_ + dice_), playerID_);
    }
}

/* sghMarker_GetTgtPosNum @ 0x20C970 .. 0x20C9A8 (0x38 bytes) */

u32 sghMarker_GetTgtPosNum(void) {
    u32 v1;
    s32 v0;

    v1 = *(u8 *)((u8 *)&MdlMng + 0x14e42);
    v0 = 0;
    if (v1 == 0) {
        v0 = v0 + 1;
    }
    v1 = *(u8 *)((u8 *)&MdlMng + 0x15002);
    if (v1 == 0) {
        v0 = v0 + 1;
    }
    return v0;
}

u8 * sghMarker_MarkerClear(void) {
    u8 *a0;

    a0 = (u8 *)MdlMng + 0x14e40;
    *(u8 *)(((u8 *)a0 + 2)) = 1;
    *(u8 *)(((u8 *)a0 + 0x1c2)) = 1;
    return;
}
