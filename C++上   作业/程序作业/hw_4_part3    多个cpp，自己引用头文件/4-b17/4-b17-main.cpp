/* 1953729 ��09 ����� */
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;
int main()
{
	cout << "������һԪ���η��̵�����ϵ��abc" << endl;
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