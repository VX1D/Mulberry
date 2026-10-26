#include "common.h"
typedef struct RtaLiteralPool {
    char allocator[12];
    u8 padAllocator[4];
    char rtaPattern[12];
    u8 padRtaPattern[4];
    char rhrPattern[12];
    u8 padRhrPattern[4];
    char bndFile[12];
    u8 padBndFile[4];
    char empty[1];
} RtaLiteralPool;

static const RtaLiteralPool dcomp_ph_FUNCTION___734 __attribute__((aligned(4))) = {
    "RtaMemAlloc", {0, 0, 0, 0},
    "rta%04d.rta", {0, 0, 0, 0},
    "rhr%04d.rhr", {0, 0, 0, 0},
    "rta\\rta.bnd", {0, 0, 0, 0},
    {0}
};
extern signed int MngState_UpdateExeCheck(void *);
extern void MngState_ResetTime(void *);
extern u32 s_RtaMng[];
extern void MemFree(void *);
extern u32 s_stabilize_on;
u8 * RtaMngUpdate(void);
signed int RtaMngDeleteRtaData(unsigned int a0 /* r4 */);
u8 * RtaMngGetRtaMng(void);
void RtaMngSetstabilizeOnOff(s32 a0 /* r4 */);

/* RtaMngSetstabilizeOnOff @ 0x16B920 .. 0x16B928 (0x8 bytes) */


void RtaMngSetstabilizeOnOff(s32 a0 /* r4 */) {
    s_stabilize_on = a0;
    return;
}

/* RtaMngGetRtaMng @ 0x16B910 .. 0x16B91C (0xc bytes) */




u8 * RtaMngGetRtaMng(void) {
    return (u8 *)s_RtaMng;
}


/* RtaMngInitialize @ 0x16B840 .. 0x16B910 (0xd0 bytes) */

signed int RtaMngInitialize(void) {
    s32 i;
    u32 v1;
    u32 v0;

    s_RtaMng[0x351] = 0;
    s_RtaMng[0x352] = 0;
    s_RtaMng[0x350] = 0;
    for (i = 0; i < 35; i++) {
        s_RtaMng[0x8 + i] = 0;
        s_RtaMng[0x2b + i] = 0;
    }
    for (i = 769; i >= 0; i--) {
        s_RtaMng[0x4e + i] = 0;
    }
    return 1;
}


/* RtaMngInit @ 0x16B750 .. 0x16B838 (0xe8 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   literal: @2082 is the string 'rta\\rta.bnd'
 */

extern signed int MngState_Init(void *);
extern signed int FileRead(char *, signed int, unsigned char **, unsigned char, signed int, signed
    int, unsigned int);

signed int RtaMngInit(void) {
    s32 a1;
    s32 s1;
    u8 *s0;
    u32 a0;
    s32 v0;

    a0 = (u32)s_RtaMng;
    MngState_Init((void *)s_RtaMng);
    s_RtaMng[0x351] = 0;
    s1 = 0;
    s0 = (u8 *)s_RtaMng;
    s_RtaMng[0x352] = 0;
    s_RtaMng[0x350] = 0;
    do {
        MemFree((void *)*(s32 *)(s0 + 0x138));
        s1 = s1 + 1;
        *(u32 *)(s0 + 0x138) = 0;
        v0 = (u32)s1 < (u32)0x302;
        s0 = (u8 *)(s0 + 4);
    } while ((u32)v0 != 0);
    a0 = *(s32 *)(s_RtaMng + 0x350);
    if (a0 != 0) {
        MemFree((void *)a0);
        s_RtaMng[0x350] = 0;
    }
    a1 = -1;
    a0 = (u32)dcomp_ph_FUNCTION___734.bndFile;
    v0 = FileRead((char *)dcomp_ph_FUNCTION___734.bndFile, a1, (unsigned char **)(u8 *)(u8 *)(s_RtaMng + 0x350), 0, a1, 0xd,
        0);
    if (v0 <= 0) {
        s_RtaMng[0x350] = 0;
    }
    a0 = (u32)s_RtaMng;
    MngState_ResetTime((void *)s_RtaMng);
    *(u32 *)s_RtaMng = 2;
    return 1;
}

extern void *MemAllocReal(unsigned int, char *, char *);
extern void sceVu0UnitMatrix(void *);
extern void fsvu0_CopyVectorF(float *, float *);
extern u32 g_ZeroVec[];
signed int RtaMngMakeRtaData(unsigned int number, signed int type)
{
    s32 savedNumber;
    u32 savedType;
    u32 count;
    u32 index;
    u32 offset;
    s32 slot;
    u32 header;
    s32 result;
    savedNumber = (s32)number;
    savedType = type;
    if ((u32)savedNumber >= 0x302) {
        result = 0;
        goto finished;
    }
    if ((u32)savedType >= 0x23) return 0;
    header = s_RtaMng[8 + savedType];
    if (header == 0) result = 0;
    else {
        count = *(u32 *)(header + 0x14);
        if ((u32)savedNumber <= 0x301) {
            slot = (u32)(s_RtaMng + 0x4e) + savedNumber * 4;
            MemFree((void *)*(u32 *)slot);
            *(u32 *)slot = 0;
        }
        header = (u32)MemAllocReal(count << 9, (char *)dcomp_ph_FUNCTION___734.allocator, (char *)dcomp_ph_FUNCTION___734.empty);
        number = savedNumber << 2;
        *(u32 *)((u32)(s_RtaMng + 0x4e) + number) = header;
        if (header == 0) result = 0;
        else {
            index = 0;
            if ((u8 *)0 < (u8 *)count) {
                offset = 0;
                header = (u32)s_RtaMng + number;
                savedNumber = (s32)header + 0x138;
                do {
                    *(u32 *)(*(u32 *)savedNumber + offset) = savedType;
                    sceVu0UnitMatrix((void *)(*(u32 *)savedNumber + offset + 0x40));
                    fsvu0_CopyVectorF((float *)(*(u32 *)savedNumber + offset + 0x80), (float *)g_ZeroVec);
                    fsvu0_CopyVectorF((float *)(*(u32 *)savedNumber + offset + 0x90), (float *)g_ZeroVec);
                    fsvu0_CopyVectorF((float *)(*(u32 *)savedNumber + offset + 0xa0), (float *)g_ZeroVec);
                    index++;
                    offset += 512;
                } while (index < count);
            }
            result = 1;
        }
    }
finished:
    return result;
}

/* RtaMngDeleteRtaData @ 0x16B560 .. 0x16B5B0 (0x50 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int RtaMngDeleteRtaData(unsigned int a0 /* r4 */) {
    u32 *s0;
    u32 v0;

    v0 = (u32)(s32)a0 < (u32)0x302;
    if (v0 == 0) {
        v0 = 0;
    } else {
        s0 = (u32 *)(s32)((u32)(u8 *)(s_RtaMng + 0x4e) + (s32)((u32)a0 << 2));
        MemFree((void *)*(s32 *)s0);
        *(u32 *)s0 = 0;
        v0 = 1;
    }
    return v0;
}

