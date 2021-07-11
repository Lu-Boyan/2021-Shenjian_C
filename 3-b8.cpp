/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
    int fifty=0,twenty=0,ten=0,five=0,one=0,five_jiao=0,jiao=0,five_fen=0,two_fen=0,fen=0;
    double change;
    cout << "请输入找零值：" << endl;
    cin >> change;
    const int change1 = static_cast<int>(change/10);
    int shi = change1 % 10;
    int ge = static_cast<int>(floor((change / 10.0 - floor(change / 10)) * 10 + 1e-7));
    int horn= static_cast<int>(round((change - floor(change)) * 100)) / 10 % 10;
    int cent = static_cast<int>(round((change - floor(change)) * 100)) % 10;
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
    cout << "共" << sum << "张找零，具体如下："<<endl;
    if (fifty > 0)
        cout << setw(5) << setiosflags(ios::left) << "50元" << "：" << fifty << "张" << endl;
    if (twenty > 0)
        cout << setw(5) << setiosflags(ios::left) << "20元" << "：" << twenty << "张" << endl;
    if (ten > 0)
        cout << setw(5) << setiosflags(ios::left) << "10元" << "：" << ten << "张" << endl;
    if (five > 0)
        cout << setw(5) << setiosflags(ios::left) << "5元" << "：" << five << "张" << endl;
    if (one > 0)
        cout << setw(5) << setiosflags(ios::left) << "1元" << "：" << one << "张" << endl;
    if (five_jiao > 0)
        cout << setw(5) << setiosflags(ios::left) << "5角" << "：" << five_jiao << "张" << endl;
    if (jiao > 0)
        cout << setw(5) << setiosflags(ios::left) << "1角" << "：" << jiao << "张" << endl;
    if (five_fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "5分" << "：" << five_fen << "张" << endl;
    if (two_fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "2分" << "：" << two_fen << "张" << endl;
    if (fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "1分" << "：" << fen << "张" << endl;
    return 0;
}
