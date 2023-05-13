/* 1953729 –≈09 Œ‚∫∆‘Û */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	int no;
	char name[9];
	int score;
	int rank;
};

int main()
{
	FILE* fp;
	fp = fopen("student.txt", "r");
	if (fp == NULL)
	{
		printf("open error\n");
		return -1;
	}
	int n;
	fscanf(fp, "%d", &n);
	struct student* s = (struct student*)malloc(n * sizeof(struct student));
	if (s == NULL)
	{
		printf("…Í«Î ß∞‹\n");
		return -1;
	}
	struct student* head = s;
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d%s%d", &s->no, &s->name, &s->score);
		s++;
	}
	fclose(fp);
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
			if (s[i].no > s[j].no)
			{
				struct student t = s[j];
				s[j] = s[i];
				s[i] = t;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d %-8s %2d %2d", s->no, s->name, s->score, s->rank);
		s++;
		printf("\n");
	}
	free(head);
	return 0;
}