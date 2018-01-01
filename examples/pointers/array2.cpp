/*****************************************************
 *
 *  PROGRAM: array2.cpp
 *
 *  AUTHOR: Brother Cameron, 5/10/01
 *
 *  PURPOSE: Demonstrate how to use pointer and array indices to
 *           access an array
 *
 ******************************************************/
using namespace std;
#include <iostream>

main()
{
  int a[5] = {2,4,6,8,22};
  int *aptr = &a[0];

  cout << "Element 0 as array index: " << a[0] << endl;
  cout << "Element 0 as pointer    : " << *a << endl;
  cout << "Element 0 from pointer  : " << *aptr << endl;
}
