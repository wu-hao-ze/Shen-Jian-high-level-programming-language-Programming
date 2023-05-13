/* 1952033 信12 侯雅玥 */
#include <iostream>
#include <cmath>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"

static const double PI = 3.141592;
//画一个四叶玫瑰线
//(point_x,point_y)为玫瑰线直角坐标系的原点坐标
//rotate为玫瑰线的旋转角，规则为右侧x轴为0度，顺时针旋转为正
//thickness 为线粗 a为极坐标方程p=acos(angle)的系数a,RGB_value为颜色参数
static void hdc_draw_quadrifolium_sin(const int point_x, const int point_y, const int rotate,const int a, const int thickness, const int RGB_value=INVALID_RGB)
{
	if (RGB_value != INVALID_RGB)
		hdc_set_pencolor(RGB_value);
	double angle = 0;
	double p1 = 0,p2=0;
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0,ya=y1,xa=x1;
	double delta = 180.0 / (double)a / PI/10;

	for (angle = 0; angle < 360; angle+=delta)
	{
		p1 =a*sin(2*angle * PI / 180);
		p2= a * sin(2 * (angle+delta) * PI / 180);
		if (thickness > 1)
		{
			y1 = point_y + p1 * sin((angle+rotate) * PI / 180);
			y2 = point_y + p2 * sin((angle + rotate+ delta) * PI / 180);

			if ((ya != y1))
			{
				ya = y1;

				hdc_line((int)x1, (int)y1 - thickness / 2, (int)x1, (int)y1 + thickness / 2,1);
				hdc_line((int)x1 - thickness / 2, (int)y1, (int)x1 + thickness / 2, (int)y1,1);

			}
			x1 = point_x + p1 * cos((angle + rotate) * PI / 180);
			x2 = point_x + p2 * cos((angle+ rotate + delta) * PI / 180);

			if (xa != x1)
			{
				xa = x1;

				hdc_line((int)x1, (int)y1 - thickness / 2, (int)x1, (int)y1 + thickness / 2,1);
				hdc_line((int)x1 - thickness / 2, (int)y1, (int)x1 + thickness / 2, (int)y1,1);
			}

		}
		else
		{
			y1 = point_y + p1 * sin((angle + rotate) * PI / 180);
			y2 = point_y + p2 * sin((angle + rotate+ delta) * PI / 180);

			x1 = point_x + p1 * cos((angle + rotate) * PI / 180);
			x2 = point_x + p2 * cos((angle + rotate+ delta) * PI / 180);
			
			hdc_line((int)x1, (int)y1, (int)x2, (int)y2, 1);
		}
	}



}


void hdc_draw_Mathematical_curve_1952033()
{
	hdc_cls();
	int angle = 0,a=0;
	int start_angle = 0;
	int r, g, b,color;
	
	r = 85;
	g = 1;
	b = 199;
	color = RGB(r, g, b);
	for (a = 350; a >=50; a -= 20)
	{

		for (angle = start_angle; angle < 90 + start_angle; angle += 45)
		{
			hdc_draw_quadrifolium_sin(370, 370, angle, a, 1, color);
		}

		start_angle += 17;

	}
	
}