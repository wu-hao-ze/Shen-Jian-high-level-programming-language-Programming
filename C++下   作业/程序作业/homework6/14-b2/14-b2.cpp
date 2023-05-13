/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;

const int ROW = 2;
const int COL = 3;

#define OPERATOR_IS_MENBER_FUNCTION		1	//运算符的重载用成员函数方式实现（如果值为0，表示用友元方式实现）

class matrix {
private:
	int value[ROW][COL];
	//除此之外不允许再添加数据成员
public:
	matrix(){}
	matrix(const int(*p)[COL])                      //构造函数，用数组初始化矩阵
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
	//给出+的成员函数实现方式的声明
	matrix operator+(const matrix& t);
#else
	//给出+的友元函数实现方式的声明
	friend matrix operator+(const matrix& t1, const matrix& t2);
#endif
	/* ----根据需要添加其它成员函数的定义和友元函数的声明，数量不限---- */
	friend istream& operator>>(istream& intput, matrix& t);
	friend ostream& operator<<(ostream& output, matrix& t);
};
/* ---- 给出成员函数的体外实现/友元函数的实现，其中+的实现有成员和友元两种形式，要求放在下面的预编译中 ---- */
#if OPERATOR_IS_MENBER_FUNCTION
//给出+的成员函数方式的体外实现
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
//给出+的友元函数方式的体外实现
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int a[ROW][COL] = { { 1,2,3 },{ 4,5,6 } };
	int b[ROW][COL] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3; //m3的初值为全0

	/* 下面为定值测试 */
	cout << "初始矩阵m1的值" << endl;
	cout << m1 << endl;
	cout << "初始矩阵m2的值" << endl;
	cout << m2 << endl;

	m3 = m1 + m2;
	cout << "相加后矩阵m3的值" << endl;
	cout << m3 << endl;

	cout << "------------------" << endl;

	/* 下面为键盘输入测试 */
	cout << "请输入初始矩阵m1" << endl;
	cin >> m1;
	cout << "请输入初始矩阵m2" << endl;
	cin >> m2;

	cout << "初始矩阵m1的值" << endl;
	cout << m1 << endl;
	cout << "初始矩阵m2的值" << endl;
	cout << m2 << endl;
	cout << "相加后矩阵m3的值" << endl;
	cout << (m3 = m1 + m2) << endl;

	return 0;
}