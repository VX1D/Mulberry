#include "common.h"




typedef struct MCE { u8 pad[0x78]; s32 id; u8 pad2[0x90 - 0x7c]; } MCE;
typedef struct MCH { u8 pad[0x14]; u32 num; } MCH;
typedef struct MMng { u8 pad[0x60]; MCH *head; MCE *pe; } MMng;
typedef struct { u8 pad[0x14]; u32 num; } MENUINFOX;
typedef struct {
    s32 state;
    u8 pad04[0x5c];
    MENUINFOX *pInfo;
    u8 *pCtrl;
    u8 pad68[4];
    s32 file_id;
    s32 x70;
    s32 x74;
    s32 x78;
} MENUMNGX;
extern signed int MngState_UpdateExeCheck(void *);
extern signed int MenuCtrlMng_GetTexId(void *);
extern signed int MenuCtrlMng_Delete(void *);
extern void MemFree(void *);
extern signed int MngState_DrawExeCheck(void *);
extern signed int MenuCtrlMng_Draw(void *);
extern int sprintf(char *, const char *, ...);
extern signed int MenuReadFile(unsigned char **, char *);
extern void * _MemAlloc(unsigned int);
extern signed int MenuCtrlMng_Initialize(void *);
extern signed int MenuCtrlMng_Init(void *, signed int, signed int, unsigned char *);
extern signed int MngState_Init(void *);
void * MenuMng_GetDrawPos(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */);
signed int MenuMng_CheckCtrlPlayWait(void *a0 /* r4 */, signed int a1 /* r5 */);
signed int MenuMng_CheckCtrlPlay(void *a0 /* r4 */, signed int a1 /* r5 */);
signed int MenuMng_GetCursorId(MMng *pMenuMng, u32 ctrl);
signed int MenuMng_GetTexId(void *a0 /* r4 */);
signed int MenuMng_PlayMenu(void *a0 /* r4 */, void *a1 /* r5 */);
signed int MenuMng_Delete(void *a0 /* r4 */);
signed int MenuMng_Draw(void *a0 /* r4 */);
static signed int MenuMng_Alloc(u8 *pMenuMng, unsigned char *pPath);
signed int MenuMng_Init(void *a0, signed int file_id, unsigned char *pPath);
u32 MenuMng_Initialize(u32 *a0 /* r4 */);

/* MenuMng_Initialize @ 0x1D9580 .. 0x1D9594 (0x14 bytes) */




u32 MenuMng_Initialize(u32 *a0 /* r4 */) {
    u32 v0;

    *(u32 *)(((u8 *)a0 + 0x60)) = 0;
    v0 = 1;
    *(u32 *)(((u8 *)a0 + 0x64)) = 0;
    *(u32 *)(((u8 *)a0 + 0x68)) = 0;
    return v0;
}










static inline signed int MenuMng_DeleteX(MENUMNGX *pMenuMng) {
    u32 i;

    if (pMenuMng == 0) {
        return 0;
    }
    if (pMenuMng != 0) {
        if (pMenuMng->pInfo != 0) {
            for (i = 0; i < pMenuMng->pInfo->num; i++) {
                if (MenuCtrlMng_Delete(pMenuMng->pCtrl + i * 0x90) == 0) {
                    goto end;
                }
            }
        }
        MemFree(pMenuMng->pCtrl);
        pMenuMng->pCtrl = 0;
        pMenuMng->pInfo = 0;
    }
end:
    pMenuMng->state = 0;
    return 1;
}

signed int MenuMng_Init(void *a0, signed int file_id, unsigned char *pPath) {
    MENUMNGX *pMenuMng = a0;
    unsigned char aPath[256];

    if (pMenuMng == 0) {
        return 0;
    }
    MngState_Init(pMenuMng);
    pMenuMng->file_id = file_id;
    pMenuMng->x70 = -1;
    pMenuMng->x74 = 0;
    pMenuMng->x78 = 0;
    sprintf((char *)aPath, "%s\\menu%04d", pPath, pMenuMng->file_id);
    if (MenuMng_Alloc((u8 *)pMenuMng, aPath) != 1) {
        MenuMng_DeleteX(pMenuMng);
        return 0;
    }
    pMenuMng->state = 2;
    return 1;
}





