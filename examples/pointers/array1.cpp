/*****************************************************
 *
 *  PROGRAM: array1.cpp
 *
 *  AUTHOR: Brother Cameron, 5/10/01
 *
 *  PURPOSE: Demonstrate that array name is pointer 
 *           to first element of an array
 *
 ******************************************************/
using namespace std;
#include <iostream>

main()
{
  int a[5] = {1,2,3,4,5};
  int *b;

  cout << "Address of a[0]: " << &a[0] << endl;
  cout << "Name as pointer: " << a << endl;
  b = a;
  cout << b << endl;
}
