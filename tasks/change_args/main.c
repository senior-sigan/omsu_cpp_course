#include <stdlib.h>

#include "test.h"

/**
 * Перемножает a и b.
 * Результат произведения складывает в a.
 *
 * @param a указатель на первый множитель.
 * Результат произведения перезаписывает значение по этому адресу.
 * @param b второй множитель.
 */
void multiply_by(int* a, int b) {
  // TODO: напиши меня!
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
    int res = 42;
    multiply_by(&res, 2);
    ASSERT_INT(84, ==, res);
  }

  {
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 3;
    multiply_by(ptr, -33);
    ASSERT_INT(-99, ==, *ptr);
  }
}

int main(void) {
  test();
  return 0;
}