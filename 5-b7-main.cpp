/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include"5-b7.h"
using namespace std;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int num = 1;
int topa = 0, topb = 0, topc = 0;
static int moving = -1;
int display = -1;
void print_tower()
{
    cct_gotoxy(9, 12);
    cout << "=========================" << endl;
    cct_gotoxy(11, 13);
    cout << "A         B         C";
    for (int i = 0; i < 10; i++)
    {
        cct_gotoxy(10, 11 - i);
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
        cct_gotoxy(20, 11 - i);
        if (B[i]!=0)
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
        cct_gotoxy(30, 11 - i);
        if (C[i]!=0)
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
void print_move(int n, char src, char dst)
{
    cct_gotoxy(0, 17);
    cout << "第" << setw(4) << num << "步" << "(" << n << "#: " << src << "-->" << dst << ")  ";
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
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        wait();
        print_move(n, src, dst);
        move(src, dst);
        if (display == 1)
        {
            print();
            wait();
        }
        print_tower();
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        wait();
        print_move(n, src, dst);
        move(src, dst);
        if (display == 1)
        {
            print();
            wait();
        }
        print_tower();
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n;
    int j = 0;
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
            break;
        }
    }
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> display;
        if (!cin.good() || display > 1 || display < 0)
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
    cct_cls();
    if (display == 1)
        cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层，延时设置为 " << moving << "，显示内部数组值" << endl;
    else
        cout << "从 " << start << " 移动到 " << end << "，共 " << n << " 层，延时设置为 " << moving << "，不显示内部数组值" << endl;
    print_tower();
    if (display == 1)
    {
        cct_gotoxy(0, 17);
        cout << "初始:" << setw(16) << " ";
        print();
    }
    hanoi(n, start, tmp, end);
    cct_gotoxy(0, 19);
    return 0;
}