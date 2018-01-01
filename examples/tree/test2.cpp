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
using namespace std;
#include <iostream>
#include <math.h>
#include "tree.h"
#include "random.h"

#define   LOW       1
#define   HIGH      100
#define   NUMNODES  15

main()
{
  BTree *node[NUMNODES];
  Random r; 

  for (int i = 0; i < NUMNODES; ++i)
      node[i] = new BTree(r.NextInt(LOW,HIGH));

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
