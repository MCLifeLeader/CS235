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
  Queue Q(10);
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

  cout << "TEST FULL FUNCTION:" << endl;
  cout << "Add one more item to queue to over flow." << endl;
  cout << endl;
  Q.Insert(r.NextInt(1,100));
}
