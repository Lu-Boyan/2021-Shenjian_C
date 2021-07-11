/*1953609 软件 王灏廷*/
#include <iostream>
using namespace std;
int main()
{
    int a[1002];
    cout << "请输入成绩（最多1000个），以-1结束" << endl;
    for (int j = 0; j < 1002; j++)
        a[j] = 1;
    int i = 0, num = 0, sum = 0;
    while (a[i] >0 && i <= 1001)
    {
        if (i != 0)
            i++;
        for (; i < 1001; ++i)
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
    int max = a[0];
    if (a[0] > 0)
    {
        cout << "输入的数组为:" << endl;
        for (int j = 0; j < i; j++)
        {
            cout << a[j] << " ";
            if ((j + 1) % 10 == 0 && j + 1 != i)
                cout << endl;
        }
        cout << endl;
        cout << "分数与人数的对应关系为:" << endl;
        while(i-sum>0)
        {
            for (int k = 0; k < i; k++)
            {
                if (a[k] > max)
                {
                    max = a[k];
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (a[j] == max)
                {
                    a[j] = -1;
                    num++;
                }
            }
            cout << max << " " << num << endl;
            sum += num;
            num = 0;
            max = a[0];
        }
    }
    return 0;
}


