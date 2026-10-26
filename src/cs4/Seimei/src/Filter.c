#include "common.h"
extern int rand(void);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void PadSetVib(signed int, float, float, unsigned char, unsigned char, signed int);
extern u32 TVEffectMng[2];
extern u8 GameSt[];
extern u8 TVSwitch[];
extern u8 TVNoise[8];
extern u8 TVFlash[8];
extern void FlushCache(int);
static u8 FrameBuffer[0x15000];
static u8 NoiseImageTex[0x200];
static u16 NoiseImageClut[0x10];
static u8 TVSwitch[0xc];

static u8 DMABuf_1139[0x200];
static u32 DMABuf_1095[48];
static u32 DMABuf_1074[32];
static u8 DMABuf_1056[0x80];
static u8 DMABuf_715[0xc0];
static u8 DMABuf_677[0x1e0];
extern u8 *lpDrawMng;
extern void *memset(void *, int, unsigned int);
extern void * memcpy(void *, const void *, unsigned int);
extern u32 L1027[];
extern u32 lpMdlPacketMem;
extern unsigned char GetMapGlareID(void);
extern u8 MdlMng[];
extern signed int CheckEneDead(void *);
extern void GetAmbientColor(void *);
extern u8 DarkFilterMng[4];
extern u32 FrameID;
extern u8 FrameBuffer[];
void CopySmallFrameBuffer(void);
extern void CopySmallFrameBuffer(void);
extern int sceGsSetDefStoreImage(void *, short, short, short, short, short, short, short);
extern int sceGsExecStoreImage(void *, void *);
extern int sceGsSyncPath(int, unsigned short);
extern int sceGsSetDefLoadImage(void *, short, short, short, short, short, short, short);
extern int sceGsExecLoadImage(void *, void *);
void BlendFrameFilter(void);
extern void BlendFrameFilter(void);
void CheckTVEffect(void);
void CheckTVEffect(void);
void ClearFrameBuffer(void);
void ClearFrameBuffer(void);
static void CopyFrameBuffer(void);
static void CopyFrameBuffer(void);
void DrawFrameFilter(void);
void DrawFrameFilter(void);
void SetGlareFilter(s32 a0 );
void SetGlareFilter(s32 a0 /* r4 */);
void InitGlareFilter(void);
void InitGlareFilter(void);
static void ResetCharaPriority(unsigned char a0 );
static void ResetCharaPriority(unsigned char a0 /* r4 */);
static void SetCharaPriority(unsigned char a0 );
static void SetCharaPriority(unsigned char a0 /* r4 */);
u32 CheckDarkFilter(void);
u32 CheckDarkFilter(void);
u32 SetBlurFilter(s32 a0 );
u32 SetBlurFilter(s32 a0 /* r4 */);
void SetPcrtc(void);
void SetPcrtc(void);
void InitPcrtc(void);
void InitPcrtc(void);
void BlendFrameFilter(void);
void MakeFadedFilter(void);
void MakeFadedFilter(void);
void CopySmallFrameBuffer(void);
void DrawFadedFilter(void);
void DrawFadedFilter(void);
void ClearFadedFilter(void);
void ClearFadedFilter(void);


/* DrawDarkFilter @ 0x184340 .. 0x184744 (0x404 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1843ac writes a register its branch at 0x1843a8 reads
 *   stack: address of the slot at 0x30 escapes at 0x1843d8
 *   fpu: float literal 0x3f800000 at 0x1843e8
 *   fpu: mtc1 reinterprets a3 at 0x1843f8
 *   fpu: mtc1 reinterprets a0 at 0x184410
 *   fpu: float literal 0x42c80000 at 0x184430
 *   fpu: float literal 0x3f800000 at 0x184448
 *   fpu: mtc1 reinterprets a3 at 0x184454
 *   stack: address of the slot at 0x34 escapes at 0x184460
 *   fpu: mtc1 reinterprets a0 at 0x18446c
 *   fpu: float literal 0x42c80000 at 0x18448c
 *   fpu: float literal 0x3f800000 at 0x1844a4
 *   fpu: mtc1 reinterprets a3 at 0x1844b0
 *   stack: address of the slot at 0x38 escapes at 0x1844bc
 *   fpu: mtc1 reinterprets a0 at 0x1844c8
 *   fpu: float literal 0x42c80000 at 0x1844f4
 *   delay: addiu at 0x184528 writes a register its branch at 0x184524 reads
 *   stack: address of the slot at 0x30 escapes at 0x18452c
 *   delay: addiu at 0x184588 writes a register its branch at 0x184584 reads
 *   stack: address of the slot at 0x30 escapes at 0x18458c
 *   cfg: loop body is not one contiguous region: .L00184510
 *   cfg: loop body is not one contiguous region: .L00184570
 *   cfg: kept goto: 0x1845d0 -> .L00184630
 *   cfg: kept goto: 0x1845e0 -> .L00184630
 *   cfg: kept goto: 0x18460c -> .L00184630
 */

extern void sceVu0CopyVector(void *, void *);

