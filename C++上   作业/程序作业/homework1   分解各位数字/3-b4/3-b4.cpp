/* 1953729 ��09 ����� */
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������һ��[0-100��)�������:" << endl;
	double N;
	cin >> N;
	double n = N / 10;
	int a = (int)(n) / 100000000;
	int b = (int)(n) / 10000000 % 10;
	int c = (int)(n) / 1000000 % 10;
	int d = (int)(n) / 100000 % 10;
	int e = (int)(n) / 10000 % 10;
	int f = (int)(n) / 1000 % 10;
	int g = (int)(n) / 100 % 10;
	int h = (int)(n) / 10 % 10;
	int i = (int)(n) % 10;
	int t = int(n);
	double x = n - t + 0.0004;
	int j = int(x * 10);
	int x1 = int(x * 100) % 10;
	int x2 = int(x * 1000) % 10;
	cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ʮλ   : " << i << endl;
	cout << "Բ     : " << j << endl;
	cout << "��     : " << x1 << endl;
	cout << "��     : " << x2 << endl;
	return 0;
}
