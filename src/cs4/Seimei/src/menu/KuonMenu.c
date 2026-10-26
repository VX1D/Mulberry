#include "common.h"

/* KnMenuMng_GetPlayMenu @ 0x1D6660 .. 0x1D66C8 (0x68 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1d66a8 writes a register its branch at 0x1d66a4 reads
 */

extern u16 s_KnMenuMng[];

/* KnMenuMng_GetPlayMenu_All @ 0x1D66D0 .. 0x1D6760 (0x90 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1d6720 writes a register its branch at 0x1d671c reads
 *   delay: daddu at 0x1d6754 writes a register its branch at 0x1d6750 reads
 *   cfg: loop body is not one contiguous region: .L001D66E8
 */

extern u16 s_KnMenuMng[];
static u32 KnMenuMng_CallMenu_(s32 a0 , u32 a1 );

/* KnMenuMng_CallBackCallMenu @ 0x1D6760 .. 0x1D679C (0x3c bytes, frame 0x10) */

static u32 KnMenuMng_CallMenu_(s32, u32);
extern u16 s_KnMenuMng[];
extern u8 GameSt[];

/* KnMenuMng_GetDrawPos @ 0x1D67A0 .. 0x1D6800 (0x60 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void * MenuMng_GetDrawPos(void *, signed int, signed int);
extern u16 s_KnMenuMng[];

/* KnMenuMng_CallSave @ 0x1D6800 .. 0x1D68A4 (0xa4 bytes, frame 0x10) */

extern signed int SetVagStmFade(unsigned char, unsigned char, signed int);
static u32 KnMenuMng_CallMenu_(s32, u32);
extern u8 GameSt[];

/* KnMenuMng_SetForceChangeCursorId @ 0x1D68B0 .. 0x1D6920 (0x70 bytes, frame 0x40) */

extern void MenuCtrlMng_SetForceChangeCursorId(void *, signed int);

/* KnMenuMng_CheckCtrlPlayWait @ 0x1D6980 .. 0x1D69F0 (0x70 bytes, frame 0x30) */

extern signed int MngState_UpdateExeCheck(void *);
extern signed int MenuMng_CheckCtrlPlayWait(void *, signed int);

/* KnMenuMng_CheckCtrlPlay @ 0x1D69F0 .. 0x1D6A60 (0x70 bytes, frame 0x30) */


extern signed int MenuMng_CheckCtrlPlay(void *, signed int);

/* KnMenuMng_GetCursorId @ 0x1D6A60 .. 0x1D6AD0 (0x70 bytes, frame 0x30) */


extern signed int MenuMng_GetCursorId(void *, signed int);

/* dcomp: the 16-byte ambient template @1050 is one writable object shared
 * by KnMenuMng_CallMenu_ and KnMenuMng_Init; a local initializer in each
 * function would emit a second, differently placed copy. */
struct dcomp_amb { u8 b[16]; };
static struct dcomp_amb dcomp_amb_data __attribute__((aligned(16))) = {{
    0xcd, 0xcc, 0xcc, 0x3d, 0xcd, 0xcc, 0xcc, 0x3d,
    0xcd, 0xcc, 0xcc, 0x3d, 0x00, 0x00, 0x80, 0x3f}};

/* KnMenuMng_CallMenu_ @ 0x1D6AD0 .. 0x1D6CC8 (0x1f8 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1050 -> 0x248ad0
 *   delay: lui at 0x1d6ba8 writes a register its branch at 0x1d6ba4 reads
 *   stack: address of the slot at 0x40 escapes at 0x1d6c68
 *   literal: @1050 initializes the 16-byte local at 0x40
 */

extern void Menu_SetEndSave(signed int);
extern signed int MenuMng_GetTexId(void *);
extern signed int MenuMng_PlayMenu(void *, void *);
extern void Menu_SetUnLoaded(void);
extern void Menu_SetUnSaved(void);
extern u32 GetCameraPos(void);
extern void fsvu0_CopyVectorF(float *, float *);
extern u32 GetCameraAng(void);
extern void fspad_PadSetRepeat(signed int, signed int, unsigned short, unsigned short, unsigned
    short);
extern void GetAmbientColor(void *);
extern void SetAmbientColor(float *);
extern void Menu_SettingStore(void);
extern void Menu_ClearMemocaMng(void);
extern void PadVibAllClear(void);
extern void PadUpdate(void);
extern u8 *lpDrawMng;

/* KnMenuMng_ReMakeMenu @ 0x1D6D80 .. 0x1D7680 (0x900 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1417 is the string 'menu'
 *   cfg: kept branch: 0x1d6dfc if (..) goto .L001D6E30
 *   cfg: kept branch: 0x1d6ec4 if (..) goto .L001D6EF8
 *   cfg: kept branch: 0x1d6f8c if (..) goto .L001D6FC0
 *   cfg: kept branch: 0x1d7054 if (..) goto .L001D7088
 *   cfg: kept branch: 0x1d711c if (..) goto .L001D7150
 *   cfg: kept branch: 0x1d71e4 if (..) goto .L001D7218
 *   cfg: kept branch: 0x1d72ac if (..) goto .L001D72E0
 *   cfg: kept branch: 0x1d738c if (..) goto .L001D73C0
 *   cfg: kept branch: 0x1d7454 if (..) goto .L001D7488
 *   cfg: kept branch: 0x1d751c if (..) goto .L001D7550
 *   cfg: loop body is not one contiguous region: .L001D75B8
 *   cfg: kept branch: 0x1d75f0 if (..) goto .L001D7630
 */

extern signed int MenuMng_Delete(void *);
extern void MemFree(void *);
extern void * _MemAlloc(unsigned int);
extern signed int MenuMng_Initialize(void *);
extern signed int MenuMng_Init(void *, signed int, unsigned char *);
extern void KnMenuModelMng_ReMakeMdl();
extern void Menu_MapTexFree(void);
extern signed int KnMenuModelMng_ReLoadMdl(int, signed int);
extern u32 MenuReLoadFile();

