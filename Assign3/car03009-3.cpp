/***********************************************************************
* Program:
*    Assignment 03, Stack with RPN and Assembly
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create and implement a Stack then actually use it.
*    Input: An Infix expression
*    Output: The RPN expression, modified as simple Assembly
***********************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cassert>

using namespace std;

#define MAXSTACK 500

/************************************************************
*
*  NAME: Brother Cameron
*  Modified: Brother Michael Carey
*
*  PURPOSE: 
*     Class definition for a stack object
************************************************************/
class Stack
{
   private:
      int topPtr;
      int maxSize;
      char *stackItems;
   public:
      Stack(int = 100);   //default constructor (stack size 100)
      char top(void);
      void push(char item);
      void pop(void);
      bool empty(void);
      bool full(void);
      ~Stack();          // default destructor
};

// function to return the RPN from infix
string infixToRPN( string exp );
// function to return the Assembly from RPN
string rpnToAssembly( string exp );

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   string exp; // infix expression
   
   ifstream ifile;

   if ( argc > 1 )
   {
      ifile.open( argv[ 1 ] );

      if ( ifile.is_open() )
      {
         for ( ; ifile; )
         {
            getline( ifile, exp );
            
            if ( exp.length() > 1 )
               cout << rpnToAssembly( infixToRPN( exp ) ) << endl;
         }
      }
      else
      {
         cout << "File " << argv[ 1 ] << " failed to open" << endl;
         return ( 1 );
      }
   }

   ifile.close();
   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Convert an infix expression into RPN
**************************************************************************/
string infixToRPN( string exp )
{
   unsigned int i;
   char token;                // character in exp
   char topToken;             // token on top of opStack
   Stack opStack;             // stack of operators
   string rpnExp;             // RPN string
   const string BLANK = " ";  // Blank

   for ( i = 0; i < exp.length(); i++ )
   {
      token = exp[ i ];
      switch ( token )
      {
         case ' ':
            break;     // do nothing
         case '(':
            opStack.push( token );
            break;
         case ')':
            for ( ; ; )
            {
               assert ( !opStack.empty() );
               topToken = opStack.top();
               opStack.pop();
               if ( topToken == '(' ) 
                  break;

               rpnExp.append( BLANK + topToken );
            }
            break;
         case '+':
         case '-':
         case '*':
         case '/':
            for ( ; ; )
            {
               if ( opStack.empty() || opStack.top() == '(' || 
                  ( token == '*' || token == '/') && 
                  ( opStack.top() == '+' || opStack.top() == '-' ) )
               {
                  opStack.push( token );
                  break;
               }
               else
               {
                  topToken = opStack.top();
                  opStack.pop();
                  rpnExp.append( BLANK + topToken );
               }
            }
            break;
         default: 
            rpnExp.append( BLANK + token );
      }
   }

   for ( ; ; )
   {
      if ( opStack.empty())
         break;

      topToken = opStack.top();
      opStack.pop();
      if ( topToken != '(' )
         rpnExp.append( BLANK + topToken );
      else
      {
         cout << " *** Error in infix expression *** \n";
         break;
      }
   }

   return ( rpnExp );
}

