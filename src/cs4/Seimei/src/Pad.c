#include "common.h"
static u32 PadVib[0x10];

static u8 PadVibPlan[0x180];
void PadSetVib(signed int port, float frame, float power, unsigned char addtype, unsigned char vibtype, signed int TimeLag);

/* SetPadVibHeart @ 0x13D120 .. 0x13D1D4 (0xb4 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40400000 at 0x13d138
 *   fpu: float literal 0x41f00000 at 0x13d140
 *   fpu: float literal 0x40400000 at 0x13d15c
 *   fpu: float literal 0x42700000 at 0x13d16c
 *   fpu: float literal 0x40400000 at 0x13d184
 *   fpu: float literal 0x3f800000 at 0x13d194
 *   fpu: float literal 0x40400000 at 0x13d1ac
 *   fpu: float literal 0x3f800000 at 0x13d1bc
 */

extern void PadSetVib(signed int, float, float, unsigned char, unsigned char, signed int);
extern u8 GameSt[];

/* CheckPadEnable @ 0x13D1E0 .. 0x13D240 (0x60 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13d1fc writes a register its branch at 0x13d1f8 reads
 *   delay: daddu at 0x13d220 writes a register its branch at 0x13d21c reads
 *   cfg: kept branch: 0x13d1e0 if (..) goto .L0013D210
 *   cfg: kept branch: 0x13d200 if (..) goto .L0013D210
 *   cfg: kept goto: 0x13d20c -> .L0013D238
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 PadState[2];
extern u32 PadReqState[2];

/* CheckResetPad @ 0x13D240 .. 0x13D388 (0x148 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: dsll32 at 0x13d2f0 writes a register its branch at 0x13d2ec reads
 *   cfg: kept branch: 0x13d2f0 if (..) goto .L0013D368
 *   cfg: kept branch: 0x13d308 if (..) goto .L0013D360
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern signed int KnMenu_CheckSaveLoadSoftResetOff(void);
extern u32 Menu_TD_IsPlay(void);
extern int FileCheckAsyncBusy(void);
extern signed int CheckNowFade(signed int);
extern void SetGoToTitleFade(void);
extern u32 lpPadData[2];
u32 lpPadData[0x2];
static u32 PadState[0x2];
static u32 PadReqState[0x2];

static u32 PushTimer_898;

/* CheckResetPad @ 0x13D240 .. 0x13D388 (0x148 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: dsll32 at 0x13d2f0 writes a register its branch at 0x13d2ec reads
 *   cfg: kept branch: 0x13d2f0 if (..) goto .L0013D368
 *   cfg: kept branch: 0x13d308 if (..) goto .L0013D360
 *   declaration vs inferred signature: return int vs inferred u32
 */

#ifndef PROTO_DW_223293_FIELDS
#define PROTO_DW_223293_FIELDS
struct dw_223293_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_223293_FIELDS_PADPORT_FC990377_DEFINED
#define DCOMP_OFF_STRUCT_DW_223293_FIELDS_PADPORT_FC990377_DEFINED
enum { DCOMP_OFF_STRUCT_DW_223293_FIELDS_PADPORT_FC990377 = (int)&(((struct dw_223293_fields *)0)->padport) - 0 };
#endif

