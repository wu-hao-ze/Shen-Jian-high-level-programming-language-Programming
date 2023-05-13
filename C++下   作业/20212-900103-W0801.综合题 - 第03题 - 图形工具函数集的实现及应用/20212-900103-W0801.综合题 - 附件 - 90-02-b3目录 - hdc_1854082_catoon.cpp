/*1854082 信18 金唱*/
#include <iostream>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
using namespace std;

static void hdc_draw_background()
{
	hdc_rectangle(0, 0, 800, 550, 0, 1, 3, RGB(243, 180, 145));
	hdc_rectangle(0, 550, 800, 250, 0, 1, 3, RGB(104, 64, 56));
}

static void hdc_draw_body(const int base_x, const int base_y)
{
	//白色的胖身子
	hdc_sector(base_x + 33, base_y + 75, 180, 250, 290, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 33, base_y + 75, 180, 250, 290, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 41, base_y + 82, 190, 290, 50, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 41, base_y + 82, 190, 290, 50, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 86, base_y + 43, 130, 50, 130, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 86, base_y + 43, 130, 50, 130, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 65, base_y + 22, 160, 130, 155, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 65, base_y + 22, 160, 130, 155, 4, RGB(0, 0, 0));
	hdc_sector(base_x - 88, base_y + 120, 50, 184, 250, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x - 88, base_y + 120, 50, 184, 250, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 95, base_y - 60, 230, 170, 175, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 95, base_y - 60, 230, 170, 175, 4, RGB(0, 0, 0));
	hdc_arc(base_x + 9, base_y - 1226, 1395, 175, 184, 10, RGB(254, 254, 254));
	hdc_arc(base_x + 9, base_y - 1226, 1400, 175, 184, 4, RGB(0, 0, 0));
	hdc_rectangle(base_x - 100, base_y, 220, 160, 0, 1, 4, RGB(254, 254, 254));

	//身上的阴影
	hdc_arc(base_x + 9, base_y - 1226, 1371, 176, 184, 55, RGB(182, 176, 186));
	hdc_sector(base_x + 95, base_y - 60, 227, 170, 175, 1, 4, RGB(182, 176, 186));
	hdc_sector(base_x + 65, base_y + 22, 156, 130, 155, 1, 4, RGB(182, 176, 186));
	hdc_sector(base_x + 97, base_y, 150, 145, 210, 1, 4, RGB(254, 254, 254));
	hdc_sector(base_x - 115, base_y + 67, 100, 140, 170, 1, 4, RGB(254, 254, 254));

	//身上的橙色斑点
	hdc_ellipse(base_x - 39, base_y + 15, 110, 80, 140, 1, 4, RGB(216, 129, 89));
	hdc_arc(base_x + 41, base_y + 81, 168, 290, 40, 40, RGB(216, 129, 89));
	hdc_arc(base_x + 34, base_y + 75, 170, 260, 290, 20, RGB(216, 129, 89));
	hdc_arc(base_x - 83, base_y - 80, 190, 89, 195, 20, RGB(216, 129, 89));
	hdc_point(base_x - 120, base_y + 93, 20, RGB(216, 129, 89));

	//身上的灰色斑点
	hdc_ellipse(base_x + 122, base_y+ 20, 110, 84, 60, 1, 4, RGB(119, 119, 119));

	//项圈
	hdc_ellipse(base_x + 6, base_y + 45, 122, 110, 0, 1, 4, RGB(187, 81, 80));
	hdc_ellipse(base_x + 6, base_y + 45, 122, 110, 0, 0, 4, RGB(0, 0, 0));
	hdc_arc(base_x + 45, base_y + 30, 95, 50, 145, 15, RGB(187, 81, 80));
	hdc_arc(base_x + 45, base_y + 30, 100, 50, 145, 4, RGB(0, 0, 0));

	//铃铛
	hdc_ellipse(base_x - 5, base_y + 152, 17, 13, 10, 1, 4, RGB(244, 212, 153));
	hdc_ellipse(base_x - 5, base_y + 152, 17, 13, 10, 0, 4, RGB(0, 0, 0));
	hdc_point(base_x - 5, base_y + 153, 8, RGB(0, 0, 0));
	hdc_line(base_x - 7, base_y + 153, base_x - 7, base_y + 161, 3, RGB(0, 0, 0));
}