/* RtaMngUpdate @ 0x16B510 .. 0x16B554 (0x44 bytes, frame 0x10) */


u8 * RtaMngUpdate(void) {
    u8 *a0;
    s32 v0;

    a0 = (u8 *)s_RtaMng;
    v0 = MngState_UpdateExeCheck((void *)s_RtaMng);
    if ((u32)v0 != (u32)1) {
        v0 = 0;
    } else {
        a0 = (u8 *)s_RtaMng;
        MngState_ResetTime((void *)s_RtaMng);
        v0 = 1;
    }
    return (u8 *)v0;
}


/* RtaMngRtaUpdate @ 0x16B420 .. 0x16B504 (0xe4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: daddu at 0x16b460 writes a register its branch at 0x16b45c reads
 *   cfg: kept branch: 0x16b42c if (..) goto .L0016B458
 *   cfg: kept goto: 0x16b454 -> .L0016B4F0
 *   declaration vs inferred signature: return signed int vs inferred u8 *
 */

extern void MngState_GetStartTime(void *);
static signed int RtaMngUpdate_CalcRta(unsigned char *, void *, void *, void *);
extern void MngState_GetEndTime(void *);

signed int RtaMngRtaUpdate(unsigned int a0 /* r4 */, unsigned int a1 /* r5 */) {
    s32 s1;
    s32 s0;
    u32 *a3;
    u32 v1;
    u32 v0;
    unsigned int a0_2;
    unsigned int a1_2;

    s1 = a0;
    s0 = a1;
    a0_2 = (unsigned int)s_RtaMng;
    v0 = MngState_UpdateExeCheck((void *)s_RtaMng);
    v1 = 1;
    if (v0 == v1) {
        goto _L0016B458;
    }
    v0 = 0;
    goto _L0016B4F0;
    _L0016B458:;
    v0 = (u32)s1 < (u32)0x302;
    if (v0 == 0) {
        v0 = 0;
        return v0;
    }
    a0_2 = (unsigned int)s_RtaMng;
    MngState_GetStartTime((void *)s_RtaMng);
    v1 = (u32)(s32)s1 << 2;
    v0 = (u32)(u8 *)(s_RtaMng + 0x4e);
    s_RtaMng[0x351] = s0;
    {
        u32 dcomp_tmp_1;
        dcomp_tmp_1 = v0 + v1;
        v0 = dcomp_tmp_1;
    }
    a3 = (u32 *)*(s32 *)v0;
    if ((u32)(s32)a3 != 0) {
        v1 = *(s32 *)a3;
        v0 = (u32)(u8 *)(s_RtaMng + 8);
        v1 = v1 << 2;
        {
            u32 dcomp_tmp_0;
            dcomp_tmp_0 = v0 + v1;
            v0 = dcomp_tmp_0;
        }
        a0_2 = *(s32 *)v0;
        if ((u32)(s32)a0_2 != 0) {
            v1 = *(u8 *)(((s32)(a0_2) + 0x1c));
            v0 = 1;
            v1 = v1 & 1;
            a1_2 = (u32)(a0_2) + 0x20;
            if (v1 != v0) {
                RtaMngUpdate_CalcRta((unsigned char *)a0_2, (void *)a1_2, (void *)0, (void *)a3);
            }
        }
    }
    a0_2 = (unsigned int)s_RtaMng;
    MngState_GetEndTime((void *)s_RtaMng);
    v0 = 1;
    _L0016B4F0:;
    return v0;
}







/* RtaMngRtaSetMat @ 0x16B330 .. 0x16B41C (0xec bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x16b380 writes a register its branch at 0x16b37c reads
 *   cfg: kept goto: 0x16b374 -> .L0016B400
 *   declaration vs inferred signature: return signed int vs inferred u32
 */

extern signed int MngState_DrawExeCheck(void *);
static signed int RtaMngSetMat(unsigned char *, void *, void *, void *, void *, int);

signed int RtaMngRtaSetMat(unsigned int data_id, unsigned int mdl_handle, void *mat, int set_mat_type) {
    s32 *pRtaFileHeader;
    u8 *pRtaData;

    if (MngState_DrawExeCheck((void *)s_RtaMng) != 1) {
        return 1;
    }
    if (data_id >= 0x302) {
        return 0;
    }
    s_RtaMng[0x351] = mdl_handle;
    pRtaFileHeader = (s32 *)s_RtaMng[0x4e + data_id];
    if (pRtaFileHeader != 0) {
        pRtaData = (u8 *)s_RtaMng[8 + *pRtaFileHeader];
        if (pRtaData != 0 && (pRtaData[0x1c] & 1) != 1) {
            RtaMngSetMat(pRtaData, pRtaData + 0x20, (void *)0, (void *)pRtaFileHeader, mat, set_mat_type);
        }
    }
    return 1;
}







/* RtaMngUpdate_CalcRta @ 0x16A000 .. 0x16B324 (0x1324 bytes, frame 0x560) */
extern void sceVu0CopyMatrix(void *, void *);
extern void fsvu0_ScaleVector(float *, float *, float);
extern void fsvu0_AddVector(float *, float *, float *);
extern void * GetMdlObjWMat(unsigned int, unsigned int, unsigned int);
extern void sceVu0CopyVector(void *, void *);
extern signed int KnMenuWindMng_GetWindVec(float *, float *, signed int);
extern u32 GetFirstBlastDir();
extern void fsvu0_SubVector(float *, float *, float *);
extern float GetDist_(float *, float *);
extern void fsvu0_Normalize(float *, float *);
struct dw_797362_fields;
extern unsigned int RhrCheckHit(struct dw_797362_fields *, unsigned int, float *, float *, float *, float *, float, unsigned int, unsigned int);
extern void fsvu0_OuterProduct(float *, float *, float *);
extern float Rta_Acosf(float);
extern float acosf(float);
extern void fsvu0_MulMatrix(void *, void *, void *);
s32 g_RtaNoUpdate;
extern u8 GameSt[];
extern u32 g_UnitMat[];

