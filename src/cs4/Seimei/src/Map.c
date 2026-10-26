#include "common.h"




extern u32 lpMapFile;
extern signed int CheckEventFlag(signed int);
extern void SetEventFlag(signed int);
extern u8 GameSt[];
extern u32 SaveEvent[];
extern void *memset(void *, int, unsigned int);
extern u32 KnMsgMng_CheckMsgNone(void);
extern u32 KnMsgMng_GetSelectNum(void);
extern void KnMenuMng_CallSave(void);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetMyControlOn(void);
extern void SetMyStay(void *, void *, unsigned short);
extern void ReadDramaData(signed int, signed int, signed int);
extern u8 MdlMng[];
extern signed int CheckHeartBeatEvent(void *);
extern signed int CheckItemUseEvent(unsigned short);
extern signed int CheckLookAtEvent(void *, float, float, float (*)[4]);
extern u32 MapSfxSt[];
extern unsigned int CheckDrawMapByCamParam(signed int);
extern signed int SFX_EnableDraw(signed int, signed int, unsigned short);
extern signed int SFX_EnableAction(signed int, signed int, unsigned short);
void SetMapSeData(void);
extern void SetMapSfxData();
extern void CheckAutoEvent(void *);
extern void CheckMapEventData(void *);
extern void *GetMdlInfoStart(signed int);
extern signed int GetMdlDataIndexFromMapMdlInfo(signed int, signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void *GetMapPartsInfoByCtrlId(signed int, signed int);
extern char * SearchFileName(char *);
extern void ChangeExtension(void *, char *, char *);
extern void ReadMdlBndFile(char *, signed int, void *);
u8 GetMapGlareID(void);
u8 * SetSaveDrama(void);
void InitSaveEvent(void);
void CheckSaveEvent(void);
signed int GetMapSfxHdl(signed int a0 /* r4 */);
void UpdateMapSfx(void);
void * GetMapPartsInfo(signed int a0 /* r4 */, signed int a1 /* r5 */);
void ReadMapMdlFile(void *a0 /* r4 */);
u8 * GetMapFileBuf(void);

/* GetMapFileBuf @ 0x14FB30 .. 0x14FB38 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x14fb34 computes the return value
 */





u8 * GetMapFileBuf(void) {
    return (u8 *)&lpMapFile;
}


/* RemapMapFile @ 0x14F930 .. 0x14FB30 (0x200 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0014FB00
 *   v1#17 is the pointer held in a0+0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */

#ifndef PROTO_DW_345414
#define PROTO_DW_345414
struct dw_345414 { float Pos[4]; float Ang[4]; float Scl[4]; int ModelID; int MdlKindId; unsigned int MapObjData; int unused1[1]; char Name[16]; };
#endif

void RemapMapFile(void *a0 /* r4 */) {
    s32 t3;
    s32 a1;
    struct dw_345414 *t2;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(s32 *)(a0_bytes + 0x20);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x20) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x24);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x24) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x28);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x28) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x2c);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x2c) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x30);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x30) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x34);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x34) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x38);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x38) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x3c);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x3c) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x40);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x40) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x44);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x44) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x48);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x48) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x4c);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x4c) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x50);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x50) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x54);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x54) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x58);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x58) = (s32)(a0_bytes + v1);
    }
    v1 = *(s32 *)(a0_bytes + 0x5c);
    if (v1 != 0) {
        *(u32 *)(a0_bytes + 0x5c) = (s32)(a0_bytes + v1);
    }
    a1 = (u32)(*(u16 *)(a0_bytes + 0x1e)) + (s32)((u32)(*(u16 *)(a0_bytes + 0x1c)) +
        (u32)((u32)(*(u16 *)(a0_bytes + 0x1a)) + (u32)((u32)(*(u16 *)(a0_bytes + 0x18)) +
        (s32)((u32)(*(u16 *)(a0_bytes + 0x16)) + (u32)((u32)(*(u16 *)(a0_bytes + 0x14)) +
        (s32)((u32)(*(u16 *)(a0_bytes + 0x10)) + (u32)(*(u16 *)(a0_bytes + 0x12))))))));
    t2 = (struct dw_345414 *)*(s32 *)(a0_bytes + 0x40);
    t3 = 0;
    if (0 < a1) {
        do {
            v1 = t2->MapObjData;
            if (v1 != 0) {
                t2->MapObjData = (u32)(s32)(a0_bytes + v1);
            }
            t3 = t3 + 1;
            v1 = t3 < a1;
            t2 = (struct dw_345414 *)(s32)((u32)t2 + 0x50);
        } while (v1 != 0);
    }
    return;
}









/* ReadMapMdlFile @ 0x14F760 .. 0x14F930 (0x1d0 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   literal: @5527 is the string '.bnd'
 *   stack: address of the slot at 0x40 escapes at 0x14f798
 *   stack: address of the slot at 0x40 escapes at 0x14f7b4
 *   stack: address of the slot at 0x40 escapes at 0x14f7c4
 *   stack: address of the slot at 0x40 escapes at 0x14f800
 *   stack: address of the slot at 0x40 escapes at 0x14f81c
 *   stack: address of the slot at 0x40 escapes at 0x14f82c
 *   stack: address of the slot at 0x40 escapes at 0x14f868
 *   stack: address of the slot at 0x40 escapes at 0x14f884
 *   stack: address of the slot at 0x40 escapes at 0x14f894
 *   stack: address of the slot at 0x40 escapes at 0x14f8d0
 *   stack: address of the slot at 0x40 escapes at 0x14f8ec
 *   stack: address of the slot at 0x40 escapes at 0x14f8fc
 *   declaration vs inferred signature: return void vs inferred u32
 */


void ReadMapMdlFile(void *a0 /* r4 */) {
    u32 a2;
    u8 *s0;
    u32 s2;
    s32 s1;
    u8 *a0_2; // a0
    u32 v1;
    u8 *v0;
    u8 stackFrame_40[128] __attribute__((aligned(16)));

    v1 = *(u16 *)a0;
    s0 = (u8 *)a0;
    s2 = *(s32 *)(((u8 *)lpMapFile + 0x20));
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            memset((void *)((u8 *)&stackFrame_40[0]), 0, 0x80);
            v0 = (u8 *)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_40[0]), (char *)v0, ".bnd");
            ReadMdlBndFile((char *)((u8 *)&stackFrame_40[0]), s1 + 0x1c, (void *)0);
            s1 = s1 + 1;
            v1 = s1 < (s32)*(u16 *)s0;
            s2 = s2 + 0x20;
        } while (v1 != 0);
    }
    a0_2 = (u8 *)lpMapFile;
    v1 = *(u16 *)(s0 + 2);
    s2 = *(s32 *)(a0_2 + 0x24);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            memset((void *)((u8 *)&stackFrame_40[0]), 0, 0x80);
            v0 = (u8 *)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_40[0]), (char *)v0, ".bnd");
            ReadMdlBndFile((char *)((u8 *)&stackFrame_40[0]), s1 + 0x4c, (void *)0);
            s1 = s1 + 1;
            v1 = s1 < (s32)*(u16 *)(s0 + 2);
            s2 = s2 + 0x20;
        } while (v1 != 0);
    }
    a0_2 = (u8 *)lpMapFile;
    v1 = *(u16 *)(s0 + 4);
    s2 = *(s32 *)(a0_2 + 0x28);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            memset((void *)((u8 *)&stackFrame_40[0]), 0, 0x80);
            v0 = (u8 *)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_40[0]), (char *)v0, ".bnd");
            ReadMdlBndFile((char *)((u8 *)&stackFrame_40[0]), s1 + 4, (void *)0);
            s1 = s1 + 1;
            v1 = s1 < (s32)*(u16 *)(s0 + 4);
            s2 = s2 + 0x20;
        } while (v1 != 0);
    }
    a0_2 = (u8 *)lpMapFile;
    v1 = *(u16 *)(s0 + 0xe);
    s2 = *(s32 *)(a0_2 + 0x3c);
    s1 = 0;
    if (0 < (s32)v1) {
        do {
            memset((void *)((u8 *)&stackFrame_40[0]), 0, 0x80);
            v0 = (u8 *)SearchFileName((char *)s2);
            a2 = (u32)".bnd";
            ChangeExtension((void *)((u8 *)&stackFrame_40[0]), (char *)v0, ".bnd");
            ReadMdlBndFile((char *)((u8 *)&stackFrame_40[0]), s1 + 0x120, (void *)0);
            s1 = s1 + 1;
            v1 = s1 < (s32)*(u16 *)(s0 + 0xe);
            s2 = s2 + 0x20;
        } while (v1 != 0);
    }
    return;
}



/* SetMapModel @ 0x14F1E0 .. 0x14F754 (0x574 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c8ef34d at 0x14f28c
 *   fpu: float literal 0x3c8ef34d at 0x14f314
 *   fpu: float literal 0x00000000 at 0x14f34c
 *   fpu: float literal 0x3c8ef34d at 0x14f4b0
 *   fpu: float literal 0x3c8ef34d at 0x14f634
 *   cfg: loop body is not one contiguous region: .L0014F2F8
 *   cfg: loop body is not one contiguous region: .L0014F3C0
 *   cfg: kept branch: 0x14f3c0 if (..) goto .L0014F3F8
 *   cfg: kept branch: 0x14f3d0 if (..) goto .L0014F3F8
 *   cfg: loop body is not one contiguous region: .L0014F498
 *   cfg: kept branch: 0x14f54c if (..) goto .L0014F5D8
 *   cfg: kept branch: 0x14f56c if (..) goto .L0014F5D8
 *   cfg: loop body is not one contiguous region: .L0014F618
 *   cfg: loop body is not one contiguous region: .L0014F680
 *   cfg: kept branch: 0x14f680 if (..) goto .L0014F6B8
 *   cfg: kept branch: 0x14f690 if (..) goto .L0014F6B8
 */

