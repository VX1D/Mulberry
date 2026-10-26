#include "common.h"
static const char sMyEquipBndFmt[16] __attribute__((section(".rodata"), aligned(8))) = "fu/p%03d.bnd";

/* CheckMyBlastAnimEnable @ 0x14FCD0 .. 0x14FD50 (0x80 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14fcfc writes a register its branch at 0x14fcf8 reads
 *   delay: addiu at 0x14fd10 writes a register its branch at 0x14fd0c reads
 *   cfg: kept goto: 0x14fd30 -> .L0014FD48
 */

extern u8 MdlMng[];

/* SetMyActFreeFlag @ 0x14FD50 .. 0x14FD60 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 MdlMng[];

/* SetMyCrouchDisable @ 0x14FD60 .. 0x14FD70 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 MdlMng[];

/* SetMyTotterMode @ 0x14FE70 .. 0x14FEF0 (0x80 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x14feb8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * GetMovePath(unsigned char, signed int);
extern void SetMyPadMode(signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);

/* SetMyNormalMode @ 0x14FEF0 .. 0x14FF48 (0x58 bytes, frame 0x30) */

extern void SetCamCtrlMode(unsigned int);
extern void SetMyPadMode(signed int);
extern void SetMyStay(void *, void *, unsigned short);
extern void FECard_Enable_Draw(signed int);
extern u8 MdlMng[];

/* SetMyMukadeMode @ 0x14FF50 .. 0x1501D4 (0x284 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1822 -> 0x228900
 *   literal: @1824 -> 0x228910
 *   stack: address of the slot at 0x80 escapes at 0x14ffe0
 *   stack: address of the slot at 0x70 escapes at 0x14ffe8
 *   fpu: float literal 0x00000000 at 0x14fff8
 *   fpu: float literal 0x00000000 at 0x150008
 *   fpu: float literal 0x40490fdb at 0x150020
 *   fpu: float literal 0x00000000 at 0x150024
 *   fpu: float literal 0x40c90fdb at 0x15004c
 *   fpu: mtc1 reinterprets v0 at 0x150070
 *   fpu: float literal 0x3fc00000 at 0x15009c
 *   fpu: float literal 0x40490fdb at 0x1500bc
 *   fpu: float literal 0x00000000 at 0x1500c0
 *   fpu: float literal 0x40c90fdb at 0x1500e4
 *   fpu: mtc1 reinterprets v0 at 0x150108
 *   fpu: float literal 0x3fc00000 at 0x150138
 *   literal: @1824 initializes the 16-byte local at 0x50
 *   cfg: loop body is not one contiguous region: .L00150168
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * GetMapPartsInfoByCtrlId(signed int, signed int);
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void SetHokanFrame(void *, float);
extern signed int GetMdlCtrlId(void *);
extern void FreeMdlMng(void *);
extern void EneEraseAllFriend();
extern u8 GameSt[];
extern u_long128 L1822[];
extern u32 L1824[];

struct dw_383276_fields;
struct dw_387349_fields;
#ifndef PROTO_DW_409091_FIELDS
#define PROTO_DW_409091_FIELDS
struct dw_409091_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_406033_FIELDS
#define PROTO_DW_406033_FIELDS
struct dw_406033_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_405710_FIELDS
#define PROTO_DW_405710_FIELDS
struct dw_405710_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_383276_fields *lpMdl; };
#endif
#ifndef PROTO_DW_383276_FIELDS
#define PROTO_DW_383276_FIELDS
struct dw_383276_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_387349_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_383276_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_409091_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_406033_fields flags; unsigned char _pad1[3]; struct dw_405710_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_407453_FIELDS
#define PROTO_DW_407453_FIELDS
struct dw_407453_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_383276_FIELDS_ANG_1__5AC85484_DEFINED
#define DCOMP_OFF_STRUCT_DW_383276_FIELDS_ANG_1__5AC85484_DEFINED
enum { DCOMP_OFF_STRUCT_DW_383276_FIELDS_ANG_1__5AC85484 = (int)&(((struct dw_383276_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_0__FA9AEEBB_DEFINED
#define DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_0__FA9AEEBB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_0__FA9AEEBB = (int)&(((struct dw_383276_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_1__D7D1DFF6_DEFINED
#define DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_1__D7D1DFF6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_1__D7D1DFF6 = (int)&(((struct dw_383276_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_2__BB360F5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_2__BB360F5E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_383276_FIELDS_POS_2__BB360F5E = (int)&(((struct dw_383276_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_383276_FIELDS_BUSE_48DA806A_DEFINED
#define DCOMP_OFF_STRUCT_DW_383276_FIELDS_BUSE_48DA806A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_383276_FIELDS_BUSE_48DA806A = (int)&(((struct dw_383276_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_407453_FIELDS_PLAYERID_84FB57B1_DEFINED
#define DCOMP_OFF_STRUCT_DW_407453_FIELDS_PLAYERID_84FB57B1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_407453_FIELDS_PLAYERID_84FB57B1 = (int)&(((struct dw_407453_fields *)0)->PlayerId) - 0 };
#endif
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
struct smV4 { float v[4]; };

/* SetMyDizzy @ 0x150210 .. 0x150284 (0x74 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x150244 if (..) goto .L00150258
 *   cfg: kept goto: 0x150250 -> .L00150260
 */

extern void SetDizzy(signed int);



/* UpdateMyHead (cs4/Seimei/src/My): code EXACT in whole-unit landing (verified with void* variant: only diff left was prototype).
 * Blocker: landed caller block declares `static void UpdateMyHead(void *, signed int, float *, signed int);` (My.c ~l.1266);
 * DWARF param is struct *lpMy; a void* param + cast/copy changes regalloc (formal-copy order / base-cast CSE).
 * To land: change that prototype to `static void UpdateMyHead(struct umh_My *, int, float *, int);`.
 * ScriptHeart must be defined `= 0` here so .sbss order is ScriptHeart(+0), Flag(+4). */
static u8 ScriptHeart = 0;
extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0ScaleVectorXYZ(void *, void *, float);
extern void sceVu0SubVector(void *, void *, void *);
extern void Math_VectorToAngleXY(float *, float *);
extern void sceVu0CopyVector(void *, void *);
extern void AnimLinear(float *, float *, float *, float);

struct umh_Obj {
    float Position[4];
    float Angle[4];
    float Scale[4];
    short ObjectId;
    short GeomObjectId;
    short ParentObjectId;
    short umh_r0[21];
};
struct umh_Vmd {
    unsigned char umh_r1[0x1c];
    struct umh_Obj *lpObject;
    float GeomScale;
};
struct umh_MdlData {
    unsigned char umh_r2[0x10];
    struct umh_Vmd *lpVmdHead;
};
struct umh_AnimCtrl {
    unsigned char umh_r3[0x24];
    unsigned int Flag;
    unsigned char umh_r4[0x18];
    float Pos[4];
    float Ang[4];
    float Scl[4];
    float UserScl[4];
    float LocalMat[4][4];
    unsigned char umh_r5[0x10];
};
struct umh_My {
    unsigned char umh_r6[0xc];
    struct umh_MdlData *lpMdlData;
    float (*lpObjMat)[4][4];
    unsigned char umh_r7[0xec];
    void *lpAnimCtrl;
};

#define UMH_WRAP(a) (((a) + PI) >= 0.0f ? ((a) - TWO_PI * (int)(((a) + PI) / TWO_PI)) : (TWO_PI + ((a) - TWO_PI * (int)(((a) + PI) / TWO_PI))))

#define UMH_SETMAT(ac, ang) { \
    float rx = UMH_WRAP((ang)[0]); \
    float ry = UMH_WRAP((ang)[1]); \
    float rz = UMH_WRAP((ang)[2]); \
    float sx = sinf(rx); \
    float cx = cosf(rx); \
    float sz = sinf(rz); \
    float cz = cosf(rz); \
    float sy = sinf(ry); \
    float cy = cosf(ry); \
    (ac)->LocalMat[0][0] = cz * ((ac)->Scl[0] * cy); \
    (ac)->LocalMat[0][1] = (ac)->Scl[0] * sz; \
    (ac)->LocalMat[0][2] = cz * ((ac)->Scl[0] * -sy); \
    (ac)->LocalMat[0][3] = 0.0f; \
    (ac)->LocalMat[1][0] = (ac)->Scl[1] * (sy * sx - cx * (cy * sz)); \
    (ac)->LocalMat[1][1] = cx * ((ac)->Scl[1] * cz); \
    (ac)->LocalMat[1][2] = (ac)->Scl[1] * (cy * sx + cx * (sy * sz)); \
    (ac)->LocalMat[1][3] = 0.0f; \
    (ac)->LocalMat[2][0] = (ac)->Scl[2] * (sy * cx + sx * (cy * sz)); \
    (ac)->LocalMat[2][1] = sx * ((ac)->Scl[2] * -cz); \
    (ac)->LocalMat[2][2] = (ac)->Scl[2] * (cy * cx - sx * (sy * sz)); \
    (ac)->LocalMat[2][3] = 0.0f; \
    (ac)->LocalMat[3][0] = (ac)->Pos[0]; \
    (ac)->LocalMat[3][1] = (ac)->Pos[1]; \
    (ac)->LocalMat[3][2] = (ac)->Pos[2]; \
    (ac)->LocalMat[3][3] = 1.0f; \
}

#define UMH_ABS(x) ((x) < 0.0f ? -(x) : (x))


/* StabilizeMyCloth @ 0x150D20 .. 0x150DC0 (0xa0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x150d44
 *   fpu: float literal 0x3d4ccccd at 0x150d68
 */

extern void SetHokanFrame(void *, float);
extern void MasterMove(void *);
extern unsigned int CheckHitMap(void *);
extern signed int CsMngRtaSetMat(unsigned int, void *, int);
extern void PlayMi3(void *);
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern u32 g_UnitMat[];

/* CheckDrawMyWrist @ 0x150DC0 .. 0x150EA0 (0xe0 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x150dfc writes a register its branch at 0x150df8 reads
 *   delay: addiu at 0x150e10 writes a register its branch at 0x150e0c reads
 *   delay: slti at 0x150e50 writes a register its branch at 0x150e4c reads
 *   cfg: kept branch: 0x150dc0 if (..) goto .L00150DE0
 *   cfg: kept goto: 0x150dd8 -> .L00150E98
 *   cfg: kept branch: 0x150e48 if (..) goto .L00150E90
 *   cfg: kept branch: 0x150e70 if (..) goto .L00150E90
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u8 GameSt[];

/* UpdateMyWep @ 0x150EA0 .. 0x150FB8 (0x118 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x150f14
 *   fpu: float literal 0x00000000 at 0x150f50
 *   fpu: float literal 0x00000000 at 0x150f84
 *   cfg: kept branch: 0x150f04 if (..) goto .L00150F30
 *   cfg: kept branch: 0x150f40 if (..) goto .L00150F68
 */

extern unsigned int CheckAnimEndFrame(void *);
extern void MasterMove(void *);

extern u32 MyEquip[];

/* CheckMyWeapon @ 0x1510D0 .. 0x151108 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1510e0 writes a register its branch at 0x1510dc reads
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return signed int vs inferred u32; 1 parameters vs 2
 *   inferred
 */

extern u8 GameSt[];

/* InitMyWeapon @ 0x151180 .. 0x1512A8 (0x128 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001511D8
 *   cfg: loop body is not one contiguous region: .L00151200
 */

extern unsigned int SetMdlMng(void *, void *);
extern void * memcpy(void *, void *, unsigned int);
extern void *GetSaveData(void);
extern u32 MdlData[];


/* dcomp: the 16-byte writable template @1582 is one object shared by
 * UpdateMyLump and SetMyLumpOn; a local initializer in each function
 * would emit a second, differently placed copy. */
struct dcomp_amb { u8 b[16]; };
static struct dcomp_amb dcomp_amb_data __attribute__((aligned(16)));

/* UpdateMyLump @ 0x1512B0 .. 0x151370 (0xc0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1582 -> 0x2288f0
 *   stack: address of the slot at 0x30 escapes at 0x1512e8
 *   stack: address of the slot at 0x30 escapes at 0x1512e8
 *   fpu: float literal 0x3e4ccccd at 0x151300
 *   fpu: float literal 0x3e4ccccd at 0x151324
 *   fpu: float literal 0x3f800000 at 0x151340
 *   stack: address of the slot at 0x30 escapes at 0x151354
 *   literal: @1582 initializes the 16-byte local at 0x30
 */

extern void sceVu0ApplyMatrix(void *, void *, void *);
extern signed int SFX_SetPos(signed int, float *);

