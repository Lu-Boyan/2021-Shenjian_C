/*软件 1953609 王灏廷*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //取系统时间

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
					printf("No.%3d : %d+%d+%d=1953\n",num,i,j,1953-i-j);
				}
			}
		}
	}
	printf("total=%d\n",num);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n",tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6lf秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
	//3-b11对应的cpp方式作业的编码格式不对
}
//3-b11对应的cpp方式作业的编码格式不对


