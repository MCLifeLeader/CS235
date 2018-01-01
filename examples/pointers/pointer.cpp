/*****************************************************************
 *
 *   File: pointer1.cpp
 *
 *   Author: Brother Cameron, 10/11/2001
 *
 *   Purpose: Example of pointer usage
 *
 *****************************************************************/
using namespace std;
#include <iostream>

main (void)
{
  int  a = 6;
  int  b = 2;
  int  c = 0;
  int *p = &b;
  int *q = NULL;
  int *r = NULL;
  
  q = p;      // --- address stored in p is copied to q
  r = &c;     // --- address of c is stored in r
  
  p  = &a;    // --- address of a is stored in p
  *q = 8;     // --- data pointed to by q will get an 8
  c  = *q;    // --- variable c will get copy of data pointed to by q
  
  *r = *p;    // --- data pointed to by p will be copied to location pointed to 
              // --- by r
  
  *r = a + *q + *r;
  
  cout << "p -> a" << endl;
  cout << "   p: " << p << endl;
  cout << "  &a: " << &a << endl;
  cout << "  *p: " << *p << endl;
  cout << "   a: " << a << endl;

  cout << "q -> b" << endl;
  cout << "   q: " << q << endl;
  cout << "  &b: " << &b << endl;
  cout << "  *q: " << *q << endl;
  cout << "   b: " << b << endl;

  cout << "r -> c" << endl;
  cout << "   r: " << r << endl;
  cout << "  &c: " << &c << endl;
  cout << "  *r: " << *r << endl;
  cout << "   c: " << c << endl;
}	// main