extern unsigned int SetMdlMng(void *, void *);
extern void sceVu0CopyVector(void *, void *);
extern void MakePresetMdlMatrix(void *);
extern void ObjAppear(signed int, void *, float *, float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int CheckPointInBoundBox(float *, void *);
extern signed int GetClothDataId(void *);
extern void ReCalcMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern void * GetEneSave(unsigned char, void *);
extern void EneAppear(signed int, signed int, void *, float *, float, float *, unsigned char,
    unsigned short, unsigned char, void *, void *);
extern int rand(void);
extern void SFX_Idle(unsigned short);
extern void ItemAppear(signed int, void *, float *, float *, float *);
void SetMapEventData(void);
extern void SetEventFunc(void);
extern void InitEventFunc(void);

void SetMapPathData(void);
extern u32 MdlData[];

struct dw_347896_fields;
struct dw_361841_fields;
#ifndef PROTO_DW_363241_FIELDS
#define PROTO_DW_363241_FIELDS
struct dw_363241_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_359086_FIELDS
#define PROTO_DW_359086_FIELDS
struct dw_359086_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_358763_FIELDS
#define PROTO_DW_358763_FIELDS
struct dw_358763_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_347896_fields *lpMdl; };
#endif
#ifndef PROTO_DW_347896_FIELDS
#define PROTO_DW_347896_FIELDS
struct dw_347896_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_361841_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_347896_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_363241_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_359086_fields flags; unsigned char _pad1[3]; struct dw_358763_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_359917_FIELDS
#define PROTO_DW_359917_FIELDS
struct dw_359917_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_347896_FIELDS_BUSE_4E3A607C_DEFINED
#define DCOMP_OFF_STRUCT_DW_347896_FIELDS_BUSE_4E3A607C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_347896_FIELDS_BUSE_4E3A607C = (int)&(((struct dw_347896_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPHITMAP_0__F2404025_DEFINED
#define DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPHITMAP_0__F2404025_DEFINED
enum { DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPHITMAP_0__F2404025 = (int)&(((struct dw_347896_fields *)0)->lpHitMap[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPPARTS_E25FC7A8_DEFINED
#define DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPPARTS_E25FC7A8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_347896_FIELDS_LPPARTS_E25FC7A8 = (int)&(((struct dw_347896_fields *)0)->lpParts) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_359917_FIELDS_ENEMYOFF_1A1EF99B_DEFINED
#define DCOMP_OFF_STRUCT_DW_359917_FIELDS_ENEMYOFF_1A1EF99B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_359917_FIELDS_ENEMYOFF_1A1EF99B = (int)&(((struct dw_359917_fields *)0)->EnemyOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_359917_FIELDS_SCENENO_C2A837CF_DEFINED
#define DCOMP_OFF_STRUCT_DW_359917_FIELDS_SCENENO_C2A837CF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_359917_FIELDS_SCENENO_C2A837CF = (int)&(((struct dw_359917_fields *)0)->sceneNo) - 0 };
#endif

struct SMMBit2 { unsigned char _pad : 2; unsigned char f : 1; };

static inline void SetHitMap(struct dw_347896_fields *lpMdlMng) {
    u8 *p;
    s32 n = 0;
    for (p = MdlMng; p != MdlMng + 0x5400; p += 0x1c0) {
        if (*(u8 *)p != 0 && CheckPointInBoundBox(lpMdlMng->Pos, p) != 0) {
            if (n == 2) {
                break;
            }
            lpMdlMng->lpHitMap[n] = (struct dw_347896_fields *)p;
            n++;
        }
    }
}

#define SMM_SCALE(p) \
    *(float *)((p) + 0xc) = 1.0f; \
    *(float *)((p) + 0x10) = 0.01745f * (float)*(float *)((p) + 0x10); \
    *(float *)((p) + 0x14) = 0.01745f * (float)*(float *)((p) + 0x14); \
    *(float *)((p) + 0x18) = 0.01745f * (float)*(float *)((p) + 0x18)

void SetMapModel(void) {
    u32 i;
    u8 *lpParts;
    u8 *lpMapHead;
    struct dw_347896_fields *lpMdlMng;
    u8 *lpEneSave;
    u8 *lpEneData;
    u8 *lpObjData;

    lpMapHead = (u8 *)lpMapFile;
    lpMdlMng = (struct dw_347896_fields *)MdlMng;
    lpParts = (u8 *)*(s32 *)(lpMapHead + 0x40);
    for (i = 0; i < *(u16 *)(lpMapHead + 0x10); i++, lpMdlMng++, lpParts += 0x50) {
        SetMdlMng(lpMdlMng, (u8 *)MdlData + (*(s32 *)(lpParts + 0x30) + 0x1c) * 0x680);
        lpMdlMng->lpParts = lpParts;
        *(float *)(lpParts + 0xc) = 1.0f;
        sceVu0CopyVector(lpMdlMng->Pos, lpParts);
        sceVu0CopyVector(lpMdlMng->PosB, lpMdlMng->Pos);
        *(float *)(lpParts + 0x10) = 0.01745f * (float)*(float *)(lpParts + 0x10);
        *(float *)(lpParts + 0x14) = 0.01745f * (float)*(float *)(lpParts + 0x14);
        *(float *)(lpParts + 0x18) = 0.01745f * (float)*(float *)(lpParts + 0x18);
        sceVu0CopyVector(lpMdlMng->Ang, 0x10 + lpParts);
        MakePresetMdlMatrix(lpMdlMng);
    }
    lpMdlMng = (struct dw_347896_fields *)(MdlMng + 0x5400);
    lpParts = (u8 *)*(s32 *)((u8 *)lpMapFile + 0x44);
    for (i = 0; i < *(u16 *)(lpMapHead + 0x12); i++, lpMdlMng++, lpParts += 0x50) {
        SMM_SCALE(lpParts);
        ObjAppear(*(s32 *)(lpParts + 0x30), lpMdlMng, (float *)lpParts, (float *)(lpParts + 0x10), (float *)(lpParts + 0x20));
        lpObjData = *(u8 **)(lpParts + 0x38);
        ChangeAnimParam(lpMdlMng, *(u16 *)(lpObjData + 0x24), 0.0f);
        MakePresetMdlMatrix(lpMdlMng);
        if (*(u8 *)(lpObjData + 0x2e) & 1) {
            lpMdlMng->lpHitMap[0] = (struct dw_347896_fields *)(MdlMng + GetMdlMngIndexByCtrlId(0, *(s32 *)(lpObjData + 0x28)) * 0x1c0);
        } else if (!((struct SMMBit2 *)(lpObjData + 0x2d))->f) {
            SetHitMap(lpMdlMng);
        }
        if (((struct SMMBit2 *)(lpObjData + 0x2c))->f) {
            *((u8 *)lpMdlMng + 0x12b) |= 2;
        }
        if (GetClothDataId(lpMdlMng) > 0) {
            ReCalcMi3Matrix(lpMdlMng);
            UpdateWorldMatrixInAnim(lpMdlMng);
            CsMngStabilize((unsigned int)lpMdlMng, 0x1e);
        }
    }
    {
    lpMdlMng = (struct dw_347896_fields *)(MdlMng + 0x119c0);
    lpParts = (u8 *)*(s32 *)((u8 *)lpMapFile + 0x48);
    for (i = 0; i < *(u16 *)(lpMapHead + 0x14); i++, lpMdlMng++, lpParts += 0x50) {
        SMM_SCALE(lpParts);
        lpEneData = *(u8 **)(lpParts + 0x38);
        if (GameSt[0x11] == 0) {
            lpEneSave = (u8 *)GetEneSave(GameSt[9], lpMdlMng);
            if (lpEneSave != 0) {
                EneAppear(*(s32 *)(lpParts + 0x34), *(s32 *)(lpParts + 0x30), lpMdlMng, (float *)lpParts, *(float *)(lpParts + 0x14), (float *)(lpParts + 0x20), 1, 0xffff, 0, (void *)0, lpEneSave);
            }
            if (*(u8 *)(lpEneData + 0x2e) & 1) {
                if (*(s32 *)(lpEneData + 4) != 0) {
                    if (CheckEventFlag(*(s32 *)(lpEneData + 4)) != 0) {
                        continue;
                    }
                }
                if (*(s32 *)(lpEneData + 8) != 0) {
                    if (rand() % 100 > *(s32 *)(lpEneData + 8)) {
                        continue;
                    }
                }
                EneAppear(*(s32 *)(lpParts + 0x34), *(s32 *)(lpParts + 0x30), lpMdlMng, (float *)lpParts, *(float *)(lpParts + 0x14), (float *)(lpParts + 0x20), 1, 0xffff, 0, (void *)0, (void *)0);
                *(u8 *)(*(s32 *)((u8 *)lpMdlMng + 0x148) + 0x248) = 1;
            }
        }
    }
    }
    SFX_Idle(0x78);
    lpParts = (u8 *)*(s32 *)((u8 *)lpMapFile + 0x5c);
    lpMdlMng = (struct dw_347896_fields *)(MdlMng + 0xfc00);
    for (i = 0; i < *(u16 *)(lpMapHead + 0x1e); i++, lpMdlMng++, lpParts += 0x50) {
        SMM_SCALE(lpParts);
        ItemAppear(*(s32 *)(lpParts + 0x30), lpMdlMng, (float *)lpParts, (float *)(lpParts + 0x10), (float *)(lpParts + 0x20));
        MakePresetMdlMatrix(lpMdlMng);
        SetHitMap(lpMdlMng);
        *((u8 *)lpMdlMng + 0x12b) |= 2;
    }
    SetMapEventData();
    SetEventFunc();
    InitEventFunc();
    SetMapSfxData();
    SetMapSeData();
    SetMapPathData();
}








/* FreeMapData @ 0x14EEA0 .. 0x14F1D8 (0x338 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0014EF10
 *   cfg: loop body is not one contiguous region: .L0014EF60
 *   cfg: loop body is not one contiguous region: .L0014EFC8
 *   cfg: loop body is not one contiguous region: .L0014F018
 */

extern void FreeMdlMng(void *);
extern signed int GetClothDataId(void *);
extern signed int CsMngFreeRtaData(unsigned int);
extern void SetEneSave(void *);
extern void FreeMdlData(void *, signed int);
extern signed int SFX_Delete();
extern void SND_Stop(signed int);
extern void FreeMapTex(signed int);
extern void FreeMovePath(void);
extern void MemFree(void *);
extern u32 MdlData[];
static u32 MapSeSt[0x240];

struct dw_347896;
struct dw_361841;
#ifndef PROTO_DW_346294
#define PROTO_DW_346294
struct dw_346294 {
    unsigned short MapMdlNum;
    unsigned short ObjMdlNum;
    unsigned short EneMdlNum;
    unsigned short PathMdlNum;
    unsigned short SfxMdlNum;
    unsigned short EventMdlNum;
    unsigned short SeMdlNum;
    unsigned short ItemMdlNum;
    unsigned short MapNum;
    unsigned short ObjNum;
    unsigned short EneNum;
    unsigned short PathNum;
    unsigned short SfxNum;
    unsigned short EventNum;
    unsigned short SeNum;
    unsigned short ItemNum;
    unsigned int MapMdlInfo;
    unsigned int ObjMdlInfo;
    unsigned int EneMdlInfo;
    unsigned int PathMdlInfo;
    unsigned int SfxMdlInfo;
    unsigned int EventMdlInfo;
    unsigned int SeMdlInfo;
    unsigned int ItemMdlInfo;
    unsigned int MapData;
    unsigned int ObjData;
    unsigned int EneData;
    unsigned int PathData;
    unsigned int SfxData;
    unsigned int EventData;
    unsigned int SeData;
    unsigned int ItemData;
    unsigned int MapObjectData;
    unsigned int ObjObjectData;
    unsigned int EneObjectData;
    unsigned int PathObjectData;
    unsigned int SfxObjectData;
    unsigned int EvtObjectData;
    unsigned int SeObjectData;
    unsigned int ItemObjectData;
};
#endif
#ifndef PROTO_DW_363241
#define PROTO_DW_363241
struct dw_363241 {
    unsigned int unused2 : 7;
    unsigned int ZMSK : 1;
    unsigned int unused1 : 5;
    unsigned int TEST : 19;
};
#endif
#ifndef PROTO_DW_359086
#define PROTO_DW_359086
struct dw_359086 {
    unsigned char dmy : 7;
    unsigned char inhibit_mirror_sfx : 1;
};
#endif
#ifndef PROTO_DW_358763
#define PROTO_DW_358763
struct dw_358763 {
    float angY;
    float distXZ;
    float angStep;
    unsigned short stayAnim;
    unsigned short walkAnim;
    unsigned short prevAnim;
    short unused[5];
    struct dw_347896 *lpMdl;
};
#endif
#ifndef PROTO_DW_347896
#define PROTO_DW_347896
struct dw_347896 {
    unsigned char bUse;
    unsigned char bMultiDraw;
    unsigned char bErase;
    unsigned char bEraseByMapDraw;
    unsigned char bPresetMatrix;
    unsigned char FadeType;
    unsigned char Priority;
    unsigned char bUseMdlLight;
    unsigned char bUseMdlAmbient;
    unsigned char bUseWorldMat;
    unsigned char unused0[2];
    struct dw_361841 *lpMdlData;
    float (*lpObjMat)[4][4];
    float (*lpShadowMat)[4][4];
    float (*lpLocalMat)[4][4];
    void *lpMi3Head;
    float Pos[4];
    float Ang[4];
    float Scl[4];
    float Acc[4];
    float Dcy[4];
    float PosB[4];
    float AngB[4];
    float LightDir[4];
    float LightCol[4];
    float AmbientCol[4];
    float WorldMat[4][4];
    void *lpAnimCtrl;
    short IndexAnim;
    short AnimState;
    float AnimSpeed;
    float Alpha;
    float HitSize;
    float HitHigh;
    float ShadowSize;
    float ShadowHigh;
    int Hp;
    unsigned int timer;
    unsigned char TeamNo;
    unsigned char TeamNoBase;
    unsigned char AttackNo;
    unsigned char Flags;
    short DmgCnt;
    short NoSearched;
    unsigned char HitOff;
    unsigned char GravOff;
    unsigned char MapHitOff;
    unsigned char CharHitOutOff;
    unsigned int HitFlag;
    struct dw_347896 *lpHitMap[2];
    void *lpParts;
    void *lpEventData;
    void *lpCtrlSt;
    float FadeStep;
    struct dw_363241 DrawRegs;
    int State[10];
    void *lpPathMng;
    int PLightIndex;
    float Z_Offset;
    short DebugAnimState;
    unsigned char CtrlMode;
    unsigned char CtrlModeB;
    unsigned int *lpShiftTexPacket;
    unsigned char sceneNo;
    unsigned char _pad0[1];
    unsigned short hSfxPLight;
    struct dw_359086 flags;
    unsigned char _pad1[3];
    struct dw_358763 Target;
    int remnant_HP;
    unsigned short blood_pool_sfx_idx;
    unsigned char _pad2[2];
};
#endif

void FreeMapData(signed int a0 /* r4 */) {
    s32 s1;
    struct dw_361841 *s3;
    struct dw_347896 *s2;
    struct dw_346294 *s0;
    u32 v0;
    signed int a0_2;

    s3 = (struct dw_361841 *)0;
    s1 = a0;
    s0 = (struct dw_346294 *)lpMapFile;
    v0 = s0->MapNum;
    s2 = (struct dw_347896 *)MdlMng;
    if ((u8 *)0 < (u8 *)v0) {
        do {
            FreeMdlMng((void *)s2);
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 1);
            v0 = (u32)s3 < (u32)s0->MapNum;
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 0x1c0);
        } while (v0 != 0);
    }
    v0 = s0->ObjNum;
    s2 = (struct dw_347896 *)0;
    s3 = (struct dw_361841 *)(u8 *)(MdlMng + 0x5400);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            v0 = GetClothDataId((void *)s3);
            a0_2 = (u32)s3;
            if ((s32)v0 > 0) {
                CsMngFreeRtaData(a0_2);
            }
            FreeMdlMng((void *)s3);
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 1);
            v0 = (u32)s2 < (u32)s0->ObjNum;
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 0x1c0);
        } while (v0 != 0);
    }
    v0 = s0->EneNum;
    s2 = (struct dw_347896 *)0;
    s3 = (struct dw_361841 *)(u8 *)(MdlMng + 0x119c0);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            v0 = *(u8 *)(u32)s3;
            a0_2 = (u32)s3;
            if (v0 != 0) {
                SetEneSave((void *)a0_2);
            }
            v0 = GetClothDataId((void *)s3);
            a0_2 = (u32)s3;
            if ((s32)v0 > 0) {
                CsMngFreeRtaData(a0_2);
            }
            FreeMdlMng((void *)s3);
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 1);
            v0 = (u32)s2 < (u32)s0->EneNum;
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 0x1c0);
        } while (v0 != 0);
    }
    v0 = s0->ItemNum;
    s2 = (struct dw_347896 *)0;
    s3 = (struct dw_361841 *)(u8 *)(MdlMng + 0xfc00);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            v0 = GetClothDataId((void *)s3);
            a0_2 = (u32)s3;
            if ((s32)v0 > 0) {
                CsMngFreeRtaData(a0_2);
            }
            FreeMdlMng((void *)s3);
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 1);
            v0 = (u32)s2 < (u32)s0->ItemNum;
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 0x1c0);
        } while (v0 != 0);
    }
    s2 = (struct dw_347896 *)(u8 *)(MdlMng + 0x119c0);
    v0 = (u32)(u8 *)(MdlMng + 0x17140);
    if ((u32)s2 != v0) {
        do {
            v0 = s2->bUse;
            a0_2 = (u32)s2;
            if (v0 != 0) {
                FreeMdlMng((void *)a0_2);
            }
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 0x1c0);
        } while ((u8 *)s2 != (u8 *)(MdlMng + 0x17140));
    }
    v0 = s0->MapMdlNum;
    s2 = (struct dw_347896 *)0;
    s3 = (struct dw_361841 *)(u8 *)(MdlData + 0x2d80);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            FreeMdlData((void *)s3, s1);
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 1);
            v0 = (u32)s2 < (u32)s0->MapMdlNum;
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 0x680);
        } while (v0 != 0);
    }
    v0 = s0->ObjMdlNum;
    s3 = (struct dw_361841 *)0;
    s2 = (struct dw_347896 *)(u8 *)(MdlData + 0x7b80);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            FreeMdlData((void *)s2, s1);
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 1);
            v0 = (u32)s3 < (u32)s0->ObjMdlNum;
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 0x680);
        } while (v0 != 0);
    }
    v0 = s0->EneMdlNum;
    s3 = (struct dw_361841 *)0;
    s2 = (struct dw_347896 *)(u8 *)(MdlData + 0x680);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            FreeMdlData((void *)s2, s1);
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 1);
            v0 = (u32)s3 < (u32)s0->EneMdlNum;
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 0x680);
        } while (v0 != 0);
    }
    v0 = s0->ItemMdlNum;
    s3 = (struct dw_361841 *)0;
    s2 = (struct dw_347896 *)(u8 *)(MdlData + 0x1d400);
    if ((u8 *)0 < (u8 *)v0) {
        do {
            FreeMdlData((void *)s2, s1);
            s3 = (struct dw_361841 *)(s32)((u32)s3 + 1);
            v0 = (u32)s3 < (u32)s0->ItemMdlNum;
            s2 = (struct dw_347896 *)(s32)((u32)s2 + 0x680);
        } while (v0 != 0);
    }
    s0 = (struct dw_346294 *)MapSfxSt;
    do {
        SFX_Delete(*(s32 *)(((u8 *)(u8 *)s0 + 4)), (u32)1);
        s0 = (struct dw_346294 *)((u8 *)(u8 *)s0 + 0x10);
    } while ((u8 *)s0 != (u8 *)(MapSfxSt + 0x100));
    a0_2 = (signed int)MapSfxSt;
    memset((void *)MapSfxSt, 0, 0x400);
    s0 = (struct dw_346294 *)MapSeSt;
    do {
        SND_Stop(s0->ObjMdlInfo);
        s0 = (struct dw_346294 *)((u8 *)(u8 *)s0 + 0x30);
    } while ((u8 *)s0 != (u8 *)(MapSeSt + 0x240));
    a0_2 = (signed int)MapSeSt;
    memset((void *)MapSeSt, 0, 0x900);
    FreeMapTex(s1);
    FreeMovePath();
    if ((u32)s1 != 0) {
        MemFree((void *)lpMapFile);
    }
    lpMapFile = 0;
    return;
}












