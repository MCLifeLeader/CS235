/***********************************************************************
* Program:
*    Assignment 01, Set Class
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    This program demonstrates the use of overloaded operators to make
*    various comparisons in two sets of randomly generated numbers from
*    a data file using a personally defined class.
***********************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

/*************************************************************************
*   class:
*      Set
*   Purpose:
*      Storage object for number sets.
*************************************************************************/
class Set
{
   public:
      Set();                              // Default Constructor
      Set( int iInitArraySize );          // Overloaded
      int getSize( void );                // Return Size
      int getCount( void );               // Return Count
      int getArrItm( int iItem );         // Get Array Element Item
      bool isNumberInList( int iNumber ); // is a number in the list
      bool addNumber( int iNumber );      // add the number to the list
      void operator = ( Set objSet );     // copy object values

   private:
      int iArraySize;      // The length of the Array
      int iArrayCount;     // Count of unique Items
      int *iNumberList;    // Storage array, could be linked list
};

// Difference
Set operator -  ( Set &objSet1, Set &objSet2 );
// Intersection
Set operator && ( Set &objSet1, Set &objSet2 );
// Union
Set operator || ( Set &objSet1, Set &objSet2 );
// using ostream for output
ostream &operator << ( ostream &objStream, Set &objSet );

/*************************************************************************
*   Purpose:
*      main function for using Set class
*   Input:
*      void
*   Output:
*      none
*   Return:
*      int
*   Parameters:
*      Program return value ( void ).
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iItems;
   int iCount;
   unsigned int i;
   string stReadFile;
   string stSeg;

   Set obj1;
   Set obj2;
   Set obj3;

   ifstream ifile;

   if ( argc > 1 )
   {
      ifile.open( argv[ 1 ] );

      // Get Lines from the file
      getline( ifile, stReadFile );
      iCount = atoi( stReadFile.c_str() );
      obj1 = Set( iCount );

      // --- Create set A
      // Get Lines from the file
      getline( ifile, stReadFile );

      iItems = 0;
      i = 0;
      while ( iItems++ < iCount )
      {
         stSeg = "";
         for ( ; i < strlen( stReadFile.c_str() ); i++ )
         {
            if ( stReadFile[ i ] == ' ' )
               break;

            stSeg  += stReadFile[ i ];
         }
         i++;

         obj1.addNumber( atoi( stSeg.c_str() ) );
      }

      // Get Lines from the file
      getline( ifile, stReadFile );
      iCount = atoi( stReadFile.c_str() );
      obj2 = Set( iCount );

      // --- Create set A
      // Get Lines from the file
      getline( ifile, stReadFile );

      iItems = 0;
      i = 0;
      while ( iItems++ < iCount )
      {
         stSeg = "";
         for ( ; i < strlen( stReadFile.c_str() ); i++ )
         {
            if ( stReadFile[ i ] == ' ' )
               break;

            stSeg  += stReadFile[ i ];
         }
         i++;

         obj2.addNumber( atoi( stSeg.c_str() ) );
      }

      // --- Output set A and B
      cout << "Set A: " << endl;
      cout << obj1 << endl << endl;
      cout << "Set B: " << endl;
      cout << obj2 << endl << endl;

      // --- Intersection
      obj3 = obj1 && obj2;
      cout << "Intersection of A and B: " << endl;
      cout << obj3 << endl << endl;

      // --- Union
      obj3 = obj1 || obj2;
      cout << "Union of A and B: " << endl;
      cout << obj3 << endl << endl;

      // --- Difference
      obj3 = obj1 - obj2;
      cout << "Difference of A and B: " << endl;
      cout << obj3 << endl << endl;

      // --- Difference
      obj3 = obj2 - obj1;
      cout << "Difference of B and A: " << endl;
      cout << obj3 << endl << endl;
   }
   else
   {
      cout << "Usage: assign1.exe inFile" << endl;
   }

   ifile.close();
   return ( 0 );
}

/*************************************************************************
*   Purpose:
*      Default Constructor initialize values
**************************************************************************/
Set::Set()
{
   // Set values to NULL
   iNumberList = NULL;
   iArrayCount = iArraySize = 0;
}

