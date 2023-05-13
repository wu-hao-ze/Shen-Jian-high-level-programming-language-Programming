/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	printf("请输入三角形的两边及其夹角(角度) : \n");
	float a, b, c, S;
	const float Pi=acos(-1); 
	scanf("%f %f %f", &a, &b, &c);
	S = 1 / 2.0f * a * b * (float)sin(c / 180.0f * Pi);
	printf("三角形面积为 : "); 
	printf("%.3f\n", S);
	return 0;
}
