#include "common.h"




extern void * GetTexMngByID(unsigned short);
extern unsigned int * MakeTexPacket(unsigned int *, void *);

typedef struct {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    s32 u;
    s32 v;
    s32 tw;
    s32 th;
} MIRelData;
struct V16 { float f[4]; };
struct V32 { float f[8]; };
extern signed int MngState_Init(void *);
extern void * memset(void *, int, unsigned int);
extern signed int GetMenuFuncId(unsigned char *);
extern u32 L2877[];
unsigned int * MenuItemMng_MakeSpritePacketUseSpr(u8 *a0 /* r4 */, u32 *a1 /* r5 */, u8 a2 /* r6
        */, s32 a3 /* r7 */);
signed int MenuItemMng_Delete(void *a0 /* r4 */);
static signed int MenuItemMng_RelativeData_Add(void *a0, void *a1, void *a2, unsigned int relative_flag_set);
signed int MenuItemMng_Init(void *a0 /* r4 */, void *a1 /* r5 */, signed int *a2 /* r6 */, signed
        int *a3 /* r7 */, signed int *t0 /* r8 */, void *t1 /* r9 */, signed int *t2 /* r10 */);
u32 MenuItemMng_Initialize(u32 *a0 /* r4 */);

/* MenuItemMng_Initialize @ 0x1F1AC0 .. 0x1F1AE0 (0x20 bytes) */




u32 MenuItemMng_Initialize(u32 *a0 /* r4 */) {
    u32 v0;

    *(u32 *)(((u8 *)a0 + 0x20)) = 0;
    v0 = 1;
    *(u32 *)(((u8 *)a0 + 0xa8)) = 0;
    *(u32 *)(((u8 *)a0 + 0xac)) = 0;
    *(u32 *)(((u8 *)a0 + 0xb0)) = 0;
    *(u32 *)(((u8 *)a0 + 0xb4)) = 0;
    *(u32 *)(((u8 *)a0 + 0xb8)) = 0;
    return v0;
}


/* MenuItemMng_Init @ 0x1F18D0 .. 0x1F1AC0 (0x1f0 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   literal: @2877 -> 0x257070
 *   indirect: jr v0 at 0x1f1a18 -> <v0>
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuItemMng_Init(void *a0 /* r4 */, void *a1 /* r5 */, signed int *a2 /* r6 */, signed
        int *a3 /* r7 */, signed int *t0 /* r8 */, void *t1 /* r9 */, signed int *t2 /* r10 */) {
    u8 *s5;
    u32 s4;
    u32 s3;
    u32 s2;
    u32 s1;
    u32 s0;
    u32 s6;
    u8 *v1;
    u32 v0;
    float f3;
    float f2;
    float f1;
    float f0;
    signed int *a2_2;

    s6 = (u32)t2;
    s5 = (u8 *)a0;
    s4 = (u32)a1;
    s3 = (u32)a2;
    s2 = (u32)a3;
    s1 = (u32)t0;
    s0 = (u32)t1;
    if ((u32)s5 == 0) {
        v0 = 0;
    } else {
        MngState_Init(a0);
        *(u32 *)(s5 + 0x20) = s4;
        v0 = 0x3f800000;
        *(u8 *)(s5 + 0xa4) = 0;
        a0 = (void *)(s5 + 0xbc);
        *(u32 *)(s5 + 0xa8) = s3;
        *(u32 *)(s5 + 0xac) = s2;
        a2_2 = (signed int *)(s32)4;
        *(u32 *)(s5 + 0xb0) = s1;
        *(u32 *)(s5 + 0xb4) = s0;
        *(u32 *)(s5 + 0xb8) = s6;
        *(u8 *)(s5 + 0x24) = 0;
        *(u8 *)(s5 + 0xa4) = 0;
        *(u32 *)(s5 + 0xa0) = 0;
        *(u32 *)(s5 + 0xd0) = 0;
        *(u32 *)(s5 + 0xd4) = 0;
        *(u32 *)(s5 + 0xd8) = 0;
        *(u32 *)(s5 + 0xdc) = 0x3f800000;
        memset(a0, 0, (unsigned int)a2_2);
        if ((u32)s5 == 0) {
            if ((u32)s5 != 0) {
                *(u32 *)s5 = 0;
            }
            v0 = 0;
        } else {
            v1 = (u8 *)*(s32 *)(s5 + 0x20);
            v0 = -1;
            a0 = (void *)(s32)(s4 + 0xb0);
            *(struct V16 *)(s5 + 0x30) = *(struct V16 *)(v1 + 0x90);
            *(struct V16 *)(s5 + 0x40) = *(struct V16 *)(v1 + 0xa0);
            *(u32 *)(s5 + 0x50) = 0;
            *(u32 *)(s5 + 0x54) = v0;
            *(u32 *)(s5 + 0x58) = 0;
            *(u32 *)(s5 + 0x5c) = 0;
            v0 = GetMenuFuncId((unsigned char *)a0);
            *(u32 *)(s5 + 0x60) = v0;
            v0 = *(s32 *)((*(s32 *)(s5 + 0x20) + 0x14));
            switch (v0) {
            case 1:
                *(u8 *)(s5 + 0x80) = 0;
                break;
            case 2:
                *(u16 *)(s5 + 0x80) = 0;
                break;
            case 3:
                *(u32 *)(s5 + 0x80) = 0;
                break;
            case 4:
                *(u64 *)(s5 + 0x80) = 0;
                break;
            case 5:
                *(u8 *)(s5 + 0x80) = 0;
                break;
            case 6:
                *(u16 *)(s5 + 0x80) = 0;
                break;
            case 7:
                *(u32 *)(s5 + 0x80) = 0;
                break;
            case 8:
                *(u32 *)(s5 + 0x80) = 0;
                break;
            case 9:
                *(u32 *)(s5 + 0x80) = 0;
                break;
            case 10:
                *(u_long128 *)(s5 + 0x80) = (u_long128)0;
                break;
            case 12:
                *(u32 *)(s5 + 0x80) = 0;
                break;
            case 13:
                *(u32 *)(s5 + 0x80) = 0;
            case 0:
            case 11:
            default:
                break;
            }
            v0 = -1;
            *(u32 *)(s5 + 0x90) = v0;
            v1 = (u8 *)(s32)2;
            *(u32 *)(s5 + 0x94) = 0;
            v0 = 1;
            *(u32 *)s5 = (s32)v1;
        }
    }
    return v0;
}




/* MenuItemMng_Update @ 0x1EFB10 .. 0x1F18D0 (0x1dc0 bytes, frame 0x1b0) */
extern signed int MngState_UpdateExeCheck(void *);
extern signed int Menu_SND_Play2D(signed int, signed short, signed short);
extern double pow(double, double);
typedef struct {
    u8 name[0x20];
    void (*Get)(void *, s32);
    void (*Set)(void *, s32);
    void (*Decide)(void *, s32);
    void (*CntUp)(void *, s32);
    void (*CntDown)(void *, s32);
    void (*Gene1)(void *, s32);
    void (*Gene2)(void *, s32);
    void (*Evrfrm)(void *, s32, s32);
    void (*Init)(void *, s32, s32);
    void (*Check)(void *, s32, s32);
} MIU_MapFn;
extern MIU_MapFn g_MapFuncTable[];
#ifndef PROTO_DW_2407860_FIELDS
#define PROTO_DW_2407860_FIELDS
struct dw_2407860_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_2403759_FIELDS
#define PROTO_DW_2403759_FIELDS
struct dw_2403759_fields { int pos_x; int pos_y; int size_w; int size_h; int col_r; int col_g; int col_b; int col_a; };
#endif
#ifndef PROTO_DW_2406978_FIELDS
#define PROTO_DW_2406978_FIELDS
union dw_2406978_fields { char _s8; short _s16; int _s32; long _s64; unsigned char _u8; unsigned short _u16; unsigned int _u32; unsigned int _u64; float _f32; u_long128 _u128; int _q128[4]; unsigned char *_p8; void *_pv; };
#endif
#ifndef PROTO_DW_2409403_FIELDS
#define PROTO_DW_2409403_FIELDS
struct dw_2409403_fields { struct dw_2403759_fields anim_arrange; int now_frame; int now_anim_id; int now_tex_anim_counter; int anim_play_counter; int func_id; float tex_u; float tex_v; float tex_w; float tex_h; unsigned char _pad0[12]; union dw_2406978_fields variable; int force_anim_id; float force_anim_ratio; float dmy; unsigned char _pad1[4]; };
#endif
#ifndef PROTO_DW_2404084_FIELDS
#define PROTO_DW_2404084_FIELDS
struct dw_2404084_fields { unsigned int ctrl_decide : 1; unsigned int ctrl_cancel : 1; unsigned int ctrl_up : 1; unsigned int ctrl_down : 1; unsigned int ctrl_left : 1; unsigned int ctrl_right : 1; unsigned int ctrl_option : 1; unsigned int item_decide : 1; unsigned int item_cancel : 1; unsigned int item_up : 1; unsigned int item_down : 1; unsigned int item_left : 1; unsigned int item_right : 1; unsigned int item_option : 1; unsigned int exe_decide : 1; unsigned int exe_cancel : 1; unsigned int exe_up : 1; unsigned int exe_down : 1; unsigned int exe_left : 1; unsigned int exe_right : 1; unsigned int exe_option : 1; unsigned int force_end_none : 1; unsigned int force_end_end : 1; unsigned int through : 1; unsigned int : 8; unsigned int reserve : 18; unsigned int : 14; };
#endif
#ifndef PROTO_DW_2401203_FIELDS
#define PROTO_DW_2401203_FIELDS
struct dw_2401203_fields { struct dw_2407860_fields mng_state; struct dw_2399598_fields *pMenuItemParam; unsigned char state; unsigned char _pad0[11]; struct dw_2409403_fields MenuItemData; int goto_id; unsigned char state_order; unsigned char _pad1[3]; int *pParentPosX; int *pParentPosY; int *pAnimNum; struct dw_2402782_fields *pAnimList; int *pTexIdList; struct dw_2404084_fields wait_flag; unsigned char _pad2[12]; float old_draw_pos[4]; int link_id; unsigned char _pad3[12]; };
#endif
#ifndef PROTO_DW_2402102_FIELDS
#define PROTO_DW_2402102_FIELDS
struct dw_2402102_fields { unsigned int use_ctrl_arg_data : 1; unsigned int reserve : 31; };

