#include "common.h"

/* CheckP030Counter @ 0x170930 .. 0x170AC8 (0x198 bytes, frame 0xa0) */
/*
 * dcomp notes:
 *   delay: addiu at 0x170998 writes a register its branch at 0x170994 reads
 *   stack: address of the slot at 0x70 escapes at 0x1709b8
 *   stack: address of the slot at 0x70 escapes at 0x1709d8
 *   stack: address of the slot at 0x60 escapes at 0x1709e8
 *   stack: address of the slot at 0x60 escapes at 0x1709fc
 *   fpu: float literal 0x40490fdb at 0x170a34
 *   fpu: float literal 0x00000000 at 0x170a38
 *   fpu: float literal 0x40c90fdb at 0x170a58
 *   fpu: mtc1 reinterprets v0 at 0x170a7c
 *   cfg: kept branch: 0x170998 if (..) goto .L001709B0
 *   cfg: kept goto: 0x1709a8 -> .L00170AA8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void * memset(void *, int, unsigned int);
extern void SetEneDamageProc(void *);
extern void sceVu0CopyVector(void *, void *);
extern float Math_VectorToAngle(float, float);


extern void SetHeartRate(void *, signed int, unsigned char);
extern signed int SFX_BurnModel(void *);
extern void SetMyDamage(void *, void *, unsigned short);
extern void SetMyDead(void *, void *, unsigned short);


/* CheckMyDamage @ 0x170F00 .. 0x17105C (0x15c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x170f10 writes a register its branch at 0x170f0c reads
 *   delay: daddu at 0x170f28 writes a register its branch at 0x170f24 reads
 *   delay: daddu at 0x170f40 writes a register its branch at 0x170f3c reads
 *   delay: daddu at 0x170f80 writes a register its branch at 0x170f7c reads
 *   delay: daddu at 0x170f9c writes a register its branch at 0x170f98 reads
 *   delay: daddu at 0x170fb0 writes a register its branch at 0x170fac reads
 *   delay: addiu at 0x170fcc writes a register its branch at 0x170fc8 reads
 *   delay: addiu at 0x170fe0 writes a register its branch at 0x170fdc reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int CheckNowFade(signed int);
extern signed int KnMsgMng_CheckMsgNone(void);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int CheckMyDamage(void *a0 , void *a1 );
void SetMyDamageProc(void *arg);
static signed int GetMyDamageAnim(void *a0 );
signed int CheckP030Counter(void *a0 , void *a1 );


signed int CheckMyDamage(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *a2;
    u32 v1;
    u32 v0;

    v0 = *(u8 *)a0;
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(s32 *)(((u8 *)a0 + 0x120));
    if ((s32)v0 <= 0) {
        v0 = 0;
        return v0;
    }
    v0 = *(s16 *)(((u8 *)a0 + 0x12c));
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    a2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x148));
    v0 = *(u8 *)(a2 + 0x18a);
    if (v0 != 0) {
        if ((u32)a1 == 0) {
            v0 = 0;
            return v0;
        }
        v1 = *(s32 *)(((u8 *)a1 + 0xc));
        v0 = 1;
        v1 = *(u16 *)((v1 + 0xa));
        if (v1 != v0) {
            v0 = 0;
            return v0;
        }
        v0 = *(s32 *)((*(s32 *)(((u8 *)a1 + 0x148)) + 0x1e4));
        if (v0 != (u32)a0) {
            v0 = 0;
            return v0;
        }
    }
    v0 = *(u8 *)(a2 + 0x189);
    if (v0 != 0) {
        v0 = 0;
        return v0;
    }
    v1 = *(u8 *)(a2 + 0x100);
    v0 = 0xc;
    a1 = (void *)(s32)6;
    switch (v1) {
    case 6:
    case 8:
    case 9:
    case 10:
    case 12:
        v0 = 0;
        return v0;
    default:
        v1 = *(s16 *)(((u8 *)a0 + 0x104));
        v0 = 0x28;
        switch (v1) {
        case 40:
            v0 = 0;
            return v0;
        }
    }
    v0 = CheckNowFade((s32)a1);
    if (v0 != 0) {
        v0 = 0;
    } else {
        v0 = KnMsgMng_CheckMsgNone();
        v0 = v0 != 0;
    }
    return v0;
}
void SetMyDamageProc(void *arg) {
    __asm__ volatile(
        ".set noreorder\n"
        "lbu $5,0x19($4)\n"
        "lw $18,0x10($4)\n"
        "lw $2,0x14($4)\n"
        "sll $3,$5,2\n"
        "addu $3,$3,$5\n"
        "lw $17,0x148($18)\n"
        "sll $3,$3,3\n"
        "addu $2,$2,$3\n"
        "lw $3,0xc($18)\n"
        "addiu $19,$2,0xa0\n"
        "lw $2,0xa0($2)\n"
        "lw $16,0x4c($3)\n"
        ".word 0x04400004\n"
        "daddu $20,$4,$0\n"
        "mtc1 $2,$f0\n"
        ".word 0x10000008\n"
        "cvt.s.w $f1,$f0\n"
        "srl $3,$2,1\n"
        "andi $2,$2,1\n"
        "or $3,$3,$2\n"
        "mtc1 $3,$f0\n"
        "nop\n"
        "cvt.s.w $f1,$f0\n"
        "add.s $f1,$f1,$f1\n"
        "lwc1 $f0,0x20($20)\n"
        "daddu $4,$18,$0\n"
        "mul.s $f0,$f1,$f0\n"
        ".word 0x46000024\n"
        "mfc1 $5,$f0\n"
        "jal SetHeartRate\n"
        "daddu $6,$0,$0\n"
        "lbu $2,0x17($19)\n"
        ".word 0x10400004\n"
        "nop\n"
        "jal SFX_BurnModel\n"
        "daddu $4,$18,$0\n"
        "nop\n"
        "jal GetMyDamageAnim\n"
        "daddu $4,$20,$0\n"
        "lw $3,0x120($18)\n"
        ".word 0x18600018\n"
        "nop\n"
        "lh $4,0x104($18)\n"
        "addiu $3,$0,0x7a\n"
        ".word 0x10830018\n"
        "nop\n"
        "addiu $3,$0,0x6c\n"
        ".word 0x10830015\n"
        "nop\n"
        "addiu $3,$0,0x4e\n"
        ".word 0x10830012\n"
        "nop\n"
        "addiu $3,$0,0x66\n"
        ".word 0x1083000f\n"
        "nop\n"
        "addiu $3,$0,0x48\n"
        ".word 0x1083000c\n"
        "nop\n"
        "nop\n"
        "daddu $5,$17,$0\n"
        "andi $6,$2,0xffff\n"
        "jal SetMyDamage\n"
        "daddu $4,$18,$0\n"
        ".word 0x10000005\n"
        "nop\n"
        "daddu $5,$17,$0\n"
        "andi $6,$2,0xffff\n"
        "jal SetMyDead\n"
        "daddu $4,$18,$0\n"
        "lhu $4,0x36($16)\n"
        ".word 0x14800002\n"
        "nop\n"
        "addiu $4,$0,0x3c\n"
        "lbu $3,0x19($19)\n"
        "subu $3,$4,$3\n"
        "sh $3,0x12c($18)\n"
        "lh $3,0x12c($18)\n"
        ".word 0x04610003\n"
        "nop\n"
        "sh $0,0x12c($18)\n"
        "nop\n"
        ".set reorder\n"
        :
        :
        : "memory");
}


static signed int GetMyDamageAnim(void *a0 /* r4 */) {
    u8 *s1;
    float f3;
    u32 a1;
    float f2;
    u32 v1;
    float f1;
    float f0;
    u32 v0;
    u8 *s0;

    s0 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    s1 = (u8 *)(*(u32 *)((u8 *)a0 + 0x14) + *(u8 *)((u8 *)a0 + 0x19) * 40 + 0xa0);
    f0 = Math_VectorToAngle((*(float *)(s0 + 0x20) - *(float *)a0), (*(float *)(s0 + 0x28) -
        *(float *)(((u8 *)a0 + 8))));
    f3 = (f0 - *(float *)(s0 + 0x34));
    if (3.1415927f + f3 >= 0.0f) {
        f2 = f3 - 6.2831855f * (float)(s32)((3.1415927f + f3) / 6.2831855f);
    } else {
        f2 = 6.2831855f + (f3 - 6.2831855f * (float)(s32)((3.1415927f + f3) / 6.2831855f));
    }
    v1 = *(s16 *)(s0 + 0x104);
    v0 = 0x6c;
    switch (v1) {
    case 70:
    case 71:
    case 72:
    case 100:
    case 101:
    case 102:
    case 122:
        v0 = (s16)v1;
        break;
    case 76:
    case 77:
    case 78:
    case 106:
    case 107:
    case 108:
        v0 = (s16)v1;
        break;
    default:
        v0 = *(u8 *)(s1 + 7);
        if (v0 == 0) {
            v0 = *(s32 *)(s0 + 0x120);
            if ((s32)v0 > 0) {
                f1 = f2 < 0.0f ? -f2 : (float)f2;
                if (f1 < 0.78524995f) {
                    v0 = 0xf;
                    return v0;
                }
                f1 = f2 < 0.0f ? -f2 : (float)f2;
                if (!(f1 <= 2.3557498f)) {
                    v0 = 0x10;
                    return v0;
                }
                f0 = 0.0f;
                if (f2 < 0.0f) {
                    v0 = 0x15;
                    return v0;
                }
                if (f2 <= f0) {
                    goto _L00170D60;
                }
                v0 = 0x14;
                return v0;
            }
            f2 = f2 < 0.0f ? -f2 : f2;
            if (f2 < 1.5704999f) {
                v0 = 0x1e;
                return v0;
            }
            v0 = 0x1f;
            return v0;
        }
        _L00170D60:;
        v0 = -1;
    }
    return v0;
}

