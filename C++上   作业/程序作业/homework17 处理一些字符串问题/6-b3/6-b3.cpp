/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	char str[33] = {}, * p1;
	unsigned int* p2;
	unsigned int a = 0;
	int n = 0;
	p2 = &a;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	p1 = str + strlen(str) - 1;
	for (; p1 != str; p1--)
	{
		*p2 = (*p1 - 48) * (int)(pow(2, n)) + *p2;
		n++;
	}
	*p2 = (*p1 - 48) * (int)(pow(2, n)) + *p2;
	cout << *p2 << endl;
	return 0;
}