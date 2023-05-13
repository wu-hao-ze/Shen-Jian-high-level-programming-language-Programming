/*1953729 信09 吴浩泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "90-02-b1-popstar.h"
using namespace std;

int menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.命令行找出可消除项并标识" << endl;
	cout << "2.命令行完成一次消除（分步骤显示）" << endl;
	cout << "3.命令行完成一关（分步骤显示）" << endl;
	cout << "4.伪图形界面下用鼠标选择一个色块（无分隔线）" << endl;
	cout << "5.伪图形界面完成一次消除（分步骤）" << endl;
	cout << "6.伪图形界面完整版" << endl;
	cout << "0.退出游戏" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[请选择] :";
	while (1)
	{
		char num = _getch();
		if (num >= '0' && num <= '7')
			return num - 48;
	}
}

