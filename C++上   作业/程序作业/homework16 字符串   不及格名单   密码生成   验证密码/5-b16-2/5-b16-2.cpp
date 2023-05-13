/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <string>
using namespace std;

void input(string num[], string name[], int grade[]);
void select(string num[], int fail[], int);
void output(string num[], string name[], int grade[], int fail[], int j);

int main()
{
	string num[10], name[10];
	int grade[10];
	input(num, name, grade);
	cout << endl;
	cout << "不及格名单:" << endl;
	int fail[10];
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		if (grade[i] < 60)
		{
			fail[j] = i;
			j++;
		}
	}
	select(num, fail, j);
	output(num, name, grade, fail, j);
	return 0;
}
void input(string num[], string name[], int grade[])
{
	int i = 1;
	for (; i <= 10; i++)
	{
		cout << "请输入第" << i << "个人的学号、姓名、成绩" << endl;
		cin >> num[i - 1];
		cin >> name[i - 1];
		cin >> grade[i - 1];
	}
}
void select(string num[], int fail[], int j)
{
	int tmpt = 0;
	for (int m = 7; m >= 0; m--)
	{
		for (int i = 0; i < j; i++)
		{
			for (int k = i + 1; k < j; k++)
			{
				if (num[fail[i]][m] < num[fail[k]][m])
				{
					tmpt = fail[i];
					fail[i] = fail[k];
					fail[k] = tmpt;
				}
			}
		}
	}
}
void output(string num[], string name[], int grade[], int fail[], int j)
{
	for (int i = 0; i < j; i++)
	{
		cout << name[fail[i]];
		cout << ' ';
		cout << num[fail[i]];
		cout << ' ';
		cout << grade[fail[i]];
		cout << endl;
	}
}