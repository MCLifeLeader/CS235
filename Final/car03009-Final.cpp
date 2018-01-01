/***********************************************************************
* Program:
*    Assignment final, parsing a gedcom
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Read in and sort gedcom data using data structures developed in 
*    class.
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const unsigned int MAX = 500;

struct GEDATA
{
   int iGedID;    // gedcom ID
   string stGivn; // first name
   string stSurn; // last name
   string stDate; // birth date
};

/*******************************************************************
*  PURPOSE: 
*     Node Class for a doubly linked list
*******************************************************************/
class Node
{
   private:
      GEDATA data;            // The data
      Node *next;             // --- pointer to next node
      Node *mother;           // mother node
      Node *father;           // father node
      int iDepth;             // tree depth

   public:
      Node();                 // --- Creates empty node
      Node *getNext();        // --- returns next pointer of a node
      GEDATA getData();       // get the gedcom data struct
      void setData( GEDATA gedata );   // set the gedcom data struct
      void setDepth( int depth );   // set the depth
      int getDepth( void );      // get the depth
      void setNext(Node *node);  // --- sets next to point to node
      void setfather( Node *node ); // set father node
      void setmother( Node *node ); // set mother node
      Node *getfather( void );   // get father node
      Node *getmother( void );   // set father node
};

/*******************************************************************
*  PURPOSE: 
*     List Class for handling and managing a doubly linked list
*******************************************************************/
class List
{
   private:
      int iNumItems;          // number of items in list
      Node *ptrNodeListItems; // head node
      void setDepth( void );  // set the depth search process

   public:
      List();  // constructor
      void insert( int pos, Node *temp );    // insert a node at position
      void insertSorted( GEDATA gedData );   // insert in sorted order
      void deleteNode(int pos);  // delete a node
      int lookup(int gedID);     // lookup a node
      GEDATA getData(int pos);   // get the data from a node
      Node *getNode( int pos );  // get a node
      void setData( GEDATA item, int pos );  // set data at a position
      int empty(void);           // is empty?
      int getNumitems(void);     // get number of items
            //set relationships
      void setParents( int iChild, int iFather, int iMother );
      void levelPrint( void );   // level order traversal
};

int parseGedID( string stInput );

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   bool bIndividual; // individual flag

   int iGedChild;    // child gedID
   int iGedMother;   // mother gedID
   int iGedFather;   // father gedID
   
   ifstream ifile;   // in file stream
   ofstream ofile;   // out file stream

   string stFileData;   // temp string for data read

   List gedList;     // the list

   GEDATA gedData;   // gedcom data struct

   bIndividual = false;

   // check for file input
   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the data in
         getline( ifile, stFileData );
         while ( !ifile.eof() )
         {
            // look for a person record
            if ( stFileData.substr( 2, 2 ) == "@I" )
            {
               // store some information about a person
               if ( bIndividual == true )
                  gedList.insertSorted( gedData );

               bIndividual = true;

               gedData.iGedID = 0;
               gedData.stGivn = "";
               gedData.stSurn = "";
               gedData.stDate = "";

               // get a gedID
               gedData.iGedID = parseGedID( 
                     stFileData.substr( 4, stFileData.size() - 4 ) );
            }
            else if ( stFileData.substr( 2, 2 ) == "@F" )   // look for family
            {
               // store last individual found
               if ( bIndividual == true )
                  gedList.insertSorted( gedData );

               bIndividual = false;
               
               gedData.iGedID = 0;
               gedData.stGivn = "";
               gedData.stSurn = "";
               gedData.stDate = "";
               
               iGedChild = iGedMother = iGedFather = 0;
            }

            // looking for a person
            if ( bIndividual )
            {
               if ( stFileData.substr( 2, 4 ) == "GIVN" )   // first name
                  gedData.stGivn = stFileData.substr( 7, 
                     stFileData.size() - 7 );
               else if ( stFileData.substr( 2, 4 ) == "SURN" ) // last name
                  gedData.stSurn = stFileData.substr( 7, 
                     stFileData.size() - 7 );
               else if ( stFileData.substr( 2, 4 ) == "BIRT" ) // birth date
               {
                  getline( ifile, stFileData );

                  if ( stFileData.substr( 2, 4 ) == "DATE" )   // the date
                     gedData.stDate = stFileData.substr( 7, 
                        stFileData.size() - 7 );
               }
            }
            else
            {
               // look for family record information
               if ( !bIndividual && stFileData.substr( 2, 4 ) == "HUSB" )
                  iGedFather = parseGedID( 
                     stFileData.substr( 9, stFileData.size() - 9 ) );
               else if ( !bIndividual && stFileData.substr( 2, 4 ) == "WIFE" )
                  iGedMother = parseGedID( 
                     stFileData.substr( 9, stFileData.size() - 9 ) );
               else if ( !bIndividual && stFileData.substr( 2, 4 ) == "CHIL" )
               {
                  iGedChild = parseGedID( 
                     stFileData.substr( 9, stFileData.size() - 9 ) );

                  gedList.setParents( iGedChild, iGedFather, iGedMother );
               }
            }

            // get a line of data
            getline( ifile, stFileData );
         }

         // open a file for writing
         ofile.open( "sorted.dat" );
         
         // output the contents from the list into the file
         for ( int i = 0; i < gedList.getNumitems(); i++ )
         {
            gedData = gedList.getData( i );

            if ( gedData.stGivn.size() )
            {
               ofile << gedData.stGivn;

               if ( gedData.stSurn.size() )
                  ofile << " " << gedData.stSurn;

               if ( gedData.stDate.size() )
                  ofile << ", b. " << gedData.stDate;
            }
            else
            {
               ofile << gedData.stSurn;

               if ( gedData.stDate.size() )
                  ofile << ", b. " << gedData.stDate;
            }

            ofile << endl;
         }

         // close file
         ofile.close();

         // print the contents of the family tree
         gedList.levelPrint( );
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
      cout << "usage: assignFinal infile" << endl;
      exit( 1 );
   }

   return ( 0 );
}