/* SetMyLumpOff @ 0x151370 .. 0x1513BC (0x4c bytes, frame 0x20) */

extern signed int SFX_Delete();


/* SetMyLumpOn @ 0x1513C0 .. 0x1515DC (0x21c bytes, frame 0x80) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1582 -> 0x2288f0
 *   literal: @1563 -> 0x2288d0
 *   literal: @1566 -> 0x2288e0
 *   stack: address of the slot at 0x50 escapes at 0x151490
 *   stack: address of the slot at 0x50 escapes at 0x151490
 *   fpu: float literal 0x3e4ccccd at 0x1514a8
 *   fpu: float literal 0x3e4ccccd at 0x1514cc
 *   fpu: float literal 0x3f800000 at 0x1514e8
 *   stack: address of the slot at 0x50 escapes at 0x1514fc
 *   stack: address of the slot at 0x70 escapes at 0x151554
 *   stack: address of the slot at 0x60 escapes at 0x1515a4
 *   literal: @1582 initializes the 16-byte local at 0x50
 *   literal: @1566 initializes the 16-byte local at 0x60
 *   literal: @1563 initializes the 16-byte local at 0x70
 */
/* dcomp: stackFrame_50 copies the 16-byte template @1582 that UpdateMyLump
 * also uses; it must be the one file-scope object of
 * blockers/tpltwo_My_src.patch's src patch (a local initializer here emits a
 * second, differently placed copy). */

extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern signed int SFX_AttachMdlMng(signed int, void *, unsigned short);
extern u32 V0[];
extern u32 L1582[];
extern u32 VX[];
extern u32 L1563[];
extern u32 L1566[];





/* SetMyControlOn @ 0x151650 .. 0x151660 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u8 MdlMng[];

/* SetScriptHeartBeat @ 0x151780 .. 0x151788 (0x8 bytes) */

extern u8 ScriptHeart;

/* StopHeartBeatSnd @ 0x151790 .. 0x1517D0 (0x40 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void SND_Stop(signed int);

extern int rand(void);


/* CheckMyEquipUpdate @ 0x151B70 .. 0x151BD4 (0x64 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00151B88
 */

extern u32 MyEquip[];
extern u32 MdlData[];

extern int FileCheckAsyncBusy(void);


/* FreeAllMyEquipSound @ 0x151C70 .. 0x151CAC (0x3c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern signed int SND_SecRemoveSpirit(signed int);

/* ReadAllMyEquipSound @ 0x151CB0 .. 0x151D0C (0x5c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00151CD0
 *   return without a value in a non-void function
 */

extern signed int SND_SecLoadSpirit(signed int, signed int);
extern u32 MyEquip[];

/* FreeAllMyEquip @ 0x151D90 .. 0x151EA0 (0x110 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x151da4 -> .L00151E68
 *   cfg: loop test does not fall through into its body: 0x151e50
 *   cfg: kept branch: 0x151e50 if (..) goto .L00151DB8
 *   cfg: kept goto: 0x151e68 -> .L00151E50
 */

extern void EneClearAllPullIn(void);
extern void EneClearAllPauseDamage(void);
extern void FreeMdlMng(void *);
extern void FreeMdlData(void *, signed int);

/* SetAllMyEquip @ 0x151EA0 .. 0x151F68 (0xc8 bytes, frame 0x60) */

extern void * memset(void *, int, unsigned int);
unsigned int SetMyEquip(void *lpMy, int button, int type, int id, int bFreeMdlData);
unsigned int SetMyEquip(void *lpMy, int button, int type, int id, int bFreeMdlData);



/* SetMyEquip @ 0x151FE0 .. 0x152308 (0x328 bytes, frame 0xd0) */
/*
 * dcomp notes:
 *   literal: @2955 is the string 'fu/p%03d.bnd'
 *   delay: daddu at 0x1520dc writes a register its branch at 0x1520d8 reads
 *   delay: addiu at 0x1520f8 writes a register its branch at 0x1520f4 reads
 *   delay: addiu at 0x152124 writes a register its branch at 0x152120 reads
 *   stack: address of the slot at 0xb0 escapes at 0x152228
 *   stack: address of the slot at 0xb0 escapes at 0x15224c
 *   delay: addiu at 0x152268 writes a register its branch at 0x152264 reads
 *   cfg: kept goto: 0x1520a8 -> .L001522D8
 *   cfg: kept branch: 0x1520b0 if (..) goto .L001520D0
 *   cfg: kept goto: 0x1520c0 -> .L001520D0
 *   cfg: kept branch: 0x1520f0 if (..) goto .L00152140
 *   cfg: loop body is not one contiguous region: .L00152110
 *   cfg: kept branch: 0x152110 if (..) goto .L00152130
 *   cfg: kept goto: 0x152124 -> .L00152148
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern void * GetEneParam(signed int, unsigned char);
extern int sprintf(void *, void *, ...);
extern void ReadMdlBndFile(char *, signed int, void *);
extern void FECard_CancelVanish(unsigned short);
extern u32 MySpiritBuf[];

#ifndef DCOMP_OFF_STRUCT_DW_407453_FIELDS_GAMEMODE_4A724316_DEFINED
#define DCOMP_OFF_STRUCT_DW_407453_FIELDS_GAMEMODE_4A724316_DEFINED
enum { DCOMP_OFF_STRUCT_DW_407453_FIELDS_GAMEMODE_4A724316 = (int)&(((struct dw_407453_fields *)0)->GameMode) - 0 };
#endif
typedef struct { u8 eq_type; u8 eq_flag; s16 eq_num; s32 eq_id; s32 eq_btn; } SMEQ;
typedef struct { SMEQ eq_e[2]; } SMEQROW;

static inline int SetMyEquipCheck(SMEQROW *row, SMEQ *slot, int type, int id) {
    SMEQ *p;
    int i;

    if (type == 0) {
        if (slot->eq_type == type) {
            return 1;
        }
    } else {
        p = row->eq_e;
        for (i = 0; i < 2; i++, p++) {
            if (p->eq_type == type && p->eq_id == id) {
                return 1;
            }
        }
    }
    return 0;
}

/* InitMyEquip @ 0x152310 .. 0x152a44 (0x734 bytes) */
typedef struct { u8 pad[0x1c0]; } MYMDL;
typedef struct {
    u8 Type;
    u8 bLoad;
    s16 Num;
    int Id;
    int Order;
} MYEQUIP_ENT;

static inline void MyEquipSet(MYEQUIP_ENT *pEquip, int idx, int Type, int Id) {
    MYEQUIP_ENT *pSlot = &pEquip[idx];
    s16 Num;
    u32 bFound;
    int i;

    Num = (Type == 1) ? GetSpiritNum(Id) : 1;
    if (Num != 0) {
        if (Type == 0) {
            if (pSlot->Type == Type) {
                bFound = 1;
                goto done;
            }
        } else {
            MYEQUIP_ENT *p = pEquip;
            for (i = 0; i < 2; i++, p++) {
                if (p->Type == Type && p->Id == Id) {
                    bFound = 1;
                    goto done;
                }
            }
        }
        bFound = 0;
    done:
        if (bFound == 0) {
            pSlot->Type = Type;
            pSlot->Id = Id;
            pSlot->Num = Num;
            pSlot->Order = idx;
        }
    }
}

static inline MYEQUIP_ENT *GetMyEquipTop(MYMDL *pModel) {
    return (MYEQUIP_ENT *)((u8 *)MyEquip + (pModel - &((MYMDL *)MdlMng)[0xa0]) * 0x18);
}


typedef struct StickFlags { unsigned char b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1; } StickFlags;

/* MyPadUpdate @ 0x152C80 .. 0x152D44 (0xc4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 1 parameters vs 2 inferred
 */

extern signed int CheckPadEnable(unsigned char);
extern void SetCamDirLockFlag(char, char);
extern u32 lpPadData;

