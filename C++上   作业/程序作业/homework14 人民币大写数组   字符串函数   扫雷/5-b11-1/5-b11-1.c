/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chistr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
int daxie(int num, int flag_of_zero, int jishu)
{
	switch (num) 
	{
		case 0:
			if (flag_of_zero)
			{
				result[jishu++] = chistr[0];
				result[jishu++] = chistr[1];
			}
			break;
		case 1:
		{
			result[jishu++] = chistr[2];
			result[jishu++] = chistr[3];
		}
			break;
		case 2:
		{
			result[jishu++] = chistr[4];
			result[jishu++] = chistr[5];
		}
			break;
		case 3:
		{
			result[jishu++] = chistr[6];
			result[jishu++] = chistr[7];
		}
			break;
		case 4:
		{
			result[jishu++] = chistr[8];
			result[jishu++] = chistr[9];
		}
			break;
		case 5:
		{
			result[jishu++] = chistr[10];
			result[jishu++] = chistr[11];
		}
			break;
		case 6:
		{
			result[jishu++] = chistr[12];
			result[jishu++] = chistr[13];
		}
			break;
		case 7:
		{
			result[jishu++] = chistr[14];
			result[jishu++] = chistr[15];
		}
			break;
		case 8:
		{
			result[jishu++] = chistr[16];
			result[jishu++] = chistr[17];
		}
			break;
		case 9:
		{
			result[jishu++] = chistr[18];
			result[jishu++] = chistr[19];
		}
			break;
		default:
			;
			break;
	}
	return jishu;
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
    
	printf("������һ��[0-100��)�����:\n");
	double n;
	char whz[30] = "ʰ��Ǫ����Բ�Ƿ���";
	int jishu = 0;
	scanf("%lf", &n);
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
	printf("��д�����:\n");
	if (a != 0)
	{
		jishu = daxie(a, 0, jishu);
		result[jishu++] = whz[0];
		result[jishu++] = whz[1];
		if (b == 0)
		{
			result[jishu++] = whz[8];
			result[jishu++] = whz[9];
		}
	}
	if (b != 0)
	{
		jishu = daxie(b, 0, jishu);
		result[jishu++] = whz[8];
		result[jishu++] = whz[9];
	}
	if (c != 0)
	{
		jishu = daxie(c, 0, jishu);
		result[jishu++] = whz[4];
		result[jishu++] = whz[5];
		if (d == 0 && e == 0 && f == 0)
		{
			result[jishu++] = whz[6];
			result[jishu++] = whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0)
		jishu = daxie(c, d, jishu);
	if (d != 0)
	{
		jishu = daxie(d, 0, jishu);
		result[jishu++] = whz[2];
		result[jishu++] = whz[3];
		if (e == 0 && f == 0)
		{
			result[jishu++] = whz[6];
			result[jishu++] = whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0)
		jishu = daxie(d, e, jishu);
	if (e != 0)
	{
		jishu = daxie(e, 0, jishu);
		result[jishu++] = whz[0];
		result[jishu++] = whz[1];
		if (f == 0)
		{
			result[jishu++] = whz[6];
			result[jishu++] = whz[7];
		}
	}
	if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
		jishu = daxie(e, f, jishu);
	if (f != 0)
	{
		jishu = daxie(e, d, jishu);
		jishu = daxie(e, c, jishu);
		jishu = daxie(f, 0, jishu);
		result[jishu++] = whz[6];
		result[jishu++] = whz[7];
	}
	if (g != 0)
	{
		jishu = daxie(g, 0, jishu);
		result[jishu++] = whz[4];
		result[jishu++] = whz[5];
		if (h == 0 && i == 0 && j == 0)
		{
			result[jishu++] = whz[10];
			result[jishu++] = whz[11];
		}
		else if (h == 0)
			jishu = daxie(h, g, jishu);
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			jishu = daxie(g, h, jishu);
		jishu = daxie(h, 0, jishu);
		result[jishu++] = whz[2];
		result[jishu++] = whz[3];
		if (i == 0 && j == 0)
		{
			result[jishu++] = whz[10];
			result[jishu++] = whz[11];
		}
		if (i == 0 && j != 0)
			jishu = daxie(i, j, jishu);
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			jishu = daxie(h, i, jishu);
		jishu = daxie(i, 0, jishu);
		result[jishu++] = whz[0];
		result[jishu++] = whz[1];
		if (j == 0)
		{
			result[jishu++] = whz[10];
			result[jishu++] = whz[11];
		}
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			jishu = daxie(i, j, jishu);
		jishu = daxie(j, 0, jishu);
		result[jishu++] = whz[10];
		result[jishu++] = whz[11];
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
	{
		result[jishu++] = whz[10];
		result[jishu++] = whz[11];
	}
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
	{
		jishu = daxie(x1, 1, jishu);
		result[jishu++] = whz[10];
		result[jishu++] = whz[11];
	}
	if (x1 == 0 && x2 == 0)
	{
		result[jishu++] = whz[16];
		result[jishu++] = whz[17];
	}
	if (x1 != 0)
	{
		jishu = daxie(x1, 0, jishu);
		result[jishu++] = whz[12];
		result[jishu++] = whz[13];
		if (x2 == 0)
		{
			result[jishu++] = whz[16];
			result[jishu++] = whz[17];
		}
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			jishu = daxie(x1, x2, jishu);
		jishu = daxie(x2, 0, jishu);
		result[jishu++] = whz[14];
		result[jishu++] = whz[15];
	}
	result[jishu] = '\0';
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
    return 0;
}