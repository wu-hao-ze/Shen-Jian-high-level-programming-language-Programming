/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	srand((unsigned int)(time(0)));
	char str[10][16] = {}, a[10][16] = {};
	int length, daxie, xiaoxie, num, qita;
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其他符号个数(≥2)" << endl;
	cin >> length >> daxie >> xiaoxie >> num >> qita;
	if (cin.fail())
		cout << "输入含有非法字符." << endl;
	else
	{
		if (length < 12 || length > 16)
			cout << "密码长度[" << length << "]不正确" << endl;
		else if (daxie < 2)
			cout << "大写字母个数[" << daxie << "]不正确" << endl;
		else if (xiaoxie < 2)
			cout << "小写字母个数[" << xiaoxie << "]不正确" << endl;
		else if (num < 2)
			cout << "数字个数[" << num << "]不正确" << endl;
		else if (qita < 2)
			cout << "其它符号个数[" << qita << "]不正确" << endl;
		else if (daxie + xiaoxie + num + qita > length)
			cout << "所有字符类型之和[" << daxie << "+" << xiaoxie << "+" << num << "+" << qita << "]大于总密码长度[12]" << endl;
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