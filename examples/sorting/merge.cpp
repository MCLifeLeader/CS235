/**************************************************************
 *
 *  Function: merge
 *
 *  Parameters: data[] - array of data to be sorted
 *              low    - index of first element to be sorted
 *              high   - index of last element to be sorted
 *
 **************************************************************/
void mergesort(int data[], int low, int high)
{
  int mid;             // --- index of where to split the list
  int endlow;          // --- last index of left list
  int starthigh;       // --- first index of right list
  int temp;            // --- temporary storage location

  // --- base case for recursion
  if (low >= high)
    return;

  // --- split list
  mid = (low + high)/2;

  // --- recursively merge two lists
  mergesort(data,low,mid);
  mergesort(data,mid+1,high);

  // --- merge two sorted lists
  endlow = mid;
  starthigh = mid+1;
  while ((low <= endlow) && (starthigh <= high))
    {
      if (data[low] <= data[starthigh])
	low++;
      else
	{
	  temp = data[starthigh];
	  for (int i = starthigh-1; i >= low; i--)
	    data[i+1] = data[i];
	  data[low] = temp;
	  low++;
	  endlow++;
	  starthigh++;
	}
    }
}
