/* 1953609 软件 王灏廷 */
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
struct KFC
{
	char type;
	char food[20];
	double price;
};

struct SPECIAL
{
	char type[20];
	char food[21];
	double price;
};
int main()
{
	const struct KFC list[] =
	{
	{'A', "香辣鸡腿堡",         18},
	{'B', "劲脆鸡腿堡",         18},
	{'C', "新奥尔良烤鸡腿堡",   18.5},
	{'D', "鸡肉火腿帕尼尼",   14.0},
	{'E', "老北京鸡肉卷",       16.5},
	{'F', "川辣嫩牛卷",     19},
	{'G', "吮指原味鸡(1块)",   11.5},
	{'H', "热辣薯片脆皮鸡",   12.5},
	{'I', "新奥尔良烤翅(2块)", 12},
	{'J', "劲爆鸡米花",         10.5},
	{'K', "香辣鸡翅(2块)",     11.0},
	{'L', "热辣香骨鸡(3块)",     11.0},
	{'M', "鲜蔬色拉",           12.5},
	{'N', "薯条(小)",           8},
	{'O', "薯条(中)",           11},
	{'P', "薯条(大)",           13},
	{'Q', "芙蓉蔬荟汤",         8},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         6.5},
	{'T', "香甜粟米棒",         8.0},
	{'U', "葡式蛋挞",           7.5},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.0},
	{'Z', "纯纯玉米饮",         11.0},
	{'\0', NULL,                0}
	};
	const struct SPECIAL special[] = 
	{
		//	{"ANV", "香辣鸡腿堡工作日午餐",    22}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
			{"BMV", "劲脆鸡腿堡超值套餐",    24},
			{"ABCGGIIKKOUWWW", "超值全家桶", 100},
			{"KIIRRJUWW", "缤纷小吃桶",  65},
			{"JJ","劲爆鸡米花(2份小)",      9.5},
			{NULL, NULL, 0}
	};
	int discount[5][26] = { 0 };
	for (int i = 0; special[i].price != 0; i++)
	{
		for (unsigned int j = 0; j < strlen(special[i].type); j++)
		{
			if (special[i].type[j] - 'A' >= 0)
				discount[i][special[i].type[j] - 'A']++;
		}
	}
	while (1)
	{
		int tag = 0;
		double cost = 0;
		char order[100] = { '0' };
		int charge[27] = { 0 };
		int location = 0;
		system("mode con cols=120 lines=35");
		cout << "=============================================================" << endl;
		cout << "                      KFC 2021春季菜单                       " << endl;
		cout << "=============================================================" << endl;
		for (int i = 0; list[i].price != 0; i++)
		{
			cout << setw(2) << list[i].type << " " << setiosflags(ios::left) << setw(20) << list[i].food << setw(8) << list[i].price;
			if ((i + 1) % 2 == 0)
				cout << endl;
			else
				cout << setw(2) << "|";
			cout << resetiosflags(ios::left);
		}
		cout << endl;
		cout << "【优惠信息】：" << endl;
		for (int i = 0; special[i].price != 0; i++)
		{
			cout << special[i].food << "=";
			for (unsigned int j = 0; j < strlen(special[i].type); j++)
			{
				for (int k = 0; k < 26; k++)
				{
					if (special[i].type[j] == list[k].type)
					{
						cout << list[k].food;
						if (discount[i][special[i].type[j] - 'A'] > 1)
						{
							cout << "*" << discount[i][special[i].type[j] - 'A'];
							j += discount[i][special[i].type[j] - 'A'] - 1;
						}
						if (j < strlen(special[i].type) - 1)
							cout << "+";
						else
						{
							cout << "=";
							break;
						}
					}
				}
			}
			cout << special[i].price << endl;
		}
		cout << endl;
		cout << "【输入规则说明】：" << endl
			<< "ANV = 香辣鸡腿堡 + 薯条(小) + 百事可乐(小) / akaak = 香辣鸡腿堡 * 3 + 香辣鸡翅 * 2" << endl
			<< "字母不分大小写，不限顺序，单独输入0则退出程序" << endl << endl;
		cout << "请点单：";
		for (unsigned int i = 0;; i++)
		{
			order[i] = getchar();
			if (order[i] == '\n')
				break;
			if (order[0] == '0'&& getchar()== '\n')
			{
				tag = 2;
				break;
			}
			if (order[i] >= 'a' && order[i] <= 'z')
				order[i] -= 32;
			else if (order[i] < 'A' || order[i] > 'Z' || !cin.good())
			{
				cout << "输入错误，按任意键继续." << endl;
				tag = 1;
				break;
			}
		}
		if (tag == 1)
		{
			while (getchar() !='\n' );
			_getch();
			system("cls");
			continue;
		}
		else if (tag == 2)
			break;
		for (unsigned int i = 0; i < strlen(order); i++)
		{
			if (order[i] - 'A' >= 0)
				charge[order[i] - 'A']++;
		}
		for (int i = 26; i >= 0; i--)
		{
			if (charge[i] != 0)
			{
				location = i;
				break;
			}
		}
		cout << "您的点餐=";
		for (unsigned int i = 0; list[i].price != 0; i++)
		{
			if (charge[i] != 0)
			{
				cout << list[i].food;
				if (charge[i] > 1)
					cout << "*" << charge[i];
				if (i != location)
					cout << "+";
				else
					cout << endl;
			}
		}
		for (int i = 0; special[i].price != 0; i++)
		{
			int sum = 99999;
			tag = 0;
			for (unsigned int j = 0; j < 26; j++)
			{
				if (discount[i][j] != 0)
					if (charge[j] >= discount[i][j] && charge[j] != 0)
					{
						if (charge[j] / discount[i][j] < sum)
							sum = charge[j] / discount[i][j];
					}
					else
					{
						tag = 3;
						break;
					}
			}
			if (sum != 99999 && tag != 3)
			{
				cost += special[i].price * sum;
				for (unsigned int j = 0; j < 26; j++)
				{
					if (discount[i][j] != 0)
						charge[j] -= discount[i][j] * sum;
				}
			}
		}
		for (int i = 0; i <= location; i++)
		{
			if (charge[i] > 0)
				cost += charge[i] * list[i].price;
		}
		cout << "共计：" << cost << "元" << endl;
		cout << "点单完成，按任意键继续." << endl;
		_getch();
		system("cls");
    }
	return 0;
}