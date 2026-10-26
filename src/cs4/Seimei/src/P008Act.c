#include "common.h"

/* P008ActAppear @ 0x193990 .. 0x193BA8 (0x218 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @866 -> 0x22c560
 *   fpu: float literal 0x3f800000 at 0x19399c
 *   stack: address of the slot at 0x90 escapes at 0x1939c8
 *   fpu: float literal 0x40490fdb at 0x1939e0
 *   fpu: float literal 0x00000000 at 0x1939e8
 *   stack: address of the slot at 0xa0 escapes at 0x1939ec
 *   fpu: float literal 0x40a00000 at 0x193a04
 *   fpu: float literal 0x40490fdb at 0x193a0c
 *   stack: address of the slot at 0x40 escapes at 0x193a60
 *   stack: address of the slot at 0x70 escapes at 0x193a70
 *   stack: address of the slot at 0x40 escapes at 0x193a80
 *   stack: address of the slot at 0x80 escapes at 0x193a80
 *   fpu: float literal 0x3f800000 at 0x193a90
 *   fpu: float literal 0x42700000 at 0x193aa4
 *   fpu: float literal 0x00000000 at 0x193adc
 *   fpu: float literal 0x42700000 at 0x193af0
 *   fpu: float literal 0x3c8b4396 at 0x193b10
 *   fpu: float literal 0x3f800000 at 0x193b18
 *   fpu: float literal 0x3d23d70a at 0x193b54
 *   fpu: float literal 0x3ca3d70a at 0x193b6c
 *   literal: @866 initializes the 16-byte local at 0x80
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern void NM_GetPcHeadPos(float *);
extern void SfxCalc_PY_To_Dir(float, float, void *);
extern void * SfxUtil_FindChar_Corn(signed int, float *, float *, float, float, signed int);
extern void sceVu0CopyVector(void *, void *);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern unsigned int CheckAnimEndFrame(void *);
extern void EneDeadProc(void *, void *);
extern u32 MdlMng[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 P008ActInit(u8 *a0 , u8 *a1 );
static void P008ActAppear(void *a0 , void *a1 );


/* P008ActInit @ 0x193BB0 .. 0x193BD8 (0x28 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */



u32 P008ActInit(u8 *a0 /* r4 */, u8 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)P008ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)P008ActAppear;
    *(u8 *)(((u8 *)a1 + 0x1da)) = 1;
    v1 = (u8 *)0xffff;
    *(u8 *)(((u8 *)a0 + 0x131)) = 1;
    *(u16 *)(((u8 *)a1 + 0x1fa)) = 0xffff;
    *(u8 *)(((u8 *)a1 + 0x24d)) = 1;
    return;
}

static void P008ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u32 s1;
    float f13;
    float *s0;
    float f12;
    float f1;
    float f0;
    u32 v1;
    u32 v0;
    u8 stackFrame_A0[16] __attribute__((aligned(16)));
    u8 stackFrame_90[16] __attribute__((aligned(16)));
    struct stackFrame_80 { u8 b[16]; } stackFrame_80 __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_40[48] __attribute__((aligned(16)));

    f12 = 1.0f;
    s2 = (u8 *)a0;
    s1 = (u32)a1;
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x100));
    v0 = CheckAnimNumFrame((void *)(u32)(s32)s0, 1.0f);
    a0 = (void *)((u8 *)&stackFrame_90[0]);
    if (v0 != 0) {
        NM_GetPcHeadPos((float *)a0);
        f1 = 3.14159274f;
        f12 = 0.0f;
        SfxCalc_PY_To_Dir(0.0f, (3.14159274f + *(float *)(MdlMng + 0x460d)), (void *)((u8
            *)&stackFrame_A0[0]));
        a0 = (void *)(s32)1;
        f12 = 5.0f;
        f13 = 3.14159274f;
        v0 = (u32)SfxUtil_FindChar_Corn((signed int)a0, (float *)((u8 *)&stackFrame_90[0]), (float
            *)(u8 *)((u8 *)&stackFrame_A0[0]), 5.0f, 3.14159274f, (s32)a0);
        a1 = (void *)(s32)(v0 + 0x20);
        if (v0 != 0) {
            sceVu0CopyVector((void *)(u32)(s32)(s2 + 0x20), a1);
        } else {
            v0 = 0x22c560;
            v1 = (u32)((u8 *)&stackFrame_80);
            a1 = (void *)((u8 *)MdlMng + 0x11830);
            stackFrame_80 = (struct stackFrame_80){{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f}};
            f12 = *(float *)a1;
            SfxCalc_MakeMatrixFromPYR((void *)((u8 *)&stackFrame_40[0]), f12, *(float *)(((u8 *)a1
                + 4)), *(float *)(((u8 *)a1 + 8)));
            sceVu0CopyVector((void *)(u32)((u8 *)&stackFrame_70[0]), (void *)((u8 *)MdlMng +
                0x11820));
            sceVu0ApplyMatrix((void *)(u32)(s32)(s2 + 0x20), (void *)((u8 *)&stackFrame_40[0]),
                (void *)(u8 *)((u8 *)&stackFrame_80));
        }
    }
    f1 = *(float *)s0;
    f0 = 1.0f;
    v0 = 0x42700000;
    if (1.0f < f1) {
        f0 = 60.0f;
        if (f1 < 60.0f) {
            v1 = *(s32 *)(s2 + 0x1b4);
            if (v1 != 0 && (u32)((u8 *)MdlMng + 0x11800) != v1) {
                sceVu0CopyVector((void *)(u32)(s32)(s2 + 0x20), (void *)(u32)(v1 + 0x20));
            }
        }
    }
    f1 = *(float *)s0;
    f0 = 0.0f;
    v0 = 0x42700000;
    if ((s32)(0.0f <= f1)) {
        f0 = 60.0f;
        if ((s32)(f1 < 60.0f)) {
            v0 = 0x3c8b0000;
            v1 = 0x3c8b0000 | 0x4396;
            f1 = 0.0170000009f;
            v0 = 0x3f800000;
            f1 = (*(float *)(s2 + 0x10c) + (float)f1);
            *(f32 *)(s2 + 0x10c) = f1;
            if (!(s32)(f1 <= 1.0f)) {
                *(f32 *)(s2 + 0x10c) = 1.0f;
            }
        }
    }
    v0 = CheckAnimEndFrame((void *)(u32)(s32)s0);
    if (v0 != 0) {
        f1 = *(float *)(s2 + 0x10c);
        v1 = 0x3d23d70a;
        f0 = 0.0399999991f;
        if (!(f1 < 0.0399999991f)) {
            v1 = 0x3ca3d70a;
            f0 = 0.0199999996f;
            *(f32 *)(s2 + 0x10c) = (f1 - 0.0199999996f);
        } else {
            a1 = (void *)s1;
            a0 = (void *)s2;
            *(u32 *)(s2 + 0x10c) = 0;
            EneDeadProc(a0, a1);
        }
    }
    return;
}
