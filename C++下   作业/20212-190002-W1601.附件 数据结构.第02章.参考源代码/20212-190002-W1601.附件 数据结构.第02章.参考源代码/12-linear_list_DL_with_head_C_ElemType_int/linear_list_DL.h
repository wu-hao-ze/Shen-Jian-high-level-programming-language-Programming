/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

/* P.28 ��ʽ���� */
typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

typedef struct DuLNode {
    ElemType        data;	//�������
    struct DuLNode *prior;	//���ֱ��ǰ����ָ��
    struct DuLNode *next;	//���ֱ�Ӻ�̵�ָ��
} DuLNode, *DuLinkList;

/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C���� */
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
