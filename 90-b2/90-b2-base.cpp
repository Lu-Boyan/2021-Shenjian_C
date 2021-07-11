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
void print_moto(int moto[][10], int row, int column)//打印数组
{
	cout << "当前数组：" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			cout << setw(3) << moto[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int cmd_opr(int moto[][10], int row, int column, int findmoto[][10], int x, int y, int res, int target, int score_sum)
{
	cout << "请确认是否把相邻的相同值合并到C2中(Y/N/Q)：";
	char cmd;
	while (1)
	{
		cmd = _getch();
		if (cmd == 'y' || cmd == 'Y')
		{
			cout << "y" << endl << endl;
			cout << "相同值归并后的数组(不同色标识)：" << endl;
			int merge_sum = merge_res(moto, row, column, findmoto, x, y);
			print_res(moto, row, column, findmoto, 0);
			int score_cur = score(res, merge_sum);
			score_sum += score_cur;
			cout << endl << "本次得分：" << score_cur << " 总得分：" << score_sum << " 合成目标：" << target << endl;
			print_removeZero(moto, row, column, findmoto);
			break;
		}
		else if (cmd == 'n' || cmd == 'N')
		{
			cout << "n" << endl << endl;
			return score_sum;
		}
		else if (cmd == 'q' || cmd == 'Q')
		{
			cout << "q" << endl << endl;
			return -1;
		}
	}
	return score_sum;
}
void print_removeZero(int moto[][10], int row, int column, int findmoto[][10])
{
	cout << endl << "按回车键进行数组下落除0操作..." << endl;
	int cmd;
	while (1)
	{
		cmd = _getch();
		if (cmd == 13)
		{
			break;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			findmoto[i][j] = 0;
		}
	}
	down_arr(moto, row, column);
	cout << "除0后的数组(不同色标识)：" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (moto[i][j] != 0)
				cout << setw(3) << moto[i][j];
			else
			{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				findmoto[i][j] = 1;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
	cout << endl << "按回车键进行新值填充..." << endl;
	int cmd2;
	while (1)
	{
		cmd2 = _getch();
		if (cmd2 == 13)
		{
			break;
		}
	}
	set_zero(moto, row, column);
	cout << "新值填充后的数组(不同色标识)：" << endl;
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (findmoto[i][j] == 0)
				cout << setw(3) << moto[i][j];
			else
			{
				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				findmoto[i][j] = 0;
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
	cout << endl << "本次合成结束，按回车键继续新一次的合成..." << endl;
	int cmd3;
	while (1)
	{
		cmd3 = _getch();
		if (cmd3 == 13)
		{
			break;
		}
	}
}
void print_res(int moto[][10], int row, int column, int findmoto[][10], int tag)
{
	if (tag == 1)
	{
		cout << "查找结果数组：" << endl;
		cout << "  |";
		for (int i = 0; i < column; i++)
			cout << setw(3) << i;
		cout << endl << "--+";
		for (int i = 0; i < 3 * column; i++)
			cout << "-";
		cout << "-" << endl;
		for (int i = 0; i < row; i++)
		{
			cout << char(i + 'A') << " |";
			for (int j = 0; j < column; j++)
			{
				if (findmoto[i][j] == 0)
					cout << setw(3) << findmoto[i][j];
				else
					cout << setw(3) << "*";
			}
			cout << endl;
		}
		cout << endl << endl << "当前数组(不同色标识)：" << endl;
	}
	cout << "  |";
	for (int i = 0; i < column; i++)
		cout << setw(3) << i;
	cout << endl << "--+";
	for (int i = 0; i < 3 * column; i++)
		cout << "-";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < column; j++)
		{
			if (findmoto[i][j] == 0)
				cout << setw(3) << moto[i][j];
			else
			{

				int x, y;
				cct_getxy(x, y);
				cct_showint(x, y, 0, COLOR_BLACK, COLOR_BLACK, 2);
				cct_showint(x + 2, y, moto[i][j], COLOR_BLACK, COLOR_HYELLOW);
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
}

void initial(char sign)
{
	int row, column;
	cct_cls();
	cout << "请输入行数(5-8)：";
	while (1)
	{
		cin >> row;
		if (!cin.good() || row > 8 || row < 5)
		{
			cout << "输入不合法，请重新输入";
			cct_showch(17, 0, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(17, 0);
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
	cout << "请输入列数(5-10)：";
	while (1)
	{
		cin >> column;
		if (!cin.good() || column > 10 || column < 5)
		{
			cout << "输入不合法，请重新输入";
			cct_showch(18, 1, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(18, 1);
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
	int target;
	if (sign == '3' || sign == '4')
	{
		cout << "请输入合成目标(5-20)：";
		while (1)
		{
			cin >> target;
			if (!cin.good() || target > 20 || target < 5)
			{
				cout << "输入不合法，请重新输入";
				cct_showch(21, 2, 0, 0, 0, 10);
				cct_setcolor(0, 7);
				cct_gotoxy(21, 2);
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
	cct_gotoxy(0, 4);
	int moto[8][10] = { 0 };
	set_arr(moto, row, column);
	print_moto(moto, row, column);
	char matx;
	int maty;
	while (1)
	{
		cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		cin >> matx >> maty;
		if (matx >= 'a' && matx <= 'z')
			matx -= 32;
		if (!cin.good() || maty > column || maty < 0 || matx<'A' || matx>char(row + 'A'))
		{
			cout << "输入不合法，请重新输入";
			cct_showch(38, 5 + column, 0, 0, 0, 10);
			cct_setcolor(0, 7);
			cct_gotoxy(38, 5 + column);
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
		}
		cout << "输入为" << matx << "行" << maty << "列" << endl << endl;
		int jud_adjoin;
		jud_adjoin = judge_adjoin(moto, row, column, matx - 'A', maty);
		if (jud_adjoin == 1)
			break;
		else
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
	}
	int findmoto[8][10] = { 0 };
	int res = moto[matx - 'A'][maty];
	findmoto[matx - 'A'][maty] = 1;
	if (sign == '1')
	{
		find_res(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
	}
	else if (sign == '2')
	{
		find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
	}
	else if (sign == '3')
	{
		find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
		print_res(moto, row, column, findmoto, 1);
		int score_sum = 0;
		score_sum += cmd_opr(moto, row, column, findmoto, matx - 'A', maty, res, target, score_sum);
	}
	else if (sign == '4')
	{
		int score_sum = 0;
		int tag_four = 0;
		while (1)
		{
			if (tag_four == 1)
				print_moto(moto, row, column);
			while (tag_four == 1)
			{
				cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
				cin >> matx >> maty;
				if (matx >= 'a' && matx <= 'z')
					matx -= 32;
				if (!cin.good() || maty > column || maty < 0 || matx<'A' || matx>char(row + 'A'))
				{
					cout << "输入不合法，请重新输入";
					cct_showch(38, 5 + column, 0, 0, 0, 10);
					cct_setcolor(0, 7);
					cct_gotoxy(38, 5 + column);
					cin.clear();
					cin.ignore(2147483647, '\n');
					continue;
				}
				else
				{
					cin.clear();
					cin.ignore(2147483647, '\n');
				}
				cout << "输入为" << matx << "行" << maty << "列" << endl << endl;
				int jud_adjoin;
				jud_adjoin = judge_adjoin(moto, row, column, matx - 'A', maty);
				if (jud_adjoin == 1)
				{
					tag_four++;
					break;
				}
				else
					cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < column; j++)
				{
					findmoto[i][j] = 0;
				}
			}
			res = moto[matx - 'A'][maty];
			findmoto[matx - 'A'][maty] = 1;
			find_res_rec(moto, row, column, findmoto, matx - 'A', maty, res);
			print_res(moto, row, column, findmoto, 1);
			int score_cur = cmd_opr(moto, row, column, findmoto, matx - 'A', maty, res, target, score_sum);
			tag_four = 1;
			if (score_cur == -1)
				break;
			else
				score_sum += score_cur;
			if (find_max(moto, row, column) >= target)
			{
				int x, y;
				cct_getxy(x, y);
				cct_showstr(x, y, "已经合成到", COLOR_HYELLOW, COLOR_HRED);
				cct_showint(x + 10, y, target, COLOR_HYELLOW, COLOR_HRED);
				cct_setcolor(0, 7);
				cout << endl << "按回车键继续向更高目标进发..." << endl;
				int cmd;
				while (1)
				{
					cmd = _getch();
					if (cmd == 13)
					{
						break;
					}
				}
				target++;
			}
		}
	}
	end(column);
	return;
}