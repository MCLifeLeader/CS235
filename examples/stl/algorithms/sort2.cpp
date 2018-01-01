/************************************************
 * Program:
 *    Homework 00, Sorting Example 2 (page 365)
 *    Brother Cameron, CS 235
 * Author:
 *    Brother Cameron
 * Summary:
 *    Program to illustrate use of the standard
 *    sort algorithm.  Outputs a sorted list
 *    of doubles.
 ************************************************/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

main()
{
   double dubs[] = {55.5, 3.3, 44.4, 2.2, 22.2, 77.7, 0.1};
   deque<double> d(dubs,dubs+7);

   sort(d.begin(), d.end());
   cout << "Sorted list of doubles: " << endl;
   for (int i = 0; i < d.size(); i++)
      cout << d[i] << " ";
   cout << endl;

}
   
