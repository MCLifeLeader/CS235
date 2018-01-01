int binary_search(int a[], int n, int key)
{
  int l = 0;
  int r = n-1; 
  int midpoint;
  
  while (l <= r)
    {
      midpoint = (l + r)/2;
      if (key == a[midpoint])
	return(midpoint);
      else if (key > a[midpoint])
	l = midpoint + 1;
      else
	r = midpoint - 1;
    }
  return(-1);
}
