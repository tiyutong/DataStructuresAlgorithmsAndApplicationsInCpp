// MatrixClass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Matrix.h"
#include "SparseMatrix.h"
#include "Term.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Matrix<int> a(1, 3);
	Matrix<int> b(3, 1);
	a(1,1) = 1;
	a(1,2) = 2;
	a(1,3) = 3;

	b(1,1) = 1;
	b(2,1) = 2;
	b(3,1) = 3;

	Matrix<int> c = a * b;
	Matrix<int> d = b * a;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	SparseMatrix<int> sparseMatrix(10);
	cin >> sparseMatrix;
	cout << sparseMatrix << endl;

	return 0;
}

