/*************************************************************
 *
 *   File: eval2.cpp
 *
 *   Author: Brother Cameron
 *
 *   Purpose: Evaluates a postfix expression
 *
 *************************************************************/
using namespace std;

#include <iostream>
#include <cctype>
#include <math.h>
#include <cstdlib>
 
#include "stack.h"

int eval(char expr[]);
int oper(char symb, int op1, int op2);

main()
{
  char expr[80];
  int position = 0;

  cout << "Enter expression: ";
  cin.getline(expr,80);
  cout << eval(expr) << endl;
}

// --- eval function to evaluate postifix expression
int eval(char expr[])
{
  int position;
  int opnd1;
  int opnd2;
  int value;
  Stack S(100);

  for (position = 0; expr[position] != '\0'; position++)
    {
      if (isspace(expr[position]))  // --- ignore white space
	continue;
      else 
	if (isdigit(expr[position]))
	    // -- converts character to integer and pushes on stack
	  S.Push(expr[position]-'0');
	else
	  {
	    opnd2 = S.Top();
	    S.Pop();
	    opnd1 = S.Top();
	    S.Pop();
	    value = oper(expr[position], opnd1, opnd2);
	    S.Push(value);
	  }
    }
  value = S.Top();
  S.Pop();
  return(value);
}

// --- Function to evaluate op1 and op2 based on symb
int oper(char symb, int op1, int op2)
{
  switch(symb)
    {
    case '+': return(op1+op2);
    case '-': return(op1-op2);
    case '*': return(op1*op2);
    case '/': return(op1/op2);
    case '^': return((int)pow((double)op1,(double)op2));
    default:
      cout << "Illegal operation" << endl;
      exit(1);
    }
}










