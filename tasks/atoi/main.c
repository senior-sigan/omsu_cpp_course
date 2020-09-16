#include <stdio.h>
#include <stdlib.h>

#include "test.h"

/**
 * Переводит строку в число, если возможно.
 * Например, строку "-42" интерпретирует, как int -42.
 *
 * Игнорирует любые пробельные символы.
 * Например, строку " 33 " интерпретирует, как число 33.
 *
 * Если строку невозможно интерпретировать, как число, тогда функция вернет -1,
 * как индикатор ошибки, и результат не будет записан в out.
 *
 * @param str указатель на нультерминальную строку, которую нужно
 * проинтерпретировать, как число.
 * @param out указатель на переменную, куда сохранить результат интерпретации
 * @return ноль, если можно интерпретировать как число, иначе -1.
 */
int atoi_(const char* str, int* out) {
  // TODO: НАПИШИ МЕНЯ!
  // использовать atoi из stdlib.h нельзя!
  return 0;
}

void cli(void) {
  // TODO: запросить пользователя ввести число
  // TODO: сохранить ввод пользователя в строку.
  // TODO: вызвать atoi и вывести результат
  // TODO: если произошла ошибка в atoi то сообщить об этом пользователю
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
    int res;
    int err = atoi_("-42", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(-42, ==, res);
  }

  {
    int res;
    int err = atoi_("33", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(33, ==, res);
  }

  {
    int res;
    int err = atoi_("8 ", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(8, ==, res);
  }

  {
    int res;
    int err = atoi_(" -42", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(-42, ==, res);
  }

  {
    int res;
    int err = atoi_("\t-42", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(-42, ==, res);
  }

  {
    int res;
    int err = atoi_("+12456547", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(12456547, ==, res);
  }

  {
    int res;
    int err = atoi_("\t\n \v  5152 \t \t \n\n\n\r", &res);
    ASSERT_INT(err, >=, 0);
    ASSERT_INT(5152, ==, res);
  }

  {
    int res = 42;
    int err = atoi_("3 3", &res);
    ASSERT_INT(err, <, 0);
    ASSERT_INT(42, ==, res);
  }

  {
    int res = 42;
    int err = atoi_("A", &res);
    ASSERT_INT(err, <, 0);
    ASSERT_INT(42, ==, res);
  }

  {
    int res = 42;
    int err = atoi_("123-", &res);
    ASSERT_INT(err, <, 0);
    ASSERT_INT(42, ==, res);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
