#pragma once
#include <iostream>
using namespace std;

template <class T> class Chain;

class Node {
   friend ostream& operator<<(ostream&, const Node &);
   friend void BinSort(Chain<Node>&, int);
   friend int F1(Node&);
   friend int F2(Node&);
   friend int F3(Node&);
   friend int _tmain(int argc, _TCHAR* argv[]);
   public:
      operator int() const {return exam1;}
   private:
      int exam1, exam2, exam3;
      int name;
};