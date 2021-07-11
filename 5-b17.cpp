/* 1953609 软件 王灏廷 */
#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
    cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)" << endl;
    int len, big, small, num, sym;
    cin >> len >> big >> small >> num >> sym;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "输入含有非法字符." << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (big < 2)
	{
		cout << "大写字母个数[" << big << "]不正确" << endl;
		return 0;
	}
	if (small < 2)
	{
		cout << "小写字母个数[" << small << "]不正确" << endl;
		return 0;
	}
	if (num < 2)
	{
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (sym < 2)
	{
		cout << "其他符号个数[" << sym << "]不正确" << endl;
		return 0;
	}
	if (big + small + num + sym > len)
	{
		cout << "所有字符类型之和[" << big << "+" << small << "+" << num << "+" << sym << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
    cout << len << " " << big << " " << small << " " << num << " " << sym << endl;
    char pw[10][17];
	int  big1=big, small1=small, num1=num, sym1=sym;
	const int sur = len - big - small - num - sym;
	int sur1 = sur;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < len; j++)
		{
			int a = rand() % 94 + 33;
			if (a >= 'A' && a <= 'Z')
			{
				big1--;
				if (big1 < 0)
				{
					big1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}					
				}
			}
			else if (a >= 'a' && a <= 'z')
			{
				small1--;
				if (small1 < 0)
				{
					small1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			else if (a >= '0' && a <= '9')
			{
				num1--;
				if (num1 < 0)
				{
					num1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			else
			{
				sym1--;
				if (sym1 < 0)
				{
					sym1++;
					sur1--;
					if (sur1 < 0)
					{
						j--;
						sur1++;
						continue;
					}
				}
			}
			pw[i][j] = a;
		}
		big1 = big, small1 = small, num1 = num, sym1 = sym,sur1=sur;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << pw[i][j];
		}
		cout << endl;
	}
    return 0;
}