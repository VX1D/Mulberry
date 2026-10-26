#include "common.h"
#include "MathUtil.h"

#define REVOLUTIONS(angle) (TWO_PI * (int) ((PI + angle) / TWO_PI))

float V0[4]; // size: 0x10, address: 0x3A5E40
float V1[4] = {1.0, 1.0, 1.0, 1.0}; // size: 0x10, address: 0x2286F0
float VX[4] = {1.0, 0.0, 0.0, 0.0}; // size: 0x10, address: 0x228700
float VY[4] = {0.0, 1.0, 0.0, 0.0}; // size: 0x10, address: 0x228710
float VZ[4] = {0.0, 0.0, 1.0, 0.0}; // size: 0x10, address: 0x228720
float VW[4] = {0.0, 0.0, 0.0, 1.0}; // size: 0x10, address: 0x228730
float MRX1[4][4] = {
    {1.0, 0.0, 0.0, 0.0},
    {0.0, 1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0, 0.0},
    {0.0, 0.0, 0.0, 1.0},
}; 

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
float Math_VectorToAngle(float xx, float zz);
void Math_VectorToAngleXY(float* Ang, float* Vec);
float Math_GotoAngle(float f12 , float f13 , float f14 );
float Math_GetDist(float*v1 , float*v2);
float Math_GetDist2(float* v1, float* v2);
float Math_GetDistXZ(float* v1, float* v2);
float Math_GetAngle360(float ang);
float Math_GetAngleDist(float ang1, float ang2);
u_int Math_GotoVectorXZ(float*now, float*end, float add);
u_int Math_GotoVector(float*now, float*end, float add);
u_int Math_GotoVector2(float*now, float*end, float per, float min, float max);
float Math_GetPosToAngle(float*pos1, float*pos2);


float Math_VectorToAngle(float xx, float zz) {
    float Angle;
 
    if (zz != 0.0f) {
        Angle = atanf(xx / -zz);
        
        if (-zz > 0.0f) {
            if (xx > 0.0f) Angle -= PI;
            else Angle += PI;
        }
    }
        
    else if (xx > 0.0f) Angle = -HALF_PI;
    else Angle = HALF_PI;

    if (PI - Angle >= 0.0f) return -Angle - REVOLUTIONS(-Angle);
    return TWO_PI + (-Angle - REVOLUTIONS(-Angle));
}

void Math_VectorToAngleXY(float* Ang, float* Vec) {
    float dist = sqrtf(Vec[0] * Vec[0] + Vec[2] * Vec[2]);

    if (dist == 0.0f) {
        if (Vec[1] < 0.0f) Ang[0] = HALF_PI;
        else if (Vec[1] > 0.0f) Ang[0] = -HALF_PI;
        else Ang[0] = 0.0f;
    } else {
        // treat distance as x-axis
        Ang[0] = atanf(-Vec[1] / dist);
    }
    
    Ang[1] = atan2f(Vec[0], Vec[2]);
    Ang[3] = Ang[2] = 0;
}

/* Math_GotoAngle @ 0x13B960 .. 0x13BA50 (0xf0 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x13b96c
 *   fpu: float literal 0x40c90fdb at 0x13b984
 *   fpu: float literal 0xc0490fdb at 0x13b998
 *   fpu: float literal 0x40c90fdb at 0x13b9b0
 *   fpu: float literal 0x40490fdb at 0x13b9d4
 *   fpu: float literal 0x40c90fdb at 0x13b9f0
 *   fpu: float literal 0xc0490fdb at 0x13ba18
 *   fpu: float literal 0x40c90fdb at 0x13ba34
 *   fpu: mov.s at 0x13ba40 is a float copy
 *   fpu: mov.s at 0x13ba4c is a float copy
 *   return: mov.s at 0x13ba4c computes the return value
 */

