#include "common.h"

/* SfxBugs_Create @ 0x2043F0 .. 0x20445C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

extern unsigned short SList_PushFront(void *, void *);
extern void * SList_GetElemPtr(void *, unsigned short);
static void _InitMng(void *pMngV, void *pParamV);
static void _InitMng(void *, void *);
extern u32 s_pMngObjList;

static u32 s_pBugObjList;
/* _InitMng @ 0x204460 .. 0x204838 (0x3d8 bytes, frame 0xb0) */
/*
 * dcomp notes:
 *   literal: @1131 is the string 'sfxt%03d.tm2'
 *   stack: address of the slot at 0x80 escapes at 0x2044c0
 *   fpu: mov.s at 0x2044f4 is a float copy
 *   stack: address of the slot at 0x90 escapes at 0x204550
 *   fpu: mtc1 reinterprets v0 at 0x2045c4
 *   fpu: mtc1 reinterprets v1 at 0x2045d8
 *   fpu: float literal 0x37800080 at 0x2045f8
 *   fpu: float literal 0x40c90fdb at 0x2045fc
 *   fpu: mtc1 reinterprets v0 at 0x20461c
 *   fpu: mtc1 reinterprets v1 at 0x204630
 *   fpu: float literal 0x37800080 at 0x204650
 *   fpu: float literal 0x40c90fdb at 0x204654
 *   fpu: mtc1 reinterprets v0 at 0x204674
 *   fpu: mtc1 reinterprets v1 at 0x204688
 *   fpu: float literal 0x37800080 at 0x2046a4
 *   fpu: mov.s at 0x2046cc is a float copy
 *   fpu: mov.s at 0x2046d8 is a float copy
 *   fpu: mov.s at 0x20471c is a float copy
 *   fpu: mov.s at 0x204728 is a float copy
 *   fpu: mov.s at 0x204748 is a float copy
 *   fpu: mtc1 reinterprets v0 at 0x204798
 *   fpu: mtc1 reinterprets v1 at 0x2047ac
 *   fpu: float literal 0x37800080 at 0x2047c4
 *   stack: address of the slot at 0xae escapes at 0x2047e4
 *   cfg: loop body is not one contiguous region: .L00204588
 */

extern void * memset(void *, int, unsigned int);
extern void * SList_Init(void *, unsigned int, unsigned short);


extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void sceVu0CopyVector(void *, void *);
extern int sprintf(char *, const char *, ...);
extern u32 SfxFIO_GetTextureFile_Data();
extern void * GetTexMngByName(void *, char *);
extern u32 SfxCalc_RandU32();
extern float SfxCalc_Cos(float);
extern float SfxCalc_Sin(float);


struct dw_2704753_fields;
#ifndef PROTO_DW_2701003_FIELDS
#define PROTO_DW_2701003_FIELDS
struct dw_2701003_fields { float mrx[4][4]; float time; float scale; float speed; float rnd_range; unsigned int rgba; float life; struct dw_2704753_fields *pTex; float wall_r; float wall_l; unsigned char bWallR; unsigned char bWallL; unsigned char _pad0[2]; void *pBugLinkList; int dmy[3]; char buglink_buff[3072]; unsigned char _pad1[8]; };
#endif
#ifndef PROTO_DW_2701577_FIELDS
#define PROTO_DW_2701577_FIELDS
struct dw_2701577_fields { unsigned char form; unsigned char _pad0[15]; float pos[4]; float azim; float radius; float scale; float speed; float rnd_range; unsigned short tex_no; unsigned short num_bugs; unsigned int rgba; float life; float width_limit; float height_limit; float wall_r; float wall_l; unsigned char bWallR; unsigned char bWallL; unsigned char _pad1[14]; };
#endif

struct SfxBugObj { float pos[3]; u32 rnd; float life; float life0; };


/* SfxBugs_DrawAll @ 0x204840 .. 0x2048A8 (0x68 bytes, frame 0x30) */

extern unsigned short SList_GetFrontElem(void *);
extern unsigned short SList_GetNextElem(void *, unsigned short);
signed int SfxBugs_Draw(unsigned short hMng);
extern signed int SfxBugs_Draw(unsigned short);

