#include "common.h"
struct dw_2799281_fields { unsigned char pos[25]; };
typedef struct dw_2799281_fields PosList;
extern PosList gINIT_POS_LIST;
extern u32 gaScoreList[];
extern u8 gEnemyData[];
extern u8 gALLPOS[];
void __sghEneThk_GetSafePos(u8 *output);
void __sghEneThk_GetGoalOrNonGoal(void *, void *, unsigned int, int);
static void __sghEneThk_GetGoalByAddSai(void *, void *, unsigned int, int);
extern void sghEneThk_GetActIsPossible(void *, void *, unsigned int);
extern void sghMap_Eval(void *, void *, unsigned char, unsigned char, unsigned char);
static void __sghEneThk_GetActIsMostScoreInInside(void *, unsigned char);
static signed int __sghEneThk_GetMostScoreInInside(unsigned char);
static signed int __sghEneThk_MarkingBefore(unsigned char);
static signed int __sghEneThk_MarkingAfter(unsigned char, unsigned char);
struct dw_2799695_fields { unsigned char spots[2]; };
typedef struct { s8 d[0x20]; } SghMapN;
typedef struct { SghMapN m[2]; } MapPairN;
struct H { s16 v; };


static inline int MbSafe(u8 *p, unsigned int pos_, u8 *map) {
    if (p[0] != 0xff) {
        do {
            if (*p >= (u32)(u8)pos_) {
                return 1;
            }
            if (map[*p] > 0) {
                return 0;
            }
            p++;
        } while (*p != 0xff);
    }
    return 1;
}


static u8 gALLPOS[0x19] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10,
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0xff
};
static PosList gINIT_POS_LIST __attribute__((aligned(16))) = {{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
}};
static u32 gaScoreList[0x1b] __attribute__((aligned(16)));
static u8 gEnemyData[0x42] __attribute__((aligned(16)));


extern PosList gINIT_POS_LIST;
extern u8 gEnemyData[];


extern PosList gINIT_POS_LIST;
extern u8 gEnemyData[];


/* sghEneThk_DiceShake @ 0x209CF0 .. 0x209D8C (0x9c bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: 2-byte aggregate copy in 1-byte chunks at 0x209d74
 *   return without a value in a non-void function
 */

extern int rand(void);

/* sghEneThk_GetOutSideKomaNum @ 0x209D90 .. 0x209DB0 (0x20 bytes) */
/*
 * dcomp notes:
 *   return: lbu at 0x209dac computes the return value
 */

extern u8 gEnemyData[];

extern void sghEneThk_GetActIsPossible(void *, void *, unsigned int);


static inline void DoEval(MapPairN *maplist, u8 *sai, u8 e0) {
    MapPairN evalmap = {0};
    sghMap_Eval(&evalmap, 2 + gEnemyData, sai[1], sai[0], e0);
    *maplist = evalmap;
}


typedef struct { s8 d[0x20]; } SghMap;



enum sghEneThk_SetPlayerID_Bool { sghEneThk_SetPlayerID_F, sghEneThk_SetPlayerID_T };


/* sghEneThk_GetActList @ 0x20A680 .. 0x20A6A4 (0x24 bytes) */
/*
 * dcomp notes:
 *   stack: 4-byte aggregate copy in 1-byte chunks at 0x20a6a0
 *   return without a value in a non-void function
 */

extern u8 gActlist[4];

/* sghEneThk_ScoreInit @ 0x20A6E0 .. 0x20A804 (0x124 bytes) */

extern u32 gaScoreList[];

static u8 gActlist[0x4];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
unsigned int sghEneThk_ScoreInit(void);
void sghEneThk_SetActList(void *a0 );
u8 sghEneThk_GetActList(u8 *a0 );
void sghEneThk_SetPlayerID(unsigned char playerID);
void sghEneThk_SetMap(SghMap *maplist_);
void sghEneThk_ThinkNomal(void *a0, struct dw_2799695_fields *dice_);
void sghEneThk_ThinkOutSideOnce(void *a0, struct dw_2799695_fields *dice_);
void sghEneThk_ThinkOutSide(void *outputArg, void *diceArg);
u8 sghEneThk_GetOutSideKomaNum(void);
u8 sghEneThk_DiceShake(u8 *a0 , u8 a1 , u8 a2 );
void sghEneThk_IsKoma(void *a0, signed int a1);
static void __sghEneThk_GetGoalByAddSai(void *a0 , void *a1 , unsigned int a2 , int a3 );
void __sghEneThk_GetGoalOrNonGoal(void *a0 , void *a1 , unsigned int a2 , int a3 );
void sghEneThk_GetActIsPossible(void *a0 , void *a1 , unsigned int a2 );
void __sghEneThk_GetSafePos(u8 *output);
static signed int __sghEneThk_MarkingBefore(unsigned char pos_);
static signed int __sghEneThk_MarkingAfter(unsigned char pos_, unsigned char spots_);
static signed int __sghEneThk_GetMostScoreInInside(unsigned char spots_);
static void __sghEneThk_GetActIsMostScoreInInside(void *out_, unsigned char spots_);