/* KnMenuMng_ReMakeMenu @ 0x1D6D80 .. 0x1D7680 (0x900 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @1417 is the string 'menu'
 *   cfg: kept branch: 0x1d6dfc if (..) goto .L001D6E30
 *   cfg: kept branch: 0x1d6ec4 if (..) goto .L001D6EF8
 *   cfg: kept branch: 0x1d6f8c if (..) goto .L001D6FC0
 *   cfg: kept branch: 0x1d7054 if (..) goto .L001D7088
 *   cfg: kept branch: 0x1d711c if (..) goto .L001D7150
 *   cfg: kept branch: 0x1d71e4 if (..) goto .L001D7218
 *   cfg: kept branch: 0x1d72ac if (..) goto .L001D72E0
 *   cfg: kept branch: 0x1d738c if (..) goto .L001D73C0
 *   cfg: kept branch: 0x1d7454 if (..) goto .L001D7488
 *   cfg: kept branch: 0x1d751c if (..) goto .L001D7550
 *   cfg: loop body is not one contiguous region: .L001D75B8
 *   cfg: kept branch: 0x1d75f0 if (..) goto .L001D7630
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

static inline void KnMenuMng_ReMakeMenu__inl0(void) {
    u8 *a2;
    u32 v1;
    u32 v0;
    u32 a0_2;

    v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
    v1 = 1;
    if (v0 == v1) {
        v1 = *(s32 *)(s_KnMenuMng + 0x12);
        if (v1 > (u32)5) {
            v0 = *(s32 *)(s_KnMenuMng + 0x10);
            a0_2 = *(s32 *)((v0 + 0x14));
            if (a0_2 != 0 && v1 > (u32)5) {
                if (a0_2 != 0) {
                    v0 = MenuMng_Delete((void *)a0_2);
                    if (v0 == 0) {
                        goto _L001D6FC0;
                    }
                }
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x14));
                MemFree((void *)a0_2);
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v0 + 0x14)) = 0;
            }
            _L001D6FC0:;
            a0_2 = 0x90;
            v0 = (u32)_MemAlloc(a0_2);
            v1 = *(s32 *)(s_KnMenuMng + 0x10);
            *(u32 *)((v1 + 0x14)) = v0;
            if (v0 != 0) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x14));
                MenuMng_Initialize((void *)a0_2);
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x14));
                a2 = (u8 *)"menu";
                MenuMng_Init((void *)a0_2, 5, (unsigned char *)"menu");
            }
        }
    }
}

static inline void KnMenuMng_ReMakeMenu__inl1(void) {
    u8 *a2;
    u32 v1;
    u32 v0;
    u32 a0_2;

    v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
    v1 = 1;
    if (v0 == v1) {
        v1 = *(s32 *)(s_KnMenuMng + 0x12);
        if (v1 > (u32)9) {
            v0 = *(s32 *)(s_KnMenuMng + 0x10);
            a0_2 = *(s32 *)((v0 + 0x24));
            if (a0_2 != 0 && v1 > (u32)9) {
                if (a0_2 != 0) {
                    v0 = MenuMng_Delete((void *)a0_2);
                    if (v0 == 0) {
                        goto _L001D72E0;
                    }
                }
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x24));
                MemFree((void *)a0_2);
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v0 + 0x24)) = 0;
            }
            _L001D72E0:;
            a0_2 = 0x90;
            v0 = (u32)_MemAlloc(a0_2);
            v1 = *(s32 *)(s_KnMenuMng + 0x10);
            *(u32 *)((v1 + 0x24)) = v0;
            if (v0 != 0) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x24));
                MenuMng_Initialize((void *)a0_2);
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x24));
                a2 = (u8 *)"menu";
                MenuMng_Init((void *)a0_2, 9, (unsigned char *)"menu");
            }
        }
    }
}

/* KnMenuMng_ReLoadMenu @ 0x1D7680 .. 0x1D76B4 (0x34 bytes, frame 0x20) */

extern signed int KnMenuModelMng_ReLoadMdl(int, signed int);
extern u32 MenuReLoadFile();

/* KnMenuMng_Draw @ 0x1D76C0 .. 0x1D7774 (0xb4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001D7720
 *   declaration vs inferred signature: return int vs inferred u32
 */

extern signed int MngState_DrawExeCheck(void *);
extern signed int KnMenuModelMng_Draw(void);
extern signed int MenuMng_Draw(void *);
extern void Menu_DialogDraw(void);
extern u8 GameSt[];

static s32 s_now_play_menu_id;
u32 s_get_item_end;
u32 s_get_item_start;
static u32 s_save_load_reset_off;
/* KnMenuMng_Update @ 0x1D7780 .. 0x1D7FF8 (0x878 bytes, frame 0x80) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d77ec writes a register its branch at 0x1d77e8 reads
 *   stack: address of the slot at 0x60 escapes at 0x1d789c
 *   stack: address of the slot at 0x60 escapes at 0x1d78d4
 *   delay: addiu at 0x1d78ec writes a register its branch at 0x1d78e8 reads
 *   delay: lui at 0x1d793c writes a register its branch at 0x1d7938 reads
 *   delay: daddu at 0x1d7a74 writes a register its branch at 0x1d7a70 reads
 *   stack: address of the slot at 0x50 escapes at 0x1d7b24
 *   stack: address of the slot at 0x50 escapes at 0x1d7b5c
 *   delay: addiu at 0x1d7b74 writes a register its branch at 0x1d7b70 reads
 *   delay: daddu at 0x1d7be4 writes a register its branch at 0x1d7be0 reads
 *   stack: address of the slot at 0x40 escapes at 0x1d7c94
 *   stack: address of the slot at 0x40 escapes at 0x1d7ccc
 *   delay: addiu at 0x1d7ce4 writes a register its branch at 0x1d7ce0 reads
 *   stack: address of the slot at 0x70 escapes at 0x1d7f9c
 *   stack: address of the slot at 0x70 escapes at 0x1d7fd0
 *   cfg: kept branch: 0x1d77c4 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d77d4 if (..) goto .L001D79A0
 *   cfg: kept goto: 0x1d791c -> .L001D7FE0
 *   cfg: kept branch: 0x1d79a0 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79a4 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79b8 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79c8 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79d8 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79e8 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d79f8 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d7a08 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d7a18 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d7a44 if (..) goto .L001D7D30
 *   cfg: kept branch: 0x1d7a58 if (..) goto .L001D7BC8
 *   cfg: kept goto: 0x1d7ba4 -> .L001D7FE0
 *   cfg: kept goto: 0x1d7ba8 -> .L001D7D30
 *   cfg: kept branch: 0x1d7bc8 if (..) goto .L001D7D30
 *   cfg: kept goto: 0x1d7d14 -> .L001D7FE0
 *   cfg: loop body is not one contiguous region: .L001D7D88
 *   cfg: kept branch: 0x1d7dd0 if (..) goto .L001D7DE0
 */

extern void SetFadeMng(unsigned char, signed int *, signed int, void *, void *, signed int, signed
    int);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern void Menu_SetGetItemId(signed int);