/* GetMapPartsInfo @ 0x14ED90 .. 0x14EE9C (0x10c bytes) */
/*
 * dcomp notes:
 *   literal: @4994 -> 0x253700
 *   literal: @4995 -> 0x2536e0
 *   indirect: jr v0 at 0x14edb0 -> <v0>
 *   indirect: jr v0 at 0x14ee1c -> <v0>
 *   declaration vs inferred signature: return void * vs inferred u32
 */






void * GetMapPartsInfo(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a3;
    u8 *a2;
    u8 *v1;
    u32 v0;

    a2 = (u8 *)lpMapFile;
    v1 = (u8 *)0x253700;
    switch (a0) {
    case 0:
        a3 = *(s32 *)(a2 + 0x40);
        break;
    case 1:
        a3 = *(s32 *)(a2 + 0x44);
        break;
    case 2:
        a3 = *(s32 *)(a2 + 0x48);
        break;
    case 3:
        a3 = *(s32 *)(a2 + 0x4c);
        break;
    case 4:
        a3 = *(s32 *)(a2 + 0x50);
        break;
    case 5:
        a3 = *(s32 *)(a2 + 0x54);
        break;
    case 6:
        a3 = *(s32 *)(a2 + 0x58);
        break;
    case 7:
        a3 = *(s32 *)(a2 + 0x5c);
        break;
    default:
        a3 = 0;
    }
    v1 = (u8 *)0x2536e0;
    switch (a0) {
    case 0:
        v0 = *(u16 *)(a2 + 0x10);
        break;
    case 1:
        v0 = *(u16 *)(a2 + 0x12);
        break;
    case 2:
        v0 = *(u16 *)(a2 + 0x14);
        break;
    case 3:
        v0 = *(u16 *)(a2 + 0x16);
        break;
    case 4:
        v0 = *(u16 *)(a2 + 0x18);
        break;
    case 5:
        v0 = *(u16 *)(a2 + 0x1a);
        break;
    case 6:
        v0 = *(u16 *)(a2 + 0x1c);
        break;
    case 7:
        v0 = *(u16 *)(a2 + 0x1e);
        break;
    default:
        v0 = 0;
    }
    v0 = (s32)a1 < (s32)v0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = (u32)a1 * (u32)(0x50);
        v0 = a3 + (u32)v0;
    }
    return (void *)v0;
}




/* GetMapPartsInfoByCtrlId @ 0x14EC60 .. 0x14ED88 (0x128 bytes) */
/*
 * dcomp notes:
 *   literal: @4958 -> 0x2536c0
 *   literal: @4959 -> 0x2536a0
 *   indirect: jr v0 at 0x14ec80 -> <v0>
 *   indirect: jr v1 at 0x14ecec -> <v1>
 *   cfg: loop body is not one contiguous region: .L0014ED50
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern u32 L4958[];
extern u32 L4959[];

void * GetMapPartsInfoByCtrlId(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *a2;
    u32 v1;
    u32 v0;

    a2 = (u8 *)lpMapFile;
    switch (a0) {
    case 0:
        v0 = *(s32 *)(a2 + 0x40);
        break;
    case 1:
        v0 = *(s32 *)(a2 + 0x44);
        break;
    case 2:
        v0 = *(s32 *)(a2 + 0x48);
        break;
    case 3:
        v0 = *(s32 *)(a2 + 0x4c);
        break;
    case 4:
        v0 = *(s32 *)(a2 + 0x50);
        break;
    case 5:
        v0 = *(s32 *)(a2 + 0x54);
        break;
    case 6:
        v0 = *(s32 *)(a2 + 0x58);
        break;
    case 7:
        v0 = *(s32 *)(a2 + 0x5c);
        break;
    default:
        v0 = 0;
    }
    switch (a0) {
    case 0:
        a2 = (u8 *)*(u16 *)(a2 + 0x10);
        break;
    case 1:
        a2 = (u8 *)*(u16 *)(a2 + 0x12);
        break;
    case 2:
        a2 = (u8 *)*(u16 *)(a2 + 0x14);
        break;
    case 3:
        a2 = (u8 *)*(u16 *)(a2 + 0x16);
        break;
    case 4:
        a2 = (u8 *)*(u16 *)(a2 + 0x18);
        break;
    case 5:
        a2 = (u8 *)*(u16 *)(a2 + 0x1a);
        break;
    case 6:
        a2 = (u8 *)*(u16 *)(a2 + 0x1c);
        break;
    case 7:
        a2 = (u8 *)*(u16 *)(a2 + 0x1e);
        break;
    default:
        a2 = (u8 *)0;
    }
    a0 = 0;
    if (0 < (s32)a2) {
        do {
            v1 = *(s32 *)*(s32 *)((v0 + 0x38));
            if (v1 == (u32)(s32)a1) {
                return (void *)v0;
            }
            a0 = (u32)(a0) + 1;
            v1 = (s32)a0 < (s32)a2;
            v0 = v0 + 0x50;
        } while (v1 != 0);
    }
    v0 = 0;
    return (void *)v0;
}





/* GetMdlMngIndexByCtrlId @ 0x14EAA0 .. 0x14EC58 (0x1b8 bytes) */
/*
 * dcomp notes:
 *   literal: @4917 -> 0x253680
 *   literal: @4918 -> 0x253660
 *   literal: @4919 -> 0x253640
 *   indirect: jr v0 at 0x14eac0 -> <v0>
 *   indirect: jr v0 at 0x14eb2c -> <v0>
 *   indirect: jr v0 at 0x14eb9c -> <v0>
 *   return: addu at 0x14ec54 computes the return value
 *   cfg: loop body is not one contiguous region: .L0014EC00
 *   cfg: kept branch: 0x14ec00 if (..) goto .L0014EC18
 *   cfg: kept goto: 0x14ec10 -> .L0014EC30
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 L4917[];
extern u32 L4918[];
extern u32 L4919[];

signed int GetMdlMngIndexByCtrlId(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 *t0;
    u8 *a3;
    u8 *a2;
    u8 *selected;
    u32 v1;
    u32 v0;

    a3 = (u8 *)lpMapFile;
    switch (a0) {
    case 0:
        t0 = (u32 *)*(s32 *)(a3 + 0x40);
        break;
    case 1:
        t0 = (u32 *)*(s32 *)(a3 + 0x44);
        break;
    case 2:
        t0 = (u32 *)*(s32 *)(a3 + 0x48);
        break;
    case 3:
        t0 = (u32 *)*(s32 *)(a3 + 0x4c);
        break;
    case 4:
        t0 = (u32 *)*(s32 *)(a3 + 0x50);
        break;
    case 5:
        t0 = (u32 *)*(s32 *)(a3 + 0x54);
        break;
    case 6:
        t0 = (u32 *)*(s32 *)(a3 + 0x58);
        break;
    case 7:
        t0 = (u32 *)*(s32 *)(a3 + 0x5c);
        break;
    default:
        t0 = (u32 *)0;
    }
    switch (a0) {
    case 0:
        a2 = (u8 *)*(s32 *)(a3 + 0x40);
        break;
    case 1:
        a2 = (u8 *)*(s32 *)(a3 + 0x44);
        break;
    case 2:
        a2 = (u8 *)*(s32 *)(a3 + 0x48);
        break;
    case 3:
        a2 = (u8 *)*(s32 *)(a3 + 0x4c);
        break;
    case 4:
        a2 = (u8 *)*(s32 *)(a3 + 0x50);
        break;
    case 5:
        a2 = (u8 *)*(s32 *)(a3 + 0x54);
        break;
    case 6:
        a2 = (u8 *)*(s32 *)(a3 + 0x58);
        break;
    case 7:
        a2 = (u8 *)*(s32 *)(a3 + 0x5c);
        break;
    default:
        a2 = (u8 *)0;
    }
    switch (a0) {
    case 0:
        a0 = *(u16 *)(a3 + 0x10);
        break;
    case 1:
        a0 = *(u16 *)(a3 + 0x12);
        break;
    case 2:
        a0 = *(u16 *)(a3 + 0x14);
        break;
    case 3:
        a0 = *(u16 *)(a3 + 0x16);
        break;
    case 4:
        a0 = *(u16 *)(a3 + 0x18);
        break;
    case 5:
        a0 = *(u16 *)(a3 + 0x1a);
        break;
    case 6:
        a0 = *(u16 *)(a3 + 0x1c);
        break;
    case 7:
        a0 = *(u16 *)(a3 + 0x1e);
        break;
    default:
        a0 = 0;
    }
    v1 = 0;
    if (0 < (s32)a0) {
        do {
            v0 = *(s32 *)*(s32 *)(a2 + 0x38);
            if (v0 == (u32)(s32)a1) {
                selected = a2;
                goto found;
            }
            v1 = v1 + 1;
            a2 = (u8 *)(a2 + 0x50);
        } while ((s32)v1 < (s32)a0);
    }
    selected = (u8 *)0;
    found:;
    a0 = (s32)(selected - (u32)(t0));
    return (s32)a0 / 0x50;
}




/* GetMdlDataIndexFromMapMdlInfo @ 0x14E970 .. 0x14EA98 (0x128 bytes) */
/*
 * dcomp notes:
 *   literal: @4854 -> 0x253620
 *   literal: @4855 -> 0x253600
 *   indirect: jr v0 at 0x14e990 -> <v0>
 *   indirect: jr v0 at 0x14e9fc -> <v0>
 *   cfg: loop body is not one contiguous region: .L0014EA60
 *   cfg: kept branch: 0x14ea60 if (..) goto .L0014EA78
 *   cfg: kept goto: 0x14ea70 -> .L0014EA90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 L4854[];
extern u32 L4855[];

signed int GetMdlDataIndexFromMapMdlInfo(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *a3;
    u8 *a2;
    u32 *v1;
    u32 v0;

    a2 = (u8 *)lpMapFile;
    switch (a0) {
    case 0:
        a3 = (u8 *)*(s32 *)(a2 + 0x40);
        break;
    case 1:
        a3 = (u8 *)*(s32 *)(a2 + 0x44);
        break;
    case 2:
        a3 = (u8 *)*(s32 *)(a2 + 0x48);
        break;
    case 3:
        a3 = (u8 *)*(s32 *)(a2 + 0x4c);
        break;
    case 4:
        a3 = (u8 *)*(s32 *)(a2 + 0x50);
        break;
    case 5:
        a3 = (u8 *)*(s32 *)(a2 + 0x54);
        break;
    case 6:
        a3 = (u8 *)*(s32 *)(a2 + 0x58);
        break;
    case 7:
        a3 = (u8 *)*(s32 *)(a2 + 0x5c);
        break;
    default:
        a3 = (u8 *)0;
    }
    switch (a0) {
    case 0:
        v1 = (u32 *)*(u16 *)(a2 + 0x10);
        break;
    case 1:
        v1 = (u32 *)*(u16 *)(a2 + 0x12);
        break;
    case 2:
        v1 = (u32 *)*(u16 *)(a2 + 0x14);
        break;
    case 3:
        v1 = (u32 *)*(u16 *)(a2 + 0x16);
        break;
    case 4:
        v1 = (u32 *)*(u16 *)(a2 + 0x18);
        break;
    case 5:
        v1 = (u32 *)*(u16 *)(a2 + 0x1a);
        break;
    case 6:
        v1 = (u32 *)*(u16 *)(a2 + 0x1c);
        break;
    case 7:
        v1 = (u32 *)*(u16 *)(a2 + 0x1e);
        break;
    default:
        v1 = (u32 *)0;
    }
    a0 = 0;
    if (0 < (s32)v1) {
        do {
            v0 = *(s32 *)(a3 + 0x34);
            if (v0 != (u32)(s32)a1) {
                goto _L0014EA78;
            }
            v0 = *(s32 *)(a3 + 0x30);
            goto _L0014EA90;
            _L0014EA78:;
            a0 = (u32)(a0) + 1;
            v0 = (s32)a0 < (s32)v1;
            a3 = (u8 *)(a3 + 0x50);
        } while (v0 != 0);
    }
    v0 = -1;
    _L0014EA90:;
    return v0;
}








/* GetMdlInfoStart @ 0x14E8F0 .. 0x14E968 (0x78 bytes) */
/*
 * dcomp notes:
 *   literal: @4793 -> 0x2535e0
 *   indirect: jr v0 at 0x14e910 -> <v0>
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern u32 L4793[];

void * GetMdlInfoStart(signed int a0 /* r4 */) {
    u8 *a1;
    u32 v0;

    a1 = (u8 *)lpMapFile;
    switch (a0) {
    case 0:
        v0 = *(s32 *)(a1 + 0x20);
        break;
    case 1:
        v0 = *(s32 *)(a1 + 0x24);
        break;
    case 2:
        v0 = *(s32 *)(a1 + 0x28);
        break;
    case 3:
        v0 = *(s32 *)(a1 + 0x2c);
        break;
    case 4:
        v0 = *(s32 *)(a1 + 0x30);
        break;
    case 5:
        v0 = *(s32 *)(a1 + 0x34);
        break;
    case 6:
        v0 = *(s32 *)(a1 + 0x38);
        break;
    case 7:
        v0 = *(s32 *)(a1 + 0x3c);
        break;
    default:
        v0 = 0;
    }
    return (void *)v0;
}



