#ifndef MYBTREE_H
#define MYBTREE_H
#include<iostream>
#include"myQueue.h"
using namespace std;
//typedef struct BiTNode{
//	char data;
//	struct BiTNode *lchild, *rchild;
//}BiTNode, *BiTree;

// ������ 
void CreatBiTree(BiTree &T)
{
	char a;
	cin >> a;
	if(a == '*') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = a;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}

// ������� 
void PreOrder(BiTree T)
{
	if(T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// ������� 
void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}

// ������� 
void PostOrder(BiTree T)
{
	if(T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data;
	}
}

// ���������Ҷ�ӽ���� 
// ��ȫ�ֱ����ķ��� 
int cnt = 0;
int LeefCount1(BiTree T)
{
	if(T)
	{
		if(T->lchild == NULL && T->rchild == NULL)
		{
			cnt++;
		}
		LeefCount1(T->lchild);
		LeefCount1(T->rchild);
	}
	return cnt;
}

// ���������Ҷ�ӽ���� 
// ����ȫ�ֱ��� 
int LeefCount2(BiTree T)
{
	if(T == NULL) return 0;
	if(T->rchild == NULL && T->lchild == NULL) return 1;
	return LeefCount2(T->lchild) + LeefCount2(T->rchild);	
}

// ��������� 
int dcount = 0;
int dL = 0, dR = 0;
int DeepCount(BiTree T)
{
	if(T == NULL) dcount = 0;
	else
	{
		dL = DeepCount(T->lchild);	//��������������� 
		dR = DeepCount(T->rchild);	//��������������� 
		dcount = 1 + (dL > dR ? dL : dR);	//�����������Ϊ�ϴ��߼�1(���ϸտ�ʼ�ĸ����)
	}
	return dcount;	
}

// ���������������������� 
void InverseTree(BiTree &T)
{
	BiTree temp;
	if(T == NULL) return;
	else
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		InverseTree(T->lchild);
		InverseTree(T->rchild);		
	}
}

// ��α��� 
void LayerOrder(BiTree T)
{
	LinkQueue Q;	// �������� 
	BiTree a;		// ����һ�����ڵ�a 
	InitQueue(Q);	// ��ʼ������ 
	EnQueue(Q, T);	// �����ڵ���� 
	while(!isEmptyQueue(Q))	// ѭ��ֱ���ӿ� 
	{
		DeQueue(Q, a);		// ����Ԫ��(ָ��)������a 
		cout << a->data;	// ����a��ָ���
		if(a->lchild != NULL) EnQueue(Q, a->lchild);	// ���a������ 
		if(a->rchild != NULL) EnQueue(Q, a->rchild);	// ���a���Һ��� 
	}
}
#endif 


