/*1851746 ÐÅ19 ·¶Ç§»Ý*/
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

static void test_coordinate(const int basex, const int basey, const int thickness)
{
	const int N = 700;
	const int dN = 25;

	for (int i = 0; i < N; i += dN) {
		int RGB_value = RGB(247, 247, 247);
		if (!(i % 125))
			RGB_value = RGB(139, 205, 221);
		hdc_point(basex+i, basey, thickness, RGB_value);
		hdc_line(basex + i, basey, basex + i, basey + N);
		
		hdc_point(basex, basey+i, thickness, RGB_value);
		hdc_line(basex, basey+i, basex + N, basey+i);

	}
}

//draw PikaPika 
void hdc_draw_catoon_1851746(const int base_x, const int base_y)
{
	////cct_setconsoleborder(120, 50);
	//test_coordinate(base_x, base_y, 6);
	hdc_rectangle(base_x + 10, base_y + 105, 635, 500, 0, 1, 2, RGB(235, 212, 175));
	
	const int LineTn = 3;
	const int LineColor = RGB(187, 66, 5);
	const int PikaYColor = RGB(255, 252, 121);
	const int FaceColor = RGB(255, 217, 217);
	const int FlowerColor = RGB(255, 83, 83);
	const int CULineColor = LineColor;
	const int BackColor = FaceColor;
	
	//µ××ù
	hdc_ellipse(base_x+320, base_y+500, 210, 30, 0, 1, 2, BackColor);

	//Î²°Í
	hdc_triangle(base_x + 191, base_y + 448, base_x + 194, base_y + 471, base_x + 240, base_y + 492,1,2,CULineColor);
	hdc_triangle(base_x + 191, base_y + 448, base_x + 194, base_y + 471, base_x + 162, base_y + 487, 1,2, CULineColor);
	hdc_triangle(base_x + 154, base_y + 448, base_x + 191, base_y + 448, base_x + 162, base_y + 487, 1,2, CULineColor);
	hdc_triangle(base_x + 154, base_y + 448, base_x + 137, base_y + 455, base_x + 162, base_y + 487, 1,2, CULineColor);

	//ÉíÌå
	hdc_circle(base_x+243,base_y+ 460, 38, 1, 2,PikaYColor);
	hdc_sector(base_x + 268, base_y + 453, 57, -128, 143,1,2, PikaYColor);
	hdc_arc(base_x + 243, base_y + 460, 38, -180, -58, LineTn, LineColor);
	hdc_arc(base_x + 268, base_y + 453, 57, -76, 143, LineTn, LineColor);

	////Í·
	//ÉÏ
	hdc_sector(base_x + 262, base_y + 375, 111, -57, 31, 1, 2, PikaYColor);
	hdc_arc(base_x + 262, base_y + 375, 111, -25, 18, 3, LineColor);
	//ÓÒ
	hdc_sector(base_x + 278, base_y + 352, 82, 30, 106, 1, 2, PikaYColor);
	hdc_arc(base_x + 278, base_y + 352, 82, 30, 106, LineTn, LineColor);
	//×ó
	hdc_sector(base_x + 248, base_y + 344, 82, -130, -73+5, 1, 2, PikaYColor);
	hdc_arc(base_x + 248, base_y + 344, 82, -130, -73+5,LineTn, LineColor);
	//ÏÂ
	hdc_sector(base_x + 257+2, base_y-6 + 303, 125, 127,218, 1, 2, PikaYColor);
	hdc_arc(base_x + 257+2, base_y -6+ 303, 125, 127, 218, LineTn, LineColor);

	//»¨
	hdc_circle(base_x + 293, base_y + 407, 18, 1, 2, FlowerColor);
	hdc_circle(base_x + 293, base_y + 407, 18, 0, 2, LineColor);
	hdc_triangle(base_x + 275, base_y + 390, base_x + 305, base_y + 390, base_x + 294, base_y + 425, 1, 2, FlowerColor);
	hdc_sector(base_x + 294, base_y + 383, 5, 89, 269, 1, 2, FlowerColor);
	hdc_line(base_x + 293, base_y + 425, base_x + 295, base_y + 450,2,LineColor);

	//ÓÒÊÖ
	hdc_arc(base_x + 306, base_y + 435, 14, -180, 30, LineTn, LineColor);

	//×óÊÖ
	hdc_arc(base_x + 275, base_y + 435, 19, 80, 180, LineTn, LineColor);
	hdc_line(base_x + 243, base_y + 425, base_x + 291, base_y + 430, LineTn, LineColor);
	hdc_line(base_x + 293, base_y + 433, base_x + 291, base_y + 430, LineTn, LineColor);

	//½Å
	hdc_ellipse(base_x + 300, base_y + 478, 24, 20, 90, 1, LineTn, LineColor);
	hdc_ellipse(base_x + 300, base_y + 478, 22, 18, 90, 1, 2, PikaYColor);
	hdc_ellipse(base_x + 259, base_y + 478, 27, 24, 104, 1, LineTn, LineColor);
	hdc_ellipse(base_x + 259, base_y + 478, 25, 22, 104, 1, 2, PikaYColor);

	hdc_line(base_x + 265, base_y + 453, base_x + 265, base_y + 466,2,LineColor);
	hdc_line(base_x + 275, base_y + 455, base_x + 275, base_y + 465, 2, LineColor);

	hdc_line(base_x + 295, base_y + 455, base_x + 295, base_y + 468, 2, LineColor);
	hdc_line(base_x + 305, base_y + 455, base_x + 305, base_y + 464, 2, LineColor);
	hdc_line(base_x + 313, base_y + 459, base_x + 313, base_y + 466, 2, LineColor);

	////Îå¹Ù
	//×ì
	hdc_arc(base_x + 290, base_y + 369, 16, 134, 220, 2, LineColor);
	//±Ç
	hdc_circle(base_x + 300, base_y + 365, 2, 1, 1, RGB(183,155,155));
	//ÑÛ
	hdc_ellipse(base_x + 235, base_y + 355, 25, 22, 113, 1, 2, LineColor);
	hdc_ellipse(base_x + 327, base_y + 349, 20, 15, 75, 1, 2, LineColor);
	hdc_circle(base_x + 243, base_y + 344, 9, 1, 1, RGB(255, 255, 255));
	hdc_circle(base_x + 327, base_y + 337, 6, 1, 1, RGB(255, 255, 255));
	//×óÈùºì
	hdc_ellipse(base_x + 213, base_y + 396, 25, 16, 18, 1, 2, LineColor);
	hdc_ellipse(base_x + 213, base_y + 396, 24, 15, 18, 1, 2, FaceColor);
	//ÓÒÈùºì
	hdc_ellipse(base_x + 346, base_y + 378, 18, 7, 125, 1, 2, LineColor);
	hdc_ellipse(base_x + 346, base_y + 378, 17, 6, 125, 1, 2, FaceColor);
	////×ó¶ú¶ä////
	for (int i = 0; i < 5; i++) {
		hdc_arc(base_x + 88-i*15, base_y + 297, 122, 58, 84, 30, PikaYColor);
	}
	hdc_arc(base_x + 113, base_y + 389, 181, -11, 27, 20, PikaYColor);
	hdc_arc(base_x + 150, base_y + 153, 150, 166, 184, 20, PikaYColor);
	hdc_arc(base_x + 150, base_y + 145, 150, 166, 184, 20, PikaYColor);
	for (int i = 0; i < 5; i++) {
		hdc_arc(base_x + 244+i*15, base_y + 159, 176, -146, -108, 20, PikaYColor);
	}
	////ÃèÏß
	//ÉÏ´ÖÏß
	hdc_arc(base_x + 113, base_y + 389, 181, -11, 28, 20, CULineColor);
	hdc_arc(base_x + 113+2, base_y + 400, 181, -12, 27, 10, CULineColor);
	//ÏÂ´ÖÏß
	hdc_arc(base_x + 244, base_y + 159, 176, -146, -108, 20, CULineColor);
	hdc_arc(base_x + 255, base_y + 159, 176, -146, -108, 8, CULineColor);
	//´ÖÏßÌî³ä
	hdc_triangle(base_x + 84, base_y + 230, base_x + 125, base_y + 243, base_x + 106, base_y + 220,1,2,CULineColor);
	hdc_triangle(base_x + 145, base_y + 311, base_x + 154, base_y + 300, base_x + 170, base_y + 311, 1, 2, CULineColor);
	hdc_triangle(base_x + 199, base_y + 222, base_x + 198, base_y + 242, base_x + 217, base_y + 250, 1, 2, CULineColor);
	hdc_line(base_x + 198, base_y + 220, base_x + 198, base_y + 244, LineTn+1, CULineColor);
	//Ï¸Ïß
	hdc_arc(base_x + 105, base_y + 297, 122, 52, 82, LineTn, LineColor);
	hdc_arc(base_x + 150, base_y + 164, 150, 165, 184, LineTn, LineColor);
	
	////ÓÒ¶ú¶ä////
	hdc_circle(base_x + 323, base_y + 235, 44, 1, 2, PikaYColor);
	hdc_triangle(base_x + 350, base_y + 150, base_x + 300, base_y + 200, base_x + 350, base_y + 200, 1, 2, PikaYColor);

	hdc_arc(base_x + 323, base_y + 235, 44, 75, 189, LineTn, CULineColor);
	hdc_arc(base_x + 323, base_y + 235, 44, 215, 288, LineTn, CULineColor);
	
	////´Ö±ß
	//×ó
	hdc_arc(base_x + 363, base_y + 235, 76, -87, -15, 15, CULineColor);
	hdc_arc(base_x + 363+2, base_y + 235, 76, -65, -15, 15, CULineColor);
	hdc_line(base_x + 292, base_y + 230, base_x + 335, base_y + 165, 16, CULineColor);
	//ÓÒ
	hdc_sector(base_x + 352, base_y + 252, 10, 90, 180, 1, LineTn, CULineColor);
	hdc_rectangle(base_x+352, base_y+175, 12, 75, 0, 1, LineTn, CULineColor);
	//ÉÏ
	hdc_triangle(base_x + 319, base_y + 144, base_x + 323, base_y + 175, base_x + 358, base_y + 175, 1, LineTn, CULineColor);
	hdc_triangle(base_x + 350, base_y + 135, base_x + 323, base_y + 175, base_x + 350, base_y + 175, 1, LineTn, CULineColor);
	hdc_triangle(base_x + 372, base_y + 150, base_x + 323, base_y + 175, base_x + 362, base_y + 175, 1, LineTn, CULineColor);
	hdc_triangle(base_x + 335, base_y + 175, base_x + 335, base_y + 198, base_x + 352, base_y + 175, 1, LineTn, CULineColor);
	//²¹
	hdc_line(base_x + 364, base_y + 250, base_x + 364, base_y + 166, LineTn, CULineColor);
	hdc_triangle(base_x + 280, base_y + 225, base_x + 282, base_y + 248, base_x + 292, base_y + 235, 1, 1, CULineColor);
	hdc_line(base_x + 351, base_y + 265, base_x + 351, base_y + 242, 2, CULineColor);
	hdc_line(base_x + 353, base_y + 264, base_x + 353, base_y + 248, 2, CULineColor);

	
	//Çò
	const int BallColor = FlowerColor;
	hdc_circle(base_x + 463, base_y + 463, 37, 1, 2, LineColor);
	hdc_circle(base_x + 463, base_y + 463, 35, 1, 2, BallColor);

}
