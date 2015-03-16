// Exercise1_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
bool IsArrayAscend(T array[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if(array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char list[8] = "abcdefg";
	if(IsArrayAscend(list, 7))
	{
		cout << "Yes, list is ascend" << endl;
	}
	else
	{
		cout << "No, list is descend" << endl;
	}

	getchar();
	return 0;
}

