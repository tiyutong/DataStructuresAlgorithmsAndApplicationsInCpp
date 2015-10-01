// Chapter5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

const int maxLength = 100;	//最大的字符串长度

void PrintMatchedPairs(char * expr)
{
	Stack<int> s(maxLength);
	int  j, length = strlen(expr);
	for (int i = 1; i <= length; i++)
	{
		if (expr[i - 1] == '(')
		{
			s.Add(i);
		}
		else if (expr[i - 1] == ')')
		{
			try
			{
				s.Delete(j);
				cout << j << ' ' << i << endl;
			}
			catch (OutOfBounds)
			{
				cout << "No match for right parenthesis" << "at" << i << endl;
				
			}

			while (!s.IsEmpty())
			{
				s.Delete(j);
				cout << "No match for left parenthesis at" << j << endl;
			}
		}
		else
		{ }
	}
}

int main()
{
	char expr[maxLength];
	cout << "Type an epression of length at most " << maxLength << endl;
	cin.getline(expr, maxLength);

	cout << "The pairs of matching parentheses in" << endl;
	puts(expr);
	cout << "are" << endl;
	PrintMatchedPairs(expr);

    return 0;
}

