#include <deque>
#include <stack>
#include <iostream>
using namespace std;

main()
{
  unsigned int long number;
  stack <unsigned int long> st;

  cout << "Enter number: ";
  cin >> number;

  cout << number << "= ";
  for (int n = 2; n <= number; ++n)
    {
      while (number % n == 0)
	{
	  st.push(n);
	  number /= n;
	}
    }

  while(1)
    {
      cout << st.top();
      st.pop();
      if (st.empty())
	break;
      cout << " * ";
    }
  cout << endl;
}
