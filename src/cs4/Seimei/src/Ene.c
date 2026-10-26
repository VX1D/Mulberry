#include "common.h"

/* SetEneNoFloorDead @ 0x15E900 .. 0x15E9D4 (0xd4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x15e98c writes a register its branch at 0x15e988 reads
 */

extern void EneDeadProc(void *, void *);

/* EneDramaEndFunc @ 0x15E9E0 .. 0x15EA58 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EA08
 */

extern u8 MdlMng[];

/* EneClearAllPauseDamage @ 0x15EB60 .. 0x15EBA8 (0x48 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EB78
 *   cfg: kept branch: 0x15eb78 if (..) goto .L0015EB90
 *   return without a value in a non-void function
 */

extern u8 MdlMng[];

/* CheckEneGetItem @ 0x15ECA0 .. 0x15EE74 (0x1d4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x15ed6c
 *   fpu: mov.s at 0x15edac is a float copy
 *   fpu: mov.s at 0x15edb4 is a float copy
 *   fpu: float literal 0x00000000 at 0x15edb8
 *   fpu: mov.s at 0x15edd4 is a float copy
 *   fpu: mov.s at 0x15ede8 is a float copy
 *   fpu: float literal 0x00000000 at 0x15edec
 *   fpu: float literal 0x3f490fdb at 0x15ee0c
 *   cfg: loop body is not one contiguous region: .L0015ED40
 */

extern signed int CheckMyEventStart(void *);
extern signed int CheckMyControlOff(void *);
extern signed int CheckNowFade(signed int);
extern float Math_GetDistXZ(float *, float *);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern signed int ItemMng_GetItemProc(signed int, signed int, signed int, signed int, signed int);
extern u32 lpPadData;
extern u8 GameSt[];

struct dw_588531_fields;
struct dw_602814_fields;
#ifndef PROTO_DW_600687_FIELDS
#define PROTO_DW_600687_FIELDS
struct dw_600687_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_598350_FIELDS
#define PROTO_DW_598350_FIELDS
struct dw_598350_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_597992_FIELDS
#define PROTO_DW_597992_FIELDS
struct dw_597992_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_588531_fields *lpMdl; };
#endif
#ifndef PROTO_DW_588531_FIELDS
#define PROTO_DW_588531_FIELDS
struct dw_588531_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_602814_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_588531_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_600687_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_598350_fields flags; unsigned char _pad1[3]; struct dw_597992_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_599013_FIELDS
#define PROTO_DW_599013_FIELDS
struct dw_599013_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_EXPR_CFEF94067507FB7D
#define DCOMP_EXPR_CFEF94067507FB7D(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (dcomp_arg))
#endif
#define CAE_ABSF(x) (((x) < 0.0f) ? -(x) : (x))
struct PadBitsI { u8 pad:6; u8 f:1; u8 g:1; };


/* EneSetItemId @ 0x15EE80 .. 0x15EF3C (0xbc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EEC0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand();

/* EneCaptureProc @ 0x15EFB0 .. 0x15F0A8 (0xf8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3d4ccccd at 0x15efec
 *   fpu: float literal 0x00000000 at 0x15eff0
 *   delay: addiu at 0x15f030 writes a register its branch at 0x15f02c reads
 *   delay: addiu at 0x15f044 writes a register its branch at 0x15f040 reads
 */

extern int rand(void);
extern void AddSpiritNum(signed int, signed short, unsigned char);

extern void E003ActInit(void *);
extern void E003ThkInit(void *);
extern void E011ActInit(void *);
extern void E011ThkInit(void *);
extern void E016ActInit(void *, void *);
extern void E016ThkInit(void *);
extern void E022ActInit(void *);
extern void E022ThkInit(void *);
extern u8 E023ActInit[];
extern u8 E028ActInit[];
extern void E031ActInit(void *);
extern void E032ActInit(void *);
extern void E032ThkInit(void *);
extern void E033ActInit(void *);
extern void E034ActInit(void *);
extern void E034ThkInit(void *);
extern void E035ActInit(void *);
extern void E035ThkInit(void *);
extern u8 E036ActInit[];
extern u8 E037ActInit[];
extern void E041ActInit(void *);
extern void E042ActInit(void *, void *);
extern void E044ActInit(void *);
extern void P004ActInit(void *);
extern void P004ThkInit(void *, void *);
extern void P006ThkInit(void *);
extern void P007ActInit(void *);
extern void P007ThkInit(void *);
extern void P008ActInit(void *, void *);
extern void P018ActInit(void *);
extern void P018ThkInit(void *);
extern void P019ActInit(void *, void *);
extern void P019ThkInit(void *);
extern void P020ActInit(void *);
extern void P025ActInit(void *);
extern void P025ThkInit(void *);
extern void P027ActInit(void *);
extern void P027ThkInit(void *);
extern void P030ActInit(void *);
extern void P030ThkInit(void *);
extern void P036ActInit(void *);
static u32 EneInitFunc[0xca] = {
    0, 0, 0, 0, 0, 0, (u32)&E003ThkInit, (u32)&E003ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, (u32)&E011ThkInit, (u32)&E011ActInit, 0, 0, 0, 0, 0, 0, 0, 0, (u32)&E016ThkInit,
    (u32)&E016ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (u32)&E022ThkInit, (u32)&E022ActInit, 0,
    (u32)&E023ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, (u32)&E028ActInit, 0, 0, 0, 0, 0,
    (u32)&E031ActInit, (u32)&E032ThkInit, (u32)&E032ActInit, 0, (u32)&E033ActInit,
    (u32)&E034ThkInit, (u32)&E034ActInit, (u32)&E035ThkInit, (u32)&E035ActInit, 0,
    (u32)&E036ActInit, 0, (u32)&E037ActInit, 0, 0, 0, 0, 0, 0, 0, (u32)&E041ActInit, 0,
    (u32)&E042ActInit, 0, 0, 0, (u32)&E044ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, (u32)&P004ThkInit, (u32)&P004ActInit, 0, 0, (u32)&P006ThkInit, 0,
    (u32)&P007ThkInit, (u32)&P007ActInit, 0, (u32)&P008ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, (u32)&P018ThkInit, (u32)&P018ActInit, (u32)&P019ThkInit,
    (u32)&P019ActInit, 0, (u32)&P020ActInit, 0, 0, 0, 0, 0, 0, 0, 0, (u32)&P025ThkInit,
    (u32)&P025ActInit, 0, 0, (u32)&P027ThkInit, (u32)&P027ActInit, 0, 0, 0, 0,
    (u32)&P030ThkInit, (u32)&P030ActInit, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (u32)&P036ActInit
};
u32 EneAuraSfx[0x64] = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0, 0x1f5, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0, 0x1f2, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0x1f2, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0, 0x1f2, 0, 0x1f2, 0, 0x1f2, 0xffffffff, 0xffffffff, 0,
    0x1f2, 0, 0x1f2, 0, 0x1f2, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0, 0x1f2, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
};
#ifndef ENE_DEATH_SCALE_TYPE
#define ENE_DEATH_SCALE_TYPE
typedef struct EneDeathScale { float value[4]; } EneDeathScale __attribute__((aligned(16)));
#endif
static EneDeathScale s_EneDeathScale = {{0.05f, 0.05f, 0.05f, 1.0f}};

/* ApplyEneSave @ 0x15F0B0 .. 0x15F1E8 (0x138 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1513 -> 0x228f10
 *   fpu: float literal 0x00000000 at 0x15f0dc
 *   delay: addiu at 0x15f128 writes a register its branch at 0x15f124 reads
 *   delay: addiu at 0x15f1a0 writes a register its branch at 0x15f19c reads
 *   stack: address of the slot at 0x40 escapes at 0x15f1bc
 *   literal: @1513 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u16
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetHokanFrame(void *, float);
extern void sceVu0CopyVector(void *, void *);

extern u32 EneSaveSt[];
extern u8 GameSt[];


/* GetEneSave @ 0x15F3C0 .. 0x15F470 (0xb0 bytes) */
/*
 * dcomp notes:
 *   delay: lui at 0x15f3d0 writes a register its branch at 0x15f3cc reads
 *   cfg: kept goto: 0x15f3e8 -> .L0015F468
 *   loop body is not one contiguous region: .L0015F428
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern u32 EneSaveSt[];

struct dw_588531 { u8 b[0x1c0]; };
struct dw_595709 { u8 b[3]; u8 pad[0x4d]; };


/* InitEneSave @ 0x15F470 .. 0x15F484 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x15f47c leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void *memset(void *, int, unsigned int);
extern u32 EneSaveSt[];

/* CheckEneStop @ 0x15F4F0 .. 0x15F540 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x15f524 writes a register its branch at 0x15f520 reads
 *   cfg: kept branch: 0x15f4f0 if (..) goto .L0015F508
 *   cfg: kept goto: 0x15f504 -> .L0015F538
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u8 GameSt[];

/* SetEneDrawByMap @ 0x15F540 .. 0x15F620 (0xe0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x15f588 writes a register its branch at 0x15f584 reads
 *   declaration vs inferred signature: return void vs inferred u8
 */

extern unsigned int CheckDrawMapByCamParam(signed int);

#ifndef ENE_DEATH_SCALE_TYPE
#define ENE_DEATH_SCALE_TYPE
 
#endif

extern signed int GetSpiritNum(signed int);
extern unsigned int SetMyEquip(void *, signed int, signed int, signed int, signed int);
extern void FreeMdlMng(void *);
extern void SetHeartRate(void *, signed int, unsigned char);


/* EneAppearProc @ 0x15F750 .. 0x15F854 (0x104 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42700000 at 0x15f77c
 *   fpu: float literal 0x42e60000 at 0x15f790
 *   fpu: float literal 0x425c0000 at 0x15f7ac
 *   fpu: float literal 0x42e80000 at 0x15f804
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckAnimNumFrame(void *, float);

extern float CheckHitMapLineGetNormal(void *, void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0AddVector(void *, void *, void *);
extern float Math_VectorToAngle(float, float);


/* EneSetTarget @ 0x15F9E0 .. 0x15FA64 (0x84 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   a1 takes slot 1 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred float; 2 parameters vs 3 inferred
 *   return value dropped: the function is void
 */

