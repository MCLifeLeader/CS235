int linear_search(int a[], int n, int key)
{
  for (i = 0; i < n; ++i)
    if (key == a[i])
      return(i);
  return(-1);
}
