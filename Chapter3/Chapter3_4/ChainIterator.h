#pragma once
#include "Chain.h"


template<class T>
class ChainIterator
{
public:
	T* Initialize(const Chain<T>& c)
	{
		location = c.first;
		if(location)
		{
			return &location->data;
		}
		return 0;
	}

	T* Next()
	{
		if(!location)
		{
			return 0;
		}
		location = location->link;
		if(location)
		{
			return &location->data;
		}
		return 0;
	}
	//ChainIterator(void);
	//~ChainIterator(void);


private:
	ChainNode<T>* location;
};

