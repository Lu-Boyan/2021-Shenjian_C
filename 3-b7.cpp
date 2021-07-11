/*1953609 Èí¼ş Íõå°Í¢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a;
	int tag = 0;
	cout << "ÇëÊäÈë[0,100ÒÚ£©Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
	cout << "´óĞ´½á¹ûÊÇ£º" << endl;
	const int a1 = static_cast<int>(a / 10);
	const int billion = a1 / 100000000;
	const int hundred_million = a1 / 10000000 % 10;
	const int ten_million = a1 / 1000000 % 10;
	const int million = a1 / 100000 % 10;
	const int hundred_thousand = a1 / 10000 % 10;
	const int ten_thousand = a1 / 1000 % 10;
	const int thousand = a1 / 100 % 10;
	const int hundred = a1 / 10 % 10;
	const int ten = a1 % 10;
	const int yuan = static_cast<int>(floor((a / 10.0 - floor(a / 10)) * 10+1e-7));
	const int jiao = static_cast<int>(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = static_cast<int>(round((a - floor(a)) * 100)) % 10;
	if (billion != 0)
	{
		switch (billion)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
		if (hundred_million == 0)
			cout << "ÒÚ";
	}
	if (hundred_million != 0)
	{
		switch (hundred_million)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "ÒÚ";
	}
	if (ten_million != 0)
	{
		switch (ten_million)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
			default:
				break;
		}
		cout << "Çª";
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			cout << "Íò";
	}
	else if ((million != 0 || hundred_thousand != 0 || ten_thousand != 0))
		if(hundred_million!=0||billion!=0)
		cout << "Áã";
	if (million != 0)
	{
		switch (million)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "°Û";
		if (hundred_thousand== 0&&ten_thousand==0)
	        cout << "Íò";
	}
	else if (ten_million != 0)
		if (hundred_thousand != 0 || ten_thousand != 0)
		    cout << "Áã";
	if (hundred_thousand != 0)
	{
		switch (hundred_thousand)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
		if (ten_thousand == 0)
			cout << "Íò";
	}
	else if (million != 0 && ten_thousand != 0)
		cout << "Áã";
	if (ten_thousand != 0)
	{
		switch (ten_thousand)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Íò";
	}
	if (thousand != 0)
	{
		switch (thousand)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Çª";
	}
	else if (hundred != 0 || ten != 0 || yuan != 0)
		if(billion!=0||hundred_million!=0||ten_million!=0|| million != 0 || hundred_thousand != 0 || ten_thousand != 0)
	        cout << "Áã";
	if (hundred != 0)
	{
		switch (hundred)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "°Û";
	}
	else if(thousand!=0)
		if(ten!=0||yuan!=0)
		cout << "Áã";
	if (ten != 0)
	{
		switch (ten)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ê°";
	}
	else if (hundred != 0 && yuan!=0)
		cout << "Áã";
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag = 1;
	}
	if (yuan != 0)
	{
		switch (yuan)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "Ô²";
	}
	else if (tag==1)
	{
        cout << "Ô²";
	}	
	if (jiao == 0 && fen == 0)
	{
		if (yuan == 0)
		{
			if (billion == 0 && hundred_million == 0 && ten_million == 0)
			{
				if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
				{
					if (thousand == 0 && hundred == 0 && ten == 0)
					{
						cout << "ÁãÔ²";
					}
				}
			}
		}
		cout << "Õû";
	}
	if (jiao != 0)
	{
		switch (jiao)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "½Ç";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag == 1 || yuan != 0)
			cout << "Áã";
	}
	if (fen != 0)
	{
		switch (fen)
		{
			case 1:
				cout << "Ò¼";
				break;
			case 2:
				cout << "·¡";
				break;
			case 3:
				cout << "Èş";
				break;
			case 4:
				cout << "ËÁ";
				break;
			case 5:
				cout << "Îé";
				break;
			case 6:
				cout << "Â½";
				break;
			case 7:
				cout << "Æâ";
				break;
			case 8:
				cout << "°Æ";
				break;
			case 9:
				cout << "¾Á";
				break;
			default:
				break;
		}
		cout << "·Ö";
	}
	else if (fen == 0 && jiao != 0)
		cout << "Õû";
	cout << endl;
	return 0;
}
