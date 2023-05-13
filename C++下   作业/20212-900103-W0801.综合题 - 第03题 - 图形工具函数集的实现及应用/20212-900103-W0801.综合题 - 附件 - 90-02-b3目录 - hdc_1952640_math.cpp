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
/* 画竖直心脏线 */
void hdc_draw_Mathematical_curve_1952640() {
	hdc_cls();
	for (int j = 0; j <= 360; j++) {
		double xita = ((double)j / 180.0 * PI);
		int x =350+ int((80.0) * (1 + sin(xita)) * cos(xita));
		int y =300+ int((80.0) * (1 + sin(xita)) * sin(xita));
		hdc_point(x, y, 5, RGB(245, 255, 33));
	}
	for (int j = 0; j <= 360; j++) {
		double xita = ((double)j / 180.0 * PI);
		int x =350+ int((100.0) * (1 + sin(xita)) * cos(xita));
		int y =300+ int((100.0) * (1 + sin(xita)) * sin(xita));
		hdc_point(x, y, 8, RGB(100, 180, 200));
	}
	for (int j = 0; j <= 360; j++) {
		double xita = ((double)j / 180.0 * PI);
		int x =350+ int((120.0) * (1 + sin(xita)) * cos(xita));
		int y =300+ int((120.0) * (1 + sin(xita)) * sin(xita));
		hdc_point(x, y, 10, RGB(255, 181, 181));
	}
}