/* SfxBugs_Draw @ 0x2048B0 .. 0x204C88 (0x3d8 bytes, frame 0x120) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @946 -> 0x250020
 *   literal: @951 -> 0x250030
 *   fpu: float literal 0x00000000 at 0x204948
 *   fpu: float literal 0x00000000 at 0x20496c
 *   stack: address of the slot at 0xd0 escapes at 0x20498c
 *   fpu: mtc1 reinterprets v0 at 0x2049e0
 *   fpu: mtc1 reinterprets v1 at 0x2049f8
 *   fpu: float literal 0x4f000000 at 0x204a10
 *   stack: address of the slot at 0x118 escapes at 0x204a6c
 *   fpu: float literal 0x00000000 at 0x204a90
 *   fpu: mov.s at 0x204aa4 is a float copy
 *   stack: address of the slot at 0xb0 escapes at 0x204ad0
 *   stack: address of the slot at 0x118 escapes at 0x204ad0
 *   stack: address of the slot at 0xc0 escapes at 0x204b10
 *   stack: address of the slot at 0xd0 escapes at 0x204b10
 *   stack: address of the slot at 0xc0 escapes at 0x204b10
 *   fpu: mtc1 reinterprets v1 at 0x204b40
 *   fpu: mtc1 reinterprets v1 at 0x204b8c
 *   stack: address of the slot at 0xc0 escapes at 0x204bb0
 *   stack: address of the slot at 0xc0 escapes at 0x204bb0
 *   stack: address of the slot at 0x110 escapes at 0x204bc4
 *   fpu: float literal 0x00000000 at 0x204be8
 *   fpu: mov.s at 0x204bf8 is a float copy
 *   stack: address of the slot at 0xc0 escapes at 0x204c04
 *   stack: address of the slot at 0x110 escapes at 0x204c04
 *   stack: address of the slot at 0x11c escapes at 0x204c58
 *   stack: address of the slot at 0xb4 escapes at 0x204c58
 *   stack: address of the slot at 0xb8 escapes at 0x204c58
 *   stack: address of the slot at 0xc4 escapes at 0x204c58
 *   literal: @946 initializes the 16-byte local at 0xb0
 *   literal: @951 initializes the 16-byte local at 0xc0
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 *   cfg: kept goto: 0x204990 -> .L00204C40
 *   cfg: loop test does not fall through into its body: 0x204c20
 *   cfg: kept branch: 0x204c20 if (..) goto .L002049A0
 *   cfg: kept goto: 0x204c40 -> .L00204C20
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_UseTexture(signed int);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_EnableFog(signed int);
extern void SfxDraw_SetBlendType(unsigned short);
extern void sceVu0InversMatrix(void *, void *);
extern void SfxDraw_SetColor(unsigned int);
extern void SfxDraw_DrawSprite_Wld2(float *, float *, float, float *, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern void SfxDraw_SetRenderStateBlock(u_long128);

extern u32 L946[];
extern u32 L951[];

typedef struct { float v[4]; } SbV4 __attribute__((aligned(16)));
signed int SfxBugs_Action(unsigned short a0 , float f12 );


/* SfxBugs_ActionAll @ 0x204C90 .. 0x204DAC (0x11c bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x204cb4 is a float copy
 *   fpu: mov.s at 0x204ce0 is a float copy
 *   cfg: loop body is not one contiguous region: .L00204CC8
 */

extern signed int SfxBugs_Action(unsigned short, float);
extern unsigned short SList_GetExistElemNum(void *);
extern signed int SList_Delete(void *, unsigned short);
extern u32 s_pBugObjList;

extern float Math_VectorToAngle(float, float);
extern float SfxCalc_Sin(float);
extern float SfxCalc_Cos(float);
extern u32 MdlMng[];


/* SfxBugs_Initialize @ 0x205060 .. 0x2050C4 (0x64 bytes, frame 0x10) */

extern void * SList_Init(void *, unsigned int, unsigned short);
extern u32 s_data_buff_mng[];
extern u32 s_data_buff_bug[];
static u32 s_data_buff_mng[0xa00];
static u32 s_data_buff_bug[0x1400];
static u32 s_pBugObjList;
static u32 s_pMngObjList;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int SfxBugs_Initialize(void);
signed int SfxBugs_Action(unsigned short a0 , float f12 );
u32 SfxBugs_ActionAll(float f12 );
signed int SfxBugs_Draw(unsigned short hMng);
u32 SfxBugs_DrawAll(void);
static void _InitMng(void *pMngV, void *pParamV);
unsigned short SfxBugs_Create(void *a0 );


signed int SfxBugs_Initialize(void) {
    u8 *a0;
    u32 v0;

    a0 = (u8 *)s_data_buff_mng;
    v0 = (u32)SList_Init((void *)s_data_buff_mng, 0x2800, 0xc80);
    s_pMngObjList = (u32)v0;
    v0 = s_pMngObjList;
    if (v0 == 0) {
        v0 = 0;
    } else {
        a0 = (u8 *)s_data_buff_bug;
        v0 = (u32)SList_Init((void *)s_data_buff_bug, 0x5000, 0x18);
        s_pBugObjList = (u32)v0;
        v0 = s_pBugObjList;
        v0 = v0 != 0;
    }
    return v0;
}

