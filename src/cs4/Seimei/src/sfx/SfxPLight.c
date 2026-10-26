#include "common.h"

/* SfxPLight_Enable @ 0x1CEB60 .. 0x1CEBD8 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * SList_GetElemPtr(void *, unsigned short);
static u32 s_pObjList;

#ifndef PROTO_DW_2155172
#define PROTO_DW_2155172
struct dw_2155172 { signed char bEnableBlink : 1; signed char bEnableWind : 1; signed char bDeleting : 1; signed char bDisable : 1; signed char bDisableShadow : 1; unsigned char : 3; };
#endif
#ifndef PROTO_DW_2157807
#define PROTO_DW_2157807
struct dw_2157807 { float freq; float range; float progress; float prev_ratio; float next_ratio; char dmy[12]; };
#endif
#ifndef PROTO_DW_2157586
#define PROTO_DW_2157586
struct dw_2157586 { float val_target; float val_curr; float recover; float response; float last_pos[4]; };
#endif
#ifndef PROTO_DW_2155452
#define PROTO_DW_2155452
struct dw_2155452 { float pos[4]; float rgba[4]; float curr_fade; float init_fade; float range; float dimmer; int plight_id; struct dw_2155172 flag; char dmy[11]; struct dw_2157807 blink; struct dw_2157586 wind; };
#endif

/* SfxPLight_SetWindParam @ 0x1CEBE0 .. 0x1CEC3C (0x5c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1cebfc is a float copy
 *   fpu: mov.s at 0x1cec04 is a float copy
 */

extern void * SList_GetElemPtr(void *, unsigned short);
static u32 s_pObjList;

/* SfxPLight_SetBlink @ 0x1CEC40 .. 0x1CED88 (0x148 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1cec60 is a float copy
 *   fpu: mov.s at 0x1cec68 is a float copy
 *   fpu: float literal 0x3f800000 at 0x1cec94
 *   fpu: mtc1 reinterprets v0 at 0x1cecb0
 *   fpu: mtc1 reinterprets v1 at 0x1cecc4
 *   fpu: float literal 0x37800080 at 0x1cece0
 *   fpu: float literal 0x3f800000 at 0x1cece4
 *   fpu: mtc1 reinterprets v0 at 0x1ced18
 *   fpu: mtc1 reinterprets v1 at 0x1ced2c
 *   fpu: float literal 0x37800080 at 0x1ced48
 *   fpu: float literal 0x3f800000 at 0x1ced50
 */

extern u32 SfxCalc_RandU32(void);

