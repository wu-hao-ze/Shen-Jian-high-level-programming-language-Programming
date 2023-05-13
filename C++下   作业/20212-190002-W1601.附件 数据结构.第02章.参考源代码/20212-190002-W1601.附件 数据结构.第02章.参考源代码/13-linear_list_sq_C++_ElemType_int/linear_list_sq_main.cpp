#include <iostream>
#include <iomanip>
#include "linear_list_sq.h"

using namespace std;

#define INSERT_NUM		115		//��ʼ������е�Ԫ������
#define MAX_NUM_PER_LINE 	10		//ÿ����������Ԫ�ظ���

int line_count = 0;   //��ӡ����ʱ�ļ�����

/* ���ڱȽ�����ֵ�Ƿ���ȵľ��庯������LocateElem�еĺ���ָ�붨����ͬ������ʱ����
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
    if (e1==e2)
    	return TRUE;
    else
    	return FALSE;
}

/* ���ڷ���ĳ��Ԫ�ص�ֵ�ľ��庯������ListTraverse�еĺ���ָ�붨����ͬ������ʱ����
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
    cout << setw(3) << e << "->";

    /* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
    if ((++line_count)%MAX_NUM_PER_LINE == 0)
    	cout << endl;

    return OK;
}

int main()
{
    sqlist   L;
    ElemType e1, e2;
    int      i, pos;

    cout << "�ձ�=" << ((L.ListEmpty()==TRUE)?"TRUE":"FALSE") << endl;
    cout << "��=" << L.ListLength() << endl;

    cout << "����" << INSERT_NUM << "��Ԫ�أ�" << endl;
    for (i=INSERT_NUM*2; i>0; i-=2)
	L.ListInsert(1, i);
    L.ListTraverse(MyVisit);//�˴�����MyVisit������

    cout << "�ձ�=" << ((L.ListEmpty()==TRUE)?"TRUE":"FALSE") << endl;
    cout << "��=" << L.ListLength() << endl;

    /* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
       ����ټ�һ����������ֵ */
    for (i=0; i<5; i++) {
    	int pos;
	switch(i) {
	    case 0:
	    	pos = 1;
	    	break;
	    case 1:
	    	pos = L.ListLength();
	    	break;
	    case 2:
	    	pos = -1;
	    	break;
	    case 3:
	    	pos = L.ListLength()+1;
	    	break;
	    case 4:
		cout << "������ҪȡԪ�ص�λ��[1.." << L.ListLength() << "]��" << endl;
		cin >> pos;
		break;
	    }

	if (L.GetElem(pos, e1)==OK) {
    	    cout << "��" << pos << "��Ԫ��=" << e1 << endl;
    
	    /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
	    if (L.PriorElem(e1, e2)==OK)
    		cout << "��" << pos << "��Ԫ��(" << e1 << ")��ǰ��=" << e2 << endl;
	    else
    		cout << "�޷�ȡ�õ�" << pos << "��Ԫ��(" << e1 << ")��ǰ��" << endl;

	    if (L.NextElem(e1, e2)==OK)
    		cout << "��" << pos << "��Ԫ��(" << e1 << ")�ĺ��=" << e2 << endl << endl;
	    else
    		cout << "�޷�ȡ�õ�" << pos << "��Ԫ��(" << e1 << ")�ĺ��" << endl << endl;
	    }
	else
	    cout << "�޷�ȡ�õ�" << pos << "��Ԫ��" << endl << endl;
        } // end of for

    cout << "������Ҫ���ҵ�Ԫ�أ�" << endl;
    cin >> e1;
    if ((pos=L.LocateElem(e1, MyCompare))>0)
    	cout << "Ԫ��" << e1 << "��λ��=" << pos << endl;
    else
    	cout << "�Ҳ���Ԫ��" << e1 << endl;

    cout << endl << "������Ҫ����Ԫ�ص�ֵ��" << endl;
    cin >> e1;
    cout << "������Ҫ����Ԫ�ص�λ��" << endl;
    cin >> pos;
    if (L.ListInsert(pos, e1)==OK) {
    	cout << "��" << pos << "ǰ����Ԫ��" << e1 << "�ɹ�" << endl;
    	cout << "�±�Ϊ��" << endl;
	L.ListTraverse(MyVisit);
    	}
    else
    	cout << "��" << pos << "ǰ����Ԫ��" << e1 << "ʧ��" << endl;

    cout << endl << "������Ҫɾ��Ԫ�ص�λ��" << endl;
    cin >> pos;
    if (L.ListDelete(pos, e1)==OK) {
    	cout << "ɾ����" << pos << "Ԫ��=" << e1 << "�ɹ�" << endl;
    	cout << "�±�Ϊ��" << endl;
	L.ListTraverse(MyVisit);
    	}
    else
    	cout << "ɾ����" << pos << "Ԫ��=" << e1 << "ʧ��" << endl;

    cout << endl << "��ձ�" << endl;
    L.ClearList();
    cout << "�ձ�=" << ((L.ListEmpty()==TRUE)?"TRUE":"FALSE") << endl;
    cout << "��=" << L.ListLength() << endl;

    return 0;
}
