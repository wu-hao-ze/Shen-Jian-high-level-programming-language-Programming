/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{	
	char str[3][128] = {};
	cout << "�������һ��" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "������ڶ���" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "�����������" << endl;
	cin.getline(str[2], 128, '\n');
	int daxie = 0, xiaoxie = 0, shuzi = 0, kongge = 0, qita = 0;
	for (int i = 0; str[0][i] != '\0'; i++)
	{
		if (str[0][i] >= 'A' && str[0][i] <= 'Z')
			daxie++;
		else if (str[0][i] >= 'a' && str[0][i] <= 'z')
			xiaoxie++;
		else if (str[0][i] >= '0' && str[0][i] <= '9')
			shuzi++;
		else if (str[0][i] == ' ')
			kongge++;
		else
			qita++;
	}
	for (int i = 0; str[1][i] != '\0'; i++)
	{
		if (str[1][i] >= 'A' && str[1][i] <= 'Z')
			daxie++;
		else if (str[1][i] >= 'a' && str[1][i] <= 'z')
			xiaoxie++;
		else if (str[1][i] >= '0' && str[1][i] <= '9')
			shuzi++;
		else if (str[1][i] == ' ')
			kongge++;
		else
			qita++;
	}
	for (int i = 0; str[2][i] != '\0'; i++)
	{
		if (str[2][i] >= 'A' && str[2][i] <= 'Z')
			daxie++;
		else if (str[2][i] >= 'a' && str[2][i] <= 'z')
			xiaoxie++;
		else if (str[2][i] >= '0' && str[2][i] <= '9')
			shuzi++;
		else if (str[2][i] == ' ')
			kongge++;
		else
			qita++;
	}
	cout << "��д : " << daxie << endl;
	cout << "Сд : " << xiaoxie << endl;
	cout << "���� : " << shuzi << endl;
	cout << "�ո� : " << kongge << endl;
	cout << "���� : " << qita << endl;
	return 0;
}