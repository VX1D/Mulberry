#include "common.h"
typedef struct { u8 _p[0x120]; int Hp; u8 _q[0x1c0-0x124]; } MDLMNG;
extern MDLMNG MdlMng[770];
#define MdlMngB (MdlMng[0]._p)




extern signed int KnMenuMng_GetCursorId(int, signed int);
extern u32 MenuModelPosState[];
extern u32 MenuModelTargetPosOffset[];
extern u32 MenuModelDefPos[];

#define KN_MDLMNG ((struct KNMDL_MNG *)MdlMngB)
#define KN_MDLDATA(n) (&MdlData[(n) * (0x680 / 4)])
#define KN_DEFPOS(k, j) (*(float *)(MenuModelDefPos + (k) * 4 + (j)))
#define KN_MDL 754
#define KN_SET_DEFPOS(k, x, y, z, s) if (pMdlMng[k].bUse) { KN_DEFPOS(k, 0) = x; KN_DEFPOS(k, 1) = y; KN_DEFPOS(k, 2) = z; KN_DEFPOS(k, 2) *= s; KN_DEFPOS(k, 3) = 1.0f; fsvu0_CopyVectorF(pMdlMng[k].Pos, (float *)(MenuModelDefPos + (k) * 4)); pMdlMng[k].bErase = 1; }
extern signed int MngState_DrawExeCheck(void *);
extern void FlushCache(int);
extern void FreeMdlMng(void *);
extern signed int CsMngFreeRtaData(void *);
extern unsigned int SetMdlMng(void *, void *);
extern signed int CsMngMakeRtaData(void *);
extern void SetMdlShiftTexPacket(void *, void *, char *);
extern void fsvu0_CopyVectorF(float *, float *);
extern u32 MdlData[];
extern u32 pKnMenuModelMng;
extern void FreeTexList(void *);
extern void MemFree(void *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern void ReadTexList(char *, void **, signed int, signed int);
extern int FileCheckAsyncBusy(void);
extern void FileBackReadControl(void);
extern u32 s_pIconTexList;
extern u32 s_pMenuMapIconDataHeader;
extern u8 s_ctrler_state;
extern u32 s_MoveMentHelpId;
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int CsMngRtaSetMat(unsigned int, void *, int);
extern u8 GameSt[];
extern u32 s_ctrler_state_init_on;
extern u32 MenuModelDefPos[];
extern u32 g_ZeroVec[];
extern u32 g_UnitMat[];
extern signed int MngState_Init(void *);
void Menu_SetModelState(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */,
        void *a3 /* r7 */);
signed int KnMenuModelMng_ReMakeMdl(int load_flag);
u32 KnMenuModelMng_Delete(void);
signed int Menu_ReLoadFile_MapIconData(signed int a0 /* r4 */);
s8 KnMenuModelMng_GetCtrlerState(void);
u32 Menu_GetMovementHelpId(void);
u32 Menu_CheckMapMove(void);
u32 KnMenuModelMng_ResetCtrlerAnim(void);
signed int KnMenuModelMng_Init(void);

/* KnMenuModelMng_Init @ 0x1D60B0 .. 0x1D616C (0xbc bytes, frame 0x10) */


signed int KnMenuModelMng_Init(void) {
    s32 a1;
    u32 a0;
    u32 v1;
    s32 v0;

    a0 = pKnMenuModelMng;
    if (a0 == 0) {
        return 0;
    }
    MngState_Init((void *)a0);
    a1 = 0;
    a0 = 0;
    do {
        v1 = pKnMenuModelMng;
        a1 = a1 + 5;
        v0 = a1 < (s32)0xf;
        *(u32 *)(((u32)(v1 + a0) + 0x24)) = 0;
        v1 = pKnMenuModelMng;
        *(u32 *)(((u32)(v1 + a0) + 0x34)) = 0;
        v1 = pKnMenuModelMng;
        *(u32 *)(((u32)(v1 + a0) + 0x44)) = 0;
        v1 = pKnMenuModelMng;
        *(u32 *)(((u32)(v1 + a0) + 0x54)) = 0;
        v1 = pKnMenuModelMng;
        *(u32 *)(((u32)(v1 + a0) + 0x64)) = 0;
        a0 = a0 + 0x50;
    } while ((u32)v0 != 0);
    v1 = pKnMenuModelMng;
    if (v1 == 0) {
        if (v1 != 0) {
            *(u32 *)v1 = 0;
        }
        v0 = 0;
    } else {
        *(u32 *)v1 = 2;
        v0 = 1;
    }
    return v0;
}



static u32 pKnMenuModelMng;













struct KNMDL_MNG {
    unsigned char bUse;
    unsigned char bMultiDraw;
    unsigned char bErase;
    unsigned char bEraseByMapDraw;
    unsigned char _gap0[0x1c];
    float Pos[4];
    unsigned char _gap1[0x1c0 - 0x30];
};

struct KNMDL_DATA {
    unsigned char _gap[0x680];
};
/* KnMenuModelMng_ResetCtrlerAnim @ 0x1D5FD0 .. 0x1D60B0 (0xe0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1d600c
 *   fpu: float literal 0x00000000 at 0x1d6064
 *   return without a value in a non-void function
 */


u32 KnMenuModelMng_ResetCtrlerAnim(void) {
    u32 a1;
    u32 a0;
    u8 *s0;
    u32 v1;
    float f12;
    u32 v0;

    a0 = 1;
    v1 = GameSt[0x16];
    s0 = (u8 *)(MdlMngB + 0x54000);
    s_ctrler_state_init_on = a0;
    switch (v1) {
    case 0:
        f12 = 0.0f;
        s_ctrler_state = 2;
        ChangeAnimParam((void *)s0, 5, 0.0f);
        fsvu0_CopyVectorF((float *)(s0 + 0x20), (float *)(u8 *)(MenuModelDefPos + 0x38));
        a1 = (u32)g_ZeroVec;
        fsvu0_CopyVectorF((float *)(s0 + 0x30), (float *)g_ZeroVec);
        a1 = (u32)g_UnitMat;
        v0 = CsMngRtaSetMat((unsigned int)s0, (void *)g_UnitMat, 1);
        break;
    case 1:
        s_ctrler_state = a0;
        f12 = 0.0f;
        ChangeAnimParam((void *)s0, 5, 0.0f);
        fsvu0_CopyVectorF((float *)(s0 + 0x20), (float *)(u8 *)(MenuModelDefPos + 0x38));
        a1 = (u32)g_ZeroVec;
        fsvu0_CopyVectorF((float *)(s0 + 0x30), (float *)g_ZeroVec);
        v1 = 0x3f2ed623;
        *(u32 *)(s0 + 0x34) = 0x3f2ed623;
    }
    return;
}



/* Menu_CheckMapMove @ 0x1D5FC0 .. 0x1D5FC8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: daddu at 0x1d5fc4 computes the return value
 */




u32 Menu_CheckMapMove(void) {
    return 0;
}






/* Menu_GetMovementHelpId @ 0x1D5FB0 .. 0x1D5FB8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1d5fb4 computes the return value
 */


u32 Menu_GetMovementHelpId(void) {
    return s_MoveMentHelpId;
}


extern void Menu_GetTexCenter(s32, float *);
extern u32 Menu_GetTexId_now(void);
extern float s_mm_cam_pos[4], s_mm_cam_target_pos[4];
void Menu_SetMmCamPos(s32 position, s32 target, s32 mode)
{
    float zero, x, width, limit, delta, value;
    float half;
    float player[4] __attribute__((aligned(16)));
    float center[4] __attribute__((aligned(16)));
    if(position>=0) Menu_GetTexCenter(position,s_mm_cam_pos);
    if(target>=0) Menu_GetTexCenter(target,s_mm_cam_target_pos);
    if(mode>0) {
        fsvu0_CopyVectorF(player,(float *)(MdlMngB+0x11820));
        if(GameSt[9]>=51 && GameSt[9]<=59) {
            player[0]-=-3.0037203f;
            player[1]-=0.595437f;
            player[2]-=-43.002304f;
        }
        s_mm_cam_target_pos[0]=player[0];
        s_mm_cam_target_pos[1]=player[2];
        Menu_GetTexCenter(Menu_GetTexId_now(),center);
        half=2.0f;
        width=0.0f;
        s_mm_cam_target_pos[0]+=width;
        s_mm_cam_target_pos[1]+=width;
        center[3]*=-1.0f;
        width=center[2]; x=center[0];
        delta=s_mm_cam_target_pos[0]-x;
        if(delta<(-width/half)/half) s_mm_cam_target_pos[0]=x-(width/half)/half;
        limit=(width/2.0f)/2.0f;
        delta=s_mm_cam_target_pos[0]-x;
        if(!(delta<=limit)) s_mm_cam_target_pos[0]=x+limit;
        {
            float yWidth, y;
            yWidth=center[3]; y=center[1];
            delta=s_mm_cam_target_pos[1]-y;
            if(delta<(-yWidth/2.0f)/2.0f) s_mm_cam_target_pos[1]=y-(yWidth/2.0f)/2.0f;
            limit=(yWidth/2.0f)/2.0f;
            delta=s_mm_cam_target_pos[1]-y;
            if(!(delta<=limit)) s_mm_cam_target_pos[1]=y+limit;
        }
        if(mode>1) {
            x=s_mm_cam_target_pos[0];
            delta=s_mm_cam_target_pos[1];
            s_mm_cam_pos[0]=x;
            s_mm_cam_pos[1]=delta;
        }
    }
}















/* KnMenuModelMng_GetCtrlerState @ 0x1D5D20 .. 0x1D5D28 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lb at 0x1d5d24 computes the return value
 */


s8 KnMenuModelMng_GetCtrlerState(void) {
    return s_ctrler_state;
}




static u32 s_ctrler_state_counter;
/* KnMenuModelMng_Update @ 0x1D4E20 .. 0x1D5D18 (0xef8 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   literal: @3492 -> 0x255ab0
 *   indirect: jr v0 at 0x1d5314 -> <v0>
 *   fpu: float literal 0x00000000 at 0x1d5334
 *   delay: addiu at 0x1d5398 writes a register its branch at 0x1d5394 reads
 *   fpu: float literal 0x00000000 at 0x1d53a0
 *   fpu: float literal 0x00000000 at 0x1d5408
 *   fpu: float literal 0x00000000 at 0x1d545c
 *   fpu: float literal 0x00000000 at 0x1d547c
 *   fpu: float literal 0x00000000 at 0x1d549c
 *   delay: addiu at 0x1d54e4 writes a register its branch at 0x1d54e0 reads
 *   delay: addiu at 0x1d54f8 writes a register its branch at 0x1d54f4 reads
 *   delay: addiu at 0x1d5550 writes a register its branch at 0x1d554c reads
 *   delay: addiu at 0x1d5564 writes a register its branch at 0x1d5560 reads
 *   delay: addiu at 0x1d55d0 writes a register its branch at 0x1d55cc reads
 *   fpu: float literal 0x00000000 at 0x1d55d8
 *   fpu: float literal 0x00000000 at 0x1d5650
 *   fpu: float literal 0x00000000 at 0x1d56a4
 *   fpu: float literal 0x00000000 at 0x1d56c4
 *   fpu: float literal 0x00000000 at 0x1d56e4
 *   delay: addiu at 0x1d5734 writes a register its branch at 0x1d5730 reads
 *   delay: addiu at 0x1d5748 writes a register its branch at 0x1d5744 reads
 *   delay: addiu at 0x1d57a0 writes a register its branch at 0x1d579c reads
 *   delay: addiu at 0x1d57b4 writes a register its branch at 0x1d57b0 reads
 *   fpu: float literal 0x3d00adfd at 0x1d57e4
 *   fpu: float literal 0x3d00adfd at 0x1d5814
 *   fpu: float literal 0x3dcccccd at 0x1d5844
 *   fpu: float literal 0xbdcccccd at 0x1d5944
 *   fpu: float literal 0x3dcccccd at 0x1d5948
 *   fpu: float literal 0x00000000 at 0x1d59f0
 *   fpu: mov.s at 0x1d5a0c is a float copy
 *   fpu: mtc1 reinterprets v1 at 0x1d5a24
 *   fpu: float literal 0x00000000 at 0x1d5a28
 *   fpu: float literal 0x42700000 at 0x1d5a40
 *   fpu: float literal 0x42700000 at 0x1d5a5c
 *   fpu: float literal 0x42880000 at 0x1d5a6c
 *   fpu: float literal 0xc0400000 at 0x1d5a7c
 *   fpu: mtc1 reinterprets v1 at 0x1d5aa4
 *   fpu: float literal 0x00000000 at 0x1d5aa8
 *   fpu: float literal 0x42700000 at 0x1d5ac0
 *   fpu: float literal 0x42700000 at 0x1d5adc
 *   fpu: float literal 0x42880000 at 0x1d5aec
 *   fpu: float literal 0x40400000 at 0x1d5afc
 *   fpu: float literal 0x40400000 at 0x1d5b1c
 *   fpu: float literal 0xc0400000 at 0x1d5b34
 *   fpu: float literal 0xc0400000 at 0x1d5b4c
 *   fpu: float literal 0x40400000 at 0x1d5b68
 *   stack: address of the slot at 0x90 escapes at 0x1d5b7c
 *   fpu: float literal 0xbf800000 at 0x1d5b94
 *   fpu: float literal 0x40000000 at 0x1d5b9c
 *   stack: address of the slot at 0x9c escapes at 0x1d5c18
 *   fpu: float literal 0x40000000 at 0x1d5c1c
 *   fpu: float literal 0x40000000 at 0x1d5c5c
 *   fpu: float literal 0x40000000 at 0x1d5cac
 *   cfg: kept branch: 0x1d4f68 if (..) goto .L001D4F80
 *   cfg: kept branch: 0x1d4fd8 if (..) goto .L001D4FF0
 *   cfg: kept branch: 0x1d5280 if (..) goto .L001D5298
 *   cfg: loop body is not one contiguous region: .L001D52C8
 *   cfg: loop body is not one contiguous region: .L001D5950
 */

extern signed int MngState_UpdateExeCheck(void *);
extern signed int KnMenuMng_CheckCtrlPlay(int, signed int);
extern unsigned int CheckAnimEndFrame(void *);
extern void PlayMi3(void *);
extern u32 Menu_GetMapTexSorL();
extern u32 Menu_TD_IsPlay();

extern float s_mm_cam_pos[4];
extern float s_mm_cam_target_pos[4];
extern u32 lpPadData;
extern u32 L3492[];
static u8 old_type_1002;

struct dw_2190011_fields;
struct dw_2194051_fields;
#ifndef PROTO_DW_2210472_FIELDS
#define PROTO_DW_2210472_FIELDS
struct dw_2210472_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2206142_FIELDS
#define PROTO_DW_2206142_FIELDS
struct dw_2206142_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2205819_FIELDS
#define PROTO_DW_2205819_FIELDS
struct dw_2205819_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2194051_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2194051_FIELDS
#define PROTO_DW_2194051_FIELDS
struct dw_2194051_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2190011_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2194051_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2210472_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2206142_fields flags; unsigned char _pad1[3]; struct dw_2205819_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2208523_FIELDS
#define PROTO_DW_2208523_FIELDS
struct dw_2208523_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS_ANG_1__16156C2B_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS_ANG_1__16156C2B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS_ANG_1__16156C2B = (int)&(((struct dw_2194051_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65 = (int)&(((struct dw_2194051_fields *)0)->IndexAnim) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B = (int)&(((struct dw_2194051_fields *)0)[754].Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9 = (int)&(((struct dw_2194051_fields *)0)[754].Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873 = (int)&(((struct dw_2194051_fields *)0)[754].Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D = (int)&(((struct dw_2194051_fields *)0)[754].Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__BERASE_57CB8EC0_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__BERASE_57CB8EC0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__BERASE_57CB8EC0 = (int)&(((struct dw_2194051_fields *)0)[754].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__755__BERASE_C0016D81_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__755__BERASE_C0016D81_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__755__BERASE_C0016D81 = (int)&(((struct dw_2194051_fields *)0)[755].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__756__BERASE_3849487C_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__756__BERASE_3849487C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__756__BERASE_3849487C = (int)&(((struct dw_2194051_fields *)0)[756].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__757__BERASE_1597E72C_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__757__BERASE_1597E72C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__757__BERASE_1597E72C = (int)&(((struct dw_2194051_fields *)0)[757].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__758__BERASE_28773680_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__758__BERASE_28773680_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__758__BERASE_28773680 = (int)&(((struct dw_2194051_fields *)0)[758].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__759__BERASE_773A9B1E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__759__BERASE_773A9B1E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__759__BERASE_773A9B1E = (int)&(((struct dw_2194051_fields *)0)[759].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__760__BERASE_93B2C496_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__760__BERASE_93B2C496_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__760__BERASE_93B2C496 = (int)&(((struct dw_2194051_fields *)0)[760].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__761__BERASE_5F7D4A2A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__761__BERASE_5F7D4A2A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__761__BERASE_5F7D4A2A = (int)&(((struct dw_2194051_fields *)0)[761].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__763__BERASE_F446C099_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__763__BERASE_F446C099_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__763__BERASE_F446C099 = (int)&(((struct dw_2194051_fields *)0)[763].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__764__BERASE_8837B2A7_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__764__BERASE_8837B2A7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__764__BERASE_8837B2A7 = (int)&(((struct dw_2194051_fields *)0)[764].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__765__BERASE_B36FEFE4_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__765__BERASE_B36FEFE4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__765__BERASE_B36FEFE4 = (int)&(((struct dw_2194051_fields *)0)[765].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__766__BERASE_3C0DDC9E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__766__BERASE_3C0DDC9E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__766__BERASE_3C0DDC9E = (int)&(((struct dw_2194051_fields *)0)[766].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__767__BERASE_1C5EB46F_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__767__BERASE_1C5EB46F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__767__BERASE_1C5EB46F = (int)&(((struct dw_2194051_fields *)0)[767].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__768__BERASE_1DA59050_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__768__BERASE_1DA59050_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__768__BERASE_1DA59050 = (int)&(((struct dw_2194051_fields *)0)[768].bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BERASE_EE752118_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BERASE_EE752118_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BERASE_EE752118 = (int)&(((struct dw_2194051_fields *)0)->bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BUSE_49D03678_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BUSE_49D03678_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BUSE_49D03678 = (int)&(((struct dw_2194051_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9 = (int)&(((struct dw_2194051_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2208523_FIELDS_KEYCONFTYPE_17DC55EA_DEFINED
#define DCOMP_OFF_STRUCT_DW_2208523_FIELDS_KEYCONFTYPE_17DC55EA_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2208523_FIELDS_KEYCONFTYPE_17DC55EA = (int)&(((struct dw_2208523_fields *)0)->KeyConfType) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PADPORT_E9A24807_DEFINED
#define DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PADPORT_E9A24807_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PADPORT_E9A24807 = (int)&(((struct dw_2208523_fields *)0)->padport) - 0 };
#endif
signed int KnMenuModelMng_Update(void) {
    s32 xt4;
    u32 xt5;
    u32 a1;
    u32 xt0;
    u32 xt3;
    s32 s4;
    s32 a2;
    u8 *s3;
    float *s2;
    u8 *s1;
    s32 ps;
    u8 *s5;
    float f3;
    float rate;
    u32 v0;
    float f4;
    float f1;
    u64 v1_64;
    u8 stackFrame_90[16] __attribute__((aligned(16)));

    xt0 = pKnMenuModelMng;
    if (xt0 == 0) {
        return 0;
    }
    v0 = MngState_UpdateExeCheck((void *)xt0);
    xt4 = 1;
    if (v0 != xt4) {
        v0 = 0;
    } else {
        xt0 = 7;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        xt0 = 7;
        if (v0 == 0) {
            v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
            xt0 = 3;
            if (v0 == 0) {
                v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                xt0 = 3;
                if (v0 == 0) {
                    a1 = 2;
                    v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
                    xt0 = 3;
                    if (v0 == 0) {
                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt0);
                        xt0 = 6;
                        if (v0 == 0) {
                            v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                            xt0 = 9;
                            if (v0 == 0) {
                                v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                xt0 = 3;
                                if (v0 == 0) {
                                    a1 = 7;
                                    v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
                                    xt0 = 9;
                                    if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 5;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 4;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 0xa;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 5;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 4;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 3;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 6);
                                        if (v0 == 0) {
                                        goto _L001D4F80;
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        xt4 = 0;
        _L001D4F80:;
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__755__BERASE_C0016D81 / 1)] = xt4;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__763__BERASE_F446C099 / 1)] = xt4;
        xt0 = 3;
        a1 = 2;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
        xt0 = 7;
        if (v0 == 0) {
            v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
            xt0 = 7;
            if (v0 == 0) {
                v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                if (v0 == 0) {
                    goto _L001D4FF0;
                }
            }
        }
        xt4 = 0;
        _L001D4FF0:;
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__764__BERASE_8837B2A7 / 1)] = xt4;
        xt4 = 1;
        xt0 = 3;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__765__BERASE_B36FEFE4 / 1)] = xt4;
        xt0 = 9;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__766__BERASE_3C0DDC9E / 1)] = xt4;
        xt0 = 9;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__767__BERASE_1C5EB46F / 1)] = xt4;
        xt0 = 9;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__768__BERASE_1DA59050 / 1)] = xt4;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__756__BERASE_3849487C / 1)] = (u32)xt4;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__757__BERASE_1597E72C / 1)] = xt4;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__758__BERASE_28773680 / 1)] = xt4;
        xt4 = 1;
        xt0 = 3;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        xt0 = 3;
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__759__BERASE_773A9B1E / 1)] = xt4;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__760__BERASE_93B2C496 / 1)] = xt4;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
        if (v0 != 0) {
            xt4 = 0;
        }
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__761__BERASE_5F7D4A2A / 1)] = xt4;
        xt0 = 3;
        xt0 = 3;
        xt4 = 1;
        v0 = KnMenuMng_CheckCtrlPlay((u8)xt0, 0);
        if (v0 == 0) {
            v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
            xt0 = 3;
            if (v0 == 0) {
                a1 = 2;
                v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
                xt0 = 3;
                if (v0 == 0) {
                    v0 = KnMenuMng_CheckCtrlPlay(xt0, xt0);
                    xt0 = 6;
                    if (v0 == 0) {
                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                        xt0 = 9;
                        if (v0 == 0) {
                            v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                            xt0 = 3;
                            if (v0 == 0) {
                                a1 = 7;
                                v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
                                xt0 = 9;
                                if (v0 == 0) {
                                    v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                    xt0 = 5;
                                    if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 4;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 0xa;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        xt0 = 5;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 4;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 3;
                                        if (v0 == 0) {
                                        a1 = 6;
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, a1);
                                        xt0 = 7;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, xt4);
                                        xt0 = 7;
                                        if (v0 == 0) {
                                        v0 = KnMenuMng_CheckCtrlPlay(xt0, 0);
                                        if (v0 == 0) {
                                        goto _L001D5298;
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        xt4 = 0;
        _L001D5298:;
        MdlMngB[(DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__BERASE_57CB8EC0 / 1)] = xt4;
        s2 = (float *)MenuModelDefPos;
        s4 = 0;
        xt5 = 0;
        s1 = MdlMngB;
        ps = (u32)MenuModelPosState;
        s5 = (u8 *)MenuModelDefPos;
        do {
            v0 = 0x50000;
            xt3 = 0x50000 | 0x2780;
            xt3 = xt5 + ((u32)xt3);
            v0 = (u32)MdlMngB;
            s3 = (u8 *)((u8 *)MdlMngB + xt3);
            v0 = *(u8 *)(DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BUSE_49D03678 + s3);
            if (v0 != 0) {
                xt3 = *(u8 *)(DCOMP_OFF_STRUCT_DW_2194051_FIELDS_BERASE_EE752118 + s3);
                v0 = 1;
                xt0 = 0xf;
                xt4 = s4 < xt0;
                if (xt3 != v0) {
                    switch (s4) {
                    case 1:
                        xt0 = *(s32 *)(DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9 + s3);
                        v0 = CheckAnimEndFrame((void *)xt0);
                        if (v0 == 0) {
                            break;
                        }
                        a1 = *(s16 *)(DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65 + s3);
                        ChangeAnimParam((void *)s3, a1, 0.0f);
                        break;
                    case 14:
                        xt3 = GameSt[(DCOMP_OFF_STRUCT_DW_2208523_FIELDS_KEYCONFTYPE_17DC55EA / 1)];
                        v0 = old_type_1002;
                        if (xt3 != v0) {
                            old_type_1002 = xt3;
                            KnMenuModelMng_ResetCtrlerAnim();
                        }
                        v0 = GameSt[(DCOMP_OFF_STRUCT_DW_2208523_FIELDS_KEYCONFTYPE_17DC55EA / 1)];
                        xt3 = 1;
                        switch (v0) {
                        case 0:
                            v0 = s_ctrler_state_init_on;
                            if (v0 == xt3) {
                                v0 = 2;
                                xt0 = ((s32)s3);
                                s_ctrler_state_counter = v0;
                                s_ctrler_state = v0;
                                a1 = 5;
                                s_ctrler_state_init_on = 0;
                                ChangeAnimParam((void *)xt0, a1, 0.0f);
                                fsvu0_CopyVectorF((float *)(s3 + 0x20), s2);
                                a1 = (u32)g_ZeroVec;
                                fsvu0_CopyVectorF((float *)(s3 + 0x30), (float *)g_ZeroVec);
                                a2 = 1;
                                a1 = (u32)g_UnitMat;
                                CsMngRtaSetMat((s32)(s32)s3, (void *)g_UnitMat, (u32)a2);
                            }
                            xt0 = *(s32 *)(s3 +
                                DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9);
                            v0 = CheckAnimEndFrame((void *)xt0);
                            if (v0 != 0) {
                                v0 = s_ctrler_state_counter;
                                if (v0 != 0) {
                                    a1 = *(s16 *)(s3 +
                                        DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65);
                                    ChangeAnimParam((void *)s3, a1, 0.0f);
                                    v0 = s_ctrler_state_counter;
                                    v0 = v0 + -1;
                                    s_ctrler_state_counter = v0;
                                } else {
                                    xt0 = s_ctrler_state;
                                    v0 = 4;
                                    xt3 = 3;
                                    if (xt0 != v0) {
                                        if (xt0 != xt3) {
                                        v0 = 2;
                                        switch (xt0) {
                                        case 2:
                                        s_ctrler_state = xt3;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                        break;
                                        }
                                        } else {
                                        s_ctrler_state = v0;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                        }
                                    } else {
                                        s_ctrler_state = 2;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                    }
                                    fsvu0_CopyVectorF((float *)(0x20 + s3), s2);
                                    v0 = 2;
                                    fsvu0_CopyVectorF((float *)(s3 + 0x30), (float *)g_ZeroVec);
                                    a1 = (u32)g_ZeroVec;
                                    s_ctrler_state_counter = v0;
                                }
                            }
                            v0 = 4;
                            xt3 = s_ctrler_state;
                            switch (xt3) {
                            case 0:
                            case 1:
                                break;
                            case 2:
                                s_MoveMentHelpId = 0x18820;
                                v0 = 0x18820;
                                break;
                            case 3:
                                s_MoveMentHelpId = 0x18821;
                                v0 = 0x18821;
                                break;
                            case 4:
                                s_MoveMentHelpId = 0x18822;
                                v0 = 0x18822;
                            }
                            v0 = 4;
                            switch (xt3) {
                            case 0:
                                break;
                            case 1:
                                xt4 = 0x50000;
                                v0 = 0x40490fdb;
                                *(u32 *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) =
                                    0x40490fdb;
                                break;
                            case 2:
                                break;
                            case 3:
                                xt4 = 0x50000;
                                v0 = 0x3fc90fdb;
                                *(u32 *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) =
                                    0x3fc90fdb;
                                break;
                            case 4:
                                xt4 = 0x50000;
                                v0 = -0x4036f025;
                                *(u32 *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) =
                                    -0x4036f025;
                                break;
                            }
                            break;
                        case 1:
                            v0 = s_ctrler_state_init_on;
                            if (v0 == xt3) {
                                v0 = 2;
                                s_ctrler_state_counter = v0;
                                xt0 = (s32)s3;
                                s_ctrler_state = xt3;
                                a1 = 5;
                                s_ctrler_state_init_on = 0;
                                ChangeAnimParam((void *)xt0, a1, 0.0f);
                                fsvu0_CopyVectorF((float *)(s3 + 0x20), s2);
                                fsvu0_CopyVectorF((float *)(s3 + 0x30), (float *)g_ZeroVec);
                                v0 = 0x3f2ed623;
                                a1 = (u32)g_ZeroVec;
                                xt0 = (s32)s3;
                                a1 = (u32)g_UnitMat;
                                *(u32 *)(s3 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS_ANG_1__16156C2B) =
                                    0x3f2ed623;
                                a2 = 1;
                                CsMngRtaSetMat(xt0, (void *)g_UnitMat, a2);
                            }
                            xt0 = *(s32 *)(s3 +
                                DCOMP_OFF_STRUCT_DW_2194051_FIELDS_LPANIMCTRL_4FF1C5A9);
                            v0 = CheckAnimEndFrame((void *)xt0);
                            if (v0 != 0) {
                                v0 = s_ctrler_state_counter;
                                if (v0 != 0) {
                                    a1 = *(s16 *)(s3 +
                                        DCOMP_OFF_STRUCT_DW_2194051_FIELDS_INDEXANIM_4EB89A65);
                                    ChangeAnimParam((void *)s3, a1, 0.0f);
                                    v0 = s_ctrler_state_counter;
                                    v0 = v0 + -1;
                                    s_ctrler_state_counter = v0;
                                } else {
                                    v0 = 4;
                                    xt3 = 3;
                                    xt0 = s_ctrler_state;
                                    if (xt0 != v0) {
                                        if (xt0 != xt3) {
                                        v0 = 1;
                                        switch (xt0) {
                                        case 1:
                                        s_ctrler_state = xt3;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                        break;
                                        }
                                        } else {
                                        s_ctrler_state = v0;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                        }
                                    } else {
                                        s_ctrler_state = 1;
                                        ChangeAnimParam((void *)s3, 5, 0.0f);
                                    }
                                    fsvu0_CopyVectorF((float *)(s3 + 0x20), s2);
                                    a1 = ((u32)g_ZeroVec);
                                    fsvu0_CopyVectorF((float *)(0x30 + s3), (float *)g_ZeroVec);
                                    v0 = 2;
                                    xt3 = 0x3f2ed623;
                                    *(u32 *)(s3 +
                                        DCOMP_OFF_STRUCT_DW_2194051_FIELDS_ANG_1__16156C2B) =
                                        0x3f2ed623;
                                    s_ctrler_state_counter = v0;
                                }
                            }
                            xt3 = s_ctrler_state;
                            v0 = 4;
                            switch (xt3) {
                            case 0:
                                break;
                            case 1:
                                v0 = 0x18823;
                                s_MoveMentHelpId = 0x18823;
                                break;
                            case 2:
                                break;
                            case 3:
                                s_MoveMentHelpId = 0x18824;
                                v0 = 0x18824;
                                break;
                            case 4:
                                v0 = 0x18825;
                                s_MoveMentHelpId = 0x18825;
                            }
                            v0 = 4;
                            switch (xt3) {
                            case 0:
                            case 1:
                            case 2:
                                break;
                            case 3:
                                xt4 = 0x50000;
                                *(f32 *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) =
                                    (*(float *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) -
                                    0.03141593f);
                                break;
                            case 4:
                                xt4 = 0x50000;
                                *(f32 *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) =
                                    (*(float *)(s1 +
                                    DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__ANG_1__25722D8B) + (0.03141593f));
                            }
                        }
                    case 0:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                    case 12:
                    case 13:
                    default:
                        break;
                    }
                    a1 = *(s32 *)ps;
                    xt3 = ((u32)MenuModelTargetPosOffset);
                    xt0 = (s32)s3;
                    v0 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a1];
                    f3 = *(float *)v0;
                    *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9) = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9) + 0.1f * ((*(float *)s5 + f3) - *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_0__42EE3FF9));
                    v0 = *(s32 *)ps;
                    v0 = v0 << 4;
                    v0 = (s32)((u8 *)MenuModelTargetPosOffset + v0);
                    xt4 = (4 + v0);
                    f3 = *(float *)((xt4));
                    *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873) = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873) + 0.1f * ((*(float *)(s5 + 4) + f3) - *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_1__8F8FC873));
                    a1 = *(s32 *)ps;
                    v0 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a1];
                    f3 = *(float *)(v0 + 8);
                    *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D) = *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D) + 0.1f * ((*(float *)(8 + s5) + f3) - *(float *)(s1 + DCOMP_OFF_STRUCT_DW_2194051_FIELDS__754__POS_2__0B9AD59D));
                    PlayMi3((void *)xt0);
                    xt4 = (s32)(s1 + 0x50000);
                }
            }
            s4 = s4 + 1;
            v0 = s4 < 0xf;
            xt5 = xt5 + 0x1c0;
            s2 = (float *)(u8 *)(4 + s2);
            s1 = (u8 *)(0x1c0 + s1);
            ps = ps + 4;
            s5 = (u8 *)(s5 + 0x10);
        } while (v0 != 0);
        for (a2 = 0; a2 < 2; a2++) {
            ((float *)s_mm_cam_pos)[a2] = 0.1f * (((float *)s_mm_cam_target_pos)[a2] - ((float *)s_mm_cam_pos)[a2]) + ((float *)s_mm_cam_pos)[a2];
            f3 = ((float *)s_mm_cam_target_pos)[a2] - ((float *)s_mm_cam_pos)[a2];
            if (f3 >= 0.1f) {
                ((float *)s_mm_cam_pos)[a2] = ((float *)s_mm_cam_pos)[a2] + 0.1f;
            } else if (f3 <= -0.1f) {
                ((float *)s_mm_cam_pos)[a2] = ((float *)s_mm_cam_pos)[a2] - 0.1f;
            } else {
                ((float *)s_mm_cam_pos)[a2] = ((float *)s_mm_cam_target_pos)[a2];
            }
        }
        if ((u8)Menu_GetMapTexSorL() == 0) {
            if (Menu_TD_IsPlay() == 0) {
                float h, v, x;
                unsigned char *lpPad;
                float center[4] __attribute__((aligned(16)));
                float width, limit, delta;
                lpPad = (unsigned char *)((u32 *)&lpPadData)[GameSt[10]];
                h = 0.0f;
                v = h;
                if (lpPad[7] < 0x44 || lpPad[7] > 0xbc) {
                    float t = (float)(lpPad[7] - 0x80);
                    if (t < 0.0f) {
                        t = t + 60.0f;
                    } else if (!(t <= 0.0f)) {
                        t = t - 60.0f;
                    }
                    t = t / 68.0f;
                    v = -3.0f * t;
                }
                if (lpPad[6] < 0x44 || lpPad[6] > 0xbc) {
                    float t = (float)(lpPad[6] - 0x80);
                    if (t < 0.0f) {
                        t = t + 60.0f;
                    } else if (!(t <= 0.0f)) {
                        t = t - 60.0f;
                    }
                    t = t / 68.0f;
                    h = 3.0f * t;
                }
                if (((struct { unsigned char _p : 4; unsigned char f : 1; } *)(lpPad + 2))->f != 0) {
                    v = 3.0f;
                }
                if (((struct { unsigned char _p : 6; unsigned char f : 1; } *)(lpPad + 2))->f != 0) {
                    v = -3.0f;
                }
                if (((struct { unsigned char _p : 7; unsigned char f : 1; } *)(2 + lpPad))->f != 0) {
                    h = -3.0f;
                }
                if (((struct { unsigned char _p : 5; unsigned char f : 1; } *)(lpPad + 2))->f != 0) {
                    h = 3.0f;
                }
                Menu_GetTexCenter(Menu_GetTexId_now(), center);
                s_mm_cam_target_pos[0] += h;
                s_mm_cam_target_pos[1] += v;
                center[3] *= -1.0f;
                width = center[2];
                x = center[0];
                delta = s_mm_cam_target_pos[0] - x;
                if (delta < (-width / (2.0f)) / (2.0f)) {
                    s_mm_cam_target_pos[0] = x - (width / (2.0f)) / (2.0f);
                }
                limit = (width / 2.0f) / 2.0f;
                delta = s_mm_cam_target_pos[0] - x;
                if (!(delta <= limit)) {
                    s_mm_cam_target_pos[0] = x + limit;
                }
                {
                    float yWidth, y;
                    yWidth = center[3];
                    y = center[1];
                    delta = s_mm_cam_target_pos[1] - y;
                    if (delta < (-yWidth / 2.0f) / 2.0f) {
                        s_mm_cam_target_pos[1] = y - (yWidth / 2.0f) / 2.0f;
                    }
                    limit = (yWidth / 2.0f) / 2.0f;
                    delta = s_mm_cam_target_pos[1] - y;
                    if (!(delta <= limit)) {
                        s_mm_cam_target_pos[1] = y + limit;
                    }
                }
            }
        }
        v0 = 1;
    }
    return v0;
}


static u32 MenuModelPosState[0xf] = {
    0, 3, 9, 8, 7, 6, 5, 4
};
static u32 MenuModelTargetPosOffset[0x28] = {
    0, 0, 0, 0, 0, 0x40c00000, 0x40400000, 0, 0, 0, 0, 0, 0, 0x80000000, 0x80000000, 0, 0, 0,
    0xc4000000, 0, 0, 0, 0xc2000000, 0, 0, 0, 0xc3000000, 0, 0, 0xc1200000, 0xc1800000, 0, 0, 0,
    0xc2800000, 0, 0, 0, 0xc3800000
};
extern u8 s_KnMenuModelMng[];
static u32 pKnMenuModelMng = (u32)&s_KnMenuModelMng;
static u32 s_ctrler_state_counter = 2;
static u8 s_ctrler_state = 1;
static u32 s_ctrler_state_init_on = 1;
static u32 s_MoveMentHelpId = 0x18820;
static u32 MenuModelDefPos[0x3c] = {0};
float s_mm_cam_pos[0x4] = {0};
float s_mm_cam_target_pos[0x4] = {0};
void *s_pClothMdlTexList = 0;
void *s_GetItemBG = 0;
static u8 old_type_1002 = 0; /* Initialized here to preserve old_type$1002 at .sbss+0x8. */

/* KnMenuModelMng_Draw @ 0x1D42B0 .. 0x1D4E1C (0xb6c bytes, frame 0x240) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   quad: s1: 128-bit web split from its scalar uses
 *   quad: t0: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1127 -> 0x2489a0
 *   literal: @1129 -> 0x2489b0
 *   literal: @1132 -> 0x2489c0
 *   literal: @1233 -> 0x2489f0
 *   literal: @1231 -> 0x2489e0
 *   literal: @1235 -> 0x248a00
 *   literal: @3074 is the string 'art_txt000.tm2'
 *   literal: @3075 is the string 'art_txt001.tm2'
 *   literal: @1316 -> 0x248a10
 *   literal: @1322 -> 0x248a20
 *   literal: @1326 -> 0x248a30
 *   delay: daddu at 0x1d439c writes a register its branch at 0x1d4398 reads
 *   stack: address of the slot at 0x230 escapes at 0x1d43a8
 *   stack: address of the slot at 0x220 escapes at 0x1d43a8
 *   stack: address of the slot at 0x210 escapes at 0x1d43a8
 *   stack: address of the slot at 0x220 escapes at 0x1d43b0
 *   fpu: float literal 0x3edf66f4 at 0x1d43c0
 *   fpu: float literal 0x3c23d70a at 0x1d43ec
 *   fpu: mtc1 reinterprets v0 at 0x1d43f4
 *   fpu: float literal 0x3f19999a at 0x1d4428
 *   fpu: float literal 0x40490fdb at 0x1d4440
 *   stack: address of the slot at 0x210 escapes at 0x1d4468
 *   fpu: mov.s at 0x1d447c is a float copy
 *   fpu: float literal 0x3e4ccccd at 0x1d44a4
 *   fpu: float literal 0x40400000 at 0x1d453c
 *   fpu: float literal 0x40400000 at 0x1d45bc
 *   fpu: float literal 0x40400000 at 0x1d463c
 *   fpu: float literal 0x40400000 at 0x1d46bc
 *   fpu: float literal 0x40400000 at 0x1d4738
 *   fpu: float literal 0x40400000 at 0x1d47bc
 *   stack: address of the slot at 0x108 escapes at 0x1d4818
 *   stack: address of the slot at 0x1d2 escapes at 0x1d4818
 *   fpu: float literal 0x00000000 at 0x1d497c
 *   stack: address of the slot at 0x200 escapes at 0x1d498c
 *   stack: address of the slot at 0x1f0 escapes at 0x1d498c
 *   stack: address of the slot at 0x1e0 escapes at 0x1d498c
 *   delay: lui at 0x1d49bc writes a register its branch at 0x1d49b8 reads
 *   delay: lui at 0x1d4c98 writes a register its branch at 0x1d4c94 reads
 *   stack: address of the slot at 0xf0 escapes at 0x1d4cc8
 *   stack: address of the slot at 0xe0 escapes at 0x1d4cc8
 *   delay: lui at 0x1d4d28 writes a register its branch at 0x1d4d24 reads
 *   stack: address of the slot at 0xd0 escapes at 0x1d4d3c
 *   delay: lui at 0x1d4d4c writes a register its branch at 0x1d4d48 reads
 *   stack: address of the slot at 0xc0 escapes at 0x1d4d60
 *   stack: address of the slot at 0xb0 escapes at 0x1d4d6c
 *   stack: address of the slot at 0xd0 escapes at 0x1d4d80
 *   delay: slti at 0x1d4d90 writes a register its branch at 0x1d4d8c reads
 *   stack: address of the slot at 0x210 escapes at 0x1d4dac
 *   literal: @1326 initializes the 16-byte local at 0xb0
 *   literal: @1322 initializes the 16-byte local at 0xc0
 *   literal: @1316 initializes the 16-byte local at 0xe0
 *   literal: @1235 initializes the 16-byte local at 0x1e0
 *   literal: @1233 initializes the 16-byte local at 0x1f0
 *   literal: @1231 initializes the 16-byte local at 0x200
 *   literal: @1132 initializes the 16-byte local at 0x210
 *   literal: @1129 initializes the 16-byte local at 0x220
 *   literal: @1127 initializes the 16-byte local at 0x230
 *   quad: a0: 128-bit web split from its scalar variable as a0_q2
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 *   cfg: kept goto: 0x1d4310 -> .L001D4DE8
 *   cfg: loop body is not one contiguous region: .L001D44C8
 *   cfg: kept branch: 0x1d44c8 if (..) goto .L001D4500
 *   cfg: loop body is not one contiguous region: .L001D4568
 *   cfg: loop body is not one contiguous region: .L001D45E8
 *   cfg: loop body is not one contiguous region: .L001D4668
 *   cfg: loop body is not one contiguous region: .L001D46E8
 *   cfg: loop body is not one contiguous region: .L001D4768
 *   cfg: loop body is not one contiguous region: .L001D4818
 */

extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void SetCameraFov(float);
extern void DrawCalcView();
extern int rand();
extern double pow(double, double);
extern void SetPointLightOn(signed int, float *, float);
extern signed int UpdatePointLightRadius(signed int, float);

extern void * KnMenuMng_GetDrawPos(int, signed int, signed int);
extern void SetPointLightOff(signed int);
extern signed int UpdatePointLightPos(signed int, float *);
extern signed int Menu_GetGetItemId(void);
extern signed int Menu_GetNowDocId(void);
extern void * GetTexMngByName(void *, char *);
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_DrawSprite_Scr(float *, void *, float, void *, void *);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern void ClearZBuffer();
extern float KnMenuMng_GetCtrlCalA(int, signed int);
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern unsigned int * MakeSpritePacketUseSpr(void *, unsigned int *);
extern void GetAmbientColor(void *);
extern void SetAmbientColor(float *);
extern signed int UpdatePointLightColor(signed int, float *);
extern void DrawModel(void *);
extern void KnMenuMedelDrawMap();
extern void DrawSetViewRange();
extern u32 L1127[];
extern u32 L1129[];
extern u32 L1132[];
extern u32 lpDrawMng;
extern u32 L1233[];
extern u32 L1231[];
extern u32 L1235[];

extern u32 lpMdlPacketMem;
extern u32 L1316[];
extern u32 L1322[];
extern u32 L1326[];



#ifndef PROTO_DW_2210472_FIELDS
#define PROTO_DW_2210472_FIELDS

#endif
#ifndef PROTO_DW_2206142_FIELDS
#define PROTO_DW_2206142_FIELDS

#endif
#ifndef PROTO_DW_2205819_FIELDS
#define PROTO_DW_2205819_FIELDS

#endif
#ifndef PROTO_DW_2194051_FIELDS
#define PROTO_DW_2194051_FIELDS

#endif
#ifndef PROTO_DW_2203125_FIELDS
#define PROTO_DW_2203125_FIELDS
struct dw_2203125_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_2205587_FIELDS
#define PROTO_DW_2205587_FIELDS
struct dw_2205587_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_2203528_FIELDS
#define PROTO_DW_2203528_FIELDS
struct dw_2203528_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_2206957_FIELDS
#define PROTO_DW_2206957_FIELDS
struct dw_2206957_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_2206273_FIELDS
#define PROTO_DW_2206273_FIELDS
struct dw_2206273_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_2198899_FIELDS
#define PROTO_DW_2198899_FIELDS
struct dw_2198899_fields { struct dw_2203125_fields pmode; struct dw_2205587_fields smode2; struct dw_2203528_fields dispfb; struct dw_2206957_fields display; struct dw_2206273_fields bgcolor; };
#endif
#ifndef PROTO_DW_2200326_FIELDS
#define PROTO_DW_2200326_FIELDS
struct dw_2200326_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_2204536_FIELDS
#define PROTO_DW_2204536_FIELDS
struct dw_2204536_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_2213334_FIELDS
#define PROTO_DW_2213334_FIELDS
struct dw_2213334_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_2210158_FIELDS
#define PROTO_DW_2210158_FIELDS
struct dw_2210158_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_2203893_FIELDS
#define PROTO_DW_2203893_FIELDS
struct dw_2203893_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_2199226_FIELDS
#define PROTO_DW_2199226_FIELDS
struct dw_2199226_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2212253_FIELDS
#define PROTO_DW_2212253_FIELDS
struct dw_2212253_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2202970_FIELDS
#define PROTO_DW_2202970_FIELDS
struct dw_2202970_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_2206538_FIELDS
#define PROTO_DW_2206538_FIELDS
struct dw_2206538_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_2199637_FIELDS
#define PROTO_DW_2199637_FIELDS
struct dw_2199637_fields { struct dw_2204536_fields frame1; unsigned long frame1addr; struct dw_2213334_fields zbuf1; long zbuf1addr; struct dw_2210158_fields xyoffset1; long xyoffset1addr; struct dw_2203893_fields scissor1; long scissor1addr; struct dw_2199226_fields prmodecont; long prmodecontaddr; struct dw_2212253_fields colclamp; long colclampaddr; struct dw_2202970_fields dthe; long dtheaddr; struct dw_2206538_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_2193311_FIELDS
#define PROTO_DW_2193311_FIELDS
struct dw_2193311_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_2202748_FIELDS
#define PROTO_DW_2202748_FIELDS
struct dw_2202748_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_2210910_FIELDS
#define PROTO_DW_2210910_FIELDS
struct dw_2210910_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_2208013_FIELDS
#define PROTO_DW_2208013_FIELDS
struct dw_2208013_fields { struct dw_2206538_fields testa; long testaaddr; struct dw_2193311_fields prim; long primaddr; struct dw_2202748_fields rgbaq; long rgbaqaddr; struct dw_2210910_fields xyz2a; long xyz2aaddr; struct dw_2210910_fields xyz2b; long xyz2baddr; struct dw_2206538_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_2212509_FIELDS
#define PROTO_DW_2212509_FIELDS
struct dw_2212509_fields { struct dw_2198899_fields disp[2]; struct dw_2200326_fields giftag0; struct dw_2199637_fields draw0; struct dw_2208013_fields clear0; struct dw_2200326_fields giftag1; struct dw_2199637_fields draw1; struct dw_2208013_fields clear1; };
#endif
#ifndef PROTO_DW_2201409_FIELDS
#define PROTO_DW_2201409_FIELDS
struct dw_2201409_fields { struct dw_2212509_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_2208523_FIELDS
#define PROTO_DW_2208523_FIELDS

#endif

typedef struct {
    unsigned short bUse : 1;
    unsigned short Fst : 1;
    unsigned short Alpha : 2;
    unsigned short LoadOff : 1;
    unsigned short unused : 11;
    unsigned short texID;
    unsigned char pad0[12];
    int ver[4][4];
    int col[4][4];
    union { int uv[4][4]; float st[4][4]; };
    unsigned char tex0[8];
    unsigned char tex1[8];
    unsigned char test[8];
    unsigned char pad1[8];
} KnSPD;
struct KnTexMng { unsigned char bUse; unsigned char unused0; unsigned short id; void *lpTm2; void *lpTexList; int unused1[1]; unsigned char texName[32]; unsigned char texNameBase[32]; int texW; int texH; int texTBW; int texPSM; };

#define KN_FIND(M, N, LIM) \
    if (on_ok == 0) { \
        for (ctrl = 0; ctrl <= N - 1; ctrl++) { \
            if (KnMenuMng_CheckCtrlPlay(M, ctrl) != 0) { \
                break; \
            } \
        } \
        if (ctrl < LIM) { \
            item = KnMenuMng_GetCursorId(M, ctrl); \
            pDrawPos = KnMenuMng_GetDrawPos(M, ctrl, item); \
            pl_pos[0] = 3.0f * (*pDrawPos)[0]; \
            pl_pos[1] = 3.0f * (*pDrawPos)[1]; \
            on_ok = 1; \
        } \
    }
#define KN_ALPHA \
            if (KnMenuMng_CheckCtrlPlay(3, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(3, 1) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 1); \
            } else if (KnMenuMng_CheckCtrlPlay(3, 2) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 2); \
            } else if (KnMenuMng_CheckCtrlPlay(3, 3) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 3); \
            } else if (KnMenuMng_CheckCtrlPlay(3, 7) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 7); \
            } else if (KnMenuMng_CheckCtrlPlay(3, 6) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(3, 6); \
            } else if (KnMenuMng_CheckCtrlPlay(7, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(7, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(7, 1) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(7, 1); \
            } else if (KnMenuMng_CheckCtrlPlay(4, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(4, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(10, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(10, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(4, 1) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(4, 1); \
            } else if (KnMenuMng_CheckCtrlPlay(5, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(5, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(5, 1) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(5, 1); \
            } else if (KnMenuMng_CheckCtrlPlay(6, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(6, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(9, 0) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(9, 0); \
            } else if (KnMenuMng_CheckCtrlPlay(9, 1) != 0) { \
                pMdlMng->Alpha = KnMenuMng_GetCtrlCalA(9, 1); \
            }

#pragma enumsalwaysint off
enum _KUON_MENU__TYPE_EN { KUON_MENU__TEST_MENU = 0, KUON_MENU__TITLE_MENU = 1, KUON_MENU__START_MENU = 2, KUON_MENU__MAIN_MENU = 3, KUON_MENU__SAVE_MENU = 4, KUON_MENU__LOAD_MENU = 5, KUON_MENU__MAP_MENU = 6, KUON_MENU__ITEM_MENU = 7, KUON_MENU__MSG_MENU = 8, KUON_MENU__SET_MENU = 9, KUON_MENU__END_SAVE_MENU = 10, KUON_MENU__DEAD_MENU = 11, KUON_MENU__MENU_NUM = 12, KUON_MENU__MAKE_NONE = 100, KUON_MENU__MAKE_TITLE = 101, KUON_MENU__MAKE_GAME = 102, KUON_MENU__DMY_MENU = 999 };
#pragma enumsalwaysint reset
signed int KnMenuModelMng_Draw(void) {
    int i;
    struct dw_2194051_fields *pMdlMng;
    static float posx;
    static float posy;
    static float posz = -0.0f;
    static float angx;
    static float angy;
    static float angz;
    static float pl_size = 3.0f;
    static float pl_a;
    static float pl_pos_c[4];
    static int depth = 0x99cf0;
    int ctrl;
    int item;
    float (*pDrawPos)[4];
    enum _KUON_MENU__TYPE_EN menu;
    int on_ok;

    if (pKnMenuModelMng == 0) {
        return 0;
    }
    if (MngState_DrawExeCheck((void *)pKnMenuModelMng) != 1) {
        return 1;
    }
    {
    float camPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    camPos[0] = posx;
    camPos[1] = posy;
    camPos[2] = posz;
    {
    float camAng[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float store_fov;
    camAng[0] = angx;
    camAng[1] = angy;
    camAng[2] = angz;
    store_fov = *(float *)(lpDrawMng + 0x41c);
    {
    float pl_col[4] = {0.5f, 0.35f, 0.1f, 1.0f};
    static float pl_pos[4] = {-1.0f, 0.300000012f, 14.25f, 1.0f};
    if (GameSt[5] != 2) {
        return 1;
    }
    SetCameraPos(camPos);
    SetCameraAng(camAng);
    SetCameraFov(0.43633235f);
    DrawCalcView();
    pl_a = pl_a + 0.6f * (float)pow(0.01f * (float)(rand() % 100), 4.0);
    if (pl_a > 3.1415927f) {
        pl_a = pl_a - 3.1415927f;
    }
    SetPointLightOn(0, pl_col, pl_size);
    UpdatePointLightRadius(0, pl_size + 0.2f * (float)pow(sinf(pl_a), 2.0));
    on_ok = 0;
    for (ctrl = 0, menu = KUON_MENU__MAIN_MENU; ctrl <= 13; ctrl++) {
        if (menu == 3 && (unsigned int)ctrl > 3 && (unsigned int)(ctrl - 6) > 1) {
            continue;
        }
        if (KnMenuMng_CheckCtrlPlay(3, ctrl) != 0) {
            break;
        }
    }
    if (ctrl < 13) {
        item = KnMenuMng_GetCursorId(3, ctrl);
        pDrawPos = KnMenuMng_GetDrawPos(3, ctrl, item);
        pl_pos[0] = 3.0f * (*pDrawPos)[0];
        pl_pos[1] = 3.0f * (*pDrawPos)[1];
        on_ok = 1;
    }
    KN_FIND(9, 3, 2)
    KN_FIND(5, 3, 2)
    KN_FIND(4, 3, 2)
    KN_FIND(0xa, 2, 1)
    KN_FIND(7, 3, 2)
    if (on_ok == 0) {
        SetPointLightOff(0);
    }
    UpdatePointLightPos(0, pl_pos);
    for (i = 0; i < 15; i++) {
        pMdlMng = &((struct dw_2194051_fields *)MdlMng)[754 + i];
        {
        struct KnTexMng *pTexMng_BookBG = 0;
        float bg_pos[4] = {256.0f, 224.0f, 0.0f, 0.0f};
        float bg_size[4] = {512.0f, 448.0f, 1.0f, 1.0f};
        float bg_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        int get_item_id;
        int now_doc_id;
        get_item_id = Menu_GetGetItemId();
        now_doc_id = Menu_GetNowDocId();
        if (KnMenuMng_CheckCtrlPlay(7, 1) != 0) {
            if (get_item_id % 10000 == 0x2d) {
                pTexMng_BookBG = GetTexMngByName(s_GetItemBG, "art_txt000.tm2");
            } else if (get_item_id % 10000 == 0x2e) {
                pTexMng_BookBG = GetTexMngByName(s_GetItemBG, "art_txt001.tm2");
            }
        }
        if (KnMenuMng_CheckCtrlPlay(3, 7) != 0) {
            if (now_doc_id % 10000 == 0x2d) {
                pTexMng_BookBG = GetTexMngByName(s_GetItemBG, "art_txt000.tm2");
            } else if (now_doc_id % 10000 == 0x2e) {
                pTexMng_BookBG = GetTexMngByName(s_GetItemBG, "art_txt001.tm2");
            }
        }
        if (pTexMng_BookBG != 0) {
            u_long128 sb;
            sb = SfxDraw_GetRenderStateBlock();
            SfxDraw_SetBlendType(0);
            SfxDraw_EnableZTest(0);
            SfxDraw_SetTexture(pTexMng_BookBG);
            SfxDraw_DrawSprite_Scr(bg_pos, bg_size, 0.0f, bg_color, 0);
            SfxDraw_SetRenderStateBlock(sb);
            ClearZBuffer();
        }
        if (pMdlMng->bUse != 0 && pMdlMng->bErase == 0) {
            pMdlMng->Alpha = 1.0f;
            KN_ALPHA
            if (i > 0 && i < 8) {
                fsvu0_CopyVectorF(pl_pos_c, pl_pos);
                pl_pos_c[2] = 21.0f;
                UpdatePointLightPos(0, pl_pos_c);
            } else {
                UpdatePointLightPos(0, pl_pos);
            }
            if (i == 14) {
                unsigned int *lpPacket = (unsigned int *)lpMdlPacketMem;
                KnSPD Sprite;
                int col[4] = {0, 0, 0, 0x40};
                SetSprite(&Sprite, -180, -97, 155, 192, col, 0, 0);
                Sprite.ver[0][2] = depth;
                Sprite.ver[1][2] = depth;
                Sprite.ver[2][2] = depth;
                Sprite.ver[3][2] = depth;
                ((struct { unsigned char _p : 1; unsigned char f : 2; } *)&Sprite.test[2])->f = 2;
                lpMdlPacketMem = (u32)MakeSpritePacketUseSpr(&Sprite, lpPacket);
            }
            if (pMdlMng->lpMdlData != 0) {
                float anb[4];
                float player_anb[4] = {0.4f, 0.4f, 0.4f, 1.0f};
                GetAmbientColor(anb);
                if (i == 14) {
                    float player_pl_col[4] = {2.0f, 1.8f, 1.5f, 1.0f};
                    SetAmbientColor(player_anb);
                    UpdatePointLightColor(0, player_pl_col);
                }
                DrawModel(pMdlMng);
                SetAmbientColor(anb);
                if (i < 8) {
                    if (i < 8) {
                        ClearZBuffer();
                    }
                    UpdatePointLightColor(0, pl_col);
                }
            }
        }
        }
    }
    KnMenuMedelDrawMap();
    *(float *)(lpDrawMng + 0x41c) = store_fov;
    DrawSetViewRange();
    DrawCalcView();
    return 1;
    }
    }
    }
}







/* Menu_ReLoadFile_MapIconData @ 0x1D41D0 .. 0x1D42A8 (0xd8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @2786 is the string 'menu\\vari\\mmi_01.mmi'
 *   cfg: kept branch: 0x1d4208 if (..) goto .L001D4240
 *   cfg: kept goto: 0x1d4238 -> .L001D4298
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int Menu_ReLoadFile_MapIconData(signed int a0 /* r4 */) {
    s32 s0;
    u32 a2;
    u32 a1;
    s32 v1;
    u32 v0;
    signed int a0_2;

    s0 = a0;
    a0_2 = s_pIconTexList;
    FreeTexList((void *)a0_2);
    a0_2 = s_pIconTexList;
    MemFree((void *)a0_2);
    a0_2 = s_pMenuMapIconDataHeader;
    s_pIconTexList = 0;
    MemFree((void *)a0_2);
    s_pMenuMapIconDataHeader = 0;
    if ((u32)s0 != 0) {
        a0_2 = (signed int)"menu\\vari\\mmi_01.mmi";
        a2 = (u32)&s_pMenuMapIconDataHeader;
        FileRead("menu\\vari\\mmi_01.mmi", -1, (unsigned char **)&s_pMenuMapIconDataHeader, 1, 0,
            0xf, 0);
        v0 = s_pMenuMapIconDataHeader;
        if (v0 != 0) {
            goto _L001D4240;
        }
        v0 = 0;
        goto _L001D4298;
        _L001D4240:;
        a0_2 = v0 + 0x20;
        a1 = (u32)&s_pIconTexList;
        ReadTexList((char *)a0_2, (void **)&s_pIconTexList, 6, 0);
        v0 = FileCheckAsyncBusy();
        v1 = 1;
        if (v0 == (u32)v1) {
            do {
                FileBackReadControl();
                v0 = FileCheckAsyncBusy();
                v1 = 1;
            } while (v0 == (u32)v1);
        }
    }
    v0 = 1;
    _L001D4298:;
    return v0;
}




/* KnMenuMedelDrawMap @ 0x1D3720 .. 0x1D41C8 (0xaa8 bytes, frame 0x230) */
/*
 * dcomp notes:
 *   quad: a2: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1354 -> 0x248a40
 *   literal: @1356 -> 0x248a50
 *   literal: @1358 -> 0x248a60
 *   literal: @1371 -> 0x248a80
 *   literal: @1396 -> 0x248a90
 *   literal: @1422 -> 0x248aa0
 *   literal: @2769 is the string 'point00.tm2'
 *   literal: @1448 -> 0x248ab0
 *   fpu: float literal 0x3c23d70a at 0x1d37e0
 *   fpu: float literal 0x3d4ccccd at 0x1d37e4
 *   fpu: float literal 0x40490fdb at 0x1d380c
 *   fpu: float literal 0x3ecccccd at 0x1d383c
 *   fpu: float literal 0x40000000 at 0x1d3894
 *   stack: address of the slot at 0x1e0 escapes at 0x1d38bc
 *   fpu: float literal 0x44000000 at 0x1d390c
 *   fpu: mov.s at 0x1d392c is a float copy
 *   fpu: mov.s at 0x1d3950 is a float copy
 *   fpu: float literal 0x40000000 at 0x1d3974
 *   stack: address of the slot at 0x1e4 escapes at 0x1d3990
 *   fpu: float literal 0x43800000 at 0x1d399c
 *   fpu: float literal 0x00000000 at 0x1d39d0
 *   stack: address of the slot at 0x1c0 escapes at 0x1d39e0
 *   stack: address of the slot at 0x1d0 escapes at 0x1d39e0
 *   stack: address of the slot at 0x220 escapes at 0x1d39e0
 *   stack: address of the slot at 0x140 escapes at 0x1d3a18
 *   stack: address of the slot at 0x140 escapes at 0x1d3a7c
 *   fpu: float literal 0x3f800000 at 0x1d3aa0
 *   fpu: mov.s at 0x1d3aa8 is a float copy
 *   fpu: float literal 0x42aa0000 at 0x1d3ab4
 *   fpu: float literal 0x435c0000 at 0x1d3ab8
 *   stack: address of the slot at 0x140 escapes at 0x1d3abc
 *   stack: address of the slot at 0x130 escapes at 0x1d3b48
 *   stack: address of the slot at 0x124 escapes at 0x1d3b48
 *   stack: address of the slot at 0x114 escapes at 0x1d3b48
 *   stack: address of the slot at 0x20c escapes at 0x1d3b48
 *   delay: sll at 0x1d3b90 writes a register its branch at 0x1d3b8c reads
 *   fpu: mtc1 reinterprets v0 at 0x1d3c24
 *   fpu: mtc1 reinterprets v0 at 0x1d3c48
 *   stack: address of the slot at 0x1e0 escapes at 0x1d3c70
 *   fpu: float literal 0x44000000 at 0x1d3c8c
 *   fpu: mov.s at 0x1d3cac is a float copy
 *   fpu: mov.s at 0x1d3cd0 is a float copy
 *   stack: address of the slot at 0x1e0 escapes at 0x1d3cf0
 *   fpu: float literal 0x44800000 at 0x1d3d14
 *   fpu: float literal 0x40000000 at 0x1d3d28
 *   fpu: float literal 0x44000000 at 0x1d3d48
 *   fpu: mov.s at 0x1d3d50 is a float copy
 *   fpu: mov.s at 0x1d3d8c is a float copy
 *   stack: address of the slot at 0x1ec escapes at 0x1d3d98
 *   fpu: float literal 0x40000000 at 0x1d3db4
 *   fpu: float literal 0x43800000 at 0x1d3df0
 *   fpu: float literal 0x3c8ef34d at 0x1d3ec4
 *   fpu: float literal 0x00000000 at 0x1d3edc
 *   fpu: mtc1 reinterprets v0 at 0x1d3ee0
 *   fpu: mtc1 reinterprets v0 at 0x1d3efc
 *   stack: address of the slot at 0x110 escapes at 0x1d3f1c
 *   stack: address of the slot at 0x120 escapes at 0x1d3f1c
 *   stack: address of the slot at 0x130 escapes at 0x1d3f1c
 *   stack: address of the slot at 0x100 escapes at 0x1d3f1c
 *   stack: address of the slot at 0xd0 escapes at 0x1d3ff4
 *   stack: address of the slot at 0x1e0 escapes at 0x1d4008
 *   fpu: float literal 0xc0403cf4 at 0x1d4030
 *   fpu: float literal 0x3f186e8f at 0x1d4040
 *   fpu: float literal 0xc22c025c at 0x1d405c
 *   fpu: float literal 0x44000000 at 0x1d409c
 *   fpu: mov.s at 0x1d40b0 is a float copy
 *   fpu: mov.s at 0x1d40c8 is a float copy
 *   fpu: float literal 0x40000000 at 0x1d40ec
 *   fpu: float literal 0x43800000 at 0x1d4110
 *   fpu: float literal 0x40490fdb at 0x1d4170
 *   stack: address of the slot at 0xe0 escapes at 0x1d4180
 *   stack: address of the slot at 0xf0 escapes at 0x1d4180
 *   stack: address of the slot at 0x210 escapes at 0x1d4180
 *   literal: @1448 initializes the 16-byte local at 0xf0
 *   literal: @1422 initializes the 16-byte local at 0x120
 *   literal: @1396 initializes the 16-byte local at 0x130
 *   literal: @1371 initializes the 16-byte local at 0x1d0
 *   literal: @1358 initializes the 32-byte local at 0x1f0
 *   literal: @1356 initializes the 16-byte local at 0x210
 *   literal: @1354 initializes the 16-byte local at 0x220
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 *   cfg: loop body is not one contiguous region: .L001D3B48
 *   cfg: loop body is not one contiguous region: .L001D3B60
 *   cfg: kept branch: 0x1d3b60 if (..) goto .L001D3B98
 *   cfg: kept branch: 0x1d3b78 if (..) goto .L001D3F28
 *   cfg: kept branch: 0x1d3bb4 if (..) goto .L001D3BD8
 *   cfg: kept branch: 0x1d3bc0 if (..) goto .L001D3F28
 *   cfg: kept branch: 0x1d3f64 if (..) goto .L001D3FC0
 *   cfg: kept branch: 0x1d3f94 if (..) goto .L001D4188
 *   cfg: kept branch: 0x1d3fa4 if (..) goto .L001D4188
 *   cfg: kept goto: 0x1d4148 -> .L001D4190
 */





extern void Menu_GetMapData();
extern void * Menu_GetTexInfo(signed int);

extern signed int Menu_CheckVisitMap(signed int);


extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern void * memcpy(void *, const void *, unsigned int);
extern void FontDrawBegin(int);
extern void SetFontColorRGBA(unsigned int);
extern signed int FsFontSetScale(float, float);
extern void FontPrintXY(float, float, char *, ...);
extern void FontDrawEnd();

extern signed int CheckEventFlag(signed int);

extern signed int Menu_GetNowMapTexId(signed int);
static f32 flicker_1364;
static f32 flicker_timer_1363;



#ifndef PROTO_DW_2210472_FIELDS
#define PROTO_DW_2210472_FIELDS

#endif
#ifndef PROTO_DW_2206142_FIELDS
#define PROTO_DW_2206142_FIELDS

#endif
#ifndef PROTO_DW_2205819_FIELDS
#define PROTO_DW_2205819_FIELDS

#endif
#ifndef PROTO_DW_2194051_FIELDS
#define PROTO_DW_2194051_FIELDS

#endif
#ifndef PROTO_DW_2207918_FIELDS
#define PROTO_DW_2207918_FIELDS
struct dw_2207918_fields { unsigned int dmy : 32; };
#endif
#ifndef PROTO_DW_2197529_FIELDS
#define PROTO_DW_2197529_FIELDS
struct dw_2197529_fields { unsigned long magic_code; unsigned long file_size; unsigned short version_id; unsigned short dmy1; unsigned int info_num; unsigned int data_num; struct dw_2207918_fields mmidh_flag; unsigned char aFilename[32]; };
#endif
#ifndef PROTO_DW_2208523_FIELDS
#define PROTO_DW_2208523_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2194051_FIELDS__160__HP_FFFEB47A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2194051_FIELDS__160__HP_FFFEB47A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2194051_FIELDS__160__HP_FFFEB47A = (int)&(((struct dw_2194051_fields *)0)[160].Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2197529_FIELDS_DATA_NUM_CBAC3F0E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2197529_FIELDS_DATA_NUM_CBAC3F0E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2197529_FIELDS_DATA_NUM_CBAC3F0E = (int)&(((struct dw_2197529_fields *)0)->data_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2197529_FIELDS_INFO_NUM_F623F22E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2197529_FIELDS_INFO_NUM_F623F22E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2197529_FIELDS_INFO_NUM_F623F22E = (int)&(((struct dw_2197529_fields *)0)->info_num) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PLAYERID_33747FA4_DEFINED
#define DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PLAYERID_33747FA4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PLAYERID_33747FA4 = (int)&(((struct dw_2208523_fields *)0)->PlayerId) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2208523_FIELDS_SCENENO_AE521B0C_DEFINED
#define DCOMP_OFF_STRUCT_DW_2208523_FIELDS_SCENENO_AE521B0C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2208523_FIELDS_SCENENO_AE521B0C = (int)&(((struct dw_2208523_fields *)0)->sceneNo) - 0 };
#endif
struct KmmInf { int kmi_0; int kmi_4; int kmi_tw; int kmi_th; int kmi_u; int kmi_v; int kmi_uw; int kmi_vh; char kmi_name[32]; };
struct KmmEnt { int kme_0; int kme_inf; int kme_tex; int kme_ev; float kme_x; float kme_y; float kme_ang; unsigned char kme_b0 : 1; unsigned char kme_b1 : 1; unsigned char kme_b2 : 1; unsigned char kme_b3 : 5; unsigned char kme_p[3]; int kme_alt[3]; short kme_ox; short kme_oy; };

void KnMenuMedelDrawMap(void) {
    u_long128 state;

    state = SfxDraw_GetRenderStateBlock();
    if (KnMenuMng_CheckCtrlPlay(6, 0) != 0) {
        SfxDraw_SetBlendType(0);
        SfxDraw_EnableZTest(0);
        {
        float color[4] = {0.8f, 0.8f, 0.8f, 1.0f};
        float color_pnt[4] = {0.8f, 0.8f, 0.8f, 1.0f};
        float aPos[2][4] = {{256.0f, 256.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}};
        float tex_pos_offset[4];
        float speed;
        u32 pa;
        float hpf;
        void *tex;
        Menu_GetMapData();
        hpf = (float)MdlMng[160].Hp;
        speed = 0.05f * (0.01f * hpf);
        flicker_1364 = sinf(flicker_timer_1363);
        flicker_timer_1363 = flicker_timer_1363 + speed;
        if (flicker_timer_1363 > 3.1415927f) {
            flicker_timer_1363 = flicker_timer_1363 - 3.1415927f;
        }
        color_pnt[3] = color_pnt[3] * (0.4f + 0.4f * flicker_1364);
        tex = *(void **)((u8 *)Menu_GetTexInfo(Menu_GetTexId_now()) + 0x40);
        {
        float uv[4] = {512.0f, 512.0f, 1.0f, 1.0f};
        float pos[4];
        if ((u8)Menu_GetMapTexSorL() == 0) {
            uv[0] = uv[0] * 2.0f;
            uv[1] = uv[1] * 2.0f;
        }
        Menu_GetTexCenter(Menu_GetTexId_now(), tex_pos_offset);
        if (Menu_CheckVisitMap(Menu_GetTexId_now()) == 0) {
            s_mm_cam_pos[0] = tex_pos_offset[0];
            s_mm_cam_pos[1] = tex_pos_offset[1];
        }
        tex_pos_offset[0] = (tex_pos_offset[0] - s_mm_cam_pos[0]) / tex_pos_offset[2];
        tex_pos_offset[0] = tex_pos_offset[0] * 512.0f;
        tex_pos_offset[1] = (tex_pos_offset[1] - s_mm_cam_pos[1]) / tex_pos_offset[3];
        tex_pos_offset[1] = tex_pos_offset[1] * 512.0f;
        if ((u8)Menu_GetMapTexSorL() == 0) {
            tex_pos_offset[0] = tex_pos_offset[0] * 2.0f;
            tex_pos_offset[1] = tex_pos_offset[1] * 2.0f;
        }
        pos[0] = 256.0f + tex_pos_offset[0];
        pos[1] = 256.0f + tex_pos_offset[1];
        pos[2] = aPos[1][2];
        pos[3] = aPos[1][3];
        SfxDraw_SetTexture(tex);
        SfxDraw_DrawSprite_Scr(pos, uv, 0.0f, color, (void *)0);
        if (Menu_CheckVisitMap(Menu_GetTexId_now()) == 0) {
            unsigned short *str = KnMsgMng_GetMsgStr(0x1d4e7);
            unsigned char buf[128] = {0};
            if (str != 0) {
                int n = 0;
                while (str[n] != 0) {
                    n++;
                }
                memcpy(buf, str, n * 2 + 2);
            }
            FontDrawBegin(0);
            SetFontColorRGBA(0x7f7f7f7f);
            FsFontSetScale(1.0f, 1.0f);
            FontPrintXY(85.0f, 220.0f, (char *)buf);
            SetFontColorRGBA(0x7f7f7f7f);
            FontDrawEnd();
            SfxDraw_SetRenderStateBlock(state);
        }
        if (Menu_CheckVisitMap(Menu_GetTexId_now()) != 0) {
            struct dw_2197529_fields *hdr;
            hdr = (struct dw_2197529_fields *)s_pMenuMapIconDataHeader;
            if (hdr != 0) {
                struct KmmInf *pMenuMapIconInfo;
                struct KmmInf *pTexInfo;
                struct KmmEnt *pMenuMapIconData;
                pMenuMapIconInfo = (struct KmmInf *)((char *)hdr + 0x40);
                pMenuMapIconData = (struct KmmEnt *)(pMenuMapIconInfo + hdr->info_num);
                {
                int i;
                float color_icon[4] = {1.0f, 1.0f, 1.0f, 1.0f};
                int idic;
                for (idic = 0; idic < 2; idic++) {
                    for (i = 0; i < ((struct dw_2197529_fields *)s_pMenuMapIconDataHeader)->data_num; i++) {
                        pTexInfo = &pMenuMapIconInfo[pMenuMapIconData[i].kme_inf];
                        if (idic == 1) {
                            int alt = pMenuMapIconData[i].kme_alt[GameSt[DCOMP_OFF_STRUCT_DW_2208523_FIELDS_PLAYERID_33747FA4]];
                            if (alt == -1) {
                                continue;
                            }
                            pTexInfo = &pMenuMapIconInfo[alt];
                        }
                        if (pMenuMapIconData[i].kme_b1 == 1) {
                            continue;
                        }
                        if (CheckEventFlag(pMenuMapIconData[i].kme_ev) == 0 && pMenuMapIconData[i].kme_b2 == 0) {
                            continue;
                        }
                        if (pMenuMapIconData[i].kme_b0 == 1) {
                            if (pMenuMapIconData[i].kme_tex == Menu_GetTexId_now()) {
                                void *pIconTex;
                                float size_[4] = {0.0f, 0.0f, 1.0f, 1.0f};
                                float pos2[4];
                                float tex_rect[4];
                                float rad;
                                size_[0] = (float)(pTexInfo->kmi_uw / 2);
                                size_[1] = (float)(pTexInfo->kmi_vh / 2);
                                pIconTex = GetTexMngByName((void *)s_pIconTexList, pTexInfo->kmi_name);
                                Menu_GetTexCenter(Menu_GetTexId_now(), tex_pos_offset);
                                tex_pos_offset[0] = (pMenuMapIconData[i].kme_x - s_mm_cam_pos[0]) / tex_pos_offset[2];
                                tex_pos_offset[0] = tex_pos_offset[0] * 512.0f;
                                tex_pos_offset[1] = (pMenuMapIconData[i].kme_y - s_mm_cam_pos[1]) / tex_pos_offset[3];
                                tex_pos_offset[1] = tex_pos_offset[1] * 512.0f;
                                if (pMenuMapIconData[i].kme_b0 == 1) {
                                    Menu_GetTexCenter(pMenuMapIconData[i].kme_tex, tex_pos_offset);
                                    tex_pos_offset[0] = ((tex_pos_offset[0] + ((tex_pos_offset[2] * (pMenuMapIconData[i].kme_x / 1024.0f)) - (tex_pos_offset[2] / 2.0f))) - s_mm_cam_pos[0]) / tex_pos_offset[2];
                                    tex_pos_offset[0] = tex_pos_offset[0] * 512.0f;
                                    tex_pos_offset[1] = ((tex_pos_offset[1] + ((tex_pos_offset[3] * (pMenuMapIconData[i].kme_y / 1024.0f)) - (tex_pos_offset[3] / 2.0f))) - s_mm_cam_pos[1]) / tex_pos_offset[3];
                                    tex_pos_offset[1] = tex_pos_offset[1] * 512.0f;
                                }
                                if ((u8)Menu_GetMapTexSorL() == 0) {
                                    tex_pos_offset[0] = tex_pos_offset[0] * 2.0f;
                                    tex_pos_offset[1] = tex_pos_offset[1] * 2.0f;
                                    size_[0] = size_[0] * 2.0f;
                                    size_[1] = size_[1] * 2.0f;
                                }
                                pos2[0] = 256.0f + tex_pos_offset[0];
                                pos2[1] = 256.0f + tex_pos_offset[1];
                                pos2[2] = aPos[1][2];
                                pos2[3] = aPos[1][3];
                                tex_rect[0] = (float)pTexInfo->kmi_u / (float)pTexInfo->kmi_tw;
                                tex_rect[1] = (float)pTexInfo->kmi_v / (float)pTexInfo->kmi_th;
                                tex_rect[2] = tex_rect[0] + (float)pTexInfo->kmi_uw / (float)pTexInfo->kmi_tw;
                                tex_rect[3] = tex_rect[1] + (float)pTexInfo->kmi_vh / (float)pTexInfo->kmi_th;
                                if (pIconTex == 0) {
                                    SfxDraw_SetRenderStateBlock(state);
                                    return;
                                }
                                SfxDraw_SetTexture(pIconTex);
                                { float a = (float)pMenuMapIconData[i].kme_ang; rad = 0.01745f * a; }
                                if (idic == 1) {
                                    rad = 0.0f;
                                    pos2[0] = pos2[0] + (float)pMenuMapIconData[i].kme_ox;
                                    pos2[1] = pos2[1] + (float)pMenuMapIconData[i].kme_oy;
                                }
                                SfxDraw_DrawSprite_Scr(pos2, size_, rad, color_icon, tex_rect);
                            }
                        }
                    }
                }
                }
            }
        }
        if ((Menu_CheckVisitMap(Menu_GetTexId_now()) != 0 && Menu_GetNowMapTexId(GameSt[DCOMP_OFF_STRUCT_DW_2208523_FIELDS_SCENENO_AE521B0C]) == Menu_GetTexId_now()) || (Menu_GetTexId_now() == 0x1f5 && GameSt[DCOMP_OFF_STRUCT_DW_2208523_FIELDS_SCENENO_AE521B0C] == 0x57 && Menu_CheckVisitMap(Menu_GetTexId_now()) != 0)) {
            struct dw_2194051_fields *lpMy = (struct dw_2194051_fields *)&MdlMng[160];
            void *pTex = GetTexMngByName((void *)0, "point00.tm2");
            float size_[4] = {32.0f, 32.0f, 1.0f, 1.0f};
            float pos[4];
            float my_pos[4];
            fsvu0_CopyVectorF(my_pos, lpMy->Pos);
            Menu_GetTexCenter(Menu_GetTexId_now(), tex_pos_offset);
            if (GameSt[9] >= 51 && GameSt[9] <= 59) {
                my_pos[0] -= -3.0037203f;
                my_pos[1] -= 0.595437f;
                my_pos[2] -= -43.002304f;
            }
            tex_pos_offset[0] = (my_pos[0] - s_mm_cam_pos[0]) / tex_pos_offset[2];
            tex_pos_offset[0] = tex_pos_offset[0] * 512.0f;
            tex_pos_offset[1] = (my_pos[2] - s_mm_cam_pos[1]) / tex_pos_offset[3];
            tex_pos_offset[1] = tex_pos_offset[1] * 512.0f;
            if ((u8)Menu_GetMapTexSorL() == 0) {
                tex_pos_offset[0] = tex_pos_offset[0] * 2.0f;
                tex_pos_offset[1] = tex_pos_offset[1] * 2.0f;
            }
            pos[0] = 256.0f + tex_pos_offset[0];
            pos[1] = 256.0f + tex_pos_offset[1];
            pos[2] = aPos[1][2];
            pos[3] = aPos[1][3];
            if (pTex == 0) {
                SfxDraw_SetRenderStateBlock(state);
                return;
            }
            SfxDraw_SetTexture(pTex);
            SfxDraw_DrawSprite_Scr(pos, size_, 3.1415927f + lpMy->Ang[1], color_pnt, (void *)0);
        }
        SfxDraw_SetRenderStateBlock(state);
        }
        }
    }
}







/* KnMenuModelMng_Delete @ 0x1D36F0 .. 0x1D3718 (0x28 bytes) */


u32 KnMenuModelMng_Delete(void) {
    u32 v0;

    v0 = pKnMenuModelMng;
    if (v0 == 0) {
        v0 = 0;
    } else {
        *(u32 *)v0 = 0;
        v0 = 1;
    }
    return v0;
}




/* KnMenuModelMng_ReLoadMdl @ 0x1D3210 .. 0x1D36E4 (0x4d4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   literal: @2499 is the string 'menu/bnd/cloth_sample07.bnd'
 *   literal: @2500 is the string 'menu/bnd/fe_me_0011.bnd'
 *   literal: @2501 is the string 'menu/tex/ClothCng.tex'
 *   literal: @2502 is the string 'menu/bnd/fe_me_re_0000.bnd'
 *   literal: @2503 is the string 'menu/bnd/cloth00.bnd'
 *   literal: @2504 is the string 'menu/bnd/fe_me_re_0001.bnd'
 *   literal: @2505 is the string 'menu/bnd/cloth01.bnd'
 *   literal: @2506 is the string 'menu/bnd/fe_me_re_0002.bnd'
 *   literal: @2507 is the string 'menu/bnd/cloth02.bnd'
 *   literal: @2508 is the string 'menu/tex/arttxt00.tex'
 *   literal: @2509 is the string 'menu/tex/arttxt01.tex'
 *   literal: @2510 is the string 'menu/bnd/fe_me_re_0003.bnd'
 *   literal: @2511 is the string 'menu/bnd/fe_me_re_0004.bnd'
 *   literal: @2512 is the string 'menu/bnd/cloth04.bnd'
 *   literal: @2513 is the string 'menu/bnd/cloth05.bnd'
 *   delay: addiu at 0x1d330c writes a register its branch at 0x1d3308 reads
 *   delay: addiu at 0x1d3320 writes a register its branch at 0x1d331c reads
 *   delay: addiu at 0x1d3334 writes a register its branch at 0x1d3330 reads
 *   delay: addiu at 0x1d3348 writes a register its branch at 0x1d3344 reads
 *   delay: addiu at 0x1d34c8 writes a register its branch at 0x1d34c4 reads
 *   delay: addiu at 0x1d3554 writes a register its branch at 0x1d3550 reads
 *   cfg: kept branch: 0x1d34c8 if (..) goto .L001D3528
 *   cfg: kept branch: 0x1d3554 if (..) goto .L001D35B0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void FreeMdlData(void *, signed int);
extern void ReadMdlBndFile(char *, signed int, void *);
extern signed int Menu_GetGetItemId(void);
extern signed int Menu_GetNowDocId(void);
extern signed int KnMenuMng_CheckCtrlPlay(int, signed int);
extern void * s_pClothMdlTexList;
extern void * s_GetItemBG;

signed int KnMenuModelMng_ReLoadMdl(int a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s3;
    s32 s2;
    u32 a2;
    u32 s1;
    u32 s0;
    s32 v1;
    u32 v0;
    int a0_2;
    signed int a1_2;

    s3 = a0;
    a0_2 = pKnMenuModelMng;
    s2 = a1;
    v0 = MngState_DrawExeCheck((void *)a0_2);
    v1 = 1;
    if (v0 != (u32)v1) {
        v0 = v1;
    } else {
        FlushCache(0);
        do {
            v0 = *(volatile s32 *)0x10009000;
            v0 = v0 & 0x100;
        } while (v0 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
        s1 = 0;
        s0 = 0;
        do {
            v0 = 0x60000;
            v1 = 0x60000 | 0xe800;
            a1_2 = 1;
            v1 = s0 + (s32)v1;
            v0 = (u32)MdlData;
            FreeMdlData((void *)((u8 *)MdlData + v1), a1_2);
            s1 = s1 + 1;
            s0 = s0 + 0x680;
        } while ((s32)s1 < (s32)0xf);
        a0_2 = (int)s_pClothMdlTexList;
        FreeTexList((void *)a0_2);
        a0_2 = (int)s_pClothMdlTexList;
        MemFree((void *)a0_2);
        a0_2 = (int)s_GetItemBG;
        s_pClothMdlTexList = (void *)0;
        FreeTexList((void *)a0_2);
        a0_2 = (int)s_GetItemBG;
        MemFree((void *)a0_2);
        a0_2 = s_pIconTexList;
        s_GetItemBG = (void *)0;
        FreeTexList((void *)a0_2);
        a0_2 = s_pIconTexList;
        MemFree((void *)a0_2);
        a0_2 = s_pMenuMapIconDataHeader;
        s_pIconTexList = 0;
        MemFree((void *)a0_2);
        v1 = (u16)s3;
        v0 = 0x8000;
        s_pMenuMapIconDataHeader = 0;
        switch ((u32)v1) {
        case 64:
            a0_2 = (int)"menu/bnd/cloth_sample07.bnd";
            a1_2 = 0x11d;
            ReadMdlBndFile("menu/bnd/cloth_sample07.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
            a1_2 = (signed int)&s_pClothMdlTexList;
            a0_2 = (int)"menu/tex/ClothCng.tex";
            a2 = 6;
            ReadTexList("menu/tex/ClothCng.tex", &s_pClothMdlTexList, a2, 0);
            break;
        case 128:
            a0_2 = (int)"menu/bnd/fe_me_re_0000.bnd";
            a1_2 = 0x118;
            ReadMdlBndFile("menu/bnd/fe_me_re_0000.bnd", a1_2, (void *)0);
            a1_2 = 0x112;
            a0_2 = (int)"menu/bnd/cloth00.bnd";
            ReadMdlBndFile("menu/bnd/cloth00.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
            break;
        case 256:
            a0_2 = (int)"menu/bnd/fe_me_re_0001.bnd";
            a1_2 = 0x119;
            ReadMdlBndFile("menu/bnd/fe_me_re_0001.bnd", a1_2, (void *)0);
            a1_2 = 0x113;
            a0_2 = (int)"menu/bnd/cloth01.bnd";
            ReadMdlBndFile("menu/bnd/cloth01.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
            break;
        case 512:
            a0_2 = (int)"menu/bnd/fe_me_re_0002.bnd";
            a1_2 = 0x11a;
            ReadMdlBndFile("menu/bnd/fe_me_re_0002.bnd", a1_2, (void *)0);
            a1_2 = 0x114;
            a0_2 = (int)"menu/bnd/cloth02.bnd";
            ReadMdlBndFile("menu/bnd/cloth02.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
            break;
        case 8192:
            v0 = Menu_GetGetItemId();
            s1 = v0;
            v0 = Menu_GetNowDocId();
            s0 = v0;
            a0_2 = 7;
            a1_2 = 1;
            v0 = KnMenuMng_CheckCtrlPlay(a0_2, a1_2);
            v1 = 0x2710;
            if (v0 != 0) {
                v0 = 0x2d;
                v1 = (s32)s1 % v1;
                if ((u32)v1 != v0) {
                    v0 = 0x2e;
                    if ((u32)v1 != v0) {
                        goto _L001D3528;
                    }
                }
                v0 = 0x2d;
                if ((u32)v1 == v0) {
                    a1_2 = (signed int)&s_GetItemBG;
                    a0_2 = (int)"menu/tex/arttxt00.tex";
                    a2 = 6;
                    ReadTexList("menu/tex/arttxt00.tex", &s_GetItemBG, a2, 0);
                    break;
                } else {
                    v0 = 0x2e;
                    if ((u32)v1 != v0) {
                        break;
                    }
                    a1_2 = (signed int)&s_GetItemBG;
                    a0_2 = (int)"menu/tex/arttxt01.tex";
                    a2 = 6;
                    ReadTexList("menu/tex/arttxt01.tex", &s_GetItemBG, a2, 0);
                    break;
                }
            } else {
                _L001D3528:;
                a0_2 = 3;
                a1_2 = 7;
                v0 = KnMenuMng_CheckCtrlPlay(a0_2, a1_2);
                v1 = 0x2710;
                if (v0 != 0) {
                    v0 = 0x2d;
                    v1 = (s32)s0 % v1;
                    if ((u32)v1 != v0) {
                        v0 = 0x2e;
                        if ((u32)v1 != v0) {
                            goto _L001D35B0;
                        }
                    }
                    v0 = 0x2d;
                    if ((u32)v1 == v0) {
                        a1_2 = (signed int)&s_GetItemBG;
                        a0_2 = (int)"menu/tex/arttxt00.tex";
                        a2 = 6;
                        ReadTexList("menu/tex/arttxt00.tex", &s_GetItemBG, a2, 0);
                        break;
                    } else {
                        v0 = 0x2e;
                        if ((u32)v1 != v0) {
                            break;
                        }
                        a1_2 = (signed int)&s_GetItemBG;
                        a0_2 = (int)"menu/tex/arttxt01.tex";
                        a2 = 6;
                        ReadTexList("menu/tex/arttxt01.tex", &s_GetItemBG, a2, 0);
                        break;
                    }
                } else {
                    _L001D35B0:;
                    a0_2 = (int)"menu/bnd/fe_me_re_0002.bnd";
                    a1_2 = 0x11a;
                    ReadMdlBndFile("menu/bnd/fe_me_re_0002.bnd", a1_2, (void *)0);
                    a1_2 = 0x114;
                    a0_2 = (int)"menu/bnd/cloth02.bnd";
                    ReadMdlBndFile("menu/bnd/cloth02.bnd", a1_2, (void *)0);
                    a1_2 = 0x110;
                    a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
                    ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
                    break;
                }
            }
        case 1024:
            break;
        case 2048:
            a0_2 = (int)"menu/bnd/fe_me_re_0003.bnd";
            a1_2 = 0x11b;
            ReadMdlBndFile("menu/bnd/fe_me_re_0003.bnd", a1_2, (void *)0);
            a1_2 = 0x11c;
            a0_2 = (int)"menu/bnd/fe_me_re_0004.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_re_0004.bnd", a1_2, (void *)0);
            a1_2 = 0x116;
            a0_2 = (int)"menu/bnd/cloth04.bnd";
            ReadMdlBndFile("menu/bnd/cloth04.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
            break;
        case 4096:
            a0_2 = (int)"menu/bnd/cloth05.bnd";
            a1_2 = 0x117;
            ReadMdlBndFile("menu/bnd/cloth05.bnd", a1_2, (void *)0);
            a1_2 = 0x110;
            a0_2 = (int)"menu/bnd/fe_me_0011.bnd";
            ReadMdlBndFile("menu/bnd/fe_me_0011.bnd", a1_2, (void *)0);
        case 16384:
        case 32768:
            break;
        }
        if (s2 != 0) {
            v0 = FileCheckAsyncBusy();
            v1 = 1;
            if (v0 == (u32)v1) {
                do {
                    FileBackReadControl();
                    v0 = FileCheckAsyncBusy();
                    v1 = 1;
                } while (v0 == (u32)v1);
            }
        }
        v0 = 1;
    }
    return v0;
}

















signed int KnMenuModelMng_ReMakeMdl(int load_flag) {
    int i;
    struct KNMDL_MNG *pMdlMng;

    if (MngState_DrawExeCheck((void *)pKnMenuModelMng) != 1) {
        return 1;
    }
    FlushCache(0);
    while ((*(volatile int *)0x10009000 & 0x100) || (*(volatile int *)0x1000a000 & 0x100)) {
    }
    for (i = 0; i < 15; i++) {
        pMdlMng = &KN_MDLMNG[KN_MDL + i];
        FreeMdlMng(pMdlMng);
        pMdlMng->bUse = 0;
        CsMngFreeRtaData(pMdlMng);
    }
    pMdlMng = &KN_MDLMNG[KN_MDL];
    switch ((unsigned short)load_flag) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
    case 0x10:
    case 0x20:
        break;
    case 0x40:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[2], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[2]);
        SetMdlMng(&pMdlMng[3], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[3]);
        SetMdlMng(&pMdlMng[4], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[4]);
        SetMdlMng(&pMdlMng[5], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[5]);
        SetMdlMng(&pMdlMng[6], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[6]);
        SetMdlMng(&pMdlMng[7], KN_MDLDATA(285)); CsMngMakeRtaData(&pMdlMng[7]);
        SetMdlShiftTexPacket(&pMdlMng[3], 0, "cloth_sample01.tm2");
        SetMdlShiftTexPacket(&pMdlMng[4], 0, "cloth_sample02.tm2");
        SetMdlShiftTexPacket(&pMdlMng[5], 0, "cloth_sample03.tm2");
        SetMdlShiftTexPacket(&pMdlMng[6], 0, "cloth_sample04.tm2");
        SetMdlShiftTexPacket(&pMdlMng[7], 0, "cloth_sample05.tm2");
        break;
    case 0x80:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[9], KN_MDLDATA(280));
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(274)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x100:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[10], KN_MDLDATA(281));
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(275)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x200:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[11], KN_MDLDATA(282));
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(276)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x2000:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[11], KN_MDLDATA(282));
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(276)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x400:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        break;
    case 0x800:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[12], KN_MDLDATA(283));
        SetMdlMng(&pMdlMng[13], KN_MDLDATA(284));
        SetMdlMng(&pMdlMng[14], KN_MDLDATA(0)); CsMngMakeRtaData(&pMdlMng[14]);
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(278)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x1000:
        SetMdlMng(&pMdlMng[0], KN_MDLDATA(272));
        SetMdlMng(&pMdlMng[1], KN_MDLDATA(279)); CsMngMakeRtaData(&pMdlMng[1]);
        break;
    case 0x4000:
    case 0x8000:
        break;
    }
    pMdlMng[0].bErase = 1;
    KN_SET_DEFPOS(1, 0.05f, -3.7f, 12.2f, 1.9f);
    KN_SET_DEFPOS(9, -1.9f, 0.3f, 7.8f, 1.9f);
    KN_SET_DEFPOS(10, -0.6f, 0.3f, 7.8f, 1.9f);
    KN_SET_DEFPOS(11, -0.6f, 0.3f, 7.8f, 1.9f);
    KN_SET_DEFPOS(12, 2.45f, 0.0f, 7.8f, 1.9f);
    KN_SET_DEFPOS(13, -2.05f, 0.0f, 7.8f, 1.9f);
    KN_SET_DEFPOS(0, 0.0f, 0.0f, 10.5f, 3.8f);
    KN_SET_DEFPOS(14, -1.2f, 0.7f, 8.0f, 1.9f);
    KN_SET_DEFPOS(2, -5.0f, -3.4f, 12.2f, 1.9f);
    KN_SET_DEFPOS(3, -3.0f, -3.5f, 12.3f, 1.9f);
    KN_SET_DEFPOS(4, -1.0f, -3.4f, 12.4f, 1.9f);
    KN_SET_DEFPOS(5, 1.0f, -3.5f, 12.4f, 1.9f);
    KN_SET_DEFPOS(6, 3.0f, -3.4f, 12.3f, 1.9f);
    KN_SET_DEFPOS(7, 5.0f, -3.5f, 12.2f, 1.9f);
    return 1;
}





/* Menu_SetModelState @ 0x1D1460 .. 0x1D271C (0x12bc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1d149c writes a register its branch at 0x1d1498 reads
 *   delay: addiu at 0x1d1660 writes a register its branch at 0x1d165c reads
 *   fpu: float literal 0x3dcccccd at 0x1d189c
 *   fpu: float literal 0x3dcccccd at 0x1d1b14
 *   fpu: float literal 0x3dcccccd at 0x1d1d8c
 *   fpu: float literal 0x3dcccccd at 0x1d2004
 *   fpu: float literal 0x3dcccccd at 0x1d227c
 *   fpu: float literal 0x3dcccccd at 0x1d24f4
 *   declaration vs inferred signature: return void vs inferred u32
 */

void Menu_SetModelState(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */,
        void *a3 /* r7 */) {
    s32 s3;
    s32 s2;
    s32 s1;
    u32 *s0;
    u32 v1;
    u32 v0;
    float f7;
    float f6;
    float f5;
    float f3;
    float f2;
    float f1;
    float f0;
    signed int a0_2;
    signed int a1_2;

    s3 = a0;
    s2 = a1;
    s1 = a2;
    s0 = (u32 *)a3;
    v0 = KnMenuMng_GetCursorId(3, 0);
    if ((u32)s1 == (u32)8) {
        MenuModelPosState[1] = 1;
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = v0;
                v1 = v1 == (u32)0;
            }
            MenuModelPosState[2] = v1 ^ 1;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = (u32)(v0 ^ 6) < (u32)1;
            }
            MenuModelPosState[3] = v1 ^ 1;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = (u32)(v0 ^ 0xc) < (u32)1;
            }
            MenuModelPosState[4] = v1 ^ 1;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = (u32)(v0 ^ 0x12) < (u32)1;
            }
            MenuModelPosState[5] = v1 ^ 1;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = (u32)(v0 ^ 0x18) < (u32)1;
            }
            MenuModelPosState[6] = v1 ^ 1;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0) {
        v1 = 8;
        if ((u32)s1 == v1) {
            v1 = *(s32 *)s0;
            v1 = (s32)v1 < (s32)0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                v1 = (u32)(v0 ^ 0x1e) < (u32)1;
            }
            MenuModelPosState[7] = v1 ^ 1;
        }
    }
    if ((u32)s1 == (u32)0xb) {
        MenuModelPosState[1] = 3;
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[2] = 9;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[3] = 8;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[4] = 7;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[5] = 6;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[6] = 5;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)0xb) {
            MenuModelPosState[7] = 4;
        }
    }
    if ((u32)s1 == (u32)6) {
        MenuModelPosState[1] = 0;
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[2] = 0;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[3] = 0;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[4] = 0;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[5] = 0;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[6] = 0;
        }
    }
    if ((u32)s3 == (u32)3 && (u32)s2 == 0) {
        if ((u32)s1 == (u32)6) {
            MenuModelPosState[7] = 0;
        }
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 2);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 8) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 9) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0xa) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x52b20);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52b20);
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52b20);
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52b20);
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52b20);
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52b20);
            f6 = *(float *)(MdlMngB + 0x52b24);
            f5 = *(float *)(MdlMngB + 0x52b28);
            *(f32 *)(MdlMngB + 0x52b20) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52b24) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52b28) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 3);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 0xc) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 0xd) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0xe) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x52ce0);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ce0);
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ce0);
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ce0);
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ce0);
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ce0);
            f6 = *(float *)(MdlMngB + 0x52ce4);
            f5 = *(float *)(MdlMngB + 0x52ce8);
            *(f32 *)(MdlMngB + 0x52ce0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ce4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ce8) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 4);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 0x10) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 0x11) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0x12) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x52ea0);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ea0);
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ea0);
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ea0);
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ea0);
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x52ea0);
            f6 = *(float *)(MdlMngB + 0x52ea4);
            f5 = *(float *)(MdlMngB + 0x52ea8);
            *(f32 *)(MdlMngB + 0x52ea0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x52ea4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x52ea8) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 5);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 0x14) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 0x15) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0x16) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x53060);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53060);
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53060);
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53060);
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53060);
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53060);
            f6 = *(float *)(MdlMngB + 0x53064);
            f5 = *(float *)(MdlMngB + 0x53068);
            *(f32 *)(MdlMngB + 0x53060) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53064) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53068) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 6);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 0x18) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 0x19) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0x1a) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x53220);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53220);
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53220);
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53220);
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53220);
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x53220);
            f6 = *(float *)(MdlMngB + 0x53224);
            f5 = *(float *)(MdlMngB + 0x53228);
            *(f32 *)(MdlMngB + 0x53220) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x53224) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x53228) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    v1 = 3;
    if ((u32)s3 == v1 && (u32)s2 == 0 && (u32)s1 == v1) {
        a0_2 = *(s32 *)(MenuModelPosState + 7);
        v1 = (u32)MenuModelTargetPosOffset;
        a1_2 = 0;
        v1 = (s32)(u32)&((struct { u8 b[0x10]; } *)MenuModelTargetPosOffset)[a0_2];
        f3 = (*(float *)(MenuModelDefPos + 0x1c) + *(float *)v1);
        f2 = (*(float *)(MenuModelDefPos + 0x1d) + (float)*(float *)((v1 + 4)));
        f1 = (*(float *)(MenuModelDefPos + 0x1e) + *(float *)((v1 + 8)));
        v1 = 0x3dcccccd;
        f0 = 0.100000001f;
        do {
            f7 = *(float *)(MdlMngB + 0x533e0);
            a1_2 = (u32)(a1_2) + 6;
            v1 = (u32)(s32)a1_2 < (u32)0xc;
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x533e0);
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x533e0);
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x533e0);
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x533e0);
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
            f7 = *(float *)(MdlMngB + 0x533e0);
            f6 = *(float *)(MdlMngB + 0x533e4);
            f5 = *(float *)(MdlMngB + 0x533e8);
            *(f32 *)(MdlMngB + 0x533e0) = (f7 + (f0 * (f3 - f7)));
            *(f32 *)(MdlMngB + 0x533e4) = (f6 + (f0 * (f2 - f6)));
            *(f32 *)(MdlMngB + 0x533e8) = (f5 + (f0 * (f1 - f5)));
        } while (v1 != 0);
    }
    return;
}

static u8 s_KnMenuModelMng[0x114];
u32 s_pMenuMapIconDataHeader = 0;
u32 s_pIconTexList = 0;