/* CheckPauseEnable @ 0x13D390 .. 0x13D494 (0x104 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x13d3a4 writes a register its branch at 0x13d3a0 reads
 *   delay: daddu at 0x13d468 writes a register its branch at 0x13d464 reads
 *   cfg: kept branch: 0x13d3b0 if (..) goto .L0013D3C8
 *   cfg: kept goto: 0x13d3c4 -> .L0013D488
 *   cfg: kept branch: 0x13d3c8 if (..) goto .L0013D3E0
 *   cfg: kept goto: 0x13d3dc -> .L0013D488
 *   cfg: kept branch: 0x13d3e0 if (..) goto .L0013D3F8
 *   cfg: kept goto: 0x13d3f4 -> .L0013D488
 *   cfg: kept branch: 0x13d3f8 if (..) goto .L0013D410
 *   cfg: kept goto: 0x13d40c -> .L0013D488
 *   cfg: kept branch: 0x13d410 if (..) goto .L0013D428
 *   cfg: kept goto: 0x13d424 -> .L0013D488
 *   cfg: kept branch: 0x13d428 if (..) goto .L0013D440
 *   cfg: kept goto: 0x13d43c -> .L0013D488
 *   cfg: kept branch: 0x13d440 if (..) goto .L0013D458
 *   cfg: kept goto: 0x13d454 -> .L0013D488
 */

extern signed int CheckNowFade(signed int);
extern u32 GetDramaReadFlag(void);
extern u32 CheckRiddleMode(void);
extern signed int CheckMyPauseDisable(void);
extern u8 GameSt[];
void PadUpdate(void);

/* PadControl @ 0x13D5B0 .. 0x13D630 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x2e escapes at 0x13d5dc
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

void PadUpdate(void);
void GetAnalogPad(void *a0 , unsigned short *a1 );
extern void GetAnalogPad(void *, unsigned short *);

/* PadUpdate @ 0x13D630 .. 0x13D77C (0x14c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x13d6b4 writes a register its branch at 0x13d6b0 reads
 *   delay: daddu at 0x13d6d8 writes a register its branch at 0x13d6d4 reads
 *   cfg: loop body is not one contiguous region: .L0013D668
 *   cfg: kept branch: 0x13d6b4 if (..) goto .L0013D6C8
 *   v0#12 is the pointer held in s0#1+0x0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void fspad_PadUpdate(void);
static void UpdatePadVibPlan(void);
static void UpdatePadVibPlan(void);
extern int scePadGetState(int, int);
extern int scePadGetReqState(int, int);
extern signed int fspad_PadModeAnalog(signed int, signed int, signed int);
extern void * fspad_PadRead(signed int, signed int);
extern void *memset();
static void UpdatePadVib(signed int a0 );
static void UpdatePadVib(signed int);
extern u32 lpPadData[2];

/* UpdatePadVibPlan @ 0x13D780 .. 0x13D8E4 (0x164 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x4f000000 at 0x13d830
 *   cfg: loop body is not one contiguous region: .L0013D7A8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void fspad_PadSetVibra(signed int, signed int, unsigned int);
extern void fspad_PadSetSmallVibra(signed int, signed int, unsigned short);
extern u32 PadVib[];

/* PadSetVib @ 0x13DA60 .. 0x13DBE8 (0x188 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x13da9c is a float copy
 *   fpu: mov.s at 0x13daa4 is a float copy
 *   fpu: float literal 0x427c0000 at 0x13db58
 *   fpu: float literal 0x437f0000 at 0x13db5c
 *   cfg: loop body is not one contiguous region: .L0013DAB8
 *   cfg: kept branch: 0x13dab8 if (..) goto .L0013DAF8
 *   cfg: kept goto: 0x13daf0 -> .L0013DB10
 *   declaration vs inferred signature: return void vs inferred u32
 */

#ifndef PROTO_DW_224820_FIELDS
#define PROTO_DW_224820_FIELDS
struct dw_224820_fields { float NowLPower; float AddLPower; float SmallFrame; float LargeFrame; int NowSPower; int AddType; int unused[2]; };
#endif
#ifndef PROTO_DW_222339_FIELDS
#define PROTO_DW_222339_FIELDS
struct dw_222339_fields { unsigned char bUse; unsigned char Type; unsigned char unused[6]; unsigned int Frame; int Port; struct dw_224820_fields PadVib; };
#endif
#ifndef PROTO_DW_223293_FIELDS
#define PROTO_DW_223293_FIELDS

#endif


