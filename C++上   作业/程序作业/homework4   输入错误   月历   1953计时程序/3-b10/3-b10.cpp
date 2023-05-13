/* 1953729 信09 吴浩泽 */
#include <iostream>
#include<limits>
using namespace std;
int main()
{
	int x;
	while (1) 
	{
		cout << "请输入x的值(0-100)：";
		cin >> x; 
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "请输入x的值(0-100)：";
			cin >> x;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << endl;
	return 0;
}
