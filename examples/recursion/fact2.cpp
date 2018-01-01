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
  int prod = 1;

  for (int i = 1; i <= n; i++)
    prod = prod * i;

  return (prod);
}
