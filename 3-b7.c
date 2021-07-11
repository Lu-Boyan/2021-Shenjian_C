/*Èí¼ş 1953609 Íõå°Í¢*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double a;
	int tag = 0;
	printf("ÇëÊäÈë[0,100ÒÚ£©Ö®¼äµÄÊı×Ö:\n");
	scanf("%lf",&a);
	printf("´óĞ´½á¹ûÊÇ£º\n");
	const int a1 = (int)(a / 10);
	const int billion = a1 / 100000000;
	const int hundred_million = a1 / 10000000 % 10;
	const int ten_million = a1 / 1000000 % 10;
	const int million = a1 / 100000 % 10;
	const int hundred_thousand = a1 / 10000 % 10;
	const int ten_thousand = a1 / 1000 % 10;
	const int thousand = a1 / 100 % 10;
	const int hundred = a1 / 10 % 10;
	const int ten = a1 % 10;
	const int yuan = (int)(floor((a / 10.0 - floor(a / 10)) * 10 + 1e-7));
	const int jiao = (int)(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = (int)(round((a - floor(a)) * 100)) % 10;
	if (billion != 0)
	{
		switch (billion)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Ê°");
		if (hundred_million == 0)
			printf("ÒÚ");
	}
	if (hundred_million != 0)
	{
		switch (hundred_million)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("ÒÚ");
	}
	if (ten_million != 0)
	{
		switch (ten_million)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
			default:
				break;
		}
		printf("Çª");
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			printf("Íò");
	}
	else if ((million != 0 || hundred_thousand != 0 || ten_thousand != 0))
		if (hundred_million != 0 || billion != 0)
			printf("Áã");
	if (million != 0)
	{
		switch (million)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("°Û");
		if (hundred_thousand == 0 && ten_thousand == 0)
			printf("Íò");
	}
	else if (ten_million != 0)
		if (hundred_thousand != 0 || ten_thousand != 0)
			printf("Áã");
	if (hundred_thousand != 0)
	{
		switch (hundred_thousand)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Ê°");
		if (ten_thousand == 0)
			printf("Íò");
	}
	else if (million != 0 && ten_thousand != 0)
		printf("Áã");
	if (ten_thousand != 0)
	{
		switch (ten_thousand)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Íò");
	}
	if (thousand != 0)
	{
		switch (thousand)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Çª");
	}
	else if (hundred != 0 || ten != 0 || yuan != 0)
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0)
			printf("Áã");
	if (hundred != 0)
	{
		switch (hundred)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("°Û");
	}
	else if (thousand != 0)
		if (ten != 0 || yuan != 0)
			printf("Áã");
	if (ten != 0)
	{
		switch (ten)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Ê°");
	}
	else if (hundred != 0 && yuan != 0)
		printf("Áã");
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag = 1;
	}
	if (yuan != 0)
	{
		switch (yuan)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("Ô²");
	}
	else if (tag == 1)
	{
		printf("Ô²");
	}
	if (jiao == 0 && fen == 0)
	{
		if (yuan == 0)
		{
			if (billion == 0 && hundred_million == 0 && ten_million == 0)
			{
				if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
				{
					if (thousand == 0 && hundred == 0 && ten == 0)
					{
						printf("ÁãÔ²");
					}
				}
			}
		}
		printf("Õû");
	}
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("½Ç");
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag == 1 || yuan != 0)
			printf("Áã");
	}
	if (fen != 0)
	{
		switch (fen)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			default:
				break;
		}
		printf("·Ö");
	}
	else if (fen == 0 && jiao != 0)
		printf("Õû");
	printf("\n");
	return 0;//3-b7¶ÔÓ¦µÄcpp·½Ê½×÷ÒµµÄ±àÂë¸ñÊ½²»¶Ô
}
//3-b7¶ÔÓ¦µÄcpp·½Ê½×÷ÒµµÄ±àÂë¸ñÊ½²»¶Ô
