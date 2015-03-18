// Chapter3_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Chain.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Chain<int> test;
	test.Insert(0,3);
	test.Insert(1, 4);
	cout << test;
	int x;

	test.Delete(2,x);
	
	cout << test;
	return 0;
}