struct dw_1119283_fields;
struct dw_1139877_fields;
#ifndef PROTO_DW_1137987_FIELDS
#define PROTO_DW_1137987_FIELDS
struct dw_1137987_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_1133409_FIELDS
#define PROTO_DW_1133409_FIELDS
struct dw_1133409_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_1133014_FIELDS
#define PROTO_DW_1133014_FIELDS
struct dw_1133014_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_1119283_fields *lpMdl; };
#endif
#ifndef PROTO_DW_1119283_FIELDS
#define PROTO_DW_1119283_FIELDS
struct dw_1119283_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_1139877_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_1119283_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_1137987_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_1133409_fields flags; unsigned char _pad1[3]; struct dw_1133014_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_1135934_FIELDS
#define PROTO_DW_1135934_FIELDS
struct dw_1135934_fields { unsigned char State; unsigned char Alpha; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1119283_FIELDS_PRIORITY_8ED77A39_DEFINED
#define DCOMP_OFF_STRUCT_DW_1119283_FIELDS_PRIORITY_8ED77A39_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1119283_FIELDS_PRIORITY_8ED77A39 = (int)&(((struct dw_1119283_fields *)0)->Priority) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1119283_FIELDS__160__INDEXANIM_4CF958ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_1119283_FIELDS__160__INDEXANIM_4CF958ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1119283_FIELDS__160__INDEXANIM_4CF958ED = (int)&(((struct dw_1119283_fields *)0)[160].IndexAnim) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1119283_FIELDS_BUSE_A804AA64_DEFINED
#define DCOMP_OFF_STRUCT_DW_1119283_FIELDS_BUSE_A804AA64_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1119283_FIELDS_BUSE_A804AA64 = (int)&(((struct dw_1119283_fields *)0)->bUse) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B = (int)&(((struct dw_1135934_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270_DEFINED
#define DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270 = (int)&(((struct dw_1135934_fields *)0)->State) - 0 };
#endif




struct GL_Info { unsigned char r; unsigned char g; unsigned char b; unsigned char a; };
struct GL_DebugParam { unsigned char pad[0x7b0]; struct GL_Info Glare[1]; };
struct GL_Frame { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
struct GL_DrawEnv { struct GL_Frame frame1; unsigned long frame1addr; unsigned long zbuf1; long zbuf1addr; unsigned long xyoffset1; long xyoffset1addr; unsigned long scissor1; long scissor1addr; };
extern struct GL_DebugParam *lpDebugParam;

#define GL_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))
#define GL_SET_FRAME(fbp, fbw, psm, fbmsk) ((u_long)(fbp) | ((u_long)(fbw) << 16) | ((u_long)(psm) << 24) | ((u_long)(fbmsk) << 32))
#define GL_SET_TEX0(tbp, tbw, psm, tw, th, tcc) ((u_long)(tbp) | ((u_long)(tbw) << 14) | ((u_long)(psm) << 20) | ((u_long)(tw) << 26) | ((u_long)(th) << 30) | ((u_long)(tcc) << 34))
#define GL_SET_RGBAQ(r, g, b, a, q) ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16) | ((u_long)(a) << 24) | ((u_long)(q) << 32))
#define GL_SET_ALPHA(a, b, c, d, fix) ((u_long)(a) | ((u_long)(b) << 2) | ((u_long)(c) << 4) | ((u_long)(d) << 6) | ((u_long)(fix) << 32))


extern u8 NoiseImageTex[];
extern u16 NoiseImageClut[];

















/* DrawNoiseEffect @ 0x182940 .. 0x182B7C (0x23c bytes, frame 0x30) */

extern unsigned int * LoadImage(signed int, signed int, signed int, signed int, signed int, signed
    int, signed int, void *, signed int, unsigned int *);

static inline void DrawNoiseEffect__inl0(void) {
    u32 v1;

    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
}









/* DrawTVEffect @ 0x182060 .. 0x1825D8 (0x578 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @1323 is the string 'fe_no.tm2'
 *   literal: @1191 -> 0x22b2b0
 *   stack: address of the slot at 0x50 escapes at 0x1820d4
 *   stack: address of the slot at 0x40 escapes at 0x1820d4
 *   stack: address of the slot at 0x50 escapes at 0x1820e4
 *   delay: addiu at 0x1821a0 writes a register its branch at 0x18219c reads
 *   delay: addiu at 0x1822cc writes a register its branch at 0x1822c8 reads
 *   literal: @1191 initializes the 16-byte local at 0x40
 */

extern void * GetTexMngByName(void *, char *);
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void MakeAndKickSpritePacket(void *);
extern void SND_Stop(signed int);
void ScaleFrameBuffer(signed int Width, signed int Height, signed int Offset, unsigned char Alpha);
static void ScaleFrameBuffer(signed int, signed int, signed int, unsigned char);

#ifndef PROTO_DW_1123026_FIELDS
#define PROTO_DW_1123026_FIELDS
struct dw_1123026_fields { unsigned char Use; unsigned char Mode; unsigned char Counter; unsigned char Alpha; int Width; int Height; };
#endif
#ifndef PROTO_DW_1125647_FIELDS
#define PROTO_DW_1125647_FIELDS
struct dw_1125647_fields { unsigned char Use; unsigned char Mode; unsigned char Counter; unsigned char Alpha; int VoiceHdl; };
#endif
#ifndef PROTO_DW_1126966_FIELDS
#define PROTO_DW_1126966_FIELDS
struct dw_1126966_fields { unsigned char Use; unsigned char Alpha; unsigned char TexNo; unsigned char Counter; char ShiftX; char ShiftY; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 = (int)&(((struct dw_1123026_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 = (int)&(((struct dw_1123026_fields *)0)->Counter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 = (int)&(((struct dw_1123026_fields *)0)->Height) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 = (int)&(((struct dw_1123026_fields *)0)->Mode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C = (int)&(((struct dw_1123026_fields *)0)->Use) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF = (int)&(((struct dw_1123026_fields *)0)->Width) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62_DEFINED
#define DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62 = (int)&(((struct dw_1125647_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5 = (int)&(((struct dw_1125647_fields *)0)->Counter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136_DEFINED
#define DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136 = (int)&(((struct dw_1125647_fields *)0)->Mode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8_DEFINED
#define DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8 = (int)&(((struct dw_1125647_fields *)0)->Use) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1125647_FIELDS_VOICEHDL_B93180DE_DEFINED
#define DCOMP_OFF_STRUCT_DW_1125647_FIELDS_VOICEHDL_B93180DE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1125647_FIELDS_VOICEHDL_B93180DE = (int)&(((struct dw_1125647_fields *)0)->VoiceHdl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8_DEFINED
#define DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8 = (int)&(((struct dw_1126966_fields *)0)->Alpha) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD_DEFINED
#define DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD = (int)&(((struct dw_1126966_fields *)0)->Counter) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTX_1A50B59C_DEFINED
#define DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTX_1A50B59C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTX_1A50B59C = (int)&(((struct dw_1126966_fields *)0)->ShiftX) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTY_99755BA5_DEFINED
#define DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTY_99755BA5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTY_99755BA5 = (int)&(((struct dw_1126966_fields *)0)->ShiftY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1126966_FIELDS_USE_E3AF5E4B_DEFINED
#define DCOMP_OFF_STRUCT_DW_1126966_FIELDS_USE_E3AF5E4B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1126966_FIELDS_USE_E3AF5E4B = (int)&(((struct dw_1126966_fields *)0)->Use) - 0 };
#endif

static u8 DarkFilterMng[0x4];
static u32 TVEffectMng[0x2];
static u8 TVNoise[0x8];

static u8 TVFlash[0x8];
static u32 FrameID;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ClearFadedFilter(void);
void DrawFadedFilter(void);
void CopySmallFrameBuffer(void);
void MakeFadedFilter(void);
void BlendFrameFilter(void);
void InitPcrtc(void);
void SetPcrtc(void);
u32 SetBlurFilter(s32 a0 );
void DrawBlurFilter(void);
u32 CheckDarkFilter(void);
void DrawDarkFilter(void);
static void SetCharaPriority(unsigned char a0 );
static void ResetCharaPriority(unsigned char a0 );
void DrawNegaPosiFilter(void);
void InitGlareFilter(void);
void SetGlareFilter(s32 a0 );
void DrawGlareFilter(void);
void DrawBilinerFilter(void);
void DrawFrameFilter(void);
void DrawBrightnessFilter(void);
void ClearFrameBuffer(void);
void ScaleFrameBuffer(signed int Width, signed int Height, signed int Offset, unsigned char Alpha);
static void DrawNoiseEffect(unsigned char a0 );
void InitTVEffect(void);
void CheckTVEffect(void);
void DrawTVEffect(void);
static void CopyFrameBuffer(void);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */



/* ClearFadedFilter @ 0x1850E0 .. 0x185110 (0x30 bytes, frame 0x10) */


void ClearFadedFilter(void) {
    memset(FrameBuffer, 0, (u64)(0x10000 | 0x5000));
    FrameID = 0;
    return;
}














/* DrawFadedFilter @ 0x184FC0 .. 0x1850DC (0x11c bytes, frame 0xe0) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x70 escapes at 0x185010
 *   stack: address of the slot at 0x70 escapes at 0x185044
 *   stack: address of the slot at 0x10 escapes at 0x185080
 *   stack: address of the slot at 0x10 escapes at 0x1850b4
 */


void DrawFadedFilter(void) {
    u32 v0;
    u32 a1;
    s32 a3;
    s32 v1;
    u8 stackFrame_70[112] __attribute__((aligned(16)));
    u8 stackFrame_10[96] __attribute__((aligned(16)));

    do {
        v0 = *(volatile s32 *)0x10009000;
        v0 = v0 & 0x100;
    } while (v0 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    CopySmallFrameBuffer();
    sceGsSetDefStoreImage((void *)((u8 *)&stackFrame_70[0]), 0x2a00, 2, 1, 0, 0, 0x80, 0x70);
    FlushCache(0);
    a1 = FrameID;
    v0 = (u32)FrameBuffer;
    a1 = a1 * (u32)(7);
    v1 = a1 << 2;
    sceGsExecStoreImage((void *)((u8 *)&stackFrame_70[0]), (void *)(u32)(s32)((u8 *)FrameBuffer +
        (s32)((u32)(v1 - a1) << 0xb)));
    sceGsSyncPath(0, 0);
    v0 = FrameID;
    a3 = 1;
    FrameID = a3 - v0;
    sceGsSetDefLoadImage((void *)((u8 *)&stackFrame_10[0]), 0x2a00, 2, a3, 0, 0, 0x80, 0x70);
    FlushCache(0);
    a1 = FrameID;
    v0 = (u32)FrameBuffer;
    a1 = a1 * (u32)(7);
    v1 = a1 << 2;
    sceGsExecLoadImage((void *)((u8 *)&stackFrame_10[0]), (void *)(u32)(s32)((u8 *)FrameBuffer +
        (s32)((u32)(v1 - a1) << 0xb)));
    sceGsSyncPath(0, 0);
    BlendFrameFilter();
    return;
}


/* CopySmallFrameBuffer @ 0x184CB0 .. 0x184FB8 (0x308 bytes, frame 0x70) */




void CopySmallFrameBuffer(void) {
    u32 t7;
    s32 t6;
    u32 t5;
    u32 t4;
    u8 *t3;
    u8 *t2;
    s32 t1;
    s32 t0;
    s32 a3;
    s32 a2;
    s32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u32 s5;
    u32 s4;
    u32 s3;
    u64 t0_64;
    u64 a3_64;
    u64 a2_64;
    u64 a1_64;

    a0 = (u32)lpDrawMng;
    v1 = *(s32 *)((a0 + 0x408));
    t3 = DMABuf_677;
    if (v1 == (u32)1) {
        t2 = (u8 *)(s32)(a0 + 0x60);
    } else {
        t2 = (u8 *)(s32)(a0 + 0x150);
    }
    v0 = 0x51000000;
    a0 = 0x10000000;
    v1 = 0x800b;
    t1 = 0xe;
    *(u32 *)t3 = 0x10000000 | 0x15;
    t0 = 0x3f;
    *(u32 *)(t3 + 4) = 0;
    *(u32 *)(t3 + 8) = 0;
    v0 = 0x10ab4000;
    *(u32 *)(t3 + 0xc) = 0x51000000 | 0x15;
    a3 = 0x4c;
    *(u32 *)(t3 + 0x10) = 0x800b;
    a2 = 0x18;
    *(u32 *)(t3 + 0x14) = 0x10ab4000;
    a1 = 0x40;
    v0 = -0x1000000;
    *(u32 *)(t3 + 0x18) = t1;
    *(u32 *)(t3 + 0x1c) = 0;
    *(u64 *)(t3 + 0x20) = 0;
    v0 = 0x1020150;
    *(s64 *)(t3 + 0x28) = t0;
    *(u64 *)(t3 + 0x30) = (u64)((s32)((s32)0x1020150)) | (u64)((u64)(s32)-0x1000000 << 0x20);
    *(s64 *)(t3 + 0x38) = a3;
    *(u64 *)(t3 + 0x40) = (u64)((s32)((s32)0x7c00)) | (u64)((u64)(u32)0x7c80 << 0x20);
    v0 = 0x6f0000;
    *(s64 *)(t3 + 0x48) = a2;
    v0 = 0x7f0000;
    *(u64 *)(t3 + 0x50) = (u64)((s32)((s32)0x7f0000)) | (u64)((u64)(u32)0x6f0000 << 0x20);
    v1 = 1;
    *(s64 *)(t3 + 0x58) = a1;
    *(u64 *)(t3 + 0x60) = (u64)(s32)v1 << 0x20;
    v0 = 0x4e;
    *(s64 *)(t3 + 0x68) = (s32)v0;
    *(s64 *)(t3 + 0x70) = (s32)0x60;
    *(s64 *)(t3 + 0x78) = (s32)0x14;
    s5 = *(u8 *)(t2 + 2);
    t4 = 0x64000000;
    s4 = *(u16 *)t2;
    s3 = *(u8 *)(t2 + 3);
    t5 = 0x80;
    t4 = 0x3f800000;
    *(u64 *)(t3 + 0x80) = (u64)((u64)((u64)(u32)(s3 & 0x3f) << 0x14) | (u64)((u64)((u64)(u32)(s5 &
        0x3f) << 0xe) | (u64)((s32)((s32)((u32)(s4 & 0x1ff) << 5))))) |
        (u64)((u64)((s32)((s32)0x64000000)) | (u64)((u64)(u32)2 << 0x20));
    *(s64 *)(t3 + 0x88) = (s32)6;
    t4 = 0x8080;
    *(u64 *)(t3 + 0x90) = 0;
    *(s64 *)(t3 + 0x98) = (s32)0x47;
    *(s64 *)(t3 + 0xa0) = (s32)0x44;
    *(s64 *)(t3 + 0xa8) = (s32)0x42;
    *(u64 *)(t3 + 0xb0) = (u64)((s32)((s32)t5)) | (u64)((u64)(s32)t5 << 0x20);
    t7 = 0x8002;
    *(s64 *)(t3 + 0xb8) = (s32)0x3b;
    t6 = 0x24000000;
    *(u64 *)(t3 + 0xc0) = (u64)((u64)((u64)0x8080 << 0x10) | (u64)(0x8080)) |
        (u64)((u64)(u32)0x3f800000 << 0x20);
    *(s64 *)(t3 + 0xc8) = (s32)v1;
    *(u32 *)(t3 + 0xd0) = 0x8002;
    v1 = 0x7c707bf0;
    *(u32 *)(t3 + 0xd4) = 0x24000000;
    *(u32 *)(t3 + 0xd8) = 0x43;
    *(u32 *)(t3 + 0xdc) = 0;
    v1 = 0x1c000000;
    *(u64 *)(t3 + 0xe0) = 0;
    *(u64 *)(t3 + 0xe8) = (u64)((s32)((s32)0x7c707bf0)) | (u64)((u64)(s32)-1 << 0x20);
    *(u64 *)(t3 + 0xf0) = (u32)(0x1c000000 | 0x2000);
    v1 = -0x7c7f7c00;
    *(u64 *)(t3 + 0xf8) = (s32)-0x7c7f7c00;
    v1 = 0x8005;
    *(u32 *)(t3 + 0x100) = 0x8005;
    *(u32 *)(t3 + 0x104) = 0x10000000;
    v1 = 0x70000000;
    *(u32 *)(t3 + 0x108) = t1;
    *(u32 *)(t3 + 0x10c) = 0;
    *(u64 *)(t3 + 0x110) = 0;
    *(s64 *)(t3 + 0x118) = t0;
    t0_64 = *(u64 *)t2;
    *(u64 *)(t3 + 0x120) = t0_64;
    *(s64 *)(t3 + 0x128) = a3;
    a3_64 = *(u64 *)(t2 + 0x20);
    *(u64 *)(t3 + 0x130) = a3_64;
    *(s64 *)(t3 + 0x138) = a2;
    a2_64 = *(u64 *)(t2 + 0x30);
    *(u64 *)(t3 + 0x140) = a2_64;
    *(s64 *)(t3 + 0x148) = a1;
    a1_64 = *(u64 *)(t2 + 0x10);
    *(u64 *)(t3 + 0x150) = a1_64;
    *(s64 *)(t3 + 0x158) = (s32)v0;
    *(u32 *)(t3 + 0x160) = 0x70000000;
    *(u32 *)(t3 + 0x164) = 0;
    *(u32 *)(t3 + 0x168) = 0;
    *(u32 *)(t3 + 0x16c) = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    a0 = (u32)DMABuf_677;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile void **)0x10009030 = (void *)DMABuf_677;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}



void MakeFadedFilter(void) {
    s32 frameOffset = 1 - (s32)FrameID;
    s32 count = 0x3800;
    u8 *pixel = FrameBuffer;
    s32 weightR = 0x12b;
    s32 weightG = 0x24b;

    pixel += (u32)((u32)((s32)(frameOffset * 7 * 3)) << 11);
    if (count-- != 0) {
        do {
            u32 red = pixel[0];
            u32 green = pixel[1];
            u32 blue = pixel[2];
            u32 total = red * (u32)weightR + green * (u32)weightG + blue * 0x72;
            u32 gray = (s32)total / 1000;
            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;
            pixel += 3;
        } while (count-- != 0);
    }
}


/* BlendFrameFilter @ 0x1849C0 .. 0x184BF0 (0x230 bytes, frame 0x10) */



void BlendFrameFilter(void) {
    u32 v1;
    u64 a0_64;
    u32 v0;

    v0 = 0x10000009;
    *(u32 *)DMABuf_715 = 0x10000009;
    *(u32 *)(DMABuf_715 + 4) = 0;
    *(u32 *)(DMABuf_715 + 8) = 0;
    v0 = 0x51000009;
    *(u32 *)(DMABuf_715 + 0xc) = 0x51000009;
    *(u32 *)(DMABuf_715 + 0x10) = 5;
    v0 = 0x10ab4000;
    *(u32 *)(DMABuf_715 + 0x14) = 0x10ab4000;
    *(u32 *)(DMABuf_715 + 0x18) = 0xe;
    *(u32 *)(DMABuf_715 + 0x1c) = 0;
    *(u64 *)(DMABuf_715 + 0x20) = 0;
    *(s64 *)(DMABuf_715 + 0x28) = (s32)0x3f;
    v0 = 0x70000;
    *(s64 *)(DMABuf_715 + 0x30) = (s32)0x70000;
    *(s64 *)(DMABuf_715 + 0x38) = (s32)0x47;
    *(u64 *)(DMABuf_715 + 0x40) = (u64)((s32)((s32)0x64)) | (u64)((u64)(u32)0x40 << 0x20);
    *(s64 *)(DMABuf_715 + 0x48) = (s32)0x42;
    v0 = 1;
    a0_64 = (u64)(s32)v0 << 0x20;
    v0 = 0xdc10;
    v0 = 0x3f800000;
    *(u64 *)(DMABuf_715 + 0x50) = (u64)((u64)((u64)0xdc10 << 0x10) | (u64)(0xaa00)) | a0_64;
    *(s64 *)(DMABuf_715 + 0x58) = (s32)6;
    v1 = 0x8080;
    v0 = 0x24000000;
    *(u64 *)(DMABuf_715 + 0x60) = (u64)((u64)((u64)0x8080 << 0x10) | (u64)(0x8080)) |
        (u64)((u64)(u32)0x3f800000 << 0x20);
    *(u64 *)(DMABuf_715 + 0x68) = 1;
    *(u32 *)(DMABuf_715 + 0x70) = 2;
    *(u32 *)(DMABuf_715 + 0x74) = 0x24000000;
    *(u32 *)(DMABuf_715 + 0x78) = 0x43;
    *(u32 *)(DMABuf_715 + 0x7c) = 0;
    *(u64 *)(DMABuf_715 + 0x80) = 0;
    v0 = 0x72000000;
    v0 = 0x7000800;
    *(u64 *)(DMABuf_715 + 0x88) = (u64)((u32)(0x72000000 | 0x7000)) | (u64)((u64)(s32)-1 << 0x20);
    *(s64 *)(DMABuf_715 + 0x90) = (s32)0x7000800;
    v0 = -0x72000000;
    v0 = 0x70000000;
    *(u64 *)(DMABuf_715 + 0x98) = (u64)((u32)(0x8e000000 | 0x9000)) | (u64)((u64)(s32)-1 << 0x20);
    *(u32 *)(DMABuf_715 + 0xa0) = 0x70000000;
    *(u32 *)(DMABuf_715 + 0xa4) = 0;
    *(u32 *)(DMABuf_715 + 0xa8) = 0;
    *(u32 *)(DMABuf_715 + 0xac) = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile void **)0x10009030 = (void *)DMABuf_715;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}










/* InitPcrtc @ 0x1849B0 .. 0x1849B8 (0x8 bytes) */



void InitPcrtc(void) {
    return;
}






/* SetPcrtc @ 0x1849A0 .. 0x1849A8 (0x8 bytes) */



void SetPcrtc(void) {
    return;
}


/* SetBlurFilter @ 0x184990 .. 0x18499C (0xc bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u32 SetBlurFilter(s32 a0 /* r4 */) {
    u8 *v1;

    v1 = (u8 *)lpDrawMng;
    *(u8 *)(((u8 *)v1 + 0x42e)) = a0;
    return;
}










/* DrawBlurFilter @ 0x184770 .. 0x18498C (0x21c bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1847a8 writes a register its branch at 0x1847a4 reads
 */



void DrawBlurFilter(void) {
    u32 t0;
    struct { u32 value; } alpha;
    u32 a2;
    u32 a3;
    u32 a3_index;
    u32 a1;
    s32 at;
    u32 a0;
    u64 a0_64;
    u64 a1_64;
    u64 a2_64;
    u8 *v1;

    a0 = (u32)lpDrawMng;
    a1 = a0 + 0x42f;
    alpha.value = *(u8 *)((a0 + 0x42f));
    v1 = (u8 *)lpMdlPacketMem;
    if (alpha.value == 0) {
        alpha.value = 0x20;
        *(u8 *)a1 = alpha.value;
    }
    a1 = (u32)lpDrawMng;
    a0 = 2;
    alpha.value = *(u8 *)(a3 = a1 + 0x42f);
    a1 = *(u8 *)((a1 + 0x42e));
    switch (a1) {
    case 1:
        if ((u8)alpha.value < 0x70) {
            *(u8 *)a3 = alpha.value + 1;
        }
        break;
    case 2:
        if ((u8)alpha.value < 0x60) {
            *(u8 *)a3 = alpha.value + 1;
        }
        a0 = (u32)lpDrawMng;
        a1 = a0 + 0x42f;
        a0 = *(u8 *)((a0 + 0x42f));
        if ((s32)a0 <= (s32)0x60) {
            break;
        }
        a0 = a0 + -1;
        *(u8 *)a1 = a0;
        break;
    default:
        if ((u8)alpha.value > 0x20) {
            *(u8 *)a3 = alpha.value - 1;
        }
    }
    a1 = (u32)lpDrawMng;
    a0 = *(s32 *)((a1 + 0x408));
    if (a0 != 0) {
        t0 = a1 + 0x60;
    } else {
        t0 = a1 + 0x150;
    }
    a1 = 0x1000000a;
    *(u32 *)v1 = 0x1000000a;
    a1_64 = 0x64 | ((u64)(alpha.value & 255) << 32);
    *(u32 *)(v1 + 4) = 0;
    *(u32 *)(v1 + 8) = 0;
    a0 = 0x5100000a;
    *(u32 *)(v1 + 0xc) = 0x5100000a;
    a0 = 6;
    *(u32 *)(v1 + 0x10) = a0;
    a0 = 0x10ab0000;
    a2 = 0x10ab0000 | 0x4000;
    *(u32 *)(v1 + 0x14) = a2;
    a0 = 0xe;
    *(u32 *)(v1 + 0x18) = a0;
    a2 = 0x47;
    *(u32 *)(v1 + 0x1c) = 0;
    a0 = 0x42;
    *(u64 *)(v1 + 0x20) = 0;
    *(s64 *)(v1 + 0x28) = 0x3f;
    *(u64 *)(v1 + 0x30) = 0;
    *(s64 *)(v1 + 0x38) = (s32)a2;
    *(u64 *)(v1 + 0x40) = a1_64;
    *(s64 *)(v1 + 0x48) = (s32)a0;
    a0 = *(u16 *)t0;
    a0 = a0 & 0x1ff;
    a2_64 = (s32)(a0 << 11) / 64;
    t0 = 6;
    a0_64 = a2_64 | ((u64)0x64120000 | ((u64)(s32)t0 << 32));
    *(u64 *)(v1 + 0x50) = a0_64;
    a2 = 0x14;
    a0 = 0x3f800000;
    *(s64 *)(v1 + 0x58) = (s32)t0;
    a1_64 = (u64)(u32)0x3f800000 << 0x20;
    *(s64 *)(v1 + 0x60) = 0x20;
    a0 = 0x8080;
    *(s64 *)(v1 + 0x68) = (s32)a2;
    a0_64 = (u64)0x8080 << 0x10;
    a2 = 1;
    a0_64 = a0_64 | (u64)(0x8080);
    a1_64 = a0_64 | a1_64;
    *(u64 *)(v1 + 0x70) = a1_64;
    a0 = 2;
    *(s64 *)(v1 + 0x78) = (s32)a2;
    a1 = 0x24000000;
    *(u32 *)(v1 + 0x80) = a0;
    a2 = 0x43;
    *(u32 *)(v1 + 0x84) = 0x24000000;
    a0 = -1;
    a1_64 = (u64)(s32)a0 << 0x20;
    *(u32 *)(v1 + 0x88) = a2;
    *(u32 *)(v1 + 0x8c) = 0;
    a0 = 0x71f07000;
    *(u64 *)(v1 + 0x90) = 0;
    a0_64 = (u64)((s32)((s32)0x71f07000)) | a1_64;
    a0_64 = a0_64;
    *(u64 *)(v1 + 0x98) = a0_64;
    a0 = 0x1c000000;
    a1 = 0x1c000000 | 0x2000;
    *(u64 *)(v1 + 0xa0) = a1;
    a0 = -0x71ff7000;
    a0_64 = (s32)-0x71ff7000;
    *(u64 *)(v1 + 0xa8) = a0_64;
    v1 = (u8 *)(v1 + 0xb0);
    lpMdlPacketMem = (s32)v1;
    return;
}


/* CheckDarkFilter @ 0x184750 .. 0x184764 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: andi at 0x184760 computes the return value
 */


u32 CheckDarkFilter(void) {
    u8 v0;

    v0 = DarkFilterMng[0];
    v0 = (s32)v0 < (s32)2;
    v0 = v0 ^ 1;
    return (u8)v0;
}
void DrawDarkFilter(void) {
    u64 t7;
    u32 t6;
    u8 *s1;
    s32 t4;
    u32 a3;
    u32 a2;
    u8 *s0;
    u32 a1;
    u64 a2_64;
    u64 a1_64;
    u32 a0;
    u32 v1;
    u64 a3_64;
    u64 v1_64;
    float *pa2;
    float *pa1;
    float Color[4] __attribute__((aligned(16)));

    v1 = 0x2f;
    a0 = *(s16 *)(MdlMng + (DCOMP_OFF_STRUCT_DW_1119283_FIELDS__160__INDEXANIM_4CF958ED / 1));
    s1 = (u8 *)lpMdlPacketMem;
    if (a0 == v1) {
        a0 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270);
        v1 = 1;
        if (a0 == v1) {
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270) = 2;
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B) = 0;
            SetCharaPriority(5);
        } else if (a0 == 0) {
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270) = v1;
        }
    } else {
        a0 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270);
        if (a0 == (u32)2) {
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270) = 3;
        } else if (a0 == (u32)1) {
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270) = 0;
        }
    }
    v1 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270);
    v1 = (s32)v1 < (s32)2;
    if (v1 == 0) {
        GetAmbientColor((void *)((u8 *)&Color[0]));
        a3 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B);
        Color[0] += ((1.0f - Color[0]) * (float)a3) / 100.0f;
        pa2 = &Color[1];
        *pa2 += ((1.0f - *pa2) * (float)a3) / 100.0f;
        pa1 = &Color[2];
        *pa1 += ((1.0f - *pa1) * (float)a3) / 100.0f;
        s0 = (u8 *)(MdlMng + 0xfc00);
        v1 = (u32)(u8 *)(MdlMng + 0x17f40);
        if ((u32)s0 < v1) {
            do {
                v1 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1119283_FIELDS_BUSE_A804AA64);
                if (v1 != 0) {
                    a0 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1119283_FIELDS_PRIORITY_8ED77A39);
                    if (a0 == (u32)5) {
                        sceVu0CopyVector((void *)(s0 + 0xb0), (void *)((u8 *)&Color[0]));
                    }
                }
                s0 = (u8 *)(s0 + 0x1c0);
            } while (s0 < (u8 *)(MdlMng + 0x17f40));
        }
        s0 = (u8 *)(MdlMng + 0x5400);
        v1 = (u32)(u8 *)(MdlMng + 0xfc00);
        if ((u32)s0 < v1) {
            do {
                v1 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1119283_FIELDS_BUSE_A804AA64);
                if (v1 != 0) {
                    a0 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_1119283_FIELDS_PRIORITY_8ED77A39);
                    if (a0 == (u32)5) {
                        sceVu0CopyVector((void *)(s0 + 0xb0), (void *)((u8 *)&Color[0]));
                    }
                }
                s0 = (u8 *)(s0 + 0x1c0);
            } while (s0 < (u8 *)(MdlMng + 0xfc00));
        }
        a0 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270);
        v1 = 2;
        if (a0 == v1) {
            v1 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B);
            if ((s32)v1 > (s32)0x62) {
                *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B) = 0x64;
                goto _L00184630;
            }
            v1 = v1 + 2;
            *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B) = v1;
            goto _L00184630;
        } else {
            v1 = 3;
            if (a0 == v1) {
                v1 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B);
                if ((s32)v1 > (s32)2) {
                    v1 = v1 + -2;
                    *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B) =
                        v1;
                    goto _L00184630;
                } else {
                    *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_STATE_47486270) = 0;
                    ResetCharaPriority(1);
                }
            } else {
                _L00184630:;
                a0 = 0x10000000;
                a1 = 0x10000000 | 9;
                t6 = 1;
                *(u32 *)s1 = a1;
                v1 = 0x51000000;
                *(u32 *)(s1 + 4) = 0;
                a1 = 0x51000000 | 9;
                *(u32 *)(s1 + 8) = 0;
                a2 = 0x8004;
                *(u32 *)(s1 + 0xc) = a1;
                v1 = 0x10230000;
                a1 = 0x10230000 | 0x4000;
                *(u32 *)(s1 + 0x10) = 0x8004;
                *(u32 *)(s1 + 0x14) = a1;
                v1 = 0xe;
                *(u32 *)(s1 + 0x18) = v1;
                a1 = 0x30000;
                *(u32 *)(s1 + 0x1c) = 0;
                *(s64 *)(s1 + 0x20) = (s32)0x30000;
                s0 = (u8 *)(s32)0x42;
                *(s64 *)(s1 + 0x28) = (s32)0x47;
                a1 = 0x3f800000;
                a3 = *(u8 *)(DarkFilterMng + DCOMP_OFF_STRUCT_DW_1135934_FIELDS_ALPHA_2F395E4B);
                a2_64 = (u64)(u32)0x3f800000 << 0x20;
                a1 = 0x8000;
                a1_64 = (u64)0x8000 << 0x10;
                t4 = 0x4e;
                t7 = a1_64 | a2_64;
                a2 = 0x71f00000;
                a1 = 0x8e00;
                a3_64 = (u64)a3 << 0x20;
                a2_64 = a3_64 | (u64)(0x64);
                a1_64 = (u64)0x8e00 << 0x10;
                *(u64 *)(s1 + 0x30) = a2_64;
                a3_64 = a1_64 | (u64)(0x9000);
                *(s64 *)(s1 + 0x38) = (s32)s0;
                a2 = 0x8001;
                *(u64 *)(s1 + 0x40) = t7;
                a1 = (s32)(s1 + 0xa0);
                *(s64 *)(s1 + 0x48) = (s32)t6;
                *(u64 *)(s1 + 0x50) = (u64)(s32)t6 << 0x20;
                *(s64 *)(s1 + 0x58) = t4;
                *(u32 *)(s1 + 0x60) = 0x8002;
                *(u32 *)(s1 + 0x64) = 0x14000000;
                *(u32 *)(s1 + 0x68) = 4;
                *(u32 *)(s1 + 0x6c) = 0;
                *(u64 *)(s1 + 0x70) = (u32)(0x71f00000 | 0x6ff0);
                *(u64 *)(s1 + 0x78) = a3_64;
                *(u32 *)(s1 + 0x80) = 0x8001;
                *(u32 *)(s1 + 0x84) = 0x10000000;
                *(u32 *)(s1 + 0x88) = v1;
                *(u32 *)(s1 + 0x8c) = 0;
                v1 = (u32)lpDrawMng;
                v1_64 = *(u64 *)((v1 + 0x70));
                *(u64 *)(s1 + 0x90) = v1_64;
                *(s64 *)(s1 + 0x98) = t4;
                lpMdlPacketMem = a1;
            }
        }
    }
    return;
}






