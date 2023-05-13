#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#include <unistd.h>		//exit����
#include "linear_list_DL.h"	//��ʽ����

/* ��ʼ�����Ա� */
Status InitList(DuLinkList *L)
{
    /* ����ͷ���ռ䣬��ֵ��ͷָ�� */
    *L = (DuLNode *)malloc(sizeof(DuLNode));
    if (*L==NULL)
	exit(OVERFLOW);

    (*L)->prior = NULL;
    (*L)->next  = NULL;
    return OK;
}

/* ɾ�����Ա� */
Status DestroyList(DuLinkList *L)
{
    DuLinkList q, p = *L; //ָ����Ԫ

    /* ��������(��ͷ���)�����ͷ�(ͬ������������priorָ�룬ֻ��next) */
    while(p) {    //������Ϊ�գ���ѭ����ִ��
	q=p->next; //ץס�������һ�����
	free(p);
	p=q;
	}

    *L=NULL;	//ͷָ����NULL
    return OK;
}

/* ������Ա�����ͷ��㣩 */
Status ClearList(DuLinkList *L)
{
    DuLinkList q, p = (*L)->next;

    /* ����Ԫ��㿪ʼ�����ͷ�(ͬ������������priorָ�룬ֻ��next) */
    while(p) {
	q = p->next;   //ץס�������һ�����
	free(p);
	p = q;
	}

    (*L)->next = NULL; //ͷ����prior����NULL
    (*L)->next = NULL; //ͷ����next����NULL
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(DuLinkList L)
{
    /* �ж�ͷ����next�򼴿�(ͬ������) */
    if (L->next==NULL)
	return TRUE;
    else
	return FALSE;
}

/* ���ĳ��� */
int ListLength(DuLinkList L)
{
    DuLinkList p = L->next; //ָ����Ԫ���
    int len=0;

    /* ѭ�������������м���(ͬ������) */
    while(p) {
	p = p->next;
	len++;
	}

    return len;
}

/* ȡ����Ԫ�� */
Status GetElem(DuLinkList L, int i, ElemType *e)
{
    DuLinkList p = L->next;	//ָ����Ԫ���
    int    pos = 1;		//��ʼλ��Ϊ1
 
    /* ����ΪNULL �� δ����i��Ԫ��(ͬ������) */
    while(p!=NULL && pos<i) {
    	p=p->next;
    	pos++;
	}

    if (!p || pos>i)
    	return ERROR;

    *e = p->data;
    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    DuLinkList p = L->next;	//��Ԫ���
    int    pos = 1;		//��ʼλ��

    /* ѭ����������(ͬ������)  */
    while(p && (*compare)(e, p->data)==FALSE) {
	p=p->next;
	pos++;
	}

    return p ? pos:0;
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e)
{
    DuLinkList p = L->next;	//ָ����Ԫ���

    if (p==NULL)	//�ձ�ֱ�ӷ���
    	return ERROR;

    /* �ӵ�2����㿪ʼѭ����������(����Ƚ���ȣ���֤��ǰ��)(ͬ������) */
    while(p->next && p->next->data != cur_e)
        p = p->next;

    if (p->next==NULL) //δ�ҵ�
    	return ERROR;
 
    *pre_e = p->data;
    return OK;
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e)
{
    DuLinkList p = L->next;  //��Ԫ���

    if (p==NULL)	//�ձ�ֱ�ӷ���
    	return ERROR;    

    /* �к�̽���ҵ�ǰ���ֵ����ʱ����(ͬ������) */
    while(p->next && p->data!=cur_e)
        p = p->next;

    if (p->next==NULL)
    	return ERROR;

    *next_e = p->next->data;
    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(DuLinkList *L, int i, ElemType e)
{
#if 0
    DuLinkList s, p = *L;	//pָ��ͷ���
    int      pos  = 1;

    /* Ѱ�ҵ�i�����(i�����Ǳ�+1) */
    while(p->next && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==NULL || pos>i-1)  //iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����

    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (s==NULL)
	return OVERFLOW;

    if (pos==i-1) {
	}
    else {
	/* ע�⣬p������NULL */
	s->data = e; 	//�½��������ֵ
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;	//�½���next�ǵ�i��
	 p->prior = s;	//��i-1����next���½��
	}
#else
    DuLinkList s, p = *L;	//pָ��ͷ���
    int      pos  = 0;

    /* Ѱ�ҵ�i-1����� */
    while(p && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p==NULL || pos>i)  //iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (s==NULL)
	return OVERFLOW;

    s->data = e; 	//�½��������ֵ
    s->next = p->next;  //�½���next�ǵ�i�����(��ʹp->next��NULLҲû����)
    if (p->next) //����е�i�����
        p->next->prior = s; //��i������prior��s
    s->prior = p;       //s��ǰ����p
    p->next = s;        //p�ĺ����s
#endif

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
#if 1
    DuLinkList p = *L;	//pָ��ͷ���
    int      pos  = 0;

    /* Ѱ�ҵ�i����㣨p�ǵ�i����㣩 */
    while(p && pos<i) {
	p=p->next;
	pos++;
	}

    if (p==NULL || pos>i)	//iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i�����

    *e = p->data;      //ȡ��i������ֵ
    p->prior->next = p->next;
    if (p->next) //Ҫ���ж�����
        p->next->prior = p->prior;
    free(p);           //�ͷŵ�i�����
#else
    DuLinkList q, p = *L;	//pָ��ͷ���
    int      pos  = 0;

    /* Ѱ�ҵ�i����㣨p->next�ǵ�i����㣩 */
    while(p->next && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==NULL || pos>i-1)	//iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i-1�����

    q = p->next;       //qָ���i�����
    p->next = q->next; //��i-1������next��ָ���i+1��(��ʹNULLҲû��)
    if (q->next)
    	q->next->prior = p;

    *e = q->data;      //ȡ��i������ֵ
    free(q);           //�ͷŵ�i�����
#endif

    return OK;
}

/* �������Ա� */
Status ListTraverse(DuLinkList L, Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    DuLinkList p = L->next;
    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�

#if 1
    while(p && (*visit)(p->data)==TRUE) //ͬ������
	p=p->next;

    if (p)
    	return ERROR;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
#else
    /* ������� */
    while(p->next) //ͬ������
	p=p->next;

    /* ִ�е��ˣ�pָ�����һ����� */
    while(p && p->prior && (*visit)(p->data)==TRUE) //ͬ������
	p=p->prior;

    printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
#endif

    return OK;
}
