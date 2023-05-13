#include <stdio.h>
#include <math.h>
#include "linear_list_sq.h"

#define INSERT_NUM		115		//初始插入表中的元素数量
#define MAX_NUM_PER_LINE 	10		//每行最多输出的元素个数

int line_count = 0;   //打印链表时的计数器

/* 用于比较两个值是否相等的具体函数，与LocateElem中的函数指针定义相同，调用时代入
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
    if (fabs(e1-e2)<1e-6)
    	return TRUE;
    else
    	return FALSE;
}

/* 用于访问某个元素的值的具体函数，与ListTraverse中的函数指针定义相同，调用时代入
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
    printf("%5.1f->", e);

    /* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	printf("\n");

    return OK;
}

int main()
{
    sqlist   L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("空表=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("表长=%d\n\n", ListLength(L));

    printf("插入%d个元素：\n", INSERT_NUM);
    for (i=INSERT_NUM*2; i>0; i-=2)
	ListInsert(&L, 1, i);
    ListTraverse(L, MyVisit);//此处传入MyVisit函数名

    printf("空表=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("表长=%d\n\n", ListLength(L));

    /* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
       最后再加一个任意输入值 */
    for (i=0; i<5; i++) {
    	int pos;
	switch(i) {
	    case 0:
	    	pos = 1;
	    	break;
	    case 1:
	    	pos = ListLength(L);
	    	break;
	    case 2:
	    	pos = -1;
	    	break;
	    case 3:
	    	pos = ListLength(L)+1;
	    	break;
	    case 4:
		printf("请输入要取元素的位序[1..%d]：", ListLength(L));
		scanf("%d", &pos);
		break;
	    }

    	/* 取第1个元素以及前驱、后继 */
	if (GetElem(L, pos, &e1)==OK) {
	    printf("第%d个元素=%5.1f\n", pos, e1);

	    /* 只有取得了某个元素，才能取前驱和后继 */
	    if (PriorElem(L, e1, &e2)==OK)
		printf("第%d个元素(%5.1f)的前驱=%5.1f\n", pos, e1, e2);
	    else
		printf("无法取得第%d个元素(%5.1f)的前驱\n", pos, e1);

	    if (NextElem(L, e1, &e2)==OK)
		printf("第%d个元素(%5.1f)的后继=%5.1f\n\n", pos, e1, e2);
	    else
		printf("无法取得第%d个元素(%5.1f)的后继\n\n", pos, e1);
	    }
	else
	    printf("无法取得第%d个元素\n\n", pos);
        } // end of for

    printf("\n请输入要查找的元素：\n");
    scanf("%lf", &e1);
    if ((pos=LocateElem(L, e1, MyCompare))>0)       //此处传入MyCompare函数名
    	printf("元素%5.1f的位序=%d\n", e1, pos);
    else
    	printf("找不到元素%5.1f\n", e1);

    printf("\n请输入要插入元素的值：\n");
    scanf("%lf", &e1);
    printf("请输入要插入元素的位序：\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1)==OK) {
    	printf("在%d前插入元素%5.1f成功\n", pos, e1);
    	printf("新表为：\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("在%d前插入元素%5.1f失败\n", pos, e1);

    printf("\n请输入要删除元素的位序：\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1)==OK) {
    	printf("删除第%d元素=%5.1f成功\n", pos, e1);
    	printf("新表为：\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("删除第%d元素=%5.1f失败\n", pos, e1);

    printf("\n清空表：\n");
    ClearList(&L);
    printf("空表=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("表长=%d\n", ListLength(L));

    DestroyList(&L);

    return 0;
}
