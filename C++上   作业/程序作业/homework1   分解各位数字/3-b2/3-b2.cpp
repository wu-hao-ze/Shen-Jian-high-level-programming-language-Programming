/* 1953729 ��09 ����� */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������뾶�͸߶�"<<endl;
	double r, h;
	cin >> r >> h;
	const double Pi = 3.14159;
	double C,S1,S2,V1,V2;
	C = 2 * Pi * r;
	S1 = Pi * r * r;
	S2 = 4 * Pi * r * r;
	V1 = 4 * Pi * r * r * r / 3;
	V2 = Pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Բ�ܳ�     : " << C<<endl;
	cout << "Բ���     : " << S1<<endl;
	cout << "Բ������ : " << S2<<endl;
	cout << "Բ�����   : " << V1<<endl;
	cout << "Բ�����   : " << V2<<endl;
	return 0;
}