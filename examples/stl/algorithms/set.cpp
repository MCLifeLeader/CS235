#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

void print_set(set<int> A);

class Random
{
 public:
  Random();

  /* --- Get next integer in range low-high --- */
  int NextInt(int low, int high); 

};

main()
{
  set<int> A;
  set<int> B;
  set<int> C;
  set<int>::iterator a;
  set<int>::iterator b;
  set<int>::iterator c;
  int i = 1;

  Random R;

  // --- Generate Set of 25
  while (A.size() != 25)
    A.insert(R.NextInt(1,99));

  // --- Generate Set of 50
  while (B.size() != 50)
    B.insert(R.NextInt(1,99));

  // --- Output Set A and B
  cout << "Set A: " << endl;
  print_set(A);

  cout << "Set B: " << endl;
  print_set(B);

  set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C,C.begin()));
  cout << "Intersection of A and B: " << endl;
  print_set(C);
  C.clear();
  
  set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C,C.begin()));
  cout << "Union of A and B: " << endl;
  print_set(C);
  C.clear();

  set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C,C.begin()));
  cout << "Difference of A and B: " << endl;
  print_set(C);
  C.clear();

  set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(C,C.begin()));
  cout << "Difference of B and A: " << endl;
  print_set(C);
}

void print_set(set<int> A)
{
  set<int>::iterator a;  
  int i = 0;

  for (a = A.begin(); a != A.end(); a++)
  {
     cout << setw(3) << *a << " ";
     ++i;
     if (i == 10)
     {
        i = 0;
        cout << endl;
     }
  }
  cout << endl << endl;
}
/*********************************************************
 *
 *    FUNCTION: Random
 *
 *  PARAMETERS: None
 *
 *     PURPOSE: Random constructor.  Sets the random number
 *              seed to the current time.  The srand function
 *              is provided by stdlib.h and time by time.h
 *              Passing NULL to the time function returns
 *              the current time (in clock ticks) and this
 *              is then passed to srand.
 *
 *       USAGE: Creates a random object to generate random numbers
 *              
 *              Random r1;  
 *
 *********************************************************/
Random::Random()
{
  srand((int)time(NULL));
}

/*********************************************************
 *
 *    FUNCTION: NextInt
 *
 *  PARAMETERS: low - smallest number in range
 *              high - largest number in range
 *
 *     PURPOSE: This function does the following:
 *                1. Generate a real number between 0 and 1 
 *                   by calling rand() and dividing by
 *                   the constant RAND_MAX + 1
 *                2. Scale this number to the appropriae range
 *                   size (high - low)
 *                3. Truncate the value to an integer
 *                4. Translate the number to the appropriate
 *                   starting point.
 *
 *        USAGE: Assumes random object has been created.
 *               This call will create 1 random number betwen
 *               1 and 50.
 *
 *               num = r1.NextInt(1,50);
 *
 *********************************************************/
int Random::NextInt(int low, int high)
{
  int k;
  double d;
  
  d = (double)rand()/((double)RAND_MAX+1);
  k = (int)(d*(high-low+1));
  return(low+k);
}
