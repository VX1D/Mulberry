#include "common.h"
u32 sCurWaterCameraInfo;
u8 WaterSurfaceMng[0x500];

/* MakeMirrorTexture @ 0x1A14E0 .. 0x1A1708 (0x228 bytes, frame 0x20) */
/*
 * dcomp notes:
 *   quad: a0: 128-bit web split from its scalar uses
 */

extern void DrawReverseByOT(void);
extern u32 lpDrawMng;
extern u32 lpMdlPacketMem;

/* DrawWaterSurface @ 0x1A1710 (0x2c0 bytes, frame 0xa0)
 * DWARF locals: lpCurDMA(s5) i(s4) j(a1) Start(s3) End(s2) PrimNum(v1). */
extern unsigned char OuterFlag[6][6];
extern u32 ScreenST[];
extern u32 ScreenRGBA[];
extern u32 ScreenXYZ[];

#define DWS_FLAG OuterFlag
#define DWS_SST ((float (*)[6][4])ScreenST)
#define DWS_RGBA ((int (*)[6][4])ScreenRGBA)
#define DWS_SXYZ ((int (*)[6][4])ScreenXYZ)




static u32 WaterInfo_6_8[0x28] = {
    0x42040000, 0x3d8f5c29, 0x40e00000, 0x3f800000, 0, 0, 0, 0, 0x42040000, 0x3d8f5c29,
    0x41100000, 0x3f800000, 0, 0, 0, 0, 0x42040000, 0x3d8f5c29, 0x41300000, 0x3f800000, 0, 0, 0,
    0, 0x41f80000, 0x3d8f5c29, 0x41100000, 0x3f800000, 0, 0, 0, 0, 0x41f80000, 0x3d8f5c29,
    0x41300000, 0x3f800000
};
static u32 WaterInfo_8_2[0x38] = {
    0x422ecccd, 0x3d8f5c29, 0xc1980000, 0x3f800000, 0, 0, 0, 0, 0x42306666, 0x3d8f5c29,
    0xc1a80000, 0x3f800000, 0, 0, 0, 0, 0x4230cccd, 0x3d8f5c29, 0xc1b80000, 0x3f800000, 0, 0, 0,
    0, 0x4230cccd, 0x3d8f5c29, 0xc1c80000, 0x3f800000, 0, 0, 0, 0, 0x4230cccd, 0x3d8f5c29,
    0xc1d80000, 0x3f800000, 0, 0, 0, 0, 0x4231cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0,
    0, 0x4231cccd, 0x3d8f5c29, 0xc1f80000, 0x3f800000
};
static u32 WaterInfo_10_5[0x48] = {
    0x420f3333, 0x3d4ccccd, 0xc1100000, 0x3f800000, 0, 0, 0, 0, 0x42100000, 0x3d4ccccd,
    0xc1300000, 0x3f800000, 0, 0, 0, 0, 0x42180000, 0x3d4ccccd, 0xc1300000, 0x3f800000, 0, 0, 0,
    0, 0x42140000, 0x3d4ccccd, 0xc1500000, 0x3f800000, 0, 0, 0, 0, 0x421c0000, 0x3d4ccccd,
    0xc1500000, 0x3f800000, 0, 0, 0, 0, 0x42240000, 0x3d4ccccd, 0xc1500000, 0x3f800000, 0, 0, 0,
    0, 0x421c0000, 0x3d4ccccd, 0xc1700000, 0x3f800000, 0, 0, 0, 0, 0x42240000, 0x3d4ccccd,
    0xc1700000, 0x3f800000, 0, 0, 0, 0, 0x422c0000, 0x3d4ccccd, 0xc1700000, 0x3f800000
};
static u32 WaterInfo_10_10[0x58] = {
    0x4201999a, 0x3d4ccccd, 0xbf800000, 0x3f800000, 0, 0, 0, 0, 0x4201999a, 0x3d4ccccd,
    0xc0400000, 0x3f800000, 0, 0, 0, 0, 0x4201999a, 0x3d4ccccd, 0xc0a00000, 0x3f800000, 0, 0, 0,
    0, 0x4209999a, 0x3d4ccccd, 0xc0a00000, 0x3f800000, 0, 0, 0, 0, 0x42026666, 0x3d4ccccd,
    0xc0e00000, 0x3f800000, 0, 0, 0, 0, 0x420a6666, 0x3d4ccccd, 0xc0e00000, 0x3f800000, 0, 0, 0,
    0, 0x42073333, 0x3d4ccccd, 0xc1100000, 0x3f800000, 0, 0, 0, 0, 0x420f3333, 0x3d4ccccd,
    0xc1100000, 0x3f800000, 0, 0, 0, 0, 0x42100000, 0x3d4ccccd, 0xc1300000, 0x3f800000, 0, 0, 0,
    0, 0x42180000, 0x3d4ccccd, 0xc1300000, 0x3f800000, 0, 0, 0, 0, 0x421c0000, 0x3d4ccccd,
    0xc1500000, 0x3f800000
};
static u32 WaterInfo_35_0[0x18] = {
    0x41600000, 0x3da7ef9e, 0xc2240000, 0x3f800000, 0, 0, 0, 0, 0x41800000, 0x3da7ef9e,
    0xc2240000, 0x3f800000, 0, 0, 0, 0, 0x41900000, 0x3da7ef9e, 0xc2240000, 0x3f800000
};
static u32 WaterInfo_35_3[0x20] = {
    0x41a00000, 0x3da7ef9e, 0xc2280000, 0x3f800000, 0, 0, 0, 0, 0x41a00000, 0x3da7ef9e,
    0xc2300000, 0x3f800000, 0, 0, 0, 0, 0x41b00000, 0x3da7ef9e, 0xc2300000, 0x3f800000, 0, 0, 0,
    0, 0x41c00000, 0x3da7ef9e, 0xc2300000, 0x3f800000
};
static u32 WaterInfo_35_6[0x28] = {
    0x41200000, 0x3da7ef9e, 0xc2240000, 0x3f800000, 0, 0, 0, 0, 0x41400000, 0x3da7ef9e,
    0xc2240000, 0x3f800000, 0, 0, 0, 0, 0x41600000, 0x3da7ef9e, 0xc2240000, 0x3f800000, 0, 0, 0,
    0, 0x41800000, 0x3da7ef9e, 0xc2240000, 0x3f800000, 0, 0, 0, 0, 0x41900000, 0x3da7ef9e,
    0xc2240000, 0x3f800000
};
static u32 WaterInfo_35_7[0x30] = {
    0x41000000, 0x3da7ef9e, 0xc2280000, 0x3f800000, 0, 0, 0, 0, 0x41000000, 0x3da7ef9e,
    0xc2300000, 0x3f800000, 0, 0, 0, 0, 0x41000000, 0x3da7ef9e, 0xc2380000, 0x3f800000, 0, 0, 0,
    0, 0x40c00000, 0x3da7ef9e, 0xc2280000, 0x3f800000, 0, 0, 0, 0, 0x40c00000, 0x3da7ef9e,
    0xc2300000, 0x3f800000, 0, 0, 0, 0, 0x40c00000, 0x3da7ef9e, 0xc2380000, 0x3f800000
};
static u32 WaterInfo_40_3[0x30] = {
    0xc0400000, 0x3e428f5c, 0xc2840000, 0x3f800000, 0, 0, 0, 0, 0xc0400000, 0x3e428f5c,
    0xc2880000, 0x3f800000, 0, 0, 0, 0, 0xc0400000, 0x3e428f5c, 0xc28c0000, 0x3f800000, 0, 0, 0,
    0, 0xc0a00000, 0x3e428f5c, 0xc2840000, 0x3f800000, 0, 0, 0, 0, 0xc0a00000, 0x3e428f5c,
    0xc2880000, 0x3f800000, 0, 0, 0, 0, 0xc0a00000, 0x3e428f5c, 0xc28c0000, 0x3f800000
};
static u32 WaterInfo_51_11[0x28] = {
    0x41900000, 0x3f35c28f, 0xc2da0000, 0x3f800000, 0, 0, 0, 0, 0x41800000, 0x3f35c28f,
    0xc2da0000, 0x3f800000, 0, 0, 0, 0, 0x41800000, 0x3f35c28f, 0xc2d60000, 0x3f800000, 0, 0, 0,
    0, 0x41600000, 0x3f35c28f, 0xc2da0000, 0x3f800000, 0, 0, 0, 0, 0x41600000, 0x3f35c28f,
    0xc2d60000, 0x3f800000
};
static u32 WaterInfo_51_21[0x8] = {
    0x41900000, 0x3f35c28f, 0xc2da0000, 0x3f800000
};
static u32 WaterInfo_72_8[0x38] = {
    0x41880000, 0x3d8f5c29, 0xc1dc0000, 0x3f800000, 0, 0x3f32b020, 0, 0, 0x41777c90, 0x3d8f5c29,
    0xc1d1b724, 0x3f800000, 0, 0x3f32b020, 0, 0, 0x415ef921, 0x3d8f5c29, 0xc1c76e49, 0x3f800000,
    0, 0x3f32b020, 0, 0, 0x414675b1, 0x3d8f5c29, 0xc1bd256d, 0x3f800000, 0, 0x3f32b020, 0, 0,
    0x412df242, 0x3d8f5c29, 0xc1b2dc92, 0x3f800000, 0, 0x3f32b020, 0, 0, 0x41156ed2, 0x3d8f5c29,
    0xc1a893b6, 0x3f800000, 0, 0x3f32b020, 0, 0, 0x411dbed1, 0x3d8f5c29, 0xc1972d90, 0x3f800000,
    0, 0x3f32b020
};
static u32 WaterInfo_72_9[0x70] = {
    0x42026666, 0x3d8f5c29, 0xc1c80000, 0x3f800000, 0, 0, 0, 0, 0x42026666, 0x3d8f5c29,
    0xc1d80000, 0x3f800000, 0, 0, 0, 0, 0x41f4cccd, 0x3d8f5c29, 0xc1d80000, 0x3f800000, 0, 0, 0,
    0, 0x41f4cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0, 0, 0x41e4cccd, 0x3d8f5c29,
    0xc1d80000, 0x3f800000, 0, 0, 0, 0, 0x41e4cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0,
    0, 0x41d4cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0, 0, 0x41d4cccd, 0x3d8f5c29,
    0xc1f80000, 0x3f800000, 0, 0, 0, 0, 0x41c4cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0,
    0, 0x41c4cccd, 0x3d8f5c29, 0xc1f80000, 0x3f800000, 0, 0, 0, 0, 0x41b4cccd, 0x3d8f5c29,
    0xc1e80000, 0x3f800000, 0, 0, 0, 0, 0x41b4cccd, 0x3d8f5c29, 0xc1f80000, 0x3f800000, 0, 0, 0,
    0, 0x41a4cccd, 0x3d8f5c29, 0xc1e80000, 0x3f800000, 0, 0, 0, 0, 0x41a4cccd, 0x3d8f5c29,
    0xc1f80000, 0x3f800000
};
static u32 WaterInfo_74_4[0x10] = {
    0x41100000, 0x3ca3d70a, 0xc1680000, 0x3f800000, 0, 0, 0, 0, 0x41100000, 0x3ca3d70a,
    0xc1200000, 0x3f800000
};
static u32 WaterInfo_74_5[0x28] = {
    0x41100000, 0x3ca3d70a, 0xc1680000, 0x3f800000, 0, 0, 0, 0, 0x41100000, 0x3ca3d70a,
    0xc1200000, 0x3f800000, 0, 0, 0, 0, 0x4114cccd, 0x3ca3d70a, 0xc1000000, 0x3f800000, 0, 0, 0,
    0, 0x41200000, 0x3ca3d70a, 0xc0c00000, 0x3f800000, 0, 0, 0, 0, 0x41280000, 0x3ca3d70a,
    0xc0800000, 0x3f800000
};
static u32 WaterInfo_74_7[0x28] = {
    0x41100000, 0x3ca3d70a, 0xc1400000, 0x3f800000, 0, 0, 0, 0, 0x41100000, 0x3ca3d70a,
    0xc1200000, 0x3f800000, 0, 0, 0, 0, 0x4114cccd, 0x3ca3d70a, 0xc1000000, 0x3f800000, 0, 0, 0,
    0, 0x41200000, 0x3ca3d70a, 0xc0c00000, 0x3f800000, 0, 0, 0, 0, 0x41280000, 0x3ca3d70a,
    0xc0800000, 0x3f800000
};
static u32 WaterInfo_77_3[0x30] = {
    0xc1dccccd, 0xbfa28f5c, 0x41880000, 0x3f800000, 0, 0, 0, 0, 0xc1eccccd, 0xbfa28f5c,
    0x41880000, 0x3f800000, 0, 0, 0, 0, 0xc1dccccd, 0xbfa28f5c, 0x41980000, 0x3f800000, 0, 0, 0,
    0, 0xc1eccccd, 0xbfa28f5c, 0x41980000, 0x3f800000, 0, 0, 0, 0, 0xc1eccccd, 0xbfa28f5c,
    0x41a80000, 0x3f800000, 0, 0, 0, 0, 0xc1fccccd, 0xbfa28f5c, 0x41a80000, 0x3f800000
};
static u32 WaterInfo_78_1[0x28] = {
    0xc2020000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0, 0, 0xc1f40000, 0x40cc7ae1,
    0xc0b00000, 0x3f800000, 0, 0, 0, 0, 0xc1f40000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0,
    0, 0xc1e40000, 0x40cc7ae1, 0xc0b00000, 0x3f800000, 0, 0, 0, 0, 0xc1e40000, 0x40cc7ae1,
    0xc0600000, 0x3f800000
};
static u32 WaterInfo_78_2[0x88] = {
    0xc2020000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0, 0, 0xc2020000, 0x40cc7ae1,
    0x3f000000, 0x3f800000, 0, 0, 0, 0, 0xc1f40000, 0x40cc7ae1, 0xc0b00000, 0x3f800000, 0, 0, 0,
    0, 0xc1f40000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0, 0, 0xc1f40000, 0x40cc7ae1,
    0x3f000000, 0x3f800000, 0, 0, 0, 0, 0xc1e40000, 0x40cc7ae1, 0xc0b00000, 0x3f800000, 0, 0, 0,
    0, 0xc1e40000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0, 0, 0xc1e40000, 0x40cc7ae1,
    0xbfc00000, 0x3f800000, 0, 0, 0, 0, 0xc1e40000, 0x40cc7ae1, 0x3f000000, 0x3f800000, 0, 0, 0,
    0, 0xc1d40000, 0x40cc7ae1, 0xc0b00000, 0x3f800000, 0, 0, 0, 0, 0xc1d40000, 0x40cc7ae1,
    0xc0600000, 0x3f800000, 0, 0, 0, 0, 0xc1d40000, 0x40cc7ae1, 0xbfc00000, 0x3f800000, 0, 0, 0,
    0, 0xc1d40000, 0x40cc7ae1, 0x3f000000, 0x3f800000, 0, 0, 0, 0, 0xc1c40000, 0x40cc7ae1,
    0xc0b00000, 0x3f800000, 0, 0, 0, 0, 0xc1c40000, 0x40cc7ae1, 0xc0600000, 0x3f800000, 0, 0, 0,
    0, 0xc1c40000, 0x40cc7ae1, 0xbfc00000, 0x3f800000, 0, 0, 0, 0, 0xc1c40000, 0x40cc7ae1,
    0x3f000000, 0x3f800000
};
static u32 WaterInfo_81_1[0x18] = {
    0xc3740000, 0xc0c9999a, 0xc3430000, 0x3f800000, 0, 0, 0, 0, 0xc3780000, 0xc0c9999a,
    0xc3430000, 0x3f800000, 0, 0, 0, 0, 0xc3760000, 0xc0c9999a, 0xc3430000, 0x3f800000
};
static u32 WaterInfo_81_2[0x30] = {
    0xc3780000, 0xc0c9999a, 0xc3410000, 0x3f800000, 0, 0, 0, 0, 0xc3780000, 0xc0c9999a,
    0xc3430000, 0x3f800000, 0, 0, 0, 0, 0xc3760000, 0xc0c9999a, 0xc3430000, 0x3f800000, 0, 0, 0,
    0, 0xc3740000, 0xc0c9999a, 0xc3430000, 0x3f800000, 0, 0, 0, 0, 0xc3720000, 0xc0c9999a,
    0xc3430000, 0x3f800000, 0, 0, 0, 0, 0xc3700000, 0xc0c9999a, 0xc3430000, 0x3f800000
};
static u32 WaterInfo_82_0[0x20] = {
    0xc34b0000, 0x3e23d70a, 0xc32b0000, 0x3f800000, 0, 0, 0, 0, 0xc34b0000, 0x3e23d70a,
    0xc3290000, 0x3f800000, 0, 0, 0, 0, 0xc3490000, 0x3e23d70a, 0xc32b0000, 0x3f800000, 0, 0, 0,
    0, 0xc3490000, 0x3e23d70a, 0xc3290000, 0x3f800000
};
static u32 WaterInfo_82_1[0x40] = {
    0xc3444ccd, 0x3e23d70a, 0xc32d0000, 0x3f800000, 0, 0, 0, 0, 0xc3464ccd, 0x3e23d70a,
    0xc32d0000, 0x3f800000, 0, 0, 0, 0, 0xc3444ccd, 0x3e23d70a, 0xc32f0000, 0x3f800000, 0, 0, 0,
    0, 0xc3464ccd, 0x3e23d70a, 0xc32f0000, 0x3f800000, 0, 0, 0, 0, 0xc3440000, 0x3e23d70a,
    0xc3310000, 0x3f800000, 0, 0, 0, 0, 0xc3460000, 0x3e23d70a, 0xc3310000, 0x3f800000, 0, 0, 0,
    0, 0xc344cccd, 0x3e23d70a, 0xc3330000, 0x3f800000, 0, 0, 0, 0, 0xc3450000, 0x3e23d70a,
    0xc3350000, 0x3f800000
};
static u32 WaterInfo_84_72[0x18] = {
    0xc3620000, 0x3e428f5c, 0xc3520000, 0x3f800000, 0, 0, 0, 0, 0xc3640000, 0x3e428f5c,
    0xc3520000, 0x3f800000, 0, 0, 0, 0, 0xc3640000, 0x3e428f5c, 0xc3540000, 0x3f800000
};
static u32 WaterInfo_86_5[0x20] = {
    0xc36f0000, 0x3e428f5c, 0xc3740000, 0x3f800000, 0, 0, 0, 0, 0xc36e0000, 0x3e428f5c,
    0xc3760000, 0x3f800000, 0, 0, 0, 0, 0xc3700000, 0x3e428f5c, 0xc3760000, 0x3f800000, 0, 0, 0,
    0, 0xc3720000, 0x3e428f5c, 0xc3760000, 0x3f800000
};
static u32 WaterInfo_86_8[0x30] = {
    0xc36c0000, 0x3e428f5c, 0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc36e0000, 0x3e428f5c,
    0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc3700000, 0x3e428f5c, 0xc37c0000, 0x3f800000, 0, 0, 0,
    0, 0xc3720000, 0x3e428f5c, 0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc3740000, 0x3e428f5c,
    0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc3730000, 0x3e428f5c, 0xc37e0000, 0x3f800000
};
static u32 WaterInfo_87_4[0x30] = {
    0xc3408000, 0x3e428f5c, 0xc37b0000, 0x3f800000, 0, 0, 0, 0, 0xc3408000, 0x3e428f5c,
    0xc3790000, 0x3f800000, 0, 0, 0, 0, 0xc33e8000, 0x3e428f5c, 0xc37b0000, 0x3f800000, 0, 0, 0,
    0, 0xc33e8000, 0x3e428f5c, 0xc3790000, 0x3f800000, 0, 0, 0, 0, 0xc33c8000, 0x3e428f5c,
    0xc37b0000, 0x3f800000, 0, 0, 0, 0, 0xc33c8000, 0x3e428f5c, 0xc3790000, 0x3f800000
};
static u32 WaterInfo_87_8[0xf0] = {
    0xc3540000, 0x3e428f5c, 0xc3818000, 0x3f800000, 0, 0, 0, 0, 0xc3520000, 0x3e428f5c,
    0xc3818000, 0x3f800000, 0, 0, 0, 0, 0xc3500000, 0x3e428f5c, 0xc3818000, 0x3f800000, 0, 0, 0,
    0, 0xc34e0000, 0x3e428f5c, 0xc3818000, 0x3f800000, 0, 0, 0, 0, 0xc34c0000, 0x3e428f5c,
    0xc3818000, 0x3f800000, 0, 0, 0, 0, 0xc34a0000, 0x3e428f5c, 0xc3818000, 0x3f800000, 0, 0, 0,
    0, 0xc3480000, 0x3e428f5c, 0xc3818000, 0x3f800000, 0, 0, 0, 0, 0xc3540000, 0x3e428f5c,
    0xc3828000, 0x3f800000, 0, 0, 0, 0, 0xc3520000, 0x3e428f5c, 0xc3828000, 0x3f800000, 0, 0, 0,
    0, 0xc3500000, 0x3e428f5c, 0xc3828000, 0x3f800000, 0, 0, 0, 0, 0xc34e0000, 0x3e428f5c,
    0xc3828000, 0x3f800000, 0, 0, 0, 0, 0xc34c0000, 0x3e428f5c, 0xc3828000, 0x3f800000, 0, 0, 0,
    0, 0xc34a0000, 0x3e428f5c, 0xc3828000, 0x3f800000, 0, 0, 0, 0, 0xc3480000, 0x3e428f5c,
    0xc3828000, 0x3f800000, 0, 0, 0, 0, 0xc34c0000, 0x3e428f5c, 0xc3838000, 0x3f800000, 0, 0, 0,
    0, 0xc34a0000, 0x3e428f5c, 0xc3838000, 0x3f800000, 0, 0, 0, 0, 0xc3530000, 0x3e428f5c,
    0xc3800000, 0x3f800000, 0, 0, 0, 0, 0xc3510000, 0x3e428f5c, 0xc3800000, 0x3f800000, 0, 0, 0,
    0, 0xc34f0000, 0x3e428f5c, 0xc3800000, 0x3f800000, 0, 0, 0, 0, 0xc34d0000, 0x3e428f5c,
    0xc3800000, 0x3f800000, 0, 0, 0, 0, 0xc34b0000, 0x3e428f5c, 0xc3800000, 0x3f800000, 0, 0, 0,
    0, 0xc3490000, 0x3e428f5c, 0xc3800000, 0x3f800000, 0, 0, 0, 0, 0xc3520000, 0x3e428f5c,
    0xc37e0000, 0x3f800000, 0, 0, 0, 0, 0xc3500000, 0x3e428f5c, 0xc37e0000, 0x3f800000, 0, 0, 0,
    0, 0xc34e0000, 0x3e428f5c, 0xc37e0000, 0x3f800000, 0, 0, 0, 0, 0xc34c0000, 0x3e428f5c,
    0xc37e0000, 0x3f800000, 0, 0, 0, 0, 0xc34a0000, 0x3e428f5c, 0xc37e0000, 0x3f800000, 0, 0, 0,
    0, 0xc34e0000, 0x3e428f5c, 0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc34c0000, 0x3e428f5c,
    0xc37c0000, 0x3f800000, 0, 0, 0, 0, 0xc34a0000, 0x3e428f5c, 0xc37c0000, 0x3f800000
};
static u32 WaterCameraInfo[0x44] = {
    0x50806, (u32)&WaterInfo_6_8, 0x50206, (u32)&WaterInfo_6_8, 0x50b06, (u32)&WaterInfo_6_8,
    0x70208, (u32)&WaterInfo_8_2, 0x9050a, (u32)&WaterInfo_10_5, 0xb0a0a, (u32)&WaterInfo_10_10,
    0x30023, (u32)&WaterInfo_35_0, 0x40323, (u32)&WaterInfo_35_3, 0x50623, (u32)&WaterInfo_35_6,
    0x60723, (u32)&WaterInfo_35_7, 0x60328, (u32)&WaterInfo_40_3, 0x61328, (u32)&WaterInfo_40_3,
    0x50b33, (u32)&WaterInfo_51_11, 0x11533, (u32)&WaterInfo_51_21, 0x12233,
    (u32)&WaterInfo_51_21, 0x70848, (u32)&WaterInfo_72_8, 0xe0948, (u32)&WaterInfo_72_9,
    0x2044a, (u32)&WaterInfo_74_4, 0x5054a, (u32)&WaterInfo_74_5, 0x5074a, (u32)&WaterInfo_74_7,
    0x6034d, (u32)&WaterInfo_77_3, 0x5014e, (u32)&WaterInfo_78_1, 0x11024e,
    (u32)&WaterInfo_78_2, 0x30151, (u32)&WaterInfo_81_1, 0x60251, (u32)&WaterInfo_81_2, 0x40052,
    (u32)&WaterInfo_82_0, 0x80152, (u32)&WaterInfo_82_1, 0x34754, (u32)&WaterInfo_84_72,
    0x34854, (u32)&WaterInfo_84_72, 0x40556, (u32)&WaterInfo_86_5, 0x60856,
    (u32)&WaterInfo_86_8, 0x60457, (u32)&WaterInfo_87_4, 0x1e0857, (u32)&WaterInfo_87_8
};

