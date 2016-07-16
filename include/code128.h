#ifndef _CODE128_H_
#define _CODE128_H_

#include <types.h>

#define INPUT_DATA_LEN 8
#define StartC 105
#define Stop 106

ZB_S8 ZB_Code128CMakeCode(ZB_U8 *pData, ZB_U8 nInputLen, ZB_U16 *pRes, ZB_U8 nResLen);

#endif
