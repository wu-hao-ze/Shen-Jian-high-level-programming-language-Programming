/* 1953729 ��09 ����� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 ������ų���
				 ����const�ͱ���
		������ ������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���������ӡ������
	 ���������order - 0 ������������
			   order - 1 ������������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
	void low1(char );
	void up1(char );
	void low2(char, char);
	void up2(char, char);
	if (order == 1)
	{
		const int k = start_ch - 'A';
		if (end_ch == start_ch)
		{
			if (start_ch == 'A')
				cout << end_ch;
			else
				cout << setfill(' ') << setw(k) << ' ' << end_ch;
			cout << endl;
		}
		else
		{
			if (k != 0)
				cout << setfill(' ') << setw(k) << ' ';
			up2(start_ch, end_ch);
			low2(start_ch, end_ch);
			cout << endl;
			print_tower((char)start_ch + 1, end_ch, 1);
		}
	}
	else
	{
		if (end_ch == start_ch)
		{
			if (order == 0)
				cout << 'A';
			else
				cout << setfill(' ') << setw(((order + 2) / 2) - 1) << ' ' << start_ch;
			cout << endl;
		}
		else
		{	
			print_tower(start_ch, (char)(end_ch - 1), order=order+2);
			if ((order - 2) != 0)
				cout << setfill(' ') << setw((order / 2) - 1) << ' ';
			low1(end_ch);
			up1(end_ch);
			cout << endl;
		}
	
	}
	
}

void low1(char x)
{
	if (x == 'A')
		cout << 'A';
	else
	{
		cout << x;
		low1(x - 1);
	}
}
void up1(char x)
{
	if (x == 'A')
		;
	else
	{
		up1(x - 1);
		cout << x;
	}
}
void low2(char x,char y)
{
	if (x == y)
		cout << y;
	else
	{
		low2(x + 1, y);
		cout << x;
	}
}
void up2(char x,char y)
{
	if (x == y)
		;
	else
	{
		cout << x;
		up2(x + 1,y);
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}