#include "common.h"

/* __sghMode_TutorialInit @ 0x20CB70 .. 0x20CBA4 (0x34 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */

extern void *sghGetGameInfo(void);
extern void *sghPad_GetPadInfo(void);

/* __sghMode_GameScore @ 0x20CBB0 .. 0x20CC18 (0x68 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   fpu: mtc1 reinterprets zero at 0x20cbc8
 *   return without a value in a non-void function
 */

extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void sghTime_SetWait(signed int);
extern void sghPad_Init(void);
extern u8 MdlMng[];

/* __sghMode_GameResult @ 0x0 */
extern void *GetMGPrcStatus(void);
extern signed int SND_Play2D(signed int, signed short, signed short);
extern unsigned int ChangeAnimParam(void *, signed int, float);
extern void sghTime_SetWait(signed int);
extern u8 MdlMng[];


extern void *sghMap_GetMainTblMap(void);
extern u32 sghDice_IsUsed(void);
enum JudgePlayer { JudgePlayer0, JudgePlayer1 };


extern void sghEneThk_GetActList(u8 *);
extern void sghEneThk_SetActList(void *);
extern unsigned char sghDice_EraseSpots(unsigned char);
extern void sghMarker_MarkerClear();
extern void sghKoma_UpdatePos(void);


/* __sghMode_KomaMoveInit @ 0x20CF20 .. 0x20CFCC (0xac bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x38 escapes at 0x20cf40
 *   stack: address of the slot at 0x3c escapes at 0x20cfa0
 *   return without a value in a non-void function
 */

extern void sghDice_GetDiceSpotsList(u8 *);
extern void sghMarker_SetTgtPos(unsigned char, unsigned char, unsigned char);
extern void sghKoma_SetMoveAnimeInit(unsigned char, unsigned char, unsigned char);
extern void sghMap_Update(unsigned char, unsigned char);
extern unsigned char sghDice_UseSpots(unsigned char);
extern void sghEneThk_SetActList(void *);



extern void sghEneThk_SetMap(void *);
extern void sghEneThk_SetPlayerID(unsigned char);
extern void sghEneThinking(void *, void *);
extern void sghDice_SetDiceSpots(unsigned char, unsigned char);


extern u32 sghPad_GetCurInfo();
extern void sghEneThk_GetActIsPossible(void *, void *, unsigned int);
extern void sghMarker_MarkerClear();
extern void sghMarker_SetActPossible(unsigned char, unsigned char, unsigned char, unsigned char);
typedef struct ChoiceDicePair { u8 b[2]; } ChoiceDicePair;


extern void sghEneThk_SetMap(void *);
extern void sghEneThk_SetPlayerID(unsigned char);
extern u32 sghEneThk_GetOutSideKomaNum(void);
extern void sghKoma_SetAnime(unsigned char,unsigned char,unsigned char);
extern void sghEneThk_IsKoma(void *,signed int);


/* __sghMode_DiceEnd @ 0x20D6A0 .. 0x20D774 (0xd4 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x3c escapes at 0x20d6c0
 *   stack: address of the slot at 0x3d escapes at 0x20d740
 */

extern void sghEneThk_DiceShake(void *, unsigned char, unsigned char);
extern void sghDice_SetDiceSpots(unsigned char, unsigned char);
extern void sghDice_SetMdlSpots(unsigned char, unsigned char);


/* __sghMode_DiceInit @ 0x20D780 .. 0x20D7E8 (0x68 bytes, frame 0x20) */

extern void sghDice_SetAnimeInit();
extern void sghDice_CastStart();

/* __sghMode_SelectEnemy @ 0x20DA30 .. 0x20DA68 (0x38 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */


extern void *sghMap_GetMainTblMap(void);
extern unsigned int sghEneThk_ScoreInit(void);

