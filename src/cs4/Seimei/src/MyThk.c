#include "common.h"




extern float Math_GetDist(float *, float *);
extern float Math_VectorToAngle(float, float);
extern float Math_GetAngleDist(float, float);
extern u8 MdlMng[];

#define MYTHK_REV(a) (TWO_PI * (int)((PI + (a)) / TWO_PI))
#define MYTHK_WRAP(a) ((PI + (a) >= 0.0f) ? (a) - MYTHK_REV(a) : TWO_PI + ((a) - MYTHK_REV(a)))
#define MYTHK_ABS(a) ((a) < 0.0f ? -(a) : (a))
typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} MYTHKBITS;
typedef struct {
    unsigned char success;
    unsigned char data_len;
    MYTHKBITS button_lo;
    MYTHKBITS button_hi;
    unsigned char r3h;
    unsigned char r3v;
    unsigned char l3h;
    unsigned char l3v;
    unsigned char apress[12];
    unsigned char press[12];
    MYTHKBITS edge_lo;
    MYTHKBITS edge_hi;
} MYTHKPAD;
typedef struct {
    float NumFrame;
} MYTHKANIM;
typedef struct {
    unsigned char hdr[0x20];
    float Pos[4];
    float Ang[4];
    unsigned char body[0xc0];
    MYTHKANIM *lpAnimCtrl;
    short IndexAnim;
    short AnimState;
    unsigned char body2[0x18];
    int Hp;
    unsigned char body3[0x10];
    unsigned int HitFlag;
} MYTHKMY;
typedef struct {
    void *ThkFunc[32];
    void *ActFunc[32];
    unsigned char actID;
    unsigned char actIDB;
    unsigned char actFree;
    unsigned char unused0[1];
    unsigned int unused1[3];
    MYTHKPAD *lpPad;
    char L3H;
    char L3V;
    char R3H;
    char R3V;
    char preL3H;
    char preL3V;
    char preR3H;
    char preR3V;
    unsigned short LStruggle;
    unsigned short RStruggle;
    unsigned short LStruggleB;
    unsigned short RStruggleB;
    unsigned int unused2[3];
    float SummonPos[4];
    float LastPreAnimPos[4];
    float moveRange[6];
    float moveAngle[6];
    float backAngle;
    float totterAngle;
    unsigned char bDash;
    unsigned char bControlOff;
    unsigned char bClinged;
    unsigned char bDrawWrist;
    unsigned char ConcentLoop;
    unsigned char bDead;
    unsigned char bDoubleAttack;
    unsigned char bHeartStop;
    unsigned char bCrouch;
    unsigned char WristObjId;
    unsigned char bBackDisable;
    unsigned char unused3[1];
    int sndHeartHdl;
    int sfxLumpHdl;
    int HpRecMax;
    int HeartBeat;
    int HeartBeatTimer;
    int HeartBeatTimerEnd;
    unsigned char bFantomDizzy;
    unsigned char WepId;
    unsigned char btnId;
    unsigned char BreakFollow;
    unsigned char bDashDisable;
} MYTHKCTRL;
extern u32 L1088[];
extern u8 GameSt[];
extern u32 L1522[];
extern signed int CheckNowFade(signed int);
extern void EneEraseFriend(void *);
extern unsigned short GetMyAttackAnim();
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void sceVu0CopyVector(void *, void *);
extern u8 MdlMng[];
extern u32 GetCamCtrlMode();
extern unsigned int CheckCamDirLock(char, char);
static unsigned int CheckMyCrouchState(void *, void *);
extern signed int CheckEventFlag(signed int);
extern void SetScriptDirect(unsigned int);
extern void SetMyCrouch(void *);
extern unsigned int CheckAnimParam(void *, signed int);
extern void SetMyStay(void *, void *, unsigned short);
extern void CheckMyStruggleStick(void *, void *);
extern void SetMyDamage(void *, void *, unsigned short);
extern struct { unsigned char mythk_pad[0x244]; float CamAng; } *lpDrawMng;
extern void SetMyPadMode(signed int);
static void * GetMyTargetEnemy(void *a0 /* r4 */, float f12 /* f12 */);
static unsigned int CheckMyCrouchState(void *a0 /* r4 */, void *a1 /* r5 */);
static unsigned int CheckMyStairsState(void *a0 /* r4 */, void *a1 /* r5 */);
static unsigned int CheckMyAttackState(void *a0 /* r4 */, void *a1 /* r5 */);
static void MyThkPad(MYTHKMY *lpMy, MYTHKCTRL *lpCtrl);
static void MyThkNone(void);
void MyThkPlay(void *a0 /* r4 */, void *a1 /* r5 */);
void MyThkInit(void);

/* MyThkInit @ 0x1593F0 .. 0x1593F8 (0x8 bytes) */
/*
 * dcomp notes:
 *   tail: j SetMyPadMode at 0x1593f0 leaves the function
 *   return value dropped, call kept: the function is void
 */


void MyThkInit(void) {
    SetMyPadMode(0);
    return;
}


/* MyThkPlay @ 0x1593D0 .. 0x1593E8 (0x18 bytes) */
/*
 * dcomp notes:
 *   tail: jr v0 at 0x1593e0 tail-calls through a pointer
 *   a0 takes slot 0 only because of the ABI order
 */




void MyThkPlay(void *a0 /* r4 */, void *a1 /* r5 */) {
    u32 v0;

    v0 = *(u8 *)(((u8 *)a1 + 0x100));
    v0 = v0 << 2;
    v0 = (s32)((u8 *)a1 + v0);
    v0 = *(s32 *)v0;
    ((void (*)(void *, void *))(s32)v0)(a0, a1);
    return;
}


/* MyThkNone @ 0x1593C0 .. 0x1593C8 (0x8 bytes) */




static void MyThkNone(void) {
    return;
}
















static inline void MyThkPad__push(MYTHKCTRL *lpCtrl, float moveRange, float moveAngle) {
    int i;

    for (i = 5; i > 0; i--) {
        lpCtrl->moveRange[i] = lpCtrl->moveRange[i - 1];
        lpCtrl->moveAngle[i] = lpCtrl->moveAngle[i - 1];
    }
    lpCtrl->moveRange[0] = moveRange;
    lpCtrl->moveAngle[0] = moveAngle;
}

static inline int MyThkPad__back(MYTHKMY *lpMy, MYTHKCTRL *lpCtrl) {
    int i;

    switch (lpCtrl->actID) {
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 12: case 13:
        return 0;
    }
    if (lpCtrl->bBackDisable) {
        return 0;
    }
    for (i = 1; i < 6; i++) {
        if (lpCtrl->moveRange[i] >= 7200.0f) {
            if (MYTHK_ABS(Math_GetAngleDist(lpMy->Ang[1], lpCtrl->moveAngle[i])) > 2.3557498f) {
                return 1;
            }
        }
    }
    return 0;
}

static inline int MyThkPad__stand(MYTHKMY *lpMy) {
    switch (lpMy->IndexAnim) {
    case 2:
        return 1;
    }
    return 0;
}

static inline int MyThkPad__attack(MYTHKMY *lpMy, MYTHKCTRL *lpCtrl) {
    if (!lpCtrl->lpPad->edge_hi.b3) {
        return 0;
    }
    if (!CheckAnimParam(lpMy, 0x2e)) {
        return 0;
    }
    return 1;
}

