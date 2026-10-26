#include "common.h"

/* SetEneAttackOff @ 0x162F30 .. 0x163020 (0xf0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x162f74 if (..) goto .L00162FA8
 *   cfg: kept branch: 0x162f80 if (..) goto .L00162FA8
 *   cfg: kept branch: 0x162fb8 if (..) goto .L00162FF0
 *   cfg: kept branch: 0x162fc4 if (..) goto .L00162FF0
 */

extern int rand(void);
extern unsigned int CheckAnimParam(void *, signed int);

/* EneSearchAttackRange @ 0x163020 .. 0x1632F4 (0x2d4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x163064
 *   fpu: mtc1 reinterprets v1 at 0x16307c
 *   fpu: float literal 0x42c80000 at 0x163094
 *   fpu: mtc1 reinterprets v0 at 0x1630b0
 *   fpu: mtc1 reinterprets v1 at 0x1630c8
 *   fpu: float literal 0x42c80000 at 0x1630e0
 *   fpu: mtc1 reinterprets v0 at 0x1630fc
 *   fpu: mtc1 reinterprets v1 at 0x163114
 *   fpu: float literal 0x41200000 at 0x16312c
 *   delay: daddu at 0x163158 writes a register its branch at 0x163154 reads
 *   delay: daddu at 0x163178 writes a register its branch at 0x163174 reads
 *   delay: daddu at 0x1631a8 writes a register its branch at 0x1631a4 reads
 *   fpu: float literal 0x00000000 at 0x163218
 *   fpu: float literal 0x3c8ef34d at 0x163254
 *   fpu: float literal 0x3f4ccccd at 0x163270
 *   fpu: float literal 0x3f800000 at 0x1632a0
 *   cfg: kept goto: 0x163158 -> .L001632D0
 *   cfg: kept goto: 0x1631a8 -> .L001632D0
 *   cfg: kept goto: 0x1631e8 -> .L001632D0
 *   a1 takes slot 1 only because of the ABI order
 *   declaration vs inferred signature: return unsigned int vs inferred u32; 2 parameters vs 3
 *   inferred
 */

extern float Math_GetAngleDist(float, float);
extern float CheckHitObstructLine(void *, float, float);
extern u8 GameSt[];

