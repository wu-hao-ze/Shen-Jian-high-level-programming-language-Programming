/* 1953729 ��09 ����� */
/* ����֤ 2052312 ��־����1952087 ����ΰ��1951477 ���2051995 ���󿭡�1953824 ���  ��ɨ���ڲ�����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char saolei[15][30] = {' '};
	for (int i = 1; i <= 10; i++)
	{	
		for (int j = 1; j <= 26;)
		{ 
			scanf("%c", &saolei[i][j]);
			if (saolei[i][j] != ' ' && saolei[i][j] != '\n')
				j++;
		}
	}
	int a = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (saolei[i][j] == '*')
				a++;
		}
	}
	if (a == 50)
	{
		int k = 0;
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
					if (saolei[i][j] != t + 48)
						k = 1;
				}
			}
		if (k == 1)
			printf("����\n");
		else
			printf("��ȷ\n");
	}
	else
		printf("����\n");
	return 0;
}
