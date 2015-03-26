#pragma once

template<class T> class SimSpace;

template<class T>
class SimNode
{
	friend class SimSpace<T>;

private:
	T data;
	int link;

public:
	SimNode(void);
	~SimNode(void);
};

