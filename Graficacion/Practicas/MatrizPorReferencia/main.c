#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int m, int n);

int main(){
  int arr[3][3], i, j;
  int m = 3, n = 3;

  print((int *)arr, m, n);

  for(i = 0; i < 3; i++){
    for (j = 0; j < 3; j++)
      printf("%6d", arr[i][j]);
    printf("\n");
  }
  //printf("%d %d %d \n", aux[0], aux[1], aux[2]);
  return 0;
}

void print(int *arr, int m, int n){
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      *((arr + i * n) + j) = i;
}
