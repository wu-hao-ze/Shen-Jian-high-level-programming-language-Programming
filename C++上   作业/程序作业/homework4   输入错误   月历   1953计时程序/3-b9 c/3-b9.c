/* 1953729 –≈09 Œ‚∫∆‘Û */
#include <stdio.h>
int main()
{
	int i, j;
	for (i = 2; i <= 1000; i++)
	{
		int sum = 1;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
				sum = sum + j;
		}
		if (i == sum)
		{
			printf("%d,its factors are 1,", i); 
			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					printf("%d", j);
					int x = 0;
					for (int t = j + 1; t < i; t++)
					{
						if (i % t == 0)
							x = x + 1;
					}
					if (x != 0)
						printf(",");
				}
			}
			printf("\n");
		}
	}
	return 0;
}