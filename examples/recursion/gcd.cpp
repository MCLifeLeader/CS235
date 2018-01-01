/**************************************************************
 *
 *  NAME:    Brother Cameron
 *
 *  PROGRAM: gcd.cpp
 *
 *  EXAMPLE: Implements the recursive version of the GCD algorithm.
 *
 ***************************************************************/
using namespace std;
#include <iostream>
#include <iomanip>

int gcd(int m, int n);

main()
{
  int num1;
  int num2;

  cout << "Enter an integer: ";
  cin >> num1;
  cout << "Enter an integer: ";
  cin >> num2;

  cout << "Greatest common divisor of " << num1;
  cout << " and " << num2;
  cout << " is " << gcd(num1,num2) << endl;
}

/************************************************************
 *
 *   FUNCTION: gcd
 *
 *   PARAMETERS:
 *        m,n - finding gcd of two int's, m and n
 *
 *   RETURN: An integer which is the gcd of m and n
 *
 *   PURPOSE: Recursively finds the gcd of m and n
 *
 ************************************************************/
int gcd(int m, int n)
{
  int g;   // --- greatest common divisorof m and n
  
  if (n > m)
    g = gcd(n,m);
  else if (n == 0)
    g = m;
  else
    g = gcd(n,m%n);
  return(g);
}
