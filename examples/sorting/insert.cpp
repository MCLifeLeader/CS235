/****************************************************************
 *
 *  Function: Brother Cameron
 *
 *  Purpose: Implements the insertion sort algorithm
 *
 *****************************************************************/
void insert_sort(int a[], int n)
{
  int i;
  int j;

  int next_elem;

  for (i = 1; i < n; ++i)
    {
      next_elem = a[i];
      j = i;
      for (j = i; (next_elem < a[j-1]) && (j != 0); j--)
	a[j] = a[j-1];
      a[j] = next_elem;
    }
}
