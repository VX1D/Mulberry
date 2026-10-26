#include "common.h"

/* _DrawFont @ 0x191680 .. 0x191750 (0xd0 bytes, frame 0x2a0) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1916a4 is a float copy
 *   fpu: mov.s at 0x1916ac is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x1916ec
 *   fpu: mov.s at 0x191718 is a float copy
 *   fpu: mov.s at 0x191724 is a float copy
 *   stack: address of the slot at 0x30 escapes at 0x191720
 */

extern signed int FsFontReplaceText(void *, void *, ...);
extern void SetFontColorRGBA(unsigned int);
extern void FontDrawBegin(int);
extern void FontPrintXY(float, float, char *, ...);
extern void FontDrawEnd(void);
extern void SetLastFontColor(void);

/* FECard_CancelVannishAll @ 0x191750 .. 0x1917B0 (0x60 bytes) */

extern u16 s_aCardWnd[];

/* FECard_CancelVanish @ 0x1917B0 .. 0x191864 (0xb4 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

extern u16 s_aCardWnd[];

extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_DrawSprite_Scr(float *, void *, float, void *, void *);
extern void SfxDraw_SetRenderStateBlock(u_long128);
#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
typedef struct CardDrawVector { float value[4]; } CardDrawVector __attribute__((aligned(16)));
#endif
extern u8 GameSt[];
extern u8 s_aFade[];
extern void *s_pReloadTex;
extern u16 s_aNumAnimH[];
extern u16 s_aNumAnimV[];


struct CFTex0 { unsigned long pad : 26; unsigned long TW : 4; unsigned long TH : 4; };









#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
 
#endif





extern u16 s_aAnimTime[];

struct RlTex0 { unsigned long pad : 26; unsigned long TW : 4; unsigned long TH : 4; };










#ifndef FE_CARD_VANISH_TYPES
#define FE_CARD_VANISH_TYPES
typedef struct {
    u_long TBP0 : 14;
    u_long TBW : 6;
    u_long PSM : 6;
    u_long TW : 4;
    u_long TH : 4;
    u_long TCC : 1;
    u_long TFX : 2;
    u_long CBP : 14;
    u_long CPSM : 4;
    u_long CSM : 1;
    u_long CSA : 5;
    u_long CLD : 3;
} FECardGsTex0;

typedef struct {
    unsigned int size;
    unsigned int wnum;
    unsigned char dummy[5];
    unsigned char compare;
    unsigned short tex_id;
    FECardGsTex0 tex0;
} FECardTm2;

typedef struct {
    unsigned char bUse;
    unsigned char unused0;
    unsigned short id;
    FECardTm2 *lpTm2;
} FECardTex;

typedef struct {
    float pos[4];
    unsigned short frame;
    unsigned short frame_phase;
    unsigned short wnd_state;
    unsigned short wnd_btn;
    FECardTex *pBaseTex;
} FECardWnd;
#endif

extern u32 s_apBurnTex[2];

#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
 
#endif


extern u32 s_apBurnTex[];


extern u16 s_aAnimTime[];
static void _CardFuncs_Draw_Stable(void *a0 );
static inline void _CardFuncs_Draw_Stable(void *);


/* _CardFuncs_Draw_Stable @ 0x192BC0 .. 0x192CBC (0xfc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1121 -> 0x22c460
 *   literal: @1123 -> 0x22c470
 *   fpu: float literal 0x3f800000 at 0x192c2c
 *   fpu: float literal 0x43000000 at 0x192c3c
 *   fpu: float literal 0x3fc90fdb at 0x192c48
 *   fpu: mtc1 reinterprets v0 at 0x192c7c
 *   stack: address of the slot at 0x40 escapes at 0x192c98
 *   stack: address of the slot at 0x30 escapes at 0x192c98
 *   literal: @1123 initializes the 16-byte local at 0x30
 *   literal: @1121 initializes the 16-byte local at 0x40
 *   quad: a0: 128-bit web split from its scalar variable as a0_q
 *   quad: v0: 128-bit web split from its scalar variable as v0_q2
 */

extern u_long128 SfxDraw_GetRenderStateBlock(void);
extern void SfxDraw_SetBlendType(unsigned short);
extern void SfxDraw_EnableZTest(signed int);
extern void SfxDraw_UseST(signed int);
extern void SfxDraw_SetTexture(void *);
extern void SfxDraw_DrawSprite_Scr(float *, void *, float, void *, void *);
extern void SfxDraw_SetRenderStateBlock(u_long128);
extern u32 L1121[];
static u16 s_aCardWnd[0xa0];
static u8 s_aFade[0x3c];
extern u8 GameSt[];
extern u32 L1123[];
void _CardFuncs_Act_Blood(void *card);

