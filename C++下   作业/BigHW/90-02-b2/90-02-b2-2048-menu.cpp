/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-02-b2-2048.h"
#include "../include/cmd_console_tools.h"
using namespace std;

void menu(int& hang, int& lie, int& score, int& yanshi)
{
	cct_cls();
	cct_setconsoleborder(73, 33, 73, 33);
	cct_setcolor(15, 0);
	cout << "╔══════════════════════════════════╗" << endl;
	for (int i = 0; i < 29; i++)
		cout << "║                                                                    ║" << endl;
	cout << "╚══════════════════════════════════╝";
	cct_gotoxy(2, 2);
	cout << "游戏2048参数设置：" << endl;
	cct_gotoxy(2, 3);
	cout << "请输入行数[5-8]：";
	while (1)
	{
		cin >> hang;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cct_gotoxy(19, 3);
			cout << "                                                   ";
			cct_gotoxy(19, 3);
			cin >> hang;
		}
		if (hang >= 5 && hang <= 8)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else
		{
			cct_gotoxy(19, 3);
			cout << "                                                   ";
			cct_gotoxy(19, 3);
		}
	}
	cct_gotoxy(2, 4);
	cout << "请输入列数[5-8]：";
	while (1)
	{
		cin >> lie;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cct_gotoxy(19, 4);
			cout << "                                                   ";
			cct_gotoxy(19, 4);
			cin >> lie;
		}
		if (lie >= 5 && lie <= 8)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else
		{
			cct_gotoxy(19, 4);
			cout << "                                                   ";
			cct_gotoxy(19, 4);
		}
	}
	cct_gotoxy(2, 5);
	cout << "请输入目标分数[1024/2048/4096]：";
	while (1)
	{
		cin >> score;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cct_gotoxy(34, 5);
			cout << "                                    ";
			cct_gotoxy(34, 5);
			cin >> score;
		}
		if (score == 1024 || score == 2048 || score == 4096)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else
		{
			cct_gotoxy(34, 5);
			cout << "                                    ";
			cct_gotoxy(34, 5);
		}
	}
	cct_gotoxy(2, 6);
	cout << "请输入延时[0-5]：";
	while (1)
	{
		cin >> yanshi;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cct_gotoxy(19, 6);
			cout << "                                                   ";
			cct_gotoxy(19, 6);
			cin >> yanshi;
		}
		if (yanshi >= 0 && yanshi <= 5)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			break;
		}
		else
		{
			cct_gotoxy(19, 6);
			cout << "                                                   ";
			cct_gotoxy(19, 6);
		}
	}
	if (yanshi == 1)
		yanshi = 1;
	if (yanshi == 2)
		yanshi = 10;
	if (yanshi == 3)
		yanshi = 20;
	if (yanshi == 4)
		yanshi = 50;
	if (yanshi == 5)
		yanshi = 100;
}
