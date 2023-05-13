#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex()	//无参构造
	{
		real = 0;
		imag = 0;
	}
	Complex(double r, double i)	//两参构造
	{
		real = r;
		imag = i;
	}
	Complex operator+(const Complex &a)		//Complex加
	{
		Complex c;
		c.real = real + a.real;
		c.imag = imag + a.imag;
		return c;
	}
	/* 类型转换函数不准做任何修改 */
	operator double()	//类型转换
	{
		return sqrt(real*real + imag * imag);
	}
	friend ostream & operator<<(ostream &out, Complex &c);		//重载<<的声明
};

ostream &operator<<(ostream &out, Complex &c)
{
	if (fabs(c.imag) < 1e-6)
		out << c.real;
	else if (c.imag > 0)
		out<< c.real << '+' << c.imag << "i";
	else
		out << c.real << c.imag << "i";

	return out;
}

/* main函数不准做任何修改 */
int main()
{
	Complex a(1,1), b(2,2), c;

	cout << a << endl;			//期望输出1+1i，实际输出1+1i
	cout << b << endl;			//期望输出2+2i，实际输出2+2i

	c = a + b;
	cout << c << endl;			//期望输出3+3i，实际输出3+3i
	cout << (a + b) << endl;		//期望输出3+3i，实际输出4.24264，为什么?如果想输出期望值，整个程序只允许某两行各修改一处，改哪里？

	return 0;
}
