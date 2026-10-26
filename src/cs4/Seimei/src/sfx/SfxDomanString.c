#include "common.h"
extern u32 s_max_time;
extern u32 s_curr_time;
extern u32 s_bAct;
extern f32 s_azim;
extern void sceVu0CopyVector();
extern u32 s_pos[];
void SfxDomanString_Init(void);
void SfxDomanString_SetAzim(float f12 /* f12 */);
void SfxDomanString_SetPos(u8 *a0 /* r4 */);

/* SfxDomanString_SetPos @ 0x1C0020 .. 0x1C0030 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j sceVu0CopyVector at 0x1c0028 leaves the function
 *   return value dropped, call kept: the function is void
 */


void SfxDomanString_SetPos(u8 *a0 /* r4 */) {
    u32 a1;

    a1 = (u32)a0;
    a0 = (u8 *)s_pos;
    sceVu0CopyVector(a0, a1);
    return;
}

/* SfxDomanString_SetAzim @ 0x1C0010 .. 0x1C0018 (0x8 bytes) */


void SfxDomanString_SetAzim(float f12 /* f12 */) {
    s_azim = (float)f12;
    return;
}

/* SfxDomanString_Start @ 0x1BFFD0 .. 0x1C0004 (0x34 bytes) */
/*
 * The unit's tentative statics are emitted by MWCC in reverse order of their
 * first declaration, so the layout of .sbss (test$947, s_phase, s_bAct,
 * s_curr_time, s_max_time, s_dmg_id, s_azim) and of .bss (s_apHitChar,
 * s_pos, s_stage_mdl) fixes this declaration order.
 */
#ifndef PROTO_DW_2030001_FIELDS
#define PROTO_DW_2030001_FIELDS
struct dw_2030001_fields { float stq[3]; unsigned int rgba; float pos[4]; };
#endif
static struct dw_2030001_fields s_stage_mdl[4];
static u32 s_pos[0x4];
static u32 s_apHitChar[0x3];
static f32 s_azim;
static u16 s_dmg_id;
static u32 s_max_time;
static u32 s_curr_time;
static u32 s_bAct;
static s32 s_phase;

void SfxDomanString_Start(float f12 /* f12 */, unsigned short a0 /* r4 */) {
    *(float *)&s_max_time = f12;
    s_curr_time = 0;
    s_bAct = 1;
    s_phase = 0;
    s_apHitChar[0] = 0;
    s_dmg_id = a0;
    s_apHitChar[1] = 0;
    s_apHitChar[2] = 0;
    return;
}







/* SfxDomanString_Init @ 0x1BFFC0 .. 0x1BFFD0 (0x10 bytes) */


void SfxDomanString_Init(void) {
    s_max_time = 0;
    s_curr_time = 0;
    s_bAct = 0;
    return;
}


/* SfxDomanString_Act @ 0x1BFCB0 .. 0x1BFFBC (0x30c bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1bfce8 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1bfd68
 *   stack: address of the slot at 0xc4 escapes at 0x1bfd68
 *   stack: address of the slot at 0xc8 escapes at 0x1bfd68
 *   stack: address of the slot at 0xc9 escapes at 0x1bfd68
 *   stack: address of the slot at 0xca escapes at 0x1bfd68
 *   fpu: float literal 0x40800000 at 0x1bfe28
 *   stack: address of the slot at 0xb0 escapes at 0x1bfe54
 *   stack: address of the slot at 0xb0 escapes at 0x1bfecc
 *   stack: address of the slot at 0xb0 escapes at 0x1bfee0
 *   delay: lui at 0x1bff10 writes a register its branch at 0x1bff0c reads
 *   cfg: kept goto: 0x1bfd24 -> .L001BFF88
 *   cfg: loop body is not one contiguous region: .L001BFD68
 *   cfg: loop body is not one contiguous region: .L001BFDE0
 *   cfg: kept branch: 0x1bfde0 if (..) goto .L001BFDF8
 *   cfg: loop body is not one contiguous region: .L001BFF08
 *   cfg: kept branch: 0x1bff08 if (..) goto .L001BFF28
 *   cfg: kept goto: 0x1bff70 -> .L001BFF88
 */

extern signed int CheckMyDamage(void *, void *);
extern signed int CheckEneDamage(void *);
extern float Math_GetDist(float *, float *);
extern void * GetEneParam(signed int, unsigned char);
extern signed int CheckP030Counter(void *, void *);
extern void SetMyDamageProc(void *);
extern void SetEneDamageProc(void *);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern struct dw_2017412_fields MdlMng[];

