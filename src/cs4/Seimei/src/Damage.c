#include "common.h"

/* CheckFinishAttack @ 0x15AC30 .. 0x15AD20 (0xf0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x15ac90 writes a register its branch at 0x15ac8c reads
 *   delay: daddu at 0x15acd4 writes a register its branch at 0x15acd0 reads
 *   cfg: kept branch: 0x15ac34 if (..) goto .L0015AC88
 *   cfg: kept goto: 0x15ac80 -> .L0015AD08
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned int CheckAnimParam(void *, signed int);
extern signed int CheckEneFlick(void *);

extern void *GetEneParam(signed int, unsigned char);


u32 DamageNum;
/* DamageProc @ 0x15AE80 .. 0x15B1F8 (0x378 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x80 escapes at 0x15aec8
 *   stack: address of the slot at 0x88 escapes at 0x15aec8
 *   stack: address of the slot at 0x89 escapes at 0x15aec8
 *   stack: address of the slot at 0x70 escapes at 0x15afd0
 *   stack: address of the slot at 0x70 escapes at 0x15afe0
 *   stack: address of the slot at 0x70 escapes at 0x15b000
 *   stack: address of the slot at 0x70 escapes at 0x15b01c
 *   stack: address of the slot at 0x70 escapes at 0x15b12c
 *   stack: address of the slot at 0x70 escapes at 0x15b13c
 *   stack: address of the slot at 0x70 escapes at 0x15b15c
 *   stack: address of the slot at 0x70 escapes at 0x15b178
 *   cfg: loop body is not one contiguous region: .L0015AEC8
 *   cfg: loop body is not one contiguous region: .L0015AEE0
 *   cfg: kept branch: 0x15af58 if (..) goto .L0015AF70
 *   cfg: kept goto: 0x15af68 -> .L0015AF98
 *   cfg: kept branch: 0x15afb4 if (..) goto .L0015B040
 *   cfg: loop body is not one contiguous region: .L0015B068
 *   cfg: kept branch: 0x15b0e0 if (..) goto .L0015B0F8
 *   cfg: kept goto: 0x15b0f0 -> .L0015B120
 */

extern signed int CheckMyDamage(void *, void *);
extern u32 GetCamCtrlMode();
extern u32 StopPeepCamera();
extern void *memset(void *, int, unsigned int);
extern void sceVu0CopyVector(void *, void *);
extern signed int CheckP030Counter(void *, void *);
extern void SetMyDamageProc(void *);
extern signed int CheckEneDamage(void *);
extern void SetEneDamageProc(void *);

extern u8 DamageMng[];

struct dw_537447_fields;
struct dw_550631_fields;
#ifndef PROTO_DW_536739_FIELDS
#define PROTO_DW_536739_FIELDS
struct dw_536739_fields { struct dw_537447_fields *lpMaster; void *lpData; float Size; unsigned char TeamNo; unsigned char AttackNo; short DataId; void *lpFunc; int unused1[3]; float Pos[4]; };
#endif
#ifndef PROTO_DW_547131_FIELDS
#define PROTO_DW_547131_FIELDS
struct dw_547131_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_544594_FIELDS
#define PROTO_DW_544594_FIELDS
struct dw_544594_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_544272_FIELDS
#define PROTO_DW_544272_FIELDS
struct dw_544272_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_537447_fields *lpMdl; };
#endif
#ifndef PROTO_DW_537447_FIELDS
#define PROTO_DW_537447_FIELDS
struct dw_537447_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_550631_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_537447_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_547131_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_544594_fields flags; unsigned char _pad1[3]; struct dw_544272_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif


extern struct dw_537447_fields MdlMng[];
struct dw_545191_fields { float DmgPos[4]; struct dw_537447_fields *lpTarget; void *lpMasterPrm; unsigned char TeamNo; unsigned char AttackNo; unsigned short PauseTime; unsigned char bFinish; unsigned char unused[3]; float PowerScl; unsigned char _pad0[12]; };


u32 DamageNum;
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0CopyVector(void *, void *);

extern u8 GameSt[];
extern u8 DamageMng[];


/* InitDamageMng @ 0x15B300 .. 0x15B32C (0x2c bytes, frame 0x10) */

