/* 1953609 软件 王灏廷 */
#include <iostream>
using namespace std;

int judge(char* str)
{
    for (char* h = str, *t = str + strlen(str) - 2; h < t; h++, t--)
    {
        if (*h != *t)
        {
            cout << "no" << endl;
            return 1;
        }
    }
    return 0;
}
int main()
{
    char str[81];
    cout << "请输入一个长度小于80的字符串（回文串）" << endl;
    fgets(str, 80,stdin);
    int tag = -1;
    tag = judge(str);
    if (tag != 1)
        cout << "yes" << endl;
    return 0;
}