extern void sceVu0MulMatrix(void *, void *, void *);
extern void sceVu0RotTransPersN(void *, void *, void *, int, int);
extern void sceVu0CopyVector(void *, void *);
extern void sceVu0RotTransPers(void *, void *, void *, int);
extern float sinf(float);
extern float cosf(float);
extern u8 GameSt[];
extern u32 WorldPos[];




extern float SinTable[6][2];

struct UWS_WaterInfo { float Pos[4]; float Ang[4]; };
struct UWS_WaterMng { unsigned char Use; unsigned char unused[3]; float Phase[2]; float Wavelength[2]; float Amplitude[2]; float Speed[2]; struct UWS_WaterInfo *lpWaterInfo; };

#define UWS_ADJ(a) ((3.1415927f + (a)) >= 0.0f ? ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f))) : (6.2831855f + ((a) - (6.2831855f * (float)(s32)((3.1415927f + (a)) / 6.2831855f)))))
#define UWS_WPOS ((float (*)[6][4])WorldPos)
#define UWS_SXYZ ((int (*)[6][4])ScreenXYZ)
#define UWS_SST ((float (*)[6][4])ScreenST)
#define UWS_RGBA ((int (*)[6][4])ScreenRGBA)
#define UWS_FLAG OuterFlag
#define UWS_SIN SinTable

