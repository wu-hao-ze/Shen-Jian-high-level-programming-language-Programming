/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
			   3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int x = 1;
	if (n == 1)
	{
		cout << setw(5) << x << ":" << setw(3) << n << "#" << " " << src << "-->" << dst << endl;
		x++;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cout << setw(5) << x << ":" << setw(3) << n << "#" << " " << src << "-->" << dst << endl;
		x++;
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "请输入汉诺塔的层数(1-16)" << endl;
			cin >> n;
		}
		if (n >= 1 && n <= 16)
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

	cout << "移动步骤为:" << endl;
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
	hanoi(n, src, tmp, dst);
	return 0;
}
