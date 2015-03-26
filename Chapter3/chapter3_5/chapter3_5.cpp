// chapter3_5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "indlist.h"


int _tmain(int argc, _TCHAR* argv[])
{
	IndirectList<float> iList(5);

	iList.Insert(0, 1.23F);
	iList.Insert(1, 2.25F);

	cout << iList << endl;
	return 0;
}