/* SfxPLight_EnableShadow @ 0x1CED90 .. 0x1CEE10 (0x80 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int EnablePointLightShadow(signed int, signed int);

#ifndef PROTO_DW_2155172
#define PROTO_DW_2155172
struct dw_2155172 { signed char bEnableBlink : 1; signed char bEnableWind : 1; signed char bDeleting : 1; signed char bDisable : 1; signed char bDisableShadow : 1; unsigned char : 3; };
#endif
#ifndef PROTO_DW_2157807
#define PROTO_DW_2157807
struct dw_2157807 { float freq; float range; float progress; float prev_ratio; float next_ratio; char dmy[12]; };
#endif
#ifndef PROTO_DW_2157586
#define PROTO_DW_2157586
struct dw_2157586 { float val_target; float val_curr; float recover; float response; float last_pos[4]; };
#endif
#ifndef PROTO_DW_2155452
#define PROTO_DW_2155452
struct dw_2155452 { float pos[4]; float rgba[4]; float curr_fade; float init_fade; float range; float dimmer; int plight_id; struct dw_2155172 flag; char dmy[11]; struct dw_2157807 blink; struct dw_2157586 wind; };
#endif

/* SfxPLight_EnableWindEffect @ 0x1CEE10 .. 0x1CEE88 (0x78 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void sceVu0CopyVector(void *, void *);

#ifndef PROTO_DW_2155172
#define PROTO_DW_2155172
struct dw_2155172 { signed char bEnableBlink : 1; signed char bEnableWind : 1; signed char bDeleting : 1; signed char bDisable : 1; signed char bDisableShadow : 1; unsigned char : 3; };
#endif
#ifndef PROTO_DW_2157807
#define PROTO_DW_2157807
struct dw_2157807 { float freq; float range; float progress; float prev_ratio; float next_ratio; char dmy[12]; };
#endif
#ifndef PROTO_DW_2157586
#define PROTO_DW_2157586
struct dw_2157586 { float val_target; float val_curr; float recover; float response; float last_pos[4]; };
#endif
#ifndef PROTO_DW_2155452
#define PROTO_DW_2155452
struct dw_2155452 { float pos[4]; float rgba[4]; float curr_fade; float init_fade; float range; float dimmer; int plight_id; struct dw_2155172 flag; char dmy[11]; struct dw_2157807 blink; struct dw_2157586 wind; };
#endif

/* SfxPLight_EnableBlink @ 0x1CEE90 .. 0x1CEEF8 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

#ifndef PROTO_DW_2155172
#define PROTO_DW_2155172
struct dw_2155172 { signed char bEnableBlink : 1; signed char bEnableWind : 1; signed char bDeleting : 1; signed char bDisable : 1; signed char bDisableShadow : 1; unsigned char : 3; };
#endif
#ifndef PROTO_DW_2157807
#define PROTO_DW_2157807
struct dw_2157807 { float freq; float range; float progress; float prev_ratio; float next_ratio; char dmy[12]; };
#endif
#ifndef PROTO_DW_2157586
#define PROTO_DW_2157586
struct dw_2157586 { float val_target; float val_curr; float recover; float response; float last_pos[4]; };
#endif
#ifndef PROTO_DW_2155452
#define PROTO_DW_2155452
struct dw_2155452 { float pos[4]; float rgba[4]; float curr_fade; float init_fade; float range; float dimmer; int plight_id; struct dw_2155172 flag; char dmy[11]; struct dw_2157807 blink; struct dw_2157586 wind; };
#endif

/* SfxPLight_SetColor @ 0x1CEF00 .. 0x1CEF64 (0x64 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred void
 */


extern void sceVu0CopyVector(void *, void *);
extern signed int UpdatePointLightColor(signed int, float *);
static u32 s_pObjList;

/* SfxPLight_SetRadius @ 0x1CEF70 .. 0x1CEFC0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1cef8c is a float copy
 *   fpu: mov.s at 0x1cefac is a float copy
 */


extern signed int UpdatePointLightRadius(signed int, float);
static u32 s_pObjList;

/* SfxPLight_SetPos @ 0x1CEFC0 .. 0x1CF024 (0x64 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred void
 */



extern signed int UpdatePointLightPos(signed int, float *);
static u32 s_pObjList;

/* SfxPLight_ActionAll @ 0x1CF030 .. 0x1CF34C (0x31c bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1cf060 is a float copy
 *   stack: address of the slot at 0x94 escapes at 0x1cf080
 *   stack: address of the slot at 0x98 escapes at 0x1cf080
 *   stack: address of the slot at 0x9c escapes at 0x1cf080
 *   stack: address of the slot at 0x80 escapes at 0x1cf0bc
 *   stack: address of the slot at 0x90 escapes at 0x1cf0dc
 *   stack: address of the slot at 0x80 escapes at 0x1cf0dc
 *   stack: address of the slot at 0x90 escapes at 0x1cf0f4
 *   fpu: float literal 0x00000000 at 0x1cf100
 *   stack: address of the slot at 0x90 escapes at 0x1cf188
 *   stack: address of the slot at 0x90 escapes at 0x1cf188
 *   fpu: float literal 0x3f800000 at 0x1cf19c
 *   stack: address of the slot at 0x90 escapes at 0x1cf1a8
 *   stack: address of the slot at 0x90 escapes at 0x1cf1a8
 *   fpu: float literal 0x3f800000 at 0x1cf1e4
 *   fpu: mtc1 reinterprets v0 at 0x1cf208
 *   fpu: mtc1 reinterprets v1 at 0x1cf21c
 *   fpu: float literal 0x37800080 at 0x1cf238
 *   fpu: float literal 0x3f800000 at 0x1cf23c
 *   fpu: float literal 0x3f800000 at 0x1cf274
 *   fpu: mov.s at 0x1cf294 is a float copy
 *   fpu: float literal 0x3f800000 at 0x1cf2a0
 *   fpu: mov.s at 0x1cf2fc is a float copy
 *   stack: address of the slot at 0x90 escapes at 0x1cf2f8
 *   stack: address of the slot at 0x90 escapes at 0x1cf304
 *   cfg: loop body is not one contiguous region: .L001CF080
 */

