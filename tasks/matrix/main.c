#include "test.h"

struct Matrix {
  int columns;
  int rows;
  int** values;
};

/**
 * Выделяет память на матрицу размера columns на rows.
 * Заполняет матрицу числами, которые генерирует функция value.
 *
 * Если входные параметры некорректные, то должна вернуть NULL.
 *
 * @param columns количество колонок
 * @param rows количество строк
 * @param value функция, которая возвращает значение ячейки (i,j)
 * @return указатель на первую ячейку матрицы
 */
struct Matrix* alloc_matrix(int columns, int rows, int (*value)(int, int)) {
  // TODO: напиши меня!
  return NULL;
}

void free_matrix(struct Matrix* matrix) {
  // TODO: напиши меня!
  // 1. удалите двумерный массив values
  // 2. удалите саму структуру matrix
}

void cli(void) {
  /**
   * 1. Запросите у пользователя columns и rows для матрицы.
   * 2. Запросите у пользователя функцию заполнения матрицы из списка: eye,
   * zeros, mul, check.
   * 3. Примените функцию alloc_matrix
   * 4. Выведите красиво в консоль полученную матрицу
   * 5. Очистите память с помощью функции free_matrix
   */
}

int eye(int i, int j) { return i == j; }
int zeros(__attribute__((unused)) int i, __attribute__((unused)) int j) {
  // __attribute__((unused)) - маркер для компилятора, чтобы сказать, что да,
  // действительно, этот аргумент не используется.
  // https://clang.llvm.org/docs/AttributeReference.html#maybe-unused-unused
  return 0;
}
int mul(int i, int j) { return i * j; }
int check(int i, int j) { return (i + j) % 2; }

void test(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  {
    struct Matrix* m = alloc_matrix(3, 3, zeros);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ASSERT_INT(0, ==, m->values[i][j]);
      }
    }
    free_matrix(m);
  }
  {
    struct Matrix* m = alloc_matrix(3, 3, eye);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ASSERT_INT(eye(i, j), ==, m->values[i][j]);
      }
    }
    free_matrix(m);
  }
  {
    struct Matrix* m = alloc_matrix(3, 3, mul);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ASSERT_INT(mul(i, j), ==, m->values[i][j]);
      }
    }
    free_matrix(m);
  }
  {
    struct Matrix* m = alloc_matrix(3, 3, check);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        ASSERT_INT(check(i, j), ==, m->values[i][j]);
      }
    }
    free_matrix(m);
  }
  {
    struct Matrix* m = alloc_matrix(-1, 3, zeros);
    ASSERT_PTR_EQUAL(NULL, m);
  }
  {
    struct Matrix* m = alloc_matrix(1, -3, zeros);
    ASSERT_PTR_EQUAL(NULL, m);
  }
  {
    struct Matrix* m = alloc_matrix(3, 3, NULL);
    ASSERT_PTR_EQUAL(NULL, m);
  }
  {
    struct Matrix* m = alloc_matrix(0, 0, zeros);
    ASSERT_PTR_EQUAL(NULL, m);
  }
}

int main(void) {
  test();
  cli();
  return 0;
}
