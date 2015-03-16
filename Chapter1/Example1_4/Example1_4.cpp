// Example1_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Currency.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Currency c(plus, 100 ,30);
	cout << c;

	getchar();
	return 0;
}

