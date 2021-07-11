/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int num = 0;
	for (int i = 123; i <= 598; i++)
	{
		const int a = (i / 10) % 10;
		const int b = i / 100;
		const int c = i % 10;
		if (a == b || a == c || b == c || a == 0 || b == 0 || c == 0)
			continue;
		for (int j = i + 1; j <= 987; j++)
		{
			const int d = (j / 10) % 10;
			const int e = j / 100;
			const int f = j % 10;
			if (d == a || d == b || d == c || e == a || e == b || e == c || f == a || f == b || f == c || d == e || d == f || f == e || d == 0 || e == 0 || f == 0)
				continue;
			else
			{
				const int k = 1953 - i - j;
				if (k < j || k > 987)
					continue;
				const int m = (k / 10) % 10;
				const int n = k / 100;
				const int p = k % 10;
				if (m == a || m == b || m == c || m == e || m == d || m == f || m == 0)
					continue;
				else if (n == a || n == b || n == c || n == e || n == d || n == f || n == 0)
					continue;
				else if (p == a || p == b || p == c || p == e || p == d || p == f || p == 0)
					continue;
				else if (m == n || m == p || n == p)
					continue;
				else
				{
					num++;
					cout << "No." << setw(3) << num << " : " << i << "+" << j << "+" << 1953 - i - j << "=1953" << endl;
				}
			}
		}
	}
	cout << "total=" << num << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}