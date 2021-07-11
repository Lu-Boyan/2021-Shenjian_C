/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int zeller(int y, int m, int d)
{
	int week, century;
	int w;
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	century = y / 100;
	y = y % 100;
	week = y + y / 4 + century / 4 - 2 * century + (13 * (m + 1) / 5) + d - 1;
	while (week < 0)
		week += 7;
	w = week % 7;
	return w;
}
void calendar(int year, int month, int week)
{
	int tag = 0;
	cout << endl << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	switch (week)
	{
		case 0:
			cout << setw(4) << "1";
			cout << setw(8) << "2";
			cout << setw(8) << "3";
			cout << setw(8) << "4";
			cout << setw(8) << "5";
			cout << setw(8) << "6";
			cout << setw(8) << "7";
			tag = 8;
			break;
		case 1:
			cout << setw(12) << "1";
			cout << setw(8) << "2";
			cout << setw(8) << "3";
			cout << setw(8) << "4";
			cout << setw(8) << "5";
			cout << setw(8) << "6";
			tag = 7;
			break;
		case 2:
			cout << setw(20) << "1";
			cout << setw(8) << "2";
			cout << setw(8) << "3";
			cout << setw(8) << "4";
			cout << setw(8) << "5";
			tag = 6;
			break;
		case 3:
			cout << setw(28) << "1";
			cout << setw(8) << "2";
			cout << setw(8) << "3";
			cout << setw(8) << "4";
			tag = 5;
			break;
		case 4:
			cout << setw(36) << "1";
			cout << setw(8) << "2";
			cout << setw(8) << "3";
			tag = 4;
			break;
		case 5:
			cout << setw(44) << "1";
			cout << setw(8) << "2";
			tag = 3;
			break;
		case 6:
			cout << setw(52) << "1";
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
				cout << setw(8) << i;
			else
				cout << endl << setw(4) << i;
		}
		cout << endl;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		for (int i = tag; i <= 30; i++)
		{
			if ((i - tag) % 7 != 0)
				cout << setw(8) << i;
			else
				cout << endl << setw(4) << i;
		}
		cout << endl;
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			for (int i = tag; i <= 29; i++)
			{
				if ((i - tag) % 7 != 0)
					cout << setw(8) << i;
				else
					cout << endl << setw(4) << i;
			}
		else
			for (int i = tag; i <= 28; i++)
			{
				if ((i - tag) % 7 != 0)
					cout << setw(8) << i;
				else
					cout << endl << setw(4) << i;
			}
		cout << endl;
	}
}
int main()
{
	int week, year, month;
	while (1)
	{
		cout << "请输入年[1900-2100]、月：" << endl;
		cin >> year >> month;
		if (!cin.good())
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year> 2100)
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		week = zeller(year, month, 1);
		calendar(year, month, week);
		break;
	}
	return 0;
}

