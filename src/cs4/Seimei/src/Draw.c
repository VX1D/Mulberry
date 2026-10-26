#include "common.h"
typedef struct { unsigned int v[16]; } ShMat;
typedef struct { unsigned int v[4]; } ShVec;




extern signed int GetRiddleFreeState(void);

#ifndef PROTO_DW_49744
#define PROTO_DW_49744
struct dw_49744 { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_52319
#define PROTO_DW_52319
struct dw_52319 { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_50147
#define PROTO_DW_50147
struct dw_50147 { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_53720
#define PROTO_DW_53720
struct dw_53720 { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_53005
#define PROTO_DW_53005
struct dw_53005 { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_40778
#define PROTO_DW_40778
struct dw_40778 { struct dw_49744 pmode; struct dw_52319 smode2; struct dw_50147 dispfb; struct dw_53720 display; struct dw_53005 bgcolor; };
#endif
#ifndef PROTO_DW_47916
#define PROTO_DW_47916
struct dw_47916 { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_51985
#define PROTO_DW_51985
struct dw_51985 { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_57495
#define PROTO_DW_57495
struct dw_57495 { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_56264
#define PROTO_DW_56264
struct dw_56264 { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_50759
#define PROTO_DW_50759
struct dw_50759 { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_45713
#define PROTO_DW_45713
struct dw_45713 { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_56940
#define PROTO_DW_56940
struct dw_56940 { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_49625
#define PROTO_DW_49625
struct dw_49625 { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_53301
#define PROTO_DW_53301
struct dw_53301 { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_47263
#define PROTO_DW_47263
struct dw_47263 { struct dw_51985 frame1; unsigned long frame1addr; struct dw_57495 zbuf1; long zbuf1addr; struct dw_56264 xyoffset1; long xyoffset1addr; struct dw_50759 scissor1; long scissor1addr; struct dw_45713 prmodecont; long prmodecontaddr; struct dw_56940 colclamp; long colclampaddr; struct dw_49625 dthe; long dtheaddr; struct dw_53301 test1; long test1addr; };
#endif
#ifndef PROTO_DW_61416
#define PROTO_DW_61416
struct dw_61416 { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_49403
#define PROTO_DW_49403
struct dw_49403 { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_56788
#define PROTO_DW_56788
struct dw_56788 { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_54224
#define PROTO_DW_54224
struct dw_54224 { struct dw_53301 testa; long testaaddr; struct dw_61416 prim; long primaddr; struct dw_49403 rgbaq; long rgbaqaddr; struct dw_56788 xyz2a; long xyz2aaddr; struct dw_56788 xyz2b; long xyz2baddr; struct dw_53301 testb; long testbaddr; };
#endif
#ifndef PROTO_DW_57096
#define PROTO_DW_57096
struct dw_57096 { struct dw_40778 disp[2]; struct dw_47916 giftag0; struct dw_47263 draw0; struct dw_54224 clear0; struct dw_47916 giftag1; struct dw_47263 draw1; struct dw_54224 clear1; };
#endif
#ifndef PROTO_DW_41105
#define PROTO_DW_41105
struct dw_41105 { struct dw_57096 dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_106614
#define PROTO_DW_106614
struct dw_106614 { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_102500
#define PROTO_DW_102500
struct dw_102500 { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_101152
#define PROTO_DW_101152
struct dw_101152 { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_78578 *lpMdl; };
#endif
#ifndef PROTO_DW_78578
#define PROTO_DW_78578
struct dw_78578 { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_109200 *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_78578 *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_106614 DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_102500 flags; unsigned char _pad1[3]; struct dw_101152 Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_110672
#define PROTO_DW_110672
struct dw_110672 { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_109200
#define PROTO_DW_109200
struct dw_109200 { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_110672 DmyPoly[32]; };
#endif
extern u32 GetDramaFreeFlag();
extern u32 L1650[];
extern void sceVu0CopyVector();
extern u32 sgColorMat[];
extern u8 *lpDrawMng;
extern unsigned int CheckBackOfCamera(float *);
extern unsigned int CheckDrawMapByCamParam(signed int);
extern u8 GameSt[];
extern u8 MdlMng[];
extern u32 L1978[];
extern void DrawHmdModel(void *, unsigned int);
static void DrawVmdModel(void *a0 );
static void DrawVmdModel(void *);
extern void sceVu0MulMatrix(void *, void *, void *);
extern int sceGsSyncV(int);
extern void FlushCache(int);
extern int sceGsSwapDBuff();
extern void * MemAllocReal(unsigned int, char *, char *);
extern int sceGsSetDefLoadImage(void *, short, short, short, short, short, short, short);
extern int sceGsExecLoadImage(void *, void *);
extern void MemFree(void *);
extern void sceVu0UnitMatrix(void *);
extern void sceVu0RotMatrixY(void *, void *, float);
extern void sceVu0RotMatrixZ(void *, void *, float);
extern void sceVu0RotMatrixX(void *, void *, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void sceVu0TransMatrix(void *, void *, void *);
extern u32 sgLightMat[];
void DrawSetViewScreenClipMatrix(void *a0 , void *a1 , void *a2 , float f12 , float f13 , float f14 , float f15 , float f16 , float f17 , float f18 , float f19 , float arg11, float arg12, float arg13);
extern void DrawSetViewScreenClipMatrix(void *, void *, void *, float, float, float, float, float,
    float, float, float, float, float, float);
extern void InitVramMng(signed int, signed int, signed int, signed int);
signed int CheckRiddleDrawModel(void *a0 );
signed int CheckRiddleDrawModel(void *a0 /* r4 */);
signed int CheckDramaDrawModel(void *a0 );
signed int CheckDramaDrawModel(void *a0 /* r4 */);
void GetAmbientColor(u8 *a0 );
void GetAmbientColor(u8 *a0 /* r4 */);
void SetAmbientColor(u8 *a0 );
void SetAmbientColor(u8 *a0 /* r4 */);
unsigned int CheckDrawModel(void *a0 );
unsigned int CheckDrawModel(void *a0 /* r4 */);
void DrawModel(struct dw_78578 *a0 );
void DrawModel(struct dw_78578 *a0 /* r4 */);
void UpdateWorldMatrixWithAnim(void *a0 , void *a1 , void *a2 );
void UpdateWorldMatrixWithAnim(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */);
void UpdateWorldMatrixNoAnim(void *a0 , void *a1 );
void UpdateWorldMatrixNoAnim(void *a0 /* r4 */, void *a1 /* r5 */);
void DrawSetClearColor(signed int *a0 );
void DrawSetClearColor(signed int *a0 /* r4 */);
void DrawSynch(void);
void DrawSynch(void);
void DrawClearImage(void);
void DrawClearImage(void);
void DrawCalcView(void);
void DrawCalcView(void);
void SetFog(float f12 , float f13 , signed int *a0 );
void SetFog(float f12 /* f12 */, float f13 /* f13 */, signed int *a0 /* r4 */);
void InitLightMat(void);
void InitLightMat(void);
void DrawSetViewRange16(void);
void DrawSetViewRange16(void);
void DrawSetViewRange(void);
void DrawSetViewRange(void);
void ResetDraw(void);
void ResetDraw(void);

extern void * memset(void *, int, unsigned int);
extern void sceGsResetPath();
extern void sceGsResetGraph(short, short, short, short);
extern void SyncDCache();
extern void InitShadowMatrix();
u32 DrawMngSt[0x11c];
u32 sgLightMat[0x10];
u32 sgColorMat[0x10];

static u32 SinTable[64];
void DrawInit(void);
void DrawInit(void);
void ResetDraw(void);
void DrawSetViewRange(void);
void DrawSetViewRange16(void);
void InitLightMat(void);
void SetFog(float f12 /* f12 */, float f13 /* f13 */, signed int *a0 /* r4 */);
void DrawCalcView(void);
void DrawClearImage(void);
void DrawSynch(void);
void DrawSetClearColor(signed int *a0 /* r4 */);
void UpdateWorldMatrixNoAnim(void *a0 /* r4 */, void *a1 /* r5 */);
void UpdateWorldMatrixWithAnim(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */);
void DrawModel(struct dw_78578 *a0 /* r4 */);
unsigned int CheckDrawModel(void *a0 /* r4 */);
void SetAmbientColor(u8 *a0 /* r4 */);
void GetAmbientColor(u8 *a0 /* r4 */);
signed int CheckPointInBoundBox(float *a0, void *a1);
signed int CheckPointInBoundBox(float *a0, void *a1);
signed int CheckDramaDrawModel(void *a0 /* r4 */);
signed int CheckRiddleDrawModel(void *a0 /* r4 */);




/* DrawVmdModel @ 0x136F00 .. 0x137538 (0x638 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f000000 at 0x137280
 *   fpu: float literal 0x3f800000 at 0x137290
 *   fpu: mov.s at 0x1372f8 is a float copy
 *   fpu: mov.s at 0x137324 is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x137398
 *   stack: address of the slot at 0x60 escapes at 0x1373f8
 *   delay: lui at 0x1374c0 writes a register its branch at 0x1374bc reads
 *   cfg: loop body is not one contiguous region: .L00137410
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void sceVu0CopyMatrix(void *, void *);
extern signed int CheckCrackWall(void *);
extern unsigned int * MakeCrackWall(unsigned int *);
unsigned int * SetMatrixPacket(unsigned int *lpCurDMA, void *lpVmdHeadSt, void *lpMdlMngSt);
extern unsigned int * SetMatrixPacket(unsigned int *, void *, void *);
extern unsigned int CheckPointLightValid(void *, void *, signed int);
extern u32 GetPointLightMng();
unsigned int * SetDirLightPacket(unsigned int *lpCurDMA, float ModelScale, float ModelAlpha, void *lpParam);
extern unsigned int * SetDirLightPacket(unsigned int *, float, float, void *);
unsigned int * SetAmbientLightPacket(unsigned int *lpCurDMA, float ModelAlpha, void *lpParam);
extern unsigned int * SetAmbientLightPacket(unsigned int *, float, void *);
extern signed int CheckDrawMyWrist(void *, signed int);
static u32 *DrawVmdMorphObject(u32 *packet,void *object,void *model,void *matrices);
static u32 *DrawVmdMorphObject(u32 *packet,void *object,void *model,void *matrices);
static unsigned int * DrawVmdObject(unsigned int *s5, void *a1 , void *a2 , void *a3 );
static unsigned int * DrawVmdObject(unsigned int *, void *, void *, void *);
extern u32 lpMdlPacketMem;

struct dw_109200_fields;
struct dw_78578_fields;
#ifndef PROTO_DW_106614_FIELDS
#define PROTO_DW_106614_FIELDS
struct dw_106614_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_102500_FIELDS
#define PROTO_DW_102500_FIELDS
struct dw_102500_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_101152_FIELDS
#define PROTO_DW_101152_FIELDS
struct dw_101152_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_78578_fields *lpMdl; };
#endif
#ifndef PROTO_DW_78578_FIELDS
#define PROTO_DW_78578_FIELDS
struct dw_78578_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_109200_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_78578_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_106614_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_102500_fields flags; unsigned char _pad1[3]; struct dw_101152_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_93044_FIELDS
#define PROTO_DW_93044_FIELDS
struct dw_93044_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_100920_FIELDS
#define PROTO_DW_100920_FIELDS
struct dw_100920_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_93729_FIELDS
#define PROTO_DW_93729_FIELDS
struct dw_93729_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_103692_FIELDS
#define PROTO_DW_103692_FIELDS
struct dw_103692_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_102667_FIELDS
#define PROTO_DW_102667_FIELDS
struct dw_102667_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_84335_FIELDS
#define PROTO_DW_84335_FIELDS
struct dw_84335_fields { struct dw_93044_fields pmode; struct dw_100920_fields smode2; struct dw_93729_fields dispfb; struct dw_103692_fields display; struct dw_102667_fields bgcolor; };
#endif
#ifndef PROTO_DW_88508_FIELDS
#define PROTO_DW_88508_FIELDS
struct dw_88508_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_100514_FIELDS
#define PROTO_DW_100514_FIELDS
struct dw_100514_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_108629_FIELDS
#define PROTO_DW_108629_FIELDS
struct dw_108629_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_106410_FIELDS
#define PROTO_DW_106410_FIELDS
struct dw_106410_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_96106_FIELDS
#define PROTO_DW_96106_FIELDS
struct dw_96106_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_87267_FIELDS
#define PROTO_DW_87267_FIELDS
struct dw_87267_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_107974_FIELDS
#define PROTO_DW_107974_FIELDS
struct dw_107974_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_92638_FIELDS
#define PROTO_DW_92638_FIELDS
struct dw_92638_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_103273_FIELDS
#define PROTO_DW_103273_FIELDS
struct dw_103273_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_87854_FIELDS
#define PROTO_DW_87854_FIELDS
struct dw_87854_fields { struct dw_100514_fields frame1; unsigned long frame1addr; struct dw_108629_fields zbuf1; long zbuf1addr; struct dw_106410_fields xyoffset1; long xyoffset1addr; struct dw_96106_fields scissor1; long scissor1addr; struct dw_87267_fields prmodecont; long prmodecontaddr; struct dw_107974_fields colclamp; long colclampaddr; struct dw_92638_fields dthe; long dtheaddr; struct dw_103273_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_110982_FIELDS
#define PROTO_DW_110982_FIELDS
struct dw_110982_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_90986_FIELDS
#define PROTO_DW_90986_FIELDS
struct dw_90986_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_107055_FIELDS
#define PROTO_DW_107055_FIELDS
struct dw_107055_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_104298_FIELDS
#define PROTO_DW_104298_FIELDS
struct dw_104298_fields { struct dw_103273_fields testa; long testaaddr; struct dw_110982_fields prim; long primaddr; struct dw_90986_fields rgbaq; long rgbaqaddr; struct dw_107055_fields xyz2a; long xyz2aaddr; struct dw_107055_fields xyz2b; long xyz2baddr; struct dw_103273_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_108194_FIELDS
#define PROTO_DW_108194_FIELDS
struct dw_108194_fields { struct dw_84335_fields disp[2]; struct dw_88508_fields giftag0; struct dw_87854_fields draw0; struct dw_104298_fields clear0; struct dw_88508_fields giftag1; struct dw_87854_fields draw1; struct dw_104298_fields clear1; };
#endif
#ifndef PROTO_DW_89591_FIELDS
#define PROTO_DW_89591_FIELDS
struct dw_89591_fields { struct dw_108194_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_110672_FIELDS
#define PROTO_DW_110672_FIELDS
struct dw_110672_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_109200_FIELDS
#define PROTO_DW_109200_FIELDS
struct dw_109200_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_110672_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0 = (int)&(((struct dw_109200_fields *)0)->MdlType) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_TEXINVMD_D18A31BF_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_TEXINVMD_D18A31BF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_TEXINVMD_D18A31BF = (int)&(((struct dw_109200_fields *)0)->TexInVmd) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPPACKET_D228A198_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPPACKET_D228A198_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPPACKET_D228A198 = (int)&(((struct dw_109200_fields *)0)->lpPacket) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPTEXPACKET_87DF94ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPTEXPACKET_87DF94ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPTEXPACKET_87DF94ED = (int)&(((struct dw_109200_fields *)0)->lpTexPacket) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD = (int)&(((struct dw_109200_fields *)0)->lpVmdHead) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_ALPHA_40ED5DAB_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_ALPHA_40ED5DAB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_ALPHA_40ED5DAB = (int)&(((struct dw_78578_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_HITHIGH_30015B9A_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_HITHIGH_30015B9A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_HITHIGH_30015B9A = (int)&(((struct dw_78578_fields *)0)->HitHigh) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44 = (int)&(((struct dw_78578_fields *)0)->Pos[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713 = (int)&(((struct dw_78578_fields *)0)->Pos[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D = (int)&(((struct dw_78578_fields *)0)->Pos[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0 = (int)&(((struct dw_78578_fields *)0)->Scl[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSE_5A9BB2D0_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSE_5A9BB2D0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSE_5A9BB2D0 = (int)&(((struct dw_78578_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLAMBIENT_39D34B9F_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLAMBIENT_39D34B9F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLAMBIENT_39D34B9F = (int)&(((struct dw_78578_fields *)0)->bUseMdlAmbient) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLLIGHT_7344CC2A_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLLIGHT_7344CC2A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLLIGHT_7344CC2A = (int)&(((struct dw_78578_fields *)0)->bUseMdlLight) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5 = (int)&(((struct dw_78578_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPSHIFTTEXPACKET_63ADB478_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPSHIFTTEXPACKET_63ADB478_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPSHIFTTEXPACKET_63ADB478 = (int)&(((struct dw_78578_fields *)0)->lpShiftTexPacket) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E_DEFINED
#define DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E = (int)&(((struct dw_89591_fields *)0)->DrawFlag) - 0 };
#endif




/* DrawVmdObject @ 0x136850 .. 0x136F00 (0x6b0 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   delay: lui at 0x136988 writes a register its branch at 0x136984 reads
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern void sceVu0CopyMatrix(void *, void *);
extern unsigned int CheckPointLightValid(void *, void *, signed int);
static unsigned int * SetPointLightPacket();
static unsigned int * SetPointLightPacket(u32 *, u8 *, u32);
extern u16 GetMicroCodeMPG(u32 *);
unsigned int *SetTexScrollPacket(unsigned int *packet,unsigned char index,float scale);
unsigned int *SetTexScrollPacket(unsigned int *packet,unsigned char index,float scale);
static unsigned int *SetTexScrollSfxPacket(unsigned int *packet, void *model);
static unsigned int *SetTexScrollSfxPacket(unsigned int *packet, void *model);
extern u32 Vu1ProgMCScissor[];
extern u32 Vu1ProgMCScissorTriangle[];
extern u32 Vu1ProgMCClipJointAmbiPLight[];
extern u32 Vu1ProgMCClipAmbi[];
extern u32 Vu1ProgMCEnvClipAmbiPLight[];
extern u32 Vu1ProgMCScrollClipAmbiPLight[];
extern u32 Vu1ProgMCEnvClipAmbi[];
extern u32 Vu1ProgMCScrollClipAmbi[];
extern u32 Vu1ProgMCJointLight[];
extern u32 Vu1ProgMCScrollJointLight[];
extern u32 Vu1ProgMCClipJointLight[];
extern u32 Vu1ProgMCScrollClipJointLight[];
extern u32 Vu1ProgMCClipAmbiPLight[];
extern u32 Vu1ProgMCBase[];
extern u32 Vu1ProgMCMulti[];
extern u32 Vu1ProgMCShadowMake[];
extern u32 Vu1ProgMCShadowDraw[];

struct dw_109200_fields;
struct dw_78578_fields;
struct dw_85832_fields;
struct dw_86468_fields;
struct dw_91208_fields;
struct dw_92381_fields;
struct dw_92793_fields;
#ifndef PROTO_DW_106614_FIELDS
#define PROTO_DW_106614_FIELDS
struct dw_106614_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_102500_FIELDS
#define PROTO_DW_102500_FIELDS
struct dw_102500_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_101152_FIELDS
#define PROTO_DW_101152_FIELDS
struct dw_101152_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_78578_fields *lpMdl; };
#endif
#ifndef PROTO_DW_78578_FIELDS
#define PROTO_DW_78578_FIELDS
struct dw_78578_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_109200_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_78578_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_106614_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_102500_fields flags; unsigned char _pad1[3]; struct dw_101152_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_82520_FIELDS
#define PROTO_DW_82520_FIELDS
struct dw_82520_fields { float Position[4]; float Angle[4]; float Scale[4]; short ObjectId; short GeomObjectId; short ParentObjectId; short ChildObjectId; short SiblingObjectId; short MatrixNum; unsigned short *lpMatrixId; int PrimListNum; struct dw_86468_fields *lpPrimHead; unsigned short PolyNum; unsigned short TreeNum; struct dw_85832_fields *lpBoundBox; char *lpObjectName; struct dw_91208_fields *lpObjParam; struct dw_92381_fields *lpTree; struct dw_92793_fields *lpObjReserve; };
#endif
#ifndef PROTO_DW_93044_FIELDS
#define PROTO_DW_93044_FIELDS
struct dw_93044_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_100920_FIELDS
#define PROTO_DW_100920_FIELDS
struct dw_100920_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_93729_FIELDS
#define PROTO_DW_93729_FIELDS
struct dw_93729_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_103692_FIELDS
#define PROTO_DW_103692_FIELDS
struct dw_103692_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_102667_FIELDS
#define PROTO_DW_102667_FIELDS
struct dw_102667_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_84335_FIELDS
#define PROTO_DW_84335_FIELDS
struct dw_84335_fields { struct dw_93044_fields pmode; struct dw_100920_fields smode2; struct dw_93729_fields dispfb; struct dw_103692_fields display; struct dw_102667_fields bgcolor; };
#endif
#ifndef PROTO_DW_88508_FIELDS
#define PROTO_DW_88508_FIELDS
struct dw_88508_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_100514_FIELDS
#define PROTO_DW_100514_FIELDS
struct dw_100514_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_108629_FIELDS
#define PROTO_DW_108629_FIELDS
struct dw_108629_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_106410_FIELDS
#define PROTO_DW_106410_FIELDS
struct dw_106410_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_96106_FIELDS
#define PROTO_DW_96106_FIELDS
struct dw_96106_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_87267_FIELDS
#define PROTO_DW_87267_FIELDS
struct dw_87267_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_107974_FIELDS
#define PROTO_DW_107974_FIELDS
struct dw_107974_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_92638_FIELDS
#define PROTO_DW_92638_FIELDS
struct dw_92638_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_103273_FIELDS
#define PROTO_DW_103273_FIELDS
struct dw_103273_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_87854_FIELDS
#define PROTO_DW_87854_FIELDS
struct dw_87854_fields { struct dw_100514_fields frame1; unsigned long frame1addr; struct dw_108629_fields zbuf1; long zbuf1addr; struct dw_106410_fields xyoffset1; long xyoffset1addr; struct dw_96106_fields scissor1; long scissor1addr; struct dw_87267_fields prmodecont; long prmodecontaddr; struct dw_107974_fields colclamp; long colclampaddr; struct dw_92638_fields dthe; long dtheaddr; struct dw_103273_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_110982_FIELDS
#define PROTO_DW_110982_FIELDS
struct dw_110982_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_90986_FIELDS
#define PROTO_DW_90986_FIELDS
struct dw_90986_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_107055_FIELDS
#define PROTO_DW_107055_FIELDS
struct dw_107055_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_104298_FIELDS
#define PROTO_DW_104298_FIELDS
struct dw_104298_fields { struct dw_103273_fields testa; long testaaddr; struct dw_110982_fields prim; long primaddr; struct dw_90986_fields rgbaq; long rgbaqaddr; struct dw_107055_fields xyz2a; long xyz2aaddr; struct dw_107055_fields xyz2b; long xyz2baddr; struct dw_103273_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_108194_FIELDS
#define PROTO_DW_108194_FIELDS
struct dw_108194_fields { struct dw_84335_fields disp[2]; struct dw_88508_fields giftag0; struct dw_87854_fields draw0; struct dw_104298_fields clear0; struct dw_88508_fields giftag1; struct dw_87854_fields draw1; struct dw_104298_fields clear1; };
#endif
#ifndef PROTO_DW_89591_FIELDS
#define PROTO_DW_89591_FIELDS
struct dw_89591_fields { struct dw_108194_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_91208_FIELDS
#define PROTO_DW_91208_FIELDS
struct dw_91208_fields { unsigned char Specular; unsigned char Scissor; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char Joint; unsigned char TexScroll; unsigned char SortPrio; unsigned char ShadowLevel; unsigned char MorphID; unsigned char Mirror; unsigned char Pad0; };
#endif
#ifndef PROTO_DW_92793_FIELDS
#define PROTO_DW_92793_FIELDS
struct dw_92793_fields { unsigned int MicroCodeAddr; unsigned int *lpModelPacket; unsigned int *lpShadowPacket; unsigned int *lpObjSort; unsigned int *lpMorphPacket; };
#endif
#ifndef PROTO_DW_110672_FIELDS
#define PROTO_DW_110672_FIELDS
struct dw_110672_fields { float Pos[4]; float Nrm[4]; short ObjectId; unsigned char Type; unsigned char Id; unsigned int unused[3]; };
#endif
#ifndef PROTO_DW_109200_FIELDS
#define PROTO_DW_109200_FIELDS
struct dw_109200_fields { int MaxAnimParam; unsigned int TexInVmd; unsigned short MdlNo; unsigned short MdlType; unsigned char bMultiDraw; unsigned char DmyPolyNum; unsigned char DropShadow; char unused0; void *lpVmdHead; void *lpAniHead; void *lpHmdHead; void *lpSmdHead; void *lpMicHead; void *lpMi3Index; void *lpJcnFileHead; void *lpAnimParam; void *lpBndFile; void *lpMdlFile; void *lpAniFile; void *lpHdlFile; void *lpSdlFile; void *lpTexList; void *lpDss; void *lpPrm; unsigned int *lpObjGroupID; unsigned int *lpPacket; unsigned int *lpCurrent; unsigned int *lpTexPacket; unsigned int *lpTexCurrent; unsigned int MdlPacketSize; unsigned int TexPacketSize; float aMorphRate[3]; unsigned int unused[2]; struct dw_110672_fields DmyPoly[32]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD = (int)&(((struct dw_109200_fields *)0)->lpVmdHead) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5 = (int)&(((struct dw_78578_fields *)0)->lpMdlData) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_82520_FIELDS_MATRIXNUM_0655EEDB_DEFINED
#define DCOMP_OFF_STRUCT_DW_82520_FIELDS_MATRIXNUM_0655EEDB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_82520_FIELDS_MATRIXNUM_0655EEDB = (int)&(((struct dw_82520_fields *)0)->MatrixNum) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPMATRIXID_BA7D1AAA_DEFINED
#define DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPMATRIXID_BA7D1AAA_DEFINED
enum { DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPMATRIXID_BA7D1AAA = (int)&(((struct dw_82520_fields *)0)->lpMatrixId) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381_DEFINED
#define DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381_DEFINED
enum { DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381 = (int)&(((struct dw_82520_fields *)0)->lpObjParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A_DEFINED
#define DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A = (int)&(((struct dw_82520_fields *)0)->lpObjReserve) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_89591_FIELDS_PROJECTIONTYPE_95D4B8D1_DEFINED
#define DCOMP_OFF_STRUCT_DW_89591_FIELDS_PROJECTIONTYPE_95D4B8D1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_89591_FIELDS_PROJECTIONTYPE_95D4B8D1 = (int)&(((struct dw_89591_fields *)0)->ProjectionType) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E_DEFINED
#define DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E = (int)&(((struct dw_91208_fields *)0)->Scissor) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF_DEFINED
#define DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF = (int)&(((struct dw_91208_fields *)0)->TexScroll) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344_DEFINED
#define DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344_DEFINED
enum { DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344 = (int)&(((struct dw_92793_fields *)0)->MicroCodeAddr) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_92793_FIELDS_LPMODELPACKET_5E68D23B_DEFINED
#define DCOMP_OFF_STRUCT_DW_92793_FIELDS_LPMODELPACKET_5E68D23B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_92793_FIELDS_LPMODELPACKET_5E68D23B = (int)&(((struct dw_92793_fields *)0)->lpModelPacket) - 0 };
#endif




extern u16 GetMicroCodeMPG(u32 *);
extern u32 Vu1ProgMCMorphClipJointLight[];
extern u32 Vu1ProgMCClipJointLight[];











struct dw_109200;
struct dw_78578;








/* SetDirLightPacket @ 0x1363A0 .. 0x1365C4 (0x224 bytes, frame 0x100) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1234 -> 0x228660
 *   fpu: float literal 0x3f800000 at 0x1363ac
 *   fpu: mov.s at 0x1363f8 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1363f4
 *   stack: address of the slot at 0xd0 escapes at 0x136408
 *   stack: address of the slot at 0xe0 escapes at 0x13641c
 *   stack: address of the slot at 0x60 escapes at 0x136438
 *   stack: address of the slot at 0x60 escapes at 0x13644c
 *   stack: address of the slot at 0x60 escapes at 0x13644c
 *   stack: address of the slot at 0x60 escapes at 0x136460
 *   stack: address of the slot at 0x60 escapes at 0x136460
 *   stack: address of the slot at 0x60 escapes at 0x136474
 *   stack: address of the slot at 0x60 escapes at 0x136474
 *   stack: address of the slot at 0xa0 escapes at 0x136484
 *   stack: address of the slot at 0x60 escapes at 0x136484
 *   stack: address of the slot at 0xa0 escapes at 0x136484
 *   fpu: float literal 0x3f000000 at 0x136494
 *   stack: address of the slot at 0xb0 escapes at 0x13649c
 *   stack: address of the slot at 0xa0 escapes at 0x13649c
 *   stack: address of the slot at 0xc0 escapes at 0x13649c
 *   stack: address of the slot at 0xf0 escapes at 0x1364a8
 *   stack: address of the slot at 0xb0 escapes at 0x1364a8
 *   stack: address of the slot at 0xd0 escapes at 0x1364b0
 *   stack: address of the slot at 0xe0 escapes at 0x1364b0
 *   fpu: mov.s at 0x1364bc is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x1364b8
 *   stack: address of the slot at 0xc0 escapes at 0x1364b8
 *   fpu: mov.s at 0x1364cc is a float copy
 *   stack: address of the slot at 0xd0 escapes at 0x1364c8
 *   fpu: mov.s at 0x1364dc is a float copy
 *   stack: address of the slot at 0xe0 escapes at 0x1364d8
 *   fpu: mov.s at 0x1364e4 is a float copy
 *   stack: address of the slot at 0xf0 escapes at 0x1364e8
 *   stack: address of the slot at 0xf0 escapes at 0x1364e8
 *   stack: address of the slot at 0xc0 escapes at 0x1364f4
 *   stack: address of the slot at 0xc0 escapes at 0x1364f4
 *   stack: address of the slot at 0xc0 escapes at 0x136594
 *   literal: @1234 initializes the 16-byte local at 0xa0
 */

extern void sceVu0Normalize(void *, void *);
extern void sceVu0InterVector(void *, void *, void *, float);
extern void fsvu0_ScaleVector(float *, float *, float);
extern void sceVu0TransposeMatrix(void *, void *);

extern void sceVu0CopyVectorXYZ(u32 *, void *);
extern u32 L1234[];
extern u32 lpDebugParam;

#ifndef PROTO_DW_93044_FIELDS
#define PROTO_DW_93044_FIELDS

#endif
#ifndef PROTO_DW_100920_FIELDS
#define PROTO_DW_100920_FIELDS

#endif
#ifndef PROTO_DW_93729_FIELDS
#define PROTO_DW_93729_FIELDS

#endif
#ifndef PROTO_DW_103692_FIELDS
#define PROTO_DW_103692_FIELDS

#endif
#ifndef PROTO_DW_102667_FIELDS
#define PROTO_DW_102667_FIELDS

#endif
#ifndef PROTO_DW_84335_FIELDS
#define PROTO_DW_84335_FIELDS

#endif
#ifndef PROTO_DW_88508_FIELDS
#define PROTO_DW_88508_FIELDS

#endif
#ifndef PROTO_DW_100514_FIELDS
#define PROTO_DW_100514_FIELDS

#endif
#ifndef PROTO_DW_108629_FIELDS
#define PROTO_DW_108629_FIELDS

#endif
#ifndef PROTO_DW_106410_FIELDS
#define PROTO_DW_106410_FIELDS

#endif
#ifndef PROTO_DW_96106_FIELDS
#define PROTO_DW_96106_FIELDS

#endif
#ifndef PROTO_DW_87267_FIELDS
#define PROTO_DW_87267_FIELDS

#endif
#ifndef PROTO_DW_107974_FIELDS
#define PROTO_DW_107974_FIELDS

#endif
#ifndef PROTO_DW_92638_FIELDS
#define PROTO_DW_92638_FIELDS

#endif
#ifndef PROTO_DW_103273_FIELDS
#define PROTO_DW_103273_FIELDS

#endif
#ifndef PROTO_DW_87854_FIELDS
#define PROTO_DW_87854_FIELDS

#endif
#ifndef PROTO_DW_110982_FIELDS
#define PROTO_DW_110982_FIELDS

#endif
#ifndef PROTO_DW_90986_FIELDS
#define PROTO_DW_90986_FIELDS

#endif
#ifndef PROTO_DW_107055_FIELDS
#define PROTO_DW_107055_FIELDS

#endif
#ifndef PROTO_DW_104298_FIELDS
#define PROTO_DW_104298_FIELDS

#endif
#ifndef PROTO_DW_108194_FIELDS
#define PROTO_DW_108194_FIELDS

#endif
#ifndef PROTO_DW_89591_FIELDS
#define PROTO_DW_89591_FIELDS

#endif









/* SetAmbientLightPacket @ 0x136230 .. 0x13639C (0x16c bytes, frame 0x30) */



#ifndef PROTO_DW_104844_FIELDS
#define PROTO_DW_104844_FIELDS
struct dw_104844_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif
#ifndef PROTO_DW_84552_FIELDS
#define PROTO_DW_84552_FIELDS
struct dw_84552_fields { int ProgramID; unsigned char ParallelDraw; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char AlphaSort; unsigned char Mirror; unsigned char AmbientID; unsigned char Specular; unsigned char ClothDataID; unsigned char DrawRegsID; unsigned char Pad0[2]; };
#endif





/* SetPointLightPacket @ 0x135F90 .. 0x136228 (0x298 bytes, frame 0xf0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xb0 escapes at 0x135fd8
 *   stack: address of the slot at 0x70 escapes at 0x135fec
 *   stack: address of the slot at 0xb0 escapes at 0x135fec
 *   stack: address of the slot at 0x80 escapes at 0x136004
 *   stack: address of the slot at 0xb0 escapes at 0x136004
 *   stack: address of the slot at 0x90 escapes at 0x13601c
 *   stack: address of the slot at 0xb0 escapes at 0x13601c
 *   stack: address of the slot at 0xa0 escapes at 0x136034
 *   stack: address of the slot at 0xb0 escapes at 0x136034
 *   stack: address of the slot at 0x70 escapes at 0x136074
 *   stack: address of the slot at 0x70 escapes at 0x136074
 *   stack: address of the slot at 0x80 escapes at 0x136084
 *   stack: address of the slot at 0x80 escapes at 0x136084
 *   stack: address of the slot at 0x90 escapes at 0x136094
 *   stack: address of the slot at 0x90 escapes at 0x136094
 *   stack: address of the slot at 0xa0 escapes at 0x1360a4
 *   stack: address of the slot at 0xa0 escapes at 0x1360a4
 *   stack: address of the slot at 0x80 escapes at 0x1360b8
 *   stack: address of the slot at 0x90 escapes at 0x1360b8
 *   stack: address of the slot at 0xa0 escapes at 0x1360b8
 *   stack: address of the slot at 0x70 escapes at 0x1360c0
 *   stack: address of the slot at 0x70 escapes at 0x1360dc
 *   stack: address of the slot at 0x70 escapes at 0x1360dc
 *   stack: address of the slot at 0x70 escapes at 0x136110
 *   delay: lui at 0x136128 writes a register its branch at 0x136124 reads
 *   fpu: float literal 0x40800000 at 0x136148
 *   fpu: float literal 0x40800000 at 0x136174
 *   fpu: float literal 0x40800000 at 0x136190
 *   fpu: float literal 0x40800000 at 0x1361ac
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */


extern void sceVu0InversMatrix(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern void sceVu0TransposeMatrix(void *, void *);


struct dw_102891_fields;
struct dw_108094;
struct dw_82520_fields;
struct dw_83647_fields;
struct dw_84552_fields;

struct dw_94469_fields;
struct dw_95063_fields;
struct dw_97846_fields;
#ifndef PROTO_DW_81473_FIELDS
#define PROTO_DW_81473_FIELDS
struct dw_81473_fields { unsigned int VmdFileVersion; char *lpAp2FileName; int VmdFileSize; short MaterialNum; short MatrixNum; short ObjectNum; short GeomObjectNum; struct dw_94469_fields *lpMaterial; struct dw_102891_fields *lpMatrix; struct dw_82520_fields *lpObject; float GeomScale; unsigned int PrimNodeFormat; struct dw_95063_fields *lpLightObject; short LightObjectNum; short TextureNum; struct dw_85832_fields *lpBoundBox; int PolyNum : 24; int PrimNodeMax : 8; struct dw_84552_fields *lpHeadParam; struct dw_83647_fields *lpTexture; struct dw_108094 *lpHeadReserve; struct dw_97846_fields *lpPMObject; int Pad0[2]; };
#endif
#ifndef PROTO_DW_84552_FIELDS
#define PROTO_DW_84552_FIELDS
struct dw_84552_fields { int ProgramID; unsigned char ParallelDraw; unsigned char Fog; unsigned char ParallelLight; unsigned char PointLight; unsigned char AlphaSort; unsigned char Mirror; unsigned char AmbientID; unsigned char Specular; unsigned char ClothDataID; unsigned char DrawRegsID; unsigned char Pad0[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8_DEFINED
#define DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8 = (int)&(((struct dw_81473_fields *)0)->GeomScale) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_81473_FIELDS_LPHEADPARAM_7B3D1659_DEFINED
#define DCOMP_OFF_STRUCT_DW_81473_FIELDS_LPHEADPARAM_7B3D1659_DEFINED
enum { DCOMP_OFF_STRUCT_DW_81473_FIELDS_LPHEADPARAM_7B3D1659 = (int)&(((struct dw_81473_fields *)0)->lpHeadParam) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_84552_FIELDS_POINTLIGHT_2299B3F7_DEFINED
#define DCOMP_OFF_STRUCT_DW_84552_FIELDS_POINTLIGHT_2299B3F7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_84552_FIELDS_POINTLIGHT_2299B3F7 = (int)&(((struct dw_84552_fields *)0)->PointLight) - 0 };
#endif











extern void *GetTextureScroll(unsigned int);











extern int SfxMdl_GetTexScroll_ByPtr(void *, float *, float *);















/* SetMatrixPacket @ 0x135520 .. 0x135B8C (0x66c bytes, frame 0x2c0) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1341 -> 0x228670
 *   literal: @1348 -> 0x228680
 *   delay: lui at 0x1355e8 writes a register its branch at 0x1355e4 reads
 *   fpu: float literal 0x00000000 at 0x135604
 *   fpu: float literal 0x40490fdb at 0x135628
 *   fpu: float literal 0x40c90fdb at 0x135660
 *   stack: address of the slot at 0x130 escapes at 0x135680
 *   fpu: float literal 0x40c90fdb at 0x135688
 *   stack: address of the slot at 0x280 escapes at 0x1356b8
 *   fpu: float literal 0x40490fdb at 0x1356cc
 *   fpu: float literal 0x00000000 at 0x1356d0
 *   fpu: float literal 0x40c90fdb at 0x1356f0
 *   fpu: mtc1 reinterprets v0 at 0x135714
 *   stack: address of the slot at 0x280 escapes at 0x135740
 *   stack: address of the slot at 0x280 escapes at 0x135740
 *   fpu: float literal 0x40490fdb at 0x135754
 *   fpu: float literal 0x00000000 at 0x135758
 *   fpu: float literal 0x40c90fdb at 0x135778
 *   fpu: mtc1 reinterprets v0 at 0x13579c
 *   stack: address of the slot at 0x280 escapes at 0x1357c8
 *   stack: address of the slot at 0x280 escapes at 0x1357c8
 *   stack: address of the slot at 0x280 escapes at 0x135828
 *   stack: address of the slot at 0x280 escapes at 0x135828
 *   stack: address of the slot at 0x130 escapes at 0x135828
 *   stack: address of the slot at 0x240 escapes at 0x135838
 *   stack: address of the slot at 0x280 escapes at 0x135838
 *   stack: address of the slot at 0x200 escapes at 0x13584c
 *   stack: address of the slot at 0x1c0 escapes at 0x13585c
 *   stack: address of the slot at 0x200 escapes at 0x13585c
 *   stack: address of the slot at 0x180 escapes at 0x135868
 *   stack: address of the slot at 0x1c0 escapes at 0x135868
 *   stack: address of the slot at 0x140 escapes at 0x135878
 *   stack: address of the slot at 0x180 escapes at 0x135878
 *   stack: address of the slot at 0x140 escapes at 0x135888
 *   stack: address of the slot at 0x140 escapes at 0x135888
 *   stack: address of the slot at 0x240 escapes at 0x135888
 *   stack: address of the slot at 0x140 escapes at 0x135898
 *   fpu: float literal 0x00000000 at 0x1358c0
 *   fpu: float literal 0x40490fdb at 0x1358d4
 *   fpu: float literal 0x40c90fdb at 0x13592c
 *   fpu: float literal 0x40c90fdb at 0x135954
 *   fpu: float literal 0x3f800000 at 0x13597c
 *   stack: address of the slot at 0xf0 escapes at 0x135990
 *   fpu: float literal 0x40490fdb at 0x1359a4
 *   fpu: float literal 0x00000000 at 0x1359a8
 *   fpu: float literal 0x40c90fdb at 0x1359c8
 *   fpu: mtc1 reinterprets v0 at 0x1359ec
 *   fpu: float literal 0x3f800000 at 0x135a14
 *   stack: address of the slot at 0xf0 escapes at 0x135a24
 *   stack: address of the slot at 0xf0 escapes at 0x135a24
 *   fpu: float literal 0x40490fdb at 0x135a38
 *   fpu: float literal 0x00000000 at 0x135a3c
 *   fpu: float literal 0x40c90fdb at 0x135a5c
 *   fpu: mtc1 reinterprets v0 at 0x135a80
 *   fpu: float literal 0x3f800000 at 0x135aa8
 *   stack: address of the slot at 0xf0 escapes at 0x135ab8
 *   stack: address of the slot at 0xf0 escapes at 0x135ab8
 *   stack: address of the slot at 0xf0 escapes at 0x135b18
 *   stack: address of the slot at 0xf0 escapes at 0x135b18
 *   stack: address of the slot at 0xa0 escapes at 0x135b18
 *   stack: address of the slot at 0xb0 escapes at 0x135b28
 *   stack: address of the slot at 0xf0 escapes at 0x135b28
 *   stack: address of the slot at 0xb0 escapes at 0x135b38
 *   literal: @1348 initializes the 16-byte local at 0xa0
 *   literal: @1341 initializes the 16-byte local at 0x130
 *   cfg: loop body is not one contiguous region: .L001355D8
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */



extern u32 L1341[];
extern u32 MRX1[];
extern u32 L1348[];



#ifndef PROTO_DW_106614_FIELDS
#define PROTO_DW_106614_FIELDS

#endif
#ifndef PROTO_DW_102500_FIELDS
#define PROTO_DW_102500_FIELDS

#endif
#ifndef PROTO_DW_101152_FIELDS
#define PROTO_DW_101152_FIELDS

#endif
#ifndef PROTO_DW_78578_FIELDS
#define PROTO_DW_78578_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPANIMCTRL_C8B66345_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPANIMCTRL_C8B66345_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPANIMCTRL_C8B66345 = (int)&(((struct dw_78578_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D = (int)&(((struct dw_78578_fields *)0)->lpObjMat) - 0 };
#endif

struct SmpVmdMat { s16 ObjA; s16 ObjB; float Rate; int pad8; int Flag; };
struct SmpAnim { u8 pad0[0x40]; float Pos[4]; float Ang[4]; u8 pad60[0x70]; };
struct SmpObj { float Position[4]; float Angle[4]; float Scale[4]; u8 pad30[0x30]; };
struct SmpHead { u8 pad0[0xe]; s16 MatrixNum; s16 ObjectNum; u8 pad12[6]; struct SmpVmdMat *lpMatrix; struct SmpObj *lpObject; };

#define SMP_WRAP(dst, ang) { float shifted; float angle; angle = (ang); shifted = 3.1415927f + angle; \
    if (shifted >= 0.0f) { dst = angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f); } \
    else { dst = 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f)); } }




/* MakePresetMdlMatrix @ 0x134D80 .. 0x135104 (0x384 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x134dc8
 *   fpu: float literal 0x00000000 at 0x134dcc
 *   fpu: float literal 0x40c90fdb at 0x134dec
 *   fpu: mtc1 reinterprets v0 at 0x134e10
 *   fpu: float literal 0x40490fdb at 0x134e3c
 *   fpu: float literal 0x00000000 at 0x134e40
 *   fpu: float literal 0x40c90fdb at 0x134e60
 *   fpu: mtc1 reinterprets v0 at 0x134e84
 *   fpu: float literal 0x40490fdb at 0x134eb0
 *   fpu: float literal 0x00000000 at 0x134eb4
 *   fpu: float literal 0x40c90fdb at 0x134ed4
 *   fpu: mtc1 reinterprets v0 at 0x134ef8
 *   fpu: mov.s at 0x134f1c is a float copy
 *   fpu: mov.s at 0x134f20 is a float copy
 *   fpu: mov.s at 0x134f28 is a float copy
 *   fpu: mov.s at 0x134f2c is a float copy
 *   fpu: mov.s at 0x134f34 is a float copy
 *   fpu: mov.s at 0x134f38 is a float copy
 *   fpu: mov.s at 0x134f40 is a float copy
 *   fpu: mov.s at 0x134f44 is a float copy
 *   fpu: mov.s at 0x134f4c is a float copy
 *   fpu: mov.s at 0x134f50 is a float copy
 *   fpu: mov.s at 0x134f58 is a float copy
 *   stack: address of the slot at 0x80 escapes at 0x135098
 *   delay: addiu at 0x1350c8 writes a register its branch at 0x1350c4 reads
 *   cfg: loop body is not one contiguous region: .L00135058
 *   declaration vs inferred signature: return void vs inferred u32
 */



#ifndef PROTO_DW_106614_FIELDS
#define PROTO_DW_106614_FIELDS

#endif
#ifndef PROTO_DW_102500_FIELDS
#define PROTO_DW_102500_FIELDS

#endif
#ifndef PROTO_DW_101152_FIELDS
#define PROTO_DW_101152_FIELDS

#endif
#ifndef PROTO_DW_78578_FIELDS
#define PROTO_DW_78578_FIELDS

#endif
#ifndef PROTO_DW_110672_FIELDS
#define PROTO_DW_110672_FIELDS

#endif
#ifndef PROTO_DW_109200_FIELDS
#define PROTO_DW_109200_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED
#define DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_0__A3C72D09_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_0__A3C72D09_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_0__A3C72D09 = (int)&(((struct dw_78578_fields *)0)->Ang[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_1__108395AF_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_1__108395AF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_1__108395AF = (int)&(((struct dw_78578_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_2__81D69CC9_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_2__81D69CC9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_2__81D69CC9 = (int)&(((struct dw_78578_fields *)0)->Ang[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7 = (int)&(((struct dw_78578_fields *)0)->Scl[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0 = (int)&(((struct dw_78578_fields *)0)->Scl[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_BPRESETMATRIX_2C185325_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_BPRESETMATRIX_2C185325_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_BPRESETMATRIX_2C185325 = (int)&(((struct dw_78578_fields *)0)->bPresetMatrix) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPLOCALMAT_866ABF3A_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPLOCALMAT_866ABF3A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPLOCALMAT_866ABF3A = (int)&(((struct dw_78578_fields *)0)->lpLocalMat) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMI3HEAD_E8C8709F_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMI3HEAD_E8C8709F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMI3HEAD_E8C8709F = (int)&(((struct dw_78578_fields *)0)->lpMi3Head) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D_DEFINED
#define DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D = (int)&(((struct dw_78578_fields *)0)->lpObjMat) - 0 };
#endif
struct VmdX { u8 pad[0x10]; s16 cnt; };
struct MdlDataX { u8 pad[0x10]; u8 *lpVmdHead; };



u8 *lpDrawMng = (u8 *)&DrawMngSt;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void DrawInit(void);
void ResetDraw(void);
void DrawSetViewScreenClipMatrix(void *a0 , void *a1 , void *a2 , float f12 , float f13 , float f14 , float f15 , float f16 , float f17 , float f18 , float f19 , float arg11, float arg12, float arg13);
void DrawSetViewRange(void);
void DrawSetViewRange16(void);
void InitLightMat(void);
void SetFog(float f12 , float f13 , signed int *a0 );
void DrawCalcView(void);
void DrawClearImage(void);
void DrawSynch(void);
void DrawSetClearColor(signed int *a0 );
void UpdateWorldMatrixNoAnim(void *a0 , void *a1 );
void UpdateWorldMatrixWithAnim(void *a0 , void *a1 , void *a2 );
void DrawModel(struct dw_78578 *a0 );
static void DrawVmdModel(void *a0 );
static unsigned int * DrawVmdObject(unsigned int *s5, void *a1 , void *a2 , void *a3 );
static u32 *DrawVmdMorphObject(u32 *packet,void *object,void *model,void *matrices);
unsigned int * SetCameraPacket(unsigned int *lpCurDMA);
unsigned int * SetDirLightPacket(unsigned int *lpCurDMA, float ModelScale, float ModelAlpha, void *lpParam);
unsigned int * SetAmbientLightPacket(unsigned int *lpCurDMA, float ModelAlpha, void *lpParam);
static unsigned int * SetPointLightPacket();
unsigned int *SetTexScrollPacket(unsigned int *packet,unsigned char index,float scale);
static unsigned int *SetTexScrollSfxPacket(unsigned int *packet, void *model);
unsigned int * SetMatrixPacket(unsigned int *lpCurDMA, void *lpVmdHeadSt, void *lpMdlMngSt);
unsigned int CheckDrawModel(void *a0 );
void SetAmbientColor(u8 *a0 );
void GetAmbientColor(u8 *a0 );
signed int CheckPointInBoundBox(float *a0, void *a1);
void MakePresetMdlMatrix(void *a0 );
signed int CheckDramaDrawModel(void *a0 );
signed int CheckRiddleDrawModel(void *a0 );



void DrawInit(void) {
    int i;

    memset(lpDrawMng, 0, 0x470);
    sceGsResetPath();
    sceGsResetGraph(0, 1, 2, 0);
    InitVramMng(0x200, 0x1c0, 1, 0x31);
    *(u32 *)(lpDrawMng + 0x400) = 0x70000000;
    *(u32 *)(lpDrawMng + 0x3f4) = 0x70001c00;
    *(u32 *)(lpDrawMng + 0x3f8) = 0x70002e00;
    *(u8 *)(lpDrawMng + 0x430) = 0;
    *(float *)(lpDrawMng + 0x41c) = 0.785249949f;
    DrawSetViewScreenClipMatrix(lpDrawMng + 0x270, lpDrawMng + 0x330, lpDrawMng + 0x3b0,
        *(float *)(lpDrawMng + 0x41c), 0.800000012f, 1.0f, 2048.0f, 2048.0f,
        0.0f, 16776960.0f, 0.0500000007f, 100.0f, 2047.0f, 2047.0f);
    *(u32 *)(lpDrawMng + 0x408) = 0;
    *(u32 *)(lpDrawMng + 0x3fc) = 0;
    *(u32 *)(lpDrawMng + 0x404) = 0;
    *(u32 *)(lpDrawMng + 0x420) = 0;
    SyncDCache(lpDrawMng, lpDrawMng + 0x470);
    SyncDCache(MdlMng, (u8 *)(MdlMng + 0x54380));
    {
        int col[4] = {0};
        *(u32 *)(lpDrawMng + 0x450) = 0x3cc71f47;
        *(u32 *)(lpDrawMng + 0x454) = 0x490f6df6;
        *(u32 *)(lpDrawMng + 0x458) = 0;
        *(u32 *)(lpDrawMng + 0x45c) = 0x457f0000;
        *(u32 *)(lpDrawMng + 0x460) = 0x40c71f47;
        *(u32 *)(lpDrawMng + 0x464) = 0x450f6df6;
        *(u32 *)(lpDrawMng + 0x468) = 0;
        *(u32 *)(lpDrawMng + 0x46c) = 0x457f0000;
        *(u8 *)(lpDrawMng + 0x100) = col[0];
        *(u8 *)(lpDrawMng + 0x101) = col[1];
        *(u8 *)(lpDrawMng + 0x102) = col[2];
        *(u8 *)(lpDrawMng + 0x103) = col[3];
        *(u8 *)(lpDrawMng + 0x1f0) = col[0];
        *(u8 *)(lpDrawMng + 0x1f1) = col[1];
        *(u8 *)(lpDrawMng + 0x1f2) = col[2];
        *(u8 *)(lpDrawMng + 0x1f3) = col[3];
    }
    InitShadowMatrix();
    for (i = 0; i < 0x20; i++) {
        ((float *)SinTable)[i] = sinf(3.14159274f * (float)i / 32.0f);
        ((float *)SinTable)[i + 0x20] = -((float *)SinTable)[i];
    }
}


/* ResetDraw @ 0x1383C0 .. 0x1383D4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j InitVramMng at 0x1383cc leaves the function
 *   return value dropped, call kept: the function is void
 */











void ResetDraw(void) {
    InitVramMng(0x200, 0x1c0, 1, 0x31);
    return;
}



void DrawSetViewScreenClipMatrix(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */, float f12
        /* f12 */, float f13 /* f13 */, float f14 /* f14 */, float f15 /* f15 */, float f16 /* f16
        */, float f17 /* f17 */, float f18 /* f18 */, float f19 /* f19 */, float arg11, float
        arg12, float arg13) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    float f3;
    float f31;
    float f30;
    float f29;
    float f28;
    float f27;
    float f26;
    float f25;
    float f24;
    float f23;
    float f2;
    float f2_v1; // f2
    float f2_v2; // f2
    float screenHeight;
    float f0;
    float f22;
    float f21;
    float f20;
    void *a2_2; // a2
    void *a0_2; // a0
    u32 v0;
    float unused, depth, product, negative;
    float matrix[16] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    s1 = (u8 *)a1;
    s0 = (u8 *)a2;
    f24 = *(float *)((u8 *)&arg11);
    f31 = (float)f13;
    f30 = (float)f14;
    f29 = (float)f15;
    f28 = (float)f16;
    f27 = (float)f17;
    f26 = (float)f18;
    f25 = (float)f19;
    f0 = atanf((f12 / 2.0f));
    f20 = 3.2e+02f / f0;
    negative = -f26;
    f22 = ((f25 * arg12) / f20);
    f21 = ((f25 * arg13) / f20);
    v0 = (u32)lpDrawMng;
    v0 = *(u8 *)(v0 + 0x430);
    f0 = negative;
    f2 = ((-f25) + f24);
    f0 = f0 * f25 + f27 * f24;
    f23 = (f0 / f2);
    product = f24 * f25;
    depth = (product * ((-f27) + f26)) / f2;
    if (v0 == 0) {
        sceVu0UnitMatrix((void *)s2);
        *(f32 *)s2 = f20;
        v0 = 0x3f800000;
        *(f32 *)(s2 + 0x14) = f20;
        *(u32 *)(s2 + 0x28) = 0;
        *(u32 *)(s2 + 0x3c) = 0;
        *(u32 *)(s2 + 0x38) = 0x3f800000;
        *(u32 *)(s2 + 0x2c) = 0x3f800000;
        sceVu0UnitMatrix(matrix);
        f0 = depth;
        a0_2 = (void *)s2;
        a2_2 = (void *)s2;
        matrix[14] = f23;
        matrix[0] = f31;
        matrix[5] = f30;
        matrix[12] = f29;
        matrix[10] = f0;
        matrix[13] = f28;
        sceVu0MulMatrix(a0_2, matrix, a2_2);
    } else {
        sceVu0UnitMatrix((void *)s2);
        *(f32 *)s2 = f31;
        v0 = -0x40800000;
        *(f32 *)(s2 + 0x14) = (-f30);
        *(f32 *)(s2 + 0x28) = ((f26 - f27) / (f24 - f25));
        *(u32 *)(s2 + 0x3c) = -0x40800000;
        *(f32 *)(s2 + 0x30) = (-f29);
        *(f32 *)(s2 + 0x34) = (-f28);
        *(f32 *)(s2 + 0x38) = f23;
    }
    sceVu0UnitMatrix((void *)s1);
    a0_2 = (void *)s0;
    f2_v1 = (2.0f * f25);
    v0 = 0x3f800000;
    f0 = -2.0f * product;
    *(f32 *)s1 = (f2_v1 / (f22 + f22));
    *(f32 *)(s1 + 0x14) = (f2_v1 / (f21 + f21));
    f2_v2 = (f24 - f25);
    *(f32 *)(s1 + 0x28) = ((f24 + f25) / f2_v2);
    *(f32 *)(s1 + 0x38) = (f0 / f2_v2);
    *(u32 *)(s1 + 0x2c) = 0x3f800000;
    *(u32 *)(s1 + 0x3c) = 0;
    sceVu0UnitMatrix(a0_2);
    a0_2 = (void *)0x40000000;
    *(f32 *)s0 = ((f22 * (f20 * f31)) / f25);
    *(f32 *)(s0 + 0x14) = ((f21 * (f20 * f30)) / f25);
    *(f32 *)(s0 + 0x28) = ((negative + f27) / 2.0f);
    *(f32 *)(s0 + 0x38) = ((f26 + f27) / 2.0f);
    *(f32 *)(s0 + 0x30) = f29;
    *(f32 *)(s0 + 0x34) = f28;
    *(u32 *)(s0 + 0x3c) = 0x3f800000;
    return;
}


/* DrawSetViewRange @ 0x138090 .. 0x138110 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x1380b4
 *   fpu: float literal 0x3f4ccccd at 0x1380b8
 *   fpu: float literal 0x4b7fff00 at 0x1380cc
 *   fpu: float literal 0x45000000 at 0x1380e0
 *   fpu: float literal 0x3d4ccccd at 0x1380e8
 *   fpu: float literal 0x00000000 at 0x1380f0
 *   fpu: mov.s at 0x1380f8 is a float copy
 */










void DrawSetViewRange(void) {
    s32 v0;
    float *a0;
    float *a3;
    s32 v1;
    u8 stackFrame[32] __attribute__((aligned(16)));

    v0 = 0x44ff0000;
    a0 = (float *)(0x44ff0000 | 0xe000);
    a3 = (float *)((u32)lpDrawMng);
    v0 = 0x3f4c0000;
    v1 = 0x3f4c0000 | 0xcccd;
    DrawSetViewScreenClipMatrix((void *)(float *)((u8 *)a3 + 0x270), (void *)(float *)((u8 *)a3 +
        0x330), (void *)(float *)((u8 *)a3 + 0x3b0), (float)*(float *)(((u8 *)a3 + 0x41c)),
        0.800000012f, 1.0f, 2048.0f, (float)(float)2048.0f, 0.0f, 16776960.0f, 0.0500000007f,
        100.0f, 2047.0f, 2047.0f);
    return;
}


/* DrawSetViewRange16 @ 0x138010 .. 0x138090 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f000000 at 0x138034
 *   fpu: float literal 0x3ecccccd at 0x138038
 *   fpu: float literal 0x477fff00 at 0x13804c
 *   fpu: float literal 0x45000000 at 0x138060
 *   fpu: float literal 0x3d4ccccd at 0x138068
 *   fpu: float literal 0x00000000 at 0x138070
 *   fpu: mov.s at 0x138078 is a float copy
 */












void DrawSetViewRange16(void) {
    s32 v0;
    float *a0;
    float *a3;
    s32 v1;
    u8 stackFrame[32] __attribute__((aligned(16)));

    v0 = 0x44ff0000;
    a0 = (float *)(0x44ff0000 | 0xe000);
    a3 = (float *)((u32)lpDrawMng);
    v0 = 0x3ecc0000;
    v1 = 0x3ecc0000 | 0xcccd;
    DrawSetViewScreenClipMatrix((void *)(float *)((u8 *)a3 + 0x270), (void *)(float *)((u8 *)a3 +
        0x330), (void *)(float *)((u8 *)a3 + 0x3b0), (float)*(float *)(((u8 *)a3 + 0x41c)),
        0.400000006f, 0.5f, 2048.0f, (float)(float)2048.0f, 0.0f, 65535.0f, 0.0500000007f, 100.0f,
        2047.0f, 2047.0f);
    return;
}


/* InitLightMat @ 0x137DC0 .. 0x138004 (0x244 bytes, frame 0x110) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @879 -> 0x228570
 *   literal: @883 -> 0x228580
 *   literal: @885 -> 0x228590
 *   literal: @887 -> 0x2285a0
 *   literal: @889 -> 0x2285b0
 *   literal: @891 -> 0x2285c0
 *   literal: @893 -> 0x2285d0
 *   literal: @896 -> 0x2285e0
 *   literal: @898 -> 0x2285f0
 *   literal: @900 -> 0x228600
 *   literal: @902 -> 0x228610
 *   literal: @904 -> 0x228620
 *   literal: @906 -> 0x228630
 *   literal: @908 -> 0x228640
 *   literal: @910 -> 0x228650
 *   delay: lui at 0x137dd8 writes a register its branch at 0x137dd4 reads
 *   stack: address of the slot at 0x100 escapes at 0x137df0
 *   stack: address of the slot at 0xf0 escapes at 0x137e04
 *   stack: address of the slot at 0xf0 escapes at 0x137e28
 *   stack: address of the slot at 0xe0 escapes at 0x137e48
 *   stack: address of the slot at 0xd0 escapes at 0x137e68
 *   stack: address of the slot at 0xc0 escapes at 0x137e88
 *   stack: address of the slot at 0xb0 escapes at 0x137ea8
 *   stack: address of the slot at 0xa0 escapes at 0x137ec8
 *   stack: address of the slot at 0x90 escapes at 0x137ee8
 *   stack: address of the slot at 0x80 escapes at 0x137f10
 *   stack: address of the slot at 0x70 escapes at 0x137f30
 *   stack: address of the slot at 0x60 escapes at 0x137f50
 *   stack: address of the slot at 0x50 escapes at 0x137f70
 *   stack: address of the slot at 0x40 escapes at 0x137f90
 *   stack: address of the slot at 0x30 escapes at 0x137fb0
 *   stack: address of the slot at 0x20 escapes at 0x137fd0
 *   stack: address of the slot at 0x10 escapes at 0x137ff0
 *   literal: @910 initializes the 16-byte local at 0x10
 *   literal: @908 initializes the 16-byte local at 0x20
 *   literal: @906 initializes the 16-byte local at 0x30
 *   literal: @904 initializes the 16-byte local at 0x40
 *   literal: @902 initializes the 16-byte local at 0x50
 *   literal: @900 initializes the 16-byte local at 0x60
 *   literal: @898 initializes the 16-byte local at 0x70
 *   literal: @896 initializes the 16-byte local at 0x80
 *   literal: @893 initializes the 16-byte local at 0x90
 *   literal: @891 initializes the 16-byte local at 0xa0
 *   literal: @889 initializes the 16-byte local at 0xb0
 *   literal: @887 initializes the 16-byte local at 0xc0
 *   literal: @885 initializes the 16-byte local at 0xd0
 *   literal: @883 initializes the 16-byte local at 0xe0
 *   literal: @879 initializes the 16-byte local at 0x100
 */











void InitLightMat(void) {
    u8 *a0;
    u32 v1;
    u32 v0;

    v1 = GameSt[5];
    if (v1 == (u32)4) {
        v0 = 0x228570;
        a0 = (u8 *)sgLightMat;
        {
            struct stackFrame_100 { u8 b[16]; } stackFrame_100 __attribute__((aligned(16))) =
                {{0xcd, 0xcc, 0xcc, 0x3d, 0xcd, 0xcc, 0x4c, 0xbe, 0xcd, 0xcc, 0xcc, 0xbd, 0x00,
                0x00, 0x80, 0x3f}};
            sceVu0CopyVector(sgLightMat, (u8 *)((u8 *)&stackFrame_100));
            {
                u8 stackFrame_F0[16] __attribute__((aligned(16))) = {0};
                a0 = (u8 *)(sgLightMat + 4);
                sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_F0[0]));
                v0 = 0x228580;
                a0 = (u8 *)(sgLightMat + 8);
                {
                    struct stackFrame_E0 { u8 b[16]; } stackFrame_E0 __attribute__((aligned(16))) =
                        {{0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x3f,
                        0x00, 0x00, 0x80, 0x3f}};
                    sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_E0));
                    v0 = 0x228590;
                    a0 = (u8 *)(sgLightMat + 0xc);
                    {
                        struct stackFrame_D0 { u8 b[16]; } stackFrame_D0
                            __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
                        sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_D0));
                        v0 = 0x2285a0;
                        a0 = (u8 *)sgColorMat;
                        {
                            struct stackFrame_C0 { u8 b[16]; } stackFrame_C0
                                __attribute__((aligned(16))) = {{0x9a, 0x99, 0x99, 0x3e, 0x9a,
                                0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x00, 0x00, 0x80, 0x3f}};
                            sceVu0CopyVector(sgColorMat, (u8 *)((u8 *)&stackFrame_C0));
                            v0 = 0x2285b0;
                            a0 = (u8 *)(sgColorMat + 4);
                            {
                                struct stackFrame_B0 { u8 b[16]; } stackFrame_B0
                                    __attribute__((aligned(16))) = {{0x9a, 0x99, 0x99, 0x3e, 0x9a,
                                    0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x00, 0x00, 0x80,
                                    0x3f}};
                                sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_B0));
                                v0 = 0x2285c0;
                                a0 = (u8 *)(sgColorMat + 8);
                                {
                                    struct stackFrame_A0 { u8 b[16]; } stackFrame_A0
                                        __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x80, 0x3f}};
                                    sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_A0));
                                    v0 = 0x2285d0;
                                    a0 = (u8 *)(sgColorMat + 0xc);
                                    {
                                        struct stackFrame_90 { u8 b[16]; } stackFrame_90
                                            __attribute__((aligned(16))) = {{0x9a, 0x99, 0x99,
                                            0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e,
                                            0x00, 0x00, 0x80, 0x3f}};
                                        sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_90));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        v0 = 0x2285e0;
        a0 = (u8 *)sgLightMat;
        {
            struct stackFrame_80 { u8 b[16]; } stackFrame_80 __attribute__((aligned(16))) = {{0x00,
                0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0xc0, 0xbf, 0x00, 0x00, 0x00,
                0x00}};
            sceVu0CopyVector(sgLightMat, (u8 *)((u8 *)&stackFrame_80));
            v0 = 0x2285f0;
            a0 = (u8 *)(sgLightMat + 4);
            {
                struct stackFrame_70 { u8 b[16]; } stackFrame_70 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x3f, 0x00,
                    0x00, 0x00, 0x00}};
                sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_70));
                v0 = 0x228600;
                a0 = (u8 *)(sgLightMat + 8);
                {
                    struct stackFrame_60 { u8 b[16]; } stackFrame_60 __attribute__((aligned(16))) =
                        {{0x00, 0x00, 0xc0, 0xbf, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x3f,
                        0x00, 0x00, 0x00, 0x00}};
                    sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_60));
                    v0 = 0x228610;
                    a0 = (u8 *)(sgLightMat + 0xc);
                    {
                        struct stackFrame_50 { u8 b[16]; } stackFrame_50
                            __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
                        sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_50));
                        v0 = 0x228620;
                        a0 = (u8 *)sgColorMat;
                        {
                            struct stackFrame_40 { u8 b[16]; } stackFrame_40
                                __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00,
                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f}};
                            sceVu0CopyVector(sgColorMat, (u8 *)((u8 *)&stackFrame_40));
                            v0 = 0x228630;
                            a0 = (u8 *)(sgColorMat + 4);
                            {
                                struct stackFrame_30 { u8 b[16]; } stackFrame_30
                                    __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
                                    0x3f}};
                                sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_30));
                                v0 = 0x228640;
                                a0 = (u8 *)(sgColorMat + 8);
                                {
                                    struct stackFrame_20 { u8 b[16]; } stackFrame_20
                                        __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x80, 0x3f}};
                                    sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_20));
                                    v0 = 0x228650;
                                    a0 = (u8 *)(sgColorMat + 0xc);
                                    {
                                        struct stackFrame_10 { u8 b[16]; } stackFrame_10
                                            __attribute__((aligned(16))) = {{0xcd, 0xcc, 0x4c,
                                            0x3e, 0xcd, 0xcc, 0x4c, 0x3e, 0x00, 0x00, 0x80, 0x3e,
                                            0x00, 0x00, 0x80, 0x3f}};
                                        sceVu0CopyVector(a0, (u8 *)((u8 *)&stackFrame_10));
                                    }
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


/* SetFog @ 0x137CB0 .. 0x137DB8 (0x108 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0xc60322b5 at 0x137cd8
 *   fpu: float literal 0x457f0000 at 0x137ce0
 *   fpu: float literal 0x454ce63b at 0x137cf4
 *   fpu: float literal 0x494ce63b at 0x137d00
 *   fpu: float literal 0xc20322b5 at 0x137d04
 */


















void SetFog(float f12 /* f12 */, float f13 /* f13 */, signed int *a0 /* r4 */) {
    u32 t0;
    u32 a2;
    u32 a1;
    float f6;
    u32 a0_scalar; // a0
    u32 v1;

    v1 = -0x39fd0000;
    t0 = -0x39fd0000 | 0x22b5;
    a1 = 0x494c0000;
    f6 = (f12 - f13);
    a2 = 0x494c0000 | 0xe63b;
    v1 = -0x3dfd0000;
    a1 = -0x3dfd0000 | 0x22b5;
    *(f32 *)(((u8 *)lpDrawMng + 0x450)) = (4080.0f / (-8392.67676f * f6));
    *(f32 *)(((s32)((u32)(lpDrawMng)) + 0x454)) = (839267.688f + (-8392.67676f * f13));
    *(u32 *)(((s32)((u32)(lpDrawMng)) + 0x458)) = 0;
    *(u32 *)(((s32)((u32)(lpDrawMng)) + 0x45c)) = 0x457f0000;
    *(f32 *)(((s32)((u32)(lpDrawMng)) + 0x460)) = (4080.0f / (-32.7838936f * f6));
    *(f32 *)(((s32)((u32)(lpDrawMng)) + 0x464)) = (3278.3894f + (-32.7838936f * f13));
    *(u32 *)(((s32)((u32)(lpDrawMng)) + 0x468)) = 0;
    *(u32 *)(((s32)((u32)(lpDrawMng)) + 0x46c)) = 0x457f0000;
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x100)) = *(s32 *)a0;
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x101)) = a0[1];
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x102)) = a0[2];
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x103)) = a0[3];
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x1f0)) = *(s32 *)a0;
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x1f1)) = a0[1];
    *(u8 *)(((s32)((u32)(lpDrawMng)) + 0x1f2)) = a0[2];
    a0_scalar = a0[3];
    v1 = (u32)lpDrawMng;
    *(u8 *)((v1 + 0x1f3)) = a0_scalar;
    return;
}


