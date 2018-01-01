/*********************************************************
 *
 *    FUNCTION: bubble
 *
 *  PARAMETERS: data - an array of integers
 *              n    - number of elements in the array to sort
 *
 *********************************************************/
void bubble(int data[], int n)
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

