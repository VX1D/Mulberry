#include "common.h"




extern u8 *lpDrawMng;
extern void * GetTexMngByName(void *, char *);
static unsigned int * MakeCrackTexture(unsigned int *, void *, void *, float, float, float);
extern signed int CheckEventFlag(signed int);
extern u8 TexEffectMng[];
extern u8 GameSt[];
extern void UpdateBloodStain();
static unsigned int * MakeBloodStainTexture(unsigned int *, void *, void *);
extern u32 TexScrollMng[];
static unsigned int * RestoreDrawEnv(unsigned int *a0 /* r4 */);
unsigned int * MakeCrackWall(unsigned int *lpCurDMA);
signed int CheckCrackWall(void *a0 /* r4 */);
void SetCrackWall(s32 a0 /* r4 */);
unsigned int * MakeBloodStain(unsigned int *lpCurDMA);
void SetBloodPoolScale(float f12 /* f12 */);
u8 CheckBloodStain(void);
void * GetTextureScroll(unsigned int a0 /* r4 */);
void InitTextureScroll(void);

static u32 TexScrollMng[0x140];
static u16 BloodControlMng[0x80];
static u8 BloodStainMng[0x2000];
static u8 TexEffectMng[0x20];

/* InitTextureScroll @ 0x1A8330 .. 0x1A8500 (0x1d0 bytes) */




void InitTextureScroll(void) {
    u8 *a2;
    u8 *a1;
    s32 a0;
    u32 v1;

    a2 = (u8 *)TexScrollMng;
    if ((u32)TexScrollMng < (u32)(u8 *)(TexScrollMng + 0x140)) {
        a1 = (u8 *)(TexScrollMng + 0xf0);
        a0 = 0x3f800000;
        do {
            *(u32 *)a2 = 0;
            *(u32 *)(a2 + 4) = 0;
            *(u32 *)(a2 + 8) = 0;
            *(u32 *)(a2 + 0xc) = 0;
            *(u32 *)(a2 + 0x10) = 0;
            *(u32 *)(a2 + 0x14) = 0;
            *(u32 *)(a2 + 0x18) = 0;
            *(u32 *)(a2 + 0x1c) = 0;
            *(u32 *)(a2 + 0x20) = a0;
            *(u32 *)(a2 + 0x24) = a0;
            *(u32 *)(a2 + 0x28) = 0;
            *(u32 *)(a2 + 0x2c) = 0;
            *(u32 *)(a2 + 0x30) = 0;
            *(u32 *)(a2 + 0x34) = 0;
            *(u32 *)(a2 + 0x38) = 0;
            *(u32 *)(a2 + 0x3c) = 0;
            *(u32 *)(a2 + 0x40) = 0;
            *(u32 *)(a2 + 0x44) = 0;
            *(u32 *)(a2 + 0x48) = a0;
            *(u32 *)(a2 + 0x4c) = a0;
            *(u32 *)(a2 + 0x50) = 0;
            *(u32 *)(a2 + 0x54) = 0;
            *(u32 *)(a2 + 0x58) = 0;
            *(u32 *)(a2 + 0x5c) = 0;
            *(u32 *)(a2 + 0x60) = 0;
            *(u32 *)(a2 + 0x64) = 0;
            *(u32 *)(a2 + 0x68) = 0;
            *(u32 *)(a2 + 0x6c) = 0;
            *(u32 *)(a2 + 0x70) = a0;
            *(u32 *)(a2 + 0x74) = a0;
            *(u32 *)(a2 + 0x78) = 0;
            *(u32 *)(a2 + 0x7c) = 0;
            *(u32 *)(a2 + 0x80) = 0;
            *(u32 *)(a2 + 0x84) = 0;
            *(u32 *)(a2 + 0x88) = 0;
            *(u32 *)(a2 + 0x8c) = 0;
            *(u32 *)(a2 + 0x90) = 0;
            *(u32 *)(a2 + 0x94) = 0;
            *(u32 *)(a2 + 0x98) = a0;
            *(u32 *)(a2 + 0x9c) = a0;
            *(u32 *)(a2 + 0xa0) = 0;
            *(u32 *)(a2 + 0xa4) = 0;
            *(u32 *)(a2 + 0xa8) = 0;
            *(u32 *)(a2 + 0xac) = 0;
            *(u32 *)(a2 + 0xb0) = 0;
            *(u32 *)(a2 + 0xb4) = 0;
            *(u32 *)(a2 + 0xb8) = 0;
            *(u32 *)(a2 + 0xbc) = 0;
            *(u32 *)(a2 + 0xc0) = a0;
            *(u32 *)(a2 + 0xc4) = a0;
            *(u32 *)(a2 + 0xc8) = 0;
            *(u32 *)(a2 + 0xcc) = 0;
            *(u32 *)(a2 + 0xd0) = 0;
            *(u32 *)(a2 + 0xd4) = 0;
            *(u32 *)(a2 + 0xd8) = 0;
            *(u32 *)(a2 + 0xdc) = 0;
            *(u32 *)(a2 + 0xe0) = 0;
            *(u32 *)(a2 + 0xe4) = 0;
            *(u32 *)(a2 + 0xe8) = a0;
            *(u32 *)(a2 + 0xec) = a0;
            *(u32 *)(a2 + 0xf0) = 0;
            *(u32 *)(a2 + 0xf4) = 0;
            *(u32 *)(a2 + 0xf8) = 0;
            *(u32 *)(a2 + 0xfc) = 0;
            *(u32 *)(a2 + 0x100) = 0;
            *(u32 *)(a2 + 0x104) = 0;
            *(u32 *)(a2 + 0x108) = 0;
            *(u32 *)(a2 + 0x10c) = 0;
            *(u32 *)(a2 + 0x110) = a0;
            *(u32 *)(a2 + 0x114) = a0;
            *(u32 *)(a2 + 0x118) = 0;
            *(u32 *)(a2 + 0x11c) = 0;
            *(u32 *)(a2 + 0x120) = 0;
            *(u32 *)(a2 + 0x124) = 0;
            *(u32 *)(a2 + 0x128) = 0;
            *(u32 *)(a2 + 0x12c) = 0;
            *(u32 *)(a2 + 0x130) = 0;
            *(u32 *)(a2 + 0x134) = 0;
            *(u32 *)(a2 + 0x138) = a0;
            *(u32 *)(a2 + 0x13c) = a0;
            a2 = (u8 *)(a2 + 0x140);
            v1 = (u32)(s32)a2 < (u32)a1;
        } while (v1 != 0);
        if (a2 < (u8 *)(TexScrollMng + 0x140)) {
            do {
                *(u32 *)a2 = 0;
                *(u32 *)(a2 + 4) = 0;
                *(u32 *)(a2 + 8) = 0;
                *(u32 *)(a2 + 0xc) = 0;
                *(u32 *)(a2 + 0x10) = 0;
                *(u32 *)(a2 + 0x14) = 0;
                *(u32 *)(a2 + 0x18) = 0;
                *(u32 *)(a2 + 0x1c) = 0;
                *(u32 *)(a2 + 0x20) = 0x3f800000;
                *(u32 *)(a2 + 0x24) = 0x3f800000;
                a2 = (u8 *)(a2 + 0x28);
                v1 = a2 < (u8 *)(TexScrollMng + 0x140);
            } while (v1 != 0);
        }
    }
    return;
}