/* DrawCalcView @ 0x137A60 .. 0x137CA4 (0x244 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x10 escapes at 0x137a68
 *   fpu: float literal 0x40490fdb at 0x137a9c
 *   fpu: float literal 0x00000000 at 0x137aa0
 *   fpu: float literal 0x40c90fdb at 0x137ac0
 *   fpu: mtc1 reinterprets v0 at 0x137ae4
 *   stack: address of the slot at 0x10 escapes at 0x137b0c
 *   stack: address of the slot at 0x10 escapes at 0x137b0c
 *   fpu: float literal 0x40490fdb at 0x137b20
 *   fpu: float literal 0x00000000 at 0x137b24
 *   fpu: float literal 0x40c90fdb at 0x137b44
 *   fpu: mtc1 reinterprets v0 at 0x137b68
 *   stack: address of the slot at 0x10 escapes at 0x137b90
 *   stack: address of the slot at 0x10 escapes at 0x137b90
 *   fpu: float literal 0x40490fdb at 0x137ba4
 *   fpu: float literal 0x00000000 at 0x137ba8
 *   fpu: float literal 0x40c90fdb at 0x137bc8
 *   fpu: mtc1 reinterprets v0 at 0x137bec
 *   stack: address of the slot at 0x10 escapes at 0x137c14
 *   stack: address of the slot at 0x10 escapes at 0x137c14
 *   stack: address of the slot at 0x50 escapes at 0x137c54
 *   stack: address of the slot at 0x10 escapes at 0x137c54
 *   stack: address of the slot at 0x50 escapes at 0x137c54
 *   stack: address of the slot at 0x10 escapes at 0x137c68
 *   stack: address of the slot at 0x50 escapes at 0x137c68
 */






