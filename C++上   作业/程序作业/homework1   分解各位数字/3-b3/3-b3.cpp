/* 1953729 ��09 ����� */
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;
	int n;
	cin >> n;
	int a = n / 10000;
	int b = n / 1000 % 10;
	int c = n / 100 % 10;
	int d = n / 10 % 10;
	int e = n % 10;
	cout << "��λ : " << a << endl;
	cout << "ǧλ : " << b << endl;
	cout << "��λ : " << c << endl;
	cout << "ʮλ : " << d << endl;
	cout << "��λ : " << e << endl;
	return 0;
}