extern unsigned short SList_GetFrontElem(void *);
extern unsigned short SList_GetNextElem(void *, unsigned short);
extern void SetPointLightOff(signed int);
extern void *memset(void *, int, unsigned int);
extern signed int SList_Delete(void *, unsigned short);
extern void sceVu0ScaleVector(void *, void *, float);
void _ApplyWind(struct PLightWind *pPLight_, float dt_, float (*pColor_)[4]);


extern float Math_GetDist(float *, float *);
extern u32 GetFirstBlastDir();
extern u32 GameSt[];

struct PLightWind {
    float vPos[4];
    u8 unk10[0x50];
    float fRate;
    float fPower;
    float fRateSpd;
    float fPowerSpd;
    float vPrevPos[4];
};


/* SfxPLight_DeleteAll @ 0x1CF4B0 .. 0x1CF550 (0xa0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern unsigned short SList_GetFrontElem(void *);
extern void * SList_GetElemPtr(void *, unsigned short);
extern unsigned short SList_GetNextElem(void *, unsigned short);
extern void SetPointLightOff(signed int);
extern void *memset(void *, int, unsigned int);
extern signed int SList_Delete(void *, unsigned short);
static u32 s_pObjList;


extern u32 GetFreePointLightIndex();
extern unsigned short SList_PushFront(void *, void *);
extern void SetPointLightOn(signed int, float *, float);
extern u32 V0[];


/* SfxPLight_Initialize @ 0x1CF740 .. 0x1CF76C (0x2c bytes, frame 0x10) */

extern void * SList_Init(void *, unsigned int, unsigned short);
static u32 s_pObjList;
static u32 s_data_buff[256];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SfxPLight_Initialize(void);
unsigned short SfxPLight_Create(float radius);
signed int SfxPLight_Delete(unsigned short a0 , float f12 );
u32 SfxPLight_DeleteAll(void);
void _ApplyWind(struct PLightWind *pPLight_, float dt_, float (*pColor_)[4]);
void SfxPLight_ActionAll(float dt_);
signed int SfxPLight_SetPos(unsigned short a0 , float *a1 );
signed int SfxPLight_SetRadius(unsigned short a0 , float f12 );
signed int SfxPLight_SetColor(unsigned short a0 , float *a1 );
signed int SfxPLight_EnableBlink(unsigned short a0 , signed int a1 );
signed int SfxPLight_EnableWindEffect(unsigned short a0 , signed int a1 );
signed int SfxPLight_EnableShadow(unsigned short a0 , signed int a1 );
signed int SfxPLight_SetBlink(unsigned short a0 , float f12 , float f13 );
signed int SfxPLight_SetWindParam(unsigned short a0 , float f12 , float f13 );
signed int SfxPLight_Enable(unsigned short a0 , signed int a1 );


void SfxPLight_Initialize(void) {
    u8 *v0;

    v0 = (u8 *)SList_Init((void *)s_data_buff, (s32)0x400, (s32)0x80);
    s_pObjList = (u32)v0;
    return;
}

