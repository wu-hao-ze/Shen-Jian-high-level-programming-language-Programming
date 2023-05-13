/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[0-100亿)间的数字:\n");
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
	printf("十亿位 : %d\n", a);
	printf("亿位   : %d\n", b);
	printf("千万位 : %d\n", c);
	printf("百万位 : %d\n", d);
	printf("十万位 : %d\n", e);
	printf("万位   : %d\n", f);
	printf("千位   : %d\n", g);
	printf("百位   : %d\n", h);
	printf("十位   : %d\n", i);
	printf("圆     : %d\n", j);
	printf("角     : %d\n", x1);
	printf("分     : %d\n", x2);
	return 0;
}