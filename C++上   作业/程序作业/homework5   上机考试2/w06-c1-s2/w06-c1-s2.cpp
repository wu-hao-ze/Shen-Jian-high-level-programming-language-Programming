/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	int n, i, sum = 1;
	cout << "������ڼ����������Ϊ1" << endl;
	cin >> n;
	for(i=1;i<n;i++)
	{ 
		sum = (sum + 1) * 2;
	}
	cout << "��һ�������������=" << sum << endl;
	return 0;
}