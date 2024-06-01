#include<iostream>
#include<cstdlib>
#include<cstring>
#define INF 0x3fffffff
using namespace std;
const int MAXN = 1000;
int w[MAXN];

typedef struct{
	//����Ȩֵ 
	int weight;
	//����˫�ס����ӡ��Һ��ӵ��±� 
	int parent, lchild, rchild;
	//�������
	int num;
}HTNode, *HuffmanTree;
typedef char* *HuffmanCode;

int min(HuffmanTree HT,int n)
{
	int m;
	int k = INF;
	for(int i = 1;i <= n;i++)
	{
		if(HT[i].weight < k &&HT[i].parent == 0)
		{
			k = HT[i].weight;
			m = i;
		}
	}
	// m����Ȩֵ��С�Ľ������ 
	HT[m].parent = 1;	// ��Ǹý�������β��� 
	return m;
}

//��HT[1��i-1]ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2 
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	s1 = min(HT, n);
	s2 = min(HT, n);
}


// *w��Ȩֵ�����ͷָ�� 
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	if(n <= 1) return;
	int m = 2 * n - 1;	//n ��Ҷ�ӵ�Huffman������2n-1����� 
	HT=(HuffmanTree)malloc((m + 1)*sizeof(HTNode));   //0��Ԫδ�ã������еĽ�����ռ� 
	int i;
	HuffmanTree p;
	
	// ��ʼ����������  
	w++;	// w�±��1��ʼ 
	for(p = HT + 1,i = 1; i<=n; ++i,++p,++w)	//��ʼ��ǰn����Ԫ 
	{
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
		p->weight = *w;
		p->num = i;
	}
	for(;i <= m;++i, ++p)	//��Ҷ��֮��Ĵ洢��Ԫ���� 
	{
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
		p->weight = 0;
		p->num = i;
	}
	
	//��Huffman��  
	for(i=n+1;i<=m; ++i)	  
	{
	    //��HT[1��i-1]ѡ��parentΪ0��weight��С���������,����ŷֱ�Ϊs1��s2 
		int s1, s2;
		Select(HT, i-1, s1, s2);
		HT[s1].parent=i;	HT[s2].parent=i; 
 		HT[i].lchild=s1; 	HT[i].rchild=s2;  //s1��s2�ֱ���Ϊi�����Һ��� 
		HT[i].weight=HT[s1].weight+ HT[s2].weight;
	}	
	
	//��Ҷ�ӵ���������ÿ���ַ��ĺշ������� 
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));	//  ����n���ַ������ͷָ�� 
	char* cd;
	cd = (char*)malloc(n * sizeof(char));	// ���������Ĺ����ռ� 
	cd[n - 1] = '\0';	//�������������cd[0]~cd[n-1]Ϊ�Ϸ��ռ䣩
	//����ַ���Huffman���� 
	for(i=1;i<=n;++i)
	{
		int start = n-1;  //���������λ�� 
		int c, f;
		for(c = i,f = HT[i].parent;f != 0;   c = f, f = HT[f].parent)
		{
			//��Ҷ�ӵ������������ 
			if(HT[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
			
		}
		//Ϊ��i���ַ��������ռ� 
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);	//��cd���Ʊ��봮��HC		
	}
	free(cd);	//�ͷŹ����ռ� 
	
}

int main()
{
	int n, x;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		w[i] = x;
	}
	
	HuffmanTree HT;
	HuffmanCode HC;
	HuffmanCoding(HT, HC, w, n);
	for(int i = 1;i <= n;i++) cout << HC[i] <<endl;
	
	return 0;
}
