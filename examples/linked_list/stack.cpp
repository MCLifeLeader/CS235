/************************************************************************
 *
 *  File: stack.cpp
 *
 *  Author: Brother Cameron, 10/16/2001
 *
 *  Purpose: Implement the stack as a linked list
 *
 ************************************************************************/
using namespace std;
#include <iostream>
#include "stack.h"

Stack::Stack()
{
  num_items = 0;
  stack_items = NULL;
}

void Stack::Push(int item)
{
  Node *ptr;
  
  // --- Create new item for stack (i.e. a new Node for LL)
  ptr = new Node;

  // --- Put data inside of Node
  ptr->set_data(item);

  // --- Set Node's next field to point to same thing as stack_items
  // --- which is the top of the stack
  ptr->set_next(stack_items);

  // --- move stack_items to Node which is the new top item on stack
  stack_items = ptr;
}

int Stack::Pop(void)
{
  Node *ptr;
  int item;

  // --- have ptr point to top item on stack
  ptr = stack_items;

  // --- retrieve data time from top of stack
  item = ptr->get_data();

  // --- move stack pointer to reflect new top of stack
  stack_items = ptr->get_next();

  // --- delete old top of stack item (requires destructor)
  delete ptr;

  // --- send item back
  return(item);
}






