/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;
int main()
{
	int i, n, k, j, m;
	int a[22];
	cout << "请输入任意个正整数（升序，最多20个），以负数结束" << endl;
	cin >> a[0];
	if (a[0] < 0)
		cout << "无有效输入" << endl;
	else
	{
		for (i = 0; a[i] >= 0 && i <= 19; i++)
			cin >> a[i + 1];
		cout << "原数组为:" << endl;
		if (i <= 19)
		{
			for (j = 0; j < i; j++)
				cout << a[j] << ' ';
			k = j - 1;
		}
		else
		{
			for (j = 0; j <= 19; j++)
				cout << a[j] << ' ';
			k = j - 1;
			rewind(stdin);
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> n;
		cout << "插入后的数组为:" << endl;
		for (i = 0; i <= k; i++)
			if (n < a[i])
			{
				m = i;
				break;
			}
		for (i = k; i >= m; i--)
			a[i + 1] = a[i];
		a[m] = n;
		for (i = 0; i <= k + 1; i++)
			cout << a[i]<<' ';
		cout << endl;
	}
	return 0;
}
