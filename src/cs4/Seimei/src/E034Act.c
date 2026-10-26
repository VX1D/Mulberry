#include "common.h"

/* E034ActAttack @ 0x1FFCF0 .. 0x1FFEE0 (0x1f0 bytes, frame 0xc0) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @860 -> 0x24f280
 *   fpu: mtc1 reinterprets v0 at 0x1ffd3c
 *   fpu: mtc1 reinterprets v1 at 0x1ffd54
 *   fpu: float literal 0x41200000 at 0x1ffd6c
 *   fpu: float literal 0x42540000 at 0x1ffd90
 *   stack: address of the slot at 0xa0 escapes at 0x1ffdbc
 *   fpu: float literal 0x40490fdb at 0x1ffdd4
 *   fpu: mov.s at 0x1ffdec is a float copy
 *   stack: address of the slot at 0x60 escapes at 0x1ffde8
 *   stack: address of the slot at 0x90 escapes at 0x1ffdf4
 *   stack: address of the slot at 0xb0 escapes at 0x1ffe04
 *   stack: address of the slot at 0x60 escapes at 0x1ffe04
 *   stack: address of the slot at 0xb0 escapes at 0x1ffe04
 *   stack: address of the slot at 0xb0 escapes at 0x1ffe1c
 *   stack: address of the slot at 0x80 escapes at 0x1ffe1c
 *   fpu: float literal 0x3c8ef34d at 0x1ffea8
 *   literal: @860 initializes the 16-byte local at 0xb0
 */

extern unsigned int CheckAnimNumFrame(void *, float);
extern void sceVu0CopyVector(void *, void *);
extern void SfxCalc_MakeMatrixFromPYR(void *, float, float, float);
extern void sceVu0ApplyMatrix(void *, void *, void *);
extern signed int SFX_Create_OnDir_Dmg(unsigned short, float *, float *, unsigned char, unsigned
    char);
extern unsigned int CheckAnimEndFrame(void *);
extern void SetEneAttackOff(void *, void *);
extern float Math_GotoAngle(float, float, float);
extern u32 L860[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E034ActInit(s32 a0 , u32 *a1 );
static void E034ActAttack(void *a0 , void *a1 );



/* E034ActInit @ 0x1FFEE0 .. 0x1FFEF0 (0x10 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */



u8 * E034ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)E034ActAttack;
    return;
}

static void E034ActAttack(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s3;
    u8 *s2;
    u8 t0;
    u8 *s1;
    u8 *s0;
    float f14;
    float f20;
    float f12;
    u32 v1;
    float f0;
    u32 v0;
    void *a1_2;

    s3 = (u8 *)a0;
    v0 = *(s32 *)(((u8 *)a0 + 0xc));
    s1 = (u8 *)*(s32 *)(((u8 *)a0 + 0x100));
    s0 = (u8 *)*(s32 *)((v0 + 0x4c));
    a0 = (void *)*(u8 *)(((u8 *)a0 + 0x12a));
    v0 = (u32)a0 << 2;
    v0 = (s32)((u8 *)v0 + (u32)(a0));
    v0 = v0 << 3;
    v0 = (s32)((u8 *)(u32)v0 + (u32)(s0));
    v0 = *(u16 *)((v0 + 0xaa));
    s2 = (u8 *)a1;
    f0 = 10.0f;
    f20 = ((float)(float)v0 / 10.0f);
    v0 = 2;
    if ((u32)(u8)a0 == v0) {
        f12 = 53.0f;
        v0 = CheckAnimNumFrame((void *)s1, 53.0f);
        if (v0 != 0) {
            v0 = (u32)L860;
            {
                struct stackFrame_B0 { u8 b[16]; } stackFrame_B0 __attribute__((aligned(16))) =
                    {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x80, 0x3f}};
                u8 stackFrame_A0[16] __attribute__((aligned(16)));
                u8 stackFrame_60[64] __attribute__((aligned(16)));
                v1 = (u32)((u8 *)&stackFrame_B0);
                sceVu0CopyVector((void *)((u8 *)&stackFrame_A0[0]), (void *)(s3 + 0x30));
                __asm__ volatile(
                    ".set noreorder\n"
                    "lwc1 $f1,0xa4($sp)\n"
                    "lui $2,0x4049\n"
                    "ori $2,$2,0xfdb\n"
                    "addiu $4,$sp,0x60\n"
                    "mtc1 $2,$f0\n"
                    "lwc1 $f12,0xa0($sp)\n"
                    "lwc1 $f14,0xa8($sp)\n"
                    "add.s $f0,$f1,$f0\n"
                    "swc1 $f0,0xa4($sp)\n"
                    "jal SfxCalc_MakeMatrixFromPYR\n"
                    "mov.s $f13,$f0\n"
                    ".set reorder\n"
                    : : : "memory");
                sceVu0CopyVector((void *)((u8 *)&stackFrame_60[48]), (void *)(u8 *)(s3 + 0x20));
                sceVu0ApplyMatrix((void *)((u8 *)&stackFrame_B0), (void *)(u8 *)((u8 *)&stackFrame_60[0]),
                    (void *)((u8 *)&stackFrame_B0));
                SFX_Create_OnDir_Dmg(0x1c7, (float *)(u8 *)((u8 *)&stackFrame_B0),
                    (float *)((u8 *)&stackFrame_60[32]), *(u8 *)s0, *(u8 *)(s3 + 0x12a));
            }
        }
    }
    v0 = CheckAnimEndFrame((void *)s1);
    if (v0 != 0) {
        __asm__ volatile(
            "lbu $3,0x12a(%0)\n"
            "sll $2,$3,2\n"
            "addu $2,$2,$3\n"
            "sll $2,$2,3\n"
            "addu $2,$2,%1\n"
            "lhu $2,0xb2($2)\n"
            "sw $2,0x1e8(%2)\n"
            : : "r"(s3), "r"(s0), "r"(s2) : "$2", "$3", "memory");
        v0 = *(s32 *)(s3 + 0x1b4);
        if (v0 != 0 && (u32)*(s32 *)(s2 + 0x1e8) != 0) {
            SetEneAttackOff((void *)s3, (void *)(u8 *)s2);
        } else {
            __asm__ volatile(
                ".set noreorder\n"
                "lw $2,0x100(%1)\n"
                "daddu $4,%0,$0\n"
                "daddu $5,%1,$0\n"
                "jalr $31,$2\n"
                "addiu $6,$0,2\n"
                "nop\n"
                ".set reorder\n"
                : : "r"(s3), "r"(s2) : "$2", "$4", "$5", "$6", "$31", "memory");
        }
        *(f32 *)(s3 + 0x198) = *(float *)(s3 + 0x34);
    }
    f0 = 0.0174499992f;
    f12 = *(float *)(s3 + 0x34);
    f0 = Math_GotoAngle(f12, *(float *)(s3 + 0x198), (0.0174499992f * f20));
    *(f32 *)(s3 + 0x34) = f0;
    return;
}