static inline void UWS_MakeLocalMatrix(float m[4][4], struct UWS_WaterMng *mng) {
    float Scale[4] __attribute__((aligned(16))) = {1.0f, 1.0f, 1.0f, 1.0f};
    float *scale = Scale;
    struct UWS_WaterInfo *info = mng->lpWaterInfo;
    float *pos = info->Pos;
    float *ang = info->Ang;
    float ax;
    float ay;
    float az;
    float sx;
    float cx;
    float sy;
    float cy;
    float sz;
    float cz;

    ax = UWS_ADJ(ang[0]);
    ay = UWS_ADJ(ang[1]);
    az = UWS_ADJ(ang[2]);
    sx = sinf(ax);
    cx = cosf(ax);
    sz = sinf(az);
    cz = cosf(az);
    sy = sinf(ay);
    cy = cosf(ay);
    m[0][0] = cz * (scale[0] * cy);
    m[0][1] = scale[0] * sz;
    m[0][2] = cz * (scale[0] * -sy);
    m[0][3] = 0.0f;
    m[1][0] = scale[1] * (sy * sx - cx * (cy * sz));
    m[1][1] = cx * (scale[1] * cz);
    m[1][2] = scale[1] * (cy * sx + cx * (sy * sz));
    m[1][3] = 0.0f;
    m[2][0] = scale[2] * (sy * cx + sx * (cy * sz));
    m[2][1] = sx * (scale[2] * -cz);
    m[2][2] = scale[2] * (cy * cx - sx * (sy * sz));
    m[2][3] = 0.0f;
    m[3][0] = pos[0];
    m[3][1] = pos[1];
    m[3][2] = pos[2];
    m[3][3] = 1.0f;
}


