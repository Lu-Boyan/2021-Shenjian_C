/* 1953609 软件 王灏廷 */
#define _CRT_SECURE_NO_WARNINGS
/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <stdio.h>

#define MAX_STU_NUM			150	//约定最大人数为150人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			20	//姓名的最大长度不超过9个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* 给出需要的定义 */

/* 给出stu_list的定义 */
struct stu_list {
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	int condi_fro;
	int condi_aft;
};

/* 给出其它需要的函数的实现 */
int get_sum(const struct stu_list *list)
{
	int sum;
	for (sum=0; list[sum].stu_no != 0; sum++)
		;
	return sum;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：append : 0 : 覆盖方式
					 1 : 追加方式
  返 回 值：
  说    明：
***************************************************************************/
int read_stulist(const char* filename, struct stu_list* list, const int append)
{
	FILE * fin;
	fin = fopen(filename, "r");
	if ((fin = fopen(filename, "r")) == NULL)
	{
		printf("文件[%s]打开失败\n", filename);
		return -1;
	}
	int sum;
	if (append != 0)
	{
		int tag = 0;
		int i = 0;
		sum = get_sum(list);
		for (; tag != 1; i++)
		{
			int a;
			int b;
			b=fscanf(fin,"%d",&a);
			if (b < 1)
				break;
			int seek = 0;
			for (int n = 0; n < sum; n++)
			{
				if (list[n].stu_no == a)
				{
					list[n].condi_aft = 1;
					seek = 1;
					break;
				}
			}
			int j = 0;
			fgetc(fin);
			for (;; j++)
			{
				char ch;
				ch = fgetc(fin);
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					if (seek == 0)
					{
						list[sum].stu_name[j] = ch;
					}
				}
			}
			if (seek == 0)
			{
				list[sum].stu_no = a;
				list[sum].condi_aft = 1;
				list[sum].stu_name[j] = '\0';
				sum++;
			}
		}
	}
	else
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			int b;
			b = fscanf(fin, "%d", &a);
			if (b < 1)
				break;
			list[i].stu_no = a;
			int j = 0;
			fgetc(fin);
			for (;; j++)
			{
				char ch;
				ch = fgetc(fin);
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					list[i].stu_name[j] = ch;
				}
			}
			list[i].stu_name[j] = '\0';
			list[i].condi_fro = 1;
		}
	}
	sum = get_sum(list);
	for (int k = 0; k < sum; k++)
	{
		for (int m = 0; m < sum - k - 1; m++)
		{
			if (list[m].stu_no > list[m + 1].stu_no)//从后面到i个元素两两比较，把小的不断上顶
			{
				struct stu_list tmp;
				tmp = list[m];
				list[m] = list[m + 1];
				list[m + 1] = tmp;
			}
		}
	}
	fclose(fin);
	return 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int print_stulist(const struct stu_list* const list, const char* prompt)
{
	int sum = get_sum(list);
	printf("%s\n", prompt);
	printf("===========================================\n");
	printf("序号 学号    姓名             第一轮 第二轮\n");
	printf("===========================================\n");
	int num = 1;
	for (int i = 0; i < sum; i++, num++)
	{
		printf("%-5d %d %-17s", num, list[i].stu_no, list[i].stu_name);
		if (list[i].condi_fro == 1)
			printf("Y      ");
		else
			printf("/      ");
		if (list[i].condi_aft == 0)
		{
			if (list[i].condi_fro == 1)
				printf("退课\n");
		}
		else
		{
			if (list[i].condi_fro == 1)
				printf("Y\n");
			else
				printf("补选\n");
		}
	}
	printf("===========================================\n");
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	printf("请输入前一轮选课的数据文件 : ");
	scanf("%s", file1);
	printf("请输入后一轮选课的数据文件 : ");
	scanf("%s", file2);

	struct stu_list list[MAX_STU_NUM + 1] = { 0 };

	if (read_stulist(file1, list, 0) < 0)
		return -1;
#if 0
	/* 打开这个宏定义，可以打印首轮读入的选课名单，用于调试 */
	print_stulist(list, "前一轮选课名单");
	printf("\n\n");
#endif

	if (read_stulist(file2, list, 1) < 0)
		return -1;

	print_stulist(list, "最终选课名单");

	return 0;
}