static signed int MenuMng_Alloc(u8 *pMenuMng, unsigned char *pPath) {
    unsigned int i;
    int ret;
    u8 *pMenuFileHeader;
    u8 *pMenuParam;
    char path[256] __attribute__((aligned(16)));

    if (pMenuMng == 0) {
        return 0;
    }
    if (pMenuMng != 0) {
        if (*(u8 **)(pMenuMng + 0x60) != 0) {
            unsigned int j;
            for (j = 0; j < *(u32 *)(*(u8 **)(pMenuMng + 0x60) + 0x14); j++) {
                if (MenuCtrlMng_Delete(*(u8 **)(pMenuMng + 0x64) + j * 0x90) == 0) {
                    goto read;
                }
            }
        }
        MemFree(*(void **)(pMenuMng + 0x64));
        *(u32 *)(pMenuMng + 0x64) = 0;
        *(u32 *)(pMenuMng + 0x60) = 0;
    }
read:
    sprintf(path, "menu%04d.mnm", *(s32 *)(pMenuMng + 0x6c));
    ret = MenuReadFile((unsigned char **)(pMenuMng + 0x60), path) == 1;
    if (ret != 1) {
        return 0;
    }
    pMenuFileHeader = *(u8 **)(pMenuMng + 0x60);
    pMenuParam = pMenuFileHeader + *(s32 *)(pMenuFileHeader + 0x18);
    if ((*(void **)(pMenuMng + 0x64) = _MemAlloc(*(u32 *)(pMenuFileHeader + 0x14) * 0x90)) == 0) {
        return 0;
    }
    for (i = 0; i < *(u32 *)(*(u8 **)(pMenuMng + 0x60) + 0x14); i++, pMenuParam += 0x20) {
        MenuCtrlMng_Initialize(*(u8 **)(pMenuMng + 0x64) + i * 0x90);
        if (MenuCtrlMng_Init(*(u8 **)(pMenuMng + 0x64) + i * 0x90, *(s32 *)pMenuParam, *(s32 *)(pMenuMng + 0x6c), pPath) == 0) {
            return 0;
        }
    }
    return 1;
}


extern void SetCtrlFuncCtrlId(signed int);
extern signed int MenuCtrlMng_Update(void *, void *, signed int);
extern signed int Menu_CallMenu(unsigned char *, signed int, unsigned int);
extern void Menu_SetNoSndOff(signed int);

typedef struct MU_CTRL { u8 pad[0x84]; s8 state_order; u8 pad2[0x90 - 0x85]; } MU_CTRL;
typedef struct MU_MNG {
    u8 pad[0x60];
    u8 *pMenuFileBuf;
    MU_CTRL *pMenuCtrlMng;
    struct MU_MNG *pMenuMng_Open;
    s32 file_id;
    s32 now_ctrl_node;
    s32 update_off;
    s32 key_off;
} MU_MNG;
typedef struct { u8 pad[0x14]; u32 ctrl_num; u32 data_offset; u32 flag; } MU_HDR;
typedef struct {
    s32 id;
    s32 dmyA;
    s32 menu_id;
    s32 dmy;
    s32 child_id;
    s32 sibling_id;
    s32 parent_id;
    u32 decide_restart : 1;
    u32 cancel_restart : 1;
    u32 reserve : 30;
} MU_PARAM;
typedef struct {
    s8 get_state;
    s32 get_goto;
    s32 get_goto_order;
    s32 get_call_menu_id;
    s32 dmy2[7];
} MU_GS;

static inline s32 MU_GSInit(MU_GS *p) {
    if (p == 0) {
        return 0;
    }
    p->get_state = 0xc;
    p->get_goto = 0;
    p->get_goto_order = 0;
    p->get_call_menu_id = -1;
    return 1;
}