typedef struct RtaCVec { float x, y, z, w; } RtaCVec;
typedef struct RtaCFlag { unsigned int no_use : 1; unsigned int wind_type : 1; unsigned int acosf_table : 1; unsigned int reserve : 29; } RtaCFlag;
typedef struct RtaCParam {
    unsigned int id; float max_length; float min_length; float spring_k; float obj_len;
    float move_vec_add_rate; float vec_decay; float gravity; float max_rot; float max_vec;
    float air_decay; float vertical_air_decay; float rebound_k; unsigned int rhr_group_id;
    float hit_decay; float vec_move_add_rate; unsigned char proc_param[64];
} RtaCParam;
typedef struct RtaCTable {
    unsigned int id; unsigned short mdl_obj_id; unsigned short anm_obj_id; RtaCFlag table_data_flag;
    unsigned char follow_mdl_or_anm; unsigned char proc_id; unsigned char dmy1[2];
    float init_rot[4]; float init_trans[4]; unsigned int rta_data_offset; unsigned int child_offset;
    unsigned int sibling_offset; unsigned char dmy[4]; float init_mat[4][4]; RtaCParam rta_param;
} RtaCTable;
typedef struct RtaCData {
    unsigned int rta_id; unsigned char reserve1[60]; float mat[4][4]; float vec[4];
    float air_move_vec[4]; float tmp_fp_pos[4]; unsigned char reserve4[16]; float tmp_mat[4][4];
    float pulled_by_parent_vec[4]; float pulled_by_child_vec[4]; unsigned char reserve3[224];
} RtaCData;
typedef struct RtaCHdr {
    unsigned long magic_code; unsigned long file_size; unsigned short version_id; unsigned short rhr_file_id;
    unsigned int obj_num; unsigned int data_offset; unsigned int header_data_flag;
} RtaCHdr;
typedef struct RtaCMng {
    unsigned char head[0xd44]; unsigned int mdl_handle; unsigned int buf_id;
} RtaCMng;
typedef struct RtaCMdl { unsigned char pad[0x10]; float (*wmat)[4][4]; float (*lmat)[4][4]; } RtaCMdl;

static inline void RtaCWind(float *vec, float *pos, signed int id) {
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = 0.0f;
    vec[3] = 1.01f;
    if (GameSt[5] == 2) {
        KnMenuWindMng_GetWindVec(vec, pos, id);
    }
    if (GameSt[5] == 0 || GameSt[5] == 1) {
        u32 blast = GetFirstBlastDir();
        if (blast != 0) {
            fsvu0_CopyVectorF(vec, (float *)(blast + 0x10));
        }
    }
}

static inline void RtaCZVec(float *out, float *src, float len, float *add) {
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    out[3] = 1.0f;
    fsvu0_ScaleVector(out, out, len);
    fsvu0_AddVector(out, out, add);
}

#define RTAC_MNG ((RtaCMng *)s_RtaMng)

static inline float RtaCAcos(RtaCTable *t, float x) {
    if (t->table_data_flag.wind_type) {
        x = Rta_Acosf(x);
    } else {
        x = acosf(x);
    }
    return x;
}

#define RTAC_TAIL() \
    pRtaTable_child = (RtaCTable *)(pRtaFileBuf + pRtaTable->child_offset); \
    pRtaTable_sibling = (RtaCTable *)(pRtaFileBuf + pRtaTable->sibling_offset); \
    if (pRtaTable->table_data_flag.no_use == 0 && (u8 *)pRtaTable_child != pRtaFileBuf) { \
        RtaMngUpdate_CalcRta(pRtaFileBuf, pRtaTable_child, pRtaTable, pRtaData_root); \
    } \
    if ((u8 *)pRtaTable_sibling != pRtaFileBuf) { \
        RtaMngUpdate_CalcRta(pRtaFileBuf, pRtaTable_sibling, pRtaTable_parent, pRtaData_root); \
    } \
    if (pRtaTable->table_data_flag.no_use == 0 && pRtaTable->follow_mdl_or_anm != 2 && s_stabilize_on == 0) { \
        u32 kind = s_RtaMng[0x352]; \
        RtaCMdl *mdl = (RtaCMdl *)s_RtaMng[0x351]; \
        u32 obj = pRtaTable->mdl_obj_id; \
        if (mdl != 0) { \
            switch (kind) { \
            case 0: sceVu0CopyMatrix(mdl->wmat[obj], pRtaData->mat); break; \
            case 1: sceVu0CopyMatrix(mdl->lmat[obj], pRtaData->mat); break; \
            default: sceVu0CopyMatrix(mdl->wmat[obj], pRtaData->mat); break; \
            } \
        } \
    }

#define RTAC_ROT() \
    if (GetDist_((float *)g_ZeroVec, rot_axis) < 0.99f) { \
        sceVu0CopyMatrix(rot, g_UnitMat); \
    } else { \
        float c, s, t; \
        c = cosf(rad); \
        s = sinf(rad); \
        t = 1.0f - c; \
        rot[0][3] = 0; rot[1][3] = 0; rot[2][3] = 0; \
        rot[3][0] = 0; rot[3][1] = 0; rot[3][2] = 0; rot[3][3] = 1.0f; \
        rot[0][0] = c + t * (rot_axis[0] * rot_axis[0]); \
        rot[0][1] = rot_axis[2] * s + t * (rot_axis[0] * rot_axis[1]); \
        rot[0][2] = -rot_axis[1] * s + t * (rot_axis[0] * rot_axis[2]); \
        rot[1][0] = -rot_axis[2] * s + t * (rot_axis[0] * rot_axis[1]); \
        rot[1][1] = c + t * (rot_axis[1] * rot_axis[1]); \
        rot[1][2] = rot_axis[0] * s + t * (rot_axis[1] * rot_axis[2]); \
        rot[2][0] = rot_axis[1] * s + t * (rot_axis[0] * rot_axis[2]); \
        rot[2][1] = -rot_axis[0] * s + t * (rot_axis[1] * rot_axis[2]); \
        rot[2][2] = c + t * (rot_axis[2] * rot_axis[2]); \
    }

