#include<iostream>
#include<cstdlib>

using namespace std;

typedef char ElemType;
typedef struct bitnode					//����������ڵ�ṹ
{     
	ElemType data;                 		//������
	struct bitnode *lchild,*rchild;  	//���Һ���ָ���� 
}BiTNode,*BiTree;


void CreatBitree(BiTree &T) // ������
{
	char a;
	cin >> a;
	if(a == '*') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = a;
		CreatBitree(T->lchild);
		CreatBitree(T->rchild);
	}
}

bool isSameStructure(BiTree A, BiTree B)
{
	if(A == NULL && B == NULL) return true;
	if(A == NULL || B == NULL) return false;
	return isSameStructure(A->lchild, B->lchild) && isSameStructure(A->rchild, B->rchild);
}

int main()
{
	BiTree A, B;
	cout << "�����루�ڿ����������*��������  A ���������У�" << endl;
	CreatBitree(A);
	cout << "�����루�ڿ����������*��������  B ���������У�" << endl;
	CreatBitree(B);
	
	if(isSameStructure(A, B)) cout << "�ṹ��ͬ";
	else cout << "�ṹ��ͬ";
	
	return 0;
}
