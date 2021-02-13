#include <iostream>

int i = 42;

int& lol() {
  return i;
}

int main() {
  std::cout << i << "\n";

  lol() = 3;

  std::cout << i << "\n";
  return 0;
}
