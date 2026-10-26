#include "common.h"





/* DrawPeepHole @ 0x18F860 .. 0x18FA14 (0x1b4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: t1: 128-bit web split from its scalar uses
 *   literal: @951 is the string 'nozoki.tm2'
 *   delay: addiu at 0x18f9d4 writes a register its branch at 0x18f9d0 reads
 *   cfg: kept branch: 0x18f9d4 if (..) goto .L0018F9E8
 */

extern void * GetTexMngByName(void *, char *);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
extern u32 GetCamCtrlMode(void);
void DrawPeepManual(void);
extern void DrawPeepManual(void);
extern u8 GameSt[];
extern u32 lpMdlPacketMem;
static u8 PeepCamera[0x10];
/* DrawPeepManual @ 0x18F6F0 .. 0x18F854 (0x164 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @932 is the string 'manual.tm2'
 */

extern void * GetTexMngByName(void *, char *);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
extern u32 lpMdlPacketMem;

/* QuitPeep71_11 @ 0x18FA20 .. 0x18FA74 (0x54 bytes, frame 0x10) */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void ResetEventFlag(signed int);
extern u8 MdlMng[];

extern void SetEventFlag(signed int);


/* CtrlPeep84_17 @ 0x18FAE0 .. 0x18FBA4 (0xc4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x18fb2c
 *   fpu: float literal 0x3f800000 at 0x18fb5c
 *   fpu: float literal 0x00000000 at 0x18fb60
 */

extern void *GetCamInfo(void);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void UpdateCamAnim(void *, void *);
extern void SetEventFlag(signed int);

extern void *GetCamPathData(void *, signed int);


/* QuitPeep23_3 @ 0x18FCE0 .. 0x18FD2C (0x4c bytes, frame 0x10) */


extern void SetPointLightOff(signed int);
static signed int CtrlOlderSister(void);

static signed int CtrlOlderSister(void);
static u32 InitOlderSister(void);
static u32 InitOlderSister(void);
static signed int InitPeep23_3(void);
static signed int InitPeep23_3(void);
static u32 QuitOlderSister(void);


static u32 QuitOlderSister(void);
static u32 QuitPeep23_3(void);
signed int InitPeep84_17(void);
static u32 CtrlPeep84_17(void);
signed int InitPeep71_11(void);
static u32 QuitPeep71_11(void);
static u32 PeepCameraInfo[0x30] = {
    0xffff2319, 0xbe860418, 0x3db2b020, 0xc04e9ba5, 0xc00b9999, (u32)&InitOlderSister,
    (u32)&CtrlOlderSister, (u32)&QuitOlderSister, 0xffffff03, 0xbeb2b020, 0x3e32b020,
    0xc075b22c, 0xc01c5a1c, (u32)&InitPeep23_3, 0, (u32)&QuitPeep23_3, 0xffffff11, 0xbf060418,
    0x3f060418, 0xbf9c5a1c, 0xbe860418, (u32)&InitPeep84_17, (u32)&CtrlPeep84_17, 0, 0xffffff12,
    0xbf060418, 0x3f060418, 0xbf9c5a1c, 0xbe860418, 0, 0, 0, 0xffffff0b, 0xbd566cf4, 0x3f136ae7,
    0xc06de0de, 0xbf136ae7, (u32)&InitPeep71_11, 0, (u32)&QuitPeep71_11, 0xffffff0d, 0xbedcadff,
    0xbda7f77a, 0xbfdbc947, 0xbfbc840e
};

/* InitPeep23_3 @ 0x18FD30 .. 0x18FDB4 (0x84 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @858 -> 0x22c360
 *   literal: @860 -> 0x22c370
 *   fpu: float literal 0x40400000 at 0x18fd74
 *   stack: address of the slot at 0x20 escapes at 0x18fd80
 *   stack: address of the slot at 0x10 escapes at 0x18fd9c
 *   literal: @860 initializes the 16-byte local at 0x10
 *   literal: @858 initializes the 16-byte local at 0x20
 */

extern void SetPointLightOn(signed int, float *, float);
extern signed int UpdatePointLightPos(signed int, float *);

/* QuitOlderSister @ 0x18FDC0 .. 0x18FE60 (0xa0 bytes, frame 0x10) */


extern void StopVagStm(unsigned char);
extern unsigned char CheckEventFlag8(signed int);
extern void SetEventFlag(signed int);
extern void SetEventFlag8(signed int, unsigned char);

/* CtrlOlderSister @ 0x18FE60 .. 0x18FFD8 (0x178 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x18feac writes a register its branch at 0x18fea8 reads
 *   fpu: float literal 0x00000000 at 0x18ff00
 *   delay: addiu at 0x18ff74 writes a register its branch at 0x18ff70 reads
 *   cfg: kept branch: 0x18ff68 if (..) goto .L0018FF80
 *   cfg: kept goto: 0x18ff98 -> .L0018FFC8
 */

extern void PlayBgmVagStm(signed int, signed int);
extern unsigned int CheckAnimEndFrame(void *);

