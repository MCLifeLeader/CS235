/***********************************************************************
* Program:
*    Assignment 08, polynomials
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Insert polynomial records in sorted order.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const unsigned int TERMCOUNT = 50;

/****************************************************************************
*
*  File: poly.h
*
*  Author: Brother Cameron, 10/9/2001
*
*  Purpose: 
*     Defines classes for a Term and a Polynomial
****************************************************************************/
class Term
{
   private:
      float coeff;
      int expon;

   public:
      Term();                   // --- Creates empty Term
      Term( float c, int e );   // --- Creates Term object with coefficient. c
                                //       and exponent. e
      float getCoeff( void );   // --- returns coefficient of term
      int getExpon( void );     // --- returns exponent of term
      void setCoeff( float c ); // --- sets term's coefficient. to c
      void setExpon( int c );   // --- sets term's exponent to c
};

/****************************************************************************
*
*  File: poly.cpp
*
*  Author: Brother Cameron, 10/9/2001
*
*  Purpose: 
*     Implements functions in Term and Poly class
****************************************************************************/
class Poly
{
   private:
      int numTerms;           // --- number of terms in polynomial
      int maxItems;           // --- array capacity
      Term *terms;            // --- dynamically allocated array of terms

   public:
      Poly();                   // --- creates empty polynomial
      float eval( float x );    // --- evaluates polynomial with value x
      unsigned int getNumTerms( void );   // --- get the number of terms
      Term getpTerm( int i );   // --- returns a term from the given location
      void insert( Term t );    // --- inserts Term t into polynomial
      void printPoly( void );   // --- prints out polynomial
      float operator () ( float x );   // evaluates polynomial with value x
};

ostream &operator << ( ostream &objStream, Poly &objPoly );
Poly operator + ( Poly objPoly1, Poly objPoly2 );

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iExpon;
   unsigned int iTermCount;

   float fCoeff;
   float fOfX;

   ifstream ifile;

   Term tTerm;
   Poly pPoly1;
   Poly pPoly2;
   Poly pPoly3;

   // check for file input
   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the file contents and put them in the vector
         while ( ifile )
         {
            // get the poly degree
            ifile >> iTermCount;

            // check to make sure we have valid information for terms
            if ( iTermCount > 0 && iTermCount <= TERMCOUNT )
            {
               // read in the terms
               for ( ; iTermCount > 0; iTermCount-- )
               {
                  ifile >> fCoeff;
                  ifile >> iExpon;

                  tTerm.setCoeff( fCoeff );
                  tTerm.setExpon( iExpon );

                  pPoly1.insert( tTerm );
               }
            }

            // get the poly degree
            ifile >> iTermCount;

            // check to make sure we have valid information for terms
            if ( iTermCount > 0 && iTermCount <= TERMCOUNT )
            {
               // read in the terms
               for ( ; iTermCount > 0; iTermCount-- )
               {
                  ifile >> fCoeff;
                  ifile >> iExpon;

                  tTerm.setCoeff( fCoeff );
                  tTerm.setExpon( iExpon );

                  pPoly2.insert( tTerm );
               }
            }

            // the f(x) value
            ifile >> fOfX;
            break;
         }
      }
      else
      {
         cerr << "Error reading file" << endl;
         exit( 1 );
      }

      // display the contents
      cout << "F(x) =  " << pPoly1 << endl;
      cout << "G(x) =  " << pPoly2 << endl << endl;

      // add the two polynomials together
      pPoly3 = pPoly1 + pPoly2;

      // display the new polynomial
      cout << "P(x) = (F + G)(x) = " << pPoly3 << endl;

      // process the f(x) of the polynomial
      cout << "P(" << fOfX << ") = " << pPoly3( fOfX ) << endl;

   }
   else
   {
      cout << "usage: assign8 infile" << endl;
   }

   return ( 0 );
}

/****************************************************************************
*
*  Function: Term
*
*  Parameters - none
*
*  Return Value - none
*
*  Purpose: 
*     Constructor function for Term class.  Creates empty Term.
***************************************************************************/
Term::Term( void )
{
   coeff = 0.0;
   expon = -1;  // --- guarantees insert will occur
}

