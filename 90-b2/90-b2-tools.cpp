/*1953609 软件 王灏廷*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include<conio.h>
using namespace std;
int find_max(int moto[][10], int row, int column)//找到数组最大值
{
	int max = -1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (moto[i][j] > max)
				max = moto[i][j];
		}
	}
	return max;
}

int random(int max)//随机值函数
{
	int n;
	switch (max)
	{
		case 3:
			n = (rand() % 3) + 1;;
			return n;
		case 4:
			n = rand() % 10 + 1;
			if (n == 10)
				return 4;
			else
				return n % 3 + 1;
		case 5:
			n = rand() % 20 + 1;
			if (n == 1 || n == 2)
				return 5;
			else if (n == 3 || n == 4 || n == 5)
				return 4;
			else
				return n % 3 + 1;
		case 6:
			n = rand() % 20 + 1;
			if (n == 1)
				return 6;
			else if (n == 3 || n == 4 || n == 5)
				return 5;
			else
				return n % 4 + 1;
		default:
			n = rand() % 20 + 1;
			if (n == 1)
				return max;
			else if (n == 2)
				return max - 1;
			else if (n == 3 || n == 4)
				return max - 2;
			else
				return rand() % (max - 3) + 1;
	}
}
void find_res(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res)//所有找到相邻的相等数字
{
	static int find = 1;
	struct node
	{
		int x;
		int y;
		int tag = 0;
	};
	node a[80];
	a[0].x = x;
	a[0].y = y;
	a[0].tag = 1;
	int final[80] = { 0 };
	int sum = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (moto[i][j] == res)
			{
				a[find].x = i;
				a[find].y = j;
				find++;
			}
		}
	}
	for (int i = 0; i < sum; i++)
	{
		for (int j = 1; j < find; j++)
		{
			if (a[final[i]].x + 1 == a[j].x && a[final[i]].y == a[j].y && a[j].tag == 0)
			{
				final[sum] = j;
				sum++;
				a[j].tag = 1;
			}
			else if (a[final[i]].x - 1 == a[j].x && a[final[i]].y == a[j].y && a[j].tag == 0)
			{
				final[sum] = j;
				sum++;
				a[j].tag = 1;
			}
			else if (a[final[i]].x == a[j].x && a[final[i]].y + 1 == a[j].y && a[j].tag == 0)
			{
				final[sum] = j;
				sum++;
				a[j].tag = 1;
			}
			else if (a[final[i]].x == a[j].x && a[final[i]].y - 1 == a[j].y && a[j].tag == 0)
			{
				final[sum] = j;
				sum++;
				a[j].tag = 1;
			}
		}
	}
	for (int i = 0; i < sum; i++)
	{
		findmoto[a[final[i]].x][a[final[i]].y] = 1;
	}
}
void find_res_rec(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res)
{
	if (x < 0 || y < 0 || x >= row || y >= column)
		return;
	static int num = 1;
	if (x > 0)
		if (moto[x - 1][y] == res && !findmoto[x - 1][y])
		{
			num++;
			findmoto[x - 1][y] = 1;
			find_res_rec(moto, row, column, findmoto, x - 1, y, res);
		}
	if (y > 0)
		if (moto[x][y - 1] == res && !findmoto[x][y - 1])
		{
			num++;
			findmoto[x][y - 1] = 1;
			find_res_rec(moto, row, column, findmoto, x, y - 1, res);
		}
	if (x < row - 1)
		if (moto[x + 1][y] == res && !findmoto[x + 1][y])
		{
			num++;
			findmoto[x + 1][y] = 1;
			find_res_rec(moto, row, column, findmoto, x + 1, y, res);
		}
	if (y < column - 1)
		if (moto[x][y + 1] == res && !findmoto[x][y + 1])
		{
			num++;
			findmoto[x][y + 1] = 1;
			find_res_rec(moto, row, column, findmoto, x, y + 1, res);
		}
}
int merge_res(int moto[][10], int row, int column, int findmoto[][10], int x, int y)
{
	int merge_sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (findmoto[i][j] == 1)
				if (i == x && j == y)
					moto[i][j]++;
				else
				{
					moto[i][j] = 0;
					merge_sum++;
				}
		}
	}
	return merge_sum + 1;
}
int judge_merge(int moto[][10], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i >= 1)
			{
				if (moto[i][j] == moto[i - 1][j])
					continue;
			}
			if (j >= 1)
			{
				if (moto[i][j] == moto[i][j - 1])
					continue;
			}
			if (i < row - 1)
			{
				if (moto[i][j] == moto[i + 1][j])
					continue;
			}
			if (j < column - 1)
			{
				if (moto[i][j] == moto[i][j + 1])
					continue;
			}
			else
				return 0;
		}
	}
	return 1;
}
int judge_adjoin(int moto[][10], int row, int column, int x, int y)
{
	if (x >= 1)
	{
		if (moto[x][y] == moto[x - 1][y])
			return 1;
	}
	if (y >= 1)
	{
		if (moto[x][y] == moto[x][y - 1])
			return 1;
	}
	if (x < row - 1)
	{
		if (moto[x][y] == moto[x + 1][y])
			return 1;
	}
	if (y < column - 1)
	{
		if (moto[x][y] == moto[x][y + 1])
			return 1;
	}
	return 0;
}
int score(int res, int merge_sum)
{
	return res * merge_sum * 3;
}
void down_arr(int moto[][10], int row, int column)
{
	for (int i = 0; i < column; i++)
	{
		for (int j = row - 2; j >= 0; j--)
		{
			if (moto[j + 1][i] == 0 && moto[j][i] != 0)
			{
				moto[j + 1][i] = moto[j][i];
				moto[j][i] = 0;
				for (int k = j + 1; k < row - 1; k++)
				{
					if (moto[k + 1][i] == 0 && moto[k][i] != 0)
					{
						moto[k + 1][i] = moto[k][i];
						moto[k][i] = 0;
					}
				}
			}
		}
	}
}
void set_arr(int moto[][10], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			moto[i][j] = random(3);
		}
	}
}
void set_zero(int moto[][10], int row, int column)
{
	int max = find_max(moto, row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (moto[i][j] == 0)
				moto[i][j] = random(max);
		}
	}
}
void end(int column)
{
	cout << endl << "本小题结束，请输入End继续...";
	while (1)
	{
		char ch[3];
		for (int i = 0; i < 3; i++)
		{
			ch[i] = getchar();
			if (ch[i] >= 'a' && ch[i] <= 'z')
				ch[i] -= 32;
		}
		if (!cin.good() || ch[0] != 'E' || ch[1] != 'N' || ch[2] != 'D')
		{
			cout << "输入不合法，请重新输入" << endl;
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			break;
		}
	}
}