static signed int RtaMngUpdate_CalcRta(unsigned char *pRtaFileBuf, void *pRtaTable_, void *pRtaTable_parent_, void *pRtaData_root_) {
    RtaCTable *pRtaTable = (RtaCTable *)pRtaTable_;
    RtaCTable *pRtaTable_parent = (RtaCTable *)pRtaTable_parent_;
    RtaCData *pRtaData_root = (RtaCData *)pRtaData_root_;
    RtaCHdr *pRtaFileHeader;
    RtaCTable *pRtaTable_child;
    RtaCTable *pRtaTable_sibling;
    RtaCData *pRtaData;
    RtaCTable *pRtaTable_A;
    RtaCTable *pRtaTable_B;
    float old_mat[4][4];
    u32 check_hit;

    if (pRtaFileBuf == 0) {
        return 0;
    }
    if (pRtaTable == 0) {
        return 0;
    }
    if (pRtaData_root == 0) {
        return 0;
    }
    pRtaFileHeader = (RtaCHdr *)pRtaFileBuf;
    pRtaData = &pRtaData_root[pRtaTable->id];
    sceVu0CopyMatrix(old_mat, pRtaData->mat);
    if (g_RtaNoUpdate == 1 && pRtaTable->table_data_flag.no_use == 0) {
        switch (pRtaTable->proc_id) {
        case 3: {
            float old_mat[4][4];
            float old_fp_mat[4][4];
            float parent_mat[4][4];
            float new_fp_mat[4][4];
            float new_mat[4][4];
            float tmp_vec[4];
            float tmp_z_vec[4];
            float tmp_dist;
            float tmp_dot;

            sceVu0CopyMatrix(old_mat, pRtaData->mat);
            tmp_z_vec[0] = old_mat[2][0];
            tmp_z_vec[1] = old_mat[2][1];
            tmp_z_vec[2] = old_mat[2][2];
            tmp_z_vec[3] = 1.0f;
            fsvu0_ScaleVector(tmp_vec, tmp_z_vec, pRtaTable->rta_param.obj_len);
            sceVu0CopyMatrix(old_fp_mat, old_mat);
            fsvu0_AddVector(old_fp_mat[3], (float *)((u8 *)old_fp_mat + 0x30), tmp_vec);
            sceVu0CopyMatrix(new_fp_mat, old_fp_mat);
            if (pRtaTable->follow_mdl_or_anm == 0) {
                sceVu0CopyMatrix(parent_mat, GetMdlObjWMat(s_RtaMng[0x351], pRtaTable->mdl_obj_id, s_RtaMng[0x352]));
            }
            if (pRtaTable->follow_mdl_or_anm == 1) {
                if (pRtaTable_parent == 0) {
                    sceVu0CopyMatrix(parent_mat, pRtaData->mat);
                } else if (pRtaTable_parent != 0) {
                    sceVu0CopyMatrix(parent_mat, pRtaData_root[pRtaTable_parent->id].mat);
                    sceVu0CopyVector(tmp_z_vec, pRtaData_root[pRtaTable_parent->id].mat[2]);
                    tmp_z_vec[3] = 1.0f;
                    fsvu0_ScaleVector(tmp_vec, tmp_z_vec, pRtaTable_parent->rta_param.obj_len);
                    fsvu0_AddVector(parent_mat[3], parent_mat[3], tmp_vec);
                }
            }
            {
            float gravity[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            gravity[1] = pRtaTable->rta_param.gravity;
            {
            float move_vec[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            float air_move_vec[4];
            float wind_vec[4];
            float new_pos[4];
            float new_vec[4];
            float rot_axis[4];
            float rad;
            float rot[4][4];
            float tmp_oya_to_new_fp_vec[4];
            fsvu0_AddVector(move_vec, move_vec, pRtaData->vec);
            fsvu0_AddVector(move_vec, move_vec, gravity);
            RtaCWind(wind_vec, old_mat[3], pRtaFileHeader->rhr_file_id);
            sceVu0CopyVector(air_move_vec, move_vec);
            fsvu0_SubVector(air_move_vec, air_move_vec, wind_vec);
            sceVu0CopyVector(pRtaData->air_move_vec, air_move_vec);
            tmp_dist = GetDist_((float *)g_ZeroVec, air_move_vec);
            tmp_dist = tmp_dist * pRtaTable->rta_param.air_decay;
            fsvu0_Normalize(tmp_vec, air_move_vec);
            fsvu0_ScaleVector(tmp_vec, tmp_vec, tmp_dist);
            fsvu0_AddVector(move_vec, move_vec, tmp_vec);
            sceVu0CopyVector(tmp_vec, pRtaData->mat[1]);
            tmp_dot = (((RtaCVec *)tmp_vec)->x * air_move_vec[0] + ((RtaCVec *)tmp_vec)->y * air_move_vec[1] + ((RtaCVec *)tmp_vec)->z * air_move_vec[2]);
            tmp_dot *= pRtaTable->rta_param.vertical_air_decay;
            fsvu0_ScaleVector(tmp_vec, tmp_vec, tmp_dot);
            fsvu0_AddVector(move_vec, move_vec, tmp_vec);
            fsvu0_AddVector(new_fp_mat[3], (float *)((u8 *)new_fp_mat + 0x30), move_vec);
            check_hit = RhrCheckHit((struct dw_797362_fields *)s_RtaMng, pRtaFileHeader->rhr_file_id, (float *)new_pos, new_vec, (float *)old_fp_mat[3], (float *)move_vec, pRtaTable->rta_param.rebound_k, s_RtaMng[0x351], pRtaTable->rta_param.rhr_group_id);
            sceVu0CopyVector(new_fp_mat[3], new_pos);
            fsvu0_SubVector(tmp_oya_to_new_fp_vec, new_fp_mat[3], (float *)((u8 *)parent_mat + 0x30));
            fsvu0_Normalize(tmp_oya_to_new_fp_vec, tmp_oya_to_new_fp_vec);
            sceVu0CopyVector(tmp_z_vec, parent_mat[2]);
            tmp_z_vec[3] = 1.0f;
            fsvu0_Normalize(tmp_z_vec, tmp_z_vec);
            rad = ((RtaCVec *)tmp_z_vec)->x * tmp_oya_to_new_fp_vec[0] + ((RtaCVec *)tmp_z_vec)->y * tmp_oya_to_new_fp_vec[1] + ((RtaCVec *)tmp_z_vec)->z * tmp_oya_to_new_fp_vec[2];
            fsvu0_OuterProduct(rot_axis, tmp_z_vec, tmp_oya_to_new_fp_vec);
            fsvu0_Normalize(rot_axis, rot_axis);
            if (rad > -1.0f && rad < 1.0f) {
                rad = RtaCAcos(pRtaTable, rad);
            } else {
                rad = 0.0f;
            }
            if (rad > pRtaTable->rta_param.max_rot) {
                rad = pRtaTable->rta_param.max_rot;
            }
            if (rad < -pRtaTable->rta_param.max_rot) {
                rad = -pRtaTable->rta_param.max_rot;
            }
            RTAC_ROT();
            sceVu0CopyVector(tmp_vec, parent_mat[3]);
            fsvu0_MulMatrix(new_mat, rot, parent_mat);
            sceVu0CopyVector(new_mat[3], tmp_vec);
            sceVu0CopyMatrix(pRtaData->mat, new_mat);
            RtaCZVec(tmp_z_vec, pRtaData->mat[2], pRtaTable->rta_param.obj_len, pRtaData->mat[3]);
            fsvu0_SubVector(tmp_z_vec, tmp_z_vec, old_fp_mat[3]);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.move_vec_add_rate);
            tmp_dist = GetDist_((float *)g_ZeroVec, tmp_z_vec);
            if (tmp_dist > pRtaTable->rta_param.max_vec) {
                tmp_dist = pRtaTable->rta_param.max_vec;
            }
            fsvu0_Normalize(tmp_z_vec, tmp_z_vec);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, tmp_dist);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.vec_decay);
            if (check_hit == 1) {
                fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.hit_decay);
            }
            sceVu0CopyVector(pRtaData->vec, tmp_z_vec);
            }
            }
            RTAC_TAIL();
            break;
        }
        case 4: {
            float tmp_vec[4];
            RtaCData *pRtaData_A;
            RtaCData *pRtaData_B;
            float a_b_dist;
            float tmp_f;
            float tmp_vec_A[4];
            float tmp_vec_B[4];
            float rate;
            float tmp_fb;
            float wa = 0.0f;
            float wb = 1.0f;

            pRtaTable_A = (RtaCTable *)(pRtaFileBuf + (pRtaTable->mdl_obj_id << 8) + 0x20);
            pRtaTable_B = (RtaCTable *)(pRtaFileBuf + (pRtaTable->anm_obj_id << 8) + 0x20);
            pRtaData_A = &pRtaData_root[pRtaTable_A->id];
            pRtaData_B = &pRtaData_root[pRtaTable_B->id];
            RtaCZVec(tmp_vec_A, pRtaData_A->mat[2], pRtaTable_A->rta_param.obj_len, pRtaData_A->mat[3]);
            RtaCZVec(tmp_vec_B, pRtaData_B->mat[2], pRtaTable_B->rta_param.obj_len, pRtaData_B->mat[3]);
            fsvu0_SubVector(tmp_vec, tmp_vec_B, tmp_vec_A);
            a_b_dist = GetDist_((float *)g_ZeroVec, tmp_vec);
            rate = 1.0f;
            fsvu0_Normalize(tmp_vec, tmp_vec);
            tmp_f = wa * (a_b_dist - pRtaTable->rta_param.obj_len);
            tmp_fb = wb * (a_b_dist - pRtaTable->rta_param.obj_len);
            if (a_b_dist < pRtaTable->rta_param.max_length) {
                if (a_b_dist > pRtaTable->rta_param.min_length) {
                    rate = pRtaTable->rta_param.spring_k;
                }
            }
            tmp_f = tmp_f * rate;
            fsvu0_ScaleVector(tmp_vec_A, tmp_vec, tmp_f);
            tmp_fb = tmp_fb * rate;
            fsvu0_ScaleVector(tmp_vec_B, tmp_vec, -tmp_fb);
            fsvu0_AddVector(pRtaData_A->vec, pRtaData_A->vec, tmp_vec_A);
            fsvu0_AddVector(pRtaData_B->vec, pRtaData_B->vec, tmp_vec_B);
            RTAC_TAIL();
            break;
        }
        case 5: {
            float old_mat[4][4];
            float old_fp_mat[4][4];
            float parent_mat[4][4];
            float new_fp_mat[4][4];
            float new_mat[4][4];
            float tmp_vec[4];
            float tmp_z_vec[4];
            float tmp_dist;
            float tmp_dot;
            float move_vec[4] = {0.0f, 0.0f, 0.0f, 1.0f};

            sceVu0CopyMatrix(old_mat, pRtaData->mat);
            sceVu0CopyVector(tmp_z_vec, old_mat[2]);
            tmp_z_vec[3] = 1.0f;
            fsvu0_ScaleVector(tmp_vec, tmp_z_vec, pRtaTable->rta_param.obj_len);
            sceVu0CopyMatrix(old_fp_mat, old_mat);
            fsvu0_AddVector(old_fp_mat[3], (float *)((u8 *)old_fp_mat + 0x30), tmp_vec);
            sceVu0CopyMatrix(new_fp_mat, old_fp_mat);
            if (pRtaTable->follow_mdl_or_anm == 1) {
                if (pRtaTable_parent != 0) {
                    sceVu0CopyMatrix(parent_mat, pRtaData_root[pRtaTable_parent->id].mat);
                    sceVu0CopyVector(tmp_z_vec, pRtaData_root[pRtaTable_parent->id].mat[2]);
                    tmp_z_vec[3] = 1.0f;
                    fsvu0_ScaleVector(tmp_vec, tmp_z_vec, pRtaTable_parent->rta_param.obj_len);
                    fsvu0_AddVector(parent_mat[3], parent_mat[3], tmp_vec);
                } else if (pRtaTable_parent == 0) {
                    sceVu0CopyMatrix(parent_mat, pRtaData->mat);
                }
            } else if (pRtaTable->follow_mdl_or_anm == 0) {
                sceVu0CopyMatrix(parent_mat, GetMdlObjWMat(s_RtaMng[0x351], pRtaTable->mdl_obj_id, s_RtaMng[0x352]));
            }
            {
            float gravity[4] = {0.0f, 0.0f, 0.0f, 1.0f};
            float air_move_vec[4];
            float wind_vec[4];
            float new_pos[4];
            float new_vec[4];
            float rot_axis[4];
            float rad;
            float rot[4][4];
            float tmp_oya_to_new_fp_vec[4];
            gravity[1] = pRtaTable->rta_param.gravity;
            gravity[0] = 0.0f;
            *(float *)((u8 *)gravity + 4) = pRtaTable->rta_param.gravity;
            gravity[2] = 0.0f;
            gravity[3] = 1.0f;
            fsvu0_AddVector(tmp_vec, (float *)g_ZeroVec, pRtaData->vec);
            fsvu0_ScaleVector(move_vec, tmp_vec, 1.0f / pRtaTable->rta_param.vec_move_add_rate);
            fsvu0_AddVector(move_vec, move_vec, gravity);
            if (pRtaTable->table_data_flag.wind_type) {
            RtaCWind(tmp_vec, old_mat[3], pRtaFileHeader->rhr_file_id);
                fsvu0_AddVector(move_vec, move_vec, tmp_vec);
            } else {
            RtaCWind(wind_vec, old_mat[3], pRtaFileHeader->rhr_file_id);
                sceVu0CopyVector(air_move_vec, move_vec);
                fsvu0_SubVector(air_move_vec, air_move_vec, wind_vec);
                sceVu0CopyVector(pRtaData->air_move_vec, air_move_vec);
                tmp_dist = GetDist_((float *)g_ZeroVec, air_move_vec);
                tmp_dist = tmp_dist * pRtaTable->rta_param.air_decay;
                fsvu0_Normalize(tmp_vec, air_move_vec);
                fsvu0_ScaleVector(tmp_vec, tmp_vec, tmp_dist);
                fsvu0_AddVector(move_vec, move_vec, tmp_vec);
                sceVu0CopyVector(tmp_vec, pRtaData->mat[1]);
                tmp_dot = (((RtaCVec *)tmp_vec)->x * air_move_vec[0] + ((RtaCVec *)tmp_vec)->y * air_move_vec[1] + ((RtaCVec *)tmp_vec)->z * air_move_vec[2]);
            tmp_dot *= pRtaTable->rta_param.vertical_air_decay;
                fsvu0_ScaleVector(tmp_vec, tmp_vec, tmp_dot);
                fsvu0_AddVector(move_vec, move_vec, tmp_vec);
            }
            fsvu0_AddVector(new_fp_mat[3], (float *)((u8 *)new_fp_mat + 0x30), move_vec);
            fsvu0_CopyVectorF(pRtaData->tmp_fp_pos, new_fp_mat[3]);
            check_hit = RhrCheckHit((struct dw_797362_fields *)s_RtaMng, pRtaFileHeader->rhr_file_id, (float *)new_pos, new_vec, (float *)old_fp_mat[3], (float *)move_vec, pRtaTable->rta_param.rebound_k, s_RtaMng[0x351], pRtaTable->rta_param.rhr_group_id);
            sceVu0CopyVector(new_fp_mat[3], new_pos);
            fsvu0_SubVector(tmp_oya_to_new_fp_vec, new_fp_mat[3], (float *)((u8 *)parent_mat + 0x30));
            fsvu0_Normalize(tmp_oya_to_new_fp_vec, tmp_oya_to_new_fp_vec);
            sceVu0CopyVector(tmp_z_vec, parent_mat[2]);
            tmp_z_vec[3] = 1.0f;
            rad = ((RtaCVec *)tmp_z_vec)->x * tmp_oya_to_new_fp_vec[0] + ((RtaCVec *)tmp_z_vec)->y * tmp_oya_to_new_fp_vec[1] + ((RtaCVec *)tmp_z_vec)->z * tmp_oya_to_new_fp_vec[2];
            fsvu0_OuterProduct(rot_axis, tmp_z_vec, tmp_oya_to_new_fp_vec);
            fsvu0_Normalize(rot_axis, rot_axis);
            if (rad > -1.0f && rad < 1.0f) {
                rad = RtaCAcos(pRtaTable, rad);
            } else {
                rad = 0.0f;
            }
            if (rad > pRtaTable->rta_param.max_rot) {
                rad = pRtaTable->rta_param.max_rot;
            }
            if (rad < -pRtaTable->rta_param.max_rot) {
                rad = -pRtaTable->rta_param.max_rot;
            }
            RTAC_ROT();
            sceVu0CopyVector(tmp_vec, parent_mat[3]);
            fsvu0_MulMatrix(new_mat, rot, parent_mat);
            sceVu0CopyVector(new_mat[3], tmp_vec);
            sceVu0CopyMatrix(pRtaData->mat, new_mat);
            RtaCZVec(tmp_z_vec, pRtaData->mat[2], pRtaTable->rta_param.obj_len, pRtaData->mat[3]);
            fsvu0_SubVector(tmp_z_vec, tmp_z_vec, old_fp_mat[3]);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.move_vec_add_rate);
            tmp_dist = GetDist_((float *)g_ZeroVec, tmp_z_vec);
            if (tmp_dist > pRtaTable->rta_param.max_vec) {
                tmp_dist = pRtaTable->rta_param.max_vec;
            }
            fsvu0_Normalize(tmp_z_vec, tmp_z_vec);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, tmp_dist);
            fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.vec_decay);
            if (check_hit == 1) {
                fsvu0_ScaleVector(tmp_z_vec, tmp_z_vec, pRtaTable->rta_param.hit_decay);
            }
            sceVu0CopyVector(pRtaData->vec, tmp_z_vec);
            }
            RTAC_TAIL();
        }
        }
    }
    return 1;
}


