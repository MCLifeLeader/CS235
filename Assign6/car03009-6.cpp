/***********************************************************************
* Program:
*    Assignment 06, Recursion
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Use Recursion to calculate a Matrix
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int detOfMatrix( vector < int > vInt, int iMatrixSize );

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   ifstream ifile;

   int iMatrixSize = 0;
   int iMatrixVal = 0;
   int iGetInt = 0;
   unsigned int iCount;

   vector < int > vInt;

   // check for file input
   if ( argc > 1 )
   {
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         ifile >> iMatrixSize;
         iCount = iMatrixSize * iMatrixSize; // size of the matrix as an array

         // read the file contents and put them in the vector
         while ( ifile )
         {
            ifile >> iGetInt;
            vInt.push_back( iGetInt );

            if ( --iCount <= 0 )
               break;
         }

         // seed call to recursive function
         iMatrixVal = detOfMatrix( vInt, iMatrixSize );

         // display formating and output
         cout << "Matrix:" << endl;         
         cout.setf( ios::left );

         // display the original matrix values
         for ( iCount = 0; iCount < vInt.size(); iCount++ )
         {
            if ( iCount % iMatrixSize == 0 )
               cout << "    ";

            cout << setw( 4 ) << setfill(' ');

            cout << vInt[ iCount ] << setw( 5 ) << setfill(' ');

            if ( ( iCount + 1 ) % iMatrixSize == 0 )
               cout << setw( 4 ) << setfill(' ') << endl;

         }
         
         cout << endl;
         cout << "Determinant: " << iMatrixVal << endl;
      }
   }
   else
   {
      cout << "usage: assign6 infile" << endl;
   }

   ifile.close();
   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     To find the determinate of a even sided matrix
**************************************************************************/
int detOfMatrix( vector < int > vInt, int iMatrixSize )
{
   // temp vector for passing a smaller matrix in
   vector < int > tInt;
   int iDet = 0;

   // check to see if the matrix is a 1x1
   if ( iMatrixSize > 1 )
   {
      // find the minor of the matrix
      for ( unsigned int i = 0; i < (unsigned int)iMatrixSize; i++ )
      {
         // get the elements and copy them into the temp vector
         for ( unsigned int j = iMatrixSize; j < vInt.size(); j++ )
         {
            if ( j % iMatrixSize != i )
            {
               // insert the the minor matrix value found
               tInt.push_back( vInt[ j ] );
            }
         }

         // recursive function call point
         iDet += (int)( pow( (double) - 1, (double) (i) ) * vInt[ i ] *
            detOfMatrix( tInt, iMatrixSize - 1 ) );

         // clear the temp vector for the next set
         tInt.clear();
      }
   }
   else
      iDet = vInt[ 0 ]; // single matrix value

   // return the value found or calculated value
   return ( iDet );
}
