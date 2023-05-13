/* 学号 姓名 班级 */
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

enum TEST_ITEM {
	T_MIN = 0,
	T_POINT = 0,
	T_LINE,
	T_TRIANGLE,
	T_RECTANGLE,
	T_SQUARE,
	T_ARC,
	T_SECTOR,
	T_CIRCLE,
	T_ELLIPSE,
	T_PEPPAPIG,
	T_MATHCURVE,
	T_CUSTOM,
	T_MAX
};

static char need_enter = '1';   //调试用全局量，置1表示回车继续，置0表示自动运行

/***************************************************************************
  函数名称：
  功    能：选择要测试的项目
  输入参数：
  返 回 值：
  说    明：打印时每2字节一组，提示必须全中文，否则会乱
***************************************************************************/
int select_test_item(char test_choice[])
{
	struct {
		enum TEST_ITEM no;
		const char* prompt;
		int len;
	} item[] = {
		{T_POINT,     "点"},
		{T_LINE,      "线"},
		{T_TRIANGLE,  "三角形"},
		{T_RECTANGLE, "矩形"},
		{T_SQUARE,    "正方形"},
		{T_ARC,       "弧"},
		{T_SECTOR,    "扇形"},
		{T_CIRCLE,    "圆"},
		{T_ELLIPSE,   "椭圆"},
		{T_PEPPAPIG,  "小猪佩奇"},
		{T_MATHCURVE, "自定义曲线"},
		{T_CUSTOM,    "创意"},
		{T_MAX,       NULL}
	};

	int i, max_len = 0;

	/* 求所有提示字符串的最大长度 */
	for (i = 0; item[i].prompt; i++) {
		item[i].len = strlen(item[i].prompt);
		if (max_len < item[i].len)
			max_len = item[i].len;
	}

	int line, pos;
	cout << endl << endl;
	cout << "在每个项目下输入0/1(c重新输入)" << endl;
	cout << setw(T_MAX * 3) << setfill('-') << "-" << endl;
	for (line = 0; line < max_len / 2; line++) {
		for (i = T_MIN; i < T_MAX; i++) {
			/* 第line行需要打印 item[i].prompt[item[i].len + i*2 - max_len]开始的两个字符（不存在则打印两个空格）*/
			pos = item[i].len + line * 2;
			if (pos < max_len)
				cout << "   ";
			else {
				cout << item[i].prompt[pos - max_len] << item[i].prompt[pos - max_len + 1] << ' ';
			}
		}//end of for i
		cout << endl;
	}//end of for line
	cout << setw(T_MAX * 3) << setfill('-') << "-" << endl;

	for (i = T_MIN; i < T_MAX; i++) {
		while (1) {
			test_choice[i] = _getch();
			if (test_choice[i] == '0' || test_choice[i] == '1') {
				putchar(test_choice[i]);
				putchar(' '); //为了和上面对齐，多打印两个空格
				putchar(' ');
				break;
			}
			else if (test_choice[i] == 'c' || test_choice[i] == 'C') { //输入c则全部重来
				return -1;
			}
		}
	}
	Sleep(300); //停顿一下，为了看清楚最后一个1
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：显示提示信息
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void to_be_continued(const char* prompt, const int X = 0, const int Y = 22)
{
	//先输出一行空格，为了清空上次字符串比本次长而多出来的后续部分
	cct_gotoxy(X, Y);
	cout << "                                                                                          " << endl;

	//恢复缺省黑白
	cct_setcolor();

	cct_gotoxy(X, Y);
	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	if (need_enter == '1') {
		/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
		while (_getch() != '\r')
			;
	}

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	const int   win_width = 800, win_high = 800;	//设定屏幕宽度
	const int   win_bgcolor = COLOR_WHITE, win_fgcolor = COLOR_HRED;
	const int   color[] = { 0x00FF0000, 0x0000FF00, 0x000000FF }; //R G B
	const int   STL_X = 0, STL_Y = win_high / 16 - 5;	//状态行的起始坐标
	const char* fill_str[] = { "空心", "实心" };

	char test_choise[1024] = "111111111111";
	char tmp[80];
	int i, round;
	int delay_ms = 0; //初始为不延时

#if 1
	cout << "请选择自动演示(0)还是单步演示(1) : ";
	while (1) {
		need_enter = _getch();
		if (need_enter == '0' || need_enter == '1') {
			putchar(need_enter);
			break;
		}
	}
	while (select_test_item(test_choise) != 0)
		;

	if (need_enter == '1') {
		cout << endl << endl << "请输入延时(>=0，ms) : ";
		cin >> delay_ms; //未判断输入错误
	}
#endif

	long t_end, t_start = GetTickCount(); //取当前系统时间，单位毫秒，精度55ms

	srand((unsigned int)time(0));

	hdc_init(win_bgcolor, win_fgcolor, win_width, win_high);		//用(背景色，前景色，宽度，高度）初始化窗口

	/* 设置延时时的延时，0表示不延时，单位ms */
	hdc_set_delay(delay_ms);

	//画点函数测试
	if (test_choise[T_POINT] == '1') {
		/* 先来一个点的直径过大的演示 */
		hdc_set_delay(0); //此处如果延时的话，太慢了
		hdc_point(300, 200, 100, RGB(rand() % 255, rand() % 255, rand() % 255));
		hdc_point(300, 350, 150, RGB(rand() % 255, rand() % 255, rand() % 255));
		hdc_point(300, 550, 200, RGB(rand() % 255, rand() % 255, rand() % 255));
		to_be_continued("这是几个过粗而导致未完全填充的点", STL_X, STL_Y);

		hdc_set_delay(delay_ms);

		/* 50个粗细为3的点 */
		hdc_set_pencolor(255, 0, 0);//红
		for (i = 0; i < 50; i++)
			hdc_point(100 + i * 10, 100, 3);

		/* 50个粗细为5的点 */
		for (i = 0; i < 50; i++)
			hdc_point(100, 150 + 10 * i, 5, RGB(0, 255, 0)); //黄

		/* 20个粗细为10的点 */
		for (i = 0; i < 20; i++)
			hdc_point(120 + 25 * i, 120 + 25 * i, 10, RGB(0, 0, 255)); //蓝

		to_be_continued("继续测试随机画点", STL_X, STL_Y);

		//随机显示100个白点
		for (i = 0; i < 100; i++) {
			int x, y;

			x = rand() % win_width;
			y = rand() % win_high;
			/* 点的大小1~20，颜色随机 */
			hdc_point(x, y, 1 + rand() % 20, RGB(rand() % 255, rand() % 255, rand() % 255)); //点的粗细1-10
			Sleep(1);
		}
		to_be_continued("画点测试完成", STL_X, STL_Y);
	}

	//划线函数测试
	if (test_choise[T_LINE] == '1') {
		hdc_cls();

		/* 横线(双向) */
		hdc_line(100, 100, 500, 100, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(500, 110, 100, 110, 3, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 竖线(双向) */
		hdc_line(100, 120, 100, 500, 5, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(110, 500, 110, 120, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 45度斜线(双向) */
		hdc_line(130, 130, 500, 500, 3, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(510, 500, 140, 130, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 45度斜线(双向) */
		hdc_line(130, 500, 500, 130, 4, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(510, 130, 140, 500, 5, RGB(rand() % 256, rand() % 256, rand() % 256));

		/* 接近于平行于x/y轴的直线 */
		hdc_line(150, 300, 600, 330, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
		hdc_line(150, 350, 600, 350, 4, RGB(rand() % 256, rand() % 256, rand() % 256));

		to_be_continued("继续测试随机画直线", STL_X, STL_Y);

		//随机显示20根随机颜色的线
		for (i = 0; i < 20; i++) {
			int x1, y1, x2, y2;

			x1 = rand() % win_width;
			y1 = rand() % win_high;
			x2 = rand() % win_width;
			y2 = rand() % win_high;
			/* 线的粗细 1~5，颜色随机 */
			hdc_line(x1, y1, x2, y2, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
			Sleep(1);
		}
		to_be_continued("画线测试完成", STL_X, STL_Y);
	}

	//画三角形函数测试
	if (test_choise[T_TRIANGLE] == '1') {
		hdc_cls();

		//随机显示20个三角形
		for (i = 0; i < 20; i++) {
			int x1, y1, x2, y2, x3, y3;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x1 = rand() % (win_width);
			y1 = rand() % (win_high);
			x2 = rand() % (win_width);
			y2 = rand() % (win_high);
			x3 = rand() % (win_width);
			y3 = rand() % (win_high);
			hdc_triangle(x1, y1, x2, y2, x3, y3, i % 2, 2 + rand() % 5); //i%2使空心实心交替
			Sleep(500);
		}
		to_be_continued("画三角形测试完成", STL_X, STL_Y);
	}

	//画矩形函数测试
	if (test_choise[T_RECTANGLE] == '1') {
		hdc_cls();

		/* 两轮测试，先空心再实心 */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "下面要显示%s矩形，旋转 %d 度", fill_str[round % 2], i); //可以直接fill_str[round]，加round%2是为了防止溢出
				to_be_continued(tmp, 0, 0);
				//				hdc_rectangle(350, 350, 300 - round*30, 200 - round * 20, i, round, 1+rand()%5, RGB(rand()%256, rand()%256, rand()%256));	//随机色(醒目程度不如预置三色轮转)
				hdc_rectangle(350, 350, 300 - round * 30, 200 - round * 20, i, round, 2 + rand() % 5, color[i / 15 % 3]); //预置三色轮转
			}

		to_be_continued("继续测试随机画矩形", STL_X, STL_Y);

		hdc_cls();
		//随机显示20个矩形
		for (i = 0; i < 20; i++) {
			int x, y, w, h, angle;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);

			x = rand() % win_width;
			y = rand() % win_high;
			w = rand() % (win_width - x);
			h = rand() % (win_high - y) * 2 / 3;
			angle = rand() % 360;
			hdc_rectangle(x, y, w, h, angle, i % 2, 2 + rand() % 5); //i%2使空心实心交替
			Sleep(100);
		}
		to_be_continued("画矩形测试完成", STL_X, STL_Y);
	}

	//画正方形函数测试
	if (test_choise[T_SQUARE] == '1') {
		hdc_cls();

		/* 先测试空心正方形的旋转，目的是为了验证旋转的的正确性 */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "下面要显示%s正方形，旋转 %d 度", fill_str[round % 2], i); //可以直接fill_str[round]，加round%2是为了防止溢出
				to_be_continued(tmp, 0, 0);
				//				hdc_square(350, 350, 300 - round * 30, i, round, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256)); //随机色(醒目程度不如预置三色轮转)
				hdc_square(350, 350, 300 - round * 30, i, round, 2 + rand() % 5, color[i / 15 % 3]); //预置三色轮转
			}

		to_be_continued("继续测试随机画正方形", STL_X, STL_Y);
		hdc_cls();

		//随机显示20个正方形
		for (i = 0; i < 20; i++) {
			int x, y, length;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = rand() % (win_width / 2);
			y = rand() % (win_high / 2);
			length = rand() % (win_width / 4 * 3);
			hdc_square(x, y, length, rand() % 360, i % 2, 2 + rand() % 5); //i%2使空心实心交替
			Sleep(100);
		}
		to_be_continued("画正方形测试完成", STL_X, STL_Y);
	}

	//划圆弧函数测试
	if (test_choise[T_ARC] == '1') {
		hdc_cls();

		/* 无名结构体的使用示例，仅if内有效 */
		struct {
			int angle_begin, angle_end;
		} t[] = {
		{180,900},
			{0, 60},
			{-360, 60},
			{-45, 45},
			{45, -45},
			{45, 135},
			{90, 180},
			{90, 270},
			{225, 360},
			{300, 90},
			{0, 360},	//整圆
			{0, 0},		//整圆	
			{540, 180},	//整圆
			{180, 181},	//一点
			{181, 180},	//整圆差一点
			{-1, -1},
		};

		/* 先测试几个指定大小的，目的是为了验证角度计算的正确性 */
		for (i = 0; t[i].angle_begin != -1 && t[i].angle_end != -1; i++) {
			char tmp[80];
			sprintf(tmp, "下面要显示圆弧：%d ~ %d", t[i].angle_begin, t[i].angle_end);
			to_be_continued(tmp, 0, 0);
			//			hdc_arc(350, 350, 200+i*10, t[i].angle_begin, t[i].angle_end, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256));
			hdc_arc(350, 350, 200 + i * 10, t[i].angle_begin, t[i].angle_end, 2 + rand() % 5, color[i % 3]);
		}

		to_be_continued("继续测试随机画圆弧", STL_X, STL_Y);

		hdc_cls();
		//随机显示20个圆弧
		for (i = 0; i < 20; i++) {
			int x, y, r, angle_begin, angle_end;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_width / 4);
			angle_begin = rand() % 360;
			angle_end = rand() % 360;
			hdc_arc(x, y, r, angle_begin, angle_end, 2 + rand() % 5);
		}
		to_be_continued("画圆弧测试完成", STL_X, STL_Y);
	}

	//画扇形函数测试
	if (test_choise[T_SECTOR] == '1') {
		hdc_cls();

		/* 无名结构体的使用示例，仅if内有效 */
		struct {
			int angle_begin, angle_end;
		} t[] = {
			{0, 135},	//半圆以内的扇区
			{45, 135},
			{225, 360},
			{-45, 45},
			{90, 180},
			{90, 270},
			{300, 90},
			{180, 181},	//一点
			{45, -45},	//超过半圆的扇区
			{225, 135},
			{135, 45},
			{-45, 225},
			{186, 185},	//整圆差一点
			{0, 360},	//整圆
			{0, 0},		//整圆	
			{540, 180},	//整圆
			{-1, -1},
		};

		/* 先测试几个指定大小的，目的是为了验证角度计算的正确性 */
		for (round = 0; round <= 1; round++)
			for (i = 0; t[i].angle_begin != -1 && t[i].angle_end != -1; i++) {
				sprintf(tmp, "下面要显示%s扇形：%d ~ %d", fill_str[round % 2], t[i].angle_begin, t[i].angle_end); //可以直接fill_str[round]，加round%2是为了防止溢出
				to_be_continued(tmp, 0, 0);

				//				hdc_sector(350, 350, 200 - round * 20 + i * 10, t[i].angle_begin, t[i].angle_end, round, 2+rand()%5, RGB(rand() % 256, rand() % 256, rand() % 256)); //随机色(醒目程度不如预置三色轮转)
				hdc_sector(350, 350, 200 - round * 20 + i * 10, t[i].angle_begin, t[i].angle_end, round, 2 + rand() % 5, color[i % 3]);	//预置三色轮换
			}

		to_be_continued("继续测试随机画扇形", STL_X, STL_Y);

		hdc_cls();

		//再随机显示20个扇形
		for (i = 0; i < 20; i++) {
			int x, y, r, angle_begin, angle_end;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_width / 4);
			angle_begin = rand() % 360;
			angle_end = rand() % 360;
			hdc_sector(x, y, r, angle_begin, angle_end, i % 2, 1 + rand() % 5);//i%2使空心实心交替
		}
		to_be_continued("画扇形测试完成", STL_X, STL_Y);

		/* 吃个豆子吧 */
		for (i = 0; i < 20; i++) {
			const int c = 0x000000FF; //蓝
			//张嘴
			hdc_sector(100 + i * 20, 500, 10, 135, 45, 1, 2, c);//i%2使空心实心交替
			Sleep(200);
			//闭嘴
			hdc_sector(100 + i * 20, 500, 10, 90, 450, 1, 2, c);//i%2使空心实心交替
			Sleep(100);
			//消失
			hdc_sector(100 + i * 20, 500, 10, 90, 450, 1, 2, 0x00CCCCCC);
			Sleep(100);
		}
		to_be_continued("吃豆子测试完成", STL_X, STL_Y);
	}

	//画圆函数测试
	if (test_choise[T_CIRCLE] == '1') {
		hdc_cls();

		//随机显示20个圆
		for (i = 0; i < 20; i++) {
			int x, y, r;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = (win_width / 4) + rand() % (win_width / 2);
			y = (win_high / 4) + rand() % (win_high / 2);
			r = rand() % (win_high / 4);
			hdc_circle(x, y, r, i % 2, 2 + rand() % 5); //i%2使空心实心交替
		}
		to_be_continued("画圆测试完成", STL_X, STL_Y);
	}

	//椭圆函数测试
	if (test_choise[T_ELLIPSE] == '1') {
		hdc_cls();

		/* 先测试椭圆的旋转，目的是为了验证旋转的的正确性 */
		for (round = 0; round <= 1; round++)
			for (i = 0; i < 360; i += 15) {
				sprintf(tmp, "下面要显示%s椭圆，旋转 %d 度", fill_str[round % 2], i); //可以直接fill_str[round]，加round%2是为了防止溢出
				to_be_continued(tmp, 0, 0);
				hdc_ellipse(350, 350, 300 - round * 20, 200 - round * 20, i, round, 2 + rand() % 5, color[i / 15 % 3]);	//预置三色轮换
			}

		to_be_continued("继续测试随机画椭圆", STL_X, STL_Y);

		hdc_cls();
		//随机显示20个椭圆
		for (i = 0; i < 20; i++) {
			int x, y, a, b, angle;

			hdc_set_pencolor(rand() % 256, rand() % 256, rand() % 256);
			x = win_width / 4 + rand() % (win_width / 2);
			y = win_high / 4 + rand() % (win_high / 2);
			a = win_width / 10 + rand() % (win_width / 4);
			b = win_high / 40 + rand() % (win_high / 4);
			angle = rand() % 360;
			hdc_ellipse(x, y, a, b, angle, i % 2, 2 + rand() % 5);	//预置三色轮换
			Sleep(100);
		}
		to_be_continued("画椭圆测试完成", STL_X, STL_Y);

		/* 来朵花吧 */
		hdc_cls();
		for (i = 0; i < 360; i += 7) //步长为素数且与360互质
			hdc_ellipse(350, 350, 300, 100, i, 0, 1, RGB(rand() % 255, rand() % 255, rand() % 255));	//预置三色轮换

		to_be_continued("画花完成", STL_X, STL_Y);
	}

	if (test_choise[T_PEPPAPIG] == '1') {
		hdc_cls();

		/* 画小猪佩奇 */
		int hdc_draw_PeppaPig(const int left_shoes_x, const int left_shoes_y); //函数声明

		hdc_draw_PeppaPig(300, 500); //左边鞋子的左上角为基准坐标
	}

	if (test_choise[T_MATHCURVE] == '1') {
		/* 画一条数学曲线 */
		hdc_draw_Mathematical_curve_1851746();
		to_be_continued("数学曲线-范千惠学姐-完成", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1953977();
		to_be_continued("数学曲线-周琳琳学姐-完成", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1854082();
		to_be_continued("数学曲线-金唱学姐-完成", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1952033();
		to_be_continued("数学曲线-侯雅玥学姐-完成", STL_X, STL_Y);

		hdc_draw_Mathematical_curve_1952640();
		to_be_continued("数学曲线-刘羽茜学姐-完成", STL_X, STL_Y);

		/* 在此添加自己的数学曲线，具体内容可自选（例：阿基米德螺线），必做项 */

	}

	if (test_choise[T_CUSTOM] == '1') {
		/* 画一个卡通人物，具体内容可自选
		   额外加分项：根据难度及展现效果给出一定分值的额外加分 */
		hdc_draw_catoon_1851746(5, 15);
		to_be_continued("01班群头像-范千惠学姐-完成", STL_X, STL_Y);

		hdc_draw_catoon_1953977(400, 400);
		to_be_continued("02班群头像-周琳琳学姐-完成", STL_X, STL_Y);

		hdc_draw_catoon_1854082(400, 415);
		to_be_continued("03班群头像-金唱学姐-完成", STL_X, STL_Y);

		hdc_draw_catoon_1952033(350, 270);
		to_be_continued("04班群头像-侯雅玥学姐-完成", STL_X, STL_Y);

		hdc_draw_catoon_1952640(350, 270);
		to_be_continued("05班群头像-刘羽茜学姐-完成", STL_X, STL_Y);

		/* 在此添加自己的卡通图，具体内容可自选，额外加分项 */

	}

	hdc_release();
	cct_gotoxy(STL_X, STL_Y - 2);

	cct_setcolor();//恢复缺省黑白
	t_end = GetTickCount();   //取当前系统时间
	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
	system("pause");

	return 0;
}
