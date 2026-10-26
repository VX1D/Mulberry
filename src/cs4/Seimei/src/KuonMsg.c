#include "common.h"

/* KnMsgMng_GetMapNameMsg @ 0x17CA10 .. 0x17CA6C (0x5c bytes, frame 0x20) */

extern signed int MngState_UpdateExeCheck(void *);
extern unsigned short * MsgFileMng_GetMsgStr(void *, signed int);
extern u8 GameSt[];
extern u8 s_KnMsgMng[];


/* KnMsgMng_CheckMsgNone @ 0x17CA70 .. 0x17CA84 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: sltiu at 0x17ca80 computes the return value
 */

extern u8 s_KnMsgMng[];

/* KnMsgMng_MsgAllClear @ 0x17CA90 .. 0x17CAC8 (0x38 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern signed int MsgMng_ClearList(void *);
extern int TmpMenuMng_SetUDBlackDraw();
extern u8 s_KnMsgMng[];
extern u32 g_TmpMenuMng[];

/* KnMsgMng_MsgClear @ 0x17CAD0 .. 0x17CADC (0xc bytes) */
/*
 * dcomp notes:
 *   tail: j MsgMng_MsgClearCounterUp at 0x17cad4 leaves the function
 *   return value dropped, call kept: the function is void
 */

extern signed int MsgMng_MsgClearCounterUp(void *);
extern u8 s_KnMsgMng[];

/* KnMsgMng_GetSelectNum @ 0x17CAE0 .. 0x17CAEC (0xc bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x17cae8 computes the return value
 *   spans: lui at at 0x17cae0 read at 0x17cae8 before its %lo
 */

extern u8 s_KnMsgMng[];

/* KnMsgMng_GetMsgStr @ 0x17CAF0 .. 0x17CB3C (0x4c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return u_short * vs inferred u32
 */

extern signed int MngState_UpdateExeCheck(void *);
extern unsigned short * MsgFileMng_GetMsgStr(void *, signed int);

u32 g_TmpMenuMng[0x38/4];
u8 s_KnMsgMng[0x260];
extern signed int MsgMng_SendMsg();
typedef struct Kn24Msg { u32 id; u8 type; u8 pad[3]; u32 zero; u32 gap[2]; struct { unsigned char first:1; unsigned char second:1; unsigned char rest:6; } flags; u8 pad2[3]; u32 owner; u32 arg0,arg1,arg2; float x,y,z; u32 mask; u32 tail[8]; } Kn24Msg;


/* KnMsgMng_SendMsgEx_SetArg3 @ 0x17CC60 .. 0x17CC88 (0x28 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x17cc60
 *   fpu: mov.s at 0x17cc7c is a float copy
 *   fpu: mov.s at 0x17cc84 is a float copy
 *   tail: j KnMsgMng_SendMsgExEx at 0x17cc80 leaves the function
 *   a0 forwarded to KnMsgMng_SendMsgExEx
 *   a1 forwarded to KnMsgMng_SendMsgExEx
 */

s32 KnMsgMng_SendMsgExEx(u32 owner, u32 id, u32 mask, u32 arg0, u32 arg1, u32 arg2, float x, float y, float z);

/* KnMsgMng_SendMsgEx_SetMdlId_AnimId @ 0x17CC90 .. 0x17CCB0 (0x20 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x17cc90
 *   fpu: mov.s at 0x17cca4 is a float copy
 *   fpu: mov.s at 0x17ccac is a float copy
 *   tail: j KnMsgMng_SendMsgExEx at 0x17cca8 leaves the function
 *   a0 forwarded to KnMsgMng_SendMsgExEx
 *   a1 forwarded to KnMsgMng_SendMsgExEx
 */

s32 KnMsgMng_SendMsgExEx(u32 owner, u32 id, u32 mask, u32 arg0, u32 arg1, u32 arg2, float x, float y, float z);

