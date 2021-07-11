/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << "请输入圆半径r[1..100] : ";
    int r, start, end;
    cin >> r;
    cout << "请输入起点(旧家)角度[0..360) : ";
    cin >> start;
    cout << "请输入终点(新家)角度[0..360) : ";
    cin >> end;
    const double pi = 3.14159;
    double l;
    if(end-start<=180)
        l = (end - start) * pi * r / 180;
    else
        l = (360-end + start) * pi * r / 180;
    cout <<"沿圆弧最短距离 : " << setiosflags(ios::fixed) << setprecision(2) << l << endl;
    return 0;
}