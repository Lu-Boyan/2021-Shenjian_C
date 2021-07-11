/* 1953609 软件 王灏廷 */
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

int main()
{
    ifstream in;
    cerr << "文件名以下形式均可以：" << endl
        << "    a.txt：不带路径形式" << endl
        << "    ..\\data\\b.dat：相对路径形式" << endl
        << "    C:\\Windows\\System32\\c.dat：绝对相对路径形式" << endl
        << "请输入文件名: ";
    char str[100];
    cin >> str;
    in.open(str, ios::in | ios::binary);
    if (!in.is_open())
    {
        cerr << "文件" << str << "打开失败!" << endl;
        in.close();
        return -1;
    }
    int serial = 0x00000000;
    int tag = 0;
    while (tag!=1)
    {
        char tmp[17] = { '0' };
        int ch;
        int i = 0;
        for (; i < 16 && !in.eof(); i++)
        {
            ch = in.get();
            if (in.eof())
            {
                tag = 1;
                if (i != 0)
                {
                    for (int k = i; k < 16; k++)
                        cout << "   ";
                    if (i <= 8)
                        cout << "  ";
                }              
                break;
            }     
            else
            {
                if (i == 0)
                {
                    cout << setfill('0') << setw(8) << hex << serial << "  ";
                    serial += 0x10;
                }
                tmp[i] = char(ch);
                if (i == 8)
                    cout << "- ";
                cout << setfill('0') << setw(2) << hex << ch;
            }                
            cout << " ";
        }
        if (i != 0)
            cout << "    ";
        for (int j = 0; j < i; j++)
        {
            if (tmp[j] >= 33 && tmp[j] <= 126)
                cout << tmp[j];
            else
                cout << ".";
        }
        if (i != 0)
            cout << endl;
    }
    in.close();
    return 0;
}