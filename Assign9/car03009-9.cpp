/***********************************************************************
* Program:
*    Assignment 09, Linked Lists
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Use the node.h as the template for creating a linked list of integers
***********************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

/*******************************************************************
*
*     FILE: node.h
*
*  PURPOSE: 
*     Contains the class definition of a Node and a List
*******************************************************************/
class Node
{
   private:
      int data;                // --- data in each node
      Node *next;              // --- pointer to next node

   public:
      Node();                  // --- Creates empty node
      Node *getNext();         // --- returns next pointer of a node
      int getData();           // --- returns data of a node
      void setData(int item);  // --- stores item in data member of 
                               //         current node
      void setNext(Node *node); // --- sets next to point to node
};

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iReadData;
   ifstream ifile;

   Node *hNode;   // Head Node
   Node *cNode;   // Current Node
   Node *tNode;   // Temp Node

   hNode = cNode = tNode = NULL;

   // check for file input
   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the file contents and put them in the vector
         while ( ifile >> iReadData )
         {
            // check for a valid head Node
            if ( hNode )
            {
               // create a new node record
               tNode = new Node;
               tNode->setData( iReadData );

               // set the current node to the head of the list
               cNode = hNode;
               while ( cNode )
               {
                  // where the actual test of c <= t is
                  if ( cNode->getData() <= iReadData )
                  {
                     // check to see if there is a next node
                     // verify that we are in the middle of the list
                     // that c <= t >= c-next
                     if ( cNode->getNext() && 
                           cNode->getNext()->getData() >= iReadData )
                     {
                        // set the temp node = to the current next node
                        tNode->setNext( cNode->getNext() );
                        
                        // set the current node = to the temp node
                        cNode->setNext( tNode );
                        break;
                     }
                     else if ( cNode->getNext() == NULL )
                     {
                        // were at the end of the list just add it
                        cNode->setNext( tNode );
                        break;
                     }
                  }
                  else
                  {
                     // check to see if the current node is the first node
                     if ( cNode == hNode )
                     {
                        // set the current node as the next node
                        tNode->setNext( cNode );
                        
                        // set the head node = to the temp node
                        hNode = tNode;
                        break;
                     }
                  }

                  // get the next record for walking the list
                  cNode = cNode->getNext();
               }
            }
            else
            {
               // allocate memory for the head node
               cNode = new Node;
               hNode = cNode;

               // set the data for the head node
               cNode->setData( iReadData );
            }
         }

         // set the current node to the head node
         cNode = hNode;
         while ( cNode )
         {
            cout << cNode->getData() << " ";
            // get the next node in the list for walking the list
            cNode = cNode->getNext();
         }

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
      cout << "usage: assign9 infile" << endl;
   }

   ifile.close();
   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Node::Node()
{
   this->data = 0;
   this->next = NULL;
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
   this->next = nNode;
}