signed int SfxBugs_Action(unsigned short a0 /* r4 */, float f12 /* f12 */) {
    u16 a1;
    float f21;
    u32 v0;
    u8 *s5;
    float f13;
    u16 s4;
    signed int shift;
    u16 *s3;
    u8 *s2;
    u16 s1;
    u32 s0;
    float f5;
    float f3;
    float f2;
    float f20;
    float f1;
    float f0;
    float f22;
    u32 a0_2;

    a0_2 = s_pMngObjList;
    f21 = (float)f12;
    v0 = (u32)SList_GetElemPtr((void *)a0_2, a0);
    a0_2 = *(s32 *)(((u8 *)v0 + 0x68));
    s5 = (u8 *)v0;
    s4 = SList_GetFrontElem((void *)a0_2);
    v0 = ((s32)(1e+01f * *(float *)(s5 + 0x40)));
    shift = (s32)v0 % 0x20;
    v0 = 0xffff;
    *(f32 *)(s5 + 0x40) = (*(float *)(s5 + 0x40) + f21);
    if ((u32)s4 != v0) {
        do {
            a0_2 = *(s32 *)(s5 + 0x68);
            v0 = (u32)SList_GetElemPtr((void *)a0_2, s4);
            a0_2 = s_pBugObjList;
            a1 = *(u16 *)v0;
            s3 = (u16 *)v0;
            v0 = (u32)SList_GetElemPtr((void *)a0_2, a1);
            a0_2 = *(s32 *)(s5 + 0x68);
            s2 = (u8 *)v0;
            v0 = SList_GetNextElem((void *)a0_2, s4);
            s0 = *(s32 *)(s2 + 0xc);
            s1 = v0;
            f5 = (*(float *)(s5 + 0x48) + ((((float)(u32)(u8)s0 / 255.0f) - 0.5f) * *(float *)(s5 + 0x4c)));
            f2 = *(float *)(MdlMng + 0x4608);
            f3 = *(float *)s2;
            f5 = (f5 * (0.25f * (float)(float)(u32)((u32)(s0 >> (u32)shift) & 3)));
            f20 = (f5 * f21);
            f13 = (*(float *)(s2 + 8) - *(float *)(MdlMng + 0x460a));
            f0 = Math_VectorToAngle((f3 - f2), f13);
            f22 = (((1.5707964f * ((float)(float)s0 / 4.2949673e+09f)) - 0.7853982f) + f0);
            f0 = SfxCalc_Sin((float)f22);
            f12 = f22;
            f22 = f0;
            f0 = SfxCalc_Cos(f12);
            *(f32 *)s2 = (*(float *)s2 + (f22 * f20));
            *(f32 *)(s2 + 8) = (*(float *)(s2 + 8) + (f0 * f20));
            f1 = (*(f32 *)(s2 + 0x10) -= f21);
            if (f1 < 0.0f) {
                a0_2 = s_pBugObjList;
                a1 = *(u16 *)s3;
                SList_Delete((void *)a0_2, a1);
                a0_2 = *(s32 *)(s5 + 0x68);
                SList_Delete((void *)a0_2, s4);
            }
            s4 = s1;
            v0 = 0xffff;
        } while ((u32)s4 != v0);
    }
    return 1;
}

