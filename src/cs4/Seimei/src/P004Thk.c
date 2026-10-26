#include "common.h"

/* CheckP004AttackState @ 0x1940A0 .. 0x19417C (0xdc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x194120
 *   cfg: kept branch: 0x1940b0 if (..) goto .L001940D8
 *   cfg: kept goto: 0x1940d0 -> .L00194160
 *   cfg: loop body is not one contiguous region: .L001940F8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern unsigned int CheckEneAttackEnable(void *, void *);
extern unsigned int EneSearchAttackRange();
extern unsigned int ChangeAnimParam(void *, signed int, float);

/* P004ThkWalk @ 0x194180 .. 0x1941CC (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckP004AttackState(void *, void *);
extern unsigned int CheckEneWalkState(void *, void *);

/* P004ThkStay @ 0x1941D0 .. 0x19421C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckP004AttackState(void *, void *);
extern unsigned int CheckEneStayState(void *, void *);

extern int rand();
extern void SetAnimUserScale(void *, signed int, float *);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void P004ThkInit(void *enemy, void *controller);
static void P004ThkStay(void *a0 , void *a1 );
static void P004ThkWalk(void *a0 , void *a1 );
static unsigned int CheckP004AttackState(void *a0 , void *a1 );

void P004ThkInit(void *enemy, void *controller) {
    float scale = 0.5f + 0.1f * (rand() % 11);
    ((void **)controller)[0] = (void *)P004ThkStay;
    ((void **)controller)[1] = (void *)P004ThkWalk;
    { float v1[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
      v1[1] = scale; SetAnimUserScale(enemy,21,v1);
      { float v2[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
        v2[1] = scale; SetAnimUserScale(enemy,22,v2);
        { float v3[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
          v3[1] = scale; SetAnimUserScale(enemy,23,v3);
          { float v4[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
            v4[1] = scale; SetAnimUserScale(enemy,24,v4);
            { float v5[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
              v5[1] = scale; SetAnimUserScale(enemy,25,v5);
              { float v6[4] __attribute__((aligned(16))) = {1.0f,0.0f,1.0f,0.0f};
                v6[1] = scale; SetAnimUserScale(enemy,26,v6);
              }
            }
          }
        }
      }
    }
}

static void P004ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckP004AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckEneStayState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1dc));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1dc)) = v1;
    }
    return;
}

static void P004ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckP004AttackState(a0, a1);
    a0 = (void *)s1;
    if (v0 == 0) {
        a1 = (void *)s0;
        CheckEneWalkState(a0, a1);
        v1 = *(u16 *)(((u8 *)s0 + 0x1de));
        v1 = v1 + 1;
        *(u16 *)(((u8 *)s0 + 0x1de)) = v1;
    }
    return;
}

static unsigned int CheckP004AttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u32 s1;
    u32 s0;
    u32 v0;

    s3 = (u8 *)a0;
    s2 = (u8 *)a1;
    v0 = CheckEneAttackEnable(a0, a1);
    if (v0 != 0) {
        goto _L001940D8;
    }
    v0 = 0;
    goto _L00194160;
    _L001940D8:;
    v0 = *(u8 *)(s2 + 0x1f0);
    s0 = 2;
    s0 = v0 != 0 ? (s32)s0 : (s32)0;
    v0 = s0 + 2;
    s1 = s0;
    if ((s32)s0 < (s32)v0) {
        do {
            a0 = (void *)s3;
            a1 = (void *)s2;
            v0 = EneSearchAttackRange(a0, a1, s1);
            v0 = v0 != 0;
            v0 = v0 ^ 1;
            if (v0 == 0) {
                v0 = s1 + 0x32;
                a0 = (void *)s3;
                a1 = (void *)(u16)v0;
                ChangeAnimParam(a0, (signed int)a1, 0.0f);
                *(u8 *)(s3 + 0x12a) = s1;
                v0 = 2;
                *(u8 *)(s2 + 0x180) = v0;
                v0 = 1;
                return v0;
            }
            s1 = s1 + 1;
            v0 = s0 + 2;
            v0 = (s32)s1 < (s32)v0;
        } while (v0 != 0);
    }
    v0 = 0;
    _L00194160:;
    return v0;
}
