// Example2_16.cpp : 定义控制台应用程序的入口点。
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
void SelectinSort(T a[], int n)
{
	bool sorted = false;
	for(int size = n; !sorted && (size > 1); size--)
	{
		int pos = 0;
		sorted = true;
		for(int i = 0; i < size; i++)
		{
			if(a[pos] <= a[i])
			{
				pos = i;
			}
			else
			{
				sorted = false;
			}
		}
		Swap(a[pos], a[size - 1]);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	SelectinSort(a, 10);

	return 0;
}

