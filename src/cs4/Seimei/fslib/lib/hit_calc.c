#include "common.h"

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
float InnerProduct(float *a0 , float *a1 );
void SubVector(float *a0 , float *a1 , float *a2 );
void OuterProduct(float *a0 , float *a1 , float *a2 );


/* InnerProduct @ 0x159670 .. 0x15969C (0x2c bytes) */
/*
 * dcomp notes:
 *   return: madd.s at 0x159698 computes the return value
 */

float InnerProduct(float *a0 /* r4 */, float *a1 /* r5 */) {
    return (((*(float *)a0 * *(float *)a1) + (float)(a0[1] * a1[1])) + (a0[2] * a1[2]));
}

/* SubVector @ 0x159630 .. 0x159664 (0x34 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */

void SubVector(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    *(f32 *)a0 = (*(float *)a1 - *(float *)a2);
    a0[1] = (a1[1] - a2[1]);
    a0[2] = (a1[2] - a2[2]);
    return;
}

/* OuterProduct @ 0x1595D0 .. 0x159628 (0x58 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred float
 */

void OuterProduct(float *a0 /* r4 */, float *a1 /* r5 */, float *a2 /* r6 */) {
    float f3;
    float f2;
    float f1;
    float f0;

    f3 = *(float *)(((u8 *)a1 + 4));
    f2 = *(float *)(((u8 *)a2 + 8));
    f1 = *(float *)(((u8 *)a1 + 8));
    f0 = *(float *)(((u8 *)a2 + 4));
    __asm__ volatile("mula.s %0,%1" : : "f"(f3), "f"(f2) : "memory");
    f0 = ({ float native_result_0; __asm__ volatile("msub.s %0,%1,%2" : "=f"(native_result_0) :
        "f"(f1), "f"(f0) : "memory"); native_result_0; });
    *(f32 *)a0 = f0;
    f3 = *(float *)(((u8 *)a1 + 8));
    f2 = *(float *)a2;
    f1 = *(float *)a1;
    f0 = *(float *)(((u8 *)a2 + 8));
    __asm__ volatile("mula.s %0,%1" : : "f"(f3), "f"(f2) : "memory");
    f0 = ({ float native_result_1; __asm__ volatile("msub.s %0,%1,%2" : "=f"(native_result_1) :
        "f"(f1), "f"(f0) : "memory"); native_result_1; });
    *(f32 *)(((u8 *)a0 + 4)) = f0;
    f3 = *(float *)a1;
    f2 = *(float *)(((u8 *)a2 + 4));
    f1 = *(float *)(((u8 *)a1 + 4));
    f0 = *(float *)a2;
    __asm__ volatile("mula.s %0,%1" : : "f"(f3), "f"(f2) : "memory");
    f0 = ({ float native_result_2; __asm__ volatile("msub.s %0,%1,%2" : "=f"(native_result_2) :
        "f"(f1), "f"(f0) : "memory"); native_result_2; });
    *(f32 *)(((u8 *)a0 + 8)) = f0;
    return;
}
