/*1953729 信09 吴浩泽*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "90-01-b2-mine_sweeper.h"
#include "../include/cmd_console_tools.h"
using namespace std;

void neibushuzu(int nanduxuanze, int num)
{
	if (nanduxuanze == 1)
		nandu1(nanduxuanze, num);
	else if (nanduxuanze == 2)
		nandu2(nanduxuanze, num);
	else
		nandu3(nanduxuanze, num);
}

void kuosan(char saolei[][11], char fugai[][11], char dakai[][11], char biaoji[][11], int alph1, int alph2)
{
	for (int i = alph1 - 1; i <= alph1 + 1; i++)
	{
		for (int j = alph2 - 1; j <= alph2 + 1; j++)
		{
			if (dakai[i][j] == 1)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else
					fugai[i][j] = saolei[i][j];
				continue;
			}
			if (dakai[i][j] == 0)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else
					fugai[i][j] = saolei[i][j];
				dakai[i][j] = 1;
			}
			if (saolei[i][j] == '0')
				kuosan(saolei, fugai, dakai, biaoji, i, j);
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (fugai[i][j] == '\0')
				fugai[i][j] = 'X';
		}
	}
}

void kuosan(char saolei[][18], char fugai[][18], char dakai[][18], char biaoji[][18], int alph1, int alph2)
{
	for (int i = alph1 - 1; i <= alph1 + 1; i++)
	{
		for (int j = alph2 - 1; j <= alph2 + 1; j++)
		{
			if (dakai[i][j] == 1)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else
					fugai[i][j] = saolei[i][j];
				continue;
			}
			if (dakai[i][j] == 0)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else
					fugai[i][j] = saolei[i][j];
				dakai[i][j] = 1;
			}
			if (saolei[i][j] == '0')
				kuosan(saolei, fugai, dakai, biaoji, i, j);
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 16; j++)
		{
			if (fugai[i][j] == '\0')
				fugai[i][j] = 'X';
		}
	}
}

void kuosan(char saolei[][32], char fugai[][32], char dakai[][32], char biaoji[][32], int alph1, int alph2)
{
	for (int i = alph1 - 1; i <= alph1 + 1; i++)
	{
		for (int j = alph2 - 1; j <= alph2 + 1; j++)
		{
			if (dakai[i][j] == 1)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else if (biaoji[i][j] == 2)
					fugai[i][j] = fugai[i][j];
				else
					fugai[i][j] = saolei[i][j];
				continue;
			}
			if (dakai[i][j] == 0)
			{
				if (biaoji[i][j] == 1)
					fugai[i][j] = 'X';
				else if (biaoji[i][j] == 2)
					fugai[i][j] = fugai[i][j];
				else
					fugai[i][j] = saolei[i][j];
				dakai[i][j] = 1;
			}
			if (saolei[i][j] == '0')
				kuosan(saolei, fugai, dakai, biaoji, i, j);
		}
	}
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 30; j++)
		{
			if (fugai[i][j] == '\0')
				fugai[i][j] = 'X';
		}
	}
}

void nandu1(int nanduxuanze, int num)
{
	clock_t start, end;
	start = clock();
	end = clock();
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9" << endl;
	cout << "--+--------------------" << endl;
	char saolei[11][11] = {};
	char fugai[11][11] = {};
	char dakai[11][11] = {};
	char biaoji[11][11] = {};
	int alph1, alph2;
	if (num == 2 || num == 3)
	{
		for (int i = 1; i <= 9; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (num == 4)
	{
		for (int i = 1; i <= 9; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E3)" << endl;
		cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (biaoji[alph1][alph2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9" << endl;
			cout << "--+--------------------" << endl;
			for (int i = 1; i <= 9; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j <= 9; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
			while (alph1 == '&')
			{
				cout << endl;
				end = clock();
				cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
				cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
				cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
				cout << "              # - 取消标记      (例：#E3)" << endl;
				cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
				input(alph1, alph2, num, dakai, biaoji);
			}
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
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
		if (num == 2 || num == 3 || num == 4)
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
	if (num == 1)
		output(num, saolei, fugai, biaoji);
	if (num == 2)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		output(num, saolei, fugai, biaoji);
	}
	if (num == 3 || num == 4)
		game1(saolei, fugai, dakai, biaoji, alph1, alph2, num, nanduxuanze, start, end);
}

void nandu2(int nanduxuanze, int num)
{
	clock_t start, end;
	start = clock();
	end = clock();
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
	cout << "--+----------------------------------" << endl;
	char saolei[18][18] = {};
	char fugai[18][18] = {};
	char dakai[18][18] = {};
	char biaoji[18][18] = {};
	int alph1, alph2;
	if (num == 2 || num == 3)
	{
		for (int i = 1; i <= 16; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (num == 4)
	{
		for (int i = 1; i <= 16; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E3)" << endl;
		cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (biaoji[alph1][alph2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
			cout << "--+----------------------------------" << endl;
			for (int i = 1; i <= 16; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j <= 16; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
			while (alph1 == '&')
			{
				cout << endl;
				end = clock();
				cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
				cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
				cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
				cout << "              # - 取消标记      (例：#E3)" << endl;
				cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
				input(alph1, alph2, num, dakai, biaoji);
			}
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
		cout << endl << endl;
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
		if (num == 2 || num == 3 || num == 4)
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
	if (num == 1)
		output(num, saolei, fugai, biaoji);
	if (num == 2)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		output(num, saolei, fugai, biaoji);
	}
	if (num == 3 || num == 4)
		game1(saolei, fugai, dakai, biaoji, alph1, alph2, num, nanduxuanze, start, end);
}

void nandu3(int nanduxuanze, int num)
{
	clock_t start, end;
	start = clock();
	end = clock();
	cout << "内部数组：" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
	cout << "--+--------------------------------------------------------------" << endl;
	char saolei[18][32] = {};
	char fugai[18][32] = {};
	char dakai[18][32] = {};
	char biaoji[18][32] = {};
	int alph1, alph2;
	if (num == 2 || num == 3)
	{
		for (int i = 1; i <= 16; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (num == 4)
	{
		for (int i = 1; i <= 16; i++)
		{
			char alph = 64;
			cout << (char)(alph + i) << " |";
			cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
		}
		cout << endl << endl;
		cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
		cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
		cout << "              # - 取消标记      (例：#E3)" << endl;
		cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (biaoji[alph1][alph2] != 0)
		{
			cout << "当前数组：" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
			cout << "--+--------------------------------------------------------------" << endl;
			for (int i = 1; i <= 16; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j <= 30; j++)
				{
					if (biaoji[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
			input(alph1, alph2, num, dakai, biaoji);
			while (alph1 == '&')
			{
				cout << endl;
				end = clock();
				cout << "已运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl << endl;
				cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
				cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
				cout << "              # - 取消标记      (例：#E3)" << endl;
				cout << "请输入（坐标必须先行后列，严格区分大小写，例：G1/Af，按Q/q退出）：";
				input(alph1, alph2, num, dakai, biaoji);
			}
			if (alph1 == 'q' || alph1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
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
		if (num == 2 || num == 3 || num == 4)
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
	if (num == 1)
		output(num, saolei, fugai, biaoji);
	if (num == 2)
	{
		kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
		output(num, saolei, fugai, biaoji);
	}
	if (num == 3 || num == 4)
		game1(saolei, fugai, dakai, biaoji, alph1, alph2, num, nanduxuanze, start, end);
}

