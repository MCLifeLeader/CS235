/*************************************************************
 *
 *  NAME: Brother Cameron
 *
 *  FILE: tree.h
 *
 *  PURPOSE: This file defines the Binary Tree Class
 *
 ************************************************************/
#ifndef _TREE_H
#define _TREE_H
using namespace std;
#include <iostream>

class BTree
{
 private:
  int data;          // --- data stored in node of tree
  BTree *left;       // --- pointer to left subtree
  BTree *right;      // --- pointer to right subtree
  BTree *parent;     // --- pointer to the parent node;

 public:
  BTree(int = 0);  
  ~BTree(void);
  void Insert_Left(int item);
  void Insert_Right(int item);
  BTree *LChild(void);  
  BTree *RChild(void);
  BTree *Parent(void);
  int Get_Data(void);
  void Set_Data(int item);
  void Set_Left(BTree *tree);
  void Set_Right(BTree *tree);
  void Infix(void);
  void Prefix(void);
  void Postfix(void);
  void Level(void);
};
#endif
