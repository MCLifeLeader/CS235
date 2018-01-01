/*************************************************************
 *
 *   NAME: Brother Cameron
 *
 *   FILE: testque.cpp
 *
 *   PURPOSE: This program test the queue functions to see
 *            if they work correctly
 *
 *************************************************************/
using namespace std;
#include <iostream>
#include <cstdlib>

#include "queue.h"
#include "random.h"

main()
{
  Queue Q(11);
  int num;
  int i;
  Random r;

  cout << "TEST INSERT FUNCTION" << endl;
  cout << "Inserting the following numbers into the queue: " << endl;
  for (i = 0; i < 10; ++i)
    {
      num = r.NextInt(1,100);
      cout << num << " ";
      Q.Insert(num);
    }
  cout << endl;

  cout << "TEST REMOVE FUNCTION: " << endl;
  cout << "Removing the following numbers from the queue: " << endl;
  for (i = 0; i < 10; ++i)
    {
      num = Q.Remove();
      cout << num << " ";
    }
  cout << endl;
  cout << "TEST EMPTY FUNCTION: " << endl;
  cout << "Attempt to remove an item from an empty queue: " << endl;
  cout << "Program should fail and exit" << endl;
  num = Q.Remove();
}
