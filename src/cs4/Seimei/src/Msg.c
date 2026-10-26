#include "common.h"




extern signed int ListMng_RemoveList(void *);
extern signed int ListMng_Delete(void *);
extern void MemFree(void *);
extern signed int MngState_DrawExeCheck(void *);
extern void FontDrawBegin(int);
extern signed int FsFontGetLineHeight(float *);
extern signed int FsFontSetScale(float, float);
extern signed int FsFontSetAlignment(signed int);
extern void SetFontColorRGBA(unsigned int);
extern signed int FsFontSetMaxChar(float);
extern void FontPrintXY(float, float, char *, ...);
extern signed int MsgFileMng_GetTexId(void *);
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void MakeAndKickSpritePacket(void *);
extern void Msg_DrawPageIcon(signed int, signed int);
extern void FontDrawEnd(void);
extern u32 g_TmpMenuMng[];
typedef struct {
    // Members
    u_int SystemCounter; // offset 0x0, size 0x4
    u_char ControlMode; // offset 0x4, size 0x1
    u_char GameMode; // offset 0x5, size 0x1
    u_char GameModePrev; // offset 0x6, size 0x1
    u_char DebugMode; // offset 0x7, size 0x1
    u_char StopMode; // offset 0x8, size 0x1
    u_char sceneNo; // offset 0x9, size 0x1
    u_char padport; // offset 0xA, size 0x1
    u_char ShadowTest; // offset 0xB, size 0x1
    u_char DepthTest; // offset 0xC, size 0x1
    u_char ScriptMode; // offset 0xD, size 0x1
    u_char DizzyTest; // offset 0xE, size 0x1
    u_char Pause; // offset 0xF, size 0x1
    u_char EnePause; // offset 0x10, size 0x1
    u_char EnemyOff; // offset 0x11, size 0x1
    u_char FadedTest; // offset 0x12, size 0x1
    u_char PeepMask; // offset 0x13, size 0x1
    u_char PlayerId; // offset 0x14, size 0x1
    u_char PadVib; // offset 0x15, size 0x1
    u_char KeyConfType; // offset 0x16, size 0x1
    u_char EneSearchOff; // offset 0x17, size 0x1
    u_char GameLevel; // offset 0x18, size 0x1
    u_char StartEquip; // offset 0x19, size 0x1
    u_char PenanceMode; // offset 0x1A, size 0x1
    u_char NineHitNum; // offset 0x1B, size 0x1
    u_char NegaPosi; // offset 0x1C, size 0x1
    u_char LoadStart; // offset 0x1D, size 0x1
    char Brightness; // offset 0x1E, size 0x1
    u_char GlareId; // offset 0x1F, size 0x1
    u_char MyAllAttack; // offset 0x20, size 0x1
    u_char DebugMenuOn; // offset 0x21, size 0x1
    u_char Sugoroku; // offset 0x22, size 0x1
    u_char TutorialOff; // offset 0x23, size 0x1
    float AmbRate; // offset 0x24, size 0x4
    u_char ClearCount[3]; // offset 0x28, size 0x3
    u_char ExtraClear; // offset 0x2B, size 0x1
    u_char VoiceLanguage; // offset 0x2C, size 0x1
    u_char LastLanguage; // offset 0x2D, size 0x1
    u_char unused[2]; // offset 0x2E, size 0x2
} GameState;
extern GameState GameSt;
extern void * MemAllocReal(unsigned int, char *, char *);
extern signed int ListMng_Init(void *, void *, signed int, unsigned int, unsigned int, int, int);
signed int MsgMng_ClearList(void *a0 /* r4 */);
signed int MsgMng_MsgClearCounterUp(void *a0 /* r4 */);
signed int MsgMng_Delete(void *a0 /* r4 */);
signed int MsgMng_Draw(void *a0 /* r4 */);
static signed int MsgMng_Alloc(void *a0 /* r4 */);
signed int MsgMng_Initialize(void *a0 /* r4 */);

/* MsgMng_Initialize @ 0x17C9B0 .. 0x17CA10 (0x60 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int MsgMng_Initialize(void *a0 /* r4 */) {
    s32 v0;
    s32 v1;

    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    *(u32 *)(((u8 *)a0 + 0x28)) = 0;
    *(u32 *)(((u8 *)a0 + 0x20)) = 0;
    v1 = 0;
    do {
        *(u32 *)(((u8 *)a0 + 0x104)) = 0;
        *(u32 *)(((u8 *)a0 + 0x108)) = 0;
        v1 = v1 + 8;
        *(u32 *)(((u8 *)a0 + 0x10c)) = 0;
        v0 = v1 < (s32)0x40;
        *(u32 *)(((u8 *)a0 + 0x110)) = 0;
        *(u32 *)(((u8 *)a0 + 0x114)) = 0;
        *(u32 *)(((u8 *)a0 + 0x118)) = 0;
        *(u32 *)(((u8 *)a0 + 0x11c)) = 0;
        *(u32 *)(((u8 *)a0 + 0x120)) = 0;
        a0 = (void *)(s32)((u8 *)a0 + 0x20);
    } while ((u32)v0 != 0);
    v0 = 1;
    return v0;
}