u32 SfxBugs_ActionAll(float f12 /* f12 */) {
    u32 a0;
    float f20;
    u32 v0;
    u16 s1;
    u16 s0;
    u8 *s3;
    u16 s2;

    a0 = s_pMngObjList;
    f20 = (float)f12;
    v0 = SList_GetFrontElem((void *)a0);
    s1 = v0;
    v0 = 0xffff;
    if ((u32)s1 != v0) {
        do {
            a0 = s_pMngObjList;
            v0 = SList_GetNextElem((void *)a0, s1);
            s0 = v0;
            SfxBugs_Action(s1, (float)(float)f20);
            a0 = s_pMngObjList;
            v0 = (u32)SList_GetElemPtr((void *)a0, s1);
            a0 = *(s32 *)(((u8 *)v0 + 0x68));
            v0 = SList_GetExistElemNum((void *)a0);
            v0 = (u16)v0;
            if (v0 == 0) {
                a0 = s_pMngObjList;
                v0 = (u32)SList_GetElemPtr((void *)a0, s1);
                a0 = *(s32 *)(((u8 *)v0 + 0x68));
                s3 = (u8 *)v0;
                v0 = SList_GetFrontElem((void *)a0);
                s2 = v0;
                v0 = 0xffff;
                if ((u32)s2 != v0) {
                    do {
                        a0 = *(s32 *)(s3 + 0x68);
                        v0 = (u32)SList_GetElemPtr((void *)a0, s2);
                        a0 = s_pBugObjList;
                        SList_Delete((void *)a0, *(u16 *)v0);
                        a0 = *(s32 *)(s3 + 0x68);
                        v0 = SList_GetNextElem((void *)a0, s2);
                        s2 = v0;
                        v0 = 0xffff;
                    } while ((u32)s2 != v0);
                }
                a0 = s_pMngObjList;
                SList_Delete((void *)a0, s1);
            }
            s1 = s0;
            v0 = 0xffff;
        } while ((u32)s1 != v0);
    }
    return 1;
}
signed int SfxBugs_Draw(unsigned short hMng) {
    u8 *pMng;
    u16 hElem;
    u32 bClip;
    u8 *pBug;
    u_long128 rs;
    u32 a;
    float mInv[4][4] __attribute__((aligned(16)));
    float f;
    SbV4 vP2;

    pMng = (u8 *)SList_GetElemPtr((void *)s_pMngObjList, hMng);
    rs = SfxDraw_GetRenderStateBlock();
    if (*(s32 *)(pMng + 0x58) != 0) {
        SfxDraw_SetTexture((void *)*(s32 *)(pMng + 0x58));
        SfxDraw_UseTexture(1);
    } else {
        SfxDraw_UseTexture(0);
    }
    SfxDraw_EnableZTest(1);
    SfxDraw_EnableFog(0);
    SfxDraw_SetBlendType(0);
    hElem = SList_GetFrontElem((void *)*(s32 *)(pMng + 0x68));
    bClip = 0.0f != *(float *)(pMng + 0x5c) || 0.0f != *(float *)(pMng + 0x60);
    if (bClip != 0) {
        sceVu0InversMatrix(mInv, pMng);
    }
    while (hElem != 0xffff) {
        pBug = (u8 *)SList_GetElemPtr((void *)s_pBugObjList, *(u16 *)SList_GetElemPtr((void *)*(s32 *)(pMng + 0x68), hElem));
        f = *(float *)(pBug + 0x10) / *(float *)(pBug + 0x14);
        a = *(s32 *)(pMng + 0x50);
        SfxDraw_SetColor((a & -0x100) + (u32)(f * (float)(u8)a));
        if (bClip == 0) {
            float sz[2] = {0.0f, 0.0f};

            sz[0] = *(float *)(pMng + 0x44);
            sz[1] = *(float *)(pMng + 0x44);
            {
                float vPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};
                vPos[0] = *(float *)pBug;
                vPos[1] = *(float *)(pBug + 4);
                vPos[2] = *(float *)(pBug + 8);
                SfxDraw_DrawSprite_Wld2(vPos, sz, 0.0f, (float *)0, 0.0f);
            }
        } else {
            static SbV4 sfxbugs_k2 = {{0.0f, 0.0f, 0.0f, 1.0f}};
            vP2 = sfxbugs_k2;

            vP2.v[0] = *(float *)pBug;
            vP2.v[1] = *(float *)(pBug + 4);
            vP2.v[2] = *(float *)(pBug + 8);
            sceVu0ApplyMatrix(vP2.v, mInv, vP2.v);
            if (*(float *)(pMng + 0x5c) < vP2.v[0]) {
                vP2.v[1] = ((*(u8 *)(pMng + 0x64) != 0 ? -1 : 1) * (vP2.v[0] - *(float *)(pMng + 0x5c)));
                vP2.v[0] = *(float *)(pMng + 0x5c);
            }
            if (vP2.v[0] < -*(float *)(pMng + 0x60)) {
                vP2.v[1] = ((*(u8 *)(pMng + 0x65) != 0 ? 1 : -1) * (vP2.v[0] - *(float *)(pMng + 0x60)));
                vP2.v[0] = *(float *)(pMng + 0x60);
            }
            sceVu0ApplyMatrix(vP2.v, pMng, vP2.v);
            {
                float sz[2] = {0.0f, 0.0f};
                sz[0] = *(float *)(pMng + 0x44);
                sz[1] = *(float *)(pMng + 0x44);
                SfxDraw_DrawSprite_Wld2(vP2.v, sz, 0.0f, (float *)0, 0.0f);
            }
        }
        hElem = SList_GetNextElem((void *)*(s32 *)(pMng + 0x68), hElem);
    }
    SfxDraw_SetRenderStateBlock(rs);
    return 1;
}


