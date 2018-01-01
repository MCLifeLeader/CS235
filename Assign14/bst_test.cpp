/********************************************************************************
 *
 *  File: bst_test.cpp
 *
 *  Author: Brother Cameron, 10/23/2001
 *
 *  Purpose: This program tests the member functions from the BST class.
 *           The program generates 20 random numbers between 1 nd 10 and
 *           inserts them into the BST.  It then prints out the numbers in
 *           infix order.  The program then enters a loop where the user
 *           is then asked to input one of the numbers in the tree.  The node
 *           with this number will then be deleted and the tree will be printed
 *           in infix order.  A -1 ends the loop.
 *
 *  Limitations: This program does not test the BST Search function.  Its is
 *               assumed that the Insert function uses the Search function
 *               to find a place to insert a new node.
 *
 *****************************************************************************/
#include "bst.h"
#include "tree.h"
#include <iostream>
#include <fstream>

using namespace std;
main()
{
  BST b;       // --- a binary search tree object
  int number;
  const int NUM = 25;
  int i;
  ifstream infile("assign14.in");

  // --- Create a BST with NUM random numbers between HIGH and LOW
  for (i = 0; i < NUM; i++)
  {
    infile >> number;
    b.Insert(number);
  }

  // --- Print out number in infix order
  b.BST_Infix();
  cout << endl;

  // --- Delete a node with one children
  b.Delete(3);
  b.BST_Infix();
  cout << endl;

  // --- Delete a node with no children
  b.Delete(17);
  b.BST_Infix();
  cout << endl;

  // --- Delete a node with two children
  b.Delete(58);
  b.BST_Infix();
  cout << endl;

}