struct dw_646622_fields;
struct dw_658678_fields;
#ifndef PROTO_DW_656943_FIELDS
#define PROTO_DW_656943_FIELDS
struct dw_656943_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_654542_FIELDS
#define PROTO_DW_654542_FIELDS
struct dw_654542_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_654220_FIELDS
#define PROTO_DW_654220_FIELDS
struct dw_654220_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_646622_fields *lpMdl; };
#endif
#ifndef PROTO_DW_646622_FIELDS
#define PROTO_DW_646622_FIELDS
struct dw_646622_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_658678_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_646622_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_656943_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_654542_fields flags; unsigned char _pad1[3]; struct dw_654220_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_654832_FIELDS
#define PROTO_DW_654832_FIELDS
struct dw_654832_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif
#ifndef PROTO_DW_660140_FIELDS
#define PROTO_DW_660140_FIELDS
struct dw_660140_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_658678_FIELDS
#define PROTO_DW_658678_FIELDS
struct dw_658678_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_660140_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0_DEFINED
#define DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0 = (int)&(((struct dw_646622_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_654832_FIELDS_DIZZYTEST_92557360_DEFINED
#define DCOMP_OFF_STRUCT_DW_654832_FIELDS_DIZZYTEST_92557360_DEFINED
enum { DCOMP_OFF_STRUCT_DW_654832_FIELDS_DIZZYTEST_92557360 = (int)&(((struct dw_654832_fields *)0)->DizzyTest) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC_DEFINED
#define DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC = (int)&(((struct dw_658678_fields *)0)->lpPrm) - 0 };
#endif
struct EneAtkEnt { u8 prob; u8 p1[3]; u16 ang; u16 p2; u16 rmin; u16 rmax; u8 p3[8]; u8 interval; u8 p4; u8 flag; u8 p5[3]; u8 p6[14]; };
struct EneThkPrm { u8 pad0[0x1e]; u8 noObstruct; u8 pad1[0xa4 - 0x1f]; struct EneAtkEnt ent[1]; };


extern float Math_GetAngleDist(float, float);


/* CheckEneAttackState @ 0x163630 .. 0x16377C (0x14c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x163680 writes a register its branch at 0x16367c reads
 *   delay: addiu at 0x16369c writes a register its branch at 0x163698 reads
 *   fpu: float literal 0x00000000 at 0x16371c
 *   cfg: kept branch: 0x163660 if (..) goto .L00163678
 *   cfg: kept goto: 0x163670 -> .L001636C0
 *   cfg: kept branch: 0x1636c0 if (..) goto .L001636D0
 *   cfg: kept goto: 0x1636cc -> .L00163760
 *   cfg: loop body is not one contiguous region: .L001636D8
 *   cfg: kept branch: 0x1636f0 if (..) goto .L00163718
 *   cfg: kept branch: 0x163700 if (..) goto .L00163730
 *   cfg: kept goto: 0x16370c -> .L00163748
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int EneSearchAttackRange();
extern signed int SetEneClingAndPush(void *, void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);

/* CheckEneAttackState @ 0x163630 .. 0x16377C (0x14c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x163680 writes a register its branch at 0x16367c reads
 *   delay: addiu at 0x16369c writes a register its branch at 0x163698 reads
 *   fpu: float literal 0x00000000 at 0x16371c
 *   cfg: kept branch: 0x163660 if (..) goto .L00163678
 *   cfg: kept goto: 0x163670 -> .L001636C0
 *   cfg: kept goto: 0x1636cc -> .L00163760
 *   cfg: loop body is not one contiguous region: .L001636D8
 *   cfg: kept branch: 0x1636f0 if (..) goto .L00163718
 *   cfg: kept branch: 0x163700 if (..) goto .L00163730
 *   cfg: kept goto: 0x16370c -> .L00163748
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */


struct dw_650841_fields;

#ifndef PROTO_DW_660440_FIELDS
#define PROTO_DW_660440_FIELDS
struct dw_660440_fields { void *ThkFunc[32]; void *ActFunc[32]; void *SetActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char freeEnd; unsigned char unused0[1]; void *GetDmgAnimFunc; void *CalcDmgFunc; void *FrameLastFunc; void *DramaStartFunc; void *DramaEndFunc; int unused[2]; };
#endif
#ifndef PROTO_DW_649581_FIELDS
#define PROTO_DW_649581_FIELDS
struct dw_649581_fields { struct dw_650841_fields *lpPad; char L3H; char L3V; char R3H; char R3V; unsigned int unused[2]; };
#endif
#ifndef PROTO_DW_644877_FIELDS
#define PROTO_DW_644877_FIELDS
struct dw_644877_fields { struct dw_660440_fields func; struct dw_649581_fields key; float InitPos[4]; float DstPos[4]; float moveRange; float moveAngle; unsigned char bDash; unsigned char Rebirth; unsigned char bHitOff; unsigned char bDead; unsigned short stayTimer; unsigned short walkTimer; unsigned short approachTimer; unsigned short ClingDmgMyAnim; struct dw_646622_fields *lpCling; int attackOff; short RebirthTimer; unsigned short PauseTime; unsigned char bWeak; unsigned char UseSfxHdlNum; unsigned char bFired; unsigned char bFree; float rollAng; unsigned short lifecut; unsigned short noDamage; short DisableSearch; short GuardFrame; int SfxHdl[8]; int SeHdl[8]; struct dw_646622_fields *lpP019; unsigned char lifecutscl; unsigned char captureLock; unsigned char ClingPos; unsigned char ClingFree; unsigned char NoSave; unsigned char FreeDamage; unsigned char bEraseDisable; unsigned char NoFloorDeadTimer; unsigned char bNoFloorDeadDisable; unsigned char AppearTypeAlpha; unsigned char unused0[2]; float PowerScl; int MaxHp; int ItemId; float SclLimit; };
#endif
#ifndef PROTO_DW_656943_FIELDS
#define PROTO_DW_656943_FIELDS

#endif
#ifndef PROTO_DW_654542_FIELDS
#define PROTO_DW_654542_FIELDS

#endif
#ifndef PROTO_DW_654220_FIELDS
#define PROTO_DW_654220_FIELDS

#endif
#ifndef PROTO_DW_646622_FIELDS
#define PROTO_DW_646622_FIELDS

#endif
#ifndef PROTO_DW_660140_FIELDS
#define PROTO_DW_660140_FIELDS

#endif
#ifndef PROTO_DW_658678_FIELDS
#define PROTO_DW_658678_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_644877_FIELDS_ATTACKOFF_3A1D0C7D_DEFINED
#define DCOMP_OFF_STRUCT_DW_644877_FIELDS_ATTACKOFF_3A1D0C7D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_644877_FIELDS_ATTACKOFF_3A1D0C7D = (int)&(((struct dw_644877_fields *)0)->attackOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_646622_FIELDS_TARGET_LPMDL_B8F61081_DEFINED
#define DCOMP_OFF_STRUCT_DW_646622_FIELDS_TARGET_LPMDL_B8F61081_DEFINED
enum { DCOMP_OFF_STRUCT_DW_646622_FIELDS_TARGET_LPMDL_B8F61081 = (int)&(((struct dw_646622_fields *)0)->Target.lpMdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0_DEFINED
#define DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC_DEFINED
#define DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC_DEFINED

#endif

extern unsigned int CheckAnimEndFrame(void *);
extern signed int UpdateMovePath(void *);

#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif


/* CheckEneStayState @ 0x163E20 .. 0x164188 (0x368 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3e99999a at 0x163ff8
 *   cfg: kept branch: 0x163e8c if (..) goto .L00164168
 *   cfg: kept branch: 0x163e94 if (..) goto .L00164168
 *   cfg: kept goto: 0x163ea0 -> .L00163FC8
 *   cfg: kept branch: 0x163f2c if (..) goto .L00163F60
 *   cfg: kept branch: 0x163f38 if (..) goto .L00163F60
 *   cfg: kept branch: 0x163f70 if (..) goto .L00163FA8
 *   cfg: kept branch: 0x163f7c if (..) goto .L00163FA8
 *   cfg: kept goto: 0x163fc0 -> .L00164170
 *   cfg: kept branch: 0x164038 if (..) goto .L00164168
 *   cfg: kept branch: 0x16404c if (..) goto .L00164168
 *   cfg: kept branch: 0x16405c if (..) goto .L00164168
 *   cfg: kept goto: 0x164084 -> .L00164168
 *   cfg: kept branch: 0x1640dc if (..) goto .L00164168
 *   cfg: kept branch: 0x1640ec if (..) goto .L00164168
 *   cfg: kept branch: 0x16413c if (..) goto .L00164168
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckEneRollState(void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern signed int UpdateMovePath(void *);

/* EneThkRebirth @ 0x1641A0 .. 0x164784 (0x5e4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1641e0 writes a register its branch at 0x1641dc reads
 *   delay: addiu at 0x1641f4 writes a register its branch at 0x1641f0 reads
 *   delay: addiu at 0x164208 writes a register its branch at 0x164204 reads
 *   delay: addiu at 0x16421c writes a register its branch at 0x164218 reads
 *   delay: addiu at 0x164230 writes a register its branch at 0x16422c reads
 *   delay: addiu at 0x164244 writes a register its branch at 0x164240 reads
 *   delay: addiu at 0x164258 writes a register its branch at 0x164254 reads
 *   delay: addiu at 0x16426c writes a register its branch at 0x164268 reads
 *   fpu: float literal 0x00000000 at 0x1642d8
 *   fpu: float literal 0x00000000 at 0x164354
 *   fpu: float literal 0x00000000 at 0x1643b0
 *   fpu: float literal 0x00000000 at 0x16442c
 *   fpu: float literal 0x00000000 at 0x164488
 *   fpu: float literal 0x00000000 at 0x164504
 *   fpu: float literal 0x00000000 at 0x164560
 *   fpu: float literal 0x00000000 at 0x1645dc
 *   fpu: float literal 0x00000000 at 0x164638
 *   fpu: float literal 0x00000000 at 0x164698
 *   fpu: float literal 0x00000000 at 0x1646f8
 *   fpu: float literal 0x00000000 at 0x164758
 *   cfg: kept goto: 0x16429c -> .L001642F8
 *   cfg: kept goto: 0x164374 -> .L001643D0
 *   cfg: kept goto: 0x16444c -> .L001644A8
 *   cfg: kept goto: 0x164524 -> .L00164580
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern float Math_GetDistXZ(float *, float *);
extern u32 MdlMng[];

/* EneThkWalk @ 0x1647C0 .. 0x16480C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckEneAttackState(void *, void *);
extern unsigned int CheckEneWalkState(void *, void *);

/* EneThkStay @ 0x164810 .. 0x16485C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


extern unsigned int CheckEneStayState(void *, void *);

/* EneThkInit @ 0x1648B0 .. 0x164960 (0xb0 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 */

extern void EneThkRebirth(void *, void *);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void EneThkInit(int a0 , void *a1 );
void EneThkPlay(void *a0 , void *a1 );
static void EneThkNone(void);
static void EneThkAppear(void);
static void EneThkFree(void);
static void EneThkStay(void *a0 , void *a1 );
static void EneThkWalk(void *a0 , void *a1 );
static void EneThkAttack(void);
static void EneThkDamage(void);
static void EneThkDead(void);
static void EneThkRebirth(void *a0 , void *a1 );
static void EneThkGuard(void);
unsigned int CheckEneStayState(void *a0 , void *a1 );
unsigned int CheckEneWalkState(void *a0 , void *a1 );
unsigned int CheckEneAttackState(void *a0 , void *a1 );
unsigned int CheckEneRollState(void *a0, void *a1);
unsigned int EneSearchAttackRange(struct dw_646622_fields *lpEne, void *unused, int AttackNo);
void SetEneAttackOff(void *a0 , void *a1 );
unsigned int CheckEneAttackEnable(void *a0 , void *a1 );


void EneThkInit(int a0 /* r4 */, void *a1 /* r5 */) {
    unsigned int i;

    for (i = 0; i < 0x20; i++) ((void (**)())a1)[i] = EneThkNone;
    ((u32 *)a1)[5] = (u32)EneThkAppear;
    ((u32 *)a1)[6] = (u32)EneThkFree;
    ((u32 *)a1)[0] = (u32)EneThkStay;
    ((u32 *)a1)[1] = (u32)EneThkWalk;
    ((u32 *)a1)[2] = (u32)EneThkAttack;
    ((u32 *)a1)[3] = (u32)EneThkDamage;
    ((u32 *)a1)[4] = (u32)EneThkDead;
    ((u32 *)a1)[7] = (u32)EneThkRebirth;
    ((u32 *)a1)[9] = (u32)EneThkGuard;
}

/* EneThkPlay @ 0x164890 .. 0x1648A8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: jr v0 at 0x1648a0 tail-calls through a pointer
 *   a0 takes slot 0 only because of the ABI order
 */

void EneThkPlay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = *(u8 *)(((u8 *)a1 + 0x180));
    v0 = v0 << 2;
    v0 = (s32)((u8 *)a1 + v0);
    v0 = *(s32 *)v0;
    ((void (*)(void *, void *))(s32)v0)(a0, a1);
    return;
}

/* EneThkNone @ 0x164880 .. 0x164888 (0x8 bytes) */

static void EneThkNone(void) {
    return;
}

/* EneThkAppear @ 0x164870 .. 0x164878 (0x8 bytes) */

static void EneThkAppear(void) {
    return;
}

/* EneThkFree @ 0x164860 .. 0x164868 (0x8 bytes) */

static void EneThkFree(void) {
    return;
}

static void EneThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
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
        CheckEneStayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}

static void EneThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
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
        CheckEneWalkState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1de));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    }
    return;
}

