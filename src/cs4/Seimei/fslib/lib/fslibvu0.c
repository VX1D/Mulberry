#include "common.h"


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void fsvu0_CopyVectorF(float *a0, float *a1);
void fsvu0_MulMatrix(void *a0 , void *a1 , void *a2 );
void fsvu0_ApplyMatrix(float *a0 , void *a1 , float *a2 );
void fsvu0_AddVector(float *a0 , float *a1 , float *a2 );
void fsvu0_SubVector(float *a0 , float *a1 , float *a2 );
u32 fsvu0_ScaleVector(float *a0 , float *a1 , float f12 );
void fsvu0_OuterProduct(float *a0 , float *a1 , float *a2 );
void fsvu0_Normalize(float *a0 , float *a1 );


void fsvu0_CopyVectorF(float *a0, float *a1) {
    __asm__ volatile("lq $6,0(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("sq $6,0(%0)" : : "r"(a0) : "memory");
}

/* fsvu0_MulMatrix @ 0x14AAB0 .. 0x14AB24 (0x74 bytes) */

void fsvu0_MulMatrix(void *a0 /* r4 */, void *a1 /* r5 */, void *a2 /* r6 */) {
    __asm__ volatile("lqc2 vf1,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("lqc2 vf2,16(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf3,32(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf4,48(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf22,0(%0)" : : "r"((u8 *)a2) : "memory");
    __asm__ volatile("lqc2 vf23,16(%0)" : : "r"(a2) : "memory");
    __asm__ volatile("lqc2 vf24,32(%0)" : : "r"(a2) : "memory");
    __asm__ volatile("lqc2 vf25,48(%0)" : : "r"(a2) : "memory");
    __asm__ volatile("vmulax.xyzw ACC,vf1,vf22x" : :  : "memory");
    __asm__ volatile("vmadday.xyzw ACC,vf2,vf22y" : :  : "memory");
    __asm__ volatile("vmaddaz.xyzw ACC,vf3,vf22z" : :  : "memory");
    __asm__ volatile("vmaddw.xyzw vf22,vf4,vf22w" : :  : "memory");
    __asm__ volatile("vmulax.xyzw ACC,vf1,vf23x" : :  : "memory");
    __asm__ volatile("vmadday.xyzw ACC,vf2,vf23y" : :  : "memory");
    __asm__ volatile("vmaddaz.xyzw ACC,vf3,vf23z" : :  : "memory");
    __asm__ volatile("vmaddw.xyzw vf23,vf4,vf23w" : :  : "memory");
    __asm__ volatile("vmulax.xyzw ACC,vf1,vf24x" : :  : "memory");
    __asm__ volatile("vmadday.xyzw ACC,vf2,vf24y" : :  : "memory");
    __asm__ volatile("vmaddaz.xyzw ACC,vf3,vf24z" : :  : "memory");
    __asm__ volatile("vmaddw.xyzw vf24,vf4,vf24w" : :  : "memory");
    __asm__ volatile("vmulax.xyzw ACC,vf1,vf25x" : :  : "memory");
    __asm__ volatile("vmadday.xyzw ACC,vf2,vf25y" : :  : "memory");
    __asm__ volatile("vmaddaz.xyzw ACC,vf3,vf25z" : :  : "memory");
    __asm__ volatile("vmaddw.xyzw vf25,vf4,vf25w" : :  : "memory");
    __asm__ volatile("sqc2 vf22,0(%0)" : : "r"((u8 *)a0) : "memory");
    __asm__ volatile("sqc2 vf23,16(%0)" : : "r"(a0) : "memory");
    __asm__ volatile("sqc2 vf24,32(%0)" : : "r"(a0) : "memory");
    __asm__ volatile("sqc2 vf25,48(%0)" : : "r"(a0) : "memory");
    return;
}

/* fsvu0_ApplyMatrix @ 0x14AA80 .. 0x14AAAC (0x2c bytes) */

void fsvu0_ApplyMatrix(float *a0 /* r4 */, void *a1 /* r5 */, float *a2 /* r6 */) {
    __asm__ volatile("lqc2 vf1,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("lqc2 vf2,16(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf3,32(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf4,48(%0)" : : "r"(a1) : "memory");
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a2) : "memory");
    __asm__ volatile("vmulax.xyzw ACC,vf1,vf16x" : :  : "memory");
    __asm__ volatile("vmadday.xyzw ACC,vf2,vf16y" : :  : "memory");
    __asm__ volatile("vmaddaz.xyzw ACC,vf3,vf16z" : :  : "memory");
    __asm__ volatile("vmaddw.xyzw vf16,vf4,vf16w" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}

/* fsvu0_AddVector @ 0x14AA60 .. 0x14AA74 (0x14 bytes) */

void fsvu0_AddVector(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("lqc2 vf17,0(%0)" : : "r"((u8 *)a2) : "memory");
    __asm__ volatile("vadd.xyz vf16,vf16,vf17" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}

/* fsvu0_SubVector @ 0x14AA40 .. 0x14AA54 (0x14 bytes) */

void fsvu0_SubVector(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("lqc2 vf17,0(%0)" : : "r"((u8 *)a2) : "memory");
    __asm__ volatile("vsub.xyz vf16,vf16,vf17" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}

/* fsvu0_ScaleVector @ 0x14AA20 .. 0x14AA3C (0x1c bytes) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

u32 fsvu0_ScaleVector(float *a0 /* r4 */, float *a1 /* r5 */, float f12 /* f12 */) {
    s32 v1;

    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a1) : "memory");
    v1 = ({ s32 native_result_0; __asm__("mfc1 %0,%1" : "=r"(native_result_0) : "f"(f12));
        native_result_0; });
    __asm__ volatile("qmtc2.ni %0,vf31" : : "r"(v1) : "memory");
    __asm__ volatile("vmulx.xyz vf16,vf16,vf31x" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}

/* fsvu0_OuterProduct @ 0x14AA00 .. 0x14AA18 (0x18 bytes) */

void fsvu0_OuterProduct(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("lqc2 vf17,0(%0)" : : "r"((u8 *)a2) : "memory");
    __asm__ volatile("vopmula.xyz ACC,vf16,vf17" : :  : "memory");
    __asm__ volatile("vopmsub.xyz vf16,vf17,vf16" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}

/* fsvu0_Normalize @ 0x14A9D0 .. 0x14AA00 (0x30 bytes) */

void fsvu0_Normalize(float *a0 /* r4 */, float *a1 /* r5 */) {
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)a1) : "memory");
    __asm__ volatile("vmul.xyz vf17,vf16,vf16" : :  : "memory");
    __asm__ volatile("vaddx.z vf17,vf17,vf17x" : :  : "memory");
    __asm__ volatile("vaddy.z vf17,vf17,vf17y" : :  : "memory");
    __asm__ volatile("vsqrt Q,vf17z" : :  : "memory");
    __asm__ volatile("vwaitq" : :  : "memory");
    __asm__ volatile("vmulq.xyzw vf17,vf0,Q" : :  : "memory");
    __asm__ volatile("vdiv Q,vf0w,vf17w" : :  : "memory");
    __asm__ volatile("vwaitq" : :  : "memory");
    __asm__ volatile("vmulq.xyz vf16,vf16,Q" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)a0) : "memory");
    return;
}
