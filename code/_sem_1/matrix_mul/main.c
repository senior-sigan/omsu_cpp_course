#include <stdio.h>

#include "test.h"

#define L 3
#define M 4
#define N 2

static int c[L][N];

// matmul - матричное произведение двух матриц.
// формула: https://ru.wikipedia.org/wiki/Умножение_матриц
// Результат произведения нужно положить в глобальную переменную c;
// PS: обычно, глобальные переменные для такого не используют,
// но здесь мы так делаем, чтобы не начинать тему про указатели.
// Функции в си не могу вернуть двумерный массив.
void matmul(int a[L][M], int b[M][N]) {
  // TODO: напиши меня!
  c[0][0] = a[0][0] * b[0][0];  // удали меня
}

void cli(void) {
  // 1. Введите матрицы через консоль.
  // 2. Напечататйте красиво в консоль результат произведения матриц.
  // TODO: напиши меня

  // int a[L][M];
  // int b[M][N];
  printf("Введите матрицы A[%d][%d] и B[%d][%d].\n", L, M, M, N);
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

  if (L == 3 && N == 2 && M == 4) {
    {
      int c_res[L][N] = {{50, 60}, {114, 140}, {110, 140}};
      int a[L][M] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}};
      int b[M][N] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
      matmul(a, b);
      for (int i = 0; i < L; i++) {
        for (int j = 0; j < N; j++) {
          ASSERT_INT(c_res[i][j], ==, c[i][j]);
        }
      }
    }
  }
}

int main(void) {
  test();
  cli();
  return 0;
}