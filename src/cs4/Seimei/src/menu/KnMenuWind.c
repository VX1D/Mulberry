#include "common.h"

/* KnMenuWindMng_GetWindVec @ 0x1D6170 .. 0x1D641C (0x2ac bytes, frame 0x70) */

extern void fsvu0_CopyVectorF(float *, float *);
extern float GetDist_(float *, float *);
extern void fsvu0_SubVector(float *, float *, float *);
extern void fsvu0_Normalize(float *, float *);
extern void fsvu0_ScaleVector(float *, float *, float);
extern signed int KnMenuMng_CheckCtrlPlay(int, signed int);
extern void fsvu0_AddVector(float *, float *, float *);
extern u32 g_ZeroVec[];
extern u32 lpPadData;
extern f32 power;
extern f32 rate;
extern u8 GameSt[];
extern f32 win_pos[];
extern f32 pos_time;
extern f32 pos_y;
extern f32 pos_z;
extern f32 radius;
extern u32 PointLightMng[];
extern f32 top_rate;


/* KnMenuWindMng_Delete @ 0x1D6420 .. 0x1D6448 (0x28 bytes) */

extern u32 pKnMenuWindMng;

extern signed int MngState_UpdateExeCheck(void *);
extern int rand();
extern f32 pos_time;
extern f32 top_rate;
extern f32 pos_y;
extern f32 pos_z;


/* KnMenuWindMng_SetTopWindRate @ 0x1D65D0 .. 0x1D65DC (0xc bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern f32 top_rate;

/* KnMenuWindMng_Init @ 0x1D65E0 .. 0x1D6644 (0x64 bytes, frame 0x10) */

extern signed int MngState_Init(void *);
static float win_pos[0x4] = {
    0.0f, 0.0f, 3e+01f, 1.0f
};
static u32 s_KnMenuWindMng[0xc];
static u32 pKnMenuWindMng = (u32)&s_KnMenuWindMng;
static float radius = 15.0f;
static float rate = 0.1f;
static f32 pos_z = 3e+01f;
static float power;
static f32 top_rate;
static f32 pos_y;
static f32 pos_time;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 KnMenuWindMng_Init(void);
u32 KnMenuWindMng_SetTopWindRate(void);
signed int KnMenuWindMng_Update(void);
u32 KnMenuWindMng_Delete(void);
signed int KnMenuWindMng_GetWindVec(float *wind_vec, float *pos, signed int id);


u32 KnMenuWindMng_Init(void) {
    u32 a0;
    s32 v0;
    u32 *v1;

    a0 = pKnMenuWindMng;
    v0 = 0;
    if (a0 == 0) {
        return v0;
    }
    MngState_Init((void *)a0);
    v1 = (u32 *)pKnMenuWindMng;
    if ((u32)(s32)v1 == 0) {
        if ((u32)(s32)v1 != 0) {
            *(u32 *)v1 = 0;
        }
        v0 = 0;
    } else {
        v0 = 2;
        *(u32 *)v1 = v0;
        v0 = 1;
    }
    return v0;
}

u32 KnMenuWindMng_SetTopWindRate(void) {
    top_rate = 1.0f;
    return;
}

signed int KnMenuWindMng_Update(void) {
    if (pKnMenuWindMng == 0) {
        return 0;
    }
    if (MngState_UpdateExeCheck((void *)pKnMenuWindMng) != 1) {
        return 0;
    }
    pos_time = (pos_time - 0.025f) - 0.00012f * (float)(rand() % 2);
    top_rate -= 0.05f;
    if (top_rate < 0.0f) {
        top_rate = 0.0f;
    }
    if (pos_time < -3.14159274f) {
        pos_time = 3.14159274f;
        pos_y = 0.1f * (float)(rand() % 10);
        pos_z = 12.5f + (float)(rand() % 10 - 5);
        pos_z = pos_z * 2.0f;
    }
    return 1;
}

u32 KnMenuWindMng_Delete(void) {
    u32 v0;

    v0 = pKnMenuWindMng;
    if (v0 == 0) {
        v0 = 0;
    } else {
        *(u32 *)v0 = 0;
        v0 = 1;
    }
    return v0;
}

signed int KnMenuWindMng_GetWindVec(float *wind_vec, float *pos, signed int id) {
    float tmpvec[4];
    float tmpf;
    float pl_pos[4];
    u8 *pad;

    fsvu0_CopyVectorF(wind_vec, (float *)g_ZeroVec);
    power = rate;
    pad = (u8 *)*(s32 *)(u32)(s32)(u32)&((struct { u8 b[4]; } *)&lpPadData)[GameSt[0xa]];
    win_pos[0] = 10.0f * (((float)(u32)pad[4] - 127.0f) / 255.0f);
    win_pos[0] = 5.0f * pos_time;
    win_pos[1] = pos_y;
    win_pos[2] = pos_z;
    tmpf = GetDist_(pos, win_pos);
    if (tmpf >= radius) {
        fsvu0_CopyVectorF(wind_vec, (float *)g_ZeroVec);
        return 1;
    }
    tmpf = tmpf / radius;
    fsvu0_SubVector(tmpvec, pos, win_pos);
    fsvu0_Normalize(tmpvec, tmpvec);
    fsvu0_ScaleVector(tmpvec, tmpvec, (1.0f - tmpf) * power);
    fsvu0_CopyVectorF(wind_vec, tmpvec);
    if (KnMenuMng_CheckCtrlPlay(3, 0) != 0) {
        fsvu0_ScaleVector(wind_vec, wind_vec, 0.5f);
        fsvu0_CopyVectorF(pl_pos, (float *)(PointLightMng + 4));
        pl_pos[1] = -3.0f;
        fsvu0_SubVector(tmpvec, pos, pl_pos);
        tmpf = GetDist_(tmpvec, (float *)g_ZeroVec);
        if (tmpf < 4.0f + 5.0f * (1.0f - top_rate)) {
            tmpf = tmpf / (5.0f + 5.0f * (1.0f - top_rate));
            fsvu0_Normalize(tmpvec, tmpvec);
            fsvu0_ScaleVector(tmpvec, tmpvec, tmpf * (0.2f * top_rate));
            fsvu0_AddVector(wind_vec, wind_vec, tmpvec);
        }
    }
    if (id != 0x13 && id != 7) {
        fsvu0_ScaleVector(wind_vec, wind_vec, 0.3f);
    }
    return 1;
}