/* SetMapEventData @ 0x14E610 .. 0x14E8F0 (0x2e0 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3c8ef34d at 0x14e6c4
 *   delay: addiu at 0x14e734 writes a register its branch at 0x14e730 reads
 *   delay: addiu at 0x14e748 writes a register its branch at 0x14e744 reads
 *   fpu: float literal 0x00000000 at 0x14e858
 *   fpu: float literal 0x00000000 at 0x14e8ac
 *   cfg: loop body is not one contiguous region: .L0014E648
 */

extern void InitFadeObj(signed int, signed int);
extern void InitFadeItem(signed int, signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetAnimLastFrame(void *);

void SetMapEventData(void) {
    u32 a1;
    s32 s3;
    u8 *s2;
    u32 s1;
    s32 s0;
    u32 a0;
    u32 v1;
    u32 v0;
    float f12;
    s32 s4;
    float f0;

    v1 = lpMapFile;
    s3 = *(u16 *)((v1 + 0x1a));
    s2 = (u8 *)*(s32 *)((v1 + 0x54));
    s0 = 0;
    if (0 < s3) {
        do {
            s1 = *(s32 *)(s2 + 0x38);
            v1 = 5;
            a1 = *(s32 *)((s1 + 8));
            a0 = 1;
            switch (a1) {
            case 1:
                if ((u32)*(s32 *)((s1 + 0xc)) != (u32)3) {
                    break;
                }
                v0 = GetMdlMngIndexByCtrlId(a0, *(s32 *)((s1 + 4)));
                a1 = v0 + 0x30;
                v1 = (u32)MdlMng;
                a0 = a1 * (u32)(0x1c0);
                v1 = (s32)((u8 *)MdlMng + a0);
                *(u32 *)((v1 + 0x144)) = s1;
                break;
            case 5:
                v1 = 0x3f800000;
                *(u32 *)(s2 + 0xc) = 0x3f800000;
                *(f32 *)(s2 + 0x10) = (0.0174499992f * *(float *)(((u8 *)0x10 + (u32)(s2))));
                *(f32 *)(s2 + 0x14) = (0.0174499992f * *(float *)(((u8 *)0x14 + (u32)(s2))));
                f0 = (0.0174499992f * *(float *)(((u8 *)0x18 + (u32)(s2))));
                *(f32 *)(s2 + 0x18) = f0;
                if ((u32)*(s32 *)((s1 + 0xc)) != (u32)3) {
                    break;
                }
                v0 = GetMdlMngIndexByCtrlId(1, *(s32 *)((s1 + 4)));
                a1 = v0 + 0x30;
                v1 = (u32)MdlMng;
                a0 = a1 * (u32)(0x1c0);
                v1 = (s32)((u8 *)MdlMng + a0);
                *(u32 *)((v1 + 0x144)) = s1;
            }
            a0 = *(s32 *)((s1 + 0xc));
            v1 = 0xa;
            v1 = 6;
            v1 = 3;
            v1 = 1;
            switch (a0) {
            case 1:
                a0 = *(s32 *)((s1 + 8));
                if (a0 == v1) {
                    a1 = *(s32 *)((s1 + 0x20));
                    a0 = *(s32 *)((s1 + 4));
                    InitFadeObj(a0, a1);
                    break;
                } else {
                    v1 = 7;
                    if (a0 != v1) {
                        break;
                    }
                    a1 = *(s32 *)((s1 + 0x20));
                    a0 = *(s32 *)((s1 + 4));
                    InitFadeItem(a0, a1);
                    break;
                }
            case 3:
                v1 = *(s32 *)((s1 + 0x10));
                if (v1 == 0) {
                    break;
                }
                a1 = *(s32 *)((s1 + 0x20));
                a0 = *(s32 *)((s1 + 0x14));
                InitFadeObj(a0, a1);
                break;
            case 6:
                v0 = GetMdlMngIndexByCtrlId(1, *(s32 *)((s1 + 0x10)));
                a1 = v0 + 0x30;
                v1 = (u32)MdlMng;
                a0 = a1 * (u32)(0x1c0);
                *(u8 *)(((u32)(s32)((u8 *)MdlMng + a0) + 2)) = 1;
                break;
            case 10:
                a0 = *(s32 *)((s1 + 0x24));
                s4 = 0;
                if (a0 != 0) {
                    v0 = CheckEventFlag(a0);
                    if (v0 != 0) {
                        s4 = 1;
                    }
                }
                if ((u32)s4 == 0) {
                    break;
                }
                v1 = *(s32 *)((s1 + 8));
                a0 = 1;
                if (v1 == a0) {
                    v0 = GetMdlMngIndexByCtrlId(a0, *(s32 *)((s1 + 4)));
                    a0 = v0 + 0x30;
                    a1 = 0x66;
                    v0 = (u32)MdlMng;
                    v1 = a0 * (u32)(0x1c0);
                    s1 = (s32)((u8 *)MdlMng + v1);
                    f12 = 0.0f;
                    ChangeAnimParam((void *)(s32)s1, a1, 0.0f);
                    a0 = s1;
                    SetAnimLastFrame((void *)a0);
                    break;
                } else {
                    a0 = 7;
                    if (v1 != a0) {
                        break;
                    }
                    v0 = GetMdlMngIndexByCtrlId(a0, *(s32 *)((s1 + 4)));
                    a0 = v0 + 0x90;
                    a1 = 0x66;
                    v0 = (u32)MdlMng;
                    v1 = a0 * (u32)(0x1c0);
                    s1 = (s32)((u8 *)MdlMng + v1);
                    f12 = 0.0f;
                    ChangeAnimParam((void *)(s32)s1, a1, 0.0f);
                    a0 = s1;
                    SetAnimLastFrame((void *)a0);
                }
            }
            s0 = s0 + 1;
            v1 = s0 < s3;
            s2 = (u8 *)(s2 + 0x50);
        } while (v1 != 0);
    }
    return;
}










/* CheckMapEventData @ 0x14DBD0 .. 0x14E604 (0xa34 bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   literal: @4641 -> 0x2535c0
 *   literal: @4642 -> 0x2535a0
 *   literal: @4671 -> 0x253580
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckMyEventStart(void *);
extern signed int CheckMyControlOff(void *);
extern signed int CheckNowFade(signed int);

extern float Math_GetDistXZ(float *, float *);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern signed int KnMsgMng_SendMsg(signed int);
extern signed int ItemMng_GetItemProc(signed int, signed int, signed int, signed int, signed int);
extern void SetScriptDirect(signed int);
extern void ActiEventFunc(unsigned int, unsigned int);
extern void CheckDoorOpen(void *, signed int);
extern void SetMyJump(void *, unsigned short, float, float *);
extern unsigned short ItemMng_GetItemNum_Direct(unsigned short);
extern signed int KnMsgMng_SendMsgEx_SetArg3(signed int, signed int, int, signed int);
extern u32 lpPadData;
extern u32 L4641[];
extern u32 L4642[];
extern u32 L4671[];

#ifndef PROTO_DW_345414
#define PROTO_DW_345414

#endif
#ifndef PROTO_DW_353246
#define PROTO_DW_353246
struct dw_353246 {
    int CtrlId;
    int FollowId;
    int FollowType;
    int EventKind;
    int EventData1;
    int EventData2;
    float EventDist;
    float EventAng;
    int EventSaveFlag;
    int EventSaveCtrlFlag;
    int NeckLevel;
    unsigned int Flag1 : 1;
    unsigned int Flag2_32 : 31;
    int MapParts;
    int EventSaveFlag2;
    int EventSaveCtrlFlag2;
    int EventData3;
};
#endif

struct PadBitsI { u8 pad:6; u8 f:1; u8 g:1; };





#ifndef CAE_PI
#define CAE_PI 3.14159274f
#endif
#ifndef CAE_ABSF
#define CAE_ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#endif
#ifndef CAE_WRAPF
#define CAE_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
#endif
static inline void * GetMapEventParts(s32 Type, s32 CtrlId) {
    u8 *lpMap;
    u8 *a2;
    u32 v1;
    u32 v0;
    int i;

    lpMap = (u8 *)lpMapFile;
    switch (Type) {
    case 0: v0 = *(s32 *)(lpMap + 0x40); break;
    case 1: v0 = *(s32 *)(lpMap + 0x44); break;
    case 2: v0 = *(s32 *)(lpMap + 0x48); break;
    case 3: v0 = *(s32 *)(lpMap + 0x4c); break;
    case 4: v0 = *(s32 *)(lpMap + 0x50); break;
    case 5: v0 = *(s32 *)(lpMap + 0x54); break;
    case 6: v0 = *(s32 *)(lpMap + 0x58); break;
    case 7: v0 = *(s32 *)(lpMap + 0x5c); break;
    default: v0 = 0; break;
    }
    switch (Type) {
    case 0: a2 = (u8 *)*(u16 *)(lpMap + 0x10); break;
    case 1: a2 = (u8 *)*(u16 *)(lpMap + 0x12); break;
    case 2: a2 = (u8 *)*(u16 *)(lpMap + 0x14); break;
    case 3: a2 = (u8 *)*(u16 *)(lpMap + 0x16); break;
    case 4: a2 = (u8 *)*(u16 *)(lpMap + 0x18); break;
    case 5: a2 = (u8 *)*(u16 *)(lpMap + 0x1a); break;
    case 6: a2 = (u8 *)*(u16 *)(lpMap + 0x1c); break;
    case 7: a2 = (u8 *)*(u16 *)(lpMap + 0x1e); break;
    default: a2 = (u8 *)0; break;
    }
    i = 0;
    if (0 < (s32)a2) {
        do {
            v1 = *(s32 *)*(s32 *)((v0 + 0x38));
            if (v1 == (u32)(s32)CtrlId) {
                return (void *)v0;
            }
            i = (u32)(i) + 1;
            v1 = (s32)i < (s32)a2;
            v0 = v0 + 0x50;
        } while (v1 != 0);
    }
    v0 = 0;
    return (void *)v0;
}

void CheckMapEventData(void *a0 /* r4 */) {
    int EventNum;
    int i;
    int j;
    int DoorType;
    u32 ItemNum;
    int BoatIndex;
    struct dw_347896_fields *lpMdlMng;
    struct dw_345414 *lpEventParts;
    struct dw_345414 *lpParts;
    struct dw_353246 *lpEventData;
    struct dw_347896_fields *lpEventMdlMng;
    u16 *lpDoorInfo;
    float EventPos[4] __attribute__((aligned(16)));
    float EventAng[4] __attribute__((aligned(16)));
    float Ang;
    float Dist;
    float AngDistObj;
    float AngDist;
    int EventMdlMngIndex;
    int Count;

    lpMdlMng = (struct dw_347896_fields *)a0;
    EventNum = *(u16 *)(lpMapFile + 0x1a);
    lpEventParts = (struct dw_345414 *)*(u32 *)(lpMapFile + 0x54);
    if (((struct PadBitsI *)((u8 *)(&lpPadData)[((struct dw_359917_fields *)GameSt)->padport] + 0x21))->f != 0) {
        if (CheckMyEventStart(lpMdlMng) != 0) {
            if (CheckMyControlOff(lpMdlMng) != 0) {
                if (CheckNowFade(3) == 0) {
                    if (CheckNowFade(6) == 0) {
                        if (CheckNowFade(0xa) == 0) {
                            if (CheckNowFade(0xb) == 0) {
                                for (i = 0; i < EventNum; i++, lpEventParts++) {
                                    lpEventData = (struct dw_353246 *)lpEventParts->MapObjData;
                                    if (lpEventData->EventSaveCtrlFlag != 0) {
                                        if (CheckEventFlag(lpEventData->EventSaveCtrlFlag) != 0) {
                                            continue;
                                        }
                                    }
                                    if (lpEventData->EventSaveCtrlFlag2 != 0) {
                                        if (CheckEventFlag(lpEventData->EventSaveCtrlFlag2) == 0) {
                                            continue;
                                        }
                                    }
                                    switch (lpEventData->FollowType) {
                                    case 5:
                                        sceVu0CopyVector(EventPos, lpEventParts->Pos);
                                        sceVu0CopyVector(EventAng, lpEventParts->Ang);
                                        break;
                                    case 1:
                                        EventMdlMngIndex = GetMdlMngIndexByCtrlId(1, lpEventData->FollowId);
                                        lpEventMdlMng = (struct dw_347896_fields *)(MdlMng + (EventMdlMngIndex + 0x30) * 0x1c0);
                                        if (lpEventMdlMng->bUse == 0) {
                                            continue;
                                        }
                                        sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
                                        sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
                                        break;
                                    case 2:
                                        EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, lpEventData->FollowId);
                                        lpEventMdlMng = (struct dw_347896_fields *)(MdlMng + (EventMdlMngIndex + 0xa1) * 0x1c0);
                                        if (lpEventMdlMng->bUse == 0) {
                                            continue;
                                        }
                                        sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
                                        sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
                                        break;
                                    case 7:
                                        EventMdlMngIndex = GetMdlMngIndexByCtrlId(7, lpEventData->FollowId);
                                        lpEventMdlMng = (struct dw_347896_fields *)(MdlMng + (EventMdlMngIndex + 0x90) * 0x1c0);
                                        if (lpEventMdlMng->bUse == 0) {
                                            continue;
                                        }
                                        sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
                                        sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
                                        break;
                                    default:
                                        lpParts = (struct dw_345414 *)GetMapEventParts(lpEventData->FollowType,
                                                                                        lpEventData->FollowId);
                                        if (lpParts == 0) {
                                            continue;
                                        }
                                        sceVu0CopyVector(EventPos, lpParts->Pos);
                                        sceVu0CopyVector(EventAng, lpParts->Ang);
                                        break;
                                    }
                                    Dist = Math_GetDistXZ(lpMdlMng->Pos, EventPos);
                                    if (!(Dist <= lpEventData->EventDist)) {
                                        continue;
                                    }
                                    Ang = Math_VectorToAngle(-(EventPos[0] - lpMdlMng->Pos[0]),
                                                             -(EventPos[2] - lpMdlMng->Pos[2]));
                                    AngDistObj = CAE_ABSF(Math_GetAngleDist(EventAng[1], CAE_WRAPF(Ang + CAE_PI)));
                                    AngDist = CAE_ABSF(Math_GetAngleDist(lpMdlMng->Ang[1], Ang));
                                    if (!(CAE_ABSF(AngDistObj) <= 0.0174499992f * (float)lpEventData->EventAng)) {
                                        continue;
                                    }
                                    switch (lpEventData->EventKind) {
                                    case 1:
                                    case 2:
                                        if (!(Dist <= 0.2f)) {
                                            if (!(CAE_ABSF(AngDist) <= 0.785398185f)) {
                                                continue;
                                            }
                                        }
                                        break;
                                    default:
                                        if (!(CAE_ABSF(AngDist) <= 0.785398185f)) {
                                            continue;
                                        }
                                        break;
                                    }
                                    switch (lpEventData->EventKind) {
                                    case 0:
                                        KnMsgMng_SendMsg(lpEventData->EventData1);
                                        if (lpEventData->EventData2 > 0) {
                                            for (j = 0; j < lpEventData->EventData2; j++) {
                                                KnMsgMng_SendMsg(lpEventData->EventData1 + j + 1);
                                            }
                                        }
                                        if (lpEventData->EventSaveFlag != 0) {
                                            SetEventFlag(lpEventData->EventSaveFlag);
                                        }
                                        return;
                                    case 1:
                                        Count = lpEventData->EventData2;
                                        if (Count == 0) {
                                            Count = 1;
                                        }
                                        ItemMng_GetItemProc(lpEventData->EventData1, lpEventData->EventSaveFlag,
                                                            lpEventData->FollowType, lpEventData->FollowId, Count);
                                        return;
                                    case 2:
                                        if (lpEventData->EventData2 == 0) {
                                            SetScriptDirect(lpEventData->EventData1);
                                        } else {
                                            ActiEventFunc(lpEventData->EventData1, lpEventData->EventData2);
                                        }
                                        return;
                                    case 3:
                                        EventMdlMngIndex = GetMdlMngIndexByCtrlId(1, lpEventData->FollowId);
                                        lpEventMdlMng = (struct dw_347896_fields *)(MdlMng + (EventMdlMngIndex + 0x30) * 0x1c0);
                                        lpDoorInfo = *(u16 **)((u8 *)lpEventMdlMng->lpMdlData + 0x4c);
                                        if (lpDoorInfo != 0 && *lpDoorInfo == 0x14) {
                                            if (AngDistObj < 1.57079637f) {
                                                DoorType = 1;
                                            } else {
                                                DoorType = 2;
                                            }
                                        } else if (lpDoorInfo != 0 && *lpDoorInfo == 0x13) {
                                            switch (((struct dw_359917_fields *)GameSt)->PlayerId) {
                                            case 0:
                                            case 2:
                                                if (AngDistObj < 1.57079637f) {
                                                    DoorType = 1;
                                                } else {
                                                    DoorType = 2;
                                                }
                                                break;
                                            case 1:
                                                if (AngDistObj < 1.57079637f) {
                                                    DoorType = 0xa;
                                                } else {
                                                    DoorType = 0xb;
                                                }
                                                break;
                                            }
                                        } else {
                                            switch (((struct dw_359917_fields *)GameSt)->PlayerId) {
                                            case 0:
                                                if (AngDistObj < 1.57079637f) {
                                                    DoorType = 1;
                                                } else {
                                                    DoorType = 2;
                                                }
                                                break;
                                            case 1:
                                                if (AngDistObj < 1.57079637f) {
                                                    DoorType = 0xa;
                                                } else {
                                                    DoorType = 0xb;
                                                }
                                                break;
                                            case 2:
                                                if (AngDistObj < 1.57079637f) {
                                                    DoorType = 0x14;
                                                } else {
                                                    DoorType = 0x15;
                                                }
                                                break;
                                            }
                                        }
                                        CheckDoorOpen(lpEventData, DoorType);
                                        return;
                                    case 4:
                                        SetMyJump(lpMdlMng, *(u16 *)((u8 *)lpEventData + 0x10), EventAng[0], lpEventParts->Scl);
                                        return;
                                    case 6:
                                        if (SaveEvent[0] == 0) {
                                            ItemNum = ItemMng_GetItemNum_Direct(0x36cd);
                                            BoatIndex = GetMdlMngIndexByCtrlId(1, lpEventData->EventData1);
                                            if ((u16)ItemNum == 0) {
                                                KnMsgMng_SendMsg(0x1d4e1);
                                            } else {
                                                KnMsgMng_SendMsgEx_SetArg3(0x1d4de, 1, 8, (u16)ItemNum);
                                            }
                                            memset(SaveEvent, 0, 0x14);
                                            *(u16 *)((u8 *)SaveEvent + 4) = ItemNum;
                                            SaveEvent[0] = 1;
                                            SaveEvent[4] = (u32)(MdlMng + (BoatIndex + 0x30) * 0x1c0);
                                            SaveEvent[3] = lpEventData->EventData1;
                                            SaveEvent[2] = lpEventData->EventData2;
                                        }
                                        return;
                                    case 5:
                                    default:
                                        continue;
                                    }
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}




#define CAE_PI 3.14159274f
#define CAE_ABSF(x) (((x) < 0.0f) ? -(x) : (x))
#define CAE_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))

#ifndef PROTO_DW_353246
#define PROTO_DW_353246
struct dw_353246 {
    int CtrlId;
    int FollowId;
    int FollowType;
    int EventKind;
    int EventData1;
    int EventData2;
    float EventDist;
    float EventAng;
    int EventSaveFlag;
    int EventSaveCtrlFlag;
    int NeckLevel;
    unsigned int Flag1 : 1;
    unsigned int Flag2_32 : 31;
    int MapParts;
    int EventSaveFlag2;
    int EventSaveCtrlFlag2;
    int EventData3;
};
#endif

extern void sceVu0CopyVector(void *, void *);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern float Math_GetDistXZ(float *, float *);
extern void SetBlast(float, float, float *, float *, signed int);
extern void SetE044RandomAppear(float *, signed int, signed int, float);

extern void ResetEventFlag(signed int);
extern int rand(void);

static inline void * GetAutoEventParts(s32 Type, s32 CtrlId) {
    u8 *lpMap;
    u8 *a2;
    u32 v1;
    u32 v0;
    int i;

    lpMap = (u8 *)lpMapFile;
    switch (Type) {
    case 0: v0 = *(s32 *)(lpMap + 0x40); break;
    case 1: v0 = *(s32 *)(lpMap + 0x44); break;
    case 2: v0 = *(s32 *)(lpMap + 0x48); break;
    case 3: v0 = *(s32 *)(lpMap + 0x4c); break;
    case 4: v0 = *(s32 *)(lpMap + 0x50); break;
    case 5: v0 = *(s32 *)(lpMap + 0x54); break;
    case 6: v0 = *(s32 *)(lpMap + 0x58); break;
    case 7: v0 = *(s32 *)(lpMap + 0x5c); break;
    default: v0 = 0; break;
    }
    switch (Type) {
    case 0: a2 = (u8 *)*(u16 *)(lpMap + 0x10); break;
    case 1: a2 = (u8 *)*(u16 *)(lpMap + 0x12); break;
    case 2: a2 = (u8 *)*(u16 *)(lpMap + 0x14); break;
    case 3: a2 = (u8 *)*(u16 *)(lpMap + 0x16); break;
    case 4: a2 = (u8 *)*(u16 *)(lpMap + 0x18); break;
    case 5: a2 = (u8 *)*(u16 *)(lpMap + 0x1a); break;
    case 6: a2 = (u8 *)*(u16 *)(lpMap + 0x1c); break;
    case 7: a2 = (u8 *)*(u16 *)(lpMap + 0x1e); break;
    default: a2 = (u8 *)0; break;
    }
    i = 0;
    if (0 < (s32)a2) {
        do {
            v1 = *(s32 *)*(s32 *)((v0 + 0x38));
            if (v1 == (u32)(s32)CtrlId) {
                return (void *)v0;
            }
            i = (u32)(i) + 1;
            v1 = (s32)i < (s32)a2;
            v0 = v0 + 0x50;
        } while (v1 != 0);
    }
    v0 = 0;
    return (void *)v0;
}

void CheckAutoEvent(void *a0 /* r4 */) {
    int EventNum;
    int i;
    u8 *lpMyCtrl;
    int E044Num;
    struct dw_345414 *lpParts;
    struct dw_347896 *lpMdlMng;
    struct dw_345414 *lpEventParts;
    struct dw_353246 *lpEventData;
    struct dw_347896 *lpEventMdlMng;
    float EventPos[4];
    float EventAng[4];
    float Ang;
    float AngDistObj;
    int EventMdlMngIndex;
    int bBlast;
    int MapMdlIndex;

    lpMdlMng = (struct dw_347896 *)a0;
    lpMyCtrl = (u8 *)lpMdlMng->lpCtrlSt;
    EventNum = *(u16 *)(lpMapFile + 0x1a);
    lpEventParts = (struct dw_345414 *)*(u32 *)(lpMapFile + 0x54);
    for (i = 0; i < EventNum; i++) {
        lpEventData = (struct dw_353246 *)lpEventParts[i].MapObjData;
        switch (lpEventData->EventKind) {
        case 8:
        case 9:
        case 10:
            break;
        default:
            continue;
        }
        if (lpEventData->EventSaveCtrlFlag != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag) != 0) {
                continue;
            }
        }
        if (lpEventData->EventSaveCtrlFlag2 != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag2) == 0) {
                continue;
            }
        }
        switch (lpEventData->FollowType) {
        case 5:
            sceVu0CopyVector(EventPos, lpEventParts[i].Pos);
            sceVu0CopyVector(EventAng, lpEventParts[i].Ang);
            break;
        case 1:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(1, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x30) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        case 2:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0xa1) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        case 7:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(7, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x90) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        default:
            lpParts = (struct dw_345414 *)GetAutoEventParts(lpEventData->FollowType,
                                                            lpEventData->FollowId);
            if (lpParts == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpParts->Pos);
            sceVu0CopyVector(EventAng, lpParts->Ang);
            break;
        }
        if (!(Math_GetDistXZ(lpMdlMng->Pos, EventPos) <= lpEventData->EventDist)) {
            continue;
        }
        if (lpEventData->EventAng != 0.0f) {
            Ang = Math_VectorToAngle(-(EventPos[0] - lpMdlMng->Pos[0]),
                                     -(EventPos[2] - lpMdlMng->Pos[2]));
            AngDistObj = Math_GetAngleDist(EventAng[1], CAE_WRAPF(Ang + CAE_PI));
            if (CAE_ABSF(AngDistObj) > 0.0174499992f * (float)lpEventData->EventAng) {
                continue;
            }
        }
        switch (lpEventData->EventKind) {
        case 8:
            E044Num = lpEventData->EventData1;
            bBlast = 1;
            if ((lpEventData->Flag1 == 0) && (*(u8 *)(lpMyCtrl + 0x188) == 0)) {
                bBlast = 0;
            }
            if (bBlast == 0) {
                continue;
            }
            SetBlast(0.0299999993f, 120.0f, EventPos, lpMdlMng->Pos, 0x28);
            if (lpEventData->EventSaveFlag != 0) {
                SetEventFlag(lpEventData->EventSaveFlag);
            }
            if (lpEventData->EventSaveFlag2 != 0) {
                ResetEventFlag(lpEventData->EventSaveFlag2);
            }
            if (lpEventData->EventData1 == 0) {
                continue;
            }
            if (lpEventData->Flag1 && *(u8 *)(lpMyCtrl + 0x188) == 0) {
                E044Num /= 2;
            }
            SetE044RandomAppear(lpMdlMng->Pos, E044Num, lpEventData->EventData2, 2.0f);
            continue;
        case 9:
            if (lpEventData->EventSaveFlag != 0) {
                if (CheckEventFlag(lpEventData->EventSaveFlag) != 0) {
                    continue;
                }
            }
            if (lpEventData->EventData1 == -1) {
                if (lpEventData->EventSaveFlag != 0) {
                    SetEventFlag(lpEventData->EventSaveFlag);
                }
                if (lpEventData->EventSaveFlag2 != 0) {
                    ResetEventFlag(lpEventData->EventSaveFlag2);
                }
                continue;
            } else {
                MapMdlIndex = GetMdlMngIndexByCtrlId(0, lpEventData->EventData1);
                if (CheckDrawMapByCamParam(MapMdlIndex) == 0) {
                    continue;
                }
                if (lpEventData->EventSaveFlag != 0) {
                    SetEventFlag(lpEventData->EventSaveFlag);
                }
                if (lpEventData->EventSaveFlag2 != 0) {
                    ResetEventFlag(lpEventData->EventSaveFlag2);
                }
                continue;
            }
        case 10:
            if (*(u8 *)(lpMyCtrl + 0x188) == 0) {
                continue;
            }
            if (lpEventData->EventSaveFlag != 0) {
                SetEventFlag(lpEventData->EventSaveFlag);
            }
            if (lpEventData->EventSaveFlag2 != 0) {
                ResetEventFlag(lpEventData->EventSaveFlag2);
            }
            if (CAE_ABSF(AngDistObj) < 1.57079637f) {
                if (lpEventData->EventSaveFlag != 0) {
                    SetEventFlag(lpEventData->EventSaveFlag + 1);
                }
                ChangeAnimParam(lpEventMdlMng, 0x67, 0.0f);
            } else {
                if (lpEventData->EventSaveFlag != 0) {
                    SetEventFlag(lpEventData->EventSaveFlag + 2);
                }
                ChangeAnimParam(lpEventMdlMng, 0x65, 0.0f);
            }
            if (lpEventData->Flag1) {
                lpEventMdlMng->CtrlMode = 4;
                lpEventMdlMng->State[8] = lpEventData->EventData1;
                lpEventMdlMng->State[9] = lpEventData->EventData2;
                continue;
            }
            if (rand() % 100 < lpEventData->EventData2) {
                SetE044RandomAppear(lpMdlMng->Pos, lpEventData->EventData1, 100, 8.0f);
            }
            continue;
        }
    }
    return;
}






extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern signed int SFX_AttachMdlMng(signed int, void *, unsigned short);
static inline void * GetAutoEventParts(s32 Type, s32 CtrlId);

void SetMapSfxData(void) {
    s32 i;
    u8 *lpSfxParts;
    u8 *lpSfxData;
    u8 *lpMdlMng;
    s32 MdlMngIndex;
    u8 *lpMapSfx;
    s32 MapMdlMngIndex;
    s32 count;

    count = *(u16 *)(lpMapFile + 0x18);
    lpSfxParts = *(u8 **)(lpMapFile + 0x50);
    lpMapSfx = (u8 *)MapSfxSt;
    do {
        memset(lpMapSfx, 0, 0x10);
        *(s32 *)(lpMapSfx + 4) = -1;
        lpMapSfx += 0x10;
    } while (lpMapSfx != (u8 *)(MapSfxSt + 0x100));
    i = 0;
    if (0 < count) do {
        lpSfxData = *(u8 **)(lpSfxParts + 0x38);
        switch (*(s32 *)(lpSfxData + 8)) {
        case 4:
            *(float *)(lpSfxParts + 0xc) = 1.0f;
            *(float *)(lpSfxParts + 0x10) = 0.01745f * (float)*(float *)(lpSfxParts + 0x10);
            *(float *)(lpSfxParts + 0x14) = 0.01745f * (float)*(float *)(lpSfxParts + 0x14);
            *(float *)(lpSfxParts + 0x18) = 0.01745f * (float)*(float *)(lpSfxParts + 0x18);
            lpMapSfx = (u8 *)MapSfxSt + *(u32 *)lpSfxData * 16;
            *lpMapSfx = 1;
            *(s32 *)(lpMapSfx + 4) = SFX_Create_OnAng(*(u16 *)(lpSfxParts + 0x34), (float *)lpSfxParts, (float *)(lpSfxParts + 0x10));
            break;
        default: {
            u8 *lpParts = (u8 *)GetAutoEventParts(*(s32 *)(lpSfxData + 8), *(s32 *)(lpSfxData + 4));
            if (lpParts == 0) goto next;
            switch (*(s32 *)(lpSfxData + 8)) {
            case 0:
                lpMdlMng = MdlMng;
                MdlMngIndex = GetMdlMngIndexByCtrlId(0, *(s32 *)(lpSfxData + 4));
                break;
            case 1:
                lpMdlMng = MdlMng + 0x5400;
                MdlMngIndex = GetMdlMngIndexByCtrlId(1, *(s32 *)(lpSfxData + 4));
                break;
            case 2:
                lpMdlMng = MdlMng + 0x119c0;
                MdlMngIndex = GetMdlMngIndexByCtrlId(2, *(s32 *)(lpSfxData + 4));
                break;
            case 7:
                lpMdlMng = MdlMng + 0xfc00;
                MdlMngIndex = GetMdlMngIndexByCtrlId(7, *(s32 *)(lpSfxData + 4));
                break;
            default:
                goto next;
            }
            lpMdlMng += MdlMngIndex * 0x1c0;
            lpMapSfx = (u8 *)MapSfxSt + *(u32 *)lpSfxData * 16;
            *lpMapSfx = 1;
            *(s32 *)(lpMapSfx + 4) = SFX_Create_OnAng(*(u16 *)(lpSfxParts + 0x34), (float *)lpParts, (float *)(lpParts + 0x10));
            if (*(s32 *)(lpMapSfx + 4) != -1) {
                SFX_AttachMdlMng(*(s32 *)(lpMapSfx + 4), lpMdlMng, 0);
            }
            }
        }
        if (lpSfxData[0x2e] & 1) {
            MapMdlMngIndex = GetMdlMngIndexByCtrlId(0, *(s32 *)(lpSfxData + 0xc));
            *(u8 **)(lpMapSfx + 8) = MdlMng + MapMdlMngIndex * 0x1c0;
        }
next:
        i++;
        lpSfxParts += 0x50;
    } while (i < count);
}









void SetMapSeData(void) {
    s32 index;
    u32 count;
    u8 *part;
    u8 *params;
    u8 *state;
    u32 range;
    u32 file;
    file=lpMapFile;
    state=(u8 *)MapSeSt;
    count=*(u16 *)(file+0x1c);
    part=*(u8 **)(file+0x58);
    do {
        memset(state,0,0x30);
        *(u32 *)(state+0x24)=0x51;
        state+=0x30;
    } while(state!=(u8 *)(MapSeSt+0x240));
    index=0;
    if(0<(s32)count) do {
        u32 event;
        params=*(u8 **)(part+0x38);
        *(float *)(part+0xc)=1.0f;
        *(float *)(part+0x10)=0.01745f*(float)*(float *)(part+0x10);
        *(float *)(part+0x14)=0.01745f*(float)*(float *)(part+0x14);
        *(float *)(part+0x18)=0.01745f*(float)*(float *)(part+0x18);
        event=*(u32 *)(params+0x1c);
        if(event!=0 && CheckEventFlag(event)!=0) goto next;
        if(!(params[0x2c]&1)) {
            u32 id;
            u32 map;
            u32 type;
            u8 *cursor;
            u8 *selected;
            s32 total;
            s32 i;
            type=*(u32 *)(params+4);
            switch(type) {
            case 6:
                state=(u8 *)MapSeSt+*(u32 *)params*0x30;
                state[0x10]=1;
                sceVu0CopyVector(state,part);
                goto sound;
            default:break;
            }
            map=*(volatile u32 *)&lpMapFile;
            id=*(volatile u32 *)(params+8);
            switch(type) {
            case 0:cursor=*(u8 **)(map+0x40);break;
            case 1:cursor=*(u8 **)(map+0x44);break;
            case 2:cursor=*(u8 **)(map+0x48);break;
            case 3:cursor=*(u8 **)(map+0x4c);break;
            case 4:cursor=*(u8 **)(map+0x50);break;
            case 5:cursor=*(u8 **)(map+0x54);break;
            case 6:cursor=*(u8 **)(map+0x58);break;
            case 7:cursor=*(u8 **)(map+0x5c);break;
            default:cursor=0;
            }
            switch(type) {
            case 0:total=*(u16 *)(map+0x10);break;
            case 1:total=*(u16 *)(map+0x12);break;
            case 2:total=*(u16 *)(map+0x14);break;
            case 3:total=*(u16 *)(map+0x16);break;
            case 4:total=*(u16 *)(map+0x18);break;
            case 5:total=*(u16 *)(map+0x1a);break;
            case 6:total=*(u16 *)(map+0x1c);break;
            case 7:total=*(u16 *)(map+0x1e);break;
            default:total=0;
            }
            i=0;
            if(0<total) do {
                if(**(u32 **)(cursor+0x38)==id) {selected=cursor;goto found;}
                ++i;cursor+=0x50;
            } while(i<total);
            selected=0;
found:
            if(selected!=0) {
                s32 volume;
                state=(u8 *)MapSeSt+*(u32 *)params*0x30;
                state[0x10]=1;
                sceVu0CopyVector(state,selected);
sound:
                range=*(u32 *)(params+0x30);
                if(range==0)volume=*(s32 *)(params+0xc);
                else {
                    volume=((u32)rand()%range)*2-range;
                    volume+=*(s32 *)(params+0xc);
                    if(volume<0)volume=0;
                }
                *(u32 *)(state+0x14)=*(u32 *)(part+0x34);
                *(s32 *)(state+0x18)=volume;
                *(u32 *)(state+0x20)=(u32)params;
                if(*(u32 *)(params+0x24)==0) *(s32 *)(state+0x1c)=-1;
            }
        }
next:
        ++index;part+=0x50;
    } while(index<(s32)count);
}



extern void *GetFreeMovePath(void);

static inline u8 * FindPathParts(s32 id) {
    s32 n = *(u16 *)(lpMapFile + 0x16);
    u8 *p = (u8 *)*(u32 *)(lpMapFile + 0x4c);
    s32 k;
    for (k = 0; k < n; k++, p += 0x50) {
        if (**(s32 **)(p + 0x38) == id) {
            return p;
        }
    }
    return 0;
}

void SetMapPathData(void) {
    int i;
    int PathIndex;
    int PathNum;
    u8 *lpPathParts1;
    u8 *lpPathParts2;
    u8 *lpPathData1;
    u8 *lpPathData2;
    u8 *lpPathMng;
    u8 *node;

    PathNum = *(u16 *)(lpMapFile + 0x16);
    lpPathParts1 = (u8 *)*(u32 *)(lpMapFile + 0x4c);
    for (i = 0; i < PathNum; i++) {
        *(float *)(lpPathParts1 + 0xc) = 1.0f;
        *(float *)(lpPathParts1 + 0x10) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x10);
        *(float *)(lpPathParts1 + 0x14) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x14);
        *(float *)(lpPathParts1 + 0x18) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x18);
        lpPathParts1 += 0x50;
    }
    lpPathParts1 = (u8 *)*(u32 *)(lpMapFile + 0x4c);
    for (i = 0; i < PathNum; i++, lpPathParts1 += 0x50) {
        lpPathData1 = *(u8 **)(lpPathParts1 + 0x38);
        *(float *)(lpPathParts1 + 0xc) = 1.0f;
        *(float *)(lpPathParts1 + 0x10) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x10);
        *(float *)(lpPathParts1 + 0x14) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x14);
        *(float *)(lpPathParts1 + 0x18) = 0.01745f * (float)*(float *)(lpPathParts1 + 0x18);
        if (*(s32 *)(lpPathData1 + 0xc) < 0) {
            lpPathMng = (u8 *)GetFreeMovePath();
            PathIndex = 0;
            lpPathParts2 = lpPathParts1;
            *(u8 **)(lpPathMng + 8) = lpPathMng + 0x10;
            node = lpPathMng;
            *(u32 *)(lpPathMng + 0xc) = 0;
            *(u8 *)(lpPathMng + 3) = *(s32 *)(lpPathData1 + 8);
            *(s32 *)(lpPathMng + 4) = *(s32 *)(lpPathData1 + 4);
            while (1) {
                lpPathData2 = *(u8 **)(lpPathParts2 + 0x38);
                sceVu0CopyVector(node + 0x10, lpPathParts2);
                if (*(s32 *)(lpPathData2 + 0xc) < 0) {
                    *(u32 *)(node + 0x20) = 0;
                } else {
                    *(u8 **)(node + 0x20) = lpPathMng + (PathIndex - 1) * 0x20 + 0x10;
                }
                if (*(s32 *)(lpPathData2 + 0x10) < 0) {
                    *(u32 *)(lpPathMng + PathIndex * 0x20 + 0x24) = 0;
                    if (*(s32 *)(lpPathData2 + 0x10) == -2) {
                        *(u8 *)(lpPathMng + 2) = 1;
                        *(u8 **)(lpPathMng + PathIndex * 0x20 + 0x24) = lpPathMng + 0x10;
                        *(u8 **)(lpPathMng + 0x20) = lpPathMng + PathIndex * 0x20 + 0x10;
                    }
                    break;
                }
                *(u8 **)(node + 0x24) = lpPathMng + (PathIndex + 1) * 0x20 + 0x10;
                lpPathParts2 = FindPathParts(*(s32 *)(lpPathData2 + 0x10));
                node += 0x20;
                PathIndex++;
            }
        }
    }
}



