/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;
int main()
{
	int i, k, j, n;
	int a[1000];
	cout << "请输入成绩（最多1000个），以负数结束" << endl;
	cin >> a[0];
	if (a[0] < 0)
		cout << "无有效输入" << endl;
	else
	{
		for (i = 0; a[i] >= 0 && i <= 1000; i++)
			cin >> a[i + 1];
		cout << "输入的数组为:" << endl;
		if (i <= 1000)
		{
			for (j = 0; j < i; j++)
			{
				cout << a[j] << ' ';
				if ((j - 9) % 10 == 0)
					cout << endl;
			}
			k = j - 1;
		}
		else
		{
			for (j = 0; j < 1000; j++)
			{
				cout << a[j] << ' ';
				if ((j - 9) % 10 == 0)
					cout << endl;
			}
			k = j - 1;
		}
		if (j % 10 != 0)
			cout << endl;
		cout << "分数与人数的对应关系为:" << endl;
		for (i = 0; i <= k; i++)
			for (j = i + 1; j <= k; j++)
			{
				if (a[i] < a[j])
				{
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		for (i = 0; i <= k; i++)
		{
			n = 1;
			cout << a[i] << ' ';
			for (j = i + 1; j <= k; j++)
				if (a[i] == a[j])
					n = n + 1;
			cout << n << endl;
			i = i + n - 1;
		}
	}
	return 0;
}