/* KnMsgMng_Draw @ 0x17CD00 .. 0x17CD44 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred u8 *
 */

extern signed int MngState_DrawExeCheck(void *);
extern signed int MsgMng_Draw(void *);

/* KnMsgMng_Update @ 0x17CD50 .. 0x17CDA4 (0x54 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return int vs inferred u8 *
 */


extern signed int MsgMng_Update(void *);
extern u8 GameSt[];

/* KnMsgMng_Alloc @ 0x17CDB0 .. 0x17D034 (0x284 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @868 is the string 'msg/english/system_msg.fmg'
 *   literal: @869 is the string 'msg/english/item_msg.fmg'
 *   literal: @870 is the string 'msg/english/stationed_msg.fmg'
 *   literal: @871 is the string 'msg/english/test_msg.fmg'
 *   literal: @872 is the string 'msg/english/map000_msg.fmg'
 *   literal: @873 is the string 'msg/english/map010_msg.fmg'
 *   literal: @874 is the string 'msg/english/map020_msg.fmg'
 *   literal: @875 is the string 'msg/english/map030_msg.fmg'
 *   literal: @876 is the string 'msg/english/map040_msg.fmg'
 *   literal: @877 is the string 'msg/english/map050_msg.fmg'
 *   literal: @878 is the string 'msg/english/map060_msg.fmg'
 *   literal: @879 is the string 'msg/english/map070_msg.fmg'
 *   literal: @880 is the string 'msg/english/map080_msg.fmg'
 *   literal: @881 is the string 'msg/english/map090_msg.fmg'
 *   literal: @882 is the string 'msg/english/item_msg2.fmg'
 *   literal: @883 is the string 'msg/english/item_msg3.fmg'
 *   literal: @884 is the string 'msg/english/item_msg4.fmg'
 *   literal: @885 is the string 'msg/english/item_msg5.fmg'
 *   stack: address of the slot at 0x10 escapes at 0x17ce28
 */

extern signed int MsgMng_Delete(void *);
extern signed int MsgFileMng_Delete(void *);
extern signed int MsgFileMng_Init(void *, unsigned int);
extern signed int MsgMng_Initialize(void *);
extern signed int MsgMng_Init(void *, void *, unsigned int, unsigned int, float *);
extern signed int MsgFileMng_ReadMsgFile(void *, unsigned int, char *);

/* KnMsgMng_Init @ 0x17D040 .. 0x17D0AC (0x6c bytes, frame 0x10) */

extern signed int MngState_Init(void *);
static signed int KnMsgMng_Alloc(void);
extern signed int MsgMng_Delete(void *);
extern signed int MsgFileMng_Delete(void *);

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 KnMsgMng_Initialize(void);
u32 KnMsgMng_Init(void);
static signed int KnMsgMng_Alloc(void);
int KnMsgMng_Update(void);
int KnMsgMng_Draw(void);
int KnMsgMng_SendMsg(int id);
void KnMsgMng_SendMsgEx(s32 a0 , s32 a1 , u32 a2 );
void KnMsgMng_SendMsgEx_SetMdlId_AnimId(s32 a0 , s32 a1 , u16 a2 , s32 a3 , s32 t0 );
void KnMsgMng_SendMsgEx_SetArg3(s32 a0 , s32 a1 , u16 a2 , s32 a3 );
s32 KnMsgMng_SendMsgExEx(u32 owner, u32 id, u32 mask, u32 arg0, u32 arg1, u32 arg2, float x, float y, float z);
u_short * KnMsgMng_GetMsgStr(int msg_id);
u32 KnMsgMng_GetSelectNum(void);
void KnMsgMng_MsgClear(void);
int KnMsgMng_MsgAllClear(void);
signed int KnMsgMng_CheckMsgNone(void);
unsigned short ** KnMsgMng_GetMapNameMsg(void);


/* KnMsgMng_Initialize @ 0x17D0B0 .. 0x17D0B8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x17d0b4 computes the return value
 */