float Math_GotoAngle(float f12 /* f12 */, float f13 /* f13 */, float f14 /* f14 */) {
    float f1;
    float f0;

    f1 = f13 - f12;
    f0 = 3.14159274f;
    if (f1 > f0) {
        f0 = 6.28318548f;
        f1 = f1 - 6.28318548f;
    } else {
        f0 = -3.14159274f;
        if (f1 < f0) {
            f0 = 6.28318548f;
            f1 = f1 + 6.28318548f;
        }
    }
    if (f1 > f14) {
        f12 = f12 + f14;
        f0 = 3.14159274f;
        if (f12 > f0) {
            f0 = 6.28318548f;
            f12 = f12 - 6.28318548f;
        }
    } else {
        f0 = -f14;
        if (f1 < f0) {
            f12 = f12 - f14;
            f0 = -3.14159274f;
            if (f12 < f0) {
                f0 = 6.28318548f;
                f12 = f12 + 6.28318548f;
            }
        } else {
            f12 = (float)f13;
        }
    }
    return (float)f12;
}

/* Math_GetDist @ 0x13B920 .. 0x13B95C (0x3c bytes, frame 0x10) */

float Math_GetDist(float*v1 /* r3 */, float*v2) {
    u8 *v0;
    u8 stackFrame_0[16] __attribute__((aligned(16)));

    v0 = ((u8 *)&stackFrame_0[0]);
    __asm__ volatile("lqc2 vf16,0(%0)" : : "r"((u8 *)v1) : "memory");
    __asm__ volatile("lqc2 vf17,0(%0)" : : "r"((u8 *)v2) : "memory");
    __asm__ volatile("vsub.xyz vf16,vf17,vf16" : :  : "memory");
    __asm__ volatile("vmul.xyz vf17,vf16,vf16" : :  : "memory");
    __asm__ volatile("vaddx.z vf17,vf17,vf17x" : :  : "memory");
    __asm__ volatile("vaddy.z vf17,vf17,vf17y" : :  : "memory");
    __asm__ volatile("vsqrt Q,vf17z" : :  : "memory");
    __asm__ volatile("vwaitq" : :  : "memory");
    __asm__ volatile("vaddq.x vf16,vf0,Q" : :  : "memory");
    __asm__ volatile("sqc2 vf16,0(%0)" : : "r"((u8 *)v0) : "memory");
    return *(float *)((u8 *)&stackFrame_0[0]);
}

float Math_GetDist2(float* v1, float* v2) {
    float dx;
    float dy;
    float dz;

    dx = v2[0] - v1[0];
    dy = v2[1] - v1[1];
    dz = v2[2] - v1[2];

    return dx * dx + dy * dy + dz * dz;
}

float Math_GetDistXZ(float* v1, float* v2) {
    float dx;
    float dz;
    float dd;

    dx = v2[0] - v1[0];
    dz = v2[2] - v1[2];
    dd = sqrtf(dx * dx + dz * dz);

    return dd;
}

float Math_GetAngle360(float ang) {
    return ang >= 0.0f ? ang : ang + TWO_PI;

}


/* Math_GetAngleDist @ 0x13B700 .. 0x13B85C (0x15c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x13b708
 *   fpu: float literal 0x00000000 at 0x13b70c
 *   fpu: float literal 0x40c90fdb at 0x13b72c
 *   fpu: mtc1 reinterprets v0 at 0x13b750
 *   fpu: float literal 0x40490fdb at 0x13b778
 *   fpu: float literal 0x00000000 at 0x13b77c
 *   fpu: float literal 0x40c90fdb at 0x13b79c
 *   fpu: mtc1 reinterprets v0 at 0x13b7c0
 *   fpu: float literal 0x40490fdb at 0x13b7ec
 *   fpu: float literal 0x00000000 at 0x13b7f0
 *   fpu: float literal 0x40c90fdb at 0x13b810
 *   fpu: mtc1 reinterprets v0 at 0x13b834
 */

