#include "common.h"

extern int GetMdlDataIndexFromMapMdlInfo(int,int);
extern int rand();
extern float Math_VectorToAngle(float,float);
extern void EneAppear(int,int,void *,float *,float,float *,unsigned char,unsigned short,unsigned char,void *,void *);
extern unsigned int ChangeAnimParam(void *,int,float);
extern u32 MdlMng[];
extern float V1[];


extern u32 MdlMng[];


/* SetE044Dead @ 0x205470 .. 0x2054AC (0x3c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x20547c
 *   a0 forwarded to ChangeAnimParam
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 E044ActInit(s32 a0 , u8 *a1 );
static void SetE044Dead(void *a0 , void *a1 , unsigned short a2 );
static void E044FrameLast(void *a0 );
void SetE044RandomAppear(u32 a0,s32 a1,s32 a2,float f12);


/* E044ActInit @ 0x2054B0 .. 0x2054D4 (0x24 bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u32 E044ActInit(s32 a0 /* r4 */, u8 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)SetE044Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetE044Dead;
    v1 = (u8 *)E044FrameLast;
    *(u32 *)(((u8 *)a1 + 0x18c)) = (u32)E044FrameLast;
    v1 = (u8 *)1;
    *(u8 *)(((u8 *)a1 + 0x24c)) = 1;
    return;
}

static void SetE044Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    float f12;
    u8 *s0;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    s0 = (u8 *)a1;
    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    a1 = (void *)(u16)a2;
    ChangeAnimParam(a0, (signed int)a1, f12);
    *(u8 *)(((u8 *)s0 + 0x1f3)) = 1;
    return;
}

static void E044FrameLast(void *a0 /* r4 */) {
    u8 *lpEne = (u8 *)a0;
    u8 *lpMy;
    float HighDif;

    lpMy = (u8 *)(MdlMng + 0x4600);
    if (*(s32 *)(lpEne + 0x134) != 0) {
        HighDif = *(float *)(lpEne + 0x74) - *(float *)(lpEne + 0x24);
        if (((HighDif < 0.0f) ? -HighDif : HighDif) > 0.02f) {
            if (HighDif > 0.0f) {
                *(f32 *)(lpEne + 0x24) = *(float *)(lpEne + 0x74) - 0.02f;
            }
        }
    } else {
        if (*(u8 *)(lpEne + 0x131) == 0) {
            *(f32 *)(lpEne + 0x24) -= 0.1f;
        }
        HighDif = *(float *)(lpMy + 0x24) - *(float *)(lpEne + 0x24);
        if (HighDif < 0.0f) {
            HighDif = -HighDif;
        }
        if (HighDif > 0.02f) {
            if (*(float *)(lpMy + 0x24) < *(float *)(lpEne + 0x24)) {
                *(f32 *)(lpEne + 0x24) -= 0.02f;
            } else {
                *(f32 *)(lpEne + 0x24) += 0.02f;
            }
        } else {
            *(f32 *)(lpEne + 0x24) = *(float *)(lpMy + 0x24);
        }
    }
}
void SetE044RandomAppear(u32 a0,s32 a1,s32 a2,float f12) {
    u32 source;
    s32 count,chance;
    float angle,radius;
    s32 i;
    u32 model;
    s32 range;
    u8 *object;
    u8 *player;
    float dx,dz;
    source=a0; count=a1; chance=a2; radius=f12;
    player=(u8 *)(MdlMng+0x4600);
    {
        float position[4] __attribute__((aligned(16)))={0,0,0,1};
        position[1]=*(float *)(a0+4);
        model=GetMdlDataIndexFromMapMdlInfo(2,44);
        if(model!=(u32)-1) {
            range=(s32)(10.0f*radius);
            i=0;
            if(0<count) {
                float *z=position+2;
                do {
                    if(i!=0) {
                        s32 random=rand()%100;
                        if(random>chance) goto next;
                    }
                    {
                        u8 *cursor,*selected;
                        cursor=(u8 *)(MdlMng+0x55c0);
                        if(cursor!=(u8 *)(MdlMng+0x5a20)) {
                            do {
                                if(*cursor==0) { selected=cursor; goto found; }
                                cursor+=448;
                            } while(cursor!=(u8 *)(MdlMng+0x5a20));
                        }
                        selected=0;
found:
                        object=selected;
                    }
                    if(object!=0) {
                        radius=0.1f*(float)(rand()%range+30);
                        angle=0.01745f*(float)(rand()%360);
                        {
                            float product=sinf((float)angle);
                            product=radius*(float)product;
                            position[0]=*(float *)source-product;
                        }
                        *z=*(float *)(source+8)-radius*cosf((float)angle);
                        dx=*(float *)(player+32)-position[0];
                        dz=*(float *)(player+40)-*z;
                        dx=-dx; dz=-dz;
                        {
                            float result=Math_VectorToAngle(dx,dz);
                            EneAppear(44,model,object,position,result,V1,1,10,0,0,0);
                        }
                        ChangeAnimParam(object,10,30.0f*(float)(i%3));
                        *(u8 *)(*(u32 *)(object+0x148)+0x248)=1;
                    }
next:
                    ++i;
                } while(i<count);
            }
        }
    }
}
