/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

/* P.28 形式定义 */
typedef int ElemType;	//可根据需要修改元素的类型

typedef struct DuLNode {
    ElemType        data;	//存放数据
    struct DuLNode *prior;	//存放直接前驱的指针
    struct DuLNode *next;	//存放直接后继的指针
} DuLNode, *DuLinkList;

/* P.19-20的抽象数据类型定义转换为实际的C语言 */
Status	InitList(DuLinkList *L);
Status	DestroyList(DuLinkList *L);
Status	ClearList(DuLinkList *L);
Status	ListEmpty(DuLinkList L);
int	ListLength(DuLinkList L);
Status	GetElem(DuLinkList L, int i, ElemType *e);
int	LocateElem(DuLinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2));
Status	PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e);
Status	NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e);
Status	ListInsert(DuLinkList *L, int i, ElemType e);
Status	ListDelete(DuLinkList *L, int i, ElemType *e);
Status	ListTraverse(DuLinkList L, Status (*visit)(ElemType e));