/* UpdateMapSfx @ 0x14C910 .. 0x14C9C0 (0xb0 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0014C928
 */


void UpdateMapSfx(void) {
    u8 *s0;
    u32 a0;
    u32 v1;
    s32 v0;
    u32 s1;

    s0 = (u8 *)MapSfxSt;
    do {
        v1 = *(u8 *)s0;
        if (v1 != 0) {
            a0 = *(s32 *)(s0 + 8);
            if (a0 != 0) {
                v1 = (u32)MdlMng;
                v0 = CheckDrawMapByCamParam((s32)((u8 *)a0 - (u8 *)MdlMng) / (s32)(0x1c0));
                a0 = *(s32 *)(s0 + 4);
                s1 = v0;
                SFX_EnableDraw(a0, s1, 1);
                a0 = *(s32 *)(s0 + 4);
                SFX_EnableAction(a0, s1, 1);
            }
        }
        s0 = (u8 *)(s0 + 0x10);
    } while (s0 != (u8 *)(MapSfxSt + 0x100));
    return;
}


/* UpdateMapSe @ 0x14C670 .. 0x14C910 (0x2a0 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0014C690
 */

extern signed int SND_Play3D(signed int, signed int, signed int, void *, float);

void UpdateMapSe(void) {
    u32 s3;
    u32 s0;
    u8 *s2;
    u8 *s1;
    u32 a0;
    u32 v1;
    u32 v0;
    s32 hi;

    s2 = (u8 *)MapSeSt;
    do {
        v1 = *(u8 *)(s2 + 0x10);
        if (v1 != 0) {
            s1 = (u8 *)*(s32 *)(s2 + 0x20);
            a0 = *(s32 *)(s1 + 0x1c);
            if (a0 != 0) {
                v0 = CheckEventFlag(a0);
                if (v0 != 0) {
                    a0 = *(s32 *)(s2 + 0x24);
                    SND_Stop(a0);
                    *(u8 *)(s2 + 0x10) = 0;
                }
            }
            v1 = *(s32 *)(s2 + 0x18);
            if (v1 == 0 && (s32)*(s32 *)(s2 + 0x1c) <= 0) {
                s0 = *(u32 *)(s1 + 0x34);
                if (s0 == 0) s0 = *(s16 *)(s1 + 0x14);
                else {
                    v0 = rand();
                    hi = v0 % s0;
                    v0 = *(s32 *)(s1 + 0x14);
                    v1 = hi << 1;
                    v1 -= s0;
                    s0 = (s16)(v1 + v0);
                    if ((s32)s0 < 0) s0 = 0;
                    else if ((s32)s0 > 127) s0 = 127;
                }
                s3 = *(u32 *)(s1 + 0x38);
                if (s3 == 0) s3 = *(s16 *)(s1 + 0x20);
                else {
                    v0 = rand();
                    hi = v0 % s3;
                    v0 = *(s32 *)(s1 + 0x20);
                    v1 = hi << 1;
                    v1 -= s3;
                    s3 = (s16)(v1 + v0);
                    if ((s32)s3 < -2400) s3 = -2400;
                    else if ((s32)s3 > 2400) s3 = 2400;
                }
                a0 = *(s32 *)(s2 + 0x24);
                SND_Stop(a0);
                a0 = *(s32 *)(s2 + 0x14);
                v0 = SND_Play3D(a0, s0, s3, (void *)s2, *(float *)(s1 + 0x10));
                *(u32 *)(s2 + 0x24) = v0;
                v1 = *(s32 *)(s1 + 0xc);
                if (v1 != 0) {
                    u32 delta;
                    u32 selected;
                    s0 = *(s32 *)(s1 + 0x30);
                    if (s0 == 0) {
                        selected = v1;
                    } else {
                        v0 = rand();
                        selected = *(s32 *)(s1 + 0xc);
                        delta = v0 % s0;
                        delta = delta << 1;
                        delta = delta - s0;
                        selected = (s32)delta + (s32)selected;
                        if ((s32)selected < 0) {
                            selected = 0;
                        }
                    }
                    *(u32 *)(s2 + 0x18) = selected;
                } else {
                    v1 = -1;
                    *(u32 *)(s2 + 0x18) = v1;
                }
                v1 = *(s32 *)(s1 + 0x24);
                if (v1 != 0) {
                    u32 delta;
                    u32 selected;
                    s0 = *(s32 *)(s1 + 0x3c);
                    if (s0 == 0) {
                        selected = v1;
                    } else {
                        v0 = rand();
                        selected = *(s32 *)(s1 + 0x24);
                        delta = v0 % s0;
                        delta = delta << 1;
                        delta = delta - s0;
                        selected = (s32)delta + (s32)selected;
                        if ((s32)selected < 0) {
                            selected = 0;
                        }
                    }
                    *(u32 *)(s2 + 0x1c) = selected;
                } else {
                    v1 = -1;
                    *(u32 *)(s2 + 0x1c) = v1;
                }
            }
            v1 = *(s32 *)(s2 + 0x1c);
            if (v1 == 0) {
                a0 = *(s32 *)(s2 + 0x24);
                SND_Stop(a0);
            }
            v1 = *(s32 *)(s2 + 0x1c);
            if ((s32)v1 > 0) {
                v1 = v1 + -1;
                *(u32 *)(s2 + 0x1c) = v1;
            } else {
                v1 = *(s32 *)(s2 + 0x18);
                if ((s32)v1 > 0) {
                    v1 = v1 + -1;
                    *(u32 *)(s2 + 0x18) = v1;
                }
            }
        }
        s2 = (u8 *)(s2 + 0x30);
    } while (s2 != (u8 *)(MapSeSt + 0x240));
    return;
}