#ifndef PROTO_DW_22229
#define PROTO_DW_22229
struct dw_22229 { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

/* MyPlay @ 0x152D50 .. 0x1530D0 (0x380 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40400000 at 0x152eac
 *   fpu: float literal 0x3fc90624 at 0x152eb0
 *   stack: address of the slot at 0x90 escapes at 0x152ec8
 *   fpu: float literal 0x3dcccccd at 0x152ef8
 *   stack: address of the slot at 0x70 escapes at 0x152f24
 *   fpu: float literal 0x3dcccccd at 0x152f3c
 *   stack: address of the slot at 0x60 escapes at 0x152f48
 *   fpu: float literal 0x3dcccccd at 0x152f60
 *   stack: address of the slot at 0x80 escapes at 0x152f70
 *   stack: address of the slot at 0x60 escapes at 0x152f70
 *   stack: address of the slot at 0x70 escapes at 0x152f70
 *   stack: address of the slot at 0x70 escapes at 0x152f80
 *   stack: address of the slot at 0x80 escapes at 0x152f80
 *   stack: address of the slot at 0x40 escapes at 0x152f80
 *   delay: addiu at 0x152f9c writes a register its branch at 0x152f98 reads
 *   fpu: float literal 0x40a00000 at 0x15301c
 *   cfg: loop body is not one contiguous region: .L00152E08
 *   cfg: kept branch: 0x152fd4 if (..) goto .L00153070
 *   cfg: loop body is not one contiguous region: .L00152FF8
 *   cfg: kept branch: 0x152ff8 if (..) goto .L00153038
 *   cfg: kept branch: 0x15300c if (..) goto .L00153038
 *   cfg: kept goto: 0x15302c -> .L00153058
 *   cfg: kept branch: 0x153060 if (..) goto .L001530B8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 Menu_TD_IsPlay();
extern void sceVu0CopyVector(void *, void *);
extern unsigned int GetCamCtrlMode(void);
extern void CheckMapEventData(void *);
extern void CheckAutoEvent(void *);
extern void CheckEneGetItem(void);
extern void MyThkPlay(void *, void *);
extern void MyActPlay(void *, void *);
extern signed int CheckLookAtEvent(void *, float, float, void *);
static void UpdateMyHead(struct umh_My *lpMy, int HeadId, float *TargetPos, int UpdateFlag);
static void UpdateMyHead(struct umh_My *, int, float *, int);
extern unsigned int CheckHitChar(void *);
extern void sceVu0SubVector(void *, void *, void *);
extern float CheckHitMapLineGetNormal(void *, void *, void *);
extern float Math_GetDist(float *, float *);
extern signed int CheckHeartBeatEvent(void *);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void SetPadVibHeart(void);

typedef struct { u8 pad[0x1c4]; s32 timer[2]; } CTRLX;


/* MyFree @ 0x1530D0 .. 0x153198 (0xc8 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern signed int CsMngFreeRtaData(unsigned int);
extern void SND_Stop(signed int);
extern void FreeMdlMng(void *);
extern void FreeMdlData(void *, signed int);
extern u32 MdlData[];
void SetMyLumpOn(void);

/* MyReset @ 0x1531A0 .. 0x153288 (0xe8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x153200
 *   fpu: mtc1 reinterprets v1 at 0x153214
 *   fpu: float literal 0x42c80000 at 0x15322c
 */

extern void SetMyLumpOn(void);
extern void FECard_SetFade(unsigned char, signed int);

extern void MyThkInit(u32, void *);
extern void MyActInit();
extern void DssPlay4Init(void *);
static u32 MyCtrlSt[0x74];



/* ReadMyMdl @ 0x153620 .. 0x1536C0 (0xa0 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   literal: @3616 is the string 'player/c%03d.bnd'
 *   literal: @3617 is the string 'player/c%03d_w%02d.bnd'
 *   stack: address of the slot at 0x20 escapes at 0x153640
 *   stack: address of the slot at 0x20 escapes at 0x153650
 *   stack: address of the slot at 0x20 escapes at 0x153688
 *   stack: address of the slot at 0x20 escapes at 0x153698
 */

extern int sprintf(void *, void *, ...);
extern void ReadMdlBndFile(char *, signed int, void *);
static u32 MyCtrlSt[0x74];
static u32 MyEquip[0x6];
static u32 MySpiritBuf[0x59998];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ReadMyMdl(void);
void MyAppear(signed int MyNo, u8 *lpMy, float *Pos, float AngY);
void MyReset(void *a0 );
u32 MyFree(void);
void MyPlay(void *a0 );
static void MyPadUpdate(struct dw_390841 *a0 , u8 *a1);
s8 ClearMyStruggleStick(s32 a0 , u8 *a1 );
void CheckMyStruggleStick(void *object, u8 *stick);
void * GetMyEquip(void *a0 , signed int a1 );
void InitMyEquip(void);
unsigned int SetMyEquip(void *lpMy, int button, int type, int id, int bFreeMdlData);
void GetMyEquipInfo(void *a0 , signed int a1 , signed int *a2 , signed int *a3 , signed int *t0 );
void SetAllMyEquip(void);
void FreeAllMyEquip(void);
u32 ChangeMyEquipSound(void);
u32 ReadAllMyEquipSound(void);
u32 FreeAllMyEquipSound(void);
unsigned int CheckMyEquipLoad(void *model, signed int type);
void CheckMyEquipUpdate(void);
void SetHeartRate(void *object,u32 amount,u8 mode);
void StopHeartBeatSnd(void *a0 );
void SetScriptHeartBeat(s32 a0 );
u32 CheckMyTired(u32 *a0 );
signed int CheckMyControlOff(void *a0 );
void SetMyControlOff(void);
u8 * SetMyControlOn(void);
signed int CheckMyEventStart(void *a0 );
void SetMyLumpOn(void);
void SetMyLumpOff(void);
void UpdateMyLump(void);
void InitMyWeapon(void);
void SetMyWeaponId(void *a0 , unsigned char a1 );
signed int CheckMyWeapon(void *a0 , u8 *a1);
u8 GetMyWeaponId(u32 *a0 );
void ChangeMyWeapon(void *model, void *parameter);
static void UpdateMyWep(void);
signed int CheckDrawMyWrist(void *a0 , signed int a1 );
void StabilizeMyCloth(void);
static void UpdateMyHead(struct umh_My *lpMy, int HeadId, float *TargetPos, int UpdateFlag);
unsigned int CheckMyHeadUpdate(void *a0 );
void SetMyDizzy(signed int a0 );
unsigned int CheckMyDash(void *a0 );
void SetMyMukadeMode(signed int CtrlId);
void SetMyNormalMode(void);
void SetMyTotterMode(signed int a0 );
u32 CheckMyMenuOpenDisable(void);
u32 CheckMyPauseDisable(void);
unsigned int CheckMyDizzyState(void *a0 , void *a1 );
u8 * SetMyCrouchDisable(s32 a0 );
u8 * SetMyActFreeFlag(s32 a0 );
u32 CheckMyBlastAnimEnable(void);


void ReadMyMdl(void) {
    u32 a1;
    u32 a0;
    s32 v1;
    u8 v0;
    s32 s0;
    u8 stackFrame_20[128] __attribute__((aligned(16)));

    v0 = GameSt[0x14];
    a1 = (u32)"player/c%03d.bnd";
    sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"player/c%03d.bnd", (u32)((u32)(v0) + 1));
    ReadMdlBndFile((char *)((u8 *)&stackFrame_20[0]), 0, (void *)0);
    v1 = 2;
    a0 = GameSt[0x14];
    s0 = 0;
    if (a0 != (u32)v1) {
        do {
            v0 = GameSt[0x14];
            a1 = (u32)"player/c%03d_w%02d.bnd";
            sprintf((void *)((u8 *)&stackFrame_20[0]), (void *)"player/c%03d_w%02d.bnd",
                (u32)((u32)(v0) + 1), (s32)(s0 + 1));
            ReadMdlBndFile((char *)((u8 *)&stackFrame_20[0]), s0 + 0x10c, (void *)0);
            s0 = s0 + 1;
            v1 = s0 < (s32)3;
        } while ((u32)v1 != 0);
    }
    return;
}
void MyAppear(signed int MyNo, u8 *lpMy, float *Pos, float AngY)
{
    u8 *s0;
    void *a1_s2;
    float f20;
    u32 v1;
    u8 *s1;
    float f1;
    float f0;
    u32 v0;
    signed int a0_2;
    float *a2_2;
    v0 = (u32)MdlData;
    v1 = (u32)MyNo * 0x680;
    s0 = (u8 *)Pos;
    a0_2 = (signed int)lpMy;
    f20 = (float)AngY;
    a1_s2 = (void *)((u8 *)MdlData + v1);
    v0 = SetMdlMng((void *)a0_2, a1_s2);
    if (v0 != 0) {
        a0_2 = (s32)(lpMy + 0x70);
        a1_s2 = lpMy + 0x20;
        *(float *)(lpMy + 0x20) = *(float *)s0;
        *(float *)(lpMy + 0x24) = *(float *)(s0 + 4);
        f0 = *(float *)(s0 + 8);
        *(float *)(lpMy + 0x28) = f0;
        *(float *)(lpMy + 0x34) = f20;
        sceVu0CopyVector((void *)a0_2, a1_s2);
        a0_2 = (s32)(lpMy + 0x80);
        a1_s2 = lpMy + 0x30;
        sceVu0CopyVector((void *)a0_2, a1_s2);
        v1 = (u32)(MdlMng + 0x11800);
        a2_2 = (float *)0x1d0;
        v0 = (u32)MyCtrlSt;
        a0_2 = (s32)(lpMy - v1) / 0x1c0;
        v1 = (u32)a0_2 * 0x1d0;
        s1 = (u8 *)MyCtrlSt + v1;
        a0_2 = (s32)s1;
        memset((void *)a0_2, 0, (unsigned int)a2_2);
        *(u32 *)(lpMy + 0x148) = (s32)s1;
        v1 = GameSt[0x14];
        v0 = 2;
        switch (v1) {
        case 0: v0 = 0x1a; *(u8 *)(s1 + 0x191) = v0; break;
        case 1: v0 = 0x10; *(u8 *)(s1 + 0x191) = v0; break;
        case 2: v0 = 0x11; *(u8 *)(s1 + 0x191) = v0; break;
        }
        v0 = *(s32 *)(lpMy + 0xc);
        s0 = (u8 *)*(s32 *)(v0 + 0x4c);
        f1 = (float)(u32)*(u16 *)(s0 + 0x20);
        a0_2 = (s32)(lpMy + 0x40);
        a1_s2 = (void *)a0_2;
        AngY = f1 / 100.0f;
        sceVu0ScaleVectorXYZ((void *)a0_2, a1_s2, AngY);
        f1 = (float)(u32)*(u16 *)(s0 + 0x16) / 100.0f;
        *(float *)(lpMy + 0x110) = f1 * *(float *)(lpMy + 0x40);
        f1 = (float)(u32)*(u16 *)(s0 + 0x18) / 100.0f;
        *(float *)(lpMy + 0x114) = f1 * *(float *)(lpMy + 0x44);
        v0 = *(u16 *)(s0 + 0x24);
        if (v0 == 0) { v0 = 100; *(u16 *)(s0 + 0x24) = v0; }
        f1 = (float)(u32)*(u16 *)(s0 + 0x24) / 100.0f;
        *(float *)(lpMy + 0x118) = f1 * *(float *)(lpMy + 0x40);
        f1 = (float)(u32)*(u16 *)(s0 + 0x28) / 100.0f;
        *(float *)(lpMy + 0x11c) = f1 * *(float *)(lpMy + 0x40);
        *(u8 *)(lpMy + 0x129) = 0;
        v0 = *(u8 *)(lpMy + 0x129);
        *(u8 *)(lpMy + 0x128) = v0;
        v0 = *(s32 *)(s0 + 4);
        *(u32 *)(lpMy + 0x120) = v0;
        v0 = *(s32 *)(lpMy + 0x120);
        *(u32 *)(s1 + 0x19c) = v0;
        v0 = GameSt[0x1d];
        if (v0 != 0) {
            v0 = (u32)GetSaveData();
            v0 = *(u8 *)(v0 + 0x19);
            *(u32 *)(lpMy + 0x120) = v0;
        }
        a0_2 = (s32)lpMy;
        a1_s2 = s1;
        SetMyStay((void *)a0_2, a1_s2, 0);
        PlayMi3(lpMy);
        v0 = -1;
        a0_2 = (s32)lpMy;
        *(u32 *)(s1 + 0x194) = v0;
        a1_s2 = s1;
        *(u32 *)(s1 + 0x1c0) = v0;
        MyThkInit(a0_2, a1_s2);
        a1_s2 = s1;
        MyActInit(lpMy, a1_s2);
        v1 = *(s32 *)(*(s32 *)(lpMy + 0xc) + 0x48);
        a0_2 = (s32)lpMy;
        if (v1 != 0) DssPlay4Init((void *)a0_2);
    }
}

void MyReset(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 v0;
    float f1;

    s1 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    *(u32 *)(s0 + 0x198) = -1;
    SetMyLumpOn();
    *(u8 *)(s0 + 0x18a) = 0;
    *(u8 *)(s0 + 0x189) = 0;
    *(u32 *)(s0 + 0x1b4) = 0;
    *(u8 *)(s1 + 0x133) = 0;
    v0 = *(s32 *)(MdlMng + 0x11948);
    *(u8 *)((v0 + 0x1b3)) = 0;
    v0 = *(u8 *)(s0 + 0x190);
    if (v0 != 0) {
        v0 = *(s32 *)(s1 + 0xc);
        v0 = *(s32 *)((v0 + 0x4c));
        v0 = *(u16 *)((v0 + 0x18));
        a0 = (void *)(s32)2;
        f1 = 100.0f;
        *(f32 *)(s1 + 0x114) = (((float)(float)v0 / 100.0f) * *(float *)(s1 + 0x44));
        FECard_SetFade((unsigned char)a0, 1);
        *(u8 *)(s0 + 0x190) = 0;
    }
    v0 = *(u8 *)(s0 + 0x18d);
    if (v0 != 0) {
        *(u8 *)(s0 + 0x18d) = 0;
        v0 = *(s32 *)(s0 + 0x19c);
        *(u32 *)(s1 + 0x120) = v0;
    }
    ScriptHeart = 0;
    SetMyPadMode(0);
    return;
}