static inline void MU_SetNode(MU_MNG *m, s32 node, s32 bRestart) {
    m->now_ctrl_node = node;
    if (node >= 0 && bRestart) {
        *((s8 *)((u8 *)m->pMenuCtrlMng + m->now_ctrl_node * 0x90) + 0x84) = 3;
    } else if (node < 0) {
        *((s8 *)((u8 *)m->pMenuCtrlMng + m->now_ctrl_node * 0x90) + 0x84) = 0;
    }
}

signed int MenuMng_Update(void *a0) {
    MU_MNG *pMenuMng = (MU_MNG *)a0;
    s32 i;
    MU_GS CtrlGS;
    MU_HDR *pMenuFileHeader;
    MU_PARAM *pMenuParam;
    s32 exit_menu;
    s32 tmp_ncn;
    s32 gg;
    s32 k;
    s32 child;

    if (pMenuMng == 0) {
        return 0;
    }
    if (MngState_UpdateExeCheck(pMenuMng) != 1) {
        return 0;
    }
    if (pMenuMng->update_off == 1) {
        return 0;
    }
    if (pMenuMng->now_ctrl_node < 0) {
        return 0;
    }
    if (pMenuMng->now_ctrl_node >= 0) {
    pMenuFileHeader = (MU_HDR *)pMenuMng->pMenuFileBuf;
    exit_menu = 0;
    i = 0;
    pMenuParam = (MU_PARAM *)((u8 *)pMenuFileHeader + pMenuFileHeader->data_offset);
    for (i = 0; i < pMenuFileHeader->ctrl_num; i++) {
        SetCtrlFuncCtrlId(i);
        if (MU_GSInit(&CtrlGS) == 0) {
            return 0;
        }
        if (pMenuMng->now_ctrl_node != i) {
            if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[i], &CtrlGS, 0) != 1) {
                return 0;
            }
        }
    }
    SetCtrlFuncCtrlId(pMenuMng->now_ctrl_node);
    if (MU_GSInit(&CtrlGS) == 0) {
        return 0;
    }
    if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, (pMenuMng->key_off != 0) ^ 1) != 1) {
        return 0;
    }
    if (CtrlGS.get_call_menu_id > 0) {
        Menu_CallMenu((unsigned char *)pMenuMng, (u16)CtrlGS.get_call_menu_id, 0);
        goto L_end_move;
    }
    tmp_ncn = pMenuMng->now_ctrl_node;
    if (CtrlGS.get_goto == -2) {
        pMenuMng->now_ctrl_node = -1;
        *((s8 *)((u8 *)pMenuMng->pMenuCtrlMng + pMenuMng->now_ctrl_node * 0x90) + 0x84) = 0;
        exit_menu = CtrlGS.get_goto;
    }
    if (CtrlGS.get_goto == -1) {
        tmp_ncn = pMenuParam[tmp_ncn].parent_id;
        if (tmp_ncn == -1) {
            pMenuMng->now_ctrl_node = -1;
            exit_menu = -1;
            *((s8 *)((u8 *)pMenuMng->pMenuCtrlMng + pMenuMng->now_ctrl_node * 0x90) + 0x84) = 0;
        } else if (tmp_ncn == -2) {
            pMenuMng->now_ctrl_node = -1;
            exit_menu = -2;
            *((s8 *)((u8 *)pMenuMng->pMenuCtrlMng + pMenuMng->now_ctrl_node * 0x90) + 0x84) = 0;
        } else {
            MU_SetNode(pMenuMng, tmp_ncn, pMenuParam[tmp_ncn].cancel_restart);
            SetCtrlFuncCtrlId(pMenuMng->now_ctrl_node);
            Menu_SetNoSndOff(1);
            if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                return 0;
            }
            if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                return 0;
            }
            Menu_SetNoSndOff(0);
        }
    }
    if (CtrlGS.get_goto == 1) {
        tmp_ncn = pMenuParam[tmp_ncn].child_id;
        if (tmp_ncn == -1) {
            MU_SetNode(pMenuMng, pMenuMng->now_ctrl_node, 1);
            goto L_ret1;
        }
        if (pMenuParam[tmp_ncn].menu_id >= 0) {
            Menu_CallMenu((unsigned char *)pMenuMng, pMenuParam[tmp_ncn].menu_id, 0);
        } else {
            MU_SetNode(pMenuMng, tmp_ncn, pMenuParam[tmp_ncn].decide_restart);
            SetCtrlFuncCtrlId(pMenuMng->now_ctrl_node);
            Menu_SetNoSndOff(1);
            if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                return 0;
            }
            if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                return 0;
            }
            Menu_SetNoSndOff(0);
        }
    }
    gg = CtrlGS.get_goto;
    if (gg > 1) {
        child = pMenuParam[tmp_ncn].child_id;
        if (child == -1) {
            MU_SetNode(pMenuMng, pMenuMng->now_ctrl_node, 1);
        } else {
            for (k = 1; k < gg; k++) {
                child = pMenuParam[child].sibling_id;
                if (child == -1) {
                    break;
                }
            }
            if (child == -1) {
                MU_SetNode(pMenuMng, pMenuMng->now_ctrl_node, 1);
            } else if (k == gg) {
                if (pMenuParam[child].menu_id >= 0) {
                    Menu_CallMenu((unsigned char *)pMenuMng, pMenuParam[child].menu_id, 0);
                } else {
                    MU_SetNode(pMenuMng, child, pMenuParam[child].decide_restart);
                    SetCtrlFuncCtrlId(pMenuMng->now_ctrl_node);
                    Menu_SetNoSndOff(1);
                    if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                        return 0;
                    }
                    if (MenuCtrlMng_Update(&pMenuMng->pMenuCtrlMng[pMenuMng->now_ctrl_node], &CtrlGS, 0) != 1) {
                        return 0;
                    }
                    Menu_SetNoSndOff(0);
                }
            }
        }
    }
