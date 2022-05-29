#include <stdio.h>
#include <stdlib.h>

typedef double (*Reducer)(double, double);

double reduce(double* array, double len, Reducer reducer) {
  double accumulator = 0;
  for (int i = 0; i < len; i++) {
    accumulator = reducer(accumulator, array[i]);
  }
  return accumulator;
}

double sum(double acc, double value) {
  double sum = acc + value;
  printf("%lf = %lf + %lf\n", sum, acc, value);
  return sum;
}

int main() {
  const int N = 5;
  double* arr = malloc(sizeof(double) * N);
  for (int i = 0; i < N; i++) {
    arr[i] = i * 3.1415926;
    printf("%lf ", arr[i]);
  }
  printf("\n");

  double r = reduce(arr, N, sum);
  printf("r=%lf\n", r);

  return 0;
}
