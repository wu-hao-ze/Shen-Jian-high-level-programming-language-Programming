/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 定义符号常量
				 定义const型变量
		不允许 ：定义全局变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：正向或反向打印三角塔
	 输入参数：order - 0 ：正三角形塔
			   order - 1 ：倒三角形塔
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	void low1(char );
	void up1(char );
	void low2(char, char);
	void up2(char, char);
	if (order == 1)
	{
		const int k = start_ch - 'A';
		if (end_ch == start_ch)
		{
			if (start_ch == 'A')
				cout << end_ch;
			else
				cout << setfill(' ') << setw(k) << ' ' << end_ch;
			cout << endl;
		}
		else
		{
			if (k != 0)
				cout << setfill(' ') << setw(k) << ' ';
			up2(start_ch, end_ch);
			low2(start_ch, end_ch);
			cout << endl;
			print_tower((char)start_ch + 1, end_ch, 1);
		}
	}
	else
	{
		if (end_ch == start_ch)
		{
			if (order == 0)
				cout << 'A';
			else
				cout << setfill(' ') << setw(((order + 2) / 2) - 1) << ' ' << start_ch;
			cout << endl;
		}
		else
		{	
			print_tower(start_ch, (char)(end_ch - 1), order=order+2);
			if ((order - 2) != 0)
				cout << setfill(' ') << setw((order / 2) - 1) << ' ';
			low1(end_ch);
			up1(end_ch);
			cout << endl;
		}
	
	}
	
}

void low1(char x)
{
	if (x == 'A')
		cout << 'A';
	else
	{
		cout << x;
		low1(x - 1);
	}
}
void up1(char x)
{
	if (x == 'A')
		;
	else
	{
		up1(x - 1);
		cout << x;
	}
}
void low2(char x,char y)
{
	if (x == y)
		cout << y;
	else
	{
		low2(x + 1, y);
		cout << x;
	}
}
void up2(char x,char y)
{
	if (x == y)
		;
	else
	{
		cout << x;
		up2(x + 1,y);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}