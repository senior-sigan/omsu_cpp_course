#include "test.h"

int add(int a, int b) { return a + b; }
int main(void) {
  ASSERT_INT(5, ==, add(2, 3));
  return 0;
}
