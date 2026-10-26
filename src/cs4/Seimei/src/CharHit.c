#include "common.h"

/* CheckHitObstructMdl @ 0x1597E0 .. 0x159894 (0xb4 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1597f8 is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x1597fc
 *   stack: address of the slot at 0x50 escapes at 0x159814
 *   stack: address of the slot at 0x70 escapes at 0x159830
 *   stack: address of the slot at 0x50 escapes at 0x159830
 *   stack: address of the slot at 0x60 escapes at 0x159830
 *   delay: lui at 0x159858 writes a register its branch at 0x159854 reads
 *   fpu: float literal 0x3f800000 at 0x15986c
 *   delay: lui at 0x159878 writes a register its branch at 0x159874 reads
 *   fpu: float literal 0x3f800000 at 0x15987c
 *   cfg: kept branch: 0x159858 if (..) goto .L00159870
 */

extern void sceVu0CopyVector(void *, void *);
extern void sceVu0SubVector(void *, void *, void *);
extern float CheckHitMapLineGetNormal(void *, void *, void *);

/* CheckHitChar @ 0x159A30 .. 0x159BE0 (0x1b0 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x159a38 writes a register its branch at 0x159a34 reads
 *   delay: daddu at 0x159a50 writes a register its branch at 0x159a4c reads
 *   fpu: float literal 0x38d1b717 at 0x159b00
 *   fpu: float literal 0x3dcccccd at 0x159b2c
 *   fpu: float literal 0x3dcccccd at 0x159ba8
 *   cfg: loop body is not one contiguous region: .L00159A78
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

extern u32 MdlMng[];


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
unsigned int CheckHitChar(void *a0 );
unsigned int CheckHitTargetMdl(void *a0 , void *a1 , signed int a2 );
float CheckHitObstructLine(void *a0 , float f12 , float f13 );
float CheckHitObstructMdl(void *a0 , void *a1 , float f12 );


unsigned int CheckHitChar(void *a0 /* r4 */) {
    u8 *a1;
    u8 *end;
    u8 *a0_bytes;
    u32 v0;
    u32 result;

    a0_bytes = (u8 *)a0;
    v0 = *(u8 *)(a0_bytes + 0x130);
    if (v0 != 0) {
        return 0;
    }
    v0 = *(u8 *)(a0_bytes + 0x133);
    if (v0 != 0) {
        return 0;
    }
    a1 = (u8 *)(MdlMng + 0x4600);
    end = (u8 *)(MdlMng + 0x5fd0);
    __asm__ volatile(
        ".set noreorder\n"
        "beq %1, %2, CheckHitCharAsm_ReturnZero\n"
        "nop\n"
        "CheckHitCharAsm_Loop:\n"
        "lbu %0, 0x0(%1)\n"
        "beqz %0, CheckHitCharAsm_Skip\n"
        "nop\n"
        "beq %1, $4, CheckHitCharAsm_Skip\n"
        "nop\n"
        "lbu %0, 0x130(%1)\n"
        "bnez %0, CheckHitCharAsm_Skip\n"
        "nop\n"
        "lwc1 $f6, 0x24(%1)\n"
        "lwc1 $f5, 0x24($4)\n"
        "lwc1 $f0, 0x114(%1)\n"
        "lwc1 $f4, 0x28(%1)\n"
        "lwc1 $f3, 0x28($4)\n"
        "lwc1 $f8, 0x20(%1)\n"
        "lwc1 $f7, 0x20($4)\n"
        "sub.s $f6, $f6, $f5\n"
        "lwc1 $f2, 0x110(%1)\n"
        "lwc1 $f1, 0x110($4)\n"
        "sub.s $f5, $f4, $f3\n"
        "sub.s $f9, $f8, $f7\n"
        "neg.s $f0, $f0\n"
        "add.s $f4, $f2, $f1\n"
        "mula.s $f9, $f9\n"
        "c.lt.s $f6, $f0\n"
        "bc1t CheckHitCharAsm_Skip\n"
        "madd.s $f1, $f5, $f5\n"
        "lwc1 $f0, 0x114($4)\n"
        "c.le.s $f6, $f0\n"
        "bc1f CheckHitCharAsm_Skip\n"
        "mul.s $f0, $f4, $f4\n"
        "c.le.s $f1, $f0\n"
        "bc1f CheckHitCharAsm_Skip\n"
        "lui %0, 0x38D1\n"
        "ori %0, %0, 0xB717\n"
        "mtc1 %0, $f0\n"
        "nop\n"
        "c.le.s $f1, $f0\n"
        "bc1t CheckHitCharAsm_Small\n"
        "nop\n"
        "nop\n"
        "nop\n"
        ".word 0x46010084\n"
        "CheckHitCharAsm_Away:\n"
        "lui %0, 0x3DCC\n"
        "ori %0, %0, 0xCCCD\n"
        "sub.s $f0, $f4, $f2\n"
        "mtc1 %0, $f3\n"
        "nop\n"
        "c.le.s $f0, $f3\n"
        "bc1t CheckHitCharAsm_Near\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "div.s $f1, $f9, $f2\n"
        "div.s $f0, $f5, $f2\n"
        "mul.s $f1, $f3, $f1\n"
        "sub.s $f2, $f7, $f1\n"
        "mul.s $f1, $f3, $f0\n"
        "swc1 $f2, 0x20($4)\n"
        "lwc1 $f0, 0x28($4)\n"
        "sub.s $f0, $f0, $f1\n"
        "b CheckHitCharAsm_Success\n"
        "swc1 $f0, 0x28($4)\n"
        "CheckHitCharAsm_Near:\n"
        "nop\n"
        "div.s $f1, $f9, $f2\n"
        "div.s $f0, $f5, $f2\n"
        "mul.s $f1, $f4, $f1\n"
        "sub.s $f1, $f8, $f1\n"
        "swc1 $f1, 0x20($4)\n"
        "lwc1 $f1, 0x28(%1)\n"
        "mul.s $f0, $f4, $f0\n"
        "sub.s $f0, $f1, $f0\n"
        "b CheckHitCharAsm_Success\n"
        "swc1 $f0, 0x28($4)\n"
        "nop\n"
        "CheckHitCharAsm_Small:\n"
        "lui %0, 0x3DCC\n"
        "ori %0, %0, 0xCCCD\n"
        "mtc1 %0, $f0\n"
        "nop\n"
        "add.s $f0, $f0, $f8\n"
        "swc1 $f0, 0x20($4)\n"
        "CheckHitCharAsm_Success:\n"
        "b CheckHitCharAsm_Exit\n"
        "addiu %0, $zero, 1\n"
        "CheckHitCharAsm_Skip:\n"
        "addiu %1, %1, 0x1C0\n"
        "bne %1, %2, CheckHitCharAsm_Loop\n"
        "nop\n"
        "nop\n"
        "CheckHitCharAsm_ReturnZero:\n"
        "daddu %0, $zero, $zero\n"
        "nop\n"
        "CheckHitCharAsm_Exit:\n"
        ".set reorder\n"
        : "=r"(result)
        : "r"(a1), "r"(end)
        : "memory"
    );
    return result;
}