/* PadVibAllClear @ 0x13DBF0 .. 0x13DC7C (0x8c bytes, frame 0x20) */

extern void fspad_PadSetVibra(signed int, signed int, unsigned int);
extern void fspad_PadSetSmallVibra(signed int, signed int, unsigned short);
extern u32 PadVib[];

/* SetPadDefaultRepeat @ 0x13DD20 .. 0x13DD98 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void fspad_PadSetRepeat(signed int, signed int, unsigned short, unsigned short, unsigned short);

/* InitPad @ 0x13DDA0 .. 0x13DF00 (0x160 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   v0#8 is the pointer held in s0#1+0x0
 */

extern signed int fspad_PadInit(signed int);
extern signed int fspad_PadPortOpen(signed int, signed int);
extern signed int fspad_PadSetAnalogEdgeMode(signed int, signed int, unsigned char);
extern void fspad_PadSetVibraSepMode(signed int, signed int, unsigned short);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitPad(void);
u32 SetPadDefaultRepeat(void);
void SetPadVibFlag(unsigned char a0 );
void PadVibAllClear(void);
void PadSetVib(signed int port, float frame, float power, unsigned char addtype, unsigned char vibtype, signed int TimeLag);
static void UpdatePadVib(signed int a0 );
static void UpdatePadVibPlan(void);
void PadUpdate(void);
void PadControl(void);
void GetAnalogPad(void *a0 , unsigned short *a1 );
static u32 CheckPauseEnable(void);
int CheckResetPad(void);
signed int CheckPadEnable(unsigned char a0 );
void SetPadVibHeart(void);


void InitPad(void) {
    s32 s2;
    u8 *s1;
    u32 s0;
    u32 a0;
    u32 v1;
    u32 v0;

    s1 = (u8 *)PadVib;
    fspad_PadInit(0);
    s2 = 0;
    s0 = (u32)&lpPadData;
    do {
        fspad_PadPortOpen(s2, 0);
        fspad_PadSetAnalogEdgeMode(s2, 0, 1);
        fspad_PadSetVibraSepMode(s2, 0, 1);
        fspad_PadSetVibra(s2, 0, 0);
        fspad_PadSetSmallVibra(s2, 0, 0);
        memset((u32)s1, 0, (s32)0x20);
        a0 = (u32)PadVibPlan;
        memset(PadVibPlan, 0, (s32)0x180);
        v0 = (u32)fspad_PadRead(s2, 0);
        *(u32 *)s0 = v0;
        s2 = s2 + 1;
        v1 = *(s32 *)s0;
        a0 = 0x7f;
        v0 = s2 < (s32)2;
        s1 = (u8 *)(s1 + 0x20);
        *(u8 *)((v1 + 6)) = a0;
        v1 = *(s32 *)s0;
        *(u8 *)((v1 + 7)) = a0;
        v1 = *(s32 *)s0;
        *(u8 *)((v1 + 4)) = a0;
        v1 = *(s32 *)s0;
        *(u8 *)((v1 + 5)) = a0;
        s0 = s0 + 4;
    } while (v0 != 0);
    s0 = 0;
    do {
        fspad_PadSetRepeat(s0, 0, 0xf000, 0x2d, 0xa);
        fspad_PadSetRepeat(s0, 0, 0xf0, 0x2d, 0xa);
        fspad_PadSetRepeat(s0, 0, 0xf00, 0x2d, 0xa);
        s0 = s0 + 1;
        v1 = (s32)s0 < (s32)2;
    } while (v1 != 0);
    return;
}

u32 SetPadDefaultRepeat(void) {
    u32 s0;
    u32 a0;
    s32 v1;

    s0 = 0;
    do {
        a0 = s0;
        fspad_PadSetRepeat(a0, 0, 0xf000, 0x2d, 0xa);
        a0 = s0;
        fspad_PadSetRepeat(a0, 0, 0xf0, 0x2d, 0xa);
        a0 = s0;
        fspad_PadSetRepeat(a0, 0, 0xf00, 0x2d, 0xa);
        s0 = s0 + 1;
        v1 = (s32)s0 < (s32)2;
    } while (v1 != 0);
    return;
}