void DrawCalcView(void) {
    u8 *v1;
    u32 v0;
    float f3;
    float f3_v1; // f3
    float f3_v2; // f3
    float f2;
    float f2_v1; // f2
    float f2_v2; // f2
    float f1;
    float f0;
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_10[64] __attribute__((aligned(16)));

    sceVu0UnitMatrix((void *)((u8 *)&stackFrame_10[0]));
    v0 = (u32)lpDrawMng;
    sceVu0CopyVector((u32)(v0 + 0x250), (u32)(v0 + 0x230));
    v0 = (u32)lpDrawMng;
    sceVu0CopyVector((u32)(v0 + 0x260), (u32)(v0 + 0x240));
    v1 = lpDrawMng;
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = *(float *)(v1 + 0x244);
    f3 = (3.14159274f + f2);
    if (f3 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f2 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
    }
    sceVu0RotMatrixY((void *)((u8 *)&stackFrame_10[0]), (void *)((u8 *)&stackFrame_10[0]), (-f0));
    v1 = lpDrawMng;
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2_v1 = *(float *)(v1 + 0x248);
    f3_v1 = (3.14159274f + f2_v1);
    if (f3_v1 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f2_v1 - (6.28318548f * (float)((float)(s32)(f3_v1 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (f2_v1 - (f1 * (float)((float)(s32)(f3_v1 / f1)))));
    }
    sceVu0RotMatrixZ((void *)((u8 *)&stackFrame_10[0]), (void *)((u8 *)&stackFrame_10[0]), (-f0));
    v1 = lpDrawMng;
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2_v2 = *(float *)(v1 + 0x240);
    f3_v2 = (3.14159274f + f2_v2);
    if (f3_v2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (f2_v2 - (6.28318548f * (float)((float)(s32)(f3_v2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (f2_v2 - (f1 * (float)((float)(s32)(f3_v2 / f1)))));
    }
    sceVu0RotMatrixX((void *)((u8 *)&stackFrame_10[0]), (void *)((u8 *)&stackFrame_10[0]), (-f0));
    v0 = (u32)lpDrawMng;
    *(f32 *)((u8 *)&stackFrame_50[0]) = (-*(float *)((v0 + 0x230)));
    ((f32 *)stackFrame_50)[1] = (-*(float *)((v0 + 0x234)));
    ((f32 *)stackFrame_50)[2] = (-*(float *)((v0 + 0x238)));
    ((f32 *)stackFrame_50)[3] = *(float *)((v0 + 0x23c));
    sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_50[0]), (void *)((u8 *)&stackFrame_10[0]), (void
        *)((u8 *)&stackFrame_50[0]));
    v0 = (u32)lpDrawMng;
    sceVu0TransMatrix((void *)(u32)(v0 + 0x2f0), (void *)((u8 *)&stackFrame_10[0]), (void *)((u8
        *)&stackFrame_50[0]));
    v0 = (u32)lpDrawMng;
    sceVu0MulMatrix((void *)(u32)(v0 + 0x2b0), (void *)(u32)(v0 + 0x270), (void *)(u32)(v0 +
        0x2f0));
    v0 = (u32)lpDrawMng;
    sceVu0MulMatrix((void *)(u32)(v0 + 0x370), (void *)(u32)(v0 + 0x330), (void *)(u32)(v0 +
        0x2f0));
    return;
}


/* DrawClearImage @ 0x1378C0 .. 0x137A60 (0x1a0 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$962 is the string 'DrawClearImage'
 *   literal: @2680 is the string ''
 *   stack: address of the slot at 0x60 escapes at 0x1379b4
 *   stack: address of the slot at 0x60 escapes at 0x1379c8
 *   stack: address of the slot at 0x60 escapes at 0x1379f8
 *   stack: address of the slot at 0x60 escapes at 0x137a0c
 */






void DrawClearImage(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    s16 s4;
    s16 s3;
    u32 v0;
    u32 *s2;
    u32 *s1;
    s32 s0;
    u8 stackFrame_60[96] __attribute__((aligned(16)));

    a0 = 0x2000;
    a1 = (u32)((char *)__FUNCTION__);
    a2 = (u32)"";
    v0 = (u32)MemAllocReal(a0, ((char *)__FUNCTION__), "");
    s2 = (u32 *)v0;
    a0 = 0x2000;
    a1 = (u32)((char *)__FUNCTION__);
    a2 = (u32)"";
    v0 = (u32)MemAllocReal(a0, ((char *)__FUNCTION__), "");
    s1 = (u32 *)v0;
    v1 = 0x800;
    a0 = (u32)s2;
    if (v1-- != 0) {
        do {
            *(u32 *)a0 = 0;
            a0 = a0 + 4;
        } while (v1-- != 0);
    }
    a0 = 0x800;
    v1 = (u32)s1;
    if (a0-- != 0) {
        do {
            *(u32 *)v1 = 0;
            v1 = v1 + 4;
        } while (a0-- != 0);
    }
    s0 = 0x100;
    s4 = 0;
    s3 = 0x20;
    if (s0-- != 0) {
        do {
            sceGsSetDefLoadImage((void *)((u8 *)&stackFrame_60[0]), s4, 1, 0, 0, 0, 0x40, 0x20);
            FlushCache(0);
            sceGsExecLoadImage((void *)((u8 *)&stackFrame_60[0]), (void *)s2);
            s4 += 0x40;
            sceGsSetDefLoadImage((void *)((u8 *)&stackFrame_60[0]), s3, 1, 0, 0, 0, 0x40, 0x20);
            FlushCache(0);
            sceGsExecLoadImage((void *)((u8 *)&stackFrame_60[0]), (void *)s1);
            s3 += 0x40;
        } while (s0-- != 0);
    }
    MemFree((void *)s2);
    MemFree((void *)s1);
    return;
}


/* DrawSynch @ 0x137870 .. 0x1378BC (0x4c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






void DrawSynch(void) {
    u32 v0;
    u32 v1;
    u32 a0;
    u32 a1;

    v0 = sceGsSyncV(0);
    v1 = ((u32)lpDrawMng);
    *(u32 *)((v1 + 0x40c)) = v0;
    FlushCache(0);
    a0 = ((u32)lpDrawMng);
    a1 = *(s32 *)((a0 + 0x408));
    sceGsSwapDBuff(a0, a1);
    a0 = ((u32)lpDrawMng);
    v1 = *(s32 *)((a0 + 0x408));
    v1 = v1 != 0;
    v1 = v1 ^ 1;
    *(u32 *)((a0 + 0x408)) = v1;
    return;
}


/* DrawSetClearColor @ 0x137800 .. 0x137864 (0x64 bytes) */








void DrawSetClearColor(signed int *a0 /* r4 */) {
    u32 a0_scalar; // a0
    u8 *v1;

    *(u8 *)(((u8 *)lpDrawMng + 0x100)) = *(s32 *)a0;
    *(u8 *)(((u8 *)lpDrawMng + 0x101)) = a0[1];
    *(u8 *)(((u8 *)lpDrawMng + 0x102)) = a0[2];
    *(u8 *)(((u8 *)lpDrawMng + 0x103)) = a0[3];
    *(u8 *)(((u8 *)lpDrawMng + 0x1f0)) = *(s32 *)a0;
    *(u8 *)(((u8 *)lpDrawMng + 0x1f1)) = a0[1];
    *(u8 *)(((u8 *)lpDrawMng + 0x1f2)) = a0[2];
    a0_scalar = a0[3];
    v1 = (u8 *)lpDrawMng;
    *(u8 *)(v1 + 0x1f3) = a0_scalar;
    return;
}


/* UpdateWorldMatrixNoAnim @ 0x137730 .. 0x1377FC (0xcc bytes, frame 0x70) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00137778
 *   declaration vs inferred signature: return void vs inferred u32
 */






void UpdateWorldMatrixNoAnim(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s5;
    u32 s4;
    s32 s3;
    u8 *s2;
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;
    void *a0_2;

    s5 = (u8 *)a0;
    s4 = (u32)a1;
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    s2 = (u8 *)*(s32 *)((v1 + 0x10));
    v1 = *(s16 *)(s2 + 0x10);
    s1 = (u8 *)*(s32 *)(s2 + 0x1c);
    s3 = 0;
    if ((u8 *)0 < (u8 *)v1) {
        s0 = 0;
        do {
            v0 = *(s16 *)(s1 + 0x34);
            v1 = v0 << 6;
            if ((s32)v0 >= 0) {
                a0_2 = (void *)*(s32 *)(s5 + 0x10);
                v0 = *(s32 *)(s5 + 0x18);
                sceVu0MulMatrix((void *)(u32)(s32)((u8 *)a0_2 + s0), (void *)(u32)(s32)((u8 *)a0_2
                    + v1), (void *)(s32)(v0 + s0));
            } else {
                v1 = *(s32 *)(s5 + 0x10);
                v0 = *(s32 *)(s5 + 0x18);
                sceVu0MulMatrix((void *)(u32)(v1 + s0), (void *)s4, (void *)(s32)(v0 + s0));
            }
            v1 = *(s16 *)(s2 + 0x10);
            s3 = s3 + 1;
            s0 = s0 + 0x40;
            v1 = (u32)s3 < v1;
            s1 = (u8 *)(s1 + 0x60);
        } while (v1 != 0);
    }
    return;
}


/* UpdateWorldMatrixWithAnim @ 0x137590 .. 0x137728 (0x198 bytes, frame 0x60) */





void UpdateWorldMatrixWithAnim(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s4;
    u32 s3;
    u32 a3;
    u8 *s2;
    u32 v1;
    s32 s1;
    u32 v0;
    u8 *s0;
    void *a0_2;
    void *a1_2;
    void *a2_2;

    v1 = 2;
    s4 = (u8 *)a0;
    s3 = (u32)a2;
    a0_2 = (void *)*(u8 *)(((u8 *)a1 + 0x29));
    s2 = (u8 *)a1;
    if ((u32)a0_2 != v1) {
        v1 = *(s32 *)(s2 + 0x24);
        v1 = v1 & 8;
        if (v1 == 0) {
            v1 = *(s32 *)(s2 + 0x18);
            v0 = *(s32 *)(s4 + 0x10);
            a2_2 = (void *)(s2 + 0x80);
            sceVu0MulMatrix((void *)(u32)(v0 + (u32)(v1 << 6)), (void *)s3, a2_2);
        }
        s0 = (u8 *)*(s32 *)(s2 + 0xc4);
        if ((u32)(s32)s0 != 0) {
            a1_2 = (void *)*(s32 *)(s2 + 0x18);
            v1 = 2;
            a3 = *(s32 *)(s4 + 0x10);
            a0_2 = (void *)*(u8 *)(s0 + 0x29);
            s1 = (s32)((u8 *)a3 + (u32)((u32)a1_2 << 6));
            if ((u32)a0_2 != v1) {
                v1 = *(s32 *)(s0 + 0x24);
                if ((u32)(v1 & 8) == 0) {
                    v0 = *(s32 *)(s0 + 0x18);
                    a2_2 = (void *)(s0 + 0x80);
                    sceVu0MulMatrix((void *)(u32)(a3 + (u32)(v0 << 6)), (void *)(u32)s1, a2_2);
                }
                a1_2 = (void *)*(s32 *)(s0 + 0xc4);
                if ((u32)(s32)a1_2 != 0) {
                    v1 = *(s32 *)(s0 + 0x18);
                    v0 = *(s32 *)(s4 + 0x10);
                    UpdateWorldMatrixWithAnim((void *)s4, a1_2, (void *)(u32)(v0 + (u32)(v1 << 6)));
                }
                a1_2 = (void *)*(s32 *)(s0 + 0xc8);
                a2_2 = (void *)s1;
                if ((u32)(s32)a1_2 != 0) {
                    UpdateWorldMatrixWithAnim((void *)s4, a1_2, a2_2);
                }
            }
        }
        s0 = (u8 *)*(s32 *)(s2 + 0xc8);
        if ((u32)(s32)s0 != 0 && (u32)*(u8 *)(s0 + 0x29) != (u32)2) {
            v1 = *(s32 *)(s0 + 0x24);
            v1 = v1 & 8;
            if (v1 == 0) {
                v1 = *(s32 *)(s0 + 0x18);
                v0 = *(s32 *)(s4 + 0x10);
                a2_2 = (void *)(s0 + 0x80);
                sceVu0MulMatrix((void *)(u32)(v0 + (u32)(v1 << 6)), (void *)s3, a2_2);
            }
            a1_2 = (void *)*(s32 *)(s0 + 0xc4);
            if ((u32)(s32)a1_2 != 0) {
                v1 = *(s32 *)(s0 + 0x18);
                v0 = *(s32 *)(s4 + 0x10);
                UpdateWorldMatrixWithAnim((void *)s4, a1_2, (void *)(u32)(v0 + (u32)(v1 << 6)));
            }
            a1_2 = (void *)*(s32 *)(s0 + 0xc8);
            a0_2 = (void *)s4;
            if ((u32)(s32)a1_2 != 0) {
                UpdateWorldMatrixWithAnim(a0_2, a1_2, (void *)s3);
            }
        }
    }
    return;
}


/* DrawModel @ 0x137540 .. 0x13758C (0x4c bytes, frame 0x10) */





void DrawModel(struct dw_78578 *a0 /* r4 */) {
    u8 v1;

    v1 = ((struct dw_41105 *)lpDrawMng)->DrawHitModel;
    if (v1 && (u32)(s32)a0->lpMdlData->lpHmdHead != 0) {
        DrawHmdModel((void *)a0, v1);
    } else {
        DrawVmdModel((void *)a0);
    }
    return;
}
static void DrawVmdModel(void *a0 /* r4 */) {
    u8 *s2;
    u32 a3;
    u32 a2;
    u8 *s1;
    u32 a1;
    unsigned int *s3;
    s32 a0_scalar; // a0
    u64 a0_64;
    u32 v1;
    u8 *s0;
    u8 *s4;
    float f13;
    float f12;
    float f4;
    float f3;
    float f2;
    float f1;
    float f0;
    u32 v0;
    float fp_acc_0;
    u8 *a0_2;
    u8 **lpPointLightMng;
    float Rate;
    float BkCol[4] __attribute__((aligned(16)));

    a1 = *(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5);
    v1 = *(u8 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSE_5A9BB2D0);
    s1 = (u8 *)*(s32 *)(a1 + DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD);
    s2 = (u8 *)a0;
    if (v1 != 0) {
        v1 = *(u8 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E);
        a0_2 = (u8 *)(v1 & 1);
        if ((u32)a0_2 == 0 || *(u8 *)((*(s32 *)(s1 + 0x38) + 9)) != 0) {
            if ((u32)a0_2 == 0 || (u32)((u32)(*(u8 *)(s2 + 0x194)) & 1) != (u32)1) {
                s3 = (unsigned int *)lpMdlPacketMem;
                v1 = 0x10000004;
                v0 = 0x6c040008;
                s3[0] = 0x10000004;
                s3[1] = 0;
                s3[2] = 0;
                s3[3] = 0x6c040008;
                v0 = (u32)lpDrawMng;
                s3 += 4;
                sceVu0CopyMatrix(((ShMat *)s3)++, (void *)(u32)(v0 + 0x370));
                v1 = 0x10000004;
                v0 = 0x6c040004;
                s3[0] = 0x10000004;
                s3[1] = 0;
                s3[2] = 0;
                s3[3] = 0x6c040004;
                v0 = (u32)lpDrawMng;
                s3 += 4;
                sceVu0CopyMatrix(((ShMat *)s3)++, (void *)(u32)(v0 + 0x2b0));
                v0 = 0x6c010000;
                v1 = 0x10000001;
                s3[0] = 0x10000001;
                s3[1] = 0;
                s3[2] = 0;
                s3[3] = 0x6c010000;
                v1 = (u32)lpDrawMng;
                v0 = *(u8 *)(v1 + DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E);
                s3 += 4;
                if ((u32)(v0 & 2) == 0) {
                    sceVu0CopyVector(((ShVec *)s3)++, (u32)(v1 + 0x450));
                } else {
                    sceVu0CopyVector(((ShVec *)s3)++, (u32)(v1 + 0x460));
                }
                a1 = 0x10000000;
                a2 = 0x50000000;
                s3[0] = 0x10000000 | 2;
                a0_2 = (u8 *)0x8001;
                s3[1] = 0;
                v0 = 0x50000000 | 2;
                s3[2] = 0;
                s3[3] = v0;
                s3[4] = 0x8001;
                v0 = 0x3d;
                s3[5] = 0x10000000;
                s3[6] = 0xe;
                s3[7] = 0;
                *(u64 *)(s3 + 8) = (u64)lpDrawMng[0x100] | ((u64)lpDrawMng[0x101] << 8) | ((u64)lpDrawMng[0x102] << 16);
                *(s64 *)(s3 + 10) = (s32)v0;
                v0 = *(s32 *)(*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5) +
                    DCOMP_OFF_STRUCT_DW_109200_FIELDS_TEXINVMD_D18A31BF);
                s3 += 12;
                if (v0 != 0) {
                    v0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPSHIFTTEXPACKET_63ADB478);
                    if (v0 != 0) {
                        s3[0] = a2;
                        v0 = *(s32 *)(s2 +
                            DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPSHIFTTEXPACKET_63ADB478);
                        s3[1] = v0;
                        s3[2] = 0;
                        s3[3] = 0;
                        s3 += 4;
                    } else {
                        s3[0] = a2;
                        v0 = *(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5);
                        a0_2 = s2;
                        v0 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPTEXPACKET_87DF94ED);
                        s3[1] = v0;
                        s3[2] = 0;
                        s3[3] = 0;
                        s3 += 4;
                        v0 = CheckCrackWall((void *)a0_2);
                        a0_2 = (u8 *)s3;
                        if (v0 != 0) {
                            v0 = (u32)MakeCrackWall((unsigned int *)a0_2);
                            s3 = (unsigned int *)v0;
                        }
                    }
                }
                v1 = 0x50000000;
                s3[0] = 0x50000000;
                v0 = *(s32 *)(*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5) +
                    DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPPACKET_D228A198);
                s3[1] = v0;
                s3[2] = 0;
                s3[3] = 0;
                v0 = *(u8 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E);
                v0 = v0 & 2;
                a3 = 0x10000000;
                if (v0 == 0) {
                    a2 = v1 | 3;
                    a1 = 0x8002;
                    s3[4] = a3 | 3;
                    a0_2 = (u8 *)(s32)0xe;
                    s3[5] = 0;
                    s3[6] = 0;
                    v0 = 0x4e;
                    s3[7] = a2;
                    s3[8] = 0x8002;
                    s3[9] = a3;
                    s3[10] = (s32)a0_2;
                    s3[11] = 0;
                    a0_2 = (u8 *)*(s32 *)(s2 + 0x150);
                    *(u64 *)(s3 + 12) = (u32)((u32)a0_2 & 0x7ffff);
                    *(s64 *)(s3 + 14) = (s32)0x47;
                    v1 = *(s32 *)(((s32)((u32)(lpDrawMng)) + 0x70));
                    s3[16] = v1;
                    v1 = *(u8 *)(s2 + 0x153);
                    s3[17] = v1 & 1;
                    *(s64 *)(s3 + 18) = (s32)v0;
                    s3 += 20;
                } else {
                    a2 = 0x10000000;
                    s3[4] = 0x10000000 | 2;
                    a0_2 = (u8 *)0x8001;
                    s3[5] = 0;
                    s3[6] = 0;
                    v0 = 0x47;
                    s3[7] = v1 | 2;
                    s3[8] = 0x8001;
                    s3[9] = 0x10000000;
                    s3[10] = 0xe;
                    s3[11] = 0;
                    v1 = *(s32 *)(s2 + 0x150);
                    *(u64 *)(s3 + 12) = (u32)(v1 & 0x7ffff);
                    *(s64 *)(s3 + 14) = (s32)v0;
                    s3 += 16;
                }
                s0 = (u8 *)(s3 + 4);
                v0 = (u32)SetMatrixPacket((unsigned int *)s3, (void *)s1, (void *)s2);
                s3 = (unsigned int *)v0;
                v0 = *(u8 *)((*(s32 *)(s1 + 0x38) + 7));
                if (v0 == 0) {
                    v0 = *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLLIGHT_7344CC2A);
                    if (v0 == 0) {
                        v1 = *(u16 *)(*(s32 *)(s2 +
                            DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5) +
                            DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0);
                        if (v1 == (u32)7) {
                            s4 = (u8 *)(MdlMng + 0x11800);
                        } else {
                            s4 = s2;
                        }
                        CheckPointLightValid((void *)s4, (void *)0, 0);
                        lpPointLightMng = (u8 **)GetPointLightMng();
                        *(f32 *)(sgLightMat + 8) = *(float *)(*lpPointLightMng + 0x10) - *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44);
                        *(f32 *)(sgLightMat + 9) = *(float *)(*lpPointLightMng + 0x14) - (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713) - 0.5f * *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_HITHIGH_30015B9A));
                        *(f32 *)(sgLightMat + 0xa) = *(float *)(*lpPointLightMng + 0x18) - *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D);
                        Rate = *(float *)(*lpPointLightMng + 4) * *(float *)(*lpPointLightMng + 4) / (*(float *)(sgLightMat + 8) * *(float *)(sgLightMat + 8) + *(float *)(sgLightMat + 9) * *(float *)(sgLightMat + 9) + *(float *)(sgLightMat + 0xa) * *(float *)(sgLightMat + 0xa));
                        Rate = Rate * Rate;
                        if (Rate > 1.0f) {
                            Rate = 1.0f;
                        }
                        *(f32 *)(sgColorMat + 8) = *(float *)(*lpPointLightMng + 0x20) * Rate;
                        *(f32 *)(sgColorMat + 9) = *(float *)(*lpPointLightMng + 0x24) * Rate;
                        *(f32 *)(sgColorMat + 0xa) = *(float *)(*lpPointLightMng + 0x28) * Rate;
                    } else {
                        sceVu0CopyVector((u32)(u8 *)(sgLightMat + 8), (u32)(s32)(s2 + 0x90));
                        sceVu0CopyVector((u32)(u8 *)(sgColorMat + 8), (u32)(s32)(s2 + 0xa0));
                    }
                }
                v0 = *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLAMBIENT_39D34B9F);
                if (v0 != 0) {
                    sceVu0CopyVector(BkCol, sgColorMat + 0xc);
                    sceVu0CopyVector(sgColorMat + 0xc, (u32)(s32)(s2 + 0xb0));
                }
                a1 = *(s32 *)(s1 + 0x38);
                v0 = *(u8 *)((a1 + 6));
                if (v0 != 0) {
                    f13 = *(float *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_ALPHA_40ED5DAB);
                    v0 = (u32)SetDirLightPacket((unsigned int *)s3, *(float *)(s2 +
                        DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0), f13, (void *)a1);
                    s3 = (unsigned int *)v0;
                } else {
                    f12 = *(float *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_ALPHA_40ED5DAB);
                    v0 = (u32)SetAmbientLightPacket((unsigned int *)s3, f12, (void *)a1);
                    s3 = (unsigned int *)v0;
                }
                v1 = *(u8 *)(s2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_BUSEMDLAMBIENT_39D34B9F);
                if (v1 != 0) {
                    sceVu0CopyVector(sgColorMat + 0xc, BkCol);
                }
                s1 = (u8 *)*(s32 *)(s1 + 0x1c);
                if ((u32)(s32)s1 != 0) {
                    do {
                        a0_scalar = *(s16 *)(s1 + 0x32);
                        v1 = -1;
                        if ((u32)a0_scalar != v1) {
                            v1 = *(u8 *)(lpDrawMng +
                                DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E);
                            if ((u32)(v1 & 1) == 0 || *(u8 *)((*(s32 *)(s1 + 0x54) + 0xa)) != 0) {
                                v0 = CheckDrawMyWrist((void *)s2, *(s16 *)(s1 + 0x30));
                                if (v0 != 0) {
                                    v0 = *(u8 *)((*(s32 *)(s1 + 0x54) + 9));
                                    a0_2 = (u8 *)s3;
                                    if (v0 != 0) {
                                        v0 = (u32)DrawVmdMorphObject((u32 *)a0_2, (void *)s1, (void
                                            *)s2, (void *)s0);
                                        s3 = (unsigned int *)v0;
                                    } else {
                                        v0 = (u32)DrawVmdObject((unsigned int *)s3, (void *)s1,
                                            (void *)s2, (void *)s0);
                                        s3 = (unsigned int *)v0;
                                    }
                                }
                            }
                        }
                        v1 = *(s32 *)(s1 + 0x5c);
                        s1 = (u8 *)*(s32 *)((v1 + 0xc));
                    } while ((u32)(s32)s1 != 0);
                }
                v1 = *(u8 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_89591_FIELDS_DRAWFLAG_D8400D5E);
                if ((u32)(v1 & 2) == 0) {
                    v1 = 0x50000000;
                    a3 = 0x10000000;
                    a1 = 0x8001;
                    a0_2 = (u8 *)(s32)0xe;
                    s3[0] = 0x10000000 | 2;
                    s3[1] = 0;
                    s3[2] = 0;
                    s3[3] = 0x50000000 | 2;
                    s3[4] = 0x8001;
                    s3[5] = 0x10000000;
                    s3[6] = (s32)a0_2;
                    s3[7] = 0;
                    a0_2 = lpDrawMng;
                    a0_64 = *(u64 *)(a0_2 + 0x70);
                    *(u64 *)(s3 + 8) = a0_64;
                    *(s64 *)(s3 + 10) = (s32)0x4e;
                    s3 += 12;
                }
                lpMdlPacketMem = (s32)s3;
            }
        }
    }
    return;
}
static unsigned int * DrawVmdObject(unsigned int *s5, void *a1 /* r5 */, void *a2 /* r6
        */, void *a3 /* r7 */) {
    u8 *s4;
    u32 s3;
    u32 s6;
    s32 t0;
    u8 *s2;
    u32 s1;
    u32 s0;
    u32 s7;
    u32 v1;
    unsigned int j;
    unsigned char tsIdx;
    unsigned int MatID;
    u32 v0;
    unsigned int *a0_2;
    void *a1_2;
    void *a2_2;
    void *a3_2;

    s6 = (u32)a3;
    s4 = (u8 *)a1;
    s3 = (u32)a2;
    v1 = *(s32 *)((u8 *)a2 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5);
    s2 = (u8 *)*(s32 *)(v1 + DCOMP_OFF_STRUCT_DW_109200_FIELDS_LPVMDHEAD_4952BAAD);
    v0 = *(s32 *)((u8 *)a1 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381);
    v0 = *(u8 *)(v0 + DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E);
    s1 = 0;
    if (v0 != 0) {
        a0_2 = (unsigned int *)0x50000000;
        v0 = (u32)Vu1ProgMCScissor;
        s5[0] = 0x50000000;
        s5[1] = (u32)Vu1ProgMCScissor;
        s5[2] = 0;
        v0 = 0x3000000;
        s5[3] = 0;
        a1_2 = (void *)(0x3000000 | 0x130);
        v1 = (u32)Vu1ProgMCScissorTriangle;
        s5[4] = 0x50000000;
        s5[5] = (u32)Vu1ProgMCScissorTriangle;
        a2_2 = (void *)0x10000000;
        s5[6] = 0;
        v0 = 0x2000000;
        s5[7] = 0;
        a0_2 = (unsigned int *)(0x2000000 | 0x124);
        s5[8] = 0x10000000;
        s5[9] = 0;
        s5[10] = (u32)a1_2;
        v0 = 0x6c040388;
        s5[11] = (u32)a0_2;
        s5[12] = 0x10000000 | 4;
        s5[13] = 0;
        s5[14] = 0;
        s5[15] = 0x6c040388;
        v0 = (u32)lpDrawMng;
        s5 += 16;
        v0 = (u32)lpDrawMng;
        sceVu0CopyMatrix(((ShMat *)s5)++, (void *)(u32)(v0 + 0x3b0));
    }
    v0 = *(u8 *)((*(s32 *)(s2 + 0x38) + 7));
    a0_2 = (unsigned int *)s3;
    if (v0 != 0) {
        s1 = CheckPointLightValid((void *)a0_2, (void *)s4, 0);
        if (s1 != 0) {
            v0 = *(u16 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPMATRIXID_BA7D1AAA);
            a2_2 = (void *)(s32)(s6 + (u32)(v0 << 6));
            v0 = (u32)SetPointLightPacket(s5, (void *)s2, (u32)a2_2);
            v1 = *(s32 *)(s2 + 0x38);
            s5 = (unsigned int *)v0;
            v1 = *(u8 *)((v1 + 7));
            if (v1 == (u32)2) {
                v1 = 0x50000000;
                v0 = (u32)Vu1ProgMCClipJointAmbiPLight;
                s5[0] = 0x50000000;
                s5[1] = (u32)Vu1ProgMCClipJointAmbiPLight;
                s5[2] = 0;
                s5[3] = 0;
                s5 += 4;
            }
        }
    }
    v0 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
        DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
    if (v0 != 0) {
        v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
        a0_2 = (unsigned int *)Vu1ProgMCClipAmbi;
        s7 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
        s0 = 0;
        v0 = (u16)GetMicroCodeMPG(Vu1ProgMCClipAmbi);
        if (s7 == v0) {
            if (s1 != 0) {
                v0 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
                    DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
                if ((s32)v0 >= (s32)0xc8) {
                    s0 = (u32)Vu1ProgMCEnvClipAmbiPLight;
                } else {
                    s0 = (u32)Vu1ProgMCScrollClipAmbiPLight;
                }
            } else {
                v0 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
                    DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
                if ((s32)v0 >= (s32)0xc8) {
                    s0 = (u32)Vu1ProgMCEnvClipAmbi;
                } else {
                    s0 = (u32)Vu1ProgMCScrollClipAmbi;
                }
            }
        } else {
            v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
            s7 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
            a0_2 = (unsigned int *)Vu1ProgMCJointLight;
            v0 = (u16)GetMicroCodeMPG(Vu1ProgMCJointLight);
            if (s7 == v0) {
                s0 = (u32)Vu1ProgMCScrollJointLight;
            } else {
                v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
                s7 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
                a0_2 = (unsigned int *)Vu1ProgMCClipJointLight;
                if (s7 == (u32)(u16)GetMicroCodeMPG(Vu1ProgMCClipJointLight)) {
                    s0 = (u32)Vu1ProgMCScrollClipJointLight;
                }
            }
        }
        v1 = 0x50000000;
        if (s0 != 0) {
            v0 = 0x64;
            s5[0] = v1;
            s5[1] = s0;
            s5[2] = 0;
            s5[3] = 0;
            v1 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381);
            tsIdx = *(u8 *)(v1 + DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
            if ((u32)tsIdx != v0) {
                a0_2 = s5 + 4;
                v0 = (u32)SetTexScrollPacket(a0_2, tsIdx, *(float *)(s2 + 0x20));
                s5 = (unsigned int *)v0;
            } else {
                a0_2 = s5 + 4;
                v0 = (u32)SetTexScrollSfxPacket(a0_2, (void *)s3);
                s5 = (unsigned int *)v0;
            }
            v1 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381);
            v0 = 5;
            v1 = *(u8 *)(v1 + DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
            a2_2 = (void *)0x10000000;
            if (v1 == v0) {
                v0 = 0x50000002;
                s5[0] = (u32)((u32)(a2_2)) | 2;
                a1_2 = (void *)0x8001;
                s5[1] = 0;
                a0_2 = (unsigned int *)(s32)0xe;
                s5[2] = 0;
                s5[3] = 0x50000002;
                s5[4] = 0x8001;
                v0 = 8;
                s5[5] = (s32)a2_2;
                s5[6] = (s32)a0_2;
                s5[7] = 0;
                *(s64 *)(s5 + 8) = (s32)4;
                *(s64 *)(s5 + 10) = (s32)v0;
                s5 += 12;
            }
        }
    }
    j = 0;
    s5[0] = 0x10000000 | 1;
    s5[1] = 0;
    s5[2] = 0;
    s5[3] = 0x6c01001c;
    s5[4] = *(s16 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_MATRIXNUM_0655EEDB);
    s5[5] = 0;
    s5[6] = 0;
    s5[7] = 0;
    s5 += 8;
    for (j = 0; j < *(s16 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_MATRIXNUM_0655EEDB); j++) {
        MatID = ((u16 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPMATRIXID_BA7D1AAA))[j];
        s5[0] = 0x30000004;
        s5[1] = (u32)s6 + (MatID << 6);
        s5[2] = 0;
        s5[3] = 0x6c040000 | (0x20 + j * 4);
        s5 += 4;
    }
    v0 = 0x10000000;
    s5[0] = 0x10000000;
    s5[1] = 0;
    s5[2] = 0;
    v0 = *(u8 *)(lpDrawMng + DCOMP_OFF_STRUCT_DW_89591_FIELDS_PROJECTIONTYPE_95D4B8D1);
    if (v0 == 0) {
        if (s1 != 0 && *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381)
            + DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E) == 0) {
            v1 = *(u8 *)((*(s32 *)(s2 + 0x38) + 7));
            if (v1 == (u32)1) {
                a0_2 = (unsigned int *)Vu1ProgMCClipAmbiPLight;
                v1 = (u16)GetMicroCodeMPG(Vu1ProgMCClipAmbiPLight);
                v0 = 0x15000000;
                s5[3] = v1 | 0x15000000;
                s5 += 4;
            } else {
                a0_2 = (unsigned int *)Vu1ProgMCClipJointAmbiPLight;
                v1 = (u16)GetMicroCodeMPG(Vu1ProgMCClipJointAmbiPLight);
                v0 = 0x15000000;
                s5[3] = v1 | 0x15000000;
                s5 += 4;
            }
        } else {
            v1 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
            v0 = 0x15000000;
            v1 = *(s32 *)(v1 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
            s5[3] = v1 | 0x15000000;
            s5 += 4;
        }
    } else {
        a0_2 = (unsigned int *)Vu1ProgMCJointLight;
        v1 = (u16)GetMicroCodeMPG(Vu1ProgMCJointLight);
        v0 = 0x15000000;
        s5[3] = v1 | 0x15000000;
        s5 += 4;
    }
    a2_2 = (void *)0x50000000;
    s5[0] = 0x50000000;
    a1_2 = (void *)0x10000000;
    v1 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
    v0 = 0x15000000;
    v1 = *(s32 *)(v1 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_LPMODELPACKET_5E68D23B);
    s5[1] = v1;
    s5[2] = 0;
    s5[3] = 0;
    s5[4] = 0x10000000;
    s5[5] = 0;
    s5[6] = 0;
    s5[7] = 0x15000000;
    v0 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
        DCOMP_OFF_STRUCT_DW_91208_FIELDS_SCISSOR_22C29C4E);
    s5 += 8;
    if (v0 != 0) {
        s5[0] = (s32)a2_2;
        v0 = (u32)Vu1ProgMCBase;
        s5[1] = (u32)Vu1ProgMCBase;
        a0_2 = (unsigned int *)Vu1ProgMCMulti;
        s5[2] = 0;
        v0 = 0x3000000;
        s5[3] = 0;
        s5[4] = (s32)a2_2;
        s5[5] = (u32)Vu1ProgMCMulti;
        v0 = 0x2000168;
        s5[6] = 0;
        s5[7] = 0;
        s5[8] = (s32)a1_2;
        s5[9] = 0;
        s5[10] = 0x3000000 | 0x130;
        s5[11] = 0x2000168;
        s5 += 12;
    }
    v0 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
        DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
    if (v0 != 0) {
        v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
        a0_2 = (unsigned int *)Vu1ProgMCClipAmbi;
        s3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
        s0 = 0;
        v0 = (u16)GetMicroCodeMPG(Vu1ProgMCClipAmbi);
        if (s3 == v0) {
            if (s1 != 0) {
                s0 = (u32)Vu1ProgMCClipAmbiPLight;
            } else {
                s0 = (u32)Vu1ProgMCClipAmbi;
            }
        } else {
            v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
            s3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
            a0_2 = (unsigned int *)Vu1ProgMCJointLight;
            v0 = (u16)GetMicroCodeMPG(Vu1ProgMCJointLight);
            if (s3 == v0) {
                s0 = (u32)Vu1ProgMCJointLight;
            } else {
                v0 = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJRESERVE_72C4B29A);
                s3 = *(s32 *)(v0 + DCOMP_OFF_STRUCT_DW_92793_FIELDS_MICROCODEADDR_FD837344);
                a0_2 = (unsigned int *)Vu1ProgMCClipJointLight;
                if (s3 == (u32)(u16)GetMicroCodeMPG(Vu1ProgMCClipJointLight)) {
                    s0 = (u32)Vu1ProgMCClipJointLight;
                }
            }
        }
        a0_2 = (unsigned int *)0x50000000;
        if (s0 != 0) {
            v0 = 5;
            s5[0] = (s32)a0_2;
            s5[1] = s0;
            s5[2] = 0;
            s5[3] = 0;
            v1 = *(u8 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_82520_FIELDS_LPOBJPARAM_5C3B5381) +
                DCOMP_OFF_STRUCT_DW_91208_FIELDS_TEXSCROLL_A4AABECF);
            s5 += 4;
            if (v1 == v0) {
                a2_2 = (void *)0x10000000;
                a1_2 = (void *)((u32)((u32)(a0_2)) | 2);
                a0_2 = (unsigned int *)0x8001;
                s5[0] = 0x10000000 | 2;
                s5[1] = 0;
                v0 = 8;
                s5[2] = 0;
                s5[3] = (u32)a1_2;
                s5[4] = 0x8001;
                s5[5] = 0x10000000;
                s5[6] = 0xe;
                s5[7] = 0;
                *(u64 *)(s5 + 8) = 0;
                *(s64 *)(s5 + 10) = (s32)v0;
                s5 += 12;
            }
        }
    }
    if (s1 != 0 && (u32)*(u8 *)((*(s32 *)(s2 + 0x38) + 7)) == (u32)2) {
        a0_2 = (unsigned int *)0x50000000;
        v1 = (u32)Vu1ProgMCShadowMake;
        s5[0] = (s32)a0_2;
        s5[1] = (u32)Vu1ProgMCShadowMake;
        s5[2] = 0;
        v0 = (u32)Vu1ProgMCShadowDraw;
        s5[3] = 0;
        s5[4] = (s32)a0_2;
        s5[5] = (u32)Vu1ProgMCShadowDraw;
        s5[6] = 0;
        s5[7] = 0;
        s5 += 8;
    }
    return s5;
}
static u32 *DrawVmdMorphObject(u32 *packet,void *object,void *model,void *matrices) {
    u32 *cursor;
    u8 *saved;
    u8 *data;
    s32 header=0x10000000;
    s32 countTag=header|1;
    s32 unpack=0x6c010000;
    void *program=Vu1ProgMCMorphClipJointLight;
    s32 strow;
    s32 cycle;
    strow=0x030000f0;
    data=*(u8 **)((u8 *)model+0xc);
    cycle=0x02000188;
    saved=object;
    packet[0]=0x50000000;
    packet[1]=(u32)program;
    packet[2]=0;packet[3]=0;
    packet[4]=header;packet[5]=0;
    cursor=packet;
    cursor+=24;
    packet[6]=strow;packet[7]=cycle;
    model=(void *)(unpack|0x3fe);
    packet[8]=countTag;packet[9]=0;packet[10]=0;packet[11]=(u32)model;
    *(float *)(packet+12)=*(float *)(data+0x6c);
    *(float *)(packet+13)=*(float *)(data+0x70);
    *(float *)(packet+14)=*(float *)(data+0x74);
    packet[15]=0;
    packet[16]=countTag;packet[17]=0;packet[18]=0;packet[19]=unpack|0x1c;
    packet[20]=*(s16 *)(saved+0x3a);packet[21]=0;packet[22]=0;packet[23]=0;
    {
        u32 i;
        i=0;
        if((u8 *)0<(u8 *)(s32)*(s16 *)(saved+0x3a)) {
        u32 offset=0;
        u32 address=32;
        do {
            u32 joint=*(u16 *)(*(u32 *)(saved+0x3c)+offset);
            cursor[0]=0x30000004;
            cursor[1]=(u32)matrices+(joint<<6);
            cursor[2]=0;cursor[3]=0x6c040000|address;
            address+=4;offset+=2;++i;cursor+=4;
        } while(i<(u32)*(s16 *)(saved+0x3a));
        }
    }
    cursor[0]=0x10000000;cursor[1]=0;cursor[2]=0;
    cursor[3]=GetMicroCodeMPG(Vu1ProgMCMorphClipJointLight)|0x15000000;
    cursor[4]=0x50000000;
    cursor[5]=*(u32 *)(*(u32 *)(saved+0x5c)+0x10);
    cursor[6]=0;cursor[7]=0;
    cursor[8]=0x10000000;cursor[9]=0;cursor[10]=0;cursor[11]=0x15000000;
    cursor[12]=0x50000000;cursor[13]=(u32)Vu1ProgMCClipJointLight;cursor[14]=0;cursor[15]=0;
    cursor[16]=0x10000000;cursor[17]=0;cursor[18]=0x03000130;cursor[19]=0x02000168;
    return cursor+20;
}

