/***********************************************************************
* Program:
*    Assignment 04, Queue
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create and implement a Queue then use it in an airport simulator.
***********************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

#define MAXQUEUE 500

/*************************************************************
*   NAME: Brother Cameron
*
*   PURPOSE:
*     Class definition for a queue (arrays)
*************************************************************/
class Queue
{
   private:
      int front;              // --- index of front of queue
      int back;               // --- index of back of queue
      int maxSize;            // --- max storage capacity of array
      int numItems;           // --- number of items currently in queue
      int *queueItems;        // --- array containing queue items

   public:
      Queue( int = 100 );     // --- constructor
      ~Queue(void);           // --- destructor
      void insert( int item );// --- insert item into back of queue
      int remove( void );     // --- remove item into front of queue
      int empty( void );      // --- returns 1 if queue is empty, 0 otherwise
      int full( void );       // --- returns 1 if queue is full, 0 otherwise
};

/*************************************************************
*   NAME: Brother Cameron
*
*   PURPOSE:
*     Class definition for a random functions
*************************************************************/
class Random
{
   public:
      Random();

      /* --- Get next integer in range low-high --- */
      int nextInt( int low, int high );
      int poissonRandom( double expected );
};

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( void )
{
   int iCurrentTime  = 1;  // current time index
   int iTotalITime   = 0;  // runway idle time count

   int iTotalPlanes  = 0;  // total number of planes processed

   int iTotalALand   = 0;  // total number allowed to land
   int iTotalDLand   = 0;  // total number refused landing
   int iAvgWaitLand  = 0;  // wait time land

   int iTotalATOff   = 0;  // total number allowed to takeoff
   int iTotalDTOff   = 0;  // total number refused takeoff
   int iAvgWaitTOff  = 0;  // wait time takeoff

   int icPlane    = 0;     // number of planes to make
   int icPlanes   = 0;     // random number of planes to make

   int iEndTime   = 0;     // user provided max time to iterate

   double rSeed1  = -1;    // user provided random seed
   double rSeed2  = -1;    // user provided random seed

   Random rand;            // random number generator

   Queue landingQueue( 5 );// landing queue
   Queue takeoffQueue( 5 );// take off queue

   cout << endl;

   // user entered value must be 1 or greater
   while ( iEndTime <= 0 )
   {
      cout << "Units of time the simulation will run: ";
      cin >> iEndTime;
   }

   // the initial seed value must be between 0 and 1
   while ( rSeed1 > 1 || rSeed1 < 0 )
   {
      cout << "Expected number of arrivals per time unit: ";
      cin >> rSeed1;
   }

   // the initial seed value must be between 0 and 1
   while ( rSeed2 > 1 || rSeed2 < 0 )
   {
      cout << "Expected number of take offs per time unit: ";
      cin >> rSeed2;
   }

   // main iteration loop
   for ( iCurrentTime = 1; iCurrentTime <= iEndTime; iCurrentTime++ )
   {
      // create planes
      icPlanes = rand.poissonRandom( rSeed1 );
      
      // add the planes created to the queue
      for ( icPlane = 0; icPlane < icPlanes; icPlane++ )
      {
         iTotalPlanes++;
         // do not add any planes if queue is full
         if ( landingQueue.full() )
         {
            // total planes denied landing
            iTotalDLand++;
         }
         else
         {
            // insert the time the plane was created
            // the space used indicates a plane is there
            landingQueue.insert( iCurrentTime );
         }
      }

      // create planes
      icPlanes = rand.poissonRandom( rSeed2 );

      // add the planes created tot he queue
      for ( icPlane = 0; icPlane < icPlanes; icPlane++ )
      {
         iTotalPlanes++;
         // do not add any planes if queue is full
         if ( takeoffQueue.full() )
         {
            // total planes denied takeoff
            iTotalDTOff++;
         }
         else
         {
            // insert the time the plane was created
            // the space used indicates a plane is there
            takeoffQueue.insert( iCurrentTime );
         }
      }

      if ( !landingQueue.empty() )
      {
         iTotalALand++;
         iAvgWaitLand += iCurrentTime - landingQueue.remove();
      }
      else if ( !takeoffQueue.empty() )
      {
         iTotalATOff++;
         iAvgWaitTOff += iCurrentTime - takeoffQueue.remove();
      }
      else
      {
         iTotalITime++;
      }
   }

   // set display for floating point values
   cout.setf( ios::fixed );
   cout.setf( ios::showpoint );
   cout.precision( 2 );

   /* the out put for display to the user */
   cout << endl << endl;
   cout << "Total number of planes processed: " << iTotalPlanes << endl;
   cout << "Number of planes landed: " << iTotalALand << endl;
   cout << "Number of planes taken off: " << iTotalATOff << endl;

   // find the number of planes left to land
   icPlanes = 0;
   for ( ; !landingQueue.empty(); landingQueue.remove() )
      icPlanes++;
   cout << "Number left read to land: " << icPlanes << endl;

   // find the number of planes left to takeoff
   icPlanes = 0;
   for ( ; !takeoffQueue.empty(); takeoffQueue.remove() )
      icPlanes++;
   cout << "Number left ready to take off: " << icPlanes << endl;

   cout << "Number of planes refused use: " << iTotalDLand << endl;

   if ( iEndTime )
   {
      cout << "Percentage of time runway idle: " << 
            ( ( double )iTotalITime / ( double )iEndTime ) * 
            100 << "%" << endl;
   }
   else
      cout << "Percentage of time runway idle: 0.00%" << endl; 
            
   if ( iTotalALand )
   {
      cout << "Average wait time to land: " << 
            ( ( double )iAvgWaitLand / ( double )iTotalALand ) << endl;
   }
   else
      cout << "Average wait time to land: 0.00" << endl;

   if ( iTotalDTOff )
   {
      cout << "Average wait time to take off: " << 
            ( ( double )iAvgWaitTOff / ( double )iTotalDTOff ) << endl;
   }
   else
      cout << "Average wait time to take off: 0.00" << endl;
   /* the out put for display to the user */

   return ( 1 );
}

