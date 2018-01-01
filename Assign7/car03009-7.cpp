/***********************************************************************
* Program:
*    Assignment 07, algorithm efficiency
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Use clock ticks to find out how fast a sort works for STL and Qsort
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

// Max array size, Style Checker is saying this is wrong, it doesn't
// like the "unsigned" keyword before "int"
const unsigned int MAXARRAY = 100000;

// quick sort function
void quicksort( int data[], int left, int right );

/*************************************************************
*   NAME: Brother Cameron
*
*   PURPOSE:
*     Class definition for a random functions
*************************************************************/
class Random
{
   public:
      Random();

      /* --- Get next integer in range low-high --- */
      int nextInt( int low, int high );
      int poissonRandom( double expected );
};

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( void )
{
   unsigned int iArrSize;
   unsigned int iCount;

   // the array that will be sorted.
   int *iArray;

   // the STL array to be sorted
   vector < int > vArray;

   // clock start
   clock_t start;
   // clock finish time
   clock_t finish;

   // random number gen class
   Random r;

   // initial array size
   iArrSize = 10000;

   // text output formatting
   cout << " Size         STL-sort           quicksort" << endl;
   cout.setf( ios_base::left );

   // main while loop test area
   while ( iArrSize <= MAXARRAY )
   {
      // allocate memory
      iArray = new int [ iArrSize ];

      // used for text formatting; output the size of the array
      if ( iArrSize > MAXARRAY - 1 )
         cout << iArrSize;
      else
         cout << " " << iArrSize;

      // fill the array and populate with random numbers
      for ( iCount = 0; iCount < iArrSize; iCount++ )
      {
         iArray[ iCount ] = r.nextInt( 1, 500 );
         vArray.push_back( r.nextInt( 1, 500 ) );
      }
      
      // sort and time the regular array
      start = clock();
      sort( vArray.begin(), vArray.end() );
      finish = clock();
      
      cout << "        " << setw( 9 ) << finish - start;

      // sort and time the STL array
      start = clock();
      quicksort( iArray, 0, iArrSize - 1 );
      finish = clock();

      cout << "          " << setw( 9 ) << finish - start << endl;

      // clean up the memory allocated
      delete [] iArray;
      vArray.clear();
      
      // increase the array size by 10000
      iArrSize += 10000;
   }

   return ( 0 );
}

/*********************************************************
*
*  FUNCTION: quicksort
*
*  PARAMETERS: data[] - array of data to be sorted
*              left   - left index of array
*              right  - right index of array
*
*  Purpose:
*     sort an array of data
*********************************************************/
void quicksort( int data[], int left, int right )
{
   int i;
   int j;
   int pivot;
   int temp;

   if ( left <= right )
   {
      pivot = data[ ( left + right ) / 2 ];

      i = left;
      j = right;
      do
      {
         while (data[ i ] < pivot)
            i++;
         while (data[ j ] > pivot)
            j--;
         if ( i <= j )
         {
            temp = data[ i ];
            data[ i ] = data[ j ];
            data[ j ] = temp;
            i++;
            j--;
         }
      } while ( i < j );

      quicksort( data, left, j );
      quicksort( data, i, right );
   }
}

/*********************************************************
*
*    FUNCTION: Random
*
*  PARAMETERS: None
*
*  PURPOSE: Random constructor.  Sets the random number
*              seed to the current time.  The srand function
*              is provided by stdlib.h and time by time.h
*              Passing NULL to the time function returns
*              the current time (in clock ticks) and this
*              is then passed to srand.
*
*  USAGE: Creates a random object to generate random numbers
*              
*              Random r1
*
*********************************************************/
Random::Random()
{
   srand( ( int ) time ( NULL ) );
}

/*********************************************************
*
*    FUNCTION: nextInt
*
*  PARAMETERS: low - smallest number in range
*              high - largest number in range
*
*  PURPOSE: 
*     This function does the following:
*                1. Generate a real number between 0 and 1 
*                   by calling rand() and dividing by
*                   the constant RAND_MAX + 1
*                2. Scale this number to the appropriate range
*                   size (high - low)
*                3. Truncate the value to an integer
*                4. Translate the number to the appropriate
*                   starting point.
*
*  USAGE: Assumes random object has been created.
*               This call will create 1 random number between
*               1 and 50.
*
*               number = r1.nextInt(1,50)
*  Purpose:
*     This one is to make S.C. happy ;)
*********************************************************/
int Random::nextInt( int low, int high )
{
   int k;
   double d;

   d = ( double )rand() / ( ( double )RAND_MAX + 1 );
   k = ( int )( d * ( high - low + 1 ) );
   return ( low + k );
}

/*********************************************************
*
*  FUNCTION: poissonRandom()
*
*  PARAMETERS: expected - the expected value for the Poisson
*              probability distribution function.
*
*  PURPOSE: 
*     To generate an integer from a Poisson distribution
*
*  USAGE:   Assume a Random object, R, has been created.  
*
*           number = R.poissonRandom(.47)
*
*           This will generate an integer based on a Poisson
*           distribution with an expected value of .47.
*  Purpose:
*     This one is to make S.C. happy ;)
***************************************************************/
int Random::poissonRandom( double expected )
{
   int n = 0;
   double limit;
   double x;

   limit = exp( - expected );
   x = rand() / ( ( double )RAND_MAX + 1 );

   while ( x > limit )
   {
      n++;
      x *= rand() / ( ( double ) RAND_MAX + 1 );
   }

   return n;
}