#endif
#ifndef PROTO_DW_2399598_FIELDS
#define PROTO_DW_2399598_FIELDS
struct dw_2399598_fields { int id; int item_type; struct dw_2402102_fields mip_gene_flag; unsigned int set_item_data_on; int p_data; unsigned int data_type; unsigned int special_proc_type; unsigned int blend_type; int bokasi_data; int dmy4; int center_flg; int msg_id; int start_anim_id; int wait_anim_id; int end_anim_id; float font_scale; int start_anim_play_num; int wait_anim_play_num; int end_anim_play_num; int font_size; int select_se_id; int decide_se_id; int cancel_se_id; unsigned int size_def_on; int start_func_id; int wait_func_id; int end_func_id; unsigned short tex_uv_rrot_num; unsigned short tex_uv_rl_symmetry; int tex_index_id; int tex_anim_type; int tex_anim_x; int tex_anim_y; float tex_u; float tex_v; float tex_w; float tex_h; struct dw_2403759_fields anim_arrange; unsigned char item_name[64]; };
#endif
#ifndef PROTO_DW_2410654_FIELDS
#define PROTO_DW_2410654_FIELDS
struct dw_2410654_fields { unsigned long TBP0 : 14; unsigned long TBW : 6; unsigned long PSM : 6; unsigned long TW : 4; unsigned long TH : 4; unsigned long TCC : 1; unsigned long TFX : 2; unsigned long CBP : 14; unsigned long CPSM : 4; unsigned long CSM : 1; unsigned long CSA : 5; unsigned long CLD : 3; };