extern void Menu_SetGetItemNum(signed int);
extern signed int TmpMenuMng_CheckDraw(void *);
extern signed int CheckNowFade(signed int);
extern u32 CheckMyMenuOpenDisable();
extern u32 CheckRiddleMode();
extern u32 GetDramaReadFlag();
extern u32 GetCamCtrlMode();
extern signed int GetKeyState(int);
extern void Menu_SetMenuBreakKeyType(int);
extern void Menu_SetDialogMsg(int, unsigned char *, signed int, int);
extern void SetCtrlFuncMenuId(signed int);
extern signed int MenuMng_Update(void *);
extern void KnMenuWindMng_Update();
extern void KnMenuModelMng_Update();
extern void Menu_DialogUpdate();
extern void Menu_UtilUpdate();
extern u32 Menu_IsSaved();
extern u32 SetSaveDrama();
extern void SetSaveBoat();
extern u32 Menu_IsLoaded();
extern u32 GetSaveData();
extern void SetSceneLoad(unsigned short, unsigned short);
extern void SetCameraPos(float *);
extern void SetCameraAng(float *);
extern void SetCameraFov(float);
extern void DrawCalcView();
extern void SetPadDefaultRepeat();
extern void SetPointLightOff(signed int);
extern u32 s_get_item_buf[];
extern u32 g_TmpMenuMng[];





struct dw_2230837_fields;
#ifndef PROTO_DW_2234905_FIELDS
#define PROTO_DW_2234905_FIELDS
struct dw_2234905_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_2241005_FIELDS
#define PROTO_DW_2241005_FIELDS
struct dw_2241005_fields { float cam_pos[4]; float cam_ang[4]; float cam_fov; int game_mode_store; int pad_analog_mode; int dmy[1]; float anb_col[4]; float AmbRate; unsigned char _pad0[12]; };
#endif
#ifndef PROTO_DW_2240255_FIELDS
#define PROTO_DW_2240255_FIELDS
struct dw_2240255_fields { struct dw_2234905_fields mng_state; struct dw_2230837_fields **pMenuMngList; unsigned int menu_num; short call_mode; short now_call_mode; int call_timer; struct dw_2241005_fields store_data; };
#endif
#ifndef PROTO_DW_2244977_FIELDS
#define PROTO_DW_2244977_FIELDS
struct dw_2244977_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_MODE_C09F8ED3_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_MODE_C09F8ED3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_MODE_C09F8ED3 = (int)&(((struct dw_2240255_fields *)0)->call_mode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_TIMER_8E027B23_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_TIMER_8E027B23_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_TIMER_8E027B23 = (int)&(((struct dw_2240255_fields *)0)->call_timer) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_NOW_CALL_MODE_9D526D14_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_NOW_CALL_MODE_9D526D14_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_NOW_CALL_MODE_9D526D14 = (int)&(((struct dw_2240255_fields *)0)->now_call_mode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_PMENUMNGLIST_F67FD93A_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_PMENUMNGLIST_F67FD93A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_PMENUMNGLIST_F67FD93A = (int)&(((struct dw_2240255_fields *)0)->pMenuMngList) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_AMBRATE_B8EFB3B4_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_AMBRATE_B8EFB3B4_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_AMBRATE_B8EFB3B4 = (int)&(((struct dw_2240255_fields *)0)->store_data.AmbRate) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_CAM_FOV_85494B22_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_CAM_FOV_85494B22_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_CAM_FOV_85494B22 = (int)&(((struct dw_2240255_fields *)0)->store_data.cam_fov) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_GAME_MODE_STORE_92A8567D_DEFINED
#define DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_GAME_MODE_STORE_92A8567D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_GAME_MODE_STORE_92A8567D = (int)&(((struct dw_2240255_fields *)0)->store_data.game_mode_store) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2244977_FIELDS_AMBRATE_5141DA65_DEFINED
#define DCOMP_OFF_STRUCT_DW_2244977_FIELDS_AMBRATE_5141DA65_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2244977_FIELDS_AMBRATE_5141DA65 = (int)&(((struct dw_2244977_fields *)0)->AmbRate) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F_DEFINED
#define DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F = (int)&(((struct dw_2244977_fields *)0)->GameMode) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2244977_FIELDS_LOADSTART_48EDEF96_DEFINED
#define DCOMP_OFF_STRUCT_DW_2244977_FIELDS_LOADSTART_48EDEF96_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2244977_FIELDS_LOADSTART_48EDEF96 = (int)&(((struct dw_2244977_fields *)0)->LoadStart) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_2244977_FIELDS_PAUSE_9419B8A2_DEFINED
#define DCOMP_OFF_STRUCT_DW_2244977_FIELDS_PAUSE_9419B8A2_DEFINED
enum { DCOMP_OFF_STRUCT_DW_2244977_FIELDS_PAUSE_9419B8A2 = (int)&(((struct dw_2244977_fields *)0)->Pause) - 0 };
#endif
#define KN_CALL_MODE s_KnMenuMng[(DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_MODE_C09F8ED3 / 2)]
#define KN_NOW_MODE s_KnMenuMng[(DCOMP_OFF_STRUCT_DW_2240255_FIELDS_NOW_CALL_MODE_9D526D14 / 2)]
#define KN_TIMER (*(u32 *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_CALL_TIMER_8E027B23 / 2)))
static void KnMenuMng_CallBackCallMenu(void);

static inline s32 KnCallStart(u32 mode) {
    s32 t;

    if (KN_CALL_MODE != 0x3e7) {
        return 0;
    }
    KN_CALL_MODE = mode;
    KN_NOW_MODE = mode;
    KN_TIMER = 0xa;
    t = KN_TIMER;
    if (t <= 1) {
        t = 2;
    }
    SetVagStmFade(0, 3, t - 1);
    SetVagStmFade(1, 3, t - 1);
    SetVagStmFade(2, 3, t - 1);
    SetVagStmFade(3, 3, t - 1);
    SetVagStmFade(4, 3, t - 1);
    SetVagStmFade(5, 3, t - 1);
    {
        u8 buf[16] __attribute__((aligned(16))) = {0};
        SetFadeMng(9, (signed int *)buf, t, (void *)0, KnMenuMng_CallBackCallMenu, 0, 0);
    }
    if (KN_NOW_MODE != 5 && (u32)(KN_NOW_MODE - 9) > 1) {
        GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_PAUSE_9419B8A2 / 1)] = 2;
    }
    return 1;
}


/* Menu_ItemDataRingBuf @ 0x1D8000 .. 0x1D808C (0x8c bytes, frame 0x10) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d8014 writes a register its branch at 0x1d8010 reads
 */

extern void Menu_SetGetItemId(signed int);
extern void Menu_SetGetItemNum(signed int);
extern u32 s_get_item_start;
extern u32 s_get_item_end;
extern u32 s_get_item_buf[];

