/* ѧ�� ���� �༶ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
using namespace std;

#include "../include/cmd_hdc_tools.h"
#include "hdc_student_works.h"

enum TEST_ITEM {
	T_MIN = 0,
	T_POINT = 0,
	T_LINE,
	T_TRIANGLE,
	T_RECTANGLE,
	T_SQUARE,
	T_ARC,
	T_SECTOR,
	T_CIRCLE,
	T_ELLIPSE,
	T_PEPPAPIG,
	T_MATHCURVE,
	T_CUSTOM,
	T_MAX
};

static char need_enter = '1';   //������ȫ��������1��ʾ�س���������0��ʾ�Զ�����

/***************************************************************************
  �������ƣ�
  ��    �ܣ�ѡ��Ҫ���Ե���Ŀ
  ���������
  �� �� ֵ��
  ˵    ������ӡʱÿ2�ֽ�һ�飬��ʾ����ȫ���ģ��������
***************************************************************************/
int select_test_item(char test_choice[])
{
	struct {
		enum TEST_ITEM no;
		const char* prompt;
		int len;
	} item[] = {
		{T_POINT,     "��"},
		{T_LINE,      "��"},
		{T_TRIANGLE,  "������"},
		{T_RECTANGLE, "����"},
		{T_SQUARE,    "������"},
		{T_ARC,       "��"},
		{T_SECTOR,    "����"},
		{T_CIRCLE,    "Բ"},
		{T_ELLIPSE,   "��Բ"},
		{T_PEPPAPIG,  "С������"},
		{T_MATHCURVE, "�Զ�������"},
		{T_CUSTOM,    "����"},
		{T_MAX,       NULL}
	};

	int i, max_len = 0;

	/* ��������ʾ�ַ�������󳤶� */
	for (i = 0; item[i].prompt; i++) {
		item[i].len = strlen(item[i].prompt);
		if (max_len < item[i].len)
			max_len = item[i].len;
	}

	int line, pos;
	cout << endl << endl;
	cout << "��ÿ����Ŀ������0/1(c��������)" << endl;
	cout << setw(T_MAX * 3) << setfill('-') << "-" << endl;
	for (line = 0; line < max_len / 2; line++) {
		for (i = T_MIN; i < T_MAX; i++) {
			/* ��line����Ҫ��ӡ item[i].prompt[item[i].len + i*2 - max_len]��ʼ�������ַ������������ӡ�����ո�*/
			pos = item[i].len + line * 2;
			if (pos < max_len)
				cout << "   ";
			else {
				cout << item[i].prompt[pos - max_len] << item[i].prompt[pos - max_len + 1] << ' ';
			}
		}//end of for i
		cout << endl;
	}//end of for line
	cout << setw(T_MAX * 3) << setfill('-') << "-" << endl;

	for (i = T_MIN; i < T_MAX; i++) {
		while (1) {
			test_choice[i] = _getch();
			if (test_choice[i] == '0' || test_choice[i] == '1') {
				putchar(test_choice[i]);
				putchar(' '); //Ϊ�˺�������룬���ӡ�����ո�
				putchar(' ');
				break;
			}
			else if (test_choice[i] == 'c' || test_choice[i] == 'C') { //����c��ȫ������
				return -1;
			}
		}
	}
	Sleep(300); //ͣ��һ�£�Ϊ�˿�������һ��1
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void to_be_continued(const char* prompt, const int X = 0, const int Y = 22)
{
	//�����һ�пո�Ϊ������ϴ��ַ����ȱ��γ���������ĺ�������
	cct_gotoxy(X, Y);
	cout << "                                                                                          " << endl;

	//�ָ�ȱʡ�ڰ�
	cct_setcolor();

	cct_gotoxy(X, Y);
	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	if (need_enter == '1') {
		/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
		while (_getch() != '\r')
			;
	}

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	const int   win_width = 800, win_high = 800;	//�趨��Ļ���
	const int   win_bgcolor = COLOR_WHITE, win_fgcolor = COLOR_HRED;
	const int   color[] = { 0x00FF0000, 0x0000FF00, 0x000000FF }; //R G B
	const int   STL_X = 0, STL_Y = win_high / 16 - 5;	//״̬�е���ʼ����
	const char* fill_str[] = { "����", "ʵ��" };

	char test_choise[1024] = "111111111111";
	char tmp[80];
	int i, round;
	int delay_ms = 0; //��ʼΪ����ʱ

#if 1
	cout << "��ѡ���Զ���ʾ(0)���ǵ�����ʾ(1) : ";
	while (1) {
		need_enter = _getch();
		if (need_enter == '0' || need_enter == '1') {
			putchar(need_enter);
			break;
		}
	}
	while (select_test_item(test_choise) != 0)
		;

	if (need_enter == '1') {
		cout << endl << endl << "��������ʱ(>=0��ms) : ";
		cin >> delay_ms; //δ�ж��������
	}
#endif

	long t_end, t_start = GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ���룬����55ms

	srand((unsigned int)time(0));

	hdc_init(win_bgcolor, win_fgcolor, win_width, win_high);		//��(����ɫ��ǰ��ɫ����ȣ��߶ȣ���ʼ������

	/* ������ʱʱ����ʱ��0��ʾ����ʱ����λms */
	hdc_set_delay(delay_ms);

	//���㺯������
	if (test_choise[T_POINT] == '1') {
		/* ����һ�����ֱ���������ʾ */
		hdc_set_delay(0); //�˴������ʱ�Ļ���̫����
		hdc_point(300, 200, 100, RGB(rand() % 255, rand() % 255, rand() % 255));
		hdc_point(300, 350, 150, RGB(rand() % 255, rand() % 255, rand() % 255));
		hdc_point(300, 550, 200, RGB(rand() % 255, rand() % 255, rand() % 255));
		to_be_continued("���Ǽ������ֶ�����δ��ȫ���ĵ�", STL_X, STL_Y);

		hdc_set_delay(delay_ms);

		/* 50����ϸΪ3�ĵ� */
		hdc_set_pencolor(255, 0, 0);//��
		for (i = 0; i < 50; i++)
			hdc_point(100 + i * 10, 100, 3);

		/* 50����ϸΪ5�ĵ� */
		for (i = 0; i < 50; i++)
			hdc_point(100, 150 + 10 * i, 5, RGB(0, 255, 0)); //��

		/* 20����ϸΪ10�ĵ� */
		for (i = 0; i < 20; i++)
			hdc_point(120 + 25 * i, 120 + 25 * i, 10, RGB(0, 0, 255)); //��

		to_be_continued("���������������", STL_X, STL_Y);

		//�����ʾ100���׵�
		for (i = 0; i < 100; i++) {
			int x, y;

			x = rand() % win_width;
			y = rand() % win_high;
			/* ��Ĵ�С1~20����ɫ��� */
			hdc_point(x, y, 1 + rand() % 20, RGB(rand() % 255, rand() % 255, rand() % 255)); //��Ĵ�ϸ1-10
			Sleep(1);
		}
		to_be_continued("����������", STL_X, STL_Y);
	}

	//���ߺ�������
	if (test_choise[T_LINE] == '1') {
		hdc_cls();

		/* ����(˫��) */
		hdc_line(100, 100, 500, 100, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(500, 110, 100, 110, 3, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* ����(˫��) */
		hdc_line(100, 120, 100, 500, 5, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(110, 500, 110, 120, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 45��б��(˫��) */
		hdc_line(130, 130, 500, 500, 3, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(510, 500, 140, 130, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 45��б��(˫��) */
		hdc_line(130, 500, 500, 130, 4, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(510, 130, 140, 500, 5, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* �ӽ���ƽ����x/y���ֱ�� */
		hdc_line(150, 300, 600, 330, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(150, 350, 600, 350, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		to_be_continued("�������������ֱ��", STL_X, STL_Y);

		//�����ʾ20�������ɫ����
		for (i = 0; i < 20; i++) {
			int x1, y1, x2, y2;

			x1 = rand() % win_width;
			y1 = rand() % win_high;
			x2 = rand() % win_width;
			y2 = rand() % win_high;
			/* �ߵĴ�ϸ 1~5����ɫ��� */
			hdc_line(x1, y1, x2, y2, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
			Sleep(1);
		}
		to_be_continued("���߲������", STL_X, STL_Y);
	}

	//�������κ�������
	if (test_choise[T_TRIANGLE] == '1') {
		hdc_cls();

		//�����ʾ20��������
		for (i = 0; i < 20; i++) {
			int x1, y1, x2, y2, x3, y3;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x1 = rand() % (win_width);
			y1 = rand() % (win_high);
			x2 = rand() % (win_width);
			y2 = rand() % (win_high);
			x3 = rand() % (win_width);
			y3 = rand() % (win_high);
			hdc_triangle(x1, y1, x2, y2, x3, y3, i % 2, 2 + rand() % 5); //i%2ʹ����ʵ�Ľ���
			Sleep(500);
		}
		to_be_continued("�������β������", STL_X, STL_Y);
	}

	//�����κ�������
	if (test_choise[T_RECTANGLE] == '1') {
		hdc_cls();

		/* ���ֲ��ԣ��ȿ�����ʵ�� */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "����Ҫ��ʾ%s���Σ���ת %d ��", fill_str[round % 2], i); //����ֱ��fill_str[round]����round%2��Ϊ�˷�ֹ���
				to_be_continued(tmp, 0, 0);
				//				hdc_rectangle(350, 350, 300 - round*30, 200 - round * 20, i, round, 1+rand()%5, RGB(rand()%256, rand()%256, rand()%256));	//���ɫ(��Ŀ�̶Ȳ���Ԥ����ɫ��ת)
				hdc_rectangle(350, 350, 300 - round * 30, 200 - round * 20, i, round, 2 + rand() % 5, color[i / 15 % 3]); //Ԥ����ɫ��ת
			}

		to_be_continued("�����������������", STL_X, STL_Y);

		hdc_cls();
		//�����ʾ20������
		for (i = 0; i < 20; i++) {
			int x, y, w, h, angle;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);

			x = rand() % win_width;
			y = rand() % win_high;
			w = rand() % (win_width - x);
			h = rand() % (win_high - y) * 2 / 3;
			angle = rand() % 360;
			hdc_rectangle(x, y, w, h, angle, i % 2, 2 + rand() % 5); //i%2ʹ����ʵ�Ľ���
			Sleep(100);
		}
		to_be_continued("�����β������", STL_X, STL_Y);
	}

	//�������κ�������
	if (test_choise[T_SQUARE] == '1') {
		hdc_cls();

		/* �Ȳ��Կ��������ε���ת��Ŀ����Ϊ����֤��ת�ĵ���ȷ�� */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "����Ҫ��ʾ%s�����Σ���ת %d ��", fill_str[round % 2], i); //����ֱ��fill_str[round]����round%2��Ϊ�˷�ֹ���
				to_be_continued(tmp, 0, 0);
				//				hdc_square(350, 350, 300 - round * 30, i, round, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256)); //���ɫ(��Ŀ�̶Ȳ���Ԥ����ɫ��ת)
				hdc_square(350, 350, 300 - round * 30, i, round, 2 + rand() % 5, color[i / 15 % 3]); //Ԥ����ɫ��ת
			}

		to_be_continued("�������������������", STL_X, STL_Y);
		hdc_cls();

		//�����ʾ20��������
		for (i = 0; i < 20; i++) {
			int x, y, length;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = rand() % (win_width / 2);
			y = rand() % (win_high / 2);
			length = rand() % (win_width / 4 * 3);
			hdc_square(x, y, length, rand() % 360, i % 2, 2 + rand() % 5); //i%2ʹ����ʵ�Ľ���
			Sleep(100);
		}
		to_be_continued("�������β������", STL_X, STL_Y);
	}

	//��Բ����������
	if (test_choise[T_ARC] == '1') {
		hdc_cls();

		/* �����ṹ���ʹ��ʾ������if����Ч */
		struct {
			int angle_begin, angle_end;
		} t[] = {
		{180,900},
			{0, 60},
			{-360, 60},
			{-45, 45},
			{45, -45},
			{45, 135},
			{90, 180},
			{90, 270},
			{225, 360},
			{300, 90},
			{0, 360},	//��Բ
			{0, 0},		//��Բ	
			{540, 180},	//��Բ
			{180, 181},	//һ��
			{181, 180},	//��Բ��һ��
			{-1, -1},
		};

		/* �Ȳ��Լ���ָ����С�ģ�Ŀ����Ϊ����֤�Ƕȼ������ȷ�� */
		for (i = 0; t[i].angle_begin != -1 && t[i].angle_end != -1; i++) {
			char tmp[80];
			sprintf(tmp, "����Ҫ��ʾԲ����%d ~ %d", t[i].angle_begin, t[i].angle_end);
			to_be_continued(tmp, 0, 0);
			//			hdc_arc(350, 350, 200+i*10, t[i].angle_begin, t[i].angle_end, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256));
			hdc_arc(350, 350, 200 + i * 10, t[i].angle_begin, t[i].angle_end, 2 + rand() % 5, color[i % 3]);
		}

		to_be_continued("�������������Բ��", STL_X, STL_Y);

		hdc_cls();
		//�����ʾ20��Բ��
		for (i = 0; i < 20; i++) {
			int x, y, r, angle_begin, angle_end;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_width / 4);
			angle_begin = rand() % 360;
			angle_end = rand() % 360;
			hdc_arc(x, y, r, angle_begin, angle_end, 2 + rand() % 5);
		}
		to_be_continued("��Բ���������", STL_X, STL_Y);
	}

	//�����κ�������
	if (test_choise[T_SECTOR] == '1') {
		hdc_cls();

		/* �����ṹ���ʹ��ʾ������if����Ч */
		struct {
			int angle_begin, angle_end;
		} t[] = {
			{0, 135},	//��Բ���ڵ�����
			{45, 135},
			{225, 360},
			{-45, 45},
			{90, 180},
			{90, 270},
			{300, 90},
			{180, 181},	//һ��
			{45, -45},	//������Բ������
			{225, 135},
			{135, 45},
			{-45, 225},
			{186, 185},	//��Բ��һ��
			{0, 360},	//��Բ
			{0, 0},		//��Բ	
			{540, 180},	//��Բ
			{-1, -1},
		};

		/* �Ȳ��Լ���ָ����С�ģ�Ŀ����Ϊ����֤�Ƕȼ������ȷ�� */
		for (round = 0; round <= 1; round++)
			for (i = 0; t[i].angle_begin != -1 && t[i].angle_end != -1; i++) {
				sprintf(tmp, "����Ҫ��ʾ%s���Σ�%d ~ %d", fill_str[round % 2], t[i].angle_begin, t[i].angle_end); //����ֱ��fill_str[round]����round%2��Ϊ�˷�ֹ���
				to_be_continued(tmp, 0, 0);

				//				hdc_sector(350, 350, 200 - round * 20 + i * 10, t[i].angle_begin, t[i].angle_end, round, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256)); //���ɫ(��Ŀ�̶Ȳ���Ԥ����ɫ��ת)
				hdc_sector(350, 350, 200 - round * 20 + i * 10, t[i].angle_begin, t[i].angle_end, round, 2 + rand() % 5, color[i % 3]);	//Ԥ����ɫ�ֻ�
			}

		to_be_continued("�����������������", STL_X, STL_Y);

		hdc_cls();

		//�������ʾ20������
		for (i = 0; i < 20; i++) {
			int x, y, r, angle_begin, angle_end;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_width / 4);
			angle_begin = rand() % 360;
			angle_end = rand() % 360;
			hdc_sector(x, y, r, angle_begin, angle_end, i % 2, 1 + rand() % 5);//i%2ʹ����ʵ�Ľ���
		}
		to_be_continued("�����β������", STL_X, STL_Y);

		/* �Ը����Ӱ� */
		for (i = 0; i < 20; i++) {
			const int c = 0x000000FF; //��
			//����
			hdc_sector(100 + i * 20, 500, 10, 135, 45, 1, 2, c);//i%2ʹ����ʵ�Ľ���
			Sleep(200);
			//����
			hdc_sector(100 + i * 20, 500, 10, 90, 450, 1, 2, c);//i%2ʹ����ʵ�Ľ���
			Sleep(100);
			//��ʧ
			hdc_sector(100 + i * 20, 500, 10, 90, 450, 1, 2, 0x00CCCCCC);
			Sleep(100);
		}
		to_be_continued("�Զ��Ӳ������", STL_X, STL_Y);
	}

	//��Բ��������
	if (test_choise[T_CIRCLE] == '1') {
		hdc_cls();

		//�����ʾ20��Բ
		for (i = 0; i < 20; i++) {
			int x, y, r;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_high / 4);
			hdc_circle(x, y, r, i % 2, 2 + rand() % 5); //i%2ʹ����ʵ�Ľ���
		}
		to_be_continued("��Բ�������", STL_X, STL_Y);
	}

	//��Բ��������
	if (test_choise[T_ELLIPSE] == '1') {
		hdc_cls();

		/* �Ȳ�����Բ����ת��Ŀ����Ϊ����֤��ת�ĵ���ȷ�� */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "����Ҫ��ʾ%s��Բ����ת %d ��", fill_str[round % 2], i); //����ֱ��fill_str[round]����round%2��Ϊ�˷�ֹ���
				to_be_continued(tmp, 0, 0);
				hdc_ellipse(350, 350, 300 - round * 20, 200 - round * 20, i, round, 2 + rand() % 5, color[i / 15 % 3]);	//Ԥ����ɫ�ֻ�
			}

		to_be_continued("���������������Բ", STL_X, STL_Y);

		hdc_cls();
		//�����ʾ20����Բ
		for (i = 0; i < 20; i++) {
			int x, y, a, b, angle;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = win_width / 4 + rand() % (win_width / 2);
			y = win_high / 4 + rand() % (win_high / 2);
			a = win_width / 10 + rand() % (win_width / 4);
			b = win_high / 40 + rand() % (win_high / 4);
			angle = rand() % 360;
			hdc_ellipse(x, y, a, b, angle, i % 2, 2 + rand() % 5);	//Ԥ����ɫ�ֻ�
			Sleep(100);
		}
		to_be_continued("����Բ�������", STL_X, STL_Y);

		/* ���仨�� */
		hdc_cls();
		for (i = 0; i < 360; i += 7) //����Ϊ��������360����
			hdc_ellipse(350, 350, 300, 100, i, 0, 1, RGB(rand() % 255, rand() % 255, rand() % 255));	//Ԥ����ɫ�ֻ�

		to_be_continued("�������", STL_X, STL_Y);
	}

	if (test_choise[T_PEPPAPIG] == '1') {
		hdc_cls();

		/* ��С������ */
		int hdc_draw_PeppaPig(const int left_shoes_x, const int left_shoes_y); //��������

		hdc_draw_PeppaPig(300, 500); //���Ь�ӵ����Ͻ�Ϊ��׼����
	}

	if (test_choise[T_MATHCURVE] == '1') {
		/* ��һ����ѧ���� */
		hdc_draw_Mathematical_curve_1851746();
		to_be_continued("��ѧ����-��ǧ��ѧ��-���", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1953977();
		to_be_continued("��ѧ����-������ѧ��-���", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1854082();
		to_be_continued("��ѧ����-��ѧ��-���", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1952033();
		to_be_continued("��ѧ����-���ūhѧ��-���", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1952640();
		to_be_continued("��ѧ����-������ѧ��-���", STL_X, STL_Y);

		/* �ڴ�����Լ�����ѧ���ߣ��������ݿ���ѡ�����������׵����ߣ��������� */

	}

	if (test_choise[T_CUSTOM] == '1') {
		/* ��һ����ͨ����������ݿ���ѡ
		   ����ӷ�������Ѷȼ�չ��Ч������һ����ֵ�Ķ���ӷ� */
		hdc_draw_catoon_1851746(5, 15);
		to_be_continued("01��Ⱥͷ��-��ǧ��ѧ��-���", STL_X, STL_Y);

		hdc_draw_catoon_1953977(400, 400);
		to_be_continued("02��Ⱥͷ��-������ѧ��-���", STL_X, STL_Y);

		hdc_draw_catoon_1854082(400, 415);
		to_be_continued("03��Ⱥͷ��-��ѧ��-���", STL_X, STL_Y);

		hdc_draw_catoon_1952033(350, 270);
		to_be_continued("04��Ⱥͷ��-���ūhѧ��-���", STL_X, STL_Y);

		hdc_draw_catoon_1952640(350, 270);
		to_be_continued("05��Ⱥͷ��-������ѧ��-���", STL_X, STL_Y);

		/* �ڴ�����Լ��Ŀ�ͨͼ���������ݿ���ѡ������ӷ��� */

	}

	hdc_release();
	cct_gotoxy(STL_X, STL_Y - 2);

	cct_setcolor();//�ָ�ȱʡ�ڰ�
	t_end = GetTickCount();   //ȡ��ǰϵͳʱ��
	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
	system("pause");

	return 0;
}