/* These definitions occupy the missing .data prefix before Stable's two local templates. */
extern void _CardFuncs_Act_Blood(void *);
static void _CardFuncs_Act_CrossFade(void *a0 );
static void _CardFuncs_Act_CrossFade(void *a0 /* r4 */);
static void _CardFuncs_Act_Reload(void *a0 );
static void _CardFuncs_Act_Reload(void *a0 /* r4 */);
static void _CardFuncs_Act_Stable(u8 *a0 );
static void _CardFuncs_Act_Stable(u8 *a0 /* r4 */);
static void _CardFuncs_Act_Vanish(void *a0 );
static void _CardFuncs_Act_Vanish(void *a0 /* r4 */);
static void _CardFuncs_Draw_Blood(u8 *pWnd_);
static void _CardFuncs_Draw_Blood(u8 *pWnd_);
static void _CardFuncs_Draw_CrossFade(u8 *pWnd_);
static void _CardFuncs_Draw_CrossFade(u8 *pWnd_);
static void _CardFuncs_Draw_Reload(u8 *pWnd_);
static void _CardFuncs_Draw_Reload(u8 *pWnd_);
static void _CardFuncs_Draw_Stable(void *a0 /* r4 */);
void _CardFuncs_Draw_Vanish(void *arg);
extern void _CardFuncs_Draw_Vanish(void *);
static u32 s_aCardFuncs[0xa] = {
    (u32)&_CardFuncs_Act_Stable, (u32)&_CardFuncs_Draw_Stable, (u32)&_CardFuncs_Act_Blood,
    (u32)&_CardFuncs_Draw_Blood, (u32)&_CardFuncs_Act_Vanish, (u32)&_CardFuncs_Draw_Vanish,
    (u32)&_CardFuncs_Act_Reload, (u32)&_CardFuncs_Draw_Reload, (u32)&_CardFuncs_Act_CrossFade,
    (u32)&_CardFuncs_Draw_CrossFade
};
typedef struct FECardSlots { u16 s[3]; } FECardSlots;
static FECardSlots s_FECardSlots;
static inline u32 FECardSlot(u32 btn) {
    FECardSlots slots = s_FECardSlots;
    return slots.s[btn];
}
#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
typedef struct CardDrawVector { float value[4]; } CardDrawVector __attribute__((aligned(16)));
#endif

/* templates of _CardFuncs_Draw_Stable (@1121, @1123) as statics: shared by the copy inlined into Blood */

/* templates of _CardFuncs_Draw_Blood (@1134, @1137) as statics: fixes the .data order */
/* templates of _CardFuncs_Draw_Reload (@1183, @1191) as statics: fixes the .data order */
/* templates of _CardFuncs_Draw_CrossFade (@1198..@1210), defined as statics to fix the .data order */

/* The BSS order is s_apButtonTex, s_aFade, then s_aCardWnd. */
static void *s_apButtonTex[0x4];
static void *s_pReloadTex;

static u32 s_apBurnTex[2] __attribute__((aligned(4)));

/* _CardFuncs_Act_Reload @ 0x192CF0 .. 0x192D40 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u16 s_aNumAnimH[];
extern u16 s_aNumAnimV[];
extern u16 s_aAnimTime[];

extern u32 MdlMng[];

/* FECard_SetFade @ 0x192F10 .. 0x192F40 (0x30 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u8 *
 */

extern u8 s_aFade[];

extern int ItemMng_GetPcEquip(unsigned short);
extern int ItemMng_GetItemNum_Direct(unsigned short);


#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
 
#endif
extern void sceVu0AddVector(void *, void *, void *);
extern unsigned short *KnMsgMng_GetMsgStr(signed int);


/* _Action @ 0x193260 .. 0x19359C (0x33c bytes, frame 0x80) */
extern int sprintf(char *, const char *, ...);
extern u32 GetGameTexList();
extern void * GetTexMngByName(void *, char *);
extern void * GetMyEquip(void *, signed int);
extern unsigned short ItemMng_GetItemNum(unsigned short, unsigned short);


static inline s32 FECardEquipId(u16 btn) {
    u16 id;
    id = ItemMng_GetPcEquip(FECardSlot(btn));
    return id / 10000 == 3 ? id : 0;
}

static inline void *FECardGetTexB(u16 btn) {
    char szName[16];
    s32 id = FECardEquipId(btn);
    if (0 < id) {
        sprintf(szName, "me_i%05d.tm2", id);
        return GetTexMngByName((void *)GetGameTexList(), szName);
    }
    return 0;
}



/* FECard_Draw @ 0x1935A0 .. 0x19360C (0x6c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int TmpMenuMng_CheckDraw(void *);
static void _Draw(void *card);
static void _Draw(void *);
extern u32 g_TmpMenuMng[];
extern u32 s_bEnableDraw;
extern u16 s_aCardWnd[];
static void _Action(void *pWnd_, float dt_);

static void _Action(void *, float);
extern u8 GameSt[];


typedef struct {
    float cur;
    float min;
    float max;
    float speed;
    u8 state;
} FECardFade;


/* FECard_Initialize @ 0x193750 .. 0x193974 (0x224 bytes, frame 0x80) */
extern int sprintf(char *, const char *, ...);
extern u32 GetGameTexList();
extern void * GetTexMngByName(void *, char *);
extern void sceVu0CopyVector(void *, void *);
extern u32 VW[];
#ifndef CARD_DRAW_VECTOR_TYPE
#define CARD_DRAW_VECTOR_TYPE
#endif
struct FEBtnPair { u8 b[4]; };
struct FECardWnd { float pos[4]; u16 frame; u16 frame_phase; u16 state; u16 btn; void *pBaseTex; void *pFrontTex; void *pNextTex; s16 num; u8 _pad0[2]; int card_id; int next_card_id; u8 dmy[32]; };
#define FEWND ((struct FECardWnd *)s_aCardWnd)


/* FECard_Enable_Draw @ 0x193980 .. 0x193988 (0x8 bytes) */

extern u32 s_bEnableDraw;
static u32 s_bEnableDraw;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void FECard_Enable_Draw(u8 **a0 );
signed int FECard_Initialize(void);
void FECard_Action(float dt_);
void FECard_Draw(void);
static void _Action(void *pWnd_, float dt_);
static void _Draw(void *card);
void FECard_StartVanish(unsigned int card);
void FECard_SetFade(unsigned char a0 , signed int a1 );
static void _CardFuncs_Act_Stable(u8 *a0 );
void _CardFuncs_Act_Blood(void *card);
static void _CardFuncs_Act_Vanish(void *a0 );
static void _CardFuncs_Act_Reload(void *a0 );
static void _CardFuncs_Act_CrossFade(void *a0 );
static void _CardFuncs_Draw_Stable(void *a0 );
static void _CardFuncs_Draw_Blood(u8 *pWnd_);
void _CardFuncs_Draw_Vanish(void *arg);
static void _CardFuncs_Draw_Reload(u8 *pWnd_);
static void _CardFuncs_Draw_CrossFade(u8 *pWnd_);
void FECard_CancelVanish(unsigned short a0 );
void FECard_CancelVannishAll(void);
static void _DrawFont(float f12 , float f13 , unsigned int a0 , char *a1 , ...);


