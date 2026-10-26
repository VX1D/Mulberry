#include "common.h"

/* GetMicroCodeMPG @ 0x141B10 .. 0x141CE0 (0x1d0 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x141b1c writes a register its branch at 0x141b18 reads
 *   delay: addiu at 0x141b34 writes a register its branch at 0x141b30 reads
 *   delay: addiu at 0x141b4c writes a register its branch at 0x141b48 reads
 *   delay: addiu at 0x141b64 writes a register its branch at 0x141b60 reads
 *   delay: addiu at 0x141b7c writes a register its branch at 0x141b78 reads
 *   delay: addiu at 0x141b94 writes a register its branch at 0x141b90 reads
 *   delay: addiu at 0x141bac writes a register its branch at 0x141ba8 reads
 *   delay: addiu at 0x141bc4 writes a register its branch at 0x141bc0 reads
 *   delay: addiu at 0x141bdc writes a register its branch at 0x141bd8 reads
 *   delay: addiu at 0x141bf4 writes a register its branch at 0x141bf0 reads
 *   delay: addiu at 0x141c0c writes a register its branch at 0x141c08 reads
 *   delay: addiu at 0x141c24 writes a register its branch at 0x141c20 reads
 *   delay: addiu at 0x141c3c writes a register its branch at 0x141c38 reads
 *   delay: addiu at 0x141c54 writes a register its branch at 0x141c50 reads
 *   delay: addiu at 0x141c6c writes a register its branch at 0x141c68 reads
 *   delay: addiu at 0x141c84 writes a register its branch at 0x141c80 reads
 *   delay: addiu at 0x141c9c writes a register its branch at 0x141c98 reads
 *   delay: addiu at 0x141cb4 writes a register its branch at 0x141cb0 reads
 *   delay: daddu at 0x141ccc writes a register its branch at 0x141cc8 reads
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

extern u32 Vu1ProgMCClipAmbi[];
extern u32 Vu1ProgMCScrollClipAmbi[];
extern u32 Vu1ProgMCEnvClipAmbi[];
extern u32 Vu1ProgMCClipAmbiPLight[];
extern u32 Vu1ProgMCScrollClipAmbiPLight[];
extern u32 Vu1ProgMCEnvClipAmbiPLight[];
extern u32 Vu1ProgMCClipJointAmbi[];
extern u32 Vu1ProgMCClipJointAmbiPLight[];
extern u32 Vu1ProgMCJointLight[];
extern u32 Vu1ProgMCScrollJointLight[];
extern u32 Vu1ProgMCClipJointLight[];
extern u32 Vu1ProgMCScrollClipJointLight[];
extern u32 Vu1ProgMCMorphClipJointLight[];
extern u32 Vu1ProgMCBase[];
extern u32 Vu1ProgMCShadowMake[];
extern u32 Vu1ProgMCShadowDraw[];
extern u32 Vu1ProgMCScissor[];
extern u32 Vu1ProgMCScissorTriangle[];
extern u32 Vu1ProgMCMulti[];

/* Vu1SendProg @ 0x141CE0 .. 0x141DBC (0xdc bytes, frame 0x20) */

extern void * sceDmaGetChan(int);
extern void sceDmaSend(void *, void *);
extern u32 Vu1ProgMCMatrix[];
extern u32 Vu1ProgMCClipAmbi[];
extern u32 Vu1ProgMCClipAmbiPLight[];
extern u32 Vu1ProgMCJointLight[];
extern u32 Vu1ProgMCClipJointLight[];
extern u32 Vu1ProgMCShadowMake[];
extern u32 Vu1ProgMCShadowDraw[];
extern u32 Vu1ProgMCClipJointAmbi[];

/* Vu1Init @ 0x141DC0 .. 0x141DEC (0x2c bytes, frame 0x10) */

extern void sceDevVif1Reset(void);
extern u32 sceDevVu1Reset(void);
extern u32 sceDevVu1PutTBit();

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void Vu1Init(void);
void Vu1SendProg(void);
unsigned short GetMicroCodeMPG(unsigned int *a0 );


void Vu1Init(void) {
    sceDevVif1Reset();
    sceDevVu1Reset();
    sceDevVu1PutTBit(1);
    return;
}

void Vu1SendProg(void) {
    u8 *a1;
    u8 *s0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)sceDmaGetChan(1);
    s0 = v0;
    a1 = (u8 *)Vu1ProgMCMatrix;
    ((struct { unsigned char _pad:6; unsigned char f:1; } *)&*(u8 *)v0)->f = 1;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCMatrix);
    a1 = (u8 *)Vu1ProgMCClipAmbi;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCClipAmbi);
    a1 = (u8 *)Vu1ProgMCClipAmbiPLight;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCClipAmbiPLight);
    a1 = (u8 *)Vu1ProgMCJointLight;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCJointLight);
    a1 = (u8 *)Vu1ProgMCClipJointLight;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCClipJointLight);
    a1 = (u8 *)Vu1ProgMCShadowMake;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCShadowMake);
    a1 = (u8 *)Vu1ProgMCShadowDraw;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCShadowDraw);
    a1 = (u8 *)Vu1ProgMCClipJointAmbi;
    sceDmaSend((void *)s0, (void *)Vu1ProgMCClipJointAmbi);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0);
    return;
}

unsigned short GetMicroCodeMPG(unsigned int *a0 /* r4 */) {
    if ((u32)a0 == (u32)Vu1ProgMCClipAmbi) {
        return 0x40;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScrollClipAmbi) {
        return 0x40;
    }
    if ((u32)a0 == (u32)Vu1ProgMCEnvClipAmbi) {
        return 0x40;
    }
    if ((u32)a0 == (u32)Vu1ProgMCClipAmbiPLight) {
        return 0x100;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScrollClipAmbiPLight) {
        return 0x100;
    }
    if ((u32)a0 == (u32)Vu1ProgMCEnvClipAmbiPLight) {
        return 0x100;
    }
    if ((u32)a0 == (u32)Vu1ProgMCClipJointAmbi) {
        return 0x700;
    }
    if ((u32)a0 == (u32)Vu1ProgMCClipJointAmbiPLight) {
        return 0x500;
    }
    if ((u32)a0 == (u32)Vu1ProgMCJointLight) {
        return 0x200;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScrollJointLight) {
        return 0x200;
    }
    if ((u32)a0 == (u32)Vu1ProgMCClipJointLight) {
        return 0x300;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScrollClipJointLight) {
        return 0x300;
    }
    if ((u32)a0 == (u32)Vu1ProgMCMorphClipJointLight) {
        return 0x300;
    }
    if ((u32)a0 == (u32)Vu1ProgMCBase) {
        return 0x400;
    }
    if ((u32)a0 == (u32)Vu1ProgMCShadowMake) {
        return 0x500;
    }
    if ((u32)a0 == (u32)Vu1ProgMCShadowDraw) {
        return 0x600;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScissor) {
        return 0x400;
    }
    if ((u32)a0 == (u32)Vu1ProgMCScissorTriangle) {
        return 0x700;
    }
    return (u32)a0 == (u32)Vu1ProgMCMulti ? (u16)0x700 : (u16)0;
}
