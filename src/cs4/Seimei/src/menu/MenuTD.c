#include "common.h"


u32 s_MenuTdMng[0x88];
static u32 s_msg_buf[0xe0];
static u32 s_end_cur;
static u32 s_start_cur;

u32 pMenuTdMng;
signed int Menu_TD_DrawDialog(void);


/* Menu_TD_Draw @ 0x212E10 .. 0x212E48 (0x38 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   repo declaration vs inferred signature: return int vs inferred u32
 */

extern signed int Menu_TD_DrawDialog(void);
extern u32 pMenuTdMng;
signed int Menu_TD_SetGetNextNode(void);

/* Menu_TD_Update @ 0x212E50 .. 0x21311C (0x2cc bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @1067 -> 0x257410
 *   literal: @1066 is the string ''
 *   indirect: jr v1 at 0x212eac -> <v1>
 *   cfg: kept branch: 0x212f34 if (..) goto .L00212F60
 *   v1#8 is the pointer held in pMenuTdMng+0x0
 *   v1#24 is the pointer held in pMenuTdMng+0x0
 *   v0#17 is the pointer held in pMenuTdMng+0x0
 */

extern signed int Menu_TD_SetGetNextNode(void);
extern signed int Menu_SND_Play2D(signed int, signed short, signed short);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern void * memcpy(void *, void *, unsigned int);
static s32 s_list_top;
extern u8 GameSt[];
extern u32 lpPadData;

/* Menu_TD_IsPlay @ 0x213120 .. 0x213180 (0x60 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x21313c writes a register its branch at 0x213138 reads
 *   delay: daddu at 0x213160 writes a register its branch at 0x21315c reads
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern u32 s_start_cur;
extern u32 s_end_cur;

/* Menu_TD_CallOrder @ 0x213180 .. 0x2131DC (0x5c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred void
 */

extern signed int CheckEventFlag(signed int);
static signed int Menu_TD_AddList(signed int a0 , signed int a1 , signed int a2 );
static signed int Menu_TD_AddList(signed int, signed int, signed int);