u32 MyFree(void) {
    u32 *s4;
    u32 a0;
    u8 *s3;
    u8 *s2;
    u8 *s1;
    u32 s0;
    s32 v0;
    s32 a1;
    s32 v1;

    s4 = (u32 *)((u8 *)MdlMng + 0x11800);
    a0 = (u32)s4;
    s3 = (u8 *)MdlData;
    s2 = (u8 *)MdlMng + 0x52240;
    s1 = (u8 *)MdlData + 0x6ce00;
    CsMngFreeRtaData(a0);
    s0 = *(s32 *)(((u8 *)s4 + 0x148));
    v0 = -1;
    a0 = *(s32 *)((s0 + 0x194));
    if (a0 != (u32)v0) {
        SND_Stop(a0);
        v0 = -1;
        *(u32 *)((s0 + 0x194)) = v0;
    }
    a0 = (u32)s4;
    FreeMdlMng((void *)a0);
    a0 = (u32)s3;
    a1 = 1;
    FreeMdlData((void *)a0, a1);
    s0 = 0;
    do {
        a0 = (u32)s2;
        FreeMdlMng((void *)a0);
        a0 = (u32)s1;
        a1 = 1;
        FreeMdlData((void *)a0, a1);
        s0 = s0 + 1;
        s2 = (u8 *)(s32)((u8 *)s2 + 0x1c0);
        v1 = (s32)s0 < (s32)3;
        s1 = (u8 *)(s32)((u8 *)s1 + 0x680);
    } while ((u32)v1 != 0);
    return;
}
void MyPlay(void *a0 /* r4 */) {
    u8 *s2;
    u8 *s1;
    u32 a1;
    s32 i;
    u8 *s0;
    u32 a0_index; // a0
    u32 v1;
    float f1;
    float f0;
    u32 v0;
    u8 stackFrame_90[16] __attribute__((aligned(16)));
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_40[32] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    v1 = GameSt[0xf];
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x4c));
    if (v1 == 0) {
        v0 = Menu_TD_IsPlay();
        if (v0 == 0 && *(u8 *)s2 != 0) {
            a0 = (void *)(s2 + 0x70);
            sceVu0CopyVector(a0, (void *)(s2 + 0x20));
            a0 = (void *)(s2 + 0x80);
            sceVu0CopyVector(a0, (void *)(s2 + 0x30));
            v0 = *(s32 *)(s2 + 0x124);
            v0 = v0 + 1;
            *(u32 *)(s2 + 0x124) = v0;
            v0 = *(s16 *)(s2 + 0x12c);
            if (v0 != 0) {
                v0 = v0 + -1;
                *(u16 *)(s2 + 0x12c) = v0;
            }
            v0 = *(s16 *)(s2 + 0x12e);
            if ((s32)v0 > 0) {
                v0 = v0 + -1;
                *(u16 *)(s2 + 0x12e) = v0;
            }
            v0 = *(u16 *)(s1 + 0x1cc);
            if (v0 != 0) {
                v0 = v0 + -1;
                *(u16 *)(s1 + 0x1cc) = v0;
            }
            for (i = 0; i < 2; i++) {
                if (((CTRLX *)s1)->timer[i] != 0) {
                    ((CTRLX *)s1)->timer[i]--;
                }
            }
            a0 = (void *)s2;
            MyPadUpdate((struct dw_390841 *)a0, (u8 *)s1);
            v0 = GetCamCtrlMode();
            v1 = 2;
            a0 = (void *)s2;
            if (v0 != v1) {
                CheckMapEventData(a0);
            }
            a0 = (void *)s2;
            CheckAutoEvent(a0);
            CheckEneGetItem();
            v0 = *(u8 *)(s1 + 0x102);
            a0 = (void *)s2;
            if (v0 == 0) {
                MyThkPlay(a0, (void *)s1);
                a0 = (void *)s2;
                MyActPlay(a0, (void *)s1);
            }
            a0 = (void *)(s1 + 0x140);
            sceVu0CopyVector(a0, (void *)(s2 + 0x20));
            a0 = (void *)s2;
            MasterMove(a0);
            a0 = (void *)s2;
            v0 = CheckLookAtEvent(a0, 3.0f, 1.5704999f, (void *)((u8 *)&stackFrame_90[0]));
            a1 = *(u8 *)(s0 + 0x27);
            a0 = (void *)s2;
            UpdateMyHead(a0, a1, (float *)((u8 *)&stackFrame_90[0]), v0);
            UpdateMyWep();
            a0 = (void *)s2;
            CheckHitChar(a0);
            v0 = *(u8 *)(s2 + 0x131);
            if (v0 == 0) {
                v0 = 0x3dcccccd;
                f0 = 0.100000001f;
                *(f32 *)(s2 + 0x24) = (*(float *)(s2 + 0x24) + f0);
            }
            v0 = *(u8 *)(s2 + 0x132);
            a0 = (void *)s2;
            if (v0 == 0) {
                v0 = CheckHitMap(a0);
                *(u32 *)(s2 + 0x134) = v0;
            }
            sceVu0CopyVector((void *)((u8 *)&stackFrame_70[0]), (void *)(s2 + 0x70));
            f0 = 0.100000001f;
            ((f32 *)stackFrame_70)[1] = (((float *)stackFrame_70)[1] - 0.100000001f);
            sceVu0CopyVector((void *)((u8 *)&stackFrame_60[0]), (void *)(s2 + 0x20));
            f0 = 0.100000001f;
            ((f32 *)stackFrame_60)[1] = (((float *)stackFrame_60)[1] - 0.100000001f);
            sceVu0SubVector((void *)((u8 *)&stackFrame_80[0]), (void *)((u8 *)&stackFrame_60[0]),
                (void *)((u8 *)&stackFrame_70[0]));
            CheckHitMapLineGetNormal((void *)((u8 *)&stackFrame_70[0]), (void *)((u8
                *)&stackFrame_80[0]), (void *)((u8 *)&stackFrame_40[0]));
            v1 = ((s32 *)stackFrame_40)[4];
            *(u32 *)(s1 + 0x1b8) = v1;
            v1 = *(s32 *)(s2 + 0x134);
            v1 = v1 & 0x1000;
            if (v1 != 0) {
                v1 = 0xb4;
                *(u16 *)(s1 + 0x1ce) = v1;
            }
            v1 = *(u16 *)(s1 + 0x1ce);
            if (v1 != 0) {
                v1 = v1 + -1;
                *(u16 *)(s1 + 0x1ce) = v1;
            }
            s1 = (u8 *)*(s32 *)(s2 + 0x148);
            v1 = *(s32 *)(s1 + 0x1a0);
            if ((s32)v1 <= (s32)0x14) {
                v1 = ScriptHeart;
                if (v1 != 0) {
                    goto _L00153070;
                }
                s0 = (u8 *)(MdlMng + 0x119c0);
                v1 = (u32)(u8 *)(MdlMng + 0x17140);
                if ((u32)s0 != v1) {
                    do {
                        v1 = *(u8 *)s0;
                        if (v1 == 0 || (s32)*(s32 *)(s0 + 0x120) <= 0) {
                            goto _L00153038;
                        }
                        a0 = (void *)(s2 + 0x20);
                        f0 = Math_GetDist((float *)a0, (float *)(s0 + 0x20));
                        f1 = 5.0f;
                        if (!(f0 <= 5.0f)) {
                            goto _L00153038;
                        }
                        v1 = 1;
                        goto _L00153058;
                        _L00153038:;
                        s0 = (u8 *)(s0 + 0x1c0);
                    } while (s0 != (u8 *)(MdlMng + 0x17140));
                }
                v1 = 0;
                _L00153058:;
                a0 = (void *)s2;
                if (v1 == 0) {
                    v0 = CheckHeartBeatEvent(a0);
                    if (v0 == 0) {
                        goto _L001530B8;
                    }
                }
            }
            _L00153070:;
            v1 = *(s32 *)(s1 + 0x1a4);
            a0 = (void *)(s32)0xbb9;
            if (v1 == 0) {
                a1 = 0x64;
                SND_Play2D((signed int)a0, a1, 0);
                SetPadVibHeart();
                v1 = 0x3c;
                *(u32 *)(s1 + 0x1a8) = v1;
            }
            v1 = *(s32 *)(s1 + 0x1a4);
            a0_index = v1 + (u32)1;
            *(u32 *)(s1 + 0x1a4) = a0_index;
            v1 = *(s32 *)(s1 + 0x1a8);
            v1 = (s32)a0_index < (s32)v1;
            if (v1 == 0) {
                *(u32 *)(s1 + 0x1a4) = 0;
            }
        }
    }
    _L001530B8:;
    return;
}

static void MyPadUpdate(struct dw_390841 *a0 /* r4 */, u8 *a1) {
    u8 *s0;
    u32 v0;

    v0 = (u32)&lpPadData;
    *(u32 *)(a1 + 0x110) = *(s32 *)(s32)((u8 *)&lpPadData + (u32)((u32)GameSt[0xa] << 2));
    a0 = (void *)((struct dw_22229 *)&GameSt)->padport;
    s0 = a1;
    v0 = CheckPadEnable((u8)a0);
    if (v0 != 0) {
        *(u8 *)(s0 + 0x114) = (u32)(*(u8 *)((*(s32 *)(s0 + 0x110) + 6))) + -0x80;
        *(u8 *)(s0 + 0x115) = (u32)(*(u8 *)((*(s32 *)(s0 + 0x110) + 7))) + -0x80;
        *(u8 *)(s0 + 0x116) = (u32)(*(u8 *)((*(s32 *)(s0 + 0x110) + 4))) + -0x80;
        *(u8 *)(s0 + 0x117) = (u32)(*(u8 *)((*(s32 *)(s0 + 0x110) + 5))) + -0x80;
    } else {
        *(u8 *)(s0 + 0x114) = 0;
        *(u8 *)(s0 + 0x115) = 0;
        *(u8 *)(s0 + 0x116) = 0;
        *(u8 *)(s0 + 0x117) = 0;
        *(u8 *)(s0 + 0x118) = 0;
        *(u8 *)(s0 + 0x119) = 0;
        *(u8 *)(s0 + 0x11a) = 0;
        *(u8 *)(s0 + 0x11b) = 0;
    }
    SetCamDirLockFlag(*(s8 *)(s0 + 0x115), *(s8 *)(s0 + 0x114));
    return;
}


/* ClearMyStruggleStick @ 0x152C40 .. 0x152C74 (0x34 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */

s8 ClearMyStruggleStick(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    s8 v1;

    *(u16 *)(((u8 *)a1 + 0x11c)) = 0;
    *(u16 *)(((u8 *)a1 + 0x120)) = 0;
    v1 = *(s8 *)(((u8 *)a1 + 0x114));
    *(u8 *)(((u8 *)a1 + 0x118)) = v1;
    v1 = *(s8 *)(((u8 *)a1 + 0x115));
    *(u8 *)(((u8 *)a1 + 0x119)) = v1;
    *(u16 *)(((u8 *)a1 + 0x11e)) = 0;
    *(u16 *)(((u8 *)a1 + 0x122)) = 0;
    v1 = *(s8 *)(((u8 *)a1 + 0x116));
    *(u8 *)(((u8 *)a1 + 0x11a)) = v1;
    v1 = *(s8 *)(((u8 *)a1 + 0x117));
    *(u8 *)(((u8 *)a1 + 0x11b)) = v1;
    return;
}
void CheckMyStruggleStick(void *object, u8 *stick) {
    u32 three=3, five=5;
    u16 amount=5, bonus=10;
    u32 state=GameSt[0x18];
    switch(state) {
    case 2: amount=(u16)three; bonus=(u16)five; break;
    case 3: amount=1; bonus=amount; break;
    }
    *(u16 *)(stick+0x120)=*(u16 *)(stick+0x11c);
    {
        u32 delta=*(s8 *)(stick+0x118)-*(s8 *)(stick+0x114);
        delta=(s32)delta<0?-delta:delta;
        if((s32)delta>50) goto left_update;
        delta=*(s8 *)(stick+0x119)-*(s8 *)(stick+0x115);
        delta=(s32)delta<0?-delta:delta;
        if((s32)delta>50) {
left_update:
        *(u16 *)(stick+0x11c)+=amount;
        *(s8 *)(stick+0x118)=*(s8 *)(stick+0x114);
        *(s8 *)(stick+0x119)=*(s8 *)(stick+0x115);
        }
    }
left_done:
    *(u16 *)(stick+0x122)=*(u16 *)(stick+0x11e);
    {
        u32 delta=*(s8 *)(stick+0x11a)-*(s8 *)(stick+0x116);
        delta=(s32)delta<0?-delta:delta;
        if((s32)delta>50) goto right_update;
        delta=*(s8 *)(stick+0x11b)-*(s8 *)(stick+0x117);
        delta=(s32)delta<0?-delta:delta;
        if((s32)delta>50) {
right_update:
        *(u16 *)(stick+0x11e)+=amount;
        *(s8 *)(stick+0x11a)=*(s8 *)(stick+0x116);
        *(s8 *)(stick+0x11b)=*(s8 *)(stick+0x117);
        }
    }
right_done:
    {
        StickFlags *flags=(StickFlags *)(*(u8 **)(stick+0x110)+0x21);
        if(flags->b6 || flags->b7 || flags->b5 || flags->b4) {
            *(u16 *)(stick+0x11c)+=bonus;
            *(u16 *)(stick+0x11e)+=bonus;
        }
    }
}


