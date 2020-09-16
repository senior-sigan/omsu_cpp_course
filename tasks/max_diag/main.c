#include <stdio.h>

#include "test.h"

#define N 3  // это число может поменяться!

// max_diag - считает сумму всех диагоналей, параллельных главной диагонали.
// Среди всех сумм диагоналей, выбирает максимальную и возвращает как результат.
int max_diag(int matrix[N][N]) {
  // TODO: напиши меня!
  // hint: сколько у нас диагоналей?
  return matrix[0][0];
}

void cli(void) {
  // 1. введите матрицу через консоль
  // 2. напечатайте результат вызова функции max_diag.
  printf("Введине матрицу A[%d][%d]\n", N, N);
  // hint: используйте scanf и printf
}

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  if (N == 3) {
    {
      int a[N][N] = {{8, 1, 1}, {1, 0, 1}, {1, 1, 0}};
      ASSERT_INT(8, ==, max_diag(a));
    }

    {
      int a[N][N] = {{1, 1, 4}, {1, 1, 1}, {1, 1, 1}};
      ASSERT_INT(4, ==, max_diag(a));
    }

    {
      int a[N][N] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
      ASSERT_INT(3, ==, max_diag(a));
    }
  }
}

int main(void) {
  test();
  cli();
}