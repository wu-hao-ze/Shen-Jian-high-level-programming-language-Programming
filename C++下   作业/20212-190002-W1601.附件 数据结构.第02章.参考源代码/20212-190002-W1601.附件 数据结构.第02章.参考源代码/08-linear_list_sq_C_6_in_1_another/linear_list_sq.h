//#define ELEMTYPE_IS_INT		//������Ҳ��
//#define ELEMTYPE_IS_DOUBLE
//#define ELEMTYPE_IS_CHAR_ARRAY
//#define ELEMTYPE_IS_CHAR_P
//#define ELEMTYPE_IS_STRUCT_STUDENT
//#define ELEMTYPE_IS_STRUCT_STUDENT_P

/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2		//��Ϊ<math.h>������ OVERFLOW �Ķ��壬��˻�һ��

typedef int Status;

#define LIST_INIT_SIZE	100	//��ʼ��С����Ϊ100���ɰ����޸ģ�
#define LISTINCREMENT	10	//���ռ䲻����ÿ������10���ɰ����޸ģ�

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
#else	//ȱʡ����int����
    typedef int ElemType;
#endif

typedef struct {
    ElemType *elem;	//��Ŷ�̬����ռ���׵�ַ���������Ϊ��ͷԪ��a1�ĵ�ַ��
    int length;		//��¼��ǰ����
    int listsize;	//��ǰ�����Ԫ�صĸ���
} sqlist;

/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C���� */
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
