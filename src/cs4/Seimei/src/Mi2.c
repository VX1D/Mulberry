#include "common.h"

/* RemapMi2 @ 0x159710 .. 0x1597E0 (0xd0 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00159728
 *   declaration vs inferred signature: return void vs inferred u32
 */

void RemapMi2(void *a0 /* r4 */) {
    s32 t0;
    s32 a3;
    u8 *a2;
    u8 *a1;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(s32 *)(a0_bytes + 8);
    a2 = (u8 *)(a0_bytes + 0x10);
    t0 = 0;
    if ((u8 *)0 < (u8 *)v1) {
        do {
            v1 = *(s32 *)(a2 + 0x30);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x30) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a2 + 0x34);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x34) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a2 + 0x38);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x38) = (s32)(a0_bytes + v1);
            }
            v1 = *(s32 *)(a2 + 0x3c);
            if (v1 != 0) {
                *(u32 *)(a2 + 0x3c) = (s32)(a0_bytes + v1);
            }
            v1 = *(u16 *)a2;
            a1 = (u8 *)*(s32 *)(a2 + 0x30);
            a3 = 0;
            if (0 < (s32)v1) {
                do {
                    *(u32 *)(a1 + 4) = a3;
                    v1 = *(u16 *)a2;
                    a3 = a3 + 1;
                    a1 = (u8 *)(a1 + 0x80);
                    v1 = a3 < (s32)v1;
                } while (v1 != 0);
            }
            v1 = *(s32 *)(a0_bytes + 8);
            t0 = t0 + 1;
            v1 = (u32)t0 < v1;
            a2 = (u8 *)(a2 + 0x40);
        } while (v1 != 0);
    }
    return;
}