static void MyThkPad(MYTHKMY *lpMy, MYTHKCTRL *lpCtrl) {
    MYTHKANIM *lpAnimCtrl;
    float moveRange;
    float moveAngle;
    float PadAng;

    lpAnimCtrl = lpMy->lpAnimCtrl;
    if (GameSt[4] == 1) return;
    if (lpCtrl->bControlOff) return;
    if (lpMy->Hp <= 0) return;
    if (GetCamCtrlMode() == 2) return;
    if (CheckMyAttackState(lpMy, lpCtrl)) return;
    moveRange = lpCtrl->L3H * lpCtrl->L3H + lpCtrl->L3V * lpCtrl->L3V;
    if (CheckNowFade(10)) moveRange = 0.0f;
    if (GameSt[0x16] == 0) {
        if (!CheckCamDirLock(lpCtrl->L3V, lpCtrl->L3H)) {
            moveAngle = Math_VectorToAngle(-lpCtrl->L3H, lpCtrl->L3V);
            moveAngle = MYTHK_WRAP(moveAngle + lpDrawMng->CamAng);
        } else {
            moveAngle = lpCtrl->moveAngle[0];
        }
        lpCtrl->bBackDisable = 0;
    } else if (GameSt[0x16] == 1) {
        PadAng = Math_VectorToAngle(-lpCtrl->L3H, lpCtrl->L3V);
        if (MYTHK_ABS(PadAng) > 2.6174998f) {
            moveAngle = lpMy->Ang[1];
        } else if (MYTHK_ABS(PadAng) < 0.34899998f) {
            if (lpCtrl->actID == 2) {
                moveAngle = lpCtrl->backAngle;
            } else {
                moveAngle = MYTHK_WRAP(PI + lpMy->Ang[1]);
            }
            if (lpCtrl->bBackDisable) {
                moveRange = 0.0f;
            }
        } else if (PadAng > 1.9194999f) {
            moveAngle = MYTHK_WRAP(lpMy->Ang[1] - 0.026175f);
        } else if (PadAng > 1.2214999f) {
            moveAngle = MYTHK_WRAP(lpMy->Ang[1] - 0.0349f);
        } else if (PadAng > 0.34899998f) {
            moveAngle = MYTHK_WRAP(lpMy->Ang[1] - 0.043624997f);
        } else if (PadAng < -1.9194999f) {
            moveAngle = MYTHK_WRAP(0.026175f + lpMy->Ang[1]);
        } else if (PadAng < -1.2214999f) {
            moveAngle = MYTHK_WRAP(0.0349f + lpMy->Ang[1]);
        } else if (PadAng < -0.34899998f) {
            moveAngle = MYTHK_WRAP(0.043624997f + lpMy->Ang[1]);
        }
        if (lpCtrl->bBackDisable) {
            lpCtrl->bBackDisable--;
            if (MYTHK_ABS(PadAng) >= 0.34899998f) {
                lpCtrl->bBackDisable = 0;
            }
        }
    }
    MyThkPad__push(lpCtrl, moveRange, moveAngle);
    if (MyThkPad__back(lpMy, lpCtrl)) {
        lpCtrl->actID = 2;
        lpCtrl->backAngle = MYTHK_WRAP(PI + lpMy->Ang[1]);
    }
    if (lpMy->HitFlag & 0x4000) {
        if (lpCtrl->lpPad->edge_hi.b6 && CheckMyCrouchState(lpMy, lpCtrl)) {
            if (GameSt[9] == 0x4b && CheckEventFlag(0x15a)) {
                SetScriptDirect(0x42);
            } else if (GameSt[9] == 0x4c && !CheckEventFlag(0x16e)) {
                SetScriptDirect(0x64);
            } else {
                SetMyCrouch(lpMy);
            }
        }
    } else {
        lpCtrl->bCrouch = 0;
    }
    if (lpCtrl->lpPad->button_hi.b5 && !lpCtrl->bDashDisable && lpCtrl->moveRange[0] > 7200.0f) {
        lpCtrl->bDash = 1;
    } else {
        lpCtrl->bDash = 0;
    }
    if (CheckMyStairsState(lpMy, lpCtrl)) {
        lpCtrl->bDash = 0;
    }
    switch (lpCtrl->actID) {
    case 0:
        if (lpCtrl->moveRange[0] > 7200.0f && !MyThkPad__stand(lpMy)) {
            if (lpAnimCtrl->NumFrame >= 0.0f) {
                lpCtrl->actID = 1;
            }
        } else {
            lpCtrl->moveAngle[5] = lpCtrl->moveAngle[4] = lpCtrl->moveAngle[3] = lpCtrl->moveAngle[2] = lpCtrl->moveAngle[1] = lpCtrl->moveAngle[0] = lpMy->Ang[1];
            if (MyThkPad__attack(lpMy, lpCtrl)) {
                lpCtrl->actID = 7;
            }
        }
        break;
    case 1:
        if (lpCtrl->moveRange[0] <= 7200.0f) {
            if (lpAnimCtrl->NumFrame >= 0.0f) {
                lpCtrl->actID = 0;
            }
        } else if (MyThkPad__attack(lpMy, lpCtrl)) {
            lpCtrl->actID = 7;
        }
        break;
    case 2:
        if (lpCtrl->moveRange[0] <= 7200.0f
            || MYTHK_ABS(Math_GetAngleDist(lpCtrl->backAngle, lpCtrl->moveAngle[0])) > 2.3557498f) {
            lpCtrl->moveRange[0] = 0.0f; lpCtrl->moveRange[1] = 0.0f; lpCtrl->moveRange[2] = 0.0f; lpCtrl->moveRange[3] = 0.0f; lpCtrl->moveRange[4] = 0.0f; lpCtrl->moveRange[5] = 0.0f;
            SetMyStay(lpMy, lpCtrl, 0);
        }
        break;
    case 4:
        CheckMyStruggleStick(lpMy, lpCtrl);
        switch (lpMy->IndexAnim) {
        case 0x47:
        case 0x4d:
        case 0x65:
        case 0x6b:
        case 0x79:
        case 0x97:
            if (lpCtrl->BreakFollow != 0xff && lpCtrl->BreakFollow < lpCtrl->LStruggle) {
                SetMyDamage(lpMy, lpCtrl, lpMy->IndexAnim + 2);
            }
            break;
        }
        break;
    case 13:
        if (lpMy->IndexAnim == 0x79) {
            CheckMyStruggleStick(lpMy, lpCtrl);
            if (lpCtrl->LStruggle != lpCtrl->LStruggleB && lpMy->Pos[1] < 0.8f) {
                lpMy->Pos[1] -= 0.003f;
                if (lpMy->Pos[1] < 0.2f && !lpCtrl->bDead) {
                    ChangeAnimParam(lpMy, 0x4a, 0.0f);
                }
            }
        }
        break;
    }
}



/* MyThkPadMukade @ 0x158120 .. 0x158614 (0x4f4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a0 at 0x158174
 *   fpu: mtc1 reinterprets v0 at 0x158188
 *   fpu: mtc1 reinterprets v0 at 0x158190
 *   fpu: float literal 0x40490fdb at 0x1581b0
 *   fpu: float literal 0x00000000 at 0x1581b4
 *   fpu: float literal 0x40c90fdb at 0x1581d8
 *   fpu: mtc1 reinterprets v1 at 0x1581fc
 *   delay: addiu at 0x158280 writes a register its branch at 0x15827c reads
 *   fpu: float literal 0x45e10000 at 0x1582d8
 *   fpu: float literal 0x00000000 at 0x1582fc
 *   fpu: float literal 0x00000000 at 0x15831c
 *   delay: dsll32 at 0x15834c writes a register its branch at 0x158348 reads
 *   fpu: float literal 0x00000000 at 0x158364
 *   fpu: float literal 0x45e10000 at 0x158388
 *   fpu: float literal 0x45e10000 at 0x1583f8
 *   fpu: float literal 0x45e10000 at 0x158468
 *   fpu: float literal 0x45e10000 at 0x1584e8
 *   fpu: float literal 0x00000000 at 0x158580
 *   fpu: float literal 0x41200000 at 0x1585ac
 *   cfg: kept branch: 0x15828c if (..) goto .L00158560
 *   declaration vs inferred signature: return void vs inferred u32
 */