/* DrawMirror @ 0x1A20D0 .. 0x1A2144 (0x74 bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop body is not one contiguous region: .L001A2100
 */

static void MakeMirrorTexture(void);
struct UWS_WaterMng;
static void UpdateWaterSurface(struct UWS_WaterMng *);
extern void DrawWaterSurface();

/* SetMirror @ 0x1A2150 .. 0x1A226C (0x11c bytes, frame 0x30) */
/*
 * dcomp notes:
 *   cfg: loop header already being structured: .L001A2190
 *   declaration vs inferred signature: return void vs inferred u32
 */

extern void * memset(void *, int, unsigned int);
extern u32 WaterCameraInfo[];

/* InitMirror @ 0x1A2270 .. 0x1A232C (0xbc bytes) */
/*
 * dcomp notes:
 *   fpu: float literal 0x40200000 at 0x1a2294
 *   fpu: float literal 0x3ecccccd at 0x1a229c
 *   fpu: mtc1 reinterprets t5 at 0x1a22ac
 *   fpu: mtc1 reinterprets t4 at 0x1a22c8
 *   cfg: loop body is not one contiguous region: .L001A22A8
 */

extern u32 WorldPos[];
extern u32 ScreenST[];
extern u32 ScreenRGBA[];

static u32 WorldPos[0x90];
static u32 ScreenXYZ[0x90];
static u32 ScreenST[0x90];
static u32 ScreenRGBA[0x90];
static unsigned char OuterFlag[6][6];
static float SinTable[6][2];

