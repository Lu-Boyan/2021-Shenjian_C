/* 1953609 软件 王灏廷 */
#include <iostream>
using namespace std;

int main()
{
    char str[3][128];
    int big = 0, small = 0, num = 0, tab = 0, other = 0;
    cout << "请输入第1行" << endl;
    cin.get(str[0],128);
    getchar();
    cout << "请输入第2行" << endl;
    cin.get(str[1], 128);
    getchar();
    cout << "请输入第3行" << endl;
    cin.get(str[2], 128);
    getchar();
    for(int i=0;i<3;i++)
    {
        for (unsigned int j = 0;str[i][j]!='\0'; j++)
        {
            if (str[i][j] == ' ')
                tab++;
            else if (str[i][j] >= 'A' && str[i][j] <= 'Z')
                big++;
            else if (str[i][j] >= 'a' && str[i][j] <= 'z')
                small++;
            else if (str[i][j] >= '0' && str[i][j] <= '9')
                num++;
            else
                other++;
        }
    }
    cout << "大写 : " << big << endl;
    cout << "小写 : " << small << endl;
    cout << "数字 : " << num << endl;
    cout << "空格 : " << tab << endl;
    cout << "其它 : " << other << endl;
    return 0;
}


