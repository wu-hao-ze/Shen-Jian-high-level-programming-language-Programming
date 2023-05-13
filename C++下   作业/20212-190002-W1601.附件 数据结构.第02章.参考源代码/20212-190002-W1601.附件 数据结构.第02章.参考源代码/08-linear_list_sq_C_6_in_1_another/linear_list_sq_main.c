#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "linear_list_sq.h"

#define INSERT_NUM		115		//��ʼ������е�Ԫ������

#ifdef ELEMTYPE_IS_DOUBLE
    #define MAX_NUM_PER_LINE 	5		//ÿ����������Ԫ�ظ���
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    #define MAX_NUM_PER_LINE 	5		//ÿ����������Ԫ�ظ���
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    #define MAX_NUM_PER_LINE 	1		//ÿ����������Ԫ�ظ���
#else	//ȱʡ����int����
    #define MAX_NUM_PER_LINE 	10		//ÿ����������Ԫ�ظ���
#endif

int line_count = 0;   //��ӡ����ʱ�ļ�����

/* ���ڱȽ�����ֵ�Ƿ���ȵľ��庯������LocateElem�еĺ���ָ�붨����ͬ������ʱ����
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
#ifdef ELEMTYPE_IS_DOUBLE
    if (fabs(e1-e2)<1e-6)
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    if (strcmp(e1, e2)==0)
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    if (e1.num==e2.num)
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    if (e1->num==e2->num)
#else	//ȱʡ����int����
    if (e1==e2)
#endif
    	return TRUE;
    else
    	return FALSE;
}

/* ���ڷ���ĳ��Ԫ�ص�ֵ�ľ��庯������ListTraverse�еĺ���ָ�붨����ͬ������ʱ����
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
#ifdef ELEMTYPE_IS_DOUBLE
    printf("%5.1f->", e);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    printf("%s->", e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    printf("%d-%s-%c-%f-%s->", e.num, e.name, e.sex, e.score, e.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    printf("%d-%s-%c-%f-%s->", e->num, e->name, e->sex, e->score, e->addr);
#else	//ȱʡ����int����
    printf("%3d->", e);
#endif

    /* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	printf("\n");

    return OK;
}

/* �ͷŶ����ռ� */
Status MySubFree(sqlist *L)
{
    /* ����ָ��������Ҫ�ͷŶ����ռ䣬����ʲôҲ���� */
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    int i;

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
        free(L->elem[i]);
#endif

    return OK;
}

