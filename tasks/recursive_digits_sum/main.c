#include "test.h"

// recursive_digits_sum считает сумму цифр числа number
// Функция должна использовать рекурсию.
// Запрещено использовать циклы for и while.
long recursive_digits_sum(long number) {
  // напиши меня!
  return number;
}

void cli(void) {
  // TODO: напиши меня
  // 1. Запросите у пользователя целое число
  // 2. Считайте с консоли число n
  // 4. Выведите пользователю результат recursive_digits_sum(n)
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_LONG(7, ==, recursive_digits_sum(7));
  ASSERT_LONG(6, ==, recursive_digits_sum(42));
  ASSERT_LONG(10, ==, recursive_digits_sum(1234));
  ASSERT_LONG(46, ==, recursive_digits_sum(1512468443413));
  ASSERT_LONG(10, ==, recursive_digits_sum(-1234));
}

int main(void) {
  test();
  cli();
  return 0;
}