/* UpdateTextureScroll @ 0x1A80A0 .. 0x1A8328 (0x288 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1a8110 writes a register its branch at 0x1a810c reads
 *   fpu: float literal 0x3f800000 at 0x1a813c
 *   fpu: float literal 0x00000000 at 0x1a8164
 *   fpu: float literal 0x3f800000 at 0x1a8178
 *   fpu: float literal 0x40490fdb at 0x1a819c
 *   fpu: float literal 0x40c90fdb at 0x1a81c0
 *   fpu: float literal 0xc0490fdb at 0x1a81dc
 *   fpu: float literal 0x40c90fdb at 0x1a81f4
 *   fpu: float literal 0x40000000 at 0x1a822c
 *   fpu: float literal 0xbf800000 at 0x1a8250
 *   fpu: float literal 0x3f800000 at 0x1a8290
 *   cfg: loop body is not one contiguous region: .L001A80E8
 *   cfg: loop body is not one contiguous region: .L001A80F8
 */

extern u32 lpDebugParam;

#ifndef PROTO_DW_1763287_FIELDS
#define PROTO_DW_1763287_FIELDS
struct dw_1763287_fields { unsigned char Num; unsigned char Length; unsigned char unused[2]; float Speed; float RangeDiff; float RangeMin; float RangeMax; float SizeDiff; float SizeMin; float SizeMax; unsigned char ColorRMax; unsigned char ColorRMin; unsigned char ColorGMax; unsigned char ColorGMin; unsigned char ColorBMax; unsigned char ColorBMin; unsigned char ColorAMax; unsigned char ColorAMin; };
#endif
#ifndef PROTO_DW_1747825_FIELDS
#define PROTO_DW_1747825_FIELDS
struct dw_1747825_fields { unsigned char Type[2]; unsigned char Wave[2]; float Speed[2]; float Amplitude[2]; float SinSpeed[2]; float SinAmplitude[2]; float SinWavelength[2]; };
#endif
#ifndef PROTO_DW_1751412_FIELDS
#define PROTO_DW_1751412_FIELDS
struct dw_1751412_fields { unsigned char Threshold[3]; unsigned char Rate; };
#endif
#ifndef PROTO_DW_1754763_FIELDS
#define PROTO_DW_1754763_FIELDS
struct dw_1754763_fields { unsigned int FileVersion; unsigned int FileSize; struct dw_1763287_fields DizzyEffect; struct dw_1747825_fields TexScroll[32]; float AmbientColor[32][4]; struct dw_1751412_fields GlareInfo[32]; };
#endif
#ifndef PROTO_DW_1755037_FIELDS
#define PROTO_DW_1755037_FIELDS
struct dw_1755037_fields { float st[2]; float phase[2]; float SinPhase[2]; float SinAmplitude[2]; float SinWavelength[2]; };
#endif
#ifndef PROTO_DW_1757953_FIELDS
#define PROTO_DW_1757953_FIELDS
struct dw_1757953_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__AMPLITUDE_0__91A9A1F3_DEFINED
#define DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__AMPLITUDE_0__91A9A1F3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__AMPLITUDE_0__91A9A1F3 = (int)&(((struct dw_1754763_fields *)0)->TexScroll[0].Amplitude[0]) - 48 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINAMPLITUDE_0__7F12F631_DEFINED
#define DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINAMPLITUDE_0__7F12F631_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINAMPLITUDE_0__7F12F631 = (int)&(((struct dw_1754763_fields *)0)->TexScroll[0].SinAmplitude[0]) - 48 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINSPEED_0__EE24C345_DEFINED
#define DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINSPEED_0__EE24C345_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINSPEED_0__EE24C345 = (int)&(((struct dw_1754763_fields *)0)->TexScroll[0].SinSpeed[0]) - 48 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINWAVELENGTH_0__03DF49C8_DEFINED
#define DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINWAVELENGTH_0__03DF49C8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SINWAVELENGTH_0__03DF49C8 = (int)&(((struct dw_1754763_fields *)0)->TexScroll[0].SinWavelength[0]) - 48 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SPEED_0__637598DF_DEFINED
#define DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SPEED_0__637598DF_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1754763_FIELDS_TEXSCROLL_0__SPEED_0__637598DF = (int)&(((struct dw_1754763_fields *)0)->TexScroll[0].Speed[0]) - 48 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINAMPLITUDE_0__D7AADBA4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINAMPLITUDE_0__D7AADBA4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINAMPLITUDE_0__D7AADBA4 = (int)&(((struct dw_1755037_fields *)0)->SinAmplitude[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINPHASE_0__868D55A4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINPHASE_0__868D55A4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINPHASE_0__868D55A4 = (int)&(((struct dw_1755037_fields *)0)->SinPhase[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINWAVELENGTH_0__837DE17A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINWAVELENGTH_0__837DE17A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1755037_FIELDS_SINWAVELENGTH_0__837DE17A = (int)&(((struct dw_1755037_fields *)0)->SinWavelength[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1755037_FIELDS_PHASE_0__44274043_DEFINED
#define DCOMP_OFF_STRUCT_DW_1755037_FIELDS_PHASE_0__44274043_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1755037_FIELDS_PHASE_0__44274043 = (int)&(((struct dw_1755037_fields *)0)->phase[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1755037_FIELDS_ST_0__661944C4_DEFINED
#define DCOMP_OFF_STRUCT_DW_1755037_FIELDS_ST_0__661944C4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1755037_FIELDS_ST_0__661944C4 = (int)&(((struct dw_1755037_fields *)0)->st[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_1757953_FIELDS_PAUSE_8B99414A_DEFINED
#define DCOMP_OFF_STRUCT_DW_1757953_FIELDS_PAUSE_8B99414A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_1757953_FIELDS_PAUSE_8B99414A = (int)&(((struct dw_1757953_fields *)0)->Pause) - 0 };
#endif
void UpdateTextureScroll(void) {
    struct dw_1747825_fields *cfg;
    struct dw_1755037_fields *mng;
    struct dw_1754763_fields *param;
    s32 i;
    s32 j;
    u32 t;

    mng = (struct dw_1755037_fields *)TexScrollMng;
    param = (struct dw_1754763_fields *)lpDebugParam;
    cfg = param->TexScroll;
    if (((struct dw_1757953_fields *)GameSt)->Pause == 0) {
        for (i = 0; i < 0x20; i++, cfg++, mng++) {
            for (j = 0; j < 2; j++) {
                t = cfg->Type[j];
                if (t != 0) {
                    switch ((u8)t) {
                    case 1:
                        mng->st[j] += cfg->Speed[j];
                        if (mng->st[j] > 1.0f) {
                            mng->st[j] = mng->st[j] - 1.0f;
                        }
                        if (mng->st[j] < 0.0f) {
                            mng->st[j] = mng->st[j] + 1.0f;
                        }
                        break;
                    case 2:
                        mng->phase[j] += 3.1415927f * cfg->Speed[j];
                        if (mng->phase[j] > 3.1415927f) {
                            mng->phase[j] = mng->phase[j] - 6.2831855f;
                        }
                        if (mng->phase[j] < -3.1415927f) {
                            mng->phase[j] = mng->phase[j] + 6.2831855f;
                        }
                        mng->st[j] = cfg->Amplitude[j] * sinf(mng->phase[j]);
                        break;
                    case 3:
                        mng->st[j] += cfg->Speed[j];
                        if (mng->st[j] > 2.0f) {
                            mng->st[j] = 2.0f;
                        }
                        if (mng->st[j] < -1.0f) {
                            mng->st[j] = -1.0f;
                        }
                        break;
                    }
                } else {
                    mng->st[j] = 0;
                }
                if (cfg->Wave[j] != 0) {
                    mng->SinPhase[j] += cfg->SinSpeed[j];
                    if (mng->SinPhase[j] >= 1.0f) {
                        mng->SinPhase[j] = mng->SinPhase[j] - 1.0f;
                    }
                    mng->SinAmplitude[j] = cfg->SinAmplitude[j];
                    mng->SinWavelength[j] = cfg->SinWavelength[j];
                } else {
                    mng->SinPhase[j] = 0;
                    mng->SinAmplitude[j] = 0;
                    mng->SinWavelength[j] = 1.0f;
                }
            }
        }
    }
}


