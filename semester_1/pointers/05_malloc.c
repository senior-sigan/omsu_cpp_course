#include <stdio.h>
#include <stdlib.h>

// [ int*, int*, int* ] --> [0, 1, 2, 3] , [3, 4, 5, 6],

int sumall(int** matrix) {
  matrix[i][j]
}

int main() {
  int** matrix;
  int n = 3;
  int m = 4;
  matrix = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