/* CheckHitTargetMdl @ 0x159970 .. 0x159A28 (0xb8 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x159980 writes a register its branch at 0x15997c reads
 *   delay: daddu at 0x159998 writes a register its branch at 0x159994 reads
 *   cfg: kept branch: 0x1599f0 if (..) goto .L00159A08
 *   cfg: kept goto: 0x159a00 -> .L00159A20
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */

unsigned int CheckHitTargetMdl(void *a0 /* r4 */, void *a1 /* r5 */, signed int a2 /* r6 */) {
    u32 v0;
    float f7;
    float f6;
    float f5;
    float fp_acc_load_2; // f5
    float f4;
    float f3;
    float fp_acc_load_3; // f3
    float f2;
    float fp_acc_load_4; // f2
    float f1;
    float fp_acc_load_0; // f1
    float fp_acc_load_5; // f1
    float f0;
    float fp_acc_load_1; // f0

    if ((u32)(s32)a2 != 0) {
        v0 = *(u8 *)(((u8 *)a0 + 0x130));
        if (v0 != 0) {
            v0 = 0;
            return v0;
        }
        v0 = *(u8 *)(((u8 *)a1 + 0x130));
        if (v0 != 0) {
            v0 = 0;
            return v0;
        }
    }
    fp_acc_load_0 = *(float *)(((u8 *)a1 + 0x20));
    fp_acc_load_1 = *(float *)(((u8 *)a0 + 0x20));
    f6 = *(float *)(((u8 *)a1 + 0x24));
    fp_acc_load_2 = *(float *)(((u8 *)a0 + 0x24));
    f4 = *(float *)(((u8 *)a1 + 0x28));
    fp_acc_load_3 = *(float *)(((u8 *)a0 + 0x28));
    fp_acc_load_4 = *(float *)(((u8 *)a1 + 0x110));
    f7 = (fp_acc_load_0 - fp_acc_load_1);
    fp_acc_load_5 = *(float *)(((u8 *)a0 + 0x110));
    f5 = (f6 - fp_acc_load_2);
    f3 = (f4 - fp_acc_load_3);
    f0 = (-*(float *)(((u8 *)a1 + 0x114)));
    f2 = (fp_acc_load_4 + fp_acc_load_5);
    f1 = ((float)(f7 * f7) + (f3 * f3));
    if (!(f5 < f0)) {
        f0 = *(float *)(((u8 *)a0 + 0x114));
        if (f5 <= f0) {
            goto _L00159A08;
        }
    }
    v0 = 0;
    goto _L00159A20;
    _L00159A08:;
    f0 = (f2 * f2);
    v0 = f1 > f0;
    v0 = v0 ^ 1;
    _L00159A20:;
    return v0;
}

