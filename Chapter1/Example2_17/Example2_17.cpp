// Example2_17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template<class T>
inline void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
bool Bubble(T a[], int n)
{
	bool swapped = false;
	for(int i = 0; i < n - 1; i++)
	{
		if(a[i] > a[i + 1])
		{
			Swap(a[i], a[i + 1]);
			swapped = true;
		}
	}
	return swapped;
}

template<class T>
void BubbleSort(T a[], int n)
{
	for(int i = n; i > 1 && Bubble(a, i); i--)
	{

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	BubbleSort(a, 10);

	return 0;
}