/* Menu_GetItemBufOn @ 0x1D8090 .. 0x1D80A4 (0x14 bytes) */
/*
 * dcomp notes:
 *   return: sltu at 0x1d80a0 computes the return value
 */

extern u32 s_get_item_start;
extern u32 s_get_item_end;

/* KnMenuMng_CallGetItemMenu @ 0x1D80B0 .. 0x1D810C (0x5c bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern u32 s_get_item_buf[];

/* KnMenuMng_Init @ 0x1D8110 .. 0x1D83D4 (0x2c4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1050 -> 0x248ad0
 *   stack: address of the slot at 0x30 escapes at 0x1d8200
 *   literal: @1050 initializes the 16-byte local at 0x30
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_Init(void *);
extern void KnMenuModelMng_Init();
extern void KnMenuWindMng_Init();
extern void KnMenuWindMng_Delete();
extern void KnMenuModelMng_Delete();
extern u32 L1050[];

/* KnMenuMng_Initialize @ 0x1D8440 .. 0x1D846C (0x2c bytes) */

extern u16 s_KnMenuMng[];

/* KnMenu_CheckSaveLoadSoftResetOff @ 0x1D8470 .. 0x1D8478 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: lw at 0x1d8474 computes the return value
 */

extern u32 s_save_load_reset_off;
static u16 s_KnMenuMng[0x40];
u32 s_get_item_buf[0x14];
static s32 s_now_play_menu_id = -0x1;
u32 s_get_item_end;
u32 s_get_item_start;
static u32 s_save_load_reset_off;

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u32 KnMenu_CheckSaveLoadSoftResetOff(void);
u32 KnMenuMng_Initialize(void);
int KnMenuMng_Crean(void);
signed int KnMenuMng_Init(unsigned int a0 );
signed int KnMenuMng_CallGetItemMenu(unsigned short a0 , signed int a1 );
u32 Menu_GetItemBufOn(void);
signed int Menu_ItemDataRingBuf(void);
signed int KnMenuMng_Update(signed int a0 );
int KnMenuMng_Draw(void);
u32 KnMenuMng_ReLoadMenu(s32 a0 );
signed int KnMenuMng_ReMakeMenu(u16 a0 );
void KnMenuMng_CallMenu(u32 ctrl_id, s32 menu_id);
static u32 KnMenuMng_CallMenu_(s32 a0 , u32 a1 );
signed int KnMenuMng_GetCursorId(u16 a0 , s32 a1 );
signed int KnMenuMng_CheckCtrlPlay(u16 a0 , s32 a1 );
signed int KnMenuMng_CheckCtrlPlayWait(u16 a0 , s32 a1 );
float KnMenuMng_GetCtrlCalA(u16 a0 , s32 a1 );
void KnMenuMng_SetForceChangeCursorId(u16 a0 , s32 a1 , s32 a2 );
signed int KnMenuMng_CallSave(void);
u8 * KnMenuMng_GetDrawPos(u16 a0 , s32 a1 , s32 a2 );
static void KnMenuMng_CallBackCallMenu(void);
signed int KnMenuMng_GetPlayMenu_All(void);
signed int KnMenuMng_GetPlayMenu(u16 a0 );
u32 KnMenuMng_MenuIdCtrlIdCheck(void);


u32 KnMenu_CheckSaveLoadSoftResetOff(void) {
    return s_save_load_reset_off;
}

u32 KnMenuMng_Initialize(void) {
    u32 v0;

    *(u32 *)((u8 *)&s_KnMenuMng + 0x20) = 0;
    v0 = 1;
    *(u32 *)((u8 *)&s_KnMenuMng + 0x2c) = 0;
    *(u16 *)((u8 *)&s_KnMenuMng + 0x28) = 0x3e7;
    *(u16 *)((u8 *)&s_KnMenuMng + 0x2a) = 0x3e7;
    return v0;
}


/* KnMenuMng_Crean @ 0x1D83E0 .. 0x1D8440 (0x60 bytes) */
/*
 * dcomp notes:
 *   return: addiu at 0x1d843c computes the return value
 *   cfg: loop body is not one contiguous region: .L001D8408
 *   declaration vs inferred signature: return int vs inferred u32
 */

int KnMenuMng_Crean(void) {
    u32 v0;
    s32 a1;
    s32 a0;
    s32 v1;

    v0 = 0x3e7;
    ((u32 *)s_KnMenuMng)[0xb] = 0;
    a1 = 0;
    a0 = 0;
    *(u16 *)(s_KnMenuMng + 0x14) = v0;
    *(u16 *)((u8 *)&s_KnMenuMng + 0x2a) = v0;
    v1 = -1;
    do {
        v0 = *(s32 *)(s_KnMenuMng + 0x10);
        v0 = v0 + a0;
        v0 = *(s32 *)v0;
        if (v0 != 0) {
            *(u32 *)((v0 + 0x70)) = v1;
        }
        a1 = a1 + 1;
        v0 = a1 < (s32)0xc;
        a0 = a0 + 4;
    } while (v0 != 0);
    return 1;
}

