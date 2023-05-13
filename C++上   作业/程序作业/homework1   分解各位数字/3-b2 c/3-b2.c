/* 1953729 信09 吴浩泽 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入半径和高度\n");
	double r, h; 
	scanf("%lf %lf", &r,&h);
	const double Pi = 3.14159;
	double C, S1, S2, V1, V2;
	C = 2 * Pi * r;
	S1 = Pi * r * r;
	S2 = 4 * Pi * r * r;
	V1 = 4 * Pi * r * r * r / 3;
	V2 = Pi * r * r * h;
	printf("圆周长     : ");
	printf("%.2lf\n", C);
	printf("圆面积     : ");
	printf("%.2lf\n", S1);
	printf("圆球表面积 : ");
	printf("%.2lf\n", S2);
	printf("圆球体积   : ");
	printf("%.2lf\n", V1);
	printf("圆柱体积   : ");
	printf("%.2lf\n", V2);
	return 0;
}
