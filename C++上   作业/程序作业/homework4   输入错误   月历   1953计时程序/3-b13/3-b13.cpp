/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;
int main()
{
	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数
	int n=1;
	int x1, x2, x3;
	for (x1 = 123; x1 <= 987; x1++)
	{
		int a1 = x1 / 100;
		int b1 = x1 / 10 % 10;
		int c1 = x1 % 10;
		if (a1 != b1 && b1 != c1 && a1 != c1 && a1 != 0 && b1 != 0 && c1 != 0)
		{
			for (x2 = x1 + 1; x2 <= 987; x2++)
			{
				int a2 = x2 / 100;
				int b2 = x2 / 10 % 10;
				int c2 = x2 % 10;
				if (a2 != b2 && b2 != c2 && a2 != c2 && a2 != a1 && a2 != b1 && a2 != c1 && b2 != a1 && b2 != b1 && b2 != c1 && c2 != a1 && c2 != b1 && c2 != c1 && a2 != 0 && b2 != 0 && c2 != 0)
				{
					for (x3 = x2 + 1; x3 <= 987; x3++)
					{
						int a3 = x3 / 100;
						int b3 = x3 / 10 % 10;
						int c3 = x3 % 10;
						if (a3 != b3 && b3 != c3 && a3 != c3 && a3 != a1 && a3 != b1 && a3 != c1 && a3 != a2 && a3 != b2 && a3 != c2 && b3 != a1 && b3 != b1 && b3 != c1 && b3 != a2 && b3 != b2 && b3 != c2 && c3 != a1 && c3 != b1 && c3 != c1 && c3 != a2 && c3 != b2 && c3 != c2 && a3 != 0 && b3 != 0 && c3 != 0)
						{
							if (x1 + x2 + x3 == 1953)
							{
								cout << "No." << setiosflags(ios::right) << setw(3) << n << " : ";
								cout << x1 << "+" << x2 << "+" << x3 << "=" << 1953 << endl;
								n++;
							}
						}
					}
				}
			}
		}
	}
	cout << "total=" << n-1 << endl;
	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数
	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;
	return 0;
}