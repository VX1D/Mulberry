#include "common.h"

/* DrawPhantomFilter @ 0x181100 .. 0x1812B0 (0x1b0 bytes) */

extern u32 lpMdlPacketMem;
extern u32 PhantomCounter;
extern u8 *lpDrawMng;


/* GetFirstBlastDir @ 0x1812B0 .. 0x1812F8 (0x48 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001812C0
 */

extern u8 BlastMng[];

/* UpdateBlast @ 0x181300 .. 0x181500 (0x200 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x3f800000 at 0x18132c
 *   fpu: float literal 0x41f00000 at 0x181334
 *   fpu: float literal 0x3c03126f at 0x181358
 *   fpu: float literal 0x42700000 at 0x181374
 *   fpu: float literal 0x3ba3d70a at 0x181394
 *   fpu: float literal 0x3a03126f at 0x1813b4
 *   fpu: float literal 0x41a00000 at 0x1813d4
 *   fpu: float literal 0x42480000 at 0x1813fc
 *   fpu: float literal 0x00000000 at 0x181460
 *   cfg: loop body is not one contiguous region: .L00181318
 */

extern void sceVu0Normalize(void *, void *);
extern void sceVu0ScaleVector(void *, void *, float);
extern signed int Menu_TD_CallOrder(signed int, signed int, signed int);
extern void SetHeartRate(void *, signed int, unsigned char);
extern void *memset(void *, int, unsigned int);
extern u8 BlastMng[];
extern u8 GameSt[];
extern u32 MdlMng[];

extern void sceVu0SubVector(void *, void *, void *);
extern signed int SFX_Create_OnDir(unsigned short, float *, float *);
extern unsigned int CheckMyDash(void *);
extern u32 CheckMyBlastAnimEnable();
extern void SetMyBlast(void *, unsigned short);
extern signed int SND_Play2D(signed int, signed short, signed short);


/* InitBlast @ 0x1816A0 .. 0x1816D4 (0x34 bytes, frame 0x10) */

extern void *memset(void *, int, unsigned int);
extern u8 BlastMng[];
extern u32 PhantomCounter;
extern u8 GameSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitBlast(void);
void SetBlast(float strength, float duration, float *start, float *end, signed int type);
void UpdateBlast(void);
void * GetFirstBlastDir(void);
void DrawPhantomFilter(void);


void InitBlast(void) {
    memset(BlastMng, 0, 0x100);
    PhantomCounter = 0;
    *(u8 *)((u8 *)&GameSt + 0x1c) = 0;
    return;
}
void SetBlast(float strength, float duration, float *start, float *end, signed int type) {
    u8 *blast = BlastMng;
    u8 *player = (u8 *)(MdlMng + 0x4600);
    if (!blast || blast[0]) return;
    blast[0] = 1;
    *(float *)(blast + 12) = strength;
    *(float *)(blast + 4) = duration;
    *(float *)(blast + 8) = duration;
    *(u16 *)(blast + 2) = type;
    sceVu0SubVector(blast + 16, end, start);
    sceVu0Normalize(blast + 16, blast + 16);
    sceVu0ScaleVector(blast + 16, blast + 16, *(float *)(blast + 12));
    SFX_Create_OnDir(202, start, (float *)(blast + 16));
    PhantomCounter = 120;
    if (CheckMyDash(player)) blast[1] = 1;
    else blast[1] = 0;
    if (GameSt[5] == 0) {
        struct BlastThink { u8 padding[0x18a]; u8 active; u8 gap[0x41]; u16 timer; };
        struct BlastThink *think = (struct BlastThink *)*(u32 *)(player + 0x148);
        if (think->active) {
            think->timer = 300;
            think->active = 0;
        }
        if (CheckMyBlastAnimEnable()) SetMyBlast(player, 63);
    }
    SND_Play2D(0, 100, 0);
    switch (GameSt[20]) {
    case 0: SND_Play2D(0x2717, 100, 0); break;
    case 1: SND_Play2D(0x2721, 100, 0); break;
    case 2: SND_Play2D(0x272c, 100, 0); break;
    }
}

void UpdateBlast(void) {
    u8 *s0;
    u32 a0;
    float f12;
    float f2;
    u32 v1;
    float f1;
    u32 v0;
    float f0;
    u8 *s1;

    s0 = BlastMng;
    do {
        v1 = *(u8 *)s0;
        if (v1 != 0) {
            f2 = *(float *)(s0 + 4);
            f1 = 1.0f;
            v0 = 0x41f00000;
            f0 = 30.0f;
            f1 = (f2 - 1.0f);
            *(f32 *)(s0 + 4) = f1;
            if (f1 < 30.0f) {
                v0 = 0x3c03126f;
                f0 = 0.00800000038f;
                *(f32 *)(s0 + 0xc) = (*(float *)(s0 + 0xc) - 0.00800000038f);
            } else {
                v0 = 0x42700000;
                f0 = 60.0f;
                if (f1 < 60.0f) {
                    v0 = 0x3ba3d70a;
                    f0 = 0.00499999989f;
                    *(f32 *)(s0 + 0xc) = (*(float *)(s0 + 0xc) + f0);
                } else {
                    v0 = 0x3a03126f;
                    f0 = 0.000500000024f;
                    *(f32 *)(s0 + 0xc) = (*(float *)(s0 + 0xc) + f0);
                }
            }
            f2 = *(float *)(s0 + 8);
            f0 = *(float *)(s0 + 4);
            f2 = (f2 - f0);
            if (f2 < 20.0f) {
                GameSt[0x1c] = 0x80;
            } else {
                v0 = 0x42480000;
                f0 = 50.0f;
                if (f2 < 50.0f) {
                    GameSt[0x1c] = (u32)0x80 - (u32)((u32)((s32)(f2 - 20.0f)) << 2);
                } else {
                    GameSt[0x1c] = 0;
                }
            }
            a0 = (s32)((u8 *)0x10 + (u32)(s0));
            sceVu0Normalize((void *)a0, (void *)a0);
            f12 = *(float *)(s0 + 0xc);
            a0 = (s32)(s0 + 0x10);
            sceVu0ScaleVector((void *)a0, (void *)a0, f12);
            f1 = *(float *)(s0 + 4);
            f0 = 0.0f;
            if (f1 <= 0.0f) {
                v0 = GameSt[5];
                s1 = (u8 *)(MdlMng + 0x4600);
                if (v0 == 0) {
                    v0 = 0x10000;
                    Menu_TD_CallOrder(0x10000 | 0xd504, 0x39a, 1);
                }
                v0 = *(u8 *)(s0 + 1);
                if (v0 != 0) {
                    v0 = *(s32 *)(s1 + 0x148);
                    *(u8 *)((v0 + 0x1ac)) = 1;
                }
                SetHeartRate((void *)s1, *(u16 *)(s0 + 2), 6);
                GameSt[0x1c] = 0;
                memset((void *)s0, 0, 0x20);
            }
        }
        s0 = (u8 *)(s0 + 0x20);
    } while (s0 != (u8 *)(BlastMng + 0x100));
    return;
}

