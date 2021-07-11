/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int tag;
	while (1) {
		printf("请输入x的值[0-100] : ");
		tag=scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (tag<=0)
		{
			while (getchar() != '\n')
				;
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	printf("x=%d\n", x);

	return 0;
}