/* SetCameraPacket @ 0x1365D0 .. 0x136664 (0x94 bytes, frame 0x20) */


unsigned int * SetCameraPacket(unsigned int *lpCurDMA) {
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c040008;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, (u8 *)lpDrawMng + 0x370);
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c040004;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, (u8 *)lpDrawMng + 0x2b0);
    return lpCurDMA;
}

unsigned int * SetDirLightPacket(unsigned int *lpCurDMA, float ModelScale, float ModelAlpha, void *lpParam) {
    float LightMat[4][4] __attribute__((aligned(16)));
    float LightScale = 1.0f / ModelScale;
    float SpecHalfVec[4] __attribute__((aligned(16)));
    float ViewVec[4] = {0.0f, 0.0f, -1.0f, 0.0f};
    unsigned char *lpVmdHeadParam = (unsigned char *)lpParam;

    sceVu0Normalize(LightMat[0], sgLightMat);
    sceVu0Normalize(LightMat[1], sgLightMat + 4);
    sceVu0Normalize(LightMat[2], sgLightMat + 8);
    if (lpVmdHeadParam != 0 && lpVmdHeadParam[0xb] != 0) {
        float wkfm[4][4] __attribute__((aligned(16)));

        sceVu0UnitMatrix(wkfm);
        sceVu0RotMatrixY(wkfm, wkfm, ((struct dw_89591_fields *)lpDrawMng)->camAng[1]);
        sceVu0RotMatrixZ(wkfm, wkfm, ((struct dw_89591_fields *)lpDrawMng)->camAng[2]);
        sceVu0RotMatrixX(wkfm, wkfm, ((struct dw_89591_fields *)lpDrawMng)->camAng[0]);
        sceVu0ApplyMatrix(ViewVec, wkfm, ViewVec);
        sceVu0InterVector(SpecHalfVec, ViewVec, LightMat[0], 0.5f);
        sceVu0Normalize(LightMat[3], SpecHalfVec);
    }
    fsvu0_ScaleVector(LightMat[0], LightMat[0], LightScale);
    fsvu0_ScaleVector(LightMat[1], (float *)((u8 *)LightMat + 0x10), LightScale);
    fsvu0_ScaleVector(LightMat[2], (float *)((u8 *)LightMat + 0x20), LightScale);
    fsvu0_ScaleVector(LightMat[3], LightMat[3], LightScale);
    sceVu0TransposeMatrix(LightMat, LightMat);
    ((float *)sgColorMat)[15] = ModelAlpha;
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c040010;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, sgColorMat);
    if (lpVmdHeadParam != 0) {
        u32 idx = lpVmdHeadParam[0xa];

        if (idx != 0) {
            sceVu0CopyVectorXYZ(lpCurDMA - 4, (void *)(lpDebugParam + ((u8)idx << 4) + 0x5b0));
        }
    }
    lpCurDMA[0] = 0x10000004;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c04000c;
    lpCurDMA += 4;
    sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, LightMat);
    return lpCurDMA;
}