extern void *memset(void *, int, unsigned int);
u8 DamageMng[0x1800];
u32 DamageNum;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitDamageMng(void);
void SetDamageMng(void *model, unsigned char bone, void *position, float damage, unsigned char type, void *source, void *callback, signed short value, unsigned char flags);
void DamageProc(void);
static void GetDmgMasterPrm(void *object, signed short enemy, void *output);
static signed int CheckFinishAttack(void *a0 , void *a1 );


void InitDamageMng(void) {
    memset(DamageMng, 0, 0x1800);
    DamageNum = 0;
    return;
}
void SetDamageMng(void *model, unsigned char bone, void *position, float damage,
                  unsigned char type, void *source, void *callback, signed short value,
                  unsigned char flags) {
    u32 index;
    u32 count;
    u8 *entry;
    count = DamageNum;
    if (count <= 127) {
        index = GameSt[5];
        if (index == 0) {
            entry = (u8 *)((u8 *)DamageMng + count * 48);
            *(void **)entry = model;
            if (bone != 255) {
                sceVu0ApplyMatrix((void *)(entry + 0x20),
                    (void *)(*(u32 *)((u8 *)model + 0x10) + (u32)bone * 64), position);
            } else {
                sceVu0CopyVector((void *)(entry + 0x20), position);
            }
            *(float *)(entry + 8) = damage;
            *(u8 *)(entry + 0xc) = type;
            *(u8 *)(entry + 0xd) = flags;
            *(s16 *)(entry + 0xe) = value;
            *(void **)(entry + 4) = source;
            *(void **)(entry + 0x10) = callback;
            DamageNum++;
        }
    }
}

void DamageProc(void) {
    struct dw_536739_fields *lpDamage;
    u8 *pd;
    struct dw_537447_fields *lpTarget;
    struct dw_545191_fields DmgPrm;

    for (pd = DamageMng; pd != DamageMng + DamageNum * 0x30; pd += 0x30) {
        lpDamage = (struct dw_536739_fields *)pd;
        for (lpTarget = &MdlMng[160]; lpTarget != &MdlMng[161]; lpTarget++) {
            if (CheckMyDamage(lpTarget, lpDamage->lpMaster) == 0) continue;
            if (lpDamage->lpMaster != 0 && lpDamage->lpMaster == lpTarget) continue;
            if (lpTarget->TeamNo == lpDamage->TeamNo) continue;
            {
                float size = lpDamage->Size;
                float dx = lpTarget->Pos[0] - lpDamage->Pos[0];
                float dy = lpTarget->Pos[1] - lpDamage->Pos[1];
                float dz = lpTarget->Pos[2] - lpDamage->Pos[2];
                float hh = lpTarget->HitHigh + size;
                float hs = lpTarget->HitSize + size;
                int hit;
                if (dy > hh || dy < -size) {
                    hit = 0;
                } else {
                    if (!(dx * dx + dz * dz <= hs * hs)) { hit = 0; } else { hit = 1; }
                }
                if (hit == 0) continue;
            }
            if (GetCamCtrlMode() == 2) {
                if (StopPeepCamera() == 0) continue;
            }
            memset(&DmgPrm, 0, sizeof(DmgPrm));
            DmgPrm.lpTarget = lpTarget;
            sceVu0CopyVector(&DmgPrm, lpDamage->Pos);
            DmgPrm.TeamNo = lpDamage->TeamNo;
            DmgPrm.AttackNo = lpDamage->AttackNo;
            GetDmgMasterPrm(lpDamage->lpMaster, lpDamage->DataId, &DmgPrm);
            if (CheckP030Counter(&DmgPrm, lpDamage->lpMaster) != 0) continue;
            SetMyDamageProc(&DmgPrm);
            if (lpDamage->lpFunc != 0) {
                ((void (*)(void *, void *))lpDamage->lpFunc)(lpDamage->lpData, lpTarget);
            }
        }
        for (lpTarget = &MdlMng[161]; lpTarget != &MdlMng[219]; lpTarget++) {
            if (CheckEneDamage(lpTarget) == 0) continue;
            if (lpDamage->lpMaster != 0 && lpDamage->lpMaster == lpTarget) continue;
            if (lpTarget->TeamNo == lpDamage->TeamNo) continue;
            {
                float size = lpDamage->Size;
                float dx = lpTarget->Pos[0] - lpDamage->Pos[0];
                float dy = lpTarget->Pos[1] - lpDamage->Pos[1];
                float dz = lpTarget->Pos[2] - lpDamage->Pos[2];
                float hh = lpTarget->HitHigh + size;
                float hs = lpTarget->HitSize + size;
                int hit;
                if (dy > hh || dy < -size) {
                    hit = 0;
                } else {
                    if (!(dx * dx + dz * dz <= hs * hs)) { hit = 0; } else { hit = 1; }
                }
                if (hit == 0) continue;
            }
            memset(&DmgPrm, 0, sizeof(DmgPrm));
            DmgPrm.lpTarget = lpTarget;
            sceVu0CopyVector(&DmgPrm, lpDamage->Pos);
            DmgPrm.TeamNo = lpDamage->TeamNo;
            DmgPrm.AttackNo = lpDamage->AttackNo;
            GetDmgMasterPrm(lpDamage->lpMaster, lpDamage->DataId, &DmgPrm);
            if (CheckFinishAttack(lpDamage->lpMaster, &DmgPrm) == 0) continue;
            SetEneDamageProc(&DmgPrm);
            if (lpDamage->lpFunc != 0) {
                ((void (*)(void *, void *))lpDamage->lpFunc)(lpDamage->lpData, lpTarget);
            }
        }
    }
    DamageNum = 0;
}
static void GetDmgMasterPrm(void *object, signed short enemy, void *output)
{
    u8 *savedObject;
    u8 *result;
    u32 params;
    float scale;
    u32 model;
    u32 control;
    params = 0;
    savedObject = object;
    scale = 1.0f;
    result = output;
    if (savedObject != 0) {
        model = *(u32 *)(savedObject + 0xc);
        output = (void *)*(u32 *)(model + 0x4c);
        if (output == 0) goto noMaster;
        switch (*(u16 *)(model + 0xa)) {
        case 1: case 2: case 0:
            params = (u32)output;
            break;
        }
    } else {
noMaster:
        if (savedObject == 0 && enemy >= 0)
            params = (u32)GetEneParam(enemy, result[0x18]);
    }
    if (params != 0) {
        *(u32 *)(result + 0x14) = params;
        if (savedObject != 0) {
            s32 offset;
            offset = result[0x19] * 40;
            offset += (s32)params;
            control = *(u32 *)(savedObject + 0x148);
            if (*(u8 *)(offset + 0xb5) != 0) {
                float *animation = *(float **)(savedObject + 0x100);
                *(u16 *)(result + 0x1a) = (u32)(animation[3] - animation[0]);
            }
            model = *(u32 *)(savedObject + 0xc);
            switch (*(u16 *)(model + 0xa)) {
            case 1: case 2:
                scale = *(float *)(control + 0x250);
            }
        }
        *(float *)(result + 0x20) = scale;
    }
}

