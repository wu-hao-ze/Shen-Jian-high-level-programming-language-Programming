/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

typedef int ElemType;	//可根据需要修改元素的类型

class LinkList;	//提前声明，因为定义友元要用到

class LNode {
    protected:
	ElemType data;	//数据域
	LNode   *next;	//指针域
    public:
    	friend class LinkList;
        //不定义任何函数，相当于struct LNode
};

class LinkList {
    protected:
	LNode *head;	//头指针
    public:
	/* P.19-20的抽象数据类型定义转换为实际的C++语言 */
	LinkList();	//构造函数，替代InitList
	~LinkList();	//析构函数，替代DestroyList
	Status	ClearList();
	Status	ListEmpty();
	int	ListLength();
	Status	GetElem(int i, ElemType &e);
	int	LocateElem(ElemType e, Status (*compare)(ElemType e1, ElemType e2));
	Status	PriorElem(ElemType cur_e, ElemType &pre_e);
	Status	NextElem(ElemType cur_e, ElemType &next_e);
	Status	ListInsert(int i, ElemType e);
	Status	ListDelete(int i, ElemType &e);
	Status	ListTraverse(Status (*visit)(ElemType e));
};
