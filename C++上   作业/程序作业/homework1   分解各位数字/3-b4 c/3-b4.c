/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[0-100��)�������:\n");
	double N;
	scanf("%lf",&N);
	double n = N / 10;
	int a = (int)(n) / 100000000;
	int b = (int)(n) / 10000000 % 10;
	int c = (int)(n) / 1000000 % 10;
	int d = (int)(n) / 100000 % 10;
	int e = (int)(n) / 10000 % 10;
	int f = (int)(n) / 1000 % 10;
	int g = (int)(n) / 100 % 10;
	int h = (int)(n) / 10 % 10;
	int i = (int)(n) % 10;
	int t = (int)n;
	double x = n - t + 0.0004;
	int j = (int)(x * 10);
	int x1 = (int)(x * 100) % 10;
	int x2 = (int)(x * 1000) % 10;
	printf("ʮ��λ : %d\n", a);
	printf("��λ   : %d\n", b);
	printf("ǧ��λ : %d\n", c);
	printf("����λ : %d\n", d);
	printf("ʮ��λ : %d\n", e);
	printf("��λ   : %d\n", f);
	printf("ǧλ   : %d\n", g);
	printf("��λ   : %d\n", h);
	printf("ʮλ   : %d\n", i);
	printf("Բ     : %d\n", j);
	printf("��     : %d\n", x1);
	printf("��     : %d\n", x2);
	return 0;
}