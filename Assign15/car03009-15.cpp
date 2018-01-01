/***********************************************************************
* Program:
*    Assignment 15, Huffman Codes
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create a Huffman tree and display the data from it.
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const unsigned int MAX = 100;
const unsigned int COUNT = 26;

/*************************************************************************
*  Purpose:
*     Basic BTree Class
**************************************************************************/
class BTree
{
   private:
      int data;          // --- data stored in node of tree
      BTree *left;       // --- pointer to left subtree
      BTree *right;      // --- pointer to right subtree
      BTree *parent;     // --- pointer to the parent node

   public:
      BTree(int = 0);  
      ~BTree(void);
      void insertLeft(int item);
      void insertRight(int item);
      BTree *leftChild(void);  
      BTree *rightChild(void);
      BTree *parentNode(void);
      int getData(void);
      void setData(int item);
      void setLeft(BTree *tree);
      void setRight(BTree *tree);
      void infix(void);
      void prefix(void);
      void postfix(void);
      string encode( BTree *tree );
      //string decode( string code, BTree *tree ); something to do later
      void level(void);
};

/*************************************************************************
*  Purpose:
*     Main program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   int iReadData;
   ifstream ifile;

   int i;
   int j;
   int k;
   int nextElm;
   int leafElm;
   int count = 0;

   BTree *nextElem;
   BTree *headNode;
   BTree **myLetters  = new BTree* [ COUNT + 1 ];
   BTree **myLeafs    = new BTree* [ COUNT + 1 ];

   for ( k = 0; k < COUNT + 1; k++ )
      myLetters[ k ] = myLeafs[ k ] = NULL;

   // check for file input
   if ( argc > 1 )
   {
      // open the file
      ifile.open( argv[ 1 ] );

      // check to see if the file was opened properly
      if ( ifile.is_open() )
      {
         // read the file contents and put them in the vector
         for ( k = 0; ifile >> iReadData; k++ )
         {
            nextElem = new BTree( iReadData );
            myLeafs[ k ] = myLetters[ k ] = nextElem;
         }
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
      cout << "usage: assign15 infile" << endl;
      exit( 1 );
   }

   ifile.close();

   if ( myLetters[ 0 ] != NULL )
   {
      // continue until we reach the last nodes in the list
      while ( count != 2 )
      {
         count = COUNT;

         /***************************BEGIN Insert SORT********************/

         // move NULL items to the end of the list
         for ( i = 0, j = 0; i < COUNT; i++, j++ )
         {
            if ( myLeafs[ i ] == NULL )
               for ( ; i < COUNT && myLeafs[ i ] == NULL; i++ );

            // style checker hates this because I have a ';'
            // at the end of my 'for' statment
            myLeafs[ j ] = myLeafs[ i ];
         }

         // clean up NULL items
         for ( ; j < COUNT; ++j, count-- )
            myLeafs[ j ] = NULL;

         // preform the sort
         for ( k = 0; k < COUNT; k++ )
         {
            for (i = 1; i < k; ++i )
            {
               if ( myLeafs[ i ] != NULL )
               {
                  nextElem = myLeafs[ i ];
                  
                  j = i;

                  nextElm = nextElem->getData();
                  leafElm = myLeafs[ j - 1 ]->getData();
                  
                  for (j = i; ( j > 0 ) && 
                        ( myLeafs[ j - 1 ] != NULL ) && 
                        ( nextElm < leafElm ); j-- )
                  {
                     leafElm = myLeafs[ j - 1 ]->getData();
                     myLeafs[ j ] = myLeafs[ j - 1 ];
                  }
                  myLeafs[ j ] = nextElem;      
               }
            }
         }
         /***************************END Insert SORT**********************/

         nextElem = new BTree( myLeafs[ 0 ]->getData() + 
               myLeafs[ 1 ]->getData() );
         nextElem->setLeft( myLeafs[ 0 ] );
         nextElem->setRight( myLeafs[ 1 ] );

         myLeafs[ 0 ] = NULL;
         myLeafs[ 1 ] = nextElem;
      }

      // We have the head node for our tree
      headNode = myLeafs[ 1 ];

      // display huffman bit codes
      for ( k = 0; k < COUNT; k++ )
         cout << (char)( k + 0x61 ) << " = " << 
            headNode->encode( myLetters[ k ] ) << endl;

   }
   else
   {
      cout << "Error reading data" << endl;
      exit( 1 );
   }
   return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