/* GetMapSfxHdl @ 0x14C650 .. 0x14C668 (0x18 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x14c664 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int GetMapSfxHdl(signed int a0 /* r4 */) {
    u32 *v0;

    v0 = (u32 *)((u8 *)MapSfxSt + 4);
    return *(s32 *)(u32 *)(s32)((u8 *)v0 + (s32)((u32)a0 << 4));
}





/* CheckLookAtEvent @ 0x14BF00 .. 0x14C64C (0x74c bytes, frame 0xf0) */
extern signed int CheckMyHeadUpdate(void *);

signed int CheckLookAtEvent(void *lpMdlMng_, float Dist, float AngY, float (*lpTargetPos)[4]) {
    u32 tp __attribute__((aligned(16)));
    struct dw_347896 *lpMdlMng;
    int i;
    struct dw_345414 *lpEventParts;
    struct dw_353246 *lpEventData;
    struct dw_353246 *lpLookEvent;
    float EventPos[4];
    float LookPos[4];
    float LookDist;
    float EventDist;
    float Ang;
    float AngDist;
    struct dw_347896 *lpLookEne;
    struct dw_347896 *lpEventMdlMng;
    int EventMdlMngIndex;
    int EventNum;
    struct dw_345414 *lpParts;

    tp = (u32)lpTargetPos;
    lpLookEne = 0;
    lpMdlMng = (struct dw_347896 *)lpMdlMng_;
    lpLookEvent = 0;
    EventNum = *(u16 *)(lpMapFile + 0x1a);
    lpEventParts = (struct dw_345414 *)*(u32 *)(lpMapFile + 0x54);
    if (CheckMyHeadUpdate(lpMdlMng_) == 0) {
        return 0;
    }
    for (i = 0; i < EventNum; i++, lpEventParts++) {
        lpEventData = (struct dw_353246 *)lpEventParts->MapObjData;
        if (lpEventData->NeckLevel == 0) {
            continue;
        }
        if (lpEventData->EventSaveCtrlFlag != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag) != 0) {
                continue;
            }
        }
        if (lpEventData->EventSaveCtrlFlag2 != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag2) == 0) {
                continue;
            }
        }
        switch (lpEventData->FollowType) {
        case 5:
            sceVu0CopyVector(EventPos, lpEventParts->Pos);
            break;
        default:
            lpParts = (struct dw_345414 *)GetAutoEventParts(lpEventData->FollowType,
                                                            lpEventData->FollowId);
            if (lpParts == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpParts->Pos);
            break;
        }
        lpEventMdlMng = 0;
        switch (lpEventData->FollowType) {
        case 0:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(0, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + EventMdlMngIndex * 0x1c0);
            break;
        case 1:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(1, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x30) * 0x1c0);
            break;
        case 2:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0xa1) * 0x1c0);
            break;
        case 7:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(7, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x90) * 0x1c0);
            break;
        }
        if (lpEventMdlMng != 0) {
            if (lpEventMdlMng->bUse == 0 || lpEventMdlMng->bErase == 0 ||
                *(float *)((u8 *)lpEventMdlMng + 0x10c) <= 0.0f) {
                continue;
            }
        }
        EventDist = Math_GetDistXZ(lpMdlMng->Pos, EventPos);
        if (!(EventDist <= Dist)) {
            continue;
        }
        Ang = Math_VectorToAngle(-(EventPos[0] - lpMdlMng->Pos[0]),
                                 -(EventPos[2] - lpMdlMng->Pos[2]));
        AngDist = CAE_ABSF(Math_GetAngleDist(lpMdlMng->Ang[1], Ang));
        if (!(CAE_ABSF(AngDist) <= AngY)) {
            continue;
        }
        if (lpEventData->MapParts != -1) {
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(0, lpEventData->MapParts);
            if (CheckDrawMapByCamParam((s32)(EventMdlMngIndex * 0x1c0) / (s32)(0x1c0)) == 0) {
                continue;
            }
        }
        if (lpEventData->FollowType == 1) {
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (GetMdlMngIndexByCtrlId(lpEventData->FollowType, lpEventData->FollowId) + 0x30) * 0x1c0);
            if (*(u32 *)(*(u32 *)((u8 *)lpEventMdlMng + 0xc) + 0x4c) != 0) {
                EventPos[1] = EventPos[1] - (float)*(u16 *)(*(u32 *)(*(u32 *)((u8 *)lpEventMdlMng + 0xc) + 0x4c) + 0x18);
            }
        }
        if (lpLookEvent == 0) {
            lpLookEvent = lpEventData;
            sceVu0CopyVector(LookPos, EventPos);
            LookDist = EventDist;
        } else if (!(lpEventData->NeckLevel < lpLookEvent->NeckLevel)) {
            if (!(LookDist < EventDist)) {
                lpLookEvent = lpEventData;
                sceVu0CopyVector(LookPos, EventPos);
                LookDist = EventDist;
            }
        }
    }
    if (lpLookEvent == 0 || lpLookEvent->NeckLevel != 4) {
        struct dw_347896 *lpEne;
        for (lpEne = (struct dw_347896 *)(MdlMng + 0x119c0); (u8 *)lpEne != MdlMng + 0x17140; lpEne++) {
            if (lpEne->bUse != 0 && lpEne->Hp > 0) {
                if (lpEne->bErase == 0 && lpEne->bEraseByMapDraw == 0) {
                    EventDist = Math_GetDistXZ(lpMdlMng->Pos, lpEne->Pos);
                    if (EventDist <= Dist) {
                        Ang = Math_VectorToAngle(-(lpEne->Pos[0] - lpMdlMng->Pos[0]),
                                                 -(lpEne->Pos[2] - lpMdlMng->Pos[2]));
                        AngDist = CAE_ABSF(Math_GetAngleDist(lpMdlMng->Ang[1], Ang));
                        if (CAE_ABSF(AngDist) <= AngY) {
                            if (lpLookEne == 0) {
                                lpLookEne = lpEne;
                                sceVu0CopyVector(LookPos, lpEne->Pos);
                                LookDist = EventDist;
                                LookPos[1] = LookPos[1] - 0.8f * lpEne->HitSize;
                            } else if (!(LookDist < EventDist)) {
                                lpLookEne = lpEne;
                                sceVu0CopyVector(LookPos, lpEne->Pos);
                                LookDist = EventDist;
                                LookPos[1] = LookPos[1] - 0.8f * lpEne->HitSize;
                            }
                        }
                    }
                }
            }
        }
    }
    if (lpLookEvent == 0 && lpLookEne == 0) {
        return 0;
    }
    sceVu0CopyVector((float(*)[4])tp, LookPos);
    (*(float(*)[4])tp)[3] = 1.0f;
    return 1;
}





