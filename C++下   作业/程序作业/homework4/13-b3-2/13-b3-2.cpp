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
	struct student* next;
};

int main()
{
	ifstream fp("list.txt", ios::in);
	if (!fp)
	{
		cerr << "open error" << endl;
		return -1;
	}
	student* head = NULL, * p = NULL, * q = NULL;
	p = new(nothrow) student;
	if (p == NULL)
	{
		clog << "…Í«Î ß∞‹" << endl;
		return -1;
	}
	fp >> p->no >> p->name >> p->score;
	head = p;
	while (p->no != 9999999)
	{
		q = p;
		p = new(nothrow) student;
		if (p == NULL)
		{
			clog << "…Í«Î ß∞‹" << endl;
			return -1;
		}
		q->next = p;
		fp >> p->no >> p->name >> p->score;
	}
	delete p;
	q->next = NULL;
	fp.close();
	p = head;
	while (p)
	{
		cout << p->no << ' ' << setiosflags(ios::left) << setw(8) << p->name << ' ' << setw(2) << p->score << ' ';
		cout << endl;
		p = p->next;
	}
	p = head;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	return 0;
}