struct dw_2014805_fields;
struct dw_2017412_fields;
#ifndef PROTO_DW_2030636_FIELDS
#define PROTO_DW_2030636_FIELDS
struct dw_2030636_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_2014805_FIELDS
#define PROTO_DW_2014805_FIELDS
struct dw_2014805_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_2030636_fields DmyPoly[32]; };
#endif
#ifndef PROTO_DW_2028329_FIELDS
#define PROTO_DW_2028329_FIELDS
struct dw_2028329_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2026365_FIELDS
#define PROTO_DW_2026365_FIELDS
struct dw_2026365_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2026042_FIELDS
#define PROTO_DW_2026042_FIELDS
struct dw_2026042_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2017412_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2017412_FIELDS
#define PROTO_DW_2017412_FIELDS
struct dw_2017412_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2014805_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2017412_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2028329_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2026365_fields flags; unsigned char _pad1[3]; struct dw_2026042_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif


struct dw_dmgprm_fields { float DmgPos[4]; struct dw_2017412_fields *lpTarget; void *lpMasterPrm; unsigned char TeamNo; unsigned char AttackNo; unsigned short PauseTime; unsigned char bFinish; unsigned char unused[3]; float PowerScl; unsigned char _pad0[12]; };

void SfxDomanString_Act(float dt) {
    struct dw_2017412_fields *p;
    struct dw_dmgprm_fields prm;
    int found;
    int i;
    int my;
    int res;

    if (s_bAct == 0) return;
    switch (s_phase) {
    case 0:
        if (*(float *)&s_max_time <= *(float *)&s_curr_time) {
            s_curr_time = 0;
            s_phase = s_phase + 1;
            *(float *)&s_max_time = 1.0f;
            return;
        }
        for (p = &MdlMng[160]; p != &MdlMng[219]; p++) {
            found = 0;
            if (p->TeamNo == 1) continue;
            if (p->bUse == 0) continue;
            my = ((*(struct dw_2014805_fields **)(s32)&p->lpMdlData)->MdlType == 0 && *(volatile unsigned char *)&p->TeamNo == 0);
            if (my) res = CheckMyDamage(p, 0); else res = CheckEneDamage(p);
            if (res == 0) continue;
            for (i = 0; i < 3; i++) {
                if ((struct dw_2017412_fields *)s_apHitChar[i] == p) { found = 1; break; }
            }
            if (found) continue;
            if (4.0f * (*(float *)&s_curr_time / *(float *)&s_max_time) < Math_GetDist((float *)s_pos, p->Pos)) continue;
            if (s_dmg_id != 0) {
                sceVu0CopyVector(prm.DmgPos, s_pos);
                prm.lpTarget = p;
                prm.lpMasterPrm = GetEneParam(s_dmg_id, 1);
                prm.TeamNo = 1;
                prm.AttackNo = 0;
                prm.PauseTime = 0;
                prm.bFinish = 0;
                prm.PowerScl = 1.0f;
                my = ((*(struct dw_2014805_fields **)(s32)&p->lpMdlData)->MdlType == 0 && p->TeamNo == 0);
                if (my) {
                    if (CheckP030Counter(&prm, 0) == 0) SetMyDamageProc(&prm);
                } else {
                    SetEneDamageProc(&prm);
                }
            }
            SFX_Create_OnAng(0x1ca, p->Pos, p->Ang);
            for (i = 0; i < 3; i++) {
                if (s_apHitChar[i] == 0) { s_apHitChar[i] = (u32)p; break; }
            }
        }
        break;
    case 1:
        if (*(float *)&s_max_time <= *(float *)&s_curr_time) {
            s_bAct = 0;
            return;
        }
        break;
    }
    *(float *)&s_curr_time = *(float *)&s_curr_time + dt;
}







static u32 s_aIdx[0x2] = {
    0x10000, 0x30002
};
static u16 s_fvf = 0xb;

/* SfxDomanString_Draw @ 0x1BF550 */

extern void sceVu0CopyMatrix(void *, void *);
static void _SetPlateVert(void *a0 /* r4 */);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0UnitMatrix(void *);
extern void sceVu0InversMatrix(void *, void *);
extern void * GetTexMngByName(void *, char *);
extern int sprintf(char *, const char *, ...);
extern char * strcpy(char *, const char *);
extern void SfxDbg_SetDebugMsg(unsigned char, char *, char *, unsigned int);
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_SetTexWrapMode(unsigned short);
extern void SfxDraw_UseST(signed int);
extern unsigned int * MakeCircleTexture(unsigned int *, unsigned char *, float);
extern void SfxDraw_SetTexture_NoLoad(void *);
extern void SfxDraw_DrawIndexedPrimitive3(unsigned short, void *, unsigned short *, unsigned short);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern u32 MRX1[];
static const u32 CENTER[0x4];
extern u32 lpDrawMng;
extern u32 L956[];
extern u32 L958[];
extern u32 L960[];
extern u32 L962[];
extern u32 lpMdlPacketMem;
static u32 s_aIdx[0x2];
static u16 s_fvf;
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


