#include "common.h"

extern unsigned int CheckEneRollState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetEneAttackOff(void *, void *);
extern int rand();

struct dw_1614069_fields;
struct dw_1619545_fields;
struct dw_1622536_fields;
struct dw_1621669_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
struct dw_1621431_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
struct dw_1621109_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1614069_fields *lpMdl; };
struct dw_1614069_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1622536_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1614069_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1621669_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1621431_fields flags; unsigned char _pad1[3]; struct dw_1621109_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
struct dw_1624174_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
struct dw_1619310_fields { struct dw_1619545_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
struct dw_1616782_fields { struct dw_1624174_fields func; struct dw_1619310_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_1614069_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_1614069_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };

typedef void (*P027ActFn)(void *, void *, unsigned short);

/* P027ThkStay @ 0x1A5A00 .. 0x1A5A4C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckEneAttackState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P027ThkInit(s32 a0 , u32 *a1 );
static void P027ThkStay(void *a0 , void *a1 );
static unsigned int CheckP027StayState(struct dw_1614069_fields *lpEne, struct dw_1616782_fields *lpCtrl);


/* P027ThkInit @ 0x1A5A50 .. 0x1A5A60 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P027ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)a1 = (u32)P027ThkStay;
    return;
}

static void P027ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckEneAttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckP027StayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}




static unsigned int CheckP027StayState(struct dw_1614069_fields *lpEne, struct dw_1616782_fields *lpCtrl) {
    void *lpAnimCtrl;

    lpAnimCtrl = lpEne->lpAnimCtrl;
    if (lpEne->Target.lpMdl != 0) {
        if (CheckEneRollState(lpEne, lpCtrl)) {
            return 1;
        }
        if (lpEne->Target.lpMdl->TeamNo != lpEne->TeamNo) {
            switch (lpEne->IndexAnim) {
            case 0xe:
            case 1:
            case 0x5a:
            case 0x5c:
                break;
            case 0x5b:
                ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5e);
                break;
            case 0x5d:
                ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5f);
                break;
            case 0x5e:
            case 0x5f:
                if (CheckAnimEndFrame(lpAnimCtrl)) {
                    ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 1);
                }
                break;
            case 0:
                ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 1);
                return 1;
            case 2:
                if (lpCtrl->attackOff == 0) {
                    ((P027ActFn)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xb);
                } else {
                    if (CheckAnimEndFrame(lpAnimCtrl)) {
                        SetEneAttackOff(lpEne, lpCtrl);
                    }
                }
                return 1;
            default:
                ((P027ActFn)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 5);
                return 1;
            }
        } else {
            if (lpEne->Target.distXZ > lpEne->HitSize + lpEne->Target.lpMdl->HitSize + 0.3f + 0.3f) {
                switch (lpEne->IndexAnim) {
                case 0x5a:
                case 0x5c:
                    break;
                case 0x5b:
                    ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5e);
                    break;
                case 0x5d:
                    ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5f);
                    break;
                case 0x5e:
                case 0x5f:
                    if (CheckAnimEndFrame(lpAnimCtrl)) {
                        ((P027ActFn)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 0xa);
                    }
                    break;
                case 0:
                case 2:
                    ((P027ActFn)lpCtrl->func.SetActFunc[1])(lpEne, lpCtrl, 5);
                    break;
                }
                return 1;
            }
            switch (lpEne->IndexAnim) {
            case 0:
                if (CheckAnimEndFrame(lpAnimCtrl)) {
                    ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5a);
                }
                break;
            case 0x5b:
                if (CheckAnimEndFrame(lpAnimCtrl)) {
                    if (rand() % 100 < 0x14) {
                        ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5c);
                    }
                }
                break;
            case 0x5e:
            case 0x5f:
                if (CheckAnimEndFrame(lpAnimCtrl)) {
                    ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0);
                }
                break;
            }
        }
    } else {
        switch (lpEne->IndexAnim) {
        case 0x5a:
        case 0x5c:
        case 0x5b:
            break;
        case 0x5d:
            ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5f);
            break;
        case 0x5f:
            if (CheckAnimEndFrame(lpAnimCtrl)) {
                ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5a);
            }
            break;
        default:
            ((P027ActFn)lpCtrl->func.SetActFunc[0])(lpEne, lpCtrl, 0x5a);
            break;
        }
    }
    return 0;
}
