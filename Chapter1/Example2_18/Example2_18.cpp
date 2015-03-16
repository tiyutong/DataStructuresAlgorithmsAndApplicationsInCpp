// Example2_18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

template<class T>
void Insert(T a[], int n, const T& x)
{
	int i;
	for (i = n - 1;  i >= 0 && x < a[i]; i--)
	{
		a[i + 1] = a[i];
	}
	a[i + 1] = x;
}

template<class T>
void InsertionSort(T a[], int n)
{
	for(int i = 1; i < n; i++)
	{
		T t = a[i];
		Insert(a, i, t);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	//InsertionSort(a, 10);

	int a[60000] = {0};
	int step = 1000;
	clock_t start, finish;

	for (int i = 50000; i < 60000; i += step)
	{
		start = clock();
		for(int n = 0; n < i; n ++)
		{
			a[n] = i - n;
		}

		InsertionSort(a, i);

		finish = clock();

		std::cout << i << '=' << (finish - start) / CLK_TCK << std::endl;
	}

	return 0;
}