/* SetCharaPriority @ 0x1841D0 .. 0x18433C (0x16c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00184200
 *   cfg: kept branch: 0x184244 if (..) goto .L00184268
 *   cfg: loop body is not one contiguous region: .L001842A0
 *   declaration vs inferred signature: return void vs inferred u32
 */


static void SetCharaPriority(unsigned char a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    s32 v0;
    u32 a0_2;

    v1 = (u32)(u8 *)(MdlMng + 0x17f40);
    s0 = (u8 *)(MdlMng + 0xfc00);
    if ((u32)s0 < v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                a0_2 = *(s32 *)(s0 + 0xc);
                v1 = *(s32 *)((a0_2 + 0x10));
                v1 = *(s32 *)((v1 + 0x38));
                if (v1 == 0 || (u32)*(u8 *)((v1 + 0xa)) == 0) {
                    v1 = *(u16 *)((a0_2 + 0xa));
                    v0 = 1;
                    if (v1 == (u32)v0) {
                        a0_2 = (u32)s0;
                        v0 = CheckEneDead((void *)a0_2);
                        if ((u32)v0 != 0) {
                            goto _L00184268;
                        }
                    }
                    *(u8 *)(s0 + 6) = a0;
                    v0 = 1;
                    a0_2 = (s32)(s0 + 0xb0);
                    *(u8 *)(s0 + 8) = v0;
                    GetAmbientColor((void *)a0_2);
                }
            }
            _L00184268:;
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 < (u8 *)(MdlMng + 0x17f40));
    }
    s0 = (u8 *)(MdlMng + 0x5400);
    v1 = (u32)(u8 *)(MdlMng + 0xfc00);
    if ((u32)s0 < v1) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0 && (u32)((u32)(*(u8 *)(s0 + 0x12b)) & 6) != 0 && (u32)*(u8 *)(s0 + 6) != 0)
                {
                v1 = *(s32 *)(s0 + 0xc);
                v1 = *(s32 *)((v1 + 0x10));
                v1 = *(s32 *)((v1 + 0x38));
                if (v1 == 0 || (u32)*(u8 *)((v1 + 0xa)) == 0) {
                    *(u8 *)(s0 + 6) = a0;
                    v1 = *(u8 *)(s0 + 0x12b);
                    v1 = v1 & 4;
                    if (v1 == 0) {
                        v0 = 1;
                        a0_2 = (s32)(s0 + 0xb0);
                        *(u8 *)(s0 + 8) = v0;
                        GetAmbientColor((void *)a0_2);
                    }
                }
            }
            s0 = (u8 *)(s0 + 0x1c0);
        } while (s0 < (u8 *)(MdlMng + 0xfc00));
    }
    return;
}





