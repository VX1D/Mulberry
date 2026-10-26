#include "common.h"

/* Msg_DrawPageIcon @ 0x185110 .. 0x185310 (0x200 bytes, frame 0x140) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @799 -> 0x22b2c0
 *   literal: @848 is the string 'fe_me_0023.tm2'
 *   fpu: mtc1 reinterprets v1 at 0x185178
 *   fpu: mtc1 reinterprets v0 at 0x185180
 *   stack: address of the slot at 0x50 escapes at 0x1851ac
 *   stack: address of the slot at 0x40 escapes at 0x1851ac
 *   fpu: float literal 0x41f00000 at 0x1851bc
 *   fpu: mtc1 reinterprets v0 at 0x1851dc
 *   fpu: float literal 0x41c00000 at 0x1851e4
 *   fpu: mtc1 reinterprets a1 at 0x185218
 *   fpu: mtc1 reinterprets v1 at 0x185220
 *   fpu: float literal 0x00000000 at 0x18524c
 *   fpu: float literal 0x3f800000 at 0x1852bc
 *   fpu: float literal 0x42700000 at 0x1852d8
 *   stack: address of the slot at 0x50 escapes at 0x1852f0
 *   literal: @799 initializes the 16-byte local at 0x40
 *   declaration vs inferred signature: return void vs inferred u32
 */


typedef struct {
    long unsigned int TBP0 : 14;
    long unsigned int TBW : 6;
    long unsigned int PSM : 6;
    long unsigned int TW : 4;
    long unsigned int TH : 4;
    long unsigned int TCC : 1;
    long unsigned int TFX : 2;
    long unsigned int CBP : 14;
    long unsigned int CPSM : 4;
    long unsigned int CSM : 1;
    long unsigned int CSA : 5;
    long unsigned int CLD : 3;
} MsgGsTex0;
typedef struct { u8 pad[0x10]; MsgGsTex0 tex0; } MsgTM2;
typedef struct { u8 bUse; u8 unused0; u16 id; MsgTM2 *lpTm2; } MsgTEXMNG;
extern MsgTEXMNG *GetTexMngByName(void *, char *);
extern void MakeAndKickSpritePacket(void *);
extern u8 GameSt[];
extern f32 s_page_send_icon_flick_counter;

#ifndef PROTO_DW_1160340_FIELDS
#define PROTO_DW_1160340_FIELDS
struct dw_1160340_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

typedef struct {
    u_short bUse : 1;
    u_short Fst : 1;
    u_short Alpha : 2;
    u_short LoadOff : 1;
    u_short unused : 11;
    u_short texID;
    u_char pad0[12];
    int ver[4][4];
    int col[4][4];
    union {
        int uv[4][4];
        float st[4][4];
    };
    u_char tex0[8];
    u_char tex1[8];
    u_char test[8];
    u_char pad1[8];
} SPD;
extern void SetSprite(SPD *lpSp, int PosX, int PosY, int w, int h, int *col, u_short texID, u_char Fst);


/* MSG_MNG__MsgWorkingCallBack @ 0x185310 .. 0x185390 (0x80 bytes, frame 0x220) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x20 escapes at 0x185330
 *   stack: address of the slot at 0x20 escapes at 0x185348
 *   stack: address of the slot at 0x20 escapes at 0x185374
 *   a2 takes slot 2 only because of the ABI order
 *   a3 takes slot 3 only because of the ABI order
 *   t0 takes slot 4 only because of the ABI order
 *   declaration vs inferred signature: 3 parameters vs 6 inferred
 */

extern signed int FsFontReplaceText(void *, void *, ...);
extern void * memcpy(void *, void *, unsigned int);

/* MSG_MNG__EndCallBack @ 0x185390 .. 0x18547C (0xec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x185434
 *   a0 takes slot 0 only because of the ABI order
 *   t1 takes slot 5 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 5 parameters vs 7 inferred
 */

extern void SetMyControlOn();
extern void SetMyDizzy(signed int);
extern void FECard_Enable_Draw(signed int);
extern signed int TmpMenuMng_SetUDBlackDraw(void *, int);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void StopVagStm(unsigned char);
extern u32 s_MsgDizzyOffFlag;
extern u32 g_TmpMenuMng[];
extern u32 MdlMng[];


/* MSG_MNG__StartCallBack @ 0x185480 .. 0x185580 (0x100 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x18553c
 *   a0 takes slot 0 only because of the ABI order
 *   t1 takes slot 5 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 5 parameters vs 7 inferred
 */

extern void SetMyControlOff();




extern signed int PlayVoiceVagStm(signed int);


/* Msg_GetDizzyOffFlag @ 0x185580 .. 0x185588 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x185584 computes the return value
 */

extern u32 s_MsgDizzyOffFlag;
static float s_page_send_icon_flick_counter;
static u32 s_MsgDizzyOffFlag;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 Msg_GetDizzyOffFlag(void);
void MSG_MNG__StartCallBack(unsigned int a0, unsigned int user_data, unsigned int sys_data, signed int gene_id1, signed int gene_id2, s32 t1, u8 *pMsgData);
void MSG_MNG__EndCallBack(unsigned int a0, unsigned int user_data, signed int sys_data, signed int gene_id1, void *t0, s32 t1, u32 *pMsgData);
void MSG_MNG__MsgWorkingCallBack(unsigned char *a0 , unsigned int a1 , signed int a2 , s32 a3, s32 t0, u8 *t1);
void Msg_DrawPageIcon(signed int pos_x, signed int pos_y);


