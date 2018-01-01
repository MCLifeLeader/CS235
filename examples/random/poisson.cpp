#include "random.h"
#include <math.h>

int Random::PoissonRandom(double expected)
{
  int n=0;
  double limit;
  double x;
  
  limit = exp(-expected);
  x = rand()/((double)RAND_MAX+1);
  while (x>limit)
    {
      n++;
      x *= rand()/((double)RAND_MAX+1);
    }
  return n;
}

