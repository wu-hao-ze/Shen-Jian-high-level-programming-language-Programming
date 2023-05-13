#include <stdio.h>
#include "linear_list_sq.h"

#define INSERT_NUM		115		//��ʼ������е�Ԫ������
#define MAX_NUM_PER_LINE 	1		//ÿ����������Ԫ�ظ���

int line_count = 0;   //��ӡ����ʱ�ļ�����

/* ���ڱȽ�����ֵ�Ƿ���ȵľ��庯������LocateElem�еĺ���ָ�붨����ͬ������ʱ����
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
    if (e1.num == e2.num)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ڷ���ĳ��Ԫ�ص�ֵ�ľ��庯������ListTraverse�еĺ���ָ�붨����ͬ������ʱ����
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
    printf("%d-%s-%c-%f-%s->", e.num, e.name, e.sex, e.score, e.addr);

    /* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	printf("\n");

    return OK;
}

int main()
{
    sqlist   L;
    ElemType e[]={{1001, "����", 'M', 76.5, "�Ϻ���������"},
		  {1002, "����", 'F', 87, "�Ϻ���������"},
		  {1003, "����", 'M', 80, "�㽭ʡ������"},
		  {1004, "����", 'M', 54, "�㽭ʡ������"},
		  {1005, "ţ��", 'F', 85, "����ʡ�Ͼ���"},
		  {1006, "���", 'M', 60, "����ʡ������"}};
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n\n", ListLength(L));

    printf("����6��Ԫ�أ�\n");
    for (i=0; i<6; i++)
	ListInsert(&L, ListLength(L)+1, e[i]);
    ListTraverse(L, MyVisit);

    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n\n", ListLength(L));

    /* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
       ����ټ�һ����������ֵ */
    for (i=0; i<5; i++) {
    	int pos;
	switch(i) {
	    case 0:
	    	pos = 1;
	    	break;
	    case 1:
	    	pos = ListLength(L);
	    	break;
	    case 2:
	    	pos = -1;
	    	break;
	    case 3:
	    	pos = ListLength(L)+1;
	    	break;
	    case 4:
		printf("������ҪȡԪ�ص�λ��[1..%d]��", ListLength(L));
		scanf("%d", &pos);
		break;
	    }

    	/* ȡ��1��Ԫ���Լ�ǰ������� */
	if (GetElem(L, pos, &e1)==OK) {
	    printf("��%d��Ԫ��=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

	    /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
	    if (PriorElem(L, e1, &e2)==OK)
    		printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
	    else
    		printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

	    if (NextElem(L, e1, &e2)==OK)
	    	printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��=\"%d.%s.%c.%f.%s\"\n\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
	    else
	    	printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��\n\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
	    }
	else
	    printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
        } // end of for

    printf("\n������Ҫ���ҵ�Ԫ�ص�ѧ�ţ�\n");
    scanf("%d", &e1.num);
    /* ��Ϊ e1.num ����ֵΪѧ�ţ����ҷ�����λ�����e1��num����ȷ�ģ�������Ա��ֵ��Ҫ��ӡ */
    if ((pos=LocateElem(L, e1, MyCompare))>0)
    	printf("Ԫ��\"ѧ��=%d\"��λ��=%d\n", e1.num, pos);
    else
    	printf("�Ҳ���Ԫ��\"ѧ��=%d\"\n", e1.num);

    printf("\n������Ҫ����Ԫ�ص�ֵ(ѧ�� ���� �Ա� �ɼ� ��ַ)��\n");
    scanf("%d %s %c %f %s", &e1.num, e1.name, &e1.sex, &e1.score, e1.addr);
    printf("������Ҫ����Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1)==OK) {
    	printf("��%dǰ����Ԫ��\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("��%dǰ����Ԫ��\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

    printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1)==OK) {
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

    printf("\n��ձ�\n");
    ClearList(&L);
    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n", ListLength(L));

    DestroyList(&L);

    return 0;
}
