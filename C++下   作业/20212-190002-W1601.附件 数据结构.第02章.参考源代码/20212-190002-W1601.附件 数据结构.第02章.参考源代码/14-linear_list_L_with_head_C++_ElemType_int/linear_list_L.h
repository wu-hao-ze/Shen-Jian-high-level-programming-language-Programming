/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

class LinkList;	//��ǰ��������Ϊ������ԪҪ�õ�

class LNode {
    protected:
	ElemType data;	//������
	LNode   *next;	//ָ����
    public:
    	friend class LinkList;
        //�������κκ������൱��struct LNode
};

class LinkList {
    protected:
	LNode *head;	//ͷָ��
    public:
	/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C++���� */
	LinkList();	//���캯�������InitList
	~LinkList();	//�������������DestroyList
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
