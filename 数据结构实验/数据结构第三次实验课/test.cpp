#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LNode_{
	int code;
	int key;
	struct LNode_ *next;
}LNode,*LinkList;

int n,m;

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;	// ͷβ���� 
}

void CreatList(LinkList &L)	// β�巨������ֵ 
{
	L->code = 1;
	int key;
	cin >> key;
	L->key = key;
	LinkList p = L;
	for(int i = 2;i <= n;i++)
	{
		LinkList q;
		q = (LinkList)malloc(sizeof(LNode));
		q->code = i;
		cin >> key;
		q->key = key;
		p->next = q;
		p = q;
	}
	p->next = L;	// ���β����nextָ��ͷ�ڵ㣬��ʵ��ͷβ�������γ�ѭ������ 
}

void Joseph(LinkList &L,int m)
{
	LinkList p = L;
	int x = 1;
	while(p->next != p)	// p->next == p��ʾ��ʣһ����� 
	{
		 
	}
	cout << p->code;
}
int main()
{
	LinkList L;
	cin >> m >> n;
	InitList(L);
	CreatList(L);
	Joseph(L,m);
	return 0;
}
