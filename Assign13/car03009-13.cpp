/***********************************************************************
* Program:
*    Assignment 13, Implement a BTree class
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create a usable BTree class
***********************************************************************/
#include <iostream>
#include "tree.h"

using namespace std;

const unsigned int MAX = 100;

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
*     Get the data at the current node
**************************************************************************/
int BTree::Get_Data( void )
{
   if ( this )
      return ( this->data );

   return ( -1 );
}

/*************************************************************************
*  Purpose:
*     Set the data at the current node
**************************************************************************/
void BTree::Set_Data( int iData )
{
   if ( this )
      this->data = iData;
}

/*************************************************************************
*  Purpose:
*     Return the parent node
**************************************************************************/
BTree *BTree::Parent( void )
{
   if ( this )
      return ( this->parent );
   
   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Return the left node
**************************************************************************/
BTree *BTree::LChild( void )
{
   if ( this )
      return ( this->left );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Return the right node
**************************************************************************/
BTree *BTree::RChild( void )
{
   if ( this )
      return ( this->right );

   return ( NULL );
}

/*************************************************************************
*  Purpose:
*     Insert a node at the given location for the left
**************************************************************************/
void BTree::Insert_Left( int iData )
{
   if ( this && this->left == NULL )
   {
      this->left = new BTree( iData );
      this->left->parent = this;
   }
   else if ( this && this->left != NULL )
   {
      BTree *tmp = new BTree( iData );

      tmp->parent = this->parent;
      this->parent = tmp;
      tmp->left = this;
      tmp->parent->left = tmp;
   }
}

/*************************************************************************
*  Purpose:
*     Insert a node at the given location for the right
**************************************************************************/
void BTree::Insert_Right( int iData )
{
   if ( this && this->right == NULL )
   {
      this->right = new BTree( iData );
      this->right->parent = this;
   }
   else if ( this && this->right != NULL )
   {
      BTree *tmp = new BTree( iData );

      tmp->parent = this->parent;
      this->parent = tmp;
      tmp->right = this;
      tmp->parent->right = tmp;
   }
}

/*************************************************************************
*  Purpose:
*     Graft in a tree on the left node
**************************************************************************/
void BTree::Set_Left( BTree *tree )
{
   if ( this && this->left == NULL )
   {
      this->left = tree;
      tree->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Graft in a tree on the right node
**************************************************************************/
void BTree::Set_Right( BTree *tree )
{
   if ( this && this->right == NULL )
   {
      this->right = tree;
      tree->parent = this;
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in Infix processing
**************************************************************************/
void BTree::Infix()
{
   if ( this )
   {
      left->Infix();
      cout << data << " ";
      right->Infix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in Prefix processing
**************************************************************************/
void BTree::Prefix()
{
   if ( this )
   {
      cout << data << " ";
      left->Prefix();
      right->Prefix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in Postfix processing
**************************************************************************/
void BTree::Postfix()
{
   if ( this )
   {
      left->Postfix();
      right->Postfix();
      cout << data << " ";
   }
}

/*************************************************************************
*  Purpose:
*     Tree Level search
**************************************************************************/
void BTree::Level()
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
