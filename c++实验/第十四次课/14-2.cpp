#include <iostream>

using namespace std;

class Matrix      //����Matrix��
{
	int mat[50][50];
public:
	static int m, n;
	Matrix(int x, int y);                    //Ĭ�Ϲ��캯��

	friend Matrix operator+ (Matrix a, Matrix b);
	friend Matrix operator- (Matrix a, Matrix b);
	friend Matrix operator* (Matrix a, Matrix b);
	friend Matrix operator/ (Matrix a, Matrix b);

	void input();                                    //�������ݺ���
	void display();                                  //������ݺ���
};
int Matrix::m = 2;
int Matrix::n = 2;

Matrix::Matrix(int x, int y)                             //���幹�캯��
{
	m = x; n = y;
	for (int i = 0; i<x; i++)
	for (int j = 0; j<y; j++)  mat[i][j] = 0;
}

//�������������"+"����
Matrix operator+ (Matrix a, Matrix b)
{
	Matrix c(Matrix::m, Matrix::n);
	for (int i = 0; i<a.m; i++)
	for (int j = 0; j<a.n; j++)  { c.mat[i][j] = a.mat[i][j] + b.mat[i][j]; }
	return c;
}

//�������������"-"����
Matrix operator- (Matrix a, Matrix b)
{
	Matrix c(Matrix::m, Matrix::n);
	for (int i = 0; i<a.m; i++)
	for (int j = 0; j<a.n; j++)  { c.mat[i][j] = a.mat[i][j] - b.mat[i][j]; }
	return c;
}

//�������������"*"����
Matrix operator* (Matrix a, Matrix b)
{
	Matrix c(Matrix::m, Matrix::n);
	for (int i = 0; i<a.m; i++)
	for (int j = 0; j<a.n; j++)  { c.mat[i][j] = a.mat[i][j] * b.mat[i][j]; }
	return c;
}
//�������������"/"����
Matrix operator/ (Matrix a, Matrix b)
{
	Matrix c(Matrix::m, Matrix::n);
	for (int i = 0; i<a.m; i++)
	for (int j = 0; j<a.n; j++)  { c.mat[i][j] = a.mat[i][j] / b.mat[i][j]; }
	return c;
}
void Matrix::input()                              //�����������ݺ���
{
	cout << "input the value of matrix:" << endl;
	int i, j;
	for (i = 0; i<this->m; i++)
	{
		for (j = 0; j<this->n; j++) { cin >> mat[i][j]; }
	}
}
void Matrix::display()                            //����������ݺ���
{
	for (int i = 0; i<this->m; i++)
	{
		for (int j = 0; j<this->n; j++)  { cout << mat[i][j] << " "; }
		cout << endl;
	}
}
int main()
{
	cout << "Please input two dimensions of the matrix:  ";
	cin >> Matrix::m >> Matrix::n;
	Matrix a(Matrix::m, Matrix::n), b(Matrix::m, Matrix::n), c(Matrix::m, Matrix::n);
	a.input();  b.input();  cout << endl << "Matrix a:" << endl;  a.display();
	cout << endl << "Matrix b:" << endl;  b.display();
	c = a + b;                    //�����������"+"ʵ�������������
	cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;  c.display();
	c = a - b;                     //�����������"+"ʵ�������������
	cout << endl << "Matrix c = Matrix a - Matrix b :" << endl;  c.display();
	c = a*b;                     //�����������"+"ʵ�������������
	cout << endl << "Matrix c = Matrix a * Matrix b :" << endl;  c.display();
	c = a / b;                      //�����������"+"ʵ�������������
	cout << endl << "Matrix c = Matrix a / Matrix b :" << endl;  c.display();

	system("pause");
	return 0;
}
