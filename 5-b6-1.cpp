/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int num = 1;
int topa = 0, topb = 0, topc = 0;
void move(char src, char dst)
{
    int temp = 0;
    switch (src)
    {
        case 'A':
            temp = A[topa-1];
            A[topa-1] = 0;
            topa--;
            break;
        case 'B':
            temp = B[topb-1];
            B[topb-1] = 0;
            topb--;
            break;
        case 'C':
            temp = C[topc-1];
            C[topc-1] = 0;
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
        cout << "第" << setw(4) << num << " 步" << "(" << setw(2) << n << "): " << src << "-->" << dst << " ";
        num++;
        move(src, dst);
        print();
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << num << " 步" << "(" << setw(2) << n << "): " << src << "-->" << dst << " ";
        num++;
        move(src, dst);
        print();
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
    cout << "初始:" << setw(16) << " ";
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
    print();
    hanoi(n, start, tmp, end);
    return 0;
}