extern void sceVu0CopyMatrix(void *, void *);
extern void sceVu0CopyVector(void *, void *);
extern void * GetMdlObjWMat(unsigned int, unsigned int, unsigned int);
extern void fsvu0_MulMatrix(void *, void *, void *);
extern u32 g_ZeroVec[];

typedef struct RtaSM_Table { s32 index; u16 obj; u8 pad[6]; u8 type; u8 pad2[0x27]; s32 child; s32 sibling; u8 pad3[4]; float mat[4][4]; } RtaSM_Table;
typedef struct RtaSM_Data { u8 pad[0x40]; float mat[4][4]; float vec[4]; u8 pad2[0x200 - 0x90]; } RtaSM_Data;
typedef struct RtaSM_Mdl { u8 pad[0x10]; float (*wmat)[4][4]; float (*lmat)[4][4]; } RtaSM_Mdl;
#define RTASM_MDL ((RtaSM_Mdl *)s_RtaMng[0x351])
#define pRtaTable ((RtaSM_Table *)pRtaTable_)
#define pRtaData_root ((RtaSM_Data *)pRtaData_root_)
#define RTASM_KIND (s_RtaMng[0x352])

static signed int RtaMngSetMat(unsigned char *pRtaFileBuf, void *pRtaTable_, void *pRtaTable_parent,
        void *pRtaData_root_, void *mat, int set_mat_type) {
    RtaSM_Table *pRtaTable_child;
    RtaSM_Table *pRtaTable_sibling;
    RtaSM_Data *pRtaData;

    if (pRtaFileBuf == 0) {
        return 0;
    }
    if (pRtaTable_ == 0) {
        return 0;
    }
    if (pRtaData_root_ == 0) {
        return 0;
    }
    pRtaData = &pRtaData_root[pRtaTable->index];
    {
        float old_mat[4][4];
        sceVu0CopyMatrix(old_mat, pRtaData->mat);
    }
    switch ((u8)set_mat_type) {
    case 0:
        break;
    case 1: {
        float tmpMat[4][4];
        sceVu0CopyMatrix(pRtaData->mat, pRtaTable->mat);
        sceVu0CopyVector(pRtaData->vec, g_ZeroVec);
        sceVu0CopyMatrix(tmpMat, GetMdlObjWMat(s_RtaMng[0x351], pRtaTable->obj, s_RtaMng[0x352]));
        fsvu0_MulMatrix(pRtaData->mat, tmpMat, pRtaData->mat);
        break;
    }
    }
    pRtaTable_child = (RtaSM_Table *)(pRtaFileBuf + pRtaTable->child);
    pRtaTable_sibling = (RtaSM_Table *)(pRtaFileBuf + pRtaTable->sibling);
    if ((unsigned char *)pRtaTable_child != pRtaFileBuf) {
        RtaMngSetMat(pRtaFileBuf, pRtaTable_child, pRtaTable, pRtaData_root, mat, set_mat_type);
    }
    if ((unsigned char *)pRtaTable_sibling != pRtaFileBuf) {
        RtaMngSetMat(pRtaFileBuf, pRtaTable_sibling, pRtaTable_parent, pRtaData_root, mat, set_mat_type);
    }
    if (pRtaTable->type != 2) {
        float tmpMat[4][4];
        switch ((u8)set_mat_type) {
        case 0:
            fsvu0_MulMatrix(tmpMat, mat, pRtaData->mat);
            break;
        case 1:
            sceVu0CopyMatrix(tmpMat, pRtaData->mat);
            break;
        }
        if (s_stabilize_on == 0) {
            u32 kind = RTASM_KIND;
            RtaSM_Mdl *mdl = RTASM_MDL;
            u32 obj = pRtaTable->obj;
            if (mdl != 0) {
                switch (kind) {
                case 0: sceVu0CopyMatrix(mdl->wmat[obj], tmpMat); break;
                case 1: sceVu0CopyMatrix(mdl->lmat[obj], tmpMat); break;
                default: sceVu0CopyMatrix(mdl->wmat[obj], tmpMat); break;
                }
            }
        }
    }
    return 1;
}
#undef pRtaTable
#undef pRtaData_root