struct dw_460924_fields;
struct dw_474304_fields;
struct dw_485197_fields;
#ifndef PROTO_DW_482799_FIELDS
#define PROTO_DW_482799_FIELDS
struct dw_482799_fields { unsigned int TEST : 19; unsigned int unused1 : 5; unsigned int ZMSK : 1; unsigned int unused2 : 7; };
#endif
#ifndef PROTO_DW_477870_FIELDS
#define PROTO_DW_477870_FIELDS
struct dw_477870_fields { unsigned char inhibit_mirror_sfx : 1; unsigned char dmy : 7; };
#endif
#ifndef PROTO_DW_477335_FIELDS
#define PROTO_DW_477335_FIELDS
struct dw_477335_fields { float angY; float distXZ; float angStep; unsigned short stayAnim; unsigned short walkAnim; unsigned short prevAnim; short unused[5]; struct dw_460924_fields *lpMdl; };
#endif
#ifndef PROTO_DW_460924_FIELDS
#define PROTO_DW_460924_FIELDS
struct dw_460924_fields { unsigned char bUse; unsigned char bMultiDraw; unsigned char bErase; unsigned char bEraseByMapDraw; unsigned char bPresetMatrix; unsigned char FadeType; unsigned char Priority; unsigned char bUseMdlLight; unsigned char bUseMdlAmbient; unsigned char bUseWorldMat; unsigned char unused0[2]; struct dw_485197_fields *lpMdlData; float (*lpObjMat)[4][4]; float (*lpShadowMat)[4][4]; float (*lpLocalMat)[4][4]; void *lpMi3Head; float Pos[4]; float Ang[4]; float Scl[4]; float Acc[4]; float Dcy[4]; float PosB[4]; float AngB[4]; float LightDir[4]; float LightCol[4]; float AmbientCol[4]; float WorldMat[4][4]; void *lpAnimCtrl; short IndexAnim; short AnimState; float AnimSpeed; float Alpha; float HitSize; float HitHigh; float ShadowSize; float ShadowHigh; int Hp; unsigned int timer; unsigned char TeamNo; unsigned char TeamNoBase; unsigned char AttackNo; unsigned char Flags; short DmgCnt; short NoSearched; unsigned char HitOff; unsigned char GravOff; unsigned char MapHitOff; unsigned char CharHitOutOff; unsigned int HitFlag; struct dw_460924_fields *lpHitMap[2]; void *lpParts; void *lpEventData; void *lpCtrlSt; float FadeStep; struct dw_482799_fields DrawRegs; int State[10]; void *lpPathMng; int PLightIndex; float Z_Offset; short DebugAnimState; unsigned char CtrlMode; unsigned char CtrlModeB; unsigned int *lpShiftTexPacket; unsigned char sceneNo; unsigned char _pad0[1]; unsigned short hSfxPLight; struct dw_477870_fields flags; unsigned char _pad1[3]; struct dw_477335_fields Target; int remnant_HP; unsigned short blood_pool_sfx_idx; unsigned char _pad2[2]; };
#endif
#ifndef PROTO_DW_468373_FIELDS
#define PROTO_DW_468373_FIELDS
struct dw_468373_fields { void *ThkFunc[32]; void *ActFunc[32]; unsigned char actID; unsigned char actIDB; unsigned char actFree; unsigned char unused0[1]; unsigned int unused1[3]; };
#endif
#ifndef PROTO_DW_473773_FIELDS
#define PROTO_DW_473773_FIELDS
struct dw_473773_fields { struct dw_474304_fields *lpPad; char L3H; char L3V; char R3H; char R3V; char preL3H; char preL3V; char preR3H; char preR3V; unsigned short LStruggle; unsigned short RStruggle; unsigned short LStruggleB; unsigned short RStruggleB; unsigned int unused1[3]; };
#endif
#ifndef PROTO_DW_465196_FIELDS
#define PROTO_DW_465196_FIELDS
struct dw_465196_fields { struct dw_468373_fields func; struct dw_473773_fields key; float SummonPos[4]; float LastPreAnimPos[4]; float moveRange[6]; float moveAngle[6]; float backAngle; float totterAngle; unsigned char bDash; unsigned char bControlOff; unsigned char bClinged; unsigned char bDrawWrist; unsigned char ConcentLoop; unsigned char bDead; unsigned char bDoubleAttack; unsigned char bHeartStop; unsigned char bCrouch; unsigned char WristObjId; unsigned char bBackDisable; unsigned char unused1[1]; int sndHeartHdl; int sfxLumpHdl; int HpRecMax; int HeartBeat; int HeartBeatTimer; int HeartBeatTimerEnd; unsigned char bFantomDizzy; unsigned char WepId; unsigned char btnId; unsigned char BreakFollow; unsigned char bDashDisable; unsigned char DoorType; unsigned char StairsState; unsigned char bCrouchDisable; struct dw_460924_fields *lpP030; unsigned int WallHit; int sfxPLightHdl; int sndConcentrateHdl; int UseWait[2]; unsigned short ClingedDisable; unsigned short stepTimer; };
#endif
#ifndef PROTO_DW_471630_FIELDS
#define PROTO_DW_471630_FIELDS
struct dw_471630_fields { unsigned int EN1 : 1; unsigned int EN2 : 1; unsigned int CRTMD : 3; unsigned int MMOD : 1; unsigned int AMOD : 1; unsigned int SLBG : 1; unsigned int ALP : 8; unsigned int p0 : 16; unsigned int p1; };
#endif
#ifndef PROTO_DW_477103_FIELDS
#define PROTO_DW_477103_FIELDS
struct dw_477103_fields { unsigned int INT : 1; unsigned int FFMD : 1; unsigned int DPMS : 2; unsigned int p0 : 28; unsigned int p1; };
#endif
#ifndef PROTO_DW_472033_FIELDS
#define PROTO_DW_472033_FIELDS
struct dw_472033_fields { unsigned int FBP : 9; unsigned int FBW : 6; unsigned int PSM : 5; unsigned int p0 : 12; unsigned int DBX : 11; unsigned int DBY : 11; unsigned int p1 : 10; };
#endif
#ifndef PROTO_DW_479189_FIELDS
#define PROTO_DW_479189_FIELDS
struct dw_479189_fields { unsigned int DX : 12; unsigned int DY : 11; unsigned int MAGH : 4; unsigned int MAGV : 2; unsigned int p0 : 3; unsigned int DW : 12; unsigned int DH : 11; unsigned int p1 : 9; };
#endif
#ifndef PROTO_DW_478001_FIELDS
#define PROTO_DW_478001_FIELDS
struct dw_478001_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int p0 : 8; unsigned int p1; };
#endif
#ifndef PROTO_DW_467858_FIELDS
#define PROTO_DW_467858_FIELDS
struct dw_467858_fields { struct dw_471630_fields pmode; struct dw_477103_fields smode2; struct dw_472033_fields dispfb; struct dw_479189_fields display; struct dw_478001_fields bgcolor; };
#endif
#ifndef PROTO_DW_469443_FIELDS
#define PROTO_DW_469443_FIELDS
struct dw_469443_fields { unsigned long NLOOP : 15; unsigned long EOP : 1; unsigned long pad16 : 16; unsigned long id : 14; unsigned long PRE : 1; unsigned long PRIM : 11; unsigned long FLG : 2; unsigned long NREG : 4; unsigned long REGS0 : 4; unsigned long REGS1 : 4; unsigned long REGS2 : 4; unsigned long REGS3 : 4; unsigned long REGS4 : 4; unsigned long REGS5 : 4; unsigned long REGS6 : 4; unsigned long REGS7 : 4; unsigned long REGS8 : 4; unsigned long REGS9 : 4; unsigned long REGS10 : 4; unsigned long REGS11 : 4; unsigned long REGS12 : 4; unsigned long REGS13 : 4; unsigned long REGS14 : 4; unsigned long REGS15 : 4; };
#endif
#ifndef PROTO_DW_476052_FIELDS
#define PROTO_DW_476052_FIELDS
struct dw_476052_fields { unsigned long FBP : 9; unsigned long pad09 : 7; unsigned long FBW : 6; unsigned long pad22 : 2; unsigned long PSM : 6; unsigned long pad30 : 2; unsigned long FBMSK : 32; };
#endif
#ifndef PROTO_DW_484434_FIELDS
#define PROTO_DW_484434_FIELDS
struct dw_484434_fields { unsigned long ZBP : 9; unsigned long pad09 : 15; unsigned long PSM : 4; unsigned long pad28 : 4; unsigned long ZMSK : 1; unsigned long pad33 : 31; };
#endif
#ifndef PROTO_DW_482418_FIELDS
#define PROTO_DW_482418_FIELDS
struct dw_482418_fields { unsigned long OFX : 16; unsigned long pad16 : 16; unsigned long OFY : 16; unsigned long pad48 : 16; };
#endif
#ifndef PROTO_DW_474719_FIELDS
#define PROTO_DW_474719_FIELDS
struct dw_474719_fields { unsigned long SCAX0 : 11; unsigned long pad11 : 5; unsigned long SCAX1 : 11; unsigned long pad27 : 5; unsigned long SCAY0 : 11; unsigned long pad43 : 5; unsigned long SCAY1 : 11; unsigned long pad59 : 5; };
#endif
#ifndef PROTO_DW_468257_FIELDS
#define PROTO_DW_468257_FIELDS
struct dw_468257_fields { unsigned long AC : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_483343_FIELDS
#define PROTO_DW_483343_FIELDS
struct dw_483343_fields { unsigned long CLAMP : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_471512_FIELDS
#define PROTO_DW_471512_FIELDS
struct dw_471512_fields { unsigned long DTHE : 1; unsigned long pad01 : 63; };
#endif
#ifndef PROTO_DW_478770_FIELDS
#define PROTO_DW_478770_FIELDS
struct dw_478770_fields { unsigned long ATE : 1; unsigned long ATST : 3; unsigned long AREF : 8; unsigned long AFAIL : 2; unsigned long DATE : 1; unsigned long DATM : 1; unsigned long ZTE : 1; unsigned long ZTST : 2; unsigned long pad19 : 45; };
#endif
#ifndef PROTO_DW_468790_FIELDS
#define PROTO_DW_468790_FIELDS
struct dw_468790_fields { struct dw_476052_fields frame1; unsigned long frame1addr; struct dw_484434_fields zbuf1; long zbuf1addr; struct dw_482418_fields xyoffset1; long xyoffset1addr; struct dw_474719_fields scissor1; long scissor1addr; struct dw_468257_fields prmodecont; long prmodecontaddr; struct dw_483343_fields colclamp; long colclampaddr; struct dw_471512_fields dthe; long dtheaddr; struct dw_478770_fields test1; long test1addr; };
#endif
#ifndef PROTO_DW_488617_FIELDS
#define PROTO_DW_488617_FIELDS
struct dw_488617_fields { unsigned long PRIM : 3; unsigned long IIP : 1; unsigned long TME : 1; unsigned long FGE : 1; unsigned long ABE : 1; unsigned long AA1 : 1; unsigned long FST : 1; unsigned long CTXT : 1; unsigned long FIX : 1; unsigned long pad11 : 53; };
#endif
#ifndef PROTO_DW_470541_FIELDS
#define PROTO_DW_470541_FIELDS
struct dw_470541_fields { unsigned int R : 8; unsigned int G : 8; unsigned int B : 8; unsigned int A : 8; float Q; };
#endif
#ifndef PROTO_DW_483175_FIELDS
#define PROTO_DW_483175_FIELDS
struct dw_483175_fields { unsigned long X : 16; unsigned long Y : 16; unsigned long Z : 32; };
#endif
#ifndef PROTO_DW_480400_FIELDS
#define PROTO_DW_480400_FIELDS
struct dw_480400_fields { struct dw_478770_fields testa; long testaaddr; struct dw_488617_fields prim; long primaddr; struct dw_470541_fields rgbaq; long rgbaqaddr; struct dw_483175_fields xyz2a; long xyz2aaddr; struct dw_483175_fields xyz2b; long xyz2baddr; struct dw_478770_fields testb; long testbaddr; };
#endif
#ifndef PROTO_DW_483613_FIELDS
#define PROTO_DW_483613_FIELDS
struct dw_483613_fields { struct dw_467858_fields disp[2]; struct dw_469443_fields giftag0; struct dw_468790_fields draw0; struct dw_480400_fields clear0; struct dw_469443_fields giftag1; struct dw_468790_fields draw1; struct dw_480400_fields clear1; };
#endif
#ifndef PROTO_DW_472434_FIELDS
#define PROTO_DW_472434_FIELDS
struct dw_472434_fields { struct dw_483613_fields dbBuf; float camPos[4]; float camAng[4]; float camPosB[4]; float camAngB[4]; float vsMat[4][4]; float wsMat[4][4]; float wvMat[4][4]; float lcMat[4][4]; float wcMat[4][4]; float csMat[4][4]; float scrDepth; unsigned int *sprBuf[2]; int sprBufID; unsigned int DMATag; int ctxt; int dbBufID; int oddeven; unsigned int calcTime; unsigned int drawTime; unsigned int frameTime; float fov; int TotalPolyNum; int TotalPrimNum; float WaterLevel; unsigned char DrawFlag; unsigned char DrawHitModel; unsigned char BlurMode; unsigned char BlurRate; unsigned char ProjectionType; unsigned char unused[15]; float PlaneParam[4]; float FogParam[4]; float FogParam16[4]; };
#endif
#ifndef PROTO_DW_480874_FIELDS
#define PROTO_DW_480874_FIELDS
struct dw_480874_fields { unsigned int SystemCounter; unsigned char ControlMode; unsigned char GameMode; unsigned char GameModePrev; unsigned char DebugMode; unsigned char StopMode; unsigned char sceneNo; unsigned char padport; unsigned char ShadowTest; unsigned char DepthTest; unsigned char ScriptMode; unsigned char DizzyTest; unsigned char Pause; unsigned char EnePause; unsigned char EnemyOff; unsigned char FadedTest; unsigned char PeepMask; unsigned char PlayerId; unsigned char PadVib; unsigned char KeyConfType; unsigned char EneSearchOff; unsigned char GameLevel; unsigned char StartEquip; unsigned char PenanceMode; unsigned char NineHitNum; unsigned char NegaPosi; unsigned char LoadStart; char Brightness; unsigned char GlareId; unsigned char MyAllAttack; unsigned char DebugMenuOn; unsigned char Sugoroku; unsigned char TutorialOff; float AmbRate; unsigned char ClearCount[3]; unsigned char ExtraClear; unsigned char VoiceLanguage; unsigned char LastLanguage; unsigned char unused[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3_DEFINED
#define DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3 = (int)&(((struct dw_460924_fields *)0)->Hp) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_460924_FIELDS_INDEXANIM_341586DB_DEFINED
#define DCOMP_OFF_STRUCT_DW_460924_FIELDS_INDEXANIM_341586DB_DEFINED
enum { DCOMP_OFF_STRUCT_DW_460924_FIELDS_INDEXANIM_341586DB = (int)&(((struct dw_460924_fields *)0)->IndexAnim) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_460924_FIELDS_LPANIMCTRL_9FD1298B_DEFINED
#define DCOMP_OFF_STRUCT_DW_460924_FIELDS_LPANIMCTRL_9FD1298B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_460924_FIELDS_LPANIMCTRL_9FD1298B = (int)&(((struct dw_460924_fields *)0)->lpAnimCtrl) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_BREAKFOLLOW_BE9FD593_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_BREAKFOLLOW_BE9FD593_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_BREAKFOLLOW_BE9FD593 = (int)&(((struct dw_465196_fields *)0)->BreakFollow) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D = (int)&(((struct dw_465196_fields *)0)->bControlOff) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967 = (int)&(((struct dw_465196_fields *)0)->key.L3H) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08 = (int)&(((struct dw_465196_fields *)0)->key.L3V) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_LSTRUGGLE_011162CC_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_LSTRUGGLE_011162CC_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_LSTRUGGLE_011162CC = (int)&(((struct dw_465196_fields *)0)->key.LStruggle) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92 = (int)&(((struct dw_465196_fields *)0)->moveAngle[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450 = (int)&(((struct dw_465196_fields *)0)->moveAngle[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F = (int)&(((struct dw_465196_fields *)0)->moveAngle[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C = (int)&(((struct dw_465196_fields *)0)->moveAngle[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3 = (int)&(((struct dw_465196_fields *)0)->moveAngle[4]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A = (int)&(((struct dw_465196_fields *)0)->moveAngle[5]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337 = (int)&(((struct dw_465196_fields *)0)->moveRange[0]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0 = (int)&(((struct dw_465196_fields *)0)->moveRange[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306 = (int)&(((struct dw_465196_fields *)0)->moveRange[2]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3 = (int)&(((struct dw_465196_fields *)0)->moveRange[3]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970 = (int)&(((struct dw_465196_fields *)0)->moveRange[4]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3_DEFINED
enum { DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3 = (int)&(((struct dw_465196_fields *)0)->moveRange[5]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66_DEFINED
#define DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66_DEFINED
enum { DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66 = (int)&(((struct dw_472434_fields *)0)->camAng[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711_DEFINED
#define DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711_DEFINED
enum { DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711 = (int)&(((struct dw_480874_fields *)0)->ControlMode) - 0 };
#endif
void MyThkPadMukade(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s2;
    u8 *s1;
    u32 t0;
    u8 *s0;
    s32 a3;
    s32 a2;
    float f12;
    float f3;
    float f1;
    float f20;
    s32 lv;
    s32 lh;
    float f0;
    void *a1_2; // a1
    s32 a0_scalar; // a0
    u8 *a0_2; // a0
    u32 v1;
    u32 v0;

    v1 = (s32)1;
    s2 = (u8 *)a0;
    s0 = (u8 *)*(s32 *)((u8 *)a0 + DCOMP_OFF_STRUCT_DW_460924_FIELDS_LPANIMCTRL_9FD1298B);
    a0_2 = (u8 *)GameSt[(DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711 / 1)];
    s1 = (u8 *)a1;
    if ((u32)a0_2 != (u32)v1) {
        v1 = *(u8 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D);
        if ((u32)v1 == 0 && (s32)*(s32 *)(s2 + DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3) > 0) {
            lv = *(s8 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08);
            lh = *(s8 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967);
            f20 = (float)(lh * lh + lv * lv);
            f0 = Math_VectorToAngle((float)(-lh), (float)lv);
            a0_2 = (u8 *)lpDrawMng;
            f3 = (f0 + *(float *)(a0_2 + DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66));
            f1 = ((3.14159274f + f3 >= 0.0f) ? (f3 - 6.28318548f * (float)(s32)((3.14159274f + f3) / 6.28318548f)) : (6.28318548f + (f3 - 6.28318548f * (float)(s32)((3.14159274f + f3) / 6.28318548f))));
            v1 = (s32)0x90;
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450) = *(float *)(s1
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92);
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337) = f20;
            *(f32 *)(s1 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92) = f1;
            t0 = *(s16 *)(s2 + DCOMP_OFF_STRUCT_DW_460924_FIELDS_INDEXANIM_341586DB);
            if (t0 != (u32)v1) {
                v1 = (s32)0x87;
                if (t0 != (u32)v1) {
                    v1 = (s32)0x84;
                    a2 = 0x88;
                    if (t0 == (u32)v1) {
                        goto _L00158560;
                    }
                    a3 = 0x85;
                    if (t0 != (u32)a2) {
                        a1_2 = (void *)(s32)0x86;
                        if (t0 != (u32)a3) {
                            if (t0 != (u32)(s32)a1_2) {
                                a2 = 0x83;
                                v1 = (s32)0x82;
                                switch (t0) {
                                case 130:
                                    f1 = *(float *)(s1 + 0x150);
                                    if (!(f1 <= 7.2e+03f)) {
                                        v1 = *(s8 *)(s1 + 0x114);
                                        if ((s32)v1 > (s32)0x64) {
                                        a0_2 = s2;
                                        ChangeAnimParam((void *)a0_2, (signed int)a1_2, 0.0f);
                                        break;
                                        } else {
                                        if ((s32)v1 > (s32)-0x65) {
                                        break;
                                        }
                                        a0_2 = s2;
                                        a1_2 = (void *)a2;
                                        ChangeAnimParam((void *)a0_2, (signed int)a1_2, 0.0f);
                                        break;
                                        }
                                    } else {
                                        v1 = *(s32 *)(s1 + 0x110);
                                        if (((struct { u8 pad0:4; u8 b4:1; u8 pad5:3; } *)((s32)v1 + 3))->b4 == 0) {
                                        if (((struct { u8 pad0:7; u8 b7:1; } *)((s32)v1 + 3))->b7 == 0) {
                                        break;
                                        }
                                        }
                                        a0_2 = s2;
                                        ChangeAnimParam((void *)a0_2, 0x89, 0.0f);
                                        v1 = (s32)3;
                                        *(u8 *)(s1 + 0x100) = v1;
                                        *(u8 *)(s2 + 0x12a) = v1;
                                        break;
                                    }
                                case 131:
                                    f1 = *(float *)(s1 + 0x150);
                                    if (f1 <= 7.2e+03f) {
                                        a0_2 = s2;
                                        a1_2 = (void *)a3;
                                        f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                        ChangeAnimParam((void *)a0_2, (signed int)a1_2, f12);
                                        break;
                                    } else {
                                        v1 = *(s8 *)(s1 + 0x114);
                                        if ((s32)v1 <= (s32)0x64) {
                                        break;
                                        }
                                        a0_2 = s2;
                                        a1_2 = (void *)a3;
                                        f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                        ChangeAnimParam((void *)a0_2, (signed int)a1_2, f12);
                                        break;
                                    }
                                }
                            } else {
                                f1 = *(float *)(s1 + 0x150);
                                if (f1 <= 7.2e+03f) {
                                    a0_2 = s2;
                                    a1_2 = (void *)a2;
                                    f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                    ChangeAnimParam((void *)a0_2, (signed int)a1_2, f12);
                                } else {
                                    v1 = *(s8 *)(s1 + 0x114);
                                    if ((s32)v1 <= (s32)-0x65) {
                                        a0_2 = s2;
                                        a1_2 = (void *)a2;
                                        f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                        ChangeAnimParam((void *)a0_2, (signed int)a1_2, f12);
                                    }
                                }
                            }
                        } else {
                            f1 = *(float *)(s1 + 0x150);
                            if (!(f1 <= 7.2e+03f) && (s32)*(s8 *)(s1 + 0x114) <= (s32)-0x65) {
                                a0_2 = s2;
                                f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                ChangeAnimParam((void *)a0_2, 0x83, f12);
                            } else {
                                v1 = *(s8 *)(s1 + 0x114);
                                if ((s32)v1 <= (s32)-0x65) {
                                    a0_2 = s2;
                                    f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                    ChangeAnimParam((void *)a0_2, 0x83, f12);
                                }
                            }
                        }
                    } else {
                        f1 = *(float *)(s1 + 0x150);
                        if (!(f1 <= 7.2e+03f) && (s32)*(s8 *)(s1 + 0x114) > (s32)0x64) {
                            a0_2 = s2;
                            f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                            ChangeAnimParam((void *)a0_2, 0x86, f12);
                        } else {
                            v1 = *(s8 *)(s1 + 0x114);
                            if ((s32)v1 > (s32)0x64) {
                                a0_2 = s2;
                                f12 = (*(float *)(s0 + 0x10) - *(float *)s0);
                                ChangeAnimParam((void *)a0_2, 0x86, f12);
                            }
                        }
                    }
                } else {
                    _L00158560:;
                    a0_scalar = *(s8 *)(s1 + 0x114);
                    v1 = a0_scalar < (s32)-0x64;
                    if ((u32)v1 == 0 && a0_scalar <= (s32)0x64) {
                        v0 = t0 + 1;
                        a0_2 = s2;
                        ChangeAnimParam((void *)a0_2, (u16)v0, 0.0f);
                    }
                }
            } else {
                a0_2 = s2;
                CheckMyStruggleStick((void *)a0_2, (void *)s1);
                f0 = *(float *)s0;
                f1 = (*(float *)(s0 + 0x10) - 1e+01f);
                if (f0 < f1) {
                    a0_2 = (u8 *)*(u8 *)(s1 +
                        DCOMP_OFF_STRUCT_DW_465196_FIELDS_BREAKFOLLOW_BE9FD593);
                    if ((u32)a0_2 != (u32)0xff && (s32)*(u16 *)(s1 +
                        DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_LSTRUGGLE_011162CC) > (s32)a0_2) {
                        a0_2 = s2;
                        a1_2 = (void *)s1;
                        SetMyDamage((void *)a0_2, a1_2, 0x91);
                    }
                }
            }
        }
    }
    return;
}











/* MyThkPadTotter @ 0x157A80 .. 0x158114 (0x694 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets a2 at 0x157ae4
 *   fpu: mtc1 reinterprets v1 at 0x157b0c
 *   fpu: mtc1 reinterprets v0 at 0x157b10
 *   fpu: float literal 0x40490fdb at 0x157b30
 *   fpu: float literal 0x00000000 at 0x157b34
 *   fpu: float literal 0x40c90fdb at 0x157b58
 *   fpu: mtc1 reinterprets v1 at 0x157b7c
 *   fpu: mtc1 reinterprets v0 at 0x157bbc
 *   fpu: mtc1 reinterprets a0 at 0x157bc0
 *   fpu: float literal 0x00000000 at 0x157bd4
 *   fpu: mov.s at 0x157be4 is a float copy
 *   fpu: float literal 0x4027851e at 0x157bf4
 *   fpu: float literal 0x00000000 at 0x157c10
 *   fpu: mov.s at 0x157c20 is a float copy
 *   fpu: float literal 0x3eb2b020 at 0x157c30
 *   fpu: float literal 0x40490fdb at 0x157c50
 *   fpu: float literal 0x00000000 at 0x157c54
 *   fpu: float literal 0x40c90fdb at 0x157c78
 *   fpu: mtc1 reinterprets v1 at 0x157c9c
 *   fpu: float literal 0x3ff5b22c at 0x157cd0
 *   fpu: float literal 0x3c8ef34d at 0x157cf0
 *   fpu: float literal 0x40490fdb at 0x157cfc
 *   fpu: float literal 0x00000000 at 0x157d00
 *   fpu: float literal 0x40c90fdb at 0x157d20
 *   fpu: mtc1 reinterprets v1 at 0x157d44
 *   fpu: float literal 0x3f9c5a1c at 0x157d78
 *   fpu: float literal 0x3cd66cf4 at 0x157d98
 *   fpu: float literal 0x40490fdb at 0x157da4
 *   fpu: float literal 0x00000000 at 0x157da8
 *   fpu: float literal 0x40c90fdb at 0x157dc8
 *   fpu: mtc1 reinterprets v1 at 0x157dec
 *   fpu: float literal 0x3d0ef34d at 0x157e30
 *   fpu: float literal 0x40490fdb at 0x157e3c
 *   fpu: float literal 0x00000000 at 0x157e40
 *   fpu: float literal 0x40c90fdb at 0x157e60
 *   fpu: mtc1 reinterprets v1 at 0x157e84
 *   fpu: float literal 0xbff5b22c at 0x157eb8
 *   fpu: float literal 0x3c8ef34d at 0x157ed8
 *   fpu: float literal 0x40490fdb at 0x157ee4
 *   fpu: float literal 0x00000000 at 0x157ee8
 *   fpu: float literal 0x40c90fdb at 0x157f08
 *   fpu: mtc1 reinterprets v1 at 0x157f2c
 *   fpu: float literal 0xbf9c5a1c at 0x157f60
 *   fpu: float literal 0x3cd66cf4 at 0x157f80
 *   fpu: float literal 0x40490fdb at 0x157f8c
 *   fpu: float literal 0x00000000 at 0x157f90
 *   fpu: float literal 0x40c90fdb at 0x157fb0
 *   fpu: mtc1 reinterprets v1 at 0x157fd4
 *   fpu: float literal 0xbeb2b020 at 0x158008
 *   fpu: float literal 0x3d0ef34d at 0x158028
 *   fpu: float literal 0x40490fdb at 0x158034
 *   fpu: float literal 0x00000000 at 0x158038
 *   fpu: float literal 0x40c90fdb at 0x158058
 *   fpu: mtc1 reinterprets v1 at 0x15807c
 *   declaration vs inferred signature: return void vs inferred u32
 */




#ifndef PROTO_DW_482799_FIELDS
#define PROTO_DW_482799_FIELDS

#endif
#ifndef PROTO_DW_477870_FIELDS
#define PROTO_DW_477870_FIELDS

#endif
#ifndef PROTO_DW_477335_FIELDS
#define PROTO_DW_477335_FIELDS

#endif
#ifndef PROTO_DW_460924_FIELDS
#define PROTO_DW_460924_FIELDS

#endif
#ifndef PROTO_DW_468373_FIELDS
#define PROTO_DW_468373_FIELDS

#endif
#ifndef PROTO_DW_473773_FIELDS
#define PROTO_DW_473773_FIELDS

#endif
#ifndef PROTO_DW_465196_FIELDS
#define PROTO_DW_465196_FIELDS

#endif
#ifndef PROTO_DW_471630_FIELDS
#define PROTO_DW_471630_FIELDS

#endif
#ifndef PROTO_DW_477103_FIELDS
#define PROTO_DW_477103_FIELDS

#endif
#ifndef PROTO_DW_472033_FIELDS
#define PROTO_DW_472033_FIELDS

#endif
#ifndef PROTO_DW_479189_FIELDS
#define PROTO_DW_479189_FIELDS

#endif
#ifndef PROTO_DW_478001_FIELDS
#define PROTO_DW_478001_FIELDS

#endif
#ifndef PROTO_DW_467858_FIELDS
#define PROTO_DW_467858_FIELDS

#endif
#ifndef PROTO_DW_469443_FIELDS
#define PROTO_DW_469443_FIELDS

#endif
#ifndef PROTO_DW_476052_FIELDS
#define PROTO_DW_476052_FIELDS

#endif
#ifndef PROTO_DW_484434_FIELDS
#define PROTO_DW_484434_FIELDS

#endif
#ifndef PROTO_DW_482418_FIELDS
#define PROTO_DW_482418_FIELDS

#endif
#ifndef PROTO_DW_474719_FIELDS
#define PROTO_DW_474719_FIELDS

#endif
#ifndef PROTO_DW_468257_FIELDS
#define PROTO_DW_468257_FIELDS

#endif
#ifndef PROTO_DW_483343_FIELDS
#define PROTO_DW_483343_FIELDS

#endif
#ifndef PROTO_DW_471512_FIELDS
#define PROTO_DW_471512_FIELDS

#endif
#ifndef PROTO_DW_478770_FIELDS
#define PROTO_DW_478770_FIELDS

#endif
#ifndef PROTO_DW_468790_FIELDS
#define PROTO_DW_468790_FIELDS

#endif
#ifndef PROTO_DW_488617_FIELDS
#define PROTO_DW_488617_FIELDS

#endif
#ifndef PROTO_DW_470541_FIELDS
#define PROTO_DW_470541_FIELDS

#endif
#ifndef PROTO_DW_483175_FIELDS
#define PROTO_DW_483175_FIELDS

#endif
#ifndef PROTO_DW_480400_FIELDS
#define PROTO_DW_480400_FIELDS

#endif
#ifndef PROTO_DW_483613_FIELDS
#define PROTO_DW_483613_FIELDS

#endif
#ifndef PROTO_DW_472434_FIELDS
#define PROTO_DW_472434_FIELDS

#endif
#ifndef PROTO_DW_480874_FIELDS
#define PROTO_DW_480874_FIELDS

#endif

#ifndef DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B_DEFINED
#define DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B = (int)&(((struct dw_460924_fields *)0)->Ang[1]) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3_DEFINED
#define DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3_DEFINED
#define DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66_DEFINED
#define DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711_DEFINED
#define DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711_DEFINED

#endif
#ifndef DCOMP_OFF_STRUCT_DW_480874_FIELDS_KEYCONFTYPE_A2102F33_DEFINED
#define DCOMP_OFF_STRUCT_DW_480874_FIELDS_KEYCONFTYPE_A2102F33_DEFINED
enum { DCOMP_OFF_STRUCT_DW_480874_FIELDS_KEYCONFTYPE_A2102F33 = (int)&(((struct dw_480874_fields *)0)->KeyConfType) - 0 };
#endif
#ifndef DCOMP_EXPR_405892EAFA68827F
#define DCOMP_EXPR_405892EAFA68827F(dcomp_arg) ((dcomp_arg) < 0.0f ? (-(dcomp_arg)) : (float)(dcomp_arg))
#endif
#ifndef DCOMP_EXPR_F4392B91E5A8C94E
#define DCOMP_EXPR_F4392B91E5A8C94E(dcomp_arg) ((3.1415927f + (dcomp_arg)) >= 0.0f ? ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f))) : (6.2831855f + ((dcomp_arg) - (6.2831855f * (float)(s32)((3.1415927f + (dcomp_arg)) / 6.2831855f)))))
#endif
void MyThkPadTotter(void *a0 /* r4 */, void *a1 /* r5 */) {
    s32 xt0;
    s32 v1;
    float f21;
    u8 *s0;
    s32 lh;
    float f1;
    float f20;
    u8 *a0_2;

    s0 = (u8 *)(s32)a1;
    v1 = GameSt[(DCOMP_OFF_STRUCT_DW_480874_FIELDS_CONTROLMODE_30721711 / 1)];
    if (v1 != (1)) {
        v1 = *(u8 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_BCONTROLOFF_B763701D);
        if (v1 == 0 && *(s32 *)(((u8 *)a0) + DCOMP_OFF_STRUCT_DW_460924_FIELDS_HP_FCACD0E3) > 0) {
            xt0 = *(s8 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08);
            lh = *(s8 *)((DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967 + s0));
            f21 = (float)(lh * lh + xt0 * xt0);
            v1 = GameSt[(DCOMP_OFF_STRUCT_DW_480874_FIELDS_KEYCONFTYPE_A2102F33 / 1)];
            if (v1 == 0) {
                if (CheckCamDirLock(*(s8 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08), *(s8 *)(DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967 + s0)) == 0) {
                    f1 = Math_VectorToAngle((float)(-*(s8 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3H_0AAFB967)), (float)*(s8 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_KEY_L3V_0AD37B08));
                    f20 = DCOMP_EXPR_F4392B91E5A8C94E(((f1 + *(float *)((u8 *)lpDrawMng + DCOMP_OFF_STRUCT_DW_472434_FIELDS_CAMANG_1__6F19AD66))));
                } else {
                    f20 = *(float *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92);
                }
            } else if (v1 == (1)) {
                f1 = Math_VectorToAngle((float)(-lh), (float)xt0);
                if (!((float)DCOMP_EXPR_405892EAFA68827F(f1) <= 2.6174998f)) {
                    f20 = *(float *)(((u8 *)a0) + DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B);
                    v1 = 0x3eb2b020;
                } else {
                    if ((float)DCOMP_EXPR_405892EAFA68827F(f1) < 0.34899998f) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((3.1415927f + *(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B)));
                    } else if (!(f1 <= 1.9194999f)) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((*(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B) - 0.01745f));
                    } else if (!(f1 <= 1.2214999f)) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((*(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B) - 0.026175f));
                    } else if (!(f1 <= 0.34899998f)) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((*(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B) - 0.0349f));
                    } else if (f1 < -1.9194999f) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((0.01745f + *(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B)));
                    } else if (f1 < -1.2214999f) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((0.026175f + *(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B)));
                    } else if (f1 < -0.34899998f) {
                        f20 = DCOMP_EXPR_F4392B91E5A8C94E((0.0349f + *(float *)(((u8 *)a0) +
                            DCOMP_OFF_STRUCT_DW_460924_FIELDS_ANG_1__F31B399B)));
                    }
                }
            }
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_5__C233C8A3) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_5__EA6F5C4A) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_4__6ACBD970) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_4__E2B6FEF3) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_3__921507A3) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_3__2BFB002C) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_2__AEB51306) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_2__6F3F578F) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_1__AAD2CFC0) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_1__99DD6450) = *(float *)(s0
                + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92);
            *(f32 *)(s0 + DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVERANGE_0__071E2337) = f21;
            *(f32 *)((DCOMP_OFF_STRUCT_DW_465196_FIELDS_MOVEANGLE_0__890CBE92 + s0)) = f20;
        }
    }
    return;
}


