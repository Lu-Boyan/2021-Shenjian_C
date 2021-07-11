/*1953609 软工 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int integer;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> integer;
	cout << setw(5)<< setiosflags(ios::left) << "万位" << ": " << integer / 10000 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "千位" << ": " << integer / 1000 % 10 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "百位" << ": " << integer / 100 % 10 << endl;
	cout << setw(5)<< setiosflags(ios::left) << "十位" << ": " << integer / 10 %10<< endl;
	cout << setw(5)<< setiosflags(ios::left) << "个位" << ": " << integer % 10 << endl;

	return 0;
}
