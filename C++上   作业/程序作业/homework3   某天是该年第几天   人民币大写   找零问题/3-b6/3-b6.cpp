/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	cout << "�������꣬�£���:" << endl;
	int year, month, day, sum = 0, t = 0;
	cin >> year >> month >> day;
	if (!(month >= 1 && month <= 12))
	{
		t = 1;
		cout << "�������-�·ݲ���ȷ" << endl;
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day>31)
			{
				t = 1; 
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day>30)
			{
				t = 1; 
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
		}
		else
		{ 
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day < 1 || day > 29)
				{
					t = 1; 
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				}
			}
			else if (day < 1 || day > 28)
			{
				t = 1;
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
		}
	}
	if (t == 0) 
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			switch (month)
			{
				case 1:
					sum = day;
					break;
				case 2:
					sum = 31 + day;
					break;
				case 3:
					sum = 31 + 29 + day;
					break;
				case 4:
					sum = 31 + 29 + 31 + day;
					break;
				case 5:
					sum = 31 + 29 + 31 + 30 + day;
					break;
				case 6:
					sum = 31 + 29 + 31 + 30 + 31 + day;
					break;
				case 7:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + day;
					break;
				case 8:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day;
					break;
				case 9:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
					break;
				case 10:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
					break;
				case 11:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
					break;
				case 12:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
					break;
			}
			cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << sum << "��" << endl;
		}
		else
		{
			switch (month)
			{
				case 1:
					sum = day;
					break;
				case 2:
					sum = 31 + day;
					break;
				case 3:
					sum = 31 + 28 + day;
					break;
				case 4:
					sum = 31 + 28 + 31 + day;
					break;
				case 5:
					sum = 31 + 28 + 31 + 30 + day;
					break;
				case 6:
					sum = 31 + 28 + 31 + 30 + 31 + day;
					break;
				case 7:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + day;
					break;
				case 8:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day;
					break;
				case 9:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
					break;
				case 10:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
					break;
				case 11:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
					break;
				case 12:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
					break;
			}
			cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << sum << "��" << endl;
		}
	}
	return 0;
}