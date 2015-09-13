#pragma once
#include <iostream>
using namespace std;
template<class T>class SparseMatrix;

template<class T>
class Term
{
	friend  SparseMatrix<T>;
	template<class T>friend ostream& operator<<	(ostream&, const SparseMatrix<T>&);
	template<class T>friend istream& operator>>(istream&, SparseMatrix<T>&);
public:

private:
	int row, col;
	T value;
};

