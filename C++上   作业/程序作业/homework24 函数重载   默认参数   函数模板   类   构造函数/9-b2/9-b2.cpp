/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int z1 = a > b ? b : a;
	int z2 = z1 > c ? c : z1;
	int z3 = z2 > d ? d : z2;
	return z3;
}

int main()
{
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		int n, zuixiao;
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
			zuixiao = min(a, b);
			cout << "min=" << zuixiao << endl;
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
			zuixiao = min(a, b, c);
			cout << "min=" << zuixiao << endl;
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
			zuixiao = min(a, b, c, d);
			cout << "min=" << zuixiao << endl;
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