/* InitOlderSister @ 0x18FFE0 .. 0x19009C (0xbc bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x190038 writes a register its branch at 0x190034 reads
 *   fpu: float literal 0x00000000 at 0x19006c
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* ControlPeepCamera @ 0x1900A0 .. 0x190888 (0x7e8 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3e0fe9ef at 0x1900e8
 *   delay: dsll32 at 0x190120 writes a register its branch at 0x19011c reads
 *   delay: addiu at 0x19013c writes a register its branch at 0x190138 reads
 *   stack: address of the slot at 0x84 escapes at 0x190158
 *   stack: address of the slot at 0x88 escapes at 0x190158
 *   stack: address of the slot at 0x80 escapes at 0x1901bc
 *   fpu: float literal 0x3f000000 at 0x1901cc
 *   fpu: mov.s at 0x190214 is a float copy
 *   fpu: mov.s at 0x19021c is a float copy
 *   fpu: mov.s at 0x190230 is a float copy
 *   fpu: float literal 0x3d8f35ca at 0x190250
 *   fpu: float literal 0x3e0fe9ef at 0x190280
 *   fpu: mov.s at 0x1902b0 is a float copy
 *   fpu: mov.s at 0x1902b4 is a float copy
 *   fpu: mov.s at 0x1902b8 is a float copy
 *   fpu: float literal 0x3c8ef34d at 0x1902f4
 *   fpu: float literal 0x3ee84b5d at 0x190334
 *   fpu: float literal 0x3c8ef34d at 0x190360
 *   fpu: float literal 0x43000000 at 0x190380
 *   fpu: float literal 0xbe4ccccd at 0x190394
 *   fpu: mtc1 reinterprets v0 at 0x19039c
 *   fpu: mtc1 reinterprets v0 at 0x1903b0
 *   fpu: float literal 0x40490fdb at 0x1903e4
 *   fpu: float literal 0x00000000 at 0x1903e8
 *   fpu: float literal 0x40c90fdb at 0x190410
 *   fpu: float literal 0x40c90fdb at 0x190438
 *   fpu: float literal 0x3ca3d70a at 0x190460
 *   fpu: float literal 0x3e4ccccd at 0x190488
 *   fpu: float literal 0x40490fdb at 0x1904ac
 *   fpu: float literal 0x00000000 at 0x1904b0
 *   fpu: float literal 0x40c90fdb at 0x1904d8
 *   fpu: float literal 0x40c90fdb at 0x190500
 *   fpu: float literal 0x3ca3d70a at 0x190528
 *   fpu: float literal 0x3e0fe9ef at 0x190550
 *   fpu: float literal 0x40490fdb at 0x190570
 *   fpu: float literal 0x00000000 at 0x190574
 *   fpu: float literal 0x40c90fdb at 0x190598
 *   fpu: float literal 0x40c90fdb at 0x1905c0
 *   fpu: float literal 0x3ca3d70a at 0x1905e8
 *   fpu: float literal 0xbe4ccccd at 0x190608
 *   fpu: float literal 0x40490fdb at 0x19062c
 *   fpu: float literal 0x00000000 at 0x190630
 *   fpu: float literal 0x40c90fdb at 0x190658
 *   fpu: float literal 0x40c90fdb at 0x190680
 *   fpu: float literal 0x3ca3d70a at 0x1906a8
 *   fpu: float literal 0x3e4ccccd at 0x1906d0
 *   fpu: float literal 0x40490fdb at 0x1906f4
 *   fpu: float literal 0x00000000 at 0x1906f8
 *   fpu: float literal 0x40c90fdb at 0x190720
 *   fpu: float literal 0x40c90fdb at 0x190748
 *   fpu: float literal 0x3ca3d70a at 0x190770
 *   fpu: float literal 0x3e0fe9ef at 0x190798
 *   fpu: float literal 0x40490fdb at 0x1907b8
 *   fpu: float literal 0x00000000 at 0x1907bc
 *   fpu: float literal 0x40c90fdb at 0x1907e0
 *   fpu: float literal 0x40c90fdb at 0x190808
 *   fpu: float literal 0x3ca3d70a at 0x190830
 *   cfg: kept goto: 0x190108 -> .L00190850
 *   cfg: kept branch: 0x190120 if (..) goto .L00190148
 *   cfg: loop body is not one contiguous region: .L00190158
 */

extern void sceVu0SubVector(void *, void *, void *);
extern float tanf(float);
extern void DrawSetViewRange();
extern u32 lpPadData;
extern u32 lpDrawMng;

