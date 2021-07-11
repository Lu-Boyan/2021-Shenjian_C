/*1953609 软件 王灏廷*/
#include <iostream>
#include<math.h>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	double a;
	int tag = 0;
	cout << "请输入[0,100亿）之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是：" << endl;
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
	const int yuan = static_cast<int>(floor((a / 10.0 - floor(a / 10)) * 10 + 1e-7));
	const int jiao = static_cast<int>(round((a - floor(a)) * 100)) / 10 % 10;
	const int fen = static_cast<int>(round((a - floor(a)) * 100)) % 10;
	daxie(billion,0);
	if (billion != 0)
	{
		cout << "拾";
		if (hundred_million == 0)
			cout << "亿";
	}
	daxie(hundred_million, 0);
	if(hundred_million!=0)
		cout << "亿";
	if (ten_million != 0)
	{
		daxie(ten_million, 0);
		cout << "仟";
		if (million == 0 && hundred_thousand == 0 && ten_thousand == 0)
			cout << "万";
	}
	else
		tag = 1;
	if (million != 0)
	{
		if (hundred_million != 0 || billion != 0)
			daxie(0, tag);
		daxie(million, tag);
		cout << "佰";
		if (hundred_thousand == 0 && ten_thousand == 0)
			cout << "万";
		tag = 0;
	}
	else
		tag = 1;
	if (hundred_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0)
			daxie(0, tag);
		daxie(hundred_thousand, tag);
		cout << "拾";
		if (ten_thousand == 0)
			cout << "万";
		tag = 0;
	}
	else
		tag = 1;
	if (ten_thousand != 0)
	{
		if (hundred_million != 0 || billion != 0 || million != 0|| hundred_thousand != 0)
			daxie(0, tag);
		daxie(ten_thousand, tag);
		cout << "万";
		tag = 0;
	}
	tag = 0;
	if (thousand != 0)
	{
		daxie(thousand, 0);
		cout << "仟";
	}
	else
		tag = 1;
	if (hundred != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0|| thousand != 0)
			daxie(0, tag);
		daxie(hundred, tag);
		cout << "佰";
		tag = 0;
	}
	else
		tag = 1;
	if (ten != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0||hundred!=0)
			daxie(0, tag);
		daxie(ten, tag);
		cout << "拾";
		tag = 0;
	}
	else
		tag = 1;
	int tag_yuan = 0;
	if (yuan != 0 || billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
	{
		tag_yuan = 1;
	}
	if (yuan != 0)
	{
		if (billion != 0 || hundred_million != 0 || ten_million != 0 || million != 0 || hundred_thousand != 0 || ten_thousand != 0 || thousand != 0 || hundred != 0 || ten != 0)
			daxie(0, tag);
		daxie(yuan, tag);
		cout << "圆";
	}
	else if (tag_yuan == 1)
	{
		cout << "圆";
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
						daxie(0, 1);
						cout << "圆";
					}
				}
			}
		}
		cout << "整";
	}
	tag = 0;
	if (jiao != 0)
	{
		daxie(jiao, tag);
		cout << "角";
	}
	else if (jiao == 0 && fen != 0)
	{
		if (tag_yuan == 1)
			daxie(0,1);
	}
	if (fen != 0)
	{
		daxie(fen, tag);
		cout << "分";
	}
	else if (fen == 0 && jiao != 0)
		cout << "整";
	cout << endl;
	return 0;
}
