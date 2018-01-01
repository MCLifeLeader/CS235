/***********************************************************************
* Program:
*    Assignment 18, Merge Sorting
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Implement a merge sort using a linked list
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*******************************************************************
*  PURPOSE: 
*     Node Class for a doubly linked list
*******************************************************************/
class Node
{
   private:
      int data;                // --- data in each node
      Node *next;              // --- pointer to next node
      Node *prev;

   public:
      Node();                 // --- Creates empty node
      Node *getPrev();        // --- returns prev pointer of a node
      Node *getNext();        // --- returns next pointer of a node
      int getData();          // --- returns data of a node
      void setData(int item); // --- stores item in data member of 
                                //     current node
      void setNext(Node *node); // --- sets next to point to node
      void setPrev(Node *node); // --- sets prev to point to node
};

/*******************************************************************
*  PURPOSE: 
*     List Class for handling and managing a doubly linked list
*******************************************************************/
class List
{
   private:
      int iNumItems;
      Node *ptrNodeListItems;

   public:
      List();
      void insert(int item, int pos);
      void deleteNode(int pos);
      int lookup(int item);
      int getData(int pos);
      void setData( int item, int pos );
      int empty(void);
      int getNumitems(void);
      void mergSort( int iLow, int iHigh );
};

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iReadData;
   ifstream ifile;

   List mergList;

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
            mergList.insert( iReadData, mergList.getNumitems() + 1 );

         // do the merg sort
         mergList.mergSort( 0, mergList.getNumitems() - 1 );
      
         // print the data out
         for ( int iCount = 0; iCount < mergList.getNumitems(); iCount++ )
            cout << mergList.getData( iCount ) << " ";

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
      cout << "usage: assign18 infile" << endl;
      exit( 1 );
   }

   ifile.close();

   return ( 0 );
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
*     Do the Merge Sort
**************************************************************************/
void List::mergSort( int iLow, int iHigh )
{
   int iMid;            // --- index of where to split the list
   int endlow;          // --- last index of left list
   int starthigh;       // --- first index of right list
   int temp;            // --- temporary storage location

   // --- base case for recursion
   if ( iLow >= iHigh )
      return;

   // --- split list
   iMid = ( iLow + iHigh ) / 2;

   // --- recursively merge two lists
   this->mergSort( iLow, iMid );
   this->mergSort( iMid + 1, iHigh );

   // --- merge two sorted lists
   endlow = iMid;
   starthigh = iMid + 1;

   // continue looping until it has completed merging the data
   while ( ( iLow <= endlow ) && ( starthigh <= iHigh ) )
   {
      // compare the data for the swap.
      if ( this->getData( iLow ) <= this->getData( starthigh ) )
         iLow++;
      else
      {
         // put the data into the temp location
         temp = this->getData( starthigh );
         
         // move the data down the row
         for (int i = starthigh - 1; i >= iLow; i-- )
            this->setData( this->getData( i ), i + 1 );

         // set the temp data back into the correct position
         this->setData( temp, iLow );

         // modifiy counters
         iLow++;
         endlow++;
         starthigh++;
      }
   }
}

/*************************************************************************
*  Purpose:
*     Set the data at a position
**************************************************************************/
void List::setData( int item, int pos )
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
*     insert a record at a certain position
**************************************************************************/
void List::insert( int item, int pos )
{
   int iCount;
   bool bInserted;

   // create some temp nodes to work with
   Node *curr;
   Node *temp;
   Node *prev;

   iCount = 0;

   // check to see if the list is empty
   if ( this->empty() )
   {
      // the list was empty create the first head node
      // insert at the head of the list
      this->ptrNodeListItems = new Node;
      this->ptrNodeListItems->setData( item );
      this->iNumItems++;

      return;
   }
   else
   {
      // else just create a temp node
      temp = new Node;
      temp->setData( item );
   }

   prev = curr = this->ptrNodeListItems;

   // are we at the beginning of the list
   if ( pos == 0 )
   {
      // set the previous nodes pointer
      this->ptrNodeListItems->setPrev( temp );
      // set the temp node as the head node
      temp->setNext( this->ptrNodeListItems );
      // set temp as the new head node
      this->ptrNodeListItems = temp;
      this->iNumItems++;

      return;
   }

   bInserted = false;
   while ( curr )
   {
      // check our position
      if ( iCount == pos )
      {
         // insert record at given position
         // set temp's next node to current
         temp->setNext( curr );
         // set prev node's next to temp
         prev->setNext( temp );
         // set the current node prev to temp
         curr->setPrev( temp );
         // set temps node's prev to prev
         temp->setPrev( prev );
         this->iNumItems++;

         return;
      }

      iCount++;
      prev = curr;
      curr = curr->getNext();
   }
   
   // if we're here, a record was not inserted
   if ( bInserted == false )
   {
      // insert at the tail of the list
      prev->setNext( temp );
      temp->setPrev( prev );
      this->iNumItems++;
      return;
   }

   return;
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

      curr->setPrev( NULL );
      prev->setNext( NULL );

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
         curr->setPrev( prev );
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
int List::lookup( int item )
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
      if ( curr->getData() == item )
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
int List::getData( int pos )
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
      // find item at given location
      if ( iCount == pos )
         return ( curr->getData() );

      iCount++;
      curr = curr->getNext();
   }

   // item not found
   return ( -1 );
}

/*************************************************************************
*  Purpose:
*     check to see if the list is empty
**************************************************************************/
int List::empty()
{
   return ( !this->iNumItems );
}

/*************************************************************************
*  Purpose:
*     return the number of items in the list
**************************************************************************/
int List::getNumitems()
{
   return ( this->iNumItems );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Node::Node()
{
   this->data = 0;
   this->next = NULL;
   this->prev = NULL;
}

/*************************************************************************
*  Purpose:
*     return the current data at given point
**************************************************************************/
int Node::getData()
{
   return ( this->data );
}

/*************************************************************************
*  Purpose:
*     set the data at the given point
**************************************************************************/
void Node::setData( int item )
{
   this->data = item;
}

/*************************************************************************
*  Purpose:
*     get the next node in the list
**************************************************************************/
Node *Node::getNext( void )
{
   return ( this->next );
}

/*************************************************************************
*  Purpose:
*     set the next node
**************************************************************************/
void Node::setNext( Node *nNode )
{
   if ( this && !this->next )
      this->next = nNode;
}

/*************************************************************************
*  Purpose:
*     set the previous node
**************************************************************************/
void Node::setPrev( Node *nNode )
{
   if ( this && !this->prev )
      this->prev = nNode;
}

/*************************************************************************
*  Purpose:
*     get the previous node
**************************************************************************/
Node *Node::getPrev( void )
{
   return ( this->prev );
}
