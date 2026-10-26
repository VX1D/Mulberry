#include "common.h"

static u32 s_params;



extern void sceVu0CopyVector(void *, void *);
extern unsigned short SfxBugs_Create(void *);
extern u32 L885[];


struct sbCreate {
    u8 flag; u8 pad0[15];
    float pos[4];
    float azim; float f24; float f28; float speed; float f30; u16 f34; u16 num; u32 params; float life;
    u8 pad1[8];
    float wallR; float wallL;
    u8 bWallR; u8 bWallL; u8 pad2[14];
};
extern u32 s_params;
void SfxScriptIF_GenerateBugs(float posX_, float posY_, float posZ_, float azim_, signed int num_, float life_, float speed_, float wallR_, float wallL_, signed int bWallR_, signed int bWallL_);
void SfxScriptIF_Initialize(void);
void SfxScriptIF_SetBugColor(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */, signed int a3 /* r7 */);

/* SfxScriptIF_SetBugColor @ 0x215250 .. 0x215280 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */




void SfxScriptIF_SetBugColor(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6
        */, signed int a3 /* r7 */) {
    s32 t0;
    u32 v1;

    t0 = (u32)(u8)(s32)a0 << 0x18;
    {
        signed int dcomp_tmp_0;
        dcomp_tmp_0 = (u32)(u8)(s32)a1 << 0x10;
        a0 = dcomp_tmp_0;
    }
    v1 = (u8)(s32)a2;
    a0 = t0 + (u32)(a0);
    {
        signed int dcomp_tmp_1;
        dcomp_tmp_1 = (u32)(v1 << 8) + (u32)(a0);
        a0 = dcomp_tmp_1;
    }
    v1 = (u8)(s32)a3;
    s_params = v1 + (u32)(a0);
    return;
}







/* SfxScriptIF_Initialize @ 0x215120 .. 0x215248 (0x128 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   literal: @866 -> 0x250520
 *   fpu: float literal 0x437f0000 at 0x215138
 *   fpu: float literal 0x4f000000 at 0x215148
 *   fpu: float literal 0x437f0000 at 0x215190
 *   fpu: float literal 0x4f000000 at 0x215198
 *   fpu: float literal 0x437f0000 at 0x2151e0
 *   fpu: float literal 0x4f000000 at 0x2151e8
 *   literal: @866 initializes the 16-byte local at 0x0
 */


void SfxScriptIF_Initialize(void) {
    u32 a2;
    float f1;
    float f0;

    {
        struct stackFrame_0 { u8 b[16]; } stackFrame_0 __attribute__((aligned(16))) = {{0x9a, 0x99,
            0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x9a, 0x99, 0x99, 0x3e, 0x00, 0x00, 0x80, 0x3f}};
        a2 = (u32)((u8 *)&stackFrame_0);
        f1 = (255.0f * *(float *)((u8 *)&stackFrame_0 + 0xc));
        a2 = (u32)f1;
        f0 = 2.14748365e+09f;
        s_params = a2 + (u32)((u32)(a2 << 8) + (u32)((s32)((u32)(255.0f * *(float *)((u8
            *)&stackFrame_0)) << 0x18) + (u32)((u32)(255.0f * *(float *)((u8 *)&stackFrame_0 +
            0x4)) << 0x10)));
        return;
    }
}


/* SfxScriptIF_GenerateBugs @ 0x215000 .. 0x215114 (0x114 bytes, frame 0xd0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @885 -> 0x250530
 *   fpu: mov.s at 0x215048 is a float copy
 *   fpu: mov.s at 0x21504c is a float copy
 *   fpu: mov.s at 0x215050 is a float copy
 *   fpu: mov.s at 0x215054 is a float copy
 *   fpu: mov.s at 0x215058 is a float copy
 *   stack: address of the slot at 0x80 escapes at 0x215068
 *   stack: address of the slot at 0x60 escapes at 0x215068
 *   fpu: float literal 0x40490fdb at 0x215080
 *   fpu: float literal 0x3c8ef34d at 0x21509c
 *   stack: address of the slot at 0x70 escapes at 0x2150e0
 *   literal: @885 initializes the 16-byte local at 0x60
 */

void SfxScriptIF_GenerateBugs(float posX_, float posY_, float posZ_, float azim_, signed int num_, float life_, float speed_, float wallR_, float wallL_, signed int bWallR_, signed int bWallL_) {
    struct sbCreate create;
    {
        float v[4] = {0.0f, 0.0f, 0.0f, 1.0f};
        v[0] = posX_;
        v[1] = posY_;
        v[2] = posZ_;
        sceVu0CopyVector(create.pos, v);
        create.azim = 3.1415927f + 0.01745f * azim_;
        create.flag = 0;
        create.f24 = 0.4f;
        create.speed = speed_;
        create.f28 = 0.06f;
        create.f30 = 0.4f;
        create.f34 = 0x68;
        create.params = s_params;
        create.life = life_;
        create.wallR = wallR_;
        create.wallL = wallL_;
        create.bWallR = bWallR_;
        create.bWallL = bWallL_;
        create.num = num_;
        SfxBugs_Create(&create);
    }
}

static u32 s_params;
