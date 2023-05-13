#define LIST_INIT_SIZE	100	//初始大小定义为100（可按需修改）
#define LISTINCREMENT	10	//若空间不够，每次增长10（可按需修改）

typedef char ElemType[10];	//可根据需要修改元素的类型(ElemType s <=> char s[10])

typedef struct {
    ElemType *elem;	//存放动态申请空间的首地址（可以理解为表头元素a1的地址）
    int length;		//记录当前长度
    int listsize;	//当前分配的元素的个数
} sqlist;

/* 相当于两步 1、先定义结构体名   2、再把结构体名用typedef声明为新类型
struct _sqlist_ {
    ElemType *elem;	//存放动态申请空间的首地址（可以理解为表头元素a1的地址）
    int length;		//记录当前长度
    int listsize;	//当前分配的元素的个数
};

typedef struct _sqlist_ sqlist
*/

/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

/* P.19-20的抽象数据类型定义转换为实际的C语言 */
Status	InitList(sqlist *L);
Status	DestroyList(sqlist *L);
Status	ClearList(sqlist *L);
Status	ListEmpty(sqlist L);
int	ListLength(sqlist L);
Status	GetElem(sqlist L, int i, ElemType *e);
int	LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2));
Status	PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e);
Status	NextElem(sqlist L, ElemType cur_e, ElemType *next_e);
Status	ListInsert(sqlist *L, int i, ElemType e);
Status	ListDelete(sqlist *L, int i, ElemType *e);
Status	ListTraverse(sqlist L, Status (*visit)(ElemType e));