unsigned int * SetAmbientLightPacket(unsigned int *lpCurDMA, float ModelAlpha, void *lpParam) {
    struct dw_84552_fields *lpVmdHeadParam;
    float (*lpAmbientDMA)[4];
    float (*lpAmbientEnd)[4];
    u32 id;

    lpVmdHeadParam = (struct dw_84552_fields *)lpParam;
    *(f32 *)(sgColorMat + 0xf) = ModelAlpha;
    lpCurDMA[0] = 0x10000001;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x6c010013;
    lpCurDMA += 4;
    sceVu0CopyVector(((ShVec *)lpCurDMA)++, sgColorMat + 0xc);
    if (lpVmdHeadParam != 0) {
        id = lpVmdHeadParam->AmbientID;
        if (id != 0) {
            sceVu0CopyVectorXYZ((u32 *)(lpCurDMA - 4), (void *)(lpDebugParam + (u8)id * 16 + 0x5b0));
        }
    }
    lpAmbientEnd = (float (*)[4])lpCurDMA;
    lpAmbientEnd[-1][0] = lpAmbientEnd[-1][0] * 1.5f;
    lpAmbientEnd[-1][1] = lpAmbientEnd[-1][1] * 1.5f;
    lpAmbientEnd[-1][2] = lpAmbientEnd[-1][2] * 1.5f;
    lpAmbientDMA = lpAmbientEnd - 1;
    if (!((*lpAmbientDMA)[0] <= 2.0f)) {
        (*lpAmbientDMA)[0] = 2.0f;
    }
    if (!((*lpAmbientDMA)[1] <= 2.0f)) {
        (*lpAmbientDMA)[1] = 2.0f;
    }
    if (!((*lpAmbientDMA)[2] <= 2.0f)) {
        (*lpAmbientDMA)[2] = 2.0f;
    }
    lpAmbientEnd[-1][0] = lpAmbientEnd[-1][0] * *(float *)(GameSt + 0x24);
    lpAmbientEnd[-1][1] = lpAmbientEnd[-1][1] * *(float *)(GameSt + 0x24);
    lpAmbientEnd[-1][2] = lpAmbientEnd[-1][2] * *(float *)(GameSt + 0x24);
    return lpCurDMA;
}
static unsigned int * SetPointLightPacket(s1, s0, s2)
    u32 *s1;
    u8 *s0;
    u32 s2; {
    u8 *s5;
    u8 *s4;
    u8 *s3;
    u32 v1;
    u32 v0;
    float f12;
    unsigned int *a0_2;
    void *a1_2;
    float InvObjMat[4][4] __attribute__((aligned(16)));
    float LightMat[4][4] __attribute__((aligned(16)));

    v0 = GetPointLightMng();
    v1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_LPHEADPARAM_7B3D1659);
    s5 = (u8 *)v0;
    v0 = 1;
    v1 = *(u8 *)(v1 + DCOMP_OFF_STRUCT_DW_84552_FIELDS_POINTLIGHT_2299B3F7);
    a1_2 = (void *)s2;
    if (v1 == v0) {
        sceVu0InversMatrix((void *)(u32 *)((u8 *)&InvObjMat[0]), a1_2);
        v0 = *(s32 *)s5;
        sceVu0ApplyMatrix((void *)(u32 *)((u8 *)&LightMat[0]), (void *)((u8 *)&InvObjMat[0]), (void
            *)(u32)(v0 + 0x10));
        v0 = *(s32 *)(s5 + 4);
        s4 = ((u8 *)&LightMat[0] + 0x10);
        sceVu0ApplyMatrix((void *)(u32 *)((u8 *)&LightMat[0] + 0x10), (void *)((u8
            *)&InvObjMat[0]), (void *)(u32)(v0 + 0x10));
        v0 = *(s32 *)(s5 + 8);
        s3 = ((u8 *)&LightMat[0] + 0x20);
        sceVu0ApplyMatrix((void *)(u32 *)((u8 *)&LightMat[0] + 0x20), (void *)((u8
            *)&InvObjMat[0]), (void *)(u32)(v0 + 0x10));
        v0 = *(s32 *)(s5 + 0xc);
        s2 = (u32)((u8 *)&LightMat[0] + 0x30);
        sceVu0ApplyMatrix((void *)(u32 *)((u8 *)&LightMat[0] + 0x30), (void *)((u8
            *)&InvObjMat[0]), (void *)(u32)(v0 + 0x10));
        v0 = *(s32 *)s5;
        LightMat[0][3] = *(float *)((v0 + 4));
        v0 = *(s32 *)(s5 + 4);
        LightMat[1][3] = *(float *)((v0 + 4));
        v0 = *(s32 *)(s5 + 8);
        LightMat[2][3] = *(float *)((v0 + 4));
        v0 = *(s32 *)(s5 + 0xc);
        LightMat[3][3] = *(float *)((v0 + 4));
        f12 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8);
        sceVu0ScaleVector((void *)((u8 *)&LightMat[0]), (void *)((u8 *)&LightMat[0]), f12);
        f12 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8);
        sceVu0ScaleVector((void *)(u32 *)((u8 *)&LightMat[0] + 0x10), (void *)((u8 *)&LightMat[0] +
            0x10), f12);
        f12 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8);
        sceVu0ScaleVector((void *)(u32 *)((u8 *)&LightMat[0] + 0x20), (void *)((u8 *)&LightMat[0] +
            0x20), f12);
        f12 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_GEOMSCALE_C9DF98C8);
        sceVu0ScaleVector((void *)(u32 *)((u8 *)&LightMat[0] + 0x30), (void *)((u8 *)&LightMat[0] +
            0x30), f12);
    } else {
        v0 = *(s32 *)s5;
        sceVu0CopyVector((u32 *)((u8 *)&LightMat[0]), (u32)(v0 + 0x10));
        v0 = *(s32 *)s5;
        LightMat[0][3] = *(float *)((v0 + 4));
    }
    sceVu0TransposeMatrix((void *)(u32 *)((u8 *)&LightMat[0]), (void *)((u8 *)&LightMat[0]));
    v1 = 0x10000004;
    v0 = 0x6c040014;
    *(u32 *)s1 = 0x10000004;
    s1[1] = 0;
    s1[2] = 0;
    s1[3] = 0x6c040014;
    s1 += 4;
    sceVu0CopyMatrix(((ShMat *)s1)++, (void *)((u8 *)&LightMat[0]));
    v1 = *(s32 *)(s0 + DCOMP_OFF_STRUCT_DW_81473_FIELDS_LPHEADPARAM_7B3D1659);
    v0 = 1;
    v1 = *(u8 *)(v1 + DCOMP_OFF_STRUCT_DW_84552_FIELDS_POINTLIGHT_2299B3F7);
    if (v1 == v0) {
        v1 = 0x10000000;
        v0 = 0x6c040000;
        *(u32 *)s1 = (u32)(u32 *)(0x10000000 | 4);
        s1[1] = 0;
        s1[2] = 0;
        s1[3] = 0x6c040000 | 0x18;
        v0 = *(s32 *)s5;
        s1 += 4;
        sceVu0ScaleVector(((ShVec *)s1)++, (void *)(u32)(v0 + 0x20), 4.0f);
        v1 = *(s32 *)(s5 + 4);
        sceVu0ScaleVector(((ShVec *)s1)++, (void *)(u32)(v1 + 0x20), 4.0f);
        v1 = *(s32 *)(s5 + 8);
        sceVu0ScaleVector(((ShVec *)s1)++, (void *)(u32)(v1 + 0x20), 4.0f);
        v1 = *(s32 *)(s5 + 0xc);
        sceVu0ScaleVector(((ShVec *)s1)++, (void *)(u32)(v1 + 0x20), 4.0f);
    } else {
        v0 = 0x10000000;
        *(u32 *)s1 = 0x10000000 | 1;
        s1[1] = 0;
        v0 = 0x6c010018;
        s1[2] = 0;
        s1[3] = 0x6c010018;
        v0 = *(s32 *)s5;
        s1 += 4;
        sceVu0CopyMatrix(((ShVec *)s1)++, (void *)(u32)(v0 + 0x20));
    }
    return (unsigned int *)s1;
}
unsigned int *SetTexScrollPacket(unsigned int *packet,unsigned char index,float scale) {
    s32 i;
    u8 *out=(u8 *)packet;
    s32 reverse=0;
    float savedScale=scale;
    float factor;
    float *scroll;
    if(index>=200) { reverse=1; index-=200; }
    scroll=(float *)GetTextureScroll(index);
    *(u32 *)out=0x10000001;
    *(u32 *)(out+4)=0;
    *(u32 *)(out+8)=0;
    *(u32 *)(out+12)=0x6c010001;
    if(reverse) {
        factor=1.0f/savedScale;
        *(float *)(out+16)=factor/scroll[9];
        *(float *)(out+20)=factor/scroll[8];
        *(u32 *)(out+24)=0;
        *(u32 *)(out+28)=0;
        out+=32;
    } else {
        *(float *)(out+16)=scroll[0];
        *(float *)(out+20)=scroll[1];
        *(u32 *)(out+24)=0;
        *(u32 *)(out+28)=0;
        out+=32;
    }
    *(u32 *)out=0x10000001;
    *(u32 *)(out+4)=0;
    *(u32 *)(out+8)=0;
    *(u32 *)(out+12)=0x6c010002;
    factor=64.0f/savedScale;
    *(float *)(out+16)=factor*scroll[8];
    *(float *)(out+20)=64.0f*scroll[4];
    *(float *)(out+24)=factor*scroll[9];
    *(float *)(out+28)=64.0f*scroll[5];
    *(u32 *)(out+32)=0x10000040;
    *(u32 *)(out+36)=0;
    *(u32 *)(out+40)=0;
    *(u32 *)(out+44)=0x6c4000f0;
    out+=48;
    for(i=0;i<64;++i) {
        *(float *)out=scroll[7]*((float *)SinTable)[i];
        *(float *)(out+4)=scroll[6]*((float *)SinTable)[i];
        *(u32 *)(out+8)=0;
        *(u32 *)(out+12)=0;
        out+=16;
    }
    return (u32 *)out;
}
static unsigned int *SetTexScrollSfxPacket(unsigned int *packet, void *model) {
    float u;
    float v;
    int i;
    unsigned int *p = packet;
    SfxMdl_GetTexScroll_ByPtr(model, &u, &v);
    p[0] = 0x10000001;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0x6c010001;
    ((float *)p)[4] = u;
    ((float *)p)[5] = v;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0x10000001;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0x6c010002;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0x10000040;
    p[17] = 0;
    p[18] = 0;
    p[19] = 0x6c4000f0;
    p += 20;
    for (i = 0; i < 64; i++) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
    return p;
}

