/*************************************************************
 *
 *  NAME:     Greg Cameron
 *
 *  PROGRAM:  random.h
 *
 *  PURPOSE:  Defines the Random class
 *
 *************************************************************/

#ifndef _RANDOM_H
#define _RANDOM_H
class Random
{
 public:
  Random();

  /* --- Get next integer in range low-high --- */
  int NextInt(int low, int high); 

  /* --- Get next float in range low-high --- */
  double NextFloat(double low, double high);

  /* --- Get next Poisson random --- */
  int PoissonRandom(double expected);

};
#endif
