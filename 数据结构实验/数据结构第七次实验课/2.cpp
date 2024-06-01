#include<iostream>
#include<cstdlib>
#define MAXN 20

using namespace std;

typedef char VertexType;
typedef int InfoType;

//�߽������Ͷ��� 
typedef struct ArcNode{
	int adjvex;					// �ߵ���һ������������е�λ�� 
	struct ArcNode *nextarc;	// ָ����һ���ߵ�ָ��
	InfoType info;
}ArcNode; 

//������ 
typedef struct VNode{
	VertexType data;	// ������Ϣ
	ArcNode *firstarc;	//ָ������ö���ı����� 
}VNode, AdjList[MAXN];

typedef struct{
	AdjList vertices;
	int vexnum, arcnum;	// ͼ�ĵ�ǰ�������ͱ��� 
}ALGragh;

// �ҵ�n��G�еĶ�Ӧλ�� 
int LocateVex(ALGragh G, VertexType n)
{
	int num = 0;
	while(G.vertices[num].data != n) num++;
	return num;
}

void CreatUDG(ALGragh &G)
{
	cin >> G.vexnum >> G.arcnum;
	
	//��������㣬�����ͷ��� 
	for(int i = 0; i < G.vexnum;i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	
	//������ߣ������ڽӱ� 
	for(int i = 0;i < G.arcnum;i++)
	{
		VertexType v1, v2;
		InfoType w;
		cin >> v1 >> v2 >> w;
		//ȷ��v1��v2��G�е�λ�� 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		
		ArcNode *p1, *p2;
		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = y;
		p1->nextarc = G.vertices[x].firstarc;
		p1->info = w;
		G.vertices[x].firstarc = p1;	//���½����뵽����vi�ı�����ͷ�� 
		
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = x;
		p2->nextarc = G.vertices[y].firstarc;
		p2->info = w;
		G.vertices[y].firstarc = p2;	//���½����뵽����vj�ı�����ͷ�� 	 	
	}
}

void PrintUDG(ALGragh G)
{
	for(int i = 0;i < G.vexnum;i++)
	{
		cout << G.vertices[i].data << '\t';	// �����ͷ�����Ϣ 
		// �����ͷ������ŵ���Ϣ 
		while(G.vertices[i].firstarc != NULL) 
		{
			cout << G.vertices[i].firstarc->adjvex << " ";	// ����߽������ 
			cout << G.vertices[i].firstarc->info << '\t';	// ����ߵ�Ȩֵ 
			G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;	// ָ����� 
		}
		cout << endl;
	}
}
int main()
{
	ALGragh G;
	CreatUDG(G);
	PrintUDG(G);
	return 0;
}