float Math_GetAngleDist(float ang1, float ang2) {
    float f3;
    float fp_rhs_value_0; // f3
    float f2;
    float f1;
    u32 v0;
    float f0;

    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + ang2);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f3 = (ang2 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f3 = (f1 + (ang2 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + ang1);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (ang1 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (ang1 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    fp_rhs_value_0 = (f0 - f3);
    f1 = 3.14159274f;
    f0 = 0.0f;
    f2 = (3.14159274f + fp_rhs_value_0);
    if (f2 >= 0.0f) {
        v0 = 0x40c90fdb;
        f1 = 6.28318548f;
        f0 = (fp_rhs_value_0 - (6.28318548f * (float)((float)(s32)(f2 / 6.28318548f))));
    } else {
        f1 = 6.28318548f;
        f0 = (f1 + (fp_rhs_value_0 - (f1 * (float)((float)(s32)(f2 / f1)))));
    }
    return f0;
}


/* Math_GotoVectorXZ @ 0x13B530 .. 0x13B6FC (0x1cc bytes, frame 0x40) */
u_int Math_GotoVectorXZ(float*now, float*end, float add) {
    float *s1;
    float *s0;
    float f13;
    float f5;
    float f20;
    register float rx, ry;
    float f23;
    float f2;
    u32 v0;
    float f1;
    float f0;

    f0 = 0.0f;
    s1 = (float *)now;
    s0 = (float *)end;
    f2 = now[2];
    f1 = end[2];
    f20 = (float)add;
    rx = (*(float *)now - *(float *)end);
    ry = (f2 - f1);
    if (0.0f == rx) {
        if (f0 == f5) {
            if (f0 == ry) {
                v0 = 2;
                return v0;
            }
        }
    }
    f0 = ((float)(rx * rx) + (ry * ry));
    f13 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"(f0));
        native_result_0; });
    if (f13 <= f20) {
        v0 = 1;
        *(f32 *)s1 = *(float *)s0;
        s1[2] = s0[2];
    } else {
        float angle0;
        add = 0.0f;
        f0 = atan2f(0.0f, f13);
        f13 = ry;
        angle0 = f0;
        f0 = atan2f((float)rx, f13);
        add = angle0;
        rx = *(float *)s1;
        ry = s1[2];
        f23 = f0;
        f0 = cosf(add);
        f20 = (f20 * f0);
        f0 = sinf((float)f23);
        f0 = (f20 * (float)f0);
        add = f23;
        *(f32 *)s1 = (*(float *)s1 - f0);
        f0 = cosf(add);
        f1 = f20 * f0;
        f0 = s1[2];
        s1[2] = f0 - f1;
        f1 = *(float *)s1;
        if (!(f1 <= rx)) {
            f0 = *(float *)s0;
            if (!(f1 <= f0)) {
                goto _L0013B680;
            }
        }
        if (f1 < rx) {
            f0 = *(float *)s0;
            if (f1 < f0) {
                _L0013B680:;
                *(f32 *)s1 = f0;
            }
        }
        f1 = s1[2];
        if (!(f1 <= ry)) {
            f0 = s0[2];
            if (!(f1 <= f0)) {
                goto _L0013B6C8;
            }
        }
        if (f1 < ry) {
            f0 = s0[2];
            if (f1 < f0) {
                _L0013B6C8:;
                s1[2] = f0;
            }
        }
        v0 = 0;
    }
    return v0;
}


/* Math_GotoVector @ 0x13B2C0 .. 0x13B530 (0x270 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x13b2c8
 *   fpu: mov.s at 0x13b310 is a float copy
 *   fpu: mov.s at 0x13b3a8 is a float copy
 *   fpu: mov.s at 0x13b3ac is a float copy
 *   fpu: mov.s at 0x13b3b4 is a float copy
 *   fpu: mov.s at 0x13b3c4 is a float copy
 *   fpu: mov.s at 0x13b3cc is a float copy
 *   fpu: mov.s at 0x13b3d8 is a float copy
 *   fpu: mov.s at 0x13b3e8 is a float copy
 *   fpu: mov.s at 0x13b3fc is a float copy
 *   cfg: kept branch: 0x13b42c if (..) goto .L0013B460
 *   cfg: kept branch: 0x13b478 if (..) goto .L0013B4A8
 *   cfg: kept branch: 0x13b4c0 if (..) goto .L0013B4F0
 *   declaration vs inferred signature: return u_int vs inferred u32
 */

u_int Math_GotoVector(float*now, float*end, float add) {
    float *s1;
    float *s0;
    float f13;
    float f4;
    float f3;
    float f2;
    float f23;
    float f26;
    float f1;
    float f25;
    u32 v0;
    float f0;
    float f24;
    float f22;
    float f21;
    float f20;

    s1 = (float *)now;
    s0 = (float *)end;
    f4 = now[1];
    f3 = end[1];
    f23 = (float)add;
    f20 = (*(float *)now - *(float *)end);
    add = (f4 - f3);
    f21 = (now[2] - end[2]);
    if (0.0f == f20) {
        if (0.0f == f21) {
            v0 = 2;
            return v0;
        }
    }
    f1 = (f20 * f20);
    f2 = (f21 * f21);
    f0 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"((f2 + (f1 +
        (add * add))))); native_result_0; });
    if (f0 <= f23) {
        v0 = 1;
        *(f32 *)s1 = *(float *)s0;
        s1[1] = s0[1];
        s1[2] = s0[2];
    } else {
        f13 = ({ float native_result_1; __asm__("sqrt.s %0,%1" : "=f"(native_result_1) : "f"((f1 +
            f2))); native_result_1; });
        f0 = atan2f(add, f13);
        f25 = f0;
        f0 = atan2f((float)f20, (float)f21);
        f22 = *(float *)s1;
        f20 = s1[1];
        f21 = s1[2];
        f24 = f0;
        f0 = cosf((float)f25);
        f26 = (f23 * f0);
        f0 = sinf((float)f24);
        f0 = (f26 * (float)f0);
        add = f24;
        *(f32 *)s1 = (*(float *)s1 - f0);
        f0 = cosf(add);
        add = f25;
        f1 = (f26 * f0);
        s1[2] = (s1[2] - f1);
        f0 = sinf(add);
        f1 = (f23 * f0);
        s1[1] = (s1[1] - f1);
        f1 = *(float *)s1;
        if (!(f1 <= f22)) {
            f0 = *(float *)s0;
            if (!(f1 <= f0)) {
                goto _L0013B460;
            }
        }
        if (f1 < f22) {
            f0 = *(float *)s0;
            if (f1 < f0) {
                _L0013B460:;
                *(f32 *)s1 = f0;
            }
        }
        f1 = s1[1];
        if (!(f1 <= f20)) {
            f0 = s0[1];
            if (!(f1 <= f0)) {
                goto _L0013B4A8;
            }
        }
        if (f1 < f20) {
            f0 = s0[1];
            if (f1 < f0) {
                _L0013B4A8:;
                s1[1] = f0;
            }
        }
        f1 = s1[2];
        if (!(f1 <= f21)) {
            f0 = s0[2];
            if (!(f1 <= f0)) {
                goto _L0013B4F0;
            }
        }
        if (f1 < f21) {
            f0 = s0[2];
            if (f1 < f0) {
                _L0013B4F0:;
                s1[2] = f0;
            }
        }
        v0 = 0;
    }
    return v0;
}

