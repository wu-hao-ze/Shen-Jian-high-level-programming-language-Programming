//#define ELEMTYPE_IS_INT		//不定义也行
//#define ELEMTYPE_IS_DOUBLE
//#define ELEMTYPE_IS_CHAR_ARRAY
//#define ELEMTYPE_IS_CHAR_P
//#define ELEMTYPE_IS_STRUCT_STUDENT
//#define ELEMTYPE_IS_STRUCT_STUDENT_P

/* P.10 的预定义常量和类型 */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2		//因为<math.h>中已有 OVERFLOW 的定义，因此换一下

typedef int Status;

#define LIST_INIT_SIZE	100	//初始大小定义为100（可按需修改）
#define LISTINCREMENT	10	//若空间不够，每次增长10（可按需修改）

#ifdef ELEMTYPE_IS_DOUBLE
    typedef double ElemType;
#elif defined (ELEMTYPE_IS_CHAR_ARRAY)
    typedef char ElemType[10];
#elif defined (ELEMTYPE_IS_CHAR_P)
    typedef char* ElemType;
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
    typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
    } ElemType;
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
    typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
    } ET, *ElemType;
#else	//缺省当做int处理
    typedef int ElemType;
#endif

typedef struct {
    ElemType *elem;	//存放动态申请空间的首地址（可以理解为表头元素a1的地址）
    int length;		//记录当前长度
    int listsize;	//当前分配的元素的个数
} sqlist;

/* P.19-20的抽象数据类型定义转换为实际的C语言 */
Status	InitList(sqlist *L);
Status  DestroyList(sqlist *L, Status (*sub_free)(sqlist *L));
Status	ClearList(sqlist *L, Status (*sub_free)(sqlist *L));
Status	ListEmpty(sqlist L);
int	ListLength(sqlist L);
Status	GetElem(sqlist L, int i, ElemType *e, Status (*assign)(ElemType *dst, ElemType src));
int	LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2));
Status  PriorElem(sqlist L, ElemType cur_e, ElemType *pre_e, Status (*compare)(ElemType e1, ElemType e2), Status (*assign)(ElemType *dst, ElemType src));
Status	NextElem(sqlist L, ElemType cur_e, ElemType *next_e, Status (*compare)(ElemType e1, ElemType e2), Status (*assign)(ElemType *dst, ElemType src));
Status  ListInsert(sqlist *L, int i, ElemType e, Status (*move)(ElemType *dst, ElemType *src), Status (*assign)(ElemType *dst, ElemType src), Status (*allocnode)(ElemType *p, ElemType e));
Status  ListDelete(sqlist *L, int i, ElemType *e, Status (*move)(ElemType *dst, ElemType *src), Status (*assign)(ElemType *dst, ElemType src), Status (*freenode)(ElemType p));
Status	ListTraverse(sqlist L, Status (*visit)(ElemType e));
