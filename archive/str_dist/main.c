#include "test.h"

struct Result {
  char* word1;
  char* word2;
  int distance;
};

/**
 * Расстояние между двумя строками равной длины - это количество позиций, в которых различаются эти
 * строки. Если слова разной длины, то считается, что меньшее строка забита нулями (в смысле \0).
 *
 * В заданном массиве строк найти пару наиболее отличающихся строк.
 *
 * @param strings - массив строк (точнее указателей на строк)
 * @param n - длина массива строк
 * @return struct Result
 */
struct Result str_dist(char* strings[], unsigned long n) {
  struct Result res;
  return res;
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
    char* sentence[] = {"hello", "world", "he11o"};
    struct Result res = str_dist(sentence, 3);
    ASSERT_INT(5, ==, res.distance);
  }

  {
    char* sentence[] = {"hello", "world", "test1", "lol7777"};
    struct Result res = str_dist(sentence, 4);
    ASSERT_INT(7, ==, res.distance);
  }
  {
    char* sentence[] = {"anime", "4nime", "4n1me", "anim3", "4n1m3"};
    struct Result res = str_dist(sentence, 5);
    ASSERT_INT(3, ==, res.distance);
  }
}

int main(void) {
  test();
  return 0;
}
