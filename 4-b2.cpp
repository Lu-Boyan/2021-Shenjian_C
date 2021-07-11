/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int zeller(int y, int m, int d)
{
	int week,century;
	int w;
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	century = y / 100;
	y = y % 100;
	week = y + y / 4 + century / 4 - 2 * century +(13 * (m + 1) / 5) + d - 1;
	while (week < 0)
		week += 7;
	w = week % 7;
	return w;
}
int main()
{  
    int week, year, month,day;
	while (1) 
	{
		cout << "请输入年[1900-2100]、月、日："<<endl;
		cin >> year >> month >> day;
		if (!cin.good())
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year<1900||year> 2100)
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
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day>31)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day>30)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		else if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day < 1 || day>29)
				{
					while (getchar() != '\n')
						;
					cin.clear();
					cout << "日不正确，请重新输入" << endl;
					continue;
				}
			}
			else if (day < 1 || day>28)
			{
				while (getchar() != '\n')
					;
				cin.clear();
				cout << "日不正确，请重新输入" << endl;
				continue;
			}
		}
		week=zeller(year, month, day);
		switch (week)
		{
			case 0:
				cout << "星期日" << endl;
				break;
			case 1:
				cout << "星期一" << endl;
				break;
			case 2:
				cout << "星期二" << endl;
				break;
			case 3:
				cout << "星期三" << endl;
				break;
			case 4:
				cout << "星期四" << endl;
				break;
			case 5:
				cout << "星期五" << endl;
				break;
			case 6:
				cout << "星期六" << endl;
				break;
			default:
				break;
		}
		break;
	}
	return 0;
}