void FECard_Enable_Draw(u8 **a0 /* r4 */) {
    s_bEnableDraw = (u32)a0;
    return;
}

signed int FECard_Initialize(void) {
    int i;
    char szFilename[16];

    for (i = 0; i < 4; i++) {
        sprintf(szFilename, "fe_%03d.tm2", i);
        s_apButtonTex[i] = GetTexMngByName((void *)GetGameTexList(), szFilename);
    }
    s_apBurnTex[0] = (u32)GetTexMngByName((void *)GetGameTexList(), "moe00.tm2");
    s_apBurnTex[1] = (u32)GetTexMngByName((void *)GetGameTexList(), "moe02.tm2");
    s_pReloadTex = GetTexMngByName((void *)GetGameTexList(), "pero.tm2");
    {
        int i;
        u16 aBtn[2] = {0, 1};
        struct FECardWnd *pWnd;
        for (i = 0, pWnd = FEWND; i < 2; i++) {
            sceVu0CopyVector(pWnd, VW);
            pWnd->frame = 0;
            pWnd->frame_phase = 0;
            pWnd->btn = aBtn[i];
            pWnd->state = 0;
            pWnd->num = 0;
            pWnd->card_id = 0;
            pWnd->next_card_id = 0;
            pWnd->pBaseTex = 0;
            pWnd->pFrontTex = 0;
            pWnd->pNextTex = 0;
            pWnd++;
        }
    }
    {
        float pos[4] = {470.0f, 345.0f, 0.0f, 1.0f};
        float offset[4] = {-40.0f, 10.0f, 0.0f, 0.0f};
        struct FECardWnd *pWnd;
        int i;
        for (i = 0, pWnd = FEWND; i < 2; i++) {
            sceVu0CopyVector(pWnd, pos);
            sceVu0AddVector(pos, offset, pos);
            pWnd++;
        }
    }
    *(float *)s_aFade = 1.0f;
    *(float *)(s_aFade + 4) = 0.0f;
    *(float *)(s_aFade + 8) = 1.0f;
    *(float *)(s_aFade + 0xc) = 1.0f;
    s_aFade[0x10] = 3;
    *(float *)(s_aFade + 0x14) = 1.0f;
    *(float *)(s_aFade + 0x18) = 0.1f;
    *(float *)(s_aFade + 0x1c) = 1.0f;
    *(float *)(s_aFade + 0x20) = 0.9f;
    s_aFade[0x24] = 3;
    *(float *)(s_aFade + 0x28) = 1.0f;
    *(float *)(s_aFade + 0x2c) = 0.0f;
    *(float *)(s_aFade + 0x30) = 1.0f;
    *(float *)(s_aFade + 0x34) = 1.0f;
    s_aFade[0x38] = 3;
    s_bEnableDraw = 1;
    return 1;
}
static FECardSlots s_FECardSlots __attribute__((aligned(4))) = {{1, 0, 0xff}};



void FECard_Action(float dt_) {
    s32 i;
    FECardFade *f;

    ((FECardFade *)s_aFade)->state = (GameSt[0xe] == 0 && GameSt[5] == 0) ? 2 : 1;
    for (i = 0; i < 2; i++) {
        _Action((u8 *)s_aCardWnd + i * 0x50, dt_);
    }
    for (i = 0; i < 3; i++) {
        f = (FECardFade *)s_aFade + i;
        if (f->state == 2) {
            f->cur += dt_ * f->speed;
            if (f->max <= f->cur) {
                f->cur = f->max;
                f->state = 3;
            }
        } else if (f->state == 1) {
            f->cur -= dt_ * f->speed;
            if (f->cur <= f->min) {
                f->cur = f->min;
                f->state = 0;
            }
        }
    }
}

