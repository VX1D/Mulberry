#include "common.h"

extern u8 *lpDrawMng;
/* DrawReverseByOT @ 0x185590 .. 0x18593C (0x3ac bytes, frame 0x160) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x120 escapes at 0x1855d0
 *   fpu: float literal 0x40000000 at 0x1855e8
 *   stack: address of the slot at 0x120 escapes at 0x18560c
 *   stack: address of the slot at 0x120 escapes at 0x185620
 *   stack: address of the slot at 0x120 escapes at 0x185634
 *   stack: address of the slot at 0xd8 escapes at 0x185658
 *   stack: address of the slot at 0xb8 escapes at 0x185658
 *   delay: addiu at 0x18569c writes a register its branch at 0x185698 reads
 *   fpu: float literal 0x00000000 at 0x185704
 *   stack: address of the slot at 0xe0 escapes at 0x185720
 *   stack: address of the slot at 0x90 escapes at 0x18573c
 *   stack: address of the slot at 0xd0 escapes at 0x185750
 *   fpu: float literal 0x42c8199a at 0x185768
 *   fpu: float literal 0x41200000 at 0x18576c
 *   fpu: float literal 0x3f800000 at 0x18578c
 *   stack: address of the slot at 0xe0 escapes at 0x18589c
 *   cfg: loop body is not one contiguous region: .L00185658
 *   cfg: loop body is not one contiguous region: .L00185678
 *   cfg: kept branch: 0x185678 if (..) goto .L001856A8
 *   cfg: kept goto: 0x18569c -> .L001856C0
 *   cfg: kept branch: 0x1856c0 if (..) goto .L001858D8
 *   cfg: kept goto: 0x1856c8 -> .L001858D0
 *   cfg: loop test does not fall through into its body: 0x1858d0
 *   cfg: kept branch: 0x1858d0 if (..) goto .L001856E0
 */

extern void DrawSetViewRange16();
extern void DrawCalcView();
extern void sceVu0UnitMatrix(void *);
extern void sceVu0MulMatrix(void *, void *, void *);
extern void SFX_EnableMillorMode(signed int);
extern unsigned int * TransMapTexPacket();
extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void DrawModel(void *);
extern void SFX_DrawSinglePtcl(void *);
extern void SfxTracer_DrawAll();
extern void DrawSetViewRange();

extern u32 lpDrawOTTop[];
extern u32 lpMdlPacketMem;
#ifndef DCOMP_COP2_9397A3F6B7
#define DCOMP_COP2_9397A3F6B7
static inline void dcomp_cop2_9397A3F6B7(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%1)\nlqc2 vf2,16(%1)\nlqc2 vf3,32(%1)\nlqc2 vf4,48(%1)\nlqc2 vf22,0(%2)\nlqc2 vf23,16(%2)\nlqc2 vf24,32(%2)\nlqc2 vf25,48(%2)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p1), "r"(p2) : "memory");
}
#endif


