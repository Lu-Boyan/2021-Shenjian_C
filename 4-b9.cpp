/*1953609 ���� ���͢*/
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ�������̬�ֲ�����
   3��������������������
   4�������������������κ���ʽ��ѭ����while��do-while��for��if-goto��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�������n�ֽ�����
	 ���������
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2��������ʹ��64λ����
   ***************************************************************************/
void convert(int n)
{
	if (n < 0)
	{
		if (n == -2147483647-1)
		{
			convert(n / 10);
			cout << char('0' - (n % 10)) << " ";
			return;
		}
		else
		{
			cout << "- ";
			n = 0 - n;
		}
	}
	if (n > 0)
	{
		convert(n / 10);
		cout << char('0'+(n % 10)) << " ";
	}
	
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int n;
	cout << "������һ������" << endl;
	cin >> n;

	convert(n);
	cout << endl;

	return 0;
}