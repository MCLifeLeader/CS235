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
#include <algorithm>
using namespace std;

main()
{
   int ints[] = {555,33,444,22,222,777,1,66};

   sort(ints, ints+8);
   cout << "Sorted list of integer: " << endl;
   for (int i = 0; i < 8; i++)
      cout << ints[i] << " ";
   cout << endl;

}
   