unsigned short SfxPLight_Create(float radius) {
    s32 index;
    u16 handle;
    u8 *object;
    float savedRadius;
    savedRadius = radius;
    index = GetFreePointLightIndex();
    if (index == -1) return 0xffff;
    handle = SList_PushFront((void *)s_pObjList, 0);
    if (handle == 0xffff) return 0xffff;
    object = (u8 *)SList_GetElemPtr((void *)s_pObjList, handle);
    {
        float position[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
        sceVu0CopyVector(object, position);
        {
            float direction[4] __attribute__((aligned(16))) = {0.0f, 0.0f, 0.0f, 1.0f};
            sceVu0CopyVector(object + 0x10, direction);
            *(float *)(object + 0x20) = savedRadius;
            *(float *)(object + 0x24) = savedRadius;
            *(float *)(object + 0x28) = 1.0f;
            *(float *)(object + 0x2c) = 1.0f;
            *(s32 *)(object + 0x30) = index;
            memset(object + 0x40, 0, 0x20);
            *(float *)(object + 0x60) = 1.0f;
            *(float *)(object + 0x64) = 1.0f;
            *(float *)(object + 0x68) = 1.0f;
            *(float *)(object + 0x6c) = 1.0f;
            sceVu0CopyVector(object + 0x70, V0);
            SetPointLightOn(index, (float *)object, *(float *)(object + 0x28));
        }
    }
    return handle;
}

/* SfxPLight_Delete @ 0x1CF550 .. 0x1CF608 (0xb8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1cf574 is a float copy
 *   fpu: float literal 0x00000000 at 0x1cf58c
 */

signed int SfxPLight_Delete(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    u16 s1;
    float f20;
    u32 v0;
    u8 *s0;
    u32 a0_guard_word;

    v0 = 0xffff;
    s1 = a0;
    f20 = f12;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        a0_guard_word = s_pObjList;
        v0 = (u32)SList_GetElemPtr((void *)a0_guard_word, s1);
        s0 = (u8 *)v0;
        if (0.0f < f20) {
            *(f32 *)(s0 + 0x20) = f20;
            *(f32 *)(s0 + 0x24) = f20;
            a0_guard_word = 4;
            v0 = 1;
            ((struct { signed char _pad:2; signed char f:1; } *)&*(s8 *)(s0 + 0x34))->f = 1;
        } else {
            SetPointLightOff(*(s32 *)(s0 + 0x30));
            memset((void *)s0, 0, 0x80);
            a0_guard_word = s_pObjList;
            v0 = SList_Delete((void *)a0_guard_word, s1);
        }
    }
    return v0;
}

u32 SfxPLight_DeleteAll(void) {
    u32 a0;
    u32 v0;
    u16 s2;
    u32 v1;
    u32 *s1;
    u16 s0;

    a0 = s_pObjList;
    v0 = SList_GetFrontElem((void *)a0);
    s2 = v0;
    v1 = 0xffff;
    if ((u32)s2 != v1) {
        do {
            a0 = s_pObjList;
            v0 = (u32)SList_GetElemPtr((void *)a0, s2);
            a0 = s_pObjList;
            s1 = (u32 *)v0;
            v0 = SList_GetNextElem((void *)a0, s2);
            s0 = v0;
            SetPointLightOff(*(s32 *)(((u8 *)s1 + 0x30)));
            memset((void *)(u32)s1, 0, 0x80);
            a0 = s_pObjList;
            SList_Delete((void *)a0, s2);
            s2 = s0;
            v1 = 0xffff;
        } while ((u32)s2 != v1);
    }
    return;
}

void _ApplyWind(struct PLightWind *pPLight_, float dt_, float (*pColor_)[4]) {
    static float max_len = 3.5f;

    pPLight_->fRate += pPLight_->fRateSpd * dt_;
    if (1.0f < pPLight_->fRate) {
        pPLight_->fRate = 1.0f;
    }
    {
        float len = Math_GetDist(pPLight_->vPos, pPLight_->vPrevPos);
        pPLight_->fRate = 1.0f - len * (1.0f / dt_) / max_len;
    }
    if (pPLight_->fRate < 0.0f) {
        pPLight_->fRate = 0.0f;
    }
    if (GetFirstBlastDir()) {
        *(u32 *)&pPLight_->fRate = 0;
        *(u32 *)&pPLight_->fPower = 0;
    } else {
        pPLight_->fPower += dt_ * (pPLight_->fPowerSpd * (pPLight_->fRate - pPLight_->fPower));
        if (pPLight_->fPower < 0.0f) {
            pPLight_->fPower = 0.0f;
        }
        if (1.0f < pPLight_->fPower) {
            pPLight_->fPower = 1.0f;
        }
    }
    sceVu0CopyVector(pPLight_->vPrevPos, pPLight_->vPos);
    (*pColor_)[0] *= pPLight_->fPower;
    (*pColor_)[1] *= pPLight_->fPower;
    (*pColor_)[2] *= pPLight_->fPower;
    (*pColor_)[3] = 1.0f;
    *(float *)(GameSt + 9) = pPLight_->fPower;
}

