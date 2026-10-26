#include "common.h"




extern u8 GameSt[];
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void ClearMyStruggleStick();
extern void FECard_SetFade(unsigned char, signed int);
extern void SetHokanFrame(void *, float);
extern void sceVu0CopyVector(void *, void *);
extern void ReCalcMi3Matrix(void *);
extern void UpdateWorldMatrixInAnim(void *);
extern signed int CsMngStabilize(unsigned int, unsigned int);
extern signed int CheckMyTired(void *);
extern unsigned int CheckAnimEndFrame(void *);
extern u32 CheckFadeEnd(void);
extern void SetGameOver(void);
extern float Math_GotoAngle(float, float, float);
extern unsigned int Math_GotoVectorXZ(float *, float *, float);
extern unsigned int CheckAnimNumFrame(void *, float);
extern void SfxPostEffect_SetEnable(unsigned short, signed int);
extern void SetLightDizzy(signed int);
extern signed int UpdateMovePathTotter(void *);
extern void SetMyNormalMode(void);
extern void SetMyControlOff(void);
extern void SetGoToEndingFade(void);
extern float Math_GetAngleDist(float, float);
extern float Math_GetDistXZ(float *, float *);
static void SetMyAttackAction(void *, void *, signed int);
extern void ChangeMyWeapon(void *, void *);
extern unsigned short GetMyAttackAnim(void *, void *, signed int);
extern unsigned int CheckAnimParam(void *, signed int);
extern void SetHeartRate(void *, signed int, unsigned char);
static float GetMyJumpCorrectFrame(void *a0 /* r4 */);
void SetMyPullIn(void *a0 /* r4 */);
void SetMyCrouch(void *a0 /* r4 */);
void SetMyBlast(void *a0 /* r4 */, unsigned short a1 /* r5 */);
void SetMyDoor(void *a0 /* r4 */, void *a1 /* r5 */, float f12 /* f12 */, unsigned short a2 /* r6
        */, unsigned char a3 /* r7 */);
