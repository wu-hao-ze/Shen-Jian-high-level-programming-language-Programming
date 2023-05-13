/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int n;
	scanf("%d", &n);
	int a = n / 10000;
	int b = n / 1000 % 10;
	int c = n / 100 % 10;
	int d = n / 10 % 10;
	int e = n % 10;
	printf("万位 : ");
	printf("%d\n", a);
	printf("千位 : ");
	printf("%d\n", b);
	printf("百位 : ");
	printf("%d\n", c);
	printf("十位 : ");
	printf("%d\n", d);
	printf("个位 : ");
	printf("%d\n", e);
	return 0;
}
