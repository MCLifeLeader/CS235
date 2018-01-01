/************************************************************************
 *
 *  File: sort_example.cpp
 *
 *  Author: Brother Cameron, 11/1/2001
 *
 *  Purpose: Main program to implement sorts.
 *
 ************************************************************************/
#include <iostream.h>
#include <iomanip.h>
#include "random.h"

void mergesort(int a[], int low, int high);

main()
{
  const int MAX = 100;
  int i;
  int data[MAX];
  Random r;

  // ---- Generate data and print out on screen
  cout << "Unsorted data: " << endl;
  for (i = 0; i < MAX; ++i)
    {
      data[i] = r.NextInt(1,50);
      cout << data[i] << " ";
    }
  cout << endl << endl;

  mergesort(data,0,MAX-1);

  // --- Print out data in sorted order
  for (i = 0; i < MAX; ++i)
    cout << data[i] << " ";
  cout << endl;
}
