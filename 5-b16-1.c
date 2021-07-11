/* 1953609 软件 王灏廷 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int shuru(char num[], char name[], int i)
{
    int grade;
    printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
    scanf("%s %s %d", num, name, &grade);
    if (grade < 60)
        return grade;
    else
        return -1;
}
void sort(char a[][8],char b[][9],int grade[])
{
    int i = 0;
    int j = 0;
    char tempa[8];
    char tempb[8];
    int temp;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                for (int k = 0; k < 7; k++)
                    tempa[k] = a[j][k];
                for (int k = 0; k < 7; k++)
                    a[j][k] = a[j + 1][k];
                for (int k = 0; k < 7; k++)
                    a[j + 1][k] = tempa[k];
                for (int k = 0; k < 8; k++)
                    tempb[k] = b[j][k];
                for (int k = 0; k < 8; k++)
                    b[j][k] = b[j + 1][k];
                for (int k = 0; k < 8; k++)
                    b[j + 1][k] = tempb[k];
                temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
            }
        }
    }
}
void shuchu(char a[][8], char b[][9], int grade[])
{
    printf("\n不及格名单:\n");
    for (int i = 0; i < 10; i++)
    {
        if (grade[i] != -1)
            printf("%s %s %d\n", b[i], a[i], grade[i]);
    }
}
int main()
{
    char num[10][8];
    char name[10][9];
    int grade[10] = { -1 };
    for (int i = 0; i < 10; i++)
        grade[i] = shuru(num[i], name[i], i);
    sort(num,name,grade);
    shuchu(num, name, grade);
    return 0;
}