extern float Math_VectorToAngle(float, float);

/* EneSearchTarget @ 0x15FA70 .. 0x1600D0 (0x660 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f4ccccd at 0x15fa84
 *   fpu: mtc1 reinterprets v0 at 0x15fadc
 *   fpu: mtc1 reinterprets v1 at 0x15faf4
 *   fpu: float literal 0x42c80000 at 0x15fb0c
 *   fpu: mtc1 reinterprets v0 at 0x15fb28
 *   fpu: mtc1 reinterprets v1 at 0x15fb40
 *   fpu: float literal 0x42c80000 at 0x15fb58
 *   fpu: mtc1 reinterprets v0 at 0x15fb74
 *   fpu: mtc1 reinterprets v1 at 0x15fb8c
 *   fpu: float literal 0x41200000 at 0x15fba4
 *   fpu: float literal 0x47c35000 at 0x15fbc4
 *   delay: daddu at 0x15fbcc writes a register its branch at 0x15fbc8 reads
 *   delay: daddu at 0x15fbe0 writes a register its branch at 0x15fbdc reads
 *   delay: daddu at 0x15fbf8 writes a register its branch at 0x15fbf4 reads
 *   delay: lui at 0x15fc1c writes a register its branch at 0x15fc18 reads
 *   fpu: float literal 0x3c8ef34d at 0x15fc24
 *   delay: daddu at 0x15fc74 writes a register its branch at 0x15fc70 reads
 *   delay: addiu at 0x15fc8c writes a register its branch at 0x15fc88 reads
 *   delay: addiu at 0x15fca0 writes a register its branch at 0x15fc9c reads
 *   fpu: mov.s at 0x15fd6c is a float copy
 *   fpu: float literal 0x00000000 at 0x15fd78
 *   fpu: mov.s at 0x15fd8c is a float copy
 *   fpu: mov.s at 0x15fdb0 is a float copy
 *   fpu: float literal 0x3f800000 at 0x15fdb8
 *   fpu: float literal 0x47c35000 at 0x15fddc
 *   fpu: mov.s at 0x15fe54 is a float copy
 *   fpu: float literal 0x00000000 at 0x15fe58
 *   fpu: mov.s at 0x15fe74 is a float copy
 *   fpu: mov.s at 0x15fe88 is a float copy
 *   fpu: mov.s at 0x15feb4 is a float copy
 *   fpu: float literal 0x00000000 at 0x15feb8
 *   fpu: mov.s at 0x15fed4 is a float copy
 *   fpu: mov.s at 0x15fee8 is a float copy
 *   fpu: mov.s at 0x15ff18 is a float copy
 *   fpu: float literal 0x3f800000 at 0x15ff20
 *   fpu: mov.s at 0x15ff50 is a float copy
 *   cfg: loop body is not one contiguous region: .L0015FC30
 *   cfg: kept branch: 0x15fc40 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fc5c if (..) goto .L0015FCE8
 *   cfg: kept branch: 0x15fcc8 if (..) goto .L0015FCF8
 *   cfg: kept goto: 0x15fcdc -> .L0015FF68
 *   cfg: kept branch: 0x15fce8 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fcf8 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fd04 if (..) goto .L0015FD38
 *   cfg: kept branch: 0x15fd18 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fd90 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fd9c if (..) goto .L0015FDF8
 *   cfg: kept branch: 0x15fda8 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fde0 if (..) goto .L0015FF38
 *   cfg: kept goto: 0x15fdec -> .L0015FF68
 *   cfg: kept branch: 0x15fdf8 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fe00 if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fe0c if (..) goto .L0015FEA0
 *   cfg: kept branch: 0x15fe1c if (..) goto .L0015FE40
 *   cfg: kept branch: 0x15fe2c if (..) goto .L0015FEF8
 *   cfg: kept branch: 0x15fe40 if (..) goto .L0015FEF8
 *   cfg: kept branch: 0x15fe8c if (..) goto .L0015FEF8
 *   cfg: kept goto: 0x15fe98 -> .L0015FF68
 *   cfg: kept branch: 0x15fea0 if (..) goto .L0015FEF8
 *   cfg: kept branch: 0x15feec if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15fef8 if (..) goto .L0015FF38
 *   cfg: kept branch: 0x15ff0c if (..) goto .L0015FF68
 *   cfg: kept branch: 0x15ff38 if (..) goto .L0015FF68
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern float CheckHitObstructMdl(void *, void *, float);
extern unsigned int CheckMyDash(void *);


struct dw_593585_fields;

#ifndef PROTO_DW_604493_FIELDS
#define PROTO_DW_604493_FIELDS
struct dw_604493_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_592325_FIELDS
#define PROTO_DW_592325_FIELDS
struct dw_592325_fields { struct dw_593585_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_586770_FIELDS
#define PROTO_DW_586770_FIELDS
struct dw_586770_fields { struct dw_604493_fields func; struct dw_592325_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_588531_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_588531_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif
#ifndef PROTO_DW_600687_FIELDS
#define PROTO_DW_600687_FIELDS

#endif
#ifndef PROTO_DW_598350_FIELDS
#define PROTO_DW_598350_FIELDS

#endif
#ifndef PROTO_DW_597992_FIELDS
#define PROTO_DW_597992_FIELDS

#endif
#ifndef PROTO_DW_588531_FIELDS
#define PROTO_DW_588531_FIELDS

#endif
#ifndef PROTO_DW_599013_FIELDS
#define PROTO_DW_599013_FIELDS

#endif
#ifndef PROTO_DW_604255_FIELDS
#define PROTO_DW_604255_FIELDS
struct dw_604255_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_602814_FIELDS
#define PROTO_DW_602814_FIELDS
struct dw_602814_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_604255_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_586770_FIELDS_DISABLESEARCH_E39BB23D_DEFINED
#define DCOMP_OFF_STRUCT_DW_586770_FIELDS_DISABLESEARCH_E39BB23D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_586770_FIELDS_DISABLESEARCH_E39BB23D = (int)&(((struct dw_586770_fields *)0)->DisableSearch) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_HITHIGH_CB9D4A6C_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_HITHIGH_CB9D4A6C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_HITHIGH_CB9D4A6C = (int)&(((struct dw_588531_fields *)0)->HitHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_HP_27E2FA06_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_HP_27E2FA06_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_HP_27E2FA06 = (int)&(((struct dw_588531_fields *)0)->Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_TARGET_LPMDL_42E735BB_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_TARGET_LPMDL_42E735BB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_TARGET_LPMDL_42E735BB = (int)&(((struct dw_588531_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_TEAMNO_A07B9DCD_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_TEAMNO_A07B9DCD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_TEAMNO_A07B9DCD = (int)&(((struct dw_588531_fields *)0)->TeamNo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__HITSIZE_6E2105F9_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__HITSIZE_6E2105F9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__HITSIZE_6E2105F9 = (int)&(((struct dw_588531_fields *)0)[160].HitSize) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_0__F9EAC981_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_0__F9EAC981_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_0__F9EAC981 = (int)&(((struct dw_588531_fields *)0)[160].Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_2__15D0995D_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_2__15D0995D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS__160__POS_2__15D0995D = (int)&(((struct dw_588531_fields *)0)[160].Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_BUSE_94C76DF9_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_BUSE_94C76DF9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_BUSE_94C76DF9 = (int)&(((struct dw_588531_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_588531_FIELDS_LPMDLDATA_A6D56B36_DEFINED
#define DCOMP_OFF_STRUCT_DW_588531_FIELDS_LPMDLDATA_A6D56B36_DEFINED
enum { DCOMP_OFF_STRUCT_DW_588531_FIELDS_LPMDLDATA_A6D56B36 = (int)&(((struct dw_588531_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_599013_FIELDS_ENESEARCHOFF_06B296BF_DEFINED
#define DCOMP_OFF_STRUCT_DW_599013_FIELDS_ENESEARCHOFF_06B296BF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_599013_FIELDS_ENESEARCHOFF_06B296BF = (int)&(((struct dw_599013_fields *)0)->EneSearchOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_602814_FIELDS_LPPRM_9F620AB1_DEFINED
#define DCOMP_OFF_STRUCT_DW_602814_FIELDS_LPPRM_9F620AB1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_602814_FIELDS_LPPRM_9F620AB1 = (int)&(((struct dw_602814_fields *)0)->lpPrm) - 0 };
#endif
#define EST_ABSF(x) (((x) < 0.0f) ? -(x) : (x))
static inline int EstIsDownAnim(struct dw_588531_fields *t) {
    if (t->lpMdlData->MdlType != 1) {
        return 0;
    }
    switch (t->IndexAnim) {
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
        return 1;
    default:
        return 0;
    }
}
struct EneSrchPrm { u8 pad0[0xf]; u8 estMode; u16 estMin; u16 estMax; u16 estAng; u8 pad1[0x1e - 0x16]; u8 estNoObstruct; u8 pad2[0x2e - 0x1f]; u8 estDecoy; u8 pad3[0xb0 - 0x2f]; u8 estFinish; };


/* EnePlay @ 0x1600D0 .. 0x16037C (0x2ac bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1600fc writes a register its branch at 0x1600f8 reads
 *   delay: addiu at 0x160124 writes a register its branch at 0x160120 reads
 *   fpu: float literal 0x3d4ccccd at 0x1602b4
 *   fpu: float literal 0x3dcccccd at 0x160310
 *   v0#10 is the pointer held in s0#1+0x1a0
 */

extern void sceVu0CopyVector(void *, void *);
static void * EneSearchTarget(void *, void *);
extern void EneLifeCutProc(void *);
extern void EneThkPlay(void *, void *);
extern void EneActPlay(void *, void *);
static void EneCaptureProc(void *, void *);
extern void MasterMove(void *);
extern unsigned int Math_GotoVectorXZ(float *, float *, float);
extern unsigned int CheckHitChar(void *);
extern unsigned int CheckHitMapGetMdlMng(void *, void *);
static void SetEneNoFloorDead(void *, void *);
static void SetEneDrawByMap(void *, void *);
extern u32 lpPadData;

/* EnePlayAll @ 0x160380 .. 0x160468 (0xe8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001603E0
 *   cfg: loop body is not one contiguous region: .L00160428
 */

