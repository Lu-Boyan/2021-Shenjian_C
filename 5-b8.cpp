/*1953609 软件 王灏廷*/
#include <iostream>
#include<cmath>
using namespace std;
double cal_length(double x1, double y1, double x2, double y2)
{
	double len;
	len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return len;
}
int judge(double x1, double x2, double x3, double y1, double y2, double y3)
{
	double p1 = x2 - x1, q1 = x3 - x2;
	double p2 = y2 - y1, q2 = y3 - y2;
	if (p1 * q2 - q1 * p2 < -1e-6)
		return 0;
	else if (p1 * q2 - q1 * p2 > 1e-6)
		return 1;
	else
		return 2;
}
double cal(double x1, double x2, double x3, double y1, double y2, double y3)
{
	double a, b, c, p, s;
	a = cal_length(x1, y1, x2, y2);
	b = cal_length(x2, y2, x3, y3);
	c = cal_length(x1, y1, x3, y3);
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
}
int main()
{
    int num;
    double x[5], y[5];
	int tag = -1,tag_last=-1;
	double s = 0;
	while (1) 
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		if (num >= 4 && num <= 7)
			break;
		else
			cin.ignore(2147483647, '\n');
	}
	cout << "请按顺时针/逆时针方向输入" << num << "个顶点的x,y坐标：" << endl;
	for (int i = 0; i < num; i++)
	{
		while (1) 
		{
			cout << "请输入第" << i + 1 << "个顶点的坐标:" << endl;
			cin >> x[i] >> y[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(2147483647, '\n');
				continue;
			}
			cin.ignore(2147483647, '\n');
			break;
		}
	}
	for (int i = 0; i < num - 2; i++)
	{
		tag = judge(x[i], x[i + 1], x[i + 2], y[i], y[i + 1], y[i + 2]);
		if ((tag !=tag_last&&i>0)||tag==2)
		{
			cout << "不是凸" << num << "边形" << endl;
			break;
		}
		tag_last = tag;
	}
	if (tag_last == tag)
	{
		for (int i = 0; i < num - 2; i++)
			s += cal(x[i], x[i + 1], x[num-1], y[i], y[i + 1], y[num-1]);
		cout << "凸" << num << "边形的面积=" << s << endl;
	}
	return 0;
}