/* GetTextureScroll @ 0x1A8070 .. 0x1A809C (0x2c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void * vs inferred u32
 */


void * GetTextureScroll(unsigned int a0 /* r4 */) {
    u32 v0;

    if (!((u32)(s32)a0 < (u32)0x20)) {
        return (void *)(u32)0;
    }
    v0 = (u32)TexScrollMng;
    v0 = (s32)((u8 *)TexScrollMng + (s32)((u32)a0 * (u32)(0x28)));
    return (void *)v0;
}



extern u32 lpDebugParam;

typedef struct {
    u8 mode;
    u8 kind;
    u8 pad0[2];
    float spdU;
    float spdV;
    u8 pad1[0x20];
} BDScrollPrm;

typedef struct {
    u8 pad0[0x30];
    BDScrollPrm prm[1];
} BDDebugParam;

typedef struct {
    float ofs;
    float scale;
    u8 pad0[0x20];
} BDScrollMng;

void SetBloodDripScroll(signed int a0, signed int a1) {
    BDScrollPrm *lpTexScrollPrm;
    BDScrollMng *lpTexScrollMng;

    lpTexScrollPrm = &((BDDebugParam *)lpDebugParam)->prm[a1];
    lpTexScrollMng = (BDScrollMng *)TexScrollMng + a1;
    lpTexScrollPrm->kind = 3;
    switch (a0) {
    case 0:
        lpTexScrollPrm->spdV = 0.0f;
        lpTexScrollMng->scale = 2.0f;
        break;
    case 1:
        lpTexScrollPrm->spdV = -0.0006f;
        break;
    }
}



/* MakeCircleTexture @ 0x1A7BC0 .. 0x1A7FE4 (0x424 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   literal: @1319 is the string 'circle.tm2'
 *   fpu: mov.s at 0x1a7bf8 is a float copy
 *   fpu: float literal 0x3f000000 at 0x1a7ea0
 *   stack: address of the slot at 0x98 escapes at 0x1a7fb8
 */

extern unsigned int * MakeTexPacket(unsigned int *, void *);

