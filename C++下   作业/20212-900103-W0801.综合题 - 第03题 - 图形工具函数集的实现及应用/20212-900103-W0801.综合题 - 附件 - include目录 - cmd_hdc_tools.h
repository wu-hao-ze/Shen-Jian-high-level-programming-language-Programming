#pragma once

#include "../include/cmd_console_tools.h"		//��Ҫ COLOR_*** ����

#define INVALID_RGB		0x7FFFFFFF

#define HDC_SERIES_BY_TEACHER   1

#if !HDC_SERIES_BY_TEACHER
/* -----------------------------------------------------------
       ���º�������ΪҪ��ѧ��ʵ�ֵ�
       ��Ӧ�Ŀպ������� ../common/commom_hdc_tools.cpp ��
   ----------------------------------------------------------- */

/* ��ʼ�������������������������μ�cpp�� */
void hdc_init(const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE, const int width = 8 * 120, const int high = 16 * 30);
void hdc_release(void);
void hdc_set_delay(int ms);

/* ���û�����ɫ�������������μ�cpp�� */
void hdc_set_pencolor(const int rgb_value);
void hdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue);

/* �����Ļ����ɫ�����ڴ�С���䣩 */
void hdc_cls(void);

/* ���㣨�����������μ�cpp�� */
void hdc_point(const int x, const int y, const int thickness = 3, const int RGB_value = INVALID_RGB);

/* ���߶Σ������������μ�cpp�� */
void hdc_line(const int x1, const int y1, const int x2, const int y2, const int thickness = 2, const int RGB_value = INVALID_RGB);

/* �������Ρ����Ρ������Σ������������μ�cpp�� */
void hdc_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void hdc_rectangle(const int left_up_x, const int left_up_y, const int width, const int high, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void hdc_square(const int left_up_x, const int left_up_y, const int length, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);

/* ���������Ρ�Բ����Բ�������������μ�cpp�� */
void hdc_arc(const int point_x, const int point_y, const int radius, const int angle_begin = 0, const int angle_end = 360, const int thickness = 2, const int RGB_value = INVALID_RGB);
void hdc_sector(const int point_x, const int point_y, const int radius, const int angle_begin = 0, const int angle_end = 360, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void hdc_circle(const int point_x, const int point_y, const int radius, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void hdc_ellipse(const int point_x, const int point_y, const int radius_a, const int radius_b, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);

#else

/* ------------------------------------------------
       �������� thdc_* ͨ���궨�� ��Ϊhdc_*������test��ͳһ����
   ------------------------------------------------ */
#define hdc_init			thdc_init
#define hdc_release		thdc_release
#define hdc_set_delay	thdc_set_delay

#define hdc_set_pencolor	thdc_set_pencolor

#define hdc_cls			thdc_cls

#define hdc_point		thdc_point

#define hdc_line			thdc_line

#define hdc_triangle		thdc_triangle
#define hdc_rectangle	thdc_rectangle
#define hdc_square		thdc_square

#define hdc_arc			thdc_arc
#define hdc_sector		thdc_sector
#define hdc_circle		thdc_circle
#define hdc_ellipse		thdc_ellipse

   /* ------------------------------------------------
          ���º�������Ϊlib_thdc_tools.lib��ʵ�ֵ�
      ------------------------------------------------ */
#include "../include/lib_thdc_tools.h"

#endif
