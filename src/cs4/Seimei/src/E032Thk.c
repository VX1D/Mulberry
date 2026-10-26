#include "common.h"

/* CheckE032UseSpirit @ 0x1A63C0 .. 0x1A6400 (0x40 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A63D0
 *   cfg: kept branch: 0x1a63e8 if (..) goto .L001A63D0
 */

extern u8 MdlMng[];

extern u32 CheckEneAttackEnable(void *,void *);
extern u32 EneSearchAttackRange(void *,void *,u32);
extern u32 ChangeAnimParam(void *,int,float);


/* E032ThkWalk @ 0x1A64F0 .. 0x1A653C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE032AttackState(void *, void *);
extern unsigned int CheckEneWalkState(void *, void *);

/* E032ThkStay @ 0x1A6540 .. 0x1A658C (0x4c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static unsigned int CheckE032AttackState(void *, void *);
extern unsigned int CheckEneStayState(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E032ThkInit(s32 a0 , u32 *a1 );
static void E032ThkStay(void *a0 , void *a1 );
static void E032ThkWalk(void *a0 , void *a1 );
static u32 CheckE032AttackState(void *object,void *enemy);
u32 CheckE032UseSpirit(void);


/* E032ThkInit @ 0x1A6590 .. 0x1A65AC (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E032ThkInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E032ThkStay;
    *(u32 *)a1 = (u32)E032ThkStay;
    v1 = (u8 *)E032ThkWalk;
    *(u32 *)(((u8 *)a1 + 4)) = (u32)E032ThkWalk;
    return;
}

static void E032ThkStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE032AttackState(a0, a1);
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

static void E032ThkWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s1;
    u16 *s0;
    u32 v0;
    u32 v1;

    s1 = (u32)a0;
    s0 = (u16 *)a1;
    v0 = CheckE032AttackState(a0, a1);
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

static u32 CheckE032AttackState(void *object,void *enemy) {
    u8 *model = object;
    u8 *controller = enemy;
    int attack;
    int result;
    if (!CheckEneAttackEnable(model,controller)) result = 0;
    else {
        for (attack=0;attack<5;attack++) {
            if (EneSearchAttackRange(model,controller,attack)) {
                u8 *freeModel;
                if (attack != 1) goto accept;
                {
                    u8 *cursor = MdlMng + 0x12280;
                    int index = 0;
                    do {
                        if (*cursor == 0) {
                            freeModel = cursor;
                            goto foundModel;
                        }
                        ++index;
                        cursor += 448;
                    } while (index < 1);
                    freeModel = 0;
foundModel:;
                }
                if (freeModel) {
accept:
                    ChangeAnimParam(model,(u16)(attack+50),0.0f);
                    model[0x12a] = attack;
                    controller[0x180] = 2;
                    result = 1;
                    goto end;
                }
            }
        }
        result = 0;
    }
end:
    return result;
}

u32 CheckE032UseSpirit(void) {
    s32 a0;
    u32 v0;
    u32 v1;

    a0 = 0;
    v0 = (u32)((u8 *)MdlMng + 0x12280);
    _L001A63D0:;
    v1 = *(u8 *)v0;
    if (v1 == 0) {
        return v0;
    }
    a0 = a0 + 1;
    v0 = v0 + 0x1c0;
    if (a0 <= 0) {
        goto _L001A63D0;
    }
    v0 = 0;
    return v0;
}
