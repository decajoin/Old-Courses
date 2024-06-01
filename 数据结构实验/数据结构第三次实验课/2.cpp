#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}LNode,*LinkList;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;	
}

void ListInsert(LinkList &L)
{
	int x = 0;
	LinkList p,r;
	p = L; // β�巨 
	while(cin >> x && x != -1)
	{
		r = (LinkList)malloc(sizeof(Node));
		r->data = x;
		r->next = NULL;
		p->next = r;
		p = r; // pʼ���������β 
	}
	return;
}

void PrintList(LinkList &L)
{
	LinkList r = L->next;
	
	while(r != NULL)
	{
		cout << r->data << " ";
		r = r->next;
	}
	cout << endl;
}

void ListSort(LinkList &L1,LinkList &L2,LinkList &L3)
{
	LinkList p1 = L1->next,p2 = L2->next;
	LinkList p3;
	L3 = p3 = L1;
	while(p1 && p2)
	{
		if(p2->data > p1->data)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
			p3->next = NULL;
		}
		else if(p2->data < p1->data)
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
			p3->next = NULL;
		}
		else
		{
			p3->next = p1;
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
			p3->next = NULL;
		}
	}
	p3->next = p1 ? p1 : p2;
}

int main()
{
	LinkList L1;
	LinkList L2;
	LinkList L3;
	
	InitList(L1);
	ListInsert(L1);
	
	InitList(L2);
	ListInsert(L2);
	
	
	ListSort(L1,L2,L3);
	
	
	PrintList(L3);
	return 0;
}
