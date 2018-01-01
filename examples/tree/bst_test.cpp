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
 *******************************************************************************/
using namespace std;
#include "bst.h"
#include "tree.h"
#include "random.h"
#include <iostream>

main()
{
  BST b;       // --- a binary search tree object
  Random r;    // --- a random number generator object
  int number;
  const int LOW = 1;
  const int HIGH = 10;
  const int NUM = 20;
  int i;

  // --- Create a BST with NUM random numbers between HIGH and LOW
  for (i = 0; i < NUM; i++)
    b.Insert(r.NextInt(LOW,HIGH));

  // --- Print out number in infix order
  b.BST_Infix();

  // --- Allow user to enter a number from the BST.
  // --- The program will then delete the number from the BST.
  // --- The program will then reprint out the BST in infix order
  // --- This will continue to repeat until a -1 is entered.
  while(1)
    {
      cout << "Enter a number from the BST: ";
      cin >> number;
      if (number == -1)
	break;
      b.Delete(number);
      b.BST_Infix();
    }
}