/* __sghMode_Init @ 0x20DA70 .. 0x20DBAC (0x13c bytes, frame 0x50) */
/*
 * dcomp notes:
 *   fpu: float literal 0x00000000 at 0x20dac8
 *   cfg: kept goto: 0x20db70 -> .L0020DB90
 */

extern void *GetMGPrcStatus(void);
extern void sghMap_MainInit(void);
extern void sghKoma_UpdatePos(void);
extern void sghDice_Init(void);
extern void sghKoma_Init(void);

extern signed int sghTime_GetWait(void);

extern u32 gSGH_ModeFnc[];


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void sghMode_Execute(void);
static void __sghMode_Init(void);
static u32 __sghMode_SelectEnemy(void);
static void __sghMode_OrderPlayerInit(void);
void __sghMode_OrderPlayerEnd(void);
static u32 __sghMode_MainInit(void);
static void __sghMode_DiceInit(void);
void __sghMode_DiceEnd(void);
void __sghMode_UserChoiceKomaInit(void);
void __sghMode_UserChoiceDiceInit(void);
void __sghMode_AIThink(void);
void __sghMode_AIAct(void);
static u32 __sghMode_KomaMoveInit(void);
void __sghMode_KomaMoveEnd(void);
void __sghMode_JudgeGame(void);
void __sghMode_GameResult(void);
static u32 __sghMode_GameScore(void);
static u32 __sghMode_TutorialInit(void);

void sghMode_Execute(void) {
    u8 *game = sghGetGameInfo();
    sghTime_GetWait();
    __asm__ volatile(
        ".set noreorder\n"
        "daddu $4, $2, $zero\n"
        ".word 0x1880000a\n"
        "nop\n"
        "lbu $5, 1(%0)\n"
        "addiu $3, $zero, 1\n"
        ".word 0x10a30004\n"
        "nop\n"
        "jal sghTime_SetWait\n"
        "addiu $4, $4, -1\n"
        "nop\n"
        ".word 0x1000000b\n"
        "nop\n"
        "1:\n"
        "lbu $4, 0(%0)\n"
        "la $3, gSGH_ModeFnc\n"
        "sll $4, $4, 2\n"
        "addu $3, $3, $4\n"
        "lw $3, 0($3)\n"
        ".word 0x10600003\n"
        "nop\n"
        "jalr $31, $3\n"
        "nop # %0\n"
        ".set reorder\n"
        :
        : "r"(game)
        : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13",
          "$14", "$15", "$31", "memory");
}

static void __sghMode_Init(void) {
    s32 a1;
    u8 *s3;
    u8 *s0;
    u8 *s2;
    s32 s1;
    u32 a0;
    s32 v1;
    u8 *v0;

    v0 = (u8 *)GetMGPrcStatus();
    s3 = v0;
    v0 = (u8 *)sghGetGameInfo();
    s0 = v0;
    sghMap_MainInit();
    sghKoma_UpdatePos();
    sghDice_Init();
    sghKoma_Init();
    s1 = 0;
    s2 = (u8 *)(MdlMng + 0x119c0);
    do {
        *(u8 *)(s2 + 2) = 0;
        *(u32 *)(s2 + 0x30) = 0;
        *(u32 *)(s2 + 0x34) = 0;
        a0 = (u32)s2;
        *(u32 *)(s2 + 0x38) = 0;
        ChangeAnimParam((void *)a0, 0, 0.0f);
        s1 = s1 + 1;
        s2 = (u8 *)(s2 + 0x1c0);
    } while (s1 < (s32)0x1e);
    a1 = 1;
    *(u8 *)((u8 *)&MdlMng + 0x14e42) = a1;
    v1 = 2;
    *(u8 *)((u8 *)&MdlMng + 0x15002) = a1;
    *(u8 *)((u8 *)&MdlMng + 0x174c2) = a1;
    *(u8 *)((u8 *)&MdlMng + 0x17682) = a1;
    *(u8 *)((u8 *)&MdlMng + 0x17142) = a1;
    *(u8 *)((u8 *)&MdlMng + 0x17302) = a1;
    a0 = *(u8 *)(s3 + 1);
    switch (a0) {
    case 0:
        *(u8 *)(s0 + 5) = 0;
        *(u8 *)(s0 + 6) = a1;
        break;
    case 1:
        *(u8 *)(s0 + 5) = 0;
        *(u8 *)(s0 + 6) = 0;
        break;
    case 2:
        v1 = 0x1a;
        *(u8 *)s0 = v1;
        return;
    }
    *(u8 *)(s0 + 4) = 0;
    v1 = 1;
    *(u8 *)s0 = v1;
    return;
}

