/*******************************************************************
 *
 *     FILE: list.h
 *
 *  PURPOSE: Contains the class definition of a Node and a List
 *
 *******************************************************************/
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
 private:
  int data;                // --- data in each node
  Node *next;              // --- pointer to next node

 public:
  Node();                  // --- Creates empty node
  Node *get_next();        // --- returns next pointer of a node
  int get_data();          // --- returns data of a node
  void set_data(int item); // --- stores item in data member of current node
  void set_next(Node *node); // --- sets next to point to node
};

class List
{
 private:
  int num_items;
  Node *list_items;
  
 public:
  List();
  void Insert(int item, int pos);
  void Delete(int pos);
  int Lookup(int item);
  int Get_Data(int pos);
  int Empty(void);
  int get_numitems(void);
};
#endif


