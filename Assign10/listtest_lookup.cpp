/****************************************************************
 *
 *  NAME: Brother Cameron
 *
 *  FILE: listtest_lookup.cpp
 *
 *  PURPOSE: This program tests the Lookup function of the 
 *           list class member functions.
 *
 ****************************************************************/
#include "list.h"
#include <iostream>
#include <fstream>

using namespace std;

main()
{
  List L;
  int  num;
  int  pos;
  int  n;
  ifstream infile("assign10_test3.in");
  
  // --- Create list
  for (int i = 0; i < 10; ++i)
  {
    infile >> num;
    L.Insert(num,i);
  }

  // --- Test Get_Data
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << "Position " << i << ": " << L.Get_Data(i) << endl;
  cout << endl;

  // --- Test Lookup function
  num = 13;
  pos = L.Lookup(num);
  cout << "Number " << num << " is in position " << pos << endl;

  num = 22;
  pos = L.Lookup(num);
  cout << "Number " << num << " is in position " << pos << endl;

  num = 25;
  pos = L.Lookup(num);
  cout << "Number " << num << " is in position " << pos << endl;

  num = 30;
  pos = L.Lookup(num);
  cout << "Number " << num << " is in position " << pos << endl;
  
}

