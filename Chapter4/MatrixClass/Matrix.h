#pragma once
#include <iostream>
#include "xcept.h"
using namespace std;

template<class T>
class Matrix
{
	template<class T> friend ostream& operator<<(ostream& out,const Matrix<T>& m);
public:
	Matrix(int r = 0, int c = 0);
	Matrix(const Matrix<T>& m);
	~Matrix(void)
	{
		delete[] element;
	}
	int Rows(void) const
	{
		return rows;
	}

	int Cols(void)const
	{
		return cols;
	}

	T& operator()(int i, int j)const;

	Matrix& operator=(const Matrix<T>& m);
	Matrix operator+()const;
	Matrix operator+(const Matrix<T>& m) const;
	Matrix operator-()const;
	Matrix operator-(const Matrix<T>& m) const;
	Matrix operator*(const Matrix<T>& m) const;
	Matrix& operator+=(const T& x);

private:
	int rows, cols;
	T* element;
};

template<class T>
Matrix<T>::Matrix(int r, int c)
{
	if(c < 0 || r < 0)
	{
		throw BadInitializers();
	}
	rows = r;
	cols = c;
	element = new T[r * c];
}

template<class T>
T& Matrix<T>::operator()(int i, int j)const
{
	if(i < 1 || i > rows || j < 1 || j > cols)
	{
		throw OutOfBounds();
	}
	return element[(i - 1) * cols + j - 1];
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	rows = m.rows;
	cols = m.cols;
	delete[] element;
	element = new T[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		element[i] = m.element[i];
	}
}

template<class T>
Matrix<T> Matrix<T>::operator+()const
{
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++)
	{
		w.element[i] = element[i];
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)const
{
	if(rows != m.rows || cols != m.cols)
	{
		throw SizeMisMatch();
	}
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++)
	{
		w.element[i] = element[i] + m.element[i];
	}
	return w;
}


template<class T>
Matrix<T> Matrix<T>::operator-()const
{
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++)
	{
		w.element[i] = -element[i];
	}
	return w;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)const
{
	if(rows != m.rows || cols != m.cols)
	{
		throw SizeMisMatch();
	}
	Matrix<T> w(rows, cols);
	for (int i = 0; i < rows * cols; i++)
	{
		w.element[i] = element[i] - m.element[i];
	}
	return w;
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const T& x)
{
	for (int i = 0; i < rows * cols; i++)
	{
		element[i] += x;
	}
	return *this;
}


template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)const
{
	if(rows != m.cols)
	{
		throw SizeMismatch();
	}
	Matrix<T> w(rows, m.cols);

	int ct = 0, cm = 0, cw = 0;
	for(int i = 1; i <= rows; i++)
	{
		for(int j = 1; j <= m.cols; j++)
		{
			T sum = element[ct]*m.element[cm];
			for(int k = 2; k <= cols; k++)
			{
				ct++;
				cm += m.cols;
				sum += element[ct] * m.element[cm];
			}
			w.element[cw++] = sum;
			ct -= cols - 1;
			cm = j;
		}
		ct += cols;
		cm = 0;
	}
	return w;
}

template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& m)
{
	for (int i = 0; i < m.rows * m.cols; i++)
	{
		out << m.element[i] << " ";
		if(i % m.cols ==  m.cols - 1)
		{
			cout << endl;
		}
	}
	return out;
}