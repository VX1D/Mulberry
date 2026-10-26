#include "common.h"

/* P020SearchTarget @ 0x1A8500 .. 0x1A879C (0x29c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1a8540
 *   fpu: mtc1 reinterprets a0 at 0x1a8558
 *   fpu: float literal 0x42c80000 at 0x1a8570
 *   fpu: mtc1 reinterprets v1 at 0x1a858c
 *   fpu: mtc1 reinterprets a0 at 0x1a85a4
 *   fpu: float literal 0x41200000 at 0x1a85bc
 *   fpu: float literal 0x47c35000 at 0x1a85d8
 *   fpu: float literal 0x3c8ef34d at 0x1a85ec
 *   delay: addiu at 0x1a8648 writes a register its branch at 0x1a8644 reads
 *   fpu: mov.s at 0x1a8690 is a float copy
 *   fpu: mov.s at 0x1a86c0 is a float copy
 *   fpu: float literal 0x00000000 at 0x1a86c4
 *   fpu: mov.s at 0x1a86e0 is a float copy
 *   fpu: mov.s at 0x1a86f4 is a float copy
 *   fpu: float literal 0x3f4ccccd at 0x1a8710
 *   fpu: float literal 0x3f800000 at 0x1a8730
 *   fpu: mov.s at 0x1a8750 is a float copy
 *   cfg: loop body is not one contiguous region: .L001A85F8
 *   cfg: kept branch: 0x1a862c if (..) goto .L001A8758
 *   cfg: kept branch: 0x1a863c if (..) goto .L001A8758
 *   cfg: kept branch: 0x1a8648 if (..) goto .L001A8758
 *   cfg: kept branch: 0x1a8654 if (..) goto .L001A8758
 *   cfg: kept branch: 0x1a8720 if (..) goto .L001A8758
 *   declaration vs inferred signature: return void vs inferred u32; 2 parameters vs 3 inferred
 */

extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern float CheckHitObstructMdl(void *, void *, float);

struct dw_1775957_fields;
struct dw_1781269_fields;
#ifndef PROTO_DW_1780428_FIELDS
#define PROTO_DW_1780428_FIELDS
struct dw_1780428_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1780044_FIELDS
#define PROTO_DW_1780044_FIELDS
struct dw_1780044_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1779722_FIELDS
#define PROTO_DW_1779722_FIELDS
struct dw_1779722_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1775957_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1775957_FIELDS
#define PROTO_DW_1775957_FIELDS
struct dw_1775957_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1781269_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1775957_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1780428_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1780044_fields flags; unsigned char _pad1[3]; struct dw_1779722_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1782669_FIELDS
#define PROTO_DW_1782669_FIELDS
struct dw_1782669_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_1781269_FIELDS
#define PROTO_DW_1781269_FIELDS
struct dw_1781269_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_1782669_fields DmyPoly[32]; };
#endif

extern struct dw_1775957_fields MdlMng[];
struct dw_1771894 { u8 pad[0x12]; u16 a; u16 b; };


/* P020ActAppear (0x158 bytes) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x1a8834
 *   stack: address of the slot at 0x40 escapes at 0x1a88a0
 *   stack: address of the slot at 0x5c escapes at 0x1a88a0
 *   cfg: kept goto: 0x1a87e8 -> .L001A88D0
 *   cfg: kept goto: 0x1a8880 -> .L001A88D0
 *   declaration vs inferred signature: return void vs inferred u_long128
 */

extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern void sceVu0CopyVector(void *, void *);
extern signed int SFX_Create_OnDir_Dmg2(unsigned short, float *, float *, unsigned char, unsigned
    char, void *);
