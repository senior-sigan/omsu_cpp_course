#include <iostream>

#include "test_shared_ptr.h"
#include "test_unique_ptr.h"

// !! раскомментируйте если будете делать weak_ptr
// #include "test_weak_ptr.h"

// текст задачи https://www.notion.so/RAII-Templates-Smart-Pointer-813efc189a8b45cf81d647cf1b3223e2

int main() {
  std::cout << "Hello World!\n";

  test_unique_ptr();
  test_shared_ptr();
  // !! раскомментируйте если будете делать weak_ptr
  // test_weak_ptr();

  return 0;
}
