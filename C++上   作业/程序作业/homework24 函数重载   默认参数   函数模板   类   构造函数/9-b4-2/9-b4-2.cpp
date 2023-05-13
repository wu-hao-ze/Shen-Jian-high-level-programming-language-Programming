/* ѧ�� ���� �༶ */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}