#include "list.h"

/*************************************************************************
*  Purpose:
*     Default Constructor
**************************************************************************/
List::List()
{
   this->num_items = 0;
   this->list_items = NULL;
}

/*************************************************************************
*  Purpose:
*     Insert a record at a certain position
**************************************************************************/
void List::Insert( int item, int pos )
{
   int iCount;
   bool bInserted;

   // create some temp nodes to work with
   Node *curr;
   Node *temp;
   Node *prev;

   iCount = 0;

   // check to see if the list is empty
   if( this->Empty() )
   {
      // insert at the head of the list
      this->list_items = new Node;
      this->list_items->set_data( item );
      this->num_items++;

      return;
   }
   else
   {
      // else just create a temp node
      temp = new Node;
      temp->set_data( item );
   }

   prev = curr = this->list_items;

   // are we at the begining of the list
   if( pos == 0 )
   {
      // set the temp node as the head node
      temp->set_next( this->list_items );
      this->list_items = temp;
      this->num_items++;

      return;
   }

   bInserted = false;
   while ( curr )
   {
      // check our position
      if( iCount == pos )
      {
         // insert record at given position
         temp->set_next( curr );
         prev->set_next( temp );
         this->num_items++;

         return;
      }

      iCount++;
      prev = curr;
      curr = curr->get_next();
   }
   
   // if we're here, a record was not inserted
   if( bInserted == false )
   {
      // insert at the tail of the list
      prev->set_next( temp );
      this->num_items++;
      return;
   }

   return;
}

/*************************************************************************
*  Purpose:
*     delete a record at a given position
**************************************************************************/
void List::Delete( int pos )
{
   int iCount;

   Node *prev;
   Node *curr;

   // if the list is not empty we can delete a record
   if( this->Empty() )
      return;

   iCount = 0;
   prev = curr = this->list_items;

   // handles first element
   if( pos == 0 )
   {
      // maintain the head
      this->list_items = curr->get_next();
      this->num_items--;
      delete curr;

      return;
   }

   while( curr )
   {
      // protect vs NULL and check if last node in list
      if( curr && !curr->get_next() )
      {
         // delete a record
         delete curr;
         prev->set_next( NULL );
         this->num_items--;

         return;
      }
      else if( pos == iCount )
      {
         // remove a record from the middle of the list
         prev->set_next( curr->get_next() );
         delete curr;
         this->num_items--;

         return;
      }

      iCount++;
      prev = curr;
      curr = curr->get_next();
   }
   
   return;
}

/*************************************************************************
*  Purpose:
*     look up an item return position of item
**************************************************************************/
int List::Lookup( int item )
{
   int iCount;

   Node *curr;

   // quit if the list is empty
   if( this->Empty() )
      return( -1 );

   iCount = 0;

   curr = this->list_items;

   while ( curr )
   {
      // find a location at the given item
      if( curr->get_data() == item )
         return( iCount );

      iCount++;
      curr = curr->get_next();
   }

   // not found return -1
   return( -1 );
}

/*************************************************************************
*  Purpose:
*     get data at a given position
**************************************************************************/
int List::Get_Data( int pos )
{
   int iCount;

   Node *curr;

   // quit if the list is empty
   if( this->Empty() )
      return( -1 );

   iCount = 0;

   curr = this->list_items;

   while ( curr )
   {
      // find item at given location
      if( iCount++ == pos )
         return( curr->get_data() );

      curr = curr->get_next();
   }

   // item not found
   return( -1 );
}

/*************************************************************************
*  Purpose:
*     check to see if the list is empty
**************************************************************************/
int List::Empty()
{
   return( !this->num_items );
}

/*************************************************************************
*  Purpose:
*     return the number of items in the list
**************************************************************************/
int List::get_numitems()
{
   return( this->num_items );
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
int Node::get_data()
{
   return ( this->data );
}

/*************************************************************************
*  Purpose:
*     set the data at the given point
**************************************************************************/
void Node::set_data( int item )
{
   this->data = item;
}

/*************************************************************************
*  Purpose:
*     get the next node in the list
**************************************************************************/
Node *Node::get_next( void )
{
   return ( this->next );
}

/*************************************************************************
*  Purpose:
*     set the next node
**************************************************************************/
void Node::set_next( Node *nNode )
{
   this->next = nNode;
}
