/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	double x;
	cin >> x;
	int a, b, c, d, e, f, g, h, i, j, sum;
	int t = (int)x;
	a = (int)(t / 50.0);
	int a1 = t % 50;
	b = (int)(a1 / 20.0);
	int b1 = a1 % 20;
	c = (int)(b1 / 10.0);
	int c1 = b1 % 10;
	d = (int)(c1 / 5.0);
	int d1 = c1 % 5;
	e = d1;
	int y = (int)((x - t + 0.0005) * 100);
	f = (int)(y / 50.0);
	int f1 = y % 50;
	g = (int)(f1 / 10.0);
	int g1 = f1 % 10;
	h = (int)(g1 / 5.0);
	int h1 = g1 % 5;
	i = (int)(h1 / 2.0);
	int i1 = h1 % 2;
	j = i1; 
	sum = a + b + c + d + e + f + g + h + i + j;
	cout << "��" << sum << "�����㣬�������£�" << endl;
	if (a != 0)
		cout << "50Ԫ : " << a << "��" << endl;
	if (b != 0)
		cout << "20Ԫ : " << b << "��" << endl;
	if (c != 0)
		cout << "10Ԫ : " << c << "��" << endl;
	if (d != 0)
		cout << "5Ԫ  : " << d << "��" << endl;
	if (e != 0)
		cout << "1Ԫ  : " << e << "��" << endl;
	if (f != 0)
		cout << "5��  : " << f << "��" << endl;
	if (g != 0)
		cout << "1��  : " << g << "��" << endl;
	if (h != 0)
		cout << "5��  : " << h << "��" << endl;
	if (i != 0)
		cout << "2��  : " << i << "��" << endl;
	if (j != 0)
		cout << "1��  : " << j << "��" << endl;
	return 0;
}
