#include "common.h"

/* FsFontSetRect @ 0x176BA0 .. 0x176BB4 (0x14 bytes) */

void FsFontSetRect(float *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */, float f14 /* f14
        */, float f15 /* f15 */) {
    *(f32 *)a0 = f12;
    *(f32 *)(((u8 *)a0 + 4)) = f13;
    *(f32 *)(((u8 *)a0 + 8)) = f14;
    *(f32 *)(((u8 *)a0 + 0xc)) = f15;
    return;
}
