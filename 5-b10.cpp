/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int y, int m, int d)
{
    int week, century;
    int w;
    if (m < 3)
    {
        m += 12;
        y -= 1;
    }
    century = y / 100;
    y = y % 100;
    week = y + y / 4 + century / 4 - 2 * century + (13 * (m + 1) / 5) + d - 1;
    while (week < 0)
        week += 7;
    w = week % 7;
    return w;
}
int run(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}
int main()
{
    system("mode con cols=120 lines=45");
    int year;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int firstday[12] = { 0 };
    while (1)
    {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> year;
        if (!cin.good() || year > 2100 || year < 1900)
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
    if (run(year) == 1)
        month[1] = 29;
    cout << year << "年的日历:" << endl << endl;
    cout << "            1月                             2月                             3月" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
    for (int i = 0; i < 12; i++)
    {
        firstday[i] = zeller(year,i+1, 1);
    }
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[0])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7- firstday[0]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[0] = 7 - firstday[0]+1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[1])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[1]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[1] = 7 - firstday[1]+1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[2])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[2]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[2] = 7 - firstday[2]+1;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < 63; i++)
    {
        if (i% 21<7)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[0];
            firstday[0]++;
        }
        if (i % 21 == 7)
            cout << "    ";
        if (i % 21 >= 7 && i % 21 < 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[1];
            firstday[1]++;
        }
        if (i % 21 == 14)
            cout << "    ";
        if (i % 21 >=14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[2];
            firstday[2]++;
        }
        if ((i + 1) % 21 == 0)
            cout << endl;
    }
    while (month[0] - firstday[0] >= 0 || month[1] - firstday[1] >= 0 || month[2] - firstday[2] >= 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (month[0] < firstday[0])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[0];
                firstday[0]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[1] < firstday[1])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[1];
                firstday[1]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[2] < firstday[2])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[2];
                firstday[2]++;
            }
        }
        cout << endl;
   }
    cout << endl;
    cout << "            4月                             5月                             6月" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[3])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[3]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[3] = 7 - firstday[3] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[4])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[4]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[4] = 7 - firstday[4] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[5])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[5]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[5] = 7 - firstday[5] + 1;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < 63; i++)
    {
        if (i % 21 < 7)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[3];
            firstday[3]++;
        }
        if (i % 21 == 7)
            cout << "    ";
        if (i % 21 >= 7 && i % 21 < 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[4];
            firstday[4]++;
        }
        if (i % 21 == 14)
            cout << "    ";
        if (i % 21 >= 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[5];
            firstday[5]++;
        }
        if ((i + 1) % 21 == 0)
            cout << endl;
    }
    while (month[3] - firstday[3] >= 0 || month[4] - firstday[4] >= 0 || month[5] - firstday[5] >= 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (month[3] < firstday[3])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[3];
                firstday[3]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[4] < firstday[4])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[4];
                firstday[4]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[5] < firstday[5])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[5];
                firstday[5]++;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "            7月                             8月                             9月" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[6])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[6]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[6] = 7 - firstday[6] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[7])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[7]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[7] = 7 - firstday[7] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[8])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[8]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[8] = 7 - firstday[8] + 1;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < 63; i++)
    {
        if (i % 21 < 7)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[6];
            firstday[6]++;
        }
        if (i % 21 == 7)
            cout << "    ";
        if (i % 21 >= 7 && i % 21 < 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[7];
            firstday[7]++;
        }
        if (i % 21 == 14)
            cout << "    ";
        if (i % 21 >= 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[8];
            firstday[8]++;
        }
        if ((i + 1) % 21 == 0)
            cout << endl;
    }
    while (month[6] - firstday[6] >= 0 || month[7] - firstday[7] >= 0 || month[8] - firstday[8] >= 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (month[6] < firstday[6])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[6];
                firstday[6]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[7] < firstday[7])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[7];
                firstday[7]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[8] < firstday[8])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[8];
                firstday[8]++;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "           10月                            11月                            12月" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[9])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[9]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[9] = 7 - firstday[9] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[10])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[10]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[10] = 7 - firstday[10] + 1;
            break;
        }
    }
    cout << "    ";
    for (int i = 0; i < 7; i++)
    {
        if (i < firstday[11])
            cout << setw(4) << " ";
        else
        {
            for (int j = 1; j <= 7 - firstday[11]; j++)
                cout << setiosflags(ios::left) << setw(4) << j;
            firstday[11] = 7 - firstday[11] + 1;
            break;
        }
    }
    cout << endl;
    for (int i = 0; i < 63; i++)
    {
        if (i % 21 < 7)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[9];
            firstday[9]++;
        }
        if (i % 21 == 7)
            cout << "    ";
        if (i % 21 >= 7 && i % 21 < 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[10];
            firstday[10]++;
        }
        if (i % 21 == 14)
            cout << "    ";
        if (i % 21 >= 14)
        {
            cout << setiosflags(ios::left) << setw(4) << firstday[11];
            firstday[11]++;
        }
        if ((i + 1) % 21 == 0)
            cout << endl;
    }
    while (month[9] - firstday[9] >= 0 || month[10] - firstday[10] >= 0 || month[11] - firstday[11] >= 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (month[9] < firstday[9])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[9];
                firstday[9]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[10] < firstday[10])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[10];
                firstday[10]++;
            }
        }
        cout << "    ";
        for (int i = 0; i < 7; i++)
        {
            if (month[11] < firstday[11])
                cout << setw(4) << " ";
            else
            {
                cout << setiosflags(ios::left) << setw(4) << firstday[11];
                firstday[11]++;
            }
        }
        cout << endl;
    }
    cout << endl << endl;
    return 0;
}
