/* 1953729 ��09 ����� */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
	switch (num)
	{
		case 0:
			if (flag_of_zero)
			{
				result = result + chistr[0];
				result = result + chistr[1];
			}
			break;
		case 1:
		{
			result = result + chistr[2];
			result = result + chistr[3];
		}
		break;
		case 2:
		{
			result = result + chistr[4];
			result = result + chistr[5];
		}
		break;
		case 3:
		{
			result = result + chistr[6];
			result = result + chistr[7];
		}
		break;
		case 4:
		{
			result = result + chistr[8];
			result = result + chistr[9];
		}
		break;
		case 5:
		{
			result = result + chistr[10];
			result = result + chistr[11];
		}
		break;
		case 6:
		{
			result = result + chistr[12];
			result = result + chistr[13];
		}
		break;
		case 7:
		{
			result = result + chistr[14];
			result = result + chistr[15];
		}
		break;
		case 8:
		{
			result = result + chistr[16];
			result = result + chistr[17];
		}
		break;
		case 9:
		{
			result = result + chistr[18];
			result = result + chistr[19];
		}
		break;
		default:
			;
			break;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	cout << "������һ��[0-100��)�����:" << endl;
	double n;
	char whz[30] = "ʰ��Ǫ����Բ�Ƿ���";
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
		result = result + whz[0];
		result = result + whz[1];
		if (b == 0)
		{
			result = result + whz[8];
			result = result + whz[9];
		}
	}
	if (b != 0)
	{
		daxie(b, 0);
		result = result + whz[8];
		result = result + whz[9];
	}
	if (c != 0)
	{
		daxie(c, 0);
		result = result + whz[4];
		result = result + whz[5];
		if (d == 0 && e == 0 && f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0)
		daxie(c, d);
	if (d != 0)
	{
		daxie(d, 0);
		result = result + whz[2];
		result = result + whz[3];
		if (e == 0 && f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0)
		daxie(d, e);
	if (e != 0)
	{
		daxie(e, 0);
		result = result + whz[0];
		result = result + whz[1];
		if (f == 0)
		{
			result = result + whz[6];
			result = result + whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
		daxie(e, f);
	if (f != 0)
	{
		daxie(e, d);
		daxie(e, c);
		daxie(f, 0);
		result = result + whz[6];
		result = result + whz[7];
	}
	if (g != 0)
	{
		daxie(g, 0);
		result = result + whz[4];
		result = result + whz[5];
		if (h == 0 && i == 0 && j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
		else if (h == 0)
			daxie(h, g);
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			daxie(g, h);
		daxie(h, 0);
		result = result + whz[2];
		result = result + whz[3];
		if (i == 0 && j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
		if (i == 0 && j != 0)
			daxie(i, j);
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			daxie(h, i);
		daxie(i, 0);
		result = result + whz[0];
		result = result + whz[1];
		if (j == 0)
		{
			result = result + whz[10];
			result = result + whz[11];
		}
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			daxie(i, j);
		daxie(j, 0);
		result = result + whz[10];
		result = result + whz[11];
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
	{
		result = result + whz[10];
		result = result + whz[11];
	}
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
	{
		daxie(x1, 1);
		result = result + whz[10];
		result = result + whz[11];
	}
	if (x1 == 0 && x2 == 0)
	{
		result = result + whz[16];
		result = result + whz[17];
	}
	if (x1 != 0)
	{
		daxie(x1, 0);
		result = result + whz[12];
		result = result + whz[13];
		if (x2 == 0)
		{
			result = result + whz[16];
			result = result + whz[17];
		}
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			daxie(x1, x2);
		daxie(x2, 0);
		result = result + whz[14];
		result = result + whz[15];
	}
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}