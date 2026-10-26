#include "common.h"

extern float Math_VectorToAngle(float, float);
extern unsigned int CheckAnimParam(void *, signed int);


/* SetP004Walk @ 0x193F40 .. 0x193FD8 (0x98 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x193f64 writes a register its branch at 0x193f60 reads
 *   delay: addiu at 0x193f78 writes a register its branch at 0x193f74 reads
 *   fpu: float literal 0x00000000 at 0x193fb4
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * P004ActInit(s32 a0 , u32 *a1 );
static void SetP004Stay(void *a0 , void *a1 , unsigned short a2 );
static void SetP004Walk(void *a0 , void *a1 , unsigned short a2 );
static signed int GetP004DamageAnim(s32 a0);


/* P004ActInit @ 0x194070 .. 0x194098 (0x28 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */





u8 * P004ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)GetP004DamageAnim;
    *(u32 *)(((u8 *)a1 + 0x184)) = (u32)GetP004DamageAnim;
    v1 = (u8 *)SetP004Stay;
    *(u32 *)(((u8 *)a1 + 0x100)) = (u32)SetP004Stay;
    v1 = (u8 *)SetP004Walk;
    *(u32 *)(((u8 *)a1 + 0x104)) = (u32)SetP004Walk;
    return;
}

/* SetP004Stay @ 0x193FE0 .. 0x19406C (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x194004 writes a register its branch at 0x194000 reads
 *   delay: addiu at 0x194018 writes a register its branch at 0x194014 reads
 *   fpu: float literal 0x00000000 at 0x19404c
 *   a0 forwarded to ChangeAnimParam
 */



static void SetP004Stay(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 *s0;
    u16 v1;
    u32 v0;

    v1 = a2;
    v0 = *(u8 *)(((u8 *)a1 + 0x1f0));
    s0 = (u8 *)a1;
    if (v0 != 0) {
        v0 = 3;
        switch ((u32)v1) {
        case 0:
        case 2:
        case 14:
        case 1:
            v1 = 0x5a;
            break;
        case 3:
            v1 = 0x5b;
        }
    }
    a1 = (void *)v1;
    *(u8 *)(((u8 *)s0 + 0x180)) = 0;
    ChangeAnimParam(a0, (signed int)a1, 0.0f);
    *(u16 *)(((u8 *)s0 + 0x1dc)) = 0;
    return;
}

static void SetP004Walk(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u8 *s0;
    u16 v1;
    u32 v0;

    v1 = a2;
    v0 = *(u8 *)(((u8 *)a1 + 0x1f0));
    s0 = (u8 *)a1;
    if (v0 != 0) {
        v0 = 0x12;
        switch ((u32)v1) {
        case 10:
        case 11:
        case 5:
            v1 = 0x5c;
            break;
        case 19:
            v1 = 0x1d;
            break;
        case 18:
            v1 = 0x1c;
        }
    }
    a1 = (void *)v1;
    *(u8 *)(((u8 *)s0 + 0x180)) = 1;
    ChangeAnimParam(a0, (signed int)a1, 0.0f);
    *(u16 *)(((u8 *)s0 + 0x1de)) = 0;
    return;
}
static signed int GetP004DamageAnim(s32 a0) {
    u8 *s2;
    float f3;
    u8 *a2;
    u32 a1;
    float f2,f1,f0;
    float dx,dz;
    u32 v1;
    u8 *s1;
    u32 v0,s0;
    s32 index;
    s2=(u8 *)a0;
    index=*(u8 *)((u8 *)a0+0x19);
    {
        struct P004DamageEntry { u8 data[40]; };
        struct P004DamageEntry *entries = (struct P004DamageEntry *)*(u32 *)((u8 *)a0+0x14);
        s1 = entries[index].data + 0xa0;
    }
    a2=(u8 *)*(u32 *)((u8 *)a0+0x10);
    f0=Math_VectorToAngle(*(float *)(a2+0x20)-*(float *)a0,
                         *(float *)(a2+0x28)-*(float *)((u8 *)a0+8));
    v1=*(u32 *)(s2+0x10);
    f3=f0-*(float *)(v1+0x34);
    if(3.1415927f+f3>=0.0f) f2=f3-6.2831855f*(float)(s32)((3.1415927f+f3)/6.2831855f);
    else f2=6.2831855f+(f3-6.2831855f*(float)(s32)((3.1415927f+f3)/6.2831855f));
    a1=*(u32 *)(v1+0x148);
    v0=*(u8 *)(a1+0x1f0);
    if(v0==0) {
        a0=*(s32 *)(v1+0x120);
        v1=*(s32 *)(a1+0x254);
        if((s32)a0<(s32)v1/2) { s0=0x5d; *(u8 *)(a1+0x1f0)=1; }
        else {
            v0=*(u8 *)(s1+7);
            if(v0!=0) {
                if((f2<0.0f?-f2:f2)<1.5704999f) s0=0x1e;
                else s0=0x20;
            } else if((s32)a0>0) {
                if((f2<0.0f?-f2:(float)f2)<0.78524995f) s0=0x16;
                else if(!((f2<0.0f?-f2:(float)f2)<=2.3557498f)) s0=0x17;
                else if(f2<0.0f) s0=0x15;
                else if(!(f2<=0.0f)) s0=0x14;
            } else if((f2<0.0f?-f2:f2)<1.5704999f) s0=0x28;
            else s0=0x29;
        }
    } else {
        v0=*(u32 *)(v1+0x120);
        if((s32)v0>0) s0=0x5e;
        else s0=0x5f;
    }
    v0=CheckAnimParam((void *)*(s32 *)(s2+0x10),(u16)s0);
    if(v0!=0) return s0;
    v0=*(u32 *)(*(u32 *)(s2+0x10)+0x120);
    if((s32)v0>0) return 0x16;
    return 0x28;
}
