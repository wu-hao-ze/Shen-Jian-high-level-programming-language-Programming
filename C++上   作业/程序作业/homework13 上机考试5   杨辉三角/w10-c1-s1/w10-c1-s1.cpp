/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;
int main()
{
	int judge(int, int);
	int n, x = 0;
	int num;
	int a[10000];
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "����������[0..9]" << endl;
	cin >> num;
	for (int i = 0; i < n; i++)
		x = x + judge(a[i], num);
	cout << n << "�����к���" << num << "�ĸ��� : " << x << endl;
	return 0;
}
int judge(int t, int k)
{
	int sum = 0;
	while (t != 0)
	{
		if (t % 10 == k)
			sum++;
		t = t / 10;
	}
	return sum;
}
