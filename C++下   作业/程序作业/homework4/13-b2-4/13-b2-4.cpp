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
	char name[9];
	int score;
	int rank;
};

int main()
{
	ifstream fp("student.txt", ios::in);
	if (!fp)
	{
		cerr << "open error" << endl;
		return -1;
	}
	int n;
	fp >> n;
	student* s = new(nothrow) student[n];
	if (s == NULL)
	{
		cerr << "…Í«Î ß∞‹" << endl;
		return -1;
	}
	student* head = s;
	for (int i = 0; i < n; i++)
	{
		fp >> s->no >> s->name >> s->score;
		s++;
	}
	fp.close();
	s = head;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i].score < s[j].score)
			{
				struct student t = s[j];
				s[j] = s[i];
				s[i] = t;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			s[i].rank = 1;
		else
		{
			if (s[i].score == s[i - 1].score)
				s[i].rank = s[i - 1].rank;
			else
				s[i].rank = i + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i].rank == s[j].rank)
				if (s[i].no > s[j].no)
				{
					student t = s[j];
					s[j] = s[i];
					s[i] = t;
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s->no << ' ' << setiosflags(ios::left) << setw(8) << s->name << ' ' << setw(2) << s->score << ' ';
		cout.setf(ios::right);
		cout.width(2);
		cout << s->rank;
		s++;
		cout << endl;
		cout.unsetf(ios::right);
	}
	delete[]head;
	return 0;
}