/* ResetCharaPriority @ 0x184120 .. 0x1841C8 (0xa8 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00184140
 *   cfg: loop body is not one contiguous region: .L00184190
 */


static void ResetCharaPriority(unsigned char a0 /* r4 */) {
    u8 *a3;
    u32 v1;

    a3 = (u8 *)(MdlMng + 0xfc00);
    if (a3 < (u8 *)(MdlMng + 0x17f40)) {
        do {
            v1 = *(u8 *)a3;
            if (v1 != 0 && (u32)*(u8 *)(a3 + 6) == (u32)5) {
                *(u8 *)(a3 + 6) = a0;
                *(u8 *)(a3 + 8) = 0;
            }
            a3 = (u8 *)(a3 + 0x1c0);
            v1 = a3 < (u8 *)(MdlMng + 0x17f40);
        } while (v1 != 0);
    }
    a3 = (u8 *)(MdlMng + 0x5400);
    if (a3 < (u8 *)(MdlMng + 0xfc00)) {
        do {
            v1 = *(u8 *)a3;
            if (v1 != 0 && (u32)*(u8 *)(a3 + 6) == (u32)5) {
                *(u8 *)(a3 + 6) = a0;
                *(u8 *)(a3 + 8) = 0;
            }
            a3 = (u8 *)(a3 + 0x1c0);
            v1 = a3 < (u8 *)(MdlMng + 0xfc00);
        } while (v1 != 0);
    }
    return;
}


void DrawNegaPosiFilter(void)
{
    u8 *draw=lpDrawMng;
    u8 *packet=(u8 *)lpMdlPacketMem;
    u8 *frame;
    u32 amount;
    u64 color,firstAlpha,secondAlpha;
    if(*(u32 *)(draw+0x408)==0) frame=draw+0x60;else frame=draw+0x150;
    amount=GameSt[0x1c];
    *(u32 *)(packet+0x00)=0x1000001b;
    *(u32 *)(packet+0x04)=0;
    *(u32 *)(packet+0x08)=0;
    *(u32 *)(packet+0x0c)=0x5100001b;
    *(u32 *)(packet+0x10)=5;
    *(u32 *)(packet+0x14)=0x10000000;
    *(u32 *)(packet+0x18)=14;
    *(u32 *)(packet+0x1c)=0;
    *(u64 *)(packet+0x20)=0;
    *(u64 *)(packet+0x28)=63;
    *(u64 *)(packet+0x30)=(u64)(s32)((*(u16 *)frame&511)<<5)|0x01082a0001080000ULL;
    *(u64 *)(packet+0x38)=80;
    *(u64 *)(packet+0x40)=0;
    *(u64 *)(packet+0x48)=81;
    *(u64 *)(packet+0x50)=0x000001c000000200ULL;
    *(u64 *)(packet+0x58)=82;
    *(u64 *)(packet+0x60)=2;
    *(u64 *)(packet+0x68)=83;
    *(u32 *)(packet+0x70)=3;
    *(u32 *)(packet+0x74)=0x10034000;
    *(u32 *)(packet+0x78)=14;
    *(u32 *)(packet+0x7c)=0;
    *(u64 *)(packet+0x80)=0;
    *(u64 *)(packet+0x88)=63;
    *(u64 *)(packet+0x90)=0;
    *(u64 *)(packet+0x98)=71;
    color=(u64)amount|((u64)amount<<8)|((u64)amount<<16)|0x3f80000080000000ULL;
    *(u64 *)(packet+0xa0)=color;
    *(u64 *)(packet+0xa8)=1;
    *(u32 *)(packet+0xb0)=2;
    *(u32 *)(packet+0xb4)=0x14000000;
    *(u32 *)(packet+0xb8)=4;
    *(u32 *)(packet+0xbc)=0;
    *(u64 *)(packet+0xc0)=0xffffffff72007000ULL;
    *(u64 *)(packet+0xc8)=0xffffffff8e009000ULL;
    *(u32 *)(packet+0xd0)=5;
    *(u32 *)(packet+0xd4)=0x10ab4000;
    *(u32 *)(packet+0xd8)=14;
    *(u32 *)(packet+0xdc)=0;
    *(u64 *)(packet+0xe0)=0;
    *(u64 *)(packet+0xe8)=63;
    *(u64 *)(packet+0xf0)=0x0000000664122a00ULL;
    *(u64 *)(packet+0xf8)=6;
    *(u64 *)(packet+0x100)=0;
    *(u64 *)(packet+0x108)=20;
    firstAlpha=((u64)amount<<32)|161;
    *(u64 *)(packet+0x110)=firstAlpha;
    *(u64 *)(packet+0x118)=66;
    *(u64 *)(packet+0x120)=0x3f80000080808080ULL;
    *(u64 *)(packet+0x128)=1;
    secondAlpha=((u64)(u8)(128-amount)<<32)|100;
    *(u32 *)(packet+0x130)=2;
    *(u32 *)(packet+0x134)=0x24000000;
    *(u32 *)(packet+0x138)=67;
    *(u32 *)(packet+0x13c)=0;
    *(u64 *)(packet+0x140)=0;
    *(u64 *)(packet+0x148)=0xffffffff72007000ULL;
    *(u64 *)(packet+0x150)=0x1c002000;
    *(u64 *)(packet+0x158)=0xffffffff8e009000ULL;
    *(u32 *)(packet+0x160)=2;
    *(u32 *)(packet+0x164)=0x10ab4000;
    *(u32 *)(packet+0x168)=14;
    *(u32 *)(packet+0x16c)=0;
    *(u64 *)(packet+0x170)=0;
    *(u64 *)(packet+0x178)=63;
    *(u64 *)(packet+0x180)=secondAlpha;
    *(u64 *)(packet+0x188)=66;
    *(u32 *)(packet+0x190)=2;
    *(u32 *)(packet+0x194)=0x24000000;
    *(u32 *)(packet+0x198)=67;
    *(u32 *)(packet+0x19c)=0;
    *(u64 *)(packet+0x1a0)=0;
    *(u64 *)(packet+0x1a8)=0xffffffff72007000ULL;
    *(u64 *)(packet+0x1b0)=0x1c002000;
    *(u64 *)(packet+0x1b8)=0xffffffff8e009000ULL;
    lpMdlPacketMem=(u32)(packet+0x1c0);
}







/* InitGlareFilter @ 0x183E40 .. 0x183E64 (0x24 bytes, frame 0x10) */


void InitGlareFilter(void) {
    GameSt[0x1f] = GetMapGlareID();
    return;
}








/* SetGlareFilter @ 0x183E30 .. 0x183E3C (0xc bytes) */


void SetGlareFilter(s32 a0 /* r4 */) {
    *(u8 *)((u8 *)&GameSt + 0x1f) = a0;
    return;
}

