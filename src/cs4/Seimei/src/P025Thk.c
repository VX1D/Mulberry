#include "common.h"

/* CheckP025AttackState @ 0x200690 .. 0x2007BC (0x12c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x20077c
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern unsigned int CheckAnimParam(void *, signed int);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 V0[];

/* P025ThkWalk @ 0x2007C0 .. 0x20081C (0x5c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckP025AttackState(void *, void *);
extern unsigned int CheckEneWalkState(void *, void *);

/* P025ThkStay @ 0x200820 .. 0x20087C (0x5c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckP025AttackState(void *, void *);
extern unsigned int CheckEneStayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P025ThkInit(s32 a0 , u32 *a1 );
static void P025ThkStay(void *a0 , void *a1 );
static void P025ThkWalk(void *a0 , void *a1 );
static unsigned int CheckP025AttackState(void *a0 , void *a1 );


/* P025ThkInit @ 0x200880 .. 0x20089C (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * P025ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)P025ThkStay;
    *(u32 *)a1 = (u32)P025ThkStay;
    v1 = (u8 *)P025ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)P025ThkWalk;
    return;
}

static void P025ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u8 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u8 *)a1;
    v0 = CheckP025AttackState(a0, a1);
    if (v0 == 0) {
        v1 = *(u8 *)(((u8 *)s0 + 0x1f0));
        a0 = (void *)s1;
        if (v1 == 0) {
            a1 = (void *)s0;
            CheckEneStayState(a0, a1);
        }
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}

static void P025ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u8 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u8 *)a1;
    v0 = CheckP025AttackState(a0, a1);
    if (v0 == 0) {
        v1 = *(u8 *)(((u8 *)s0 + 0x1f0));
        a0 = (void *)s1;
        if (v1 == 0) {
            a1 = (void *)s0;
            CheckEneWalkState(a0, a1);
        }
        v1 = *(u16 *)(((u8 *)s0 + 0x1de));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    }
    return;
}

static unsigned int CheckP025AttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u32 a2;
    s32 s1;
    u32 v0;
    u8 *s0;

    s3 = (u8 *)a0;
    s2 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 == 0) {
        v0 = 0;
    } else {
        v0 = *(u8 *)(s2 + 0x1f0);
        s1 = v0 != 0;
        v0 = EneSearchAttackRange((u32)s3, (u32)s2, (u32)s1);
        if (v0 == 0) {
            v0 = 0;
        } else {
            v0 = *(u8 *)(s2 + 0x1f0);
            if (v0 != 0) {
                s0 = (u8 *)*(s32 *)(s3 + 0x1b4);
                a0 = (void *)s3;
                a1 = (void *)s2;
                *(u8 *)(s3 + 0x12a) = s1;
                ((void (*)(u32, u32, s32))(s32)*(s32 *)(s2 + 0x110))((u32)a0, (u32)a1, 0x33);
                v0 = CheckAnimParam((void *)(u32)(s32)s0, 0x2d);
                if (v0 != 0) {
                    v0 = *(s32 *)(s0 + 0x148);
                    a1 = (void *)(s0 + 0x20);
                    a0 = (void *)(s32)0x1ba;
                    a2 = (u32)V0;
                    *(u8 *)((v0 + 0x245)) = 2;
                    SFX_Create_OnAng((unsigned short)a0, (float *)a1, (float *)V0);
                } else {
                    a2 = (u32)V0;
                    SFX_Create_OnAng(0x1bb, (float *)(u32)(s32)(s0 + 0x20), (float *)V0);
                }
            } else {
                ChangeAnimParam((void *)s3, 0x32, 0.0f);
                *(u8 *)(s3 + 0x12a) = s1;
                *(u8 *)(s2 + 0x180) = 2;
            }
            v0 = 1;
        }
    }
    return v0;
}