/****************************************************************************
*
*  Function: Term
*
*  Parameters - a float that is the coefficient and a int that is the 
*                 exponent.
*
*  Return Value - None
*
*  Purpose: 
*     Creates a Term object set to coefficient and exponent.
***************************************************************************/
Term::Term( float c, int e )
{
   coeff = c;
   expon = e;
}

/****************************************************************************
*
*  Function: get_coeff
*
*  Parameters: None
*
*  Return Value - an integer representing coefficient.
*
*  Purpose: 
*     Returns the coefficient data member of Term class
***************************************************************************/
float Term::getCoeff( void )
{
   return ( coeff );
}

/**************************************************************************
*
*  Function: get_expon
*
*  Parameters - none
*
*  Return value - integer, representing exponent.
*
*  Purpose: 
*     Returns the exponent data member of Term class
**************************************************************************/
int Term::getExpon( void )
{
   return ( expon );
}

/***************************************************************************
*
*  Function: set_coeff
*
*  Parameters - float representing coefficient
*
*  Return value - none
*
*  Purpose:
*     sets c to data member coefficient in Term class
**************************************************************************/
void Term::setCoeff( float c )
{
   coeff = c;
}

/***************************************************************************
*
*  Function: set_expon
*
*  Parameters - int representing exponent
*
*  Return value - none
*
*  Purpose: 
*     sets e to data member exponent in Term class
**************************************************************************/
void Term::setExpon( int e )
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
*  Purpose: 
*     Poly class constructor to create an empty Poly object of TERMCOUNT
*        terms.*
**************************************************************************/
Poly::Poly()
{
   numTerms = 0;
   maxItems = TERMCOUNT - 1;
   terms = new Term [ TERMCOUNT ];
}

/*************************************************************************
*  Purpose:
*     get the number of terms in the object
**************************************************************************/
unsigned int Poly::getNumTerms( void )
{
   return ( numTerms );
}

/*************************************************************************
*  Purpose:
*     get the ptr to the Term
**************************************************************************/
Term Poly::getpTerm( int i )
{
   Term t;

   // check bounds then return the value of the given location
   if ( i <= this->numTerms && i >= 0 )
      t = Term( this->terms[ i ].getCoeff(), this->terms[ i ].getExpon() );

   return ( t );
}

/*************************************************************************
*  Purpose:
*     evaluate the polynomial
**************************************************************************/
float Poly::eval( float x )
{
   unsigned int iCount;
   float totEval = 0;

   // evaluate the value of the polynomial given the f(x)
   for ( iCount = 0; iCount < ( unsigned int ) this->numTerms; iCount++ )
   {
      // check exponent value for proper addition
      if ( this->terms[ iCount ].getExpon() > 0 )
      {
         totEval += pow( x, (float)this->terms[ iCount ].getExpon() ) * 
                        this->terms[ iCount ].getCoeff();
      }
      else
         totEval += this->terms[ iCount ].getCoeff();
   }

   return ( totEval );
}

/*************************************************************************
*  Purpose:
*     insert an item into the polynomial
**************************************************************************/
void Poly::insert( Term t )
{
   bool bInsert;
   int i;
   int j;

   Term tTerm;

   bInsert = true;

   // are we with in the bounds of the array
   if ( this->numTerms <= this->maxItems )
   {
      // start looking for duplicate records
      for ( i = 0; i < this->numTerms; i++ )
      {
         // if the exponents are the same do addition on the coefficient
         if ( t.getExpon() == this->terms[ i ].getExpon() )
         {
            bInsert = false;
            this->terms[ i ].setCoeff( 
                  this->terms[ i ].getCoeff() + t.getCoeff() );

            // if the coefficient is now zero remove it from the list
            if ( this->terms[ i ].getCoeff() == 0 )
            {
               for ( j = i; j < this->numTerms; j++ )
               {
                  this->terms[ j - 1 ].setCoeff( 
                     this->terms[ j ].getCoeff( ) );
                  this->terms[ j - 1 ].setExpon( 
                     this->terms[ j ].getExpon( ) );
               }

               // remove a record
               this->numTerms--;
            }

            return;
         }
      }
      
      // insert coefficients based on exponent ranking
      for ( i = 0; i < this->numTerms; i++ )      
      {
         // check to see if the inserted exponent is larger
         if ( t.getExpon() > this->terms[ i ].getExpon() )
         {
            bInsert = false;

            // adjust the array to insert the new record
            for ( j = this->numTerms; j >= i; j-- )
            {
               this->terms[ j + 1 ].setCoeff( 
                  this->terms[ j ].getCoeff( ) );
               this->terms[ j + 1 ].setExpon( 
                  this->terms[ j ].getExpon( ) );
            }

            // insert the new term
            this->terms[ j + 1 ] = t;
            this->numTerms++;

            return;
         }
      }

      // insert a new term
      if ( bInsert == true )
         this->terms[ this->numTerms++ ] = t;
   }
   else
   {
      cerr << "Insert Failed, to many records" << endl;
      exit( 1 );
   }
}

