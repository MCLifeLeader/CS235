using namespace std;
#include "stack.h"
#include <iostream>

main()
{
  Stack st(5);
  int data[5] = {1,2,3,4,5};
  int i;
  int item;

  for (i = 0; i < 5; ++i)
    st.Push(data[i]);

  cout << "TESTING TOP FUNCITON:" << endl;
  for (i = 0; i < 5; ++i)
    {
      item = st.Top();
      cout << item << " ";
      st.Pop();
    }
  cout << endl;
}
