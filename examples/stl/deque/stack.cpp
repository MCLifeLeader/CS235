/* Program that uses a stack to convert the base-ten
 * representation of a positive integer to base two.
 * Uses the standard C++ stack container.
 *
 * Input:  A positive integer
 * Output: Base-two representation of the number
 *********************************************************/

#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main()
{
   int number;                         // the number to be converted
   int base;
   int remainder;                      // remainder when number is divided by 2
   stack<unsigned> stackOfRemainders;  // stack of remainders   

   while(1)
     {
       cout << "Enter positive integer to convert (0 to quit): ";
       cin >> number;
       if (number == 0)
	 break;
       cout << "Which base: ";
       cin >> base;
       while (number != 0)
	 {
	   remainder = number % base;
	   stackOfRemainders.push(remainder);
	   number /= base;
	 }
       
       cout << "Base two representation: ";
       while (!stackOfRemainders.empty() )
	 {
	   remainder = stackOfRemainders.top();
	   stackOfRemainders.pop();
	   cout << remainder;
	 }
       cout << "\n";
     }
}
