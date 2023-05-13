/*1953729 信09 吴浩泽*/
#include <iostream>
using namespace std;
int main()
{
	const char* month[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	cout << "请输入月份(1-12)" << endl;
	int n;
	cin >> n;
	if (n >= 1 && n <= 12 && cin.good())
		cout << month[n - 1] << endl;
	else
		cout << "Invalid" << endl;
	return 0;
}