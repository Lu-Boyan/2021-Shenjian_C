/* 1953609 软件 王灏廷 */
/* 已验证 1952652 周煜人、1951748 罗立信、1950579 周婉莹、1951225 刘玉宝、1952656 刘晨昀的hex文件生成 */
#include <iostream>
#include <iomanip>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{
    cerr << "文件名以下形式均可以：" << endl
        << "    a.txt：不带路径形式" << endl
        << "    ..\\data\\b.dat：相对路径形式" << endl
        << "    C : \\Windows\\System32\\c.dat：绝对相对路径形式" << endl
        << "请输入要转换的hex格式文件名 : " ;
    char str1[100];
    char str2[100];
    cin >> str1;  
    ifstream in(str1, ios::in|ios::binary);   
    if (!in.is_open())
    {
        cerr << "文件" << str1 << "打开失败!" << endl;
        in.close();
        return -1;
    }
    cout << "请输入转换后的文件名 : ";
    cin >> str2;
    ofstream out(str2, ios::out | ios::binary);
    int tag = 0;
    while (tag != 1)
    {
        char ch;
        int i = 0;
        for (int k = 0; k < 10; k++)
            ch=in.get();
        for (; i < 16 && tag != 1; i++)
        {
            char tmp = 0;
            char res = 0;
            for (int j = 1; j >= 0; j--)
            {
                tmp = in.get();
                if (in.eof())
                {
                    tag = 1;
                    break;
                }
                else if (tmp == 'a')
                    res += char(10 * pow(16,j));
                else if(tmp == 'b')
                    res += char(11 * pow(16, j));
                else if (tmp == 'c')
                    res += char(12 * pow(16, j));
                else if (tmp == 'd')
                    res += char(13 * pow(16, j));
                else if (tmp == 'e')
                    res += char(14 * pow(16, j));
                else if (tmp == 'f')
                    res += char(15 * pow(16, j));
                else
                {
                    if (tmp >= '0' && tmp <= '9')
                    {
                        tmp -= '0';
                        res += tmp * char(pow(16, j));
                    }
                    else
                    {
                        tag = 2;
                        continue;
                    }
                        
                }
            }
            if (tag ==0)
                out << res;
            if (i == 7)
                for (int k = 0; k < 3; k++)
                    in.get();
            else
                in.get();
        }
        for (int k = 0; k < 4; k++)
            ch=in.get();
        for (int j = 0; j < i; j++)
            ch=in.get();
        for (int k = 0; k < 2; k++)
            ch = in.get();
    }
    in.close();
    return 0;
}


