#include "common.h"

extern void _SetReverb(signed int, signed short, signed short, signed short);
extern signed int fssdsynthAddReverb(signed int, signed short, signed short, signed short, signed short, signed short, signed short, signed int);
extern void fssdsynthSetReverb(signed int);
extern u32 g_pSndMng;
u8 s_Mng[0x11];


/* SND_ReverbProc @ 0x1AA1C0 .. 0x1AA4C0 (0x300 bytes, frame 0x20) */

extern signed int fssdsynthSetParam(unsigned short, unsigned short);
extern void * memcpy(void *, const void *, unsigned int);
extern signed int fssdsynthRemoveReverb(signed int);


/* SND_SetReverbStudioC @ 0x1AA580 .. 0x1AA598 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: j _SetReverb at 0x1aa590 leaves the function
 */

extern void _SetReverb(signed int, signed short, signed short, signed short);

/* SND_SetReverbOff @ 0x1AA5A0 .. 0x1AA5B4 (0x14 bytes) */
/*
 * dcomp notes:
 *   tail: j _SetReverb at 0x1aa5ac leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void _SetReverb(signed int, signed short, signed short, signed short);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SND_SetReverbOff(void);
void SND_SetReverbStudioC(signed int a0 );
void _SetReverb(signed int mode, signed short left, signed short right, signed short depth);
void SND_ReverbProc(void);
void SND_InitReverb(void);


void SND_SetReverbOff(void) {
    _SetReverb(0, 0, 0, 0);
    return;
}

void SND_SetReverbStudioC(signed int a0 /* r4 */) {
    _SetReverb(4, 0, 0, a0);
    return;
}


void _SetReverb(signed int mode, signed short left, signed short right, signed short depth) {
    if (left < 0) left = 0;
    if (left > 127) left = 127;
    if (right < 0) right = 0;
    if (right > 127) right = 127;
    if (depth < 0) depth = 0;
    if (depth > 127) depth = 127;
    s_Mng[8] = mode;
    s_Mng[9] = depth;
    s_Mng[10] = left;
    s_Mng[11] = right;
}

