#include "test.h"

// prime_palindrom - возвращает наибольший простой палиндром, меньший числа n.
// Простое число - это число, у которого только два делителя - 1 и само число.
// Палиндромом - это число, которое записывается слева направо точно так же
// как и справа налево.
// Пример: prime_palindrom(1000) = 929
int prime_palindrom(int n) {
  // напиши меня!
  return n;
}

void cli(void) {
  // 1. Запросите у пользователя ввести число
  // 2. Примените над ним функцию prime_palindrom
  // 3. Выведите результат в консоль
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_INT(929, ==, prime_palindrom(1000));
  ASSERT_INT(11, ==, prime_palindrom(100));
  ASSERT_INT(313, ==, prime_palindrom(350));
  ASSERT_INT(353, ==, prime_palindrom(360));
}

int main(void) {
  test();
  cli();
  return 0;
}
