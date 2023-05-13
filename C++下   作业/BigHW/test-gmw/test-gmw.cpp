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
#include "../include/cmd_console_tools.h"
#include "../include/cmd_gmw_tools.h"
using namespace std;

/* -----------------------------

    ע�⣺����(ENABLE_LIB_TGMW_TOOLS)����򿪣���1��
					��Դ�ļ������в��������е� gmw_* ϵ�к���������ʹ�� lib_tgmw_tools.lib ����ʵ�ֵ� tgmw_* ϵ�к���������ʦ��������ʵ�ֺ������ο���
          ����(ENABLE_LIB_TGMW_TOOLS)����رգ���0��
					��Դ�ļ������в��������е� gmw_* ϵ�к���������ʹ�� cmd_gmw_tools.cpp ����ʵ�ֵ� gmw_* ϵ�к�����ĿǰΪ�գ���Ҫ�Լ�ʵ�֣�

          ͨ��������л������������ڲο�demo���Լ�ʵ��֮�����л�

	������ɲ�����ҵʱ��һ��Ҫ�������£�
		1������(ENABLE_LIB_TGMW_TOOLS)������0
		2����test-gmw��Ŀ���Ƴ� lib_tgmw_tools.h �� lib_tgmw_tools.lib
		3���Ӷ�Ӧ�� include Ŀ¼��ɾ�� lib_tgmw_tools.h
		4���Ӷ�Ӧ�� lib Ŀ¼��ɾ�� lib_tgmw_tools.lib

----------------------------------------------------------------------------------------------------------------------------------------------------------- */
#define ENABLE_LIB_TGMW_TOOLS			 1

#if ENABLE_LIB_TGMW_TOOLS
#include "../include/lib_tgmw_tools.h"
#define gmw_set_rowcol tgmw_set_rowcol
#define gmw_set_color tgmw_set_color
#define gmw_set_font tgmw_set_font
#define gmw_set_delay tgmw_set_delay
#define gmw_set_ext_rowcol tgmw_set_ext_rowcol

#define gmw_set_frame_default_linetype tgmw_set_frame_default_linetype
#define gmw_set_frame_linetype tgmw_set_frame_linetype
#define gmw_set_frame_style tgmw_set_frame_style
#define gmw_set_frame_color tgmw_set_frame_color

#define gmw_set_block_default_linetype tgmw_set_block_default_linetype
#define gmw_set_block_linetype tgmw_set_block_linetype
#define gmw_set_block_border_switch tgmw_set_block_border_switch

#define gmw_set_status_line_switch tgmw_set_status_line_switch
#define gmw_set_status_line_color tgmw_set_status_line_color

#define gmw_set_rowno_switch tgmw_set_rowno_switch
#define gmw_set_colno_switch tgmw_set_colno_switch

#define gmw_init tgmw_init
#define gmw_print tgmw_print

#define gmw_draw_frame tgmw_draw_frame
#define gmw_status_line tgmw_status_line
#define gmw_draw_block tgmw_draw_block
#define gmw_move_block tgmw_move_block
#define gmw_read_keyboard_and_mouse tgmw_read_keyboard_and_mouse
#endif

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ������������Ϣ
  ���������
  �� �� ֵ��
  ˵    �������� CONSOLE_GRAPHICS_INFO �ṹ����λ����״̬��(x,y)��(0,y+2)λ��
