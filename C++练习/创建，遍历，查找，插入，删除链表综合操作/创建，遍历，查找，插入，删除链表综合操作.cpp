#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;


const int maxSize = 100;
template<class T>
struct SLinkNode
{
	T data;
	int link;
};

template<typename T>
class StaticList
{
private:
	SLinkNode<T>elem[maxSize];
	int avil;
public:
	void InitList();
};

template<class T>
void StaticList<T>::InitList()
{
	elem[0].link = -1;
	avil = -1;
	for (int i = 1; i < maxSize - 1; i++ )
		elem[i].link = i + 1;
	elem[maxSize - 1].link = -1;
}

struct node
{
	int n;
	struct node* next;
};
struct node* create(int m)
{
	struct node* head = NULL;
	struct node* tail, * newnode;
	tail = new node;
	for (int i = 0; i < m; i++)
	{
		newnode = new node;
		cin >> newnode->n;
		newnode->next = NULL;
		if (head == NULL)head = newnode;
		else tail->next = newnode;
		tail = newnode;
	}return head;
}
void print(struct node* head)
{
	struct node* p = head;
	while (p != NULL)
	{
		cout << p->n << " ";
		p = p->next;
	}cout << endl;
}
void search(struct node* head, int j)
{
	int i = 1;
	struct node* p = head;
	if (i < 1)cout << "faulse";
	else {
		while (i != j && p != NULL)
		{
			i++;
			p = p->next;
		}if (i == j && p != NULL)cout << p->n;
		else cout << "faulse";
	}
}
struct node* insert(struct node* head, int x)
{
	struct node* behind, * front, * newnode;
	newnode = new node;
	newnode->n = x;
	behind = head;
	front = new node;
	if (head = NULL) { head = newnode; newnode->next = NULL; }
	else {
		while (behind != NULL && x > behind->n)
		{
			front = behind; behind = behind->next;
		}if (behind == head) { newnode->next = head; head = newnode; }
		else if (behind == NULL) {
			front->next = newnode; newnode->next = NULL;
		}
		else { front->next = newnode; newnode->next = behind; }
	}return head;
}
struct node* delnode(struct node* head, int x)
{
	struct node* p, * q;
	p = head;
	q = new node;
	if (head == NULL)cout << "faulse";
	else {
		while (p != NULL && p->n != x) { q = p; p = p->next; }
		if (p == head) { head = p->next; delete p; }
		else if (p == NULL) { cout << "faulse"; }
		else { q->next = p->next; delete p; }

	}return head;
}
int main()
{
	struct node* head = create(5);
	print(head);

	search(head, 2); cout << endl;
	insert(head, 3); print(head);
	delnode(head, 2); print(head);
	system("pause");
	return 0;
}