L_end_move:
    if (exit_menu != 0) {
        if (pMenuMng->pMenuMng_Open != 0) {
            if (exit_menu == -1) {
                MU_SetNode(pMenuMng->pMenuMng_Open, pMenuMng->pMenuMng_Open->now_ctrl_node, pMenuMng->pMenuMng_Open->update_off);
            }
            if (exit_menu == -2) {
                MU_MNG *pOpen = pMenuMng->pMenuMng_Open;
                pOpen->now_ctrl_node = -1;
                *((s8 *)((u8 *)pOpen->pMenuCtrlMng + pOpen->now_ctrl_node * 0x90) + 0x84) = 0;
            }
            pMenuMng->pMenuMng_Open->update_off = 0;
            pMenuMng->pMenuMng_Open->key_off = 0;
            goto L_ret1;
        }
        return 0;
    }
    }
L_ret1:
    return 1;
}








/* MenuMng_Draw @ 0x1D8900 .. 0x1D89E4 (0xe4 bytes, frame 0x50) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d8950 writes a register its branch at 0x1d894c reads
 *   cfg: kept branch: 0x1d8910 if (..) goto .L001D8928
 *   cfg: kept goto: 0x1d8924 -> .L001D89C8
 *   cfg: kept branch: 0x1d8928 if (..) goto .L001D8948
 *   cfg: kept goto: 0x1d8940 -> .L001D89C8
 *   cfg: loop body is not one contiguous region: .L001D8988
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuMng_Draw(void *a0 /* r4 */) {
    u8 *s3;
    s32 v1;
    s32 s2;
    u8 *s1;
    s32 s0;
    u32 v0;

    s3 = (u8 *)a0;
    if ((u32)s3 != 0) {
        goto _L001D8928;
    }
    v0 = 0;
    goto _L001D89C8;
    _L001D8928:;
    v0 = MngState_DrawExeCheck(a0);
    v1 = 1;
    if (v0 == (u32)v1) {
        goto _L001D8948;
    }
    v0 = 0;
    goto _L001D89C8;
    _L001D8948:;
    v0 = *(s32 *)(s3 + 0x74);
    if (v0 == (u32)v1) {
        v0 = 0;
        return v0;
    }
    v0 = *(s32 *)(s3 + 0x70);
    if ((s32)v0 >= 0) {
        s1 = (u8 *)*(s32 *)(s3 + 0x60);
        v0 = *(s32 *)(s1 + 0x14);
        s2 = 0;
        if ((u8 *)0 < (u8 *)v0) {
            s0 = 0;
            do {
                v0 = *(s32 *)(s3 + 0x64);
                a0 = (void *)(s32)(v0 + s0);
                v0 = MenuCtrlMng_Draw(a0);
                v1 = 1;
                if (v0 != (u32)v1) {
                    v0 = v1;
                    return v0;
                }
                v0 = *(s32 *)(s1 + 0x14);
                s2 = s2 + 1;
                v0 = (u32)s2 < v0;
                s0 = s0 + 0x90;
            } while (v0 != 0);
        }
    }
    v0 = 1;
    _L001D89C8:;
    return v0;
}


