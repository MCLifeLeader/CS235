/*****************************************************************************
 *
 *  File: poly.cpp
 *
 *  Author: Brother Cameron, 10/9/2001
 *
 *  Purpose: Implements functions in Term and Poly class
 *
 *****************************************************************************/
using namespace std;
#include <iostream>
#include <math.h>

/*****************************************************************************
 *
 *  Function: Term
 *
 *  Parameters - none
 *
 *  Return Value - none
 *
 *  Purpose - Constructor function for Term class.  Creates empty Term.
 *
 ****************************************************************************/
Term::Term(void)
{
  coeff = 0.0;
  expon = -1;  // --- guarentees insert will occur
}

/*****************************************************************************
 *
 *  Function: Term
 *
 *  Parameters - a float that is the coefficent and a int that is the expon.
 *
 *  Return Value - None
 *
 *  Purpose: Creates a Term object set to coefficent and expon.
 *
 ****************************************************************************/
Term::Term(float c, int e)
{
  coeff = c;
  expon = e;
}

/*****************************************************************************
 *
 *  Function: get_coeff
 *
 *  Parameters: None
 *
 *  Return Value - an integer representing coeff.
 *
 *  Purpose: Returns the coefficent data member of Term class
 *
 ****************************************************************************/
float Term::get_coeff(void)
{
  return(coeff);
}

/***************************************************************************
 *
 *  Function: get_expon
 *
 *  Parameters - none
 *
 *  Return value - integer, representing expon.
 *
 *  Purpose: Returns the expon data member of Term class
 *
 **************************************************************************/
int Term::get_expon(void)
{
  return(expon);
}

/***************************************************************************
 *
 *  Function: set_coeff
 *
 *  Parameters - float representing coeff
 *
 *  Return value - none
 *
 *  Purpose: sets c to data member coeff in Term class
 *
 **************************************************************************/
void Term::set_coeff(float c)
{
  coeff = c;
}

/***************************************************************************
 *
 *  Function: set_expon
 *
 *  Parameters - int representing expon
 *
 *  Return value - none
 *
 *  Purpose: sets e to data member expon in Term class
 *
 **************************************************************************/
void Term::set_expon(int e)
{
  expon = e;
}

/***************************************************************************
 *
 *  Function: Poly
 *
 *  Parameters - none
 *
 *  Return value - none
 *
 *  Purpose: Poly class constructor to create an empty Poly object of 50
 *           terms.
 *
 **************************************************************************/
Poly::Poly()
{
  num_terms = 0;
  terms = new Term [50];
}

