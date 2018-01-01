/*********************************************************
 *
 *   Program: sort_time.cpp
 *
 *   Author:  Brother Cameron, 10/5/2001
 *
 *   Purpose: Homework #7 for CS 235
 *
 *********************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

void Sort1(int data[], int n);
void Sort2(int data[], int left, int right);

class Random
{
 public:
  Random();

  /* --- Get next integer in range low-high --- */
  int NextInt(int low, int high); 

};

main()
{
  int size;         // --- size of array
  int *array;       // --- array containing random integers
  Random r;         // --- random number generator object
  clock_t start;    // --- time when algorithm starts
  clock_t finish;   // --- time when algorithm finishes

  cout << " Size      Sort #1      Sort #2" << endl;
  for (size = 10000; size <= 50000; size+= 5000)
    {
      // --- create array with 'size' random integers
      array = new int [size];
      for (int i = 0; i < size; ++i)
	array[i] = r.NextInt(1,500);
      cout << setw(5) << size;
      // --- Find out how much time for first sort
      start = clock();
      Sort1(array,size);
      finish = clock();
      cout << setw(13) << (finish-start);

      // --- recreate array with new set of random integers
      delete [] array;
      array = new int [size];
      for (int i = 0; i < size; ++i)
	array[i] = r.NextInt(1,500);

      // --- Find out how much time for second sort
      start = clock();
      Sort2(array,0,size);
      finish = clock();
      cout << setw(13) << (finish-start) << endl;

      delete [] array;
    }
}

/*********************************************************
 *
 *    FUNCTION: Sort1
 *
 *  PARAMETERS: data - an array of integers
 *              n    - number of elements in the array to sort
 *
 *********************************************************/
void Sort1(int data[], int n)
{
  int notsorted = 1;
  int temp;
  int i;

  while(notsorted)
    {
      notsorted = 0;
      for (i = 0; i < n; ++i)
	if (data[i] > data[i+1])
	  {
	    temp = data[i];
	    data[i] = data[i+1];
	    data[i+1] = temp;
	    notsorted = 1;
	  }
    }
}

/*********************************************************
 *
 *    FUNCTION: Sort2
 *
 *  PARAMETERS: data[] - array of data to be sorted
 *              left   - left index of array
 *              right  - right index of array
 *
 *********************************************************/

void Sort2(int data[], int left, int right)
{
  int i;
  int j;
  int pivot;
  int temp;

  if (left <= right)
    {
      pivot = data[(left+right)/2];
    
      i = left;
      j = right;
      do
	{
	  while (data[i] < pivot)
	    i++;
	  while (data[j] > pivot)
	    j--;
	  if (i <= j)
	    {
	      temp = data[i];
	      data[i] = data[j];
	      data[j] = temp;
	      i++;
	      j--;
	    }
	} while (i < j);
      Sort2(data,left,j);
      Sort2(data,i,right);
    }
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