/*************************************************************************
*   Purpose:
*      Constructor initialize values
**************************************************************************/
Set::Set( int iInitArraySize )
{
   int iCount = 0;

   iNumberList = new int [ iInitArraySize + 1 ];

   // Set values to iInitArrayValue
   for ( iCount = 0; iCount < iInitArraySize; iCount++ )
      iNumberList[ iCount ] = -1;
   
   iArraySize = iInitArraySize;
   iArrayCount = 0;
}

/*************************************************************************
*   Purpose:
*      Get the number of used elements in the array.
**************************************************************************/
int Set::getSize( void )
{
   return ( iArraySize );
}

/*************************************************************************
*   Purpose:
*      Get the number of used elements in the array.
**************************************************************************/
int Set::getCount( void )
{
   return ( iArrayCount );
}

/*************************************************************************
*   Purpose:
*      Get an element number and return it given a position in the array.
**************************************************************************/
int Set::getArrItm( int iItem )
{
   // Get a number from the array stored in the class
   if ( ( iItem <= iArrayCount ) || ( iItem >= 0 ) )
      return ( iNumberList[ iItem ] );

   return ( -1 ); // Return a non valid number as an error.
}

/*************************************************************************
*   Purpose:
*      Add a unique element to the array.
**************************************************************************/
bool Set::addNumber( int iNumber )
{
   // By default the number has not been added
   bool bIsNumberAdded = false;
   int iTemp;
   int iCount1;
   int iCount2;

   // check to see if we have room to add a value to the array
   if ( iArrayCount <= iArraySize )
   {
      // Check to see if the number is already in the array
      if ( !( bIsNumberAdded = isNumberInList( iNumber ) ) )
         iNumberList[ iArrayCount++ ] = iNumber;// Add the number, move index

      // use Quick Sort for the array.
      for ( iCount1 = 0; iCount1 < iArrayCount; iCount1++ )
      {
         for ( iCount2 = 0; iCount2 < iArrayCount; iCount2++ )
         {
            if ( iNumberList[ iCount1 ] < iNumberList[ iCount2 ] )
            {
               iTemp = iNumberList[ iCount1 ];
               iNumberList[ iCount1 ] = iNumberList[ iCount2 ];
               iNumberList[ iCount2 ] = iTemp;
            }
         }
      }
   }

   // return the result if added or not
   return ( !bIsNumberAdded );
}

/*************************************************************************
*   Purpose:
*      Check to see if a number is already in the list
**************************************************************************/
bool Set::isNumberInList( int iNumber )
{
   // By default the number is not in the array
   bool bIsNumberPresent = false;
   int iCount = 0;

   for ( iCount = 0; iCount < iArrayCount; iCount++ )
   {
      // If the number is present set the flag to true and break;
      if ( iNumberList[ iCount ] == iNumber )
      {
         bIsNumberPresent = true;
         break;
      }
   }

   // return the result if present or not
   return ( bIsNumberPresent );
}

/*************************************************************************
*   Purpose:
*      To create a Set object with the differences between two Set objects
**************************************************************************/
Set operator -  ( Set &objSet1, Set &objSet2 )
{
   bool bAddItem = true;   // By default we are going to add the item.
   int iSize = 0;
   int iArraySize1 = 0;
   int iArraySize2 = 0;
   int iCount1 = 0;
   
   iSize = objSet1.getCount() + objSet2.getCount();

   Set objReturn( iSize );

   // Use temp variables instead of making multiple calls to the access
   // function thus reducing function call over head and slowing down the
   // application.
   iArraySize1 = objSet1.getCount();
   iArraySize2 = objSet2.getCount();

   for ( iCount1 = 0; iCount1 < iArraySize1; iCount1++ )
   {
      bAddItem = true;

      for ( int iCount2 = 0; iCount2 < iArraySize2; iCount2++ )
      {
         // if the item is found in both lists then do not add it, so set
         // flag to false and break;
         if ( objSet1.getArrItm( iCount1 ) == objSet2.getArrItm( iCount2 ) )
         {
            bAddItem = false;
            break;
         }
      }

      // only add the item if it is unique to the first array
      if ( bAddItem )
         objReturn.addNumber( objSet1.getArrItm( iCount1 ) );
   }

   // return the new object
   return ( objReturn );
}