/* ��ֵ */
Status MyAssign(ElemType *dst, ElemType src)
{
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    strcpy(*dst, src);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(dst, &src, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    memcpy(*dst, src, sizeof(ET));
#else	//int��doubleֱ�Ӹ�ֵ
    *dst = src;
#endif

    return OK;
}

/* ����ƶ�(ǰ�ƻ����) */
Status  MyMove(ElemType *dst, ElemType *src)
{
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
    strcpy(*dst, *src);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    memcpy(dst, src, sizeof(ElemType));	//������strcpy
#else	//int��double��charָ�롢struct studentָ�붼��ֱ�Ӹ�ֵ
    *dst = *src;
#endif

    return OK;
}

Status MyAlloc(ElemType *p, ElemType e)
{
#if defined (ELEMTYPE_IS_CHAR_P)
    *p = (ElemType)malloc((strlen(e)+1)*sizeof(char));
    if (*p==NULL)
    	return LOVERFLOW;
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    *p = (ElemType)malloc(sizeof(ET));
    if (*p==NULL)
    	return LOVERFLOW;
#endif

    return OK;
}

Status MyFree(ElemType p)
{
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    free(p);
#endif

    return OK;
}

int main()
{
#if defined (ELEMTYPE_IS_STRUCT_STUDENT)
    /* ����������������ҪԤ������ */
    ElemType e[]={{1001, "����", 'M', 76.5, "�Ϻ���������"},
		  {1002, "����", 'F', 87, "�Ϻ���������"},
		  {1003, "����", 'M', 80, "�㽭ʡ������"},
		  {1004, "����", 'M', 54, "�㽭ʡ������"},
		  {1005, "ţ��", 'F', 85, "����ʡ�Ͼ���"},
		  {1006, "���", 'M', 60, "����ʡ������"}};
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    /* ����������������ҪԤ������ */
    ET       e[]={{1001, "����", 'M', 76.5, "�Ϻ���������"},
		  {1002, "����", 'F', 87, "�Ϻ���������"},
		  {1003, "����", 'M', 80, "�㽭ʡ������"},
		  {1004, "����", 'M', 54, "�㽭ʡ������"},
		  {1005, "ţ��", 'F', 85, "����ʡ�Ͼ���"},
		  {1006, "���", 'M', 60, "����ʡ������"}};
#endif
    sqlist   L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n\n", ListLength(L));

#ifdef ELEMTYPE_IS_DOUBLE
    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    for (i=INSERT_NUM*2; i>0; i-=2)
	ListInsert(&L, 1, (ElemType)i, MyMove, MyAssign, MyAlloc);	//i�����ͣ��ϸ���˵��Ҫת��Ϊdouble
#elif defined (ELEMTYPE_IS_CHAR_ARRAY)
    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    for (i=INSERT_NUM*2; i>0; i-=2) {
	sprintf(e1, "test%03d", i);
	ListInsert(&L, 1, e1, MyMove, MyAssign, MyAlloc);
	}
#elif defined (ELEMTYPE_IS_CHAR_P)
    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    e1 = (ElemType)malloc(80*sizeof(char));	//e1ʵ����ָ�룬������������Ӧ�Ŀռ�
    e2 = (ElemType)malloc(80*sizeof(char));	//e2ʵ����ָ�룬������������Ӧ�Ŀռ�
    for (i=INSERT_NUM*2; i>0; i-=2) {
	sprintf(e1, "test%03d", i);
	ListInsert(&L, 1, e1, MyMove, MyAssign, MyAlloc);
	}
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    printf("����6��Ԫ�أ�\n");
    for (i=0; i<6; i++)
	ListInsert(&L, ListLength(L)+1, *(e+i), MyMove, MyAssign, MyAlloc);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    printf("����6��Ԫ�أ�\n");
    e1 = (ElemType)malloc(sizeof(ET));
    e2 = (ElemType)malloc(sizeof(ET));

    printf("����6��Ԫ�أ�\n");
    for (i=0; i<6; i++)
	ListInsert(&L, ListLength(L)+1, (e+i), MyMove, MyAssign, MyAlloc);
#else	//ȱʡ����int����
    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    for (i=INSERT_NUM*2; i>0; i-=2)
	ListInsert(&L, 1, i, MyMove, MyAssign, MyAlloc);
#endif

    ListTraverse(L, MyVisit);//�˴�����MyVisit������

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
	if (GetElem(L, pos, &e1, MyAssign)==OK) {
#ifdef ELEMTYPE_IS_DOUBLE
	    printf("��%d��Ԫ��=%d\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	    printf("��%d��Ԫ��=%s\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	    printf("��%d��Ԫ��=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	    printf("��%d��Ԫ��=\"%d.%s.%c.%f.%s\"\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
	    printf("��%d��Ԫ��=%d\n", pos, e1);
#endif

	    /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
	    if (PriorElem(L, e1, &e2, MyCompare, MyAssign)==OK)
#ifdef ELEMTYPE_IS_DOUBLE
		printf("��%d��Ԫ��(%5.1f)��ǰ��=%5.1f\n", pos, e1, e2);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
		printf("��%d��Ԫ��(%s)��ǰ��=%s\n", pos, e1, e2);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    		printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    		printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��=\"%d.%s.%c.%f.%s\"\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr, e2->num, e2->name, e2->sex, e2->score, e2->addr);
#else	//ȱʡ����int����
		printf("��%d��Ԫ��(%d)��ǰ��=%d\n", pos, e1, e2);
#endif
	    else
#ifdef ELEMTYPE_IS_DOUBLE
		printf("�޷�ȡ�õ�%d��Ԫ��(%5.1f)��ǰ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
		printf("�޷�ȡ�õ�%d��Ԫ��(%s)��ǰ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    		printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    		printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"��ǰ��\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
		printf("�޷�ȡ�õ�%d��Ԫ��(%d)��ǰ��\n", pos, e1);
#endif

	    if (NextElem(L, e1, &e2, MyCompare, MyAssign)==OK)
#ifdef ELEMTYPE_IS_DOUBLE
		printf("��%d��Ԫ��(%5.1f)�ĺ��=%5.1f\n", pos, e1, e2);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
		printf("��%d��Ԫ��(%s)�ĺ��=%s\n", pos, e1, e2);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    		printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    		printf("��%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��=\"%d.%s.%c.%f.%s\"\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr, e2->num, e2->name, e2->sex, e2->score, e2->addr);
#else	//ȱʡ����int����
		printf("��%d��Ԫ��(%d)�ĺ��=%d\n", pos, e1, e2);
#endif
	    else
#ifdef ELEMTYPE_IS_DOUBLE
		printf("�޷�ȡ�õ�%d��Ԫ��(%5.1f)�ĺ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
		printf("�޷�ȡ�õ�%d��Ԫ��(%s)�ĺ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    		printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    		printf("�޷�ȡ�õ�%d��Ԫ��\"%d.%s.%c.%f.%s\"�ĺ��\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
		printf("�޷�ȡ�õ�%d��Ԫ��(%d)�ĺ��\n", pos, e1);
#endif
	    }
	else
	    printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
        } // end of for

#ifdef ELEMTYPE_IS_DOUBLE
    printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%lf", &e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%s", e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    printf("\n������Ҫ���ҵ�Ԫ�ص�ѧ�ţ�\n");
    scanf("%d", &e1.num);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    printf("\n������Ҫ���ҵ�Ԫ�ص�ѧ�ţ�\n");
    scanf("%d", &e1->num);
#else	//ȱʡ����int����
    printf("\n������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%d", &e1);
#endif

    if ((pos=LocateElem(L, e1, MyCompare))>0)       //�˴�����MyCompare������
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("Ԫ��%5.1f��λ��=%d\n", e1, pos);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("Ԫ��%s��λ��=%d\n", e1, pos);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("Ԫ��\"ѧ��=%d\"��λ��=%d\n", e1.num, pos);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("Ԫ��\"ѧ��=%d\"��λ��=%d\n", e1->num, pos);
#else	//ȱʡ����int����
    	printf("Ԫ��%d��λ��=%d\n", e1, pos);
#endif
    else
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("�Ҳ���Ԫ��%5.1f\n", e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("�Ҳ���Ԫ��%s\n", e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("�Ҳ���Ԫ��\"ѧ��=%d\"\n", e1.num);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("�Ҳ���Ԫ��\"ѧ��=%d\"\n", e1->num);
#else	//ȱʡ����int����
    	printf("�Ҳ���Ԫ��%d\n", e1);
#endif

#ifdef ELEMTYPE_IS_DOUBLE
    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%lf", &e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%s", e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    printf("\n������Ҫ����Ԫ�ص�ֵ(ѧ�� ���� �Ա� �ɼ� ��ַ)��\n");
    scanf("%d %s %c %f %s", &e1.num, e1.name, &e1.sex, &e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    printf("\n������Ҫ����Ԫ�ص�ֵ(ѧ�� ���� �Ա� �ɼ� ��ַ)��\n");
    scanf("%d %s %c %f %s", &e1->num, e1->name, &e1->sex, &e1->score, e1->addr);
#else	//ȱʡ����int����
    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%d", &e1);
#endif

    printf("������Ҫ����Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1, MyMove, MyAssign, MyAlloc)==OK) {
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("��%dǰ����Ԫ��=%5.1f�ɹ�\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("��%dǰ����Ԫ��=%s�ɹ�\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("��%dǰ����Ԫ��=\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("��%dǰ����Ԫ��=\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
    	printf("��%dǰ����Ԫ��=%d�ɹ�\n", pos, e1);
#endif
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("��%dǰ����Ԫ��=%5.1fʧ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("��%dǰ����Ԫ��=%sʧ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("��%dǰ����Ԫ��=\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("��%dǰ����Ԫ��=\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
    	printf("��%dǰ����Ԫ��%dʧ��\n", pos, e1);
#endif

    printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1, MyMove, MyAssign, MyFree)==OK) {
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("ɾ����%dԪ��=%5.1f�ɹ�\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("ɾ����%dԪ��=%s�ɹ�\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"�ɹ�\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
    	printf("ɾ����%dԪ��=%d�ɹ�\n", pos, e1);
#endif
    	printf("�±�Ϊ��\n");
	ListTraverse(L, MyVisit);
    	}
    else
#ifdef ELEMTYPE_IS_DOUBLE
    	printf("ɾ����%dԪ��=%5.1fʧ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
    	printf("ɾ����%dԪ��=%sʧ��\n", pos, e1);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    	printf("ɾ����%dԪ��=\"%d.%s.%c.%f.%s\"ʧ��\n", pos, e1->num, e1->name, e1->sex, e1->score, e1->addr);
#else	//ȱʡ����int����
    	printf("ɾ����%dԪ��=%dʧ��\n", pos, e1);
#endif

    printf("\n��ձ�\n");
    ClearList(&L, MySubFree);
    printf("�ձ�=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("��=%d\n", ListLength(L));

    DestroyList(&L, MySubFree);

    return 0;
}
