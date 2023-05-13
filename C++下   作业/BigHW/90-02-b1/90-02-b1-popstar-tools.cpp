/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-02-b1-popstar.h"
#include "../include/cmd_console_tools.h"
using namespace std;

void InputHangLie(int& hang, int& lie, int popstar[12][12])
{
	cout << "请输入行数(8-10)：";
	while (1)
	{
		hang = _getch();
		if (hang == '8' || hang == '9')
		{
			hang = hang - 48;
			break;
		}
		else
		{
			if (hang == '1')
			{
				hang = _getch();
				if (hang == '0')
				{
					hang = 10;
					break;
				}
			}
		}
	}
	cout << hang << endl;
	cout << "请输入列数(8-10)：";
	while (1)
	{
		lie = _getch();
		if (lie == '8' || lie == '9')
		{
			lie = lie - 48;
			break;
		}
		else
		{
			if (lie == '1')
			{
				lie = _getch();
				if (lie == '0')
				{
					lie = 10;
					break;
				}
			}
		}
	}
	cout << lie << endl;
	srand((unsigned int)(time(0)));
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			popstar[i][j] = rand() % 5 + 1;
		}
	}
}

void InputZuoBiao(int& alph1, int& alph2, int hang, int lie)
{
	cout << endl << "请以字母+数字形式[例：C2]输入矩阵坐标：(按Q/q退出)";
	while (1)
	{
		alph1 = _getch();
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		if (alph1 >= 'A' && alph1 <= 'A' + hang - 1)
		{
			cout << (char)(alph1);
			alph1 = alph1 - 64;
			break;
		}
	}
	while (1)
	{
		alph2 = _getch();
		if (lie == 10)
		{
			if (alph2 == '0')
			{
				cout << (char)(alph2);
				alph2 = alph2 - 38;
				break;
			}
		}
		if (alph2 >= '1' && alph2 <= '1' + lie - 1)
		{
			cout << (char)(alph2);
			alph2 = alph2 - 48;
			break;
		}
	}
}

void Judge(int& alph1, int& alph2, int hang, int lie, int popstar[12][12])
{
	while (1)
	{
		int t = 0;
		if (popstar[alph1 - 1][alph2] == popstar[alph1][alph2] || popstar[alph1][alph2 - 1] == popstar[alph1][alph2] || popstar[alph1][alph2 + 1] == popstar[alph1][alph2] || popstar[alph1 + 1][alph2] == popstar[alph1][alph2])
			t = 1;
		if (t == 0)
		{
			cout << endl << "输入的坐标位置处无连续相同值，请重新输入" << endl;
			InputZuoBiao(alph1, alph2, hang, lie);
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				return;
			}
		}
		else
			break;
	}
}

void OutputDangQianSZ(int hang, int lie, int popstar[12][12], int dakai[12][12])
{
	cout << endl << "当前数组:" << endl;
	cout << "  |  ";
	for (int i = 1; i <= lie; i++)
		cout << i << "  ";
	cout << endl << "--+--";
	for (int i = 1; i <= lie; i++)
		cout << "---";
	cout << endl;
	for (int i = 1; i <= hang; i++)
	{
		cout << (char)(i + 64) << " |  ";
		for (int j = 1; j <= lie; j++)
		{
			if (dakai[i][j] == 1)
			{
				cct_setcolor(14, 0);
				cout << popstar[i][j];
				cct_setcolor(0, 7);
				cout << "  ";
			}
			else if (popstar[i][j] == 0)
			{
				cct_setcolor(14, 0);
				cout << popstar[i][j];
				cct_setcolor(0, 7);
				cout << "  ";
			}
			else
				cout << popstar[i][j] << "  ";
		}
		cout << endl;
	}
}

void OutputGuiBingSZ(int hang, int lie, int popstar[12][12], int dakai[12][12])
{
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			if (dakai[i][j] == 1)
				popstar[i][j] = 0;
		}
	}
	cout << endl << "相同值归并" << endl;
	OutputDangQianSZ(hang, lie, popstar, dakai);
}

