#pragma once

#include <iostream>
#include "xcept.h"
using namespace std;

template<class T>class Chain;
template<class T>class ChainIterator;

template<class T>
class ChainNode
{
	friend class Chain<T>;
	friend class ChainIterator<T>;

private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain
{
	friend class ChainIterator<T>;
	template<class T> friend Chain<T> Alternate(Chain<T>& a,Chain<T>& b);
public:
	Chain(void)
	{
		first = 0;
	}
	~Chain(void);

	Chain(const Chain& c);

	bool IsEmplty() const
	{
		return first == 0;
	}

	int Length() const;
	bool Find(int k, T&x) const;
	int Seartch(const T& x)const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k,const T& x);
	Chain<T>& Reverse();
	Chain<T>& InsertionSort();
	void Output(ostream& out)const;
	void Erase();
	void Zero()
	{
		first = 0;
	}
	Chain<T>& Append(const T& x);

	Chain& operator = (const Chain& c);

	ChainNode<T>* GetLastNode(ChainNode<T>* node);

	void BinSort(int range, int (*value)(T& x));
private:
	ChainNode<T> *first;
	ChainNode<T> *last;

};

template<class T>
Chain<T>::Chain(const Chain<T>& c)
{
	first = 0;

	int index = 0;
	int* px;
	ChainIterator<int> cIter;
	px = cIter.Initialize(c);
	while(px)
	{
		Insert(index++,*px);
		px = cIter.Next();
	}
}

template<class T>
Chain<T>& Chain<T>::operator = (const Chain<T>& c)
{
	if(first != c.first)
	{
		Erase();
		first = 0;
		int index = 0;
		int* px;
		ChainIterator<int> cIter;
		px = cIter.Initialize(c);
		while(px)
		{
			Insert(index++,*px);
			px = cIter.Next();
		}
	}
	return *this;
}

template<class T>
Chain<T>::~Chain()
{
	ChainNode<T>* next;
	while(first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length()const
{
	ChainNode<T>* current = first;
	int len = 0;
	while(current)
	{
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x)const
{
	if(k < 1)
	{
		return false;
	}

	ChainNode<T>* current = first;
	int index = 1;
	while(index < k && current)
	{
		current = current->link;
		index++
	}
	if(current)
	{
		x = current->data;
		return true;
	}
	return false;
}

template<class T>
int Chain<T>::Seartch(const T& x)const
{
	ChainNode<T>* current = first;
	int index = 1;
	while(current && current->data != x)
	{
		current = current->link;
		index++;
	}
	if(current)
	{
		return index;
	}

	return 0;
}


template<class  T>
void Chain<T>::Output(ostream& out)const
{
	ChainNode<T>* current;
	for(current = first; current; current = current->link)
	{
		out << current->data << " ";
	}
}

template<class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{
	if( k < 1 || !first)
	{
		throw OutOfBounds();
	}

	ChainNode<T>* p = first;
	if(k == 1)
	{
		first = first->link;
	}
	else
	{
		ChainNode<T>* q = first;
		for(int index = 1; index < k - 1 && q; index++)
		{
			q = q->link;
		}
		if(!q || !q->link)
		{
			throw OutOfBounds();
		}

		p = q->link;
		if(p == last)
		{
			last = q;
		}
		q->link = p->link;
	}
	x = p->data;
	delete p;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{
	if(k < 0)
	{
		throw OutOfBounds();
	}

	ChainNode<T>* p = first;
	for(int index = 1; index < k && p; index++)
	{
		p = p->link;
	}

	if(k > 0 && !p)
	{
		throw OutOfBounds();
	}

	ChainNode<T>* y = new ChainNode<T>;
	y->data = x;
	if(k)
	{
		y->link = p->link;
		p->link = y;
	}
	else
	{
		y->link = first;
		first = y;
	}

	if(!y->link)
	{
		last = y;
	}

	return *this;
}

template<class T>
void Chain<T>::Erase()
{
	ChainNode<T> *next;
	while(first)
	{
		next = first->link;
		delete first;
		first =  next;
	}
}

template<class T>
Chain<T>& Chain<T>::Append(const T& x)
{
	ChainNode<T> *y;
	y = new ChainNode<T>;
	y->data = x;
	y->link = 0;

	if(first)
	{
		last->link = y;
		last = y;
	}
	else
	{
		first = last = y;
	}

	return *this;
}

template<class T>
Chain<T>& Chain<T>::Reverse()
{
	last = first;
	ChainNode<T> *current = first;
	ChainNode<T> *next = current->link;
	while(next)
	{
		ChainNode<T> *tmp = next->link;
		next->link = current;
		current = next;
		next = tmp;
	}
	first = current;
	last->link = 0;
	return *this;
}

template<class T>
ChainNode<T>* Chain<T>::GetLastNode(ChainNode<T>* node)
{
	ChainNode<T> *current = first;
	while(current)
	{
		if(current->link == node)
		{
			return current;
		}
		current = current->link;
	}
	return 0;
}

template<class T>
Chain<T>& Chain<T>::InsertionSort()
{
	ChainNode<T> *current = first;
	ChainNode<T> *next = current->link;
	ChainNode<T>* temp;
	while(next)
	{
		ChainNode<T> *x = next->link;	//保存下一个节点，用于下次循环
		current = first;
		while(current != next)
		{
			if(current->data > next->data)
			{
				temp = GetLastNode(next);
				if(temp)
				{
					temp->link = next->link;
				}
				if(current == first)
				{
					ChainNode<T>* temp = first;
					first = next;
					first->link = temp;
				}
				else
				{
					temp = GetLastNode(current);
					temp->link = next;
				}
				next->link = current;
				break;
			}
			current = current->link;
		}
		next = x;
	}

	return *this;
}

template<class T>
void Chain<T>::BinSort(int range, int (*value)(T& x))
{
	int b;
	ChainNode<T>** bottom, **top;
	bottom = new ChainNode<T>* [range + 1];
	top = new ChainNode<T>* [range + 1];

	for(b = 0; b <= range; b++)
	{
		bottom[b] = 0;
	}

	for(; first; first = first->link)
	{
		b = value(first->data);
		if(bottom[b])
		{
			top[b]->link = first;
			top[b] = first;
		}
		else
		{
			bottom[b] = top[b] = first;
		}
	}

	ChainNode<T> *y = 0;
	for(b = 0; b <= range; b++)
	{
		if(bottom[b])
		{
			if(y)
			{
				y->link = bottom[b];
			}
			else
			{
				first = bottom[b];
			}
			y = top[b];
		}
	}

	if(y)
	{
		y->link = 0;
	}

	delete[] bottom;
	delete[] top;
}