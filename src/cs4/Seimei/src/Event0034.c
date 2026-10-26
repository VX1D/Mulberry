#include "common.h"

extern unsigned int CheckMyDash(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void SetEventFlag(signed int);
extern float Math_GetDist2(float *, float *);
extern void SetAnimFrame(void *, float);
extern unsigned int CheckAnimEndFrame(void *);
extern signed int CheckEneDead(void *);
extern u8 GameSt[];
extern u32 MdlMng[];


/* InitS0034Event000 @ 0x210550 .. 0x21070C (0x1bc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x21065c
 *   fpu: float literal 0x00000000 at 0x210674
 *   v0#10 is the pointer held in a0+0x38
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int GetMdlMngIndexByCtrlId(signed int, signed int);
extern void FreeMdlMng(void *);
extern signed int CheckEventFlag(signed int);
extern void EasyEneAppear(signed int);
extern signed int CheckEneDead(void *);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern signed int CheckEneFlick(void *);
extern u8 GameSt[];
extern u32 MdlMng[];

/* SetEventFuncS0034 @ 0x210710 .. 0x210734 (0x24 bytes) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return void vs inferred u8 *
 */


extern u32 EventMngSt[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetEventFuncS0034(void);
static void InitS0034Event000(void *a0 );
static void PlayS0034Event000(void *arg);



void SetEventFuncS0034(void) {
    u8 *v1;

    v1 = (u8 *)InitS0034Event000;
    *(u32 *)EventMngSt = (u32)InitS0034Event000;
    v1 = (u8 *)PlayS0034Event000;
    *(u32 *)((u8 *)&EventMngSt + 4) = (u32)PlayS0034Event000;
    return;
}

static void InitS0034Event000(void *a0 /* r4 */) {
    u8 *s0;
    u32 v1;
    u32 a1;
    u32 v0;
    u32 a2;
    u8 *s1;
    float f12;

    v1 = GameSt[0x14];
    s0 = (u8 *)a0;
    a0 = (void *)(s32)1;
    a1 = 0xa;
    if (v1 == (u32)(s32)a0) {
        v0 = GetMdlMngIndexByCtrlId((signed int)a0, a1);
        a0 = (void *)(s32)(v0 + 0x30);
        v0 = (u32)MdlMng;
        FreeMdlMng((void *)(u32)(s32)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)(u32)((u32)a0 << 3) -
            (u32)(a0)) << 6)));
        v0 = GetMdlMngIndexByCtrlId(1, 2);
        a1 = v0 + 0x30;
        a0 = (void *)(s32)0x555;
        v0 = (u32)MdlMng;
        *(u32 *)(s0 + 0x34) = (s32)((u8 *)MdlMng + (u32)((u32)(a1) * (u32)(0x1c0)));
        v0 = CheckEventFlag((signed int)a0);
        a0 = (void *)(s32)4;
        if (v0 == 0) {
            EasyEneAppear((signed int)a0);
            v0 = GetMdlMngIndexByCtrlId(2, 4);
            a0 = (void *)(s32)(v0 + 0xa1);
            v1 = (u32)a0 << 3;
            v0 = (u32)MdlMng;
            *(u32 *)(s0 + 0x38) = (s32)((u8 *)MdlMng + (u32)((u32)(s32)((u8 *)v1 - (u32)(a0)) <<
                6));
        }
        v0 = CheckEventFlag(0x554);
        if (v0 == 0) {
            a0 = (void *)*(s32 *)(s0 + 0x38);
            if ((u32)(s32)a0 != 0) {
                v0 = CheckEneDead(a0);
                if (v0 == 0) {
                    a0 = (void *)*(s32 *)(s0 + 0x38);
                    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
                    ((void (*)(s32, s32, s32))(s32)*(s32 *)(s1 + 0x118))((s32)a0, (s32)s1, 0x52);
                    *(u8 *)(s1 + 0x249) = 1;
                    f12 = 0.0f;
                    a0 = (void *)*(s32 *)(s0 + 0x38);
                    ChangeAnimParam(a0, 0x52, 0.0f);
                }
            }
            f12 = 0.0f;
            ChangeAnimParam((void *)*(s32 *)(s0 + 0x34), 0x1e, 0.0f);
            *(u32 *)(s0 + 0x10) = 1;
        } else {
            a0 = (void *)*(s32 *)(s0 + 0x38);
            if ((u32)(s32)a0 != 0) {
                v0 = CheckEneDead(a0);
                if (v0 == 0) {
                    a0 = (void *)*(s32 *)(s0 + 0x38);
                    v0 = CheckEneFlick(a0);
                    if (v0 == 0) {
                        a2 = *(s32 *)(s0 + 0x38);
                        v1 = 0x42020000;
                        v1 = -0x3e170000;
                        v1 = 0x3e8e0000;
                        a0 = (void *)(0x3e8e0000 | 0xe94);
                        *(u32 *)((a2 + 0x20)) = 0x42020000 | 0x6666;
                        v1 = *(s32 *)(s0 + 0x38);
                        *(u32 *)((v1 + 0x24)) = 0;
                        v1 = *(s32 *)(s0 + 0x38);
                        *(u32 *)((v1 + 0x28)) = -0x3e170000 | 0x999a;
                        v1 = *(s32 *)(s0 + 0x38);
                        *(u32 *)((v1 + 0x34)) = (u32)a0;
                    }
                }
            }
        }
    }
    return;
}
static void PlayS0034Event000(void *arg) {
    u8 *ctrl=(u8 *)arg;
    u8 *enemy;
    float distance;
    if(GameSt[0x14]==1) {
        switch(*(u32 *)(ctrl+0x10)) {
        case 1:
            enemy=*(u8 **)(*(u8 **)(ctrl+0x38)+0x148);
            if(CheckMyDash(MdlMng+0x4600)!=0) distance=9.0f;
            else distance=4.0f;
            if(enemy[0x180]==3) {
                ChangeAnimParam(*(void **)(ctrl+0x34),0,0.0f);
                *(u32 *)(ctrl+0x10)=3;
                SetEventFlag(0x554);
                break;
            } else if(enemy[0x180]==4) {
                ChangeAnimParam(*(void **)(ctrl+0x34),0,0.0f);
                *(u32 *)(ctrl+0x10)=0;
                SetEventFlag(0x554);
                break;
            } else if(Math_GetDist2((float *)(*(u8 **)(ctrl+0x34)+0x20),(float *)(MdlMng+0x4608))<distance) {
                ChangeAnimParam(*(void **)(ctrl+0x34),0,0.0f);
                ChangeAnimParam(*(void **)(ctrl+0x38),0x53,0.0f);
                *(u32 *)(ctrl+0x10)=2;
                SetEventFlag(0x554);
                break;
            } else {
                u32 previous;
                u8 *model=*(u8 **)(ctrl+0x34);
                previous=*(u32 *)(ctrl+0x14);
                if(previous!=model[3] && previous) SetAnimFrame(*(void **)(model+0x100),**(float **)(*(u8 **)(ctrl+0x38)+0x100));
                *(u32 *)(ctrl+0x14)=(*(u8 **)(ctrl+0x34))[3];
                break;
            }
        case 2:
            if(CheckAnimEndFrame(*(void **)(*(u8 **)(ctrl+0x38)+0x100))==0) break;
            (*(u8 **)(*(u8 **)(ctrl+0x38)+0x148))[0x182]=1;
            *(u32 *)(ctrl+0x10)=0;
            break;
        case 3:
            {
                u8 *model=*(u8 **)(ctrl+0x38);
                enemy=*(u8 **)(model+0x148);
                if(enemy[0x180]==3) break;
                (*(void (**)(u8 *,u8 *,s32))(enemy+0x118))(model,enemy,0x53);
                enemy[0x249]=0;
                ChangeAnimParam(*(void **)(ctrl+0x38),0x53,0.0f);
                *(u32 *)(ctrl+0x10)=2;
            }
        }
        if(*(u32 *)(ctrl+0x38)!=0 && CheckEneDead(*(void **)(ctrl+0x38))!=0) SetEventFlag(0x555);
    }
}
