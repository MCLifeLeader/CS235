/***********************************************************************
* Program:
*    Assignment 14, Implement a BSTree class
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create a usable BSTree class to sort the data in
***********************************************************************/
#include <iostream>
#include "tree.h"
#include "bst.h"

using namespace std;

const unsigned int MAX = 100;

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
BST::BST()
{
   this->root = NULL;
}

/*************************************************************************
*  Purpose:
*   Check for empty Tree  
**************************************************************************/
int BST::Empty( void )
{
   if ( this && this->root == NULL )
      return ( 1 );
   else
      return ( 0 );
}

/*************************************************************************
*  Purpose:
*     Search the tree for a given node given a value
**************************************************************************/
BTree *BST::Search( int item )
{
   BTree *ptr = NULL;
   BTree *curr = NULL;

   if ( this && this->root )
   {
      curr = this->root;

      while ( curr )
      {
         if ( curr->Get_Data() == item )
         {
            ptr = curr;
            break;
         }

         if ( curr->Get_Data() >= item )
            curr = curr->LChild();
         else if ( curr->Get_Data() < item )
            curr = curr->RChild();
      }
   }

   return ( ptr );
}

/*************************************************************************
*  Purpose:
*     Insert a node at a given location
**************************************************************************/
void BST::Insert( int item )
{
   BTree *curr = NULL;

   if ( this && this->root == NULL )
      this->root = new BTree( item );
   else
   {
      curr = this->root;

      // traverse the nodes
      while ( curr )
      {
         if ( curr->Get_Data() >= item )
         {
            // move left
            if ( curr->LChild() )
               curr = curr->LChild();
            else
            {
               // insert the item
               curr->Insert_Left( item );
               break;
            }
         }
         else if ( curr->Get_Data() < item )
         {
            // move right
            if ( curr->RChild() )
               curr = curr->RChild();
            else
            {
               // insert the item
               curr->Insert_Right( item );
               break;
            }
         }
      }
   }
}

/*************************************************************************
*  Purpose:
*     Delete a given node
**************************************************************************/
void BST::Delete( int item )
{
   int iData;
   BTree *curr;
   BTree *delNode;

   // find a node in the list
   delNode = curr = this->Search( item );
   
   // check to see if the current node is valid
   if ( curr )
   {
      // we are at the end, just delete
      if ( curr->LChild() == NULL && curr->RChild() == NULL )
      {
         // if there is no parent we are at the head node
         if ( curr->Parent() )
            curr = curr->Parent();

         // Which node is it that we need to delete
         if ( curr->LChild() == delNode )
            curr->Set_Left( NULL );
         else if ( curr->RChild() == delNode )
            curr->Set_Right( NULL );

         // do the actual delete operation
         delete delNode;
      }
      else if ( curr->RChild() )
      {
         // start moving to the correct node to move
         delNode = delNode->RChild();
         // travel to the left until the left child is null
         while ( delNode->LChild() )
            delNode = delNode->LChild();

         // we are at the correct location store the data
         iData = delNode->Get_Data();
         // run the delete operation again on that data
         this->Delete( delNode->Get_Data() );         
         // set the data in the node at the top of the list
         curr->Set_Data( iData );
      }
      else if ( curr->LChild() )
      {
         // move to the left Node
         delNode = delNode->LChild();
         // store off the data
         iData = delNode->Get_Data();
         // delete the left node
         this->Delete( iData );
         // save off the current data
         curr->Set_Data( iData );
      }
   }
}

/*************************************************************************
*  Purpose:
*     Print the tree in using the infix process
**************************************************************************/
void BST::BST_Infix( void )
{
   // check to see if the current node is valid
   if ( this && this->root )
      this->root->Infix();
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
*     Get the data at the current node
**************************************************************************/
int BTree::Get_Data( void )
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
void BTree::Set_Data( int iData )
{
   // check to see if the current node is valid
   if ( this )
      this->data = iData;
}

/*************************************************************************
*  Purpose:
*     Return the parent node
**************************************************************************/
BTree *BTree::Parent( void )
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
BTree *BTree::LChild( void )
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
BTree *BTree::RChild( void )
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
void BTree::Insert_Left( int iData )
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
void BTree::Insert_Right( int iData )
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
void BTree::Set_Left( BTree *tree )
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
void BTree::Set_Right( BTree *tree )
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
*     Visit all the nodes in Infix processing
**************************************************************************/
void BTree::Infix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // move left
      left->Infix();
      // display data
      cout << data << " ";
      // move right
      right->Infix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in Prefix processing
**************************************************************************/
void BTree::Prefix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // show the data
      cout << data << " ";
      // move left
      left->Prefix();
      // move right
      right->Prefix();
   }
}

/*************************************************************************
*  Purpose:
*     Visit all the nodes in Postfix processing
**************************************************************************/
void BTree::Postfix()
{
   // check to see if the current node is valid
   if ( this )
   {
      // move left
      left->Postfix();
      // move right
      right->Postfix();
      // show the data
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
