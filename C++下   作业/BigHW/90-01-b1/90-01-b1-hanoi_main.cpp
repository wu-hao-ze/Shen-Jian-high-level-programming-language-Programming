/* 1953729 信09 吴浩泽 */

/* -----------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全集，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
using namespace std;
int main()
{
	cct_setconsoleborder(120, 40, 120, 9000);       /* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setfontsize("新宋体", 16);
	int n;
	char src, dst, tmp;
	int* pn = &n;
	char* ps = &src, * pt = &tmp, * pd = &dst;
	int num = menu();
	cout << endl << endl;
	while (1)
	{
		input(pn, ps, pt, pd, num);
		if (num == 0)
		{
			cout << endl << endl;
			break;
		}
		if (num == 1 || num == 2 || num == 3 || num == 4 || num == 8)
			hanoi(n, src, tmp, dst, num);
		else if (num == 5 || num == 6)
		{
			cct_cls();
			draw(n, src, dst, num);
		}
		else if (num == 7)
		{
			cct_cls();
			if (n % 2 != 0)
				draw(n, src, dst, num);
			else
				draw(n, src, tmp, num);
			Sleep(1000);
			if (n % 2 != 0)
				move(n, src, dst, num);
			else
				move(n, src, tmp, num);
		}
		else if (num == 9)
			ninth(n, src, tmp, dst, num);
		num = end(num);
		cout << endl << endl;
	}
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(120, 40, 120, 95);
	return 0;
}

