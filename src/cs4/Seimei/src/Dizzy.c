#include "common.h"




extern void StopVagStm(unsigned char);
extern void SetGoToTitleFade(void);
extern void FontDrawBegin(int);
typedef struct { unsigned char r, g, b, a; } GO_COLOR;
extern void SetFontColor(GO_COLOR);
extern signed int FsFontSetScale(float, float);
extern unsigned short *KnMsgMng_GetMsgStr(signed int);
extern signed int FsFontGetSize(float *, float *, unsigned short *, unsigned short);
extern void FontPrintXY(float, float, char *, ...);
extern void FontDrawEnd(void);
extern signed int CheckVagStmState(unsigned char);
extern void PlayBgmVagStm(signed int, signed int);
static unsigned int * DrawGameOverTexture(unsigned int *lpPacket, unsigned char Alpha);
static unsigned int *DrawGameOverTexture(unsigned int *lpPacket, unsigned char Alpha);
extern u8 *lpDrawMng;
extern unsigned int *lpMdlPacketMem;
extern u8 GameOverFilterMng[];
extern u8 GameSt[];
extern u8 GameOverMng[4];

struct GO_PadBit {
    unsigned short select : 1; unsigned short L3 : 1; unsigned short R3 : 1; unsigned short start : 1;
    unsigned short Lup : 1; unsigned short Lright : 1; unsigned short Ldown : 1; unsigned short Lleft : 1;
    unsigned short L2 : 1; unsigned short R2 : 1; unsigned short L1 : 1; unsigned short R1 : 1;
    unsigned short Rup : 1; unsigned short Rdown : 1; unsigned short Rright : 1; unsigned short Rleft : 1;
};
struct GO_Pad { u8 pad[0x20]; union { unsigned short word; struct GO_PadBit bit; } edge; };
extern struct GO_Pad *lpPadData[2];

