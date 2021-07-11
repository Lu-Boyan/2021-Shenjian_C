/*1953609 软件 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int top[3] = { 0 };
int abc[3][10] = { 0 };
int num = 1;
void move(char src, char dst)
{
    int temp = 0;
    switch (src)
    {
        case 'A':
            temp = abc[0][top[0] - 1];
            abc[0][top[0] - 1] = 0;
            top[0]--;
            break;
        case 'B':
            temp = abc[1][top[1] - 1];
            abc[1][top[1] - 1] = 0;
            top[1]--;
            break;
        case 'C':
            temp = abc[2][top[2] - 1];
            abc[2][top[2] - 1] = 0;
            top[2]--;
            break;
        default:
            break;
    }
    switch (dst)
    {
        case 'A':
            abc[0][top[0]] = temp;
            top[0]++;
            break;
        case 'B':
            abc[1][top[1]] = temp;
            top[1]++;
            break;
        case 'C':
            abc[2][top[2]] = temp;
            top[2]++;
            break;
        default:
            break;
    }
}
void print()
{
    int i;
    printf("A:");
    for (i = 0; i < 10; i++)
    {

        if (abc[0][i] == 0)
            printf("  ");
        else
            printf("%2d",abc[0][i]);
    }
    printf(" B:");
    for (i = 0; i < 10; i++)
    {

        if (abc[1][i] == 0)
            printf("  ");
        else
            printf("%2d", abc[1][i]);
    }
    printf(" C:");
    for (i = 0; i < 10; i++)
    {

        if (abc[2][i] == 0)
            printf("  ");
        else
            printf("%2d", abc[2][i]);
    }
    printf("\n");
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        printf("第%4d 步(%2d): %c-->%c ",num,n,src,dst);
        num++;
        move(src, dst);
        print();
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c ", num, n, src, dst);
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
        printf("请输入汉诺塔的层数（1-10）\n");
        const int tag = scanf("%d", &n);
        if (tag <= 0 || n > 16 || n < 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            while (getchar() != '\n')
                ;
            break;
        }
    }
    char start, end;
    while (1)
    {
        printf("请输入起始柱（A-C）\n");
        const int tag = scanf("%c", &start);
        if (tag <= 0 || start > 99 || start < 65 || (start < 97 && start>67))
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else
        {
            if (start > 96)
                start -= 32;
            while (getchar() != '\n')
                ;
            break;
        }
    }
    while (1)
    {
        printf("请输入目标柱（A-C）\n");
        const int tag = scanf("%c", &end);
        if (tag <= 0 || end > 99 || end < 65 || (end < 97 && end>67))
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        else if (end > 96)
        {
            end -= 32;
            if (end == start)
            {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", start, end);
                continue;
            }
        }
        else
        {
            if (end == start)
            {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", start, end);
                continue;
            }
        }
        while (getchar() != '\n')
            ;
        break;
    }
    char tmp = '0';
    if ((start == 65 && end == 66) || (end == 65 && start == 66))
        tmp = 'C';
    else if ((start == 65 && end == 67) || (end == 65 && start == 67))
        tmp = 'B';
    else if ((start == 66 && end == 67) || (end == 66 && start == 67))
        tmp = 'A';
    printf("初始:%16c",' ');
    for (int i = n; i > 0; i--)
    {
        if (start == 'A')
            abc[0][j] = i;
        else if (start == 'B')
            abc[1][j] = i;
        else if (start == 'C')
            abc[2][j] = i;
        j++;
    }
    if (start == 'A')
        top[0] = j;
    else if (start == 'B')
        top[1] = j;
    else if (start == 'C')
        top[2] = j;
    print();
    hanoi(n, start, tmp, end);
    return 0;
}


