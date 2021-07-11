/*1953609 软件 王灏廷*/
#include <iostream>
using namespace std;
int main()
{
    int year, month, day;
    cout << "请输入年，月，日" << endl;
    cin >> year >> month >> day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>29)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day+31 << "天" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31+29 << "天" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29+31 << "天" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29+31+30 << "天" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30+31 << "天" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31+30 << "天" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 +31<< "天" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31+31 << "天" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31+30 << "天" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31 << "天" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30 << "天" << endl;
            }
        }
        else
        {
            cout << "输入错误-月份不正确" << endl;
        }  
    }
    else
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>28)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 << "天" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 << "天" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 << "天" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 << "天" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 << "天" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 << "天" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 << "天" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 << "天" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "天" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "天" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
                cout << "输入错误-日与月的关系非法" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "天" << endl;
            }
        }
        else
        {
        cout << "输入错误-月份不正确" << endl;
        }
    }
    return 0;
}
