/************************************************
 * Program:
 *    Homework 0, Vector 2 Example
 *    Cameron, CS 235
 * Author:
 *    Brother Cameron
 * Summary:
 *    Example of reverse iterators with vectors
 ************************************************/
#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector<int> v;
  vector<int>::reverse_iterator p1;
  v.push_back(9);
  v.push_back(8);
  v.push_back(7);

  for (p1 = v.rbegin(); p1 != v.rend(); p1++)
    cout << *p1 << ' ';
  cout << endl;
}

