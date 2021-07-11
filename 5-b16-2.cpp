/* 1953609 软件 王灏廷 */
#include <iostream>
#include<string.h>
using namespace std;
int shuru(string num[], string name[],int i)
{
    int grade;
    cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
    cin >> num[i] >> name[i] >> grade;
    if (grade < 60)
        return grade;
    else
        return -1;
}
void sort(string num[], string name[], int grade[])
{
    int i = 0;
    int j = 0;
    int temp;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (num[j] < num[j + 1])
            {
                num[j].swap(num[j + 1]);
                name[j].swap(name[j + 1]);
                temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
            }
        }
    }
}
void shuchu(string num[], string name[], int grade[])
{
    cout << endl << "不及格名单:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (grade[i] != -1)
            cout << name[i] << " " << num[i] << " " << grade[i] << endl;
    }
}
int main()
{
    string num[10];
    string name[10];
    int grade[10] = { -1 };
    for (int i = 0; i < 10; i++)
        grade[i]=shuru(num, name, i);
    sort(num, name, grade);
    shuchu(num, name, grade);
    return 0;
}