/* 1953609 软件 王灏廷 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include<iomanip>
#include <iostream>
#include<fstream>
using namespace std;

#define MAX_STU_NUM			150	//约定最大人数为150人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			20	//姓名的最大长度不超过9个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int condi_fro=0;
	int condi_aft=0;
	friend class stu_list;
public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
	
	/* 允许按需加入private数据成员和成员函数 */
	int sum = 0;
public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */
	void read_no(int i,int no)
	{
		stu[i].stu_no = no;
	}
	void read_name(int i, char name,int j)
	{
		stu[i].stu_name[j] = name;
	}
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	in.open(filename, ios::in);
	if (!in.is_open())
	{
		cout << "文件[" << filename << "]打开失败" << endl;
		in.close();
		return -1;
	}
	if (append != 0)
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			in >> a;
			if (in.fail())
				break;
			int seek = 0;
			for (int n = 0; n < sum; n++)
			{
				if (stu[n].stu_no == a)
				{
					stu[n].condi_aft = 1;
					seek = 1;
					break;
				}
			}
			int j = 0;
			in.get();
			for (;; j++)
			{
				char ch;
				ch = in.get();
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					if (seek == 0)
					{
						stu[sum].stu_name[j] = ch;
					}
				}
			}
			if (seek == 0)
			{
				stu[sum].stu_no = a;
				stu[sum].condi_aft = 1;
				stu[sum].stu_name[j] = '\0';
				sum++;
			}			
		}
	}	
	else
	{
		int tag = 0;
		int i = 0;
		for (; tag != 1; i++)
		{
			int a;
			in >> a;
			if (in.fail())
				break;
			read_no(i, a);
			int j = 0;
			in.get();
			for (;; j++)
			{
				char ch;
				ch = in.get();
				if (ch == '\n')
					break;
				else if (ch == EOF)
				{
					tag = 1;
					break;
				}
				else
				{
					read_name(i, ch, j);
				}
			}
			stu[i].stu_name[j] = '\0';
			stu[i].condi_fro = 1;
		}
		sum = i;
	}
	for (int k = 0; k < sum; k++)
	{
		for (int m = 0; m < sum - k - 1; m++)
		{
			if (stu[m].stu_no > stu[m + 1].stu_no)//从后面到i个元素两两比较，把小的不断上顶
			{
				stu_info tmp;
				tmp = stu[m];
				stu[m] = stu[m + 1];
				stu[m + 1] = tmp;
			}
		}
	}
	in.close();
	return 1;
}

int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "===========================================" << endl
		 << "序号 学号    姓名             第一轮 第二轮" << endl
		 << "===========================================" << endl;
	int num = 1;
	for (int i = 0; i < sum; i++,num++)
	{
		cout << setiosflags(ios::left)<< setw(5) << num << stu[i].stu_no << " " <<setw(17)<< stu[i].stu_name;
		if (stu[i].condi_fro == 1)
			cout << "Y      ";
		else
			cout << "/      ";
		if (stu[i].condi_aft == 0)
		{
			if (stu[i].condi_fro == 1)
				cout << "退课" << endl;
		}
		else
		{
			if (stu[i].condi_fro == 1)
				cout << "Y" << endl;
			else
				cout << "补选" << endl;
		}
	}
	cout << "===========================================" << endl;
	return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;
	
	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

#if 0
	/* 打开这个宏定义，可以打印首轮读入的选课名单，用于调试 */
	list.print("前一轮选课名单");
	cout << endl << endl;
#endif

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