/* CheckMyAttackState @ 0x157870 .. 0x157A74 (0x204 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1578c4 writes a register its branch at 0x1578c0 reads
 *   fpu: float literal 0x00000000 at 0x1579c0
 *   fpu: float literal 0x00000000 at 0x157a2c
 *   cfg: kept branch: 0x1578e0 if (..) goto .L00157970
 *   cfg: kept branch: 0x157970 if (..) goto .L001579E8
 *   cfg: kept goto: 0x1579b8 -> .L00157A60
 *   cfg: kept goto: 0x157a24 -> .L00157A60
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */


static unsigned int CheckMyAttackState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    u32 v1;
    u64 v0_64;
    u32 v0;
    float f12;
    void *a1_2;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    a0 = (void *)(s32)6;
    v0 = CheckNowFade((signed int)a0);
    if (v0 != 0) {
        v0 = 0;
    } else {
        a0 = (void *)(s32)0xa;
        v0 = CheckNowFade((signed int)a0);
        if (v0 != 0) {
            v0 = 0;
        } else {
            v1 = *(u8 *)(s0 + 0x100);
            v0 = 2;
            switch (v1) {
            case 0:
            case 1:
            case 2:
                v1 = *(s32 *)(s0 + 0x110);
                v0 = *(u8 *)((v1 + 3));
                v0_64 = (u64)((u64)v0 << 0x3e) >> 0x3f;
                if (v0_64 == 0) {
                    goto _L00157970;
                }
                v1 = *(u8 *)((v1 + 0x21));
                v0_64 = (u64)((u64)v1 << 0x38) >> 0x3f;
                if (v0_64 != 0) {
                    a0 = (void *)(u8 *)(((u8 *)MdlMng) + 0x17140);
                } else {
                    v0_64 = (u64)((u64)v1 << 0x3b) >> 0x3f;
                    if (v0_64 != 0) {
                        a0 = (void *)(u8 *)(((u8 *)MdlMng) + 0x17300);
                    } else {
                        a0 = (void *)0;
                    }
                }
                if ((u32)a0 == 0 || (u32)*(u8 *)a0 == 0 || (u32)*(s16 *)(((u8 *)a0 + 0x104)) ==
                    (u32)7) {
                    break;
                }
                EneEraseFriend(a0);
                break;
                _L00157970:;
                *(u8 *)(s0 + 0x18e) = 0;
                v0 = *(s32 *)(s0 + 0x110);
                v1 = v0 + 0x21;
                v0 = *(u8 *)((v0 + 0x21));
                v0_64 = (u64)((u64)v0 << 0x38) >> 0x3f;
                if (v0_64 == 0 || (u32)*(s32 *)(s0 + 0x1c4) != 0) {
                    goto _L001579E8;
                }
                a0 = (void *)s1;
                a1_2 = (void *)s0;
                a1_2 = (void *)(u16)GetMyAttackAnim(a0, a1_2, 0);
                v0 = *(s16 *)(s1 + 0x104);
                if ((u32)a1_2 == v0) {
                    break;
                }
                v0 = 3;
                a0 = (void *)s1;
                f12 = 0.0f;
                *(u8 *)(s0 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                a1_2 = (void *)(s1 + 0x20);
                a0 = (void *)(s0 + 0x130);
                *(u8 *)(s0 + 0x1ae) = 0;
                sceVu0CopyVector(a0, a1_2);
                v0 = 1;
                goto _L00157A60;
                _L001579E8:;
                v0 = *(u8 *)v1;
                v0_64 = (u64)((u64)v0 << 0x3b) >> 0x3f;
                if (v0_64 == 0 || (u32)*(s32 *)(s0 + 0x1c8) != 0) {
                    break;
                }
                a0 = (void *)s1;
                a1_2 = (void *)s0;
                a1_2 = (void *)(u16)GetMyAttackAnim(a0, a1_2, 1);
                v0 = *(s16 *)(s1 + 0x104);
                if ((u32)a1_2 == v0) {
                    break;
                }
                v0 = 3;
                a0 = (void *)s1;
                f12 = 0.0f;
                *(u8 *)(s0 + 0x100) = v0;
                ChangeAnimParam(a0, (signed int)a1_2, 0.0f);
                v0 = 1;
                a1_2 = (void *)(s1 + 0x20);
                *(u8 *)(s0 + 0x1ae) = v0;
                a0 = (void *)(s0 + 0x130);
                sceVu0CopyVector(a0, a1_2);
                v0 = 1;
                return v0;
            }
            v0 = 0;
        }
    }
    _L00157A60:;
    return v0;
}


