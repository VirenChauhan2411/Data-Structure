#include <stdio.h>
void main()
{
  int i, j, n;
  printf("Enter the row of triangle :");
  scanf("%d", &n);

  int arr[n][n];

  for (i = 0; i < n; i++)
  {
    for(int k=n;k>=i;k--)
    {
        printf(" ");
    }
    for (j = 0; j <= i; j++) 
    {
      if (j == 0 || j == i) 
      {
        arr[i][j] = 1;
      }
       else 
      {
        arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
      }
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}