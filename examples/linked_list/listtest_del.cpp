/****************************************************************
 *
 *  NAME: Brother Cameron
 *
 *  FILE: listtest_del.cpp
 *
 *  PURPOSE: This program tests the Delete function of the 
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
    cout << L.Get_Data(i) << " ";
  cout << endl;

  // --- Test Delete function
  cout << "Deleting 10th item in list..." << endl;
  L.Delete(9);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;

  cout << "Deleting 20th item in list (should delete 9th item)..." << endl;
  L.Delete(20);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;

  cout << "Deleting 1st item in list..." << endl;
  L.Delete(0);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;

  cout << "Deleting 3rd item in list..." << endl;
  L.Delete(2);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;

  cout << "Deleting all but one item in list..." << endl;
  L.Delete(1);
  L.Delete(1);
  L.Delete(1);
  L.Delete(1);
  L.Delete(1);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;

  cout << "Deleting one item from list..." << endl;
  L.Delete(0);
  n = L.get_numitems();
  for (int i = 0; i < n; ++i)
    cout << L.Get_Data(i) << " ";
  cout << endl;
}