/* EneThkAttack @ 0x1647B0 .. 0x1647B8 (0x8 bytes) */

static void EneThkAttack(void) {
    return;
}

/* EneThkDamage @ 0x1647A0 .. 0x1647A8 (0x8 bytes) */

static void EneThkDamage(void) {
    return;
}


/* EneThkDead @ 0x164790 .. 0x164798 (0x8 bytes) */

static void EneThkDead(void) {
    return;
}

static void EneThkRebirth(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 *s1;
    s32 a1_scalar; // a1
    u8 *s0;
    s32 a1_scalar_; // a1
    s32 a1_scalar__; // a1
    float f12;
    float f2;
    float f1;
    float f0;
    s32 a1_scalar___; // a1
    void *a1_2; // a1
    s32 v1;
    s32 v0;

    v1 = 0x6f;
    s3 = (u8 *)a0;
    s2 = (u8 *)a1;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    a0 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    s0 = (u8 *)(MdlMng + 0x4600);
    switch ((u32)a0) {
    case 31:
    case 33:
    case 35:
    case 36:
        break;
    case 45:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
            goto _L001642F8;
        } else {
            a0 = (void *)(s0 + 0x20);
            a1_2 = (void *)(s3 + 0x20);
            f0 = Math_GetDistXZ((float *)a0, (float *)a1_2);
            f2 = *(float *)(s3 + 0x110);
            f1 = (f2 + *(float *)(s0 + 0x110));
            if (!(f0 <= f1) && *(u8 *)(s2 + 0x245) == 0) {
                f12 = 0.0f;
                a0 = (void *)s3;
                a1_2 = (void *)(s32)0x1f;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                *(u8 *)(s3 + 0x130) = 0;
                *(u8 *)(s3 + 0x131) = 0;
                *(u8 *)(s3 + 0x132) = 0;
                break;
            } else {
                _L001642F8:;
                a0 = (void *)s1;
                v0 = CheckAnimEndFrame(a0);
                if ((u32)v0 == 0) {
                    break;
                }
                a0 = (void *)*(s32 *)(s3 + 0x124);
                v1 = 0x3c;
                v1 = (u32)(s32)a0 % 0x3c;
                if ((u32)v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0xa;
                v1 = v0 % 0xa;
                if (v1 > (s32)2) {
                    break;
                }
                a1_scalar = *(s16 *)(s3 + 0x104);
                f12 = 0.0f;
                a0 = (void *)s3;
                ChangeAnimParam(a0, a1_scalar, 0.0f);
                break;
            }
        }
    case 46:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
            goto _L001643D0;
        } else {
            a0 = (void *)(s0 + 0x20);
            a1_2 = (void *)(s3 + 0x20);
            f0 = Math_GetDistXZ((float *)a0, (float *)a1_2);
            f2 = *(float *)(s3 + 0x110);
            f1 = (f2 + *(float *)(s0 + 0x110));
            if (!(f0 <= f1) && *(u8 *)(s2 + 0x245) == 0) {
                f12 = 0.0f;
                a0 = (void *)s3;
                a1_2 = (void *)(s32)0x21;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                *(u8 *)(s3 + 0x130) = 0;
                *(u8 *)(s3 + 0x131) = 0;
                *(u8 *)(s3 + 0x132) = 0;
                break;
            } else {
                _L001643D0:;
                a0 = (void *)s1;
                v0 = CheckAnimEndFrame(a0);
                if ((u32)v0 == 0) {
                    break;
                }
                a0 = (void *)*(s32 *)(s3 + 0x124);
                v1 = 0x3c;
                v1 = (u32)(s32)a0 % 0x3c;
                if ((u32)v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0xa;
                v1 = v0 % 0xa;
                if (v1 > (s32)2) {
                    break;
                }
                a1_scalar_ = *(s16 *)(s3 + 0x104);
                f12 = 0.0f;
                a0 = (void *)s3;
                ChangeAnimParam(a0, a1_scalar_, 0.0f);
                break;
            }
        }
    case 48:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
            goto _L001644A8;
        } else {
            a0 = (void *)(s0 + 0x20);
            a1_2 = (void *)(s3 + 0x20);
            f0 = Math_GetDistXZ((float *)a0, (float *)a1_2);
            f2 = *(float *)(s3 + 0x110);
            f1 = (f2 + *(float *)(s0 + 0x110));
            if (!(f0 <= f1) && *(u8 *)(s2 + 0x245) == 0) {
                f12 = 0.0f;
                a0 = (void *)s3;
                a1_2 = (void *)(s32)0x24;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                *(u8 *)(s3 + 0x130) = 0;
                *(u8 *)(s3 + 0x131) = 0;
                *(u8 *)(s3 + 0x132) = 0;
                break;
            } else {
                _L001644A8:;
                a0 = (void *)s1;
                v0 = CheckAnimEndFrame(a0);
                if ((u32)v0 == 0) {
                    break;
                }
                a0 = (void *)*(s32 *)(s3 + 0x124);
                v1 = 0x3c;
                v1 = (u32)(s32)a0 % 0x3c;
                if ((u32)v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0xa;
                v1 = v0 % 0xa;
                if (v1 > (s32)2) {
                    break;
                }
                a1_scalar__ = *(s16 *)(s3 + 0x104);
                f12 = 0.0f;
                a0 = (void *)s3;
                ChangeAnimParam(a0, a1_scalar__, 0.0f);
                break;
            }
        }
    case 47:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
            goto _L00164580;
        } else {
            a0 = (void *)(s0 + 0x20);
            a1_2 = (void *)(s3 + 0x20);
            f0 = Math_GetDistXZ((float *)a0, (float *)a1_2);
            f2 = *(float *)(s3 + 0x110);
            f1 = (f2 + *(float *)(s0 + 0x110));
            if (!(f0 <= f1) && *(u8 *)(s2 + 0x245) == 0) {
                f12 = 0.0f;
                a0 = (void *)s3;
                a1_2 = (void *)(s32)0x23;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                *(u8 *)(s3 + 0x130) = 0;
                *(u8 *)(s3 + 0x131) = 0;
                *(u8 *)(s3 + 0x132) = 0;
                break;
            } else {
                _L00164580:;
                a0 = (void *)s1;
                v0 = CheckAnimEndFrame(a0);
                if ((u32)v0 == 0) {
                    break;
                }
                a0 = (void *)*(s32 *)(s3 + 0x124);
                v1 = 0x3c;
                v1 = (u32)(s32)a0 % 0x3c;
                if ((u32)v1 != 0) {
                    break;
                }
                v0 = rand();
                v1 = 0xa;
                v1 = v0 % 0xa;
                if (v1 > (s32)2) {
                    break;
                }
                a1_scalar___ = *(s16 *)(s3 + 0x104);
                f12 = 0.0f;
                a0 = (void *)s3;
                ChangeAnimParam(a0, a1_scalar___, 0.0f);
                break;
            }
        }
    case 40:
    case 30:
    case 42:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
        }
        a0 = (void *)s1;
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s3 + 0x124);
        v1 = 0x5a;
        v1 = (u32)(s32)a0 % 0x5a;
        if ((u32)v1 != 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1_2 = (void *)(s32)0x2d;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 41:
    case 32:
    case 43:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
        }
        a0 = (void *)s1;
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s3 + 0x124);
        v1 = 0x5a;
        v1 = (u32)(s32)a0 % 0x5a;
        if ((u32)v1 != 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1_2 = (void *)(s32)0x2e;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 65:
    case 105:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
        }
        a0 = (void *)s1;
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s3 + 0x124);
        v1 = 0x5a;
        v1 = (u32)(s32)a0 % 0x5a;
        if ((u32)v1 != 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1_2 = (void *)(s32)0x30;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 71:
    case 111:
        v0 = *(s16 *)(s2 + 0x1ec);
        if ((u32)v0 != 0) {
            v0 = v0 + -1;
            *(u16 *)(s2 + 0x1ec) = v0;
        }
        a0 = (void *)s1;
        v0 = CheckAnimEndFrame(a0);
        if ((u32)v0 == 0) {
            break;
        }
        a0 = (void *)*(s32 *)(s3 + 0x124);
        v1 = 0x5a;
        v1 = (u32)(s32)a0 % 0x5a;
        if ((u32)v1 != 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s3;
        a1_2 = (void *)(s32)0x2f;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
    }
    return;
}