/* GetMyEquip @ 0x152A50 .. 0x152AB0 (0x60 bytes) */
/*
 * dcomp notes:
 *   return: addu at 0x152aac computes the return value
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * GetMyEquip(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v1;

    v1 = (u32)MyEquip;
    return (void *)(s32)((u32)((u32)a1 * 0xc) + (u32)(s32)((u8 *)MyEquip + (s32)((u32)((s32)((u8
        *)a0 - (u32)(u8 *)(MdlMng + 0x11800)) / 0x1c0) * 0x18)));
}

void InitMyEquip(void) {
    int i;
    MYMDL *lpMy;
    u8 *lpSaveData;
    int Type;
    int Id;
    MYEQUIP_ENT *pEquip;

    lpMy = (MYMDL *)(MdlMng + 0x11800);
    pEquip = GetMyEquipTop(lpMy);
    memset(pEquip, 0, 0x18);
    if (GameSt[0x1d] == 0) {
        if (GameSt[0x19] != 0) {
            ItemMng_Add_Direct(0x32e1, 0x1e);
            ItemMng_Add_Direct(0x32e2, 0xa);
            ItemMng_Add_Direct(0x36cd, 2);
            AddSpiritNum(2, 0x1e, 1);
            AddSpiritNum(3, 0x1e, 1);
            AddSpiritNum(4, 0x1e, 1);
            AddSpiritNum(5, 0x63, 1);
            AddSpiritNum(6, 0x32, 1);
            AddSpiritNum(7, 0x1e, 1);
            AddSpiritNum(8, 0x32, 1);
            AddSpiritNum(9, 0x63, 1);
            AddSpiritNum(0xa, 0x32, 1);
            AddSpiritNum(0xc, 0x63, 1);
            AddSpiritNum(0xe, 0x14, 1);
            AddSpiritNum(0x12, 0x1e, 1);
            AddSpiritNum(0x13, 0x3c, 1);
            AddSpiritNum(0x14, 0x3c, 1);
            AddSpiritNum(0x15, 0x1e, 1);
            AddSpiritNum(0x19, 0x1e, 1);
            AddSpiritNum(0x1a, 0x14, 1);
            AddSpiritNum(0x1b, 0x14, 1);
            AddSpiritNum(0x1d, 0x14, 1);
            AddSpiritNum(0x1e, 0x14, 1);
            AddSpiritNum(0x24, 0x14, 1);
            AddSpiritNum(0x26, 0x28, 1);
        }
        switch (GameSt[0x14]) {
        case 0:
            if (GameSt[0x19] != 0) {
                ItemMng_Add_Direct(0x9c42, 1);
                ItemMng_Add_Direct(0x9c43, 1);
            } else {
                ItemMng_Add_Direct(0x32e1, 2);
                ItemMng_Add_Direct(0x36cd, 2);
            }
            ItemMng_Add_Direct(0x2ee3, 1);
            ItemMng_Add_Direct(0x4e22, 1);
            ItemMng_Add_Direct(0x9c41, 1);
            MyEquipSet(pEquip, 0, 0, 0);
            MyEquipSet(pEquip, 1, 0, 0);
            break;
        case 1:
            if (GameSt[0x19] != 0) {
                ItemMng_Add_Direct(0x9c45, 1);
                ItemMng_Add_Direct(0x9c46, 1);
            } else {
                AddSpiritNum(5, 6, 1);
                AddSpiritNum(9, 0x18, 1);
                ItemMng_Add_Direct(0x32e1, 2);
                ItemMng_Add_Direct(0x36cd, 2);
            }
            ItemMng_Add_Direct(0x4e21, 1);
            ItemMng_Add_Direct(0x9c44, 1);
            MyEquipSet(pEquip, 0, 1, 5);
            MyEquipSet(pEquip, 1, 1, 9);
            break;
        case 2:
            if (GameSt[0x19] == 0) {
                AddSpiritNum(0xc, 0x24, 1);
                AddSpiritNum(0x12, 9, 1);
                AddSpiritNum(0x1d, 5, 1);
                AddSpiritNum(0x1e, 5, 1);
                AddSpiritNum(0x26, 0x12, 1);
                ItemMng_Add_Direct(0x32e1, 7);
                ItemMng_Add_Direct(0x32e2, 3);
                ItemMng_Add_Direct(0x36cd, 3);
            }
            ItemMng_Add_Direct(0x2eff, 1);
            ItemMng_Add_Direct(0x9c47, 1);
            MyEquipSet(pEquip, 0, 1, 0xc);
            MyEquipSet(pEquip, 1, 1, 0x1d);
            break;
        }
        GameSt[0x1b] = 0;
    } else {
        lpSaveData = (u8 *)GetSaveData();
        for (i = 0; i < 2; i++) {
            u8 *q = lpSaveData + i;
            Type = q[0x12];
            Id = q[0x15];
            MyEquipSet((MYEQUIP_ENT *)(u32)pEquip, i, Type, Id);
        }
        GameSt[0x1b] = lpSaveData[0x1c];
    }
}

unsigned int SetMyEquip(void *lpMy, int button, int type, int id, int bFreeMdlData) {
    u8 *lpPrm;
    short EquipNum;
    int ReadFlag;
    unsigned short btn;
    u8 *lpCtrl;
    SMEQROW *row;
    SMEQ *slot;
    SMEQ *cur;
    u8 *model;
    u8 *data;
    char name[32];

    row = (SMEQROW *)MyEquip + ((s32)lpMy - (s32)(MdlMng + 0x11800)) / 0x1c0;
    slot = &row->eq_e[button];
    ReadFlag = 0;
    if (type == 1) {
        EquipNum = GetSpiritNum(id);
        lpPrm = (u8 *)GetEneParam(id, 0);
        if (lpPrm == 0) {
            return 0;
        }
        if (*(u16 *)(lpPrm + 0x2a) == 0) {
            ReadFlag = 1;
        }
    } else {
        EquipNum = 1;
    }
    if (EquipNum == 0) {
        return 0;
    }
    if (SetMyEquipCheck(row, slot, type, id)) {
        return 0;
    }
    cur = (SMEQ *)MyEquip + button;
    if (cur->eq_id == 7) {
        EneClearAllPullIn();
    }
    if (cur->eq_id == 8) {
        EneClearAllPauseDamage();
    }
    model = (u8 *)MdlMng + (button + 0xd3) * 0x1c0;
    data = (u8 *)MdlData + (button + 0x14) * 0x680;
    if (*model != 0) {
        FreeMdlMng(model);
    }
    if (bFreeMdlData && *(s32 *)(data + 0x10) != 0) {
        FreeMdlData(data, 0);
    }
    slot->eq_type = type;
    slot->eq_id = id;
    slot->eq_num = EquipNum;
    slot->eq_btn = button;
    if (ReadFlag) {
        sprintf(name, (void *)sMyEquipBndFmt, slot->eq_id);
        ReadMdlBndFile(name, button + 0x14, (u8 *)MySpiritBuf + button * 0xb3330);
    }
    if (GameSt[(DCOMP_OFF_STRUCT_DW_407453_FIELDS_GAMEMODE_4A724316 / 1)] == 2) {
        switch (button) {
        case 0:
            btn = 1;
            break;
        case 1:
            btn = 0;
            break;
        default:
            btn = 1;
        }
        FECard_CancelVanish(btn);
        lpCtrl = (u8 *)*(s32 *)((u8 *)lpMy + 0x148);
        if (lpCtrl != 0 && lpCtrl[0x100] == 3) {
            SetMyStay(lpMy, lpCtrl, 0);
        }
    }
    return 1;
}

/* GetMyEquipInfo @ 0x151F70 .. 0x151FE0 (0x70 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred s16
 */

void GetMyEquipInfo(void *a0 /* r4 */, signed int a1 /* r5 */, signed int *a2 /* r6 */, signed int
        *a3 /* r7 */, signed int *t0 /* r8 */) {
    u32 v1;
    s32 t2;

    t2 = (s32)((u8 *)a0 - (u32)((u8 *)MdlMng + 0x11800));
    v1 = -0x6db6db6d;
    a0 = (void *)MyEquip;
    a0 = (void *)((u8 *)MyEquip + (s32)((u32)(t2 / (s32)(0x1c0)) * (u32)(0x18)));
    a0 = (void *)((u8 *)(u32)((u32)a1 * (u32)(0xc)) + (u32)(a0));
    v1 = *(u8 *)a0;
    *(u32 *)a2 = v1;
    v1 = *(s32 *)(((u8 *)a0 + 4));
    *(u32 *)a3 = v1;
    v1 = *(s16 *)(((u8 *)a0 + 2));
    *(u32 *)t0 = v1;
    return;
}

void SetAllMyEquip(void) {
    s32 v1;
    u32 v0;
    s32 s1;
    s32 s4;
    u32 s3;
    struct dw_383276 *s0;
    u8 *s2;

    v0 = -0x6db70000;
    v1 = -0x6db70000 | 0x2493;
    v0 = (u32)MyEquip;
    s0 = (struct dw_383276 *)(u8 *)(MdlMng + 0x11800);
    s1 = 0;
    s2 = (u8 *)((u8 *)MyEquip + (s32)((u32)((s32)((u8 *)(u8 *)s0 - (u32)((u8 *)s0)) / (s32)(0x1c0))
        * (u32)(0x18)));
    do {
        s4 = *(u8 *)s2;
        s3 = *(s32 *)(s2 + 4);
        memset((void *)s2, 0, 0xc);
        SetMyEquip((void *)(u8 *)s0, s1, s4, s3, 1);
        s1 = s1 + 1;
        v1 = s1 < (s32)2;
        s2 = (u8 *)(s2 + 0xc);
    } while ((u32)v1 != 0);
    return;
}

void FreeAllMyEquip(void) {
    s32 s3;
    u8 *s4;
    s32 a2;
    u32 a1;
    u8 *s2;
    u32 a0;
    u32 s1;
    u32 v1;
    u32 s0;

    s3 = 0;
    goto _L00151E68;
    _L00151DB8:;
    a0 = *(s32 *)(s2 + 4);
    v1 = 7;
    if (a0 == v1) {
        EneClearAllPullIn();
    }
    a0 = *(s32 *)(s2 + 4);
    v1 = 8;
    if (a0 == v1) {
        EneClearAllPauseDamage();
    }
    v1 = 0x17140;
    a0 = (u32)MdlMng;
    {
        u32 dcomp_tmp_0;
        dcomp_tmp_0 = s0 + 0x7fff;
        v1 = dcomp_tmp_0;
    }
    a0 = (s32)((u8 *)MdlMng + (u32)(s1 + 0x17140));
    a2 = v1 + 0x201;
    v1 = *(u8 *)a0;
    a1 = (u32)MdlData;
    s4 = (u8 *)((u8 *)MdlData + a2);
    if (v1 != 0) {
        FreeMdlMng((void *)a0);
    }
    v1 = *(s32 *)(s4 + 0x10);
    a0 = (s32)s4;
    if (v1 != 0) {
        FreeMdlData((void *)a0, 0);
    }
    s2 = (u8 *)(s2 + 0xc);
    s1 = s1 + 0x1c0;
    s0 = s0 + 0x680;
    s3 = s3 + 1;
    _L00151E50:;
    v1 = s3 < (s32)2;
    if (v1 != 0) {
        goto _L00151DB8;
    }
    return;
    _L00151E68:;
    s2 = (u8 *)MyEquip;
    s1 = 0;
    s0 = 0;
    goto _L00151E50;
    return;
}

/* ChangeMyEquipSound @ 0x151D10 .. 0x151D8C (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00151D50
 *   return without a value in a non-void function
 */




u32 ChangeMyEquipSound(void) {
    u32 s0;
    u32 a0;
    u32 v1;
    s32 s1;
    u32 a1;

    s0 = 0;
    do {
        a0 = s0;
        SND_SecRemoveSpirit(a0);
        s0 = s0 + 1;
        v1 = (s32)s0 < (s32)2;
    } while (v1 != 0);
    s1 = 0;
    s0 = (u32)MyEquip;
    do {
        v1 = *(u8 *)s0;
        if (v1 != 0) {
            a1 = *(s32 *)((s0 + 4));
            a0 = s1;
            SND_SecLoadSpirit(a0, a1);
        }
        s1 = s1 + 1;
        v1 = s1 < (s32)2;
        s0 = s0 + 0xc;
    } while (v1 != 0);
    return;
}

u32 ReadAllMyEquipSound(void) {
    s32 s1;
    u8 *s0;
    u32 v1;
    u32 a1;

    s1 = 0;
    s0 = (u8 *)MyEquip;
    do {
        v1 = *(u8 *)s0;
        if (v1 != 0) {
            a1 = *(s32 *)(((u8 *)s0 + 4));
            SND_SecLoadSpirit((u32)s1, a1);
        }
        s1 = s1 + 1;
        v1 = s1 < (s32)2;
        s0 = (u8 *)(s32)((u8 *)s0 + 0xc);
    } while (v1 != 0);
    return;
}

u32 FreeAllMyEquipSound(void) {
    u32 s0;
    s32 v1;

    s0 = 0;
    do {
        SND_SecRemoveSpirit((u32)s0);
        s0 = s0 + 1;
        v1 = (s32)s0 < (s32)2;
    } while (v1 != 0);
    return;
}
unsigned int CheckMyEquipLoad(void *model, signed int type) {
    s32 index = ((s32)model - (s32)(MdlMng + 0x11800)) / 0x1c0;
    u8 *equip = (u8 *)MyEquip + index * 24 + type * 12;
    u32 result;
    if (FileCheckAsyncBusy()) result = 1;
    else result = equip[1];
    return result;
}

