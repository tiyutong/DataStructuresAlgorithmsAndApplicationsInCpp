// MatrixClass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Matrix.h"

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

	return 0;
}

