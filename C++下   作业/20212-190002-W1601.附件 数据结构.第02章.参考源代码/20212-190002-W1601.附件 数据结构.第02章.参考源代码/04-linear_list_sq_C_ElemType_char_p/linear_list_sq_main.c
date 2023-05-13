#include <stdio.h>
#include <stdlib.h>
#include "linear_list_sq.h"

#define INSERT_NUM		115		//��ʼ������е�Ԫ������
#define MAX_NUM_PER_LINE 	10		//ÿ����������Ԫ�ظ���

int line_count = 0;   //��ӡ����ʱ�ļ�����

/* ���ڱȽ�����ֵ�Ƿ���ȵľ��庯������LocateElem�еĺ���ָ�붨����ͬ������ʱ����
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
    if (strcmp(e1, e2)==0)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ڷ���ĳ��Ԫ�ص�ֵ�ľ��庯������ListTraverse�еĺ���ָ�붨����ͬ������ʱ����
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
    printf("%s->", e);

    /* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	printf("\n");

    return OK;
}

int main()
{
    sqlist   L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n\n", ListLength(L));

    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    e1 = (ElemType)malloc(80*sizeof(char));	//e1ʵ����ָ�룬������������Ӧ�Ŀռ�
    e2 = (ElemType)malloc(80*sizeof(char));	//e2ʵ����ָ�룬������������Ӧ�Ŀռ�
    for (i=INSERT_NUM*2; i>0; i-=2) {
	sprintf(e1, "test%03d", i);
	ListInsert(&L, 1, e1);
	}
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
	    printf("��%d��Ԫ��=%s\n", pos, e1);

	    /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
	    if (PriorElem(L, e1, &e2)==OK)
		printf("��%d��Ԫ��(%s)��ǰ��=%s\n", pos, e1, e2);
	    else
		printf("�޷�ȡ�õ�%d��Ԫ��(%s)��ǰ��\n", pos, e1);

	    if (NextElem(L, e1, &e2)==OK)
		printf("��%d��Ԫ��(%s)�ĺ��=%s\n\n", pos, e1, e2);
	    else
		printf("�޷�ȡ�õ�%d��Ԫ��(%s)�ĺ��\n\n", pos, e1);
	    }
	else
	    printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
        } // end of for

    printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%s", e1);
    if ((pos=LocateElem(L, e1, MyCompare))>0)
    	printf("Ԫ��%s��λ��=%d\n", e1, pos);
    else
    	printf("�Ҳ���Ԫ��%s\n", e1);

    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%s", e1);
    printf("������Ҫ����Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1)==OK) {
    	printf("��%dǰ����Ԫ��%s�ɹ�\n", pos, e1);
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("��%dǰ����Ԫ��%sʧ��\n", pos, e1);

    printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1)==OK) {
    	printf("ɾ����%dԪ��=%s�ɹ�\n", pos, e1);
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("ɾ����%dԪ��=%sʧ��\n", pos, e1);

    printf("\n��ձ�\n");
    ClearList(&L);
    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n", ListLength(L));

    DestroyList(&L);

    return 0;
}
