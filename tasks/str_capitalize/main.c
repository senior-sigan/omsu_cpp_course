#include <stdio.h>
#include <stdlib.h>

#include "test.h"

// скопируйте функцию из предыдущей задачи.
char* str_dup(const char* string);

/**
 * Капитализирует каждое слово в строке.
 * Слова раделены пробелом, табуляцией и переносом на новую строку.
 * Результата перезаписывает саму строку string.
 *
 * Капитализировать значит сделать первую букву заглавной,
 * а все другие буквы прописными.
 *
 * Пример: "HELLO wOrLd !!" превратится в "Hello World !!"
 *
 * @param string строка, которая будет капитализирована на месте.
 */
void str_capitalize(char* string) {
  // TODO: напиши меня!
}

void cli(void) {
  // TODO: напиши меня
  // 1. считайте с консоли N - длину строки
  // 2. выделите память с помощью malloc на N+1 символов
  // 3. считайте с консоли строку длины N (+1 на \0)
  // 4. примените над строкой str_capitalize
  // 5. напечатайте результат в консоль
  // 6. почистите память
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
    char* str = str_dup("HELLO wOrLd !!");
    // проверяем что str_dup работает корректно
    ASSERT_STR_EQUAL(str, "HELLO wOrLd !!");
    str_capitalize(str);
    ASSERT_STR_EQUAL(str, "Hello World !!");
    free(str);
  }

  {
    char* str = str_dup("test\ntest test\ttest");
    // проверяем что str_dup работает корректно
    ASSERT_STR_EQUAL(str, "test\ntest test\ttest");
    str_capitalize(str);
    ASSERT_STR_EQUAL(str, "Test\nTest Test\tTest");
    free(str);
  }

  {
    char* str = str_dup("a b c D e FF gg ! @ #");
    // проверяем что str_dup работает корректно
    ASSERT_STR_EQUAL(str, "a b c D e FF gg ! @ #");
    str_capitalize(str);
    ASSERT_STR_EQUAL(str, "A B C D E Ff Gg ! @ #");
    free(str);
  }
  {
    char* str =
        str_dup("my name is boris. lOnDoN is the capital 0f great britain.");
    // проверяем что str_dup работает корректно
    ASSERT_STR_EQUAL(
        str, "my name is boris. lOnDoN is the capital 0f great britain.");
    str_capitalize(str);
    ASSERT_STR_EQUAL(
        str, "My Name Is Boris. London Is The Capital 0f Great Britain.");
    free(str);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