/* SetPadVibFlag @ 0x13DC80 .. 0x13DD18 (0x98 bytes, frame 0x20) */

void SetPadVibFlag(unsigned char a0 /* r4 */) {
    u32 *v0;
    u32 s0;
    u32 a0_guard_word;

    GameSt[0x15] = a0;
    if (!(a0)) {
        a0_guard_word = GameSt[0xa];
        v0 = PadVib;
        s0 = (s32)((u8 *)PadVib + (s32)(a0_guard_word << 5));
        fspad_PadSetVibra(a0_guard_word, 0, 0);
        *(u32 *)s0 = 0;
        *(u32 *)((s0 + 4)) = 0;
        *(u32 *)((s0 + 0xc)) = 0;
        s0 = GameSt[0xa];
        fspad_PadSetSmallVibra(s0, 0, 0);
        v0 = PadVib;
        a0_guard_word = (u32)PadVibPlan;
        *(u32 *)(((u8 *)(u32 *)((u8 *)PadVib + (s32)(s0 << 5)) + 8)) = 0;
        memset(PadVibPlan, 0, (s32)0x180);
    }
    return;
}

void PadVibAllClear(void) {
    u32 *v0;
    u32 a0;
    u32 s0;

    v0 = PadVib;
    a0 = GameSt[0xa];
    s0 = (s32)((u8 *)PadVib + (s32)(a0 << 5));
    fspad_PadSetVibra(a0, 0, 0);
    *(u32 *)s0 = 0;
    *(u32 *)((s0 + 4)) = 0;
    *(u32 *)((s0 + 0xc)) = 0;
    s0 = GameSt[0xa];
    fspad_PadSetSmallVibra(s0, 0, 0);
    v0 = PadVib;
    a0 = (u32)PadVibPlan;
    *(u32 *)(((u8 *)(u32 *)((u8 *)PadVib + (s32)(s0 << 5)) + 8)) = 0;
    memset((s32)PadVibPlan, 0, 0x180);
    return;
}

void PadSetVib(signed int port, float frame, float power, unsigned char addtype, unsigned char vibtype, signed int TimeLag) {
    struct dw_222339_fields *lpPlan;
    struct dw_224820_fields *lpPadVib;
    unsigned int PlayFrame;
    int Spower;
    int i;

    if (((struct dw_223293_fields *)GameSt)->PadVib != 0) {
        lpPlan = (struct dw_222339_fields *)PadVibPlan;
        for (i = 0; i < 8; i++, lpPlan++) {
            if (lpPlan->bUse == 0) {
                if (i < 8) {
                    memset(&((struct dw_222339_fields *)PadVibPlan)[i], 0, 0x30);
                }
                lpPlan = (struct dw_222339_fields *)(u32)(s32)lpPlan;
                goto found;
            }
        }
        lpPlan = 0;
found:
        if (lpPlan != 0) {
            lpPadVib = &lpPlan->PadVib;
            PlayFrame = ((struct dw_223293_fields *)GameSt)->SystemCounter + 1 + TimeLag;
            lpPlan->bUse = 1;
            lpPlan->Frame = PlayFrame;
            lpPlan->Port = port;
            lpPlan->Type = vibtype;
            if (vibtype == 0) {
                lpPadVib->AddType = addtype;
                if (addtype == 0) {
                    lpPadVib->NowLPower = 63.0f + power;
                    if (!(lpPadVib->NowLPower <= 255.0f)) {
                        lpPadVib->NowLPower = 255.0f;
                    }
                    lpPadVib->AddLPower = 0;
                    lpPadVib->LargeFrame = frame;
                } else {
                    lpPadVib->AddLPower = power;
                    lpPadVib->LargeFrame = frame;
                }
            } else {
                Spower = (int)power;
                if (Spower > 1) {
                    Spower = 1;
                }
                lpPadVib->NowSPower = Spower;
                lpPadVib->SmallFrame = frame;
            }
        }
    }
}

