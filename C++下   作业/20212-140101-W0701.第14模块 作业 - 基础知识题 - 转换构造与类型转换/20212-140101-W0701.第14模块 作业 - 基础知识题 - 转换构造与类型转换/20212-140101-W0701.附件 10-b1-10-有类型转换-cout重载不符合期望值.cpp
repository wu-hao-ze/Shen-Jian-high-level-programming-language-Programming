#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
	double real;
	double imag;
public:
	Complex()	//�޲ι���
	{
		real = 0;
		imag = 0;
	}
	Complex(double r, double i)	//���ι���
	{
		real = r;
		imag = i;
	}
	Complex operator+(const Complex &a)		//Complex��
	{
		Complex c;
		c.real = real + a.real;
		c.imag = imag + a.imag;
		return c;
	}
	/* ����ת��������׼���κ��޸� */
	operator double()	//����ת��
	{
		return sqrt(real*real + imag * imag);
	}
	friend ostream & operator<<(ostream &out, Complex &c);		//����<<������
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

/* main������׼���κ��޸� */
int main()
{
	Complex a(1,1), b(2,2), c;

	cout << a << endl;			//�������1+1i��ʵ�����1+1i
	cout << b << endl;			//�������2+2i��ʵ�����2+2i

	c = a + b;
	cout << c << endl;			//�������3+3i��ʵ�����3+3i
	cout << (a + b) << endl;		//�������3+3i��ʵ�����4.24264��Ϊʲô?������������ֵ����������ֻ����ĳ���и��޸�һ���������

	return 0;
}
