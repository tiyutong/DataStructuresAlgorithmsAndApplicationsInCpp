#pragma once

template<class T> class SimSpace;
template<class T> class SimChain;

template<class T>
class SimNode
{
	friend class SimSpace<T>;
	friend class SimChain<T>;
	
	template<class T> friend class SimChainIterator;

private:
	T data;
	int link;

public:
	SimNode(void)
	{
	}
	~SimNode(void)
	{
	}
};

