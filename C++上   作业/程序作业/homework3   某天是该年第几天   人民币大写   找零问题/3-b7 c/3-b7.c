/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[0-100��)�����:\n");
	double n;
	scanf("%lf",&n);
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
		switch (a)
		{
			case 1:
				printf ( "Ҽʰ");
				break;		   
			case 2:			   
				printf ( "��ʰ");
				break;		   
			case 3:			   
				printf ( "��ʰ");
				break;		   
			case 4:			   
				printf ( "��ʰ");
				break;		   
			case 5:			   
				printf ( "��ʰ");
				break;		   
			case 6:			   
				printf ( "½ʰ");
				break;		   
			case 7:			   
				printf ( "��ʰ");
				break;		   
			case 8:			  
				printf ( "��ʰ");
				break;		   
			case 9:			   
				printf ( "��ʰ");
				break;
		}
		if (b == 0)
			printf ( "��");
	}
	if (b != 0)
	{
		switch (b)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "����");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "����");
				break;
			case 8:
				printf ( "����");
				break;
			case 9:
				printf ( "����");
				break;
		}
	}
	if (c != 0)
	{
		switch (c)
		{
			case 1:
				printf ( "ҼǪ");
				break;
			case 2:
				printf ( "��Ǫ");
				break;
			case 3:
				printf ( "��Ǫ");
				break;
			case 4:
				printf ( "��Ǫ");
				break;
			case 5:
				printf ( "��Ǫ");
				break;
			case 6:
				printf ( "½Ǫ");
				break;
			case 7:
				printf ( "��Ǫ");
				break;
			case 8:
				printf ( "��Ǫ");
				break;
			case 9:
				printf ( "��Ǫ");
				break;
		}
		if (d == 0 && e == 0 && f == 0)
			printf ( "��");
		if (d == 0 && e == 0 && f != 0)
			printf ( "��");
		if (d == 0 && e != 0)
			printf ( "��");
	}
	if (d != 0)
	{
		if ((a != 0 || b != 0) && c == 0)
			printf ( "��");
		switch (d)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "���");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "���");
				break;
			case 8:
				printf ( "�ư�");
				break;
			case 9:
				printf ( "����");
				break;
		}
		if (e == 0 && f == 0)
			printf ( "��");
		if (e == 0 && f != 0)
			printf ( "��");
	}
	if (e != 0)
	{
		if ((a != 0 || b != 0) && (d == 0 && c == 0))
			printf ( "��");
		switch (e)
		{
			case 1:
				printf ( "Ҽʰ");
				break;
			case 2:
				printf ( "��ʰ");
				break;
			case 3:
				printf ( "��ʰ");
				break;
			case 4:
				printf ( "��ʰ");
				break;
			case 5:
				printf ( "��ʰ");
				break;
			case 6:
				printf ( "½ʰ");
				break;
			case 7:
				printf ( "��ʰ");
				break;
			case 8:
				printf ( "��ʰ");
				break;
			case 9:
				printf ( "��ʰ");
				break;
		}
		if (f == 0)
			printf ( "��");
	}
	if (f != 0)
	{
		if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
			printf ( "��");
		switch (f)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "����");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "����");
				break;
			case 8:
				printf ( "����");
				break;
			case 9:
				printf ( "����");
				break;
		}
	}
	if (g != 0)
	{
		switch (g)
		{
			case 1:
				printf ( "ҼǪ");
				break;
			case 2:
				printf ( "��Ǫ");
				break;
			case 3:
				printf ( "��Ǫ");
				break;
			case 4:
				printf ( "��Ǫ");
				break;
			case 5:
				printf ( "��Ǫ");
				break;
			case 6:
				printf ( "½Ǫ");
				break;
			case 7:
				printf ( "��Ǫ");
				break;
			case 8:
				printf ( "��Ǫ");
				break;
			case 9:
				printf ( "��Ǫ");
				break;
		}
		if (h == 0 && i == 0 && j == 0)
			printf ( "Բ");
		if (h == 0 && i == 0 && j != 0)
			printf ( "��");
		if (h == 0 && i != 0)
			printf ( "��");
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			printf ( "��");
		switch (h)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "���");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "���");
				break;
			case 8:
				printf ( "�ư�");
				break;
			case 9:
				printf ( "����");
				break;
		}
		if (i == 0 && j == 0)
			printf ( "Բ");
		if (i == 0 && j != 0)
			printf ( "��");
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			printf ( "��");
		switch (i)
		{
			case 1:
				printf ( "Ҽʰ");
				break;
			case 2:
				printf ( "��ʰ");
				break;
			case 3:
				printf ( "��ʰ");
				break;
			case 4:
				printf ( "��ʰ");
				break;
			case 5:
				printf ( "��ʰ");
				break;
			case 6:
				printf ( "½ʰ");
				break;
			case 7:
				printf ( "��ʰ");
				break;
			case 8:
				printf ( "��ʰ");
				break;
			case 9:
				printf ( "��ʰ");
				break;
		}
		if (j == 0)
			printf ( "Բ");
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			printf ( "��");
		switch (j)
		{
			case 1:
				printf ( "ҼԲ");
				break;
			case 2:
				printf ( "��Բ");
				break;
			case 3:
				printf ( "��Բ");
				break;
			case 4:
				printf ( "��Բ");
				break;
			case 5:
				printf ( "��Բ");
				break;
			case 6:
				printf ( "½Բ");
				break;
			case 7:
				printf ( "��Բ");
				break;
			case 8:
				printf ( "��Բ");
				break;
			case 9:
				printf ( "��Բ");
				break;
		}
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		printf ( "Բ");
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
		printf ( "��Բ");
	if (x1 == 0 && x2 == 0)
		printf ( "��");
	if (x1 != 0)
	{
		switch (x1)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "���");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "���");
				break;
			case 8:
				printf ( "�ƽ�");
				break;
			case 9:
				printf ( "����");
				break;
		}
		if (x2 == 0)
			printf ( "��");
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			printf ( "��");
		switch (x2)
		{
			case 1:
				printf ( "Ҽ��");
				break;
			case 2:
				printf ( "����");
				break;
			case 3:
				printf ( "����");
				break;
			case 4:
				printf ( "����");
				break;
			case 5:
				printf ( "���");
				break;
			case 6:
				printf ( "½��");
				break;
			case 7:
				printf ( "���");
				break;
			case 8:
				printf ( "�Ʒ�");
				break;
			case 9:
				printf ( "����");
				break;
		}
	}
	printf ( "\n");
	return 0;
}