/* Menu_TD_Call @ 0x2131E0 .. 0x213374 (0x194 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1066 is the string ''
 *   delay: daddu at 0x21321c writes a register its branch at 0x213218 reads
 *   delay: daddu at 0x213260 writes a register its branch at 0x21325c reads
 *   cfg: kept branch: 0x213230 if (..) goto .L00213240
 *   cfg: kept goto: 0x21323c -> .L00213360
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern void * memcpy(void *, void *, unsigned int);
extern u8 GameSt[];
/* Menu_TD_DrawDialog @ 0x212AC0 .. 0x212E04 (0x344 bytes, frame 0x370) */
/*
 * dcomp notes:
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: v0: 128-bit web split from its scalar uses
 *   quad: v1: 128-bit web split from its scalar uses
 *   literal: @859 -> 0x250410
 *   literal: @862 -> 0x250420
 *   literal: @865 -> 0x250430
 *   literal: @982 is the string 'fe_me_0019.tm2'
 *   literal: @875 -> 0x250440
 *   stack: address of the slot at 0x270 escapes at 0x212b10
 *   stack: address of the slot at 0x260 escapes at 0x212b10
 *   stack: address of the slot at 0x270 escapes at 0x212b18
 *   stack: address of the slot at 0x160 escapes at 0x212b80
 *   stack: address of the slot at 0x150 escapes at 0x212b80
 *   fpu: mtc1 reinterprets t1 at 0x212bbc
 *   fpu: mtc1 reinterprets a3 at 0x212bd8
 *   stack: address of the slot at 0x160 escapes at 0x212c64
 *   fpu: float literal 0x3f4ccccd at 0x212c80
 *   fpu: float literal 0x3f800000 at 0x212c84
 *   fpu: float literal 0x41b00000 at 0x212cc8
 *   fpu: float literal 0x41d00000 at 0x212ccc
 *   fpu: float literal 0x441c0000 at 0x212cd8
 *   fpu: float literal 0x43d60000 at 0x212cdc
 *   fpu: float literal 0x41b00000 at 0x212cf0
 *   fpu: float literal 0x41d00000 at 0x212cf4
 *   fpu: float literal 0x441c0000 at 0x212cfc
 *   fpu: float literal 0x43d60000 at 0x212d04
 *   fpu: float literal 0x40000000 at 0x212d40
 *   fpu: mov.s at 0x212d5c is a float copy
 *   fpu: mov.s at 0x212d60 is a float copy
 *   fpu: mov.s at 0x212d64 is a float copy
 *   fpu: mov.s at 0x212d6c is a float copy
 *   delay: lui at 0x212d98 writes a register its branch at 0x212d94 reads
 *   stack: address of the slot at 0x60 escapes at 0x212dc4
 *   stack: address of the slot at 0x50 escapes at 0x212dc4
 *   stack: address of the slot at 0x60 escapes at 0x212dcc
 *   stack: address of the slot at 0x36d escapes at 0x212dd8
 *   stack: address of the slot at 0x36e escapes at 0x212dd8
 *   stack: address of the slot at 0x36f escapes at 0x212dd8
 *   literal: @875 initializes the 16-byte local at 0x50
 *   literal: @865 initializes the 16-byte local at 0x150
 *   literal: @862 initializes the 16-byte local at 0x250
 *   literal: @859 initializes the 16-byte local at 0x260
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void MakeAndKickSpritePacket(void *);
extern void * GetTexMngByName(void *, char *);
extern void MenuItemMng_MakeAndKickSpritePacket(void *, int, signed int);
extern void FontDrawBegin(int);
extern signed int FsFontSetScale(float, float);
extern void SetFontColor(s32);
extern signed int FsFontSetAlignment(signed int);
extern void FsFontSetDisableColor();
extern void FontPrintInRect(float, float, float, float, char *, ...);
extern void FsFontSetEnableColor();
extern void Msg_DrawPageIcon(signed int, signed int);
extern void FontDrawEnd(void);
extern u32 L859[];
extern u32 L862[];
extern u32 L865[];

extern u8 GameSt[];
extern u32 L875[];

#ifndef PROTO_DW_2973608_FIELDS
#define PROTO_DW_2973608_FIELDS
struct dw_2973608_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2973608_FIELDS_PAUSE_B11CCBBE_DEFINED
#define DCOMP_OFF_STRUCT_DW_2973608_FIELDS_PAUSE_B11CCBBE_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2973608_FIELDS_PAUSE_B11CCBBE = (int)&(((struct dw_2973608_fields *)0)->Pause) - 0 };
#endif
typedef struct {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long rest : 30;
} MDD_TEX0;
typedef struct { unsigned long v; } MDD_TEX1;
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
    MDD_TEX0 tex0;
    MDD_TEX1 tex1;
    u64 test;
    u_char pad1[8];
} MDD_SPD;
typedef struct { u8 pad[0x10]; MDD_TEX0 tex0; MDD_TEX1 tex1; } MDD_TM2HEAD;
typedef struct { u_char bUse; u_char unused0; u_short id; MDD_TM2HEAD *lpTm2; } MDD_TEXMNG;
typedef struct { u8 r, g, b, a; } MDD_COLOR;

/* Menu_TD_SetGetNextNode @ 0x213380 .. 0x213604 (0x284 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: lui at 0x213530 writes a register its branch at 0x21352c reads
 *   cfg: loop body is not one contiguous region: .L002133A8
 *   cfg: kept branch: 0x2133a8 if (..) goto .L00213498
 *   cfg: kept branch: 0x2133d0 if (..) goto .L00213498
 *   cfg: kept goto: 0x213470 -> .L002135D8
 *   cfg: kept branch: 0x2134a8 if (..) goto .L002134C0
 *   cfg: kept branch: 0x2134c8 if (..) goto .L002135D0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 KnMenuMng_GetPlayMenu_All();
extern void SetEventFlag(signed int);



static s32 s_list_tail;
typedef struct TDNode { s32 id; s32 a; s32 b; s32 c; s32 d; s32 prev; s32 next; } TDNode;


static s32 s_list_tail;

typedef struct TDMsgA { s32 id; s32 a; s32 b; s32 c; s32 d; s32 prev; s32 next; } TDMsgA;

static inline s32 Menu_TD_AddList__find(void) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (((TDMsgA *)s_msg_buf)[i].a == 0) {
            return i;
        }
    }
    return -1;
}


extern void * memset(void *, int, unsigned int);
extern u32 s_MenuTdMng[];
static s32 s_list_tail;

typedef struct TDMsg { s32 id; s32 a; s32 b; s32 c; s32 d; s32 prev; s32 next; } TDMsg;
typedef struct TDMng { u8 flag; u8 pad[3]; s32 a; s32 b; s32 c; u8 pad2[0x10]; u8 f20; } TDMng;



u32 pMenuTdMng = (u32)&s_MenuTdMng;
static s32 s_list_top = -0x1;
static s32 s_list_tail = -0x1;



/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
signed int Menu_TD_Init(void);
static signed int Menu_TD_AddList(signed int a0 , signed int a1 , signed int a2 );
signed int Menu_TD_SetGetNextNode(void);
static signed int Menu_TD_Call(signed int a0 );
signed int Menu_TD_CallOrder(signed int a0 , signed int a1 , signed int a2 );
int Menu_TD_IsPlay(void);
signed int Menu_TD_Update(void);
int Menu_TD_Draw(void);
signed int Menu_TD_DrawDialog(void);



signed int Menu_TD_Init(void) {
    int i;

    memset(s_MenuTdMng, 0, 0x220);
    ((TDMng *)pMenuTdMng)->flag = 1;
    ((TDMng *)pMenuTdMng)->f20 = 0;
    ((TDMng *)pMenuTdMng)->a = 0;
    ((TDMng *)pMenuTdMng)->b = 0;
    ((TDMng *)pMenuTdMng)->c = 1;
    for (i = 0; i < 32; i++) {
        ((TDMsg *)s_msg_buf)[i].id = i;
        ((TDMsg *)s_msg_buf)[i].a = 0;
        ((TDMsg *)s_msg_buf)[i].b = 0;
        ((TDMsg *)s_msg_buf)[i].c = 0;
        ((TDMsg *)s_msg_buf)[i].d = 0;
        ((TDMsg *)s_msg_buf)[i].prev = -1;
        ((TDMsg *)s_msg_buf)[i].next = -1;
    }
    s_list_top = -1;
    s_list_tail = -1;
    return 1;
}

static signed int Menu_TD_AddList(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    s32 idx;
    s32 off;
    s32 tail;

    idx = Menu_TD_AddList__find();
    if (idx == -1) {
        return -1;
    }
    off = idx * 0x1c;
    *(u32 *)((u8 *)&s_msg_buf[1] + off) = 1;
    *(u32 *)((u8 *)&s_msg_buf[2] + off) = a0;
    *(u32 *)((u8 *)&s_msg_buf[3] + off) = a1;
    *(u32 *)((u8 *)&s_msg_buf[4] + off) = a2;
    if (s_list_top == -1) {
        s_list_top = idx;
        s_list_tail = idx;
    } else {
        tail = s_list_tail;
        *(u32 *)((u8 *)&s_msg_buf[6] + tail * 0x1c) = idx;
        *(u32 *)((u8 *)&s_msg_buf[5] + off) = tail;
        *(u32 *)((u8 *)&s_msg_buf[6] + off) = -1;
        s_list_tail = idx;
    }
    return 1;
}
signed int Menu_TD_SetGetNextNode(void) {
    TDNode *n;
    int off;
    int check_node;
    s32 f;
    int ok;

    check_node = s_list_top;
    while (check_node != -1) {
        off = check_node * 0x1c;
        n = (TDNode *)((u8 *)s_msg_buf + off);
        f = n->c;
        if (f != -1 && CheckEventFlag(f)) {
            s32 *pNext;
            s32 next;
            s32 *pPrev;
            pNext = &n->next;
            next = n->next;
            if (s_list_top == check_node) {
                s_list_top = next;
            }
            if (s_list_tail == check_node) {
                s_list_tail = n->prev;
            }
            pPrev = &n->prev;
            if (*pPrev != -1) {
                ((TDNode *)((u8 *)s_msg_buf + *pPrev * 0x1c))->next = next;
            }
            if (*pNext != -1) {
                ((TDNode *)((u8 *)s_msg_buf + *pNext * 0x1c))->prev = *pPrev;
            }
            check_node = next;
            *(u32 *)((u8 *)s_msg_buf + (u32)off + 4) = 0;
            *pPrev = -1;
            *pNext = -1;
        } else {
            if ((n->d & 1) && KnMenuMng_GetPlayMenu_All()) {
                ok = 0;
            } else {
                ok = 1;
            }
            if (ok) {
            s32 next;
            s32 prev;
            s32 *pNext;
            s32 *pPrev;
            Menu_TD_Call(*(s32 *)((u8 *)&s_msg_buf[2] + off));
            f = *(s32 *)((u8 *)&s_msg_buf[3] + off);
            if (f != -1) {
                SetEventFlag(f);
            }
            pNext = (s32 *)((u8 *)&s_msg_buf[6] + off);
            next = *pNext;
            if (s_list_top == check_node) {
                s_list_top = next;
            }
            if (s_list_tail == check_node) {
                s_list_tail = *(s32 *)((u8 *)&s_msg_buf[5] + off);
            }
            pPrev = (s32 *)((u8 *)&s_msg_buf[5] + off);
            prev = *pPrev;
            if (prev != -1) {
                *(u32 *)((u8 *)&s_msg_buf[6] + prev * 0x1c) = next;
            }
            if (*pNext != -1) {
                *(u32 *)((u8 *)&s_msg_buf[5] + *pNext * 0x1c) = *pPrev;
            }
            *(u32 *)((u8 *)&s_msg_buf[1] + off) = 0;
            *pPrev = -1;
            *pNext = -1;
            break;
            } else {
            check_node = n->next;
            }
        }
    }
    return 1;
}

static signed int Menu_TD_Call(signed int a0 /* r4 */) {
    s32 s1;
    s32 a2;
    u32 a1;
    u8 *s0;
    u32 v1;
    u32 v0;

    v0 = 2;
    v1 = GameSt[0x14];
    s1 = a0;
    if (v1 == v0) {
        v0 = 0;
    } else {
        v0 = GameSt[0x23];
        if (v0 != 0) {
            v0 = 0;
        } else {
            v0 = 1;
        }
    }
    if (v0 != 0) {
        goto _L00213240;
    }
    v0 = 0;
    goto _L00213360;
    _L00213240:;
    a0 = pMenuTdMng;
    v1 = *(u8 *)a0;
    if (v1 == 0) {
        v0 = 0;
        return v0;
    }
    v0 = 1;
    if (v1 != v0) {
        v0 = 0;
        return v0;
    }
    v0 = 2;
    *(u8 *)a0 = v0;
    a0 = s1;
    v0 = (u32)KnMsgMng_GetMsgStr(a0);
    s0 = (u8 *)v0;
    v0 = *(s8 *)v0;
    if (v0 == 0) {
        v0 = 0;
    } else {
        v1 = pMenuTdMng;
        a1 = 0;
        v0 = *(u16 *)"";
        a0 = v1 + 0x20;
        if (v0 != 0) {
            v1 = (u32)"";
            do {
                v1 = v1 + 2;
                v0 = *(u16 *)v1;
                a1 = a1 + 1;
            } while (v0 != 0);
        }
        v0 = a1 << 1;
        a2 = v0 + 2;
        a1 = (u32)"";
        memcpy((void *)a0, (void *)"", a2);
        if ((u32)s0 != 0) {
            v1 = pMenuTdMng;
            a1 = 0;
            v0 = *(u16 *)s0;
            a0 = v1 + 0x20;
            if (v0 != 0) {
                v1 = (u32)s0;
                do {
                    v1 = v1 + 2;
                    v0 = *(u16 *)v1;
                    a1 = a1 + 1;
                } while (v0 != 0);
            }
            v0 = a1 << 1;
            a2 = v0 + 2;
            a1 = (u32)s0;
            memcpy((void *)a0, (void *)a1, a2);
        }
        v1 = pMenuTdMng;
        v0 = 1;
        *(u32 *)((v1 + 4)) = s1;
        v1 = pMenuTdMng;
        *(u32 *)((v1 + 8)) = s1;
        v1 = pMenuTdMng;
        *(u32 *)((v1 + 0xc)) = v0;
    }
    _L00213360:;
    return v0;
}

