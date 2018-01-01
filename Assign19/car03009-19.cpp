/***********************************************************************
* Program:
*    Assignment 19, Graph
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Implement a graph
***********************************************************************/
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*******************************************************************
*  Purpose: 
*     Node Class for creating a graph
*******************************************************************/
class Node
{
   private:
      bool bVisited;       // --- visited
      list < int > links;  // --- edge

   public:
      Node( );                      // --- Creates empty node

      void setLink( unsigned int iPos );  // --- set edge 
      list < int > getLinks( void );      // --- get the edges

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

   public:
      Graph( );
      unsigned int getSize( void ); // return the size of the graph
      void insertVertex( void );
      void insertEdge( unsigned int vertex, unsigned int edge );
      void print( void );
};

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( void )
{
   Graph g;

   for ( int iCount = 0; iCount < 6; iCount++ )
      g.insertVertex();

   g.insertEdge( 1, 2 );
   g.insertEdge( 1, 4 );
   g.insertEdge( 1, 5 );
   g.insertEdge( 2, 3 );
   g.insertEdge( 2, 4 );
   g.insertEdge( 3, 3 );
   g.insertEdge( 4, 2 );
   g.insertEdge( 4, 3 );
   g.insertEdge( 6, 2 );
   g.insertEdge( 6, 3 );

   // display the contents
   g.print();

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
*     Print the contents of the graph
**************************************************************************/
void Graph::print( void )
{
   list < int > links;

   for ( unsigned int i = 1; i < this->vList.size(); i++ )
   {
      cout << "Node " << i << " -> ";
      links = vList[ i ].getLinks();

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
*     Insert the vertex
**************************************************************************/
void Graph::insertVertex( void )
{
   Node item;
   this->vList.push_back( item );
}

/*************************************************************************
*  Purpose:
*     Insert an edge to a vertex
**************************************************************************/
void Graph::insertEdge( unsigned int vertex, unsigned int edge )
{
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
   this->links.push_back( edge );
}