/* dcomp: prototypes for definition reordering (MWCC -inline deferred emits functions in reverse order) */
void InitMirror(void);
void SetMirror(unsigned char a0 , unsigned char a1 );
void DrawMirror(void);
void SetObjectParamMirror(void *a0 );


void InitMirror(void) {
    s32 t5;
    s32 t4;
    u8 *t3;
    u32 *t2;
    float f3;
    u32 *t1;
    float f2;
    u8 *t0;
    u32 *a3;
    u32 *a2;
    float f1;
    s32 a1;
    s32 a0;
    s32 v1;
    float f0;

    t5 = 0;
    t3 = (u8 *)WorldPos;
    t2 = ScreenST;
    t1 = ScreenRGBA;
    f2 = 2.5f;
    f1 = 0.400000006f;
    a1 = 0x3f800000;
    a0 = 0x80;
    do {
        t4 = 0;
        t0 = t3;
        a3 = t2;
        a2 = t1;
        f3 = (f1 * ((float)((float)(s32)(u32)t5) - f2));
        do {
            f0 = (float)t4;
            *(f32 *)t0 = f3;
            *(u32 *)(t0 + 4) = 0;
            *(f32 *)(t0 + 8) = (f1 * (f0 - f2));
            *(u32 *)(t0 + 0xc) = a1;
            a3[2] = a1;
            t0 = (u8 *)(t0 + 0x10);
            a3[3] = 0;
            a2[3] = a0;
            a3 = (u32 *)(u8 *)(a3 + 4);
            t4 = t4 + 1;
            a2 = (u32 *)(u8 *)(a2 + 4);
        } while (t4 < (s32)6);
        t3 = (u8 *)(t3 + 0x60);
        t2 = (u32 *)(u8 *)(t2 + 0x18);
        t5 = t5 + 1;
        t1 = (u32 *)(u8 *)(t1 + 0x18);
    } while (t5 < (s32)6);
    sCurWaterCameraInfo = 0;
    return;
}

