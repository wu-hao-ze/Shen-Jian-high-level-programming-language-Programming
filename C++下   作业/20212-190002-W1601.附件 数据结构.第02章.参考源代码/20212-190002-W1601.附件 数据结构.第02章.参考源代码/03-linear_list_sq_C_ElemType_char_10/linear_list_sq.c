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

    strcpy(*e, L.elem[i-1]);	//下标从0开始，第i个实际在elem[i-1]中
    return OK;
}

/* 查找符合指定条件的元素 */
int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = L.elem;
    int       i = 1;

    while(i<=L.length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=L.length) ? i : 0;	//找到返回i，否则返回0
}

/* 查找符合指定条件的元素的前驱元素 */
Status PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e)
{
    ElemType *p = L.elem;
    int       i = 1;

    /* 循环比较整个线性表 */
    while(i<=L.length && strcmp(*p, cur_e)) {
    	i++;
    	p++;
	}

    if (i==1 || i>L.length) //找到第1个元素或未找到
    	return ERROR;

    strcpy(*pre_e, *--p);	//取前驱元素的值
    return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status NextElem(sqlist L, ElemType cur_e, ElemType *next_e)
{
    ElemType *p = L.elem;
    int       i = 1;

    /* 循环比较整个线性表(不含尾元素) */
    while(i<L.length && strcmp(*p, cur_e)) {
    	i++;
    	p++;
	}

    if (i>=L.length)	//未找到（最后一个元素未比较）
    	return ERROR;

    strcpy(*next_e, *++p);	//取后继元素的值
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
        strcpy(*(p+1), *p);

    /* 插入新元素，长度+1 */
    strcpy(*q, e);
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
    strcpy(*e, *p); 				//取第i个元素的值放入e中
    q = &(L->elem[L->length-1]);	//指向最后一个元素，也可以 q = L->elem+L->length-1

    /* 从第i+1到最后，依次前移一格 */
    for (++p; p<=q; ++p)
	strcpy(*(p-1), *p);

    L->length --;	//长度-1
    return OK;
}

/* 遍历线性表 */
Status ListTraverse(sqlist L, Status (*visit)(ElemType e))
{
    extern int line_count; //在main中定义的打印换行计数器（与算法无关）
    ElemType *p = L.elem;
    int       i = 1;

    line_count = 0;		//计数器恢复初始值（与算法无关）
    while(i<=L.length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=L.length)
    	return ERROR;

    printf("\n");//最后打印一个换行，只是为了好看，与算法无关
    return OK;
}
