#include <iostream>
#include <stdlib.h>		//malloc/realloc函数
#include <unistd.h>		//exit函数
#include <string.h>
#include "linear_list_sq.h"	//形式定义

using namespace std;

/* 构造函数，替代 InitList */
sqlist::sqlist()
{
    elem = new ElemType[LIST_INIT_SIZE];
    if (elem == NULL)
    	exit(OVERFLOW);
    length = 0;
    listsize = LIST_INIT_SIZE;
}

/* 析构函数，替代 DestroyList */
sqlist::~sqlist()
{
    if (elem)
    	delete elem;
    length   = 0;
    listsize = 0;
}

/* 清除线性表（已初始化，不释放空间，只清除内容） */
Status sqlist::ClearList()
{
    length = 0;
    return OK;
}

/* 判断是否为空表 */
Status sqlist::ListEmpty()
{
    if (length == 0)
    	return TRUE;
    else
    	return FALSE;
}

/* 求表的长度 */
int sqlist::ListLength()
{
    return length;
}

/* 取表中元素 */
Status sqlist::GetElem(int i, ElemType &e)
{
    if (i<1 || i>length)  //不需要多加 || L.length>0
    	return ERROR;

    e = elem[i-1];	//下标从0开始，第i个实际在elem[i-1]中
    return OK;
}

/* 查找符合指定条件的元素 */
int sqlist::LocateElem(ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
    ElemType *p = elem;
    int       i = 1;

    while(i<=length && (*compare)(*p++, e)==FALSE)
        i++;
        
    return (i<=length) ? i : 0;	//找到返回i，否则返回0
}

/* 查找符合指定条件的元素的前驱元素 */
Status sqlist::PriorElem(ElemType cur_e, ElemType &pre_e)
{
    ElemType *p = elem;
    int       i = 1;

    /* 循环比较整个线性表 */
    while(i<=length && *p!=cur_e) {
    	i++;
    	p++;
	}

    if (i==1 || i>length) //找到第1个元素或未找到
    	return ERROR;

    pre_e = *--p;	//取前驱元素的值
    return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status sqlist::NextElem(ElemType cur_e, ElemType &next_e)
{
    ElemType *p = elem;
    int       i = 1;

    /* 循环比较整个线性表(不含尾元素) */
    while(i<length && *p!=cur_e) {
    	i++;
    	p++;
	}

    if (i>=length)	//未找到（最后一个元素未比较）
    	return ERROR;

    next_e = *++p;	//取后继元素的值
    return OK;
}

/* 在指定位置前插入一个新元素 */
Status sqlist::ListInsert(int i, ElemType e)
{
    ElemType *p, *q; //如果是算法，一般可以省略，程序不能

    if (i<1 || i>length+1)   //合理范围是 1..length+1
    	return ERROR;
    
    /* 空间已满则扩大空间 */
    if (length >= listsize) {
	ElemType *newbase;
	newbase = new ElemType[listsize+LISTINCREMENT];
	if (!newbase)
	    return OVERFLOW;

	/* 原来的listsize个ElemType空间进行复制 */
	memcpy(newbase, elem, listsize*sizeof(ElemType));

	delete elem;
	elem = newbase;
	listsize += LISTINCREMENT;
	//length暂时不变
	}

    q = &(elem[i-1]);  //第i个元素，即新的插入位置

    /* 从最后一个【length放在[length-1]中】开始到第i个元素依次后移一格 */
    for (p=&(elem[length-1]); p>=q; --p)
        *(p+1) = *p;

    /* 插入新元素，长度+1 */
    *q = e;
    length ++;

    return OK;
}

/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status sqlist::ListDelete(int i, ElemType &e)
{
    ElemType *p, *q; //如果是算法，一般可以省略，程序不能

    if (i<1 || i>length) //合理范围是 1..length
    	return ERROR;

    p = &(elem[i-1]); 		//指向第i个元素
    e = *p; 				//取第i个元素的值放入e中
    q = &(elem[length-1]);	//指向最后一个元素，也可以 q = L->elem+L->length-1

    /* 从第i+1到最后，依次前移一格 */
    for (++p; p<=q; ++p)
	*(p-1) = *p;

    length --;	//长度-1
    return OK;
}

/* 遍历线性表 */
Status sqlist::ListTraverse(Status (*visit)(ElemType e))
{
    extern int line_count; //在main中定义的打印换行计数器（与算法无关）
    ElemType *p = elem;
    int       i = 1;

    line_count = 0;		//计数器恢复初始值（与算法无关）
    while(i<=length && (*visit)(*p++)==TRUE)
        i++;

    if (i<=length)
    	return ERROR;

    cout << endl;	//最后打印一个换行，只是为了好看，与算法无关
    return OK;
}
