/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(char num[][8], char name[][9], int grade[]);
void select(char num[][8], int fail[], int);
void output(char num[][8], char name[][9], int grade[], int fail[], int j);

int main()
{
	char num[10][8], name[10][9];
	int grade[10];
	input(num, name, grade);
	printf("\n");
	printf("不及格名单:\n");
	int fail[10];
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		if (grade[i] < 60)
		{
			fail[j] = i;
			j++;
		}
	}
	select(num, fail, j);
	output(num, name, grade, fail, j);
	return 0;
}

void input(char num[][8], char name[][9], int grade[])
{
	int i = 1;
	for (; i <= 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i);
		scanf("%s", num[i - 1]);
		scanf("%s", name[i - 1]);
		scanf("%d", &grade[i - 1]);
	}
}
void select(char num[][8], int fail[], int j)
{
	int tmpt = 0;
	for (int m = 7; m >= 0; m--)
	{
		for (int i = 0; i < j; i++)
		{
			for (int k = i + 1; k < j; k++)
			{
				if (num[fail[i]][m] < num[fail[k]][m])
				{
					tmpt = fail[i];
					fail[i] = fail[k];
					fail[k] = tmpt;
				}
			}
		}
	}
}
void output(char num[][8], char name[][9], int grade[], int fail[], int j)
{
	for (int i = 0; i < j; i++)
	{
		printf("%s", name[fail[i]]);
		printf(" ");
		printf("%s", num[fail[i]]);
		printf(" ");
		printf("%d", grade[fail[i]]);
		printf("\n");
	}
}