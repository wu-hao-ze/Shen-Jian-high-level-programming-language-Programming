/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cmath>
using namespace std;
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