/* UpdatePadVib @ 0x13D8F0 .. 0x13DA54 (0x164 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x13d90c
 *   fpu: float literal 0x3f800000 at 0x13d92c
 *   fpu: float literal 0x437f0000 at 0x13d954
 *   fpu: float literal 0x4f000000 at 0x13d990
 *   fpu: float literal 0x00000000 at 0x13d9fc
 *   fpu: float literal 0x3f800000 at 0x13da10
 */





static void UpdatePadVib(signed int a0 /* r4 */) {
    s32 s1;
    float f3;
    u8 *s0;
    float f1;
    u32 v1;

    v1 = (u32)PadVib;
    f3 = 0.0f;
    s0 = (u8 *)((u8 *)PadVib + (u32)((u32)a0 << 5));
    f1 = *(float *)(s0 + 0xc);
    s1 = a0;
    if (!(s32)(f1 <= 0.0f)) {
        *(f32 *)(s0 + 0xc) = (f1 - 1.0f);
        a0 = *(s32 *)(s0 + 0x14);
        if ((u32)(s32)a0 == (u32)1) {
            f1 = (*(float *)s0 + (float)*(float *)(s0 + 4));
            *(f32 *)s0 = f1;
            if (!(s32)(f1 <= 255.0f)) {
                *(f32 *)s0 = 255.0f;
            } else if (f1 < f3) {
                *(f32 *)s0 = f3;
            }
            f1 = *(float *)s0;
            fspad_PadSetVibra(s1, 0, (u32)f1);
        }
    } else {
        fspad_PadSetVibra(a0, 0, 0);
        *(u32 *)s0 = 0;
        *(u32 *)(s0 + 4) = 0;
        *(u32 *)(s0 + 0xc) = 0;
    }
    f1 = *(float *)(s0 + 8);
    v1 = 0x3f800000;
    if (!(f1 <= 0.0f)) {
        *(f32 *)(s0 + 8) = (f1 - 1.0f);
    } else {
        fspad_PadSetSmallVibra(s1, 0, 0);
        *(u32 *)(s0 + 8) = 0;
    }
    return;
}

static void UpdatePadVibPlan(void) {
    s32 s2;
    u8 *s1;
    u8 *s0;
    u32 a0;
    u32 v1;
    u8 *v1_address; // v1
    float f1;
    u32 v0;

    s2 = 0;
    s1 = (u8 *)PadVibPlan;
    s0 = (u8 *)PadVibPlan;
    do {
        v1 = *(u8 *)s1;
        if (v1 != 0 && (u32)*(s32 *)(s1 + 8) == (u32)*(s32 *)GameSt) {
            a0 = *(s32 *)(s1 + 0xc);
            v0 = *(u8 *)(s1 + 1);
            v1 = (u32)PadVib;
            v1_address = (u8 *)((u8 *)PadVib + (u32)(a0 << 5));
            if (v0 == 0) {
                v0 = *(s32 *)(s1 + 0x24);
                *(u32 *)(v1_address + 0x14) = v0;
                *(f32 *)(v1_address + 0xc) = *(float *)(s1 + 0x1c);
                v0 = *(s32 *)(v1_address + 0x14);
                if (v0 == 0) {
                    *(f32 *)v1_address = *(float *)(s1 + 0x10);
                    *(u32 *)(v1_address + 4) = 0;
                } else {
                    *(f32 *)(v1_address + 4) = ((*(float *)(s1 + 0x14) - *(float *)v1_address) /
                        *(float *)(v1_address + 0xc));
                }
                f1 = *(float *)v1_address;
                a0 = *(s32 *)(s1 + 0xc);
                fspad_PadSetVibra(a0, 0, (u32)f1);
            } else {
                v0 = *(s32 *)(s1 + 0x20);
                *(u32 *)(v1_address + 0x10) = v0;
                *(f32 *)(v1_address + 8) = *(float *)(s1 + 0x18);
                a0 = *(s32 *)(s1 + 0xc);
                fspad_PadSetSmallVibra(a0, 0, *(u8 *)(v1_address + 0x10));
            }
            if (s2 < (s32)8) {
                memset((u32)s0, 0, (u32)0x30);
            }
        }
        s2 = s2 + 1;
        v1 = s2 < (s32)8;
        s0 = (u8 *)(s0 + 0x30);
        s1 = (u8 *)(s1 + 0x30);
    } while (v1 != 0);
    return;
}

