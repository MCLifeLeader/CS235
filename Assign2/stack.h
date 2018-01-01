/************************************************************
 *
 *  NAME: Brother Cameron
 * 
 *  PROGRAM: stack.h
 *
 *  PURPOSE: Class definition for a stack object
 *
 ************************************************************/
#ifndef _STACK_H
#define _STACK_H

using namespace std;
#include <iostream>

#define MAX_STACK 500

class Stack
{
   private:
     int top;
     int max_size;
     int *stack_items;
   public:
     Stack(int = 100);   //default constructor (stack size 100)
     int Top(void);
     void Push(int item);
     void Pop(void);
     int Empty(void);
     int Full(void);
     ~Stack();          // default destructor
};
#endif






