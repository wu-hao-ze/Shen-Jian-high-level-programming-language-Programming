/*1953729 ��09 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int menu()
{
	cout << "------------------------------------------" << endl;
	cout << "1.ѡ���ѶȲ���ʾ�ڲ�����" << endl;
	cout << "2.�����ʼλ�ò���ʾ���򿪵ĳ�ʼ����" << endl;
	cout << "3.�ڲ����������" << endl;
	cout << "4.�ڲ����������棨��ǡ�����ʱ�䣩" << endl;
	cout << "5.����αͼ�λ���ܲ���ʾ�ڲ�����" << endl;
	cout << "6.������λ�úͺϷ��ԣ���������˳���" << endl;
	cout << "7.���ѡ���ʼλ�ò���ʾ���򿪵ĳ�ʼ����" << endl;
	cout << "8.αͼ�ν��������" << endl;
	cout << "9.αͼ�ν���������" << endl;
	cout << "0.�˳���Ϸ" << endl;
	cout << "------------------------------------------" << endl;
	cout << "[��ѡ��] :";
	while (1)
	{
		char num = _getch();
		switch (num)
		{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			;
		}
	}
}
