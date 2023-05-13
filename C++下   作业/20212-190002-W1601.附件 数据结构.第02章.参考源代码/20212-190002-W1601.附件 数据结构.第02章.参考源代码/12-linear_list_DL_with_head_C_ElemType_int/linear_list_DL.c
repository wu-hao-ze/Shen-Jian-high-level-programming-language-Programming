#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数
#include <unistd.h>		//exit函数
#include "linear_list_DL.h"	//形式定义

/* 初始化线性表 */
Status InitList(DuLinkList *L)
{
    /* 申请头结点空间，赋值给头指针 */
    *L = (DuLNode *)malloc(sizeof(DuLNode));
    if (*L==NULL)
	exit(OVERFLOW);

    (*L)->prior = NULL;
    (*L)->next  = NULL;
    return OK;
}

/* 删除线性表 */
Status DestroyList(DuLinkList *L)
{
    DuLinkList q, p = *L; //指向首元

    /* 整个链表(含头结点)依次释放(同单链表，不考虑prior指针，只用next) */
    while(p) {    //若链表为空，则循环不执行
	q=p->next; //抓住链表的下一个结点
	free(p);
	p=q;
	}

    *L=NULL;	//头指针置NULL
    return OK;
}

/* 清除线性表（保留头结点） */
Status ClearList(DuLinkList *L)
{
    DuLinkList q, p = (*L)->next;

    /* 从首元结点开始依次释放(同单链表，不考虑prior指针，只用next) */
    while(p) {
	q = p->next;   //抓住链表的下一个结点
	free(p);
	p = q;
	}

    (*L)->next = NULL; //头结点的prior域置NULL
    (*L)->next = NULL; //头结点的next域置NULL
    return OK;
}

/* 判断是否为空表 */
Status ListEmpty(DuLinkList L)
{
    /* 判断头结点的next域即可(同单链表) */
    if (L->next==NULL)
	return TRUE;
    else
	return FALSE;
}

/* 求表的长度 */
int ListLength(DuLinkList L)
{
    DuLinkList p = L->next; //指向首元结点
    int len=0;

    /* 循环整个链表，进行计数(同单链表) */
    while(p) {
	p = p->next;
	len++;
	}

    return len;
}

/* 取表中元素 */
Status GetElem(DuLinkList L, int i, ElemType *e)
{
    DuLinkList p = L->next;	//指向首元结点
    int    pos = 1;		//初始位置为1
 
    /* 链表不为NULL 且 未到第i个元素(同单链表) */
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
int LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    DuLinkList p = L->next;	//首元结点
    int    pos = 1;		//初始位置

    /* 循环整个链表(同单链表)  */
    while(p && (*compare)(e, p->data)==FALSE) {
	p=p->next;
	pos++;
	}

    return p ? pos:0;
}

/* 查找符合指定条件的元素的前驱元素 */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e)
{
    DuLinkList p = L->next;	//指向首元结点

    if (p==NULL)	//空表直接返回
    	return ERROR;

    /* 从第2个结点开始循环整个链表(如果比较相等，保证有前驱)(同单链表) */
    while(p->next && p->next->data != cur_e)
        p = p->next;

    if (p->next==NULL) //未找到
    	return ERROR;
 
    *pre_e = p->data;
    return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e)
{
    DuLinkList p = L->next;  //首元结点

    if (p==NULL)	//空表直接返回
    	return ERROR;    

    /* 有后继结点且当前结点值不等时继续(同单链表) */
    while(p->next && p->data!=cur_e)
        p = p->next;

    if (p->next==NULL)
    	return ERROR;

    *next_e = p->next->data;
    return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(DuLinkList *L, int i, ElemType e)
{
#if 0
    DuLinkList s, p = *L;	//p指向头结点
    int      pos  = 1;

    /* 寻找第i个结点(i可能是表长+1) */
    while(p->next && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==NULL || pos>i-1)  //i值非法则返回
	return ERROR;

    //执行到此表示找到指定位置，p指向第i-1个结点

    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (s==NULL)
	return OVERFLOW;

    if (pos==i-1) {
	}
    else {
	/* 注意，p可能是NULL */
	s->data = e; 	//新结点数据域赋值
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;	//新结点的next是第i个
	 p->prior = s;	//第i-1个的next是新结点
	}
#else
    DuLinkList s, p = *L;	//p指向头结点
    int      pos  = 0;

    /* 寻找第i-1个结点 */
    while(p && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p==NULL || pos>i)  //i值非法则返回
	return ERROR;

    //执行到此表示找到指定位置，p指向第i-1个结点
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (s==NULL)
	return OVERFLOW;

    s->data = e; 	//新结点数据域赋值
    s->next = p->next;  //新结点的next是第i个结点(即使p->next是NULL也没问题)
    if (p->next) //如果有第i个结点
        p->next->prior = s; //第i个结点的prior是s
    s->prior = p;       //s的前驱是p
    p->next = s;        //p的后继是s
#endif

    return OK;
}

/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
#if 1
    DuLinkList p = *L;	//p指向头结点
    int      pos  = 0;

    /* 寻找第i个结点（p是第i个结点） */
    while(p && pos<i) {
	p=p->next;
	pos++;
	}

    if (p==NULL || pos>i)	//i值非法则返回
	return ERROR;

    //执行到此表示找到了第i个结点，此时p指向第i个结点

    *e = p->data;      //取第i个结点的值
    p->prior->next = p->next;
    if (p->next) //要加判断条件
        p->next->prior = p->prior;
    free(p);           //释放第i个结点
#else
    DuLinkList q, p = *L;	//p指向头结点
    int      pos  = 0;

    /* 寻找第i个结点（p->next是第i个结点） */
    while(p->next && pos<i-1) {
	p=p->next;
	pos++;
	}

    if (p->next==NULL || pos>i-1)	//i值非法则返回
	return ERROR;

    //执行到此表示找到了第i个结点，此时p指向第i-1个结点

    q = p->next;       //q指向第i个结点
    p->next = q->next; //第i-1个结点的next域指向第i+1个(即使NULL也没错)
    if (q->next)
    	q->next->prior = p;

    *e = q->data;      //取第i个结点的值
    free(q);           //释放第i个结点
#endif

    return OK;
}

/* 遍历线性表 */
Status ListTraverse(DuLinkList L, Status (*visit)(ElemType e))
{
    extern int line_count; //在main中定义的打印换行计数器（与算法无关）
    DuLinkList p = L->next;
    line_count = 0;		//计数器恢复初始值（与算法无关）

#if 1
    while(p && (*visit)(p->data)==TRUE) //同单链表
	p=p->next;

    if (p)
    	return ERROR;

    printf("\n");//最后打印一个换行，只是为了好看，与算法无关
#else
    /* 逆序输出 */
    while(p->next) //同单链表
	p=p->next;

    /* 执行到此，p指向最后一个结点 */
    while(p && p->prior && (*visit)(p->data)==TRUE) //同单链表
	p=p->prior;

    printf("\n");//最后打印一个换行，只是为了好看，与算法无关
#endif

    return OK;
}