#ifndef PROTO_DW_1750685_FIELDS
#define PROTO_DW_1750685_FIELDS
struct dw_1750685_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_1755674_FIELDS
#define PROTO_DW_1755674_FIELDS
struct dw_1755674_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_1751088_FIELDS
#define PROTO_DW_1751088_FIELDS
struct dw_1751088_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_1757079_FIELDS
#define PROTO_DW_1757079_FIELDS
struct dw_1757079_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_1756398_FIELDS
#define PROTO_DW_1756398_FIELDS
struct dw_1756398_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_1745981_FIELDS
#define PROTO_DW_1745981_FIELDS
struct dw_1745981_fields { struct dw_1750685_fields pmode; struct dw_1755674_fields smode2; struct dw_1751088_fields dispfb; struct dw_1757079_fields display; struct dw_1756398_fields bgcolor; };
#endif
#ifndef PROTO_DW_1749117_FIELDS
#define PROTO_DW_1749117_FIELDS
struct dw_1749117_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_1755340_FIELDS
#define PROTO_DW_1755340_FIELDS
struct dw_1755340_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_1761377_FIELDS
#define PROTO_DW_1761377_FIELDS
struct dw_1761377_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_1759481_FIELDS
#define PROTO_DW_1759481_FIELDS
struct dw_1759481_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_1754271_FIELDS
#define PROTO_DW_1754271_FIELDS
struct dw_1754271_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_1748238_FIELDS
#define PROTO_DW_1748238_FIELDS
struct dw_1748238_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1760583_FIELDS
#define PROTO_DW_1760583_FIELDS
struct dw_1760583_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1750566_FIELDS
#define PROTO_DW_1750566_FIELDS
struct dw_1750566_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_1756660_FIELDS
#define PROTO_DW_1756660_FIELDS
struct dw_1756660_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_1748428_FIELDS
#define PROTO_DW_1748428_FIELDS
struct dw_1748428_fields { struct dw_1755340_fields frame1; unsigned long frame1addr; struct dw_1761377_fields zbuf1; long zbuf1addr; struct dw_1759481_fields xyoffset1; long xyoffset1addr; struct dw_1754271_fields scissor1; long scissor1addr; struct dw_1748238_fields prmodecont; long prmodecontaddr; struct dw_1760583_fields colclamp; long colclampaddr; struct dw_1750566_fields dthe; long dtheaddr; struct dw_1756660_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_1764865_FIELDS
#define PROTO_DW_1764865_FIELDS
struct dw_1764865_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_1750235_FIELDS
#define PROTO_DW_1750235_FIELDS
struct dw_1750235_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_1759895_FIELDS
#define PROTO_DW_1759895_FIELDS
struct dw_1759895_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_1757479_FIELDS
#define PROTO_DW_1757479_FIELDS
struct dw_1757479_fields { struct dw_1756660_fields testa; long testaaddr; struct dw_1764865_fields prim; long primaddr; struct dw_1750235_fields rgbaq; long rgbaqaddr; struct dw_1759895_fields xyz2a; long xyz2aaddr; struct dw_1759895_fields xyz2b; long xyz2baddr; struct dw_1756660_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_1760978_FIELDS
#define PROTO_DW_1760978_FIELDS
struct dw_1760978_fields { struct dw_1745981_fields disp[2]; struct dw_1749117_fields giftag0; struct dw_1748428_fields draw0; struct dw_1757479_fields clear0; struct dw_1749117_fields giftag1; struct dw_1748428_fields draw1; struct dw_1757479_fields clear1; };
#endif
#ifndef PROTO_DW_1746485_FIELDS
#define PROTO_DW_1746485_FIELDS
struct dw_1746485_fields { struct dw_1760978_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif


typedef struct CircleTex0 {
    u64 TBP0:14; u64 TBW:6; u64 PSM:6; u64 TW:4; u64 TH:4; u64 TCC:1; u64 TFX:2; u64 CBP:14; u64 CPSM:4; u64 CSM:1; u64 CSA:5; u64 CLD:3;
} CircleTex0;

unsigned int *MakeCircleTexture(unsigned int *lpCurDMA, unsigned char *FileName, float Scale) {
    u8 *lpSrcTexMng;
    u8 *lpAlphaTexMng;
    int w;
    int h;
    CircleTex0 tex0;
    CircleTex0 *pt;
    u8 *env;
    float half;

    env = (*(s32 *)(lpDrawMng + 0x408) == 0) ? lpDrawMng + 0x60 : lpDrawMng + 0x150;
    lpSrcTexMng = (u8 *)GetTexMngByName((void *)0, (char *)FileName);
    if (lpSrcTexMng == 0) return lpCurDMA;
    lpAlphaTexMng = (u8 *)GetTexMngByName((void *)0, "circle.tm2");
    if (lpAlphaTexMng == 0) return lpCurDMA;
    lpCurDMA = (unsigned int *)MakeTexPacket(lpCurDMA, lpSrcTexMng);
    pt = (CircleTex0 *)(*(u32 *)(lpAlphaTexMng + 4) + 16);
    tex0 = *pt;
    pt->TBP0 += 0x400;
    pt = (CircleTex0 *)(*(u32 *)(lpAlphaTexMng + 4) + 16);
    pt->CBP += 0x400;
    lpCurDMA = (unsigned int *)MakeTexPacket(lpCurDMA, lpAlphaTexMng);
    w = 1 << ((CircleTex0 *)(*(u32 *)(lpSrcTexMng + 4) + 16))->TW;
    h = 1 << ((CircleTex0 *)(*(u32 *)(lpSrcTexMng + 4) + 16))->TH;
    lpCurDMA[0] = 0x10000015;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x51000015;
    lpCurDMA[4] = 0xb;
    lpCurDMA[5] = 0x102b4000;
    lpCurDMA[6] = 14;
    lpCurDMA[7] = 0;
    *(u64 *)(lpCurDMA + 8) = 0;
    *(u64 *)(lpCurDMA + 10) = 0x3f;
    pt = (CircleTex0 *)(*(u32 *)(lpSrcTexMng + 4) + 16);
    *(u64 *)(lpCurDMA + 12) = ((u64)((struct { unsigned short _pad:4; unsigned short f:6; } *)((u8 *)pt + 2))->f << 24) | ((u64)(s32)((u32)pt->TBP0 >> 5) | ((u64)pt->TBW << 16)) | 0xff00000000000000ULL;
    *(u64 *)(lpCurDMA + 14) = 0x4c;
    *(u64 *)(lpCurDMA + 16) = (u64)(s32)((2048 - w / 2) << 4) | ((u64)(s32)((2048 - h / 2) << 4) << 32);
    *(u64 *)(lpCurDMA + 18) = 0x18;
    *(u64 *)(lpCurDMA + 20) = ((u64)(s32)(w - 1) << 16) | ((u64)(s32)(h - 1) << 48);
    *(u64 *)(lpCurDMA + 22) = 0x40;
    *(u64 *)(lpCurDMA + 24) = 0x100000000ULL;
    *(u64 *)(lpCurDMA + 26) = 0x4e;
    *(u64 *)(lpCurDMA + 28) = 0;
    *(u64 *)(lpCurDMA + 30) = 0x47;
    *(u64 *)(lpCurDMA + 32) = *(u64 *)(*(u32 *)(lpAlphaTexMng + 4) + 0x10);
    *(u64 *)(lpCurDMA + 34) = 6;
    *(u64 *)(lpCurDMA + 36) = *(u64 *)(*(u32 *)(lpAlphaTexMng + 4) + 0x18);
    *(u64 *)(lpCurDMA + 38) = 20;
    *(u64 *)(lpCurDMA + 40) = 5;
    *(u64 *)(lpCurDMA + 42) = 8;
    *(u64 *)(lpCurDMA + 44) = 0x8000000062ULL;
    *(u64 *)(lpCurDMA + 46) = 66;
    *(u64 *)(lpCurDMA + 48) = 0x3f80000080808080ULL;
    *(u64 *)(lpCurDMA + 50) = 1;
    lpCurDMA[52] = 2;
    lpCurDMA[53] = 0x24000000;
    lpCurDMA[54] = 66;
    lpCurDMA[55] = 0;
    half = 0.5f / Scale;
    *(float *)(lpCurDMA + 56) = 0.5f - half;
    *(float *)(lpCurDMA + 57) = 0.5f - half;
    *(u64 *)(lpCurDMA + 58) = (u64)(s32)((2048 - w) << 4) | ((u64)(s32)((2048 - h) << 4) << 16) | 0xffffffff00000000ULL;
    *(float *)(lpCurDMA + 60) = 0.5f + half;
    *(float *)(lpCurDMA + 61) = 0.5f + half;
    *(u64 *)(lpCurDMA + 62) = (u64)(s32)((w + 2048) << 4) | ((u64)(s32)((h + 2048) << 4) << 16) | 0xffffffff00000000ULL;
    lpCurDMA[64] = 5;
    lpCurDMA[65] = 0x10000000;
    lpCurDMA[66] = 14;
    lpCurDMA[67] = 0;
    *(u64 *)(lpCurDMA + 68) = 0;
    *(u64 *)(lpCurDMA + 70) = 0x3f;
    *(u64 *)(lpCurDMA + 72) = *(u64 *)env;
    *(u64 *)(lpCurDMA + 74) = 0x4c;
    *(u64 *)(lpCurDMA + 76) = *(u64 *)(env + 0x20);
    *(u64 *)(lpCurDMA + 78) = 0x18;
    *(u64 *)(lpCurDMA + 80) = *(u64 *)(env + 0x30);
    *(u64 *)(lpCurDMA + 82) = 0x40;
    *(u64 *)(lpCurDMA + 84) = *(u64 *)(env + 0x10);
    *(u64 *)(lpCurDMA + 86) = 0x4e;
    lpCurDMA += 88;
    *(CircleTex0 *)(*(u32 *)(lpAlphaTexMng + 4) + 16) = tex0;
    return lpCurDMA;
}











/* InitBloodStain @ 0x1A79F0 .. 0x1A7BC0 (0x1d0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40000000 at 0x1a7a40
 *   fpu: float literal 0x40000000 at 0x1a7a84
 *   fpu: float literal 0x461c4000 at 0x1a7b4c
 *   fpu: float literal 0x3f800000 at 0x1a7b58
 *   fpu: float literal 0x40490fdb at 0x1a7b64
 *   fpu: mtc1 reinterprets a0 at 0x1a7b70
 *   cfg: kept branch: 0x1a7ab8 if (..) goto .L001A7BA8
 *   cfg: loop body is not one contiguous region: .L001A7AE8
 *   cfg: kept branch: 0x1a7afc if (..) goto .L001A7B08
 */

extern void * memset(void *, int, unsigned int);
extern int rand();



void InitBloodStain(void) {
    u32 a0;
    s32 v1;
    float f20;
    u8 *s1;
    s32 s0;
    u32 v0;

    v1 = 0x51;
    *(u8 *)TexEffectMng = 0;
    TexEffectMng[1] = 0;
    a0 = GameSt[9];
    if (a0 == (u32)v1) {
        v1 = -0x41000000;
        *(u32 *)(TexEffectMng + 8) = 0;
        *(u32 *)(TexEffectMng + 0xc) = -0x41000000;
        v1 = 0x40000000;
        f20 = 2.0f;
        *(u32 *)(TexEffectMng + 0x14) = 0x40000000;
        v1 = 0x3b03126f;
        *(u32 *)(TexEffectMng + 0x18) = 0x3b03126f;
    } else {
        v1 = 0x3e0c0000;
        *(u32 *)(TexEffectMng + 8) = 0x3e0c0000;
        v1 = -0x41b00000;
        *(u32 *)(TexEffectMng + 0xc) = -0x41b00000;
        v1 = 0x40000000;
        *(u32 *)(TexEffectMng + 0x14) = 0x40000000;
        f20 = 2.0f;
        v1 = 0x3ba3d70a;
        *(u32 *)(TexEffectMng + 0x18) = 0x3ba3d70a;
    }
    *(u32 *)(TexEffectMng + 0x10) = 0;
    v1 = 0x51;
    *(u32 *)(TexEffectMng + 0x1c) = 0;
    *(u32 *)(TexEffectMng + 4) = 0;
    if (a0 != (u32)v1) {
        v1 = 0x53;
        if (a0 != (u32)v1) {
            goto _L001A7BA8;
        }
    }
    s1 = (u8 *)BloodControlMng;
    memset((void *)BloodStainMng, 0, 0x2000);
    for (s0 = 0; s0 < 16; s0++) {
        *(u16 *)s1 = rand() % 0x1000 - 0x800;
        *(u16 *)(s1 + 2) = rand() % 0x1000 - 0x800;
        *(u16 *)(s1 + 4) = 0xc0;
        *(u16 *)(s1 + 6) = 0xc0;
        *(f32 *)(s1 + 8) = 3.1415927f * ((f20 * ((float)(rand() % 0x2711) / 1e+04f)) - 1.0f);
        *(u32 *)(s1 + 0xc) = 0;
        s1 = s1 + 0x10;
    }
    v1 = 1;
    *(u8 *)TexEffectMng = v1;
    _L001A7BA8:;
    return;
}







/* CheckBloodStain @ 0x1A79E0 .. 0x1A79EC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x1a79e8 computes the return value
 *   spans: lui at at 0x1a79e0 read at 0x1a79e8 before its %lo
 */




u8 CheckBloodStain(void) {
    return *(u8 *)TexEffectMng;
}





/* SetBloodPoolScale @ 0x1A79D0 .. 0x1A79DC (0xc bytes) */


void SetBloodPoolScale(float f12 /* f12 */) {
    *(f32 *)((u8 *)&TexEffectMng + 0x1c) = f12;
    return;
}








unsigned int * MakeBloodStain(unsigned int *lpCurDMA) {
    void *lpSrcTexMng;
    void *lpAlphaTexMng;

    lpSrcTexMng = GetTexMngByName((void *)0, "s0080_010.tm2");
    lpAlphaTexMng = GetTexMngByName((void *)0, "s0080_015.tm2");
    if (GameSt[0xf] == 0) {
        UpdateBloodStain();
    }
    lpCurDMA = MakeBloodStainTexture(lpCurDMA, lpSrcTexMng, lpAlphaTexMng);
    if (*(float *)(TexEffectMng + 0x1c) < 1.0f) {
        lpSrcTexMng = GetTexMngByName((void *)0, "s0080_018.tm2");
        lpCurDMA = MakeCrackTexture(lpCurDMA, lpSrcTexMng, GetTexMngByName((void *)0, "s0080_021.tm2"), 0.0f,
            0.0f, *(float *)(TexEffectMng + 0x1c));
    }
    return RestoreDrawEnv(lpCurDMA);
}






/* SetCrackWall @ 0x1A78D0 .. 0x1A78DC (0xc bytes) */


void SetCrackWall(s32 a0 /* r4 */) {
    *(u32 *)((u8 *)&TexEffectMng + 4) = a0;
    return;
}


/* CheckCrackWall @ 0x1A7890 .. 0x1A78C8 (0x38 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1a789c writes a register its branch at 0x1a7898 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int CheckCrackWall(void *a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v0 = *(u8 *)TexEffectMng;
    if (v0 == 0) {
        return 0;
    }
    v1 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(s32 *)(TexEffectMng + 4);
    v1 = *(s32 *)((v1 + 0x44));
    return ((u32)(v1 ^ (u32)v0)) < (u32)1;
}


/* MakeCrackWall @ 0x1A7780 .. 0x1A788C (0x10c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1175 is the string 's0080_016.tm2'
 *   literal: @1176 is the string 's0080_020.tm2'
 *   literal: @1177 is the string 's0080_019.tm2'
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */


unsigned int * MakeCrackWall(unsigned int *lpCurDMA) {
    void *lpSrcTexMng;
    void *lpAlphaTexMng;

    lpSrcTexMng = GetTexMngByName((void *)0, "s0080_016.tm2");
    if (TexEffectMng[1] != 0) {
        lpAlphaTexMng = GetTexMngByName((void *)0, "s0080_020.tm2");
    } else {
        lpAlphaTexMng = GetTexMngByName((void *)0, "s0080_019.tm2");
    }
    lpCurDMA = MakeCrackTexture(lpCurDMA, lpSrcTexMng, lpAlphaTexMng, *(float *)(TexEffectMng + 8),
        *(float *)(TexEffectMng + 0xc), *(float *)(TexEffectMng + 0x10));
    if (GameSt[0xf] == 0 && CheckEventFlag(0x1a8) != 0) {
        *(f32 *)(TexEffectMng + 0x10) += *(float *)(TexEffectMng + 0x18);
        if (*(f32 *)(TexEffectMng + 0x10) > *(float *)(TexEffectMng + 0x14)) {
            *(f32 *)(TexEffectMng + 0x10) = 0.0f;
            TexEffectMng[1] = !TexEffectMng[1];
        }
    }
    return RestoreDrawEnv(lpCurDMA);
}



/* UpdateBloodStain @ 0x1A73D0 .. 0x1A7780 (0x3b0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41800000 at 0x1a74f0
 *   fpu: float literal 0x41800000 at 0x1a7550
 *   fpu: float literal 0x461c4000 at 0x1a75bc
 *   fpu: float literal 0x40000000 at 0x1a75c4
 *   fpu: float literal 0x3f800000 at 0x1a75cc
 *   fpu: float literal 0x3c0ef34d at 0x1a75d8
 *   fpu: float literal 0x3db2b020 at 0x1a75e4
 *   fpu: mtc1 reinterprets v0 at 0x1a75ec
 *   fpu: float literal 0xbdb2b020 at 0x1a7628
 *   fpu: float literal 0x40490fdb at 0x1a7650
 *   fpu: float literal 0x00000000 at 0x1a7654
 *   fpu: float literal 0x40c90fdb at 0x1a7674
 *   fpu: float literal 0x40c90fdb at 0x1a769c
 *   cfg: loop body is not one contiguous region: .L001A73F8
 *   cfg: loop body is not one contiguous region: .L001A7458
 *   cfg: loop body is not one contiguous region: .L001A7468
 *   cfg: kept branch: 0x1a7468 if (..) goto .L001A7480
 *   cfg: kept goto: 0x1a7474 -> .L001A7498
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern int rand();
extern u8 BloodStainMng[];
extern u16 BloodControlMng[];

void UpdateBloodStain(void) {
    u8 *a1;
    u32 a0;
    u8 *s1;
    s32 v1;
    u32 s2;
    s32 v0;
    float f12;
    float f3;
    float f2;
    s32 hi;
    float f1;
    float f0;
    u8 *s0;

    a1 = BloodStainMng;
    a0 = 0;
    s1 = (u8 *)BloodControlMng;
    do {
        v1 = *(u8 *)a1;
        if ((u32)v1 != 0) {
            v1 = *(u8 *)(a1 + 0xf);
            if (v1 > (s32)1) {
                v1 = v1 + -1;
                *(u8 *)(a1 + 0xf) = v1;
            } else {
                *(u8 *)a1 = 0;
            }
            v1 = *(s16 *)(a1 + 8);
            v1 = v1 + -8;
            *(u16 *)(a1 + 8) = v1;
            v1 = *(s16 *)(a1 + 0xa);
            v1 = v1 + -8;
            *(u16 *)(a1 + 0xa) = v1;
        }
        a0 = a0 + 1;
        v1 = (s32)a0 < (s32)0x200;
        a1 = (u8 *)(a1 + 0x10);
    } while (v1 != 0);
    s0 = (u8 *)0;
    do {
        {
            u8 *cursor;
            u8 *selected;
            cursor = BloodStainMng;
            a0 = 0;
            do {
                if (!*cursor) {
                    selected = cursor;
                    goto found;
                }
                ++a0;
                cursor += 16;
            } while ((s32)a0 < 512);
            selected = 0;
found:
            a1 = selected;
        }
        if ((u32)a1 != 0) {
            v0 = 1;
            v1 = 0x80;
            *(u8 *)a1 = v0;
            a0 = *(s16 *)s1;
            v0 = 0x20;
            *(u16 *)(a1 + 4) = a0;
            a0 = *(s16 *)(s1 + 2);
            *(u16 *)(a1 + 6) = a0;
            a0 = *(s16 *)(s1 + 4);
            *(u16 *)(a1 + 8) = a0;
            a0 = *(s16 *)(s1 + 6);
            *(u16 *)(a1 + 0xa) = a0;
            *(u8 *)(a1 + 0xc) = v1;
            *(u8 *)(a1 + 0xd) = v1;
            *(u8 *)(a1 + 0xe) = v1;
            *(u8 *)(a1 + 0xf) = v0;
            f0 = cosf(*(float *)(s1 + 8));
            *(s16 *)s1 += (s16)(16.0f * f0);
            v0 = *(s16 *)s1;
            if (v0 > (s32)0x800) {
                v0 = v0 + -0x1000;
                *(u16 *)s1 = v0;
            }
            v0 = *(s16 *)s1;
            if (v0 <= (s32)-0x801) {
                v0 = v0 + 0x1000;
                *(u16 *)s1 = v0;
            }
            f0 = sinf(*(float *)(s1 + 8));
            *(s16 *)(s1 + 2) += (s16)(16.0f * f0);
            v0 = *(s16 *)(s1 + 2);
            if (v0 > (s32)0x800) {
                v0 = v0 + -0x1000;
                *(u16 *)(s1 + 2) = v0;
            }
            v0 = *(s16 *)(s1 + 2);
            if (v0 <= (s32)-0x801) {
                v0 = v0 + 0x1000;
                *(u16 *)(s1 + 2) = v0;
            }
            v0 = rand();
            a0 = 0x2711;
            v1 = 0x461c0000;
            hi = v0 % 0x2711;
            v0 = 0x461c0000 | 0x4000;
            v0 = hi;
            f1 = (*(f32 *)(s1 + 0xc) += (0.008725f * ((2.0f * ((float)((float)(s32)(u32)v0) /
                1e+04f)) - 1.0f)));
            if (!(f1 <= 0.087249994f)) {
                *(f32 *)(s1 + 0xc) = 0.087249994f;
            } else {
                v0 = -0x424d4fe0;
                if (f1 < -0.087249994f) {
                    *(f32 *)(s1 + 0xc) = -0.087249994f;
                }
            }
            {
                float shifted, angle;
                angle = (*(float *)(s1 + 8) += *(float *)(s1 + 0xc));
                shifted = 3.1415927f + angle;
                if (shifted >= 0.0f) {
                    f0 = angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f);
                } else {
                    f0 = 6.2831855f + (angle - 6.2831855f * (float)(s32)(shifted / 6.2831855f));
                }
                *(float *)(s1 + 8) = f0;
            }
            v0 = rand();
            a0 = 3;
            v1 = 1;
            a0 = v0 % 3;
            s2 = a0 + -1;
            if (s2 == (u32)v1) {
                v0 = rand();
                v1 = v0 % 2;
                s2 = s2 + v1;
            }
            *(s16 *)(s1 + 4) += (s16)s2;
            v1 = *(s16 *)(s1 + 4);
            if (v1 > (s32)0x300) {
                *(u16 *)(s1 + 4) = 0x300;
            } else if (v1 <= (s32)0x3f) {
                *(u16 *)(s1 + 4) = 0x40;
            }
            v1 = *(s16 *)(s1 + 4);
            *(u16 *)(s1 + 6) = v1;
        }
        s0 = (u8 *)(s0 + 1);
        v1 = (s32)s0 < (s32)0x10;
        s1 = (u8 *)(s1 + 0x10);
    } while (v1 != 0);
    return;
}



static unsigned int *ReplaceDrawEnv(unsigned int *, void *);
extern u8 BloodStainMng[];
static unsigned int *MakeBloodStainTexture(unsigned int *packet, void *texture, void *data) {
    u32 info = (u32)data;
    s32 stain = (s32)BloodStainMng;
    s32 i;
    if (texture == 0 || info == 0) return packet;
    {
        packet = ReplaceDrawEnv(packet, texture);
        packet[0] = 0x10000005; packet[1] = 0; packet[2] = 0; packet[3] = 0x51000005;
        packet[4] = 4; packet[5] = 0x102b4000; packet[6] = 14; packet[7] = 0;
        *(u64 *)(packet + 8) = 0; *(u64 *)(packet + 10) = 71;
        *(u64 *)(packet + 12) = *(u64 *)(*(u32 *)(info + 4) + 0x10);
        *(u64 *)(packet + 14) = 6;
        *(u64 *)(packet + 16) = *(u64 *)(*(u32 *)(info + 4) + 0x18);
        *(u64 *)(packet + 18) = 20;
        *(u64 *)(packet + 20) = 0x8000000042ULL;
        *(u64 *)(packet + 22) = 66;
        packet += 24;
        i = 0;
        do {
            if (*(u8 *)stain != 0) {
                s32 y, x, dy, dx;
                packet[0] = 0x10000004; packet[1] = 0; packet[2] = 0; packet[3] = 0x51000004;
                packet[4] = 2; packet[5] = 0x34000000; packet[6] = 0x421; packet[7] = 0;
                packet[8] = *(u32 *)(stain + 12); packet[9] = 0x3f800000; packet[10] = 0; packet[11] = 0;
                y = *(s16 *)(stain + 6); x = *(s16 *)(stain + 4); dy = *(s16 *)(stain + 10); dx = *(s16 *)(stain + 8);
                *(u64 *)(packet + 12) = (u64)(s32)(x + 32768 - dx) | ((u64)(s32)(y + 32768 - dy) << 16) | 0xffffffff00000000ULL;
                packet[14] = *(u32 *)(stain + 12); packet[15] = 0x3f800000; packet[16] = 0x3f800000; packet[17] = 0x3f800000;
                y = *(s16 *)(stain + 6); x = *(s16 *)(stain + 4); dy = *(s16 *)(stain + 10); dx = *(s16 *)(stain + 8);
                *(u64 *)(packet + 18) = (u64)(s32)(x + 32768 + dx) | ((u64)(s32)(y + 32768 + dy) << 16) | 0xffffffff00000000ULL;
                packet += 20;
            }
            i++; stain += 16;
        } while (i < 512);
    }
    return packet;
}








/* MakeCrackTexture @ 0x1A6FD0 .. 0x1A71D0 (0x200 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x1a7060
 *   fpu: float literal 0x3f000000 at 0x1a7170
 *   cfg: kept branch: 0x1a6ff4 if (..) goto .L001A7008
 *   cfg: kept goto: 0x1a7000 -> .L001A71B0
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */


typedef struct CrackTex0 {
    u64 base:14; u64 width:6; u64 format:6; u64 logWidth:4; u64 logHeight:4; u64 rest:30;
} CrackTex0;

static unsigned int *ReplaceDrawEnv(unsigned int *packet, void *texture);
static unsigned int *MakeCrackTexture(unsigned int *lpCurDMA, void *lpSrcTexMng, void *lpAlphaTexMng, float CenterS, float CenterT, float Scale) {
    int w;
    int h;
    float inv;
    float half;
    CrackTex0 *tex;
    if (lpSrcTexMng == 0 || lpAlphaTexMng == 0) return lpCurDMA;
    tex = (CrackTex0 *)(*(u32 *)((u8 *)lpSrcTexMng + 4) + 16);
    w = 1 << tex->logWidth;
    h = 1 << tex->logHeight;
    lpCurDMA = ReplaceDrawEnv(lpCurDMA, lpSrcTexMng);
    lpCurDMA[0] = 0x1000000a;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x5100000a;
    lpCurDMA[4] = 6;
    lpCurDMA[5] = 0x102b4000;
    lpCurDMA[6] = 14;
    lpCurDMA[7] = 0;
    *(u64 *)(lpCurDMA + 8) = 0;
    *(u64 *)(lpCurDMA + 10) = 71;
    *(u64 *)(lpCurDMA + 12) = *(u64 *)(*(u32 *)((u8 *)lpAlphaTexMng + 4) + 0x10);
    *(u64 *)(lpCurDMA + 14) = 6;
    *(u64 *)(lpCurDMA + 16) = *(u64 *)(*(u32 *)((u8 *)lpAlphaTexMng + 4) + 0x18);
    *(u64 *)(lpCurDMA + 18) = 20;
    *(u64 *)(lpCurDMA + 20) = 5;
    *(u64 *)(lpCurDMA + 22) = 8;
    *(u64 *)(lpCurDMA + 24) = 0x8000000062ULL;
    *(u64 *)(lpCurDMA + 26) = 66;
    *(u64 *)(lpCurDMA + 28) = 0x3f80000080808080ULL;
    *(u64 *)(lpCurDMA + 30) = 1;
    lpCurDMA[32] = 2;
    lpCurDMA[33] = 0x24000000;
    lpCurDMA[34] = 66;
    lpCurDMA[35] = 0;
    CenterS = CenterS / Scale;
    CenterT = CenterT / Scale;
    inv = 1.0f / Scale;
    Scale = 0.5f * (inv - 1.0f);
    half = Scale;
    *(float *)(lpCurDMA + 36) = CenterS - half;
    *(float *)(lpCurDMA + 37) = CenterT - half;
    *(u64 *)(lpCurDMA + 38) = (u64)(s32)((2048 - w) << 4) | ((u64)(s32)((2048 - h) << 4) << 16) | 0xffffffff00000000ULL;
    *(float *)(lpCurDMA + 40) = 1.0f + (CenterS + half);
    *(float *)(lpCurDMA + 41) = 1.0f + (CenterT + half);
    *(u64 *)(lpCurDMA + 42) = (u64)(s32)((w + 2048) << 4) | ((u64)(s32)((h + 2048) << 4) << 16) | 0xffffffff00000000ULL;
    return lpCurDMA + 44;
}


typedef struct EnvTex0 {
    u64 base:14; u64 width:6; u64 format:6; u64 logWidth:4; u64 logHeight:4; u64 rest:30;
} EnvTex0;
static unsigned int *ReplaceDrawEnv(unsigned int *packet, void *texture)
{
    s32 width;
    s32 height;
    EnvTex0 *tex = (EnvTex0 *)(*(u32 *)((u8 *)texture + 4) + 16);
    width = 1 << tex->logWidth;
    height = 1 << tex->logHeight;
    packet[0] = 0x10000006;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0x51000006;
    packet[4] = 5;
    packet[5] = 0x10000000;
    packet[6] = 14;
    packet[7] = 0;
    *(u64 *)(packet + 8) = 0;
    *(u64 *)(packet + 10) = 0x3f;
    tex = (EnvTex0 *)(*(u32 *)((u8 *)texture + 4) + 16);
    *(u64 *)(packet + 12) = ((u64)tex->format << 24) | ((u64)(s32)((u32)tex->base >> 5) | ((u64)tex->width << 16)) | 0xff00000000000000ULL;
    *(u64 *)(packet + 14) = 0x4c;
    *(u64 *)(packet + 16) = (u64)(s32)((2048 - width / 2) << 4) | ((u64)(s32)((2048 - height / 2) << 4) << 32);
    *(u64 *)(packet + 18) = 0x18;
    *(u64 *)(packet + 20) = ((u64)(s32)(width - 1) << 16) | ((u64)(s32)(height - 1) << 48);
    *(u64 *)(packet + 22) = 0x40;
    *(u64 *)(packet + 24) = 0x100000000ULL;
    *(u64 *)(packet + 26) = 0x4e;
    return packet + 28;
}


/* RestoreDrawEnv @ 0x1A6DC0 .. 0x1A6E6C (0xac bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned int * vs inferred u32
 */


static unsigned int * RestoreDrawEnv(unsigned int *a0 /* r4 */) {
    u8 *t2;
    s32 a2;
    u8 *v1;
    u32 v0;
    u64 t1_64;
    u64 t0_64;
    u64 a3_64;
    u64 a2_64;

    v1 = (u8 *)lpDrawMng;
    v0 = *(s32 *)(v1 + 0x408);
    t2 = (u8 *)(v1 + 0x150);
    t2 = (u8 *)(v0 == 0 ? (s32)(v1 + 0x60) : t2);
    v0 = 0x51000000;
    a2 = 0x10000000;
    *(u32 *)a0 = 0x10000000 | 7;
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0x51000000 | 7;
    a0[4] = (s32)(u8 *)(s32)6;
    a0[5] = 0x10000000;
    a0[6] = 0xe;
    a0[7] = 0;
    *(u64 *)(((u8 *)a0 + 0x20)) = 0;
    *(s64 *)(((u8 *)a0 + 0x28)) = (s32)0x3f;
    t1_64 = *(u64 *)t2;
    *(u64 *)(((u8 *)a0 + 0x30)) = t1_64;
    *(s64 *)(((u8 *)a0 + 0x38)) = (s32)0x4c;
    t0_64 = *(u64 *)(t2 + 0x20);
    *(u64 *)(((u8 *)a0 + 0x40)) = t0_64;
    *(s64 *)(((u8 *)a0 + 0x48)) = (s32)0x18;
    a3_64 = *(u64 *)(t2 + 0x30);
    *(u64 *)(((u8 *)a0 + 0x50)) = a3_64;
    *(s64 *)(((u8 *)a0 + 0x58)) = (s32)0x40;
    a2_64 = *(u64 *)(t2 + 0x10);
    *(u64 *)(((u8 *)a0 + 0x60)) = a2_64;
    *(s64 *)(((u8 *)a0 + 0x68)) = (s32)0x4e;
    *(u64 *)(((u8 *)a0 + 0x70)) = 0;
    *(s64 *)(((u8 *)a0 + 0x78)) = (s32)(u8 *)(s32)8;
    return (unsigned int *)(u8 *)(a0 + 0x20);
}