void FECard_Draw(void) {
    u8 *a0;
    u32 v0;
    u32 v1;
    s32 s1;
    u8 *s0;

    a0 = (u8 *)g_TmpMenuMng;
    v0 = TmpMenuMng_CheckDraw((void *)g_TmpMenuMng);
    if (v0 == 0) {
        v1 = s_bEnableDraw;
        if (v1 != 0) {
            s1 = 0;
            s0 = (u8 *)s_aCardWnd;
            do {
                _Draw((void *)(u8 *)s0);
                s1 = s1 + 1;
                s0 = (u8 *)(s32)((u8 *)s0 + 0x50);
                v1 = s1 < (s32)2;
            } while (v1 != 0);
        }
    }
    return;
}
static void _Action(void *pWnd_, float dt_) {
    u8 *w = (u8 *)pWnd_;
    u16 item_id;
    u16 item_num;
    u8 *pEquip;

    if (*(u16 *)(w + 0x14) != 0) {
        *(u16 *)(w + 0x10) += 2;
        *(u16 *)(w + 0x12) += 2;
    }
    ((void (*)(void *))s_aCardFuncs[*(u16 *)(w + 0x14) * 2])(w);
    item_id = FECardEquipId(*(u16 *)(w + 0x16));
    item_num = ItemMng_GetItemNum_Direct(item_id);
    if (0 < (s32)item_num) {
        if (*(u16 *)(w + 0x14) == 0) {
            *(u32 *)(w + 0x28) = FECardEquipId(*(u16 *)(w + 0x16));
            *(void **)(w + 0x18) = FECardGetTexB(*(u16 *)(w + 0x16));
        } else {
            *(u32 *)(w + 0x2c) = item_id;
            *(void **)(w + 0x20) = FECardGetTexB(*(u16 *)(w + 0x16));
        }
    } else {
        *(u32 *)(w + 0x2c) = 0;
        *(u32 *)(w + 0x20) = 0;
    }
    pEquip = (u8 *)GetMyEquip(MdlMng + 0x4600, FECardSlot(*(u16 *)(w + 0x16)));
    if (pEquip != 0 && pEquip[0] == 1) {
        *(u16 *)(w + 0x24) = ItemMng_GetItemNum(3, *(u16 *)(pEquip + 4));
    } else {
        *(u16 *)(w + 0x24) = 0;
    }
}
static void _Draw(void *card) {
    u8 *window = card;
    u_long128 state;
    u32 color;
    ((void (*)(void *))s_aCardFuncs[1 + *(u16 *)(window + 0x14) * 2])(card);
    if (*(u32 *)(window + 0x18)) {
        state = SfxDraw_GetRenderStateBlock();
        SfxDraw_SetBlendType(0);
        SfxDraw_EnableZTest(0);
        SfxDraw_UseST(0);
        {
            CardDrawVector size = {{20.0f, 20.0f, 1.0f, 1.0f}};
            CardDrawVector position = {{-15.0f, -44.8f, 0.0f, 0.0f}};
            void *texture = s_apButtonTex[*(u16 *)(window + 0x16)];
            CardDrawVector colorVector = {{1.0f, 1.0f, 1.0f, 0.0f}};
            char text[256] __attribute__((aligned(16)));
            colorVector.value[3] = *(float *)(s_aFade + 40) * (*(float *)s_aFade * *(float *)(s_aFade + 20));
            if (texture) {
                float brightness;
                sceVu0AddVector(position.value, position.value, window);
                SfxDraw_SetTexture(s_apButtonTex[*(u16 *)(window + 0x16)]);
                brightness = 1.0f + (float)*(s8 *)(GameSt + 30) / 128.0f;
                colorVector.value[2] = brightness;
                colorVector.value[1] = brightness;
                colorVector.value[0] = brightness;
                SfxDraw_DrawSprite_Scr(position.value, size.value, 0.0f, colorVector.value, 0);
            }
            color = (u32)(127.0f * (*(float *)(s_aFade + 40) * (*(float *)s_aFade * *(float *)(s_aFade + 20)))) | 0x7f7f7f00;
            FsFontReplaceText(text, KnMsgMng_GetMsgStr(0x186dd), (u32)*(s16 *)(window + 0x24));
            _DrawFont(*(float *)window - 20.0f, 45.0f + *(float *)(window + 4), color, text);
            SfxDraw_SetRenderStateBlock(state);
        }
    }
}
void FECard_StartVanish(unsigned int card) {
    u32 index = (u16)card;
    u32 offset = index << 2;
    offset += index;
    offset <<= 4;
    if (*(u32 *)((u32)(s_aCardWnd + 0xc) + offset)) {
        *(u16 *)((u32)(s_aCardWnd + 8) + offset) = 0;
        *(u16 *)((u32)(s_aCardWnd + 9) + offset) = 0;
        *(u16 *)((u32)(s_aCardWnd + 0xa) + offset) = 1;
    }
    {
        if ((u16)ItemMng_GetItemNum_Direct((u16)ItemMng_GetPcEquip(FECardSlot(index))) == 0) {
            int offset = (index * 5) << 4;
            *(u32 *)((u32)(s_aCardWnd + 0x16) + offset) = 0;
            *(u32 *)((u32)(s_aCardWnd + 0x10) + offset) = 0;
        }
    }
}

void FECard_SetFade(unsigned char a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a0_word = a0;

    a0_word = (u8)a0_word;
    *(u8 *)(u32)(s32)((u8 *)(u8 *)(s_aFade + 0x10) + (u32)(((s32)(a0_word << 2) + a0_word) << 2)) = (u32)(s32)a1 != 0 ?
        (s32)2 : (s32)1;
    return;
}


/* _CardFuncs_Act_Stable @ 0x192F00 .. 0x192F08 (0x8 bytes) */
/*
 * dcomp notes:
 *   a0 typed from the _CardFuncs_Act_Stable call table
 */

