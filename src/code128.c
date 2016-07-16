#include <stdio.h>
#include <string.h>
#include "code128.h"


const ZB_U16 Code128ListC[107] =
{
    0x6cc, //0
    0x66c, //1
    0x666, //2
    0x498, //3
    0x48c, //4
    0x44c, //5
    0x4c8, //6
    0x264, //7
    0x464, //8
    0x648, //9
    0x644, //10	
    0x624, //11
	0x59c, //12
	0x4dc, //13
	0x4ce, //14
	0x5cc, //15
	0x4ec, //16
	0x4e6, //17
	0x672, //18
	0x65c, //19
	0x64e, //20
	0x6e4, //21
	0x674, //22
	0x76e, //23
	0x74c, //24
	0x72c, //25
	0x726, //26
	0x764, //27
	0x734, //28
	0x732, //29
	0x6d8, //30
	0x6c6, //31
	0x636, //32
	0x518, //33
	0x458, //34
	0x446, //35
	0x588, //36
	0x468, //37
	0x462, //38
	0x688, //39
	0x628, //40
	0x622, //41
	0x5b8, //42
	0x58e, //43
    0x46e, //44
	0x5d8, //45
	0x5c6, //46
	0x476, //47
	0x776, //48
	0x68e, //49
	0x62e, //50
	0x6e8, //51
	0x6e2, //52
	0x6ee, //53
	0x758, //54
	0x746, //55
	0x716, //56
	0x768, //57
	0x762, //58
	0x71a, //59
	0x77a, //60
	0x642, //61
	0x78a, //62
	0x530, //63
	0x50c, //64
	0x4b0, //65
	0x486, //66
	0x42c, //67
	0x426, //68
	0x590, //69
	0x584, //70
	0x4d0, //71
	0x4c2, //72
	0x434, //73
	0x432, //74
	0x612, //75
	0x650, //76
	0x7ba, //77
	0x614, //78
	0x47a, //79
	0x53c, //80
	0x4ac, //81
	0x45e, //82
	0x5e4, //83
	0x4f4, //84
	0x4f2, //85
	0x7a4, //86
	0x794, //87
	0x792, //88
	0x6de, //89
	0x6f6, //90
	0x7b6, //91
	0x578, //92
	0x51e, //93
	0x45e, //94
	0x5e8, //95
	0x5e2, //96
	0x7a8, //97
	0x7a2, //98
	0x5de, //99
	0x5ee, //100
	0x75e, //101
	0x7ae, //102
	0x684, //103
	0x690, //104
	0x69c, //105
	0x18eb, //106
};

ZB_S8 ZB_Code128CMakeCode(ZB_U8 *pData, ZB_U8 nInputLen, ZB_U16 *pRes, ZB_U8 nResLen)
{
	ZB_U8 i = 0;
	ZB_U32 verifyBit = 0;

    if(pData == NULL || pRes == NULL)
	{
        return -1;
	}

	if(nInputLen != INPUT_DATA_LEN/2 || nResLen < 3 + INPUT_DATA_LEN/2)
	{
        return -1;
	}

    memset(pRes, 0, nResLen);

	pRes[0] = Code128ListC[StartC];
	verifyBit = StartC;

	for(i = 0; i < INPUT_DATA_LEN/2; i++)
	{
        pRes[i + 1] = Code128ListC[pData[i]];
		verifyBit = verifyBit + (i + 1)*pData[i];
	}
    
	verifyBit = verifyBit % 103; 
	pRes[i + 1] = Code128ListC[verifyBit];
	pRes[i + 2] = Code128ListC[Stop];

	return 0;
}
