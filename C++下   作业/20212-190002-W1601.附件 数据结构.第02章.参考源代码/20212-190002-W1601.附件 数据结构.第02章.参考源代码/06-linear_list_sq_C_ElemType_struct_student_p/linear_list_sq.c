#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数
#include <unistd.h>		//exit函数
#include <string.h>
#include "linear_list_sq.h"	//形式定义

/* 初始化线性表 */
Status InitList(sqlist *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (L->elem == NULL)
    	exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/* 删除线性表 */
Status DestroyList(sqlist *L)
{
    int i;
    /* 释放二级空间 */
    for (i=0; i<L->length; i++)
	free(L->elem[i]);

    /* 若未执行 InitList，直接执行本函数，则可能出错，因为指针初始值未定 */
    if (L->elem)
    	free(L->elem);
    L->length   = 0;
    L->listsize = 0;

    return OK;
}

/* 清除线性表（已初始化，不释放空间，只清除内容） */
Status ClearList(sqlist *L)
{
    int i;
    /* 释放二级空间 */
    for (i=0; i<L->length; i++)
	free(L->elem[i]);

    L->length = 0;
    return OK;
}

/* 判断是否为空表 */
Status ListEmpty(sqlist L)
{
    if (L.length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* 求表的长度 */
int ListLength(sqlist L)
{
    return L.length;
}

/* 取表中元素 */
Status GetElem(sqlist L, int i, ElemType *e)
{
    if (i<1 || i>L.length)  //不需要多加 || L.length>0
    	return ERROR;

    memcpy(*e, L.elem[i-1], sizeof(ET));//下标从0开始，第i个实际在elem[i-1]中
    return OK;
}

/* 假设存在一个函数compare，用于比较e1/e2是否相等（可按需改为其它比较形式）*/
extern Status MyCompare(ElemType e1, ElemType e2);

/* 查找符合指定条件的元素 */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    int i;
    for(i=1; i<=L.length; i++)
        if ((*compare)(e, L.elem[i-1])==TRUE) //i实际存放在[i-1]中
            return i;

    return 0;	//若循环完成，则返回找不到
}

/* 查找符合指定条件的元素的前驱元素 */
Status PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e)
{
    int pos;
    for (pos=1; pos<=L.length; pos++)
        if (L.elem[pos-1]->num == cur_e->num) //第pos个实际存放在[pos-1]中
            break;

    if (pos<=1 || pos>L.length)
    	return ERROR;

    memcpy(*pre_e, L.elem[pos-2], sizeof(ET));//取前驱元素的值
    return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status NextElem(sqlist L, ElemType cur_e, ElemType *next_e)
{
    int pos;
    for (pos=1; pos<=L.length; pos++)
        if (L.elem[pos-1]->num == cur_e->num)
            break;

    if (pos>=L.length)
    	return ERROR;

    memcpy(*next_e, L.elem[pos], sizeof(ET)); //第pos个存放在[pos-1]中，因此[pos]中实际是pos的后继
    return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(sqlist *L, int i, ElemType e)
{
    ElemType *p, *q; //如果是算法，一般可以省略，程序不能

    if (i<1 || i>L->length+1)   //合理范围是 1..length+1
    	return ERROR;
    
    /* 空间已满则扩大空间 */
    if (L->length >= L->listsize) {
	ElemType *newbase;
	newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
	if (!newbase)
	    return OVERFLOW;

	L->elem = newbase;
	L->listsize += LISTINCREMENT;
	//L->length暂时不变
	}

    q = &(L->elem[i-1]);  //第i个元素，即新的插入位置
    /* 从最后一个【length放在[length-1]中】开始到第i个元素依次后移一格 */
    for (p=&(L->elem[L->length-1]); p>=q; --p)
        *(p+1) = *p;

    /* 插入新元素，长度+1 */
    L->elem[i-1] = (ElemType)malloc(sizeof(ET));
    if (L->elem[i-1]==NULL)
    	return OVERFLOW;
    memcpy(*q, e, sizeof(ET));
    L->length ++;

    return OK;
}

/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status ListDelete(sqlist *L, int i, ElemType *e)
{
    ElemType *p, *q; //如果是算法，一般可以省略，程序不能

    if (i<1 || i>L->length) //合理范围是 1..length
    	return ERROR;

    p = &(L->elem[i-1]); 		//指向第i个元素
    memcpy(*e, *p, sizeof(ET));		//取第i个元素的值放入e中
    q = &(L->elem[L->length-1]);	//指向最后一个元素，也可以 q = L->elem+L->length-1

    /* 从第i+1到最后，依次前移一格 */
    free(*p);	//释放空间
    for (++p; p<=q; ++p)
	*(p-1) = *p;

    L->length --;	//长度-1
    return OK;
}

/* 假设存在一个函数myvisit，用于打印元素的值 */
extern Status MyVisit(ElemType e);

/* 遍历线性表 */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    int i;
    for (i=1; i<=L.length; i++)
        if (((*visit)(L.elem[i-1]))==FALSE)
            return ERROR;

    printf("\n");//最后打印一个换行，只是为了好看，与算法无关
    return OK;
}
