/*************************************************************************
*   class:
*      Set
*   Purpose:
*		Create an object to compaire two sets of numbers
*************************************************************************/
class Set
{
public:
   Set();                        // Default Constructor
   Set( int iInitArraySize );		// Overloaded
   int getSize( void );          // Return Size
	int getCount( void );			// Return Count
   int getArrItm( int iItem );         // Get Array Element Item
   bool isNumberInList( int iNumber ); // is a number in the list
   bool addNumber( int iNumber );      // add the number to the list
   void operator = ( Set objSet );		// copy object values

private:
   int iArraySize;                     // The length of the Array
	int iArrayCount;							// Count of unique Items
   int *iNumberList;							// Storage array, could be linked list
};

// Difference
Set operator -  ( Set &objSet1, Set &objSet2 );
// Intersection
Set operator && ( Set &objSet1, Set &objSet2 );
// Union
Set operator || ( Set &objSet1, Set &objSet2 );
// using ostream for output
ostream &operator << ( ostream &objStream, Set &objSet );