unsigned int * SetMatrixPacket(unsigned int *lpCurDMA, void *lpVmdHeadSt, void *lpMdlMngSt) {
    u32 lpMdlMng = (u32)lpMdlMngSt;
    struct SmpHead *lpVmdHead;
    unsigned int NextAddr;
    unsigned int i;
    struct SmpVmdMat *lpVmdMat;

    lpVmdHead = (struct SmpHead *)lpVmdHeadSt;
    NextAddr = (u32)lpCurDMA + (lpVmdHead->MatrixNum << 6) + 0x10;
    lpCurDMA[0] = 0x20000000;
    lpCurDMA[1] = NextAddr;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0;
    lpCurDMA += 4;
    for (i = 0; i < lpVmdHead->ObjectNum; i++) {
        sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, (void *)(*(u8 **)((u8 *)(lpMdlMng + 0x10)) + (i << 6)));
    }
    for (i = (s16)lpVmdHead->ObjectNum; i < lpVmdHead->MatrixNum; i++) {
        lpVmdMat = lpVmdHead->lpMatrix + i;
        if (lpVmdMat->Flag == 0) {
            struct SmpObj *lpBlendObj;
            float (*lpWorldMat)[4][4];
            struct SmpAnim *lpBlendCtrl;
            float BlendLocalMat[4][4] __attribute__((aligned(16)));
            float BlendWorldMat[4][4] __attribute__((aligned(16)));
            float OriginBlendLocalMat[4][4] __attribute__((aligned(16)));
            float OriginBlendWorldMat[4][4] __attribute__((aligned(16)));
            float OriginBlendWorldMatI[4][4] __attribute__((aligned(16)));
            float BlendMat[4][4] __attribute__((aligned(16)));
            float angleX, angleY, angleZ;

            lpBlendObj = lpVmdHead->lpObject + lpVmdMat->ObjB;
            lpWorldMat = (float (*)[4][4])(*(u8 **)((u8 *)(lpMdlMng + 0x10)) + (lpVmdMat->ObjA << 6));
            lpBlendCtrl = (struct SmpAnim *)(*(u8 **)((u8 *)(lpMdlMng + 0x100))) + lpVmdMat->ObjB;
            {
            float BlendPos[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
            SMP_WRAP(angleX, lpBlendCtrl->Ang[0]);
            sceVu0RotMatrixX(BlendLocalMat, MRX1, lpVmdMat->Rate * angleX);
            SMP_WRAP(angleZ, lpBlendCtrl->Ang[2]);
            sceVu0RotMatrixZ(BlendLocalMat, BlendLocalMat, lpVmdMat->Rate * angleZ);
            SMP_WRAP(angleY, lpBlendCtrl->Ang[1]);
            sceVu0RotMatrixY(BlendLocalMat, BlendLocalMat, lpVmdMat->Rate * angleY);
            BlendPos[0] = (lpBlendObj->Position[0] + lpBlendCtrl->Pos[0]) - lpBlendObj->Position[0] * lpVmdMat->Rate;
            BlendPos[1] = (lpBlendObj->Position[1] + lpBlendCtrl->Pos[1]) - lpBlendObj->Position[1] * lpVmdMat->Rate;
            BlendPos[2] = (lpBlendObj->Position[2] + lpBlendCtrl->Pos[2]) - lpBlendObj->Position[2] * lpVmdMat->Rate;
            sceVu0TransMatrix(BlendLocalMat, BlendLocalMat, BlendPos);
            sceVu0MulMatrix(BlendWorldMat, BlendLocalMat, lpWorldMat);
            sceVu0TransMatrix(OriginBlendLocalMat, MRX1, lpBlendObj);
            sceVu0TransMatrix(OriginBlendWorldMat, OriginBlendLocalMat, lpWorldMat);
            sceVu0InversMatrix(OriginBlendWorldMatI, OriginBlendWorldMat);
            sceVu0MulMatrix(BlendMat, lpWorldMat, OriginBlendWorldMatI);
            sceVu0MulMatrix(BlendMat, BlendMat, BlendWorldMat);
            sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, BlendMat);
            }
        } else {
            struct SmpAnim *lpAnimCtrl;
            float (*lpBlendMat)[4][4];
            struct SmpObj *lpVmdObj;
            float BlendLocalMat[4][4] __attribute__((aligned(16)));
            float BlendMat[4][4] __attribute__((aligned(16)));
            float angleX, angleY, angleZ;

            lpAnimCtrl = (struct SmpAnim *)(*(u8 **)((u8 *)(lpMdlMng + 0x100))) + lpVmdMat->ObjA;
            lpBlendMat = (float (*)[4][4])(*(u8 **)((u8 *)(lpMdlMng + 0x10)) + (lpVmdMat->ObjB << 6));
            {
            float BlendPos[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
            lpVmdObj = lpVmdHead->lpObject + lpVmdMat->ObjA;
            SMP_WRAP(angleX, lpAnimCtrl->Ang[0]);
            sceVu0RotMatrixX(BlendLocalMat, MRX1, (1.0f - lpVmdMat->Rate) * angleX);
            SMP_WRAP(angleZ, lpAnimCtrl->Ang[2]);
            sceVu0RotMatrixZ(BlendLocalMat, BlendLocalMat, (1.0f - lpVmdMat->Rate) * angleZ);
            SMP_WRAP(angleY, lpAnimCtrl->Ang[1]);
            sceVu0RotMatrixY(BlendLocalMat, BlendLocalMat, (1.0f - lpVmdMat->Rate) * angleY);
            BlendPos[0] = (lpVmdObj->Position[0] + lpAnimCtrl->Pos[0]) - lpVmdObj->Position[0] * lpVmdMat->Rate;
            BlendPos[1] = (lpVmdObj->Position[1] + lpAnimCtrl->Pos[1]) - lpVmdObj->Position[1] * lpVmdMat->Rate;
            BlendPos[2] = (lpVmdObj->Position[2] + lpAnimCtrl->Pos[2]) - lpVmdObj->Position[2] * lpVmdMat->Rate;
            sceVu0TransMatrix(BlendLocalMat, BlendLocalMat, BlendPos);
            sceVu0MulMatrix(BlendMat, BlendLocalMat, lpBlendMat);
            sceVu0CopyMatrix(((ShMat *)lpCurDMA)++, BlendMat);
            }
        }
    }
    return lpCurDMA;
}


