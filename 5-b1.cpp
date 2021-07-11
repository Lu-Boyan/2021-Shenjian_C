/*1953609 软件 王灏廷*/
#include <iostream>
using namespace std;
int main()
{
    int a[22];
    cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	int i = 0, b = 0, m = 0,k=0;
	for (int j = 0; j < 22; j++)
		a[j] = 1;
    while (a[i] >0&&i<=21)
    {
		if (i != 0)
			i++;
        for(;i < 21;++i)
        {
            cin >> a[i];
			if (a[0] <0)
			{
				cout << "无有效输入" << endl;
				break;
			}
			if (getchar() == '\n')
				break;
        }     
    }
	if (i >= 20)
	{
		i = 20;
		if (getchar() != '\n')
			cin.ignore(2147483647, '\n');
	}
	if (a[0]>0)
	{
		cout << "原数组为:" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> b;
		int low = 0, high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (b >= a[m])
			{
				low = m + 1;
			}
			else
			{
				high = m - 1;
			}
		}
		for (k=i-1; k>high; k--)
			a[k + 1] = a[k];
		a[k+1] = b;
		cout << "插入后的数组为:" << endl;
		for (int j = 0; j <= i; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
	}
    return 0;
}

