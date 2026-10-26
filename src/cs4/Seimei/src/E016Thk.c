#include "common.h"

/* CheckE016WalkState @ 0x18E260 .. 0x18E6AC (0x44c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490624 at 0x18e45c
 *   fpu: float literal 0x40490fdb at 0x18e464
 *   fpu: float literal 0x00000000 at 0x18e468
 *   fpu: float literal 0x40c90fdb at 0x18e488
 *   fpu: mtc1 reinterprets v0 at 0x18e4ac
 *   fpu: float literal 0x40490624 at 0x18e4f0
 *   fpu: float literal 0x40490fdb at 0x18e4f8
 *   fpu: float literal 0x00000000 at 0x18e4fc
 *   fpu: float literal 0x40c90fdb at 0x18e51c
 *   fpu: mtc1 reinterprets v0 at 0x18e540
 *   fpu: float literal 0x3eb2b020 at 0x18e580
 *   fpu: float literal 0x40490fdb at 0x18e58c
 *   fpu: float literal 0x00000000 at 0x18e590
 *   fpu: float literal 0x40c90fdb at 0x18e5b0
 *   fpu: mtc1 reinterprets v0 at 0x18e5d4
 *   fpu: float literal 0x3eb2b020 at 0x18e618
 *   fpu: float literal 0x40490fdb at 0x18e624
 *   fpu: float literal 0x00000000 at 0x18e628
 *   fpu: float literal 0x40c90fdb at 0x18e648
 *   fpu: mtc1 reinterprets v0 at 0x18e66c
 *   cfg: kept goto: 0x18e298 -> .L0018E690
 *   cfg: kept branch: 0x18e2b8 if (..) goto .L0018E690
 *   cfg: kept goto: 0x18e340 -> .L0018E690
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern int rand();

struct dw_1247081_fields;
struct dw_1251978_fields;
struct dw_1254818_fields;
#ifndef PROTO_DW_1254015_FIELDS
#define PROTO_DW_1254015_FIELDS
struct dw_1254015_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1253777_FIELDS
#define PROTO_DW_1253777_FIELDS
struct dw_1253777_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1253455_FIELDS
#define PROTO_DW_1253455_FIELDS
struct dw_1253455_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1247081_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1247081_FIELDS
#define PROTO_DW_1247081_FIELDS
struct dw_1247081_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1254818_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1247081_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1254015_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1253777_fields flags; unsigned char _pad1[3]; struct dw_1253455_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1256455_FIELDS
#define PROTO_DW_1256455_FIELDS
struct dw_1256455_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_1251743_FIELDS
#define PROTO_DW_1251743_FIELDS
struct dw_1251743_fields { struct dw_1251978_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_1249774_FIELDS
#define PROTO_DW_1249774_FIELDS
struct dw_1249774_fields { struct dw_1256455_fields func; struct dw_1251743_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_1247081_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_1247081_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1247081_FIELDS_POS_1__90ED7728_DEFINED
#define DCOMP_OFF_STRUCT_DW_1247081_FIELDS_POS_1__90ED7728_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1247081_FIELDS_POS_1__90ED7728 = (int)&(((struct dw_1247081_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_ANGY_3663E5CD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_ANGY_3663E5CD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_ANGY_3663E5CD = (int)&(((struct dw_1247081_fields *)0)->Target.angY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_LPMDL_7E49B471_DEFINED
#define DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_LPMDL_7E49B471_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1247081_FIELDS_TARGET_LPMDL_7E49B471 = (int)&(((struct dw_1247081_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_SETACTFUNC_1__4ABD6982_DEFINED
#define DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_SETACTFUNC_1__4ABD6982_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_SETACTFUNC_1__4ABD6982 = (int)&(((struct dw_1249774_fields *)0)->func.SetActFunc[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_ACTID_99969BD2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_ACTID_99969BD2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1249774_FIELDS_FUNC_ACTID_99969BD2 = (int)&(((struct dw_1249774_fields *)0)->func.actID) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1249774_FIELDS_STAYTIMER_C15B5257_DEFINED
#define DCOMP_OFF_STRUCT_DW_1249774_FIELDS_STAYTIMER_C15B5257_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1249774_FIELDS_STAYTIMER_C15B5257 = (int)&(((struct dw_1249774_fields *)0)->stayTimer) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1249774_FIELDS_WALKTIMER_2F03A54A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1249774_FIELDS_WALKTIMER_2F03A54A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1249774_FIELDS_WALKTIMER_2F03A54A = (int)&(((struct dw_1249774_fields *)0)->walkTimer) - 0 };
#endif
#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
typedef void (*E016ActFunc)(void *, void *, s32);

/* E016ThkWalk @ 0x18E6D0 .. 0x18E700 (0x30 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE016WalkState(void *, void *);

/* E016ThkStay @ 0x18E700 .. 0x18E730 (0x30 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE016WalkState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void E016ThkInit(void *a0 , u32 *a1);
static void E016ThkAppear(void);
static void E016ThkStay(void *a0 , void *a1 );
static void E016ThkWalk(void *a0 , void *a1 );
static void E016ThkDamage(void);
static void E016ThkDead(void);
static unsigned int CheckE016WalkState(void *lpEne_, void *lpCtrl_);


/* E016ThkInit @ 0x18E740 .. 0x18E780 (0x40 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u8 *; 1 parameters vs 2 inferred
 */