/* RtaMng_GetRtaParamFromObjectId @ 0x169CC0 .. 0x169D90 (0xd0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x169d08 writes a register its branch at 0x169d04 reads
 *   cfg: kept branch: 0x169cd0 if (..) goto .L00169D00
 *   cfg: kept goto: 0x169cfc -> .L00169D78
 *   cfg: kept branch: 0x169d3c if (..) goto .L00169D70
 *   declaration vs inferred signature: return void * vs inferred u32
 */

extern signed int MngState_DrawExeCheck(void *);
extern void * RtaMng_GetRtaParamFromObjectId_R(unsigned char *, void *, unsigned int);

void * RtaMng_GetRtaParamFromObjectId(unsigned int a0 /* r4 */, unsigned int a1 /* r5 */, unsigned
        int a2 /* r6 */) {
    u32 s2;
    u32 s1;
    u32 s0;
    unsigned int a2_2; // a2
    unsigned int a1_2; // a1
    unsigned int a0_2;
    u32 v1;
    u32 v0;

    s2 = a0;
    s1 = a1;
    s0 = a2;
    a0_2 = (unsigned int)s_RtaMng;
    v0 = MngState_DrawExeCheck((void *)s_RtaMng);
    v1 = 1;
    if (v0 == v1) {
        goto _L00169D00;
    }
    v0 = 0;
    goto _L00169D78;
    _L00169D00:;
    if ((u32)(s2 < (u32)0x302) == 0) {
        return (void *)0;
    }
    v1 = s2 << 2;
    s_RtaMng[0x351] = s1;
    v0 = *(s32 *)(s32)((u8 *)(u8 *)(s_RtaMng + 0x4e) + v1);
    if (v0 != 0) {
        v1 = (u32)*(s32 *)v0 << 2;
        v0 = (s32)((u8 *)(u8 *)(s_RtaMng + 8) + v1);
        a0_2 = *(s32 *)v0;
        a2_2 = s0;
        if ((u32)(s32)a0_2 == 0) {
            goto _L00169D70;
        }
        a1_2 = (u32)(a0_2) + 0x20;
        v0 = (u32)RtaMng_GetRtaParamFromObjectId_R((unsigned char *)a0_2, (void *)a1_2, a2_2);
    } else {
        _L00169D70:;
        v0 = 0;
    }
    _L00169D78:;
    return (void *)v0;
}

