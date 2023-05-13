/*1953729 ��09 �����*/
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

int nandu()
{
	cout << "��ѡ���Ѷȣ�" << endl;
	cout << "  1.����( 9*9  - 10����)" << endl;
	cout << "  2.�м�(16*16 - 40����)" << endl;
	cout << "  3.�߼�(16*30 - 99����)" << endl;
	cout << "������[1..3]��";
	while (1)
	{
		char num = _getch();
		switch (num)
		{
		case '1':
		{
			cct_cls();
			return 1;
		}
		case '2':
		{
			cct_cls();
			return 2;
		}
		case '3':
		{
			cct_cls();
			return 3;
		}
		default:
			;
		}
	}
}

int end(int& num, int nanduxuanze)

{
	if (num == 1 || num == 2 || num == 3 || num == 4)
		cout << "���س�������...";
	if (num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
	{
		if (nanduxuanze == 1)
		{
			cct_gotoxy(0, 33);
			cout << "���س�������...";
		}
		if (nanduxuanze == 2 || nanduxuanze == 3)
		{
			cct_gotoxy(0, 54);
			cout << "���س�������...";
		}
	}
	while (_getch() != '\r')
		;
	cct_cls();
	cct_setfontsize("������", 24);
	cct_setconsoleborder(100, 30, 100, 30);
	num = menu();
	return num;
}

void yanse(char x)
{
	switch (x)
	{
	case '0':
		cct_setcolor(14, 0);
		break;
	case '1':
		cct_setcolor(14, 1);
		break;
	case '2':
		cct_setcolor(14, 2);
		break;
	case '3':
		cct_setcolor(14, 3);
		break;
	case '4':
		cct_setcolor(14, 4);
		break;
	case '5':
		cct_setcolor(14, 5);
		break;
	case '6':
		cct_setcolor(14, 6);
		break;
	case '7':
		cct_setcolor(14, 7);
		break;
	case '8':
		cct_setcolor(14, 8);
		break;
	case 'X':
		cct_setcolor(0, 7);
		break;
	case '*':
		cct_setcolor(0, 7);
		break;
	}
	cout << x;
	cct_setcolor(0, 7);
	cout << ' ';
}

void input(int& alph1, int& alph2, int num, char dakai[][11], char biaoji[][11])
{
	while (1)
	{
		alph1 = _getch();
		if (num == 4)
		{
			if (alph1 == '&')
			{
				cout << '&';
				return;
			}
			if (alph1 == '!')
			{
				cout << '!';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'I')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0)
					biaoji[alph1][alph2] = 1;
				return;
			}
			if (alph1 == '#')
			{
				cout << '#';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'I')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0 || dakai[alph1][alph2] == 1 && biaoji[alph1][alph2] == 1)
					biaoji[alph1][alph2] = 2;
				return;
			}
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << (char)(alph1);
			return;
		}
		if (alph1 >= 'A' && alph1 <= 'I')
		{
			cout << (char)(alph1);
			alph1 = alph1 - 64;
			break;
		}
	}
	while (1)
	{
		alph2 = _getch();
		if (alph2 >= '1' && alph2 <= '9')
		{
			cout << (char)(alph2);
			alph2 = alph2 - 48;
			break;
		}
	}
	if (biaoji[alph1][alph2] == 2)
		biaoji[alph1][alph2] = 0;
}

void input(int& alph1, int& alph2, int num, char dakai[][18], char biaoji[][18])
{
	while (1)
	{
		alph1 = _getch();
		if (num == 4)
		{
			if (alph1 == '&')
			{
				cout << '&';
				return;
			}
			if (alph1 == '!')
			{
				cout << '!';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'P')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
					if (alph2 >= 'a' && alph2 <= 'g')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 87;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0)
					biaoji[alph1][alph2] = 1;
				return;
			}
			if (alph1 == '#')
			{
				cout << '#';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'P')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
					if (alph2 >= 'a' && alph2 <= 'g')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 87;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0 || dakai[alph1][alph2] == 1 && biaoji[alph1][alph2] == 1)
					biaoji[alph1][alph2] = 2;
				return;
			}
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << (char)(alph1);
			return;
		}
		if (alph1 >= 'A' && alph1 <= 'P')
		{
			cout << (char)(alph1);
			alph1 = alph1 - 64;
			break;
		}
	}
	while (1)
	{
		alph2 = _getch();
		if (alph2 >= '1' && alph2 <= '9')
		{
			cout << (char)(alph2);
			alph2 = alph2 - 48;
			break;
		}
		if (alph2 >= 'a' && alph2 <= 'g')
		{
			cout << (char)(alph2);
			alph2 = alph2 - 87;
			break;
		}
	}
	if (biaoji[alph1][alph2] == 2)
		biaoji[alph1][alph2] = 0;
}

