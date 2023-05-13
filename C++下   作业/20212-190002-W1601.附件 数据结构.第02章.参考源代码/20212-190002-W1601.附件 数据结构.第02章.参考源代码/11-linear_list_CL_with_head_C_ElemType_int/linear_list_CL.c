#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#include <unistd.h>		//exit����
#include "linear_list_CL.h"	//��ʽ����

/* ��ʼ�����Ա� */
Status InitList(LinkList *L)
{
    /* ����ͷ���ռ䣬��ֵ��ͷָ�� */
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L==NULL)
	exit(OVERFLOW);

    (*L)->next = (*L);	//ͷ����nextָ���Լ�
    return OK;
}

/* ɾ�����Ա� */
Status DestroyList(LinkList *L)
{
    LinkList q, p = *L; //ָ����Ԫ

    /* ��������(��ͷ���)�����ͷ�
       ������whileѭ�� */
    do {
	q=p->next; //ץס�������һ����㣬���ձ���qֱ��ΪNULL
	free(p);
	p=q;
    } while(p!=(*L));   //������Ϊ�գ���ѭ����ִ��

    (*L) = NULL;	//ͷ����next��NULL
    return OK;
}

/* ������Ա�����ͷ��㣩 */
Status ClearList(LinkList *L)
{
    LinkList q, p = (*L)->next;  //pָ����Ԫ

    /* ����Ԫ��㿪ʼ�����ͷ�(����ձ���while��ִ��) */
    while(p!=(*L)) {
	q = p->next;   //ץס�������һ�����
	free(p);
	p = q;
	}

    (*L)->next = (*L); //ͷ����next����L
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(LinkList L)
{
    /* �ж�ͷ����next�򼴿� */
    if (L->next==L)
	return TRUE;
    else
	return FALSE;
}

/* ���ĳ��� */
int ListLength(LinkList L)
{
    LinkList p = L->next; //ָ����Ԫ���
    int len=0;

    /* ѭ�������������м��� */
    while(p!=L) {
	p = p->next;
	len++;
	}

    return len;
}

/* ȡ����Ԫ�� */
Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;	//ָ����Ԫ���
    int    pos = 1;		//��ʼλ��Ϊ1
 
    /* ����ΪNULL �� δ����i��Ԫ�� */
    while(p != L && pos<i) {
    	p=p->next;
    	pos++;
	}

    if (p==L || pos>i)
    	return ERROR;

    *e = p->data;
    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    LinkList p = L->next;	//��Ԫ���(����Ϊ��ʱֵ����L)
    int    pos = 1;		//��ʼλ��

    /* ѭ����������  */
    while(p!=L && (*compare)(e, p->data)==FALSE) {
	p=p->next;
	pos++;
	}

    return (p!=L) ? pos:0;
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList p = L->next;	//ָ����Ԫ���

    if (p==L)	//�ձ�ֱ�ӷ���
    	return ERROR;

    /* �ӵ�2����㿪ʼѭ����������(����Ƚ���ȣ���֤��ǰ��) */
    while(p->next!=L && p->next->data != cur_e)
        p = p->next;

    if (p->next==L) //δ�ҵ�
    	return ERROR;
 
    *pre_e = p->data;
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L->next;  //��Ԫ���

    if (p==L)	//�ձ�ֱ�ӷ���
    	return ERROR;    

    /* �к�̽���ҵ�ǰ���ֵ����ʱ���� */
    while(p->next!=L && p->data!=cur_e)
        p = p->next;

    if (p->next==L)
    	return ERROR;

    *next_e = p->next->data;
    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList s, p = *L;	//pָ��ͷ���
    int      pos  = 0;

    if (i==1)
    	goto INSERT;

    /* Ѱ�ҵ�i-1����� */
    do {
	p=p->next;
	pos++;
    } while(p!=(*L) && pos<i-1);

    if (p==(*L) || pos>i-1)  //iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����
INSERT:
    s = (LinkList)malloc(sizeof(LNode));
    if (s==NULL)
	return OVERFLOW;

    s->data = e; 	//�½��������ֵ
    s->next = p->next;	//�½���next�ǵ�i��
    p->next = s;	//��i-1����next���½��

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList q, p = *L;	//pָ��ͷ���
    int      pos  = 0;

    /* Ѱ�ҵ�i����㣨p->next�ǵ�i����㣩 */
    while(p->next!=(*L) && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==(*L) || pos>i-1)	//iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i-1�����

    q = p->next;       //qָ���i�����
    p->next = q->next; //��i-1������next��ָ���i+1��

    *e = q->data;      //ȡ��i������ֵ
    free(q);           //�ͷŵ�i�����
    
    return OK;
}

/* �������Ա� */
Status ListTraverse(LinkList L, Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    LinkList p = L->next;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(p!=L && (*visit)(p->data)==TRUE)
	p=p->next;

    if (p!=L)
    	return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