/* RtaMng_GetRtaParamFromObjectId_R @ 0x169BF0 .. 0x169CB8 (0xc8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   delay: daddu at 0x169c30 writes a register its branch at 0x169c2c reads
 *   cfg: kept goto: 0x169c14 -> .L00169CA0
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * RtaMng_GetRtaParamFromObjectId_R(unsigned char *a0 /* r4 */, void *a1 /* r5 */, unsigned int
        a2 /* r6 */) {
    u32 s2;
    s32 s1;
    u32 a1_index; // a1
    s32 s0;
    void *a1_2; // a1
    u32 v1;
    u32 v0;

    s2 = (u32)a0;
    s1 = a2;
    if (s2 == 0) {
        v0 = 0;
        goto _L00169CA0;
    }
    if ((u32)a1 == 0) {
        v0 = 0;
        return (void *)v0;
    }
    v0 = *(u16 *)(((u8 *)a1 + 4));
    if (v0 == (u32)s1) {
        v0 = (u32)a1;
        return (void *)v0;
    }
    v0 = *(s32 *)(((u8 *)a1 + 0x38));
    v1 = *(s32 *)(((u8 *)a1 + 0x34));
    a1_index = s2 + v1;
    s0 = s2 + v0;
    if (a1_index != s2) {
        v0 = (u32)RtaMng_GetRtaParamFromObjectId_R(a0, (void *)a1_index, a2);
        if (v0 != 0) {
            return (void *)v0;
        }
    }
    a0 = (unsigned char *)s2;
    if ((u32)s0 != s2) {
        a1_2 = (void *)s0;
        a2 = (s32)s1;
        v0 = (u32)RtaMng_GetRtaParamFromObjectId_R(a0, a1_2, a2);
        if (v0 != 0) {
            return (void *)v0;
        }
    }
    v0 = 0;
    _L00169CA0:;
    return (void *)v0;
}


/* RhrCheckHit @ 0x169950 .. 0x169BEC (0x29c bytes, frame 0x150) */
/*
 * dcomp notes:
 *   fpu: mov.s at 0x1699a4 is a float copy
 *   stack: address of the slot at 0x140 escapes at 0x1699b8
 *   stack: address of the slot at 0x140 escapes at 0x1699c4
 *   stack: address of the slot at 0x130 escapes at 0x169a44
 *   stack: address of the slot at 0x140 escapes at 0x169a68
 *   stack: address of the slot at 0x140 escapes at 0x169a84
 *   stack: address of the slot at 0xf0 escapes at 0x169ab8
 *   stack: address of the slot at 0xe0 escapes at 0x169ae0
 *   stack: address of the slot at 0xf0 escapes at 0x169ae0
 *   stack: address of the slot at 0xd0 escapes at 0x169af0
 *   stack: address of the slot at 0x140 escapes at 0x169af0
 *   stack: address of the slot at 0xe0 escapes at 0x169af0
 *   stack: address of the slot at 0xd0 escapes at 0x169b30
 *   stack: address of the slot at 0xd0 escapes at 0x169b30
 *   stack: address of the slot at 0xd0 escapes at 0x169b40
 *   stack: address of the slot at 0xd0 escapes at 0x169b40
 *   stack: address of the slot at 0xe0 escapes at 0x169b50
 *   stack: address of the slot at 0xd0 escapes at 0x169b50
 *   stack: address of the slot at 0x140 escapes at 0x169b74
 *   cfg: loop body is not one contiguous region: .L001699D8
 *   cfg: loop body is not one contiguous region: .L00169A10
 */

extern void fsvu0_AddVector(float *, float *, float *);
extern void fsvu0_ApplyMatrix(float *, void *, float *);
extern void fsvu0_SubVector(float *, float *, float *);
extern float GetDist_(float *, float *);
extern void fsvu0_Normalize(float *, float *);
extern void fsvu0_ScaleVector(float *, float *, float);

struct dw_797714_fields;
#ifndef PROTO_DW_801078_FIELDS
#define PROTO_DW_801078_FIELDS
struct dw_801078_fields { int state; unsigned int flag; unsigned int calc_total_time; unsigned int total_time; unsigned int get_time; unsigned int dmy[3]; };
#endif
#ifndef PROTO_DW_797362_FIELDS
#define PROTO_DW_797362_FIELDS
struct dw_797362_fields { struct dw_801078_fields mng_state; unsigned char *pRtaFileBuf[35]; unsigned char *pRhrFileBuf[35]; struct dw_797714_fields *pRtaDataBuf[770]; unsigned char *pRtaBndBuf; unsigned int mdl_handle; unsigned int buf_id; unsigned int dmy[2]; };
#endif

