/*1953609 软件 王灏廷*/
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int a[9][9];
	int tag = -1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			while (1)
			{
				cin >> a[i][j];
				if (cin.fail())
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(2147483647, '\n');
					continue;
				}
				else if (a[i][j] < 1 || a[i][j]>9)
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(2147483647, '\n');
					continue;
				}
				else
					break;
			}
		}
	}
	int row[9] = { 0 };
	int col[9] = { 0 };
	int block[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			switch (a[i][j])
			{
				case 1:
					row[0]++;
					break;
				case 2:
					row[1]++;
					break;
				case 3:
					row[2]++;
					break;
				case 4:
					row[3]++;
					break;
				case 5:
					row[4]++;
					break;
				case 6:
					row[5]++;
					break;
				case 7:
					row[6]++;
					break;
				case 8:
					row[7]++;
					break;
				case 9:
					row[8]++;
					break;
				default:
					break;
			}
		}
		for (int j = 0; j < 9; j++)
		{
			if (row[j] > i + 1)
			{
				cout << "不是数独的解" << endl;
				tag = 1;
				break;
			}
		}
		if (tag == 1)
			break;
	}
	if (tag != 1)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				switch (a[j][i])
				{
					case 1:
						col[0]++;
						break;
					case 2:
						col[1]++;
						break;
					case 3:
						col[2]++;
						break;
					case 4:
						col[3]++;
						break;
					case 5:
						col[4]++;
						break;
					case 6:
						col[5]++;
						break;
					case 7:
						col[6]++;
						break;
					case 8:
						col[7]++;
						break;
					case 9:
						col[8]++;
						break;
					default:
						break;
				}
			}
			for (int j = 0; j < 9; j++)
			{
				if (col[j] > i + 1)
				{
					cout << "不是数独的解" << endl;
					tag = 1;
					break;
				}
			}
			if (tag == 1)
				break;
		}
	}
	if (tag != 1)
	{
		for (int i = 0; i < 27; i++)
		{
			if (i < 9)
			{
				for (int j = 0; j < 3; j++)
				{
					switch (a[i % 9][j])
					{
						case 1:
							block[0]++;
							break;
						case 2:
							block[1]++;
							break;
						case 3:
							block[2]++;
							break;
						case 4:
							block[3]++;
							break;
						case 5:
							block[4]++;
							break;
						case 6:
							block[5]++;
							break;
						case 7:
							block[6]++;
							break;
						case 8:
							block[7]++;
							break;
						case 9:
							block[8]++;
							break;
						default:
							break;
					}
				}
			}
			if (i >= 9 && i < 18)
			{
				for (int j = 3; j < 6; j++)
				{
					switch (a[i % 9][j])
					{
						case 1:
							block[0]++;
							break;
						case 2:
							block[1]++;
							break;
						case 3:
							block[2]++;
							break;
						case 4:
							block[3]++;
							break;
						case 5:
							block[4]++;
							break;
						case 6:
							block[5]++;
							break;
						case 7:
							block[6]++;
							break;
						case 8:
							block[7]++;
							break;
						case 9:
							block[8]++;
							break;
						default:
							break;
					}
				}
			}
			if (i >= 18)
			{
				for (int j = 6; j < 9; j++)
				{
					switch (a[i % 9][j])
					{
						case 1:
							block[0]++;
							break;
						case 2:
							block[1]++;
							break;
						case 3:
							block[2]++;
							break;
						case 4:
							block[3]++;
							break;
						case 5:
							block[4]++;
							break;
						case 6:
							block[5]++;
							break;
						case 7:
							block[6]++;
							break;
						case 8:
							block[7]++;
							break;
						case 9:
							block[8]++;
							break;
						default:
							break;
					}
				}
			}
			if ((i + 1) % 3 == 0)
			{
				for (int j = 0; j < 10; j++)
				{
					if (block[j] > (i + 1) / 3)
					{
						cout << "不是数独的解" << endl;
						tag = 1;
						break;
					}
				}
			}
			if (tag == 1)
				break;
		}
	}
	if (tag != 1)
		cout << "是数独的解" << endl;
	return 0;
}

