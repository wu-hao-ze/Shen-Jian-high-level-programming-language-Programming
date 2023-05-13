#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	int s[100];
	int i, j, k, m, n, t;
	for (i = 0; i < 20; i++)
		s[i] = rand() % 100;
	for (i = 0; i < 20; i++)
	{
		cout << s[i] << "\t";
		if ((i + 1) % 5 == 0)cout << endl;
	}k = s[0];
	for (i = 0; i < 20; i++)
		if (s[i] > k) { k = s[i]; j = i; }
	cout << "max=" << k << " " << "num=" << j + 1 << endl;
	for (i = 0; i < 20; i++)
		for (j = i + 1; j < 20; j++)
			if (s[i] > s[j]) { t = s[i]; s[i] = s[j]; s[j] = t; }
	for (i = 0; i < 20; i++)
	{
		cout << s[i] << "\t";
		if ((i + 1) % 5 == 0)cout << endl;
	}cout << endl << endl;
	for (i = 0; i < 20; i++)
	{
		if (s[i] > 50) break;
	}
	j = i;
	for (i = 20; i >= j; i--)
		s[i] = s[i - 1];
	s[j] = 50;
	for (i = 0; i < 21; i++)
	{
		cout << s[i] << "\t";
		if ((i + 1) % 5 == 0)cout << endl;
	}cout << endl << endl;
	for (i = 0; i < 21; i++)
		if (s[i] == 62)break;
	j = i;
	for (i = j; i < 21; i++)
		s[i] = s[i + 1];
	for (i = 0; i < 20; i++)
	{
		cout << s[i] << "\t";
		if ((i + 1) % 5 == 0)cout << endl;
	}

}