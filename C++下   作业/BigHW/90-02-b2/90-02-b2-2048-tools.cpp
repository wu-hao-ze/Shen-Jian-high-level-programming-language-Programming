/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-02-b2-2048.h"
#include "../include/cmd_console_tools.h"
using namespace std;

void KuangJia(int hang, int lie, int score, square _2048[8][8])
{
	cct_cls();
	cct_setcolor(0, 7);
	cct_setconsoleborder(14 * lie + 3, 6 * hang + 3, 14 * lie + 3, 6 * hang + 3);
	cct_setcolor(15, 0);
	for (int i = 0; i < 14 * lie + 2; i++)
		cout << ' ';
	cct_gotoxy(7 * lie - 15, 0);
	cout << "目标：" << score << "  (r：重玩 q：退出)";
	cct_gotoxy(0, 1);
	cout << "╔══════";
	for (int i = 0; i < lie - 1; i++)
		cout << "╤══════";
	cout << "╗" << endl;
	for (int i = 0; i < hang - 1; i++)
	{
		for (int i1 = 0; i1 < 5; i1++)
		{
			cout << "║            ";
			for (int i2 = 0; i2 < lie - 1; i2++)
				cout << "│            ";
			cout << "║" << endl;
		}
		cout << "╟──────";
		for (int i1 = 0; i1 < lie - 1; i1++)
			cout << "┼──────";
		cout << "╢" << endl;
	}
	for (int i1 = 0; i1 < 5; i1++)
	{
		cout << "║            ";
		for (int i2 = 0; i2 < lie - 1; i2++)
			cout << "│            ";
		cout << "║" << endl;
	}
	cout << "╚══════";
	for (int i1 = 0; i1 < lie - 1; i1++)
		cout << "╧══════";
	cout << "╝";
	int alph1 = rand() % hang, alph2 = rand() % lie;
	_2048[alph1][alph2].num = 2;
	color(_2048[alph1][alph2].num);
	cct_gotoxy(14 * alph2 + 2, 6 * alph1 + 2);
	cout << "╔════╗";
	for (int i = 3; i <= 5; i++)
	{
		cct_gotoxy(14 * alph2 + 2, 6 * alph1 + i);
		cout << "║        ║";
	}
	cct_gotoxy(14 * alph2 + 2, 6 * alph1 + 6);
	cout << "╚════╝";
	cct_gotoxy(14 * alph2 + 7, 6 * alph1 + 4);
	cout << _2048[alph1][alph2].num;
	cct_setcolor(0, 7);
}

void color(int num)
{
	int i = 0;
	while (num != 1)
	{
		num /= 2;
		i++;
	}
	cct_setcolor(16 - i, 0);
}