unsigned int sghEneThk_ScoreInit(void) {
    s32 a0;
    s32 v1;
    s32 v0;

    a0 = 0x14;
    v1 = 0xc8;
    *(u32 *)gaScoreList = 0x1b58;
    gaScoreList[1] = a0;
    gaScoreList[2] = 0x190;
    a0 = -0x1f4;
    gaScoreList[3] = v1;
    gaScoreList[4] = 0x1f4;
    gaScoreList[5] = 0x64;
    gaScoreList[6] = -0x32;
    gaScoreList[7] = 0x32;
    gaScoreList[8] = -0x5dc;
    gaScoreList[9] = 0x14;
    gaScoreList[0xa] = -0x3e8;
    v0 = 1;
    gaScoreList[0xb] = a0;
    gaScoreList[0xc] = a0;
    gaScoreList[0xd] = -0x64;
    gaScoreList[0xe] = -0xa;
    gaScoreList[0xf] = v1;
    gaScoreList[0x10] = 0x5dc;
    gaScoreList[0x11] = 0;
    gaScoreList[0x12] = -0x2710;
    gaScoreList[0x13] = v0;
    gaScoreList[0x14] = 2;
    gaScoreList[0x15] = v0;
    gaScoreList[0x16] = 3;
    gaScoreList[0x17] = 0;
    gaScoreList[0x18] = 0;
    gaScoreList[0x19] = v0;
    gaScoreList[0x1a] = v0;
    return v0;
}

/* sghEneThk_SetActList @ 0x20A6B0 .. 0x20A6D4 (0x24 bytes) */
/*
 * dcomp notes:
 *   stack: 4-byte aggregate copy in 1-byte chunks at 0x20a6d0
 *   declaration vs inferred signature: return void vs inferred u8
 */



void sghEneThk_SetActList(void *a0 /* r4 */) {
    struct __copy_u8_4 { u8 b[4]; };

    *(struct __copy_u8_4 *)gActlist = *(struct __copy_u8_4 *)a0;
    return;
}

u8 sghEneThk_GetActList(u8 *a0 /* r4 */) {
    struct __copy_u8_4 { u8 b[4]; };

    *(struct __copy_u8_4 *)a0 = *(struct __copy_u8_4 *)gActlist;
    return;
}

void sghEneThk_SetPlayerID(unsigned char playerID) {
    gEnemyData[0] = playerID;
    gEnemyData[1] = (playerID == 0) ? sghEneThk_SetPlayerID_T : sghEneThk_SetPlayerID_F;
}



void sghEneThk_SetMap(SghMap *maplist_) {
    *(SghMap *)(gEnemyData + 2) = maplist_[0];
    *(SghMap *)(gEnemyData + 0x22) = maplist_[1];
}