#endif
#ifndef PROTO_DW_2403223_FIELDS
#define PROTO_DW_2403223_FIELDS
struct dw_2403223_fields { long LCM : 1; long pad01 : 1; long MXL : 3; long MMAG : 1; long MMIN : 3; long MTBA : 1; long pad10 : 9; long L : 2; long pad21 : 11; long K : 12; long pad44 : 20; };
#endif
#ifndef PROTO_DW_2410236_FIELDS
#define PROTO_DW_2410236_FIELDS
struct dw_2410236_fields { long ATE : 1; long ATST : 3; long AREF : 8; long AFAIL : 2; long DATE : 1; long DATM : 1; long ZTE : 1; long ZTST : 2; long pad19 : 45; };
#endif
#ifndef PROTO_DW_2402258_FIELDS
#define PROTO_DW_2402258_FIELDS
struct dw_2402258_fields { unsigned short bUse : 1; unsigned short Fst : 1; unsigned short Alpha : 2; unsigned short LoadOff : 1; unsigned short unused : 11; unsigned short texID; unsigned char _pad0[12]; int ver[4][4]; int col[4][4]; int uv[4][4]; struct dw_2410654_fields tex0; struct dw_2403223_fields tex1; struct dw_2410236_fields test; unsigned char _pad1[8]; };
#endif
#ifndef PROTO_DW_2399133_FIELDS
#define PROTO_DW_2399133_FIELDS
struct dw_2399133_fields { unsigned char bUse; unsigned char unused0; unsigned short id; struct dw_2406575_fields *lpTm2; void *lpTexList; int unused1[1]; unsigned char texName[32]; unsigned char texNameBase[32]; int texW; int texH; int texTBW; int texPSM; };
#endif
#ifndef PROTO_DW_2410085_FIELDS
#define PROTO_DW_2410085_FIELDS
struct dw_2410085_fields { unsigned char r; unsigned char g; unsigned char b; unsigned char a; };
#endif
#ifndef PROTO_DW_2408826_FIELDS
#define PROTO_DW_2408826_FIELDS
struct dw_2408826_fields { unsigned int relative_pos_x : 1; unsigned int relative_pos_y : 1; unsigned int relative_size_x : 1; unsigned int relative_size_y : 1; unsigned int relative_cal_r : 1; unsigned int relative_cal_g : 1; unsigned int relative_cal_b : 1; unsigned int relative_cal_a : 1; unsigned int reserve : 24; };
#endif
#ifndef PROTO_DW_2402782_FIELDS
#define PROTO_DW_2402782_FIELDS
struct dw_2402782_fields { int id; int anim_type; int frame_num; float rate; struct dw_2408826_fields menu_ctrl_anim_flag; int next_anim_id; int next_anim_play_num; int wait_through; struct dw_2403759_fields anim_arrange; };
#endif
#ifndef PROTO_DW_2406575_FIELDS
#define PROTO_DW_2406575_FIELDS
struct dw_2406575_fields { unsigned int size; unsigned int wnum; unsigned char dummy[5]; unsigned char compare; unsigned short tex_id; struct dw_2410654_fields tex0; struct dw_2403223_fields tex1; };
#endif
#ifndef PROTO_DW_2401820_FIELDS
#define PROTO_DW_2401820_FIELDS
struct dw_2401820_fields { signed char get_state; signed char get_old_state; unsigned char _pad0[2]; int get_goto; int get_through; int dmy1[5]; int dmy2[8]; };
#endif
signed int MenuItemMng_Update(struct dw_2401203_fields *pMenuItemMng, struct dw_2401820_fields *pItemGS) {
    int tmp_next;

    int func_type_id1;
    int func_id1;
    union dw_2406978_fields variable1;
    struct dw_2403759_fields after_arrange1;
    struct dw_2403759_fields befor_arrange1;
    float ratio1;
    int func_type_id2;
    int func_id2;
    union dw_2406978_fields variable2;
    struct dw_2403759_fields after_arrange2;
    struct dw_2403759_fields befor_arrange2;
    float ratio2;
    int func_type_id3;
    int func_id3;
    union dw_2406978_fields variable3;
    struct dw_2403759_fields after_arrange3;
    struct dw_2403759_fields befor_arrange3;
    float ratio3;
    int tmp_tex_anim_x;
    int tmp_tex_anim_y;

    if (pMenuItemMng == 0) {
        return 0;
    }
    if (pItemGS == 0) {
        return 0;
    }
    if (MngState_UpdateExeCheck(pMenuItemMng) != 1) {
        return 0;
    }
    tmp_next = *(signed char *)&pMenuItemMng->state;

    pItemGS->get_old_state = tmp_next;
L_top:
    switch ((unsigned char)pMenuItemMng->state) {
    case 0:
        pMenuItemMng->MenuItemData.anim_arrange = pMenuItemMng->pMenuItemParam->anim_arrange;
        tmp_next++;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 1:
        tmp_next++;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        pMenuItemMng->goto_id = 0;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 2:
        tmp_next++;
        pMenuItemMng->MenuItemData.anim_arrange = pMenuItemMng->pMenuItemParam->anim_arrange;
        pMenuItemMng->MenuItemData.now_frame = -1;
        func_type_id1 = pMenuItemMng->pMenuItemParam->start_func_id;
        if (func_type_id1 != -1) {
            func_id1 = pMenuItemMng->MenuItemData.func_id;
            if (pMenuItemMng->pMenuItemParam->set_item_data_on == 1) {
                variable1._pv = &pMenuItemMng->MenuItemData.anim_arrange;
                switch (func_type_id1) {
                case 1:
                    g_MapFuncTable[func_id1].Get(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id1].Set(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id1].Decide(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id1].CntUp(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id1].CntDown(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id1].Gene1(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id1].Gene2(&variable1, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            } else {
                switch (func_type_id1) {
                case 1:
                    g_MapFuncTable[func_id1].Get(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id1].Set(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id1].Decide(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id1].CntUp(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id1].CntDown(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id1].Gene1(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id1].Gene2(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            }
        }
        {
        int t_anim;
        int t_num = pMenuItemMng->pMenuItemParam->start_anim_play_num;
        t_anim = pMenuItemMng->pMenuItemParam->start_anim_id;
        if (t_num - 1 < 0) {
            t_anim = -1;
        }
        pMenuItemMng->MenuItemData.anim_play_counter = t_num - 1;
        pMenuItemMng->MenuItemData.now_anim_id = t_anim;
        }
        if (pMenuItemMng->MenuItemData.now_anim_id != -1) {
            pMenuItemMng->MenuItemData.now_frame = 0;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
        Menu_SND_Play2D(pMenuItemMng->pMenuItemParam->select_se_id, 100, 0);
    case 3:
        tmp_next++;
        if (pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange1, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange1 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            MenuItemMng_RelativeData_Add(&befor_arrange1, &pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].menu_ctrl_anim_flag);
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange1, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange1 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            ratio1 = pow((float)pMenuItemMng->MenuItemData.now_frame / (float)pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num, pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].rate);
            pMenuItemMng->MenuItemData.anim_arrange.pos_x = (int)(0.5f + ((float)befor_arrange1.pos_x * (1.0f - ratio1) + (float)after_arrange1.pos_x * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.pos_y = (int)(0.5f + ((float)befor_arrange1.pos_y * (1.0f - ratio1) + (float)after_arrange1.pos_y * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.size_w = (int)(0.5f + ((float)befor_arrange1.size_w * (1.0f - ratio1) + (float)after_arrange1.size_w * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.size_h = (int)(0.5f + ((float)befor_arrange1.size_h * (1.0f - ratio1) + (float)after_arrange1.size_h * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.col_r = (int)(0.5f + ((float)befor_arrange1.col_r * (1.0f - ratio1) + (float)after_arrange1.col_r * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.col_g = (int)(0.5f + ((float)befor_arrange1.col_g * (1.0f - ratio1) + (float)after_arrange1.col_g * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.col_b = (int)(0.5f + ((float)befor_arrange1.col_b * (1.0f - ratio1) + (float)after_arrange1.col_b * ratio1));
            pMenuItemMng->MenuItemData.anim_arrange.col_a = (int)(0.5f + ((float)befor_arrange1.col_a * (1.0f - ratio1) + (float)after_arrange1.col_a * ratio1));
            pMenuItemMng->MenuItemData.now_frame++;
            if (!(pMenuItemMng->MenuItemData.now_frame < pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num)) {
                pMenuItemMng->MenuItemData.now_frame = -1;
            }
        }
        if (pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->MenuItemData.now_frame != -1) {
                break;
            }
            if (pMenuItemMng->MenuItemData.anim_play_counter > 0) {
                pMenuItemMng->MenuItemData.anim_play_counter--;
                pMenuItemMng->MenuItemData.now_frame = 0;
                break;
            } else {
                if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].wait_through != 0) {
                    g_MapFuncTable[pMenuItemMng->MenuItemData.func_id].Check(&pMenuItemMng->wait_flag, pMenuItemMng->pMenuItemParam->p_data, *(s32 *)&pMenuItemMng->MenuItemData.func_id);
                    if (!pMenuItemMng->wait_flag.through) {
                        pMenuItemMng->MenuItemData.now_anim_id = -2;
                        pItemGS->get_through = 1;
                    }
                }
                if (pMenuItemMng->MenuItemData.now_anim_id != -2 && pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                    pMenuItemMng->MenuItemData.now_anim_id = pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id;
                    pMenuItemMng->MenuItemData.now_frame = 0;
                    break;
                }
            }
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 4:
        tmp_next++;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 5:
        tmp_next++;
        pMenuItemMng->MenuItemData.anim_arrange = pMenuItemMng->pMenuItemParam->anim_arrange;
        pMenuItemMng->MenuItemData.now_frame = -1;
        func_type_id2 = pMenuItemMng->pMenuItemParam->wait_func_id;
        if (func_type_id2 != -1) {
            func_id2 = pMenuItemMng->MenuItemData.func_id;
            if (pMenuItemMng->pMenuItemParam->set_item_data_on == 1) {
                variable2._pv = &pMenuItemMng->MenuItemData.anim_arrange;
                switch (func_type_id2) {
                case 1:
                    g_MapFuncTable[func_id2].Get(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id2].Set(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id2].Decide(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id2].CntUp(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id2].CntDown(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id2].Gene1(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id2].Gene2(&variable2, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            } else {
                switch (func_type_id2) {
                case 1:
                    g_MapFuncTable[func_id2].Get(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id2].Set(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id2].Decide(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id2].CntUp(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id2].CntDown(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id2].Gene1(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id2].Gene2(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            }
        }
        if (pMenuItemMng->MenuItemData.now_anim_id != -2) {
            {
            int t_anim;
            int t_num = pMenuItemMng->pMenuItemParam->wait_anim_play_num;
            t_anim = pMenuItemMng->pMenuItemParam->wait_anim_id;
            if (t_num - 1 < 0) {
                t_anim = -1;
            }
            pMenuItemMng->MenuItemData.anim_play_counter = t_num - 1;
            pMenuItemMng->MenuItemData.now_anim_id = t_anim;
            }
            if (pMenuItemMng->MenuItemData.now_anim_id != -1) {
                pMenuItemMng->MenuItemData.now_frame = 0;
            }

        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 6:
        tmp_next++;
        if (pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange2, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange2 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            MenuItemMng_RelativeData_Add(&befor_arrange2, &pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].menu_ctrl_anim_flag);
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange2, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange2 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            ratio2 = pow((float)pMenuItemMng->MenuItemData.now_frame / (float)pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num, pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].rate);
            pMenuItemMng->MenuItemData.anim_arrange.pos_x = (int)(0.5f + ((float)befor_arrange2.pos_x * (1.0f - ratio2) + (float)after_arrange2.pos_x * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.pos_y = (int)(0.5f + ((float)befor_arrange2.pos_y * (1.0f - ratio2) + (float)after_arrange2.pos_y * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.size_w = (int)(0.5f + ((float)befor_arrange2.size_w * (1.0f - ratio2) + (float)after_arrange2.size_w * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.size_h = (int)(0.5f + ((float)befor_arrange2.size_h * (1.0f - ratio2) + (float)after_arrange2.size_h * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.col_r = (int)(0.5f + ((float)befor_arrange2.col_r * (1.0f - ratio2) + (float)after_arrange2.col_r * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.col_g = (int)(0.5f + ((float)befor_arrange2.col_g * (1.0f - ratio2) + (float)after_arrange2.col_g * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.col_b = (int)(0.5f + ((float)befor_arrange2.col_b * (1.0f - ratio2) + (float)after_arrange2.col_b * ratio2));
            pMenuItemMng->MenuItemData.anim_arrange.col_a = (int)(0.5f + ((float)befor_arrange2.col_a * (1.0f - ratio2) + (float)after_arrange2.col_a * ratio2));
            pMenuItemMng->MenuItemData.now_frame++;
            if (!(pMenuItemMng->MenuItemData.now_frame < pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num)) {
                pMenuItemMng->MenuItemData.now_frame = -1;
            }
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order && pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->MenuItemData.now_frame != -1) {
                break;
            }
            if (pMenuItemMng->MenuItemData.anim_play_counter > 0) {
                pMenuItemMng->MenuItemData.anim_play_counter--;
                pMenuItemMng->MenuItemData.now_frame = 0;
                break;
            } else {
                if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].wait_through != 0) {
                    g_MapFuncTable[pMenuItemMng->MenuItemData.func_id].Check(&pMenuItemMng->wait_flag, pMenuItemMng->pMenuItemParam->p_data, *(s32 *)&pMenuItemMng->MenuItemData.func_id);
                    if (!pMenuItemMng->wait_flag.through) {
                        pMenuItemMng->MenuItemData.now_anim_id = -2;
                        pItemGS->get_through = 1;
                    }
                }
                if (pMenuItemMng->MenuItemData.now_anim_id != -2 && pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                    pMenuItemMng->MenuItemData.now_anim_id = pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id;
                    pMenuItemMng->MenuItemData.now_frame = 0;
                    break;
                }
            }
        }
        if (pMenuItemMng->MenuItemData.now_anim_id == -2 && pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 7:
        tmp_next++;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 8:
        tmp_next++;
        pMenuItemMng->MenuItemData.anim_arrange = pMenuItemMng->pMenuItemParam->anim_arrange;
        pMenuItemMng->MenuItemData.now_frame = -1;
        func_type_id3 = pMenuItemMng->pMenuItemParam->end_func_id;
        if (func_type_id3 != -1) {
            func_id3 = pMenuItemMng->MenuItemData.func_id;
            if (pMenuItemMng->pMenuItemParam->set_item_data_on == 1) {
                variable3._pv = &pMenuItemMng->MenuItemData.anim_arrange;
                switch (func_type_id3) {
                case 1:
                    g_MapFuncTable[func_id3].Get(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id3].Set(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id3].Decide(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id3].CntUp(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id3].CntDown(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id3].Gene1(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id3].Gene2(&variable3, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            } else {
                switch (func_type_id3) {
                case 1:
                    g_MapFuncTable[func_id3].Get(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 2:
                    g_MapFuncTable[func_id3].Set(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 3:
                    g_MapFuncTable[func_id3].Decide(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 4:
                    g_MapFuncTable[func_id3].CntUp(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 5:
                    g_MapFuncTable[func_id3].CntDown(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 6:
                    g_MapFuncTable[func_id3].Gene1(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                case 7:
                    g_MapFuncTable[func_id3].Gene2(&pMenuItemMng->MenuItemData.variable, pMenuItemMng->pMenuItemParam->p_data);
                    break;
                }
            }
        }
        {
        int t_anim;
        int t_num = pMenuItemMng->pMenuItemParam->end_anim_play_num;
        t_anim = pMenuItemMng->pMenuItemParam->end_anim_id;
        if (t_num - 1 < 0) {
            t_anim = -1;
        }
        pMenuItemMng->MenuItemData.anim_play_counter = t_num - 1;
        pMenuItemMng->MenuItemData.now_anim_id = t_anim;
        }
        if (pMenuItemMng->MenuItemData.now_anim_id != -1) {
            pMenuItemMng->MenuItemData.now_frame = 0;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 9:
        tmp_next++;
        if (pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange3, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange3 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            MenuItemMng_RelativeData_Add(&befor_arrange3, &pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].menu_ctrl_anim_flag);
            if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                MenuItemMng_RelativeData_Add(&after_arrange3, &pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].anim_arrange, &pMenuItemMng->pMenuItemParam->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id].menu_ctrl_anim_flag);
            } else {
                after_arrange3 = pMenuItemMng->pMenuItemParam->anim_arrange;
            }
            ratio3 = pow((float)pMenuItemMng->MenuItemData.now_frame / (float)pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num, pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].rate);
            pMenuItemMng->MenuItemData.anim_arrange.pos_x = (int)(0.5f + ((float)befor_arrange3.pos_x * (1.0f - ratio3) + (float)after_arrange3.pos_x * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.pos_y = (int)(0.5f + ((float)befor_arrange3.pos_y * (1.0f - ratio3) + (float)after_arrange3.pos_y * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.size_w = (int)(0.5f + ((float)befor_arrange3.size_w * (1.0f - ratio3) + (float)after_arrange3.size_w * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.size_h = (int)(0.5f + ((float)befor_arrange3.size_h * (1.0f - ratio3) + (float)after_arrange3.size_h * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.col_r = (int)(0.5f + ((float)befor_arrange3.col_r * (1.0f - ratio3) + (float)after_arrange3.col_r * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.col_g = (int)(0.5f + ((float)befor_arrange3.col_g * (1.0f - ratio3) + (float)after_arrange3.col_g * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.col_b = (int)(0.5f + ((float)befor_arrange3.col_b * (1.0f - ratio3) + (float)after_arrange3.col_b * ratio3));
            pMenuItemMng->MenuItemData.anim_arrange.col_a = (int)(0.5f + ((float)befor_arrange3.col_a * (1.0f - ratio3) + (float)after_arrange3.col_a * ratio3));
            pMenuItemMng->MenuItemData.now_frame++;
            if (!(pMenuItemMng->MenuItemData.now_frame < pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].frame_num)) {
                pMenuItemMng->MenuItemData.now_frame = -1;
            }
        }
        if (pMenuItemMng->MenuItemData.now_anim_id >= 0) {
            if (pMenuItemMng->MenuItemData.now_frame != -1) {
                break;
            }
            if (pMenuItemMng->MenuItemData.anim_play_counter > 0) {
                pMenuItemMng->MenuItemData.anim_play_counter--;
                pMenuItemMng->MenuItemData.now_frame = 0;
                break;
            } else {
                if (pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].wait_through != 0) {
                    g_MapFuncTable[pMenuItemMng->MenuItemData.func_id].Check(&pMenuItemMng->wait_flag, pMenuItemMng->pMenuItemParam->p_data, *(s32 *)&pMenuItemMng->MenuItemData.func_id);
                    if (!pMenuItemMng->wait_flag.through) {
                        pMenuItemMng->MenuItemData.now_anim_id = -2;
                        pItemGS->get_through = 1;
                    }
                }
                if (pMenuItemMng->MenuItemData.now_anim_id != -2 && pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id != -1) {
                    pMenuItemMng->MenuItemData.now_anim_id = pMenuItemMng->pAnimList[pMenuItemMng->MenuItemData.now_anim_id].next_anim_id;
                    pMenuItemMng->MenuItemData.now_frame = 0;
                    break;
                }
            }
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = tmp_next;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = tmp_next;
    case 10:
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = (unsigned char)tmp_next + 1;
        }
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = (unsigned char)tmp_next + 1;

    case 11:
        tmp_next = 0;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            pMenuItemMng->state_order = 0;
        }
        pItemGS->get_goto = pMenuItemMng->goto_id;
        if (pMenuItemMng->state == pMenuItemMng->state_order) {
            break;
        }
        pMenuItemMng->state = 0;
        goto L_top;
    default:
        break;
    }
    pMenuItemMng->MenuItemData.tex_u = pMenuItemMng->pMenuItemParam->tex_u;
    pMenuItemMng->MenuItemData.tex_v = pMenuItemMng->pMenuItemParam->tex_v;
    pMenuItemMng->MenuItemData.tex_w = pMenuItemMng->pMenuItemParam->tex_w;
    pMenuItemMng->MenuItemData.tex_h = pMenuItemMng->pMenuItemParam->tex_h;
    switch (pMenuItemMng->pMenuItemParam->tex_anim_type) {
    case 1:
    case 2:
        pMenuItemMng->MenuItemData.now_tex_anim_counter++;
        if (!(pMenuItemMng->MenuItemData.now_tex_anim_counter < pMenuItemMng->pMenuItemParam->tex_anim_x * pMenuItemMng->pMenuItemParam->tex_anim_y)) {
            pMenuItemMng->MenuItemData.now_tex_anim_counter = 0;
        }
        if (pMenuItemMng->pMenuItemParam->tex_anim_type == 1) {
            if (pMenuItemMng->pMenuItemParam->tex_anim_x == 0) {
                tmp_tex_anim_y = 1;
                tmp_tex_anim_x = 1;
            } else {
                tmp_tex_anim_x = pMenuItemMng->MenuItemData.now_tex_anim_counter % pMenuItemMng->pMenuItemParam->tex_anim_x;
                tmp_tex_anim_y = pMenuItemMng->MenuItemData.now_tex_anim_counter / pMenuItemMng->pMenuItemParam->tex_anim_x;
            }
        } else if (pMenuItemMng->pMenuItemParam->tex_anim_type == 2) {
            if (pMenuItemMng->pMenuItemParam->tex_anim_x == 0) {
                tmp_tex_anim_y = 1;
                tmp_tex_anim_x = 1;
            } else {
                tmp_tex_anim_x = pMenuItemMng->MenuItemData.now_tex_anim_counter % pMenuItemMng->pMenuItemParam->tex_anim_x;
                tmp_tex_anim_y = pMenuItemMng->MenuItemData.now_tex_anim_counter % pMenuItemMng->pMenuItemParam->tex_anim_y;
            }
        }
        pMenuItemMng->MenuItemData.tex_u = pMenuItemMng->pMenuItemParam->tex_u + (float)tmp_tex_anim_x / (float)pMenuItemMng->pMenuItemParam->tex_anim_x;
        pMenuItemMng->MenuItemData.tex_v = pMenuItemMng->pMenuItemParam->tex_v + (float)tmp_tex_anim_y / (float)pMenuItemMng->pMenuItemParam->tex_anim_y;
    }
    pItemGS->get_state = *(signed char *)&pMenuItemMng->state;
    return 1;
}




static signed int MenuItemMng_RelativeData_Add(void *a0, void *a1, void *a2, unsigned int relative_flag_set) {
    MIRelData *pOut = a0;
    MIRelData *pParamA = a1;
    MIRelData *pParamB = a2;

    *pOut = *pParamA;
    if (relative_flag_set & 1) pOut->x = pParamA->x + pParamB->x;
    if (relative_flag_set & 2) pOut->y = pParamA->y + pParamB->y;
    if (relative_flag_set & 4) pOut->w = pParamA->w + pParamB->w;
    if (relative_flag_set & 8) pOut->h = pParamA->h + pParamB->h;
    if (relative_flag_set & 0x10) pOut->u = pParamA->u + pParamB->u;
    if (relative_flag_set & 0x20) pOut->v = pParamA->v + pParamB->v;
    if (relative_flag_set & 0x40) pOut->tw = pParamA->tw + pParamB->tw;
    if (relative_flag_set & 0x80) pOut->th = pParamA->th + pParamB->th;
    return 1;
}



/* MenuItemMng_Draw @ 0x1EE4B0 .. 0x1EF9C4 (0x1514 bytes, frame 0xb20) */

extern signed int MngState_DrawExeCheck(void *);
extern signed int Menu_GetGetItemId(void);

extern signed int KnMenuMng_CheckCtrlPlay(int, signed int);
extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void * memcpy(void *, const void *, unsigned int);
extern void FontDrawBegin(int);
extern void SetFontColorRGBA(unsigned int);
extern signed int FsFontSetScale(float, float);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern signed int FsFontReplaceText(void *, void *, ...);
extern u32 fptodp(float);
extern signed int FsFontSetAlignment(signed int);
extern signed int FsFontSetDisableColor(void);
extern void FontPrintInRect(float, float, float, float, char *, ...);
extern signed int FsFontSetEnableColor(void);
extern void FontPrintXY(float, float, char *, ...);
extern void FontDrawEnd(void);

extern u32 lpMdlPacketMem;
extern u32 L2051[];

#ifndef PROTO_DW_2407860_FIELDS
#define PROTO_DW_2407860_FIELDS
struct dw_2407860_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_2403759_FIELDS
#define PROTO_DW_2403759_FIELDS
struct dw_2403759_fields { int pos_x; int pos_y; int size_w; int size_h; int col_r; int col_g; int col_b; int col_a; };
#endif
#ifndef PROTO_DW_2406978_FIELDS
#define PROTO_DW_2406978_FIELDS
union dw_2406978_fields { char _s8; short _s16; int _s32; long _s64; unsigned char _u8; unsigned short _u16; unsigned int _u32; unsigned int _u64; float _f32; u_long128 _u128; int _q128[4]; unsigned char *_p8; void *_pv; };
#endif
#ifndef PROTO_DW_2409403_FIELDS
#define PROTO_DW_2409403_FIELDS
struct dw_2409403_fields { struct dw_2403759_fields anim_arrange; int now_frame; int now_anim_id; int now_tex_anim_counter; int anim_play_counter; int func_id; float tex_u; float tex_v; float tex_w; float tex_h; unsigned char _pad0[12]; union dw_2406978_fields variable; int force_anim_id; float force_anim_ratio; float dmy; unsigned char _pad1[4]; };
#endif
#ifndef PROTO_DW_2404084_FIELDS
#define PROTO_DW_2404084_FIELDS
struct dw_2404084_fields { int ctrl_decide : 1; int ctrl_cancel : 1; int ctrl_up : 1; int ctrl_down : 1; int ctrl_left : 1; int ctrl_right : 1; int ctrl_option : 1; int item_decide : 1; int item_cancel : 1; int item_up : 1; int item_down : 1; int item_left : 1; int item_right : 1; int item_option : 1; int exe_decide : 1; int exe_cancel : 1; int exe_up : 1; int exe_down : 1; int exe_left : 1; int exe_right : 1; int exe_option : 1; int force_end_none : 1; int force_end_end : 1; int through : 1; unsigned int : 8; int reserve : 18; unsigned int : 14; };
#endif
#ifndef PROTO_DW_2401203_FIELDS
#define PROTO_DW_2401203_FIELDS
struct dw_2401203_fields { struct dw_2407860_fields mng_state; struct dw_2399598_fields *pMenuItemParam; signed char state; unsigned char _pad0[11]; struct dw_2409403_fields MenuItemData; int goto_id; signed char state_order; unsigned char _pad1[3]; int *pParentPosX; int *pParentPosY; int *pAnimNum; struct dw_2402782_fields *pAnimList; int *pTexIdList; struct dw_2404084_fields wait_flag; unsigned char _pad2[12]; float old_draw_pos[4]; int link_id; unsigned char _pad3[12]; };
#endif
#ifndef PROTO_DW_2402102_FIELDS
#define PROTO_DW_2402102_FIELDS
struct dw_2402102_fields { unsigned int use_ctrl_arg_data : 1; unsigned int reserve : 31; };

#endif
#ifndef PROTO_DW_2399598_FIELDS
#define PROTO_DW_2399598_FIELDS
struct dw_2399598_fields { int id; int item_type; struct dw_2402102_fields mip_gene_flag; unsigned int set_item_data_on; int p_data; unsigned int data_type; unsigned int special_proc_type; unsigned int blend_type; int bokasi_data; int dmy4; int center_flg; int msg_id; int start_anim_id; int wait_anim_id; int end_anim_id; float font_scale; int start_anim_play_num; int wait_anim_play_num; int end_anim_play_num; int font_size; int select_se_id; int decide_se_id; int cancel_se_id; unsigned int size_def_on; int start_func_id; int wait_func_id; int end_func_id; unsigned short tex_uv_rrot_num; unsigned short tex_uv_rl_symmetry; int tex_index_id; int tex_anim_type; int tex_anim_x; int tex_anim_y; float tex_u; float tex_v; float tex_w; float tex_h; struct dw_2403759_fields anim_arrange; unsigned char item_name[64]; };
#endif
#ifndef PROTO_DW_2410654_FIELDS
#define PROTO_DW_2410654_FIELDS
struct dw_2410654_fields { unsigned long TBP0 : 14; unsigned long TBW : 6; unsigned long PSM : 6; unsigned long TW : 4; unsigned long TH : 4; unsigned long TCC : 1; unsigned long TFX : 2; unsigned long CBP : 14; unsigned long CPSM : 4; unsigned long CSM : 1; unsigned long CSA : 5; unsigned long CLD : 3; };

#endif
#ifndef PROTO_DW_2403223_FIELDS
#define PROTO_DW_2403223_FIELDS
struct dw_2403223_fields { long LCM : 1; long pad01 : 1; long MXL : 3; long MMAG : 1; long MMIN : 3; long MTBA : 1; long pad10 : 9; long L : 2; long pad21 : 11; long K : 12; long pad44 : 20; };
#endif
#ifndef PROTO_DW_2410236_FIELDS
#define PROTO_DW_2410236_FIELDS
struct dw_2410236_fields { long ATE : 1; long ATST : 3; long AREF : 8; long AFAIL : 2; long DATE : 1; long DATM : 1; long ZTE : 1; long ZTST : 2; long pad19 : 45; };
#endif
#ifndef PROTO_DW_2402258_FIELDS
#define PROTO_DW_2402258_FIELDS
struct dw_2402258_fields { unsigned short bUse : 1; unsigned short Fst : 1; unsigned short Alpha : 2; unsigned short LoadOff : 1; unsigned short unused : 11; unsigned short texID; unsigned char _pad0[12]; int ver[4][4]; int col[4][4]; int uv[4][4]; struct dw_2410654_fields tex0; struct dw_2403223_fields tex1; struct dw_2410236_fields test; unsigned char _pad1[8]; };
#endif
#ifndef PROTO_DW_2399133_FIELDS
#define PROTO_DW_2399133_FIELDS
struct dw_2399133_fields { unsigned char bUse; unsigned char unused0; unsigned short id; struct dw_2406575_fields *lpTm2; void *lpTexList; int unused1[1]; unsigned char texName[32]; unsigned char texNameBase[32]; int texW; int texH; int texTBW; int texPSM; };
#endif
#ifndef PROTO_DW_2410085_FIELDS
#define PROTO_DW_2410085_FIELDS
struct dw_2410085_fields { unsigned char r; unsigned char g; unsigned char b; unsigned char a; };
#endif
#ifndef PROTO_DW_2408826_FIELDS
#define PROTO_DW_2408826_FIELDS
struct dw_2408826_fields { int relative_pos_x : 1; int relative_pos_y : 1; int relative_size_x : 1; int relative_size_y : 1; int relative_cal_r : 1; int relative_cal_g : 1; int relative_cal_b : 1; int relative_cal_a : 1; int reserve : 24; };
#endif
#ifndef PROTO_DW_2402782_FIELDS
#define PROTO_DW_2402782_FIELDS
struct dw_2402782_fields { int id; int anim_type; int frame_num; float rate; struct dw_2408826_fields menu_ctrl_anim_flag; int next_anim_id; int next_anim_play_num; int wait_through; struct dw_2403759_fields anim_arrange; };
#endif
#ifndef PROTO_DW_2406575_FIELDS
#define PROTO_DW_2406575_FIELDS
struct dw_2406575_fields { unsigned int size; unsigned int wnum; unsigned char dummy[5]; unsigned char compare; unsigned short tex_id; struct dw_2410654_fields tex0; struct dw_2403223_fields tex1; };
#endif
extern void SetFontColor(struct dw_2410085_fields);

signed int MenuItemMng_Draw(struct dw_2401203_fields *pMenuItemMng, int tex_load_on, float p_size, float p_colR, float p_colG, float p_colB, float p_colA) {
    struct dw_2399598_fields *pItemP;
    struct dw_2409403_fields *pItemD;
    int item_id;
    struct dw_2402258_fields SpTest;
    int col[4];
    int offset_pos_x;
    int offset_pos_y;
    float offset_size_x;
    float offset_size_y;
    unsigned short tex_id;
    struct dw_2403759_fields DrawArrangeData;
    int tex_ok;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    int gray_texture_on;
    struct dw_2403759_fields tmpArrange;
    struct dw_2399133_fields *lpTexMng;
    int texW;
    int texH;
    int i;
    unsigned int *lpPacket;
    int bokasi_num;
    int bokasi_offset;
    int bokasi_alpha;
    int b;
    struct dw_2402258_fields Sprite;
    unsigned short *pMsg;
    unsigned short *pMsgTmp;
    unsigned short *pMsgData;
    struct dw_2410085_fields color;

    if (pMenuItemMng == 0) {
        return 0;
    }
    if (MngState_DrawExeCheck(pMenuItemMng) != 1) {
        return 1;
    }
    pItemP = pMenuItemMng->pMenuItemParam;
    pItemD = &pMenuItemMng->MenuItemData;
    item_id = Menu_GetGetItemId();
    item_id = item_id / 10000;
    item_id = item_id % 10;
    if (KnMenuMng_CheckCtrlPlay(7, 0) != 0 && pItemP->id == 0xb && item_id == 3) {
    } else if (KnMenuMng_CheckCtrlPlay(7, 0) != 0 && pItemP->id == 0x1b && item_id != 3) {
    } else if (pItemP->special_proc_type == 4 && pItemP->data_type == 3 && pItemP->p_data != pMenuItemMng->MenuItemData.variable._s32) {
    } else {
        offset_pos_x = 0;
        offset_pos_y = 0;

        offset_size_x = 1.0f;
        tex_id = 0;
        DrawArrangeData = pItemD->anim_arrange;
        offset_size_y = 1.0f;
        gray_texture_on = 0;
        if (pItemD->force_anim_id >= 0) {
            MenuItemMng_RelativeData_Add(&tmpArrange, &pMenuItemMng->pAnimList[pItemD->force_anim_id].anim_arrange, &pItemP->anim_arrange, *(unsigned int *)&pMenuItemMng->pAnimList[pItemD->force_anim_id].menu_ctrl_anim_flag);
            DrawArrangeData.pos_x = (int)(0.5f + ((float)pItemP->anim_arrange.pos_x * pItemD->force_anim_ratio + (float)tmpArrange.pos_x * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.pos_y = (int)(0.5f + ((float)pItemP->anim_arrange.pos_y * pItemD->force_anim_ratio + (float)tmpArrange.pos_y * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.size_w = (int)(0.5f + ((float)pItemP->anim_arrange.size_w * pItemD->force_anim_ratio + (float)tmpArrange.size_w * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.size_h = (int)(0.5f + ((float)pItemP->anim_arrange.size_h * pItemD->force_anim_ratio + (float)tmpArrange.size_h * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.col_r = (int)(0.5f + ((float)pItemP->anim_arrange.col_r * pItemD->force_anim_ratio + (float)tmpArrange.col_r * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.col_g = (int)(0.5f + ((float)pItemP->anim_arrange.col_g * pItemD->force_anim_ratio + (float)tmpArrange.col_g * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.col_b = (int)(0.5f + ((float)pItemP->anim_arrange.col_b * pItemD->force_anim_ratio + (float)tmpArrange.col_b * (1.0f - pItemD->force_anim_ratio)));
            DrawArrangeData.col_a = (int)(0.5f + ((float)pItemP->anim_arrange.col_a * pItemD->force_anim_ratio + (float)tmpArrange.col_a * (1.0f - pItemD->force_anim_ratio)));
        }
        if (pItemP->special_proc_type == 5) {
            if (pItemP->data_type == 9) {
                offset_pos_x += (float)(pItemP->p_data % 1000000 / 1000) * pMenuItemMng->MenuItemData.variable._f32;
                if (pItemP->p_data / 1000000 % 10 % 2 == 1) {
                    offset_pos_x = -offset_pos_x;
                }
                offset_pos_y += (float)(pItemP->p_data % 1000) * pMenuItemMng->MenuItemData.variable._f32;
                if (!(pItemP->p_data / 1000000 % 10 < 2)) {
                    offset_pos_y = -offset_pos_y;
                }
            }
        }
        if (pItemP->special_proc_type == 6) {
            if (pItemP->data_type == 9) {
                offset_size_x = (float)(pItemP->p_data % 1000000 / 1000) * pMenuItemMng->MenuItemData.variable._f32;
                if (pItemP->p_data / 1000000 % 10 % 2 == 1) {
                    offset_size_x = offset_size_x * -1.0f;
                }
                offset_size_y = (float)(pItemP->p_data % 1000) * pMenuItemMng->MenuItemData.variable._f32;
                if (!(pItemP->p_data / 1000000 % 10 < 2)) {
                    offset_size_y = offset_size_y * -1.0f;
                }
                if (pItemP->p_data % 1000 == 0) {
                    offset_size_y = 1.0f;
                }
            }
        }
        if (pItemP->mip_gene_flag.use_ctrl_arg_data) {
            p_colR = p_colR;
        } else {
            p_colR = 1.0f;
        }
        col[0] = (int)((float)DrawArrangeData.col_r * p_colR);
        if (pItemP->mip_gene_flag.use_ctrl_arg_data) {
            p_colG = p_colG;
        } else {
            p_colG = 1.0f;
        }
        col[1] = (int)((float)DrawArrangeData.col_g * p_colG);
        if (pItemP->mip_gene_flag.use_ctrl_arg_data) {
            p_colB = p_colB;
        } else {
            p_colB = 1.0f;
        }
        col[2] = (int)((float)DrawArrangeData.col_b * p_colB);
        if (pItemP->mip_gene_flag.use_ctrl_arg_data) {
            p_colA = p_colA;
        } else {
            p_colA = 1.0f;
        }
        col[3] = (int)((float)DrawArrangeData.col_a * p_colA);
        posX = (int)(0.5f + 0.8f * (((float)offset_pos_x + ((float)DrawArrangeData.pos_x + (float)*pMenuItemMng->pParentPosX * p_size)) - 320.0f));
        posY = (int)(0.5f + (((float)offset_pos_y + ((float)DrawArrangeData.pos_y + (float)*pMenuItemMng->pParentPosY * p_size)) - 224.0f));
        if (pItemP->size_def_on != 0) {
            sizeX = (int)(p_size * ((float)DrawArrangeData.size_w * offset_size_x));
            sizeY = (int)(p_size * ((float)DrawArrangeData.size_h * offset_size_y));
        } else {
            sizeX = (int)(0.5f + 0.8f * (p_size * ((float)DrawArrangeData.size_w * offset_size_x)));
            sizeY = (int)(0.5f + p_size * ((float)DrawArrangeData.size_h * offset_size_y));
        }
        pMenuItemMng->old_draw_pos[0] = (0.5f + ((float)posX + (float)sizeX / 2.0f)) / 256.0f;
        pMenuItemMng->old_draw_pos[1] = (0.5f + ((float)posY + (float)sizeY / 2.0f)) / 224.0f;
        if (pItemP->item_type == 1) {
            tex_ok = 1;
            if (pItemP->special_proc_type == 3) {
                tex_id = pMenuItemMng->MenuItemData.variable._u16 & 0x7fff;
                gray_texture_on = (pMenuItemMng->MenuItemData.variable._u16 & 0x8000) != 0;
            } else {
                if (pMenuItemMng->pTexIdList[pItemP->tex_index_id] >= 0) {
                    tex_id = pMenuItemMng->pTexIdList[pItemP->tex_index_id];
                } else {
                    tex_ok = 0;
                }
            }
            if (tex_ok == 1) {
                if (gray_texture_on) {
                    col[0] = col[0] / 4;
                    col[1] = col[1] / 4;
                    col[2] = col[2] / 4;
                }
                SetSprite(&SpTest, posX, posY, sizeX, sizeY, col, tex_id, 0);
                lpTexMng = 0;
                if (tex_id >= 0) {
                    lpTexMng = GetTexMngByID(tex_id);
                }
                if (lpTexMng != 0) {
                    texW = 1 << lpTexMng->lpTm2->tex0.TW;
                    texH = 1 << lpTexMng->lpTm2->tex0.TH;
                    SpTest.tex0 = lpTexMng->lpTm2->tex0;
                    SpTest.tex1 = lpTexMng->lpTm2->tex1;
                    SpTest.Fst = 0;

                    if (SpTest.Fst == 0) {
                        SpTest.uv[0][0] = (int)(pItemD->tex_u * texW) << 4;
                        SpTest.uv[0][1] = (int)(pItemD->tex_v * texH) << 4;
                        SpTest.uv[1][0] = ((int)(pItemD->tex_u * texW) + (int)(pMenuItemMng->MenuItemData.tex_w * texW)) << 4;
                        SpTest.uv[1][1] = (int)(pItemD->tex_v * texH) << 4;
                        SpTest.uv[2][0] = (int)(pItemD->tex_u * texW) << 4;
                        SpTest.uv[2][1] = ((int)(pItemD->tex_v * texH) + (int)(pMenuItemMng->MenuItemData.tex_h * texH)) << 4;
                        SpTest.uv[3][0] = ((int)(pItemD->tex_u * texW) + (int)(pMenuItemMng->MenuItemData.tex_w * texW)) << 4;
                        SpTest.uv[3][1] = ((int)(pItemD->tex_v * texH) + (int)(pMenuItemMng->MenuItemData.tex_h * texH)) << 4;
                    } else {
                        SpTest.uv[0][0] = 0;
                        SpTest.uv[0][1] = 0;
                        SpTest.uv[0][2] = 0x3f800000;
                        SpTest.uv[1][0] = 0x3f800000;
                        SpTest.uv[1][1] = 0;
                        SpTest.uv[1][2] = 0x3f800000;
                        SpTest.uv[2][0] = 0;
                        SpTest.uv[2][1] = 0x3f800000;
                        SpTest.uv[2][2] = 0x3f800000;
                        SpTest.uv[3][0] = 0x3f800000;
                        SpTest.uv[3][1] = 0x3f800000;
                        SpTest.uv[3][2] = 0x3f800000;
                    }
                    for (i = 0; i < pItemP->tex_uv_rrot_num; i++) {
                        int t0x = SpTest.ver[0][0];
                        int t0y = SpTest.ver[0][1];
                        int t1x = SpTest.ver[1][0];
                        int t1y = SpTest.ver[1][1];
                        int t2x = SpTest.ver[2][0];
                        int t2y = SpTest.ver[2][1];
                        int t3x = SpTest.ver[3][0];
                        int t3y = SpTest.ver[3][1];
                        SpTest.ver[0][0] = t1x;
                        SpTest.ver[0][1] = t1y;
                        SpTest.ver[1][0] = t3x;
                        SpTest.ver[1][1] = t3y;
                        SpTest.ver[2][0] = t0x;
                        SpTest.ver[2][1] = t0y;
                        SpTest.ver[3][0] = t2x;
                        SpTest.ver[3][1] = t2y;
                    }
                    if (pItemP->tex_uv_rl_symmetry == 1) {
                        int u0x = SpTest.uv[0][0];
                        int u0y = SpTest.uv[0][1];
                        int u1x = SpTest.uv[1][0];
                        int u1y = SpTest.uv[1][1];
                        int u2x = SpTest.uv[2][0];
                        int u2y = SpTest.uv[2][1];
                        int u3x = SpTest.uv[3][0];
                        int u3y = SpTest.uv[3][1];
                        SpTest.uv[0][0] = u1x;
                        SpTest.uv[0][1] = u1y;
                        SpTest.uv[1][0] = u0x;
                        SpTest.uv[1][1] = u0y;
                        SpTest.uv[2][0] = u3x;
                        SpTest.uv[2][1] = u3y;
                        SpTest.uv[3][0] = u2x;
                        SpTest.uv[3][1] = u2y;
                    }
                    lpMdlPacketMem = (u32)MenuItemMng_MakeSpritePacketUseSpr((u8 *)&SpTest, (u32 *)lpMdlPacketMem, pItemP->blend_type, 1);
                    bokasi_num = pItemP->bokasi_data / 10000 % 10;
                    bokasi_offset = pItemP->bokasi_data / 1000 % 10;
                    bokasi_alpha = pItemP->bokasi_data % 1000;
                    memcpy(&Sprite, &SpTest, 0xf0);
                    for (b = 0; b < bokasi_num * 2 + 1; b++) {
                        int offset;
                        int col;
                        lpPacket = (unsigned int *)lpMdlPacketMem;
                        offset = 0;
                        col = 0;
                        if (bokasi_num > 0) {
                            offset = bokasi_offset * ((b - 1) % bokasi_num + 1);
                        }
                        if (bokasi_num < b) {
                            offset = -offset;
                        }
                        if (b > 0) {
                            col = bokasi_alpha * (bokasi_num - ((b - 1) % bokasi_num + 1));
                        }
                        Sprite.ver[0][0] = SpTest.ver[0][0] & -0x10;
                        Sprite.ver[0][1] = ((SpTest.ver[0][1] >> 4) + offset) << 4;
                        Sprite.ver[1][0] = SpTest.ver[1][0] & -0x10;
                        Sprite.ver[1][1] = ((SpTest.ver[1][1] >> 4) + offset) << 4;
                        Sprite.ver[2][0] = SpTest.ver[2][0] & -0x10;
                        Sprite.ver[2][1] = ((SpTest.ver[2][1] >> 4) + offset) << 4;
                        Sprite.ver[3][0] = SpTest.ver[3][0] & -0x10;
                        Sprite.ver[3][1] = ((SpTest.ver[3][1] >> 4) + offset) << 4;
                        Sprite.col[0][3] = col;
                        Sprite.col[1][3] = col;
                        Sprite.col[2][3] = col;
                        Sprite.col[3][3] = col;
                        lpMdlPacketMem = (u32)MenuItemMng_MakeSpritePacketUseSpr((u8 *)&Sprite, lpPacket, pItemP->blend_type, tex_load_on);
                    }
                }
            }
        }
        if (pItemP->item_type == 2) {
            FontDrawBegin(0);
            SetFontColorRGBA(0x7f7f7f7f);
            if (pItemP->msg_id > 0) {
                unsigned char aMsgBuf[1024] = {0};
                unsigned char aMsgBufTmp[1024] = {0};
                pMsg = (unsigned short *)aMsgBuf;
                pMsgTmp = (unsigned short *)aMsgBufTmp;
                color.r = col[0];
                color.g = col[1];
                color.b = col[2];
                color.a = col[3];
                FsFontSetScale(0.8f * pItemP->font_scale * (float)pItemP->font_size / 24.0f * ((float)DrawArrangeData.size_w / (float)pItemP->anim_arrange.size_w), pItemP->font_scale * (float)pItemP->font_size / 24.0f * ((float)DrawArrangeData.size_h / (float)pItemP->anim_arrange.size_h));
                SetFontColor(color);
                pMsgData = KnMsgMng_GetMsgStr(pItemP->msg_id);
                if (pMsgData != 0) {
                    int n;
                    for (n = 0; pMsgData[n] != 0; n++) {
                    }
                    memcpy(pMsg, pMsgData, n * 2 + 2);
                }
                if (pMsgData != 0) {
                    int n;
                    for (n = 0; pMsgData[n] != 0; n++) {
                    }
                    memcpy(pMsgTmp, pMsgData, n * 2 + 2);
                }
                if (pItemP->special_proc_type == 2) {
                    switch (pItemP->data_type) {
                    case 1:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._s8);
                        break;
                    case 2:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._s16);
                        break;
                    case 3:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._s32);
                        break;
                    case 4:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._s64);
                        break;
                    case 5:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._u8);
                        break;
                    case 6:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._u16);
                        break;
                    case 7:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._u32);
                        break;
                    case 8:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._u64);
                        break;
                    case 9:
                        FsFontReplaceText(pMsg, pMsgTmp, fptodp(pMenuItemMng->MenuItemData.variable._f32));
                        break;
                    case 10:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._u128);
                        break;
                    case 12:
                        FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._p8);
                        break;
                    case 13:
                        if (pMenuItemMng->MenuItemData.variable._pv != 0) {
                            FsFontReplaceText(pMsg, pMsgTmp, pMenuItemMng->MenuItemData.variable._pv);
                        } else {
                            FsFontReplaceText(pMsg, pMsgTmp, "");
                        }
                        break;
                    }
                }
                {
                struct dw_2410085_fields color_black = {0};
                color_black.a = color.a;
                FsFontSetAlignment(0x100);
                if (pItemP->center_flg == 1) {
                    FsFontSetAlignment(0xa0);
                    SetFontColor(color_black);
                    FsFontSetDisableColor();
                    {
                        float fx = 2.0f + (float)pMenuItemMng->MenuItemData.anim_arrange.pos_x + (float)*pMenuItemMng->pParentPosX;
                        float fy = 2.0f + (float)pMenuItemMng->MenuItemData.anim_arrange.pos_y + (float)*pMenuItemMng->pParentPosY;
                        FontPrintInRect(fx, fy, (float)pMenuItemMng->MenuItemData.anim_arrange.size_w + fx, (float)pMenuItemMng->MenuItemData.anim_arrange.size_h + fy, (char *)pMsg);
                    }
                    FsFontSetEnableColor();
                    SetFontColor(color);
                    FontPrintInRect((float)(pMenuItemMng->MenuItemData.anim_arrange.pos_x + *pMenuItemMng->pParentPosX), (float)(pMenuItemMng->MenuItemData.anim_arrange.pos_y + *pMenuItemMng->pParentPosY), (float)(pMenuItemMng->MenuItemData.anim_arrange.size_w + (pMenuItemMng->MenuItemData.anim_arrange.pos_x + *pMenuItemMng->pParentPosX)), (float)(pMenuItemMng->MenuItemData.anim_arrange.size_h + (pMenuItemMng->MenuItemData.anim_arrange.pos_y + *pMenuItemMng->pParentPosY))
, (char *)pMsg);
                    FsFontSetAlignment(0x100);
                } else {
                    SetFontColor(color_black);
                    FsFontSetDisableColor();
                    FontPrintXY(256.0f + (0.5f + 512.0f * ((2.0f + (float)(DrawArrangeData.pos_x + *pMenuItemMng->pParentPosX)) - 256.0f) / 640.0f) - 70.0f, 224.0f + (0.5f + 448.0f * ((2.0f + (float)(DrawArrangeData.pos_y + *pMenuItemMng->pParentPosY)) - 224.0f) / 448.0f), (char *)pMsg);
                    FsFontSetEnableColor();
                    SetFontColor(color);
                    FontPrintXY(256.0f + (0.5f + 512.0f * ((float)(DrawArrangeData.pos_x + *pMenuItemMng->pParentPosX) - 256.0f) / 640.0f) - 70.0f, 224.0f + (0.5f + 448.0f * ((float)(DrawArrangeData.pos_y + *pMenuItemMng->pParentPosY) - 224.0f) / 448.0f), (char *)pMsg);
                }
                }
            }
            FsFontSetScale(1.0f, 1.0f);
            SetFontColorRGBA(0x7f7f7f7f);
            FontDrawEnd();
        }
    }
    return 1;
}


/* MenuItemMng_Delete @ 0x1EE490 .. 0x1EE4B0 (0x20 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */





signed int MenuItemMng_Delete(void *a0 /* r4 */) {
    s32 v0;

    v0 = 0;
    if ((u32)a0 == 0) {
        return v0;
    }
    *(u32 *)a0 = 0;
    v0 = 1;
    return v0;
}











extern void FlushCache(int);
static u32 dcomp_ph_DMABuf_1281[0xc0];
void MenuItemMng_MakeAndKickSpritePacket(void *sprite,int mode,int load) {
    u8 *saved;
    int savedMode;
    int savedLoad;
    unsigned int *packet;
    void *texture;
    savedMode=mode;
    savedLoad=load;
    saved=(u8 *)sprite;
    packet=dcomp_ph_DMABuf_1281;
    texture=GetTexMngByID(*(u16 *)((u8 *)sprite+2));
    if((u32)texture!=0) {
    if(savedLoad!=0) packet=MakeTexPacket(packet,texture);
    packet[0]=0x10000013; packet[1]=0; packet[2]=0; packet[3]=0x51000013;
    packet[4]=5; packet[5]=0x10000000; packet[6]=14; packet[7]=0;
    *(u64 *)(packet+8)=0; *(u64 *)(packet+10)=0x3f;
    *(u64 *)(packet+12)=*(u64 *)(saved+224); *(u64 *)(packet+14)=0x47;
    switch((u8)savedMode) {
    case 0: *(u64 *)(packet+16)=0x44; packet+=18; break;
    case 1: *(u64 *)(packet+16)=0x48; packet+=18; break;
    case 2: *(u64 *)(packet+16)=0x42; packet+=18; break;
    case 3: *(u64 *)(packet+16)=0x2a; packet+=18; break;
    default: *(u64 *)(packet+16)=0x44; packet+=18; break;
    }
    *(u64 *)packet=0x42;
    *(u64 *)(packet+2)=*(u64 *)(saved+216); *(u64 *)(packet+4)=20;
    *(u64 *)(packet+6)=*(u64 *)(saved+208); *(u64 *)(packet+8)=6;
    packet[10]=4; packet[11]=0x30ae4000; packet[12]=0x413; packet[13]=0;
    *(u_long128 *)(packet+14)=*(u_long128 *)(saved+144);
    *(u_long128 *)(packet+18)=*(u_long128 *)(saved+80);
    *(u_long128 *)(packet+22)=*(u_long128 *)(saved+16);
    *(u_long128 *)(packet+26)=*(u_long128 *)(saved+160);
    *(u_long128 *)(packet+30)=*(u_long128 *)(saved+96);
    *(u_long128 *)(packet+34)=*(u_long128 *)(saved+32);
    *(u_long128 *)(packet+38)=*(u_long128 *)(saved+176);
    *(u_long128 *)(packet+42)=*(u_long128 *)(saved+112);
    *(u_long128 *)(packet+46)=*(u_long128 *)(saved+48);
    *(u_long128 *)(packet+50)=*(u_long128 *)(saved+192);
    *(u_long128 *)(packet+54)=*(u_long128 *)(saved+128);
    *(u_long128 *)(packet+58)=*(u_long128 *)(saved+64);
    goto kick;
    }
    return;
kick:
    packet[62]=0x70000000; packet[63]=0; packet[64]=0; packet[65]=0;
    FlushCache(0);
    do {} while((*(volatile u32 *)0x10009000&256)!=0 || (*(volatile u32 *)0x1000a000&256)!=0);
    *(volatile u32 *)0x10009020=0;
    *(volatile u32 *)0x10009010=0;
    *(volatile void **)0x10009030=dcomp_ph_DMABuf_1281;
    *(volatile u32 *)0x10009000=0x145;
    do {} while((*(volatile u32 *)0x10009000&256)!=0 || (*(volatile u32 *)0x1000a000&256)!=0);
}


/* MenuItemMng_MakeSpritePacketUseSpr @ 0x1EE000 .. 0x1EE1EC (0x1ec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   delay: addiu at 0x1ee0e0 writes a register its branch at 0x1ee0dc reads
 *   delay: addiu at 0x1ee0f8 writes a register its branch at 0x1ee0f4 reads
 */

unsigned int * MenuItemMng_MakeSpritePacketUseSpr(u8 *a0 /* r4 */, u32 *a1 /* r5 */, u8 a2 /* r6
        */, s32 a3 /* r7 */) {
    u8 *s1;
    u32 s0;
    u32 s2;
    u32 v0;
    u32 a2_guard_word;
    u8 a3_2;

    s2 = a3;
    s1 = a0;
    s0 = (u32)a1;
    v0 = (u32)GetTexMngByID(*(u16 *)(a0 + 2));
    if ((u32)((u32)(*(u8 *)s1) & 1) == 0) {
        return (unsigned int *)s0;
    } else {
        if (v0 != 0) {
            a0 = (u8 *)s0;
            if (s2 != 0) {
                v0 = (u32)MakeTexPacket((unsigned int *)a0, (void *)v0);
                s0 = v0;
            }
            a2_guard_word = 0x10000000;
            *(u32 *)s0 = 0x10000000 | 0x13;
            v0 = 0x51000013;
            *(u32 *)(((u8 *)s0 + 4)) = 0;
            *(u32 *)(((u8 *)s0 + 8)) = 0;
            *(u32 *)(((u8 *)s0 + 0xc)) = 0x51000013;
            *(u32 *)(((u8 *)s0 + 0x10)) = 5;
            *(u32 *)(((u8 *)s0 + 0x14)) = 0x10000000;
            a3_2 = a2;
            a0 = (u8 *)(s32)0xe;
            *(u32 *)(((u8 *)s0 + 0x18)) = (s32)a0;
            *(u32 *)(((u8 *)s0 + 0x1c)) = 0;
            *(u64 *)(((u8 *)s0 + 0x20)) = 0;
            *(s64 *)(((u8 *)s0 + 0x28)) = (s32)0x3f;
            *(u64 *)(((u8 *)s0 + 0x30)) = *(u64 *)(s1 + 0xe0);
            *(s64 *)(((u8 *)s0 + 0x38)) = (s32)0x47;
            s0 = s0 + 0x40;
            if (a3_2 == 0) {
                *(s64 *)s0 = (s32)0x44;
                s0 = s0 + 8;
            }
            if (a3_2 == (u32)1) {
                *(s64 *)s0 = (s32)0x48;
                s0 = s0 + 8;
            }
            if (a3_2 == (u32)2) {
                *(s64 *)s0 = (s32)0x42;
                s0 = s0 + 8;
            }
            *(s64 *)s0 = (s32)0x42;
            *(u64 *)((s0 + 8)) = *(u64 *)(s1 + 0xd8);
            *(s64 *)((s0 + 0x10)) = (s32)0x14;
            *(u64 *)((s0 + 0x18)) = *(u64 *)(s1 + 0xd0);
            *(s64 *)((s0 + 0x20)) = (s32)6;
            s0 = s0 + 0x28;
            if ((u64)((u64)((u64)(u32)*(u8 *)s1 << 0x3e) >> 0x3f) == 0) {
                *(u32 *)s0 = 4;
                v0 = 0x30ae4000;
                *(u32 *)((s0 + 4)) = 0x30ae4000;
                *(u32 *)((s0 + 8)) = 0x413;
                *(u32 *)((s0 + 0xc)) = 0;
                *(u_long128 *)((s0 + 0x10)) = *(u_long128 *)(s1 + 0x90);
                *(u_long128 *)((s0 + 0x20)) = *(u_long128 *)(s1 + 0x50);
                *(u_long128 *)((s0 + 0x30)) = *(u_long128 *)(s1 + 0x10);
                *(u_long128 *)((s0 + 0x40)) = *(u_long128 *)(s1 + 0xa0);
                *(u_long128 *)((s0 + 0x50)) = *(u_long128 *)(s1 + 0x60);
                *(u_long128 *)((s0 + 0x60)) = *(u_long128 *)(s1 + 0x20);
                *(u_long128 *)((s0 + 0x70)) = *(u_long128 *)(s1 + 0xb0);
                *(u_long128 *)((s0 + 0x80)) = *(u_long128 *)(s1 + 0x70);
                *(u_long128 *)((s0 + 0x90)) = *(u_long128 *)(s1 + 0x30);
                *(u_long128 *)((s0 + 0xa0)) = *(u_long128 *)(s1 + 0xc0);
                *(u_long128 *)((s0 + 0xb0)) = *(u_long128 *)(s1 + 0x80);
                *(u_long128 *)((s0 + 0xc0)) = *(u_long128 *)(s1 + 0x40);
                s0 = s0 + 0xd0;
            }
        }
        return (unsigned int *)(s32)s0;
    }
    return (unsigned int *)v0;
}

