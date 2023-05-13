/* 1953729 信09 吴浩泽 */
#include <iostream>
#include <cstdio>
#include <iomanip>   //格式化输出必须包含此头文件
using namespace std;

#ifdef _MSC_VER
#pragma warning(disable:6031)
#endif

int main()
{
	double a=123.456789012345;
	int    b=123456;
	int    i;

	for (i=0; i<2; i++, a=-a) {
		cout << "======================" << endl;
		cout << "=" << (a>=0 ? "正":"负") << "浮点数的格式化输出=" << endl;
		cout << "======================" << endl;

		cout << "C++缺省输出" << endl;
		cout << a << endl;
		printf("%f\n",a);
		getchar();

		cout << "9位有效数字" << endl;
		cout << setprecision(9) << a << endl;
		printf("%10f\n",a);
		getchar();

		cout << "小数点后6位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("%.6f\n",a);
		getchar();

		cout << "小数点后8位" << endl;
		cout << setiosflags(ios::fixed) << setprecision(8) << a << endl;
		printf("%.8f\n",a);
		getchar();

		cout << "总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("%20.6f\n",a);
		getchar();

		cout << "总宽度20，小数点后8位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(8) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("%-20.8f%c\n", a, '*');
		getchar();

		cout << resetiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << "科学计数法-小数点后6位" << endl;
		cout << setiosflags(ios::scientific) << a << endl;
		printf("%.6e\n",a);
		getchar();

		cout << "科学计数法-小数点后4位" << endl;
		cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;
		printf("%.4e\n",a);
		getchar();

		cout << "科学计数法-总宽度20，小数点后6位，右对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(6) << a << endl;
		printf("%20.6e\n",a);
		getchar();

		cout << "科学计数法-总宽度20，小数点后4位，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(4) << setiosflags(ios::left) << a << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("%-20.4e%c\n",a,'*');
		getchar();

		cout << resetiosflags(ios::scientific) << resetiosflags(ios::left) << setprecision(6); //此句用于消除ios::fixed、ios::left的设置并恢复6位小数

		cout << endl << endl;
		}

	for (i=0; i<2; i++, b=-b) {
		cout << "======================" << endl;
		cout << "=" << (b>=0 ? "正":"负") << "整数的格式化输出=" << endl;
		cout << "======================" << endl;

		cout << "缺省输出" << endl;
		cout << b << endl;
		printf("%d\n",b);
		getchar();
    
		cout << "缺省输出-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("%20d\n",b);
		getchar();

		cout << "缺省输出-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("%-20d%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "八进制输出" << endl;
		cout << oct << b << endl;
		printf("*o\n",b);
		getchar();
    
		cout << "八进制-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("%20o\n",b);
		getchar();

		cout << "八进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("%-20o%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::left); //消除左对齐的设置

		cout << "十六进制输出(a-f)" << endl;
		cout << hex << b << endl;
		printf("%x\n",b);
		getchar();
    
		cout << "十六进制(a-f)-总宽度20，右对齐" << endl;
		cout << setw(20) << b << endl;
		printf("%20x\n",b);
		getchar();

		cout << "十六进制输出(A-F)" << endl;
		cout << setiosflags(ios::uppercase) << b << endl;
		printf("%X\n",b);
		getchar();
    
		cout << "十六进制-总宽度20，左对齐" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //左对齐,最后加*是为了看清楚几个空格
		printf("%-20X%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::uppercase) << resetiosflags(ios::left); //消除大写及左对齐的影响

		cout << dec;     //恢复10进制
		cout << "缺省-带符号位" << endl;
		cout << setiosflags(ios::showpos) << b << endl;
		printf("%+d\n",b);
		getchar();

		cout << endl << endl;
		}

    return 0;
}