static void hdc_draw_head(const int base_x, const int base_y)
{
	//圆圆的脸和下巴
	hdc_sector(base_x + 92, base_y + 60, 210, 275, 305, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 92, base_y + 60, 210, 275, 305, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 2, base_y + 50, 120, 250, 275, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 2, base_y + 50, 120, 250, 275, 4, RGB(0, 0, 0));
	hdc_sector(base_x - 53, base_y + 73, 60, 200, 250, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x - 53, base_y + 73, 60, 200, 250, 4, RGB(0, 0, 0));
	hdc_arc(base_x + 12, base_y - 107, 230, 165, 201, 40, RGB(254, 254, 254));
	hdc_arc(base_x + 12, base_y - 105, 250, 165, 200, 4, RGB(0, 0, 0));
	hdc_sector(base_x + 60, base_y + 78, 60, 108, 165, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 60, base_y + 78, 60, 110, 165, 4, RGB(0, 0, 0));
	hdc_arc(base_x - 195, base_y - 15, 310, 87, 110, 40, RGB(254, 254, 254));
	hdc_arc(base_x - 193, base_y - 15, 330, 87, 110, 4, RGB(0, 0, 0));

	//两个小耳朵和头顶弧线
	hdc_triangle(base_x + 80, base_y - 70, base_x + 120, base_y, base_x + 145, base_y - 85, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 45, base_y - 83, 100, 92, 128, 10, RGB(254, 254, 254));
	hdc_arc(base_x + 45, base_y - 83, 104, 91, 128, 4, RGB(0, 0, 0));
	hdc_arc(base_x + 185, base_y + 317, 400, -15, -6, 10, RGB(254, 254, 254));
	hdc_arc(base_x + 186, base_y + 310, 397, -16, -6, 4, RGB(0, 0, 0));

	hdc_arc(base_x + 2, base_y + 248, 310, -5, 13, 38, RGB(254, 254, 254));

	hdc_triangle(base_x - 90, base_y - 20, base_x - 55, base_y - 120, base_x - 25, base_y - 70, 1, 4, RGB(254, 254, 254));
	hdc_arc(base_x + 70, base_y - 28, 150, -90, -55, 10, RGB(254, 254, 254));
	hdc_arc(base_x + 70, base_y - 28, 154, -84, -54, 4, RGB(0, 0, 0));
	hdc_arc(base_x - 295, base_y + 62, 300, 55, 65, 10, RGB(254, 254, 254));
	hdc_arc(base_x - 295, base_y + 62, 304, 53, 62, 4, RGB(0, 0, 0));

	//填充整个脸
	hdc_rectangle(base_x - 50, base_y - 78, 160, 170, 10, 1, 4, RGB(254, 254, 254));
}

static void hdc_draw_speckle(const int base_x, const int base_y)
{
	//头顶橙色斑点
	hdc_arc(base_x + 2, base_y + 248, 318, -3, 3, 25, RGB(216, 129, 89));
	hdc_arc(base_x + 143, base_y + 25, 190, -75, -61, 25, RGB(216, 129, 89));
	hdc_arc(base_x + 3, base_y - 10, 45, 200, -75, 25, RGB(216, 129, 89));
	hdc_arc(base_x + 220, base_y + 50, 230, -85, -60, 25, RGB(216, 129, 89));
	hdc_rectangle(base_x - 30, base_y - 60, 30, 70, 5, 1, 4, RGB(216, 129, 89));
	
	//头顶灰色斑点
	hdc_arc(base_x + 2, base_y + 248, 318, 5, 12, 25, RGB(119, 119, 119));
	hdc_arc(base_x + 225, base_y + 47, 230, -86, -59, 25, RGB(119, 119, 119));
	hdc_arc(base_x + 20, base_y - 10, 50, 120, 206, 25, RGB(119, 119, 119));
	hdc_arc(base_x - 32, base_y - 42, 110, 80, 120, 25, RGB(119, 119, 119));
	hdc_rectangle(base_x + 20, base_y - 65, 50, 90, 10, 1, 4, RGB(119, 119, 119));

	hdc_arc(base_x + 2, base_y + 248, 330, -5, 14, 4, RGB(0, 0, 0));
}

static void hdc_draw_fivesenses(const int base_x, const int base_y)
{
	//两只眼睛
	hdc_line(base_x - 40, base_y + 87, base_x - 48, base_y + 82, 3, RGB(0, 0, 0));
	hdc_line(base_x - 48, base_y + 82, base_x - 88, base_y + 78, 3, RGB(0, 0, 0));
	hdc_line(base_x + 28, base_y + 93, base_x + 40, base_y + 91, 3, RGB(0, 0, 0));
	hdc_line(base_x + 36, base_y + 91, base_x + 75, base_y + 91, 3, RGB(0, 0, 0));
	
	//嘴巴
	hdc_line(base_x - 21, base_y + 104, base_x - 14, base_y + 109, 3, RGB(0, 0, 0));
	hdc_line(base_x - 9, base_y + 105, base_x - 22, base_y + 115, 3, RGB(0, 0, 0));
	hdc_line(base_x - 15, base_y + 111, base_x - 2, base_y + 120, 3, RGB(0, 0, 0));

	//猫胡子
	hdc_line(base_x - 88, base_y + 60, base_x - 87, base_y + 66, 3, RGB(0, 0, 0));
	hdc_line(base_x - 96, base_y + 63, base_x - 92, base_y + 70, 3, RGB(0, 0, 0));
	hdc_line(base_x - 103, base_y + 67, base_x - 99, base_y + 73, 3, RGB(0, 0, 0));
	hdc_line(base_x - 85, base_y + 105, base_x - 70, base_y + 104, 3, RGB(0, 0, 0));
	hdc_line(base_x - 80, base_y + 113, base_x - 70, base_y + 111, 3, RGB(0, 0, 0));
	hdc_line(base_x + 65, base_y + 110, base_x + 78, base_y + 112, 3, RGB(0, 0, 0));
	hdc_line(base_x + 62, base_y + 120, base_x + 72, base_y + 123, 3, RGB(0, 0, 0));
	hdc_line(base_x + 76, base_y + 75, base_x + 71, base_y + 80, 3, RGB(0, 0, 0));
	hdc_line(base_x + 86, base_y + 77, base_x + 79, base_y + 83, 3, RGB(0, 0, 0));
	hdc_line(base_x + 97, base_y + 81, base_x + 91, base_y + 84, 3, RGB(0, 0, 0));
}

