#ifndef MYGRAPH_H
#define MYGRAPH_H
#include<iostream>
#include<climits>
#define MAXN 20
#define MaxInt INT_MAX
using namespace std;

typedef char VertexType;
typedef int ArcType;

typedef struct{
	VertexType vexs[MAXN];
	ArcType arcs[MAXN][MAXN];
	int vexnum, arcnum;
}MGraph;

// �ҵ�n��G�еĶ�Ӧλ�� 
int LocateVex(MGraph G, VertexType n)
{
	int num = 0;
	while(G.vexs[num] != n) num++;
	return num;
}

void CreatUDG(MGraph &G)
{
	cin >> G.vexnum >> G.arcnum;
	// ���붥����Ϣ 
	for(int i = 0;i < G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}
	
	// ��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
	for(int i = 0;i < G.vexnum;i++)
		for(int j = 0;j < G.vexnum;j++)
			G.arcs[i][j] = MaxInt;
			
	// �����ڽӾ��� 
	for(int i = 0;i < G.arcnum;i++)
	{
		VertexType v1, v2;
		ArcType w;
		cin >> v1 >> v2 >> w;
		int x = LocateVex(G, v1);
		int y = LocateVex(G, v2);
//		cout << x << " " << y << " " << w << endl;
		G.arcs[x][y] = w;
		G.arcs[y][x] = G.arcs[x][y];	// ����ͼ�ǶԳƾ��� 
	}
		
}


// ��
void PrintUDG(MGraph G)
{
	for(int i = 0;i < G.arcnum;i++)
	{
		for(int j = 0;j < G.arcnum;j++)
		{
			if(G.arcs[i][j] != MaxInt) cout << G.arcs[i][j] << "   ";
			else cout << "��" << " ";
		}
		cout << endl;	
	}		
}


int FirstAdjVex(MGraph G, int v)
{
	for(int i = 0;i < G.vexnum;i++)
	{
		if(G.arcs[v][i] != MaxInt) return i;
	}
	return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
	if(G.arcs[v][w] != MaxInt)
	{
		for(int i = w + 1;i < G.vexnum;i++)
		{
			if(G.arcs[v][i] != MaxInt) return i;
		}
		return -1;
	}
	return -1;
}
#endif
