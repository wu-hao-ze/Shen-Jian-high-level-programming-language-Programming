/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n");
	int n;
	scanf("%d", &n);
	int a = n / 10000;
	int b = n / 1000 % 10;
	int c = n / 100 % 10;
	int d = n / 10 % 10;
	int e = n % 10;
	printf("��λ : ");
	printf("%d\n", a);
	printf("ǧλ : ");
	printf("%d\n", b);
	printf("��λ : ");
	printf("%d\n", c);
	printf("ʮλ : ");
	printf("%d\n", d);
	printf("��λ : ");
	printf("%d\n", e);
	return 0;
}