extern void SetScriptDirect(signed int);

signed int CheckItemUseEvent(unsigned short ItemId) {
    int i;
    struct dw_345414 *lpEventParts;
    struct dw_353246 *lpEventData;
    float EventPos[4];
    float EventAng[4];
    struct dw_347896 *lpMdlMng;
    float Ang;
    float AngDistObj;
    float AngDistMy;
    int EventNum;
    struct dw_345414 *lpParts;

    lpMdlMng = (struct dw_347896 *)(MdlMng + 0x11800);
    EventNum = *(u16 *)(lpMapFile + 0x1a);
    lpEventParts = (struct dw_345414 *)*(u32 *)(lpMapFile + 0x54);
    for (i = 0; i < EventNum; i++) {
        lpEventData = (struct dw_353246 *)lpEventParts[i].MapObjData;
        if (lpEventData->EventData2 != ItemId) {
            continue;
        }
        if (lpEventData->EventSaveCtrlFlag != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag) != 0) {
                continue;
            }
        }
        if (lpEventData->EventSaveCtrlFlag2 != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag2) == 0) {
                continue;
            }
        }
        switch (lpEventData->FollowType) {
        case 5:
            sceVu0CopyVector(EventPos, lpEventParts[i].Pos);
            sceVu0CopyVector(EventAng, lpEventParts[i].Ang);
            break;
        default:
            lpParts = (struct dw_345414 *)GetAutoEventParts(lpEventData->FollowType,
                                                            lpEventData->FollowId);
            if (lpParts == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpParts->Pos);
            sceVu0CopyVector(EventAng, lpParts->Ang);
            break;
        }
        if (!(Math_GetDistXZ(lpMdlMng->Pos, EventPos) <= lpEventData->EventDist)) {
            continue;
        }
        Ang = Math_VectorToAngle(-(EventPos[0] - lpMdlMng->Pos[0]),
                                 -(EventPos[2] - lpMdlMng->Pos[2]));
        AngDistObj = CAE_ABSF(Math_GetAngleDist(EventAng[1], CAE_WRAPF(Ang + CAE_PI)));
        AngDistMy = CAE_ABSF(Math_GetAngleDist(lpMdlMng->Ang[1], Ang));
        if (CAE_ABSF(AngDistObj) <= 0.0174499992f * (float)lpEventData->EventAng) {
            if (CAE_ABSF(AngDistMy) <= 0.785398185f) {
                SetScriptDirect(lpEventData->EventData1);
                if (lpEventData->EventSaveFlag != 0) {
                    SetEventFlag(lpEventData->EventSaveFlag);
                }
                if (lpEventData->EventSaveFlag2 != 0) {
                    ResetEventFlag(lpEventData->EventSaveFlag2);
                }
                return 1;
            }
        }
    }
    return 0;
}