void E016ThkInit(void *a0 /* r4 */, u32 *a1) {
    u8 *v1;

    v1 = (u8 *)E016ThkAppear;
    *(u32 *)(((u8 *)a1 + 0x14)) = (u32)E016ThkAppear;
    v1 = (u8 *)E016ThkStay;
    *(u32 *)a1 = (u32)E016ThkStay;
    v1 = (u8 *)E016ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E016ThkWalk;
    v1 = (u8 *)E016ThkDamage;
    *(u32 *)(((u8 *)a1 + 0xc)) = (u32)E016ThkDamage;
    v1 = (u8 *)E016ThkDead;
    *(u32 *)(((u8 *)a1 + 0x10)) = (u32)E016ThkDead;
    return;
}

/* E016ThkAppear @ 0x18E730 .. 0x18E738 (0x8 bytes) */

static void E016ThkAppear(void) {
    return;
}

static void E016ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u16 *s0;
    u32 v1;

    s0 = (u16 *)a1;
    CheckE016WalkState(a0, a1);
    v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
    v1 = v1 + 1;
    *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    return;
}

static void E016ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u16 *s0;
    u32 v1;

    s0 = (u16 *)a1;
    CheckE016WalkState(a0, a1);
    v1 = *(u16 *)(((u8 *)s0 + 0x1de));
    v1 = v1 + 1;
    *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    return;
}

/* E016ThkDamage @ 0x18E6C0 .. 0x18E6C8 (0x8 bytes) */

static void E016ThkDamage(void) {
    return;
}


/* E016ThkDead @ 0x18E6B0 .. 0x18E6B8 (0x8 bytes) */

static void E016ThkDead(void) {
    return;
}
static unsigned int CheckE016WalkState(void *lpEne_, void *lpCtrl_) {
    struct dw_1247081_fields *lpEne = (struct dw_1247081_fields *)lpEne_;
    struct dw_1249774_fields *lpCtrl = (struct dw_1249774_fields *)lpCtrl_;
    int rnd;

    if ((u32)lpEne->Target.lpMdl != 0) {
        switch (lpCtrl->func.actID) {
        case 0:
            ((E016ActFunc)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xa);
            return 1;
        case 1:
            if (lpCtrl->walkTimer % (rand() % 0x14 + 0x32) == 0) {
                if (lpCtrl->bDash == 0) {
                    ((E016ActFunc)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xa);
                }
                if (lpCtrl->bDash == 1) {
                    ((E016ActFunc)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xb);
                }
                lpCtrl->walkTimer = 0;
                lpEne->Pos[1] = -1.35f;
            }
            break;
        }
    } else {
        switch (lpCtrl->func.actID) {
        case 0:
            if (lpCtrl->stayTimer > 0x78 && rand() % 100 < 10) {
                ((E016ActFunc)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xa);
                lpEne->Pos[1] = -1.35f;
            }
            break;
        case 1:
            if (lpCtrl->walkTimer % (rand() % 0x14 + 0x32) == 0) {
                rnd = rand() % 100;
                ((E016ActFunc)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xa);
                lpEne->Pos[1] = -1.35f;
                if (rnd < 10) {
                    lpEne->Target.angY = WRAPF(3.1409998f + lpEne->Target.angY);
                } else if (rnd < 0x14) {
                    lpEne->Target.angY = WRAPF(lpEne->Target.angY - 3.1409998f);
                } else if (rnd < 0x32) {
                    lpEne->Target.angY = WRAPF(0.34899998f + lpEne->Target.angY);
                } else if (rnd < 0x50) {
                    lpEne->Target.angY = WRAPF(lpEne->Target.angY - 0.34899998f);
                }
            }
            break;
        }
    }
    return 0;
}
