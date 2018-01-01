using namespace std;
#include "stack.h"
#include <iostream>

main()
{
  int i;
  int data[5] = {1,2,3,4,5};
  Stack st(5);

  // --- Push items onto stack
  for (i = 0; i < 5; ++i)
    st.Push(data[i]);

  // -- Test Pop function
  cout << "TESTING POP FUNCITON:" << endl;
  for (i = 0; i < 5; ++i)
     st.Pop();
  cout << "TESTING EMPTY FUNCTION: " << endl;
  cout << "\tTry popping a value off an empty stack." << endl;
  cout << "\tProgram should exit and fail." << endl;
  st.Pop();
  cout << "Test Completed\n";
}
