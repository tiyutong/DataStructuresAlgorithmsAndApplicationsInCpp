// Example2_41.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

template<class T>
int BinarySearch(T a[], const T& x, int n)
{
	int left = 0; 
	int right = n - 1;

	while(left <= right)
	{
		int middle = (left + right) / 2;
		
		if(x == a[middle])
		{
			return middle;
		}
		
		if(x > a[middle])
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	return - 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[100000] = {0};
	int step = 1000;
	clock_t start, finish;

	for (int i = 90000; i < 100000; i += step)
	{
		start = clock();
		for(int n = 0; n < i; n ++)
		{
			a[n] = i - n;
		}

		int index = BinarySearch(a, 7, i);

		finish = clock();

		std::cout << i << '=' << (finish - start) / CLK_TCK << std::endl;
	}
	return 0;
}

