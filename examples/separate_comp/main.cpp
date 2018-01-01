#include "mth.h"
#include <iostream>
using namespace std;

main()
{
  Mth m1;
  int temp1;
  int temp2;

  cout << "Enter first number: ";
  cin >> temp1;
  cout << "Enter second number: ";
  cin >> temp2;
  
  m1.set_op1(temp1);
  m1.set_op2(temp2);

  cout << "Results: " << endl;
  m1.Add();
  cout << m1.get_op1() << " + " << m1.get_op2() << " = " << m1.get_result() << endl;
  m1.Sub();
  cout << m1.get_op1() << " - " << m1.get_op2() << " = " << m1.get_result() << endl;
  m1.Mult();
  cout << m1.get_op1() << " * " << m1.get_op2() << " = " << m1.get_result() << endl;
  m1.Div();
  cout << m1.get_op1() << " / " << m1.get_op2() << " = " << m1.get_result() << endl;
  cout << endl;
}

  
