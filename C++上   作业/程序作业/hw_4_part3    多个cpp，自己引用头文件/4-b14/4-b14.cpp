/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数abc" << endl;
	cin >> a >> b >> c;
	void sub1();
	void sub2(double, double, double);
	void sub3(double,double);
	void sub4(double, double, double);
	if (a == 0)
		sub1();
	else
	{
		if (b * b - 4 * a * c > 1e-6)
			sub2(a, b, c);
		else if (b * b - 4 * a * c<1e-6 && b * b - 4 * a * c>-1e-6)
			sub3(a, b);
		else
			sub4(a, b, c);
	}
	return 0;
}

void sub1()
{
	cout << "不是一元二次方程" << endl;
}
void sub2(double a, double b, double c)
{
	double x1, x2;
	cout << "有两个不等实根:" << endl;
	if (a > 0)
	{
		x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	}
	if (a < 0)
	{
		x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	}
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
void sub3(double a, double b)
{
	cout << "有两个相等实根:" << endl;
	double x = -b / (2 * a);
	cout << "x1=x2=" << x << endl;
}
void sub4(double a, double b, double c)
{
	cout << "有两个虚根:" << endl;
	if (sqrt(-b * b + 4 * a * c) / (2 * a) == 1 || sqrt(-b * b + 4 * a * c) / (2 * a) == -1)
		if (b == 0)
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
		else
		{
			cout << "x1=" << -b / (2 * a) << "+" << "i" << endl;
			cout << "x2=" << -b / (2 * a) << "-" << "i" << endl;
		}
	else
	{
		if (b == 0)
		{
			if (a > 0)
			{
				cout << "x1=" << sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
				cout << "x2=" << -sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
			}
			else
			{
				cout << "x1=" << -sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
				cout << "x2=" << sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
			}
		}
		else
		{
			if (a > 0)
			{
				cout << "x1=" << -b / (2 * a) << "+" << sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
				cout << "x2=" << -b / (2 * a) << "-" << sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
			}
			else
			{
				cout << "x1=" << -b / (2 * a) << "+" << -sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
				cout << "x2=" << -b / (2 * a) << "-" << -sqrt(-b * b + 4 * a * c) / (2 * a) << "i" << endl;
			}
		}
	}
}