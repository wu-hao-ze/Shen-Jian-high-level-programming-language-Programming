/* 1953729 –≈09 Œ‚∫∆‘Û */
#include <iostream>
using namespace std;
int main()
{
	char a[400];
	char str[15][20] = {};
	int length, daxie, xiaoxie, num, qita;
	int daxie1 = 0, xiaoxie1 = 0, num1 = 0, qita1 = 0;
	cin.getline(a, 100, '\n');
	cin >> length >> daxie >> xiaoxie >> num >> qita;
	int i = 0, t = 0;
	for (; i < 10; i++)
	{
		t = 0;
		for (; t < length; t++)
			cin >> str[i][t];
	}
	if (i != 10 || t != length)
		cout << "¥ÌŒÛ" << endl;
	else if (length < 12 || length>16)
		cout << "¥ÌŒÛ" << endl;
	else if (daxie < 2 || xiaoxie < 2 || num < 2 || qita < 2)
		cout << "¥ÌŒÛ" << endl;
	else
	{
		int i = 0;
		for (; i < 10; i++)
		{
			daxie1 = 0, xiaoxie1 = 0, num1 = 0, qita1 = 0;
			for (int j = 0; j < length; j++)
			{
				if (str[i][j] >= 'A' && str[i][j] <= 'Z')
					daxie1++;
				else if (str[i][j] >= 'a' && str[i][j] <= 'z')
					xiaoxie1++;
				else if (str[i][j] >= '0' && str[i][j] <= '9')
					num1++;
				else
					qita1++;
			}
			if (daxie1 < daxie || xiaoxie1 < xiaoxie || num1 < num || qita1 < qita)
				break;
			if (daxie1 + xiaoxie1 + num1 + qita1 != length)
				break;
		}
		if (i == 10)
			cout << "’˝»∑" << endl;
		else
			cout << "¥ÌŒÛ" << endl;
	}
	return 0;
}