/*************************************************************************
*  Purpose:
*     Convert the RPN into simple Assembly
*
*     LD  A   Places operand A into the register.
*     ST  A   Places the contents of the register into the variable A.
*     AD  A   Adds the contents of the variable A to the register and 
*              stores the result in the register.
*     SB  A   Subtracts the contents of the variable from the register 
*              and stores the result in the register.
*     ML  A   Multiplies the contents of the register by the variable A 
*              and stores the result in the register.
*     DV  A   Divides the contents of the register by the variable A and 
*              stores the result into the register.
**************************************************************************/
string rpnToAssembly( string exp )
{
   unsigned int i;
   char mem;
   char token;                // character in exp
   char topToken1[2];         // token on top of opStack
   char topToken2[2];         // token on top of opStack
   Stack opStack;             // stack of operators
   string asmOut;
   const string BLANK = "  ";  // Blank

   mem = '0';
   topToken1[ 1 ] = '\0';
   topToken2[ 1 ] = '\0';

   for ( i = 0; i < exp.length(); i++ )
   {
      token = exp[ i ];
      switch ( token )
      {
         case ' ':
            break;     // do nothing
         case '+':
         case '-':
         case '*':
         case '/':
            if ( !opStack.empty() )
            {
               // LD
               topToken1[0] = opStack.top();
               opStack.pop();
               topToken2[0] = opStack.top();
               opStack.pop();

               asmOut += "LD";
               asmOut += BLANK;

               if ( atoi( topToken2 ) >= 1 && atoi( topToken2 ) <= 9 )
               {
                  asmOut += "TEMP";
                  asmOut += topToken2;
               }
               else
               {
                  asmOut += topToken2;
               }
               asmOut += "\n";
               
               // Operator
               switch ( token )
               {
                  case '+':   // AD
                     asmOut.append( "AD" );
                     break;
                  case '-':   // SB
                     asmOut.append( "SB" );
                     break;
                  case '*':   // ML
                     asmOut.append( "ML" );
                     break;
                  case '/':   // DV
                     asmOut.append( "DV" );
                     break;
               }

               asmOut += BLANK;

               if ( atoi( topToken1 ) >= 1 && atoi( topToken1 ) <= 9 )
               {
                  asmOut += "TEMP";
                  asmOut += topToken1;
               }
               else
               {
                  asmOut += topToken1;
               }

               asmOut += "\n";
               mem++;
               opStack.push( mem );
               topToken1[0] = opStack.top();

               // ST
               asmOut += "ST  TEMP";
               asmOut += topToken1;
               asmOut += "\n";
            }
            else
            {
               cout << "empty Stack" << endl;
               exit( 1 );
            }
            break;
         default:
            opStack.push( token );
      }
   }

   return ( asmOut );
}

/*************************************************************************
*  Purpose:
*     Overloaded default constructor
**************************************************************************/
Stack::Stack( int iStackSize )
{
   int iCount;
   topPtr = -1;

   // Prevent overloading of the stack
   if ( iStackSize <= MAXSTACK )
   {
      maxSize = iStackSize;
      stackItems = new char [ iStackSize ];

      // initialize the stack to a null value
      for ( iCount = 0; iCount < iStackSize; iCount++ )
      {
         stackItems[ iCount ] = 0;
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
   topPtr = maxSize = -1;
}

/*************************************************************************
*  Purpose:
*     Return the status of the stack if it is full
**************************************************************************/
bool Stack::full()
{
   if ( ( topPtr == maxSize ) && ( topPtr <= MAXSTACK ) )
      return ( true );
   else
      return ( false );
}

/*************************************************************************
*  Purpose:
*     Return the status of the stack if it is empty
**************************************************************************/
bool Stack::empty()
{
   if ( topPtr == -1 )
      return ( true );
   else
      return ( false );
}

/*************************************************************************
*  Purpose:
*     Return the value of the top element in the stack
**************************************************************************/
char Stack::top()
{
   if ( !empty() )
   {
      return ( stackItems[ topPtr ] );
   }
   else
   {
      cout << "ERROR: Stack empty" << endl;
      exit( 1 );
   }
}

/*************************************************************************
*  Purpose:
*     push an item onto the stack
**************************************************************************/
void Stack::push( char iItem )
{
   if ( ( topPtr < maxSize - 1 ) && ( topPtr < MAXSTACK ) )
   {
      stackItems[ ++topPtr ] = iItem;
   }
   else
   {
      cout << "ERROR: Stack Overflow" << endl;

      for ( ; topPtr; topPtr-- )
         cout << stackItems[ topPtr ] << endl;

      exit( 2 );
   }
}

/*************************************************************************
*  Purpose:
*     pop an item off of the stack
**************************************************************************/
void Stack::pop()
{
   if ( topPtr >= 0 )
   {
      stackItems[ topPtr-- ] = 0;
   }
   else
   {
      cout << "ERROR: Stack Underflow" << endl;
      exit( 3 );
   }
}