void SetMirror(unsigned char a0 /* r4 */, unsigned char a1 /* r5 */) {
    u32 t3;
    s32 t2;
    u8 *t1;
    s32 t0;
    s32 a3;
    u32 a2;
    u32 a1_2; // a1
    u32 a0_2;
    u32 v1;

    a0_2 = (u32)WaterSurfaceMng;
    memset((void *)WaterSurfaceMng, 0, 0x500);
    a2 = (u8)a0;
    v1 = (u32)WaterCameraInfo;
    a1_2 = (u8)a1;
    sCurWaterCameraInfo = (u32)WaterCameraInfo;
    while (1) {
        a0_2 = sCurWaterCameraInfo;
        v1 = *(u8 *)a0_2;
        if (v1 == 0) {
            sCurWaterCameraInfo = 0;
            return;
        }
        if (v1 == a2 && (u32)*(u8 *)((a0_2 + 1)) == a1_2) {
            break;
        }
        sCurWaterCameraInfo += 8;
    }
    v1 = *(s16 *)((a0_2 + 2));
    t3 = *(s32 *)((a0_2 + 4));
    t2 = 0;
    if (0 < (s32)v1) {
        t1 = WaterSurfaceMng;
        v1 = 0x3d560000;
        a0_2 = 0x3d230000;
        a1_2 = 0x3d560000 | 0x6cf4;
        a2 = 0x3d230000 | 0xd70b;
        v1 = 0x3f2a0000;
        t0 = 1;
        a3 = 0x3f800000;
        a0_2 = 0x3f2a0000 | 0xaaab;
        do {
            *(u8 *)t1 = t0;
            *(u32 *)(t1 + 4) = 0;
            t2 = t2 + 1;
            *(u32 *)(t1 + 0xc) = a3;
            *(u32 *)(t1 + 0x14) = a2;
            *(u32 *)(t1 + 0x1c) = a1_2;
            *(u32 *)(t1 + 8) = 0;
            *(u32 *)(t1 + 0x10) = a0_2;
            *(u32 *)(t1 + 0x18) = a2;
            *(u32 *)(t1 + 0x20) = a1_2;
            *(u32 *)(t1 + 0x24) = t3;
            t1 = (u8 *)(t1 + 0x28);
            v1 = t2 < (s32)*(s16 *)((sCurWaterCameraInfo + 2));
            t3 = t3 + 0x20;
        } while (v1 != 0);
    }
    return;
}

void DrawMirror(void) {
    u32 v1;
    u8 *s1;
    s32 s0;

    v1 = sCurWaterCameraInfo;
    if (v1 != 0) {
        MakeMirrorTexture();
        s0 = 0;
        s1 = (u8 *)WaterSurfaceMng;
        do {
            v1 = *(u8 *)s1;
            if (v1 == 0) {
                break;
            }
            UpdateWaterSurface((void *)(u8 *)s1);
            DrawWaterSurface((u8 *)s1);
            s0 = s0 + 1;
            v1 = s0 < (s32)0x20;
            s1 = (u8 *)(s1 + 0x28);
        } while (v1 != 0);
    }
    return;
}