void * GetFirstBlastDir(void) {
    u32 a0;
    u32 v0;

    v0 = (u32)BlastMng;
    do {
        a0 = *(u8 *)v0;
        a0 = a0 != 0;
        if ((u32)(a0 ^ 1) == 0) {
            return (void *)v0;
        }
        v0 = v0 + 0x20;
    } while ((u8 *)v0 != (u8 *)(BlastMng + 0x100));
    return (void *)(u32)0;
}

void DrawPhantomFilter(void) {
    u32 t0;
    u32 a2;
    u32 a1;
    u32 a0;
    u8 *v1;
    u64 a1_64;
    u64 a2_64;

    v1 = (u8 *)lpMdlPacketMem;
    a1 = (u32)PhantomCounter * 3;
    a2 = (u8)((s32)((u32)PhantomCounter * 0x60) / 0x78);
    if ((u32)PhantomCounter != 0) {
        a1 = ((u32)lpDrawMng);
        PhantomCounter += -1;
        a0 = *(s32 *)((a1 + 0x408));
        if (a0 != 0) {
            t0 = a1 + 0x60;
        } else {
            t0 = a1 + 0x150;
        }
        a1 = 0x1000000a;
        *(u32 *)v1 = 0x1000000a;
        a1_64 = (u64)((u64)(u32)(u8)a2 << 0x20) | (u64)(0x64);
        *(u32 *)(v1 + 4) = 0;
        *(u32 *)(v1 + 8) = 0;
        a0 = 0x5100000a;
        *(u32 *)(v1 + 0xc) = 0x5100000a;
        *(u32 *)(v1 + 0x10) = 6;
        a0 = 0x10ab0000;
        *(u32 *)(v1 + 0x14) = 0x10ab0000 | 0x4000;
        *(u32 *)(v1 + 0x18) = 0xe;
        a2 = 0x47;
        *(u32 *)(v1 + 0x1c) = 0;
        *(u64 *)(v1 + 0x20) = 0;
        *(s64 *)(v1 + 0x28) = (s32)0x3f;
        *(u64 *)(v1 + 0x30) = 0;
        *(s64 *)(v1 + 0x38) = (s32)a2;
        *(u64 *)(v1 + 0x40) = a1_64;
        *(s64 *)(v1 + 0x48) = (s32)0x42;
        a0 = *(u16 *)t0;
        a2_64 = (s32)((s32)((u32)(a0 & 0x1ff) << 0xb) / 0x40);
        t0 = 6;
        a0 = 0x64120000;
        *(u64 *)(v1 + 0x50) = a2_64 | (u64)((u64)((s32)((s32)0x64120000)) | (u64)((u64)(s32)t0 <<
            0x20));
        a2 = 0x14;
        a0 = 0x3f800000;
        *(s64 *)(v1 + 0x58) = (s32)t0;
        *(s64 *)(v1 + 0x60) = (s32)0x20;
        a0 = 0x8080;
        *(s64 *)(v1 + 0x68) = (s32)a2;
        a2 = 1;
        *(u64 *)(v1 + 0x70) = (u64)((u64)((u64)0x8080 << 0x10) | (u64)(0x8080)) |
            (u64)((u64)(u32)0x3f800000 << 0x20);
        *(s64 *)(v1 + 0x78) = (s32)a2;
        a1 = 0x24000000;
        *(u32 *)(v1 + 0x80) = 2;
        a2 = 0x43;
        *(u32 *)(v1 + 0x84) = 0x24000000;
        a0 = 0x800000;
        *(u32 *)(v1 + 0x88) = a2;
        *(u32 *)(v1 + 0x8c) = 0;
        *(u64 *)(v1 + 0x90) = (u32)(0x800000 | 0x80);
        a0 = 0x72000000;
        a0 = 0x1b800000;
        *(u64 *)(v1 + 0x98) = (u64)((u32)(0x72000000 | 0x7000)) | (u64)((u64)(s32)-1 << 0x20);
        *(u64 *)(v1 + 0xa0) = (u32)(0x1b800000 | 0x1f80);
        a0 = -0x71ff7000;
        *(u64 *)(v1 + 0xa8) = (s32)-0x71ff7000;
        v1 = (u8 *)(v1 + 0xb0);
        lpMdlPacketMem = (s32)v1;
    }
    return;
}
u8 BlastMng[0x100];
static u32 PhantomCounter;
