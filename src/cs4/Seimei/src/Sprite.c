#include "common.h"

/* MakeAndKickSpritePacket @ 0x13DF00 .. 0x13E000 (0x100 bytes, frame 0x30) */

extern void * GetTexMngByID(unsigned short);
extern unsigned int * MakeTexPacket(unsigned int *, void *);
extern unsigned int * MakeSpritePacketUseSpr(void *, unsigned int *);
extern void FlushCache(int);
static u32 DMABuf_742[0xc0];


typedef struct StripFlags { unsigned char active:1, flat:1, mode:2, pad:4; } StripFlags;


extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);


/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void SetSprite(u8 *out, signed int x, signed int y, signed int width, signed int height, signed int *color, unsigned short texId, unsigned char mode);
void SetSpriteTexRegs(u8 *sprite, u64 tex0, u64 tex1, s32 width, s32 height);
u32 *MakeStripPacketUseSpr(void *a0,u32 *a1);
unsigned int *MakeSpritePacketUseSpr(void *sprite,unsigned int *packet);
void MakeAndKickSpritePacket(void *a0 );

void SetSprite(u8 *out, signed int x, signed int y, signed int width, signed int height, signed int *color, unsigned short texId, unsigned char mode) {
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
    if (*(u16 *)(out+2)!=0) {
        u8 *data;
        data = (u8 *)*(s32 *)((u32)GetTexMngByID(texId)+4);
        SetSpriteTexRegs(out, *(u64 *)(data+16), *(u64 *)(data+24),
            1 << ((struct { u64 tbp:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; } *)(data+16))->tw,
            1 << ((struct { u64 tbp:14; u64 tbw:6; u64 psm:6; u64 tw:4; u64 th:4; } *)(data+16))->th);
    }
}