void SND_ReverbProc(void) {
    u32 a3;
    s8 a2;
    u8 *s0;
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    a1 = (u32)(u8 *)(s_Mng + 8);
    v1 = g_pSndMng;
    s0 = s_Mng;
    if (v1 != 0) {
        a0 = *(u8 *)s0;
        v1 = *(u8 *)a1;
        if (a0 != v1) {
            v0 = *(u8 *)(s0 + 1);
            if ((s32)v0 > 0) {
                *(u8 *)(s0 + 1) = v0 + -1;
                v1 = *(u8 *)(s0 + 1);
                if ((s32)v1 < 0) {
                    v1 = 0;
                }
                if ((s32)v1 > (s32)0x7f) {
                    v1 = 0x7f;
                }
                v0 = v1 << 7;
                s0 = (u8 *)(s32)(v1 * 0x81);
                if ((s32)s0 < 0) {
                    s0 = (u8 *)0;
                }
                if ((s32)s0 > (s32)0x3fff) {
                    s0 = (u8 *)(s32)0x3fff;
                }
                fssdsynthSetParam(0xb81, (s32)s0);
                fssdsynthSetParam(0xc81, (s32)s0);
            } else {
                memcpy((void *)s0, (const void *)a1, 8);
                *(u8 *)(s0 + 1) = 0;
                a0 = *(s8 *)((g_pSndMng + 0x36));
                if ((s32)a0 >= 0 && (s32)a0 <= (s32)3) {
                    fssdsynthRemoveReverb(a0);
                    *(s8 *)((g_pSndMng + 0x36)) = -1;
                }
                a1 = (s16)((u32)s_Mng[1] * 0x81);
                v0 = fssdsynthAddReverb(*(u8 *)s_Mng, a1, a1, s_Mng[2], s_Mng[3], a1, a1, 1);
                *(u8 *)((g_pSndMng + 0x36)) = v0;
                a0 = *(s8 *)((g_pSndMng + 0x36));
                if ((s32)a0 >= 0 && (s32)a0 <= (s32)3) {
                    fssdsynthSetReverb(a0);
                }
            }
        } else {
            a0 = *(u8 *)((a1 + 1));
            v1 = *(u8 *)(s0 + 1);
            a3 = 0;
            a2 = 0;
            if (v1 != a0) {
                if ((s32)a0 < (s32)v1) {
                    *(u8 *)(s0 + 1) = v1 + -1;
                } else {
                    *(u8 *)(s0 + 1) = v1 + 1;
                }
                a3 = 1;
            }
            a0 = *(u8 *)((a1 + 2));
            v1 = *(u8 *)(s0 + 2);
            if (v1 != a0) {
                if ((s32)a0 < (s32)v1) {
                    *(u8 *)(s0 + 2) = v1 + -1;
                } else {
                    *(u8 *)(s0 + 2) = v1 + 1;
                }
                a2 += 1;
            }
            a0 = *(u8 *)((a1 + 3));
            v1 = *(u8 *)(s0 + 3);
            if (v1 != a0) {
                if ((s32)a0 < (s32)v1) {
                    *(u8 *)(s0 + 3) = v1 + -1;
                } else {
                    *(u8 *)(s0 + 3) = v1 + 1;
                }
                a2 += 1;
            }
            v1 = a2;
            if ((s32)v1 > 0) {
                a1 = (s16)((u32)s_Mng[1] * 0x81);
                v0 = fssdsynthAddReverb(*(u8 *)s_Mng, a1, a1, s_Mng[2], s_Mng[3], a1, a1, 1);
                *(u8 *)((g_pSndMng + 0x36)) = v0;
            } else if (a3 != 0) {
                v1 = *(u8 *)(s0 + 1);
                if ((s32)v1 < 0) {
                    v1 = 0;
                }
                if ((s32)v1 > (s32)0x7f) {
                    v1 = 0x7f;
                }
                v0 = v1 << 7;
                s0 = (u8 *)(s32)(v1 * 0x81);
                if ((s32)s0 < 0) {
                    s0 = (u8 *)0;
                }
                if ((s32)s0 > (s32)0x3fff) {
                    s0 = (u8 *)(s32)0x3fff;
                }
                fssdsynthSetParam(0xb81, (s32)s0);
                fssdsynthSetParam(0xc81, (s32)s0);
            }
        }
    }
    return;
}

void SND_InitReverb(void) {
    u8 t0;
    u8 a3;
    s16 a1;
    u32 a0;
    u32 v1;
    u32 v0;

    a0 = 0;
    v1 = -1;
    do {
        v0 = g_pSndMng;
        *(s8 *)(((u32)(v0 + a0) + 0x34)) = v1;
        a0 = a0 + 1;
    } while (a0 < (u32)8);
    _SetReverb(0, 0, 0, 0);
    v1 = s_Mng[1];
    a1 = v1 * 0x81;
    a0 = *(u8 *)s_Mng;
    a3 = s_Mng[2];
    t0 = s_Mng[3];
    v0 = fssdsynthAddReverb(a0, a1, a1, a3, t0, a1, a1, 0);
    v1 = g_pSndMng;
    *(u8 *)((v1 + 0x35)) = v0;
    v1 = s_Mng[1];
    a1 = v1 * 0x81;
    a0 = *(u8 *)s_Mng;
    a3 = s_Mng[2];
    t0 = s_Mng[3];
    v0 = fssdsynthAddReverb(a0, a1, a1, a3, t0, a1, a1, 1);
    v1 = g_pSndMng;
    *(u8 *)((v1 + 0x36)) = v0;
    v1 = g_pSndMng;
    a0 = *(s8 *)((v1 + 0x35));
    if ((s32)a0 >= 0 && (s32)a0 <= (s32)3) {
        fssdsynthSetReverb(a0);
    }
    v1 = g_pSndMng;
    a0 = *(s8 *)((v1 + 0x36));
    if ((s32)a0 >= 0 && (s32)a0 <= (s32)3) {
        fssdsynthSetReverb(a0);
    }
}
