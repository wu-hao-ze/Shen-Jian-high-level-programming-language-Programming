/* 1953729 ��09 ����� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
			   3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int x = 1;
	if (n == 1)
	{
		cout << setw(5) << x << ":" << setw(3) << n << "#" << " " << src << "-->" << dst << endl;
		x++;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cout << setw(5) << x << ":" << setw(3) << n << "#" << " " << src << "-->" << dst << endl;
		x++;
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	int n;
	char src, dst, tmp;
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
			cin >> n;
		}
		if (n >= 1 && n <= 16)
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');

	while (1)
	{
		cout << "��������ʼ��(A-C)" << endl;
		cin >> src;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "��������ʼ��(A-C)" << endl;
			cin >> src;
		}
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');

	while (1)
	{
		cout << "������Ŀ����(A-C)" << endl;
		cin >> dst;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������Ŀ����(A-C)" << endl;
			cin >> dst;
		}
		if (dst == src || (dst - src) == 32 || (dst - src) == -32)
		{
			if (src > 95)
				src = src - 32;
			cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
			continue;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
			break;
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');

	cout << "�ƶ�����Ϊ:" << endl;
	if (src > 95)
		src = src - 32;
	if (dst > 95)
		dst = dst - 32;
	if (src == 'A' && dst == 'B')
		tmp = 'C';
	if (src == 'A' && dst == 'C')
		tmp = 'B';
	if (src == 'B' && dst == 'A')
		tmp = 'C';
	if (src == 'B' && dst == 'C')
		tmp = 'A';
	if (src == 'C' && dst == 'B')
		tmp = 'A';
	if (src == 'C' && dst == 'A')
		tmp = 'B';
	hanoi(n, src, tmp, dst);
	return 0;
}
