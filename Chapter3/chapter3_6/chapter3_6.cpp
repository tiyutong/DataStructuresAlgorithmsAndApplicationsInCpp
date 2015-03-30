// chapter3_6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "SimChain.h"
#include "SimSpace.h"
#include "SimChainIterator.h"

using namespace std;


SimSpace<int> SimChain<int>::S;

int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	SimChain<int> c;
	cout << "Chain length is " << c.Length() << endl;
	c.Insert(0, 2).Insert(1,6);
	cout << "Current chain is "<< c << endl;
	cout << "Chain length is " << c.Length() << endl;
	c.Find(1, x);
	cout << "First element is "<< x << endl;
	c.Delete(1, x);
	cout << "Deleted "<< x << endl;
	cout << "New length is " << c.Length() << endl;
	cout << "Position of 2 is "<< c.Search(2) << endl;
	cout << "Position of 6 is "<< c.Search(6) << endl;
	c.Insert(0, 9).Insert(1, 8);
	c.Insert(2, 7);
	cout << "Current chain is "<< c << endl;
	cout << "Its length is " << c.Length() << endl;


	int *x2;
	SimChainIterator<int> it;
	x2 = it.Initialize(c);
	while(x2)
	{
		cout << *x2 << ' ';
		x2= it.Next();
	}

	cout << endl;


	return 0;
}

