/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
    int fifty = 0, twenty = 0, ten = 0, five = 0, one = 0, five_jiao = 0, jiao = 0, five_fen = 0, two_fen = 0, fen = 0;
    double change;
    printf("请输入找零值：\n");
    scanf("%lf",&change);
    const int change1 = (int)(change / 10);
    int shi = change1 % 10;
    int ge = (int)(floor((change / 10.0 - floor(change / 10)) * 10 + 1e-7));
    int horn = (int)(round((change - floor(change)) * 100)) / 10 % 10;
    int cent = (int)(round((change - floor(change)) * 100)) % 10;
    if (shi >= 5)
    {
        fifty += 1;
        shi -= 5;
    }
    if (shi >= 2)
    {
        twenty += 1;
        shi -= 2;
    }
    if (shi >= 2)
    {
        twenty += 1;
        shi -= 2;
    }
    if (shi >= 1)
    {
        ten += 1;
        shi -= 1;
    }
    if (ge >= 5)
    {
        five += 1;
        ge -= 5;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (horn >= 5)
    {
        five_jiao += 1;
        horn -= 5;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (cent >= 5)
    {
        five_fen += 1;
        cent -= 5;
    }
    if (cent >= 2)
    {
        two_fen += 1;
        cent -= 2;
    }
    if (cent >= 2)
    {
        two_fen += 1;
        cent -= 2;
    }
    if (cent >= 1)
    {
        fen += 1;
        cent -= 1;
    }
    const int sum = fifty + twenty + ten + five + one + five_jiao + jiao + five_fen + two_fen + fen;
    printf("共%d张找零，具体如下：\n",sum);
    if (fifty > 0)
        printf("50元 : %d张\n",fifty);
    if (twenty > 0)
        printf("20元 : %d张\n", twenty);
    if (ten > 0)
        printf("10元 : %d张\n", ten);
    if (five > 0)
        printf("5元  : %d张\n", five);
    if (one > 0)
        printf("1元  : %d张\n", one);
    if (five_jiao > 0)
        printf("5角  : %d张\n", five_jiao);
    if (jiao > 0)
        printf("1角  : %d张\n", jiao);
    if (five_fen > 0)
        printf("5分  : %d张\n", five_fen);
    if (two_fen > 0)
        printf("2分  : %d张\n", two_fen);
    if (fen > 0)
        printf("1分  : %d张\n", fen);
    return 0;//3-b8对应的cpp方式作业的编码格式不对
}
//3-b8对应的cpp方式作业的编码格式不对