void PadUpdate(void) {
    u32 s3;
    u32 *s2;
    u32 *s1;
    u32 *s0;
    u32 a0;
    u32 v0;
    s32 a2;
    u32 v1;

    fspad_PadUpdate();
    UpdatePadVibPlan();
    s3 = 0;
    s2 = PadState;
    s1 = PadReqState;
    s0 = lpPadData;
    do {
        a0 = s3;
        v0 = scePadGetState(a0, 0);
        *(u32 *)s2 = v0;
        a0 = s3;
        v0 = scePadGetReqState(a0, 0);
        *(u32 *)s1 = v0;
        a0 = s3;
        a2 = 3;
        fspad_PadModeAnalog(a0, 0, a2);
        v0 = (u8)s3;
        v1 = (u32)&PadState;
        a0 = v0 << 2;
        v1 = (s32)((u8 *)&PadState + a0);
        v0 = 2;
        v1 = *(s32 *)v1;
        if (v1 != v0) {
            v0 = 6;
            if (v1 == v0) {
                goto _L0013D6C8;
            }
            v0 = 0;
        } else {
            _L0013D6C8:;
            v0 = (u32)&PadReqState;
            v0 = (s32)((u8 *)&PadReqState + a0);
            v0 = *(s32 *)v0;
            if (v0 != 0) {
                v0 = 0;
            } else {
                v0 = 1;
            }
        }
        a0 = s3;
        if (v0 != 0) {
            v0 = (u32)fspad_PadRead(a0, 0);
            *(u32 *)s0 = v0;
        } else {
            a0 = *(s32 *)s0;
            a2 = 0x24;
            memset(a0, 0, a2);
            v0 = *(s32 *)s0;
            v1 = 0x80;
            *(u8 *)((v0 + 4)) = v1;
            v0 = *(s32 *)s0;
            *(u8 *)((v0 + 5)) = v1;
            v0 = *(s32 *)s0;
            *(u8 *)((v0 + 6)) = v1;
            v0 = *(s32 *)s0;
            *(u8 *)((v0 + 7)) = v1;
        }
        a0 = s3;
        UpdatePadVib(a0);
        s3 = s3 + 1;
        s2 = (u32 *)(s32)((u8 *)s2 + 4);
        v1 = (s32)s3 < (s32)2;
        s1 = (u32 *)(s32)((u8 *)s1 + 4);
        s0 = (u32 *)(s32)((u8 *)s0 + 4);
    } while (v1 != 0);
    return;
}