void input(int& alph1, int& alph2, int num, char dakai[][32], char biaoji[][32])
{
	while (1)
	{
		alph1 = _getch();
		if (num == 4)
		{
			if (alph1 == '&')
			{
				cout << '&';
				return;
			}
			if (alph1 == '!')
			{
				cout << '!';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'P')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
					if (alph2 >= 'a' && alph2 <= 'u')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 87;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0)
					biaoji[alph1][alph2] = 1;
				return;
			}
			if (alph1 == '#')
			{
				cout << '#';
				while (1)
				{
					alph1 = _getch();
					if (alph1 >= 'A' && alph1 <= 'P')
					{
						cout << (char)(alph1);
						alph1 = alph1 - 64;
						break;
					}
				}
				while (1)
				{
					alph2 = _getch();
					if (alph2 >= '1' && alph2 <= '9')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 48;
						break;
					}
					if (alph2 >= 'a' && alph2 <= 'u')
					{
						cout << (char)(alph2);
						alph2 = alph2 - 87;
						break;
					}
				}
				if (dakai[alph1][alph2] == 0 || dakai[alph1][alph2] == 1 && biaoji[alph1][alph2] == 1)
					biaoji[alph1][alph2] = 2;
				return;
			}
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << (char)(alph1);
			return;
		}
		if (alph1 >= 'A' && alph1 <= 'P')
		{
			cout << (char)(alph1);
			alph1 = alph1 - 64;
			break;
		}
	}
	while (1)
	{
		alph2 = _getch();
		if (alph2 >= '1' && alph2 <= '9')
		{
			cout << (char)(alph2);
			alph2 = alph2 - 48;
			break;
		}
		if (alph2 >= 'a' && alph2 <= 'u')
		{
			cout << (char)(alph2);
			alph2 = alph2 - 87;
			break;
		}
	}
	if (biaoji[alph1][alph2] == 2)
		biaoji[alph1][alph2] = 0;
}

void output(int num, char saolei[][11], char fugai[][11], char biaoji[][11])
{
	if (num == 1)
	{
		for (int i = 1; i <= 9; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 9; j++)
			{
				cout << saolei[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	if (num == 2 || num == 3 || num == 4)
	{
		if (num == 2)
			cout << "�㿪������飺" << endl;
		if (num == 3 || num == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9" << endl << "--+--------------------" << endl;
		for (int i = 1; i <= 9; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 9; j++)
			{
				if (biaoji[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << fugai[i][j];
					cct_setcolor(0, 7);
					cout << ' ';
				}
				else
					yanse(fugai[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

void output(int num, char saolei[][18], char fugai[][18], char biaoji[][18])
{
	if (num == 1)
	{
		for (int i = 1; i <= 16; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 16; j++)
			{
				cout << saolei[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	if (num == 2 || num == 3 || num == 4)
	{
		if (num == 2)
			cout << "�㿪������飺" << endl;
		if (num == 3 || num == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl << "--+----------------------------------" << endl;
		for (int i = 1; i <= 16; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 16; j++)
			{
				if (biaoji[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << fugai[i][j];
					cct_setcolor(0, 7);
					cout << ' ';
				}
				else
					yanse(fugai[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

void output(int num, char saolei[][32], char fugai[][32], char biaoji[][32])
{
	if (num == 1)
	{
		for (int i = 1; i <= 16; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 30; j++)
			{
				cout << saolei[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	if (num == 2 || num == 3 || num == 4)
	{
		if (num == 2)
			cout << "�㿪������飺" << endl;
		if (num == 3 || num == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl << "--+--------------------------------------------------------------" << endl;
		for (int i = 1; i <= 16; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j <= 30; j++)
			{
				if (biaoji[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << fugai[i][j];
					cct_setcolor(0, 7);
					cout << ' ';
				}
				else
					yanse(fugai[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

void game1(char saolei[][11], char fugai[][11], char dakai[][11], char biaoji[][11], int alph1, int alph2, int num, int nanduxuanze, clock_t start, clock_t end)
{
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	output(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		if (num == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (num == 4)
		{
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		}
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "������ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl << endl;
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
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
		output(num, saolei, fugai, biaoji);
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
			cout << "��ϲʤ������Ϸ����" << endl;
			break;
		}
		if (fugai[alph1][alph2] == '*')
			cout << "�����ˣ���Ϸ����" << endl;
	}
}

void game1(char saolei[][18], char fugai[][18], char dakai[][18], char biaoji[][18], int alph1, int alph2, int num, int nanduxuanze, clock_t start, clock_t end)
{
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	output(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		if (num == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (num == 4)
		{
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		}
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "������ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl << endl;
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
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
		output(num, saolei, fugai, biaoji);
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
			cout << "��ϲʤ������Ϸ����" << endl;
			break;
		}
		if (fugai[alph1][alph2] == '*')
			cout << "�����ˣ���Ϸ����" << endl;
	}
}

void game1(char saolei[][32], char fugai[][32], char dakai[][32], char biaoji[][32], int alph1, int alph2, int num, int nanduxuanze, clock_t start, clock_t end)
{
	kuosan(saolei, fugai, dakai, biaoji, alph1, alph2);
	output(num, saolei, fugai, biaoji);
	while (saolei[alph1][alph2] != '*' || biaoji[alph1][alph2] != 0)
	{
		if (num == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (num == 4)
		{
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		}
		input(alph1, alph2, num, dakai, biaoji);
		while (alph1 == '&')
		{
			cout << endl;
			end = clock();
			cout << "������ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl << endl;
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
			input(alph1, alph2, num, dakai, biaoji);
		}
		if (alph1 == 'q' || alph1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
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
		output(num, saolei, fugai, biaoji);
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
			cout << "��ϲʤ������Ϸ����" << endl;
			break;
		}
		if (fugai[alph1][alph2] == '*')
			cout << "�����ˣ���Ϸ����" << endl;
	}
}