/* EneThkGuard @ 0x164190 .. 0x164198 (0x8 bytes) */

static void EneThkGuard(void) {
    return;
}

unsigned int CheckEneStayState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 a2;
    u32 s0;
    s32 v1;
    u32 v0;
    float f1;
    float f0;
    u8 *a0_2;
    void *a1_2;

    s2 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0x1b4));
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    if (v0 != 0) {
        v0 = CheckEneRollState(a0, a1);
        if (v0 != 0) {
            v0 = 1;
        } else {
            a0_2 = (u8 *)*(s32 *)(s2 + 0x1b4);
            v0 = *(u8 *)(s2 + 0x128);
            v1 = *(u8 *)(a0_2 + 0x128);
            if ((u32)v1 != v0) {
                v1 = *(s16 *)(s2 + 0x104);
                v0 = 2;
                if ((u32)v1 != v0) {
                    v0 = 1;
                    if ((u32)v1 != 0) {
                        if ((u32)v1 == v0) {
                            goto _L00164168;
                        }
                        v0 = 0xe;
                        if ((u32)v1 != v0) {
                            goto _L00163FC8;
                        }
                        goto _L00164168;
                    } else {
                        v0 = *(s32 *)(s1 + 0x100);
                        a0_2 = s2;
                        a1_2 = (void *)s1;
                        a2 = 1;
                        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                        v0 = 1;
                    }
                } else {
                    v0 = *(s32 *)(s1 + 0x1e8);
                    if (v0 == 0) {
                        v0 = *(s32 *)(s1 + 0x104);
                        a0_2 = s2;
                        a1_2 = (void *)s1;
                        a2 = 0xb;
                        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    } else {
                        a0_2 = (u8 *)(s32)s0;
                        v0 = CheckAnimEndFrame((void *)a0_2);
                        if (v0 != 0) {
                            v0 = rand();
                            v1 = 0x64;
                            s0 = (s32)v0 % (s32)(0x64);
                            a0_2 = s2;
                            if ((s32)s0 <= (s32)0xe) {
                                a1_2 = (void *)(s32)0x50;
                                v0 = CheckAnimParam((void *)a0_2, (signed int)a1_2);
                                if (v0 == 0) {
                                    goto _L00163F60;
                                }
                                v0 = *(s16 *)(s2 + 0x104);
                                a2 = 0x50;
                                if (v0 == (u32)a2) {
                                    goto _L00163F60;
                                }
                                v0 = *(s32 *)(s1 + 0x104);
                                a0_2 = s2;
                                a1_2 = (void *)s1;
                                ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                            } else {
                                _L00163F60:;
                                a0_2 = s2;
                                if ((s32)s0 <= (s32)0x1d) {
                                    a1_2 = (void *)(s32)0x51;
                                    v0 = CheckAnimParam((void *)a0_2, (signed int)a1_2);
                                    if (v0 == 0) {
                                        goto _L00163FA8;
                                    }
                                    v0 = *(s16 *)(s2 + 0x104);
                                    a2 = 0x51;
                                    if (v0 == (u32)a2) {
                                        goto _L00163FA8;
                                    }
                                    v0 = *(s32 *)(s1 + 0x104);
                                    a0_2 = s2;
                                    a1_2 = (void *)s1;
                                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                                } else {
                                    _L00163FA8:;
                                    v0 = *(s32 *)(s1 + 0x100);
                                    a0_2 = s2;
                                    a1_2 = (void *)s1;
                                    a2 = 2;
                                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                                }
                            }
                        }
                    }
                    v0 = 1;
                    goto _L00164170;
                    _L00163FC8:;
                    v0 = *(s32 *)(s1 + 0x104);
                    a0_2 = s2;
                    a1_2 = (void *)s1;
                    a2 = 5;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    v0 = 1;
                }
            } else {
                v0 = 0x3e99999a;
                f0 = *(float *)(s2 + 0x19c);
                f1 = (0.300000012f + (0.300000012f + (*(float *)(s2 + 0x110) + *(float *)(a0_2 +
                    0x110))));
                if (!(f0 <= f1)) {
                    v0 = *(s32 *)(s1 + 0x104);
                    a0_2 = s2;
                    a1_2 = (void *)s1;
                    a2 = 5;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    v0 = 1;
                } else {
                    a0_2 = s2;
                    a1_2 = (void *)(s32)3;
                    v0 = CheckAnimParam((void *)a0_2, (signed int)a1_2);
                    a0_2 = (u8 *)(s32)s0;
                    if (v0 == 0) {
                        goto _L00164168;
                    }
                    v0 = CheckAnimEndFrame((void *)a0_2);
                    if (v0 == 0) {
                        goto _L00164168;
                    }
                    v0 = rand();
                    v1 = 0x64;
                    v0 = (s32)v0 % (s32)(0x64);
                    if ((s32)v0 > (s32)0x27) {
                        goto _L00164168;
                    }
                    v0 = *(s32 *)(s1 + 0x100);
                    a0_2 = s2;
                    a1_2 = (void *)s1;
                    a2 = 3;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    goto _L00164168;
                }
            }
        }
    } else {
        v0 = UpdateMovePath(a0);
        if (v0 != 0) {
            v0 = *(s32 *)(s1 + 0x104);
            a0_2 = s2;
            a1_2 = (void *)s1;
            a2 = 5;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
            v0 = 1;
        } else {
            v1 = *(s16 *)(s2 + 0x104);
            if ((u32)v1 == 0) {
                v0 = *(u16 *)(s1 + 0x1dc);
                if ((s32)v0 <= (s32)0x78) {
                    goto _L00164168;
                }
                v0 = rand();
                v1 = 0x64;
                v0 = (s32)v0 % (s32)(0x64);
                if ((s32)v0 > (s32)4) {
                    goto _L00164168;
                }
                v0 = *(s32 *)(s1 + 0x104);
                a0_2 = s2;
                a1_2 = (void *)s1;
                a2 = 5;
                ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                v0 = 1;
            } else {
                v0 = 2;
                a0_2 = (u8 *)(s32)s0;
                if ((u32)v1 == v0) {
                    v0 = CheckAnimEndFrame((void *)a0_2);
                    if (v0 == 0) {
                        goto _L00164168;
                    }
                    v0 = *(s32 *)(s1 + 0x104);
                    a0_2 = s2;
                    a1_2 = (void *)s1;
                    a2 = 5;
                    ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_2, (u32)a1_2, a2);
                    v0 = 1;
                } else {
                    _L00164168:;
                    v0 = 0;
                }
            }
        }
    }
    _L00164170:;
    return v0;
}
unsigned int CheckEneWalkState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    s32 a2;
    float f3;
    float f2;
    float f1;
    void *a0_s1; // a0
    float f20;
    u8 *s0;
    u32 v1;
    float f0;
    u32 v0;
    u8 *a1_2;
    s32 s2;

    a0_bytes = (u8 *)a0;
    a0 = *(void **)((u8 *)a0 + 0x100);
    a0_s1 = a0;
    v0 = *(s32 *)((u32)a0_bytes + 0xc);
    v0 = *(s32 *)(v0 + 0x4c);
    s0 = (u8 *)a1;
    f2 = (float)(u32)*(u16 *)(v0 + 0x12);
    f1 = f2 / 100.0f;
    f20 = 0.4f * f1;
    a1_2 = (u8 *)*(s32 *)((u32)a0_bytes + 0x1b4);
    if ((u32)(s32)a1_2 != 0) {
        v1 = *(u8 *)(a1_2 + 0x128);
        v0 = *(u8 *)(a0_bytes + 0x128);
        if (v1 != v0) {
            v0 = CheckAnimEndFrame(a0_s1);
            if (v0 == 0) {
                goto _L00163DF8;
            }
            v1 = *(s16 *)(a0_bytes + 0x104);
            switch (v1) {
            default: goto _L00163DF8;
            case 10: case 11: case 17: case 80: case 81:
            case 18: case 19: case 28: case 29:
                v0 = *(s32 *)(s0 + 0x1e8);
                if (v0 != 0) {
                    v0 = 0x11;
                    if (v1 == v0) {
                        goto _L00163970;
                    }
                    v0 = rand();
                    v1 = 0x64;
                    s2 = (s32)v0 % 0x64;
                    a0_s1 = (void *)a0_bytes;
                    if (s2 <= (s32)0xe) {
                        a1_2 = (u8 *)(s32)0x50;
                        v0 = CheckAnimParam(a0_s1, (signed int)a1_2);
                        if (v0 == 0) {
                            goto _L00163908;
                        }
                        v0 = *(s16 *)(a0_bytes + 0x104);
                        a2 = 0x50;
                        if (v0 == (u32)a2) {
                            goto _L00163908;
                        }
                        v0 = *(s32 *)(s0 + 0x104);
                        a0_s1 = (void *)a0_bytes;
                        a1_2 = s0;
                        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                    } else {
                        _L00163908:;
                        a0_s1 = (void *)a0_bytes;
                        if (s2 <= (s32)0x1d) {
                            a1_2 = (u8 *)(s32)0x51;
                            v0 = CheckAnimParam(a0_s1, (signed int)a1_2);
                            if (v0 == 0) {
                                goto _L00163950;
                            }
                            v0 = *(s16 *)(a0_bytes + 0x104);
                            a2 = 0x51;
                            if (v0 == (u32)a2) {
                                goto _L00163950;
                            }
                            v0 = *(s32 *)(s0 + 0x104);
                            a0_s1 = (void *)a0_bytes;
                            a1_2 = s0;
                            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                        } else {
                            _L00163950:;
                            v0 = *(s32 *)(s0 + 0x100);
                            a0_s1 = (void *)a0_bytes;
                            a1_2 = s0;
                            a2 = 2;
                            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                        }
                    }
                } else {
                    _L00163970:;
                    f1 = *(float *)(a0_bytes + 0x19c);
                    if (0.0f < f1) {
                        if (!(f1 < f20) || (s32)*(u16 *)(s0 + 0x1e0) > (s32)0x12b) {
                            goto _L00163A00;
                        }
                        a0_s1 = (void *)a0_bytes;
                        a1_2 = (u8 *)(s32)0x11;
                        v0 = CheckAnimParam(a0_s1, (signed int)a1_2);
                        if (v0 == 0) {
                            goto _L00163A00;
                        }
                        v0 = *(s16 *)(a0_bytes + 0x104);
                        a2 = 0x11;
                        if (v0 != (u32)a2) {
                            *(u16 *)(s0 + 0x1e0) = 0;
                            a0_s1 = (void *)a0_bytes;
                            v0 = *(s32 *)(s0 + 0x104);
                            a1_2 = s0;
                            a2 = 0x10;
                            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                        } else {
                            v0 = *(s32 *)(s0 + 0x104);
                            a0_s1 = (void *)a0_bytes;
                            a1_2 = s0;
                            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                        }
                    } else {
                        _L00163A00:;
                        *(u16 *)(s0 + 0x1e0) = 0;
                        v0 = *(s32 *)(s0 + 0x104);
                        a0_s1 = (void *)a0_bytes;
                        a1_2 = s0;
                        a2 = 0xb;
                        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
                    }
                }
                v0 = 1;
            }
        } else {
            float partner = *(float *)(a1_2 + 0x110);
            float self = *(float *)(a0_bytes + 0x110);
            v1 = *(s16 *)(a0_bytes + 0x104);
            v0 = 0x1d;
            f1 = 0.3f + (self + partner);
            switch (v1) {
            case 18:
            case 19:
            case 28:
            case 29:
                v0 = CheckAnimEndFrame(a0_s1);
                if (v0 == 0) {
                    goto _L00163DF8;
                }
                v0 = *(s32 *)(s0 + 0x100);
                a0_s1 = (void *)a0_bytes;
                a1_2 = s0;
                ((void (*)(u32, u32, u32))(s32)v0)((u32)a0_s1, (u32)a1_2, 0);
                goto _L00163DF8;
            default:
                f0 = *(float *)(a0_bytes + 0x19c);
                if (!(f0 < f1)) {
                    goto _L00163DF8;
                }
                v0 = *(s32 *)(s0 + 0x100);
                a0_s1 = (void *)a0_bytes;
                a1_2 = s0;
                ((void (*)(u32, u32, u32))(s32)v0)((u32)a0_s1, (u32)a1_2, 0);
                v0 = 1;
                break;
            }
        }
    } else {
        v1 = *(s16 *)(a0_bytes + 0x104);
        v0 = 0x51;
        switch (v1) {
        case 18:
        case 19:
        case 28:
        case 29:
        case 11:
        case 17:
        case 80:
        case 81:
            v0 = CheckAnimEndFrame(a0_s1);
            if (v0 == 0) {
                goto _L00163B60;
            }
            v0 = *(s32 *)(s0 + 0x100);
            a0_s1 = (void *)a0_bytes;
            a1_2 = s0;
            a2 = 0xe;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0_s1, (u32)a1_2, a2);
            v0 = 1;
            return v0;
        default:
            _L00163B60:;
            a0_s1 = (void *)a0_bytes;
            v0 = UpdateMovePath(a0_s1);
            if (v0 != 0) {
                goto _L00163DF8;
            }
            v1 = *(u16 *)(s0 + 0x1de);
            v0 = 0x3c;
            v0 = (s32)v1 % 0x3c;
            if (v0 != 0) {
                goto _L00163DF8;
            }
            v0 = rand();
            v1 = 0x64;
            v0 = (s32)v0 % 0x64;
            if ((s32)v0 > (s32)9) {
                goto _L00163C40;
            }
            v0 = 0x40490000;
            v1 = 0x40490000 | 0x624;
            v0 = 0x40490000 | 0xfdb;
            f2 = (3.1409998f + *(float *)(a0_bytes + 0x198));
            f3 = (3.1415927f + f2);
            if (f3 >= 0.0f) {
                f0 = (f2 - (6.2831855f * (float)((float)(s32)(f3 / 6.2831855f))));
                break;
            } else {
                f1 = 6.2831855f;
                f0 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
            }
        }
        *(f32 *)(a0_bytes + 0x198) = f0;
        goto _L00163DF8;
        _L00163C40:;
        if ((s32)v0 <= (s32)0x13) {
            *(f32 *)(a0_bytes + 0x198) = DCOMP_EXPR_F4392B91E5A8C94E((*(float *)(a0_bytes + 0x198)
                - 3.1409998f));
        } else if ((s32)v0 <= (s32)0x31) {
            *(f32 *)(a0_bytes + 0x198) = DCOMP_EXPR_F4392B91E5A8C94E((0.34899998f + *(float
                *)(a0_bytes + 0x198)));
        } else if ((s32)v0 <= (s32)0x4f) {
            *(f32 *)(a0_bytes + 0x198) = DCOMP_EXPR_F4392B91E5A8C94E((*(float *)(a0_bytes + 0x198)
                - 0.34899998f));
        }
        _L00163DF8:;
        v0 = 0;
    }
    return v0;
}
unsigned int CheckEneAttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 s3;
    u8 *s0;
    u32 v1;
    u32 v0;

    s2 = (u8 *)a0;
    v1 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_646622_FIELDS_LPMDLDATA_1B1FD1B0);
    v0 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_646622_FIELDS_TARGET_LPMDL_B8F61081);
    s0 = (u8 *)*(s32 *)(v1 + DCOMP_OFF_STRUCT_DW_658678_FIELDS_LPPRM_19C154FC);
    s1 = (u8 *)a1;
    if (v0 != 0) {
        v0 = *(s32 *)(s1 + DCOMP_OFF_STRUCT_DW_644877_FIELDS_ATTACKOFF_3A1D0C7D);
        if (v0 == 0) {
            goto _L00163678;
        }
    }
    v0 = 0;
    goto _L001636C0;
    _L00163678:;
    v0 = *(s32 *)(s1 + 0x240);
    if (v0 != 0) {
        v0 = 0;
    } else {
        v1 = *(s16 *)(s2 + 0x104);
        v0 = 0x51;
        switch (v1) {
        case 80:
        case 81:
            v0 = 0;
            break;
        default:
            v0 = 1;
        }
    }
    _L001636C0:;
    if (v0 == 0) {
        v0 = 0;
        goto _L00163760;
    }
    s3 = 0;
    do {
        a0 = (void *)s2;
        a1 = (void *)s1;
        v0 = EneSearchAttackRange((struct dw_646622_fields *)a0, a1, s3);
        if (v0 != 0) {
            v0 = *(u8 *)(s0 + 0xa5);
            if (v0 == 0) {
                goto _L00163718;
            }
            a0 = (void *)s2;
            a1 = (void *)s1;
            v0 = SetEneClingAndPush(a0, a1);
            if (v0 == 0) {
                goto _L00163748;
            }
            goto _L00163730;
            _L00163718:;
            v0 = s3 + 0x32;
            a1 = (void *)(u16)v0;
            a0 = (void *)s2;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            _L00163730:;
            *(u8 *)(s2 + 0x12a) = s3;
            v0 = 1;
            *(u8 *)(s1 + 0x180) = 2;
            return v0;
        }
        _L00163748:;
        s3 = s3 + 1;
        v0 = s3 < (s32)5;
        s0 = (u8 *)(s0 + 0x28);
    } while (v0 != 0);
    v0 = 0;
    _L00163760:;
    return v0;
}
unsigned int CheckEneRollState(void *a0, void *a1)
{
    float distance;
        float shifted;
        float angle;
        float normalized;
        float difference;
        float zero;
    u8 *model = (u8 *)a0;
    u8 *enemy = (u8 *)a1;
    u8 *data = (u8 *)*(u32 *)(model + 0x100);
    u32 result;
    if (!*(u32 *)(model + 0x1b4)) { result = 0; goto end; }
    switch ((u32)*(s16 *)(model + 0x104)) {
    case 18: case 19: case 28: case 29: return 0;
    default:
        if (!CheckAnimParam(a0, 18)) { result = 0; goto end; }
        if (Math_GetAngleDist(*(float *)(model + 0x34), *(float *)(model + 0x198)) < 0.0f)
            distance = -Math_GetAngleDist(*(float *)(model + 0x34), *(float *)(model + 0x198));
        else
            distance = Math_GetAngleDist(*(float *)(model + 0x34), *(float *)(model + 0x198));
    }
    if (distance < 1.5704999f) result = 0;
    else {
        zero = 0.0f;
        angle = 1.5707964f + *(float *)(model + 0x34);
        shifted = 3.1415927f + angle;
        if (shifted >= zero) normalized = angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f);
        else normalized = 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
        difference = Math_GetAngleDist(normalized, *(float *)(model + 0x198));
        {
        if (difference < 0.0f) {
            float shifted;
            float sum;
            shifted = *(float *)(model + 0x34);
            shifted = 1.5707964f + (float)shifted;
            sum = 3.1415927f + shifted;
            if (sum >= 0.0f) normalized = shifted - 6.2831855f * (float)(s32)(sum / 6.2831855f);
            else normalized = 6.2831855f + (shifted - 6.2831855f * (float)(s32)(sum / 6.2831855f));
            difference = -Math_GetAngleDist(normalized, *(float *)(model + 0x198));
        } else {
            float shifted;
            float sum;
            shifted = *(float *)(model + 0x34);
            shifted = 1.5707964f + (float)shifted;
            sum = 3.1415927f + shifted;
            if (sum >= 0.0f) normalized = shifted - 6.2831855f * (float)(s32)(sum / 6.2831855f);
            else normalized = 6.2831855f + (shifted - 6.2831855f * (float)(s32)(sum / 6.2831855f));
            difference = Math_GetAngleDist(normalized, *(float *)(model + 0x198));
        }
        }
        if (difference < 1.5707964f)
            ((void (*)(void *, void *, s32))*(u32 *)(enemy + 0x104))(model, enemy, 19);
        else
            ((void (*)(void *, void *, s32))*(u32 *)(enemy + 0x104))(model, enemy, 18);
        result = 1;
        *(float *)(enemy + 0x1f4) = distance / *(float *)(data + 0x10);
    }