BTree::BTree( int iData )
{
   this->data = iData;
   this->left = this->right = this->parent = NULL;
}

/*************************************************************************
*  Purpose:
*     Destructor
**************************************************************************/
BTree::~BTree()
{
}

/*************************************************************************
*  Purpose:
*     Encode a Huffman Code
**************************************************************************/
string BTree::encode( BTree *tree )
{
   vector < string > v;
   string code;
   BTree *curr;
   BTree *tcurr;

   code = "";

   tcurr = curr = tree;
   while ( tcurr )
   {
      if ( curr == tcurr->left )
         v.push_back( "1" );
      else if ( curr == tcurr->right )
         v.push_back( "0" );

      curr = tcurr;
      tcurr = curr->parent;
   }

   v.pop_back();

   while ( !v.empty() )
   {
      code += v.back();
      v.pop_back();
   }

   return ( code );
}

/*************************************************************************
*  Purpose:
*     Get the data at the current node
**************************************************************************/
int BTree::getData( void )
{
   // check to see if the current node is valid
   if ( this )
      return ( this->data );

   return ( -1 );
}

/*************************************************************************
*  Purpose:
*     Set the data at the current node
**************************************************************************/
void BTree::setData( int iData )
{
   // check to see if the current node is valid
   if ( this )
      this->data = iData;
}

/*************************************************************************
*  Purpose:
*     Return the parent node
**************************************************************************/
BTree *BTree::parentNode( void )
{
   // check to see if the current node is valid
   if ( this )
      return ( this->parent );
   
   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Return the left node
**************************************************************************/
BTree *BTree::leftChild( void )
{
   // check to see if the current node is valid
   if ( this )
      return ( this->left );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Return the right node
**************************************************************************/
BTree *BTree::rightChild( void )
{
   // check to see if the current node is valid
   if ( this )
      return ( this->right );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Insert a node at the given location for the left
**************************************************************************/
void BTree::insertLeft( int iData )
{
   // check to see if the current node is valid
   if ( this && this->left == NULL )
   {
      this->left = new BTree( iData );
      this->left->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Insert a node at the given location for the right
**************************************************************************/
void BTree::insertRight( int iData )
{
   // check to see if the current node is valid
   if ( this && this->right == NULL )
   {
      this->right = new BTree( iData );
      this->right->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Graft in a tree on the left node
**************************************************************************/
void BTree::setLeft( BTree *tree )
{
   // check to see if the current node is valid
   if ( ( this && this->left == NULL ) || !tree )
   {
      // set the data in the node
      this->left = tree;
      
      // allow for NULL insertion of a node
      if ( tree )
         tree->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Graft in a tree on the right node
**************************************************************************/
void BTree::setRight( BTree *tree )
{
   // check to see if the current node is valid
   if ( ( this && this->right == NULL ) || !tree )
   {
      // set the node value
      this->right = tree;
      
      // allow for NULL insertion of a node
      if ( tree )
         tree->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in infix processing
**************************************************************************/
void BTree::infix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // move left
      left->infix();
      // display data
      cout << data << " ";
      // move right
      right->infix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in prefix processing
**************************************************************************/
void BTree::prefix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // show the data
      cout << data << " ";
      // move left
      left->prefix();
      // move right
      right->prefix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in postfix processing
**************************************************************************/
void BTree::postfix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // move left
      left->postfix();
      // move right
      right->postfix();
      // show the data
      cout << data << " ";
   }
}

/*************************************************************************
*  Purpose:
*     Tree level search
**************************************************************************/
void BTree::level()
{
   BTree *queue[ MAX ];
   BTree *temp;
   int front = 0;
   int back = 0;

   queue[ back++ ] = this;

   while ( front != back )
   {
      temp = queue[ front ];
      front = ( front + 1 ) % MAX;
      if ( temp != NULL )
      {
         cout << temp->data << " ";
         queue[ back ] = temp->left;
         back = ( back + 1 ) % MAX;
         queue[ back ] = temp->right;
         back = ( back + 1 ) % MAX;
      }
   }
}
