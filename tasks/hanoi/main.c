#include <stdio.h>
#include <stdlib.h>

#include "test.h"

void hanoi(int n, char x, char y, char z, char* buffer) {
  if (n <= 0) return;
  hanoi(n - 1, x, z, y, buffer);
  sprintf(buffer, "%c -> %c\n", x, y);
  hanoi(n - 1, z, y, x, buffer);
}

void cli(void) {
  // TODO: напиши меня
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
    char* buffer = calloc(106, sizeof(char));
    buffer[105] = '\0';
    hanoi(4, 'x', 'y', 'z', buffer);
    printf("%s", buffer);
    // const char* out =
    //     "x -> z\nx -> y\nz -> y\nx -> z\ny -> x\ny -> z\nx -> z\nx -> y\nz ->
    //     " "y\nz -> x\ny -> x\nz -> y\nx -> z\nx -> y\nz -> y\n";
    // ASSERT_STR_EQUAL(out, buffer);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