void DrawGlareFilter(void) {
    static float Shift[8][2] = {
        {0.02f, 0.0f}, {-0.02f, 0.0f}, {0.0f, 0.02f}, {0.0f, -0.02f},
        {0.011547006f, 0.011547006f}, {-0.011547006f, -0.011547006f},
        {0.011547006f, -0.011547006f}, {-0.011547006f, 0.011547006f},
    };
    unsigned int *lpCurDMA;
    struct GL_Info *lpGlareInfo;
    int i;
    unsigned int Fbp;
    unsigned int Tbp;
    struct GL_DrawEnv *lpDraw;

    lpCurDMA = (unsigned int *)lpMdlPacketMem;
    lpDraw = (*(int *)(lpDrawMng + 0x408) == 0) ? (struct GL_DrawEnv *)(lpDrawMng + 0x60) : (struct GL_DrawEnv *)(lpDrawMng + 0x150);
    lpGlareInfo = &lpDebugParam->Glare[GameSt[0x1f]];
    if (GameSt[0x1f] == 0) {
        return;
    }
    lpCurDMA[0] = 0x1000005a;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x5100005a;
    lpCurDMA[4] = 0x8007;
    lpCurDMA[5] = 0x10034000;
    lpCurDMA[6] = 0xe;
    lpCurDMA[7] = 0;
    *(u_long *)&lpCurDMA[8] = 0;
    *(u_long *)&lpCurDMA[10] = 0x3f;
    *(u_long *)&lpCurDMA[12] = GL_SET_FRAME(0x150, 2, 1, 0xff000000);
    *(u_long *)&lpCurDMA[14] = 0x4c;
    *(u_long *)&lpCurDMA[16] = (u_long)0x7c00 | ((u_long)0x7c80 << 32);
    *(u_long *)&lpCurDMA[18] = 0x18;
    *(u_long *)&lpCurDMA[20] = ((u_long)0x7f << 16) | ((u_long)0x6f << 48);
    *(u_long *)&lpCurDMA[22] = 0x40;
    *(u_long *)&lpCurDMA[24] = (u_long)1 << 32;
    *(u_long *)&lpCurDMA[26] = 0x4e;
    *(u_long *)&lpCurDMA[28] = 0;
    *(u_long *)&lpCurDMA[30] = 0x47;
    *(u_long *)&lpCurDMA[32] = GL_SET_RGBAQ(lpGlareInfo->r, lpGlareInfo->g, lpGlareInfo->b, 0x80, 0x3f800000);
    *(u_long *)&lpCurDMA[34] = 1;
    lpCurDMA[36] = 0x8002;
    lpCurDMA[37] = 0x14000000;
    lpCurDMA[38] = 4;
    lpCurDMA[39] = 0;
    *(u_long *)&lpCurDMA[40] = GL_SET_XYZ(0x7bf0, 0x7c70, 0xffffffff);
    *(u_long *)&lpCurDMA[42] = GL_SET_XYZ(0x8400, 0x8380, 0xffffffff);
    lpCurDMA[44] = 0x8005;
    lpCurDMA[45] = 0x102b4000;
    lpCurDMA[46] = 0xe;
    lpCurDMA[47] = 0;
    *(u_long *)&lpCurDMA[48] = 0x60;
    *(u_long *)&lpCurDMA[50] = 0x14;
    *(u_long *)&lpCurDMA[52] = GL_SET_TEX0(lpDraw->frame1.FBP * 32, lpDraw->frame1.FBW, lpDraw->frame1.PSM, 9, 9, 0);
    *(u_long *)&lpCurDMA[54] = 6;
    *(u_long *)&lpCurDMA[56] = GL_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3f800000);
    *(u_long *)&lpCurDMA[58] = 1;
    *(u_long *)&lpCurDMA[60] = GL_SET_ALPHA(0, 1, 2, 2, 0x80);
    *(u_long *)&lpCurDMA[62] = 0x42;
    *(u_long *)&lpCurDMA[64] = (u_long)2 | ((u_long)2 << 2) | ((u_long)0x1ff << 14) | ((u_long)0x1bf << 34);
    *(u_long *)&lpCurDMA[66] = 8;
    lpCurDMA[68] = 0x8002;
    lpCurDMA[69] = 0x24000000;
    lpCurDMA[70] = 0x42;
    lpCurDMA[71] = 0;
    *(float *)&lpCurDMA[72] = -0.04f;
    *(float *)&lpCurDMA[73] = -0.04f;
    *(u_long *)&lpCurDMA[74] = GL_SET_XYZ(0x7bf0, 0x7c70, 0xffffffff);
    *(float *)&lpCurDMA[76] = 1.04f;
    *(float *)&lpCurDMA[77] = 0.915f;
    *(u_long *)&lpCurDMA[78] = GL_SET_XYZ(0x8400, 0x8380, 0xffffffff);
    lpCurDMA[80] = 0x8001;
    lpCurDMA[81] = 0x10000000;
    lpCurDMA[82] = 0xe;
    lpCurDMA[83] = 0;
    *(u_long *)&lpCurDMA[84] = 5;
    *(u_long *)&lpCurDMA[86] = 8;
    lpCurDMA += 88;
    for (i = 0; i < 8; i++) {
        if ((i & 1) == 0) {
            Fbp = 0x158;
            Tbp = 0x2a00;
        } else {
            Fbp = 0x150;
            Tbp = 0x2b00;
        }
        lpCurDMA[0] = 0x8003;
        lpCurDMA[1] = 0x100b4000;
        lpCurDMA[2] = 0xe;
        lpCurDMA[3] = 0;
        *(u_long *)&lpCurDMA[4] = 0;
        *(u_long *)&lpCurDMA[6] = 0x3f;
        *(u_long *)&lpCurDMA[8] = GL_SET_FRAME(Fbp, 2, 1, 0xff000000);
        *(u_long *)&lpCurDMA[10] = 0x4c;
        *(u_long *)&lpCurDMA[12] = GL_SET_TEX0(Tbp, 2, 1, 7, 7, 0);
        *(u_long *)&lpCurDMA[14] = 6;
        lpCurDMA[16] = 0x8002;
        lpCurDMA[17] = 0x24000000;
        lpCurDMA[18] = 0x42;
        lpCurDMA[19] = 0;
        *(float *)&lpCurDMA[20] = Shift[i][0];
        *(float *)&lpCurDMA[21] = Shift[i][1];
        *(u_long *)&lpCurDMA[22] = GL_SET_XYZ(0x7bf0, 0x7c70, 0xffffffff);
        *(float *)&lpCurDMA[24] = 1.0f + Shift[i][0];
        *(float *)&lpCurDMA[25] = 0.875f + Shift[i][1];
        *(u_long *)&lpCurDMA[26] = GL_SET_XYZ(0x8400, 0x8380, 0xffffffff);
        lpCurDMA += 28;
    }
    lpCurDMA[0] = 0x8005;
    lpCurDMA[1] = 0x10000000;
    lpCurDMA[2] = 0xe;
    lpCurDMA[3] = 0;
    *(u_long *)&lpCurDMA[4] = 0;
    *(u_long *)&lpCurDMA[6] = 0x3f;
    *(u_long *)&lpCurDMA[8] = *(u_long *)&lpDraw->frame1;
    *(u_long *)&lpCurDMA[10] = 0x4c;
    *(u_long *)&lpCurDMA[12] = lpDraw->xyoffset1;
    *(u_long *)&lpCurDMA[14] = 0x18;
    *(u_long *)&lpCurDMA[16] = lpDraw->scissor1;
    *(u_long *)&lpCurDMA[18] = 0x40;
    *(u_long *)&lpCurDMA[20] = lpDraw->zbuf1;
    *(u_long *)&lpCurDMA[22] = 0x4e;
    lpCurDMA[24] = 0x8003;
    lpCurDMA[25] = 0x10ab4000;
    lpCurDMA[26] = 0xe;
    lpCurDMA[27] = 0;
    *(u_long *)&lpCurDMA[28] = GL_SET_TEX0(0x2a00, 2, 1, 7, 7, 0);
    *(u_long *)&lpCurDMA[30] = 6;
    *(u_long *)&lpCurDMA[32] = GL_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3f800000);
    *(u_long *)&lpCurDMA[34] = 1;
    *(u_long *)&lpCurDMA[36] = GL_SET_ALPHA(0, 2, 2, 1, lpGlareInfo->a);
    *(u_long *)&lpCurDMA[38] = 0x42;
    lpCurDMA[40] = 0x8002;
    lpCurDMA[41] = 0x24000000;
    lpCurDMA[42] = 0x43;
    lpCurDMA[43] = 0;
    *(u_long *)&lpCurDMA[44] = 0;
    *(u_long *)&lpCurDMA[46] = GL_SET_XYZ(0x6ff0, 0x71f0, 0xffffffff);
    *(u_long *)&lpCurDMA[48] = (u_long)0x800 | ((u_long)0x6f0 << 16);
    *(u_long *)&lpCurDMA[50] = GL_SET_XYZ(0x9000, 0x8e10, 0xffffffff);
    lpMdlPacketMem = (u32)(lpCurDMA + 52);
}










