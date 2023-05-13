#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

void 判断(int a)
{
	while (a >= 10)
	{
		if (a / 10 % 10 <= a % 10)
			a = a / 10;
		else break;
	}if (a < 10)cout << "shi" << endl; else
		cout << "bushi" << endl;
}
void 计算(int& p)
{

	int s = p;
	p = 0;
	for (; s != 0;)
	{
		p = p + s % 10;
		s = s / 10;
	}


}


int main()
{
	int x;
	cin >> x;
	判断(x);
	计算(x
	);
	cout << x;


}

