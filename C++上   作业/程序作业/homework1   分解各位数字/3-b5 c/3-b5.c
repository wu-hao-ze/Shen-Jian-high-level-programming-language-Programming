/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	printf("�����������ε����߼���н�(�Ƕ�) : \n");
	float a, b, c, S;
	const float Pi=acos(-1); 
	scanf("%f %f %f", &a, &b, &c);
	S = 1 / 2.0f * a * b * (float)sin(c / 180.0f * Pi);
	printf("���������Ϊ : "); 
	printf("%.3f\n", S);
	return 0;
}
