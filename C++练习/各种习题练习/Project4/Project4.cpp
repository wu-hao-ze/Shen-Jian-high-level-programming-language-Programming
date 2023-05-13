#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

void HUAXIN()
{
	cct_setcolor(0, 12);
	cct_setcursor(3);
	cout << endl << endl << endl;
	for (int i = 0; i < 24; i++)
		cout << ' ';
	for (int i = 0; i < 6; i++)
	{
		cout << "★";
		Sleep(30);
	}
	for (int i = 0; i < 14; i++)
		cout << ' ';
	for (int i = 0; i < 6; i++)
	{
		cout << "★";
		Sleep(30);
	}
	cout << endl;


	for (int i = 0; i < 22; i++)
		cout << ' ';
	for (int i = 0; i < 8; i++)
	{
		cout << "★";
		Sleep(30);
	}
	for (int i = 0; i < 10; i++)
		cout << ' ';
	for (int i = 0; i < 8; i++)
	{
		cout << "★";
		Sleep(30);
	}
	cout << endl;

	for (int i = 0; i < 20; i++)
		cout << ' ';
	for (int i = 0; i < 10; i++)
	{
		cout << "★";
		Sleep(30);
	}
	for (int i = 0; i < 6; i++)
		cout << ' ';
	for (int i = 0; i < 10; i++)
	{
		cout << "★";
		Sleep(30);
	}
	cout << endl;

	for (int i = 0; i < 18; i++)
		cout << ' ';
	for (int i = 0; i < 12; i++)
	{
		cout << "★";
		Sleep(30);
	}
	for (int i = 0; i < 2; i++)
		cout << ' ';
	for (int i = 0; i < 12; i++)
	{
		cout << "★";
		Sleep(30);
	}
	cout << endl;

	for (int i = 0; i < 16; i++)
		cout << ' ';
	for (int i = 0; i < 27; i++)
	{
		cout << "★";
		Sleep(30);
	}
	cout << endl;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 14; i++)
			cout << ' ';
		for (int i = 0; i < 29; i++)
		{
			cout << "★";
			Sleep(30);
		}
		cout << endl;
	}
	for (int i = 29; i >= 1; i -= 2)
	{
		for (int j = 0; j < 14 + (29 - i); j++)
			cout << ' ';
		for (int z = 0; z < i; z++)
		{
			cout << "★";
			Sleep(30);
		}
		cout << endl;
	}
}

int main()
{
	//char a[15] = "abcd";
	//char b[4] = "123";

	//string str[] = { "aaa","bbb" };
	//char* p = str[0];
	//cout << *p;
	//string name = "chain";
	//char* q = &name[0];
	//string* q1 = &name;
	//cout << q1;




	cct_setconsoleborder(120, 35, 120, 200);
	while (1)
	{
		cout << "请输入你老公的昵称缩写：";
		char str[200];
		cin >> str;
		if (strcmp(str, "whz") == 0 || strcmp(str, "whz") == 0)
		{
			HUAXIN();
			break;
		}
		else
			cout << "他妈的，这就是你老公？你在逗我！" << endl;
	}
	getchar();                             
	getchar();                                          
	cct_setcolor(0, 7);                                            
	cct_setcursor(2);                                   
	return 0;
}