void sghEneThk_ThinkNomal(void *a0, struct dw_2799695_fields *dice_) {
    u8 *output = (u8 *)a0;
    u8 actlist[4] __attribute__((aligned(4))) = {0};
    s32 xt0;
    u8 sai0;
    u8 sai1;
    struct Pair { u8 b[2]; };
    struct Quad { u8 b[4]; };
    s8 second[4];
    s32 score0;
    u8 sai[2];

    actlist[0] = 0;
    actlist[2] = 0;
    score0 = __sghEneThk_GetMostScoreInInside(dice_->spots[0]);
    if (score0 < __sghEneThk_GetMostScoreInInside(dice_->spots[1])) {
        sai0 = (u8)dice_->spots[0];
        sai1 = dice_->spots[1];
    } else {
        sai0 = dice_->spots[1];
        sai1 = dice_->spots[0];
    }
    __sghEneThk_GetActIsMostScoreInInside(actlist, sai0);
    {
        MapPairN maplist = {0};

        u32 dst = (u32)sai;
        u32 src = (u32)actlist;

        sai0 = gEnemyData[0];
        *(struct H *)dst = *(struct H *)src;
        {
            MapPairN evalmap = {0};

            sghMap_Eval(&evalmap, 2 + gEnemyData, sai[1], sai[0], sai0);
            maplist = evalmap;
        }
        *(SghMapN *)(gEnemyData + 2) = maplist.m[0];
        *(SghMapN *)(0x22 + gEnemyData) = maplist.m[1];
    }
    {
        __sghEneThk_GetActIsMostScoreInInside(second, sai1);
        *(struct Pair *)(actlist + 2) = *(struct Pair *)second;
    }
    *(struct Quad *)output = *(struct Quad *)((s32)actlist);
}
void sghEneThk_ThinkOutSideOnce(void *a0, struct dw_2799695_fields *dice_) {
    u8 *output = (u8 *)a0;
    struct Pair { u8 b[2]; };
    struct Quad { u8 b[4]; };
    int i;
    u8 diceOK_num = 0;
    u8 spotsOK[2] = {0};
    u8 spotsNG[2] = {0};
    u8 actlist[4] __attribute__((aligned(4))) = {0};
    u8 ng1[2];
    u8 ng2[2];
    u8 sai1a[2];
    u8 sai2a[2];
    PosList tmp = {0};
    PosList list;
    u8 *okp;
    u8 *ngp;
    u8 sai0;
    u8 sai1;
    s32 score0;

    list = gINIT_POS_LIST;
    actlist[0] = 0;
    actlist[2] = 0;
    list.pos[0] = 0;
    i = 0;
    okp = spotsOK;
    ngp = spotsNG;
    for (; i < 2; i++) {
        sghEneThk_GetActIsPossible(&tmp, &list, dice_->spots[i]);
        if (tmp.pos[0] != 0xff) {
            *okp++ = dice_->spots[i];
            diceOK_num++;
        } else {
            *ngp++ = dice_->spots[i];
        }
    }
    switch (diceOK_num) {
    case 0:
        break;
    case 1:
        actlist[0] = spotsOK[0];
        {
            MapPairN maplist = {0};
            u32 dst = (u32)sai1a;
            u32 src = (u32)actlist;
            u8 e0;
            e0 = gEnemyData[0];
            *(struct H *)dst = *(struct H *)src;
            DoEval(&maplist, sai1a, e0);
            *(SghMapN *)(gEnemyData + 2) = maplist.m[0];
            *(SghMapN *)(0x22 + gEnemyData) = maplist.m[1];
        }
        __sghEneThk_GetActIsMostScoreInInside(ng1, spotsNG[0]);
        *(struct Pair *)(actlist + 2) = *(struct Pair *)ng1;
        break;
    case 2:
        score0 = __sghEneThk_GetMostScoreInInside(dice_->spots[0]);
        if (score0 < __sghEneThk_GetMostScoreInInside(dice_->spots[1])) {
            sai0 = dice_->spots[0];
            sai1 = dice_->spots[1];
        } else {
            sai0 = dice_->spots[1];
            sai1 = dice_->spots[0];
        }
        actlist[0] = sai0;
        {
            MapPairN maplist = {0};
            u32 dst = (u32)sai2a;
            u32 src = (u32)actlist;
            u8 e0;
            e0 = gEnemyData[0];
            *(struct H *)dst = *(struct H *)src;
            DoEval(&maplist, sai2a, e0);
            *(SghMapN *)(gEnemyData + 2) = maplist.m[0];
            *(SghMapN *)(0x22 + gEnemyData) = maplist.m[1];
        }
        __sghEneThk_GetActIsMostScoreInInside(ng2, sai1);
        *(struct Pair *)(actlist + 2) = *(struct Pair *)ng2;
        break;
    }
    *(struct Quad *)output = *(struct Quad *)actlist;
}
void sghEneThk_ThinkOutSide(void *outputArg, void *diceArg) {
    u8 *output=(u8*)outputArg;
    u32 dice=(u32)diceArg;
    s32 i;
    u8 *cursor;
    u8 *current;
    u8 *second;
    u8 actions[4] __attribute__((aligned(4)))={0};
    u8 possible[25] __attribute__((aligned(16)))={0};
    u8 positions[32] __attribute__((aligned(16)));
    struct Pair {u8 b[2];};
    struct Quad {u8 b[4];};
    {
        u32 source=(u32)&gINIT_POS_LIST;
        u32 destination=(u32)positions;
        u_long128 quad=*(volatile u_long128*)source;
        u64 tail=*(u64*)(source+16);
        u8 last=*(u8*)(source+24);
        *(u_long128*)destination=quad;
        *(u64*)(destination+16)=tail;
        *(u8*)(destination+24)=last;
    }
    i=0;
    second=actions+2;
    cursor=actions;
    actions[0]=0;
    *second=0;
    positions[0]=0;
    do {
        u32 value;
        current=(u8*)(dice+i);
        sghEneThk_GetActIsPossible(possible,positions,*current);
        if (possible[0]!=255) value=*current;
        else value=0;
        *cursor=value;
        i++;
        cursor+=2;
    } while(i<2);
    if (actions[0]==0 && *second!=0) {
        u8 temp[2] __attribute__((aligned(8)))={0};
        u32 source=(u32)actions;
        u32 temporary=(u32)temp;
        *(s16*)temporary=*(s16*)source;
        *(struct Pair*)source=*(struct Pair*)second;
        *(struct Pair*)second=*(struct Pair*)temporary;
    }
    *(struct Quad*)output=*(struct Quad*)actions;
}

