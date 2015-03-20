// Chapter3_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Chain.h"
#include <iostream>
#include "ChainIterator.h"

template<class T>
Chain<T> Alternate(Chain<T>& a,Chain<T>& b)
{
	Chain<T> ret;

	ChainIterator<int> aIter;
	ChainIterator<int> bIter;
	int* pa = aIter.Initialize(a);
	int* pb = bIter.Initialize(b);
	int index = 0;
	while(pa)
	{
		ret.Insert(index++,*pa);
		if(pb)
		{
			ret.Insert(index++,*pb);
			pb = bIter.Next();
		}
		pa = aIter.Next();
	}

	while(pb)
	{
		ret.Insert(index++,*pb);
		pb = bIter.Next();
	}

	return ret;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Chain<int> test;
	test.Insert(0,1);
	test.Insert(1, 3);
	test.Insert(2, 5);
	test.Insert(3, 7);
	cout << "test = "<< test << endl;;

	Chain<int> test2(test);
	cout << "test2 = " << test2 << endl;

	
	Chain<int> test3 = test2;
	cout << "test3 = " << test3 << endl;

	
	Chain<int> revTest = test.Reverse();
	cout << "revTest = " << revTest << endl;

	Chain<int> test4;
	test4.Insert(0, 2);
	test4.Insert(1, 6);
	test4.Insert(2, 4);
	test4.Insert(3, 18);
	test4.Insert(4, 10);

	
	cout << "test2 = " << test2 << endl;
	cout << "test4 = " << test4 << endl;
	Chain<int> alternate = Alternate(test2, test4);
	 
	cout<< "Alternate = " << alternate << endl;

	alternate.InsertionSort();
	cout<< "alternate.InsertionSort() = " << alternate << endl;

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

