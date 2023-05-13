/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入年，月，日:\n");
	int year, month, day, sum = 0, t = 0;
	scanf("%d%d%d",&year, &month, &day);
	if (!(month >= 1 && month <= 12))
	{
		t = 1;
		printf("输入错误-月份不正确\n");
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day>31)
			{
				t = 1;
				printf("输入错误-日与月的关系非法\n");
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day>30)
			{
				t = 1;
				printf("输入错误-日与月的关系非法\n");
			}
		}
		else
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				if (day < 1 || day > 29)
				{
					t = 1;
					printf("输入错误-日与月的关系非法\n");
				}
			}
			else if (day < 1 || day > 28)
			{
				t = 1;
				printf("输入错误-日与月的关系非法\n");
			}
		}
	}
	if (t == 0)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			switch (month)
			{
				case 1:
					sum = day; 
					break;
				case 2:
					sum = 31 + day; 
					break;
				case 3:
					sum = 31 + 29 + day; 
					break;
				case 4:
					sum = 31 + 29 + 31 + day; 
					break;
				case 5:
					sum = 31 + 29 + 31 + 30 + day; 
					break;
				case 6:
					sum = 31 + 29 + 31 + 30 + 31 + day; 
					break;
				case 7:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + day; 
					break;
				case 8:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + day; 
					break;
				case 9:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day; 
					break;
				case 10:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day; 
					break;
				case 11:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day; 
					break;
				case 12:
					sum = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day; 
					break;
			}
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, sum);
		}
		else
		{
			switch (month)
			{
				case 1:
					sum = day; 
					break;
				case 2:
					sum = 31 + day; 
					break;
				case 3:
					sum = 31 + 28 + day; 
					break;
				case 4:
					sum = 31 + 28 + 31 + day; 
					break;
				case 5:
					sum = 31 + 28 + 31 + 30 + day; 
					break;
				case 6:
					sum = 31 + 28 + 31 + 30 + 31 + day; 
					break;
				case 7:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + day;
					break;
				case 8:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + day; 
					break;
				case 9:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day; 
					break;
				case 10:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day; 
					break;
				case 11:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day; 
					break;
				case 12:
					sum = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day; 
					break;
			}
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, sum);
		}
	}
	return 0;
}