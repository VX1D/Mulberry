#include "common.h"

/* RemapMiz @ 0x1A5ED0 .. 0x1A5FE0 (0x110 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A5EE8
 *   cfg: loop body is not one contiguous region: .L001A5F90
 *   a2#6 is the pointer held in a0+0x48
 *   declaration vs inferred signature: return void vs inferred u32
 */

void RemapMiz(void *a0 /* r4 */) {
    s32 a1;
    s32 t0;
    u8 *v1;
    u8 *a3;
    u32 a2;
    u8 *a0_bytes; // a0

    a0_bytes = (u8 *)a0;
    a2 = *(s32 *)(a0_bytes + 8);
    v1 = (u8 *)(a0_bytes + 0x10);
    a1 = 0;
    if ((u8 *)0 < (u8 *)a2) {
        do {
            a2 = *(s32 *)(v1 + 0x30);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x30) = (s32)(a0_bytes + a2);
            }
            a2 = *(s32 *)(v1 + 0x34);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x34) = (s32)(a0_bytes + a2);
            }
            a2 = *(s32 *)(v1 + 0x38);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x38) = (s32)(a0_bytes + a2);
            }
            a2 = *(s32 *)(v1 + 0x3c);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x3c) = (s32)(a0_bytes + a2);
            }
            a2 = *(s32 *)(v1 + 0x40);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x40) = (s32)(a0_bytes + a2);
            }
            a2 = *(s32 *)(v1 + 0x44);
            if (a2 != 0) {
                *(u32 *)(v1 + 0x44) = (s32)(a0_bytes + a2);
            }
            a2 = *(u16 *)(v1 + 0xa);
            a3 = (u8 *)*(s32 *)(v1 + 0x38);
            t0 = 0;
            if (0 < (s32)a2) {
                do {
                    a2 = *(s32 *)(a3 + 8);
                    if (a2 != 0) {
                        *(u32 *)(a3 + 8) = (s32)(a0_bytes + a2);
                    }
                    a2 = *(u16 *)(v1 + 0xa);
                    t0 = t0 + 1;
                    a2 = t0 < (s32)a2;
                    a3 = (u8 *)(a3 + 0x10);
                } while (a2 != 0);
            }
            a2 = *(s32 *)(a0_bytes + 8);
            a1 = a1 + 1;
            a2 = (u32)a1 < a2;
            v1 = (u8 *)(v1 + 0x48);
        } while (a2 != 0);
    }
    return;
}
