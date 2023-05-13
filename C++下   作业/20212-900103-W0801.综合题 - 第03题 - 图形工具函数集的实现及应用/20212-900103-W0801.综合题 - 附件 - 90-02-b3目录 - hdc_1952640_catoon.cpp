/* 1952640 信03 刘羽茜 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;
static const double PI = 3.14159;
#define COLOR_SKIN RGB(253,245,233)
#define COLOR_CHEEK RGB(255,211,198)
#define COLOR_MOUTH RGB(255,190,190)
#define COLOR_BROWN RGB(143,45,0)
#define COLOR_FUR RGB(255,141,59)
#define COLOR_EAR RGB(255,102,95)
#define COLOR_HEART RGB(255,124,128)
#define COLOR_MYWHITE RGB(255,255,255)
#define COLOR_FLOWER RGB(255,235,227) //252 200
#define COLOR_BAKEGROUND RGB(255,227,225)
static void draw_body(const int base_x, const int base_y)
{
	hdc_circle(base_x, base_y + 10, 130, true, 5, COLOR_SKIN);
	hdc_arc(base_x, base_y + 10, 130,-85 , 85, 5, COLOR_BROWN);

	hdc_sector(base_x - 45, base_y+10, 90, 210, 280,true, 5, COLOR_SKIN);
	hdc_sector(base_x + 45, base_y+10, 90, 80, 150, true, 5, COLOR_SKIN);
	hdc_arc(base_x - 45, base_y+10, 90, 210, 280, 5, COLOR_BROWN);
	hdc_arc(base_x + 45, base_y+10, 90, 80, 150, 5, COLOR_BROWN);

	hdc_sector(base_x + 40, base_y+160, 133, 255, 305, true, 5, COLOR_SKIN);
	hdc_sector(base_x - 40, base_y + 160, 133, 55, 105, true, 5, COLOR_SKIN);
	hdc_rectangle(base_x - 85, base_y + 110, 170, 85, 0, true, 5, COLOR_SKIN);
	hdc_arc(base_x + 40, base_y+160, 133, 255, 295, 5, COLOR_BROWN);
	hdc_arc(base_x - 40, base_y+160, 133, 65, 105, 5, COLOR_BROWN);
}
static void draw_hands(const int base_x, const int base_y) {
	hdc_ellipse(base_x - 110, base_y + 108, 50, 22, 165, true, 4, COLOR_BROWN);
	hdc_ellipse(base_x + 110, base_y + 108, 50, 22, 15, true, 4, COLOR_BROWN);
}
static void draw_ears(const int base_x, const int base_y) {
	hdc_sector(base_x - 88, base_y - 88, 25, 225, 55, true, 4, COLOR_BROWN);
	hdc_sector(base_x + 88, base_y - 88, 25, -55, 135, true, 4, COLOR_BROWN);
	hdc_sector(base_x - 88, base_y - 88, 12, 225, 55, true, 4, COLOR_CHEEK);
	hdc_sector(base_x + 88, base_y - 88, 12, -55, 135, true, 4, COLOR_CHEEK);
}
static void draw_face(const int base_x, const int y) {
	int base_y = y+13;
	hdc_ellipse(base_x, base_y, 8, 4, 0, true, 3, COLOR_BROWN);

	hdc_ellipse(base_x - 58, base_y - 6, 21, 14, -30, true, 4, COLOR_CHEEK);
	hdc_ellipse(base_x + 58, base_y - 6, 21, 14, +30, true, 4, COLOR_CHEEK);

	hdc_ellipse(base_x-40, base_y-15, 8, 4, 0, true, 3, COLOR_BROWN);
	hdc_ellipse(base_x+40, base_y-15, 8, 4, 0, true, 3, COLOR_BROWN);

	hdc_ellipse(base_x, base_y + 20, 20, 10, 90, true, 3, COLOR_MOUTH);
	hdc_circle(base_x - 12, base_y + 5, 16, true,2, COLOR_SKIN);
	hdc_circle(base_x + 12, base_y + 5, 16,true, 2, COLOR_SKIN);
	hdc_arc(base_x - 12, base_y + 5, 16, 123, 250, 2, COLOR_BROWN);
	hdc_arc(base_x + 12, base_y + 5, 16, 110, 237, 2, COLOR_BROWN);
	hdc_ellipse(base_x, base_y, 8, 4, 0, true, 3, COLOR_BROWN);
}
static void draw_heart(const int base_x, const int base_y) {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 360; j++) {
			double xita = ((double)j / 180.0 * PI);
			int x = base_x-40 + int(double(i) * (1 + sin(xita)) * cos(xita));
			int y = base_y-88 + int(double(i) * (1 + sin(xita)) * sin(xita));
			hdc_point(x, y, 4, COLOR_HEART);
		}
	}
}
static void draw_tail(const int base_x, const int base_y) {
	hdc_ellipse(base_x + 105, base_y + 170, 60, 30, 0, true, 5, COLOR_BROWN);
	for (int i = 0; i <= 20;i++) {
		hdc_arc(base_x + 85 + i, base_y + 170, 40, 53, 135, 4, COLOR_FUR);
	}
	hdc_ellipse(base_x + 105, base_y + 170, 60, 30, 0, false, 5, COLOR_BROWN);
}

static void draw_big_love(const int base_x,const int base_y)
{
	int x, y;
	for (int i = 0; i < 6; i++) {
		x = base_x + 70;
		y = base_y + 118;
		double xita = -PI / 6.0 + PI / 3.0 * i;
		int x1 = x + int(20.0 * cos(xita));
		int y1 = y + int(20.0 * sin(xita));
		hdc_ellipse(x1, y1, 20, 12, int(xita / PI * 180.0), true, 5, COLOR_FLOWER);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x +70;
		y = base_y + 118;
		double xita = -PI / 6.0 + PI / 3.0 * i;
		int x1 = x + int(20.0 * cos(xita));
		int y1 = y + int(20.0 * sin(xita));
		hdc_line(x, y, x1, y1, 3, COLOR_MYWHITE);
		hdc_point(x1, y1, 8, COLOR_MYWHITE);
	}
	for (int j = 0; j <= 360; j++) {
		double xita = ((double)j / 180.0 * PI);
		int x = base_x + int((105.0) * (1 + sin(xita)) * cos(xita));
		int y = base_y - 20 + int((105.0) * (1 + sin(xita)) * sin(xita));
		hdc_point(x, y, 5, COLOR_HEART);
	}
}

static void draw_flower(const int base_x, const int base_y) {
	int x, y;
	for (int i = 0; i < 6; i++) {
		x = base_x + 140;
		y = base_y - 120;
		double xita = PI / 10.0 + PI / 3.0 * i;
		int x1 = x + int(70.0 * cos(xita));
		int y1 = y + int(70.0 * sin(xita));
		hdc_ellipse(x1, y1, 70, 40, int(xita / PI * 180.0), true, 5, COLOR_FLOWER);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x + 140;
		y = base_y - 120;
		double xita = PI / 10.0 + PI / 3.0 * i;
		int x1 = x + int(70.0 * cos(xita));
		int y1 = y + int(70.0 * sin(xita));
		hdc_line(x, y, x1, y1, 3, COLOR_MYWHITE);
		hdc_point(x1, y1, 8, COLOR_MYWHITE);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x - 140;
		y = base_y - 150;
		double xita = PI / 8.0 + PI / 3.0 * i;
		int x1 = x + int(50.0 * cos(xita));
		int y1 = y + int(50.0 * sin(xita));
		hdc_ellipse(x1, y1, 50, 30, int(xita / PI * 180.0), true, 5, COLOR_FLOWER);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x - 140;
		y = base_y - 150;
		double xita = PI / 8.0 + PI / 3.0 * i;
		int x1 = x + int(50.0 * cos(xita));
		int y1 = y + int(50.0 * sin(xita));
		hdc_line(x, y, x1, y1, 3, COLOR_MYWHITE);
		hdc_point(x1, y1, 8, COLOR_MYWHITE);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x - 120;
		y = base_y + 90;
		double xita = PI / 2.0 + PI / 3.0 * i;
		int x1 = x + int(60.0 * cos(xita));
		int y1 = y + int(60.0 * sin(xita));
		hdc_ellipse(x1, y1, 60, 40, int( xita / PI * 180.0), true, 5, COLOR_FLOWER);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x - 120;
		y = base_y + 90;
		double xita = PI / 2.0 + PI / 3.0 * i;
		int x1 = x + int(60.0 * cos(xita));
		int y1 = y + int(60.0 * sin(xita));
		hdc_line(x, y, x1, y1, 3, COLOR_MYWHITE);
		hdc_point(x1, y1, 8, COLOR_MYWHITE);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x + 180;
		y = base_y + 110;
		double xita = -PI / 2.0 + PI / 3.0 * i;
		int x1 = x + int(30.0 * cos(xita));
		int y1 = y + int(30.0 * sin(xita));
		hdc_ellipse(x1, y1, 30, 18, int(xita / PI * 180.0), true, 5, COLOR_FLOWER);
	}
	for (int i = 0; i < 6; i++) {
		x = base_x + 180;
		y = base_y + 110;
		double xita = -PI / 2.0 + PI / 3.0 * i;
		int x1 = x + int(30.0 * cos(xita));
		int y1 = y + int(30.0 * sin(xita));
		hdc_line(x, y, x1, y1, 3, COLOR_MYWHITE);
		hdc_point(x1, y1, 8, COLOR_MYWHITE);
	}
	
}

void hdc_draw_catoon_1952640(const int base_x, const int base_y) {
	hdc_cls();
	cout << "给你一颗小心心" << endl;
	hdc_rectangle(base_x - 250, base_y - 240, 500, 440,0, true, 4,COLOR_BAKEGROUND);
	draw_flower(base_x, base_y);
	draw_tail(base_x, base_y);
	draw_body(base_x, base_y);
	draw_hands(base_x, base_y);
	draw_ears(base_x, base_y);
	draw_face(base_x, base_y);
	draw_heart(base_x, base_y);
	draw_big_love(base_x, base_y);
}