end:
    return result;
}
unsigned int EneSearchAttackRange(struct dw_646622_fields *lpEne, void *unused, int AttackNo) {
    struct EneThkPrm *lpEnePrm;
    float searchMin;
    float searchMax;
    float searchAng;
    int perFrame;
    float HitHigh;
    float HitDist;

    lpEnePrm = (struct EneThkPrm *)lpEne->lpMdlData->lpPrm;
    searchMin = (float)lpEnePrm->ent[AttackNo].rmin / 100.0f;
    searchMax = (float)lpEnePrm->ent[AttackNo].rmax / 100.0f;
    searchAng = (float)lpEnePrm->ent[AttackNo].ang / 10.0f;
    perFrame = lpEnePrm->ent[AttackNo].interval;
    if (lpEnePrm->ent[AttackNo].flag != 0 && GameSt[DCOMP_OFF_STRUCT_DW_654832_FIELDS_DIZZYTEST_92557360] != 0) {
        return 0;
    }
    if (lpEne->TeamNo == lpEne->Target.lpMdl->TeamNo) {
        return 0;
    }
    if (perFrame != 0 && lpEne->timer % (u32)perFrame != 0) {
        return 0;
    }
    if (rand() % 100 > lpEnePrm->ent[AttackNo].prob) {
        return 0;
    }
    if (searchMin <= lpEne->Target.distXZ && lpEne->Target.distXZ < searchMax) {
        if ((Math_GetAngleDist(lpEne->Ang[1], lpEne->Target.angY) < 0.0f ? -Math_GetAngleDist(lpEne->Ang[1], lpEne->Target.angY) : Math_GetAngleDist(lpEne->Ang[1], lpEne->Target.angY)) < 0.01745f * searchAng) {
            HitHigh = 0.8f * lpEne->HitHigh;
            HitDist = lpEne->Target.distXZ;
            if (lpEne->MapHitOff == 0 && lpEnePrm->noObstruct == 0) {
                if (CheckHitObstructLine(lpEne, HitHigh, HitDist) < 1.0f) {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

void SetEneAttackOff(void *a0 /* r4 */, void *a1 /* r5 */) {
    u16 *s2;
    u32 *s1;
    u32 v0;
    s32 v1;
    s32 s0;
    s64 lo;
    s64 hi;
    s32 a2;

    s2 = (u16 *)a0;
    s1 = (u32 *)a1;
    v0 = rand();
    v1 = 0x64;
    s0 = (s32)((s32)v0) % (s32)(0x64);
    lo = (s32)((s32)((s32)v0) / (s32)(0x64));
    hi = (s32)((s32)((s32)v0) % (s32)(0x64));
    a0 = (void *)s2;
    if (s0 < (s32)0xf) {
        a1 = (void *)(s32)0x50;
        v0 = CheckAnimParam(a0, (signed int)a1);
        if (v0 == 0) {
            goto _L00162FA8;
        }
        v0 = *(s16 *)(((u8 *)s2 + 0x104));
        a2 = 0x50;
        if (v0 == (u32)a2) {
            goto _L00162FA8;
        }
        v0 = *(s32 *)(((u8 *)s1 + 0x104));
        a0 = (void *)s2;
        a1 = (void *)s1;
        ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
    } else {
        _L00162FA8:;
        a0 = (void *)s2;
        if (s0 < (s32)0x1e) {
            a1 = (void *)(s32)0x51;
            v0 = CheckAnimParam(a0, (signed int)a1);
            if (v0 == 0) {
                goto _L00162FF0;
            }
            v0 = *(s16 *)(((u8 *)s2 + 0x104));
            a2 = 0x51;
            if (v0 == (u32)a2) {
                goto _L00162FF0;
            }
            v0 = *(s32 *)(((u8 *)s1 + 0x104));
            a0 = (void *)s2;
            a1 = (void *)s1;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
        } else {
            _L00162FF0:;
            v0 = *(s32 *)(((u8 *)s1 + 0x100));
            a0 = (void *)s2;
            a1 = (void *)s1;
            a2 = 2;
            ((void (*)(u32, u32, s32))(s32)v0)((u32)a0, (u32)a1, a2);
        }
    }
    return;
}

/* CheckEneAttackEnable @ 0x162EC0 .. 0x162F30 (0x70 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x162ee8 writes a register its branch at 0x162ee4 reads
 *   delay: addiu at 0x162f04 writes a register its branch at 0x162f00 reads
 *   cfg: kept branch: 0x162ec0 if (..) goto .L00162ED8
 *   cfg: kept branch: 0x162ecc if (..) goto .L00162EE0
 *   cfg: kept goto: 0x162ed8 -> .L00162F28
 *   cfg: kept goto: 0x162f18 -> .L00162F28
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckEneAttackEnable(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;
    s32 v1;

    v0 = *(s32 *)(((u8 *)a0 + 0x1b4));
    if (v0 == 0) {
        goto _L00162ED8;
    }
    v0 = *(s32 *)(((u8 *)a1 + 0x1e8));
    if (v0 == 0) {
        goto _L00162EE0;
    }
    _L00162ED8:;
    v0 = 0;
    goto _L00162F28;
    _L00162EE0:;
    v0 = *(s32 *)(((u8 *)a1 + 0x240));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    v0 = 0x51;
    switch ((u32)v1) {
    case 80:
    case 81:
        v0 = 0;
        return v0;
    }
    v0 = 1;
    _L00162F28:;
    return v0;
}
