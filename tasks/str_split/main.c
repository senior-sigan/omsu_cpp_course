#include <stdio.h>
#include <stdlib.h>

#include "test.h"

/**
 * Разбивает строку str на подстроки используя разделитель delim.
 *
 * Пример: строка "hello world! Nya" разбивается на ["hello", "world!", "Nya"]
 * разделителем ' '.
 *
 * - Строки нультерминальные.
 * - Подстроки не включают разделители delim в себя.
 * - Память для массива строк должна быть выделена динамически внутри функции.
 * - Если разделитель не встречается, то в `out` записывается копия входной
 * строки и возвращается `1`.
 * - Если строка пустая или `NULL`, то возвращается `0` , в `out` ничего не
 * записывается.
 * - Функция возвращает `-1`, если что-то идет не так.
 * - Вызывающая функция обязана освободить память.
 *
 * @param str входная строка которую надо разбить на подстроки
 * @param delim разделитель подстрок
 * @param out результат разбиения строки - указатель на массив нультерминальных
 * строк
 * @return количество подстрок
 */
int str_split(const char* str, char delim, char*** out) {
  // TODO: напиши меня!
  return 0;
}

void cli(void) {
  // TODO: запросите у пользователя строку и разделитель
  // TODO: примените функцию str_split
  // TODO: выведите результат в консоль
  // TODO: почистите память
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
    char** res;  // массив строк
    int n = str_split("hello world! Nya", ' ', &res);
    ASSERT_INT(3, ==, n);
    ASSERT_STR_EQUAL("hello", res[0]);
    ASSERT_STR_EQUAL("world!", res[1]);
    ASSERT_STR_EQUAL("Nya", res[2]);
    for (int i = 0; i < n; i++) {
      free(res[i]);
    }
    free(res);
  }
  {
    char** res;  // массив строк
    int n = str_split("helloAworld!ANya", 'A', &res);
    ASSERT_INT(3, ==, n);
    ASSERT_STR_EQUAL("hello", res[0]);
    ASSERT_STR_EQUAL("world!", res[1]);
    ASSERT_STR_EQUAL("Nya", res[2]);
    for (int i = 0; i < n; i++) {
      free(res[i]);
    }
    free(res);
  }
  {
    char** res;  // массив строк
    const char* str = "hello world! Nya";
    int n = str_split(str, '\n', &res);
    ASSERT_INT(1, ==, n);
    ASSERT_STR_EQUAL("hello world! Nya", res[0]);
    ASSERT_PTR_NOT_EQUAL(res[0], str);
    for (int i = 0; i < n; i++) {
      free(res[i]);
    }
    free(res);
  }
  {
    char** res;  // массив строк
    int n = str_split("", '\n', &res);
    ASSERT_INT(0, ==, n);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