signed int KnMenuMng_Init(unsigned int a0 /* r4 */) {
    s32 s0;
    u32 v1;
    u32 v0;
    s32 s1;
    unsigned int a0_2;
    u32 i;
    u32 k;
    s32 j;
    s32 ok;

    s0 = a0;
    a0_2 = (unsigned int)s_KnMenuMng;
    MngState_Init((void *)s_KnMenuMng);
    *(u32 *)(s_KnMenuMng + 0x12) = s0;
    v0 = (u32)L1050;
    {
        struct dcomp_amb
            stackFrame_30 __attribute__((aligned(16))) = dcomp_amb_data;
        v1 = (u32)((u8 *)&stackFrame_30);
        v0 = GameSt[5];
        *(u32 *)(s_KnMenuMng + 0x2a) = v0;
        v0 = GetCameraPos();
        fsvu0_CopyVectorF((float *)(u8 *)(s_KnMenuMng + 0x18), (float *)v0);
        v0 = GetCameraAng();
        fsvu0_CopyVectorF((float *)(u8 *)(s_KnMenuMng + 0x20), (float *)v0);
        v0 = (u32)lpDrawMng;
        s0 = 0;
        *(f32 *)(s_KnMenuMng + 0x28) = *(float *)((v0 + 0x41c));
        do {
            fspad_PadSetRepeat(s0, 0, 0xf000, 0x2d, (unsigned
    short)0xa);
            fspad_PadSetRepeat(s0, 0, 0xf0, 0x1e, (unsigned
    short)6);
            fspad_PadSetRepeat(s0, 0, 0xf00, 0x1e, (unsigned
    short)6);
            s0 = s0 + 1;
            v0 = s0 < (s32)2;
        } while (v0 != 0);
        GetAmbientColor((void *)(u8 *)(s_KnMenuMng + 0x30));
        SetAmbientColor((float *)((u8 *)&stackFrame_30));
        *(f32 *)(s_KnMenuMng + 0x38) = *(float *)(GameSt + 0x24);
        Menu_SettingStore();
        Menu_ClearMemocaMng();
        PadVibAllClear();
        PadUpdate();
        KnMenuModelMng_Init();
        KnMenuWindMng_Init();
        if (*(void ***)(s_KnMenuMng + 0x10) != 0) {
            for (i = 0; i < *(u32 *)(s_KnMenuMng + 0x12); i++) {
                MenuMng_Delete((*(void ***)(s_KnMenuMng + 0x10))[i]);
            }
        }
        MemFree(*(void **)(s_KnMenuMng + 0x10));
        *(void **)(s_KnMenuMng + 0x10) = 0;
        if ((*(void **)(s_KnMenuMng + 0x10) = _MemAlloc(*(u32 *)(s_KnMenuMng + 0x12) << 2)) == 0) {
            ok = 0;
        } else {
            for (j = 0; j < *(u32 *)(s_KnMenuMng + 0x12); j++) {
                (*(void ***)(s_KnMenuMng + 0x10))[j] = 0;
            }
            ok = 1;
        }
        if (ok != 1) {
            if (*(void ***)(s_KnMenuMng + 0x10) != 0) {
                for (k = 0; k < *(u32 *)(s_KnMenuMng + 0x12); k++) {
                        MenuMng_Delete((*(void ***)(s_KnMenuMng + 0x10))[k]);
                }
            }
            MemFree(*(void **)(s_KnMenuMng + 0x10));
            *(void **)(s_KnMenuMng + 0x10) = 0;
            KnMenuWindMng_Delete();
            KnMenuModelMng_Delete();
            Menu_MapTexFree();
            *(u32 *)s_KnMenuMng = 0;
            return 0;
        }
        *(u32 *)s_KnMenuMng = 2;
        return 1;
    }
}

signed int KnMenuMng_CallGetItemMenu(unsigned short a0 /* r4 */, signed int a1 /* r5 */) {
    u32 t0;
    u32 *a2;
    s32 v1;
    u32 a0_2;

    t0 = s_get_item_end;
    a2 = s_get_item_buf;
    a0_2 = (u32)(u8 *)(s_get_item_buf + 1);
    v1 = 0xa;
    t0 = (u32)t0 << 3;
    *(u32 *)(u32 *)((u8 *)s_get_item_buf + t0) = (u16)a0;
    *(u32 *)(u32)(a0_2 + t0) = a1;
    a0_2 = s_get_item_end;
    s_get_item_end = (u32)a0_2 + 1;
    a0_2 = s_get_item_end;
    s_get_item_end = (s32)a0_2 % (s32)(0xa);
    return 1;
}

u32 Menu_GetItemBufOn(void) {
    u32 v1;
    u32 v0;

    v1 = s_get_item_start;
    v0 = s_get_item_end;
    return (u32)(v1 ^ v0) != 0;
}

signed int Menu_ItemDataRingBuf(void) {
    u32 a0;
    u32 v1;
    u32 v0;

    v1 = s_get_item_start;
    v0 = s_get_item_end;
    if (v1 == v0) {
        return 0;
    }
    v0 = (u32)s_get_item_buf;
    a0 = *(s32 *)(u32)(s32)((u8 *)s_get_item_buf + (u32)(v1 << 3));
    Menu_SetGetItemId(a0);
    v1 = s_get_item_start;
    v0 = (u32)(u8 *)(s_get_item_buf + 1);
    a0 = *(s32 *)(u32)(v0 + (u32)((u32)v1 << 3));
    Menu_SetGetItemNum(a0);
    a0 = s_get_item_start;
    v1 = 0xa;
    s_get_item_start = (u32)a0 + 1;
    a0 = s_get_item_start;
    s_get_item_start = (s32)a0 % (s32)(0xa);
    return 1;
}