/*************************************************************************
*   Purpose:
*      To create a Set object with the intersection between two Set objects
**************************************************************************/
Set operator && ( Set &objSet1, Set &objSet2 )
{
   int iSize = 0;
   int iArraySize1 = 0;
   int iArraySize2 = 0;
   int iCount1 = 0;
   int iCount2 = 0;
   
   iSize = objSet1.getCount() + objSet2.getCount();

   Set objReturn( iSize );

   // Use temp variables instead of making multiple calls to the access
   // function thus reducing function call over head and slowing down the
   // application.
   iArraySize1 = objSet1.getCount();
   iArraySize2 = objSet2.getCount();

   for ( iCount1 = 0; iCount1 < iArraySize1; iCount1++ )
   {
      for ( iCount2 = 0; iCount2 < iArraySize2; iCount2++ )
      {
         // check to see if the item is found in both arrays then add
         // the element and then break;
         if ( objSet1.getArrItm( iCount1 ) == objSet2.getArrItm( iCount2 ) )
         {
            objReturn.addNumber( objSet1.getArrItm( iCount1 ) );
            break;
         }
      }
   }

   // return the new object
   return ( objReturn );
}

/*************************************************************************
*   Purpose:
*      To create a Set object with the union between two Set objects
**************************************************************************/
Set operator || ( Set &objSet1, Set &objSet2 )
{
   int iSize = 0;
   int iArraySize = 0;
   int iCount = 0;
   
   iSize = objSet1.getCount() + objSet2.getCount();

   Set objReturn( iSize );

   // Use temp variable instead of making multiple calls to the access
   // function thus reducing function call over head and slowing down the
   // application.
   iArraySize = objSet1.getCount();

   for ( iCount = 0; iCount < iArraySize; iCount++ )
   {
      // Add all the items found in the first list
      objReturn.addNumber( objSet1.getArrItm( iCount ) );
   }

   iArraySize = objSet2.getCount();
   for ( iCount = 0; iCount < iArraySize; iCount++ )
   {
      // Add all the items found in the second list
      // if they are not duplicates
      objReturn.addNumber( objSet2.getArrItm( iCount ) );
   }

   // return the new object
   return ( objReturn );
}

/*************************************************************************
*   Purpose:
*      To send the contents of the set object to the out stream
**************************************************************************/
ostream &operator << ( ostream &objStream, Set &objSet )
{
   int iDisplayCount = 0;                     // counter to display 10 across.
   int iArraySize    = objSet.getCount();    // Get the size of the array.
   int iArrayItem    = 0;                     // Temp variable for Items
   
   if ( objSet.getCount() )
   {
      objStream << " ";    // For character formatting

      // loop through the array to display the gathered numbers
      for ( int iCount = 0; iCount < iArraySize; iCount++ )
      {
         // if the value in the objSet.getArrItm() is > 0 then
         // display that value
         if ( ( iArrayItem = objSet.getArrItm( iCount ) ) >= 0 )
         {
            iDisplayCount++;

            // This is used for display formatting.
            if ( iArrayItem >= 10 )
               objStream << iArrayItem << " ";
            else
               objStream << " " << iArrayItem << " ";

            // if the 10th item then print a \n to the screen after it.
            if ( iDisplayCount % 10 == 0 )
            {
               objStream << endl;
               if ( iCount < iArraySize - 1 )
                  objStream << " "; // For character formatting
            }
            else
               if ( iCount < iArraySize - 1 )
                  objStream << " ";
         }
      }
   }

   // return an outstream object reference
   return ( objStream );
}

/*************************************************************************
*   Purpose:
*      To copy the contents of one object into another object
**************************************************************************/
void Set::operator = ( Set objCopy )
{
   int iCount = 0;

   iArrayCount = iArraySize = 0;

   // Copy the contents of one object into the new object
   if ( iArraySize == 0 && objCopy.getCount() > 0 )
   {
      iArrayCount = iArraySize = objCopy.getCount();

      iNumberList = new int [ iArraySize + 1 ];
      for ( iCount = 0; iCount < iArraySize; iCount++ )
      {
         iNumberList[ iCount ] = objCopy.getArrItm( iCount );
      }
   }
   else
   {
      iArraySize = objCopy.getSize();
      iNumberList = new int [ iArraySize + 1 ];
   }
}
