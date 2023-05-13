/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	int z = a > b ? a : b;
	return z > c ? z : c;
}

int max(int a, int b, int c, int d)
{
	int z1 = a > b ? a : b;
	int z2 = c > d ? c : d;
	return z1 > z2 ? z1 : z2;
}

int main()
{
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		int n, zuida;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "请输入个数num及num个正整数：" << endl;
			cin >> n;
		}
		if (n == 2)
		{
			int a, b;
			cin >> a;
			if (cin.fail() || a <= 0);
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> b;
			if (cin.fail() || b <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			zuida = max(a, b);
			cout << "max=" << zuida << endl;
			break;
		}
		else if (n == 3)
		{
			int a, b, c;
			cin >> a;
			if (cin.fail() || a <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> b;
			if (cin.fail() || b <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> c;
			if (cin.fail() || c <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			zuida = max(a, b, c);
			cout << "max=" << zuida << endl;
			break;
		}
		else if (n == 4)
		{
			int a, b, c, d;
			cin >> a;
			if (cin.fail() || a <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> b;
			if (cin.fail() || b <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> c;
			if (cin.fail() || c <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin >> d;
			if (cin.fail() || d <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			zuida = max(a, b, c, d);
			cout << "max=" << zuida << endl;
			break;
		}
		else
		{
			cout << "个数输入错误" << endl;
			break;
		}
	}
	return 0;
}
