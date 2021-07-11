//1953609 软件 王灏廷//
#include <iostream>
using namespace std;
int fac(int n)
{
	int a = 1;
	if (n > 1)
		a = fac(n - 1);
	n *= a;
	return n;
}
int main()
{
	cout << "计算a!+b!+c!,请输入a,b,c的值（非负整数）" << endl;
	int a, b, c;
	cin >> a >> b >> c;
	int ansa,ansb,ansc;
	ansa = fac(a);
	ansb = fac(b);
	ansc = fac(c);
	cout << a << "!+" << b << "!+" << c << "!=" << ansa+ansb+ansc << endl;
	return 0;
}