***************************************************************************/
static void to_be_continued(const char *prompt, const CONSOLE_GRAPHICS_INFO *const bgi)
{
	if (bgi->inited == CGI_INITED) { //��ʼ����
		cct_setcolor(bgi->area_bgcolor, bgi->area_fgcolor); //�ָ���ʼ��ɫ

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//����赽ָ��λ��
		cout << setw(bgi->cols - 1) << ' '; //���ÿո��������

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//����赽ָ��λ��
	}
	else { //δ��ʼ����
		cct_setcolor(); //ȱʡ��ɫ
		cct_gotoxy(0, 0);//����赽ָ��λ��
	}

	if (prompt)
		cout << prompt << "�����س�������...   ";
	else
		cout << "���س�������...   ";

	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ������������Ϣ
  ���������
  �� �� ֵ��
  ˵    �������� CONSOLE_GRAPHICS_INFO �ṹ����λ����״̬��(x,y)��(0,y+2)λ��
***************************************************************************/
static void to_be_continued(const char *game_name, const char *prompt, const CONSOLE_GRAPHICS_INFO *const bgi)
{
	if (bgi->inited == CGI_INITED) { //��ʼ����
		cct_setcolor(bgi->area_bgcolor, bgi->area_fgcolor); //�ָ���ʼ��ɫ

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//����赽ָ��λ��
		cout << setw(bgi->cols - 1) << ' '; //���ÿո��������

		cct_gotoxy(0, bgi->SLI.lower_start_y + 2);//����赽ָ��λ��
		cout << game_name << '-' << (bgi->CFI.separator ? "��" : "��") << "�ָ���-" << prompt << "�����س�������...";
	}
	else {
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		cct_gotoxy(0, 0);//����赽ָ��λ��
		cout << game_name << '-' << prompt << "�����س�������...   ";
	}

	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_by_fixed(void)
{
	CONSOLE_GRAPHICS_INFO MyCGI; //����һ��CGI����
	char temp[256];

	/* ������ʼ�����������������ڴ˻����������޸Ĳ������ã��������Ԥ��ֵ
		��Ϸ��������ܣ�Ϊ10*10�����ָ��ߣ�ÿ��ɫ��Ĵ�СΪ2��*1�У�ɫ�鲻���߿�
		���ڱ���ɫ�ڣ�ǰ��ɫ��
		����Ϊ����8*16
		���߿�ɫ��ʱ����ʱ��ɫ���ƶ�ʱ��ʱ3ms
		�������Ҹ�������ȫ��Ϊ0
		��״̬�����������ı���ɫͬ���ڣ���Ŀ�ı�����ͬ���ڣ�ǰ��Ϊ����
		��״̬�����������ı���ɫͬ���ڣ���Ŀ�ı�����ͬ���ڣ�ǰ��Ϊ����
		����ʾ�к�
		����ʾ�б�
		��Ϸ����Ϊ˫�߿򣬴��ָ��ߣ�ɫ���СΪ2�����2��=1�����֣�*1���߶�1�У�����ɫͬ����
		ɫ��Ϊ˫���ߣ���ɫ��δ�꣩		*/
	gmw_init(&MyCGI);

	if (1) {
		/* ��ʾ��ʼ���Ŀ�� */
		gmw_draw_frame(&MyCGI);

		/* ��״̬����ʾ���� */
		sprintf(temp, "����1 - ���ڴ�С��%d�� %d��", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* ��״̬����ʾ���� */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "����End����", "���ؽ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

		to_be_continued("����1���", &MyCGI);
	}

	if (1) {
		/* Ϊ�˼򻯣������������ȷ�ԣ����б�֤ */
		cct_cls();
		int sel;
		cout << "����2�ȽϺ�ʱ���Ƿ����[0/1] : ";
		cin >> sel;
		if (sel == 1) {
		const int row = 6, col = 7;
		/* �ڳ�ʼ����ܵĻ������޸ģ�
			��Ϸ�����С
			��������
			������ɫ
			�����ֺ�
			ÿ����Ϸ��Ĵ�С
			��ʾ�к�
			��ʾ�б�
			������ʱ	*/
		gmw_set_rowcol(&MyCGI, row, col);					//��Ϸ����6*7
		gmw_set_ext_rowcol(&MyCGI, 3, 4, 10, 20);				//���ö�������
		gmw_set_color(&MyCGI, COLOR_BLUE, COLOR_HGREEN);		//�޸Ĵ�����ɫ�������޸���Ϸ��������״̬��
		gmw_set_font(&MyCGI, "������", 16, 0);				//TrueType���壨�����壩��Ȳ���Ҫ������������
		gmw_set_frame_style(&MyCGI, 6, 3, true);				//ÿ��ɫ��������6��*�߶�3�У�Ҫ�ָ���
		gmw_set_frame_default_linetype(&MyCGI, 2);			//���ÿ������ΪԤ��ֵ2��ȫ��Ϊ���ߣ�
		gmw_set_rowno_switch(&MyCGI, true);					//��ʾ�к�
		gmw_set_colno_switch(&MyCGI, true);					//��ʾ�б�
			gmw_set_delay(&MyCGI, DELAY_OF_DRAW_FRAME, 200);		//���߿����ʱ
		gmw_set_block_border_switch(&MyCGI, true);			//����ɫ����ҪС�߿�

		/* ��ʾ��� */
		gmw_draw_frame(&MyCGI);

		/* ��״̬����ʾ���� */
		sprintf(temp, "����2 - ���ڴ�С��%d�� %d��", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* ���������ɫ�� */
		{
			const BLOCK_DISPLAY_INFO bdi[] = {
				{BDI_VALUE_BLANK, -1, -1, "  "},						//0����ʾ���ÿո���伴��
				{1,  COLOR_HBLACK, -1, "��"},				//�����������1������ʾ������
				{2,  COLOR_HBLUE, COLOR_HYELLOW, "��"},	//�����������2������ʾ˫�߿�����
				{3,  COLOR_HCYAN, COLOR_GREEN, "��"},		//�����������3������ʾ��
				{4,  COLOR_HRED, -1, NULL},				//�����������4����ֱ����ʾ4��NULL��ʾֱ����ʾ���֣�
				{BDI_VALUE_END, -1, -1, NULL}			//��BDI_VALUE_END������һ��Ҫ��!!!
			};
				gmw_set_delay(&MyCGI, DELAY_OF_DRAW_BLOCK, 200);		//��ɫ�����ʱ
			int i, j;
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
						gmw_draw_block(&MyCGI, i, j, (i*row + j) % 5, bdi);
		}

		/* ��״̬����ʾ���� */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "����Quit����", "��ʾ������"); //ֻ�Ǹ�����ʾ���ѣ�������������Quit����������Ҫ�����뼰�ж�

		to_be_continued("����2���", &MyCGI);
		}
	}

	if (1) {
		/* ����������ϼ����޸ģ�
			��Ϸ�����С
			�����ֺ�
			������ɫ
			ÿ����Ϸ��Ĵ�С
			����ʾ�к�
			��ʾ�б�
			�ر���״̬��
			��ʱΪ0	*/
		gmw_set_rowcol(&MyCGI, 9, 12);								//��Ϸ����9*12
		gmw_set_font(&MyCGI, "������", 20, 0);						//TrueType���壨�����壩��Ȳ���Ҫ������������
		gmw_set_color(&MyCGI);										//�ָ�ȱʡɫ������
		gmw_set_frame_style(&MyCGI, 4, 2, true);						//ÿ��ɫ��������4��*�߶�2�У�Ҫ�ָ���
		gmw_set_rowno_switch(&MyCGI, false);							//����ʾ�к�
		gmw_set_colno_switch(&MyCGI, true);							//��ʾ�б�
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE, false);	//�ر���״̬��
		gmw_set_delay(&MyCGI, DELAY_OF_DRAW_FRAME, 0);				//��Ҫ��ʱ
//		gmw_set_frame_linetype(&MyCGI, "�X", "�^", "�[", "�a", "�T", "�U", "�j", "�m", "�d", "�g", "�p");		//д������ֻ��Ϊ�˶�����������ò���
		gmw_set_frame_linetype(&MyCGI, "��", "��", "��", "ϵ", "�T", "�U", "��", "��", "��", "��", "��");	//�Զ�����Ԫ��
		gmw_set_block_border_switch(&MyCGI);							//����ɫ�鲻��ҪС�߿�

		/* ��ʾ��� */
		gmw_draw_frame(&MyCGI);

		/* ��״̬����ʾ���� */
		sprintf(temp, "����3 - ���ڴ�С��%d�� %d��", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* ��״̬����ʾ���� */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "����Quit����", "��ʾ������"); //ֻ�Ǹ�����ʾ���ѣ�������������Quit����������Ҫ�����뼰�ж�

		to_be_continued("����3���", &MyCGI);
	}

	if (1) {
		/* ����������ϼ����޸ģ�
			��Ϸ�����С���صس������к��б�����ɱ�ʾ��Χ���۲�����Ƿ���*��**��
			�������о�Ϊ0
			�����ֺ�
			������ɫ
			ÿ����Ϸ��Ĵ�С
			����ʾ�к�
			��ʾ�б�
			������״̬��
			�ر���״̬��		*/
		gmw_set_rowcol(&MyCGI, 55, 102);							//��Ϸ����55*102���صز����к��б��ӡ�Ƿ���ȷ
		gmw_set_ext_rowcol(&MyCGI, 0, 0, 0, 0);					//���ö�������
		gmw_set_font(&MyCGI, "������", 12, 0);					//TrueType���壨�����壩��Ȳ���Ҫ������������
		gmw_set_color(&MyCGI, COLOR_CYAN, COLOR_HWHITE);			//�޸Ĵ�����ɫ(�������޸���Ϸ��������״̬����
		gmw_set_frame_style(&MyCGI, 2, 1, false);					//ÿ��ɫ��������2��*�߶�1�У���Ҫ�ָ���
		gmw_set_rowno_switch(&MyCGI, true);						//�����к���ʾ
		gmw_set_colno_switch(&MyCGI, true);						//�����б���ʾ
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE);		//������״̬��
		gmw_set_status_line_color(&MyCGI, TOP_STATUS_LINE, COLOR_HYELLOW, COLOR_BLUE, COLOR_HRED, COLOR_BLUE);		//������״̬����ɫ
		gmw_set_status_line_switch(&MyCGI, LOWER_STATUS_LINE);	//������״̬��
		gmw_set_status_line_color(&MyCGI, LOWER_STATUS_LINE, COLOR_HYELLOW, COLOR_HGREEN, COLOR_HRED, COLOR_HGREEN);		//������״̬����ɫ

		/* ��ʾ��� */
		gmw_draw_frame(&MyCGI);

		/* ��״̬����ʾ���� */
		sprintf(temp, "����4 - ���ڴ�С��%d�� %d��", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* ��״̬����ʾ����(���п�����) */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "����Q����", "��ʾ������"); //ֻ�Ǹ�����ʾ���ѣ�������������Q����������Ҫ�����뼰�ж�

		to_be_continued("����4���", &MyCGI);
	}

	if (1) {
		/* ����������ϼ����޸ģ�
			��Ϸ�����С
			���Ҷ����о�Ϊ3
			������ɫ
			�����ֺ�
			����ʾ�к�
			��ʾ�б�
			������״̬��
			�ر���״̬��		*/
		gmw_set_rowcol(&MyCGI, 5, 5);								//��Ϸ����5*5
		gmw_set_ext_rowcol(&MyCGI, 0, 0, 3, 3);						//���ö�������
		gmw_set_color(&MyCGI, COLOR_CYAN, COLOR_HPINK);				//�����޸���ɫ����ʾ����״̬����ɫ���䣩
		gmw_set_font(&MyCGI, "������", 24, 0);						//TrueType���壨�����壩��Ȳ���Ҫ������������
		gmw_set_frame_style(&MyCGI, 3, 2, false);						//ÿ��ɫ��������3��*�߶�2�У���Ҫ�ָ��ߣ�3���Ϊ4��
		gmw_set_frame_default_linetype(&MyCGI, 1);					//���Ԫ�ػָ�Ϊ˫��
		gmw_set_colno_switch(&MyCGI);								//�����б���ʾ
		gmw_set_status_line_switch(&MyCGI, TOP_STATUS_LINE, false);	//�ر���״̬��
		gmw_set_status_line_color(&MyCGI, TOP_STATUS_LINE);			//������״̬����ɫΪȱʡ(��Ȼ����ʾ)
		gmw_set_status_line_switch(&MyCGI, LOWER_STATUS_LINE);		//������״̬��
		gmw_set_status_line_color(&MyCGI, LOWER_STATUS_LINE);		//������״̬����ɫΪȱʡ

		/* ��ʾ��� */
		gmw_draw_frame(&MyCGI);

		/* ��״̬����ʾ���� */
		sprintf(temp, "����5 - ���ڴ�С��%d�� %d��", MyCGI.lines, MyCGI.cols);
		gmw_status_line(&MyCGI, TOP_STATUS_LINE, temp);

		/* ��״̬����ʾ����(�ر���ʾ��������ʾ���ܻ��ң�Ҫ������������ѣ����ⲻ�ڴ����ϣ� */
		gmw_status_line(&MyCGI, LOWER_STATUS_LINE, "����Hello����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������Hello����������Ҫ�����뼰�ж�

		to_be_continued("����5���", &MyCGI);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_by_input(void)
{
	/* �ָ���ʼ��ɫ������ */
	cct_setfontsize("��������", 16, 8);
	cct_setcolor();
	cct_setconsoleborder(120, 35);
	cct_cls();

	/* Ϊ�˼򻯣������������ȷ�ԣ����б�֤ */
	int sel;
	cout << "�Ƿ������ѡ����[0/1] : ";
	cin >> sel;
	if (sel != 1)
		return;

	CONSOLE_GRAPHICS_INFO TestCGI; //����һ��CGI����(Ҳ������)
	char temp[256];

	/* ��ʼ������Ϊ��������뺭�ǵ���ȫ��ֵ�����Բ�Ҫ�� */
	gmw_init(&TestCGI);

	/* ����Ϊ�˼򻯣��������������ȷ�ԣ����б�֤ */
	if (1) {
		int row, col;
		cout << "������Ϸɫ�������[1..55] : ";
		cin >> row;
		cout << "������Ϸɫ�������[1..102] : ";
		cin >> col;
		gmw_set_rowcol(&TestCGI, row, col);	//���row,col��ֵ���󣬱������޷ָ��ߣ�����cmd���ڻ���
	}

	if (1) {
		int ext_up_line, ext_down_line, ext_left_cols, ext_right_cols;
		cout << "������Ϸ������ϲ�Ԥ������[0..10] : ";
		cin >> ext_up_line;
		cout << "������Ϸ������²�Ԥ������[0..10] : ";
		cin >> ext_down_line;
		cout << "������Ϸ��������Ԥ������[0..20] : ";
		cin >> ext_left_cols;
		cout << "������Ϸ������ұ�Ԥ������[0..20] : ";
		cin >> ext_right_cols;
		gmw_set_ext_rowcol(&TestCGI, ext_up_line, ext_down_line, ext_left_cols, ext_right_cols);
	}

	if (1) {
		int bg_color, fg_color;
		cout << "���봰�ڱ���ɫ[0..15] : ";
		cin >> bg_color;
		cout << "���봰��ǰ��ɫ[0..15] : ";
		cin >> fg_color;
		gmw_set_color(&TestCGI, bg_color, fg_color);
	}

	if (1) {
		int font_num, font_high, font_width;
		cout << "��������[0:���� 1:������] : ";
		cin >> font_num;
		cout << "��������߶�[1..36] : ";
		cin >> font_high;
		cout << "����������[1..36] : ";
		cin >> font_width;
		if (font_num == 1)
			gmw_set_font(&TestCGI, "������", font_high, font_width);
		else
			gmw_set_font(&TestCGI, "Terminal", font_high, font_width);
	}

	if (1) {
		int draw_border_delay;
		cout << "���뻭�߿���ʱ[0..1000 ��λ:ms] : ";
		cin >> draw_border_delay;
		gmw_set_delay(&TestCGI, DELAY_OF_DRAW_FRAME, draw_border_delay);
	}

	if (1) {
		int top_status_line, top_normal_bgcolor, top_normal_fgcolor, top_catchy_bgcolor, top_catchy_fgcolor;
		cout << "�Ƿ���Ҫ��״̬��[0/1] : ";
		cin >> top_status_line;
		if (top_status_line) {
			cout << "������״̬�������ı�����ɫ[-1..16��-1��ʾ�ô��ڱ���ɫ] : ";
			cin >> top_normal_bgcolor;
			cout << "������״̬�������ı�ǰ��ɫ[-1..16��-1��ʾ�ô���ǰ��ɫ] : ";
			cin >> top_normal_fgcolor;
			cout << "������״̬����Ŀ�ı�����ɫ[-1..16��-1��ʾ�ô��ڱ���ɫ] : ";
			cin >> top_catchy_bgcolor;
			cout << "������״̬����Ŀ�ı�����ɫ[-1..16��-1��ʾ��ȱʡ����] : ";
			cin >> top_catchy_fgcolor;
			gmw_set_status_line_switch(&TestCGI, TOP_STATUS_LINE);
			gmw_set_status_line_color(&TestCGI, TOP_STATUS_LINE, top_normal_bgcolor, top_normal_fgcolor, top_catchy_bgcolor, top_catchy_fgcolor);
		}
		else
			gmw_set_status_line_switch(&TestCGI, TOP_STATUS_LINE, false);
	}

	if (1) {
		int lower_status_line, lower_normal_bgcolor, lower_normal_fgcolor, lower_catchy_bgcolor, lower_catchy_fgcolor;
		cout << "�Ƿ���Ҫ��״̬��[0/1] : ";
		cin >> lower_status_line;
		if (lower_status_line) {
			cout << "������״̬�������ı�����ɫ[-1..16��-1��ʾ�ô��ڱ���ɫ] : ";
			cin >> lower_normal_bgcolor;
			cout << "������״̬�������ı�ǰ��ɫ[-1..16��-1��ʾ�ô���ǰ��ɫ] : ";
			cin >> lower_normal_fgcolor;
			cout << "������״̬����Ŀ�ı�����ɫ[-1..16��-1��ʾ�ô��ڱ���ɫ] : ";
			cin >> lower_catchy_bgcolor;
			cout << "������״̬����Ŀ�ı�����ɫ[-1..16��-1��ʾ��ȱʡ����] : ";
			cin >> lower_catchy_fgcolor;
			gmw_set_status_line_switch(&TestCGI, LOWER_STATUS_LINE);
			gmw_set_status_line_color(&TestCGI, LOWER_STATUS_LINE, lower_normal_bgcolor, lower_normal_fgcolor, lower_catchy_bgcolor, lower_catchy_fgcolor);
		}
		else
			gmw_set_status_line_switch(&TestCGI, LOWER_STATUS_LINE, false);
	}

	if (1) {
		int rowno, colno;
		cout << "�����Ƿ���Ҫ�к�[0/1] : ";
		cin >> rowno;
		cout << "�����Ƿ���Ҫ�б�[0/1] : ";
		cin >> colno;
		gmw_set_rowno_switch(&TestCGI, rowno);
		gmw_set_colno_switch(&TestCGI, colno);

		int def_linetype;
		cout << "����߿�����[1-ȫ˫�� 2-ȫ���� 3-��˫���� 4-�ᵥ��˫] : ";
		cin >> def_linetype;
		gmw_set_block_default_linetype(&TestCGI, def_linetype);
	}

	if (1) {
		int width, high, separator;
		cout << "������Ϸɫ��Ŀ��[ż��2..32] : ";
		cin >> width;
		cout << "������Ϸɫ��ĸ߶�[1..10] : ";
		cin >> high;
		cout << "�����Ƿ���Ҫ�ָ���[0/1] : ";
		cin >> separator;
		gmw_set_frame_style(&TestCGI, width, high, separator);
	}

	if (1) {
		int border_bg_color, border_fg_color;
		cout << "������Ϸ������ɫ[-1..16��-1��ʾ�ô��ڱ���ɫ] : ";
		cin >> border_bg_color;
		cout << "������Ϸ��ǰ��ɫ[-1..16��-1��ʾ�ô���ǰ��ɫ] : ";
		cin >> border_fg_color;
		gmw_set_frame_color(&TestCGI, border_bg_color, border_bg_color);
	}

	/* ��ʾ��ʼ���Ŀ�� */
	gmw_draw_frame(&TestCGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "��ѡ���� - ���ڴ�С��%d�� %d��", TestCGI.lines, TestCGI.cols);
	gmw_status_line(&TestCGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(&TestCGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	to_be_continued("��ѡ�������", &TestCGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_step_of_color_linez(CONSOLE_GRAPHICS_INFO *pColorLinez_CGI)
{
	const char *gname = "ColorLinez";
	const int row = 8, col = 8;

	/* Ԥ��һ�����飬1-7��ʾ7�ֲ�ͬ��ɫ����0��ʾ�� */
	int cl[row][col] = {
		{0, 0, 0, 0, 4, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 2, 0, 0, 0, 7, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 6},
		{0, 1, 0, 0, 0, 5, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};

	/* ����1-7�������ú�����ʽ��ʾ�ڽ�����
	   - ע��1���������ý�������+ѡ�С���Ϣ����һ�������еķ���
				1-7��ʾ������11-17��ʾѡ��
			 2��ʵ��ʵ���е�����ֵ��Ҫ����ˣ��˴�������Ϊ��ɫ��Ĳ�ͬ״̬����ʾ
			  3���� test_magic_ball ����������һ�ַ�ʽ��ʾɫ��Ĳ�ͬ״̬�����Զ��� */
	const BLOCK_DISPLAY_INFO bdi[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //0����ʾ���ÿո���伴��
		{1,  COLOR_HBLACK, -1, "��"},	//����״̬����1����Ӧ�Ĳ���
		{2,  COLOR_YELLOW, -1, "��"},
		{3,  COLOR_HGREEN, -1, "��"},
		{4,  COLOR_HCYAN, -1, "��"},
		{5,  COLOR_HRED, -1, "��"},
		{6,  COLOR_HPINK, -1, "��"},
		{7,  COLOR_HYELLOW, -1, "��"},
		{11, COLOR_HBLACK, -1, "��"},//ѡ��״̬����1����Ӧ�Ĳ���ͼ��
		{12, COLOR_YELLOW, -1, "��"},
		{13, COLOR_HGREEN, -1, "��"},
		{14, COLOR_HCYAN, -1, "��"},
		{15, COLOR_HRED, -1, "��"},
		{16, COLOR_HPINK, -1, "��"},
		{17, COLOR_HYELLOW, -1, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	const int BDI_NORMAL = 0, BDI_SELECTED = 10;
	char temp[256];
	int i, j;

	/* ��row/col��ֵ������Ϸ���������� */
	gmw_set_rowcol(pColorLinez_CGI, row, col);

	/* ��ʾ��� */
	gmw_draw_frame(pColorLinez_CGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pColorLinez_CGI->lines, pColorLinez_CGI->cols);
	gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	/* ���ڲ�����չ�ֵ���Ļ�� */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pColorLinez_CGI, i, j, BDI_NORMAL + cl[i][j], bdi);
		}
	to_be_continued(gname, "��ʼ�����", pColorLinez_CGI);

	/* �����/���̲����ݷ���ֵ������Ӧ�Ķ���
	   ע��1������Լ������Ҽ��˳��������ʾ<�У���>��ʵ����Ϸ�У�Ҫ���ݷ��ص����н���ĳ�ֶ������ҳ���ͬ�����ѡ��������ȣ�
           2������Լ�����س��˳���������ʾ������Ϣ��ʵ����Ϸ�У�Ҫ���ݷ��ص����н���ĳ�ֶ������ҳ���ͬ�����ѡ��������ȣ�
           3��ʵ����Ϸ��ӦдΪ���� */
	if (pColorLinez_CGI->inited == CGI_INITED) {
		gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, "���Լ���/��꣬�Ҽ�/�س��˳�");

		int loop = 1;
		int maction, old_mrow, old_mcol, mrow = -1, mcol = -1;
		int keycode1, keycode2;
		int ret;

		while (loop) {
			old_mrow = mrow;
			old_mcol = mcol;
			ret = gmw_read_keyboard_and_mouse(pColorLinez_CGI, maction, mrow, mcol, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				if (maction == MOUSE_ONLY_MOVED) {
					/* ��ʱ��mrow��mcol�϶����ղŲ�ͬ */

					/* ��һ��ɫ��仯��color_linez��������λ�ö���ɫ�飬�˴�ֱ����3���棩����ͬ��Ϸ�˴���ͬ�������Ǹ���ʾ */

					/* ԭɫ��������ʾ */
					if (old_mrow >=0 && old_mcol>=0)
						gmw_draw_block(pColorLinez_CGI, old_mrow, old_mcol, BDI_NORMAL + cl[old_mrow][old_mcol], bdi);

					/* ��ɫ�����ԣ���Ϊ��������ɫ�鶼��ֵ���˴���3����� */
					gmw_draw_block(pColorLinez_CGI, mrow, mcol, BDI_SELECTED + 3, bdi);
				}
				else if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					/* ��״̬����ʾ���� */
					gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�����Ҽ�]", NULL);
					loop = 0;
				}
				else {
					sprintf(temp, "[�������] %c��%d��", char('A' + mrow), mcol); //δ����mrow����26��mcol����99�������������Ҫ�������д���
					gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, temp);
					loop = 0;
				}
			}
			else { //CCT_KEYBOARD_EVENT - ������뺬��ȥ�� cmd_console_tools.cpp
				switch (keycode1) {
					case 0x0D:
						/* ��״̬����ʾ���� */
						gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�����س���]", NULL);
						loop = 0;
						break;
					case 0xE0: //224
						switch (keycode2) {
							case KB_ARROW_UP:
								/* ��״̬����ʾ���� */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�����ϼ�ͷ]", NULL);
								break;
							case KB_ARROW_DOWN:
								/* ��״̬����ʾ���� */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�����¼�ͷ]", NULL);
								break;
							case KB_ARROW_LEFT:
								/* ��״̬����ʾ���� */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�������ͷ]", NULL);
								break;
							case KB_ARROW_RIGHT:
								/* ��״̬����ʾ���� */
								gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, "[�����Ҽ�ͷ]", NULL);
								break;
						}
						break;
					default:
						sprintf(temp, "[��������] %d/%d", keycode1, keycode2);
						gmw_status_line(pColorLinez_CGI, LOWER_STATUS_LINE, temp);
						break;
				}//end of switch
			}//end of else
		}//end of while

		/* ��״̬���ָ�ԭ����Ϣ */
		sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pColorLinez_CGI->lines, pColorLinez_CGI->cols);
		gmw_status_line(pColorLinez_CGI, TOP_STATUS_LINE, temp);

		to_be_continued(gname, "�������������", pColorLinez_CGI);
	}

	/* �����е�һ������ʾΪ��ѡ��״̬�� - ע��������ѡ��һ����ʵ����Ϸ�и������/���̶�����ȷ��ĳ���� */
	gmw_draw_block(pColorLinez_CGI, 2, 2, BDI_SELECTED + cl[2][2], bdi);
	to_be_continued(gname, "ѡ��1��", pColorLinez_CGI);

	/* �ƶ�ĳ����
	   ע��1��������ѡ��һ����ʵ����Ϸ�и������/���̶�����ȷ��ĳ����
		   2����������ѡ�˽���Ϊֹ��ʵ����Ϸ�и������/���̶�����ȷ���ƶ�����λ��
		   3��������δ�޸��ڲ������ֵ��ʵ����Ϸ�п�����Ҫ�޸� */
	gmw_set_delay(pColorLinez_CGI, DELAY_OF_BLOCK_MOVED, 200); //�����ƶ���ʱ
	gmw_move_block(pColorLinez_CGI, 2, 2, BDI_SELECTED + cl[2][2], 0, bdi, UP_TO_DOWN, 3);
	/* Ϊ�˺����ƶ������������ֵ */
	cl[2 + 3][2] = cl[2][2];
	cl[2][2] = 0;
	to_be_continued(gname, "�����ƶ�3��", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 5, 2, BDI_SELECTED + cl[5][2], 0, bdi, LEFT_TO_RIGHT, 2);
	/* Ϊ�˺����ƶ������������ֵ */
	cl[5][2 + 2] = cl[5][2];
	cl[5][2] = 0;
	to_be_continued(gname, "�����ƶ�2��", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 5, 4, BDI_SELECTED + cl[5][4], 0, bdi, DOWN_TO_UP, 3);
	/* Ϊ�˺����ƶ������������ֵ */
	cl[5 - 3][4] = cl[5][4];
	cl[5][4] = 0;
	to_be_continued(gname, "�����ƶ�3��", pColorLinez_CGI);

	gmw_move_block(pColorLinez_CGI, 2, 4, BDI_SELECTED + cl[2][4], 0, bdi, RIGHT_TO_LEFT, 2);
	/* Ϊ�˺����ƶ������������ֵ */
	cl[2][4 - 2] = cl[2][4];
	cl[2][4] = 0;
	to_be_continued(gname, "�����ƶ�2��", pColorLinez_CGI);

	/* �����е�һ����������
	   ע��1��������ѡ��һ����ʵ����Ϸ��һ������5����
		   2���޶�����ʽ
		   3��δ�޸��ڲ������ֵ   */
	gmw_draw_block(pColorLinez_CGI, 2, 2, 0, bdi);
	to_be_continued(gname, "����1��", pColorLinez_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_color_linez(void)
{
	CONSOLE_GRAPHICS_INFO ColorLinez_CGI; //����һ��CGI����

	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&ColorLinez_CGI);

//	gmw_set_ext_rowcol(&ColorLinez_CGI, 3, 2, 10, 10);						//ע�������ø������򣬿��ܵ���to_be_continued��ӡΪ���У�������δ��������ͬ��
	gmw_set_color(&ColorLinez_CGI, COLOR_BLACK, COLOR_HWHITE);			//����������ɫ
	gmw_set_font(&ColorLinez_CGI, "������", 32);							//����
//	gmw_set_frame_style(&ColorLinez_CGI);									//��Ϸ��������ÿ��ɫ���2��1���зָ���
	gmw_set_frame_default_linetype(&ColorLinez_CGI, 2);					//��Ϸ���������ͣ�����
	gmw_set_frame_color(&ColorLinez_CGI, COLOR_HWHITE, COLOR_BLACK);		//��Ϸ��������ɫ
//	gmw_set_block_border_switch(&ColorLinez_CGI);							//ÿ����Ϸɫ��/������Ҫ�߿�
//	gmw_set_status_line_switch(&ColorLinez_CGI, TOP_STATUS_LINE);				//��Ҫ��״̬��
//	gmw_set_status_line_switch(&ColorLinez_CGI, LOWER_STATUS_LINE);			//��Ҫ��״̬��
	gmw_set_rowno_switch(&ColorLinez_CGI, true);							//��ʾ�к�
	gmw_set_colno_switch(&ColorLinez_CGI, true);							//��ʾ�б�
	gmw_set_delay(&ColorLinez_CGI, DELAY_OF_BLOCK_MOVED, BLOCK_MOVED_DELAY_MS * 3);//�Ӵ���ʱ

	test_step_of_color_linez(&ColorLinez_CGI);

	/* ��Ϊ�޷ָ��ߣ�����һ�� */
	gmw_set_frame_style(&ColorLinez_CGI, 2, 1, false);					//��Ϸ��������ÿ��ɫ���2��1���޷ָ���
	gmw_set_ext_rowcol(&ColorLinez_CGI, 3, 2, 10, 10);					//����������2��3����10��10
	gmw_set_frame_default_linetype(&ColorLinez_CGI, 1);					//��Ϸ���������ͣ�˫��

	test_step_of_color_linez(&ColorLinez_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_step_of_magic_ball(CONSOLE_GRAPHICS_INFO *pMagicBall_CGI)
{
	const char *gname = "MagicBall";
	const int row = 7, col = 7;

	/* Ԥ��һ������ */
	int mb[row][col] = {
		{1, 2, 3, 4, 5, 6, 7},
		{2, 3, 4, 5, 6, 8, 1},
		{7, 6, 9, 4, 3, 2, 1},
		{8, 4, 9, 6, 7, 1, 2},
		{4, 5, 6, 7, 3, 1, 2},
		{5, 7, 5, 8, 3, 2, 4},
		{6, 2, 3, 4, 1, 6, 7},
	};

	/* ����1-9�������ú�����ʽ��ʾ�ڽ�����
	   - ע��1���������ý������� + ѡ�� + ��ʾ������ + ��ը����Ϣ�����ĸ������еķ���
			 2��ʵ��ʵ���е�����ֵ��Ҫ����ˣ��˴�������Ϊ��ɫ��Ĳ�ͬ״̬����ʾ
			 3���� test_color_linez ����������һ�ַ�ʽ��ʾɫ��Ĳ�ͬ״̬�����Զ��� */

	/* ����1-9�������ú�����ʽ��ʾ�ڽ����ϣ�����״̬�� */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //0����ʾ���ÿո���伴��
		{1, COLOR_HBLACK, -1, "��"},
		{2, COLOR_YELLOW, -1, "��"},
		{3, COLOR_HGREEN, -1, "��"},
		{4, COLOR_HCYAN, -1, "��"},
		{5, COLOR_HRED, -1, "��"},
		{6, COLOR_HPINK, -1, "��"},
		{7, COLOR_HYELLOW, -1, "��"},
		{8, COLOR_CYAN, -1, "��"},
		{9, COLOR_WHITE, -1, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	/* ����1-9�������ú�����ʽ��ʾ�ڽ����ϣ�ѡ��״̬�� */
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //�հ�
		{1, COLOR_HBLACK, -1, "��"},
		{2, COLOR_YELLOW, -1, "��"},
		{3, COLOR_HGREEN, -1, "��"},
		{4, COLOR_HCYAN, -1, "��"},
		{5, COLOR_HRED, -1, "��"},
		{6, COLOR_HPINK, -1, "��"},
		{7, COLOR_HYELLOW, -1, "��"},
		{8, COLOR_CYAN, -1, "��"},
		{9, COLOR_WHITE, -1, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	/* ����1-9�������ú�����ʽ��ʾ�ڽ����ϣ���������ʾ״̬�� */
	const BLOCK_DISPLAY_INFO bdi_prompt[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //�հ�
		{1, COLOR_HBLACK, -1, "��"},
		{2, COLOR_YELLOW, -1, "��"},
		{3, COLOR_HGREEN, -1, "��"},
		{4, COLOR_HCYAN, -1, "��"},
		{5, COLOR_HRED, -1, "��"},
		{6, COLOR_HPINK, -1, "��"},
		{7, COLOR_HYELLOW, -1, "��"},
		{8, COLOR_CYAN, -1, "��"},
		{9, COLOR_WHITE, -1, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	/* ����1-9�������ú�����ʽ��ʾ�ڽ����ϣ���ը/����״̬�� */
	const BLOCK_DISPLAY_INFO bdi_exploded[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //�հ�
		{1, COLOR_HBLACK, -1, "��"},
		{2, COLOR_YELLOW, -1, "��"},
		{3, COLOR_HGREEN, -1, "��"},
		{4, COLOR_HCYAN, -1, "��"},
		{5, COLOR_HRED, -1, "��"},
		{6, COLOR_HPINK, -1, "��"},
		{7, COLOR_HYELLOW, -1, "��"},
		{8, COLOR_CYAN, -1, "��"},
		{9, COLOR_WHITE, -1, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	char temp[256];
	int i, j;

	/* ��row/col��ֵ������Ϸ���������� */
	gmw_set_rowcol(pMagicBall_CGI, row, col);

	/* ��ʾ��� */
	gmw_draw_frame(pMagicBall_CGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pMagicBall_CGI->lines, pMagicBall_CGI->cols);
	gmw_status_line(pMagicBall_CGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(pMagicBall_CGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	/* ���ڲ�����չ�ֵ���Ļ�� */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pMagicBall_CGI, i, j, mb[i][j], bdi_normal);
		}
	to_be_continued(gname, "��ʼ�����", pMagicBall_CGI);

	/* �����е���������ʾΪ��������״̬��ʾ�� - ע��������ѡ��������ʵ����Ϸ�а�Ҫ������Һ���ʾ */
	gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_prompt);
	gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_prompt);
	gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_prompt);
	to_be_continued(gname, "��3��������Ϊ��������ʾ", pMagicBall_CGI);

	/* �����е���������ʾΪ��ѡ��״̬�� - ע��������ѡ��������ʵ����Ϸ�а�Ҫ������Һ���ʾ
	   �������н���ʾѡ��״̬��δ�޸��ڲ������ֵ */
	gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_selected);
	gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_selected);
	gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_selected);
	to_be_continued(gname, "��3��������Ϊѡ��", pMagicBall_CGI);

	/* �����е�������������������ʽ - ��ը+�հס��� - ע��������ѡ��������ʵ����Ϸ�а�Ҫ������Һ���ʾ
	   �������н���ʱ����������δ�޸��ڲ������ֵ */
	for (int k = 0; k < 5; k++) {
		gmw_draw_block(pMagicBall_CGI, 2, 2, mb[2][2], bdi_exploded);
		gmw_draw_block(pMagicBall_CGI, 2, 3, mb[2][3], bdi_exploded);
		gmw_draw_block(pMagicBall_CGI, 2, 4, mb[2][4], bdi_exploded);
		Sleep(50);
		gmw_draw_block(pMagicBall_CGI, 2, 2, 0, bdi_normal); //0�ǿհ�
		gmw_draw_block(pMagicBall_CGI, 2, 3, 0, bdi_normal);
		gmw_draw_block(pMagicBall_CGI, 2, 4, 0, bdi_normal);
		Sleep(50);
	}
	to_be_continued(gname, "��3��������(����)", pMagicBall_CGI);

	/* ���ϲ�����������������Ϸ�������
	   ע��1��δ�޸��ڲ������ֵ
		   2��δʹ��ѭ����ֱ��д�˶�ֵ */
	gmw_move_block(pMagicBall_CGI, 1, 2, mb[1][2], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 1, 3, mb[1][3], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 1, 4, mb[1][4], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 2, mb[0][2], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 3, mb[0][3], 0, bdi_normal, UP_TO_DOWN, 1);
	gmw_move_block(pMagicBall_CGI, 0, 4, mb[0][4], 0, bdi_normal, UP_TO_DOWN, 1);
	to_be_continued(gname, "�Ϸ�������", pMagicBall_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_magic_ball(void)
{
	CONSOLE_GRAPHICS_INFO MagicBall_CGI; //����һ��CGI����

	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&MagicBall_CGI);

	gmw_set_ext_rowcol(&MagicBall_CGI, 0, 0, 0, 30);						//�ұ���30��
	gmw_set_color(&MagicBall_CGI, COLOR_BLACK, COLOR_HWHITE);			//����������ɫ
	gmw_set_font(&MagicBall_CGI, "������", 36);							//����
//	gmw_set_frame_style(&MagicBall_CGI);									//��Ϸ��������ÿ��ɫ���2��1���зָ���
	gmw_set_frame_default_linetype(&MagicBall_CGI, 4);					//��Ϸ���������ͣ��ᵥ��˫
	gmw_set_frame_color(&MagicBall_CGI, COLOR_HWHITE, COLOR_BLACK);		//��Ϸ��������ɫ
	gmw_set_rowno_switch(&MagicBall_CGI, true);							//��ʾ�к�
	gmw_set_colno_switch(&MagicBall_CGI, false);							//����ʾ�б�
	gmw_set_status_line_switch(&MagicBall_CGI, TOP_STATUS_LINE, false);	//����Ҫ��״̬��
	gmw_set_status_line_switch(&MagicBall_CGI, LOWER_STATUS_LINE, true);	//��Ҫ��״̬��

	test_step_of_magic_ball(&MagicBall_CGI);

	/* ��Ϊ�޷ָ��ߣ�����һ�� */
	gmw_set_frame_style(&MagicBall_CGI, 2, 1, false);						//��Ϸ��������ÿ��ɫ���2��1���޷ָ���
	gmw_set_ext_rowcol(&MagicBall_CGI, 2, 3, 20, 20);						//��2��3����20��20
	gmw_set_rowno_switch(&MagicBall_CGI, false);							//����ʾ�к�
	gmw_set_colno_switch(&MagicBall_CGI, true);							//��ʾ�б�
	gmw_set_status_line_switch(&MagicBall_CGI, TOP_STATUS_LINE, true);	//��Ҫ��״̬��
	gmw_set_status_line_switch(&MagicBall_CGI, LOWER_STATUS_LINE, false);	//����Ҫ��״̬��

	test_step_of_magic_ball(&MagicBall_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_step_of_2048(CONSOLE_GRAPHICS_INFO *pG2048_CGI)
{
	const char *gname = "2048";
	const int row = 6, col = 5;

	/* Ԥ��һ������ */
	int g2048[row][col] = {
		{0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0},
		{0, 0, 0, 4, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 2, 0, 0, 0},
	};
	int g2048_full[row][col] = {
		{8192, 128, 131072, 256, 512},
		{8, 2, 4096, 1024, 65536},
		{16, 1024, 4, 4, 8192},
		{64, 1024, 512, 256, 4096},
		{2048, 32, 16384, 128, 2048},
		{2, 8, 64, 32768, 16},
	};

	/* ����2 ~ 131072 �������ú�����ʽ��ʾ�ڽ�����
	   - ע��1���������ý������� + ��ǰ + ��ǰ�������Ϣ�������������еķ���
			 2��ʵ��ʵ���е�����ֵ��Ҫ����ˣ��˴�������Ϊ��ɫ��Ĳ�ͬ״̬����ʾ */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0����ʾ���ÿո���伴��
		{2, COLOR_HYELLOW, COLOR_BLACK, NULL},
		{4, COLOR_HRED, COLOR_BLACK, NULL},
		{8, COLOR_GREEN, COLOR_BLACK, NULL},
		{16, COLOR_RED, COLOR_BLACK, NULL},
		{32, COLOR_HGREEN, COLOR_BLACK, NULL},
		{64, COLOR_HYELLOW, COLOR_BLACK, NULL},
		{128, COLOR_HRED, COLOR_BLACK, NULL},
		{256, COLOR_HWHITE, COLOR_BLACK, NULL},
		{512, COLOR_HBLACK, COLOR_BLACK, NULL},
		{1024, COLOR_HPINK, COLOR_BLACK, NULL},
		{2048, COLOR_WHITE, COLOR_BLACK, NULL},
		{4096, COLOR_YELLOW, COLOR_BLACK, NULL},
		{8192, COLOR_PINK, COLOR_BLACK, NULL},
		{16384, COLOR_HBLUE, COLOR_BLACK, NULL},
		{32768, COLOR_HCYAN, COLOR_BLACK, NULL},
		{65536, COLOR_HGREEN, COLOR_BLACK, NULL},
		{131072, COLOR_HPINK, COLOR_BLACK, NULL},  //������ģ������Լ�����
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};

	char temp[256];
	int i, j;

	/* ��row/col��ֵ������Ϸ���������� */
	gmw_set_rowcol(pG2048_CGI, row, col);

	/* ��ʾ��� */
	gmw_draw_frame(pG2048_CGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pG2048_CGI->lines, pG2048_CGI->cols);
	gmw_status_line(pG2048_CGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(pG2048_CGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pG2048_CGI, i, j, g2048_full[i][j], bdi_normal);
		}

	to_be_continued(gname, "ȫ��ֵ��ʾ���", pG2048_CGI);

	/* ���ڲ�����չ�ֵ���Ļ�� */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pG2048_CGI, i, j, g2048[i][j], bdi_normal);
		}
	to_be_continued(gname, "��ʼ�����", pG2048_CGI);

	/* �ƶ�ĳ����
	   ע��1��������ѡ��һ�����֣�ʵ����Ϸ�и��ݼ��̶�����ȷ��ĳ��ɫ��
		   2����������ѡ�˽���λ�ã�ʵ����Ϸ�и��ݼ�ͷ�������ƶ�����0Ϊֹ */
	gmw_move_block(pG2048_CGI, 2, 3, g2048[2][3], 0, bdi_normal, UP_TO_DOWN, 2);
	/* Ϊ�˺����ƶ������������ֵ */
	g2048[2 + 2][3] = g2048[2][3];
	g2048[2][3] = 0;
	to_be_continued(gname, "�����ƶ�2��", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 4, 3, g2048[4][3], 0, bdi_normal, RIGHT_TO_LEFT, 3);
	/* Ϊ�˺����ƶ������������ֵ */
	g2048[4][3 - 3] = g2048[4][3];
	g2048[4][3] = 0;
	to_be_continued(gname, "�����ƶ�3��", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 4, 0, g2048[4][0], 0, bdi_normal, DOWN_TO_UP, 2);
	/* Ϊ�˺����ƶ������������ֵ */
	g2048[4 - 2][0] = g2048[4][0];
	g2048[4][0] = 0;
	to_be_continued(gname, "�����ƶ�2��", pG2048_CGI);

	gmw_move_block(pG2048_CGI, 2, 0, g2048[2][0], 0, bdi_normal, LEFT_TO_RIGHT, 3);
	/* Ϊ�˺����ƶ������������ֵ */
	g2048[2][0 + 3] = g2048[2][0];
	g2048[2][0] = 0;
	to_be_continued(gname, "�����ƶ�3��", pG2048_CGI);

	/* ģ��һ�����µĺϲ�
	   ע��1����������ͬ���ֺϲ�����ʾ������δ��
		   2��δ�޸������ֵ */
	gmw_move_block(pG2048_CGI, 1, 1, g2048[1][1], 0, bdi_normal, DOWN_TO_UP, 1);
	gmw_move_block(pG2048_CGI, 5, 1, g2048[5][1], 0, bdi_normal, DOWN_TO_UP, 5); //�ƶ���(0,1)���غ�λ��
	//�ƶ����غ�λ�ú��������ֵ���ɫ�ػ�(0,1)
	gmw_draw_block(pG2048_CGI, 0, 1, g2048[1][1] + g2048[5][1], bdi_normal); //δ�޸������ֵ��ֱ���úͽ�����ʾ

	gmw_move_block(pG2048_CGI, 2, 3, g2048[2][3], 0, bdi_normal, DOWN_TO_UP, 2);
	to_be_continued(gname, "���һ�����Ϻϲ�", pG2048_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_2048(void)
{
	CONSOLE_GRAPHICS_INFO G2048_CGI; //����һ��CGI����

	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&G2048_CGI);

	gmw_set_color(&G2048_CGI, COLOR_BLACK, COLOR_WHITE);			//����������ɫ
	gmw_set_font(&G2048_CGI, "������", 16);						//����
	gmw_set_frame_style(&G2048_CGI, 10, 5, true);					//��Ϸ��������ÿ��ɫ���10��5���зָ��ߡ�����ɫ����߿򣬿��Ϊ10(�����6λ����)���߶�Ϊ5(Ϊ�˱���ɫ��Ϊ����)��
	gmw_set_frame_color(&G2048_CGI, COLOR_WHITE, COLOR_BLACK);	//��Ϸ��������ɫ
	gmw_set_block_border_switch(&G2048_CGI, true);				//Сɫ����߿�
	gmw_set_rowno_switch(&G2048_CGI, true);						//��ʾ�к�
	gmw_set_colno_switch(&G2048_CGI, true);						//��ʾ�б�

	test_step_of_2048(&G2048_CGI);

	/* ��Ϊ�޷ָ��ߣ�����һ�� */
	gmw_set_font(&G2048_CGI, "Terminal", 16, 8);	//����
	gmw_set_frame_style(&G2048_CGI, 10, 5, false);//��Ϸ��������ÿ��ɫ���10��5���޷ָ��ߡ�����ɫ����߿򣬿��Ϊ10(�����6λ����)���߶�Ϊ5(Ϊ�˱���ɫ��Ϊ����)��
	gmw_set_ext_rowcol(&G2048_CGI, 2, 3, 4, 5);	//�������У���2��3����4��5
	gmw_set_rowno_switch(&G2048_CGI, false);		//����ʾ�к�
	gmw_set_colno_switch(&G2048_CGI, false);		//����ʾ�б�

	test_step_of_2048(&G2048_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_step_of_merge_to_10(CONSOLE_GRAPHICS_INFO *pMto10_CGI)
{
	const char *gname = "�ϳ�ʮ";
	const int row = 6, col = 5;

	/* Ԥ��һ������ */
	int mto10[row][col] = {
		{1, 3, 2, 1, 1},
		{3, 1, 3, 2, 2},
		{3, 1, 1, 2, 1},
		{1, 1, 1, 2, 1},
		{2, 3, 2, 3, 3},
		{1, 2, 2, 2, 1}
	};

	/* ����1 ~ 10 �������ú�����ʽ��ʾ�ڽ�����
	   - ע��1���������ý������� + ��ǰ + ��ǰ�������Ϣ�������������еķ���
			 2��ʵ��ʵ���е�����ֵ��Ҫ����ˣ��˴�������Ϊ��ɫ��Ĳ�ͬ״̬����ʾ */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0����ʾ���ÿո���伴��
		{1,  COLOR_BLUE,   COLOR_BLACK,  NULL},	//����1�ġ�������״̬
		{2,  COLOR_GREEN,  COLOR_BLACK,  NULL},
		{3,  COLOR_CYAN,   COLOR_BLACK,  NULL},
		{4,  COLOR_RED,    COLOR_BLACK,  NULL},
		{5,  COLOR_PINK,   COLOR_BLACK,  NULL},
		{6,  COLOR_HBLUE,  COLOR_BLACK,  NULL},
		{7,  COLOR_HGREEN, COLOR_BLACK,  NULL},
		{8,  COLOR_HCYAN,  COLOR_BLACK,  NULL},
		{9,  COLOR_HRED,   COLOR_BLACK,  NULL},
		{10, COLOR_HPINK,  COLOR_BLACK,  NULL},	//����10�ġ�������״̬�������Ҫ�������Լ�������11���Ժ������
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	const BLOCK_DISPLAY_INFO bdi_related[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0����ʾ���ÿո���伴��
		{1,  COLOR_BLUE,   COLOR_WHITE,  NULL},	//����1�ġ���ѡ��+������״̬
		{2,  COLOR_GREEN,  COLOR_WHITE,  NULL},
		{3,  COLOR_CYAN,   COLOR_WHITE,  NULL},
		{4,  COLOR_RED,    COLOR_WHITE,  NULL},
		{5,  COLOR_PINK,   COLOR_WHITE,  NULL},
		{6,  COLOR_HBLUE,  COLOR_WHITE,  NULL},
		{7,  COLOR_HGREEN, COLOR_WHITE,  NULL},
		{8,  COLOR_HCYAN,  COLOR_WHITE,  NULL},
		{9,  COLOR_HRED,   COLOR_WHITE,  NULL},
		{10, COLOR_HPINK,  COLOR_WHITE,  NULL},	//����10�ġ���ѡ��+������״̬�������Ҫ�������Լ�������11���Ժ������
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, NULL},  //0����ʾ���ÿո���伴��
		{1, COLOR_BLUE,   COLOR_HWHITE, NULL},	//����1�ġ�ѡ�С�״̬
		{2, COLOR_GREEN,  COLOR_HWHITE, NULL},
		{3, COLOR_CYAN,   COLOR_HWHITE, NULL},
		{4, COLOR_RED,    COLOR_HWHITE, NULL},
		{5, COLOR_PINK,   COLOR_HWHITE, NULL},
		{6, COLOR_HBLUE,  COLOR_HWHITE, NULL},
		{7, COLOR_HGREEN, COLOR_HWHITE, NULL},
		{8, COLOR_HCYAN,  COLOR_HWHITE, NULL},
		{9, COLOR_HRED,   COLOR_HWHITE, NULL},
		{10,COLOR_HPINK,  COLOR_HWHITE, NULL},	//����10�ġ�ѡ�С�״̬�������Ҫ�������Լ�������11���Ժ������
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};

	char temp[256];
	int i, j;

	/* ��row/col��ֵ������Ϸ���������� */
	gmw_set_rowcol(pMto10_CGI, row, col);

	/* ��ʾ��� */
	gmw_draw_frame(pMto10_CGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pMto10_CGI->lines, pMto10_CGI->cols);
	gmw_status_line(pMto10_CGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(pMto10_CGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	/* ���ڲ�����չ�ֵ���Ļ�� */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pMto10_CGI, i, j, mto10[i][j], bdi_normal);
		}
	to_be_continued(gname, "��ʼ�����", pMto10_CGI);

	/* ��ʾһ����ǰ�ģ������ƶ�/�����ϰ���ͷ����Ч���� - �˴����ָ��һ����ʵ����Ϸ�и��ݼ��̻����Ĳ�����ѡ�� */
	gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_related);
	to_be_continued(gname, "��ǰ��ѡ״̬", pMto10_CGI);

	/* i=0ѭ������ʾһ��ѡ��������ģ��������/�س������˴�ֱ��д�����꣬ʵ����Ϸ��Ҫ�ò��Һ��������ҵ�ǰѡ����ֵ��ͬ������������
	   i=1ѭ��������ѡ���������������ǽ�����ֵ��Ϊ0��ͨ����ʾ����ֵ�ķ�ʽ��ʾ�հ׿飬�����������ǲ�������ֵ��ֱ�ӽ�������Ϊ0��*/
	for (i = 0; i < 2; i++) {
		if (i == 1)
			mto10[2][2] = mto10[1][1] = mto10[2][1] = mto10[3][0] = mto10[3][1] = mto10[3][2] = 0; //�������ֵ

		gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_selected); //������ֵΪ0ʱ��ʾ����
		gmw_draw_block(pMto10_CGI, 1, 1, mto10[1][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 2, 1, mto10[2][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 0, mto10[3][0], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 1, mto10[3][1], bdi_related);
		gmw_draw_block(pMto10_CGI, 3, 2, mto10[3][2], bdi_related);

		if (i == 0)
			to_be_continued(gname, "��ʾ��ǰѡ�м�������", pMto10_CGI);
		else {
			/* ѡ������ʾ��ֵ */
			mto10[2][2] = 2; //�˴�ֱ��д��
			gmw_draw_block(pMto10_CGI, 2, 2, mto10[2][2], bdi_normal);

			to_be_continued(gname, "������ǰѡ�м�������", pMto10_CGI);
		}
	}

	/* ���ϲ��кϲ��ģ�2,2��ɫ�����䵽��3,2�� - ����Ӧ����ɫ�������δ����ʵ�ʳ����а�����м���
	   ע��1��δ�޸��ڲ������ֵ
		   2��δʹ��ѭ����ֱ��д�˶�ֵ */
	gmw_move_block(pMto10_CGI, 2, 2, mto10[2][2], 0, bdi_normal, UP_TO_DOWN, 1);
	to_be_continued(gname, "����1��ɫ�����", pMto10_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_merge_to_10(void)
{
	CONSOLE_GRAPHICS_INFO Mto10_CGI; //����һ��CGI����

	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&Mto10_CGI);

	gmw_set_color(&Mto10_CGI, COLOR_BLACK, COLOR_WHITE);
	gmw_set_font(&Mto10_CGI, "Terminal", 16, 8);
	gmw_set_frame_style(&Mto10_CGI, 6, 3, true);	//ɫ����߿򣬿��Ϊ6(�����2λ����)���߶�Ϊ3(����һ��)
	gmw_set_frame_color(&Mto10_CGI, COLOR_WHITE, COLOR_BLACK);
	gmw_set_block_border_switch(&Mto10_CGI, true);
	gmw_set_rowno_switch(&Mto10_CGI, true);//��ʾ�к�
	gmw_set_colno_switch(&Mto10_CGI, true);//��ʾ�б�

	test_step_of_merge_to_10(&Mto10_CGI);

	/* ��Ϊ�޷ָ��ߣ�����һ�� */
	gmw_set_font(&Mto10_CGI, "Terminal", 20, 10);
	gmw_set_frame_style(&Mto10_CGI, 6, 3, false);//�޷ָ���
	gmw_set_ext_rowcol(&Mto10_CGI, 2, 3, 4, 5);	//�������У���2��3����4��5

	test_step_of_merge_to_10(&Mto10_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_step_of_popstar(CONSOLE_GRAPHICS_INFO *pPopStar_CGI)
{
	const char *gname = "PopStar";
	const int row = 8, col = 9;

	/* Ԥ��һ������ */
	int popstar[row][col] = {
		{1, 2, 1, 3, 5, 2, 5, 5, 4},
		{2, 2, 3, 4, 5, 1, 1, 2, 1},
		{1, 1, 4, 4, 5, 2, 1, 1, 1},
		{2, 2, 5, 4, 3, 3, 2, 3, 4},
		{4, 3, 5, 5, 5, 2, 5, 1, 2},
		{1, 3, 3, 2, 2, 2, 3, 3, 3},
		{5, 4, 2, 2, 3, 3, 3, 1, 2},
		{4, 2, 2, 2, 3, 2, 2, 2, 2}
	};
	int popstar_col_moved[row][col] = {
		{0, 2, 0, 0, 5, 0, 0, 0, 0},
		{0, 2, 0, 0, 5, 0, 0, 0, 0},
		{1, 1, 0, 0, 5, 0, 0, 0, 0},
		{2, 2, 5, 0, 3, 0, 0, 3, 0},
		{4, 3, 5, 0, 5, 0, 0, 1, 0},
		{1, 3, 3, 2, 2, 0, 0, 3, 0},
		{5, 4, 2, 2, 3, 0, 0, 1, 0},
		{4, 2, 2, 2, 3, 0, 0, 2, 0}
	};

	/* ����0-5�������ú�����ʽ��ʾ�ڽ�����
	   - ע��1���������ý������� + ��ǰ + ��ǰ�������Ϣ�������������еķ���
			 2��ʵ��ʵ���е�����ֵ��Ҫ����ˣ��˴�������Ϊ��ɫ��Ĳ�ͬ״̬����ʾ */

	 /* ����1-5�������ú�����ʽ��ʾ�ڽ����ϣ�����״̬�� */
	const BLOCK_DISPLAY_INFO bdi_normal[] = {
		{0, -1, -1, "  "},  //0����ʾ���ÿո���伴��
		{1, COLOR_HBLUE, COLOR_BLACK, "��"},
		{2, COLOR_HGREEN, COLOR_BLACK, "��"},
		{3, COLOR_HCYAN, COLOR_BLACK, "��"},
		{4, COLOR_HRED, COLOR_BLACK, "��"},
		{5, COLOR_HPINK, COLOR_BLACK, "��"},
		{-999, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	/* ����1-5�������ú�����ʽ��ʾ�ڽ����ϣ���ǰѡ����״̬+ѡ�к������״̬�� */
	const BLOCK_DISPLAY_INFO bdi_related[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //�հ�
		{1, COLOR_HBLUE, COLOR_WHITE, "��"},
		{2, COLOR_HGREEN, COLOR_WHITE, "��"},
		{3, COLOR_HCYAN, COLOR_WHITE, "��"},
		{4, COLOR_HRED, COLOR_WHITE, "��"},
		{5, COLOR_HPINK, COLOR_WHITE, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};
	/* ����1-5�������ú�����ʽ��ʾ�ڽ����ϣ�ѡ��״̬�� */
	const BLOCK_DISPLAY_INFO bdi_selected[] = {
		{BDI_VALUE_BLANK, -1, -1, "  "},  //�հ�
		{1, COLOR_HBLUE, COLOR_HWHITE, "��"},
		{2, COLOR_HGREEN, COLOR_HWHITE, "��"},
		{3, COLOR_HCYAN, COLOR_HWHITE, "��"},
		{4, COLOR_HRED, COLOR_HWHITE, "��"},
		{5, COLOR_HPINK, COLOR_HWHITE, "��"},
		{BDI_VALUE_END, -1, -1, NULL} //�жϽ�������Ϊ-999
	};

	char temp[256];
	int i, j;

	/* ��row/col��ֵ������Ϸ���������� */
	gmw_set_rowcol(pPopStar_CGI, row, col);

	/* ��ʾ��� */
	gmw_draw_frame(pPopStar_CGI);

	/* ��״̬����ʾ���� */
	sprintf(temp, "%s-���ڴ�С��%d�� %d��", gname, pPopStar_CGI->lines, pPopStar_CGI->cols);
	gmw_status_line(pPopStar_CGI, TOP_STATUS_LINE, temp);

	/* ��״̬����ʾ���� */
	gmw_status_line(pPopStar_CGI, LOWER_STATUS_LINE, "����End����", "���Խ�����"); //ֻ�Ǹ�����ʾ���ѣ�������������End����������Ҫ�����뼰�ж�

	/* ���ڲ�����չ�ֵ���Ļ�� */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			gmw_draw_block(pPopStar_CGI, i, j, popstar[i][j], bdi_normal);
		}
	to_be_continued(gname, "��ʼ�����", pPopStar_CGI);

	/* ��ʾһ����ǰ�ģ������ƶ�/�����ϰ���ͷ����Ч���� - �˴����ָ��һ����ʵ����Ϸ�и��ݼ��̻����Ĳ�����ѡ�� */
	gmw_draw_block(pPopStar_CGI, 4, 4, popstar[4][4], bdi_related);
	to_be_continued(gname, "��ǰѡ��״̬", pPopStar_CGI);

	/* ��ʾһ��ѡ��������ģ��������/�س������˴�ֱ��д�����꣬ʵ����Ϸ��Ҫ�ò��Һ��������ҵ�ǰѡ����ֵ��ͬ������������ */
	gmw_draw_block(pPopStar_CGI, 4, 4, popstar[4][4], bdi_selected);
	gmw_draw_block(pPopStar_CGI, 4, 3, popstar[4][3], bdi_related);
	gmw_draw_block(pPopStar_CGI, 4, 2, popstar[4][2], bdi_related);
	gmw_draw_block(pPopStar_CGI, 3, 2, popstar[3][2], bdi_related);
	to_be_continued(gname, "��ǰѡ�м���������ʾ״̬", pPopStar_CGI);

	/* ����ѡ��������� - �˴�ֱ��д������ */
	gmw_draw_block(pPopStar_CGI, 4, 4, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 4, 3, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 4, 2, 0, bdi_normal);
	gmw_draw_block(pPopStar_CGI, 3, 2, 0, bdi_normal);
	to_be_continued(gname, "����4�����", pPopStar_CGI);

	/* ���ϲ��������ģ�2,2��ɫ�����䵽��4,2��
	   ע��1��δ�޸��ڲ������ֵ
		   2��δʹ��ѭ����ֱ��д�˶�ֵ */
	gmw_move_block(pPopStar_CGI, 2, 2, popstar[2][2], 0, bdi_normal, UP_TO_DOWN, 2);
	to_be_continued(gname, "����1��ɫ�����", pPopStar_CGI);

	/* ��ʾ�����ƶ�(ӦΪ�������˴�ֱ��д) */
	{
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++) {
				gmw_draw_block(pPopStar_CGI, i, j, popstar_col_moved[i][j], bdi_normal);
			}
		to_be_continued(gname, "���ƶ���ʼ�����", pPopStar_CGI);

		//���дΪ��������������const���ǲ���
		const int moved_col_no = 7;
		const int distance = 2;

		for (i = row - 1; i >= 0; i--) {
			if (popstar_col_moved[i][moved_col_no] == 0)
				continue; //�հ׿鲻�ƶ�
			gmw_move_block(pPopStar_CGI, i, moved_col_no, popstar_col_moved[i][moved_col_no], 0, bdi_normal, RIGHT_TO_LEFT, distance);
			//Ӧ�޸������ֵ���˴���
		}
	}
	to_be_continued(gname, "��������2�����", pPopStar_CGI);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void test_popstar(void)
{
	CONSOLE_GRAPHICS_INFO PopStar_CGI; //����һ��CGI����

	/*��ȱʡֵ��ʼ�������ڱ�����/ǰ���ף�����16*8�����������޶������У�����״̬�����У����к�/�б꣬�������Ϊ˫�ߣ�ɫ����2/�߶�1/��С�߿���ɫ�ԣ�*/
	gmw_init(&PopStar_CGI);

	gmw_set_color(&PopStar_CGI, COLOR_BLACK, COLOR_WHITE);
	gmw_set_font(&PopStar_CGI, "Terminal", 16, 8);
	gmw_set_frame_style(&PopStar_CGI, 6, 3, true);	//ɫ����߿򣬿��Ϊ6���߶�Ϊ3
	gmw_set_frame_color(&PopStar_CGI, COLOR_WHITE, COLOR_BLACK);
	gmw_set_block_border_switch(&PopStar_CGI, true);

	test_step_of_popstar(&PopStar_CGI);

	/* ��Ϊ�޷ָ��ߣ�����һ�� */
	gmw_set_font(&PopStar_CGI, "������", 20);
	gmw_set_frame_style(&PopStar_CGI, 6, 3, false);
	gmw_set_ext_rowcol(&PopStar_CGI, 2, 3, 4, 5);	//��2��3����4��5
	gmw_set_rowno_switch(&PopStar_CGI, true);//��ʾ�к�
	gmw_set_colno_switch(&PopStar_CGI, true);//��ʾ�б�

	test_step_of_popstar(&PopStar_CGI);
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
	/* ��Ϊ������ lib_tgmw_tools.lib���˴��ȼ�鼸���ṹ��Ĵ�С�Ƿ����Ҫ�� */
	if (sizeof(STATUS_LINE_INFO) != 120) {
		cout << "STATUS_LINE_INFO ����120�ֽڣ����ʹ�� lib_tgmw_tools.lib �еĺ�������ܳ���" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_FRAME_INFO) != 136) {
		cout << "CONSOLE_FRAME_INFO ����136�ֽڣ����ʹ�� lib_tgmw_tools.lib �еĺ�������ܳ���" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_BLOCK_INFO) != 84) {
		cout << "CONSOLE_BLOCK_INFO ����84�ֽڣ����ʹ�� lib_tgmw_tools.lib �еĺ�������ܳ���" << endl;
		return -1;
	}
	if (sizeof(CONSOLE_GRAPHICS_INFO) != 492) {
		cout << "CONSOLE_GRAPHICS_INFO ����492�ֽڣ����ʹ�� lib_tgmw_tools.lib �еĺ�������ܳ���" << endl;
		return -1;
	}

	/* �ù̶�ֵ���Կ�� */
	test_by_fixed();

	/* �ü�������ֵ���Կ�� */
	test_by_input();

	/* �� color_linez ��������Ϸ���� */
	test_color_linez();

	/* �� magic_ball ��������Ϸ���� */
	test_magic_ball();

	/* �� 2048 ��������Ϸ���� */
	test_2048();

	/* �� �ϳ�ʮ ��������Ϸ���� */
	test_merge_to_10();

	/* �� �������� ��������Ϸ���� */
	test_popstar();

	cct_setcolor();

	system("pause");

	return 0;
}
