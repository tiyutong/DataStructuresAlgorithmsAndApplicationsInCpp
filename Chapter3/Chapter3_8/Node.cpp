#include "stdafx.h"
#include "Node.h"



ostream& operator<<(ostream& out, const Node& x)
{
   out << x.name << ' ' << x.exam1 << ' ' << x.exam2 
       << ' ' << x.exam3 << endl;
    return out;
}