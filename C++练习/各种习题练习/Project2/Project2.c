#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student
{
	int num;
	float score;
};
int main()
{
	struct student s1;
	s1 = { 23,45 };
	printf("%d", s1.num);
	return 0;
}