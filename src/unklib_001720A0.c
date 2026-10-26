#include "common.h"

s32 FsCConvUTF16To8(u8 *destination, u8 *source) {
    u8 *out = destination;
    u32 value;

    while ((value = *(u16 *)source) != 0) {
        if (value & 0xf800) {
            *out++ = (value >> 12) | 0xe0;
            *out++ = ((*(u16 *)source >> 6) & 0x3f) | 0x80;
            *out++ = (*(u16 *)source & 0x3f) | 0x80;
        } else if (value & 0x780) {
            *out++ = ((value >> 6) & 0x1f) | 0xc0;
            *out++ = (*(u16 *)source & 0x3f) | 0x80;
        } else {
            *out++ = *(u16 *)source;
        }
        source += 2;
    }
    *out = 0;
    return out - destination + 1;
}


s32 FsCConvUTF8To16(u8 *destination, u8 *source) {
    u32 value = *source;
    const s32 leadWidths[16] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4
    };
    u8 *out = destination;
    s32 width;

    while (value != 0) {
        width = leadWidths[value >> 4];
        switch (width) {
        case 0:
            *(u16 *)out = *source++;
            break;
        case 2:
            *(u16 *)out = (value & 0x1f) << 6;
            source++;
            *(u16 *)out = *(u16 *)out + (*source++ & 0x3f);
            break;
        case 3:
            source++;
            *(u16 *)out = (value & 0xf) << 12;
            *(u16 *)out = *(u16 *)out + ((*source++ & 0x3f) << 6);
            *(u16 *)out = *(u16 *)out + (*source++ & 0x3f);
            break;
        default:
            if (width != 1 && width < 7) {
                return -3;
            }
            return -2;
        }
        value = *source;
        out += 2;
    }
    *(u16 *)out = 0;
    return out - destination + 2;
}

