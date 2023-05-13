#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <conio.h>
#include <cstdlib>
using namespace std;

int judge(int num)
{
	int i;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
			break;
	}
	if (i == num)
		return 1;
	else
		return 0;
}

void fun(int a[20210509], int num)
{
	a[num - 1] = 1;
	static int b[20210509] = {};
	int i, j = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			b[j] = i;
			j++;
		}
	}
	for (int t = 0; t < j; t++)
	{
		a[num - 1] += a[b[t] - 1];
	}
}

int main()
{
	static int a[20210509] = {};
	int num = 4;
	a[0] = 1, a[1] = 1, a[2] = 1;
	for (; num <= 20210509; num++)
	{
		if (judge(num) == 1)
			a[num - 1] = 1;
		else
			fun(a, num);
	}
	double sum = 0;
	for (int i = 0; i < 20210509; i++)
		sum += a[i];
	cout << setiosflags(ios::fixed) << setprecision(17) << sum;
	return 0;
}
