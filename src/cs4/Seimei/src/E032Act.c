#include "common.h"

/* SetE032Dead @ 0x1A5FE0 .. 0x1A6044 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x1a5fec
 *   a0 forwarded to ChangeAnimParam
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern u8 MdlMng[];

extern u32 CheckAnimNumFrame(void *,float);
extern void sceVu0CopyVector(void *,void *);
extern void SfxCalc_MakeMatrixFromPYR(void *,float,float,float);
extern void sceVu0ApplyMatrix(void *,void *,void *);
extern s32 SFX_Create_OnDir_Dmg(u16,float *,float *,u8,u8);
extern u32 CheckE032UseSpirit(void *,void *);
extern void EneAppear(s32,s32,void *,float *,float,float *,u8,u16,u8,void *,void *);
extern u32 CheckAnimEndFrame(void *);
extern void SetEneAttackOff(void *,void *);
extern float Math_GotoAngle(float,float,float);
extern u32 V1[];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * E032ActInit(s32 a0 , u32 *a1 );
static void E032ActAttack(void *object,void *controller);
static void SetE032Dead(void *a0 , void *a1 , unsigned short a2 );



/* E032ActInit @ 0x1A63A0 .. 0x1A63BC (0x1c bytes) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   return without a value in a non-void function
 */




u8 * E032ActInit(s32 a0 /* r4 */, u32 *a1 /* r5 */) {
    u8 *v1;

    v1 = (u8 *)E032ActAttack;
    *(u32 *)(((u8 *)a1 + 0x88)) = (u32)E032ActAttack;
    v1 = (u8 *)SetE032Dead;
    *(u32 *)(((u8 *)a1 + 0x110)) = (u32)SetE032Dead;
    return;
}
static void E032ActAttack(void *object,void *controller)
{
    u8 *spirit;
    u8 *model=object;
    u8 *ctrl=controller;
    u8 *anim;
    u16 *params;
    float speed;
    anim=(u8 *)*(u32 *)(model+256);
    params=(u16 *)*(u32 *)(*(u32 *)(model+12)+76);
    object=(void *)(u32)model[298];
    {
        u32 offset=(u32)object*40;
        offset+=(u32)params;
        speed=(float)(u32)*(u16 *)(offset+170)/10.0f;
    }
    if((u8)(u32)object==0) {
        if(CheckAnimNumFrame(anim,35.0f)!=0 || CheckAnimNumFrame(anim,90.0f)!=0) {
            float direction[4] __attribute__((aligned(16)))={0.0f,-1.0f,1.0f,1.0f};
            float rotation[4] __attribute__((aligned(16)));
            float matrix[16] __attribute__((aligned(16)));
            sceVu0CopyVector(rotation,model+48);
            *(float *)((u8 *)rotation+4)=*(float *)((u8 *)rotation+4)+3.1415927f;
            SfxCalc_MakeMatrixFromPYR(matrix,rotation[0],rotation[1],rotation[2]);
            sceVu0CopyVector(matrix+12,model+32);
            sceVu0ApplyMatrix(direction,matrix,direction);
            SFX_Create_OnDir_Dmg(470,direction,matrix+8,params?params[0]:0,model[298]);
        }
    }
    if(model[298]==2 && CheckAnimNumFrame(anim,72.0f)!=0) {
        float direction[4] __attribute__((aligned(16)))={0.0f,-1.0f,1.0f,1.0f};
        float rotation[4] __attribute__((aligned(16)));
        float matrix[16] __attribute__((aligned(16)));
        sceVu0CopyVector(rotation,model+48);
        *(float *)((u8 *)rotation+4)=*(float *)((u8 *)rotation+4)+3.1415927f;
        SfxCalc_MakeMatrixFromPYR(matrix,rotation[0],rotation[1],rotation[2]);
        sceVu0CopyVector(matrix+12,model+32);
        sceVu0ApplyMatrix(direction,matrix,direction);
        SFX_Create_OnDir_Dmg(471,direction,matrix+8,params?params[0]:0,model[298]);
    }
    if(model[298]==1 && CheckAnimNumFrame(anim,90.0f)!=0) {
        spirit=(u8 *)CheckE032UseSpirit(model,ctrl);
        if(spirit!=0) {
            EneAppear(39,1,spirit,(float *)(model+32),*(float *)(model+52),(float *)V1,1,6,0,0,0);
            {
                u8 *spiritCtrl=(u8 *)*(u32 *)(spirit+328);
                spiritCtrl[499]=1;
                spiritCtrl[584]=1;
            }
        }
    }
    if(CheckAnimEndFrame(anim)!=0) {
        {
            u32 offset=model[298]*40;
            offset+=(u32)params;
            *(u32 *)(ctrl+488)=*(u16 *)(offset+178);
        }
        if(*(u32 *)(model+436)!=0 && *(u32 *)(ctrl+488)!=0) SetEneAttackOff(model,ctrl);
        else ((void (*)(u32,u32,s32))*(u32 *)(ctrl+256))((u32)model,(u32)ctrl,2);
        *(float *)(model+408)=*(float *)(model+52);
    }
    *(float *)(model+52)=Math_GotoAngle(*(float *)(model+52),*(float *)(model+408),0.01745f*speed);
}

static void SetE032Dead(void *a0 /* r4 */, void *a1 /* r5 */, unsigned short a2 /* r6 */) {
    u32 a2_word = a2;
    s32 v0;
    u32 v1;

    *(u8 *)(((u8 *)a1 + 0x180)) = 4;
    ChangeAnimParam(a0, (u32)(u16)a2_word, 0.0f);
    a0 = (void *)((u8 *)MdlMng + 0x12280);
    v1 = *(u8 *)a0;
    if (v1 != 0) {
        a1 = (void *)*(s32 *)(((u8 *)a0 + 0x148));
        a2_word = *(u8 *)(((u8 *)a1 + 0x180));
        if (a2_word != (u32)4) {
            *(u32 *)(((u8 *)a0 + 0x120)) = 0;
            v0 = *(s32 *)(((u8 *)a1 + 0x110));
            ((void (*)(u32, s32, s32))v0)((u32)a0, (s32)a1, 0x28);
        }
    }
    return;
}