u32 KnMsgMng_Initialize(void) {
    return 1;
}

u32 KnMsgMng_Init(void) {
    u8 *a0;
    u32 v0;
    s32 v1;

    a0 = (u8 *)s_KnMsgMng;
    MngState_Init((void *)s_KnMsgMng);
    v0 = KnMsgMng_Alloc();
    v1 = 1;
    if (v0 != (u32)v1) {
        a0 = (u8 *)s_KnMsgMng + 0x20;
        MsgMng_Delete((void *)a0);
        a0 = (u8 *)s_KnMsgMng + 0x230;
        MsgFileMng_Delete((void *)a0);
        v0 = 0;
        *(u32 **)s_KnMsgMng = (u32 *)0;
    } else {
        v0 = v1;
        v1 = 2;
        *(u32 **)s_KnMsgMng = (u32 *)(u32)v1;
    }
    return v0;
}

static signed int KnMsgMng_Alloc(void) {
    u32 a2;
    s32 v0;
    u8 stackFrame_10[16] __attribute__((aligned(16)));

    MsgMng_Delete((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x20));
    MsgFileMng_Delete((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230));
    v0 = 0x42b80000;
    *(u32 *)((u8 *)&stackFrame_10[0]) = 0x42b80000 | 0x51ec;
    v0 = 0x43c51eb8;
    ((u32 *)stackFrame_10)[1] = 0x43c51eb8;
    v0 = 0x3f800000;
    ((u32 *)stackFrame_10)[2] = 0;
    ((u32 *)stackFrame_10)[3] = 0x3f800000;
    MsgFileMng_Init((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0x13);
    MsgMng_Initialize((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x20));
    MsgMng_Init((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x20), (void *)(u8 *)(s_KnMsgMng + 0x230), 0xa, 0x64,
        (float *)(u8 *)((u8 *)&stackFrame_10[0]));
    a2 = (u32)"msg/english/system_msg.fmg";
    v0 = MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 1,
        "msg/english/system_msg.fmg");
    if ((u32)v0 == 0) {
        v0 = 0;
    } else {
        a2 = (u32)"msg/english/item_msg.fmg";
        v0 = MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 2,
            "msg/english/item_msg.fmg");
        if ((u32)v0 == 0) {
            v0 = 0;
        } else {
            a2 = (u32)"msg/english/stationed_msg.fmg";
            v0 = MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 3,
                "msg/english/stationed_msg.fmg");
            if ((u32)v0 == 0) {
                v0 = 0;
            } else {
                a2 = (u32)"msg/english/test_msg.fmg";
                v0 = MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 4,
                    "msg/english/test_msg.fmg");
                if ((u32)v0 == 0) {
                    v0 = 0;
                } else {
                    a2 = (u32)"msg/english/map000_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 5,
                        "msg/english/map000_msg.fmg");
                    a2 = (u32)"msg/english/map010_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 6,
                        "msg/english/map010_msg.fmg");
                    a2 = (u32)"msg/english/map020_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 7,
                        "msg/english/map020_msg.fmg");
                    a2 = (u32)"msg/english/map030_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 8,
                        "msg/english/map030_msg.fmg");
                    a2 = (u32)"msg/english/map040_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 9,
                        "msg/english/map040_msg.fmg");
                    a2 = (u32)"msg/english/map050_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xa,
                        "msg/english/map050_msg.fmg");
                    a2 = (u32)"msg/english/map060_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xb,
                        "msg/english/map060_msg.fmg");
                    a2 = (u32)"msg/english/map070_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xc,
                        "msg/english/map070_msg.fmg");
                    a2 = (u32)"msg/english/map080_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xd,
                        "msg/english/map080_msg.fmg");
                    a2 = (u32)"msg/english/map090_msg.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xe,
                        "msg/english/map090_msg.fmg");
                    a2 = (u32)"msg/english/item_msg2.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0xf,
                        "msg/english/item_msg2.fmg");
                    a2 = (u32)"msg/english/item_msg3.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0x10,
                        "msg/english/item_msg3.fmg");
                    a2 = (u32)"msg/english/item_msg4.fmg";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0x11,
                        "msg/english/item_msg4.fmg");
                    a2 = (u32)"msg/english/item_msg5.fmg\0\0\0\0\0\0";
                    MsgFileMng_ReadMsgFile((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), 0x12,
                        "msg/english/item_msg5.fmg\0\0\0\0\0\0");
                    v0 = 1;
                }
            }
        }
    }
    return v0;
}

