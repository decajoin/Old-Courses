/*
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node {
	int num;
	struct node* next;
} Lnode, * pNode;

pNode CreatLinkList(pNode L, int m)
{
	if(m < 1)	// ����С��1�ǲ���������
	{
		L = NULL;
		return L;
	}

	L = (pNode)malloc(sizeof(Lnode));
	L->num = 1;
	pNode p = L;
	for(int i = 2; i <= m; i++)
	{
		pNode q = (pNode)malloc(sizeof(Lnode));
		q->num = i;
		p->next = q;
		p = q;
	}
	p->next = L;	// ��βָ����ͷָ�������γ�ѭ������

	return p;	// ����βָ�루�������ɾ���ڵ㣩
}

int MonkeyKing(pNode &rear, int n)
{
	if(rear == NULL) return 0;

	pNode p = rear;
	while(p->next != p)
	{
		for(int i = 1; i < n; i++)
		{
			p = p->next;
		}
		pNode q	= p->next;
		p->next = q->next;
		free(q);
	}
	int kingnum = p->num;
	return kingnum;
}


int main()
{
	int m, n;
	pNode L;
	cout << "�����������M����������N��" << endl;
	cin >> m >> n;
	pNode rear = CreatLinkList(L, m);
	cout << "������" << MonkeyKing(rear, n) << "�ź���";
	return 0;
}
*/