#include "common.h"

extern float sinf(float);
extern f32 s_timer;
static u8 s_setting[16];
extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern void SfxDraw_SetPrimitiveType(unsigned short);
extern void SfxDraw_UseTexture(signed int);
extern void SfxDraw_SetColor(s32);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_SetTexture_FrameBuff(unsigned short, unsigned short, void *);
extern void SfxDraw_DrawIndexedPrimitive(void *, void *, void *, int);


/* SfxPostEffect_Draw @ 0x1CFBC0 .. 0x1CFC4C (0x8c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1cfbd8 writes a register its branch at 0x1cfbd4 reads
 *   fpu: float literal 0x00000000 at 0x1cfbf0
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern void _DrawFlicker(void);
static u8 s_setting[16];

/* SfxPostEffect_Action @ 0x1CFC50 .. 0x1CFC64 (0x14 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred float
 */

extern f32 s_timer;
static f32 s_timer;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SfxPostEffect_SetFlickerParam(void *a0 );
void SfxPostEffect_SetEnable(unsigned short a0 , signed int a1 );
signed int SfxPostEffect_Initialize(void);
int SfxPostEffect_Action(float sec_);
int SfxPostEffect_Draw(void);
void _DrawFlicker(void);


/* SfxPostEffect_SetFlickerParam @ 0x1CFCF0 .. 0x1CFD14 (0x24 bytes) */
/*
 * dcomp notes:
 *   stack: 12-byte aggregate copy in 4-byte chunks at 0x1cfd10
 *   declaration vs inferred signature: return void vs inferred float
 */

void SfxPostEffect_SetFlickerParam(void *a0 /* r4 */) {
    struct __copy_float_3 { float b[3]; };

    *(struct __copy_float_3 *)s_setting = *(struct __copy_float_3 *)a0;
    return;
}

/* SfxPostEffect_SetEnable @ 0x1CFCC0 .. 0x1CFCF0 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

void SfxPostEffect_SetEnable(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    u16 a2;
    u32 v1;
    u8 a0_2; // a0

    a2 = a0;
    v1 = (u32)a1 << (u32)a2;
    a0_2 = s_setting[0xc];
    s_setting[0xc] = v1 | (u32)((u32)~(u32)((u32)1 << (u32)a2) & (u32)(a0_2));
    return;
}

/* SfxPostEffect_Initialize @ 0x1CFC70 .. 0x1CFCBC (0x4c bytes) */

signed int SfxPostEffect_Initialize(void) {
    u32 a1;
    s32 v0;

    v0 = 0x3f000000;
    a1 = 0x3f800000;
    *(u32 *)s_setting = 0x3f800000;
    *(u32 *)(s_setting + 8) = 0x3f000000;
    s_timer = 0.0f;
    *(u32 *)(s_setting + 4) = 0x3f800000;
    ((struct { unsigned char f:1; } *)&s_setting[0xc])->f = 0;
    return 1;
}

int SfxPostEffect_Action(float sec_) {
    float f0;
    s32 v0;

    f0 = s_timer;
    v0 = 1;
    f0 = (f0 + sec_);
    s_timer = f0;
    return v0;
}

int SfxPostEffect_Draw(void) {
    u32 v0;
    s32 branchcond_1cfbd4;
    float f0;
    float f1;
    s32 fpcc;

    v0 = *(u8 *)((u8 *)&s_setting + 0xc);
    v0 = v0 & 1;
    branchcond_1cfbd4 = v0 != 0;
    v0 = 1;
    if (!branchcond_1cfbd4) {
        return v0;
    }
    f0 = *(float *)s_setting;
    f1 = 0.0f;
    fpcc = 0.0f == f0;
    v0 = 1;
    if (fpcc) {
        return v0;
    }
    f0 = *(float *)((u8 *)&s_setting + 8);
    fpcc = f1 == f0;
    v0 = 1;
    if (fpcc) {
        return v0;
    }
    _DrawFlicker();
    v0 = 1;
    return v0;
}

void _DrawFlicker(void) {
    int i;
    int j;
    float aVert[21][11][4];
    float aST[21][11][4];
    unsigned short aIndex[440];
    unsigned short count;
    unsigned int color;
    u_long128 sb;
    float *rowp;
    float *elp;
    unsigned short phase;
    int base0;
    int base1;

    count = 0;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 11; j++) {
            aVert[i][j][0] = 51.2f * (float)j;
            aVert[i][j][1] = 22.4f * (float)i;
            aVert[i][j][2] = 0.0f;
            aVert[i][j][3] = 1.0f;
            aST[i][j][0] = 0.1f * (float)j;
            aST[i][j][1] = 0.05f * (float)i;
            aST[i][j][2] = 1.0f;
            aST[i][j][3] = 0.0f;
        }
    }
    {
        int stripBase;
        unsigned short *marker;
        int row2Current;
        int row2Base;
        unsigned short c;
        i = 0;
        stripBase = 0;
        marker = aIndex;
        for (; i < 20; i++) {
            row2Base = stripBase + 11;
            j = 0;
            row2Current = row2Base;
            for (; j < 6; j += 5) {
                c = (u16)(count + 0);
                aIndex[c] = (j + 0) + stripBase;
                aIndex[(u16)(c + 1)] = row2Current;
                c = (u16)(count + 2);
                aIndex[c] = (j + 1) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 1) + row2Base;
                c = (u16)(count + 4);
                aIndex[c] = (j + 2) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 2) + row2Base;
                c = (u16)(count + 6);
                aIndex[c] = (j + 3) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 3) + row2Base;
                c = (u16)(count + 8);
                aIndex[c] = (j + 4) + stripBase;
                aIndex[(u16)(c + 1)] = (j + 4) + row2Base;
                count += 10;
                row2Current += 5;
            }
            c = (u16)(count + 0);
            aIndex[c] = j + stripBase;
            aIndex[(u16)(c + 1)] = j + row2Base;
            count += 2;
            stripBase += 11;
            marker[0] = marker[0] + 0x8000;
            marker[1] = marker[1] + 0x8000;
            marker += 22;
        }
    }
    phase = 200.0f * s_timer * ((float *)s_setting)[1];
    for (i = 1, rowp = aST[1][0]; i < 20; i++) {
        j = 1;
        elp = rowp + 4;
        for (; j < 10; j++) {
            elp[0] += ((float *)s_setting)[0] * (0.01f * sinf(0.01745f * (float)phase));
            phase += 10;
            elp += 4;
        }
        rowp += 44;
    }
    color = (unsigned int)(128.0f * ((float *)s_setting)[2]) + 0x80808000;
    sb = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetPrimitiveType(4);
    SfxDraw_UseTexture(1);
    SfxDraw_SetColor(color);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(1);
    SfxDraw_SetTexture_FrameBuff(9, 9, 0);
    SfxDraw_DrawIndexedPrimitive(aVert, aST, aIndex, 0x1b8);
    SfxDraw_SetRenderStateBlock(sb);
}
