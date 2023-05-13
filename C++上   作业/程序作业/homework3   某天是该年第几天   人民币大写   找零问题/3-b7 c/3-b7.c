/* 1953729 ĞÅ09 ÎâºÆÔó */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("ÇëÊäÈëÒ»¸ö[0-100ÒÚ)¼äµÄÊı:\n");
	double n;
	scanf("%lf",&n);
	int a = (int)((long long int)(n) / 1000000000);
	int b = (int)((long long int)(n) / 100000000 % 10);
	int c = (int)((long long int)(n) / 10000000 % 10);
	int d = (int)((long long int)(n) / 1000000 % 10);
	int e = (int)((long long int)(n) / 100000 % 10);
	int f = (int)((long long int)(n) / 10000 % 10);
	int g = (int)((long long int)(n) / 1000 % 10);
	int h = (int)((long long int)(n) / 100 % 10);
	int i = (int)((long long int)(n) / 10 % 10);
	int j = (int)((long long int)(n) % 10);
	long long int t = (long long int)(n);
	double x = n - t + 0.0004;
	int x1 = (int)(x * 10) % 10;
	int x2 = (int)(x * 100) % 10;
	printf("´óĞ´½á¹ûÊÇ:\n");
	if (a != 0)
	{
		switch (a)
		{
			case 1:
				printf ( "Ò¼Ê°");
				break;		   
			case 2:			   
				printf ( "·¡Ê°");
				break;		   
			case 3:			   
				printf ( "ÈşÊ°");
				break;		   
			case 4:			   
				printf ( "ËÁÊ°");
				break;		   
			case 5:			   
				printf ( "ÎéÊ°");
				break;		   
			case 6:			   
				printf ( "Â½Ê°");
				break;		   
			case 7:			   
				printf ( "ÆâÊ°");
				break;		   
			case 8:			  
				printf ( "°ÆÊ°");
				break;		   
			case 9:			   
				printf ( "¾ÁÊ°");
				break;
		}
		if (b == 0)
			printf ( "ÒÚ");
	}
	if (b != 0)
	{
		switch (b)
		{
			case 1:
				printf ( "Ò¼ÒÚ");
				break;
			case 2:
				printf ( "·¡ÒÚ");
				break;
			case 3:
				printf ( "ÈşÒÚ");
				break;
			case 4:
				printf ( "ËÁÒÚ");
				break;
			case 5:
				printf ( "ÎéÒÚ");
				break;
			case 6:
				printf ( "Â½ÒÚ");
				break;
			case 7:
				printf ( "ÆâÒÚ");
				break;
			case 8:
				printf ( "°ÆÒÚ");
				break;
			case 9:
				printf ( "¾ÁÒÚ");
				break;
		}
	}
	if (c != 0)
	{
		switch (c)
		{
			case 1:
				printf ( "Ò¼Çª");
				break;
			case 2:
				printf ( "·¡Çª");
				break;
			case 3:
				printf ( "ÈşÇª");
				break;
			case 4:
				printf ( "ËÁÇª");
				break;
			case 5:
				printf ( "ÎéÇª");
				break;
			case 6:
				printf ( "Â½Çª");
				break;
			case 7:
				printf ( "ÆâÇª");
				break;
			case 8:
				printf ( "°ÆÇª");
				break;
			case 9:
				printf ( "¾ÁÇª");
				break;
		}
		if (d == 0 && e == 0 && f == 0)
			printf ( "Íò");
		if (d == 0 && e == 0 && f != 0)
			printf ( "Áã");
		if (d == 0 && e != 0)
			printf ( "Áã");
	}
	if (d != 0)
	{
		if ((a != 0 || b != 0) && c == 0)
			printf ( "Áã");
		switch (d)
		{
			case 1:
				printf ( "Ò¼°Û");
				break;
			case 2:
				printf ( "·¡°Û");
				break;
			case 3:
				printf ( "Èş°Û");
				break;
			case 4:
				printf ( "ËÁ°Û");
				break;
			case 5:
				printf ( "Îé°Û");
				break;
			case 6:
				printf ( "Â½°Û");
				break;
			case 7:
				printf ( "Æâ°Û");
				break;
			case 8:
				printf ( "°Æ°Û");
				break;
			case 9:
				printf ( "¾Á°Û");
				break;
		}
		if (e == 0 && f == 0)
			printf ( "Íò");
		if (e == 0 && f != 0)
			printf ( "Áã");
	}
	if (e != 0)
	{
		if ((a != 0 || b != 0) && (d == 0 && c == 0))
			printf ( "Áã");
		switch (e)
		{
			case 1:
				printf ( "Ò¼Ê°");
				break;
			case 2:
				printf ( "·¡Ê°");
				break;
			case 3:
				printf ( "ÈşÊ°");
				break;
			case 4:
				printf ( "ËÁÊ°");
				break;
			case 5:
				printf ( "ÎéÊ°");
				break;
			case 6:
				printf ( "Â½Ê°");
				break;
			case 7:
				printf ( "ÆâÊ°");
				break;
			case 8:
				printf ( "°ÆÊ°");
				break;
			case 9:
				printf ( "¾ÁÊ°");
				break;
		}
		if (f == 0)
			printf ( "Íò");
	}
	if (f != 0)
	{
		if ((a != 0 || b != 0) && c == 0 && d == 0 && e == 0)
			printf ( "Áã");
		switch (f)
		{
			case 1:
				printf ( "Ò¼Íò");
				break;
			case 2:
				printf ( "·¡Íò");
				break;
			case 3:
				printf ( "ÈşÍò");
				break;
			case 4:
				printf ( "ËÁÍò");
				break;
			case 5:
				printf ( "ÎéÍò");
				break;
			case 6:
				printf ( "Â½Íò");
				break;
			case 7:
				printf ( "ÆâÍò");
				break;
			case 8:
				printf ( "°ÆÍò");
				break;
			case 9:
				printf ( "¾ÁÍò");
				break;
		}
	}
	if (g != 0)
	{
		switch (g)
		{
			case 1:
				printf ( "Ò¼Çª");
				break;
			case 2:
				printf ( "·¡Çª");
				break;
			case 3:
				printf ( "ÈşÇª");
				break;
			case 4:
				printf ( "ËÁÇª");
				break;
			case 5:
				printf ( "ÎéÇª");
				break;
			case 6:
				printf ( "Â½Çª");
				break;
			case 7:
				printf ( "ÆâÇª");
				break;
			case 8:
				printf ( "°ÆÇª");
				break;
			case 9:
				printf ( "¾ÁÇª");
				break;
		}
		if (h == 0 && i == 0 && j == 0)
			printf ( "Ô²");
		if (h == 0 && i == 0 && j != 0)
			printf ( "Áã");
		if (h == 0 && i != 0)
			printf ( "Áã");
	}
	if (h != 0)
	{
		if ((a != 0 || b != 0) && g == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0)
			printf ( "Áã");
		switch (h)
		{
			case 1:
				printf ( "Ò¼°Û");
				break;
			case 2:
				printf ( "·¡°Û");
				break;
			case 3:
				printf ( "Èş°Û");
				break;
			case 4:
				printf ( "ËÁ°Û");
				break;
			case 5:
				printf ( "Îé°Û");
				break;
			case 6:
				printf ( "Â½°Û");
				break;
			case 7:
				printf ( "Æâ°Û");
				break;
			case 8:
				printf ( "°Æ°Û");
				break;
			case 9:
				printf ( "¾Á°Û");
				break;
		}
		if (i == 0 && j == 0)
			printf ( "Ô²");
		if (i == 0 && j != 0)
			printf ( "Áã");
	}
	if (i != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0)
			printf ( "Áã");
		switch (i)
		{
			case 1:
				printf ( "Ò¼Ê°");
				break;
			case 2:
				printf ( "·¡Ê°");
				break;
			case 3:
				printf ( "ÈşÊ°");
				break;
			case 4:
				printf ( "ËÁÊ°");
				break;
			case 5:
				printf ( "ÎéÊ°");
				break;
			case 6:
				printf ( "Â½Ê°");
				break;
			case 7:
				printf ( "ÆâÊ°");
				break;
			case 8:
				printf ( "°ÆÊ°");
				break;
			case 9:
				printf ( "¾ÁÊ°");
				break;
		}
		if (j == 0)
			printf ( "Ô²");
	}
	if (j != 0)
	{
		if ((a != 0 || b != 0) && g == 0 && h == 0 && i == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0)
			printf ( "Áã");
		switch (j)
		{
			case 1:
				printf ( "Ò¼Ô²");
				break;
			case 2:
				printf ( "·¡Ô²");
				break;
			case 3:
				printf ( "ÈşÔ²");
				break;
			case 4:
				printf ( "ËÁÔ²");
				break;
			case 5:
				printf ( "ÎéÔ²");
				break;
			case 6:
				printf ( "Â½Ô²");
				break;
			case 7:
				printf ( "ÆâÔ²");
				break;
			case 8:
				printf ( "°ÆÔ²");
				break;
			case 9:
				printf ( "¾ÁÔ²");
				break;
		}
	}
	if ((a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) && g == 0 && h == 0 && i == 0 && j == 0)
		printf ( "Ô²");
	if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && x1 == 0 && x2 == 0)
		printf ( "ÁãÔ²");
	if (x1 == 0 && x2 == 0)
		printf ( "Õû");
	if (x1 != 0)
	{
		switch (x1)
		{
			case 1:
				printf ( "Ò¼½Ç");
				break;
			case 2:
				printf ( "·¡½Ç");
				break;
			case 3:
				printf ( "Èş½Ç");
				break;
			case 4:
				printf ( "ËÁ½Ç");
				break;
			case 5:
				printf ( "Îé½Ç");
				break;
			case 6:
				printf ( "Â½½Ç");
				break;
			case 7:
				printf ( "Æâ½Ç");
				break;
			case 8:
				printf ( "°Æ½Ç");
				break;
			case 9:
				printf ( "¾Á½Ç");
				break;
		}
		if (x2 == 0)
			printf ( "Õû");
	}
	if (x2 != 0)
	{
		if ((a != 0 || b != 0) && x1 == 0 || (c != 0 || d != 0 || e != 0 || f != 0) && x1 == 0 || (g != 0 || h != 0 || i != 0 || j != 0) && x1 == 0)
			printf ( "Áã");
		switch (x2)
		{
			case 1:
				printf ( "Ò¼·Ö");
				break;
			case 2:
				printf ( "·¡·Ö");
				break;
			case 3:
				printf ( "Èş·Ö");
				break;
			case 4:
				printf ( "ËÁ·Ö");
				break;
			case 5:
				printf ( "Îé·Ö");
				break;
			case 6:
				printf ( "Â½·Ö");
				break;
			case 7:
				printf ( "Æâ·Ö");
				break;
			case 8:
				printf ( "°Æ·Ö");
				break;
			case 9:
				printf ( "¾Á·Ö");
				break;
		}
	}
	printf ( "\n");
	return 0;
}