extern signed int Menu_TD_IsPlay(void);
extern signed int KnMsgMng_CheckMsgNone(void);

/* EneAppear @ 0x160470 .. 0x160D64 (0x8f4 bytes, frame 0xc0) */
extern u32 EneCtrlSt[];
extern u32 DmyEnePrm[];
extern unsigned int SetMdlMng(void *, void *);
extern void * GetMapPartsInfo();
extern void * GetEneParam(signed int, unsigned char);
extern void sceVu0ScaleVectorXYZ(void *, void *, float);
extern void EneThkInit();
extern void EneActInit();
extern void PlayMi3(void *);
extern void DssPlay4Init(void *);
extern unsigned short ConvBloodPool_Nml_Reset(unsigned short);
extern signed int SFX_Create_OnDir_Attach2(unsigned short, float *, float *, void *, unsigned
    short, unsigned char, unsigned char, void *);
extern void * GetMovePath(unsigned char, signed int);
extern signed int SFX_Create_OnDir_Attach(unsigned short, float *, float *, void *, unsigned short,
    unsigned char, unsigned char);
extern u32 VW[];
extern u32 VZ[];
extern u32 V0[];

#ifndef PROTO_DW_596457_FIELDS
#define PROTO_DW_596457_FIELDS
struct dw_596457_fields { unsigned int power; unsigned char per; unsigned char clingAt; unsigned char pushAt; unsigned char blowAt; unsigned short ang; unsigned short angCorrect; unsigned short area[2]; unsigned char finish; unsigned char damageID; unsigned short waitTime; unsigned char pullAt; unsigned char pauseAt; unsigned char recover; unsigned char fire; unsigned char perframe; unsigned char disnodamage; unsigned char blastAt; unsigned char unused1[13]; };
#endif
#ifndef PROTO_DW_593999_FIELDS
#define PROTO_DW_593999_FIELDS
struct dw_593999_fields { unsigned short no; unsigned short game_no; unsigned int hp; unsigned char revival; unsigned char clingTarget; unsigned char pushTarget; unsigned char blowTarget; unsigned char wanderType; unsigned char thinkType; unsigned char unionThink; unsigned char searchType; unsigned short searchArea[2]; unsigned short searchAng; unsigned short hitR; unsigned short hitH; unsigned short angMoveCorrect; unsigned short angStayCorrect; unsigned char throughSearch; unsigned char throughMove; unsigned short scale; unsigned char summonAnimType; unsigned char useHeart; unsigned short shadowSize; unsigned char noDamageFlag; unsigned char headId; unsigned short shadowHigh; unsigned short sfxId; unsigned short lifecut; unsigned char decoy; unsigned char breakfollow; unsigned char revival_rate; unsigned char bite_rate; unsigned short revival_time; unsigned short bite_wait_time; unsigned short no_damage_time; unsigned short use_wait; unsigned char item_rate[2]; unsigned int item_id[2]; unsigned char unused1[92]; struct dw_596457_fields Attack[5]; };
#endif
#ifndef PROTO_DW_599013_FIELDS
#define PROTO_DW_599013_FIELDS

#endif

struct dw_591569_fields;
struct dw_593585_fields;

