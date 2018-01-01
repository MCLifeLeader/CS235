#include <iostream.h>
#include <stdlib.h>
#include <iomanip.h>

int A(int m, int n);

main(int argc, char *argv[])
{
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  cout << "A(" << m << "," << n << ") = " << A(m,n) << endl;

}

int A(int m, int n)
{
  if ((m == 0) && (n >= 0))
    return (2*n);
  if ((n == 0) && (m > 0))
    return(0);
  if ((m >= 1 && n == 1))
    return(2);
  return(A(m-1,A(m,n-1)));
}