struct dw_1297344_fields;
struct dw_1300057_fields;
struct dw_1305439_fields;
struct dw_1315532_fields;
#ifndef PROTO_DW_1313223_FIELDS
#define PROTO_DW_1313223_FIELDS
struct dw_1313223_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1309805_FIELDS
#define PROTO_DW_1309805_FIELDS
struct dw_1309805_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1309482_FIELDS
#define PROTO_DW_1309482_FIELDS
struct dw_1309482_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1297344_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1297344_FIELDS
#define PROTO_DW_1297344_FIELDS
struct dw_1297344_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1315532_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1297344_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1313223_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1309805_fields flags; unsigned char _pad1[3]; struct dw_1309482_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1300057_FIELDS
#define PROTO_DW_1300057_FIELDS
struct dw_1300057_fields { unsigned char CamIndex; unsigned char TargetObj[3]; float MinAngX; float MaxAngX; float MinAngY; float MaxAngY; void *InitEventFunc; void *CtrlEventFunc; void *QuitEventFunc; };
#endif
#ifndef PROTO_DW_1304278_FIELDS
#define PROTO_DW_1304278_FIELDS
struct dw_1304278_fields { struct dw_1300057_fields *lpInfo; struct dw_1305439_fields *lpCamPath; unsigned char Status; unsigned char CamIndex; unsigned char CamLock; unsigned char Look; unsigned char Visible; unsigned char Mask; unsigned char CancelOff; unsigned char unused; };
#endif
#ifndef PROTO_DW_1305439_FIELDS
#define PROTO_DW_1305439_FIELDS
struct dw_1305439_fields { char cam_name[16]; unsigned short cam_id; unsigned short cam_type; unsigned short pos_key_num; unsigned short ang_key_num; unsigned short fov_key_num; unsigned short wall_num; float fov; float position[4]; float angle[4]; unsigned int posData; unsigned int angData; unsigned int fovData; unsigned int wallData; unsigned int mapInfo; unsigned int charData; unsigned char limitAngX; unsigned char limitAngY; unsigned char bUseAng; unsigned char unused1; unsigned int ambData; unsigned int reverbData; unsigned int unused2[3]; };
#endif
#ifndef PROTO_DW_1304676_FIELDS
#define PROTO_DW_1304676_FIELDS
struct dw_1304676_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_1309250_FIELDS
#define PROTO_DW_1309250_FIELDS
struct dw_1309250_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_1305079_FIELDS
#define PROTO_DW_1305079_FIELDS
struct dw_1305079_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_1310579_FIELDS
#define PROTO_DW_1310579_FIELDS
struct dw_1310579_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_1309936_FIELDS
#define PROTO_DW_1309936_FIELDS
struct dw_1309936_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_1301310_FIELDS
#define PROTO_DW_1301310_FIELDS
struct dw_1301310_fields { struct dw_1304676_fields pmode; struct dw_1309250_fields smode2; struct dw_1305079_fields dispfb; struct dw_1310579_fields display; struct dw_1309936_fields bgcolor; };
#endif
#ifndef PROTO_DW_1302438_FIELDS
#define PROTO_DW_1302438_FIELDS
struct dw_1302438_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_1306896_FIELDS
#define PROTO_DW_1306896_FIELDS
struct dw_1306896_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_1315167_FIELDS
#define PROTO_DW_1315167_FIELDS
struct dw_1315167_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_1312981_FIELDS
#define PROTO_DW_1312981_FIELDS
struct dw_1312981_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_1306366_FIELDS
#define PROTO_DW_1306366_FIELDS
struct dw_1306366_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_1301653_FIELDS
#define PROTO_DW_1301653_FIELDS
struct dw_1301653_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1314160_FIELDS
#define PROTO_DW_1314160_FIELDS
struct dw_1314160_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1304159_FIELDS
#define PROTO_DW_1304159_FIELDS
struct dw_1304159_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1310160_FIELDS
#define PROTO_DW_1310160_FIELDS
struct dw_1310160_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_1301785_FIELDS
#define PROTO_DW_1301785_FIELDS
struct dw_1301785_fields { struct dw_1306896_fields frame1; unsigned long frame1addr; struct dw_1315167_fields zbuf1; long zbuf1addr; struct dw_1312981_fields xyoffset1; long xyoffset1addr; struct dw_1306366_fields scissor1; long scissor1addr; struct dw_1301653_fields prmodecont; long prmodecontaddr; struct dw_1314160_fields colclamp; long colclampaddr; struct dw_1304159_fields dthe; long dtheaddr; struct dw_1310160_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_1318018_FIELDS
#define PROTO_DW_1318018_FIELDS
struct dw_1318018_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_1303610_FIELDS
#define PROTO_DW_1303610_FIELDS
struct dw_1303610_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_1313472_FIELDS
#define PROTO_DW_1313472_FIELDS
struct dw_1313472_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_1310979_FIELDS
#define PROTO_DW_1310979_FIELDS
struct dw_1310979_fields { struct dw_1310160_fields testa; long testaaddr; struct dw_1318018_fields prim; long primaddr; struct dw_1303610_fields rgbaq; long rgbaqaddr; struct dw_1313472_fields xyz2a; long xyz2aaddr; struct dw_1313472_fields xyz2b; long xyz2baddr; struct dw_1310160_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_1314414_FIELDS
#define PROTO_DW_1314414_FIELDS
struct dw_1314414_fields { struct dw_1301310_fields disp[2]; struct dw_1302438_fields giftag0; struct dw_1301785_fields draw0; struct dw_1310979_fields clear0; struct dw_1302438_fields giftag1; struct dw_1301785_fields draw1; struct dw_1310979_fields clear1; };
#endif
#ifndef PROTO_DW_1307947_FIELDS
#define PROTO_DW_1307947_FIELDS
struct dw_1307947_fields { struct dw_1314414_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_1311453_FIELDS
#define PROTO_DW_1311453_FIELDS
struct dw_1311453_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1297344_FIELDS_HITHIGH_7F644653_DEFINED
#define DCOMP_OFF_STRUCT_DW_1297344_FIELDS_HITHIGH_7F644653_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1297344_FIELDS_HITHIGH_7F644653 = (int)&(((struct dw_1297344_fields *)0)->HitHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BERASE_8EEECFD2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BERASE_8EEECFD2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BERASE_8EEECFD2 = (int)&(((struct dw_1297344_fields *)0)->bErase) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BUSE_48E4C466_DEFINED
#define DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BUSE_48E4C466_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1297344_FIELDS_BUSE_48E4C466 = (int)&(((struct dw_1297344_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGX_649B3359_DEFINED
#define DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGX_649B3359_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGX_649B3359 = (int)&(((struct dw_1300057_fields *)0)->MaxAngX) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGY_DC67F0F2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGY_DC67F0F2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MAXANGY_DC67F0F2 = (int)&(((struct dw_1300057_fields *)0)->MaxAngY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGX_1DA8351E_DEFINED
#define DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGX_1DA8351E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGX_1DA8351E = (int)&(((struct dw_1300057_fields *)0)->MinAngX) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGY_03B4733F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGY_03B4733F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1300057_FIELDS_MINANGY_03B4733F = (int)&(((struct dw_1300057_fields *)0)->MinAngY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CAMLOCK_8CD51F76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CAMLOCK_8CD51F76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CAMLOCK_8CD51F76 = (int)&(((struct dw_1304278_fields *)0)->CamLock) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CANCELOFF_F17C31E2_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CANCELOFF_F17C31E2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_CANCELOFF_F17C31E2 = (int)&(((struct dw_1304278_fields *)0)->CancelOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LOOK_13338878_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LOOK_13338878_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LOOK_13338878 = (int)&(((struct dw_1304278_fields *)0)->Look) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_VISIBLE_6322D7DF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_VISIBLE_6322D7DF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_VISIBLE_6322D7DF = (int)&(((struct dw_1304278_fields *)0)->Visible) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPCAMPATH_1A73DC76_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPCAMPATH_1A73DC76_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPCAMPATH_1A73DC76 = (int)&(((struct dw_1304278_fields *)0)->lpCamPath) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPINFO_3D9C1D82_DEFINED
#define DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPINFO_3D9C1D82_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1304278_FIELDS_LPINFO_3D9C1D82 = (int)&(((struct dw_1304278_fields *)0)->lpInfo) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1305439_FIELDS_FOV_1F62B4BB_DEFINED
#define DCOMP_OFF_STRUCT_DW_1305439_FIELDS_FOV_1F62B4BB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1305439_FIELDS_FOV_1F62B4BB = (int)&(((struct dw_1305439_fields *)0)->fov) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__7FC9B974_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__7FC9B974_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__7FC9B974 = (int)&(((struct dw_1307947_fields *)0)->camAng[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__998AAF62_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__998AAF62_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_0__998AAF62 = (int)&(((struct dw_1307947_fields *)0)->camAng[0]) - 576 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__875CC1AF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__875CC1AF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__875CC1AF = (int)&(((struct dw_1307947_fields *)0)->camAng[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__13E3AB34_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__13E3AB34_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_CAMANG_1__13E3AB34 = (int)&(((struct dw_1307947_fields *)0)->camAng[1]) - 580 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_966CF127_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_966CF127_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_966CF127 = (int)&(((struct dw_1307947_fields *)0)->fov) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_68260D41_DEFINED
#define DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_68260D41_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1307947_FIELDS_FOV_68260D41 = (int)&(((struct dw_1307947_fields *)0)->fov) - 1052 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1311453_FIELDS_PADPORT_4DBC074F_DEFINED
#define DCOMP_OFF_STRUCT_DW_1311453_FIELDS_PADPORT_4DBC074F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1311453_FIELDS_PADPORT_4DBC074F = (int)&(((struct dw_1311453_fields *)0)->padport) - 0 };
#endif
struct PeepPad { u8 ppPad[0x21]; u8 ppB0 : 1; u8 ppB1 : 1; u8 ppB2 : 1; u8 ppB3 : 1; u8 ppB4 : 1; u8 ppB5 : 1; u8 ppB6 : 1; u8 ppB7 : 1; };
#define PEEP_WRAP2(a, s) (((s) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((s) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((s) / 6.28318548f))))
#define PEEP_WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
#define PC_INFO (*(struct dw_1300057_fields **)(PeepCamera + 0))
#define PC_PATH (*(struct dw_1305439_fields **)(PeepCamera + 4))
#define PC_LOCK PeepCamera[0xa]
#define PC_LOOK PeepCamera[0xb]
#define PC_VIS PeepCamera[0xc]
#define PC_CANCEL PeepCamera[0xe]
#define PEEP_DM ((struct dw_1307947_fields *)lpDrawMng)


extern u32 CheckFadeEnd();
extern void * GetCamPathData(void *, signed int);
extern void SetCamAmbient(void *);
extern void SetCamReverb(void *);
extern void sceVu0CopyVector(void *, void *);
extern void DrawSetViewRange();
extern void FECard_Enable_Draw(signed int);
extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern signed int CheckEventFlag(signed int);
unsigned int ControlPeepCamera(void);
extern u32 ControlPeepCamera();
extern void SetCamCtrlMode(unsigned int);
extern void SetMyDizzy(signed int);
extern u32 lpDrawMng;
extern u32 lpPadData;


/* CheckPeepManual @ 0x190D00 .. 0x190D40 (0x40 bytes) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x190d10 if (..) goto .L00190D28
 *   cfg: kept branch: 0x190d18 if (..) goto .L00190D30
 *   cfg: kept goto: 0x190d28 -> .L00190D38
 */

extern u8 PeepCamera[];

/* StopPeepCamera @ 0x190D40 .. 0x190DCC (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x190d58 writes a register its branch at 0x190d54 reads
 *   stack: address of the slot at 0x10 escapes at 0x190d64
 *   stack: address of the slot at 0x10 escapes at 0x190d98
 */

extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);

/* SetPeepCamera @ 0x190DD0 .. 0x190ED4 (0x104 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x30 escapes at 0x190e70
 *   stack: address of the slot at 0x30 escapes at 0x190ea4
 */

extern u32 GetCamCtrlMode(void);
extern void SetCamCtrlMode(unsigned int);
extern void SetMyControlOn(void);
extern void SetMyDizzy(signed int);
static u8 PeepCamera[0x10];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetPeepCamera(signed int a0 );
signed int StopPeepCamera(void);
u32 CheckPeepManual(void);
void UpdatePeepCamera(void);
unsigned int ControlPeepCamera(void);
static u32 InitOlderSister(void);
static signed int CtrlOlderSister(void);
static u32 QuitOlderSister(void);
static signed int InitPeep23_3(void);
static u32 QuitPeep23_3(void);
signed int InitPeep84_17(void);
static u32 CtrlPeep84_17(void);
signed int InitPeep71_11(void);
static u32 QuitPeep71_11(void);
void DrawPeepHole(void);
void DrawPeepManual(void);


void SetPeepCamera(signed int a0 /* r4 */) {
    u32 a3;
    u8 *s0;
    s32 a2;
    u8 *a1;
    signed int a0_2; // a0
    u32 v1;
    u32 v0;

    v0 = (u32)GetCamInfo();
    s0 = (u8 *)v0;
    v0 = GetCamCtrlMode();
    if (v0 == 0 && (u32)(s32)a0 <= (u32)5) {
        a0_2 = 2;
        SetCamCtrlMode(a0_2);
        v0 = (u32)PeepCameraInfo;
        v1 = (s32)(u32)&((struct { u8 b[0x20]; } *)PeepCameraInfo)[a0];
        *(u32 *)PeepCamera = v1;
        v0 = (u32)(a0) ^ 2;
        a3 = *(s32 *)(s0 + 4);
        a2 = v0 < (u32)1;
        a1 = (u8 *)(s32)((u32)((u32)(a0) ^ 1) != 0);
        a0_2 = (u32)((u32)(a0) ^ 5) < (u32)1;
        PeepCamera[9] = a3;
        PeepCamera[0xa] = a2;
        PeepCamera[0xd] = (s32)a1;
        PeepCamera[0xe] = a0_2;
        PeepCamera[8] = 0;
        {
            u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
            a0_2 = 1;
            a2 = 0x1e;
            SetFadeMng(a0_2, (signed int *)(u8 *)((u8 *)&stackFrame_30[0]), a2, (void *)0, (void
                *)0, 0, (signed
    int)0);
            SetMyControlOn();
            SetMyDizzy(0);
        }
    }
    return;
}

signed int StopPeepCamera(void) {
    u32 v1;
    u32 v0;

    v0 = 2;
    v1 = PeepCamera[8];
    if (!(s32)(v1 != v0)) {
        {
            u8 stackFrame_10[16] __attribute__((aligned(16))) = {0};
            SetFadeMng(1, (signed int *)(u8 *)((u8 *)&stackFrame_10[0]), 0x1e, (void *)0, (void
                *)0, 0, 0);
            v1 = 3;
            v0 = 1;
            PeepCamera[8] = v1;
        }
    } else {
        v0 = 0;
    }
    return v0;
}

u32 CheckPeepManual(void) {
    u32 v1;
    u32 v0;

    v1 = *(u8 *)((u8 *)&PeepCamera + 8);
    v0 = 0xa;
    if (v1 != 0) {
        if (v1 == v0) {
            goto _L00190D28;
        }
        v0 = 0xb;
        if (v1 != v0) {
            goto _L00190D30;
        }
    }
    _L00190D28:;
    v0 = 1;
    goto _L00190D38;
    _L00190D30:;
    v0 = 0;
    _L00190D38:;
    return v0;
}

void UpdatePeepCamera(void) {
    s32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;

    v1 = 0xff;
    PeepCamera[0xb] = v1;
    PeepCamera[0xc] = v1;
    v1 = GameSt[0xf];
    if (v1 == 0) {
        v1 = 0xb;
        a0 = PeepCamera[8];
        switch (a0) {
        case 0:
            v0 = CheckFadeEnd();
            if (v0 == 0) {
                break;
            }
            v0 = (u32)GetCamInfo();
            v1 = *(u8 *)*(s32 *)PeepCamera;
            *(u32 *)(((u8 *)v0 + 4)) = v1;
            a1 = *(s32 *)(((u8 *)v0 + 4));
            v0 = (u32)GetCamPathData((void *)v0, a1);
            *(u32 *)(PeepCamera + 4) = v0;
            a0 = *(s32 *)(PeepCamera + 4);
            SetCamAmbient((void *)a0);
            a0 = *(s32 *)(PeepCamera + 4);
            SetCamReverb((void *)a0);
            {
                u32 path;
                u32 draw;
                draw=lpDrawMng;
                path=*(s32 *)(PeepCamera+4);
                sceVu0CopyVector((void *)(s32)(draw+0x230),(void *)(s32)(path+0x20));
            }
            v1 = lpDrawMng;
            v0 = *(s32 *)(PeepCamera + 4);
            sceVu0CopyVector((void *)(s32)(v1 + 0x240), (void *)(s32)(v0 + 0x30));
            v0 = lpDrawMng;
            v1 = *(s32 *)(PeepCamera + 4);
            *(f32 *)((v0 + 0x41c)) = *(float *)((v1 + 0x1c));
            DrawSetViewRange();
            FECard_Enable_Draw(0);
            {
                u8 stackFrame_50[16] __attribute__((aligned(16))) = {0};
                a2 = 0x1e;
                SetFadeMng(0, (signed int *)((u8 *)&stackFrame_50[0]), a2, (void *)0, (void *)0, 0,
                    (signed
    int)0);
                v1 = PeepCamera[0xd];
                if (v1 != 0) {
                    v0 = 1;
                    a0 = 0x78;
                    GameSt[0x13] = v0;
                    v0 = CheckEventFlag(a0);
                    if (v0 != 0) {
                        v1 = PeepCamera[8];
                        v1 = v1 + 1;
                        PeepCamera[8] = v1;
                    } else {
                        v1 = 0xa;
                        PeepCamera[8] = v1;
                    }
                } else {
                    v1 = PeepCamera[8];
                    v1 = v1 + 1;
                    PeepCamera[8] = v1;
                }
                v1 = *(s32 *)((*(s32 *)PeepCamera + 0x14));
                if (v1 == 0) {
                    break;
                }
                ((void (*)(void))(s32)v1)();
                break;
            }
        case 1:
            v0 = CheckFadeEnd();
            if (v0 == 0) {
                break;
            }
            v1 = PeepCamera[8];
            v1 = v1 + 1;
            PeepCamera[8] = v1;
            break;
        case 2:
            v0 = ControlPeepCamera();
            if (v0 != 0) {
                {
                    u8 stackFrame_40[16] __attribute__((aligned(16))) = {0};
                    a0 = 1;
                    a2 = 0x1e;
                    SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_40[0]), a2, (void *)0, (void
                        *)0, 0, (signed
    int)0);
                    v1 = PeepCamera[8];
                    v1 = v1 + 1;
                    PeepCamera[8] = v1;
                    break;
                }
            } else {
                v1 = *(s32 *)((*(s32 *)PeepCamera + 0x18));
                if (v1 == 0) {
                    break;
                }
                v0 = ((u32 (*)(void))(s32)v1)();
                if (v0 == 0) {
                    break;
                }
                {
                    u8 stackFrame_30[16] __attribute__((aligned(16))) = {0};
                    a0 = 1;
                    a2 = 0x1e;
                    SetFadeMng(a0, (signed int *)((u8 *)&stackFrame_30[0]), a2, (void *)0, (void
                        *)0, 0, (signed
    int)0);
                    v1 = PeepCamera[8];
                    v1 = v1 + 1;
                    PeepCamera[8] = v1;
                    break;
                }
            }
        case 3:
            v0 = CheckFadeEnd();
            if (v0 == 0) {
                break;
            }
            v0 = (u32)GetCamInfo();
            s0 = (u8 *)v0;
            DrawSetViewRange();
            v0 = PeepCamera[9];
            *(u32 *)(s0 + 4) = v0;
            a1 = *(s32 *)(s0 + 4);
            v0 = (u32)GetCamPathData((void *)s0, a1);
            *(u32 *)(PeepCamera + 4) = v0;
            a0 = *(s32 *)(PeepCamera + 4);
            SetCamAmbient((void *)a0);
            a0 = *(s32 *)(PeepCamera + 4);
            SetCamReverb((void *)a0);
            FECard_Enable_Draw(1);
            {
                u8 stackFrame_20[16] __attribute__((aligned(16))) = {0};
                a2 = 0x1e;
                SetFadeMng(0, (signed int *)((u8 *)&stackFrame_20[0]), a2, (void *)0, (void *)0, 0,
                    (signed
    int)0);
                SetCamCtrlMode(0);
                a0 = 1;
                SetMyDizzy(a0);
                GameSt[0x13] = 0;
                v1 = *(s32 *)((*(s32 *)PeepCamera + 0x1c));
                if (v1 == 0) {
                    break;
                }
                ((void (*)(void))(s32)v1)();
                break;
            }
        case 10:
            v0 = CheckFadeEnd();
            if (v0 == 0) {
                break;
            }
            v1 = PeepCamera[8];
            v1 = v1 + 1;
            PeepCamera[8] = v1;
            break;
        case 11:
            a0 = GameSt[0xa];
            v1 = (u32)&lpPadData;
            a0 = a0 << 2;
            v1 = (s32)((u8 *)&lpPadData + a0);
            v1 = *(s32 *)v1;
            v1 = *(u8 *)((v1 + 0x21));
            if ((u64)((u64)v1 << 0x39 >> 0x3f) == 0) {
                break;
            }
            v0 = 2;
            a0 = 0x78;
            PeepCamera[8] = v0;
            SetEventFlag(a0);
        }
    }
    return;
}
unsigned int ControlPeepCamera(void) {
    struct PeepPad *lpPad;
    s32 i;
    float NearTan;
    struct dw_1297344_fields *lpObject;
    float Vec[4];
    float l;
    float x;
    float y;
    float bx;
    float by;
    float sy;
    float sx;
    float d;
    float tx;
    float ty;

    lpPad = ((struct PeepPad **)&lpPadData)[((struct dw_1311453_fields *)GameSt)->padport];
    NearTan = 0.14054082f;
    if (PC_LOCK != 0) {
        return 0;
    }
    if (lpPad->ppB6 != 0 || lpPad->ppB5 != 0) {
        if (PC_CANCEL == 0) {
            return 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if (PC_INFO->TargetObj[i] != 0xff) {
            lpObject = &((struct dw_1297344_fields *)MdlMng)[GetMdlMngIndexByCtrlId(1, PC_INFO->TargetObj[i]) + 0x30];
            if (lpObject->bUse != 0 && lpObject->bErase == 0) {
                sceVu0SubVector(Vec, lpObject->Pos, PEEP_DM->camPos);
                Vec[1] -= 0.5f * lpObject->HitHigh;
                x = atan2f(-Vec[1], sqrtf(Vec[0] * Vec[0] + Vec[2] * Vec[2]));
                y = atan2f(Vec[0], Vec[2]);
                l = tanf(x - PEEP_DM->camAng[0]);
                ty = tanf(y - PEEP_DM->camAng[1]);
                l = l * l + ty * ty;
                if (l < 0.06992681f) {
                    PC_LOOK = PC_INFO->TargetObj[i];
                }
                if (l < 0.14054082f) {
                    PC_VIS = PC_INFO->TargetObj[i];
                    if (l < NearTan) {
                        NearTan = l;
                        bx = x;
                        by = y;
                    }
                }
            }
        }
    }
    if (PC_LOOK == 0xff) {
        if (PEEP_DM->fov >= PC_PATH->fov - 0.01745f) {
            PEEP_DM->fov = PC_PATH->fov;
        } else {
            PEEP_DM->fov = PEEP_DM->fov + 0.01745f;
        }
    } else {
        if (PEEP_DM->fov <= 0.45369998f) {
            PEEP_DM->fov = 0.43624997f;
        } else {
            PEEP_DM->fov = PEEP_DM->fov - 0.01745f;
        }
    }
    DrawSetViewRange();
    sy = (float)(s32)(0x80 - *((u8 *)lpPad + 7)) / 128.0f;
    sx = (float)(s32)(*((u8 *)lpPad + 6) - 0x80) / 128.0f;
    if (sy < -0.2f) {
        x = PC_INFO->MinAngX - PEEP_DM->camAng[0];
        y = 3.14159274f + x;
        d = PEEP_WRAP2(x, y);
        PEEP_DM->camAng[0] = PEEP_DM->camAng[0] - sy * (0.02f * d);
    } else if (!(sy <= 0.2f)) {
        l = PC_INFO->MaxAngX - PEEP_DM->camAng[0];
        d = PEEP_WRAPF(l);
        PEEP_DM->camAng[0] = PEEP_DM->camAng[0] + sy * (0.02f * d);
    } else if (NearTan < 0.14054082f) {
        l = bx - PEEP_DM->camAng[0];
        d = PEEP_WRAPF(l);
        PEEP_DM->camAng[0] = PEEP_DM->camAng[0] + 0.02f * d;
    }
    if (sx < -0.2f) {
        l = PC_INFO->MinAngY - PEEP_DM->camAng[1];
        d = PEEP_WRAPF(l);
        PEEP_DM->camAng[1] = PEEP_DM->camAng[1] - sx * (0.02f * d);
    } else if (!(sx <= 0.2f)) {
        l = PC_INFO->MaxAngY - PEEP_DM->camAng[1];
        d = PEEP_WRAPF(l);
        PEEP_DM->camAng[1] = PEEP_DM->camAng[1] + sx * (0.02f * d);
    } else if (NearTan < 0.14054082f) {
        l = by - PEEP_DM->camAng[1];
        d = PEEP_WRAPF(l);
        PEEP_DM->camAng[1] = PEEP_DM->camAng[1] + 0.02f * d;
    }
    return 0;
}

static u32 InitOlderSister(void) {
    u32 a0;
    u32 a1;
    u32 v0;
    u32 v1;
    u8 *s0;

    a0 = 1;
    a1 = 0x23;
    v0 = GetMdlMngIndexByCtrlId(a0, a1);
    a1 = v0 + 0x30;
    a0 = 0x78;
    v0 = (u32)MdlMng;
    v1 = (u32)(a1) * (u32)(0x1c0);
    s0 = (u8 *)(s32)((u8 *)MdlMng + v1);
    v0 = CheckEventFlag8(a0);
    v1 = (u8)v0;
    v0 = 0x10;
    v1 = v1 & 0xf0;
    switch (v1) {
    case 0:
    case 48:
    case 32:
        v0 = 1;
        *(u8 *)(((u8 *)s0 + 2)) = v0;
        *(u32 *)(((u8 *)s0 + 0x158)) = 0;
        break;
    case 16:
        a0 = (s32)s0;
        ChangeAnimParam((void *)a0, 0, 0.0f);
        *(u8 *)(((u8 *)s0 + 2)) = 0;
        v0 = 1;
        *(u32 *)(((u8 *)s0 + 0x158)) = v0;
        *(u32 *)(((u8 *)s0 + 0x15c)) = 0;
    }
    v0 = 0;
    return v0;
}

static signed int CtrlOlderSister(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 *s0;

    a0 = 1;
    a1 = 0x23;
    v0 = GetMdlMngIndexByCtrlId(a0, a1);
    a1 = v0 + 0x30;
    v1 = (u32)MdlMng;
    v0 = 3;
    a0 = a1 * (u32)(0x1c0);
    s0 = (u8 *)((u8 *)MdlMng + a0);
    v1 = *(s32 *)(s0 + 0x158);
    switch (v1) {
    case 1:
        v1 = PeepCamera[0xb];
        v0 = 0x23;
        if (v1 == v0) {
            v0 = *(s32 *)(s0 + 0x15c);
            v0 = v0 + 1;
            *(u32 *)(s0 + 0x15c) = v0;
        } else {
            *(u32 *)(s0 + 0x15c) = 0;
        }
        v0 = *(s32 *)(s0 + 0x15c);
        if ((s32)v0 <= (s32)0x3c) {
            break;
        }
        a0 = (s32)s0;
        a1 = 1;
        ChangeAnimParam((void *)a0, a1, 0.0f);
        v0 = 2;
        a0 = 0x78;
        *(u32 *)(s0 + 0x158) = v0;
        v0 = (u8)CheckEventFlag8(a0);
        a0 = 0x78;
        v0 = v0 & 0xf;
        v0 = v0 + 0x20;
        a1 = (u8)v0;
        SetEventFlag8(a0, a1);
        StopVagStm(0);
        a0 = 3;
        a1 = 0x33;
        PlayBgmVagStm(a0, a1);
        break;
    case 2:
        a0 = *(s32 *)(s0 + 0x100);
        v0 = CheckAnimEndFrame((void *)a0);
        if (v0 == 0) {
            break;
        }
        v0 = 0x23;
        v1 = PeepCamera[0xc];
        if (v1 == v0) {
            goto _L0018FF80;
        }
        v0 = 1;
        *(u8 *)(s0 + 2) = v0;
        break;
        _L0018FF80:;
        v0 = 1;
        return v0;
    case 3:
        a0 = *(s32 *)(s0 + 0x100);
        v0 = CheckAnimEndFrame((void *)a0);
        a0 = 0x78;
        if (v0 == 0) {
            break;
        }
        v0 = (u8)CheckEventFlag8(a0);
        a0 = 0x78;
        v0 = v0 & 0xf;
        v0 = v0 + 0x30;
        a1 = (u8)v0;
        SetEventFlag8(a0, a1);
        v0 = 1;
        return v0;
    }
    v0 = 0;
    return v0;
}


static u32 QuitOlderSister(void) {
    u32 a0;
    u32 a1;
    u32 v0;
    u32 v1;

    a0 = 1;
    a1 = 0x23;
    v0 = GetMdlMngIndexByCtrlId(a0, a1);
    a1 = v0 + 0x30;
    v0 = a1 << 3;
    a0 = (u32)MdlMng;
    a1 = v0 - a1;
    v1 = 1;
    a1 = a1 << 6;
    v0 = 2;
    a0 = (s32)((u8 *)MdlMng + a1);
    *(u8 *)((a0 + 2)) = v1;
    v1 = *(s32 *)((a0 + 0x158));
    a0 = 0;
    if (v1 == v0) {
        StopVagStm(0);
    }
    a0 = 0x78;
    v0 = CheckEventFlag8(a0);
    v1 = (u8)v0;
    v0 = 0x30;
    v1 = v1 & 0xf0;
    a0 = 0x79;
    if (v1 == v0) {
        SetEventFlag(a0);
        a0 = 0x78;
        v0 = CheckEventFlag8(a0);
        v0 = (u8)v0;
        a0 = 0x78;
        a1 = v0 & 0xf;
        SetEventFlag8(a0, a1);
    }
    v0 = 0;
    return v0;
}

static signed int InitPeep23_3(void) {
    u32 a2;
    u32 a1;
    s32 a0;
    u32 v1;
    u32 v0;

    a0 = 1;
    v0 = GetMdlMngIndexByCtrlId(a0, a0);
    a1 = v0 + 0x30;
    a0 = 1;
    v0 = (u32)MdlMng;
    a2 = (u32)(a1 * (u32)(7)) << 6;
    a2 = (s32)((u8 *)MdlMng + (u32)a2);
    v1 = 0x22c360;
    *(u8 *)((a2 + 2)) = a0;
    {
        struct stackFrame_20 { u8 b[16]; } stackFrame_20 __attribute__((aligned(16))) = {{0x9a,
            0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x00, 0x00, 0x80,
            0x3f}};
        SetPointLightOn(a0, (float *)((u8 *)&stackFrame_20), 3.0f);
        v0 = 0x22c370;
        {
            struct stackFrame_10 { u8 b[16]; } stackFrame_10 __attribute__((aligned(16))) = {{0x00,
                0x00, 0xe1, 0xc2, 0x66, 0x66, 0xe6, 0xc0, 0xcd, 0xcc, 0x98, 0xc1, 0x00, 0x00, 0x80,
                0x3f}};
            UpdatePointLightPos(1, (float *)((u8 *)&stackFrame_10));
            return 0;
        }
    }
}


static u32 QuitPeep23_3(void) {
    s32 a0;
    s32 a1;
    u32 v0;
    s32 v1;

    a0 = 1;
    a1 = a0;
    v0 = GetMdlMngIndexByCtrlId(a0, a1);
    a1 = v0 + 0x30;
    a0 = 1;
    v1 = (u32)a1 << 3;
    v1 = v1 - a1;
    v0 = (u32)MdlMng;
    v1 = (u32)v1 << 6;
    v0 = (s32)((u8 *)MdlMng + v1);
    *(u8 *)((v0 + 2)) = 0;
    SetPointLightOff(a0);
    v0 = 0;
    return v0;
}
signed int InitPeep84_17(void) {
    u8 *model;
    u8 *camera;
    u8 *path;
    u8 *entry;
    int total;
    int i;
    u16 count;
    model = MdlMng + (GetMdlMngIndexByCtrlId(1, 4) + 0x30) * 0x1c0;
    camera = GetCamInfo();
    path = GetCamPathData(camera, *(int *)(camera + 4));
    entry = *(u8 **)(path + 0x40);
    total = 0;
    *(u32 *)(model + 0x158) = 0;
    count = *(u16 *)(path + 0x14);
    for (i = 0; i < count; i++) {
        total += *(u16 *)(entry + 2);
        entry += 0x40;
    }
    *(float *)(camera + 8) = (float)total;
    UpdateCamAnim(camera, 0);
    return 0;
}

static u32 CtrlPeep84_17(void) {
    u32 a0;
    u32 v0;
    u8 *s1;
    u8 *s0;
    float f1;

    v0 = GetMdlMngIndexByCtrlId(1, 4);
    a0 = v0 + 0x30;
    v0 = (u32)MdlMng;
    s1 = (u8 *)((u8 *)MdlMng + (s32)(a0 * 0x1c0));
    v0 = (u32)GetCamInfo();
    s0 = (u8 *)v0;
    v0 = *(s32 *)(s1 + 0x158);
    if (v0 == 0) {
        ChangeAnimParam((void *)s1, 0xa, 0.0f);
        *(u32 *)(s1 + 0x158) = 1;
    }
    UpdateCamAnim((void *)s0, (void *)0);
    v0 = 0x3f800000;
    f1 = 1.0f;
    f1 = (*(f32 *)(s0 + 8) -= 1.0f);
    if (f1 <= 0.0f) {
        SetEventFlag(0x1b8);
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}

signed int InitPeep71_11(void) {
    u8 *lpObject;

    lpObject = MdlMng + (GetMdlMngIndexByCtrlId(1, 1) + 0x30) * 0x1c0;
    lpObject[2] = 1;
    MdlMng[0x11802] = 1;
    SetEventFlag(0x105);
    return 0;
}

static u32 QuitPeep71_11(void) {
    s32 a0;
    s32 a1;
    u32 v0;
    s32 v1;

    a0 = 1;
    a1 = a0;
    v0 = GetMdlMngIndexByCtrlId(a0, a1);
    a1 = v0 + 0x30;
    a0 = 0x105;
    v1 = (u32)a1 << 3;
    v1 = v1 - a1;
    v0 = (u32)MdlMng;
    v1 = (u32)v1 << 6;
    v0 = (s32)((u8 *)MdlMng + v1);
    *(u8 *)((v0 + 2)) = 0;
    *(u8 *)((u8 *)&MdlMng + 0x11802) = 0;
    ResetEventFlag(a0);
    v0 = 0;
    return v0;
}

void DrawPeepHole(void) {
    u64 t6;
    int s1;
    u64 t5;
    u8 *t1;
    u8 *s0;
    int a3;
    int a2;
    u8 *a1;
    u64 a0_64;
    u64 a2_64;
    int a0;
    u64 a3_64;
    u64 t0_64;
    int v1;
    int v0;
    u64 a1_64;

    v1 = GameSt[0x13];
    s1 = lpMdlPacketMem;
    if (v1 != 0) {
        a1 = (u8 *)"nozoki.tm2";
        v0 = (u32)GetTexMngByName((void *)0, "nozoki.tm2");
        s0 = (u8 *)v0;
        a0 = s1;
        if ((u32)s0 != 0) {
            a1 = s0;
            v0 = (u32)MakeTexPacket((unsigned int *)a0, (void *)a1);
            v1 = 0x51000000;
            a0 = 0x1000000a;
            a2 = 0x51000000 | 0xa;
            *(u32 *)v0 = 0x1000000a;
            v1 = 0x102b0000;
            *(u32 *)(((u8 *)v0 + 4)) = 0;
            a0 = 0x102b0000 | 0x4000;
            *(u32 *)(((u8 *)v0 + 8)) = 0;
            a1 = (u8 *)(s32)6;
            *(u32 *)(((u8 *)v0 + 0xc)) = a2;
            v1 = 0xe;
            *(u32 *)(((u8 *)v0 + 0x10)) = (s32)a1;
            *(u32 *)(((u8 *)v0 + 0x14)) = a0;
            a3 = 0x47;
            *(u32 *)(((u8 *)v0 + 0x18)) = v1;
            *(u32 *)(((u8 *)v0 + 0x1c)) = 0;
            v1 = 0x80;
            *(u64 *)(((u8 *)v0 + 0x20)) = 0;
            a0_64 = (u64)(s32)v1 << 0x20;
            *(s64 *)(((u8 *)v0 + 0x28)) = (s32)0x3f;
            v1 = 0x44;
            *(u64 *)(((u8 *)v0 + 0x30)) = 0;
            a2_64 = (u64)((s32)((s32)v1)) | (u64)(a0_64);
            *(s64 *)(((u8 *)v0 + 0x38)) = (s32)a3;
            a0 = 0x42;
            *(u64 *)(((u8 *)v0 + 0x40)) = a2_64;
            v1 = 0x14;
            *(s64 *)(((u8 *)v0 + 0x48)) = (s32)a0;
            a2 = 0x3f800000;
            t1 = (u8 *)*(s32 *)(s0 + 4);
            a3_64 = (u64)(u32)0x3f800000 << 0x20;
            t0_64 = (u64)((s32)((s32)0x3f800000)) | (u64)(a3_64);
            a2 = 0x8080;
            a2_64 = (u64)0x8080 << 0x10;
            a2_64 = (u64)(a2_64) | (u64)(0x8080);
            t5 = (u64)(a2_64) | (u64)(a3_64);
            t6 = *(u64 *)(t1 + 0x10);
            a2 = -1;
            a3_64 = (u64)(s32)a2 << 0x20;
            a2 = 0x72007000;
            a3_64 = (u64)((s32)((s32)0x72007000)) | (u64)(a3_64);
            a2 = -0x72000000;
            *(u64 *)(((u8 *)v0 + 0x50)) = t6;
            *(s64 *)(((u8 *)v0 + 0x58)) = (s32)a1;
            a3 = -0x72000000 | 0x9000;
            a1 = (u8 *)*(s32 *)(s0 + 4);
            a2 = v0 + 0xb0;
            a1_64 = *(u64 *)(a1 + 0x18);
            *(u64 *)(((u8 *)v0 + 0x60)) = a1_64;
            *(s64 *)(((u8 *)v0 + 0x68)) = (s32)v1;
            *(u64 *)(((u8 *)v0 + 0x70)) = t5;
            *(s64 *)(((u8 *)v0 + 0x78)) = (s32)1;
            *(u32 *)(((u8 *)v0 + 0x80)) = 2;
            *(u32 *)(((u8 *)v0 + 0x84)) = 0x24000000;
            *(u32 *)(((u8 *)v0 + 0x88)) = a0;
            *(u32 *)(((u8 *)v0 + 0x8c)) = 0;
            *(u64 *)(((u8 *)v0 + 0x90)) = 0;
            *(u64 *)(((u8 *)v0 + 0x98)) = a3_64;
            *(u64 *)(((u8 *)v0 + 0xa0)) = t0_64;
            *(u64 *)(((u8 *)v0 + 0xa8)) = a3;
            lpMdlPacketMem = a2;
            v0 = GetCamCtrlMode();
            v1 = 2;
            if (v0 == v1) {
                v1 = 0xa;
                a0 = PeepCamera[8];
                if (a0 != v1) {
                    v1 = 0xb;
                    if (a0 != v1) {
                        goto _L0018F9E8;
                    }
                }
                v1 = 1;
            } else {
                _L0018F9E8:;
                v1 = 0;
            }
            if (v1 != 0) {
                DrawPeepManual();
            }
        }
    }
    return;
}

void DrawPeepManual(void) {
    u32 s1;
    u64 t6;
    u8 *t1;
    u8 *s0;
    u32 a2;
    u8 *a1;
    u32 a0;
    u32 v1;
    u64 a3_64;
    u8 *v0;
    u64 a1_64;

    s1 = lpMdlPacketMem;
    a1 = (u8 *)"manual.tm2";
    v0 = (u8 *)GetTexMngByName((void *)0, "manual.tm2");
    s0 = v0;
    a0 = s1;
    if ((u32)s0 != 0) {
        v0 = (u8 *)MakeTexPacket((unsigned int *)a0, (void *)(u8 *)s0);
        v1 = 0x51000000;
        a0 = 0x1000000a;
        *(u32 *)v0 = 0x1000000a;
        v1 = 0x102b0000;
        *(u32 *)(v0 + 4) = 0;
        *(u32 *)(v0 + 8) = 0;
        a1 = (u8 *)(s32)6;
        *(u32 *)(v0 + 0xc) = 0x51000000 | 0xa;
        *(u32 *)(v0 + 0x10) = (s32)a1;
        *(u32 *)(v0 + 0x14) = 0x102b0000 | 0x4000;
        *(u32 *)(v0 + 0x18) = 0xe;
        *(u32 *)(v0 + 0x1c) = 0;
        *(u64 *)(v0 + 0x20) = 0;
        *(s64 *)(v0 + 0x28) = (s32)0x3f;
        *(u64 *)(v0 + 0x30) = 0;
        *(s64 *)(v0 + 0x38) = (s32)0x47;
        a0 = 0x42;
        *(u64 *)(v0 + 0x40) = (u64)((s32)((s32)0x44)) | (u64)((u64)(u32)0x80 << 0x20);
        *(s64 *)(v0 + 0x48) = (s32)a0;
        a2 = 0x3f800000;
        t1 = (u8 *)*(s32 *)(s0 + 4);
        a3_64 = (u64)(u32)0x3f800000 << 0x20;
        a2 = 0x8080;
        t6 = *(u64 *)(t1 + 0x10);
        a2 = 0x72007000;
        a2 = -0x72000000;
        *(u64 *)(v0 + 0x50) = t6;
        *(s64 *)(v0 + 0x58) = (s32)a1;
        a1 = (u8 *)*(s32 *)(s0 + 4);
        a1_64 = *(u64 *)(a1 + 0x18);
        *(u64 *)(v0 + 0x60) = a1_64;
        *(s64 *)(v0 + 0x68) = (s32)0x14;
        *(u64 *)(v0 + 0x70) = (u64)((u64)((u64)0x8080 << 0x10) | (u64)(0x8080)) | a3_64;
        *(s64 *)(v0 + 0x78) = (s32)1;
        *(u32 *)(v0 + 0x80) = 2;
        *(u32 *)(v0 + 0x84) = 0x24000000;
        *(u32 *)(v0 + 0x88) = a0;
        *(u32 *)(v0 + 0x8c) = 0;
        *(u64 *)(v0 + 0x90) = 0;
        *(u64 *)(v0 + 0x98) = (u64)((s32)((s32)0x72007000)) | (u64)((u64)(s32)-1 << 0x20);
        *(u64 *)(v0 + 0xa0) = (u64)((s32)((s32)0x3f800000)) | a3_64;
        *(u64 *)(v0 + 0xa8) = (s32)(-0x72000000 | 0x9000);
        lpMdlPacketMem = (s32)(v0 + 0xb0);
    }
    return;
}
