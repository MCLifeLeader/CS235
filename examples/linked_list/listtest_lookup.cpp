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
  
  // --- Create list
  cout << "Creating list of 10 items..." << endl;
  for (int i = 0; i < 10; ++i)
    L.Insert(r.NextInt(1,100),i);

  // --- Test Get_Data
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << "Position " << i << ": " << L.Get_Data(i) << endl;
  cout << endl;

  // --- Test Lookup function
  while(1)
    {
      cout << "Enter number to search for (-1 to end): ";
      cin >> num;
      if (num < 0)
	break;
      pos = L.Lookup(num);
      if (pos < 0)
	cout << "Number not found..." << endl;
      else
	cout << num << " is found at position " << pos << endl;
    }
}

