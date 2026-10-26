#include "common.h"

/* E031ActInit @ 0x1A4F00 .. 0x1A4F0C (0xc bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */

u32 E031ActInit(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    *(u8 *)(((u8 *)a1 + 0x24a)) = 1;
    return;
}
