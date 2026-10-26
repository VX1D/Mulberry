#include "common.h"

/* P007ThkStay @ 0x191020 .. 0x1910DC (0xbc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x191094
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern unsigned int CheckAnimParam(void *, signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);

struct dw_1338039_fields;
struct dw_1338453_fields;
struct dw_1345239_fields;
#ifndef PROTO_DW_1344374_FIELDS
#define PROTO_DW_1344374_FIELDS
struct dw_1344374_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1344136_FIELDS
#define PROTO_DW_1344136_FIELDS
struct dw_1344136_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1343814_FIELDS
#define PROTO_DW_1343814_FIELDS
struct dw_1343814_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1338453_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1338453_FIELDS
#define PROTO_DW_1338453_FIELDS
struct dw_1338453_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1345239_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1338453_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1344374_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1344136_fields flags; unsigned char _pad1[3]; struct dw_1343814_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1346876_FIELDS
#define PROTO_DW_1346876_FIELDS
struct dw_1346876_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_1337804_FIELDS
#define PROTO_DW_1337804_FIELDS
struct dw_1337804_fields { struct dw_1338039_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_1341130_FIELDS
#define PROTO_DW_1341130_FIELDS
struct dw_1341130_fields { struct dw_1346876_fields func; struct dw_1337804_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_1338453_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_1338453_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73_DEFINED
#define DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73 = (int)&(((struct dw_1338453_fields *)0)->AttackNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1338453_FIELDS_HP_ECA3FE66_DEFINED
#define DCOMP_OFF_STRUCT_DW_1338453_FIELDS_HP_ECA3FE66_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1338453_FIELDS_HP_ECA3FE66 = (int)&(((struct dw_1338453_fields *)0)->Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1338453_FIELDS_TARGET_LPMDL_D6DA68E2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1338453_FIELDS_TARGET_LPMDL_D6DA68E2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1338453_FIELDS_TARGET_LPMDL_D6DA68E2 = (int)&(((struct dw_1338453_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1341130_FIELDS_FUNC_ACTID_F4467962_DEFINED
#define DCOMP_OFF_STRUCT_DW_1341130_FIELDS_FUNC_ACTID_F4467962_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1341130_FIELDS_FUNC_ACTID_F4467962 = (int)&(((struct dw_1341130_fields *)0)->func.actID) - 0 };
#endif

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P007ThkInit(s32 a0 , u32 *a1 );
static void P007ThkStay(void *a0 , void *a1 );



/* P007ThkInit @ 0x1910E0 .. 0x1910F0 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P007ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)a1 = (u32)P007ThkStay;
    return;
}
static void P007ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 v0;
    u32 v1;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 == 0) {
        v1 = 0;
    } else {
        v0 = EneSearchAttackRange((u32)s1, (u32)s0, 0);
        if (v0 != 0) {
            v0 = CheckAnimParam((void *)*(s32 *)(s1 +
                DCOMP_OFF_STRUCT_DW_1338453_FIELDS_TARGET_LPMDL_D6DA68E2), 0x22);
            if (v0 != 0) {
                *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73) = 0;
            } else {
                *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73) = 1;
            }
            v0 = *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_1338453_FIELDS_ATTACKNO_0CF86B73);
            ChangeAnimParam((void *)s1, (u16)(v0 + 0x32), 0.0f);
            *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1341130_FIELDS_FUNC_ACTID_F4467962) = 4;
            *(u32 *)(s1 + DCOMP_OFF_STRUCT_DW_1338453_FIELDS_HP_ECA3FE66) = 0;
            v1 = 1;
        } else {
            v1 = 0;
        }
    }
    if (v1 == 0) {
        return;
    }
    return;
}
