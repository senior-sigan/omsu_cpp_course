#include <stdio.h>

#define LEN 3

int add(int a, int b) {
  return a + b;
}

int mul(int a, int b) {
  return a * b;
}

int sub(int a, int b) {
  return a - b;
}

int main() {
  int a = 1;
  int b = 2;

  int (*operations[LEN])(int, int) = {add, mul, sub};

  for (int i = 0; i < LEN; i++) {
    a = operations[i](a, b);
  }
  printf("a=%d\n", a);

  printf("manual = %d\n", sub(mul(add(1, 2), 2), 2));
}
