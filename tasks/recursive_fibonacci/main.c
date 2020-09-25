#include "test.h"

// recursive_fib выдает N-ый член последовательности Фибоначчи.
// Правило последовательности:
// recursive_fib(0) == 0
// recursive_fib(1) == 1
// recursive_fib(2) == 1
// recursive_fib(n+1) = recursive_fib(n) + recursive_fib(n-1)
// !!! Функция должна использовать рекурсию
// Циклы for, while ЗАПРЕЩЕНЫ
int recursive_fib(int n) {
  // Напиши меня!
  return n;
}

void cli(void) {
  // TODO: напиши меня
  // 1. Запросите у пользователя целое число
  // 2. Считайте с консоли число n
  // 3. Обработайте возможный неверный ввод (отрицательное число)
  // 4. Выведите пользователю результат recursive_fib(n)
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_INT(0, ==, recursive_fib(0));
  ASSERT_INT(1, ==, recursive_fib(1));
  ASSERT_INT(1, ==, recursive_fib(2));
  ASSERT_INT(2, ==, recursive_fib(3));
  ASSERT_INT(3, ==, recursive_fib(4));
  ASSERT_INT(55, ==, recursive_fib(10));
  ASSERT_INT(89, ==, recursive_fib(11));
  ASSERT_INT(987, ==, recursive_fib(16));
}

int main(void) {
  test();
  cli();
  return 0;
}