static void _CardFuncs_Act_Stable(u8 *a0 /* r4 */) {
    return;
}
void _CardFuncs_Act_Blood(void *card)
{
    float initialFloat;
    s16 initialShort;
    u32 model;
    u32 index;
    s32 kind;
    u16 slots[3];
    u16 *slotPtr;
    initialFloat = *(float *)&s_FECardSlots;
    initialShort = *(s16 *)&s_FECardSlots.s[2];
    slotPtr = slots;
    __asm__ volatile("" : "+r"(slotPtr));
    *(float *)slotPtr = initialFloat;
    slotPtr[2] = initialShort;
    model = slots[*(u16 *)((u8 *)card + 22)];
    index = model + 211;
    model = index * 448;
    model = (u32)((u8 *)MdlMng + model);
    kind = 0;
    if (*(volatile u8 *)model) kind = *(u16 *)*(u32 *)(*(u32 *)(model + 12) + 76) != 8;
    if (kind) {
        __asm__ volatile(
            ".set noreorder\n"
            "lbu $v1, 0(%0)\n"
            ".word 0x10600004\n"
            "daddu $v1, $zero, $zero\n"
            "lw $v1, 0xc(%0)\n"
            "lw $v1, 0x4c($v1)\n"
            "lw $v1, 4($v1)\n"
            "1:\n"
            "lwc1 $f0, 0x120(%0)\n"
            "lui $a2, 0x3f80\n"
            "mtc1 $v1, $f1\n"
            "nop\n"
            "cvt.s.w $f1, $f1\n"
            "lui $v1, 0x4f00\n"
            "lui $a1, 0x4280\n"
            "cvt.s.w $f0, $f0\n"
            "div.s $f2, $f0, $f1\n"
            "mtc1 $a2, $f1\n"
            "mtc1 $a1, $f0\n"
            "nop\n"
            "sub.s $f1, $f1, $f2\n"
            "mul.s $f1, $f0, $f1\n"
            "mtc1 $v1, $f0\n"
            "nop\n"
            "c.le.s $f0, $f1\n"
            ".word 0x45010005\n"
            "nop\n"
            "cvt.w.s $f1, $f1\n"
            "mfc1 $a1, $f1\n"
            ".word 0x10000008\n"
            "sh $a1, 0x12(%1)\n"
            "2:\n"
            "sub.s $f1, $f1, $f0\n"
            "lui $v1, 0x8000\n"
            "cvt.w.s $f1, $f1\n"
            "mfc1 $a1, $f1\n"
            "nop\n"
            "or $a1, $a1, $v1\n"
            "sh $a1, 0x12(%1)\n"
            "3:\n"
            ".set reorder\n"
            : "+r"(model)
            : "r"(card)
            : "$3", "$6", "$7", "$f0", "$f1", "$f2", "memory");
    }
    if (*(u16 *)((u8 *)card + 18) >= 64) {
        *(u16 *)((u32)card + 18) = 0;
        (*(u16 *)((u8 *)card + 20))++;
    }
}

/* _CardFuncs_Act_Vanish @ 0x192D40 .. 0x192DC8 (0x88 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */





static void _CardFuncs_Act_Vanish(void *a0 /* r4 */) {
    u16 a3;
    u16 a2;
    u16 a1;
    u8 *a0_bytes; // a0
    u32 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(u16 *)(a0_bytes + 0x12);
    a3 = s_aNumAnimH[1];
    a2 = s_aNumAnimV[1];
    a1 = s_aAnimTime[1];
    if ((s32)(u16)((u32)a1 * (u32)((u32)a3 * (u32)a2)) <= (s32)v1) {
        *(u16 *)(a0_bytes + 0x12) = 0;
        v1 = *(s32 *)(a0_bytes + 0x2c);
        *(u32 *)(a0_bytes + 0x28) = v1;
        v1 = *(s32 *)(a0_bytes + 0x20);
        *(u32 *)(a0_bytes + 0x18) = v1;
        *(u32 *)(a0_bytes + 0x2c) = 0;
        *(u32 *)(a0_bytes + 0x20) = 0;
        v1 = *(s32 *)(a0_bytes + 0x18);
        if (v1 != 0) {
            v1 = *(u16 *)(a0_bytes + 0x14);
            *(u16 *)(a0_bytes + 0x14) = v1 + 1;
        } else {
            *(u16 *)(a0_bytes + 0x10) = 0;
            *(u16 *)(a0_bytes + 0x12) = 0;
            *(u16 *)(a0_bytes + 0x14) = 0;
        }
    }
    return;
}

static void _CardFuncs_Act_Reload(void *a0 /* r4 */) {
    u16 a3;
    u16 a2;
    u16 a1;
    u8 *a0_bytes; // a0
    u16 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(u16 *)(a0_bytes + 0x12);
    a3 = s_aNumAnimH[2];
    a2 = s_aNumAnimV[2];
    a1 = s_aAnimTime[2];
    if ((s32)(u16)((u32)a1 * (u32)((u32)a3 * (u32)a2)) <= (s32)v1) {
        *(u16 *)(a0_bytes + 0x12) = 0;
        v1 = *(u16 *)(a0_bytes + 0x14);
        *(u16 *)(a0_bytes + 0x14) = (u32)(v1) + 1;
    }
    return;
}


/* _CardFuncs_Act_CrossFade @ 0x192CC0 .. 0x192CE8 (0x28 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

static void _CardFuncs_Act_CrossFade(void *a0 /* r4 */) {
    u8 *a0_bytes; // a0
    u16 v1;

    a0_bytes = (u8 *)a0;
    v1 = *(u16 *)(a0_bytes + 0x12);
    if ((u32)((s32)v1 < (s32)0x1e) == 0) {
        *(u16 *)(a0_bytes + 0x10) = 0;
        *(u16 *)(a0_bytes + 0x12) = 0;
        *(u16 *)(a0_bytes + 0x14) = 0;
    }
    return;
}

static void _CardFuncs_Draw_Stable(void *a0 /* r4 */) {
    u8 *s1;
    u_long128 v0_q2;
    u_long128 s0;
    u32 v1;
    u32 v0;
    float f2;
    float f1;
    float f0;
    void *a0_2;

    s1 = (u8 *)a0;
    v0_q2 = SfxDraw_GetRenderStateBlock();
    v1 = *(s32 *)(s1 + 0x18);
    s0 = v0_q2;
    if (v1 != 0) {
        SfxDraw_SetBlendType(0);
        SfxDraw_EnableZTest(0);
        SfxDraw_UseST(0);
        SfxDraw_SetTexture((void *)*(s32 *)(s1 + 0x18));
        v0 = (u32)L1121;
        a0_2 = (void *)s1;
        f0 = 1.0f;
        {
            CardDrawVector stackFrame_40 = {{80.0f, 40.0f, 1.0f, 1.0f}};
            f1 = 128.0f;
            {
                CardDrawVector stackFrame_30 = {{1.0f, 1.0f, 1.0f, 0.0f}};
                f2 = (*(volatile float *)(s_aFade + 0x28) * (*(volatile float *)(s_aFade) *
                    *(volatile float *)(s_aFade + 0x14)));
                v0 = *(s8 *)(GameSt + 0x1e);
                *(f32 *)((u8 *)&stackFrame_30 + 0xc) = f2;
                f0 = (1.0f + ((float)((float)(s32)v0) / 128.0f));
                *(f32 *)((u8 *)&stackFrame_30 + 0x8) = f0;
                *(f32 *)((u8 *)&stackFrame_30 + 0x4) = f0;
                *(f32 *)((u8 *)&stackFrame_30) = f0;
                SfxDraw_DrawSprite_Scr((float *)a0_2, (void *)(u8 *)((u8 *)&stackFrame_40),
                    1.57079637f, (void *)(u8 *)((u8 *)&stackFrame_30), (void *)0);
                SfxDraw_SetRenderStateBlock(s0);
            }
        }
    }
    return;
}

