#include "test.h"

// prime возвращает максимальное простое число, меньшее n.
// Например, prime(20) == 19, prime(2020) == 2017.
// Простое число - это число, у которого только два делителя - 1 и само число.
int prime(int n) {
  // Напиши меня!
  // Попробуйте придумать алгоритм, который эффективнее чем полный перебор.
  return n;
}

int main(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если в задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_INT(5, ==, prime(6));
  ASSERT_INT(19, ==, prime(20));
  ASSERT_INT(2017, ==, prime(2027));
  ASSERT_INT(2221, ==, prime(2237));
  ASSERT_INT(3571, ==, prime(3572));
  return 0;
}
