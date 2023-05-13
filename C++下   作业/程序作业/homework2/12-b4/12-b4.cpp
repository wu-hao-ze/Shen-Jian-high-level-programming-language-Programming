/*1953729 信09 吴浩泽*/
#include <iostream>
#include <cmath>
using namespace std;

double definite_integration(double (*p)(double), int n, double low, double high)
{
	double value = 0;
	double area = (high - low) / n;
	for (int i = 1; i <= n; i++)
	{
		value += (*p)(low + i * area) * area;
	}
	cout << "dx[" << low << "~" << high << "/n=" << n << "] : ";
	return value;
}
int main()
{
	int n;
	double low, high, value;
	cout << "请输入sinxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	cout << "sin";
	value = definite_integration(sin, n, low, high); //sin 为cmath 中已有函数
	cout << value << endl;
	cout << "请输入cosxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	cout << "cos";
	value = definite_integration(cos, n, low, high); //cos 为cmath 中已有函数
	cout << value << endl;
	cout << "请输入e^xdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	cout << "e^x";
	value = definite_integration(exp, n, low, high); //exp 为cmath 中已有函数
	cout << value << endl;
	return 0;
}