static void _CardFuncs_Draw_Blood(u8 *pWnd_) {
    u_long128 sb;
    s32 anim_no;

    sb = SfxDraw_GetRenderStateBlock();
    _CardFuncs_Draw_Stable(pWnd_);
    SfxDraw_EnableZTest(0);
    SfxDraw_SetBlendType(2);
    SfxDraw_UseST(1);
    SfxDraw_SetTexture((void *)s_apBurnTex[0]);
    {
        float aAnimSizeH[2] = {0};
        aAnimSizeH[0] = 1.0f / (float)s_aNumAnimH[0];
        aAnimSizeH[1] = 1.0f / (float)s_aNumAnimH[1];
        {
            float aAnimSizeV[2] = {0};
            float iv;
            iv = 1.0f / (float)s_aNumAnimV[0];
            aAnimSizeV[0] = iv;
            aAnimSizeV[1] = 1.0f / (float)s_aNumAnimV[1];
            {
                CardDrawVector size = {{42.0f, 82.0f, 1.0f, 1.0f}};
                u16 nh;
                nh = s_aNumAnimH[0];
                anim_no = (*(u16 *)(pWnd_ + 0x12) / s_aAnimTime[0]) % (nh * s_aNumAnimV[0]);
                {
                    CardDrawVector color = {{1.0f, 1.0f, 1.0f, 0.0f}};
                    float st[4];
                    *(float *)((u8 *)&color + 0xc) = *(float *)(s_aFade + 0x28) * (*(float *)s_aFade * *(float *)(s_aFade + 0x14));
                    st[0] = (1.0f / (float)nh) * (float)(anim_no % nh);
                    st[1] = iv * (float)(anim_no / nh);
                    st[2] = st[0] + 1.0f / (float)nh;
                    st[3] = st[1] + iv;
                    color.value[0] = color.value[1] = color.value[2] = 1.0f + (float)*(s8 *)(GameSt + 0x1e) / 128.0f;
                    SfxDraw_DrawSprite_Scr((float *)pWnd_, size.value, 0.0f, color.value, st);
                }
            }
        }
    }
    SfxDraw_SetRenderStateBlock(sb);
}

void _CardFuncs_Draw_Vanish(void *arg) {
    FECardWnd *pWnd_ = (FECardWnd *)arg;
    u_long128 sb;

    sb = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetBlendType(0);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(0);
    SfxDraw_SetTexture(pWnd_->pBaseTex);
    {
        float size[4] = { 80.0f, 40.0f, 1.0f, 1.0f };
        float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        float alpha;

        alpha = 1.0f - 2.0f * pWnd_->frame_phase / (u16)(s_aNumAnimH[1] * s_aNumAnimV[1] * s_aAnimTime[1]);
        if (alpha < 0.0f) alpha = 0.0f;
        color[3] = alpha * (*(float *)s_aFade * *(float *)(s_aFade + 0x14) * *(float *)(s_aFade + 0x28));
        color[0] = color[1] = color[2] = 1.0f + (s8)GameSt[0x1e] / 128.0f;
        SfxDraw_DrawSprite_Scr((float *)pWnd_, size, HALF_PI, color, 0);
    }
    SfxDraw_SetBlendType(2);
    SfxDraw_UseST(1);
    SfxDraw_SetTexture((void *)s_apBurnTex[0]);
    {
        float alpha;
        float aAnimSizeH[2] = { 1.0f / s_aNumAnimH[0], 1.0f / s_aNumAnimH[1] };
        float aAnimSizeV[2] = { 1.0f / s_aNumAnimV[0], 1.0f / s_aNumAnimV[1] };
        float size[4] = { 42.0f, 82.0f, 1.0f, 1.0f };
        int anim_no = s_aNumAnimH[0] * s_aNumAnimV[1] - 1;
        float color[4] = { 1.0f, 1.0f, 1.0f, *(float *)s_aFade * *(float *)(s_aFade + 0x14) * *(float *)(s_aFade + 0x28) };
        float st[4];

        alpha = 1.0f - 2.0f * pWnd_->frame_phase / (u16)(s_aNumAnimH[1] * s_aNumAnimV[1] * s_aAnimTime[1]);
        if (alpha < 0.0f) alpha = 0.0f;
        color[3] *= alpha;
        st[0] = (1.0f / s_aNumAnimH[0]) * (anim_no % s_aNumAnimH[0]);
        st[1] = (1.0f / s_aNumAnimV[0]) * (anim_no / s_aNumAnimH[0]);
        st[2] = st[0] + (1.0f / s_aNumAnimH[0]);
        st[3] = st[1] + (1.0f / s_aNumAnimV[0]);
        color[0] = color[1] = color[2] = 1.0f + (s8)GameSt[0x1e] / 128.0f;
        SfxDraw_DrawSprite_Scr((float *)pWnd_, size, 0.0f, color, st);
    }
    SfxDraw_SetBlendType(0);
    SfxDraw_SetTexture((void *)s_apBurnTex[1]);
    SfxDraw_UseST(0);
    {
        float aAnimSizeH[2] = { 1.0f / s_aNumAnimH[0], 1.0f / s_aNumAnimH[1] };
        float aAnimSizeV[2] = { 1.0f / s_aNumAnimV[0], 1.0f / s_aNumAnimV[1] };
        float size[4] = { 80.0f, 160.0f, 1.0f, 1.0f };
        int anim_no = pWnd_->frame_phase / s_aAnimTime[1] % (s_aNumAnimH[1] * s_aNumAnimV[1]);
        float animSizeH1;
        float animSizeV1;
        float st[4] = {
            (animSizeH1 = aAnimSizeH[1]) * (anim_no % s_aNumAnimH[1]),
            (animSizeV1 = aAnimSizeV[1]) * (anim_no / s_aNumAnimH[1]),
            animSizeH1 * (anim_no % s_aNumAnimH[1]) + animSizeH1,
            animSizeV1 * (anim_no / s_aNumAnimH[1]) + aAnimSizeV[0],
        };
        float color[4] = { 1.0f, 1.0f, 1.0f, *(float *)s_aFade * *(float *)(s_aFade + 0x14) * *(float *)(s_aFade + 0x28) };
        st[0] *= (u16)(1 << ((FECardTex *)s_apBurnTex[1])->lpTm2->tex0.TW);
        st[2] *= (u16)(1 << ((FECardTex *)s_apBurnTex[1])->lpTm2->tex0.TW);
        st[1] *= (u16)(1 << ((FECardTex *)s_apBurnTex[1])->lpTm2->tex0.TH);
        st[3] *= (u16)(1 << ((FECardTex *)s_apBurnTex[1])->lpTm2->tex0.TH);
        color[0] = color[1] = color[2] = 1.0f + (s8)GameSt[0x1e] / 128.0f;
        SfxDraw_DrawSprite_Scr((float *)pWnd_, size, 0.0f, color, st);
    }
    SfxDraw_SetRenderStateBlock(sb);
}