signed int CheckP030Counter(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s4;
    u32 *s3;
    u8 *s2;
    u8 *s1;
    u8 *s0;
    u32 v1;
    float f13;
    u32 v0;
    float f12;
    float f3;
    float f2;
    float f1;
    float f0;
    void *a1_2;
    u8 stackFrame_70[48] __attribute__((aligned(16)));
    float DmgPos[4] __attribute__((aligned(16)));

    s4 = (u32)a1;
    s2 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    s1 = (u8 *)*(s32 *)(s2 + 0x148);
    v1 = *(s32 *)(s1 + 0x1b4);
    s3 = (u32 *)a0;
    if (v1 == 0) {
        v0 = 0;
    } else {
        v0 = *(u8 *)v1;
        if (v0 == 0) {
            *(u32 *)(s1 + 0x1b4) = 0;
            v0 = 0;
        } else {
            s0 = (u8 *)*(s32 *)((v1 + 0x148));
            v0 = 3;
            v1 = *(u8 *)(s0 + 0x180);
            if (v1 != v0) {
                v0 = 4;
                if (v1 != v0) {
                    goto _L001709B0;
                }
            }
            v0 = 1;
            goto _L00170AA8;
            _L001709B0:;
            memset((void *)((u8 *)&stackFrame_70[0]), 0, 0x30);
            v0 = *(s32 *)(s1 + 0x1b4);
            ((u32 *)stackFrame_70)[4] = v0;
            v0 = (s32)s3[5];
            ((u32 *)stackFrame_70)[5] = v0;
            ((f32 *)stackFrame_70)[8] = *(float *)(s0 + 0x250);
            SetEneDamageProc((void *)((u8 *)&stackFrame_70[0]));
            a1_2 = (void *)(s32)(s4 + 0x20);
            if (s4 != 0) {
                sceVu0CopyVector(DmgPos, a1_2);
            } else {
                a1_2 = (void *)s3;
                sceVu0CopyVector(DmgPos, a1_2);
            }
            f0 = Math_VectorToAngle(-(DmgPos[0] - *(float *)(s2 + 0x20)), -(DmgPos[2] - *(float *)(s2 + 0x28)));
            f2 = 3.14159274f;
            f1 = 0.0f;
            f3 = (3.14159274f + f0);
            if (f3 >= 0.0f) {
                v0 = 0x40c90fdb;
                f2 = 6.28318548f;
                f0 = ((float)f0 - (6.28318548f * (float)((float)(s32)(f3 / 6.28318548f))));
            } else {
                v0 = 0x40c90fdb;
                f2 = 6.28318548f;
                f0 = (f2 + (f0 - (f2 * (float)((float)(s32)(f3 / f2)))));
            }
            v1 = *(s32 *)(s1 + 0x1b4);
            v0 = 1;
            *(f32 *)((v1 + 0x34)) = f0;
        }
    }
    _L00170AA8:;
    return v0;
}
