#include "common.h"

struct PointLight {
    u8 bUse;
    u8 ShadowOff;
    u8 unused0[2];
    float Radius;
    u8 unused1[8];
    float Pos[4];
    float Col[4];
};

/* UpdateObjectPointLight @ 0x164960 .. 0x1649BC (0x5c bytes, frame 0x10) */

extern void sceVu0CopyVector();
extern struct PointLight PointLightMng[];

/* GetPointLightMng @ 0x164B30 .. 0x164B3C (0xc bytes) */

extern struct PointLight *lpPointLightMng[];

#include "common.h"




extern struct PointLight DummyPointLightMng[1];

extern void sceVu0InversMatrix();
extern void sceVu0ApplyMatrix();
extern void sceVu0ScaleVectorXYZ(float *, float *, float);


/* UpdatePointLight @ 0x165180 .. 0x165188 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j UpdateMyLump at 0x165180 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern void UpdateMyLump(void);

/* SetPointLightOff @ 0x165190 .. 0x1651DC (0x4c bytes, frame 0x10) */

extern void * memset(void *, int, unsigned int);

/* InitPointLight @ 0x1652B0 .. 0x1652EC (0x3c bytes, frame 0x10) */

extern void *memset(void *, int, unsigned int);
extern struct PointLight PointLightMng[];
extern struct PointLight DummyPointLightMng[];
struct PointLight PointLightMng[0x10];
static struct PointLight DummyPointLightMng[1];
static struct PointLight *lpPointLightMng[0x4];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitPointLight(void);
u32 GetFreePointLightIndex(void);
u8 * SetPointLightOn(signed int a0 , float *a1 , float f12 );
void SetPointLightOff(signed int a0 );
void UpdatePointLight(void);
s32 CheckPointLightValid(void *lpVmdHead, void *lpBox, s32 mode);
u8 * GetPointLightMng(void);
signed int UpdatePointLightPos(signed int a0 , float *a1 );
signed int EnablePointLightShadow(signed int a0 , signed int a1 );
u32 UpdatePointLightRadius(signed int a0 , float f12 );
signed int UpdatePointLightColor(signed int a0 , float *a1 );
void UpdateObjectPointLight(u32 *a0 );


void InitPointLight(void) {
    u8 *a0;

    a0 = (u8 *)PointLightMng;
    memset(PointLightMng, 0, 0x300);
    a0 = (u8 *)DummyPointLightMng;
    memset(DummyPointLightMng, 0, 0x30);
    return;
}

/* GetFreePointLightIndex @ 0x165260 .. 0x1652A8 (0x48 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L00165270
 *   cfg: kept branch: 0x165288 if (..) goto .L00165270
 */

u32 GetFreePointLightIndex(void) {
    s32 v0;
    u8 *a0;
    u32 v1;

    v0 = 2;
    a0 = (u8 *)PointLightMng + 0x60;
    _L00165270:;
    v1 = *(u8 *)a0;
    if (v1 == 0) {
        return v0;
    }
    v0 = v0 + 1;
    v1 = v0 < (s32)0x10;
    a0 = (u8 *)(s32)((u8 *)a0 + 0x30);
    if (v1 != 0) {
        goto _L00165270;
    }
    v0 = -1;
    return v0;
}

/* SetPointLightOn @ 0x1651E0 .. 0x165254 (0x74 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1651f8 is a float copy
 *   return without a value in a non-void function
 */

u8 * SetPointLightOn(signed int a0 /* r4 */, float *a1 /* r5 */, float f12 /* f12 */) {
    float f20;
    u32 a2;
    u32 v1;
    s32 s0;

    f20 = (float)f12;
    if ((s32)a0 < (s32)0x11) {
        v1 = (u32)PointLightMng;
        s0 = (u32)((u32)((u32)a0) * (u32)(3)) << 4;
        a2 = (s32)((u8 *)PointLightMng + s0);
        v1 = *(u8 *)a2;
        if (v1 == 0) {
            a0 = a2 + 0x20;
            *(u8 *)a2 = 1;
            sceVu0CopyVector(a0, a1, a2);
            v1 = (u32)((u8 *)PointLightMng + 4);
            *(f32 *)(u32)(v1 + s0) = f20;
        }
    }
    return;
}