#ifndef PROTO_DW_1172947_FIELDS
#define PROTO_DW_1172947_FIELDS
struct dw_1172947_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_1174618_FIELDS
#define PROTO_DW_1174618_FIELDS
struct dw_1174618_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_1173349_FIELDS
#define PROTO_DW_1173349_FIELDS
struct dw_1173349_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_1175947_FIELDS
#define PROTO_DW_1175947_FIELDS
struct dw_1175947_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_1175304_FIELDS
#define PROTO_DW_1175304_FIELDS
struct dw_1175304_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_1167191_FIELDS
#define PROTO_DW_1167191_FIELDS
struct dw_1167191_fields { struct dw_1172947_fields pmode; struct dw_1174618_fields smode2; struct dw_1173349_fields dispfb; struct dw_1175947_fields display; struct dw_1175304_fields bgcolor; };
#endif
#ifndef PROTO_DW_1171488_FIELDS
#define PROTO_DW_1171488_FIELDS
struct dw_1171488_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_1174284_FIELDS
#define PROTO_DW_1174284_FIELDS
struct dw_1174284_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_1178409_FIELDS
#define PROTO_DW_1178409_FIELDS
struct dw_1178409_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_1176821_FIELDS
#define PROTO_DW_1176821_FIELDS
struct dw_1176821_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_1173754_FIELDS
#define PROTO_DW_1173754_FIELDS
struct dw_1173754_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_1170195_FIELDS
#define PROTO_DW_1170195_FIELDS
struct dw_1170195_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1177923_FIELDS
#define PROTO_DW_1177923_FIELDS
struct dw_1177923_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1172791_FIELDS
#define PROTO_DW_1172791_FIELDS
struct dw_1172791_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1175528_FIELDS
#define PROTO_DW_1175528_FIELDS
struct dw_1175528_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_1170311_FIELDS
#define PROTO_DW_1170311_FIELDS
struct dw_1170311_fields { struct dw_1174284_fields frame1; unsigned long frame1addr; struct dw_1178409_fields zbuf1; long zbuf1addr; struct dw_1176821_fields xyoffset1; long xyoffset1addr; struct dw_1173754_fields scissor1; long scissor1addr; struct dw_1170195_fields prmodecont; long prmodecontaddr; struct dw_1177923_fields colclamp; long colclampaddr; struct dw_1172791_fields dthe; long dtheaddr; struct dw_1175528_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_1180989_FIELDS
#define PROTO_DW_1180989_FIELDS
struct dw_1180989_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_1172570_FIELDS
#define PROTO_DW_1172570_FIELDS
struct dw_1172570_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_1177235_FIELDS
#define PROTO_DW_1177235_FIELDS
struct dw_1177235_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_1176347_FIELDS
#define PROTO_DW_1176347_FIELDS
struct dw_1176347_fields { struct dw_1175528_fields testa; long testaaddr; struct dw_1180989_fields prim; long primaddr; struct dw_1172570_fields rgbaq; long rgbaqaddr; struct dw_1177235_fields xyz2a; long xyz2aaddr; struct dw_1177235_fields xyz2b; long xyz2baddr; struct dw_1175528_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_1178043_FIELDS
#define PROTO_DW_1178043_FIELDS
struct dw_1178043_fields { struct dw_1167191_fields disp[2]; struct dw_1171488_fields giftag0; struct dw_1170311_fields draw0; struct dw_1176347_fields clear0; struct dw_1171488_fields giftag1; struct dw_1170311_fields draw1; struct dw_1176347_fields clear1; };
#endif
#ifndef PROTO_DW_1165516_FIELDS
#define PROTO_DW_1165516_FIELDS
struct dw_1165516_fields { struct dw_1178043_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1165516_FIELDS_DRAWFLAG_A500D2C6_DEFINED
#define DCOMP_OFF_STRUCT_DW_1165516_FIELDS_DRAWFLAG_A500D2C6_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1165516_FIELDS_DRAWFLAG_A500D2C6 = (int)&(((struct dw_1165516_fields *)0)->DrawFlag) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1165516_FIELDS_WATERLEVEL_6B0470C3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1165516_FIELDS_WATERLEVEL_6B0470C3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1165516_FIELDS_WATERLEVEL_6B0470C3 = (int)&(((struct dw_1165516_fields *)0)->WaterLevel) - 0 };
#endif
#define COP2MUL(p0,p1,p2) __asm__("lqc2 vf1,0(%2)\nlqc2 vf2,16(%2)\nlqc2 vf3,32(%2)\nlqc2 vf4,48(%2)\nlqc2 vf22,0(%1)\nlqc2 vf23,16(%1)\nlqc2 vf24,32(%1)\nlqc2 vf25,48(%1)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p2), "r"(p1) : "memory")
static inline int HasMapTex(u8 *p) {
    for (; p != 0; p = *(u8 **)(p + 0xc)) {
        if (p[1] == 0 && *(u8 *)(*(u32 *)(*(u32 *)(*(u32 *)(*(u32 *)(p + 8) + 0xc) + 0x10) + 0x38) + 9) != 0) {
            return 1;
        }
    }
    return 0;
}

static inline void CalcZOffsetMat(float *mWS, float *pos, float z) {
    float v[4];
    float m[4][4];
    sceVu0CopyMatrix(m, (u8 *)lpDrawMng + 0x330);
    sceVu0ApplyMatrix(v, (u8 *)lpDrawMng + 0x2f0, pos);
    m[2][2] *= 1.0f + (10.0f * z) / ((100.05f * v[2]) * (v[2] + z));
    COP2MUL(mWS, m, (u8 *)lpDrawMng + 0x2f0);
    COP2MUL(mWS, (u8 *)lpDrawMng + 0x3b0, mWS);
}

#define DRM ((struct dw_1165516_fields *)lpDrawMng)


/* DrawByOT @ 0x185940 .. 0x185CA8 (0x368 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0xe8 escapes at 0x185988
 *   stack: address of the slot at 0xc8 escapes at 0x185988
 *   delay: addiu at 0x185990 writes a register its branch at 0x18598c reads
 *   delay: addiu at 0x185a64 writes a register its branch at 0x185a60 reads
 *   fpu: float literal 0x00000000 at 0x185a84
 *   stack: address of the slot at 0xf0 escapes at 0x185aa0
 *   stack: address of the slot at 0xa0 escapes at 0x185abc
 *   stack: address of the slot at 0xe0 escapes at 0x185ad0
 *   fpu: float literal 0x42c8199a at 0x185ae8
 *   fpu: float literal 0x41200000 at 0x185aec
 *   fpu: float literal 0x3f800000 at 0x185b0c
 *   stack: address of the slot at 0xf0 escapes at 0x185c1c
 *   cfg: loop body is not one contiguous region: .L00185988
 *   cfg: kept goto: 0x185a38 -> .L00185C60
 *   cfg: loop test does not fall through into its body: 0x185c60
 *   cfg: kept branch: 0x185c60 if (..) goto .L00185A58
 */

extern u32 CheckDarkFilter();
extern void DrawMirror();
extern void DrawShadow();
extern void DrawDarkFilter();





extern void SFX_DrawSingleEmitter(void *);



#ifndef DCOMP_COP2_9397A3F6B7_B
#define DCOMP_COP2_9397A3F6B7_B
static inline void dcomp_cop2_9397A3F6B7_b(void *p0, void *p1, void *p2) {
    __asm__("lqc2 vf1,0(%2)\nlqc2 vf2,16(%2)\nlqc2 vf3,32(%2)\nlqc2 vf4,48(%2)\nlqc2 vf22,0(%1)\nlqc2 vf23,16(%1)\nlqc2 vf24,32(%1)\nlqc2 vf25,48(%1)\nvmulax.xyzw ACC,vf1,vf22x\nvmadday.xyzw ACC,vf2,vf22y\nvmaddaz.xyzw ACC,vf3,vf22z\nvmaddw.xyzw vf22,vf4,vf22w\nvmulax.xyzw ACC,vf1,vf23x\nvmadday.xyzw ACC,vf2,vf23y\nvmaddaz.xyzw ACC,vf3,vf23z\nvmaddw.xyzw vf23,vf4,vf23w\nvmulax.xyzw ACC,vf1,vf24x\nvmadday.xyzw ACC,vf2,vf24y\nvmaddaz.xyzw ACC,vf3,vf24z\nvmaddw.xyzw vf24,vf4,vf24w\nvmulax.xyzw ACC,vf1,vf25x\nvmadday.xyzw ACC,vf2,vf25y\nvmaddaz.xyzw ACC,vf3,vf25z\nvmaddw.xyzw vf25,vf4,vf25w\nsqc2 vf22,0(%0)\nsqc2 vf23,16(%0)\nsqc2 vf24,32(%0)\nsqc2 vf25,48(%0)" : : "r"(p0), "r"(p2), "r"(p1) : "memory");
}
#endif


/* _AddDrawOT @ 0x185CB0 .. 0x185D38 (0x88 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00185CE0
 *   declaration vs inferred signature: return void vs inferred float
 */

extern u32 lpDrawOTTop[];

/* SetDrawOTSprite @ 0x185D40 .. 0x185D58 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j _SetDrawOT at 0x185d50 leaves the function
 *   declaration vs inferred signature: return signed int vs inferred void
 */

static signed int _SetDrawOT(unsigned char, void *, float *, unsigned char);

/* SetDrawOTModel @ 0x185D60 .. 0x185DC0 (0x60 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned int CheckDrawModel(void *);

/* _SetDrawOT @ 0x185DC0 .. 0x185EA4 (0xe4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00185DF0
 *   cfg: kept branch: 0x185df0 if (..) goto .L00185E08
 *   cfg: kept goto: 0x185dfc -> .L00185E20
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern float Math_GetDist2(float *, float *);
extern u8 DrawOT[];
extern u8 *lpDrawMng;


/* ClearDrawOT @ 0x185EB0 .. 0x185F18 (0x68 bytes, frame 0x10) */

extern void *memset(void *, int, unsigned int);
extern u8 DrawOT[];
extern u32 lpDrawOTTop[];
static u8 DrawOT[0x4000];
static u32 lpDrawOTTop[0x8];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void ClearDrawOT(void);
static signed int _SetDrawOT(unsigned char a0 , void *a1 , float *a2 , unsigned char a3 );
signed int SetDrawOTModel(void *a0 , float *a1 , unsigned char a2 );
signed int SetDrawOTSprite(void *a0 , float *a1 , unsigned char a2 );
static void _AddDrawOT(void *a0 , unsigned char a1 );
void DrawByOT(void);
void DrawReverseByOT(void);


void ClearDrawOT(void) {
    memset(DrawOT, 0, 0x4000);
    *(u32 *)((u8 *)&lpDrawOTTop + 0x1c) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 0x18) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 0x14) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 0x10) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 0xc) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 8) = 0;
    *(u32 *)((u8 *)&lpDrawOTTop + 4) = 0;
    *(u32 *)lpDrawOTTop = 0;
    return;
}

