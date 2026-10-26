#include "common.h"

u32 GameCamInfo[0xc04];
u8 DramaCamInfo[0xc0400];
f32 s_vibration[4] __attribute__((aligned(16)));
u32 s_vibration_act[5];
u32 CamId4FreeTarget;
u32 CamCtrlMode;


#ifndef PROTO_DW_40166
#define PROTO_DW_40166
struct dw_40166 { unsigned char *lpCamData; int nowIndex; float frame; unsigned char LockDirFlag; char LockL3V; char LockL3H; unsigned char noneUpdate; unsigned char eraseMap[256][48]; };
#endif
#ifndef PROTO_DW_42407
#define PROTO_DW_42407
struct dw_42407 { char mg_code[4]; unsigned int file_size; unsigned int ver; unsigned short scene_id; unsigned short cam_num; unsigned short map_parts_num; unsigned short wall_num; unsigned short prim_num; unsigned short vert_num; unsigned int camPath; unsigned int dmyPath; unsigned int wallData; unsigned short chardata_num; unsigned char drama_flag; unsigned char drama_id; unsigned int unused1[2]; };
#endif
#ifndef PROTO_DW_46050
#define PROTO_DW_46050
struct dw_46050 { char cam_name[16]; unsigned short cam_id; unsigned short cam_type; unsigned short pos_key_num; unsigned short ang_key_num; unsigned short fov_key_num; unsigned short wall_num; float fov; float position[4]; float angle[4]; unsigned int posData; unsigned int angData; unsigned int fovData; unsigned int wallData; unsigned int mapInfo; unsigned int charData; unsigned char limitAngX; unsigned char limitAngY; unsigned char bUseAng; unsigned char unused1; unsigned int ambData; unsigned int reverbData; unsigned int unused2[3]; };
#endif
typedef struct CameraRemapEntry { u8 head[64]; u32 p64,p68,p72,p76,p80,p84,unused88,p92,p96; u8 tail[12]; } CameraRemapEntry;
typedef struct CameraRemapSecond { u8 head[20]; u32 p20; u8 tail[24]; } CameraRemapSecond;
typedef struct CameraRemapThird { u8 head[40]; u32 p40,p44; u8 tail[16]; } CameraRemapThird;
extern u32 s_vibration_act[];
extern f32 s_vibration[];
extern void GetMapAmbient(void *);
extern void SetAmbientColor(float *);
void SetCamReverb(void *);
extern void SetMirror(unsigned char, unsigned char);
extern u32 GameSt[];
void SetCamReverb(void *a0 );
extern float tanf(float);
extern float atanf(float);
extern void DrawSetViewRange(void);
extern u32 GameCamInfo[];
extern u32 CamCtrlMode;
extern u32 CamId4FreeTarget;
extern u8 *lpDrawMng;
extern void SND_SetReverbStudioC(signed int);
extern void SND_SetReverbOff(void);
extern void SND_SqVolSetValue(int, signed int);
extern u8 DramaCamInfo[];
extern u32 lpDramaMng;
extern void *memset();
extern void MemFree(void *);
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0CopyVector(void *,void *);
extern void sceVu0SubVector(void *,void *,void *);
extern signed int fsHit_GetHitPolygonLine(void *,void *,void *);
extern signed int CheckNowFade(signed int);
extern void SetSceneLoad(unsigned short,unsigned short);
extern void SetFadeMng(unsigned char,signed int *,signed int,void *,void *,signed int,signed int);
extern void SetFadeSceneLoad(signed int,signed int);
extern u32 MdlMng[];
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern void sceVu0UnitMatrix(void *);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void UpdateCamAnim(void *, void *);
static void UpdateTargetCam(void *, signed int, void *);
extern void UpdatePeepCamera();
extern void UpdateCamVib();
extern u32 L995[];
void StartCamVibration(s32 a0 /* r4 */, float f12 /* f12 */);
void SetCamVibration(void *a0 /* r4 */);
void SetCamPathDirect(signed int id);
void SetCamEnv(void *a0 /* r4 */, signed int a1 /* r5 */);
void SetTargetFreeCamera(signed int id);
u32 GetCamCtrlMode(void);
void SetCamCtrlMode(u_int mode);
void SetCamReverb(void *a0 /* r4 */);
void SetCamAmbient(void *a0 /* r4 */);
u8 * GetGameCamInfo(void);
u32 GetDramaCamInfo(s32 a0 /* r4 */);
u8 * GetCamInfo(void);
signed int GetCurCamID(void);
void FreeDramaCamData(void);
void FreeGameCamData(signed int a0 /* r4 */);
void SetCamDirLockFlag(char a0 /* r4 */, char a1 /* r5 */);
static float GetCamFrame(void *scene, void *camera, int id);
static signed int CheckHitCamWall(void *data,void *object,signed int id);
void * GetCamPathData(void *a0 /* r4 */, signed int a1 /* r5 */);
void SetEraseMapData(struct dw_40166 *a0 /* r4 */);
unsigned int CheckDrawMapByCamParam(signed int a0 /* r4 */);
unsigned int CheckPosOutOfSight(float *a0 /* r4 */);
unsigned int CheckBackOfCamera(float *a0 /* r4 */);
void UpdateCamera(void);
void SetCameraFov(float f12 /* f12 */);
void SetCameraAng(float *a0 /* r4 */);
void SetCameraPos(float *a0 /* r4 */);
void RemapCamData(void *data);
u32 GetCameraAng(void);
u32 GetCameraPos(void);








/* InitCamera @ 0x1343F0 .. 0x134890 (0x4a0 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @885 -> 0x228540
 *   literal: @887 -> 0x228550
 *   stack: address of the slot at 0x60 escapes at 0x1344c8
 *   stack: address of the slot at 0x50 escapes at 0x1344c8
 *   stack: address of the slot at 0x80 escapes at 0x134624
 *   stack: address of the slot at 0x80 escapes at 0x134654
 *   stack: address of the slot at 0x70 escapes at 0x1346d4
 *   fpu: float literal 0x40490fdb at 0x1346f4
 *   fpu: float literal 0x00000000 at 0x1346f8
 *   fpu: float literal 0x40c90fdb at 0x134718
 *   stack: address of the slot at 0x74 escapes at 0x134738
 *   fpu: mtc1 reinterprets v0 at 0x13473c
 *   fpu: float literal 0x00000000 at 0x1347d4
 *   delay: addiu at 0x134850 writes a register its branch at 0x13484c reads
 *   literal: @887 initializes the 16-byte local at 0x50
 *   literal: @885 initializes the 16-byte local at 0x60
 *   cfg: loop body is not one contiguous region: .L001344E8
 *   cfg: loop header already being structured: .L001345C8
 *   cfg: loop body is not one contiguous region: .L001345E8
 *   cfg: kept branch: 0x1345e8 if (..) goto .L00134600
 *   cfg: kept goto: 0x1345f4 -> .L00134618
 *   cfg: kept branch: 0x134640 if (..) goto .L00134768
 *   cfg: loop body is not one contiguous region: .L00134688
 *   cfg: kept branch: 0x134688 if (..) goto .L001346A0
 *   cfg: kept goto: 0x134694 -> .L001346B8
 *   cfg: loop body is not one contiguous region: .L001347A0
 *   cfg: kept branch: 0x1347a0 if (..) goto .L001347B8
 *   cfg: kept goto: 0x1347ac -> .L001347D0
 *   cfg: kept branch: 0x1347e8 if (..) goto .L00134820
 *   cfg: kept branch: 0x1347f8 if (..) goto .L00134820
 */

extern u32 GetCamIdAfterLoad();
extern u32 GetSaveData();
extern void InitSceneLoadFlag();
extern u32 L885[];
extern u32 L887[];