signed int KnMenuMng_Update(signed int a0 /* r4 */) {
    s32 i;
    u32 handled;
    u32 saved;
    u32 hit;

    if (MngState_UpdateExeCheck((void *)s_KnMenuMng) != 1) {
        return 0;
    }
    handled = 0;
    if (a0 != 0 && KN_NOW_MODE == 0x3e7) {
        if (s_get_item_start != s_get_item_end) {
            if (!KnCallStart(7)) {
                return 0;
            }
            SND_Play2D(9, 0x64, 0);
            if (s_get_item_start != s_get_item_end) {
                Menu_SetGetItemId(s_get_item_buf[s_get_item_start * 2]);
                Menu_SetGetItemNum(s_get_item_buf[s_get_item_start * 2 + 1]);
                s_get_item_start = s_get_item_start + 1;
                s_get_item_start = (s32)(*(volatile u32 *)&s_get_item_start) % 10;
            }
            handled = 1;
        }
        if (handled == 0 && !(TmpMenuMng_CheckDraw((void *)g_TmpMenuMng) != 0 || CheckNowFade(3) != 0 || CheckNowFade(6) != 0 || CheckNowFade(8) != 0 || CheckNowFade(0xa) != 0 || CheckMyMenuOpenDisable() != 0 || CheckRiddleMode() != 0 || GetDramaReadFlag() != 0 || GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F / 1)] != 0 || GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_PAUSE_9419B8A2 / 1)] != 0 || GetCamCtrlMode() == 2)) {
            if (GetKeyState(7) != 0) {
                if (!KnCallStart(3)) {
                    return 0;
                }
                Menu_SetMenuBreakKeyType(7);
                SND_Play2D(0x12, 0x64, 0);
            } else if (GetKeyState(0xa) != 0) {
                if (!KnCallStart(6)) {
                    return 0;
                }
                Menu_SetMenuBreakKeyType(0xa);
                SND_Play2D(0x12, 0x64, 0);
            }
        }
    }
    s_save_load_reset_off = 0;
    if (GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F / 1)] != 2) {
        Menu_SetDialogMsg(0, (unsigned char *)0, 0, 0);
        if (KN_CALL_MODE == 0x3e7) {
            KN_NOW_MODE = 0x3e7;
        }
    } else {
        hit = 0;
        for (i = 0; i < 0xc; i++) {
            SetCtrlFuncMenuId(i);
            s_now_play_menu_id = i;
            if (((u32 *)*(u32 *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_PMENUMNGLIST_F67FD93A / 2)))[i] != 0) {
                if (MenuMng_Update((void *)((u32 *)*(u32 *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_PMENUMNGLIST_F67FD93A / 2)))[i]) == 1) {
                    if ((u32)(i - 4) <= 1 || i == 4) {
                        s_save_load_reset_off = 1;
                    }
                    hit = 1;
                    *(u32 *)(GameSt + (DCOMP_OFF_STRUCT_DW_2244977_FIELDS_AMBRATE_5141DA65 / 1)) = 0x3f800000;
                }
            }
        }
        s_now_play_menu_id = -1;
        if (GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F / 1)] == 2) {
            KnMenuWindMng_Update();
            KnMenuModelMng_Update();
        }
        Menu_DialogUpdate();
        Menu_UtilUpdate();
        saved = 0;
        if (hit == 0) {
            if (Menu_IsSaved() != 0) {
                saved = SetSaveDrama();
                if (saved == 0) {
                    SetSaveBoat();
                }
            }
            if (Menu_IsLoaded() != 0) {
                u8 *sd = (u8 *)GetSaveData();
                GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_LOADSTART_48EDEF96 / 1)] = 1;
                SetSceneLoad(sd[0x10], sd[0x11]);
            }
            KnMenuModelMng_ReMakeMdl(0x4000);
            KnMenuModelMng_ReLoadMdl(0x4000, 1);
            GameSt[(DCOMP_OFF_STRUCT_DW_2244977_FIELDS_GAMEMODE_C839727F / 1)] = *(u32 *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_GAME_MODE_STORE_92A8567D / 2));
            SetCameraPos((float *)(s_KnMenuMng + 0x18));
            SetCameraAng((float *)(s_KnMenuMng + 0x20));
            SetCameraFov(*(float *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_CAM_FOV_85494B22 / 2)));
            DrawCalcView();
            SetPadDefaultRepeat();
            SetAmbientColor((float *)(s_KnMenuMng + 0x30));
            SetPointLightOff(0);
            *(f32 *)(GameSt + (DCOMP_OFF_STRUCT_DW_2244977_FIELDS_AMBRATE_5141DA65 / 1)) = *(float *)(s_KnMenuMng + (DCOMP_OFF_STRUCT_DW_2240255_FIELDS_STORE_DATA_AMBRATE_B8EFB3B4 / 2));
            Menu_SetMenuBreakKeyType(0x10);
            SetVagStmFade(0, 2, 0xa);
            SetVagStmFade(1, 2, 0xa);
            SetVagStmFade(2, 2, 0xa);
            SetVagStmFade(3, 2, 0xa);
            SetVagStmFade(4, 2, 0xa);
            SetVagStmFade(5, 2, 0xa);
            if (saved == 0) {
                u8 vec[16] __attribute__((aligned(16))) = {0};
                SetFadeMng(0xb, (signed int *)vec, 0xa, (void *)0, (void *)0, 0, 0);
            }
        }
    }
    return 1;
}

int KnMenuMng_Draw(void) {
    u32 a0;
    u32 v1;
    u32 v0;
    s32 s1;
    s32 s0;

    a0 = (u32)s_KnMenuMng;
    v0 = MngState_DrawExeCheck((void *)s_KnMenuMng);
    v1 = 1;
    if (v0 != v1) {
        v0 = v1;
    } else {
        v1 = GameSt[5];
        v0 = 2;
        if (v1 == v0) {
            if (v1 == v0) {
                KnMenuModelMng_Draw();
            }
            s1 = 0;
            s0 = 0;
            do {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0 = *(s32 *)(u32)(v0 + s0);
                if (a0 != 0) {
                    MenuMng_Draw((void *)a0);
                }
                s1 = s1 + 1;
                s0 = s0 + 4;
            } while (s1 < (s32)0xc);
            Menu_DialogDraw();
        }
        v0 = 1;
    }
    return v0;
}

/* KnMenuMng_ReLoadMenu @ 0x1D7680 .. 0x1D76B4 (0x34 bytes, frame 0x20) */
/* KnMenuMng_ReLoadMenu @ 0x1D7680 .. 0x1D76B4 (0x34 bytes, frame 0x20) */
u32 KnMenuMng_ReLoadMenu(s32 a0 /* r4 */) {
    s32 s0;

    s0 = a0;
    KnMenuModelMng_ReLoadMdl(a0, 0);
    MenuReLoadFile(s0);
    return 1;
}
signed int KnMenuMng_ReMakeMenu(u16 a0 /* r4 */) {
    u8 *a2;
    u32 v1;
    u32 v0;
    u32 s0;
    u32 s1;
    u32 a0_2;

    v1 = a0;
    v0 = 0x65;
    switch (v1) {
    case 102:
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)3) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0xc));
                if (a0_2 != 0 && v1 > (u32)3) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D6E30;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0xc));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0xc)) = 0;
                }
                _L001D6E30:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0xc)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0xc));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0xc));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 3, (unsigned char *)"menu");
                }
            }
        }
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)4) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x10));
                if (a0_2 != 0 && v1 > (u32)4) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D6EF8;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x10));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0x10)) = 0;
                }
                _L001D6EF8:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0x10)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x10));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x10));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 4, (unsigned char *)"menu");
                }
            }
        }
        a0_2 = (u32)s_KnMenuMng;
        KnMenuMng_ReMakeMenu__inl0();
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)6) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x18));
                if (a0_2 != 0 && v1 > (u32)6) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D7088;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x18));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0x18)) = 0;
                }
                _L001D7088:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0x18)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x18));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x18));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 6, (unsigned char *)"menu");
                }
            }
        }
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)7) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x1c));
                if (a0_2 != 0 && v1 > (u32)7) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D7150;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x1c));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0x1c)) = 0;
                }
                _L001D7150:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0x1c)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x1c));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x1c));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 7, (unsigned char *)"menu");
                }
            }
        }
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)8) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x20));
                if (a0_2 != 0 && v1 > (u32)8) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D7218;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x20));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0x20)) = 0;
                }
                _L001D7218:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0x20)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x20));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x20));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 8, (unsigned char *)"menu");
                }
            }
        }
        a0_2 = (u32)s_KnMenuMng;
        KnMenuMng_ReMakeMenu__inl1();
        a0_2 = 0x4000;
        KnMenuModelMng_ReMakeMdl(a0_2);
        Menu_MapTexFree();
        break;
    case 101:
        a0_2 = (u32)s_KnMenuMng;
        KnMenuMng_ReMakeMenu__inl0();
        a0_2 = (u32)s_KnMenuMng;
        KnMenuMng_ReMakeMenu__inl1();
        a0_2 = (u32)s_KnMenuMng;
        v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
        v1 = 1;
        if (v0 == v1) {
            v1 = *(s32 *)(s_KnMenuMng + 0x12);
            if (v1 > (u32)0xa) {
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                a0_2 = *(s32 *)((v0 + 0x28));
                if (a0_2 != 0 && v1 > (u32)0xa) {
                    if (a0_2 != 0) {
                        v0 = MenuMng_Delete((void *)a0_2);
                        if (v0 == 0) {
                            goto _L001D7550;
                        }
                    }
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x28));
                    MemFree((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    *(u32 *)((v0 + 0x28)) = 0;
                }
                _L001D7550:;
                a0_2 = 0x90;
                v0 = (u32)_MemAlloc(a0_2);
                v1 = *(s32 *)(s_KnMenuMng + 0x10);
                *(u32 *)((v1 + 0x28)) = v0;
                if (v0 != 0) {
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x28));
                    MenuMng_Initialize((void *)a0_2);
                    v0 = *(s32 *)(s_KnMenuMng + 0x10);
                    a0_2 = *(s32 *)((v0 + 0x28));
                    a2 = (u8 *)"menu";
                    MenuMng_Init((void *)a0_2, 0xa, (unsigned char *)"menu");
                }
            }
        }
        KnMenuModelMng_ReMakeMdl(0x8000);
        Menu_MapTexFree();
        break;
    default:
        s0 = 0;
        do {
            s1 = (u16)s0;
            if ((s32)s1 >= 0 && (u32)*(s32 *)(s_KnMenuMng + 0x12) > s1) {
                v1 = s1 << 2;
                a0_2 = *(s32 *)(u8 *)((u8 *)(u8 *)*(s32 *)(s_KnMenuMng + 0x10) + v1);
                if (a0_2 != 0) {
                    v0 = MenuMng_Delete((void *)a0_2);
                    if (v0 == 0) {
                        goto _L001D7630;
                    }
                }
                v0 = (u16)s1;
                s1 = v0 << 2;
                a0_2 = *(s32 *)(u8 *)((u8 *)(u8 *)*(s32 *)(s_KnMenuMng + 0x10) + s1);
                MemFree((void *)a0_2);
                v0 = *(s32 *)(s_KnMenuMng + 0x10);
                v0 = v0 + s1;
                *(u32 *)v0 = 0;
            }
            _L001D7630:;
            s0 = s0 + 1;
            v0 = (s32)s0 < (s32)0xc;
            a0_2 = 0;
        } while (v0 != 0);
        KnMenuModelMng_ReMakeMdl(0);
        KnMenuModelMng_ReLoadMdl(0, 0);
        MenuReLoadFile(0);
        Menu_MapTexFree();
    }
    v0 = 1;
    return v0;
}

