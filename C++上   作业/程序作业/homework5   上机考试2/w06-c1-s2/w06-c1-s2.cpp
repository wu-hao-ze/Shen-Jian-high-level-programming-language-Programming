/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;
int main()
{
	int n, i, sum = 1;
	cout << "请输入第几天的桃子数为1" << endl;
	cin >> n;
	for(i=1;i<n;i++)
	{ 
		sum = (sum + 1) * 2;
	}
	cout << "第一天买的桃子数量=" << sum << endl;
	return 0;
}