u8 sghEneThk_GetOutSideKomaNum(void) {
    u32 v1;
    u8 *v0;

    v1 = *(u8 *)gEnemyData;
    v0 = gEnemyData;
    v1 = (u32)v1 << 5;
    return *(u8 *)(((u8 *)(u8 *)((u8 *)gEnemyData + v1) + 2));
}

u8 sghEneThk_DiceShake(u8 *a0 /* r4 */, u8 a1 /* r5 */, u8 a2 /* r6 */) {
    u8 s1;
    u32 v1;
    u32 v0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));
    struct __copy_u8_2 { u8 b[2]; };

    v1 = a1;
    s1 = a2;
    if (v1 == 0) {
        v0 = rand();
        v1 = 6;
        v1 = (s32)v0 % (s32)(6);
        v1 = v1 + 1;
    }
    *(u8 *)((u8 *)&stackFrame_3C[0]) = v1;
    v1 = s1;
    if (v1 == 0) {
        v0 = rand();
        v1 = 6;
        v1 = (s32)v0 % (s32)(6);
        v1 = v1 + 1;
    }
    *(u8 *)((u8 *)&stackFrame_3C[1]) = v1;
    v1 = (u32)((u8 *)&stackFrame_3C[0]);
    *(struct __copy_u8_2 *)(u8 *)a0 = *(struct __copy_u8_2 *)((u8 *)&stackFrame_3C[0]);
    return;
}

void sghEneThk_IsKoma(void *a0, signed int a1) {
    s32 row;
    s32 index;
    u_long128 quad;
    u64 tail;
    s32 enemy;
    u32 value;
    struct Positions { s8 values[25]; } positions __attribute__((aligned(16)));

    value = (u32)&gINIT_POS_LIST;
    row = (u32)&positions;
    quad = *(volatile u_long128 *)value;
    tail = *(u64 *)(value + 16);
    value = *(u8 *)(value + 24);
    *(u_long128 *)row = quad;
    *(u64 *)(row + 16) = tail;
    *(u8 *)(row + 24) = value;
    if (a1 != 0) value = gEnemyData[0];
    else value = gEnemyData[1];
    enemy = (u8)value;
    {
        u8 *row;
        u8 *out;
        enemy <<= 5;
        row = (u8 *)((u32)gEnemyData + enemy + 2);
        index = 1;
        out = (u8 *)&positions;
        do {
            value = *(u8 *)(row + index);
            if ((s32)value > 0) {
                if (a1 != 0) value = index;
                else value = 25 - index;
                *out++ = value;
            }
            index++;
        } while (index < 25);
    }
    {
        s8 *source = positions.values;
        a1 = 25;
        do {
            value = *source;
            a1--;
            *(u8 *)a0 = value;
            source++;
            a0 = (u8 *)a0 + 1;
        } while (a1 > 0);
    }
}