static u32 __sghMode_SelectEnemy(void) {
    u8 *v0;
    u8 *s0;

    v0 = (u8 *)sghGetGameInfo();
    s0 = v0;
    sghMap_GetMainTblMap();
    v0 = (u8 *)sghEneThk_ScoreInit();
    *(u8 *)s0 = 3;
    return (u32)v0;
}


/* __sghMode_OrderPlayerInit @ 0x20D940 .. 0x20DA28 (0xe8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   stack: address of the slot at 0x28 escapes at 0x20d954
 *   stack: address of the slot at 0x2c escapes at 0x20d988
 *   stack: 2-byte aggregate copy in 1-byte chunks at 0x20d974
 *   cfg: kept branch: 0x20d984 if (..) goto .L0020DA10
 *   cfg: kept branch: 0x20d9d4 if (..) goto .L0020DA10
 */




static void __sghMode_OrderPlayerInit(void) {
    u8 *s0;
    u32 a1;
    u32 a0;
    u32 v1;
    u8 stackFrame_2C[4] __attribute__((aligned(4)));
    u8 stackFrame_28[4] __attribute__((aligned(8)));
    struct __copy_u8_2 { u8 b[2]; };

    s0 = (u8 *)sghGetGameInfo();
    sghDice_GetDiceSpotsList(((u8 *)&stackFrame_28[0]));
    v1 = (u32)((u8 *)&stackFrame_28[0]);
    a0 = 0xff;
    *(struct __copy_u8_2 *)((u8 *)&stackFrame_2C[0]) = *(struct __copy_u8_2 *)((u8
        *)&stackFrame_28[0]);
    v1 = *(u8 *)((u8 *)&stackFrame_2C[0]);
    a1 = ((u8 *)stackFrame_2C)[1];
    if (v1 == a0) {
        sghDice_SetAnimeInit(0, 0, (u8 *)((u8 *)&stackFrame_2C[0]));
        a0 = *(u8 *)(s0 + 4);
        v1 = 1;
        a0 = *(u8 *)((u32)&((u8 *)(s0 + 5))[a0]);
        if (a0 != v1) {
            goto _L0020DA10;
        }
        *(u8 *)s0 = (s32)(u8 *)(s32)5;
        sghDice_CastStart(0, 0);
    } else {
        v1 = (u8)a1;
        if (v1 == a0) {
            sghDice_SetAnimeInit(0, (s32)1);
            v1 = *(u8 *)(s0 + 4);
            a1 = 1;
            v1 = *(u8 *)((u32)&((u8 *)(s0 + 5))[v1]);
            if (v1 != a1) {
                goto _L0020DA10;
            }
            *(u8 *)s0 = (s32)(u8 *)(s32)5;
            sghDice_CastStart(0, a1);
        } else {
            _L0020DA10:;
            *(u8 *)s0 = 4;
        }
    }
    return;
}

