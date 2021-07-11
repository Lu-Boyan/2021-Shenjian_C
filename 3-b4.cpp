/*1953609 软工 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    double a;
    cout << "请输入[0,100亿）之间的数字:" << endl;
    cin >> a;
	int a1 = static_cast<int>(a/10);
	cout << setw(7)<< setiosflags(ios::left) << "十亿位" << ": " << a1/ 100000000 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "亿位" << ": " << a1 / 10000000%10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "千万位" << ": " << a1 / 1000000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "百万位" << ": " << a1 / 100000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "十万位" << ": " << a1 / 10000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "万位" << ": " << a1 / 1000 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "千位" << ": " << a1 / 100 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "百位" << ": " << a1 / 10 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "十位" << ": " << a1 % 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "圆" << ": " << floor((a / 10 - floor(a / 10)) * 10) << endl;
	cout << setw(7)<< setiosflags(ios::left) << "角" << ": " << static_cast<int>(round((a - floor(a)) * 100))/10% 10 << endl;
	cout << setw(7)<< setiosflags(ios::left) << "分" << ": " << static_cast<int>(round((a - floor(a))*100))%10<< endl;
	//不准的只是小数点后的两位，相减后留下小数点后两位，再扩大为整数即可

	return 0;
}

