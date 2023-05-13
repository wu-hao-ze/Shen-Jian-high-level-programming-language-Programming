#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#include <unistd.h>		//exit����
#include <string.h>
#include "linear_list_sq.h"	//��ʽ����

/* ��ʼ�����Ա� */
Status InitList(sqlist *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL)
    	exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/* ɾ�����Ա� */
Status DestroyList(sqlist *L)
{
    int i;
    /* �ͷŶ����ռ� */
    for (i=0; i<L->length; i++)
	free(L->elem[i]);

    /* ��δִ�� InitList��ֱ��ִ�б�����������ܳ�����Ϊָ���ʼֵδ�� */
    if (L->elem)
    	free(L->elem);
    L->length   = 0;
    L->listsize = 0;

    return OK;
}

/* ������Ա��ѳ�ʼ�������ͷſռ䣬ֻ������ݣ� */
Status ClearList(sqlist *L)
{
    int i;
    /* �ͷŶ����ռ� */
    for (i=0; i<L->length; i++)
	free(L->elem[i]);

    L->length = 0;
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(sqlist L)
{
    if (L.length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ĳ��� */
int ListLength(sqlist L)
{
    return L.length;
}

/* ȡ����Ԫ�� */
Status GetElem(sqlist L, int i, ElemType *e)
{
    if (i<1 || i>L.length)  //����Ҫ��� || L.length>0
    	return ERROR;

    memcpy(*e, L.elem[i-1], sizeof(ET));//�±��0��ʼ����i��ʵ����elem[i-1]��
    return OK;
}

/* �������һ������compare�����ڱȽ�e1/e2�Ƿ���ȣ��ɰ����Ϊ�����Ƚ���ʽ��*/
extern Status MyCompare(ElemType e1, ElemType e2);

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    int i;
    for(i=1; i<=L.length; i++)
        if ((*compare)(e, L.elem[i-1])==TRUE) //iʵ�ʴ����[i-1]��
            return i;

    return 0;	//��ѭ����ɣ��򷵻��Ҳ���
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e)
{
    int pos;
    for (pos=1; pos<=L.length; pos++)
        if (L.elem[pos-1]->num == cur_e->num) //��pos��ʵ�ʴ����[pos-1]��
            break;

    if (pos<=1 || pos>L.length)
    	return ERROR;

    memcpy(*pre_e, L.elem[pos-2], sizeof(ET));//ȡǰ��Ԫ�ص�ֵ
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(sqlist L, ElemType cur_e, ElemType *next_e)
{
    int pos;
    for (pos=1; pos<=L.length; pos++)
        if (L.elem[pos-1]->num == cur_e->num)
            break;

    if (pos>=L.length)
    	return ERROR;

    memcpy(*next_e, L.elem[pos], sizeof(ET)); //��pos�������[pos-1]�У����[pos]��ʵ����pos�ĺ��
    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(sqlist *L, int i, ElemType e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length+1)   //����Χ�� 1..length+1
    	return ERROR;
    
    /* �ռ�����������ռ� */
    if (L->length >= L->listsize) {
	ElemType *newbase;
	newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
	if (!newbase)
	    return OVERFLOW;

	L->elem = newbase;
	L->listsize += LISTINCREMENT;
	//L->length��ʱ����
	}

    q = &(L->elem[i-1]);  //��i��Ԫ�أ����µĲ���λ��
    /* �����һ����length����[length-1]�С���ʼ����i��Ԫ�����κ���һ�� */
    for (p=&(L->elem[L->length-1]); p>=q; --p)
        *(p+1) = *p;

    /* ������Ԫ�أ�����+1 */
    L->elem[i-1] = (ElemType)malloc(sizeof(ET));
    if (L->elem[i-1]==NULL)
    	return OVERFLOW;
    memcpy(*q, e, sizeof(ET));
    L->length ++;

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(sqlist *L, int i, ElemType *e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>L->length) //����Χ�� 1..length
    	return ERROR;

    p = &(L->elem[i-1]); 		//ָ���i��Ԫ��
    memcpy(*e, *p, sizeof(ET));		//ȡ��i��Ԫ�ص�ֵ����e��
    q = &(L->elem[L->length-1]);	//ָ�����һ��Ԫ�أ�Ҳ���� q = L->elem+L->length-1

    /* �ӵ�i+1���������ǰ��һ�� */
    free(*p);	//�ͷſռ�
    for (++p; p<=q; ++p)
	*(p-1) = *p;

    L->length --;	//����-1
    return OK;
}

/* �������һ������myvisit�����ڴ�ӡԪ�ص�ֵ */
extern Status MyVisit(ElemType e);

/* �������Ա� */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    int i;
    for (i=1; i<=L.length; i++)
        if (((*visit)(L.elem[i-1]))==FALSE)
            return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
