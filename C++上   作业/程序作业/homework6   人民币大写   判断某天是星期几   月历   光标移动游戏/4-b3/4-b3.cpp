/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int year, month, day, i, a = 0;
	int zeller(int, int, int);
	while (1)
	{
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			cout << "请输入年[1900-2100]、月" << endl;
			cin >> year >> month;
		}
		if (year < 1900 || year > 2100)
			cout << "年份不正确，请重新输入" << endl;
		else if (month < 1 || month>12)
			cout << "月份不正确，请重新输入" << endl;
		if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
	}
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	int x = zeller(year, month, 1);
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
			if (i <= 8)
				cout << "       ";
			else
				cout << "      ";
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
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
	for (w; w < 0;)
		w = w + 7;
	week = w % 7;
	return week;
}