signed int Menu_TD_CallOrder(signed int a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    s32 s2;
    s32 s1;
    s32 s0;
    u32 v0;

    s2 = (s32)a0;
    s1 = (s32)a1;
    s0 = (s32)a2;
    a0 = s1;
    v0 = CheckEventFlag(a0);
    a0 = s2;
    if (v0 != 0) {
        v0 = 0;
    } else {
        a1 = s1;
        a2 = s0;
        v0 = Menu_TD_AddList(a0, a1, a2);
    }
    return v0;
}

int Menu_TD_IsPlay(void) {
    u32 v0;
    u32 a0;
    u32 v1;
    s32 branchcond_213138;
    s32 branchcond_21315c;

    v0 = pMenuTdMng;
    a0 = *(u8 *)v0;
    if (a0 == 0) {
        v1 = s_start_cur;
        v0 = s_end_cur;
        branchcond_213138 = v1 != v0;
        v0 = 0;
        if (!branchcond_213138) {
            return v0;
        }
    }
    v0 = 1;
    if (a0 == v0) {
        v1 = s_start_cur;
        v0 = s_end_cur;
        branchcond_21315c = v1 != v0;
        v0 = 0;
        if (!branchcond_21315c) {
            return v0;
        }
    }
    v0 = 1;
    return v0;
}

