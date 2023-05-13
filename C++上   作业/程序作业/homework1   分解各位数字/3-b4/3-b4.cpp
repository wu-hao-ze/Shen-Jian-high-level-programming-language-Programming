/* 1953729 信09 吴浩泽 */
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入一个[0-100亿)间的数字:" << endl;
	double N;
	cin >> N;
	double n = N / 10;
	int a = (int)(n) / 100000000;
	int b = (int)(n) / 10000000 % 10;
	int c = (int)(n) / 1000000 % 10;
	int d = (int)(n) / 100000 % 10;
	int e = (int)(n) / 10000 % 10;
	int f = (int)(n) / 1000 % 10;
	int g = (int)(n) / 100 % 10;
	int h = (int)(n) / 10 % 10;
	int i = (int)(n) % 10;
	int t = int(n);
	double x = n - t + 0.0004;
	int j = int(x * 10);
	int x1 = int(x * 100) % 10;
	int x2 = int(x * 1000) % 10;
	cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << h << endl;
	cout << "十位   : " << i << endl;
	cout << "圆     : " << j << endl;
	cout << "角     : " << x1 << endl;
	cout << "分     : " << x2 << endl;
	return 0;
}
