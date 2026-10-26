#include "common.h"

/* SetE035Dead @ 0x1FF850 .. 0x1FF880 (0x30 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x1ff85c
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetMyCrouchDisable(unsigned char);

/* E035ActAttack @ 0x1FF880 .. 0x1FFB10 (0x290 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @860 -> 0x24f260
 *   literal: @868 -> 0x24f270
 *   fpu: mtc1 reinterprets v0 at 0x1ff8cc
 *   fpu: mtc1 reinterprets v1 at 0x1ff8e4
 *   fpu: float literal 0x41200000 at 0x1ff8fc
 *   fpu: float literal 0x42100000 at 0x1ff91c
 *   stack: address of the slot at 0x100 escapes at 0x1ff948
 *   fpu: float literal 0x40490fdb at 0x1ff960
 *   fpu: mov.s at 0x1ff978 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1ff974
 *   stack: address of the slot at 0xf0 escapes at 0x1ff980
 *   stack: address of the slot at 0x110 escapes at 0x1ff990
 *   stack: address of the slot at 0xc0 escapes at 0x1ff990
 *   stack: address of the slot at 0x110 escapes at 0x1ff990
 *   stack: address of the slot at 0x110 escapes at 0x1ff9a8
 *   stack: address of the slot at 0xe0 escapes at 0x1ff9a8
 *   delay: lui at 0x1ff9bc writes a register its branch at 0x1ff9b8 reads
 *   fpu: float literal 0x420c0000 at 0x1ff9c0
 *   stack: address of the slot at 0xa0 escapes at 0x1ff9ec
 *   fpu: float literal 0x40490fdb at 0x1ffa04
 *   fpu: mov.s at 0x1ffa1c is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x1ffa18
 *   stack: address of the slot at 0x90 escapes at 0x1ffa24
 *   stack: address of the slot at 0xb0 escapes at 0x1ffa34
 *   stack: address of the slot at 0x60 escapes at 0x1ffa34
 *   stack: address of the slot at 0xb0 escapes at 0x1ffa34
 *   stack: address of the slot at 0xb0 escapes at 0x1ffa4c
 *   stack: address of the slot at 0x80 escapes at 0x1ffa4c
 *   fpu: float literal 0x3c8ef34d at 0x1ffad8
 *   literal: @868 initializes the 16-byte local at 0xb0
 *   literal: @860 initializes the 16-byte local at 0x110
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern void sceVu0CopyVector(void *, void *);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern signed int SFX_Create_OnDir_Dmg(unsigned short, float *, float *, unsigned char, unsigned
    char);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetEneAttackOff(void *, void *);
extern float Math_GotoAngle(float, float, float);
extern u32 L860[];
extern u32 L868[];

struct dw_2554251_fields;
struct dw_2559070_fields;
struct dw_2566808_fields;
#ifndef PROTO_DW_2565090_FIELDS
#define PROTO_DW_2565090_FIELDS
struct dw_2565090_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2563870_FIELDS
#define PROTO_DW_2563870_FIELDS
struct dw_2563870_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2563548_FIELDS
#define PROTO_DW_2563548_FIELDS
struct dw_2563548_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2554251_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2554251_FIELDS
#define PROTO_DW_2554251_FIELDS
struct dw_2554251_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2566808_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2554251_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2565090_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2563870_fields flags; unsigned char _pad1[3]; struct dw_2563548_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2568482_FIELDS
#define PROTO_DW_2568482_FIELDS
struct dw_2568482_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_2558835_FIELDS
#define PROTO_DW_2558835_FIELDS
struct dw_2558835_fields { struct dw_2559070_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_2556964_FIELDS
#define PROTO_DW_2556964_FIELDS
struct dw_2556964_fields { struct dw_2568482_fields func; struct dw_2558835_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_2554251_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_2554251_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif
#ifndef PROTO_DW_2568208_FIELDS
#define PROTO_DW_2568208_FIELDS
struct dw_2568208_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_2566808_FIELDS
#define PROTO_DW_2566808_FIELDS
struct dw_2566808_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_2568208_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892 = (int)&(((struct dw_2554251_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE = (int)&(((struct dw_2554251_fields *)0)->AttackNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_ANGY_3F32A39D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_ANGY_3F32A39D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_ANGY_3F32A39D = (int)&(((struct dw_2554251_fields *)0)->Target.angY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_LPMDL_C09C4BD8_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_LPMDL_C09C4BD8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_LPMDL_C09C4BD8 = (int)&(((struct dw_2554251_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPANIMCTRL_BAFE4810_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPANIMCTRL_BAFE4810_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPANIMCTRL_BAFE4810 = (int)&(((struct dw_2554251_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPMDLDATA_FECDDE42_DEFINED
#define DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPMDLDATA_FECDDE42_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPMDLDATA_FECDDE42 = (int)&(((struct dw_2554251_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2556964_FIELDS_ATTACKOFF_E22A207D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2556964_FIELDS_ATTACKOFF_E22A207D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2556964_FIELDS_ATTACKOFF_E22A207D = (int)&(((struct dw_2556964_fields *)0)->attackOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2556964_FIELDS_FUNC_SETACTFUNC_0__CE3AEF02_DEFINED
#define DCOMP_OFF_STRUCT_DW_2556964_FIELDS_FUNC_SETACTFUNC_0__CE3AEF02_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2556964_FIELDS_FUNC_SETACTFUNC_0__CE3AEF02 = (int)&(((struct dw_2556964_fields *)0)->func.SetActFunc[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2566808_FIELDS_LPPRM_232FF934_DEFINED
#define DCOMP_OFF_STRUCT_DW_2566808_FIELDS_LPPRM_232FF934_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2566808_FIELDS_LPPRM_232FF934 = (int)&(((struct dw_2566808_fields *)0)->lpPrm) - 0 };
#endif
struct E035V4 { float x, y, z, w; };

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E035ActInit(s32 a0 , u32 *a1 );
static void E035ActAttack(void *a0 , void *a1 );
static void SetE035Dead(void *a0 , void *a1 , unsigned short a2 );



/* E035ActInit @ 0x1FFB10 .. 0x1FFB2C (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E035ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E035ActAttack;
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)E035ActAttack;
    v1 = (u8 *)SetE035Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetE035Dead;
    return;
}
static void E035ActAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 t0;
    u8 *s1;
    u8 *s0;
    u8 a3;
    float f14;
    float f12;
    float f20;
    float f1;
    float f0;
    u32 v1;
    u32 v0;
    void *a1_2;

    s3 = (u8 *)a0;
    v0 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPMDLDATA_FECDDE42);
    s1 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_LPANIMCTRL_BAFE4810);
    s0 = (u8 *)*(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_2566808_FIELDS_LPPRM_232FF934);
    a0 = (void *)*(u8 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE);
    s2 = (u8 *)a1;
    f1 = (float)(u32)*(u16 *)(((u32)(s32)((u8 *)(u32)((u32)((s32)((u32)((u32)(a0)) * (u32)(5))) <<
        3) + (u32)(s0)) + 0xaa));
    v0 = (u8)a0;
    f20 = (f1 / 1e+01f);
    if (v0 == 0) {
        v0 = CheckAnimNumFrame((void *)s1, 36.0f);
        if (v0 != 0) {
            v0 = (u32)L860;
            a1_2 = (void *)(s3 + 0x30);
            {
                struct stackFrame_110 { u8 b[16]; } stackFrame_110 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00,
                    0x00, 0x80, 0x3f}};
                float ang[4] __attribute__((aligned(16)));
                float mEne[4][4] __attribute__((aligned(16)));
                v1 = (u32)((u8 *)&stackFrame_110);
                sceVu0CopyVector((void *)ang, a1_2);
                *(float *)((u8 *)ang + 4) = *(float *)((u8 *)ang + 4) + 3.1415927f;
                SfxCalc_MakeMatrixFromPYR((void *)((u8 *)&mEne[0]), ang[0], ang[1], ang[2]);
                sceVu0CopyVector((void *)((u8 *)&mEne[0] + 0x30), (void *)(u8 *)(s3 + 0x20));
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_110), (void *)(u8 *)((u8 *)&mEne[0]),
                    (void *)((u8 *)&stackFrame_110));
                a3 = *(u8 *)s0;
                t0 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE);
                SFX_Create_OnDir_Dmg(0x1d6, (float *)(u8 *)((u8 *)&stackFrame_110), (float *)((u8
                    *)&mEne[0] + 0x20), a3, t0);
            }
        }
    }
    v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE);
    v0 = 1;
    if (v1 == v0) {
        v0 = CheckAnimNumFrame((void *)s1, 35.0f);
        if (v0 != 0) {
            v0 = (u32)L868;
            a1_2 = (void *)(s3 + 0x30);
            {
                struct stackFrame_B0 { u8 b[16]; } stackFrame_B0 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00,
                    0x00, 0x80, 0x3f}};
                float stackFrame_A0[4] __attribute__((aligned(16)));
                float stackFrame_60[4][4] __attribute__((aligned(16)));
                v1 = (u32)((u8 *)&stackFrame_B0);
                sceVu0CopyVector((void *)stackFrame_A0, a1_2);
                *(float *)((u8 *)stackFrame_A0 + 4) = *(float *)((u8 *)stackFrame_A0 + 4) + 3.1415927f;
                SfxCalc_MakeMatrixFromPYR((void *)((u8 *)&stackFrame_60[0]), stackFrame_A0[0], stackFrame_A0[1], stackFrame_A0[2]);
                sceVu0CopyVector((void *)((u8 *)&stackFrame_60[0] + 0x30), (void *)(u8 *)(s3 +
                    0x20));
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_B0), (void *)(u8 *)((u8
                    *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_B0));
                a3 = *(u8 *)s0;
                t0 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE);
                SFX_Create_OnDir_Dmg(0x1d8, (float *)(u8 *)((u8 *)&stackFrame_B0), (float *)((u8
                    *)&stackFrame_60[0] + 0x20), a3, t0);
            }
        }
    }
    v0 = CheckAnimEndFrame((void *)s1);
    if (v0 != 0) {
        v1 = *(u8 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ATTACKNO_5E5DB5FE);
        v0 = *(u16 *)(((u32)(s32)((u8 *)(u32)(v1 * 0x28) + (u32)(s0)) + 0xb2));
        *(u32 *)(s2 + DCOMP_OFF_STRUCT_DW_2556964_FIELDS_ATTACKOFF_E22A207D) = v0;
        v0 = *(s32 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_LPMDL_C09C4BD8);
        if (v0 != 0 && (u32)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2556964_FIELDS_ATTACKOFF_E22A207D) !=
            0) {
            SetEneAttackOff((void *)s3, (void *)(u8 *)s2);
        } else {
            v0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_2556964_FIELDS_FUNC_SETACTFUNC_0__CE3AEF02);
            ((void (*)(u32, u32, s32))(s32)v0)((u32)s3, (u32)(u8 *)s2, 2);
        }
        *(f32 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_ANGY_3F32A39D) = *(float *)(s3 +
            DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892);
    }
    f12 = *(float *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892);
    f0 = Math_GotoAngle(f12, *(float *)(s3 +
        DCOMP_OFF_STRUCT_DW_2554251_FIELDS_TARGET_ANGY_3F32A39D), (0.01745f * f20));
    *(f32 *)(s3 + DCOMP_OFF_STRUCT_DW_2554251_FIELDS_ANG_1__CAC64892) = f0;
    return;
}

static void SetE035Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    float f12;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, f12);
    SetMyCrouchDisable(0);
    return;
}