void DrawBilinerFilter(void) {
    s32 s6, s5;
    u8 *s4, *s3;
    s32 s2, s1, s0, t9, t8, t7, t6;
    u64 t5, t4_64;
    u32 t3, t2, t1, t0;
    u64 a3_64;
    u64 a2;
    u32 a1, a0, v1;
    u64 a1_64, v1_64, t1_64;

    a0 = (u32)lpDrawMng;
    v1 = *(s32 *)((a0 + 0x408));
    s4 = (u8 *)lpMdlPacketMem;
    if (v1 == 0) {
        s3 = (u8 *)(s32)(a0 + 0x60);
    } else {
        s3 = (u8 *)(s32)(a0 + 0x150);
    }
    *(u32 *)s4 = 0x10000000 | 0x1c;
    *(u32 *)(s4 + 4) = 0;
    *(u32 *)(s4 + 8) = 0;
    *(u32 *)(s4 + 0xc) = 0x51000000 | 0x1c;
    *(u32 *)(s4 + 0x10) = 0x8006;
    *(u32 *)(s4 + 0x14) = 0x10034000;
    s2 = 0xe;
    *(u32 *)(s4 + 0x18) = s2;
    *(u32 *)(s4 + 0x1c) = 0;
    t4_64 = 0x0000008000000064ULL;
    *(u64 *)(s4 + 0x20) = 0;
    *(u64 *)(s4 + 0x28) = 0x3f;
    *(u64 *)(s4 + 0x30) = ((u64)0xff000000 << 0x20) | 0x1080150;
    s1 = 0x4c;
    s5 = -0x71ff7000;
    *(s64 *)(s4 + 0x38) = s1;
    s6 = -0x71ef7000;
    *(u64 *)(s4 + 0x40) = ((u64)0x7200 << 0x20) | 0x7000;
    s0 = 0x18;
    *(s64 *)(s4 + 0x48) = s0;
    t9 = 0x40;
    t8 = 1;
    t7 = 0x4e;
    *(u64 *)(s4 + 0x50) = ((u64)0x1bf0000 << 0x20) | 0x1ff0000;
    *(s64 *)(s4 + 0x58) = t9;
    *(u64 *)(s4 + 0x60) = (u64)t8 << 0x20;
    *(s64 *)(s4 + 0x68) = t7;
    *(u64 *)(s4 + 0x70) = 0;
    *(s64 *)(s4 + 0x78) = (s32)0x47;
    *(u32 *)(s4 + 0x80) = 0x8004;
    *(u32 *)(s4 + 0x84) = 0x108b4000;
    *(u32 *)(s4 + 0x88) = s2;
    *(u32 *)(s4 + 0x8c) = 0;
    v1_64 = (u64)(u32)2 << 0x20;
    *(s64 *)(s4 + 0x90) = (s32)0x60;
    t6 = 6;
    *(s64 *)(s4 + 0x98) = (s32)0x14;
    t2 = *(u8 *)(s3 + 2);
    t1 = *(u16 *)s3;
    t0 = *(u8 *)(s3 + 3);
    t5 = 0x3f80000080808080ULL;
    t3 = 0x42;
    t2 &= 0x3f;
    t1 &= 0x1ff;
    t1_64 = ((u64)t2 << 14) | (s32)(t1 << 5);
    t2 = 0x8002;
    t0 &= 0x3f;
    a1_64 = ((u64)t0 << 20) | t1_64;
    t0 = 0x43;
    t1 = 0x24000000;
    *(u64 *)(s4 + 0xa0) = a1_64 | (u64)((u64)((s32)((s32)0x64000000)) | v1_64);
    *(s64 *)(s4 + 0xa8) = t6;
    *(u64 *)(s4 + 0xb0) = t5;
    *(s64 *)(s4 + 0xb8) = t8;
    *(u64 *)(s4 + 0xc0) = t4_64;
    *(s64 *)(s4 + 0xc8) = (s32)t3;
    *(u32 *)(s4 + 0xd0) = 0x8002;
    a3_64 = ((u64)0xffffffff << 0x20) | 0x71f06ff0;
    *(u32 *)(s4 + 0xd4) = 0x24000000;
    *(u32 *)(s4 + 0xd8) = t0;
    *(u32 *)(s4 + 0xdc) = 0;
    *(u64 *)(s4 + 0xe0) = 0;
    *(u64 *)(s4 + 0xe8) = a3_64;
    *(s64 *)(s4 + 0xf0) = (s32)0x1c002000;
    *(u64 *)(s4 + 0xf8) = s5;
    *(u32 *)(s4 + 0x100) = 0x8005;
    *(u32 *)(s4 + 0x104) = 0x10000000;
    *(u32 *)(s4 + 0x108) = s2;
    *(u32 *)(s4 + 0x10c) = 0;
    *(u64 *)(s4 + 0x110) = 0;
    *(u64 *)(s4 + 0x118) = 0x3f;
    *(u64 *)(s4 + 0x120) = *(u64 *)s3;
    *(s64 *)(s4 + 0x128) = s1;
    *(u64 *)(s4 + 0x130) = *(u64 *)(s3 + 0x20);
    *(s64 *)(s4 + 0x138) = s0;
    *(u64 *)(s4 + 0x140) = *(u64 *)(s3 + 0x30);
    *(s64 *)(s4 + 0x148) = t9;
    *(u64 *)(s4 + 0x150) = *(u64 *)(s3 + 0x10);
    *(s64 *)(s4 + 0x158) = t7;
    *(u32 *)(s4 + 0x160) = 0x8003;
    *(u32 *)(s4 + 0x164) = 0x10ab4000;
    *(u32 *)(s4 + 0x168) = s2;
    *(u32 *)(s4 + 0x16c) = 0;
    *(u64 *)(s4 + 0x170) = (u64)((s32)((s32)0x64122a00)) | v1_64;
    *(s64 *)(s4 + 0x178) = t6;
    *(u64 *)(s4 + 0x180) = t5;
    *(s64 *)(s4 + 0x188) = t8;
    *(u64 *)(s4 + 0x190) = t4_64;
    *(s64 *)(s4 + 0x198) = (s32)t3;
    *(u32 *)(s4 + 0x1a0) = 0x8002;
    *(u32 *)(s4 + 0x1a4) = 0x24000000;
    *(u32 *)(s4 + 0x1a8) = t0;
    *(u32 *)(s4 + 0x1ac) = 0;
    *(u64 *)(s4 + 0x1b0) = 0;
    *(u64 *)(s4 + 0x1b8) = a3_64;
    *(s64 *)(s4 + 0x1c0) = (s32)0x1bf02000;
    *(u64 *)(s4 + 0x1c8) = s6;
    s5 = (u32)(s4 + 0x1d0);
    lpMdlPacketMem = s5;
    return;
}


/* DrawFrameFilter @ 0x183360 .. 0x1835F4 (0x294 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: t0: 128-bit web split from its scalar uses
 *   literal: @1027 -> 0x22b2a0
 *   stack: address of the slot at 0x50 escapes at 0x1833a4
 *   stack: address of the slot at 0x40 escapes at 0x18341c
 *   stack: address of the slot at 0x40 escapes at 0x18342c
 *   literal: @1027 initializes the 16-byte local at 0x40
 */


void DrawFrameFilter(void) {
    u32 t4;
    u32 t3;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u64 t2;
    s32 t1;
    u32 a3;
    u32 a2;
    u32 v1;
    u32 v0;
    u64 a1_64;
    u_long128 t0_q;
    u8 stackFrame_50[240] __attribute__((aligned(16)));

    v0 = (u32)L1027;
    s2 = (u8 *)lpMdlPacketMem;
    {
        struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) = {{0x80,
            0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00,
            0x00}};
        v1 = (u32)((u8 *)&stackFrame_40);
        v1 = (u32)lpDrawMng;
        v0 = *(s32 *)((v1 + 0x408));
        s1 = ((u8 *)&stackFrame_50[0]);
        if (v0 == 0) {
            s0 = (u8 *)(s32)(v1 + 0x60);
        } else {
            s0 = (u8 *)(s32)(v1 + 0x150);
        }
        memset((void *)s1, 0, 0xf0);
        *(u32 *)(s1 + 0x10) = 0x7000;
        a2 = -1;
        *(u32 *)(s1 + 0x14) = 0x7200;
        v1 = 0x9000;
        *(u32 *)(s1 + 0x18) = a2;
        v0 = 0x8e00;
        *(u32 *)(s1 + 0x20) = 0x9000;
        *(u32 *)(s1 + 0x24) = 0x8e00;
        *(u32 *)(s1 + 0x28) = a2;
        v0 = *(s32 *)(s1 + 0x10);
        *(u32 *)(s1 + 0x10) = v0 + -8;
        v0 = *(s32 *)(s1 + 0x14);
        *(u32 *)(s1 + 0x14) = v0 + -4;
        v0 = *(s32 *)(s1 + 0x20);
        *(u32 *)(s1 + 0x20) = v0 + -8;
        v0 = *(s32 *)(s1 + 0x24);
        *(u32 *)(s1 + 0x24) = v0 + -4;
        memcpy((void *)(s1 + 0x50), (const void *)((u8 *)&stackFrame_40), 0x10);
        memcpy((void *)(s1 + 0x60), (const void *)((u8 *)&stackFrame_40), 0x10);
        *(u32 *)(s1 + 0x90) = 0;
        *(u32 *)(s1 + 0x94) = 0;
        *(u32 *)(s1 + 0xa0) = 0x2000;
        a2 = 0x10000000;
        *(u32 *)(s1 + 0xa4) = 0x1c00;
        *(u32 *)s2 = 0x10000000 | 0x12;
        v1 = 0x51000000;
        *(u32 *)(s2 + 4) = 0;
        *(u32 *)(s2 + 8) = 0;
        *(u32 *)(s2 + 0xc) = 0x51000000 | 0x12;
        *(u32 *)(s2 + 0x10) = 7;
        *(u32 *)(s2 + 0x14) = 0x10000000;
        *(u32 *)(s2 + 0x18) = 0xe;
        t2 = (u64)(u32)1 << 0x20;
        *(u32 *)(s2 + 0x1c) = 0;
        v1 = 0x30000;
        *(u64 *)(s2 + 0x20) = 0;
        *(s64 *)(s2 + 0x28) = (s32)0x3f;
        t3 = *(u8 *)(s0 + 0x13);
        t4 = *(u16 *)(s0 + 0x10);
        t3 &= 0xf;
        t4 &= 0x1ff;
        *(u64 *)(s2 + 0x30) = ((u64)t4 | ((u64)t3 << 0x18)) | t2;
        *(s64 *)(s2 + 0x38) = (s32)0x4e;
        *(u64 *)(s2 + 0x40) = (u32)(0x30000 | 0x3001);
        *(s64 *)(s2 + 0x48) = (s32)0x47;
        *(u64 *)(s2 + 0x50) = (u64)((s32)((s32)0x64)) | (u64)((u64)(u32)0x40 << 0x20);
        *(s64 *)(s2 + 0x58) = (s32)0x42;
        *(s64 *)(s2 + 0x60) = (s32)0x20;
        *(s64 *)(s2 + 0x68) = (s32)0x14;
        v1 = *(u16 *)s0;
        a1_64 = (s32)((s32)((u32)(v1 & 0x1ff) << 0xb) / 0x40);
        a2 = 6;
        v1 = 0x64120000;
        *(u64 *)(s2 + 0x70) = a1_64 | (u64)((u64)((s32)((s32)0x64120000)) | (u64)((u64)(s32)a2 <<
            0x20));
        t1 = 8;
        *(s64 *)(s2 + 0x78) = (s32)a2;
        *(s64 *)(s2 + 0x80) = (s32)5;
        v1 = 0x308b0000;
        *(s64 *)(s2 + 0x88) = t1;
        *(u32 *)(s2 + 0x90) = 2;
        *(u32 *)(s2 + 0x94) = 0x308b0000 | 0x4000;
        a3 = 0x8002;
        *(u32 *)(s2 + 0x98) = 0x413;
        a2 = 0x10000000;
        *(u32 *)(s2 + 0x9c) = 0;
        t0_q = *(u_long128 *)(s1 + 0x90);
        *(u_long128 *)(s2 + 0xa0) = t0_q;
        t0_q = *(u_long128 *)(s1 + 0x50);
        *(u_long128 *)(s2 + 0xb0) = t0_q;
        t0_q = *(u_long128 *)(s1 + 0x10);
        *(u_long128 *)(s2 + 0xc0) = t0_q;
        t0_q = *(u_long128 *)(s1 + 0xa0);
        *(u_long128 *)(s2 + 0xd0) = t0_q;
        t0_q = *(u_long128 *)(s1 + 0x60);
        *(u_long128 *)(s2 + 0xe0) = t0_q;
        t0_q = *(u_long128 *)(s1 + 0x20);
        *(u_long128 *)(s2 + 0xf0) = t0_q;
        *(u32 *)(s2 + 0x100) = 0x8002;
        *(u32 *)(s2 + 0x104) = 0x10000000;
        *(u32 *)(s2 + 0x108) = 0xe;
        *(u32 *)(s2 + 0x10c) = 0;
        a1_64 = *(u64 *)(s0 + 0x10);
        *(u64 *)(s2 + 0x110) = a1_64;
        *(s64 *)(s2 + 0x118) = (s32)0x4e;
        *(u64 *)(s2 + 0x120) = 0;
        *(s64 *)(s2 + 0x128) = t1;
        lpMdlPacketMem = (s32)(s2 + 0x130);
        return;
    }
}








void DrawBrightnessFilter(void) {
    u8 *packet;
    u32 index;
    u8 *env;
    u32 right, left;
    u64 saved;
    u32 value;
    s64 brightness;
    u32 draw = (u32)lpDrawMng;
    packet = (u8 *)lpMdlPacketMem;
    if (*(s32 *)(draw + 0x408) == 0) env = (u8 *)(draw + 0x60);
    else env = (u8 *)(draw + 0x150);
    if (*(s8 *)(GameSt + 0x1e) != 0) {
        *(u32 *)packet = 0x10000031;
        *(u32 *)(packet + 4) = 0; *(u32 *)(packet + 8) = 0;
        *(u32 *)(packet + 0xc) = 0x51000031;
        *(u32 *)(packet + 0x10) = 6;
        *(u32 *)(packet + 0x14) = 0x10ab4000;
        *(u32 *)(packet + 0x18) = 14; *(u32 *)(packet + 0x1c) = 0;
        *(u64 *)(packet + 0x20) = 0; *(u64 *)(packet + 0x28) = 63;
        *(u64 *)(packet + 0x30) = 0; *(u64 *)(packet + 0x38) = 71;
        *(u64 *)(packet + 0x40) = (u64)(s32)((*(u16 *)env & 511) << 5) | 0x664120000ULL;
        *(u64 *)(packet + 0x48) = 6;
        *(u64 *)(packet + 0x50) = 0; *(u64 *)(packet + 0x58) = 20;
        brightness = *(s8 *)(GameSt + 0x1e);
        if ((s32)brightness > 0) {
            *(u64 *)(packet + 0x60) = ((u64)brightness << 32) | 0x68;
            packet += 0x68;
        } else {
            s32 negative = (s32)brightness;
            negative = negative < 0 ? -negative : negative;
            *(u64 *)(packet + 0x60) = ((u64)negative << 32) | 0x62;
            packet += 0x68;
        }
        *(u64 *)packet = 0x42;
        *(u64 *)(packet + 8) = 0x3f80000080808080ULL;
        *(u64 *)(packet + 0x10) = 1;
        packet += 0x18;
        index = 0; right = 63; left = 0;
        saved = 0xffffffff72007000ULL;
        value = 0x1c102000;
        do {
            *(u32 *)packet = 1; *(u32 *)(packet + 4) = 0x10000000;
            *(u32 *)(packet + 8) = 14; *(u32 *)(packet + 0xc) = 0;
            *(u64 *)(packet + 0x10) = ((u64)(s32)left | ((u64)(s32)right << 16)) | 0x01bf000000000000ULL;
            right += 64;
            left += 64;
            *(u64 *)(packet + 0x18) = 64;
            *(u32 *)(packet + 0x20) = 2; *(u32 *)(packet + 0x24) = 0x24000000;
            *(u32 *)(packet + 0x28) = 0x43; *(u32 *)(packet + 0x2c) = 0;
            *(u64 *)(packet + 0x30) = 0; *(u64 *)(packet + 0x38) = saved;
            *(u64 *)(packet + 0x40) = value;
            *(u64 *)(packet + 0x48) = 0xffffffff8e009000ULL;
            index++; packet += 0x50;
        } while ((s32)index < 8);
        *(u32 *)packet = 1; *(u32 *)(packet + 4) = 0x10000000;
        *(u32 *)(packet + 8) = 14; *(u32 *)(packet + 0xc) = 0;
        *(u64 *)(packet + 0x10) = *(u64 *)(env + 0x30);
        *(u64 *)(packet + 0x18) = 64;
        lpMdlPacketMem = (s32)(packet + 0x20);
    }
}


