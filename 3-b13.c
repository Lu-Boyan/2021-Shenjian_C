/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, week;
	int tag = 0;
	int a = 0;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		a=scanf("%d %d",&year,&month);
		if (a <2)
		{
			printf("输入非法 ，请重新输入\n");
			while (getchar() != '\n')
				;
			continue;
		}
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
		{
			while (1)
			{
				printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
				a=scanf("%d", &week);
				if (a <= 0)
				{
					printf("输入非法 ，请重新输入\n");
					while (getchar() != '\n')
						;
					continue;
				}
				if (week >= 0 && week <= 6)
				{
					printf("\n");
					printf("%d年%d月的月历为:\n", year, month);
					printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
					switch (week)
					{
						case 0:
							printf("%4d", 1);
							printf("%8d", 2);
							printf("%8d", 3);
							printf("%8d", 4);
							printf("%8d", 5);
							printf("%8d", 6);
							printf("%8d", 7);
							tag = 8;
							break;
						case 1:
							printf("%12d", 1);
							printf("%8d", 2);
							printf("%8d", 3);
							printf("%8d", 4);
							printf("%8d", 5);
							printf("%8d", 6);
							tag = 7;
							break;
						case 2:
							printf("%20d", 1);
							printf("%8d", 2);
							printf("%8d", 3);
							printf("%8d", 4);
							printf("%8d", 5);
							tag = 6;
							break;
						case 3:
							printf("%28d", 1);
							printf("%8d", 2);
							printf("%8d", 3);
							printf("%8d", 4);
							tag = 5;
							break;
						case 4:
							printf("%36d", 1);
							printf("%8d", 2);
							printf("%8d", 3);
							tag = 4;
							break;
						case 5:
							printf("%44d", 1);
							printf("%8d", 2);
							tag = 3;
							break;
						case 6:
							printf("%52d", 1);
							tag = 2;
							break;
						default:
							break;
					}
					if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
					{
						for (int i = tag; i <= 31; i++)
						{
							if ((i - tag) % 7 != 0)
								printf("%8d", i);
							else
								printf("\n%4d", i);
						}
						printf("\n");
						break;
					}
					else if (month == 4 || month == 6 || month == 9 || month == 11)
					{
						for (int i = tag; i <= 30; i++)
						{
							if ((i - tag) % 7 != 0)
								printf("%8d", i);
							else
								printf("\n%4d", i);
						}
						printf("\n");
						break;
					}
					else if (month == 2)
					{
						if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
							for (int i = tag; i <= 29; i++)
							{
								if ((i - tag) % 7 != 0)
									printf("%8d", i);
								else
									printf("\n%4d", i);
							}
						else
							for (int i = tag; i <= 28; i++)
							{
								if ((i - tag) % 7 != 0)
									printf("%8d", i);
								else
									printf("\n%4d", i);
							}
						printf("\n");
						break;
					}
				}
				else
				{
				    printf("输入非法 ，请重新输入\n");
					continue;
				}
			}
		}
		else
		{
		    printf("输入非法 ，请重新输入\n");
			continue;
		}
		break;
	}

	return 0;
}



