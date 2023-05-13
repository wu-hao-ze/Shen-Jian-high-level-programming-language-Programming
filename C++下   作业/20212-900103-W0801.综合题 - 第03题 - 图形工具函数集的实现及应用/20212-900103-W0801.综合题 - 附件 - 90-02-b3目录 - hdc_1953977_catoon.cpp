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

static const int R = 300;
static const int border_tn = 3;
static const int BLACK = RGB(0, 0, 0);
static const int WHITE = RGB(255, 255, 255);
static const double PI = acos(-1.0);

static int rad_to_angle(double rad)
{
	return int(rad / PI * 180 + 0.5);
}

static void hdc_hand(const int base_x, const int base_y)
{
	hdc_sector(base_x - 110, base_y + 245, 25, -70, 20, true, 1, WHITE);
	hdc_arc(base_x - 110, base_y + 245, 25, -70, 20, border_tn, BLACK);
	hdc_sector(base_x - 128, base_y + 238, 30, 60, 110, true, 1, WHITE);
	hdc_arc(base_x - 128, base_y + 238, 30, 60, 110, border_tn, BLACK);

	hdc_sector(base_x + 110, base_y + 245, 25, -20, 70, true, 1, WHITE);
	hdc_arc(base_x + 110, base_y + 245, 25, -20, 70, border_tn, BLACK);
	hdc_sector(base_x + 128, base_y + 238, 30, -110, -60, true, 1, WHITE);
	hdc_arc(base_x + 128, base_y + 238, 30, -110, -60, border_tn, BLACK);
}

static void hdc_necklace(const int base_x, const int base_y)
{
	for (int i = base_x - R; i <= base_x + R; i++)
	{
		for (int j = base_y; j <= base_y + R; j++)
		{
			if (int(sqrt((base_x - i) * (base_x - i) + (j - base_y) * (j - base_y)) + 0.5) < R)
			{
				if (int(sqrt((base_x - i) * (base_x - i) + (j - base_y + 280) * (j - base_y + 280)) + 0.5) > 500)
				{
					if (int(sqrt((base_x - i) * (base_x - i) + (j - base_y + 245) * (j - base_y + 245)) + 0.5) < 490)
					{
						hdc_point(i, j, 1, RGB(174, 51, 53));
					}
				}
			}
		}
	}
	hdc_arc(base_x, base_y - 280, 500, 149, 211, 4, BLACK);
	hdc_arc(base_x, base_y - 245, 490, 151, 209, 4, BLACK);

	hdc_circle(base_x, base_y + 233, 25, true, 1, RGB(249, 226, 32));
	hdc_circle(base_x, base_y + 233, 25, false, 4, BLACK);
	hdc_circle(base_x, base_y + 230, 10, true, 1, BLACK);
	hdc_line(base_x, base_y + 240, base_x, base_y + 258, 4, BLACK);
	hdc_circle(base_x, base_y + 255, 5, true, 1, BLACK);
}

static void hdc_dot(const int base_x, const int base_y)
{
	hdc_sector(base_x - 200, base_y + 10, 20, -50, -20, true, 1, RGB(184, 90, 90));
	hdc_point(base_x - 213, base_y - 7, 13, RGB(184, 90, 90));
	hdc_ellipse(base_x - 218, base_y + 15, 9, 4, 40, true, 1, RGB(184, 90, 90));
	hdc_point(base_x - 222, base_y + 12, 12, RGB(184, 90, 90));
	hdc_sector(base_x - 218, base_y + 43, 23, -75, -50, true, 1, RGB(184, 90, 90));
	hdc_point(base_x - 237, base_y + 33, 10, RGB(184, 90, 90));
	hdc_arc(base_x - 218, base_y + 13, 30, 195, 225, 2, RGB(184, 90, 90));

	hdc_arc(base_x - 220, base_y + 43, 40, 155, 185, 5, RGB(184, 90, 90));
	hdc_arc(base_x - 223, base_y + 31, 40, 150, 190, 5, RGB(184, 90, 90));

	hdc_sector(base_x + 200, base_y + 10, 20, 20, 50, true, 1, RGB(184, 90, 90));
	hdc_point(base_x + 213, base_y - 7, 13, RGB(184, 90, 90));
	hdc_ellipse(base_x + 218, base_y + 15, 9, 4, -40, true, 1, RGB(184, 90, 90));
	hdc_point(base_x + 222, base_y + 12, 12, RGB(184, 90, 90));
	hdc_sector(base_x + 218, base_y + 43, 23, 50, 75, true, 1, RGB(184, 90, 90));
	hdc_point(base_x + 237, base_y + 33, 10, RGB(184, 90, 90));
	hdc_arc(base_x + 218, base_y + 13, 30, 135, 165, 2, RGB(184, 90, 90));

	hdc_arc(base_x + 220, base_y + 43, 40, 175, 205, 5, RGB(184, 90, 90));
	hdc_arc(base_x + 223, base_y + 31, 40, 170, 210, 5, RGB(184, 90, 90));
}

