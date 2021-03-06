#include "test.h"

/**
 * Находит место первого вхождения подстроки substr в строке str.
 *
 * Обе подстроки должны быть нуль треминальными, иначе поведение не определено.
 *
 * Например: для str "one two three" и подстроки "two", вернет указатель на
 * четвертый символ строки str.
 * Например: str_str("one two three", "five") == NULL;
 *
 * @param str нультерминальная строка в которой будет искаться вхождение.
 * @param substr нультерминальная подстрока
 * @return указатель на первый символ найденной подстроки substr в строке str.
 * Возвращает NULL если вхождение не было найдено. Если substr это пустая
 * строка или NULL, то возвращает str.
 */
char* str_str(const char* str, const char* substr) {
  // TODO: напиши меня!
  if (substr == NULL) return (char*)(&str[0]);  // исправь меня
  return (char*)(&str[0]);                      // исправь меня!
}

void cli(void) {
  // TODO: напиши меня
  // 1. считайте с консоли N - длину строки str
  // 2. выделите память с помощью malloc на N+1 символов
  // 3. считайте с консоли строку длины N (+1 на \0)
  // 4. считайте с консоли L - длину строки substr
  // 5. выделите память с помощью malloc на L+1 символов
  // 6. считайте с консоли строку длины L (+1 на \0)
  // 7. примените функцию str_str
  // 8. напечатайте результат в консоль:
  //    - если вхождение найдено, то позицию в подстроке
  //    - если вхождение не найдено, то NULL
  // 9. почистите память
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
    char* str = "one two three";
    char* pos = str_str(str, "two");
    ASSERT_INT(4, ==, pos - str);
  }

  {
    char* str = "one two three twelve";
    char* pos = str_str(str, "tw");
    ASSERT_INT(4, ==, pos - str);
  }

  {
    char* str = "one two three twelve";
    char* pos = str_str(str, "twe");
    ASSERT_INT(14, ==, pos - str);
  }

  {
    char* str = "one two three";
    char* pos = str_str(str, "five");
    ASSERT_PTR_EQUAL(pos, NULL);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
