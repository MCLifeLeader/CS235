/************************************************
 * Program:
 *    Homework 00, Sorting Example (page 365)
 *    Brother Cameron, CS 235
 * Author:
 *    Brother Cameron
 * Summary:
 *    Program to illustrate use of the standard
 *    sort algorithm.  Outputs a sorted list
 *    of ints.
 ************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main()
{
   int ints[] = {555,33,444,22,222,777,1,66};
   vector<int> v(ints,ints+8);

   sort(v.begin(), v.end());
   cout << "Sorted list of integer: " << endl;
   for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
   cout << endl;

}
   
