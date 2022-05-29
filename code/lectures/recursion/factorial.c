#include <stdio.h>

int fact_iter(int n) {
  if (n < 0) {
    return 1;
  }

  int res = 1;
  while (n > 0) {
    res *= n;
    n -= 1;
  }
  return res;
}

int fact_rec(int n) {
  if (n <= 1) {
    return 1;
  }
  int res = fact_rec(n - 1);
  return n * res;
}

int fact_for(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    // !!!!
    res *= i;
  }
  return res;
}

int fact_rec_iter(int res, int i, const int n) {
  if (i <= n) {
    return fact_rec_iter(res * i, i + 1, n);
  }
  return res;
}

int fact_rec2(int n) {
  return fact_rec_iter(1, 1, n);
}

int main(void) {
  printf("Factorial iter\n");
  int n = 5;
  printf("f(%d) = %d\n", n, fact_iter(n));

  printf("Rec fact\n");
  printf("f(%d) = %d\n", n, fact_rec(n));

  printf("Factorial FOR\n");
  printf("f(%d) = %d\n", n, fact_for(n));

  printf("Rec fact 2\n");
  printf("f(%d) = %d\n", n, fact_rec2(n));
  return 0;
}