/* CheckDrawModel @ 0x135350 .. 0x135520 (0x1d0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1978 -> 0x253020
 *   fpu: float literal 0x00000000 at 0x135374
 *   delay: addiu at 0x1353a0 writes a register its branch at 0x13539c reads
 *   indirect: jr v0 at 0x1353d4 -> <v0>
 *   delay: daddu at 0x135400 writes a register its branch at 0x1353fc reads
 *   delay: daddu at 0x135438 writes a register its branch at 0x135434 reads
 *   delay: daddu at 0x135450 writes a register its branch at 0x13544c reads
 *   delay: daddu at 0x1354c8 writes a register its branch at 0x1354c4 reads
 *   delay: daddu at 0x1354e0 writes a register its branch at 0x1354dc reads
 *   delay: daddu at 0x1354fc writes a register its branch at 0x1354f8 reads
 *   cfg: kept branch: 0x1353f8 if (..) goto .L00135508
 *   cfg: kept branch: 0x135448 if (..) goto .L00135508
 *   cfg: kept branch: 0x135460 if (..) goto .L00135508
 *   cfg: kept branch: 0x1354a8 if (..) goto .L00135508
 *   cfg: kept branch: 0x1354d8 if (..) goto .L00135508
 *   cfg: kept branch: 0x1354f0 if (..) goto .L00135508
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */






