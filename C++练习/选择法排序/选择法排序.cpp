#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	int i, j, k, m, n, s, t;
	int a[100];
	for (i = 0; i < 100; i++)
	{
		a[i] = rand() % 101;
		cout << a[i] << "\t";
	}for (i = 0; i < 100; i++)
		for (j = i + 1; j < 100; j++)
			if (a[j] > a[i])
			{
				t = a[i]; a[i] = a[j]; a[j] = t;
			}cout << endl << endl << endl; for (i = 0; i < 100; i++)
				cout << a[i] << "\t";




}










