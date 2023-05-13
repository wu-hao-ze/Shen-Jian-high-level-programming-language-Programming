/* 1953729 –≈09 Œ‚∫∆‘Û */
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
int main()
{
	srand((unsigned int)(time(0)));
	char saolei[15][30] = {};
	for (int t = 0; t < 50;)
	{
		t = 0;
		saolei[rand() % 10 + 1][rand() % 26 + 1] = '*';
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 26; j++)
				if (saolei[i][j] == '*')
					t++;
	}
	for (int i = 1; i <= 10; i++)
	    for (int j = 1; j <= 26; j++)
		{
			int t = 0;
			if (saolei[i][j] != '*')
			{
				for (int a = i - 1; a <= i + 1; a++)
					for (int b = j - 1; b <= j + 1; b++)
						if (saolei[a][b] == '*')
							t++;
				saolei[i][j] = t + 48;
			}
		}
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 26; j++)
		{
			cout << saolei[i][j] << ' ';
			if (j == 26)
				cout << endl;
		}
	return 0;
}