/* MenuMng_Delete @ 0x1D8850 .. 0x1D8900 (0xb0 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001D88A0
 *   cfg: kept branch: 0x1d88a0 if (..) goto .L001D88E0
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuMng_Delete(void *a0 /* r4 */) {
    u8 *s1;
    s32 s0;
    u32 v0;

    s1 = (u8 *)a0;
    if ((u32)s1 == 0) {
        v0 = 0;
    } else {
        if ((u32)s1 != 0) {
            v0 = *(s32 *)(s1 + 0x60);
            if (v0 != 0) {
                s0 = 0;
                for (; (u32)s0 < (u32)*(s32 *)((*(s32 *)(s1 + 0x60) + 0x14)); s0 = s0 + 1) {
                    a0 = (void *)(s32)(*(s32 *)(s1 + 0x64) + s0 * 0x90);
                    v0 = MenuCtrlMng_Delete(a0);
                    if (v0 == 0) {
                        goto _L001D88E0;
                    }
                }
            }
            a0 = (void *)*(s32 *)(s1 + 0x64);
            MemFree(a0);
            *(u32 *)(s1 + 0x64) = 0;
            *(u32 *)(s1 + 0x60) = 0;
        }
        _L001D88E0:;
        *(u32 *)s1 = 0;
        v0 = 1;
    }
    return v0;
}







/* MenuMng_PlayMenu @ 0x1D8780 .. 0x1D884C (0xcc bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d87d0 writes a register its branch at 0x1d87cc reads
 *   cfg: kept branch: 0x1d8790 if (..) goto .L001D87A8
 *   cfg: kept goto: 0x1d87a0 -> .L001D8838
 *   cfg: kept branch: 0x1d87a8 if (..) goto .L001D87C8
 *   cfg: kept goto: 0x1d87c0 -> .L001D8838
 *   declaration vs inferred signature: return signed int vs inferred u32
 */




