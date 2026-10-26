#include "common.h"
extern void DIntr();
extern void scePrintf(char *, ...);
extern void EIntr();
extern void * strcpy(void *, void *);
extern int SignalSema(int);
extern u8 aio[];
extern u32 ssid;
extern int WaitSema(int);
extern u32 PollSema(s32, signed int *, signed int *);
extern u32 esid;
signed int AioCdSearchFile(char *a0 /* r4 */, void *a1 /* r5 */);
signed int AioCmdSync(signed int a0 /* r4 */, signed int *a1 /* r5 */, signed int *a2 /* r6 */);

static u8 aio[0x1230];
static s32 tid;
static u32 ssid;
static u32 esid;

/* AioCmdSync @ 0x165780 .. 0x165864 (0xe4 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: kept goto: 0x1657d8 -> .L00165850
 *   cfg: kept branch: 0x165828 if (..) goto .L00165840
 *   cfg: kept goto: 0x165838 -> .L00165850
 *   cfg: kept goto: 0x165840 -> .L00165850
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int AioCmdSync(signed int a0 /* r4 */, signed int *a1 /* r5 */, signed int *a2 /* r6 */) {
    u32 *s1;
    u32 *s0;
    u32 v0;
    u32 v1;

    v0 = 1;
    s1 = (u32 *)a1;
    s0 = (u32 *)a2;
    switch ((u32)(s32)a0) {
    case 0:
        a0 = esid;
        WaitSema(a0);
        if ((u32)s1 != 0) {
            v0 = *(u8 *)((u8 *)&aio + 0x1229);
            *(u32 *)s1 = v0;
        }
        if ((u32)s0 != 0) {
            v0 = *(s32 *)((u8 *)&aio + 0x122c);
            *(u32 *)s0 = v0;
        }
        v0 = 1;
        return v0;
    case 1:
        a0 = esid;
        v0 = PollSema(a0, a1, a2);
        if ((u32)s1 != 0) {
            v1 = *(u8 *)((u8 *)&aio + 0x1228);
            if (v1 != 0) {
                v1 = (u8)v1;
                *(u32 *)s1 = v1;
            } else {
                v1 = *(u8 *)((u8 *)&aio + 0x1229);
                *(u32 *)s1 = v1;
            }
        }
        if ((u32)s0 != 0) {
            v1 = *(s32 *)((u8 *)&aio + 0x122c);
            *(u32 *)s0 = v1;
        }
        v1 = -1;
        if (v0 != v1) {
            goto _L00165840;
        }
        v0 = 0;
        goto _L00165850;
        _L00165840:;
        v0 = 1;
        return v0;
    }
    v0 = -1;
    _L00165850:;
    return v0;
}


/* AioCdSearchFile @ 0x1656C0 .. 0x165778 (0xb8 bytes, frame 0x40) */
/*
 * dcomp notes:
 *   literal: @403 is the string 'aio: overlapped operation %d, while %d\n'
 *   declaration vs inferred signature: return signed int vs inferred u32
 */


signed int AioCdSearchFile(char *a0 /* r4 */, void *a1 /* r5 */) {
    u32 s2;
    u32 s1;
    s32 s0;
    u8 a2;
    s32 v0;
    char *a0_2;

    s2 = (u32)a0;
    s1 = (u32)a1;
    s0 = 0;
    DIntr();
    v0 = aio[0x1228];
    a2 = v0;
    if (v0 != 0) {
        a0_2 = "aio: overlapped operation %d, while %d\012";
        s0 = -a2;
        scePrintf("aio: overlapped operation %d, while %d\012", 0x19, (s32)a2);
    } else {
        aio[0x1228] = 0x19;
    }
    EIntr();
    if (s0 < 0) {
        return s0;
    }
    a0_2 = (char *)aio;
    strcpy((void *)aio, (void *)s2);
    a0_2 = (char *)ssid;
    *(u32 *)(aio + 0x1200) = s1;
    SignalSema((int)a0_2);
    return 0;
}















extern void ExitDeleteThread(void);
extern int sceOpen(const char *, int, ...);
extern int sceClose(int);
extern int sceRead(int, void *, int);
extern int sceWrite(int, const void *, int);
extern int sceLseek(int, int, int);
extern long sceLseek64(int, long, int);
extern int sceChstat(const char *, void *, unsigned int);
extern int sceGetstat(const char *, void *);
extern int sceRename(const char *, const char *);
extern int sceRemove(const char *);
extern int sceReadlink(const char *, char *, unsigned int);
extern int sceSymlink(const char *, const char *);
extern int sceChdir(const char *);
extern int sceMkdir(const char *, int);
extern int sceRmdir(const char *);
extern int sceDopen(const char *);
extern int sceDclose(int);
extern int sceDread(int, void *);
extern int sceSync(const char *, int);
extern int sceFormat(const char *, const char *, void *, int);
extern int sceMount(const char *, const char *, int, void *, int);
extern int sceUmount(const char *);
extern int sceDevctl(const char *, int, const void *, unsigned int, void *, unsigned int);
extern int sceIoctl2(int, int, void *, unsigned int, void *, unsigned int);
extern int sceCdSearchFile(void *, const char *);

