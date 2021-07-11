/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
using namespace std;

int main()
{
    const int MAX_X = 10;
    const int MAX_Y = 26;
    char map[11][27] = { '0' };
    for (int j = 0; j < 50; j++)
    {
        int x = rand() % MAX_X, y = rand() % MAX_Y;
        if (map[x][y] == '*')
        {
            j--;
            continue;
        }
        else
            map[x][y] = '*';
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int num = 0;
            if (map[i][j] != '*')
            {
                if (i >= 1 && j >= 1)
                    if (map[i - 1][j - 1] == '*')
                        num++;
                if (i >= 1)
                    if (map[i - 1][j] == '*')
                        num++;
                if (j >= 1)
                    if (map[i][j - 1] == '*')
                        num++;
                if (i >= 1 && j < MAX_Y)
                    if (map[i - 1][j + 1] == '*')
                        num++;
                if (j < MAX_Y)
                    if (map[i][j + 1] == '*')
                        num++;
                if (i < MAX_X && j >= 1)
                    if (map[i + 1][j - 1] == '*')
                        num++;
                if (i < MAX_X)
                    if (map[i + 1][j] == '*')
                        num++;
                if (i < MAX_X && j < MAX_Y)
                    if (map[i + 1][j + 1] == '*')
                        num++;
                map[i][j] = num + '0';
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
