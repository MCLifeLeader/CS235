/*************************************************************
 *
 *   NAME: Brother Cameron
 *
 *   FILE: test1.cpp
 *
 *   PURPOSE: This program tests the following member functions:
 *            constructor, destructor, Insert_Left, Insert_Right
 *            LChild, RChild, Get_Data, Level, Infix, Prefix,
 *            and Postfix.  The program does this
 *            by doing the following steps:
 *              1. Create a complete binary tree
 *              2. Do all 4 traversals of the tree
 *
 *************************************************************/
#include <iostream>
#include <math.h>
#include "tree.h"

using namespace std;

BTree *find_node(BTree *temp, int node);

main()
{
  BTree *queue[20];      // --- used to implement a queue
  int front = 0;         // --- index to front of queue
  int back = 0;          // --- index to back of queue
  BTree *root;           // --- pointer to root of heap
  BTree *temp;           // --- pointer used to traverse tree
  int node;              // --- current node number
  int parent_node;       // --- node number of parent node
  int mask = 1;          // --- used in finding lowest-level right most node
  int i;      
  int array[] = {23, 15, 21, 29, 26, 27, 3, 10, 0, 2};

  // --- Create complete binary tree with elements from array
   root = new BTree(array[0]);
   queue[back++] = root;
   node = 1;
   while (node < 10)
   {
      temp = queue[front++];
      temp->Insert_Left(array[node]);
      node++;

      if (node == 10)
         break;
      else
      {
         temp->Insert_Right(array[node]);
         node++;
         queue[back++] = temp->LChild();
         queue[back++] = temp->RChild();
      }
   }
  cout << "Tree in Level-Order Traversal" << endl;
  root->Level();
  cout << endl;

  cout << "Tree in Infix-Order Traversal" << endl;
  root->Infix();
  cout << endl;

  cout << "Tree in Prefix-Order Traversal" << endl;
  root->Prefix();
  cout << endl;

  cout << "Tree in Postfix-Order Traversal" << endl;
  root->Postfix();
  cout << endl;

}