struct aio_req {
    char name[0x100];
    char name2[0x1100];
    int arg[8];
    long off;
    char cmd;
    u8 last;
    int result;
};

void threadmain(void *param) {
    struct aio_req *p;
    int r;

    p = (struct aio_req *)param;
    while (1) {
        if (WaitSema(ssid) < 0) {
            ExitDeleteThread();
        }
        switch ((u8)p->cmd) {
        case 0:
            r = 0;
            break;
        case 1:
            r = sceOpen(p->name, p->arg[0], (unsigned int)p->arg[1]);
            break;
        case 2:
            r = sceClose(p->arg[0]);
            break;
        case 3:
            r = sceRead(p->arg[0], (void *)p->arg[1], p->arg[2]);
            break;
        case 4:
            r = sceWrite(p->arg[0], (void *)p->arg[1], p->arg[2]);
            break;
        case 5:
            r = sceLseek(p->arg[0], p->arg[1], p->arg[2]);
            break;
        case 6:
            r = sceLseek64(p->arg[0], p->off, p->arg[1]);
            break;
        case 7:
            r = sceChstat(p->name, (void *)p->arg[0], p->arg[1]);
            break;
        case 8:
            r = sceGetstat(p->name, (void *)p->arg[0]);
            break;
        case 9:
            r = sceRename(p->name, p->name2);
            break;
        case 10:
            r = sceRemove(p->name);
            break;
        case 11:
            r = sceReadlink(p->name, (char *)p->arg[0], p->arg[1]);
            break;
        case 12:
            r = sceSymlink(p->name, p->name2);
            break;
        case 13:
            r = sceChdir(p->name);
            break;
        case 14:
            r = sceMkdir(p->name, p->arg[0]);
            break;
        case 15:
            r = sceRmdir(p->name);
            break;
        case 16:
            r = sceDopen(p->name);
            break;
        case 17:
            r = sceDclose(p->arg[0]);
            break;
        case 18:
            r = sceDread(p->arg[0], (void *)p->arg[1]);
            break;
        case 19:
            r = sceSync(p->name, p->arg[0]);
            break;
        case 20:
            r = sceFormat(p->name, (const char *)p->arg[0], (void *)p->arg[1], p->arg[2]);
            break;
        case 21:
            r = sceMount(p->name, (const char *)p->arg[0], p->arg[1], (void *)p->arg[2], p->arg[3]);
            break;
        case 22:
            r = sceUmount(p->name);
            break;
        case 23:
            r = sceDevctl(p->name, p->arg[0], (void *)p->arg[1], p->arg[2], (void *)p->arg[3], p->arg[4]);
            break;
        case 24:
            r = sceIoctl2(p->arg[0], p->arg[1], (void *)p->arg[2], p->arg[3], (void *)p->arg[4], p->arg[5]);
            break;
        case 25:
            r = sceCdSearchFile((void *)p->arg[0], p->name);
            break;
        default:
            r = -1;
            scePrintf("aio: unknown i/o operation.\n");
            break;
        }
        p->result = r;
        p->last = p->cmd;
        p->cmd = 0;
        SignalSema(esid);
    }
}











extern int CreateSema(void *);
extern int CreateThread(void *);
extern void *memset(void *, int, unsigned int);
extern int StartThread(int, void *);
extern u32 _gp;

static u32 stack_336[0x800];
signed int AioInit(signed int priority) {
    u32 sema[8] __attribute__((aligned(16)));
    u32 thread[12] __attribute__((aligned(16)));
    sema[2] = 0;
    sema[1] = 1;
    sema[5] = 0;
    ssid = CreateSema(sema);
    sema[2] = 0;
    sema[1] = 1;
    sema[5] = 0;
    esid = CreateSema(sema);
    thread[1] = (u32)threadmain;
    thread[5] = priority;
    thread[2] = (u32)stack_336;
    thread[3] = 0x2000;
    thread[4] = (u32)&_gp;
    tid = CreateThread(thread);
    memset(aio, 0, 0x1230);
    StartThread(tid, aio);
    return 0;
}





