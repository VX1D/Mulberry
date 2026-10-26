#include "common.h"

/* InitS0009Event000 @ 0x212A00 .. 0x212AA0 (0xa0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x212a74
 *   cfg: kept branch: 0x212a4c if (..) goto .L00212A70
 *   cfg: kept goto: 0x212a60 -> .L00212A90
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern signed int CheckEventFlag(signed int);
extern void SetEventFlag(signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u32 MdlMng[];
extern u8 GameSt[];

/* SetEventFuncS0009 @ 0x212AA0 .. 0x212AB4 (0x14 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */

extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0009(void);
static void InitS0009Event000(void *a0 );



void SetEventFuncS0009(void) {
    *(u32 *)EventMngSt = (u32)InitS0009Event000;
    return;
}

static void InitS0009Event000(void *a0 /* r4 */) {
    u8 *s0;
    s32 a1;
    u32 v1;
    u32 v0;

    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    a1 = (s32)a0;
    v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
    a0 = (void *)(s32)(v0 << 3);
    a0 = (void *)((u8 *)a0 - v0);
    a0 = (void *)(s32)((u32)a0 << 6);
    v1 = (s32)((u8 *)(u8 *)(MdlMng + 0x1500) + (u32)(a0));
    v0 = 1;
    *(u32 *)(s0 + 0x34) = v1;
    v1 = GameSt[0x14];
    a0 = (void *)(s32)0x54a;
    if (v1 == v0) {
        v0 = CheckEventFlag((signed int)a0);
        if (v0 == 0) {
            goto _L00212A70;
        }
    }
    a0 = (void *)(s32)0x54a;
    SetEventFlag((signed int)a0);
    goto _L00212A90;
    _L00212A70:;
    a0 = (void *)*(s32 *)(s0 + 0x34);
    a1 = 3;
    ChangeAnimParam(a0, a1, 0.0f);
    v1 = *(s32 *)(s0 + 0x34);
    a0 = (void *)(s32)1;
    *(u8 *)((v1 + 0x130)) = (s32)a0;
    _L00212A90:;
    return;
}
