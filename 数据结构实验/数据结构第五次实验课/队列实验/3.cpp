#include<iostream>
#include"myQueue1.h"
#include"mystack2.h"
using namespace std;

void Arrival(LinkStack &P, LinkQueue &Q, int n, int num, int time)
{
	// Len_P����ջ����Ԫ�ظ��� 
	int Len_P = StackLength(P);
	// Len_Q���ڶ�������Ԫ�ظ��� 
	int Len_Q = QueueLength(Q);
	// ѹλ - ����ͷ�ļ���data��һ�����ݣ����������ǰ�num��timeѹλ�ٴ���ջ 
	// ��ʱ�䳬��10000ʱ��ѹλ����ʧЧ��������Ŀδ�������巶Χ����ʱѡȡ10000Ϊʱ�����ֵ 
	int comx = num * 10000 + time;
	if(Len_P < n)
	{
		push(P, comx);	// ��ջ
		Len_P++;
		cout << "parking location:" << Len_P << endl;
	}
	else
	{
		EnQueue(Q, comx);	// ���
		Len_Q++;
		cout << "sidewalk location:" << Len_Q << endl;
	}
}

void Leave(LinkStack &P, LinkQueue &Q, LinkStack &T, int n, int num,int time)
{
	// x��Ŀ�공����ջ��λ�� 
	int x = StackFind(P, num);
	int e;
	if(n != -1)
	{
		for(int i = 0;i < x;i++)
		{
			pop(P, e);
			push(T ,e);
		}
		pop(P, e);
		// ��ѹλ���ݴ�����ȡ������ͣ������ʱ�� 
		int time1 = e - 10000 * num;
		int ans = time - time1;
		cout << "time: " << ans << " parking fees: " << ans << endl;
		for(int i = 0;i < x;i++)
		{
			pop(T, e);
			push(P, e);
		}
		int Len_Q = QueueLength(Q);
		// ֻ�еȴ��������г���ʱ�ų��� 
		if (Len_Q > 0)
		{
			DeQueue(Q, e);
			// ���´Ӷ��н���ջ�ĳ��Ľ���ͣ������ʱ�� 
			int num1 = e / 10000;
			e = num1 * 10000 + time;
			push(P, e); 
		}
	}
	else cout<< "���ƺ����������" << endl;
	
}
int main()
{
	LinkStack P;
	LinkStack T;
	LinkQueue Q;
	InitQueue(Q);
	InitStack(P);
	InitStack(T);
	char ch;
	int n, num, time;
	
	cin >> n;
	getchar();
	
	while(1)
	{
		printf("\n  A. The Car Arrive  D. The Car Leave   E. Exit System\n");
		scanf("%c%d%d",&ch, &num, &time);
		getchar();	// �����س���chֵ��Ӱ�� 
		switch(ch) 
		{
			case 'A': Arrival(P, Q, n, num, time);  break; /*��������*/
			case 'D': Leave(P, Q, T, n, num, time);    break; /*�����뿪*/
			case 'E': return 0;          /*�˳�������*/ 
			default: break;
		}
	}
	
	return 0;
}
