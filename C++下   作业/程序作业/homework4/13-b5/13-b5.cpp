/* 1953729 –≈09 Œ‚∫∆‘Û */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct student
{
	int no;
	char* name1;
	char* name2;
};

int main()
{
	ifstream fp1("stulist.txt", ios::in);
	ofstream fp2("result.txt", ios::out);
	if (!fp1)
	{
		cerr << "open error" << endl;
		return -1;
	}
	if (!fp2)
	{
		cerr << "open error" << endl;
		return -1;
	}
	student* p = NULL, * q = NULL, * stu = NULL;
	int N;
	fp1 >> N;
	stu = new(nothrow)student[N];
	if (stu == NULL)
	{
		clog << "…Í«Î ß∞‹" << endl;
		return -1;
	}
	int t = 0, M;
	fp1 >> M;
	for (; t < N; t++)
	{
		srand((unsigned int)(time(0)));
		int i = rand() % M + 3;
		int k = 1;
		if (i <= 1056)
		{
			fp1.seekg(12 + (i - 3) * 39, ios::beg);
			k = 1;
		}
		else if (i > 1056 && i <= 11586)
		{
			fp1.seekg(12 + 1053 * 39 + (i - 1053) * 40, ios::beg);
			k = 2;
		}
		else
		{
			fp1.seekg(12 + 1053 * 39 + (11586 - 1053) * 40 + (i - 11583) * 41, ios::beg);
			k = 3;
		}
		fp1 >> stu[t].no;
		fp2 << stu[t].no;
		int j = 0;
		while (fp1.get() == ' ')
			j++;
		fp1.seekg(-1, ios::cur);
		stu[t].name1 = new(nothrow)char[16 - j];
		if (stu[t].name1 == NULL)
		{
			cerr << "…Í«Î ß∞‹" << endl;
			return -1;
		}
		fp1 >> stu[t].name1;
		fp2 << ' ' << setw(15) << stu[t].name1;
		stu[t].name2 = new(nothrow)char[7 + k];
		if (stu[t].name2 == NULL)
		{
			cerr << "…Í«Î ß∞‹" << endl;
			return -1;
		}
		fp1 >> stu[t].name2;
		fp2 << "     " << stu[t].name2;
		fp2 << endl;
	}
	fp1.close();
	fp2.close();
	t = 0;
	for (; t < N; t++)
	{
		delete[]stu[t].name1;
		delete[]stu[t].name2;
	}
	delete[]stu;
	return 0;
}