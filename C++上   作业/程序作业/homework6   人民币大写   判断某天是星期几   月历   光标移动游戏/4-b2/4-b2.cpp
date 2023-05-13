/* 1953729 ��09 ����� */
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int year, month, day;
	int zeller(int, int, int);
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			cout << "��������[1900-2100]���¡��գ�" << endl;
			cin >> year >> month >> day;
		}
		if (year < 1900 || year > 2100)
			cout << "��ݲ���ȷ������������" << endl;
		else if (month < 1 || month>12)
			cout << "�·ݲ���ȷ������������" << endl;
		if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
		{
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
			{
				if (month == 2 && day >= 1 && day <= 29)
					break;
				else if (month == 2)
					cout << "�ղ���ȷ������������" << endl;
			}
			if (!(year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
			{
				if (month == 2 && day >= 1 && day <= 28)
					break;
				else if (month == 2)
					cout << "�ղ���ȷ������������" << endl;
			}
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day >= 1 && day <= 31)
					break;
				else
					cout << "�ղ���ȷ������������" << endl;
			}
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day >= 1 && day <= 30)
					break;
				else
					cout << "�ղ���ȷ������������" << endl;
			}
		}
	}
	switch (zeller(year, month, day))
	{
		case 0:
			cout << "������";
			break;
		case 1:
			cout << "����һ";
			break;
		case 2:
			cout << "���ڶ�";
			break;
		case 3:
			cout << "������";
			break;
		case 4:
			cout << "������";
			break;
		case 5:
			cout << "������";
			break;
		case 6:
			cout << "������";
			break;
	}
	cout << endl;
	return 0;
}

int zeller(int year, int month, int day)
{
	int week;
	int w;
	int y;
	int c;
	if (month >= 3 && month <= 12)
	{
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	else if (month == 1)
	{
		year = year - 1;
		month = 13;
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	else if (month == 2)
	{
		year = year - 1;
		month = 14;
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	for (; w < 0;)
		w = w + 7;
	week = w % 7;
	return week;
}