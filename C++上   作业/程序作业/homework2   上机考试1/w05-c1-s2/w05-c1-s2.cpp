/*1953729 ��09 �����*/ 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	int x, y, r, a, b;
	double x1, x2, y1, y2;
	cout << "������Բ��x����[-100..100] : ";
	cin >> x;
	cout << "������Բ��y����[-100..100] : ";
	cin >> y;
	cout << "������Բ�뾶r[1..100] : ";
	cin >> r;
	cout << "���������(�ɼ�)�Ƕ�[0..360] : ";
	cin >> a;
	cout << "�������յ�(�¼�)�Ƕ�[0..360] : ";
	cin >> b;
	x1 = x + sin(a / 180.0 * Pi) * r;
	y1 = y + cos(a / 180.0 * Pi) * r;
	x2 = x + sin(b / 180.0 * Pi) * r;
	y2 = y + cos(b / 180.0 * Pi) * r;
	cout << "�ɼ����� : (";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << x1 << ", " << y1 << ")" << endl;
	cout << "�¼����� : (";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << x2 << ", " << y2 << ")" << endl;
	return 0;
}
