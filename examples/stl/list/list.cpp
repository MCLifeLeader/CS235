#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//--- Overload output operator for list<T>
template <typename T>
ostream & operator<<(ostream & out, list<T> l)
{
  for (list<T>::iterator i = l.begin(); i != l.end(); i++)
    out << *i << "  ";
  return out;
}

int main()
{
  list<int> l,
            l1(4, 111),
            l2(6);

  cout << "l:  " << l << "  size = " << l.size() << endl;
  cout << "l1: " << l1 << "  size = " << l1.size() << endl;
  cout << "l2: " << l2 << "  size = " << l2.size() << endl;

  // Construct l3 from an array
  //===========================
  int b[] = {2, 22, 222,2222};
  list<int> l3(b, b+4);
  cout << "l3: " << l3 << endl;

  // Assignment
  //===========
  cout << "\nAssignments l = l3 and  l2 = l3:" << endl;
  l = l3;
  l2 = l3;
  cout << "l = " << l << "  size = " << l.size() << endl;
  cout << "l2 = " << l2 << "  size = " << l2.size() << endl;


  // Ways to insert into a list
  //===========================
  cout << "\nInserts in l1:\n";
  list<int>::iterator i;
  i = l1.begin();
  i++; i++;
  l1.insert(i, 66666);
  cout << l1 << endl;

  l1.insert(i, 3, 555);   // error in CodeWarrior 4.0
  cout << l1 << endl;

  l1.insert(i, b, b+3);
  cout << l1 << endl;

  l1.push_back(888);
  l1.push_front(111);
  cout << l1 << endl;

  // Ways to delete from a list
  //===========================
  cout << "\nErases in l1:\n";
  i = find(l1.begin(), l1.end(), 66666);  // find is an algorithm
  if (i != l1.end())
    {
      cout << "66666 found -- will erase it\n";
      l1.erase(i);
    }
  else
    cout << "66666 not found\n";
  cout << l1 << endl;

  i = l1.begin(); i++;
  list<int>::iterator j = l1.end();
  --j; --j; i = --j; i --; i--;
  l1.erase(i,j);
  cout << l1 << endl;

  l1.pop_back();
  l1.pop_front();
  cout << l1 << endl;

  // Reversing a list
  //=================
  cout << "\nReverse l3:\n";
  l3.reverse();
  cout << l3 << endl;

  // Sorting a list
  //===============
  cout << "\nSort l1:\n";
  l1.sort();
  cout << l1 << endl;

  // Merging two lists
  //==================
  cout << "\nSort l3 and then merge l1 and l3:\n";
  l3.sort();l1.merge(l3);
  cout << "l1: " << l1 << endl;
  cout << "l3: " << l3 << endl;

  // Splicing a list into another list
  //==================================
  cout << "\nSplice l2 into l at second position:\n";
  i=l.begin(); i++;
  l.splice(i, l2);
  cout << "l: " << l << endl;
  cout << "l2: " << l2 << endl;

  // Global removal of a value
  //==========================
  cout << "\nRemove 22s from l:\n";
  l.remove(22);
  cout << l << endl;

  // Eliminating duplicates
  //=======================
  cout << "\nUnique applied to l1:\n";
  l1.unique();
  cout << l1 << endl;

}