u32 SfxBugs_DrawAll(void) {
    u32 a0;
    u32 v0;
    u16 s1;
    u16 s0;

    a0 = s_pMngObjList;
    v0 = SList_GetFrontElem((void *)a0);
    s1 = v0;
    v0 = 0xffff;
    if ((u32)s1 != v0) {
        do {
            a0 = s_pMngObjList;
            v0 = SList_GetNextElem((void *)a0, s1);
            s0 = v0;
            SfxBugs_Draw(s1);
            s1 = s0;
            v0 = 0xffff;
        } while ((u32)s1 != v0);
    }
    return 1;
}

static void _InitMng(void *pMngV, void *pParamV) {
    struct dw_2701003_fields *pMng_ = (struct dw_2701003_fields *)pMngV;
    struct dw_2701577_fields *pParam_ = (struct dw_2701577_fields *)pParamV;
    int i;
    u8 buff[30];
    u16 hElem;
    struct SfxBugObj *pBug;
    float ang1;
    float ang2;
    float rnd;
    float rndRange;

    memset(pMng_, 0, 0xc80);
    pMng_->pBugLinkList = SList_Init(pMng_->buglink_buff, 0xc00, 2);
    {
        float pyr[4] = {0};

        *(float *)((u8 *)pyr + 4) = pParam_->azim;
        SfxCalc_MakeMatrixFromPYR(pMng_, pyr[0], pyr[1], pyr[2]);
    }
    sceVu0CopyVector(pMng_->mrx[3], pParam_->pos);
    pMng_->speed = pParam_->speed;
    pMng_->rnd_range = pParam_->rnd_range;
    pMng_->scale = pParam_->scale;
    pMng_->rgba = pParam_->rgba;
    pMng_->wall_r = pParam_->wall_r;
    pMng_->wall_l = pParam_->wall_l;
    pMng_->bWallR = pParam_->bWallR;
    pMng_->bWallL = pParam_->bWallL;
    sprintf((char *)buff, "sfxt%03d.tm2", pParam_->tex_no);
    pMng_->pTex = GetTexMngByName((void *)SfxFIO_GetTextureFile_Data(), (char *)buff);
    i = 0;
    if (i < pParam_->num_bugs) {
        float *py = &pMng_->mrx[3][1];
        float *pz = &pMng_->mrx[3][2];
        do {

        hElem = SList_PushFront((void *)s_pBugObjList, 0);
        if (hElem != 0xffff) {
            pBug = SList_GetElemPtr((void *)s_pBugObjList, hElem);
            ang1 = 6.2831855f * (1.5259022e-05f * (float)(u16)SfxCalc_RandU32());
            ang2 = 6.2831855f * (1.5259022e-05f * (float)(u16)SfxCalc_RandU32());
            rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            switch (pParam_->form) {
            case 0:
                pBug->pos[0] = pMng_->mrx[3][0] + rnd * (pParam_->radius * SfxCalc_Cos(ang1));
                pBug->pos[1] = *py;
                pBug->pos[2] = *pz + rnd * (pParam_->radius * SfxCalc_Sin(ang1));
                break;
            case 1:
                pBug->pos[0] = pMng_->mrx[3][0] + rnd * (pParam_->radius * SfxCalc_Cos(ang1));
                pBug->pos[1] = *py + rnd * (pParam_->radius * SfxCalc_Cos(ang2));
                pBug->pos[2] = *pz + rnd * (pParam_->radius * SfxCalc_Sin(ang1));
                break;
            }
            pBug->rnd = SfxCalc_RandU32();
            rndRange = pMng_->rnd_range;
            rnd = 1.5259022e-05f * (float)(u16)SfxCalc_RandU32();
            pBug->life = pBug->life0 = pParam_->life - rndRange * rnd;
            SList_PushFront(pMng_->pBugLinkList, &hElem);
        }
        i++;
        } while (i < pParam_->num_bugs);
    }
}

unsigned short SfxBugs_Create(void *a0 /* r4 */) {
    u32 s1;
    u32 v0;
    u16 s0;

    s1 = (u32)a0;
    a0 = (void *)s_pMngObjList;
    v0 = SList_PushFront(a0, (void *)0);
    s0 = v0;
    v0 = 0xffff;
    if ((u32)s0 == v0) {
        return v0;
    }
    a0 = (void *)s_pMngObjList;
    v0 = (u32)SList_GetElemPtr(a0, s0);
    _InitMng((void *)v0, (void *)s1);
    return s0;
}
