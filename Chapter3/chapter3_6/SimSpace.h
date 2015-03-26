#pragma once
#include "SimNode.h"
#include "xcept.h"

template<class T>
class SimSpace
{
public:
	SimSpace(int MaxSpaceSize = 100);
	~SimSpace(void)
	{
		delete[] node;
	}

	int Allocate();
	void Deallocate(int& i);

private:
	int NumberOfNodes, first1, first2;
	SimNode<T> *node;
};

template<class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes = MaxSpaceSize;

	node = new SimNode<T>[NumberOfNodes];
	
	first1 = 0;
	first2 = 0;
}

template<class T>
int SimSpace<T>::Allocate()
{
	if(first2 == -1)
	{
		if(first1 == NumberOfNodes)
		{
			throw NoMem();
		}
		return first1++;
	}
	int i = first2;
	first2 = node[i].link;
	return i;
}

template<class T>
void SimSpace<T>::Deallocate(int& i)
{
	node[i].link = first;
	first = i;
	i = -1;
}

template<class T>
void SimSpace<T>::DeallocateCircular(int& c)
{
	if( c != -1)
	{
		int next = node[c].link;
		node[c].link = first;
		first = next;
		c = -1;
	}
}