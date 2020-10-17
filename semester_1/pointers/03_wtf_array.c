#include <stdio.h>

int main(void) {
  int arr[3] = {1, 2, 3};

  printf("%d\n", arr[1]);
  printf("%d\n", 1 [arr]);

  for (int i = 0; i < 3; i++) {
    i[arr] = 42;
  }

  printf("%d\n", arr[0]);
  printf("%d\n", arr[1]);
  printf("%d\n", arr[2]);

  // arr[1] == *(arr + 1) == *(1 + arr) == 1 [arr];
}
