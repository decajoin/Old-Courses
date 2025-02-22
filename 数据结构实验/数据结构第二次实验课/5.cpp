#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define INT_LIST_SIZE 6
#define LISTINCREMENT 3

typedef struct{
    int* elem;
    int length;
    int listsize;
}SqList;

void InitList(SqList &L)
{
    L.elem = (int*)malloc(sizeof(int)*INT_LIST_SIZE);
    memset(L.elem,0,sizeof(int)*INT_LIST_SIZE);
    if(!L.elem) exit(0);
    L.length = 0;
    L.listsize = INT_LIST_SIZE;
}

void PrintList(SqList L)
{
    for(int i = 0;i < L.length;i++) cout<<L.elem[i]<<" ";
    cout<<endl;
}

void ListInsert_sort(SqList &L,int e)
{
	if(L.length >= L.listsize)
	{
	   	int *newbase;
	    newbase = (int*)realloc(L.elem,sizeof(int)*(L.listsize + LISTINCREMENT));
	    if(!newbase) exit(0);
	    L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	
	int* p;
	int i = 0;
	p = &(L.elem[0]);
	while(*(p + i) <= e && i < L.length) i++;
	i++; // 上面循环得到的i是数组的下标，而之前我们后移操作的i是位置故加一 
	
	int* q;
	q = &(L.elem[i - 1]);
	    
	for(p = &(L.elem[L.length - 1]);p >= q;p--)
	{
	    *(p + 1) = *p ;// 插入的元素向后移 
	}
	*q = e;
	L.length++;
}

void ListCompare(SqList L1,SqList L2)
{
	int i = 0,j = 0;
	while(i < L1.length && i < L2.length)
	{
		if(L1.elem[i] < L2.elem[i])
		{
			cout<<"A<B"<<endl;
			exit(0);
		}
		else if(L1.elem[i] > L2.elem[i])
		{
			cout<<"A>B"<<endl;
			exit(0);
		}
		i++;
	}
	if(L1.length == L2.length) cout<<"A=B"<<endl;
	else
	{
		if(i < L1.length) cout<<"A>B"<<endl;
		else cout<<"A<B"<<endl;
	}	
}

int main()
{
	int n,x;
    SqList L1,L2;
	InitList(L1);
	InitList(L2);

	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert_sort(L1,x);
	}

	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		ListInsert_sort(L2,x);
	}	
	
	ListCompare(L1,L2);
	return 0;
}
