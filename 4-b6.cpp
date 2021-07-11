//1953609 ���� ���͢//
#include <iostream>
#include <cmath>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ�������̬�ֲ�����
   3��������������������
   4�������������������κ���ʽ��ѭ����while��do-while��for��if-goto��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�����n��legendre����ʽ��ֵ
	 ���������
	 �� �� ֵ��
	 ˵    �������������βΡ��������;���׼��
   ***************************************************************************/
double legendre(double x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
	{
		double a = 0;
		a = ((2 * n - 1) * x * legendre(x, n - 1) - (n - 1) * legendre(x, n - 2)) / n;
		return a;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����������롢���õݹ麯�������
***************************************************************************/
int main()
{
	cout << "����legendre,������x��n��ֵ" << endl;
	double x;
	int n;
	cin >> x >> n;
	double ans;
	ans = legendre(x, n);
	cout << "legendre[" << n << "](" << x << ")=" << ans<<endl;
	return 0;
}

