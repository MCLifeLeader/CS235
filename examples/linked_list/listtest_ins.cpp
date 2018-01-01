/****************************************************************
 *
 *  NAME: Brother Cameron
 *
 *  FILE: list_test.cpp
 *
 *  PURPOSE: This program tests the list class member functions
 *
 ****************************************************************/
using namespace std;
#include "list.h"
#include "random.h"
#include <iostream>

main()
{
  List L;
  int  num;
  int  pos;
  int  n;
  Random r;

  num = r.NextInt(1,100);
  cout << "Inserting " << num << " at beginning of an empty list..." << endl;
  L.Insert(num,0);
  num = r.NextInt(1,100);
  cout << "Inserting " << num << " at beginning of an existing list..." << endl;
  L.Insert(num,0);
  num = r.NextInt(1,100);
  cout << "Inserting " << num << " at end of an existing list..." << endl;
  L.Insert(num,5);
  num = r.NextInt(1,100);
  cout << "Inserting " << num << " into the middle of an existing list..." << endl;
  L.Insert(num,1);


  
  // --- Test Get_Data
  cout << "Testing Get_Data..." << endl;
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << "Postion " << i << " contains " << L.Get_Data(i) << endl;
}

