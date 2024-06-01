#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct BiTreeNode{	// �������Ľ��
	char data;
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild;
}BiTreeNode, *BiTree;

typedef struct QNode {	// �������н��
	BiTree data;
	struct QNode* next;
}QNode, *QueuePtr;

typedef struct {	// Ϊ���н�㴴��ͷβָ��(��������)
	QueuePtr front;
	QueuePtr rear;
}Queue;

typedef struct SNode{
	BiTree data;
	struct SNode* next;
}SNode, *Stack;


// ������
void CreateBiTree(BiTree& T)
{
	char a;
	cin >> a;
	if (a == '*') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = a;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

// �������
void PreOrder(BiTree T)
{
	if (T)
	{
		cout << T->data ;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

// �������
void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	}
}

// �������
void PostOrder(BiTree T)
{
	if (T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data;
	}
}

// ���������
int DeepthBiTree(BiTree T)
{
	if (T == NULL) return 0;
	else
	{
		int dr = DeepthBiTree(T->rchild);
		int dl = DeepthBiTree(T->lchild);
		return 1 + (dr > dl ? dr : dl);
	}
}

// ��Ҷ�ӽڵ����
int LeefBiTree(BiTree T)
{
	if (T == NULL) return 0;
	if (T->lchild == NULL && T->rchild == NULL) return 1;
	return LeefBiTree(T->lchild) + LeefBiTree(T->rchild);
}


// ������������
void InverseTree(BiTree& T)
{
	BiTree temp;
	if (T == NULL) return;
	else
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		InverseTree(T->lchild);
		InverseTree(T->rchild);
	}
}

// ��ʼ������
void InitQueue(Queue& Q)
{
	Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

// ���
void EnQueue(Queue& Q, BiTree T)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = T;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	// ����rearָ��
	Q.rear->next = NULL;
}

// �п�
bool isEmptyQueue(Queue Q)
{
	if (Q.rear == Q.front) return true;
	else return false;
}

// ����
void DeQueue(Queue& Q, BiTree& e)
{
	QueuePtr p;
	if (Q.front == Q.rear || Q.front == NULL) return;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
}

// ��α���
void LayerOrder(BiTree T)
{
	Queue Q;
	BiTree a;
	InitQueue(Q);
	EnQueue(Q, T);
	while (!isEmptyQueue(Q))
	{
		DeQueue(Q, a);
		cout << a->data;
		if (a->lchild != NULL) EnQueue(Q, a->lchild);
		if (a->rchild != NULL) EnQueue(Q, a->rchild);
	}
}


void InitStack(Stack& S)
{
	S = NULL;
}

void PushStack(Stack& S, BiTree T)
{
	Stack p;
	p = (Stack)malloc(sizeof(SNode));
	p->data = T;
	p->next = S;
	S = p;
}

void PopStack(Stack& S, BiTree& e)
{
	if (S == NULL) return;
	Stack p;
	p = S;
	e = p->data;
	S = S->next;
	free(p);
}

BiTree TopStack(Stack S)
{
	if (S == NULL) return NULL;
	else return S->data;
}

bool isEmptyStack(Stack S)
{
	if (S == NULL) return true;
	else return false;
}


// �ǵݹ��������
void PreOrderTraversal(BiTree T)
{
	Stack S;
	InitStack(S);
	if (T == NULL) return;

	PushStack(S, T);
	while (!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		if (a != NULL)
		{
			PopStack(S, a);
			if (a->rchild) PushStack(S, a->rchild);
			if (a->lchild) PushStack(S, a->lchild);
			PushStack(S, a);
			PushStack(S, NULL);
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}



// �ǵݹ��������
void InOrderTraversal(BiTree T)
{
	Stack S;
	InitStack(S);
	if (T == NULL) return;

	PushStack(S, T);
	while (!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		if (a != NULL)
		{
			PopStack(S, a);
			if (a->rchild) PushStack(S, a->rchild);
			PushStack(S, a);
			PushStack(S, NULL);
			if (a->lchild) PushStack(S, a->lchild);
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}

// �ǵݹ�������
void PostOrderTraversal(BiTree T)
{
	Stack S;
	InitStack(S);
	if (T == NULL) return;

	PushStack(S, T);
	while (!isEmptyStack(S))
	{
		BiTree a = TopStack(S);
		BiTree e;
		if (a != NULL)
		{
			PopStack(S, a);
			PushStack(S, a);
			PushStack(S, NULL);
			if (a->rchild) PushStack(S, a->rchild);
			if (a->lchild) PushStack(S, a->lchild);
		}
		else
		{
			PopStack(S, e);
			PopStack(S, a);
			cout << a->data;
		}
	}
}


int main()
{
	BiTree T;
	CreateBiTree(T);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PostOrder(T);
	cout << endl;
	cout << DeepthBiTree(T);
	cout << endl;
	cout << LeefBiTree(T);
	cout << endl;
	LayerOrder(T);
	cout << endl;
	InverseTree(T);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PostOrder(T);
	cout << endl;
	cout << DeepthBiTree(T);
	cout << endl;
	cout << LeefBiTree(T);
	cout << endl;
	LayerOrder(T);
	cout << endl;
	PreOrderTraversal(T);
	cout << endl;
	InOrderTraversal(T);
	cout << endl;
	PostOrderTraversal(T);
	cout << endl;
	return 0;
}