unsigned int CheckDrawModel(void *a0 /* r4 */) {
    u8 *s0;
    float f1;
    u32 v1;
    u32 v0;

    v0 = *(u8 *)(((u8 *)a0 + 2));
    s0 = (u8 *)a0;
    if (v0 != 0) {
        v0 = 0;
    } else {
        f1 = *(float *)(s0 + 0x10c);
        if (0.0f == f1) {
            v0 = 0;
        } else {
            v1 = GameSt[5];
            v0 = 4;
            if (v1 == v0) {
                v0 = 1;
            } else {
                v0 = *(u16 *)((*(s32 *)(s0 + 0xc) + 0xa));
                switch (v0) {
                case 1:
                    a0 = (void *)(s0 + 0x20);
                    v0 = CheckBackOfCamera((float *)a0);
                    if (v0 != 0) {
                        v0 = 0;
                        break;
                    } else {
                        v0 = *(u8 *)(s0 + 3);
                        if (v0 == 0) {
                            goto _L00135508;
                        }
                        v0 = 0;
                        break;
                    }
                case 2:
                    a0 = (void *)(s0 + 0x20);
                    v0 = CheckBackOfCamera((float *)a0);
                    if (v0 != 0) {
                        v0 = 0;
                        break;
                    } else {
                        v1 = *(u8 *)(s0 + 0x190);
                        v0 = GameSt[9];
                        if (v1 != v0) {
                            v0 = 0;
                            break;
                        } else {
                            v0 = *(u8 *)(s0 + 3);
                            if (v0 == 0) {
                                goto _L00135508;
                            }
                            v0 = 0;
                            break;
                        }
                    }
                case 3:
                    v0 = (u32)MdlMng;
                    a0 = (void *)(s0 - (u32)(MdlMng));
                    a0 = (void *)(s32)((s32)a0 / 0x1c0);
                    v0 = CheckDrawMapByCamParam((signed int)a0);
                    if (v0 != 0) {
                        goto _L00135508;
                    }
                    v0 = 0;
                    break;
                case 6:
                    v0 = *(u8 *)((lpDrawMng + 0x42c));
                    v0 = v0 & 1;
                    if (v0 == 0 || (u32)((u32)(*(u8 *)(s0 + 0x194)) & 1) == 0) {
                        goto _L00135508;
                    }
                    v0 = 0;
                    break;
                case 4:
                case 10:
                    v0 = *(u8 *)(s0 + 3);
                    if (v0 == 0) {
                        goto _L00135508;
                    }
                    v0 = 0;
                    break;
                case 7:
                    v0 = MdlMng[0x11802];
                    if (v0 == 0) {
                        goto _L00135508;
                    }
                    v0 = 0;
                    break;
                case 0:
                case 5:
                case 8:
                case 9:
                default:
                    _L00135508:;
                    v0 = 1;
                }
            }
        }
    }
    return v0;
}


/* SetAmbientColor @ 0x135340 .. 0x135350 (0x10 bytes) */
/*
 * dcomp notes:
 *   tail: j sceVu0CopyVector at 0x135348 leaves the function
 *   return value dropped, call kept: the function is void
 */











void SetAmbientColor(u8 *a0 /* r4 */) {
    u32 a1;

    a1 = (u32)a0;
    a0 = (u8 *)sgColorMat + 0x30;
    sceVu0CopyVector(a0, a1);
    return;
}


/* GetAmbientColor @ 0x135330 .. 0x13533C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j sceVu0CopyVector at 0x135334 leaves the function
 *   a0 forwarded to sceVu0CopyVector
 *   return value dropped, call kept: the function is void
 */










void GetAmbientColor(u8 *a0 /* r4 */) {
    sceVu0CopyVector(a0, (u8 *)((u8 *)sgColorMat + 0x30));
    return;
}




signed int CheckPointInBoundBox(float *a0, void *a1) {
    float *s1;
    u8 *s0;
    float f1;
    u8 *t3;
    u8 *t2;
    u8 *t1;
    s32 t0;
    u8 *a3;
    float f0;
    u32 v1;
    u32 v0;
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    struct __copy_u_long128_1 { u_long128 b[1]; };

    t2 = (u8 *)*(s32 *)(((u8 *)a1 + 0xc));
    s1 = a0;
    v1 = (u32)((u8 *)&stackFrame_70[0]);
    s0 = (u8 *)a1;
    t3 = (u8 *)*(s32 *)(t2 + 0x10);
    t2 = (u8 *)*(s32 *)(t3 + 0x30);
    f1 = 1.0f / *(float *)(t3 + 0x20);
    {
        struct stackFrame_40 { f32 b[4]; } stackFrame_40 __attribute__((aligned(16))) = {{0.0f,0.0f,0.0f,1.0f}};
        t1 = ((u8 *)&stackFrame_40);
        t0 = *(s16 *)(t2 + 8);
        *(f32 *)((u8 *)&stackFrame_40) = ((float)((float)(s32)(u32)t0) * f1);
        t0 = *(s16 *)(t2 + 0xa);
        *(f32 *)((u8 *)&stackFrame_40 + 0x4) = ((float)((float)(s32)(u32)t0) * f1);
        t0 = *(s16 *)(t2 + 0xc);
        *(f32 *)((u8 *)&stackFrame_40 + 0x8) = ((float)((float)(s32)(u32)t0) * f1);
        *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_80[0]) = *(struct __copy_u_long128_1
            *)((u8 *)&stackFrame_40);
        {
            struct stackFrame_30 { f32 b[4]; } stackFrame_30 __attribute__((aligned(16))) = {{0.0f,0.0f,0.0f,1.0f}};
            a3 = ((u8 *)&stackFrame_30);
            v0 = *(s16 *)(t2 + 0xe);
            *(f32 *)((u8 *)&stackFrame_30) = ((float)((float)(s32)v0) * f1);
            v0 = *(s16 *)(t2 + 0x10);
            *(f32 *)((u8 *)&stackFrame_30 + 0x4) = ((float)((float)(s32)v0) * f1);
            v0 = *(s16 *)(t2 + 0x12);
            *(f32 *)((u8 *)&stackFrame_30 + 0x8) = ((float)((float)(s32)v0) * f1);
            *(struct __copy_u_long128_1 *)((u8 *)&stackFrame_70[0]) = *(struct __copy_u_long128_1
                *)((u8 *)&stackFrame_30);
            a1 = (void *)*(s32 *)(((u8 *)a1 + 0x10));
            sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_60[0]), a1, (void *)((u8
                *)&stackFrame_80[0]));
            a1 = (void *)*(s32 *)(s0 + 0x10);
            sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_50[0]), a1, (void *)((u8
                *)&stackFrame_70[0]));
            *(f32 *)((u8 *)&stackFrame_60[0]) = (*(float *)((u8 *)&stackFrame_60[0]) - 0.01f);
            *(float *)((u8 *)&stackFrame_60[4]) -= 0.01f;
            *(float *)((u8 *)&stackFrame_60[8]) -= 0.01f;
            *(f32 *)((u8 *)&stackFrame_50[0]) = (*(float *)((u8 *)&stackFrame_50[0]) + 0.01f);
            *(float *)((u8 *)&stackFrame_50[4]) += 0.01f;
            *(float *)((u8 *)&stackFrame_50[8]) += 0.01f;
            f1 = *(float *)s1;
            f0 = *(float *)((u8 *)&stackFrame_60[0]);
            if (!(f0 < f1)) goto _L00135308;
                f0 = *(float *)((u8 *)&stackFrame_50[0]);
                if (!(f1 < f0)) {
                    goto _L00135308;
                }
                f0 = *(float *)((u8 *)&stackFrame_60[4]);
                f1 = s1[1];
                if (!(f0 < f1)) {
                    goto _L00135308;
                }
                f0 = *(float *)((u8 *)&stackFrame_50[4]);
                if (!(f1 < f0)) {
                    goto _L00135308;
                }
                f1 = s1[2];
                f0 = *(float *)((u8 *)&stackFrame_60[8]);
                if (!(f0 < f1)) {
                    goto _L00135308;
                }
                f0 = *(float *)((u8 *)&stackFrame_50[8]);
                if (!(f1 < f0)) {
                    goto _L00135308;
                }
                v0 = 1;
                goto done;
                _L00135308:;
                v0 = 0;
            done:;
            return v0;
        }
    }
}
void MakePresetMdlMatrix(void *a0 /* r4 */) {
    u8 *s4;
    u32 v1;
    u32 mdl;
    u32 cnt;
    s32 s3;
    u8 *s2;
    u8 *s1;
    s32 s0;
    u32 v0;
    void *a0_2;
    float sinX, cosX, angleZ, angleX, angleY;
    float sinZ, cosZ, sinY;
    float f12, f4, f3, f2, f1, f0;
    float fp_acc_load_5;
    float lw_mat[4][4] __attribute__((aligned(16)));

    s4 = (u8 *)a0;
    if (*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMI3HEAD_E8C8709F) == 0) {
        {
            float shifted;
            float angle;
        angle = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_0__A3C72D09);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleX = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleX = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_1__108395AF);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleY = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleY = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        {
            float shifted;
            float angle;
        angle = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_ANG_2__81D69CC9);
        shifted = (3.1415927f + angle);
        if (shifted >= 0.0f) {
            angleZ = (angle - (6.2831855f * (float)((float)(s32)(shifted / 6.2831855f))));
        } else {
            f1 = 6.2831855f;
            angleZ = (f1 + (angle - (f1 * (float)((float)(s32)(shifted / f1)))));
        }
        }
        sinX = sinf(angleX);
        cosX = cosf(angleX);
        sinZ = sinf(angleZ);
        cosZ = cosf(angleZ);
        sinY = sinf(angleY);
        f0 = cosf(angleY);
        f3 = (f0 * sinZ);
        lw_mat[0][0] = (cosZ * (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0) * f0));
        f2 = (sinY * sinZ);
        lw_mat[0][1] = (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0) * sinZ);
        f4 = ((float)(f0 * sinX) + (cosX * f2));
        f1 = ((f0 * cosX) - (sinX * f2));
        lw_mat[0][2] = (cosZ * (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_0__AC3107A0) * (-sinY)));
        ((u32 *)lw_mat)[3] = 0;
        lw_mat[1][0] = (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7) * ((sinY * sinX) - (cosX * f3)));
        lw_mat[1][1] = (cosX * (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7) * cosZ));
        lw_mat[1][2] = (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_1__8B11CDF7) * f4);
        ((u32 *)lw_mat)[7] = 0;
        fp_acc_load_5 = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0);
        lw_mat[2][0] = (fp_acc_load_5 * (float)((float)(sinY * cosX) + (sinX * f3)));
        lw_mat[2][1] = (sinX * (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0) * (-cosZ)));
        lw_mat[2][2] = (*(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_SCL_2__2D28B8D0) * f1);
        ((u32 *)lw_mat)[11] = 0;
        lw_mat[3][0] = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_0__A6FD9D44);
        lw_mat[3][1] = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_1__8CC0E713);
        lw_mat[3][2] = *(float *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_POS_2__2052E15D);
        ((u32 *)lw_mat)[15] = 0x3f800000;
        mdl = *(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5);
        s2 = ((struct MdlDataX *)mdl)->lpVmdHead;
        cnt = ((struct VmdX *)s2)->cnt;
        s1 = (u8 *)*(s32 *)(s2 + 0x1c);
        s3 = 0;
        if ((u8 *)0 < (u8 *)cnt) {
            s0 = 0;
            do {
                v0 = *(s16 *)(s1 + 0x34);
                if ((s32)v0 >= 0) {
                    sceVu0MulMatrix((void *)(u32)(s32)((u8 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D) + s0),
                        (void *)(u32)(s32)((u8 *)*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D) + (v0 << 6)),
                        (void *)(s32)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPLOCALMAT_866ABF3A) + s0));
                } else {
                    sceVu0MulMatrix((void *)(u32)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPOBJMAT_4614FB8D) + s0), (void *)((u8 *)&lw_mat[0]),
                        (void *)(s32)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPLOCALMAT_866ABF3A) + s0));
                }
                s3 = s3 + 1;
                s0 = s0 + 0x40;
                s1 = (u8 *)(s1 + 0x60);
            } while ((u32)s3 < (u32)*(s16 *)(s2 + 0x10));
        }
        a0_2 = (void *)*(u16 *)(*(s32 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_LPMDLDATA_9A28BBC5)
            + DCOMP_OFF_STRUCT_DW_109200_FIELDS_MDLTYPE_46876BE0);
        if ((u32)a0_2 != (u32)7) {
            *(u8 *)(s4 + DCOMP_OFF_STRUCT_DW_78578_FIELDS_BPRESETMATRIX_2C185325) = 1;
        }
    }
    return;
}


/* CheckDramaDrawModel @ 0x134D00 .. 0x134D78 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1650 -> 0x253000
 *   indirect: jr v0 at 0x134d50 -> <v0>
 *   declaration vs inferred signature: return signed int vs inferred u32
 */











signed int CheckDramaDrawModel(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;

    s0 = (u8 *)a0;
    v0 = GetDramaFreeFlag();
    if (v0 != 0) {
        v0 = 0;
    } else {
        v0 = *(u16 *)((*(s32 *)(s0 + 0xc) + 0xa));
        v0 = ({ s32 native_result_0; __asm__ volatile("addi %0,%1,-3" : "=r"(native_result_0) :
            "r"((s32)v0) : "memory"); native_result_0; });
        switch (v0) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
            v0 = 1;
            break;
        case 4:
        case 6:
        default:
            v0 = 0;
        }
    }
    return v0;
}


/* CheckRiddleDrawModel @ 0x134C90 .. 0x134D00 (0x70 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x134cc8 writes a register its branch at 0x134cc4 reads
 *   cfg: kept goto: 0x134ce0 -> .L00134CF0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int CheckRiddleDrawModel(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v0 = GetRiddleFreeState();
    if (v0 == 0) {
        goto _L00134CB8;
    }
    v0 = 0;
    goto _L00134CF0;
    _L00134CB8:;
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = 8;
    v1 = *(u16 *)((v1 + 0xa));
    switch (v1) {
    case 5:
    case 8:
        v0 = 1;
        return v0;
    }
    v0 = 0;
    _L00134CF0:;
    return v0;
}
