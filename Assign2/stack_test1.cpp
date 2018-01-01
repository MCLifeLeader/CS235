#include <iostream>
#include "stack.h"

using namespace std;

main()
{
  Stack st(5);
  int data[5] = {1,2,3,4,5};
  int i;

  cout << "TESTING PUSH FUNCTION:" << endl;
  for (i = 0; i < 5; ++i)
    st.Push(data[i]);
  cout << "TESTING FULL FUNCTION: Inserting a 6th item" << endl;
  cout << "This function should fail and leave error message" << endl;
  st.Push(-1);
  cout << "Test Completed\n";
}
