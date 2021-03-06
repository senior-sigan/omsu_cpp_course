#include <stdio.h>

#include "test.h"

#define N 10

// longest_sequence_length - находит длину максимально длинной
// последовательности одинаковых чисел идущих подряд.
// Например, для массива [1, 1, 2, 2, 5, 5, 5, 4, 1, 1] максимально длинная
// последовательность одинаковых чисел идущих подряд это [5,5,5], и ее длина 3.
int longest_sequence_length(int array[N]) {
  // TODO: напиши меня!
  return array[0];
}

void cli_interface(void) {
  // 1. запросите через консоль у пользователя 10 чисел
  // 2. сохраните введеные числа в массив array
  // 3. выведите результат выполнения longest_sequence_length в консоль

  // int array[N];
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  {
    int array[N] = {1, 1, 2, 2, 5, 5, 5, 4, 1, 1};
    ASSERT_INT(3, ==, longest_sequence_length(array));
  }

  {
    int array[N] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_INT(10, ==, longest_sequence_length(array));
  }

  {
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_INT(1, ==, longest_sequence_length(array));
  }

  {
    int array[N] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    ASSERT_INT(2, ==, longest_sequence_length(array));
  }
}

int main(void) {
  test();
  cli_interface();
  return 0;
}
