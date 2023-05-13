/* 1953729 ��09 ����� */

/* -----------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ����const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
using namespace std;
int main()
{
	cct_setconsoleborder(120, 40, 120, 9000);       /* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setfontsize("������", 16);
	int n;
	char src, dst, tmp;
	int* pn = &n;
	char* ps = &src, * pt = &tmp, * pd = &dst;
	int num = menu();
	cout << endl << endl;
	while (1)
	{
		input(pn, ps, pt, pd, num);
		if (num == 0)
		{
			cout << endl << endl;
			break;
		}
		if (num == 1 || num == 2 || num == 3 || num == 4 || num == 8)
			hanoi(n, src, tmp, dst, num);
		else if (num == 5 || num == 6)
		{
			cct_cls();
			draw(n, src, dst, num);
		}
		else if (num == 7)
		{
			cct_cls();
			if (n % 2 != 0)
				draw(n, src, dst, num);
			else
				draw(n, src, tmp, num);
			Sleep(1000);
			if (n % 2 != 0)
				move(n, src, dst, num);
			else
				move(n, src, tmp, num);
		}
		else if (num == 9)
			ninth(n, src, tmp, dst, num);
		num = end(num);
		cout << endl << endl;
	}
	cct_setfontsize("������", 16);
	cct_setconsoleborder(120, 40, 120, 95);
	return 0;
}

