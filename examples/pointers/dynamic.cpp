#include <iostream>
using namespace std;

main()
{
  for (int i = 1000000; i < 10000000; i += 100000)
  {
    int *ptr;
    cout << "Allocating " << i << " integer locations" << endl;
    ptr = new int[i];
    ptr[i-1] = 5;
    cout << ptr[i-1] << endl;
    //    delete [] ptr;
  }
}