void SetPointLightOff(signed int a0 /* r4 */) {
    u32 a1;
    u32 v1;

    if ((s32)a0 < (s32)0x11) {
        a0 = (u32)a0 * (u32)(3);
        v1 = (u32)PointLightMng;
        a0 = (u32)a0 << 4;
        a0 = (s32)((u8 *)PointLightMng + a0);
        v1 = *(u8 *)a0;
        a1 = 0;
        if (v1 != 0) {
            memset((void *)a0, 0, 0x30);
        }
    }
    return;
}

/* UpdatePointLight @ 0x165180 .. 0x165188 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j UpdateMyLump at 0x165180 leaves the function
 */
void UpdatePointLight(void) {
    UpdateMyLump();
    return;
}

s32 CheckPointLightValid(void *lpVmdHead, void *lpBox, s32 mode)
{
    float InvObjMat[4][4];
    float PLightPos[4];
    float Prio[4];
    float GeomScale;
    float PLightSize;
    float x, y, z, Rate;
    u8 *lpVmdObj;
    struct PointLight *lpVmdObjLight;
    s16 ObjectId;
    u32 i, PLightNum, j, k;

    GeomScale = *(float *)(*(u8 **)(*(u8 **)((u8 *)lpVmdHead + 0xc) + 0x10) + 0x20);
    PLightNum = 0;
    if (lpBox != 0) {
        lpVmdObj = *(u8 **)((u8 *)lpBox + 0x4c);
        ObjectId = *(s16 *)((u8 *)lpBox + 0x30);
    } else {
        lpVmdObj = *(u8 **)(*(u8 **)(*(u8 **)((u8 *)lpVmdHead + 0xc) + 0x10) + 0x30);
        ObjectId = 0;
    }
    sceVu0InversMatrix(InvObjMat, *(u8 **)((u8 *)lpVmdHead + 0x10) + ObjectId * 0x40);
    for (i = 0; i < 4; i++) {
        lpPointLightMng[i] = DummyPointLightMng;
        Prio[i] = 10000000.0f;
    }

    for (i = 0; i < 16; ++i) {
        lpVmdObjLight = &PointLightMng[i];
        if (lpVmdObjLight->bUse == 0 || (mode == 1 && lpVmdObjLight->ShadowOff != 0))
            continue;
        sceVu0ApplyMatrix(PLightPos, InvObjMat, lpVmdObjLight->Pos);
        sceVu0ScaleVectorXYZ(PLightPos, PLightPos, GeomScale);
        PLightSize = GeomScale * (lpVmdObjLight->Radius * 3.0f);
        if (!((float)*(s16 *)(lpVmdObj + 8) < PLightPos[0] + PLightSize &&
              (float)*(s16 *)(lpVmdObj + 14) > PLightPos[0] - PLightSize &&
              (float)*(s16 *)(lpVmdObj + 10) < PLightPos[1] + PLightSize &&
              (float)*(s16 *)(lpVmdObj + 16) > PLightPos[1] - PLightSize &&
              (float)*(s16 *)(lpVmdObj + 12) < PLightPos[2] + PLightSize &&
              (float)*(s16 *)(lpVmdObj + 18) > PLightPos[2] - PLightSize))
            continue;
        x = (float)*(s16 *)(lpVmdObj + 0) - PLightPos[0];
        y = (float)*(s16 *)(lpVmdObj + 2) - PLightPos[1];
        z = (float)*(s16 *)(lpVmdObj + 4) - PLightPos[2];
        Rate = (x * x + y * y + z * z) / (GeomScale * GeomScale);
        for (j = 0; j < 4; ++j) {
            if (!(Rate < Prio[j])) {
                continue;
            }
            for (k = 3; k > j; --k) {
                lpPointLightMng[k] = lpPointLightMng[(u32)k - 1];
                Prio[k] = Prio[(u32)k - 1];
            }
            lpPointLightMng[j] = lpVmdObjLight;
            Prio[j] = Rate;
            ++PLightNum;
            break;
        }
    }
    return PLightNum;
}