struct GO_DizzyMng {
    unsigned char Mode; unsigned char Flag; unsigned char Alpha; unsigned char Counter;
    float Rate; float Max; float Add;
    short PosX; short PosY; short HalfSizeW; short HalfSizeH;
    void *lpMdlMng;
};
struct GO_Mng { short Counter; unsigned char BGM; unsigned char FontAlpha; };
struct GO_Frame { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
struct GO_Zbuf { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
struct GO_DrawEnv { struct GO_Frame frame1; unsigned long frame1addr; struct GO_Zbuf zbuf1; long zbuf1addr; };

#define GO_GAMEST_PADPORT (GameSt[0xa])
#define GO_BGM ((GameOverMng)[2])
#define GO_FONTALPHA ((GameOverMng)[3])
#define GO_SET_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))
#define GO_SET_ST(s, t) ((u_long)(s) | ((u_long)(t) << 32))

static inline int GameOverCheckPad(void) {
    struct GO_Pad *lpPad = lpPadData[GO_GAMEST_PADPORT];

    if (lpPad->edge.bit.start || lpPad->edge.bit.Rright) {
        if (GO_BGM) {
            StopVagStm(0);
        }
        SetGoToTitleFade();
        return 1;
    }
    return 0;
}
void * SetDizzyFilter(unsigned char a0 , signed short a1 , signed short a2 , signed short a3 , signed short t0 );


/* SetGameOver @ 0x178140 .. 0x178204 (0xc4 bytes, frame 0x10) */

extern void * SetDizzyFilter(unsigned char, signed short, signed short, signed short, signed short);
extern void FECard_Enable_Draw(signed int);
extern void SND_VoiceFadeOffAll(void);
extern signed int SND_SecRemoveMap(void);
extern signed int CheckVagStmState(unsigned char);
extern void PlayBgmVagStm(signed int, signed int);
extern signed int SetVagStmFade(unsigned char, unsigned char, signed int);
extern u8 GameOverFilterMng[];
extern u8 GameSt[];
extern u8 GameOverMng[4];

/* InitDizzyWorm @ 0x178210 .. 0x1784C4 (0x2b4 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3a83126f at 0x1782d8
 *   fpu: float literal 0x40490fdb at 0x1782ec
 *   fpu: float literal 0x40c90fdb at 0x1782f0
 *   fpu: mtc1 reinterprets v0 at 0x1782f8
 *   fpu: float literal 0x3a83126f at 0x178338
 *   fpu: mtc1 reinterprets v0 at 0x178340
 *   fpu: float literal 0x3a83126f at 0x178380
 *   fpu: mtc1 reinterprets v0 at 0x178388
 *   cfg: loop body is not one contiguous region: .L00178258
 */

extern int rand();
extern u32 lpDebugParam;
extern u8 DizzyWorm[];
extern u8 DizzyWormBase[];

/* MakeCircleFrameTexture @ 0x1784E0 .. 0x178868 (0x388 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1597 is the string 'filter01.tm2'
 *   cfg: loop body is not one contiguous region: .L001786F0
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern void * GetTexMngByName(void *, char *);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
extern u8 *lpDrawMng;
extern u8 DizzyFilterMng[];

struct dw_969538_fields;
#ifndef PROTO_DW_972256_FIELDS
#define PROTO_DW_972256_FIELDS
struct dw_972256_fields { unsigned char Mode; unsigned char Flag; unsigned char Alpha; unsigned char Counter; float Rate; float Max; float Add; short PosX; short PosY; short HalfSizeW; short HalfSizeH; struct dw_969538_fields *lpMdlMng; };
#endif
#ifndef PROTO_DW_968811_FIELDS
#define PROTO_DW_968811_FIELDS
struct dw_968811_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_976784_FIELDS
#define PROTO_DW_976784_FIELDS
struct dw_976784_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_969214_FIELDS
#define PROTO_DW_969214_FIELDS
struct dw_969214_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_978254_FIELDS
#define PROTO_DW_978254_FIELDS
struct dw_978254_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_977575_FIELDS
#define PROTO_DW_977575_FIELDS
struct dw_977575_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_966186_FIELDS
#define PROTO_DW_966186_FIELDS
struct dw_966186_fields { struct dw_968811_fields pmode; struct dw_976784_fields smode2; struct dw_969214_fields dispfb; struct dw_978254_fields display; struct dw_977575_fields bgcolor; };
#endif
#ifndef PROTO_DW_967390_FIELDS
#define PROTO_DW_967390_FIELDS
struct dw_967390_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_975733_FIELDS
#define PROTO_DW_975733_FIELDS
struct dw_975733_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_983333_FIELDS
#define PROTO_DW_983333_FIELDS
struct dw_983333_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_980656_FIELDS
#define PROTO_DW_980656_FIELDS
struct dw_980656_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_972815_FIELDS
#define PROTO_DW_972815_FIELDS
struct dw_972815_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_966621_FIELDS
#define PROTO_DW_966621_FIELDS
struct dw_966621_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_982245_FIELDS
#define PROTO_DW_982245_FIELDS
struct dw_982245_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_968693_FIELDS
#define PROTO_DW_968693_FIELDS
struct dw_968693_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_977835_FIELDS
#define PROTO_DW_977835_FIELDS
struct dw_977835_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_966737_FIELDS
#define PROTO_DW_966737_FIELDS
struct dw_966737_fields { struct dw_975733_fields frame1; unsigned long frame1addr; struct dw_983333_fields zbuf1; long zbuf1addr; struct dw_980656_fields xyoffset1; long xyoffset1addr; struct dw_972815_fields scissor1; long scissor1addr; struct dw_966621_fields prmodecont; long prmodecontaddr; struct dw_982245_fields colclamp; long colclampaddr; struct dw_968693_fields dthe; long dtheaddr; struct dw_977835_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_985873_FIELDS
#define PROTO_DW_985873_FIELDS
struct dw_985873_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_968472_FIELDS
#define PROTO_DW_968472_FIELDS
struct dw_968472_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_981070_FIELDS
#define PROTO_DW_981070_FIELDS
struct dw_981070_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_978654_FIELDS
#define PROTO_DW_978654_FIELDS
struct dw_978654_fields { struct dw_977835_fields testa; long testaaddr; struct dw_985873_fields prim; long primaddr; struct dw_968472_fields rgbaq; long rgbaqaddr; struct dw_981070_fields xyz2a; long xyz2aaddr; struct dw_981070_fields xyz2b; long xyz2baddr; struct dw_977835_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_982580_FIELDS
#define PROTO_DW_982580_FIELDS
struct dw_982580_fields { struct dw_966186_fields disp[2]; struct dw_967390_fields giftag0; struct dw_966737_fields draw0; struct dw_978654_fields clear0; struct dw_967390_fields giftag1; struct dw_966737_fields draw1; struct dw_978654_fields clear1; };
#endif
#ifndef PROTO_DW_974212_FIELDS
#define PROTO_DW_974212_FIELDS
struct dw_974212_fields { struct dw_982580_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEH_89DD4EE4_DEFINED
#define DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEH_89DD4EE4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEH_89DD4EE4 = (int)&(((struct dw_972256_fields *)0)->HalfSizeH) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEW_2F3ADEB0_DEFINED
#define DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEW_2F3ADEB0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_972256_FIELDS_HALFSIZEW_2F3ADEB0 = (int)&(((struct dw_972256_fields *)0)->HalfSizeW) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_972256_FIELDS_MODE_6A6AD9D1_DEFINED
#define DCOMP_OFF_STRUCT_DW_972256_FIELDS_MODE_6A6AD9D1_DEFINED
enum { DCOMP_OFF_STRUCT_DW_972256_FIELDS_MODE_6A6AD9D1 = (int)&(((struct dw_972256_fields *)0)->Mode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSX_7E5EA276_DEFINED
#define DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSX_7E5EA276_DEFINED
enum { DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSX_7E5EA276 = (int)&(((struct dw_972256_fields *)0)->PosX) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSY_5D8B8CB0_DEFINED
#define DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSY_5D8B8CB0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_972256_FIELDS_POSY_5D8B8CB0 = (int)&(((struct dw_972256_fields *)0)->PosY) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_974212_FIELDS_DBBUFID_C7278B45_DEFINED
#define DCOMP_OFF_STRUCT_DW_974212_FIELDS_DBBUFID_C7278B45_DEFINED
enum { DCOMP_OFF_STRUCT_DW_974212_FIELDS_DBBUFID_C7278B45 = (int)&(((struct dw_974212_fields *)0)->dbBufID) - 0 };
#endif

struct DzFrame { u8 Mode; u8 Flag; u8 Alpha; u8 Counter; float Rate; float Max; float Add; short PosX; short PosY; short HalfSizeW; short HalfSizeH; void *lpMdlMng; };
/* DrawGameOverTexture @ 0x177990 .. 0x177B10 (0x180 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1115 is the string 'gameover.tm2'
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */

extern void * GetTexMngByName(void *, char *);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
void UpdateDizzyFilter(void);


void UpdateDizzyFilter(void);


/* UpdateDizzyFilter @ 0x178DA0 .. 0x179070 (0x2d0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3a83126f at 0x178e84
 *   fpu: float literal 0x43480000 at 0x178e8c
 *   fpu: mtc1 reinterprets v0 at 0x178e94
 *   fpu: float literal 0x3a83126f at 0x178ec4
 *   fpu: float literal 0x3f800000 at 0x178ecc
 *   fpu: mtc1 reinterprets v1 at 0x178ed4
 *   fpu: float literal 0x3a83126f at 0x178f5c
 *   fpu: float literal 0x43480000 at 0x178f64
 *   fpu: mtc1 reinterprets v0 at 0x178f6c
 *   fpu: float literal 0x3a83126f at 0x178f98
 *   fpu: float literal 0x3f800000 at 0x178fa0
 *   fpu: mtc1 reinterprets v1 at 0x178fa8
 *   delay: addiu at 0x178ff0 writes a register its branch at 0x178fec reads
 *   delay: addiu at 0x179010 writes a register its branch at 0x17900c reads
 *   cfg: loop body is not one contiguous region: .L00178E20
 */

extern u8 DizzyFilterMng[];


/* SetDizzyFilter @ 0x179070 .. 0x1792E8 (0x278 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1790bc writes a register its branch at 0x1790b8 reads
 *   delay: daddu at 0x179148 writes a register its branch at 0x179144 reads
 *   fpu: float literal 0x3a83126f at 0x179210
 *   fpu: float literal 0x43480000 at 0x179218
 *   fpu: mtc1 reinterprets v0 at 0x179220
 *   fpu: float literal 0x3a83126f at 0x17924c
 *   fpu: float literal 0x3f800000 at 0x179254
 *   fpu: mtc1 reinterprets v0 at 0x17925c
 *   cfg: loop body is not one contiguous region: .L00179118
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern u8 DizzyFilterMng[];


/* SetLightDizzy @ 0x1792F0 .. 0x179344 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * SetDizzyFilter(unsigned char, signed short, signed short, signed short, signed short);
extern u8 DizzyFilterMng[];

/* SetDizzy @ 0x179350 .. 0x179394 (0x44 bytes, frame 0x10) */

extern signed int Menu_TD_CallOrder(signed int, signed int, signed int);
extern u32 LastDizzyMode;
extern u8 GameSt[];

/* InitDizzyFilter @ 0x1793A0 .. 0x179400 (0x60 bytes) */
/*
 * dcomp notes:
 *   delay: sltu at 0x1793b8 writes a register its branch at 0x1793b4 reads
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u8 GameOverFilterMng[];

/* UpdateAppearEffect @ 0x179430 .. 0x179514 (0xe4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x179464 is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x179474
 *   fpu: float literal 0x46000000 at 0x179484
 *   fpu: float literal 0x40800000 at 0x17948c
 */

extern void sceVu0RotTransPers(void *, void *, void *, int);
extern u8 *lpDrawMng;
static u8 DizzyFilterMng[0x70];
static u8 DizzyWorm[0x11170];
static u8 DizzyWormBase[0x578];
static u8 GameOverFilterMng[0x1c];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SetAppearEffect(float *a0 , float f12 );
void UpdateAppearEffect(signed int a0 , float *a1 , float f12 );
void DeleteAppearEffect(signed int a0 );
void InitDizzyFilter(void);
void SetDizzy(s32 a0 );
void SetLightDizzy(signed int a0 );
void * SetDizzyFilter(unsigned char a0 , signed short a1 , signed short a2 , signed short a3 , signed short t0 );
void UpdateDizzyFilter(void);
void DrawDizzyFilter(void);
static unsigned int * MakeCircleFrameTexture(unsigned int *lpPacket);
void DrawDizzyMask(void);
void InitDizzyWorm(void);
void SetGameOver(void);
void DrawGameOver(void);
static unsigned int * DrawGameOverTexture(unsigned int *lpPacket, unsigned char Alpha);


/* SetAppearEffect @ 0x179520 .. 0x17963C (0x11c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x17953c is a float copy
 *   stack: address of the slot at 0x20 escapes at 0x179540
 *   fpu: float literal 0x40000000 at 0x179550
 *   fpu: float literal 0x40800000 at 0x179558
 *   fpu: float literal 0x46000000 at 0x179594
 */




signed int SetAppearEffect(float *a0 /* r4 */, float f12 /* f12 */) {
    s16 t0;
    s16 a2;
    u32 a1;
    float f20;
    float f2;
    u32 v1;
    float f1;
    u32 v0;
    u8 stackFrame_20[16] __attribute__((aligned(16)));

    v0 = ((u32)lpDrawMng);
    f20 = f12;
    sceVu0RotTransPers((void *)((u8 *)&stackFrame_20[0]), (void *)(u32)(v0 + 0x2b0), (void *)a0, 0);
    f2 = 2.0f;
    a1 = *(s32 *)((u8 *)&stackFrame_20[0]);
    v1 = ((s32 *)stackFrame_20)[1];
    a2 = (u32)((s32)v1 >> 4) + -0x720;
    f1 = 8192.0f;
    v1 = ((s32)((8192.0f * (4.0f * (2.0f * f20))) / (float)(float)((float)((s32
        *)stackFrame_20)[3])));
    t0 = v1;
    v0 = (u32)SetDizzyFilter(2, (u32)((s32)a1 >> 4) + -0x700, a2, (s32)((u32)t0 << 2) / (s32)(5),
        t0);
    if (v0 == 0) {
        v0 = -1;
    } else {
        v1 = -0x6db70000;
        a0 = (float *)DizzyFilterMng;
        a0 = (float *)(s32)(v0 - (u32)((u32)(DizzyFilterMng)));
        v0 = -0x6db70000 | 0x2493;
        v1 = (u32)a0 >> 0x1f;
        v0 = (s32)a0 / (s32)(0x1c);
    }
    return v0;
}

void UpdateAppearEffect(signed int a0 /* r4 */, float *a1 /* r5 */, float f12 /* f12 */) {
    u32 a2;
    u8 *s0;
    float f20;
    u32 v0;
    float f1;
    float f0;
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    a2 = (u32)a1;
    a1 = (float *)DizzyFilterMng;
    s0 = (u8 *)((u8 *)DizzyFilterMng + (u32)((u32)a0 * (u32)(0x1c)));
    f20 = f12;
    if ((u32)(s32)a0 != (u32)-1) {
        v0 = ((u32)lpDrawMng);
        sceVu0RotTransPers((void *)((u8 *)&stackFrame_30[0]), (void *)(u32)(v0 + 0x2b0), (void
            *)a2, 0);
        a0 = *(s32 *)((u8 *)&stackFrame_30[0]);
        f1 = 8192.0f;
        f0 = 4.0f;
        *(u16 *)(s0 + 0x10) = (u32)((s32)a0 >> 4) + -0x700;
        a0 = ((s32 *)stackFrame_30)[1];
        *(u16 *)(s0 + 0x12) = (u32)((s32)a0 >> 4) + -0x720;
        a0 = ((s32)((8192.0f * (4.0f * f20)) / (float)(float)((float)((s32 *)stackFrame_30)[3])));
        *(u16 *)(s0 + 0x16) = a0;
        a0 = *(s16 *)(s0 + 0x16);
        *(u16 *)(s0 + 0x14) = (s32)((u32)a0 << 2) / (s32)(5);
    }
    return;
}

/* DeleteAppearEffect @ 0x179400 .. 0x179430 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */



void DeleteAppearEffect(signed int a0 /* r4 */) {
    s32 v1;
    u8 *a1;

    a1 = (u8 *)DizzyFilterMng;
    v1 = -1;
    a1 = (u8 *)(s32)((u8 *)DizzyFilterMng + (s32)((u32)((u32)a0) * (u32)(0x1c)));
    if ((u32)(s32)a0 != (u32)v1) {
        v1 = 1;
        *(u8 *)(((u8 *)a1 + 3)) = v1;
    }
    return;
}

void InitDizzyFilter(void) {
    u8 *a1;
    u8 *a0;
    s32 v1;

    a1 = DizzyFilterMng;
    a0 = (u8 *)DizzyFilterMng + 0x70;
    if ((u32)DizzyFilterMng < (u32)a0) {
        if ((u32)a1 < (u32)a0) {
            do {
                *(u8 *)a1 = 0;
                a1 = (u8 *)((u8 *)a1 + 0x1c);
                v1 = (u32)(s32)a1 < (u32)a0;
            } while ((u32)v1 != 0);
        }
    }
    *(u8 *)GameOverFilterMng = 0;
    LastDizzyMode = 0;
    *(u8 *)((u8 *)&GameSt + 0xe) = 0;
    return;
}

void SetDizzy(s32 a0 /* r4 */) {
    u32 v1;

    v1 = LastDizzyMode;
    if (a0 != v1) {
        *(u8 *)((u8 *)&GameSt + 0xe) = a0;
    }
    LastDizzyMode = a0;
    if (a0 != 0) {
        a0 = 0x10000 | 0xd507;
        Menu_TD_CallOrder(a0, 0x39b, 1);
    }
    return;
}

void SetLightDizzy(signed int a0 /* r4 */) {
    u32 v1;

    if ((u32)(s32)a0 != 0) {
        v1 = *(u8 *)((u8 *)&DizzyFilterMng + 0x1c);
        a0 = (s32)4;
        if (v1 == 0) {
            SetDizzyFilter(a0, (s32)0x100, (s32)0xe0, (s32)0x200, (s32)0x1c0);
        }
    } else {
        v1 = 1;
        *(u8 *)((u8 *)&DizzyFilterMng + 0x1f) = v1;
    }
    return;
}

void * SetDizzyFilter(unsigned char a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6
        */, signed short a3 /* r7 */, signed short t0 /* r8 */) {
    u8 *s1;
    u8 s0;
    u32 v1;
    u32 v0;
    s32 hi;
    float f2;
    float f1;
    float f0;
    u32 a0_2;

    s0 = a0;
    v0 = 4;
    switch ((u32)s0) {
    case 1:
        s1 = DizzyFilterMng;
        InitDizzyWorm();
        break;
    case 2:
        s1 = (u8 *)(DizzyFilterMng + 0x38);
        v1 = (u32)(u8 *)(DizzyFilterMng + 0x70);
        if ((u32)s1 < v1) {
            do {
                if (*(u8 *)s1 == 0) {
                    break;
                }
                s1 = (u8 *)(s1 + 0x1c);
                v0 = (u32)(s32)s1 < v1;
            } while (v0 != 0);
        }
        if ((u32)(s1 < (u8 *)(DizzyFilterMng + 0x70)) != 0) {
            break;
        }
        v0 = 0;
        return (void *)v0;
    case 3:
        s1 = GameOverFilterMng;
        break;
    case 4:
        s1 = (u8 *)(DizzyFilterMng + 0x1c);
        break;
    default:
        v0 = 0;
        return (void *)v0;
    }
    *(u8 *)s1 = a0;
    *(u8 *)(s1 + 1) = 0;
    if ((u32)s0 != (u32)3) {
        *(u8 *)(s1 + 2) = 0;
    } else {
        *(u8 *)(s1 + 2) = 0x70;
    }
    *(u8 *)(s1 + 3) = 0;
    v0 = 3;
    *(u32 *)(s1 + 4) = 0;
    switch ((u32)s0) {
    case 2:
        v0 = 0x43480000;
        *(u32 *)(s1 + 8) = 0x43480000;
        v0 = 0x40a00000;
        *(u32 *)(s1 + 0xc) = 0x40a00000;
        break;
    case 3:
        v0 = 0x43c80000;
        *(u32 *)(s1 + 8) = 0x43c80000;
        v0 = 0x40800000;
        *(u32 *)(s1 + 0xc) = 0x40800000;
        break;
    default:
        v0 = rand();
        a0_2 = 0x3e9;
        v1 = 0x3a830000;
        hi = (s32)v0 % 0x3e9;
        v0 = 0x3a830000 | 0x126f;
        f1 = 0.00100000005f;
        f0 = 200.0f;
        *(f32 *)(s1 + 8) = (200.0f * (0.00100000005f * (float)((float)(s32)(u32)hi)));
        v0 = rand();
        a0_2 = 0x3e9;
        v1 = 0x3a830000;
        hi = (s32)v0 % 0x3e9;
        v0 = 0x3a830000 | 0x126f;
        f1 = 0.00100000005f;
        f0 = 1.0f;
        v0 = hi;
        f2 = ((float)(s32)v0);
        f1 = (0.00100000005f * f2);
        f0 = (1.0f + f1);
        *(f32 *)(s1 + 0xc) = f0;
    }
    *(u16 *)(s1 + 0x10) = a1;
    *(u16 *)(s1 + 0x12) = a2;
    *(u16 *)(s1 + 0x14) = (s32)(s16)a3 / 2;
    *(u16 *)(s1 + 0x16) = (s32)(s16)t0 / 2;
    *(u32 *)(s1 + 0x18) = 0;
    return (void *)s1;
}

void UpdateDizzyFilter(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s0;
    float f1;
    float f0;
    u32 v0;
    s32 hi;
    s32 branchcond_178fec;

    a0 = 1;
    a1 = GameSt[0xe];
    v1 = 2;
    if (a1 == a0 || a1 == v1) {
        v1 = *(u8 *)DizzyFilterMng;
        if (v1 == 0) {
            SetDizzyFilter(1, 0x100, 0xe0, 0x200, 0x1c0);
        }
    } else {
        DizzyFilterMng[3] = a0;
    }
    s0 = DizzyFilterMng;
    if ((u32)DizzyFilterMng < (u32)(u8 *)(DizzyFilterMng + 0x70)) {
        do {
            v1 = *(u8 *)s0;
            if (v1 != 0) {
                v1 = *(u8 *)(s0 + 1);
                if (v1 == 0) {
                    f1 = (*(f32 *)(s0 + 4) += *(float *)(s0 + 0xc));
                    f0 = *(float *)(s0 + 8);
                    a0 = 1;
                    if (!(f1 < f0)) {
                        *(u8 *)(s0 + 1) = a0;
                        a0 = *(u8 *)s0;
                        if (a0 != (u32)2) {
                            v0 = rand();
                            a0 = 0x3e9;
                            v1 = 0x3a830000;
                            hi = (s32)v0 % 0x3e9;
                            v0 = 0x3a830000 | 0x126f;
                            f1 = 0.00100000005f;
                            f0 = 200.0f;
                            *(f32 *)(s0 + 8) = (-(200.0f * (0.00100000005f *
                                (float)((float)(s32)(u32)hi))));
                            v0 = rand();
                            a0 = 0x3e9;
                            f1 = 0.00100000005f;
                            f0 = 1.0f;
                            *(f32 *)(s0 + 0xc) = (-(1.0f + (0.00100000005f *
                                (float)((float)(s32)(u32)((s32)v0 % 0x3e9)))));
                        } else {
                            v1 = -0x3cb80000;
                            *(u32 *)(s0 + 8) = -0x3cb80000;
                            v1 = -0x3f600000;
                            *(u32 *)(s0 + 0xc) = -0x3f600000;
                        }
                    }
                } else {
                    f1 = (*(f32 *)(s0 + 4) += *(float *)(s0 + 0xc));
                    f0 = *(float *)(s0 + 8);
                    if (f1 <= f0) {
                        *(u8 *)(s0 + 1) = 0;
                        a0 = *(u8 *)s0;
                        if (a0 != (u32)2) {
                            v0 = rand();
                            a0 = 0x3e9;
                            v1 = 0x3a830000;
                            hi = (s32)v0 % 0x3e9;
                            v0 = 0x3a830000 | 0x126f;
                            f1 = 0.00100000005f;
                            f0 = 200.0f;
                            *(f32 *)(s0 + 8) = (200.0f * (0.00100000005f *
                                (float)((float)(s32)(u32)hi)));
                            v0 = rand();
                            a0 = 0x3e9;
                            f1 = 0.00100000005f;
                            f0 = 1.0f;
                            *(f32 *)(s0 + 0xc) = (1.0f + (0.00100000005f *
                                (float)((float)(s32)(u32)((s32)v0 % 0x3e9))));
                        } else {
                            v1 = 0x43480000;
                            *(u32 *)(s0 + 8) = 0x43480000;
                            v1 = 0x40a00000;
                            *(u32 *)(s0 + 0xc) = 0x40a00000;
                        }
                    }
                }
                a0 = *(u8 *)(s0 + 3);
                if (a0 == 0) {
                    if (++*(u8 *)(s0 + 2) >= (*(u8 *)s0 != 4 ? 0x60 : 0x40)) {
                        *(u8 *)(s0 + 3) = 0xf0;
                    }
                } else {
                    v1 = 1;
                    if (a0 == v1) {
                        v1 = *(u8 *)(s0 + 2);
                        v1 = v1 + -1;
                        *(u8 *)(s0 + 2) = v1;
                        if ((u32)(u8)v1 == 0) {
                            *(u8 *)s0 = 0;
                        }
                    }
                }
            }
            s0 = (u8 *)(s0 + 0x1c);
        } while (s0 < (u8 *)(DizzyFilterMng + 0x70));
    }
    return;
}

void DrawDizzyFilter(void) {
    unsigned int *lpPacket;
    struct DzFrame *lpDizzyMng;
    struct GO_DrawEnv *lpDraw;
    unsigned int Mode;
    int Gap;
    int x0;
    int x1;
    int y0;
    int y1;
    unsigned int Tex[2][2];
    float Scale;

    lpPacket = lpMdlPacketMem;
    lpDraw = (*(int *)(lpDrawMng + 0x408) != 0) ? (struct GO_DrawEnv *)(lpDrawMng + 0x60) : (struct GO_DrawEnv *)(lpDrawMng + 0x150);
    Mode = 0;
    Scale = 1.0f;
    if (GameSt[0xf] == 0) {
        UpdateDizzyFilter();
    }
    lpDizzyMng = (struct DzFrame *)DizzyFilterMng;
    if ((u8 *)lpDizzyMng < DizzyFilterMng + 0x70) {
        if ((u8 *)lpDizzyMng < DizzyFilterMng + 0x70) {
            do {
                Mode |= lpDizzyMng->Mode;
                lpDizzyMng++;
            } while ((u8 *)lpDizzyMng < DizzyFilterMng + 0x70);
        }
    }
    if (Mode == 0) {
        return;
    }
    if (Mode & 2) {
        lpPacket = MakeCircleFrameTexture(lpPacket);
    }
    for (lpDizzyMng = (struct DzFrame *)DizzyFilterMng; (u8 *)lpDizzyMng < DizzyFilterMng + 0x70; lpDizzyMng++) {
        if (lpDizzyMng->Mode == 0) {
            continue;
        }
        lpPacket[0] = 0x10000011;
        lpPacket[1] = 0;
        lpPacket[2] = 0;
        lpPacket[3] = 0x51000011;
        lpPacket[4] = 8;
        lpPacket[5] = 0x102a4000;
        lpPacket[6] = 0xe;
        lpPacket[7] = 0;
        *(u_long *)&lpPacket[8] = 0;
        *(u_long *)&lpPacket[10] = 0x3f;
        *(u_long *)&lpPacket[12] = (u_long)lpDraw->zbuf1.ZBP | ((u_long)lpDraw->zbuf1.PSM << 24) | ((u_long)1 << 32);
        *(u_long *)&lpPacket[14] = 0x4e;
        *(u_long *)&lpPacket[16] = 0;
        *(u_long *)&lpPacket[18] = 0x47;
        if (lpDizzyMng->Mode == 2) {
            *(u_long *)&lpPacket[20] = 0x44;
            lpPacket += 22;
        } else {
            *(u_long *)&lpPacket[20] = (u_long)0x64 | ((u_long)lpDizzyMng->Alpha << 32);
            lpPacket += 22;
        }
        *(u_long *)&lpPacket[0] = 0x42;
        *(u_long *)&lpPacket[2] = 0x20;
        *(u_long *)&lpPacket[4] = 0x14;
        if (lpDizzyMng->Mode == 2) {
            *(u_long *)&lpPacket[6] = (u_long)0x2a00 | ((u_long)8 << 14) | ((u_long)9 << 26) | ((u_long)9 << 30) | ((u_long)1 << 34);
            lpPacket += 8;
        } else {
            *(u_long *)&lpPacket[6] = (u_long)(lpDraw->frame1.FBP * 2048 / 64) | ((u_long)8 << 14) | ((u_long)1 << 20) | ((u_long)9 << 26) | ((u_long)9 << 30) | ((u_long)1 << 34);
            lpPacket += 8;
        }
        *(u_long *)&lpPacket[0] = 6;
        *(u_long *)&lpPacket[2] = 5;
        *(u_long *)&lpPacket[4] = 8;
        if (lpDizzyMng->Mode == 2) {
            *(u_long *)&lpPacket[6] = (u_long)0x80 | ((u_long)0x80 << 8) | ((u_long)0x80 << 16) | ((u_long)lpDizzyMng->Alpha << 24) | ((u_long)0x3f800000 << 32);
            lpPacket += 8;
        } else {
            *(u_long *)&lpPacket[6] = (u_long)0x80 | ((u_long)0x80 << 8) | ((u_long)0x80 << 16) | ((u_long)0x80 << 24) | ((u_long)0x3f800000 << 32);
            lpPacket += 8;
        }
        *(u_long *)&lpPacket[0] = 1;
        lpPacket[2] = 4;
        lpPacket[3] = 0x24000000;
        lpPacket[4] = 0x42;
        lpPacket[5] = 0;
        Gap = (int)(lpDizzyMng->Rate * Scale);
        x0 = (lpDizzyMng->PosX + 0x6fc - lpDizzyMng->HalfSizeW) << 4;
        x1 = (lpDizzyMng->PosX + 0x704 + lpDizzyMng->HalfSizeW) << 4;
        y0 = (lpDizzyMng->PosY + 0x71c - lpDizzyMng->HalfSizeH) << 4;
        y1 = (lpDizzyMng->PosY + 0x724 + lpDizzyMng->HalfSizeH) << 4;
        *(float *)&Tex[0][0] = (float)(lpDizzyMng->PosX - lpDizzyMng->HalfSizeW) / 512.0f;
        *(float *)&Tex[0][1] = (float)(lpDizzyMng->PosX + lpDizzyMng->HalfSizeW) / 512.0f;
        *(float *)&Tex[1][0] = (float)(lpDizzyMng->PosY - lpDizzyMng->HalfSizeH) / 512.0f;
        *(float *)&Tex[1][1] = (float)(lpDizzyMng->PosY + lpDizzyMng->HalfSizeH) / 512.0f;
        *(u_long *)&lpPacket[6] = GO_SET_ST(Tex[0][0], Tex[1][0]);
        *(u_long *)&lpPacket[8] = GO_SET_XYZ(x0 - Gap, y0 + Gap, 0xffffffff);
        *(u_long *)&lpPacket[10] = GO_SET_ST(Tex[0][1], Tex[1][0]);
        *(u_long *)&lpPacket[12] = GO_SET_XYZ(x1 - Gap, y0 - Gap, 0xffffffff);
        *(u_long *)&lpPacket[14] = GO_SET_ST(Tex[0][0], Tex[1][1]);
        *(u_long *)&lpPacket[16] = GO_SET_XYZ(x0 + Gap, y1 + Gap, 0xffffffff);
        *(u_long *)&lpPacket[18] = GO_SET_ST(Tex[0][1], Tex[1][1]);
        *(u_long *)&lpPacket[20] = GO_SET_XYZ(x1 + Gap, y1 - Gap, 0xffffffff);
        lpPacket[22] = 0x8002;
        lpPacket[23] = 0x10000000;
        lpPacket[24] = 0xe;
        lpPacket[25] = 0;
        *(u_long *)&lpPacket[26] = *(u_long *)&lpDraw->zbuf1;
        *(u_long *)&lpPacket[28] = 0x4e;
        *(u_long *)&lpPacket[30] = 0;
        *(u_long *)&lpPacket[32] = 8;
        lpPacket += 34;
    }
    lpMdlPacketMem = lpPacket;
}

static unsigned int * MakeCircleFrameTexture(unsigned int *lpPacket) {
    struct DzFrame *lpDizzyMng;
    u8 *lpTexMng;
    u8 *env;

    env = (*(s32 *)(lpDrawMng + 0x408) != 0) ? lpDrawMng + 0x60 : lpDrawMng + 0x150;
    lpTexMng = (u8 *)GetTexMngByName((void *)0, "filter01.tm2");
    if (lpTexMng == 0) {
        return lpPacket;
    }
    lpPacket = (unsigned int *)MakeTexPacket(lpPacket, lpTexMng);
    lpPacket[0] = 0x1000000b;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x5100000b;
    lpPacket[4] = 0xa;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = 0;
    *(u64 *)(lpPacket + 10) = 0x3f;
    *(u64 *)(lpPacket + 12) = (u64)(s32)((s32)((u32)(*(u16 *)env & 0x1ff) << 11) / 64) | (((u64)0x1082a00 << 32) | 0x1080000);
    *(u64 *)(lpPacket + 14) = 0x50;
    *(u64 *)(lpPacket + 16) = 0;
    *(u64 *)(lpPacket + 18) = 0x51;
    *(u64 *)(lpPacket + 20) = ((u64)0x1c0 << 32) | 0x200;
    *(u64 *)(lpPacket + 22) = 0x52;
    *(u64 *)(lpPacket + 24) = 2;
    *(u64 *)(lpPacket + 26) = 0x53;
    *(u64 *)(lpPacket + 28) = ((u64)0xffffff << 32) | 0x80150;
    *(u64 *)(lpPacket + 30) = 0x4c;
    *(u64 *)(lpPacket + 32) = (u64)(u32)(*(u16 *)(env + 0x10) & 0x1ff) | ((u64)(u32)(*(u8 *)(env + 0x13) & 0xf) << 24) | ((u64)1 << 32);
    *(u64 *)(lpPacket + 34) = 0x4e;
    *(u64 *)(lpPacket + 36) = 0;
    *(u64 *)(lpPacket + 38) = 0x47;
    *(u64 *)(lpPacket + 40) = 0x44;
    *(u64 *)(lpPacket + 42) = 0x42;
    *(u64 *)(lpPacket + 44) = ((u64)0x8080 << 16) | 0x8080 | ((u64)0x3f800000 << 32);
    *(u64 *)(lpPacket + 46) = 1;
    lpPacket += 48;
    for (lpDizzyMng = (struct DzFrame *)(DizzyFilterMng + 0x1c); (u8 *)lpDizzyMng < DizzyFilterMng + 0x70; lpDizzyMng++) {
        if (lpDizzyMng->Mode == 2) {
            lpPacket[0] = 0x10000006;
            lpPacket[1] = 0;
            lpPacket[2] = 0;
            lpPacket[3] = 0x51000006;
            lpPacket[4] = 2;
            lpPacket[5] = 0x102b4000;
            lpPacket[6] = 0xe;
            lpPacket[7] = 0;
            *(u64 *)(lpPacket + 8) = *(u64 *)(*(s32 *)(lpTexMng + 4) + 0x10);
            *(u64 *)(lpPacket + 10) = 6;
            *(u64 *)(lpPacket + 12) = *(u64 *)(*(s32 *)(lpTexMng + 4) + 0x18);
            *(u64 *)(lpPacket + 14) = 0x14;
            lpPacket[16] = 2;
            lpPacket[17] = 0x24000000;
            lpPacket[18] = 0x42;
            lpPacket[19] = 0;
            *(u64 *)(lpPacket + 20) = 0;
            *(u64 *)(lpPacket + 22) = ((u64)(s32)((lpDizzyMng->PosX + 0x700 - lpDizzyMng->HalfSizeW) << 4)) | ((u64)(s32)((lpDizzyMng->PosY + 0x720 - lpDizzyMng->HalfSizeH) << 4) << 16) | ((u64)(s32)-1 << 32);
            *(u64 *)(lpPacket + 24) = (u64)0x3f800000 | ((u64)0x3f800000 << 32);
            *(u64 *)(lpPacket + 26) = ((u64)(s32)((lpDizzyMng->PosX + 0x700 + lpDizzyMng->HalfSizeW) << 4)) | ((u64)(s32)((lpDizzyMng->PosY + 0x720 + lpDizzyMng->HalfSizeH) << 4) << 16) | ((u64)(s32)-1 << 32);
            lpPacket += 28;
        }
    }
    lpPacket[0] = 0x10000002;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x51000002;
    lpPacket[4] = 1;
    lpPacket[5] = 0x10000000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    if (*(s32 *)(lpDrawMng + 0x408) == 0) {
        *(u64 *)(lpPacket + 8) = *(u64 *)(lpDrawMng + 0x60);
        lpPacket += 10;
    } else {
        *(u64 *)(lpPacket + 8) = *(u64 *)(lpDrawMng + 0x150);
        lpPacket += 10;
    }
    *(s64 *)lpPacket = 0x4c;
    return lpPacket + 2;
}

/* DrawDizzyMask @ 0x1784D0 .. 0x1784D8 (0x8 bytes) */

void DrawDizzyMask(void) {
    return;
}

void InitDizzyWorm(void) {
    s32 a0;
    s32 s2;
    u8 *s4;
    s32 s3;
    u32 v1;
    u32 v0;
    s32 hi;
    float f2;
    float f1;
    float f0;
    u8 *s1;
    float f20;
    u8 *s0;

    v1 = *(u8 *)((lpDebugParam + 8));
    s2 = 0;
    if (0 < (s32)v1) {
        s1 = DizzyWorm;
        s0 = DizzyWormBase;
        do {
            v1 = 0x31;
            v0 = (s32)(s1 + 0x55c);
            do {
                *(u8 *)v0 = 0;
                *(u8 *)((v0 + -0x1c)) = 0;
                v1 = v1 + -8;
                *(u8 *)((v0 + -0x38)) = 0;
                *(u8 *)((v0 + -0x54)) = 0;
                *(u8 *)((v0 + -0x70)) = 0;
                *(u8 *)((v0 + -0x8c)) = 0;
                *(u8 *)((v0 + -0xa8)) = 0;
                *(u8 *)((v0 + -0xc4)) = 0;
                v0 = v0 + -0xe0;
            } while ((s32)v1 > (s32)7);
            v0 = (s32)(s1 + (s32)(v1 * (u32)(0x1c)));
            *(u8 *)v0 = 0;
            *(u8 *)((v0 + -0x1c)) = 0;
            v1 = (s32)rand() % (s32)(2);
            *(u8 *)(s0 + 1) = v1;
            a0 = 0x3e9;
            v1 = 0x3a830000;
            hi = (s32)rand() % (s32)(0x3e9);
            v0 = 0x3a830000 | 0x126f;
            f2 = 0.00100000005f;
            v0 = 0x40c90000;
            v1 = 0x40c90000 | 0xfdb;
            f0 = 3.14159274f;
            f1 = 6.28318548f;
            *(f32 *)(s0 + 8) = ((6.28318548f * (0.00100000005f * (float)((float)(s32)(u32)hi))) -
                3.14159274f);
            s3 = lpDebugParam;
            f20 = *(float *)((s3 + 0x14));
            v1 = 0x3e9;
            f1 = 0.00100000005f;
            *(f32 *)(s0 + 0xc) = (f20 + ((*(float *)((s3 + 0x18)) - f20) * (0.00100000005f *
                (float)((float)(s32)(u32)((s32)rand() % (s32)(0x3e9))))));
            s3 = lpDebugParam;
            f20 = *(float *)((s3 + 0x20));
            v1 = 0x3e9;
            f1 = 0.00100000005f;
            *(f32 *)(s0 + 0x10) = (f20 + ((*(float *)((s3 + 0x24)) - f20) * (0.00100000005f *
                (float)((float)(s32)(u32)((s32)rand() % (s32)(0x3e9))))));
            s4 = (u8 *)lpDebugParam;
            s3 = *(u8 *)(s4 + 0x29);
            v0 = (s32)rand() % (s32)((s32)((u32)(*(u8 *)(s4 + 0x28)) - s3) + 1);
            *(u8 *)(s0 + 4) = s3 + v0;
            s4 = (u8 *)lpDebugParam;
            s3 = *(u8 *)(s4 + 0x2b);
            v0 = (s32)rand() % (s32)((s32)((u32)(*(u8 *)(s4 + 0x2a)) - s3) + 1);
            *(u8 *)(s0 + 5) = s3 + v0;
            s4 = (u8 *)lpDebugParam;
            s3 = *(u8 *)(s4 + 0x2d);
            v0 = (s32)rand() % (s32)((s32)((u32)(*(u8 *)(s4 + 0x2c)) - s3) + 1);
            *(u8 *)(s0 + 6) = s3 + v0;
            s4 = (u8 *)lpDebugParam;
            s3 = *(u8 *)(s4 + 0x2f);
            v0 = (s32)rand() % (s32)((s32)((u32)(*(u8 *)(s4 + 0x2e)) - s3) + 1);
            *(u8 *)(s0 + 7) = s3 + v0;
            v1 = (s32)rand() % (s32)(4);
            *(u8 *)(s0 + 2) = v1;
            s2 = s2 + 1;
            s1 = (u8 *)(s1 + 0x578);
            v1 = s2 < (s32)*(u8 *)((lpDebugParam + 8));
            s0 = (u8 *)(s0 + 0x1c);
        } while (v1 != 0);
    }
    return;
}

void SetGameOver(void) {
    s32 a0;
    u32 v1;
    u32 v0;

    v1 = *(u8 *)GameOverFilterMng;
    if (v1 == 0) {
        SetDizzyFilter(3, 0x100, 0xe0, 0x200, 0x1c0);
        GameSt[0xf] = 2;
        FECard_Enable_Draw(0);
        SND_VoiceFadeOffAll();
        SND_SecRemoveMap();
        v0 = CheckVagStmState(0);
        a0 = 0;
        if (v0 == 0) {
            PlayBgmVagStm(0, 4);
            *(u8 *)((u8 *)&GameOverMng + 2) = 1;
        } else {
            SetVagStmFade(0, 1, 0x3c);
            *(u8 *)((u8 *)&GameOverMng + 2) = 0;
        }
        v0 = CheckVagStmState(5);
        if (v0 != 0) {
            SetVagStmFade(5, 1, 0x1e);
        }
        *(u16 *)((u8 *)&GameOverMng) = 0;
        *(u8 *)((u8 *)&GameOverMng + 3) = 0;
    }
    return;
}

void DrawGameOver(void) {
    unsigned int *lpPacket;
    struct GO_DizzyMng *lpDizzyMng;
    unsigned short *lpMsg;
    float w;
    float h;
    int Gap;
    unsigned int Tex[2][2];
    struct GO_DrawEnv *lpDraw;
    int x0;
    int x1;
    int y0;
    int y1;

    lpPacket = lpMdlPacketMem;
    lpDraw = (*(int *)(lpDrawMng + 0x408) != 0) ? (struct GO_DrawEnv *)(lpDrawMng + 0x60) : (struct GO_DrawEnv *)(lpDrawMng + 0x150);
    lpDizzyMng = (struct GO_DizzyMng *)GameOverFilterMng;
    if (((struct GO_DizzyMng *)GameOverFilterMng)->Mode == 0) {
        return;
    }
    switch (lpDizzyMng->Flag) {
    case 0:
        lpDizzyMng->Rate += lpDizzyMng->Add;
        if (lpDizzyMng->Rate >= lpDizzyMng->Max) {
            lpDizzyMng->Flag = 1;
            lpDizzyMng->Max = 0.0f;
            lpDizzyMng->Add = -4.0f;
            lpDizzyMng->Counter = 0;
        }
        break;
    case 1:
        lpDizzyMng->Rate += lpDizzyMng->Add;
        if (lpDizzyMng->Rate <= lpDizzyMng->Max) {
            lpDizzyMng->Rate = 0.0f;
            lpDizzyMng->Flag = 2;
        }
        break;
    case 2:
        if (--lpDizzyMng->Alpha == 0) {
            lpDizzyMng->Flag = 3;
        }
        break;
    case 3:
        if (GameOverCheckPad()) {
            lpDizzyMng->Flag = 4;
        }
    case 4:
        FontDrawBegin(0);
        SetFontColor((GO_COLOR){127, 127, 127, GO_FONTALPHA});
        FsFontSetScale(1.5f, 1.5f);
        if ((lpMsg = KnMsgMng_GetMsgStr(0x1d4e8)) != 0) {
            FsFontGetSize(&w, &h, lpMsg, 0);
            FontPrintXY(0.5f * (512.0f - w), 200.0f, (char *)lpMsg);
        }
        SetFontColor((GO_COLOR){127, 127, 127, 127});
        FontDrawEnd();
        if (GO_FONTALPHA < 0x7f) {
            GO_FONTALPHA++;
        }
        break;
    }
    if (GO_BGM == 0 && CheckVagStmState(0) == 0) {
        PlayBgmVagStm(0, 4);
        GO_BGM = 1;
    }
    if (lpDizzyMng->Flag != 0) {
        if (lpDizzyMng->Counter < 0x80) {
            lpDizzyMng->Counter++;
        }
        lpPacket = DrawGameOverTexture(lpPacket, lpDizzyMng->Counter);
    }
    lpPacket[0] = 0x10000011;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x51000011;
    lpPacket[4] = 8;
    lpPacket[5] = 0x102a4000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u_long *)&lpPacket[8] = 0;
    *(u_long *)&lpPacket[10] = 0x3f;
    *(u_long *)&lpPacket[12] = (u_long)lpDraw->zbuf1.ZBP | ((u_long)lpDraw->zbuf1.PSM << 24) | ((u_long)1 << 32);
    *(u_long *)&lpPacket[14] = 0x4e;
    *(u_long *)&lpPacket[16] = 0;
    *(u_long *)&lpPacket[18] = 0x47;
    *(u_long *)&lpPacket[20] = (u_long)0x64 | ((u_long)lpDizzyMng->Alpha << 32);
    *(u_long *)&lpPacket[22] = 0x42;
    *(u_long *)&lpPacket[24] = 0x20;
    *(u_long *)&lpPacket[26] = 0x14;
    *(u_long *)&lpPacket[28] = (u_long)(lpDraw->frame1.FBP * 2048 / 64) | ((u_long)8 << 14) | ((u_long)1 << 20) | ((u_long)9 << 26) | ((u_long)9 << 30) | ((u_long)1 << 34);
    *(u_long *)&lpPacket[30] = 6;
    *(u_long *)&lpPacket[32] = 5;
    *(u_long *)&lpPacket[34] = 8;
    *(u_long *)&lpPacket[36] = (u_long)0x80 | ((u_long)0x80 << 8) | ((u_long)0x80 << 16) | ((u_long)0x80 << 24) | ((u_long)0x3f800000 << 32);
    *(u_long *)&lpPacket[38] = 1;
    lpPacket[40] = 4;
    lpPacket[41] = 0x24000000;
    lpPacket[42] = 0x42;
    lpPacket[43] = 0;
    Gap = (int)lpDizzyMng->Rate;
    x0 = (lpDizzyMng->PosX + 0x6fc - lpDizzyMng->HalfSizeW) << 4;
    x1 = (lpDizzyMng->PosX + 0x704 + lpDizzyMng->HalfSizeW) << 4;
    y0 = (lpDizzyMng->PosY + 0x71c - lpDizzyMng->HalfSizeH) << 4;
    y1 = (lpDizzyMng->PosY + 0x724 + lpDizzyMng->HalfSizeH) << 4;
    *(float *)&Tex[0][0] = (float)(lpDizzyMng->PosX - lpDizzyMng->HalfSizeW) / 512.0f;
    *(float *)&Tex[0][1] = (float)(lpDizzyMng->PosX + lpDizzyMng->HalfSizeW) / 512.0f;
    *(float *)&Tex[1][0] = (float)(lpDizzyMng->PosY - lpDizzyMng->HalfSizeH) / 512.0f;
    *(float *)&Tex[1][1] = (float)(lpDizzyMng->PosY + lpDizzyMng->HalfSizeH) / 512.0f;
    *(u_long *)&lpPacket[44] = GO_SET_ST(Tex[0][0], Tex[1][0]);
    *(u_long *)&lpPacket[46] = GO_SET_XYZ(x0 - Gap, y0 + Gap, 0xffffffff);
    *(u_long *)&lpPacket[48] = GO_SET_ST(Tex[0][1], Tex[1][0]);
    *(u_long *)&lpPacket[50] = GO_SET_XYZ(x1 - Gap, y0 - Gap, 0xffffffff);
    *(u_long *)&lpPacket[52] = GO_SET_ST(Tex[0][0], Tex[1][1]);
    *(u_long *)&lpPacket[54] = GO_SET_XYZ(x0 + Gap, y1 + Gap, 0xffffffff);
    *(u_long *)&lpPacket[56] = GO_SET_ST(Tex[0][1], Tex[1][1]);
    *(u_long *)&lpPacket[58] = GO_SET_XYZ(x1 + Gap, y1 - Gap, 0xffffffff);
    lpPacket[60] = 0x8002;
    lpPacket[61] = 0x10000000;
    lpPacket[62] = 0xe;
    lpPacket[63] = 0;
    *(u_long *)&lpPacket[64] = *(u_long *)&lpDraw->zbuf1;
    *(u_long *)&lpPacket[66] = 0x4e;
    *(u_long *)&lpPacket[68] = 0;
    *(u_long *)&lpPacket[70] = 8;
    lpMdlPacketMem = lpPacket + 72;
}

static unsigned int * DrawGameOverTexture(unsigned int *lpPacket, unsigned char Alpha) {
    u8 *lpTexMng;

    lpTexMng = (u8 *)GetTexMngByName((void *)0, "gameover.tm2");
    if (lpTexMng == 0) {
        return lpPacket;
    }
    lpPacket = (unsigned int *)MakeTexPacket(lpPacket, lpTexMng);
    lpPacket[0] = 0x1000000a;
    lpPacket[1] = 0;
    lpPacket[2] = 0;
    lpPacket[3] = 0x5100000a;
    lpPacket[4] = 6;
    lpPacket[5] = 0x102b4000;
    lpPacket[6] = 0xe;
    lpPacket[7] = 0;
    *(u64 *)(lpPacket + 8) = 0;
    *(u64 *)(lpPacket + 10) = 0x3f;
    *(u64 *)(lpPacket + 12) = 0;
    *(u64 *)(lpPacket + 14) = 0x47;
    *(u64 *)(lpPacket + 16) = ((u64)0x80 << 32) | 0x44;
    *(u64 *)(lpPacket + 18) = 0x42;
    *(u64 *)(lpPacket + 20) = *(u64 *)(*(s32 *)(lpTexMng + 4) + 0x10);
    *(u64 *)(lpPacket + 22) = 6;
    *(u64 *)(lpPacket + 24) = *(u64 *)(*(s32 *)(lpTexMng + 4) + 0x18);
    *(u64 *)(lpPacket + 26) = 0x14;
    *(u64 *)(lpPacket + 28) = ((u64)(u32)Alpha << 24) | ((u64)(s32)0x808080 | ((u64)0x3f800000 << 32));
    *(u64 *)(lpPacket + 30) = 1;
    lpPacket[32] = 2;
    lpPacket[33] = 0x24000000;
    lpPacket[34] = 0x42;
    lpPacket[35] = 0;
    *(u64 *)(lpPacket + 36) = 0;
    *(u64 *)(lpPacket + 38) = ((u64)0xffffffff << 32) | 0x72007000;
    *(u64 *)(lpPacket + 40) = (u64)0x3f800000 | ((u64)0x3f800000 << 32);
    *(u64 *)(lpPacket + 42) = (s32)-0x71ff7000;
    return lpPacket + 44;
}
static u32 LastDizzyMode;
static u8 GameOverMng[0x4];
