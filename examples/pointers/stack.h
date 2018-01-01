/* RStackT1.h provides a Stack template.
 *
 * Receives:  Type parameter StackElement
 * Basic operations:
 *   Constructor:  Constructs an empty stack
 *   empty:   Checks if a stack is empty
 *   push:    Modifies a stack by adding a value at the top
 *   top:     Accesses the top stack value; leaves stack unchanged
 *   pop:     Modifies a stack by removing the value at the top
 *   display: Displays all the stack elements
 * Class Invariant:
 *   1. The stack elements (if any) are stored in positions
 *      0, 1, . . ., myTop_ of myArrayPtr.
 *   2. -1 <= myTop_ <= STACK_CAPACITY
 ------------------------------------------------------------------*/

#ifndef RTSTACK1
#define RTSTACK1

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

template <typename StackElement>
class Stack
{

  public:
   Stack(int numElements = 128);
   Stack(const Stack<StackElement> & original);
   ~Stack();
   bool Empty() const;
   void Push(const StackElement & value);
   StackElement Top();
   void Pop();
   void display(ostream & out) const;
   Stack<StackElement> & operator=(const Stack & original);

  private:
   StackElement * myArrayPtr;  // run-time allocated array
   int myCapacity_;            // capacity of stack
   int myTop_;                 // top of stack
};


//*** Definition of class constructor
template <typename StackElement>
Stack<StackElement>::Stack(int numElements)
{
  assert (numElements > 0);   // check precondition
  myCapacity_ = numElements;  // set stack capacity
                              // allocate array of this capacity
  myArrayPtr = new StackElement[myCapacity_];

  if (myArrayPtr == 0)        // check if memory available
  {
    cout << "*** Inadequate memory to allocate stack ***\n";
    exit(-1);
  }                                        // or assert(myArrayPtr != 0);

  myTop_ = -1;
}

//*** Definition of copy constructor
template <typename StackElement>
Stack<StackElement>::Stack(const Stack<StackElement> & original)
{
  cout << "COPY CONSTRUCTOR\n";
  myCapacity_ = original.myCapacity_;         // copy myCapacity_ member
  myArrayPtr = new StackElement[myCapacity_];   // allocate array in copy

  if (myArrayPtr == 0)                          // check if memory available
  {
    cout << "*** Inadequate memory to allocate stack ***\n";
    exit(-1);
  }

  for (int pos = 0; pos < myCapacity_; pos++) // copy array member
    myArrayPtr[pos] = original.myArrayPtr[pos];
  myTop_ = original.myTop_ ;                  // copy myTop_ member
}

//*** Definition of class destructor
template <typename StackElement>
Stack<StackElement>::~Stack()
{
  cout << "DESTRUCTOR\n";
  delete[] myArrayPtr;
}

//*** Definition of empty()
template<typename StackElement>
inline bool Stack<StackElement>::Empty() const
{
  return (myTop_ == -1);
}

//*** Definition of push()
template <typename StackElement>
void Stack<StackElement>::Push(const StackElement & value)
{
  if (myTop_ < myCapacity_ - 1)
  {
    ++myTop_;
    myArrayPtr[myTop_] = value;
  }                  // or simply, myArrayPtr[++myTop_] = value;
  else
    cout << "*** Stack is full -- can't add new value ***\n";
}

//*** Definition of top()
template <typename StackElement>
StackElement Stack<StackElement>::Top()
{
  if (myTop_ >= 0)
    return (myArrayPtr[myTop_]);
  cout << "*** Stack is empty -- returning 'garbage value' ***\n";
  return myArrayPtr[myCapacity_ -1];
}

//*** Definition of pop ()
template <typename StackElement>
void Stack<StackElement>::Pop()
{
  if (myTop_ >= 0)
    myTop_--;
  else
    cout << "*** Stack is empty -- can't remove a value ***\n";
}

//--- Definition of display()
template <typename StackElement>
void Stack<StackElement>::display(ostream & out) const
{
  for (int i = myTop_; i >= 0; i--)
    out << myArrayPtr[i] << endl;
}

//*** Definition of operator=() 
template <typename StackElement>
Stack<StackElement> & 
   Stack<StackElement>::operator=(const Stack<StackElement> & original)
{
  if (this != &original)                        // check that not st = st
  {
    delete[] myArrayPtr;                        // destroy previous array

    myArrayPtr = new StackElement[myCapacity_];   // allocate array in copy
    if (myArrayPtr == 0)                          // check if memory available
    {
      cout << "*** Inadequate memory to allocate stack ***\n";
      exit(-1);
    }

    myCapacity_ = original.myCapacity_;         // copy myCapacity_ member

    for (int pos = 0; pos < myCapacity_; pos++) // copy array member
      myArrayPtr[pos] = original.myArrayPtr[pos];
    myTop_ = original.myTop_ ;                  // copy myTop_ member
  }

  return *this;                                // return this object
}


#endif