/* CheckMyStairsState @ 0x157770 .. 0x157868 (0xf8 bytes) */
/*
 * dcomp notes:
 *   delay: addiu at 0x15778c writes a register its branch at 0x157788 reads
 *   delay: addiu at 0x1577a4 writes a register its branch at 0x1577a0 reads
 *   return: lbu at 0x157864 computes the return value
 *   declaration vs inferred signature: return unsigned int vs inferred u8
 */





static unsigned int CheckMyStairsState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 a2;
    u8 *a1_bytes; // a1
    u8 *a0_bytes; // a0
    float f1;
    float f0;
    u32 v1;
    u32 v0;

    a0_bytes = (u8 *)a0;
    a1_bytes = (u8 *)a1;
    a2 = *(u8 *)(a1_bytes + 0x1b2);
    if ((u32)a2 == 0) {
        v1 = *(s32 *)(a1_bytes + 0x1b8);
        v0 = 0x400000;
        if ((u32)(v1 & 0x400000) != 0) {
            *(u8 *)(a1_bytes + 0x1b2) = 1;
        } else {
            v0 = 0x200000;
            if ((u32)(v1 & 0x200000) != 0) {
                *(u8 *)(a1_bytes + 0x1b2) = 2;
            }
        }
    } else {
        v1 = 2;
        if ((u32)a2 == v1) {
            f1 = *(float *)(a0_bytes + 0x24);
            f0 = *(float *)(a1_bytes + 0x144);
            if (f1 < f0) {
                *(u8 *)(a1_bytes + 0x1b2) = 1;
            }
            v1 = *(s32 *)(a1_bytes + 0x1b8);
            v0 = 0x400000;
            if ((u32)(v1 & 0x400000) != 0 || (u32)(*(s32 *)(a0_bytes + 0x134) & 0x8000) == 0) {
                *(u8 *)(a1_bytes + 0x1b2) = 0;
            }
        } else if ((u32)a2 == (u32)1) {
            f1 = *(float *)(a0_bytes + 0x24);
            f0 = *(float *)(a1_bytes + 0x144);
            if (!(f1 <= f0)) {
                *(u8 *)(a1_bytes + 0x1b2) = v1;
            }
            v1 = *(s32 *)(a1_bytes + 0x1b8);
            v0 = 0x200000;
            if ((u32)(v1 & 0x200000) != 0 || (u32)(*(s32 *)(a0_bytes + 0x134) & 0x8000) == 0) {
                *(u8 *)(a1_bytes + 0x1b2) = 0;
            }
        }
    }
    return *(u8 *)(a1_bytes + 0x1b2);
}















