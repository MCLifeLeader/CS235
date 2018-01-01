#include <iostream>
using namespace std;

int fact(int n);

main()
{
  int n;

  cout << "Enter n: ";
  cin >> n;
  cout << "n! = " << fact(n) << endl;
}

int fact(int n)
{
  if (n <= 0)
    return 1;
  else
    return (n*fact(n-1));
}