u8 * GetPointLightMng(void) {
    return (u8 *)lpPointLightMng;
}

/* UpdatePointLightPos @ 0x164AD0 .. 0x164B24 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x164af8 writes a register its branch at 0x164af4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int UpdatePointLightPos(signed int a0 /* r4 */, float *a1 /* r5 */) {
    u32 v0;
    u32 v1;
    s32 branchcond_164af4;

    v1 = (u32)((u32)a0) * (u32)(0x30);
    v0 = (u32)PointLightMng;
    v1 = (s32)((u8 *)PointLightMng + v1);
    v0 = *(u8 *)v1;
    branchcond_164af4 = v0 != 0;
    v0 = 0;
    if (!branchcond_164af4) {
        return v0;
    }
    a0 = (s32)(v1 + 0x10);
    sceVu0CopyVector(a0, a1);
    v0 = 1;
    return v0;
}

/* EnablePointLightShadow @ 0x164A70 .. 0x164AC8 (0x58 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x164a90 writes a register its branch at 0x164a8c reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int EnablePointLightShadow(signed int a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v0;
    u32 v1;

    v1 = (u32)((u32)a0) * (u32)(0x30);
    v0 = (u32)PointLightMng;
    v0 = (s32)((u8 *)PointLightMng + v1);
    v0 = *(u8 *)v0;
    if (v0 == 0) {
        return (u32)0;
    }
    v0 = 1;
    *(u8 *)(u32)((u32)((u8 *)PointLightMng + 1) + v1) = (u32)((u32)(s32)a1 != 0) ^ 1;
    return v0;
}

/* UpdatePointLightRadius @ 0x164A20 .. 0x164A70 (0x50 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x164a40 writes a register its branch at 0x164a3c reads
 */

u32 UpdatePointLightRadius(signed int a0 /* r4 */, float f12 /* f12 */) {
    u32 v0;
    u32 v1;

    v1 = (u32)((u32)a0) * (u32)(0x30);
    v0 = (u32)PointLightMng;
    v0 = (s32)((u8 *)PointLightMng + v1);
    v0 = *(u8 *)v0;
    if (v0 == 0) {
        return 0;
    }
    v0 = 1;
    *(f32 *)(u32)((u32)((u8 *)PointLightMng + 4) + v1) = (float)f12;
    return v0;
}

/* UpdatePointLightColor @ 0x1649C0 .. 0x164A14 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1649e8 writes a register its branch at 0x1649e4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

signed int UpdatePointLightColor(signed int a0 /* r4 */, float *a1 /* r5 */) {
    u32 v0;
    u32 v1;
    s32 branchcond_1649e4;

    v1 = (u32)((u32)a0) * (u32)(0x30);
    v0 = (u32)PointLightMng;
    v1 = (s32)((u8 *)PointLightMng + v1);
    v0 = *(u8 *)v1;
    branchcond_1649e4 = v0 != 0;
    v0 = 0;
    if (!branchcond_1649e4) {
        return v0;
    }
    a0 = (s32)(v1 + 0x20);
    sceVu0CopyVector(a0, a1);
    v0 = 1;
    return v0;
}

void UpdateObjectPointLight(u32 *a0 /* r4 */) {
    u32 a1;
    u32 v1;
    u32 a2;

    a1 = *(u32 *)(((u8 *)a0 + 0x180));
    v1 = (s32)a1 < (s32)2;
    a2 = (u32)a0;
    if (v1 == 0) {
        a0 = (u32 *)((u32)a1 << 1);
        a0 = (u32 *)((u8 *)a0 + a1);
        v1 = (u32)PointLightMng;
        a0 = (u32 *)((u32)a0 << 4);
        a0 = (u32 *)((u8 *)PointLightMng + (u32)(a0));
        v1 = *(u8 *)a0;
        if (v1 != 0) {
            if (v1 != 0) {
                a0 = (u32 *)((u8 *)a0 + 0x10);
                a1 = a2 + 0x20;
                sceVu0CopyVector(a0, a1, a2);
            }
        }
    }
    return;
}