/*************************************************************************
*  Purpose:
*     Create the initial queue
**************************************************************************/
Queue::Queue( int s )    
{
   if ( s > MAXQUEUE )
   {
      maxSize = MAXQUEUE;
      cout << "Error: queue size too big, setting to " << MAXQUEUE << endl;
   }

   maxSize = s > 0 ? s : 100;
   numItems = 0;
   back = front = maxSize - 1;
   queueItems = new int[ maxSize ];
}

/*************************************************************************
*  Purpose:
*     destroy the queue
**************************************************************************/
Queue::~Queue( void )
{
   delete queueItems;
}

/*************************************************************************
*  Purpose:
*     if the queue is empty
**************************************************************************/
int Queue::empty( void )
{
   return ( numItems == 0 );
}

/*************************************************************************
*  Purpose:
*     if the queue is full
**************************************************************************/
int Queue::full( void )
{
   return ( numItems == maxSize );
}

/*************************************************************************
*  Purpose:
*     insert a record into queue
**************************************************************************/
void Queue::insert( int item )
{
   // --- check for overflow
   if (full())
   {
      cout << "Queue overflow" << endl;
      exit(1);
   }

   queueItems[ back ] = item;
   back = ( back + 1 ) % maxSize;
   numItems++;
}

/*************************************************************************
*  Purpose:
*     Remote item from queue
**************************************************************************/
int Queue::remove( void )
{
   int temp;

   if (empty())
   {
      cout << "queue underflow" << endl;
      exit( 1 );
   }

   temp = queueItems[ front ];
   front = ( front + 1 ) % maxSize;
   numItems--;

   return ( temp );
}

/*********************************************************
*
*    FUNCTION: Random
*
*  PARAMETERS: None
*
*  PURPOSE: Random constructor.  Sets the random number
*              seed to the current time.  The srand function
*              is provided by stdlib.h and time by time.h
*              Passing NULL to the time function returns
*              the current time (in clock ticks) and this
*              is then passed to srand.
*
*  USAGE: Creates a random object to generate random numbers
*              
*              Random r1
*
*********************************************************/
Random::Random()
{
   srand( ( int ) time ( NULL ) );
}

/*********************************************************
*
*    FUNCTION: nextInt
*
*  PARAMETERS: low - smallest number in range
*              high - largest number in range
*
*  PURPOSE: 
*     This function does the following:
*                1. Generate a real number between 0 and 1 
*                   by calling rand() and dividing by
*                   the constant RAND_MAX + 1
*                2. Scale this number to the appropriate range
*                   size (high - low)
*                3. Truncate the value to an integer
*                4. Translate the number to the appropriate
*                   starting point.
*
*  USAGE: Assumes random object has been created.
*               This call will create 1 random number between
*               1 and 50.
*
*               number = r1.nextInt(1,50)
*  Purpose:
*     This one is to make S.C. happy ;)
*********************************************************/
int Random::nextInt( int low, int high )
{
   int k;
   double d;

   d = ( double )rand() / ( ( double )RAND_MAX + 1 );
   k = ( int )( d * ( high - low + 1 ) );
   return ( low + k );
}

/*********************************************************
*
*  FUNCTION: poissonRandom()
*
*  PARAMETERS: expected - the expected value for the Poisson
*              probability distribution function.
*
*  PURPOSE: 
*     To generate an integer from a Poisson distribution
*
*  USAGE:   Assume a Random object, R, has been created.  
*
*           number = R.poissonRandom(.47)
*
*           This will generate an integer based on a Poisson
*           distribution with an expected value of .47.
*  Purpose:
*     This one is to make S.C. happy ;)
***************************************************************/
int Random::poissonRandom( double expected )
{
   int n = 0;
   double limit;
   double x;

   limit = exp( - expected );
   x = rand() / ( ( double )RAND_MAX + 1 );

   while ( x > limit )
   {
      n++;
      x *= rand() / ( ( double ) RAND_MAX + 1 );
   }

   return n;
}