static void __sghEneThk_GetGoalByAddSai(void *a0 /* r4 */, void *a1 /* r5 */, unsigned int a2 /* r6 */, int a3 /* r7 */) {
    s32 row;
    s32 index;
    u_long128 quad;
    u64 tail;
    s32 enemy;
    u32 value;
    struct Positions { s8 values[25]; } positions __attribute__((aligned(16)));

    value = (u32)&gINIT_POS_LIST;
    row = (u32)&positions;
    quad = *(volatile u_long128 *)value;
    tail = *(u64 *)(value + 16);
    value = *(u8 *)(value + 24);
    *(u_long128 *)row = quad;
    *(u64 *)(row + 16) = tail;
    *(u8 *)(row + 24) = value;
    if (a3 != 0) value = gEnemyData[0];
    else value = gEnemyData[1];
    enemy = (u8)value;
    {
        u8 *row;
        u8 *out;
        u8 *list = (u8 *)a1;
        u32 pos;
        enemy <<= 5;
        row = (u8 *)((u32)gEnemyData + enemy + 2);
        index = 0;
        if (list[0] != 0xff) {
            out = (u8 *)&positions;
            do {
                pos = list[index];
                value = *(u8 *)(row + pos);
                if ((s32)value > 0) {
                    value = pos + a2;
                    if (value > 0x12) {
                        if (value <= 0x18) {
                            if (a3 != 0) value = pos;
                            else value = 25 - pos;
                            *out++ = value;
                        }
                    }
                }
                index++;
            } while (list[index] != 0xff);
        }
    }
    {
        s8 *source = positions.values;
        a1 = (void *)25;
        do {
            value = *source;
            a1 = (u8 *)a1 - 1;
            *(u8 *)a0 = value;
            source++;
            a0 = (u8 *)a0 + 1;
        } while ((s32)a1 > 0);
    }
}





void __sghEneThk_GetGoalOrNonGoal(void *a0 /* r4 */, void *a1 /* r5 */, unsigned int a2 /* r6 */, int a3 /* r7 */) {
    s32 row;
    s32 index;
    u_long128 quad;
    u64 tail;
    s32 enemy;
    u32 value;
    struct Positions { s8 values[25]; } positions __attribute__((aligned(16)));

    value = (u32)&gINIT_POS_LIST;
    row = (u32)&positions;
    quad = *(volatile u_long128 *)value;
    tail = *(u64 *)(value + 16);
    value = *(u8 *)(value + 24);
    *(u_long128 *)row = quad;
    *(u64 *)(row + 16) = tail;
    *(u8 *)(row + 24) = value;
    if (a3 != 0) value = gEnemyData[0];
    else value = gEnemyData[1];
    enemy = (u8)value;
    {
        u8 *row;
        u8 *out;
        u8 *list = (u8 *)a1;
        u8 pos;
        enemy <<= 5;
        row = (u8 *)((u32)gEnemyData + enemy + 2);
        index = 0;
        if (list[0] != 0xff) {
            out = (u8 *)&positions;
            do {
                pos = list[index];
                if (a2 != 0 && pos < 0x13) goto next;
                if (a2 == 0 && pos > 0x12) goto next;
                value = *(u8 *)(row + pos);
                if ((s32)value > 0) {
                    if (a3 != 0) value = pos;
                    else value = 25 - pos;
                    *out++ = value;
                }
            next:
                index++;
            } while (list[index] != 0xff);
        }
    }
    {
        s8 *source = positions.values;
        a1 = (void *)25;
        do {
            value = *source;
            a1 = (u8 *)a1 - 1;
            *(u8 *)a0 = value;
            source++;
            a0 = (u8 *)a0 + 1;
        } while ((s32)a1 > 0);
    }
}

