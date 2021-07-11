/* 1953609 Èí¼ş Íõå°Í¢ */
#include <iostream>
using namespace std;

int main()
{
	while (cin.get() != '\n')
		;
	int len, big, small, num, sym;
	int tag = -1;
	cin >> len >> big >> small >> num >> sym;
	getchar();
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (len < 12 || len>16)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (big < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (small < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (num < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (sym < 2)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	else if (big + small + num + sym > len)
	{
		cout << "´íÎó" << endl;
		return 0;
	}
	char pw[10][17];
	if (tag != 1)
	{
		for (int i = 0; i < 10; i++)
			cin >> pw[i];
	}
	int  big1 = big, small1 = small, num1 = num, sym1 = sym;
	const int sur = len - big - small - num - sym;
	int sur1 = sur;
	if (tag != 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (pw[i][j] >= 'A' && pw[i][j] <= 'Z')
				{
					big1--;
					if (big1 < 0)
					{
						big1++;
						sur1--;
						if (sur1 < 0)
						{
							tag = 0;
							break;
						}
					}
				}
				else if (pw[i][j] >= 'a' && pw[i][j] <= 'z')
				{
					small1--;
					if (small1 < 0)
					{
						small1++;
						sur1--;
						if (sur1 < 0)
						{
							tag = 0;
							break;
						}
					}
				}
				else if (pw[i][j] >= '0' && pw[i][j] <= '9')
				{
					num1--;
					if (num1 < 0)
					{
						num1++;
						sur1--;
						if (sur1 < 0)
						{
							tag = 0;
							break;
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
							tag = 0;
							break;
						}
					}
				}
			}
			big1 = big, small1 = small, num1 = num, sym1 = sym, sur1 = sur;
			if (tag == 0)
			{
				cout << "´íÎó" << endl;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (pw[i][j] >= 'A' && pw[i][j] <= 'Z')
			{
				big1--;
				if (big1 < 0)
				{
					big1++;
					sur1--;
					if (sur1 < 0)
					{
						tag = 0;
						break;
					}
				}
			}
			else if (pw[i][j] >= 'a' && pw[i][j] <= 'z')
			{
				small1--;
				if (small1 < 0)
				{
					small1++;
					sur1--;
					if (sur1 < 0)
					{
						tag = 0;
						break;
					}
				}
			}
			else if (pw[i][j] >= '0' && pw[i][j] <= '9')
			{
				num1--;
				if (num1 < 0)
				{
					num1++;
					sur1--;
					if (sur1 < 0)
					{
						tag = 0;
						break;
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
						tag = 0;
						break;
					}
				}
			}
		}
		big1 = big, small1 = small, num1 = num, sym1 = sym, sur1 = sur;
		if (tag == 0)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
	}
	if (tag == -1)
		cout << "ÕıÈ·" << endl;
	return 0;
}
