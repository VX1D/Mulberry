#include "common.h"

/* GetHitLinePolygon @ 0x1596A0 .. 0x159710 (0x70 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1596c0
 *   fpu: float literal 0x3f800000 at 0x1596d4
 *   cfg: kept branch: 0x1596d4 if (..) goto .L001596F0
 *   cfg: kept goto: 0x1596e8 -> .L00159700
 *   a0 takes slot 0 only because of the ABI order
 *   a1 takes slot 1 only because of the ABI order
 *   a2 takes slot 2 only because of the ABI order
 *   a3 takes slot 3 only because of the ABI order
 *   t0 takes slot 4 only because of the ABI order
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int GetHitRateLinePolygon(float *, float *, float *, float *, float *, float *);

signed int GetHitLinePolygon(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */, float *a3
        /* r7 */, float *t0 /* r8 */, float *t1 /* r9 */) {
    float *s0;
    u32 v0;
    float f1;
    float f0;
    s32 fpcc;

    s0 = t1;
    v0 = GetHitRateLinePolygon(a0, a1, a2, a3, t0, t1);
    if (v0 != 0) {
        f1 = *(float *)s0;
        f0 = 0.0f;
        fpcc = f1 < 0.0f;
        v0 = 0x3f800000;
        if (!fpcc) {
            f0 = 1.0f;
            fpcc = f1 <= 1.0f;
            if (fpcc) {
                goto _L001596F0;
            }
        }
        v0 = 0;
        goto _L00159700;
        _L001596F0:;
        v0 = 1;
    } else {
        v0 = 0;
    }
    _L00159700:;
    return v0;
}