/* CheckMyCrouchState @ 0x1575C0 .. 0x157764 (0x1a4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   quad: v0: 128-bit web split from its scalar uses
 *   literal: @1088 -> 0x228930
 *   literal: @1522 -> 0x253780
 *   stack: address of the slot at 0x30 escapes at 0x1575f8
 *   indirect: jr v0 at 0x15761c -> <v0>
 *   delay: addiu at 0x157640 writes a register its branch at 0x15763c reads
 *   delay: addiu at 0x157654 writes a register its branch at 0x157650 reads
 *   stack: address of the slot at 0x38 escapes at 0x157680
 *   stack: address of the slot at 0x38 escapes at 0x157698
 *   stack: address of the slot at 0x38 escapes at 0x1576b0
 *   fpu: mov.s at 0x1576e0 is a float copy
 *   fpu: mov.s at 0x1576e8 is a float copy
 *   fpu: float literal 0x00000000 at 0x1576ec
 *   fpu: mov.s at 0x157708 is a float copy
 *   fpu: mov.s at 0x15771c is a float copy
 *   fpu: float literal 0x3f490fdb at 0x157728
 *   literal: @1088 initializes the 16-byte local at 0x30
 *   cfg: kept goto: 0x1575f4 -> .L00157750
 *   cfg: kept goto: 0x157668 -> .L001576B8
 *   cfg: kept goto: 0x157680 -> .L001576B8
 *   cfg: kept goto: 0x157698 -> .L001576B8
 *   declaration vs inferred signature: return unsigned int vs inferred u32
 */


