/* 1953729 ��09 ����� */
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int year, month, i, x, a = 0;
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;  
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			cout << "���������(2000-2030)���·�(1-12) : ";
			cin >> year >> month;
		}
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			cout << "����Ƿ�������������" << endl;
	}
	cout << "������" << year << "��" << month << "��" << "1�յ�����(0-6��ʾ������-������) : ";
	while (1)
	{
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			cout << "������" << year << "��" << month << "��" << "1�յ�����(0-6��ʾ������-������) : ";
			cin >> year >> month;
		}
		if (x >= 0 && x <= 6)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			cout << "������" << year << "��" << month << "��" << "1�յ�����(0-6��ʾ������-������) : ";
		}
	}
	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	switch (x)
	{
		case 0:      
			cout << "   1       2       3       4       5       6       7" << endl;
			break;
		case 1:
			cout << "           1       2       3       4       5       6" << endl;
			break;
		case 2:
			cout << "                   1       2       3       4       5" << endl;
			break;
		case 3:
			cout << "                           1       2       3       4" << endl;
			break;
		case 4:
			cout << "                                   1       2       3" << endl;
			break;
		case 5:
			cout << "                                           1       2" << endl;
			break;
		case 6:
			cout << "                                                   1" << endl;
			break;
	}
	        cout << "   ";
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		for (i = 8 - x; i <= 31; i++)
		{
			cout << i;
			a = a + 1;
			if (a % 7 == 0)
			{
				cout << endl;
				if (i <= 8)
					cout << "   ";
				else
					cout << "  ";
				continue;
			}
			if(i<=8)
			    cout << "       ";
			else
				cout << "      ";
		}
	}
	else if(month == 4|| month == 6|| month == 9|| month == 11)
	{
		for (i = 8 - x; i <= 30; i++)
		{
			cout << i;
			a = a + 1;
			if (a % 7 == 0)
			{
				cout << endl;
				if (i <= 8)
					cout << "   ";
				else
					cout << "  ";
				continue;
			}
			if (i <= 8)
				cout << "       ";
			else
				cout << "      ";
		}
	}
	else
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			for (i = 8 - x; i <= 29; i++)
			{
				cout << i;
				a = a + 1;
				if (a % 7 == 0)
				{
					cout << endl;
					if (i <= 8)
						cout << "   ";
					else
						cout << "  ";
					continue;
				}
				if (i <= 8)
					cout << "       ";
				else
					cout << "      ";
			}
		else
			for (i = 8 - x; i <= 28; i++)
			{
				cout << i;
				a = a + 1;
				if (a % 7 == 0)
				{
					cout << endl;
					if (i <= 8)
						cout << "   ";
					else
						cout << "  ";
					continue;
				}
				if (i <= 8)
					cout << "       ";
				else
					cout << "      ";
			}
	}
	cout<<endl; 
	return 0;
}
