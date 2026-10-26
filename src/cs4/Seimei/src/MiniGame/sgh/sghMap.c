#include "common.h"

static void __sghMap_MainMapPosTblInit(void);
/* __sghMap_MainMapPosTblInit @ 0x20BF60 .. 0x20C3EC (0x48c bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0xbf4f5c29 at 0x20bf88
 *   fpu: float literal 0x3dfdf3b6 at 0x20bf90
 *   fpu: mtc1 reinterprets a3 at 0x20bfa8
 *   fpu: mtc1 reinterprets t2 at 0x20bfbc
 *   fpu: mtc1 reinterprets t1 at 0x20bff0
 *   fpu: mtc1 reinterprets t2 at 0x20c008
 *   fpu: mtc1 reinterprets t1 at 0x20c03c
 *   fpu: mtc1 reinterprets t2 at 0x20c054
 *   fpu: mtc1 reinterprets t1 at 0x20c088
 *   fpu: mtc1 reinterprets t2 at 0x20c0a0
 *   fpu: mtc1 reinterprets t1 at 0x20c0d4
 *   fpu: mtc1 reinterprets t2 at 0x20c0ec
 *   fpu: mtc1 reinterprets t1 at 0x20c120
 *   fpu: mtc1 reinterprets t2 at 0x20c138
 *   fpu: float literal 0x3dfdf3b6 at 0x20c188
 *   fpu: float literal 0xbf4f5c29 at 0x20c190
 *   fpu: float literal 0xbc75c28f at 0x20c1a0
 *   fpu: float literal 0x3f800000 at 0x20c1a8
 *   fpu: mtc1 reinterprets t1 at 0x20c1c4
 *   fpu: mtc1 reinterprets t2 at 0x20c1dc
 *   fpu: mtc1 reinterprets t1 at 0x20c21c
 *   fpu: mtc1 reinterprets t2 at 0x20c234
 *   fpu: mtc1 reinterprets t1 at 0x20c274
 *   fpu: mtc1 reinterprets t2 at 0x20c28c
 *   fpu: mtc1 reinterprets t1 at 0x20c2cc
 *   fpu: mtc1 reinterprets t2 at 0x20c2e4
 *   fpu: mtc1 reinterprets t1 at 0x20c324
 *   fpu: mtc1 reinterprets t2 at 0x20c33c
 *   fpu: mtc1 reinterprets t1 at 0x20c37c
 *   fpu: mtc1 reinterprets t2 at 0x20c394
 */

extern u8 gMainTblMap[];



typedef struct {
    u8 knum[25];
    u8 dummy[7];
} SGHMAP;

typedef struct {
    SGHMAP map[2];
} SGHLMAP;

#define SGHMAP_PACK() \
    switch (arrival) { \
    case 0: \
        pMap[0] = map0; \
        pMap[1] = map1; \
        break; \
    case 1: \
        pMap[0] = map1; \
        pMap[1] = map0; \
        break; \
    } \
    *(SGHLMAP *)map_ = l_map

extern void SND_Play2D(int, int, int);


typedef struct {
    u8 knum[25] __attribute__((aligned(16)));
    u8 dummy[7];
} SGHMAPQ_;


extern u32 sghGetGameInfo();
extern void sghMap_Eval(void *, void *, unsigned char, unsigned char, unsigned char);
extern u8 gMainTblMap[];


/* sghMap_GetMainTblMap @ 0x20C940 .. 0x20C94C (0xc bytes) */

extern u8 gMainTblMap[];
static u8 gMainTblMap[0x1d0];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
u8 * sghMap_GetMainTblMap(void);
void sghMap_Update(unsigned char first, unsigned char second);
void sghMap_MainInit(void);
void sghMap_Eval(void *map_, void *ktgt_, unsigned char spots_, unsigned char player_, unsigned char arrival_);
static void __sghMap_MainMapPosTblInit(void);


u8 * sghMap_GetMainTblMap(void) {
    return (u8 *)gMainTblMap;
}
void sghMap_Update(unsigned char first, unsigned char second) {
    u8 *info = (u8 *)sghGetGameInfo();
    struct MapCopy { u_long128 words[4]; } map = {0};
    sghMap_Eval(&map, gMainTblMap, first, second, info[4]);
    *(struct MapCopy *)gMainTblMap = map;
}

void sghMap_MainInit(void) {
    {
        SGHMAPQ_ map0 = {{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0}};
        *(SGHMAPQ_ *)gMainTblMap = map0;
    }
    {
        SGHMAP map1 = {{0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0}};
        ((SGHMAP *)gMainTblMap)[1] = map1;
    }
    __sghMap_MainMapPosTblInit();
}

void sghMap_Eval(void *map_, void *ktgt_, unsigned char spots_, unsigned char player_, unsigned char arrival_) {
    SGHLMAP l_map = {0};
    SGHMAP *pMap = l_map.map;
    SGHMAP map0 = {0};
    SGHMAP map1 = {0};
    int arrival;
    int sum;

    arrival = arrival_;
    switch (arrival) {
    case 0:
        map0 = ((SGHMAP *)ktgt_)[0];
        map1 = ((SGHMAP *)ktgt_)[1];
        break;
    case 1:
        map1 = ((SGHMAP *)ktgt_)[0];
        map0 = ((SGHMAP *)ktgt_)[1];
        break;
    }
    sum = spots_ + player_;
    if (player_ == 0) {
        SGHMAP_PACK();
    } else {
        map0.knum[spots_]--;
        map0.knum[sum]++;
        switch (map1.knum[0x19 - sum]) {
        case 0:
            break;
        case 1:
            SND_Play2D(0x1392, 0x7f, 0);
            map1.knum[0x19 - sum]--;
            map1.knum[0]++;
            break;
        default:
            break;
        }
        SGHMAP_PACK();
    }
}

static void __sghMap_MainMapPosTblInit(void) {
    float (*paPosList)[4];
    unsigned int i;
    float *pPos;

    paPosList = (float (*)[4])(gMainTblMap + 0x40);
    for (i = 1; i < 13; i++) {
        pPos = paPosList[i];
        pPos[0] = -0.81f + 0.124f * (float)i;
        pPos[1] = -0.015f;
        pPos[2] = 0.43f;
        pPos[3] = 1.0f;
    }
    for (i = 1; i < 13; i++) {
        pPos = paPosList[i + 12];
        pPos[0] = -0.81f + 0.124f * (float)(13 - i);
        pPos[1] = -0.015f;
        pPos[2] = -0.17f;
        pPos[3] = 1.0f;
    }
    pPos = paPosList[0];
    pPos[0] = -0.686f;
    pPos[1] = -0.015f;
    pPos[2] = 0.05f;
    pPos[3] = 1.0f;
}