/* KnMenuMng_CallMenu @ 0x1D6CD0 .. 0x1D6D78 (0xa8 bytes, frame 0x30) */

void KnMenuMng_CallMenu(u32 ctrl_id, s32 menu_id) {
    u32 s1;
    s32 s0;
    u32 a0_2; // a0

    s1 = ctrl_id;
    s0 = menu_id;
    SetVagStmFade(0, 3, 1);
    a0_2 = 1;
    SetVagStmFade(a0_2, 3, a0_2);
    SetVagStmFade(2, 3, 1);
    a0_2 = 3;
    SetVagStmFade(a0_2, a0_2, 1);
    SetVagStmFade(4, 3, 1);
    SetVagStmFade(5, 3, 1);
    if ((u32)s0 != 0) {
        s_KnMenuMng[0x15] = s1;
    }
    KnMenuMng_CallMenu_(s1, s0);
    return;
}

static u32 KnMenuMng_CallMenu_(s32 a0 /* r4 */, u32 a1 /* r5 */) {
    u32 s1;
    s32 s0;
    u32 s2;
    u8 *v1;
    u32 v0;
    s32 a0_2;

    s2 = (u16)a0;
    s1 = a0;
    s0 = a1;
    if (s2 == (u32)0xa) {
        Menu_SetEndSave(1);
    } else {
        Menu_SetEndSave(0);
    }
    if ((s32)s2 < 0 || s2 >= (u32)*(s32 *)(s_KnMenuMng + 0x12)) {
        v0 = 0;
    } else {
        v0 = (u16)s1;
        s1 = v0 << 2;
        v0 = *(s32 *)(s_KnMenuMng + 0x10);
        a0_2 = *(s32 *)(u32)(v0 + s1);
        v0 = MenuMng_GetTexId((void *)a0_2);
        if (v0 == 0) {
            v0 = 0;
        } else {
            v0 = *(s32 *)(s_KnMenuMng + 0x10);
            a0_2 = *(s32 *)(u32)(v0 + s1);
            v0 = MenuMng_PlayMenu((void *)a0_2, (void *)(u32)s0);
            if (v0 == 0) {
                v0 = 0;
            } else {
                Menu_SetUnLoaded();
                Menu_SetUnSaved();
                v0 = 2;
                a0_2 = GameSt[5];
                if ((u32)a0_2 != v0) {
                    v0 = 0x248ad0;
                    {
                        struct dcomp_amb stackFrame_40
                            __attribute__((aligned(16))) = dcomp_amb_data;
                        v1 = ((u8 *)&stackFrame_40);
                        *(u32 *)(s_KnMenuMng + 0x2a) = a0_2;
                        v0 = GetCameraPos();
                        fsvu0_CopyVectorF((float *)(u8 *)(s_KnMenuMng + 0x18), (float *)v0);
                        v0 = GetCameraAng();
                        fsvu0_CopyVectorF((float *)(u8 *)(s_KnMenuMng + 0x20), (float *)v0);
                        v0 = ((u32)lpDrawMng);
                        s0 = 0;
                        *(f32 *)(s_KnMenuMng + 0x28) = *(float *)((v0 + 0x41c));
                        do {
                            fspad_PadSetRepeat(s0, 0, 0xf000, 0x2d, 0xa);
                            fspad_PadSetRepeat(s0, 0, 0xf0, 0x1e, 6);
                            fspad_PadSetRepeat(s0, 0, 0xf00, 0x1e, 6);
                            s0 = s0 + 1;
                            v0 = s0 < (s32)2;
                        } while (v0 != 0);
                        GetAmbientColor((void *)(u8 *)(s_KnMenuMng + 0x30));
                        SetAmbientColor((float *)((u8 *)&stackFrame_40));
                        *(f32 *)(s_KnMenuMng + 0x38) = *(float *)(GameSt + 0x24);
                        Menu_SettingStore();
                        Menu_ClearMemocaMng();
                        PadVibAllClear();
                        PadUpdate();
                    }
                }
                GameSt[5] = 2;
                v0 = 1;
            }
        }
    }
    return v0;
}