void SfxPLight_ActionAll(float dt_) {
    unsigned short hElem;
    struct dw_2155452 *pObj;
    unsigned short hNextElem;
    float rgba[4];
    float ratio;
    float rnd;
    float v;

    hElem = SList_GetFrontElem((void *)s_pObjList);
    while (hElem != 0xffff) {
        pObj = (struct dw_2155452 *)SList_GetElemPtr((void *)s_pObjList, hElem);
        hNextElem = SList_GetNextElem((void *)s_pObjList, hElem);
        if (pObj->flag.bDisable) {
            float zero[4] = {0.0f, 0.0f, 0.0f, 0.0f};
            sceVu0CopyVector(rgba, zero);
        } else {
            sceVu0CopyVector(rgba, pObj->rgba);
            if (0.0f < pObj->init_fade) {
                pObj->curr_fade -= dt_;
                if (pObj->curr_fade < 0.0f) {
                    if (pObj->flag.bDeleting) {
                        SetPointLightOff(pObj->plight_id);
                        memset((void *)pObj, 0, 0x80);
                        SList_Delete((void *)s_pObjList, hElem);
                    }
                } else {
                    ratio = pObj->curr_fade / pObj->init_fade;
                    if (pObj->flag.bDeleting) {
                        sceVu0ScaleVector(rgba, rgba, ratio);
                    } else {
                        sceVu0ScaleVector(rgba, rgba, 1.0f - ratio);
                    }
                }
            }
            if (pObj->flag.bEnableBlink) {
                if (pObj->blink.freq <= pObj->blink.progress) {
                    pObj->blink.progress = 0.0f;
                    pObj->blink.prev_ratio = pObj->blink.next_ratio;
                    v = 1.0f - pObj->blink.range;
                    rnd = (float)(u16)SfxCalc_RandU32() * 1.5259022e-05f;
                    pObj->blink.next_ratio = v + (1.0f - v) * rnd;
                } else {
                    pObj->blink.progress = pObj->blink.progress + dt_;
                }
                ratio = pObj->blink.progress / pObj->blink.freq;
                if (1.0f < ratio) {
                    ratio = 1.0f;
                }
                v = pObj->blink.next_ratio * ratio + pObj->blink.prev_ratio * (1.0f - ratio);
                rgba[0] = rgba[0] * v;
                rgba[1] = rgba[1] * v;
                rgba[2] = rgba[2] * v;
                rgba[3] = 1.0f;
            }
            if (pObj->flag.bEnableWind) {
                _ApplyWind((struct PLightWind *)pObj, dt_, (float (*)[4])rgba);
            }
        }
        UpdatePointLightColor(pObj->plight_id, rgba);
        hElem = hNextElem;
    }
}

signed int SfxPLight_SetPos(unsigned short a0 /* r4 */, float *a1 /* r5 */) {
    u32 s1;
    u32 v0;
    u8 *s0;

    v0 = 0xffff;
    s1 = (u32)a1;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        s0 = (u8 *)v0;
        sceVu0CopyVector((void *)s0, (void *)s1);
        v0 = UpdatePointLightPos(*(s32 *)(s0 + 0x30), (float *)s1);
    }
    return v0;
}

signed int SfxPLight_SetRadius(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    float f20;
    u32 v0;
    u32 a0_guard_word;

    v0 = 0xffff;
    f20 = f12;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        *(f32 *)(((u8 *)v0 + 0x28)) = f20;
        a0_guard_word = *(s32 *)(((u8 *)v0 + 0x30));
        v0 = UpdatePointLightRadius(a0_guard_word, (float)f20);
    }
    return v0;
}

signed int SfxPLight_SetColor(unsigned short a0 /* r4 */, float *a1 /* r5 */) {
    u32 s1;
    u32 v0;
    u8 *s0;

    v0 = 0xffff;
    s1 = (u32)a1;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        s0 = (u8 *)v0;
        sceVu0CopyVector((void *)(u32)(s32)(s0 + 0x10), (void *)s1);
        v0 = UpdatePointLightColor(*(s32 *)(s0 + 0x30), (float *)s1);
    }
    return v0;
}

signed int SfxPLight_EnableBlink(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    signed int a1_2; // a1
    u32 v1;
    struct dw_2155452 *v0;

    v1 = (u16)a0;
    v0 = (struct dw_2155452 *)0xffff;
    s0 = a1;
    if (v1 == (u32)v0) {
        v0 = (struct dw_2155452 *)0;
    } else {
        v0 = (struct dw_2155452 *)SList_GetElemPtr((void *)s_pObjList, a0);
        v0->flag.bEnableBlink = s0;
        v0 = (struct dw_2155452 *)(s32)1;
    }
    return (u32)v0;
}