static void UpdateWaterSurface(struct UWS_WaterMng *lpWaterMng) {
    int x;
    int z;
    int i;
    float Angle;
    float lsMat[4][4] __attribute__((aligned(16)));
    float WorldST[4] __attribute__((aligned(16)));
    int ScreenUV[4] __attribute__((aligned(16)));
    float Rate0;
    float Rate1;
    float Rate2;

    if (GameSt[0xf] == 0) {
        for (i = 0; i < 2; i++) {
            for (x = 0; x < 6; x++) {
                Angle = lpWaterMng->Phase[i] + (UWS_WPOS[x][0][0] / lpWaterMng->Wavelength[i]) * 6.2831855f;
                UWS_SIN[x][i] = lpWaterMng->Amplitude[i] * sinf(UWS_ADJ(Angle));
            }
            lpWaterMng->Phase[i] += lpWaterMng->Speed[i];
        }
    }
    UWS_MakeLocalMatrix(lsMat, lpWaterMng);
    sceVu0MulMatrix(lsMat, (u8 *)lpDrawMng + 0x2b0, lsMat);
    sceVu0RotTransPersN(ScreenXYZ, lsMat, WorldPos, 0x24, 0);
    for (x = 0; x < 6; x++) {
        for (z = 0; z < 6; z++) {
            sceVu0CopyVector(WorldST, UWS_WPOS[x][z]);
            WorldST[0] += UWS_SIN[x][0];
            WorldST[1] += UWS_SIN[z][1];
            sceVu0RotTransPers(ScreenUV, lsMat, WorldST, 0);
            UWS_SST[x][z][0] = (float)(ScreenUV[0] - 0x7000) / 8192.0f;
            UWS_SST[x][z][1] = (float)(ScreenUV[1] - 0x7200) / 8192.0f;
            Rate0 = 0.5f * ((lpWaterMng->Amplitude[0] + UWS_SIN[x][0]) / lpWaterMng->Amplitude[0]);
            Rate1 = 0.5f * ((lpWaterMng->Amplitude[1] + UWS_SIN[z][1]) / lpWaterMng->Amplitude[1]);
            Rate2 = Rate0 * Rate0 + Rate1 * Rate1;
            if (Rate2 > 1.0f) {
                Rate2 = 1.0f;
            }
            UWS_RGBA[x][z][0] = UWS_RGBA[x][z][1] = UWS_RGBA[x][z][2] = (int)(64.0f + 64.0f * (1.0f - Rate2));
            UWS_FLAG[x][z] = !(UWS_SXYZ[x][z][0] > 0 && UWS_SXYZ[x][z][0] < 0x10000 && UWS_SXYZ[x][z][1] > 0 && UWS_SXYZ[x][z][1] < 0x10000 && UWS_SXYZ[x][z][2] > 0 && UWS_SXYZ[x][z][2] < 0xffffff);
        }
    }
}

void DrawWaterSurface(void)
{
    unsigned int *lpCurDMA = (unsigned int *)lpMdlPacketMem;
    int i;
    int j;
    int Start;
    int End;
    unsigned int PrimNum;

    lpCurDMA[0] = 0x10000007;
    lpCurDMA[1] = 0;
    lpCurDMA[2] = 0;
    lpCurDMA[3] = 0x50000007;
    lpCurDMA[4] = 6;
    lpCurDMA[5] = 0x10000000;
    lpCurDMA[6] = 0xe;
    lpCurDMA[7] = 0;
    ((u_long *)lpCurDMA)[4] = 0;
    ((u_long *)lpCurDMA)[5] = 0x3f;
    ((u_long *)lpCurDMA)[6] = 0x51001;
    ((u_long *)lpCurDMA)[7] = 0x47;
    ((u_long *)lpCurDMA)[8] = 0x620213bc0;
    ((u_long *)lpCurDMA)[9] = 6;
    ((u_long *)lpCurDMA)[10] = 0x60;
    ((u_long *)lpCurDMA)[11] = 0x14;
    ((u_long *)lpCurDMA)[12] = 0x4000000068;
    ((u_long *)lpCurDMA)[13] = 0x42;
    ((u_long *)lpCurDMA)[14] = 0x3f80000080808080;
    ((u_long *)lpCurDMA)[15] = 1;
    lpCurDMA += 32;

    for (i = 0; i < 5; i++) {
        Start = -1;
        End = 6;
        for (j = 0; j < 6; j++) {
            if (Start == -1 && DWS_FLAG[j][i] == 0 && DWS_FLAG[j][i + 1] == 0) {
                Start = j;
            }
            if (Start != -1 && End == 6 && (DWS_FLAG[j][i] != 0 || DWS_FLAG[j][i + 1] != 0)) {
                End = j;
            }
        }
        if (Start != -1) {
            PrimNum = (End - Start) * 6 + 1;
            lpCurDMA[0] = PrimNum | 0x10000000;
            lpCurDMA[1] = 0;
            lpCurDMA[2] = 0;
            lpCurDMA[3] = PrimNum | 0x50000000;
            lpCurDMA[4] = (End - Start) * 2;
            lpCurDMA[5] = 0x302e4000;
            lpCurDMA[6] = 0x412;
            lpCurDMA[7] = 0;
            lpCurDMA += 8;
            for (; Start < End; Start++) {
                ((u_long128 *)lpCurDMA)[0] = *(u_long128 *)DWS_SST[Start][i];
                ((u_long128 *)lpCurDMA)[1] = *(u_long128 *)DWS_RGBA[Start][i];
                ((u_long128 *)lpCurDMA)[2] = *(u_long128 *)DWS_SXYZ[Start][i];
                ((u_long128 *)lpCurDMA)[3] = *(u_long128 *)DWS_SST[Start][i + 1];
                ((u_long128 *)lpCurDMA)[4] = *(u_long128 *)DWS_RGBA[Start][i + 1];
                ((u_long128 *)lpCurDMA)[5] = *(u_long128 *)DWS_SXYZ[Start][i + 1];
                lpCurDMA += 24;
            }
        }
    }
    lpMdlPacketMem = (unsigned int)lpCurDMA;
}

