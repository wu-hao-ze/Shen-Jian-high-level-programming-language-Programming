/* 1953729 ��09 ����� */
#include <iostream>
#include <cstdio>
#include <iomanip>   //��ʽ��������������ͷ�ļ�
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
		cout << "=" << (a>=0 ? "��":"��") << "�������ĸ�ʽ�����=" << endl;
		cout << "======================" << endl;

		cout << "C++ȱʡ���" << endl;
		cout << a << endl;
		printf("%f\n",a);
		getchar();

		cout << "9λ��Ч����" << endl;
		cout << setprecision(9) << a << endl;
		printf("%10f\n",a);
		getchar();

		cout << "С�����6λ" << endl;
		cout << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("%.6f\n",a);
		getchar();

		cout << "С�����8λ" << endl;
		cout << setiosflags(ios::fixed) << setprecision(8) << a << endl;
		printf("%.8f\n",a);
		getchar();

		cout << "�ܿ��20��С�����6λ���Ҷ���" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(6) << a << endl;
		printf("%20.6f\n",a);
		getchar();

		cout << "�ܿ��20��С�����8λ�������" << endl;
		cout << setw(20) << setiosflags(ios::fixed) << setprecision(8) << setiosflags(ios::left) << a << '*' << endl; //�����,����*��Ϊ�˿���������ո�
		printf("%-20.8f%c\n", a, '*');
		getchar();

		cout << resetiosflags(ios::fixed) << resetiosflags(ios::left) << setprecision(6); //�˾���������ios::fixed��ios::left�����ò��ָ�6λС��

		cout << "��ѧ������-С�����6λ" << endl;
		cout << setiosflags(ios::scientific) << a << endl;
		printf("%.6e\n",a);
		getchar();

		cout << "��ѧ������-С�����4λ" << endl;
		cout << setiosflags(ios::scientific) << setprecision(4) << a << endl;
		printf("%.4e\n",a);
		getchar();

		cout << "��ѧ������-�ܿ��20��С�����6λ���Ҷ���" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(6) << a << endl;
		printf("%20.6e\n",a);
		getchar();

		cout << "��ѧ������-�ܿ��20��С�����4λ�������" << endl;
		cout << setw(20) << setiosflags(ios::scientific) << setprecision(4) << setiosflags(ios::left) << a << '*' << endl; //�����,����*��Ϊ�˿���������ո�
		printf("%-20.4e%c\n",a,'*');
		getchar();

		cout << resetiosflags(ios::scientific) << resetiosflags(ios::left) << setprecision(6); //�˾���������ios::fixed��ios::left�����ò��ָ�6λС��

		cout << endl << endl;
		}

	for (i=0; i<2; i++, b=-b) {
		cout << "======================" << endl;
		cout << "=" << (b>=0 ? "��":"��") << "�����ĸ�ʽ�����=" << endl;
		cout << "======================" << endl;

		cout << "ȱʡ���" << endl;
		cout << b << endl;
		printf("%d\n",b);
		getchar();
    
		cout << "ȱʡ���-�ܿ��20���Ҷ���" << endl;
		cout << setw(20) << b << endl;
		printf("%20d\n",b);
		getchar();

		cout << "ȱʡ���-�ܿ��20�������" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //�����,����*��Ϊ�˿���������ո�
		printf("%-20d%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::left); //��������������

		cout << "�˽������" << endl;
		cout << oct << b << endl;
		printf("*o\n",b);
		getchar();
    
		cout << "�˽���-�ܿ��20���Ҷ���" << endl;
		cout << setw(20) << b << endl;
		printf("%20o\n",b);
		getchar();

		cout << "�˽���-�ܿ��20�������" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //�����,����*��Ϊ�˿���������ո�
		printf("%-20o%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::left); //��������������

		cout << "ʮ���������(a-f)" << endl;
		cout << hex << b << endl;
		printf("%x\n",b);
		getchar();
    
		cout << "ʮ������(a-f)-�ܿ��20���Ҷ���" << endl;
		cout << setw(20) << b << endl;
		printf("%20x\n",b);
		getchar();

		cout << "ʮ���������(A-F)" << endl;
		cout << setiosflags(ios::uppercase) << b << endl;
		printf("%X\n",b);
		getchar();
    
		cout << "ʮ������-�ܿ��20�������" << endl;
		cout << setw(20) << setiosflags(ios::left) << b << '*' << endl; //�����,����*��Ϊ�˿���������ո�
		printf("%-20X%c\n",b,'*');
		getchar();

		cout << resetiosflags(ios::uppercase) << resetiosflags(ios::left); //������д��������Ӱ��

		cout << dec;     //�ָ�10����
		cout << "ȱʡ-������λ" << endl;
		cout << setiosflags(ios::showpos) << b << endl;
		printf("%+d\n",b);
		getchar();

		cout << endl << endl;
		}

    return 0;
}
