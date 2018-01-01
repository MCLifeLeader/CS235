/************************************************
 * Program:
 *    Homework 0, Vector 2 Example
 *    Cameron, CS 235
 * Author:
 *    Brother Cameron
 * Summary:
 *    Example of iterators with vectors
 ************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

main()
{
  vector<int> v;
  vector<int>::iterator p1;
  vector<int>::iterator p2;
  v.push_back(9);
  v.push_back(8);
  v.push_back(7);

  p1 = v.begin();
  p2 = v.end();

  cout << *p1 << ' ' << *(p2-1) << endl;
  p1 += 3;
  p2 -= 2;
  cout << *p1 << ' ' << *(p2-1) << endl;
  p1--;
  ++p2;
  cout << *p1 << ' ' << *(p2-1) << endl;
  cout << p1[1] << ' ' << p1[-1] << endl;
  for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    cout << *i << ' ';
  cout << endl;
  
}

