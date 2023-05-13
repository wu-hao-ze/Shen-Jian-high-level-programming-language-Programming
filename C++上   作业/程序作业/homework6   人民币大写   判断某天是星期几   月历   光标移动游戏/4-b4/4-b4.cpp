/* 1953729 ��09 ����� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>



using namespace std;


const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

 /***************************************************************************
  �������ƣ�cls 
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ���� 
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu()
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ�������ͷ���������ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ������ͷ���������ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "��ѡ��[0-6]";
	return _getch();
}
void move_by_ijkl(const HANDLE hout, int X, int Y, int Z, int P)
{
	char a = _getch();
	int b = Y;
	int c = X;
	while (a != 'q' && a != 'Q')
	{
		if (a == '\40')
		{
			showch(hout, c, b, ' ');
			gotoxy(hout, c, b);
			a = _getch();
			continue;
		}
		if (Z == 1)
		{
			if (a != 'i' && a != 'I' && a != 'j' && a != 'J' && a != 'k' && a != 'K' && a != 'l' && a != 'L' && a != '\340')
			{
				;
				a = _getch();
				continue;
			}
			if (a == 'i' || a == 'I')
			{
				if (b == 1)
					;
				else
				{
					b = b - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();	
				continue;
			}
			if (a == 'j' || a == 'J')
			{
				if (c == 1)
					;
				else
				{
					c = c - 1;
					gotoxy(hout, c, b);
				}	
				a = _getch();
				continue;
			}
			if (P == 0 || P != 0 && a != '\340')
			{
				if (a == '\340')
				{
					char i = _getch();
					if (i == '\113')
					{
						if (b == 17)
							;
						else
						{
							b = b + 1;
							gotoxy(hout, c, b);
						}
						a = _getch();
						continue;
					}
					else 
					{
						a = _getch();
						continue;
					}
				}
				if (a == 'k' || a == 'K')
				{
					if (b == 17)
						;
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (P != 0 && a == '\340')
			{
				char i = _getch();
				a = _getch();
				continue;
			}
			if (a == 'l' || a == 'L')
			{
				if (c == 69)
					;
				else
				{
					c = c + 1;
					gotoxy(hout, c, b);
				}	
				a = _getch();
				continue;
			}
		}
		if (Z == 2)
		{
			if (a != 'i' && a != 'I' && a != 'j' && a != 'J' && a != 'k' && a != 'K' && a != 'l' && a != 'L' && a != '\340')
			{
				;
				a = _getch();
				continue;
			}
			if (a == 'i' || a == 'I')
			{
				if (b == 1)
				{
					b = 17;
					gotoxy(hout, c, b);
				}
				else
				{
					b = b - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
			if (a == 'j' || a == 'J')
			{
				if (c == 1)
				{
					c = 69;
					gotoxy(hout, c, b);
				}
				else
				{
					c = c - 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
			if (P == 0 || P != 0 && a != '\340')
			{
				if (a == '\340')
				{
					char i = _getch();
					if (i == '\113')
					{
						if (b == 17)
						{
							b = 1;
							gotoxy(hout, c, b);
						}
						else
						{
							b = b + 1;
							gotoxy(hout, c, b);
						}
						a = _getch();
						continue;
					}
					else 
					{
						a = _getch();
						continue;
					}
				}
				if (a == 'k' || a == 'K')
				{
					if (b == 17)
					{
						b = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (P != 0 && a == '\340')
			{
				char i = _getch();
				a = _getch();
				continue;
			}
			if (a == 'l' || a == 'L')
			{
				if (c == 69)
				{
					c = 1;
					gotoxy(hout, c, b);
				}
				else
				{
					c = c + 1;
					gotoxy(hout, c, b);
				}
				a = _getch();
				continue;
			}
		}
	}
	if (a == 'q' || a == 'Q')
	{
		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س������ز˵�." << endl;
	}
}
void move_by_arrow(const HANDLE hout, int X, int Y, int Z)
{
	char a = _getch();
	int b = Y;
	int c = X;
	while (a != 'q' && a != 'Q')
	{
		if (a == '\40')
		{
			showch(hout, c, b, ' ');
			gotoxy(hout, c, b);
			a = _getch();
			continue;
		}
		else if (a == '\340')
		{
			char x = _getch();
			if (Z == 1)
			{
				if (x != '\110' && x != '\120' && x != '\113' && x != '\115')
				{
					;
					a = _getch();
					continue;
				}
				if (x == '\110')
				{
					if (b == 1)
						;
					else
					{
						b = b - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\113')
				{
					if (c == 1)
						;
					else
					{
						c = c - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\120')
				{
					if (b == 17)
						;
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\115')
				{
					if (c == 69)
						;
					else
					{
						c = c + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
			if (Z == 2)
			{
				if (x != '\110' && x != '\120' && x != '\113' && x != '\115')
				{
					;
					a = _getch();
					continue;
				}
				if (x == '\110')
				{
					if (b == 1)
					{
						b = 17;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\113')
				{
					if (c == 1)
					{
						c = 69;
						gotoxy(hout, c, b);
					}
					else
					{
						c = c - 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\120')
				{
					if (b == 17)
					{
						b = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						b = b + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
				if (x == '\115')
				{
					if (c == 69)
					{
						c = 1;
						gotoxy(hout, c, b);
					}
					else
					{
						c = c + 1;
						gotoxy(hout, c, b);
					}
					a = _getch();
					continue;
				}
			}
		}
		else
		{
			;
			a = _getch();
			continue;
		}
	}
	if (a == 'q' || a == 'Q')
	{
		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س������ز˵�." << endl;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);                //ȡ��׼����豸��Ӧ�ľ��
	srand((unsigned int)(time(0)));                                     /* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	int x = menu();
	while (x != 48)
	{
		if (x == 48)
			break;
		else if (x == 49)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 1, 0);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 50)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 2, 0);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 51)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, 35, 9, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 52)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, 35, 9, 2);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 53)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 1, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else if (x == 54)
		{
			cls(hout);
			init_border(hout);                                                    /* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			move_by_ijkl(hout, 35, 9, 2, 1);
			while (_getch() != '\r')
				;
			cls(hout);
			x = menu();
			continue;
		}
		else
			x = _getch();
	}
	cout << endl;
	return 0;
}
