#include "test.h"

#define N 8  // это число может поменяться
#define M 3  // это число может поменяться

struct Result {
  int sum;  // сумма абсолютных значений лементов строки матрицы
  int row_idx;  // индекс строки матрицы
};

// max_sum_odd_matrix_rows
// - находи те строки, которые содержат только нечетные элементы;
// - считает сумму абсолютные значений элементов этих строк;
// - находит максимальную сумму
// - возвращает эму сумму и номер строки, которой она принадлежит
// Hints:
// - результатом может быть только неотрицательное число.
// - напишите функцию для подсчета суммы элементов строки массива,
// а если в строке есть хоть одно четное значение, то верните -1,
// как код ошибки.
// - находите максимум на лету, не создавайте промежуточный массив
struct Result max_sum_odd_matrix_rows(int matrix[N][M]) {
  // TODO: напиши меня!
  // код ниже можно менять как угодно
  struct Result result;
  result.sum = matrix[0][0];  // исправь меня
  restrict.row_idx = -1;      // исправь меня
  return result;
}

void cli(void) {
  // 1. Введите матрицы через консоль.
  // 2. Напечататйте в консоль результат работы max_sum_odd_matrix_rows
  // TODO: напиши меня

  // int m[N][M];
  printf("Введите матрицу размера [%d][%d].\n", N, M);
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

  // !!!!!!!!!!!!!!!!!!!!!!!
  // ХМ, а почему бы в этот раз не вам написать тесты?
  // Обязательно напишите пару тестов!
}

int main(void) {
  test();
  cli();
  return 0;
}
