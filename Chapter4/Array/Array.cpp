// Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Array1D.h"
#include "Array2D.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Array1D<int> array1(30);
	array1 += 3;
	Array1D<int>array2 = - array1;
	Array1D<int>array3(array2);
	Array1D<int>array4 = array1 + array3;
	
	cout << array1 << endl;
	cout << array2 << endl;
	cout << array3 << endl;
	cout << array4 << endl;


	Array2D<int> array2d;
	return 0;
}

