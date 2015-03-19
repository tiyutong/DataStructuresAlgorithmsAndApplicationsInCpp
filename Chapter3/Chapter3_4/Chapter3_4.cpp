// Chapter3_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Chain.h"
#include <iostream>
#include "ChainIterator.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Chain<int> test;
	test.Insert(0,3);
	test.Insert(1, 4);
	cout << test << endl;;

	Chain<int> test2(test);
	cout << test2 << endl;

	
	Chain<int> test3 = test2;
	cout << test3 << endl;
	//int x;

	//test.Delete(2,x);
	//
	//cout << test;

	//cout << endl;

	//int* px;
	//ChainIterator<int> c;
	//px = c.Initialize(test);

	//while(px)
	//{
	//	cout << *px << ' ';
	//	px = c.Next();
	//}
	return 0;
}

