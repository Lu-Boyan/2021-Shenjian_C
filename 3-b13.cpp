/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
	int year,month,week;
	int tag=0;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month; 
		if (!cin.good())
		{
			cout << "输入非法, 请重新输入" << endl;
			while (getchar() != '\n')
				;
			cin.clear();
			continue;
		}
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
		{
			while (1)
			{
				cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
				cin >> week;
				if (!cin.good())
				{
					cout << "输入非法, 请重新输入" << endl;
					while (getchar() != '\n')
						;
					cin.clear();
					continue;
				}
				if (week >= 0 && week <= 6)
				{
					cout << endl;
					cout << year << "年" << month << "月的月历为:" << endl;
					cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
						break;
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
						break;
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
						break;
					}
				}
				else
				{
					cout << "输入非法, 请重新输入" << endl;
					continue;
				}
			}
		}
		else
		{
		    cout << "输入非法, 请重新输入" << endl;
			continue;
		}
		break;
	}
	
	return 0;
}