void CheckMyEquipUpdate(void) {
    s32 a3;
    u8 *a2;
    u8 *a1;
    s32 a0;
    u32 v1;
    s32 at;

    a2 = (u8 *)MyEquip;
    a3 = 0;
    a1 = (u8 *)MdlData;
    a0 = 1;
    do {
        v1 = *(u8 *)(a2 + 1);
        if (v1 != 0 && (u32)*(u8 *)a2 == (u32)a0 && (u32)*(s32 *)(a1 + 0x8210) != 0) {
            at = 0x10000;
            at = (s32)(a1 + (s32)at);
            *(u8 *)(a2 + 1) = 0;
        }
        a3 = a3 + 1;
        v1 = a3 < (s32)2;
        a1 = (u8 *)(a1 + 0x680);
        a2 = (u8 *)(a2 + 0xc);
    } while (v1 != 0);
    return;
}
void SetHeartRate(void *object,u32 amount,u8 mode) {
    u8 *obj=object;
    s32 delta=amount;
    u8 *ctrl=*(u8 **)(obj+0x148);
    if (!ctrl[0x18f]) {
        switch(mode) {
        case 0: {
            float variation;
            s32 current, next;
            float rounded;
            if (rand()%10<=4) variation=(float)(rand()%30)/100.0f;
            else variation=-((float)(rand()%30)/100.0f);
            current=*(s32 *)(obj+0x120);
            rounded=({float value; __asm__("cvt.w.s %0,%1" : "=f"(value) : "f"((float)delta*(1.0f+variation))); value;});
            next=current-({s32 value; __asm__("mfc1 %0,%1" : "=r"(value) : "f"(rounded));value;});
            if (current>30 && next<=30) *(s32 *)(obj+0x120)=30;
            else *(s32 *)(obj+0x120)=next;
            if (GameSt[0x1a]==1) {
                if (++GameSt[0x1b]==9) *(s32 *)(obj+0x120)=0;
            } else if (GameSt[0x1a]==2) *(s32 *)(obj+0x120)=0;
            break;
        }
        case 1: {
            s32 rate=*(s32 *)(ctrl+0x1a0);
            if (rate<=28 && *(u32 *)(obj+0x124)%60==0) *(s32 *)(ctrl+0x1a0)=rate+delta;
            if (!ctrl[0x189]) {
                rate=*(s32 *)(ctrl+0x1a0);
                if (rate>=30 && *(u32 *)(obj+0x124)%15==0) *(s32 *)(ctrl+0x1a0)=rate-delta;
            }
            break;
        }
        case 2:
            if (!ctrl[0x189] && *(u32 *)(obj+0x124)%15==0) *(s32 *)(ctrl+0x1a0)-=delta;
            break;
        case 7:
            if (*(u32 *)(obj+0x124)%5==0) { *(s32 *)(obj+0x120)+=delta; *(s32 *)(ctrl+0x1a0)-=delta; }
            break;
        case 6: *(s32 *)(ctrl+0x1a0)+=delta; break;
        case 9: *(s32 *)(obj+0x120)+=delta; ctrl[0x1ac]=0; break;
        }
        {
            s32 rate=*(s32 *)(obj+0x120);
            if (rate<0) *(s32 *)(obj+0x120)=0;
            else { s32 maximum=*(s32 *)(ctrl+0x19c); if (maximum<rate) *(s32 *)(obj+0x120)=maximum; }
        }
        if (*(s32 *)(ctrl+0x1a0)<0) *(s32 *)(ctrl+0x1a0)=0;
        if (*(s32 *)(ctrl+0x1a0)<=20) ctrl[0x1b0]=0;
        if (ctrl[0x1ac] && *(s32 *)(ctrl+0x1a0)<=29) ctrl[0x1ac]=0;
        {
            s32 dizzy;
            if (*(s32 *)(obj+0x120)>30) {
                if (!ctrl[0x1ac]) goto not_dizzy;
            }
            dizzy=1;
            goto set_dizzy;
        not_dizzy:
            dizzy=0;
        set_dizzy:
            SetDizzy(dizzy);
        }
    }
}

void StopHeartBeatSnd(void *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    a0 = (void *)*(s32 *)(s0 + 0x194);
    if ((u32)(s32)a0 != (u32)-1) {
        SND_Stop((signed int)a0);
        *(u32 *)(s0 + 0x194) = -1;
    }
    return;
}

void SetScriptHeartBeat(s32 a0 /* r4 */) {
    ScriptHeart = a0;
    return;
}

/* CheckMyTired @ 0x151770 .. 0x15177C (0xc bytes) */
/*
 * dcomp notes:
 *   return: slti at 0x151778 computes the return value
 */

u32 CheckMyTired(u32 *a0 /* r4 */) {
    s32 v0;

    v0 = *(u32 *)(((u8 *)a0 + 0x120));
    return (s32)v0 < (s32)0x46;
}

/* CheckMyControlOff @ 0x151720 .. 0x151770 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x15172c writes a register its branch at 0x151728 reads
 *   delay: addiu at 0x151744 writes a register its branch at 0x151740 reads
 *   cfg: kept goto: 0x151758 -> .L00151768
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckMyControlOff(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x148));
    v0 = *(u8 *)((v1 + 0x18a));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(u8 *)((v1 + 0x100));
    v0 = 5;
    switch (v1) {
    case 4:
    case 5:
        v0 = 0;
        return v0;
    }
    v0 = 1;
    return v0;
}

/* SetMyControlOff @ 0x151660 .. 0x15171C (0xbc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1516cc
 *   fpu: mtc1 reinterprets a0 at 0x1516e0
 *   fpu: float literal 0x42c80000 at 0x1516f4
 */

void SetMyControlOff(void) {
    u32 a2;
    u8 *s0;
    u8 *a1;
    u32 v1;
    u8 *s1;
    u32 v0;
    float f2;
    float f1;

    a2 = 1;
    s0 = (u8 *)(MdlMng + 0x11800);
    v0 = *(s32 *)(s0 + 0xc);
    a1 = (u8 *)*(s32 *)(s0 + 0x148);
    s1 = (u8 *)*(s32 *)((v0 + 0x4c));
    *(u8 *)(a1 + 0x189) = a2;
    v0 = *(s32 *)(s0 + 0x120);
    if ((s32)v0 <= (s32)0x45) {
        SetMyStay((void *)s0, (void *)a1, a2);
    } else {
        SetMyStay((void *)s0, (void *)a1, 0);
    }
    v1 = *(u16 *)(s1 + 0x18);
    f2 = (float)v1;
    v1 = 0x42c80000;
    f1 = 100.0f;
    *(f32 *)(s0 + 0x114) = ((f2 / 100.0f) * *(float *)(s0 + 0x44));
    return;
}

u8 * SetMyControlOn(void) {
    u8 *v1;

    v1 = (u8 *)*(u32 *)((u8 *)&MdlMng + 0x11948);
    *(u8 *)(((u8 *)v1 + 0x189)) = 0;
    return;
}

/* CheckMyEventStart @ 0x1515E0 .. 0x151648 (0x68 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x151610 if (..) goto .L00151630
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int CheckMyEventStart(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v0 = *(u8 *)((*(s32 *)(MdlMng + 0x11948) + 0x189));
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x148));
    if (v0 != 0) {
        v0 = 0;
    } else {
        v1 = *(u8 *)(((u8 *)a0 + 0x100));
        switch (v1) {
        default:
            v0 = 0;
            break;
        case 0:
        case 1:
        case 9:
            v0 = *(u8 *)(((u8 *)a0 + 0x18a));
            v0 = v0 != 0;
            v0 = v0 ^ 1;
            break;
        }
    }
    return v0;
}

void SetMyLumpOn(void) {
    u32 a2;
    u8 *s3;
    u32 a0;
    u8 *s2;
    u32 v1;
    u32 v0;
    u8 *s1;
    u8 *s0;
    float f12;
    float f2;
    float f1;
    float f0;
    struct stackFrame_70 { u8 b[16]; } stackFrame_70 __attribute__((aligned(16)));
    struct stackFrame_60 { u8 b[16]; } stackFrame_60 __attribute__((aligned(16)));
    struct dcomp_amb stackFrame_50 __attribute__((aligned(16)));

    v0 = 2;
    s3 = (u8 *)(MdlMng + 0x11800);
    v1 = GameSt[0x14];
    s2 = (u8 *)*(s32 *)(s3 + 0x148);
    switch (v1) {
    case 0:
        a0 = 0x28;
        a2 = (u32)V0;
        v0 = SFX_Create_OnAng(a0, (float *)(s3 + 0x20), (float *)V0);
        *(u32 *)(s2 + 0x1bc) = v0;
        break;
    case 1:
        a0 = 0x28;
        a2 = (u32)V0;
        v0 = SFX_Create_OnAng(a0, (float *)(s3 + 0x20), (float *)V0);
        *(u32 *)(s2 + 0x1bc) = v0;
        break;
    case 2:
        a0 = 0x27;
        a2 = (u32)V0;
        v0 = SFX_Create_OnAng(a0, (float *)(s3 + 0x20), (float *)V0);
        *(u32 *)(s2 + 0x1bc) = v0;
    }
    s1 = (u8 *)(MdlMng + 0x11800);
    v0 = (u32)L1582;
    s0 = (u8 *)*(s32 *)(s1 + 0x148);
    stackFrame_50 = dcomp_amb_data;
    v0 = *(s32 *)(s1 + 0x10);
    sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_50), (void *)(s32)(v0 + 0x440),
        (void *)((u8 *)&stackFrame_50));
    f12 = *(float *)(s1 + 0x34);
    f0 = sinf(f12);
    f2 = 0.200000003f;
    f0 = (0.200000003f * (float)f0);
    *(f32 *)((u8 *)&stackFrame_50) = (*(float *)(s1 + 0x20) - f0);
    f12 = *(float *)(s1 + 0x34);
    f0 = cosf(f12);
    v0 = 0x3e4c0000;
    v1 = 0x3e4c0000 | 0xcccd;
    f0 = (0.200000003f * (float)f0);
    *(f32 *)((u8 *)&stackFrame_50 + 0x8) = (*(float *)(s1 + 0x28) - f0);
    f1 = 1.0f;
    f0 = (*(float *)(s1 + 0x24) - 1.0f);
    *(f32 *)((u8 *)&stackFrame_50 + 0x4) = f0;
    a0 = *(s32 *)(s0 + 0x1bc);
    SFX_SetPos(a0, (float *)((u8 *)&stackFrame_50));
    v1 = 1;
    a0 = GameSt[0x14];
    switch (a0) {
    case 0:
        a0 = 0xfb;
        a2 = (u32)VX;
        v0 = SFX_Create_OnAng(a0, (float *)(s3 + 0x20), (float *)VX);
        *(u32 *)(s2 + 0x198) = v0;
        v0 = (u32)L1563;
        stackFrame_70 = (struct stackFrame_70){{0x00, 0x00, 0x00, 0x00, 0x29, 0x5c, 0x8f, 0x3d,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
        a0 = *(s32 *)(s2 + 0x198);
        SFX_SetPos(a0, (float *)((u8 *)&stackFrame_70));
        a0 = *(s32 *)(s2 + 0x198);
        a2 = 0x11;
        SFX_AttachMdlMng(a0, (void *)s3, a2);
        break;
    case 1:
        a0 = 0x12d;
        a2 = (u32)VX;
        v0 = SFX_Create_OnAng(a0, (float *)(s3 + 0x20), (float *)VX);
        *(u32 *)(s2 + 0x198) = v0;
        v0 = (u32)L1566;
        stackFrame_60 = (struct stackFrame_60){{0x00, 0x00, 0x00, 0x00, 0xb8, 0x1e, 0x05, 0x3e,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
        a0 = *(s32 *)(s2 + 0x198);
        SFX_SetPos(a0, (float *)((u8 *)&stackFrame_60));
        a0 = *(s32 *)(s2 + 0x198);
        a2 = 0x2f;
        SFX_AttachMdlMng(a0, (void *)s3, a2);
    }
    return;
}

void SetMyLumpOff(void) {
    u8 *s0;

    s0 = (u8 *)*(s32 *)(MdlMng + 0x11948);
    SFX_Delete(*(s32 *)(s0 + 0x1bc), (s32)1);
    *(u32 *)(s0 + 0x1bc) = -1;
    SFX_Delete(*(s32 *)(s0 + 0x198), (s32)1);
    *(u32 *)(s0 + 0x198) = -1;
    return;
}

static struct dcomp_amb dcomp_amb_data __attribute__((aligned(16))) = {{
    0x00, 0x00, 0x00, 0x00, 0xec, 0x51, 0xb8, 0x3d, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x3f}};
void UpdateMyLump(void) {
    u32 v1;
    u8 *s1;
    u8 *s0;
    float f12;
    float f2;
    float f1;
    float f0;
    u32 v0;

    v0 = 0x2288f0;
    s1 = (u8 *)(MdlMng + 0x11800);
    s0 = (u8 *)*(s32 *)(s1 + 0x148);
    {
        struct dcomp_amb stackFrame_30 __attribute__((aligned(16))) = dcomp_amb_data;
        v0 = *(s32 *)(s1 + 0x10);
        sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_30), (void *)(u32)(v0 + 0x440), (void *)(u8
            *)((u8 *)&stackFrame_30));
        f12 = *(float *)(s1 + 0x34);
        f0 = sinf(f12);
        f2 = 0.200000003f;
        f0 = (0.200000003f * (float)f0);
        *(f32 *)((u8 *)&stackFrame_30) = (*(float *)(s1 + 0x20) - f0);
        f12 = *(float *)(s1 + 0x34);
        f0 = cosf(f12);
        v0 = 0x3e4c0000;
        v1 = 0x3e4c0000 | 0xcccd;
        f0 = (0.200000003f * (float)f0);
        *(f32 *)((u8 *)&stackFrame_30 + 0x8) = (*(float *)(s1 + 0x28) - f0);
        f1 = 1.0f;
        *(f32 *)((u8 *)&stackFrame_30 + 0x4) = (*(float *)(s1 + 0x24) - 1.0f);
        SFX_SetPos(*(s32 *)(s0 + 0x1bc), (float *)((u8 *)&stackFrame_30));
        return;
    }
}

void InitMyWeapon(void) {
    u32 a1;
    u32 a0;
    u8 *s4;
    u8 *s3;
    s32 v1;
    u8 *s2;
    u8 *s1;
    u32 v0;
    s32 s0;

    v0 = (u32)(u8 *)(MdlMng + 0x11800);
    a1 = 0;
    s4 = (u8 *)(MdlMng + 0x52240);
    s2 = (u8 *)*(s32 *)((v0 + 0x148));
    v0 = *(s32 *)((v0 + 0xc));
    v0 = *(s32 *)((v0 + 0x10));
    v1 = *(s16 *)((v0 + 0x10));
    s1 = (u8 *)*(s32 *)((v0 + 0x1c));
    s3 = (u8 *)(MdlData + 0x1b380);
    if (0 < v1) {
        a0 = *(u8 *)(s2 + 0x191);
        do {
            v0 = *(s16 *)(s1 + 0x30);
            if (v0 == a0) {
                break;
            }
            a1 = a1 + 1;
            v0 = (s32)a1 < v1;
            s1 = (u8 *)(s1 + 0x60);
        } while (v0 != 0);
    }
    s0 = 0;
    do {
        SetMdlMng((void *)s4, (void *)s3);
        v1 = *(u8 *)s4;
        if ((u32)v1 != 0) {
            memcpy((void *)(s4 + 0x20), (void *)s1, 0xc);
            memcpy((void *)(u32)(s32)(s4 + 0x30), (void *)(s1 + 0x10), 0xc);
            *(u8 *)(s4 + 2) = 1;
        }
        s0 = s0 + 1;
        v1 = s0 < (s32)3;
        s4 = (u8 *)(s4 + 0x1c0);
        s3 = (u8 *)(s3 + 0x680);
    } while ((u32)v1 != 0);
    *(u8 *)(s2 + 0x18b) = 1;
    v1 = GameSt[0x1d];
    if ((u32)v1 != 0) {
        v0 = (u32)GetSaveData();
        v1 = *(u8 *)(((u8 *)v0 + 0x18));
        *(u8 *)(s2 + 0x1ad) = v1;
    } else {
        *(u8 *)(s2 + 0x1ad) = 0;
    }
    return;
}

/* SetMyWeaponId @ 0x151110 .. 0x151178 (0x68 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void SetMyWeaponId(void *a0 /* r4 */, unsigned char a1 /* r5 */) {
    u8 *t0;
    u32 a2;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    t0 = (u8 *)*(s32 *)(a0_bytes + 0x148);
    if ((s32)(u8)a1 <= (s32)2) {
        a0_bytes = (u8 *)*(u8 *)(t0 + 0x1ad);
        a2 = (s32)(a0_bytes + 0x2ef);
        a0_bytes = (u8 *)(s32)(a2 << 3);
        a0_bytes = (u8 *)(a0_bytes - a2);
        a0_bytes = (u8 *)(s32)((u32)a0_bytes << 6);
        a0_bytes = (u8 *)((u8 *)MdlMng + (u32)(a0_bytes));
        a2 = *(u8 *)(a0_bytes + 2);
        *(u8 *)(a0_bytes + 2) = 1;
        *(u8 *)(t0 + 0x1ad) = a1;
        v1 = *(u8 *)(t0 + 0x1ad);
        a0_bytes = (u8 *)(s32)(v1 + 0x2ef);
        *(u8 *)(((u32)(s32)((u8 *)MdlMng + (s32)((u32)((u32)(a0_bytes)) * (u32)(0x1c0))) + 2)) = a2;
    }
    return;
}

