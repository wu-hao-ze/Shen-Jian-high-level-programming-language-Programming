#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
void drop(int m)
{

	for (; m >= 10; )
	{
		if ((m / 10) % 10 > (m % 10))m = m / 10;
		else break;
	}
	if (m < 10)cout << "是降序数" << endl;
	else cout << "不是" << endl;

}
int calculate(int& sum)
{
	int i = 0;
	for (; sum != 0;)
	{
		i = i + sum % 10;
		sum = sum / 10;


	}
	return (i);
}
int main()
{
	int x;
	cin >> x;
	drop(x);
	x = calculate(x);
	cout << x;




}










