/*1953729 ��09 �����*/
#include <iostream>
#include <cmath>
using namespace std;

double definite_integration(double (*p)(double), int n, double low, double high)
{
	double value = 0;
	double area = (high - low) / n;
	for (int i = 1; i <= n; i++)
	{
		value += (*p)(low + i * area) * area;
	}
	cout << "dx[" << low << "~" << high << "/n=" << n << "] : ";
	return value;
}
int main()
{
	int n;
	double low, high, value;
	cout << "������sinxdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	cout << "sin";
	value = definite_integration(sin, n, low, high); //sin Ϊcmath �����к���
	cout << value << endl;
	cout << "������cosxdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	cout << "cos";
	value = definite_integration(cos, n, low, high); //cos Ϊcmath �����к���
	cout << value << endl;
	cout << "������e^xdx�����ޡ����޼����仮������" << endl;
	cin >> low >> high >> n;
	cout << "e^x";
	value = definite_integration(exp, n, low, high); //exp Ϊcmath �����к���
	cout << value << endl;
	return 0;
}