signed int CheckMyWeapon(void *a0 /* r4 */, u8 *a1) {
    u32 v0;
    u32 v1;
    s32 branchcond_1510dc;

    v0 = 2;
    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    branchcond_1510dc = v1 != v0;
    v0 = -1;
    if (!branchcond_1510dc) {
        return v0;
    }
    v0 = *(u8 *)(((u8 *)a1 + 0x18b));
    v0 = v0 != 0;
    v0 = v0 ^ 1;
    return v0;
}


/* GetMyWeaponId @ 0x1510C0 .. 0x1510CC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1510c8 computes the return value
 */

u8 GetMyWeaponId(u32 *a0 /* r4 */) {
    u8 *v0;

    v0 = (u8 *)*(u32 *)(((u8 *)a0 + 0x148));
    return *(u8 *)(((u8 *)v0 + 0x1ad));
}
void ChangeMyWeapon(void *model, void *parameter) {
    u8 *prm = parameter;
    u32 weapon = *(u8 *)(prm + 0x1ad);
    s32 delta = (u8 *)model - (u8 *)(MdlMng + 0x11800);
    s32 state = *(s32 *)((u8 *)model + 0x120);
    u32 entry = *(u8 *)(prm + 0x1ae);
    s32 index = delta / 0x1c0;
    u8 *weaponModel = (u8 *)MdlMng + (weapon + 0x2ef) * 0x1c0;
    u8 *equip = (u8 *)MyEquip + index * 0x18 + entry * 12;
    u32 blocked;
    if (state > 30) {
        if (!*(u8 *)(prm + 0x1ac)) goto available;
    }
    blocked = 1;
    goto ready;
available:
    blocked = 0;
ready:
    if (blocked) {
        *(u8 *)(prm + 0x18b) = 0;
        weaponModel[2] = 0;
    } else {
        switch (*equip) {
        case 0:
            *(u8 *)(prm + 0x18b) = 0;
            weaponModel[2] = 0;
            break;
        case 1:
            *(u8 *)(prm + 0x18b) = 1;
            weaponModel[2] = 1;
        }
    }
}


static void UpdateMyWep(void) {
    u32 a0;
    s32 v1;
    u8 *s2;
    u32 a1;
    s32 v0;
    u32 a2;
    u8 *s1;
    u32 s0;
    float f12;

    a0 = (u32)MdlMng;
    v1 = 1;
    s2 = (u8 *)*(s32 *)(MdlMng + 0x11948);
    a1 = *(u8 *)(s2 + 0x1ad);
    v0 = GameSt[0x14];
    a2 = a1 + 0x2ef;
    a1 = (u32)(a2) * (u32)(0x1c0);
    s1 = (u8 *)((u8 *)MdlMng + a1);
    s0 = *(s32 *)(s1 + 0x100);
    switch ((u32)v0) {
    case 1:
        v0 = *(s16 *)(s1 + 0x104);
        a0 = s0;
        if ((u32)v0 == (u32)v1) {
            v0 = CheckAnimEndFrame((void *)a0);
            if ((u32)v0 == 0) {
                goto _L00150F30;
            }
            f12 = 0.0f;
            a0 = (s32)s1;
            a1 = 2;
            ChangeAnimParam((void *)a0, a1, 0.0f);
            break;
        } else {
            _L00150F30:;
            v1 = *(s16 *)(s1 + 0x104);
            v0 = 2;
            if ((u32)v1 == (u32)v0) {
                v0 = *(u8 *)(s2 + 0x100);
                a1 = 3;
                if ((u32)v0 == a1) {
                    goto _L00150F68;
                }
                f12 = 0.0f;
                a0 = (s32)s1;
                ChangeAnimParam((void *)a0, a1, 0.0f);
                break;
            } else {
                _L00150F68:;
                v0 = 3;
                a0 = s0;
                if ((u32)v1 != (u32)v0) {
                    break;
                }
                v0 = CheckAnimEndFrame((void *)a0);
                if ((u32)v0 == 0) {
                    break;
                }
                f12 = 0.0f;
                a0 = (s32)s1;
                ChangeAnimParam((void *)a0, 0, 0.0f);
            }
        }
    }
    a0 = (s32)s1;
    MasterMove((void *)a0);
    return;
}

signed int CheckDrawMyWrist(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 v1;
    u32 v0;
    u8 *a2;

    v1 = GameSt[5];
    v0 = 4;
    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    if ((u32)v1 != v0) {
        goto _L00150DE0;
    }
    v0 = 1;
    goto _L00150E98;
    _L00150DE0:;
    v0 = 1;
    if ((u32)(s32)a2 == 0) {
        return v0;
    }
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(u16 *)((v0 + 0xa));
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    v0 = *(u8 *)(a2 + 0x18b);
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    v1 = GameSt[0x14];
    v0 = 1;
    switch ((u32)v1) {
    case 0:
        v0 = 0x1a;
        if ((u32)(s32)a1 != v0 && ((u32)((s32)a1 < (s32)0x1e) != 0 || (s32)a1 >= (s32)0x22)) {
            goto _L00150E90;
        }
        v0 = 0;
        break;
    case 1:
        v0 = (s32)a1 < (s32)0x10;
        if (v0 != 0 || (s32)a1 >= (s32)0x15) {
            goto _L00150E90;
        }
        v0 = 0;
        break;
    default:
        _L00150E90:;
        v0 = 1;
    }
    _L00150E98:;
    return v0;
}

void StabilizeMyCloth(void) {
    u8 *s0;
    u32 a1;
    u32 v0;

    s0 = (u8 *)(MdlMng + 0x11800);
    SetMyStay((void *)(u8 *)s0, (void *)*(s32 *)(s0 + 0x148), 0);
    SetHokanFrame((void *)(u8 *)s0, 0.0f);
    *(u8 *)(s0 + 0x131) = 0;
    *(u8 *)(s0 + 0x132) = 0;
    *(f32 *)(s0 + 0x24) = (*(float *)(s0 + 0x24) + 0.0500000007f);
    MasterMove((void *)(u8 *)s0);
    v0 = CheckHitMap((void *)(u8 *)s0);
    *(u32 *)(s0 + 0x134) = v0;
    a1 = (u32)g_UnitMat;
    CsMngRtaSetMat((unsigned int)(u8 *)s0, (void *)g_UnitMat, 1);
    PlayMi3((void *)(u8 *)s0);
    CsMngStabilize((unsigned int)(u8 *)s0, 0x1e);
    return;
}