static void _CardFuncs_Draw_Reload(u8 *pWnd_) {
    u_long128 sb;
    u_long128 sb2;

    sb = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetBlendType(0);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(0);
    SfxDraw_SetTexture((void *)*(s32 *)(pWnd_ + 0x18));
    {
        CardDrawVector size = {{40.0f, 80.0f, 1.0f, 1.0f}};
        s32 anim_no = (*(u16 *)(pWnd_ + 0x12) / s_aAnimTime[2]) % (s_aNumAnimH[2] * s_aNumAnimH[6]);
        u8 *tm2 = *(u8 **)((u8 *)s_pReloadTex + 4);
        u16 w = 1 << ((struct RlTex0 *)(tm2 + 0x10))->TW;
        u16 h = 1 << ((struct RlTex0 *)(tm2 + 0x10))->TH;
        float st[4] = {0};
        s32 wq = w / s_aNumAnimH[2];
        s32 hq = h / s_aNumAnimH[6];
        s32 x = (s32)(w * (anim_no % s_aNumAnimH[2])) / s_aNumAnimH[2];
        s32 y = (s32)(h * (anim_no / s_aNumAnimH[2])) / s_aNumAnimH[6];
        st[0] = (float)x;
        st[2] = (float)(wq + x);
        st[1] = (float)y;
        st[3] = (float)(hq + y);
        sb2 = SfxDraw_GetRenderStateBlock();
        {
            CardDrawVector color = {{1.0f, 1.0f, 1.0f, 0.0f}};
            color.value[3] = *(float *)(s_aFade + 0x28) * (*(float *)(s_aFade) * *(float *)(s_aFade + 0x14));
            SfxDraw_SetBlendType(0);
            SfxDraw_UseST(0);
            SfxDraw_SetTexture(s_pReloadTex);
            color.value[0] = color.value[1] = color.value[2] = 1.0f + (float)*(s8 *)(GameSt + 0x1e) / 128.0f;
            SfxDraw_DrawSprite_Scr((float *)pWnd_, size.value, 0.0f, color.value, st);
        }
        SfxDraw_SetRenderStateBlock(sb2);
    }
    SfxDraw_SetRenderStateBlock(sb);
}