/* MsgMng_Init @ 0x17C870 .. 0x17C9A8 (0x138 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: daddu at 0x17c8d8 writes a register its branch at 0x17c8d4 reads
 *   cfg: kept goto: 0x17c8a8 -> .L0017C988
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_Init(void *);
extern void fsvu0_CopyVectorF(float *, float *);

signed int MsgMng_Init(void *a0 /* r4 */, void *a1 /* r5 */, unsigned int a2 /* r6 */, unsigned int
        a3 /* r7 */, float *t0 /* r8 */) {
    u8 *s0;
    void *s4;
    u32 s3;
    u32 s2;
    float *s1;
    void *a1_2; // a1
    s32 v1;
    s32 v0;

    s4 = a1;
    s3 = a2;
    s2 = a3;
    s0 = (u8 *)a0;
    s1 = t0;
    if ((u32)s0 == 0) {
        v0 = 0;
        goto _L0017C988;
    }
    if (s4 == 0) {
        return 0;
    }
    if ((u32)s3 == 0) {
        return 0;
    }
    v0 = 1;
    if ((u32)s2 == (u32)v0) {
        return 0;
    }
    MngState_Init(s0);
    *(u32 *)(s0 + 0x24) = s3;
    a1_2 = (void *)(u32)s1;
    a0 = (void *)(s0 + 0xe0);
    *(u32 *)(s0 + 0xcc) = s2;
    fsvu0_CopyVectorF((float *)a0, (float *)a1_2);
    *(u32 *)(s0 + 0xf4) = 0;
    a0 = (void *)s0;
    *(u32 *)(s0 + 0xf8) = 0;
    *(u32 *)(s0 + 0xfc) = 0;
    *(u32 *)(s0 + 0x204) = 0;
    *(void **)(s0 + 0x20) = s4;
    v0 = MsgMng_Alloc(a0);
    v1 = 1;
    if ((u32)v0 != (u32)v1) {
        if ((u32)s0 != 0) {
            if ((u32)s0 != 0) {
                ListMng_Delete(s0 + 0x2c);
                a0 = (void *)*(s32 *)(s0 + 0x28);
                MemFree(a0);
                *(u32 *)(s0 + 0x28) = 0;
                a0 = (void *)*(s32 *)(s0 + 0xd4);
                MemFree(a0);
                *(u32 *)(s0 + 0xd4) = 0;
                a0 = (void *)*(s32 *)(s0 + 0xd8);
                MemFree(a0);
                *(u32 *)(s0 + 0xd8) = 0;
            }
            *(u32 *)s0 = 0;
        }
        v0 = 0;
    } else {
        v0 = v1;
        v1 = 2;
        *(u32 *)s0 = v1;
    }
    _L0017C988:;
    return v0;
}


/* MsgMng_Alloc @ 0x17C6A0 .. 0x17C870 (0x1d0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: __FUNCTION__$707 is the string 'MsgMng_Alloc'
 *   literal: @1611 is the string ''
 *   cfg: loop body is not one contiguous region: .L0017C7C0
 *   v0#7 is the pointer held in a0+0xd4
 *   v0#11 is the pointer held in a0+0xd8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


static signed int MsgMng_Alloc(void *a0 /* r4 */) {
    u8 *pMsgMng;
    u8 *p;
    u32 i;

    pMsgMng = (u8 *)a0;
    if (pMsgMng == 0) {
        return 0;
    }
    if (pMsgMng != 0) {
        ListMng_Delete(pMsgMng + 0x2c);
        MemFree((void *)*(s32 *)(pMsgMng + 0x28));
        *(u32 *)(pMsgMng + 0x28) = 0;
        MemFree((void *)*(s32 *)(pMsgMng + 0xd4));
        *(u32 *)(pMsgMng + 0xd4) = 0;
        MemFree((void *)*(s32 *)(pMsgMng + 0xd8));
        *(u32 *)(pMsgMng + 0xd8) = 0;
    }
    if ((*(u32 *)(pMsgMng + 0xd4) = (u32)MemAllocReal(*(s32 *)(pMsgMng + 0xcc) * 4 + 1, (char *)__FUNCTION__, "")) == 0) {
        return 0;
    }
    **(u16 **)(pMsgMng + 0xd4) = 0;
    if ((*(u32 *)(pMsgMng + 0xd8) = (u32)MemAllocReal(*(s32 *)(pMsgMng + 0xcc) * 4 + 1, (char *)__FUNCTION__, "")) == 0) {
        return 0;
    }
    **(u16 **)(pMsgMng + 0xd8) = 0;
    if ((*(u32 *)(pMsgMng + 0x28) = (u32)MemAllocReal(*(u32 *)(pMsgMng + 0x24) * 0x58, (char *)__FUNCTION__, "")) == 0) {
        return 0;
    }
    for (i = 0; i < *(u32 *)(pMsgMng + 0x24); i++) {
        p = (u8 *)*(s32 *)(pMsgMng + 0x28) + i * 0x58;
        if (p != 0) {
            *(u32 *)(p + 0x18) = 0;
            *(u8 *)(p + 4) = 0;
            *(u32 *)(p + 0x1c) = 0;
            *(u32 *)(p + 0x20) = 0;
            *(u32 *)(p + 0x24) = 0;
            *(u32 *)(p + 0x28) = 0;
            *(u32 *)(p + 0x2c) = 0;
            *(u32 *)(p + 0x30) = 0;
        }
    }
    if (pMsgMng + 0x74 != 0) {
        *(u32 *)(pMsgMng + 0x8c) = 0;
        *(u8 *)(pMsgMng + 0x78) = 0;
        *(u32 *)(pMsgMng + 0x90) = 0;
        *(u32 *)(pMsgMng + 0x94) = 0;
        *(u32 *)(pMsgMng + 0x98) = 0;
        *(u32 *)(pMsgMng + 0x9c) = 0;
        *(u32 *)(pMsgMng + 0xa0) = 0;
        *(u32 *)(pMsgMng + 0xa4) = 0;
    }
    ListMng_Init(pMsgMng + 0x2c, (void *)*(u32 *)(pMsgMng + 0x28), *(u32 *)(pMsgMng + 0x24), 0x58, 0, 3, 7);
    return 1;
}








