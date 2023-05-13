/* 学号 姓名 班级 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <math.h>
#include <time.h>
using namespace std;

#include "../include/cmd_hdc_tools.h"

static const int PCOLOR_LINE_PINK = RGB(255, 155, 192);
static const int PCOLOR_FILLED_PINK = RGB(245, 180, 217);

static const int PCOLOR_HEAD_LINE = PCOLOR_LINE_PINK;
static const int PCOLOR_HEAD_FILLED = PCOLOR_FILLED_PINK;

static const int PCOLOR_NOSE_LINE = PCOLOR_LINE_PINK;
static const int PCOLOR_NOSE_FILLED = PCOLOR_FILLED_PINK;
static const int PCOLOR_NOSTRIL = RGB(160, 82, 45);

static const int PCOLOR_BODY_LINE = RGB(255, 110, 90);
static const int PCOLOR_BODY_FILLED = RGB(235, 90, 71);

static const int PCOLOR_EARS_LINE = PCOLOR_LINE_PINK;
static const int PCOLOR_EARS_FILLED = PCOLOR_FILLED_PINK;

static const int PCOLOR_HANDS = PCOLOR_LINE_PINK;

static const int PCOLOR_CHEEK = PCOLOR_LINE_PINK;
static const int PCOLOR_EYE = PCOLOR_LINE_PINK;
static const int PCOLOR_EYEBALL = RGB(255, 255, 255);
static const int PCOLOR_PUPILS = RGB(0, 0, 0);

static const int PCOLOR_MOUTH = RGB(239, 69, 19);
static const int PCOLOR_FOOT = RGB(240, 128, 128);
static const int PCOLOR_SHOES = RGB(0, 0, 0);

static const int PCOLOR_TAIL = PCOLOR_LINE_PINK;

static int base_x = 400;
static int base_y = 400;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void nose()
{
	hdc_ellipse(base_x-20, base_y-335, 25, 40, 30, 0, 5, PCOLOR_NOSE_LINE);	//鼻子外圈
	hdc_ellipse(base_x-20, base_y-335, 21, 36, 30, 1, 4, PCOLOR_NOSE_FILLED);//鼻子填充

	hdc_circle(base_x-30, base_y-335, 6, 0, 3, PCOLOR_NOSE_LINE);//鼻孔外圈
	hdc_circle(base_x-30, base_y-335, 3, 1, 3, PCOLOR_NOSTRIL);//鼻孔内圈
	hdc_circle(base_x-10, base_y-335, 6, 0, 3, PCOLOR_NOSE_LINE);//鼻孔外圈
	hdc_circle(base_x-10, base_y-335, 3, 1, 3, PCOLOR_NOSTRIL);//鼻孔内圈
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void head()
{
	//没有任意形状闭合区间的fill函数，因此先把head用画arc的方式填充一下
	hdc_set_pencolor(PCOLOR_HEAD_FILLED);
	hdc_arc(base_x - 20, base_y - 70, 265, 5, 30, 72); //上部的边线
	hdc_arc(base_x + 55, base_y - 415, 132, 207, 221, 46);//下部的边线

	/* head 的边 */
	hdc_arc(base_x-20, base_y-70, 300, 5, 30, 5, PCOLOR_HEAD_LINE); //上部的边线
	hdc_arc(base_x+80, base_y-270, 77, 15, 275, 5, PCOLOR_HEAD_LINE); //脸的圆形外廓
	hdc_circle(base_x+80, base_y-270, 74, 1, 2, PCOLOR_HEAD_FILLED);   //脸的填充
	hdc_arc(base_x+80, base_y-425, 172, 207, 222, 5, PCOLOR_HEAD_LINE);//下部的边线
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void ears()
{
	hdc_ellipse(base_x+60, base_y-375, 18, 35, 15, 0, 5, PCOLOR_EARS_LINE);	//耳朵外圈
	hdc_ellipse(base_x+60, base_y-375, 15, 32, 15, 1, 5, PCOLOR_EARS_FILLED);	//耳朵内圈

	hdc_ellipse(base_x+110, base_y-358, 18, 35, 15, 0, 5, PCOLOR_EARS_LINE);//耳朵外圈
	hdc_ellipse(base_x+110, base_y-358, 15, 32, 15, 1, 5, PCOLOR_EARS_FILLED);	//耳朵内圈
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void eyes()
{
	hdc_circle(base_x+40, base_y-325, 12, 0, 5, PCOLOR_EYE);	//眼睛外圈
	hdc_circle(base_x+40, base_y-325, 8, 1, 5, PCOLOR_EYEBALL);//眼球
	hdc_circle(base_x+40, base_y-325, 3, 1, 3, PCOLOR_PUPILS);	//眼珠（瞳孔）

	hdc_circle(base_x+80, base_y-310, 12, 0, 5, PCOLOR_EYE);//眼睛外圈
	hdc_circle(base_x+80, base_y-310, 8, 1, 5, PCOLOR_EYEBALL);	//眼球
	hdc_circle(base_x+80, base_y-310, 3, 1, 3, PCOLOR_PUPILS);	//眼珠（瞳孔）
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void cheek()
{
	hdc_circle(base_x+100, base_y-255, 27, 1, 1, PCOLOR_CHEEK);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void mouth()
{
	hdc_arc(base_x+60, base_y-255, 30, 165, 260, 5, PCOLOR_MOUTH);

}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void body()
{
	hdc_sector(base_x+130, base_y-50, 180, 270, 345, 1, 5, PCOLOR_BODY_FILLED); //左侧扇形填充
	hdc_arc(base_x+130, base_y-50, 180, 270, 330, 5, PCOLOR_BODY_LINE);//左侧边

	hdc_sector(base_x+5, base_y-50, 180, 30, 90, 1, 5, PCOLOR_BODY_FILLED);//右侧扇形填充
	hdc_arc(base_x+5, base_y-50, 180, 30, 90, 5, PCOLOR_BODY_LINE);//右侧边

	hdc_line(base_x-50, base_y-48, base_x+187, base_y-48, 5, PCOLOR_BODY_LINE); //下面的边
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void hands()
{
	hdc_arc(base_x+80, base_y+175, 320, 325, 30, 5, PCOLOR_HANDS);	//整个胳膊
	hdc_arc(base_x-122, base_y-75, 40, 30, 90, 5, PCOLOR_HANDS);//左边的手（右手）
	hdc_arc(base_x+250, base_y-95, 40, 270, 330, 5, PCOLOR_HANDS);//右边的手（左手）
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void foot()
{
	hdc_rectangle(base_x+20, base_y-50, 7, 50, 0, 1, 1, PCOLOR_FOOT);//左边腿（右腿）
	hdc_rectangle(base_x+115, base_y-50, 7, 50, 0, 1, 1, PCOLOR_FOOT);//右边腿（左腿）

	hdc_rectangle(base_x, base_y, 32, 12, 0, 1, 1, PCOLOR_SHOES); //左边鞋
	hdc_rectangle(base_x+95, base_y, 32, 12, 0, 1, 1, PCOLOR_SHOES); //右边鞋
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void tail()
{
	hdc_arc(base_x+200, base_y-85, 30, 165, 210, 5, PCOLOR_TAIL);//尾巴-身子连圈
	hdc_circle(base_x+215, base_y-65, 10, 0, 5, PCOLOR_TAIL); //尾巴-圈
	hdc_arc(base_x+225, base_y-92, 40, 130, 210, 5, PCOLOR_TAIL);//尾巴-身子连圈
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int hdc_draw_PeppaPig(const int left_shoes_x, const int left_shoes_y)
{
/*  https://www.jianshu.com/p/d1f75fb55bb8
	nose(-100, 100) #鼻子
	head(-69, 167) #头
	ears(0, 160) #耳朵
	eyes(0, 140) #眼睛
	cheek(80, 10) #腮
	mouth(-20, 30) #嘴
	body(-32, -8) #身体
	hands(-56, -45) #手
	foot(2, -177) #脚
	tail(148, -155) #尾巴	*/

	base_x = left_shoes_x;
	base_y = left_shoes_y;

	hands();
	body();
	head();
	nose();
	ears();
	eyes();
	cheek();
	mouth();
	foot();
	tail();

	return 0;
}
