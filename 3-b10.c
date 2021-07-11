/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%dx%d=%-4d",j,i,j*i);
            if (i == j)
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;//3-b9对应的cpp方式作业的编码格式不对
}
//3-b9对应的cpp方式作业的编码格式不对


