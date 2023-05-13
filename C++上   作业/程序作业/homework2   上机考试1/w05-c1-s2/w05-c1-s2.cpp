/*1953729 信09 吴浩泽*/ 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	int x, y, r, a, b;
	double x1, x2, y1, y2;
	cout << "请输入圆心x坐标[-100..100] : ";
	cin >> x;
	cout << "请输入圆心y坐标[-100..100] : ";
	cin >> y;
	cout << "请输入圆半径r[1..100] : ";
	cin >> r;
	cout << "请输入起点(旧家)角度[0..360] : ";
	cin >> a;
	cout << "请输入终点(新家)角度[0..360] : ";
	cin >> b;
	x1 = x + sin(a / 180.0 * Pi) * r;
	y1 = y + cos(a / 180.0 * Pi) * r;
	x2 = x + sin(b / 180.0 * Pi) * r;
	y2 = y + cos(b / 180.0 * Pi) * r;
	cout << "旧家坐标 : (";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << x1 << ", " << y1 << ")" << endl;
	cout << "新家坐标 : (";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << x2 << ", " << y2 << ")" << endl;
	return 0;
}
