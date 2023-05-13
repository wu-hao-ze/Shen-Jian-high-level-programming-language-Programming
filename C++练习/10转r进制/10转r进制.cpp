#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{

	int m, k, i, p = 0, n, r = 16, j;
	int s[100];
	cin >> n;
	char a[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	for (i = 0; n != 0; i++)
	{
		s[i] = n % r;
		n = n / r;

	}
	for (--i; i >= 0; i--)
	{
		n = s[i];
		cout << a[n];
	}

}


















