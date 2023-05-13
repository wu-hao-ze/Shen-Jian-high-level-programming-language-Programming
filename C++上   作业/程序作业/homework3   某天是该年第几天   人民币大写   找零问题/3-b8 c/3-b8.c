/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入找零值：\n");
	double x;
	scanf("%lf", &x);
	int a, b, c, d, e, f, g, h, i, j, sum;
	int t = (int)x;
	a = (int)(t / 50.0);
	int a1 = t % 50;
	b = (int)(a1 / 20.0);
	int b1 = a1 % 20;
	c = (int)(b1 / 10.0);
	int c1 = b1 % 10;
	d = (int)(c1 / 5.0);
	int d1 = c1 % 5;
	e = d1;
	int y = (int)((x - t + 0.0005) * 100);
	f = (int)(y / 50.0);
	int f1 = y % 50;
	g = (int)(f1 / 10.0);
	int g1 = f1 % 10;
	h = (int)(g1 / 5.0);
	int h1 = g1 % 5;
	i = (int)(h1 / 2.0);
	int i1 = h1 % 2;
	j = i1;
	sum = a + b + c + d + e + f + g + h + i + j;
	printf("共%d张找零，具体如下：\n", sum);
	if (a != 0)
		printf("50元 : %d张\n", a);
	if (b != 0)
		printf("20元 : %d张\n", b);
	if (c != 0)
		printf("10元 : %d张\n", c);
	if (d != 0)
		printf("5元  : %d张\n", d);
	if (e != 0)
		printf("1元  : %d张\n", e);
	if (f != 0)
		printf("5角  : %d张\n", f);
	if (g != 0)
		printf("1角  : %d张\n", g);
	if (h != 0)
		printf("5分  : %d张\n", h);
	if (i != 0)
		printf("2分  : %d张\n", i);
	if (j != 0)
		printf("1分  : %d张\n", j);
	return 0;
}
