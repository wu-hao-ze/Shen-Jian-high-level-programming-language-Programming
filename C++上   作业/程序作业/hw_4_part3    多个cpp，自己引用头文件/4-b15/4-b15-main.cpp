/* 1953729 ��09 ����� */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "������һԪ���η��̵�����ϵ��abc" << endl;
	cin >> a >> b >> c;
	void sub1();
	void sub2(double, double, double);
	void sub3(double, double);
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