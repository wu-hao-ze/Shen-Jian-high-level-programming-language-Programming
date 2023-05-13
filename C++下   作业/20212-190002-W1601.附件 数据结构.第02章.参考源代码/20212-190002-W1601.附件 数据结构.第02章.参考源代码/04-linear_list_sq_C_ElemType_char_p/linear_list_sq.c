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

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
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

    /* �����ͷŶ����ռ� */
    for(i=0; i<L->length; i++)
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

    strcpy(*e, L.elem[i-1]);	//�±��0��ʼ����i��ʵ����elem[i-1]��
    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = L.elem;
    int       i = 1;

    while(i<=L.length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=L.length) ? i : 0;	//�ҵ�����i�����򷵻�0
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e)
{
    ElemType *p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա� */
    while(i<=L.length && strcmp(*p, cur_e)) {
    	i++;
    	p++;
	}

    if (i==1 || i>L.length) //�ҵ���1��Ԫ�ػ�δ�ҵ�
    	return ERROR;

    strcpy(*pre_e, *--p);	//ȡǰ��Ԫ�ص�ֵ
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(sqlist L, ElemType cur_e, ElemType *next_e)
{
    ElemType *p = L.elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա�(����βԪ��) */
    while(i<L.length && strcmp(*p, cur_e)) {
    	i++;
    	p++;
	}

    if (i>=L.length)	//δ�ҵ������һ��Ԫ��δ�Ƚϣ�
    	return ERROR;

    strcpy(*next_e, *++p);	//ȡ���Ԫ�ص�ֵ
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

    /* ԭ��L->elem[i-1]��ָ���ѷ���[i]�У�Ҫ��������ռ䣬������Ԫ�أ�����+1 */
    L->elem[i-1] = (ElemType)malloc((strlen(e)+1) * sizeof(char));
    if (L->elem[i-1]==NULL)
    	return OVERFLOW;
    strcpy(*q, e);
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
    strcpy(*e, *p); 			//ȡ��i��Ԫ�ص�ֵ����e��
    q = &(L->elem[L->length-1]);	//ָ�����һ��Ԫ�أ�Ҳ���� q = L->elem+L->length-1

    /* �ӵ�i+1���������ǰ��һ�� */
    free(*p);	//�ͷſռ�
    for (++p; p<=q; ++p)
	*(p-1) = *p;

    L->length --;	//����-1
    return OK;
}

/* �������Ա� */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    ElemType *p = L.elem;
    int       i = 1;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(i<=L.length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=L.length)
    	return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
