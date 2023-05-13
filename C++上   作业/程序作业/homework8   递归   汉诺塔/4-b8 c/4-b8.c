/* 1953729 ��09 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

int x = 1;
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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		printf("%5d:%3d# %c-->%c\n", x, n, src, dst);
		x++;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", x, n, src, dst);
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
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		scanf("%d", &n);
		rewind(stdin);
		if (n >= 1 && n <= 16)
			break;
	}
	while (1)
	{
		printf("��������ʼ��(A-C)\n");
		scanf("%c", &src);
		rewind(stdin);
		if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
			break;
	}
	while (1)
	{
		printf("������Ŀ����(A-C)\n");
		scanf("%c", &dst);
		rewind(stdin);
		if (dst == src || (dst - src) == 32 || (dst - src) == -32) 
		{
			if (src > 95)
				src = src - 32;
			printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, src);
			continue;
		}
		if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
			break;
	}
	printf("�ƶ�����Ϊ:\n");
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