void OutputXiaLuoSZ(int hang, int lie, int popstar[12][12], int dakai[12][12])
{
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			if (popstar[i][j] == 0)
			{
				int i1 = i;
				int j1 = j;
				int t;
				for (; popstar[i1][j1] == 0 && i1 <= hang; i1++)
				{
					int i2 = i1;
					int j2 = j1;
					for (; i2 != 1; i2--)
					{
						t = popstar[i2][j2];
						popstar[i2][j2] = popstar[i2 - 1][j2];
						popstar[i2 - 1][j2] = t;
						t = dakai[i2][j2];
						dakai[i2][j2] = dakai[i2 - 1][j2];
						dakai[i2 - 1][j2] = t;
					}
				}
				for (i1 = 1; i1 <= hang; i1++)
				{
					if (popstar[i1][j1] != 0)
						break;
				}
				if (i1 == hang + 1)
				{
					for (; j1 < lie; j1++)
					{
						for (i1 = 1; i1 <= hang; i1++)
						{
							t = popstar[i1][j1];
							popstar[i1][j1] = popstar[i1][j1 + 1];
							popstar[i1][j1 + 1] = t;
							t = dakai[i1][j1];
							dakai[i1][j1] = dakai[i1][j1 + 1];
							dakai[i1][j1 + 1] = t;
						}
					}
				}
			}
		}
	}
	cout << endl << "下落" << "      " << "按回车键继续...";
	while (_getch() != '\r')
		;
	cout << endl;
	OutputDangQianSZ(hang, lie, popstar, dakai);
}

void XiaLuo(int hang, int lie, int popstar[12][12], int dakai[12][12])
{
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			int i1 = i;
			int j1 = j;
			int t;
			if (popstar[i1][j1] == 0 && popstar[i1 - 1][j1] != 0)
			{
				for (; popstar[i1][j1] == 0 && i1 <= hang; i1++)
				{
					Sleep(50);
					int i2 = i1;
					int j2 = j1;
					for (; popstar[i2 - 1][j2] != 0; i2--)
					{
						t = popstar[i2][j2];
						popstar[i2][j2] = popstar[i2 - 1][j2];
						popstar[i2 - 1][j2] = t;
						t = dakai[i2][j2];
						dakai[i2][j2] = dakai[i2 - 1][j2];
						dakai[i2 - 1][j2] = t;
						for (int t = 0; t < 3; t++)
						{
							cct_gotoxy(6 * j2 - 2, 3 * i2 - 3 + t);
							cct_setcolor(15, 15);
							cout << "      ";
							cct_setcolor(popstar[i2][j2] + 8, 0);
							cct_gotoxy(6 * j2 - 2, 3 * i2 - 2 + t);
							cout << "╔═╗";
							cct_gotoxy(6 * j2 - 2, 3 * i2 - 1 + t);
							cout << "║★║";
							cct_gotoxy(6 * j2 - 2, 3 * i2 + t);
							cout << "╚═╝";
							cct_setcolor(0, 7);
						}
					}
				}
			}
			for (i1 = 1; i1 <= hang; i1++)
			{
				if (popstar[i1][j1] != 0)
					break;
			}
			if (i1 == hang + 1 && popstar[i1 - 1][j1 + 1] != 0)
			{
				for (; j1 < lie; j1++)
				{
					for (i1 = hang; i1 >= 1; i1--)
					{
						t = popstar[i1][j1];
						popstar[i1][j1] = popstar[i1][j1 + 1];
						popstar[i1][j1 + 1] = t;
						t = dakai[i1][j1];
						dakai[i1][j1] = dakai[i1][j1 + 1];
						dakai[i1][j1 + 1] = t;
						for (int t = 1; t <= 3; t++)
						{
							if (popstar[i1][j1] != 0)
							{
								Sleep(10);
								cct_setcolor(popstar[i1][j1] + 8, 0);
								cct_gotoxy(6 * j1 + 4 - 2 * t, 3 * i1);
								cout << "╔═╗";
								cct_setcolor(15, 15);
								cout << "  ";
								cct_setcolor(popstar[i1][j1] + 8, 0);
								cct_gotoxy(6 * j1 + 4 - 2 * t, 3 * i1 + 1);
								cout << "║★║";
								cct_setcolor(15, 15);
								cout << "  ";
								cct_setcolor(popstar[i1][j1] + 8, 0);
								cct_gotoxy(6 * j1 + 4 - 2 * t, 3 * i1 + 2);
								cout << "╚═╝";
								cct_setcolor(15, 15);
								cout << "  ";
								cct_setcolor(0, 7);
							}
						}
					}
				}
			}
		}
	}

}

