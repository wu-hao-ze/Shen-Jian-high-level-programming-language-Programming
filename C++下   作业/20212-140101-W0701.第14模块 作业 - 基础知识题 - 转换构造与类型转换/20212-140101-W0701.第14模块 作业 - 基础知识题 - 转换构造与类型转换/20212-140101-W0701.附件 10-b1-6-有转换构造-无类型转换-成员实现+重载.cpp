#include <iostream>
using namespace std;

class Complex {
	private:
		double real;
		double imag;

	public:
		//�޲ι��캯��
		Complex()
		{
			real = 0;
			imag = 0;
		}
		//���ι��캯��
		Complex(double r, double i)
		{
			real = r;
			imag = i;
		}
		//ת�����캯��
		Complex(double r)
		{
			real = r;
			imag = 0;
		}
		//����ת������
//		operator double()
//		{
//			return real;
//		}
		//�������
		void display()
		{
			cout << real << "+" << imag << "i" << endl; //��δ�����鲿Ϊ�������
		}
		//������������ӣ���Ԫ������ʽ
//		friend Complex operator+(const Complex &c1, const Complex &c2);
		//������������ӣ���Ա������ʽ
		Complex operator+(const Complex &c2);
};

//������������ӣ���Ԫ������ʽ
//Complex operator+(const Complex &c1, const Complex &c2)
//{
//	return Complex(c1.real+c2.real, c1.imag+c2.imag);   //����ʱ���ø��ƹ���
//}

//������������ӣ���Ա������ʽ
Complex Complex::operator+(const Complex &c2)
{
	return Complex(real+c2.real, imag+c2.imag);   //����ʱ���ø��ƹ���
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
