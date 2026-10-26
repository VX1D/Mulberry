#include "common.h"

extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void *GetTexMngByID(unsigned short);
#undef out
void MGSetSprite(void *output, int x, int y, int width, int height, int *color, unsigned short texId, unsigned char mode, int u,int v,int w,int h,unsigned char kind);


extern void MGSetSprite(void *, int,int,int,int,int *,unsigned short,unsigned char,int,int,int,int,unsigned char);
extern void *GetTexMngByID(unsigned short);
extern unsigned int *MakeTexPacket(unsigned int *,void *);
extern unsigned int *MakeSpritePacketUseSpr(void *,unsigned int *);
extern u32 lpMdlPacketMem;
extern s32 g_MenuAnimDir;


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void DrawBackSprite(void *a0);
void DrawSprite(void *a0);
void MGSetSprite(void *output, int x, int y, int width, int height, int *color, unsigned short texId, unsigned char mode, int u,int v,int w,int h,unsigned char kind);









void DrawBackSprite(void *a0) {
    s32 index;
    u8 *sprite;
    u16 *texture;
    u32 packet;
    u8 buffer[240] __attribute__((aligned(16)));
    index=0; sprite=(u8 *)a0; texture=(u16 *)(buffer+2); packet=lpMdlPacketMem;
    do {
        if(sprite[3]==0) {
            u32 mode=sprite[2];
            if(mode!=0) {
                if(mode==1) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+48),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                } else if(mode==2 || mode==3) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+64),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                } else if(mode==4) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+48),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                    if(*(s32 *)(sprite+60)>=255) g_MenuAnimDir=-1;
                    if(*(s32 *)(sprite+60)<=128) g_MenuAnimDir=1;
                    *(s32 *)(sprite+60)+=(s32)(4.27f*(float)g_MenuAnimDir);
                    if(*(s32 *)(sprite+60)>=255) *(s32 *)(sprite+60)=255;
                    if(*(s32 *)(sprite+60)<=128) *(s32 *)(sprite+60)=128;
                }
                packet=(u32)MakeSpritePacketUseSpr(buffer,MakeTexPacket((u32 *)packet,GetTexMngByID(*texture)));
            }
        }
        ++index; sprite+=112;
    } while(index<108);
    lpMdlPacketMem=packet;
}
void DrawSprite(void *a0) {
    s32 index;
    u8 *sprite;
    u16 *texture;
    u32 packet;
    u8 buffer[240] __attribute__((aligned(16)));
    index=0; sprite=(u8 *)a0; texture=(u16 *)(buffer+2); packet=lpMdlPacketMem;
    do {
        if(sprite[3]!=0) {
            u32 mode=sprite[2];
            if(mode!=0) {
                if(mode==1) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+48),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                } else if(mode==2 || mode==3) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+64),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                } else if(mode==4) {
                    MGSetSprite(buffer,*(s32 *)(sprite+4),*(s32 *)(sprite+8),*(s32 *)(sprite+12),*(s32 *)(sprite+16),(s32 *)(sprite+48),*(u16 *)sprite,0,*(s32 *)(sprite+80),*(s32 *)(sprite+84),*(s32 *)(sprite+88),*(s32 *)(sprite+92),sprite[96]);
                    if(*(s32 *)(sprite+60)>=255) g_MenuAnimDir=-1;
                    if(*(s32 *)(sprite+60)<=128) g_MenuAnimDir=1;
                    *(s32 *)(sprite+60)+=(s32)(4.27f*(float)g_MenuAnimDir);
                    if(*(s32 *)(sprite+60)>=255) *(s32 *)(sprite+60)=255;
                    if(*(s32 *)(sprite+60)<=128) *(s32 *)(sprite+60)=128;
                }
                packet=(u32)MakeSpritePacketUseSpr(buffer,MakeTexPacket((u32 *)packet,GetTexMngByID(*texture)));
            }
        }
        ++index; sprite+=112;
    } while(index<108);
    lpMdlPacketMem=packet;
}
void MGSetSprite(void *output, int x, int y, int width, int height, int *color, unsigned short texId, unsigned char mode, int u,int v,int w,int h,unsigned char kind) {
#define out ((u8 *)output)
    s32 left,top,right,bottom;
    memset(out,0,240);
    left = (x + 2048) << 4;
    top = (y + 2048) << 4;
    right = (x + width + 2048) << 4;
    bottom = (y + height + 2048) << 4;
    ((struct { unsigned char active:1; unsigned char mode:1; } *)out)->active = 1;
    *(u32 *)(out+16)=left; *(u32 *)(out+20)=top; *(u32 *)(out+24)=-1;
    *(u32 *)(out+32)=right; *(u32 *)(out+36)=top; *(u32 *)(out+40)=-1;
    *(u32 *)(out+48)=left; *(u32 *)(out+52)=bottom; *(u32 *)(out+56)=-1;
    *(u32 *)(out+64)=right; *(u32 *)(out+68)=bottom; *(u32 *)(out+72)=-1;
    memcpy(out+80,color,16); memcpy(out+96,color,16);
    memcpy(out+112,color,16); memcpy(out+128,color,16);
    ((struct { unsigned char active:1; unsigned char kind:3; } *)(out+224))->active=1;
    ((struct { unsigned char active:1; unsigned char kind:3; } *)(out+224))->kind=0;
    ((struct { unsigned short low:4; unsigned short value:8; unsigned short high:4; } *)(out+224))->value=0;
    ((struct { unsigned char low:4; unsigned char mode:2; unsigned char flag:1; unsigned char other:1; } *)(out+225))->mode=3;
    ((struct { unsigned char low:4; unsigned char mode:2; unsigned char flag:1; unsigned char other:1; } *)(out+225))->flag=0;
    ((struct { unsigned char low:4; unsigned char mode:2; unsigned char flag:1; unsigned char other:1; } *)(out+225))->other=0;
    ((struct { unsigned char active:1; unsigned char kind:2; } *)(out+226))->active=1;
    ((struct { unsigned char active:1; unsigned char kind:2; } *)(out+226))->kind=1;
    *(u16 *)(out+2)=texId;
    ((struct { unsigned char active:1; unsigned char mode:1; } *)out)->mode=mode;
    ((struct { unsigned char active:1; unsigned char mode:1; unsigned char kind:2; } *)out)->kind=kind;
    if (*(u16 *)(out+2)!=0) {
        u32 texture=(u32)GetTexMngByID(texId);
        *(u64 *)(out+208)=*(u64 *)(*(u32 *)(texture+4)+16);
        *(u64 *)(out+216)=*(u64 *)(*(u32 *)(texture+4)+24);
        if(!((struct {unsigned char active:1;unsigned char mode:1;}*)out)->mode) {
            s32 left=u<<4,top=v<<4,right=(u+w)<<4,bottom=(v+h)<<4;
            *(u32 *)(out+144)=left;*(u32 *)(out+148)=top;
            *(u32 *)(out+160)=right;*(u32 *)(out+164)=top;
            *(u32 *)(out+176)=left;*(u32 *)(out+180)=bottom;
            *(u32 *)(out+192)=right;*(u32 *)(out+196)=bottom;
        } else {
            *(u32 *)(out+144)=0;*(u32 *)(out+148)=0;*(u32 *)(out+152)=0x3f800000;
            *(u32 *)(out+160)=0x3f800000;*(u32 *)(out+164)=0;*(u32 *)(out+168)=0x3f800000;
            *(u32 *)(out+176)=0;*(u32 *)(out+180)=0x3f800000;*(u32 *)(out+184)=0x3f800000;
            *(u32 *)(out+192)=0x3f800000;*(u32 *)(out+196)=0x3f800000;*(u32 *)(out+200)=0x3f800000;
        }
    }
}
static s32 g_MenuAnimDir = 1;