void sghEneThk_GetActIsPossible(void *a0 /* r4 */, void *a1 /* r5 */, unsigned int a2 /* r6 */) {
    u8 positions[32] __attribute__((aligned(16)));
    u8 *pList_;
    u32 spots_;
    u8 *output;
    s32 i;
    u32 destination;
    u_long128 quad;
    u64 empty;
    u32 map;
    u32 initial;
    u32 base;
    u32 e0;
    u32 e1;
    u32 first;
    u32 terminal;
    u8 *rowA;
    u8 *rowB;
    u32 pos;

    output = (u8 *)a0;
    pList_ = (u8 *)a1;
    spots_ = a2;
    initial = (u32)&gINIT_POS_LIST;
    destination = (u32)positions;
    quad = *(volatile u_long128 *)initial;
    base = (u32)gEnemyData;
    empty = *(u64 *)(initial + 16);
    i = 0;
    map = *(u8 *)(initial + 24);
    *(u_long128 *)destination = quad;
    *(u64 *)(destination + 16) = empty;
    *(u8 *)(destination + 24) = map;
    e0 = gEnemyData[0];
    first = pList_[0];
    rowA = (u8 *)(base + (e0 << 5)) + 2;
    e1 = gEnemyData[1];
    rowB = (u8 *)(base + (e1 << 5)) + 2;
    while (pList_[i] != 0xff) {
        pos = pList_[i];
        terminal = pos + spots_;
        if (terminal <= 0x18) {
            if (rowA[pos] > 0 && rowB[0x19 - terminal] <= 1) {
                *(u8 *)destination = pos;
                destination++;
            }
        }
        i++;
    }
    {
        s8 *source = (s8 *)positions;
        s32 remaining = 25;
        do {
            *output++ = *source++;
        } while (--remaining > 0);
    }
}
void __sghEneThk_GetSafePos(u8 *output) {
    u8 positions[32] __attribute__((aligned(16)));
    s32 i;
    u32 count;
    u32 destination;
    u_long128 quad;
    u64 empty;
    u32 map;
    u32 initial;
    initial = (u32)&gINIT_POS_LIST;
    destination = (u32)positions;
    quad = *(volatile u_long128 *)initial;
    empty = *(u64 *)(initial + 16);
    count = 0;
    map = *(u8 *)(initial + 24);
    i = 1;
    *(u_long128 *)destination = quad;
    *(u64 *)(destination + 16) = empty;
    *(u8 *)(destination + 24) = map;
    map = (u32)gEnemyData + (gEnemyData[1] << 5) + 2;
    empty = *(u8 *)map == 0;
    do {
        if (*(u8 *)(map + i) == 0) count++;
        else { count = 0; empty = 0; }
        if (count > 6 || empty) {
            *(u8 *)destination = 0;
            destination++;
        }
        i++;
    } while (i < 25);
    {
        s8 *source = (s8 *)positions;
        s32 remaining = 25;
        do {
            *output++ = *source++;
        } while (--remaining > 0);
    }
}
static signed int __sghEneThk_MarkingBefore(unsigned char pos_) {
    s32 score;
    PosList list;
    PosList poslist;
    PosList copy;
    PosList positions;
    PosList tmp;
    u8 *map;
    u8 *row;
    s32 i;
    u8 *p;
    s32 ok;
    s32 bonus;

    score = 0;
    row = gEnemyData + (gEnemyData[0] << 5);
    switch (row[(u8)pos_ + 2]) {
    case 1:
        score += gaScoreList[5];
        break;
    case 2:
        score += gaScoreList[6];
        break;
    default:
        score += gaScoreList[7];
    }
    tmp = gINIT_POS_LIST;
    list = tmp;
    poslist = tmp;
    poslist.pos[0] = pos_;
    __sghEneThk_GetGoalOrNonGoal(&list, &poslist, 1, 1);
    if (list.pos[0] != 0xff) bonus = gaScoreList[8];
    else bonus = 0;
    score += bonus;
    positions = gINIT_POS_LIST;
    p = positions.pos;
    map = gEnemyData + (gEnemyData[0] << 5) + 2;
    for (i = 1; i < 25; i++) {
        if (map[i] > 0) {
            *p++ = i;
        }
    }
    copy = positions;
    ok = MbSafe(copy.pos, pos_, gEnemyData + (gEnemyData[0] << 5) + 2);
    if (ok) bonus = gaScoreList[0xf];
    else bonus = 0;
    score += bonus;
    return score;
}


/* __sghEneThk_MarkingAfter @ 0x2090B0 .. 0x2095D0 (0x520 bytes, frame 0x1e0) */
/*
 * dcomp notes:
 *   quad: a1: 128-bit web split from its scalar uses
 *   quad: a2: 128-bit web split from its scalar uses
 *   quad: a3: 128-bit web split from its scalar uses
 *   quad: t0: 128-bit web split from its scalar uses
 *   stack: address of the slot at 0xe0 escapes at 0x2091a8
 *   delay: subu at 0x2091b8 writes a register its branch at 0x2091b4 reads
 *   stack: address of the slot at 0x1c0 escapes at 0x209208
 *   stack: address of the slot at 0x1a0 escapes at 0x209290
 *   stack: address of the slot at 0x1a0 escapes at 0x2092a8
 *   delay: lui at 0x2092dc writes a register its branch at 0x2092d8 reads
 *   stack: address of the slot at 0xc0 escapes at 0x209330
 *   stack: address of the slot at 0x180 escapes at 0x209398
 *   stack: address of the slot at 0x80 escapes at 0x209480
 *   stack: address of the slot at 0x160 escapes at 0x209480
 *   stack: address of the slot at 0xa0 escapes at 0x209480
 *   stack: address of the slot at 0x140 escapes at 0x2094e0
 *   stack: address of the slot at 0x100 escapes at 0x209550
 *   stack: address of the slot at 0x120 escapes at 0x209550
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x2091ec
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x2091f4
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x2091f8
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x209378
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x20937c
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x209380
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x209444
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x209448
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x20944c
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x209460
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x209464
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x209468
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x2094c0
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x2094c4
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x2094c8
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x20952c
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x209530
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x209534
 *   stack: 16-byte aggregate copy in 16-byte chunks at 0x209544
 *   stack: 8-byte aggregate copy in 8-byte chunks at 0x209548
 *   stack: 1-byte aggregate copy in 1-byte chunks at 0x20954c
 *   cfg: loop body is not one contiguous region: .L002091A8
 *   cfg: loop body is not one contiguous region: .L00209238
 *   cfg: loop body is not one contiguous region: .L002092A8
 *   cfg: kept branch: 0x2092a8 if (..) goto .L002092C0
 *   cfg: loop body is not one contiguous region: .L00209330
 *   cfg: loop body is not one contiguous region: .L00209398
 *   cfg: loop body is not one contiguous region: .L00209480
 *   declaration vs inferred signature: return signed int vs inferred u32
 */








