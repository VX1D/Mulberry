#include "common.h"

/* fsHit_GetHitPolygonLine @ 0x159400 .. 0x159470 (0x70 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int GetHitLinePolygon(float *, float *, float *, float *, float *, float *);

signed int fsHit_GetHitPolygonLine(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    u8 *s0;
    u32 v0;
    u8 stackFrame_2C[4] __attribute__((aligned(4)));

    s0 = (u8 *)a2;
    v0 = GetHitLinePolygon((float *)a1, (float *)((u8 *)a1 + 0x10), (float *)a0, (float *)((u8 *)a0
        + 0x30), (float *)((u8 *)a0 + 0x40), (float *)(u8 *)((u8 *)&stackFrame_2C[0]));
    if (v0 != 0) {
        if ((u32)s0 != 0) {
            *(f32 *)s0 = *(float *)((u8 *)&stackFrame_2C[0]);
            *(f32 *)(s0 + 4) = *(float *)((u8 *)&stackFrame_2C[0]);
        }
        v0 = 1;
    } else {
        v0 = 0;
    }
    return v0;
}
