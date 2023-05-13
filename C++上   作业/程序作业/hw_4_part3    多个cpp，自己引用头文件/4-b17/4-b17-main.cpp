/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;
int main()
{
	cout << "请输入一元二次方程的三个系数abc" << endl;
	cin >> a >> b >> c;
	void sub1();
	void sub2();
	void sub3();
	void sub4();
	if (a == 0)
		sub1();
	else
	{
		if (b * b - 4 * a * c > 1e-6)
			sub2();
		else if (b * b - 4 * a * c<1e-6 && b * b - 4 * a * c>-1e-6)
			sub3();
		else
			sub4();
	}
	return 0;
}