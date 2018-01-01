/***********************************************************************
* Program:
*    Assignment 21, Graph Searching
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Implement a graph then search it
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
      unsigned int data;
      list < unsigned int > weight;
      list < unsigned int > links;  // --- edge

   public:
      Node( );                      // --- Creates empty node

      void setLink( unsigned int iPos );  // --- set edge 
      list < unsigned int > getLinks( void );      // --- get the edges
      void setWeight( unsigned int iData );
      list < unsigned int > getWeight( void );

      void setData( unsigned int iData );
      unsigned int getData( void );
      void setStatus( bool bStat );
      bool getStatus( void );
};

/*************************************************************************
*  Purpose:
*     Graph class
**************************************************************************/
class Graph
{
   private:
      vector < Node > vList;
      vector < vector < unsigned int > > distGraph;
      void resetGraph( void );
      void displayPath( unsigned int iPos );

   public:
      Graph( );
      unsigned int getSize( void ); // return the size of the graph
      void insertVertex( unsigned int iData );
      void insertEdge( unsigned int vertex, 
                       unsigned int edge, 
                       unsigned int weight );
      void print( void );
      void printDepth( unsigned int iStart );
      void printBreadth( unsigned int iStart );
      void findShortestPath( unsigned int iStart, unsigned int iEnd );
};

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   bool bFirst;
   bool bSwap;

   int ivertex;
   int iedge;
   int iweight;
   int iTemp;
   
   unsigned int j = 0;
   unsigned int iStart = 0;
   unsigned int iEnd = 0;

   string stReadLine;
   char stTemp[ 10 ];

   ifstream ifile;

   Graph g;

   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the data in
         while ( !ifile.eof() )
         {
            // get a line of text from the file
            getline( ifile, stReadLine );

            // flags used for reading in the numbers
            bFirst = bSwap = false;
            
            // resize the string arrays
            stReadLine.reserve();
            
            j = 0;
            // Style checker does it again...
            for ( unsigned int i = 0; i < stReadLine.size(); i++, j++ )
            {
               // copy out parts of the data to look at
               stTemp[ j ] = stReadLine[ i ];
               stTemp[ j + 1 ] = '\0';
               
               // look for the parsing elements
               if ( stTemp[ j ] == 0x20 || i >= stReadLine.size() - 1 )
               {
                  //look for bad chars of expected types and remove them
                  if ( stTemp[ j ] == 0x20 )
                     stTemp[ j ] = '\0';

                  // get the integer value
                  iTemp = atoi( stTemp );
                  j = ( unsigned int ) -1;

                  // the first vertex value
                  if ( !bFirst )
                  {
                     // used to find first vertex
                     bFirst = !bFirst;
                     ivertex = iTemp;
                     g.insertVertex( ivertex );
                  }
                  else if ( !bSwap )
                  {
                     // toggle bSwap;
                     bSwap = !bSwap;
                     iedge = iTemp;
                  }
                  else if ( bSwap )
                  {
                     // toggle bSwap;
                     bSwap = !bSwap;
                     iweight = iTemp;
                     // insert the data into the graph
                     g.insertEdge( ivertex, iedge, iweight );
                  }
               }
            }
         }

         cout << "Starting Node: ";
         cin >> iStart;
         cout << "Ending Node: ";
         cin >> iEnd;

         // display the contents
         g.findShortestPath( iStart, iEnd );
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
      cout << "usage: assign21 infile" << endl;
      exit( 1 );
   }

   ifile.close();

   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
