/* 1953729 ��09 ����� */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand((unsigned int)(time(0)));
	char str[10][16] = {}, a[10][16] = {};
	int length, daxie, xiaoxie, num, qita;
	cout << "���������볤��(12-16)����д��ĸ����(��2)��Сд��ĸ����(��2)�����ָ���(��2)���������Ÿ���(��2)" << endl;
	cin >> length >> daxie >> xiaoxie >> num >> qita;
	if (cin.fail())
		cout << "���뺬�зǷ��ַ�." << endl;
	else
	{
		if (length < 12 || length > 16)
			cout << "���볤��[" << length << "]����ȷ" << endl;
		else if (daxie < 2)
			cout << "��д��ĸ����[" << daxie << "]����ȷ" << endl;
		else if (xiaoxie < 2)
			cout << "Сд��ĸ����[" << xiaoxie << "]����ȷ" << endl;
		else if (num < 2)
			cout << "���ָ���[" << num << "]����ȷ" << endl;
		else if (qita < 2)
			cout << "�������Ÿ���[" << qita << "]����ȷ" << endl;
		else if (daxie + xiaoxie + num + qita > length)
			cout << "�����ַ�����֮��[" << daxie << "+" << xiaoxie << "+" << num << "+" << qita << "]���������볤��[12]" << endl;
		else
		{
			cout << length << ' ' << daxie << ' ' << xiaoxie << ' ' << num << ' ' << qita << endl;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < daxie; j++)
				{
					str[i][j] = rand() % 94 + 33;
					if (str[i][j] < 'A' || str[i][j]>'Z')
						j--;
				}
				for (int j = daxie; j < daxie + xiaoxie; j++)
				{
					str[i][j] = rand() % 94 + 33;
					if (str[i][j] < 'a' || str[i][j]>'z')
						j--;
				}
				for (int j = daxie + xiaoxie; j < daxie + xiaoxie + num; j++)
				{
					str[i][j] = rand() % 94 + 33;
					if (str[i][j] < '0' || str[i][j]>'9')
						j--;
				}
				for (int j = daxie + xiaoxie + num; j < daxie + xiaoxie + num + qita; j++)
				{
					str[i][j] = rand() % 94 + 33;
					if (str[i][j] >= 'A' && str[i][j] <= 'Z' || str[i][j] >= 'a' && str[i][j] <= 'z' || str[i][j] >= '0' && str[i][j] <= '9')
						j--;
				}
				for (int j = daxie + xiaoxie + num + qita; j < length; j++)
					str[i][j] = rand() % 94 + 33;
				for (int t = 0; t < length; t++)
				{
					int m = rand() % length;
					while (a[i][m] != '\0')
						m = rand() % length;
					a[i][m] = str[i][t];
				}
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < length; j++)
					cout << a[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}