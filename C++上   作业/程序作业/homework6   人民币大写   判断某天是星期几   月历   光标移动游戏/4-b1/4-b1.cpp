 /* 1953729 ��09 ����� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	cout << "������һ��[0-100��)�����:" << endl;
	double n;
	cin >> n;
	int a = (int)((long long int)(n) / 1000000000);
	int b = (int)((long long int)(n) / 100000000 % 10);
	int c = (int)((long long int)(n) / 10000000 % 10);
	int d = (int)((long long int)(n) / 1000000 % 10);
	int e = (int)((long long int)(n) / 100000 % 10);
	int f = (int)((long long int)(n) / 10000 % 10);
	int g = (int)((long long int)(n) / 1000 % 10);
	int h = (int)((long long int)(n) / 100 % 10);
	int i = (int)((long long int)(n) / 10 % 10);
	int j = (int)((long long int)(n) % 10);
	long long int t = (long long int)(n);
	double x = n - t + 0.0004;
	int x1 = (int)(x * 10) % 10;
	int x2 = (int)(x * 100) % 10;
	cout << "��д�����:" << endl;
	if (a != 0)
	{
		daxie(a, 0);
		cout << "ʰ";
		if (b == 0)
			cout << "��";
	}
	if (b != 0)
	{
		daxie(b, 0);
		cout << "��";
	}
	if (c != 0)
	{
		daxie(c, 0);
		cout << "Ǫ";
		if (d == 0 && e == 0 && f == 0)
			cout << "��";
	}
	if ((a != 0 || b != 0) && c == 0)
		daxie(c, d);
	if (d != 0)
	{
		daxie(d, 0);
		cout << "��";
		if (e == 0 && f == 0)
			cout << "��";
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0)
		daxie(d, e);
	if (e != 0)
	{
		daxie(e, 0);
		cout << "ʰ";
		if (f == 0)
			cout << "��";
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
		daxie(e, f);
	if (f != 0)
	{
		daxie(e,d);
		daxie(e,c);
		daxie(f, 0);
		cout << "��";
	}
	if (g != 0)
	{
		daxie(g, 0);
		cout << "Ǫ";
		if (h == 0 && i == 0 && j == 0)
			cout << "Բ";
		else if (h == 0)
			daxie(h, g);
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			daxie(g, h);
		daxie(h, 0);
		cout << "��";
		if (i == 0 && j == 0)
			cout << "Բ";
		if (i == 0 && j != 0)
			daxie(i, j);
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			daxie(h, i);
		daxie(i, 0);
		cout << "ʰ";
		if (j == 0)
			cout << "Բ";
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			daxie(i, j);
		daxie(j, 0);
		cout << "Բ";
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		cout << "Բ";
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
	{	
		daxie(x1, 1);
		cout << "Բ";
	}
	if (x1 == 0 && x2 == 0)
		cout << "��";
	if (x1 != 0)
	{
		daxie(x1, 0);
		cout << "��";
		if (x2 == 0)
			cout << "��";
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			daxie(x1, x2);
		daxie(x2, 0);
		cout << "��";
	}
	cout << endl;
	return 0;
}
