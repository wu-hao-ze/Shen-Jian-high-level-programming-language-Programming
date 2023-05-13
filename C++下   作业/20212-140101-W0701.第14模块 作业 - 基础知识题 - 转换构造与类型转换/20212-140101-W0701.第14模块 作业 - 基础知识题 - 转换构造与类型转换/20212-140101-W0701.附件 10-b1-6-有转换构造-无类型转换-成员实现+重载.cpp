#include <iostream>
using namespace std;

class Complex {
	private:
		double real;
		double imag;

	public:
		//无参构造函数
		Complex()
		{
			real = 0;
			imag = 0;
		}
		//两参构造函数
		Complex(double r, double i)
		{
			real = r;
			imag = i;
		}
		//转换构造函数
		Complex(double r)
		{
			real = r;
			imag = 0;
		}
		//类型转换函数
//		operator double()
//		{
//			return real;
//		}
		//输出函数
		void display()
		{
			cout << real << "+" << imag << "i" << endl; //暂未考虑虚部为负的情况
		}
		//两个复数类相加，友元函数方式
//		friend Complex operator+(const Complex &c1, const Complex &c2);
		//两个复数类相加，成员函数方式
		Complex operator+(const Complex &c2);
};

//两个复数类相加，友元函数方式
//Complex operator+(const Complex &c1, const Complex &c2)
//{
//	return Complex(c1.real+c2.real, c1.imag+c2.imag);   //返回时调用复制构造
//}

//两个复数类相加，成员函数方式
Complex Complex::operator+(const Complex &c2)
{
	return Complex(real+c2.real, imag+c2.imag);   //返回时调用复制构造
}

int main()
{
	Complex c1(3,4), c3;

	c3 = c1 + Complex(2.5);
	c3.display();

	c3 = c1 + 2.5;
	c3.display();

	c3 = 2.5 + c1;
	c3.display();

	return 0;
}
