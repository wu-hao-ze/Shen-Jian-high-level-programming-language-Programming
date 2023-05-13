/* 1953729 信09 吴浩泽 */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角(角度) : " << endl;
	float a, b, c, S;
	cin >> a >> b >> c;
	const float Pi = acos(-1);
	S = 1 / 2.0f * a * b * (float)sin(c / 180.0f * Pi);
	cout << "三角形面积为 : " << setiosflags(ios::fixed)
		<< setprecision(3) << S << endl;
	return 0;
}
