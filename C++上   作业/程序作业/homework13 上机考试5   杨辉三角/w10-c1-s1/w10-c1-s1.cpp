/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;
int main()
{
	int judge(int, int);
	int n, x = 0;
	int num;
	int a[10000];
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "请输入数码[0..9]" << endl;
	cin >> num;
	for (int i = 0; i < n; i++)
		x = x + judge(a[i], num);
	cout << n << "个数中含有" << num << "的个数 : " << x << endl;
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
