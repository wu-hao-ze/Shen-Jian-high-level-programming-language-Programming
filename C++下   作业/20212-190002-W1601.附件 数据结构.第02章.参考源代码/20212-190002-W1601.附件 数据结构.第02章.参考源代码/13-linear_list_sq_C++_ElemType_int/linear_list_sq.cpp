#include <iostream>
#include <stdlib.h>		//malloc/realloc����
#include <unistd.h>		//exit����
#include <string.h>
#include "linear_list_sq.h"	//��ʽ����

using namespace std;

/* ���캯������� InitList */
sqlist::sqlist()
{
    elem = new ElemType[LIST_INIT_SIZE];
    if (elem == NULL)
    	exit(OVERFLOW);
    length = 0;
    listsize = LIST_INIT_SIZE;
}

/* ������������� DestroyList */
sqlist::~sqlist()
{
    if (elem)
    	delete elem;
    length   = 0;
    listsize = 0;
}

/* ������Ա��ѳ�ʼ�������ͷſռ䣬ֻ������ݣ� */
Status sqlist::ClearList()
{
    length = 0;
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status sqlist::ListEmpty()
{
    if (length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ĳ��� */
int sqlist::ListLength()
{
    return length;
}

/* ȡ����Ԫ�� */
Status sqlist::GetElem(int i, ElemType &e)
{
    if (i<1 || i>length)  //����Ҫ��� || L.length>0
    	return ERROR;

    e = elem[i-1];	//�±��0��ʼ����i��ʵ����elem[i-1]��
    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int sqlist::LocateElem(ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = elem;
    int       i = 1;

    while(i<=length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=length) ? i : 0;	//�ҵ�����i�����򷵻�0
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status sqlist::PriorElem(ElemType cur_e, ElemType &pre_e)
{
    ElemType *p = elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա� */
    while(i<=length && *p!=cur_e) {
    	i++;
    	p++;
	}

    if (i==1 || i>length) //�ҵ���1��Ԫ�ػ�δ�ҵ�
    	return ERROR;

    pre_e = *--p;	//ȡǰ��Ԫ�ص�ֵ
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status sqlist::NextElem(ElemType cur_e, ElemType &next_e)
{
    ElemType *p = elem;
    int       i = 1;

    /* ѭ���Ƚ��������Ա�(����βԪ��) */
    while(i<length && *p!=cur_e) {
    	i++;
    	p++;
	}

    if (i>=length)	//δ�ҵ������һ��Ԫ��δ�Ƚϣ�
    	return ERROR;

    next_e = *++p;	//ȡ���Ԫ�ص�ֵ
    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status sqlist::ListInsert(int i, ElemType e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>length+1)   //����Χ�� 1..length+1
    	return ERROR;
    
    /* �ռ�����������ռ� */
    if (length >= listsize) {
	ElemType *newbase;
	newbase = new ElemType[listsize+LISTINCREMENT];
	if (!newbase)
	    return OVERFLOW;

	/* ԭ����listsize��ElemType�ռ���и��� */
	memcpy(newbase, elem, listsize*sizeof(ElemType));

	delete elem;
	elem = newbase;
	listsize += LISTINCREMENT;
	//length��ʱ����
	}

    q = &(elem[i-1]);  //��i��Ԫ�أ����µĲ���λ��

    /* �����һ����length����[length-1]�С���ʼ����i��Ԫ�����κ���һ�� */
    for (p=&(elem[length-1]); p>=q; --p)
        *(p+1) = *p;

    /* ������Ԫ�أ�����+1 */
    *q = e;
    length ++;

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status sqlist::ListDelete(int i, ElemType &e)
{
    ElemType *p, *q; //������㷨��һ�����ʡ�ԣ�������

    if (i<1 || i>length) //����Χ�� 1..length
    	return ERROR;

    p = &(elem[i-1]); 		//ָ���i��Ԫ��
    e = *p; 				//ȡ��i��Ԫ�ص�ֵ����e��
    q = &(elem[length-1]);	//ָ�����һ��Ԫ�أ�Ҳ���� q = L->elem+L->length-1

    /* �ӵ�i+1���������ǰ��һ�� */
    for (++p; p<=q; ++p)
	*(p-1) = *p;

    length --;	//����-1
    return OK;
}

/* �������Ա� */
Status sqlist::ListTraverse(Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    ElemType *p = elem;
    int       i = 1;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(i<=length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=length)
    	return ERROR;

    cout << endl;	//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
