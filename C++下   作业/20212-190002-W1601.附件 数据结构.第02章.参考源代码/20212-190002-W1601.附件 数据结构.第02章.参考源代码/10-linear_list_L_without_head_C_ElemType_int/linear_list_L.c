#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数
#include <unistd.h>		//exit函数
#include "linear_list_L.h"	//形式定义

/* 初始化线性表 */
Status InitList(LinkList *L)
{
    *L = NULL;  //头指针直接赋NULL
    return OK;
}

/* 删除线性表 */
Status DestroyList(LinkList *L)
{
    LinkList q, p = *L; //指向首元

    /* 整个链表依次释放 */
    while(p) {    //若链表为空，则循环不执行
	q=p->next; //抓住链表的下一个结点
	free(p);
	p=q;
	}

    *L=NULL;	//头指针置NULL
    return OK;
}

/* 清除线性表（与DestroyList完全相同） */
Status ClearList(LinkList *L)
{
    LinkList q, p = *L; //指向首元

    /* 整个链表依次释放 */
    while(p) {
	q=p->next; //抓住链表的下一个结点
	free(p);
	p=q;
	}

    *L=NULL;	//头指针置NULL
    return OK;
}

/* 判断是否为空表 */
Status ListEmpty(LinkList L)
{
    /* 判断头指针即可 */
    if (L==NULL)
	return TRUE;
    else
	return FALSE;
}

/* 求表的长度 */
int ListLength(LinkList L)
{
    LinkList   p = L; //指向首元结点
    int      len = 0;

    /* 循环整个链表，进行计数 */
    while(p) {
	p = p->next;
	len++;
	}

    return len;
}

/* 取表中元素 */
Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList   p = L; //指向首元结点
    int      pos = 1; //初始位置为1
 
    /* 链表不为NULL 且 未到第i个元素 */
    while(p!=NULL && pos<i) {
    	p=p->next;
    	pos++;
	}

    if (!p || pos>i)
    	return ERROR;

    *e = p->data;
    return OK;
}

/* 查找符合指定条件的元素 */
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    LinkList   p = L;	//首元结点
    int      pos = 1;	//初始位置

    /* 循环整个链表  */
    while(p && (*compare)(e, p->data)==FALSE) {
	p=p->next;
	pos++;
	}

    return p ? pos:0;
}

/* 查找符合指定条件的元素的前驱元素 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList p = L; //指向首元结点

    if (p==NULL)	//空表直接返回
    	return ERROR;

    /* 从第2个结点开始循环整个链表(如果比较相等，保证有前驱) */
    while(p->next && p->next->data != cur_e)
        p = p->next;

    if (p->next==NULL) //未找到
    	 return ERROR;

    *pre_e = p->data;
    return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L;  //首元结点

    if (p==NULL)	//空表直接返回
    	return ERROR;    

    /* 有后继结点且当前结点值不等时继续 */
    while(p->next && p->data!=cur_e)
        p = p->next;

    if (p->next==NULL)
    	return ERROR;

    *next_e = p->next->data;
    return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
    LinkList s, p = *L;	//p指向首元结点(可能为NULL)
    int      pos  = 1;  //因为p已指向首元，故起始位置是1

    /* 如果新结点成为首元，则需要改变L的值，其它位置插入则L不变 */
    if (i != 1) {
	/* 寻找第i-1个结点 */
	while(p && pos<i-1) {
	    p=p->next;
	    pos++;
	    }

	if (p==NULL || pos>i-1)  //i值非法则返回
	    return ERROR;
	}

    s = (LinkList)malloc(sizeof(LNode));
    if (s==NULL)
	return OVERFLOW;

    s->data = e; 	//新结点数据域赋值
    if (i != 1) {
    	//插入位置非首元，此时p指向第i-1个结点
	s->next = p->next;	//新结点的next是p->next
	p->next = s;		//第i-1个的next是新结点
	}
    else {
    	//插入位置是首元
	s->next = p;	//此时p就是L（包括L=NULL的情况）
	*L = s;		//头指针指向新结点
	}

    return OK;
}

/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList q=NULL, p = *L;	//p指向首元结点(可能为NULL)
    int      pos  = 1;	//因为p已指向首元，故起始位置是1

    if (p==NULL)	//空表直接返回
    	return ERROR;

    /* 如果删除的不是首元，则查找第i个结点 */
    if (i != 1) {
	/* 寻找第i个结点（p->next是第i个结点） */
	while(p->next && pos<i-1) {
	    p=p->next;
	    pos++;
	    }

	if (p->next==NULL || pos>i-1)	//i值非法则返回
	    return ERROR;

	q = p->next;       //q指向第i个结点
	p->next = q->next; //第i-1个结点的next域指向第i+1个
	}
    else { //要删除的是首元
	q  = p;
	*L = q->next;	//如果只有一个结点，则q->next为NULL
	}

    *e = q->data;      //取第i个结点的值
    free(q);           //释放第i个结点
    
    return OK;
}

/* 遍历线性表 */
Status ListTraverse(LinkList L, Status (*visit)(ElemType e))
{
    extern int line_count;	//在main中定义的打印换行计数器（与算法无关）
    LinkList p = L;		//指向首元

    line_count = 0;		//计数器恢复初始值（与算法无关）
    while(p && (*visit)(p->data)==TRUE)
	p=p->next;

    if (p)
    	return ERROR;

    printf("\n");//最后打印一个换行，只是为了好看，与算法无关
    return OK;
}
