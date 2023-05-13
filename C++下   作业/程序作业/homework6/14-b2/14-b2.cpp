/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;

const int ROW = 2;
const int COL = 3;

#define OPERATOR_IS_MENBER_FUNCTION		1	//������������ó�Ա������ʽʵ�֣����ֵΪ0����ʾ����Ԫ��ʽʵ�֣�

class matrix {
private:
	int value[ROW][COL];
	//����֮�ⲻ������������ݳ�Ա
public:
	matrix(){}
	matrix(const int(*p)[COL])                      //���캯�����������ʼ������
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				value[i][j] = *(*(p + i) + j);
			}
		}
	}
#if OPERATOR_IS_MENBER_FUNCTION
	//����+�ĳ�Ա����ʵ�ַ�ʽ������
	matrix operator+(const matrix& t);
#else
	//����+����Ԫ����ʵ�ַ�ʽ������
	friend matrix operator+(const matrix& t1, const matrix& t2);
#endif
	/* ----������Ҫ���������Ա�����Ķ������Ԫ��������������������---- */
	friend istream& operator>>(istream& intput, matrix& t);
	friend ostream& operator<<(ostream& output, matrix& t);
};
/* ---- ������Ա����������ʵ��/��Ԫ������ʵ�֣�����+��ʵ���г�Ա����Ԫ������ʽ��Ҫ����������Ԥ������ ---- */
#if OPERATOR_IS_MENBER_FUNCTION
//����+�ĳ�Ա������ʽ������ʵ��
matrix matrix::operator+(const matrix& t)
{
	matrix c;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			c.value[i][j] = value[i][j] + t.value[i][j];
		}
	}
	return c;
}
#else
//����+����Ԫ������ʽ������ʵ��
matrix operator+(const matrix& t1, const matrix& t2)
{
	matrix c;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			c.value[i][j] = t1.value[i][j] + t2.value[i][j];
		}
	}
	return c;
}
#endif

istream& operator>>(istream& intput, matrix& t)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			intput >> t.value[i][j];
		}
	}
	return intput;
}
ostream& operator<<(ostream& output, matrix& t)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			output << t.value[i][j] << ' ';
		}
		cout << endl;
	}
	return output;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int a[ROW][COL] = { { 1,2,3 },{ 4,5,6 } };
	int b[ROW][COL] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3; //m3�ĳ�ֵΪȫ0

	/* ����Ϊ��ֵ���� */
	cout << "��ʼ����m1��ֵ" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ" << endl;
	cout << m2 << endl;

	m3 = m1 + m2;
	cout << "��Ӻ����m3��ֵ" << endl;
	cout << m3 << endl;

	cout << "------------------" << endl;

	/* ����Ϊ����������� */
	cout << "�������ʼ����m1" << endl;
	cin >> m1;
	cout << "�������ʼ����m2" << endl;
	cin >> m2;

	cout << "��ʼ����m1��ֵ" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ" << endl;
	cout << m2 << endl;
	cout << "��Ӻ����m3��ֵ" << endl;
	cout << (m3 = m1 + m2) << endl;

	return 0;
}