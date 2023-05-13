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
int main()
{
	while (1)
	{
		cct_setfontsize("新宋体", 24);
		cct_setcolor(0, 7);
		cct_setconsoleborder(55, 32, 55, 32);
		int num = menu();
		int popstar[12][12] = {};
		int dakai[12][12] = {};
		char fenshu[12][12] = {};
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
				fenshu[i][j] = '0';
		int alph1, alph2, score = 0, flag = 0;
		if (num == 0)
		{
			cout << '0';
			break;
		}
		cct_cls();
		int hang, lie;
		InputHangLie(hang, lie, popstar);
		if (num == 1 || num == 2)
		{
			OutputDangQianSZ(hang, lie, popstar, dakai);
			InputZuoBiao(alph1, alph2, hang, lie);
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				end(num, hang, lie);
				continue;
			}
			Judge(alph1, alph2, hang, lie, popstar);
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				end(num, hang, lie);
				continue;
			}
			kuosan(alph1, alph2, popstar, dakai, fenshu);
			OutputDangQianSZ(hang, lie, popstar, dakai);
			if (num == 2)
			{
				OutputGuiBingSZ(hang, lie, popstar, dakai);
				OutputXiaLuoSZ(hang, lie, popstar, dakai);
			}
		}
		if (num == 3)
		{
			OutputDangQianSZ(hang, lie, popstar, dakai);
			while (PanDuanEnd(hang, lie, popstar))
			{
				InputZuoBiao(alph1, alph2, hang, lie);
				if (alph1 == 'q' || alph1 == 'Q')
				{
					cout << endl;
					break;
				}
				Judge(alph1, alph2, hang, lie, popstar);
				if (alph1 == 'q' || alph1 == 'Q')
				{
					cout << endl;
					break;
				}
				kuosan(alph1, alph2, popstar, dakai, fenshu);
				OutputDangQianSZ(hang, lie, popstar, dakai);
				OutputGuiBingSZ(hang, lie, popstar, dakai);
				OutScore(fenshu, score, num);
				OutputXiaLuoSZ(hang, lie, popstar, dakai);
			}
		}
		if (num == 4)
		{
			kuangjia(hang, lie, popstar);
			shubiao(flag, alph1, alph2, hang, lie, popstar);
		}
		if (num == 5)
		{
			kuangjia(hang, lie, popstar);
			shubiao(flag, alph1, alph2, hang, lie, popstar);
			kuosan(alph1, alph2, popstar, dakai, fenshu);
			for (int i = 1; i <= hang; i++)
			{
				for (int j = 1; j <= lie; j++)
				{
					if (dakai[i][j] == 1)
						popstar[i][j] = 0;
				}
			}
			for (int i = 1; i <= hang; i++)
				for (int j = 1; j <= lie; j++)
				{
					if (fenshu[i][j] == '*')
					{
						cct_setcolor(15, 15);
						cct_gotoxy(6 * j - 2, 3 * i);
						cout << "      ";
						cct_gotoxy(6 * j - 2, 3 * i + 1);
						cout << "      ";
						cct_gotoxy(6 * j - 2, 3 * i + 2);
						cout << "      ";
						cct_setcolor(0, 7);
					}
				}
			OutScore(fenshu, score, num);
			XiaLuo(hang, lie, popstar, dakai);
		}
		if (num == 6)
		{
			kuangjia(hang, lie, popstar);
			cct_gotoxy(0, 5 + 3 * hang);
			cout << "按Esc退出";
			cct_gotoxy(0, 0);
			while (PanDuanEnd(hang, lie, popstar))
			{
				shubiao(flag, alph1, alph2, hang, lie, popstar);
				if (flag == 1)
					break;
				kuosan(alph1, alph2, popstar, dakai, fenshu);
				for (int i = 1; i <= hang; i++)
				{
					for (int j = 1; j <= lie; j++)
					{
						if (dakai[i][j] == 1)
							popstar[i][j] = 0;
					}
				}
				for (int i = 1; i <= hang; i++)
					for (int j = 1; j <= lie; j++)
					{
						if (fenshu[i][j] == '*')
						{
							cct_setcolor(15, 15);
							cct_gotoxy(6 * j - 2, 3 * i);
							cout << "      ";
							cct_gotoxy(6 * j - 2, 3 * i + 1);
							cout << "      ";
							cct_gotoxy(6 * j - 2, 3 * i + 2);
							cout << "      ";
							cct_setcolor(0, 7);
						}
					}
				OutScore(fenshu, score, num);
				XiaLuo(hang, lie, popstar, dakai);
			}
		}
		end(num, hang, lie);
	}
	cout << endl;
	cct_setfontsize("新宋体", 16);
	cct_setconsoleborder(120, 40, 120, 95);
	return 0;
}