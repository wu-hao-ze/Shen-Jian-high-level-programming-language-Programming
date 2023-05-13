/*1851746 信19 范千惠*/
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

static const double PI = 3.14159;

static void hdc_draw_Lemniscate_of_Bernoulli(int base_x, int base_y, int a, int thickness, int RGB_value)
{
	//直线拟合
	int x1, y1, x2, y2;
	x1 =(int)( base_x - 0.7 * a);
	y1 =(int)( base_y - 0.7 * a);
	x2 = (int)(base_x + 0.7 * a);
	y2 = (int)(base_y + 0.7 * a);
	hdc_line(x1, y1, x2, y2, 1+thickness, RGB_value);
	x1 = (int)(base_x - 0.7 * a);
	y1 = (int)(base_y + 0.7 * a);
	x2 = (int)(base_x + 0.7 * a);
	y2 = (int)(base_y - 0.7 * a);
	hdc_line(x1, y1, x2, y2, 1+thickness, RGB_value);

	//半圆拟合
	int r = (int)(sqrt(2) * a);
	int pointr_x = base_x + (int)(sqrt(6) * a);
	int pointr_y = base_y;
	int pointf_x = base_x - (int)(sqrt(6) * a);
	int pointf_y = base_y;
	hdc_arc(pointr_x, pointr_y, r, 0, 180, thickness, RGB_value);
	hdc_arc(pointf_x, pointf_y, r, 180, 0, thickness, RGB_value);

	//弧线拟合
	int arc_r = (int)(7*sqrt(2)*a/2-sqrt(6)*a);
	int arcr_x = pointr_x;
	int arcf_x = pointf_x;
	int arcu_y = base_y + (int)(5 * sqrt(2) * a / 2 - sqrt(6) * a);
	int arcb_y = base_y - (int)(5 * sqrt(2) * a / 2 - sqrt(6) * a);
	double angle_b = asin((sqrt(6) - 1 / sqrt(2)) * a / (7 * sqrt(2) * a / 2 - sqrt(6) * a));
	int angle = (int)(angle_b * 180 / PI);

	//右上
	hdc_arc(arcr_x, arcu_y, arc_r, -angle, 0, thickness, RGB_value);
	//右下
	hdc_arc(arcr_x, arcb_y, arc_r,180, 180+angle, thickness, RGB_value);
	//左上
	hdc_arc(arcf_x, arcu_y, arc_r, 0, angle, thickness, RGB_value);
	//左下
	hdc_arc(arcf_x, arcb_y, arc_r, 180- angle, 180, thickness, RGB_value);

}

void hdc_draw_Mathematical_curve_1851746()
{
	int base_x=390, base_y=300;
	int a=80;
	for (int i = 0; i <= 15; i++) {
		hdc_draw_Lemniscate_of_Bernoulli(base_x, base_y, a - 5 * i, 3, RGB(120+i*8, 2, 127));
	}
	cct_gotoxy(0, 0);
	cct_setcolor(7, 0);
	cout << "#一系列伯努利双扭线" << endl;
}
