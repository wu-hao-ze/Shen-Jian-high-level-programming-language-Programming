/* 1953729 ��09 ����� */
#pragma once

/* -----------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ----------------------------------------- */

int menu();
int end(int);
void input(int*, char*, char*, char*, int);
void hanoi(int n, char src, char tmp, char dst, int num);
void choose(int n, char src, char tmp, char dst, int num);
void first(int n, char src, char dst);
void second(int n, char src, char dst);
void heng(int n, char src, char dst);
void shu(int n, char src, char dst, int num);
void fourth(int n, char src, char dst, int num);
void draw(int n, char src, char dst, int num);
void drawplate(int n, char src, char dst, int num);
void move(int n, char src, char dst, int num);
void eighth(int n, char src, char dst, int num);
void ninth(int n, char src, char tmp, char dst, int num);
void feifa();