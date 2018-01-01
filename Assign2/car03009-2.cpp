/***********************************************************************
* Program:
*    Assignment 02, Stack
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create and implement a stack
***********************************************************************/

#include <iostream>
#include "stack.h"

using namespace std;

/*************************************************************************
*  Purpose:
*     Overloaded default constructor
**************************************************************************/
Stack::Stack( int iStackSize )
{
   int iCount;
   top = -1;

   // Prevent overloading of the stack
   if ( iStackSize <= MAX_STACK )
   {
      max_size = iStackSize;
      stack_items = new int [ iStackSize ];

      // initialize the stack to a null value
      for ( iCount = 0; iCount < iStackSize; iCount++ )
      {
         stack_items[ iCount ] = 0;
      }
   }
}

/*************************************************************************
*  Purpose:
*     Default destructor to set error status on variables
**************************************************************************/
Stack::~Stack()
{
   // set the stack variables to the error status
   top = max_size = -1;
}

/*************************************************************************
*  Purpose:
*     Return the status of the stack if it is full
**************************************************************************/
int Stack::Full()
{
   if ( ( top == max_size ) && ( top <= MAX_STACK ) )
      return ( 1 );
   else
      return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Return the status of the stack if it is empty
**************************************************************************/
int Stack::Empty()
{
   if ( top == -1 )
      return ( 1 );
   else
      return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Return the value of the top element in the stack
**************************************************************************/
int Stack::Top()
{
   if ( !Empty() )
   {
      return ( stack_items[ top ] );
   }
   else
   {
      cout << "ERROR: Stack Empty" << endl;
      exit( 1 );
   }
}

/*************************************************************************
*  Purpose:
*     Push an item onto the stack
**************************************************************************/
void Stack::Push( int iItem )
{
   if ( ( top < max_size - 1 ) && ( top < MAX_STACK ) )
   {
      stack_items[ ++top ] = iItem;
   }
   else
   {
      cout << "ERROR: Stack Overflow" << endl;
      exit( 2 );
   }
}

/*************************************************************************
*  Purpose:
*     pop an item off of the stack
**************************************************************************/
void Stack::Pop()
{
   if ( top >= 0 )
   {
      stack_items[ top-- ] = 0;
   }
   else
   {
      cout << "ERROR: Stack Underflow" << endl;
      exit( 3 );
   }
}
