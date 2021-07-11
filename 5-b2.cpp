/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
using namespace std;

int main()
{
    int a[101];
    for (int i = 0; i < 101; i++)
        a[i] = 0;
    for (int i = 1; i < 101; i++)
        for (int j = 1; i * j-1 < 101; j++)
        {
            if (a[i * j-1] == 1)
                a[i * j-1] = 0;
            else
                a[i * j-1] = 1;
        }
    for (int i = 0; i < 100; i++)
    {
        if (a[i] == 1)
        {
            cout << i+1;
            if (i != 99)
                cout << " ";
        }
    }
    cout << endl;
    return 0;
}

