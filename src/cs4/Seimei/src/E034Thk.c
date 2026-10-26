#include "common.h"

/* E034ThkWalk @ 0x1FFEF0 .. 0x1FFFB8 (0xc8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1fff50
 *   delay: daddu at 0x1fff7c writes a register its branch at 0x1fff78 reads
 *   cfg: loop body is not one contiguous region: .L001FFF28
 *   cfg: kept branch: 0x1fff28 if (..) goto .L001FFF70
 *   cfg: kept goto: 0x1fff48 -> .L001FFF80
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern unsigned int CheckEneWalkState(void *, void *);

/* E034ThkStay @ 0x1FFFC0 .. 0x200088 (0xc8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x200020
 *   delay: daddu at 0x20004c writes a register its branch at 0x200048 reads
 *   cfg: loop body is not one contiguous region: .L001FFFF8
 *   cfg: kept branch: 0x1ffff8 if (..) goto .L00200040
 *   cfg: kept goto: 0x200018 -> .L00200050
 *   declaration vs inferred signature: return void vs inferred u32
 */




extern unsigned int CheckEneStayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E034ThkInit(s32 a0 , u32 *a1 );
static void E034ThkStay(void *a0 , void *a1 );
static void E034ThkWalk(void *a0 , void *a1 );


/* E034ThkInit @ 0x200090 .. 0x2000AC (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E034ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E034ThkStay;
    *(u32 *)a1 = (u32)E034ThkStay;
    v1 = (u8 *)E034ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E034ThkWalk;
    return;
}

static void E034ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
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
                goto _L00200040;
            }
            v0 = s2 + 0x32;
            a0 = (void *)s1;
            a1 = (void *)(u16)v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            *(u8 *)(s1 + 0x12a) = s2;
            v1 = 2;
            *(u8 *)(s0 + 0x180) = v1;
            v1 = 1;
            goto _L00200050;
            _L00200040:;
            s2 = s2 + 1;
            v1 = (s32)s2 < (s32)5;
        } while (v1 != 0);
        v1 = 0;
    }
    _L00200050:;
    a0 = (void *)s1;
    if (v1 == 0) {
        a1 = (void *)s0;
        CheckEneStayState(a0, a1);
        v1 = *(u16 *)(s0 + 0x1dc);
        v1 = v1 + 1;
        *(u16 *)(s0 + 0x1dc) = v1;
    }
    return;
}

static void E034ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
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
                goto _L001FFF70;
            }
            v0 = s2 + 0x32;
            a0 = (void *)s1;
            a1 = (void *)(u16)v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            *(u8 *)(s1 + 0x12a) = s2;
            v1 = 2;
            *(u8 *)(s0 + 0x180) = v1;
            v1 = 1;
            goto _L001FFF80;
            _L001FFF70:;
            s2 = s2 + 1;
            v1 = (s32)s2 < (s32)5;
        } while (v1 != 0);
        v1 = 0;
    }
    _L001FFF80:;
    a0 = (void *)s1;
    if (v1 == 0) {
        a1 = (void *)s0;
        CheckEneWalkState(a0, a1);
        v1 = *(u16 *)(s0 + 0x1de);
        v1 = v1 + 1;
        *(u16 *)(s0 + 0x1de) = v1;
    }
    return;
}