signed int MenuMng_PlayMenu(void *a0 /* r4 */, void *a1 /* r5 */) {
    u8 *s1;
    u8 *s0;
    void *a1_2; // a1
    u32 v1;
    u32 v0;

    s1 = (u8 *)a0;
    s0 = (u8 *)a1;
    if ((u32)s1 != 0) {
        goto _L001D87A8;
    }
    v0 = 0;
    goto _L001D8838;
    _L001D87A8:;
    v0 = MngState_UpdateExeCheck(a0);
    v1 = 1;
    if (v0 == v1) {
        goto _L001D87C8;
    }
    v0 = 0;
    goto _L001D8838;
    _L001D87C8:;
    v0 = *(s32 *)(s1 + 0x70);
    if ((s32)v0 >= 0) {
        v0 = 0;
        return v0;
    }
    *(u32 *)(s1 + 0x68) = (u32)s0;
    if ((u32)s0 != 0) {
        v1 = *(s32 *)(s1 + 0x60);
        v0 = ((struct { unsigned char _pad:1; unsigned char f:1; } *)&*(u8 *)((v1 + 0x1c)))->f;
        *(u32 *)(s0 + 0x74) = v0;
        v0 = ((struct { unsigned char _pad:2; unsigned char f:1; } *)&*(u8 *)((v1 + 0x1c)))->f;
        *(u32 *)(s0 + 0x78) = v0;
    }
    *(u32 *)(s1 + 0x70) = 0;
    a1_2 = (void *)*(s32 *)(s1 + 0x70);
    v1 = *(s32 *)(s1 + 0x64);
    v0 = 1;
    a0 = (void *)((s32)((u32)((u32)(a1_2)) * (u32)(0x90)));
    *(u8 *)(((u32)(s32)((u8 *)v1 + (u32)(a0)) + 0x84)) = 3;
    _L001D8838:;
    return v0;
}







/* MenuMng_GetTexId @ 0x1D86C0 .. 0x1D8778 (0xb8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   cfg: kept branch: 0x1d86d0 if (..) goto .L001D86E8
 *   cfg: kept goto: 0x1d86e0 -> .L001D8760
 *   cfg: kept branch: 0x1d86e8 if (..) goto .L001D8708
 *   cfg: kept goto: 0x1d8700 -> .L001D8760
 *   cfg: loop body is not one contiguous region: .L001D8720
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuMng_GetTexId(void *a0 /* r4 */) {
    u8 *s1;
    s32 s0;
    s32 s2;
    u32 v0;

    s1 = (u8 *)a0;
    if ((u32)s1 != 0) {
        goto _L001D86E8;
    }
    v0 = 0;
    goto _L001D8760;
    _L001D86E8:;
    v0 = MngState_UpdateExeCheck(a0);
    if (v0 == (u32)1) {
        goto _L001D8708;
    }
    v0 = 0;
    goto _L001D8760;
    _L001D8708:;
    v0 = *(s32 *)(s1 + 0x60);
    v0 = *(s32 *)((v0 + 0x14));
    s0 = 0;
    if ((u8 *)0 < (u8 *)v0) {
        s2 = 0;
        do {
            v0 = *(s32 *)(s1 + 0x64);
            a0 = (void *)(s32)(v0 + s2);
            v0 = MenuCtrlMng_GetTexId(a0);
            if (v0 == 0) {
                v0 = 0;
                return v0;
            }
            v0 = *(s32 *)(s1 + 0x60);
            s0 = s0 + 1;
            v0 = *(s32 *)((v0 + 0x14));
            v0 = (u32)s0 < v0;
            s2 = s2 + 0x90;
        } while (v0 != 0);
    }
    v0 = 1;
    _L001D8760:;
    return v0;
}




signed int MenuMng_GetCursorId(MMng *pMenuMng, u32 ctrl) {
    if (pMenuMng == 0) {
        return 0;
    }
    if (MngState_UpdateExeCheck(pMenuMng) != 1) {
        return 0;
    }
    return ctrl < pMenuMng->head->num ? pMenuMng->pe[ctrl].id : -1;
}









/* MenuMng_CheckCtrlPlay @ 0x1D8590 .. 0x1D862C (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1d85e8 writes a register its branch at 0x1d85e4 reads
 *   cfg: kept branch: 0x1d85a0 if (..) goto .L001D85B8
 *   cfg: kept goto: 0x1d85b0 -> .L001D8618
 *   cfg: kept branch: 0x1d85b8 if (..) goto .L001D85D8
 *   cfg: kept goto: 0x1d85d0 -> .L001D8618
 *   declaration vs inferred signature: return signed int vs inferred u32
 */