void SetMyStay(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */);
static void MyActPullIn(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActFall(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActTotter(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActJump(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActBlast(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActDead(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActAttack4Seimei(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActAttack4Utsuki(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActBack(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActStay(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActNone(void);
void MyActPlay(void *a0 /* r4 */, void *a1 /* r5 */);

/* MyActInit @ 0x156D60 .. 0x156EA0 (0x140 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x156e4c writes a register its branch at 0x156e48 reads
 *   a0 takes slot 0 only because of the ABI order
 */

extern void MyActWalk(void *, void *);
extern void MyActDamage(void *, void *);
static void MyActDoor(void *a0 /* r4 */, void *a1 /* r5 */);
extern void MyActConcentrate(void *, void *);
static void MyActCrouch(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyActAttack4Sakuya(void *a0 /* r4 */, void *a1 /* r5 */);

typedef struct {
    u8 pad[0x80];
    void *ActFunc[32];
} MY_CTRL;

void MyActInit(int a0, MY_CTRL *lpCtrl) {
    unsigned int i;

    for (i = 0; i < 32; i++) {
        lpCtrl->ActFunc[i] = MyActNone;
    }
    lpCtrl->ActFunc[0] = MyActStay;
    lpCtrl->ActFunc[1] = MyActWalk;
    lpCtrl->ActFunc[2] = MyActBack;
    lpCtrl->ActFunc[4] = MyActDamage;
    lpCtrl->ActFunc[5] = MyActDead;
    lpCtrl->ActFunc[6] = MyActDoor;
    lpCtrl->ActFunc[7] = MyActConcentrate;
    lpCtrl->ActFunc[8] = MyActBlast;
    lpCtrl->ActFunc[9] = MyActCrouch;
    lpCtrl->ActFunc[10] = MyActJump;
    lpCtrl->ActFunc[11] = MyActTotter;
    lpCtrl->ActFunc[12] = MyActFall;
    lpCtrl->ActFunc[13] = MyActPullIn;
    switch (GameSt[0x14]) {
    case 0:
        lpCtrl->ActFunc[3] = MyActAttack4Utsuki;
        break;
    case 1:
        lpCtrl->ActFunc[3] = MyActAttack4Sakuya;
        break;
    case 2:
        lpCtrl->ActFunc[3] = MyActAttack4Seimei;
        break;
    }
}


/* MyActPlay @ 0x156D40 .. 0x156D58 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: jr v0 at 0x156d50 tail-calls through a pointer
 *   a0 takes slot 0 only because of the ABI order
 */




void MyActPlay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = *(u8 *)(((u8 *)a1 + 0x100));
    v0 = v0 << 2;
    v0 = (s32)((u8 *)v0 + (u32)(a1));
    v0 = *(s32 *)((v0 + 0x80));
    ((void (*)(void *, void *))(s32)v0)(a0, a1);
    return;
}


/* MyActNone @ 0x156D30 .. 0x156D38 (0x8 bytes) */



static void MyActNone(void) {
    return;
}








/* MyActStay @ 0x1569A0 .. 0x156D2C (0x38c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1569d0 writes a register its branch at 0x1569cc reads
 *   delay: addiu at 0x1569e4 writes a register its branch at 0x1569e0 reads
 *   delay: addiu at 0x1569f8 writes a register its branch at 0x1569f4 reads
 *   delay: addiu at 0x156a2c writes a register its branch at 0x156a28 reads
 *   fpu: float literal 0x00000000 at 0x156a58
 *   fpu: float literal 0x00000000 at 0x156aa4
 *   fpu: float literal 0x00000000 at 0x156ad8
 *   fpu: float literal 0x00000000 at 0x156b00
 *   fpu: float literal 0x00000000 at 0x156b4c
 *   fpu: float literal 0x00000000 at 0x156b80
 *   fpu: float literal 0x00000000 at 0x156bb8
 *   fpu: float literal 0x00000000 at 0x156bf0
 *   fpu: float literal 0x00000000 at 0x156c28
 *   fpu: float literal 0x00000000 at 0x156c50
 *   fpu: float literal 0x00000000 at 0x156c90
 *   fpu: float literal 0x00000000 at 0x156cc8
 *   fpu: float literal 0x00000000 at 0x156cf8
 *   cfg: kept branch: 0x156a88 if (..) goto .L00156AC0
 *   cfg: kept branch: 0x156b30 if (..) goto .L00156B68
 */


static void MyActStay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    void *a0_s1; // a0
    s32 v1;
    float f12;
    u32 v0;
    u8 *s0;

    a0_bytes = (u8 *)a0;
    v0 = 0x88;
    v1 = *(s16 *)(a0_bytes + 0x104);
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    s0 = (u8 *)a1;
    a1 = (void *)(s32)2;
    switch ((u32)v1) {
    case 5:
        a0_s1 = (void *)a0_bytes;
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 10:
        v0 = *(s32 *)(s0 + 0x1a0);
        a0_s1 = (void *)a0_bytes;
        if ((s32)v0 > (s32)0x14) {
            v0 = CheckAnimParam(a0_s1, (signed int)a1);
            if (v0 == 0) {
                goto _L00156AC0;
            }
            v0 = 1;
            a0_s1 = (void *)a0_bytes;
            *(u8 *)(s0 + 0x1b0) = v0;
            f12 = 0.0f;
            a1 = (void *)(s32)2;
            *(u8 *)(s0 + 0x100) = 0;
            ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
            v0 = 1;
        } else {
            _L00156AC0:;
            v0 = 0;
        }
        a0_s1 = (void *)a0_bytes;
        if (v0 != 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 6:
        a0_s1 = (void *)a0_bytes;
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 11:
        v0 = *(s32 *)(s0 + 0x1a0);
        a0_s1 = (void *)a0_bytes;
        if ((s32)v0 > (s32)0x14) {
            v0 = CheckAnimParam(a0_s1, (signed int)a1);
            if (v0 == 0) {
                goto _L00156B68;
            }
            v0 = 1;
            a0_s1 = (void *)a0_bytes;
            *(u8 *)(s0 + 0x1b0) = v0;
            f12 = 0.0f;
            a1 = (void *)(s32)2;
            *(u8 *)(s0 + 0x100) = 0;
            ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
            v0 = 1;
        } else {
            _L00156B68:;
            v0 = 0;
        }
        a0_s1 = (void *)a0_bytes;
        if (v0 != 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 0:
        a0_s1 = (void *)a0_bytes;
        v0 = CheckMyTired(a0_s1);
        a0_s1 = (void *)a0_bytes;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 1:
        a0_s1 = (void *)a0_bytes;
        v0 = CheckMyTired(a0_s1);
        a0_s1 = (void *)a0_bytes;
        if (v0 != 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 2:
        v0 = CheckAnimEndFrame(a0_s1);
        a0_s1 = (void *)a0_bytes;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 61:
    case 60:
        a0_s1 = (void *)a0_bytes;
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = (void *)a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 130:
        *(u32 *)(a0_bytes + 0x154) = 0;
        break;
    case 131:
        v0 = 1;
        *(u32 *)(a0_bytes + 0x154) = v0;
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        v0 = *(s16 *)(a0_bytes + 0x104);
        f12 = 0.0f;
        a0_s1 = (void *)a0_bytes;
        v0 = v0 + 1;
        a1 = (void *)(u16)v0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 134:
        v0 = 2;
        *(u32 *)(a0_bytes + 0x154) = v0;
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        v0 = *(s16 *)(a0_bytes + 0x104);
        f12 = 0.0f;
        a0_s1 = (void *)a0_bytes;
        v0 = v0 + 1;
        a1 = (void *)(u16)v0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 133:
    case 136:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_s1 = (void *)a0_bytes;
        a1 = (void *)(s32)0x82;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
    }
    SetHeartRate((void *)a0_bytes, 1, 2);
    return;
}


void MyActWalk(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 a2;
    u8 *s0;
    float f13;
    s32 a0_scalar; // a0
    s32 v1;
    u32 v0_2; // v0
    float f12;
    float f2;
    float f0;
    float f1;
    u32 v0;

    s1 = (u8 *)a1;
    a1 = (void *)*(u8 *)(((u8 *)a1 + 0x1b2));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s2 = (u8 *)a0;
    switch ((u32)a1) {
    case 1:
        v1 = *(s16 *)(s2 + 0x104);
        a1 = (void *)(s32)0x3d;
        if ((u32)v1 == (u32)(s32)a1) {
            break;
        }
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 2:
        v1 = *(s16 *)(s2 + 0x104);
        a1 = (void *)(s32)0x3c;
        if ((u32)v1 == (u32)(s32)a1) {
            break;
        }
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 0:
        a0_scalar = *(s16 *)(s2 + 0x104);
        v1 = 0x3d;
        if ((u32)a0_scalar != (u32)v1) {
            v1 = 0x3c;
            if ((u32)a0_scalar != (u32)v1) {
                break;
            }
        }
        a0 = (void *)s2;
        v0_2 = CheckMyTired(a0);
        a1 = (void *)(s32)(v0_2 != 0);
        a0 = (void *)s2;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
    }
    a2 = *(s16 *)(s2 + 0x104);
    v1 = 0x3c;
    a0 = (void *)(s32)0xb;
    a1 = (void *)(s32)0xa;
    switch ((u32)a2) {
    case 0:
    case 1:
        v0 = *(u8 *)(s1 + 0x188);
        if (v0 != 0) {
            v0 = a2 + 0xa;
            a0 = (void *)s2;
            a1 = (void *)(u16)v0;
            v0 = 1;
            *(u8 *)(s1 + 0x100) = v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        } else {
            v0 = a2 + 5;
            a1 = (void *)(u16)v0;
            a0 = (void *)s2;
            v0 = 1;
            *(u8 *)(s1 + 0x100) = v0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        }
    case 5:
        v0 = *(u8 *)(s1 + 0x188);
        if (v0 != 0) {
            f2 = 0.8f * *(float *)s0;
            f0 = *(float *)(s0 + 0x10);
            v1 = (s32)(8.0f + f2);
            v0 = (s32)f0;
            *(u8 *)(s1 + 0x100) = 1;
            ChangeAnimParam(s2, (s32)a1, (float)(v1 % (s32)v0));
        } else {
            a0 = (void *)s2;
            v0 = CheckMyTired(a0);
            if (v0 != 0) {
                f12 = *(float *)s0;
                v0 = 1;
                a0 = (void *)s2;
                a1 = (void *)(s32)6;
                *(u8 *)(s1 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1, f12);
            }
        }
        a0 = (void *)s2;
        a1 = (void *)(s32)1;
        a2 = 2;
        SetHeartRate(a0, (signed int)a1, a2);
        f12 = *(float *)(s2 + 0x34);
        f13 = *(float *)(s1 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.0698f);
        *(f32 *)(s2 + 0x34) = f0;
        break;
    case 6:
        v0 = *(u8 *)(s1 + 0x188);
        if (v0 != 0) {
            f2 = 0.8f * *(float *)s0;
            f0 = *(float *)(s0 + 0x10);
            v1 = (s32)(8.0f + f2);
            v0 = (s32)f0;
            *(u8 *)(s1 + 0x100) = 1;
            ChangeAnimParam(s2, (s32)a0, (float)(v1 % (s32)v0));
        } else {
            a0 = (void *)s2;
            v0 = CheckMyTired(a0);
            if (v0 == 0) {
                f12 = *(float *)s0;
                v0 = 1;
                a0 = (void *)s2;
                a1 = (void *)(s32)5;
                *(u8 *)(s1 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1, f12);
            }
        }
        a0 = (void *)s2;
        a1 = (void *)(s32)1;
        a2 = 2;
        SetHeartRate(a0, (signed int)a1, a2);
        f12 = *(float *)(s2 + 0x34);
        f13 = *(float *)(s1 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.0698f);
        *(f32 *)(s2 + 0x34) = f0;
        break;
    case 10:
        v0 = *(u8 *)(s1 + 0x188);
        if (v0 == 0) {
            v0 = *(s32 *)(s1 + 0x1a0);
            a0 = (void *)s2;
            if ((s32)v0 > (s32)0x14) {
                a1 = (void *)(s32)2;
                v0 = CheckAnimParam(a0, (signed int)a1);
                if (v0 == 0) {
                    goto _L00156770;
                }
                v0 = 1;
                a0 = (void *)s2;
                *(u8 *)(s1 + 0x1b0) = v0;
                a1 = (void *)(s32)2;
                *(u8 *)(s1 + 0x100) = 0;
                ChangeAnimParam(a0, (signed int)a1, 0.0f);
                v0 = 1;
            } else {
                _L00156770:;
                v0 = 0;
            }
            if (v0 == 0) {
                f2 = 1.25f * *(float *)s0;
                f0 = *(float *)(s0 + 0x10);
                v1 = (s32)(12.5f + f2);
                v0 = (s32)f0;
                *(u8 *)(s1 + 0x100) = 1;
                ChangeAnimParam(s2, 5, (float)(v1 % (s32)v0));
            }
        } else {
            a0 = (void *)s2;
            v0 = CheckMyTired(a0);
            if (v0 != 0) {
                f12 = *(float *)s0;
                v0 = 1;
                a0 = (void *)s2;
                a1 = (void *)(s32)0xb;
                *(u8 *)(s1 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1, f12);
            }
        }
        a1 = (void *)(s32)1;
        a0 = (void *)s2;
        SetHeartRate(a0, (signed int)a1, (s32)a1);
        f12 = *(float *)(s2 + 0x34);
        f13 = *(float *)(s1 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.040134996f);
        *(f32 *)(s2 + 0x34) = f0;
        break;
    case 11:
        v0 = *(u8 *)(s1 + 0x188);
        if (v0 == 0) {
            v0 = *(s32 *)(s1 + 0x1a0);
            a0 = (void *)s2;
            if ((s32)v0 > (s32)0x14) {
                a1 = (void *)(s32)2;
                v0 = CheckAnimParam(a0, (signed int)a1);
                if (v0 == 0) {
                    goto _L00156890;
                }
                v0 = 1;
                a0 = (void *)s2;
                *(u8 *)(s1 + 0x1b0) = v0;
                a1 = (void *)(s32)2;
                *(u8 *)(s1 + 0x100) = 0;
                ChangeAnimParam(a0, (signed int)a1, 0.0f);
                v0 = 1;
            } else {
                _L00156890:;
                v0 = 0;
            }
            if (v0 == 0) {
                f2 = 1.25f * *(float *)s0;
                f0 = *(float *)(s0 + 0x10);
                v1 = (s32)(12.5f + f2);
                v0 = (s32)f0;
                *(u8 *)(s1 + 0x100) = 1;
                ChangeAnimParam(s2, 6, (float)(v1 % (s32)v0));
            }
        } else {
            a0 = (void *)s2;
            v0 = CheckMyTired(a0);
            if (v0 == 0) {
                f12 = *(float *)s0;
                v0 = 1;
                a0 = (void *)s2;
                a1 = (void *)(s32)0xa;
                *(u8 *)(s1 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1, f12);
            }
        }
        a1 = (void *)(s32)1;
        a0 = (void *)s2;
        SetHeartRate(a0, (signed int)a1, (s32)a1);
        f12 = *(float *)(s2 + 0x34);
        f13 = *(float *)(s1 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.040134996f);
        *(f32 *)(s2 + 0x34) = f0;
        break;
    case 61:
    case 60:
        f12 = *(float *)(s2 + 0x34);
        f13 = *(float *)(s1 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.0698f);
        *(f32 *)(s2 + 0x34) = f0;
    }
    return;
}


/* MyActBack @ 0x1562D0 .. 0x1563F4 (0x124 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x156320
 *   delay: addiu at 0x156354 writes a register its branch at 0x156350 reads
 *   fpu: float literal 0x00000000 at 0x156368
 *   fpu: float literal 0x3c23d70a at 0x156390
 *   fpu: float literal 0x3c23d70a at 0x1563b4
 *   fpu: float literal 0x00000000 at 0x1563d0
 */




static void MyActBack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    void *a0_s1; // a0
    s32 v1;
    float f12;
    float f2;
    float f1;
    float f0;
    s32 v0;
    void *a1_2;
    u8 *s0;

    a0_bytes = (u8 *)a0;
    v1 = *(s16 *)(a0_bytes + 0x104);
    s0 = (u8 *)a1;
    a1_2 = (void *)(s32)8;
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    switch ((u32)v1) {
    case 7:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_s1 = (void *)a0_bytes;
        a1_2 = (void *)(s32)8;
        ChangeAnimParam(a0_s1, (signed int)a1_2, 0.0f);
        break;
    case 8:
        v0 = CheckAnimEndFrame(a0_s1);
        if ((u32)v0 != 0) {
            v0 = 1;
            v1 = GameSt[0x16];
            if ((u32)v1 == (u32)v0) {
                v0 = 0x3c;
                *(u8 *)(s0 + 0x192) = v0;
            }
            a0_s1 = (void *)a0_bytes;
            v0 = CheckMyTired(a0_s1);
            f12 = 0.0f;
            a1_2 = (void *)(s32)((u32)v0 != 0);
            a0_s1 = (void *)a0_bytes;
            *(u8 *)(s0 + 0x100) = 0;
            ChangeAnimParam(a0_s1, (signed int)a1_2, 0.0f);
        }
        f12 = *(float *)(s0 + 0x180);
        f0 = sinf(f12);
        f2 = 0.00999999978f;
        f0 = (0.00999999978f * (float)f0);
        *(f32 *)(a0_bytes + 0x20) = (*(float *)(a0_bytes + 0x20) - f0);
        f12 = *(float *)(s0 + 0x180);
        f0 = cosf(f12);
        v1 = 0x3c23d70a;
        f2 = 0.00999999978f;
        f1 = *(float *)(a0_bytes + 0x28);
        f0 = (0.00999999978f * (float)f0);
        f0 = (f1 - f0);
        *(f32 *)(a0_bytes + 0x28) = f0;
        break;
    default:
        f12 = 0.0f;
        a0_s1 = (void *)a0_bytes;
        ChangeAnimParam(a0_s1, (signed int)a1_2, 0.0f);
    }
    return;
}








/* MyActAttack4Utsuki @ 0x155FA0 .. 0x1562D0 (0x330 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x155fd4 writes a register its branch at 0x155fd0 reads
 *   fpu: float literal 0x41e00000 at 0x155ffc
 *   fpu: float literal 0x00000000 at 0x156038
 *   fpu: float literal 0x41f00000 at 0x156058
 *   fpu: float literal 0x41f00000 at 0x156098
 *   fpu: float literal 0x42200000 at 0x1560ac
 *   delay: lui at 0x156178 writes a register its branch at 0x156174 reads
 *   fpu: float literal 0x42200000 at 0x15617c
 *   fpu: float literal 0x00000000 at 0x156190
 *   fpu: float literal 0x00000000 at 0x1561d0
 *   fpu: float literal 0x41f00000 at 0x1561f8
 *   fpu: float literal 0x00000000 at 0x156258
 *   fpu: float literal 0x00000000 at 0x1562a0
 *   cfg: kept branch: 0x156184 if (..) goto .L001561A8
 */


static void MyActAttack4Utsuki(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 v0;
    s32 v1;
    float *s0;
    float f12;
    u8 a2;
    float f1;
    float f0;
    s32 fpcc;
    float f13;
    float f14;

    v0 = 0x33;
    s2 = (u8 *)a0;
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    switch ((u32)v1) {
    case 40:
        f12 = 28.0f;
        a0 = (void *)s0;
        v0 = CheckAnimNumFrame(a0, 28.0f);
        a0 = (void *)s2;
        if (v0 != 0) {
            a1 = (void *)s1;
            ChangeMyWeapon(a0, a1);
        }
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        a2 = *(u8 *)(s1 + 0x1ae);
        a1 = (void *)s1;
        a0 = (void *)s2;
        v0 = GetMyAttackAnim(a0, a1, a2);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1 = (void *)(u16)v0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 50:
        v0 = 0x41f00000;
        f1 = *(float *)s0;
        f0 = 30.0f;
        fpcc = f1 <= 30.0f;
        if (fpcc && (u32)*(s32 *)(s2 + 0x1b4) != 0) {
            f13 = *(float *)(s2 + 0x198);
            f14 = *(float *)(s2 + 0x1a0);
            f12 = *(float *)(s2 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s2 + 0x34) = f0;
        }
        f1 = *(float *)s0;
        f0 = 30.0f;
        fpcc = 30.0f <= f1;
        v0 = 0x42200000;
        if (fpcc) {
            f0 = 40.0f;
            fpcc = f1 <= 40.0f;
            if (fpcc) {
                v1 = *(u8 *)(s1 + 0x1ae);
                v0 = 1;
                switch ((u32)v1) {
                case 255:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                    break;
                case 0:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                    break;
                case 1:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                }
            }
        }
        v0 = *(u8 *)(s1 + 0x18e);
        if (v0 != 0) {
            f12 = 40.0f;
            a0 = (void *)s0;
            v0 = CheckAnimNumFrame(a0, 40.0f);
            if (v0 == 0) {
                goto _L001561A8;
            }
            f12 = 0.0f;
            a0 = (void *)s2;
            a1 = (void *)(s32)0x33;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        } else {
            _L001561A8:;
            a2 = *(u8 *)(s1 + 0x1ae);
            a0 = (void *)s2;
            a1 = (void *)s1;
            SetMyAttackAction(a0, a1, a2);
            a0 = (void *)s0;
            v0 = CheckAnimEndFrame(a0);
            a0 = (void *)s2;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyTired(a0);
            f12 = 0.0f;
            a0 = (void *)s2;
            a1 = (void *)(s32)(v0 != 0);
            *(u8 *)(s1 + 0x100) = 0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        }
    case 53:
        v0 = 0x41f00000;
        f1 = *(float *)s0;
        f0 = 30.0f;
        fpcc = f1 <= 30.0f;
        if (fpcc && (u32)*(s32 *)(s2 + 0x1b4) != 0) {
            f13 = *(float *)(s2 + 0x198);
            f14 = *(float *)(s2 + 0x1a0);
            f12 = *(float *)(s2 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s2 + 0x34) = f0;
        }
        a2 = *(u8 *)(s1 + 0x1ae);
        a0 = (void *)s2;
        a1 = (void *)s1;
        SetMyAttackAction(a0, a1, a2);
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)s2;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1 = (void *)(s32)(v0 != 0);
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 51:
    default:
        a2 = *(u8 *)(s1 + 0x1ae);
        a0 = (void *)s2;
        a1 = (void *)s1;
        SetMyAttackAction(a0, a1, a2);
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)s2;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1 = (void *)(s32)(v0 != 0);
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
    }
    return;
}







/* MyActAttack4Sakuya @ 0x155BD0 .. 0x155F9C (0x3cc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x155c28 writes a register its branch at 0x155c24 reads
 *   delay: addiu at 0x155c3c writes a register its branch at 0x155c38 reads
 *   delay: addiu at 0x155c50 writes a register its branch at 0x155c4c reads
 *   fpu: float literal 0x41e00000 at 0x155c6c
 *   fpu: float literal 0x00000000 at 0x155ca8
 *   fpu: float literal 0x3f800000 at 0x155cc4
 *   fpu: float literal 0x00000000 at 0x155cd8
 *   fpu: float literal 0x41f00000 at 0x155cf0
 *   fpu: float literal 0x41f00000 at 0x155d30
 *   fpu: float literal 0x42480000 at 0x155d44
 *   delay: lui at 0x155e10 writes a register its branch at 0x155e0c reads
 *   fpu: float literal 0x42480000 at 0x155e14
 *   fpu: float literal 0x00000000 at 0x155e28
 *   fpu: float literal 0x00000000 at 0x155e68
 *   fpu: float literal 0x41f00000 at 0x155e90
 *   fpu: float literal 0x00000000 at 0x155ef0
 *   fpu: float literal 0x00000000 at 0x155f20
 *   fpu: float literal 0x00000000 at 0x155f68
 *   cfg: kept branch: 0x155e1c if (..) goto .L00155E40
 */

extern u8 MdlMng[];

static void MyActAttack4Sakuya(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u32 a2;
    float *s1;
    s32 v1;
    u32 v0;
    s32 s0;
    float f14;
    float f13;
    float f12;
    float f1;
    float f0;
    u64 v0_64;
    void *a0_2;
    void *a1_2;

    v0 = 0x33;
    s3 = (u8 *)a0;
    s2 = (u8 *)a1;
    a2 = *(u8 *)(((u8 *)a1 + 0x1ad));
    s1 = (float *)*(s32 *)(((u8 *)a0 + 0x100));
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    a2 = a2 + 0x2ef;
    a1_2 = (void *)MdlMng;
    a0_2 = (void *)(s32)((u32)(s32)((u8 *)(s32)(a2 << 3) - a2) << 6);
    s0 = (s32)((u8 *)MdlMng + (u32)(a0_2));
    switch ((u32)v1) {
    case 40:
        f12 = 28.0f;
        v0 = CheckAnimNumFrame((void *)s1, 28.0f);
        a0_2 = (void *)s3;
        if (v0 != 0) {
            a1_2 = (void *)s2;
            ChangeMyWeapon(a0_2, a1_2);
        }
        a0_2 = (void *)s1;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        a2 = *(u8 *)(s2 + 0x1ae);
        v0 = GetMyAttackAnim((void *)s3, (void *)s2, a2);
        f12 = 0.0f;
        a0_2 = (void *)s3;
        a1_2 = (void *)(u16)v0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        break;
    case 50:
        f12 = 1.0f;
        a0_2 = (void *)s1;
        v0 = CheckAnimNumFrame(a0_2, 1.0f);
        if (v0 != 0) {
            f12 = 0.0f;
            a0_2 = (void *)s0;
            a1_2 = (void *)(s32)1;
            ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        }
        v0 = 0x41f00000;
        f1 = *(float *)s1;
        f0 = 30.0f;
        if (f1 <= 30.0f && (u32)*(s32 *)(s3 + 0x1b4) != 0) {
            f13 = *(float *)(s3 + 0x198);
            f14 = *(float *)(s3 + 0x1a0);
            f12 = *(float *)(s3 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s3 + 0x34) = f0;
        }
        f1 = *(float *)s1;
        f0 = 30.0f;
        v0 = 0x42480000;
        if (30.0f <= f1) {
            f0 = 50.0f;
            if (f1 <= 50.0f) {
                v1 = *(u8 *)(s2 + 0x1ae);
                v0 = 1;
                switch ((u32)v1) {
                case 255:
                    v0 = *(u8 *)((*(s32 *)(s2 + 0x110) + 0x21));
                    v0_64 = (u64)((u64)v0 << 0x3a) >> 0x3f;
                    if (v0_64 == 0) {
                        break;
                    }
                    v0 = (s32)(*(u8 *)(s2 + 0x18e) != 0) ^ 1;
                    *(u8 *)(s2 + 0x18e) = v0;
                    break;
                case 0:
                    v0 = *(u8 *)((*(s32 *)(s2 + 0x110) + 0x21));
                    v0_64 = (u64)((u64)v0 << 0x38) >> 0x3f;
                    if (v0_64 == 0) {
                        break;
                    }
                    v0 = (s32)(*(u8 *)(s2 + 0x18e) != 0) ^ 1;
                    *(u8 *)(s2 + 0x18e) = v0;
                    break;
                case 1:
                    v0 = *(u8 *)((*(s32 *)(s2 + 0x110) + 0x21));
                    v0_64 = (u64)((u64)v0 << 0x3b) >> 0x3f;
                    if (v0_64 == 0) {
                        break;
                    }
                    v0 = (s32)(*(u8 *)(s2 + 0x18e) != 0) ^ 1;
                    *(u8 *)(s2 + 0x18e) = v0;
                }
            }
        }
        v0 = *(u8 *)(s2 + 0x18e);
        if (v0 != 0) {
            f12 = 50.0f;
            a0_2 = (void *)s1;
            v0 = CheckAnimNumFrame(a0_2, 50.0f);
            if (v0 == 0) {
                goto _L00155E40;
            }
            f12 = 0.0f;
            a0_2 = (void *)s3;
            a1_2 = (void *)(s32)0x33;
            ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
            break;
        } else {
            _L00155E40:;
            a2 = *(u8 *)(s2 + 0x1ae);
            a1_2 = (void *)s2;
            SetMyAttackAction((void *)s3, a1_2, a2);
            v0 = CheckAnimEndFrame((void *)s1);
            a0_2 = (void *)s3;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyTired(a0_2);
            f12 = 0.0f;
            a0_2 = (void *)s3;
            a1_2 = (void *)(s32)(v0 != 0);
            *(u8 *)(s2 + 0x100) = 0;
            ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
            break;
        }
    case 53:
        v0 = 0x41f00000;
        f1 = *(float *)s1;
        f0 = 30.0f;
        if (f1 <= 30.0f && (u32)*(s32 *)(s3 + 0x1b4) != 0) {
            f13 = *(float *)(s3 + 0x198);
            f14 = *(float *)(s3 + 0x1a0);
            f12 = *(float *)(s3 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s3 + 0x34) = f0;
        }
        a2 = *(u8 *)(s2 + 0x1ae);
        a1_2 = (void *)s2;
        SetMyAttackAction((void *)s3, a1_2, a2);
        v0 = CheckAnimEndFrame((void *)s1);
        a0_2 = (void *)s3;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_2);
        f12 = 0.0f;
        a0_2 = (void *)s3;
        a1_2 = (void *)(s32)(v0 != 0);
        *(u8 *)(s2 + 0x100) = 0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        break;
    case 137:
    case 138:
    case 139:
        a0_2 = (void *)s1;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_2 = (void *)s3;
        a1_2 = (void *)(s32)0x82;
        *(u8 *)(s2 + 0x100) = 0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        break;
    case 51:
    default:
        a2 = *(u8 *)(s2 + 0x1ae);
        a1_2 = (void *)s2;
        SetMyAttackAction((void *)s3, a1_2, a2);
        v0 = CheckAnimEndFrame((void *)s1);
        a0_2 = (void *)s3;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_2);
        f12 = 0.0f;
        a0_2 = (void *)s3;
        a1_2 = (void *)(s32)(v0 != 0);
        *(u8 *)(s2 + 0x100) = 0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
    }
    return;
}









/* MyActAttack4Seimei @ 0x155900 .. 0x155BC8 (0x2c8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x155934 writes a register its branch at 0x155930 reads
 *   fpu: float literal 0x41f00000 at 0x155950
 *   fpu: float literal 0x41a00000 at 0x155990
 *   fpu: float literal 0x41f00000 at 0x1559a4
 *   delay: lui at 0x155a70 writes a register its branch at 0x155a6c reads
 *   fpu: float literal 0x41f00000 at 0x155a74
 *   fpu: float literal 0x00000000 at 0x155a88
 *   fpu: float literal 0x00000000 at 0x155ac8
 *   fpu: float literal 0x41f00000 at 0x155af0
 *   fpu: float literal 0x00000000 at 0x155b50
 *   fpu: float literal 0x00000000 at 0x155b98
 *   cfg: kept branch: 0x155a7c if (..) goto .L00155AA0
 */


static void MyActAttack4Seimei(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 v0;
    s32 v1;
    float *s0;
    float f1;
    float f0;
    s32 fpcc;
    float f13;
    float f14;
    float f12;
    u8 a2;

    v0 = 0x33;
    s2 = (u8 *)a0;
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    s0 = (float *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    switch ((u32)v1) {
    case 50:
        v0 = 0x41f00000;
        f1 = *(float *)s0;
        f0 = 30.0f;
        fpcc = f1 <= 30.0f;
        if (fpcc && (u32)*(s32 *)(s2 + 0x1b4) != 0) {
            f13 = *(float *)(s2 + 0x198);
            f14 = *(float *)(s2 + 0x1a0);
            f12 = *(float *)(s2 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s2 + 0x34) = f0;
        }
        f1 = *(float *)s0;
        f0 = 20.0f;
        fpcc = 20.0f <= f1;
        v0 = 0x41f00000;
        if (fpcc) {
            f0 = 30.0f;
            fpcc = f1 <= 30.0f;
            if (fpcc) {
                v1 = *(u8 *)(s1 + 0x1ae);
                v0 = 1;
                switch ((u32)v1) {
                case 255:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                    break;
                case 0:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                    break;
                case 1:
                    v0 = *(s32 *)(s1 + 0x110);
                    v0 = ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)((v0 +
                        0x21)))->f;
                    if (v0 == 0) {
                        break;
                    }
                    v0 = *(u8 *)(s1 + 0x18e);
                    v0 = v0 != 0;
                    v0 = v0 ^ 1;
                    *(u8 *)(s1 + 0x18e) = v0;
                }
            }
        }
        v0 = *(u8 *)(s1 + 0x18e);
        if (v0 != 0) {
            f12 = 30.0f;
            a0 = (void *)s0;
            v0 = CheckAnimNumFrame(a0, 30.0f);
            if (v0 == 0) {
                goto _L00155AA0;
            }
            f12 = 0.0f;
            a0 = (void *)s2;
            a1 = (void *)(s32)0x33;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        } else {
            _L00155AA0:;
            a2 = *(u8 *)(s1 + 0x1ae);
            a0 = (void *)s2;
            a1 = (void *)s1;
            SetMyAttackAction(a0, a1, a2);
            a0 = (void *)s0;
            v0 = CheckAnimEndFrame(a0);
            a0 = (void *)s2;
            if (v0 == 0) {
                break;
            }
            v0 = CheckMyTired(a0);
            f12 = 0.0f;
            a0 = (void *)s2;
            a1 = (void *)(s32)(v0 != 0);
            *(u8 *)(s1 + 0x100) = 0;
            ChangeAnimParam(a0, (signed int)a1, 0.0f);
            break;
        }
    case 53:
        v0 = 0x41f00000;
        f1 = *(float *)s0;
        f0 = 30.0f;
        fpcc = f1 <= 30.0f;
        if (fpcc && (u32)*(s32 *)(s2 + 0x1b4) != 0) {
            f13 = *(float *)(s2 + 0x198);
            f14 = *(float *)(s2 + 0x1a0);
            f12 = *(float *)(s2 + 0x34);
            f0 = Math_GotoAngle(f12, f13, f14);
            *(f32 *)(s2 + 0x34) = f0;
        }
        a2 = *(u8 *)(s1 + 0x1ae);
        a0 = (void *)s2;
        a1 = (void *)s1;
        SetMyAttackAction(a0, a1, a2);
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)s2;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1 = (void *)(s32)(v0 != 0);
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 51:
    default:
        a2 = *(u8 *)(s1 + 0x1ae);
        a0 = (void *)s2;
        a1 = (void *)s1;
        SetMyAttackAction(a0, a1, a2);
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)s2;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1 = (void *)(s32)(v0 != 0);
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
    }
    return;
}


/* MyActDamage @ 0x1554E0 .. 0x1558F8 (0x418 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x155514 writes a register its branch at 0x155510 reads
 *   delay: addiu at 0x155528 writes a register its branch at 0x155524 reads
 *   delay: addiu at 0x15553c writes a register its branch at 0x155538 reads
 *   delay: addiu at 0x155550 writes a register its branch at 0x15554c reads
 *   delay: addiu at 0x155564 writes a register its branch at 0x155560 reads
 *   delay: addiu at 0x155584 writes a register its branch at 0x155580 reads
 *   delay: addiu at 0x155598 writes a register its branch at 0x155594 reads
 *   delay: addiu at 0x1555ac writes a register its branch at 0x1555a8 reads
 *   delay: addiu at 0x1555c0 writes a register its branch at 0x1555bc reads
 *   delay: addiu at 0x1555d4 writes a register its branch at 0x1555d0 reads
 *   fpu: float literal 0x00000000 at 0x155608
 *   fpu: float literal 0x00000000 at 0x155630
 *   fpu: float literal 0x00000000 at 0x155658
 *   fpu: float literal 0x00000000 at 0x155680
 *   fpu: float literal 0x00000000 at 0x1556a8
 *   fpu: float literal 0x00000000 at 0x1556d0
 *   fpu: float literal 0x41c80000 at 0x15571c
 *   fpu: float literal 0x00000000 at 0x155768
 *   fpu: float literal 0x00000000 at 0x155790
 *   fpu: float literal 0x00000000 at 0x1557b8
 *   fpu: float literal 0x00000000 at 0x1557e8
 *   fpu: float literal 0x41c80000 at 0x155834
 *   fpu: float literal 0x00000000 at 0x155880
 *   delay: addiu at 0x1558b8 writes a register its branch at 0x1558b4 reads
 *   fpu: float literal 0x00000000 at 0x1558cc
 *   cfg: kept branch: 0x155758 if (..) goto .L00155780
 *   cfg: kept branch: 0x155780 if (..) goto .L001557A8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int SND_Play3DPoint(signed int, signed short, signed short, float *, float);

void MyActDamage(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    s32 v1;
    float f12;
    u32 v0;
    void *a1_2;

    s2 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    a0 = (void *)(s32)0x91;
    s1 = (u8 *)a1;
    switch ((u32)v1) {
    case 70:
    case 72:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x47;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 76:
    case 78:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x4d;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 100:
    case 102:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x65;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 106:
    case 108:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x6b;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 120:
    case 122:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x79;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 150:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x97;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 71:
    case 77:
    case 101:
    case 107:
    case 121:
        break;
    case 151:
        a0 = (void *)*(u8 *)(s1 + 0x1af);
        v1 = 0xff;
        if ((u32)a0 != (u32)v1) {
            break;
        }
        v1 = *(u8 *)(s1 + 0x100);
        v0 = 7;
        a0 = (void *)(s32)1;
        if ((u32)v1 == v0) {
            FECard_SetFade((unsigned char)a0, (s32)a0);
        }
        v1 = GameSt[0x14];
        f12 = 25.0f;
        a1_2 = (void *)(s32)0x64;
        v0 = (u32)v1 * 100;
        SND_Play3DPoint((signed int)(void *)(u32)(v0 + (u32)0xbee), (signed short)a1_2, 0, (float
            *)(s2 + 0x20), 25.0f);
        v1 = 5;
        *(u8 *)(s1 + 0x100) = v1;
        break;
    case 140:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L00155780;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x82;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
    case 141:
        _L00155780:;
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            goto _L001557A8;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x84;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
    case 142:
        _L001557A8:;
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x87;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 143:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x90;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    case 144:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        v1 = *(u8 *)(s1 + 0x100);
        v0 = 7;
        a0 = (void *)(s32)1;
        if ((u32)v1 == v0) {
            FECard_SetFade((unsigned char)a0, (s32)a0);
        }
        v1 = GameSt[0x14];
        f12 = 25.0f;
        a1_2 = (void *)(s32)0x64;
        v0 = (u32)v1 * 100;
        SND_Play3DPoint((signed int)(void *)(u32)(v0 + (u32)0xbee), (signed short)a1_2, 0, (float
            *)(s2 + 0x20), 25.0f);
        v1 = 5;
        *(u8 *)(s1 + 0x100) = v1;
        break;
    case 145:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        *(u8 *)(s1 + 0x18a) = 0;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)0x82;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    default:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        v0 = *(u8 *)(s1 + 0x18a);
        if (v0 != 0) {
            v0 = 0x12c;
            *(u16 *)(s1 + 0x1cc) = v0;
        }
        a0 = (void *)s2;
        *(u8 *)(s1 + 0x18a) = 0;
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a0 = (void *)s2;
        a1_2 = (void *)(s32)(v0 != 0);
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
        break;
    }
    return;
}


/* MyActDead @ 0x155360 .. 0x1554E0 (0x180 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1553bc writes a register its branch at 0x1553b8 reads
 *   delay: addiu at 0x1553d0 writes a register its branch at 0x1553cc reads
 *   delay: addiu at 0x1553e4 writes a register its branch at 0x1553e0 reads
 *   fpu: float literal 0x00000000 at 0x155418
 *   fpu: float literal 0x00000000 at 0x155440
 *   fpu: float literal 0x00000000 at 0x155468
 *   fpu: float literal 0x00000000 at 0x155490
 *   fpu: float literal 0x00000000 at 0x1554b8
 */


static void MyActDead(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 s0;
    u32 v0;
    s32 v1;
    float f12;

    s2 = (u8 *)a1;
    s1 = (u8 *)a0;
    s0 = *(s32 *)(((u8 *)a0 + 0x100));
    a0 = (void *)(s32)s0;
    v0 = CheckAnimEndFrame(a0);
    if (v0 != 0) {
        v0 = CheckFadeEnd();
        if (v0 != 0) {
            v0 = 1;
            *(u8 *)(((u8 *)s2 + 0x18d)) = v0;
            SetGameOver();
        }
    }
    a0 = (void *)*(s16 *)(((u8 *)s1 + 0x104));
    v1 = 0x7a;
    switch ((u32)a0) {
    case 72:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x4c;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 76:
    case 78:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x4e;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 102:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x6a;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 106:
    case 108:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x6c;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 122:
        a0 = (void *)(s32)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x7a;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
    }
    return;
}








/* MyActDoor @ 0x1551D0 .. 0x155358 (0x188 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x42b40000 at 0x1551dc
 *   stack: address of the slot at 0x40 escapes at 0x155210
 *   stack: address of the slot at 0x40 escapes at 0x155244
 *   fpu: float literal 0x00000000 at 0x155278
 *   fpu: float literal 0x3f000000 at 0x155298
 *   fpu: float literal 0x00000000 at 0x1552c8
 *   fpu: float literal 0x3f800000 at 0x1552f8
 *   fpu: float literal 0x3f800000 at 0x15531c
 */

extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern signed int SND_Play2D(signed int, signed short, signed short);

static void MyActDoor(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    float f12;
    u32 s2;
    u32 v1;
    s32 v0;
    float f2;
    float f1;
    float f0;
    void *a0_2;
    void *a1_2;

    f12 = 90.0f;
    s1 = (u8 *)a0;
    s2 = *(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)a1;
    a0_2 = (void *)(s32)s2;
    v0 = CheckAnimNumFrame(a0_2, 90.0f);
    if ((u32)v0 != 0) {
        {
            u8 stackFrame_40[16] __attribute__((aligned(16))) = {0};
            a0_2 = (void *)(s32)8;
            SetFadeMng((unsigned char)a0_2, (signed int *)((u8 *)&stackFrame_40[0]), 0x50, (void
                *)0, (void *)0, 0x1e, 0x32);
        }
    }
    a0_2 = (void *)(s32)s2;
    v0 = CheckAnimEndFrame(a0_2);
    if ((u32)v0 != 0) {
        v1 = *(u8 *)(s0 + 0x1b1);
        v0 = 1;
        if (v1 == (u32)v0) {
            s0 = (u8 *)*(s32 *)(s1 + 0x148);
            v0 = 9;
            f12 = 0.0f;
            a0_2 = (void *)s1;
            a1_2 = (void *)(s32)0x55;
            *(u8 *)(s0 + 0x100) = v0;
            ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
            v1 = 1;
            *(u8 *)(s0 + 0x190) = v1;
            f1 = 0.5f;
            a0_2 = (void *)(s32)2;
            *(f32 *)(s1 + 0x114) = (*(float *)(s1 + 0x114) * f1);
            FECard_SetFade((unsigned char)a0_2, 0);
        } else {
            a0_2 = (void *)s1;
            v0 = CheckMyTired(a0_2);
            f12 = 0.0f;
            a1_2 = (void *)(s32)((u32)v0 != 0);
            a0_2 = (void *)s1;
            *(u8 *)(s0 + 0x100) = 0;
            ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        }
        *(u8 *)(s1 + 0x132) = 0;
        *(u8 *)(s1 + 0x131) = 0;
        *(u8 *)(s1 + 0x133) = 0;
        f12 = *(float *)(s1 + 0x34);
        f0 = sinf(f12);
        f2 = 1.0f;
        f0 = (f2 * (float)f0);
        *(f32 *)(s1 + 0x20) = (*(float *)(s1 + 0x20) - f0);
        f12 = *(float *)(s1 + 0x34);
        f0 = cosf(f12);
        a0_2 = (void *)(s32)0x407;
        f2 = 1.0f;
        a1_2 = (void *)(s32)0x64;
        f0 = (f2 * (float)f0);
        *(f32 *)(s1 + 0x28) = (*(float *)(s1 + 0x28) - f0);
        SND_Play2D((signed int)a0_2, (signed short)a1_2, 0);
    }
    return;
}







/* MyActConcentrate @ 0x154F70 .. 0x1551D0 (0x260 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41200000 at 0x154fbc
 *   fpu: float literal 0x00000000 at 0x154ff8
 *   delay: addiu at 0x155030 writes a register its branch at 0x15502c reads
 *   fpu: float literal 0x41c80000 at 0x155054
 *   fpu: float literal 0x41c80000 at 0x15507c
 *   fpu: float literal 0x41c80000 at 0x1550a4
 *   fpu: float literal 0x00000000 at 0x155104
 *   delay: addiu at 0x15513c writes a register its branch at 0x155138 reads
 *   fpu: float literal 0x00000000 at 0x155180
 *   fpu: float literal 0x00000000 at 0x1551a8
 *   cfg: kept branch: 0x1550e0 if (..) goto .L00155120
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int Menu_TD_CallOrder(signed int, signed int, signed int);
extern void EneEraseAllFriend(void);
extern void SND_Stop(signed int);

void MyActConcentrate(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    s32 a2;
    u8 *s0;
    void *a1_2; // a1
    float f12;
    void *a0_2; // a0
    u32 v1;
    u32 v0;

    v0 = 0x30;
    s2 = (u8 *)a0;
    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    a1_2 = (void *)(s32)0x2e;
    switch (v1) {
    case 46:
        f12 = 10.0f;
        a0_2 = (void *)s0;
        v0 = CheckAnimNumFrame(a0_2, 10.0f);
        if (v0 != 0) {
            v0 = 0x10000;
            a1_2 = (void *)(s32)0x39c;
            a0_2 = (void *)(0x10000 | 0xd50c);
            a2 = 1;
            Menu_TD_CallOrder((signed int)a0_2, (signed int)a1_2, a2);
        }
        a0_2 = (void *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_2 = (void *)s2;
        a1_2 = (void *)(s32)0x2f;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        EneEraseAllFriend();
        a0_2 = (void *)(s32)1;
        *(u8 *)(s1 + 0x18c) = 0;
        FECard_SetFade((unsigned char)a0_2, 0);
        v1 = 2;
        a0_2 = (void *)GameSt[0x14];
        switch ((u32)a0_2) {
        case 0:
            f12 = 25.0f;
            a0_2 = (void *)(s32)0xc11;
            a1_2 = (void *)(s32)0x64;
            v0 = SND_Play3DPoint((signed int)a0_2, (signed short)a1_2, 0, (float *)(s2 + 0x20),
                25.0f);
            *(u32 *)(s1 + 0x1c0) = v0;
            break;
        case 1:
            f12 = 25.0f;
            a0_2 = (void *)(s32)0xc79;
            a1_2 = (void *)(s32)0x64;
            v0 = SND_Play3DPoint((signed int)a0_2, (signed short)a1_2, 0, (float *)(s2 + 0x20),
                25.0f);
            *(u32 *)(s1 + 0x1c0) = v0;
            break;
        case 2:
            f12 = 25.0f;
            a0_2 = (void *)(s32)0xcda;
            a1_2 = (void *)(s32)0x64;
            v0 = SND_Play3DPoint((signed int)a0_2, (signed short)a1_2, 0, (float *)(s2 + 0x20),
                25.0f);
            *(u32 *)(s1 + 0x1c0) = v0;
            break;
        }
        break;
    case 47:
        v0 = *(u8 *)((*(s32 *)(s1 + 0x110) + 3));
        if ((u64)((u64)v0 << 0x3c >> 0x3f) != 0) {
            if (*(s32 *)(s2 + 0x120) < *(s32 *)(s1 + 0x19c) || (s32)*(s32 *)(s1 + 0x1a0) > 0) {
                goto _L00155120;
            }
        }
        a0_2 = (void *)s2;
        f12 = 0.0f;
        a1_2 = (void *)(s32)0x30;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        a0_2 = (void *)*(s32 *)(s1 + 0x1c0);
        SND_Stop((signed int)a0_2);
        v0 = -1;
        *(u32 *)(s1 + 0x1c0) = v0;
        _L00155120:;
        a0_2 = (void *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        if (v0 != 0) {
            a0_2 = (void *)*(u8 *)(s1 + 0x18c);
            v1 = 1;
            if ((u32)a0_2 != v1) {
                v1 = (s32)((u8 *)a0_2 + 1);
                *(u8 *)(s1 + 0x18c) = v1;
            }
        }
        v1 = *(u8 *)(s1 + 0x18c);
        a1_2 = (void *)(s32)1;
        a0_2 = (void *)s2;
        if (v1 != (u32)(s32)a1_2) {
            break;
        }
        a2 = 7;
        SetHeartRate(a0_2, (signed int)a1_2, a2);
        break;
    case 48:
        a0_2 = (void *)s0;
        v0 = CheckAnimEndFrame(a0_2);
        a0_2 = (void *)s2;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_2);
        f12 = 0.0f;
        a1_2 = (void *)(s32)(v0 != 0);
        a0_2 = (void *)s2;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        a0_2 = (void *)(s32)1;
        a1_2 = (void *)a0_2;
        FECard_SetFade((unsigned char)a0_2, (signed int)a1_2);
        break;
    default:
        f12 = 0.0f;
        ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
    }
    return;
}












/* MyActBlast @ 0x154EC0 .. 0x154F6C (0xac bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x154f10
 *   fpu: float literal 0x00000000 at 0x154f40
 */


static void MyActBlast(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s0;
    s32 v1;
    u32 v0;
    float f12;
    void *a0_s1; // a0

    v1 = 0x40;
    s0 = (u8 *)a1;
    a1 = (void *)*(s16 *)(((u8 *)a0 + 0x104));
    a0_s1 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    switch ((u32)a1) {
    case 63:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_s1 = a0;
        a1 = (void *)(s32)0x40;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
        break;
    case 64:
        v0 = CheckAnimEndFrame(a0_s1);
        a0_s1 = a0;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0_s1);
        f12 = 0.0f;
        a0_s1 = a0;
        a1 = (void *)(s32)(v0 != 0);
        *(u8 *)(((u8 *)s0 + 0x100)) = 0;
        ChangeAnimParam(a0_s1, (signed int)a1, 0.0f);
    }
    return;
}











/* MyActCrouch @ 0x154A70 .. 0x154EB4 (0x444 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x154ae8
 *   fpu: float literal 0x00000000 at 0x154b0c
 *   fpu: float literal 0x45e10000 at 0x154b28
 *   fpu: float literal 0x00000000 at 0x154b3c
 *   fpu: float literal 0x00000000 at 0x154b64
 *   fpu: float literal 0x3fc90fdb at 0x154ba0
 *   fpu: float literal 0x00000000 at 0x154bb4
 *   fpu: float literal 0x3c8ef34d at 0x154bd4
 *   fpu: float literal 0x00000000 at 0x154bf4
 *   fpu: float literal 0x45e10000 at 0x154c10
 *   fpu: float literal 0x00000000 at 0x154c30
 *   fpu: float literal 0x3fc90fdb at 0x154c6c
 *   fpu: float literal 0x00000000 at 0x154c80
 *   fpu: float literal 0x00000000 at 0x154c9c
 *   fpu: float literal 0x00000000 at 0x154cbc
 *   fpu: mov.s at 0x154cc8 is a float copy
 *   fpu: float literal 0x45e10000 at 0x154ce0
 *   fpu: float literal 0x00000000 at 0x154cf4
 *   fpu: mov.s at 0x154d04 is a float copy
 *   fpu: float literal 0x00000000 at 0x154d14
 *   fpu: mov.s at 0x154d20 is a float copy
 *   fpu: float literal 0x3fc90fdb at 0x154d58
 *   fpu: float literal 0x00000000 at 0x154d6c
 *   fpu: float literal 0x40490fdb at 0x154d8c
 *   fpu: float literal 0x40c90fdb at 0x154db0
 *   fpu: mtc1 reinterprets v0 at 0x154dd4
 *   fpu: float literal 0x3c8ef34d at 0x154dfc
 *   fpu: mtc1 reinterprets v0 at 0x154e2c
 *   fpu: mtc1 reinterprets v1 at 0x154e40
 *   fpu: float literal 0x42c80000 at 0x154e58
 *   fpu: float literal 0x00000000 at 0x154e80
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void MyActCrouch(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    s32 a3;
    s32 a2;
    u8 *s0;
    void *a0_s1; // a0
    u32 v1;
    float f14;
    float f13;
    float f12;
    float f2;
    float f1;
    float f20;
    float f0;
    u32 v0;
    void *a1_2;
    u8 *s2;

    a0_bytes = (u8 *)a0;
    s0 = (u8 *)a1;
    a0_s1 = (void *)*(s32 *)(a0_bytes + 0x100);
    v1 = *(s32 *)(a0_bytes + 0xc);
    a1_2 = (void *)(s32)0x59;
    a3 = *(s16 *)(a0_bytes + 0x104);
    s2 = (u8 *)*(s32 *)((v1 + 0x4c));
    a2 = 0x57;
    switch ((u32)a3) {
    case 85:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        ChangeAnimParam((void *)a0_bytes, 0x57, 0.0f);
        break;
    case 86:
        v0 = *(u8 *)(s0 + 0x190);
        if (v0 == 0) {
            f12 = 0.0f;
            ChangeAnimParam((void *)a0_bytes, (signed int)a1_2, 0.0f);
        } else {
            v0 = 0x45e10000;
            f1 = *(float *)(s0 + 0x150);
            f0 = 7200.0f;
            if (f1 <= 7200.0f) {
                f12 = 0.0f;
                ChangeAnimParam((void *)a0_bytes, a2, 0.0f);
            } else {
                f13 = *(float *)(s0 + 0x168);
                f12 = *(float *)(a0_bytes + 0x34);
                f0 = Math_GetAngleDist(f12, f13);
                f1 = 0.0f;
                if (f0 < 0.0f) {
                    f13 = *(float *)(s0 + 0x168);
                    f12 = *(float *)(a0_bytes + 0x34);
                    f0 = (-Math_GetAngleDist(f12, f13));
                } else {
                    f13 = *(float *)(s0 + 0x168);
                    f12 = *(float *)(a0_bytes + 0x34);
                    f0 = Math_GetAngleDist(f12, f13);
                }
                v0 = 0x3fc90fdb;
                f1 = 1.57079637f;
                if (!(f0 < 1.57079637f)) {
                    f12 = 0.0f;
                    ChangeAnimParam((void *)a0_bytes, 0x58, 0.0f);
                }
            }
        }
        f12 = *(float *)(a0_bytes + 0x34);
        f14 = 0.0174499992f;
        f13 = *(float *)(s0 + 0x168);
        f0 = Math_GotoAngle(f12, f13, 0.0174499992f);
        *(f32 *)(a0_bytes + 0x34) = f0;
        break;
    case 87:
        v1 = *(u8 *)(s0 + 0x190);
        if (v1 == 0) {
            f12 = 0.0f;
            ChangeAnimParam((void *)a0_bytes, (signed int)a1_2, 0.0f);
            break;
        } else {
            v1 = 0x45e10000;
            f1 = *(float *)(s0 + 0x150);
            f0 = 7200.0f;
            if (f1 <= 7200.0f) {
                break;
            }
            f13 = *(float *)(s0 + 0x168);
            f12 = *(float *)(a0_bytes + 0x34);
            f0 = Math_GetAngleDist(f12, f13);
            f1 = 0.0f;
            if (f0 < 0.0f) {
                f12 = *(float *)(a0_bytes + 0x34);
                f13 = *(float *)(s0 + 0x168);
                f0 = (-Math_GetAngleDist(f12, f13));
            } else {
                f12 = *(float *)(a0_bytes + 0x34);
                f13 = *(float *)(s0 + 0x168);
                f0 = Math_GetAngleDist(f12, f13);
            }
            v0 = 0x3fc90fdb;
            f1 = 1.57079637f;
            if (f0 < 1.57079637f) {
                f12 = 0.0f;
                ChangeAnimParam((void *)a0_bytes, 0x56, 0.0f);
                break;
            } else {
                f12 = 0.0f;
                ChangeAnimParam((void *)a0_bytes, 0x58, 0.0f);
                break;
            }
        }
    case 88:
        v0 = *(u8 *)(s0 + 0x190);
        if (v0 == 0) {
            f20 = 0.0f;
            ChangeAnimParam((void *)a0_bytes, (signed int)a1_2, (float)0.0f);
        } else {
            v0 = 0x45e10000;
            f1 = *(float *)(s0 + 0x150);
            f0 = 7200.0f;
            if (f1 <= 7200.0f) {
                f20 = 0.0f;
                ChangeAnimParam((void *)a0_bytes, 0x57, (float)0.0f);
            } else {
                f13 = *(float *)(s0 + 0x168);
                f20 = 0.0f;
                f12 = *(float *)(a0_bytes + 0x34);
                f0 = Math_GetAngleDist(f12, f13);
                if (f0 < (float)0.0f) {
                    f13 = *(float *)(s0 + 0x168);
                    f12 = *(float *)(a0_bytes + 0x34);
                    f0 = (-Math_GetAngleDist(f12, f13));
                } else {
                    f13 = *(float *)(s0 + 0x168);
                    f12 = *(float *)(a0_bytes + 0x34);
                    f0 = Math_GetAngleDist(f12, f13);
                }
                v0 = 0x3fc90fdb;
                f1 = 1.57079637f;
                if (f0 < 1.57079637f) {
                    f12 = 0.0f;
                    ChangeAnimParam((void *)a0_bytes, 0x56, 0.0f);
                }
            }
        }
        f0 = 3.14159274f;
        f2 = (3.14159274f + *(float *)(s0 + 0x168));
        f0 = (3.14159274f + f2);
        if (f0 >= f20) {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f13 = (f2 - (6.28318548f * (float)((float)(s32)(f0 / 6.28318548f))));
        } else {
            v0 = 0x40c90fdb;
            f1 = 6.28318548f;
            f13 = (f1 + (f2 - (f1 * (float)((float)(s32)(f0 / f1)))));
        }
        f14 = 0.0174499992f;
        f12 = *(float *)(a0_bytes + 0x34);
        f0 = Math_GotoAngle(f12, f13, 0.0174499992f);
        *(f32 *)(a0_bytes + 0x34) = f0;
        break;
    case 89:
        v0 = CheckAnimEndFrame(a0_s1);
        if (v0 == 0) {
            break;
        }
        v0 = *(u16 *)(s2 + 0x18);
        f1 = 100.0f;
        a1_2 = (void *)(s32)1;
        *(f32 *)(a0_bytes + 0x114) = (((float)(float)v0 / 100.0f) * *(float *)(a0_bytes + 0x44));
        FECard_SetFade((unsigned char)(void *)(s32)2, (signed int)a1_2);
        v0 = CheckMyTired((void *)a0_bytes);
        f12 = 0.0f;
        a1_2 = (void *)(s32)(v0 != 0);
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam((void *)a0_bytes, (signed int)a1_2, 0.0f);
    }
    return;
}


/* MyActJump @ 0x154970 .. 0x154A64 (0xf4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x154998 is a float copy
 *   fpu: mov.s at 0x1549e8 is a float copy
 *   fpu: float literal 0x00000000 at 0x154a28
 */




static void MyActJump(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u8 *s0;
    float f12;
    float f20;
    float f0;
    u32 v1;
    u32 v0;
    void *a0_2;
    void *a1_2;

    s2 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a1;
    f0 = GetMyJumpCorrectFrame(a0);
    f20 = (float)f0;
    f0 = *(float *)s0;
    if (f0 < f20) {
        f0 = Math_GotoAngle(*(float *)(s2 + 0x34), *(float *)(s2 + 0x198), *(float *)(s2 + 0x1a0));
        *(f32 *)(s2 + 0x34) = f0;
        a1_2 = (void *)(s2 + 0x50);
        Math_GotoVectorXZ((float *)(u8 *)(s2 + 0x20), (float *)a1_2, (*(float *)(s2 + 0x19c) /
            f20));
    }
    v0 = CheckAnimNumFrame((void *)(u8 *)s0, (float)f20);
    a0_2 = (void *)(s2 + 0x20);
    if (v0 != 0) {
        a1_2 = (void *)(s2 + 0x50);
        sceVu0CopyVector(a0_2, a1_2);
        v1 = *(s32 *)(s0 + 0x24);
        v0 = -0x11;
        *(u32 *)(s0 + 0x24) = v1 & v0;
    }
    v0 = CheckAnimEndFrame((void *)(u8 *)s0);
    a0_2 = (void *)s2;
    if (v0 != 0) {
        v0 = CheckMyTired(a0_2);
        f12 = 0.0f;
        a1_2 = (void *)(s32)(v0 != 0);
        a0_2 = (void *)s2;
        *(u8 *)(s1 + 0x100) = 0;
        ChangeAnimParam(a0_2, (signed int)a1_2, 0.0f);
        *(u8 *)(s2 + 0x131) = 0;
        *(u8 *)(s2 + 0x132) = 0;
        *(u8 *)(s2 + 0x133) = 0;
    }
    return;
}


/* MyActTotter @ 0x154760 .. 0x154970 (0x210 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1547ec is a float copy
 *   fpu: mov.s at 0x1547f4 is a float copy
 *   fpu: float literal 0x40000000 at 0x154808
 *   fpu: float literal 0x00000000 at 0x154830
 *   fpu: mov.s at 0x154840 is a float copy
 *   fpu: float literal 0x3eb2b020 at 0x154850
 *   fpu: float literal 0x40490fdb at 0x1548a4
 *   fpu: float literal 0x00000000 at 0x1548a8
 *   fpu: float literal 0x40c90fdb at 0x1548c8
 *   fpu: mtc1 reinterprets v0 at 0x1548ec
 *   fpu: float literal 0x3c8ef34d at 0x15491c
 *   fpu: float literal 0x3d0ef34d at 0x15493c
 *   fpu: mov.s at 0x154944 is a float copy
 */



static void MyActTotter(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    float f21;
    u8 *s2;
    float f14;
    float f13;
    float f12;
    u32 v1;
    float f20;
    u32 v0;
    float f3;
    float f2;
    float f1;
    float f0;

    s1 = (u8 *)a0;
    f21 = *(float *)(((u8 *)a0 + 0x198));
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x17c));
    s0 = (u8 *)a1;
    UpdateMovePathTotter(a0);
    v0 = *(s32 *)(s1 + 0x17c);
    if (v0 == 0) {
        SetMyNormalMode();
        SetMyControlOff();
        SetGoToEndingFade();
    } else {
        v1 = *(s32 *)(s1 + 0x124);
        v0 = 0x78;
        if ((u32)(v1 % (u32)(0x78)) < (u32)0x3c) {
            f12 = *(float *)(s0 + 0x168);
            f0 = Math_GetAngleDist(f12, (float)f21);
            f20 = f0;
            f0 = Math_GetDistXZ((float *)*(s32 *)(s2 + 8), (float *)(u8 *)(s1 + 0x20));
            v0 = 0x40000000;
            f2 = 2.0f;
            f1 = (2.0f * *(float *)(s1 + 0x110));
            if (f0 < f1) {
                *(f32 *)(s0 + 0x184) = *(float *)(s1 + 0x198);
            } else {
                f0 = 0.0f;
                f1 = f20;
                if (f20 < 0.0f) {
                    f1 = (-f20);
                }
                v0 = 0x3eb2b020;
                f0 = 0.348999977f;
                if (f1 < 0.348999977f) {
                    *(f32 *)(s0 + 0x184) = (f21 + *(float *)(s0 + 0x168));
                } else if (!(f20 < f0)) {
                    *(f32 *)(s0 + 0x184) = (f0 + f21);
                } else {
                    *(f32 *)(s0 + 0x184) = (f21 - f0);
                }
            }
            f2 = *(float *)(s0 + 0x184);
            f1 = 3.14159274f;
            f0 = 0.0f;
            f3 = (3.14159274f + f2);
            if (f3 >= 0.0f) {
                v0 = 0x40c90fdb;
                f1 = 6.28318548f;
                f0 = (f2 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
            } else {
                f1 = 6.28318548f;
                f0 = (f1 + (f2 - (f1 * (float)((float)(s32)(f3 / f1)))));
            }
            *(f32 *)(s0 + 0x184) = f0;
            f12 = *(float *)(s1 + 0x34);
            f14 = 0.0174499992f;
            f13 = *(float *)(s0 + 0x184);
            f0 = Math_GotoAngle(f12, f13, 0.0174499992f);
            *(f32 *)(s1 + 0x34) = f0;
        } else {
            f12 = *(float *)(s1 + 0x34);
            f14 = 0.0348999985f;
            f0 = Math_GotoAngle(f12, (float)f21, 0.0348999985f);
            *(f32 *)(s1 + 0x34) = f0;
        }
    }
    return;
}








/* MyActFall @ 0x1545D0 .. 0x154760 (0x190 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x154604 writes a register its branch at 0x154600 reads
 *   fpu: float literal 0x41f00000 at 0x154620
 *   fpu: float literal 0x41f00000 at 0x154654
 *   fpu: float literal 0x41f00000 at 0x154674
 *   fpu: float literal 0x00000000 at 0x1546b0
 *   fpu: float literal 0x00000000 at 0x1546f8
 *   fpu: float literal 0x00000000 at 0x154728
 */


static void MyActFall(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s2;
    s32 a2;
    u8 *s0;
    u32 v1;
    float f12;
    float f1;
    float f0;
    u32 v0;

    s2 = (u8 *)a1;
    a1 = (void *)(s32)0x39;
    a2 = *(s16 *)(((u8 *)a0 + 0x104));
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s1 = (u8 *)a0;
    switch ((u32)a2) {
    case 55:
        v0 = 0x41f00000;
        f1 = *(float *)s0;
        f0 = 30.0f;
        if (f1 < 30.0f) {
            f0 = Math_GotoAngle(*(float *)(s1 + 0x34), *(float *)(s1 + 0x198), *(float *)(s1 +
                0x1a0));
            *(f32 *)(s1 + 0x34) = f0;
            f0 = *(float *)(s1 + 0x19c);
            a0 = (void *)(s1 + 0x20);
            f1 = 30.0f;
            a1 = (void *)(s1 + 0x50);
            Math_GotoVectorXZ((float *)a0, (float *)a1, (f0 / 30.0f));
        }
        f12 = 30.0f;
        a0 = (void *)s0;
        v0 = CheckAnimNumFrame(a0, 30.0f);
        a0 = (void *)(s1 + 0x20);
        if (v0 != 0) {
            a1 = (void *)(s1 + 0x50);
            sceVu0CopyVector(a0, a1);
            v1 = *(s32 *)(s0 + 0x24);
            v0 = -0x11;
            v0 = v1 & (u32)v0;
            *(u32 *)(s0 + 0x24) = v0;
        }
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0 = (void *)s1;
        a1 = (void *)(s32)0x38;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        SfxPostEffect_SetEnable(0, 0);
        SetLightDizzy(0);
        break;
    case 56:
        v1 = *(s32 *)(s2 + 0x110);
        v1 = *(u8 *)((v1 + 3));
        if ((u64)((u64)((u64)v1 << 0x39) >> 0x3f) == 0) {
            break;
        }
        f12 = 0.0f;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        break;
    case 57:
        a0 = (void *)s0;
        v0 = CheckAnimEndFrame(a0);
        a0 = (void *)s1;
        if (v0 == 0) {
            break;
        }
        v0 = CheckMyTired(a0);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0 = (void *)s1;
        *(u8 *)(s2 + 0x100) = 0;
        ChangeAnimParam(a0, (signed int)a1, 0.0f);
        *(u8 *)(s1 + 0x131) = 0;
        *(u8 *)(s1 + 0x132) = 0;
        *(u8 *)(s1 + 0x133) = 0;
    }
    return;
}


/* MyActPullIn @ 0x154420 .. 0x1545CC (0x1ac bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x154450 writes a register its branch at 0x15444c reads
 *   fpu: float literal 0x3ecccccd at 0x154474
 *   fpu: float literal 0x00000000 at 0x154498
 *   fpu: float literal 0x3f99999a at 0x1544bc
 *   fpu: float literal 0x3f4ccccd at 0x154508
 *   fpu: float literal 0x3b83126f at 0x154520
 *   fpu: float literal 0x3a83126f at 0x154540
 *   fpu: float literal 0x3e4ccccd at 0x154564
 *   fpu: float literal 0x00000000 at 0x15459c
 */


static void MyActPullIn(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a0_bytes; // s1
    u8 *a0_s1; // a0
    float f12;
    float f2;
    float f1;
    u32 v1;
    float f0;
    u32 v0;
    u8 *s0;

    a0_bytes = (u8 *)a0;
    v1 = 0x4a;
    s0 = (u8 *)a1;
    a1 = (void *)*(s16 *)(a0_bytes + 0x104);
    a0_s1 = (u8 *)*(s32 *)(a0_bytes + 0x100);
    switch ((u32)a1) {
    case 120:
        f2 = 0.400000006f;
        f1 = (0.400000006f / *(float *)(a0_s1 + 0xc));
        f0 = (*(float *)(a0_bytes + 0x24) + f1);
        *(f32 *)(a0_bytes + 0x24) = f0;
        v0 = CheckAnimEndFrame((void *)a0_s1);
        if (v0 == 0) {
            break;
        }
        f12 = 0.0f;
        a0_s1 = a0_bytes;
        a1 = (void *)(s32)0x79;
        ChangeAnimParam((void *)a0_s1, (signed int)a1, 0.0f);
        break;
    case 121:
        f1 = *(float *)(a0_bytes + 0x24);
        v1 = 0x3f99999a;
        f0 = 1.20000005f;
        if (!(f1 < 1.20000005f)) {
            v0 = CheckFadeEnd();
            if (v0 == 0 || (u32)*(u8 *)(s0 + 0x18d) != 0) {
                break;
            }
            v0 = 1;
            *(u8 *)(s0 + 0x18d) = v0;
            SetGameOver();
            break;
        } else {
            v1 = 0x3f4ccccd;
            f0 = 0.800000012f;
            if (!(f1 < 0.800000012f)) {
                v1 = 0x3b83126f;
                f0 = 0.00400000019f;
                f0 = (f1 + (float)f0);
                *(f32 *)(a0_bytes + 0x24) = f0;
                break;
            } else {
                v1 = 0x3a83126f;
                f0 = 0.00100000005f;
                f0 = (f1 + (float)f0);
                *(f32 *)(a0_bytes + 0x24) = f0;
                break;
            }
        }
    case 74:
        f2 = 0.200000003f;
        f1 = (0.200000003f / *(float *)(a0_s1 + 0xc));
        f0 = (*(float *)(a0_bytes + 0x24) - f1);
        *(f32 *)(a0_bytes + 0x24) = f0;
        v0 = CheckAnimEndFrame((void *)a0_s1);
        if (v0 == 0) {
            break;
        }
        *(u32 *)(a0_bytes + 0x24) = 0;
        v0 = 0x12c;
        *(u16 *)(s0 + 0x1cc) = v0;
        a0_s1 = a0_bytes;
        v0 = CheckMyTired((void *)a0_s1);
        f12 = 0.0f;
        a1 = (void *)(s32)(v0 != 0);
        a0_s1 = a0_bytes;
        *(u8 *)(s0 + 0x100) = 0;
        ChangeAnimParam((void *)a0_s1, (signed int)a1, 0.0f);
        *(u8 *)(a0_bytes + 0x131) = 0;
        *(u8 *)(a0_bytes + 0x132) = 0;
    }
    return;
}


/* SetMyStay @ 0x1543A0 .. 0x154420 (0x80 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1543fc
 */


void SetMyStay(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u32 s1;
    u8 *s0;
    u16 v1;
    u32 v0;

    v1 = a2;
    v0 = 1;
    s1 = (u32)a0;
    s0 = (u8 *)a1;
    switch ((u32)v1) {
    case 0:
    case 1:
        a0 = (void *)s1;
        v0 = CheckMyTired(a0);
        v1 = 1;
        switch (v0) {
        case 0:
            v1 = 0;
        }
    }
    a1 = (void *)v1;
    a0 = (void *)s1;
    *(u8 *)(s0 + 0x100) = 0;
    ChangeAnimParam(a0, (signed int)a1, 0.0f);
    return;
}










typedef struct {
    u8 pad0[0x100];
    u8 State;
    u8 pad1[0x18a - 0x101];
    u8 DamageFlag;
} SetMyDamageCtrl;

void SetMyDamage(void *lpMy, void *a1, unsigned short AnimIndex) {
    SetMyDamageCtrl *lpCtrl = a1;

    if (lpCtrl->State == 7) {
        FECard_SetFade(1, 1);
    }
    lpCtrl->State = 4;
    ChangeAnimParam(lpMy, AnimIndex, 0.0f);
    switch (AnimIndex) {
    case 70:
    case 100:
    case 120:
    case 143:
        lpCtrl->DamageFlag = 1;
        break;
    }
}


/* SetMyDead @ 0x154240 .. 0x1542F0 (0xb0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: float literal 0x41c80000 at 0x154284
 *   fpu: float literal 0x00000000 at 0x1542c8
 */

extern signed int SND_Play3DPoint(signed int, signed short, signed short, float *, float);

void SetMyDead(void *a0 /* r4 */, u8 *a1 /* r5 */, unsigned short a2 /* r6 */) {
    void *a1_value; // a1
    float f12;
    void *a0_value; // a0
    u32 v1;

    v1 = *(u8 *)(a1 + 0x100);
    if (v1 == (u32)7) {
        a0_value = (void *)(s32)1;
        FECard_SetFade((unsigned char)a0_value, (s32)a0_value);
    }
    v1 = GameSt[0x14];
    f12 = 25.0f;
    v1 = v1 * 5;
    SND_Play3DPoint((signed int)(void *)(u32)((u32)(v1 * (u32)(0x14)) + (u32)0xbee), 0x64, 0,
        (float *)((u8 *)a0 + 0x20), 25.0f);
    a1_value = (void *)(u16)(u32)a2;
    *(u8 *)(a1 + 0x100) = 5;
    if ((u32)a1_value != (u32)0xffff) {
        f12 = 0.0f;
        ChangeAnimParam((void *)a0, (signed int)a1_value, 0.0f);
    }
    return;
}









/* SetMyDoor @ 0x154120 .. 0x154240 (0x120 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x154154 is a float copy
 *   fpu: float literal 0x00000000 at 0x154158
 *   fpu: float literal 0x00000000 at 0x154164
 *   fpu: mtc1 reinterprets v0 at 0x1541d0
 *   fpu: mtc1 reinterprets v1 at 0x1541e4
 *   fpu: float literal 0x42c80000 at 0x1541fc
 */


void SetMyDoor(void *a0 /* r4 */, void *a1 /* r5 */, float f12 /* f12 */, unsigned short a2 /* r6
        */, unsigned char a3 /* r7 */) {
    u8 s2;
    void *a1_value; // a1
    u8 *s0;
    float f20;
    void *a0_value; // a0
    float f1;
    u32 v1;
    u32 v0;

    s2 = a3;
    a1_value = (void *)(u16)a2;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    f20 = f12;
    f12 = 0.0f;
    *(u8 *)(s0 + 0x100) = 6;
    ChangeAnimParam(a0, (signed int)a1_value, 0.0f);
    f12 = 0.0f;
    SetHokanFrame((void *)a0, 0.0f);
    sceVu0CopyVector((void *)(u32)(s32)((u8 *)a0 + 0x20), (void *)a1);
    a0_value = a0;
    *(f32 *)(((u8 *)a0 + 0x34)) = f20;
    ReCalcMi3Matrix(a0_value);
    UpdateWorldMatrixInAnim((void *)a0);
    CsMngStabilize((u32)a0, 0x1e);
    *(u8 *)(s0 + 0x1b1) = s2;
    v1 = 1;
    *(u8 *)(((u8 *)a0 + 0x132)) = v1;
    *(u8 *)(((u8 *)a0 + 0x131)) = v1;
    *(u8 *)(((u8 *)a0 + 0x133)) = v1;
    v1 = *(u8 *)(s0 + 0x190);
    if (v1 != 0) {
        v0 = *(s32 *)(((u8 *)a0 + 0xc));
        v0 = *(s32 *)((v0 + 0x4c));
        v0 = *(u16 *)((v0 + 0x18));
        a0_value = (void *)(s32)2;
        f1 = 100.0f;
        a1_value = (void *)(s32)1;
        *(f32 *)(((u8 *)a0 + 0x114)) = (((float)(float)v0 / 100.0f) * *(float *)(((u8 *)a0 +
            0x44)));
        FECard_SetFade((unsigned char)a0_value, (signed int)a1_value);
        *(u8 *)(s0 + 0x190) = 0;
    }
    return;
}


/* SetMyBlast @ 0x1540E0 .. 0x154118 (0x38 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1540ec
 */


void SetMyBlast(void *a0 /* r4 */, unsigned short a1 /* r5 */) {
    u32 a1_word = a1;
    u8 *v0;

    v0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    a1_word = (u16)a1_word;
    *(u8 *)(((u8 *)v0 + 0x100)) = 8;
    ChangeAnimParam(a0, a1_word, 0.0f);
    a0 = (void *)(s32)1;
    a1_word = (s32)a0;
    FECard_SetFade((unsigned char)a0, a1_word);
    return;
}











/* SetMyCrouch @ 0x154070 .. 0x1540D8 (0x68 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x15407c
 *   fpu: float literal 0x3f000000 at 0x1540a8
 */


void SetMyCrouch(void *a0 /* r4 */) {
    u8 *a0_bytes; // s1
    u8 *s0;

    a0_bytes = (u8 *)a0;
    s0 = (u8 *)*(s32 *)(a0_bytes + 0x148);
    *(u8 *)(s0 + 0x100) = 9;
    ChangeAnimParam((void *)a0_bytes, 0x55, 0.0f);
    *(u8 *)(s0 + 0x190) = 1;
    *(f32 *)(a0_bytes + 0x114) = (*(float *)(a0_bytes + 0x114) * 0.5f);
    FECard_SetFade((unsigned char)(void *)(s32)2, 0);
    return;
}



/* SetMyJump @ 0x153F70 .. 0x15406C (0xfc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x153f9c is a float copy
 *   fpu: float literal 0x00000000 at 0x153fa4
 *   fpu: float literal 0x00000000 at 0x153fd0
 *   fpu: mov.s at 0x154004 is a float copy
 */

extern float Math_GetDist(float *, float *);

void SetMyJump(void *a0 /* r4 */, unsigned short a1 /* r5 */, float f12 /* f12 */, float *a2 /* r6
        */) {
    u32 a1_word = a1;
    u8 *s2;
    u32 s1;
    u8 *s0;
    float f20;
    u32 v1;
    float f13;
    float f1;
    float f0;
    u8 *v0;
    void *a0_2;

    a1_word = (u16)a1_word;
    s2 = (u8 *)a0;
    s1 = (u32)a2;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    f20 = f12;
    v0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    f12 = 0.0f;
    *(u8 *)(v0 + 0x100) = 0xa;
    ChangeAnimParam(a0, a1_word, 0.0f);
    v0 = (u8 *)(s32)1;
    *(u8 *)(s2 + 0x131) = (s32)v0;
    *(u8 *)(s2 + 0x132) = (s32)v0;
    *(u8 *)(s2 + 0x133) = (s32)v0;
    *(f32 *)(s2 + 0x198) = f20;
    f13 = *(float *)(s2 + 0x198);
    f12 = *(float *)(s2 + 0x34);
    f0 = Math_GetAngleDist(f12, f13);
    f1 = 0.0f;
    if (f0 < 0.0f) {
        f13 = *(float *)(s2 + 0x198);
        f12 = *(float *)(s2 + 0x34);
        f0 = (-Math_GetAngleDist(f12, f13));
    } else {
        f13 = *(float *)(s2 + 0x198);
        f12 = *(float *)(s2 + 0x34);
        f0 = Math_GetAngleDist(f12, f13);
    }
    f1 = f0;
    f0 = GetMyJumpCorrectFrame((void *)(u8 *)s2);
    a0_2 = (void *)(s2 + 0x50);
    a1_word = s1;
    *(f32 *)(s2 + 0x1a0) = (f1 / f0);
    sceVu0CopyVector(a0_2, (void *)a1_word);
    v0 = (u8 *)0x3f800000;
    a1_word = s1;
    *(u32 *)(s2 + 0x5c) = 0x3f800000;
    f0 = Math_GetDist((float *)(u8 *)(s2 + 0x20), (float *)a1_word);
    *(f32 *)(s2 + 0x19c) = f0;
    v1 = *(s32 *)(s0 + 0x24);
    *(u32 *)(s0 + 0x24) = v1 | 0x10;
    return;
}

/* SetMyFall @ 0x153E40 .. 0x153F6C (0x12c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x153e6c is a float copy
 *   fpu: float literal 0x00000000 at 0x153e74
 *   fpu: float literal 0x00000000 at 0x153ea0
 *   fpu: float literal 0x41f00000 at 0x153edc
 *   stack: address of the slot at 0x50 escapes at 0x153f34
 */

extern void SfxPostEffect_SetFlickerParam(void *);

void SetMyFall(void *a0 /* r4 */, float f12 /* f12 */, float *a1 /* r5 */) {
    u8 *s2;
    u32 s1;
    u8 *s0;
    float f20;
    u32 v1;
    float f13;
    float f1;
    float f0;
    u32 v0;
    void *a0_2;
    float *a1_2;
    u8 stackFrame_50[16] __attribute__((aligned(16)));

    s2 = (u8 *)a0;
    s1 = (u32)a1;
    a1_2 = (float *)(s32)0x37;
    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    f20 = f12;
    v0 = *(s32 *)(((u8 *)a0 + 0x148));
    f12 = 0.0f;
    *(u8 *)((v0 + 0x100)) = 0xc;
    ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
    v0 = 1;
    *(u8 *)(s2 + 0x131) = v0;
    *(u8 *)(s2 + 0x132) = v0;
    *(u8 *)(s2 + 0x133) = v0;
    *(f32 *)(s2 + 0x198) = f20;
    f13 = *(float *)(s2 + 0x198);
    f12 = *(float *)(s2 + 0x34);
    f0 = Math_GetAngleDist(f12, f13);
    f1 = 0.0f;
    if (f0 < 0.0f) {
        f13 = *(float *)(s2 + 0x198);
        f12 = *(float *)(s2 + 0x34);
        f0 = (-Math_GetAngleDist(f12, f13));
    } else {
        f13 = *(float *)(s2 + 0x198);
        f12 = *(float *)(s2 + 0x34);
        f0 = Math_GetAngleDist(f12, f13);
    }
    a0_2 = (void *)(s2 + 0x50);
    f1 = 30.0f;
    a1_2 = (float *)s1;
    *(f32 *)(s2 + 0x1a0) = (f0 / 30.0f);
    sceVu0CopyVector(a0_2, (void *)a1_2);
    v0 = 0x3f800000;
    a1_2 = (float *)s1;
    *(u32 *)(s2 + 0x5c) = 0x3f800000;
    a0_2 = (void *)(s2 + 0x20);
    f0 = Math_GetDist((float *)a0_2, a1_2);
    *(f32 *)(s2 + 0x19c) = f0;
    v0 = 0x3f990000;
    a1_2 = (float *)*(s32 *)(s0 + 0x24);
    v1 = 0x3f990000 | 0x999a;
    v0 = 0x3f000000;
    *(u32 *)(s0 + 0x24) = (u32)((u32)(a1_2)) | 0x10;
    *(u32 *)((u8 *)&stackFrame_50[0]) = v1;
    ((u32 *)stackFrame_50)[2] = 0x3f000000;
    ((u32 *)stackFrame_50)[1] = v1;
    SfxPostEffect_SetFlickerParam((void *)((u8 *)&stackFrame_50[0]));
    SfxPostEffect_SetEnable(0, 1);
    SetLightDizzy(1);
    return;
}







/* SetMyPullIn @ 0x153DE0 .. 0x153E38 (0x58 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x153dec
 */


void SetMyPullIn(void *a0 /* r4 */) {
    u8 *s0;
    s32 v0;

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    *(u8 *)(s0 + 0x100) = 0xd;
    ChangeAnimParam(a0, 0x78, 0.0f);
    v0 = 1;
    *(u8 *)(((u8 *)a0 + 0x131)) = v0;
    *(u8 *)(((u8 *)a0 + 0x132)) = v0;
    ClearMyStruggleStick((void *)a0, (u32)(s32)s0);
    return;
}



/* SetMyAttackAction @ 0x153A00 */
extern void * GetMyEquip(void *, signed int);
extern unsigned int CheckMyDizzyState(void *, void *);
extern void * GetEneParam(signed int, unsigned char);
extern signed int SFX_Create_OnAng(unsigned short, float *, float *);
struct SSP_Chr;
static void SetMySfxSpirit(struct SSP_Chr *lpMy, int unused, int SfxId, unsigned char dmypoly_id,
    int SpiritId);
extern void AddSpiritNum(signed int, signed short, unsigned char);
extern signed int GetSpiritNum(signed int);
extern unsigned int SetMyEquip(void *, signed int, signed int, signed int, signed int);
extern void FECard_StartVanish(unsigned short);
extern signed int CheckSpiritType(signed int);
extern void EneAppear(signed int, signed int, void *, float *, float, float *, unsigned char,
    unsigned short, unsigned char, void *, void *);
extern u32 V0[];
extern u32 V1[];

struct SmaMy { u8 pad0[0x20]; float Pos[4]; float Ang[4]; u8 pad1[0x100 - 0x40]; void *lpAnimCtrl; u8 pad2[0x128 - 0x104]; u8 TeamNo; u8 pad3[0x1c0 - 0x129]; };
struct SmaCtrl { u8 pad0[0x130]; float SummonPos[4]; u8 pad1[0x1ae - 0x140]; u8 btnId; u8 pad2[0x1c4 - 0x1af]; int UseWait[2]; u8 pad3[0x1d0 - 0x1cc]; };
struct SmaEquip { u8 type; u8 bRead; short num; int id; int dataIndex; };
struct SmaAtk { u32 power; u8 pad0[0x16 - 4]; u8 recover; u8 pad1[40 - 0x17]; };
struct SmaEne { u16 no; u8 pad0[0x23 - 2]; u8 useHeart; u8 pad1[0x2a - 0x24]; u16 sfxId; u8 pad2[0x38 - 0x2c]; u16 use_wait; u8 pad3[0xa0 - 0x3a]; struct SmaAtk Attack[5]; };

#define SMA_MY ((struct SmaMy *)a0)
#define SMA_CTRL ((struct SmaCtrl *)a1)
static void SetMyAttackAction(void *a0, void *a1, signed int btn) {
    struct SmaEquip *lpEquip;
    struct SmaEne *lpEnePrm;
    void *lpAnimCtrl;
    float ActFrame;
    int ObjId;
    unsigned char dmypoly_id;
    static void SetMySfxSpirit(struct SSP_Chr *, void *, int, unsigned char, int, int);

    lpEquip = (struct SmaEquip *)GetMyEquip(a0, btn);
    lpAnimCtrl = SMA_MY->lpAnimCtrl;
    {
    unsigned short Button[3] = {1, 0, 2};
    if (CheckMyDizzyState(a0, a1) != 0) {
        if (CheckAnimEndFrame(lpAnimCtrl) != 0) {
            SetHeartRate(a0, 0xa, 5);
        }
        return;
    }
    switch (lpEquip->type) {
    case 0:
        if (CheckAnimEndFrame(lpAnimCtrl) != 0) {
            SetHeartRate(a0, 0xa, 5);
        }
        break;
    case 1:
        lpEnePrm = (struct SmaEne *)GetEneParam(lpEquip->id, SMA_MY->TeamNo);
        if (lpEnePrm == 0) break;
        if (lpEnePrm->sfxId != 0) {
            switch (GameSt[0x14]) {
            case 0:
                ActFrame = 33.0f;
                dmypoly_id = 1;
                ObjId = 0x1e;
                break;
            case 2:
                dmypoly_id = 2;
                ActFrame = 20.0f;
                ObjId = 0x1e;
                break;
            case 1:
                ActFrame = 50.0f;
                ObjId = 0x14;
                dmypoly_id = 2;
                break;
            }
            if (CheckAnimNumFrame(lpAnimCtrl, ActFrame) == 0) break;
            if (lpEnePrm->Attack[0].recover != 0) {
                {
                    int power = lpEnePrm->Attack[0].power;
                    SFX_Create_OnAng(lpEnePrm->sfxId, SMA_MY->Pos, (float *)V0);
                    SetHeartRate(a0, power, 9);
                }
            } else {
                SetMySfxSpirit((struct SSP_Chr *)a0, a1, lpEnePrm->sfxId, dmypoly_id, lpEnePrm->no, ObjId);
            }
            SetHeartRate(a0, lpEnePrm->useHeart, 4);
            AddSpiritNum(lpEquip->id, -1, 1);
            ((int *)((u8 *)a1 + 0x1c4))[btn] = lpEnePrm->use_wait;
            if ((signed short)GetSpiritNum(lpEnePrm->no) == 0) {
                SetMyEquip(a0, btn, 0, 0, 0);
            }
            FECard_StartVanish(Button[SMA_CTRL->btnId]);
            if (CheckSpiritType(lpEnePrm->no) == 0) {
                Menu_TD_CallOrder(0x1d4fe, 0x398, 1);
            }
            if (CheckSpiritType(lpEnePrm->no) == 1) {
                Menu_TD_CallOrder(0x1d4fa, 0x399, 1);
            }
        } else {
            struct SmaMy *lpFriend;
            if (CheckAnimNumFrame(lpAnimCtrl, 1.0f) == 0) break;
            lpFriend = (struct SmaMy *)MdlMng + (btn + 0xd3);
            if (*(u8 *)lpFriend != 0) break;
            EneAppear(lpEquip->id, lpEquip->dataIndex, lpFriend, SMA_CTRL->SummonPos, SMA_MY->Ang[1], (float *)V1, 0, 6, 0, (void *)0, (void *)0);
            SetHeartRate(a0, lpEnePrm->useHeart, 3);
            AddSpiritNum(lpEquip->id, -1, 1);
            FECard_StartVanish(Button[SMA_CTRL->btnId]);
            ((int *)((u8 *)a1 + 0x1c4))[btn] = lpEnePrm->use_wait;
            if (CheckSpiritType(lpEnePrm->no) == 0) {
                Menu_TD_CallOrder(0x1d4fe, 0x398, 1);
            }
            if (CheckSpiritType(lpEnePrm->no) == 1) {
                Menu_TD_CallOrder(0x1d4fa, 0x399, 1);
            }
        }
        break;
    }
    }
}


extern void * GetDummyPolyData(void *, unsigned char, unsigned char);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void SfxCalc_Ang2Vec(float *, float, float);
extern void * SfxUtil_FindChar_Fan(signed int, float *, float *, float, float, signed int);
extern void sceVu0SubVector(void *, void *, void *);
extern void sceVu0Normalize(void *, void *);
extern signed int SFX_Create_OnDir_Dmg(unsigned short, float *, float *, unsigned char, unsigned char);

#define SSP_PI 3.14159274f
#define SSP_PI2 6.28318548f
#define SSP_ADJ(a) (((a) + SSP_PI >= 0.0f) ? ((a) - SSP_PI2 * (float)(s32)(((a) + SSP_PI) / SSP_PI2)) : (SSP_PI2 + ((a) - SSP_PI2 * (float)(s32)(((a) + SSP_PI) / SSP_PI2))))

typedef struct SSP_Dmy { u8 pad[0x20]; s16 bone; } SSP_Dmy;
typedef struct SSP_Chr { u8 pad[0xc]; void *mdl; float (*mtx)[4][4]; u8 pad2[0x1c]; float ang[4];
    u8 pad3[0x114 - 0x40]; float high; } SSP_Chr;

static void SetMySfxSpirit(SSP_Chr *lpMy, int unused, int SfxId, unsigned char dmypoly_id, int SpiritId) {
    SSP_Chr *lpEne;
    float SfxPos[4];
    float SfxAng[4];
    float Dir[4];
    SSP_Dmy *lpDmyPoly;
    float vAim[4];

    lpDmyPoly = GetDummyPolyData(lpMy->mdl, 0, dmypoly_id);
    sceVu0ApplyMatrix(SfxPos, lpMy->mtx[lpDmyPoly->bone], lpDmyPoly);
    sceVu0CopyVector(SfxAng, lpMy->ang);
    SfxAng[1] = SSP_ADJ(SSP_PI + SfxAng[1]);
    SfxCalc_Ang2Vec(Dir, SfxAng[0], SfxAng[1]);
    lpEne = SfxUtil_FindChar_Fan(1, SfxPos, Dir, 10.0f, 1.04699993f, 1);
    if (lpEne != 0) {
        lpDmyPoly = GetDummyPolyData(lpEne->mdl, 0, 5);
        if (lpDmyPoly != 0) {
            sceVu0ApplyMatrix(vAim, lpEne->mtx[lpDmyPoly->bone], lpDmyPoly);
        } else {
            float High;
            High = ((float *)((u8 *)lpEne + 0x20))[1] - 0.5f * lpEne->high;
            {
                float v[4] = {((float *)((u8 *)lpEne + 0x20))[0], High, ((float *)((u8 *)lpEne + 0x20))[2], 1.0f};
                sceVu0CopyVector(vAim, v);
            }
        }
        sceVu0SubVector(Dir, vAim, SfxPos);
        sceVu0Normalize(Dir, Dir);
    }
    SFX_Create_OnDir_Dmg(SfxId, SfxPos, Dir, SpiritId, 0);
}


/* GetMyJumpCorrectFrame @ 0x1536C0 .. 0x153810 (0x150 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1536c4
 *   delay: addiu at 0x1536d0 writes a register its branch at 0x1536cc reads
 *   delay: addiu at 0x1536e4 writes a register its branch at 0x1536e0 reads
 *   delay: addiu at 0x1536f8 writes a register its branch at 0x1536f4 reads
 *   fpu: float literal 0x41f00000 at 0x153714
 *   fpu: float literal 0x42340000 at 0x153724
 *   fpu: float literal 0x41f00000 at 0x153740
 *   delay: lui at 0x153758 writes a register its branch at 0x153754 reads
 *   fpu: float literal 0x42200000 at 0x15375c
 *   fpu: float literal 0x41f00000 at 0x153778
 *   delay: lui at 0x153790 writes a register its branch at 0x15378c reads
 *   fpu: float literal 0x42200000 at 0x153794
 *   fpu: float literal 0x41f00000 at 0x1537b0
 *   delay: lui at 0x1537c8 writes a register its branch at 0x1537c4 reads
 *   fpu: float literal 0x41f00000 at 0x1537cc
 *   fpu: float literal 0x42480000 at 0x1537e8
 *   delay: lui at 0x153800 writes a register its branch at 0x1537fc reads
 *   fpu: float literal 0x42700000 at 0x153804
 *   cfg: kept branch: 0x1536c0 if (..) goto .L001537D8
 *   cfg: kept branch: 0x1536d4 if (..) goto .L001537A0
 *   cfg: kept branch: 0x1536dc if (..) goto .L00153768
 *   cfg: kept branch: 0x1536e8 if (..) goto .L00153730
 *   cfg: kept branch: 0x1536f0 if (..) goto .L00153720
 *   cfg: kept goto: 0x153710 -> .L00153808
 *   cfg: kept goto: 0x153720 -> .L00153808
 *   cfg: kept goto: 0x15375c -> .L00153808
 *   cfg: kept goto: 0x153794 -> .L00153808
 *   cfg: kept goto: 0x1537cc -> .L00153808
 *   declaration vs inferred signature: return float vs inferred double
 */


static float GetMyJumpCorrectFrame(void *a0 /* r4 */) {
    s32 v1;
    float f0;
    s32 v0;
    s32 branchcond_1536cc;
    s32 branchcond_1536e0;
    s32 branchcond_1536f4;
    s32 branchcond_153754;
    s32 branchcond_15378c;
    s32 branchcond_1537c4;
    s32 branchcond_1537fc;

    v1 = *(s16 *)(((u8 *)a0 + 0x104));
    f0 = 0.0f;
    v0 = 0x45;
    branchcond_1536cc = (u32)v1 == (u32)v0;
    v0 = 0x44;
    if (branchcond_1536cc) {
        goto _L001537D8;
    }
    if ((u32)v1 == (u32)v0) {
        goto _L001537A0;
    }
    v0 = 0x43;
    branchcond_1536e0 = (u32)v1 == (u32)v0;
    v0 = 0x42;
    if (branchcond_1536e0) {
        goto _L00153768;
    }
    if ((u32)v1 == (u32)v0) {
        goto _L00153730;
    }
    v0 = 0x60;
    branchcond_1536f4 = (u32)v1 == (u32)v0;
    v0 = 0x5f;
    if (branchcond_1536f4) {
        goto _L00153720;
    }
    if ((u32)v1 != (u32)v0) {
        return f0;
    }
    v0 = 0x41f00000;
    f0 = 30.0f;
    goto _L00153808;
    _L00153720:;
    v0 = 0x42340000;
    f0 = 45.0f;
    goto _L00153808;
    _L00153730:;
    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
    v0 = 0x41f00000;
    if ((u32)v1 == 0) {
        f0 = 30.0f;
    } else {
        v0 = 1;
        branchcond_153754 = (u32)v1 != (u32)v0;
        v0 = 0x42200000;
        if (!branchcond_153754) {
            f0 = 40.0f;
            goto _L00153808;
            _L00153768:;
            v1 = *(u8 *)((u8 *)&GameSt + 0x14);
            v0 = 0x41f00000;
            if ((u32)v1 == 0) {
                f0 = 30.0f;
            } else {
                v0 = 1;
                branchcond_15378c = (u32)v1 != (u32)v0;
                v0 = 0x42200000;
                if (!branchcond_15378c) {
                    f0 = 40.0f;
                    goto _L00153808;
                    _L001537A0:;
                    v1 = *(u8 *)((u8 *)&GameSt + 0x14);
                    v0 = 0x41f00000;
                    if ((u32)v1 == 0) {
                        f0 = 30.0f;
                    } else {
                        v0 = 1;
                        branchcond_1537c4 = (u32)v1 != (u32)v0;
                        v0 = 0x41f00000;
                        if (!branchcond_1537c4) {
                            f0 = 30.0f;
                            goto _L00153808;
                            _L001537D8:;
                            v1 = *(u8 *)((u8 *)&GameSt + 0x14);
                            v0 = 0x42480000;
                            if ((u32)v1 == 0) {
                                f0 = 50.0f;
                            } else {
                                v0 = 1;
                                branchcond_1537fc = (u32)v1 != (u32)v0;
                                v0 = 0x42700000;
                                if (!branchcond_1537fc) {
                                    f0 = 60.0f;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    _L00153808:;
    return f0;
}