/*************************************************************************
*  Purpose:
*     print the polynomial
**************************************************************************/
void Poly::printPoly( )
{
   cout << this;
}

/*************************************************************************
*  Purpose:
*     Overloaded Evaluate function
**************************************************************************/
float Poly::operator () ( float x )
{
   return ( this->eval( x ) );
}

/*************************************************************************
*  Purpose:
*     Add two polynomials together
**************************************************************************/
Poly operator + ( Poly objPoly1, Poly objPoly2 )
{
   unsigned int iCount;
   Poly p;

   // use the insert function to do the addition
   for ( iCount = 0; iCount < objPoly1.getNumTerms(); iCount++ )
   {
      p.insert( objPoly1.getpTerm( iCount ) );
   }

   // use the insert function to do the addition
   for ( iCount = 0; iCount < objPoly2.getNumTerms(); iCount++ )
   {
      p.insert( objPoly2.getpTerm( iCount ) );
   }

   return ( p );
}

/*************************************************************************
*  Purpose:
*     Display the polynomial
**************************************************************************/
ostream &operator << ( ostream &objStream, Poly &objPoly )
{
   unsigned int iCount;
   float tCoe;
   int tExp;

   // text output formatting.
   for ( iCount = 0; iCount < objPoly.getNumTerms(); iCount++ )
   {
      tCoe = objPoly.getpTerm( iCount ).getCoeff();
      tExp = objPoly.getpTerm( iCount ).getExpon();

      if ( tCoe > 0 && tExp >= 0 )
      {
         if ( tCoe > 1 )
         {
            if ( iCount == 0 )
            {
               objStream << tCoe;
               
               if ( tExp > 1 )
               {
                  objStream << "x^" << tExp;
               }
               else if ( tExp == 1 )
               {
                  objStream << "x";
               }
            }
            else
            {
               objStream << " + " << tCoe;

               if ( tExp > 1 )
               {
                  objStream << "x^" << tExp;
               }
               else if ( tExp == 1 )
               {
                  objStream << "x";
               }
            }
         }
         else if ( tExp == 0 )
         {
            if ( iCount == 0 )
            {
               objStream << tCoe;
            }
            else
            {
               objStream << " + " << tCoe;
            }
         }
         else if ( tCoe == 1 )
         {
            if ( iCount != 0 )
            {
               objStream << " + ";
            }

            if ( tExp > 1 )
            {
               objStream << "x^" << tExp;
            }
            else if ( tExp == 1 )
            {
               objStream << "x";
            }
         }
      }
      else if ( tCoe < 0 )
      {
         if ( tCoe < -1 )
         {
            if ( iCount == 0 )
            {
               objStream << tCoe;

               if ( tExp > 1 )
               {
                  objStream << "x^" << tExp;
               }
               else if ( tExp == 1 )
               {
                  objStream << "x";
               }
            }
            else
            {
               objStream << " - " << ( tCoe * -1 );

               if ( tExp > 1 )
               {
                  objStream << "x^" << tExp;
               }
               else if ( tExp == 1 )
               {
                  objStream << "x";
               }
            }
         }
         else if ( tExp == 0 )
         {
            if ( iCount == 0 )
            {
               objStream << "-" << tCoe;
            }
            else
            {
               objStream << " - " << ( tCoe * -1 );
            }
         }
         else if ( tCoe == -1 )
         {
            if ( iCount == 0 )
            {
               objStream << "-";
            }
            else
            {
               objStream << " - ";
            }

            if ( tExp > 1 )
            {
               objStream << "x^" << tExp;
            }
            else if ( tExp == 1 )
            {
               objStream << "x";
            }
         }
      }
   }

   return ( objStream );
}
