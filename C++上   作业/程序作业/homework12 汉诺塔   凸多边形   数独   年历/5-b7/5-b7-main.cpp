/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "5-b7.h"
#include <conio.h>
using namespace std;

static int t;
static int str;

int a[10], b[10], c[10];
int top1, top2, top3;
int x = 1;

void hanoi(int n, char src, char tmp, char dst)
{
	if (str == 1)
	{
		if (n == 1)
		{
			cct_gotoxy(0, 17);
			cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  " << "A:";
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
			int ch;
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
		}
		else
		{
			hanoi(n - 1, src, dst, tmp);
			cct_gotoxy(0, 17);
			cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")  " << "A:";
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
			else if (src == 'C' && dst == 'B')
				b[top2++] = c[--top3];
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
			int ch;
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
			hanoi(n - 1, tmp, src, dst);
		}
	}
	else
	{
		if (n == 1)
		{
			cct_gotoxy(0, 17);
			cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
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
			x++;
			int ch;
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
		}
		else
		{
			hanoi(n - 1, src, dst, tmp);
			cct_gotoxy(0, 17);
			cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
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
			else if (src == 'C' && dst == 'B')
				b[top2++] = c[--top3];
			x++;
			int ch;
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
			if (t == 0)
				getchar();
			else
				Sleep(t);
			hanoi(n - 1, tmp, src, dst);
		}
	}
}
int main()
{
	char src, dst, tmp;
	int n;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入汉诺塔的层数(1-10)" << endl;
			cin >> n;
		}
		if (n >= 1 && n <= 10)
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
		cin >> src;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入起始柱(A-C)" << endl;
			cin >> src;
		}
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
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
		cin >> dst;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入目标柱(A-C)" << endl;
			cin >> dst;
		}
		if (dst == src || (dst - src) == 32 || (dst - src) == -32)
		{
			if (src > 95)
				src = src - 32;
			cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
			continue;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');

	if (src > 95)
		src = src - 32;
	if (dst > 95)
		dst = dst - 32;
	if (src == 'A' && dst == 'B')
		tmp = 'C';
	if (src == 'A' && dst == 'C')
		tmp = 'B';
	if (src == 'B' && dst == 'A')
		tmp = 'C';
	if (src == 'B' && dst == 'C')
		tmp = 'A';
	if (src == 'C' && dst == 'B')
		tmp = 'A';
	if (src == 'C' && dst == 'A')
		tmp = 'B';
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
	if (t == 0)
		t = 0;
	else if (t == 1)
		t = 1000;
	else if (t == 2)
		t = 500;
	else if (t == 3)
		t = 100;
	else if (t == 4)
		t = 10;
	else
		t = 1;
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> str;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
			cin >> str;
		}
		if (str == 0 || str == 1)
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
	if (str == 1)
		cout << "从 " << src << " 移动到 " << dst << ", 共 " << n << " 层, 延时设置为 " << t << ", 显示内部数组值" << endl;
	else
		cout << "从 " << src << " 移动到 " << dst << ", 共 " << n << " 层, 延时设置为 " << t << ", 不显示内部数组值" << endl;
	if (str == 1)
	{
		cct_gotoxy(0, 17);
		if (src == 'A')
		{
			top1 = n;
			top2 = 0;
			top3 = 0;
			for (int i = n; i >= 1; i--)
				a[i - 1] = n - i + 1;
			cout << "初始:                A:";
			for (int i = n; i >= 1; i--)
				cout << setw(2) << i;
			cout << setfill(' ') << setw(2 * (10 - n) + 1) << ' ';
			cout << "B:                     C:" << endl;
		}
		else if (src == 'B')
		{
			top1 = 0;
			top2 = n;
			top3 = 0;
			for (int i = n; i >= 1; i--)
				b[i - 1] = n - i + 1;
			cout << "初始:                A:                     B:";
			for (int i = n; i >= 1; i--)
				cout << setw(2) << i;
			cout << setfill(' ') << setw(2 * (10 - n) + 1) << ' ' << "C:" << endl;
		}
		else
		{
			top1 = 0;
			top2 = 0;
			top3 = n;
			for (int i = n; i >= 1; i--)
				c[i - 1] = n - i + 1;
			cout << "初始:                A:                     B:                     C:";
			for (int i = n; i >= 1; i--)
				cout << setw(2) << i;
			cout << endl;
		}
		if (t == 0)
			getchar();
		else
			Sleep(t);
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
		if (src == 'A')
			ch = 10;
		else if (src == 'B')
			ch = 20;
		else
			ch = 30;
		cct_gotoxy(ch, 12 - n);
		int y = 12 - n;
		for (int j = 1; j <= n; j++)
		{
			cout << setw(2) << j;
			y++;
			if (y != 12)
				cct_gotoxy(ch, y);
		}
		if (t == 0)
			getchar();
		else
			Sleep(t);
		hanoi(n, src, tmp, dst);
	}
	else
	{
		if (src == 'A')
		{
			top1 = n;
			top2 = 0;
			top3 = 0;
			for (int i = n; i >= 1; i--)
				a[i - 1] = n - i + 1;
		}
		else if (src == 'B')
		{
			top1 = 0;
			top2 = n;
			top3 = 0;
			for (int i = n; i >= 1; i--)
				b[i - 1] = n - i + 1;
		}
		else
		{
			top1 = 0;
			top2 = 0;
			top3 = n;
			for (int i = n; i >= 1; i--)
				c[i - 1] = n - i + 1;
		}
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
		if (src == 'A')
			ch = 10;
		else if (src == 'B')
			ch = 20;
		else
			ch = 30;
		cct_gotoxy(ch, 12 - n);
		int y = 12 - n;
		for (int j = 1; j <= n; j++)
		{
			cout << setw(2) << j;
			y++;
			if (y != 12)
				cct_gotoxy(ch, y);
		}
		if (t == 0)
			getchar();
		else
			Sleep(t);
		hanoi(n, src, tmp, dst);
	}
	cct_gotoxy(0, 25);
	return 0;
}