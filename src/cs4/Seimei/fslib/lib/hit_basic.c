#include "common.h"

/* GetHitRateLinePolygon @ 0x159470 .. 0x1595C4 (0x154 bytes, frame 0x90) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x80 escapes at 0x1594a4
 *   stack: address of the slot at 0x70 escapes at 0x1594b4
 *   stack: address of the slot at 0x60 escapes at 0x1594c4
 *   stack: address of the slot at 0x80 escapes at 0x1594c4
 *   fpu: mov.s at 0x1594d8 is a float copy
 *   fpu: mov.s at 0x1594e0 is a float copy
 *   fpu: float literal 0x38d1b717 at 0x1594ec
 *   fpu: float literal 0x3f800000 at 0x15950c
 *   fpu: float literal 0x00000000 at 0x159540
 *   fpu: float literal 0x3f800000 at 0x159568
 *   cfg: kept branch: 0x159554 if (..) goto .L00159580
 *   cfg: kept branch: 0x159560 if (..) goto .L00159588
 *   cfg: kept goto: 0x159580 -> .L001595A0
 *   a2 takes slot 2 only because of the ABI order
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SubVector(float *, float *, float *);
extern void OuterProduct(float *, float *, float *);
extern float InnerProduct(float *, float *);
extern float fabsf(float);

signed int GetHitRateLinePolygon(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float
        *a3 /* r7 */, float *t0 /* r8 */, float *t1 /* r9 */) {
    u32 s2;
    u32 s1;
    float *s0;
    float f1;
    float f20;
    float f0;
    s32 v0;
    float f21;
    float *a0_2;
    float *a1_2;
    u8 stackFrame_80[16] __attribute__((aligned(16)));
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));

    s2 = (u32)a1;
    a1_2 = a0;
    s1 = (u32)t0;
    s0 = t1;
    SubVector((float *)((u8 *)&stackFrame_80[0]), a1_2, a2);
    a1_2 = (float *)s2;
    a2 = (float *)(u32)s1;
    OuterProduct((float *)((u8 *)&stackFrame_70[0]), a1_2, a2);
    a2 = a3;
    OuterProduct((float *)((u8 *)&stackFrame_60[0]), (float *)((u8 *)&stackFrame_80[0]), a2);
    a1_2 = a3;
    f0 = InnerProduct((float *)((u8 *)&stackFrame_70[0]), a1_2);
    f20 = (float)f0;
    f0 = fabsf((float)f20);
    f1 = 9.99999975e-05f;
    if (f0 < 9.99999975e-05f) {
        v0 = 0;
        return v0;
    }
    f0 = 1.0f;
    f20 = (1.0f / f20);
    f0 = InnerProduct((float *)((u8 *)&stackFrame_70[0]), (float *)((u8 *)&stackFrame_80[0]));
    f21 = (f20 * f0);
    a1_2 = (float *)s2;
    a0_2 = (float *)((u8 *)&stackFrame_60[0]);
    f0 = InnerProduct(a0_2, a1_2);
    f1 = (f20 * f0);
    f0 = 0.0f;
    if (f21 >= 0.0f) {
        if (f1 < f0) {
            goto _L00159580;
        }
        f1 = (f21 + (float)f1);
        v0 = 0x3f800000;
        f0 = 1.0f;
        if (f1 <= 1.0f) {
            goto _L00159588;
        }
    }
    _L00159580:;
    v0 = 0;
    goto _L001595A0;
    _L00159588:;
    a1_2 = (float *)(u32)s1;
    f0 = InnerProduct((float *)((u8 *)&stackFrame_60[0]), a1_2);
    v0 = 1;
    *(f32 *)s0 = (f20 * f0);
    _L001595A0:;
    return v0;
}