static void UpdateMyHead(struct umh_My *lpMy, int HeadId, float *TargetPos, int UpdateFlag) {
    struct umh_Vmd *lpVmdHead;
    struct umh_AnimCtrl *lpAnimCtrlHead;
    int NeckId;
    struct umh_Obj *lpVmdObjNeck;
    struct umh_AnimCtrl *lpAnimCtrlNeck;
    float NeckAng[4];
    float HeadAng[4];
    float InvMat[4][4];
    float LocalTargetPos[4];
    static float LastHeadAng[4];
    static float LastNeckAng[4];
    static int Flag;

    lpVmdHead = lpMy->lpMdlData->lpVmdHead;
    lpAnimCtrlHead = (struct umh_AnimCtrl *)lpMy->lpAnimCtrl + HeadId;
    NeckId = ((struct umh_Obj *)((char *)lpVmdHead->lpObject + HeadId * sizeof(struct umh_Obj)))->ParentObjectId;
    lpVmdObjNeck = &lpVmdHead->lpObject[NeckId];
    lpAnimCtrlNeck = (struct umh_AnimCtrl *)lpMy->lpAnimCtrl + NeckId;

    if (UpdateFlag == 0 && Flag == 0) {
        lpAnimCtrlHead->Flag &= 0xfb;
        lpAnimCtrlNeck->Flag &= 0xfb;
        return;
    }
    sceVu0InversMatrix(InvMat, lpMy->lpObjMat[lpVmdObjNeck->ParentObjectId]);
    sceVu0ApplyMatrix(LocalTargetPos, InvMat, TargetPos);
    sceVu0ScaleVectorXYZ(LocalTargetPos, LocalTargetPos, lpVmdHead->GeomScale);
    sceVu0SubVector(LocalTargetPos, lpMy->lpObjMat[NeckId][3], LocalTargetPos);
    Math_VectorToAngleXY(HeadAng, LocalTargetPos);

    if (HeadAng[0] < -1.04699993f || HeadAng[0] > 1.04699993f || HeadAng[1] < -1.5704999f || HeadAng[1] > 1.5704999f) {
        UpdateFlag = 0;
        if (Flag == 0) {
            lpAnimCtrlHead->Flag &= 0xfb;
            lpAnimCtrlNeck->Flag &= 0xfb;
            return;
        }
    }
    if (HeadAng[0] < -0.523499966f) HeadAng[0] = -0.523499966f;
    if (HeadAng[0] > 0.523499966f) HeadAng[0] = 0.523499966f;
    if (HeadAng[1] < -1.04699993f) HeadAng[1] = -1.04699993f;
    if (HeadAng[1] > 1.04699993f) HeadAng[1] = 1.04699993f;
    sceVu0ScaleVectorXYZ(HeadAng, HeadAng, 0.5f);
    sceVu0CopyVector(NeckAng, HeadAng);

    if (UpdateFlag) {
        if (Flag) {
            AnimLinear(HeadAng, LastHeadAng, HeadAng, 0.1f);
            AnimLinear(NeckAng, LastNeckAng, HeadAng, 0.1f);
        } else {
            AnimLinear(HeadAng, lpAnimCtrlHead->Ang, HeadAng, 0.1f);
            AnimLinear(NeckAng, lpAnimCtrlNeck->Ang, NeckAng, 0.1f);
            Flag = 1;
        }
    } else {
        AnimLinear(HeadAng, LastHeadAng, lpAnimCtrlHead->Ang, 0.1f);
        AnimLinear(NeckAng, LastNeckAng, lpAnimCtrlNeck->Ang, 0.1f);
        if (UMH_ABS(HeadAng[0] - lpAnimCtrlHead->Ang[0]) < 0.0523499995f
            && UMH_ABS(HeadAng[1] - lpAnimCtrlHead->Ang[1]) < 0.0523499995f
            && UMH_ABS(HeadAng[2] - lpAnimCtrlHead->Ang[2]) < 0.0523499995f
            && UMH_ABS(NeckAng[0] - lpAnimCtrlNeck->Ang[0]) < 0.0523499995f
            && UMH_ABS(NeckAng[1] - lpAnimCtrlNeck->Ang[1]) < 0.0523499995f
            && UMH_ABS(NeckAng[2] - lpAnimCtrlNeck->Ang[2]) < 0.0523499995f) {
            Flag = 0;
        }
    }
    sceVu0CopyVector(LastHeadAng, HeadAng);
    sceVu0CopyVector(LastNeckAng, NeckAng);
    lpAnimCtrlHead->Flag |= 4;
    UMH_SETMAT(lpAnimCtrlHead, HeadAng);
    lpAnimCtrlNeck->Flag |= 4;
    UMH_SETMAT(lpAnimCtrlNeck, NeckAng);
}

/* CheckMyHeadUpdate @ 0x150290 .. 0x1502D0 (0x40 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1502a0 writes a register its branch at 0x15029c reads
 *   cfg: kept goto: 0x1502b8 -> .L001502C8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckMyHeadUpdate(void *a0 /* r4 */) {
    u32 v1;
    s32 v0;

    v1 = *(s32 *)(((u8 *)a0 + 0x148));
    v0 = 7;
    v1 = *(u8 *)((v1 + 0x100));
    switch (v1) {
    case 6:
    case 7:
        v0 = 0;
        return v0;
    }
    return (s32)1;
}

void SetMyDizzy(signed int a0 /* r4 */) {
    u32 *a1;
    u8 *v1;
    u32 v0;

    a1 = (u32 *)((u8 *)MdlMng + 0x11800);
    v1 = (u8 *)*(s32 *)(((u8 *)a1 + 0x148));
    v0 = (u32)(s32)a0 != 0;
    v0 = v0 ^ 1;
    *(u8 *)(((u8 *)v1 + 0x18f)) = v0;
    if ((u32)(s32)a0 != 0) {
        v0 = *(s32 *)(((u8 *)a1 + 0x120));
        if ((s32)v0 > (s32)0x1e) {
            v0 = *(u8 *)(((u8 *)v1 + 0x1ac));
            if (v0 == 0) {
                goto _L00150258;
            }
        }
        a0 = 1;
        goto _L00150260;
        _L00150258:;
        a0 = 0;
        _L00150260:;
        SetDizzy(a0);
    } else {
        SetDizzy(0);
    }
    return;
}


/* CheckMyDash @ 0x1501E0 .. 0x150210 (0x30 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1501ec writes a register its branch at 0x1501e8 reads
 *   cfg: kept branch: 0x1501f0 if (..) goto .L00150200
 *   cfg: kept goto: 0x1501f8 -> .L00150208
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckMyDash(void *a0 /* r4 */) {
    s32 v1;
    u32 v0;
    s32 branchcond_1501e8;

    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    v0 = 0xa;
    branchcond_1501e8 = (u32)v1 == v0;
    v0 = 0xb;
    if (!branchcond_1501e8) {
        if ((u32)v1 != v0) {
            goto _L00150200;
        }
    }
    v0 = 1;
    goto _L00150208;
    _L00150200:;
    v0 = 0;
    _L00150208:;
    return v0;
}
void SetMyMukadeMode(signed int CtrlId) {
    u8 *lpMy;
    u8 *lpParts;
    u8 *lpEne;
    struct smV4 CamPos;
    struct smV4 CamAng;
    volatile struct smV4 tp;
    volatile struct smV4 ta;
    float f2, f12, f0;

    lpMy = (u8 *)(MdlMng + 0x11800);
    lpParts = (u8 *)GetMapPartsInfoByCtrlId(2, CtrlId);
    if (GameSt[0x14] == 1) {
        if (lpParts != 0) {
            tp = (struct smV4){{4.6f, -1.5f, -151.6f, 1.0f}};
            CamPos = tp;
            ta = (struct smV4){{-0.36644998f, -0.15705f, 0.0f, 0.0f}};
            CamAng = ta;
            SetCamCtrlMode(1);
            SetCameraPos(CamPos.v);
            SetCameraAng(CamAng.v);
            SetMyPadMode(1);
            ChangeAnimParam(lpMy, 0x82, 0.0f);
            SetHokanFrame(lpMy, 0.0f);
            *(float *)(lpMy + 0x34) = *(float *)(lpParts + 0x14);
            f12 = WRAPF((3.14159274f + *(float *)(lpParts + 0x14)));
            f0 = sinf(f12) * 1.5f;
            *(float *)(lpMy + 0x20) = *(float *)lpParts - f0;
            f12 = WRAPF((3.14159274f + *(float *)(lpParts + 0x14)));
            f0 = cosf(f12) * 1.5f;
            *(float *)(lpMy + 0x28) = *(float *)(lpParts + 8) - f0;
            *(float *)(lpMy + 0x24) = *(float *)(lpParts + 4);
            for (lpEne = (u8 *)(MdlMng + 0x119c0); lpEne != (u8 *)(MdlMng + 0x17140); lpEne += 0x1c0) {
                if (*lpEne != 0) {
                    if (CtrlId != GetMdlCtrlId(lpEne)) {
                        FreeMdlMng(lpEne);
                    }
                }
            }
            EneEraseAllFriend();
            FECard_Enable_Draw(0);
        }
    }
}

void SetMyNormalMode(void) {
    u8 *s1;
    u32 s0;

    s1 = (u8 *)(MdlMng + 0x11800);
    s0 = *(s32 *)(s1 + 0x148);
    SetCamCtrlMode(0);
    SetMyPadMode(0);
    SetMyStay((void *)s1, (void *)s0, 0);
    FECard_Enable_Draw(1);
    return;
}

void SetMyTotterMode(signed int a0 /* r4 */) {
    s32 a1;
    u32 *s2;
    u8 *s1;
    u16 *v0;
    u16 *s0;
    float f12;

    a1 = (s32)a0;
    s2 = (u32 *)((u8 *)MdlMng + 0x11800);
    s1 = (u8 *)*(s32 *)(((u8 *)s2 + 0x148));
    a0 = (s32)3;
    v0 = (u16 *)GetMovePath(a0, a1);
    s0 = v0;
    a0 = (s32)2;
    if ((u32)s0 != 0) {
        SetMyPadMode(a0);
        v0 = (u16 *)(s32)0xb;
        a0 = (signed int)s2;
        f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) :
            "r"((u32)0)); native_result_0; });
        *(u8 *)(((u8 *)s1 + 0x100)) = (s32)v0;
        a1 = 0xc;
        ChangeAnimParam((void *)a0, a1, f12);
        *(u32 *)(((u8 *)s2 + 0x17c)) = (u32)s0;
        *(u16 *)(((u8 *)s0 + 0x210)) = 1;
    }
    return;
}

/* CheckMyMenuOpenDisable @ 0x14FDF0 .. 0x14FE68 (0x78 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x14fe04 writes a register its branch at 0x14fe00 reads
 *   delay: addiu at 0x14fe20 writes a register its branch at 0x14fe1c reads
 *   delay: addiu at 0x14fe3c writes a register its branch at 0x14fe38 reads
 *   cfg: kept goto: 0x14fe50 -> .L0014FE60
 */

u32 CheckMyMenuOpenDisable(void) {
    u32 v0;
    u32 v1;

    v0 = (u32)((u8 *)MdlMng + 0x11800);
    v1 = *(s32 *)((v0 + 0x148));
    v0 = *(s32 *)((v0 + 0x120));
    if ((s32)v0 <= 0) {
        v0 = 1;
        return v0;
    }
    v0 = *(s32 *)((u8 *)&MdlMng + 0x11948);
    v0 = *(u8 *)((v0 + 0x189));
    if (v0 != 0) {
        v0 = 1;
        return v0;
    }
    v1 = *(u8 *)((v1 + 0x100));
    v0 = 0xa;
    switch (v1) {
    case 6:
    case 10:
        v0 = 1;
        return v0;
    }
    v0 = 0;
    return v0;
}

/* CheckMyPauseDisable @ 0x14FDB0 .. 0x14FDE8 (0x38 bytes) */

u32 CheckMyPauseDisable(void) {
    u32 v0;
    u32 v1;

    v0 = 6;
    v1 = *(s32 *)(MdlMng + 0x11948);
    v1 = *(u8 *)((v1 + 0x100));
    switch (v1) {
    case 6:
        v0 = 1;
        return v0;
    }
    return 0;
}

/* CheckMyDizzyState @ 0x14FD70 .. 0x14FDA8 (0x38 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x14fd80 if (..) goto .L0014FD98
 *   cfg: kept goto: 0x14fd90 -> .L0014FDA0
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckMyDizzyState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = *(s32 *)(((u8 *)a0 + 0x120));
    if ((s32)v0 > (s32)0x1e) {
        v0 = *(u8 *)(((u8 *)a1 + 0x1ac));
        if (v0 == 0) {
            goto _L0014FD98;
        }
    }
    v0 = 1;
    goto _L0014FDA0;
    _L0014FD98:;
    v0 = 0;
    _L0014FDA0:;
    return v0;
}

u8 * SetMyCrouchDisable(s32 a0 /* r4 */) {
    u8 *v1;

    v1 = (u8 *)*(u32 *)((u8 *)&MdlMng + 0x11948);
    *(u8 *)(((u8 *)v1 + 0x1b3)) = a0;
    return;
}

u8 * SetMyActFreeFlag(s32 a0 /* r4 */) {
    u8 *v1;

    v1 = (u8 *)*(u32 *)((u8 *)&MdlMng + 0x11948);
    *(u8 *)(((u8 *)v1 + 0x102)) = a0;
    return;
}

u32 CheckMyBlastAnimEnable(void) {
    u8 *a0;
    u32 v0;
    u32 v1;

    a0 = (u8 *)MdlMng + 0x11800;
    v0 = *(s32 *)(((u8 *)a0 + 0x120));
    v1 = *(s32 *)(((u8 *)a0 + 0x148));
    if ((s32)v0 <= 0) {
        v0 = 0;
    } else {
        v1 = *(u8 *)((v1 + 0x100));
        v0 = 0xc;
        switch (v1) {
        case 5:
        case 6:
        case 9:
        case 10:
        case 12:
            v0 = 0;
            return v0;
        }
        v0 = *(s16 *)(((u8 *)a0 + 0x104));
        v0 = v0 ^ 0x59;
        v0 = v0 != 0;
    }
    return v0;
}