signed int Menu_TD_Update(void) {
    s32 a2;
    u32 a1;
    u32 a0;
    u32 v1;
    u64 v1_64;
    u8 *s0;
    u32 v0;

    v0 = 1;
    v1 = pMenuTdMng;
    v1 = *(u8 *)v1;
    if (v1 == v0) {
        v1 = s_list_top;
        v0 = -1;
        if (v1 != v0) {
            Menu_TD_SetGetNextNode();
        }
    }
    v0 = pMenuTdMng;
    v1 = *(u8 *)v0;
    switch (v1) {
    case 2:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 3:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 4:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 5:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 6:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 7:
        a1 = GameSt[0xa];
        a0 = (u32)&lpPadData;
        a1 = a1 << 2;
        a0 = (s32)((u8 *)&lpPadData + a1);
        v1 = (s32)(GameSt[0xf] != 0) ^ 1;
        a0 = *(s32 *)a0;
        if (v1 != 0) {
            v1 = *(u8 *)((a0 + 0x21));
            v1_64 = (u64)((u64)v1 << 0x39) >> 0x3f;
            if (v1_64 != 0) {
                goto _L00212F60;
            }
        }
        v1 = *(u8 *)((a0 + 0x21));
        v1_64 = (u64)((u64)v1 << 0x3a) >> 0x3f;
        if (v1_64 == 0) {
            break;
        }
        _L00212F60:;
        v1 = *(s8 *)v0;
        a0 = 0x11;
        a1 = 0x64;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        Menu_SND_Play2D(a0, a1, 0);
        break;
    case 8:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 9:
        *(u32 *)((v0 + 8)) = *(s32 *)((v0 + 8)) + *(s32 *)((v0 + 0xc));
        v0 = pMenuTdMng;
        a0 = *(s32 *)((v0 + 8));
        v0 = (u32)KnMsgMng_GetMsgStr(a0);
        s0 = (u8 *)v0;
        if ((u32)s0 == 0 || *(s8 *)s0 == 0) {
            v0 = pMenuTdMng;
            v1 = 0xd;
            *(u8 *)v0 = v1;
        } else {
            v1 = pMenuTdMng;
            a1 = 0;
            v0 = *(u16 *)"";
            a0 = v1 + 0x20;
            if (v0 != 0) {
                v1 = (u32)"";
                do {
                    v1 = v1 + 2;
                    v0 = *(u16 *)v1;
                    a1 = a1 + 1;
                } while (v0 != 0);
            }
            v0 = a1 << 1;
            a2 = v0 + 2;
            a1 = (u32)"";
            memcpy((void *)a0, (void *)"", a2);
            if ((u32)s0 != 0) {
                v1 = pMenuTdMng;
                a1 = 0;
                v0 = *(u16 *)s0;
                a0 = v1 + 0x20;
                if (v0 != 0) {
                    v1 = (u32)s0;
                    do {
                        v1 = v1 + 2;
                        v0 = *(u16 *)v1;
                        a1 = a1 + 1;
                    } while (v0 != 0);
                }
                v0 = a1 << 1;
                a2 = v0 + 2;
                a1 = (u32)s0;
                memcpy((void *)a0, (void *)a1, a2);
            }
        }
        v1 = pMenuTdMng;
        v0 = *(s8 *)v1;
        v0 = v0 + 1;
        *(u8 *)v1 = v0;
        break;
    case 10:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 11:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 12:
        v1 = 6;
        *(u8 *)v0 = v1;
        break;
    case 13:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 14:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 15:
        v1 = *(s8 *)v0;
        v1 = v1 + 1;
        *(u8 *)v0 = v1;
        break;
    case 16:
        v1 = 1;
        *(u8 *)v0 = v1;
    case 0:
    case 1:
    default:
        break;
    }
    v0 = 1;
    return v0;
}

