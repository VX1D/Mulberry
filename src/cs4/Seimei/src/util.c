#include "common.h"


/* MngState_GetEndTime @ 0x17D940 .. 0x17D97C (0x3c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int GetTime(void);

/* MngState_GetStartTime @ 0x17D980 .. 0x17D9A8 (0x28 bytes, frame 0x20) */

extern unsigned int GetTime(void);

/* _MemAlloc @ 0x17D9E0 .. 0x17D9F4 (0x14 bytes) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$677 is the string '_MemAlloc'
 *   literal: @746 is the string ''
 *   tail: j MemAllocReal at 0x17d9ec leaves the function
 *   a0 forwarded to MemAllocReal
 *   declaration vs inferred signature: return void * vs inferred void
 */

extern void * MemAllocReal(unsigned int, char *, char *);

/* ReadFile @ 0x17DA00 .. 0x17DA60 (0x60 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int ReadFile(unsigned char **a0 , char *a1 , signed int a2 );
void * _MemAlloc(unsigned int a0 );
u32 MngState_Init(u32 *a0 );
u32 MngState_ResetTime(u32 *a0 );
void MngState_GetStartTime(void *a0 );
void MngState_GetEndTime(void *a0 );
signed int MngState_UpdateExeCheck(void *a0 );
signed int MngState_DrawExeCheck(void *a0 );
float GetDist_(float *v1, float *v2);


signed int ReadFile(unsigned char **a0 /* r4 */, char *a1 /* r5 */, signed int a2 /* r6 */) {
    s32 t1;
    u32 *s0;
    s32 v0;

    t1 = (s32)a2;
    s0 = (u32 *)a0;
    a0 = (unsigned char **)a1;
    a2 = (signed int)s0;
    a1 = (char *)(s32)-1;
    v0 = FileRead((char *)a0, (signed int)a1, (unsigned char **)a2, (s32)1, (s32)a1, t1, 0);
    if (v0 <= 0) {
        *(u32 *)s0 = 0;
        v0 = 0;
    } else {
        v0 = 1;
    }
    return v0;
}

void * _MemAlloc(unsigned int a0 /* r4 */) {
    return MemAllocReal(a0, (char *)(u8 *)((char *)__FUNCTION__), (char *)(u8 *)"");
}

/* MngState_Init @ 0x17D9C0 .. 0x17D9DC (0x1c bytes) */

u32 MngState_Init(u32 *a0 /* r4 */) {
    u32 v0;

    *(u32 *)a0 = 0;
    v0 = 1;
    *(u32 *)(((u8 *)a0 + 4)) = 0;
    *(u32 *)(((u8 *)a0 + 0xc)) = 0;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    *(u32 *)(((u8 *)a0 + 0x10)) = 0;
    return v0;
}

/* MngState_ResetTime @ 0x17D9B0 .. 0x17D9C0 (0x10 bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 MngState_ResetTime(u32 *a0 /* r4 */) {
    u32 v1;

    v1 = *(u32 *)(((u8 *)a0 + 8));
    *(u32 *)(((u8 *)a0 + 0xc)) = v1;
    *(u32 *)(((u8 *)a0 + 8)) = 0;
    return;
}

void MngState_GetStartTime(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    s0 = (u32 *)a0;
    v0 = GetTime();
    *(u32 *)(((u8 *)s0 + 0x10)) = v0;
    return;
}

void MngState_GetEndTime(void *a0 /* r4 */) {
    u32 *s0;
    u32 v0;
    u32 v1;

    s0 = (u32 *)a0;
    v0 = GetTime();
    a0 = (void *)*(s32 *)(((u8 *)s0 + 0x10));
    v1 = *(s32 *)(((u8 *)s0 + 8));
    *(u32 *)(((u8 *)s0 + 8)) = (s32)((u8 *)v1 + (u32)(s32)((u8 *)v0 - (u32)(a0)));
    *(u32 *)(((u8 *)s0 + 0x10)) = 0;
    return;
}

signed int MngState_UpdateExeCheck(void *a0 /* r4 */) {
    switch (*(s32 *)a0) {
    default:
        return 0;
    case 2:
        return !(*(s32 *)((u8 *)a0 + 4) & 2);
    }
}


/* MngState_DrawExeCheck @ 0x17D8F0 .. 0x17D904 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: xori at 0x17d900 computes the return value
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int MngState_DrawExeCheck(void *a0 /* r4 */) {
    u32 v0;

    v0 = *(s32 *)(((u8 *)a0 + 4));
    v0 = v0 & 4;
    v0 = v0 != 0;
    return v0 ^ 1;
}

float GetDist_(float *v1, float *v2) {
    float dx;
    float dy;
    float dz;
    float dd;

    dx = v2[0] - v1[0];
    dy = v2[1] - v1[1];
    dz = v2[2] - v1[2];
    dd = sqrtf(dx * dx + dy * dy + dz * dz);
    return dd;
}
float g_ZeroVec[0x4] = {
    0.0f, 0.0f, 0.0f, 1.0f
};
u32 g_UnitMat[0x10] = {
    0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000, 0, 0, 0, 0, 0x3f800000
};
