#define LIST_INIT_SIZE	100	//��ʼ��С����Ϊ100���ɰ����޸ģ�
#define LISTINCREMENT	10	//���ռ䲻����ÿ������10���ɰ����޸ģ�

typedef struct student {
    int   num;
    char  name[10];
    char  sex;
    float score;
    char  addr[30];
} ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

typedef struct {
    ElemType *elem;	//��Ŷ�̬����ռ���׵�ַ���������Ϊ��ͷԪ��a1�ĵ�ַ��
    int length;		//��¼��ǰ����
    int listsize;	//��ǰ�����Ԫ�صĸ���
} sqlist;

/* �൱������ 1���ȶ���ṹ����   2���ٰѽṹ������typedef����Ϊ������
struct _sqlist_ {
    ElemType *elem;	//��Ŷ�̬����ռ���׵�ַ���������Ϊ��ͷԪ��a1�ĵ�ַ��
    int length;		//��¼��ǰ����
    int listsize;	//��ǰ�����Ԫ�صĸ���
};

typedef struct _sqlist_ sqlist
*/

/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C���� */
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