void kuosan(int alph1, int alph2, int popstar[12][12], int dakai[12][12], char fenshu[12][12])
{
	for (int i = alph1 - 1; i <= alph1 + 1; i++)
	{
		for (int j = alph2 - 1; j <= alph2 + 1; j++)
		{
			if (i + j - alph1 - alph2 == 1 || i + j - alph1 - alph2 == -1)
			{
				if (dakai[i][j] == 1)
					continue;
				if (dakai[i][j] == 0)
				{
					if (popstar[i][j] == popstar[alph1][alph2])
					{
						dakai[i][j] = 1;
						fenshu[i][j] = '*';
					}
				}
				if (popstar[i][j] == popstar[alph1][alph2] && popstar[i][j] != 0)
					kuosan(i, j, popstar, dakai, fenshu);
			}
		}
	}
}

int PanDuanEnd(int hang, int lie, int popstar[12][12])
{
	int t = 0;
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			if (popstar[i][j] != 0)
			{
				if (popstar[i - 1][j] == popstar[i][j] || popstar[i][j - 1] == popstar[i][j] || popstar[i][j + 1] == popstar[i][j] || popstar[i + 1][j] == popstar[i][j])
					t = 1;
			}
		}
	}
	return t;
}

void OutScore(char fenshu[12][12], int& score, int num)
{
	int t = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (fenshu[i][j] == '*')
				t++;
		}
	}
	if (num == 5 || num == 6)
		cct_gotoxy(0, 0);
	else
		cout << endl;
	cout << "本次得分：" << t * t * 5 << "   ";
	score += t * t * 5;
	cout << "总得分：" << score << "           " << endl;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			fenshu[i][j] = '0';
}

void end(int num, int hang, int lie)
{
	if (num == 1 || num == 2 || num == 3)
	{
		if (num == 1 || num == 2)
			cout << endl << "按回车键继续...";
		else
			cout << endl << "本关结束，按回车键继续...";
		while (_getch() != '\r')
			;
		cct_cls();
	}
	if (num == 4 || num == 5)
	{
		cct_gotoxy(0, 5 + 3 * hang);
		cout << "按回车键继续...";
		while (_getch() != '\r')
			;
	}
	if (num == 6)
	{
		cct_gotoxy(0, 5 + 3 * hang);
		cout << "本关结束，按回车键继续...";
		while (_getch() != '\r')
			;
	}
}

