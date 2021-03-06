#include <stdio.h>
#include <string.h>

#include "test.h"

/**
 * Вычисляет длину нультерминальной строки.
 * Если строка не нультерминальная, то поведение не определено.
 *
 * @param string строка
 * @return Длина строки.
 */
unsigned int str_length(const char* string) {
  // TODO: напиши меня!
  return 0;
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  ASSERT_INT(12, ==, str_length("Hello world."));
  ASSERT_INT(0, ==, str_length(""));
  ASSERT_INT(1, ==, str_length("a"));
  ASSERT_INT(19, ==, str_length("Hello.\nHow are you?"));
  ASSERT_INT(0, ==, str_length(NULL));
}

int main(void) {
  test();
  return 0;
}