int KnMsgMng_Update(void) {
    u8 *a0;
    u32 v0;

    a0 = (u8 *)s_KnMsgMng;
    v0 = MngState_UpdateExeCheck((void *)s_KnMsgMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        v0 = *(u8 *)((u8 *)&GameSt + 0xf);
        if (v0 == 0) {
            MsgMng_Update((void *)(u8 *)((u8 *)s_KnMsgMng + 0x20));
        }
        v0 = 1;
    }
    return v0;
}

int KnMsgMng_Draw(void) {
    u8 *a0;
    s32 v0;
    s32 v1;

    a0 = (u8 *)s_KnMsgMng;
    v0 = MngState_DrawExeCheck((void *)s_KnMsgMng);
    v1 = 1;
    if ((u32)v0 != (u32)v1) {
        v0 = v1;
    } else {
        MsgMng_Draw((void *)(u8 *)((u8 *)s_KnMsgMng + 0x20));
        v0 = 1;
    }
    return v0;
}

/* KnMsgMng_SendMsg @ 0x17CCD0 .. 0x17CCF4 (0x24 bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x17ccd0
 *   fpu: mov.s at 0x17cce8 is a float copy
 *   fpu: mov.s at 0x17ccf0 is a float copy
 *   tail: j KnMsgMng_SendMsgExEx at 0x17ccec leaves the function
 *   a0 forwarded to KnMsgMng_SendMsgExEx
 *   declaration vs inferred signature: return int vs inferred void
 *   return without a value in a non-void function
 */

int KnMsgMng_SendMsg(int id) {
    float f12;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    KnMsgMng_SendMsgExEx(id, 1, 0, 0, 0, 0, f12, (float)(float)f12, (float)(float)f12);
    return;
}

/* KnMsgMng_SendMsgEx @ 0x17CCB0 .. 0x17CCCC (0x1c bytes) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x17ccb0
 *   fpu: mov.s at 0x17ccc0 is a float copy
 *   fpu: mov.s at 0x17ccc8 is a float copy
 *   tail: j KnMsgMng_SendMsgExEx at 0x17ccc4 leaves the function
 *   a0 forwarded to KnMsgMng_SendMsgExEx
 *   a1 forwarded to KnMsgMng_SendMsgExEx
 *   a2 forwarded to KnMsgMng_SendMsgExEx
 */

void KnMsgMng_SendMsgEx(s32 a0 /* r4 */, s32 a1 /* r5 */, u32 a2 /* r6 */) {
    float f12;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    KnMsgMng_SendMsgExEx(a0, a1, a2, 0, 0, 0, f12, (float)(float)f12, (float)(float)f12);
    return;
}

void KnMsgMng_SendMsgEx_SetMdlId_AnimId(s32 a0 /* r4 */, s32 a1 /* r5 */, u16 a2 /* r6 */, s32 a3 /* r7 */, s32 t0 /* r8 */) {
    u32 a2_word = a2;
    float f12;
    u32 v0;

    f12 = ({ float native_result_0; __asm__("mtc1 %1,%0" : "=f"(native_result_0) : "r"((u32)0));
        native_result_0; });
    v0 = (u16)a2_word;
    v0 = v0 | 2;
    a2_word = (u16)v0;
    KnMsgMng_SendMsgExEx(a0, a1, a2_word, a3, t0, 0, f12, (float)(float)f12, (float)(float)f12);
    return;
}

