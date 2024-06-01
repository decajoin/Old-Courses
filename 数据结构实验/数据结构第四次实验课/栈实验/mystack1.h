#ifndef MYSTACK1_H
#define MYSTACK1_H
#include<iostream>
#include<stdlib.h>
using namespace std;

#define INIT_SIZE 100	// �洢�ռ��ʼ������
#define INCREMENT 10	//�洢�ռ��������

typedef struct{
	int *base;
	int *top;
	int StackSize;
}SqStack;
 
void InitStack(SqStack &S)
{
	S.base = (int*)malloc(INIT_SIZE*sizeof(int));
	if(!S.base) exit(-1);
	S.top = S.base;
	S.StackSize = INIT_SIZE;
	return;
}

bool StackEmpty(SqStack S)
{
	if(!S.base) exit(-1);
	if(S.top == S.base) return true;
	else return false;
}

void push(SqStack &S,int x)
{
	if(S.top - S.base == S.StackSize)	//ջ�� 
	{	
		int *newbase;	//׼���»�ַ 
		newbase = (int*)realloc(S.base,(S.StackSize + INCREMENT)*sizeof(int));
		if(!newbase) exit(-1);
		S.base = newbase;
		S.top = S.StackSize + S.base;	// �ҵ�����topָ���λ��  
		S.StackSize += INCREMENT;
	}
	*S.top++ = x;	// ���ڸ�ֵ��top++��topʼ���ǿյ� 
	return;
}

void pop(SqStack &S,int &e)
{
	if(S.top == S.base) exit(-1);
	e = *--S.top;
}

void top(SqStack S,int &e)
{
	if(S.top == S.base) return;
	e = *(S.top - 1);
}

void travel(SqStack S)	// ��ջ������Ԫ�ش�ջ�׵�ջ��������ʾ
{
	while(S.top != S.base)
	{
		cout << *S.base++ << " ";
	}
	cout << endl;
}

#endif
