/*1953729 信09 吴浩泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-01-b2-mine_sweeper.h"
#include "../include/cmd_console_tools.h"
using namespace std;

void weituxing(int nanduxuanze, int num)
{
	if (nanduxuanze == 1)
		difficulty1(nanduxuanze, num);
	else if (nanduxuanze == 2)
		difficulty2(nanduxuanze, num);
	else
		difficulty3(nanduxuanze, num);
}

void shengyuleishu(int leishu, int num)
{
	if (num == 9)
	{
		cct_gotoxy(32, 0);
		if (leishu > 0)
			cout << setw(2) << leishu << " ";
		else
			cout << setw(2) << 0 << " ";
	}
}

void color(char x)
{
	switch (x)
	{
	case '0':
		cct_setcolor(7, 7);
		break;
	case '1':
		cct_setcolor(7, 1);
		break;
	case '2':
		cct_setcolor(7, 2);
		break;
	case '3':
		cct_setcolor(7, 3);
		break;
	case '4':
		cct_setcolor(7, 4);
		break;
	case '5':
		cct_setcolor(7, 5);
		break;
	case '6':
		cct_setcolor(7, 6);
		break;
	case '7':
		cct_setcolor(7, 7);
		break;
	case '8':
		cct_setcolor(7, 8);
		break;
	case 'X':
		cct_setcolor(6, 6);
		break;
	case '*':
		cct_setcolor(7, 0);
		break;
	}
	if (x == '0' || x == 'X')
		cout << ' ';
	else
		cout << x;
	cct_setcolor(0, 7);
}

void kuangjia1()
{
	cout << endl;
	cout << "     0     1     2     3     4     5     6     7     8" << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╔══╦══╦══╦══╦══╦══╦══╦══╦══╗" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	for (int i = 1; i <= 8; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "╠══╬══╬══╬══╬══╬══╬══╬══╬══╣" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╚══╩══╩══╩══╩══╩══╩══╩══╩══╝" << endl;
	cct_setcolor(0, 7);
	for (int i = 1; i <= 9; i++)
	{
		char zimu = 'A';
		cct_gotoxy(0, 3 * i + 1);
		cout << (char)(zimu + i - 1);
	}
}

void kuangjia2()
{
	cout << endl;
	cout << "     0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15" << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╔══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╗" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	for (int i = 1; i <= 15; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "╠══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╣" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╚══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╝" << endl;
	cct_setcolor(0, 7);
	for (int i = 1; i <= 16; i++)
	{
		char zimu = 'A';
		cct_gotoxy(0, 3 * i + 1);
		cout << (char)(zimu + i - 1);
	}
}

void kuangjia3()
{
	cout << endl;
	cout << "     0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29" << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╔══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╦══╗" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	for (int i = 1; i <= 15; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "╠══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╬══╣" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║    ║" << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╚══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╩══╝" << endl;
	cct_setcolor(0, 7);
	for (int i = 1; i <= 16; i++)
	{
		char zimu = 'A';
		cct_gotoxy(0, 3 * i + 1);
		cout << (char)(zimu + i - 1);
	}
}

void shubiao(int num, int& flag, int& leishu, int& alph1, int& alph2, char dakai[][11], char biaoji[][11])
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 30);
			cout << "[当前光标]";
			int t = 0;
			switch (maction) {
			case MOUSE_ONLY_MOVED:
				cct_gotoxy(11, 30);
				for (int i = 1; i <= 9; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							t = 1;
							char zimu = 'A';
							cct_gotoxy(11, 30);
							cout << (char)(zimu + i - 1) << "行" << j - 1 << "列  ";
							break;
						}
					}
				}
				if (t == 0)
				{
					cct_gotoxy(11, 30);
					cout << "位置非法";
				}
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (num == 8 || num == 9)
				{
					for (int i = 1; i <= 9; i++)
					{
						for (int j = 1; j <= 9; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								alph1 = i;
								alph2 = j;
								t = 1;
								if (dakai[alph1][alph2] == 0 && biaoji[alph1][alph2] != 1)
								{
									biaoji[alph1][alph2] = 1;
									leishu--;
								}
								else if (biaoji[alph1][alph2] == 1)
								{
									biaoji[alph1][alph2] = 2;
									leishu++;
								}
							}
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i <= 9; i++)
				{
					for (int j = 1; j <= 9; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							alph1 = i;
							alph2 = j;
							if (biaoji[alph1][alph2] != 1)
								t = 1;
							if (biaoji[alph1][alph2] == 2)
								biaoji[alph1][alph2] = 0;
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((num == 8 || num == 9) && ret == CCT_KEYBOARD_EVENT)
		{
			switch (keycode1)
			{
			case 27:
				loop = 0;
				flag = 1;
				break;
			case 32:
				if (num == 9)
				{
					flag = 2;
					loop = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void shubiao(int num, int& flag, int& leishu, int& alph1, int& alph2, char dakai[][18], char biaoji[][18])
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 51);
			cout << "[当前光标]";
			int t = 0;
			switch (maction) {
			case MOUSE_ONLY_MOVED:
				cct_gotoxy(11, 51);
				for (int i = 1; i <= 16; i++)
				{
					for (int j = 1; j <= 16; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							t = 1;
							char zimu = 'A';
							cct_gotoxy(11, 51);
							cout << (char)(zimu + i - 1) << "行" << j - 1 << "列  ";
							break;
						}
					}
				}
				if (t == 0)
				{
					cct_gotoxy(11, 51);
					cout << "位置非法";
				}
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (num == 8 || num == 9)
				{
					for (int i = 1; i <= 16; i++)
					{
						for (int j = 1; j <= 16; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								alph1 = i;
								alph2 = j;
								t = 1;
								if (dakai[alph1][alph2] == 0 && biaoji[alph1][alph2] != 1)
								{
									biaoji[alph1][alph2] = 1;
									leishu--;
								}
								else if (biaoji[alph1][alph2] == 1)
								{
									biaoji[alph1][alph2] = 2;
									leishu++;
								}
							}
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i <= 16; i++)
				{
					for (int j = 1; j <= 16; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							alph1 = i;
							alph2 = j;
							if (biaoji[alph1][alph2] != 1)
								t = 1;
							if (biaoji[alph1][alph2] == 2)
								biaoji[alph1][alph2] = 0;
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((num == 8 || num == 9) && ret == CCT_KEYBOARD_EVENT)
		{
			switch (keycode1)
			{
			case 27:
				loop = 0;
				flag = 1;
				break;
			case 32:
				if (num == 9)
				{
					flag = 2;
					loop = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void shubiao(int num, int& flag, int& leishu, int& alph1, int& alph2, char dakai[][32], char biaoji[][32])
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 51);
			cout << "[当前光标]";
			int t = 0;
			switch (maction) {
			case MOUSE_ONLY_MOVED:
				cct_gotoxy(11, 51);
				for (int i = 1; i <= 16; i++)
				{
					for (int j = 1; j <= 30; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							t = 1;
							char zimu = 'A';
							cct_gotoxy(11, 51);
							cout << (char)(zimu + i - 1) << "行" << j - 1 << "列  ";
							break;
						}
					}
				}
				if (t == 0)
				{
					cct_gotoxy(11, 51);
					cout << "位置非法";
				}
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (num == 8 || num == 9)
				{
					for (int i = 1; i <= 16; i++)
					{
						for (int j = 1; j <= 30; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								alph1 = i;
								alph2 = j;
								t = 1;
								if (dakai[alph1][alph2] == 0 && biaoji[alph1][alph2] != 1)
								{
									biaoji[alph1][alph2] = 1;
									leishu--;
								}
								else if (biaoji[alph1][alph2] == 1)
								{
									biaoji[alph1][alph2] = 2;
									leishu++;
								}
							}
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i <= 16; i++)
				{
					for (int j = 1; j <= 30; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							alph1 = i;
							alph2 = j;
							if (biaoji[alph1][alph2] != 1)
								t = 1;
							if (biaoji[alph1][alph2] == 2)
								biaoji[alph1][alph2] = 0;
						}
					}
				}
				if (t == 1)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((num == 8 || num == 9) && ret == CCT_KEYBOARD_EVENT)
		{
			switch (keycode1)
			{
			case 27:
				loop = 0;
				flag = 1;
				break;
			case 32:
				if (num == 9)
				{
					flag = 2;
					loop = 0;
				}
				break;
			default:
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void shuchu(int num, char saolei[][11], char fugai[][11], char biaoji[][11])
{
	if (num == 5 || num == 6)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				color(saolei[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (fugai[i][j] == 'X' && biaoji[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (fugai[i][j] == 'X' && biaoji[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(4, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(4, 7);
					cout << '#';
					cct_setcolor(4, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					color(fugai[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0, 7);
}

void shuchu(int num, char saolei[][18], char fugai[][18], char biaoji[][18])
{
	if (num == 5 || num == 6)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				color(saolei[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				if (fugai[i][j] == 'X' && biaoji[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (fugai[i][j] == 'X' && biaoji[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(4, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(4, 7);
					cout << '#';
					cct_setcolor(4, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					color(fugai[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0, 7);
}

void shuchu(int num, char saolei[][32], char fugai[][32], char biaoji[][32])
{
	if (num == 5 || num == 6)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				color(saolei[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (fugai[i][j] == 'X' && biaoji[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (fugai[i][j] == 'X' && biaoji[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(4, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(4, 7);
					cout << '#';
					cct_setcolor(4, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					color(fugai[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0, 7);
}

void difficulty1(int nanduxuanze, int num)
{
	cct_setfontsize("点阵字体", 16, 8);
	cct_setconsoleborder(59, 35, 59, 35);
	clock_t start, end;
	start = clock();
	end = clock();
	char saolei[11][11] = {};
	char fugai[11][11] = {};
	char dakai[11][11] = {};
	char biaoji[11][11] = {};
	int alph1, alph2, flag = 0, leishu = 10;
	kuangjia1();
	if (num == 8)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出";
	}
	if (num == 9)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出,空格显示时间 剩余雷数:" << setw(2) << leishu << " ";
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (biaoji[alph1][alph2] != 0)
		{
			for (int i = 1; i <= 9; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(4, 4);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << " ";
						cct_setcolor(4, 7);
						cout << '#';
						cct_setcolor(4, 4);
						cout << "  ";
						cct_setcolor(0, 7);
					}
					else
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(6, 6);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << "    ";
						cct_setcolor(0, 7);
					}
				}
			}
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
			while (flag == 2)
			{
				cct_gotoxy(36, 0);
				end = clock();
				cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
				cct_setcolor(0, 7);
				flag = 0;
				shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
				shengyuleishu(leishu, num);
			}
			if (flag == 1)
				return;
			cct_gotoxy(36, 0);
			cout << "                   ";
		}
	}
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (biaoji[i][j] == 2)
				biaoji[i][j] = 0;
	srand((unsigned int)(time(0)));
	for (int t = 0; t < 10;)
	{
		t = 0;
		saolei[rand() % 9 + 1][rand() % 9 + 1] = '*';
		if (num == 7 || num == 8 || num == 9)
		{
			for (int i = alph1 - 1; i <= alph1 + 1; i++)
			{
				for (int j = alph2 - 1; j <= alph2 + 1; j++)
				{
					if (saolei[i][j] == '*')
						saolei[i][j] = '\0';
				}
			}
		}
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (saolei[i][j] == '*')
					t++;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int t = 0;
			if (saolei[i][j] != '*')
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
						if (saolei[a][b] == '*')
							t++;
				saolei[i][j] = t + 48;
			}
		}
	}
	if (num == 5)
		shuchu(num, saolei, fugai, biaoji);
	if (num == 6)
	{
		shuchu(num, saolei, fugai, biaoji);
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
	}
	if (num == 7)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		shuchu(num, saolei, fugai, biaoji);
	}
	if (num == 8 || num == 9)
		game2(saolei, fugai, dakai, biaoji, alph1, alph2, leishu, num, nanduxuanze, start, end);
}

void difficulty2(int nanduxuanze, int num)
{
	cct_setfontsize("点阵字体", 16, 8);
	cct_setconsoleborder(101, 56, 101, 56);
	clock_t start, end;
	start = clock();
	end = clock();
	char saolei[18][18] = {};
	char fugai[18][18] = {};
	char dakai[18][18] = {};
	char biaoji[18][18] = {};
	int alph1, alph2, flag = 0, leishu = 40;
	kuangjia2();
	if (num == 8)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出";
	}
	if (num == 9)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出,空格显示时间 剩余雷数:" << setw(2) << leishu << " ";
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (biaoji[alph1][alph2] != 0)
		{
			for (int i = 1; i <= 16; i++)
			{
				for (int j = 1; j <= 16; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(4, 4);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << " ";
						cct_setcolor(4, 7);
						cout << '#';
						cct_setcolor(4, 4);
						cout << "  ";
						cct_setcolor(0, 7);
					}
					else
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(6, 6);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << "    ";
						cct_setcolor(0, 7);
					}
				}
			}
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
			while (flag == 2)
			{
				cct_gotoxy(36, 0);
				end = clock();
				cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
				cct_setcolor(0, 7);
				flag = 0;
				shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
				shengyuleishu(leishu, num);
			}
			if (flag == 1)
				return;
			cct_gotoxy(36, 0);
			cout << "                   ";
		}
	}
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= 16; j++)
			if (biaoji[i][j] == 2)
				biaoji[i][j] = 0;
	srand((unsigned int)(time(0)));
	for (int t = 0; t < 40;)
	{
		t = 0;
		saolei[rand() % 16 + 1][rand() % 16 + 1] = '*';
		if (num == 7 || num == 8 || num == 9)
		{
			for (int i = alph1 - 1; i <= alph1 + 1; i++)
			{
				for (int j = alph2 - 1; j <= alph2 + 1; j++)
				{
					if (saolei[i][j] == '*')
						saolei[i][j] = '\0';
				}
			}
		}
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				if (saolei[i][j] == '*')
					t++;
			}
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 16; j++)
		{
			int t = 0;
			if (saolei[i][j] != '*')
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
						if (saolei[a][b] == '*')
							t++;
				saolei[i][j] = t + 48;
			}
		}
	}
	if (num == 5)
		shuchu(num, saolei, fugai, biaoji);
	if (num == 6)
	{
		shuchu(num, saolei, fugai, biaoji);
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
	}
	if (num == 7)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		shuchu(num, saolei, fugai, biaoji);
	}
	if (num == 8 || num == 9)
		game2(saolei, fugai, dakai, biaoji, alph1, alph2, leishu, num, nanduxuanze, start, end);
}

void difficulty3(int nanduxuanze, int num)
{
	cct_setfontsize("点阵字体", 16, 8);
	cct_setconsoleborder(185, 56, 185, 56);
	clock_t start, end;
	start = clock();
	end = clock();
	char saolei[18][32] = {};
	char fugai[18][32] = {};
	char dakai[18][32] = {};
	char biaoji[18][32] = {};
	int alph1, alph2, flag = 0, leishu = 99;
	kuangjia3();
	if (num == 8)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出";
	}
	if (num == 9)
	{
		cct_gotoxy(0, 0);
		cout << "按Esc退出,空格显示时间 剩余雷数:" << setw(2) << leishu << " ";
	}
	if (num == 7 || num == 8 || num == 9)
	{
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (biaoji[alph1][alph2] != 0)
		{
			for (int i = 1; i <= 16; i++)
			{
				for (int j = 1; j <= 30; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(4, 4);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << " ";
						cct_setcolor(4, 7);
						cout << '#';
						cct_setcolor(4, 4);
						cout << "  ";
						cct_setcolor(0, 7);
					}
					else
					{
						cct_gotoxy(6 * j - 2, 3 * i);
						cct_setcolor(6, 6);
						cout << "    ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << "    ";
						cct_setcolor(0, 7);
					}
				}
			}
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
			while (flag == 2)
			{
				cct_gotoxy(36, 0);
				end = clock();
				cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
				cct_setcolor(0, 7);
				flag = 0;
				shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
				shengyuleishu(leishu, num);
			}
			if (flag == 1)
				return;
			cct_gotoxy(36, 0);
			cout << "                   ";
		}
	}
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= 30; j++)
			if (biaoji[i][j] == 2)
				biaoji[i][j] = 0;
	srand((unsigned int)(time(0)));
	for (int t = 0; t < 99;)
	{
		t = 0;
		saolei[rand() % 16 + 1][rand() % 30 + 1] = '*';
		if (num == 7 || num == 8 || num == 9)
		{
			for (int i = alph1 - 1; i <= alph1 + 1; i++)
			{
				for (int j = alph2 - 1; j <= alph2 + 1; j++)
				{
					if (saolei[i][j] == '*')
						saolei[i][j] = '\0';
				}
			}
		}
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (saolei[i][j] == '*')
					t++;
			}
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 30; j++)
		{
			int t = 0;
			if (saolei[i][j] != '*')
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
						if (saolei[a][b] == '*')
							t++;
				saolei[i][j] = t + 48;
			}
		}
	}
	if (num == 5)
		shuchu(num, saolei, fugai, biaoji);
	if (num == 6)
	{
		shuchu(num, saolei, fugai, biaoji);
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
	}
	if (num == 7)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		shuchu(num, saolei, fugai, biaoji);
	}
	if (num == 8 || num == 9)
		game2(saolei, fugai, dakai, biaoji, alph1, alph2, leishu, num, nanduxuanze, start, end);
}

void game2(char saolei[][11], char fugai[][11], char dakai[][11], char biaoji[][11], int alph1, int alph2, int leishu, int num, int nanduxuanze, clock_t start, clock_t end)
{
	int flag = 0;
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	shuchu(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		if (saolei[alph1][alph2] == '0' && biaoji[alph1][alph2] == 0)
		{
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 9; j++)
					if (biaoji[i][j] == 2)
						biaoji[i][j] = 0;
			kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		}
		else
		{
			if (biaoji[alph1][alph2] == 1)
			{
				fugai[alph1][alph2] = 'X';
				dakai[alph1][alph2] = 1;
			}
			else if (biaoji[alph1][alph2] == 2)
				fugai[alph1][alph2] = fugai[alph1][alph2];
			else
			{
				fugai[alph1][alph2] = saolei[alph1][alph2];
				dakai[alph1][alph2] = 1;
			}
		}
		shuchu(num, saolei, fugai, biaoji);
		int t = 0;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (fugai[i][j] == 'X')
				{
					if (saolei[i][j] != '*')
						t = 1;
				}
			}
		}
		if (t == 0)
		{
			cct_gotoxy(0, 30);
			cout << "恭喜胜利，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
			if (num == 9)
			{
				cct_gotoxy(32, 0);
				cout << setw(2) << 0 << " ";
			}
			break;
		}
		if (fugai[alph1][alph2] == '*')
		{
			cct_gotoxy(0, 30);
			cout << "你输了，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
		}
	}
}

void game2(char saolei[][18], char fugai[][18], char dakai[][18], char biaoji[][18], int alph1, int alph2, int leishu, int num, int nanduxuanze, clock_t start, clock_t end)
{
	int flag = 0;
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	shuchu(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		if (saolei[alph1][alph2] == '0' && biaoji[alph1][alph2] == 0)
		{
			for (int i = 1; i <= 16; i++)
				for (int j = 1; j <= 16; j++)
					if (biaoji[i][j] == 2)
						biaoji[i][j] = 0;
			kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		}
		else
		{
			if (biaoji[alph1][alph2] == 1)
			{
				fugai[alph1][alph2] = 'X';
				dakai[alph1][alph2] = 1;
			}
			else if (biaoji[alph1][alph2] == 2)
				fugai[alph1][alph2] = fugai[alph1][alph2];
			else
			{
				fugai[alph1][alph2] = saolei[alph1][alph2];
				dakai[alph1][alph2] = 1;
			}
		}
		shuchu(num, saolei, fugai, biaoji);
		int t = 0;
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 16; j++)
			{
				if (fugai[i][j] == 'X')
				{
					if (saolei[i][j] != '*')
						t = 1;
				}
			}
		}
		if (t == 0)
		{
			cct_gotoxy(0, 51);
			cout << "恭喜胜利，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
			if (num == 9)
			{
				cct_gotoxy(32, 0);
				cout << setw(2) << 0 << " ";
			}
			break;
		}
		if (fugai[alph1][alph2] == '*')
		{
			cct_gotoxy(0, 51);
			cout << "你输了，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
		}
	}
}

void game2(char saolei[][32], char fugai[][32], char dakai[][32], char biaoji[][32], int alph1, int alph2, int leishu, int num, int nanduxuanze, clock_t start, clock_t end)
{
	int flag = 0;
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	shuchu(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
		shengyuleishu(leishu, num);
		while (flag == 2)
		{
			cct_gotoxy(36, 0);
			end = clock();
			cout << "当前时间:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			cct_setcolor(0, 7);
			flag = 0;
			shubiao(num, flag, leishu, alph1, alph2, dakai, biaoji);
			shengyuleishu(leishu, num);
		}
		if (flag == 1)
			return;
		cct_gotoxy(36, 0);
		cout << "                   ";
		if (saolei[alph1][alph2] == '0' && biaoji[alph1][alph2] == 0)
		{
			for (int i = 1; i <= 16; i++)
				for (int j = 1; j <= 30; j++)
					if (biaoji[i][j] == 2)
						biaoji[i][j] = 0;
			kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		}
		else
		{
			if (biaoji[alph1][alph2] == 1)
			{
				fugai[alph1][alph2] = 'X';
				dakai[alph1][alph2] = 1;
			}
			else if (biaoji[alph1][alph2] == 2)
				fugai[alph1][alph2] = fugai[alph1][alph2];
			else
			{
				fugai[alph1][alph2] = saolei[alph1][alph2];
				dakai[alph1][alph2] = 1;
			}
		}
		shuchu(num, saolei, fugai, biaoji);
		int t = 0;
		for (int i = 1; i <= 16; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (fugai[i][j] == 'X')
				{
					if (saolei[i][j] != '*')
						t = 1;
				}
			}
		}
		if (t == 0)
		{
			cct_gotoxy(0, 51);
			cout << "恭喜胜利，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
			if (num == 9)
			{
				cct_gotoxy(32, 0);
				cout << setw(2) << 0 << " ";
			}
			break;
		}
		if (fugai[alph1][alph2] == '*')
		{
			cct_gotoxy(0, 51);
			cout << "你输了，游戏结束     " << endl;
			if (num == 9)
			{
				end = clock();
				cout << "共用时:" << (double)(end - start) / CLOCKS_PER_SEC << "秒";
			}
		}
	}
}

