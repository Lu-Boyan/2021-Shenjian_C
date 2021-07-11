/*1953609 软件 王灏廷*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const double a = 123456.789012345;
    cout << "==================================================" << endl;
    cout << "0         " << "1         " << "2         " << "3         " << "4         " << endl;
    cout << "01234567890123456789012345678901234567890123456789" << endl;
    cout << "==================================================" << endl;
    cout << setprecision(6) << a << "#" << endl;
    cout << setprecision(5)<< a << "#" << endl;
    cout << resetiosflags(ios::scientific);
    cout << setiosflags(ios::fixed) << setprecision(6) << a << "#" << endl;
    cout << setw(20) << setiosflags(ios::fixed) << setprecision(6) << a << ",";
    cout << setw(20) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(12) << a << "#" << endl;
    cout << setw(20) << setiosflags(ios::fixed) << setprecision(5) << a << ",";
    cout << resetiosflags(ios::fixed);
    cout << resetiosflags(ios::left);
    cout << setw(20) << setprecision(6) << a << "#" << endl;
    cout << setw(15) << setiosflags(ios::left) << setiosflags(ios::scientific) << setprecision(6) << a << ",";
    cout << resetiosflags(ios::left);
    cout << setw(15) << setiosflags(ios::scientific) << setprecision(4) << a << "#" << endl;
    cout << setw(15) << setiosflags(ios::scientific) << setprecision(4) << a << ",";
    cout << resetiosflags(ios::left);
    cout << setw(15) << setiosflags(ios::left) << setiosflags(ios::scientific) << setprecision(6) << a << "#" << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
