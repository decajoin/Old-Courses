#include<iostream>
#include<string.h>
using namespace std;

typedef struct Student_{
	int num;
	string sex;
	string name;
	string place;
}Student;

int main()
{
	Student S;
	S.name = "Tim";
	S.place = "�Ͼ�";
	S.sex = "��";
	S.num = 16;
	
	cout<< "������" << S.name << endl;
	cout<< "ѧ�ţ�" << S.num << endl;
	cout<< "��ַ��" << S.place << endl;
	cout<< "�Ա�" << S.sex << endl;
	
 	return 0;
}
