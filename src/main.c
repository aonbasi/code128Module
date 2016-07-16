#include <stdio.h>
#include <gd.h>
#include <gdfontl.h>
#include "types.h"
#include "code128.h"

void printCode128C(ZB_U16 *pData, ZB_U8 nLen)
{
	ZB_U8 i = 0;
	for(i = 0; i < nLen; i++)
	{
        printf("0x%x ", pData[i]);
	}
	printf("\n");
}

int paintCode128(ZB_U16 *pData, ZB_U8 nLen, ZB_U8 xScale, ZB_U8 yScale)
{
	int i = 0, j = 0, q = 0;
	int xPos = 1;
	/* Declare the image */
	gdImagePtr im;
	/* Declare output files */
	FILE *pngout;
	/* Declare color indexes */
	int black;
	int white;

	/* 创建100x100的图像，如果需要使用真彩色，
	 *      * 换成 gdImageCreateTrueColor 接口 
	 *           */
	im = gdImageCreate(100, 100);

	/* 黑色作为背景，我这里使用了RGBA模式，也就是有透明的图像，
	 ** 使用宏 gdAlphaTransparent,背景就为透明了。还有就是默认创建的第一层图像即为背景层
	 **/
	white = gdImageColorAllocateAlpha(im, 255, 255, 255, gdAlphaTransparent);  
	/* 创建白色的前景层，这里就不适用Alpha通道了。 */
	black = gdImageColorAllocate(im, 0, 0, 0);  

	for(i = 0; i < nLen; i++)
	{
		if(pData[i] & 0x1000)
		{
			for(q = 0; q < xScale; q++)
			{
                gdImageLine(im, xPos, 10, xPos, 50 * yScale, black);
				xPos++;
			}
		}

		if(pData[i] & 0x0800)
		{
			for(q = 0; q < xScale; q++)
			{
                gdImageLine(im, xPos, 10, xPos, 50 * yScale, black);
				xPos++;
			}
		}

		for(j = 0; j < 11; j++)
		{
			if(pData[i] & 0x0400)
			{
				for(q = 0; q < xScale; q++)
				{
					gdImageLine(im, xPos, 10, xPos, 50 * yScale, black);
				    xPos++;
				}
			}
			else
			{
				xPos = xPos + xScale;
			}
			pData[i] = pData[i] << 1;
		}
	}
	/* 打开文件 */
	pngout = fopen("test.png", "wb");

	/* 不同的图像格式，对应不同的输出函数 
	 *      * PNG -- gdImagePng 
	 *           * Gif -- gdImageGif 
	 *                * Tiff -- gdImageTiff 等，
	 *                     */
	gdImagePng(im, pngout);

	/* Close the files. */
	fclose(pngout);

	/* Destroy the image in memory. */
	gdImageDestroy(im);

	return 0;
}

int main()
{
	ZB_U8 nData[4] = {95, 27, 0, 78};
	ZB_U16 nRes[7];
    ZB_Code128CMakeCode(nData, 4, nRes, 7);	
    printCode128C(nRes, 7);
	paintCode128(nRes, 7, 1, 2);
	return 0;
}