#ifndef DCOMP_OFF_STRUCT_DW_797362_FIELDS_BUF_ID_51EFD2DD_DEFINED
#define DCOMP_OFF_STRUCT_DW_797362_FIELDS_BUF_ID_51EFD2DD_DEFINED
enum { DCOMP_OFF_STRUCT_DW_797362_FIELDS_BUF_ID_51EFD2DD = (int)&(((struct dw_797362_fields *)0)->buf_id) - 0 };
#endif
#ifndef DCOMP_OFF_STRUCT_DW_797362_FIELDS_PRHRFILEBUF__0___02DD4F5B_DEFINED
#define DCOMP_OFF_STRUCT_DW_797362_FIELDS_PRHRFILEBUF__0___02DD4F5B_DEFINED
enum { DCOMP_OFF_STRUCT_DW_797362_FIELDS_PRHRFILEBUF__0___02DD4F5B = (int)&(((struct dw_797362_fields *)0)->pRhrFileBuf[0]) - 0 };
#endif
struct RhrParam { int type; int node; int pad0[2]; float vec[4]; int pad1[4]; float rad; float rk; };
struct RhrHdr { int pad0[6]; u32 paramSize; int pad1; struct { u32 ofs; u32 num; } tbl[12]; };
struct RhrM64 { u32 w[16]; };
unsigned int RhrCheckHit(struct dw_797362_fields *pRtaMng, unsigned int rhr_file_id, float *new_pos, float *unused_a3, float *_old_pos, float *_move_vec, float rebound_k, unsigned int mdl_handle, unsigned int check_type_flag) {
    unsigned int i;
    float old_pos[4];
    float tmp130[4];
    struct RhrM64 mat;
    float tmpE0[4];
    float tmpD0[4];
    unsigned int check_hit;
    struct RhrHdr *pRhrFileHeader;
    struct RhrParam *pRhrParam;
    unsigned int j;
    int hit;
    unsigned int buf;
    float f21, f20, f0, f2, dist, dist2, f3;
    float *pPos;
    u32 *pEnt;
    struct RhrM64 *m;

    pRhrFileHeader = (struct RhrHdr *)pRtaMng->pRhrFileBuf[rhr_file_id];
    if (pRhrFileHeader == 0) {
        return 1;
    }
    fsvu0_AddVector(old_pos, _old_pos, _move_vec);
    fsvu0_CopyVectorF(new_pos, old_pos);
    i = 0;
    pEnt = (u32 *)pRhrFileHeader;
    pPos = (float *)(mdl_handle + 0x20);
    for (; i < 12; i++, pEnt += 2) {
        if (check_type_flag & (1 << i)) {
            if (pEnt[9] != 0) {
                pRhrParam = (struct RhrParam *)((u8 *)pRhrFileHeader + pEnt[8]);
                for (j = 0; j < pEnt[9]; j++) {
                    buf = s_RtaMng[0x352];
                    hit = 0;
                    switch (pRhrParam->type) {
                    case 2:
                        sceVu0CopyVector(tmp130, pPos);
                        f21 = tmp130[1];
                        f0 = old_pos[1];
                        if (f0 <= f21) {
                            fsvu0_CopyVectorF(new_pos, old_pos);
                        } else {
                            f20 = f0 - f21;
                            f20 = f20 * rebound_k;
                            fsvu0_CopyVectorF(new_pos, old_pos);
                            new_pos[1] = f21 - f20;
                            hit = 1;
                        }
                        break;
                    case 7:
                        m = (struct RhrM64 *)GetMdlObjWMat(mdl_handle, pRhrParam->node, buf);
                        mat = *m;
                        fsvu0_ApplyMatrix(tmpE0, &mat, pRhrParam->vec);
                        fsvu0_SubVector(tmpD0, old_pos, tmpE0);
                        dist = GetDist_((float *)g_ZeroVec, tmpD0);
                        f2 = pRhrParam->rad;
                        if (!(dist < f2)) break;
                        f21 = f2 - dist;
                        f21 = f21 * rebound_k;
                        f2 -= dist;
                        f20 = dist + pRhrParam->rk * f2;
                        fsvu0_Normalize(tmpD0, tmpD0);
                        fsvu0_ScaleVector(tmpD0, tmpD0, f20 + f21);
                        fsvu0_AddVector(new_pos, tmpE0, tmpD0);
                        hit = 1;
                    }
                    if (hit == 1) {
                        check_hit = 1;
                    }
                    fsvu0_CopyVectorF(old_pos, new_pos);
                    pRhrParam = (struct RhrParam *)((u8 *)pRhrParam + pRhrFileHeader->paramSize);
                }
            }
        }
    }
    return check_hit;
}






/* Rta_BndReadEndCallBack @ 0x1698B0 .. 0x169944 (0x94 bytes, frame 0x130) */
/*
 * dcomp notes:
 *   literal: @1350 is the string 'rta%04d.rta'
 *   literal: @1351 is the string 'rhr%04d.rhr'
 *   stack: address of the slot at 0x30 escapes at 0x1698dc
 *   stack: address of the slot at 0x30 escapes at 0x169904
 */

extern int sprintf(void *, void *, ...);
extern unsigned int GetBindOffsetByName(void *, char *);


void Rta_BndReadEndCallBack(void) {
    s32 s1;
    u8 *s0;
    u8 *a1;
    u32 a0;
    s32 v1;
    u32 v0;
    u8 stackFrame_30[256] __attribute__((aligned(16)));

    s1 = 0;
    s0 = (u8 *)s_RtaMng;
    do {
        a1 = (u8 *)dcomp_ph_FUNCTION___734.rtaPattern;
        sprintf((void *)((u8 *)&stackFrame_30[0]), (void *)dcomp_ph_FUNCTION___734.rtaPattern, (u32)s1);
        a0 = *(s32 *)(s_RtaMng + 0x350);
        v0 = GetBindOffsetByName((void *)a0, (char *)(u8 *)((u8 *)&stackFrame_30[0]));
        *(u32 *)(s0 + 0x20) = v0;
        a1 = (u8 *)dcomp_ph_FUNCTION___734.rhrPattern;
        sprintf((void *)((u8 *)&stackFrame_30[0]), (void *)dcomp_ph_FUNCTION___734.rhrPattern, (u32)s1);
        a0 = *(s32 *)(s_RtaMng + 0x350);
        v0 = GetBindOffsetByName((void *)a0, (char *)(u8 *)((u8 *)&stackFrame_30[0]));
        s1 = s1 + 1;
        *(u32 *)(s0 + 0xac) = v0;
        v1 = s1 < (s32)0x23;
        s0 = (u8 *)(s0 + 4);
    } while ((u32)v1 != 0);
    return;
}
static u32 s_RtaMng[0x355];
s32 g_RtaNoUpdate = 1;
static u32 s_stabilize_on;
