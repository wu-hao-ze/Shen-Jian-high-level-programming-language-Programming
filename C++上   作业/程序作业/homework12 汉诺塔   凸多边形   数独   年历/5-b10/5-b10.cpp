/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	system("mode con cols=120 lines=45");
	int zeller(int, int, int);
	int cal(int, int, int);
	int run(int);
	void blank(int);
	int year;
	int i = 0, j = 0, k = 0;
	int a[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10240, '\n');
			cout << "请输入年份[1900-2100]" << endl;
			cin >> year;
		}
		if (year >= 1900 && year <= 2100)
			break;
		else
		{
			cin.clear();
			cin.ignore(10240, '\n');
		}
	}
	cout << year << "年的日历:" << endl;
	cout << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	blank(zeller(year, 1, 1));
	for (; i + zeller(year, 1, 1) < 7; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[i];
	}
	cout << "    ";
	blank(zeller(year, 2, 1));
	for (; j + zeller(year, 2, 1) < 7; j++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[j];
	}
	cout << "    ";
	blank(zeller(year, 3, 1));
	for (; k + zeller(year, 3, 1) < 7; k++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[k];
	}
	cout << endl;
	for (int t = 0; t < 7; t++)               // 第2行开始
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7 && i <= 30; t++)                 //倒数第二行
	{
		cout << setw(4) << a[i];
		i++;
	}
	if (i == 31)
		blank(6 - zeller(year, 1, 31));
	cout << "    ";
	if (j == run(year))
		blank(7);
	else
	{
		for (int t = 0; t < 7 && j < run(year); t++)
		{
			cout << setw(4) << a[j];
			j++;
		}
		if (j == run(year))
			blank(6 - zeller(year, 2, run(year)));
	}
	cout << "    ";
	for (int t = 0; t < 7 && k <= 30; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	if (k == 31)
		blank(6 - zeller(year, 3, 31));
	if (i == 31 && j == run(year) && k == 31)
		cout << endl;
	else                                                  //最后一行
	{
		cout << endl;
		if (i == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && i <= 30; t++)
			{
				cout << setw(4) << a[i];
				i++;
			}
			if (i == 31)
				blank(6 - zeller(year, 1, 31));
		}
		cout << "    ";
		blank(7);
		cout << "    ";
		if (k == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && k <= 30; t++)
			{
				cout << setw(4) << a[k];
				k++;
			}
			if (k == 31)
				blank(6 - zeller(year, 3, 31));
		}
		cout << endl;
	}
	cout << endl;
	i = 0;
	j = 0;
	k = 0;
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	blank(zeller(year, 4, 1));
	for (; i + zeller(year, 4, 1) < 7; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[i];
	}
	cout << "    ";
	blank(zeller(year, 5, 1));
	for (; j + zeller(year, 5, 1) < 7; j++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[j];
	}
	cout << "    ";
	blank(zeller(year, 6, 1));
	for (; k + zeller(year, 6, 1) < 7; k++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[k];
	}
	cout << endl;
	for (int t = 0; t < 7; t++)               // 第2行开始
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7 && i <= 29; t++)                 //倒数第二行
	{
		cout << setw(4) << a[i];
		i++;
	}
	if (i == 30)
		blank(6 - zeller(year, 4, 30));
	cout << "    ";
	for (int t = 0; t < 7 && j <= 30; t++)                
	{
		cout << setw(4) << a[j];
		j++;
	}
	if (j == 31)
		blank(6 - zeller(year, 5, 31));
	cout << "    ";
	for (int t = 0; t < 7 && k <= 29; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	if (k == 30)
		blank(6 - zeller(year, 6, 30));
	if (i == 30 && j == 31 && k == 30)
		cout << endl;
	else                                                  //最后一行
	{
		cout << endl;
		if (i == 30)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && i <= 29; t++)
			{
				cout << setw(4) << a[i];
				i++;
			}
			if (i == 30)
				blank(6 - zeller(year, 4, 30));
		}
		cout << "    ";
		if (j == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && j <= 30; t++)
			{
				cout << setw(4) << a[j];
				j++;
			}
			if (j == 31)
				blank(6 - zeller(year, 5, 31));
		}
		cout << "    ";
		if (k == 30)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && k <= 29; t++)
			{
				cout << setw(4) << a[k];
				k++;
			}
			if (k == 30)
				blank(6 - zeller(year, 6, 30));
		}
		cout << endl;
	}
	cout << endl;
	i = 0;
	j = 0;
	k = 0;
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	blank(zeller(year, 7, 1));
	for (; i + zeller(year, 7, 1) < 7; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[i];
	}
	cout << "    ";
	blank(zeller(year, 8, 1));
	for (; j + zeller(year, 8, 1) < 7; j++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[j];
	}
	cout << "    ";
	blank(zeller(year, 9, 1));
	for (; k + zeller(year, 9, 1) < 7; k++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[k];
	}
	cout << endl;
	for (int t = 0; t < 7; t++)               // 第2行开始
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7 && i <= 30; t++)                 //倒数第二行
	{
		cout << setw(4) << a[i];
		i++;
	}
	if (i == 31)
		blank(6 - zeller(year, 7, 31));
	cout << "    ";
	for (int t = 0; t < 7 && j <= 30; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	if (j == 31)
		blank(6 - zeller(year, 8, 31));
	cout << "    ";
	for (int t = 0; t < 7 && k <= 29; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	if (k == 30)
		blank(6 - zeller(year, 9, 30));
	if (i == 31 && j == 31 && k == 30)
		cout << endl;
	else                                                  //最后一行
	{
		cout << endl;
		if (i == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && i <= 30; t++)
			{
				cout << setw(4) << a[i];
				i++;
			}
			if (i == 31)
				blank(6 - zeller(year, 7, 31));
		}
		cout << "    ";
		if (j == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && j <= 30; t++)
			{
				cout << setw(4) << a[j];
				j++;
			}
			if (j == 31)
				blank(6 - zeller(year, 8, 31));
		}
		cout << "    ";
		if (k == 30)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && k <= 29; t++)
			{
				cout << setw(4) << a[k];
				k++;
			}
			if (k == 30)
				blank(6 - zeller(year, 9, 30));
		}
		cout << endl;
	}
	cout << endl;
	i = 0;
	j = 0;
	k = 0;
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	blank(zeller(year, 10, 1));
	for (; i + zeller(year, 10, 1) < 7; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[i];
	}
	cout << "    ";
	blank(zeller(year, 11, 1));
	for (; j + zeller(year, 11, 1) < 7; j++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[j];
	}
	cout << "    ";
	blank(zeller(year, 12, 1));
	for (; k + zeller(year, 12, 1) < 7; k++)
	{
		cout << setiosflags(ios::left);
		cout << setw(4) << a[k];
	}
	cout << endl;
	for (int t = 0; t < 7; t++)               // 第2行开始
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[i];
		i++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	cout << "    ";
	for (int t = 0; t < 7; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	cout << endl;
	for (int t = 0; t < 7 && i <= 30; t++)                 //倒数第二行
	{
		cout << setw(4) << a[i];
		i++;
	}
	if (i == 31)
		blank(6 - zeller(year, 10, 31));
	cout << "    ";
	for (int t = 0; t < 7 && j <= 29; t++)
	{
		cout << setw(4) << a[j];
		j++;
	}
	if (j == 30)
		blank(6 - zeller(year, 11, 30));
	cout << "    ";
	for (int t = 0; t < 7 && k <= 30; t++)
	{
		cout << setw(4) << a[k];
		k++;
	}
	if (k == 31)
		blank(6 - zeller(year, 12, 31));
	if (i == 31 && j == 30 && k == 31)
		cout << endl;
	else                                                  //最后一行
	{
		cout << endl;
		if (i == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && i <= 30; t++)
			{
				cout << setw(4) << a[i];
				i++;
			}
			if (i == 31)
				blank(6 - zeller(year, 10, 31));
		}
		cout << "    ";
		if (j == 30)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && j <= 29; t++)
			{
				cout << setw(4) << a[j];
				j++;
			}
			if (j == 30)
				blank(6 - zeller(year, 11, 30));
		}
		cout << "    ";
		if (k == 31)
			blank(7);
		else
		{
			for (int t = 0; t < 7 && k <= 30; t++)
			{
				cout << setw(4) << a[k];
				k++;
			}
			if (k == 31)
				blank(6 - zeller(year, 12, 31));
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

int run(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 29;
	else
		return 28;
}
void blank(int x)
{
	if (x == 0)
		;
	else if (x == 1)
		cout << "    ";
	else if (x == 2)
		cout << "        ";
	else if (x == 3)
		cout << "            ";
	else if (x == 4)
		cout << "                ";
	else if (x == 5)
		cout << "                    ";
	else if (x == 6)
		cout << "                        ";
	else
		cout << "                            ";
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