Graph::Graph( )
{
   Node item;
   this->distGraph.clear();
   this->vList.clear();
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

   list < unsigned int > links;
   list < unsigned int > weight;


   // go through all the nodes.
   for ( unsigned int i = 1; i < this->vList.size(); i++ )
   {
      cout << "Node " << i << " -> ";
      cout << vList[ i ].getData() << " ";
      links = vList[ i ].getLinks();
      weight = vList[ i ].getWeight();

      // go through the links
      while ( !links.empty() )
      {
         cout << links.front() << " " << weight.front();
         links.pop_front();
         weight.pop_front();

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
   list < unsigned int > links;
   list < unsigned int > weight;
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
         vList[ tNode->getData() ].setStatus( true );

         cout << tNode->getData();
         links = tNode->getLinks();
         weight = tNode->getWeight();

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
   list < unsigned int > links;
   list < unsigned int > weight;
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
         vList[ tNode->getData() ].setStatus( true );

         cout << tNode->getData();
         links = tNode->getLinks();
         weight = tNode->getWeight();

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
*     Find the shortest path given a starting location
**************************************************************************/
void Graph::findShortestPath( unsigned int iStart, unsigned int iEnd )
{
   int link;
   int weight;
   int vIndex;
   unsigned int setDist;

   list < unsigned int > links;
   list < unsigned int > weights;

   vector < unsigned int > iTempVec;

   // use an unsigned int, when set to -1 it rolls to size of( unsigned int )
   setDist = ( unsigned int ) -1;

   // create the second graph
   for ( unsigned int i = 0; i < this->vList.size(); i++ )
   {
      // clear the memory
      iTempVec.clear();
      // insert the record
      iTempVec.push_back( i );
      iTempVec.push_back( 0 );
      iTempVec.push_back( setDist );
      iTempVec.push_back( 0 );

      distGraph.push_back( iTempVec );
   }

   // set the first vertex to 0 on distance
   distGraph[ iStart ][ 2 ] = 0;

   // infinite loop
   while ( true )
   {
      // once again set to size of( unsigned int )
      setDist = ( unsigned int ) -1;
      for ( unsigned int i = 1; i < distGraph.size(); i++ )
      {
         // look for the distance in the graph
         if ( distGraph[i][1] == 0 && distGraph[i][2] < setDist )
         {
            // get that distance
            setDist = distGraph[i][2];
            vIndex = i;
         }
      }

      // if the size is size of( unsigned int ) then we have
      // changed nothing. break;
      if ( setDist == ( unsigned int ) -1 )
         break;

      // set the "known" status to 1
      distGraph[vIndex][1] = 1;

      // get the list of edges or links
      links = vList[vIndex].getLinks();
      // get the weight for each edge
      weights = vList[vIndex].getWeight();

      while ( !links.empty() )
      {
         // get the edge and the weight from the list
         link = links.front();
         weight = weights.front();

         links.pop_front();
         weights.pop_front();

         // check to see if it has been visited yet
         if ( ( distGraph[link][1] == 0 ) )
         {
            // check it weight
            if ( ( distGraph[vIndex][2] + weight ) < distGraph[link][2] )
            {
               // make the appropriate adjustments to the node
               distGraph[link][2] = distGraph[vIndex][2] + weight;
               distGraph[link][3] = vIndex;
            }
         }
      }
   }

   // display the path
   this->displayPath( iEnd );
   cout << iEnd << endl;
}

/*************************************************************************
*  Purpose:
*     Display the shortest path
**************************************************************************/
void Graph::displayPath( unsigned int iPos )
{
   unsigned int pPos = this->distGraph[iPos][3];

   // find the position
   if ( this->distGraph[ iPos ][3] != 0 )
      this->displayPath( pPos );
   
   if ( pPos != 0 )
      cout << pPos << " to ";
}

/*************************************************************************
*  Purpose:
*     Private function to Reset the node visited status
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
void Graph::insertVertex( unsigned int iData )
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
void Graph::insertEdge( unsigned int vertex, 
                        unsigned int edge, 
                        unsigned int weight )
{
   if ( this )
   {
      this->vList[ vertex ].setLink( edge );
      this->vList[ vertex ].setWeight( weight );
   }
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
*     set the edge in the list
**************************************************************************/
void Node::setLink( unsigned int edge )
{
   if ( this )
      this->links.push_back( edge );
}

/*************************************************************************
*  Purpose:
*     get the list of links as a copy
**************************************************************************/
list < unsigned int > Node::getLinks( void )
{
   if ( this )
      return ( this->links );
}

/*************************************************************************
*  Purpose:
*     Set a particular weight
**************************************************************************/
void Node::setWeight( unsigned int iWeight )
{
   if ( this )
      this->weight.push_back( iWeight );
}

/*************************************************************************
*  Purpose:
*     get the weight list
**************************************************************************/
list < unsigned int > Node::getWeight( void )
{
   if ( this )
      return ( this->weight );
}

/*************************************************************************
*  Purpose:
*     Set the data
**************************************************************************/
void Node::setData( unsigned int iData )
{
   if ( this )
      this->data = iData;
}

/*************************************************************************
*  Purpose:
*     get the data
**************************************************************************/
unsigned int Node::getData( void )
{
   if ( this )
      return ( this->data );
 
   return ( '\0' );
}
