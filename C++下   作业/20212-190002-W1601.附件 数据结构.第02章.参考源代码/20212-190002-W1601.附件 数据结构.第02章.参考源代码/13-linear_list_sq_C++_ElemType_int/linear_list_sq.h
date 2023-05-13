/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

#define LIST_INIT_SIZE	100	//初始大小定义为100（可按需修改）
#define LISTINCREMENT	10	//若空间不够，每次增长10（可按需修改）

typedef int ElemType;	//可根据需要修改元素的类型

class sqlist {
    protected:
	ElemType *elem;	//存放动态申请空间的首地址（可以理解为表头元素a1的地址）
	int length;	//记录当前长度
	int listsize;	//当前分配的元素的个数
    public:
	/* P.19-20的抽象数据类型定义转换为实际的C++语言 */
	sqlist();	//构造函数，替代InitList
	~sqlist();	//析构函数，替代DestroyList
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
