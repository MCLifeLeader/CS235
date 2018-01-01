/* This program demonstrates how often a class' constructor,
 * destructor, and copy constructor can get called automatically
 * by the compiler.  It uses the Stack class from Figure 8.6 but
 * with output statements inserted into the constructor, destructor,
 * and copy constructor to trace when they are called.
 *******************************************************************/

#include "stack.h"
#include <iostream>
using namespace std;

/* Function to print a stack.
 * Receives: Stack<int> st as a value parameter
 * Output:   The contents of the stack
 ***********************************************/
void Print (Stack<int> st)
{
  st.display(cout);
}

int main()
{
  int numElements;
  cout << "Enter stack capacity: ";
  cin >> numElements;

  cout << "**A**\n";
  Stack<int> s(numElements);

  cout << "**B**\n";
  for (int i = 1; i <= 5; i++)
  {
    cout << "**C**\n";
    s.Push(i);
  }

  cout << "**D**\n";
  Stack<int> t = s;

  cout << "**E**\n";
  Print(t);

  cout << "**F**\n";
  Stack<int> u;

  cout << "**G**\n";
  u = t;

  cout << "**H**\n";
  Print(u);

  cout << "**I**\n";
}