signed int MenuMng_CheckCtrlPlay(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;

    s1 = (u8 *)a0;
    s0 = a1;
    if ((u32)s1 != 0) {
        goto _L001D85B8;
    }
    v0 = 0;
    goto _L001D8618;
    _L001D85B8:;
    v0 = MngState_UpdateExeCheck(a0);
    v1 = 1;
    if (v0 == v1) {
        goto _L001D85D8;
    }
    v0 = 0;
    goto _L001D8618;
    _L001D85D8:;
    v0 = *(s32 *)(s1 + 0x60);
    v0 = *(s32 *)((v0 + 0x14));
    v0 = (u32)s0 < v0;
    if (v0 == 0) {
        v0 = -1;
        return v0;
    }
    v1 = *(s32 *)(s1 + 0x64);
    v0 = (u32)s0 << 3;
    v0 = v0 + s0;
    v0 = v0 << 4;
    v0 = (u32)v0 + (u32)v1;
    v0 = *(u8 *)((v0 + 0x70));
    v0 = v0 != 0;
    _L001D8618:;
    return v0;
}




/* MenuMng_CheckCtrlPlayWait @ 0x1D84F0 .. 0x1D858C (0x9c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   delay: addiu at 0x1d8548 writes a register its branch at 0x1d8544 reads
 *   cfg: kept branch: 0x1d8500 if (..) goto .L001D8518
 *   cfg: kept goto: 0x1d8510 -> .L001D8578
 *   cfg: kept branch: 0x1d8518 if (..) goto .L001D8538
 *   cfg: kept goto: 0x1d8530 -> .L001D8578
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int MenuMng_CheckCtrlPlayWait(void *a0 /* r4 */, signed int a1 /* r5 */) {
    u8 *s1;
    s32 s0;
    u32 v1;
    u32 v0;

    s1 = (u8 *)a0;
    s0 = a1;
    if ((u32)s1 != 0) {
        goto _L001D8518;
    }
    v0 = 0;
    goto _L001D8578;
    _L001D8518:;
    v0 = MngState_UpdateExeCheck(a0);
    v1 = 1;
    if (v0 == v1) {
        goto _L001D8538;
    }
    v0 = 0;
    goto _L001D8578;
    _L001D8538:;
    v0 = *(s32 *)(s1 + 0x60);
    v0 = *(s32 *)((v0 + 0x14));
    v0 = (u32)s0 < v0;
    if (v0 == 0) {
        v0 = -1;
        return v0;
    }
    v1 = *(s32 *)(s1 + 0x64);
    v0 = (u32)s0 << 3;
    v0 = v0 + s0;
    v0 = v0 << 4;
    v0 = (u32)v0 + (u32)v1;
    v0 = *(u8 *)((v0 + 0x70));
    v0 = v0 ^ 6;
    v0 = v0 < (u32)1;
    _L001D8578:;
    return v0;
}


/* MenuMng_GetDrawPos @ 0x1D8480 .. 0x1D84F0 (0x70 bytes) */
/*
 * dcomp notes:
 *   delay: daddu at 0x1d8490 writes a register its branch at 0x1d848c reads
 *   declaration vs inferred signature: return void * vs inferred u32
 */

void * MenuMng_GetDrawPos(void *a0 /* r4 */, signed int a1 /* r5 */, signed int a2 /* r6 */) {
    u32 v1;
    u32 v0;
    s32 at;

    v0 = *(s32 *)((*(s32 *)(((u8 *)a0 + 0x60)) + 0x14));
    if ((u32)((u32)a1 < v0) == 0) {
        return (void *)(u32)0;
    }
    v1 = *(s32 *)(((u8 *)a0 + 0x64)) + (s32)((u32)a1 * (u32)(0x90));
    at = (u32)(s32)a2 < (u32)*(s32 *)((*(s32 *)((v1 + 0x20)) + 0x14));
    v0 = 0;
    if (at != 0) {
        v0 = (s32)(*(s32 *)((v1 + 0x6c)) + (s32)((u32)a2 * (u32)(0xf0))) + 0xd0;
        return (void *)v0;
    }
    return (void *)v0;
}

