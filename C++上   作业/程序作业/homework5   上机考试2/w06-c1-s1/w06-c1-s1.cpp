/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cmath> 
using namespace std;
int main()
{
	int x, a;
	cout << "请输入利润" << endl;
	cin >> x;
	if (x >= 1 && x <= 100000)
		a = (int)round(x / 10.0);
	else if (x > 100000 && x <= 200000)
		a = (int)(100000 * 0.1 + round((x - 100000) * 0.075));
	else if (x > 200000 && x <= 400000)
		a = (int)(100000 * 0.1 + 100000 * 0.075 + round((x - 200000) * 0.05));
	else if (x > 400000 && x <= 600000)
		a = (int)(100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + round((x - 400000) * 0.03));
	else if (x > 600000 && x <= 1000000)
		a = (int)(100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + round((x - 600000) * 0.015));
	else if (x > 1000000)
		a = (int)(100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + round((x - 1000000) * 0.01));
	cout << "应发奖金数 : " << a << endl;
	return 0;
}