#ifndef PROTO_DW_604493_FIELDS
#define PROTO_DW_604493_FIELDS
struct dw_604493_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_592325_FIELDS
#define PROTO_DW_592325_FIELDS
struct dw_592325_fields { struct dw_593585_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_586770_FIELDS
#define PROTO_DW_586770_FIELDS
struct dw_586770_fields { struct dw_604493_fields func; struct dw_592325_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_588531_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_588531_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif
#ifndef PROTO_DW_595709_FIELDS
#define PROTO_DW_595709_FIELDS
struct dw_595709_fields { unsigned char bUse; unsigned char SceneNo; unsigned char MdlMngIndex; unsigned char ActID; unsigned short AnimID; unsigned short blood_pool_sfx_idx; float Frame; int Hp; float Pos[4]; float Ang[4]; float Scl[4]; short RebirthTimer; unsigned char Rebirth; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char Weak; unsigned char bFired; int ItemId; unsigned char _pad0[4]; };
#endif
#ifndef PROTO_DW_601198_FIELDS
#define PROTO_DW_601198_FIELDS
struct dw_601198_fields { struct dw_588531_fields *pCreater; };
#endif
#ifndef PROTO_DW_591569_FIELDS
#define PROTO_DW_591569_FIELDS
struct dw_591569_fields { float Pos[4]; struct dw_591569_fields *lpParent; struct dw_591569_fields *lpChild; unsigned char _pad0[8]; };
#endif
#ifndef PROTO_DW_591846_FIELDS
#define PROTO_DW_591846_FIELDS
struct dw_591846_fields { unsigned char bUse; unsigned char bLost; unsigned char bLoop; unsigned char Type; int CtrlId; struct dw_591569_fields *lpNowPath; struct dw_591569_fields *lpPrePath; struct dw_591569_fields PathData[16]; unsigned short EndAnimId; unsigned short MoveAnimId; float AngCorrect; int unused1[2]; };
#endif
#ifndef PROTO_DW_604255_FIELDS
#define PROTO_DW_604255_FIELDS
struct dw_604255_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_602814_FIELDS
#define PROTO_DW_602814_FIELDS
struct dw_602814_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_604255_fields DmyPoly[32]; };
#endif
struct MdlSlot { u8 b[0x680]; };
extern struct MdlSlot MdlData[];

static u32 EneCtrlSt[0x2270];
static u32 EneSaveSt[0xa00];
static u32 DmyEnePrm[0x5a];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void EneAppear(int EneId , int EneDataIndex , struct dw_588531_fields *lpEne , float *Pos , float AngY , float *Scl , unsigned char TeamNo , unsigned short AnimId , unsigned char ActFree , struct dw_586770_fields *lpCtrlSt, struct dw_595709_fields *lpEneSave);
void EnePlayAll(void);
void EnePlay(void *a0 );
static void *EneSearchTarget(void *lpEne_, void *lpCtrl_);
void EneSetTarget(void *a0 , void *a1 , float *a2);
void EneCorrectWalkAngle(void *a0 );
void EneAppearProc(void *a0 , void *a1 );
void EneDeadProc(void *a0, void *a1);
static void SetEneDrawByMap(void *a0 , void *a1 );
signed int CheckEneStop(void *a0 );
signed int CheckEneDead(void *a0 );
signed int CheckEneRebirth(void *a0 );
void InitEneSave(void);
void * GetEneSave(unsigned char a0 , struct dw_588531 *a1 );
void SetEneSave(void *object);
static void ApplyEneSave(void *a0 , void *a1 );
static void EneCaptureProc(void *a0 , void *a1 );
signed int CheckEneFlick(void *a0 );
static void EneSetItemId(void *a0 , void *a1 );
void CheckEneGetItem(void);
void EneEraseAllFriend(void);
void EneEraseFriend(void *a0 );
u32 EneClearAllPauseDamage(void);
void EneClearAllPullIn(void);
void EneDramaStartFunc(void);
void EneDramaEndFunc(void);
static void SetEneNoFloorDead(void *a0 , void *a1 );


void EneAppear(int EneId /* r4 */, int EneDataIndex /* r5 */, struct dw_588531_fields *lpEne /* r6 */, float *Pos /* r7 */, float AngY /* f12 */, float *Scl /* r8 */, unsigned char TeamNo /* r9 */, unsigned short AnimId /* r10 */, unsigned char ActFree /* r11 */, struct dw_586770_fields *lpCtrlSt, struct dw_595709_fields *lpEneSave) {
    struct dw_586770_fields *lpCtrl;
    struct dw_593999_fields *lpPrm;
    struct dw_601198_fields add_data;
    unsigned short sfxId;
    struct dw_591846_fields *lpPathMng;
    int SfxHdl;

    if (((struct dw_599013_fields *)GameSt)->EnemyOff == 0) {
        if (TeamNo == 1) {
            if (SetMdlMng(lpEne, &MdlData[EneDataIndex + 4]) == 0) {
                return;
            }
        } else {
            if (SetMdlMng(lpEne, &MdlData[EneDataIndex + 0x14]) == 0) {
                return;
            }
        }
        sceVu0CopyVector(lpEne->Pos, Pos);
        lpEne->Pos[3] = 1.0f;
        sceVu0CopyVector(lpEne->PosB, lpEne->Pos);
        lpEne->Ang[1] = AngY;
        sceVu0CopyVector(lpEne->AngB, lpEne->Ang);
        sceVu0CopyVector(lpEne->Scl, Scl);
        lpCtrl = lpCtrlSt;
        if (lpCtrl != 0) {
            lpCtrl = (struct dw_586770_fields *)(u32)lpCtrl;
        } else {

            lpCtrl = (struct dw_586770_fields *)EneCtrlSt + (lpEne - (struct dw_588531_fields *)(MdlMng + 0x119c0));
        }
        memset(lpCtrl, 0, 0x260);
        lpEne->lpCtrlSt = lpCtrl;
        if ((MdlMng + 0x119c0) <= (u8 *)lpEne) {
            if ((u8 *)lpEne < (MdlMng + 0x16f80)) {
                lpEne->lpParts = GetMapPartsInfo(2, lpEne - (struct dw_588531_fields *)(MdlMng + 0x119c0));
            }
        }

        lpPrm = GetEneParam(EneId, TeamNo);
        if (lpPrm == 0) {
            lpPrm = (struct dw_593999_fields *)DmyEnePrm;
            ((struct dw_593999_fields *)DmyEnePrm)->hitR = 90;
            ((struct dw_593999_fields *)DmyEnePrm)->hitH = 160;
            ((struct dw_593999_fields *)DmyEnePrm)->hp = 10;
            ((struct dw_593999_fields *)DmyEnePrm)->scale = 100;
            ((struct dw_593999_fields *)DmyEnePrm)->shadowSize = 100;
            ((struct dw_593999_fields *)DmyEnePrm)->shadowHigh = 0;
        }
        lpEne->lpMdlData->lpPrm = lpPrm;
        sceVu0ScaleVectorXYZ(lpEne->Scl, lpEne->Scl, (float)lpPrm->scale / 100.0f);
        lpCtrl->SclLimit = lpEne->Scl[0];
        lpEne->HitSize = (float)lpPrm->hitR / 100.0f * lpEne->Scl[0];
        lpEne->HitHigh = (float)lpPrm->hitH / 100.0f * lpEne->Scl[1];
        if (lpPrm->shadowSize == 0) {
            lpPrm->shadowSize = 100;
        }
        lpEne->ShadowSize = (float)lpPrm->shadowSize / 100.0f * lpEne->Scl[0];
        lpEne->ShadowHigh = (float)lpPrm->shadowHigh / 100.0f * lpEne->Scl[0];
        lpEne->Flags |= 0x10;
        lpEne->Target.angY = lpEne->Ang[1];
        lpEne->TeamNoBase = TeamNo;
        lpEne->TeamNo = lpEne->TeamNoBase;
        lpCtrl->MaxHp = lpPrm->hp;
        lpEne->Hp = lpCtrl->MaxHp;
        lpEne->sceneNo = ((struct dw_599013_fields *)GameSt)->sceneNo;
        lpEne->lpHitMap[0] = 0;
        lpEne->lpHitMap[1] = 0;
        if (lpPrm->throughMove) {
            lpEne->Flags |= 0x20;
        }
        lpCtrl->SfxHdl[0] = -1;
        lpCtrl->SfxHdl[1] = -1;
        lpCtrl->SfxHdl[2] = -1;
        lpCtrl->SfxHdl[3] = -1;
        lpCtrl->SfxHdl[4] = -1;
        lpCtrl->SfxHdl[5] = -1;
        lpCtrl->SfxHdl[6] = -1;
        lpCtrl->SfxHdl[7] = -1;
        lpCtrl->SeHdl[0] = 0x51;
        lpCtrl->SeHdl[1] = 0x51;
        lpCtrl->SeHdl[2] = 0x51;
        lpCtrl->SeHdl[3] = 0x51;
        lpCtrl->SeHdl[4] = 0x51;
        lpCtrl->SeHdl[5] = 0x51;
        lpCtrl->SeHdl[6] = 0x51;
        lpCtrl->SeHdl[7] = 0x51;
        EneThkInit(lpEne, lpCtrl);
        EneActInit(lpEne, lpCtrl);
        if (TeamNo == 1) {
            if (*(u32 *)((u8 *)EneInitFunc + EneId * 8) != 0) {
                (*(void (**)(void *, void *))((u8 *)EneInitFunc + EneId * 8))(lpEne, lpCtrl);
            }
            if (*(u32 *)((u8 *)&((u32 *)EneInitFunc)[1] + EneId * 8) != 0) {
                (*(void (**)(void *, void *))((u8 *)&((u32 *)EneInitFunc)[1] + EneId * 8))(lpEne, lpCtrl);
            }
        } else {
            if (*(u32 *)((u8 *)&((u32 *)EneInitFunc)[0x64] + EneId * 8) != 0) {
                (*(void (**)(void *, void *))((u8 *)&((u32 *)EneInitFunc)[0x64] + EneId * 8))(lpEne, lpCtrl);
            }
            if (*(u32 *)((u8 *)&((u32 *)EneInitFunc)[0x65] + EneId * 8) != 0) {
                (*(void (**)(void *, void *))((u8 *)&((u32 *)EneInitFunc)[0x65] + EneId * 8))(lpEne, lpCtrl);
            }
            if (lpCtrl->AppearTypeAlpha != 0) {
                lpEne->Alpha = 0;
            } else {
                lpEne->Scl[2] = 0;
                lpEne->Scl[1] = 0;
                lpEne->Scl[0] = 0;
            }
            lpEne->HitOff = 1;
        }
        if (lpEneSave != 0) {
            ApplyEneSave(lpEne, lpEneSave);
        } else {
            if (AnimId == 0xffff) {
                ChangeAnimParam(lpEne, 10, 0.0f);
                lpCtrl->func.actID = 1;
            } else if (TeamNo == 0) {
                ChangeAnimParam(lpEne, AnimId, 0.0f);
                lpCtrl->func.actID = 5;
            } else {
                if (ChangeAnimParam(lpEne, AnimId, 0.0f) != 0) {
                    switch (AnimId) {
                    case 0:
                    case 2:
                    case 3:
                        lpCtrl->func.actID = 0;
                        break;
                    case 10:
                    case 11:
                        lpCtrl->func.actID = 1;
                        break;
                    default:
                        lpCtrl->func.actID = 5;
                        break;
                    }
                } else {
                    lpCtrl->func.actID = 0;
                }
            }
            if (ActFree) {
                lpCtrl->func.actID = 6;
            }
            sceVu0CopyVector(lpCtrl->InitPos, lpEne->Pos);
        }
        MasterMove(lpEne);
        PlayMi3(lpEne);
        if (lpEne->lpMdlData->lpDss != 0) {
            DssPlay4Init(lpEne);
        }
        if (lpEneSave != 0 && lpEneSave->blood_pool_sfx_idx != 0) {
            add_data.pCreater = lpEne;
            sfxId = ConvBloodPool_Nml_Reset(lpEneSave->blood_pool_sfx_idx);
            SFX_Create_OnDir_Attach2(sfxId, (float *)VW, (float *)VZ, lpEne, 0, lpPrm->no, lpEne->AttackNo, &add_data);
        }
        if (lpEneSave != 0) {
            memset(lpEneSave, 0, 0x50);
        }
        lpEne->HitFlag = CheckHitMapGetMdlMng(lpEne, lpEne->lpHitMap);
        SetEneDrawByMap(lpEne, lpCtrl);
        lpCtrl->Rebirth = lpPrm->revival;
        lpCtrl->PowerScl = 1.0f;
        if (lpEne->lpParts != 0) {
            lpPathMng = GetMovePath(2, **(int **)((u8 *)lpEne->lpParts + 0x38));
            lpEne->lpPathMng = lpPathMng;
            if (lpPathMng != 0) {
                lpPathMng->EndAnimId = 0xffff;
            }
        }
        if (lpEne->TeamNo == 1) {
            switch (((struct dw_599013_fields *)GameSt)->GameLevel) {
            case 1:
                lpCtrl->PowerScl = 1.2f;
                lpCtrl->MaxHp = (int)(1.2f * (float)lpCtrl->MaxHp);
                break;
            case 2:
                lpCtrl->PowerScl = 1.3f;
                lpCtrl->MaxHp = (int)(1.5f * (float)lpCtrl->MaxHp);
                break;
            case 3:
                lpCtrl->PowerScl = 1.5f;
                lpCtrl->MaxHp = (int)(2.0f * (float)lpCtrl->MaxHp);
                break;
            }
            if (lpEneSave == 0) {
                lpEne->Hp = lpCtrl->MaxHp;
            }
        }
        if (lpEne->TeamNo == 1) {
            if (((s32 *)EneAuraSfx)[EneId * 2] != -1) {
                SfxHdl = SFX_Create_OnDir_Attach(*(u16 *)((u8 *)&((u32 *)EneAuraSfx)[1] + EneId * 8), (float *)VW, (float *)V0, lpEne, 0, 0, 0);
                lpCtrl->SfxHdl[((s32 *)EneAuraSfx)[EneId * 2]] = SfxHdl;
            }
        }
    }
}

void EnePlayAll(void) {
    u32 v1;
    u32 v0;
    u8 *s0;

    v1 = GameSt[0xf];
    if (v1 == 0 && GameSt[0x10] == 0) {
        v0 = Menu_TD_IsPlay();
        if (v0 == 0) {
            v0 = KnMsgMng_CheckMsgNone();
            if (v0 != 0) {
                s0 = (u8 *)(MdlMng + 0x119c0);
                v1 = (u32)(u8 *)(MdlMng + 0x17140);
                if ((u32)s0 != v1) {
                    do {
                        v1 = *(u8 *)s0;
                        if (v1 != 0) {
                            EnePlay((void *)(u8 *)s0);
                        }
                        s0 = (u8 *)(s0 + 0x1c0);
                    } while (s0 != (u8 *)(MdlMng + 0x17140));
                }
                s0 = (u8 *)(MdlMng + 0x17140);
                v1 = (u32)(u8 *)(MdlMng + 0x17f40);
                if ((u32)s0 != v1) {
                    do {
                        v1 = *(u8 *)s0;
                        if (v1 != 0) {
                            EnePlay((void *)(u8 *)s0);
                        }
                        s0 = (u8 *)(s0 + 0x1c0);
                    } while (s0 != (u8 *)(MdlMng + 0x17f40));
                }
            }
        }
    }
    return;
}

void EnePlay(void *a0 /* r4 */) {
    u8 *s1;
    u32 v1;
    u8 *s0;
    u32 v0;
    float f1;
    float f0;

    v1 = *(u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    s1 = (u8 *)a0;
    if (v1 != 0) {
        v1 = GameSt[0x10];
        if (v1 != 0) {
            v1 = 1;
        } else {
            a0 = (void *)*(u8 *)(s0 + 0x180);
            v1 = 4;
            if ((u32)a0 != v1 && (u32)*(u8 *)(s1 + 0x190) != (u32)GameSt[9]) {
                v1 = 1;
            } else {
                v1 = 0;
            }
        }
        a0 = (void *)(s1 + 0x70);
        if (v1 == 0) {
            sceVu0CopyVector(a0, (void *)(u8 *)(s1 + 0x20));
            sceVu0CopyVector((void *)(u32)(s32)(s1 + 0x80), (void *)(u8 *)(s1 + 0x30));
            v0 = *(s32 *)(s1 + 0x124);
            *(u32 *)(s1 + 0x124) = v0 + 1;
            v0 = *(s16 *)(s1 + 0x12c);
            if (v0 != 0) {
                *(u16 *)(s1 + 0x12c) = v0 + -1;
            }
            v0 = *(s32 *)(s0 + 0x1e8);
            if (v0 != 0) {
                *(u32 *)(s0 + 0x1e8) = v0 + -1;
            }
            v0 = *(s16 *)(s1 + 0x12e);
            if ((s32)v0 > 0) {
                *(u16 *)(s1 + 0x12e) = v0 + -1;
            }
            v0 = *(s16 *)(s0 + 0x1fc);
            if ((s32)v0 > 0) {
                *(u16 *)(s0 + 0x1fc) = v0 + -1;
            }
            v1 = *(u16 *)(s0 + 0x1fa);
            if (v1 != (u32)0xffff && v1 != 0) {
                *(u16 *)(s0 + 0x1fa) = v1 + -1;
            }
            v1 = GameSt[0xa];
            v0 = (u32)&lpPadData;
            a0 = (void *)s1;
            v0 = (s32)((u8 *)&lpPadData + (u32)(v1 << 2));
            v0 = *(s32 *)v0;
            *(u32 *)(s0 + 0x1a0) = v0;
            v0 = *(s32 *)(s0 + 0x1a0);
            v0 = *(u8 *)((v0 + 6));
            *(u8 *)(s0 + 0x1a4) = v0 + -0x80;
            v0 = *(s32 *)(s0 + 0x1a0);
            v0 = *(u8 *)((v0 + 7));
            *(u8 *)(s0 + 0x1a5) = v0 + -0x80;
            v0 = *(s32 *)(s0 + 0x1a0);
            v0 = *(u8 *)((v0 + 4));
            *(u8 *)(s0 + 0x1a6) = v0 + -0x80;
            v0 = *(s32 *)(s0 + 0x1a0);
            v0 = *(u8 *)((v0 + 5));
            *(u8 *)(s0 + 0x1a7) = v0 + -0x80;
            EneSearchTarget(a0, (void *)(u8 *)s0);
            EneLifeCutProc((void *)(u32)s1);
            EneThkPlay((void *)(u32)s1, (void *)(u8 *)s0);
            EneActPlay((void *)(u32)s1, (void *)(u8 *)s0);
            EneCaptureProc((void *)(u32)s1, (void *)(u8 *)s0);
            MasterMove((void *)(u32)s1);
            v1 = *(s32 *)(s0 + 0x240);
            if (v1 != 0) {
                v0 = *(u8 *)v1;
                if (v0 == 0 || (s32)*(s32 *)((v1 + 0x120)) <= 0) {
                    *(u32 *)(s0 + 0x240) = 0;
                } else {
                    v0 = Math_GotoVectorXZ((float *)(u32)(s32)(s1 + 0x20), (float *)(u8 *)(s32)(v1
                        + 0x20), 0.0500000007f);
                    a0 = (void *)(s1 + 0x20);
                    if (v0 != 0) {
                        sceVu0CopyVector(a0, (void *)(u8 *)(s1 + 0x70));
                        sceVu0CopyVector((void *)(u32)(s32)(s1 + 0x30), (void *)(u8 *)(s1 + 0x80));
                    }
                }
            }
            v1 = *(u8 *)(s0 + 0x180);
            v0 = 6;
            a0 = (void *)s1;
            if (v1 != v0) {
                CheckHitChar(a0);
                v0 = *(u8 *)(s1 + 0x131);
                if (v0 == 0) {
                    f1 = *(float *)(s1 + 0x24);
                    v0 = 0x3dcccccd;
                    f0 = 0.100000001f;
                    f0 = (f1 + 0.100000001f);
                    *(f32 *)(s1 + 0x24) = f0;
                }
                v0 = *(u8 *)(s1 + 0x132);
                a0 = (void *)s1;
                if (v0 == 0) {
                    v0 = CheckHitMapGetMdlMng(a0, (void *)(u8 *)(s1 + 0x138));
                    *(u32 *)(s1 + 0x134) = v0;
                }
                SetEneNoFloorDead((void *)(u32)s1, (void *)(u8 *)s0);
            }
            SetEneDrawByMap((void *)(u32)s1, (void *)(u8 *)s0);
            v1 = *(s32 *)(s0 + 0x18c);
            a0 = (void *)s1;
            if (v1 != 0) {
                ((void (*)(u32, s32))(s32)v1)((u32)a0, (s32)(u8 *)s0);
            }
        }
    }
    return;
}
static void *EneSearchTarget(void *lpEne_, void *lpCtrl_) {
    struct dw_588531_fields *lpEne = (struct dw_588531_fields *)lpEne_;
    struct dw_586770_fields *lpCtrl = (struct dw_586770_fields *)lpCtrl_;
    struct dw_588531_fields *lpTarget;
    float mx;
    float xx;
    float angY;
    float zz;
    float distMax;
    float dist;
    float searchMin;
    float searchMax;
    float HitHigh;
    float searchAng;
    struct EneSrchPrm *lpTargetPrm;
    struct EneSrchPrm *lpEnePrm;
    int DecoySearchMode;
    int FinishAttack;
    struct dw_586770_fields *lpTargetCtrl;

    HitHigh = 0.8f * lpEne->HitHigh;
    DecoySearchMode = 0;
    lpEnePrm = (struct EneSrchPrm *)lpEne->lpMdlData->lpPrm;
    FinishAttack = lpEnePrm->estFinish;
    searchMin = (float)lpEnePrm->estMin / 100.0f;
    searchMax = (float)lpEnePrm->estMax / 100.0f;
    searchAng = (float)lpEnePrm->estAng / 10.0f;
    distMax = 100000.0f;
    lpEne->Target.lpMdl = 0;
    if (GameSt[DCOMP_OFF_STRUCT_DW_599013_FIELDS_ENESEARCHOFF_06B296BF] != 0) {
        return 0;
    }
    if (lpCtrl->DisableSearch != 0) {
        return 0;
    }
    if (lpEne->Hp <= 0) {
        return 0;
    }
    for (lpTarget = (struct dw_588531_fields *)(MdlMng + 0x11800); lpTarget != (struct dw_588531_fields *)(MdlMng + 0x17f40); lpTarget++) {
        if (lpEnePrm->estMode == 2) {
            break;
        }
        if (lpTarget->bUse == 0 || lpTarget->TeamNo == lpEne->TeamNo) {
            continue;
        }
        if (FinishAttack != 0) {
            if (EstIsDownAnim(lpTarget) == 0 && lpTarget->Hp <= 0) {
                continue;
            }
        } else {
            if (lpTarget->Hp <= 0) {
                continue;
            }
        }
        if (lpTarget->NoSearched != 0) {
            continue;
        }
        if (lpTarget->lpMdlData->MdlType == 1) {
            lpTargetCtrl = (struct dw_586770_fields *)lpTarget->lpCtrlSt;
            if (lpTargetCtrl->func.actID == 6 && lpTargetCtrl->FreeDamage == 0) {
                continue;
            }
        }
        lpTargetPrm = (struct EneSrchPrm *)lpTarget->lpMdlData->lpPrm;
        xx = lpTarget->Pos[0] - lpEne->Pos[0];
        zz = lpTarget->Pos[2] - lpEne->Pos[2];
        angY = Math_VectorToAngle(-xx, -zz);
        dist = sqrtf(xx * xx + zz * zz) - lpTarget->HitSize;
        if (dist < 0.0f) {
            dist = 0.0f;
        }
        if (dist > searchMax) {
            continue;
        }
        if (lpTargetPrm->estDecoy != 0) {
            if (CheckHitObstructMdl(lpEne, lpTarget, HitHigh) < 1.0f) {
                continue;
            }
            if (DecoySearchMode == 0) {
                DecoySearchMode = 1;
                distMax = 100000.0f;
            }
            if (dist > distMax) {
                continue;
            }
        } else {
            if (DecoySearchMode != 0) {
                continue;
            }
            if (dist > distMax) {
                continue;
            }
            if (lpEne->TeamNo == 1) {
                if (lpTarget->lpMdlData->MdlType != 0 || CheckMyDash(lpTarget) == 0) {
                    if (dist > searchMin) {
                        if (EST_ABSF(Math_GetAngleDist(lpEne->Ang[1], angY)) > 0.01745f * searchAng) {
                            continue;
                        }
                    }
                }
            } else {
                if (dist > searchMin) {
                    if (EST_ABSF(Math_GetAngleDist(lpEne->Ang[1], angY)) > 0.01745f * searchAng) {
                        continue;
                    }
                }
            }
            if (lpEne->MapHitOff == 0 && lpEnePrm->estNoObstruct == 0) {
                if (CheckHitObstructMdl(lpEne, lpTarget, HitHigh) < 1.0f) {
                    continue;
                }
            }
        }
        lpEne->Target.lpMdl = lpTarget;
        lpEne->Target.angY = angY;
        lpEne->Target.distXZ = dist;
        distMax = dist;
        if (lpTarget->lpMdlData->MdlType == 0 && lpEnePrm->estMode == 1) {
            break;
        }
    }
    if (lpEne->Target.lpMdl != 0) {
        if (lpEne->lpPathMng != 0) {
            ((u8 *)lpEne->lpPathMng)[1] = 1;
        }
    }
    if (lpEne->TeamNo == 0 && lpEne->Target.lpMdl == 0) {
        lpEne->Target.lpMdl = 0;
        angY = ((struct dw_588531_fields *)MdlMng)[160].Pos[0];
        zz = lpEne->Pos[0];
        xx = angY - zz;
        dist = ((float *)(void *)lpEne)[10];
        zz = ((struct dw_588531_fields *)MdlMng)[160].Pos[2] - dist;
        angY = Math_VectorToAngle(-xx, -zz);
        dist = sqrtf(xx * xx + zz * zz) - ((struct dw_588531_fields *)MdlMng)[160].HitSize;
        lpEne->Target.lpMdl = (struct dw_588531_fields *)(MdlMng + 0x11800);
        lpEne->Target.angY = angY;
        lpEne->Target.distXZ = dist;
    }
    if (lpEnePrm->estMode == 2) {
        lpEne->Target.lpMdl = 0;
        angY = ((struct dw_588531_fields *)MdlMng)[160].Pos[0];
        zz = lpEne->Pos[0];
        xx = angY - zz;
        dist = ((float *)(void *)lpEne)[10];
        zz = ((struct dw_588531_fields *)MdlMng)[160].Pos[2] - dist;
        angY = Math_VectorToAngle(-xx, -zz);
        dist = sqrtf(xx * xx + zz * zz) - ((struct dw_588531_fields *)MdlMng)[160].HitSize;
        lpEne->Target.lpMdl = (struct dw_588531_fields *)(MdlMng + 0x11800);
        lpEne->Target.angY = angY;
        lpEne->Target.distXZ = dist;
    }
    return lpEne->Target.lpMdl;
}

void EneSetTarget(void *a0 /* r4 */, void *a1 /* r5 */, float *a2) {
    u8 *s1;
    float *s0;
    float f3;
    float f2;
    float f1;
    float f0;
    float f21;
    float f20;
    float f12;
    float f13;

    s1 = (u8 *)a0;
    s0 = a2;
    *(u32 *)(((u8 *)a0 + 0x1b4)) = 0;
    f3 = *(float *)(((u8 *)a2 + 0x20));
    f2 = *(float *)(((u8 *)a0 + 0x20));
    f1 = *(float *)(((u8 *)a2 + 0x28));
    f0 = *(float *)(((u8 *)a0 + 0x28));
    f21 = (f3 - f2);
    f20 = (f1 - f0);
    f12 = (-f21);
    f13 = (-f20);
    f0 = Math_VectorToAngle(f12, f13);
    __asm__ volatile("mula.s %0,%1" : : "f"(f21), "f"(f21) : "memory");
    f2 = ({ float native_result_0; __asm__ volatile("madd.s %0,%1,%2" : "=f"(native_result_0) :
        "f"(f20), "f"(f20) : "memory"); native_result_0; });
    f2 = ({ float native_result_1; __asm__ volatile("sqrt.s %0,%1" : "=f"(native_result_1) :
        "f"(f2) : "memory"); native_result_1; });
    f1 = *(float *)(((u8 *)s0 + 0x110));
    *(u32 *)(((u8 *)s1 + 0x1b4)) = (u32)s0;
    *(f32 *)(((u8 *)s1 + 0x198)) = f0;
    f0 = (f2 - f1);
    *(f32 *)(((u8 *)s1 + 0x19c)) = f0;
    return;
}

void EneCorrectWalkAngle(void *a0 /* r4 */) {
    float f13;
    float f12;
    float f1;
    float f0_2;
    float f0_3;
    float f20;
    float f0_4;
    void *a0_s0;
    s32 v1;
    u8 *a0_bytes;
    float f0;
    s32 v0;
    u32 *s1;
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_40[32] __attribute__((aligned(16)));

    a0_bytes = (u8 *)a0;
    f1 = 1.5f;
    f0 = *(float *)(a0_bytes + 0x110);
    f20 = (1.5f * f0);
    sceVu0CopyVector((void *)((u8 *)&stackFrame_70[0]), (void *)(a0_bytes + 0x20));
    f0 = 0.200000003f;
    ((f32 *)stackFrame_70)[1] = (((float *)stackFrame_70)[1] - 0.200000003f);
    f12 = *(float *)(a0_bytes + 0x198);
    f20 = (-f20);
    f0_3 = sinf(f12);
    *(f32 *)((u8 *)&stackFrame_80[0]) = (f20 * f0_3);
    f12 = *(float *)(a0_bytes + 0x198);
    f0_4 = cosf(f12);
    ((u32 *)stackFrame_80)[3] = 0;
    ((u32 *)stackFrame_80)[1] = 0;
    ((f32 *)stackFrame_80)[2] = (f20 * f0_4);
    f0 = CheckHitMapLineGetNormal((void *)((u8 *)&stackFrame_70[0]), (void *)((u8
        *)&stackFrame_80[0]), (void *)((u8 *)&stackFrame_40[0]));
    a0_s0 = (void *)((s32 *)stackFrame_40)[4];
    v1 = 0x200000;
    v1 = (u32)((u32)(a0_s0)) & 0x200000;
    if ((u32)v1 == 0) {
        v1 = 0x400000;
        v1 = (u32)((u32)(a0_s0)) & 0x400000;
        if ((u32)v1 == 0) {
            goto _L0015F918;
        }
    }
    v1 = 0x3f800000;
    f0 = 1.0f;
    _L0015F918:;
    v1 = (u32)((u32)(a0_s0)) & 1;
    if ((u32)v1 != 0) {
        v1 = 0x3f800000;
        f0 = 1.0f;
    }
    v1 = 0x3f800000;
    f1 = 1.0f;
    f12 = f0;
    if (f0 < 1.0f) {
        sceVu0ScaleVector((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_80[0]),
            f12);
        sceVu0AddVector((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_60[0]), (void
            *)((u8 *)&stackFrame_70[0]));
        v0 = 0x3f800000;
        ((u32 *)stackFrame_60)[3] = 0x3f800000;
        sceVu0AddVector((void *)((u8 *)&stackFrame_70[0]), (void *)((u8 *)&stackFrame_70[0]), (void
            *)((u8 *)&stackFrame_80[0]));
        s1 = (u32 *)((u8 *)&stackFrame_70[0] + 0xc);
        v0 = 0x3f800000;
        *(u32 *)s1 = 0x3f800000;
        sceVu0AddVector((void *)((u8 *)&stackFrame_70[0]), (void *)((u8 *)&stackFrame_40[0]), (void
            *)((u8 *)&stackFrame_60[0]));
        v0 = 0x3f800000;
        ((u32 *)stackFrame_70)[3] = 0x3f800000;
        f12 = (*(float *)((u8 *)&stackFrame_70[0]) - *(float *)(a0_bytes + 0x20));
        f13 = (*(float *)((u8 *)&stackFrame_70[8]) - *(float *)(a0_bytes + 0x28));
        f12 = (-f12);
        f13 = (-f13);
        f0_2 = Math_VectorToAngle(f12, f13);
        *(f32 *)(a0_bytes + 0x198) = f0_2;
    }
    return;
}

void EneAppearProc(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s0
    void *a0_s0; // a0
    float f1;
    float f0;
    u8 v1;
    u32 v0;
    u8 *s1;

    a0_bytes = (u8 *)a0;
    v1 = *(u8 *)(a0_bytes + 0x128);
    a0_s0 = (void *)*(s32 *)(a0_bytes + 0x100);
    s1 = (u8 *)a1;
    if ((u32)v1 == 0) {
        f1 = *(float *)a0_s0;
        f0 = 60.0f;
        v0 = 0x42e60000;
        if (60.0f <= f1) {
            f0 = 115.0f;
            if (f1 <= 115.0f) {
                v0 = 0x425c0000;
                f1 = (*(float *)(s1 + 0x25c) / 55.0f);
                *(f32 *)(a0_bytes + 0x40) = (*(float *)(a0_bytes + 0x40) + f1);
                *(f32 *)(a0_bytes + 0x44) = (*(float *)(a0_bytes + 0x44) + f1);
                *(f32 *)(a0_bytes + 0x48) = (*(float *)(a0_bytes + 0x48) + f1);
                f1 = *(float *)(s1 + 0x25c);
                f0 = *(float *)(a0_bytes + 0x40);
                if (!(f0 <= f1)) {
                    *(f32 *)(a0_bytes + 0x40) = f1;
                    *(f32 *)(a0_bytes + 0x44) = *(float *)(s1 + 0x25c);
                    *(f32 *)(a0_bytes + 0x48) = *(float *)(s1 + 0x25c);
                }
            }
        }
        v0 = CheckAnimNumFrame(a0_s0, 116.0f);
        if (v0 != 0) {
            *(f32 *)(a0_bytes + 0x40) = *(float *)(s1 + 0x25c);
            *(f32 *)(a0_bytes + 0x44) = *(float *)(s1 + 0x25c);
            *(f32 *)(a0_bytes + 0x48) = *(float *)(s1 + 0x25c);
            v1 = *(u8 *)(s1 + 0x1da);
            if ((u32)v1 == 0) {
                *(u8 *)(a0_bytes + 0x130) = 0;
            }
        }
    }
    return;
}
void EneDeadProc(void *a0, void *a1) {
    u8 *model;
    u8 *enemy;
    u8 *data;
    u32 object;
    model = (u8 *)a0;
    enemy = (u8 *)a1;
    object = *(u32 *)((u8 *)a0 + 12);
    data = (u8 *)*(u32 *)(object + 0x4c);
    *((u8 *)a0 + 0x130) = 1;
    *((u8 *)a0 + 0x131) = 1;
    *((u8 *)a0 + 0x132) = 1;
    *((u8 *)a1 + 0x1db) = 1;
    EneSetItemId(a0, a1);
    if (!model[0x128]) {
        if (!(s16)GetSpiritNum(*(u16 *)data)) {
            s32 index = ((s32)model - (s32)(MdlMng + 0x17140)) / 0x1c0;
            SetMyEquip((void *)(MdlMng + 0x11800), index, 0, 0, 0);
        }
        FreeMdlMng(model);
        SetHeartRate((void *)(MdlMng + 0x11800), data[0x23], 8);
    } else {
        if (enemy[0x1f3]) FreeMdlMng(model);
    }
    if (model && enemy[0x1f2]) {
        model[8] = 1;
        {
        EneDeathScale scale = s_EneDeathScale;
        sceVu0CopyVector(model + 0xb0, scale.value);
        }
    }
}

static void SetEneDrawByMap(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s0;
    u8 *a2;
    u32 v1;
    u32 v0;

    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x138));
    s0 = (u8 *)a0;
    if ((u32)(s32)a2 == 0) {
        *(u8 *)(s0 + 3) = 0;
    } else {
        v1 = *(u8 *)(((u8 *)a1 + 0x24a));
        if (v1 != 0) {
            *(u8 *)(s0 + 3) = 0;
        } else {
            a0 = (void *)*(s32 *)(a2 + 0xc);
            v1 = 4;
            a0 = (void *)*(u16 *)(((u8 *)a0 + 0xa));
            switch ((u32)a0) {
            case 3:
                v0 = (u32)MdlMng;
                a0 = (void *)(a2 - (u32)(MdlMng));
                v0 = -0x6db6db6d;
                a0 = (void *)(s32)((s32)a0 / (s32)(0x1c0));
                v0 = CheckDrawMapByCamParam((signed int)a0);
                if (v0 != 0) {
                    *(u8 *)(s0 + 3) = 0;
                    break;
                } else {
                    v1 = 1;
                    *(u8 *)(s0 + 3) = v1;
                    break;
                }
            case 4:
                v1 = *(u8 *)(a2 + 3);
                *(u8 *)(s0 + 3) = v1;
                break;
            default:
                *(u8 *)(s0 + 3) = 0;
            }
        }
    }
    return;
}