signed int KnMenuMng_GetCursorId(u16 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s0;
    u32 v0;
    u32 a0_2;

    s0 = a1;
    KnMenuMng_MenuIdCtrlIdCheck();
    a0_2 = (u32)s_KnMenuMng;
    v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s_KnMenuMng + 0x10);
        a0_2 = *(s32 *)(u32)(v0 + (s32)((u32)a0 << 2));
        v0 = MenuMng_GetCursorId((void *)a0_2, s0);
    }
    return v0;
}

signed int KnMenuMng_CheckCtrlPlay(u16 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s0;
    u32 v0;
    u32 a0_2;

    s0 = a1;
    KnMenuMng_MenuIdCtrlIdCheck();
    a0_2 = (u32)s_KnMenuMng;
    v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s_KnMenuMng + 0x10);
        a0_2 = *(s32 *)(u32)(v0 + (s32)((u32)a0 << 2));
        v0 = MenuMng_CheckCtrlPlay((void *)a0_2, s0);
    }
    return v0;
}

signed int KnMenuMng_CheckCtrlPlayWait(u16 a0 /* r4 */, s32 a1 /* r5 */) {
    u32 s0;
    u32 v0;
    u32 a0_2;

    s0 = a1;
    KnMenuMng_MenuIdCtrlIdCheck();
    a0_2 = (u32)s_KnMenuMng;
    v0 = MngState_UpdateExeCheck((void *)s_KnMenuMng);
    if (v0 != (u32)1) {
        v0 = 0;
    } else {
        v0 = *(s32 *)(s_KnMenuMng + 0x10);
        a0_2 = *(s32 *)(u32)(v0 + (s32)((u32)a0 << 2));
        v0 = MenuMng_CheckCtrlPlayWait((void *)a0_2, s0);
    }
    return v0;
}

/* KnMenuMng_GetCtrlCalA @ 0x1D6920 .. 0x1D6980 (0x60 bytes, frame 0x30) */

float KnMenuMng_GetCtrlCalA(u16 a0 /* r4 */, s32 a1 /* r5 */) {
    u16 s1;
    u32 s0;

    s1 = a0;
    s0 = a1;
    KnMenuMng_MenuIdCtrlIdCheck();
    return *(float *)(((s32)(*(s32 *)((*(s32 *)(s32)(*(s32 *)(s_KnMenuMng + 0x10) + (s32)((u32)s1 <<
        2)) + 0x64)) + (s32)((s32)((u32)((s32)s0) * (u32)(0x90)))) + 0x44));
}

void KnMenuMng_SetForceChangeCursorId(u16 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    int s1;
    int s0;

    s1 = a1;
    s0 = a2;
    KnMenuMng_MenuIdCtrlIdCheck();
    MenuCtrlMng_SetForceChangeCursorId((void *)(u32)(*(s32 *)((*(s32 *)(s32)(*(s32 *)(s_KnMenuMng +
        0x10) + (s32)((u32)a0 << 2)) + 0x64)) + (s32)((u32)((s32)(s1 << 3) + s1) << 4)), s0);
    return;
}

signed int KnMenuMng_CallSave(void) {
    s32 a0;
    u8 v1;
    u32 v0;

    v0 = 2;
    v1 = GameSt[5];
    a0 = 0;
    if ((u32)v1 != v0) {
        SetVagStmFade(0, 3, 1);
        a0 = 1;
        SetVagStmFade(a0, 3, a0);
        SetVagStmFade(2, 3, 1);
        a0 = 3;
        SetVagStmFade(a0, a0, 1);
        SetVagStmFade(4, 3, 1);
        SetVagStmFade(5, 3, 1);
        v0 = KnMenuMng_CallMenu_(4, 0);
    } else {
        v0 = 0;
    }
    return v0;
}

u8 * KnMenuMng_GetDrawPos(u16 a0 /* r4 */, s32 a1 /* r5 */, s32 a2 /* r6 */) {
    u32 a0_word = a0;
    u32 s2;
    u32 s1;
    u32 s0;
    u32 v0;
    s32 v1;

    s2 = a0_word;
    s1 = a1;
    s0 = a2;
    KnMenuMng_MenuIdCtrlIdCheck();
    v0 = (u16)s2;
    v1 = v0 << 2;
    a1 = s1;
    v0 = *(s32 *)((u8 *)&s_KnMenuMng + 0x20);
    v0 = v0 + v1;
    a0_word = *(s32 *)v0;
    a2 = s0;
    MenuMng_GetDrawPos((void *)a0_word, a1, a2);
    return;
}

static void KnMenuMng_CallBackCallMenu(void) {
    u32 v0;

    v0 = KnMenuMng_CallMenu_(*(s16 *)(s_KnMenuMng + 0x14), 0);
    if (v0 != 0) {
        GameSt[0xf] = 0;
        s_KnMenuMng[0x14] = 0x3e7;
    }
    return;
}

signed int KnMenuMng_GetPlayMenu_All(void) {
    u32 a2;
    u32 a1;
    u32 a0;
    u16 v1;
    u32 v0;

    a2 = 0;
    a1 = *(s32 *)(s_KnMenuMng + 0x10);
    a0 = s_KnMenuMng[0x14];
    do {
        v1 = a2;
        v0 = (u32)(u16)v1 << 2;
        v0 = a1 + (u32)v0;
        v0 = *(s32 *)v0;
        if (v0 != 0 && (s32)*(s32 *)((v0 + 0x70)) >= 0) {
            v0 = 1;
        } else {
            v0 = v1;
            if (a0 == v0) {
                v0 = 2;
            } else {
                v0 = 0;
            }
        }
        if (v0 != 0) {
            return 1;
        }
        a2 = a2 + 1;
        v0 = (s32)a2 < (s32)0xc;
    } while (v0 != 0);
    return 0;
}

signed int KnMenuMng_GetPlayMenu(u16 a0 /* r4 */) {
    u32 v1;
    u32 v0;

    v0 = (u32)&((struct { u8 b[4]; } *)*(s32 *)(s_KnMenuMng + 0x10))[a0];
    v0 = *(s32 *)v0;
    if (v0 != 0 && (s32)*(s32 *)((v0 + 0x70)) >= 0) {
        return 1;
    }
    v1 = s_KnMenuMng[0x14];
    if (v1 == (u32)a0) {
        return 2;
    }
    return 0;
}

/* KnMenuMng_MenuIdCtrlIdCheck @ 0x1D6650 .. 0x1D6658 (0x8 bytes) */
/*
 * dcomp notes:
 *   return: daddu at 0x1d6654 computes the return value
 */

u32 KnMenuMng_MenuIdCtrlIdCheck(void) {
    return 0;
}
