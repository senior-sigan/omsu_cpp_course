#include <iostream>
#include <vector>

// void PrintLen(const std::vector<int>* const vec) {
//   std::cout << vec->size() << std::endl;
// }

void PrintLen(const std::vector<int>& vec) {
  std::cout << vec.size() << std::endl;
}

int main() {
  std::cout << "Create vector" << std::endl;
  std::vector<int> v(10000000);
  std::cout << "Show len" << std::endl;
  PrintLen(v);
  std::cout << "Show len" << std::endl;
  PrintLen(v);
  std::cout << "Show len" << std::endl;
  PrintLen(v);
  std::cout << "Show len" << std::endl;
  PrintLen(v);
  std::cout << "Show len" << std::endl;
  PrintLen(v);
  return 0;
}
