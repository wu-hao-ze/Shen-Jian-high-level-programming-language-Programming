/* 1953729 ��09 ����� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
#if (__GNUC__)
	gets(str);
#elif (_MSC_VER)
	gets_s(str);
#endif
	p = str;
	pa = a;
	for (; *p != '\0'; )
	{
		if (*p >= '0' && *p <= '9')
		{
			*pa = *p - 48;
			p++;
			for (; *p >= '0' && *p <= '9'; p++)
				*pa = 10 * (*pa) + *p - 48;
			p--;
			pa++;
			if (pa - a == 10)
				break;
		}
		p++;
	}
	cout << "����" << pa - a << "������" << endl;
	for (pnum = a; pnum != pa; pnum++)
		cout << *pnum << ' ';
	cout << endl;
	return 0;
}
