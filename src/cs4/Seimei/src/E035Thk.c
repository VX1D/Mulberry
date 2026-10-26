#include "common.h"

/* E035ThkWalk @ 0x1FFB30 .. 0x1FFC00 (0xd0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1ffb90
 *   delay: daddu at 0x1ffbbc writes a register its branch at 0x1ffbb8 reads
 *   cfg: loop body is not one contiguous region: .L001FFB68
 *   cfg: kept branch: 0x1ffb68 if (..) goto .L001FFBB0
 *   cfg: kept goto: 0x1ffb88 -> .L001FFBC0
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern unsigned int CheckEneWalkState(void *, void *);
extern void SetMyCrouchDisable(unsigned char);

/* E035ThkStay @ 0x1FFC00 .. 0x1FFCD0 (0xd0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1ffc60
 *   delay: daddu at 0x1ffc8c writes a register its branch at 0x1ffc88 reads
 *   cfg: loop body is not one contiguous region: .L001FFC38
 *   cfg: kept branch: 0x1ffc38 if (..) goto .L001FFC80
 *   cfg: kept goto: 0x1ffc58 -> .L001FFC90
 */




extern unsigned int CheckEneStayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E035ThkInit(s32 a0 , u32 *a1 );
static void E035ThkStay(void *a0 , void *a1 );
static void E035ThkWalk(void *a0 , void *a1 );


/* E035ThkInit @ 0x1FFCD0 .. 0x1FFCEC (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E035ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E035ThkStay;
    *(u32 *)a1 = (u32)E035ThkStay;
    v1 = (u8 *)E035ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E035ThkWalk;
    return;
}


static void E035ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 s2;
    u32 v1;
    u32 v0;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 == 0) {
        v1 = 0;
    } else {
        s2 = 0;
        do {
            a0 = (void *)s1;
            a1 = (void *)s0;
            v0 = EneSearchAttackRange(a0, a1, s2);
            v1 = v0 != 0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                goto _L001FFC80;
            }
            v0 = s2 + 0x32;
            a0 = (void *)s1;
            a1 = (void *)(u16)v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            *(u8 *)(s1 + 0x12a) = s2;
            v1 = 2;
            *(u8 *)(s0 + 0x180) = v1;
            v1 = 1;
            goto _L001FFC90;
            _L001FFC80:;
            s2 = s2 + 1;
            v1 = (s32)s2 < (s32)5;
        } while (v1 != 0);
        v1 = 0;
    }
    _L001FFC90:;
    a0 = (void *)s1;
    if (v1 == 0) {
        a1 = (void *)s0;
        CheckEneStayState(a0, a1);
        v0 = *(u16 *)(s0 + 0x1dc);
        a0 = (void *)(s32)1;
        v0 = v0 + 1;
        *(u16 *)(s0 + 0x1dc) = v0;
        SetMyCrouchDisable((unsigned char)a0);
    }
    return;
}

static void E035ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 s2;
    u32 v1;
    u32 v0;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 == 0) {
        v1 = 0;
    } else {
        s2 = 0;
        do {
            a0 = (void *)s1;
            a1 = (void *)s0;
            v0 = EneSearchAttackRange(a0, a1, s2);
            v1 = v0 != 0;
            v1 = v1 ^ 1;
            if (v1 != 0) {
                goto _L001FFBB0;
            }
            v0 = s2 + 0x32;
            a0 = (void *)s1;
            a1 = (void *)(u16)v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            *(u8 *)(s1 + 0x12a) = s2;
            v1 = 2;
            *(u8 *)(s0 + 0x180) = v1;
            v1 = 1;
            goto _L001FFBC0;
            _L001FFBB0:;
            s2 = s2 + 1;
            v1 = (s32)s2 < (s32)5;
        } while (v1 != 0);
        v1 = 0;
    }
    _L001FFBC0:;
    a0 = (void *)s1;
    if (v1 == 0) {
        a1 = (void *)s0;
        CheckEneWalkState(a0, a1);
        v0 = *(u16 *)(s0 + 0x1de);
        a0 = (void *)(s32)1;
        v0 = v0 + 1;
        *(u16 *)(s0 + 0x1de) = v0;
        SetMyCrouchDisable((unsigned char)a0);
    }
    return;
}
