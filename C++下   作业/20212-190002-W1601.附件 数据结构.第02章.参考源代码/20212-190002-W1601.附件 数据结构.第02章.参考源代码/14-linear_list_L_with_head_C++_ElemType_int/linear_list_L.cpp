#include <iostream>
#include <cstdlib>
#include "linear_list_L.h"	//��ʽ����

using namespace std;

/* ���캯������ʼ�����Ա� */
LinkList::LinkList()
{
    /* ����ͷ���ռ䣬��ֵ��ͷָ�� */
    head = new LNode;
    if (head == NULL)
    	exit(OVERFLOW);

    head->next = NULL;
}

/* ����������ɾ�����Ա� */
LinkList::~LinkList()
{
    LNode *q, *p = head;

    /* ��ͷ��㿪ʼ�����ͷţ���ͷ��㣩 */
    while(p) {    //������Ϊ�գ���ѭ����ִ��
	q=p->next; //ץס�������һ�����
	delete p;
	p=q;
	}

    head = NULL;	//ͷָ����NULL
}

/* ������Ա�����ͷ��㣩 */
Status LinkList::ClearList()
{
    LNode *q, *p = head->next;

    /* ����Ԫ��㿪ʼ�����ͷ� */
    while(p) {
	q = p->next;   //ץס�������һ�����
	delete p;
	p = q;
	}

    head->next = NULL; //ͷ����next����NULL
    return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status LinkList::ListEmpty()
{
    /* �ж�ͷ����next�򼴿� */
    if (head->next==NULL)
	return TRUE;
    else
	return FALSE;
}

/* ���ĳ��� */
int LinkList::ListLength()
{
    LNode *p = head->next; //ָ����Ԫ���
    int    len = 0;

    /* ѭ�������������м��� */
    while(p) {
	p = p->next;
	len++;
	}

    return len;
}

/* ȡ����Ԫ�� */
Status LinkList::GetElem(int i, ElemType &e)
{
    LNode *p = head->next;	//ָ����Ԫ���
    int  pos = 1;		//��ʼλ��Ϊ1
 
    /* ����ΪNULL �� δ����i��Ԫ�� */
    while(p!=NULL && pos<i) {
    	p=p->next;
    	pos++;
	}

    if (!p || pos>i)
    	return ERROR;

    e = p->data;
    return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LinkList::LocateElem(ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    LNode *p = head->next;	//ָ����Ԫ���
    int  pos = 1;		//��ʼλ��Ϊ1

    /* ѭ����������  */
    while(p && (*compare)(e, p->data)==FALSE) {
	p=p->next;
	pos++;
	}

    return p ? pos:0;
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status LinkList::PriorElem(ElemType cur_e, ElemType &pre_e)
{
#if 1
    LNode *p = head->next;	//ָ����Ԫ���

    if (p==NULL)	//�ձ�ֱ�ӷ���
    	return ERROR;

    /* �ӵ�2����㿪ʼѭ����������(����Ƚ���ȣ���֤��ǰ��) */
    while(p->next && p->next->data != cur_e)
        p = p->next;

    if (p->next==NULL) //δ�ҵ�
    	return ERROR;
 
    pre_e = p->data;
    return OK;
#else
    LNode *p = head; //ָ��ͷ���

    /* ѭ�����������Ƚ�ֵ�Ƿ���� */
    while(p->next && p->next->data != cur_e)
        p = p->next;

    if (p->next==NULL || p==head) //δ�ҵ�����Ԫ����ձ�
    	 return ERROR;

    pre_e = p->data;
    return OK;
#endif
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status LinkList::NextElem(ElemType cur_e, ElemType &next_e)
{
    LNode *p = head->next;  //��Ԫ���

    if (p==NULL)	//�ձ�ֱ�ӷ���
    	return ERROR;    

    /* �к�̽���ҵ�ǰ���ֵ����ʱ���� */
    while(p->next && p->data!=cur_e)
        p = p->next;

    if (p->next==NULL)
    	return ERROR;

    next_e = p->next->data;
    return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status LinkList::ListInsert(int i, ElemType e)
{
    LNode *s, *p = head;	//pָ��ͷ���
    int   pos  = 0;

    /* Ѱ�ҵ�i-1����� */
    while(p && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p==NULL || pos>i-1)  //iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����

    s = new LNode;
    if (s==NULL)
	return OVERFLOW;

    s->data = e; 	//�½��������ֵ
    s->next = p->next;	//�½���next�ǵ�i��
    p->next = s;	//��i-1����next���½��

    return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status LinkList::ListDelete(int i, ElemType &e)
{
    LNode *q, *p = head;	//pָ��ͷ���
    int   pos  = 0;

    /* Ѱ�ҵ�i����㣨p->next�ǵ�i����㣩 */
    while(p->next && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==NULL || pos>i-1)	//iֵ�Ƿ��򷵻�
	return ERROR;

    //ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i-1�����

    q = p->next;       //qָ���i�����
    p->next = q->next; //��i-1������next��ָ���i+1��

    e = q->data;      //ȡ��i������ֵ
    delete q;           //�ͷŵ�i�����
    
    return OK;
}

/* �������Ա� */
Status LinkList::ListTraverse(Status (*visit)(ElemType e))
{
    extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
    LNode *p = head->next;

    line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
    while(p && (*visit)(p->data)==TRUE)
	p=p->next;

    if (p)
    	return ERROR;

    cout << endl;	//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
    return OK;
}
