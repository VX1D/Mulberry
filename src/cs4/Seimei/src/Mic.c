#include "common.h"

/* InitMic @ 0x13BD40 .. 0x13BE58 (0x118 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L0013BD70
 *   cfg: loop body is not one contiguous region: .L0013BDA0
 *   declaration vs inferred signature: return void vs inferred u32
 */

void InitMic(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v1;
    u8 *t1;
    u8 *t0;
    s32 a3;
    u32 a2;
    u8 *a1_bytes; // a1

    a1_bytes = (u8 *)a1;
    *(u32 *)(((u8 *)a0 + 0x20)) = (u32)a1_bytes;
    v1 = (s32)(a1_bytes + 0x10);
    a2 = 0x77770000;
    *(u32 *)(((u8 *)a0 + 0x24)) = v1;
    a0 = (void *)(0x77770000 | 0x7777);
    a2 = *(s32 *)(a1_bytes + 0xc);
    if (a2 == (u32)a0) {
        a0 = (void *)*(s32 *)(a1_bytes + 4);
        a3 = 0;
        if ((u8 *)0 < (u8 *)(u32)(s32)a0) {
            do {
                a0 = (void *)*(s32 *)v1;
                if ((u32)(s32)a0 != 0) {
                    *(u32 *)v1 = (s32)(a1_bytes + (u32)(a0));
                }
                t1 = (u8 *)*(s32 *)v1;
                a2 = 0;
                a0 = (void *)*(s16 *)(t1 + 8);
                t0 = (u8 *)(t1 + 0x10);
                if ((u8 *)0 < (u8 *)a0) {
                    do {
                        a0 = (void *)*(s32 *)(t0 + 0x10);
                        if ((u32)(s32)a0 != 0) {
                            *(u32 *)(t0 + 0x10) = (s32)(t1 + (u32)(a0));
                        }
                        a0 = (void *)*(s32 *)(t0 + 0x14);
                        if ((u32)(s32)a0 != 0) {
                            *(u32 *)(t0 + 0x14) = (s32)(t1 + (u32)(a0));
                        }
                        a0 = (void *)*(s32 *)(t0 + 0x18);
                        if ((u32)(s32)a0 != 0) {
                            *(u32 *)(t0 + 0x18) = (s32)(t1 + (u32)(a0));
                        }
                        a0 = (void *)*(s32 *)(t0 + 0x1c);
                        if ((u32)(s32)a0 != 0) {
                            *(u32 *)(t0 + 0x1c) = (s32)(t1 + (u32)(a0));
                        }
                        a0 = (void *)*(s16 *)(t1 + 8);
                        a2 = a2 + 1;
                        a0 = (void *)(s32)(a2 < (u32)a0);
                        t0 = (u8 *)(t0 + 0x20);
                    } while ((u32)(s32)a0 != 0);
                }
                a0 = (void *)*(s32 *)(a1_bytes + 4);
                a3 = a3 + 1;
                a0 = (void *)(s32)((u32)a3 < (u32)(s32)a0);
                v1 = v1 + 4;
            } while ((u32)(s32)a0 != 0);
        }
        v1 = *(s32 *)(a1_bytes + 8);
        if (v1 != 0) {
            v1 = (s32)(a1_bytes + (u32)v1);
            *(u32 *)(a1_bytes + 8) = v1;
        }
        v1 = 1;
        *(u32 *)(a1_bytes + 0xc) = v1;
    }
    return;
}