static unsigned int CheckMyCrouchState(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s0;
    u32 v1;
    u32 v0;
    float f13;
    float f12;
    float f1;
    float f0;
    float f20;

    v0 = (u32)L1088;
    {
        struct stackFrame_30 { u8 b[16]; } stackFrame_30 __attribute__((aligned(16))) = {{0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x3f}};
        v1 = (u32)((u8 *)&stackFrame_30);
        v0 = *(u8 *)(((u8 *)a1 + 0x1b3));
        s0 = (u8 *)a0;
        if (v0 != 0) {
            v0 = 0;
            goto _L00157750;
        }
        v0 = *(u8 *)(((u8 *)a1 + 0x100));
        v0 = ({ s32 native_result_0; __asm__("addi %0,%1,-3" : "=r"(native_result_0) :
            "r"((s32)v0)); native_result_0; });
        switch (v0) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            v0 = 0;
            return v0;
        default:
            v1 = GameSt[9];
            v0 = 0x4c;
            switch (v1) {
            case 6:
                v0 = 0x420c0000;
                *(u32 *)((u8 *)&stackFrame_30) = 0x420c0000;
                v1 = (u32)((u8 *)&stackFrame_30 + 0x8);
                v0 = 0x40900000;
                *(u32 *)((u8 *)&stackFrame_30 + 0x8) = 0x40900000;
                goto _L001576B8;
            case 73:
                v0 = 0x41e00000;
                *(u32 *)((u8 *)&stackFrame_30) = 0x41e00000;
                v1 = (u32)((u8 *)&stackFrame_30 + 0x8);
                v0 = 0x40e00000;
                *(u32 *)((u8 *)&stackFrame_30 + 0x8) = 0x40e00000;
                goto _L001576B8;
            case 75:
            case 76:
                v0 = -0x3ec80000;
                *(u32 *)((u8 *)&stackFrame_30) = -0x3ec80000;
                v1 = (u32)((u8 *)&stackFrame_30 + 0x8);
                v0 = -0x3ea80000;
                *(u32 *)((u8 *)&stackFrame_30 + 0x8) = -0x3ea80000;
                goto _L001576B8;
            }
        }
        v0 = 0;
        return v0;
        _L001576B8:;
        f12 = (-(*(float *)((u8 *)&stackFrame_30) - *(float *)(s0 + 0x20)));
        f13 = (-(*(float *)v1 - *(float *)(s0 + 0x28)));
        f0 = Math_VectorToAngle(f12, f13);
        f12 = *(float *)(s0 + 0x34);
        f20 = (float)f0;
        f0 = Math_GetAngleDist(f12, (float)f20);
        f1 = 0.0f;
        if (f0 < 0.0f) {
            f12 = *(float *)(s0 + 0x34);
            f0 = (-Math_GetAngleDist(f12, (float)f20));
        } else {
            f12 = *(float *)(s0 + 0x34);
            f0 = Math_GetAngleDist(f12, (float)f20);
        }
        f1 = 0.785398185f;
        if (!(f0 <= 0.785398185f)) {
            v0 = 0;
            return v0;
        }
        v0 = 1;
        _L00157750:;
        return v0;
    }
}



/* GetMyAttackAnim @ 0x157140 .. 0x1575BC (0x47c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40400000 at 0x1571ac
 *   fpu: float literal 0x00000000 at 0x1571d4
 *   fpu: float literal 0x3fc90624 at 0x157210
 *   fpu: mov.s at 0x157224 is a float copy
 *   fpu: float literal 0x41f00000 at 0x15722c
 *   fpu: float literal 0x3fc00000 at 0x157270
 *   fpu: float literal 0x40400000 at 0x157364
 *   fpu: float literal 0x00000000 at 0x15738c
 *   fpu: float literal 0x3fc90624 at 0x1573c8
 *   fpu: mov.s at 0x1573dc is a float copy
 *   fpu: float literal 0x41f00000 at 0x1573e4
 *   fpu: float literal 0x3fc00000 at 0x157428
 *   cfg: kept goto: 0x157198 -> .L001575A0
 *   cfg: kept goto: 0x1572d8 -> .L001575A0
 *   cfg: kept goto: 0x157314 -> .L001575A0
 *   cfg: kept goto: 0x157350 -> .L001575A0
 *   cfg: kept goto: 0x157490 -> .L001575A0
 *   cfg: kept goto: 0x1574d8 -> .L001575A0
 *   cfg: kept goto: 0x157534 -> .L001575A0
 *   cfg: kept goto: 0x157554 -> .L001575A0
 *   declaration vs inferred signature: return unsigned short vs inferred u32
 */