void SetSpriteTexRegs(u8 *sprite, u64 tex0, u64 tex1, s32 width, s32 height) {
    u64 second, first;
    u32 u, v;
    u32 address;
    first = tex0;
    second = tex1;
    address = (u32)&first;
    *(u64 *)(sprite + 0xd0) = *(u64 *)address;
    address = (u32)&second;
    *(u64 *)(sprite + 0xd8) = *(u64 *)address;
    if (((u64)sprite[0] << 62 >> 63) == 0) {
        *(u32 *)(sprite + 0x90) = 0;
        u = width << 4;
        *(u32 *)(sprite + 0x94) = 0;
        v = height << 4;
        *(u32 *)(sprite + 0xa0) = u;
        *(u32 *)(sprite + 0xa4) = 0;
        *(u32 *)(sprite + 0xb0) = 0;
        *(u32 *)(sprite + 0xb4) = v;
        *(u32 *)(sprite + 0xc0) = u;
        *(u32 *)(sprite + 0xc4) = v;
    } else {
        *(float *)(sprite + 0x90) = 0;
        *(float *)(sprite + 0x94) = 0;
        *(float *)(sprite + 0x98) = 1;
        *(float *)(sprite + 0xa0) = 1;
        *(float *)(sprite + 0xa4) = 0;
        *(float *)(sprite + 0xa8) = 1;
        *(float *)(sprite + 0xb0) = 0;
        *(float *)(sprite + 0xb4) = 1;
        *(float *)(sprite + 0xb8) = 1;
        *(float *)(sprite + 0xc0) = 1;
        *(float *)(sprite + 0xc4) = 1;
        *(float *)(sprite + 0xc8) = 1;
    }
}
u32 *MakeStripPacketUseSpr(void *a0,u32 *a1) {
    u8 *sprite=(u8 *)a0;
    if(!((StripFlags *)sprite)->active) return a1;
    if(*(u16 *)(sprite+2)==0) {
        a1[0]=0x1000000c; a1[1]=0; a1[2]=0; a1[3]=0x5100000c;
        a1[4]=2; a1[5]=0x10000000; a1[6]=14; a1[7]=0;
        *(u64 *)((u8 *)a1+32)=*(u64 *)(sprite+224);
        *(u64 *)((u8 *)a1+40)=0x47;
        switch(((StripFlags *)sprite)->mode) {
        case 1: *(u64 *)((u8 *)a1+48)=0x48; a1+=14; break;
        case 2: *(u64 *)((u8 *)a1+48)=0x42; a1+=14; break;
        default: *(u64 *)((u8 *)a1+48)=0x44; a1+=14; break;
        }
        *(u64 *)a1=0x42;
        a1[2]=0x8004; a1[3]=0x20264000; a1[4]=0x41; a1[5]=0;
        *(u_long128 *)((u8 *)a1+24)=*(u_long128 *)(sprite+80);
        *(u_long128 *)((u8 *)a1+40)=*(u_long128 *)(sprite+16);
        *(u_long128 *)((u8 *)a1+56)=*(u_long128 *)(sprite+96);
        *(u_long128 *)((u8 *)a1+72)=*(u_long128 *)(sprite+32);
        *(u_long128 *)((u8 *)a1+88)=*(u_long128 *)(sprite+112);
        *(u_long128 *)((u8 *)a1+104)=*(u_long128 *)(sprite+48);
        *(u_long128 *)((u8 *)a1+120)=*(u_long128 *)(sprite+128);
        *(u_long128 *)((u8 *)a1+136)=*(u_long128 *)(sprite+64);
        a1+=38;
    } else {
        a1[0]=0x10000013; a1[1]=0; a1[2]=0; a1[3]=0x51000013;
        a1[4]=5; a1[5]=0x10000000; a1[6]=14; a1[7]=0;
        *(u64 *)((u8 *)a1+32)=0;
        *(u64 *)((u8 *)a1+40)=0x3f;
        *(u64 *)((u8 *)a1+48)=*(u64 *)(sprite+224);
        *(u64 *)((u8 *)a1+56)=0x47;
        switch(((StripFlags *)sprite)->mode) {
        case 1: *(u64 *)((u8 *)a1+64)=0x48; a1+=18; break;
        case 2: *(u64 *)((u8 *)a1+64)=0x42; a1+=18; break;
        default: *(u64 *)((u8 *)a1+64)=0x44; a1+=18; break;
        }
        *(u64 *)a1=0x42;
        *(u64 *)((u8 *)a1+8)=*(u64 *)(sprite+216);
        *(u64 *)((u8 *)a1+16)=0x14;
        *(u64 *)((u8 *)a1+24)=*(u64 *)(sprite+208);
        *(u64 *)((u8 *)a1+32)=6;
        if(!((StripFlags *)sprite)->flat) {
            a1[10]=0x8004; a1[11]=0x30ae4000; a1[12]=0x413; a1[13]=0;
            *(u_long128 *)((u8 *)a1+56)=*(u_long128 *)(sprite+144);
            *(u_long128 *)((u8 *)a1+72)=*(u_long128 *)(sprite+80);
            *(u_long128 *)((u8 *)a1+88)=*(u_long128 *)(sprite+16);
            *(u_long128 *)((u8 *)a1+104)=*(u_long128 *)(sprite+160);
            *(u_long128 *)((u8 *)a1+120)=*(u_long128 *)(sprite+96);
            *(u_long128 *)((u8 *)a1+136)=*(u_long128 *)(sprite+32);
            *(u_long128 *)((u8 *)a1+152)=*(u_long128 *)(sprite+176);
            *(u_long128 *)((u8 *)a1+168)=*(u_long128 *)(sprite+112);
            *(u_long128 *)((u8 *)a1+184)=*(u_long128 *)(sprite+48);
            *(u_long128 *)((u8 *)a1+200)=*(u_long128 *)(sprite+192);
            *(u_long128 *)((u8 *)a1+216)=*(u_long128 *)(sprite+128);
            *(u_long128 *)((u8 *)a1+232)=*(u_long128 *)(sprite+64);
            a1+=62;
        } else {
            a1[10]=0x8004; a1[11]=0x302e4000; a1[12]=0x412; a1[13]=0;
            *(u_long128 *)((u8 *)a1+56)=*(u_long128 *)(sprite+144);
            *(u_long128 *)((u8 *)a1+72)=*(u_long128 *)(sprite+80);
            *(u_long128 *)((u8 *)a1+88)=*(u_long128 *)(sprite+16);
            *(u_long128 *)((u8 *)a1+104)=*(u_long128 *)(sprite+160);
            *(u_long128 *)((u8 *)a1+120)=*(u_long128 *)(sprite+96);
            *(u_long128 *)((u8 *)a1+136)=*(u_long128 *)(sprite+32);
            *(u_long128 *)((u8 *)a1+152)=*(u_long128 *)(sprite+176);
            *(u_long128 *)((u8 *)a1+168)=*(u_long128 *)(sprite+112);
            *(u_long128 *)((u8 *)a1+184)=*(u_long128 *)(sprite+48);
            *(u_long128 *)((u8 *)a1+200)=*(u_long128 *)(sprite+192);
            *(u_long128 *)((u8 *)a1+216)=*(u_long128 *)(sprite+128);
            *(u_long128 *)((u8 *)a1+232)=*(u_long128 *)(sprite+64);
            a1+=62;
        }
    }
    return a1;
}


