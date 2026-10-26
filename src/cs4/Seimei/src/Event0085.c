#include "common.h"

/* PlayS0085Event000 @ 0x215890 .. 0x215A1C (0x18c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x21590c
 *   fpu: float literal 0x00000000 at 0x215940
 *   fpu: float literal 0x00000000 at 0x215988
 *   fpu: float literal 0x00000000 at 0x2159a4
 *   fpu: float literal 0x00000000 at 0x2159f4
 *   cfg: kept branch: 0x2158e8 if (..) goto .L00215938
 */

extern signed int CheckMyControlOff(void *);
extern u32 GetCurCamID();
extern void SetMyActFreeFlag(unsigned char);
extern void SetMyControlOff();
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetMyControlOn();
extern void SetEventFlag(signed int);
extern u32 MdlMng[];

/* InitS0085Event000 @ 0x215A20 .. 0x215AB8 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x215a84
 *   cfg: kept branch: 0x215a48 if (..) goto .L00215AA0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int CheckEventFlag(signed int);
extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u8 GameSt[];
extern u32 MdlMng[];

/* SetEventFuncS0085 @ 0x215AC0 .. 0x215AE4 (0x24 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0085(void);
static void InitS0085Event000(void *a0 );
static void PlayS0085Event000(void *a0 );



void SetEventFuncS0085(void) {
    u8 *v1;

    v1 = (u8 *)InitS0085Event000;
    *(u32 *)EventMngSt = (u32)InitS0085Event000;
    v1 = (u8 *)PlayS0085Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0085Event000;
    return;
}

static void InitS0085Event000(void *a0 /* r4 */) {
    s32 v1;
    u32 *s0;
    u32 v0;
    s32 a1;

    v1 = 2;
    s0 = (u32 *)a0;
    a0 = (void *)*(u8 *)((u8 *)&GameSt + 0x14);
    if ((u32)a0 == (u32)v1) {
        a0 = (void *)(s32)0x6d8;
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)1;
        if (v0 != 0) {
            goto _L00215AA0;
        }
        *(u32 *)(((u8 *)s0 + 0xc)) = 0;
        a1 = (s32)a0;
        *(u32 *)(((u8 *)s0 + 0x10)) = 0;
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a0 = (void *)(s32)(v0 + 0x30);
        v1 = (u32)a0 << 3;
        v1 = (s32)((u8 *)v1 - (u32)(a0));
        v0 = (u32)MdlMng;
        v1 = (u32)v1 << 6;
        v0 = (s32)((u8 *)MdlMng + v1);
        *(u32 *)(((u8 *)s0 + 0x34)) = v0;
        a0 = (void *)*(s32 *)(((u8 *)s0 + 0x34));
        a1 = 0x1e;
        ChangeAnimParam(a0, a1, (float)({ float native_result_0; __asm__("mtc1 %1,%0" :
            "=f"(native_result_0) : "r"((u32)0)); native_result_0; }));
    } else {
        _L00215AA0:;
        v1 = 3;
        *(u32 *)(((u8 *)s0 + 0xc)) = v1;
    }
    return;
}

static void PlayS0085Event000(void *a0 /* r4 */) {
    u8 *s1;
    u32 a1;
    u8 *s0;
    u32 v1;
    float f12;
    u32 v0;

    v1 = 2;
    s1 = (u8 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0xc));
    s0 = (u8 *)(MdlMng + 0x4600);
    switch ((u32)(s32)a0) {
    case 0:
        a0 = (void *)s0;
        v0 = CheckMyControlOff(a0);
        if (v0 != 0) {
            v0 = GetCurCamID();
            v1 = 2;
            a0 = (void *)(s32)1;
            if (v0 != v1) {
                goto _L00215938;
            }
            SetMyActFreeFlag((unsigned char)a0);
            SetMyControlOff();
            f12 = 0.0f;
            a0 = (void *)s0;
            a1 = 5;
            ChangeAnimParam(a0, a1, 0.0f);
            a0 = (void *)(s32)1;
            v1 = -0x3cc80000;
            *(u32 *)(s1 + 0xc) = (s32)a0;
            *(u32 *)(s0 + 0x20) = -0x3cc80000;
            *(u8 *)(s0 + 0x132) = (s32)a0;
            break;
        } else {
            _L00215938:;
            v0 = 3;
            *(u32 *)(s1 + 0xc) = v0;
            f12 = 0.0f;
            a0 = (void *)*(s32 *)(s1 + 0x34);
            ChangeAnimParam(a0, 0, 0.0f);
            break;
        }
    case 1:
        v0 = -0x457ced91;
        *(u32 *)(s0 + 0x24) = -0x457ced91;
        a0 = (void *)*(s32 *)(s0 + 0x100);
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        v1 = *(s32 *)(s1 + 0x10);
        v1 = v1 + 1;
        *(u32 *)(s1 + 0x10) = v1;
        if ((s32)v1 <= (s32)1) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s0;
        *(u8 *)(s0 + 0x132) = 0;
        ChangeAnimParam(a0, 0, 0.0f);
        v0 = 2;
        *(u32 *)(s1 + 0xc) = v0;
        f12 = 0.0f;
        *(u32 *)(s1 + 0x10) = 0;
        a0 = (void *)*(s32 *)(s1 + 0x34);
        a1 = 0x20;
        ChangeAnimParam(a0, a1, 0.0f);
        break;
    case 2:
        v0 = *(s32 *)(s1 + 0x34);
        a0 = (void *)*(s32 *)((v0 + 0x100));
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)0;
        if (v0 == 0) {
            break;
        }
        SetMyActFreeFlag(0);
        SetMyControlOn();
        a0 = (void *)(s32)0x6d8;
        SetEventFlag((signed int)a0);
        v0 = 3;
        *(u32 *)(s1 + 0xc) = v0;
        f12 = 0.0f;
        a0 = (void *)*(s32 *)(s1 + 0x34);
        ChangeAnimParam(a0, 0, 0.0f);
    }
    return;
}
