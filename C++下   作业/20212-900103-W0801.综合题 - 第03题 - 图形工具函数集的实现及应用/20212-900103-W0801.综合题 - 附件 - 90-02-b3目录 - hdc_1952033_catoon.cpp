/* 1952033 ÐÅ12 ºîÑÅ«h */
#include <iostream>
#include <cmath>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;
const int FACE_YELLOW = RGB(231, 199, 186);
const int HAIR_YELLOW = RGB(41, 41, 41);
const int EYE_WHITE = RGB(242, 255, 250);
const int EYE_BLACK = RGB(60, 54, 54);
const int EYE_BROWN = RGB(140, 80, 60);
const int SIG_RED = RGB(173, 62, 51);
const int QK_CIRCLE = RGB(240, 200, 69);
const int QK_BORDER = RGB(205, 168, 65);
const int EAR = RGB(149, 114, 86);
void hdc_draw_catoon_1952033(const int base_x, const int base_y)
{
	int b_x=base_x,b_y=base_y;
	if (b_x < 0)
		b_x= 1;
	if (b_y < 0)
		b_y = 1;
	while (b_x > 100)
		b_x -=100 ;
	while(b_y >100)
		b_y -=100;
	
	hdc_cls();
	//±³¾°
	hdc_rectangle(b_x - 100, b_y - 100, 600, 600, 0, true, 1, EYE_WHITE);


	//²±×ÓÍ··¢	
	hdc_sector(b_x + 51, b_y + 238, 63, 90, 190, true, 1, HAIR_YELLOW);
	hdc_circle(b_x + 1, b_y + 232, 83, true, 1, EYE_WHITE);
	hdc_sector(b_x + 237, b_y + 266, 96, 60, 128, true, 1, HAIR_YELLOW);

	//hdc_sector(b_x +197, b_y + 300, 106, 60, 128, true, 1, HAIR_YELLOW);
	hdc_circle(b_x + 197, b_y + 300, 106, true, 1, EYE_WHITE);
	hdc_sector(b_x + 211, b_y + 259, 110, 90, 180, true, 1, HAIR_YELLOW);

	hdc_sector(b_x + 156, b_y + 264, 93, 60, 150, true, 1, HAIR_YELLOW);
	hdc_sector(b_x + 94, b_y + 311, 66, 90, 150, true, 1, EYE_WHITE);
	//hdc_circle(b_x +94, b_y + 311, 66, true, 1, EYE_WHITE);

	hdc_sector(b_x + 155, b_y + 327, 83, -90, -53, true, 1, HAIR_YELLOW);
	hdc_sector(b_x + 124, b_y + 205, 145, 152, 188, true, 1, HAIR_YELLOW);
	hdc_circle(b_x + 91, b_y + 325, 29, true, 1, EYE_WHITE);
	//	hdc_arc(b_x + 188, b_y + 196, 90, 148, 188, 1, HAIR_YELLOW);
	hdc_sector(b_x + 86, b_y + 228, 103, 148, 188, true, 1, HAIR_YELLOW);

	//	hdc_circle(b_x +155, b_y + 327, 83, true, 1, HAIR_YELLOW);
	//	hdc_circle(b_x + 86, b_y + 228, 103, true, 1, HAIR_YELLOW);
	hdc_rectangle(b_x + 179, b_y + 325, 56, 72, 0, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 167, b_y + 338, 84, 25, 0, true, 1, FACE_YELLOW);

	hdc_sector(b_x + 149, b_y + 342, 31, 70, 150, true, 1, HAIR_YELLOW);
	hdc_circle(b_x + 253, b_y + 344, 15, true, 1, HAIR_YELLOW);
	hdc_rectangle(b_x + 132, b_y + 370, 49, 29, -16, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 233, b_y + 356, 51, 23, 13, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 274, b_y + 385, 35, 20, 11, true, 1, FACE_YELLOW);
	hdc_sector(b_x + 291, b_y + 398, 24, -90, 90, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 138, b_y + 400, 27, 30, 0, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 141, b_y + 378, 143, 35, 0, true, 1, FACE_YELLOW);


	hdc_rectangle(b_x + 240, b_y + 358, 35, 43, 8, true, 1, SIG_RED);
	hdc_rectangle(b_x + 238, b_y + 358, 37, 43, 8, false, 3, QK_CIRCLE);
	hdc_rectangle(b_x + 144, b_y + 372, 33, 33, 0, true, 1, SIG_RED);
	hdc_rectangle(b_x + 142, b_y + 372, 35, 33, 0, false, 3, QK_CIRCLE);
	hdc_rectangle(b_x + 143, b_y + 365, 26, 21, -22, true, 1, SIG_RED);


	//Ç¬À¤È¦
	hdc_ellipse(b_x + 207, b_y + 364, 53, 33, 0, true, 1, QK_CIRCLE);
	hdc_ellipse(b_x + 208, b_y + 363, 41, 23, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 207, b_y + 364, 53, 33, 0, false, 3, QK_BORDER);
	hdc_ellipse(b_x + 208, b_y + 363, 41, 23, 0, false, 3, QK_BORDER);
	hdc_rectangle(b_x + 179, b_y + 327, 56, 25, 0, true, 1, FACE_YELLOW);


	//×óÃ«
	hdc_rectangle(b_x + 30, b_y + 80, 66, 38, 0, true, 1, SIG_RED);
	hdc_circle(b_x + 21, b_y + 132, 26, true, 1, SIG_RED);
	hdc_ellipse(b_x + 21, b_y + 59, 68, 48, 0, true, 1, EYE_WHITE);

	//hdc_ellipse(b_x + 12, b_y + 136, 24, 90, 150, true, 1, EYE_WHITE);
	hdc_circle(b_x + 12, b_y + 136, 24, true, 1, EYE_WHITE);
	hdc_circle(b_x + 51, b_y + 151, 39, true, 1, SIG_RED);
	hdc_circle(b_x + 70, b_y + 158, 27, true, 1, EYE_WHITE);
	hdc_rectangle(b_x + 83, b_y + 107, 28, 46, 43, true, 1, EYE_WHITE);


	//Á³
	hdc_ellipse(b_x + 197, b_y + 284, 85, 47, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 157, b_y + 268, 75, 52, 15, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 261, b_y + 248, 82, 61, 133, true, 1, FACE_YELLOW);


	hdc_ellipse(b_x + 148, b_y + 172, 70, 148, 0, true, 1, FACE_YELLOW);

	hdc_ellipse(b_x + 197, b_y + 93, 109, 84, 0, true, 1, FACE_YELLOW);

	//×ó¶ú
	hdc_ellipse(b_x + 68, b_y + 215, 18, 35, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 79, b_y + 236, 22, 22, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 69, b_y + 222, 12, 23, -9, false, 1, EAR);
	hdc_arc(b_x + 87, b_y + 220, 18, 210, 320, 1, EAR);
	hdc_arc(b_x + 72, b_y + 217, 12, -40, 20, 1, EAR);


	//¶îÍ·Í··¢
	hdc_ellipse(b_x + 249, b_y + 144, 102, 121, 0, true, 1, FACE_YELLOW);

	hdc_rectangle(b_x + 260, b_y + 174, 66, 43, -8, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 158, b_y + 156, 167, 30, -7, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 81, b_y + 196, 110, 77, -3, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 171, b_y + 68, 148, 77, -2, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 87, b_y + 140, 17, 60, 6, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 148, b_y + 172, 70, 148, 0, true, 1, FACE_YELLOW);
	hdc_sector(b_x + 197, b_y + 132, 124, -90, 90, true, 1, HAIR_YELLOW);
	hdc_sector(b_x + 223, b_y + 142, 127, 90, 90, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 107, b_y + 120, 8, 20, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 110, b_y + 112, 8, 18, 0, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 132, b_y + 120, 7, 24, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 144, b_y + 109, 15, 27, -8, true, 1, HAIR_YELLOW);


	hdc_ellipse(b_x + 192, b_y + 101, 10, 52, 2, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 215, b_y + 99, 25, 64, -12, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 225, b_y + 100, 20, 50, -16, true, 1, FACE_YELLOW);

	hdc_ellipse(b_x + 239, b_y + 87, 34, 62, -20, true, 1, HAIR_YELLOW);



	hdc_ellipse(b_x + 293, b_y + 125, 15, 15, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 291, b_y + 118, 13, 21, 0, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 262, b_y + 123, 15, 29, -24, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 225, b_y + 83, 32, 62, -20, true, 1, HAIR_YELLOW);

	hdc_rectangle(b_x + 87, b_y + 129, 102, 93, -8, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 272, b_y + 125, 41, 23, 6, true, 1, FACE_YELLOW);

	//ÓÒ¶ú
	hdc_rectangle(b_x + 203, b_y + 142, 119, 83, -8, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 200, b_y + 125, 75, 41, 0, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 161, b_y + 124, 50, 44, 4, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 106, b_y + 128, 154, 157, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 357, b_y + 201, 22, 24, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 358, b_y + 225, 13, 29, 30, true, 1, FACE_YELLOW);
	hdc_triangle(b_x + 329, b_y + 212, b_x + 329, b_y + 212, b_x + 329, b_y + 212, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 314, b_y + 234, 65, 26, -59, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 296, b_y + 232, 45, 38, 0, true, 1, FACE_YELLOW);
	hdc_ellipse(b_x + 354, b_y + 215, 10, 27, 19, false, 1, EAR);
	hdc_arc(b_x + 346, b_y + 216, 20, 15, 90, 1, EAR);
	hdc_arc(b_x + 340, b_y + 218, 14, 25, 180, 1, EAR);





	//hdc_line(b_x + 183, b_y + 140, b_x + 183, b_y + 90,1);
	//hdc_line(b_x + 183, b_y + 140, b_x + 210, b_y + 139,1);
	//hdc_line(b_x + 210, b_y + 139, b_x + 183, b_y + 90, 1);
	//hdc_line(b_x + 185, b_y + 57, b_x + 188, b_y + 113, 1);
	//hdc_line(b_x + 188, b_y +57, b_x + 190, b_y + 107, 1);
	//hdc_line(b_x + 188, b_y + 57, b_x + 183, b_y +93, 1);
	hdc_ellipse(b_x + 352, b_y + 42, 26, 37, -20, true, 1, HAIR_YELLOW);
	hdc_ellipse(b_x + 331, b_y + 24, 19, 25, 61, true, 1, HAIR_YELLOW);
	hdc_ellipse(b_x + 337, b_y + 59, 42, 29, 0, true, 1, HAIR_YELLOW);

	hdc_ellipse(b_x + 100, b_y + 55, 36, 39, 0, true, 1, HAIR_YELLOW);

	//Ã¼Ã«
	hdc_ellipse(b_x + 234, b_y + 182, 64, 43, 0, true, 1, HAIR_YELLOW);
	hdc_ellipse(b_x + 234, b_y + 184, 66, 36, 0, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 159, b_y + 138, 49, 124, -6, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 189, b_y + 180, 127, 79, 0, true, 1, FACE_YELLOW);



	hdc_ellipse(b_x + 137, b_y + 184, 50, 32, -6, true, 1, HAIR_YELLOW);
	hdc_ellipse(b_x + 130, b_y + 192, 46, 30, -10, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 173, b_y + 152, 60, 95, 32, true, 1, FACE_YELLOW);








	//ÑÛ¾¦
//	hdc_triangle(b_x + 185, b_y + 57, b_x + 188, b_y +113, b_x +183, b_y +91, true, 1, FACE_YELLOW);
	//hdc_triangle(b_x + 183, b_y + 139, b_x +195, b_y + 139, b_x +183, b_y + 89, true, 1, FACE_YELLOW);
	//hdc_sector(b_x + 120, b_y + 193, 45, 145, 215, true, 1, EYE_BLACK);
	//hdc_sector(b_x + 136, b_y + 185,54, 150, 210, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 115, b_y + 206, 25, 34, 18, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 135, b_y + 208, 25, 37, -34, true, 1, EYE_BLACK);

	hdc_ellipse(b_x + 135, b_y + 212, 23, 35, -28, true, 1, EYE_WHITE);
	hdc_ellipse(b_x + 115, b_y + 210, 19, 30, 24, true, 1, EYE_WHITE);
	hdc_rectangle(b_x + 91, b_y + 228, 74, 24, 0, true, 1, FACE_YELLOW);

	hdc_ellipse(b_x + 129, b_y + 227, 31, 8, 0, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 110, b_y + 227, 18, 8, 0, true, 1, EYE_BLACK);
	hdc_rectangle(b_x + 93, b_y + 219, 66, 9, 0, true, 1, EYE_WHITE);


	hdc_sector(b_x + 120, b_y + 218, 39, 34, 78, true, 1, EYE_BROWN);
	hdc_triangle(b_x + 118, b_y + 219, b_x + 125, b_y + 203, b_x + 137, b_y + 215, true, 1, EYE_WHITE);
	hdc_rectangle(b_x + 102, b_y + 208, 31, 14, 0, true, 1, EYE_WHITE);

	hdc_sector(b_x + 142, b_y + 200, 20, 121, 364, true, 1, EYE_BROWN);
	hdc_sector(b_x + 156, b_y + 200, 12, 150, -40, true, 1, EYE_BLACK);
	hdc_circle(b_x + 144, b_y + 203, 3, true, 1, EYE_WHITE);







	hdc_ellipse(b_x + 262, b_y + 205, 44, 40, 0, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 225, b_y + 218, 10, 25, 0, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 260, b_y + 220, 41, 51, 0, true, 1, EYE_WHITE);

	hdc_rectangle(b_x + 216, b_y + 220, 85, 61, 0, true, 1, FACE_YELLOW);



	//hdc_ellipse(b_x + 267, b_y + 216, 32, 44, 0, true, 1, EYE_WHITE);


	hdc_ellipse(b_x + 258, b_y + 222, 43, 12, 0, true, 1, EYE_BLACK);
	hdc_ellipse(b_x + 260, b_y + 220, 40, 8, 0, true, 1, EYE_WHITE);

	hdc_rectangle(b_x + 221, b_y + 207, 75, 16, 0, true, 1, EYE_WHITE);
	hdc_sector(b_x + 260, b_y + 206, 37, -22, 24, true, 1, EYE_BROWN);
	hdc_triangle(b_x + 260, b_y + 214, b_x + 251, b_y + 197, b_x + 273, b_y + 198, true, 1, EYE_WHITE);
	hdc_sector(b_x + 262, b_y + 185, 21, 56, 307, true, 1, EYE_BROWN);
	hdc_circle(b_x + 263, b_y + 181, 12, true, 1, EYE_BLACK);
	hdc_circle(b_x + 258, b_y + 189, 3, true, 1, EYE_WHITE);


	//hdc_arc(b_x + 188, b_y + 196, 90, 157, 215, 2, HAIR_YELLOW);
	//hdc_arc(b_x + 145, b_y + 260, 29, 215, 265, 2, HAIR_YELLOW);
	//hdc_line(b_x + 126, b_y + 264, b_x + 118, b_y + 264);



	hdc_ellipse(b_x + 179, b_y + 262, 57, 27, 9, false, 2, HAIR_YELLOW);
	hdc_rectangle(b_x + 191, b_y + 226, 23, 95, 79, true, 1, FACE_YELLOW);
	hdc_rectangle(b_x + 195, b_y + 217, 97, 31, 40, true, 1, FACE_YELLOW);
	hdc_line(b_x + 127, b_y + 263, b_x + 118, b_y + 263, 2, HAIR_YELLOW);

	//hdc_circle(b_x + 190, b_y + 124, 15, true, 1, SIG_RED);
	//hdc_ellipse(b_x +191, b_y + 123, 9,8, -23, false, 2, HAIR_YELLOW);

	//·¢´ø
	hdc_arc(b_x + 190, b_y + 122, 15, 180, 45, 8, SIG_RED);
	hdc_arc(b_x + 190, b_y + 128, 9, 25, 181, 8, SIG_RED);
	hdc_arc(b_x + 193, b_y + 121, 6, -135, 30, 8, SIG_RED);

	hdc_arc(b_x + 296, b_y + 79, 104, 246, 270, 13, HAIR_YELLOW);
	hdc_rectangle(b_x + 172, b_y + 106, 9, 9, 0, true, 1, HAIR_YELLOW);






	//ÓÒ·¢´ø
	hdc_arc(b_x + 343, b_y + 143, 28, 33, 150, 22, SIG_RED);
	hdc_circle(b_x + 366, b_y + 112, 18, true, 1, SIG_RED);
	hdc_triangle(b_x + 339, b_y + 82, b_x + 375, b_y + 96, b_x + 348, b_y + 112, true, 1, SIG_RED);
	hdc_triangle(b_x + 368, b_y + 113, b_x + 365, b_y + 120, b_x + 353, b_y + 111, true, 1, EYE_WHITE);
	hdc_rectangle(b_x + 308, b_y + 33, 22, 11, 40, true, 1, SIG_RED);

	hdc_ellipse(b_x + 311, b_y + 71, 25, 30, -32, true, 1, SIG_RED);
	hdc_ellipse(b_x + 300, b_y + 73, 26, 45, -42, true, 1, HAIR_YELLOW);



	
	//±ßÔµ´¦Àí
	hdc_rectangle(b_x + 0, b_y + 399, 400, 40, 0, true, 1, EYE_WHITE);

}
