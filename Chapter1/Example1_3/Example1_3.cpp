// Example1_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
inline void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void Perm(T list[], int k, int m)
{
	int i = 0;
	if(k == m)
	{
		for (i = 0; i <= m; i++)
		{
			cout << list[i];
		}
		cout << endl;
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			Swap(list[k], list[i]);
			Perm(list, k + 1, m);
			Swap(list[k], list[i]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char list[8] = "abcdefg";
	Perm(list, 0, 3);
	return 0;
}