void __sghMode_OrderPlayerEnd(void) {
    u32 first;
    u8 *game;
    u32 second;
    u32 value;
    u8 output[4] __attribute__((aligned(4)));
    u8 current[4] __attribute__((aligned(4)));
    u8 source[4] __attribute__((aligned(4)));
    struct DicePair { u8 b[2]; };
    game = (u8 *)sghGetGameInfo();
    sghDice_GetDiceSpotsList(source);
    second = (u32)&current[1];
    *(struct DicePair *)(u32)current = *(struct DicePair *)(u32)source;
    first = current[0];
    value = *(u8 *)second;
    if (first == 255) {
        sghEneThk_DiceShake(output, 0, 0);
        sghDice_SetDiceSpots(0, output[0]);
        sghDice_SetMdlSpots(0, output[0]);
        goto done;
    }
    if ((u8)value == 255) {
        u32 winner;
        sghEneThk_DiceShake(output, 0, 0);
        second = (u32)&output[1];
        sghDice_SetDiceSpots(1, *(u8 *)second);
        sghDice_SetMdlSpots(0, *(u8 *)second);
        __asm__ volatile(
            ".set noreorder\n"
            "lbu %0, 0(%1)\n"
            "andi $a0, %2, 0xff\n"
            "slt $at, %0, $a0\n"
            "beqz $at, 1f\n"
            "addiu %0, $zero, 1\n"
            "daddu %0, $zero, $zero\n"
            "1:\n"
            : "=&r"(winner)
            : "r"(second), "r"(first)
            : "a0", "at", "memory");
        game[4] = winner;
        goto done;
    }
    sghDice_GetDiceSpotsList(current);
    __asm__ volatile(
        ".set noreorder\n"
        ".word 0x93a50048\n"
        ".word 0x240300ff\n"
        ".word 0x10a30005\n"
        ".word 0x92040000\n"
        ".word 0x308400ff\n"
        ".word 0x14830004\n"
        ".word 0x00000000\n"
        ".word 0x00000000\n"
        ".word 0x10000001\n"
        ".word 0x00000000\n"
        :
        :
        : "memory");
done:
    return;
}

/* __sghMode_MainInit @ 0x20D7F0 .. 0x20D814 (0x24 bytes, frame 0x10) */
/*
 * dcomp notes:
 *   return without a value in a non-void function
 */



static u32 __sghMode_MainInit(void) {
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    *(u8 *)v0 = 8;
    return (u32)v0;
}

static void __sghMode_DiceInit(void) {
    u8 a1;
    s32 a0;
    u8 *s0;
    u32 v1;
    u8 *v0;

    v0 = (u8 *)sghGetGameInfo();
    a1 = *(u8 *)(v0 + 4);
    s0 = v0;
    sghDice_SetAnimeInit((s32)1, a1);
    v1 = *(u8 *)(s0 + 4);
    a0 = 1;
    v1 = *(u8 *)(((u32)(s32)((u8 *)v1 + (u32)(s0)) + 5));
    if (v1 == (u32)a0) {
        *(u8 *)s0 = (s32)(u8 *)(s32)0xa;
        a1 = *(u8 *)(s0 + 4);
        sghDice_CastStart(a0, a1);
    } else {
        *(u8 *)s0 = 9;
    }
    return;
}