/* MsgMng_Update @ 0x17BC20 .. 0x17C6A0 (0xa80 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @1485 -> 0x253cd0
 *   indirect: jr v0 at 0x17bcb0 -> <v0>
 *   fpu: float literal 0x3f800000 at 0x17bf0c
 *   delay: dsll32 at 0x17c1f8 writes a register its branch at 0x17c1f4 reads
 *   delay: lui at 0x17c4a8 writes a register its branch at 0x17c4a4 reads
 *   delay: dsll32 at 0x17c520 writes a register its branch at 0x17c51c reads
 *   cfg: loop body is not one contiguous region: .L0017BC68
 *   cfg: loop body is not one contiguous region: .L0017BE70
 *   cfg: kept branch: 0x17be70 if (..) goto .L0017BE98
 *   cfg: kept goto: 0x17bf20 -> .L0017BF38
 *   cfg: loop body is not one contiguous region: .L0017BFB0
 *   cfg: loop body is not one contiguous region: .L0017C018
 *   cfg: kept branch: 0x17c088 if (..) goto .L0017C0E8
 *   cfg: kept branch: 0x17c150 if (..) goto .L0017C198
 *   cfg: kept branch: 0x17c15c if (..) goto .L0017C180
 *   cfg: kept branch: 0x17c1cc if (..) goto .L0017C208
 *   cfg: kept branch: 0x17c1e8 if (..) goto .L0017C218
 *   cfg: kept branch: 0x17c1f8 if (..) goto .L0017C218
 *   cfg: loop body is not one contiguous region: .L0017C338
 *   cfg: kept goto: 0x17c43c -> .L0017C460
 *   cfg: loop test does not fall through into its body: 0x17c460
 *   cfg: kept branch: 0x17c460 if (..) goto .L0017C450
 *   cfg: kept goto: 0x17c5c8 -> .L0017BC68
 *   v0#10 is the pointer held in a0+0xd0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_UpdateExeCheck(void *);
extern signed int MsgFileMng_GetMsgData(void *, unsigned short **, signed int);
extern void MSG_MNG__StartCallBack(s32, s32, s32, s32, s32, s32, s32, float, float, float);
extern void * memcpy(void *, const void *, unsigned int);
extern void MSG_MNG__MsgWorkingCallBack(s32, s32, s32, s32, s32, s32, s32, float, float, float);
extern signed int CheckNowFade(signed int);
extern signed int ListMng_GetNextId(void *);
extern void MSG_MNG__EndCallBack(unsigned int, s32, s32, s32, s32, s32, s32, float, float, float);
struct Msg24Payload;
signed int MsgMng_SendMsg(void *object, struct Msg24Payload *source);
static s8 msgmng_error_str[0x100];

#ifndef PROTO_DW_1027597_FIELDS
#define PROTO_DW_1027597_FIELDS
struct dw_1027597_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_1026716_FIELDS
#define PROTO_DW_1026716_FIELDS
struct dw_1026716_fields { struct dw_1027597_fields mng_state; int DrawState; unsigned char **pTmpMenuFileBuf; float draw_up_rate; unsigned char dmy[12]; };
#endif
#ifndef PROTO_DW_1029710_FIELDS
#define PROTO_DW_1029710_FIELDS
struct dw_1029710_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif


struct dw_1027597 { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
struct dw_1025715 { int wait_until_exec_wait : 1; int overwrite : 1; int reserve : 30; };
struct dw_1023617 { int priority; unsigned char state; unsigned char _pad0[3]; unsigned int proc_id; int counter; int counter2; struct dw_1025715 msg_data_flag; int msg_id; int id1; int id2; int id3; float fdata1; float fdata2; float fdata3; unsigned int user_data; unsigned int print_msg_len; int dmy[7]; };
struct dw_1024230 { struct dw_1027597 mng_state; signed char type; unsigned char _pad0[3]; void *pList; unsigned char *pDataTop; unsigned char priority_type; unsigned char _pad1[3]; unsigned int data_size; unsigned int key_offset; int node_num; int top_node_id; int end_node_id; int csr_node_id; };
struct dw_1025910 { struct dw_1027597 mng_state; void *pMsgFileMng; unsigned int msg_data_num; struct dw_1023617 *pMsgDataBuf; struct dw_1024230 list_mng; struct dw_1023617 now_draw_msg; unsigned int str_max_length; unsigned short *pFileStr; unsigned short *pWorkStr; unsigned short *pDrawStr; unsigned char _pad0[4]; float draw_pos[4]; unsigned int buf_on; unsigned int msg_mng_state; int befor_select; int select; int select_num; unsigned short *aSelectPtr[64]; int msg_clear_counter; unsigned char _pad1[8]; };
struct dw_1027967 { unsigned short select : 1; unsigned short L3 : 1; unsigned short R3 : 1; unsigned short start : 1; unsigned short Lup : 1; unsigned short Lright : 1; unsigned short Ldown : 1; unsigned short Lleft : 1; unsigned short L2 : 1; unsigned short R2 : 1; unsigned short L1 : 1; unsigned short R1 : 1; unsigned short Rup : 1; unsigned short Rdown : 1; unsigned short Rright : 1; unsigned short Rleft : 1; };
union dw_1032409 { struct dw_1027967 bit; unsigned short set; };
struct dw_1032506 { unsigned char Lright; unsigned char Lleft; unsigned char Lup; unsigned char Ldown; unsigned char Rup; unsigned char Rright; unsigned char Rdown; unsigned char Rleft; unsigned char L1; unsigned char R1; unsigned char L2; unsigned char R2; };
struct dw_1024697 { unsigned char success; unsigned char data_len; union dw_1032409 button; unsigned char r3h; unsigned char r3v; unsigned char l3h; unsigned char l3v; unsigned char apress[12]; struct dw_1032506 press; union dw_1032409 edge; union dw_1032409 repeat; };
extern struct dw_1024697 *lpPadData[2];

static inline int MsgIsLead(unsigned char c) {
    if ((unsigned char)(c - 0x81) < 0x1e) return 1;
    if ((unsigned char)(c - 0xe0) < 0x1c) return 1;
    return 0;
}
static inline int MsgIsTrail(unsigned char c) {
    if ((unsigned char)(c - 0x40) < 0x3e) return 1;
    if ((unsigned char)(c - 0x80) < 0x6c) return 1;
    return 0;
}
#define MSG_IS_LEAD(c) MsgIsLead(c)
#define MSG_IS_TRAIL(c) MsgIsTrail(c)

static inline void MsgStrCopy16(unsigned short *dst, unsigned short *src) {
    unsigned int n;
    for (n = 0; src[n] != 0; n++) {}
    memcpy(dst, src, n * 2 + 2);
}

static inline unsigned int MsgStrLen16(unsigned short *s) {
    unsigned int n;
    for (n = 0; s[n] != 0; n++) {}
    return n;
}

static inline int MsgSjisType(unsigned char *s, int idx) {
    int k;
    int odd;
    if (idx > 0) {
        if (!MSG_IS_LEAD(s[idx - 1])) {
            odd = 0;
        } else {
            k = idx - 1;
            do {
                k--;
                if (k < 0) break;
            } while (MSG_IS_LEAD(s[k]));
            odd = (((idx - 1) - k) & 1);
        }
        if (odd) {
            return MSG_IS_TRAIL(s[idx]) ? 2 : 3;
        }
    }
    if (MSG_IS_LEAD(s[idx])) return 1;
    return 0;
}

signed int MsgMng_Update(struct dw_1025910 *pMsgMng) {
    struct dw_1023617 *pNowMsgData;
    unsigned short *pd;
    unsigned int i;
    int j;
    int i2;
    struct dw_1024697 *lpPad;
    int k;
    struct dw_1024697 *lpPad2;
    struct dw_1024697 *lpPad3;
    int next_id;

    if (pMsgMng == 0) return 0;
    if (MngState_UpdateExeCheck(pMsgMng) != 1) return 0;

restart:
    pMsgMng->select_num = 0;
    pNowMsgData = &pMsgMng->now_draw_msg;
    switch (pNowMsgData->proc_id) {
    case 0:
        switch (pNowMsgData->state) {
        case 1:
            pMsgMng->pWorkStr[0] = 0;
            pMsgMng->select = 0;
            for (i = 0; i < 0x40; i++) pMsgMng->aSelectPtr[i] = 0;
            if (MsgFileMng_GetMsgData(pMsgMng->pMsgFileMng, &pMsgMng->pFileStr, pNowMsgData->msg_id) == 0) {
                pMsgMng->pFileStr = (unsigned short *)msgmng_error_str;
                pMsgMng->pDrawStr[0] = 0;
            }
            pNowMsgData->counter = pMsgMng->str_max_length;
            pNowMsgData->print_msg_len = 0;
            pNowMsgData->counter2 = 2;
            MSG_MNG__StartCallBack(*(s32 *)((u8 *)pNowMsgData + 0x18), *(s32 *)((u8 *)pNowMsgData + 0x34), *(s32 *)((u8 *)pMsgMng + 0xf4), *(s32 *)((u8 *)pNowMsgData + 0x1c), *(s32 *)((u8 *)pNowMsgData + 0x20), *(s32 *)((u8 *)pNowMsgData + 0x24), (s32)pNowMsgData, *(float *)((u8 *)pNowMsgData + 0x28), *(float *)((u8 *)pNowMsgData + 0x2c), *(float *)((u8 *)pNowMsgData + 0x30));
            pNowMsgData->state = 2;
            pMsgMng->pDrawStr[0] = 0;
            break;
        case 2:
            if (pNowMsgData->counter > 0) {
                MsgStrCopy16(pMsgMng->pWorkStr, pMsgMng->pFileStr);
                MSG_MNG__MsgWorkingCallBack((s32)pMsgMng->pWorkStr, pNowMsgData->user_data, pMsgMng->msg_mng_state, pNowMsgData->id1, pNowMsgData->id2, pNowMsgData->id3, (s32)pNowMsgData, pNowMsgData->fdata1, pNowMsgData->fdata2, pNowMsgData->fdata3);
                MsgStrCopy16(pMsgMng->pDrawStr, pMsgMng->pWorkStr);
                pMsgMng->select_num = 0;
                for (j = 0; j < pMsgMng->str_max_length; j++) {
                    if (pMsgMng->pDrawStr != 0 && pMsgMng->pDrawStr[j] == 0x40) {
                        pMsgMng->pDrawStr[j] = 0;
                        break;
                    }
                    if (pMsgMng->pFileStr != 0 && pMsgMng->pFileStr[j] == 0) break;
                }
                pd = pMsgMng->pDrawStr;
                i = MsgStrLen16(pd);
                if (1.0f == *(float *)(g_TmpMenuMng + 10)) {
                    pNowMsgData->counter2--;
                } else {
                    pd[0] = 0;
                    break;
                }
                if (pNowMsgData->counter2 == 0) {
                    pNowMsgData->counter--;
                    pNowMsgData->print_msg_len++;
                    pNowMsgData->counter2 = 2;
                }
                if (i <= pMsgMng->str_max_length - pNowMsgData->counter) {
                    pNowMsgData->counter = 0;
                    pNowMsgData->print_msg_len = 100000;
                }
                for (i2 = 0; i2 < pMsgMng->str_max_length; i2++) {
                    if ((unsigned char)MsgSjisType((unsigned char *)pMsgMng->pFileStr, i2) == 0) {
                        if (pMsgMng->pFileStr != 0 && pMsgMng->pFileStr[i2] == 0xa) {
                            pMsgMng->msg_mng_state |= 4;
                            break;
                        }
                        if (pMsgMng->pFileStr != 0 && pMsgMng->pFileStr[i2] == 0) break;
                    }
                }
                lpPad = lpPadData[GameSt.padport];
                if (((GameSt.GameMode == 0 || GameSt.GameMode == 3) && GameSt.Pause == 0 && (lpPad->edge.bit.Rright || lpPad->edge.bit.Rdown)) || pMsgMng->msg_clear_counter > 0) {
                    pNowMsgData->counter = 0;
                    pNowMsgData->print_msg_len = 100000;
                    pNowMsgData->counter2 = 3;
                }
                break;
            }
            pNowMsgData->counter = pMsgMng->str_max_length;
            pNowMsgData->print_msg_len = 100000;
            pNowMsgData->state = 3;
        case 3:
            if (pNowMsgData->counter > 0) {
                MsgStrCopy16(pMsgMng->pWorkStr, pMsgMng->pFileStr);
                MSG_MNG__MsgWorkingCallBack((s32)pMsgMng->pWorkStr, pNowMsgData->user_data, pMsgMng->msg_mng_state, pNowMsgData->id1, pNowMsgData->id2, pNowMsgData->id3, (s32)pNowMsgData, pNowMsgData->fdata1, pNowMsgData->fdata2, pNowMsgData->fdata3);
                MsgStrCopy16(pMsgMng->pDrawStr, pMsgMng->pWorkStr);
                pMsgMng->select_num = 0;
                for (k = 0; k < pMsgMng->str_max_length; k++) {
                    if (pMsgMng->pDrawStr != 0 && pMsgMng->pDrawStr[k] == 0x40) {
                        pMsgMng->aSelectPtr[pMsgMng->select_num] = &pMsgMng->pDrawStr[k + 1];
                        pMsgMng->pDrawStr[k] = 0;
                        pMsgMng->select_num++;
                    }
                    if (pMsgMng->select_num == 0x40) break;
                    if (pMsgMng->pFileStr != 0 && pMsgMng->pFileStr[k] == 0) break;
                }
                if (pMsgMng->select_num != 0) {
                    lpPad2 = lpPadData[GameSt.padport];
                    if (GameSt.Pause == 0) {
                        if (lpPad2->edge.bit.Lleft) pMsgMng->select--;
                    }
                    if (GameSt.Pause == 0) {
                        if (lpPad2->edge.bit.Lright) pMsgMng->select++;
                    }
                    while (pMsgMng->select < 0) pMsgMng->select += pMsgMng->select_num;
                    while (pMsgMng->select >= pMsgMng->select_num) pMsgMng->select -= pMsgMng->select_num;
                }
                if (pMsgMng->msg_clear_counter > 0) {
                    pNowMsgData->counter = 0;
                    pNowMsgData->print_msg_len = 100000;
                    pNowMsgData->counter2 = 2;
                    pMsgMng->msg_clear_counter--;
                    break;
                } else {
                    lpPad3 = lpPadData[GameSt.padport];
                    if (GameSt.GameMode != 0 && GameSt.GameMode != 3) break;
                    if (GameSt.Pause != 0) break;
                    if (!lpPad3->edge.bit.Rright && !lpPad3->edge.bit.Rdown) break;
                    if (CheckNowFade(10) != 0) break;
                    pNowMsgData->counter = 0;
                    pNowMsgData->print_msg_len = 100000;
                    if (GameSt.Pause != 0) break;
                    if (!lpPad3->edge.bit.Rdown) break;
                    if (pMsgMng->select_num == 0) break;
                    pMsgMng->select = pMsgMng->select_num - 1;
                    break;
                }
            } else {
                pNowMsgData->state = 4;
            }
        case 4:
            pMsgMng->befor_select = pMsgMng->select;
            pNowMsgData->state = 5;
        case 5:
            pNowMsgData->state = 0;
            pMsgMng->msg_mng_state = 0;
            next_id = ListMng_GetNextId(&pMsgMng->list_mng);
            if (next_id != -1) {
                pMsgMng->msg_mng_state |= 2;
                MSG_MNG__EndCallBack(pNowMsgData->msg_id, pNowMsgData->user_data, pMsgMng->msg_mng_state, pNowMsgData->id1, pNowMsgData->id2, pNowMsgData->id3, (s32)pNowMsgData, pNowMsgData->fdata1, pNowMsgData->fdata2, pNowMsgData->fdata3);
                MsgMng_SendMsg(pMsgMng, (struct Msg24Payload *)&pMsgMng->pMsgDataBuf[next_id]);
                ListMng_RemoveList(&pMsgMng->list_mng);
                goto restart;
            } else {
                pMsgMng->pDrawStr[0] = 0;
                MSG_MNG__EndCallBack(*(s32 *)((u8 *)pNowMsgData + 0x18), *(s32 *)((u8 *)pNowMsgData + 0x34), *(s32 *)((u8 *)pMsgMng + 0xf4), *(s32 *)((u8 *)pNowMsgData + 0x1c), *(s32 *)((u8 *)pNowMsgData + 0x20), *(s32 *)((u8 *)pNowMsgData + 0x24), (s32)pNowMsgData, *(float *)((u8 *)pNowMsgData + 0x28), *(float *)((u8 *)pNowMsgData + 0x2c), *(float *)((u8 *)pNowMsgData + 0x30));
                break;
            }
        case 6:
            pNowMsgData->state = 1;
        case 0:
        default:
            break;
        }
    case 1:
        break;
    }
    return 1;
}




















/* MsgMng_Draw @ 0x17B8A0 .. 0x17BC20 (0x380 bytes, frame 0x170) */
/*
 * dcomp notes:
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @948 -> 0x22b190
 *   fpu: float literal 0x3f800000 at 0x17b8fc
 *   stack: address of the slot at 0x16c escapes at 0x17b924
 *   fpu: float literal 0x40000000 at 0x17b934
 *   fpu: float literal 0x3f3bbbbc at 0x17b94c
 *   fpu: float literal 0x3f6aaaab at 0x17b950
 *   fpu: mtc1 reinterprets v0 at 0x17b998
 *   fpu: mtc1 reinterprets v1 at 0x17b9ac
 *   fpu: float literal 0x3f000000 at 0x17b9c0
 *   fpu: float literal 0x428c0000 at 0x17b9dc
 *   fpu: float literal 0x41000000 at 0x17b9e8
 *   fpu: float literal 0x47c35000 at 0x17ba08
 *   fpu: float literal 0x44000000 at 0x17ba28
 *   delay: lui at 0x17ba70 writes a register its branch at 0x17ba6c reads
 *   fpu: mtc1 reinterprets s0 at 0x17ba9c
 *   fpu: float literal 0x42000000 at 0x17bab0
 *   fpu: float literal 0x41a00000 at 0x17bac0
 *   delay: lui at 0x17bafc writes a register its branch at 0x17baf8 reads
 *   fpu: float literal 0x42000000 at 0x17bb18
 *   fpu: float literal 0x43a00000 at 0x17bb20
 *   fpu: float literal 0x42080000 at 0x17bb28
 *   fpu: float literal 0x43700000 at 0x17bb30
 *   fpu: mtc1 reinterprets v0 at 0x17bb60
 *   stack: address of the slot at 0x70 escapes at 0x17bbb0
 *   stack: address of the slot at 0x60 escapes at 0x17bbb0
 *   stack: address of the slot at 0x70 escapes at 0x17bbb8
 *   literal: @948 initializes the 16-byte local at 0x60
 *   cfg: loop body is not one contiguous region: .L0017BA68
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MsgMng_Draw(void *a0 /* r4 */) {
    u8 *s4;
    s32 a3;
    float f13;
    float f12;
    u32 v1;
    float f4;
    float f3;
    float f1;
    float f0;
    s32 s3;
    s32 s2;
    u32 s1;
    s32 s0;
    u32 v0;
    u8 stackFrame_16C[4] __attribute__((aligned(4)));
    u8 stackFrame_70[252] __attribute__((aligned(16)));

    s4 = (u8 *)a0;
    if ((u32)s4 == 0) {
        v0 = 0;
    } else {
        v0 = MngState_DrawExeCheck(a0);
        v1 = 1;
        if (v0 != v1) {
            v0 = v1;
        } else {
            f0 = *(float *)(g_TmpMenuMng + 0xa);
            v0 = 0x3f800000;
            f1 = 1.0f;
            if (1.0f == f0 && (u32)*(u8 *)(s4 + 0x78) != 0) {
                a0 = (void *)0;
                FontDrawBegin(0);
                FsFontGetLineHeight((float *)((u8 *)&stackFrame_16C[0]));
                f1 = 2.0f;
                v0 = 0x3f3b0000;
                v1 = 0x3f3b0000 | 0xbbbc;
                f12 = 0.733333349f;
                f13 = 0.916666687f;
                *(f32 *)((u8 *)&stackFrame_16C[0]) = (*(float *)((u8 *)&stackFrame_16C[0]) / 2.0f);
                FsFontSetScale(0.733333349f, 0.916666687f);
                v0 = *(s32 *)(s4 + 0xf4);
                if ((u32)(v0 & 4) != 0) {
                    *(u32 *)((u8 *)&stackFrame_16C[0]) = 0;
                }
                FsFontSetAlignment(0x100);
                v0 = 0x7f7f0000;
                SetFontColorRGBA(0x7f7f0000 | 0x7f7f);
                v0 = *(s32 *)(s4 + 0xac);
                f0 = 0.5f;
                FsFontSetMaxChar((0.5f + (float)(float)v0));
                f3 = 70.0f;
                f0 = 8.0f;
                f12 = (*(float *)(s4 + 0xe0) - 70.0f);
                f13 = ((*(float *)(s4 + 0xe4) + *(float *)((u8 *)&stackFrame_16C[0])) - 8.0f);
                FontPrintXY(f12, f13, (char *)*(s32 *)(s4 + 0xd8));
                f12 = 100000.0f;
                FsFontSetMaxChar(100000.0f);
                v1 = *(s32 *)(s4 + 0x100);
                if (v1 != 0) {
                    f0 = 512.0f;
                    v0 = ((s32)(f0 - *(float *)(s4 + 0xe0)));
                    s2 = (s32)v0 / (s32)v1;
                }
                s3 = 0;
                if (0 < (s32)v1) {
                    s1 = (u32)s4;
                    s0 = 0;
                    do {
                        v0 = *(s32 *)(s4 + 0xfc);
                        if ((u32)s3 == v0) {
                            v0 = 0x7f7f0000;
                            SetFontColorRGBA(0x7f7f0000 | 0x7f7f);
                        } else {
                            v0 = 0x40400000;
                            SetFontColorRGBA(0x40400000 | 0x407f);
                        }
                        f0 = 32.0f;
                        f12 = (32.0f + (*(float *)(s4 + 0xe0) + (float)((float)(s32)(u32)s0)));
                        f0 = 20.0f;
                        f13 = (20.0f + *(float *)(s4 + 0xe4));
                        FontPrintXY(f12, f13, (char *)*(s32 *)((s1 + 0x104)));
                        v0 = *(s32 *)(s4 + 0x100);
                        s3 = s3 + 1;
                        s1 = s1 + 4;
                        v0 = s3 < (s32)v0;
                        s0 = s0 + s2;
                    } while (v0 != 0);
                }
                v0 = 0x7f7f0000;
                SetFontColorRGBA(0x7f7f0000 | 0x7f7f);
                v0 = *(s32 *)(s4 + 0x100);
                if (v0 != 0) {
                    v0 = 0x22b190;
                    {
                        struct stackFrame_60 { u8 b[16]; } stackFrame_60
                            __attribute__((aligned(16))) = {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00}};
                        a0 = (void *)((u8 *)&stackFrame_60);
                        f4 = 32.0f;
                        f3 = 320.0f;
                        f1 = 34.0f;
                        f0 = 240.0f;
                        v0 = GameSt.Brightness;
                        v0 = v0 + 0x80;
                        *(u32 *)((u8 *)&stackFrame_60) = v0;
                        *(u32 *)((u8 *)&stackFrame_60 + 0x4) = v0;
                        *(u32 *)((u8 *)&stackFrame_60 + 0x8) = v0;
                        v0 = *(s32 *)(s4 + 0xfc);
                        s1 = ((s32)(32.0f + (((*(float *)(s4 + 0xe0) +
                            (float)((float)(s32)(u32)((u32)s2 * v0))) - 32.0f) - 320.0f)));
                        s0 = ((s32)((34.0f + *(float *)(s4 + 0xe4)) - 240.0f));
                        v0 = MsgFileMng_GetTexId((void *)*(s32 *)(s4 + 0x20));
                        a3 = 0x20;
                        SetSprite((void *)((u8 *)&stackFrame_70[0]), s1, s0, a3, a3, (signed int
                            *)(u8 *)((u8 *)&stackFrame_60), v0, 0);
                        MakeAndKickSpritePacket((void *)((u8 *)&stackFrame_70[0]));
                    }
                }
                v1 = GameSt.GameMode;
                if (v1 != (u32)1) {
                    v1 = *(u8 *)(s4 + 0x78);
                    a0 = (void *)(s32)0x1c8;
                    if (v1 == (u32)3) {
                        Msg_DrawPageIcon((signed int)a0, 0x194);
                    }
                }
                FontDrawEnd();
            }
            v0 = 1;
        }
    }
    return v0;
}