/* CopyFrameBuffer @ 0x182FB0 .. 0x183120 (0x170 bytes, frame 0x10) */


static void CopyFrameBuffer(void) {
    u32 t4;
    u8 *t0;
    s32 a3;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *v0;

    a1 = (u32)lpDrawMng;
    a0 = *(s32 *)((a1 + 0x408));
    v0 = DMABuf_1056;
    if (a0 == (u32)1) {
        t0 = (u8 *)(s32)(a1 + 0x60);
    } else {
        t0 = (u8 *)(s32)(a1 + 0x150);
    }
    v1 = 0x51000000;
    a3 = 0x10000000;
    *(u32 *)v0 = 0x10000000 | 6;
    *(u32 *)(v0 + 4) = 0;
    *(u32 *)(v0 + 8) = 0;
    *(u32 *)(v0 + 0xc) = 0x51000000 | 6;
    *(u32 *)(v0 + 0x10) = 5;
    a0 = 0x1080000;
    *(u32 *)(v0 + 0x14) = 0x10000000;
    *(u32 *)(v0 + 0x18) = 0xe;
    *(u32 *)(v0 + 0x1c) = 0;
    *(u64 *)(v0 + 0x20) = 0;
    *(s64 *)(v0 + 0x28) = (s32)0x3f;
    t4 = *(u16 *)t0;
    v1 = 0x70000000;
    *(u64 *)(v0 + 0x30) = (u64)((s32)((s32)((u32)(t4 & 0x1ff) << 5))) |
        (u64)((u64)((s32)((s32)0x1080000)) | (u64)((u64)(s32)(0x1080000 | 0x2a00) << 0x20));
    *(s64 *)(v0 + 0x38) = (s32)0x50;
    *(u64 *)(v0 + 0x40) = 0;
    *(s64 *)(v0 + 0x48) = (s32)0x51;
    *(u64 *)(v0 + 0x50) = (u64)((s32)((s32)0x200)) | (u64)((u64)(u32)0x1c0 << 0x20);
    *(s64 *)(v0 + 0x58) = (s32)0x52;
    *(s64 *)(v0 + 0x60) = (s32)2;
    *(s64 *)(v0 + 0x68) = (s32)0x53;
    *(u32 *)(v0 + 0x70) = 0x70000000;
    *(u32 *)(v0 + 0x74) = 0;
    *(u32 *)(v0 + 0x78) = 0;
    *(u32 *)(v0 + 0x7c) = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    a0 = (u32)DMABuf_1056;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009030 = (u32)DMABuf_1056;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}





/* ClearFrameBuffer @ 0x182E00 .. 0x182FB0 (0x1b0 bytes, frame 0x10) */


void ClearFrameBuffer(void) {
    u32 v1;
    u32 v0;

    DMABuf_1074[1] = 0;
    v0 = 0x10000005;
    v1 = 2;
    DMABuf_1074[2] = 0;
    DMABuf_1074[7] = 0;
    *(u32 *)DMABuf_1074 = 0x10000005;
    *(u64 *)(DMABuf_1074 + 8) = 0;
    v0 = 0x51000005;
    DMABuf_1074[3] = 0x51000005;
    DMABuf_1074[4] = v1;
    v0 = 0x10034000;
    DMABuf_1074[0x10] = v1;
    DMABuf_1074[5] = 0x10034000;
    DMABuf_1074[6] = 0xe;
    *(s64 *)(DMABuf_1074 + 0xa) = (s32)0x47;
    v0 = 0x3f800000;
    DMABuf_1074[0x13] = 0;
    v0 = 0x8000;
    DMABuf_1074[0x19] = 0;
    DMABuf_1074[0x1a] = 0;
    DMABuf_1074[0x1b] = 0;
    *(u64 *)(DMABuf_1074 + 0xc) = (u64)((u64)0x8000 << 0x10) | (u64)((u64)(u32)0x3f800000 << 0x20);
    *(s64 *)(DMABuf_1074 + 0xe) = (s32)1;
    v0 = 0x14000000;
    DMABuf_1074[0x11] = 0x14000000;
    DMABuf_1074[0x12] = 4;
    v0 = 0x72000000;
    v0 = -0x71ff7000;
    *(u64 *)(DMABuf_1074 + 0x14) = (u64)((u32)(0x72000000 | 0x7000)) | (u64)((u64)(s32)-1 << 0x20);
    *(u64 *)(DMABuf_1074 + 0x16) = (s32)-0x71ff7000;
    v0 = 0x70000000;
    DMABuf_1074[0x18] = 0x70000000;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009030 = (u32)DMABuf_1074;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}



/* ScaleFrameBuffer @ 0x182B80 */

void ScaleFrameBuffer(signed int Width, signed int Height, signed int Offset, unsigned char Alpha) {
    s32 hh;
    s32 hw;
    u32 v1;

    DMABuf_1095[0] = 0x1000000a;
    DMABuf_1095[1] = 0;
    DMABuf_1095[2] = 0;
    DMABuf_1095[3] = 0x5100000a;
    DMABuf_1095[4] = 6;
    DMABuf_1095[5] = 0x10ab4000;
    DMABuf_1095[6] = 0xe;
    DMABuf_1095[7] = 0;
    *(u64 *)(DMABuf_1095 + 8) = 0;
    *(s64 *)(DMABuf_1095 + 0xa) = (s32)0x3f;
    *(u64 *)(DMABuf_1095 + 0xc) = (u64)(s32)0x64122a00 | ((u64)6 << 0x20);
    *(s64 *)(DMABuf_1095 + 0xe) = (s32)6;
    *(u64 *)(DMABuf_1095 + 0x10) = 0;
    *(s64 *)(DMABuf_1095 + 0x12) = (s32)0x14;
    *(u64 *)(DMABuf_1095 + 0x14) = 0;
    *(s64 *)(DMABuf_1095 + 0x16) = (s32)0x47;
    *(u64 *)(DMABuf_1095 + 0x18) = ((u64)(u32)Alpha << 0x20) | (u64)0x64;
    *(s64 *)(DMABuf_1095 + 0x1a) = (s32)0x42;
    *(u64 *)(DMABuf_1095 + 0x1c) = (u64)((u64)0x8080 << 0x10 | (u64)0x8080) | ((u64)(u32)0x3f800000 << 0x20);
    *(s64 *)(DMABuf_1095 + 0x1e) = (s32)1;
    DMABuf_1095[0x20] = 2;
    DMABuf_1095[0x21] = 0x24000000;
    DMABuf_1095[0x22] = 0x43;
    DMABuf_1095[0x23] = 0;
    *(u64 *)(DMABuf_1095 + 0x24) = 0;
    hh = Height / 2;
    hw = Width / 2;
    *(u64 *)(DMABuf_1095 + 0x26) = (u64)((u64)((s32)((0x800 - hw) << 4)) | ((u64)(s32)(((Offset + 0x800) - hh) << 4) << 0x10)) | ((u64)(s32)-1 << 0x20);
    *(u64 *)(DMABuf_1095 + 0x28) = (u32)(0x1c100000 | 0x2000);
    *(u64 *)(DMABuf_1095 + 0x2a) = (u64)((u64)((s32)((hw + 0x800) << 4)) | ((u64)(s32)(((Offset + 0x800) + hh) << 4) << 0x10)) | ((u64)(s32)-1 << 0x20);
    DMABuf_1095[0x2c] = 0x70000000;
    DMABuf_1095[0x2d] = 0;
    DMABuf_1095[0x2e] = 0;
    DMABuf_1095[0x2f] = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile u32 *)0x10009030 = (u32)DMABuf_1095;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
}

static void DrawNoiseEffect(unsigned char a0 /* r4 */) {
    u8 *t3;
    s32 t1;
    s32 a2;
    s32 a1;
    u32 v1;
    u8 *v0;
    u64 v1_64;
    u32 a0_2;
    u8 stackFrame[16] __attribute__((aligned(16)));

    t1 = 0x20;
    v1 = 0x200;
    v0 = (u8 *)DMABuf_1139;
    t3 = NoiseImageTex;
    v0 = (u8 *)LoadImage(0x2a00, 1, 0x14, 0, 0, t1, t1, (void *)NoiseImageTex, 0x200, (unsigned int
        *)DMABuf_1139);
    v1 = 0x20;
    a2 = 2;
    t3 = (u8 *)NoiseImageClut;
    v0 = (u8 *)LoadImage(0x2a02, 1, a2, 0, 0, 8, a2, (void *)NoiseImageClut, 0x20, (unsigned int
        *)v0);
    a0_2 = 0x1000000a;
    *(u32 *)v0 = 0x1000000a;
    *(u32 *)(v0 + 4) = 0;
    v1 = 0x5100000a;
    *(u32 *)(v0 + 8) = 0;
    *(u32 *)(v0 + 0xc) = 0x5100000a;
    t1 = 6;
    v1 = 0x102b0000;
    *(u32 *)(v0 + 0x10) = t1;
    *(u32 *)(v0 + 0x14) = 0x102b0000 | 0x4000;
    *(u32 *)(v0 + 0x18) = 0xe;
    *(u32 *)(v0 + 0x1c) = 0;
    v1 = 0x20154045;
    *(u64 *)(v0 + 0x20) = 0;
    *(s64 *)(v0 + 0x28) = (s32)0x3f;
    v1 = 0x55406a00;
    a1 = 0x42;
    *(u64 *)(v0 + 0x30) = ((u64)0x20154045 << 0x20) | 0x55406a00;
    *(s64 *)(v0 + 0x38) = t1;
    v1 = 0x3f800000;
    *(u64 *)(v0 + 0x40) = 0;
    *(s64 *)(v0 + 0x48) = (s32)0x14;
    v1 = 0x8080;
    *(u64 *)(v0 + 0x50) = 0;
    v1_64 = (u64)0x8080 << 0x10;
    *(s64 *)(v0 + 0x58) = (s32)0x47;
    *(u64 *)(v0 + 0x60) = (u64)((u64)(u32)(u8)a0 << 0x20) | (u64)(0x64);
    *(s64 *)(v0 + 0x68) = a1;
    *(u64 *)(v0 + 0x70) = (u64)(v1_64 | (u64)(0x8080)) | (u64)((u64)(u32)0x3f800000 << 0x20);
    *(s64 *)(v0 + 0x78) = (s32)1;
    *(u32 *)(v0 + 0x80) = 2;
    a0_2 = 0x24000000;
    *(u32 *)(v0 + 0x84) = 0x24000000;
    *(u32 *)(v0 + 0x88) = a1;
    *(u32 *)(v0 + 0x8c) = 0;
    v1 = 0x72007000;
    *(u32 *)(v0 + 0x90) = 0;
    v1_64 = ((u64)0xffffffff << 0x20) | 0x72007000;
    *(u32 *)(v0 + 0x94) = 0;
    *(u64 *)(v0 + 0x98) = v1_64;
    v1 = 0x41200000;
    *(u32 *)(v0 + 0xa0) = 0x41200000;
    v1 = 0x40e00000;
    *(u32 *)(v0 + 0xa4) = 0x40e00000;
    v1 = -0x72000000;
    *(u64 *)(v0 + 0xa8) = (s32)(-0x72000000 | 0x9000);
    v1 = 0x70000000;
    *(u32 *)(v0 + 0xb0) = 0x70000000;
    *(u32 *)(v0 + 0xb4) = 0;
    *(u32 *)(v0 + 0xb8) = 0;
    *(u32 *)(v0 + 0xbc) = 0;
    FlushCache(0);
    DrawNoiseEffect__inl0();
    *(volatile u32 *)0x10009020 = 0;
    a0_2 = (u32)DMABuf_1139;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile void **)0x10009030 = (void *)DMABuf_1139;
    *(volatile u32 *)0x10009000 = 0x145;
    DrawNoiseEffect__inl0();
    return;
}
void InitTVEffect(void) {
    s32 high;
    u8 *texture = NoiseImageTex;
    u16 *clut = NoiseImageClut;
    s32 i;
    *(u32 *)TVEffectMng = 0;
    TVEffectMng[1] = 0;
    *(u8 *)TVSwitch = 0;
    TVNoise[0] = 0;
    *(u8 *)TVFlash = 0;
    for (i = 0; i < 512; ++i) {
        high = (rand() & 15) << 4;
        *texture++ = high | (rand() & 15);
    }
    for (i = 0; i < 16; ++i) {
        clut[i] = i | ((i << 10) | (i << 5));
    }
}