struct dw_43036_fields;
struct dw_58100_fields;
#ifndef PROTO_DW_40166_FIELDS
#define PROTO_DW_40166_FIELDS
struct dw_40166_fields { unsigned char *lpCamData; int nowIndex; float frame; unsigned char LockDirFlag; char LockL3V; char LockL3H; unsigned char noneUpdate; unsigned char eraseMap[256][48]; };
#endif
#ifndef PROTO_DW_49744_FIELDS
#define PROTO_DW_49744_FIELDS
struct dw_49744_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_52319_FIELDS
#define PROTO_DW_52319_FIELDS
struct dw_52319_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_50147_FIELDS
#define PROTO_DW_50147_FIELDS
struct dw_50147_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_53720_FIELDS
#define PROTO_DW_53720_FIELDS
struct dw_53720_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_53005_FIELDS
#define PROTO_DW_53005_FIELDS
struct dw_53005_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_40778_FIELDS
#define PROTO_DW_40778_FIELDS
struct dw_40778_fields { struct dw_49744_fields pmode; struct dw_52319_fields smode2; struct dw_50147_fields dispfb; struct dw_53720_fields display; struct dw_53005_fields bgcolor; };
#endif
#ifndef PROTO_DW_47916_FIELDS
#define PROTO_DW_47916_FIELDS
struct dw_47916_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_51985_FIELDS
#define PROTO_DW_51985_FIELDS
struct dw_51985_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_57495_FIELDS
#define PROTO_DW_57495_FIELDS
struct dw_57495_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_56264_FIELDS
#define PROTO_DW_56264_FIELDS
struct dw_56264_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_50759_FIELDS
#define PROTO_DW_50759_FIELDS
struct dw_50759_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_45713_FIELDS
#define PROTO_DW_45713_FIELDS
struct dw_45713_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_56940_FIELDS
#define PROTO_DW_56940_FIELDS
struct dw_56940_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_49625_FIELDS
#define PROTO_DW_49625_FIELDS
struct dw_49625_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_53301_FIELDS
#define PROTO_DW_53301_FIELDS
struct dw_53301_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_47263_FIELDS
#define PROTO_DW_47263_FIELDS
struct dw_47263_fields { struct dw_51985_fields frame1; unsigned long frame1addr; struct dw_57495_fields zbuf1; long zbuf1addr; struct dw_56264_fields xyoffset1; long xyoffset1addr; struct dw_50759_fields scissor1; long scissor1addr; struct dw_45713_fields prmodecont; long prmodecontaddr; struct dw_56940_fields colclamp; long colclampaddr; struct dw_49625_fields dthe; long dtheaddr; struct dw_53301_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_61416_FIELDS
#define PROTO_DW_61416_FIELDS
struct dw_61416_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_49403_FIELDS
#define PROTO_DW_49403_FIELDS
struct dw_49403_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_56788_FIELDS
#define PROTO_DW_56788_FIELDS
struct dw_56788_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_54224_FIELDS
#define PROTO_DW_54224_FIELDS
struct dw_54224_fields { struct dw_53301_fields testa; long testaaddr; struct dw_61416_fields prim; long primaddr; struct dw_49403_fields rgbaq; long rgbaqaddr; struct dw_56788_fields xyz2a; long xyz2aaddr; struct dw_56788_fields xyz2b; long xyz2baddr; struct dw_53301_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_57096_FIELDS
#define PROTO_DW_57096_FIELDS
struct dw_57096_fields { struct dw_40778_fields disp[2]; struct dw_47916_fields giftag0; struct dw_47263_fields draw0; struct dw_54224_fields clear0; struct dw_47916_fields giftag1; struct dw_47263_fields draw1; struct dw_54224_fields clear1; };
#endif
#ifndef PROTO_DW_41105_FIELDS
#define PROTO_DW_41105_FIELDS
struct dw_41105_fields { struct dw_57096_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_56468_FIELDS
#define PROTO_DW_56468_FIELDS
struct dw_56468_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_52874_FIELDS
#define PROTO_DW_52874_FIELDS
struct dw_52874_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_52551_FIELDS
#define PROTO_DW_52551_FIELDS
struct dw_52551_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_43036_fields *lpMdl; };
#endif
#ifndef PROTO_DW_43036_FIELDS
#define PROTO_DW_43036_FIELDS
struct dw_43036_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_58100_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_43036_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_56468_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_52874_fields flags; unsigned char _pad1[3]; struct dw_52551_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_54698_FIELDS
#define PROTO_DW_54698_FIELDS
struct dw_54698_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED
#define DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED
enum { DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36 = (int)&(((struct dw_40166_fields *)0)->lpCamData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3 = (int)&(((struct dw_40166_fields *)0)->nowIndex) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A = (int)&(((struct dw_41105_fields *)0)->camAng[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1 = (int)&(((struct dw_41105_fields *)0)->camAng[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3 = (int)&(((struct dw_41105_fields *)0)->camAng[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_3__7C370154_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_3__7C370154_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_3__7C370154 = (int)&(((struct dw_41105_fields *)0)->camAng[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0 = (int)&(((struct dw_41105_fields *)0)->camPos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE = (int)&(((struct dw_41105_fields *)0)->camPos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846 = (int)&(((struct dw_41105_fields *)0)->camPos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_3__344649E6_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_3__344649E6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_3__344649E6 = (int)&(((struct dw_41105_fields *)0)->camPos[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_43036_FIELDS_ANG_1__12D2F838_DEFINED
#define DCOMP_OFF_STRUCT_DW_43036_FIELDS_ANG_1__12D2F838_DEFINED
enum { DCOMP_OFF_STRUCT_DW_43036_FIELDS_ANG_1__12D2F838 = (int)&(((struct dw_43036_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_0__D7BA0245_DEFINED
#define DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_0__D7BA0245_DEFINED
enum { DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_0__D7BA0245 = (int)&(((struct dw_43036_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_1__18D7B9F2_DEFINED
#define DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_1__18D7B9F2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_1__18D7B9F2 = (int)&(((struct dw_43036_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_2__E16CE311_DEFINED
#define DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_2__E16CE311_DEFINED
enum { DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_2__E16CE311 = (int)&(((struct dw_43036_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_3__4F58B144_DEFINED
#define DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_3__4F58B144_DEFINED
enum { DCOMP_OFF_STRUCT_DW_43036_FIELDS_POS_3__4F58B144 = (int)&(((struct dw_43036_fields *)0)->Pos[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_54698_FIELDS_CONTROLMODE_9940226C_DEFINED
#define DCOMP_OFF_STRUCT_DW_54698_FIELDS_CONTROLMODE_9940226C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_54698_FIELDS_CONTROLMODE_9940226C = (int)&(((struct dw_54698_fields *)0)->ControlMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_54698_FIELDS_GAMEMODE_7942BDFC_DEFINED
#define DCOMP_OFF_STRUCT_DW_54698_FIELDS_GAMEMODE_7942BDFC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_54698_FIELDS_GAMEMODE_7942BDFC = (int)&(((struct dw_54698_fields *)0)->GameMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_54698_FIELDS_LOADSTART_D6F8E4F3_DEFINED
#define DCOMP_OFF_STRUCT_DW_54698_FIELDS_LOADSTART_D6F8E4F3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_54698_FIELDS_LOADSTART_D6F8E4F3 = (int)&(((struct dw_54698_fields *)0)->LoadStart) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_54698_FIELDS_SCENENO_088DB581_DEFINED
#define DCOMP_OFF_STRUCT_DW_54698_FIELDS_SCENENO_088DB581_DEFINED
enum { DCOMP_OFF_STRUCT_DW_54698_FIELDS_SCENENO_088DB581 = (int)&(((struct dw_54698_fields *)0)->sceneNo) - 0 };
#endif
#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif
static inline void SetEraseMapData__ic(struct dw_40166 *a0) {
    struct dw_42407 *t2;
    struct dw_46050 *t1;
    s32 t0;
    s32 a3;

    t2 = (struct dw_42407 *)(s32)a0->lpCamData;
    if ((u32)(s32)(u8 *)t2 != 0) {
        t1 = (struct dw_46050 *)t2->camPath;
        t0 = 0;
        for (; t0 < (s32)t2->cam_num; t0 = t0 + 1) {
            a3 = 0;
            for (; a3 < (s32)t2->map_parts_num; a3 = a3 + 1) {
                u8 *row = a0->eraseMap[t1->cam_id];
                row[a3] = *(u8 *)(u32)(a3 + t1->mapInfo);
            }
            t1 = (struct dw_46050 *)((u8 *)(u8 *)t1 + 0x70);
        }
    }
}
static inline void * GetCamPathData__ic2(void *a0, signed int a1) {
    struct dw_42407 *data = (struct dw_42407 *)((struct dw_40166 *)a0)->lpCamData;
    struct dw_46050 *p = (struct dw_46050 *)data->camPath;
    int i;
    for (i = 0; i < (s32)data->cam_num; i++, p = (struct dw_46050 *)((u8 *)p + 0x70)) {
        if (p->cam_id == a1) {
            return p;
        }
    }
    return 0;
}








/* UpdateCamAnim @ 0x133100 .. 0x1336DC (0x5dc bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x133188
 *   fpu: mtc1 reinterprets v0 at 0x1331b0
 *   fpu: mtc1 reinterprets a1 at 0x1331d0
 *   fpu: mtc1 reinterprets v1 at 0x1331e8
 *   fpu: mtc1 reinterprets a0 at 0x133200
 *   fpu: mtc1 reinterprets v1 at 0x133218
 *   fpu: mtc1 reinterprets v0 at 0x133294
 *   fpu: mtc1 reinterprets v0 at 0x1332c0
 *   fpu: mtc1 reinterprets a1 at 0x1332e0
 *   fpu: mtc1 reinterprets v1 at 0x1332f8
 *   fpu: mtc1 reinterprets a0 at 0x133310
 *   fpu: mtc1 reinterprets v1 at 0x133328
 *   fpu: mtc1 reinterprets v0 at 0x1333b0
 *   fpu: mtc1 reinterprets v0 at 0x1333d8
 *   fpu: mtc1 reinterprets a1 at 0x1333f8
 *   fpu: mtc1 reinterprets v1 at 0x133410
 *   fpu: mtc1 reinterprets a0 at 0x133428
 *   fpu: mtc1 reinterprets v1 at 0x133440
 *   fpu: float literal 0x40000000 at 0x133470
 *   fpu: float literal 0x3f400000 at 0x133490
 *   fpu: float literal 0x40000000 at 0x1334b4
 *   fpu: float literal 0x40000000 at 0x1334e8
 *   fpu: float literal 0x3f400000 at 0x133508
 *   fpu: float literal 0x40000000 at 0x13352c
 *   fpu: float literal 0x40490fdb at 0x13355c
 *   fpu: float literal 0x00000000 at 0x133560
 *   fpu: float literal 0x40c90fdb at 0x133580
 *   fpu: float literal 0x40c90fdb at 0x1335a8
 *   fpu: float literal 0x40490fdb at 0x1335d8
 *   fpu: float literal 0x00000000 at 0x1335dc
 *   fpu: float literal 0x40c90fdb at 0x1335fc
 *   fpu: float literal 0x40c90fdb at 0x133624
 *   fpu: float literal 0x40490fdb at 0x133654
 *   fpu: float literal 0x00000000 at 0x133658
 *   fpu: float literal 0x40c90fdb at 0x133678
 *   fpu: float literal 0x40c90fdb at 0x1336a0
 *   cfg: loop body is not one contiguous region: .L00133138
 *   cfg: kept branch: 0x133138 if (..) goto .L00133150
 *   cfg: kept goto: 0x133144 -> .L00133168
 *   declaration vs inferred signature: return void vs inferred float
 */

extern void AnimCurve(float *, float *, float *, float *, float *, float);

#ifndef PROTO_DW_40166_FIELDS
#define PROTO_DW_40166_FIELDS
struct dw_40166_fields { unsigned char *lpCamData; int nowIndex; float frame; unsigned char LockDirFlag; char LockL3V; char LockL3H; unsigned char noneUpdate; unsigned char eraseMap[256][48]; };
#endif
#ifndef PROTO_DW_49744_FIELDS
#define PROTO_DW_49744_FIELDS
struct dw_49744_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_52319_FIELDS
#define PROTO_DW_52319_FIELDS
struct dw_52319_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_50147_FIELDS
#define PROTO_DW_50147_FIELDS
struct dw_50147_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_53720_FIELDS
#define PROTO_DW_53720_FIELDS
struct dw_53720_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_53005_FIELDS
#define PROTO_DW_53005_FIELDS
struct dw_53005_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_40778_FIELDS
#define PROTO_DW_40778_FIELDS
struct dw_40778_fields { struct dw_49744_fields pmode; struct dw_52319_fields smode2; struct dw_50147_fields dispfb; struct dw_53720_fields display; struct dw_53005_fields bgcolor; };
#endif
#ifndef PROTO_DW_47916_FIELDS
#define PROTO_DW_47916_FIELDS
struct dw_47916_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_51985_FIELDS
#define PROTO_DW_51985_FIELDS
struct dw_51985_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_57495_FIELDS
#define PROTO_DW_57495_FIELDS
struct dw_57495_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_56264_FIELDS
#define PROTO_DW_56264_FIELDS
struct dw_56264_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_50759_FIELDS
#define PROTO_DW_50759_FIELDS
struct dw_50759_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_45713_FIELDS
#define PROTO_DW_45713_FIELDS
struct dw_45713_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_56940_FIELDS
#define PROTO_DW_56940_FIELDS
struct dw_56940_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_49625_FIELDS
#define PROTO_DW_49625_FIELDS
struct dw_49625_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_53301_FIELDS
#define PROTO_DW_53301_FIELDS
struct dw_53301_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_47263_FIELDS
#define PROTO_DW_47263_FIELDS
struct dw_47263_fields { struct dw_51985_fields frame1; unsigned long frame1addr; struct dw_57495_fields zbuf1; long zbuf1addr; struct dw_56264_fields xyoffset1; long xyoffset1addr; struct dw_50759_fields scissor1; long scissor1addr; struct dw_45713_fields prmodecont; long prmodecontaddr; struct dw_56940_fields colclamp; long colclampaddr; struct dw_49625_fields dthe; long dtheaddr; struct dw_53301_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_61416_FIELDS
#define PROTO_DW_61416_FIELDS
struct dw_61416_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_49403_FIELDS
#define PROTO_DW_49403_FIELDS
struct dw_49403_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_56788_FIELDS
#define PROTO_DW_56788_FIELDS
struct dw_56788_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_54224_FIELDS
#define PROTO_DW_54224_FIELDS
struct dw_54224_fields { struct dw_53301_fields testa; long testaaddr; struct dw_61416_fields prim; long primaddr; struct dw_49403_fields rgbaq; long rgbaqaddr; struct dw_56788_fields xyz2a; long xyz2aaddr; struct dw_56788_fields xyz2b; long xyz2baddr; struct dw_53301_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_57096_FIELDS
#define PROTO_DW_57096_FIELDS
struct dw_57096_fields { struct dw_40778_fields disp[2]; struct dw_47916_fields giftag0; struct dw_47263_fields draw0; struct dw_54224_fields clear0; struct dw_47916_fields giftag1; struct dw_47263_fields draw1; struct dw_54224_fields clear1; };
#endif
#ifndef PROTO_DW_41105_FIELDS
#define PROTO_DW_41105_FIELDS
struct dw_41105_fields { struct dw_57096_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED
#define DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED
enum { DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36 = (int)&(((struct dw_40166_fields *)0)->lpCamData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_40166_FIELDS_NOWINDEX_5D58E9A3 = (int)&(((struct dw_40166_fields *)0)->nowIndex) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A = (int)&(((struct dw_41105_fields *)0)->camAng[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__AF620303_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__AF620303_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__AF620303 = (int)&(((struct dw_41105_fields *)0)->camAng[0]) - 576 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1 = (int)&(((struct dw_41105_fields *)0)->camAng[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__9505CA95_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__9505CA95_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__9505CA95 = (int)&(((struct dw_41105_fields *)0)->camAng[1]) - 580 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__7BB547B3 = (int)&(((struct dw_41105_fields *)0)->camAng[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__87840938_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__87840938_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_2__87840938 = (int)&(((struct dw_41105_fields *)0)->camAng[2]) - 584 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_FOV_CEFE84D9_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_FOV_CEFE84D9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_FOV_CEFE84D9 = (int)&(((struct dw_41105_fields *)0)->fov) - 0 };
#endif
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
struct CamKey2 { u16 frame; u16 len; u8 pad[12]; float p[4]; float b[4]; float c[4]; };
struct CamKey { u16 frame; u16 len; u8 pad[12]; float p[4]; float b[4]; float c[4]; };
struct CamFovKey { u16 frame; u16 len; float v; float pad[2]; };
static inline void * GetCamPathData__ic(void *a0, signed int a1) {
    s32 a2;
    u32 v1;
    u32 v0;
    void *a0_v;

    v1 = *(s32 *)a0;
    a0_v = (void *)*(u16 *)((v1 + 0xe));
    v0 = *(s32 *)((v1 + 0x18));
    a2 = 0;
    if (0 < (s32)a0_v) {
        do {
            v1 = *(u16 *)((v0 + 0x10));
            if (v1 == (u32)(s32)a1) {
                return (void *)v0;
            }
            a2 = a2 + 1;
            v1 = a2 < (s32)a0_v;
            v0 = v0 + 0x70;
        } while (v1 != 0);
    }
    return (void *)(u32)0;
}






/* UpdateTargetCam @ 0x132BF0 .. 0x1330F4 (0x504 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x30 escapes at 0x132c54
 *   fpu: float literal 0x3fa66666 at 0x132c6c
 *   fpu: mov.s at 0x132c80 is a float copy
 *   fpu: mov.s at 0x132cc8 is a float copy
 *   fpu: mov.s at 0x132ccc is a float copy
 *   fpu: float literal 0x40490fdb at 0x132ce4
 *   fpu: float literal 0x00000000 at 0x132ce8
 *   fpu: float literal 0x40c90fdb at 0x132d14
 *   fpu: float literal 0x40c90fdb at 0x132d3c
 *   fpu: float literal 0x40490fdb at 0x132d6c
 *   fpu: float literal 0x00000000 at 0x132d70
 *   fpu: float literal 0x40c90fdb at 0x132d90
 *   fpu: float literal 0x40c90fdb at 0x132db8
 *   fpu: float literal 0x3c8ef34d at 0x132df0
 *   fpu: mtc1 reinterprets a0 at 0x132dfc
 *   fpu: mtc1 reinterprets v1 at 0x132e10
 *   fpu: float literal 0x40000000 at 0x132e2c
 *   fpu: float literal 0x00000000 at 0x132e48
 *   fpu: mov.s at 0x132ea8 is a float copy
 *   fpu: float literal 0x00000000 at 0x132eac
 *   fpu: mov.s at 0x132ecc is a float copy
 *   fpu: mov.s at 0x132ee4 is a float copy
 *   fpu: mov.s at 0x132eec is a float copy
 *   fpu: mov.s at 0x132ef8 is a float copy
 *   fpu: float literal 0x00000000 at 0x132efc
 *   fpu: mov.s at 0x132f1c is a float copy
 *   fpu: mov.s at 0x132f34 is a float copy
 *   fpu: float literal 0x3c8ef34d at 0x132f6c
 *   fpu: mtc1 reinterprets a0 at 0x132f78
 *   fpu: mtc1 reinterprets v1 at 0x132f8c
 *   fpu: float literal 0x40000000 at 0x132fa8
 *   fpu: float literal 0x00000000 at 0x132fc4
 *   fpu: mov.s at 0x133024 is a float copy
 *   fpu: float literal 0x00000000 at 0x133028
 *   fpu: mov.s at 0x133048 is a float copy
 *   fpu: mov.s at 0x133060 is a float copy
 *   fpu: mov.s at 0x133068 is a float copy
 *   fpu: mov.s at 0x133074 is a float copy
 *   fpu: float literal 0x00000000 at 0x133078
 *   fpu: mov.s at 0x133098 is a float copy
 *   fpu: mov.s at 0x1330b0 is a float copy
 *   cfg: loop body is not one contiguous region: .L00132C20
 *   cfg: kept branch: 0x132c20 if (..) goto .L00132C38
 *   cfg: kept goto: 0x132c2c -> .L00132C50
 *   declaration vs inferred signature: return void vs inferred u32
 */

#ifndef PROTO_DW_40166_FIELDS
#define PROTO_DW_40166_FIELDS

#endif
#ifndef PROTO_DW_49744_FIELDS
#define PROTO_DW_49744_FIELDS

#endif
#ifndef PROTO_DW_52319_FIELDS
#define PROTO_DW_52319_FIELDS

#endif
#ifndef PROTO_DW_50147_FIELDS
#define PROTO_DW_50147_FIELDS

#endif
#ifndef PROTO_DW_53720_FIELDS
#define PROTO_DW_53720_FIELDS

#endif
#ifndef PROTO_DW_53005_FIELDS
#define PROTO_DW_53005_FIELDS

#endif
#ifndef PROTO_DW_40778_FIELDS
#define PROTO_DW_40778_FIELDS

#endif
#ifndef PROTO_DW_47916_FIELDS
#define PROTO_DW_47916_FIELDS

#endif
#ifndef PROTO_DW_51985_FIELDS
#define PROTO_DW_51985_FIELDS

#endif
#ifndef PROTO_DW_57495_FIELDS
#define PROTO_DW_57495_FIELDS

#endif
#ifndef PROTO_DW_56264_FIELDS
#define PROTO_DW_56264_FIELDS

#endif
#ifndef PROTO_DW_50759_FIELDS
#define PROTO_DW_50759_FIELDS

#endif
#ifndef PROTO_DW_45713_FIELDS
#define PROTO_DW_45713_FIELDS

#endif
#ifndef PROTO_DW_56940_FIELDS
#define PROTO_DW_56940_FIELDS

#endif
#ifndef PROTO_DW_49625_FIELDS
#define PROTO_DW_49625_FIELDS

#endif
#ifndef PROTO_DW_53301_FIELDS
#define PROTO_DW_53301_FIELDS

#endif
#ifndef PROTO_DW_47263_FIELDS
#define PROTO_DW_47263_FIELDS

#endif
#ifndef PROTO_DW_61416_FIELDS
#define PROTO_DW_61416_FIELDS

#endif
#ifndef PROTO_DW_49403_FIELDS
#define PROTO_DW_49403_FIELDS

#endif
#ifndef PROTO_DW_56788_FIELDS
#define PROTO_DW_56788_FIELDS

#endif
#ifndef PROTO_DW_54224_FIELDS
#define PROTO_DW_54224_FIELDS

#endif
#ifndef PROTO_DW_57096_FIELDS
#define PROTO_DW_57096_FIELDS

#endif
#ifndef PROTO_DW_41105_FIELDS
#define PROTO_DW_41105_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED
#define DCOMP_OFF_STRUCT_DW_40166_FIELDS_LPCAMDATA_C8941E36_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__76A5B89A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__AF620303_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_0__AF620303_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__0577DBD1_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__9505CA95_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMANG_1__9505CA95_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_0__68BDF4A0 = (int)&(((struct dw_41105_fields *)0)->camPos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_1__B321F7DE = (int)&(((struct dw_41105_fields *)0)->camPos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846_DEFINED
#define DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846_DEFINED
enum { DCOMP_OFF_STRUCT_DW_41105_FIELDS_CAMPOS_2__BB809846 = (int)&(((struct dw_41105_fields *)0)->camPos[2]) - 0 };
#endif
#define WRAPF(a) ((3.14159274f + (a) >= 0.0f) ? ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f)) : (6.28318548f + ((a) - 6.28318548f * (float)(s32)((3.14159274f + (a)) / 6.28318548f))))
#define DM ((struct dw_41105_fields *)lpDrawMng)
#define ABSF(x) (((x) < 0.0f) ? -(x) : (x))
extern float sqrtf(float);


/* SetCamEnv @ 0x1323C0 .. 0x1324A8 (0xe8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x132424
 *   cfg: loop leaves to a block that is not its join: 0x1323fc -> 0x132420
 *   cfg: kept branch: 0x1323f0 if (..) goto .L00132408
 *   cfg: kept goto: 0x1323fc -> .L00132420
 *   cfg: kept branch: 0x132408 if (..) goto .L001323F0
 *   cfg: kept branch: 0x132438 if (..) goto .L00132470
 *   cfg: kept branch: 0x132448 if (..) goto .L00132470
 *   inlcall: line 1306 is GetCamPathData expanded inline
 *   inlcall: line 1309 is SetCamAmbient expanded inline
 */
/* r4 */


static inline void * GetCamPathData__inl(void *a0, signed int a1) {
    s32 a2;
    u32 v1;
    u32 v0;
    void *a0_v;

    v1 = *(s32 *)a0;
    a0_v = (void *)*(u16 *)((v1 + 0xe));
    v0 = *(s32 *)((v1 + 0x18));
    a2 = 0;
    if (0 < (s32)a0_v) {
        do {
            v1 = *(u16 *)((v0 + 0x10));
            if (v1 == (u32)(s32)a1) {
                return (void *)v0;
            }
            a2 = a2 + 1;
            v1 = a2 < (s32)a0_v;
            v0 = v0 + 0x70;
        } while (v1 != 0);
    }
    return (void *)(u32)0;
}



static inline void SetCamAmbient__inl(void *a0) {
    float f1;
    float *s0;
    float f0;
    s32 fpcc;

    f1 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x5c));
    f0 = *(float *)s0;
    fpcc = f1 == f0;
    if (fpcc) {
        f0 = *(float *)(((u8 *)s0 + 4));
        fpcc = f1 == f0;
        if (!fpcc) {
            goto _L00132710;
        }
        f0 = *(float *)(((u8 *)s0 + 8));
        fpcc = f1 == f0;
        a0 = (void *)(s32)s0;
        if (!fpcc) {
            goto _L00132710;
        }
        GetMapAmbient(a0);
        a0 = (void *)(s32)s0;
        SetAmbientColor((float *)a0);
    } else {
        _L00132710:;
        a0 = (void *)(s32)s0;
        SetAmbientColor((float *)a0);
    }
    return;
}






extern float SfxCalc_IntoAngle_0_2PI(float);
#define VAF(i) (*(float *)(s_vibration_act + (i)))


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 GetCameraPos(void);
u32 GetCameraAng(void);
void InitCamera(void);
void RemapCamData(void *data);
void SetCameraPos(float *a0 );
void SetCameraAng(float *a0 );
void SetCameraFov(float f12 );
void UpdateCamera(void);
unsigned int CheckBackOfCamera(float *a0 );
unsigned int CheckPosOutOfSight(float *a0 );
unsigned int CheckDrawMapByCamParam(signed int a0 );
void SetEraseMapData(struct dw_40166 *a0 );
void * GetCamPathData(void *a0 , signed int a1 );
static signed int CheckHitCamWall(void *data,void *object,signed int id);
void UpdateCamAnim(void *lpCamInfo_, void *lpTarget_);
static void UpdateTargetCam(void *lpCamInfo, signed int index, void *lpTarget);
static float GetCamFrame(void *scene, void *camera, int id);
void SetCamDirLockFlag(char a0 , char a1 );
unsigned int CheckCamDirLock(char x, char y);
void FreeGameCamData(signed int a0 );
void FreeDramaCamData(void);
signed int GetCurCamID(void);
u8 * GetCamInfo(void);
u32 GetDramaCamInfo(s32 a0 );
u8 * GetGameCamInfo(void);
void SetCamAmbient(void *a0 );
void SetCamReverb(void *a0 );
void SetCamCtrlMode(u_int mode);
u32 GetCamCtrlMode(void);
void SetTargetFreeCamera(signed int id);
void SetCamEnv(void *a0 , signed int a1 );
void SetCamPathDirect(signed int id);
void SetCamVibration(void *a0 );
void StartCamVibration(s32 a0 , float f12 );
void UpdateCamVib(void);


/* GetCameraPos @ 0x1348A0 .. 0x1348AC (0xc bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1348a8 computes the return value
 */


u32 GetCameraPos(void) {
    u32 v0;

    v0 = ((u32)lpDrawMng);
    return v0 + 0x250;
}






/* GetCameraAng @ 0x134890 .. 0x13489C (0xc bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x134898 computes the return value
 */


u32 GetCameraAng(void) {
    u32 v0;

    v0 = ((u32)lpDrawMng);
    return v0 + 0x260;
}
void InitCamera(void) {
    struct dw_43036_fields *lpMy;
    float CharPos[4];
    float CharAng[4];
    struct dw_40166_fields *lpCamInfo;
    float *lpSaveData;
    u32 nidx;
    u32 nidx0;
    u8 *cam;
    float *pChar;
    float *s3;
    float f0, f1;
    int ok;
    u32 idx;

    lpCamInfo = (struct dw_40166_fields *)GameCamInfo;
    CamCtrlMode = 0;
    lpMy = (struct dw_43036_fields *)(MdlMng + 0x4600);
    if (((struct dw_54698_fields *)GameSt)->GameMode == 4) {
        memset(lpCamInfo, 0, 0x3010);
        {
            float v[4] = {0.0f, -0.5f, -5.0f, 1.0f};
            ((struct dw_41105_fields *)lpDrawMng)->camPos[0] = v[0];
            ((struct dw_41105_fields *)lpDrawMng)->camPos[1] = v[1];
            ((struct dw_41105_fields *)lpDrawMng)->camPos[2] = v[2];
            ((struct dw_41105_fields *)lpDrawMng)->camPos[3] = 1.0f;
            {
                float w[4] = {0.0f, 0.0f, 0.0f, 1.0f};
                ((struct dw_41105_fields *)lpDrawMng)->camAng[0] = w[0];
                ((struct dw_41105_fields *)lpDrawMng)->camAng[1] = w[1];
                ((struct dw_41105_fields *)lpDrawMng)->camAng[2] = w[2];
                ((struct dw_41105_fields *)lpDrawMng)->camAng[3] = 1.0f;
            }
        }
    } else {
        SetEraseMapData__ic((struct dw_40166 *)lpCamInfo);
        lpCamInfo->nowIndex = (u16)GetCamIdAfterLoad();
        if (((struct dw_54698_fields *)GameSt)->LoadStart != 0) {
            lpSaveData = (float *)GetSaveData();
            lpMy->Pos[0] = lpSaveData[0];
            lpMy->Pos[1] = lpSaveData[1];
            lpMy->Pos[2] = lpSaveData[2];
            lpMy->Pos[3] = 1.0f;
            lpMy->Ang[1] = lpSaveData[3];
            sceVu0CopyVector(lpMy->PosB, lpMy->Pos);
            sceVu0CopyVector(lpMy->AngB, lpMy->Ang);
            *((u8 *)GameSt + 0x1d) = 0;
        } else {
            for (;; lpCamInfo->nowIndex = lpCamInfo->nowIndex + 1) {
                nidx0 = lpCamInfo->nowIndex;
                cam = (u8 *)GetCamPathData__ic2(lpCamInfo, nidx0);
                pChar = (float *)*(s32 *)(cam + 0x54);
                if (pChar != 0) {
                    sceVu0CopyVector(CharPos, pChar);
                    ok = 1;
                } else {
                    ok = 0;
                }
                if (ok == 0) {
                    continue;
                }
                CharPos[3] = 1.0f;
                sceVu0CopyVector(lpMy->Pos, CharPos);
                sceVu0CopyVector(lpMy->PosB, lpMy->Pos);
                nidx = lpCamInfo->nowIndex;
                cam = (u8 *)GetCamPathData__ic2(lpCamInfo, nidx);
                pChar = (float *)*(s32 *)(cam + 0x54);
                if (*(u8 *)(cam + 0x5a) == 0) {
                    ok = 0;
                } else {
                    sceVu0CopyVector(CharAng, (u8 *)pChar + 0x10);
                    ok = 1;
                }
                if (ok == 0) {
                    break;
                }
                lpMy->Ang[1] = DCOMP_EXPR_F4392B91E5A8C94E(CharAng[1]);
                break;
            }
        }
        InitSceneLoadFlag();
        idx = lpCamInfo->nowIndex;
        cam = (u8 *)GetCamPathData__ic2(lpCamInfo, idx);
        s3 = (float *)*(s32 *)(cam + 0x5c);
        f1 = 0.0f;
        f0 = s3[0];
        if (0.0f == f0) {
            f0 = s3[1];
            if (!(f1 == f0)) {
                goto amb;
            }
            f0 = s3[2];
            if (!(f1 == f0)) {
                goto amb;
            }
            GetMapAmbient(s3);
            SetAmbientColor(s3);
        } else {
amb:
            SetAmbientColor(s3);
        }
        SetCamReverb(cam);
        SetMirror(((struct dw_54698_fields *)GameSt)->sceneNo, idx);
        UpdateCamera();
        if (lpCamInfo->lpCamData == 0) {
            ((struct dw_54698_fields *)GameSt)->ControlMode = 1;
        }
    }
    memset(s_vibration, 0, 0x10);
}








void RemapCamData(void *data)
{
    u8 *base=data;
    u32 offset;
    if(base!=0) {
        offset=*(u32 *)(base+24);
        if(offset!=0) *(u32 *)(base+24)=(u32)base+offset;
        offset=*(u32 *)(base+28);
        if(offset!=0) *(u32 *)(base+28)=(u32)base+offset;
        offset=*(u32 *)(base+32);
        if(offset!=0) *(u32 *)(base+32)=(u32)base+offset;
        {
            CameraRemapSecond *second;
            s32 i;
            CameraRemapEntry *pointer;
            s32 count;
            u32 offset;
            count=*(u16 *)(base+14);
            pointer=(CameraRemapEntry *)*(u32 *)(base+24);
            i=0;
            if(0<(s32)count) do {
                offset=pointer->p64; if(offset!=0) pointer->p64=(u32)base+offset;
                offset=pointer->p68; if(offset!=0) pointer->p68=(u32)base+offset;
                offset=pointer->p72; if(offset!=0) pointer->p72=(u32)base+offset;
                offset=pointer->p76; if(offset!=0) pointer->p76=(u32)base+offset;
                offset=pointer->p80; if(offset!=0) pointer->p80=(u32)base+offset;
                offset=pointer->p84; if(offset!=0) pointer->p84=(u32)base+offset;
                offset=pointer->p92; if(offset!=0) pointer->p92=(u32)base+offset;
                offset=pointer->p96; if(offset!=0) pointer->p96=(u32)base+offset;
                count=*(u16 *)(base+14);
                i++; pointer++;
            } while(i<count);
            if(base[38]==0) {
                s32 j;
                u32 offset;
                second=(CameraRemapSecond *)*(u32 *)(base+28); j=0;
                if(0<(s32)count) do {
                    offset=second->p20; if(offset!=0) second->p20=(u32)base+offset;
                    j++; second++;
                } while(j<(s32)*(u16 *)(base+14));
            }
        }
        {
            s32 count;
            CameraRemapThird *pointer;
            s32 i;
            u32 offset;
            count=*(u16 *)(base+18);
            pointer=(CameraRemapThird *)*(u32 *)(base+32); i=0;
            if(0<count) do {
                offset=pointer->p40; if(offset!=0) pointer->p40=(u32)base+offset;
                offset=pointer->p44; if(offset!=0) pointer->p44=(u32)base+offset;
                i++; pointer++;
            } while(i<(s32)*(u16 *)(base+18));
        }
    }
}











/* SetCameraPos @ 0x1341B0 .. 0x1341E4 (0x34 bytes) */



void SetCameraPos(float *a0 /* r4 */) {
    float f0;
    u8 *v1;

    f0 = *(float *)a0;
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x230) = f0;
    f0 = a0[1];
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x234) = f0;
    f0 = a0[2];
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x238) = f0;
    v1 = lpDrawMng;
    *(u32 *)(v1 + 0x23c) = 0x3f800000;
    return;
}









/* SetCameraAng @ 0x134170 .. 0x1341A4 (0x34 bytes) */



void SetCameraAng(float *a0 /* r4 */) {
    float f0;
    u8 *v1;

    f0 = *(float *)a0;
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x240) = f0;
    f0 = a0[1];
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x244) = f0;
    f0 = a0[2];
    v1 = lpDrawMng;
    *(f32 *)(v1 + 0x248) = f0;
    v1 = lpDrawMng;
    *(u32 *)(v1 + 0x24c) = 0x3f800000;
    return;
}







/* SetCameraFov @ 0x134160 .. 0x13416C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j DrawSetViewRange at 0x134164 leaves the function
 */


void SetCameraFov(float f12 /* f12 */) {
    float *v0;

    v0 = (float *)((u32)lpDrawMng);
    *(f32 *)(((u8 *)v0 + 0x41c)) = (float)f12;
    DrawSetViewRange();
    return;
}





/* UpdateCamera @ 0x133CD0 .. 0x134160 (0x490 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @995 -> 0x228560
 *   stack: address of the slot at 0x60 escapes at 0x133d00
 *   stack: address of the slot at 0x60 escapes at 0x133d14
 *   stack: address of the slot at 0x60 escapes at 0x133d14
 *   stack: address of the slot at 0x60 escapes at 0x133d28
 *   stack: address of the slot at 0x60 escapes at 0x133d28
 *   stack: address of the slot at 0x60 escapes at 0x133d3c
 *   stack: address of the slot at 0x60 escapes at 0x133d3c
 *   stack: address of the slot at 0xa0 escapes at 0x133d4c
 *   stack: address of the slot at 0x60 escapes at 0x133d4c
 *   stack: address of the slot at 0xa0 escapes at 0x133d4c
 *   delay: addiu at 0x133dc8 writes a register its branch at 0x133dc4 reads
 *   fpu: float literal 0x00000000 at 0x133e84
 *   fpu: float literal 0x00000000 at 0x133fa4
 *   fpu: float literal 0x00000000 at 0x1340bc
 *   literal: @995 initializes the 16-byte local at 0xa0
 *   cfg: loop body is not one contiguous region: .L00133E50
 *   cfg: kept branch: 0x133e50 if (..) goto .L00133E68
 *   cfg: kept goto: 0x133e5c -> .L00133E80
 *   cfg: kept branch: 0x133e98 if (..) goto .L00133ED0
 *   cfg: kept branch: 0x133ea8 if (..) goto .L00133ED0
 *   cfg: loop body is not one contiguous region: .L00133F70
 *   cfg: kept branch: 0x133f70 if (..) goto .L00133F88
 *   cfg: kept goto: 0x133f7c -> .L00133FA0
 *   cfg: kept branch: 0x133fb8 if (..) goto .L00133FF0
 *   cfg: kept branch: 0x133fc8 if (..) goto .L00133FF0
 *   cfg: loop body is not one contiguous region: .L00134088
 *   cfg: kept branch: 0x134088 if (..) goto .L001340A0
 *   cfg: kept goto: 0x134094 -> .L001340B8
 *   cfg: kept branch: 0x1340d0 if (..) goto .L00134108
 *   cfg: kept branch: 0x1340e0 if (..) goto .L00134108
 */


void UpdateCamera(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    float f12;
    u32 v1;
    u32 v0;
    float f4;
    float f2;
    float f1;
    float f0;
    u8 *s4;
    u8 *s3;
    u8 *s2;
    u32 s1;
    u8 *s0;
    u8 *selected;
    s32 loopIndex;
    s32 loopCount;
    struct stackFrame_A0 { u8 b[16]; } stackFrame_A0 __attribute__((aligned(16))) = {{0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00}};
    u8 stackFrame_60[64] __attribute__((aligned(16)));

    v0 = (u32)L995;
    v1 = (u32)((u8 *)&stackFrame_A0);
    sceVu0UnitMatrix((void *)((u8 *)&stackFrame_60[0]));
    v0 = (u32)lpDrawMng;
    sceVu0RotMatrixZ((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_60[0]), *(float
        *)((v0 + 0x248)));
    v0 = (u32)lpDrawMng;
    sceVu0RotMatrixX((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_60[0]), *(float
        *)((v0 + 0x240)));
    v0 = (u32)lpDrawMng;
    f12 = *(float *)((v0 + 0x244));
    sceVu0RotMatrixY((void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_60[0]), f12);
    sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_A0), (void *)((u8 *)&stackFrame_60[0]), (void *)((u8 *)&stackFrame_A0));
    f0 = *(float *)((u8 *)&stackFrame_A0);
    v1 = (u32)lpDrawMng;
    *(f32 *)((v1 + 0x440)) = f0;
    f0 = *(float *)((u8 *)&stackFrame_A0 + 0x4);
    v1 = (u32)lpDrawMng;
    *(f32 *)((v1 + 0x444)) = f0;
    f0 = *(float *)((u8 *)&stackFrame_A0 + 0x8);
    v1 = (u32)lpDrawMng;
    *(f32 *)((v1 + 0x448)) = f0;
    v1 = (u32)lpDrawMng;
    f1 = *(float *)((v1 + 0x448));
    f4 = (*(float *)((v1 + 0x440)) * *(float *)((v1 + 0x230)));
    f2 = (*(float *)((v1 + 0x444)) * *(float *)((v1 + 0x234)));
    f0 = (-((f4 + f2) + (f1 * *(float *)((v1 + 0x238)))));
    *(f32 *)((v1 + 0x44c)) = f0;
    v1 = *(u8 *)((u8 *)&GameCamInfo + 0xf);
    if (v1 == 0) {
        v1 = CamCtrlMode;
        v0 = 2;
        switch (v1) {
        case 0:
            v0 = *(s32 *)GameCamInfo;
            s3 = (u8 *)(MdlMng + 0x4600);
            s2 = (u8 *)GameCamInfo;
            if (v0 == 0) {
                break;
            }
            a2 = *(s32 *)(s2 + 4);
            v0 = CheckHitCamWall((void *)s2, (void *)s3, a2);
            if ((s32)v0 >= 0) {
                *(u32 *)(s2 + 4) = v0;
                v0 = 1;
                *(u8 *)(s2 + 0xc) = v0;
                v0 = *(s32 *)s2;
                s1 = *(s32 *)(s2 + 4);
                v1 = *(u16 *)((v0 + 0xe));
                s0 = (u8 *)*(s32 *)((v0 + 0x18));
                a0 = 0;
                if (0 < (s32)v1) {
                    do {
                        if (*(u16 *)(s0 + 0x10) == s1) {
                            selected = s0;
                            goto _L00133E80;
                        }
                        a0 = a0 + 1;
                        v0 = (s32)a0 < (s32)v1;
                        s0 = (u8 *)(s0 + 0x70);
                    } while (v0 != 0);
                }
                selected = (u8 *)0;
                _L00133E80:;
                s0 = selected;
                s4 = (u8 *)*(s32 *)(s0 + 0x5c);
                f1 = 0.0f;
                f0 = *(float *)s4;
                if (0.0f == f0) {
                    f0 = *(float *)(s4 + 4);
                    if (!(f1 == f0)) {
                        goto _L00133ED0;
                    }
                    f0 = *(float *)(s4 + 8);
                    a0 = (s32)s4;
                    if (!(f1 == f0)) {
                        goto _L00133ED0;
                    }
                    GetMapAmbient((void *)a0);
                    SetAmbientColor((float *)s4);
                } else {
                    _L00133ED0:;
                    SetAmbientColor((float *)s4);
                }
                SetCamReverb((void *)s0);
                a0 = *(u8 *)((u8 *)&GameSt + 9);
                SetMirror(a0, s1);
            }
            a2 = *(s32 *)(s2 + 4);
            f0 = GetCamFrame((void *)s2, (void *)s3, a2);
            *(f32 *)(s2 + 8) = f0;
            UpdateCamAnim((void *)s2, (void *)s3);
            break;
        case 1:
            v0 = CheckHitCamWall((void *)GameCamInfo, (void *)(u8 *)(MdlMng + 0x4600), GameCamInfo[1]);
            if ((s32)v0 < 0) {
                break;
            }
            GameCamInfo[1] = v0;
            v0 = 1;
            *(u8 *)(GameCamInfo + 3) = v0;
            s1 = GameCamInfo[1];
            v0 = *(s32 *)GameCamInfo;
            loopCount = (s32)*(u16 *)(v0 + 0xe);
            s0 = (u8 *)*(s32 *)((v0 + 0x18));
            loopIndex = 0;
            if (0 < loopCount) {
                do {
                    if (*(u16 *)(s0 + 0x10) == s1) {
                        selected = s0;
                        goto _L00133FA0;
                    }
                    loopIndex = loopIndex + 1;
                    v0 = loopIndex < loopCount;
                    s0 = (u8 *)(s0 + 0x70);
                } while (v0 != 0);
            }
            selected = (u8 *)0;
            _L00133FA0:;
            s0 = selected;
            s2 = (u8 *)*(s32 *)(s0 + 0x5c);
            f1 = 0.0f;
            f0 = *(float *)s2;
            if (0.0f == f0) {
                f0 = *(float *)(s2 + 4);
                if (!(f1 == f0)) {
                    goto _L00133FF0;
                }
                f0 = *(float *)(s2 + 8);
                a0 = (s32)s2;
                if (!(f1 == f0)) {
                    goto _L00133FF0;
                }
                GetMapAmbient((void *)a0);
                SetAmbientColor((float *)s2);
            } else {
                _L00133FF0:;
                SetAmbientColor((float *)s2);
            }
            SetCamReverb((void *)s0);
            a0 = *(u8 *)((u8 *)&GameSt + 9);
            SetMirror(a0, s1);
            break;
        case 3: {
            s32 scanIndex;
            s32 scanCount;
            a1 = CamId4FreeTarget;
            a0 = (u32)GameCamInfo;
            UpdateTargetCam((void *)GameCamInfo, a1, (void *)(u8 *)(MdlMng + 0x4600));
            v0 = CheckHitCamWall((void *)GameCamInfo, (void *)(u8 *)(MdlMng + 0x4600), GameCamInfo[1]);
            if ((s32)v0 < 0) {
                break;
            }
            GameCamInfo[1] = v0;
            v0 = 1;
            *(u8 *)(GameCamInfo + 3) = v0;
            s1 = GameCamInfo[1];
            v0 = *(s32 *)GameCamInfo;
            scanCount = (s32)*(u16 *)(v0 + 0xe);
            s0 = (u8 *)*(s32 *)((v0 + 0x18));
            scanIndex = 0;
            if (0 < scanCount) {
                do {
                    if (*(u16 *)(s0 + 0x10) == s1) {
                        selected = s0;
                        goto _L001340B8;
                    }
                    scanIndex = scanIndex + 1;
                    v0 = scanIndex < scanCount;
                    s0 = (u8 *)(s0 + 0x70);
                } while (v0 != 0);
            }
            selected = (u8 *)0;
            _L001340B8:;
            s0 = selected;
            s2 = (u8 *)*(s32 *)(s0 + 0x5c);
            f1 = 0.0f;
            f0 = *(float *)s2;
            if (0.0f == f0) {
                f0 = *(float *)(s2 + 4);
                if (!(f1 == f0)) {
                    goto _L00134108;
                }
                f0 = *(float *)(s2 + 8);
                a0 = (s32)s2;
                if (!(f1 == f0)) {
                    goto _L00134108;
                }
                GetMapAmbient((void *)a0);
                SetAmbientColor((float *)s2);
            } else {
                _L00134108:;
                SetAmbientColor((float *)s2);
            }
            SetCamReverb((void *)s0);
            a0 = *(u8 *)((u8 *)&GameSt + 9);
            SetMirror(a0, s1);
            break;
        }
        case 2:
            UpdatePeepCamera();
        }
        UpdateCamVib();
    }
    return;
}








/* CheckBackOfCamera @ 0x133C80 .. 0x133CD0 (0x50 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x133c90
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */






unsigned int CheckBackOfCamera(float *a0 /* r4 */) {
    u8 *v1;

    v1 = (u8 *)lpDrawMng;
    return (*(float *)(v1 + 0x44c) + (((*(float *)(v1 + 0x440) * *(float *)a0) + (*(float *)(v1 +
        0x444) * a0[1])) + (*(float *)(v1 + 0x448) * a0[2]))) > 0.0f;
}







/* CheckPosOutOfSight @ 0x133BF0 .. 0x133C80 (0x90 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x133c24 is a float copy
 *   fpu: float literal 0x00000000 at 0x133c28
 *   fpu: float literal 0x3f490624 at 0x133c48
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */



unsigned int CheckPosOutOfSight(float *a0 /* r4 */) {
    u8 *s0;
    float f12;
    float f1;
    float f0;

    s0 = (u8 *)lpDrawMng;
    f12 = (*(float *)a0 - *(float *)(s0 + 0x230));
    f0 = Math_VectorToAngle(f12, (a0[2] - *(float *)(s0 + 0x238)));
    f0 = Math_GetAngleDist((float)f0, *(float *)(s0 + 0x244));
    f1 = 0.0f;
    if (f0 < 0.0f) {
        f0 = (-f0);
    }
    f1 = 0.785249949f;
    if (!(f0 <= 0.785249949f)) {
        return 1;
    }
    return 0;
}





/* CheckDrawMapByCamParam @ 0x133B10 .. 0x133BF0 (0xe0 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x133ba0 writes a register its branch at 0x133b9c reads
 *   delay: daddu at 0x133bd0 writes a register its branch at 0x133bcc reads
 *   cfg: kept branch: 0x133b80 if (..) goto .L00133BE0
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */


unsigned int CheckDrawMapByCamParam(signed int a0 /* r4 */) {
    u32 a1;
    u32 v1;
    u32 v0;

    v0 = 1;
    v1 = ((u8 *)GameSt)[5];
    switch (v1) {
    case 1:
        v1 = lpDramaMng;
        v0 = (u32)DramaCamInfo;
        a1 = *(u16 *)((v1 + 0xc));
        v1 = a1 * (u32)(0x3010);
        a1 = (s32)((u8 *)DramaCamInfo + v1);
        break;
    default:
        a1 = (u32)GameCamInfo;
    }
    v1 = CamCtrlMode;
    v0 = 3;
    switch (v1) {
    case 3:
        v1 = CamId4FreeTarget;
        v0 = v1 * (u32)(0x30);
        v0 = v0 + a1;
        v0 = (u32)(a0) + (u32)v0;
        v0 = *(u8 *)((v0 + 0x10));
        if (v0 == 0) {
            goto _L00133BE0;
        }
        v0 = 0;
        return v0;
    }
    v1 = *(s32 *)((a1 + 4));
    v0 = v1 * (u32)(0x30);
    v0 = v0 + a1;
    v0 = (u32)(a0) + (u32)v0;
    v0 = *(u8 *)((v0 + 0x10));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    _L00133BE0:;
    v0 = 1;
    return v0;
}






/* SetEraseMapData @ 0x133A80 .. 0x133B10 (0x90 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00133AA0
 *   declaration vs inferred signature: return void vs inferred u32
 */





void SetEraseMapData(struct dw_40166 *a0 /* r4 */) {
    struct dw_42407 *t2;
    struct dw_46050 *t1;
    s32 t0;
    s32 a3;
    u32 a2;
    u32 a1;
    u32 v1;

    t2 = (struct dw_42407 *)(s32)a0->lpCamData;
    if ((u32)(s32)(u8 *)t2 != 0) {
        t1 = (struct dw_46050 *)t2->camPath;
        t0 = 0;
        for (; t0 < (s32)t2->cam_num; t0 = t0 + 1) {
            a3 = 0;
            for (; a3 < (s32)t2->map_parts_num; a3 = a3 + 1) {
                a0->eraseMap[t1->cam_id][a3] = *(u8 *)(u32)(a3 + t1->mapInfo);
            }
            t1 = (struct dw_46050 *)((u8 *)(u8 *)t1 + 0x70);
        }
    }
    return;
}






/* GetCamPathData @ 0x133A30 .. 0x133A80 (0x50 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00133A48
 *   declaration vs inferred signature: return void * vs inferred u32
 */





void * GetCamPathData(void *a0 /* r4 */, signed int a1 /* r5 */) {
    s32 a2;
    u32 v1;
    u32 v0;

    v1 = *(s32 *)a0;
    a0 = (void *)*(u16 *)((v1 + 0xe));
    v0 = *(s32 *)((v1 + 0x18));
    a2 = 0;
    if (0 < (s32)a0) {
        do {
            v1 = *(u16 *)((v0 + 0x10));
            if (v1 == (u32)(s32)a1) {
                return (void *)v0;
            }
            a2 = a2 + 1;
            v1 = a2 < (s32)a0;
            v0 = v0 + 0x70;
        } while (v1 != 0);
    }
    return (void *)(u32)0;
}


static signed int CheckHitCamWall(void *data,void *object,signed int id) {
    s32 group;
    u8 *wall;
    u32 *face;
    u32 vertices;
    float *point;
    u32 *indices;
    u32 section;
    u32 triangle;
    u8 *selected;
    float polygon[6][4] __attribute__((aligned(16)));
    float line[2][4] __attribute__((aligned(16)));
    float hit[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    float end[4] __attribute__((aligned(16)));
    float start[4] __attribute__((aligned(16)));
    if (*(s32 *)((u8 *)object+0x120)<=0) return -1;
    sceVu0CopyVector(end,(u8 *)object+0x20);
    sceVu0CopyVector(start,(u8 *)object+0x70);
    end[1]-=0.5f;
    start[1]-=0.5f;
    sceVu0SubVector(delta,end,start);
    sceVu0CopyVector(line[0],start);
    sceVu0CopyVector(line[1],delta);
    {
        u8 *record=*(u8 **)data;
        u8 *entry=*(u8 **)(record+0x18);
        s32 i;
        s32 count=*(u16 *)(record+14);
        i=0;
        if (0<count) {
            do {
                if (*(u16 *)(entry+16)==id) {selected=entry;goto selectedWall;}
                i++;
                entry+=0x70;
            } while(i<count);
        }
        selected=0;
    }
selectedWall:
    wall=*(u8 **)(selected+0x4c);
    section=0;
    if (0 < *(u16 *)(selected+0x1a)) {
        point=polygon[1];
        do {
            face=*(u32 **)(wall+0x28);
            group=0;
            face++;
            if (0 < *(u16 *)(wall+0x26)) {
                do {
                    vertices=*face;
                    triangle=2;
                    if(vertices>2) {
                        indices=face+2;
                        do {
                            sceVu0CopyVector(polygon[0],(void *)(*(u32 *)(wall+0x2c)+(indices[-1]<<4)));
                            sceVu0CopyVector(point,(void *)(*(u32 *)(wall+0x2c)+(indices[0]<<4)));
                            sceVu0CopyVector(polygon[2],(void *)(*(u32 *)(wall+0x2c)+(indices[1]<<4)));
                            sceVu0SubVector(polygon[3],point,polygon[0]);
                            sceVu0SubVector(polygon[4],polygon[2],polygon[0]);
                            if (((fsHit_GetHitPolygonLine(polygon[0],line[0],hit)!=0)^1)==0) {
                                u32 scene=*(u16 *)(wall+0x22);
                                if(scene==0xffff) return *(u16 *)(wall+0x24);
                                if(((u8 *)GameSt)[9]!=scene) {
                                    indices=(u32 *)((u8 *)MdlMng+0x11800);
                                    if(CheckNowFade(8)!=0) SetSceneLoad(*(u16 *)(wall+0x22),*(u16 *)(wall+0x24));
                                    else if(CheckNowFade(6)==0 && *(s32 *)((u8 *)indices+0x120)>0) {
                                        s32 color[4] __attribute__((aligned(16)))={0};
                                        SetFadeMng(6,color,30,0,0,0,0);
                                        SetFadeSceneLoad(*(u16 *)(wall+0x22),*(u16 *)(wall+0x24));
                                    }
                                }
                                return -1;
                            }
                            triangle++;
                            indices++;
                        } while(triangle<vertices);
                    }
                    group++;
                    face+=vertices+1;
                } while(group<*(u16 *)(wall+0x26));
            }
            section++;
            wall+=0x40;
        } while((s32)section<*(u16 *)(selected+0x1a));
    }
    return -1;
}
void UpdateCamAnim(void *lpCamInfo_, void *lpTarget_) {
    struct dw_40166 *lpCamInfo = (struct dw_40166 *)lpCamInfo_;
    u8 *lpTarget = (u8 *)lpTarget_;
    u8 *cam;
    struct CamKey *key;
    struct CamKey *key1;
    struct CamKey2 *ang0;
    struct CamKey2 *ang1;
    struct CamFovKey *fk;
    float frame;
    float f0, f1, f2, f12;
    float fov;
    float *pD;
    float *pA;
    u32 kf;
    u32 kl;
    u32 kf2;
    u32 kl2;
    u32 kf3;
    u32 kl3;

    cam = (u8 *)GetCamPathData__ic(lpCamInfo, lpCamInfo->nowIndex);
    if (*(u16 *)(cam + 0x14) != 0) {
        key = *(struct CamKey **)(cam + 0x40);
        frame = lpCamInfo->frame;
        kl = key->len;
        kf = key->frame;
        while ((float)(s32)(kf + kl) < frame) {
            key++;
            kl = key->len;
            kf = key->frame;
        }
        key1 = key + 1;
        f12 = (frame - (float)kf) / (float)kl;
        AnimCurve((float *)(lpDrawMng + 0x230), key->p, key1->p, key->c, key1->b, f12);
    } else {
        sceVu0CopyVector(lpDrawMng + 0x230, cam + 0x20);
    }
    if (*(u16 *)(cam + 0x12) == 0) {
        if (*(u16 *)(cam + 0x16) != 0) {
            ang0 = *(struct CamKey2 **)(cam + 0x44);
            frame = lpCamInfo->frame;
            kl2 = ang0->len;
            kf2 = ang0->frame;
            while ((float)(s32)(kf2 + kl2) < frame) {
                ang0++;
                kl2 = ang0->len;
                kf2 = ang0->frame;
            }
            ang1 = ang0 + 1;
            f12 = (frame - (float)kf2) / (float)kl2;
            AnimCurve((float *)(lpDrawMng + 0x240), ang0->p, ang1->p, ang0->c, ang1->b, f12);
        } else {
            sceVu0CopyVector(lpDrawMng + 0x240, cam + 0x30);
        }
    } else {
        UpdateTargetCam(lpCamInfo, lpCamInfo->nowIndex, lpTarget);
    }
    if (*(u16 *)(cam + 0x18) != 0) {
        fk = *(struct CamFovKey **)(cam + 0x48);
        frame = lpCamInfo->frame;
        kl3 = fk->len;
        kf3 = fk->frame;
        while ((float)(s32)(kf3 + kl3) < frame) {
            fk++;
            kl3 = fk->len;
            kf3 = fk->frame;
        }
        f2 = fk->v;
        f0 = tanf((f2 + ((frame - (float)kf3) / (float)kl3) * (fk[1].v - f2)) / 2.0f);
        f0 = atanf(f0 / 0.75f);
        f1 = 2.0f * f0;
        if (!(*(float *)(lpDrawMng + 0x41c) == f1)) {
            *(float *)(lpDrawMng + 0x41c) = f1;
            DrawSetViewRange();
        }
    } else {
        f0 = tanf(*(float *)(cam + 0x1c) / 2.0f);
        f0 = atanf(f0 / 0.75f);
        f1 = 2.0f * f0;
        if (!(*(float *)(lpDrawMng + 0x41c) == f1)) {
            *(float *)(lpDrawMng + 0x41c) = f1;
            DrawSetViewRange();
        }
    }
    pD = (float *)lpDrawMng;
    pA = pD + 0x90;
    f2 = pD[0x90];
    *pA = WRAPF(f2);
    pD = (float *)lpDrawMng;
    pA = pD + 0x91;
    f2 = pD[0x91];
    *pA = WRAPF(f2);
    pD = (float *)lpDrawMng;
    pA = pD + 0x92;
    f2 = pD[0x92];
    *pA = WRAPF(f2);
}

static void UpdateTargetCam(void *lpCamInfo, signed int index, void *lpTarget) {
    float xx, yy, zz;
    float TargetPos[4];
    float dd;
    float LimitRadX, angXLimitMin, angXLimitMax;
    float LimitRadY, angYLimitMin, angYLimitMax;
    u8 *cam;

    cam = (u8 *)GetCamPathData__ic(lpCamInfo, index);
    sceVu0CopyVector(TargetPos, (u8 *)lpTarget + 0x20);
    TargetPos[1] = TargetPos[1] - 1.3f;
    xx = TargetPos[0] - DM->camPos[0];
    yy = *(volatile float *)&TargetPos[1] - DM->camPos[1];
    zz = TargetPos[2] - DM->camPos[2];
    DM->camAng[0] = Math_VectorToAngle(-yy, sqrtf(xx * xx + zz * zz));
    DM->camAng[1] = Math_VectorToAngle(xx, zz);
    DM->camAng[0] = WRAPF(DM->camAng[0]);
    DM->camAng[1] = WRAPF(DM->camAng[1]);
    if (cam[0x58] != 0) {
        LimitRadX = 0.01745f * (float)cam[0x58] / 2.0f;
        if (!(ABSF(Math_GetAngleDist(*(float *)(cam + 0x30), DM->camAng[0])) <= LimitRadX)) {
            angXLimitMin = *(float *)(cam + 0x30) - LimitRadX;
            angXLimitMax = *(float *)(cam + 0x30) + LimitRadX;
            dd = ABSF(Math_GetAngleDist(DM->camAng[0], angXLimitMin));
            if (dd < ABSF(Math_GetAngleDist(DM->camAng[0], angXLimitMax))) {
                DM->camAng[0] = angXLimitMin;
            } else {
                DM->camAng[0] = angXLimitMax;
            }
        }
    }
    if (cam[0x59] != 0) {
        LimitRadY = 0.01745f * (float)cam[0x59] / 2.0f;
        if (!(ABSF(Math_GetAngleDist(*(float *)(cam + 0x34), DM->camAng[1])) <= LimitRadY)) {
            angYLimitMin = *(float *)(cam + 0x34) - LimitRadY;
            angYLimitMax = *(float *)(cam + 0x34) + LimitRadY;
            dd = ABSF(Math_GetAngleDist(DM->camAng[1], angYLimitMin));
            if (dd < ABSF(Math_GetAngleDist(DM->camAng[1], angYLimitMax))) {
                DM->camAng[1] = angYLimitMin;
            } else {
                DM->camAng[1] = angYLimitMax;
            }
        }
    }
}


static float GetCamFrame(void *scene, void *camera, int id) {
    u8 *savedCamera = camera;
    float t;
    u32 high;
    u8 *track;
    u8 *current;
    u8 *next;
    float *third, *last, *second, *first;
    float direction[4] __attribute__((aligned(16)));
    float delta[4] __attribute__((aligned(16)));
    u32 root = *(u32 *)scene;
    s32 count = *(u16 *)(root+0xe);
    u8 *cursor = *(u8 **)(root+0x1c);
    scene = 0;
    if (0 < count) {
        do {
            if (*(u16 *)(cursor+0x10) == (u32)id) {
                track = cursor;
                goto found;
            }
            scene = (u8 *)scene + 1;
            cursor += 0x30;
        } while ((s32)scene < count);
    }
    track = 0;
found:
    current = *(u8 **)(track+0x14);
    second = &direction[1];
    first = &direction[2];
    third = &delta[1];
    last = &delta[2];
    next = current+0x40;
    while (1) {
        float length;
        sceVu0SubVector(direction,next+0x10,current+0x10);
        length = direction[0]*direction[0] + *second * *second + *first * *first;
        sceVu0SubVector(delta,current+0x10,savedCamera+0x20);
        t = (direction[0]*delta[0] + *second * *third + *first * *last) / length;
        t = -t;
        if ((0.0f <= t) & (t <= 1.0f)) break;
        if (*(u16 *)(current+4) != 0) goto checkEnd;
        if (!(t <= 0.0f)) goto checkEnd;
        t = 0.0f;
        break;
checkEnd:
        if (*(u16 *)(next+4) != *(u16 *)(track+0x12)-1) goto advance;
        if (t < 1.0f) goto advance;
        t = 1.0f;
        break;
advance:
        current += 0x40;
        next += 0x40;
    }
    return (float)(u32)*(u16 *)current + (float)(u32)*(u16 *)(current+2)*(float)t;
}


/* SetCamDirLockFlag @ 0x132980 .. 0x1329B0 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */





void SetCamDirLockFlag(char a0 /* r4 */, char a1 /* r5 */) {
    u32 a2;
    s32 v1;
    u8 *a3;

    a2 = *(u8 *)((u8 *)&GameCamInfo + 0xc);
    v1 = 1;
    a3 = (u8 *)GameCamInfo;
    if (a2 == (u32)v1) {
        *(u8 *)(((u8 *)a3 + 0xd)) = (u8)a0;
        v1 = 2;
        *(u8 *)(((u8 *)a3 + 0xe)) = (u8)a1;
        *(u8 *)(((u8 *)a3 + 0xc)) = v1;
    }
    return;
}



unsigned int CheckCamDirLock(char x, char y) {
    u8 *info;
    u32 state, result;
    info = (u8 *)GameCamInfo;
    if (*(u8 *)(GameCamInfo + 3) <= 1) {
        result = 0;
    } else {
        state = info[12];
        if (state == 2) {
            if (*(s8 *)(info + 13) - 20 > x) goto increment;
            if (*(s8 *)(info + 13) + 20 < x) goto increment;
            if (*(s8 *)(info + 14) - 20 > y) goto increment;
            if (*(s8 *)(info + 14) + 20 < y) goto increment;
            goto locked;
        increment:
            info[12]++;
            goto locked;
        } else {
            info[12] = state + 1;
            if (state == 5) {
                info[12] = 0;
                result = 0;
                info[13] = 0;
                info[14] = 0;
            } else {
            locked:
                result = 1;
            }
        }
    }
    return result;
}


/* FreeGameCamData @ 0x132870 .. 0x1328B0 (0x40 bytes, frame 0x20) */



void FreeGameCamData(signed int a0 /* r4 */) {
    u32 *s0;

    s0 = GameCamInfo;
    if ((u32)(s32)a0 != 0) {
        a0 = *(s32 *)s0;
        MemFree((void *)a0);
    }
    a0 = (signed int)s0;
    memset(a0, 0, (s32)0x3010);
    return;
}


/* FreeDramaCamData @ 0x132850 .. 0x132868 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j memset at 0x132860 leaves the function
 *   return value dropped, call kept: the function is void
 */


void FreeDramaCamData(void) {
    memset((u8 *)DramaCamInfo, 0, (u64)(0xc0000 | 0x400));
    return;
}











/* GetCurCamID @ 0x1327D0 .. 0x132848 (0x78 bytes) */



signed int GetCurCamID(void) {
    u32 a0;
    u32 v1;
    u32 v0;

    v0 = 1;
    v1 = ((u8 *)GameSt)[5];
    switch (v1) {
    case 1:
        v1 = lpDramaMng;
        v0 = (u32)DramaCamInfo;
        a0 = *(u16 *)((v1 + 0xc));
        v1 = a0 * (u32)(0x3010);
        v0 = (s32)((u8 *)DramaCamInfo + v1);
        break;
    default:
        v0 = (u32)GameCamInfo;
    }
    if (v0 != 0) {
        return *(s32 *)((v0 + 4));
    } else {
        return -1;
    }
}


/* GetCamInfo @ 0x132770 .. 0x1327D0 (0x60 bytes) */


u8 * GetCamInfo(void) {
    u32 v0;
    u32 v1;
    u16 a0;

    v0 = 1;
    v1 = ((u8 *)GameSt)[5];
    switch (v1) {
    case 1:
        v1 = lpDramaMng;
        v0 = (u32)DramaCamInfo;
        a0 = *(u16 *)((v1 + 0xc));
        v1 = (u32)((u32)a0) * (u32)(0x3010);
        v0 = (s32)((u8 *)DramaCamInfo + v1);
        break;
    default:
        v0 = (u32)GameCamInfo;
    }
    return (u8 *)v0;
}


/* GetDramaCamInfo @ 0x132740 .. 0x132764 (0x24 bytes) */
/*
 * dcomp notes:
 *   return: addu at 0x132760 computes the return value
 */


u32 GetDramaCamInfo(s32 a0 /* r4 */) {
    u32 v0;
    u32 v1;

    v0 = (u32)a0 << 1;
    v1 = v0 + a0;
    v1 = (u32)v1 << 8;
    v1 = v1 + a0;
    v0 = (u32)DramaCamInfo;
    v1 = (u32)v1 << 4;
    return v0 + v1;
}






/* GetGameCamInfo @ 0x132730 .. 0x13273C (0xc bytes) */


u8 * GetGameCamInfo(void) {
    return (u8 *)GameCamInfo;
}








/* SetCamAmbient @ 0x1326B0 .. 0x132728 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x1326b8
 *   cfg: kept branch: 0x1326d4 if (..) goto .L00132710
 *   cfg: kept branch: 0x1326e4 if (..) goto .L00132710
 */


void SetCamAmbient(void *a0 /* r4 */) {
    float f1;
    float *s0;
    float f0;
    s32 fpcc;

    f1 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x5c));
    f0 = *(float *)s0;
    fpcc = f1 == f0;
    if (fpcc) {
        f0 = *(float *)(((u8 *)s0 + 4));
        fpcc = f1 == f0;
        if (!fpcc) {
            goto _L00132710;
        }
        f0 = *(float *)(((u8 *)s0 + 8));
        fpcc = f1 == f0;
        a0 = (void *)(s32)s0;
        if (!fpcc) {
            goto _L00132710;
        }
        GetMapAmbient(a0);
        a0 = (void *)(s32)s0;
        SetAmbientColor((float *)a0);
    } else {
        _L00132710:;
        a0 = (void *)(s32)s0;
        SetAmbientColor((float *)a0);
    }
    return;
}


/* SetCamReverb @ 0x132610 .. 0x1326AC (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1731 -> 0x252f90
 *   indirect: jr v0 at 0x13264c -> <v0>
 *   declaration vs inferred signature: return void vs inferred u32
 */


void SetCamReverb(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    u32 s1;

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x60));
    if ((u32)(s32)s0 != 0) {
        v0 = *(s16 *)s0;
        switch (v0) {
        case 4:
            SND_SetReverbStudioC(*(s16 *)(s0 + 2));
            break;
        case 0:
        default:
            SND_SetReverbOff();
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        }
        s1 = 0;
        do {
            SND_SqVolSetValue((u8)s1, *(s8 *)(((u32)(s32)(s0 + s1) + 0xa)));
            s1 = s1 + 1;
        } while ((s32)s1 < (s32)4);
    }
    return;
}


/* SetCamCtrlMode @ 0x132600 .. 0x132608 (0x8 bytes) */


void SetCamCtrlMode(u_int mode) {
    CamCtrlMode = mode;
    return;
}















/* GetCamCtrlMode @ 0x1325F0 .. 0x1325F8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1325f4 computes the return value
 */


u32 GetCamCtrlMode(void) {
    return CamCtrlMode;
}








void SetTargetFreeCamera(signed int id) {
    u8 *cursor;
    s32 i;
    s32 count;
    u8 *selected;
    u32 info = GameCamInfo[0];
    count = *(u16 *)(info + 0xe);
    cursor = *(u8 **)(info + 0x18);
    i = 0;
    if (0 < count) {
        do {
            if (*(u16 *)(cursor + 0x10) == id) {
                selected = cursor;
                goto found;
            }
            i++;
            cursor += 0x70;
        } while (i < count);
    }
    selected = 0;
found:
    if (selected) {
        CamCtrlMode = 3;
        CamId4FreeTarget = id;
        *(float *)(lpDrawMng + 0x230) = *(float *)(selected + 0x20);
        *(float *)(lpDrawMng + 0x234) = *(float *)(selected + 0x24);
        *(float *)(lpDrawMng + 0x238) = *(float *)(selected + 0x28);
        *(float *)(lpDrawMng + 0x23c) = 1.0f;
        *(float *)(lpDrawMng + 0x240) = *(float *)(selected + 0x30);
        *(float *)(lpDrawMng + 0x244) = *(float *)(selected + 0x34);
        *(float *)(lpDrawMng + 0x248) = *(float *)(selected + 0x38);
        *(float *)(lpDrawMng + 0x24c) = 1.0f;
        *(float *)(lpDrawMng + 0x41c) = 2.0f * atanf(tanf(*(float *)(selected + 0x1c) / 2.0f) / 0.75f);
        DrawSetViewRange();
    }
}

void SetCamEnv(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s0;

    s0 = (u8 *)GetCamPathData__inl(a0, a1);
    SetCamAmbient__inl((void *)s0);
    SetCamReverb((void *)s0);
    SetMirror(*(u8 *)((u8 *)&GameSt + 9), (signed int)(u8)(s32)a1);
    return;
}


void SetCamPathDirect(signed int id) {
    float *ambient;
    u32 selected;
    u8 *camera;
    s32 i, count, temp;
    GameCamInfo[1] = id;
    selected = GameCamInfo[1];
    count = *(u16 *)(GameCamInfo[0] + 0xe);
    camera = (u8 *)*(s32 *)(GameCamInfo[0] + 0x18);
    __asm__ volatile(
        ".set noreorder\n"
        "slt $1,$zero,%3\n"
        "beqz $1,2f\n"
        "daddu %2,$zero,$zero\n"
        "1:\n"
        "lhu %0,0x10(%1)\n"
        "bne %0,%4,3f\n"
        "nop\n"
        "b 4f\n"
        "nop\n"
        "nop\n"
        "3:\n"
        "addiu %2,%2,1\n"
        "slt %0,%2,%3\n"
        "bnez %0,1b\n"
        "addiu %1,%1,0x70\n"
        "2:\n"
        "daddu %1,$zero,$zero\n"
        "nop\n"
        "4:\n"
        ".set reorder\n"
        : "=&r"(temp), "+r"(camera), "=&r"(i)
        : "r"(count), "r"(selected)
        : "$1", "memory");
    ambient = (float *)*(s32 *)(camera + 0x5c);
    if (ambient[0] == 0.0f && ambient[1] == 0.0f && ambient[2] == 0.0f) {
        GetMapAmbient(ambient);
        SetAmbientColor(ambient);
    } else {
        SetAmbientColor(ambient);
    }
    SetCamReverb(camera);
    SetMirror(*(u8 *)((u8 *)&GameSt + 9), selected);
}


/* SetCamVibration @ 0x132290 .. 0x1322BC (0x2c bytes) */
/*
 * dcomp notes:
 *   stack: 16-byte aggregate copy in 4-byte chunks at 0x1322b8
 *   declaration vs inferred signature: return void vs inferred float
 */


void SetCamVibration(void *a0 /* r4 */) {
    struct __copy_float_4 { float b[4]; };

    *(struct __copy_float_4 *)s_vibration = *(struct __copy_float_4 *)a0;
    return;
}







/* StartCamVibration @ 0x132270 .. 0x13228C (0x1c bytes) */


void StartCamVibration(s32 a0 /* r4 */, float f12 /* f12 */) {
    *(f32 *)((u8 *)&s_vibration_act + 8) = f12;
    *(u32 *)((u8 *)&s_vibration_act + 0x10) = a0;
    *(u32 *)((u8 *)&s_vibration_act + 0xc) = 0;
    return;
}

void UpdateCamVib(void) {
    float coeff;

    if (0.0f < VAF(2)) {
        if (VAF(3) < VAF(2)) {
            VAF(3) = VAF(3) + 0.0166666f;
            if (VAF(2) < VAF(3)) {
                VAF(3) = VAF(2);
            }
        }
        coeff = 0.0f < VAF(2) ? VAF(3) / VAF(2) : 0.0f;
        switch (s_vibration_act[4]) {
        case 1:
            coeff = 1.0f - coeff;
            break;
        case 2:
            coeff = sinf(3.1415927f * coeff);
        }
        if (0.0f < coeff) {
            VAF(0) = VAF(0) + 0.10471934f * s_vibration[2];
            VAF(1) = VAF(1) + 0.10471934f * s_vibration[3];
            VAF(0) = SfxCalc_IntoAngle_0_2PI(VAF(0));
            VAF(1) = SfxCalc_IntoAngle_0_2PI(VAF(1));
            *(f32 *)((u8 *)lpDrawMng + 0x240) = *(f32 *)((u8 *)lpDrawMng + 0x240) + coeff * (0.5f * s_vibration[1] * sinf(VAF(1)));
            *(f32 *)((u8 *)lpDrawMng + 0x244) = *(f32 *)((u8 *)lpDrawMng + 0x244) + coeff * (0.5f * s_vibration[0] * sinf(VAF(0)));
        }
    }
}
