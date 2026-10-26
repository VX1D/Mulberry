#include "common.h"
#include "KuonMenu.h"

/* ---- .sdata ---- */
static s32 s_get_item_id = -1;
static s32 s_get_item_buf_on = 1;
static s32 s_force_anim_id_u = -1;
static s32 s_force_anim_id_d = -1;
static s32 s_scrl_on = 1;
static s32 s_next_ctrl_or_item = -10;
s16 s_memoca_state_msg_id = -1;
static u8 s_memoca_real_time_check_state __attribute__((aligned(4))) = 3;
static u8 s_memoca_state __attribute__((aligned(4))) = 1;
static u8 s_check_next_state __attribute__((aligned(4))) = 5;
s8 s_memoca_decide_state_order __attribute__((aligned(4))) = -1;
s8 s_fixed_end_state __attribute__((aligned(4))) = -1;
static s32 s_ctrl_func_menu_id = -1;
static s32 s_ctrl_func_ctrl_id = -1;
static s16 s_last_reload_type __attribute__((aligned(4))) = -32768;
static u8 s_menu_break_key_type __attribute__((aligned(4))) = 0x10;

/* ---- .sbss (MWCC places uninitialized objects in reverse definition order) ---- */
s32 stg_str_key;
s32 stg_str_vib;
s32 stg_str_bgm;
s32 stg_str_se;
s32 stg_str_voice;
s32 stg_str_kido;
s32 stg_str_SndMode;
s32 stg_str_lang;
static s32 no_snd_on;
static s32 no_snd_counter;
static s32 s_nokoribi;
static s32 s_no_pad_check;
static s32 s_DialogUseCounter;
static s32 s_dialog_state;
static s32 s_now_dialog_id;
static u8 s_aDialogResult[4];
static s32 s_MenuFileBndBuf;
static s32 s_stick_udlr_old;
static s32 s_stick_udlr;
static s32 s_stick_cursol_on;
static s32 s_menu_map_now_tex_id;
static u8 s_MapTex_SorL __attribute__((aligned(4)));
u8 s_go_ttl_state;
s32 s_fixed_fail_msg_id;
s32 s_next_mode;
s8 s_memoca_decide_state;
static s32 s_check_next_msg_id;
static s32 use_memoca_slot;
static s32 memoca_index_offset;
static s32 s_load_offset;
static s32 s_load_slot;
static s32 menu_save_ok;
static s32 menu_load_ok;
static s32 s_end_save;
static s32 s_BookFaile;
static s32 s_EquipFaile;
static f32 s_force_anim_ratio;
static s32 s_item_use_check;
static s32 s_get_item_buf_wait;
static s32 s_now_get_item_num;
static s32 book_doc_page;
u8 now_equip_button;
static s32 s_now_doc_id;
static s32 book_offset;
static s32 item_offset;
static s32 equip_offset;
static u8 stick_data;
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void * memcpy(void *, void *, unsigned int);
extern signed int FsFontReplaceText(void *, void *, ...);
extern u32 s_aDialogMsg[];
void MI_Check_Arrow(u32 *a0 /* r4 */);
void MI_Check_BtnGuide(u32 *a0 /* r4 */);
void MI_Check_CngStr(u32 *a0 /* r4 */);
extern void MI_Check_CngTex(void *, signed int);
void MI_Check_Ctrler(u32 *a0 /* r4 */);
void MI_Check_Dmy(u32 *a0 /* r4 */);
extern void MI_Check_Equip(void *, signed int);
extern void MI_Check_GoTtl(void *);
void MI_Check_HelpStr(u32 *a0 /* r4 */);
struct ItemScrlBits { u8 b0_0:1, b0_1:1, b0_2:1, b0_3:1, b0_4:1, b0_5:1, b0_6:1, b0_7:1; u8 b1_0:1, b1_1:1, b1_2:1, b1_3:1, b1_4:1, b1_5:1, b1_6:1, b1_7:1; u8 pad[2]; };
extern void MI_Check_ItemScrl(struct ItemScrlBits *, signed int);
void MI_Check_ItemStr(void *a0 /* r4 */);
void MI_Check_KeyType(u32 *a0 /* r4 */);
void MI_Check_LangType(u32 *a0 /* r4 */);
void MI_Check_Load(void *a0 /* r4 */, signed int a1 /* r5 */);
extern void MI_Check_MapTex(void *, signed int);
extern void MI_Check_Memoca(void *);
void MI_Check_MsgDlg(s32 *item);
void MI_Check_Num(u32 *a0 /* r4 */);
void MI_Check_SL_Scrl(u32 *a0 /* r4 */);
void MI_Check_Setting(void);
void MI_Check_SldBar(u32 *a0 /* r4 */);
void MI_Check_Stereo(u32 *a0 /* r4 */);
void MI_Check_Stick(u32 *a0 /* r4 */);
void MI_Check_Test(void);
extern void MI_Check_Top(void *, signed int);
void MI_Check_Vib(u32 *a0 /* r4 */);
void MI_CntDown_Arrow(void);
void MI_CntDown_BtnGuide(void);
void MI_CntDown_CngStr(void);
void MI_CntDown_CngTex(void);
void MI_CntDown_Ctrler(void);
void MI_CntDown_Dmy(void);
void MI_CntDown_Equip(void);
void MI_CntDown_GoTtl(void);
void MI_CntDown_HelpStr(void);
void MI_CntDown_ItemScrl(signed int a0 /* r4 */, s32 a1);
void MI_CntDown_ItemStr(signed int a0 /* r4 */, s32 a1);
void MI_CntDown_KeyType(void);
void MI_CntDown_LangType(void);
void MI_CntDown_Load(signed int a0 /* r4 */, s32 a1);
void MI_CntDown_MapTex(void);
void MI_CntDown_Memoca(void);
void MI_CntDown_MsgDlg(void);
void MI_CntDown_Num(void);
void MI_CntDown_SL_Scrl(void);
void MI_CntDown_Setting(void);
extern void MI_CntDown_SldBar(void *, signed int);
void MI_CntDown_Stereo(void *a0 /* r4 */);
void MI_CntDown_Stick(void);
void MI_CntDown_Test(void);
void MI_CntDown_Top(void);
void MI_CntDown_Vib(void);
void MI_CntUp_Arrow(void);
void MI_CntUp_BtnGuide(void);
void MI_CntUp_CngStr(void);
void MI_CntUp_CngTex(void);
void MI_CntUp_Ctrler(void);
void MI_CntUp_Dmy(void);
void MI_CntUp_Equip(void);
void MI_CntUp_GoTtl(void);
void MI_CntUp_HelpStr(void);
void MI_CntUp_ItemScrl(signed int a0 /* r4 */, s32 a1);
void MI_CntUp_ItemStr(signed int a0 /* r4 */, s32 a1);
void MI_CntUp_KeyType(void);
void MI_CntUp_LangType(void);
void MI_CntUp_Load(signed int a0 /* r4 */, s32 a1);
void MI_CntUp_MapTex(void);
void MI_CntUp_Memoca(void);
void MI_CntUp_MsgDlg(void);
void MI_CntUp_Num(void);
void MI_CntUp_SL_Scrl(void);
void MI_CntUp_Setting(void);
extern void MI_CntUp_SldBar(void *, signed int);
void MI_CntUp_Stereo(void *a0 /* r4 */);
void MI_CntUp_Stick(void);
void MI_CntUp_Test(void);
void MI_CntUp_Top(void);
void MI_CntUp_Vib(void);
void MI_Decide_Arrow(void);
void MI_Decide_BtnGuide(void);
void MI_Decide_CngStr(void);
void MI_Decide_CngTex(void);
void MI_Decide_Ctrler(void);
void MI_Decide_Dmy(void);
void MI_Decide_Equip(void *a0 /* r4 */, signed int a1 /* r5 */);
u32 MI_Decide_GoTtl(void);
void MI_Decide_HelpStr(void);
void MI_Decide_ItemScrl(signed int a0, s32 id);
void MI_Decide_ItemStr(void);
void MI_Decide_KeyType(void);
void MI_Decide_LangType(void);
u32 MI_Decide_Load(void);
void MI_Decide_MapTex(void);
void MI_Decide_Memoca(void);
void MI_Decide_MsgDlg(void);
void MI_Decide_Num(void);
void MI_Decide_SL_Scrl(void);
void MI_Decide_Setting(void);
void MI_Decide_SldBar(void);
void MI_Decide_Stereo(void);
void MI_Decide_Stick(void);
void MI_Decide_Test(void);
extern void MI_Decide_Top(void *, signed int);
void MI_Decide_Vib(void);
void MI_Evrfrm_Arrow(u32 *a0 /* r4 */, s32 a1 /* r5 */);
extern void MI_Evrfrm_BtnGuide(void *, signed int);
extern void MI_Evrfrm_CngStr(void *, signed int);
extern void MI_Evrfrm_CngTex(void *, signed int);
void MI_Evrfrm_Ctrler(void *a0 /* r4 */, signed int a1 /* r5 */);
void MI_Evrfrm_Dmy(void);
extern void MI_Evrfrm_Equip(void *, signed int);
void MI_Evrfrm_GoTtl(void);
extern void MI_Evrfrm_HelpStr(void *, signed int);
extern void MI_Evrfrm_ItemScrl(void *, signed int);
extern void MI_Evrfrm_ItemStr(void *, signed int);
void MI_Evrfrm_KeyType(void *a0 /* r4 */);
void MI_Evrfrm_LangType(void *a0 /* r4 */);
extern void MI_Evrfrm_Load(void *, signed int);
extern void MI_Evrfrm_MapTex(void *, signed int);
void MI_Evrfrm_Memoca(void *a0 /* r4 */, signed int a1 /* r5 */);
void MI_Evrfrm_MsgDlg(void);
extern void MI_Evrfrm_Num(void *, signed int);
void MI_Evrfrm_SL_Scrl(void *a0 /* r4 */);
void MI_Evrfrm_Setting(void);
void MI_Evrfrm_SldBar(void *a0 /* r4 */, signed int a1 /* r5 */);
void MI_Evrfrm_Stereo(void *a0 /* r4 */);
void MI_Evrfrm_Stick(void *a0 /* r4 */);
void MI_Evrfrm_Test(void);
void MI_Evrfrm_Top(void);
void MI_Evrfrm_Vib(void *a0 /* r4 */);
void MI_Gene1_Arrow(void);
void MI_Gene1_BtnGuide(void);
void MI_Gene1_CngStr(void);
void MI_Gene1_CngTex(void);
void MI_Gene1_Ctrler(void);
void MI_Gene1_Dmy(void);
void MI_Gene1_Equip(void);
void MI_Gene1_GoTtl(void);
void MI_Gene1_HelpStr(void);
void MI_Gene1_ItemScrl(signed int a0 /* r4 */, s32 a1);
void MI_Gene1_ItemStr(void);
void MI_Gene1_KeyType(void);
void MI_Gene1_LangType(void);
void MI_Gene1_Load(void);
void MI_Gene1_MapTex(signed int unused, s32 state);
u32 MI_Gene1_Memoca(void);
void MI_Gene1_MsgDlg(void);
void MI_Gene1_Num(void);
void MI_Gene1_SL_Scrl(void);
u32 MI_Gene1_Setting(void);
void MI_Gene1_SldBar(void);
void MI_Gene1_Stereo(void);
void MI_Gene1_Stick(void);
void MI_Gene1_Test(void);
void MI_Gene1_Top(void);
void MI_Gene1_Vib(void);
void MI_Gene2_Arrow(void);
void MI_Gene2_BtnGuide(void);
void MI_Gene2_CngStr(void);
void MI_Gene2_CngTex(void);
void MI_Gene2_Ctrler(void);
void MI_Gene2_Dmy(void);
void MI_Gene2_Equip(void);
void MI_Gene2_GoTtl(void);
void MI_Gene2_HelpStr(void);
void MI_Gene2_ItemScrl(signed int a0 /* r4 */, s32 a1);
void MI_Gene2_ItemStr(void);
void MI_Gene2_KeyType(void);
void MI_Gene2_LangType(void);
void MI_Gene2_Load(void);
void MI_Gene2_MapTex(void);
void MI_Gene2_Memoca(void);
void MI_Gene2_MsgDlg(void);
void MI_Gene2_Num(void);
void MI_Gene2_SL_Scrl(void);
u8 MI_Gene2_Setting(void);
void MI_Gene2_SldBar(void);
void MI_Gene2_Stereo(void);
void MI_Gene2_Stick(void);
void MI_Gene2_Test(void);
void MI_Gene2_Top(void);
void MI_Gene2_Vib(void);
void MI_Get_Arrow(u32 *a0, s32 a1);
void MI_Get_BtnGuide(void);
void MI_Get_CngStr(void);
void MI_Get_CngTex(void);
void MI_Get_Ctrler(void *a0 /* r4 */, signed int a1 /* r5 */);
void MI_Get_Dmy(void);
void MI_Get_Equip(void);
void MI_Get_GoTtl(void);
void MI_Get_HelpStr(void);
void MI_Get_ItemScrl(void);
void MI_Get_ItemStr(void);
void MI_Get_KeyType(void);
void MI_Get_LangType(void);
extern void MI_Get_Load(void *, signed int);
void MI_Get_MapTex(void);
extern void MI_Get_Memoca(void *, signed int);
void MI_Get_MsgDlg(void);
void MI_Get_Num(void);
void MI_Get_SL_Scrl(void);
u8 MI_Get_Setting(void);
void MI_Get_SldBar(void);
void MI_Get_Stereo(void);
void MI_Get_Stick(void *a0 /* r4 */);
void MI_Get_Test(void);
void MI_Get_Top(void);
void MI_Get_Vib(void);
void MI_Init_Arrow(void);
void MI_Init_BtnGuide(void);
void MI_Init_CngStr(void);
void MI_Init_CngTex(void);
void MI_Init_Ctrler(void);
void MI_Init_Dmy(void);
void MI_Init_Equip(void);
void MI_Init_GoTtl(void);
void MI_Init_HelpStr(void);
void MI_Init_ItemScrl(void);
void MI_Init_ItemStr(void);
void MI_Init_KeyType(void);
void MI_Init_LangType(void);
void MI_Init_Load(void);
void MI_Init_MapTex(void);
void MI_Init_Memoca(void);
void MI_Init_MsgDlg(void);
void MI_Init_Num(void);
void MI_Init_SL_Scrl(void);
void MI_Init_Setting(void);
void MI_Init_SldBar(void);
void MI_Init_Stereo(void);
void MI_Init_Stick(void);
void MI_Init_Test(void);
void MI_Init_Top(void);
void MI_Init_Vib(void);
void MI_Set_Arrow(void);
void MI_Set_BtnGuide(void);
void MI_Set_CngStr(void);
void MI_Set_CngTex(void);
void MI_Set_Ctrler(void);
void MI_Set_Dmy(void);
void MI_Set_Equip(void);
void MI_Set_GoTtl(void);
void MI_Set_HelpStr(void);
void MI_Set_ItemScrl(void);
void MI_Set_ItemStr(void);
void MI_Set_KeyType(void);
void MI_Set_LangType(void);
void MI_Set_Load(void);
void MI_Set_MapTex(void);
void MI_Set_Memoca(void);
void MI_Set_MsgDlg(void);
void MI_Set_Num(void);
void MI_Set_SL_Scrl(void);
void MI_Set_Setting(void);
void MI_Set_SldBar(void);
void MI_Set_Stereo(void);
void MI_Set_Stick(void);
void MI_Set_Test(void);
void MI_Set_Top(void);
void MI_Set_Vib(void);
extern signed int GetKeyState(int);
extern void MemFree(void *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);
extern void FreeTexList(void *);
extern u32 s_MenuFileBuf[];
extern unsigned int GetBindOffsetByName(void *, char *);
extern void RemapMdlLink(void *);
extern void SetTexList(void *, unsigned int);
extern u8 s_FileType[];
extern u32 s_MenuFileList[];
extern int strcmp();
extern u32 g_MapFuncTable[];
extern signed int Menu_ReLoadFile_MapIconData(signed int);
extern u8 s_tex_id_table[];
extern u32 s_MapData[];
extern unsigned short ItemMng_GetItemNum_Direct(unsigned short);
extern u8 s_MapTex_SorL;
extern signed int KnMenuMng_CheckCtrlPlay(int, signed int);
extern signed int KnMenuMng_GetCursorId(int, signed int);
static signed int Menu_ScrlCheck_down(signed int);
extern unsigned short * KnMsgMng_GetMsgStr(signed int);
extern u32 aTmpStr_Page[];
extern u8 s_go_ttl_state;
extern unsigned short GetVagMasterVolume(unsigned char);
extern u32 SND_GetVol(s32);
extern u8 GameSt[];
extern u32 g_pSndMng;
extern void SetVagMasterVolume(unsigned char, unsigned int);
extern void SND_SqSetVolume(signed int);
extern void SND_SetVol(int, unsigned char);
extern void KnMenuWindMng_SetTopWindRate(void);
extern signed int Menu_CheckSetMemocaState(void);
extern u8 s_memoca_real_time_check_state;
extern signed int GetMemoryCardMessage(unsigned char);
extern u32 ExistKuonData();
extern signed int GetNeedCluster(signed int);
extern u8 MemocaMng[];
extern void *memset(void *, int, unsigned int);
extern unsigned short ItemMng_GetItemMaxNum(unsigned short);
extern signed int ItemMng_GetItemBySequence(unsigned short, unsigned short);
extern unsigned short ItemMng_GetItemNum(unsigned short, unsigned short);
extern void GetMyEquipInfo(void *, signed int, signed int *, signed int *, signed int *);
extern unsigned char GetMyWeaponId(void *);
extern u32 MdlMng[];
extern void * ItemMng_GetItemTex(unsigned short, unsigned short);
extern void SetKeyConfig(unsigned char);
extern void KnMenuModelMng_ResetCtrlerAnim(void);
extern void SetPadVibFlag(unsigned char);
extern void SND_SetMode(int);
extern int KnMenuModelMng_GetCtrlerState(void);
s32 Menu_GetMenuBreakKeyType(void);
void Menu_SetMenuBreakKeyType(u8 type);
signed int Menu_SND_Play2D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6
        */);
s32 Menu_GetNoSndOff(void);
void Menu_SetNoSndOff(s32 on);
void Menu_UtilUpdate(void);
void Menu_SetDialogMsg(int id, unsigned char *pMsgStr, signed int arg, int type);
void Menu_DialogUpdate(void);
signed int MenuReLoadFile(int _type);
s16 Menu_GetLastReloadType(void);
u32 Menu_FileReadCallBack(u16 a0 /* r4 */);
signed int MenuReadFile(unsigned char **a0 /* r4 */, char *a1 /* r5 */);
void SetCtrlFuncCtrlId(s32 ctrl_id);
void SetCtrlFuncMenuId(s32 menu_id);
void Menu_CallMenu(s32 menu_id, s32 ctrl_id);
signed int GetMenuFuncId(unsigned char *a0 /* r4 */);
void Menu_MapTexFree(void);
u8 * Menu_GetMapData(void);
u32 Menu_GetTexInfo(s32 a0 /* r4 */);
u32 Menu_GetTexId_now(void);
signed int Menu_CheckVisitMap(signed int a0 /* r4 */);
s8 Menu_GetMapTexSorL(void);
void MI_Get_Arrow(u32 *a0 /* r4 */, s32 a1 /* r5 */);
void MI_Check_GoTtl(void *pVariable);
u8 Menu_SettingStore(void);
signed int Menu_CallMemocaStateDialog(void);
u8 * Menu_ClearMemocaMng(void);
void Menu_SetUnSaved(void);
u32 Menu_IsSaved(void);
void Menu_SetUnLoaded(void);
u32 Menu_IsLoaded(void);
void Menu_SetLoadSlotOffsetReset(void);
void Menu_SetEndSave(signed int a0 /* r4 */);
u32 Menu_GetNowDocId(void);
u32 Menu_GetGetItemId(void);
void Menu_SetGetItemId(signed int a0 /* r4 */);
void Menu_SetGetItemNum(signed int a0 /* r4 */);
signed int GetEquipNum(int a0 /* r4 */);
void * GetEquipTexMng(u8 a0 /* r4 */);



static u8 s_tex_id_table[0x3f0] = {
    0, 0, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xf4, 1, 0, 0, 0xc8, 0, 0, 0, 0xff, 0xff, 0xff, 0xff, 0,
    0, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xe2, 0xff, 0xff, 0xff, 0xd9, 0xff, 0xff, 0xff, 0xff, 0, 0,
    0, 0xb3, 2, 0, 0, 0x46, 0, 0, 0, 6, 0, 0, 0, 0x1b, 3, 0, 0, 0x5f, 1, 0, 0, 0x91, 0x87, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x65, 0x6e, 0x75, 0x2f, 0x74, 0x65, 0x78, 0x2f, 0x6d, 0x61,
    0x70, 0x2f, 0x6d, 0x61, 0x70, 0x30, 0x30, 0x5f, 0x30, 0x30, 0x2e, 0x74, 0x65, 0x78, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0x6d, 0x61, 0x70, 0x30, 0x30, 0x5f, 0x30, 0x30, 0x2e, 0x74, 0x33, 0x32, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xc8, 0, 0, 0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xbc, 2, 0, 0, 0, 0, 0, 0, 0xc8, 0, 0, 0, 0xff, 0xff, 0xff, 0xff,
    0x7c, 0xff, 0xff, 0xff, 0xe6, 0xff, 0xff, 0xff, 0x21, 1, 0, 0, 0x71, 3, 0, 0, 0xcd, 0xff,
    0xff, 0xff, 0x14, 0, 0, 0, 0x8b, 3, 0, 0, 0x78, 1, 0, 0, 0x93, 0x87, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0x6d, 0x65, 0x6e, 0x75, 0x2f, 0x74, 0x65, 0x78, 0x2f, 0x6d, 0x61, 0x70, 0x2f, 0x6d,
    0x61, 0x70, 0x32, 0x30, 0x5f, 0x30, 0x30, 0x2e, 0x74, 0x65, 0x78, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x6d, 0x61, 0x70, 0x32, 0x30, 0x5f, 0x30, 0x30, 0x2e, 0x74, 0x33, 0x32, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xf4, 1, 0, 0, 0, 0, 0, 0, 0xff, 0xff, 0xff, 0xff,
    0x20, 3, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xf4, 1, 0, 0, 0xf5, 1, 0, 0, 0xe1, 0xff, 0xff, 0xff,
    0xca, 0xff, 0xff, 0xff, 0x7c, 1, 0, 0, 0xe2, 1, 0, 0, 0x15, 0, 0, 0, 0xf2, 0xff, 0xff, 0xff,
    0x6e, 2, 0, 0, 0xcd, 0, 0, 0, 0x92, 0x87, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x65, 0x6e,
    0x75, 0x2f, 0x74, 0x65, 0x78, 0x2f, 0x6d, 0x61, 0x70, 0x2f, 0x6d, 0x61, 0x70, 0x35, 0x30,
    0x5f, 0x30, 0x30, 0x2e, 0x74, 0x65, 0x78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x61, 0x70, 0x35,
    0x30, 0x5f, 0x30, 0x30, 0x2e, 0x74, 0x33, 0x32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0xf5, 1, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 1, 0, 0, 0x2a, 0xff, 0xff,
    0xff, 0xfc, 0xfe, 0xff, 0xff, 0x55, 1, 0, 0, 0x7e, 2, 0, 0, 0x5c, 0xff, 0xff, 0xff, 0x18,
    0xff, 0xff, 0xff, 0xf7, 2, 0, 0, 0x37, 1, 0, 0, 0x92, 0x87, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x6d, 0x65, 0x6e, 0x75, 0x2f, 0x74, 0x65, 0x78, 0x2f, 0x6d, 0x61, 0x70, 0x2f, 0x6d, 0x61,
    0x70, 0x35, 0x30, 0x5f, 0x30, 0x31, 0x2e, 0x74, 0x65, 0x78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d,
    0x61, 0x70, 0x35, 0x30, 0x5f, 0x30, 0x31, 0x2e, 0x74, 0x33, 0x32, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xbc, 2, 0, 0, 0xff, 0xff, 0xff, 0xff, 0x20, 3, 0, 0, 0xff,
    0xff, 0xff, 0xff, 0xc8, 0, 0, 0, 0xbc, 2, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xff, 0xff,
    0xff, 0xea, 0xff, 0xff, 0xff, 0xcc, 1, 0, 0, 0x63, 2, 0, 0, 0x24, 0, 0, 0, 6, 0, 0, 0, 0xd5,
    2, 0, 0, 0x8d, 1, 0, 0, 0x94, 0x87, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x65, 0x6e, 0x75,
    0x2f, 0x74, 0x65, 0x78, 0x2f, 0x6d, 0x61, 0x70, 0x2f, 0x6d, 0x61, 0x70, 0x37, 0x30, 0x5f,
    0x30, 0x30, 0x2e, 0x74, 0x65, 0x78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x61, 0x70, 0x37, 0x30,
    0x5f, 0x30, 0x30, 0x2e, 0x74, 0x33, 0x32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0x20, 3, 0, 0, 0xbc, 2, 0, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4,
    1, 0, 0, 0x20, 3, 0, 0, 0xff, 0xff, 0xff, 0xff, 1, 0xff, 0xff, 0xff, 2, 0xff, 0xff, 0xff,
    0x3c, 1, 0, 0, 0x32, 3, 0, 0, 0x33, 0xff, 0xff, 0xff, 0x56, 0xff, 0xff, 0xff, 0x4f, 2, 0, 0,
    0xaa, 0, 0, 0, 0x95, 0x87, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x65, 0x6e, 0x75, 0x2f, 0x74,
    0x65, 0x78, 0x2f, 0x6d, 0x61, 0x70, 0x2f, 0x6d, 0x61, 0x70, 0x38, 0x30, 0x5f, 0x30, 0x30,
    0x2e, 0x74, 0x65, 0x78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x6d, 0x61, 0x70, 0x38, 0x30, 0x5f, 0x30,
    0x30, 0x2e, 0x74, 0x33, 0x32
};




































































































































































































































































u32 g_MapFuncTable[0x384] = {
    0x796d44, 0, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Dmy, (u32)&MI_Set_Dmy, (u32)&MI_Decide_Dmy,
    (u32)&MI_CntUp_Dmy, (u32)&MI_CntDown_Dmy, (u32)&MI_Gene1_Dmy, (u32)&MI_Gene2_Dmy,
    (u32)&MI_Evrfrm_Dmy, (u32)&MI_Init_Dmy, (u32)&MI_Check_Dmy, 0x5f30304d, 0x303043, 0, 0, 0,
    0, 0, 0, (u32)&MI_Get_Test, (u32)&MI_Set_Test, (u32)&MI_Decide_Test, (u32)&MI_CntUp_Test,
    (u32)&MI_CntDown_Test, (u32)&MI_Gene1_Test, (u32)&MI_Gene2_Test, (u32)&MI_Evrfrm_Test,
    (u32)&MI_Init_Test, (u32)&MI_Check_Test, 0x31796d44, 0, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Dmy,
    (u32)&MI_Set_Dmy, (u32)&MI_Decide_Dmy, (u32)&MI_CntUp_Dmy, (u32)&MI_CntDown_Dmy,
    (u32)&MI_Gene1_Dmy, (u32)&MI_Gene2_Dmy, (u32)&MI_Evrfrm_Dmy, (u32)&MI_Init_Dmy,
    (u32)&MI_Check_Dmy, 0x74546f47, 0x6c, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_GoTtl,
    (u32)&MI_Set_GoTtl, (u32)&MI_Decide_GoTtl, (u32)&MI_CntUp_GoTtl, (u32)&MI_CntDown_GoTtl,
    (u32)&MI_Gene1_GoTtl, (u32)&MI_Gene2_GoTtl, (u32)&MI_Evrfrm_GoTtl, (u32)&MI_Init_GoTtl,
    (u32)&MI_Check_GoTtl, 0x74746553, 0x676e69, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Setting,
    (u32)&MI_Set_Setting, (u32)&MI_Decide_Setting, (u32)&MI_CntUp_Setting,
    (u32)&MI_CntDown_Setting, (u32)&MI_Gene1_Setting, (u32)&MI_Gene2_Setting,
    (u32)&MI_Evrfrm_Setting, (u32)&MI_Init_Setting, (u32)&MI_Check_Setting, 0x6f727241, 0x77, 0,
    0, 0, 0, 0, 0, (u32)&MI_Get_Arrow, (u32)&MI_Set_Arrow, (u32)&MI_Decide_Arrow,
    (u32)&MI_CntUp_Arrow, (u32)&MI_CntDown_Arrow, (u32)&MI_Gene1_Arrow, (u32)&MI_Gene2_Arrow,
    (u32)&MI_Evrfrm_Arrow, (u32)&MI_Init_Arrow, (u32)&MI_Check_Arrow, 0x6c727443, 0x7265, 0, 0,
    0, 0, 0, 0, (u32)&MI_Get_Ctrler, (u32)&MI_Set_Ctrler, (u32)&MI_Decide_Ctrler,
    (u32)&MI_CntUp_Ctrler, (u32)&MI_CntDown_Ctrler, (u32)&MI_Gene1_Ctrler,
    (u32)&MI_Gene2_Ctrler, (u32)&MI_Evrfrm_Ctrler, (u32)&MI_Init_Ctrler, (u32)&MI_Check_Ctrler,
    0x64616f4c, 0, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Load, (u32)&MI_Set_Load, (u32)&MI_Decide_Load,
    (u32)&MI_CntUp_Load, (u32)&MI_CntDown_Load, (u32)&MI_Gene1_Load, (u32)&MI_Gene2_Load,
    (u32)&MI_Evrfrm_Load, (u32)&MI_Init_Load, (u32)&MI_Check_Load, 0x6f6d654d, 0x6163, 0, 0, 0,
    0, 0, 0, (u32)&MI_Get_Memoca, (u32)&MI_Set_Memoca, (u32)&MI_Decide_Memoca,
    (u32)&MI_CntUp_Memoca, (u32)&MI_CntDown_Memoca, (u32)&MI_Gene1_Memoca,
    (u32)&MI_Gene2_Memoca, (u32)&MI_Evrfrm_Memoca, (u32)&MI_Init_Memoca, (u32)&MI_Check_Memoca,
    0x6d657449, 0x727453, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_ItemStr, (u32)&MI_Set_ItemStr,
    (u32)&MI_Decide_ItemStr, (u32)&MI_CntUp_ItemStr, (u32)&MI_CntDown_ItemStr,
    (u32)&MI_Gene1_ItemStr, (u32)&MI_Gene2_ItemStr, (u32)&MI_Evrfrm_ItemStr,
    (u32)&MI_Init_ItemStr, (u32)&MI_Check_ItemStr, 0x6d754e, 0, 0, 0, 0, 0, 0, 0,
    (u32)&MI_Get_Num, (u32)&MI_Set_Num, (u32)&MI_Decide_Num, (u32)&MI_CntUp_Num,
    (u32)&MI_CntDown_Num, (u32)&MI_Gene1_Num, (u32)&MI_Gene2_Num, (u32)&MI_Evrfrm_Num,
    (u32)&MI_Init_Num, (u32)&MI_Check_Num, 0x69757145, 0x70, 0, 0, 0, 0, 0, 0,
    (u32)&MI_Get_Equip, (u32)&MI_Set_Equip, (u32)&MI_Decide_Equip, (u32)&MI_CntUp_Equip,
    (u32)&MI_CntDown_Equip, (u32)&MI_Gene1_Equip, (u32)&MI_Gene2_Equip, (u32)&MI_Evrfrm_Equip,
    (u32)&MI_Init_Equip, (u32)&MI_Check_Equip, 0x6d657449, 0x6c726353, 0, 0, 0, 0, 0, 0,
    (u32)&MI_Get_ItemScrl, (u32)&MI_Set_ItemScrl, (u32)&MI_Decide_ItemScrl,
    (u32)&MI_CntUp_ItemScrl, (u32)&MI_CntDown_ItemScrl, (u32)&MI_Gene1_ItemScrl,
    (u32)&MI_Gene2_ItemScrl, (u32)&MI_Evrfrm_ItemScrl, (u32)&MI_Init_ItemScrl,
    (u32)&MI_Check_ItemScrl, 0x6e616843, 0x65546567, 0x78, 0, 0, 0, 0, 0, (u32)&MI_Get_CngTex,
    (u32)&MI_Set_CngTex, (u32)&MI_Decide_CngTex, (u32)&MI_CntUp_CngTex, (u32)&MI_CntDown_CngTex,
    (u32)&MI_Gene1_CngTex, (u32)&MI_Gene2_CngTex, (u32)&MI_Evrfrm_CngTex, (u32)&MI_Init_CngTex,
    (u32)&MI_Check_CngTex, 0x64696c53, 0x72614265, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_SldBar,
    (u32)&MI_Set_SldBar, (u32)&MI_Decide_SldBar, (u32)&MI_CntUp_SldBar, (u32)&MI_CntDown_SldBar,
    (u32)&MI_Gene1_SldBar, (u32)&MI_Gene2_SldBar, (u32)&MI_Evrfrm_SldBar, (u32)&MI_Init_SldBar,
    (u32)&MI_Check_SldBar, 0x535f4c53, 0x6c7263, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_SL_Scrl,
    (u32)&MI_Set_SL_Scrl, (u32)&MI_Decide_SL_Scrl, (u32)&MI_CntUp_SL_Scrl,
    (u32)&MI_CntDown_SL_Scrl, (u32)&MI_Gene1_SL_Scrl, (u32)&MI_Gene2_SL_Scrl,
    (u32)&MI_Evrfrm_SL_Scrl, (u32)&MI_Init_SL_Scrl, (u32)&MI_Check_SL_Scrl, 0x5479654b,
    0x657079, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_KeyType, (u32)&MI_Set_KeyType,
    (u32)&MI_Decide_KeyType, (u32)&MI_CntUp_KeyType, (u32)&MI_CntDown_KeyType,
    (u32)&MI_Gene1_KeyType, (u32)&MI_Gene2_KeyType, (u32)&MI_Evrfrm_KeyType,
    (u32)&MI_Init_KeyType, (u32)&MI_Check_KeyType, 0x676e614c, 0x65707954, 0, 0, 0, 0, 0, 0,
    (u32)&MI_Get_LangType, (u32)&MI_Set_LangType, (u32)&MI_Decide_LangType,
    (u32)&MI_CntUp_LangType, (u32)&MI_CntDown_LangType, (u32)&MI_Gene1_LangType,
    (u32)&MI_Gene2_LangType, (u32)&MI_Evrfrm_LangType, (u32)&MI_Init_LangType,
    (u32)&MI_Check_LangType, 0x626956, 0, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Vib, (u32)&MI_Set_Vib,
    (u32)&MI_Decide_Vib, (u32)&MI_CntUp_Vib, (u32)&MI_CntDown_Vib, (u32)&MI_Gene1_Vib,
    (u32)&MI_Gene2_Vib, (u32)&MI_Evrfrm_Vib, (u32)&MI_Init_Vib, (u32)&MI_Check_Vib, 0x72657453,
    0x6f65, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Stereo, (u32)&MI_Set_Stereo, (u32)&MI_Decide_Stereo,
    (u32)&MI_CntUp_Stereo, (u32)&MI_CntDown_Stereo, (u32)&MI_Gene1_Stereo,
    (u32)&MI_Gene2_Stereo, (u32)&MI_Evrfrm_Stereo, (u32)&MI_Init_Stereo, (u32)&MI_Check_Stereo,
    0x706c6548, 0x727453, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_HelpStr, (u32)&MI_Set_HelpStr,
    (u32)&MI_Decide_HelpStr, (u32)&MI_CntUp_HelpStr, (u32)&MI_CntDown_HelpStr,
    (u32)&MI_Gene1_HelpStr, (u32)&MI_Gene2_HelpStr, (u32)&MI_Evrfrm_HelpStr,
    (u32)&MI_Init_HelpStr, (u32)&MI_Check_HelpStr, 0x6e616843, 0x74536567, 0x72, 0, 0, 0, 0, 0,
    (u32)&MI_Get_CngStr, (u32)&MI_Set_CngStr, (u32)&MI_Decide_CngStr, (u32)&MI_CntUp_CngStr,
    (u32)&MI_CntDown_CngStr, (u32)&MI_Gene1_CngStr, (u32)&MI_Gene2_CngStr,
    (u32)&MI_Evrfrm_CngStr, (u32)&MI_Init_CngStr, (u32)&MI_Check_CngStr, 0x63697453, 0x6b, 0, 0,
    0, 0, 0, 0, (u32)&MI_Get_Stick, (u32)&MI_Set_Stick, (u32)&MI_Decide_Stick,
    (u32)&MI_CntUp_Stick, (u32)&MI_CntDown_Stick, (u32)&MI_Gene1_Stick, (u32)&MI_Gene2_Stick,
    (u32)&MI_Evrfrm_Stick, (u32)&MI_Init_Stick, (u32)&MI_Check_Stick, 0x5470614d, 0x7865, 0, 0,
    0, 0, 0, 0, (u32)&MI_Get_MapTex, (u32)&MI_Set_MapTex, (u32)&MI_Decide_MapTex,
    (u32)&MI_CntUp_MapTex, (u32)&MI_CntDown_MapTex, (u32)&MI_Gene1_MapTex,
    (u32)&MI_Gene2_MapTex, (u32)&MI_Evrfrm_MapTex, (u32)&MI_Init_MapTex, (u32)&MI_Check_MapTex,
    0x4467734d, 0x676c, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_MsgDlg, (u32)&MI_Set_MsgDlg,
    (u32)&MI_Decide_MsgDlg, (u32)&MI_CntUp_MsgDlg, (u32)&MI_CntDown_MsgDlg,
    (u32)&MI_Gene1_MsgDlg, (u32)&MI_Gene2_MsgDlg, (u32)&MI_Evrfrm_MsgDlg, (u32)&MI_Init_MsgDlg,
    (u32)&MI_Check_MsgDlg, 0x706f54, 0, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_Top, (u32)&MI_Set_Top,
    (u32)&MI_Decide_Top, (u32)&MI_CntUp_Top, (u32)&MI_CntDown_Top, (u32)&MI_Gene1_Top,
    (u32)&MI_Gene2_Top, (u32)&MI_Evrfrm_Top, (u32)&MI_Init_Top, (u32)&MI_Check_Top, 0x476e7442,
    0x65646975, 0, 0, 0, 0, 0, 0, (u32)&MI_Get_BtnGuide, (u32)&MI_Set_BtnGuide,
    (u32)&MI_Decide_BtnGuide, (u32)&MI_CntUp_BtnGuide, (u32)&MI_CntDown_BtnGuide,
    (u32)&MI_Gene1_BtnGuide, (u32)&MI_Gene2_BtnGuide, (u32)&MI_Evrfrm_BtnGuide,
    (u32)&MI_Init_BtnGuide, (u32)&MI_Check_BtnGuide, 0x74736574, 0, 0, 0, 0, 0, 0, 0,
    (u32)&MI_Get_Test, (u32)&MI_Set_Test, (u32)&MI_Decide_Test, (u32)&MI_CntUp_Test,
    (u32)&MI_CntDown_Test, (u32)&MI_Gene1_Test, (u32)&MI_Gene2_Test, (u32)&MI_Evrfrm_Test,
    (u32)&MI_Init_Test, (u32)&MI_Check_Test
};
static u32 s_MenuFileList[0x28] = {
    (u32)"mm00.tex", (u32)"mm01.tex", (u32)"mm02.tex", (u32)"mm03.tex", (u32)"mm04.tex",
    (u32)"mm05.tex", (u32)"mm06.tex", (u32)"mm07.tex", (u32)"ctrl0300.mnc", (u32)"ctrl0301.mnc",
    (u32)"ctrl0302.mnc", (u32)"ctrl0303.mnc", (u32)"ctrl0304.mnc", (u32)"ctrl0305.mnc",
    (u32)"ctrl0306.mnc", (u32)"ctrl0307.mnc", (u32)"ctrl0308.mnc", (u32)"ctrl0309.mnc",
    (u32)"ctrl0310.mnc", (u32)"ctrl0311.mnc", (u32)"ctrl0312.mnc", (u32)"menu0003.mnm",
    (u32)"ctrl0401.mnc", (u32)"ctrl0400.mnc", (u32)"menu0004.mnm", (u32)"ctrl0501.mnc",
    (u32)"ctrl0500.mnc", (u32)"menu0005.mnm", (u32)"ctrl0600.mnc", (u32)"menu0006.mnm",
    (u32)"ctrl0700.mnc", (u32)"ctrl0701.mnc", (u32)"menu0007.mnm", (u32)"ctrl0800.mnc",
    (u32)"menu0008.mnm", (u32)"ctrl0900.mnc", (u32)"ctrl0901.mnc", (u32)"menu0009.mnm",
    (u32)"ctrl1000.mnc", (u32)"menu0010.mnm"
};
static u8 s_FileType[0x28] = {
    0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3
};

static inline s32 MI_Decide_Top__lenu16(u16 *s) {
    s32 n = 0;
    while (s[n] != 0) {
        n++;
    }
    return n;
}


typedef struct {
    u32 bit0 : 1;
    u32 rest : 31;
} MICheckBits;

#define MI_CHECK_EMPTY(kind)                                                                 \
    {                                                                                        \
        s32 i;                                                                               \
        u16 max;                                                                             \
        s32 found;                                                                           \
        max = ItemMng_GetItemMaxNum(kind);                                                   \
        found = 0;                                                                           \
        for (i = 0; i < max; i++) {                                                          \
            if ((u16)ItemMng_GetItemNum(kind, (u16)(ItemMng_GetItemBySequence(kind, i) % 1000)) > 0) { \
                found = 1;                                                                   \
            }                                                                                \
        }                                                                                    \
        if (found) {                                                                         \
            break;                                                                           \
        }                                                                                    \
    }


typedef union { u8 all; struct { u8 b0:1; u8 b1:7; } bit; } MIVARX;



/* GetItemData @ 0x1E8DA0 .. 0x1E9610 (0x870 bytes, frame 0x70) */
extern char * ItemMng_GetItemName_Direct(unsigned short);
extern signed int ItemMng_CheckGetExperience(unsigned short);
extern char * ItemMng_GetItemNote_Direct(unsigned short);
extern void * ItemMng_GetItemTex_Direct(unsigned short);
extern void * GetTexMngByBaseName(void *, char *);
extern signed int ItemMng_GetReadMark(unsigned short);
extern char * ItemMng_GetDocument(unsigned short, unsigned short);
extern void ItemMng_SetReadMark(unsigned short, signed int);
extern unsigned short ItemMng_GetDocumentPageNum(unsigned short);
extern u8 aTmpItemName[];
extern u8 aTmpItemNote[];
extern u8 aTmpItemDoc[];

typedef struct { u_long128 q; } GetItemDataRet;


/* MI_Evrfrm_CngTex @ 0x1E89D0 .. 0x1E8CA8 (0x2d8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @13882 -> 0x256c40
 *   literal: @13879 is the string 'fe_me_0015.t32'
 *   literal: @13880 is the string 'fe_me_0014.t32'
 *   literal: @13881 is the string 'fe_me_0016.t32'
 *   indirect: jr v1 at 0x1e8a00 -> <v1>
 *   stack: address of the slot at 0x20 escapes at 0x1e8acc
 *   stack: address of the slot at 0x20 escapes at 0x1e8b24
 *   stack: address of the slot at 0x20 escapes at 0x1e8c78
 *   cfg: kept branch: 0x1e8b88 if (..) goto .L001E8C28
 *   cfg: kept branch: 0x1e8b94 if (..) goto .L001E8BB8
 *   cfg: kept branch: 0x1e8ba4 if (..) goto .L001E8C28
 *   cfg: kept branch: 0x1e8bb8 if (..) goto .L001E8C20
 *   cfg: kept goto: 0x1e8c08 -> .L001E8C28
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * GetTexMngByBaseName(void *, char *);
static GetItemDataRet GetItemData(int, int);
extern signed int Menu_GetItemBufOn(void);
extern signed int Menu_ItemDataRingBuf(void);
extern void * ItemMng_GetItemTex_Direct(unsigned short);
extern u32 L13882[];






typedef struct IconChangeFlags {u8 a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;} IconChangeFlags;


/* Code-exact; blocked by @6503 ownership: target relocations resolve to .rodata+0x358, while this candidate's literal resolves to @5091+0. */
extern u8 aTmpItemName[];
extern u8 aTmpItemName_Left[];












/* MI_Decide_ItemScrl @ 0x1E7A80 .. 0x1E8370 (0x8f0 bytes, frame 0x1fe0) */
/*
 * dcomp notes:
 *   literal: @13604 -> 0x256b00
 *   indirect: jr v1 at 0x1e7ab0 -> <v1>
 *   stack: address of the slot at 0x1bb0 escapes at 0x1e7b68
 *   stack: address of the slot at 0x1bb0 escapes at 0x1e7b7c
 *   stack: address of the slot at 0x1fa0 escapes at 0x1e7bc8
 *   stack: address of the slot at 0x17c0 escapes at 0x1e7c68
 *   stack: address of the slot at 0x17c0 escapes at 0x1e7c7c
 *   delay: lui at 0x1e7d38 writes a register its branch at 0x1e7d34 reads
 *   stack: address of the slot at 0x13d0 escapes at 0x1e7da0
 *   stack: address of the slot at 0x13d0 escapes at 0x1e7db4
 *   stack: address of the slot at 0xfe0 escapes at 0x1e7f20
 *   stack: address of the slot at 0xfe0 escapes at 0x1e7f34
 *   stack: address of the slot at 0x1fc0 escapes at 0x1e7f84
 *   stack: address of the slot at 0xbf0 escapes at 0x1e8008
 *   stack: address of the slot at 0xbf0 escapes at 0x1e801c
 *   delay: lui at 0x1e80e4 writes a register its branch at 0x1e80e0 reads
 *   stack: address of the slot at 0x800 escapes at 0x1e8150
 *   stack: address of the slot at 0x800 escapes at 0x1e8164
 *   stack: address of the slot at 0x410 escapes at 0x1e81e8
 *   stack: address of the slot at 0x410 escapes at 0x1e81fc
 *   stack: address of the slot at 0x1fb0 escapes at 0x1e825c
 *   stack: address of the slot at 0x20 escapes at 0x1e82e0
 *   stack: address of the slot at 0x20 escapes at 0x1e82f4
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x1e7be0
 *   cfg: kept branch: 0x1e7e38 if (..) goto .L001E7E78
 *   cfg: kept goto: 0x1e8094 -> .L001E8220
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u_long128; 1 parameters vs 2
 *   inferred
 */

extern unsigned int SetMyEquip(void *, signed int, signed int, signed int, signed int);
extern void ChangeMyEquipSound();
extern unsigned int CheckMyEquipLoad(void *, signed int);
extern void SetMyWeaponId(void *, unsigned char);
extern signed int ItemMng_ConsumeItem(unsigned short);
extern u32 L13604[];

struct dw_2278209_fields;
struct dw_2282036_fields;
#ifndef PROTO_DW_2300685_FIELDS
#define PROTO_DW_2300685_FIELDS
struct dw_2300685_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_2296670_FIELDS
#define PROTO_DW_2296670_FIELDS
struct dw_2296670_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_2296347_FIELDS
#define PROTO_DW_2296347_FIELDS
struct dw_2296347_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_2282036_fields *lpMdl; };
#endif
#ifndef PROTO_DW_2282036_FIELDS
#define PROTO_DW_2282036_FIELDS
struct dw_2282036_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_2278209_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_2282036_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_2300685_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_2296670_fields flags; unsigned char _pad1[3]; struct dw_2296347_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_2299119_FIELDS
#define PROTO_DW_2299119_FIELDS
struct dw_2299119_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2282036_FIELDS_LPCTRLST_E6456178_DEFINED
#define DCOMP_OFF_STRUCT_DW_2282036_FIELDS_LPCTRLST_E6456178_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2282036_FIELDS_LPCTRLST_E6456178 = (int)&(((struct dw_2282036_fields *)0)->lpCtrlSt) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5_DEFINED
#define DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5 = (int)&(((struct dw_2299119_fields *)0)->PlayerId) - 0 };
#endif

static inline s32 MI_Decide_ItemScrl__len(u16 *s) {
    s32 n = 0;
    while (s[n] != 0) {
        n++;
    }
    return n;
}







#define MCN_ADDI21(x) ({ s32 r_; __asm__("addi %0,%1,-21" : "=r"(r_) : "r"(x)); r_; })
#define MCN_ADDI26(x) ({ s32 r_; __asm__("addi %0,%1,-26" : "=r"(r_) : "r"(x)); r_; })
#define MCN_ADDI41(x) ({ s32 r_; __asm__("addi %0,%1,-41" : "=r"(r_) : "r"(x)); r_; })

static inline s32 MCN_Find(s32 id, s32 cur, s32 off) {
    s32 n;
    for (n = cur + off; ; n--) {
        if (cur >= n) {
            return cur;
        }
        if (Menu_CheckItemOnCursor(id, n)) {
            return n;
        }
    }
}
#define MCN_D4() \
    { \
        next = MCN_Find(id, cur, 1); \
        if (next == cur) { \
            next = 0x19; \
        } \
    }
#define MCN_D4N() \
    { \
        next = MCN_Find(id, cur, 1); \
    }
#define MCN_U(K) \
    { \
        cur = MCN_Find(id, cur, K); \
        next = cur; \
    }
#define MCN_N(K) \
    { \
        next = MCN_Find(id, cur, K); \
    }
#define MCN_ADJ(LIM, ADD, K) \
    if (next > (LIM) && cur + (K) > next) { \
        next += (ADD); \
    }


/* MI_CntUp_ItemScrl @ 0x1E7040 .. 0x1E7138 (0xf8 bytes) */
/*
 * dcomp notes:
 *   literal: @12713 -> 0x2566b0
 *   indirect: jr v1 at 0x1e7064 -> <v1>
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

extern u32 L12713[];



/* MI_Gene1_ItemScrl @ 0x1E6CF0 .. 0x1E6F98 (0x2a8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @12646 -> 0x2565a0
 *   indirect: jr v1 at 0x1e6d3c -> <v1>
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

static signed int Menu_CheckItemOnCursor(signed int, signed int);
extern void KnMenuMng_SetForceChangeCursorId(int, signed int, signed int);
extern signed int Menu_CursorMoveNext(signed int, int);
extern u32 L12646[];



/* MI_Gene2_ItemScrl @ 0x1E6A10 .. 0x1E6CF0 (0x2e0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @12541 -> 0x2564c0
 *   indirect: jr v1 at 0x1e6a5c -> <v1>
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */



extern u32 L12541[];


/* MI_Decide_Equip @ 0x1E5F20 .. 0x1E6218 (0x2f8 bytes, frame 0x820) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e5f48 writes a register its branch at 0x1e5f44 reads
 *   stack: address of the slot at 0x430 escapes at 0x1e6048
 *   stack: address of the slot at 0x430 escapes at 0x1e605c
 *   stack: address of the slot at 0x40 escapes at 0x1e6198
 *   stack: address of the slot at 0x40 escapes at 0x1e61ac
 *   cfg: loop body is not one contiguous region: .L001E5F88
 *   cfg: loop body is not one contiguous region: .L001E60D8
 */


static inline s32 MI_Decide_Equip__lenu16(u16 *s) {
    s32 n = 0;
    while (s[n] != 0) {
        n++;
    }
    return n;
}



/* MI_CntUp_ItemStr @ 0x1E5620 .. 0x1E56FC (0xdc bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @11915 -> 0x256180
 *   indirect: jr v1 at 0x1e565c -> <v1>
 *   stack: address of the slot at 0x10 escapes at 0x1e566c
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

extern u32 L11915[];


/* MI_CntDown_ItemStr @ 0x1E5590 .. 0x1E561C (0x8c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @11885 -> 0x256160
 *   indirect: jr v1 at 0x1e55b4 -> <v1>
 *   stack: address of the slot at 0x10 escapes at 0x1e55c4
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */

extern u32 L11885[];



/* MI_Evrfrm_ItemStr @ 0x1E4A30 .. 0x1E556C (0xb3c bytes, frame 0x480) */
/*
 * dcomp notes:
 *   literal: @11874 -> 0x256130
 *   literal: @6503 is the string ''
 *   indirect: jr v1 at 0x1e4a74 -> <v1>
 *   stack: address of the slot at 0x460 escapes at 0x1e4d04
 *   stack: address of the slot at 0x47c escapes at 0x1e4d5c
 *   stack: address of the slot at 0x478 escapes at 0x1e4d5c
 *   stack: address of the slot at 0x474 escapes at 0x1e4d5c
 *   stack: address of the slot at 0x47c escapes at 0x1e4f50
 *   stack: address of the slot at 0x478 escapes at 0x1e4f50
 *   stack: address of the slot at 0x474 escapes at 0x1e4f50
 *   stack: address of the slot at 0x70 escapes at 0x1e546c
 *   stack: address of the slot at 0x70 escapes at 0x1e5480
 *   delay: addiu at 0x1e54d8 writes a register its branch at 0x1e54d4 reads
 *   quad: v1: 128-bit web split from its scalar variable as v1_q
 *   cfg: kept goto: 0x1e4bf8 -> .L001E5548
 *   cfg: kept goto: 0x1e4cc0 -> .L001E5548
 *   cfg: kept goto: 0x1e4cd0 -> .L001E5548
 *   declaration vs inferred signature: return void vs inferred u_long128
 */

extern char * ItemMng_GetItemName_Direct(unsigned short);
extern char * ItemMng_GetItemNote_Direct(unsigned short);
extern char * ItemMng_GetItemName(unsigned short, unsigned short);
extern char * ItemMng_GetItemNote(unsigned short, unsigned short);
extern u8 aTmpItemNote[];

#ifndef PROTO_DW_2299119_FIELDS
#define PROTO_DW_2299119_FIELDS
struct dw_2299119_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5_DEFINED
#define DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5 = (int)&(((struct dw_2299119_fields *)0)->PlayerId) - 0 };
#endif
static inline s32 MI_Evrfrm_ItemStr__lenu16(u16 *s) {
    s32 n = 0;
    while (s[n] != 0) {
        n++;
    }
    return n;
}



enum MCSEnum { MCS_A = 0, MCS_B = 1 };



/* MI_Get_Memoca @ 0x1E2C50 .. 0x1E4360 (0x1710 bytes, frame 0x2bb0) */
/*
 * dcomp notes:
 *   literal: @11317 -> 0x256100
 *   literal: @11318 -> 0x2560d0
 *   indirect: jr v0 at 0x1e2cfc -> <v0>
 *   stack: address of the slot at 0x27c0 escapes at 0x1e2dfc
 *   stack: address of the slot at 0x27c0 escapes at 0x1e2e10
 *   delay: addiu at 0x1e2e88 writes a register its branch at 0x1e2e84 reads
 *   delay: addiu at 0x1e2e9c writes a register its branch at 0x1e2e98 reads
 *   delay: addiu at 0x1e2fb0 writes a register its branch at 0x1e2fac reads
 *   delay: addiu at 0x1e2fc4 writes a register its branch at 0x1e2fc0 reads
 *   stack: address of the slot at 0x23d0 escapes at 0x1e3114
 *   stack: address of the slot at 0x23d0 escapes at 0x1e3128
 *   delay: addiu at 0x1e31f8 writes a register its branch at 0x1e31f4 reads
 *   delay: addiu at 0x1e320c writes a register its branch at 0x1e3208 reads
 *   stack: address of the slot at 0x1fe0 escapes at 0x1e333c
 *   stack: address of the slot at 0x1fe0 escapes at 0x1e3350
 *   delay: addiu at 0x1e33c8 writes a register its branch at 0x1e33c4 reads
 *   delay: addiu at 0x1e33dc writes a register its branch at 0x1e33d8 reads
 *   stack: address of the slot at 0x1bf0 escapes at 0x1e34f4
 *   stack: address of the slot at 0x1bf0 escapes at 0x1e3508
 *   stack: address of the slot at 0x1800 escapes at 0x1e36bc
 *   stack: address of the slot at 0x1800 escapes at 0x1e36d0
 *   delay: addiu at 0x1e36f8 writes a register its branch at 0x1e36f4 reads
 *   stack: address of the slot at 0x1410 escapes at 0x1e3784
 *   stack: address of the slot at 0x1410 escapes at 0x1e3798
 *   delay: addiu at 0x1e37c4 writes a register its branch at 0x1e37c0 reads
 *   delay: addiu at 0x1e37d8 writes a register its branch at 0x1e37d4 reads
 *   delay: addiu at 0x1e3830 writes a register its branch at 0x1e382c reads
 *   delay: addiu at 0x1e38e4 writes a register its branch at 0x1e38e0 reads
 *   delay: addiu at 0x1e38f8 writes a register its branch at 0x1e38f4 reads
 *   delay: addiu at 0x1e393c writes a register its branch at 0x1e3938 reads
 *   delay: addiu at 0x1e3950 writes a register its branch at 0x1e394c reads
 *   stack: address of the slot at 0x1020 escapes at 0x1e39f4
 *   stack: address of the slot at 0x1020 escapes at 0x1e3a08
 *   delay: addiu at 0x1e3a30 writes a register its branch at 0x1e3a2c reads
 *   stack: address of the slot at 0xc30 escapes at 0x1e3abc
 *   stack: address of the slot at 0xc30 escapes at 0x1e3ad0
 *   delay: addiu at 0x1e3afc writes a register its branch at 0x1e3af8 reads
 *   delay: addiu at 0x1e3b10 writes a register its branch at 0x1e3b0c reads
 *   delay: addiu at 0x1e3bd0 writes a register its branch at 0x1e3bcc reads
 *   stack: address of the slot at 0x840 escapes at 0x1e3cec
 *   stack: address of the slot at 0x840 escapes at 0x1e3d00
 *   stack: address of the slot at 0x450 escapes at 0x1e3da4
 *   stack: address of the slot at 0x450 escapes at 0x1e3db8
 *   stack: address of the slot at 0x60 escapes at 0x1e3e44
 *   stack: address of the slot at 0x60 escapes at 0x1e3e58
 *   delay: addiu at 0x1e3f08 writes a register its branch at 0x1e3f04 reads
 *   delay: addiu at 0x1e3fac writes a register its branch at 0x1e3fa8 reads
 *   delay: addiu at 0x1e3fcc writes a register its branch at 0x1e3fc8 reads
 *   delay: addiu at 0x1e3fec writes a register its branch at 0x1e3fe8 reads
 *   indirect: jr v1 at 0x1e407c -> <v1>
 *   delay: addiu at 0x1e422c writes a register its branch at 0x1e4228 reads
 *   delay: addiu at 0x1e4240 writes a register its branch at 0x1e423c reads
 *   delay: addiu at 0x1e4288 writes a register its branch at 0x1e4284 reads
 *   delay: addiu at 0x1e4298 writes a register its branch at 0x1e4294 reads
 *   delay: addiu at 0x1e42b8 writes a register its branch at 0x1e42b4 reads
 *   delay: addiu at 0x1e42cc writes a register its branch at 0x1e42c8 reads
 *   delay: addiu at 0x1e4310 writes a register its branch at 0x1e430c reads
 *   delay: addiu at 0x1e4320 writes a register its branch at 0x1e431c reads
 *   cfg: kept branch: 0x1e2e88 if (..) goto .L001E2EA8
 *   cfg: kept branch: 0x1e2e94 if (..) goto .L001E2EA8
 *   cfg: kept branch: 0x1e2e9c if (..) goto .L001E2EB8
 *   cfg: kept branch: 0x1e2fb0 if (..) goto .L001E2FD0
 *   cfg: kept branch: 0x1e2fbc if (..) goto .L001E2FD0
 *   cfg: kept branch: 0x1e2fc4 if (..) goto .L001E2FE0
 *   cfg: kept branch: 0x1e309c if (..) goto .L001E3148
 *   cfg: kept goto: 0x1e3140 -> .L001E3150
 *   cfg: kept branch: 0x1e31f8 if (..) goto .L001E3218
 *   cfg: kept branch: 0x1e3204 if (..) goto .L001E3218
 *   cfg: kept branch: 0x1e320c if (..) goto .L001E3228
 *   cfg: kept branch: 0x1e33c8 if (..) goto .L001E33E8
 *   cfg: kept branch: 0x1e33d4 if (..) goto .L001E33E8
 *   cfg: kept branch: 0x1e33dc if (..) goto .L001E33F8
 *   cfg: kept branch: 0x1e359c if (..) goto .L001E3600
 *   cfg: kept branch: 0x1e35a4 if (..) goto .L001E3600
 *   cfg: kept branch: 0x1e35b0 if (..) goto .L001E3B58
 *   cfg: kept goto: 0x1e35ec -> .L001E3B58
 *   cfg: kept branch: 0x1e3638 if (..) goto .L001E36F0
 *   cfg: kept branch: 0x1e37c4 if (..) goto .L001E37E8
 *   cfg: kept branch: 0x1e37d0 if (..) goto .L001E37E8
 *   cfg: kept branch: 0x1e37d8 if (..) goto .L001E37F8
 *   cfg: kept branch: 0x1e37f8 if (..) goto .L001E3B58
 *   cfg: kept goto: 0x1e3800 -> .L001E3B58
 *   cfg: kept goto: 0x1e3840 -> .L001E3B58
 *   cfg: kept branch: 0x1e38e4 if (..) goto .L001E3908
 *   cfg: kept branch: 0x1e38f0 if (..) goto .L001E3908
 *   cfg: kept branch: 0x1e38f8 if (..) goto .L001E3918
 *   cfg: kept branch: 0x1e393c if (..) goto .L001E3960
 *   cfg: kept branch: 0x1e3948 if (..) goto .L001E3960
 *   cfg: kept branch: 0x1e3950 if (..) goto .L001E3970
 *   cfg: kept branch: 0x1e3970 if (..) goto .L001E3A28
 *   cfg: kept goto: 0x1e3a20 -> .L001E3AE8
 *   cfg: kept branch: 0x1e3afc if (..) goto .L001E3B20
 *   cfg: kept branch: 0x1e3b08 if (..) goto .L001E3B20
 *   cfg: kept branch: 0x1e3b10 if (..) goto .L001E3B30
 *   cfg: kept branch: 0x1e3b80 if (..) goto .L001E3C50
 *   cfg: kept branch: 0x1e3bac if (..) goto .L001E3C50
 *   cfg: kept branch: 0x1e3bc0 if (..) goto .L001E3C50
 *   cfg: kept branch: 0x1e4088 if (..) goto .L001E41B8
 *   cfg: kept branch: 0x1e4094 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e40a8 -> .L001E4340
 *   cfg: kept branch: 0x1e40b0 if (..) goto .L001E41B8
 *   cfg: kept branch: 0x1e40bc if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e40d0 -> .L001E4340
 *   cfg: kept branch: 0x1e40d8 if (..) goto .L001E41B8
 *   cfg: kept branch: 0x1e40e4 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e40f8 -> .L001E4340
 *   cfg: kept branch: 0x1e4100 if (..) goto .L001E41B8
 *   cfg: kept branch: 0x1e410c if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e4120 -> .L001E4340
 *   cfg: kept branch: 0x1e4128 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e413c -> .L001E4340
 *   cfg: kept branch: 0x1e4140 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e4154 -> .L001E4340
 *   cfg: kept branch: 0x1e4158 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e416c -> .L001E4340
 *   cfg: kept branch: 0x1e4170 if (..) goto .L001E4188
 *   cfg: kept goto: 0x1e4184 -> .L001E4340
 *   cfg: kept branch: 0x1e4188 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e4198 -> .L001E4340
 *   cfg: kept branch: 0x1e41a0 if (..) goto .L001E41B8
 *   cfg: kept goto: 0x1e41b4 -> .L001E4340
 *   cfg: kept goto: 0x1e4258 -> .L001E42B0
 *   cfg: kept goto: 0x1e4260 -> .L001E42B0
 *   cfg: kept goto: 0x1e4270 -> .L001E42B0
 *   cfg: kept branch: 0x1e4290 if (..) goto .L001E42B0
 *   cfg: kept goto: 0x1e4298 -> .L001E42B0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int MemoryCardStart(unsigned char, unsigned char, unsigned char);
extern u32 MemoryCardProc();
extern u32 L11317[];
extern u32 L11318[];

#ifndef PROTO_DW_2298180_FIELDS
#define PROTO_DW_2298180_FIELDS
struct dw_2298180_fields { unsigned char state[2]; unsigned char mode_[2]; unsigned char checking_port; unsigned char checking_port_ok; unsigned char data_index; unsigned char list_ok; unsigned char checking_on; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED = (int)&(((struct dw_2298180_fields *)0)->checking_on) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 = (int)&(((struct dw_2298180_fields *)0)->checking_port) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 = (int)&(((struct dw_2298180_fields *)0)->checking_port_ok) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E = (int)&(((struct dw_2298180_fields *)0)->list_ok) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E = (int)&(((struct dw_2298180_fields *)0)->state[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 = (int)&(((struct dw_2298180_fields *)0)->state[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 = (int)&(((struct dw_2298180_fields *)0)->state[0]) - 0 };
#endif


/* MI_Decide_Memoca @ 0x1E2960 .. 0x1E2C40 (0x2e0 bytes, frame 0x420) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e29dc writes a register its branch at 0x1e29d8 reads
 *   delay: addiu at 0x1e29f0 writes a register its branch at 0x1e29ec reads
 *   delay: addiu at 0x1e2a38 writes a register its branch at 0x1e2a34 reads
 *   delay: addiu at 0x1e2a48 writes a register its branch at 0x1e2a44 reads
 *   stack: address of the slot at 0x410 escapes at 0x1e2a78
 *   stack: address of the slot at 0x410 escapes at 0x1e2ab8
 *   stack: address of the slot at 0x20 escapes at 0x1e2b10
 *   stack: address of the slot at 0x20 escapes at 0x1e2b24
 *   delay: addiu at 0x1e2bd8 writes a register its branch at 0x1e2bd4 reads
 */

extern signed int MemoryCardStart(unsigned char, unsigned char, unsigned char);



typedef struct { unsigned char pad:7, busy:1; unsigned char check:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, pad1:2; unsigned char remaining[2]; } MICardFlags;


extern void *GetSaveDataHeader(signed int);
extern u32 aTmpMemocaData[];



/* MI_Evrfrm_Load @ 0x1DE060 .. 0x1E20E0 (0x4080 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   literal: @10293 -> 0x256010
 *   delay: addiu at 0x1de0b0 writes a register its branch at 0x1de0ac reads
 *   delay: addiu at 0x1de0c4 writes a register its branch at 0x1de0c0 reads
 *   delay: addiu at 0x1de14c writes a register its branch at 0x1de148 reads
 *   delay: addiu at 0x1de160 writes a register its branch at 0x1de15c reads
 *   delay: addiu at 0x1de20c writes a register its branch at 0x1de208 reads
 *   delay: addiu at 0x1de220 writes a register its branch at 0x1de21c reads
 *   delay: addiu at 0x1de234 writes a register its branch at 0x1de230 reads
 *   delay: addiu at 0x1de248 writes a register its branch at 0x1de244 reads
 *   delay: addiu at 0x1de25c writes a register its branch at 0x1de258 reads
 *   delay: addiu at 0x1de2cc writes a register its branch at 0x1de2c8 reads
 *   delay: addiu at 0x1de2e0 writes a register its branch at 0x1de2dc reads
 *   delay: addiu at 0x1de3b8 writes a register its branch at 0x1de3b4 reads
 *   delay: addiu at 0x1de3cc writes a register its branch at 0x1de3c8 reads
 *   delay: addiu at 0x1de40c writes a register its branch at 0x1de408 reads
 *   delay: addiu at 0x1de420 writes a register its branch at 0x1de41c reads
 *   delay: addiu at 0x1de464 writes a register its branch at 0x1de460 reads
 *   delay: addiu at 0x1de478 writes a register its branch at 0x1de474 reads
 *   delay: addiu at 0x1de4bc writes a register its branch at 0x1de4b8 reads
 *   delay: addiu at 0x1de4d0 writes a register its branch at 0x1de4cc reads
 *   delay: addiu at 0x1de50c writes a register its branch at 0x1de508 reads
 *   delay: addiu at 0x1de520 writes a register its branch at 0x1de51c reads
 *   indirect: jr v1 at 0x1de5a4 -> <v1>
 *   delay: addiu at 0x1de5d8 writes a register its branch at 0x1de5d4 reads
 *   delay: addiu at 0x1de5ec writes a register its branch at 0x1de5e8 reads
 *   delay: addiu at 0x1de62c writes a register its branch at 0x1de628 reads
 *   delay: addiu at 0x1de640 writes a register its branch at 0x1de63c reads
 *   delay: addiu at 0x1de684 writes a register its branch at 0x1de680 reads
 *   delay: addiu at 0x1de698 writes a register its branch at 0x1de694 reads
 *   delay: addiu at 0x1de6dc writes a register its branch at 0x1de6d8 reads
 *   delay: addiu at 0x1de6f0 writes a register its branch at 0x1de6ec reads
 *   delay: addiu at 0x1de72c writes a register its branch at 0x1de728 reads
 *   delay: addiu at 0x1de740 writes a register its branch at 0x1de73c reads
 *   delay: addiu at 0x1de7fc writes a register its branch at 0x1de7f8 reads
 *   delay: addiu at 0x1de810 writes a register its branch at 0x1de80c reads
 *   delay: addiu at 0x1de854 writes a register its branch at 0x1de850 reads
 *   delay: addiu at 0x1de868 writes a register its branch at 0x1de864 reads
 *   delay: addiu at 0x1de8ac writes a register its branch at 0x1de8a8 reads
 *   delay: addiu at 0x1de8c0 writes a register its branch at 0x1de8bc reads
 *   delay: addiu at 0x1de904 writes a register its branch at 0x1de900 reads
 *   delay: addiu at 0x1de918 writes a register its branch at 0x1de914 reads
 *   delay: addiu at 0x1de954 writes a register its branch at 0x1de950 reads
 *   delay: addiu at 0x1de968 writes a register its branch at 0x1de964 reads
 *   delay: addiu at 0x1dea60 writes a register its branch at 0x1dea5c reads
 *   delay: addiu at 0x1dea74 writes a register its branch at 0x1dea70 reads
 *   delay: addiu at 0x1deab4 writes a register its branch at 0x1deab0 reads
 *   delay: addiu at 0x1deac8 writes a register its branch at 0x1deac4 reads
 *   delay: addiu at 0x1deb0c writes a register its branch at 0x1deb08 reads
 *   delay: addiu at 0x1deb20 writes a register its branch at 0x1deb1c reads
 *   delay: addiu at 0x1deb64 writes a register its branch at 0x1deb60 reads
 *   delay: addiu at 0x1deb78 writes a register its branch at 0x1deb74 reads
 *   delay: addiu at 0x1debb4 writes a register its branch at 0x1debb0 reads
 *   delay: addiu at 0x1debc8 writes a register its branch at 0x1debc4 reads
 *   delay: addiu at 0x1dec20 writes a register its branch at 0x1dec1c reads
 *   delay: addiu at 0x1dec34 writes a register its branch at 0x1dec30 reads
 *   delay: addiu at 0x1dec74 writes a register its branch at 0x1dec70 reads
 *   delay: addiu at 0x1dec88 writes a register its branch at 0x1dec84 reads
 *   delay: addiu at 0x1deccc writes a register its branch at 0x1decc8 reads
 *   delay: addiu at 0x1dece0 writes a register its branch at 0x1decdc reads
 *   delay: addiu at 0x1ded24 writes a register its branch at 0x1ded20 reads
 *   delay: addiu at 0x1ded38 writes a register its branch at 0x1ded34 reads
 *   delay: addiu at 0x1ded8c writes a register its branch at 0x1ded88 reads
 *   delay: addiu at 0x1deda0 writes a register its branch at 0x1ded9c reads
 *   delay: addiu at 0x1dedf4 writes a register its branch at 0x1dedf0 reads
 *   delay: addiu at 0x1dee08 writes a register its branch at 0x1dee04 reads
 *   delay: addiu at 0x1dee4c writes a register its branch at 0x1dee48 reads
 *   delay: addiu at 0x1dee60 writes a register its branch at 0x1dee5c reads
 *   delay: addiu at 0x1deea4 writes a register its branch at 0x1deea0 reads
 *   delay: addiu at 0x1deeb8 writes a register its branch at 0x1deeb4 reads
 *   delay: addiu at 0x1deefc writes a register its branch at 0x1deef8 reads
 *   delay: addiu at 0x1def10 writes a register its branch at 0x1def0c reads
 *   delay: addiu at 0x1def4c writes a register its branch at 0x1def48 reads
 *   delay: addiu at 0x1def60 writes a register its branch at 0x1def5c reads
 *   delay: addiu at 0x1defb8 writes a register its branch at 0x1defb4 reads
 *   delay: addiu at 0x1defcc writes a register its branch at 0x1defc8 reads
 *   delay: addiu at 0x1df00c writes a register its branch at 0x1df008 reads
 *   delay: addiu at 0x1df020 writes a register its branch at 0x1df01c reads
 *   delay: addiu at 0x1df140 writes a register its branch at 0x1df13c reads
 *   delay: addiu at 0x1df1d8 writes a register its branch at 0x1df1d4 reads
 *   delay: addiu at 0x1df1ec writes a register its branch at 0x1df1e8 reads
 *   delay: addiu at 0x1df22c writes a register its branch at 0x1df228 reads
 *   delay: addiu at 0x1df240 writes a register its branch at 0x1df23c reads
 *   delay: addiu at 0x1df284 writes a register its branch at 0x1df280 reads
 *   delay: addiu at 0x1df298 writes a register its branch at 0x1df294 reads
 *   delay: addiu at 0x1df2dc writes a register its branch at 0x1df2d8 reads
 *   delay: addiu at 0x1df2f0 writes a register its branch at 0x1df2ec reads
 *   delay: addiu at 0x1df32c writes a register its branch at 0x1df328 reads
 *   delay: addiu at 0x1df340 writes a register its branch at 0x1df33c reads
 *   delay: addiu at 0x1df398 writes a register its branch at 0x1df394 reads
 *   delay: addiu at 0x1df3ac writes a register its branch at 0x1df3a8 reads
 *   delay: addiu at 0x1df3ec writes a register its branch at 0x1df3e8 reads
 *   delay: addiu at 0x1df400 writes a register its branch at 0x1df3fc reads
 *   delay: addiu at 0x1df444 writes a register its branch at 0x1df440 reads
 *   delay: addiu at 0x1df458 writes a register its branch at 0x1df454 reads
 *   delay: addiu at 0x1df49c writes a register its branch at 0x1df498 reads
 *   delay: addiu at 0x1df4b0 writes a register its branch at 0x1df4ac reads
 *   delay: addiu at 0x1df4ec writes a register its branch at 0x1df4e8 reads
 *   delay: addiu at 0x1df500 writes a register its branch at 0x1df4fc reads
 *   delay: addiu at 0x1df574 writes a register its branch at 0x1df570 reads
 *   delay: addiu at 0x1df588 writes a register its branch at 0x1df584 reads
 *   delay: addiu at 0x1df60c writes a register its branch at 0x1df608 reads
 *   delay: addiu at 0x1df620 writes a register its branch at 0x1df61c reads
 *   delay: addiu at 0x1df664 writes a register its branch at 0x1df660 reads
 *   delay: addiu at 0x1df678 writes a register its branch at 0x1df674 reads
 *   delay: addiu at 0x1df6bc writes a register its branch at 0x1df6b8 reads
 *   delay: addiu at 0x1df6d0 writes a register its branch at 0x1df6cc reads
 *   delay: addiu at 0x1df714 writes a register its branch at 0x1df710 reads
 *   delay: addiu at 0x1df728 writes a register its branch at 0x1df724 reads
 *   delay: addiu at 0x1df764 writes a register its branch at 0x1df760 reads
 *   delay: addiu at 0x1df778 writes a register its branch at 0x1df774 reads
 *   delay: addiu at 0x1df828 writes a register its branch at 0x1df824 reads
 *   delay: addiu at 0x1df8d0 writes a register its branch at 0x1df8cc reads
 *   delay: addiu at 0x1df8e4 writes a register its branch at 0x1df8e0 reads
 *   delay: addiu at 0x1df924 writes a register its branch at 0x1df920 reads
 *   delay: addiu at 0x1df938 writes a register its branch at 0x1df934 reads
 *   delay: addiu at 0x1df97c writes a register its branch at 0x1df978 reads
 *   delay: addiu at 0x1df990 writes a register its branch at 0x1df98c reads
 *   delay: addiu at 0x1df9d4 writes a register its branch at 0x1df9d0 reads
 *   delay: addiu at 0x1df9e8 writes a register its branch at 0x1df9e4 reads
 *   delay: addiu at 0x1dfa24 writes a register its branch at 0x1dfa20 reads
 *   delay: addiu at 0x1dfa38 writes a register its branch at 0x1dfa34 reads
 *   delay: addiu at 0x1dfaac writes a register its branch at 0x1dfaa8 reads
 *   delay: addiu at 0x1dfac0 writes a register its branch at 0x1dfabc reads
 *   delay: addiu at 0x1dfb44 writes a register its branch at 0x1dfb40 reads
 *   delay: addiu at 0x1dfb58 writes a register its branch at 0x1dfb54 reads
 *   delay: addiu at 0x1dfb9c writes a register its branch at 0x1dfb98 reads
 *   delay: addiu at 0x1dfbb0 writes a register its branch at 0x1dfbac reads
 *   delay: addiu at 0x1dfbf4 writes a register its branch at 0x1dfbf0 reads
 *   delay: addiu at 0x1dfc08 writes a register its branch at 0x1dfc04 reads
 *   delay: addiu at 0x1dfc4c writes a register its branch at 0x1dfc48 reads
 *   delay: addiu at 0x1dfc60 writes a register its branch at 0x1dfc5c reads
 *   delay: addiu at 0x1dfc9c writes a register its branch at 0x1dfc98 reads
 *   delay: addiu at 0x1dfcb0 writes a register its branch at 0x1dfcac reads
 *   delay: addiu at 0x1dfd08 writes a register its branch at 0x1dfd04 reads
 *   delay: addiu at 0x1dfd1c writes a register its branch at 0x1dfd18 reads
 *   delay: addiu at 0x1dfd5c writes a register its branch at 0x1dfd58 reads
 *   delay: addiu at 0x1dfd70 writes a register its branch at 0x1dfd6c reads
 *   delay: addiu at 0x1dfe20 writes a register its branch at 0x1dfe1c reads
 *   delay: addiu at 0x1dfeb8 writes a register its branch at 0x1dfeb4 reads
 *   delay: addiu at 0x1dfecc writes a register its branch at 0x1dfec8 reads
 *   delay: addiu at 0x1dff0c writes a register its branch at 0x1dff08 reads
 *   delay: addiu at 0x1dff20 writes a register its branch at 0x1dff1c reads
 *   delay: addiu at 0x1dff64 writes a register its branch at 0x1dff60 reads
 *   delay: addiu at 0x1dff78 writes a register its branch at 0x1dff74 reads
 *   delay: addiu at 0x1dffbc writes a register its branch at 0x1dffb8 reads
 *   delay: addiu at 0x1dffd0 writes a register its branch at 0x1dffcc reads
 *   delay: addiu at 0x1e000c writes a register its branch at 0x1e0008 reads
 *   delay: addiu at 0x1e0020 writes a register its branch at 0x1e001c reads
 *   delay: addiu at 0x1e00a4 writes a register its branch at 0x1e00a0 reads
 *   delay: addiu at 0x1e00b8 writes a register its branch at 0x1e00b4 reads
 *   delay: addiu at 0x1e00fc writes a register its branch at 0x1e00f8 reads
 *   delay: addiu at 0x1e0110 writes a register its branch at 0x1e010c reads
 *   delay: addiu at 0x1e0154 writes a register its branch at 0x1e0150 reads
 *   delay: addiu at 0x1e0168 writes a register its branch at 0x1e0164 reads
 *   delay: addiu at 0x1e01ac writes a register its branch at 0x1e01a8 reads
 *   delay: addiu at 0x1e01c0 writes a register its branch at 0x1e01bc reads
 *   delay: addiu at 0x1e01fc writes a register its branch at 0x1e01f8 reads
 *   delay: addiu at 0x1e0210 writes a register its branch at 0x1e020c reads
 *   delay: addiu at 0x1e02f0 writes a register its branch at 0x1e02ec reads
 *   delay: addiu at 0x1e0304 writes a register its branch at 0x1e0300 reads
 *   delay: addiu at 0x1e0344 writes a register its branch at 0x1e0340 reads
 *   delay: addiu at 0x1e0358 writes a register its branch at 0x1e0354 reads
 *   delay: addiu at 0x1e039c writes a register its branch at 0x1e0398 reads
 *   delay: addiu at 0x1e03b0 writes a register its branch at 0x1e03ac reads
 *   delay: addiu at 0x1e03f4 writes a register its branch at 0x1e03f0 reads
 *   delay: addiu at 0x1e0408 writes a register its branch at 0x1e0404 reads
 *   delay: addiu at 0x1e0444 writes a register its branch at 0x1e0440 reads
 *   delay: addiu at 0x1e0458 writes a register its branch at 0x1e0454 reads
 *   delay: addiu at 0x1e04cc writes a register its branch at 0x1e04c8 reads
 *   delay: addiu at 0x1e04e0 writes a register its branch at 0x1e04dc reads
 *   delay: addiu at 0x1e057c writes a register its branch at 0x1e0578 reads
 *   delay: addiu at 0x1e0590 writes a register its branch at 0x1e058c reads
 *   delay: addiu at 0x1e05d4 writes a register its branch at 0x1e05d0 reads
 *   delay: addiu at 0x1e05e8 writes a register its branch at 0x1e05e4 reads
 *   delay: addiu at 0x1e062c writes a register its branch at 0x1e0628 reads
 *   delay: addiu at 0x1e0640 writes a register its branch at 0x1e063c reads
 *   delay: addiu at 0x1e0684 writes a register its branch at 0x1e0680 reads
 *   delay: addiu at 0x1e0698 writes a register its branch at 0x1e0694 reads
 *   delay: addiu at 0x1e06d4 writes a register its branch at 0x1e06d0 reads
 *   delay: addiu at 0x1e06e8 writes a register its branch at 0x1e06e4 reads
 *   delay: addiu at 0x1e0740 writes a register its branch at 0x1e073c reads
 *   delay: addiu at 0x1e0754 writes a register its branch at 0x1e0750 reads
 *   delay: addiu at 0x1e0794 writes a register its branch at 0x1e0790 reads
 *   delay: addiu at 0x1e07a8 writes a register its branch at 0x1e07a4 reads
 *   delay: addiu at 0x1e0858 writes a register its branch at 0x1e0854 reads
 *   delay: addiu at 0x1e08f0 writes a register its branch at 0x1e08ec reads
 *   delay: addiu at 0x1e0904 writes a register its branch at 0x1e0900 reads
 *   delay: addiu at 0x1e0944 writes a register its branch at 0x1e0940 reads
 *   delay: addiu at 0x1e0958 writes a register its branch at 0x1e0954 reads
 *   delay: addiu at 0x1e099c writes a register its branch at 0x1e0998 reads
 *   delay: addiu at 0x1e09b0 writes a register its branch at 0x1e09ac reads
 *   delay: addiu at 0x1e09f4 writes a register its branch at 0x1e09f0 reads
 *   delay: addiu at 0x1e0a08 writes a register its branch at 0x1e0a04 reads
 *   delay: addiu at 0x1e0a44 writes a register its branch at 0x1e0a40 reads
 *   delay: addiu at 0x1e0a58 writes a register its branch at 0x1e0a54 reads
 *   delay: addiu at 0x1e0af4 writes a register its branch at 0x1e0af0 reads
 *   delay: addiu at 0x1e0b08 writes a register its branch at 0x1e0b04 reads
 *   delay: addiu at 0x1e0b4c writes a register its branch at 0x1e0b48 reads
 *   delay: addiu at 0x1e0b60 writes a register its branch at 0x1e0b5c reads
 *   delay: addiu at 0x1e0ba4 writes a register its branch at 0x1e0ba0 reads
 *   delay: addiu at 0x1e0bb8 writes a register its branch at 0x1e0bb4 reads
 *   delay: addiu at 0x1e0bfc writes a register its branch at 0x1e0bf8 reads
 *   delay: addiu at 0x1e0c10 writes a register its branch at 0x1e0c0c reads
 *   delay: addiu at 0x1e0c4c writes a register its branch at 0x1e0c48 reads
 *   delay: addiu at 0x1e0c60 writes a register its branch at 0x1e0c5c reads
 *   delay: addiu at 0x1e0d0c writes a register its branch at 0x1e0d08 reads
 *   delay: addiu at 0x1e0d20 writes a register its branch at 0x1e0d1c reads
 *   delay: addiu at 0x1e0d64 writes a register its branch at 0x1e0d60 reads
 *   delay: addiu at 0x1e0d78 writes a register its branch at 0x1e0d74 reads
 *   delay: addiu at 0x1e0dbc writes a register its branch at 0x1e0db8 reads
 *   delay: addiu at 0x1e0dd0 writes a register its branch at 0x1e0dcc reads
 *   delay: addiu at 0x1e0e14 writes a register its branch at 0x1e0e10 reads
 *   delay: addiu at 0x1e0e28 writes a register its branch at 0x1e0e24 reads
 *   delay: addiu at 0x1e0e64 writes a register its branch at 0x1e0e60 reads
 *   delay: addiu at 0x1e0e78 writes a register its branch at 0x1e0e74 reads
 *   delay: addiu at 0x1e0ed0 writes a register its branch at 0x1e0ecc reads
 *   delay: addiu at 0x1e0f48 writes a register its branch at 0x1e0f44 reads
 *   delay: addiu at 0x1e0fd8 writes a register its branch at 0x1e0fd4 reads
 *   delay: addiu at 0x1e0fec writes a register its branch at 0x1e0fe8 reads
 *   delay: addiu at 0x1e102c writes a register its branch at 0x1e1028 reads
 *   delay: addiu at 0x1e1040 writes a register its branch at 0x1e103c reads
 *   delay: addiu at 0x1e1084 writes a register its branch at 0x1e1080 reads
 *   delay: addiu at 0x1e1098 writes a register its branch at 0x1e1094 reads
 *   delay: addiu at 0x1e10dc writes a register its branch at 0x1e10d8 reads
 *   delay: addiu at 0x1e10f0 writes a register its branch at 0x1e10ec reads
 *   delay: addiu at 0x1e112c writes a register its branch at 0x1e1128 reads
 *   delay: addiu at 0x1e1140 writes a register its branch at 0x1e113c reads
 *   delay: addiu at 0x1e11c4 writes a register its branch at 0x1e11c0 reads
 *   delay: addiu at 0x1e11d8 writes a register its branch at 0x1e11d4 reads
 *   delay: addiu at 0x1e121c writes a register its branch at 0x1e1218 reads
 *   delay: addiu at 0x1e1230 writes a register its branch at 0x1e122c reads
 *   delay: addiu at 0x1e1274 writes a register its branch at 0x1e1270 reads
 *   delay: addiu at 0x1e1288 writes a register its branch at 0x1e1284 reads
 *   delay: addiu at 0x1e12cc writes a register its branch at 0x1e12c8 reads
 *   delay: addiu at 0x1e12e0 writes a register its branch at 0x1e12dc reads
 *   delay: addiu at 0x1e131c writes a register its branch at 0x1e1318 reads
 *   delay: addiu at 0x1e1330 writes a register its branch at 0x1e132c reads
 *   delay: addiu at 0x1e13f8 writes a register its branch at 0x1e13f4 reads
 *   delay: addiu at 0x1e140c writes a register its branch at 0x1e1408 reads
 *   delay: addiu at 0x1e144c writes a register its branch at 0x1e1448 reads
 *   delay: addiu at 0x1e1460 writes a register its branch at 0x1e145c reads
 *   delay: addiu at 0x1e14a4 writes a register its branch at 0x1e14a0 reads
 *   delay: addiu at 0x1e14b8 writes a register its branch at 0x1e14b4 reads
 *   delay: addiu at 0x1e14fc writes a register its branch at 0x1e14f8 reads
 *   delay: addiu at 0x1e1510 writes a register its branch at 0x1e150c reads
 *   delay: addiu at 0x1e154c writes a register its branch at 0x1e1548 reads
 *   delay: addiu at 0x1e1560 writes a register its branch at 0x1e155c reads
 *   delay: addiu at 0x1e15d0 writes a register its branch at 0x1e15cc reads
 *   delay: addiu at 0x1e15e4 writes a register its branch at 0x1e15e0 reads
 *   delay: addiu at 0x1e1664 writes a register its branch at 0x1e1660 reads
 *   delay: addiu at 0x1e1678 writes a register its branch at 0x1e1674 reads
 *   delay: addiu at 0x1e16bc writes a register its branch at 0x1e16b8 reads
 *   delay: addiu at 0x1e16d0 writes a register its branch at 0x1e16cc reads
 *   delay: addiu at 0x1e1714 writes a register its branch at 0x1e1710 reads
 *   delay: addiu at 0x1e1728 writes a register its branch at 0x1e1724 reads
 *   delay: addiu at 0x1e176c writes a register its branch at 0x1e1768 reads
 *   delay: addiu at 0x1e1780 writes a register its branch at 0x1e177c reads
 *   delay: addiu at 0x1e17bc writes a register its branch at 0x1e17b8 reads
 *   delay: addiu at 0x1e17d0 writes a register its branch at 0x1e17cc reads
 *   delay: addiu at 0x1e1890 writes a register its branch at 0x1e188c reads
 *   delay: addiu at 0x1e18b8 writes a register its branch at 0x1e18b4 reads
 *   delay: addiu at 0x1e18cc writes a register its branch at 0x1e18c8 reads
 *   delay: addiu at 0x1e190c writes a register its branch at 0x1e1908 reads
 *   delay: addiu at 0x1e1920 writes a register its branch at 0x1e191c reads
 *   delay: addiu at 0x1e1964 writes a register its branch at 0x1e1960 reads
 *   delay: addiu at 0x1e1978 writes a register its branch at 0x1e1974 reads
 *   delay: addiu at 0x1e19bc writes a register its branch at 0x1e19b8 reads
 *   delay: addiu at 0x1e19d0 writes a register its branch at 0x1e19cc reads
 *   delay: addiu at 0x1e1a0c writes a register its branch at 0x1e1a08 reads
 *   delay: addiu at 0x1e1a20 writes a register its branch at 0x1e1a1c reads
 *   delay: addiu at 0x1e1af8 writes a register its branch at 0x1e1af4 reads
 *   delay: addiu at 0x1e1b88 writes a register its branch at 0x1e1b84 reads
 *   delay: addiu at 0x1e1b9c writes a register its branch at 0x1e1b98 reads
 *   delay: addiu at 0x1e1bdc writes a register its branch at 0x1e1bd8 reads
 *   delay: addiu at 0x1e1bf0 writes a register its branch at 0x1e1bec reads
 *   delay: addiu at 0x1e1c34 writes a register its branch at 0x1e1c30 reads
 *   delay: addiu at 0x1e1c48 writes a register its branch at 0x1e1c44 reads
 *   delay: addiu at 0x1e1c8c writes a register its branch at 0x1e1c88 reads
 *   delay: addiu at 0x1e1ca0 writes a register its branch at 0x1e1c9c reads
 *   delay: addiu at 0x1e1cdc writes a register its branch at 0x1e1cd8 reads
 *   delay: addiu at 0x1e1cf0 writes a register its branch at 0x1e1cec reads
 *   delay: addiu at 0x1e1d48 writes a register its branch at 0x1e1d44 reads
 *   delay: addiu at 0x1e1d5c writes a register its branch at 0x1e1d58 reads
 *   delay: addiu at 0x1e1f3c writes a register its branch at 0x1e1f38 reads
 *   delay: addiu at 0x1e1f50 writes a register its branch at 0x1e1f4c reads
 *   delay: addiu at 0x1e1f64 writes a register its branch at 0x1e1f60 reads
 *   delay: addiu at 0x1e1f78 writes a register its branch at 0x1e1f74 reads
 *   delay: addiu at 0x1e1f8c writes a register its branch at 0x1e1f88 reads
 *   delay: addiu at 0x1e1fa0 writes a register its branch at 0x1e1f9c reads
 *   delay: addiu at 0x1e1fb4 writes a register its branch at 0x1e1fb0 reads
 *   delay: addiu at 0x1e1fc8 writes a register its branch at 0x1e1fc4 reads
 *   delay: addiu at 0x1e1fdc writes a register its branch at 0x1e1fd8 reads
 *   delay: addiu at 0x1e1ff0 writes a register its branch at 0x1e1fec reads
 *   delay: addiu at 0x1e2004 writes a register its branch at 0x1e2000 reads
 *   cfg: kept branch: 0x1de204 if (..) goto .L001DE288
 *   cfg: kept goto: 0x1de27c -> .L001DE2A0
 *   cfg: kept branch: 0x1de2e0 if (..) goto .L001DE300
 *   cfg: kept branch: 0x1de3cc if (..) goto .L001DE3E8
 *   cfg: kept branch: 0x1de420 if (..) goto .L001DE440
 *   cfg: kept branch: 0x1de478 if (..) goto .L001DE498
 *   cfg: kept branch: 0x1de4d0 if (..) goto .L001DE4F0
 *   cfg: kept branch: 0x1de520 if (..) goto .L001DE540
 *   cfg: kept branch: 0x1de540 if (..) goto .L001DE568
 *   cfg: loop body is not one contiguous region: .L001DE580
 *   cfg: kept branch: 0x1de5d8 if (..) goto .L001DE5F8
 *   cfg: kept branch: 0x1de5e4 if (..) goto .L001DE5F8
 *   cfg: kept branch: 0x1de5ec if (..) goto .L001DE608
 *   cfg: kept branch: 0x1de62c if (..) goto .L001DE650
 *   cfg: kept branch: 0x1de638 if (..) goto .L001DE650
 *   cfg: kept branch: 0x1de640 if (..) goto .L001DE660
 *   cfg: kept branch: 0x1de660 if (..) goto .L001DE770
 *   cfg: kept branch: 0x1de684 if (..) goto .L001DE6A8
 *   cfg: kept branch: 0x1de690 if (..) goto .L001DE6A8
 *   cfg: kept branch: 0x1de698 if (..) goto .L001DE6B8
 *   cfg: kept branch: 0x1de6b8 if (..) goto .L001DE770
 *   cfg: kept branch: 0x1de6dc if (..) goto .L001DE700
 *   cfg: kept branch: 0x1de6e8 if (..) goto .L001DE700
 *   cfg: kept branch: 0x1de6f0 if (..) goto .L001DE710
 *   cfg: kept branch: 0x1de710 if (..) goto .L001DE770
 *   cfg: kept branch: 0x1de72c if (..) goto .L001DE750
 *   cfg: kept branch: 0x1de738 if (..) goto .L001DE750
 *   cfg: kept branch: 0x1de740 if (..) goto .L001DE760
 *   cfg: kept branch: 0x1de760 if (..) goto .L001DE780
 *   cfg: kept branch: 0x1de7fc if (..) goto .L001DE820
 *   cfg: kept branch: 0x1de808 if (..) goto .L001DE820
 *   cfg: kept branch: 0x1de810 if (..) goto .L001DE830
 *   cfg: kept branch: 0x1de854 if (..) goto .L001DE878
 *   cfg: kept branch: 0x1de860 if (..) goto .L001DE878
 *   cfg: kept branch: 0x1de868 if (..) goto .L001DE888
 *   cfg: kept branch: 0x1de888 if (..) goto .L001DE998
 *   cfg: kept branch: 0x1de8ac if (..) goto .L001DE8D0
 *   cfg: kept branch: 0x1de8b8 if (..) goto .L001DE8D0
 *   cfg: kept branch: 0x1de8c0 if (..) goto .L001DE8E0
 *   cfg: kept branch: 0x1de8e0 if (..) goto .L001DE998
 *   cfg: kept branch: 0x1de904 if (..) goto .L001DE928
 *   cfg: kept branch: 0x1de910 if (..) goto .L001DE928
 *   cfg: kept branch: 0x1de918 if (..) goto .L001DE938
 *   cfg: kept branch: 0x1de938 if (..) goto .L001DE998
 *   cfg: kept branch: 0x1de954 if (..) goto .L001DE978
 *   cfg: kept branch: 0x1de960 if (..) goto .L001DE978
 *   cfg: kept branch: 0x1de968 if (..) goto .L001DE988
 *   cfg: kept branch: 0x1de988 if (..) goto .L001DE9A8
 *   cfg: kept branch: 0x1dea60 if (..) goto .L001DEA80
 *   cfg: kept branch: 0x1dea6c if (..) goto .L001DEA80
 *   cfg: kept branch: 0x1dea74 if (..) goto .L001DEA90
 *   cfg: kept branch: 0x1deab4 if (..) goto .L001DEAD8
 *   cfg: kept branch: 0x1deac0 if (..) goto .L001DEAD8
 *   cfg: kept branch: 0x1deac8 if (..) goto .L001DEAE8
 *   cfg: kept branch: 0x1deae8 if (..) goto .L001DEBF8
 *   cfg: kept branch: 0x1deb0c if (..) goto .L001DEB30
 *   cfg: kept branch: 0x1deb18 if (..) goto .L001DEB30
 *   cfg: kept branch: 0x1deb20 if (..) goto .L001DEB40
 *   cfg: kept branch: 0x1deb40 if (..) goto .L001DEBF8
 *   cfg: kept branch: 0x1deb64 if (..) goto .L001DEB88
 *   cfg: kept branch: 0x1deb70 if (..) goto .L001DEB88
 *   cfg: kept branch: 0x1deb78 if (..) goto .L001DEB98
 *   cfg: kept branch: 0x1deb98 if (..) goto .L001DEBF8
 *   cfg: kept branch: 0x1debb4 if (..) goto .L001DEBD8
 *   cfg: kept branch: 0x1debc0 if (..) goto .L001DEBD8
 *   cfg: kept branch: 0x1debc8 if (..) goto .L001DEBE8
 *   cfg: kept branch: 0x1dec20 if (..) goto .L001DEC40
 *   cfg: kept branch: 0x1dec2c if (..) goto .L001DEC40
 *   cfg: kept branch: 0x1dec34 if (..) goto .L001DEC50
 *   cfg: kept branch: 0x1dec74 if (..) goto .L001DEC98
 *   cfg: kept branch: 0x1dec80 if (..) goto .L001DEC98
 *   cfg: kept branch: 0x1dec88 if (..) goto .L001DECA8
 *   cfg: kept branch: 0x1deca8 if (..) goto .L001DED68
 *   cfg: kept branch: 0x1deccc if (..) goto .L001DECF0
 *   cfg: kept branch: 0x1decd8 if (..) goto .L001DECF0
 *   cfg: kept branch: 0x1dece0 if (..) goto .L001DED00
 *   cfg: kept branch: 0x1ded00 if (..) goto .L001DED68
 *   cfg: kept branch: 0x1ded24 if (..) goto .L001DED48
 *   cfg: kept branch: 0x1ded30 if (..) goto .L001DED48
 *   cfg: kept branch: 0x1ded38 if (..) goto .L001DED58
 *   cfg: kept branch: 0x1ded58 if (..) goto .L001DED78
 *   cfg: kept goto: 0x1ded68 -> .L001DF0D0
 *   cfg: kept branch: 0x1ded8c if (..) goto .L001DEDB0
 *   cfg: kept branch: 0x1ded98 if (..) goto .L001DEDB0
 *   cfg: kept branch: 0x1deda0 if (..) goto .L001DEDC0
 *   cfg: kept branch: 0x1dedf4 if (..) goto .L001DEE18
 *   cfg: kept branch: 0x1dee00 if (..) goto .L001DEE18
 *   cfg: kept branch: 0x1dee08 if (..) goto .L001DEE28
 *   cfg: kept branch: 0x1dee4c if (..) goto .L001DEE70
 *   cfg: kept branch: 0x1dee58 if (..) goto .L001DEE70
 *   cfg: kept branch: 0x1dee60 if (..) goto .L001DEE80
 *   cfg: kept branch: 0x1dee80 if (..) goto .L001DEF90
 *   cfg: kept branch: 0x1deea4 if (..) goto .L001DEEC8
 *   cfg: kept branch: 0x1deeb0 if (..) goto .L001DEEC8
 *   cfg: kept branch: 0x1deeb8 if (..) goto .L001DEED8
 *   cfg: kept branch: 0x1deed8 if (..) goto .L001DEF90
 *   cfg: kept branch: 0x1deefc if (..) goto .L001DEF20
 *   cfg: kept branch: 0x1def08 if (..) goto .L001DEF20
 *   cfg: kept branch: 0x1def10 if (..) goto .L001DEF30
 *   cfg: kept branch: 0x1def30 if (..) goto .L001DEF90
 *   cfg: kept branch: 0x1def4c if (..) goto .L001DEF70
 *   cfg: kept branch: 0x1def58 if (..) goto .L001DEF70
 *   cfg: kept branch: 0x1def60 if (..) goto .L001DEF80
 *   cfg: kept branch: 0x1def80 if (..) goto .L001DEFA0
 *   cfg: kept goto: 0x1def90 -> .L001DF0D0
 *   cfg: kept branch: 0x1defb8 if (..) goto .L001DEFD8
 *   cfg: kept branch: 0x1defc4 if (..) goto .L001DEFD8
 *   cfg: kept branch: 0x1defcc if (..) goto .L001DEFE8
 *   cfg: kept branch: 0x1df00c if (..) goto .L001DF030
 *   cfg: kept branch: 0x1df018 if (..) goto .L001DF030
 *   cfg: kept branch: 0x1df020 if (..) goto .L001DF040
 *   cfg: kept branch: 0x1df040 if (..) goto .L001DF060
 *   cfg: kept goto: 0x1df050 -> .L001DF0D0
 *   cfg: kept branch: 0x1df1d8 if (..) goto .L001DF1F8
 *   cfg: kept branch: 0x1df1e4 if (..) goto .L001DF1F8
 *   cfg: kept branch: 0x1df1ec if (..) goto .L001DF208
 *   cfg: kept branch: 0x1df22c if (..) goto .L001DF250
 *   cfg: kept branch: 0x1df238 if (..) goto .L001DF250
 *   cfg: kept branch: 0x1df240 if (..) goto .L001DF260
 *   cfg: kept branch: 0x1df260 if (..) goto .L001DF370
 *   cfg: kept branch: 0x1df284 if (..) goto .L001DF2A8
 *   cfg: kept branch: 0x1df290 if (..) goto .L001DF2A8
 *   cfg: kept branch: 0x1df298 if (..) goto .L001DF2B8
 *   cfg: kept branch: 0x1df2b8 if (..) goto .L001DF370
 *   cfg: kept branch: 0x1df2dc if (..) goto .L001DF300
 *   cfg: kept branch: 0x1df2e8 if (..) goto .L001DF300
 *   cfg: kept branch: 0x1df2f0 if (..) goto .L001DF310
 *   cfg: kept branch: 0x1df310 if (..) goto .L001DF370
 *   cfg: kept branch: 0x1df32c if (..) goto .L001DF350
 *   cfg: kept branch: 0x1df338 if (..) goto .L001DF350
 *   cfg: kept branch: 0x1df340 if (..) goto .L001DF360
 *   cfg: kept branch: 0x1df398 if (..) goto .L001DF3B8
 *   cfg: kept branch: 0x1df3a4 if (..) goto .L001DF3B8
 *   cfg: kept branch: 0x1df3ac if (..) goto .L001DF3C8
 *   cfg: kept branch: 0x1df3ec if (..) goto .L001DF410
 *   cfg: kept branch: 0x1df3f8 if (..) goto .L001DF410
 *   cfg: kept branch: 0x1df400 if (..) goto .L001DF420
 *   cfg: kept branch: 0x1df420 if (..) goto .L001DF530
 *   cfg: kept branch: 0x1df444 if (..) goto .L001DF468
 *   cfg: kept branch: 0x1df450 if (..) goto .L001DF468
 *   cfg: kept branch: 0x1df458 if (..) goto .L001DF478
 *   cfg: kept branch: 0x1df478 if (..) goto .L001DF530
 *   cfg: kept branch: 0x1df49c if (..) goto .L001DF4C0
 *   cfg: kept branch: 0x1df4a8 if (..) goto .L001DF4C0
 *   cfg: kept branch: 0x1df4b0 if (..) goto .L001DF4D0
 *   cfg: kept branch: 0x1df4d0 if (..) goto .L001DF530
 *   cfg: kept branch: 0x1df4ec if (..) goto .L001DF510
 *   cfg: kept branch: 0x1df4f8 if (..) goto .L001DF510
 *   cfg: kept branch: 0x1df500 if (..) goto .L001DF520
 *   cfg: kept branch: 0x1df520 if (..) goto .L001DF540
 *   cfg: kept branch: 0x1df574 if (..) goto .L001DF598
 *   cfg: kept branch: 0x1df580 if (..) goto .L001DF598
 *   cfg: kept branch: 0x1df588 if (..) goto .L001DF5A8
 *   cfg: kept branch: 0x1df60c if (..) goto .L001DF630
 *   cfg: kept branch: 0x1df618 if (..) goto .L001DF630
 *   cfg: kept branch: 0x1df620 if (..) goto .L001DF640
 *   cfg: kept branch: 0x1df664 if (..) goto .L001DF688
 *   cfg: kept branch: 0x1df670 if (..) goto .L001DF688
 *   cfg: kept branch: 0x1df678 if (..) goto .L001DF698
 *   cfg: kept branch: 0x1df698 if (..) goto .L001DF7A8
 *   cfg: kept branch: 0x1df6bc if (..) goto .L001DF6E0
 *   cfg: kept branch: 0x1df6c8 if (..) goto .L001DF6E0
 *   cfg: kept branch: 0x1df6d0 if (..) goto .L001DF6F0
 *   cfg: kept branch: 0x1df6f0 if (..) goto .L001DF7A8
 *   cfg: kept branch: 0x1df714 if (..) goto .L001DF738
 *   cfg: kept branch: 0x1df720 if (..) goto .L001DF738
 *   cfg: kept branch: 0x1df728 if (..) goto .L001DF748
 *   cfg: kept branch: 0x1df748 if (..) goto .L001DF7A8
 *   cfg: kept branch: 0x1df764 if (..) goto .L001DF788
 *   cfg: kept branch: 0x1df770 if (..) goto .L001DF788
 *   cfg: kept branch: 0x1df778 if (..) goto .L001DF798
 *   cfg: kept branch: 0x1df798 if (..) goto .L001DF7B8
 *   cfg: kept branch: 0x1df8d0 if (..) goto .L001DF8F0
 *   cfg: kept branch: 0x1df8dc if (..) goto .L001DF8F0
 *   cfg: kept branch: 0x1df8e4 if (..) goto .L001DF900
 *   cfg: kept branch: 0x1df924 if (..) goto .L001DF948
 *   cfg: kept branch: 0x1df930 if (..) goto .L001DF948
 *   cfg: kept branch: 0x1df938 if (..) goto .L001DF958
 *   cfg: kept branch: 0x1df958 if (..) goto .L001DFA68
 *   cfg: kept branch: 0x1df97c if (..) goto .L001DF9A0
 *   cfg: kept branch: 0x1df988 if (..) goto .L001DF9A0
 *   cfg: kept branch: 0x1df990 if (..) goto .L001DF9B0
 *   cfg: kept branch: 0x1df9b0 if (..) goto .L001DFA68
 *   cfg: kept branch: 0x1df9d4 if (..) goto .L001DF9F8
 *   cfg: kept branch: 0x1df9e0 if (..) goto .L001DF9F8
 *   cfg: kept branch: 0x1df9e8 if (..) goto .L001DFA08
 *   cfg: kept branch: 0x1dfa08 if (..) goto .L001DFA68
 *   cfg: kept branch: 0x1dfa24 if (..) goto .L001DFA48
 *   cfg: kept branch: 0x1dfa30 if (..) goto .L001DFA48
 *   cfg: kept branch: 0x1dfa38 if (..) goto .L001DFA58
 *   cfg: kept branch: 0x1dfaac if (..) goto .L001DFAD0
 *   cfg: kept branch: 0x1dfab8 if (..) goto .L001DFAD0
 *   cfg: kept branch: 0x1dfac0 if (..) goto .L001DFAE0
 *   cfg: kept branch: 0x1dfae0 if (..) goto .L001DFB08
 *   cfg: kept branch: 0x1dfb44 if (..) goto .L001DFB68
 *   cfg: kept branch: 0x1dfb50 if (..) goto .L001DFB68
 *   cfg: kept branch: 0x1dfb58 if (..) goto .L001DFB78
 *   cfg: kept branch: 0x1dfb9c if (..) goto .L001DFBC0
 *   cfg: kept branch: 0x1dfba8 if (..) goto .L001DFBC0
 *   cfg: kept branch: 0x1dfbb0 if (..) goto .L001DFBD0
 *   cfg: kept branch: 0x1dfbd0 if (..) goto .L001DFCE0
 *   cfg: kept branch: 0x1dfbf4 if (..) goto .L001DFC18
 *   cfg: kept branch: 0x1dfc00 if (..) goto .L001DFC18
 *   cfg: kept branch: 0x1dfc08 if (..) goto .L001DFC28
 *   cfg: kept branch: 0x1dfc28 if (..) goto .L001DFCE0
 *   cfg: kept branch: 0x1dfc4c if (..) goto .L001DFC70
 *   cfg: kept branch: 0x1dfc58 if (..) goto .L001DFC70
 *   cfg: kept branch: 0x1dfc60 if (..) goto .L001DFC80
 *   cfg: kept branch: 0x1dfc80 if (..) goto .L001DFCE0
 *   cfg: kept branch: 0x1dfc9c if (..) goto .L001DFCC0
 *   cfg: kept branch: 0x1dfca8 if (..) goto .L001DFCC0
 *   cfg: kept branch: 0x1dfcb0 if (..) goto .L001DFCD0
 *   cfg: kept branch: 0x1dfcd0 if (..) goto .L001DFCF0
 *   cfg: kept branch: 0x1dfd08 if (..) goto .L001DFD28
 *   cfg: kept branch: 0x1dfd14 if (..) goto .L001DFD28
 *   cfg: kept branch: 0x1dfd1c if (..) goto .L001DFD38
 *   cfg: kept branch: 0x1dfd5c if (..) goto .L001DFD80
 *   cfg: kept branch: 0x1dfd68 if (..) goto .L001DFD80
 *   cfg: kept branch: 0x1dfd70 if (..) goto .L001DFD90
 *   cfg: kept branch: 0x1dfd90 if (..) goto .L001DFDB0
 *   cfg: kept branch: 0x1dfeb8 if (..) goto .L001DFED8
 *   cfg: kept branch: 0x1dfec4 if (..) goto .L001DFED8
 *   cfg: kept branch: 0x1dfecc if (..) goto .L001DFEE8
 *   cfg: kept branch: 0x1dff0c if (..) goto .L001DFF30
 *   cfg: kept branch: 0x1dff18 if (..) goto .L001DFF30
 *   cfg: kept branch: 0x1dff20 if (..) goto .L001DFF40
 *   cfg: kept branch: 0x1dff40 if (..) goto .L001E0050
 *   cfg: kept branch: 0x1dff64 if (..) goto .L001DFF88
 *   cfg: kept branch: 0x1dff70 if (..) goto .L001DFF88
 *   cfg: kept branch: 0x1dff78 if (..) goto .L001DFF98
 *   cfg: kept branch: 0x1dff98 if (..) goto .L001E0050
 *   cfg: kept branch: 0x1dffbc if (..) goto .L001DFFE0
 *   cfg: kept branch: 0x1dffc8 if (..) goto .L001DFFE0
 *   cfg: kept branch: 0x1dffd0 if (..) goto .L001DFFF0
 *   cfg: kept branch: 0x1dfff0 if (..) goto .L001E0050
 *   cfg: kept branch: 0x1e000c if (..) goto .L001E0030
 *   cfg: kept branch: 0x1e0018 if (..) goto .L001E0030
 *   cfg: kept branch: 0x1e0020 if (..) goto .L001E0040
 *   cfg: kept branch: 0x1e00a4 if (..) goto .L001E00C8
 *   cfg: kept branch: 0x1e00b0 if (..) goto .L001E00C8
 *   cfg: kept branch: 0x1e00b8 if (..) goto .L001E00D8
 *   cfg: kept branch: 0x1e00fc if (..) goto .L001E0120
 *   cfg: kept branch: 0x1e0108 if (..) goto .L001E0120
 *   cfg: kept branch: 0x1e0110 if (..) goto .L001E0130
 *   cfg: kept branch: 0x1e0130 if (..) goto .L001E0240
 *   cfg: kept branch: 0x1e0154 if (..) goto .L001E0178
 *   cfg: kept branch: 0x1e0160 if (..) goto .L001E0178
 *   cfg: kept branch: 0x1e0168 if (..) goto .L001E0188
 *   cfg: kept branch: 0x1e0188 if (..) goto .L001E0240
 *   cfg: kept branch: 0x1e01ac if (..) goto .L001E01D0
 *   cfg: kept branch: 0x1e01b8 if (..) goto .L001E01D0
 *   cfg: kept branch: 0x1e01c0 if (..) goto .L001E01E0
 *   cfg: kept branch: 0x1e01e0 if (..) goto .L001E0240
 *   cfg: kept branch: 0x1e01fc if (..) goto .L001E0220
 *   cfg: kept branch: 0x1e0208 if (..) goto .L001E0220
 *   cfg: kept branch: 0x1e0210 if (..) goto .L001E0230
 *   cfg: kept branch: 0x1e0230 if (..) goto .L001E0250
 *   cfg: kept branch: 0x1e02f0 if (..) goto .L001E0310
 *   cfg: kept branch: 0x1e02fc if (..) goto .L001E0310
 *   cfg: kept branch: 0x1e0304 if (..) goto .L001E0320
 *   cfg: kept branch: 0x1e0344 if (..) goto .L001E0368
 *   cfg: kept branch: 0x1e0350 if (..) goto .L001E0368
 *   cfg: kept branch: 0x1e0358 if (..) goto .L001E0378
 *   cfg: kept branch: 0x1e0378 if (..) goto .L001E0488
 *   cfg: kept branch: 0x1e039c if (..) goto .L001E03C0
 *   cfg: kept branch: 0x1e03a8 if (..) goto .L001E03C0
 *   cfg: kept branch: 0x1e03b0 if (..) goto .L001E03D0
 *   cfg: kept branch: 0x1e03d0 if (..) goto .L001E0488
 *   cfg: kept branch: 0x1e03f4 if (..) goto .L001E0418
 *   cfg: kept branch: 0x1e0400 if (..) goto .L001E0418
 *   cfg: kept branch: 0x1e0408 if (..) goto .L001E0428
 *   cfg: kept branch: 0x1e0428 if (..) goto .L001E0488
 *   cfg: kept branch: 0x1e0444 if (..) goto .L001E0468
 *   cfg: kept branch: 0x1e0450 if (..) goto .L001E0468
 *   cfg: kept branch: 0x1e0458 if (..) goto .L001E0478
 *   cfg: kept branch: 0x1e04cc if (..) goto .L001E04F0
 *   cfg: kept branch: 0x1e04d8 if (..) goto .L001E04F0
 *   cfg: kept branch: 0x1e04e0 if (..) goto .L001E0500
 *   cfg: kept branch: 0x1e0500 if (..) goto .L001E0540
 *   cfg: kept branch: 0x1e057c if (..) goto .L001E05A0
 *   cfg: kept branch: 0x1e0588 if (..) goto .L001E05A0
 *   cfg: kept branch: 0x1e0590 if (..) goto .L001E05B0
 *   cfg: kept branch: 0x1e05d4 if (..) goto .L001E05F8
 *   cfg: kept branch: 0x1e05e0 if (..) goto .L001E05F8
 *   cfg: kept branch: 0x1e05e8 if (..) goto .L001E0608
 *   cfg: kept branch: 0x1e0608 if (..) goto .L001E0718
 *   cfg: kept branch: 0x1e062c if (..) goto .L001E0650
 *   cfg: kept branch: 0x1e0638 if (..) goto .L001E0650
 *   cfg: kept branch: 0x1e0640 if (..) goto .L001E0660
 *   cfg: kept branch: 0x1e0660 if (..) goto .L001E0718
 *   cfg: kept branch: 0x1e0684 if (..) goto .L001E06A8
 *   cfg: kept branch: 0x1e0690 if (..) goto .L001E06A8
 *   cfg: kept branch: 0x1e0698 if (..) goto .L001E06B8
 *   cfg: kept branch: 0x1e06b8 if (..) goto .L001E0718
 *   cfg: kept branch: 0x1e06d4 if (..) goto .L001E06F8
 *   cfg: kept branch: 0x1e06e0 if (..) goto .L001E06F8
 *   cfg: kept branch: 0x1e06e8 if (..) goto .L001E0708
 *   cfg: kept branch: 0x1e0708 if (..) goto .L001E0728
 *   cfg: kept branch: 0x1e0740 if (..) goto .L001E0760
 *   cfg: kept branch: 0x1e074c if (..) goto .L001E0760
 *   cfg: kept branch: 0x1e0754 if (..) goto .L001E0770
 *   cfg: kept branch: 0x1e0794 if (..) goto .L001E07B8
 *   cfg: kept branch: 0x1e07a0 if (..) goto .L001E07B8
 *   cfg: kept branch: 0x1e07a8 if (..) goto .L001E07C8
 *   cfg: kept branch: 0x1e07c8 if (..) goto .L001E07E8
 *   cfg: kept branch: 0x1e08f0 if (..) goto .L001E0910
 *   cfg: kept branch: 0x1e08fc if (..) goto .L001E0910
 *   cfg: kept branch: 0x1e0904 if (..) goto .L001E0920
 *   cfg: kept branch: 0x1e0944 if (..) goto .L001E0968
 *   cfg: kept branch: 0x1e0950 if (..) goto .L001E0968
 *   cfg: kept branch: 0x1e0958 if (..) goto .L001E0978
 *   cfg: kept branch: 0x1e0978 if (..) goto .L001E0A88
 *   cfg: kept branch: 0x1e099c if (..) goto .L001E09C0
 *   cfg: kept branch: 0x1e09a8 if (..) goto .L001E09C0
 *   cfg: kept branch: 0x1e09b0 if (..) goto .L001E09D0
 *   cfg: kept branch: 0x1e09d0 if (..) goto .L001E0A88
 *   cfg: kept branch: 0x1e09f4 if (..) goto .L001E0A18
 *   cfg: kept branch: 0x1e0a00 if (..) goto .L001E0A18
 *   cfg: kept branch: 0x1e0a08 if (..) goto .L001E0A28
 *   cfg: kept branch: 0x1e0a28 if (..) goto .L001E0A88
 *   cfg: kept branch: 0x1e0a44 if (..) goto .L001E0A68
 *   cfg: kept branch: 0x1e0a50 if (..) goto .L001E0A68
 *   cfg: kept branch: 0x1e0a58 if (..) goto .L001E0A78
 *   cfg: kept branch: 0x1e0af4 if (..) goto .L001E0B18
 *   cfg: kept branch: 0x1e0b00 if (..) goto .L001E0B18
 *   cfg: kept branch: 0x1e0b08 if (..) goto .L001E0B28
 *   cfg: kept branch: 0x1e0b4c if (..) goto .L001E0B70
 *   cfg: kept branch: 0x1e0b58 if (..) goto .L001E0B70
 *   cfg: kept branch: 0x1e0b60 if (..) goto .L001E0B80
 *   cfg: kept branch: 0x1e0b80 if (..) goto .L001E0C90
 *   cfg: kept branch: 0x1e0ba4 if (..) goto .L001E0BC8
 *   cfg: kept branch: 0x1e0bb0 if (..) goto .L001E0BC8
 *   cfg: kept branch: 0x1e0bb8 if (..) goto .L001E0BD8
 *   cfg: kept branch: 0x1e0bd8 if (..) goto .L001E0C90
 *   cfg: kept branch: 0x1e0bfc if (..) goto .L001E0C20
 *   cfg: kept branch: 0x1e0c08 if (..) goto .L001E0C20
 *   cfg: kept branch: 0x1e0c10 if (..) goto .L001E0C30
 *   cfg: kept branch: 0x1e0c30 if (..) goto .L001E0C90
 *   cfg: kept branch: 0x1e0c4c if (..) goto .L001E0C70
 *   cfg: kept branch: 0x1e0c58 if (..) goto .L001E0C70
 *   cfg: kept branch: 0x1e0c60 if (..) goto .L001E0C80
 *   cfg: kept branch: 0x1e0c80 if (..) goto .L001E0CA0
 *   cfg: kept branch: 0x1e0d0c if (..) goto .L001E0D30
 *   cfg: kept branch: 0x1e0d18 if (..) goto .L001E0D30
 *   cfg: kept branch: 0x1e0d20 if (..) goto .L001E0D40
 *   cfg: kept branch: 0x1e0d64 if (..) goto .L001E0D88
 *   cfg: kept branch: 0x1e0d70 if (..) goto .L001E0D88
 *   cfg: kept branch: 0x1e0d78 if (..) goto .L001E0D98
 *   cfg: kept branch: 0x1e0d98 if (..) goto .L001E0EA8
 *   cfg: kept branch: 0x1e0dbc if (..) goto .L001E0DE0
 *   cfg: kept branch: 0x1e0dc8 if (..) goto .L001E0DE0
 *   cfg: kept branch: 0x1e0dd0 if (..) goto .L001E0DF0
 *   cfg: kept branch: 0x1e0df0 if (..) goto .L001E0EA8
 *   cfg: kept branch: 0x1e0e14 if (..) goto .L001E0E38
 *   cfg: kept branch: 0x1e0e20 if (..) goto .L001E0E38
 *   cfg: kept branch: 0x1e0e28 if (..) goto .L001E0E48
 *   cfg: kept branch: 0x1e0e48 if (..) goto .L001E0EA8
 *   cfg: kept branch: 0x1e0e64 if (..) goto .L001E0E88
 *   cfg: kept branch: 0x1e0e70 if (..) goto .L001E0E88
 *   cfg: kept branch: 0x1e0e78 if (..) goto .L001E0E98
 *   cfg: kept branch: 0x1e0e98 if (..) goto .L001E0EB8
 *   cfg: kept branch: 0x1e0fd8 if (..) goto .L001E0FF8
 *   cfg: kept branch: 0x1e0fe4 if (..) goto .L001E0FF8
 *   cfg: kept branch: 0x1e0fec if (..) goto .L001E1008
 *   cfg: kept branch: 0x1e102c if (..) goto .L001E1050
 *   cfg: kept branch: 0x1e1038 if (..) goto .L001E1050
 *   cfg: kept branch: 0x1e1040 if (..) goto .L001E1060
 *   cfg: kept branch: 0x1e1060 if (..) goto .L001E1170
 *   cfg: kept branch: 0x1e1084 if (..) goto .L001E10A8
 *   cfg: kept branch: 0x1e1090 if (..) goto .L001E10A8
 *   cfg: kept branch: 0x1e1098 if (..) goto .L001E10B8
 *   cfg: kept branch: 0x1e10b8 if (..) goto .L001E1170
 *   cfg: kept branch: 0x1e10dc if (..) goto .L001E1100
 *   cfg: kept branch: 0x1e10e8 if (..) goto .L001E1100
 *   cfg: kept branch: 0x1e10f0 if (..) goto .L001E1110
 *   cfg: kept branch: 0x1e1110 if (..) goto .L001E1170
 *   cfg: kept branch: 0x1e112c if (..) goto .L001E1150
 *   cfg: kept branch: 0x1e1138 if (..) goto .L001E1150
 *   cfg: kept branch: 0x1e1140 if (..) goto .L001E1160
 *   cfg: kept branch: 0x1e11c4 if (..) goto .L001E11E8
 *   cfg: kept branch: 0x1e11d0 if (..) goto .L001E11E8
 *   cfg: kept branch: 0x1e11d8 if (..) goto .L001E11F8
 *   cfg: kept branch: 0x1e121c if (..) goto .L001E1240
 *   cfg: kept branch: 0x1e1228 if (..) goto .L001E1240
 *   cfg: kept branch: 0x1e1230 if (..) goto .L001E1250
 *   cfg: kept branch: 0x1e1250 if (..) goto .L001E1360
 *   cfg: kept branch: 0x1e1274 if (..) goto .L001E1298
 *   cfg: kept branch: 0x1e1280 if (..) goto .L001E1298
 *   cfg: kept branch: 0x1e1288 if (..) goto .L001E12A8
 *   cfg: kept branch: 0x1e12a8 if (..) goto .L001E1360
 *   cfg: kept branch: 0x1e12cc if (..) goto .L001E12F0
 *   cfg: kept branch: 0x1e12d8 if (..) goto .L001E12F0
 *   cfg: kept branch: 0x1e12e0 if (..) goto .L001E1300
 *   cfg: kept branch: 0x1e1300 if (..) goto .L001E1360
 *   cfg: kept branch: 0x1e131c if (..) goto .L001E1340
 *   cfg: kept branch: 0x1e1328 if (..) goto .L001E1340
 *   cfg: kept branch: 0x1e1330 if (..) goto .L001E1350
 *   cfg: kept branch: 0x1e1350 if (..) goto .L001E1370
 *   cfg: kept branch: 0x1e13f8 if (..) goto .L001E1418
 *   cfg: kept branch: 0x1e1404 if (..) goto .L001E1418
 *   cfg: kept branch: 0x1e140c if (..) goto .L001E1428
 *   cfg: kept branch: 0x1e144c if (..) goto .L001E1470
 *   cfg: kept branch: 0x1e1458 if (..) goto .L001E1470
 *   cfg: kept branch: 0x1e1460 if (..) goto .L001E1480
 *   cfg: kept branch: 0x1e1480 if (..) goto .L001E1590
 *   cfg: kept branch: 0x1e14a4 if (..) goto .L001E14C8
 *   cfg: kept branch: 0x1e14b0 if (..) goto .L001E14C8
 *   cfg: kept branch: 0x1e14b8 if (..) goto .L001E14D8
 *   cfg: kept branch: 0x1e14d8 if (..) goto .L001E1590
 *   cfg: kept branch: 0x1e14fc if (..) goto .L001E1520
 *   cfg: kept branch: 0x1e1508 if (..) goto .L001E1520
 *   cfg: kept branch: 0x1e1510 if (..) goto .L001E1530
 *   cfg: kept branch: 0x1e1530 if (..) goto .L001E1590
 *   cfg: kept branch: 0x1e154c if (..) goto .L001E1570
 *   cfg: kept branch: 0x1e1558 if (..) goto .L001E1570
 *   cfg: kept branch: 0x1e1560 if (..) goto .L001E1580
 *   cfg: kept branch: 0x1e15d0 if (..) goto .L001E15F0
 *   cfg: kept branch: 0x1e15dc if (..) goto .L001E15F0
 *   cfg: kept branch: 0x1e15e4 if (..) goto .L001E1600
 *   cfg: kept branch: 0x1e1600 if (..) goto .L001E1630
 *   cfg: kept branch: 0x1e1664 if (..) goto .L001E1688
 *   cfg: kept branch: 0x1e1670 if (..) goto .L001E1688
 *   cfg: kept branch: 0x1e1678 if (..) goto .L001E1698
 *   cfg: kept branch: 0x1e16bc if (..) goto .L001E16E0
 *   cfg: kept branch: 0x1e16c8 if (..) goto .L001E16E0
 *   cfg: kept branch: 0x1e16d0 if (..) goto .L001E16F0
 *   cfg: kept branch: 0x1e16f0 if (..) goto .L001E1800
 *   cfg: kept branch: 0x1e1714 if (..) goto .L001E1738
 *   cfg: kept branch: 0x1e1720 if (..) goto .L001E1738
 *   cfg: kept branch: 0x1e1728 if (..) goto .L001E1748
 *   cfg: kept branch: 0x1e1748 if (..) goto .L001E1800
 *   cfg: kept branch: 0x1e176c if (..) goto .L001E1790
 *   cfg: kept branch: 0x1e1778 if (..) goto .L001E1790
 *   cfg: kept branch: 0x1e1780 if (..) goto .L001E17A0
 *   cfg: kept branch: 0x1e17a0 if (..) goto .L001E1800
 *   cfg: kept branch: 0x1e17bc if (..) goto .L001E17E0
 *   cfg: kept branch: 0x1e17c8 if (..) goto .L001E17E0
 *   cfg: kept branch: 0x1e17d0 if (..) goto .L001E17F0
 *   cfg: kept branch: 0x1e17f0 if (..) goto .L001E1810
 *   cfg: kept branch: 0x1e18b8 if (..) goto .L001E18D8
 *   cfg: kept branch: 0x1e18c4 if (..) goto .L001E18D8
 *   cfg: kept branch: 0x1e18cc if (..) goto .L001E18E8
 *   cfg: kept branch: 0x1e190c if (..) goto .L001E1930
 *   cfg: kept branch: 0x1e1918 if (..) goto .L001E1930
 *   cfg: kept branch: 0x1e1920 if (..) goto .L001E1940
 *   cfg: kept branch: 0x1e1940 if (..) goto .L001E1A50
 *   cfg: kept branch: 0x1e1964 if (..) goto .L001E1988
 *   cfg: kept branch: 0x1e1970 if (..) goto .L001E1988
 *   cfg: kept branch: 0x1e1978 if (..) goto .L001E1998
 *   cfg: kept branch: 0x1e1998 if (..) goto .L001E1A50
 *   cfg: kept branch: 0x1e19bc if (..) goto .L001E19E0
 *   cfg: kept branch: 0x1e19c8 if (..) goto .L001E19E0
 *   cfg: kept branch: 0x1e19d0 if (..) goto .L001E19F0
 *   cfg: kept branch: 0x1e19f0 if (..) goto .L001E1A50
 *   cfg: kept branch: 0x1e1a0c if (..) goto .L001E1A30
 *   cfg: kept branch: 0x1e1a18 if (..) goto .L001E1A30
 *   cfg: kept branch: 0x1e1a20 if (..) goto .L001E1A40
 *   cfg: kept branch: 0x1e1a40 if (..) goto .L001E1A60
 *   cfg: kept branch: 0x1e1b88 if (..) goto .L001E1BA8
 *   cfg: kept branch: 0x1e1b94 if (..) goto .L001E1BA8
 *   cfg: kept branch: 0x1e1b9c if (..) goto .L001E1BB8
 *   cfg: kept branch: 0x1e1bdc if (..) goto .L001E1C00
 *   cfg: kept branch: 0x1e1be8 if (..) goto .L001E1C00
 *   cfg: kept branch: 0x1e1bf0 if (..) goto .L001E1C10
 *   cfg: kept branch: 0x1e1c10 if (..) goto .L001E1D20
 *   cfg: kept branch: 0x1e1c34 if (..) goto .L001E1C58
 *   cfg: kept branch: 0x1e1c40 if (..) goto .L001E1C58
 *   cfg: kept branch: 0x1e1c48 if (..) goto .L001E1C68
 *   cfg: kept branch: 0x1e1c68 if (..) goto .L001E1D20
 *   cfg: kept branch: 0x1e1c8c if (..) goto .L001E1CB0
 *   cfg: kept branch: 0x1e1c98 if (..) goto .L001E1CB0
 *   cfg: kept branch: 0x1e1ca0 if (..) goto .L001E1CC0
 *   cfg: kept branch: 0x1e1cc0 if (..) goto .L001E1D20
 *   cfg: kept branch: 0x1e1cdc if (..) goto .L001E1D00
 *   cfg: kept branch: 0x1e1ce8 if (..) goto .L001E1D00
 *   cfg: kept branch: 0x1e1cf0 if (..) goto .L001E1D10
 *   cfg: kept branch: 0x1e1d10 if (..) goto .L001E1D30
 *   cfg: kept branch: 0x1e1d48 if (..) goto .L001E1D68
 *   cfg: kept branch: 0x1e1d54 if (..) goto .L001E1D68
 *   cfg: kept branch: 0x1e1d5c if (..) goto .L001E1D78
 *   cfg: kept branch: 0x1e1fd4 if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e1fdc if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e1fe8 if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e1ff0 if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e1ffc if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e2004 if (..) goto .L001E20C0
 *   cfg: kept branch: 0x1e2010 if (..) goto .L001E20C0
 *   cfg: kept goto: 0x1e201c -> .L001E2058
 *   cfg: kept branch: 0x1e2028 if (..) goto .L001E20C0
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 MemoryCardProc();
extern signed int ExistSaveData(signed int);
extern signed int ItemMng_Add_Direct(unsigned short, signed short);
extern u32 L10293[];

#ifndef PROTO_DW_2298180_FIELDS
#define PROTO_DW_2298180_FIELDS
struct dw_2298180_fields { unsigned char state[2]; unsigned char mode_[2]; unsigned char checking_port; unsigned char checking_port_ok; unsigned char data_index; unsigned char list_ok; unsigned char checking_on; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED = (int)&(((struct dw_2298180_fields *)0)->checking_on) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 = (int)&(((struct dw_2298180_fields *)0)->checking_port) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B = (int)&(((struct dw_2298180_fields *)0)->data_index) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9_DEFINED
#define DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 = (int)&(((struct dw_2298180_fields *)0)->state[0]) - 0 };
#endif


/* MI_Evrfrm_GoTtl @ 0x1DD990 .. 0x1DDAB4 (0x124 bytes, frame 0x400) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x10 escapes at 0x1dda38
 *   stack: address of the slot at 0x10 escapes at 0x1dda4c
 */

extern void SetGoToTitleFlag(void);



/* MI_Evrfrm_HelpStr @ 0x1DCDA0 .. 0x1DD8C4 (0xb24 bytes, frame 0x50) */
extern int sprintf(char *, const char *, ...);
extern u32 Menu_GetMovementHelpId();
extern u8 aTmpHelpStr2[];
extern u8 aTmpHelpStr[];



/* MI_Evrfrm_BtnGuide @ 0x1DC8B0 .. 0x1DCD04 (0x454 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   literal: @7618 -> 0x255f90
 *   literal: @6503 is the string ''
 *   indirect: jr v1 at 0x1dc90c -> <v1>
 *   stack: address of the slot at 0x70 escapes at 0x1dc91c
 *   delay: addiu at 0x1dc9a8 writes a register its branch at 0x1dc9a4 reads
 *   delay: addiu at 0x1dc9bc writes a register its branch at 0x1dc9b8 reads
 *   delay: addiu at 0x1dc9d0 writes a register its branch at 0x1dc9cc reads
 *   delay: addiu at 0x1dc9f4 writes a register its branch at 0x1dc9f0 reads
 *   delay: addiu at 0x1dca08 writes a register its branch at 0x1dca04 reads
 *   delay: addiu at 0x1dca30 writes a register its branch at 0x1dca2c reads
 *   delay: lui at 0x1dca68 writes a register its branch at 0x1dca64 reads
 *   delay: lui at 0x1dcaac writes a register its branch at 0x1dcaa8 reads
 *   stack: address of the slot at 0x70 escapes at 0x1dcb98
 *   delay: lui at 0x1dcbb4 writes a register its branch at 0x1dcbb0 reads
 *   cfg: kept branch: 0x1dca30 if (..) goto .L001DCA58
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern unsigned short ItemMng_GetDocumentPageNum(unsigned short);
extern int sprintf(char *, const char *, ...);
extern u32 aTmpBtnGuide[];
extern u32 L7618[];


struct TexCEnt { s32 id; s32 pad0[6]; s32 w[35]; };



/* Menu_ReLoadSetTex @ 0x1DBB60 .. 0x1DC0E0 (0x580 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   literal: @7235 -> 0x255f70
 *   literal: @7233 is the string 'menu/tex/map/map_nashi.tex'
 *   literal: @7234 is the string 'map_nashi.t32'
 *   indirect: jr v0 at 0x1dbc38 -> <v0>
 *   delay: addiu at 0x1dbcdc writes a register its branch at 0x1dbcd8 reads
 *   cfg: loop body is not one contiguous region: .L001DBB98
 *   cfg: kept branch: 0x1dbb98 if (..) goto .L001DBBB0
 *   cfg: kept goto: 0x1dbba4 -> .L001DBBC8
 *   cfg: loop body is not one contiguous region: .L001DBD28
 *   cfg: kept branch: 0x1dbd28 if (..) goto .L001DBD58
 *   cfg: kept goto: 0x1dbd34 -> .L001DBD70
 *   cfg: loop body is not one contiguous region: .L001DBDD8
 *   cfg: kept branch: 0x1dbdd8 if (..) goto .L001DBE08
 *   cfg: kept goto: 0x1dbde4 -> .L001DBE20
 *   cfg: loop body is not one contiguous region: .L001DBE30
 *   cfg: kept branch: 0x1dbe30 if (..) goto .L001DBE60
 *   cfg: kept goto: 0x1dbe3c -> .L001DBE78
 *   cfg: loop body is not one contiguous region: .L001DBEA0
 *   cfg: kept branch: 0x1dbea0 if (..) goto .L001DBED0
 *   cfg: kept goto: 0x1dbeac -> .L001DBEE8
 *   cfg: loop body is not one contiguous region: .L001DBEF8
 *   cfg: kept branch: 0x1dbef8 if (..) goto .L001DBF28
 *   cfg: kept goto: 0x1dbf04 -> .L001DBF40
 *   cfg: loop body is not one contiguous region: .L001DBFA0
 *   cfg: kept branch: 0x1dbfa0 if (..) goto .L001DBFD0
 *   cfg: kept goto: 0x1dbfac -> .L001DBFE8
 *   cfg: loop body is not one contiguous region: .L001DBFF8
 *   cfg: kept branch: 0x1dbff8 if (..) goto .L001DC028
 *   cfg: kept goto: 0x1dc004 -> .L001DC040
 *   cfg: loop body is not one contiguous region: .L001DC050
 *   cfg: kept branch: 0x1dc050 if (..) goto .L001DC080
 *   cfg: kept goto: 0x1dc05c -> .L001DC098
 *   a2 typed from the Menu_ReLoadSetTex call table
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void FlushCache(int);
extern void ReadTexList(char *, void **, signed int, signed int);
extern int FileCheckAsyncBusy(void);
extern void FileBackReadControl();
extern u32 L7235[];

struct TexIdEnt3 { s32 v[7]; u8 pad0[0x24]; s32 f40; s32 f44; char name48[0x40]; char name88[0x20]; };


static signed int Menu_ReLoadSetTex(int, int);
extern void Menu_SetMmCamPos(signed int, signed int, signed int);



/* MI_Evrfrm_MapTex @ 0x1DB440 .. 0x1DBA3C (0x5fc bytes, frame 0x50) */
/*
 * dcomp notes:
 *   literal: @7015 -> 0x255f20
 *   literal: @7016 -> 0x255f00
 *   literal: @6503 is the string ''
 *   indirect: jr v1 at 0x1db47c -> <v1>
 *   indirect: jr v1 at 0x1db890 -> <v1>
 *   delay: addiu at 0x1dba14 writes a register its branch at 0x1dba10 reads
 *   cfg: loop body is not one contiguous region: .L001DB748
 *   cfg: kept branch: 0x1db748 if (..) goto .L001DB778
 *   cfg: kept goto: 0x1db754 -> .L001DB790
 *   cfg: loop body is not one contiguous region: .L001DB7F0
 *   cfg: kept branch: 0x1db7f0 if (..) goto .L001DB808
 *   cfg: kept goto: 0x1db7fc -> .L001DB820
 *   cfg: loop body is not one contiguous region: .L001DB8C8
 *   cfg: kept branch: 0x1db8c8 if (..) goto .L001DB8E0
 *   cfg: kept goto: 0x1db8d4 -> .L001DB8F8
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern signed int KnMenuMng_CheckCtrlPlayWait(int, signed int);
extern u32 Menu_TD_IsPlay();
extern u32 Menu_CheckMapMove();
extern u32 lpPadData;
extern u8 s_menu_map_name[];
extern u32 L7015[];
extern u32 L7016[];

enum MI_Evrfrm_MapTex__sel { MI_Evrfrm_MapTex__sel_0, MI_Evrfrm_MapTex__sel_1 };

#ifndef PROTO_DW_2299119_FIELDS
#define PROTO_DW_2299119_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PADPORT_51A19403_DEFINED
#define DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PADPORT_51A19403_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PADPORT_51A19403 = (int)&(((struct dw_2299119_fields *)0)->padport) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820_DEFINED
#define DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820 = (int)&(((struct dw_2299119_fields *)0)->sceneNo) - 0 };
#endif

struct MapTexEnt { s32 v[7]; s32 w[8]; u8 pad[0x6c]; };



/* MI_Check_MapTex @ 0x1DAE50 .. 0x1DB42C (0x5dc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @6753 -> 0x255ee0
 *   literal: @6754 -> 0x255ec0
 *   literal: @6755 -> 0x255ea0
 *   literal: @6756 -> 0x255e80
 *   delay: addiu at 0x1dae78 writes a register its branch at 0x1dae74 reads
 *   delay: addiu at 0x1dae8c writes a register its branch at 0x1dae88 reads
 *   indirect: jr v1 at 0x1daf98 -> <v1>
 *   indirect: jr v1 at 0x1db0e0 -> <v1>
 *   indirect: jr v1 at 0x1db228 -> <v1>
 *   indirect: jr v1 at 0x1db370 -> <v1>
 *   cfg: loop body is not one contiguous region: .L001DAEF8
 *   cfg: kept branch: 0x1daef8 if (..) goto .L001DAF10
 *   cfg: kept goto: 0x1daf04 -> .L001DAF28
 *   cfg: loop body is not one contiguous region: .L001DB040
 *   cfg: kept branch: 0x1db040 if (..) goto .L001DB058
 *   cfg: kept goto: 0x1db04c -> .L001DB070
 *   cfg: loop body is not one contiguous region: .L001DB188
 *   cfg: kept branch: 0x1db188 if (..) goto .L001DB1A0
 *   cfg: kept goto: 0x1db194 -> .L001DB1B8
 *   cfg: loop body is not one contiguous region: .L001DB2D0
 *   cfg: kept branch: 0x1db2d0 if (..) goto .L001DB2E8
 *   cfg: kept goto: 0x1db2dc -> .L001DB300
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern u32 Menu_CheckMapMove();
extern u32 L6753[];
extern u32 L6754[];
extern u32 L6755[];
extern u32 L6756[];

struct TexIdEnt { s32 v[7]; u8 pad[0x8c]; };



extern u32 abs();
extern u32 Menu_TD_IsPlay();
extern u32 lpPadData;

struct PadK { u8 pad0[2]; u8 c2_0:1, c2_1:1, c2_2:1, c2_3:1, c2_4:1, c2_5:1, c2_6:1, c2_7:1; u8 pad1[3]; u8 x; u8 y; u8 pad2[24]; u8 a0:1, a1:1, a2:1, a3:1, a4:1, a5:1, a6:1, a7:1; u8 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1; u8 d0:1, d1:1, d2:1, d3:1, d4:1, d5:1, d6:1, d7:1; };
#define STICK_SET(n) \
    if (s_stick_udlr_old != (n) || (u32)s_stick_cursol_on == 0) { \
        s_stick_udlr = (n); \
        s_stick_cursol_on = 0xa; \
    }
#define KEY_PLAIN(bit) \
        if ((bit) == 0 || s_DialogUseCounter != 0) { goto fail; } \
        if (Menu_TD_IsPlay() != 0) { goto fail; } \
        ret = 1; \
        break;



/* Memu_CtrlFunc @ 0x1D9F80 .. 0x1DA774 (0x7f4 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   literal: @6323 -> 0x255e00
 *   literal: @6324 -> 0x255de0
 *   delay: addiu at 0x1d9fb0 writes a register its branch at 0x1d9fac reads
 *   indirect: jr v0 at 0x1d9fe8 -> <v0>
 *   indirect: jr v0 at 0x1da090 -> <v0>
 *   delay: addiu at 0x1da430 writes a register its branch at 0x1da42c reads
 *   delay: addiu at 0x1da548 writes a register its branch at 0x1da544 reads
 *   delay: addiu at 0x1da668 writes a register its branch at 0x1da664 reads
 *   cfg: a region cannot contain a jump table whole: 0x1da144..0x1da178
 *   cfg: kept branch: 0x1da138 if (..) goto .L001DA188
 *   cfg: a region cannot contain a jump table whole: 0x1da178..0x1da178
 *   cfg: kept branch: 0x1da144 if (..) goto .L001DA188
 *   cfg: a region cannot contain a jump table whole: 0x1da2fc..0x1da2fc
 *   cfg: a region cannot contain a jump table whole: 0x1da308..0x1da394
 *   cfg: kept branch: 0x1da2f0 if (..) goto .L001DA308
 *   cfg: a region cannot contain a jump table whole: 0x1da310..0x1da378
 *   cfg: kept branch: 0x1da308 if (..) goto .L001DA388
 *   cfg: a region cannot contain a jump table whole: 0x1da378..0x1da378
 *   cfg: kept branch: 0x1da310 if (..) goto .L001DA388
 *   cfg: a region cannot contain a jump table whole: 0x1da3c0..0x1da430
 *   cfg: a region cannot contain a jump table whole: 0x1da440..0x1da4c8
 *   cfg: kept branch: 0x1da3b0 if (..) goto .L001DA440
 *   cfg: a region cannot contain a jump table whole: 0x1da3c8..0x1da3c8
 *   cfg: a region cannot contain a jump table whole: 0x1da3d0..0x1da4c8
 *   cfg: kept branch: 0x1da3c0 if (..) goto .L001DA3D0
 *   cfg: a region cannot contain a jump table whole: 0x1da3d8..0x1da410
 *   cfg: kept branch: 0x1da3d0 if (..) goto .L001DA428
 *   cfg: a region cannot contain a jump table whole: 0x1da40c..0x1da40c
 *   cfg: kept branch: 0x1da3d8 if (..) goto .L001DA410
 *   cfg: a region cannot contain a jump table whole: 0x1da448..0x1da498
 *   cfg: kept branch: 0x1da440 if (..) goto .L001DA4B8
 *   cfg: a region cannot contain a jump table whole: 0x1da478..0x1da478
 *   cfg: kept branch: 0x1da448 if (..) goto .L001DA480
 *   cfg: a region cannot contain a jump table whole: 0x1da48c..0x1da48c
 *   cfg: kept branch: 0x1da480 if (..) goto .L001DA498
 *   cfg: a region cannot contain a jump table whole: 0x1da4e0..0x1da548
 *   cfg: a region cannot contain a jump table whole: 0x1da558..0x1da5e8
 *   cfg: kept branch: 0x1da4d0 if (..) goto .L001DA558
 *   cfg: a region cannot contain a jump table whole: 0x1da4e8..0x1da4e8
 *   cfg: a region cannot contain a jump table whole: 0x1da4f0..0x1da5e8
 *   cfg: kept branch: 0x1da4e0 if (..) goto .L001DA4F0
 *   cfg: a region cannot contain a jump table whole: 0x1da4f8..0x1da530
 *   cfg: kept branch: 0x1da4f0 if (..) goto .L001DA540
 *   cfg: a region cannot contain a jump table whole: 0x1da52c..0x1da52c
 *   cfg: kept branch: 0x1da4f8 if (..) goto .L001DA530
 *   cfg: a region cannot contain a jump table whole: 0x1da560..0x1da5b0
 *   cfg: kept branch: 0x1da558 if (..) goto .L001DA5D8
 *   cfg: a region cannot contain a jump table whole: 0x1da590..0x1da590
 *   cfg: kept branch: 0x1da560 if (..) goto .L001DA598
 *   cfg: a region cannot contain a jump table whole: 0x1da5a4..0x1da5a4
 *   cfg: kept branch: 0x1da598 if (..) goto .L001DA5B0
 *   cfg: a region cannot contain a jump table whole: 0x1da5fc..0x1da5fc
 *   cfg: a region cannot contain a jump table whole: 0x1da608..0x1da668
 *   cfg: kept branch: 0x1da5f0 if (..) goto .L001DA608
 *   cfg: a region cannot contain a jump table whole: 0x1da614..0x1da648
 *   cfg: kept branch: 0x1da608 if (..) goto .L001DA660
 *   cfg: a region cannot contain a jump table whole: 0x1da644..0x1da644
 *   cfg: kept branch: 0x1da614 if (..) goto .L001DA648
 *   cfg: a region cannot contain a jump table whole: 0x1da688..0x1da720
 *   cfg: a region cannot contain a jump table whole: 0x1da730..0x1da738
 *   cfg: kept branch: 0x1da678 if (..) goto .L001DA730
 *   cfg: a region cannot contain a jump table whole: 0x1da690..0x1da690
 *   cfg: a region cannot contain a jump table whole: 0x1da698..0x1da738
 *   cfg: kept branch: 0x1da688 if (..) goto .L001DA698
 *   cfg: a region cannot contain a jump table whole: 0x1da6a0..0x1da6a0
 *   cfg: kept branch: 0x1da698 if (..) goto .L001DA6C0
 *   cfg: a region cannot contain a jump table whole: 0x1da6f8..0x1da6f8
 *   cfg: kept branch: 0x1da6dc if (..) goto .L001DA720
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern void Menu_SetModelState(signed int, signed int, signed int, void *);
extern signed int KnMenuModelMng_ReMakeMdl(int);
extern signed int KnMenuModelMng_ReLoadMdl(int, signed int);
extern signed int CheckEventFlag(signed int);
extern signed int Menu_TD_CallOrder(signed int, signed int, signed int);

extern void ChangeLanguageSound();


extern void RestartMapSe();

#ifndef PROTO_DW_2288205_FIELDS
#define PROTO_DW_2288205_FIELDS
struct dw_2288205_fields { float (*fvListenerPosPtr)[4]; float (*fvListenerAngPtr)[4]; float (*fmListenerMatPtr)[4][4]; };
#endif
#ifndef PROTO_DW_2285952_FIELDS
#define PROTO_DW_2285952_FIELDS
struct dw_2285952_fields { float panlim; float zofs; char dopp; char pad[3]; float range; char reserved[16]; };
#endif
#ifndef PROTO_DW_2305547_FIELDS
#define PROTO_DW_2305547_FIELDS
struct dw_2305547_fields { short sCalcedVol; char bid; char sid; char PlayId; char reserv[3]; int sq_fade; int sq_vol; };
#endif
#ifndef PROTO_DW_2284950_FIELDS
#define PROTO_DW_2284950_FIELDS
struct dw_2284950_fields { unsigned short usFreq; unsigned char ucLoop; char cDmy[1]; };
#endif
#ifndef PROTO_DW_2285569_FIELDS
#define PROTO_DW_2285569_FIELDS
struct dw_2285569_fields { unsigned int uiProgNum; char cDmy[12]; struct dw_2284950_fields aParam[128]; };
#endif
#ifndef PROTO_DW_2288913_FIELDS
#define PROTO_DW_2288913_FIELDS
struct dw_2288913_fields { struct dw_2288205_fields Listener; struct dw_2285952_fields Param; signed char SndMode; unsigned char bfMasterVolume : 1; unsigned char bfReserv : 7; unsigned char ucMasterVolume; unsigned char ucBgmVolume; unsigned char ucSqVolume; unsigned char ucSeVolume; unsigned short usVolumeFadeOutFrame; char rid[8]; unsigned short ucVoiceCnt; unsigned char _pad0[2]; int Handle[12]; struct dw_2305547_fields aSqSong[4]; unsigned char calloff; unsigned char _pad1[3]; struct dw_2285569_fields aBankInfo[12]; unsigned short aaIdTable[12][128]; unsigned int uiUseVoiceNum; };
#endif
#ifndef PROTO_DW_2298180_FIELDS
#define PROTO_DW_2298180_FIELDS

#endif
#ifndef PROTO_DW_2299119_FIELDS
#define PROTO_DW_2299119_FIELDS

#endif

#define GS ((struct dw_2299119_fields *)GameSt)
#define MCM ((struct dw_2298180_fields *)MemocaMng)

static inline int SlotCursor(void) {
    int r;
    r = 0x15;
    if (s_load_slot == 1) {
        r = 0x16;
    }
    return r;
}

#undef KEY_PLAIN
#undef STICK_SET





extern void SetSprite(void *, signed int, signed int, signed int, signed int, signed int *,
    unsigned short, unsigned char);
extern void MakeAndKickSpritePacket(void *);
extern void FontDrawBegin(int);
extern signed int FsFontSetScale(float, float);
extern void * GetTexMngByName(void *, char *);
extern void MenuItemMng_MakeAndKickSpritePacket(void *, int, signed int);
extern void SetFontColor(s32);
extern signed int FsFontSetAlignment(signed int);
extern void FontPrintInRect(float, float, float, float, char *, ...);
extern void FontDrawEnd();

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

static u8 MemocaMng[0x9];
static u32 aTmpStr_Page[0x8];
static u32 s_MapData[0x15];
static u32 s_aDialogMsg[0x40];
static u32 s_MenuFileBuf[0x28];
static u8 s_menu_map_name[0x100];
static u32 aTmpBtnGuide[0x3c0];
static u8 aTmpHelpStr2[0x80];
static u8 aTmpHelpStr[0x80];
static u32 aTmpMemocaData[0x140];
static u8 aTmpItemDoc[0x400];
static u8 aTmpItemName_Left[0x80];
static u8 aTmpItemNote[0x80];
static u8 aTmpItemName[0x80];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void Menu_GetTexCenter(int tex_id, float *center);
s32 Menu_GetNowMapTexId(s32 a0);
signed int Memu_CtrlFunc(void *pVariable, signed int _state_id);
void Menu_DialogDraw(void);


/* MI_Get_Dmy @ 0x1EBB50 .. 0x1EBB58 (0x8 bytes) */



void MI_Get_Dmy(void) {
    return;
}


/* MI_Set_Dmy @ 0x1EBB40 .. 0x1EBB48 (0x8 bytes) */



void MI_Set_Dmy(void) {
    return;
}






/* MI_Decide_Dmy @ 0x1EBB30 .. 0x1EBB38 (0x8 bytes) */



void MI_Decide_Dmy(void) {
    return;
}


/* MI_CntUp_Dmy @ 0x1EBB20 .. 0x1EBB28 (0x8 bytes) */



void MI_CntUp_Dmy(void) {
    return;
}


/* MI_CntDown_Dmy @ 0x1EBB10 .. 0x1EBB18 (0x8 bytes) */



void MI_CntDown_Dmy(void) {
    return;
}


/* MI_Gene1_Dmy @ 0x1EBB00 .. 0x1EBB08 (0x8 bytes) */



void MI_Gene1_Dmy(void) {
    return;
}







/* MI_Gene2_Dmy @ 0x1EBAF0 .. 0x1EBAF8 (0x8 bytes) */



void MI_Gene2_Dmy(void) {
    return;
}
/* MI_Evrfrm_Dmy @ 0x1EBAE0 .. 0x1EBAE8 (0x8 bytes) */



void MI_Evrfrm_Dmy(void) {
    return;
}






/* MI_Init_Dmy @ 0x1EBAD0 .. 0x1EBAD8 (0x8 bytes) */



void MI_Init_Dmy(void) {
    return;
}









/* MI_Check_Dmy @ 0x1EBAC0 .. 0x1EBAC8 (0x8 bytes) */



void MI_Check_Dmy(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_Test @ 0x1EBAB0 .. 0x1EBAB8 (0x8 bytes) */



void MI_Get_Test(void) {
    return;
}












/* MI_Set_Test @ 0x1EBAA0 .. 0x1EBAA8 (0x8 bytes) */



void MI_Set_Test(void) {
    return;
}









/* MI_Decide_Test @ 0x1EBA90 .. 0x1EBA98 (0x8 bytes) */



void MI_Decide_Test(void) {
    return;
}


/* MI_CntUp_Test @ 0x1EBA80 .. 0x1EBA88 (0x8 bytes) */



void MI_CntUp_Test(void) {
    return;
}


/* MI_CntDown_Test @ 0x1EBA70 .. 0x1EBA78 (0x8 bytes) */



void MI_CntDown_Test(void) {
    return;
}


/* MI_Gene1_Test @ 0x1EBA60 .. 0x1EBA68 (0x8 bytes) */



void MI_Gene1_Test(void) {
    return;
}


/* MI_Gene2_Test @ 0x1EBA50 .. 0x1EBA58 (0x8 bytes) */



void MI_Gene2_Test(void) {
    return;
}


/* MI_Evrfrm_Test @ 0x1EBA40 .. 0x1EBA48 (0x8 bytes) */



void MI_Evrfrm_Test(void) {
    return;
}







/* MI_Init_Test @ 0x1EBA30 .. 0x1EBA38 (0x8 bytes) */



void MI_Init_Test(void) {
    return;
}


/* MI_Check_Test @ 0x1EBA20 .. 0x1EBA28 (0x8 bytes) */



void MI_Check_Test(void) {
    return;
}


/* MI_Get_Top @ 0x1EBA10 .. 0x1EBA18 (0x8 bytes) */



void MI_Get_Top(void) {
    return;
}


/* MI_Set_Top @ 0x1EBA00 .. 0x1EBA08 (0x8 bytes) */




void MI_Set_Top(void) {
    return;
}


static inline s32 MI_Decide_Top__haveItem(unsigned short kind) {
    s32 i;
    s32 num;
    s32 have;

    num = ItemMng_GetItemMaxNum(kind);
    have = 0;
    for (i = 0; i < num; i++) {
        if ((s32)ItemMng_GetItemNum(kind, ItemMng_GetItemBySequence(kind, i) % 1000) > 0) {
            have = 1;
        }
    }
    return have;
}

static inline void MI_Decide_Top__dialog(signed int msg, u16 *buf) {
    u16 *str;

    str = KnMsgMng_GetMsgStr(msg);
    s_now_dialog_id = 0;
    if (str == 0) {
        s_DialogUseCounter = 0;
    } else if (s_DialogUseCounter == 0) {
        memcpy(buf, str, MI_Decide_Top__lenu16(str) * 2 + 2);
        FsFontReplaceText(s_aDialogMsg, buf, 0);
        *(u8 *)&s_aDialogResult = 0;
        s_DialogUseCounter = 10;
        s_no_pad_check = 0;
    }
}

void MI_Decide_Top(void *pVariable, signed int id) {
    u16 buf1[504];
    u16 buf2[504];

    KnMenuWindMng_SetTopWindRate();
    *(u32 *)pVariable = 0;
    switch (id) {
    case 1:
        break;
    case 2:
        if (MI_Decide_Top__haveItem(1)) break;
        MI_Decide_Top__dialog(0x186e4, buf1);
        break;
    case 3:
        if (MI_Decide_Top__haveItem(2)) break;
        MI_Decide_Top__dialog(0x186e5, buf2);
        break;
    case 4:
        break;
    case 5:
        break;
    }
}


/* MI_CntUp_Top @ 0x1EB750 .. 0x1EB758 (0x8 bytes) */



void MI_CntUp_Top(void) {
    return;
}


/* MI_CntDown_Top @ 0x1EB740 .. 0x1EB748 (0x8 bytes) */



void MI_CntDown_Top(void) {
    return;
}


/* MI_Gene1_Top @ 0x1EB730 .. 0x1EB738 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j KnMenuWindMng_SetTopWindRate at 0x1eb730 leaves the function
 *   return value dropped, call kept: the function is void
 */


void MI_Gene1_Top(void) {
    KnMenuWindMng_SetTopWindRate();
    return;
}


/* MI_Gene2_Top @ 0x1EB720 .. 0x1EB728 (0x8 bytes) */



void MI_Gene2_Top(void) {
    return;
}


/* MI_Evrfrm_Top @ 0x1EB710 .. 0x1EB718 (0x8 bytes) */



void MI_Evrfrm_Top(void) {
    return;
}


/* MI_Init_Top @ 0x1EB700 .. 0x1EB708 (0x8 bytes) */




void MI_Init_Top(void) {
    return;
}

void MI_Check_Top(void *a0 /* r4 */, signed int a1 /* r5 */) {
    *(u32 *)a0 = 0;
    switch (a1) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        MI_CHECK_EMPTY(1);
        ((MICheckBits *)a0)->bit0 |= 1;
        break;
    case 3:
        MI_CHECK_EMPTY(2);
        ((MICheckBits *)a0)->bit0 |= 1;
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }
}


/* MI_Get_Stick @ 0x1EB530 .. 0x1EB560 (0x30 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






void MI_Get_Stick(void *a0 /* r4 */) {
    u32 v0;

    v0 = KnMenuModelMng_GetCtrlerState();
    stick_data = v0;
    *(u32 *)a0 = (u8)v0;
    return;
}


/* MI_Set_Stick @ 0x1EB520 .. 0x1EB528 (0x8 bytes) */



void MI_Set_Stick(void) {
    return;
}


/* MI_Decide_Stick @ 0x1EB510 .. 0x1EB518 (0x8 bytes) */



void MI_Decide_Stick(void) {
    return;
}


/* MI_CntUp_Stick @ 0x1EB500 .. 0x1EB508 (0x8 bytes) */



void MI_CntUp_Stick(void) {
    return;
}


/* MI_CntDown_Stick @ 0x1EB4F0 .. 0x1EB4F8 (0x8 bytes) */



void MI_CntDown_Stick(void) {
    return;
}


/* MI_Gene1_Stick @ 0x1EB4E0 .. 0x1EB4E8 (0x8 bytes) */



void MI_Gene1_Stick(void) {
    return;
}


/* MI_Gene2_Stick @ 0x1EB4D0 .. 0x1EB4D8 (0x8 bytes) */



void MI_Gene2_Stick(void) {
    return;
}


/* MI_Evrfrm_Stick @ 0x1EB4A0 .. 0x1EB4D0 (0x30 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */


void MI_Evrfrm_Stick(void *a0 /* r4 */) {
    u32 v0;

    v0 = KnMenuModelMng_GetCtrlerState();
    stick_data = v0;
    *(u32 *)a0 = (u8)v0;
    return;
}


/* MI_Init_Stick @ 0x1EB490 .. 0x1EB498 (0x8 bytes) */



void MI_Init_Stick(void) {
    return;
}


/* MI_Check_Stick @ 0x1EB480 .. 0x1EB488 (0x8 bytes) */



void MI_Check_Stick(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}








/* MI_Get_Ctrler @ 0x1EB410 .. 0x1EB478 (0x68 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */




void MI_Get_Ctrler(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a2;
    u32 v1;

    v1 = 1;
    a2 = GameSt[0x16];
    switch (a2) {
    case 0:
        *(u32 *)a0 = v1;
        break;
    case 1:
        v1 = 2;
        *(u32 *)a0 = v1;
    }
    v1 = (s32)a1 < (s32)0xa;
    if (v1 == 0) {
        a2 = stick_data;
        v1 = *(s32 *)a0;
        *(u32 *)a0 = v1 + (s32)((u32)a2 * (u32)(0xa));
    }
    return;
}





/* MI_Set_Ctrler @ 0x1EB400 .. 0x1EB408 (0x8 bytes) */



void MI_Set_Ctrler(void) {
    return;
}


/* MI_Decide_Ctrler @ 0x1EB3F0 .. 0x1EB3F8 (0x8 bytes) */



void MI_Decide_Ctrler(void) {
    return;
}







/* MI_CntUp_Ctrler @ 0x1EB3E0 .. 0x1EB3E8 (0x8 bytes) */



void MI_CntUp_Ctrler(void) {
    return;
}


/* MI_CntDown_Ctrler @ 0x1EB3D0 .. 0x1EB3D8 (0x8 bytes) */



void MI_CntDown_Ctrler(void) {
    return;
}


/* MI_Gene1_Ctrler @ 0x1EB3C0 .. 0x1EB3C8 (0x8 bytes) */



void MI_Gene1_Ctrler(void) {
    return;
}







/* MI_Gene2_Ctrler @ 0x1EB3B0 .. 0x1EB3B8 (0x8 bytes) */



void MI_Gene2_Ctrler(void) {
    return;
}






/* MI_Evrfrm_Ctrler @ 0x1EB340 .. 0x1EB3A8 (0x68 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */




void MI_Evrfrm_Ctrler(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a2;
    u32 v1;

    v1 = 1;
    a2 = GameSt[0x16];
    switch (a2) {
    case 0:
        *(u32 *)a0 = v1;
        break;
    case 1:
        v1 = 2;
        *(u32 *)a0 = v1;
    }
    v1 = (s32)a1 < (s32)0xa;
    if (v1 == 0) {
        a2 = stick_data;
        v1 = *(s32 *)a0;
        *(u32 *)a0 = v1 + (s32)((u32)a2 * (u32)(0xa));
    }
    return;
}


/* MI_Init_Ctrler @ 0x1EB330 .. 0x1EB338 (0x8 bytes) */



void MI_Init_Ctrler(void) {
    return;
}


/* MI_Check_Ctrler @ 0x1EB320 .. 0x1EB328 (0x8 bytes) */



void MI_Check_Ctrler(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}






/* MI_Get_Stereo @ 0x1EB310 .. 0x1EB318 (0x8 bytes) */



void MI_Get_Stereo(void) {
    return;
}


/* MI_Set_Stereo @ 0x1EB300 .. 0x1EB308 (0x8 bytes) */



void MI_Set_Stereo(void) {
    return;
}


/* MI_Decide_Stereo @ 0x1EB2F0 .. 0x1EB2F8 (0x8 bytes) */



void MI_Decide_Stereo(void) {
    return;
}


/* MI_CntUp_Stereo @ 0x1EB230 .. 0x1EB2E4 (0xb4 bytes, frame 0x10) */






void MI_CntUp_Stereo(void *a0 /* r4 */) {
    u32 a1;
    u32 v1;

    v1 = g_pSndMng;
    if (v1 == 0) {
        *(u32 *)a0 = 0;
    } else {
        a1 = *(u8 *)((v1 + 0x2c));
        v1 = 2;
        a0 = (void *)(s32)1;
        switch (a1) {
        case 0:
            SND_SetMode((int)a0);
            break;
        case 1:
            SND_SetMode(v1);
            break;
        case 2:
            SND_SetMode(0);
        }
        v1 = no_snd_on;
        if (v1 == 0) {
            if ((s32)no_snd_counter > 0) {
                no_snd_counter += -1;
            } else {
                SND_Play2D(0x11, 0x64, 0);
            }
        }
    }
    return;
}


/* MI_CntDown_Stereo @ 0x1EB170 .. 0x1EB22C (0xbc bytes, frame 0x10) */



void MI_CntDown_Stereo(void *a0 /* r4 */) {
    u32 a1;
    u32 v1;

    v1 = g_pSndMng;
    if (v1 == 0) {
        *(u32 *)a0 = 0;
    } else {
        a1 = *(u8 *)((v1 + 0x2c));
        a0 = (void *)(s32)2;
        switch (a1) {
        case 0:
            SND_SetMode((int)a0);
            break;
        case 1:
            SND_SetMode(0);
            break;
        case 2:
            SND_SetMode(1);
        }
        v1 = no_snd_on;
        if (v1 == 0) {
            if ((s32)no_snd_counter > 0) {
                no_snd_counter += -1;
            } else {
                SND_Play2D(0x11, 0x64, 0);
            }
        }
    }
    return;
}


/* MI_Gene1_Stereo @ 0x1EB160 .. 0x1EB168 (0x8 bytes) */



void MI_Gene1_Stereo(void) {
    return;
}


/* MI_Gene2_Stereo @ 0x1EB0B0 .. 0x1EB158 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1eb0ec
 *   fpu: float literal 0x437f0000 at 0x1eb0f0
 */




void MI_Gene2_Stereo(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}












/* MI_Evrfrm_Stereo @ 0x1EB040 .. 0x1EB0A8 (0x68 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */






void MI_Evrfrm_Stereo(void *a0 /* r4 */) {
    u32 v1;
    u32 a2;
    s32 a1;

    v1 = g_pSndMng;
    if (v1 == 0) {
        *(u32 *)a0 = 0;
    } else {
        a2 = *(u8 *)((v1 + 0x2c));
        a1 = 2;
        v1 = 1;
        switch (a2) {
        case 0:
            *(u32 *)a0 = v1;
            break;
        case 1:
            *(u32 *)a0 = a1;
            break;
        case 2:
            v1 = 3;
            *(u32 *)a0 = v1;
        }
    }
    return;
}


/* MI_Init_Stereo @ 0x1EB030 .. 0x1EB038 (0x8 bytes) */



void MI_Init_Stereo(void) {
    return;
}


/* MI_Check_Stereo @ 0x1EB020 .. 0x1EB028 (0x8 bytes) */



void MI_Check_Stereo(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_Vib @ 0x1EB010 .. 0x1EB018 (0x8 bytes) */



void MI_Get_Vib(void) {
    return;
}


/* MI_Set_Vib @ 0x1EB000 .. 0x1EB008 (0x8 bytes) */



void MI_Set_Vib(void) {
    return;
}


/* MI_Decide_Vib @ 0x1EAFF0 .. 0x1EAFF8 (0x8 bytes) */



void MI_Decide_Vib(void) {
    return;
}


/* MI_CntUp_Vib @ 0x1EAF60 .. 0x1EAFEC (0x8c bytes, frame 0x10) */






void MI_CntUp_Vib(void) {
    s32 a0;
    u32 v1;

    a0 = 1;
    v1 = GameSt[0x15];
    switch (v1) {
    case 0:
        SetPadVibFlag(a0);
        break;
    case 1:
        SetPadVibFlag(0);
    }
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_CntDown_Vib @ 0x1EAED0 .. 0x1EAF5C (0x8c bytes, frame 0x10) */



void MI_CntDown_Vib(void) {
    s32 a0;
    u32 v1;

    a0 = 1;
    v1 = GameSt[0x15];
    switch (v1) {
    case 0:
        SetPadVibFlag(a0);
        break;
    case 1:
        SetPadVibFlag(0);
    }
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_Gene1_Vib @ 0x1EAEC0 .. 0x1EAEC8 (0x8 bytes) */



void MI_Gene1_Vib(void) {
    return;
}


/* MI_Gene2_Vib @ 0x1EAE10 .. 0x1EAEB8 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1eae4c
 *   fpu: float literal 0x437f0000 at 0x1eae50
 */




void MI_Gene2_Vib(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}


/* MI_Evrfrm_Vib @ 0x1EAD90 .. 0x1EAE10 (0x80 bytes, frame 0x20) */



void MI_Evrfrm_Vib(void *a0 /* r4 */) {
    u32 *s0;
    u32 v1;
    u32 v0;

    v1 = g_pSndMng;
    s0 = (u32 *)a0;
    if (v1 == 0) {
        *(u32 *)s0 = 0;
    } else {
        a0 = (void *)*(u8 *)((u8 *)&GameSt + 0x15);
        v1 = 1;
        switch ((u32)a0) {
        case 0:
            v0 = 0x10000;
            a0 = (void *)(0x10000 | 0x86da);
            v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
            *(u32 *)s0 = v0;
            break;
        case 1:
            v0 = 0x10000;
            a0 = (void *)(0x10000 | 0x86d9);
            v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
            *(u32 *)s0 = v0;
        }
    }
    return;
}


/* MI_Init_Vib @ 0x1EAD80 .. 0x1EAD88 (0x8 bytes) */



void MI_Init_Vib(void) {
    return;
}


/* MI_Check_Vib @ 0x1EAD70 .. 0x1EAD78 (0x8 bytes) */



void MI_Check_Vib(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_KeyType @ 0x1EAD60 .. 0x1EAD68 (0x8 bytes) */



void MI_Get_KeyType(void) {
    return;
}


/* MI_Set_KeyType @ 0x1EAD50 .. 0x1EAD58 (0x8 bytes) */



void MI_Set_KeyType(void) {
    return;
}


/* MI_Decide_KeyType @ 0x1EAD40 .. 0x1EAD48 (0x8 bytes) */



void MI_Decide_KeyType(void) {
    return;
}


/* MI_CntUp_KeyType @ 0x1EACA0 .. 0x1EAD34 (0x94 bytes, frame 0x10) */







void MI_CntUp_KeyType(void) {
    s32 a0;
    u8 v0;
    u32 v1;

    a0 = 1;
    v0 = GameSt[0x16];
    switch ((u32)v0) {
    case 0:
        SetKeyConfig(a0);
        break;
    case 1:
        SetKeyConfig(0);
    }
    KnMenuModelMng_ResetCtrlerAnim();
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_CntDown_KeyType @ 0x1EAC00 .. 0x1EAC94 (0x94 bytes, frame 0x10) */



void MI_CntDown_KeyType(void) {
    s32 a0;
    u8 v0;
    u32 v1;

    a0 = 1;
    v0 = GameSt[0x16];
    switch ((u32)v0) {
    case 0:
        SetKeyConfig(a0);
        break;
    case 1:
        SetKeyConfig(0);
    }
    KnMenuModelMng_ResetCtrlerAnim();
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_Gene1_KeyType @ 0x1EABF0 .. 0x1EABF8 (0x8 bytes) */



void MI_Gene1_KeyType(void) {
    return;
}


/* MI_Gene2_KeyType @ 0x1EAB40 .. 0x1EABE8 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1eab7c
 *   fpu: float literal 0x437f0000 at 0x1eab80
 */




void MI_Gene2_KeyType(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}


/* MI_Evrfrm_KeyType @ 0x1EAAD0 .. 0x1EAB40 (0x70 bytes, frame 0x20) */






void MI_Evrfrm_KeyType(void *a0 /* r4 */) {
    u32 *s0;
    s32 v1;
    u32 v0;

    v1 = 1;
    s0 = (u32 *)a0;
    a0 = (void *)*(u8 *)((u8 *)&GameSt + 0x16);
    switch ((u32)a0) {
    case 0:
        v0 = 0x10000;
        a0 = (void *)(0x10000 | 0x86db);
        v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
        *(u32 *)s0 = v0;
        break;
    case 1:
        v0 = 0x10000;
        a0 = (void *)(0x10000 | 0x86dc);
        v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
        *(u32 *)s0 = v0;
    }
    return;
}
/* MI_Init_KeyType @ 0x1EAAC0 .. 0x1EAAC8 (0x8 bytes) */



void MI_Init_KeyType(void) {
    return;
}


/* MI_Check_KeyType @ 0x1EAAB0 .. 0x1EAAB8 (0x8 bytes) */



void MI_Check_KeyType(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_LangType @ 0x1EAAA0 .. 0x1EAAA8 (0x8 bytes) */



void MI_Get_LangType(void) {
    return;
}


/* MI_Set_LangType @ 0x1EAA90 .. 0x1EAA98 (0x8 bytes) */



void MI_Set_LangType(void) {
    return;
}


/* MI_Decide_LangType @ 0x1EAA80 .. 0x1EAA88 (0x8 bytes) */



void MI_Decide_LangType(void) {
    return;
}


/* MI_CntUp_LangType @ 0x1EA9F0 .. 0x1EAA7C (0x8c bytes, frame 0x10) */





void MI_CntUp_LangType(void) {
    u32 v1;
    u8 a0;

    v1 = 1;
    a0 = GameSt[0x2c];
    switch ((u32)a0) {
    case 0:
        GameSt[0x2c] = v1;
        break;
    case 1:
        GameSt[0x2c] = 0;
    }
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_CntDown_LangType @ 0x1EA960 .. 0x1EA9EC (0x8c bytes, frame 0x10) */





void MI_CntDown_LangType(void) {
    u32 v1;
    u8 a0;

    v1 = 1;
    a0 = GameSt[0x2c];
    switch ((u32)a0) {
    case 0:
        GameSt[0x2c] = v1;
        break;
    case 1:
        GameSt[0x2c] = 0;
    }
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}






/* MI_Gene1_LangType @ 0x1EA950 .. 0x1EA958 (0x8 bytes) */



void MI_Gene1_LangType(void) {
    return;
}


/* MI_Gene2_LangType @ 0x1EA8A0 .. 0x1EA948 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1ea8dc
 *   fpu: float literal 0x437f0000 at 0x1ea8e0
 */




void MI_Gene2_LangType(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}


/* MI_Evrfrm_LangType @ 0x1EA830 .. 0x1EA8A0 (0x70 bytes, frame 0x20) */


void MI_Evrfrm_LangType(void *a0 /* r4 */) {
    u32 *s0;
    s32 v1;
    u32 v0;

    v1 = 1;
    s0 = (u32 *)a0;
    a0 = (void *)*(u8 *)((u8 *)&GameSt + 0x2c);
    switch ((u32)a0) {
    case 0:
        v0 = 0x10000;
        a0 = (void *)(0x10000 | 0x86ba);
        v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
        *(u32 *)s0 = v0;
        break;
    case 1:
        v0 = 0x10000;
        a0 = (void *)(0x10000 | 0x86bb);
        v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0);
        *(u32 *)s0 = v0;
    }
    return;
}


/* MI_Init_LangType @ 0x1EA820 .. 0x1EA828 (0x8 bytes) */



void MI_Init_LangType(void) {
    return;
}


/* MI_Check_LangType @ 0x1EA810 .. 0x1EA818 (0x8 bytes) */



void MI_Check_LangType(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_SldBar @ 0x1EA800 .. 0x1EA808 (0x8 bytes) */



void MI_Get_SldBar(void) {
    return;
}









/* MI_Set_SldBar @ 0x1EA7F0 .. 0x1EA7F8 (0x8 bytes) */



void MI_Set_SldBar(void) {
    return;
}








/* MI_Decide_SldBar @ 0x1EA7E0 .. 0x1EA7E8 (0x8 bytes) */




void MI_Decide_SldBar(void) {
    return;
}



/* MI_CntUp_SldBar @ 0x1EA1B0 .. 0x1EA7D8 (0x628 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1ea21c
 *   fpu: float literal 0x467ffc00 at 0x1ea22c
 *   fpu: float literal 0x42000000 at 0x1ea23c
 *   fpu: float literal 0x3f800000 at 0x1ea270
 *   fpu: float literal 0x3c23d70a at 0x1ea278
 *   fpu: mtc1 reinterprets v1 at 0x1ea2cc
 *   fpu: float literal 0x42000000 at 0x1ea304
 *   fpu: float literal 0x467ffc00 at 0x1ea31c
 *   fpu: float literal 0x4f000000 at 0x1ea320
 *   fpu: float literal 0x437f0000 at 0x1ea374
 *   fpu: float literal 0x4f000000 at 0x1ea378
 *   fpu: mtc1 reinterprets v0 at 0x1ea3e0
 *   fpu: float literal 0x42fe0000 at 0x1ea3e4
 *   fpu: float literal 0x42000000 at 0x1ea3f8
 *   fpu: float literal 0x3f800000 at 0x1ea42c
 *   fpu: float literal 0x3e800000 at 0x1ea430
 *   fpu: mtc1 reinterprets v1 at 0x1ea484
 *   fpu: float literal 0x42000000 at 0x1ea4bc
 *   fpu: float literal 0x42fe0000 at 0x1ea4cc
 *   fpu: float literal 0x4f000000 at 0x1ea4dc
 *   fpu: mtc1 reinterprets v1 at 0x1ea53c
 *   fpu: float literal 0x467ffc00 at 0x1ea54c
 *   fpu: float literal 0x42000000 at 0x1ea55c
 *   fpu: float literal 0x3f800000 at 0x1ea590
 *   fpu: float literal 0x3c23d70a at 0x1ea598
 *   fpu: mtc1 reinterprets v1 at 0x1ea5ec
 *   fpu: float literal 0x42000000 at 0x1ea624
 *   fpu: float literal 0x467ffc00 at 0x1ea63c
 *   fpu: float literal 0x4f000000 at 0x1ea640
 *   fpu: float literal 0x42000000 at 0x1ea6a4
 *   fpu: float literal 0x43480000 at 0x1ea6ac
 *   fpu: mtc1 reinterprets v1 at 0x1ea6b4
 *   fpu: float literal 0x3f800000 at 0x1ea6f0
 *   fpu: float literal 0x3e19999a at 0x1ea6f8
 *   fpu: mtc1 reinterprets a0 at 0x1ea74c
 *   fpu: float literal 0x42000000 at 0x1ea784
 *   fpu: float literal 0x43480000 at 0x1ea794
 *   fpu: float literal 0x42c80000 at 0x1ea7a4
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

void MI_CntUp_SldBar(void *arg0, signed int a1 /* r5 */) {
    u32 a2;
    u32 a0;
    u32 v1;
    float f2;
    float f1;
    float f20;
    u32 v0;

    a2 = (s32)a1 / 0x989680;
    v1 = 4;
    a1 = 3;
    switch (a2) {
    case 1:
        v0 = GetVagMasterVolume(0);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u16)v0) / 16383.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 <= (s32)0x1f) {
            f1 = 1.0f;
            f2 = (f2 + 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 = f20 + 0.00999999978f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f20 = (f20 / 32.0f);
        v1 = 0x467f0000 | 0xfc00;
        f1 = 16383.0f;
        SetVagMasterVolume(0, (u32)(16383.0f * f20));
        f1 = 255.0f;
        v1 = (u32)(255.0f * f20);
        SND_SqSetVolume((u8)v1);
        break;
    case 2:
        v0 = SND_GetVol(a1);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u8)v0) / 127.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 <= (s32)0x1f) {
            f1 = 1.0f;
            f2 = (f2 + 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 = f20 + 0.25f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f1 = 32.0f;
        SND_SetVol(3, (u8)(127.0f * (f20 / 32.0f)));
        break;
    case 3:
        v0 = GetVagMasterVolume(1);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u16)v0) / 16383.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 <= (s32)0x1f) {
            f1 = 1.0f;
            f2 = (f2 + 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 = f20 + 0.00999999978f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f2 = (f20 / 32.0f);
        v1 = 0x467f0000 | 0xfc00;
        f1 = 16383.0f;
        SetVagMasterVolume(1, (u32)(16383.0f * f2));
        break;
    case 4:
        a1 = *(s8 *)(GameSt + 0x1e);
        f1 = 200.0f;
        v1 = (u32)(a1) + 0x64;
        f2 = ((float)(s32)v1);
        f2 = ((float)(s32)(32.0f * (f2 / 200.0f)));
        a0 = ((s32)f2);
        if ((s32)a0 <= (s32)0x1f) {
            a0 = 0x3f800000;
            f1 = 1.0f;
            f2 = (f2 + 1.0f);
            v1 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 = f20 + 0.150000006f;
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    v1 = v1 + -1;
                    no_snd_counter = v1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v1 = no_snd_on;
            f20 = ((float)(s32)a0);
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    v1 = v1 + -1;
                    no_snd_counter = v1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f1 = 32.0f;
        v1 = ((s32)((200.0f * (f20 / 32.0f)) - 100.0f));
        GameSt[0x1e] = v1;
        break;
    default:
        *(u32 *)arg0 = 0;
    }
    return;
}


/* MI_CntDown_SldBar @ 0x1E9B80 .. 0x1EA1A8 (0x628 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v1 at 0x1e9bec
 *   fpu: float literal 0x467ffc00 at 0x1e9bfc
 *   fpu: float literal 0x42000000 at 0x1e9c0c
 *   fpu: float literal 0x3f800000 at 0x1e9c3c
 *   fpu: float literal 0x3c23d70a at 0x1e9c44
 *   fpu: mtc1 reinterprets v1 at 0x1e9c9c
 *   fpu: float literal 0x42000000 at 0x1e9cd4
 *   fpu: float literal 0x467ffc00 at 0x1e9cec
 *   fpu: float literal 0x4f000000 at 0x1e9cf0
 *   fpu: float literal 0x437f0000 at 0x1e9d44
 *   fpu: float literal 0x4f000000 at 0x1e9d48
 *   fpu: mtc1 reinterprets v0 at 0x1e9db0
 *   fpu: float literal 0x42fe0000 at 0x1e9db4
 *   fpu: float literal 0x42000000 at 0x1e9dc8
 *   fpu: float literal 0x3f800000 at 0x1e9df8
 *   fpu: float literal 0x3e800000 at 0x1e9dfc
 *   fpu: mtc1 reinterprets v1 at 0x1e9e54
 *   fpu: float literal 0x42000000 at 0x1e9e8c
 *   fpu: float literal 0x42fe0000 at 0x1e9e9c
 *   fpu: float literal 0x4f000000 at 0x1e9eac
 *   fpu: mtc1 reinterprets v1 at 0x1e9f0c
 *   fpu: float literal 0x467ffc00 at 0x1e9f1c
 *   fpu: float literal 0x42000000 at 0x1e9f2c
 *   fpu: float literal 0x3f800000 at 0x1e9f5c
 *   fpu: float literal 0x3c23d70a at 0x1e9f64
 *   fpu: mtc1 reinterprets v1 at 0x1e9fbc
 *   fpu: float literal 0x42000000 at 0x1e9ff4
 *   fpu: float literal 0x467ffc00 at 0x1ea00c
 *   fpu: float literal 0x4f000000 at 0x1ea010
 *   fpu: float literal 0x42000000 at 0x1ea074
 *   fpu: float literal 0x43480000 at 0x1ea07c
 *   fpu: mtc1 reinterprets v1 at 0x1ea084
 *   fpu: float literal 0x3f800000 at 0x1ea0bc
 *   fpu: float literal 0x3e19999a at 0x1ea0c4
 *   fpu: mtc1 reinterprets a0 at 0x1ea11c
 *   fpu: float literal 0x42000000 at 0x1ea154
 *   fpu: float literal 0x43480000 at 0x1ea164
 *   fpu: float literal 0x42c80000 at 0x1ea174
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32
 */

void MI_CntDown_SldBar(void *arg0, signed int a1 /* r5 */) {
    u32 a0;
    u32 a2;
    u32 v1;
    float f2;
    float f1;
    float f20;
    u32 v0;

    a2 = (s32)a1 / 0x989680;
    v1 = 4;
    a1 = 3;
    switch (a2) {
    case 1:
        v0 = GetVagMasterVolume(0);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u16)v0) / 16383.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 > 0) {
            f1 = 1.0f;
            f2 = (f2 - 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 += 0.00999999978f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f20 = (f20 / 32.0f);
        v1 = 0x467f0000 | 0xfc00;
        f1 = 16383.0f;
        SetVagMasterVolume(0, (u32)(16383.0f * f20));
        f1 = 255.0f;
        v1 = (u32)(255.0f * f20);
        SND_SqSetVolume((u8)v1);
        break;
    case 2:
        v0 = SND_GetVol(a1);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u8)v0) / 127.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 > 0) {
            f1 = 1.0f;
            f2 = (f2 - 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 += 0.25f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f1 = 32.0f;
        SND_SetVol(3, (u8)(127.0f * (f20 / 32.0f)));
        break;
    case 3:
        v0 = GetVagMasterVolume(1);
        f2 = ((float)(s32)(32.0f * ((float)((float)(s32)(u32)(u16)v0) / 16383.0f)));
        v1 = ((s32)f2);
        if ((s32)v1 > 0) {
            f1 = 1.0f;
            f2 = (f2 - 1.0f);
            v0 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 += 0.00999999978f;
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v0 = no_snd_on;
            f20 = ((float)(s32)v1);
            if (v0 == 0) {
                v0 = no_snd_counter;
                if ((s32)v0 > 0) {
                    no_snd_counter = v0 + -1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f2 = (f20 / 32.0f);
        v1 = 0x467f0000 | 0xfc00;
        f1 = 16383.0f;
        SetVagMasterVolume(1, (u32)(16383.0f * f2));
        break;
    case 4:
        a1 = *(s8 *)(GameSt + 0x1e);
        f1 = 200.0f;
        v1 = (u32)(a1) + 0x64;
        f2 = ((float)(s32)v1);
        f2 = ((float)(s32)(32.0f * (f2 / 200.0f)));
        a0 = ((s32)f2);
        if ((s32)a0 > 0) {
            a0 = 0x3f800000;
            f1 = 1.0f;
            f2 = (f2 - 1.0f);
            v1 = no_snd_on;
            f20 = (float)(s32)f2;
            f20 += 0.150000006f;
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    v1 = v1 + -1;
                    no_snd_counter = v1;
                } else {
                    SND_Play2D(0x14, 0x64, 0x258);
                }
            }
        } else {
            v1 = no_snd_on;
            f20 = ((float)(s32)a0);
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    v1 = v1 + -1;
                    no_snd_counter = v1;
                } else {
                    SND_Play2D(0x16, 0x64, 0);
                }
            }
        }
        f1 = 32.0f;
        v1 = ((s32)((200.0f * (f20 / 32.0f)) - 100.0f));
        GameSt[0x1e] = v1;
        break;
    default:
        *(u32 *)arg0 = 0;
    }
    return;
}






/* MI_Gene1_SldBar @ 0x1E9B70 .. 0x1E9B78 (0x8 bytes) */



void MI_Gene1_SldBar(void) {
    return;
}


/* MI_Gene2_SldBar @ 0x1E9AC0 .. 0x1E9B68 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1e9afc
 *   fpu: float literal 0x437f0000 at 0x1e9b00
 */




void MI_Gene2_SldBar(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}


/* MI_Evrfrm_SldBar @ 0x1E9900 .. 0x1E9AC0 (0x1c0 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets v0 at 0x1e9978
 *   fpu: mtc1 reinterprets a0 at 0x1e998c
 *   fpu: float literal 0x467ffc00 at 0x1e99a4
 *   fpu: mtc1 reinterprets v0 at 0x1e99d0
 *   fpu: mtc1 reinterprets a0 at 0x1e99e4
 *   fpu: float literal 0x42fe0000 at 0x1e99f8
 *   fpu: mtc1 reinterprets v0 at 0x1e9a28
 *   fpu: mtc1 reinterprets a0 at 0x1e9a3c
 *   fpu: float literal 0x467ffc00 at 0x1e9a54
 *   fpu: float literal 0x43480000 at 0x1e9a7c
 *   fpu: mtc1 reinterprets v1 at 0x1e9a84
 *   declaration vs inferred signature: return void vs inferred float
 */




void MI_Evrfrm_SldBar(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s0;
    s32 a2;
    s32 v1;
    u32 v0;
    float f1;
    float f0;

    v1 = 0x6b5f0000;
    a2 = (u32)a1 >> 0x1f;
    s0 = (u8 *)a0;
    a0 = (void *)(0x6b5f0000 | 0xca6b);
    v1 = 4;
    a0 = (void *)(s32)3;
    switch ((u32)((s32)a1 / (s32)(0x989680))) {
    case 1:
        f1 = (float)GetVagMasterVolume(0);
        v1 = 0x467ffc00;
        f0 = 16383.0f;
        f0 = (f1 / 16383.0f);
        *(f32 *)s0 = f0;
        break;
    case 2:
        v0 = SND_GetVol((s32)a0);
        f1 = (float)v0;
        v1 = 0x42fe0000;
        f0 = 127.0f;
        f0 = (f1 / 127.0f);
        *(f32 *)s0 = f0;
        break;
    case 3:
        a0 = (void *)(s32)1;
        f1 = (float)GetVagMasterVolume((unsigned char)a0);
        v1 = 0x467ffc00;
        f0 = 16383.0f;
        f0 = (f1 / 16383.0f);
        *(f32 *)s0 = f0;
        break;
    case 4:
        a0 = (void *)*(s8 *)(GameSt + 0x1e);
        f0 = 200.0f;
        f1 = ((float)(s32)(u32)(s32)((u8 *)a0 + 0x64));
        f0 = (f1 / 200.0f);
        *(f32 *)s0 = f0;
        break;
    default:
        *(u32 *)s0 = 0;
    }
    return;
}


/* MI_Init_SldBar @ 0x1E98F0 .. 0x1E98F8 (0x8 bytes) */



void MI_Init_SldBar(void) {
    return;
}


/* MI_Check_SldBar @ 0x1E98E0 .. 0x1E98E8 (0x8 bytes) */



void MI_Check_SldBar(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* GetEquipTexMng @ 0x1E9760 .. 0x1E98D4 (0x174 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e9794 writes a register its branch at 0x1e9790 reads
 *   stack: address of the slot at 0x4c escapes at 0x1e97c8
 *   stack: address of the slot at 0x48 escapes at 0x1e97c8
 *   stack: address of the slot at 0x44 escapes at 0x1e97c8
 *   stack: address of the slot at 0x4c escapes at 0x1e9808
 *   stack: address of the slot at 0x48 escapes at 0x1e9808
 *   stack: address of the slot at 0x44 escapes at 0x1e9808
 *   stack: address of the slot at 0x4c escapes at 0x1e9848
 *   stack: address of the slot at 0x48 escapes at 0x1e9848
 *   stack: address of the slot at 0x44 escapes at 0x1e9848
 */


void * GetEquipTexMng(u8 a0 /* r4 */) {
    u8 *t0;
    u8 *s2;
    u32 s1;
    u8 *a3;
    u8 *a2;
    u32 a1;
    u32 a0_2; // a0
    u32 v1;
    u32 v0;
    u8 stackFrame_4C[4] __attribute__((aligned(4)));
    u8 stackFrame_48[4] __attribute__((aligned(4)));
    u8 stackFrame_44[4] __attribute__((aligned(4)));

    v0 = 8;
    s2 = (u8 *)(MdlMng + 0x4600);
    s1 = 0;
    switch ((u32)a0) {
    case 5:
        a0_2 = (u32)s2;
        a1 = 0xff;
        a2 = ((u8 *)&stackFrame_4C[0]);
        a3 = ((u8 *)&stackFrame_48[0]);
        t0 = ((u8 *)&stackFrame_44[0]);
        GetMyEquipInfo((void *)a0_2, a1, (signed int *)a2, (signed int *)a3, (signed int *)t0);
        v1 = *(s32 *)((u8 *)&stackFrame_4C[0]);
        v0 = 1;
        if (v1 != v0) {
            break;
        }
        a1 = *(u16 *)((u8 *)&stackFrame_48[0]);
        a0_2 = 3;
        v0 = (u32)ItemMng_GetItemTex(a0_2, a1);
        s1 = v0;
        break;
    case 6:
        a0_2 = (u32)s2;
        a2 = ((u8 *)&stackFrame_4C[0]);
        a3 = ((u8 *)&stackFrame_48[0]);
        t0 = ((u8 *)&stackFrame_44[0]);
        GetMyEquipInfo((void *)a0_2, 0, (signed int *)a2, (signed int *)a3, (signed int *)t0);
        v1 = *(s32 *)((u8 *)&stackFrame_4C[0]);
        v0 = 1;
        if (v1 != v0) {
            break;
        }
        a1 = *(u16 *)((u8 *)&stackFrame_48[0]);
        a0_2 = 3;
        v0 = (u32)ItemMng_GetItemTex(a0_2, a1);
        s1 = v0;
        break;
    case 7:
        a0_2 = (u32)s2;
        a1 = 1;
        a2 = ((u8 *)&stackFrame_4C[0]);
        a3 = ((u8 *)&stackFrame_48[0]);
        t0 = ((u8 *)&stackFrame_44[0]);
        GetMyEquipInfo((void *)a0_2, a1, (signed int *)a2, (signed int *)a3, (signed int *)t0);
        v1 = *(s32 *)((u8 *)&stackFrame_4C[0]);
        v0 = 1;
        if (v1 != v0) {
            break;
        }
        a1 = *(u16 *)((u8 *)&stackFrame_48[0]);
        a0_2 = 3;
        v0 = (u32)ItemMng_GetItemTex(a0_2, a1);
        s1 = v0;
    case 8:
        break;
    }
    v0 = 8;
    if (s1 == 0 && (u32)a0 == v0) {
        v0 = GetMyWeaponId((void *)s2);
        v1 = GameSt[0x14];
        a1 = (u32)(u8)v0 + 1;
        v0 = v1 * (u32)(3);
        v0 = v0 + a1;
        *(u32 *)((u8 *)&stackFrame_48[0]) = v0;
        a1 = *(u16 *)((u8 *)&stackFrame_48[0]);
        v0 = (u32)ItemMng_GetItemTex(4, a1);
        s1 = v0;
    }
    return (void *)s1;
}


/* GetEquipNum @ 0x1E9610 .. 0x1E975C (0x14c bytes, frame 0x20) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e9634 writes a register its branch at 0x1e9630 reads
 *   stack: address of the slot at 0x1c escapes at 0x1e9664
 *   stack: address of the slot at 0x18 escapes at 0x1e9664
 *   stack: address of the slot at 0x14 escapes at 0x1e9664
 *   delay: addiu at 0x1e9678 writes a register its branch at 0x1e9674 reads
 *   stack: address of the slot at 0x1c escapes at 0x1e96a4
 *   stack: address of the slot at 0x18 escapes at 0x1e96a4
 *   stack: address of the slot at 0x14 escapes at 0x1e96a4
 *   delay: addiu at 0x1e96b8 writes a register its branch at 0x1e96b4 reads
 *   stack: address of the slot at 0x1c escapes at 0x1e96e4
 *   stack: address of the slot at 0x18 escapes at 0x1e96e4
 *   stack: address of the slot at 0x14 escapes at 0x1e96e4
 *   delay: addiu at 0x1e96f8 writes a register its branch at 0x1e96f4 reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int GetEquipNum(int a0 /* r4 */) {
    u32 a1;
    u32 v1;
    u32 v0;
    u8 stackFrame_1C[4] __attribute__((aligned(4)));
    u8 stackFrame_18[4] __attribute__((aligned(4)));
    u8 stackFrame_14[4] __attribute__((aligned(4)));

    v1 = (u8)(s32)a0;
    v0 = 8;
    a0 = (int)(u8 *)(MdlMng + 0x4600);
    switch (v1) {
    case 5:
        a1 = 0xff;
        GetMyEquipInfo((void *)a0, a1, (signed int *)(u8 *)((u8 *)&stackFrame_1C[0]), (signed int
            *)(u8 *)((u8 *)&stackFrame_18[0]), (signed int *)(u8 *)((u8 *)&stackFrame_14[0]));
        v1 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        v0 = 1;
        if (v1 == 1) {
            a1 = *(u16 *)((u8 *)&stackFrame_18[0]);
            a0 = 3;
            v0 = (u16)ItemMng_GetItemNum(a0, a1);
        } else {
            v0 = 0x64;
        }
        return v0;
    case 6:
        GetMyEquipInfo((void *)a0, 0, (signed int *)(u8 *)((u8 *)&stackFrame_1C[0]), (signed int
            *)(u8 *)((u8 *)&stackFrame_18[0]), (signed int *)(u8 *)((u8 *)&stackFrame_14[0]));
        v1 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        v0 = 1;
        if (v1 == 1) {
            a1 = *(u16 *)((u8 *)&stackFrame_18[0]);
            a0 = 3;
            v0 = (u16)ItemMng_GetItemNum(a0, a1);
        } else {
            v0 = 0x64;
        }
        return v0;
    case 7:
        a1 = 1;
        GetMyEquipInfo((void *)a0, a1, (signed int *)(u8 *)((u8 *)&stackFrame_1C[0]), (signed int
            *)(u8 *)((u8 *)&stackFrame_18[0]), (signed int *)(u8 *)((u8 *)&stackFrame_14[0]));
        v1 = *(s32 *)((u8 *)&stackFrame_1C[0]);
        v0 = 1;
        if (v1 == 1) {
            a1 = *(u16 *)((u8 *)&stackFrame_18[0]);
            a0 = 3;
            v0 = (u16)ItemMng_GetItemNum(a0, a1);
        } else {
            v0 = 0x64;
        }
        return v0;
    case 8:
        v0 = (u8)GetMyWeaponId((void *)a0);
        a0 = GameSt[0x14];
        a1 = v0 + 1;
        v0 = 0x64;
        v1 = (u32)a0 * 3;
        v1 = v1 + a1;
        *(u32 *)((u8 *)&stackFrame_18[0]) = v1;
        break;
    default:
        v0 = 0x64;
    }
    return v0;
}
static GetItemDataRet GetItemData(int a1 /* r5 */, int a2 /* r6 */) {
    int item_type;
    u32 target;
    int type_offset;
    int gray_on;
    u32 type;
    int cur;
    char *pMsg;
    char *pNote;
    char *pDocument;
    u32 page;
    u32 length;
    u16 *scan;
    u_long128 q;
    u32 pq;
    u8 frame[16] __attribute__((aligned(16)));

    type = (u8)a1;
    target = a2;
    switch (({ s32 r_; __asm__("addi %0,%1,-21" : "=r"(r_) : "r"((s32)type)); r_; })) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        item_type = 3;
        switch (now_equip_button) {
        case 255:
        case 1:
        case 0:
            item_type = 3;
            break;
        case 2:
            item_type = 4;
        }
        type_offset = type + equip_offset * 3 - 23;
        break;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
        item_type = 1;
        type_offset = type + (item_offset << 2) - 44;
        break;
    case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
        item_type = 2;
        type_offset = type + (book_offset << 2) - 64;
        break;
    case 16: case 17: case 18: case 19: case 36: case 37: case 38: case 39:
    default:
        item_type = -1;
    }
    target = ItemMng_GetItemBySequence((u16)item_type, (u16)(type_offset - 1));
    switch ((u8)a2) {
    case 1:
        if (item_type != -1) {
            *(u32 *)frame = target;
        } else {
            *(u32 *)frame = 0;
        }
        return *(GetItemDataRet *)frame;
        break;
    case 2:
        pMsg = ItemMng_GetItemName_Direct((u16)target);
        if (pMsg != 0 && item_type != -1 && ItemMng_CheckGetExperience((u16)target) != 0) {
            length = 0;
            if (*(u16 *)pMsg != 0) {
                scan = (u16 *)pMsg;
                do {
                    scan++;
                    length++;
                } while (*scan != 0);
            }
            memcpy(aTmpItemName, pMsg, (length << 1) + 2);
            *(void **)frame = aTmpItemName;
        } else {
            length = 0;
            if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    length++;
                } while (*scan != 0);
            }
            memcpy(aTmpItemName, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (length << 1) + 2);
            *(void **)frame = aTmpItemName;
        }
        return *(GetItemDataRet *)frame;
        break;
    case 3:
        pNote = ItemMng_GetItemNote_Direct((u16)target);
        if (pNote != 0 && ItemMng_CheckGetExperience((u16)target) != 0) {
            length = 0;
            if (*(u16 *)pNote != 0) {
                scan = (u16 *)pNote;
                do {
                    scan++;
                    length++;
                } while (*scan != 0);
            }
            memcpy(aTmpItemNote, pNote, (length << 1) + 2);
            *(void **)frame = aTmpItemNote;
        } else {
            length = 0;
            if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    length++;
                } while (*scan != 0);
            }
            memcpy(aTmpItemNote, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (length << 1) + 2);
            *(void **)frame = aTmpItemNote;
        }
        return *(GetItemDataRet *)frame;
        break;
    case 4:
        gray_on = 0;
        if (item_type != -1) {
            *(void **)frame = ItemMng_GetItemTex_Direct((u16)target);
        } else {
            *(u32 *)frame = 0;
        }
        if (*(u32 *)frame != 0) {
            if ((u16)ItemMng_GetItemNum_Direct((u16)target) == 0) {
                if (ItemMng_CheckGetExperience((u16)target) != 0) {
                    gray_on = 1;
                } else {
                    *(void **)frame = GetTexMngByBaseName(0, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000");
                }
            }
        }
        if (KnMenuMng_CheckCtrlPlay(3, 3) != 0) {
            cur = KnMenuMng_GetCursorId(3, 3);
            if (cur - 26 == type - 65) {
                s_now_doc_id = (u16)((s32)target % 1000);
            }
        }
        if (*(u32 *)frame == 0) {
            *(u32 *)frame = 0;
        }
        if (*(u32 *)frame == 0) {
            *(u16 *)frame = 0;
        } else {
            *(u16 *)frame = *(u16 *)(*(u32 *)frame + 2);
            if (gray_on != 0) {
                *(u16 *)frame = *(u16 *)frame | 0x8000;
            }
        }
        return *(GetItemDataRet *)frame;
        break;
    case 5:
        if (item_type == 2) {
            if (ItemMng_GetReadMark((u16)((s32)target % 1000)) != 0) {
                *(u32 *)frame = 0x66;
            } else {
                *(u32 *)frame = 0x65;
            }
        } else {
            if (item_type != -1 && target != -1) {
                *(u32 *)frame = (u16)ItemMng_GetItemNum_Direct((u16)target);
            } else {
                *(u32 *)frame = 0;
            }
        }
        if (ItemMng_CheckGetExperience((u16)target) != 0 && *(u32 *)frame == 0) {
            *(u32 *)frame = 0x67;
        }
        if (ItemMng_CheckGetExperience((u16)target) == 0) {
            *(u32 *)frame = 0;
        }
        return *(GetItemDataRet *)frame;
        break;
    case 6:
        if (KnMenuMng_CheckCtrlPlay(7, 1) != 0) {
            pMsg = ItemMng_GetDocument((u16)((s32)s_get_item_id % 1000), book_doc_page);
            if (s_get_item_id != -1 && pMsg != 0) {
                length = 0;
                if (*(u16 *)pMsg != 0) {
                    scan = (u16 *)pMsg;
                    do {
                        scan++;
                        length++;
                    } while (*scan != 0);
                }
                memcpy(aTmpItemDoc, pMsg, (length << 1) + 2);
                *(void **)frame = aTmpItemDoc;
            } else {
                length = 0;
                if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
                    scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                    do {
                        scan++;
                        length++;
                    } while (*scan != 0);
                }
                memcpy(aTmpItemDoc, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (length << 1) + 2);
                *(void **)frame = aTmpItemDoc;
            }
            return *(GetItemDataRet *)frame;
            break;
        } else {
            pDocument = ItemMng_GetDocument((u16)((s32)target % 1000), book_doc_page);
            if (pDocument != 0) {
                length = 0;
                if (*(u16 *)pDocument != 0) {
                    scan = (u16 *)pDocument;
                    do {
                        scan++;
                        length++;
                    } while (*scan != 0);
                }
                memcpy(aTmpItemDoc, pDocument, (length << 1) + 2);
                *(void **)frame = aTmpItemDoc;
            } else {
                length = 0;
                if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
                    scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                    do {
                        scan++;
                        length++;
                    } while (*scan != 0);
                }
                memcpy(aTmpItemDoc, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (length << 1) + 2);
                *(void **)frame = aTmpItemDoc;
            }
            return *(GetItemDataRet *)frame;
            break;
        }
    case 7:
        if (KnMenuMng_CheckCtrlPlay(7, 1) != 0) {
            if (ItemMng_GetReadMark((u16)((s32)s_get_item_id % 1000)) == 0) {
                ItemMng_SetReadMark((u16)((s32)s_get_item_id % 1000), 1);
            }
            if (s_get_item_id != -1) {
                *(u32 *)frame = (u16)ItemMng_GetDocumentPageNum((u16)((s32)s_get_item_id % 1000));
            } else {
                *(u32 *)frame = 1;
            }
            return *(GetItemDataRet *)frame;
            break;
        } else {
            if (item_type != -1) {
                page = (u16)ItemMng_GetDocumentPageNum((u16)((s32)target % 1000));
            } else {
                page = 1;
            }
            target = (s32)target % 1000;
            if (ItemMng_GetReadMark((u16)target) == 0) {
                ItemMng_SetReadMark((u16)target, 1);
            }
            *(u32 *)frame = page;
            return *(GetItemDataRet *)frame;
            break;
        }
    case 0:
    default:
        *(u32 *)frame = 0;
        return *(GetItemDataRet *)frame;
    }
}

/* MI_Get_CngTex @ 0x1E8D90 .. 0x1E8D98 (0x8 bytes) */



void MI_Get_CngTex(void) {
    return;
}


/* MI_Set_CngTex @ 0x1E8D80 .. 0x1E8D88 (0x8 bytes) */



void MI_Set_CngTex(void) {
    return;
}


/* MI_Decide_CngTex @ 0x1E8D70 .. 0x1E8D78 (0x8 bytes) */



void MI_Decide_CngTex(void) {
    return;
}


/* MI_CntUp_CngTex @ 0x1E8D60 .. 0x1E8D68 (0x8 bytes) */



void MI_CntUp_CngTex(void) {
    return;
}


/* MI_CntDown_CngTex @ 0x1E8D50 .. 0x1E8D58 (0x8 bytes) */



void MI_CntDown_CngTex(void) {
    return;
}


/* Menu_SetGetItemNum @ 0x1E8D40 .. 0x1E8D48 (0x8 bytes) */



void Menu_SetGetItemNum(signed int a0 /* r4 */) {
    s_now_get_item_num = a0;
    return;
}


/* Menu_SetGetItemId @ 0x1E8D30 .. 0x1E8D38 (0x8 bytes) */



void Menu_SetGetItemId(signed int a0 /* r4 */) {
    s_get_item_id = (s32)a0;
    return;
}


/* Menu_GetGetItemId @ 0x1E8D20 .. 0x1E8D28 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1e8d24 computes the return value
 */




u32 Menu_GetGetItemId(void) {
    return s_get_item_id;
}


/* Menu_GetNowDocId @ 0x1E8D10 .. 0x1E8D18 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1e8d14 computes the return value
 */




u32 Menu_GetNowDocId(void) {
    return s_now_doc_id;
}


/* MI_Gene1_CngTex @ 0x1E8CC0 .. 0x1E8D0C (0x4c bytes, frame 0x10) */





void MI_Gene1_CngTex(void) {
    u32 v1;

    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            no_snd_counter = v1 + -1;
        } else {
            SND_Play2D(0x11, 0x64, 0);
        }
    }
    return;
}


/* MI_Gene2_CngTex @ 0x1E8CB0 .. 0x1E8CB8 (0x8 bytes) */




void MI_Gene2_CngTex(void) {
    return;
}

void MI_Evrfrm_CngTex(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u16 *s0;
    u32 a2;
    void *a0_2; // a0
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0_7; // v0
    u32 v0_8; // v0
    u32 v0_9; // v0
    u32 v0;
    GetItemDataRet stackFrame_20[1] __attribute__((aligned(16)));

    s0 = (u16 *)a0;
    *(u16 *)((u8 *)&stackFrame_20[0]) = 0;
    switch (a1) {
    case 1:
        v1 = (u32)(u8 *)(MdlMng + 0x4600);
        if (v1 == 0) {
            v1 = 0;
        } else {
            v0 = *(s32 *)((v1 + 0x120));
            if ((s32)v0 <= (s32)0x1e) {
                a1 = (signed int)"fe_me_0015.t32";
                v0_7 = (u32)GetTexMngByBaseName((void *)0, "fe_me_0015.t32");
                v1 = v0_7;
            } else if ((s32)v0 <= (s32)0x46) {
                a1 = (signed int)"fe_me_0014.t32";
                v0_8 = (u32)GetTexMngByBaseName((void *)0, "fe_me_0014.t32");
                v1 = v0_8;
            } else {
                a1 = (signed int)"fe_me_0016.t32";
                v0_9 = (u32)GetTexMngByBaseName((void *)0, "fe_me_0016.t32");
                v1 = v0_9;
            }
        }
        if (v1 == 0) {
            *(u16 *)s0 = 0;
            break;
        } else {
            v1 = *(u16 *)(((u8 *)v1 + 2));
            *(u16 *)s0 = v1;
            break;
        }
    case 3:
        a0_2 = (void *)(s32)3;
        a1 = 2;
        v0 = KnMenuMng_GetCursorId((int)a0_2, a1);
        v1 = (s32)v0 < (s32)0x1a;
        if (v1 == 0 && (s32)v0 <= (s32)0x21) {
            v0 = v0 + 0x13;
            a1 = (u8)v0;
            a2 = 4;
            stackFrame_20[0] = GetItemData(a1, a2);
        } else {
            *(u16 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        v1 = *(u16 *)((u8 *)&stackFrame_20[0]);
        *(u16 *)s0 = v1;
        break;
    case 4:
        a0_2 = (void *)(s32)3;
        a1 = (s32)a0_2;
        v0 = KnMenuMng_GetCursorId((int)a0_2, a1);
        v1 = (s32)v0 < (s32)0x1a;
        if (v1 == 0 && (s32)v0 <= (s32)0x21) {
            v0 = v0 + 0x27;
            a1 = (u8)v0;
            a2 = 4;
            stackFrame_20[0] = GetItemData(a1, a2);
        }
        v1 = *(u16 *)((u8 *)&stackFrame_20[0]);
        *(u16 *)s0 = v1;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        a0_2 = (void *)(u8)a1;
        v0_6 = (u32)GetEquipTexMng((u8)a0_2);
        if (v0_6 == 0) {
            *(u16 *)s0 = 0;
            break;
        } else {
            v1 = *(u16 *)(((u8 *)v0_6 + 2));
            *(u16 *)s0 = v1;
            break;
        }
    case 13:
        v1 = 1;
        s_get_item_buf_on = v1;
        v1 = s_get_item_buf_wait;
        if ((s32)v1 > 0) {
            v1 = v1 + -1;
            s_get_item_buf_wait = v1;
        }
        v1 = s_get_item_buf_wait;
        a0_2 = (void *)0;
        if (v1 != 0) {
            goto _L001E8C28;
        }
        v0 = GetKeyState(0);
        a0_2 = (void *)(s32)1;
        if (v0 != 0) {
            goto _L001E8BB8;
        }
        v0 = GetKeyState((int)a0_2);
        if (v0 == 0) {
            goto _L001E8C28;
        }
        _L001E8BB8:;
        v0 = Menu_GetItemBufOn();
        a0_2 = (void *)0;
        if (v0 == 0) {
            goto _L001E8C20;
        }
        v0_4 = GetKeyState(0);
        a0_2 = (void *)(s32)0x11;
        if (v0_4 != 0) {
            a1 = 0x64;
            SND_Play2D((signed int)a0_2, a1, 0);
        }
        a0_2 = (void *)(s32)1;
        v0_5 = GetKeyState((int)a0_2);
        a0_2 = (void *)(s32)0x13;
        if (v0_5 != 0) {
            a1 = 0x64;
            SND_Play2D((signed int)a0_2, a1, 0);
        }
        Menu_ItemDataRingBuf();
        v1 = 0x3c;
        s_get_item_buf_wait = v1;
        goto _L001E8C28;
        _L001E8C20:;
        s_get_item_buf_on = 0;
    case 15:
        _L001E8C28:;
        v1 = s_get_item_id;
        if ((s32)v1 < 0) {
            *(u16 *)s0 = 0;
            break;
        } else {
            a0_2 = (void *)(u16)v1;
            v0_3 = (u32)ItemMng_GetItemTex_Direct((unsigned short)a0_2);
            if (v0_3 == 0) {
                *(u16 *)s0 = 0;
                break;
            } else {
                a0_2 = (void *)*(u16 *)((u8 *)&s_get_item_id);
                v0_2 = (u32)ItemMng_GetItemTex_Direct((unsigned short)a0_2);
                v1 = *(u16 *)(((u8 *)v0_2 + 2));
                *(u16 *)s0 = v1;
                break;
            }
        }
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
        a1 = (u8)(s32)a1;
        a2 = 4;
        stackFrame_20[0] = GetItemData(a1, a2);
        v1 = *(u16 *)((u8 *)&stackFrame_20[0]);
        *(u16 *)s0 = v1;
        break;
    case 0:
    case 2:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 37:
    case 38:
    case 39:
    case 40:
    case 57:
    case 58:
    case 59:
    case 60:
    default:
        *(u16 *)s0 = 0;
    }
    return;
}


/* MI_Init_CngTex @ 0x1E89C0 .. 0x1E89C8 (0x8 bytes) */




void MI_Init_CngTex(void) {
    return;
}
void MI_Check_CngTex(void *flags,s32 kind)
{
    *(u32 *)flags=0;
    if(KnMenuMng_CheckCtrlPlay(7,0)!=0) {
        if((s32)s_get_item_id/10000%10!=2) ((IconChangeFlags *)flags)[0].a|=1;
    }
    if(KnMenuMng_CheckCtrlPlay(7,0)!=0) {
        if((u32)kind==13 && (s32)s_get_item_id/10000%10==2) ((IconChangeFlags *)flags)[0].h|=1;
    }
    if(KnMenuMng_CheckCtrlPlay(7,0)!=0 && (u32)s_get_item_buf_on!=0) {
        ((IconChangeFlags *)flags)[1].g|=1;
        ((IconChangeFlags *)flags)[0].h|=1;
        ((IconChangeFlags *)flags)[1].a|=1;
        ((IconChangeFlags *)flags)[0].a|=1;
        ((IconChangeFlags *)flags)[0].b|=1;
    }
}


/* MI_Get_CngStr @ 0x1E8790 .. 0x1E8798 (0x8 bytes) */



void MI_Get_CngStr(void) {
    return;
}


/* MI_Set_CngStr @ 0x1E8780 .. 0x1E8788 (0x8 bytes) */



void MI_Set_CngStr(void) {
    return;
}


/* MI_Decide_CngStr @ 0x1E8770 .. 0x1E8778 (0x8 bytes) */



void MI_Decide_CngStr(void) {
    return;
}


/* MI_CntUp_CngStr @ 0x1E8760 .. 0x1E8768 (0x8 bytes) */



void MI_CntUp_CngStr(void) {
    return;
}






/* MI_CntDown_CngStr @ 0x1E8750 .. 0x1E8758 (0x8 bytes) */



void MI_CntDown_CngStr(void) {
    return;
}


/* MI_Gene1_CngStr @ 0x1E8740 .. 0x1E8748 (0x8 bytes) */



void MI_Gene1_CngStr(void) {
    return;
}






/* MI_Gene2_CngStr @ 0x1E8730 .. 0x1E8738 (0x8 bytes) */




void MI_Gene2_CngStr(void) {
    return;
}

void MI_Evrfrm_CngStr(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 *s0;
    s32 a2;
    u32 v1;
    u32 v0;
    u32 length;
    u16 *scan;
    u32 a0_2;
    signed int a1_2;
    GetItemDataRet stackFrame_20[1] __attribute__((aligned(16)));

    v1 = 0xa;
    s0 = (u32 *)a0;
    a0_2 = 3;
    switch ((u32)(s32)a1) {
    case 3:
        v0 = KnMenuMng_GetCursorId((int)a0_2, 2);
        if ((s32)v0 >= (s32)0x1a && (s32)v0 <= (s32)0x21) {
            stackFrame_20[0] = GetItemData((u8)(v0 + 0x13), 2);
        } else {
            *(u32 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        a1_2 = *(s32 *)((u8 *)&stackFrame_20[0]);
        if ((u32)(s32)a1_2 != 0) {
            v0 = *(u16 *)a1_2;
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)a1_2;
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            memcpy((void *)aTmpItemName, (void *)a1_2, a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
            break;
        } else {
            v0 = *(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            a1_2 = (signed int)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            memcpy((void *)aTmpItemName, (void *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
            break;
        }
    case 4:
        a0_2 = 3;
        v0 = KnMenuMng_GetCursorId((int)a0_2, (s32)a0_2);
        if ((s32)v0 >= (s32)0x1a && (s32)v0 <= (s32)0x21) {
            stackFrame_20[0] = GetItemData((u8)(v0 + 0x27), 2);
        } else {
            *(u32 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        a1_2 = *(s32 *)((u8 *)&stackFrame_20[0]);
        if ((u32)(s32)a1_2 != 0) {
            v0 = *(u16 *)a1_2;
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)a1_2;
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            memcpy((void *)aTmpItemName, (void *)a1_2, a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
            break;
        } else {
            v0 = *(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            a1_2 = (signed int)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            memcpy((void *)aTmpItemName, (void *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
            break;
        }
    case 10:
        a0_2 = 3;
        v0 = KnMenuMng_GetCursorId((int)a0_2, (s32)a0_2);
        if ((s32)v0 >= (s32)0x1a && (s32)v0 <= (s32)0x21) {
            stackFrame_20[0] = GetItemData((u8)(v0 + 0x27), 6);
        } else {
            *(u32 *)((u8 *)&stackFrame_20[0]) = 0;
        }
        a1_2 = *(s32 *)((u8 *)&stackFrame_20[0]);
        if ((u32)(s32)a1_2 != 0) {
            v0 = *(u16 *)a1_2;
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)a1_2;
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            memcpy((void *)aTmpItemName, (void *)a1_2, a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
            break;
        } else {
            v0 = *(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            length = 0;
            if (v0 != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    v0 = *scan;
                    length++;
                } while (v0 != 0);
            }
            a2 = (length << 1) + 2;
            a1_2 = (signed int)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            memcpy((void *)aTmpItemName, (void *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", a2);
            v1 = (u32)aTmpItemName_Left;
            *(void **)s0 = (void *)aTmpItemName_Left;
        }
    }
    return;
}


/* MI_Init_CngStr @ 0x1E83A0 .. 0x1E83A8 (0x8 bytes) */



void MI_Init_CngStr(void) {
    return;
}


/* MI_Check_CngStr @ 0x1E8390 .. 0x1E8398 (0x8 bytes) */



void MI_Check_CngStr(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_ItemScrl @ 0x1E8380 .. 0x1E8388 (0x8 bytes) */



void MI_Get_ItemScrl(void) {
    return;
}


/* MI_Set_ItemScrl @ 0x1E8370 .. 0x1E8378 (0x8 bytes) */




void MI_Set_ItemScrl(void) {
    return;
}
static inline void MI_Decide_ItemScrl__inl0(void) {
    u32 v1;
    u32 v0;

    v0 = no_snd_on;
    if (v0 == 0) {
        v0 = no_snd_counter;
        if ((s32)v0 > 0) {
            v0 = v0 + -1;
            no_snd_counter = v0;
        } else {
            SND_Play2D(0x16, 0x64, 0);
        }
    }
}
static inline void MI_Decide_ItemScrl__dlg(signed int msg) {
    u16 buf[504];
    u16 *str;

    str = KnMsgMng_GetMsgStr(msg);
    s_now_dialog_id = 0;
    if (str == 0) {
        s_DialogUseCounter = 0;
    } else if (s_DialogUseCounter == 0) {
        memcpy(buf, str, MI_Decide_ItemScrl__len(str) * 2 + 2);
        FsFontReplaceText(s_aDialogMsg, buf, 0);
        *(u8 *)&s_aDialogResult = 0;
        s_DialogUseCounter = 10;
        s_no_pad_check = 0;
    }
}
void MI_Decide_ItemScrl(signed int a0, s32 id) {
    u8 *lpMy;
    GetItemDataRet vari3;
    GetItemDataRet vari1;
    GetItemDataRet vari2;
    s32 swv;
    u8 next_wep_id;
    int cur;
    s32 r;

    __asm__("addi %0,%1,-12" : "=r"(swv) : "r"((s32)id));
    switch (swv) {
    case 0:
        lpMy = (u8 *)(MdlMng + 0x4600);
        if (now_equip_button == 2) {
            MI_Decide_ItemScrl__inl0();
            MI_Decide_ItemScrl__dlg(0x1881a);
            break;
        } else {
            if (SetMyEquip(lpMy, now_equip_button, 0, 0, 1) == 0) {
                break;
            }
            ChangeMyEquipSound();
            break;
        }
    case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
    case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24:
        {
            GetItemDataRet vari0;
            vari0 = GetItemData((u8)id, 1);
            vari3 = vari0;
        }
        lpMy = (u8 *)(MdlMng + 0x4600);
        if ((u16)ItemMng_GetItemNum_Direct((u16)*(s32 *)&vari3) == 0) {
            MI_Decide_ItemScrl__dlg(0x187de);
            MI_Decide_ItemScrl__inl0();
            s_EquipFaile = 1;
            break;
        } else {
            if (now_equip_button == 2) {
                if (CheckMyEquipLoad(lpMy, now_equip_button) != 0) {
                    break;
                }
                next_wep_id = (*(s32 *)&vari3 % 1000) - 1 - GameSt[0x14] * 3;
                if (*(u8 *)(*(s32 *)(lpMy + 0x148) + 0x1ad) == next_wep_id) {
                    MI_Decide_ItemScrl__dlg(0x187dd);
                    MI_Decide_ItemScrl__inl0();
                    s_EquipFaile = 1;
                    break;
                } else {
                    SetMyWeaponId(lpMy, next_wep_id);
                    s_EquipFaile = 0;
                    break;
                }
            } else {
                if (CheckMyEquipLoad(lpMy, now_equip_button) == 0) {
                    if (SetMyEquip(lpMy, now_equip_button, 1, *(s32 *)&vari3 % 1000, 1) != 0) {
                        s_EquipFaile = 0;
                        break;
                    }
                }
                s_EquipFaile = 1;
                MI_Decide_ItemScrl__inl0();
                MI_Decide_ItemScrl__dlg(0x187dd);
                break;
            }
        }
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
    case 37: case 38: case 39: case 40: case 41: case 42: case 43: case 44:
        if (KnMenuMng_CheckCtrlPlay(3, 2) == 0) {
            break;
        }
        cur = KnMenuMng_GetCursorId(3, 2);
        if (cur < 0x1a || cur > 0x21) {
            break;
        }
        vari1 = GetItemData((u8)id, 1);
        if ((u16)ItemMng_GetItemNum_Direct((u16)*(s32 *)&vari1) == 0) {
            MI_Decide_ItemScrl__dlg(0x187de);
            MI_Decide_ItemScrl__inl0();
            break;
        } else {
            r = ItemMng_ConsumeItem((u16)*(s32 *)&vari1);
            switch (r) {
            case 0:
                s_item_use_check = 0;
                MI_Decide_ItemScrl__inl0();
                if (*(s32 *)&vari1 == 0x36cd) {
                    MI_Decide_ItemScrl__dlg(0x1d4e5);
                    break;
                } else {
                    MI_Decide_ItemScrl__dlg(0x1d4df);
                    break;
                }
            case 1:
                s_item_use_check = 1;
                break;
            default:
                s_item_use_check = 0;
                break;
            }
            break;
        }
    case 49: case 50: case 51: case 52: case 53: case 54: case 55: case 56:
    case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64:
        if (KnMenuMng_CheckCtrlPlay(3, 3) == 0) {
            break;
        }
        cur = KnMenuMng_GetCursorId(3, 2);
        if (cur < 0x1a || cur > 0x21) {
            break;
        }
        vari2 = GetItemData((u8)id, 1);
        if ((u16)ItemMng_GetItemNum_Direct((u16)*(s32 *)&vari2) == 0) {
            MI_Decide_ItemScrl__dlg(0x187de);
            MI_Decide_ItemScrl__inl0();
            s_BookFaile = 1;
            break;
        } else {
            s_BookFaile = 0;
            break;
        }
    default:
        break;
    }
}




static signed int Menu_ScrlCheck_down(signed int id) {
    signed int item_type;
    int ret;
    int max_num;

    ret = 0;
    switch (({ s32 r_; __asm__("addi %0,%1,-21" : "=r"(r_) : "r"(id)); r_; })) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        item_type = 3;
        switch (now_equip_button) {
        case 255:
        case 1:
        case 0:
            item_type = 3;
            break;
        case 2:
            item_type = 4;
            break;
        }
        max_num = ItemMng_GetItemMaxNum(item_type);
        if (equip_offset < (max_num + 2) / 3 - 2) {
            ret = 1;
        }
        break;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
        max_num = ItemMng_GetItemMaxNum(1);
        if (item_offset < (max_num + 3) / 4 - 2) {
            ret = 2;
        }
        break;
    case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
        max_num = ItemMng_GetItemMaxNum(2);
        if (book_offset < (max_num + 3) / 4 - 2) {
            ret = 3;
        }
        break;
    default:
        break;
    }
    return ret;
}












static signed int Menu_CheckItemOnCursor(int id, int item_id) {
    unsigned short item_type;
    int type_offset;
    int ret;
    int type;
    int max_num;

    ret = 0;
    switch (({ s32 r_; __asm__("addi %0,%1,-21" : "=r"(r_) : "r"(id)); r_; })) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        type = item_id - 2;
        item_type = 3;
        switch (now_equip_button) {
        case 255:
        case 1:
        case 0:
            item_type = 3;
            break;
        case 2:
            item_type = 4;
            break;
        }
        type_offset = type + equip_offset * 3 - 0x17;
        break;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
        item_type = 1;
        type = item_id + 0x13;
        type_offset = type + item_offset * 4 - 0x2c;
        break;
    case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
        item_type = 2;
        type = item_id + 0x27;
        type_offset = type + book_offset * 4 - 0x40;
        break;
    default:
        item_type = 0;
        break;
    }
    max_num = ItemMng_GetItemMaxNum(item_type);
    if (max_num >= type_offset) {
        ret = 1;
    }
    return ret;
}

signed int Menu_CursorMoveNext(signed int id, int udlr) {
    s32 cur;
    s32 next;

    next = 0;
    switch (MCN_ADDI21(id)) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        cur = KnMenuMng_GetCursorId(3, 1);
        switch (MCN_ADDI26(cur)) {
        case 0:
        case 1:
            if ((u8)udlr == 4) {
                MCN_D4()
            }
            if ((u8)udlr == 2) {
                MCN_U(3)
            }
            break;
        case 2:
            if ((u8)udlr == 4) {
                next = 0x19;
            }
            if ((u8)udlr == 2) {
                MCN_U(3)
            }
            break;
        case 3:
        case 4:
            if ((u8)udlr == 4) {
                MCN_D4()
            }
            if ((u8)udlr == 2) {
                MCN_N(3)
                MCN_ADJ(0x1f, 0x11, 3)
            }
            break;
        case 5:
            if ((u8)udlr == 4) {
                next = 0x19;
            }
            if ((u8)udlr == 2) {
                MCN_N(3)
                MCN_ADJ(0x1f, 0x11, 3)
            }
            break;
        }
        break;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
    case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
    case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
        switch (MCN_ADDI41(id)) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            cur = KnMenuMng_GetCursorId(3, 2);
            break;
        case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35:
            cur = KnMenuMng_GetCursorId(3, 3);
            break;
        }
        switch (MCN_ADDI26(cur)) {
        case 0:
        case 1:
        case 2:
            if ((u8)udlr == 4) {
                MCN_D4N()
            }
            if ((u8)udlr == 2) {
                MCN_U(4)
            }
            break;
        case 3:
            if ((u8)udlr == 4) {
                MCN_D4N()
            }
            if ((u8)udlr == 2) {
                MCN_U(4)
            }
            break;
        case 4:
        case 5:
        case 6:
            if ((u8)udlr == 4) {
                MCN_D4N()
            }
            if ((u8)udlr == 2) {
                MCN_N(4)
                MCN_ADJ(0x21, 0x14, 4)
            }
            break;
        case 7:
            if ((u8)udlr == 4) {
                MCN_D4N()
                MCN_ADJ(0x21, 0x14, 4)
            }
            if ((u8)udlr == 2) {
                MCN_N(4)
                MCN_ADJ(0x21, 0x14, 4)
            }
            break;
        }
        break;
    }
    return next;
}

void MI_CntUp_ItemScrl(signed int a0 /* r4 */, s32 a1) {
    u32 v1;

    v1 = ({ s32 native_result_0; __asm__("addi %0,%1,-21" : "=r"(native_result_0) : "r"(a1));
        native_result_0; });
    a1 = 0;
    switch (v1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        v1 = equip_offset;
        if ((s32)v1 <= 0) {
            break;
        }
        a1 = 1;
        break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
        v1 = item_offset;
        if ((s32)v1 <= 0) {
            break;
        }
        a1 = 2;
        break;
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
        v1 = book_offset;
        if ((s32)v1 <= 0) {
            break;
        }
        a1 = 3;
    case 16:
    case 17:
    case 18:
    case 19:
    case 36:
    case 37:
    case 38:
    case 39:
    default:
        break;
    }
    s_scrl_on = 0;
    if (a1 > 0) {
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch ((u32)a1) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + -1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + -1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + -1;
            book_offset = v1;
        }
        a0 = 3;
        v1 = 4;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
        s_force_anim_ratio = 0.0f;
    }
    return;
}


/* MI_CntDown_ItemScrl @ 0x1E6FA0 .. 0x1E703C (0x9c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   a0 takes slot 0 only because of the ABI order
 *   declaration vs inferred signature: return void vs inferred u32; 1 parameters vs 2 inferred
 */


void MI_CntDown_ItemScrl(signed int a0 /* r4 */, s32 a1) {
    u32 v1;
    u32 v0;

    a0 = a1;
    v0 = Menu_ScrlCheck_down(a0);
    s_scrl_on = 0;
    if ((s32)v0 > 0) {
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
    }
    return;
}

void MI_Gene1_ItemScrl(signed int a0 /* r4 */, s32 a1) {
    u32 s1;
    u32 a2;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u32 s0;
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0_7; // v0
    u32 v0;
    u32 s2;

    v1 = 0x64;
    s1 = a1;
    s0 = (s32)s1 % 0x64;
    v1 = ({ s32 native_result_0; __asm__ volatile("addi %0,%1,-12" : "=r"(native_result_0) :
        "r"((s32)s0) : "memory"); native_result_0; });
    switch (v1) {
    case 0:
        a0 = 0x1a;
        a1 = 0x1c;
        v0 = Menu_CheckItemOnCursor(a0, a1);
        a2 = 0x1c;
        switch (v0) {
        case 0:
            a0 = 0x19;
            a1 = 0x1b;
            v0 = Menu_CheckItemOnCursor(a0, a1);
            a2 = 0x1b;
            switch (v0) {
            case 0:
                a0 = 0x18;
                a1 = 0x1a;
                Menu_CheckItemOnCursor(a0, a1);
                a2 = 0x1a;
            }
        }
        a0 = 3;
        if (a2 == 0) {
            break;
        }
        a1 = 1;
        KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
        a0 = 3;
        a1 = 1;
        v0_6 = KnMenuMng_GetCursorId(a0, a1);
        a0 = s0;
        a1 = 4;
        s0 = v0_6;
        v0_7 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_7;
        if (a2 == 0 || (u32)(s0 + 1) == a2) {
            break;
        }
        a0 = 3;
        a1 = 1;
        KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        break;
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
        a0 = 3;
        a1 = 2;
        v0_4 = KnMenuMng_GetCursorId(a0, a1);
        s2 = v0_4;
        a0 = s0;
        a1 = 4;
        v0_5 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_5;
        if (a2 != 0 && (u32)(s2 + 1) != a2) {
            a0 = 3;
            a1 = 2;
            KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        }
        v1 = 0x34;
        if (s0 != v1) {
            break;
        }
        a0 = s1;
        v0 = Menu_ScrlCheck_down(a0);
        s_scrl_on = 0;
        if ((s32)v0 <= 0) {
            break;
        }
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
        break;
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
        a0 = 3;
        a1 = a0;
        v0_2 = KnMenuMng_GetCursorId(a0, a1);
        s2 = v0_2;
        a0 = s0;
        a1 = 4;
        v0_3 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_3;
        if (a2 != 0 && (u32)(s2 + 1) != a2) {
            a0 = 3;
            a1 = a0;
            KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        }
        v1 = 0x48;
        if (s0 != v1) {
            break;
        }
        a0 = s1;
        v0 = Menu_ScrlCheck_down(a0);
        s_scrl_on = 0;
        if ((s32)v0 <= 0) {
            break;
        }
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 25:
    case 26:
    case 27:
    case 28:
    case 45:
    case 46:
    case 47:
    case 48:
    default:
        break;
    }
    return;
}

void MI_Gene2_ItemScrl(signed int a0 /* r4 */, s32 a1) {
    u32 s1;
    u32 a2;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    s32 s0;
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0_7; // v0
    u32 s2;
    u32 v0;

    v1 = 0x64;
    s1 = a1;
    s0 = (s32)s1 % 0x64;
    v1 = ({ s32 native_result_0; __asm__ volatile("addi %0,%1,-21" : "=r"(native_result_0) :
        "r"(s0) : "memory"); native_result_0; });
    switch (v1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        a0 = 3;
        a1 = 1;
        v0_6 = KnMenuMng_GetCursorId(a0, a1);
        s2 = v0_6;
        a0 = s0;
        a1 = 2;
        v0_7 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_7;
        if (a2 != 0 && (u32)(s2 + 3) != a2) {
            a0 = 3;
            a1 = 1;
            KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        }
        v1 = s0 < (s32)0x1b;
        if (v1 != 0 || s0 > (s32)0x1d) {
            break;
        }
        a0 = s1;
        v0 = Menu_ScrlCheck_down(a0);
        s_scrl_on = 0;
        if ((s32)v0 <= 0) {
            break;
        }
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
        break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
        a0 = 3;
        a1 = 2;
        v0_4 = KnMenuMng_GetCursorId(a0, a1);
        s2 = v0_4;
        a0 = s0;
        a1 = 2;
        v0_5 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_5;
        if (a2 != 0 && (u32)(s2 + 4) != a2) {
            a0 = 3;
            a1 = 2;
            KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        }
        v1 = s0 < (s32)0x31;
        if (v1 != 0 || s0 > (s32)0x34) {
            break;
        }
        a0 = s1;
        v0 = Menu_ScrlCheck_down(a0);
        s_scrl_on = 0;
        if ((s32)v0 <= 0) {
            break;
        }
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
        break;
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
        a0 = 3;
        a1 = a0;
        v0_2 = KnMenuMng_GetCursorId(a0, a1);
        s2 = v0_2;
        a0 = s0;
        a1 = 2;
        v0_3 = Menu_CursorMoveNext(a0, a1);
        a2 = v0_3;
        if (a2 != 0 && (u32)(s2 + 4) != a2) {
            a0 = 3;
            a1 = a0;
            KnMenuMng_SetForceChangeCursorId(a0, a1, a2);
        }
        v1 = s0 < (s32)0x45;
        if (v1 != 0 || s0 > (s32)0x48) {
            break;
        }
        a0 = s1;
        v0 = Menu_ScrlCheck_down(a0);
        s_scrl_on = 0;
        if ((s32)v0 <= 0) {
            break;
        }
        a0 = 1;
        v1 = 3;
        s_scrl_on = a0;
        switch (v0) {
        case 1:
            v1 = equip_offset;
            v1 = v1 + 1;
            equip_offset = v1;
            break;
        case 2:
            v1 = item_offset;
            v1 = v1 + 1;
            item_offset = v1;
            break;
        case 3:
            v1 = book_offset;
            v1 = v1 + 1;
            book_offset = v1;
        }
        a0 = 5;
        v1 = 6;
        s_force_anim_ratio = 0.0f;
        s_force_anim_id_u = a0;
        s_force_anim_id_d = v1;
    case 16:
    case 17:
    case 18:
    case 19:
    case 36:
    case 37:
    case 38:
    case 39:
    default:
        break;
    }
    return;
}



void MI_Evrfrm_ItemScrl(void *a0 /* r4 */, signed int a1 /* r5 */) {
    s32 a3;
    u32 a2;
    s32 v1;
    u32 v0;
    float f1;
    float f0;

    a2 = 0x64;
    v1 = 0x51eb0000;
    a2 = 0x51eb0000 | 0x851f;
    v1 = (s32)a1 % 0x64;
    a3 = (s32)a1 / 0x64;
    s_item_use_check = 0;
    __asm__("addi %0,%1,-12" : "+r"(a1) : "r"(v1));
    switch (a1) {
    case 0:
    case 2:
        a1 = now_equip_button;
        v1 = 2;
        switch ((u32)a1) {
        case 255:
            v1 = *(s32 *)a0;
            a0 = (void *)(s32)0xc;
            *(u32 *)((v1 + 0x50)) = (s32)a0;
            break;
        case 0:
            v1 = *(s32 *)a0;
            a0 = (void *)(s32)0xc;
            *(u32 *)((v1 + 0x50)) = (s32)a0;
            break;
        case 1:
            v1 = *(s32 *)a0;
            a0 = (void *)(s32)0xc;
            *(u32 *)((v1 + 0x50)) = (s32)a0;
            break;
        case 2:
            v1 = *(s32 *)a0;
            a0 = (void *)(s32)0xe;
            *(u32 *)((v1 + 0x50)) = (s32)a0;
            break;
        }
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
        a1 = ({ s32 offset; __asm__("addi %0,%1,-21" : "=r"(offset) : "r"(v1)); offset; });
        switch (a1) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            a1 = now_equip_button;
            a1 = (u32)(signed int)((u32)(a1) ^ 2) < (u32)1;
            if ((u32)a3 == (u32)(s32)a1) {
                goto _L001E68A0;
            }
            v1 = *(s32 *)a0;
            *(u32 *)((v1 + 0x50)) = 0;
            goto _L001E6A00;
            _L001E68A0:;
            v0 = 6;
            break;
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
            v0 = 8;
            break;
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            v0 = 8;
        case 16:
        case 17:
        case 18:
        case 19:
        case 36:
        case 37:
        case 38:
        case 39:
        default:
            break;
        }
        a1 = 0x15;
        if (v1 == (u32)(s32)a1 && (s32)s_force_anim_id_u >= 0) {
            f0 = 0.05f;
            s_force_anim_ratio = (s_force_anim_ratio + f0);
        }
        a1 = 0x29;
        if (v1 == (u32)(s32)a1 && (s32)s_force_anim_id_u >= 0) {
            f0 = 0.05f;
            s_force_anim_ratio = (s_force_anim_ratio + f0);
        }
        a1 = 0x3d;
        if (v1 == (u32)(s32)a1 && (s32)s_force_anim_id_u >= 0) {
            f0 = 0.05f;
            s_force_anim_ratio = (s_force_anim_ratio + f0);
        }
        f1 = s_force_anim_ratio;
        a1 = -1;
        if (!(f1 <= 1.0f)) {
            s_force_anim_ratio = 0.0f;
            s_force_anim_id_u = a1;
            s_force_anim_id_d = a1;
        }
        a1 = 0x14;
        a1 = (s32)v1 % 0x14;
        if ((s32)a1 <= (s32)v0) {
            *(u32 *)(*(s32 *)a0 + 0x60) = s_force_anim_id_u;
            f0 = s_force_anim_ratio;
            v0 = *(s32 *)a0;
            *(f32 *)((v0 + 0x64)) = f0;
        } else {
            *(u32 *)(*(s32 *)a0 + 0x60) = s_force_anim_id_d;
            f0 = s_force_anim_ratio;
            v0 = *(s32 *)a0;
            *(f32 *)((v0 + 0x64)) = f0;
        }
        v0 = *(s32 *)a0;
        a1 = v1;
        a0 = (void *)(s32)(v0 + 0x50);
        MI_Evrfrm_CngTex(a0, a1);
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 25:
    case 26:
    case 27:
    case 28:
    case 45:
    case 46:
    case 47:
    case 48:
    default:
        *(u16 *)a0 = 0;
    }
    _L001E6A00:;
    return;
}


/* MI_Init_ItemScrl @ 0x1E6770 .. 0x1E6778 (0x8 bytes) */




void MI_Init_ItemScrl(void) {
    return;
}


/* MI_Check_ItemScrl @ 0x1E6240 .. 0x1E6764 (0x524 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e628c writes a register its branch at 0x1e6288 reads
 *   delay: addiu at 0x1e62f0 writes a register its branch at 0x1e62ec reads
 *   delay: addiu at 0x1e6358 writes a register its branch at 0x1e6354 reads
 *   stack: address of the slot at 0x30 escapes at 0x1e63cc
 *   stack: address of the slot at 0x30 escapes at 0x1e646c
 *   cfg: kept branch: 0x1e6480 if (..) goto .L001E64B8
 *   declaration vs inferred signature: return void vs inferred u32
 */

void MI_Check_ItemScrl(struct ItemScrlBits *pVariable, signed int id) {
    int cur;
    GetItemDataRet vari;

    *(u32 *)pVariable = 0;
    if (KnMenuMng_CheckCtrlPlay(3, 1)) {
        cur = KnMenuMng_GetCursorId(3, 1);
        if (equip_offset == 0 && s_scrl_on == 0) {
            if (cur == 0x1a) {
                pVariable->b1_3 = pVariable->b1_3 | 1;
            }
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 2)) {
        cur = KnMenuMng_GetCursorId(3, 2);
        if (item_offset == 0 && s_scrl_on == 0) {
            if (cur == 0x1a) {
                pVariable->b1_3 = pVariable->b1_3 | 1;
            }
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 3)) {
        cur = KnMenuMng_GetCursorId(3, 3);
        if (book_offset == 0 && s_scrl_on == 0) {
            if (cur == 0x1a) {
                pVariable->b1_3 = pVariable->b1_3 | 1;
            }
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 3)) {
        cur = KnMenuMng_GetCursorId(3, 3);
        if (cur >= 0x1a && cur <= 0x21) {
            vari = GetItemData((u8)(cur + 0x27), 1);
            if (*(s32 *)&vari == 0) {
                pVariable->b0_0 = pVariable->b0_0 | 1;
            }
        }
        if (s_BookFaile != 0) {
            pVariable->b0_0 = pVariable->b0_0 | 1;
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 1)) {
        cur = KnMenuMng_GetCursorId(3, 1);
        if (cur >= 0x1a && cur <= 0x1f) {
            vari = GetItemData((u8)(cur - 2), 1);
            if (*(s32 *)&vari == 0 || s_EquipFaile == 1) {
                pVariable->b0_7 = pVariable->b0_7 | 1;
            }
        }
    }
    if (id == 0xc) {
        if (now_equip_button == 2) {
            pVariable->b0_7 = pVariable->b0_7 | 1;
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 2) && s_item_use_check == 0) {
        pVariable->b0_0 = pVariable->b0_0 | 1;
    }
    if (KnMenuMng_CheckCtrlPlay(3, 1)) {
        cur = KnMenuMng_GetCursorId(3, 1);
        if (cur >= 0x1a && cur <= 0x1c && s_scrl_on == 0) {
            pVariable->b1_1 = pVariable->b1_1 | 1;
        }
        if (cur >= 0x1d && cur <= 0x1f && s_scrl_on == 0) {
            pVariable->b1_2 = pVariable->b1_2 | 1;
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 2)) {
        cur = KnMenuMng_GetCursorId(3, 2);
        if (cur >= 0x1a && cur <= 0x1d && s_scrl_on == 0) {
            pVariable->b1_1 = pVariable->b1_1 | 1;
        }
        if (cur >= 0x1e && cur <= 0x21 && s_scrl_on == 0) {
            pVariable->b1_2 = pVariable->b1_2 | 1;
        }
    }
    if (KnMenuMng_CheckCtrlPlay(3, 3)) {
        cur = KnMenuMng_GetCursorId(3, 3);
        if (cur >= 0x1a && cur <= 0x1d && s_scrl_on == 0) {
            pVariable->b1_1 = pVariable->b1_1 | 1;
        }
        if (cur >= 0x1e && cur <= 0x21 && s_scrl_on == 0) {
            pVariable->b1_2 = pVariable->b1_2 | 1;
        }
    }
}


/* MI_Get_Equip @ 0x1E6230 .. 0x1E6238 (0x8 bytes) */



void MI_Get_Equip(void) {
    return;
}


/* MI_Set_Equip @ 0x1E6220 .. 0x1E6228 (0x8 bytes) */



void MI_Set_Equip(void) {
    return;
}

static inline s32 MI_Decide_Equip__inl0(void) {
    s32 s2;
    u32 s1;
    s32 s0;
    u32 v1;
    u32 v0;
    void *a0_2;
    signed int a1_2;

    a0_2 = (void *)(s32)3;
    s1 = (u16)ItemMng_GetItemMaxNum((unsigned short)a0_2);
    s0 = 0;
    s2 = 0;
    if (0 < (s32)s1) {
        do {
            a1_2 = (u16)s2;
            a0_2 = (void *)(s32)3;
            v0 = ItemMng_GetItemBySequence((unsigned short)a0_2, a1_2);
            v1 = 0x3e8;
            a0_2 = (void *)(s32)3;
            v0 = (s32)v0 % 0x3e8;
            a1_2 = (u16)v0;
            v1 = (u16)ItemMng_GetItemNum((unsigned short)a0_2, a1_2);
            if ((s32)v1 > 0) {
                s0 = 1;
            }
            s2 = s2 + 1;
            v1 = s2 < (s32)s1;
        } while (v1 != 0);
    }
    return s0;
}

static inline void MI_Decide_Equip__inl1(u8 *fr_430) {
    u32 a2;
    u32 v1;
    u32 v0;
    void *a0_2;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0x86e3);
    a1_2 = (signed int)KnMsgMng_GetMsgStr((signed int)a0_2);
    s_now_dialog_id = 0;
    if ((u32)a1_2 == 0) {
        s_DialogUseCounter = 0;
    } else {
        v1 = s_DialogUseCounter;
        if (v1 == 0) {
            a0_2 = (void *)MI_Decide_Equip__lenu16((u16 *)a1_2);
            v0 = (u32)a0_2 << 1;
            a2 = v0 + 2;
            memcpy((void *)(u8 *)fr_430, (void *)a1_2, a2);
            a0_2 = (void *)s_aDialogMsg;
            FsFontReplaceText((void *)s_aDialogMsg, (void *)(u8 *)fr_430, 0);
            v1 = 0xa;
            *(u8 *)((u8 *)&s_aDialogResult) = 0;
            s_DialogUseCounter = v1;
            s_no_pad_check = 0;
        }
    }
}

static inline void MI_Decide_Equip__inl2(void) {
    u32 v1;
    void *a0_2;
    signed int a1_2;

    v1 = no_snd_on;
    if (v1 != 0) {
        return;
    }
    v1 = no_snd_counter;
    if ((s32)v1 > 0) {
        v1 = v1 + -1;
        no_snd_counter = v1;
        return;
    } else {
        a0_2 = (void *)(s32)0x16;
        a1_2 = 0x64;
        SND_Play2D((signed int)a0_2, a1_2, 0);
        return;
    }
}

static inline s32 MI_Decide_Equip__inl3(void) {
    s32 s2;
    u32 s1;
    s32 s0;
    u32 v1;
    u32 v0;
    void *a0_2;
    signed int a1_2;

    a0_2 = (void *)(s32)4;
    s1 = (u16)ItemMng_GetItemMaxNum((unsigned short)a0_2);
    s0 = 0;
    s2 = 0;
    if (0 < (s32)s1) {
        do {
            a1_2 = (u16)s2;
            a0_2 = (void *)(s32)4;
            v0 = ItemMng_GetItemBySequence((unsigned short)a0_2, a1_2);
            v1 = 0x3e8;
            a0_2 = (void *)(s32)4;
            v0 = (s32)v0 % 0x3e8;
            a1_2 = (u16)v0;
            v1 = (u16)ItemMng_GetItemNum((unsigned short)a0_2, a1_2);
            if ((s32)v1 > 0) {
                s0 = 1;
            }
            s2 = s2 + 1;
            v1 = s2 < (s32)s1;
        } while (v1 != 0);
    }
    return s0;
}

static inline void MI_Decide_Equip__inl4(u8 *fr_40) {
    u32 a2;
    u32 v1;
    u32 v0;
    void *a0_2;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0x86e6);
    a1_2 = (signed int)KnMsgMng_GetMsgStr((signed int)a0_2);
    s_now_dialog_id = 0;
    if ((u32)a1_2 == 0) {
        s_DialogUseCounter = 0;
    } else {
        v1 = s_DialogUseCounter;
        if (v1 == 0) {
            a0_2 = (void *)MI_Decide_Equip__lenu16((u16 *)a1_2);
            v0 = (u32)a0_2 << 1;
            a2 = v0 + 2;
            memcpy((void *)(u8 *)fr_40, (void *)a1_2, a2);
            a0_2 = (void *)s_aDialogMsg;
            FsFontReplaceText((void *)s_aDialogMsg, (void *)(u8 *)fr_40, 0);
            v1 = 0xa;
            *(u8 *)((u8 *)&s_aDialogResult) = 0;
            s_DialogUseCounter = v1;
            s_no_pad_check = 0;
        }
    }
}

static inline void MI_Decide_Equip__inl5(void) {
    u32 v1;
    void *a0_2;
    signed int a1_2;

    v1 = no_snd_on;
    if (v1 != 0) {
        return;
    }
    v1 = no_snd_counter;
    if ((s32)v1 > 0) {
        v1 = v1 + -1;
        no_snd_counter = v1;
        return;
    } else {
        a0_2 = (void *)(s32)0x16;
        a1_2 = 0x64;
        SND_Play2D((signed int)a0_2, a1_2, 0);
    }
}

void MI_Decide_Equip(void *a0 /* r4 */, signed int a1 /* r5 */) {
    s32 s0;
    u32 v1;
    u32 v0;
    u8 stackFrame_430[1008] __attribute__((aligned(16)));
    u8 stackFrame_40[1008] __attribute__((aligned(16)));

    v1 = 8;
    *(u32 *)a0 = 0;
    switch ((u32)(s32)a1) {
    case 5:
    case 6:
    case 7:
        s0 = MI_Decide_Equip__inl0();
        if ((u32)s0 != 0) {
            break;
        }
        v0 = 0x10000;
        MI_Decide_Equip__inl1(((u8 *)&stackFrame_430[0]));
        MI_Decide_Equip__inl2();
        break;
    case 8:
        s0 = MI_Decide_Equip__inl3();
        if ((u32)s0 != 0) {
            break;
        }
        v0 = 0x10000;
        MI_Decide_Equip__inl4(((u8 *)&stackFrame_40[0]));
        MI_Decide_Equip__inl5();
    }
    return;
}


/* MI_CntUp_Equip @ 0x1E5F10 .. 0x1E5F18 (0x8 bytes) */



void MI_CntUp_Equip(void) {
    return;
}


/* MI_CntDown_Equip @ 0x1E5F00 .. 0x1E5F08 (0x8 bytes) */



void MI_CntDown_Equip(void) {
    return;
}


/* MI_Gene1_Equip @ 0x1E5EF0 .. 0x1E5EF8 (0x8 bytes) */



void MI_Gene1_Equip(void) {
    return;
}


/* MI_Gene2_Equip @ 0x1E5EE0 .. 0x1E5EE8 (0x8 bytes) */




void MI_Gene2_Equip(void) {
    return;
}


void MI_Evrfrm_Equip(void *entry, signed int id) {
    s32 cursor=KnMenuMng_GetCursorId(3,1);
    switch(cursor) {
    case 11: now_equip_button=255; break;
    case 12: now_equip_button=0; break;
    case 13: now_equip_button=1; break;
    case 21: equip_offset=0; now_equip_button=2; break;
    }
    switch(cursor) {
    case 11: case 12: case 13: case 21: item_offset=0; book_offset=0;
    }
    switch(id) {
    case 5: case 6: case 7: case 8:
        MI_Evrfrm_CngTex(entry,id);
        switch(now_equip_button) {
        case 255: if(id==5) *(u16*)entry=0; break;
        case 0: if(id==6) *(u16*)entry=0; break;
        case 1: if(id==7) *(u16*)entry=0; break;
        case 2: if(id==8) *(u16*)entry=0; break;
        }
        break;
    case 105: case 106: case 107: case 108:
        MI_Evrfrm_CngTex(entry,id%100);
        if(!*(u16*)entry) *(u32*)entry=!id;
        else *(u32*)entry=id;
        break;
    case 205: case 206: case 207: case 208:
        switch(now_equip_button) {
        case 255:
          if(id==205) MI_Evrfrm_CngTex(entry,id%100);
          else { *(u16*)entry=0; return; } break;
        case 0:
          if(id==206) MI_Evrfrm_CngTex(entry,id%100);
          else { *(u16*)entry=0; return; } break;
        case 1:
          if(id==207) MI_Evrfrm_CngTex(entry,id%100);
          else { *(u16*)entry=0; return; } break;
        case 2:
          if(id==208) MI_Evrfrm_CngTex(entry,id%100);
          else { *(u16*)entry=0; return; } break;
        default: *(u16*)entry=0;
        }
        break;
    }
}


/* MI_Init_Equip @ 0x1E5B70 .. 0x1E5B78 (0x8 bytes) */




void MI_Init_Equip(void) {
    return;
}


void MI_Check_Equip(void *a0, signed int a1) {
    *(u32 *)a0 = 0;
    switch (a1) {
    case 5:
    case 6:
    case 7: {
    s32 ia;
    u16 maxa;
    s32 founda;
    s32 va;
    u32 na;
        maxa = ItemMng_GetItemMaxNum(3);
        founda = 0;
        for (ia = 0; ia < maxa; ia++) {
            va = ItemMng_GetItemBySequence(3, ia);
            va %= 1000;
            na = ItemMng_GetItemNum(3, (u16)va);
            if ((u16)na > 0) {
                founda = 1;
            }
        }
        if (founda) {
            break;
        }
        ((MICheckBits *)a0)->bit0 |= 1;
        break;
    }
    case 8: {
    s32 ib;
    u16 maxb;
    s32 foundb;
    s32 vb;
    u32 nb;
        maxb = ItemMng_GetItemMaxNum(4);
        foundb = 0;
        for (ib = 0; ib < maxb; ib++) {
            vb = ItemMng_GetItemBySequence(4, ib);
            vb %= 1000;
            nb = ItemMng_GetItemNum(4, (u16)vb);
            if ((u16)nb > 0) {
                foundb = 1;
            }
        }
        if (foundb) {
            break;
        }
        ((MICheckBits *)a0)->bit0 |= 1;
        break;
    }
    }
}


/* MI_Get_Num @ 0x1E59B0 .. 0x1E59B8 (0x8 bytes) */



void MI_Get_Num(void) {
    return;
}


/* MI_Set_Num @ 0x1E59A0 .. 0x1E59A8 (0x8 bytes) */



void MI_Set_Num(void) {
    return;
}


/* MI_Decide_Num @ 0x1E5990 .. 0x1E5998 (0x8 bytes) */



void MI_Decide_Num(void) {
    return;
}


/* MI_CntUp_Num @ 0x1E5980 .. 0x1E5988 (0x8 bytes) */



void MI_CntUp_Num(void) {
    return;
}


/* MI_CntDown_Num @ 0x1E5970 .. 0x1E5978 (0x8 bytes) */



void MI_CntDown_Num(void) {
    return;
}


/* MI_Gene1_Num @ 0x1E5960 .. 0x1E5968 (0x8 bytes) */



void MI_Gene1_Num(void) {
    return;
}


/* MI_Gene2_Num @ 0x1E5950 .. 0x1E5958 (0x8 bytes) */




void MI_Gene2_Num(void) {
    return;
}



void MI_Evrfrm_Num(void *output, s32 number)
{
    u8 *destination;
    s32 kind;
    u32 value;
    GetItemDataRet item0[1] __attribute__((aligned(16)));
    GetItemDataRet item1[1] __attribute__((aligned(16)));
    GetItemDataRet item2[1] __attribute__((aligned(16)));
    GetItemDataRet item3[1] __attribute__((aligned(16)));

    __asm__("addi %0,%1,-3" : "=r"(kind) : "r"(number));
    *(u32 *)output = 0;
    destination = output;
    switch ((u32)kind) {
    case 2: case 3: case 4: case 5:
        *(u32 *)destination = GetEquipNum((u8)number);
        break;
    case 10:
        if (s_get_item_id < 0) *(u32 *)destination = 0;
        else *(u32 *)destination = s_now_get_item_num;
        if (s_get_item_id / 10000 == 2) *(u32 *)destination = 0;
        break;
    case 0:
        value = KnMenuMng_GetCursorId(3, 2);
        if ((s32)value >= 26 && (s32)value <= 33) {
            item0[0] = GetItemData((u8)(value + 19), 5);
            *(u_long128 *)destination = *(u_long128 *)(u32)item0;
        } else *(u32 *)destination = 0;
        break;
    case 1:
        value = KnMenuMng_GetCursorId(3, 3);
        if ((s32)value >= 26 && (s32)value <= 33) {
            item1[0] = GetItemData((u8)(value + 39), 5);
            *(u_long128 *)destination = *(u_long128 *)(u32)item1;
        } else *(u32 *)destination = 0;
        break;
    case 18: case 19: case 20: case 21:
    case 22: case 23: case 24: case 25:
    case 26: case 27: case 28: case 29:
    case 30: case 31: case 32: case 33:
        switch (now_equip_button) {
        case 255: case 1: case 0:
            item2[0] = GetItemData((u8)number, 5);
            *(u_long128 *)destination = *(u_long128 *)(u32)item2;
            break;
        case 2:
            *(u32 *)destination = 0;
            break;
        }
        break;
    case 38: case 39: case 40: case 41:
    case 42: case 43: case 44: case 45:
    case 46: case 47: case 48: case 49:
    case 50: case 51: case 52: case 53:
    case 58: case 59: case 60: case 61:
    case 62: case 63: case 64: case 65:
    case 66: case 67: case 68: case 69:
    case 70: case 71: case 72: case 73:
        item3[0] = GetItemData((u8)number, 5);
        *(u_long128 *)destination = *(u_long128 *)(u32)item3;
        break;
    default:
        break;
    }
    *(u32 *)destination += 0x188f8;
    *(u32 *)destination = (u32)KnMsgMng_GetMsgStr(*(s32 *)destination);
}


/* MI_Init_Num @ 0x1E5740 .. 0x1E5748 (0x8 bytes) */



void MI_Init_Num(void) {
    return;
}


/* MI_Check_Num @ 0x1E5730 .. 0x1E5738 (0x8 bytes) */



void MI_Check_Num(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_ItemStr @ 0x1E5720 .. 0x1E5728 (0x8 bytes) */



void MI_Get_ItemStr(void) {
    return;
}


/* MI_Set_ItemStr @ 0x1E5710 .. 0x1E5718 (0x8 bytes) */



void MI_Set_ItemStr(void) {
    return;
}


/* MI_Decide_ItemStr @ 0x1E5700 .. 0x1E5708 (0x8 bytes) */




void MI_Decide_ItemStr(void) {
    return;
}

void MI_CntUp_ItemStr(signed int a0 /* r4 */, s32 a1) {
    u8 *a0_2; // a0
    u32 v1;
    u8 stackFrame_10[16] __attribute__((aligned(16)));

    v1 = s_next_ctrl_or_item;
    if ((s32)v1 <= 0) {
        v1 = v1 + 1;
        s_next_ctrl_or_item = v1;
    }
    switch (a1) {
    case 7:
        a1 = 8;
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_10[0]), a1);
        v1 = book_doc_page;
        a0_2 = (u8 *)*(s32 *)((u8 *)&stackFrame_10[0]);
        v1 = v1 + 1;
        book_doc_page = (u32)v1;
        v1 = book_doc_page;
        v1 = v1 < (u32)(s32)a0_2;
        if (v1 == 0) {
            if ((u32)(s32)a0_2 == 0) {
                book_doc_page = 0;
                break;
            } else {
                v1 = (s32)(a0_2 + -1);
                book_doc_page = v1;
                break;
            }
        } else {
            v1 = no_snd_on;
            if (v1 != 0) {
                break;
            }
            v1 = no_snd_counter;
            if ((s32)v1 > 0) {
                v1 = v1 + -1;
                no_snd_counter = v1;
                break;
            } else {
                a0_2 = (u8 *)(s32)0x14;
                a1 = 0x64;
                SND_Play2D((signed int)a0_2, a1, 0);
            }
        }
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        break;
    }
    return;
}

void MI_CntDown_ItemStr(signed int a0 /* r4 */, s32 a1) {
    u32 a0_index; // a0
    u32 v1;
    u8 stackFrame_10[16] __attribute__((aligned(16)));

    switch (a1) {
    case 7:
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_10[0]), 8);
        v1 = book_doc_page;
        a0_index = v1 + (u32)-1;
        if ((s32)v1 <= 0) {
            break;
        }
        v1 = no_snd_on;
        book_doc_page = a0_index;
        if (v1 != 0) {
            break;
        }
        if ((s32)no_snd_counter > 0) {
            no_snd_counter += -1;
            break;
        } else {
            SND_Play2D(0x16, 0x64, 0);
        }
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        break;
    }
    return;
}










/* MI_Gene1_ItemStr @ 0x1E5580 .. 0x1E5588 (0x8 bytes) */



void MI_Gene1_ItemStr(void) {
    return;
}


/* MI_Gene2_ItemStr @ 0x1E5570 .. 0x1E5578 (0x8 bytes) */




void MI_Gene2_ItemStr(void) {
    return;
}

static inline void MI_Evrfrm_ItemStr__cpy(void *dst, u16 *src) {
    memcpy(dst, src, MI_Evrfrm_ItemStr__lenu16(src) * 2 + 2);
}

static inline void MI_Evrfrm_ItemStr__inl0(void) {
    s32 n = 0;
    u16 *e;
    if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
        e = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
        do {
            e++;
            n++;
        } while (*e != 0);
    }
    memcpy(aTmpItemName, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", n * 2 + 2);
}

static inline void MI_Evrfrm_ItemStr__inl1(void) {
    s32 n = 0;
    u16 *e;
    if (*(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000" != 0) {
        e = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
        do {
            e++;
            n++;
        } while (*e != 0);
    }
    memcpy(aTmpItemNote, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", n * 2 + 2);
}

void MI_Evrfrm_ItemStr(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s4;
    s32 s5;
    u32 a2;
    s32 s3;
    s32 s2;
    u32 s1;
    u32 s0;
    u32 v1;
    u32 v0;
    u_long128 v1_q;
    void *a0_2;
    signed int a1_2;
    u8 stackFrame_47C[4] __attribute__((aligned(4)));
    u8 stackFrame_478[4] __attribute__((aligned(4)));
    u8 stackFrame_474[4] __attribute__((aligned(4)));
    GetItemDataRet stackFrame_460[1] __attribute__((aligned(16)));
    u8 stackFrame_70[1008] __attribute__((aligned(16)));

    s5 = a1;
    s4 = (u8 *)a0;
    switch (s5) {
    case 1:
        s3 = 0x1a;
        s2 = 0x1f;
        s1 = 0x18;
        a1_2 = 1;
        s0 = 2;
        break;
    case 2:
        s3 = 0x1a;
        s2 = 0x1f;
        s1 = 0x18;
        a1_2 = 1;
        s0 = 3;
        break;
    case 3:
        a1_2 = 2;
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x2d;
        s0 = a1_2;
        break;
    case 4:
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x2d;
        a1_2 = 2;
        s0 = 3;
        break;
    case 5:
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x41;
        a1_2 = 3;
        s0 = 2;
        break;
    case 6:
        a1_2 = 3;
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x41;
        s0 = a1_2;
        break;
    case 7:
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x41;
        a1_2 = 3;
        s0 = 6;
        break;
    case 8:
        s3 = 0x1a;
        s2 = 0x21;
        s1 = 0x41;
        a1_2 = 3;
        s0 = 7;
        break;
    case 9:
        a0_2 = (void *)*(u16 *)((u8 *)&s_get_item_id);
        v0 = (u32)ItemMng_GetItemName_Direct((unsigned short)a0_2);
        if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemName, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl0();
 }
        v1 = (u32)aTmpItemName;
        *(void **)s4 = (void *)aTmpItemName;
        goto _L001E5548;
    case 10:
        a0_2 = (void *)*(u16 *)((u8 *)&s_get_item_id);
        v0 = (u32)ItemMng_GetItemNote_Direct((unsigned short)a0_2);
        if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemNote, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl1();
 }
        v1 = (u32)aTmpItemNote;
        *(void **)s4 = (void *)aTmpItemNote;
        goto _L001E5548;
    case 0:
    default:
        *(u32 *)s4 = 0;
        goto _L001E5548;
    }
    a0_2 = (void *)(s32)3;
    v0 = KnMenuMng_GetCursorId((int)a0_2, a1_2);
    v1 = (s32)v0 < s3;
    if (v1 == 0 && (s32)v0 <= s2) {
        v0 = v0 - s3;
        v0 = s1 + (u32)v0;
        a1_2 = (u8)v0;
        stackFrame_460[0] = GetItemData(a1_2, s0);
        v1 = (u32)((u8 *)&stackFrame_460[0]);
        v1_q = *(u_long128 *)v1;
        *(u_long128 *)s4 = v1_q;
    } else {
        a0_2 = (void *)(s32)3;
        a1_2 = 1;
        v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
        if (v0 != 0) {
            a0_2 = (void *)(s32)3;
            a1_2 = 1;
            s1 = (u32)(u8 *)(MdlMng + 0x4600);
            v0 = KnMenuMng_GetCursorId((int)a0_2, a1_2);
            v1 = 0xc;
            if (v0 == v1) {
                a0_2 = (void *)s1;
                GetMyEquipInfo(a0_2, 0, (signed int *)((u8 *)&stackFrame_47C[0]), (signed int
                    *)((u8 *)&stackFrame_478[0]), (signed int *)((u8 *)&stackFrame_474[0]));
                a0_2 = (void *)*(s32 *)((u8 *)&stackFrame_47C[0]);
                v1 = 1;
                a1_2 = (u8)s0;
                if ((u32)(s32)a0_2 == v1) {
                    v1 = 2;
                    if ((u32)a1_2 == v1) {
                        a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                        a0_2 = (void *)(s32)3;
                        v0 = (u32)ItemMng_GetItemName((unsigned short)a0_2, a1_2);
                        if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemName, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl0();
 }
                        v1 = (u32)aTmpItemName;
                        *(void **)s4 = (void *)aTmpItemName;
                    } else {
                        a0_2 = (void *)(s32)3;
                        if ((u32)a1_2 == (u32)(s32)a0_2) {
                            a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                            v0 = (u32)ItemMng_GetItemNote((unsigned short)a0_2, a1_2);
                            if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemNote, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl1();
 }
                            v1 = (u32)aTmpItemNote;
                            *(void **)s4 = (void *)aTmpItemNote;
                        } else {
                            *(u32 *)s4 = 0;
                        }
                    }
                } else {
                    *(u32 *)s4 = 0;
                }
            } else {
                v1 = 0xd;
                if (v0 == v1) {
                    a0_2 = (void *)s1;
                    a1_2 = 1;
                    GetMyEquipInfo(a0_2, a1_2, (signed int *)((u8 *)&stackFrame_47C[0]), (signed
                        int *)((u8 *)&stackFrame_478[0]), (signed int *)((u8 *)&stackFrame_474[0]));
                    a0_2 = (void *)*(s32 *)((u8 *)&stackFrame_47C[0]);
                    v1 = 1;
                    a1_2 = (u8)s0;
                    if ((u32)(s32)a0_2 == v1) {
                        v1 = 2;
                        if ((u32)a1_2 == v1) {
                            a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                            a0_2 = (void *)(s32)3;
                            v0 = (u32)ItemMng_GetItemName((unsigned short)a0_2, a1_2);
                            if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemName, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl0();
 }
                            v1 = (u32)aTmpItemName;
                            *(void **)s4 = (void *)aTmpItemName;
                        } else {
                            a0_2 = (void *)(s32)3;
                            if ((u32)a1_2 == (u32)(s32)a0_2) {
                                a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                                v0 = (u32)ItemMng_GetItemNote((unsigned short)a0_2, a1_2);
                                if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemNote, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl1();
 }
                                v1 = (u32)aTmpItemNote;
                                *(void **)s4 = (void *)aTmpItemNote;
                            } else {
                                *(u32 *)s4 = 0;
                            }
                        }
                    } else {
                        *(u32 *)s4 = 0;
                    }
                } else {
                    v1 = 0x15;
                    a0_2 = (void *)s1;
                    if (v0 == v1) {
                        *(s32 *)((u8 *)&stackFrame_47C[0]) = 0;
                        a2 = (u8)GetMyWeaponId(a0_2) + 1;
                        a1_2 = GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PLAYERID_DD4498F5 / 1)] * 3;
                        *(s32 *)((u8 *)&stackFrame_478[0]) = a1_2 + a2;
                        if (*(s32 *)((u8 *)&stackFrame_47C[0]) == 0) {
                            a0_2 = (void *)(u8)s0;
                            v1 = 2;
                            if ((u32)a0_2 == v1) {
                                a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                                a0_2 = (void *)(s32)4;
                                v0 = (u32)ItemMng_GetItemName((unsigned short)a0_2, a1_2);
                                if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemName, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl0();
 }
                                v1 = (u32)aTmpItemName;
                                *(void **)s4 = (void *)aTmpItemName;
                            } else {
                                v1 = 3;
                                if ((u32)a0_2 == v1) {
                                    a1_2 = *(u16 *)((u8 *)&stackFrame_478[0]);
                                    a0_2 = (void *)(s32)4;
                                    v0 = (u32)ItemMng_GetItemNote((unsigned short)a0_2, a1_2);
                                    if (v0 != 0) {
 MI_Evrfrm_ItemStr__cpy(aTmpItemNote, (u16 *)v0);
 } else {
 MI_Evrfrm_ItemStr__inl1();
 }
                                    v1 = (u32)aTmpItemNote;
                                    *(void **)s4 = (void *)aTmpItemNote;
                                } else {
                                    *(u32 *)s4 = 0;
                                }
                            }
                        } else {
                            *(u32 *)s4 = 0;
                        }
                    } else {
                        *(u32 *)s4 = 0;
                    }
                }
            }
        } else {
            *(u32 *)s4 = 0;
        }
    }
    v1 = 8;
    if ((u32)s5 == v1) {
        v1 = *(s32 *)s4;
        a0_2 = (void *)book_doc_page;
        v1 = v1 + -1;
        v1 = (u32)(s32)a0_2 < v1;
        if (v1 == 0) {
            a1_2 = s_next_ctrl_or_item;
            v1 = (s32)a1_2 < (s32)-0xa;
            if (v1 == 0 && (s32)a1_2 < 0) {
                v1 = (u32)(a1_2) + 1;
                s_next_ctrl_or_item = v1;
            } else {
                a0_2 = (void *)(s32)1;
                if ((u32)(s32)a1_2 == (u32)(s32)a0_2) {
                    v0 = 0x10000;
                    a0_2 = (void *)(s32)3;
                    s0 = 0x10000 | 0x86e7;
                    a1_2 = 7;
                    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                    if (v0 != 0) {
                        v0 = 0x10000;
                        s0 = 0x10000 | 0x86e7;
                    }
                    a0_2 = (void *)(s32)7;
                    a1_2 = 1;
                    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                    if (v0 != 0) {
                        v0 = 0x10000;
                        s0 = 0x10000 | 0x86ec;
                    }
                    a0_2 = (void *)s0;
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    v1 = 3;
                    s0 = v0;
                    s_now_dialog_id = v1;
                    if (s0 == 0) {
                        s_DialogUseCounter = 0;
                    } else {
                        v1 = s_DialogUseCounter;
                        if (v1 == 0) {
                            v0 = no_snd_on;
                            if (v0 == 0) {
                                v0 = no_snd_counter;
                                if ((s32)v0 > 0) {
                                    v0 = v0 + -1;
                                    no_snd_counter = v0;
                                } else {
                                    SND_Play2D(0x11, 0x64, 0);
                                }
                            }
                            v0 = *(u16 *)s0;
                            a0_2 = (void *)0;
                            if (v0 != 0) {
                                v1 = s0;
                                do {
                                    v1 = v1 + 2;
                                    v0 = *(u16 *)v1;
                                    a0_2 = (void *)((u8 *)a0_2 + 1);
                                } while (v0 != 0);
                            }
                            v0 = (u32)a0_2 << 1;
                            a1_2 = s0;
                            memcpy((void *)((u8 *)&stackFrame_70[0]), (void *)a1_2, v0 + 2);
                            a0_2 = (void *)s_aDialogMsg;
                            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                                *)&stackFrame_70[0]), 0);
                            v1 = 0xa;
                            s_aDialogResult[3] = 0;
                            s_DialogUseCounter = v1;
                            s_no_pad_check = 0;
                        }
                    }
                    v1 = 2;
                    s_next_ctrl_or_item = v1;
                } else {
                    v1 = 2;
                    if ((u32)a1_2 == v1) {
                        a1_2 = s_aDialogResult[3];
                        if ((u32)a1_2 != 0) {
                            v1 = 3;
                            if ((u32)a1_2 == (u32)a0_2) {
                                s_next_ctrl_or_item = v1;
                            }
                            v1 = 2;
                            if ((u32)a1_2 == v1) {
                                book_doc_page = 0;
                                s_next_ctrl_or_item = -0xa;
                            }
                        }
                    } else {
                        a0_2 = (void *)(s32)3;
                        if ((u32)a1_2 == (u32)(s32)a0_2) {
                            a1_2 = 7;
                            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                            a0_2 = (void *)(s32)3;
                            if (v0 != 0) {
                                KnMenuMng_SetForceChangeCursorId((int)a0_2, 7, 0xa);
                            }
                            a0_2 = (void *)(s32)7;
                            a1_2 = 1;
                            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                            a0_2 = (void *)(s32)7;
                            if (v0 != 0) {
                                KnMenuMng_SetForceChangeCursorId((int)a0_2, 1, 0xa);
                            }
                            s_next_ctrl_or_item = -0xa;
                        }
                    }
                }
            }
        } else {
            s_next_ctrl_or_item = -0xa;
        }
    }
    _L001E5548:;
    return;
}


/* MI_Init_ItemStr @ 0x1E4A20 .. 0x1E4A28 (0x8 bytes) */



void MI_Init_ItemStr(void) {
    return;
}


/* MI_Check_ItemStr @ 0x1E4970 .. 0x1E4A18 (0xa8 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1e499c if (..) goto .L001E4A08
 *   declaration vs inferred signature: return void vs inferred u32
 */




void MI_Check_ItemStr(void *a0 /* r4 */) {
    u8 *s0;
    u32 a1;
    u32 v1;
    u32 v0;

    a1 = 7;
    *(u32 *)a0 = 0;
    s0 = (u8 *)a0;
    a0 = (void *)(s32)3;
    v0 = KnMenuMng_CheckCtrlPlay((s32)a0, a1);
    a0 = (void *)(s32)7;
    if (v0 == 0) {
        a1 = 1;
        v0 = KnMenuMng_CheckCtrlPlay((s32)a0, a1);
        if (v0 == 0) {
            goto _L001E4A08;
        }
    }
    v1 = book_doc_page;
    if (v1 == 0) {
        ((struct { unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(s0 + 1))->f = ((struct {
            unsigned char _pad:5; unsigned char f:1; } *)&*(u8 *)(s0 + 1))->f | 1;
        ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(s0 + 1))->f = ((struct {
            unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(s0 + 1))->f | 1;
    }
    _L001E4A08:;
    return;
}


/* Menu_SetEndSave @ 0x1E4960 .. 0x1E4968 (0x8 bytes) */



void Menu_SetEndSave(signed int a0 /* r4 */) {
    s_end_save = a0;
    return;
}


/* Menu_SetLoadSlotOffsetReset @ 0x1E4950 .. 0x1E4960 (0x10 bytes) */



void Menu_SetLoadSlotOffsetReset(void) {
    s_load_slot = 0;
    s_load_offset = 0;
    memoca_index_offset = 0;
    return;
}


/* Menu_IsLoaded @ 0x1E4940 .. 0x1E4948 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1e4944 computes the return value
 */




u32 Menu_IsLoaded(void) {
    return menu_load_ok;
}







/* Menu_SetUnLoaded @ 0x1E4930 .. 0x1E4938 (0x8 bytes) */



void Menu_SetUnLoaded(void) {
    menu_load_ok = 0;
    return;
}


/* Menu_IsSaved @ 0x1E4920 .. 0x1E4928 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1e4924 computes the return value
 */




u32 Menu_IsSaved(void) {
    return menu_save_ok;
}


/* Menu_SetUnSaved @ 0x1E4910 .. 0x1E4918 (0x8 bytes) */



void Menu_SetUnSaved(void) {
    menu_save_ok = 0;
    return;
}


/* Menu_ClearMemocaMng @ 0x1E48C0 .. 0x1E4904 (0x44 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u8 * Menu_ClearMemocaMng(void) {
    memset(MemocaMng, 0, 9);
    *(u8 *)((u8 *)&MemocaMng + 5) = 0;
    *(u8 *)MemocaMng = 2;
    *(u8 *)((u8 *)&MemocaMng + 1) = 2;
    return;
}
signed int Menu_CheckSetMemocaState(void) {
    s32 message=GetMemoryCardMessage(MemocaMng[4]);
    if (message==2 || message==4 || message==22 || message==23) {
        s_load_slot=0;
        s_load_offset=0;
        memoca_index_offset=0;
    }
    switch(message) {
    case 0: s_memoca_state_msg_id=-2; break;
    case 1: s_memoca_state_msg_id=MemocaMng[4]==0 ? (enum MCSEnum)0 : (enum MCSEnum)1; break;
    case 2: s_memoca_state_msg_id=MemocaMng[4]+28; break;
    case 3: s_memoca_state_msg_id=4; break;
    case 4: s_memoca_state_msg_id=MemocaMng[4]+28; break;
    case 20: s_memoca_state_msg_id=-2; break;
    case 21: s_memoca_state_msg_id=4; break;
    case 22: s_memoca_state_msg_id=MemocaMng[4]+28; break;
    case 23: s_memoca_state_msg_id=14; break;
    case 30: s_memoca_state_msg_id=14; break;
    case 31: s_memoca_state_msg_id=14; break;
    case 40: s_memoca_state_msg_id=14; break;
    case 45: s_memoca_state_msg_id=14; break;
    case 46: s_memoca_state_msg_id=-2; break;
    case 50: s_memoca_state_msg_id=7; break;
    case 51: s_memoca_state_msg_id=5; break;
    case 52: s_memoca_state_msg_id=6; break;
    case 60: s_memoca_state_msg_id=10; break;
    case 61: s_memoca_state_msg_id=13; break;
    case 62: s_memoca_state_msg_id=12; break;
    case 70: s_memoca_state_msg_id=16; break;
    case 71: s_memoca_state_msg_id=18; break;
    case 72: s_memoca_state_msg_id=17; break;
    case 99: s_memoca_state_msg_id=-2; break;
    case 100: s_memoca_state_msg_id=-2; break;
    default: s_memoca_state_msg_id=-2; break;
    }
    return s_memoca_state_msg_id;
}


/* Menu_CallMemocaStateDialog @ 0x1E4360 .. 0x1E45A4 (0x244 bytes, frame 0x410) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e4384 writes a register its branch at 0x1e4380 reads
 *   delay: addiu at 0x1e4398 writes a register its branch at 0x1e4394 reads
 *   delay: addiu at 0x1e43c0 writes a register its branch at 0x1e43bc reads
 *   delay: addiu at 0x1e43d4 writes a register its branch at 0x1e43d0 reads
 *   delay: addiu at 0x1e43e8 writes a register its branch at 0x1e43e4 reads
 *   delay: addiu at 0x1e43fc writes a register its branch at 0x1e43f8 reads
 *   delay: addiu at 0x1e4410 writes a register its branch at 0x1e440c reads
 *   delay: addiu at 0x1e4424 writes a register its branch at 0x1e4420 reads
 *   delay: addiu at 0x1e4438 writes a register its branch at 0x1e4434 reads
 *   delay: addiu at 0x1e444c writes a register its branch at 0x1e4448 reads
 *   delay: addiu at 0x1e4460 writes a register its branch at 0x1e445c reads
 *   delay: addiu at 0x1e4474 writes a register its branch at 0x1e4470 reads
 *   delay: addiu at 0x1e4488 writes a register its branch at 0x1e4484 reads
 *   delay: addiu at 0x1e449c writes a register its branch at 0x1e4498 reads
 *   stack: address of the slot at 0x20 escapes at 0x1e4564
 *   stack: address of the slot at 0x20 escapes at 0x1e4578
 *   cfg: kept branch: 0x1e4398 if (..) goto .L001E43B8
 */


signed int Menu_CallMemocaStateDialog(void) {
    u32 a1;
    u32 s0;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_20[1008] __attribute__((aligned(16)));

    a0 = MemocaMng[4];
    s0 = 0;
    v0 = GetMemoryCardMessage(a0);
    v1 = 2;
    if (v0 != v1) {
        v1 = 4;
        if (v0 != v1) {
            v1 = 0x16;
            if (v0 != v1) {
                v1 = 0x17;
                if (v0 != v1) {
                    goto _L001E43B8;
                }
            }
        }
    }
    s_load_slot = 0;
    s_load_offset = 0;
    memoca_index_offset = 0;
    _L001E43B8:;
    v1 = 0x64;
    switch (v0) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 20:
    case 21:
    case 22:
    case 23:
        break;
    case 30:
        s0 = GetNeedCluster(ExistKuonData());
        break;
    case 31:
        s0 = GetNeedCluster(ExistKuonData());
        break;
    case 40:
    case 45:
    case 46:
    case 50:
    case 51:
    case 52:
    case 60:
    case 61:
    case 62:
    case 70:
    case 71:
    case 72:
    case 99:
    case 100:
        break;
    }
    v0 = Menu_CheckSetMemocaState();
    v1 = 0x18894;
    v0 = (u32)KnMsgMng_GetMsgStr(v0 + 0x18894);
    v1 = 2;
    s_now_dialog_id = v1;
    if (v0 == 0) {
        s_DialogUseCounter = 0;
    } else {
        v1 = s_DialogUseCounter;
        if (v1 == 0) {
            v1 = *(u16 *)v0;
            a1 = 0;
            if (v1 != 0) {
                a0 = v0;
                do {
                    a0 = a0 + 2;
                    v1 = *(u16 *)a0;
                    a1 = a1 + 1;
                } while (v1 != 0);
            }
            v1 = a1 << 1;
            memcpy((void *)((u8 *)&stackFrame_20[0]), (void *)v0, v1 + 2);
            a0 = (u32)s_aDialogMsg;
            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_20[0]), s0);
            v0 = 0xa;
            *(u8 *)((u8 *)&s_aDialogResult + 2) = 0;
            s_DialogUseCounter = v0;
            s_no_pad_check = 0;
        }
    }
    v0 = s_memoca_state_msg_id;
    return v0;
}
static inline void MI_Get_Memoca__inl0(void) {
    u32 v1;
    u32 v0;
    void *a0_2;

    v0 = MemoryCardStart(0, 0, 0);
    if (v0 == 0) {
        MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)] = 0;
        v0 = 1;
        MemocaMng[2 + MemocaMng[4]] = 0;
        MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = v0;
        MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] = v0;
    }
}

static inline u32 MI_Get_Memoca__inl1(void) {
    u32 v1;
    u32 v0;
    u32 s4;
    u32 s3;
    void *a0_2;
    signed int a1_2;

    v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
    s3 = (v0 == 0);
    s4 = MemoryCardProc();
    if (s4 != 0 || MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] == 0) {
        v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)];
        if (v0 != 0 && s4) {
            a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                1)];
            v0 = GetMemoryCardMessage((unsigned char)a0_2);
            v1 = 2;
            if (v0 != v1) {
                v1 = 4;
                if (v0 == v1) {
                    goto _L001E2EA8;
                }
                v1 = 0x16;
                if (v0 == v1) {
                    goto _L001E2EA8;
                }
                v1 = 0x17;
                if (v0 != v1) {
                    goto _L001E2EB8;
                }
            }
            _L001E2EA8:;
            s_load_slot = 0;
            s_load_offset = 0;
            memoca_index_offset = 0;
            _L001E2EB8:;
            a0_2 = (void *)(s32)1;
            if (v0 != (u32)(s32)a0_2) {
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = (s32)a0_2;
            } else {
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = 2;
            }
        }
        a1_2 = (u8)s3;
        v0 = MemoryCardStart(0, a1_2, 0);
        if (v0 == 0) {
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)] = s3;
            v0 = 1;
            MemocaMng[2 + MemocaMng[4]] = 0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = v0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] = v0;
        }
    }
    return s4;
}

static inline u32 MI_Get_Memoca__inl2(u32 v0) {
    u32 v1;
    u32 s4;
    u32 s3;
    void *a0_2;
    signed int a1_2;

    v0 = v0 + -1;
    s4 = (u8)v0;
    s3 = MemoryCardProc();
    if (s3 != 0 || MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] == 0) {
        v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)];
        if (v0 != 0 && s3) {
            a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                1)];
            v0 = GetMemoryCardMessage((unsigned char)a0_2);
            v1 = 2;
            if (v0 != v1) {
                v1 = 4;
                if (v0 == v1) {
                    goto _L001E33E8;
                }
                v1 = 0x16;
                if (v0 == v1) {
                    goto _L001E33E8;
                }
                v1 = 0x17;
                if (v0 != v1) {
                    goto _L001E33F8;
                }
            }
            _L001E33E8:;
            s_load_slot = 0;
            s_load_offset = 0;
            memoca_index_offset = 0;
            _L001E33F8:;
            a0_2 = (void *)(s32)1;
            if (v0 != (u32)(s32)a0_2) {
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = (s32)a0_2;
            } else {
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = 2;
            }
        }
        a1_2 = (u8)s4;
        a0_2 = (void *)(s32)1;
        v0 = MemoryCardStart((unsigned char)a0_2, a1_2, 0);
        if (v0 == 0) {
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)] = s4;
            a0_2 = (void *)(s32)1;
            MemocaMng[2 + MemocaMng[4]] = (s32)a0_2;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = (s32)a0_2;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] =
                (s32)a0_2;
        }
    }
    return s3;
}

void MI_Get_Memoca(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 *s2;
    u32 s1;
    u32 v1;
    u32 v0;
    u32 s0;
    u32 s4;
    u32 s3;
    u32 length;
    u16 *scan;
    void *a0_2;
    signed int a1_2;
    u8 stackFrame_27C0[1008] __attribute__((aligned(16)));
    u8 stackFrame_23D0[1008] __attribute__((aligned(16)));
    u8 stackFrame_1FE0[1008] __attribute__((aligned(16)));
    u8 stackFrame_1BF0[1008] __attribute__((aligned(16)));
    u8 stackFrame_1800[1008] __attribute__((aligned(16)));
    u8 stackFrame_1410[1008] __attribute__((aligned(16)));
    u8 stackFrame_1020[1008] __attribute__((aligned(16)));
    u8 stackFrame_C30[1008] __attribute__((aligned(16)));
    u8 stackFrame_840[1008] __attribute__((aligned(16)));
    u8 stackFrame_450[1008] __attribute__((aligned(16)));
    u8 stackFrame_60[1008] __attribute__((aligned(16)));

    s2 = (u32 *)a0;
    s1 = a1;
    a0_2 = (void *)(s32)0xa;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)0xa;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 0);
    }
    a0_2 = (void *)(s32)4;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)4;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 0);
    }
    a0_2 = (void *)(s32)5;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)5;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 0);
    }
    v0 = 1;
    if ((u32)s1 == v0) {
        v0 = s_memoca_real_time_check_state;
        switch (v0) {
        case 3:
            a0_2 = (void *)MemocaMng;
            memset((void *)MemocaMng, 0, 9);
            v0 = 2;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] = 0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E / 1)] = v0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 / 1)] = v0;
            s_memoca_real_time_check_state = 0;
            break;
        case 0:
            MI_Get_Memoca__inl0();
            v0 = 1;
            s_memoca_real_time_check_state = v0;
            v0 = 0x10000;
            a0_2 = (void *)(0x10000 | 0xd4e6);
            v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
            v1 = 2;
            s_now_dialog_id = v1;
            if (v0 == 0) {
                s_DialogUseCounter = 0;
                break;
            } else {
                v1 = s_DialogUseCounter;
                if (v1 != 0) {
                    break;
                }
                v1 = *(u16 *)v0;
                length = 0;
                if (v1 != 0) {
                    scan = (u16 *)v0;
                    do {
                        scan++;
                        v1 = *scan;
                        length++;
                    } while (v1 != 0);
                }
                v1 = length << 1;
                a1_2 = v0;
                memcpy((void *)((u8 *)&stackFrame_27C0[0]), (void *)a1_2, v1 + 2);
                a0_2 = (void *)s_aDialogMsg;
                FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_27C0[0]), 0);
                v0 = 0xa;
                s_aDialogResult[2] = 0;
                s_DialogUseCounter = v0;
                v0 = 1;
                s_no_pad_check = v0;
                break;
            }
        case 1:
            s4 = MI_Get_Memoca__inl1();
            v0 = 2;
            if (s4 == 0) {
                break;
            }
            s_memoca_real_time_check_state = v0;
            break;
        case 2:
            v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
            s4 = (v0 == 0);
            s3 = MemoryCardProc();
            if (s3 != 0 || MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] == 0) {
                v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)];
                if (v0 != 0 && s3) {
                    a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E2EA8c2;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E2EA8c2;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E2EB8c2;
                        }
                    }
                    _L001E2EA8c2:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E2EB8c2:;
                    a0_2 = (void *)(s32)1;
                    if (v0 != (u32)(s32)a0_2) {
                        v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                        v0 = (u32)MemocaMng;
                        *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                            1) = (s32)a0_2;
                    } else {
                        v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                        v0 = (u32)MemocaMng;
                        *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                            1) = 2;
                    }
                }
                a1_2 = (u8)s4;
                v0 = MemoryCardStart(0, a1_2, 0);
                if (v0 == 0) {
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)] = s4;
                    v0 = 1;
                    MemocaMng[2 + MemocaMng[4]] = 0;
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = v0;
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] = v0;
                }
            }
            v0 = 5;
            if (s3 == 0) {
                break;
            }
            s_memoca_real_time_check_state = v0;
            s_DialogUseCounter = 0;
            v0 = 2;
            s_now_dialog_id = v0;
            break;
        case 4:
            v0 = s_DialogUseCounter;
            if ((s32)v0 > 0) {
                break;
            }
            a0_2 = (void *)s_check_next_msg_id;
            if ((u32)(s32)a0_2 == 0) {
                goto _L001E3148;
            }
            v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
            v1 = 2;
            s_now_dialog_id = v1;
            if (v0 == 0) {
                s_DialogUseCounter = 0;
            } else {
                v1 = s_DialogUseCounter;
                if (v1 == 0) {
                    v1 = *(u16 *)v0;
                    length = 0;
                    if (v1 != 0) {
                        scan = (u16 *)v0;
                        do {
                            scan++;
                            v1 = *scan;
                            length++;
                        } while (v1 != 0);
                    }
                    v1 = length << 1;
                    a1_2 = v0;
                    memcpy((void *)((u8 *)&stackFrame_23D0[0]), (void *)a1_2, v1 + 2);
                    a0_2 = (void *)s_aDialogMsg;
                    FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_23D0[0]), 0);
                    v0 = 0xa;
                    s_aDialogResult[2] = 0;
                    s_DialogUseCounter = v0;
                    s_no_pad_check = 0;
                }
            }
            s_check_next_msg_id = 0;
            goto _L001E3150;
            _L001E3148:;
            v0 = 5;
            s_memoca_real_time_check_state = v0;
        case 5:
            _L001E3150:;
            v0 = s_DialogUseCounter;
            a0_2 = (void *)0;
            if ((s32)v0 > 0) {
                break;
            }
            MI_Get_Memoca__inl0();
            v0 = 6;
            s_memoca_real_time_check_state = v0;
        case 6:
            v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
            s3 = (v0 == 0);
            v0 = MemoryCardProc();
            if (v0 == 0 && MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)]
                != 0) {
                break;
            }
            v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)];
            if (v1 != 0 && v0) {
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E3218;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E3218;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E3228;
                    }
                }
                _L001E3218:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E3228:;
                a0_2 = (void *)(s32)1;
                if (v0 != (u32)(s32)a0_2) {
                    v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                    v0 = (u32)MemocaMng;
                    *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 +
                        (v1) * 1) = (s32)a0_2;
                } else {
                    v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                    v0 = (u32)MemocaMng;
                    *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 +
                        (v1) * 1) = 2;
                }
            }
            a1_2 = (u8)s3;
            v0 = MemoryCardStart(0, a1_2, 0);
            if (v0 != 0) {
                break;
            }
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)] = s3;
            v0 = 1;
            MemocaMng[2 + MemocaMng[4]] = 0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = v0;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_OK_7FEC4AA8 / 1)] = v0;
            break;
        case 7:
            v0 = use_memoca_slot;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)] = 0;
            if (v0 == 0) {
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x88a7);
                v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                v1 = 2;
                s_now_dialog_id = v1;
                if (v0 == 0) {
                    s_DialogUseCounter = 0;
                } else {
                    v1 = s_DialogUseCounter;
                    if (v1 == 0) {
                        v1 = *(u16 *)v0;
                        length = 0;
                        if (v1 != 0) {
                            scan = (u16 *)v0;
                            do {
                                scan++;
                                v1 = *scan;
                                length++;
                            } while (v1 != 0);
                        }
                        v1 = length << 1;
                        a1_2 = v0;
                        memcpy((void *)((u8 *)&stackFrame_1FE0[0]), (void *)a1_2, v1 + 2);
                        a0_2 = (void *)s_aDialogMsg;
                        FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                            *)&stackFrame_1FE0[0]), 0);
                        v0 = 0xa;
                        s_aDialogResult[2] = 0;
                        s_DialogUseCounter = v0;
                        s_no_pad_check = 0;
                    }
                }
                v0 = 5;
                s_memoca_real_time_check_state = v0;
                break;
            } else {
                s3 = MI_Get_Memoca__inl2(v0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0xd4e6);
                v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                v1 = 2;
                s_now_dialog_id = v1;
                if (v0 == 0) {
                    s_DialogUseCounter = 0;
                } else {
                    v1 = s_DialogUseCounter;
                    if (v1 == 0) {
                        v1 = *(u16 *)v0;
                        length = 0;
                        if (v1 != 0) {
                            scan = (u16 *)v0;
                            do {
                                scan++;
                                v1 = *scan;
                                length++;
                            } while (v1 != 0);
                        }
                        v1 = length << 1;
                        a1_2 = v0;
                        memcpy((void *)((u8 *)&stackFrame_1BF0[0]), (void *)a1_2, v1 + 2);
                        a0_2 = (void *)s_aDialogMsg;
                        FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                            *)&stackFrame_1BF0[0]), 0);
                        v0 = 0xa;
                        s_aDialogResult[2] = 0;
                        s_DialogUseCounter = v0;
                        v0 = 1;
                        s_no_pad_check = v0;
                    }
                }
                if (s3 == 0) {
                    break;
                }
                v1 = 8;
                s_memoca_real_time_check_state = v1;
                v0 = s_end_save;
                if (v0 == 0) {
                    break;
                }
                v0 = 5;
                s_memoca_decide_state = v0;
                break;
            }
        case 8:
            s3 = MemoryCardProc();
            if (s3 == 0) {
                break;
            }
            a0_2 = (void *)(s32)0xa;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = 0;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 == 0) {
                s_DialogUseCounter = 0;
                s_now_dialog_id = 2;
            }
            a0_2 = (void *)(s32)5;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                if ((s32)s3 <= 0) {
                    goto _L001E3600;
                }
                v0 = ExistKuonData();
                if (v0 == 0) {
                    goto _L001E3600;
                }
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                GetMemoryCardMessage((unsigned char)a0_2);
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                a1_2 = 1;
                v0 = (s32)((u8 *)MemocaMng + v1);
                MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)] = a1_2;
                *(u8 *)v0 = a1_2;
                v0 = s_end_save;
                a0_2 = (void *)(s32)0xa;
                if (v0 == 0) {
                    goto _L001E3B58;
                }
                v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                v0 = v0 != 0;
                menu_save_ok = v0;
                goto _L001E3B58;
                _L001E3600:;
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                s3 = GetMemoryCardMessage((unsigned char)a0_2);
                MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)] = 0;
                MemocaMng[MemocaMng[4]] = 1;
                a0_2 = (void *)(s32)1;
                if (s3 != (u32)(s32)a0_2) {
                    v0 = ExistKuonData();
                    v1 = 4;
                    if (v0 != 0) {
                        goto _L001E36F0;
                    }
                    v0 = 0x10000;
                    s_check_next_state = v1;
                    a0_2 = (void *)(0x10000 | 0x88a7);
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    v1 = 2;
                    s_now_dialog_id = v1;
                    if (v0 == 0) {
                        s_DialogUseCounter = 0;
                    } else {
                        v1 = s_DialogUseCounter;
                        if (v1 == 0) {
                            v1 = *(u16 *)v0;
                            length = 0;
                            if (v1 != 0) {
                                scan = (u16 *)v0;
                                do {
                                    scan++;
                                    v1 = *scan;
                                    length++;
                                } while (v1 != 0);
                            }
                            v1 = length << 1;
                            a1_2 = v0;
                            memcpy((void *)((u8 *)&stackFrame_1800[0]), (void *)a1_2, v1 + 2);
                            a0_2 = (void *)s_aDialogMsg;
                            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                                *)&stackFrame_1800[0]), 0);
                            v0 = 0xa;
                            s_aDialogResult[2] = 0;
                            s_DialogUseCounter = v0;
                            s_no_pad_check = 0;
                        }
                    }
                    s_check_next_msg_id = 0;
                } else {
                    _L001E36F0:;
                    v0 = 1;
                    if (s3 == v0) {
                        v0 = 4;
                        s_check_next_state = v0;
                        v0 = Menu_CheckSetMemocaState();
                        v1 = 0x18894;
                        v0 = v0 + 0x18894;
                        s_check_next_msg_id = v0;
                    }
                    v0 = 0x10000;
                    a0_2 = (void *)(0x10000 | 0x8892);
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    v1 = 2;
                    s_now_dialog_id = v1;
                    if (v0 == 0) {
                        s_DialogUseCounter = 0;
                    } else {
                        v1 = s_DialogUseCounter;
                        if (v1 == 0) {
                            v1 = *(u16 *)v0;
                            length = 0;
                            if (v1 != 0) {
                                scan = (u16 *)v0;
                                do {
                                    scan++;
                                    v1 = *scan;
                                    length++;
                                } while (v1 != 0);
                            }
                            v1 = length << 1;
                            a1_2 = v0;
                            memcpy((void *)((u8 *)&stackFrame_1410[0]), (void *)a1_2, v1 + 2);
                            a0_2 = (void *)s_aDialogMsg;
                            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                                *)&stackFrame_1410[0]), 0);
                            v0 = 0xa;
                            s_aDialogResult[2] = 0;
                            s_DialogUseCounter = v0;
                            s_no_pad_check = 0;
                        }
                    }
                }
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E37E8;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E37E8;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E37F8;
                    }
                }
                _L001E37E8:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E37F8:;
                v1 = 1;
                if (v0 != v1) {
                    goto _L001E3B58;
                }
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = (u32)MemocaMng;
                a0_2 = (void *)(s32)2;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = (s32)a0_2;
                goto _L001E3B58;
            } else if ((s32)s3 > 0) {
                v0 = s_end_save;
                if (v0 != 0) {
                    s_memoca_real_time_check_state = 0xb;
                    break;
                } else {
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    GetMemoryCardMessage((unsigned char)a0_2);
                    a0_2 = (void *)(s32)1;
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)] =
                        (s32)a0_2;
                    MemocaMng[MemocaMng[4]] = 1;
                    goto _L001E3B58;
                }
            } else {
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                s3 = v0;
                a0_2 = (void *)(s32)0xa;
                v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                if (v0 != 0) {
                    s_DialogUseCounter = 0;
                    s_now_dialog_id = 2;
                }
                MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)] = 0;
                v0 = (u32)MemocaMng;
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                a0_2 = (void *)(s32)1;
                *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 + (v1) *
                    1) = (s32)a0_2;
                v0 = use_memoca_slot;
                v0 = v0 + -1;
                a0_2 = (void *)(u8)v0;
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E3908;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E3908;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E3918;
                    }
                }
                _L001E3908:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E3918:;
                v1 = 0x1e;
                if (v0 != v1) {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E3960;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E3960;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E3970;
                        }
                    }
                    _L001E3960:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E3970:;
                    v1 = 0x1f;
                    if (v0 != v1) {
                        goto _L001E3A28;
                    }
                }
                v0 = 4;
                s_check_next_state = v0;
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x8892);
                v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                v1 = 2;
                s_now_dialog_id = v1;
                if (v0 == 0) {
                    s_DialogUseCounter = 0;
                } else {
                    v1 = s_DialogUseCounter;
                    if (v1 == 0) {
                        v1 = *(u16 *)v0;
                        length = 0;
                        if (v1 != 0) {
                            scan = (u16 *)v0;
                            do {
                                scan++;
                                v1 = *scan;
                                length++;
                            } while (v1 != 0);
                        }
                        v1 = length << 1;
                        a1_2 = v0;
                        memcpy((void *)((u8 *)&stackFrame_1020[0]), (void *)a1_2, v1 + 2);
                        a0_2 = (void *)s_aDialogMsg;
                        FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                            *)&stackFrame_1020[0]), 0);
                        v0 = 0xa;
                        s_aDialogResult[2] = 0;
                        s_DialogUseCounter = v0;
                        s_no_pad_check = 0;
                    }
                }
                s_check_next_msg_id = 0;
                goto _L001E3AE8;
                _L001E3A28:;
                v0 = 1;
                if (s3 == v0) {
                    v0 = 4;
                    s_check_next_state = v0;
                    v0 = Menu_CheckSetMemocaState();
                    v1 = 0x18894;
                    v0 = v0 + 0x18894;
                    s_check_next_msg_id = v0;
                }
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x8892);
                v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                v1 = 2;
                s_now_dialog_id = v1;
                if (v0 == 0) {
                    s_DialogUseCounter = 0;
                } else {
                    v1 = s_DialogUseCounter;
                    if (v1 == 0) {
                        v1 = *(u16 *)v0;
                        length = 0;
                        if (v1 != 0) {
                            scan = (u16 *)v0;
                            do {
                                scan++;
                                v1 = *scan;
                                length++;
                            } while (v1 != 0);
                        }
                        v1 = length << 1;
                        a1_2 = v0;
                        memcpy((void *)((u8 *)&stackFrame_C30[0]), (void *)a1_2, v1 + 2);
                        a0_2 = (void *)s_aDialogMsg;
                        FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_C30[0]),
                            0);
                        v0 = 0xa;
                        s_aDialogResult[2] = 0;
                        s_DialogUseCounter = v0;
                        s_no_pad_check = 0;
                    }
                }
                _L001E3AE8:;
                a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                    / 1)];
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E3B20;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E3B20;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E3B30;
                    }
                }
                _L001E3B20:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E3B30:;
                v1 = 1;
                if (v0 == v1) {
                    v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                    v0 = (u32)MemocaMng;
                    *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9 +
                        (v1) * 1) = 2;
                }
                _L001E3B58:;
                MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = 0;
                Menu_CheckSetMemocaState();
                s_memoca_decide_state = 0;
                Menu_CheckSetMemocaState();
                v1 = 1;
                v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)];
                if (v0 != v1) {
                    a0_2 = (void *)use_memoca_slot;
                    if ((u32)(s32)a0_2 == 0 || (u32)(s32)a0_2 == v1 &&
                        (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E / 1)]
                        != v1) {
                        goto _L001E3C50;
                    }
                    v0 = 2;
                    if ((u32)(s32)a0_2 == v0) {
                        v0 = 1;
                        v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 / 1)];
                        if (v1 != v0) {
                            goto _L001E3C50;
                        }
                    }
                    v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_LIST_OK_37E3376E / 1)];
                    v0 = 1;
                    if (v1 != v0) {
                        goto _L001E3C50;
                    }
                    v0 = 0xc;
                    a0_2 = (void *)(s32)5;
                    s_memoca_real_time_check_state = v0;
                    s_memoca_decide_state = 0;
                    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                    a0_2 = (void *)(s32)5;
                    if (v0 != 0) {
                        KnMenuMng_SetForceChangeCursorId((int)a0_2, 0, 0x21);
                    }
                    a0_2 = (void *)(s32)4;
                    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                    a0_2 = (void *)(s32)4;
                    if (v0 != 0) {
                        KnMenuMng_SetForceChangeCursorId((int)a0_2, 0, 0x1e);
                    }
                    a0_2 = (void *)(s32)0xa;
                    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                    if (v0 == 0) {
                        break;
                    }
                    v0 = 0xb;
                    menu_save_ok = 0;
                    s_memoca_real_time_check_state = v0;
                    v0 = 1;
                    s_memoca_decide_state = v0;
                    break;
                } else {
                    _L001E3C50:;
                    v1 = *(s8 *)&s_check_next_state;
                    s_memoca_real_time_check_state = v1;
                    s_check_next_state = 5;
                    break;
                }
            }
        case 9:
            a0_2 = (void *)(s32)5;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x86e8);
                v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                v1 = 2;
                s_now_dialog_id = v1;
                if (v0 == 0) {
                    s_DialogUseCounter = 0;
                } else {
                    v1 = s_DialogUseCounter;
                    if (v1 == 0) {
                        v1 = *(u16 *)v0;
                        length = 0;
                        if (v1 != 0) {
                            scan = (u16 *)v0;
                            do {
                                scan++;
                                v1 = *scan;
                                length++;
                            } while (v1 != 0);
                        }
                        v1 = length << 1;
                        a1_2 = v0;
                        memcpy((void *)((u8 *)&stackFrame_840[0]), (void *)a1_2, v1 + 2);
                        a0_2 = (void *)s_aDialogMsg;
                        FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_840[0]),
                            0);
                        v0 = 0xa;
                        s_aDialogResult[2] = 0;
                        s_DialogUseCounter = v0;
                        s_no_pad_check = 0;
                    }
                }
            } else {
                a0_2 = (void *)(s32)4;
                v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                if (v0 != 0) {
                    v0 = 0x10000;
                    a0_2 = (void *)(0x10000 | 0x86e9);
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    v1 = 2;
                    s_now_dialog_id = v1;
                    if (v0 == 0) {
                        s_DialogUseCounter = 0;
                    } else {
                        v1 = s_DialogUseCounter;
                        if (v1 == 0) {
                            v1 = *(u16 *)v0;
                            length = 0;
                            if (v1 != 0) {
                                scan = (u16 *)v0;
                                do {
                                    scan++;
                                    v1 = *scan;
                                    length++;
                                } while (v1 != 0);
                            }
                            v1 = length << 1;
                            a1_2 = v0;
                            memcpy((void *)((u8 *)&stackFrame_450[0]), (void *)a1_2, v1 + 2);
                            a0_2 = (void *)s_aDialogMsg;
                            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                                *)&stackFrame_450[0]), 0);
                            v0 = 0xa;
                            s_aDialogResult[2] = 0;
                            s_DialogUseCounter = v0;
                            s_no_pad_check = 0;
                        }
                    }
                } else {
                    v0 = 0x10000;
                    a0_2 = (void *)(0x10000 | 0x86ea);
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    v1 = 2;
                    s_now_dialog_id = v1;
                    if (v0 == 0) {
                        s_DialogUseCounter = 0;
                    } else {
                        v1 = s_DialogUseCounter;
                        if (v1 == 0) {
                            v1 = *(u16 *)v0;
                            length = 0;
                            if (v1 != 0) {
                                scan = (u16 *)v0;
                                do {
                                    scan++;
                                    v1 = *scan;
                                    length++;
                                } while (v1 != 0);
                            }
                            v1 = length << 1;
                            a1_2 = v0;
                            memcpy((void *)((u8 *)&stackFrame_60[0]), (void *)a1_2, v1 + 2);
                            a0_2 = (void *)s_aDialogMsg;
                            FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8
                                *)&stackFrame_60[0]), 0);
                            v0 = 0xa;
                            s_aDialogResult[2] = 0;
                            s_DialogUseCounter = v0;
                            s_no_pad_check = 0;
                        }
                    }
                }
            }
            v0 = 0xa;
            s_memoca_real_time_check_state = v0;
            break;
        case 10:
            s3 = s_aDialogResult[2];
            s4 = 0x3e7;
            if (s3 == 0) {
                break;
            }
            a0_2 = (void *)(s32)0xa;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                s4 = 0xa;
            }
            a0_2 = (void *)(s32)4;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                s4 = 4;
            }
            a0_2 = (void *)(s32)5;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                s4 = 5;
            }
            v0 = 1;
            v1 = (u16)s4;
            if (s3 == v0) {
                a0_2 = (void *)(s32)s4;
                if (v1 != (u32)0x3e7) {
                    KnMenuMng_SetForceChangeCursorId((int)a0_2, 0, 0);
                }
            }
            v0 = 2;
            if (s3 != v0) {
                break;
            }
            v0 = 6;
            s_memoca_real_time_check_state = v0;
            break;
        case 11:
            a0_2 = (void *)s2;
            MI_Evrfrm_Load(a0_2, 0x6f);
            v1 = menu_save_ok;
            v0 = 1;
            a0_2 = (void *)(s32)0xa;
            if (v1 == v0) {
                KnMenuMng_SetForceChangeCursorId((int)a0_2, 0, 0x1e);
                s_memoca_real_time_check_state = 0xc;
                break;
            } else {
                v1 = s_memoca_decide_state;
                v0 = 0x2c;
                if (v1 != 0 && v1 != v0) {
                    break;
                }
                v0 = 5;
                s_memoca_real_time_check_state = v0;
            }
        default:
            break;
        }
    }
    a0_2 = (void *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_0__B820828E / 1)];
    v1 = 1;
    if ((u32)a0_2 != v1 && (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 /
        1)] != v1) {
        s_memoca_state = v1;
    }
    v1 = 1;
    if ((u32)a0_2 == v1 && (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 /
        1)] != v1) {
        s_memoca_state = 2;
    }
    v1 = 1;
    if ((u32)a0_2 != v1 && (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 /
        1)] == v1) {
        s_memoca_state = 3;
    }
    v1 = 1;
    if ((u32)a0_2 == v1 && (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE_1__E9E8B199 /
        1)] == v1) {
        s_memoca_state = 4;
    }
    a0_2 = (void *)(s32)0xa;
    *(u32 *)s2 = 0;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)0xa;
    if (v0 != 0) {
        v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
        s0 = v0;
    }
    a0_2 = (void *)(s32)4;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)4;
    if (v0 != 0) {
        v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
        s0 = v0;
    }
    a0_2 = (void *)(s32)5;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
    a0_2 = (void *)(s32)5;
    if (v0 != 0) {
        v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
        s0 = v0;
    }
    switch (s1) {
    case 1:
        v1 = 0x15;
        if (s0 == v1) {
            goto _L001E41B8;
        }
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 5:
        v1 = 0x16;
        if (s0 == v1) {
            goto _L001E41B8;
        }
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 6:
        v1 = 0x15;
        if (s0 != v1) {
            goto _L001E41B8;
        }
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 7:
        v1 = 0x16;
        if (s0 != v1) {
            goto _L001E41B8;
        }
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 8:
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 9:
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 2:
        a0_2 = (void *)s_memoca_state;
        v1 = 2;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 3:
        a0_2 = (void *)s_memoca_state;
        v1 = 2;
        if ((u32)a0_2 != v1) {
            goto _L001E4188;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
        _L001E4188:;
        v1 = 3;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 4:
        a0_2 = (void *)s_memoca_state;
        v1 = 3;
        if ((u32)a0_2 != v1) {
            goto _L001E41B8;
        }
        *(u32 *)s2 = s1;
        goto _L001E4340;
    case 0:
    default:
        _L001E41B8:;
        a0_2 = (void *)(s32)0xa;
        s0 = 0;
        v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
        a0_2 = (void *)(s32)0xa;
        if (v0 != 0) {
            v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
            s0 = v0;
        }
        a0_2 = (void *)(s32)4;
        v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
        a0_2 = (void *)(s32)4;
        if (v0 != 0) {
            v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
            s0 = v0;
        }
        a0_2 = (void *)(s32)5;
        v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
        a0_2 = (void *)(s32)5;
        if (v0 != 0) {
            v0 = KnMenuMng_GetCursorId((int)a0_2, 0);
            s0 = v0;
        }
        a0_2 = (void *)s_memoca_state;
        v1 = 4;
        switch ((u32)a0_2) {
        case 1:
            use_memoca_slot = 0;
            goto _L001E42B0;
        case 2:
            use_memoca_slot = 1;
            goto _L001E42B0;
        case 3:
            use_memoca_slot = 2;
            goto _L001E42B0;
        case 4:
            v1 = 0x15;
            if (s0 == v1) {
                use_memoca_slot = 1;
            }
            v1 = 0x16;
            if (s0 != v1) {
                goto _L001E42B0;
            }
            v1 = 2;
            use_memoca_slot = v1;
            goto _L001E42B0;
        }
    }
    use_memoca_slot = 0;
    _L001E42B0:;
    v1 = 4;
    switch ((u32)a0_2) {
    case 1:
        use_memoca_slot = 0;
        break;
    case 2:
        use_memoca_slot = 1;
        break;
    case 3:
        use_memoca_slot = 2;
        break;
    case 4:
        v1 = 0x15;
        if (s0 == v1) {
            use_memoca_slot = 1;
        }
        v1 = 0x16;
        if (s0 != v1) {
            break;
        }
        v1 = 2;
        use_memoca_slot = v1;
        break;
    default:
        use_memoca_slot = 0;
    }
    *(u32 *)s2 = 0;
    _L001E4340:;
    return;
}


/* MI_Set_Memoca @ 0x1E2C40 .. 0x1E2C48 (0x8 bytes) */




void MI_Set_Memoca(void) {
    return;
}

void MI_Decide_Memoca(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0_7; // v0
    u32 s0;
    u32 v0_8; // v0
    u32 v0;

    a0 = 0xa;
    v0_5 = KnMenuMng_CheckCtrlPlay(a0, 0);
    a0 = 0xa;
    if (v0_5 != 0) {
        v0_2 = KnMenuMng_GetCursorId(a0, 0);
        s0 = v0_2;
    }
    a0 = 4;
    v0_6 = KnMenuMng_CheckCtrlPlay(a0, 0);
    a0 = 4;
    if (v0_6 != 0) {
        v0_3 = KnMenuMng_GetCursorId(a0, 0);
        s0 = v0_3;
    }
    a0 = 5;
    v0_7 = KnMenuMng_CheckCtrlPlay(a0, 0);
    a0 = 5;
    if (v0_7 != 0) {
        v0_4 = KnMenuMng_GetCursorId(a0, 0);
        s0 = v0_4;
    }
    v1 = s_memoca_state;
    v0 = 4;
    switch (v1) {
    case 1:
        use_memoca_slot = 0;
        break;
    case 2:
        v0 = 1;
        use_memoca_slot = v0;
        break;
    case 3:
        v0 = 2;
        use_memoca_slot = v0;
        break;
    case 4:
        v0 = 0x15;
        if (s0 == v0) {
            v0 = 1;
            use_memoca_slot = v0;
        }
        v0 = 0x16;
        if (s0 != v0) {
            break;
        }
        v0 = 2;
        use_memoca_slot = v0;
        break;
    default:
        use_memoca_slot = 0;
    }
    a0 = 1;
    if (v1 == a0) {
        u8 stackFrame_410[16] __attribute__((aligned(16))) = {0};
        u8 stackFrame_20[1008] __attribute__((aligned(16)));
        v0 = 0x10000;
        a0 = 0x10000 | 0x88af;
        v0 = (u32)KnMsgMng_GetMsgStr(a0);
        v1 = 0x19;
        a1 = v0;
        s_memoca_state_msg_id = v1;
        if (a1 == 0) {
            a1 = (u32)&stackFrame_410;
        }
        s_now_dialog_id = 0;
        if (a1 == 0) {
            s_DialogUseCounter = 0;
        } else {
            v1 = s_DialogUseCounter;
            if (v1 == 0) {
                v0 = *(u16 *)a1;
                a0 = 0;
                if (v0 != 0) {
                    v1 = a1;
                    do {
                        v1 = v1 + 2;
                        v0 = *(u16 *)v1;
                        a0 = a0 + 1;
                    } while (v0 != 0);
                }
                v0 = a0 << 1;
                memcpy((void *)((u8 *)&stackFrame_20[0]), (void *)a1, v0 + 2);
                a0 = (u32)s_aDialogMsg;
                FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_20[0]), 0);
                v1 = 0xa;
                *(u8 *)((u8 *)&s_aDialogResult) = 0;
                s_DialogUseCounter = v1;
                s_no_pad_check = 0;
            }
        }
        return;
    }
    MemocaMng[7] = 0;
    v1 = use_memoca_slot;
    v1 = v1 + -1;
    MemocaMng[4] = v1;
    v0 = s_end_save;
    if (v0 != 0) {
        MemocaMng[2 + MemocaMng[4]] = 4;
    } else {
        MemocaMng[2 + MemocaMng[4]] = a0;
    }
    a1 = MemocaMng[4];
    a0 = MemocaMng[2 + a1];
    MemoryCardStart(a0, a1, 0);
    v0 = 1;
    MemocaMng[8] = v0;
    v1 = s_memoca_real_time_check_state;
    v0 = 6;
    if (v1 == v0) {
        v0 = 7;
        s_memoca_real_time_check_state = v0;
    }
    a0 = 0xa;
    v0_8 = KnMenuMng_CheckCtrlPlay(a0, 0);
    v1 = 1;
    if (v0_8 != 0) {
        s_memoca_decide_state = v1;
    }
    v1 = no_snd_on;
    if (v1 == 0) {
        v1 = no_snd_counter;
        if ((s32)v1 > 0) {
            v1 = v1 + -1;
            no_snd_counter = v1;
        } else {
            a0 = 0x11;
            a1 = 0x64;
            SND_Play2D(a0, a1, 0);
        }
    }
    return;
}


/* MI_CntUp_Memoca @ 0x1E2950 .. 0x1E2958 (0x8 bytes) */



void MI_CntUp_Memoca(void) {
    return;
}


/* MI_CntDown_Memoca @ 0x1E2940 .. 0x1E2948 (0x8 bytes) */



void MI_CntDown_Memoca(void) {
    return;
}


/* MI_Gene1_Memoca @ 0x1E2920 .. 0x1E2940 (0x20 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e292c writes a register its branch at 0x1e2928 reads
 *   return without a value in a non-void function
 */


u32 MI_Gene1_Memoca(void) {
    u8 a0;
    u32 v1;

    a0 = s_memoca_real_time_check_state;
    v1 = 6;
    v1 = 9;
    if (!(s32)(a0 != 6)) {
        s_memoca_real_time_check_state = v1;
    }
    return;
}


/* MI_Gene2_Memoca @ 0x1E2910 .. 0x1E2918 (0x8 bytes) */



void MI_Gene2_Memoca(void) {
    return;
}


/* MI_Evrfrm_Memoca @ 0x1E28C0 .. 0x1E2904 (0x44 bytes, frame 0x10) */


void MI_Evrfrm_Memoca(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 v1;

    MI_Get_Memoca(a0, a1);
    v1 = use_memoca_slot;
    menu_load_ok = 0;
    menu_save_ok = 0;
    if (v1 == 0) {
        s_memoca_state_msg_id = 0x19;
    } else {
        Menu_CheckSetMemocaState();
    }
    return;
}


/* MI_Init_Memoca @ 0x1E28B0 .. 0x1E28B8 (0x8 bytes) */




void MI_Init_Memoca(void) {
    return;
}
void MI_Check_Memoca(void *output) {
    MICardFlags *flags = output;
    *(u32 *)output = 0;
    s_memoca_state_msg_id = -1;
    if ((u32)(s_memoca_real_time_check_state - 9) > 1) {
        if ((u32)s_memoca_real_time_check_state > 2) {
            if (s_memoca_real_time_check_state != 3) goto checked;
        }
    }
        flags->busy |= 1;
        flags->check |= 1;
checked:
    if (s_memoca_real_time_check_state != 6) {
        flags->flag1 |= 1;
        flags->flag2 |= 1;
        flags->flag3 |= 1;
        flags->flag4 |= 1;
        flags->busy |= 1;
        flags->check |= 1;
        flags->flag5 |= 1;
    }
}
void MI_Get_Load(void *a0, signed int a1) {
    u32 *output;
    s32 page;
    s32 type;
    u8 *header;
    s32 number;
    u32 text;
    u32 format;
    u32 duration;
    u32 hours;
    u32 minutes;
    u32 seconds;
    output = (u32 *)a0;
    number = a1 / 10;
    type = a1 % 10;
    page = number + memoca_index_offset;
    header = (u8 *)GetSaveDataHeader(0) + (page - 1) * 8;
    switch (type) {
    case 1:
        number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
        text = (u32)KnMsgMng_GetMsgStr(0x493f1);
        FsFontReplaceText((void *)number, (void *)text, page);
        *output = number;
        break;
    case 2:
        if (header[0] != 0) {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493eb);
            text = (u32)KnMsgMng_GetMsgStr(header[1] + 0x18768);
            FsFontReplaceText((void *)number, (void *)format, text);
        } else {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493eb);
            text = (u32)KnMsgMng_GetMsgStr(0x493ee);
            FsFontReplaceText((void *)number, (void *)format, text);
        }
        *output = number;
        break;
    case 3:
        if (header[0] != 0) {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493ec);
            text = (u32)KnMsgMng_GetMsgStr(header[2] + 0x1adb0);
            FsFontReplaceText((void *)number, (void *)format, text);
        } else {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493ec);
            text = (u32)KnMsgMng_GetMsgStr(0x493ef);
            FsFontReplaceText((void *)number, (void *)format, text);
        }
        *output = number;
        break;
    case 4:
        if (header[0] != 0) {
            duration = *(u32 *)(header + 4);
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493ed);
            hours = duration / 216000;
            minutes = duration / 3600 % 60;
            seconds = duration / 60 % 60;
            FsFontReplaceText((void *)number, (void *)format, hours, minutes, seconds);
        } else {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            text = (u32)KnMsgMng_GetMsgStr(0x493f0);
            FsFontReplaceText((void *)number, (void *)text);
        }
        *output = number;
        break;
    case 5:
        if (header[0] != 0) {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493f2);
            text = (u32)KnMsgMng_GetMsgStr(header[3] + 0x18772);
            FsFontReplaceText((void *)number, (void *)format, text);
        } else {
            number = (u32)&((u8 (*)[5][64])aTmpMemocaData)[number - 1][type - 1][0];
            format = (u32)KnMsgMng_GetMsgStr(0x493f3);
            text = (u32)KnMsgMng_GetMsgStr(0x493f3);
            FsFontReplaceText((void *)number, (void *)format, text);
        }
        *output = number;
        break;
    default:
        *output = 0;
    }
}


/* MI_Set_Load @ 0x1E2260 .. 0x1E2268 (0x8 bytes) */



void MI_Set_Load(void) {
    return;
}


/* MI_Decide_Load @ 0x1E21F0 .. 0x1E2254 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1e2214 writes a register its branch at 0x1e2210 reads
 *   delay: addiu at 0x1e223c writes a register its branch at 0x1e2238 reads
 *   return without a value in a non-void function
 */


u32 MI_Decide_Load(void) {
    s32 a0;
    s32 a1;
    u32 v0;
    s32 branchcond_1e2210;
    s32 v1;
    s32 branchcond_1e2238;

    a0 = 4;
    a1 = 1;
    v0 = KnMenuMng_CheckCtrlPlay(a0, a1);
    if (v0 != 0) {
        v0 = s_memoca_decide_state;
        branchcond_1e2210 = v0 != 0;
        v0 = 1;
        if (!branchcond_1e2210) {
            s_memoca_decide_state_order = v0;
        }
    }
    a0 = 5;
    a1 = 1;
    v0 = KnMenuMng_CheckCtrlPlay(a0, a1);
    if (v0 != 0) {
        v1 = s_memoca_decide_state;
        branchcond_1e2238 = (u32)v1 != 0;
        v1 = 0x15;
        if (!branchcond_1e2238) {
            s_memoca_decide_state_order = v1;
        }
    }
    return;
}


/* MI_CntUp_Load @ 0x1E2170 .. 0x1E21E4 (0x74 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 1 parameters vs 2 inferred
 */






void MI_CntUp_Load(signed int a0 /* r4 */, s32 a1) {
    u32 v1;

    v1 = 0x29;
    if ((u32)a1 == v1) {
        a0 = memoca_index_offset;
        if ((s32)a0 < (s32)4) {
            v1 = s_memoca_decide_state;
            if (v1 == 0) {
                v1 = no_snd_on;
                memoca_index_offset = (u32)(a0) + 1;
                if (v1 == 0) {
                    v1 = no_snd_counter;
                    if ((s32)v1 > 0) {
                        no_snd_counter = v1 + -1;
                    } else {
                        SND_Play2D(0x14, 0x64, 0);
                    }
                }
            }
        }
    }
    return;
}


/* MI_CntDown_Load @ 0x1E2100 .. 0x1E216C (0x6c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: 1 parameters vs 2 inferred
 */






void MI_CntDown_Load(signed int a0 /* r4 */, s32 a1) {
    u32 v1;

    v1 = 0xb;
    if ((u32)a1 == v1) {
        a0 = memoca_index_offset;
        if ((s32)a0 > 0 && (u32)s_memoca_decide_state == 0) {
            v1 = no_snd_on;
            memoca_index_offset = (u32)(a0) + -1;
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    no_snd_counter = v1 + -1;
                } else {
                    SND_Play2D(0x14, 0x64, 0);
                }
            }
        }
    }
    return;
}


/* MI_Gene1_Load @ 0x1E20F0 .. 0x1E20F8 (0x8 bytes) */



void MI_Gene1_Load(void) {
    return;
}


/* MI_Gene2_Load @ 0x1E20E0 .. 0x1E20E8 (0x8 bytes) */




void MI_Gene2_Load(void) {
    return;
}
static inline void MI_Evrfrm_Load__inl0(void) {
    void *a0_2;
    u32 v0_23;
    u32 v0_26;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0x889d);
    v0_26 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
    a0_2 = (void *)(s32)2;
    a1_2 = v0_26;
    Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
}

static inline void MI_Evrfrm_Load__inl1(u32 s1) {
    void *a0_2;
    u32 v0_21;
    u32 v0_22;
    u32 v0_25;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0x889e);
    v0_25 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
    a0_2 = (void *)(s32)2;
    a1_2 = v0_25;
    Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, s1);
}

static inline void MI_Evrfrm_Load__inl2(u32 s1) {
    void *a0_2;
    u32 v0_9;
    u32 v0_18;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0xd4e6);
    v0_18 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
    a0_2 = (void *)(s32)2;
    a1_2 = v0_18;
    Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, s1);
}

static inline void MI_Evrfrm_Load__inl3(u32 s1) {
    void *a0_2;
    u32 v0_13;
    u32 v0_14;
    signed int a1_2;

    a0_2 = (void *)(0x10000 | 0x88a4);
    v0_14 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
    a0_2 = (void *)(s32)2;
    a1_2 = v0_14;
    Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, s1);
}

static inline void MemocaClear(s32 msg) {
    if (msg == 2 || msg == 4 || msg == 0x16 || msg == 0x17) {
        s_load_slot = 0;
        s_load_offset = 0;
        memoca_index_offset = 0;
    }
}
void MI_Evrfrm_Load(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 s1;
    u32 s0;
    u32 a2;
    void *a0_2; // a0
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 v0_4; // v0
    u32 v0_5; // v0
    u32 v0_6; // v0
    u32 v0_7; // v0
    u32 v0_8; // v0
    u32 v0_10; // v0
    u32 v0_11; // v0
    u32 v0_12; // v0
    u32 v0_15; // v0
    u32 v0_16; // v0
    u32 v0_17; // v0
    u32 v0_19; // v0
    u32 v0_20; // v0
    u32 v0_24; // v0
    u32 v0_27; // v0
    u32 v0_28; // v0
    u32 v0_29; // v0
    u32 v0_30; // v0
    u32 s4;
    u32 v0_31; // v0
    u32 v0_32; // v0
    u32 v0_33; // v0
    u32 v0_34; // v0
    u32 s3;
    u32 s2;
    s32 at;
    u32 v0_35; // v0
    u32 v0;
    signed int a1_2;

    s1 = (u32)a0;
    s4 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)];
    s0 = a1;
    a0_2 = (void *)(s32)4;
    a1_2 = 1;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
    a0_2 = (void *)(s32)4;
    if (v0 != 0) {
        v0 = KnMenuMng_GetCursorId((int)a0_2, 1);
        v1 = 0x36;
        switch (v0) {
        case 51:
            v0 = memoca_index_offset;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 52:
            v0 = memoca_index_offset;
            v0 = v0 + 1;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 53:
            v0 = memoca_index_offset;
            v0 = v0 + 2;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 54:
            v0 = memoca_index_offset;
            v0 = v0 + 3;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
        }
    }
    a0_2 = (void *)(s32)5;
    a1_2 = 1;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
    a0_2 = (void *)(s32)5;
    if (v0 != 0) {
        v0 = KnMenuMng_GetCursorId((int)a0_2, 1);
        v1 = 0x36;
        switch (v0) {
        case 51:
            v0 = memoca_index_offset;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 52:
            v0 = memoca_index_offset;
            v0 = v0 + 1;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 53:
            v0 = memoca_index_offset;
            v0 = v0 + 2;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
            break;
        case 54:
            v0 = memoca_index_offset;
            v0 = v0 + 3;
            MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)] = v0;
        }
    }
    v0 = 0x64;
    a1_2 = (s32)s0 % 0x64;
    a0_2 = (void *)s1;
    MI_Get_Load(a0_2, a1_2);
    v1 = 0x6f;
    if (s0 == v1) {
        v1 = 0x28;
        s3 = 0;
        s2 = -1;
        a0_2 = (void *)s_memoca_decide_state;
        if ((u32)a0_2 != v1) {
            v1 = 0x27;
            if ((u32)a0_2 == v1) {
                goto _L001DE288;
            }
            v1 = 0x24;
            if ((u32)a0_2 != v1) {
                v1 = 0x23;
                if ((u32)a0_2 != v1) {
                    v1 = 0x22;
                    if ((u32)a0_2 != v1) {
                        v1 = 0x21;
                        if ((u32)a0_2 != v1) {
                            v1 = 0x2e;
                            if ((u32)a0_2 != v1) {
                                v1 = 0x2d;
                                if ((u32)a0_2 != v1) {
                                    v1 = 0x2c;
                                    if ((u32)a0_2 != v1) {
                                        v1 = 0x2b;
                                        if ((u32)a0_2 != v1) {
                                        v1 = 0x2a;
                                        if ((u32)a0_2 != v1) {
                                        v1 = 0x29;
                                        if ((u32)a0_2 != v1) {
                                        if ((u32)a0_2 != s2) {
                                        goto _L001DE2A0;
                                        }
                                        }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            _L001DE288:;
            a0_2 = (void *)(s32)0xa;
            v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
            if (v0 != 0) {
                _L001DE2A0:;
                s3 = MemoryCardProc();
                if (s3 != 0) {
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = 0;
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 != v1) {
                            v1 = 0x16;
                            if (v0 != v1) {
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DE300;
                                }
                            }
                        }
                    }
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DE300:;
                    a1_2 = 1;
                    if (v0 != (u32)(s32)a1_2) {
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v1 = (u32)MemocaMng;
                        *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9
                            + ((u32)(a0_2)) * 1) = a1_2;
                    } else {
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v1 = (u32)MemocaMng;
                        *(u8 *)(MemocaMng + DCOMP_OFF_STRUCT_DW_2298180_FIELDS_STATE__0___2A5040B9
                            + ((u32)(a0_2)) * 1) = 2;
                    }
                    a0_2 = (void *)s_memoca_decide_state;
                    if (!((u32)((u32)a0_2 - 9) <= 1 || (u32)((u32)a0_2 - 0xd) <= 1
                          || (u32)((u32)a0_2 - 0x15) <= 1 || (u32)((u32)a0_2 - 0x1b) <= 3
                          || (u32)((u32)a0_2 - 3) <= 1 || (u32)((u32)a0_2 - 0x11) <= 1)) {
                        v0 = GetMemoryCardMessage((unsigned char)(use_memoca_slot - 1));
                        MemocaClear(v0);
                        if (v0 != 2) {
                            v0 = GetMemoryCardMessage((unsigned char)(use_memoca_slot - 1));
                            MemocaClear(v0);
                            if (v0 != 4) {
                                v0 = GetMemoryCardMessage((unsigned char)(use_memoca_slot - 1));
                                MemocaClear(v0);
                                if (v0 != 0x16) {
                                    v0 = GetMemoryCardMessage((unsigned char)(use_memoca_slot - 1));
                                    MemocaClear(v0);
                                    if (v0 != 0x17) {
                                        v0 = GetMemoryCardMessage((unsigned char)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)]);
                                        MemocaClear(v0);
                                        if (v0 != 1) {
                                            goto _L001DE568;
                                        }
                                    }
                                }
                            }
                        }
                        v1 = s_memoca_decide_state;
                        v1 = v1 + -0x27;
                        if (v1 > (u32)1) {
                            s_memoca_decide_state = 0x27;
                        }
                    }
                    _L001DE568:;
                    s2 = MemocaMng[2 + (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)]];
                }
            }
        }
        do {
            a1_2 = s_memoca_decide_state;
            s1 = 1;
            switch (a1_2) {
            case 0:
                if (s4 == s1) {
                    if (s3 == 0) {
                        break;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DE5F8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DE5F8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DE608;
                        }
                    }
                    _L001DE5F8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DE608:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE650;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE650;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE660;
                            }
                        }
                        _L001DE650:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE660:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DE770;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE6A8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE6A8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE6B8;
                            }
                        }
                        _L001DE6A8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE6B8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DE770;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE700;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE700;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE710;
                            }
                        }
                        _L001DE700:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE710:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DE770;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE750;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE750;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE760;
                            }
                        }
                        _L001DE750:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE760:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001DE780;
                        }
                    }
                    _L001DE770:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                    _L001DE780:;
                    a0_2 = (void *)s_memoca_decide_state_order;
                    v1 = -1;
                    if ((u32)a0_2 == v1) {
                        break;
                    }
                    s_memoca_decide_state = (u8)a0_2;
                    s_memoca_decide_state_order = v1;
                    break;
                } else {
                    if (s4 != 0) {
                        break;
                    }
                    a0_2 = (void *)s_memoca_decide_state_order;
                    v1 = -1;
                    s_next_mode = 0;
                    if ((u32)a0_2 == v1) {
                        break;
                    }
                    s_memoca_decide_state = (u8)a0_2;
                    s_memoca_decide_state_order = v1;
                    break;
                }
            case 1:
                v1 = (u32)(a1_2) + 1;
                s_memoca_decide_state = v1;
            case 2:
                v1 = 1;
                if (s4 == v1) {
                    if (s3 == 0) {
                        break;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DE820;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DE820;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DE830;
                        }
                    }
                    _L001DE820:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DE830:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE878;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE878;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE888;
                            }
                        }
                        _L001DE878:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE888:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DE998;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE8D0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE8D0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE8E0;
                            }
                        }
                        _L001DE8D0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE8E0:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DE998;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE928;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE928;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE938;
                            }
                        }
                        _L001DE928:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE938:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DE998;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DE978;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DE978;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DE988;
                            }
                        }
                        _L001DE978:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DE988:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001DE9A8;
                        }
                    }
                    _L001DE998:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                    _L001DE9A8:;
                    v1 = 5;
                    s_memoca_decide_state = v1;
                    s1 = 0;
                    break;
                } else {
                    s_memoca_decide_state = 5;
                    break;
                }
            case 5:
                a0_2 = (void *)(s32)0xa;
                s_next_mode = 0;
                v0_33 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                a0_2 = (void *)(s32)2;
                if (v0_33 == 0) {
                    Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                }
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0xd4e6);
                v0_34 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_34;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 1);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 6:
                if (s3 == 0) {
                    break;
                }
                if (s2 != 0) {
                    v0 = s_next_mode;
                    if (v0 != 0) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DEA80;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DEA80;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DEA90;
                        }
                    }
                    _L001DEA80:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DEA90:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEAD8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEAD8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEAE8;
                            }
                        }
                        _L001DEAD8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEAE8:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DEBF8;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEB30;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEB30;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEB40;
                            }
                        }
                        _L001DEB30:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEB40:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DEBF8;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEB88;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEB88;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEB98;
                            }
                        }
                        _L001DEB88:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEB98:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DEBF8;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEBD8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEBD8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEBE8;
                            }
                        }
                        _L001DEBD8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEBE8:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001DEBF8:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DEC40;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DEC40;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DEC50;
                        }
                    }
                    _L001DEC40:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DEC50:;
                    v1 = 3;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEC98;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEC98;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DECA8;
                            }
                        }
                        _L001DEC98:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DECA8:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DED68;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DECF0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DECF0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DED00;
                            }
                        }
                        _L001DECF0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DED00:;
                        v1 = 0x15;
                        if (v0 == v1) {
                            goto _L001DED68;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DED48;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DED48;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DED58;
                            }
                        }
                        _L001DED48:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DED58:;
                        v1 = 4;
                        if (v0 != v1) {
                            goto _L001DED78;
                        }
                    }
                    _L001DED68:;
                    v1 = 7;
                    s_memoca_decide_state = v1;
                    goto _L001DF0D0;
                    _L001DED78:;
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DEDB0;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DEDB0;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DEDC0;
                        }
                    }
                    _L001DEDB0:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DEDC0:;
                    if (v0 != 0) {
                        v1 = 0x23;
                        v0 = 0x18892;
                        s_memoca_decide_state = v1;
                        s_fixed_fail_msg_id = 0x18892;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEE18;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEE18;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEE28;
                            }
                        }
                        _L001DEE18:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEE28:;
                        v1 = 2;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DEE70;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DEE70;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DEE80;
                                }
                            }
                            _L001DEE70:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DEE80:;
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEF90;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DEEC8;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DEEC8;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DEED8;
                                }
                            }
                            _L001DEEC8:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DEED8:;
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEF90;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DEF20;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DEF20;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DEF30;
                                }
                            }
                            _L001DEF20:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DEF30:;
                            v1 = 0x17;
                            if (v0 == v1) {
                                goto _L001DEF90;
                            }
                            a0_2 = (void
                                *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                                / 1)];
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DEF70;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DEF70;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DEF80;
                                }
                            }
                            _L001DEF70:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DEF80:;
                            v1 = 1;
                            if (v0 != v1) {
                                goto _L001DEFA0;
                            }
                        }
                        _L001DEF90:;
                        v1 = 0x27;
                        s_fixed_end_state = v1;
                        goto _L001DF0D0;
                        _L001DEFA0:;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DEFD8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DEFD8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DEFE8;
                            }
                        }
                        _L001DEFD8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DEFE8:;
                        v1 = 0x1e;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DF030;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DF030;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DF040;
                                }
                            }
                            _L001DF030:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DF040:;
                            v1 = 0x1f;
                            if (v0 != v1) {
                                goto _L001DF060;
                            }
                        }
                        v1 = 0x21;
                        s_memoca_decide_state = v1;
                        goto _L001DF0D0;
                        _L001DF060:;
                        s_fixed_end_state = 0;
                    } else {
                        a0_2 = (void *)(s32)0xa;
                        v0_32 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                        if (v0_32 != 0) {
                            v0_30 = ExistKuonData();
                            if (v0_30 != 0) {
                                s_memoca_decide_state = 0xb;
                            } else {
                                s_memoca_decide_state = 0xd;
                            }
                        } else {
                            a0_2 = (void
                                *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B
                                / 1)];
                            v0_31 = ExistSaveData((signed int)a0_2);
                            if (v0_31 != 0) {
                                s_memoca_decide_state = 0xf;
                            } else {
                                s_memoca_decide_state = 0x11;
                            }
                        }
                    }
                    _L001DF0D0:;
                    s1 = 0;
                    break;
                }
            case 7:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x8898);
                v0_29 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_29;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 8:
                a0_2 = (void *)s_aDialogResult[2];
                v1 = 1;
                if ((u32)a0_2 == 0) {
                    break;
                }
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 9;
                }
                v1 = 2;
                if ((u32)a0_2 != v1) {
                    break;
                }
                v1 = 0x2d;
                s_memoca_decide_state = v1;
                break;
            case 9:
                v0 = 5;
                s_next_mode = v0;
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x8899);
                v0_28 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_28;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, s1);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 10:
                v1 = 5;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF1F8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF1F8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DF208;
                        }
                    }
                    _L001DF1F8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DF208:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF250;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF250;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF260;
                            }
                        }
                        _L001DF250:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF260:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF370;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF2A8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF2A8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF2B8;
                            }
                        }
                        _L001DF2A8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF2B8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF370;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF300;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF300;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF310;
                            }
                        }
                        _L001DF300:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF310:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DF370;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF350;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF350;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF360;
                            }
                        }
                        _L001DF350:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF360:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001DF370:;
                    v1 = 0x27;
                    s_next_mode = 0;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF3B8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF3B8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DF3C8;
                        }
                    }
                    _L001DF3B8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DF3C8:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF410;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF410;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF420;
                            }
                        }
                        _L001DF410:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF420:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF530;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF468;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF468;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF478;
                            }
                        }
                        _L001DF468:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF478:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF530;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF4C0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF4C0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF4D0;
                            }
                        }
                        _L001DF4C0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF4D0:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DF530;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF510;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF510;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF520;
                            }
                        }
                        _L001DF510:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF520:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001DF540;
                        }
                    }
                    _L001DF530:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                    _L001DF540:;
                    a0_2 = (void *)(s32)2;
                    Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                    if ((s32)s3 > 0) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF598;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF598;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF5A8;
                            }
                        }
                        _L001DF598:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF5A8:;
                        v1 = 0x34;
                        a0_2 = (void *)(s32)0xa;
                        if (v0 == v1) {
                            v0_27 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                            if (v0_27 != 0) {
                                s_memoca_decide_state = 0xd;
                            } else {
                                s_memoca_decide_state = 0x11;
                            }
                        }
                    }
                    if ((s32)s3 >= 0) {
                        break;
                    }
                    v1 = 0x23;
                    v0 = 0x1889b;
                    s_memoca_decide_state = v1;
                    s_fixed_fail_msg_id = 0x1889b;
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF630;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF630;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DF640;
                        }
                    }
                    _L001DF630:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DF640:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF688;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF688;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF698;
                            }
                        }
                        _L001DF688:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF698:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF7A8;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF6E0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF6E0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF6F0;
                            }
                        }
                        _L001DF6E0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF6F0:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF7A8;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF738;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF738;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF748;
                            }
                        }
                        _L001DF738:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF748:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DF7A8;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF788;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF788;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF798;
                            }
                        }
                        _L001DF788:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF798:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001DF7B8;
                        }
                    }
                    _L001DF7A8:;
                    v1 = 0x27;
                    s_fixed_end_state = v1;
                    break;
                    _L001DF7B8:;
                    s_fixed_end_state = 0;
                    break;
                }
            case 11:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl0();
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 12:
                a0_2 = (void *)s_aDialogResult[2];
                v1 = 1;
                if ((u32)a0_2 == 0) {
                    break;
                }
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 0xd;
                }
                v1 = 2;
                if ((u32)a0_2 != v1) {
                    break;
                }
                v1 = 0x2d;
                s_memoca_decide_state = v1;
                break;
            case 13:
                a0_2 = (void *)(s32)0x36cd;
                ItemMng_Add_Direct((unsigned short)a0_2, -1);
                v0 = s_memoca_decide_state;
                s_next_mode = 4;
                a0_2 = (void *)(s32)2;
                v0 = v0 + 1;
                s_memoca_decide_state = v0;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl1(s1);
            case 14:
                v1 = 4;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DF8F0;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DF8F0;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DF900;
                        }
                    }
                    _L001DF8F0:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DF900:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF948;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF948;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF958;
                            }
                        }
                        _L001DF948:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF958:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DFA68;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF9A0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF9A0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DF9B0;
                            }
                        }
                        _L001DF9A0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DF9B0:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DFA68;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DF9F8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DF9F8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFA08;
                            }
                        }
                        _L001DF9F8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFA08:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001DFA68;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFA48;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFA48;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFA58;
                            }
                        }
                        _L001DFA48:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFA58:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001DFA68:;
                    v1 = 0x27;
                    s_next_mode = 0;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    a0_2 = (void *)(s32)2;
                    Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                    if ((s32)s3 > 0) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFAD0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFAD0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFAE0;
                            }
                        }
                        _L001DFAD0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFAE0:;
                        v1 = 0x3e;
                        a0_2 = (void *)(s32)4;
                        if (v0 != v1) {
                            goto _L001DFB08;
                        }
                        v0_24 = KnMenuMng_CheckCtrlPlay((int)a0_2, 1);
                        a0_2 = (void *)(s32)(v0_24 != 0);
                        v1 = 0x13;
                        menu_save_ok = (s32)a0_2;
                        s_memoca_decide_state = v1;
                        break;
                    } else {
                        _L001DFB08:;
                        a0_2 = (void *)(s32)0x36cd;
                        if (s3 == 0) {
                            break;
                        }
                        ItemMng_Add_Direct((unsigned short)a0_2, 1);
                        v1 = 0x23;
                        v0 = 0x188a1;
                        s_memoca_decide_state = v1;
                        s_fixed_fail_msg_id = 0x188a1;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFB68;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFB68;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFB78;
                            }
                        }
                        _L001DFB68:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFB78:;
                        v1 = 2;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DFBC0;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DFBC0;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DFBD0;
                                }
                            }
                            _L001DFBC0:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DFBD0:;
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFCE0;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DFC18;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DFC18;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DFC28;
                                }
                            }
                            _L001DFC18:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DFC28:;
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFCE0;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DFC70;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DFC70;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DFC80;
                                }
                            }
                            _L001DFC70:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DFC80:;
                            v1 = 0x17;
                            if (v0 == v1) {
                                goto _L001DFCE0;
                            }
                            a0_2 = (void
                                *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                                / 1)];
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DFCC0;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DFCC0;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DFCD0;
                                }
                            }
                            _L001DFCC0:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DFCD0:;
                            v1 = 1;
                            if (v0 != v1) {
                                goto _L001DFCF0;
                            }
                        }
                        _L001DFCE0:;
                        v1 = 0x27;
                        s_fixed_end_state = v1;
                        break;
                        _L001DFCF0:;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFD28;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFD28;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFD38;
                            }
                        }
                        _L001DFD28:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFD38:;
                        v1 = 0x1e;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001DFD80;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001DFD80;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001DFD90;
                                }
                            }
                            _L001DFD80:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001DFD90:;
                            v1 = 0x1f;
                            if (v0 != v1) {
                                goto _L001DFDB0;
                            }
                        }
                        v1 = 0x21;
                        s_fixed_end_state = v1;
                        break;
                        _L001DFDB0:;
                        s_fixed_end_state = 0;
                        break;
                    }
                }
            case 15:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl0();
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 16:
                a0_2 = (void *)s_aDialogResult[2];
                v1 = 1;
                if ((u32)a0_2 == 0) {
                    break;
                }
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 0x11;
                }
                v1 = 2;
                if ((u32)a0_2 != v1) {
                    break;
                }
                v1 = 0x2d;
                s_memoca_decide_state = v1;
                break;
            case 3:
                a0_2 = (void *)(s32)2;
                s_next_mode = s1;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl1(s1);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 4:
                v1 = 1;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001DFED8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001DFED8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001DFEE8;
                        }
                    }
                    _L001DFED8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001DFEE8:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFF30;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFF30;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFF40;
                            }
                        }
                        _L001DFF30:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFF40:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0050;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFF88;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFF88;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFF98;
                            }
                        }
                        _L001DFF88:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFF98:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0050;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001DFFE0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001DFFE0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001DFFF0;
                            }
                        }
                        _L001DFFE0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001DFFF0:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E0050;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0030;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0030;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0040;
                            }
                        }
                        _L001E0030:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0040:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001E0050:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    v1 = 0x11;
                    if ((s32)s3 > 0) {
                        s_memoca_decide_state = v1;
                    }
                    if ((s32)s3 >= 0) {
                        break;
                    }
                    v1 = 0x23;
                    v0 = 0x188a1;
                    s_memoca_decide_state = v1;
                    s_fixed_fail_msg_id = 0x188a1;
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E00C8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E00C8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E00D8;
                        }
                    }
                    _L001E00C8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E00D8:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0120;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0120;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0130;
                            }
                        }
                        _L001E0120:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0130:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0240;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0178;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0178;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0188;
                            }
                        }
                        _L001E0178:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0188:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0240;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E01D0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E01D0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E01E0;
                            }
                        }
                        _L001E01D0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E01E0:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E0240;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0220;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0220;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0230;
                            }
                        }
                        _L001E0220:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0230:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001E0250;
                        }
                    }
                    _L001E0240:;
                    v1 = 0x27;
                    s_fixed_end_state = v1;
                    break;
                    _L001E0250:;
                    s_fixed_end_state = 0;
                    break;
                }
            case 17:
                a0_2 = (void *)(s32)0x36cd;
                ItemMng_Add_Direct((unsigned short)a0_2, -1);
                v0 = s_memoca_decide_state;
                s_next_mode = 3;
                a0_2 = (void *)(s32)2;
                v0 = v0 + 1;
                s_memoca_decide_state = v0;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl1(s1);
            case 18:
                v1 = 3;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0310;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0310;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0320;
                        }
                    }
                    _L001E0310:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0320:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0368;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0368;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0378;
                            }
                        }
                        _L001E0368:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0378:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0488;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E03C0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E03C0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E03D0;
                            }
                        }
                        _L001E03C0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E03D0:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0488;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0418;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0418;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0428;
                            }
                        }
                        _L001E0418:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0428:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E0488;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0468;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0468;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0478;
                            }
                        }
                        _L001E0468:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0478:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001E0488:;
                    v1 = 0x27;
                    s_next_mode = 0;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    a0_2 = (void *)(s32)2;
                    Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                    if ((s32)s3 > 0) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E04F0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E04F0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0500;
                            }
                        }
                        _L001E04F0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0500:;
                        v1 = 0x3e;
                        if (v0 != v1) {
                            goto _L001E0540;
                        }
                        a0_2 = (void *)(s32)4;
                        v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                            1)];
                        a1_2 = 1;
                        s_load_slot = v1;
                        v0 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B /
                            1)];
                        s_load_offset = v0;
                        v0_20 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                        a0_2 = (void *)(s32)(v0_20 != 0);
                        v1 = 0x13;
                        menu_save_ok = (s32)a0_2;
                        s_memoca_decide_state = v1;
                        break;
                    } else {
                        _L001E0540:;
                        a0_2 = (void *)(s32)0x36cd;
                        if (s3 == 0) {
                            break;
                        }
                        ItemMng_Add_Direct((unsigned short)a0_2, 1);
                        v1 = 0x23;
                        v0 = 0x188a1;
                        s_memoca_decide_state = v1;
                        s_fixed_fail_msg_id = 0x188a1;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E05A0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E05A0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E05B0;
                            }
                        }
                        _L001E05A0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E05B0:;
                        v1 = 2;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E05F8;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E05F8;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E0608;
                                }
                            }
                            _L001E05F8:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E0608:;
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0718;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E0650;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E0650;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E0660;
                                }
                            }
                            _L001E0650:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E0660:;
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0718;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E06A8;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E06A8;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E06B8;
                                }
                            }
                            _L001E06A8:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E06B8:;
                            v1 = 0x17;
                            if (v0 == v1) {
                                goto _L001E0718;
                            }
                            a0_2 = (void
                                *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                                / 1)];
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E06F8;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E06F8;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E0708;
                                }
                            }
                            _L001E06F8:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E0708:;
                            v1 = 1;
                            if (v0 != v1) {
                                goto _L001E0728;
                            }
                        }
                        _L001E0718:;
                        v1 = 0x27;
                        s_fixed_end_state = v1;
                        break;
                        _L001E0728:;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0760;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0760;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0770;
                            }
                        }
                        _L001E0760:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0770:;
                        v1 = 0x1e;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E07B8;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E07B8;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E07C8;
                                }
                            }
                            _L001E07B8:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E07C8:;
                            v1 = 0x1f;
                            if (v0 != v1) {
                                goto _L001E07E8;
                            }
                        }
                        v1 = 0x21;
                        s_fixed_end_state = v1;
                        break;
                        _L001E07E8:;
                        s_fixed_end_state = 0;
                        break;
                    }
                }
            case 19:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x88a0);
                v0_19 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_19;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 20:
                a0_2 = (void *)s_aDialogResult[2];
                v1 = 1;
                if ((u32)a0_2 == 0) {
                    break;
                }
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 0x2b;
                }
                v1 = 2;
                if ((u32)a0_2 != v1) {
                    break;
                }
                v1 = 0x2b;
                s_memoca_decide_state = v1;
                break;
            case 21:
                a0_2 = (void *)(s32)2;
                s_next_mode = s1;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl2(s1);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 22:
                v1 = 1;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0910;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0910;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0920;
                        }
                    }
                    _L001E0910:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0920:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0968;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0968;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0978;
                            }
                        }
                        _L001E0968:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0978:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0A88;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E09C0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E09C0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E09D0;
                            }
                        }
                        _L001E09C0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E09D0:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0A88;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0A18;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0A18;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0A28;
                            }
                        }
                        _L001E0A18:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0A28:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E0A88;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0A68;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0A68;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0A78;
                            }
                        }
                        _L001E0A68:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0A78:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001E0A88:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    if ((s32)s3 > 0) {
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B /
                            1)];
                        v0_17 = ExistSaveData((signed int)a0_2);
                        if (v0_17 != 0) {
                            s_memoca_decide_state = 0x17;
                        } else {
                            s_memoca_decide_state = 0x19;
                        }
                    }
                    if ((s32)s3 >= 0) {
                        break;
                    }
                    v1 = 0x23;
                    v0 = 0x18892;
                    s_memoca_decide_state = v1;
                    s_fixed_fail_msg_id = 0x18892;
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0B18;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0B18;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0B28;
                        }
                    }
                    _L001E0B18:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0B28:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0B70;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0B70;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0B80;
                            }
                        }
                        _L001E0B70:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0B80:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0C90;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0BC8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0BC8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0BD8;
                            }
                        }
                        _L001E0BC8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0BD8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0C90;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0C20;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0C20;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0C30;
                            }
                        }
                        _L001E0C20:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0C30:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E0C90;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E0C70;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E0C70;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E0C80;
                            }
                        }
                        _L001E0C70:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E0C80:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001E0CA0;
                        }
                    }
                    _L001E0C90:;
                    v1 = 0x27;
                    s_fixed_end_state = v1;
                    break;
                    _L001E0CA0:;
                    s_fixed_end_state = 0;
                    break;
                }
            case 25:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x88a7);
                v0_16 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_16;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 26:
                s0 = s_aDialogResult[2];
                if (s0 == 0) {
                    break;
                }
                v0 = use_memoca_slot;
                v0 = v0 + -1;
                a0_2 = (void *)(u8)v0;
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E0D30;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E0D30;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E0D40;
                    }
                }
                _L001E0D30:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E0D40:;
                v1 = 2;
                if (v0 != v1) {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0D88;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0D88;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0D98;
                        }
                    }
                    _L001E0D88:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0D98:;
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E0EA8;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0DE0;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0DE0;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0DF0;
                        }
                    }
                    _L001E0DE0:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0DF0:;
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E0EA8;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0E38;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0E38;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0E48;
                        }
                    }
                    _L001E0E38:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0E48:;
                    v1 = 0x17;
                    if (v0 == v1) {
                        goto _L001E0EA8;
                    }
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0E88;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0E88;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E0E98;
                        }
                    }
                    _L001E0E88:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E0E98:;
                    v1 = 1;
                    if (v0 != v1) {
                        goto _L001E0EB8;
                    }
                }
                _L001E0EA8:;
                v1 = 0x27;
                s_memoca_decide_state = v1;
                break;
                _L001E0EB8:;
                if (s0 == v1) {
                    s_memoca_decide_state = 0x2d;
                }
                v1 = 2;
                if (s0 != v1) {
                    break;
                }
                v1 = 0x2d;
                s_memoca_decide_state = v1;
                break;
            case 23:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x88a3);
                v0_15 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_15;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 24:
                a0_2 = (void *)s_aDialogResult[2];
                v1 = 1;
                if ((u32)a0_2 == 0) {
                    break;
                }
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 0x1d;
                }
                v1 = 2;
                if ((u32)a0_2 != v1) {
                    break;
                }
                v1 = 0x2d;
                s_memoca_decide_state = v1;
                break;
            case 27:
                v0 = (u32)(a1_2) + 1;
                s_memoca_decide_state = v0;
                a0_2 = (void *)(s32)2;
                s_next_mode = s1;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl3(s1);
            case 28:
                v1 = 1;
                if (s3 == 0) {
                    break;
                }
                if (s2 != v1) {
                    v0 = s_next_mode;
                    if (v0 != v1) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E0FF8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E0FF8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1008;
                        }
                    }
                    _L001E0FF8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1008:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1050;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1050;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1060;
                            }
                        }
                        _L001E1050:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1060:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1170;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E10A8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E10A8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E10B8;
                            }
                        }
                        _L001E10A8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E10B8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1170;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1100;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1100;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1110;
                            }
                        }
                        _L001E1100:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1110:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E1170;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1150;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1150;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1160;
                            }
                        }
                        _L001E1150:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1160:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001E1170:;
                    v1 = 0x27;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    v1 = 0x1d;
                    if ((s32)s3 > 0) {
                        s_memoca_decide_state = v1;
                    }
                    if ((s32)s3 >= 0) {
                        break;
                    }
                    v1 = 0x23;
                    v0 = 0x188a6;
                    s_memoca_decide_state = v1;
                    s_fixed_fail_msg_id = 0x188a6;
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E11E8;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E11E8;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E11F8;
                        }
                    }
                    _L001E11E8:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E11F8:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1240;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1240;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1250;
                            }
                        }
                        _L001E1240:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1250:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1360;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1298;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1298;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E12A8;
                            }
                        }
                        _L001E1298:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E12A8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1360;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E12F0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E12F0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1300;
                            }
                        }
                        _L001E12F0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1300:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E1360;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1340;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1340;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1350;
                            }
                        }
                        _L001E1340:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1350:;
                        v1 = 1;
                        if (v0 != v1) {
                            goto _L001E1370;
                        }
                    }
                    _L001E1360:;
                    v1 = 0x27;
                    s_fixed_end_state = v1;
                    break;
                    _L001E1370:;
                    s_fixed_end_state = 0;
                    break;
                }
            case 29:
                v0 = (u32)(a1_2) + 1;
                a0_2 = (void *)(s32)2;
                s_memoca_decide_state = v0;
                s_next_mode = (s32)a0_2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl3(s1);
            case 30:
                a0_2 = (void *)(s32)2;
                if (s3 == 0) {
                    break;
                }
                if (s2 != (u32)(s32)a0_2) {
                    v0 = s_next_mode;
                    if (v0 != (u32)(s32)a0_2) {
                        v0 = s_memoca_decide_state;
                        v0 = v0 + -1;
                        s_memoca_decide_state = v0;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1418;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1418;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1428;
                        }
                    }
                    _L001E1418:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1428:;
                    v1 = 2;
                    if (v0 != v1) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1470;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1470;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1480;
                            }
                        }
                        _L001E1470:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1480:;
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1590;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E14C8;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E14C8;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E14D8;
                            }
                        }
                        _L001E14C8:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E14D8:;
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1590;
                        }
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1520;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1520;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1530;
                            }
                        }
                        _L001E1520:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1530:;
                        v1 = 0x17;
                        if (v0 == v1) {
                            goto _L001E1590;
                        }
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1570;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1570;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1580;
                            }
                        }
                        _L001E1570:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1580:;
                        v1 = 1;
                        if (v0 != v1) {
                            break;
                        }
                    }
                    _L001E1590:;
                    v1 = 0x27;
                    s_next_mode = 0;
                    s_memoca_decide_state = v1;
                    break;
                } else {
                    Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                    if ((s32)s3 > 0) {
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E15F0;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E15F0;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1600;
                            }
                        }
                        _L001E15F0:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1600:;
                        v1 = 0x48;
                        if (v0 != v1) {
                            goto _L001E1630;
                        }
                        v1 = 0x1f;
                        a0_2 = (void
                            *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                            / 1)];
                        s_load_slot = (u32)a0_2;
                        v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B /
                            1)];
                        s_load_offset = v1;
                        s_memoca_decide_state = 0x1f;
                        break;
                    } else {
                        _L001E1630:;
                        if (s3 == 0) {
                            break;
                        }
                        v1 = 0x23;
                        v0 = 0x188a6;
                        s_memoca_decide_state = v1;
                        s_fixed_fail_msg_id = 0x188a6;
                        v0 = use_memoca_slot;
                        v0 = v0 + -1;
                        a0_2 = (void *)(u8)v0;
                        v0 = GetMemoryCardMessage((unsigned char)a0_2);
                        v1 = 2;
                        if (v0 != v1) {
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1688;
                            }
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1688;
                            }
                            v1 = 0x17;
                            if (v0 != v1) {
                                goto _L001E1698;
                            }
                        }
                        _L001E1688:;
                        s_load_slot = 0;
                        s_load_offset = 0;
                        memoca_index_offset = 0;
                        _L001E1698:;
                        v1 = 2;
                        if (v0 != v1) {
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E16E0;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E16E0;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E16F0;
                                }
                            }
                            _L001E16E0:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E16F0:;
                            v1 = 4;
                            if (v0 == v1) {
                                goto _L001E1800;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E1738;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E1738;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E1748;
                                }
                            }
                            _L001E1738:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E1748:;
                            v1 = 0x16;
                            if (v0 == v1) {
                                goto _L001E1800;
                            }
                            v0 = use_memoca_slot;
                            v0 = v0 + -1;
                            a0_2 = (void *)(u8)v0;
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E1790;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E1790;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E17A0;
                                }
                            }
                            _L001E1790:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E17A0:;
                            v1 = 0x17;
                            if (v0 == v1) {
                                goto _L001E1800;
                            }
                            a0_2 = (void
                                *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0
                                / 1)];
                            v0 = GetMemoryCardMessage((unsigned char)a0_2);
                            v1 = 2;
                            if (v0 != v1) {
                                v1 = 4;
                                if (v0 == v1) {
                                    goto _L001E17E0;
                                }
                                v1 = 0x16;
                                if (v0 == v1) {
                                    goto _L001E17E0;
                                }
                                v1 = 0x17;
                                if (v0 != v1) {
                                    goto _L001E17F0;
                                }
                            }
                            _L001E17E0:;
                            s_load_slot = 0;
                            s_load_offset = 0;
                            memoca_index_offset = 0;
                            _L001E17F0:;
                            v1 = 1;
                            if (v0 != v1) {
                                goto _L001E1810;
                            }
                        }
                        _L001E1800:;
                        v1 = 0x27;
                        s_fixed_end_state = v1;
                        break;
                        _L001E1810:;
                        s_fixed_end_state = 0;
                        break;
                    }
                }
            case 31:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                a0_2 = (void *)(0x10000 | 0x88a5);
                v0_12 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_12;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 32:
                s0 = s_aDialogResult[2];
                a0_2 = (void *)(s32)5;
                if (s0 == 0) {
                    break;
                }
                v0_11 = KnMenuMng_CheckCtrlPlay((int)a0_2, 1);
                a0_2 = (void *)(s32)(v0_11 != 0);
                v1 = 1;
                menu_load_ok = (s32)a0_2;
                if (s0 == v1) {
                    s_memoca_decide_state = 0x2b;
                }
                v1 = 2;
                if (s0 != v1) {
                    break;
                }
                v1 = 0x2b;
                s_memoca_decide_state = v1;
                break;
            case 33:
                v0 = use_memoca_slot;
                v0 = v0 + -1;
                a0_2 = (void *)(u8)v0;
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E18D8;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E18D8;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E18E8;
                    }
                }
                _L001E18D8:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E18E8:;
                v1 = 2;
                if (v0 != v1) {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1930;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1930;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1940;
                        }
                    }
                    _L001E1930:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1940:;
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E1A50;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1988;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1988;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1998;
                        }
                    }
                    _L001E1988:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1998:;
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E1A50;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E19E0;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E19E0;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E19F0;
                        }
                    }
                    _L001E19E0:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E19F0:;
                    v1 = 0x17;
                    if (v0 == v1) {
                        goto _L001E1A50;
                    }
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1A30;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1A30;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1A40;
                        }
                    }
                    _L001E1A30:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1A40:;
                    v1 = 1;
                    if (v0 != v1) {
                        goto _L001E1A60;
                    }
                }
                _L001E1A50:;
                v1 = 0x27;
                s_memoca_decide_state = v1;
                break;
                _L001E1A60:;
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                Menu_CallMemocaStateDialog();
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 34:
                v1 = s_aDialogResult[2];
                if (v1 == 0) {
                    break;
                }
                s_memoca_decide_state = 0;
                break;
            case 35:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                a0_2 = (void *)s_fixed_fail_msg_id;
                v0_10 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_10;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 36:
                v1 = s_aDialogResult[2];
                if (v1 == 0) {
                    break;
                }
                a0_2 = (void *)*(s8 *)&s_fixed_end_state;
                v1 = -1;
                if ((u32)a0_2 == v1) {
                    s_memoca_decide_state = 0x25;
                } else {
                    s_memoca_decide_state = (u8)a0_2;
                }
                v1 = -1;
                s_fixed_end_state = v1;
                break;
            case 37:
                a0_2 = (void *)(s32)2;
                s_next_mode = 0;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v0 = 0x10000;
                MI_Evrfrm_Load__inl2(s1);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
                break;
            case 38:
                if (s3 == 0) {
                    break;
                }
                v0 = use_memoca_slot;
                v0 = v0 + -1;
                a0_2 = (void *)(u8)v0;
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E1BA8;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E1BA8;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E1BB8;
                    }
                }
                _L001E1BA8:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E1BB8:;
                v1 = 2;
                if (v0 != v1) {
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1C00;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1C00;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1C10;
                        }
                    }
                    _L001E1C00:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1C10:;
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E1D20;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1C58;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1C58;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1C68;
                        }
                    }
                    _L001E1C58:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1C68:;
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E1D20;
                    }
                    v0 = use_memoca_slot;
                    v0 = v0 + -1;
                    a0_2 = (void *)(u8)v0;
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1CB0;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1CB0;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1CC0;
                        }
                    }
                    _L001E1CB0:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1CC0:;
                    v1 = 0x17;
                    if (v0 == v1) {
                        goto _L001E1D20;
                    }
                    a0_2 = (void
                        *)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 /
                        1)];
                    v0 = GetMemoryCardMessage((unsigned char)a0_2);
                    v1 = 2;
                    if (v0 != v1) {
                        v1 = 4;
                        if (v0 == v1) {
                            goto _L001E1D00;
                        }
                        v1 = 0x16;
                        if (v0 == v1) {
                            goto _L001E1D00;
                        }
                        v1 = 0x17;
                        if (v0 != v1) {
                            goto _L001E1D10;
                        }
                    }
                    _L001E1D00:;
                    s_load_slot = 0;
                    s_load_offset = 0;
                    memoca_index_offset = 0;
                    _L001E1D10:;
                    v1 = 1;
                    if (v0 != v1) {
                        goto _L001E1D30;
                    }
                }
                _L001E1D20:;
                v1 = 0x27;
                s_memoca_decide_state = v1;
                break;
                _L001E1D30:;
                v0 = use_memoca_slot;
                v0 = v0 + -1;
                a0_2 = (void *)(u8)v0;
                v0 = GetMemoryCardMessage((unsigned char)a0_2);
                v1 = 2;
                if (v0 != v1) {
                    v1 = 4;
                    if (v0 == v1) {
                        goto _L001E1D68;
                    }
                    v1 = 0x16;
                    if (v0 == v1) {
                        goto _L001E1D68;
                    }
                    v1 = 0x17;
                    if (v0 != v1) {
                        goto _L001E1D78;
                    }
                }
                _L001E1D68:;
                s_load_slot = 0;
                s_load_offset = 0;
                memoca_index_offset = 0;
                _L001E1D78:;
                a0_2 = (void *)(s32)2;
                s_memoca_decide_state = 0;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                break;
            case 39:
                a0_2 = (void *)(s32)2;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)0, 0, 0);
                v1 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                v0 = 0x18894;
                v1 = v1 + 0x1c;
                v1 = (s16)v1;
                a0_2 = (void *)(s32)(v1 + 0x18894);
                v0_8 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                a0_2 = (void *)(s32)2;
                a1_2 = v0_8;
                Menu_SetDialogMsg((int)a0_2, (unsigned char *)a1_2, 0, 0);
                v1 = s_memoca_decide_state;
                v1 = v1 + 1;
                s_memoca_decide_state = v1;
            case 40:
                v1 = s_aDialogResult[2];
                a0_2 = (void *)(s32)0xa;
                if (v1 == 0) {
                    break;
                }
                v0_5 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                if (v0_5 != 0) {
                    s_memoca_real_time_check_state = 6;
                }
                a0_2 = (void *)(s32)4;
                a1_2 = 1;
                v0_6 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                a0_2 = (void *)(s32)4;
                if (v0_6 != 0) {
                    KnMenuMng_SetForceChangeCursorId((int)a0_2, 1, 0);
                }
                a0_2 = (void *)(s32)5;
                a1_2 = 1;
                v0_7 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                a0_2 = (void *)(s32)5;
                if (v0_7 != 0) {
                    KnMenuMng_SetForceChangeCursorId((int)a0_2, 1, 0);
                }
                v1 = 0x29;
                s_memoca_decide_state = v1;
                break;
            case 41:
                v1 = (u32)(a1_2) + 1;
                s_memoca_decide_state = v1;
                break;
            case 43:
                v0 = (u32)(a1_2) + 1;
                s_memoca_decide_state = v0;
            case 44:
                a0_2 = (void *)(s32)0xa;
                v0_2 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                a0_2 = (void *)(s32)0xa;
                if (v0_2 != 0) {
                    KnMenuMng_SetForceChangeCursorId((int)a0_2, 0, 1);
                }
                a0_2 = (void *)(s32)4;
                a1_2 = 1;
                v0_3 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                a1_2 = 1;
                if (v0_3 != 0) {
                    KnMenuMng_SetForceChangeCursorId(4, a1_2, a1_2);
                }
                a0_2 = (void *)(s32)5;
                a1_2 = 1;
                v0_4 = KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                a1_2 = 1;
                if (v0_4 != 0) {
                    KnMenuMng_SetForceChangeCursorId(5, a1_2, a1_2);
                }
                s_memoca_decide_state = 0x29;
                break;
            case 45:
                v0 = (u32)(a1_2) + 1;
                s_memoca_decide_state = v0;
            case 46:
                a0_2 = (void *)(s32)0xa;
                KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
                a0_2 = (void *)(s32)4;
                KnMenuMng_CheckCtrlPlay((int)a0_2, 1);
                a0_2 = (void *)(s32)5;
                a1_2 = 1;
                KnMenuMng_CheckCtrlPlay((int)a0_2, a1_2);
                s_memoca_decide_state = 0;
            case 42:
            default:
                break;
            }
            v1 = s1 != 0;
            v1 = v1 ^ 1;
        } while (v1 != 0);
        v1 = s_memoca_decide_state;
        a0_2 = (void *)(s32)0x22;
        if (v1 != (u32)(s32)a0_2) {
            a0_2 = (void *)(s32)0x21;
            if (v1 != (u32)(s32)a0_2) {
                a0_2 = (void *)(s32)0x24;
                if (v1 != (u32)(s32)a0_2) {
                    a0_2 = (void *)(s32)0x23;
                    if (v1 != (u32)(s32)a0_2) {
                        a0_2 = (void *)(s32)0x28;
                        if (v1 != (u32)(s32)a0_2) {
                            a0_2 = (void *)(s32)0x27;
                            if (v1 != (u32)(s32)a0_2) {
                                a0_2 = (void *)(s32)0x20;
                                if (v1 != (u32)(s32)a0_2) {
                                    a0_2 = (void *)(s32)0x1f;
                                    if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x14;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x13;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x1e;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x1d;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x12;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x11;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0xe;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0xd;
                                        if (v1 != (u32)(s32)a0_2) {
                                        a0_2 = (void *)(s32)0x2e;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)0x2d;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)0x2c;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)0x2b;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)0x2a;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)0x29;
                                        if (v1 == (u32)(s32)a0_2) {
                                        goto _L001E20C0;
                                        }
                                        a0_2 = (void *)(s32)-1;
                                        if (v1 != (u32)(s32)a0_2) {
                                        goto _L001E2058;
                                        }
                                        goto _L001E20C0;
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            v1 = s_next_mode;
            if (v1 == 0) {
                goto _L001E20C0;
            }
        }
        a0_2 = (void *)(s32)0xa;
        v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, 0);
        if (v0 != 0 || (u32)s_next_mode != 0) {
            _L001E2058:;
            if (s3 != 0 || MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)]
                == 0) {
                a1_2 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)];
                a0_2 = (void *)*(u8 *)((u8 *)&s_next_mode);
                a2 = MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_DATA_INDEX_40965F1B / 1)];
                menu_load_ok = 0;
                v0_35 = MemoryCardStart((unsigned char)a0_2, a1_2, a2);
                if (v0_35 == 0) {
                    MemocaMng[2 + (u32)MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_PORT_B8644FA0 / 1)]] = s_next_mode;
                    MemocaMng[(DCOMP_OFF_STRUCT_DW_2298180_FIELDS_CHECKING_ON_07DF47ED / 1)] = 1;
                    s_next_mode = 0;
                }
            }
        }
    }
    _L001E20C0:;
    return;
}


/* MI_Init_Load @ 0x1DE050 .. 0x1DE058 (0x8 bytes) */



void MI_Init_Load(void) {
    return;
}


/* MI_Check_Load @ 0x1DDF00 .. 0x1DE044 (0x144 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ddfa0 writes a register its branch at 0x1ddf9c reads
 *   declaration vs inferred signature: return void vs inferred u32
 */






void MI_Check_Load(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s1;
    s32 s0;
    u32 v1;

    s1 = (u8 *)a0;
    *(u32 *)a0 = 0;
    v1 = menu_load_ok;
    s0 = a1;
    if (v1 == 0 && (u32)menu_save_ok == 0) {
        a1 = *(u8 *)s1;
        a0 = (void *)(s32)-2;
        a0 = (void *)((u32)(a1) & (u32)((u32)(a0)));
        a1 = (u32)(a1) & 1;
        *(u8 *)s1 = (u32)((u32)(a0)) | (u32)((u32)((u32)(a1) | 1) & 1);
        ((struct { unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)(s1 + 2))->f = ((struct {
            unsigned char _pad:7; unsigned char f:1; } *)&*(u8 *)(s1 + 2))->f | 1;
    } else {
        KnMenuMng_CheckCtrlPlay(4, 1);
        KnMenuMng_CheckCtrlPlay(5, 1);
    }
    v1 = s_memoca_decide_state;
    if (v1 != 0) {
        *(u32 *)s1 = -1;
    }
    if ((u32)s0 == (u32)0x29 && (s32)memoca_index_offset >= (s32)4) {
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)(s1 + 1))->f = ((struct {
            unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)(s1 + 1))->f | 1;
    }
    if ((u32)s0 == (u32)0xb && (s32)memoca_index_offset <= 0) {
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)(s1 + 1))->f = ((struct {
            unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)(s1 + 1))->f | 1;
    }
    return;
}


/* MI_Get_SL_Scrl @ 0x1DDEF0 .. 0x1DDEF8 (0x8 bytes) */



void MI_Get_SL_Scrl(void) {
    return;
}


/* MI_Set_SL_Scrl @ 0x1DDEE0 .. 0x1DDEE8 (0x8 bytes) */



void MI_Set_SL_Scrl(void) {
    return;
}


/* MI_Decide_SL_Scrl @ 0x1DDED0 .. 0x1DDED8 (0x8 bytes) */



void MI_Decide_SL_Scrl(void) {
    return;
}


/* MI_CntUp_SL_Scrl @ 0x1DDEC0 .. 0x1DDEC8 (0x8 bytes) */



void MI_CntUp_SL_Scrl(void) {
    return;
}


/* MI_CntDown_SL_Scrl @ 0x1DDEB0 .. 0x1DDEB8 (0x8 bytes) */



void MI_CntDown_SL_Scrl(void) {
    return;
}


/* MI_Gene1_SL_Scrl @ 0x1DDEA0 .. 0x1DDEA8 (0x8 bytes) */



void MI_Gene1_SL_Scrl(void) {
    return;
}


/* MI_Gene2_SL_Scrl @ 0x1DDE90 .. 0x1DDE98 (0x8 bytes) */



void MI_Gene2_SL_Scrl(void) {
    return;
}









/* MI_Evrfrm_SL_Scrl @ 0x1DDE60 .. 0x1DDE88 (0x28 bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40800000 at 0x1dde68
 *   declaration vs inferred signature: return void vs inferred float
 */




void MI_Evrfrm_SL_Scrl(void *a0 /* r4 */) {
    float f0;

    f0 = 4.0f;
    *(f32 *)a0 = ((float)(float)((float)memoca_index_offset) / 4.0f);
    return;
}









/* MI_Init_SL_Scrl @ 0x1DDE50 .. 0x1DDE58 (0x8 bytes) */



void MI_Init_SL_Scrl(void) {
    return;
}


/* MI_Check_SL_Scrl @ 0x1DDE40 .. 0x1DDE48 (0x8 bytes) */



void MI_Check_SL_Scrl(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* Menu_SettingStore @ 0x1DDDC0 .. 0x1DDE40 (0x80 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */









u8 Menu_SettingStore(void) {
    u8 v1;
    u32 v0;
    u32 a0;
    s32 a1;

    v1 = GameSt[0x16];
    stg_str_key = v1;
    v0 = GameSt[0x15];
    stg_str_vib = v0;
    v0 = GetVagMasterVolume(0);
    stg_str_bgm = (u16)v0;
    v0 = SND_GetVol(3);
    stg_str_se = (u8)v0;
    v0 = GetVagMasterVolume(1);
    a1 = *(s8 *)(GameSt + 0x1e);
    a0 = g_pSndMng;
    stg_str_voice = (u16)v0;
    stg_str_kido = a1;
    a0 = *(u8 *)((a0 + 0x2c));
    v1 = GameSt[0x2c];
    stg_str_SndMode = a0;
    stg_str_lang = v1;
    return;
}


/* MI_Get_Setting @ 0x1DDD40 .. 0x1DDDC0 (0x80 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */









u8 MI_Get_Setting(void) {
    u8 v1;
    u32 v0;
    u32 a0;
    s32 a1;

    v1 = GameSt[0x16];
    stg_str_key = v1;
    v0 = GameSt[0x15];
    stg_str_vib = v0;
    v0 = GetVagMasterVolume(0);
    stg_str_bgm = (u16)v0;
    v0 = SND_GetVol(3);
    stg_str_se = (u8)v0;
    v0 = GetVagMasterVolume(1);
    a1 = *(s8 *)(GameSt + 0x1e);
    a0 = g_pSndMng;
    stg_str_voice = (u16)v0;
    stg_str_kido = a1;
    a0 = *(u8 *)((a0 + 0x2c));
    v1 = GameSt[0x2c];
    stg_str_SndMode = a0;
    stg_str_lang = v1;
    return;
}


/* MI_Set_Setting @ 0x1DDC90 .. 0x1DDD38 (0xa8 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   fpu: float literal 0x467ffc00 at 0x1ddccc
 *   fpu: float literal 0x437f0000 at 0x1ddcd0
 */




void MI_Set_Setting(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    float f1;
    float f0;
    u32 v0;

    v1 = stg_str_key;
    v0 = stg_str_vib;
    a1 = *(u16 *)((u8 *)&stg_str_bgm);
    GameSt[0x16] = v1;
    GameSt[0x15] = v0;
    SetVagMasterVolume(0, a1);
    v0 = 0x467f0000;
    v1 = 0x467f0000 | 0xfc00;
    f1 = 16383.0f;
    f0 = 255.0f;
    a0 = ((s32)(255.0f * ((float)(float)((float)stg_str_bgm) / 16383.0f)));
    SND_SqSetVolume(a0);
    SND_SetVol(3, *(u8 *)((u8 *)&stg_str_se));
    a1 = *(u16 *)((u8 *)&stg_str_voice);
    SetVagMasterVolume(1, a1);
    a1 = stg_str_kido;
    a0 = stg_str_SndMode;
    v1 = g_pSndMng;
    GameSt[0x1e] = a1;
    *(u8 *)((v1 + 0x2c)) = a0;
    v1 = stg_str_lang;
    GameSt[0x2c] = v1;
    return;
}


/* MI_Decide_Setting @ 0x1DDC80 .. 0x1DDC88 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j KnMenuWindMng_SetTopWindRate at 0x1ddc80 leaves the function
 *   return value dropped, call kept: the function is void
 */


void MI_Decide_Setting(void) {
    KnMenuWindMng_SetTopWindRate();
    return;
}


/* MI_CntUp_Setting @ 0x1DDC70 .. 0x1DDC78 (0x8 bytes) */



void MI_CntUp_Setting(void) {
    return;
}


/* MI_CntDown_Setting @ 0x1DDC60 .. 0x1DDC68 (0x8 bytes) */



void MI_CntDown_Setting(void) {
    return;
}


/* MI_Gene1_Setting @ 0x1DDBF0 .. 0x1DDC58 (0x68 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */




u32 MI_Gene1_Setting(void) {
    u8 *v1;

    GameSt[0x16] = 0;
    GameSt[0x15] = 1;
    SetVagMasterVolume(0, 0x3fff);
    SND_SqSetVolume(0xff);
    SND_SetVol(3, 0x7f);
    SetVagMasterVolume(1, 0x3fff);
    v1 = (u8 *)g_pSndMng;
    GameSt[0x1e] = 0;
    *(u8 *)(v1 + 0x2c) = 2;
    return;
}


/* MI_Gene2_Setting @ 0x1DDB70 .. 0x1DDBF0 (0x80 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


u8 MI_Gene2_Setting(void) {
    u8 v1;
    u32 v0;
    u32 a0;
    s32 a1;

    v1 = GameSt[0x16];
    stg_str_key = v1;
    v0 = GameSt[0x15];
    stg_str_vib = v0;
    v0 = GetVagMasterVolume(0);
    stg_str_bgm = (u16)v0;
    v0 = SND_GetVol(3);
    stg_str_se = (u8)v0;
    v0 = GetVagMasterVolume(1);
    a1 = *(s8 *)(GameSt + 0x1e);
    a0 = g_pSndMng;
    stg_str_voice = (u16)v0;
    stg_str_kido = a1;
    a0 = *(u8 *)((a0 + 0x2c));
    v1 = GameSt[0x2c];
    stg_str_SndMode = a0;
    stg_str_lang = v1;
    return;
}


/* MI_Evrfrm_Setting @ 0x1DDB60 .. 0x1DDB68 (0x8 bytes) */



void MI_Evrfrm_Setting(void) {
    return;
}


/* MI_Init_Setting @ 0x1DDB50 .. 0x1DDB58 (0x8 bytes) */



void MI_Init_Setting(void) {
    return;
}


/* MI_Check_Setting @ 0x1DDB40 .. 0x1DDB48 (0x8 bytes) */



void MI_Check_Setting(void) {
    return;
}






/* MI_Get_GoTtl @ 0x1DDB30 .. 0x1DDB38 (0x8 bytes) */



void MI_Get_GoTtl(void) {
    return;
}


/* MI_Set_GoTtl @ 0x1DDB20 .. 0x1DDB28 (0x8 bytes) */



void MI_Set_GoTtl(void) {
    return;
}


/* MI_Decide_GoTtl @ 0x1DDB00 .. 0x1DDB18 (0x18 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1ddb08 writes a register its branch at 0x1ddb04 reads
 *   return without a value in a non-void function
 */


u32 MI_Decide_GoTtl(void) {
    u32 v1;
    s32 branchcond_1ddb04;

    v1 = s_go_ttl_state;
    branchcond_1ddb04 = v1 != 0;
    v1 = 1;
    if (!branchcond_1ddb04) {
        s_go_ttl_state = v1;
    }
    return;
}


/* MI_CntUp_GoTtl @ 0x1DDAF0 .. 0x1DDAF8 (0x8 bytes) */



void MI_CntUp_GoTtl(void) {
    return;
}


/* MI_CntDown_GoTtl @ 0x1DDAE0 .. 0x1DDAE8 (0x8 bytes) */



void MI_CntDown_GoTtl(void) {
    return;
}


/* MI_Gene1_GoTtl @ 0x1DDAD0 .. 0x1DDAD8 (0x8 bytes) */



void MI_Gene1_GoTtl(void) {
    return;
}


/* MI_Gene2_GoTtl @ 0x1DDAC0 .. 0x1DDAC8 (0x8 bytes) */




void MI_Gene2_GoTtl(void) {
    return;
}

void MI_Evrfrm_GoTtl(void) {
    u32 a1;
    u32 a0;
    u32 v1;
    u32 v0;
    u8 stackFrame_10[1008] __attribute__((aligned(16)));

    v1 = 3;
    a1 = s_go_ttl_state;
    a0 = 2;
    switch (a1) {
    case 0:
        break;
    case 1:
        s_now_dialog_id = a0;
        v0 = 0x10000;
        s_DialogUseCounter = 0;
        v0 = (u32)KnMsgMng_GetMsgStr(0x10000 | 0x86eb);
        a1 = v0;
        s_now_dialog_id = 0;
        if (a1 == 0) {
            s_DialogUseCounter = 0;
        } else {
            v1 = s_DialogUseCounter;
            if (v1 == 0) {
                v0 = *(u16 *)a1;
                a0 = 0;
                if (v0 != 0) {
                    v1 = a1;
                    do {
                        v1 = v1 + 2;
                        v0 = *(u16 *)v1;
                        a0 = a0 + 1;
                    } while (v0 != 0);
                }
                memcpy((void *)((u8 *)&stackFrame_10[0]), (void *)a1, (u32)(a0 << 1) + 2);
                a0 = (u32)s_aDialogMsg;
                FsFontReplaceText((void *)s_aDialogMsg, (void *)((u8 *)&stackFrame_10[0]), 0);
                *(u8 *)((u8 *)&s_aDialogResult) = 0;
                s_DialogUseCounter = 0xa;
                s_no_pad_check = 0;
            }
        }
        s_go_ttl_state = 2;
        break;
    case 2:
        a0 = *(u8 *)((u8 *)&s_aDialogResult);
        if (a0 == 0) {
            break;
        }
        if (a0 == (u32)1) {
            SetGoToTitleFlag();
            s_go_ttl_state = 3;
            break;
        } else {
            s_go_ttl_state = 0;
        }
    case 3:
        break;
    }
    return;
}


/* MI_Init_GoTtl @ 0x1DD980 .. 0x1DD988 (0x8 bytes) */




void MI_Init_GoTtl(void) {
    return;
}



void MI_Check_GoTtl(void *pVariable) {
    if (s_go_ttl_state == 1 || s_go_ttl_state == 2) {
        ((MIVARX *)pVariable)->bit.b0 |= 1;
    }
}


/* MI_Get_HelpStr @ 0x1DD930 .. 0x1DD938 (0x8 bytes) */



void MI_Get_HelpStr(void) {
    return;
}


/* MI_Set_HelpStr @ 0x1DD920 .. 0x1DD928 (0x8 bytes) */



void MI_Set_HelpStr(void) {
    return;
}


/* MI_Decide_HelpStr @ 0x1DD910 .. 0x1DD918 (0x8 bytes) */



void MI_Decide_HelpStr(void) {
    return;
}






/* MI_CntUp_HelpStr @ 0x1DD900 .. 0x1DD908 (0x8 bytes) */



void MI_CntUp_HelpStr(void) {
    return;
}


/* MI_CntDown_HelpStr @ 0x1DD8F0 .. 0x1DD8F8 (0x8 bytes) */



void MI_CntDown_HelpStr(void) {
    return;
}


/* MI_Gene1_HelpStr @ 0x1DD8E0 .. 0x1DD8E8 (0x8 bytes) */



void MI_Gene1_HelpStr(void) {
    return;
}


/* MI_Gene2_HelpStr @ 0x1DD8D0 .. 0x1DD8D8 (0x8 bytes) */




void MI_Gene2_HelpStr(void) {
    return;
}

void MI_Evrfrm_HelpStr(void *pVariable, signed int id) {
    u32 msg_id;
    u32 sub;
    u32 st;
    int cur;
    int cancel_offset;
    u16 *pTmpStr;
    u32 len;
    u16 *scan;

    msg_id = 0x1882f;
    if (id > 20000) {
        pTmpStr = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
        len = 0;
        if (*pTmpStr != 0) {
            scan = pTmpStr;
            do {
                scan++;
                len++;
            } while (*scan != 0);
        }
        memcpy(aTmpHelpStr2, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (len << 1) + 2);
        switch (id) {
        case 10001:
            len = 0;
            if (*pTmpStr != 0) {
                scan = (u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
                do {
                    scan++;
                    len++;
                } while (*scan != 0);
            }
            memcpy(aTmpHelpStr2, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", (len << 1) + 2);
            break;
        }
        *(void **)pVariable = aTmpHelpStr2;
        return;
    }
    if (id > 10000) {
        switch (id) {
        case 10001:
            msg_id = MemocaMng[4] + 0x186de;
            break;
        }
        pTmpStr = KnMsgMng_GetMsgStr(msg_id);
        if (pTmpStr != 0) {
            len = 0;
            if (*pTmpStr != 0) {
                scan = pTmpStr;
                do {
                    scan++;
                    len++;
                } while (*scan != 0);
            }
            memcpy(aTmpHelpStr2, pTmpStr, (len << 1) + 2);
        } else {
            sprintf((char *)aTmpHelpStr2, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000");
        }
        *(void **)pVariable = aTmpHelpStr2;
        return;
    }
    cur = KnMenuMng_GetCursorId((u16)(id / 100), id % 100);
    switch (id / 100) {
    case 3:
        switch (id % 100) {
        case 0:
            switch (cur) {
            case 0: msg_id = 0x187cd; break;
            case 6: msg_id = 0x187ce; break;
            case 12: msg_id = 0x187cf; break;
            case 18: msg_id = 0x187d0; break;
            case 24: msg_id = 0x187d1; break;
            case 30: msg_id = 0x187d2; break;
            }
            break;
        case 1:
            cancel_offset = 0;
            switch (cur) {
            case 11: msg_id = 0x187d7; break;
            case 12: msg_id = 0x187d8; break;
            case 13: msg_id = 0x187d9; break;
            case 21: msg_id = 0x187da; break;
            case 25:
                if (now_equip_button == 0) cancel_offset = 1;
                if (now_equip_button == 1) cancel_offset = 2;
                if (now_equip_button == 2) cancel_offset = 3;
                msg_id = 0x18817 + cancel_offset;
                break;
            case 26: msg_id = 0x187dc; break;
            case 27: msg_id = 0x187dc; break;
            case 28: msg_id = 0x187dc; break;
            case 29: msg_id = 0x187dc; break;
            case 30: msg_id = 0x187dc; break;
            case 31: msg_id = 0x187dc; break;
            }
            break;
        case 2:
            switch (({ s32 r_; __asm__("addi %0,%1,-26" : "=r"(r_) : "r"(cur)); r_; })) {
            case 0: msg_id = 0x187eb; break;
            case 1: msg_id = 0x187eb; break;
            case 2: msg_id = 0x187eb; break;
            case 3: msg_id = 0x187eb; break;
            case 4: msg_id = 0x187eb; break;
            case 5: msg_id = 0x187eb; break;
            case 6: msg_id = 0x187eb; break;
            case 7: msg_id = 0x187eb; break;
            }
            break;
        case 3:
            switch (({ s32 r_; __asm__("addi %0,%1,-26" : "=r"(r_) : "r"(cur)); r_; })) {
            case 0: msg_id = 0x187f5; break;
            case 1: msg_id = 0x187f5; break;
            case 2: msg_id = 0x187f5; break;
            case 3: msg_id = 0x187f5; break;
            case 4: msg_id = 0x187f5; break;
            case 5: msg_id = 0x187f5; break;
            case 6: msg_id = 0x187f5; break;
            case 7: msg_id = 0x187f5; break;
            }
            break;
        case 6:
            switch (cur) {
            case 9: msg_id = 0x1881d; break;
            case 10: msg_id = 0x1881e; break;
            case 11: msg_id = 0x1881f; break;
            }
            break;
        case 4:
        case 5:
        case 7:
            break;
        }
        break;
    case 4:
        switch (id % 100) {
        case 0:
            msg_id = 0x18827;
            if (use_memoca_slot == 0) msg_id = 0x188af;
            st = s_memoca_real_time_check_state;
            if (st <= 2 || st == 3) msg_id = 0x18703;
            if (s_DialogUseCounter != 0) msg_id = 0x18703;
            if (st == 12 || st == 10) msg_id = 0x18703;
            break;
        case 1:
            switch (cur) {
            case 0: msg_id = 0x1882a; break;
            case 1: msg_id = 0x1882a; break;
            case 51: msg_id = 0x1882a; break;
            case 52: msg_id = 0x1882a; break;
            case 53: msg_id = 0x1882a; break;
            case 54: msg_id = 0x1882a; break;
            }
            break;
        }
        break;
    case 10:
        switch (id % 100) {
        case 0:
            switch (cur) {
            case 21: msg_id = 0x18827; break;
            case 22: msg_id = 0x18828; break;
            }
            if (use_memoca_slot == 0) msg_id = 0x188af;
            st = s_memoca_real_time_check_state;
            if (st <= 2 || st == 3) msg_id = 0x18703;
            if (s_DialogUseCounter != 0) msg_id = 0x18703;
            if (st == 12 || st == 10) msg_id = 0x18703;
            break;
        }
        break;
    case 5:
        switch (id % 100) {
        case 0:
            msg_id = 0x18827;
            if (use_memoca_slot == 0) msg_id = 0x188af;
            st = s_memoca_real_time_check_state;
            if (st <= 2 || st == 3) msg_id = 0x18703;
            if (s_DialogUseCounter != 0) msg_id = 0x18703;
            if (st == 12 || st == 10) msg_id = 0x18703;
            break;
        case 1:
            switch (cur) {
            case 0: msg_id = 0x18829; break;
            case 1: msg_id = 0x18829; break;
            case 51: msg_id = 0x18829; break;
            case 52: msg_id = 0x18829; break;
            case 53: msg_id = 0x18829; break;
            case 54: msg_id = 0x18829; break;
            }
            break;
        }
        break;
    case 9:
        switch (id % 100) {
        case 0:
            switch (cur) {
            case 6: msg_id = 0x18809; break;
            case 7: msg_id = 0x1880a; break;
            case 8: msg_id = 0x1880b; break;
            case 9: msg_id = 0x1880c; break;
            case 10: msg_id = 0x1880d; break;
            case 11: msg_id = 0x1880e; break;
            case 12: msg_id = 0x1880f; break;
            case 16: msg_id = 0x18811; break;
            case 17: msg_id = 0x18812; break;
            case 18: msg_id = 0x18813; break;
            case 72: msg_id = 0x18810; break;
            }
            break;
        case 1:
            switch (cur) {
            case 80: msg_id = Menu_GetMovementHelpId(); break;
            }
            break;
        }
        break;
    }
    pTmpStr = KnMsgMng_GetMsgStr(msg_id);
    if (pTmpStr != 0) {
        len = 0;
        if (*pTmpStr != 0) {
            scan = pTmpStr;
            do {
                scan++;
                len++;
            } while (*scan != 0);
        }
        memcpy(aTmpHelpStr, pTmpStr, (len << 1) + 2);
    } else {
        sprintf((char *)aTmpHelpStr, "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000");
    }
    *(void **)pVariable = aTmpHelpStr;
}


/* MI_Init_HelpStr @ 0x1DCD90 .. 0x1DCD98 (0x8 bytes) */



void MI_Init_HelpStr(void) {
    return;
}


/* MI_Check_HelpStr @ 0x1DCD80 .. 0x1DCD88 (0x8 bytes) */



void MI_Check_HelpStr(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}






/* MI_Get_BtnGuide @ 0x1DCD70 .. 0x1DCD78 (0x8 bytes) */



void MI_Get_BtnGuide(void) {
    return;
}


/* MI_Set_BtnGuide @ 0x1DCD60 .. 0x1DCD68 (0x8 bytes) */



void MI_Set_BtnGuide(void) {
    return;
}


/* MI_Decide_BtnGuide @ 0x1DCD50 .. 0x1DCD58 (0x8 bytes) */



void MI_Decide_BtnGuide(void) {
    return;
}





/* MI_CntUp_BtnGuide @ 0x1DCD40 .. 0x1DCD48 (0x8 bytes) */



void MI_CntUp_BtnGuide(void) {
    return;
}


/* MI_CntDown_BtnGuide @ 0x1DCD30 .. 0x1DCD38 (0x8 bytes) */



void MI_CntDown_BtnGuide(void) {
    return;
}


/* MI_Gene1_BtnGuide @ 0x1DCD20 .. 0x1DCD28 (0x8 bytes) */



void MI_Gene1_BtnGuide(void) {
    return;
}


/* MI_Gene2_BtnGuide @ 0x1DCD10 .. 0x1DCD18 (0x8 bytes) */




void MI_Gene2_BtnGuide(void) {
    return;
}

void MI_Evrfrm_BtnGuide(void *pVariable, signed int id) {
    s32 a2;
    u32 s2;
    s32 s1;
    u32 s0;
    u32 v1;
    u32 v0_2; // v0
    u32 v0_3; // v0
    u32 s5;
    u32 v0;
    void *a0_2;
    signed int a1_2;
    u8 stackFrame_70[16] __attribute__((aligned(16)));

    v1 = 0x188c6;
    s2 = (u32)(id) + 0x188c6;
    v1 = id - 21;
    s1 = 0;
    s0 = 0;
    switch (({ s32 r_; __asm__("addi %0,%1,-21" : "=r"(r_) : "r"(id)); r_; })) {
    case 0:
    case 1:
    case 2:
        a1_2 = 8;
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_70[0]), a1_2);
        v1 = *(s32 *)((u8 *)&stackFrame_70[0]);
        a0_2 = (void *)book_doc_page;
        v1 = v1 + -1;
        v1 = (u32)(s32)a0_2 < v1;
        if (v1 == 0) {
            s1 = 1;
        }
        if ((u32)(s32)a0_2 != 0) {
            break;
        }
        s0 = 1;
        break;
    case 3:
    case 4:
    case 5:
        v1 = s_get_item_id;
        v0 = 0x3e8;
        s5 = book_doc_page;
        v0 = (s32)v1 % 0x3e8;
        a0_2 = (void *)(u16)v0;
        v0_2 = ItemMng_GetDocumentPageNum((unsigned short)a0_2);
        v1 = (u16)v0_2;
        v1 = v1 + -1;
        v1 = (s32)s5 < (s32)v1;
        if (v1 == 0) {
            s1 = 1;
        }
        if (s5 != 0) {
            break;
        }
        s0 = 1;
    default:
        break;
    }
    v1 = 0x1a;
    a1_2 = 8;
    switch ((u32)id) {
    case 20:
        *(u32 *)pVariable = 0;
        a0_2 = (void *)s_menu_map_now_tex_id;
        v1 = 0x1f4;
        if ((u32)(s32)a0_2 != v1) {
            v1 = 0x1f5;
            if ((u32)(s32)a0_2 != v1) {
                goto _L001DCA58;
            }
        }
        v0_3 = Menu_CheckVisitMap((signed int)a0_2);
        if (v0_3 != 0) {
            *(u32 *)pVariable = id;
        }
        _L001DCA58:;
        return;
    case 5:
        v0 = s_MapTex_SorL;
        if (v0 != 0) {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88d0;
        }
        a0_2 = (void *)s_menu_map_now_tex_id;
        v0 = Menu_CheckVisitMap((signed int)a0_2);
        if (v0 != 0) {
            v1 = s_menu_map_now_tex_id;
            v0 = 0x1f5;
            if (v1 != v0) {
                break;
            }
        }
        v0 = 0x10000;
        s2 = 0x10000 | 0x88e1;
        break;
    case 15:
        v1 = s_menu_map_now_tex_id;
        v0 = 0x1f5;
        if (v1 == v0) {
            break;
        }
        v0 = 0x10000;
        s2 = 0x10000 | 0x88d9;
        break;
    case 14:
        a1_2 = s_get_item_id;
        v0 = 0x68db0000;
        v1 = 0xa;
        a0_2 = (void *)(0x68db0000 | 0x8bad);
        v0 = 2;
        a0_2 = (void *)(s32)((s32)a1_2 / 0x2710);
        a1_2 = (u32)a1_2 >> 0x1f;
        v1 = (s32)a0_2 % 0xa;
        if (v1 != v0) {
            v0 = Menu_GetItemBufOn();
            if (v0 != 0) {
                v0 = 0x10000;
                s2 = 0x10000 | 0x88e2;
                break;
            } else {
                v0 = 0x10000;
                s2 = 0x10000 | 0x88d6;
                break;
            }
        } else {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88d7;
            break;
        }
    case 16:
        v1 = s_get_item_id;
        v0 = 0x3e8;
        s0 = book_doc_page;
        v0 = (s32)v1 % 0x3e8;
        a0_2 = (void *)(u16)v0;
        v0 = (u16)ItemMng_GetDocumentPageNum((unsigned short)a0_2);
        v0 = v0 + -1;
        v0 = (s32)s0 < (s32)v0;
        if (v0 == 0) {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88c4;
            break;
        } else {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88d8;
            break;
        }
    case 8:
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_70[0]), a1_2);
        v0 = *(s32 *)((u8 *)&stackFrame_70[0]);
        v1 = book_doc_page;
        v0 = v0 + -1;
        v0 = v1 < v0;
        if (v0 == 0) {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88c6;
            break;
        } else {
            v0 = 0x10000;
            s2 = 0x10000 | 0x88c5;
            break;
        }
    case 21:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88db;
        if ((u32)s1 == 0) {
            break;
        }
        s2 = v0 | 0x88dd;
        break;
    case 22:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88dc;
        if (s0 == 0) {
            break;
        }
        s2 = v0 | 0x88d9;
        break;
    case 23:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88df;
        break;
    case 24:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88db;
        if ((u32)s1 == 0) {
            break;
        }
        s2 = v0 | 0x88de;
        break;
    case 25:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88dc;
        if (s0 == 0) {
            break;
        }
        s2 = v0 | 0x88d9;
        break;
    case 26:
        v0 = 0x10000;
        s2 = 0x10000 | 0x88e0;
    }
    a0_2 = (void *)s2;
    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
    if (v0 != 0) {
        v1 = *(u16 *)v0;
        a2 = 0;
        if (v1 != 0) {
            a0_2 = (void *)v0;
            do {
                a0_2 = (void *)((u8 *)a0_2 + 2);
                v1 = *(u16 *)a0_2;
                a2 = a2 + 1;
            } while (v1 != 0);
        }
        a0_2 = (void *)aTmpBtnGuide;
        s0 = (s32)(u32)&((struct { u8 b[0x80]; } *)aTmpBtnGuide)[id];
        v1 = (u32)a2 << 1;
        a0_2 = (void *)(s32)s0;
        memcpy(a0_2, (void *)v0, v1 + 2);
    } else {
        v0 = (u32)aTmpBtnGuide;
        s0 = (s32)(u32)&((struct { u8 b[0x80]; } *)aTmpBtnGuide)[id];
        a1_2 = (signed int)"";
        sprintf((char *)(s32)s0, (const char *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000");
    }
    *(u32 *)pVariable = s0;
    return;
}


/* MI_Init_BtnGuide @ 0x1DC8A0 .. 0x1DC8A8 (0x8 bytes) */



void MI_Init_BtnGuide(void) {
    return;
}


/* MI_Check_BtnGuide @ 0x1DC890 .. 0x1DC898 (0x8 bytes) */



void MI_Check_BtnGuide(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* MI_Get_Arrow @ 0x1DC5F0 .. 0x1DC88C (0x29c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x40 escapes at 0x1dc738
 *   delay: lui at 0x1dc790 writes a register its branch at 0x1dc78c reads
 *   stack: address of the slot at 0x30 escapes at 0x1dc7e8
 *   declaration vs inferred signature: return void vs inferred u8 *; 0 parameters vs 2 inferred
 */


void MI_Get_Arrow(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    s32 a1_2; // a1
    u32 v1;
    u32 *a0_2;
    u32 v0;
    u8 stackFrame_40[16] __attribute__((aligned(16)));
    u8 stackFrame_30[16] __attribute__((aligned(16)));

    *(u32 *)a0 = a1;
    v0 = KnMenuMng_CheckCtrlPlay(3, 1);
    a0_2 = (u32 *)(s32)3;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 1);
        if ((u32)a1 == (u32)1 && (u32)equip_offset == 0) {
            *(u32 *)a0 = 0;
        }
        v0 = 2;
        a0_2 = (u32 *)(s32)0x1d;
        if ((u32)a1 == v0) {
            v0 = Menu_ScrlCheck_down((signed int)a0_2);
            if (v0 == 0) {
                *(u32 *)a0 = 0;
            }
        }
    }
    v0 = KnMenuMng_CheckCtrlPlay(3, 2);
    a0_2 = (u32 *)(s32)3;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 2);
        if ((u32)a1 == (u32)1 && (u32)item_offset == 0) {
            *(u32 *)a0 = 0;
        }
        v0 = 2;
        a0_2 = (u32 *)(s32)0x32;
        if ((u32)a1 == v0) {
            v0 = Menu_ScrlCheck_down((signed int)a0_2);
            if (v0 == 0) {
                *(u32 *)a0 = 0;
            }
        }
    }
    a0_2 = (u32 *)(s32)3;
    v0 = KnMenuMng_CheckCtrlPlay((int)a0_2, (s32)a0_2);
    a0_2 = (u32 *)(s32)3;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, (s32)a0_2);
        if ((u32)a1 == (u32)1 && (u32)book_offset == 0) {
            *(u32 *)a0 = 0;
        }
        v0 = 2;
        a0_2 = (u32 *)(s32)0x46;
        if ((u32)a1 == v0) {
            v0 = Menu_ScrlCheck_down((signed int)a0_2);
            if (v0 == 0) {
                *(u32 *)a0 = 0;
            }
        }
    }
    v0 = KnMenuMng_CheckCtrlPlay(3, 7);
    a0_2 = (u32 *)(s32)3;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, (s32)a0_2);
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_40[0]), 8);
        if ((u32)a1 == (u32)1 && (u32)book_doc_page == 0) {
            *(u32 *)a0 = 0;
        }
        if ((u32)a1 == (u32)2 && (u32)book_doc_page >= (u32)(*(s32 *)((u8 *)&stackFrame_40[0]) +
            -1)) {
            *(u32 *)a0 = 0;
        }
        v0 = 3;
        if ((u32)a1 == v0) {
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x93f4);
            a1_2 = v0;
            v0 = book_doc_page;
            a0_2 = aTmpStr_Page;
            FsFontReplaceText((void *)aTmpStr_Page, (void *)a1_2, (u32)(v0 + 1), *(s32 *)((u8
                *)&stackFrame_40[0]));
            v0 = (u32)aTmpStr_Page;
            *(u32 *)a0 = (u32)aTmpStr_Page;
        }
    }
    v0 = KnMenuMng_CheckCtrlPlay(7, 1);
    a0_2 = (u32 *)(s32)7;
    if (v0 != 0) {
        KnMenuMng_GetCursorId((int)a0_2, 1);
        MI_Evrfrm_ItemStr((void *)((u8 *)&stackFrame_30[0]), 8);
        if ((u32)a1 == (u32)1 && (u32)book_doc_page == 0) {
            *(u32 *)a0 = 0;
        }
        if ((u32)a1 == (u32)2 && (u32)book_doc_page >= (u32)(*(s32 *)((u8 *)&stackFrame_30[0]) +
            -1)) {
            *(u32 *)a0 = 0;
        }
        v1 = 3;
        if ((u32)a1 == v1) {
            v0 = 0x40000;
            v0 = (u32)KnMsgMng_GetMsgStr(0x40000 | 0x93f4);
            v1 = book_doc_page;
            a0_2 = aTmpStr_Page;
            FsFontReplaceText((void *)aTmpStr_Page, (void *)v0, (u32)(v1 + 1), *(s32 *)((u8
                *)&stackFrame_30[0]));
            v1 = (u32)aTmpStr_Page;
            *(u32 *)a0 = (u32)aTmpStr_Page;
        }
    }
    return;
}


/* MI_Set_Arrow @ 0x1DC5E0 .. 0x1DC5E8 (0x8 bytes) */



void MI_Set_Arrow(void) {
    return;
}


/* MI_Decide_Arrow @ 0x1DC5D0 .. 0x1DC5D8 (0x8 bytes) */



void MI_Decide_Arrow(void) {
    return;
}





/* MI_CntUp_Arrow @ 0x1DC5C0 .. 0x1DC5C8 (0x8 bytes) */



void MI_CntUp_Arrow(void) {
    return;
}


/* MI_CntDown_Arrow @ 0x1DC5B0 .. 0x1DC5B8 (0x8 bytes) */



void MI_CntDown_Arrow(void) {
    return;
}


/* MI_Gene1_Arrow @ 0x1DC5A0 .. 0x1DC5A8 (0x8 bytes) */



void MI_Gene1_Arrow(void) {
    return;
}


/* MI_Gene2_Arrow @ 0x1DC590 .. 0x1DC598 (0x8 bytes) */



void MI_Gene2_Arrow(void) {
    return;
}


/* MI_Evrfrm_Arrow @ 0x1DC580 .. 0x1DC588 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j MI_Get_Arrow at 0x1dc580 leaves the function
 *   return value dropped, call kept: the function is void
 */


void MI_Evrfrm_Arrow(u32 *a0 /* r4 */, s32 a1 /* r5 */) {
    MI_Get_Arrow(a0, a1);
    return;
}


/* MI_Init_Arrow @ 0x1DC570 .. 0x1DC578 (0x8 bytes) */



void MI_Init_Arrow(void) {
    return;
}


/* MI_Check_Arrow @ 0x1DC560 .. 0x1DC568 (0x8 bytes) */



void MI_Check_Arrow(u32 *a0 /* r4 */) {
    *(u32 *)a0 = 0;
    return;
}


/* Menu_GetMapTexSorL @ 0x1DC550 .. 0x1DC558 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lb at 0x1dc554 computes the return value
 */


s8 Menu_GetMapTexSorL(void) {
    return s_MapTex_SorL;
}


/* Menu_CheckVisitMap @ 0x1DC480 .. 0x1DC54C (0xcc bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1dc49c writes a register its branch at 0x1dc498 reads
 *   delay: addiu at 0x1dc4b0 writes a register its branch at 0x1dc4ac reads
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int Menu_CheckVisitMap(signed int a0 /* r4 */) {
    s32 v1;
    u32 v0;

    v1 = 0x320;
    v0 = 0;
    switch ((u32)(s32)a0) {
    case 0:
        a0 = (s32)0x2eff;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
        break;
    case 200:
        a0 = (s32)0x2f01;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
        break;
    case 500:
        a0 = (s32)0x2f00;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
        break;
    case 501:
        a0 = (s32)0x2f00;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
        break;
    case 700:
        a0 = (s32)0x2f02;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
        break;
    case 800:
        a0 = (s32)0x2f03;
        v0 = ItemMng_GetItemNum_Direct(a0);
        v0 = (u16)v0;
    }
    if ((s32)v0 > 0) {
        v0 = 1;
    }
    return v0;
}
static inline int MGTC_find(int id) {
    int i;
    for (i = 0; i < 6; i++) {
        if (id == ((struct TexCEnt *)s_tex_id_table)[i].id) return i;
    }
    return -1;
}
void Menu_GetTexCenter(int tex_id, float *center) {
    int off;
    int i;
    int idx;
    float dx, dy, x0, a, b, x1, y0, y1, w, h;

    idx = MGTC_find(tex_id);
    {
    float real_pos[4] = {0};
    off = idx * 0xa8;
    *(float *)((u8 *)real_pos + 0) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x1c) + off);
    *(float *)((u8 *)real_pos + 4) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x30) + off);
    *(float *)((u8 *)real_pos + 8) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x2c) + off);
    *(float *)((u8 *)real_pos + 12) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x20) + off);
    {
    float tex_pos[4] = {0};
    *(float *)((u8 *)tex_pos + 0) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x24) + off);
    *(float *)((u8 *)tex_pos + 4) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x38) + off);
    *(float *)((u8 *)tex_pos + 8) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x34) + off);
    *(float *)((u8 *)tex_pos + 12) = (float)*(s32 *)((u8 *)(s_tex_id_table + 0x28) + off);
        if ((tex_pos[2] - tex_pos[0]) != 0.0f) {
            if ((tex_pos[1] - tex_pos[3]) != 0.0f) {
                a = real_pos[2] - real_pos[0];
                x0 = real_pos[2] - a * (tex_pos[2] / (tex_pos[2] - tex_pos[0]));
                x1 = real_pos[0] + a * ((1024.0f - tex_pos[0]) / (tex_pos[2] - tex_pos[0]));
                b = real_pos[1] - real_pos[3];
                y0 = real_pos[1] - b * (tex_pos[1] / (tex_pos[1] - tex_pos[3]));
                y1 = real_pos[3] + b * ((1024.0f - tex_pos[3]) / (tex_pos[1] - tex_pos[3]));
                w = x1 - x0;
                h = y1 - y0;
                center[0] = x0 + w / 2.0f;
                center[1] = y0 + h / 2.0f;
                center[2] = w;
                center[3] = h;
            }
        }
    }
    }
}


/* Menu_GetTexId_now @ 0x1DC230 .. 0x1DC238 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1dc234 computes the return value
 */




u32 Menu_GetTexId_now(void) {
    return s_menu_map_now_tex_id;
}


/* Menu_GetTexInfo @ 0x1DC1D0 .. 0x1DC230 (0x60 bytes) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001DC1E0
 *   cfg: kept branch: 0x1dc210 if (..) goto .L001DC1E0
 */


u32 Menu_GetTexInfo(s32 a0 /* r4 */) {
    u32 a1;
    u32 v1;
    u32 v0;

    a1 = 0;
    v1 = (u32)s_tex_id_table;
    _L001DC1E0:;
    v0 = *(u32 *)v1;
    if (a0 == v0) {
        v1 = (u32)a1 << 3;
        a0 = v1 - a1;
        v0 = (u32)s_tex_id_table;
        v1 = (u32)a0 << 2;
        v1 = v1 - a0;
        v1 = (u32)v1 << 3;
        v0 = (u32)((u8 *)s_tex_id_table + v1);
    } else {
        a1 = a1 + 1;
        v0 = (s32)a1 < (s32)6;
        v1 = v1 + 0xa8;
        if (v0 != 0) {
            goto _L001DC1E0;
        }
        v0 = 0;
    }
    return v0;
}


s32 Menu_GetNowMapTexId(s32 a0) {
    s32 v0 = 0;
    if (0 > a0) v0 = 0;
    if (a0 >= 0x14) v0 = 0xc8;
    if (a0 >= 0x1e) v0 = 0;
    if (a0 >= 0x28) v0 = 0x1f4;
    if (a0 >= 0x46) v0 = 0x2bc;
    if (a0 >= 0x50) v0 = 0x320;
    if (a0 == 0x29) v0 = 0;
    return v0;
}


/* Menu_GetMapData @ 0x1DC150 .. 0x1DC15C (0xc bytes) */


u8 * Menu_GetMapData(void) {
    return (u8 *)s_MapData;
}


/* Menu_MapTexFree @ 0x1DC0E0 .. 0x1DC144 (0x64 bytes, frame 0x30) */


void Menu_MapTexFree(void) {
    s32 s1;
    u8 *s0;
    u32 a0;
    s32 v0;

    s1 = 0;
    s0 = (u8 *)s_tex_id_table;
    do {
        a0 = *(s32 *)(s0 + 0x44);
        FreeTexList((void *)a0);
        a0 = *(s32 *)(s0 + 0x44);
        MemFree((void *)a0);
        *(u32 *)(s0 + 0x44) = 0;
        s1 = s1 + 1;
        *(u32 *)(s0 + 0x40) = 0;
        v0 = s1 < (s32)6;
        s0 = (u8 *)(s0 + 0xa8);
    } while ((u32)v0 != 0);
    Menu_ReLoadFile_MapIconData(0);
    return;
}
static inline s32 TexIdxFind(s32 id) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)s_tex_id_table;
    do {
        if (id == *(s32 *)p) {
            return i;
        }
        i = i + 1;
        p = p + 0xa8;
    } while (i < 6);
    return -1;
}
static inline struct TexIdEnt3 *TexInfoInl(s32 id) {
    s32 i;
    u8 *p;

    i = 0;
    p = (u8 *)s_tex_id_table;
    do {
        if (id == *(s32 *)p) {
            return &((struct TexIdEnt3 *)s_tex_id_table)[i];
        }
        i = i + 1;
        p = p + 0xa8;
    } while (i < 6);
    return 0;
}
static signed int Menu_ReLoadSetTex(int type, int cng_type_) {
    s32 next_tex_id;
    s32 idx;
    struct TexIdEnt3 *e;
    u32 s0;
    s32 i;
    struct TexIdEnt3 *p3;

    s0 = cng_type_;

    next_tex_id = s_menu_map_now_tex_id;
    idx = TexIdxFind(next_tex_id);
    if (idx == -1) {
        next_tex_id = 0;
    } else {
        e = &((struct TexIdEnt3 *)s_tex_id_table)[idx];
        if (e->v[0] == -1) {
            next_tex_id = -1;
        } else {
            switch ((u8)s0) {
            case 0:
                next_tex_id = (s32)(u32)next_tex_id;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                next_tex_id = e->v[(u8)s0];
            default:
                break;
            }
        }
    }
    if (next_tex_id < 0) {
        return 0;
    }
    s_MapTex_SorL = type;
    FlushCache(0);
    do {
    } while ((*(volatile s32 *)0x10009000 & 0x100) != 0 || (*(volatile s32 *)0x1000a000 & 0x100) != 0);
    i = 0;
    p3 = (struct TexIdEnt3 *)s_tex_id_table;
    do {
        FreeTexList((void *)p3->f44);
        MemFree((void *)p3->f44);
        p3->f44 = 0;
        p3->f40 = 0;
        i++;
        p3++;
    } while (i < 6);
    Menu_ReLoadFile_MapIconData(0);
    if ((u8)type == 2) {
        return 1;
    }
    if (Menu_CheckVisitMap(next_tex_id) == 0) {
        s_MapTex_SorL = 1;
        if ((u8)s0 != 6) {
            s_menu_map_now_tex_id = next_tex_id;
        }
        ReadTexList("menu/tex/map/map_nashi.tex", (void **)&TexInfoInl(s_menu_map_now_tex_id)->f44, 6, 0);
        if (FileCheckAsyncBusy() == 1) {
            do {
                FileBackReadControl();
            } while (FileCheckAsyncBusy() == 1);
        }
        s0 = (u32)TexInfoInl(s_menu_map_now_tex_id);
        ((struct TexIdEnt3 *)s0)->f40 = (s32)GetTexMngByBaseName((void *)TexInfoInl(s_menu_map_now_tex_id)->f44, "map_nashi.t32");
    } else {
        ReadTexList(TexInfoInl(next_tex_id)->name48, (void **)&TexInfoInl(next_tex_id)->f44, 6, 0);
        if (FileCheckAsyncBusy() == 1) {
            do {
                FileBackReadControl();
            } while (FileCheckAsyncBusy() == 1);
        }
        s0 = (u32)TexInfoInl(next_tex_id);
        e = TexInfoInl(next_tex_id);
        ((struct TexIdEnt3 *)s0)->f40 = (s32)GetTexMngByBaseName((void *)e->f44, TexInfoInl(next_tex_id)->name88);
        s_menu_map_now_tex_id = next_tex_id;
        Menu_ReLoadFile_MapIconData(1);
    }
    return 1;
}


/* MI_Get_MapTex @ 0x1DBB50 .. 0x1DBB58 (0x8 bytes) */



void MI_Get_MapTex(void) {
    return;
}






/* MI_Set_MapTex @ 0x1DBB40 .. 0x1DBB48 (0x8 bytes) */



void MI_Set_MapTex(void) {
    return;
}


/* MI_Decide_MapTex @ 0x1DBB30 .. 0x1DBB38 (0x8 bytes) */



void MI_Decide_MapTex(void) {
    return;
}


/* MI_CntUp_MapTex @ 0x1DBB20 .. 0x1DBB28 (0x8 bytes) */



void MI_CntUp_MapTex(void) {
    return;
}


/* MI_CntDown_MapTex @ 0x1DBB10 .. 0x1DBB18 (0x8 bytes) */




void MI_CntDown_MapTex(void) {
    return;
}
void MI_Gene1_MapTex(signed int unused, s32 state) {
    switch (state) {
    case 0: break;
    case 1: case 2: case 3: case 4:
        if (s_MapTex_SorL != 1) break;
        if (Menu_ReLoadSetTex(*(s8 *)&s_MapTex_SorL, (u8)state) != 1) break;
        Menu_SetMmCamPos(s_menu_map_now_tex_id, s_menu_map_now_tex_id, 0);
        if (no_snd_on) break;
        if ((s32)no_snd_counter > 0) { no_snd_counter--; break; }
        else SND_Play2D(20, 100, 600);
    }
}


/* MI_Gene2_MapTex @ 0x1DBA40 .. 0x1DBA48 (0x8 bytes) */




void MI_Gene2_MapTex(void) {
    return;
}
static inline signed int MI_Evrfrm_MapTex__inl0(u32 a3) {
    signed int a1_2;
    void *a0_2;
    u32 v1;

    a1_2 = 0;
    a0_2 = (void *)s_tex_id_table;
    do {
        v1 = *(s32 *)a0_2;
        if (a3 == v1) {
            return a1_2;
        }
        goto _L00MT0;
        _L00MT0:;
        a1_2 = (u32)(a1_2) + 1;
        v1 = (s32)a1_2 < (s32)6;
        a0_2 = (void *)((u8 *)a0_2 + 0xa8);
    } while (v1 != 0);
    a1_2 = -1;
    return a1_2;
}
void MI_Evrfrm_MapTex(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 n0;
    u32 p0;
    u32 n1;
    u32 p1;
    u32 *s1;
    struct MapTexEnt *e;
    u32 s0;
    u32 a3;
    u32 a2;
    u64 v0_64;
    u32 s2;
    u32 v1;
    u32 s3;
    u32 v0;
    void *a0_2;
    signed int a1_2;

    s0 = a1;
    s1 = (u32 *)a0;
    switch (s0) {
    case 0:
        v1 = GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_PADPORT_51A19403 / 1)];
        v0 = (u32)&lpPadData;
        a0_2 = (void *)(s32)6;
        v1 = v1 << 2;
        v0 = (s32)((u8 *)&lpPadData + v1);
        s0 = *(s32 *)v0;
        v0 = KnMenuMng_CheckCtrlPlayWait((int)a0_2, 0);
        if (v0 != 0) {
            v0 = Menu_TD_IsPlay();
            if (v0 == 0) {
                v1 = *(u8 *)((s0 + 0x21));
                v0_64 = (u64)v1 << 0x3b >> 0x3f;
                if (v0_64 != 0) {
                    v0 = Menu_CheckMapMove();
                    if (v0 == 0) {
                        v0 = 0x1f5;
                        s2 = s_MapTex_SorL;
                        s0 = 0;
                        v1 = s_menu_map_now_tex_id;
                        if (v1 == v0) {
                            Menu_ReLoadSetTex(1, 5);
                        } else {
                            a0_2 = (void *)(s32)1;
                            a0_2 = (void *)(s2 == 0 ? (enum MI_Evrfrm_MapTex__sel)(s32)a0_2 : (enum
                                MI_Evrfrm_MapTex__sel)(s32)0);
                            Menu_ReLoadSetTex((int)a0_2, 5);
                        }
                        v0 = s_MapTex_SorL;
                        if (s2 != v0) {
                            v0 = no_snd_on;
                            if (v0 == 0) {
                                v0 = no_snd_counter;
                                if ((s32)v0 > 0) {
                                    v0 = v0 + -1;
                                    no_snd_counter = v0;
                                } else {
                                    SND_Play2D(0x15, 0x64, 0x258);
                                }
                            }
                        } else {
                            v0 = no_snd_on;
                            if (v0 == 0) {
                                v0 = no_snd_counter;
                                if ((s32)v0 > 0) {
                                    v0 = v0 + -1;
                                    no_snd_counter = v0;
                                } else {
                                    SND_Play2D(0x16, 0x64, 0x258);
                                }
                            }
                        }
                        v0 = s_MapTex_SorL;
                        if (v0 == 0) {
                            a0_2 = (void
                                *)GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820 / 1)];
                            s2 = s_menu_map_now_tex_id;
                            v0 = Menu_GetNowMapTexId((s32)a0_2);
                            if (v0 == s2) {
                                s0 = 2;
                            }
                        }
                        a0_2 = (void *)s_menu_map_now_tex_id;
                        Menu_SetMmCamPos((signed int)a0_2, (s32)a0_2, s0);
                    }
                } else {
                    v0_64 = (u64)v1 << 0x39 >> 0x3f;
                    if (v0_64 != 0) {
                        v1 = s_MapTex_SorL;
                        if (v1 == 0) {
                            a0_2 = (void
                                *)GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820 / 1)];
                            s0 = s_menu_map_now_tex_id;
                            v0 = Menu_GetNowMapTexId((s32)a0_2);
                            if (v0 == s0) {
                                a1_2 = s_menu_map_now_tex_id;
                                Menu_SetMmCamPos(-1, a1_2, 1);
                            } else {
                                a1_2 = s_menu_map_now_tex_id;
                                Menu_SetMmCamPos(-1, a1_2, 0);
                            }
                        } else {
                            v0 = 1;
                            if (v1 == v0) {
                                a0_2 = (void
                                    *)GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820 /
                                    1)];
                                v0 = Menu_GetNowMapTexId((s32)a0_2);
                                s_menu_map_now_tex_id = (u32)v0;
                                a0_2 = (void *)s_menu_map_now_tex_id;
                                Menu_SetMmCamPos((signed int)a0_2, (s32)a0_2, 0);
                                a0_2 = (void *)(s32)1;
                                Menu_ReLoadSetTex((int)a0_2, 0);
                            }
                        }
                    } else {
                        v0_64 = (u64)v1 << 0x38 >> 0x3f;
                        if (v0_64 != 0) {
                            v0 = Menu_CheckMapMove();
                            if (v0 == 0) {
                                s3 = s_menu_map_now_tex_id;
                                a0_2 = (void *)(s32)1;
                                a1_2 = 6;
                                s0 = 0;
                                Menu_ReLoadSetTex((int)a0_2, a1_2);
                                s2 = s_menu_map_now_tex_id;
                                if (s3 != s2) {
                                    v1 = s_MapTex_SorL;
                                    v0 = 1;
                                    if (v1 == v0) {
                                        if (v1 == 0) {
                                        a0_2 = (void
                                            *)GameSt[(DCOMP_OFF_STRUCT_DW_2299119_FIELDS_SCENENO_5F26D820
                                            / 1)];
                                        v0 = Menu_GetNowMapTexId((s32)a0_2);
                                        if (v0 == s2) {
                                        s0 = 2;
                                        }
                                        }
                                        v0 = no_snd_on;
                                        if (v0 == 0) {
                                        v0 = no_snd_counter;
                                        if ((s32)v0 > 0) {
                                        v0 = v0 + -1;
                                        no_snd_counter = v0;
                                        } else {
                                        SND_Play2D(0x15, 0x64, 0x258);
                                        }
                                        }
                                        a0_2 = (void *)s_menu_map_now_tex_id;
                                        Menu_SetMmCamPos((signed int)a0_2, (s32)a0_2, s0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        a0_2 = (void *)s_menu_map_now_tex_id;
        a1_2 = 0;
        v1 = (u32)s_tex_id_table;
        do {
            v0 = *(s32 *)v1;
            if ((u32)(s32)a0_2 != v0) {
                goto _L001DB778;
            }
            v0 = (u32)&((struct MapTexEnt *)s_tex_id_table)[a1_2];
            goto _L001DB790;
            _L001DB778:;
            a1_2 = (u32)(a1_2) + 1;
            v0 = (s32)a1_2 < (s32)6;
            v1 = v1 + 0xa8;
        } while (v0 != 0);
        v0 = 0;
        _L001DB790:;
        s0 = *(s32 *)((v0 + 0x40));
        v0 = Menu_CheckVisitMap((signed int)a0_2);
        if (v0 == 0 || s0 == 0) {
            *(u32 *)s1 = 0;
            break;
        } else {
            v1 = *(u16 *)((s0 + 2));
            *(u32 *)s1 = v1;
            break;
        }
    case 1:
    case 2:
    case 3:
    case 4:
        *(u32 *)s1 = 0;
        v0 = Menu_CheckMapMove();
        if (v0 != 0 || (u32)s_MapTex_SorL != (u32)1) {
            break;
        }
        a3 = s_menu_map_now_tex_id;
        a1_2 = MI_Evrfrm_MapTex__inl0(a3);
        a2 = -1;
        if ((u32)(s32)a1_2 == a2) {
            a3 = 0;
        } else {
            e = &((struct MapTexEnt *)s_tex_id_table)[a1_2];
            v1 = e->v[0];
            if (v1 == a2) {
                a3 = a2;
            } else {
                v1 = (u8)s0;
                switch (v1) {
                case 0:
                    a3 = (u32)(s32)a3;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    a3 = e->v[v1];
                default:
                    break;
                }
            }
        }
        if ((s32)a3 < 0) {
            break;
        }
        *(u32 *)s1 = s0;
        break;
    case 5:
        s0 = MI_Evrfrm_MapTex__inl0(s_menu_map_now_tex_id);
        v0 = *(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
        n0 = 0;
        if (v0 != 0) {
            p0 = (u32)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
            do {
                p0 = p0 + 2;
                v0 = *(u16 *)p0;
                n0 = n0 + 1;
            } while (v0 != 0);
        }
        v0 = n0 << 1;
        a0_2 = (void *)s_menu_map_name;
        a1_2 = (signed int)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
        memcpy((void *)s_menu_map_name, (void *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000", v0 + 2);
        a2 = -1;
        if (s0 != a2) {
            s0 = s0 * 0xa8;
            v1 = *(s32 *)((u8 *)s_tex_id_table + s0);
            if (v1 != a2) {
                a0_2 = (void *)s_menu_map_now_tex_id;
                v0 = Menu_CheckVisitMap((signed int)a0_2);
                if (v0 != 0) {
                    v0 = (u32)(u8 *)(s_tex_id_table + 0x3c);
                    v0 = v0 + s0;
                    a0_2 = (void *)*(s32 *)v0;
                    v0 = (u32)KnMsgMng_GetMsgStr((signed int)a0_2);
                    a1_2 = v0;
                    if ((u32)a1_2 != 0) {
                        v0 = *(u16 *)a1_2;
                        n1 = 0;
                        if (v0 != 0) {
                            p1 = a1_2;
                            do {
                                p1 = p1 + 2;
                                v0 = *(u16 *)p1;
                                n1 = n1 + 1;
                            } while (v0 != 0);
                        }
                        v0 = n1 << 1;
                        a0_2 = (void *)s_menu_map_name;
                        memcpy((void *)s_menu_map_name, (void *)a1_2, v0 + 2);
                    }
                }
            }
        }
        v1 = (u32)s_menu_map_name;
        *(void **)s1 = (void *)s_menu_map_name;
        break;
    case 6:
    case 7:
        a0_2 = (void *)s_MapTex_SorL;
        *(u32 *)s1 = ((u32)a0_2 == 1) ? 6 : 7;
    default:
        break;
    }
    return;
}


/* MI_Init_MapTex @ 0x1DB430 .. 0x1DB438 (0x8 bytes) */




void MI_Init_MapTex(void) {
    return;
}

static inline signed int MI_Check_MapTex__inl0(u32 a3) {
    signed int a1_2;
    void *a0_2;
    u32 v1;

    a1_2 = 0;
    a0_2 = (void *)s_tex_id_table;
    do {
        v1 = *(s32 *)a0_2;
        if (a3 == v1) {
            return a1_2;
        }
        goto _L001DAF10;
        _L001DAF10:;
        a1_2 = (u32)(a1_2) + 1;
        v1 = (s32)a1_2 < (s32)6;
        a0_2 = (void *)((u8 *)a0_2 + 0xa8);
    } while (v1 != 0);
    a1_2 = -1;
    return a1_2;
}
void MI_Check_MapTex(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u32 a3;
    struct TexIdEnt *e;
    u8 *s0;
    u32 a2;
    signed int a1_2; // a1
    void *a0_2; // a0
    u32 v1;
    u32 v0;

    v1 = 9;
    *(u32 *)a0 = 0;
    switch ((u32)(s32)a1) {
    case 1:
        s0 = (u8 *)((u8 *)a0 + 1);
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f =
            ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f &
            1;
        v0 = Menu_CheckMapMove();
        if (v0 != 0 || (u32)s_MapTex_SorL != (u32)1) {
            break;
        }
        a3 = s_menu_map_now_tex_id;
        a1_2 = MI_Check_MapTex__inl0(a3);
        _L001DAF28:;
        a2 = -1;
        if ((u32)(s32)a1_2 == a2) {
            a3 = 0;
        } else {
            e = &((struct TexIdEnt *)s_tex_id_table)[a1_2];
            v1 = e->v[0];
            if (v1 == a2) {
                a3 = a2;
            } else {
                v1 = (u8)(s32)a1;
                switch (v1) {
                case 0:
                    a3 = (u32)(s32)a3;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    a3 = e->v[v1];
                default:
                    break;
                }
            }
        }
        if ((s32)a3 < 0) {
            break;
        }
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)s0)->f = ((struct {
            unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)s0)->f & 1;
        break;
    case 2:
        s0 = (u8 *)((u8 *)a0 + 1);
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f =
            ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f &
            1;
        v0 = Menu_CheckMapMove();
        if (v0 != 0 || (u32)s_MapTex_SorL != (u32)1) {
            break;
        }
        a3 = s_menu_map_now_tex_id;
        a1_2 = MI_Check_MapTex__inl0(a3);
        _L001DB070:;
        a2 = -1;
        if ((u32)(s32)a1_2 == a2) {
            a3 = 0;
        } else {
            e = &((struct TexIdEnt *)s_tex_id_table)[a1_2];
            v1 = e->v[0];
            if (v1 == a2) {
                a3 = a2;
            } else {
                v1 = (u8)(s32)a1;
                switch (v1) {
                case 0:
                    a3 = (u32)(s32)a3;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    a3 = e->v[v1];
                default:
                    break;
                }
            }
        }
        if ((s32)a3 < 0) {
            break;
        }
        ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)s0)->f = ((struct {
            unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)s0)->f & 1;
        break;
    case 3:
        s0 = (u8 *)((u8 *)a0 + 1);
        ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f =
            ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f &
            1;
        v0 = Menu_CheckMapMove();
        if (v0 != 0 || (u32)s_MapTex_SorL != (u32)1) {
            break;
        }
        a3 = s_menu_map_now_tex_id;
        a1_2 = MI_Check_MapTex__inl0(a3);
        _L001DB1B8:;
        a2 = -1;
        if ((u32)(s32)a1_2 == a2) {
            a3 = 0;
        } else {
            e = &((struct TexIdEnt *)s_tex_id_table)[a1_2];
            v1 = e->v[0];
            if (v1 == a2) {
                a3 = a2;
            } else {
                v1 = (u8)(s32)a1;
                switch (v1) {
                case 0:
                    a3 = (u32)(s32)a3;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    a3 = e->v[v1];
                default:
                    break;
                }
            }
        }
        if ((s32)a3 < 0) {
            break;
        }
        ((struct { unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)s0)->f = ((struct {
            unsigned char _pad:3; unsigned char f:1; } *)&*(u8 *)s0)->f & 1;
        break;
    case 4:
        s0 = (u8 *)((u8 *)a0 + 1);
        ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f =
            ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)(((u8 *)a0 + 1)))->f &
            1;
        v0 = Menu_CheckMapMove();
        if (v0 != 0 || (u32)s_MapTex_SorL != (u32)1) {
            break;
        }
        a3 = s_menu_map_now_tex_id;
        a1_2 = MI_Check_MapTex__inl0(a3);
        _L001DB300:;
        a2 = -1;
        if ((u32)(s32)a1_2 == a2) {
            a3 = 0;
        } else {
            e = &((struct TexIdEnt *)s_tex_id_table)[a1_2];
            v1 = e->v[0];
            if (v1 == a2) {
                a3 = a2;
            } else {
                v1 = (u8)(s32)a1;
                switch (v1) {
                case 0:
                    a3 = (u32)(s32)a3;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    a3 = e->v[v1];
                default:
                    break;
                }
            }
        }
        if ((s32)a3 < 0) {
            break;
        }
        ((struct { unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)s0)->f = ((struct {
            unsigned char _pad:4; unsigned char f:1; } *)&*(u8 *)s0)->f & 1;
        break;
    case 9:
        v1 = s_DialogUseCounter;
        if (v1 == 0) {
            break;
        }
        ((struct { unsigned char f:1; } *)a0)->f = ((struct { unsigned char f:1; } *)a0)->f & 1;
        ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)a0)->f = ((struct {
            unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)a0)->f & 1;
    }
    return;
}
/* unreferenced in the shipped image (mwld dead-strips it); its reference fixes the .rodata order of the pooled empty u16 list */
void MI_DeadStripped_EmptyList(u16 *p) {
    *p = *(u16 *)"\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
}


void MI_Get_MsgDlg(void) {
}


void MI_Set_MsgDlg(void) {
}


void MI_Decide_MsgDlg(void) {
}






void MI_CntUp_MsgDlg(void) {
}


void MI_CntDown_MsgDlg(void) {
}


void MI_Gene1_MsgDlg(void) {
}


void MI_Gene2_MsgDlg(void) {
}


void MI_Evrfrm_MsgDlg(void) {
}


void MI_Init_MsgDlg(void) {
}


void MI_Check_MsgDlg(s32 *item) {
    *item = 0;
}


/* GetMenuFuncId @ 0x1DAD30 .. 0x1DADA8 (0x78 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001DAD58
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int GetMenuFuncId(unsigned char *a0 /* r4 */) {
    u32 s2;
    s32 s1;
    u8 *s0;
    u32 v0;

    s2 = (u32)a0;
    s1 = 0;
    s0 = (u8 *)g_MapFuncTable;
    do {
        v0 = strcmp((u32)s0, s2);
        if (v0 == 0) {
            return s1;
        }
        s1 = s1 + 1;
        v0 = s1 < (s32)0x32;
        s0 = (u8 *)(s0 + 0x48);
    } while (v0 != 0);
    return 0;
}
#pragma inline_intrinsics off
#define KEY_PLAIN(bit) \
        if ((bit) == 0 || s_DialogUseCounter != 0) { goto fail; } \
        if (Menu_TD_IsPlay() != 0) { goto fail; } \
        ret = 1; \
        break;
#define STICK_SET(n) \
    if (s_stick_udlr_old != (n) || (u32)s_stick_cursol_on == 0) { \
        s_stick_udlr = (n); \
        s_stick_cursol_on = 0xa; \
    }
signed int GetKeyState(int key_type) {
    struct PadK *lpPad;
    int v;
    int h;
    int t;
    u32 ret;
    u32 av;
    u32 ah;

    lpPad = (struct PadK *)((u32 *)&lpPadData)[GameSt[0x0a]];
    if (lpPad->y < 0x40 || lpPad->y > 0xc0 || lpPad->x < 0x40 || lpPad->x > 0xc0) {
        v = (u8)lpPad->y - 0x80;
        h = lpPad->x - 0x80;
        t = v;
        av = abs(t);
        t = h;
        ah = abs(t);
        if ((s32)ah < (s32)av) {
            if (v < 0) {
                STICK_SET(1)
            } else {
                STICK_SET(2)
            }
        } else if (h < 0) {
            STICK_SET(3)
        } else {
            STICK_SET(4)
        }
    } else {
        s_stick_udlr = 0;
        s_stick_udlr_old = 0;
    }
    switch ((u8)key_type) {
    case 0: KEY_PLAIN(lpPad->b6)
    case 1: KEY_PLAIN(lpPad->b5)
    case 2: KEY_PLAIN(lpPad->d4)
    case 3: KEY_PLAIN(lpPad->d6)
    case 4: KEY_PLAIN(lpPad->d7)
    case 5: KEY_PLAIN(lpPad->d5)
    case 6: KEY_PLAIN(lpPad->b4)
    case 7: KEY_PLAIN(lpPad->a0)
    case 13:
        if (lpPad->a4 == 0) { goto fail; }
        KEY_PLAIN(lpPad->c2_3)
    case 8:
        if (lpPad->b4 == 0) { goto fail; }
        KEY_PLAIN(lpPad->c2_3)
    case 10: KEY_PLAIN(lpPad->b2)
    case 11:
        if (lpPad->a6 == 0) { goto fail; }
        KEY_PLAIN(lpPad->c2_3)
    case 12:
        if (lpPad->a7 == 0) { goto fail; }
        KEY_PLAIN(lpPad->c2_3)
    case 14:
        if (lpPad->b6 == 0) { goto fail; }
        if (Menu_TD_IsPlay() != 0) { goto fail; }
        ret = 1;
        break;
    case 15:
        if (lpPad->b5 == 0) { goto fail; }
        if (Menu_TD_IsPlay() != 0) { goto fail; }
        ret = 1;
        break;
    case 9:
    default:
fail:
        ret = 0;
    }
    return ret;
}
#pragma inline_intrinsics reset

void Menu_CallMenu(s32 menu_id, s32 ctrl_id) {
    KnMenuMng_CallMenu(ctrl_id, menu_id);
}


void SetCtrlFuncMenuId(s32 menu_id) {
    s_ctrl_func_menu_id = menu_id;
}



void SetCtrlFuncCtrlId(s32 ctrl_id) {
    s_ctrl_func_ctrl_id = ctrl_id;
}

static inline void MenuMdlChange(int bit) {
    KnMenuModelMng_ReMakeMdl(0);
    KnMenuModelMng_ReLoadMdl(bit, 1);
    KnMenuModelMng_ReMakeMdl(bit);
}
#pragma inline_intrinsics off
signed int Memu_CtrlFunc(void *pVariable, signed int _state_id) {
    u8 state_id;

    state_id = _state_id;
    Menu_SetModelState(s_ctrl_func_menu_id, s_ctrl_func_ctrl_id, state_id, pVariable);
    if (state_id == 2) {
        no_snd_on = 1;
    }
    if (state_id == 4) {
        no_snd_on = 0;
    }
    switch (s_ctrl_func_menu_id) {
    case 0:
    case 1:
    case 2:
    case 8:
        break;
    case 7:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                MenuMdlChange(0x100);
            }
            break;
        case 1:
            if (state_id == 1) {
                MenuMdlChange(0x2000);
                book_doc_page = 0;
            }
            break;
        }
        break;
    case 3:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                MenuMdlChange(0x40);
                book_offset = 0;
                stg_str_key = GS->KeyConfType;
                stg_str_vib = GS->PadVib;
                stg_str_bgm = GetVagMasterVolume(0);
                stg_str_se = (u8)SND_GetVol(3);
                stg_str_voice = GetVagMasterVolume(1);
                stg_str_kido = GS->Brightness;
                stg_str_SndMode = (u8)((struct dw_2288913_fields *)g_pSndMng)->SndMode;
                stg_str_lang = GS->VoiceLanguage;
            }
            break;
        case 1:
            if (state_id == 1) {
                MenuMdlChange(0x80);
                equip_offset = 0;
                if (CheckEventFlag(0x388) == 0) {
                    Menu_TD_CallOrder(0x1d52c, 0x388, 0);
                }
            }
            if (state_id == 0xb) {
                ChangeMyEquipSound();
            }
            break;
        case 2:
            if (state_id == 1) {
                MenuMdlChange(0x100);
                item_offset = 0;
                if (CheckEventFlag(0x389) == 0) {
                    Menu_TD_CallOrder(0x1d514, 0x389, 0);
                }
            }
            break;
        case 3:
            if (state_id == 1) {
                MenuMdlChange(0x200);
                if (CheckEventFlag(0x38a) == 0) {
                    Menu_TD_CallOrder(0x1d517, 0x38a, 0);
                }
            }
            break;
        case 6:
            if (state_id == 1) {
                MenuMdlChange(0x1000);
                s_memoca_real_time_check_state = 3;
                s_go_ttl_state = 0;
                memset(MemocaMng, 0, 9);
                MCM->checking_port_ok = 0;
                MCM->state[0] = 2;
                MCM->state[1] = 2;
            }
            break;
        case 7:
            if (state_id == 1) {
                MenuMdlChange(0x2000);
                book_doc_page = 0;
            }
            break;
        }
        break;
    case 6:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                s_MapTex_SorL = 0;
                s_menu_map_now_tex_id = Menu_GetNowMapTexId(GS->sceneNo);
                Menu_SetMmCamPos(s_menu_map_now_tex_id, s_menu_map_now_tex_id, 2);
                Menu_ReLoadSetTex(0, 0);
                MenuMdlChange(0x400);
                Menu_ReLoadFile_MapIconData(1);
                if (CheckEventFlag(0x38b) == 0) {
                    Menu_TD_CallOrder(0x1d51a, 0x38b, 0);
                }
            }
            if (state_id == 0xb) {
                Menu_ReLoadSetTex(2, 0);
                Menu_ReLoadFile_MapIconData(0);
            }
            break;
        }
        break;
    case 5:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                int next_id;
                MenuMdlChange(0x1000);
                next_id = 0x15;
                if (s_load_slot == state_id) goto Lslot1;
                next_id = 0x15;
                Lslot1:
                if (s_load_slot == 1) next_id = 0x16;
                KnMenuMng_SetForceChangeCursorId(5, 0, next_id);
                s_memoca_real_time_check_state = 3;
                menu_load_ok = 0;
            }
            if (state_id == 0xb) {
                s_memoca_real_time_check_state = 3;
            }
            break;
        case 1:
            if (state_id == 1) {
                int memoca_offset;
                MenuMdlChange(0x1000);
                memoca_offset = s_load_offset;
                if (s_load_slot != MCM->checking_port) {
                    memoca_offset = 0;
                }
                memoca_index_offset = memoca_offset;
                if (memoca_offset > 4) {
                    memoca_index_offset = 4;
                }
                KnMenuMng_SetForceChangeCursorId(5, 1, memoca_offset + 0x33 - memoca_index_offset);
                s_memoca_decide_state = 0;
            }
            if (state_id == 0xb) {
                memoca_index_offset = 0;
            }
            break;
        }
        break;
    case 4:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                int next_id;
                MenuMdlChange(0x1000);
                next_id = 0x15;
                if (s_load_slot == state_id) goto Lslot2;
                next_id = 0x15;
                Lslot2:
                if (s_load_slot == 1) next_id = 0x16;
                KnMenuMng_SetForceChangeCursorId(4, 0, next_id);
            }
            if (state_id == 0xb) {
                s_memoca_real_time_check_state = 3;
            }
            break;
        case 1:
            if (state_id == 1) {
                int memoca_offset;
                MenuMdlChange(0x1000);
                memoca_offset = s_load_offset;
                if (s_load_slot != MCM->checking_port) {
                    memoca_offset = 0;
                }
                memoca_index_offset = memoca_offset;
                if (memoca_offset > 4) {
                    memoca_index_offset = 4;
                }
                KnMenuMng_SetForceChangeCursorId(4, 1, memoca_offset + 0x33 - memoca_index_offset);
                s_memoca_real_time_check_state = 3;
                s_memoca_decide_state = 0;
            }
            if (state_id == 0xb) {
                memoca_index_offset = 0;
            }
            break;
        }
        break;
    case 10:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                int next_id;
                MenuMdlChange(0x1000);
                next_id = 0x15;
                if (s_load_slot == state_id) goto Lslot3;
                next_id = 0x15;
                Lslot3:
                if (s_load_slot == 1) next_id = 0x16;
                KnMenuMng_SetForceChangeCursorId(0xa, 0, next_id);
                s_memoca_real_time_check_state = 3;
            }
            if (state_id == 0xb) {
                s_memoca_real_time_check_state = 3;
            }
            break;
        }
        break;
    case 9:
        switch (s_ctrl_func_ctrl_id) {
        case 0:
            if (state_id == 1) {
                MenuMdlChange(0x800);
            }
            if (state_id == 0xb) {
                if (*(u16 *)&s_last_reload_type != 0x8000) {
                    ChangeLanguageSound();
                    if (FileCheckAsyncBusy() == 1) {
                        do {
                            FileBackReadControl();
                        } while (FileCheckAsyncBusy() == 1);
                    }
                    RestartMapSe();
                }
            }
            break;
        case 1:
            if (state_id == 1) {
                MenuMdlChange(0x800);
                KnMenuModelMng_ResetCtrlerAnim();
            }
            break;
        }
        break;
    }
    return 1;
}
#pragma inline_intrinsics reset



/* MenuReadFile @ 0x1D9EC0 .. 0x1D9F74 (0xb4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001D9EF8
 *   cfg: kept branch: 0x1d9f10 if (..) goto .L001D9F50
 *   cfg: kept branch: 0x1d9f40 if (..) goto .L001D9EF8
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuReadFile(unsigned char **a0 /* r4 */, char *a1 /* r5 */) {
    u32 *s0;
    u32 s3;
    s32 s2;
    u32 *s1;
    u32 v0;
    u32 v1;

    s0 = (u32 *)a0;
    a0 = (unsigned char **)*(s32 *)a0;
    s3 = (u32)a1;
    MemFree((void *)a0);
    *(u32 *)s0 = 0;
    s2 = 0;
    s1 = s_MenuFileList;
    _L001D9EF8:;
    a1 = (char *)*(s32 *)s1;
    a0 = (unsigned char **)s3;
    v0 = strcmp((u32)a0, (s32)a1);
    if (v0 == 0) {
        v1 = (u32)s2 << 2;
        v0 = (u32)s_MenuFileBuf;
        v1 = (s32)((u8 *)s_MenuFileBuf + v1);
        v0 = *(s32 *)v1;
        *(u32 *)s0 = v0;
        v0 = *(s32 *)s0;
        if (v0 == 0) {
            goto _L001D9F50;
        }
        *(u32 *)v1 = 0;
        v0 = 1;
    } else {
        s2 = s2 + 1;
        v0 = s2 < (s32)0x28;
        s1 = (u32 *)(s32)((u8 *)s1 + 4);
        if (v0 != 0) {
            goto _L001D9EF8;
        }
        _L001D9F50:;
        v0 = 0;
    }
    return v0;
}


/* Menu_FileReadCallBack @ 0x1D9D70 .. 0x1D9EB4 (0x144 bytes, frame 0x60) */
/*
 * dcomp notes:
 *   delay: ori at 0x1d9db8 writes a register its branch at 0x1d9db4 reads
 *   delay: andi at 0x1d9e24 writes a register its branch at 0x1d9e20 reads
 *   cfg: loop body is not one contiguous region: .L001D9DF0
 */


u32 Menu_FileReadCallBack(u16 a0 /* r4 */) {
    u32 a0_word = a0;
    u32 v1;
    u32 v0;
    s32 s4;
    s32 s3;
    u8 *s2;
    u32 *s1;
    u32 *s0;
    u32 a1;

    v1 = (u16)a0_word;
    v0 = 0x8000;
    s4 = 0;
    if (v1 == v0) {
        s4 = 1;
    }
    v0 = 0x4000;
    if (v1 == v0) {
        s4 = 2;
    }
    v0 = 0x4000;
    switch (v1) {
    case 32768:
    case 16384:
        s3 = 0;
        s2 = (u8 *)s_FileType;
        s1 = s_MenuFileBuf;
        s0 = s_MenuFileList;
        do {
            v0 = *(u8 *)s2;
            v0 = v0 & 0x80;
            if (v0 != 0) {
                a0_word = *(s32 *)s1;
                FreeTexList((void *)a0_word);
            }
            v0 = *(s32 *)s1;
            if (v0 != 0) {
                *(u32 *)s1 = 0;
            }
            v1 = *(u8 *)s2;
            v0 = v1 & s4;
            if (v0 != 0) {
                v0 = v1 & 0x80;
                if (v0 != 0) {
                    a1 = *(s32 *)s0;
                    a0_word = s_MenuFileBndBuf;
                    v0 = GetBindOffsetByName((void *)a0_word, (char *)a1);
                    *(u32 *)s1 = v0;
                    a0_word = *(s32 *)s1;
                    RemapMdlLink((void *)a0_word);
                    a0_word = *(s32 *)s1;
                    a1 = 1;
                    SetTexList((void *)a0_word, a1);
                } else if (v0 == 0) {
                    a1 = *(s32 *)s0;
                    a0_word = s_MenuFileBndBuf;
                    v0 = GetBindOffsetByName((void *)a0_word, (char *)a1);
                    *(u32 *)s1 = v0;
                }
            }
            s3 = s3 + 1;
            v0 = s3 < (s32)0x28;
            s2 = (u8 *)(s2 + 1);
            s1 = (u32 *)((u8 *)s1 + 4);
            s0 = (u32 *)((u8 *)s0 + 4);
        } while (v0 != 0);
    }
    v0 = 1;
    return v0;
}



s16 Menu_GetLastReloadType(void) {
    return s_last_reload_type;
}

/* MenuReLoadFile @ 0x1D9C40 .. 0x1D9D54 (0x114 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @6074 is the string 'menu\\m_title.bnd'
 *   literal: @6075 is the string 'menu\\m_game.bnd'
 *   delay: ori at 0x1d9c78 writes a register its branch at 0x1d9c74 reads
 *   cfg: loop body is not one contiguous region: .L001D9D08
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuReLoadFile(int _type) {
    s32 i;

    s_last_reload_type = _type;
    MemFree((void *)s_MenuFileBndBuf);
    s_MenuFileBndBuf = 0;
    switch ((u16)_type) {
    case 32768:
        FileRead("menu\\m_title.bnd", -1, (unsigned char **)&s_MenuFileBndBuf, 0, -1, 0x10, 0);
        break;
    case 16384:
        FileRead("menu\\m_game.bnd", -1, (unsigned char **)&s_MenuFileBndBuf, 0, -1, 0x10, 0);
        break;
    case 0:
        for (i = 0; i < 0x28; i++) {
            if (s_FileType[i] & 0x80) {
                FreeTexList((void *)s_MenuFileBuf[i]);
            }
            s_MenuFileBuf[i] = 0;
        }
    }
    return 1;
}


/* Menu_DialogUpdate @ 0x1D9B20 .. 0x1D9C3C (0x11c bytes, frame 0x10) */



void Menu_DialogUpdate(void) {
    u32 v1;
    u32 a0;
    u32 v0;
    s32 a1;

    v1 = s_DialogUseCounter;
    if ((s32)v1 > (s32)1) {
        s_DialogUseCounter = v1 + -1;
    }
    a0 = s_DialogUseCounter;
    v1 = 1;
    if (a0 == v1 && (u32)s_no_pad_check == 0) {
        v0 = GetKeyState(0xe);
        if (v0 != 0) {
            a0 = s_now_dialog_id;
            a1 = 1;
            v1 = (u32)&s_aDialogResult;
            s_DialogUseCounter = 0;
            s_dialog_state = a1;
            *(u8 *)(u32)(s32)((u8 *)&s_aDialogResult + a0) = a1;
            v1 = no_snd_on;
            if (v1 == 0) {
                v1 = no_snd_counter;
                if ((s32)v1 > 0) {
                    no_snd_counter = v1 + -1;
                } else {
                    SND_Play2D(0x11, 0x64, 0);
                }
            }
        } else {
            v0 = GetKeyState(0xf);
            if (v0 != 0) {
                a0 = s_now_dialog_id;
                s_dialog_state = 1;
                v1 = (u32)&s_aDialogResult;
                s_DialogUseCounter = 0;
                *(u8 *)(u32)(s32)((u8 *)&s_aDialogResult + a0) = 2;
                v1 = no_snd_on;
                if (v1 == 0) {
                    v1 = no_snd_counter;
                    if ((s32)v1 > 0) {
                        no_snd_counter = v1 + -1;
                    } else {
                        SND_Play2D(0x13, 0x64, 0);
                    }
                }
            }
        }
    }
    return;
}

void Menu_DialogDraw(void) {
    u8 alpha;

    alpha = 127.0f * ((float)(10 - s_DialogUseCounter) / 9.0f);
    if (s_nokoribi > 0 || s_DialogUseCounter > 0) {
        MDD_SPD Sp_black;
        int col[4] = {0, 0, 0, 0x60};

        SetSprite(&Sp_black, -0x100, -0xe0, 0x200, 0x1c0, col, 0, 0);
        MakeAndKickSpritePacket(&Sp_black);
        if (s_DialogUseCounter == 0) {
            if (s_nokoribi > 0) {
                s_nokoribi--;
            }
        }
    }
    if (s_DialogUseCounter > 0) {
        s_nokoribi = 2;
        FontDrawBegin(0);
        FsFontSetScale(0.6666667f, 0.8333333f);
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

            col[3] = alpha;
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
            FsFontSetScale(0.8f, 1.0f);
            color.r = 0;
            color.g = 0;
            color.b = 0;
            color.a = alpha;
            SetFontColor(*(s32 *)&color);
            FsFontSetAlignment(0xa0);
            x = 22.0f;
            y = 26.0f;
            w = 624.0f;
            h = 428.0f;
            FontPrintInRect(x, y, w, h, (char *)s_aDialogMsg);
            color.r = 0x7f;
            color.g = 0x7f;
            color.b = 0x7f;
            color.a = alpha;
            SetFontColor(*(s32 *)&color);
            x -= 2.0f;
            y -= 2.0f;
            w -= 2.0f;
            h -= 2.0f;
            FontPrintInRect(x, y, w, h, (char *)s_aDialogMsg);
            FsFontSetAlignment(0x100);
            FontDrawEnd();
        }
    }
}


/* Menu_SetDialogMsg @ 0x1D9680 .. 0x1D9768 (0xe8 bytes, frame 0x430) */


void Menu_SetDialogMsg(int id, unsigned char *pMsgStr, signed int arg, int type) {
    int len;
    u8 buf[1008] __attribute__((aligned(16)));

    s_now_dialog_id = (u8)id;
    if (pMsgStr == 0) {
        s_DialogUseCounter = 0;
    } else if (s_DialogUseCounter == 0) {
        for (len = 0; ((u16 *)pMsgStr)[len] != 0; len++) {
        }
        memcpy(buf, pMsgStr, (len << 1) + 2);
        FsFontReplaceText(s_aDialogMsg, buf, arg);
        s_DialogUseCounter = 0xa;
        ((u8 *)&s_aDialogResult)[(u8)id] = 0;
        s_no_pad_check = 0;
        if ((u8)type & 1) {
            s_no_pad_check = 1;
        }
    }
}


void Menu_UtilUpdate(void) {
    if (s_stick_cursol_on > 0) {
        s_stick_cursol_on = s_stick_cursol_on - 1;
    }
    if (s_stick_udlr != 0) {
        s_stick_udlr_old = s_stick_udlr;
    }
    s_stick_udlr = 0;
}


void Menu_SetNoSndOff(s32 on) {
    no_snd_on = on;
}


s32 Menu_GetNoSndOff(void) {
    return no_snd_on;
}


/* Menu_SND_Play2D @ 0x1D95C0 .. 0x1D9624 (0x64 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1d95f0 -> .L001D9610
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int Menu_SND_Play2D(signed int a0 /* r4 */, signed short a1 /* r5 */, signed short a2 /* r6
        */) {
    u32 v0;

    v0 = -1;
    if ((u32)(s32)a0 == v0) {
        v0 = 0;
    } else {
        v0 = no_snd_on;
        if (v0 == 0) {
            v0 = no_snd_counter;
            if ((s32)v0 > 0) {
                v0 = v0 + -1;
                no_snd_counter = v0;
                goto _L001D9610;
            } else {
                v0 = SND_Play2D(a0, a1, a2);
            }
        } else {
            _L001D9610:;
            v0 = 0;
        }
    }
    return v0;
}

void Menu_SetMenuBreakKeyType(u8 type) {
    s_menu_break_key_type = type;
}


/* Menu_GetMenuBreakKeyType @ 0x1D95A0 .. 0x1D95A8 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lb at 0x1d95a4 computes the return value
 *   declaration vs inferred signature: return s32 vs inferred s8
 */





s32 Menu_GetMenuBreakKeyType(void) {
    return *(s8 *)&s_menu_break_key_type;
}