void PadControl(void) {
    u32 v0;
    u32 v1;
    u8 *s0;
    u8 stackFrame_2E[2] __attribute__((aligned(2)));

    PadUpdate();
    v0 = (u32)&lpPadData;
    v1 = GameSt[0xa];
    s0 = (u8 *)*(s32 *)(u32)(s32)((u8 *)&lpPadData + (u32)(v1 << 2));
    GetAnalogPad((void *)(u8 *)s0, (unsigned short *)(u8 *)((u8 *)&stackFrame_2E[0]));
    v0 = CheckPauseEnable();
    if (v0 != 0 && (u32)((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(s0 +
        0x20))->f != 0) {
        v1 = GameSt[0xf];
        v1 = v1 != 0;
        GameSt[0xf] = v1 ^ 1;
    }
    return;
}

/* GetAnalogPad @ 0x13D4A0 .. 0x13D5A8 (0x108 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void GetAnalogPad(void *a0 /* r4 */, unsigned short *a1 /* r5 */) {
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    *(u16 *)a1 = 0;
    v1 = *(u8 *)(a0_bytes + 6);
    if ((s32)v1 < (s32)0xf) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x80;
    }
    v1 = *(u8 *)(a0_bytes + 6);
    if ((s32)v1 > (s32)0xf0) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x20;
    }
    v1 = *(u8 *)(a0_bytes + 7);
    if ((s32)v1 < (s32)0xf) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x10;
    }
    v1 = *(u8 *)(a0_bytes + 7);
    if ((s32)v1 > (s32)0xf0) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x40;
    }
    v1 = *(u8 *)(a0_bytes + 4);
    if ((s32)v1 < (s32)0xf) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x8000;
    }
    v1 = *(u8 *)(a0_bytes + 4);
    if ((s32)v1 > (s32)0xf0) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x4000;
    }
    v1 = *(u8 *)(a0_bytes + 5);
    if ((s32)v1 < (s32)0xf) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x1000;
    }
    v1 = *(u8 *)(a0_bytes + 5);
    if ((s32)v1 > (s32)0xf0) {
        v1 = *(u16 *)a1;
        *(u16 *)a1 = v1 | 0x2000;
    }
    return;
}

/* CheckPauseEnable @ 0x13D390 .. 0x13D494 (0x104 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x13d3a4 writes a register its branch at 0x13d3a0 reads
 *   delay: daddu at 0x13d468 writes a register its branch at 0x13d464 reads
 *   cfg: kept goto: 0x13d3c4 -> .L0013D488
 *   cfg: kept goto: 0x13d3dc -> .L0013D488
 *   cfg: kept goto: 0x13d3f4 -> .L0013D488
 *   cfg: kept goto: 0x13d40c -> .L0013D488
 *   cfg: kept goto: 0x13d424 -> .L0013D488
 *   cfg: kept goto: 0x13d43c -> .L0013D488
 *   cfg: kept goto: 0x13d454 -> .L0013D488
 */
