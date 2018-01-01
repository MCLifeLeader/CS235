/****************************************************************
 *
 *  Function: Brother Cameron
 *
 *  Purpose: Implements the selection sort algorithm
 *
 *****************************************************************/
void select_sort(int a[], int n)
{
  int  i,
       j,
       small,
       temp;

  for (i = 0; i < n-1; i++)
    {
      // set small to the index of the first occurance of
      // the smalles element remaining
      small = i;
      for (j = i+1; j < n; j++)
	if (a[j] < a[small])
	  small = j;
      temp = a[small];
      a[small] = a[i];
      a[i] = temp;
    }
}
