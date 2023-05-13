/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chistr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	switch (num)
	{
		case 0:
			if (flag_of_zero)
			{
				result = result + chistr[0];
				result = result + chistr[1];
			}
			break;
		case 1:
		{
			result = result + chistr[2];
			result = result + chistr[3];
		}
		break;
		case 2:
		{
			result = result + chistr[4];
			result = result + chistr[5];
		}
		break;
		case 3:
		{
			result = result + chistr[6];
			result = result + chistr[7];
		}
		break;
		case 4:
		{
			result = result + chistr[8];
			result = result + chistr[9];
		}
		break;
		case 5:
		{
			result = result + chistr[10];
			result = result + chistr[11];
		}
		break;
		case 6:
		{
			result = result + chistr[12];
			result = result + chistr[13];
		}
		break;
		case 7:
		{
			result = result + chistr[14];
			result = result + chistr[15];
		}
		break;
		case 8:
		{
			result = result + chistr[16];
			result = result + chistr[17];
		}
		break;
		case 9:
		{
			result = result + chistr[18];
			result = result + chistr[19];
		}
		break;
		default:
			;
			break;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	cout << "请输入一个[0-100亿)间的数:" << endl;
	double n;
	char whz[30] = "拾佰仟万亿圆角分整";
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
		result = result + whz[0];
		result = result + whz[1];
		if (b == 0)
		{
			result = result + whz[8];
			result = result + whz[9];
		}
	}
	if (b != 0)
	{
		daxie(b, 0);
		result = result + whz[8];
		result = result + whz[9];
	}
	if (c != 0)
	{
		daxie(c, 0);
		result = result + whz[4];
		result = result + whz[5];
		if (d == 0 && e == 0 && f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0)
		daxie(c, d);
	if (d != 0)
	{
		daxie(d, 0);
		result = result + whz[2];
		result = result + whz[3];
		if (e == 0 && f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0)
		daxie(d, e);
	if (e != 0)
	{
		daxie(e, 0);
		result = result + whz[0];
		result = result + whz[1];
		if (f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
		daxie(e, f);
	if (f != 0)
	{
		daxie(e, d);
		daxie(e, c);
		daxie(f, 0);
		result = result + whz[6];
		result = result + whz[7];
	}
	if (g != 0)
	{
		daxie(g, 0);
		result = result + whz[4];
		result = result + whz[5];
		if (h == 0 && i == 0 && j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
		else if (h == 0)
			daxie(h, g);
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			daxie(g, h);
		daxie(h, 0);
		result = result + whz[2];
		result = result + whz[3];
		if (i == 0 && j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
		if (i == 0 && j != 0)
			daxie(i, j);
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			daxie(h, i);
		daxie(i, 0);
		result = result + whz[0];
		result = result + whz[1];
		if (j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			daxie(i, j);
		daxie(j, 0);
		result = result + whz[10];
		result = result + whz[11];
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
	{
		result = result + whz[10];
		result = result + whz[11];
	}
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
	{
		daxie(x1, 1);
		result = result + whz[10];
		result = result + whz[11];
	}
	if (x1 == 0 && x2 == 0)
	{
		result = result + whz[16];
		result = result + whz[17];
	}
	if (x1 != 0)
	{
		daxie(x1, 0);
		result = result + whz[12];
		result = result + whz[13];
		if (x2 == 0)
		{
			result = result + whz[16];
			result = result + whz[17];
		}
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			daxie(x1, x2);
		daxie(x2, 0);
		result = result + whz[14];
		result = result + whz[15];
	}
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}