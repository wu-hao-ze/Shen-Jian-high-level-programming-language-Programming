/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day;
	int zeller(int, int, int);
	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n");
		int num=scanf("%d%d%d", &year, &month, &day);
		if (num != 3)
		{
			printf("�����������������\n");
			rewind(stdin);
		}
		else 
		{
			if (year < 1900 || year > 2100)
			{
				printf("��ݲ���ȷ������������\n");
				continue;
			}
			else if (month < 1 || month > 12)
			{
				printf("�·ݲ���ȷ������������\n");
				continue;
			}
			else
			{
				if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
				{
					if (month == 2 && day >= 1 && day <= 29)
						break;
					else if (month == 2)
					{
						printf("�ղ���ȷ������������\n");
						continue;
					}
				}
				if (!(year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
				{
					if (month == 2 && day >= 1 && day <= 28)
						break;
					else if (month == 2)
					{
						printf("�ղ���ȷ������������\n");
						continue;
					}
				}
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if (day >= 1 && day <= 31)
						break;
					else
					{
						printf("�ղ���ȷ������������\n");
						continue;
					}
				}
				if (month == 4 || month == 6 || month == 9 || month == 11)
				{
					if (day >= 1 && day <= 30)
						break;
					else
					{
						printf("�ղ���ȷ������������\n");
						continue;
					}
				}
			}
		}
	}
	switch (zeller(year, month, day))
	{
		case 0:
			printf ( "������");
			break;			
		case 1:				 
			printf ( "����һ");
			break;			
		case 2:				 
			printf ( "���ڶ�");
			break;			
		case 3:				
			printf ( "������");
			break;			
		case 4:				
			printf ( "������");
			break;			
		case 5:				 
			printf ( "������");
			break;			
		case 6:				 
			printf ( "������");
			break;
	}
	printf("\n");
	return 0;
}

int zeller(int year, int month, int day)
{
	int week;
	int w;
	int y;
	int c;
	if (month >= 3 && month <= 12)
	{
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	else if (month == 1)
	{
		year = year - 1;
		month = 13;
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	else if (month == 2)
	{
		year = year - 1;
		month = 14;
		y = year % 100;
		c = year / 100;
		w = y + (int)(y / 4.0) + (int)(c / 4.0) - 2 * c + (int)(13 * (month + 1) / 5.0) + day - 1;
	}
	for (w; w < 0;)
		w = w + 7;
	week = w % 7;
	return week;
}