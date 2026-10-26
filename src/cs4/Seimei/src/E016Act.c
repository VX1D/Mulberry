#include "common.h"

extern int rand();
extern float Math_GetPosToAngle(float *,float *);
extern float Math_GotoAngle(float,float,float);
extern u32 MdlMng[];


/* E016ActStay @ 0x18E120 .. 0x18E1AC (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x18e140
 *   fpu: mtc1 reinterprets v1 at 0x18e158
 *   fpu: float literal 0x41200000 at 0x18e170
 *   fpu: float literal 0x3c8ef34d at 0x18e178
 */

extern float Math_GotoAngle(float, float, float);

/* E016ActAppear @ 0x18E1B0 .. 0x18E204 (0x54 bytes, frame 0x30) */

extern unsigned int CheckAnimEndFrame(void *);

/* E016ActInit @ 0x18E210 .. 0x18E260 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void E016ActAppear(void *a0 /* r4 */, void *a1 /* r5 */);
static void E016ActStay(void *a0 /* r4 */);
extern void E016ActWalk(void *, void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void E016ActInit(void *a0 , void *a1 );
static void E016ActAppear(void *a0 , void *a1 );
static void E016ActStay(void *a0 );
static void E016ActWalk(void *a0,void *a1);
static void E016ActDamage(void);
static void E016ActDead(void);


void E016ActInit(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E016ActAppear;
    *(u32 *)(((u8 *)a1 + 0x94)) = (u32)E016ActAppear;
    v1 = (u8 *)E016ActStay;
    *(u32 *)(((u8 *)a1 + 0x80)) = (u32)E016ActStay;
    v1 = (u8 *)E016ActWalk;
    *(u32 *)(((u8 *)a1 + 0x84)) = (u32)E016ActWalk;
    v1 = (u8 *)E016ActDamage;
    *(u32 *)(((u8 *)a1 + 0x8c)) = (u32)E016ActDamage;
    v1 = (u8 *)E016ActDead;
    *(u32 *)(((u8 *)a1 + 0x90)) = (u32)E016ActDead;
    v1 = (u8 *)(s32)1;
    *(u8 *)(((u8 *)a0 + 0x130)) = (s32)v1;
    *(u8 *)(((u8 *)a0 + 0x131)) = (s32)v1;
    *(u8 *)(((u8 *)a0 + 0x132)) = (s32)v1;
    return;
}

static void E016ActAppear(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 *s1;
    u32 *s0;
    s32 v0;

    s1 = (u32 *)a0;
    a0 = (void *)*(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u32 *)a1;
    v0 = CheckAnimEndFrame(a0);
    if ((u32)v0 != 0) {
        v0 = *(s32 *)(((u8 *)s0 + 0x100));
        ((void (*)(u32, u32, u32))v0)((u32)s1, (u32)(u32 *)s0, 0);
    }
    return;
}

static void E016ActStay(void *a0 /* r4 */) {
    u8 *s0;
    u32 v0;
    float f1;
    float f0;

    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    v0 = *(s32 *)((v0 + 0x4c));
    v0 = *(u16 *)((v0 + 0x1c));
    s0 = (u8 *)a0;
    f1 = 10.0f;
    f0 = 0.0174499992f;
    f0 = Math_GotoAngle(*(float *)(s0 + 0x34), *(float *)(s0 + 0x198), (0.0174499992f *
        ((float)(float)v0 / 10.0f)));
    *(f32 *)(s0 + 0x34) = f0;
    return;
}
static void E016ActWalk(void *a0,void *a1) {
    u8 *s2;
    u8 *s1;
    float f1;
    float f0;
    s32 s0;
    float f20;
    u32 v1;
    s32 hi;
    float f21;
    u32 v0;
    void *a0_2;
    s2=(u8 *)a0;
    v0=*(s32 *)(*(s32 *)((u8 *)a0+12)+76);
    s1=(u8 *)a1;
    f1=(float)(u32)*(u16 *)(v0+26);
    *(u8 *)(s1+472)=0;
    v1=(u32)(MdlMng+0x4600);
    s0=0;
    f20=f1/10.0f;
    v0=*(s32 *)(s2+436);
    if(v0!=0) {
        v0=rand();
        f0=*(float *)(s2+412);
        hi=(s32)v0%400;
        f1=1.0f+0.01f*(float)((float)(s32)(u32)hi);
        if(f0<f1) {
            f21=(3.1415927f+(3.1415927f+*(float *)(s2+408)))>=0.0f ? ((3.1415927f+*(float *)(s2+408))-6.2831855f*(float)(s32)((3.1415927f+(3.1415927f+*(float *)(s2+408)))/6.2831855f)) : 6.2831855f+((3.1415927f+*(float *)(s2+408))-6.2831855f*(float)(s32)((3.1415927f+(3.1415927f+*(float *)(s2+408)))/6.2831855f));
            v0=rand();
            if((u32)((s32)v0%5)!=0) *(u8 *)(s1+472)=1;
            f1=*(float *)(s2+412);
            if(f1<1.0f) *(u8 *)(s1+472)=1;
        } else {
            f21=(3.1415927f+*(float *)(s2+408))>=0.0f ? (*(float *)(s2+408)-6.2831855f*(float)(s32)((3.1415927f+*(float *)(s2+408))/6.2831855f)) : 6.2831855f+(*(float *)(s2+408)-6.2831855f*(float)(s32)((3.1415927f+*(float *)(s2+408))/6.2831855f));
            v0=rand();
            if((u32)((s32)v0%10)!=0) *(u8 *)(s1+472)=1;
            s0=1;
        }
        f1=*(float *)(s2+412);
        if(f1<0.1f && (u32)s0==0) ((void (*)(u32,u32,s32))*(s32 *)(s1+272))((u32)s2,(u32)s1,40);
    } else {
        a0_2=(void *)(s2+32);
        f0=Math_GetPosToAngle((float *)a0_2,(float *)(v1+32));
        f21=f0-3.1415927f;
    }
    f0=Math_GotoAngle(*(float *)(s2+52),(float)f21,0.01745f*f20);
    *(float *)(s2+52)=f0;
}

/* E016ActDamage @ 0x18DE10 .. 0x18DE18 (0x8 bytes) */

static void E016ActDamage(void) {
    return;
}

/* E016ActDead @ 0x18DE00 .. 0x18DE08 (0x8 bytes) */

static void E016ActDead(void) {
    return;
}