unsigned int *MakeSpritePacketUseSpr(void *sprite,unsigned int *packet) {
    u8 *s=(u8 *)sprite;
    if((*(u8 *)s&1)==0) return packet;
    if(*(u16 *)(s+2)==0) {
        packet[0]=0x10000008; packet[1]=0; packet[2]=0; packet[3]=0x51000008;
        packet[4]=2; packet[5]=0x10000000; packet[6]=14; packet[7]=0;
        *(u64 *)(packet+8)=*(u64 *)(s+224);
        *(u64 *)(packet+10)=0x47;
        switch(((struct { unsigned char pad:2,mode:2; } *)s)->mode) {
        case 1: *(u64 *)(packet+12)=0x48; packet+=14; break;
        case 2: *(u64 *)(packet+12)=0x42; packet+=14; break;
        default: *(u64 *)(packet+12)=0x44; packet+=14; break;
        }
        *(u64 *)packet=0x42;
        packet[2]=0x8002; packet[3]=0x20274000; packet[4]=0x41; packet[5]=0;
        *(u_long128 *)(packet+6)=*(u_long128 *)(s+80);
        *(u_long128 *)(packet+10)=*(u_long128 *)(s+16);
        *(u_long128 *)(packet+14)=*(u_long128 *)(s+128);
        *(u_long128 *)(packet+18)=*(u_long128 *)(s+64);
        packet+=22;
    } else {
        packet[0]=0x1000000d; packet[1]=0; packet[2]=0; packet[3]=0x5100000d;
        packet[4]=5; packet[5]=0x10000000; packet[6]=14; packet[7]=0;
        *(u64 *)(packet+8)=0; *(u64 *)(packet+10)=0x3f;
        *(u64 *)(packet+12)=*(u64 *)(s+224); *(u64 *)(packet+14)=0x47;
        switch(((struct { unsigned char pad:2,mode:2; } *)s)->mode) {
        case 1: *(u64 *)(packet+16)=0x48; packet+=18; break;
        case 2: *(u64 *)(packet+16)=0x42; packet+=18; break;
        default: *(u64 *)(packet+16)=0x44; packet+=18; break;
        }
        *(u64 *)packet=0x42;
        *(u64 *)(packet+2)=*(u64 *)(s+216); *(u64 *)(packet+4)=20;
        *(u64 *)(packet+6)=*(u64 *)(s+208); *(u64 *)(packet+8)=6;
        if(((struct { unsigned char pad:1,flag:1; } *)s)->flag==0) {
            packet[10]=0x8002; packet[11]=0x30af4000; packet[12]=0x413; packet[13]=0;
            *(u_long128 *)(packet+14)=*(u_long128 *)(s+144);
            *(u_long128 *)(packet+18)=*(u_long128 *)(s+80);
            *(u_long128 *)(packet+22)=*(u_long128 *)(s+16);
            *(u_long128 *)(packet+26)=*(u_long128 *)(s+192);
            *(u_long128 *)(packet+30)=*(u_long128 *)(s+128);
            *(u_long128 *)(packet+34)=*(u_long128 *)(s+64);
            packet+=38;
        } else {
            packet[10]=0x8002; packet[11]=0x302f4000; packet[12]=0x412; packet[13]=0;
            *(u_long128 *)(packet+14)=*(u_long128 *)(s+144);
            *(u_long128 *)(packet+18)=*(u_long128 *)(s+80);
            *(u_long128 *)(packet+22)=*(u_long128 *)(s+16);
            *(u_long128 *)(packet+26)=*(u_long128 *)(s+192);
            *(u_long128 *)(packet+30)=*(u_long128 *)(s+128);
            *(u_long128 *)(packet+34)=*(u_long128 *)(s+64);
            packet+=38;
        }
    }
    return packet;
}

void MakeAndKickSpritePacket(void *a0 /* r4 */) {
    u8 *s1;
    u8 *s0;
    u32 v1;
    u32 v0;
    u16 texId;

    s1 = (u8 *)a0;
    texId = *(u16 *)(((u8 *)a0 + 2));
    s0 = (u8 *)&DMABuf_742;
    if (texId != 0) {
        v0 = *(u8 *)s1;
        if ((u64)((u64)v0 << 0x3b >> 0x3f) == 0) {
            v0 = (u32)GetTexMngByID(texId);
            v0 = (u32)MakeTexPacket((unsigned int *)s0, (void *)v0);
            s0 = (u8 *)v0;
        }
    }
    v0 = (u32)MakeSpritePacketUseSpr((void *)s1, (unsigned int *)(u8 *)s0);
    v1 = 0x70000000;
    *(u32 *)v0 = 0x70000000;
    *(u32 *)(((u8 *)v0 + 4)) = 0;
    *(u32 *)(((u8 *)v0 + 8)) = 0;
    *(u32 *)(((u8 *)v0 + 0xc)) = 0;
    FlushCache(0);
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    *(volatile u32 *)0x10009020 = 0;
    a0 = (void *)&DMABuf_742;
    *(volatile u32 *)0x10009010 = 0;
    *(volatile void **)0x10009030 = (void *)&DMABuf_742;
    *(volatile u32 *)0x10009000 = 0x145;
    do {
        v1 = *(volatile s32 *)0x10009000;
        v1 = v1 & 0x100;
    } while (v1 != 0 || (u32)(*(volatile s32 *)0x1000a000 & 0x100) != 0);
    return;
}
