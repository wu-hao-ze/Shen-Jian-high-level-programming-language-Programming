/* 1953729 ��09 ����� */

/* -----------------------------------------

     ���ļ����ܣ�
	1���ű� hanoi_main.cpp/hanoi_menu.cpp �еĸ��������õĲ˵������Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2���������徲̬ȫ�ֱ�����ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

int menu()
{
	cout << "----------------------------------" << endl;
	cout << "1.������" << endl;
	cout << "2.������(������¼)" << endl;
	cout << "3.�ڲ�������ʾ(����)" << endl;
	cout << "4.�ڲ�������ʾ(����+����)" << endl;
	cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
	cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
	cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
	cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
	cout << "9.ͼ�ν�-��Ϸ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "----------------------------------" << endl;
	cout << "[��ѡ��:] " ;
	while (1)
	{
		char num = _getch();
		switch (num)
		{
			case '0':
				cout << 0;
				return 0;
			case '1':
				cout << 1;
				return 1;
			case '2':
				cout << 2;
				return 2;
			case '3':
				cout << 3;
				return 3;
			case '4':
				cout << 4;
				return 4;
			case '5':
				cout << 5;
				return 5;
			case '6':
				cout << 6;
				return 6;
			case '7':
				cout << 7;
				return 7;
			case '8':
				cout << 8;
				return 8;
			case '9':
				cout << 9;
				return 9;
			default:
				;
		}
	}
}


