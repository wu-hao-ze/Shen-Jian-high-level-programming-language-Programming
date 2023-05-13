//1953977 –≈20 ÷‹¡’¡’
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

static double f(double theta, int size)
{
	return size * 15.0 / sqrt(17 - 16 * sin(theta) * fabs(cos(theta)));
}

void hdc_draw_Mathematical_curve_1953977()
{
	hdc_cls();
	double theta, rho;
	int x, y, size = 70, thickness = 2, RGB_value = 0;
	for (int i = 0; i <= 36000; i++)
	{
		theta = i / 36000.0 * 2 * acos(-1.0);
		rho = f(theta, size);
		x = int(rho * cos(theta) + 0.5);
		y = int(rho * sin(theta) + 0.5);
		hdc_point(x + 400, -y + 400, thickness, RGB_value);
	}

}