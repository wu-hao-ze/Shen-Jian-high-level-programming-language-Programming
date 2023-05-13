#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int 最大公约数(int x, int y)
{
	int r;
	for (; x % y != 0;)
	{
		r = x % y;
		x = y; y = r;
	}

	return (y);
}
int 最小公倍数(int x, int y)
{
	int p;
	p = x * y / 最大公约数(x, y);

	return (p);
}
int main()
{
	int m, n, r;
	cin >> m >> n;
	cout << 最大公约数(m, n) << endl;
	cout << 最小公倍数(m, n) << endl;
}