/* CheckHitObstructLine @ 0x1598A0 .. 0x159968 (0xc8 bytes, frame 0x70) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1598bc is a float copy
 *   fpu: mov.s at 0x1598c8 is a float copy
 *   stack: address of the slot at 0x50 escapes at 0x1598c4
 *   delay: lui at 0x159924 writes a register its branch at 0x159920 reads
 *   fpu: float literal 0x3f800000 at 0x15993c
 *   delay: lui at 0x159948 writes a register its branch at 0x159944 reads
 *   fpu: float literal 0x3f800000 at 0x15994c
 *   cfg: kept branch: 0x159924 if (..) goto .L00159940
 */




float CheckHitObstructLine(void *a0 /* r4 */, float f12 /* f12 */, float f13 /* f13 */) {
    float *s0;
    float *a1;
    float f21;
    float f20;
    float f0;
    u32 v1;
    s32 v0;
    s32 branchcond_159944;
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_30[32] __attribute__((aligned(16)));

    s0 = (float *)a0;
    f21 = f12;
    a1 = (float *)((u8 *)s0 + 0x20);
    f20 = f13;
    sceVu0CopyVector((void *)(float *)((u8 *)&stackFrame_50[0]), (void *)a1);
    ((f32 *)stackFrame_50)[1] = (((float *)stackFrame_50)[1] - f21);
    f12 = s0[0xd];
    f20 = (-f20);
    f0 = sinf(f12);
    *(f32 *)((u8 *)&stackFrame_60[0]) = (f20 * f0);
    f12 = s0[0xd];
    f0 = cosf(f12);
    a0 = (void *)((u8 *)&stackFrame_50[0]);
    a1 = (float *)((u8 *)&stackFrame_60[0]);
    ((u32 *)stackFrame_60)[3] = 0;
    ((u32 *)stackFrame_60)[1] = 0;
    ((f32 *)stackFrame_60)[2] = (f20 * f0);
    f0 = CheckHitMapLineGetNormal(a0, (void *)a1, (void *)(u8 *)((u8 *)&stackFrame_30[0]));
    v1 = ((s32 *)stackFrame_30)[4];
    v0 = 0x200000;
    v0 = v1 & 0x200000;
    if ((u32)v0 == 0) {
        v0 = 0x400000;
        v0 = v1 & 0x400000;
        if ((u32)v0 == 0) {
            goto _L00159940;
        }
    }
    v0 = 0x3f800000;
    f0 = 1.0f;
    _L00159940:;
    v0 = v1 & 1;
    branchcond_159944 = (u32)v0 == 0;
    v0 = 0x3f800000;
    if (!branchcond_159944) {
        f0 = 1.0f;
    }
    return f0;
}

float CheckHitObstructMdl(void *a0 /* r4 */, void *a1 /* r5 */, float f12 /* f12 */) {
    u32 s0;
    u8 *a2;
    float f20;
    float f0;
    u32 v1;
    s32 v0;
    s32 branchcond_159874;
    u8 stackFrame_70[16] __attribute__((aligned(16)));
    u8 stackFrame_60[16] __attribute__((aligned(16)));
    u8 stackFrame_50[16] __attribute__((aligned(16)));
    u8 stackFrame_30[32] __attribute__((aligned(16)));

    s0 = (u32)a1;
    a1 = (void *)((u8 *)a0 + 0x20);
    f20 = f12;
    sceVu0CopyVector((void *)((u8 *)&stackFrame_60[0]), a1);
    a1 = (void *)(s32)(s0 + 0x20);
    a0 = (void *)((u8 *)&stackFrame_50[0]);
    ((f32 *)stackFrame_60)[1] = (((float *)stackFrame_60)[1] - f20);
    sceVu0CopyVector(a0, a1);
    a0 = (void *)((u8 *)&stackFrame_70[0]);
    a1 = (void *)((u8 *)&stackFrame_50[0]);
    ((f32 *)stackFrame_50)[1] = (((float *)stackFrame_50)[1] - f20);
    sceVu0SubVector(a0, a1, (void *)(u8 *)((u8 *)&stackFrame_60[0]));
    a0 = (void *)((u8 *)&stackFrame_60[0]);
    a1 = (void *)((u8 *)&stackFrame_70[0]);
    a2 = ((u8 *)&stackFrame_30[0]);
    f0 = CheckHitMapLineGetNormal(a0, a1, (void *)a2);
    v1 = ((s32 *)stackFrame_30)[4];
    v0 = 0x200000;
    v0 = v1 & 0x200000;
    if ((u32)v0 == 0) {
        v0 = 0x400000;
        v0 = v1 & 0x400000;
        if ((u32)v0 == 0) {
            goto _L00159870;
        }
    }
    v0 = 0x3f800000;
    f0 = 1.0f;
    _L00159870:;
    v0 = v1 & 1;
    branchcond_159874 = (u32)v0 == 0;
    v0 = 0x3f800000;
    if (!branchcond_159874) {
        f0 = 1.0f;
    }
    return f0;
}