signed int CheckEneStop(void *a0 /* r4 */) {
    u32 v0;
    u32 v1;
    s32 branchcond_15f520;

    v0 = *(u8 *)((u8 *)&GameSt + 0x10);
    v1 = *(s32 *)(((u8 *)a0 + 0x148));
    if (v0 == 0) {
        goto _L0015F508;
    }
    v0 = 1;
    goto _L0015F538;
    _L0015F508:;
    v1 = *(u8 *)((v1 + 0x180));
    v0 = 4;
    if (v1 != v0) {
        v1 = *(u8 *)(((u8 *)a0 + 0x190));
        v0 = *(u8 *)((u8 *)&GameSt + 9);
        branchcond_15f520 = v1 == v0;
        v0 = 1;
        if (!branchcond_15f520) {
            return v0;
        }
    }
    v0 = 0;
    _L0015F538:;
    return v0;
}

/* CheckEneDead @ 0x15F4C0 .. 0x15F4E8 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckEneDead(void *a0 /* r4 */) {
    u8 *v1;
    u32 v0;

    v0 = *(u8 *)a0;
    v1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    if (v0 == 0) {
        return 1;
    } else {
        v0 = *(u8 *)(v1 + 0x1db);
        v0 = v0 != 0;
    }
    return v0;
}

