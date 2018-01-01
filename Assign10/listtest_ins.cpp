/****************************************************************
 *
 *  NAME: Brother Cameron
 *
 *  FILE: list_test.cpp
 *
 *  PURPOSE: This program tests the list class member functions
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
  ifstream infile("assign10_test2.in");

  infile >> num;
  cout << "Inserting " << num << " at beginning of an empty list..." << endl;
  L.Insert(num,0);

  infile >> num;
  cout << "Inserting " << num << " at beginning of an existing list..." << endl;
  L.Insert(num,0);

  infile >> num;
  cout << "Inserting " << num << " at end of an existing list..." << endl;
  L.Insert(num,5);

  infile >> num;
  cout << "Inserting " << num << " into the middle of an existing list..." << endl;
  L.Insert(num,1);


  
  // --- Test Get_Data
  cout << "Testing Get_Data..." << endl;
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << "Postion " << i << " contains " << L.Get_Data(i) << endl;
}

