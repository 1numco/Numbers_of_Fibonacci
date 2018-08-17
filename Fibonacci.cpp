#include <iostream>
using namespace std;
int** matrix_multiply(int** mat1, int** mat2)
{
	int** mat3;
	mat3 = new int*[2];
	for (int i = 0; i < 2; i++)
		mat3[i] = new int[2];
	mat3[0][0] = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
	mat3[0][1] = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
	mat3[1][0] = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
	mat3[1][1] = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
	return mat3;
}

int** pow(int** mat3,int n)
{
	int** mat;
	mat = new int*[2];
	for (int i = 0; i < 2; i++)
		mat[i] = new int[2];
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[1][0] = 0;
	mat[1][1] = 1;
	if (n == 0)
		return mat;
	if (n == 1)
		return mat3;
	if (n % 2)
	{
		return matrix_multiply(mat3, pow(matrix_multiply(mat3, mat3), n / 2));
	}
	else
	{
		return pow(matrix_multiply(mat3, mat3), n / 2);
	}
}
int fib(int** mat,int n)
{
	return pow(mat,n - 1)[0][0];
}
int main()
{
	int n = 0;
	cout << "Enter the serial number: " << endl;
	cin >> n;
	int** mat;
	mat = new int*[2];
	for (int i = 0; i < 2; i++)
		mat[i] = new int[2];
	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 0;
	cout << "Your desired number of Fibonacci: "<<fib(mat,n)<<endl;
	system("pause");
	return 0;
}