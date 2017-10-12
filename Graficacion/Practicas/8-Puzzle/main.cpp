#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>

using namespace std;

void fillMatrix(int *puzzle, int x);

int main(int argc, char const *argv[]) {
  int x = 3;
  int y;
  int matrix[x][x], arr[10];
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      y = rand()%9;
      matrix[i][j] = y;
    }
  }
  matrix[0][0] = 0;
  fillMatrix((int *)matrix, x);
  return 0;
}

void fillMatrix(int *matrix, int x){
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < x; j++) {
      if(*((matrix + i * x) + j) != 0)
          cout << *((matrix + i * x) + j) << " ";   //Imprime Valores de la Matriz
      else
          cout << "  ";
    }
    cout << endl;
  }
}
