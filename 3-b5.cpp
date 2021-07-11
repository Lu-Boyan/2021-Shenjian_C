/*1953609 软工 王灏廷*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
	double pi = 3.14159;
	int a,b,angle;
	cout << "请输入三角形的两边及其夹角（角度）:" << endl;
	cin >> a >> b>>angle;
	double s = 0.5 * a * b * sin(angle/180.0*pi);
	cout << setiosflags(ios::fixed) << setprecision(3) << setw(13)
		<< setiosflags(ios::left) << "三角形面积为" << ": " << static_cast<float>(s) << endl;

	return 0;
}