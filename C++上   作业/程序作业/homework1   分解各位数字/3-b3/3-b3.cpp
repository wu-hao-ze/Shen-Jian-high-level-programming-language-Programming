/* 1953729 信09 吴浩泽 */
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
	int n;
	cin >> n;
	int a = n / 10000;
	int b = n / 1000 % 10;
	int c = n / 100 % 10;
	int d = n / 10 % 10;
	int e = n % 10;
	cout << "万位 : " << a << endl;
	cout << "千位 : " << b << endl;
	cout << "百位 : " << c << endl;
	cout << "十位 : " << d << endl;
	cout << "个位 : " << e << endl;
	return 0;
}