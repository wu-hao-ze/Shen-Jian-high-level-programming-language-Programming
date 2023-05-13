 /* 1953729 信09 吴浩泽 */
#include <iostream>
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
	cout << "请输入一个[0-100亿)间的数:" << endl;
	double n;
	cin >> n;
	int a = (int)((long long int)(n) / 1000000000);
	int b = (int)((long long int)(n) / 100000000 % 10);
	int c = (int)((long long int)(n) / 10000000 % 10);
	int d = (int)((long long int)(n) / 1000000 % 10);
	int e = (int)((long long int)(n) / 100000 % 10);
	int f = (int)((long long int)(n) / 10000 % 10);
	int g = (int)((long long int)(n) / 1000 % 10);
	int h = (int)((long long int)(n) / 100 % 10);
	int i = (int)((long long int)(n) / 10 % 10);
	int j = (int)((long long int)(n) % 10);
	long long int t = (long long int)(n);
	double x = n - t + 0.0004;
	int x1 = (int)(x * 10) % 10;
	int x2 = (int)(x * 100) % 10;
	cout << "大写结果是:" << endl;
	if (a != 0)
	{
		daxie(a, 0);
		cout << "拾";
		if (b == 0)
			cout << "亿";
	}
	if (b != 0)
	{
		daxie(b, 0);
		cout << "亿";
	}
	if (c != 0)
	{
		daxie(c, 0);
		cout << "仟";
		if (d == 0 && e == 0 && f == 0)
			cout << "万";
	}
	if ((a != 0 || b != 0) && c == 0)
		daxie(c, d);
	if (d != 0)
	{
		daxie(d, 0);
		cout << "佰";
		if (e == 0 && f == 0)
			cout << "万";
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0)
		daxie(d, e);
	if (e != 0)
	{
		daxie(e, 0);
		cout << "拾";
		if (f == 0)
			cout << "万";
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
		daxie(e, f);
	if (f != 0)
	{
		daxie(e,d);
		daxie(e,c);
		daxie(f, 0);
		cout << "万";
	}
	if (g != 0)
	{
		daxie(g, 0);
		cout << "仟";
		if (h == 0 && i == 0 && j == 0)
			cout << "圆";
		else if (h == 0)
			daxie(h, g);
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			daxie(g, h);
		daxie(h, 0);
		cout << "佰";
		if (i == 0 && j == 0)
			cout << "圆";
		if (i == 0 && j != 0)
			daxie(i, j);
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			daxie(h, i);
		daxie(i, 0);
		cout << "拾";
		if (j == 0)
			cout << "圆";
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			daxie(i, j);
		daxie(j, 0);
		cout << "圆";
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		cout << "圆";
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
	{	
		daxie(x1, 1);
		cout << "圆";
	}
	if (x1 == 0 && x2 == 0)
		cout << "整";
	if (x1 != 0)
	{
		daxie(x1, 0);
		cout << "角";
		if (x2 == 0)
			cout << "整";
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			daxie(x1, x2);
		daxie(x2, 0);
		cout << "分";
	}
	cout << endl;
	return 0;
}
