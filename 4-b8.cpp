/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int sum = 1;
    if (n == 1)
    {
        cout << setiosflags(ios::right) << setw(5) << sum << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        sum++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setiosflags(ios::right) << setw(5) << sum << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        sum++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数（1-16）" << endl;
        cin >> n;
        if (!cin.good() || n > 16 || n < 1)
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
    cout << "移动步骤为:" << endl;
    hanoi(n, start, tmp, end);
    return 0;
}