void kuangjia(int hang, int lie, int popstar[12][12])
{
	cct_cls();
	cct_setconsoleborder(55 + 6 * (lie - 8), 32 + 3 * (hang - 8), 55 + 6 * (lie - 8), 32 + 3 * (hang - 8));
	cout << "屏幕当前设置为：" << 32 + 3 * (hang - 8) << "行" << 55 + 6 * (lie - 8) << "列" << endl;
	cout << "      ";
	for (int i = 1; i <= lie; i++)
	{
		if (i == 10)
			cout << i << "    ";
		else
			cout << i << "     ";
	}
	cout << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╔";
	for (int i = 1; i <= 3 * lie; i++)
		cout << "═";
	cout << "╗" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║";
	for (int i = 1; i <= 6 * lie; i++)
		cout << ' ';
	cout << "║" << endl;
	for (int i = 1; i < hang; i++)
	{
		cct_setcolor(0, 7);
		cout << (char)(i + 64) << ' ';
		cct_setcolor(15, 0);
		cout << "║";
		for (int i = 1; i <= 6 * lie; i++)
			cout << ' ';
		cout << "║" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║";
		for (int i = 1; i <= 6 * lie; i++)
			cout << ' ';
		cout << "║" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "║";
		for (int i = 1; i <= 6 * lie; i++)
			cout << ' ';
		cout << "║" << endl;
	}
	cct_setcolor(0, 7);
	cout << (char)(hang + 64) << ' ';
	cct_setcolor(15, 0);
	cout << "║";
	for (int i = 1; i <= 6 * lie; i++)
		cout << ' ';
	cout << "║" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "║";
	for (int i = 1; i <= 6 * lie; i++)
		cout << ' ';
	cout << "║" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "╚";
	for (int i = 1; i <= 3 * lie; i++)
		cout << "═";
	cout << "╝" << endl;
	for (int i = 1; i <= hang; i++)
	{
		for (int j = 1; j <= lie; j++)
		{
			cct_gotoxy(6 * j - 2, 3 * i);
			cct_setcolor(popstar[i][j] + 8, 0);
			cout << "╔═╗";
			cct_gotoxy(6 * j - 2, 3 * i + 1);
			cout << "║★║";
			cct_gotoxy(6 * j - 2, 3 * i + 2);
			cout << "╚═╝";
		}
	}
	cct_setcolor(0, 7);
}

void shubiao(int& flag, int& alph1, int& alph2, int hang, int lie, int popstar[12][12])
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	flag = 0;
	int ti = 1, tj = 1;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 3 * hang + 4);
			cout << "[当前鼠标]";
			int t = 0;
			switch (maction) {
			case MOUSE_ONLY_MOVED:
				if (popstar[ti][tj] != 0)
				{
					cct_gotoxy(6 * tj - 2, 3 * ti);
					cct_setcolor(popstar[ti][tj] + 8, 0);
					cout << "╔═╗";
					cct_gotoxy(6 * tj - 2, 3 * ti + 1);
					cout << "║★║";
					cct_gotoxy(6 * tj - 2, 3 * ti + 2);
					cout << "╚═╝";
					cct_setcolor(0, 7);
				}
				for (int i = 1; i <= hang; i++)
				{
					for (int j = 1; j <= lie; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 3 && Y >= 3 * i && Y <= 3 * i + 2)
						{
							t = 1;
							char zimu = 'A';
							cct_gotoxy(11, 3 * hang + 4);
							cout << (char)(zimu + i - 1) << "行" << j << "列  ";
							cct_gotoxy(6 * j - 2, 3 * i);
							if (popstar[i][j] != 0)
							{
								cct_setcolor(popstar[i][j] + 8, 7);
								cout << "╔═╗";
								cct_gotoxy(6 * j - 2, 3 * i + 1);
								cout << "║★║";
								cct_gotoxy(6 * j - 2, 3 * i + 2);
								cout << "╚═╝";
								cct_setcolor(0, 7);
								ti = i;
								tj = j;
							}
							break;
						}
					}
				}
				if (t == 0)
				{
					cct_gotoxy(11, 3 * hang + 4);
					cout << "位置非法";
				}
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i <= hang; i++)
				{
					for (int j = 1; j <= lie; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 3 && Y >= 3 * i && Y <= 3 * i + 2)
						{
							alph1 = i;
							alph2 = j;
							t = 1;
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
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			switch (keycode1)
			{
			case 27:
				loop = 0;
				flag = 1;
				break;
			default:
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}