/* CheckEneRebirth @ 0x15F490 .. 0x15F4C0 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckEneRebirth(void *a0 /* r4 */) {
    u8 *v1;
    u32 v0;

    v0 = *(u8 *)a0;
    v1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    if (v0 == 0) {
        return 0;
    } else {
        v0 = *(u8 *)(v1 + 0x180);
        v0 = v0 ^ 7;
        v0 = v0 < (u32)1;
    }
    return v0;
}

void InitEneSave(void) {
    memset((u8 *)EneSaveSt, 0, 0x2800);
    return;
}
void * GetEneSave(unsigned char a0 /* r4 */, struct dw_588531 *a1 /* r5 */) {
    struct dw_595709 *lpEneSave;

    if (a1 < (struct dw_588531 *)(MdlMng + 0x119c0) ||
        a1 >= (struct dw_588531 *)(MdlMng + 0x17140)) {
        return 0;
    }
    a1 = (struct dw_588531 *)(s32)((s32)((u8 *)a1 -
        (u8 *)(MdlMng + 0x119c0)) / 0x1c0);
    lpEneSave = (struct dw_595709 *)EneSaveSt;
    do {
        if (lpEneSave->b[0] != 0 && lpEneSave->b[1] == a0 &&
            lpEneSave->b[2] == (u32)a1) {
            return lpEneSave;
        }
        lpEneSave++;
    } while (lpEneSave != (struct dw_595709 *)(EneSaveSt + 0xa00));
    return 0;
}
void SetEneSave(void *object) {
    u8 *obj = (u8 *)object;
    u8 *ctrl;
    u8 *save;
    u8 *cursor = (u8 *)EneSaveSt;
    do {
        if (*cursor == 0) { save = cursor; goto found; }
        cursor += 0x50;
    } while (cursor != (u8 *)(EneSaveSt + 0xa00));
    save = 0;
found:
    if (save != 0) {
        u8 *base = MdlMng + 0x119c0;
        float *model;
        if (obj < base || obj >= MdlMng + 0x17140) return;
        ctrl = (u8 *)*(s32 *)(obj + 0x148);
        model = (float *)*(s32 *)(obj + 0x100);
        if (ctrl[0x248] == 0 && ctrl[0x180] != 6 && ctrl[0x1f3] == 0) {
            s32 index = (obj - base) / 0x1c0;
            save[0] = 1;
            save[1] = GameSt[9];
            save[2] = index;
            save[3] = ctrl[0x180];
            *(u16 *)(save + 4) = *(s16 *)(obj + 0x104);
            *(float *)(save + 8) = *model;
            *(u32 *)(save + 0xc) = *(u32 *)(obj + 0x120);
            sceVu0CopyVector(save + 0x10, obj + 0x20);
            sceVu0CopyVector(save + 0x20, obj + 0x30);
            sceVu0CopyVector(save + 0x30, obj + 0x40);
            save[0x42] = ctrl[0x1d9];
            *(u16 *)(save + 0x40) = *(s16 *)(ctrl + 0x1ec);
            save[0x43] = obj[0x130];
            save[0x44] = obj[0x131];
            save[0x45] = obj[0x132];
            save[0x46] = ctrl[0x1f0];
            save[0x47] = ctrl[0x1f2];
            *(u32 *)(save + 0x48) = *(u32 *)(ctrl + 0x258);
            *(u16 *)(save + 6) = *(u16 *)(obj + 0x1bc);
            if (*(u32 *)(ctrl + 0x1e4) != 0) {
                save[3] = 0; *(u16 *)(save + 4) = 2;
                save[0x43] = 0; save[0x44] = 0; save[0x45] = 0;
                *(u32 *)(ctrl + 0x1e4) = 0;
            } else if (ctrl[0x180] == 2) {
                save[3] = 0; *(u16 *)(save + 4) = 2;
            }
        }
    }
}