static signed int __sghEneThk_MarkingAfter(unsigned char pos_, unsigned char spots_) {
    u8 *row0;
    s32 xt1;
    int score;
    PosList L1;
    PosList L2;
    PosList L3;
    PosList L4;
    PosList L5;
    PosList L6;
    PosList L7;
    PosList L8;
    PosList L11;
    PosList L9;
    PosList L10;
    PosList L12;
    u8 *pMapEne;
    u8 *r;
    u8 *q;
    u8 *pm;
    int list_num;
    u8 e;
    int i;
    int j;
    int t;

    row0 = gEnemyData + ((unsigned)gEnemyData[0] << 5);
    pMapEne = gEnemyData + ((unsigned)gEnemyData[1] << 5) + 2;
    score = 0;
    switch (*(pos_ + row0 + 2)) {
    case 0:
        score += gaScoreList[0xb] + gaScoreList[0xe] * pos_;
        if (pMapEne[25 - pos_] == 1) {
            q = L8.pos;
            score += gaScoreList[0];
            L8 = gINIT_POS_LIST;
            if (gALLPOS[0] != 0xff) { r = gALLPOS; do {
                e = *r;
                if (pMapEne[e] == 1) {
                    *q++ = 25 - e;
                }
                r++;
            } while (*r != 0xff); }
            L1 = L8;
            q = L1.pos;
            list_num = 0;
            while ((L1.pos[0]) != 0xff) list_num++;
            i = 0;
            if ((u8)(L1.pos[0]) != 0xff) do {
                if (*q == pos_) break;
                q++;
                i++;
            } while (*q != 0xff);
            score += gaScoreList[3] * (((list_num - i)));
        }
        L2 = gINIT_POS_LIST;
        __sghEneThk_GetSafePos(L2.pos);
        q = L2.pos;
        if (L2.pos[0] != 0xff) do {
            if (*q == pos_) {
                score += gaScoreList[9];
                break;
            }
            q++;
        } while (*q != 0xff);
        if (*(pos_ + row0 + 2) > 1) {
            score += gaScoreList[0xc];
        }
        break;
    case 1:
        pm = gEnemyData + (gEnemyData[0] << 5) + 2;
        L9 = gINIT_POS_LIST;
        q = L9.pos;
        if (gALLPOS[0] != 0xff) { r = gALLPOS; do {
            e = *r;
            if (pm[e] == 1) {
                *q++ = e;
            }
            r++;
        } while (*r != 0xff); }
        q = L3.pos;
        L3 = L9;
        j = 0;
        if (L3.pos[0] != 0xff) do {
            if (*q == (u8)pos_) break;
            q++;
            j++;
        } while (*q != 0xff);
        score += j * gaScoreList[3];
        if (*(row0 + pos_ + 2) == 1) {
            score += gaScoreList[4];
        }
        break;
    default:
        score += gaScoreList[7];
        if (*(row0 + pos_ + 2) == 1) {
            score += gaScoreList[4];
        }
    }
    L11 = gINIT_POS_LIST;
    L4 = L11;
    L4.pos[0] = pos_;
    L10 = L11;
    q = L4.pos;
    r = L10.pos;
    if (L4.pos[0] != 0xff) do {
        e = *q;
        if ((u8)spots_ + e == 0x13) {
            *r++ = 0;
        }
        q++;
    } while (*q != 0xff);
    L5 = L10;
    if (L5.pos[0] != 0xff) t = gaScoreList[0x10];
    else t = 0;
    score += t;
    L12 = gINIT_POS_LIST;
    L6 = L12;
    L7 = L12;
    L6.pos[0] = pos_;
    __sghEneThk_GetGoalByAddSai(&L7, &L6, (u8)spots_, 1);
    if (L7.pos[0] != 0xff) t = gaScoreList[0xa];
    else t = 0;
    score += t;
    i = 19 - (u8)pos_;
    if (i < 0) t = 0;
    else t = i * gaScoreList[0x11];
    score += t;
    return (u32)score;
}


