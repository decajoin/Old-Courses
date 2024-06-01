#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct 
{
	bool  *elem;        	//�洢�ռ��ַ
	int length;             //��ǰ����
	int listsize;           //��ǰ����Ĵ洢���� 
}SqList;

void InitSqList(SqList &L, int n)
{
	L.elem = (bool*)malloc(n * sizeof(bool));
	memset(L.elem, 0, n * sizeof(bool));
	L.length = 0;
	L.listsize = n;
}



int main()
{
	SqList L;
	int n, k;
	
	cout << "������ɽ���ĸ�����" << endl;
	cin >> n;
	cout << "���������������Ĵ�����" << endl;
	cin >> k;
	
	InitSqList(L, n + 1);
	
	long long x = 1;
	L.elem[1] = true;	// ��һ�����ؽ���
	for(int i = 2; i <= k; i++)
	{
		x = x + i;
		int cnt = x % n;
		if(cnt != 0) L.elem[x % n] = true;
		else L.elem[n] = true;
		
	}
	
	cout << "���ӿ��ܲ������ж��У�" << endl;
	for(int i = 1; i <= n; i++)
	{
		if(L.elem[i] == false) cout << i << " ";
	}
	
	return 0;
}
