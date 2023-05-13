/* 1953729 信09 吴浩泽 */

/* -----------------------------------------

	 本文件功能：
	1、放被 hanoi_main.cpp/hanoi_menu.cpp 中的各函数调用的菜单各项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
using namespace std;

static int x = 1;
static int t = 1;
static int a[10] = {}, b[10] = {}, c[10] = {};
static int top1 = 0, top2 = 0, top3 = 0;

void hanoi(int n, char src, char tmp, char dst, int num)                
{
	if (n == 1)
		choose(n, src, tmp, dst, num);
	else
	{
		hanoi(n - 1, src, dst, tmp, num);
		choose(n, src, tmp, dst, num);
		hanoi(n - 1, tmp, src, dst, num);
	}
}

void choose(int n, char src, char tmp, char dst, int num)              
{
	if (src == 'A' && dst == 'B')
		b[top2++] = a[--top1];
	else if (src == 'A' && dst == 'C')
		c[top3++] = a[--top1];
	else if (src == 'B' && dst == 'C')
		c[top3++] = b[--top2];
	else if (src == 'B' && dst == 'A')
		a[top1++] = b[--top2];
	else if (src == 'C' && dst == 'A')
		a[top1++] = c[--top3];
	else
		b[top2++] = c[--top3];
	if (num == 1)
		first(n, src, dst);
	else if (num == 2)
		second(n, src, dst);
	else if (num == 3)
		heng(n, src, dst);
	else if (num == 4)
		fourth(n, src, dst, num);
	else if (num == 8)
		eighth(n, src, dst, num);
}

void draw(int n, char src, char dst, int num)
{
	if (num != 5)
	{
		cct_gotoxy(0, 0);
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
	}
	cct_setcursor(3);
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(33, 15, ' ', 14, 0, 23);
	cct_showch(65, 15, ' ', 14, 0, 23);
	for (int y = 14; y >= 3; y--)
	{
		Sleep(50);
		cct_showch(12, y, ' ', 14, 0, 1);
		cct_showch(44, y, ' ', 14, 0, 1);
		cct_showch(76, y, ' ', 14, 0, 1);
	}
	if (num == 6 || num == 7 || num == 8 || num == 9)
		drawplate(n, src, dst, num);
	if (num == 7)
	{
		if (src == 'A' && dst == 'B')
			b[top2++] = a[--top1];
		else if (src == 'A' && dst == 'C')
			c[top3++] = a[--top1];
		else if (src == 'B' && dst == 'C')
			c[top3++] = b[--top2];
		else if (src == 'B' && dst == 'A')
			a[top1++] = b[--top2];
		else if (src == 'C' && dst == 'A')
			a[top1++] = c[--top3];
		else
			b[top2++] = c[--top3];
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 37);
	if (num == 9)
	{
		cct_gotoxy(0, 34);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		cct_setcursor(2);
	}
}

void drawplate(int n, char src, char dst, int num)                         
{
	int x, y = 14;
	if (src == 'A')
		x = 12;
	else if (src == 'B')
		x = 44;
	else if (src == 'C')
		x = 76;
	int color = n;
	for (int i = 0; i < n; i++)
	{
		Sleep(30);
		cct_showch(x - color, y, ' ', color, 0, 2 * color + 1);
		color--;
		y--;
	}
}

void first(int n, char src, char dst)
{
	cout << setw(2) << n << "#" << " " << src << "---->" << dst << endl;
}

void second(int n, char src, char dst)
{
	cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	x++;
}

void heng(int n, char src, char dst)                                 
{
	cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  " << "A:";
	for (int i = 0; i < top1; i++)
		cout << setw(2) << a[i];
	cout << setfill(' ') << setw((10 - top1) * 2 + 1) << ' ' << "B:";
	for (int i = 0; i < top2; i++)
		cout << setw(2) << b[i];
	cout << setfill(' ') << setw((10 - top2) * 2 + 1) << ' ' << "C:";
	for (int i = 0; i < top3; i++)
		cout << setw(2) << c[i];
	cout << setfill(' ') << setw((10 - top3) * 2 + 1) << ' ' << endl;
	x++;
}

void shu(int n, char src, char dst, int num)                           
{
	int ch;
	if (num == 4)
	{
		if (src == 'A')
		{
			ch = 10;
			cct_gotoxy(ch, 11 - top1);
			cout << ' ';
			cct_gotoxy(ch + 1, 11 - top1);
			cout << ' ';
		}
		else if (src == 'B')
		{
			ch = 20;
			cct_gotoxy(ch, 11 - top2);
			cout << ' ';
			cct_gotoxy(ch + 1, 11 - top2);
			cout << ' ';
		}
		else
		{
			ch = 30;
			cct_gotoxy(ch, 11 - top3);
			cout << ' ';
			cct_gotoxy(ch + 1, 11 - top3);
			cout << ' ';
		}

		if (dst == 'A')
		{
			ch = 10;
			cct_gotoxy(ch, 12 - top1);
			cout << setw(2) << n;
		}
		else if (dst == 'B')
		{
			ch = 20;
			cct_gotoxy(ch, 12 - top2);
			cout << setw(2) << n;
		}
		else
		{
			ch = 30;
			cct_gotoxy(ch, 12 - top3);
			cout << setw(2) << n;
		}
	}
	else
	{
		if (src == 'A')
		{
			ch = 10;
			cct_gotoxy(ch, 26 - top1);
			cout << ' ';
			cct_gotoxy(ch + 1, 26 - top1);
			cout << ' ';
		}
		else if (src == 'B')
		{
			ch = 20;
			cct_gotoxy(ch, 26 - top2);
			cout << ' ';
			cct_gotoxy(ch + 1, 26 - top2);
			cout << ' ';
		}
		else
		{
			ch = 30;
			cct_gotoxy(ch, 26 - top3);
			cout << ' ';
			cct_gotoxy(ch + 1, 26 - top3);
			cout << ' ';
		}
		if (dst == 'A')
		{
			ch = 10;
			cct_gotoxy(ch, 27 - top1);
			cout << setw(2) << a[top1 - 1];
		}
		else if (dst == 'B')
		{
			ch = 20;
			cct_gotoxy(ch, 27 - top2);
			cout << setw(2) << b[top2 - 1];
		}
		else
		{
			ch = 30;
			cct_gotoxy(ch, 27 - top3);
			cout << setw(2) << c[top3 - 1];
		}
	}
}

void fourth(int n, char src, char dst, int num)                        
{
	cct_gotoxy(0, 17);
	heng(n, src, dst);
	shu(n, src, dst, num);
	if (t == 0)
		while (_getch() != '\r')
			;
	else
	{
		if (t == 1)
			for (int i = 0; i < 250000; i++)
				;
		else
			Sleep(t);
	}
}

void eighth(int n, char src, char dst, int num)                
{
	cct_setcolor(0, 7);
	cct_gotoxy(0, 32);
	heng(n, src, dst);
	shu(n, src, dst, num);
	move(n, src, dst, num);
	if (t == 0)
		while (_getch() != '\r')
			;
	else
	{
		if (t == 1)
			for (int i = 0; i < 250000; i++)
				;
		else
			Sleep(t);
	}
	cct_setcolor(0, 7);
}

void input(int* pn, char* ps, char* pt, char* pd, int num)                    
{
	if (num == 1 || num == 2 || num == 3 || num == 4 || num == 6 || num == 7 || num == 8 || num == 9)
	{
		while (1)
		{
			cout << "请输入汉诺塔的层数(1-10)" << endl;
			cin >> *pn;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请输入汉诺塔的层数(1-10)" << endl;
				cin >> *pn;
			}
			if (*pn >= 1 && *pn <= 10)
				break;
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		cin.clear();
		cin.ignore(1024, '\n');
		while (1)
		{
			cout << "请输入起始柱(A-C)" << endl;
			cin >> *ps;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请输入起始柱(A-C)" << endl;
				cin >> *ps;
			}
			if (*ps == 'A' || *ps == 'B' || *ps == 'C' || *ps == 'a' || *ps == 'b' || *ps == 'c')
				break;
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		cin.clear();
		cin.ignore(1024, '\n');
		while (1)
		{
			cout << "请输入目标柱(A-C)" << endl;
			cin >> *pd;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "请输入目标柱(A-C)" << endl;
				cin >> *pd;
			}
			if (*pd == *ps || (*pd - *ps) == 32 || (*pd - *ps) == -32)
			{
				if (*ps > 95)
					*ps = *ps - 32;
				cout << "目标柱(" << *ps << ")不能与起始柱(" << *ps << ")相同" << endl;
				continue;
			}
			if (*pd == 'A' || *pd == 'B' || *pd == 'C' || *pd == 'a' || *pd == 'b' || *pd == 'c')
				break;
			else
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		cin.clear();
		cin.ignore(1024, '\n');
		if (*ps > 95)
			*ps = *ps - 32;
		if (*pd > 95)
			*pd = *pd - 32;
		if (*ps == 'A' && *pd == 'B')
			*pt = 'C';
		if (*ps == 'A' && *pd == 'C')
			*pt = 'B';
		if (*ps == 'B' && *pd == 'A')
			*pt = 'C';
		if (*ps == 'B' && *pd == 'C')
			*pt = 'A';
		if (*ps == 'C' && *pd == 'B')
			*pt = 'A';
		if (*ps == 'C' && *pd == 'A')
			*pt = 'B';
		if (*ps == 'A')
		{
			top1 = *pn;
			top2 = 0;
			top3 = 0;
			for (int i = *pn; i >= 1; i--)
				a[i - 1] = *pn - i + 1;
			for (int i = 0; i < 10; i++)
			{
				b[i] = 0;
				c[i] = 0;
			}
		}
		else if (*ps == 'B')
		{
			top1 = 0;
			top2 = *pn;
			top3 = 0;
			for (int i = *pn; i >= 1; i--)
				b[i - 1] = *pn - i + 1;
			for (int i = 0; i < 10; i++)
			{
				a[i] = 0;
				c[i] = 0;
			}
		}
		else
		{
			top1 = 0;
			top2 = 0;
			top3 = *pn;
			for (int i = *pn; i >= 1; i--)
				c[i - 1] = *pn - i + 1;
			for (int i = 0; i < 10; i++)
			{
				a[i] = 0;
				b[i] = 0;
			}
		}
		if (num == 4 || num == 8 || num == 9)
		{
			if (num == 4 || num == 8)
			{
				while (1)
				{
					cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
					cin >> t;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
						cin >> t;
					}
					if (t >= 0 && t <= 5)
						break;
					else
					{
						cin.clear();
						cin.ignore(1024, '\n');
					}
				}
				cin.clear();
				cin.ignore(1024, '\n');
				cct_cls();
				cout << "从 " << *ps << " 移动到 " << *pd << ", 共 " << *pn << " 层, 延时设置为 " << t << endl;
				if (t == 0)
					t = 0;
				else if (t == 1)
					t = 200;
				else if (t == 2)
					t = 100;
				else if (t == 3)
					t = 50;
				else if (t == 4)
					t = 10;
				else
					t = 1;
			}
			if (num == 9)
				cct_cls();
			if (num == 4)
				cct_gotoxy(0, 17);
			else
				cct_gotoxy(0, 32);
			if (*ps == 'A')
			{
				cout << "初始:                A:";
				for (int i = *pn; i >= 1; i--)
					cout << setw(2) << i;
				cout << setfill(' ') << setw(2 * (10 - *pn) + 1) << ' ';
				cout << "B:                     C:" << endl;
			}
			else if (*ps == 'B')
			{
				cout << "初始:                A:                     B:";
				for (int i = *pn; i >= 1; i--)
					cout << setw(2) << i;
				cout << setfill(' ') << setw(2 * (10 - *pn) + 1) << ' ' << "C:" << endl;
			}
			else
			{
				cout << "初始:                A:                     B:                     C:";
				for (int i = *pn; i >= 1; i--)
					cout << setw(2) << i;
				cout << endl;
			}
			if (num == 8 || num == 9)
			{
				cct_gotoxy(11, 28);
				putchar('A');
				cct_gotoxy(21, 28);
				putchar('B');
				cct_gotoxy(31, 28);
				putchar('C');
				cct_gotoxy(9, 27);
				for (int i = 0; i <= 24; i++)
					putchar('=');
				int ch;
				if (*ps == 'A')
					ch = 10;
				else if (*ps == 'B')
					ch = 20;
				else
					ch = 30;
				cct_gotoxy(ch, 27 - *pn);
				int y = 27 - *pn;
				for (int j = 1; j <= *pn; j++)
				{
					cout << setw(2) << j;
					y++;
					if (y != 27)
						cct_gotoxy(ch, y);
				}
			}
			else
			{
				cct_gotoxy(11, 13);
				putchar('A');
				cct_gotoxy(21, 13);
				putchar('B');
				cct_gotoxy(31, 13);
				putchar('C');
				cct_gotoxy(9, 12);
				for (int i = 0; i <= 24; i++)
					putchar('=');
				int ch;
				if (*ps == 'A')
					ch = 10;
				else if (*ps == 'B')
					ch = 20;
				else
					ch = 30;
				cct_gotoxy(ch, 12 - *pn);
				int y = 12 - *pn;
				for (int j = 1; j <= *pn; j++)
				{
					cout << setw(2) << j;
					y++;
					if (y != 12)
						cct_gotoxy(ch, y);
				}
			}
			if (num == 8 || num == 9)
				draw(*pn, *ps, *pd, num);
			if (t == 0)
				while (_getch() != '\r')
					;
			else
				Sleep(t);
		}
	}
	else
		;
}

int end(int num)                                                        
{
	x = 1;
	if (num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		cct_gotoxy(0, 37);
	cout << endl;
	cct_setcursor(2);
	cct_setcolor(0, 7);
	cout << "按回车键继续";
	while (_getch() != '\r')
		;
	cct_cls();
	num = menu();
	return num;
}

void ninth(int n, char src, char tmp, char dst, int num)                         
{
	while (1)
	{
		char whz[25] = {};
		int i = 0;
		while (!(i == 3 && whz[2] == '\r' || i == 2 && (whz[0] == 'q' || whz[0] == 'Q') && whz[1] == '\r'))
		{
			if (i == 20)
			{
				cct_showch(60, 34, ' ', 0, 7, 20);
				cct_gotoxy(60, 34);
				i = 0;
			}
			whz[i] = _getche();
			if (whz[i] == ' ')
			{
				cout << '\b';
				i--;
			}
			if (whz[i] == '\b')
			{
				if (i == 0)
					cout << ' ';
				else
					cout << whz[i - 1];
				i--;
			}
			i++;
			if (!(i == 3 && whz[2] == '\r' || i == 2 && (whz[0] == 'q' || whz[0] == 'Q') && whz[1] == '\r') && whz[i - 1] == '\r')
			{
				cct_showch(60, 34, ' ', 0, 7, 20);
				cct_gotoxy(60, 34);
				i = 0;
			}
		}
		src = whz[0];
		tmp = whz[1];
		if (src == 'q' || src == 'Q')
		{
			cout << endl;
			cout << "游戏中止!!!!!" << endl;
			break;
		}
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && (tmp == 'A' || tmp == 'B' || tmp == 'C' || tmp == 'a' || tmp == 'b' || tmp == 'c'))
		{
			if (tmp != src && (tmp - src) != 32 && (tmp - src) != -32)
			{
				if (src > 95)
					src = src - 32;
				if (tmp > 95)
					tmp = tmp - 32;
				if (src == 'A' && top1 == 0 || src == 'B' && top2 == 0 || src == 'C' && top3 == 0)
				{
					cout << endl;
					cout << "源柱为空!";
					Sleep(1000);
					cct_showch(0, 35, ' ', 0, 7, 30);
					cct_showch(60, 34, ' ', 0, 7, 30);
					cct_gotoxy(60, 34);
					continue;
				}
				else
				{
					if (src == 'A' && tmp == 'B')
					{
						if (top2 == 0)
							;
						else if (b[top2 - 1] != 0 && a[top1 - 1] > b[top2 - 1])
						{
							feifa();
							continue;
						}
					}
					if (src == 'A' && tmp == 'C')
					{
						if (top3 == 0)
							;
						else if (c[top3 - 1] != 0 && a[top1 - 1] > c[top3 - 1])
						{
							feifa();
							continue;
						}
					}
					if (src == 'B' && tmp == 'A')
					{
						if (top1 == 0)
							;
						else if (a[top1 - 1] != 0 && b[top2 - 1] > a[top1 - 1])
						{
							feifa();
							continue;
						}
					}
					if (src == 'B' && tmp == 'C')
					{
						if (top3 == 0)
							;
						else if (c[top3 - 1] != 0 && b[top2 - 1] > c[top3 - 1])
						{
							feifa();
							continue;
						}
					}
					if (src == 'C' && tmp == 'A')
					{
						if (top1 == 0)
							;
						else if (a[top1 - 1] != 0 && c[top3 - 1] > a[top1 - 1])
						{
							feifa();
							continue;
						}
					}
					if (src == 'C' && tmp == 'B')
					{
						if (top2 == 0)
							;
						else if (b[top2 - 1] != 0 && c[top3 - 1] > b[top2 - 1])
						{
							feifa();
							continue;
						}
					}
					cct_gotoxy(0, 32);
					if (src == 'A' && tmp == 'B')
						b[top2++] = a[--top1];
					else if (src == 'A' && tmp == 'C')
						c[top3++] = a[--top1];
					else if (src == 'B' && tmp == 'C')
						c[top3++] = b[--top2];
					else if (src == 'B' && tmp == 'A')
						a[top1++] = b[--top2];
					else if (src == 'C' && tmp == 'A')
						a[top1++] = c[--top3];
					else
						b[top2++] = c[--top3];
					heng(n, src, tmp);
					shu(n, src, tmp, num);
					t = 1;
					move(n, src, tmp, num);
					if (dst == 'A' && top1 == n || dst == 'B' && top2 == n || dst == 'C' && top3 == n)
					{
						cct_setcolor(0, 7);
						cct_gotoxy(0, 35);
						cout << "游戏结束!!!!!" << endl;
						break;
					}
					cct_showch(60, 34, ' ', 0, 7, 30);
					cct_gotoxy(60, 34);
				}
			}
			else
			{
				cct_showch(60, 34, ' ', 0, 7, 30);
				cct_gotoxy(60, 34);
			}
		}
		else
		{
			cct_showch(60, 34, ' ', 0, 7, 30);
			cct_gotoxy(60, 34);
		}
	}
}

void move(int n, char src, char dst, int num)                           
{
	if (src == 'A' && dst == 'B')
	{
		int x = 12, y;
		for (y = 14 - top1; y > 1; y--)
		{
			cct_showch(x - a[top1], y, ' ', 0, 0, a[top1]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, a[top1]);
			cct_showch(x - a[top1], y - 1, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - a[top1]; x < 44 - a[top1]; x++)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * a[top1] + 1);
			cct_showch(x + 1, y, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top2; y++)
		{
			cct_showch(x, y, ' ', 0, 0, a[top1]);
			if (y < 3)
				cct_showch(x + a[top1], y, ' ', 0, 0, 1);
			else
				cct_showch(x + a[top1], y, ' ', 14, 0, 1);
			cct_showch(x + a[top1] + 1, y, ' ', 0, 0, a[top1]);
			cct_showch(x, y + 1, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
	else if (src == 'A' && dst == 'C')
	{
		int x = 12, y;
		for (y = 14 - top1; y > 1; y--)
		{
			cct_showch(x - a[top1], y, ' ', 0, 0, a[top1]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, a[top1]);
			cct_showch(x - a[top1], y - 1, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - a[top1]; x < 76 - a[top1]; x++)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * a[top1] + 1);
			cct_showch(x + 1, y, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top3; y++)
		{
			cct_showch(x, y, ' ', 0, 0, a[top1]);
			if (y < 3)
				cct_showch(x + a[top1], y, ' ', 0, 0, 1);
			else
				cct_showch(x + a[top1], y, ' ', 14, 0, 1);
			cct_showch(x + a[top1] + 1, y, ' ', 0, 0, a[top1]);
			cct_showch(x, y + 1, ' ', a[top1], 0, 2 * a[top1] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
	else if (src == 'B' && dst == 'A')
	{
		int x = 44, y;
		for (y = 14 - top2; y > 1; y--)
		{
			cct_showch(x - b[top2], y, ' ', 0, 0, b[top2]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, b[top2]);
			cct_showch(x - b[top2], y - 1, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - b[top2]; x > 12 - b[top2]; x--)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * b[top2] + 1);
			cct_showch(x - 1, y, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top1; y++)
		{
			cct_showch(x, y, ' ', 0, 0, b[top2]);
			if (y < 3)
				cct_showch(x + b[top2], y, ' ', 0, 0, 1);
			else
				cct_showch(x + b[top2], y, ' ', 14, 0, 1);
			cct_showch(x + b[top2] + 1, y, ' ', 0, 0, b[top2]);
			cct_showch(x, y + 1, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
	else if (src == 'B' && dst == 'C')
	{
		int x = 44, y;
		for (y = 14 - top2; y > 1; y--)
		{
			cct_showch(x - b[top2], y, ' ', 0, 0, b[top2]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, b[top2]);
			cct_showch(x - b[top2], y - 1, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - b[top2]; x < 76 - b[top2]; x++)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * b[top2] + 1);
			cct_showch(x + 1, y, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top3; y++)
		{
			cct_showch(x, y, ' ', 0, 0, b[top2]);
			if (y < 3)
				cct_showch(x + b[top2], y, ' ', 0, 0, 1);
			else
				cct_showch(x + b[top2], y, ' ', 14, 0, 1);
			cct_showch(x + b[top2] + 1, y, ' ', 0, 0, b[top2]);
			cct_showch(x, y + 1, ' ', b[top2], 0, 2 * b[top2] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
	else if (src == 'C' && dst == 'A')
	{
		int x = 76, y;
		for (y = 14 - top3; y > 1; y--)
		{
			cct_showch(x - c[top3], y, ' ', 0, 0, c[top3]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, c[top3]);
			cct_showch(x - c[top3], y - 1, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - c[top3]; x > 12 - c[top3]; x--)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * c[top3] + 1);
			cct_showch(x - 1, y, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top1; y++)
		{
			cct_showch(x, y, ' ', 0, 0, c[top3]);
			if (y < 3)
				cct_showch(x + c[top3], y, ' ', 0, 0, 1);
			else
				cct_showch(x + c[top3], y, ' ', 14, 0, 1);
			cct_showch(x + c[top3] + 1, y, ' ', 0, 0, c[top3]);
			cct_showch(x, y + 1, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
	else if (src == 'C' && dst == 'B')
	{
		int x = 76, y;
		for (y = 14 - top3; y > 1; y--)
		{
			cct_showch(x - c[top3], y, ' ', 0, 0, c[top3]);
			if (y < 3)
				cct_showch(x, y, ' ', 0, 0, 1);
			else
				cct_showch(x, y, ' ', 14, 0, 1);
			cct_showch(x + 1, y, ' ', 0, 0, c[top3]);
			cct_showch(x - c[top3], y - 1, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (x = x - c[top3]; x > 44 - c[top3]; x--)
		{
			cct_showch(x, y, ' ', 0, 0, 2 * c[top3] + 1);
			cct_showch(x - 1, y, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
		for (y = 1; y <= 14 - top2; y++)
		{
			cct_showch(x, y, ' ', 0, 0, c[top3]);
			if (y < 3)
				cct_showch(x + c[top3], y, ' ', 0, 0, 1);
			else
				cct_showch(x + c[top3], y, ' ', 14, 0, 1);
			cct_showch(x + c[top3] + 1, y, ' ', 0, 0, c[top3]);
			cct_showch(x, y + 1, ' ', c[top3], 0, 2 * c[top3] + 1);
			if (t != 0)
			{
				if (t == 1)
					for (int i = 0; i < 250000; i++)
						;
				else
					Sleep(t);
			}
			else
				Sleep(30);
		}
	}
}

void feifa()                                          
{
	cout << endl;
	cout << "大盘压小盘，非法移动!";
	Sleep(1000);
	cct_showch(0, 35, ' ', 0, 7, 30);
	cct_showch(60, 34, ' ', 0, 7, 30);
	cct_gotoxy(60, 34);
}