u_int Math_GotoVector2(float*now, float*end, float per, float min, float max) {
    float *s1;
    float *s0;
    float addxz;
    float rx;
    float ry;
    float add;
    float oldX;
    float oldY;
    float oldZ;
    float currentX;
    float currentY;
    float currentZ;
    float diffX;
    float diffZ;
    float f3;
    float f2;
    float f1;
    float f0;
    u32 v0;

    f0 = 0.0f;
    s1 = (float *)now;
    s0 = (float *)end;
    diffX = (*(float *)now - *(float *)end);
    f3 = (now[1] - end[1]);
    diffZ = (now[2] - end[2]);
    if (0.0f == diffX) {
        if (f0 == f3) {
            if (f0 == diffZ) {
                v0 = 2;
                return v0;
            }
        }
    }
    f1 = (diffX * diffX);
    f2 = (diffZ * diffZ);
    f0 = ({ float native_result_0; __asm__("sqrt.s %0,%1" : "=f"(native_result_0) : "f"((f2 + (f1 +
        (f3 * f3))))); native_result_0; });
    if (f0 <= min) {
        v0 = 1;
        *(f32 *)s1 = *(float *)s0;
        s1[1] = s0[1];
        s1[2] = s0[2];
    } else {
        add = (f0 * per);
        if (add < min) {
            add = (float)min;
        }
        if (!(add <= max)) {
            add = (float)max;
        }
        min = ({ float native_result_1; __asm__("sqrt.s %0,%1" : "=f"(native_result_1) : "f"((f1 +
            f2))); native_result_1; });
        f0 = atan2f((float)f3, min);
        rx = f0;
        f0 = atan2f((float)diffX, (float)diffZ);
        oldX = *(float *)s1;
        oldY = s1[1];
        oldZ = s1[2];
        ry = f0;
        f0 = cosf((float)rx);
        addxz = (add * f0);
        f0 = sinf((float)ry);
        f0 = (addxz * (float)f0);
        per = ry;
        *(f32 *)s1 = (*(float *)s1 - f0);
        f0 = cosf(per);
        per = rx;
        f1 = (addxz * f0);
        s1[2] = (s1[2] - f1);
        f0 = sinf(per);
        f1 = (add * f0);
        f0 = s1[1];
        s1[1] = (f0 - f1);
        currentX = *(float *)s1;
        if (!(currentX <= oldX)) {
            f0 = *(float *)s0;
            if (!(currentX <= f0)) {
                goto _L0013B1F0;
            }
        }
        if (currentX < oldX) {
            f0 = *(float *)s0;
            if (currentX < f0) {
                _L0013B1F0:;
                *(f32 *)s1 = f0;
            }
        }
        currentY = s1[1];
        if (!(currentY <= oldY)) {
            f0 = s0[1];
            if (!(currentY <= f0)) {
                goto _L0013B238;
            }
        }
        if (currentY < oldY) {
            f0 = s0[1];
            if (currentY < f0) {
                _L0013B238:;
                s1[1] = f0;
            }
        }
        currentZ = s1[2];
        if (!(currentZ <= oldZ)) {
            f0 = s0[2];
            if (!(currentZ <= f0)) {
                goto _L0013B280;
            }
        }
        if (currentZ < oldZ) {
            f0 = s0[2];
            if (currentZ < f0) {
                _L0013B280:;
                s1[2] = f0;
            }
        }
        v0 = 0;
    }
    return v0;
}
// size: 0x40, address: 0x228740

/* Math_GetPosToAngle @ 0x13AF60 .. 0x13B01C (0xbc bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x13af8c
 *   fpu: float literal 0x40c90fdb at 0x13afa8
 *   fpu: float literal 0xc0490fdb at 0x13afd0
 *   fpu: float literal 0x40490fdb at 0x13aff0
 *   fpu: float literal 0x40c90fdb at 0x13aff4
 */

float Math_GetPosToAngle(float*pos1, float*pos2) {
    float f13;
    float f12;
    float f2;
    float f1;
    float f0;

    f12 = (*(float *)pos2 - *(float *)pos1);
    f13 = (pos2[2] - pos1[2]);
    f0 = atan2f(f12, f13);
    if (!(f0 <= 3.14159274f)) {
        f2 = 6.28318548f;
        f0 = (f0 - (6.28318548f * (float)((float)(s32)((3.14159274f + f0) / 6.28318548f))));
    }
    f1 = -3.14159274f;
    if (f0 <= -3.14159274f) {
        f1 = 3.14159274f;
        f2 = 6.28318548f;
        f0 = (f0 + (6.28318548f * (float)((float)(s32)((f1 - f0) / 6.28318548f))));
    }
    return f0;
}