/* CheckTVEffect @ 0x1825E0 .. 0x1827CC (0x1ec bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x182680 writes a register its branch at 0x18267c reads
 *   fpu: float literal 0x41200000 at 0x182794
 *   fpu: float literal 0x42c80000 at 0x18279c
 *   cfg: kept branch: 0x182608 if (..) goto .L00182628
 *   cfg: kept goto: 0x182618 -> .L001827C0
 */


void CheckTVEffect(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    s32 v0;

    v1 = *(s32 *)(TVEffectMng + 1);
    if (v1 == 0) {
        v1 = 1;
        a0 = GameSt[0xf];
        if (a0 != v1) {
            v1 = 2;
            a0 = GameSt[5];
            if (a0 != v1) {
                goto _L00182628;
            }
        }
        v1 = *(s32 *)TVEffectMng;
        v1 = v1 + 1;
        *(u32 *)TVEffectMng = v1;
        goto _L001827C0;
        _L00182628:;
        v1 = *(s32 *)TVEffectMng;
        v1 = (s32)v1 < (s32)0x2a30;
        if (v1 == 0) {
            v0 = rand();
            v1 = 0xa;
            v1 = v0 % (s32)(0xa);
            if (v1 == 0) {
                v0 = rand();
                a0 = 3;
                v1 = 2;
                a0 = v0 % (s32)(3);
                v1 = 1;
                switch (a0) {
                case 0:
                    *(u8 *)TVSwitch = v1;
                    v0 = 0x200;
                    a0 = 0x1b;
                    TVSwitch[1] = 0;
                    a1 = 0x64;
                    *(u32 *)(TVSwitch + 4) = v0;
                    v0 = 0x1c0;
                    *(u32 *)(TVSwitch + 8) = v0;
                    v0 = 0x80;
                    TVSwitch[3] = v0;
                    SND_Play2D(a0, a1, 0);
                    break;
                case 1:
                    TVNoise[0] = v1;
                    a0 = 0x1d;
                    a1 = 0x64;
                    TVNoise[1] = 0;
                    TVNoise[3] = 0;
                    v0 = SND_Play2D(a0, a1, 0);
                    *(u32 *)(TVNoise + 4) = v0;
                    break;
                case 2:
                    v0 = 1;
                    *(u8 *)TVFlash = v0;
                    v0 = 0x78;
                    TVFlash[1] = v0;
                    v0 = 5;
                    TVFlash[2] = v0;
                    v0 = rand();
                    v1 = 5;
                    v0 = v0 % (s32)(5);
                    TVFlash[3] = v0;
                    v0 = rand();
                    v1 = 0xa;
                    v0 = v0 % (s32)(0xa);
                    TVFlash[4] = v0;
                    v0 = rand();
                    v1 = 0xa;
                    a0 = 0x1c;
                    a1 = 0x64;
                    v0 = v0 % (s32)(0xa);
                    TVFlash[5] = v0;
                    SND_Play2D(a0, a1, 0);
                    PadSetVib(0, 10.0f, 100.0f, 0, 1, 0);
                }
                v1 = 1;
                TVEffectMng[1] = v1;
            }
        }
        *(u32 *)TVEffectMng = 0;
    }
    _L001827C0:;
    return;
}
void DrawTVEffect(void) {
    u32 v0;
    u8 a3;
    s32 xt1;
    s32 a1;
    u32 s2;
    u8 *s1;
    s32 v1;
    u8 stackFrame_50[240] __attribute__((aligned(16)));

    v1 = TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_USE_E3AF5E4B / 1)];
    if (v1 != 0) {
        v0 = (u32)GetTexMngByName((void *)0, "fe_no.tm2");
        a1 = (u32)"fe_no.tm2";
        if (v0 != 0) {
            {
                struct stackFrame_40 { u8 b[16]; } stackFrame_40 __attribute__((aligned(16))) =
                    {{0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x60,
                    0x00, 0x00, 0x00}};
                xt1 = TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8 / 1)];
                *(u32 *)((u8 *)&stackFrame_40 + 0xc) = (u32)xt1;
                v1 = *(s8 *)(TVFlash + (DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTY_99755BA5 / 1));
                a1 = *(s8 *)(TVFlash + (DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTX_1A50B59C / 1));
                SetSprite((void *)((u8 *)&stackFrame_50[0]), -0x100 - a1, (-0xe0) - v1, 0x20a,
                    0x1ca, (signed int *)(u8 *)((u8 *)&stackFrame_40), *(u16 *)(((u8 *)2 + v0)), 1);
                ((u32 *)stackFrame_50)[45] = 0x3f600000;
                MakeAndKickSpritePacket((void *)((u8 *)&stackFrame_50[0]));
                v0 = 0x3f600000;
            }
        }
        v1 = TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD / 1)];
        if (v1 != 0) {
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD / 1)] = v1 + -1;
        } else {
            v1 = 0xa;
            v0 = rand();
            v1 = 5;
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_COUNTER_6DF0E8FD / 1)] = (s32)((s32)v0) % 5;
            v0 = rand();
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTX_1A50B59C / 1)] = ((s32)v0) % 0xa;
            v0 = rand();
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_SHIFTY_99755BA5 / 1)] = (((((s32)v0)))) % 0xa;
            v1 = 0xa;
        }
        v1 = TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8 / 1)];
        if ((s32)2 < v1) {
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_ALPHA_F7D646B8 / 1)] = v1 + -2;
        } else {
            TVFlash[(DCOMP_OFF_STRUCT_DW_1126966_FIELDS_USE_E3AF5E4B / 1)] = 0;
        }
    }
    v1 = *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8);
    if (v1 != 0) {
        v1 = 2;
        xt1 = *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136);
        switch (xt1) {
        case 0:
            v1 = *(u8 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62 + TVNoise);
            if ((s32)v1 <= 0x63) {
                *(u8 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62 + TVNoise) = 0xa + v1;
                break;
            } else {
                *(u8 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136 + TVNoise) = xt1 + 1;
                v0 = rand();
                v1 = 0x1e;
                *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5) = (s32)v0 %
                    0x1e;
                break;
            }
        case 1:
            v1 = *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5);
            if (v1 != 0) {
                *(u8 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_COUNTER_294C4FF5 + TVNoise) = v1 + -1;
                break;
            } else {
                *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_MODE_0B452136) = xt1 + 1;
                break;
            }
        case 2:
            v1 = *(u8 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62 + TVNoise);
            if (0xa < v1) {
                *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62) = v1 + -0xa;
                break;
            } else {
                xt1 = *(s32 *)(DCOMP_OFF_STRUCT_DW_1125647_FIELDS_VOICEHDL_B93180DE + TVNoise);
                *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8) = 0;
                SND_Stop((s32)xt1);
            }
        }
        v1 = *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_USE_1ADF8CA8);
        if (v1 != 0) {
            xt1 = 0;
            s1 = NoiseImageTex;
            do {
                v0 = rand();
                s2 = (v0 & 0xf) << 4;
                v0 = rand();
                xt1 = xt1 + 1;
                *(u8 *)s1 = s2 | (u32)(v0 & 0xf);
                v0 = xt1 < ((0x200));
                s1 = (u8 *)(s1 + 1);
            } while (v0 != 0);
            xt1 = *(u8 *)(TVNoise + DCOMP_OFF_STRUCT_DW_1125647_FIELDS_ALPHA_43C2AC62);
            DrawNoiseEffect(xt1);
        }
    }
    v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C / 1)];
    if (v1 != 0) {
        v1 = 3;
        xt1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)];
        switch (xt1) {
        case 0:
            v1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1));
            if (v1 > (s32)0x28) {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1)) = v1
                    + -0x28;
                break;
            } else {
                v1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1));
                if (v1 > (s32)0x28) {
                    *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1)) =
                        v1 + -0x28;
                    break;
                } else {
                    xt1 = 0x3c;
                    v0 = rand();
                    TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)] = (s32)v0 %
                        0x3c;
                    v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)];
                    TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)] = 1 + v1;
                    break;
                }
            }
        case 1:
            v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)];
            *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1)) = 0;
            *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1)) = 0;
            if (v1 != 0) {
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)] = v1 + -1;
                break;
            } else {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1)) =
                    0x19c;
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1)) =
                    0x15c;
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)] = 0;
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)] = 1 + xt1;
                break;
            }
        case 2:
            if ((s32)*(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1))
                <= (s32)0x1fb) {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1)) =
                    *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF /
                    1)) + 4;
            } else {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1)) =
                    0x200;
            }
            if (*(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1))
                <= 0x1bb) {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1)) =
                    *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 /
                    1)) + 4;
            } else {
                *(u32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1)) =
                    0x1c0;
            }
            v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)];
            if ((s32)v1 <= (s32)0x7b) {
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)] = v1 + 4;
                break;
            } else {
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)]++;
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)] = 8;
                break;
            }
        case 3:
            v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)];
            if (v1 != 0) {
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_COUNTER_C8B48E60 / 1)] = v1 + -1;
                break;
            } else {
                TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C / 1)] = 0;
            }
        }
        v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_USE_C70A9E9C / 1)];
        if (v1 != 0) {
            CopyFrameBuffer();
            ClearFrameBuffer();
            v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)];
            if (v1 != 3) {
                xt1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1));
                a1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1));
                a3 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)];
                ScaleFrameBuffer(xt1, a1, 0, a3);
            } else {
                a1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1));
                a3 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)];
                xt1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1));
                ScaleFrameBuffer((s32)xt1, a1, -0xa, a3);
            }
            v1 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_MODE_84DA19A4 / 1)];
            if ((s32)v1 >= (s32)2) {
                v0 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1));
                xt1 = v0;
                a1 = xt1 / 2;
                v0 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)];
                xt1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1));
                ScaleFrameBuffer(xt1, (u32)a1, 0x64, v0 >> 1);
                v0 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_HEIGHT_86A1D467 / 1));
                a1 = (s32)v0 / 4;
                v0 = TVSwitch[(DCOMP_OFF_STRUCT_DW_1123026_FIELDS_ALPHA_AABF3DF4 / 1)];
                xt1 = *(s32 *)(TVSwitch + (DCOMP_OFF_STRUCT_DW_1123026_FIELDS_WIDTH_12DC51BF / 1));
                ScaleFrameBuffer(xt1, a1, -0x32, v0 >> 2);
            }
        }
    }
    return;
}
