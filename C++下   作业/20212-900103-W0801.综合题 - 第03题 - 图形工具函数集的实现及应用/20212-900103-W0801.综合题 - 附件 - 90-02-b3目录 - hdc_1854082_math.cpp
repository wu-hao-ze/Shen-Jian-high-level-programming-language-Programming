/*1854082 信18 金唱*/
#include <iostream>
#include <Windows.h>
#include "../include/cmd_hdc_tools.h"
#define pi 3.14159
using namespace std;

static void decartes_leaf_lines(const int point_x, const int point_y, const int a, const int thickness, const int RGB_value)
{
	double deta_theta = (double(thickness) / 60) / 180 * pi;
	int x_max = a + 100;
	int x_min = -(a + 150);
	for (double theta = 0; theta < pi; theta += deta_theta)
	{
		double t = tan(theta);
		int x = int(3.0 * a * t / (1 + t * t * t));
		int y = int(3.0 * a * t * t / (1 + t * t * t));
		if (x >= x_min && x <= x_max)
			hdc_point(point_x + x, point_y + y, thickness, RGB_value);
	}
}

void hdc_draw_Mathematical_curve_1854082()
{
	hdc_cls();
	cout << "这是3条笛卡尔叶形线" << endl;
	decartes_leaf_lines(350, 400, 50, 5, RGB(75, 205, 45));
	decartes_leaf_lines(350, 400, 100, 5, RGB(75, 220, 250));
	decartes_leaf_lines(350, 400, 150, 5, RGB(250, 245, 5));
}