static void hdc_eye(const int base_x, const int base_y)
{
	int x1 = -150, y1 = 80, r1 = 75;
	int x2 = -212, y2 = 392, r2 = 350;
	hdc_arc(base_x + x1, base_y + y1, r1, -60, 80, 4, BLACK);
	hdc_arc(base_x + x2, base_y + y2, r2, 0, 23, 4, BLACK);

	hdc_arc(base_x - x1, base_y + y1, r1, -80, 60, 4, BLACK);
	hdc_arc(base_x - x2, base_y + y2, r2, -23, 0, 4, BLACK);

	for (int i = -190; i <= -120; i++)
	{
		int u = int(y1 - sqrt(r1 * r1 - (i - x1) * (i - x1)) + 0.5);
		int d = int(y2 - sqrt(r2 * r2 - (i - x2) * (i - x2)) + 0.5);
		hdc_line(base_x + i, base_y + u, base_x + i, base_y + d, 1, BLACK);
		hdc_line(base_x - i, base_y + u, base_x - i, base_y + d, 1, BLACK);
	}
}

static void hdc_nosemouth(const int base_x, const int base_y)
{
	hdc_arc(base_x, base_y + 40, 20, 120, 240, 2, BLACK);
	hdc_line(base_x, base_y + 60, base_x, base_y + 70, 3, BLACK);
	hdc_arc(base_x - int(10 * sqrt(3) + 0.5), base_y + 60, 20, 120, 240, 4, BLACK);
	hdc_arc(base_x + int(10 * sqrt(3) + 0.5), base_y + 60, 20, 120, 240, 4, BLACK);
}

static void hdc_ear(const int base_x, const int base_y)
{
    
	const int x2 = -223, y2 = -110, r2 = 210;
	for (int i = -280; i <= -100; i++)
	{
		for (int j = -400; j <= -50; j++)
		{
			if ((i - 1320) * (i - 1320) + (j - 100) * (j - 100) < 1597 * 1597 &&
				(i - x2) * (i - x2) + (j - y2) * (j - y2) < (r2-3) * (r2-3) &&
				i * i + j * j > (R-4)*(R-4))
			{
				hdc_point(base_x + i, base_y + j, 1, WHITE);
				hdc_point(base_x - i, base_y + j, 1, WHITE);
			}
		}
	}

    hdc_arc(base_x + 1320, base_y + 100, 1600, -81, -75, 4, BLACK);
    hdc_arc(base_x - 223, base_y - 110, 210, -1, 35, 4, BLACK);

    hdc_arc(base_x - 1320, base_y + 100, 1600, 75, 81, 4, BLACK);
    hdc_arc(base_x + 223, base_y - 110, 210, -35, 1, 4, BLACK);
}

static void hdc_touding(const int base_x, const int base_y)
{
	int y1, y2;
	for (int i = 0; i <= 100; i++)
	{
		y1 = -int(sqrt(R * R - i * i) + 0.5);
		y2 = int(sqrt(150 * 150 - i * i) - 250 + 0.5);

		hdc_line(base_x + i, base_y + y1, base_x + i, base_y + y2, 1, RGB(140, 141, 135));
		hdc_line(base_x - i, base_y + y1, base_x - i, base_y + y2, 1, RGB(241, 174, 106));
	}

	hdc_line(base_x - 100, base_y - 280, base_x - 100, base_y - 140, border_tn, BLACK);
	hdc_line(base_x + 100, base_y - 280, base_x + 100, base_y - 140, border_tn, BLACK);
	hdc_line(base_x, base_y - 100, base_x, base_y - 300, border_tn, BLACK);

	hdc_arc(base_x, base_y - 250, 150, 138, 222, border_tn, BLACK);
	hdc_arc(base_x, base_y, R, -20, 20, border_tn, BLACK);
}

void hdc_draw_catoon_1953977(const int base_x, const int base_y)
{
	hdc_cls();

	hdc_circle(base_x, base_y, R, true, 2, WHITE);
	hdc_arc(base_x, base_y, R, 58,302, border_tn, BLACK);
	hdc_touding(base_x, base_y);
	hdc_ear(base_x, base_y);
	hdc_nosemouth(base_x, base_y);
	hdc_eye(base_x, base_y);
	hdc_dot(base_x, base_y);
	hdc_necklace(base_x, base_y);
	hdc_hand(base_x, base_y);
}