/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
using namespace std;
int main()
{
    for (int i = 2; i < 1000; i++)
    {
        int a = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                a += j;
            if (a == i&&j==i/2)
            {
                cout << a << ",its factors are ";
                for (int k = 1; k <= a / 2; k++)
                {
                    if (a % k == 0 && k != a / 2)
                        cout << k << ",";
                    else if (a % k == 0)
                        cout << k << endl;
                }
            }
        }
    }
    return 0;
}


