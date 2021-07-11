/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	double r, h, c, s, s_surface, v_ball, v_cylinder;
	cin >> r >> h;
	c = 2 * pi * r;
	s = pi * r * r;
	s_surface = 4 * pi * r * r;
	v_ball = 4.0 / 3 * pi * r * r * r;
	v_cylinder = pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "圆周长" << ": " << c << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "圆面积" << ": " << s << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "圆球表面积" << ": " << s_surface << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "圆球体积" << ": " << v_ball << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << setw(11)
		<< setiosflags(ios::left) << "圆柱体积" << ": " << v_cylinder << endl;

	return 0;
}
