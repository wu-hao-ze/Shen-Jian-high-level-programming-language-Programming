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

int main()
{
	cct_setcolor(0, 7);
	int hang, lie, score, yanshi;
	int sum = 0, biaoji = 0;
	int alph1, alph2;
	char ch;
	square _2048[8][8];
	srand((unsigned int)(time(0)));
	cct_setfontsize("新宋体", 20);
	while (1)
	{
		biaoji = 0;
		cct_setcursor(2);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				_2048[i][j].num = 0;
				_2048[i][j].flag = 0;
			}
		}
		menu(hang, lie, score, yanshi);
		cct_setcursor(3);
		KuangJia(hang, lie, score, _2048);
		while (!biaoji)
		{
			while (1)
			{
				alph1 = rand() % hang, alph2 = rand() % lie;
				if (_2048[alph1][alph2].num == 0)
				{
					int i = rand() % 4;
					if (i <= 1)
						_2048[alph1][alph2].num = 2;
					else
						_2048[alph1][alph2].num = 4;
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
					break;
				}
			}
			while (1)
			{
				ch = _getch();
				if (ch == 'r' || ch == 'q')
					break;
				if (ch == '\340')
				{
					ch = _getch();
					if (ch != '\110' && ch != '\120' && ch != '\113' && ch != '\115')
						continue;
					else
					{
						int check[8][8];
						for (int i = 0; i < hang; i++)
							for (int j = 0; j < lie; j++)
								check[i][j] = _2048[i][j].num;
						if (ch == '\110')
							_2048_up(hang, lie, yanshi, _2048);
						if (ch == '\120')
							_2048_down(hang, lie, yanshi, _2048);
						if (ch == '\113')
							_2048_left(hang, lie, yanshi, _2048);
						if (ch == '\115')
							_2048_right(hang, lie, yanshi, _2048);
						int i, j;
						for (i = 0; i < hang; i++)
						{
							for (j = 0; j < lie; j++)
							{
								if (check[i][j] != _2048[i][j].num)
									break;
							}
							if (j < lie && check[i][j] != _2048[i][j].num)
								break;
						}
						if (i == hang && j == lie)
						{
							sum = 0;
							for (int i = 0; i < hang; i++)
								for (int j = 0; j < lie; j++)
									if (_2048[i][j].num != 0)
										sum++;
							if (sum == hang * lie)
							{
								biaoji = 1;
								break;
							}
							else
								continue;
						}
						else
							break;
					}
				}
			}
			if (ch == 'r' || ch == 'q')
				break;
			sum = 0;
			for (int i = 0; i < hang; i++)
				for (int j = 0; j < lie; j++)
					if (_2048[i][j].num != 0)
						sum++;
			if (sum == hang * lie)
				biaoji = 1;
			for (int i = 0; i < hang; i++)
				for (int j = 0; j < lie; j++)
					if (_2048[i][j].num == score)
						biaoji = 2;
		}
		if (biaoji != 0)
		{
			cct_setcolor(12, 15);
			cct_gotoxy(7 * lie - 5, 3 * hang - 1);
			cout << "╔════╗";
			cct_gotoxy(7 * lie - 5, 3 * hang);
			if (biaoji == 1)
				cout << "║游戏失败║";
			if (biaoji == 2)
				cout << "║游戏成功║";
			cct_gotoxy(7 * lie - 5, 3 * hang + 1);
			cout << "║r： 重玩║";
			cct_gotoxy(7 * lie - 5, 3 * hang + 2);
			cout << "║q： 退出║";
			cct_gotoxy(7 * lie - 5, 3 * hang + 3);
			cout << "╚════╝";
			cct_setcolor(0, 7);
			while (1)
			{
				ch = _getch();
				if (ch == 'r' || ch == 'q')
					break;
			}
		}
		if (ch == 'r')
			continue;
		if (ch == 'q')
			break;
	}
	cct_cls();
	cct_setcursor(2);
	cct_setfontsize("新宋体", 16);
	cct_setcolor(0, 7);
	cct_setconsoleborder(120, 40, 120, 95);
	return 0;
}