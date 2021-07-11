/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include"hanoi.h"
#include<conio.h>
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int num = 1;
int topa = 0, topb = 0, topc = 0;
static int moving = 5;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_disk()
{
    for (int i = 0; i < 3; i++)
    {
        cct_showch(2 + 30 * i, 17, 0, 14, 14, 25);
    }
    for (int j = 0; j < 15; j++)
    {
        cct_showch(14, 17 - j, 0, 14, 14, 1);
        cct_showch(44, 17 - j, 0, 14, 14, 1);
        cct_showch(74, 17 - j, 0, 14, 14, 1);
        Sleep(50);
    }
    cct_gotoxy(0, 35);
    cct_setcolor(0, 7);
}
void print_disk_ini(char src,int sum)
{
    int sum1 = sum;
    if (src == 'A')
    {
        for (int i = 0; i < sum; i++)
        {
            cct_showch(14 - sum1, 16 - i, 0, sum1, sum1, sum1 * 2 + 1);
            Sleep(50);
            sum1--;
        }
    }
    else if (src == 'B')
    {
        for (int i = 0; i < sum; i++)
        {
            cct_showch(44 - sum1, 16 - i, 0, sum1, sum1, sum1 * 2 + 1);
            Sleep(50);
            sum1--;
        }
    }
    else if (src == 'C')
    {
        for (int i = 0; i < sum; i++)
        {
            cct_showch(74 - sum1, 16 - i, 0, sum1, sum1, sum1 * 2 + 1);
            Sleep(50);
            sum1--;
        }
    }
    cct_gotoxy(0, 35);
    cct_setcolor(0, 7);
}
void disk_move(int n, char src,char dst, char sign)
{
    cct_setcursor(CURSOR_INVISIBLE);
    if (src == 'A')
    {
        for (int i = 0; i+ topa<15; i++)
        {
            cct_showch(14- A[topa - 1], 17 - topa-i, 0, COLOR_BLACK, COLOR_BLACK, A[topa-1] * 2 + 1);
            cct_showch(14, 17 - topa-i, 0, 14, 14, 1);
            cct_showch(14 - A[topa - 1], 16 - topa-i, 0, A[topa - 1], A[topa - 1], A[topa - 1] * 2 + 1);
            Sleep((6-moving)*30);
        }
        if (dst == 'C')
        {
            for (int i = 0; i < 60; i++)
            {
                cct_showch(14 - A[topa - 1] + i, 2, 0, COLOR_BLACK, COLOR_BLACK, A[topa - 1] * 2 + 1);
                cct_showch(14 - A[topa - 1] + 1 + i, 2, 0, A[topa - 1], A[topa - 1], A[topa - 1] * 2 + 1);
                Sleep((6 - moving) * 30);
            }
            for (int i = 0; i < 14-topc; i++)
            {
                cct_showch(74 - A[topa - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, A[topa - 1] * 2 + 1);
                cct_showch(74 - A[topa - 1], 2 + i + 1, 0, A[topa - 1], A[topa - 1], A[topa - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(74, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
        else if (dst == 'B')
        {
            for (int i = 0; i < 30; i++)
            {
                cct_showch(14 - A[topa - 1] + i, 2, 0, COLOR_BLACK, COLOR_BLACK, A[topa - 1] * 2 + 1);
                cct_showch(14 - A[topa - 1] + 1 + i, 2, 0, A[topa - 1], A[topa - 1], A[topa - 1] * 2 + 1);
                Sleep((6-moving)*30);
            }
            for (int i = 0; i < 14-topb; i++)
            {
                cct_showch(44 - A[topa - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, A[topa - 1] * 2 + 1);
                cct_showch(44 - A[topa - 1], 2 + i + 1, 0, A[topa - 1], A[topa - 1], A[topa - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(44, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
    }
    if (src == 'B')
    {
        for (int i = 0; i + topb < 15; i++)
        {
            cct_showch(44 - B[topb - 1], 17 - topb - i, 0, COLOR_BLACK, COLOR_BLACK, B[topb - 1] * 2 + 1);
            cct_showch(44, 17 - topb - i, 0, 14, 14, 1);
            cct_showch(44 - B[topb - 1], 16 - topb - i, 0, B[topb - 1], B[topb - 1], B[topb - 1] * 2 + 1);
            Sleep((6-moving)*30);
        }
        if (dst == 'C')
        {
            for (int i = 0; i < 30; i++)
            {
                cct_showch(44 - B[topb - 1] + i, 2, 0, COLOR_BLACK, COLOR_BLACK, B[topb - 1] * 2 + 1);
                cct_showch(44 - B[topb - 1] + 1 + i, 2, 0, B[topb - 1], B[topb - 1], B[topb - 1] * 2 + 1);
                Sleep((6-moving)*30);
            }
            for (int i = 0; i < 14-topc; i++)
            {
                cct_showch(74 - B[topb - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, B[topb - 1] * 2 + 1);
                cct_showch(74 - B[topb - 1], 2 + i + 1, 0, B[topb - 1], B[topb - 1], B[topb - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(74, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
        else if (dst == 'A')
        {
            for (int i = 0; i < 30; i++)
            {
                cct_showch(44 - B[topb - 1] - i, 2, 0, COLOR_BLACK, COLOR_BLACK, B[topb - 1] * 2 + 1);
                cct_showch(44 - B[topb - 1] - 1 - i, 2, 0, B[topb - 1], B[topb - 1], B[topb - 1] * 2 + 1);
                Sleep((6-moving)*30);
            }
            for (int i = 0; i < 14-topa; i++)
            {
                cct_showch(14 - B[topb - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, B[topb - 1] * 2 + 1);
                cct_showch(14 - B[topb - 1], 2 + i + 1, 0, B[topb - 1], B[topb - 1], B[topb - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(14, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
    }
    if (src == 'C')
    {
        for (int i = 0; i + topc < 15; i++)
        {
            cct_showch(74 - C[topc - 1], 17 - topc - i, 0, COLOR_BLACK, COLOR_BLACK, C[topc - 1] * 2 + 1);
            cct_showch(74, 17 - topc - i, 0, 14, 14, 1);
            cct_showch(74 - C[topc - 1], 16 - topc - i, 0, C[topc - 1], C[topc - 1], C[topc - 1] * 2 + 1);
            Sleep((6-moving)*30);
        }
        if (dst == 'B')
        {
            for (int i = 0; i < 30; i++)
            {
                cct_showch(74 - C[topc - 1] - i, 2, 0, COLOR_BLACK, COLOR_BLACK, C[topc - 1] * 2 + 1);
                cct_showch(74 - C[topc - 1] - 1 - i, 2, 0, C[topc - 1], C[topc - 1], C[topc - 1] * 2 + 1);
                Sleep((6-moving)*30);
            }
            for (int i = 0; i < 14-topb; i++)
            {
                cct_showch(44 - C[topc - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, C[topc - 1] * 2 + 1);
                cct_showch(44 - C[topc - 1], 2 + i + 1, 0, C[topc - 1], C[topc - 1], C[topc - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(44, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
        else if (dst == 'A')
        {
            for (int i = 0; i < 60; i++)
            {
                cct_showch(74 - C[topc - 1] - i, 2, 0, COLOR_BLACK, COLOR_BLACK, C[topc - 1] * 2 + 1);
                cct_showch(74 - C[topc - 1] - 1 - i, 2, 0, C[topc - 1], C[topc - 1], C[topc - 1] * 2 + 1);
                Sleep((6-moving)*30);
            }
            for (int i = 0; i < 14-topa; i++)
            {
                cct_showch(14 - C[topc - 1], 2 + i, 0, COLOR_BLACK, COLOR_BLACK, C[topc - 1] * 2 + 1);
                cct_showch(14 - C[topc - 1], 2 + i + 1, 0, C[topc - 1], C[topc - 1], C[topc - 1] * 2 + 1);
                if (i != 0)
                    cct_showch(14, 2 + i, 0, 14, 14, 1);
                Sleep((6-moving)*30);
            }
        }
    }
    cct_gotoxy(0, 35);
    cct_setcolor(0, 7);
}
void transverse(int n, char src, char tmp, char dst,char sign)
{
    if (sign == '1' || sign == '2')
        print_move_one(n,src,dst,sign);
    if (sign == '3')
    {
        print_move(n, src, dst, sign);
        move(src, dst);
        print();
        return;
    }
    if (sign == '4')
    {
        wait();
        print_move(n, src, dst, sign);
        move(src, dst);
        print();
        wait();
        print_tower(sign);
    }
    if (sign == '8')
    {
        wait();
        print_move(n, src, dst, sign);
        move(src, dst);
        print();
        print_tower(sign);
        move(dst, src);
        disk_move(n, src, dst, sign);
        move(src, dst);
    }
}
void print_tower(char sign)
{
    if (sign == '4')
        cct_gotoxy(9, 12);
    else
        cct_gotoxy(9, 30);
    cout << "=========================" << endl;
    if (sign == '4')
        cct_gotoxy(11, 13);
    else
        cct_gotoxy(11, 31);
    cout << "A         B         C";
    for (int i = 0; i < 10; i++)
    {
        if (sign == '4')
            cct_gotoxy(10, 11 - i);
        else
            cct_gotoxy(10, 29 - i);
        if (A[i] != 0)
        {
            cout << setw(2) << A[i];
        }
        else
        {
            cout << setw(2) << " ";
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (sign == '4')
            cct_gotoxy(20, 11 - i);
        else
            cct_gotoxy(20, 29 - i);
        if (B[i] != 0)
        {
            cout << setw(2) << B[i];
        }
        else
        {
            cout << setw(2) << " ";
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (sign == '4')
            cct_gotoxy(30, 11 - i);
        else
            cct_gotoxy(30, 29 - i);
        if (C[i] != 0)
        {
            cout << setw(2) << C[i];
        }
        else
        {
            cout << setw(2) << " ";
            break;
        }
    }
}
void wait()
{
    switch (moving)
    {
        case 0:
            int cmd;
            while (1)
            {
                cmd = _getch();
                if (cmd == 13)
                    break;
            }
            break;
        case 1:
            Sleep(1000);
            break;
        case 2:
            Sleep(500);
            break;
        case 3:
            Sleep(200);
            break;
        case 4:
            Sleep(100);
            break;
        case 5:
            Sleep(50);
            break;
        default:
            break;
    }
}
void print_move_one(int n, char src, char dst,char sign)
{
    if (sign == '1')
        cout << setiosflags(ios::right) << setw(2) << n << "# " << src << "-->" << dst << endl;
    else if (sign == '2')
    {
        cout << "第" << setw(4) << num << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")  " << endl;
        num++;
    }
}
void print_move(int n, char src, char dst,char sign)
{
    if (sign == '4')
        cct_gotoxy(0, 17);
    else
        cct_gotoxy(0, 33);
    cout << "第" << setw(4) << num << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
    num++;
}
void move(char src, char dst)
{
    int temp = 0;
    switch (src)
    {
        case 'A':
            temp = A[topa - 1];
            A[topa - 1] = 0;
            topa--;
            break;
        case 'B':
            temp = B[topb - 1];
            B[topb - 1] = 0;
            topb--;
            break;
        case 'C':
            temp = C[topc - 1];
            C[topc - 1] = 0;
            topc--;
            break;
        default:
            break;
    }
    switch (dst)
    {
        case 'A':
            A[topa] = temp;
            topa++;
            break;
        case 'B':
            B[topb] = temp;
            topb++;
            break;
        case 'C':
            C[topc] = temp;
            topc++;
            break;
        default:
            break;
    }
}
void print()
{
    int i;
    cout << "A:";
    for (i = 0; i < 10; i++)
    {

        if (A[i] == 0)
            cout << "  ";
        else
            cout << setw(2) << A[i];
    }
    cout << " B:";
    for (i = 0; i < 10; i++)
    {

        if (B[i] == 0)
            cout << "  ";
        else
            cout << setw(2) << B[i];
    }
    cout << " C:";
    for (i = 0; i < 10; i++)
    {

        if (C[i] == 0)
            cout << "  ";
        else
            cout << setw(2) << C[i];
    }
    cout << endl;
}
void hanoi(int n, char src, char tmp, char dst,char sign)
{
    if (n == 1)
        transverse(n,src,tmp,dst,sign);
    else
    {
        hanoi(n - 1, src, dst, tmp,sign);
        transverse(n, src, tmp, dst,sign);
        hanoi(n - 1, tmp, src, dst,sign);
    }
}
void initial(char sign)
{
    num = 1;
    topa = 0, topb = 0, topc = 0;
    int n = 0;
    int j = 0;
    if (sign == '0' || sign == '5')
    {
        cout << sign;
        return;
    }
    else if (sign >= '1' && sign <= '9')
    {
        cout << sign << endl << endl << endl;
        while (1)
        {
            cout << "请输入汉诺塔的层数（1-10）" << endl;
            cin >> n;
            if (!cin.good() || n > 10 || n < 1)
            {
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
    char start, end;
    while (1)
    {
        cout << "请输入起始柱（A-C）" << endl;
        cin >> start;
        if (!cin.good() || start > 99 || start < 65 || (start < 97 && start>67))
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else
        {
            if (start > 96)
                start -= 32;
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "请输入目标柱（A-C）" << endl;
        cin >> end;
        if (!cin.good() || end > 99 || end < 65 || (end < 97 && end>67))
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else if (end > 96)
        {
            end -= 32;
            if (end == start)
            {
                cout << "目标柱(" << start << ")" << "不能与起始柱(" << end << ")相同" << endl;
                continue;
            }
        }
        else
        {
            if (end == start)
            {
                cout << "目标柱(" << start << ")" << "不能与起始柱(" << end << ")相同" << endl;
                continue;
            }
        }
        cin.clear();
        cin.ignore(2147483647, '\n');
        break;
    }
    char tmp = '0';
    if ((start == 65 && end == 66) || (end == 65 && start == 66))
        tmp = 'C';
    else if ((start == 65 && end == 67) || (end == 65 && start == 67))
        tmp = 'B';
    else if ((start == 66 && end == 67) || (end == 66 && start == 67))
        tmp = 'A';
    for (int i = n; i > 0; i--)
    {
        if (start == 'A')
            A[j] = i;
        else if (start == 'B')
            B[j] = i;
        else if (start == 'C')
            C[j] = i;
        j++;
    }
    if (start == 'A')
        topa = j;
    else if (start == 'B')
        topb = j;
    else if (start == 'C')
        topc = j;
    if (sign == '4' || sign == '8')
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
            cin >> moving;
            if (!cin.good() || moving > 5 || moving < 0)
            {
                cin.clear();
                cin.ignore(2147483647, '\n');
                continue;
            }
            else
            {
                cin.clear();
                cin.ignore(2147483647, '\n');
            }
            cct_cls();
            cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层，延时设置为 " << moving << endl;
            if (sign == '4')
            {
                print_tower(sign);
                cct_gotoxy(0, 17);
                cout << "初始:" << setw(16) << " ";
                print();
                hanoi(n, start, tmp, end, sign);
                cct_gotoxy(0, 19);
                break;
            }
            else
            {
                print_tower(sign);
                cct_gotoxy(0, 33);
                cout << "初始:" << setw(16) << " ";
                print();
                print_disk();
                print_disk_ini(start, n);
                hanoi(n, start, tmp, end, sign);
                cct_gotoxy(0, 35);
                cct_setcursor(CURSOR_VISIBLE_FULL);
                break;
            }
        }
    }
    else if (sign == '6' || sign == '7')
    {
        cct_cls();
        cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层" << endl;
        print_disk();
        print_disk_ini(start, n);
        if (sign == '7')
            disk_move(n, start, end, 1);
        cct_setcursor(6);
    }
    else if (sign == '9')
    {
        cct_cls();
        cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层" << endl;
        print_disk();
        print_disk_ini(start, n);
        print_tower(sign);
        cct_gotoxy(0, 33);
        cout << "初始:" << setw(16) << " ";
        print();
        cout << endl << endl << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
        int x, y;
        cct_getxy(x, y);
        while (1)
        {
            cct_setcursor(6);
            cct_showch(x, y, 32, COLOR_BLACK, COLOR_BLACK, 10);
            cct_showch(0, y + 1, 32, COLOR_BLACK, COLOR_BLACK, 25);
            cct_setcolor(0, 7);
            cct_gotoxy(x, y);
            cin.get(start);
            if (start == 'Q' || start == 'q')
            {
                cout << "游戏中止!!!!!" << endl;
                Sleep(500);
                return;
            }
            cin.get(end);
            int cishu = 0;
            for(;getchar() != '\n';cishu++)
                ;
            if (cishu > 0)
                continue;
            if (start == 'A' || start == 'B' || start == 'C' || start == 'a' || start == 'b' || start == 'c')
            {
                if (start >= 'a' && start <= 'c')
                    start -= 32;
                if (start == 'A')
                {
                    if (topa == 0)
                    {
                        cout <<"原柱为空！" << endl;
                        Sleep(900);
                        continue;
                    }
                }
                if (start == 'B')
                {
                    if (topb == 0)
                    {
                        cout <<"原柱为空！" << endl;
                        Sleep(900);
                        continue;
                    }
                }
                if (start == 'C')
                {
                    if (topc == 0)
                    {
                        cout <<"原柱为空！" << endl;
                        Sleep(900);
                        continue;
                    }
                }
            }
            else
                continue;
            if (end == 'A' || end == 'B' || end == 'C' || end == 'a' || end == 'b' || end == 'c')
            {
                if (end >= 'a' && end <= 'c')
                    end -= 32;
                if (end == start)
                    continue;
            }
            else
                continue;
            if (start == 'A' && end == 'B')
            {
                if (topb > 0)
                    if (A[topa - 1] > B[topb - 1])
                    {
                        cout <<"大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            else if (start == 'A' && end == 'C')
            {
                if (topc > 0)
                    if (A[topa - 1] > C[topc - 1])
                    {
                        cout <<"大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            else if (start == 'B' && end == 'C')
            {
                if (topc > 0)
                    if (B[topb - 1] > C[topc - 1])
                    {
                        cout << "大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            else if (start == 'B' && end == 'A')
            {
                if (topa > 0)
                    if (B[topb - 1] > A[topa - 1])
                    {
                        cout << "大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            else if (start == 'C' && end == 'A')
            {
                if (topa > 0)
                    if (C[topc - 1] > A[topa - 1])
                    {
                        cout << "大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            else if (start == 'C' && end == 'B')
            {
                if (topb > 0)
                    if (C[topc-1] > B[topb - 1])
                    {
                        cout <<  "大盘压小盘，非法移动!" << endl;
                        Sleep(900);
                        continue;
                    }
            }
            print_move(n, start, end, sign);
            move(start, end);
            print();
            print_tower(sign);
            move(end, start);
            disk_move(n, start, end, sign);
            move(start, end);
        }

    }
    else
        hanoi(n, start, tmp, end, sign);
}