/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
using namespace std;
int a[10], b[10], c[10];
int top1, top2, top3;
int x = 1;
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "): " << src << "-->" << dst << ' ' << "A:";
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
		cout << endl;
		x++;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cout << "第" << setw(4) << x << " 步(" << setw(2) << n << "): " << src << "-->" << dst << ' ' << "A:";
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
		cout << endl;
		x++;
		hanoi(n - 1, tmp, src, dst);
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
	hanoi(n, src, tmp, dst);
	return 0;
}