static u32 CheckPauseEnable(void) {
    s32 a0;
    u32 v1;
    u32 v0;

    v0 = GameSt[5];
    if (v0 != 0) {
        return 0;
    }
    a0 = 3;
    v0 = CheckNowFade(a0);
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    a0 = 6;
    v0 = CheckNowFade(a0);
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    a0 = 8;
    v0 = CheckNowFade(a0);
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    a0 = 9;
    v0 = CheckNowFade(a0);
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    a0 = 0xa;
    v0 = CheckNowFade(a0);
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    v0 = GetDramaReadFlag();
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    v0 = CheckRiddleMode();
    if (v0 != 0) {
        v0 = 0;
        goto _L0013D488;
    }
    v1 = GameSt[0xf];
    v0 = 2;
    if (v1 == v0) {
        return 0;
    }
    v0 = CheckMyPauseDisable();
    v0 = v0 != 0;
    v0 = v0 ^ 1;
    _L0013D488:;
    return v0;
}
int CheckResetPad(void) {
    u32 v1;
    u32 v0;
    u8 *s0;
    u64 v0_64;

    v0 = (u32)&lpPadData;
    v1 = GameSt[(DCOMP_OFF_STRUCT_DW_223293_FIELDS_PADPORT_FC990377 / 1)];
    v1 = v1 << 2;
    v0 = (s32)((u8 *)&lpPadData + v1);
    s0 = (u8 *)*(s32 *)v0;
    v0 = KnMenu_CheckSaveLoadSoftResetOff();
    if (v0 != 0) {
        PushTimer_898 = 0;
        v0 = 0;
    } else {
        v0 = Menu_TD_IsPlay();
        if (v0 != 0) {
            PushTimer_898 = 0;
            v0 = 0;
        } else {
            v0 = FileCheckAsyncBusy();
            if (v0 != 0) {
                PushTimer_898 = 0;
                v0 = 0;
            } else {
                v0 = CheckNowFade(6);
                if (v0 != 0) {
                    PushTimer_898 = 0;
                    v0 = 0;
                } else {
                    v1 = *(u8 *)(s0 + 3);
                    v0_64 = (u64)v1 << 0x3d >> 0x3f;
                    if (v0_64 != 0) {
                        v0_64 = (u64)v1 << 0x3c;
                        v0_64 = v0_64 >> 0x3f;
                        if (v0_64 == 0) {
                            goto _L0013D368;
                        }
                        v0 = v1 & 1;
                        if (v0 != 0) {
                            v0_64 = (u64)v1 << 0x3e >> 0x3f;
                            if (v0_64 == 0) {
                                goto _L0013D360;
                            }
                            v1 = *(u8 *)(s0 + 2);
                            v0_64 = (u64)v1 << 0x3c >> 0x3f;
                            if (v0_64 != 0 && (u32)(v1 & 1) != 0) {
                                v1 = PushTimer_898;
                                v1 = v1 + 1;
                                PushTimer_898 = v1;
                                if (v1 == (u32)0xb4) {
                                    SetGoToTitleFade();
                                }
                            } else {
                                PushTimer_898 = 0;
                            }
                        } else {
                            _L0013D360:;
                            PushTimer_898 = 0;
                        }
                    } else {
                        _L0013D368:;
                        PushTimer_898 = 0;
                    }
                    v0 = 0;
                }
            }
        }
    }
    return v0;
}

signed int CheckPadEnable(unsigned char a0 /* r4 */) {
    u32 a0_word = a0;
    u32 v0;
    u32 v1;
    s32 branchcond_13d1f8;
    s32 branchcond_13d21c;

    v0 = (u8)a0_word;
    a0_word = v0 << 2;
    v0 = (u32)&PadState;
    v1 = (s32)((u8 *)&PadState + a0_word);
    v1 = *(s32 *)v1;
    v0 = 2;
    branchcond_13d1f8 = v1 == v0;
    v0 = 6;
    if (branchcond_13d1f8) {
        goto _L0013D210;
    }
    if (v1 == v0) {
        goto _L0013D210;
    }
    v0 = 0;
    goto _L0013D238;
    _L0013D210:;
    v0 = (u32)&PadReqState;
    v0 = (s32)((u8 *)&PadReqState + a0_word);
    v0 = *(s32 *)v0;
    branchcond_13d21c = v0 == 0;
    v0 = 0;
    if (!branchcond_13d21c) {
        return v0;
    }
    v0 = 1;
    _L0013D238:;
    return v0;
}

void SetPadVibHeart(void) {
    u8 a0;
    float f12;
    float f13;

    a0 = GameSt[0xa];
    f12 = 3.0f;
    f13 = 30.0f;
    PadSetVib(a0, 3.0f, 30.0f, 0, 0, 0);
    a0 = GameSt[0xa];
    f12 = 3.0f;
    f13 = 60.0f;
    PadSetVib(a0, 3.0f, 60.0f, 0, 0, 0x14);
    a0 = GameSt[0xa];
    f12 = 3.0f;
    f13 = 1.0f;
    PadSetVib(a0, 3.0f, 1.0f, 0, 1, 0);
    a0 = GameSt[0xa];
    f12 = 3.0f;
    f13 = 1.0f;
    PadSetVib(a0, 3.0f, 1.0f, 0, 1, 0x14);
    return;
}
