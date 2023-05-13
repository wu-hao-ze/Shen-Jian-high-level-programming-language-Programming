#include <stdio.h>
#include "linear_list_sq.h"

#define INSERT_NUM		115		//初始插入表中的元素数量
#define MAX_NUM_PER_LINE 	1		//每行最多输出的元素个数

int line_count = 0;   //打印链表时的计数器

/* 用于比较两个值是否相等的具体函数，与LocateElem中的函数指针定义相同，调用时代入
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
    if (e1.num == e2.num)
    	return TRUE;
    else
    	return FALSE;
}

/* 用于访问某个元素的值的具体函数，与ListTraverse中的函数指针定义相同，调用时代入
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
    printf("%d-%s-%c-%f-%s->", e.num, e.name, e.sex, e.score, e.addr);

    /* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	printf("\n");

    return OK;
}

int main()
{
    sqlist   L;
    ElemType e[]={{1001, "张三", 'M', 76.5, "上海市杨浦区"},
		  {1002, "李四", 'F', 87, "上海市普陀区"},
		  {1003, "王五", 'M', 80, "浙江省杭州市"},
		  {1004, "赵六", 'M', 54, "浙江省绍兴市"},
		  {1005, "牛七", 'F', 85, "江苏省南京市"},
		  {1006, "马八", 'M', 60, "江苏省苏州市"}};
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("空表=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("表长=%d\n\n", ListLength(L));

    printf("插入6个元素：\n");
    for (i=0; i<6; i++)
	ListInsert(&L, ListLength(L)+1, e[i]);
    ListTraverse(L, MyVisit);

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
	    printf("第%d个元素=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

	    /* 只有取得了某个元素，才能取前驱和后继 */
	    if (PriorElem(L, e1, &e2)==OK)
    		printf("第%d个元素\"%d.%s.%c.%f.%s\"的前驱=\"%d.%s.%c.%f.%s\"\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
	    else
    		printf("无法取得第%d个元素\"%d.%s.%c.%f.%s\"的前驱\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

	    if (NextElem(L, e1, &e2)==OK)
	    	printf("第%d个元素\"%d.%s.%c.%f.%s\"的后继=\"%d.%s.%c.%f.%s\"\n\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr, e2.num, e2.name, e2.sex, e2.score, e2.addr);
	    else
	    	printf("无法取得第%d个元素\"%d.%s.%c.%f.%s\"的后继\n\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
	    }
	else
	    printf("无法取得第%d个元素\n\n", pos);
        } // end of for

    printf("\n请输入要查找的元素的学号：\n");
    scanf("%d", &e1.num);
    /* 因为 e1.num 被赋值为学号，而且返回是位序，因此e1中num是正确的，其它成员的值不要打印 */
    if ((pos=LocateElem(L, e1, MyCompare))>0)
    	printf("元素\"学号=%d\"的位序=%d\n", e1.num, pos);
    else
    	printf("找不到元素\"学号=%d\"\n", e1.num);

    printf("\n请输入要插入元素的值(学号 姓名 性别 成绩 地址)：\n");
    scanf("%d %s %c %f %s", &e1.num, e1.name, &e1.sex, &e1.score, e1.addr);
    printf("请输入要插入元素的位序：\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1)==OK) {
    	printf("在%d前插入元素\"%d.%s.%c.%f.%s\"成功\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
    	printf("新表为：\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("在%d前插入元素\"%d.%s.%c.%f.%s\"失败\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

    printf("\n请输入要删除元素的位序：\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1)==OK) {
    	printf("删除第%d元素=\"%d.%s.%c.%f.%s\"成功\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);
    	printf("新表为：\n");
	ListTraverse(L, MyVisit);
    	}
    else
    	printf("删除第%d元素=\"%d.%s.%c.%f.%s\"失败\n", pos, e1.num, e1.name, e1.sex, e1.score, e1.addr);

    printf("\n清空表：\n");
    ClearList(&L);
    printf("空表=%s\n", (ListEmpty(L)==TRUE)?"TRUE":"FALSE");
    printf("表长=%d\n", ListLength(L));

    DestroyList(&L);

    return 0;
}
