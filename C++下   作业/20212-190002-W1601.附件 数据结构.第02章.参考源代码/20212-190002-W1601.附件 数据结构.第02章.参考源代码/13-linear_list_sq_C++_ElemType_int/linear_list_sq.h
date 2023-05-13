/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

#define LIST_INIT_SIZE	100	//��ʼ��С����Ϊ100���ɰ����޸ģ�
#define LISTINCREMENT	10	//���ռ䲻����ÿ������10���ɰ����޸ģ�

typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

class sqlist {
    protected:
	ElemType *elem;	//��Ŷ�̬����ռ���׵�ַ���������Ϊ��ͷԪ��a1�ĵ�ַ��
	int length;	//��¼��ǰ����
	int listsize;	//��ǰ�����Ԫ�صĸ���
    public:
	/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C++���� */
	sqlist();	//���캯�������InitList
	~sqlist();	//�������������DestroyList
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