static signed int _SetDrawOT(unsigned char a0 /* r4 */, void *a1 /* r5 */, float *a2 /* r6 */,
        unsigned char a3 /* r7 */) {
    u8 *entry;
    u8 *p;
    u32 w;

    for (p = DrawOT; p < DrawOT + 0x4000; p += 0x10) {
        if (*p == 0) {
            entry = p;
            goto found;
        }
    }
    entry = 0;
found:
    if (entry == 0) {
        return 0;
    }
    *entry = 1;
    *(u8 *)(entry + 1) = a0;
    *(u32 *)(entry + 8) = (u32)a1;
    w = (u8)a3;
    if (w == 0x64) {
        a3 = 1;
    } else if (0 < (s32)w) {
        a3++;
    }
    *(f32 *)(entry + 4) = Math_GetDist2(a2, (float *)(lpDrawMng + 0x230));
    _AddDrawOT(entry, a3);
    return 1;
}

signed int SetDrawOTModel(void *a0 /* r4 */, float *a1 /* r5 */, unsigned char a2 /* r6 */) {
    float *a1_value; // a1
    u64 ra;
    u32 v0;
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    *(&stackFrame_30[0]) = ra;
    v0 = CheckDrawModel(a0);
    a1_value = (float *)a0;
    if (v0 != 0) {
        v0 = _SetDrawOT(0, (void *)a1_value, (float *)a1, a2);
        ra = *(u64 *)((u8 *)&stackFrame_30[0]);
    } else {
        v0 = 0;
        ra = *(u64 *)((u8 *)&stackFrame_30[0]);
    }
    return v0;
}

