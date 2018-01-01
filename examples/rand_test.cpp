using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <math.h>

class Random
{
 public:
  Random();

  /* --- Get next integer in range low-high --- */
  int NextInt(int low, int high); 

};

main(int argc, char *argv[])
{
  ofstream outfile(argv[1]);
  Random rand_gen;
  int num;
  int beg_range;
  int end_range;

  num = atoi(argv[2]);
  beg_range = atoi(argv[3]);
  end_range = atoi(argv[4]);

  for (int i = 0; i < num; ++i)
    outfile << rand_gen.NextInt(beg_range,end_range) << " ";
  outfile << endl;
  

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