void _2048_up(int hang, int lie, int yanshi, square _2048[8][8])
{
	for (int j = 0; j < lie; j++)
	{
		for (int i = 0; i < hang; i++)
		{
			if (_2048[i][j].num != 0)
			{
				int i1 = i - 1;
				for (; i1 >= 0 && _2048[i1][j].num == 0; i1--)
				{
					int t = _2048[i1][j].num;
					_2048[i1][j].num = _2048[i1 + 1][j].num;
					_2048[i1 + 1][j].num = t;
					for (int t = 0; t < 6; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 300000; i++)
								;
						else
							Sleep(yanshi);
						cct_gotoxy(14 * j + 2, 6 * i1 + 12 - t);
						cct_setcolor(15, 0);
						if (t == 5)
							cout << "──────";
						else
							cout << "            ";
						color(_2048[i1][j].num);
						cct_gotoxy(14 * j + 2, 6 * i1 + 11 - t);
						cout << "╚════╝";
						for (int i = 0; i < 3; i++)
						{
							cct_gotoxy(14 * j + 2, 6 * i1 + 10 - i - t);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j + 2, 6 * i1 + 7 - t);
						cout << "╔════╗";
						cct_gotoxy(14 * j + 7, 6 * i1 + 9 - t);
						cout << _2048[i1][j].num;
						cct_setcolor(0, 7);
					}	cct_setcolor(0, 7);
				}
				if (i1 >= 0 && _2048[i1][j].num == _2048[i1 + 1][j].num && _2048[i1][j].flag == 0)
				{
					for (int t = 0; t < 6; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 300000; i++)
								;
						else
							Sleep(yanshi);
						cct_gotoxy(14 * j + 2, 6 * i1 + 12 - t);
						cct_setcolor(15, 0);
						if (t == 5)
							cout << "──────";
						else
							cout << "            ";
						color(_2048[i1][j].num);
						cct_gotoxy(14 * j + 2, 6 * i1 + 11 - t);
						cout << "╚════╝";
						for (int i = 0; i < 3; i++)
						{
							cct_gotoxy(14 * j + 2, 6 * i1 + 10 - i - t);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j + 2, 6 * i1 + 7 - t);
						cout << "╔════╗";
						cct_gotoxy(14 * j + 7, 6 * i1 + 9 - t);
						cout << _2048[i1][j].num;
						cct_setcolor(0, 7);
					}
					_2048[i1][j].num = _2048[i1][j].num * 2;
					_2048[i1][j].flag = 1;
					_2048[i1 + 1][j].num = 0;
					color(_2048[i1][j].num);
					cct_gotoxy(14 * j + 2, 6 * i1 + 2);
					cout << "╔════╗";
					for (int i = 3; i <= 5; i++)
					{
						cct_gotoxy(14 * j + 2, 6 * i1 + i);
						cout << "║        ║";
					}
					cct_gotoxy(14 * j + 2, 6 * i1 + 6);
					cout << "╚════╝";
					cct_gotoxy(14 * j + 7, 6 * i1 + 4);
					cout << _2048[i1][j].num;
					cct_setcolor(0, 7);
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_2048[i][j].flag = 0;
}

void _2048_down(int hang, int lie, int yanshi, square _2048[8][8])
{
	for (int j = 0; j < lie; j++)
	{
		for (int i = hang - 1; i >= 0; i--)
		{
			if (_2048[i][j].num != 0)
			{
				int i1 = i + 1;
				for (; i1 < hang && _2048[i1][j].num == 0; i1++)
				{
					int t = _2048[i1][j].num;
					_2048[i1][j].num = _2048[i1 - 1][j].num;
					_2048[i1 - 1][j].num = t;
					for (int t = 0; t < 6; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 300000; i++)
								;
						else
							Sleep(yanshi);
						cct_gotoxy(14 * j + 2, 6 * i1 - 4 + t);
						cct_setcolor(15, 0);
						if (t == 5)
							cout << "──────";
						else
							cout << "            ";
						color(_2048[i1][j].num);
						cct_gotoxy(14 * j + 2, 6 * i1 - 3 + t);
						cout << "╔════╗";
						for (int i = 3; i <= 5; i++)
						{
							cct_gotoxy(14 * j + 2, 6 * i1 - 5 + i + t);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j + 2, 6 * i1 + 1 + t);
						cout << "╚════╝";
						cct_gotoxy(14 * j + 7, 6 * i1 - 1 + t);
						cout << _2048[i1][j].num;
						cct_setcolor(0, 7);
					}
				}
				if (i1 < hang && _2048[i1][j].num == _2048[i1 - 1][j].num && _2048[i1][j].flag == 0)
				{
					for (int t = 0; t < 6; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 300000; i++)
								;
						else
							Sleep(yanshi);
						cct_gotoxy(14 * j + 2, 6 * i1 - 4 + t);
						cct_setcolor(15, 0);
						if (t == 5)
							cout << "──────";
						else
							cout << "            ";
						color(_2048[i1][j].num);
						cct_gotoxy(14 * j + 2, 6 * i1 - 3 + t);
						cout << "╔════╗";
						for (int i = 3; i <= 5; i++)
						{
							cct_gotoxy(14 * j + 2, 6 * i1 - 5 + i + t);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j + 2, 6 * i1 + 1 + t);
						cout << "╚════╝";
						cct_gotoxy(14 * j + 7, 6 * i1 - 1 + t);
						cout << _2048[i1][j].num;
					}
					_2048[i1][j].num = _2048[i1][j].num * 2;
					_2048[i1][j].flag = 1;
					_2048[i1 - 1][j].num = 0;
					color(_2048[i1][j].num);
					cct_gotoxy(14 * j + 2, 6 * i1 + 2);
					cout << "╔════╗";
					for (int i = 3; i <= 5; i++)
					{
						cct_gotoxy(14 * j + 2, 6 * i1 + i);
						cout << "║        ║";
					}
					cct_gotoxy(14 * j + 2, 6 * i1 + 6);
					cout << "╚════╝";
					cct_gotoxy(14 * j + 7, 6 * i1 + 4);
					cout << _2048[i1][j].num;
					cct_setcolor(0, 7);
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_2048[i][j].flag = 0;
}

void _2048_left(int hang, int lie, int yanshi, square _2048[8][8])
{
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < lie; j++)
		{
			if (_2048[i][j].num != 0)
			{
				int j1 = j - 1;
				for (; j1 >= 0 && _2048[i][j1].num == 0; j1--)
				{
					int t = _2048[i][j1].num;
					_2048[i][j1].num = _2048[i][j1 + 1].num;
					_2048[i][j1 + 1].num = t;
					for (int t = 0; t < 14; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 30000; i++)
								;
						else
							Sleep(yanshi);
						for (int k = 0; k < 5; k++)
						{
							cct_gotoxy(14 * j1 + 26 - t, 6 * i + 2 + k);
							cct_setcolor(15, 0);
							if (t == 13)
							{
								cct_gotoxy(14 * j1 + 14, 6 * i + 2 + k);
								cout << "│";
							}
							else
								cout << "  ";
						}
						color(_2048[i][j1].num);
						cct_gotoxy(14 * j1 + 15 - t, 6 * i + 2);
						cout << "╔════╗";
						for (int k = 0; k < 3; k++)
						{
							cct_gotoxy(14 * j1 + 15 - t, 6 * i + 3 + k);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j1 + 15 - t, 6 * i + 6);
						cout << "╚════╝";
						cct_gotoxy(14 * j1 + 20 - t, 6 * i + 4);
						cout << _2048[i][j1].num;
						cct_setcolor(0, 7);
					}
				}
				if (j1 >= 0 && _2048[i][j1].num == _2048[i][j1 + 1].num && _2048[i][j1].flag == 0)
				{
					for (int t = 0; t < 14; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 30000; i++)
								;
						else
							Sleep(yanshi);
						for (int k = 0; k < 5; k++)
						{
							cct_gotoxy(14 * j1 + 26 - t, 6 * i + 2 + k);
							cct_setcolor(15, 0);
							if (t == 13)
							{
								cct_gotoxy(14 * j1 + 14, 6 * i + 2 + k);
								cout << "│";
							}
							else
								cout << "  ";
						}
						color(_2048[i][j1].num);
						cct_gotoxy(14 * j1 + 15 - t, 6 * i + 2);
						cout << "╔════╗";
						for (int k = 0; k < 3; k++)
						{
							cct_gotoxy(14 * j1 + 15 - t, 6 * i + 3 + k);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j1 + 15 - t, 6 * i + 6);
						cout << "╚════╝";
						cct_gotoxy(14 * j1 + 20 - t, 6 * i + 4);
						cout << _2048[i][j1].num;
						cct_setcolor(0, 7);
					}
					_2048[i][j1].num = _2048[i][j1].num * 2;
					_2048[i][j1].flag = 1;
					_2048[i][j1 + 1].num = 0;
					color(_2048[i][j1].num);
					cct_gotoxy(14 * j1 + 2, 6 * i + 2);
					cout << "╔════╗";
					for (int k = 0; k < 3; k++)
					{
						cct_gotoxy(14 * j1 + 2, 6 * i + 3 + k);
						cout << "║        ║";
					}
					cct_gotoxy(14 * j1 + 2, 6 * i + 6);
					cout << "╚════╝";
					cct_gotoxy(14 * j1 + 7, 6 * i + 4);
					cout << _2048[i][j1].num;
					cct_setcolor(0, 7);
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_2048[i][j].flag = 0;
}

void _2048_right(int hang, int lie, int yanshi, square _2048[8][8])
{
	for (int i = 0; i < hang; i++)
	{
		for (int j = lie - 1; j >= 0; j--)
		{
			if (_2048[i][j].num != 0)
			{
				int j1 = j + 1;
				for (; j1 < lie && _2048[i][j1].num == 0; j1++)
				{
					int t = _2048[i][j1].num;
					_2048[i][j1].num = _2048[i][j1 - 1].num;
					_2048[i][j1 - 1].num = t;
					for (int t = 0; t < 14; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 30000; i++)
								;
						else
							Sleep(yanshi);
						for (int k = 0; k < 5; k++)
						{
							cct_gotoxy(14 * j1 - 12 + t, 6 * i + 2 + k);
							cct_setcolor(15, 0);
							if (t == 13)
							{
								cct_gotoxy(14 * j1, 6 * i + 2 + k);
								cout << "│";
							}
							else
								cout << "  ";
						}
						color(_2048[i][j1].num);
						cct_gotoxy(14 * j1 - 11 + t, 6 * i + 2);
						cout << "╔════╗";
						for (int k = 0; k < 3; k++)
						{
							cct_gotoxy(14 * j1 - 11 + t, 6 * i + 3 + k);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j1 - 11 + t, 6 * i + 6);
						cout << "╚════╝";
						cct_gotoxy(14 * j1 - 6 + t, 6 * i + 4);
						cout << _2048[i][j1].num;
						cct_setcolor(0, 7);
					}
				}
				if (j1 < lie && _2048[i][j1].num == _2048[i][j1 - 1].num && _2048[i][j1].flag == 0)
				{
					for (int t = 0; t < 14; t++)
					{
						if (yanshi == 0)
							for (int i = 0; i < 30000; i++)
								;
						else
							Sleep(yanshi);
						for (int k = 0; k < 5; k++)
						{
							cct_gotoxy(14 * j1 - 12 + t, 6 * i + 2 + k);
							cct_setcolor(15, 0);
							if (t == 13)
							{
								cct_gotoxy(14 * j1, 6 * i + 2 + k);
								cout << "│";
							}
							else
								cout << "  ";
						}
						color(_2048[i][j1].num);
						cct_gotoxy(14 * j1 - 11 + t, 6 * i + 2);
						cout << "╔════╗";
						for (int k = 0; k < 3; k++)
						{
							cct_gotoxy(14 * j1 - 11 + t, 6 * i + 3 + k);
							cout << "║        ║";
						}
						cct_gotoxy(14 * j1 - 11 + t, 6 * i + 6);
						cout << "╚════╝";
						cct_gotoxy(14 * j1 - 6 + t, 6 * i + 4);
						cout << _2048[i][j1].num;
						cct_setcolor(0, 7);
					}
					_2048[i][j1].num = _2048[i][j1].num * 2;
					_2048[i][j1].flag = 1;
					_2048[i][j1 - 1].num = 0;
					color(_2048[i][j1].num);
					cct_gotoxy(14 * j1 + 2, 6 * i + 2);
					cout << "╔════╗";
					for (int k = 0; k < 3; k++)
					{
						cct_gotoxy(14 * j1 + 2, 6 * i + 3 + k);
						cout << "║        ║";
					}
					cct_gotoxy(14 * j1 + 2, 6 * i + 6);
					cout << "╚════╝";
					cct_gotoxy(14 * j1 + 7, 6 * i + 4);
					cout << _2048[i][j1].num;
					cct_setcolor(0, 7);
				}
			}
		}
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_2048[i][j].flag = 0;
}