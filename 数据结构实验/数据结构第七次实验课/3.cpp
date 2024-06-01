#include"myGraph.h"

using namespace std;
bool vis[MAXN];
void DFS(MGraph G, int v)
{
	cout << G.vexs[v] << " ";
	vis[v] = true;
	//���μ��V�������ڽӵ�w��FirstAdjVex(G, v)��ʾv�ĵ�һ���ڽӵ�  
	// NextAdjVex(G, v, w)��ʾv�������w����һ���ڽӵ㣬w��0��ʾ�����ڽӵ� 
	for(int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
		if(!vis[w]) DFS(G, w);
}
int main()
{
	MGraph G; 
	CreatUDG(G);
	
	// ��֤�ڷ���ͨͼ��״̬��Ҳ��ʵ��ȫ������ 
	for(int v = 0; v < G.vexnum; v++) 
		if(!vis[v]) DFS(G, v);
	
	return 0;
}