void KnMsgMng_SendMsgEx_SetArg3(s32 a0 /* r4 */, s32 a1 /* r5 */, u16 a2 /* r6 */, s32 a3 /* r7 */) {
    u32 a2_word = a2;
    u32 v0;

    v0 = (u16)a2_word;
    v0 = v0 | 8;
    a2_word = (u16)v0;
    KnMsgMng_SendMsgExEx(a0, a1, a2_word, 0, 0, a3, 0.0f, (float)(float)0.0f, (float)(float)0.0f);
    return;
}
s32 KnMsgMng_SendMsgExEx(u32 owner, u32 id, u32 mask, u32 arg0, u32 arg1, u32 arg2, float x, float y, float z) {
    u32 savedOwner, savedId, savedMask, savedArg0, savedArg1, savedArg2;
    float savedX,savedY,savedZ;
    s32 result;
    Kn24Msg message __attribute__((aligned(16)));
    savedOwner=owner; savedId=id; savedMask=mask; savedArg0=arg0; savedArg1=arg1; savedArg2=arg2;
    savedX=x; savedY=y; savedZ=z;
    if (MngState_UpdateExeCheck((void *)s_KnMsgMng) != 1) result=0;
    else {
        message.mask=(u16)savedMask;
        message.id=savedId;
        message.type=1;
        message.owner=savedOwner;
        message.zero=0;
        message.flags.first = 0;
        message.flags.second = 0;
        message.arg0=savedArg0;
        message.x=savedX;
        message.arg1=savedArg1;
        message.y=savedY;
        message.arg2=savedArg2;
        message.z=savedZ;
        MsgMng_SendMsg(s_KnMsgMng + 0x20, &message);
        result=1;
    }
    return result;
}

u_short * KnMsgMng_GetMsgStr(int msg_id) {
    s32 s0;
    u32 v0;

    s0 = (s32)msg_id;
    msg_id = (int)s_KnMsgMng;
    v0 = MngState_UpdateExeCheck((void *)s_KnMsgMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        msg_id = (int)((u8 *)s_KnMsgMng + 0x230);
        v0 = (u32)MsgFileMng_GetMsgStr((void *)msg_id, s0);
    }
    return (u_short *)v0;
}

u32 KnMsgMng_GetSelectNum(void) {
    return *(u32 *)((u8 *)&s_KnMsgMng + 0x118);
}

void KnMsgMng_MsgClear(void) {
    MsgMng_MsgClearCounterUp((u8 *)((u8 *)s_KnMsgMng + 0x20));
    return;
}

int KnMsgMng_MsgAllClear(void) {
    u8 *a0;
    s32 v0;

    v0 = MsgMng_ClearList((void *)(u8 *)((u8 *)s_KnMsgMng + 0x20));
    if ((u32)v0 == 0) {
        a0 = (u8 *)g_TmpMenuMng;
        TmpMenuMng_SetUDBlackDraw((u32)g_TmpMenuMng, 1);
    }
    v0 = 1;
    return v0;
}

signed int KnMsgMng_CheckMsgNone(void) {
    u32 v0;

    v0 = s_KnMsgMng[0x98];
    return v0 == (u32)0;
}

unsigned short ** KnMsgMng_GetMapNameMsg(void) {
    u8 *a0;
    u32 v1;
    u32 v0;
    s32 s0;

    v1 = GameSt[9];
    v0 = 0x1ae78;
    a0 = s_KnMsgMng;
    s0 = v1 + 0x1ae78;
    v0 = MngState_UpdateExeCheck((void *)s_KnMsgMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        v0 = (u32)MsgFileMng_GetMsgStr((void *)(u8 *)(u8 *)(s_KnMsgMng + 0x230), s0);
    }
    return (unsigned short **)v0;
}