signed int SetDrawOTSprite(void *a0 /* r4 */, float *a1 /* r5 */, unsigned char a2 /* r6 */) {
    return _SetDrawOT(1, (void *)(u32)a0, (float *)(u32)a1, a2);
}

static void _AddDrawOT(void *a0 /* r4 */, unsigned char a1 /* r5 */) {
    u32 a1_word = a1;
    u32 v1;
    u32 a2;
    float f1;
    float f0;

    v1 = (u8)a1_word;
    a1_word = v1 << 2;
    v1 = (u32)lpDrawOTTop;
    v1 = (s32)((u8 *)lpDrawOTTop + a1_word);
    a2 = *(s32 *)v1;
    if (a2 != 0) {
        a1_word = 0;
        if (a2 != 0) {
            f1 = *(float *)(((u8 *)a0 + 4));
            do {
                f0 = *(float *)((a2 + 4));
                if (!(s32)(f1 <= f0)) {
                    break;
                }
                a1_word = a2;
                a2 = *(s32 *)((a2 + 0xc));
            } while (a2 != 0);
        }
        if (a2 != 0) {
            *(u32 *)(((u8 *)a0 + 0xc)) = a2;
        }
        if (a1_word != 0) {
            *(u32 *)((a1_word + 0xc)) = (u32)a0;
        } else {
            *(u32 *)v1 = (u32)a0;
        }
    } else {
        *(u32 *)v1 = (u32)a0;
    }
    return;
}


