/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	int a[9][9];
	int t = 0;
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			while (1)
			{
				cin >> a[i][j];
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(10240,'\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					cin >> a[i][j];
				}
				if (a[i][j] >= 1 && a[i][j] <= 9)
					break;
				cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
			}
		}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			for (int k = j + 1; k < 9; k++)
			{
				if (a[i][j] == a[i][k])
					t = 1;
			}
	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 9; i++)
			for (int k = i + 1; k < 9; k++)
			{
				if (a[i][j] == a[k][j])
					t = 1;
			}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = i; k < 3; k++)
				for (int m = j + 1; m < 3; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 0; i < 3; i++)
		for (int j = 3; j < 6; j++)
			for (int k = i; k < 3; k++)
				for (int m = j + 1; m < 6; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 0; i < 3; i++)
		for (int j = 6; j < 9; j++)
			for (int k = i; k < 3; k++)
				for (int m = j + 1; m < 9; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 3; i < 6; i++)
		for (int j = 0; j < 3; j++)
			for (int k = i; k < 6; k++)
				for (int m = j + 1; m < 3; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 3; i < 6; i++)
		for (int j = 3; j < 6; j++)
			for (int k = i; k < 6; k++)
				for (int m = j + 1; m < 6; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 3; i < 6; i++)
		for (int j = 6; j < 9; j++)
			for (int k = i; k < 6; k++)
				for (int m = j + 1; m < 9; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 6; i < 9; i++)
		for (int j = 0; j < 3; j++)
			for (int k = i; k < 9; k++)
				for (int m = j + 1; m < 3; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 6; i < 9; i++)
		for (int j = 3; j < 6; j++)
			for (int k = i; k < 9; k++)
				for (int m = j + 1; m < 6; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	for (int i = 6; i < 9; i++)
		for (int j = 6; j < 9; j++)
			for (int k = i; k < 9; k++)
				for (int m = j + 1; m < 9; m++)
				{
					if (a[i][j] == a[k][m])
						t = 1;
				}
	if (t == 1)
		cout << "���������Ľ�" << endl;
	else
		cout << "�������Ľ�" << endl;
	return 0;
}