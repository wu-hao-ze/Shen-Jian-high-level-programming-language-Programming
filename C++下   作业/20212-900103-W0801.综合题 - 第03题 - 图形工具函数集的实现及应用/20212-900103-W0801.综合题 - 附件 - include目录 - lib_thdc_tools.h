#pragma once

#include "../include/cmd_console_tools.h"		//需要 COLOR_*** 定义
#define INVALID_RGB		0x7FFFFFFF

/* ------------------------------------------------
       以下函数声明为lib_thdc_tools.lib中实现的
   ------------------------------------------------ */

/* 初始化及结束函数（具体参数含义参见cpp） */
void thdc_init(const int bgcolor = COLOR_BLACK, const int fgcolor = COLOR_WHITE, const int width = 8 * 120, const int high = 16 * 30);
void thdc_release(void);
void thdc_set_delay(int ms);

/* 设置画笔颜色（具体参数含义参见cpp） */
void thdc_set_pencolor(const int rgb_value);
void thdc_set_pencolor(const unsigned char red, const unsigned char green, const unsigned char blue);

/* 清除屏幕（颜色、窗口大小不变） */
void thdc_cls(void);

/* 画点（具体参数含义参见cpp） */
void thdc_point(const int x, const int y, const int thickness = 3, const int RGB_value = INVALID_RGB);

/* 画线段（具体参数含义参见cpp） */
void thdc_line(const int x1, const int y1, const int x2, const int y2, const int thickness = 2, const int RGB_value = INVALID_RGB);

/* 画三角形、矩形、正方形（具体参数含义参见cpp） */
void thdc_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void thdc_rectangle(const int left_up_x, const int left_up_y, const int width, const int high, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void thdc_square(const int left_up_x, const int left_up_y, const int length, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);

/* 画弧、扇形、圆、椭圆（具体参数含义参见cpp） */
void thdc_arc(const int point_x, const int point_y, const int radius, const int angle_begin = 0, const int angle_end = 360, const int thickness = 2, const int RGB_value = INVALID_RGB);
void thdc_sector(const int point_x, const int point_y, const int radius, const int angle_begin = 0, const int angle_end = 360, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void thdc_circle(const int point_x, const int point_y, const int radius, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
void thdc_ellipse(const int point_x, const int point_y, const int radius_a, const int radius_b, const int rotation_angles = 0, const bool filled = false, const int thickness = 2, const int RGB_value = INVALID_RGB);
