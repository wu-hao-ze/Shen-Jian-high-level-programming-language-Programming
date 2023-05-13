/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>



using namespace std;


const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

 /***************************************************************************
  函数名称：cls 
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：无 
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止，按左箭头键不向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，按左箭头键不向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "请选择[0-6]";
	return _getch();
}
void move_by_ijkl(const HANDLE hout, int X, int Y, int Z, int P)
{
	char a = _getch();
	int b = Y;
	int c = X;
	while (a != 'q' && a != 'Q')
	{
		if (a == '\40')
		{
			showch(hout, c, b, ' ');
			gotoxy(hout, c, b);
			a = _getch();
			continue;
		}
		if (Z == 1)
		{
			if (a != 'i' && a != 'I' && a != 'j' && a != 'J' && a != 'k' && a != 'K' && a != 'l' && a != 'L' && a != '\340')
			{
				;
				a = _getch();
				continue;
			}
			if (a == 'i' || a == 'I')
			{
				if (b == 1)
					;
				else
				{
					b = b - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();	
				continue;
			}
			if (a == 'j' || a == 'J')
			{
				if (c == 1)
					;
				else
				{
					c = c - 1;
					gotoxy(hout, c, b);
				}	
				a = _getch();
				continue;
			}
			if (P == 0 || P != 0 && a != '\340')
			{
				if (a == '\340')
				{
					char i = _getch();
					if (i == '\113')
					{
						if (b == 17)
							;
						else
						{
							b = b + 1;
							gotoxy(hout, c, b);
						}
						a = _getch();
						continue;
					}
					else 
					{
						a = _getch();
						continue;
					}
				}
				if (a == 'k' || a == 'K')
				{
					if (b == 17)
						;
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (P != 0 && a == '\340')
			{
				char i = _getch();
				a = _getch();
				continue;
			}
			if (a == 'l' || a == 'L')
			{
				if (c == 69)
					;
				else
				{
					c = c + 1;
					gotoxy(hout, c, b);
				}	
				a = _getch();
				continue;
			}
		}
		if (Z == 2)
		{
			if (a != 'i' && a != 'I' && a != 'j' && a != 'J' && a != 'k' && a != 'K' && a != 'l' && a != 'L' && a != '\340')
			{
				;
				a = _getch();
				continue;
			}
			if (a == 'i' || a == 'I')
			{
				if (b == 1)
				{
					b = 17;
					gotoxy(hout, c, b);
				}
				else
				{
					b = b - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
			if (a == 'j' || a == 'J')
			{
				if (c == 1)
				{
					c = 69;
					gotoxy(hout, c, b);
				}
				else
				{
					c = c - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
			if (P == 0 || P != 0 && a != '\340')
			{
				if (a == '\340')
				{
					char i = _getch();
					if (i == '\113')
					{
						if (b == 17)
						{
							b = 1;
							gotoxy(hout, c, b);
						}
						else
						{
							b = b + 1;
							gotoxy(hout, c, b);
						}
						a = _getch();
						continue;
					}
					else 
					{
						a = _getch();
						continue;
					}
				}
				if (a == 'k' || a == 'K')
				{
					if (b == 17)
					{
						b = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (P != 0 && a == '\340')
			{
				char i = _getch();
				a = _getch();
				continue;
			}
			if (a == 'l' || a == 'L')
			{
				if (c == 69)
				{
					c = 1;
					gotoxy(hout, c, b);
				}
				else
				{
					c = c + 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
		}
	}
	if (a == 'q' || a == 'Q')
	{
		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键返回菜单." << endl;
	}
}
void move_by_arrow(const HANDLE hout, int X, int Y, int Z)
{
	char a = _getch();
	int b = Y;
	int c = X;
	while (a != 'q' && a != 'Q')
	{
		if (a == '\40')
		{
			showch(hout, c, b, ' ');
			gotoxy(hout, c, b);
			a = _getch();
			continue;
		}
		else if (a == '\340')
		{
			char x = _getch();
			if (Z == 1)
			{
				if (x != '\110' && x != '\120' && x != '\113' && x != '\115')
				{
					;
					a = _getch();
					continue;
				}
				if (x == '\110')
				{
					if (b == 1)
						;
					else
					{
						b = b - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\113')
				{
					if (c == 1)
						;
					else
					{
						c = c - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\120')
				{
					if (b == 17)
						;
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\115')
				{
					if (c == 69)
						;
					else
					{
						c = c + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (Z == 2)
			{
				if (x != '\110' && x != '\120' && x != '\113' && x != '\115')
				{
					;
					a = _getch();
					continue;
				}
				if (x == '\110')
				{
					if (b == 1)
					{
						b = 17;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\113')
				{
					if (c == 1)
					{
						c = 69;
						gotoxy(hout, c, b);
					}
					else
					{
						c = c - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\120')
				{
					if (b == 17)
					{
						b = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\115')
				{
					if (c == 69)
					{
						c = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						c = c + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
		}
		else
		{
			;
			a = _getch();
			continue;
		}
	}
	if (a == 'q' || a == 'Q')
	{
		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键返回菜单." << endl;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);                //取标准输出设备对应的句柄
	srand((unsigned int)(time(0)));                                     /* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	int x = menu();
	while (x != 48)
	{
		if (x == 48)
			break;
		else if (x == 49)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 1, 0);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 50)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 2, 0);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 51)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, 35, 9, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 52)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, 35, 9, 2);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 53)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 1, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 54)
		{
			cls(hout);
			init_border(hout);                                                    /* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 2, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else
			x = _getch();
	}
	cout << endl;
	return 0;
}
