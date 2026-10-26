#include "common.h"

/* CheckP019AttackState @ 0x1A6970 .. 0x1A6A64 (0xf4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: lui at 0x1a6a24 writes a register its branch at 0x1a6a20 reads
 *   fpu: float literal 0x41f00000 at 0x1a6a2c
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern signed int SFX_Delete();
extern signed int SFX_Create_OnAng_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern signed int SND_Play3D(signed int, signed short, signed short, void *, float);
extern u32 VW[];
extern u32 V0[];

struct dw_1705645;
struct dw_1706059;
struct dw_1712845;
#ifndef PROTO_DW_1712042
#define PROTO_DW_1712042
struct dw_1712042 { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1711804
#define PROTO_DW_1711804
struct dw_1711804 { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1711482
#define PROTO_DW_1711482
struct dw_1711482 { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1706059 *lpMdl; };
#endif
#ifndef PROTO_DW_1706059
#define PROTO_DW_1706059
struct dw_1706059 { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1712845 *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1706059 *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1712042 DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1711804 flags; unsigned char _pad1[3]; struct dw_1711482 Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1714482
#define PROTO_DW_1714482
struct dw_1714482 { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_1705410
#define PROTO_DW_1705410
struct dw_1705410 { struct dw_1705645 *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_1708736
#define PROTO_DW_1708736
struct dw_1708736 { struct dw_1714482 func; struct dw_1705410 key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_1706059 *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_1706059 *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P019ThkInit(s32 a0 , u32 *a1 );
static void P019ThkStay(struct dw_1706059 *lpEne, struct dw_1708736 *lpCtrl);
static unsigned int CheckP019AttackState(struct dw_1706059 *a0 , struct dw_1708736 *a1 );



/* P019ThkInit @ 0x1A6A90 .. 0x1A6AA0 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * P019ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)a1 = (u32)P019ThkStay;
    return;
}

static void P019ThkStay(struct dw_1706059 *lpEne, struct dw_1708736 *lpCtrl) {
    if (CheckP019AttackState(lpEne, lpCtrl)) {
        return;
    }
}

static unsigned int CheckP019AttackState(struct dw_1706059 *a0 /* r4 */, struct dw_1708736 *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 a2;
    struct dw_1708736 *v1;
    u32 v0;

    s1 = (u8 *)a0;
    a2 = (s32)a0->Target.lpMdl;
    s0 = (u8 *)a1;
    if (a2 == 0) {
        v0 = 0;
    } else {
        v1 = (struct dw_1708736 *)*(u8 *)((a2 + 0x128));
        v0 = *(u8 *)(s1 + 0x128);
        if ((u32)v1 != v0) {
            v1 = (struct dw_1708736 *)*(s32 *)((a2 + 0x148));
            v0 = (s32)v1->lpP019;
            if (v0 == 0) {
                v1->lpP019 = (void *)(s1);
                ((void (*)(void *, void *, s32))(s32)*(s32 *)(s0 + 0x100))((void *)a0, (void *)a1,
                    2);
                *(u8 *)(s0 + 0x244) = 0xa;
                SFX_Delete(*(s32 *)(s0 + 0x200), (u32)1);
                v1 = (struct dw_1708736 *)(s32)-1;
                *(u32 *)(s0 + 0x200) = (u32)v1;
                v0 = *(s32 *)(s0 + 0x204);
                if (v0 == (u32)v1) {
                    a1 = (void *)VW;
                    a2 = (u32)V0;
                    v0 = SFX_Create_OnAng_Attach(0x1b5, (float *)VW, (float *)V0, (void *)(u8 *)s1,
                        0, 0, 0);
                    *(u32 *)(s0 + 0x204) = v0;
                }
                v1 = (struct dw_1708736 *)*(s32 *)(s0 + 0x224);
                v0 = 0x51;
                if ((u32)v1 == v0) {
                    v0 = SND_Play3D(0x88e, 0x64, 0x12c, (void *)(u8 *)(s1 + 0x20), 30.0f);
                    *(u32 *)(s0 + 0x224) = v0;
                }
            }
        }
        v0 = 0;
    }
    return v0;
}
