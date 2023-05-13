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
	struct student* next;
};

int main()
{
	FILE* fp;
	fp = fopen("list.txt", "r");
	if (fp == NULL)
	{
		printf("open error\n");
		return -1;
	}
	struct student* head = NULL, * p = NULL, * q = NULL;
	p = (struct student*)malloc(sizeof(struct student));
	if (p == NULL)
	{
		printf("…Í«Î ß∞‹\n");
		return -1;
	}
	fscanf(fp, "%d%s%d", &p->no, &p->name, &p->score);
	head = p;
	while (p->no != 9999999)
	{
		q = p;
		p = (struct student*)malloc(sizeof(struct student));
		if (p == NULL)
		{
			printf("…Í«Î ß∞‹\n");
			return -1;
		}
		q->next = p;
		fscanf(fp, "%d%s%d", &p->no, &p->name, &p->score);
	}
	free(p);
	q->next = NULL;
	fclose(fp);
	p = head;
	while (p)
	{
		printf("%d %-8s %2d", p->no, p->name, p->score);
		p = p->next;
		printf("\n");
	}
	p = head;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return 0;
}