/***********************************************************************
* Program:
*    Assignment 20, Graph Searching
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Implement a graph then search it
***********************************************************************/
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/*******************************************************************
*  Purpose: 
*     Node Class for creating a graph
*******************************************************************/
class Node
{
   private:
      bool bVisited;       // --- visited
      char data;
      list < int > links;  // --- edge

   public:
      Node( );                      // --- Creates empty node

      void setLink( unsigned int iPos );  // --- set edge 
      list < int > getLinks( void );      // --- get the edges

      void setData( char cData );
      char getData( void );
      bool getStatus( void );
      void setStatus( bool bStat );
};

/*************************************************************************
*  Purpose:
*     Graph class
**************************************************************************/
class Graph
{
   private:
      vector < Node > vList;
      void resetGraph( void );

   public:
      Graph( );
      unsigned int getSize( void ); // return the size of the graph
      void insertVertex( char iData );
      void insertEdge( unsigned int vertex, unsigned int edge );
      void print( void );
      void printDepth( unsigned int iStart );
      void printBreadth( unsigned int iStart );
};

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( void )
{
   Graph g;

   for ( int iCount = 0; iCount < 9; iCount++ )
      g.insertVertex( ( 'A' + ( char )iCount ) );

   g.insertEdge( 1, 2 );
   g.insertEdge( 1, 4 );
   g.insertEdge( 1, 5 );
   g.insertEdge( 2, 6 );
   g.insertEdge( 3, 2 );
   g.insertEdge( 3, 4 );
   g.insertEdge( 4, 3 );
   g.insertEdge( 4, 8 );
   g.insertEdge( 5, 8 );
   g.insertEdge( 6, 7 );
   g.insertEdge( 6, 9 );
   g.insertEdge( 7, 2 );
   g.insertEdge( 7, 3 );
   g.insertEdge( 9, 8 );

   // display the contents
   g.printBreadth( 1 );
   g.printDepth( 1 );

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Graph::Graph( )
{
   Node item;
   this->vList.push_back( item );
}

/*************************************************************************
*  Purpose:
*     print the contents
**************************************************************************/
void Graph::print( void )
{
   if ( !this )
      return;

   list < int > links;

   // go through all the nodes.
   for ( unsigned int i = 1; i < this->vList.size(); i++ )
   {
      cout << "Node " << i << " -> ";
      cout << vList[ i ].getData() << " ";
      links = vList[ i ].getLinks();

      // go through the links
      while ( !links.empty() )
      {
         cout << links.front();
         links.pop_front();

         if ( !links.empty() )
            cout << ", ";
      }
      cout << endl;
   }
}

/*************************************************************************
*  Purpose:
*     Print the ADT in Breadth visit order
**************************************************************************/
void Graph::printBreadth( unsigned int iStart )
{
   if ( !this && iStart <= this->vList.size() )
      return;

   Node *tNode;
   list < int > links;
   queue < Node * > myQueue;

   // seed the queue
   myQueue.push( &vList[ iStart ] );

   cout << "Breadth-first order: ";

   this->resetGraph();
   // process the queue until empty
   while ( !myQueue.empty() )
   {
      tNode = myQueue.front();
      myQueue.pop();

      // check to see if it was visited.
      if ( !tNode->getStatus() )
      {
         // set the visit status
         vList[ ( tNode->getData() - 'A' ) + 1 ].setStatus( true );

         cout << tNode->getData();
         links = tNode->getLinks();

         // find the list of links to travel
         while ( !links.empty() )
         {
            // get the item
            iStart = links.front();
            // push that node onto the stack
            myQueue.push( &vList[ iStart ] );
            // remove the link from the list
            links.pop_front();
         }
      }
   }

   cout << endl;
}

/*************************************************************************
*  Purpose:
*     Print the ADT in Depth visit order
**************************************************************************/
void Graph::printDepth( unsigned int iStart )
{
   if ( !this && iStart <= this->vList.size() )
      return;

   Node *tNode;
   list < int > links;
   stack < Node * > myStack;

   // seed the stack
   myStack.push( &vList[ iStart ] );

   cout << "Depth-first order: ";

   // reset the graph visit status
   this->resetGraph();

   // while the stack is not empty run
   while ( !myStack.empty() )
   {
      // get the node
      tNode = myStack.top();
      // remove the node
      myStack.pop();

      // check visit order
      if ( !tNode->getStatus() )
      {
         // get the correct node to set visit status
         vList[ ( tNode->getData() - 'A' ) + 1 ].setStatus( true );

         cout << tNode->getData();
         links = tNode->getLinks();

         // find the list of links to travel
         while ( !links.empty() )
         {
            // get the item
            iStart = links.front();
            // push that node onto the stack
            myStack.push( &vList[ iStart ] );
            // remove the link from the list
            links.pop_front();
         }
      }
   }

   cout << endl;
}

/*************************************************************************
*  Purpose:
*     Reset the node visited status
**************************************************************************/
void Graph::resetGraph( void )
{
   if ( this )
      for ( unsigned int iCount = 0; iCount < this->vList.size(); iCount++ )
         vList[ iCount ].setStatus( false );
}

/*************************************************************************
*  Purpose:
*     Insert the vertex
**************************************************************************/
void Graph::insertVertex( char iData )
{
   if ( this )
   {
      Node item;
      item.setData( iData );
      this->vList.push_back( item );
   }
}

/*************************************************************************
*  Purpose:
*     Insert an edge to a vertex
**************************************************************************/
void Graph::insertEdge( unsigned int vertex, unsigned int edge )
{
   if ( this )
      if ( vertex <= this->vList.size() && edge <= this->vList.size() )
         this->vList[ vertex ].setLink( edge );
}

/*************************************************************************
*  Purpose:
*     Return the number of vertexes
**************************************************************************/
unsigned int Graph::getSize( void )
{
   if ( this )
      return ( this->vList.size() );

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Node::Node( )
{
   this->bVisited = false;
   this->data = '\0';
}

/*************************************************************************
*  Purpose:
*     get visited Status
**************************************************************************/
bool Node::getStatus( void )
{
   if ( this )
      return ( this->bVisited );

   return ( false );
}

/*************************************************************************
*  Purpose:
*     Set the visited status
**************************************************************************/
void Node::setStatus( bool bStat )
{
   if ( this )
      this->bVisited = bStat;
}

/*************************************************************************
*  Purpose:
*     get the list of links as a copy
**************************************************************************/
list < int > Node::getLinks( void )
{
   if ( this )
      return ( this->links );
}

/*************************************************************************
*  Purpose:
*     set the edge in the list
**************************************************************************/
void Node::setLink( unsigned int edge )
{
   if ( this )
      this->links.push_back( edge );
}

/*************************************************************************
*  Purpose:
*     Set the data
**************************************************************************/
void Node::setData( char cData )
{
   if ( this )
      this->data = cData;
}

/*************************************************************************
*  Purpose:
*     get the data
**************************************************************************/
char Node::getData( void )
{
   if ( this )
      return ( this->data );
 
   return ( '\0' );
}