void DrawByOT(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u8 *s4;
    s32 s3;
    s32 s7;
    float *s6;
    float *s5;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u8 *s2;
    u32 v0_4; // v0
    u32 v0;
    float f5;
    u32 *s1;
    float f20;
    u8 *s0;
    float f1;
    float mOldWS[4][4] __attribute__((aligned(8)));
    float *pm;
    float vec[4] __attribute__((aligned(8)));
    float mTmp[4][4] __attribute__((aligned(16)));

    s7 = 0;
    s6 = &vec[2];
    s5 = &mTmp[2][2];
    s3 = 0;
    s1 = lpDrawOTTop;
    do {
        v1 = 6;
        switch ((u32)s3) {
        case 3:
            v0_3 = CheckDarkFilter();
            v1 = (u8)v0_3;
            if (v1 != 0) {
                break;
            }
            DrawMirror();
            break;
        case 4:
            DrawShadow();
            break;
        case 6:
            DrawDarkFilter();
            v0_2 = CheckDarkFilter();
            v1 = (u8)v0_2;
            if (v1 == 0) {
                break;
            }
            DrawMirror();
        }
        s4 = (u8 *)*(s32 *)s1;
        if ((u32)(s32)s4 != 0) {
            v1 = 1;
            if ((u32)s3 == 0 || (u32)s3 == v1) {
                if ((u32)s7 == 0) {
                    a0 = *(s32 *)(s4 + 8);
                    a1 = lpMdlPacketMem;
                    v0_4 = (u32)TransMapTexPacket(a0, a1, 0);
                    lpMdlPacketMem = v0_4;
                    s7 = 1;
                    goto _L00185C60;
                    _L00185A58:;
                    a0 = *(u8 *)(s4 + 1);
                    v1 = 2;
                    switch (a0) {
                    case 0:
                        a0 = *(s32 *)(s4 + 8);
                        f1 = *(float *)((a0 + 0x184));
                        if (!(0.0f == f1)) {
                            v0 = (u32)lpDrawMng;
                            sceVu0CopyMatrix((void *)((u8 *)&mOldWS[0]), (void *)(s32)(v0 + 0x2b0));
                            s0 = (u8 *)*(s32 *)(s4 + 8);
                            v0 = (u32)lpDrawMng;
                            f20 = *(float *)(s0 + 0x184);
                            s2 = (u8 *)(s32)(v0 + 0x2b0);
                            sceVu0CopyMatrix((void *)mTmp, (void *)(s32)(v0 +
                                0x330));
                            v0 = (u32)lpDrawMng;
                            sceVu0ApplyMatrix((void *)vec, (void *)(s32)(v0 +
                                0x2f0), (void *)(s0 + 0x20));
                            f5 = *(float *)s6;
                            pm = (float *)mTmp;
                                            *(f32 *)s5 = (*(float *)s5 * (1.0f + ((1e+01f * f20) / ((100.05f * f5)
                                * (f5 + f20)))));
                            v0 = (u32)lpDrawMng;
                            a0 = v0 + 0x2f0;
                            dcomp_cop2_9397A3F6B7_b((void *)((u8 *)s2), (void *)pm,
                                (void *)((u8 *)a0));
                            v0 = v0 + 0x3b0;
                            dcomp_cop2_9397A3F6B7_b((void *)((u8 *)s2), (void *)((u8 *)v0), (void
                                *)((u8 *)s2));
                            a0 = *(s32 *)(s4 + 8);
                            DrawModel((void *)a0);
                            v0 = (u32)lpDrawMng;
                            sceVu0CopyMatrix((void *)(s32)(v0 + 0x2b0), (void *)((u8 *)&mOldWS[0]));
                            break;
                        } else {
                            DrawModel((void *)a0);
                            break;
                        }
                    case 1:
                        a0 = *(s32 *)(s4 + 8);
                        SFX_DrawSinglePtcl((void *)a0);
                        break;
                    case 2:
                        a0 = *(s32 *)(s4 + 8);
                        SFX_DrawSingleEmitter((void *)a0);
                    }
                    s4 = (u8 *)*(s32 *)(s4 + 0xc);
                }
            }
            _L00185C60:;
            if ((u32)(s32)s4 != 0) {
                goto _L00185A58;
            }
        }
        s3 = s3 + 1;
        v1 = s3 < (s32)8;
        s1 += 1;
    } while (v1 != 0);
    return;
}
void DrawReverseByOT(void) {
    u8 *lpCurOT;
    int Priority;
    float ReverseMat[4][4];
    float mOldWS[4][4];
    u8 *lpMdl;
    float z;

    DrawSetViewRange16();
    DrawCalcView();
    DRM->DrawFlag = 3;
    sceVu0UnitMatrix(ReverseMat);
    ReverseMat[1][1] = -ReverseMat[1][1];
    ReverseMat[3][1] = 2.0f * DRM->WaterLevel;
    sceVu0MulMatrix((u8 *)lpDrawMng + 0x370, (u8 *)lpDrawMng + 0x370, ReverseMat);
    sceVu0MulMatrix((u8 *)lpDrawMng + 0x2b0, (u8 *)lpDrawMng + 0x2b0, ReverseMat);
    sceVu0MulMatrix((u8 *)lpDrawMng + 0x2f0, (u8 *)lpDrawMng + 0x2f0, ReverseMat);
    SFX_EnableMillorMode(1);
    for (Priority = 0; Priority < 8; Priority++) {
        lpCurOT = (u8 *)lpDrawOTTop[Priority];
        if (lpCurOT == 0) continue;
        if (Priority == 0) {
            if (!HasMapTex(lpCurOT)) continue;
            lpMdlPacketMem = (u32)TransMapTexPacket(*(u32 *)(lpCurOT + 8), lpMdlPacketMem, 0);
        }
        for (; lpCurOT != 0; lpCurOT = *(u8 **)(lpCurOT + 0xc)) {
            switch (lpCurOT[1]) {
            case 0:
                if (0.0f != *(float *)(*(u32 *)(lpCurOT + 8) + 0x184)) {
                    sceVu0CopyMatrix(mOldWS, (u8 *)lpDrawMng + 0x2b0);
                    CalcZOffsetMat((float *)((u8 *)lpDrawMng + 0x2b0), (float *)(*(u8 **)(lpCurOT + 8) + 0x20), *(float *)(*(u8 **)(lpCurOT + 8) + 0x184));
                    DrawModel(*(void **)(lpCurOT + 8));
                    sceVu0CopyMatrix((u8 *)lpDrawMng + 0x2b0, mOldWS);
                } else {
                    DrawModel(*(void **)(lpCurOT + 8));
                }
                break;
            case 1:
                SFX_DrawSinglePtcl(*(void **)(lpCurOT + 8));
                break;
            }
        }
    }
    SfxTracer_DrawAll();
    SFX_EnableMillorMode(0);
    DrawSetViewRange();
    DrawCalcView();
    DRM->DrawFlag = 0;
}