static void ApplyEneSave(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    float f12;
    u32 v1;
    u32 v0;
    void *a0_2;
    void *a1_2;

    s1 = (u8 *)a1;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    s2 = (u8 *)a0;
    ChangeAnimParam(a0, (u16)*(u16 *)(((u8 *)a1 + 4)), *(float *)(s1 + 8));
    f12 = 0.0f;
    SetHokanFrame((void *)s2, 0.0f);
    v0 = *(u8 *)(s1 + 3);
    *(u8 *)(s0 + 0x180) = v0;
    v0 = *(s32 *)(s1 + 0xc);
    *(u32 *)(s2 + 0x120) = v0;
    v0 = *(u8 *)(s1 + 0x43);
    *(u8 *)(s2 + 0x130) = v0;
    v0 = *(u8 *)(s1 + 0x44);
    *(u8 *)(s2 + 0x131) = v0;
    v0 = *(u8 *)(s1 + 0x45);
    *(u8 *)(s2 + 0x132) = v0;
    v0 = *(s32 *)(s2 + 0x120);
    if (v0 == 0) {
        v1 = *(u8 *)(s0 + 0x180);
        if (v1 != (u32)7) {
            *(u8 *)(s0 + 0x1db) = 1;
        }
    }
    v0 = *(u8 *)(s1 + 0x42);
    a0_2 = (void *)(s2 + 0x20);
    a1_2 = (void *)(s1 + 0x10);
    *(u8 *)(s0 + 0x1d9) = v0;
    v0 = *(s16 *)(s1 + 0x40);
    *(u16 *)(s0 + 0x1ec) = v0;
    v0 = *(u8 *)(s1 + 0x46);
    *(u8 *)(s0 + 0x1f0) = v0;
    v0 = *(u8 *)(s1 + 0x47);
    *(u8 *)(s0 + 0x1f2) = v0;
    v0 = *(s32 *)(s1 + 0x48);
    *(u32 *)(s0 + 0x258) = v0;
    sceVu0CopyVector(a0_2, a1_2);
    sceVu0CopyVector((void *)(u32)(s32)(s2 + 0x30), (void *)(u32)(s32)(s1 + 0x20));
    sceVu0CopyVector((void *)(u32)(s32)(s2 + 0x40), (void *)(u32)(s32)(s1 + 0x30));
    sceVu0CopyVector((void *)(u32)(s32)(s0 + 0x1b0), (void *)(u32)(s32)(s2 + 0x20));
    a0_2 = (void *)*(u8 *)(s0 + 0x180);
    if ((u32)a0_2 == (u32)4 && (u32)*(u8 *)(s0 + 0x1f2) != 0) {
        v0 = 0x228f10;
        *(u8 *)(s2 + 8) = 1;
        a0_2 = (void *)(s2 + 0xb0);
        {
            struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0xcd,
                0xcc, 0x4c, 0x3d, 0xcd, 0xcc, 0x4c, 0x3d, 0xcd, 0xcc, 0x4c, 0x3d, 0x00, 0x00, 0x80,
                0x3f}};
            a1_2 = (void *)((u8 *)&stackFrame_40);
            sceVu0CopyVector(a0_2, a1_2);
        }
    }
    v1 = *(u16 *)(s1 + 6);
    *(u16 *)(s2 + 0x1bc) = v1;
    return;
}

static void EneCaptureProc(void *a0 /* r4 */, void *a1 /* r5 */) {
    float f1;
    u8 *a1_bytes; // a1
    u32 s0;
    u8 *a0_bytes; // a0
    u32 v1;
    s32 v0;

    a0_bytes = (u8 *)a0;
    a1_bytes = (u8 *)a1;
    v1 = *(u8 *)(a1_bytes + 0x245);
    if (v1 != 0) {
        if ((s32)v1 > (s32)1) {
            v1 = v1 + -1;
            *(u8 *)(a1_bytes + 0x245) = v1;
        } else {
            v1 = 0x3d4ccccd;
            f1 = 0.0500000007f;
            f1 = (*(float *)(a0_bytes + 0x44) - 0.0500000007f);
            *(f32 *)(a0_bytes + 0x44) = f1;
            if ((s32)(f1 < 0.0f)) {
                v1 = *(s32 *)(a0_bytes + 0xc);
                v0 = 1;
                s0 = *(s32 *)((v1 + 0x4c));
                *(f32 *)(a0_bytes + 0x44) = 0.0f;
                *(u8 *)(a1_bytes + 0x245) = 0;
                *(u8 *)(a1_bytes + 0x1f3) = v0;
                EneDeadProc((void *)a0_bytes, (void *)a1_bytes);
                s0 = *(u16 *)s0;
                v0 = 0x25;
                switch (s0) {
                case 15:
                    s0 = 2;
                    break;
                case 23:
                case 28:
                case 37:
                    s0 = 0x24;
                }
                v0 = rand();
                v1 = 3;
                a0_bytes = (u8 *)(s32)s0;
                v0 = v0 % (s32)(3);
                v0 = v0 + 3;
                a1_bytes = (u8 *)(s16)v0;
                AddSpiritNum((signed int)a0_bytes, (signed short)a1_bytes, 1);
            }
        }
    }
    return;
}

