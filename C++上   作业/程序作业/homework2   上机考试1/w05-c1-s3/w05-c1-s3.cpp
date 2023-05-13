/*1953729 信09 吴浩泽*/
#include<iostream>
using namespace std;
int main()
{
	int x1, x2, y1, y2;
	cout << "请输入第1个点的坐标 : ";
	cin >> x1 >> y1;
	cout << "请输入第2个点的坐标 : ";
	cin >> x2 >> y2;
	double k, a, b;
	k = double((y2 - y1)) / (x2 - x1);
	b = k * (-x1) + y1;
	a = x1 + 1.0 / k * (-y1);
	cout << a << ' ' << b << endl;
	if (x1 == x2) 
	{
		if(x1<0)
		cout << "平行于y轴，在二三象限" << endl;
		else 
		cout << "平行于y轴，在一四象限" << endl;
	}
	else 
	{
		if (k != 0)
		{
			if (a > 0 && b > 0)
				cout << "在第一象限" << endl;
			else if (a < 0 && b > 0)
				cout << "在第二象限" << endl;
			else if (a < 0 && b < 0)
				cout << "在第三象限" << endl;
			else if (a > 0 && b < 0)
				cout << "在第四象限" << endl;
		}
		else
		{
			if (b > 0)
				cout << "平行于x轴，在一二象限" << endl;
			else
				cout << "平行于x轴，在三四象限" << endl;
		}
	}
	return 0;
}