/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, i, x, a = 0;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		scanf("%d%d", &year, &month);
	    if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
		    break;
		else
		{
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month); 
		scanf("%d", &x);
		if (x >= 0 && x <= 6)
			break;
		else
		{
			printf("输入非法，请重新输入\n");
			rewind(stdin);
		}
	}
	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	switch (x)
	{
		case 0:
			printf ( "   1       2       3       4       5       6       7\n");
			break;														 
		case 1:															 
			printf ( "           1       2       3       4       5       6\n");
			break;														 
		case 2:															 
			printf ( "                   1       2       3       4       5\n");
			break;														 
		case 3:															 
			printf ( "                           1       2       3       4\n");
			break;														 
		case 4:															 
			printf ( "                                   1       2       3\n");
			break;														
		case 5:															
			printf ( "                                           1       2\n");
			break;														 
		case 6:															 
			printf ( "                                                   1\n");
			break;
	}
	printf ( "   ");
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		for (i = 8 - x; i <= 31; i++)
		{
			printf ("%d", i);
			a = a + 1;
			if (a % 7 == 0)
			{
				printf ( "\n");
				if (i <= 8)
					printf ( "   ");
				else
					printf ( "  ");
				continue;
			}
			if (i <= 8)
				printf ( "       ");
			else
				printf ( "      ");
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		for (i = 8 - x; i <= 30; i++)
		{
			printf("%d", i);
			a = a + 1;
			if (a % 7 == 0)
			{
				printf("\n");
				if (i <= 8)
					printf("   ");
				else
					printf("  ");
				continue;
			}
			if (i <= 8)
				printf("       ");
			else
				printf("      ");
		}
	}
	else
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			for (i = 8 - x; i <= 29; i++)
			{
				printf("%d", i);
				a = a + 1;
				if (a % 7 == 0)
				{
					printf("\n");
					if (i <= 8)
						printf("   ");
					else
						printf("  ");
					continue;
				}
				if (i <= 8)
					printf("       ");
				else
					printf("      ");
			}
		else
			for (i = 8 - x; i <= 28; i++)
			{
				printf("%d", i);
				a = a + 1;
				if (a % 7 == 0)
				{
					printf("\n");
					if (i <= 8)
						printf("   ");
					else
						printf("  ");
					continue;
				}
				if (i <= 8)
					printf("       ");
				else
					printf("      ");
			}
	}
	printf("\n"); 
	return 0;
}
