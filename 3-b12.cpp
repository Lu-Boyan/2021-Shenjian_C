/*���� 1953609 ���͢*/
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "������x��ֵ[0-100] : ";
		cin >> x;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (!cin.good())
		{
			while (getchar() != '\n')
				;
			cin.clear();
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	cout << "x=" << x << endl;

	return 0;
}