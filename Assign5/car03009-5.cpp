/***********************************************************************
* Program:
*    Assignment 05, Deque
*    Brother Cameron, CS 235
* Author:
*    Brother Michael Carey
* Summary:
*    Create and implement a Deque for use in a stock calculator
***********************************************************************/

#include <iostream>
#include <fstream>
#include <deque>
#include <string>

using namespace std;

struct STOCKS
{
   int shares;
   double price;
};

/*************************************************************************
*  Purpose:
*     Main Program entry point
**************************************************************************/
int main( int argc, char *argv[] )
{
   unsigned int iCount;
   int sTransSwitch;
   double dProfit;
   double dTotProfit;

   int iSharesCount;

   ifstream ifile;

   string readFile;
   string filePart;

   STOCKS stTrans;
   STOCKS stSell;

   deque < STOCKS > dStocks;

   dTotProfit = 0;

   if ( argc > 1 )
   {
      // set display for floating point values
      cout.setf( ios::fixed );
      cout.setf( ios::showpoint );
      cout.precision( 2 );

      ifile.open( argv[ 1 ] );

      if ( ifile.is_open() )
      {
         while ( ifile )
         {
            sTransSwitch = 0;

            getline( ifile, readFile );

            // Parse the first word from the file
            filePart = "";
            for ( iCount = 0; iCount < readFile.length(); iCount++ )
            {
               if ( readFile[ iCount ] == ' ' )
               {
                  iCount++;
                  break;
               }
               else
                  filePart += readFile[ iCount ];
            }
            
            // Set the buy or sell flag
            if ( filePart == "BUY" )
               sTransSwitch = 1;
            else if ( filePart == "SELL" )
               sTransSwitch = -1;
            else
               sTransSwitch = 0;

            // parse the shares amount
            filePart = "";            
            for ( ; iCount < readFile.length(); iCount++ )
            {
               if ( readFile[ iCount ] == ' ' )
               {
                  iCount++;
                  break;
               }
               else
                  filePart += readFile[ iCount ];
            }

            // store off the shares found
            stTrans.shares = atoi( filePart.c_str() );

            // parse the price per share amount
            filePart = "";
            for ( ; iCount < readFile.length(); iCount++ )
            {
               if ( readFile[ iCount ] == ' ' )
               {
                  iCount++;
                  break;
               }
               else
                  filePart += readFile[ iCount ];
            }

            // store off the price per share amount
            stTrans.price = atof( filePart.c_str() );

            if ( sTransSwitch == 1 )
            {
               // buying stock push it onto the queue
               cout << "Bought " << stTrans.shares << " shares at $" <<
                  stTrans.price << endl;

               dStocks.push_back( stTrans );
            }
            else if ( sTransSwitch == -1 && !dStocks.empty() )
            {
               iSharesCount = stTrans.shares;
               dProfit = 0;

               // check to see if the the deque is not empty 
               while ( !dStocks.empty() && iSharesCount )
               {
                  stSell = dStocks[ 0 ];
                  dStocks.pop_front();

                  // sell some shares adjust if needed
                  if ( stSell.shares <= iSharesCount )
                  {
                     dProfit += stSell.shares * 
                        ( stTrans.price - stSell.price );
                     iSharesCount -= stSell.shares;
                  }
                  else if ( stSell.shares > iSharesCount )
                  {
                     dProfit += iSharesCount * 
                        ( stTrans.price - stSell.price );

                     stSell.shares -= iSharesCount;
                     dStocks.push_front( stSell );
                     iSharesCount = 0;
                  }
               }

               // add up the profit
               dTotProfit += dProfit;

               // format out put
               if ( dProfit >= 0 )
                  cout << "Sold " << stTrans.shares << " shares at $" << 
                     stTrans.price << " for a profit of $" << dProfit << endl;
               else
                  cout << "Sold " << stTrans.shares << 
                     " shares at $" << stTrans.price << 
                     " for a profit of $(" << ( dProfit * -1 ) << ")" << endl;
            }
         }

         cout << endl;
         cout << "Total Profit: $" << dTotProfit << endl;
         cout << endl;
         cout << "Unsold Shares" << endl;

         // show the rest of the contents of the deque
         while ( !dStocks.empty() )
         {
            stTrans = dStocks[ 0 ];
            dStocks.pop_front( );
            cout << "   " << stTrans.shares << " shares bought for $" << 
               stTrans.price << endl;
         }
      }
      else
      {
         cout << "File " << argv[ 1 ] << " failed to open" << endl;
         ifile.close();
         return ( 1 );
      }
   }

   ifile.close();
   return ( 0 );
}
