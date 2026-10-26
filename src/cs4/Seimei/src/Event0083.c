#include "common.h"

extern signed int CheckEventFlag(signed int);
extern void SetBloodPoolScale(float);
extern void SetMyPullIn(void *);
extern void SetBloodDripScroll(signed int, signed int);
extern u32 MdlMng[];


/* InitS0083Event000 @ 0x213A50 .. 0x213A5C (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j SetBloodDripScroll at 0x213a54 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void SetBloodDripScroll(signed int, signed int);

/* SetEventFuncS0083 @ 0x213A60 .. 0x213A84 (0x24 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

extern void PlayS0083Event000(void *);
extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0083(void);
static void InitS0083Event000(void);
static void PlayS0083Event000(void *event);


void SetEventFuncS0083(void) {
    u8 *v1;

    v1 = (u8 *)InitS0083Event000;
    *(u32 **)EventMngSt = (u32 *)InitS0083Event000;
    v1 = (u8 *)PlayS0083Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0083Event000;
    return;
}

static void InitS0083Event000(void) {
    SetBloodDripScroll(0, 5);
    return;
}
static void PlayS0083Event000(void *event)
{
    u8 *state;
    u8 *model;
    u8 *ctrl;
    float x, radius, z, sx, sz;
    state = event;
    model = (u8 *)(MdlMng + 0x4600);
    ctrl = (u8 *)*(s32 *)(model + 0x148);
    if (CheckEventFlag(0x556)) {
        if (*(s32 *)(state + 0x10) == 0) {
            if (*(s32 *)(state + 0xc) < 14400) (*(s32 *)(state + 0xc))++;
            radius = (float)*(s32 *)(state + 0xc) / 14400.0f;
            SetBloodPoolScale(radius);
            if (!(radius <= 0.1f)) {
                x = *(float *)(model + 0x20) - -245.0f;
                z = *(float *)(model + 0x28) - -223.5f;
                radius *= 0.9f;
                if (!(radius <= 0.5f)) radius = 0.5f;
                sx = x * x;
                sz = z * z;
                if (sx / 25.0f + sz / 9.0f < radius * radius &&
                    *(u16 *)(ctrl + 0x1cc) == 0 && *(u8 *)(ctrl + 0x189) == 0) {
                    SetMyPullIn(model);
                    *(s32 *)(state + 0x10) = 1;
                }
            }
        } else {
            u8 animation = *(u8 *)(ctrl + 0x100);
            if (animation != 13) *(s32 *)(state + 0x10) = 0;
        }
        if (*(s32 *)(state + 0x14) == 0) {
            SetBloodDripScroll(1, 5);
            *(s32 *)(state + 0x14) = 1;
        }
    }
}
