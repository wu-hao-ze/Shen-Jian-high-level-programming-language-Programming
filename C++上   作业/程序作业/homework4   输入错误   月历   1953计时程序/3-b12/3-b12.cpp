/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int year, month, i, x, a = 0;
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;  
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入年份(2000-2030)和月份(1-12) : ";
			cin >> year >> month;
		}
		if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
			break;
		else
			cout << "输入非法，请重新输入" << endl;
	}
	cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
	while (1)
	{
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
			cin >> year >> month;
		}
		if (x >= 0 && x <= 6)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
		}
	}
	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