extern void EneDeadProc(void *, void *);
extern u32 V0[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 P020ActInit(s32 a0 , u8 *a1 );
static void P020ActAppear(void *a0 , void *a1 );
static void P020SearchTarget(struct dw_1775957_fields *lpEne, void *unused, int bFailed);



/* P020ActInit @ 0x1A8900 .. 0x1A8918 (0x18 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u32 P020ActInit(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)P020ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P020ActAppear;
    v1 = (u8 *)1;
    *(u8 *)(((u8 *)a1 + 0x24d)) = 1;
    return;
}

static void P020ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 a2;
    u8 *s0;
    u32 v1;
    u32 v0;
    float f12;
    float f0;
    void *a0_2;
    u8 stackFrame_5C[4] __attribute__((aligned(4)));
    u8 stackFrame_40[16] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    a2 = *(u16 *)(((u8 *)a1 + 0x1dc));
    s0 = (u8 *)*(s32 *)((v1 + 0x4c));
    s1 = (u8 *)a1;
    if (a2 == 0) {
        v0 = 0x3f800000;
        *(u32 *)(s2 + 0x10c) = 0x3f800000;
        P020SearchTarget(a0, a1, 0);
        v0 = *(s32 *)(s2 + 0x1b4);
        if (v0 != 0) {
            *(u8 *)(*(s32 *)(v0 + 0x148) + 0x245) = 0x3c;
            SFX_Create_OnAng(0x1b0, (float *)(*(s32 *)(s2 + 0x1b4) + 0x20), (float *)V0);
            goto _L001A88D0;
        }
        a0_2 = (void *)s2;
        a1 = (void *)s1;
        P020SearchTarget(a0_2, a1, (s32)1);
        v0 = *(s32 *)(s2 + 0x1b4);
        a1 = (void *)(s32)(v0 + 0x20);
        if (v0 != 0) {
            sceVu0CopyVector((void *)((u8 *)&stackFrame_40[0]), a1);
        } else {
            f12 = *(float *)(s2 + 0x34);
            f0 = sinf(f12);
            *(f32 *)((u8 *)&stackFrame_40[0]) = (*(float *)(s2 + 0x20) - f0);
            f12 = *(float *)(s2 + 0x34);
            f0 = cosf(f12);
            v0 = 0x3f800000;
            ((f32 *)stackFrame_40)[2] = (*(float *)(s2 + 0x28) - f0);
            ((f32 *)stackFrame_40)[1] = *(float *)(s2 + 0x24);
            ((u32 *)stackFrame_40)[3] = 0x3f800000;
        }
        *(u32 *)(s2 + 0x1b4) = 0;
        *(u32 *)((u8 *)&stackFrame_5C[0]) = (u32)s2;
        a0_2 = (void *)(s32)0x1b8;
        a2 = (u32)V0;
        SFX_Create_OnDir_Dmg2((unsigned short)a0_2, (float *)((u8 *)&stackFrame_40[0]), (float
            *)V0, *(u8 *)s0, *(u8 *)(s2 + 0x12a), (void *)(u8 *)((u8 *)&stackFrame_5C[0]));
        goto _L001A88D0;
    } else {
        v1 = 0x3c;
        if (a2 == v1) {
            EneDeadProc(a0, a1);
        } else {
            _L001A88D0:;
            v1 = *(u16 *)(s1 + 0x1dc);
            v1 = v1 + 1;
            *(u16 *)(s1 + 0x1dc) = v1;
        }
    }
    return;
}
static void P020SearchTarget(struct dw_1775957_fields *lpEne, void *unused, int bFailed) {
    struct dw_1775957_fields *lpTarget;
    u8 *lpTargetCtrl;
    float xx;
    float zz;
    float angY;
    float dist;
    float distMax;
    float searchMax;
    float searchAng;
    float HitHigh;
    struct dw_1771894 *lpEnePrm;

    lpEnePrm = (struct dw_1771894 *)lpEne->lpMdlData->lpPrm;
    searchMax = (float)lpEnePrm->a / 100.0f;
    searchAng = (float)lpEnePrm->b / 10.0f;
    lpEne->Target.lpMdl = 0;
    distMax = 100000.0f;
    for (lpTarget = &MdlMng[161]; lpTarget != &MdlMng[219]; lpTarget++) {
        if (lpTarget->bUse == 0 || lpTarget->TeamNo == lpEne->TeamNo) {
            continue;
        }
        lpTargetCtrl = (u8 *)lpTarget->lpCtrlSt;
        if (lpTargetCtrl[0x245] != 0) {
            continue;
        }
        if (bFailed == 0) {
            if (lpTargetCtrl[0x180] != 7) {
                continue;
            }
            if (lpTarget->IndexAnim == 0x1f || lpTarget->IndexAnim == 0x21 || lpTarget->IndexAnim == 0x23) {
                continue;
            }
        }
        xx = lpTarget->Pos[0] - lpEne->Pos[0];
        zz = lpTarget->Pos[2] - lpEne->Pos[2];
        angY = Math_VectorToAngle(-xx, -zz);
        dist = sqrtf(xx * xx + zz * zz) - lpTarget->HitSize;
        if (dist > searchMax) {
            continue;
        }
        if (dist > distMax) {
            continue;
        }
        if ((Math_GetAngleDist(lpEne->Ang[1], angY) < 0.0f ? -Math_GetAngleDist(lpEne->Ang[1], angY) : Math_GetAngleDist(lpEne->Ang[1], angY)) > 0.01745f * searchAng) {
            continue;
        }
        HitHigh = 0.8f * lpEne->HitHigh;
        if (lpEne->MapHitOff == 0) {
            if (CheckHitObstructMdl(lpEne, lpTarget, HitHigh) < 1.0f) {
                continue;
            }
        }
        lpEne->Target.lpMdl = lpTarget;
        lpEne->Target.angY = angY;
        distMax = dist;
        lpEne->Target.distXZ = dist;
    }
}
