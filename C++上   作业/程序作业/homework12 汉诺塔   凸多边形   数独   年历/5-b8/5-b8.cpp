/* 1953729 ��09 ����� */
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x[10], y[10];
	int n;
	double a, b, c, s, sum = 0;
	int t;
	double dist(double, double, double, double);
	double square(double, double, double);
	while (1)
	{
		cout << "���������εĶ�������(4-7)" << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10240, '\n');
			cout << "���������εĶ�������(4-7)" << endl;
			cin >> n;
		}
		if (n >= 4 && n <= 7)
			break;
		else
		{
			cin.clear();
			cin.ignore(10240, '\n');
		}
	}
	cin.clear();
	cin.ignore(10240, '\n');
	cout << "�밴˳ʱ��/��ʱ�뷽������" << n << "�������x,y���꣺" << endl;
	for (int i = 1; i <= n; i++)
	{
		while (1)
		{

			cout << "�������" << i << "�����������" << endl;
			cin >> x[i - 1];
			cin >> y[i - 1];
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(10240, '\n');
				cout << "�������" << i << "�����������" << endl;
				cin >> x[i - 1];
				cin >> y[i - 1];
			}
			break;
		}
		cin.clear();
		cin.ignore(10240, '\n');
	}
	if ((x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]) > 0)
	{
		for (int i = 2; i <= n - 2; i++)
			if ((x[i] - x[i - 1]) * (y[i + 1] - y[i]) - (x[i + 1] - x[i]) * (y[i] - y[i - 1]) <= 0)
				t = 1;
		if ((x[n - 1] - x[n - 2]) * (y[0] - y[n - 1]) - (x[0] - x[n - 1]) * (y[n - 1] - y[n - 2]) <= 0)
			t = 1;
	}
	if ((x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]) < 0)
	{
		for (int i = 2; i <= n - 2; i++)
			if ((x[i] - x[i - 1]) * (y[i + 1] - y[i]) - (x[i + 1] - x[i]) * (y[i] - y[i - 1]) >= 0)
				t = 1;
		if ((x[n - 1] - x[n - 2]) * (y[0] - y[n - 1]) - (x[0] - x[n - 1]) * (y[n - 1] - y[n - 2]) >= 0)
			t = 1;
	}
	if ((x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]) == 0)
		t = 1;
	if (t == 1)
		cout << "����͹" << n << "����" << endl;
	else
	{
		for (int i = 1; i < n - 1; i++)
		{
			a = dist(x[i], y[i], x[0], y[0]);
			b = dist(x[i + 1], y[i + 1], x[i], y[i]);
			c = dist(x[i + 1], y[i + 1], x[0], y[0]);
			s = square(a, b, c);
			sum = sum + s;
		}
		cout << "͹" << n << "���ε����=" << sum << endl;
	}
	return 0;
}

double dist(double x1, double y1, double x2, double y2)
{
	double C;
	C = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return C;
}
double square(double a, double b, double c)
{
	double S;
	double p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}