static void _CardFuncs_Draw_CrossFade(u8 *pWnd_) {
    u_long128 sb;
    float alpha;

    sb = SfxDraw_GetRenderStateBlock();
    SfxDraw_SetBlendType(0);
    SfxDraw_EnableZTest(0);
    SfxDraw_UseST(0);
    SfxDraw_SetTexture((void *)*(s32 *)(pWnd_ + 0x18));
    {
        CardDrawVector size = {{80.0f, 40.0f, 1.0f, 1.0f}};
        {
            CardDrawVector color = {{1.0f, 1.0f, 1.0f, 0.0f}};
            color.value[3] = *(float *)(s_aFade + 0x28) * (*(float *)(s_aFade) * *(float *)(s_aFade + 0x14));
            color.value[0] = color.value[1] = color.value[2] = 1.0f + (float)*(s8 *)(GameSt + 0x1e) / 128.0f;
            SfxDraw_DrawSprite_Scr((float *)pWnd_, size.value, 1.5707964f, color.value, 0);
        }
    }
    SfxDraw_SetBlendType(0);
    SfxDraw_UseST(0);
    SfxDraw_SetTexture(s_pReloadTex);
    {
        CardDrawVector size = {{40.0f, 80.0f, 1.0f, 1.0f}};
        u8 *tm2 = *(u8 **)((u8 *)s_pReloadTex + 4);
        u16 w = 1 << ((struct CFTex0 *)(tm2 + 0x10))->TW;
        u16 h = 1 << ((struct CFTex0 *)(tm2 + 0x10))->TH;
        float st[4] = {0};
        s32 wq = w / s_aNumAnimH[2];
        s32 hq = h / s_aNumAnimH[6];
        s32 x = (s32)(w * (15 % s_aNumAnimH[2])) / s_aNumAnimH[2];
        s32 y = (s32)(h * (15 / s_aNumAnimH[2])) / s_aNumAnimH[6];
        st[0] = (float)x;
        st[2] = (float)(wq + x);
        st[1] = (float)y;
        st[3] = (float)(hq + y);
        {
            CardDrawVector color = {{1.0f, 1.0f, 1.0f, 0.0f}};
            float f0 = *(float *)(s_aFade);
            *(float *)((u8 *)&color + 0xc) = *(float *)(s_aFade + 0x28) * (f0 * *(float *)(s_aFade + 0x14));
            alpha = f0 * (float)(0x1e - *(u16 *)(pWnd_ + 0x12)) / 30.0f;
            if (alpha < 0.0f) alpha = 0.0f;
            color.value[3] = color.value[3] * alpha;
            color.value[0] = color.value[1] = color.value[2] = 1.0f + (float)*(s8 *)(GameSt + 0x1e) / 128.0f;
            SfxDraw_DrawSprite_Scr((float *)pWnd_, size.value, 0.0f, color.value, st);
        }
    }
    SfxDraw_SetRenderStateBlock(sb);
}

void FECard_CancelVanish(unsigned short a0 /* r4 */) {
    s32 t0;
    u32 v1;

    t0 = (u32)(u16)a0 * (u32)(0x50);
    *(u16 *)(u16 *)((u8 *)(u16 *)(u8 *)(s_aCardWnd + 8) + t0) = 0;
    *(u16 *)(u16 *)(s32)((u32)(u8 *)(s_aCardWnd + 9) + t0) = 0;
    *(u16 *)(u32)((u32)(u8 *)(s_aCardWnd + 0xb) + t0) = a0;
    *(u16 *)(u32)((u32)(u8 *)(s_aCardWnd + 0xa) + t0) = 0;
    *(u16 *)(u32)((u32)(u8 *)(s_aCardWnd + 0x12) + t0) = 0;
    *(u32 *)(u32)((u32)(u8 *)(s_aCardWnd + 0x14) + t0) = 0;
    *(u32 *)(u32)((u32)(u8 *)(s_aCardWnd + 0x16) + t0) = 0;
    *(u32 *)(u32)((u32)(u8 *)(s_aCardWnd + 0xc) + t0) = 0;
    *(u32 *)(u32)((u32)(u8 *)(s_aCardWnd + 0xe) + t0) = 0;
    v1 = (u32)(u8 *)(s_aCardWnd + 0x10);
    *(u32 *)(u32)(v1 + t0) = 0;
    return;
}

void FECard_CancelVannishAll(void) {
    u32 a2;
    u32 a1;
    s32 v1;

    a2 = 0;
    do {
        a1 = (s32)((u8 *)s_aCardWnd + (s32)((u32)(u16)a2 * 0x50));
        *(u16 *)((a1 + 0x10)) = 0;
        *(u16 *)((a1 + 0x12)) = 0;
        *(u16 *)((a1 + 0x16)) = a2;
        *(u16 *)((a1 + 0x14)) = 0;
        a2 = a2 + 1;
        *(u16 *)((a1 + 0x24)) = 0;
        v1 = (s32)a2 < (s32)4;
        *(u32 *)((a1 + 0x28)) = 0;
        *(u32 *)((a1 + 0x2c)) = 0;
        *(u32 *)((a1 + 0x18)) = 0;
        *(u32 *)((a1 + 0x1c)) = 0;
        *(u32 *)((a1 + 0x20)) = 0;
    } while ((u32)v1 != 0);
    return;
}

static void _DrawFont(float f12 /* f12 */, float f13 /* f13 */, unsigned int a0 /* r4 */, char *a1 /* r5
        */, ...) {
    s32 s0;
    float f21;
    float f20;
    s32 a2;
    char *a1_value; // a1
    u32 v1;
    u32 v0;
    u8 stackFrame_30[512] __attribute__((aligned(16)));

    a1_value = a1;
    s0 = (unsigned int)a0;
    f21 = f12;
    f20 = f13;
    v1 = (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    a1_value = (char *)*(s32 *)((u8 *)&a1);
    v0 = (u32)((u8 *)__builtin_next_arg(a1));
    a2 = (s32)((u8 *)((u8 *)__builtin_next_arg(a1)) - v1);
    if ((u32)(s32)a1_value != 0) {
        FsFontReplaceText((void *)((u8 *)&stackFrame_30[0]), (void *)a1_value, a2);
        ((u8 *)stackFrame_30)[511] = 0;
        ((u8 *)stackFrame_30)[510] = 0;
    } else {
        *(u8 *)((u8 *)&stackFrame_30[0]) = 0;
    }
    SetFontColorRGBA((unsigned int)s0);
    FontDrawBegin(0);
    FontPrintXY((float)f21, (float)f20, (char *)((u8 *)&stackFrame_30[0]));
    FontDrawEnd();
    SetLastFontColor();
    return;
}
static u16 s_aNumAnimH[3] __attribute__((section(".rodata"))) = {8, 4, 8};
static u16 s_aNumAnimV[3] __attribute__((section(".rodata"))) = {4, 4, 2};
static u16 s_aAnimTime[3] __attribute__((section(".rodata"))) = {2, 4, 2};