void __sghMode_DiceEnd(void) {
    u8 a1;
    u8 *s0;
    u32 a0;
    s32 v1;
    u8 *v0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));

    v0 = (u8 *)sghGetGameInfo();
    s0 = v0;
    sghEneThk_DiceShake((void *)((u8 *)&stackFrame_3C[0]), 0, 0);
    a1 = *(u8 *)((u8 *)&stackFrame_3C[0]);
    sghDice_SetDiceSpots(0, a1);
    a1 = *(u8 *)(u8 *)((u8 *)&stackFrame_3C[0] + 0x1);
    sghDice_SetDiceSpots(1, a1);
    a1 = *(u8 *)((u8 *)&stackFrame_3C[0]);
    sghDice_SetMdlSpots(0, a1);
    a1 = ((u8 *)stackFrame_3C)[1];
    sghDice_SetMdlSpots(1, a1);
    a0 = 0x3e99999a;
    v1 = 1;
    *(u32 *)(MdlMng + 0x1724c) = 0x3e99999a;
    *(u32 *)(MdlMng + 0x1740c) = 0x3e99999a;
    a0 = *(u8 *)(s0 + 4);
    a0 = *(u8 *)((u32)&((u8 *)(s0 + 5))[a0]);
    switch (a0) {
    case 0:
        v0 = (u8 *)(s32)0xc;
        *(u8 *)s0 = (s32)v0;
        sghPad_Init();
        break;
    case 1:
        *(u8 *)s0 = 0x10;
    }
    return;
}
void __sghMode_UserChoiceKomaInit(void) {
    u8 *game;
    u8 *pad;
    u8 *current;
    u8 *map;
    struct ChoiceDice { u8 b[2]; } dice;
    u8 original[2] __attribute__((aligned(8)));
    game=(u8 *)sghGetGameInfo();
    pad=(u8 *)sghPad_GetPadInfo();
    current=(u8 *)sghPad_GetCurInfo();
    map=(u8 *)sghMap_GetMainTblMap();
    sghDice_GetDiceSpotsList(original);
    *(struct ChoiceDice *)(u32)&dice=*(struct ChoiceDice *)(u32)original;
    {
        u8 pieces[25] __attribute__((aligned(16)))={0};
        u8 possible[25] __attribute__((aligned(16)))={0};
        int valid;
        *(u32 *)(pad+4)=0;
        sghEneThk_SetMap(map);
        sghEneThk_SetPlayerID(game[4]);
        if(sghEneThk_GetOutSideKomaNum()!=0) {
            current[0]=0;
            current[1]=255;
            current[25]=1;
            valid=0;
            sghEneThk_GetActIsPossible(possible,current,dice.b[0]);
            if(possible[0]!=255) valid++;
            sghEneThk_GetActIsPossible(possible,current,dice.b[1]);
            if(possible[0]!=255) valid++;
            if(valid<=0) game[0]=18;
            else {
                int i;
                u8 *cursor;
                sghKoma_SetAnime(2,0,game[4]);
                i=0; cursor=dice.b;
                do {
                    if(*cursor!=255) sghMarker_SetActPossible((u8)i,0,*cursor,game[4]);
                    i++; cursor++;
                } while(i<2);
                game[0]=13;
            }
        } else {
            sghEneThk_IsKoma(pieces,1);
            valid=0;
            sghEneThk_GetActIsPossible(possible,pieces,dice.b[0]);
            if(possible[0]!=255) valid++;
            sghEneThk_GetActIsPossible(possible,pieces,dice.b[1]);
            if(possible[0]!=255) valid++;
            if(valid<=0) game[0]=18;
            else {
                s8 *source;
                u8 *destination;
                int count;
                source=(s8 *)pieces; count=25; destination=current;
                do { *destination=*source; count--; source++; destination++; } while(count>0);
                {
                    u8 *scan;
                    int total;
                    total=0; scan=pieces;
                    if(*scan!=255) do { scan++; total++; } while(*scan!=255);
                    current[25]=total;
                }
                game[0]=13;
                sghKoma_SetAnime(2,current[0],game[4]);
                {
                    u8 *cursor;
                    int i;
                    i=0; cursor=dice.b;
                    do {
                        if(*cursor!=255) sghMarker_SetActPossible((u8)i,current[0],*cursor,game[4]);
                        i++; cursor++;
                    } while(i<2);
                }
            }
        }
    }
}
void __sghMode_UserChoiceDiceInit(void) {
    u8 *game;
    u8 *pad;
    u32 selected;
    s32 validCount;
    s32 index;
    u8 *possibleTail;
    u8 *diceCursor;
    s32 modelOffset;
    u8 *validCursor;
    u8 *current;
    ChoiceDicePair dice;
    ChoiceDicePair original;
    game=(u8 *)sghGetGameInfo();
    pad=(u8 *)sghPad_GetPadInfo();
    current=(u8 *)sghPad_GetCurInfo();
    selected=pad[12];
    sghDice_GetDiceSpotsList(original.b);
    *(ChoiceDicePair *)(u32)&dice=*(ChoiceDicePair *)(u32)&original;
    validCount=0;
    {
        u8 possible[25]={0};
        u8 valid[25]={0};
        index=0;
        diceCursor=dice.b;
        modelOffset=0;
        validCursor=valid;
        possibleTail=possible+1;
        do {
            if(*diceCursor==255) {
                *(u8 *)((s32)((u8 *)MdlMng+(modelOffset+0x17140))+2)=1;
            } else {
                possible[0]=selected;
                *possibleTail=255;
                sghEneThk_GetActIsPossible(possible,possible,*diceCursor);
                if(possible[0]!=255) {
                    *validCursor=index;
                    ++validCount;
                    ++validCursor;
                }
            }
            ++index;
            ++diceCursor;
            modelOffset+=0x1c0;
        } while(index<2);
        valid[validCount]=255;
        current[0x33]=validCount;
        {
            u8 *source;
            u8 *dest;
            s32 count;
            source=valid;
            count=25;
            dest=current+0x1a;
            do { *dest=*(s8 *)source; ++source; ++dest; } while(--count>0);
        }
        sghMarker_MarkerClear();
        sghMarker_SetActPossible(0,selected,dice.b[valid[0]],game[4]);
        *(u32 *)((u32)(MdlMng+0x1724c)+valid[0]*0x1c0)=0x3f800000;
    }
    *(u32 *)(pad+4)=0;
    game[0]=15;
}
void __sghMode_AIThink(void) {
    u8 a1;
    u8 *s0;
    u32 v0;
    u8 copied[4] __attribute__((aligned(4)));
    struct Slots {
        u8 padding[4];
        u8 source[4];
        u8 actions[4];
    } slots;
    v0=(u32)sghGetGameInfo();
    s0=(u8*)v0;
    sghDice_GetDiceSpotsList(slots.source);
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $29, 0x24\n"
        "addiu $4, $29, 0x2c\n"
        "lbu $3, 0($2)\n"
        "lbu $2, 1($2)\n"
        "sb $3, 0($4)\n"
        "jal sghMap_GetMainTblMap\n"
        "sb $2, 1($4)\n"
        ".set reorder\n"
        :
        :
        : "$2", "$3", "$4", "$31", "memory");
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $4, $29, 0x28\n"
        ".word 0x10800008\n"
        "addiu $3, $zero, 4\n"
        "0:\n"
        "sb $zero, 0($4)\n"
        "addiu $3, $3, -1\n"
        "addiu $4, $4, 1\n"
        "nop\n"
        "nop\n"
        ".word 0x1460fffa\n"
        "nop\n"
        "1:\n"
        ".set reorder\n"
        :
        :
        : "$3", "$4", "memory");
    __asm__ volatile(
        ".set noreorder\n"
        "jal sghEneThk_SetMap\n"
        "daddu $4, $2, $zero\n"
        ".set reorder\n"
        :
        :
        : "$2", "$4", "$31", "memory");
    sghEneThk_SetPlayerID(s0[4]);
    sghEneThinking(slots.actions,copied);
    sghEneThk_SetActList(slots.actions);
    a1=slots.actions[0]; sghDice_SetDiceSpots(0,a1);
    a1=slots.actions[2]; sghDice_SetDiceSpots(1,a1);
    s0[0]=0x11;
}


