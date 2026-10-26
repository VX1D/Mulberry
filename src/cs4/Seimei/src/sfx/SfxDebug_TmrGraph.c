#include "common.h"

/* SfxDebug_TmrGraph_Clear @ 0x1BF380 .. 0x1BF3DC (0x5c bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern u32 s_aCPUCountSum[];
extern u32 s_aCPUCount[];

/* SfxDebug_TmrGraph_End @ 0x1BF3E0 .. 0x1BF438 (0x58 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 GetTime(void);

/* SfxDebug_TmrGraph_Start @ 0x1BF440 .. 0x1BF480 (0x40 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 GetTime(void);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SfxDebug_TmrGraph_Start(unsigned short a0 );
signed int SfxDebug_TmrGraph_End(unsigned short a0 );
u32 SfxDebug_TmrGraph_Clear(void);


signed int SfxDebug_TmrGraph_Start(unsigned short a0 /* r4 */) {
    u16 s0;
    u32 v0;
    u32 *v1;

    s0 = a0;
    v0 = GetTime();
    v1 = s_aCPUCount;
    *(u32 *)(u32 *)((u8 *)s_aCPUCount + (u32)((u32)s0 << 2)) = v0;
    return 1;
}

signed int SfxDebug_TmrGraph_End(unsigned short a0 /* r4 */) {
    u32 a1;
    s32 s0;
    u32 v1;
    u32 v0;
    u32 a0_2;

    s0 = (u32)(u16)a0 << 2;
    v0 = GetTime();
    a0_2 = (u32)s_aCPUCount;
    v1 = (u32)s_aCPUCountSum;
    a1 = (s32)((u8 *)s_aCPUCount + s0);
    a0_2 = (s32)((u8 *)s_aCPUCountSum + s0);
    a1 = *(s32 *)a1;
    *(u32 *)a0_2 += v0 - a1;
    return 1;
}

u32 SfxDebug_TmrGraph_Clear(void) {
    u32 a2;
    u32 *a1;
    u32 *a0;
    u32 v1;

    a2 = 0;
    a1 = s_aCPUCountSum;
    a0 = s_aCPUCount;
    do {
        *(u32 *)a1 = 0;
        *(u32 *)a0 = 0;
        a2 = a2 + 5;
        *(u32 *)(((u8 *)a1 + 4)) = 0;
        v1 = (u32)a2 < (u32)0xa;
        *(u32 *)(((u8 *)a0 + 4)) = 0;
        *(u32 *)(((u8 *)a1 + 8)) = 0;
        *(u32 *)(((u8 *)a0 + 8)) = 0;
        *(u32 *)(((u8 *)a1 + 0xc)) = 0;
        *(u32 *)(((u8 *)a0 + 0xc)) = 0;
        *(u32 *)(((u8 *)a1 + 0x10)) = 0;
        *(u32 *)(((u8 *)a0 + 0x10)) = 0;
        a1 = (u32 *)((u8 *)a1 + 0x14);
        a0 = (u32 *)((u8 *)a0 + 0x14);
    } while (v1 != 0);
    return;
}
static u32 s_aCPUCount[0xa];
static u32 s_aCPUCountSum[0xa];