/*************************************************************************
*  Purpose:
*     Find the GedID, pass in starting at the first digit
**************************************************************************/
int parseGedID( string stInput )
{
   char *tempStr;
   int iGedID;

   tempStr = new char [ stInput.size() + 1 ];

   // get the number id
   for ( unsigned int i = 0; i < stInput.size(); i++ )
   {
      tempStr[ i ] = stInput[ i ];
      tempStr[ i + 1 ] = '\0';
      if ( tempStr[ i ] == '@' )
      {
         tempStr[ i ] = '\0';
         break;
      }
   }

   // convert c-String to int value
   iGedID = atoi( tempStr );
   delete [] tempStr;

   return ( iGedID );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
List::List()
{
   this->iNumItems = 0;
   this->ptrNodeListItems = NULL;
}

/*************************************************************************
*  Purpose:
*     Set the data at a position
**************************************************************************/
void List::setData( GEDATA item, int pos )
{
   Node *curr;
   int iCount = 0;

   curr = this->ptrNodeListItems;
   
   while ( curr )
   {
      if ( iCount == pos )
      {
         curr->setData( item );
         return;
      }

      iCount++;
      curr = curr->getNext();
   }
}

/*************************************************************************
*  Purpose:
*     insert a record at a certain position in sorted order
**************************************************************************/
void List::insertSorted( GEDATA itemIn )
{
   int pos = 0;
   
   Node *curr;
   Node *temp;
   
   temp = new Node;
   
   GEDATA tItem = itemIn;

   temp->setData( tItem );

   curr = this->ptrNodeListItems;

   string stSurn;
   string stGivn;
   string stDate;

   // find the position to insert data at
   for ( int i = 0; i < this->iNumItems; i++ )
   {
      stSurn = curr->getData().stSurn;
      stGivn = curr->getData().stGivn;
      stDate = curr->getData().stDate;

      // check the name, last, first, and birth date
      if ( tItem.stSurn == stSurn )
      {
         if ( tItem.stGivn == stGivn )
         {
            if ( tItem.stDate < stDate )
            {
               pos = i;
               break;
            }
         }
         else if ( tItem.stGivn < stGivn )
         {
            pos = i;
            break;
         }
      }
      else if ( tItem.stSurn < stSurn )
      {
         pos = i;
         break;
      }

      if ( curr->getNext () == NULL )
      {
         pos = this->iNumItems;
         break;
      }
      else
         curr = curr->getNext();
   }

   // insert the record at a given position found
   this->insert( pos, temp );
}

/*************************************************************************
*  Purpose:
*     Insert a record at a position
**************************************************************************/
void List::insert( int pos, Node *temp )
{
   Node *curr;

   // if empty or position 0 insert at head
   if ( pos == 0 || this->empty() )
   {
      if ( empty() )
         this->ptrNodeListItems = temp;
      else
      {
         temp->setNext( this->ptrNodeListItems );
         this->ptrNodeListItems = temp;
      }
   }
   else
   {
      // insert later in the record set
      curr = this->ptrNodeListItems;

      for ( int i = 0; i < pos - 1; i++ )
      {
         if ( curr->getNext() == NULL )
            break;
         else
            curr = curr->getNext();
      }

      temp->setNext( curr->getNext() );
      curr->setNext( temp );
   }

   this->iNumItems++;
}

/*************************************************************************
*  Purpose:
*     Set the parent child relationship.
**************************************************************************/
void List::setParents( int iChild, int iFather, int iMother )
{
   Node *nChild;
   Node *nFather;
   Node *nMother;

   // find the child node
   nChild = this->getNode( this->lookup( iChild ) );

   if ( nChild )
   {
      // find the father node
      nFather = this->getNode( this->lookup( iFather ) );
      // find the mother node
      nMother = this->getNode( this->lookup( iMother ) );

      // set the father node if one was found
      if ( nFather )
         nChild->setfather( nFather );

      // set the mother node if one was found
      if ( nMother )
         nChild->setmother( nMother );
   }
}

/*************************************************************************
*  Purpose:
*     delete a record at a given position
**************************************************************************/
void List::deleteNode( int pos )
{
   int iCount;

   Node *prev;
   Node *curr;

   // if the list is not empty we can delete a record
   if ( this->empty() )
      return;

   iCount = 0;
   prev = curr = this->ptrNodeListItems;

   // handles first element
   if ( pos == 0 )
   {
      // maintain the head
      this->ptrNodeListItems = curr->getNext();
      this->iNumItems--;
      curr = curr->getNext();

      delete prev;

      return;
   }

   while ( curr )
   {
      // protect vs NULL and check if last node in list
      if ( curr && !curr->getNext() )
      {
         // delete a record
         delete curr;
         prev->setNext( NULL );
         this->iNumItems--;

         return;
      }
      else if ( pos == iCount )
      {
         // remove a record from the middle of the list
         prev->setNext( curr->getNext() );
         delete curr;
         curr = prev->getNext();
         this->iNumItems--;

         return;
      }

      iCount++;
      prev = curr;
      curr = curr->getNext();
   }
   
   return;
}

/*************************************************************************
*  Purpose:
*     look up an item return position of item
**************************************************************************/
int List::lookup( int iGedID )
{
   int iCount;

   Node *curr;

   // quit if the list is empty
   if ( this->empty() )
      return ( -1 );

   iCount = 0;

   curr = this->ptrNodeListItems;

   while ( curr )
   {
      // find a location at the given item
      if ( curr->getData().iGedID == iGedID )
         return ( iCount );

      iCount++;
      curr = curr->getNext();
   }

   // not found return -1
   return ( -1 );
}

/*************************************************************************
*  Purpose:
*     get data at a given position
**************************************************************************/
GEDATA List::getData( int pos )
{
   int iCount;
   GEDATA err;
   err.iGedID = -1;

   Node *curr;

   // quit if the list is empty
   if ( this->empty() )
      return ( err );

   iCount = 0;

   curr = this->ptrNodeListItems;

   while ( curr )
   {
      // find item at given location
      if ( iCount == pos )
         return ( curr->getData() );

      iCount++;
      curr = curr->getNext();
   }

   // item not found
   return ( err );
}

/*************************************************************************
*  Purpose:
*     get data at a given position
**************************************************************************/
Node *List::getNode( int pos )
{
   int iCount;

   Node *curr;

   // quit if the list is empty
   if ( this->empty() )
      return ( NULL );

   iCount = 0;

   curr = this->ptrNodeListItems;

   while ( curr )
   {
      // find item at given location
      if ( iCount == pos )
         return ( curr );

      iCount++;
      curr = curr->getNext();
   }

   // item not found
   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     check to see if the list is empty
**************************************************************************/
int List::empty()
{
   if ( this )
      return ( !this->iNumItems );

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     return the number of items in the list
**************************************************************************/
int List::getNumitems()
{
   if ( this )
      return ( this->iNumItems );

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Tree Level search
**************************************************************************/
void List::levelPrint( void )
{
   Node *queue[ MAX ];
   Node *temp;
   int front = 0;
   int back = 0;
   int iDepth = 0;
   GEDATA gedData;

   this->setDepth();

   // start from brother cameron
   queue[ back++ ] = this->getNode( this->lookup( 1 ) );

   while ( front != back )
   {
      temp = queue[ front ];
      front = ( front + 1 ) % MAX;

      // use iDepth as a stair step flag for printing data
      if ( iDepth == temp->getDepth() && temp->getDepth() == 0 )
      {
         iDepth++;
         cout << "The Ancestors of " << temp->getData().stGivn << " " 
              << temp->getData().stSurn << ":" << endl;
      }
      else if ( iDepth == temp->getDepth() && temp->getDepth() == 1 )
      {
         iDepth++;
         cout << "Parents:" << endl;
      }
      else if ( iDepth == temp->getDepth() && temp->getDepth() == 2 )
      {
         iDepth++;
         cout << "Grandparents:" << endl;
      }
      else if ( iDepth == temp->getDepth() && temp->getDepth() == 3 )
      {
         iDepth++;
         cout << "Great Grandparents:" << endl;
      }
      else if ( iDepth == temp->getDepth() && temp->getDepth() > 3 )
      {
         iDepth++;
         cout << ( temp->getDepth() - 2 ) << "nd Great Grandparents:" << endl;
      }
      
      // if temp is not null do some stuff for printing
      if ( temp != NULL )
      {
         if ( iDepth != 1 )
         {
            gedData = temp->getData();

            // format the data for screen display
            if ( gedData.stGivn.size() )
            {
               cout << "        " << gedData.stGivn;

               if ( gedData.stSurn.size() )
                  cout << " " << gedData.stSurn;

               if ( gedData.stDate.size() )
                  cout << ", b. " << gedData.stDate;
            }
            else
            {
               cout << "        " << gedData.stSurn;

               if ( gedData.stDate.size() )
                  cout << ", b. " << gedData.stDate;
            }
            cout << endl;
         }

         // push stuff onto the queue
         queue[ back ] = temp->getfather();
         back = ( back + 1 ) % MAX;
         queue[ back ] = temp->getmother();
         back = ( back + 1 ) % MAX;
      }
   }
}

/*************************************************************************
*  Purpose:
*     Set the depth on the nodes for Level order print
**************************************************************************/
void List::setDepth( void )
{
   Node *stack[ MAX ];
   Node *temp;
   int iTop = 0;

   // start from brother cameron
   stack[ iTop++ ] = this->getNode( this->lookup( 1 ) );
   
   // use a stack to set the node depth
   while ( iTop != 0 )
   {
      temp = stack[ --iTop ];

      temp->getfather()->setDepth( temp->getDepth() + 1 );
      temp->getmother()->setDepth( temp->getDepth() + 1 );

      // push data onto the stack
      if ( temp->getfather() )
         stack[ iTop++ ] = temp->getfather();
      if ( temp->getmother() )
         stack[ iTop++ ] = temp->getmother();
   }
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Node::Node()
{
   this->data.iGedID = 0;
   this->data.stDate = "";
   this->data.stGivn = "";
   this->data.stSurn = "";
   this->next = NULL;
   this->father = NULL;
   this->mother = NULL;
   this->iDepth = 0;
}

/*************************************************************************
*  Purpose:
*     return the current data at given point
**************************************************************************/
GEDATA Node::getData()
{
   GEDATA err;
   err.iGedID = -1;

   if ( this )
      return ( this->data );
   
   return ( err );
}

/*************************************************************************
*  Purpose:
*     set the data at the given point
**************************************************************************/
void Node::setData( GEDATA item )
{
   if ( this )
      this->data = item;
}

/*************************************************************************
*  Purpose:
*     get the next node in the list
**************************************************************************/
Node *Node::getNext( void )
{
   if ( this )
      return ( this->next );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     set the next node
**************************************************************************/
void Node::setNext( Node *nNode )
{
   this->next = nNode;
}

/*************************************************************************
*  Purpose:
*     set father node
**************************************************************************/
void Node::setfather( Node *node )
{
   if ( this )
      this->father = node;
}

/*************************************************************************
*  Purpose:
*     set mother node
**************************************************************************/
void Node::setmother( Node *node )
{
   if ( this )
      this->mother = node;
}

/*************************************************************************
*  Purpose:
*     get father node
**************************************************************************/
Node *Node::getfather( void )
{
   if ( this )
      return ( this->father );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     get mother node
**************************************************************************/
Node *Node::getmother( void )
{
   if ( this )
      return ( this->mother );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     set the depth
**************************************************************************/
void Node::setDepth( int depth )
{
   if ( this )
      this->iDepth = depth;
}

/*************************************************************************
*  Purpose:
*     get the depth
**************************************************************************/
int Node::getDepth( void )
{
   if ( this )
      return ( this->iDepth );

   return ( 0 );
}