void __sghMode_AIAct(void) {
    u8 *info;
    u8 spots;
    u8 from;
    u32 destination;
    struct AIAction { u8 spots, from, next, nextFrom; } action, original;
    info = (u8 *)sghGetGameInfo();
    sghEneThk_GetActList((u8 *)&original);
    {
    u32 target, source;
    source = (u32)&original;
    target = (u32)&action;
    *(struct AIAction *)target = *(struct AIAction *)source;
    }
    spots = action.spots;
    from = action.from;
    if (spots == 0 || spots == 255) {
        struct AIActionPair { u8 spots, from; };
        u32 source;
        source = (u32)&action.next;
        *(struct AIActionPair *)&action = *(struct AIActionPair *)source;
        action.next = 255;
        sghEneThk_SetActList(&action);
        info[0] = 18;
    } else {
        destination = (u32)from + spots;
        sghMarker_SetTgtPos(0, destination, info[4]);
        sghKoma_SetMoveAnimeInit(from, destination, info[4]);
        sghMap_Update(action.from, action.spots);
        sghDice_UseSpots(spots);
        info[0] = 20;
    }
}

static u32 __sghMode_KomaMoveInit(void) {
    u8 a2;
    u8 *s1;
    u8 *s0;
    u8 a1;
    u8 a0;
    u8 v1;
    u32 v0;
    u8 stackFrame_3C[4] __attribute__((aligned(4)));
    u8 stackFrame_38[4] __attribute__((aligned(8)));

    v0 = (u32)sghGetGameInfo();
    s1 = (u8 *)v0;
    v0 = (u32)sghPad_GetPadInfo();
    s0 = (u8 *)v0;
    sghDice_GetDiceSpotsList((u8 *)((u8 *)&stackFrame_38[0]));
    v0 = *(u8 *)(s0 + 0xc);
    ((u8 *)stackFrame_3C)[1] = v0;
    v0 = *(u8 *)(s0 + 0xd);
    *(u8 *)((u8 *)&stackFrame_3C[0]) = v0;
    v1 = *(u8 *)(s0 + 0xc);
    v0 = *(u8 *)(s0 + 0xd);
    a2 = *(u8 *)(s1 + 4);
    sghMarker_SetTgtPos(0, (u32)(v1) + v0, a2);
    a0 = *(u8 *)(s0 + 0xc);
    v0 = *(u8 *)(s0 + 0xd);
    a2 = *(u8 *)(s1 + 4);
    sghKoma_SetMoveAnimeInit(a0, (u32)(a0) + v0, a2);
    a1 = *(u8 *)(s0 + 0xd);
    a0 = *(u8 *)(s0 + 0xc);
    sghMap_Update(a0, a1);
    a0 = *(u8 *)(s0 + 0xd);
    sghDice_UseSpots(a0);
    sghEneThk_SetActList((void *)((u8 *)&stackFrame_3C[0]));
    sghPad_Init();
    *(u8 *)s1 = 0x14;
    return;
}
void __sghMode_KomaMoveEnd(void) {
    u8 *info;
    u8 spots;
    struct AIAction { u8 spots, from, next, nextFrom; } action, original;
    info = (u8 *)sghGetGameInfo();
    sghEneThk_GetActList((u8 *)&original);
    {
        u32 target, source;
        source = (u32)&original;
        target = (u32)&action;
        *(struct AIAction *)target = *(struct AIAction *)source;
    }
    spots = action.spots;
    {
        struct AIActionPair { u8 spots, from; };
        u32 source;
        source = (u32)&action.next;
        *(struct AIActionPair *)&action = *(struct AIActionPair *)source;
    }
    action.next = 255;
    sghEneThk_SetActList(&action);
    sghDice_EraseSpots(spots);
    sghMarker_MarkerClear();
    sghKoma_UpdatePos();
    info[0] = 22;
}
void __sghMode_JudgeGame(void) {
    s32 count;
    u8 *info;
    u8 player;
    s32 i;
    u32 address, equal;
    info = (u8 *)sghGetGameInfo();
    player = info[4];
    address = (u32)sghMap_GetMainTblMap();
    equal = (u32)player << 5;
    address = address + equal;
    count = 0;
    for (i = 0; i < 6; i++) count += *(u8 *)(address + 19 + i);
    equal = (u32)(count ^ 15) < 1;
    if (equal) {
        info[0] = 23;
        goto end;
    }
    if (!sghDice_IsUsed()) {
        switch (info[5 + info[4]]) {
        case 0: info[0] = 12; break;
        case 1: info[0] = 17;
        }
        return;
    }
    info[4] = info[4] == 0 ? (enum JudgePlayer)1 : (enum JudgePlayer)0;
    info[0] = 8;
end:;
}

