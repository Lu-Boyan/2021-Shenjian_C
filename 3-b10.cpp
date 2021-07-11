/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << j << "x" << i << "=" << setw(4) << setiosflags(ios::left) << i * j;
            if (i == j)
            {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}