#ifndef PROTO_DW_2030001_FIELDS
#define PROTO_DW_2030001_FIELDS

#endif

#define DMS_V s_stage_mdl
#define DMS_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
void SfxDomanString_Draw(void) {
    float e;
    float d;
    static volatile float test_947;
    static float test1_948 = 0.5f;
    static float size_949 = 0.150000006f;
    int i;
    float aW[4];
    float mPlate[4][4];
    float mLocToScr[4][4];
    float st[4];
    float mPlate2PC[4][4];
    float mInvPC[4][4];
    float mPC[4][4];
    float mScl[4][4];
    float ratio;
    u_long128 sb;
    void *pTex;
    char msg[32];
    u8 szFile[256] __attribute__((aligned(16)));

    if (s_bAct != 0) {
        sceVu0CopyMatrix(mPlate, MRX1);
        sceVu0CopyVector(mPlate[3], CENTER);
        _SetPlateVert(s_stage_mdl);
        dcomp_cop2_9397A3F6B7(mLocToScr, (u8 *)lpDrawMng + 0x2b0, mPlate);
        {
            struct dw_2030001_fields *p;
            for (i = 0, p = (struct dw_2030001_fields *)s_stage_mdl; i < 4; i++) {
                sceVu0ApplyMatrix(p->pos, mLocToScr, p->pos);
                aW[i] = p->pos[3];
                sceVu0ScaleVector(p->pos, p->pos, 1.0f / p->pos[3]);
                p++;
            }
        }
        sceVu0RotMatrixY(mPC, MRX1, DMS_WRAPF(s_azim));
        sceVu0CopyVector(mPC[3], s_pos);
        sceVu0UnitMatrix(mScl);
        mScl[0][0] = size_949;
        mScl[1][1] = size_949;
        mScl[2][2] = size_949;
        dcomp_cop2_9397A3F6B7(mPC, mPC, mScl);
        sceVu0InversMatrix(mInvPC, mPC);
        dcomp_cop2_9397A3F6B7(mPlate2PC, mInvPC, mPlate);
        {
            float v[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            e = test_947;
            d = 4.55f + e;
            v[2] = d;
            v[0] = -d;
            sceVu0ApplyMatrix(st, mPlate2PC, v);
            s_stage_mdl[0].stq[0] = st[0] + test1_948;
            s_stage_mdl[0].stq[1] = st[2] + test1_948;
        }
        {
            float v[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            d = 4.55f + test_947;
            v[0] = d;
            v[2] = d;
            sceVu0ApplyMatrix(st, mPlate2PC, v);
            s_stage_mdl[1].stq[0] = st[0] + test1_948;
            s_stage_mdl[1].stq[1] = st[2] + test1_948;
        }
        {
            float v[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            d = 4.55f + test_947;
            v[0] = -d;
            v[2] = -d;
            sceVu0ApplyMatrix(st, mPlate2PC, v);
            s_stage_mdl[2].stq[0] = st[0] + test1_948;
            s_stage_mdl[2].stq[1] = st[2] + test1_948;
        }
        {
            float v[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            e = test_947;
            d = 4.55f + e;
            v[0] = d;
            v[2] = -d;
            sceVu0ApplyMatrix(st, mPlate2PC, v);
            s_stage_mdl[3].stq[0] = st[0] + test1_948;
            s_stage_mdl[3].stq[1] = st[2] + test1_948;
        }
        for (i = 0; i < 4; i++) {
            s_stage_mdl[i].stq[0] /= aW[i];
            s_stage_mdl[i].stq[1] /= aW[i];
            s_stage_mdl[i].stq[2] = 1.0f / aW[i];
        }
        {
        float cu = *(float *)&s_curr_time; float mx = *(float *)&s_max_time;
        for (i = 0; i < 4; i++) {
            switch (s_phase) {
            case 0:
                s_stage_mdl[i].rgba = 0x80808080;
                break;
            case 1:
                if (mx <= cu) {
                    s_stage_mdl[i].rgba = 0x80808000;
                } else {
                    s_stage_mdl[i].rgba = (u32)(128.0f - 128.0f * (cu / mx)) + 0x80808000;
                }
                break;
            }
        }
        }
        pTex = GetTexMngByName(0, "ito.tm2");
        if (pTex == 0) {
            sprintf(msg, "%s not found", "ito.tm2");
            strcpy((char *)szFile, "SfxDomanString.c");
            SfxDbg_SetDebugMsg(0, msg, (char *)szFile, 0x15e);
        } else {
            switch (s_phase) {
            case 0:
                ratio = *(float *)&s_curr_time / *(float *)&s_max_time;
                break;
            case 1:
                ratio = 1.0f;
                break;
            }
            sb = SfxDraw_GetRenderStateBlock();
            SfxDraw_SetPrimitiveType(4);
            SfxDraw_SetBlendType(1);
            SfxDraw_SetTexWrapMode(1);
            SfxDraw_UseST(1);
            lpMdlPacketMem = (u32)MakeCircleTexture((unsigned int *)lpMdlPacketMem, (unsigned char *)"ito.tm2", ratio);
            SfxDraw_SetTexture_NoLoad(pTex);
            SfxDraw_DrawIndexedPrimitive3(s_fvf, s_stage_mdl, (unsigned short *)s_aIdx, 4);
            SfxDraw_SetRenderStateBlock(sb);
        }
    }
}








/* _SetPlateVert @ 0x1BF480 .. 0x1BF54C (0xcc bytes, frame 0x60) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1004 -> 0x248590
 *   literal: @1006 -> 0x2485a0
 *   literal: @1008 -> 0x2485b0
 *   literal: @1010 -> 0x2485c0
 *   stack: address of the slot at 0x50 escapes at 0x1bf4a4
 *   stack: address of the slot at 0x40 escapes at 0x1bf4c0
 *   stack: address of the slot at 0x30 escapes at 0x1bf4dc
 *   stack: address of the slot at 0x20 escapes at 0x1bf4f8
 *   literal: @1010 initializes the 16-byte local at 0x20
 *   literal: @1008 initializes the 16-byte local at 0x30
 *   literal: @1006 initializes the 16-byte local at 0x40
 *   literal: @1004 initializes the 16-byte local at 0x50
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void _SetPlateVert(void *a0 /* r4 */) {
    u8 *s0;
    u8 *v0;

    v0 = (u8 *)0x248590;
    s0 = (u8 *)a0;
    a0 = (void *)(s0 + 0x10);
    {
        struct stackFrame_50 { u8 b[16]; } stackFrame_50 __attribute__((aligned(16))) = {{0x9a,
            0x99, 0x91, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x91, 0x40, 0x00, 0x00, 0x80,
            0x3f}};
        sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_50));
        v0 = (u8 *)0x2485a0;
        a0 = (void *)(s0 + 0x30);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0x9a,
                0x99, 0x91, 0x40, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x91, 0x40, 0x00, 0x00, 0x80,
                0x3f}};
            sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_40));
            v0 = (u8 *)0x2485b0;
            a0 = (void *)(s0 + 0x50);
            {
                struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) =
                    {{0x9a, 0x99, 0x91, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x91, 0xc0, 0x00,
                    0x00, 0x80, 0x3f}};
                sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_30));
                v0 = (u8 *)0x2485c0;
                a0 = (void *)(s0 + 0x70);
                {
                    struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) =
                        {{0x9a, 0x99, 0x91, 0x40, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x91, 0xc0,
                        0x00, 0x00, 0x80, 0x3f}};
                    sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_20));
                    a0 = (void *)-0x7f7f7f80;
                    *(u32 *)(s0 + 0xc) = -0x7f7f7f80;
                    *(u32 *)(s0 + 0x2c) = -0x7f7f7f80;
                    *(u32 *)(s0 + 0x4c) = -0x7f7f7f80;
                    *(u32 *)(s0 + 0x6c) = -0x7f7f7f80;
                    *(u32 *)s0 = 0;
                    *(u32 *)(s0 + 4) = 0;
                    *(u32 *)(s0 + 0x20) = 0x3f800000;
                    *(u32 *)(s0 + 0x24) = 0;
                    *(u32 *)(s0 + 0x40) = 0;
                    *(u32 *)(s0 + 0x44) = 0x3f800000;
                    *(u32 *)(s0 + 0x60) = 0x3f800000;
                    *(u32 *)(s0 + 0x64) = 0x3f800000;
                    return;
                }
            }
        }
    }
}
static struct dw_2030001_fields s_stage_mdl[4];
static u32 s_pos[0x4];
static u32 s_apHitChar[0x3];
static const u32 CENTER[0x4] = {
    0xc34301cb, 0xbf800000, 0xc362feb8, 0x3f800000
};
static f32 s_azim;
static u16 s_dmg_id;
static u32 s_max_time;
static u32 s_curr_time;
static u32 s_bAct;
static s32 s_phase;
