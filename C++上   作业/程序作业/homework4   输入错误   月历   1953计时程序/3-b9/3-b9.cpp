/* 1953729 –≈09 Œ‚∫∆‘Û */
#include <iostream>
using namespace std;
int main()
{
	int i, j;
	for(i=2;i<=1000;i++)
	{
		int sum = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				sum = sum + j;
		}
		if (i == sum)
		{
			cout << i << ",its factors are 1,";
			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					cout << j;
					int x = 0;
					for (int t = j + 1; t < i; t++)
					{
						if (i % t == 0)
							x = x + 1;
					}
					if (x != 0)
						cout << ",";
				}
			}
			cout << endl;
		}
	}
	return 0;
}