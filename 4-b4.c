/*1953609 软件 王灏廷*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu()
{
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界停止\n");
	printf("6.用I、J、K、L键控制上下左右(按左箭头键不向下移动，大小写均可，边界停止\n");
	printf("0.退出\n[请选择0-6] ");
	//在循环中，若只检查ijkl的ASCII码，而不对224进行特殊处理
    //左方向键的224+75会在忽略224以后被当成K处理
	int input;
	while (1)
	{
		input = _getch();
		if (input <= '6' && input >= '0')
			break;
	}
	return input;
}
void move_by_ijkl(int u, int d, int l, int r, int tag_huirao, int five_six)
{
	int input;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	while (1)
	{
		input = _getch();
		if (five_six == 1)
			if (input == 224)
				_getch();
		if (tag_huirao == 0)
		{
			if (input == u || input == u - 32)
			{
				if (y == 1)
					y = 2;
				gotoxy(hout, x, --y);
			}
			if (input == d || input == d - 32)
			{
				if (y == 17)
					y = 16;
				gotoxy(hout, x, ++y);
			}
			if (input == l || input == l - 32)
			{
				if (x == 1)
					x = 2;
				gotoxy(hout, --x, y);
			}
			if (input == r || input == r - 32)
			{
				if (x == 69)
					x = 68;
				gotoxy(hout, ++x, y);
			}
		}
		else
		{
			if (input == u || input == u - 32)
			{
				if (y == 1)
					y = 18;
				gotoxy(hout, x, --y);
			}
			if (input == d || input == d - 32)
			{
				if (y == 17)
					y = 0;
				gotoxy(hout, x, ++y);
			}
			if (input == l || input == l - 32)
			{
				if (x == 1)
					x = 70;
				gotoxy(hout, --x, y);
			}
			if (input == r || input == r - 32)
			{
				if (x == 69)
					x = 0;
				gotoxy(hout, ++x, y);
			}
		}
		if (input == ' ')
			printf(" \b");
		if (input == 'q' || input == 'q' - 32)
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.\n");
			while (1)
			{
				input = _getch();
				if (input == 13)
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}
void move_by_arrow(int u, int d, int l, int r, int tag_huirao)
{
	//在循环中，若只检查ijkl的ASCII码，而不对224进行特殊处理
    //左方向键的224+75会在忽略224以后被当成K处理
	int input;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	init_border(hout);
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	while (1)
	{
		input = _getch();
		if (input == 224)
		{
			input = _getch();
			if (tag_huirao == 0)
			{
				if (input == u || input == u - 32)
				{
					if (y == 1)
						y = 2;
					gotoxy(hout, x, --y);
				}
				if (input == d || input == d - 32)
				{
					if (y == 17)
						y = 16;
					gotoxy(hout, x, ++y);
				}
				if (input == l || input == l - 32)
				{
					if (x == 1)
						x = 2;
					gotoxy(hout, --x, y);
				}
				if (input == r || input == r - 32)
				{
					if (x == 69)
						x = 68;
					gotoxy(hout, ++x, y);
				}
			}
			else
			{
				if (input == u || input == u - 32)
				{
					if (y == 1)
						y = 18;
					gotoxy(hout, x, --y);
				}
				if (input == d || input == d - 32)
				{
					if (y == 17)
						y = 0;
					gotoxy(hout, x, ++y);
				}
				if (input == l || input == l - 32)
				{
					if (x == 1)
						x = 70;
					gotoxy(hout, --x, y);
				}
				if (input == r || input == r - 32)
				{
					if (x == 69)
						x = 0;
					gotoxy(hout, ++x, y);
				}
			}
		}
		if (input == ' ')
			printf(" \b");
		if (input == 'q' || input == 'q' - 32)
		{
			gotoxy(hout, 0, 23);
			printf("游戏结束，按回车键返回菜单.\n");
			while (1)
			{
				input = _getch();
				if (input == 13)
				{
					cls(hout);
					gotoxy(hout, 0, 0);
					return;
				}
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	int input;
	while (1)
	{
		input = menu();
		switch (input)
		{
			case '0':
				return 0;
				break;
			case '1':
				move_by_ijkl('i', 'k', 'j', 'l', 0, 0);
				break;
			case '2':
				move_by_ijkl('i', 'k', 'j', 'l', 1, 0);
				break;
			case  '3':
				move_by_arrow(72, 80, 75, 77, 0);
				break;
			case '4':
				move_by_arrow(72, 80, 75, 77, 1);
				break;
			case '5':
				move_by_ijkl('i', 'k', 'j', 'l', 0, 1);
				break;
			case '6':
				move_by_ijkl('i', 'k', 'j', 'l', 1, 1);
				break;
			default:
				break;
		}
	}
	return 0;
}
//const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
//srand((unsigned int)(time(0)));

/* 此句的作用是调用系统的cls命令清屏 */
//cls(hout);

/* 显示初始的边框及其中的随机字符 */
//init_border(hout);

//暂停
//getchar();

//gotoxy(hout, 0, 23);
//printf("游戏结束，按回车键退出.\n");

//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
//getchar();