extern void * GetMyEquip(void *, signed int);
extern unsigned int CheckMyDizzyState(void *, void *);
extern signed int CheckMyWeapon();
extern void SetModelTargetToModel(void *, void *);
extern signed int CheckEneFlick(void *);
extern void * GetEneParam(signed int, unsigned char);
extern signed short GetSpiritNum(signed int);

static inline void GetMyAttackAnim__inl0(u8 *s3, u32 v1) {
    u32 v0;
    float f13;
    float f12;
    float f0;
    void *a0_2;
    void *a1_2;

    a0_2 = (void *)s3;
    *(u8 *)(s3 + 0x12a) = v1;
    v0 = (u32)GetMyTargetEnemy(a0_2, 3.0f);
    a1_2 = (void *)v0;
    if (v0 != 0) {
        a0_2 = (void *)s3;
        SetModelTargetToModel(a0_2, a1_2);
        f13 = *(float *)(s3 + 0x198);
        f12 = *(float *)(s3 + 0x34);
        f0 = Math_GetAngleDist(f12, f13);
        if (f0 < 0.0f) {
            f13 = *(float *)(s3 + 0x198);
            f12 = *(float *)(s3 + 0x34);
            f0 = (-Math_GetAngleDist(f12, f13));
        } else {
            f13 = *(float *)(s3 + 0x198);
            f12 = *(float *)(s3 + 0x34);
            f0 = Math_GetAngleDist(f12, f13);
        }
        v0 = 0x3fc90624;
        if (!(f0 <= 1.5704999f)) {
            f0 = (float)1.5704999f;
        }
        *(f32 *)(s3 + 0x1a0) = (f0 / 3e+01f);
    } else {
        *(u32 *)(s3 + 0x1b4) = 0;
    }
}

static inline u32 GetMyAttackAnim__inl1(u8 *s3) {
    u8 *s0;
    u32 v0;
    float f2;
    float f0;
    void *a0_2;

    s0 = (u8 *)*(s32 *)(s3 + 0x1b4);
    if ((u32)(s32)s0 == 0) {
        v0 = 0;
    } else {
        f2 = *(float *)(s3 + 0x19c);
        f0 = (1.5f * *(float *)(s0 + 0x110));
        if (!(f2 <= f0)) {
            v0 = 0;
        } else {
            a0_2 = (void *)s3;
            v0 = CheckAnimParam(a0_2, 0x35);
            if (v0 == 0) {
                v0 = 0;
            } else {
                a0_2 = (void *)s0;
                v0 = CheckEneFlick(a0_2);
                if (v0 == 0) {
                    v0 = 0;
                } else {
                    v0 = 1;
                }
            }
        }
    }
    return v0;
}

unsigned short GetMyAttackAnim(lpMy, lpCtrl, btn)
    u8 *lpMy;
    u8 *lpCtrl;
    signed int btn; {
    u8 *lpEquip;

    lpEquip = (u8 *)GetMyEquip(lpMy, btn);
    if (CheckMyDizzyState(lpMy, lpCtrl) != 0) {
        if (CheckMyWeapon(lpMy, lpCtrl) == 0) {
            return 0x28;
        }
        GetMyAttackAnim__inl0(lpMy, *(u8 *)(lpCtrl + 0x1ad));
        if (GetMyAttackAnim__inl1(lpMy) != 0) {
            *(u8 *)(lpMy + 0x12a) = 0;
            return 0x35;
        }
        return 0x32;
    }
    if (*(s16 *)(lpMy + 0x104) == 0x28) {
        if (CheckMyWeapon(lpMy, lpCtrl) != 0) {
            return 0x32;
        }
    }
    switch (*(u8 *)lpEquip) {
    case 0:
        if (CheckMyWeapon(lpMy, lpCtrl) == 0) {
            return 0x28;
        }
        GetMyAttackAnim__inl0(lpMy, *(u8 *)(lpCtrl + 0x1ad));
        if (GetMyAttackAnim__inl1(lpMy) != 0) {
            *(u8 *)(lpMy + 0x12a) = 0;
            return 0x35;
        }
        return 0x32;
    case 1: {
        u8 *lpEnePrm = (u8 *)GetEneParam(*(s32 *)(lpEquip + 4), *(u8 *)(lpMy + 0x128));
        if (lpEnePrm == 0) {
            break;
        }
        if (*(s32 *)(lpMy + 0x120) < *(u8 *)(lpEnePrm + 0x23)) {
            return *(u16 *)(lpMy + 0x104);
        }
        if (*(u16 *)(lpEnePrm + 0x2a) == 0 && *(u8 *)((u8 *)(MdlMng + 0x17140) + (s32)((btn * 8 - btn) << 6)) != 0) {
            return *(u16 *)(lpMy + 0x104);
        }
        if ((s16)GetSpiritNum(*(u16 *)lpEnePrm) == 0) {
            return *(u16 *)(lpMy + 0x104);
        }
        if (CheckMyWeapon(lpMy, lpCtrl) == 1) {
            return 0x28;
        }
        switch (*(u8 *)(lpEnePrm + 0x22)) {
        case 0:
            return 0x2b;
        case 1:
            return 0x29;
        case 2:
            return 0x2a;
        }
    }
    }
    return *(u16 *)(lpMy + 0x104);
}


extern void MyThkPadMukade();
extern void MyThkPadTotter();

void SetMyPadMode(signed int Mode) {
    int i;
    MYTHKCTRL *lpCtrl;

    lpCtrl = (MYTHKCTRL *)*(u32 *)(MdlMng + 0x11948);
    for (i = 0; i < 32; i++) {
        lpCtrl->ThkFunc[i] = (void *)MyThkNone;
    }
    switch (Mode) {
    case 0:
        for (i = 0; i < 32; i++) {
            lpCtrl->ThkFunc[i] = (void *)MyThkPad;
        }
        return;
    case 1:
        for (i = 0; i < 32; i++) {
            lpCtrl->ThkFunc[i] = (void *)MyThkPadMukade;
        }
        return;
    case 2:
        for (i = 0; i < 32; i++) {
            lpCtrl->ThkFunc[i] = (void *)MyThkPadTotter;
        }
    }
}






/* GetMyTargetEnemy @ 0x156EA0 .. 0x156FF0 (0x150 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40490fdb at 0x156ee0
 *   fpu: mov.s at 0x156ee8 is a float copy
 *   fpu: mov.s at 0x156f58 is a float copy
 *   fpu: mov.s at 0x156f60 is a float copy
 *   fpu: float literal 0x00000000 at 0x156f64
 *   fpu: mov.s at 0x156f80 is a float copy
 *   fpu: mov.s at 0x156f94 is a float copy
 *   fpu: mov.s at 0x156fa4 is a float copy
 *   cfg: loop body is not one contiguous region: .L00156EF0
 *   cfg: kept branch: 0x156f08 if (..) goto .L00156FB0
 */

static void * GetMyTargetEnemy(void *a0 /* r4 */, float f12 /* f12 */) {
    float *s2;
    u32 v1;
    u8 *s1;
    u32 s0;
    float f22;
    float f21;
    u32 v0;
    float f13;
    float f2;
    float f1;
    float f0;
    float f20;
    void *a0_2;

    v0 = 0x40490000;
    v1 = 0x40490000 | 0xfdb;
    v0 = (u32)(u8 *)(MdlMng + 0x17140);
    s1 = (u8 *)(MdlMng + 0x119c0);
    s2 = (float *)a0;
    s0 = 0;
    f20 = 3.14159274f;
    f22 = f12;
    if ((u32)s1 != v0) {
        do {
            v0 = *(u8 *)s1;
            if (v0 != 0) {
                v0 = *(s32 *)(s1 + 0x120);
                v1 = *(s32 *)(s1 + 0x148);
                if ((s32)v0 <= 0) {
                    v1 = *(u8 *)((v1 + 0x180));
                    v0 = 7;
                    if (v1 != v0) {
                        goto _L00156FB0;
                    }
                }
                a0_2 = (void *)(u8 *)(s2 + 8);
                f0 = Math_GetDist((float *)a0_2, (float *)(u8 *)(s1 + 0x20));
                if (!(f22 < f0)) {
                    f2 = (*(float *)(s1 + 0x20) - s2[8]);
                    f12 = (-f2);
                    f13 = (-(*(float *)(s1 + 0x28) - s2[0xa]));
                    f0 = Math_VectorToAngle(f12, f13);
                    f12 = s2[0xd];
                    f21 = (float)f0;
                    f0 = Math_GetAngleDist(f12, (float)f21);
                    f1 = 0.0f;
                    if (f0 < 0.0f) {
                        f12 = s2[0xd];
                        f13 = f21;
                        f0 = (-Math_GetAngleDist(f12, f13));
                    } else {
                        f12 = s2[0xd];
                        f13 = f21;
                        f0 = Math_GetAngleDist(f12, f13);
                    }
                    if (f0 < f20) {
                        f20 = f0;
                        s0 = (u32)s1;
                    }
                }
            }
            _L00156FB0:;
            s1 = (u8 *)(s1 + 0x1c0);
        } while (s1 != (u8 *)(MdlMng + 0x17140));
    }
    v0 = s0;
    return (void *)v0;
}