signed int CheckHeartBeatEvent(void *a0 /* r4 */) {
    int EventNum;
    int i;
    struct dw_345414 *lpParts;
    struct dw_347896 *lpMdlMng;
    struct dw_345414 *lpEventParts;
    struct dw_353246 *lpEventData;
    struct dw_347896 *lpEventMdlMng;
    float EventPos[4];
    float EventAng[4];
    float Ang;
    float AngDistObj;
    int EventMdlMngIndex;

    lpMdlMng = (struct dw_347896 *)a0;
    EventNum = *(u16 *)(lpMapFile + 0x1a);
    lpEventParts = (struct dw_345414 *)*(u32 *)(lpMapFile + 0x54);
    for (i = 0; i < EventNum; i++) {
        lpEventData = (struct dw_353246 *)lpEventParts[i].MapObjData;
        if (lpEventData->EventKind != 7) {
            continue;
        }
        if (lpEventData->EventSaveCtrlFlag != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag) != 0) {
                continue;
            }
        }
        if (lpEventData->EventSaveCtrlFlag2 != 0) {
            if (CheckEventFlag(lpEventData->EventSaveCtrlFlag2) == 0) {
                continue;
            }
        }
        switch (lpEventData->FollowType) {
        case 5:
            sceVu0CopyVector(EventPos, lpEventParts[i].Pos);
            sceVu0CopyVector(EventAng, lpEventParts[i].Ang);
            break;
        case 1:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(1, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x30) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        case 2:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(2, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0xa1) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        case 7:
            EventMdlMngIndex = GetMdlMngIndexByCtrlId(7, lpEventData->FollowId);
            lpEventMdlMng = (struct dw_347896 *)(MdlMng + (EventMdlMngIndex + 0x90) * 0x1c0);
            if (lpEventMdlMng->bUse == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpEventMdlMng->Pos);
            sceVu0CopyVector(EventAng, lpEventMdlMng->Ang);
            break;
        default:
            lpParts = (struct dw_345414 *)GetAutoEventParts(lpEventData->FollowType,
                                                            lpEventData->FollowId);
            if (lpParts == 0) {
                continue;
            }
            sceVu0CopyVector(EventPos, lpParts->Pos);
            sceVu0CopyVector(EventAng, lpParts->Ang);
            break;
        }
        if (!(Math_GetDistXZ(lpMdlMng->Pos, EventPos) <= lpEventData->EventDist)) {
            continue;
        }
        Ang = Math_VectorToAngle(-(EventPos[0] - lpMdlMng->Pos[0]),
                                 -(EventPos[2] - lpMdlMng->Pos[2]));
        AngDistObj = CAE_ABSF(Math_GetAngleDist(EventAng[1], CAE_WRAPF(Ang + CAE_PI)));
        if (CAE_ABSF(AngDistObj) <= 0.0174499992f * (float)lpEventData->EventAng) {
            return 1;
        }
    }
    return 0;
}


/* CheckSaveEvent @ 0x14B420 .. 0x14B554 (0x134 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14b440 writes a register its branch at 0x14b43c reads
 */


void CheckSaveEvent(void) {
    u32 v1;
    u32 a0;
    u32 v0;
    u8 *s1;
    u32 s0;
    u32 a1;

    v1 = 3;
    a0 = *(s32 *)SaveEvent;
    switch (a0) {
    case 1:
        v0 = KnMsgMng_CheckMsgNone();
        if (v0 == 0) {
            break;
        }
        v1 = *(u16 *)((u8 *)&SaveEvent + 4);
        if (v1 != 0) {
            v0 = KnMsgMng_GetSelectNum();
            if (v0 == 0) {
                KnMenuMng_CallSave();
                v1 = 2;
                *(u32 *)SaveEvent = v1;
                break;
            } else {
                *(u32 *)SaveEvent = 0;
                break;
            }
        } else {
            *(u32 *)SaveEvent = 0;
            break;
        }
    case 2:
        s1 = (u8 *)MdlMng + 0x11800;
        v1 = 0x59;
        a0 = *(s16 *)(((u8 *)s1 + 0x104));
        s0 = *(s32 *)(((u8 *)s1 + 0x148));
        if (a0 == v1) {
            a0 = *(s32 *)(((u8 *)s1 + 0x100));
            v0 = CheckAnimEndFrame((void *)a0);
            if (v0 == 0) {
                break;
            }
            SetMyControlOn();
            a0 = (u32)s1;
            a1 = s0;
            SetMyStay((void *)a0, (void *)a1, 0);
            *(u32 *)SaveEvent = 0;
            break;
        } else {
            *(u32 *)SaveEvent = 0;
            break;
        }
    case 3:
        a1 = 1;
        a0 = 0x33;
        ReadDramaData(a0, a1, (s32)a1);
        *(u32 *)SaveEvent = 0;
    }
    return;
}


/* InitSaveEvent @ 0x14B400 .. 0x14B414 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x14b40c leaves the function
 *   return value dropped, call kept: the function is void
 */


void InitSaveEvent(void) {
    memset((u8 *)SaveEvent, 0, 0x14);
    return;
}


/* SetSaveBoat @ 0x14B2C0 .. 0x14B3FC (0x13c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x14b3cc
 *   fpu: float literal 0x00000000 at 0x14b3dc
 *   cfg: loop body is not one contiguous region: .L0014B310
 *   cfg: kept branch: 0x14b310 if (..) goto .L0014B328
 *   cfg: kept goto: 0x14b320 -> .L0014B340
 */

extern void SetObjMovePath(void *, signed int, unsigned short, unsigned short);
extern void SetMyControlOff(void);
extern void SetHokanFrame(void *, float);

void SetSaveBoat(void) {
    struct BoatItem {
        u8 pad[0x38];
        u32 *id;
        u8 tail[0x14];
    };
    register struct dw_347896 *model;
    register struct BoatItem *cursor;
    register struct BoatItem *boat;
    register u32 a2;
    register u32 a1;
    register u32 a0;
    register u32 v0;
    register s32 v1;

    v1 = 0xb;
    a1 = *(s32 *)(SaveEvent + 4);
    a0 = *(u16 *)*(s32 *)((*(s32 *)((a1 + 0xc)) + 0x4c));
    if (a0 == (u32)v1) {

        v0 = lpMapFile;
        a2 = *(s32 *)(SaveEvent + 3);
        {
            register s32 count;
            register s32 index;
            count = *(u16 *)((v0 + 0x12));
            cursor = (struct BoatItem *)*(u32 *)(v0 + 0x44);
            index = 0;

            if (0 < count) {
                do {
                    v0 = *cursor->id;
                    if (v0 == a2) {
                        boat = cursor;
                        goto foundBoat;
                    }
                    ++index;
                    ++cursor;
                } while (index < count);
            }
            boat = 0;
        }
foundBoat: {
        model = (struct dw_347896 *)(MdlMng + 0x11800);
        sceVu0CopyVector((void *)(s32)(a1 + 0x20), (void *)boat);
        v0 = *(s32 *)(SaveEvent + 4);
        sceVu0CopyVector((void *)(s32)(v0 + 0x30), (void *)((u8 *)boat + 0x10));
        a2 = 1;
        v1 = 0x3f800000;
        *(u8 *)((*(s32 *)(SaveEvent + 4) + 2)) = 0;
        *(u8 *)((*(s32 *)(SaveEvent + 4) + 0x131)) = a2;
        *(u8 *)((*(s32 *)(SaveEvent + 4) + 0x132)) = a2;
        *(u32 *)((*(s32 *)(SaveEvent + 4) + 0x10c)) = v1;
        v0 = *(s32 *)(SaveEvent + 4);
        *(u32 *)((v0 + 0x158)) = a2;
        a0 = *(s32 *)(SaveEvent + 4);
        a1 = *(s32 *)(SaveEvent + 2);
        SetObjMovePath((void *)a0, a1, a2, 0);
        SetMyControlOff();
        ChangeAnimParam((void *)model, 0x59, 0.0f);
        SetHokanFrame((void *)model, 0.0f);
        }
    }
    return;
}









/* SetSaveDrama @ 0x14B250 .. 0x14B2BC (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x14b268 if (..) goto .L0014B280
 *   cfg: kept goto: 0x14b278 -> .L0014B2B0
 */


u8 * SetSaveDrama(void) {
    u32 v0;
    u32 v1;
    s32 a0;

    v0 = *(u8 *)((u8 *)&GameSt + 0x14);
    if (v0 == 0) {
        v0 = 0x33;
        v1 = *(u8 *)((u8 *)&GameSt + 9);
        if (v1 == v0) {
            goto _L0014B280;
        }
    }
    v0 = 0;
    goto _L0014B2B0;
    _L0014B280:;
    a0 = 0x47f;
    v0 = CheckEventFlag(a0);
    if (v0 != 0) {
        v0 = 0;
    } else {
        a0 = 0x47f;
        SetEventFlag(a0);
        v1 = 3;
        v0 = 1;
        *(u32 *)SaveEvent = v1;
    }
    _L0014B2B0:;
    return (u8 *)v0;
}


/* GetMapAmbient @ 0x14B0E0 .. 0x14B244 (0x164 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x14b0fc
 *   fpu: mtc1 reinterprets v1 at 0x14b110
 *   fpu: float literal 0x42fe0000 at 0x14b128
 *   fpu: mtc1 reinterprets v0 at 0x14b148
 *   stack: address of the slot at 0x14 escapes at 0x14b154
 *   fpu: mtc1 reinterprets v1 at 0x14b15c
 *   fpu: float literal 0x42fe0000 at 0x14b174
 *   fpu: mtc1 reinterprets v0 at 0x14b194
 *   stack: address of the slot at 0x18 escapes at 0x14b1a0
 *   fpu: mtc1 reinterprets v1 at 0x14b1a8
 *   fpu: float literal 0x42fe0000 at 0x14b1c0
 *   fpu: float literal 0x40000000 at 0x14b1d8
 *   fpu: float literal 0x40000000 at 0x14b1f8
 *   fpu: float literal 0x40000000 at 0x14b218
 *   stack: address of the slot at 0x10 escapes at 0x14b230
 *   a0 forwarded to sceVu0CopyVector
 */

extern void sceVu0CopyVector(void *, void *);

void GetMapAmbient(void *a0 /* r4 */) {
    u8 *a3;
    s32 v1;
    u32 v0;
    float f1;
    float f1_v1; // f1
    float f1_v2; // f1
    float f1_v3; // f1
    float f1_v4; // f1
    float f0;
    float f0_v1; // f0
    u8 stackFrame_10[16] __attribute__((aligned(16)));

    v0 = lpMapFile;
    a3 = (u8 *)(s32)(v0 + 0x80);
    v0 = *(u8 *)((v0 + 0x84));
    f0 = 127.0f;
    *(f32 *)((u8 *)&stackFrame_10[0]) = ((float)(float)v0 / 127.0f);
    v0 = *(u8 *)(a3 + 5);
    f0_v1 = 127.0f;
    ((f32 *)stackFrame_10)[1] = ((float)(float)v0 / 127.0f);
    v0 = *(u8 *)(a3 + 6);
    v1 = 0x3f800000;
    f1 = 127.0f;
    f1_v1 = ((float)(float)v0 / 127.0f);
    v0 = 0x40000000;
    ((f32 *)stackFrame_10)[2] = f1_v1;
    f1_v2 = *(float *)((u8 *)&stackFrame_10[0]);
    ((u32 *)stackFrame_10)[3] = 0x3f800000;
    if (!(f1_v2 <= 2.0f)) {
        *(f32 *)((u8 *)&stackFrame_10[0]) = 2.0f;
    }
    v0 = 0x40000000;
    f1_v3 = ((float *)stackFrame_10)[1];
    if (!(f1_v3 <= 2.0f)) {
        ((f32 *)stackFrame_10)[1] = 2.0f;
    }
    v0 = 0x40000000;
    f1_v4 = ((float *)stackFrame_10)[2];
    if (!(f1_v4 <= 2.0f)) {
        ((f32 *)stackFrame_10)[2] = 2.0f;
    }
    sceVu0CopyVector(a0, (void *)(float *)((u8 *)&stackFrame_10[0]));
    return;
}

/* GetMapGlareID @ 0x14B0D0 .. 0x14B0DC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x14b0d8 computes the return value
 */


u8 GetMapGlareID(void) {
    u8 *v0;

    v0 = (u8 *)lpMapFile;
    return *(u8 *)(((u8 *)v0 + 0x88));
}

static u32 MapSeSt[0x240];
static u32 MapSfxSt[0x100];
static u32 SaveEvent[0x5];
static u32 lpMapFile;
