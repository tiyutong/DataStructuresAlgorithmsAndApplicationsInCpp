// Exercise1_5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
#include <algorithm>  
#include <iterator> 
#include <vector>

using namespace std;

struct classcomp 
{
	bool operator() (const string& lhs, const string& rhs) const
	{
		//int len1 = lhs.length();
		//int len2 = rhs.length();
		//if(len1 < len2)
		//{
		//	return false;
		//}

		return lhs > rhs;
	}
};

set<string> subset;

template<class T>
inline void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void GetSubSet(char list[], int k, int m)
{
	string temp ;
	int i = 0 ;
	if(k <= m)
	{
		for (i = k; i <= m; i++)
		{
			temp += list[i];
		}
		subset.insert(temp);

		for (i = k; i <= m; i++)
		{
			Swap(list[k], list[i]);
			GetSubSet(list, k + 1, m);
			Swap(list[k], list[i]);
		}
	}
	else
	{
		//cout << "{ }" << endl;
		subset.insert("{}");
	}


}

int _tmain(int argc, _TCHAR* argv[])
{	
	char list[8] = "abcdefg";
	GetSubSet(list, 0, 3);

	set<string, classcomp> s2(subset.begin(), subset.end());

	//set<string>::const_iterator set_it = s2.begin();
	//while(set_it != s2.end())
	//{
	//	cout << *set_it << " ";
	//	++set_it;
	//}
	//cout << endl;

	   // print the 1st set.
    copy(subset.begin(), subset.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
     
	 // print the 2nd set with customized comp.
    copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
     
	vector<string> v;

	// convert set to vector, and print the vector.
    copy(subset.begin(), subset.end(), back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));    
    cout << endl;
     
    // sort the vector with customized comparator, then print it out.
    sort(v.begin(), v.end(), classcomp());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));    
    cout << endl;   

	getchar();
	return 0;
}

