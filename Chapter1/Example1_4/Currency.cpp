#include "stdafx.h"
#include "Currency.h"
#include <iostream>
using namespace std;

Currency::Currency(sign s , unsigned long d, unsigned int c)
{
	if(c > 99)
	{
		cerr << "Cents should be < 100" << endl;
		exit(1);
	}
	sgn = s;
	dollars = d;
	cents = c;
}


Currency::~Currency(void)
{
}

bool Currency::Set(sign s, unsigned long d, unsigned int c)
{
	if(c > 99)
	{
		return false;
	}
	sgn = s;
	dollars = d;
	cents = c;
	
	return true;
}

bool Currency::Set(float a)
{
	if(a < 0)
	{
		sgn = minus;
		a = -a;
	}
	else
	{
		sgn = plus;
	}
	dollars = a;
	cents = (a + 0.005 - dollars) * 100;

	return true;
}

Currency Currency::Add(const Currency& x) const
{
	long a1, a2, a3;
	Currency ans;
	a1 = dollars * 100 + cents;
	if(sgn == minus)
	{
		a1 = - a1;
	}

	a2 = x.dollars * 100 + cents;
	if(x.sgn == minus)
	{
		a2 = -a2;
	}
	a3 = a1 + a2;

	if( a3 < 0)
	{
		ans.sgn = minus;
		a3 = -a3;
	}
	else
	{
		ans.sgn = plus;
	}
	ans.dollars = a3 / 100;
	ans.cents = a3 - ans.dollars * 100;

	return ans;
}

Currency& Currency::Increment(const Currency& x)
{
	*this = Add(x);
	return *this;
}

void Currency::Output(ostream& out)const
{
	if(sgn == minus)
	{
		out << "-";
	}
	out << '$' << dollars << '.';
	if(cents < 10)
	{
		out << "0";
	}
	out << cents;
} 


ostream& operator<<(ostream& out, const Currency& x)
{
	x.Output(out);

	return out;
}