static void hdc_draw_books(const int base_x, const int base_y)
{
	//右侧的书
	hdc_rectangle(base_x + 170, base_y + 121, 300, 40, 0, 1, 4, RGB(254, 254, 254)); //第一本书
	hdc_rectangle(base_x + 170, base_y + 121, 300, 15, 0, 1, 4, RGB(182, 176, 186));
	hdc_arc(base_x + 518, base_y + 165, 350, -90, -83, 4, RGB(0, 0, 0));
	hdc_arc(base_x + 325, base_y - 1627, 1795, 180, 184, 10, RGB(254, 254, 254));
	hdc_arc(base_x + 325, base_y - 1627, 1800, 180, 185, 4, RGB(0, 0, 0));
	hdc_line(base_x + 320, base_y + 165, base_x + 400, base_y + 165, 10, RGB(254, 254, 254));
	hdc_line(base_x + 320, base_y + 170, base_x + 400, base_y + 170, 4, RGB(0, 0, 0));
	hdc_rectangle(base_x + 157, base_y + 70, 400, 49, 0, 1, 4, RGB(226, 198, 150)); //第二本书
	hdc_line(base_x + 155, base_y + 121, base_x + 400, base_y + 121, 3, RGB(0, 0, 0));
	hdc_line(base_x + 155, base_y + 121, base_x + 157, base_y + 68, 4, RGB(0, 0, 0));
	hdc_line(base_x + 162, base_y + 118, base_x + 164, base_y + 67, 10, RGB(226, 198, 150));
	hdc_line(base_x + 157, base_y + 68, base_x + 400, base_y + 68, 3, RGB(0, 0, 0));
	hdc_line(base_x + 162, base_y + 80, base_x + 250, base_y + 80, 2, RGB(119, 119, 119));
	hdc_rectangle(base_x + 165, base_y + 10, 400, 53, 0, 1, 4, RGB(254, 254, 254)); //第三本书
	hdc_line(base_x + 165, base_y + 8, base_x + 400, base_y + 8, 3, RGB(0, 0, 0));
	hdc_line(base_x + 165, base_y + 10, base_x + 165, base_y + 67, 3, RGB(0, 0, 0));
	hdc_line(base_x + 170, base_y + 15, base_x + 250, base_y + 16, 3, RGB(0, 0, 0));
	hdc_line(base_x + 185, base_y + 35, base_x + 270, base_y + 35, 3, RGB(119, 119, 119));

	//左侧的书
	hdc_arc(base_x - 400, base_y + 500, 495, -3, 5, 10, RGB(80, 110, 138)); //第一本书
	hdc_arc(base_x - 400, base_y + 500, 500, -3, 5, 4, RGB(0, 0, 0));
	hdc_arc(base_x - 393, base_y - 332, 495, 176, 187, 10, RGB(80, 110, 138));
	hdc_arc(base_x - 393, base_y - 332, 500, 176, 187, 4, RGB(0, 0, 0));
	hdc_rectangle(base_x - 400, base_y + 3, 40, 159, 0, 1, 4, RGB(80, 110, 138));
	hdc_line(base_x - 358, base_y - 21, base_x - 358, base_y + 165, 3, RGB(0, 0, 0));
	hdc_rectangle(base_x - 358, base_y - 80, 60, 244, 0, 1, 4, RGB(131, 89, 91)); //第二本书
	hdc_rectangle(base_x - 358, base_y - 80, 62, 246, 0, 0, 3, RGB(0, 0, 0));
	hdc_line(base_x - 358, base_y - 50, base_x - 298, base_y - 50, 3, RGB(0, 0, 0));
	hdc_rectangle(base_x - 156, base_y + 145, 60, 240, 160, 1, 3, RGB(87, 81, 95));  //第三本书
	hdc_rectangle(base_x - 156, base_y + 145, 62, 242, 160, 0, 3, RGB(0, 0, 0));
	hdc_line(base_x - 244, base_y + 78, base_x - 191, base_y + 55, 10, RGB(226, 198, 150));
}


void hdc_draw_catoon_1854082(const int base_x, const int base_y)
{
	hdc_cls();
	hdc_draw_background();
	hdc_draw_body(base_x, base_y);
	hdc_draw_head(base_x, base_y);
	hdc_draw_speckle(base_x, base_y);
	hdc_draw_fivesenses(base_x, base_y);
	hdc_draw_books(base_x, base_y);
}