/* MsgMng_Delete @ 0x17B830 .. 0x17B8A0 (0x70 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MsgMng_Delete(void *a0 /* r4 */) {
    u8 *s0;

    s0 = (u8 *)a0;
    if ((u32)s0 == 0) {
        return 0;
    }
    a0 = (void *)(s0 + 0x2c);
    if ((u32)s0 != 0) {
        ListMng_Delete(a0);
        MemFree((void *)*(s32 *)(s0 + 0x28));
        *(u32 *)(s0 + 0x28) = 0;
        MemFree((void *)*(s32 *)(s0 + 0xd4));
        *(u32 *)(s0 + 0xd4) = 0;
        MemFree((void *)*(s32 *)(s0 + 0xd8));
        *(u32 *)(s0 + 0xd8) = 0;
    }
    *(u32 *)s0 = 0;
    return 1;
}








extern signed int ListMng_AddList(void *, unsigned char *);
typedef struct Msg24Payload { s32 words[22]; } Msg24Payload;
signed int MsgMng_SendMsg(void *object, Msg24Payload *source) {
    Msg24Payload message = *source;
    u8 *ctrl = (u8 *)object;
    u32 queued;
    if (!ctrl) return 0;
    queued = 1;
    if (!ctrl[0x78]) {
        *(Msg24Payload *)(ctrl + 0x74) = message;
        **(u16 **)(ctrl + 0xd8) = 0;
        *(u32 *)(ctrl + 0x204) = 0;
        queued = 0;
    }
    if (queued == 1 && *(s32 *)(ctrl + 0x74) < message.words[0] && ctrl) {
        (*(u32 *)(ctrl + 0x204))++;
    }
    if (queued == 1) {
        s32 current = *(s32 *)(ctrl + 0x74);
        if (current == message.words[0]) {
            if (((u64)((u8 *)&message)[20] << 62 >> 63) == 1) {
                if (ctrl) (*(u32 *)(ctrl + 0x204))++;
            } else if (!current && ctrl) (*(u32 *)(ctrl + 0x204))++;
        }
    }
    if (queued == 1) ListMng_AddList(ctrl + 0x2c, (u8 *)&message);
    return 1;
}


/* MsgMng_MsgClearCounterUp @ 0x17B6A0 .. 0x17B6C8 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int MsgMng_MsgClearCounterUp(void *a0 /* r4 */) {
    s32 v0;
    u32 v1;

    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    v1 = *(s32 *)(((u8 *)a0 + 0x204));
    v0 = 1;
    v1 = v1 + 1;
    *(u32 *)(((u8 *)a0 + 0x204)) = v1;
    return v0;
}


/* MsgMng_ClearList @ 0x17B620 .. 0x17B69C (0x7c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MsgMng_ClearList(void *a0 /* r4 */) {
    u8 *s1;
    s32 s0;
    u32 v0;

    v0 = *(u8 *)(((u8 *)a0 + 0x78));
    s1 = (u8 *)a0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        *(u8 *)(s1 + 0x78) = 0;
        *(u32 *)(s1 + 0xf4) = 0;
        v0 = *(s32 *)(s1 + 0x24);
        s0 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            do {
                ListMng_RemoveList((void *)(u8 *)(s1 + 0x2c));
                v0 = *(s32 *)(s1 + 0x24);
                s0 = s0 + 1;
                v0 = (u32)s0 < v0;
            } while (v0 != 0);
        }
        v0 = 1;
    }
    return v0;
}

