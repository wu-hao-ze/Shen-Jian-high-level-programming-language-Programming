/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	int i, n, k, j, m;
	int a[22];
	cout << "��������������������������20�������Ը�������" << endl;
	cin >> a[0];
	if (a[0] < 0)
		cout << "����Ч����" << endl;
	else
	{
		for (i = 0; a[i] >= 0 && i <= 19; i++)
			cin >> a[i + 1];
		cout << "ԭ����Ϊ:" << endl;
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
		cout << "������Ҫ�����������" << endl;
		cin >> n;
		cout << "����������Ϊ:" << endl;
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
