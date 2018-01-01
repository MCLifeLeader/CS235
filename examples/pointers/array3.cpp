using namespace std;
#include <iostream>

main()
{
  int a[5] = {2,4,6,8,10};
  int *aptr = a;

  for (int i = 0; i < 5; ++i)
    cout << a[i] << " ";
  cout << endl;

  for (int i = 0; i < 5; ++i)
    cout << *(a + i) << " ";
  cout << endl;

  for (int i = 0; i < 5; ++i)
    cout << *(aptr + i) << " ";
  cout << endl;

  for (int i = 0; i < 5; ++i)
    cout << aptr[i] << " ";
  cout << endl;
}
