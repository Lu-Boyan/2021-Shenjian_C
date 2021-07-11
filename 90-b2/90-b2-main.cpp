/*1953609 软件 王灏廷*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include<iostream>
#include<conio.h>
using namespace std;

char menu()
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_cls();
	cout << "-----------------------------------" << endl
		<< "1.命令行找出可合成项并标识（非递归）" << endl
		<< "2.命令行找出可合成项并标识（递归）" << endl
		<< "3.命令行完成一次合成（分步骤显示）" << endl
		<< "4.命令行完整版（分步骤显示）" << endl
		<< "5.伪图形界面显示初始数组（无分隔线）" << endl
		<< "6.伪图形界面显示初始数组（有分隔线）" << endl
		<< "7.伪图形界面下用箭头键选择当前色块" << endl
		<< "8.伪图形界面完成一次合成（分步骤）" << endl
		<< "9.伪图形界面完整版" << endl
		<< "0.退出" << endl
		<< "-----------------------------------" << endl
		<< "[请选择0-9] ";
	while (1)
	{
		const char num = _getch();
		if (num < '0' || num>'9')
		{
			cin.clear();
			continue;
		}
		return num;
	}
}
int main()
{

	while (1)
	{
		time_t t;
		srand((unsigned)time(&t));
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_cls();
		const int select = menu();
		switch (select)  //输入参数 根据输入分别处理
		{
			case '0':
				cout << endl;
				return 0;
			case '1':
				initial(select);
				break;
			case '2':
				initial(select);
				break;
			case '3':
				initial(select);
				break;
			case '4':
				initial(select);
				break;
			case '5':
				initial_graph(select);
				break;
			case '6':
				initial_graph(select);
				break;
			case '7':
				initial_graph(select);
				break;
			case '8':
				initial_graph(select);
			case '9':
				initial_graph(select);
				break;
			default:
				break;
		}
	}
	return 0;
}