signed int SfxPLight_EnableWindEffect(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    s32 a3;
    signed int a1_2; // a1
    u32 v1;
    struct dw_2155452 *v0;
    struct dw_2155452 *a1_2_w1;

    v1 = (u16)a0;
    v0 = (struct dw_2155452 *)0xffff;
    s0 = a1;
    if (v1 == (u32)v0) {
        v0 = (struct dw_2155452 *)0;
    } else {
        v0 = (struct dw_2155452 *)SList_GetElemPtr((void *)s_pObjList, a0);
        a1_2_w1 = (struct dw_2155452 *)v0;
        v0->flag.bEnableWind = s0;
        sceVu0CopyVector((void *)(u32)((u32)v0 + 0x70), (void *)a1_2_w1);
        v0 = (struct dw_2155452 *)(s32)1;
    }
    return (u32)v0;
}

signed int SfxPLight_EnableShadow(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    s32 a2;
    struct dw_2155452 *v0;

    v0 = (struct dw_2155452 *)0xffff;
    s0 = a1;
    if ((u32)(u16)a0 == (u32)v0) {
        v0 = (struct dw_2155452 *)0;
    } else {
        v0 = (struct dw_2155452 *)SList_GetElemPtr((void *)s_pObjList, a0);
        v0->flag.bDisableShadow = (u32)((u32)s0 != 0) ^ 1;
        EnablePointLightShadow(v0->plight_id, s0);
        v0 = (struct dw_2155452 *)(s32)1;
    }
    return (u32)v0;
}

signed int SfxPLight_SetBlink(unsigned short a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */) {
    s32 v1;
    float f21;
    float f20;
    u32 v0;
    u8 *s0;
    float f2;
    float f1;
    float f0;
    u32 a0_guard_word;

    v0 = 0xffff;
    f21 = f12;
    f20 = f13;
    if ((u32)(u16)a0 == v0) {
        return 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        *(f32 *)(((u8 *)v0 + 0x40)) = f21;
        *(f32 *)(((u8 *)v0 + 0x44)) = f20;
        s0 = (u8 *)v0;
        *(u32 *)(((u8 *)v0 + 0x48)) = 0;
        f0 = 1.0f;
        f1 = *(float *)(((u8 *)v0 + 0x44));
        f20 = (1.0f - f1);
        v0 = SfxCalc_RandU32();
        f0 = 1.52590219e-05f;
        f1 = 1.0f;
        *(f32 *)(s0 + 0x50) = (f20 + ((1.0f - f20) * (1.52590219e-05f *
            (float)(float)(u32)(u16)v0)));
        f0 = *(float *)(s0 + 0x44);
        f20 = (1.0f - f0);
        v0 = SfxCalc_RandU32();
        f2 = (float)(u32)(u16)v0;
        v0 = 0x37800000;
        v1 = 0x3f800000;
        a0_guard_word = 0x37800000 | 0x80;
        f1 = 1.52590219e-05f;
        v0 = 1;
        *(f32 *)(s0 + 0x4c) = (f20 + ((1.0f - f20) * (1.52590219e-05f * f2)));
    }
    return v0;
}

signed int SfxPLight_SetWindParam(unsigned short a0 /* r4 */, float f12 /* f12 */, float f13 /* f13
        */) {
    float f21;
    float f20;
    u32 v0;

    v0 = 0xffff;
    f21 = f12;
    f20 = f13;
    if ((u32)(u16)a0 == v0) {
        v0 = 0;
    } else {
        v0 = (u32)SList_GetElemPtr((void *)s_pObjList, a0);
        *(f32 *)(((u8 *)v0 + 0x68)) = f21;
        *(f32 *)(((u8 *)v0 + 0x6c)) = f20;
        v0 = 1;
    }
    return v0;
}

signed int SfxPLight_Enable(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    signed int a1_2; // a1
    struct dw_2155452 *v0;

    v0 = (struct dw_2155452 *)0xffff;
    s0 = a1;
    if ((u32)(u16)a0 == (u32)v0) {
        v0 = (struct dw_2155452 *)0;
    } else {
        v0 = (struct dw_2155452 *)SList_GetElemPtr((void *)s_pObjList, a0);
        v0->flag.bDisable = (u32)((u32)s0 != 0) ^ 1;
        v0 = (struct dw_2155452 *)(s32)1;
    }
    return (u32)v0;
}