u32 Msg_GetDizzyOffFlag(void) {
    return s_MsgDizzyOffFlag;
}




void MSG_MNG__StartCallBack(unsigned int a0, unsigned int user_data, unsigned int sys_data,
        signed int gene_id1, signed int gene_id2, s32 t1, u8 *pMsgData) {
    s_MsgDizzyOffFlag = 1;
    SetMyControlOff();
    SetMyDizzy(0);
    FECard_Enable_Draw(0);
    if (!(sys_data & 2)) {
        SetMyControlOff();
        SetMyDizzy(0);
        FECard_Enable_Draw(0);
        TmpMenuMng_SetUDBlackDraw(g_TmpMenuMng, 0);
    }
    if (user_data & 2) {
        u8 *mdl = (u8 *)MdlMng + gene_id1 * 0x1c0;
        if (*mdl != 0 && gene_id1 >= 0 && gene_id2 >= 0) {
            ChangeAnimParam(mdl, gene_id2, 0.0f);
        }
    }
    if (user_data & 0x10) {
        *(s32 *)(pMsgData + 0x24) = PlayVoiceVagStm(*(s32 *)(pMsgData + 0x18));
    }
}

void MSG_MNG__EndCallBack(unsigned int a0, unsigned int user_data, signed int sys_data, signed int gene_id1, void *t0, s32 t1, u32 *pMsgData) {
    u8 *mdl;
    u32 id;

    if (((u32)sys_data & 2) == 0) {
        if ((user_data & 1) == 0) {
            SetMyControlOn();
            SetMyDizzy(1);
            s_MsgDizzyOffFlag = 0;
        }
        FECard_Enable_Draw(1);
        TmpMenuMng_SetUDBlackDraw((void *)g_TmpMenuMng, 1);
    }
    if (user_data & 4) {
        mdl = (u8 *)MdlMng + gene_id1 * 0x1c0;
        if (*mdl != 0 && gene_id1 >= 0 && (s32)t0 >= 0) {
            ChangeAnimParam(mdl, (s32)t0, 0.0f);
        }
    }
    if (user_data & 0x10) {
        if ((id = pMsgData[9]) != 0) {
            StopVagStm((u8)id);
        }
    }
}

void MSG_MNG__MsgWorkingCallBack(unsigned char *a0 /* r4 */, unsigned int a1 /* r5 */, signed int
        a2 /* r6 */, s32 a3, s32 t0, u8 *t1) {
    u8 *a0_2;
    u32 s0;
    u32 v1;
    u32 v0;
    u8 stackFrame_20[512] __attribute__((aligned(16)));

    v1 = (u32)(a1) & 8;
    s0 = (u32)a0;
    if (v1 != 0) {
        FsFontReplaceText((void *)((u8 *)&stackFrame_20[0]), (void *)s0, (s32)t1);
        v0 = *(u16 *)((u8 *)&stackFrame_20[0]);
        a0_2 = (u8 *)0;
        if (v0 != 0) {
            v1 = (u32)((u8 *)&stackFrame_20[0]);
            do {
                v1 = v1 + 2;
                v0 = *(u16 *)v1;
                a0_2 = (u8 *)(a0_2 + 1);
            } while (v0 != 0);
        }
        memcpy((void *)s0, (void *)((u8 *)&stackFrame_20[0]), (u32)((u32)a0_2 << 1) + 2);
    }
    return;
}
void Msg_DrawPageIcon(signed int pos_x, signed int pos_y) {
    SPD pSprite;
    int col[4] = {0, 0, 0, 0x80};
    MsgTEXMNG *pTex;
    int texW;
    int texH;
    int posx;
    int posy;
    int brt;

    brt = ((struct dw_1160340_fields *)GameSt)->Brightness + 0x80;
    col[0] = brt;
    col[1] = brt;
    col[2] = brt;
    pTex = GetTexMngByName(0, "fe_me_0023.tm2");
    if (pTex != 0) {
        SetSprite(&pSprite, (s32)(float)(pos_x - 0x10c), (s32)(float)(pos_y - 0xec), 0x18, 0x18, col, pTex->id, 0);
        posy = !(s_page_send_icon_flick_counter < 30.0f);
        texW = 1 << pTex->lpTm2->tex0.TW;
        texH = 1 << pTex->lpTm2->tex0.TH;
        posx = (int)((float)texW * ((24.0f * (float)posy) / (float)texW));
        pSprite.uv[2][0] = pSprite.uv[0][0] = posx << 4;
        posy = (int)((0.0f / (float)texH) * (float)texH);
        pSprite.uv[1][1] = pSprite.uv[0][1] = posy << 4;
        pSprite.uv[3][0] = pSprite.uv[1][0] = (posx + (int)((24.0f / (float)texW) * (float)texW)) << 4;
        pSprite.uv[3][1] = pSprite.uv[2][1] = (posy + (int)((24.0f / (float)texH) * (float)texH)) << 4;
        if (((struct dw_1160340_fields *)GameSt)->Pause == 0) {
            s_page_send_icon_flick_counter = s_page_send_icon_flick_counter + 1.0f;
        }
        if (!(s_page_send_icon_flick_counter < 60.0f)) {
            s_page_send_icon_flick_counter = 0.0f;
        }
        MakeAndKickSpritePacket(&pSprite);
    }
}
