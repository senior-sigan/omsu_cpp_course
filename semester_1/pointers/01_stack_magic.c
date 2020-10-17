#include <stdio.h>

int main(void) {
  int a = 42;
  int b = 31;
  int c = 14;
  int d = 7;

  int arr[4] = {};

  printf("a %p\n", &a);
  printf("b %p\n", &b);
  printf("c %p\n", &c);
  printf("d %p\n", &d);
  printf("0 %p\n", &arr[0]);
  printf("1 %p\n", &arr[1]);
  printf("2 %p\n", &arr[2]);
  printf("3 %p\n", &arr[3]);

  printf("%d\n", *(&d + 1));  //  14

  // wtf lol array in memory is upper but in code - not!
  printf("%d\n", arr[-2]);  // 42
  printf("%d\n", arr[-3]);  // 31
  printf("%d\n", arr[-4]);  // 14
  printf("%d\n", arr[-5]);  // 7

  return 0;
}
