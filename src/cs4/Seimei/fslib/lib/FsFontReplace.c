#include "common.h"

extern int FsCConvUTF16To8(char *dst, unsigned short *src);
extern int FsCConvUTF8To16(unsigned short *dst, char *src);
extern int vsprintf(char *, const char *, char *);

#define FRU_VA_ARG(ap, type) (*(type *)((ap += 8) - 8))

static inline unsigned short *FRU_G(unsigned short *v) {
    if (v == 0) {
        return 0;
    }
    return v;
}

int FontReplaceUnicode(unsigned short *destStr, unsigned short *fmtStr, char *vaList) {
    char *p;
    char c;
    char *pUTF8;
    char tmpUTF8[768];
    char tmp[768];
    int ret;
    char *saveVaList;
    char **ppListPos;
    int isPercent;
    int formatType;

    saveVaList = vaList;
    isPercent = 0;
    formatType = 0;
    pUTF8 = tmpUTF8;
    ret = FsCConvUTF16To8(pUTF8, fmtStr);
    if (ret < 0) {
        return -11;
    }
    pUTF8 += ret;
    p = tmpUTF8;
    c = *p;
    if (c == 0) goto done;
top:
    if (c == '%') {
        isPercent = !isPercent;
        formatType = 0;
    } else if (isPercent) {
        switch (c) {
        case 'l':
        case 'L':
            formatType = 2;
            break;
        case 'h':
            formatType = 1;
            break;
        default:
            switch (c) {
            case 'c':
            case 'C':
                if (formatType & 2) {
                    return -10;
                }
                *p = 's';
                ppListPos = &FRU_VA_ARG(vaList, char *);
                ret = FsCConvUTF16To8(pUTF8, (unsigned short *)ppListPos);
                if (ret < 0) {
                    return -11;
                }
                *ppListPos = pUTF8;
                pUTF8 += ret;
                break;
            case 's':
            case 'S':
                if (formatType & 2) {
                    return -10;
                }
                ppListPos = &FRU_VA_ARG(vaList, char *);
                ret = FsCConvUTF16To8(pUTF8, (unsigned short *)*ppListPos);
                if (ret < 0) {
                    return -11;
                }
                *ppListPos = pUTF8;
                pUTF8 += ret;
                break;
            case 'u':
                FRU_VA_ARG(vaList, unsigned int);
                break;
            case 'd':
            case 'i':
            case 'o':
            case 'x':
            case 'X':
                FRU_VA_ARG(vaList, int);
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                FRU_VA_ARG(vaList, double);
                break;
            default:
                formatType = 0;
                p++;
                goto test;
            }
            formatType = 0;
            isPercent = 0;
            break;
        }
    } else {
        formatType = 0;
    }
    p++;
test:
    c = *p;
    if (c) goto top;
    destStr = (unsigned short *)(unsigned int)destStr;
done:
    ret = vsprintf(tmp, tmpUTF8, saveVaList);
    if (ret < 0) {
        return -9;
    }
    ret = FsCConvUTF8To16(destStr, tmp);
    return ret < 0 ? -11 : 0;
}