static void MakeMirrorTexture(void) {
    u8 *t6;
    u32 t2;
    s32 t1;
    u8 *s0;
    s32 a3;
    u32 a0;
    u64 a2_64;
    u32 v1;
    u64 t0_64;
    u32 v0;
    u64 a3_64;
    u64 a1_64;

    a0 = lpDrawMng;
    v0 = *(s32 *)((a0 + 0x408));
    v1 = lpMdlPacketMem;
    if (v0 == 0) {
        s0 = (u8 *)(s32)(a0 + 0x60);
    } else {
        s0 = (u8 *)(s32)(a0 + 0x150);
    }
    t1 = 0x10000000;
    v0 = 0x51000000;
    *(u32 *)v1 = 0x10000000 | 6;
    *(u32 *)((v1 + 4)) = 0;
    a0 = 0x8005;
    *(u32 *)((v1 + 8)) = 0;
    v0 = 0xe;
    *(u32 *)((v1 + 0xc)) = 0x51000000 | 6;
    *(u32 *)((v1 + 0x10)) = 0x8005;
    a0 = -0x1000000;
    *(u32 *)((v1 + 0x14)) = 0x10000000;
    *(u32 *)((v1 + 0x18)) = v0;
    *(u32 *)((v1 + 0x1c)) = 0;
    a0 = 0x20401de;
    *(u64 *)((v1 + 0x20)) = 0;
    *(s64 *)((v1 + 0x28)) = (s32)0x3f;
    *(u64 *)((v1 + 0x30)) = (u64)((s32)((s32)0x20401de)) | (u64)((u64)(s32)-0x1000000 << 0x20);
    t2 = 0x8002;
    *(s64 *)((v1 + 0x38)) = (s32)0x4c;
    t1 = 0x30000;
    *(u64 *)((v1 + 0x40)) = (u64)((s32)((s32)0x7800)) | (u64)((u64)(u32)0x7900 << 0x20);
    a0 = 0xdf0000;
    *(s64 *)((v1 + 0x48)) = (s32)0x18;
    a0 = 0xff0000;
    *(u64 *)((v1 + 0x50)) = (u64)((s32)((s32)0xff0000)) | (u64)((u64)(u32)0xdf0000 << 0x20);
    a0 = 0x32000000;
    *(s64 *)((v1 + 0x58)) = (s32)0x40;
    *(s64 *)((v1 + 0x60)) = (s32)(0x32000000 | 0x1ee);
    *(s64 *)((v1 + 0x68)) = (s32)0x4e;
    *(u32 *)((v1 + 0x70)) = 0x10000000 | 5;
    a0 = 0x10030000;
    *(u32 *)((v1 + 0x74)) = 0;
    *(u32 *)((v1 + 0x78)) = 0;
    a0 = 0x3f800000;
    *(u32 *)((v1 + 0x7c)) = 0x51000000 | 5;
    *(u32 *)((v1 + 0x80)) = 0x8002;
    *(u32 *)((v1 + 0x84)) = 0x10030000 | 0x4000;
    *(u32 *)((v1 + 0x88)) = v0;
    a3 = 0x14000000;
    *(u32 *)((v1 + 0x8c)) = 0;
    v0 = 0x78f00000;
    *(s64 *)((v1 + 0x90)) = (s32)0x30000;
    *(s64 *)((v1 + 0x98)) = (s32)0x47;
    *(u64 *)((v1 + 0xa0)) = (u64)(u32)0x3f800000 << 0x20;
    *(s64 *)((v1 + 0xa8)) = (s32)1;
    v0 = 0x8700;
    *(u32 *)((v1 + 0xb0)) = 0x8002;
    *(u32 *)((v1 + 0xb4)) = 0x14000000;
    *(u32 *)((v1 + 0xb8)) = 4;
    v0 = v1 + 0xd0;
    *(u32 *)((v1 + 0xbc)) = 0;
    *(s64 *)((v1 + 0xc0)) = (s32)(0x78f00000 | 0x77f0);
    *(u64 *)((v1 + 0xc8)) = (u64)((u64)0x8700 << 0x10) | (u64)(0x8800);
    lpMdlPacketMem = v0;
    v1 = *(s32 *)(WaterSurfaceMng + 0x24);
    v0 = lpDrawMng;
    *(f32 *)((v0 + 0x428)) = *(float *)((v1 + 4));
    DrawReverseByOT();
    t6 = (u8 *)lpMdlPacketMem;
    v1 = 0x51000000;
    t2 = 0x8005;
    *(u32 *)t6 = 0x10000000 | 6;
    v1 = (s32)(t6 + 0x70);
    *(u32 *)(t6 + 4) = 0;
    *(u32 *)(t6 + 8) = 0;
    *(u32 *)(t6 + 0xc) = 0x51000000 | 6;
    *(u32 *)(t6 + 0x10) = 0x8005;
    *(u32 *)(t6 + 0x14) = 0x10000000;
    *(u32 *)(t6 + 0x18) = 0xe;
    *(u32 *)(t6 + 0x1c) = 0;
    *(u64 *)(t6 + 0x20) = 0;
    *(s64 *)(t6 + 0x28) = (s32)0x3f;
    t0_64 = *(u64 *)s0;
    *(u64 *)(t6 + 0x30) = t0_64;
    *(s64 *)(t6 + 0x38) = (s32)0x4c;
    a3_64 = *(u64 *)(s0 + 0x20);
    *(u64 *)(t6 + 0x40) = a3_64;
    *(s64 *)(t6 + 0x48) = (s32)0x18;
    a2_64 = *(u64 *)(s0 + 0x30);
    *(u64 *)(t6 + 0x50) = a2_64;
    *(s64 *)(t6 + 0x58) = (s32)0x40;
    a1_64 = *(u64 *)(s0 + 0x10);
    *(u64 *)(t6 + 0x60) = a1_64;
    *(s64 *)(t6 + 0x68) = (s32)0x4e;
    lpMdlPacketMem = v1;
    return;
}

/* SetObjectParamMirror @ 0x1A1490 .. 0x1A14E0 (0x50 bytes) */
/*
 * dcomp notes:
 *   declaration vs inferred signature: return void vs inferred u32
 */

void SetObjectParamMirror(void *a0 /* r4 */) {
    u8 *a3;
    u8 *a2;
    s32 a1;
    u32 v1;

    a3 = (u8 *)*(s32 *)(((u8 *)a0 + 0x10));
    a2 = (u8 *)*(s32 *)(a3 + 0x1c);
    a0 = (void *)(s32)1;
    v1 = *(s32 *)(a3 + 0x38);
    *(u8 *)((v1 + 9)) = (s32)a0;
    v1 = *(s16 *)(a3 + 0x10);
    a1 = 0;
    if (0 < (s32)v1) {
        do {
            v1 = *(s32 *)(a2 + 0x54);
            a1 = a1 + 1;
            *(u8 *)((v1 + 0xa)) = (s32)a0;
            v1 = *(s16 *)(a3 + 0x10);
            v1 = a1 < (s32)v1;
            a2 = (u8 *)(a2 + 0x60);
        } while (v1 != 0);
    }
    return;
}
