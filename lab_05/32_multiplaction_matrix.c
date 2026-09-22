#include <stdio.h>
void main() {
  int i, j;
  int b[2][3], a[3][2],c[3][3]={0};
  printf("Enter th element of 1st matrix :");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  printf("Enter th element of 2nd matrix :");

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &b[i][j]);
    }
  }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
       for(int k = 0 ; k < 2 ; k++)
       {
        c[i][j] += a[i][k] * b[k][j];
       }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }
}