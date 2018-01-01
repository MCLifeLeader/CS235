/*********************************************************
 *
 *    FUNCTION: quicksort
 *
 *  PARAMETERS: data[] - array of data to be sorted
 *              left   - left index of array
 *              right  - right index of array
 *
 *********************************************************/

void quicksort(int data[], int left, int right)
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
      quicksort(data,left,j);
      quicksort(data,i,right);
    }
}
