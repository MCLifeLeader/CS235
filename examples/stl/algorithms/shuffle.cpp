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
   int ints[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   vector<int> v(ints,ints+15);

   random_shuffle(v.begin(),v.end());
   cout << "Shuffled list of integers: " << endl;
   for (int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
   cout << endl;

}
   
