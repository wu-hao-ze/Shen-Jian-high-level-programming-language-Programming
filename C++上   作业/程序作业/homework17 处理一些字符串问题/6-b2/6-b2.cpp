/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char str[81] = {}, * p1, * p2;
	p1 = str;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 80, stdin);
	if (*(p1 + strlen(str) - 1) == '\n')
		*(p1 + strlen(str) - 1) = '\0';
	p2 = str + strlen(str) - 1;
	if (strlen(str) == 1 || strlen(str) == 0)
		cout << "yes" << endl;
	else if (strlen(str) % 2 == 0)
	{
		while ((p1 - str) != strlen(str) / 2)
		{
			if (*p1 == *p2)
			{
				p1++;
				p2--;
			}
			else
				break;
		}
		if ((p1 - str) == strlen(str) / 2)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	else if (strlen(str) % 2 != 0)
	{
		while ((p1 - str) != (strlen(str) + 1) / 2 - 1)
		{
			if (*p1 == *p2)
			{
				p1++;
				p2--;
			}
			else
				break;
		}
		if ((p1 - str) == (strlen(str) + 1) / 2 - 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}