static signed int __sghEneThk_GetMostScoreInInside(unsigned char spots_) {
    int aScore[25] = {0};
    int iMaxScore;
    int i;
    unsigned char pos;
    unsigned int score_cnt;
    PosList list;
    PosList tmp;
    PosList a;
    PosList b;
    PosList t0;
    u8 *p;
    u8 *row;
    int score;
    u8 *q;

    iMaxScore = gaScoreList[0x12];
    tmp = gINIT_POS_LIST;
    row = gEnemyData + (gEnemyData[0] << 5) + 2;
    score_cnt = 0;
    p = tmp.pos;
    for (i = 1; i < 25; i++) {
        if (row[i] > 0) {
            *p++ = i;
        }
    }
    list = tmp;
    i = 0;
    q = list.pos;
    if (list.pos[0] != 0xff) do {
        pos = *q;
        score = 0;
        if (gEnemyData[(gEnemyData[0] << 5) + 2 + pos] <= 0) {
            score = gaScoreList[0x12];
        } else {
            t0 = gINIT_POS_LIST;
            a = t0;
            b = t0;
            a.pos[0] = pos;
            sghEneThk_GetActIsPossible(&b, &a, spots_);
            if (b.pos[0] == 0xff) {
                score = gaScoreList[0x12];
            } else {
                score += __sghEneThk_MarkingBefore(pos);
                score += __sghEneThk_MarkingAfter(pos, spots_);
            }
        }
        aScore[score_cnt] = score;
        q++;
        score_cnt++;
        i++;
    } while (*q != 0xff);
    for (i = 0; i < score_cnt; i++) {
        if (iMaxScore < aScore[i]) {
            iMaxScore = aScore[i];
        }
    }
    return iMaxScore;
}


static void __sghEneThk_GetActIsMostScoreInInside(void *out_, unsigned char spots_) {
    struct Pair2 { u8 b[2]; };
    struct Pair2 result = {0};
    PosList list;
    int aScore[25] = {0};
    PosList tmp;
    PosList a;
    PosList b;
    PosList t0;
    int iMaxIdx;
    int iMaxScore;
    int i;
    unsigned char pos;
    unsigned int score_cnt;
    u8 *p;
    u8 *row;
    int score;
    u8 *q;

    iMaxIdx = 0;
    iMaxScore = gaScoreList[0x12];
    tmp = gINIT_POS_LIST;
    row = gEnemyData + (gEnemyData[0] << 5) + 2;
    score_cnt = 0;
    p = tmp.pos;
    for (i = 1; i < 25; i++) {
        if (row[i] > 0) {
            *p++ = i;
        }
    }
    list = tmp;
    i = 0;
    q = list.pos;
    if (list.pos[0] != 0xff) do {
        pos = *q;
        score = 0;
        if (gEnemyData[(gEnemyData[0] << 5) + 2 + pos] <= 0) {
            score = gaScoreList[0x12];
        } else {
            t0 = gINIT_POS_LIST;
            a = t0;
            b = t0;
            a.pos[0] = pos;
            sghEneThk_GetActIsPossible(&b, &a, spots_);
            if (b.pos[0] == 0xff) {
                score = gaScoreList[0x12];
            } else {
                score += __sghEneThk_MarkingBefore(pos);
                score += __sghEneThk_MarkingAfter(pos, spots_);
            }
        }
        aScore[score_cnt] = score;
        q++;
        score_cnt++;
        i++;
    } while (*q != 0xff);
    for (i = 0; i < score_cnt; i++) {
        if (aScore[i] >= iMaxScore) {
            iMaxScore = aScore[i];
            iMaxIdx = i;
        }
    }
    if (iMaxScore != gaScoreList[0x12]) {
        result.b[1] = list.pos[iMaxIdx];
        result.b[0] = spots_;
    } else {
        result.b[1] = 0;
        result.b[0] = 0;
    }
    *(struct Pair2 *)out_ = result;
}
