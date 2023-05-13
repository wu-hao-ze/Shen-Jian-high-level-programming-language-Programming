/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int s[3][10];
int top[3];
int x = 1;
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		printf("第%4d 步(%2d): %c-->%c A:", x, n, src, dst);
		if (src == 'A' && dst == 'B')
			s[1][top[1]++] = s[0][--top[0]];
		else if (src == 'A' && dst == 'C')
			s[2][top[2]++] = s[0][--top[0]];
		else if (src == 'B' && dst == 'C')
			s[2][top[2]++] = s[1][--top[1]];
		else if (src == 'B' && dst == 'A')
			s[0][top[0]++] = s[1][--top[1]];
		else if (src == 'C' && dst == 'A')
			s[0][top[0]++] = s[2][--top[2]];
		else
			s[1][top[1]++] = s[2][--top[2]];
		for (int i = 0; i < top[0]; i++)
			printf("%2d", s[0][i]);
		for (int i = 0; i < (10 - top[0]) * 2 + 1; i++)
			printf("%c", ' ');
		printf("B:");
		for (int i = 0; i < top[1]; i++)
			printf("%2d", s[1][i]);
		for (int i = 0; i < (10 - top[1]) * 2 + 1; i++)
			printf("%c", ' ');
		printf("C:");
		for (int i = 0; i < top[2]; i++)
			printf("%2d", s[2][i]);
		printf("\n");
		x++;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		printf("第%4d 步(%2d): %c-->%c A:", x, n, src, dst);
		if (src == 'A' && dst == 'B')
			s[1][top[1]++] = s[0][--top[0]];
		else if (src == 'A' && dst == 'C')
			s[2][top[2]++] = s[0][--top[0]];
		else if (src == 'B' && dst == 'C')
			s[2][top[2]++] = s[1][--top[1]];
		else if (src == 'B' && dst == 'A')
			s[0][top[0]++] = s[1][--top[1]];
		else if (src == 'C' && dst == 'A')
			s[0][top[0]++] = s[2][--top[2]];
		else if (src == 'C' && dst == 'B')
			s[1][top[1]++] = s[2][--top[2]];
		for (int i = 0; i < top[0]; i++)
			printf("%2d", s[0][i]);
		for (int i = 0; i < (10 - top[0]) * 2 + 1; i++)
			printf("%c", ' ');
		printf("B:");
		for (int i = 0; i < top[1]; i++)
			printf("%2d", s[1][i]);
		for (int i = 0; i < (10 - top[1]) * 2 + 1; i++)
			printf("%c", ' ');
		printf("C:");
		for (int i = 0; i < top[2]; i++)
			printf("%2d", s[2][i]);
		printf("\n");
		x++;
		hanoi(n - 1, tmp, src, dst);
	}
}
int main()
{
	char src, dst, tmp;
	int n;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)\n");
		scanf("%d", &n);
		rewind(stdin);
		if (n >= 1 && n <= 10)
			break;
	}
	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		scanf("%c", &src);
		rewind(stdin);
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
			break;
	}
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		scanf("%c", &dst);
		rewind(stdin);
		if (dst == src || (dst - src) == 32 || (dst - src) == -32)
		{
			if (src > 95)
				src = src - 32;
			printf("目标柱(%c)不能与起始柱(%c)相同\n", src, src);
			continue;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
			break;
	}

	if (src > 95)
		src = src - 32;
	if (dst > 95)
		dst = dst - 32;
	if (src == 'A' && dst == 'B')
		tmp = 'C';
	if (src == 'A' && dst == 'C')
		tmp = 'B';
	if (src == 'B' && dst == 'A')
		tmp = 'C';
	if (src == 'B' && dst == 'C')
		tmp = 'A';
	if (src == 'C' && dst == 'B')
		tmp = 'A';
	if (src == 'C' && dst == 'A')
		tmp = 'B';
	if (src == 'A')
	{
		top[0] = n;
		top[1] = 0;
		top[2] = 0;
		for (int i = n; i >= 1; i--)
			s[0][i - 1] = n - i + 1;
		printf("初始:                A:");
		for (int i = n; i >= 1; i--)
			printf("%2d", i);
		for (int i = 0; i < (10 - n) * 2 + 1; i++)
			printf("%c", ' ');
		printf("B:                     C:\n");
	}
	else if (src == 'B')
	{
		top[0] = 0;
		top[1] = n;
		top[2] = 0;
		for (int i = n; i >= 1; i--)
			s[1][i - 1] = n - i + 1;
		printf( "初始:                A:                     B:");
		for (int i = n; i >= 1; i--)
			printf("%2d", i);
		for (int i = 0; i < (10 - n) * 2 + 1; i++)
			printf("%c", ' ');
		printf("C:\n");
	}
	else
	{
		top[0] = 0;
		top[1] = 0;
		top[2] = n;
		for (int i = n; i >= 1; i--)
			s[2][i - 1] = n - i + 1;
		printf("初始:                A:                     B:                     C:");
		for (int i = n; i >= 1; i--)
			printf("%2d", i);
		printf("\n");
	}
	hanoi(n, src, tmp, dst);
	return 0;
}