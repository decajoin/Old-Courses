#include<iostream>

using namespace std;

int n = 1;
void move(char a,int n,char b)
{
	cout << n << ":" << " ";
	cout << n << " " << a << " " << b <<endl;
	n++;
}

void hanoi(int n,char x,char y,char z)
{
	if(n == 1) move(x,1,z);	// �����Ϊ1��Բ�̴�x�Ƶ�z 
	else
	{
		hanoi(n - 1,x,z,y);	// ��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z��������  
		move(x,n,z);		// �����Ϊn��Բ�̴�x�Ƶ�z 
		hanoi(n - 1,y,x,z);	// ��y�ϱ��Ϊ1��n-1��Բ���Ƶ�z��x�������� 
	}
}

int main()
{
	int n;
	cin >> n;
	hanoi(n,'A','B','C');
	return 0;
}
