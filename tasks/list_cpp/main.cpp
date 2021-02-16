#include <iostream>

#include "array_list.h"
#include "linked_list.h"
#include "test.h"

template<typename TList>  // познакосьтесь, это шаблонизированная функция
void Test() {
  SETUP_TESTS();
}

int main() {
  // тут немного магии на шаблонах, чтобы ее копипастить тесты много раз
  Test<ArrayList>();
  Test<LinkedList>();
}
