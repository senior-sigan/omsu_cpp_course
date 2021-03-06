#include <stdio.h>

#include "test.h"

// Дополнительные функции создавать можно.

/**
 * Быстрое возведение в степень.
 * Говорят, что можно возводить число рекурсивно в степень быстрее,
 * чем x*pow(x, n-1).
 *
 * Функция должна считаться рекурсивно.
 * Циклы for, while использовать запрещено.
 *
 * @param x - число, которое надо возвести в степень.
 * @param n - показатель степени.
 * @return результат возведения числа x в степень n.
 */
double fast_power(double x, int n) {
  // Напиши меня
  return x * n;
}

void cli(void) {
  // TODO: напиши меня
  // 1. Запросите у пользователя числа x и n
  // 2. Считайте с консоли числа x и n
  // 4. Выведите пользователю результат fast_power(x, n)
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_DOUBLE_EQUAL(9, fast_power(3, 2), EPSILON);
  ASSERT_DOUBLE_EQUAL(1, fast_power(1, 0), EPSILON);
  ASSERT_DOUBLE_EQUAL(14551915.228366852, fast_power(-2.5, 18), EPSILON);
  ASSERT_DOUBLE_EQUAL(0.00390625, fast_power(2, -8), EPSILON);
}

int main(void) {
  test();
  cli();
  return 0;
}
