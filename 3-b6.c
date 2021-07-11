/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int year, month, day;
    printf("请输入年，月，日\n");
    const int a=scanf("%d%d%d",&year,&month,&day);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day);
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>29)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n",year,month,day,year,day+31);
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31+29);
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29+31);
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29+31+30);
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30+31);
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31+30);
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31 + 30+31);
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31 + 30 + 31+31);
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31 + 30 + 31+31+30);
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31 + 30 + 31+31+30+31);
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
                printf("输入错误-日与月的关系非法\n");
            else
            {
                printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30);
            }
        }
        else
        {
            printf("输入错误-月份不正确\n");
        }
    }
    else
    {
    if (month == 1)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day);
        }
    }
    else if (month == 2)
    {
        if (day < 1 || day>28)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31);
        }
    }
    else if (month == 3)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28);
        }
    }
    else if (month == 4)
    {
        if (day < 1 || day>30)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31);
        }
    }
    else if (month == 5)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30);
        }
    }
    else if (month == 6)
    {
        if (day < 1 || day>30)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31);
        }
    }
    else if (month == 7)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30);
        }
    }
    else if (month == 8)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30 + 31);
        }
    }
    else if (month == 9)
    {
        if (day < 1 || day>30)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
        }
    }
    else if (month == 10)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
        }
    }
    else if (month == 11)
    {
        if (day < 1 || day>30)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
        }
    }
    else if (month == 12)
    {
        if (day < 1 || day>31)
            printf("输入错误-日与月的关系非法\n");
        else
        {
            printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
        }
    }
    else
    {
        printf("输入错误-月份不正确\n");
    }
    }
    //3-b6对应的cpp方式作业的编码格式不对
    return 0;
}
//3-b6对应的cpp方式作业的编码格式不对
