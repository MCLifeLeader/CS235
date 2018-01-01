/*************************************************************
 *
 *   NAME: Brother Cameron
 *
 *   FILE: test2.cpp
 *
 *   PURPOSE: This program tests the Set_Right and Set_Left
 *            functions of the binary tree class.
 *
 *************************************************************/
#include <iostream>
#include <math.h>
#include "tree.h"

using namespace std;

main()
{
  BTree *node[15];
  int array[] = {23, 15, 21, 29, 26, 27, 3, 10, 0, 2, 20, 9, 14, 22, 1};

  for (int i = 0; i < 15; ++i)
      node[i] = new BTree(array[i]);

  for (int i = 6; i >= 0; i--)
    {
      node[i]->Set_Left(node[i*2+1]);
      node[i]->Set_Right(node[i*2+2]);
    }

  cout << "Tree in Level-Order Traversal" << endl;
  node[0]->Level();
  cout << endl;

  cout << "Tree in Infix-Order Traversal" << endl;
  node[0]->Infix();
  cout << endl;

  cout << "Tree in Prefix-Order Traversal" << endl;
  node[0]->Prefix();
  cout << endl;

  cout << "Tree in Postfix-Order Traversal" << endl;
  node[0]->Postfix();
  cout << endl;

}