/* CheckEneFlick @ 0x15EF40 .. 0x15EFB0 (0x70 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x15ef50 writes a register its branch at 0x15ef4c reads
 *   delay: addiu at 0x15ef6c writes a register its branch at 0x15ef68 reads
 *   delay: addiu at 0x15ef80 writes a register its branch at 0x15ef7c reads
 *   cfg: kept goto: 0x15ef98 -> .L0015EFA8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckEneFlick(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = 1;
    v1 = *(u16 *)((v1 + 0xa));
    if (v1 != v0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    v0 = 0x30;
    switch (v1) {
    case 45:
    case 46:
    case 47:
    case 48:
        v0 = 1;
        return v0;
    }
    v0 = 0;
    return v0;
}

static void EneSetItemId(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s3;
    s32 s2;
    u32 v1;
    u32 *s1;
    u32 *s0;
    u32 v0;

    s3 = (u32 *)a1;
    v1 = *(s32 *)(((u8 *)a1 + 0x258));
    a1 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s1 = (u32 *)*(s32 *)(((u8 *)a1 + 0x4c));
    if (v1 == 0) {
        a0 = (void *)*(u8 *)(((u8 *)a0 + 0x128));
        v1 = 1;
        s2 = 0;
        if ((u32)a0 == v1) {
            s0 = (u32 *)s1;
            do {
                v1 = (s32)s0[0xf];
                if (v1 != 0) {
                    v0 = rand();
                    a0 = (void *)(s32)0x64;
                    v1 = (s32)((u8 *)s1 + s2);
                    if ((s32)((s32)v0 % (s32)(0x64)) <= (s32)(*(u8 *)((v1 + 0x3a)))) {
                        v1 = (u32)s2 << 2;
                        v1 = (s32)((u8 *)v1 + (u32)(s1));
                        v1 = *(s32 *)((v1 + 0x3c));
                        s3[0x96] = v1;
                        return;
                    }
                }
                s2 = (s32)s2 + 1;
                v1 = s2 < (s32)2;
                s0 = (u32 *)(u8 *)(s0 + 1);
            } while (v1 != 0);
            s3[0x96] = -1;
        }
    }
    return;
}
void CheckEneGetItem(void) {
    struct dw_588531_fields *lpMy = (struct dw_588531_fields *)(MdlMng + 0x11800);
    struct dw_588531_fields *lpEne;
    u8 *lpCtrl;
    float AngDist;
    float ang;

    if (((struct PadBitsI *)((u8 *)(&lpPadData)[((struct dw_599013_fields *)GameSt)->padport] + 0x21))->f != 0) {
        if (CheckMyEventStart(lpMy) != 0) {
            if (CheckMyControlOff(lpMy) != 0) {
                if (CheckNowFade(3) == 0) {
                    if (CheckNowFade(6) == 0) {
                        for (lpEne = (struct dw_588531_fields *)(MdlMng + 0x119c0); lpEne != (struct dw_588531_fields *)(MdlMng + 0x17140); lpEne++) {
                            if (lpEne->bUse != 0) {
                                lpCtrl = (u8 *)lpEne->lpCtrlSt;
                                if (*(s32 *)(lpCtrl + 0x258) > 0) {
                                    if (Math_GetDistXZ(lpMy->Pos, lpEne->Pos) <= 1.0f + lpEne->HitSize) {
                                        ang = Math_VectorToAngle(-(lpEne->Pos[0] - lpMy->Pos[0]), -(lpEne->Pos[2] - lpMy->Pos[2]));
                                        AngDist = CAE_ABSF(Math_GetAngleDist(lpMy->Ang[1], ang));
                                        if (CAE_ABSF(AngDist) <= 0.7853982f) {
                                            ItemMng_GetItemProc(*(s32 *)(lpCtrl + 0x258), 0, 0, -1, 1);
                                            *(s32 *)(lpCtrl + 0x258) = -1;
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

/* EneEraseAllFriend @ 0x15EC00 .. 0x15EC98 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EC28
 */

void EneEraseAllFriend(void) {
    u32 a3;
    u8 *s0;
    u8 *a1;
    u32 v1;

    v1 = (u32)(u8 *)(MdlMng + 0x17f40);
    s0 = (u8 *)(MdlMng + 0x17140);
    if ((u32)s0 != v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                a3 = *(s32 *)(s0 + 0x120);
                if ((s32)a3 > 0 && v1 != 0 && (s32)a3 > 0) {
                    a1 = (u8 *)*(s32 *)(s0 + 0x148);
                    *(u32 *)(s0 + 0x1b8) = a3;
                    *(u32 *)(s0 + 0x120) = 0;
                    ((void (*)(u32, s32, s32, s32))(s32)*(s32 *)(a1 + 0x110))((u32)(u8 *)s0,
                        (s32)a1, 7, a3);
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 != (u8 *)(MdlMng + 0x17f40));
    }
    return;
}

/* EneEraseFriend @ 0x15EBB0 .. 0x15EBFC (0x4c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x15ebb8 if (..) goto .L0015EBD0
 */

void EneEraseFriend(void *a0 /* r4 */) {
    u8 *a1;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(u8 *)a0_bytes;
    if (v1 == 0) {
        goto _L0015EBD0;
    }
    v1 = *(s32 *)(a0_bytes + 0x120);
    if ((s32)v1 <= 0) {
        _L0015EBD0:;
        return;
    }
    a1 = (u8 *)*(s32 *)(a0_bytes + 0x148);
    *(u32 *)(a0_bytes + 0x1b8) = v1;
    *(u32 *)(a0_bytes + 0x120) = 0;
    ((void (*)(void *, s32, s32))(s32)*(s32 *)(a1 + 0x110))((void *)a0_bytes, (s32)a1, 7);
    return;
}

u32 EneClearAllPauseDamage(void) {
    u8 *a1;
    u8 *a0;
    u32 v1;

    a1 = (u8 *)MdlMng + 0x119c0;
    a0 = (u8 *)MdlMng + 0x17140;
    if ((u32)(a1) != (u32)(a0)) {
        do {
            v1 = *(u8 *)a1;
            if (v1 == 0) {
                goto _L0015EB90;
            }
            v1 = *(u32 *)(((u8 *)a1 + 0x148));
            *(u16 *)((v1 + 0x1ee)) = 0;
            _L0015EB90:;
            a1 = (u8 *)a1 + 0x1c0;
        } while ((u32)(a1) != (u32)(a0));
    }
    return;
}

/* EneClearAllPullIn @ 0x15EAE0 .. 0x15EB58 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EB08
 */



void EneClearAllPullIn(void) {
    u32 a0;
    u8 *s0;
    u32 v1;

    v1 = (u32)(u8 *)(MdlMng + 0x17140);
    s0 = (u8 *)(MdlMng + 0x119c0);
    if ((u32)s0 != v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                a0 = *(s16 *)(s0 + 0x104);
                if (a0 == (u32)0x22) {
                    EneDeadProc((void *)s0, (void *)*(s32 *)(s0 + 0x148));
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 != (u8 *)(MdlMng + 0x17140));
    }
    return;
}

/* EneDramaStartFunc @ 0x15EA60 .. 0x15EAD8 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0015EA88
 */



void EneDramaStartFunc(void) {
    u8 *a1;
    u8 *s0;
    u32 v1;

    v1 = (u32)(u8 *)(MdlMng + 0x17f40);
    s0 = (u8 *)(MdlMng + 0x119c0);
    if ((u32)s0 != v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                a1 = (u8 *)*(s32 *)(s0 + 0x148);
                v1 = *(s32 *)(a1 + 0x190);
                if (v1 != 0) {
                    ((void (*)(u32, s32))(s32)v1)((u32)(u8 *)s0, (s32)a1);
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 != (u8 *)(MdlMng + 0x17f40));
    }
    return;
}

void EneDramaEndFunc(void) {
    u8 *a1;
    u8 *s0;
    u32 v1;

    v1 = (u32)(u8 *)(MdlMng + 0x17f40);
    s0 = (u8 *)(MdlMng + 0x119c0);
    if ((u32)s0 != v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                a1 = (u8 *)*(s32 *)(s0 + 0x148);
                v1 = *(s32 *)(a1 + 0x194);
                if (v1 != 0) {
                    ((void (*)(u32, s32))(s32)v1)((u32)(u8 *)s0, (s32)a1);
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 != (u8 *)(MdlMng + 0x17f40));
    }
    return;
}

static void SetEneNoFloorDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 v1;
    s32 v0;

    s1 = (u8 *)a0;
    v1 = *(u8 *)(((u8 *)a0 + 0x132));
    s0 = (u8 *)a1;
    if (v1 == 0 && (u32)*(u8 *)(s1 + 0x131) == 0) {
        v1 = *(u8 *)(s0 + 0x24c);
        if (v1 == 0 && (s32)*(s32 *)(s1 + 0x120) > 0) {
            a0 = (void *)*(u8 *)(s0 + 0x180);
            v1 = 4;
            if ((u32)a0 != v1) {
                v1 = *(s32 *)(s1 + 0x134);
                v1 = v1 & 1;
                if (v1 != 0) {
                    *(u8 *)(s0 + 0x24b) = 0;
                } else {
                    v1 = *(u8 *)(s0 + 0x24b);
                    *(u8 *)(s0 + 0x24b) = v1 + 1;
                }
                v1 = *(u8 *)(s0 + 0x24b);
                if ((u32)((s32)v1 < (s32)0x3c) == 0) {
                    v0 = 1;
                    *(u32 *)(s0 + 0x258) = -1;
                    a0 = (void *)s1;
                    *(u8 *)(s0 + 0x248) = v0;
                    a1 = (void *)s0;
                    *(u8 *)(s0 + 0x1f3) = v0;
                    ((void (*)(u32, u32, s32))(s32)*(s32 *)(s0 + 0x110))((u32)a0, (u32)a1, 0x28);
                    EneDeadProc((void *)(u32)s1, (void *)(u8 *)s0);
                }
            }
        }
    }
    return;
}
