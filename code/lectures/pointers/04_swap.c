#include <stdio.h>

void swap(int* a, int* b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

int main(void) {
  int c = 42;
  int d = 31;

  printf("a=%d b=%d\n", c, d);
  swap(&c, &d);
  printf("a=%d b=%d\n", c, d);
}
