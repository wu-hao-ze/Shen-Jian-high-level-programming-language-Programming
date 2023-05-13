/* 1953729 信09 吴浩泽 */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度"<<endl;
	double r, h;
	cin >> r >> h;
	const double Pi = 3.14159;
	double C,S1,S2,V1,V2;
	C = 2 * Pi * r;
	S1 = Pi * r * r;
	S2 = 4 * Pi * r * r;
	V1 = 4 * Pi * r * r * r / 3;
	V2 = Pi * r * r * h;
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "圆周长     : " << C<<endl;
	cout << "圆面积     : " << S1<<endl;
	cout << "圆球表面积 : " << S2<<endl;
	cout << "圆球体积   : " << V1<<endl;
	cout << "圆柱体积   : " << V2<<endl;
	return 0;
}