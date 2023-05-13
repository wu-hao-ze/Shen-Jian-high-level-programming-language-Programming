/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cmath>
#include "4-b16.h"
using namespace std;
int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数abc" << endl;
	cin >> a >> b >> c;

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