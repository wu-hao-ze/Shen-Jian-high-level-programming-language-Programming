/*1953729 ��09 �����*/
#include<iostream>
using namespace std;
int main()
{
	int x1, x2, y1, y2;
	cout << "�������1��������� : ";
	cin >> x1 >> y1;
	cout << "�������2��������� : ";
	cin >> x2 >> y2;
	double k, a, b;
	k = double((y2 - y1)) / (x2 - x1);
	b = k * (-x1) + y1;
	a = x1 + 1.0 / k * (-y1);
	cout << a << ' ' << b << endl;
	if (x1 == x2) 
	{
		if(x1<0)
		cout << "ƽ����y�ᣬ�ڶ�������" << endl;
		else 
		cout << "ƽ����y�ᣬ��һ������" << endl;
	}
	else 
	{
		if (k != 0)
		{
			if (a > 0 && b > 0)
				cout << "�ڵ�һ����" << endl;
			else if (a < 0 && b > 0)
				cout << "�ڵڶ�����" << endl;
			else if (a < 0 && b < 0)
				cout << "�ڵ�������" << endl;
			else if (a > 0 && b < 0)
				cout << "�ڵ�������" << endl;
		}
		else
		{
			if (b > 0)
				cout << "ƽ����x�ᣬ��һ������" << endl;
			else
				cout << "ƽ����x�ᣬ����������" << endl;
		}
	}
	return 0;
}