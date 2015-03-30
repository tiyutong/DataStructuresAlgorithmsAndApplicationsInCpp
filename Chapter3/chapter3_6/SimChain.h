#pragma once
#include "SimSpace.h"
#include <iostream>
using namespace std;

template <class T>
class SimChain
{
	template<class T> friend class SimChainIterator;
public:
	SimChain(void)
	{
		first = -1;
	}
	~SimChain(void)
	{
		Destroy();
	}

	void Destroy();
	int Length() const;
	bool Find(int  k, T& x) const;
	int Search(const T& x) const;
	SimChain<T>& Delete(int k, T& x);
	SimChain<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;


private:
	int first;
	static SimSpace<T> S;
};

template<class T>
void SimChain<T>::Destroy()
{
	int next;
	while(first != -1)
	{
		next = S.node[first].link;
		S.Deallocate(first);
		first = next;
	}
}

template<class T>
int SimChain<T>::Length()const
{
	int current = first;
	int len = 0;
	while(current != -1)
	{
		current = S.node[current].link;
		len++;
	}
	return len;
}

template<class T>
void SimChain<T>::Output(ostream& out) const
{
	int current = first;
	while(current != -1)
	{
		out << S.node[current].data << "  ";
		current = S.node[current].link;
	}

}

template<class T>
bool SimChain<T>::Find(int k, T& x)const
{
	if(k < 1)
	{
		return false;
	}

	int current = first;
	int index = 1;
	while(index < k && current != -1)
	{
		current = S.node[current].link;
		index++;
	}
	if(current != -1)
	{
		x = S.node[current].data;
		return true;
	}
	return false;
}

template<class T>
SimChain<T>& SimChain<T>::Delete(int k, T& x)
{
	if(k < 1 || first == -1)
	{
		throw OutOfBounds();
	}
	int p = first;
	if(k == 1)
	{
		first = S.node[first].link;
	}
	else
	{
		//使用q指向第k - 1个元素
		int q = first;
		for(int index = 1; index < k - 1 && q != -1; index++)
		{
			q = S.node[q].link;
		}

		if((q == -1) || S.node[q].link == -1)
		{
			throw OutOfBounds();
		}
		p = S.node[q].link;
		S.node[q].link = S.node[p].link;
	}

	x = S.node[p].data;
	S.Deallocate(p);
	return *this;
}

template<class T>
SimChain<T>& SimChain<T>::Insert(int k,const T& x)
{
	if(k < 0)
	{
		throw OutOfBounds();
	}

	int p = first;
	for(int index = 1; index < k && p != -1; index++)
	{
		p = S.node[p].link;
	}
	//验证第k个节点的存在性
	if(k > 0 && p == -1)
	{
		throw OutOfBounds();
	}

	int y = S.Allocate();
	S.node[y].data = x;
	if(k)
	{
		S.node[y].link = S.node[p].link;
		S.node[p].link = y;
	}
	else //作为链表的首节点插入
	{
		S.node[y].link = first;
		first = y;
	}

	return *this;
}

template<class T>
int SimChain<T>::Search(const T& x) const
{
	for (int i = 0; i < Length(); i++)
	{
		if(S.node[i].data == x)
		{
			return i;
		}
	}
	return -1;
}

template< class T>
ostream& operator << (ostream& out, SimChain<T>& c)
{
	c.Output(out);
	return out;
}