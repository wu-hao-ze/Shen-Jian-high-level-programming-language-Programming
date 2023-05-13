/* 1953729 信09 吴浩泽 */
#include <iostream>
using namespace std;
int main()
{	
	char str[3][128] = {};
	cout << "请输入第一行" << endl;
	cin.getline(str[0], 128, '\n');
	cout << "请输入第二行" << endl;
	cin.getline(str[1], 128, '\n');
	cout << "请输入第三行" << endl;
	cin.getline(str[2], 128, '\n');
	int daxie = 0, xiaoxie = 0, shuzi = 0, kongge = 0, qita = 0;
	for (int i = 0; str[0][i] != '\0'; i++)
	{
		if (str[0][i] >= 'A' && str[0][i] <= 'Z')
			daxie++;
		else if (str[0][i] >= 'a' && str[0][i] <= 'z')
			xiaoxie++;
		else if (str[0][i] >= '0' && str[0][i] <= '9')
			shuzi++;
		else if (str[0][i] == ' ')
			kongge++;
		else
			qita++;
	}
	for (int i = 0; str[1][i] != '\0'; i++)
	{
		if (str[1][i] >= 'A' && str[1][i] <= 'Z')
			daxie++;
		else if (str[1][i] >= 'a' && str[1][i] <= 'z')
			xiaoxie++;
		else if (str[1][i] >= '0' && str[1][i] <= '9')
			shuzi++;
		else if (str[1][i] == ' ')
			kongge++;
		else
			qita++;
	}
	for (int i = 0; str[2][i] != '\0'; i++)
	{
		if (str[2][i] >= 'A' && str[2][i] <= 'Z')
			daxie++;
		else if (str[2][i] >= 'a' && str[2][i] <= 'z')
			xiaoxie++;
		else if (str[2][i] >= '0' && str[2][i] <= '9')
			shuzi++;
		else if (str[2][i] == ' ')
			kongge++;
		else
			qita++;
	}
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << shuzi << endl;
	cout << "空格 : " << kongge << endl;
	cout << "其它 : " << qita << endl;
	return 0;
}