static u32 gSGH_ModeFnc[0x1c] = {
    (u32)&__sghMode_Init, 0, (u32)&__sghMode_SelectEnemy, (u32)&__sghMode_OrderPlayerInit, 0, 0,
    (u32)&__sghMode_OrderPlayerEnd, (u32)&__sghMode_MainInit, (u32)&__sghMode_DiceInit, 0, 0,
    (u32)&__sghMode_DiceEnd, (u32)&__sghMode_UserChoiceKomaInit, 0,
    (u32)&__sghMode_UserChoiceDiceInit, 0, (u32)&__sghMode_AIThink, (u32)&__sghMode_AIAct, 0,
    (u32)&__sghMode_KomaMoveInit, 0, (u32)&__sghMode_KomaMoveEnd, (u32)&__sghMode_JudgeGame,
    (u32)&__sghMode_GameResult, (u32)&__sghMode_GameScore, 0, (u32)&__sghMode_TutorialInit
};

void __sghMode_GameResult(void) {
    u8 *prc;
    u8 *info;
    u8 *q;
    u8 *p;
    s32 i;
    s32 v;
    u8 *mdl;

    prc = (u8 *)GetMGPrcStatus();
    info = (u8 *)sghGetGameInfo();
    {
    s32 sndTbl[2][2] = {{0x138e, 0x138f}, {0x138e, 0x138e}};
    q = (u8 *)((u32)info[4] + (u32)info) + 7;
    v = (u8)(*q + 1);
    if (v > 99) {
        v = 99;
    } else {
        v = v < 0 ? 0 : v;
    }
    *q = v;
    SND_Play2D(sndTbl[prc[1]][info[4]], 0x7f, 0);
    }
    if (prc[1] == 0) {
        mdl = MdlMng + (info[4] + 0xd5) * 0x1c0;
    } else {
        mdl = MdlMng + 0x174c0;
    }
    mdl[2] = 0;
    sghTime_SetWait(0x50);
    ChangeAnimParam(mdl, 3, 0.0f);
    p = MdlMng + 0x119c0;
    i = 0;
    do {
        p[2] = 1;
        p[0x1c2] = 1;
        p[0x382] = 1;
        p[0x542] = 1;
        p[0x702] = 1;
        p[0x8c2] = 1;
        p[0xa82] = 1;
        p[0xc42] = 1;
        i += 8;
        p += 0xe00;
    } while (i < 0x20);
    MdlMng[0x17142] = 1;
    MdlMng[0x17302] = 1;
    *info = 0x18;
}

static u32 __sghMode_GameScore(void) {
    u8 v1;
    u8 *v0;
    u8 *s0;

    v0 = (u8 *)sghGetGameInfo();
    v1 = *(u8 *)(v0 + 4);
    s0 = v0;
    v0 = (u8 *)MdlMng;
    ChangeAnimParam((void *)((u8 *)MdlMng + (u32)((u32)((u32)(v1) + 0xd5) * 0x1c0)), 0, 0.0f);
    sghTime_SetWait(0x80);
    sghPad_Init();
    *(u8 *)s0 = 0x19;
    return;
}

static u32 __sghMode_TutorialInit(void) {
    u8 *v0;
    u8 *s0;

    s0 = (u8 *)sghGetGameInfo();
    v0 = (u8 *)sghPad_GetPadInfo();
    *(u32 *)(v0 + 8) = 0;
    *(u8 *)s0 = 0x1b;
    return (u32)v0;
}
