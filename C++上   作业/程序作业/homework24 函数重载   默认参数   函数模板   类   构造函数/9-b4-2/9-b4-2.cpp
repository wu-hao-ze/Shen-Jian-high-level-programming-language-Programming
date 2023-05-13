/* 学号 姓名 班级 */
#include <iostream>
#include <cmath>
using namespace std;

class point;
class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	double area(point);
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y);
};
class point {
private:
	int x;
	int y;
public:
	void set(int p_x, int p_y);
	friend triangle;
};

triangle::triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
{
	p1.set(p1_x, p1_y);
	p2.set(p2_x, p2_y);
	p3.set(p3_x, p3_y);
}
double triangle::area(point p1)
{
	cout << p1.x;
}
void point::set(int p_x, int p_y)
{
	cout << 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //三点共线
		cout << "三角形面积应该是：-1， 实际是：" << tr.area() << endl;
	}

	return 0;
}