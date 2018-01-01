/***********************************************************************
* Program:
*    Assignment 17, Heap Sort
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Using a list to do a Heap Sort
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Heapify
void heapIt( vector < int > &vList, int iPos, int iEnd );
// Heap Sort
void heapSort( vector < int > &vList );

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iReadData;
   ifstream ifile;

   vector < int > vList;

   // check for file input
   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the data in
         while ( ifile >> iReadData )
            vList.push_back( iReadData );

         // sort the data
         heapSort( vList );

         // print the data
         for ( unsigned int i = 0; i < vList.size(); i++ )
            cout << vList[ i ] << " ";

         cout << endl;

      }
      else
      {
         cerr << "Error reading file" << endl;
         ifile.close();
         exit( 1 );
      }
   }
   else
   {
      cout << "usage: assign17 infile" << endl;
      exit( 1 );
   }

   ifile.close();

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Heapify the data
**************************************************************************/
void heapIt( vector < int > &vList, int iPos, int iEnd )
{
   int iMax;
   int iTemp;

   // continue until properly sorted with the end point
   while ( iPos * 2 <= iEnd )
   {
      // check which way it should go checking leaf nodes
      if ( iPos * 2 == iEnd )
         iMax = iPos * 2;
      else if ( vList[ iPos * 2 ] > vList[ iPos * 2 + 1 ] )
         iMax = iPos * 2;
      else
         iMax = iPos * 2 + 1;

      // do the swap if the condition is true
      if ( vList[ iPos ] < vList[ iMax ] )
      {
         // the actual swap process
         iTemp = vList[ iPos ];
         vList[ iPos ] = vList[ iMax ];
         vList[ iMax ] = iTemp;
         // adjust the pointing location in the list
         iPos = iMax;
      }
      else
         break; // quit
   }
}

/*************************************************************************
*  Purpose:
*     Heap sort process
**************************************************************************/
void heapSort( vector < int > &vList )
{
   int size = vList.size();
   int temp;

   // do the inital heapify
   for ( int i = ( size / 2) - 1; i >= 0; i-- )
      heapIt( vList, i, size );

   // do the swap and the heapify process over and over again
   for ( int i = size - 1; i >= 1; i-- )
   {
      // do the swap
      temp = vList[ 0 ];
      vList[ 0 ] = vList[ i ];
      vList[ i ] = temp;

      // heapify it
      heapIt( vList, 0, i - 1 );
   }
}