int Menu_TD_Draw(void) {
    u32 v1;
    u32 v0;

    v0 = pMenuTdMng;
    v1 = *(u8 *)v0;
    if (v1 != 0 && v1 != (u32)1) {
        Menu_TD_DrawDialog();
    }
    return 1;
}

signed int Menu_TD_DrawDialog(void) {
    MDD_SPD Sp_black;
    int col[4] = {0, 0, 0, 0x60};

    SetSprite(&Sp_black, -0x100, -0xe0, 0x200, 0x1c0, col, 0, 0);
    MakeAndKickSpritePacket(&Sp_black);
    {
        float tex_data[4] = {0.0f, 0.0f, 0.859375f, 0.8515625f};
        MDD_SPD Sprite;
        int col[4] = {0x7f, 0x7f, 0x7f, 0};
        MDD_TEXMNG *pTexMng;
        int texW;
        int texH;
        MDD_COLOR color;
        float x, y, w, h;
        int u, v;

        col[3] = 0x7f;
        pTexMng = (MDD_TEXMNG *)GetTexMngByName(0, "fe_me_0019.tm2");
        SetSprite(&Sprite, -0xc8, -0x7d, 0x190, 0xfa, col, pTexMng->id, 0);
        texW = 1 << pTexMng->lpTm2->tex0.TW;
        texH = 1 << pTexMng->lpTm2->tex0.TH;
        Sprite.tex0 = pTexMng->lpTm2->tex0;
        Sprite.tex1 = pTexMng->lpTm2->tex1;
        u = (int)(tex_data[0] * texW);
        v = (int)(tex_data[1] * texH);
        Sprite.uv[0][0] = u << 4;
        Sprite.uv[2][0] = u << 4;
        Sprite.uv[0][1] = v << 4;
        Sprite.uv[1][1] = v << 4;
        Sprite.uv[1][0] = (u + (int)(tex_data[2] * texW)) << 4;
        Sprite.uv[3][0] = (u + (int)(tex_data[2] * texW)) << 4;
        Sprite.uv[2][1] = (v + (int)(tex_data[3] * texH)) << 4;
        Sprite.uv[3][1] = (v + (int)(tex_data[3] * texH)) << 4;
        MenuItemMng_MakeAndKickSpritePacket(&Sprite, 1, 1);
        FontDrawBegin(0);
        FsFontSetScale(0.8f, 1.0f);
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 0x7f;
        SetFontColor(*(s32 *)&color);
        FsFontSetAlignment(0xa0);
        x = 22.0f;
        y = 26.0f;
        w = 624.0f;
        h = 428.0f;
        FsFontSetDisableColor();
        FontPrintInRect(22.0f, 26.0f, 624.0f, 428.0f, (char *)(pMenuTdMng + 0x20));
        FsFontSetEnableColor();
        color.r = 0x7f;
        color.g = 0x7f;
        color.b = 0x7f;
        color.a = 0x7f;
        SetFontColor(*(s32 *)&color);
        x -= 2.0f;
        y -= 2.0f;
        w -= 2.0f;
        h -= 2.0f;
        FontPrintInRect(x, y, w, h, (char *)(pMenuTdMng + 0x20));
        FsFontSetAlignment(0x100);
        Msg_DrawPageIcon(0x100, 0x12c);
        FontDrawEnd();
    }
    if (((struct dw_2973608_fields *)GameSt)->Pause != 0) {
        MDD_SPD Sp_black;
        int col[4] = {0, 0, 0, 0x60};

        SetSprite(&Sp_black, -0x100, -0xe0, 0x200, 0x1c0, col, 0, 0);
        MakeAndKickSpritePacket(&Sp_black);
    }
    return 1;
}
