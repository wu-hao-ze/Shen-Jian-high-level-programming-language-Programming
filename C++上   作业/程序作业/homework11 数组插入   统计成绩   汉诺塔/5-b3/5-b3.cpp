/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	int run(int);
	int cal(int, int, int);
	cout << "�������꣬�£���:" << endl;
	int year, month, day, sum = 0, t = 0;
	cin >> year >> month >> day;
	if (!(month >= 1 && month <= 12))
	{
		cout << "�������-�·ݲ���ȷ" << endl;
		t = 1;
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day > 31)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				t = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day > 30)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				t = 1;
			}
		}
		else
		{
			if (run(year))
			{
				if (day < 1 || day > 29)
				{
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					t = 1;
				}
			}
			else if (day < 1 || day > 28)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				t = 1;
			}
		}
	}
	if (t != 1)
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << cal(year, month, day) << "��" << endl;
	return 0;
}

int run(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int cal(int year, int month, int day)
{
	int sum=0;
	if (run(year))
	{
		int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < month - 1; i++)
			sum = sum + a[i];
		sum = sum + day;
	}
	else
	{
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < month - 1; i++)
			sum = sum + a[i];
		sum = sum + day;
	}	
	return sum;
}
