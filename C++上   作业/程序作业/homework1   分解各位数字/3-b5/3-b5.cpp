/* 1953729 ��09 ����� */
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "�����������ε����߼���н�(�Ƕ�) : " << endl;
	float a, b, c, S;
	cin >> a >> b >> c;
	const float Pi = acos(-1);
	S = 1 / 2.0f * a * b * (float)sin(c / 180.0f * Pi);
	cout << "���������Ϊ : " << setiosflags(ios::fixed)
		<< setprecision(3) << S << endl;
	return 0;
}
