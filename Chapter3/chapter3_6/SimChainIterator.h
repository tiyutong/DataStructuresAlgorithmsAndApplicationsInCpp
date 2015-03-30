#pragma once
#include "SimChain.h"
#include "SimNode.h"

template<class T>
class SimChainIterator
{
public:
	SimChainIterator(void)
	{
	}
	~SimChainIterator(void)
	{
	}

	T* Initialize(const SimChain<T>& c)
	{
		node = c.S.node;
		if(c.first != -1)
		{
			location = c.first;
			return &node[location].data;
		}
		return 0;
	}

	T* Next()
	{
		if(0 == location)
		{
			return 0;
		}

		location = node[location].link;
		if(location != -1)
		{
			return & node[location].data;
		}

		return 0;
	}



private:
	int location;
	SimNode<T>* node;
};