static signed int CheckFinishAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *a3;
    u8 *s1;
    u32 a2;
    u8 *a1_bytes; // a1
    u8 *s0;
    u32 v1;
    u32 v0;

    a1_bytes = (u8 *)a1;
    s1 = a1_bytes;
    a3 = (u8 *)*(s32 *)(a1_bytes + 0x10);
    s0 = (u8 *)*(s32 *)(a3 + 0x148);
    a2 = *(u8 *)(a1_bytes + 0x19);
    a1_bytes = (u8 *)(s32)((s32)((u8 *)*(s32 *)(a1_bytes + 0x14) + (s32)((u32)(s32)((u8 *)(s32)(a2
        << 2) + a2) << 3)) + 0xa0);
    v1 = *(u8 *)(s0 + 0x180);
    s2 = (u8 *)a0;
    if (v1 == (u32)7) {
        goto _L0015AC88;
    }
    v0 = 1;
    goto _L0015AD08;
    _L0015AC88:;
    if (*(u8 *)(a1_bytes + 0x10) == 0) {
        return 0;
    }
    if ((u32)s2 != 0 && *(u16 *)((*(s32 *)(s2 + 0xc) + 0xa)) == 0) {
        a1_bytes = (u8 *)(s32)0x35;
        v0 = CheckAnimParam(a0, (signed int)a1_bytes);
        if (v0 != 0) {
            v1 = *(s16 *)(s2 + 0x104);
            if (v1 != (u32)0x35) {
                return 0;
            }
        }
    }
    a0 = (void *)*(s32 *)(s1 + 0x10);
    v0 = CheckEneFlick(a0);
    if (v0 == 0) {
        v0 = 0;
    } else {
        *(u8 *)(s0 + 0x1d9) = 0;
        v0 = 1;
        *(u8 *)(s1 + 0x1c) = v0;
    }
    _L0015AD08:;
    return v0;
}
