/*1953729 ��09 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "90-02-b1-popstar.h"
using namespace std;

int menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "1.�������ҳ����������ʶ" << endl;
	cout << "2.���������һ���������ֲ�����ʾ��" << endl;
	cout << "3.���������һ�أ��ֲ�����ʾ��" << endl;
	cout << "4.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�" << endl;
	cout << "5.αͼ�ν������һ���������ֲ��裩" << endl;
	cout << "6.αͼ�ν���������" << endl;
	cout << "0.�˳���Ϸ" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "[��ѡ��] :";
	while (1)
	{
		char num = _getch();
		if (num >= '0' && num <= '7')
			return num - 48;
	}
}

