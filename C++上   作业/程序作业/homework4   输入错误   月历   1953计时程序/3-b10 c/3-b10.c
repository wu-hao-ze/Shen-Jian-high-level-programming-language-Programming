/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x;
	while (1) 
	{
		printf("请输入x的值(0-100)：");
		scanf("%d", &x);
		if (x >= 0 && x <= 100)
			break;
		rewind(stdin);
	}
	printf("x=%d\n", x);
	return 0;
} 
