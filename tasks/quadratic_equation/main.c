#include "test.h"

// Solution - это структура, которая хранит в себе набор решений квадратного
// уравнения. Если решений уравнение нет, то n_solutions = 0, а содержимое x1 и
// x2 неопределено. Если решения уравнения одно, то n_solutions = 1 и x1==x2
// == единственному решению. Если решений два, то n_solutions = 2, в x1 лежит
// решение, полученное вычитанием дискриминанта, в x1 лежит решение, полученное
// прибавлением дискриминанта
struct Solution {
  int n_solutions;  // количество решений. Ноль, 1 или 2
  float x1;         // первый корень уравнения
  float x2;         // второй корень уравнения
};

// quadratic_equation - находит корни квадратного уравнения a*x*x + b*x + c = 0.
// где
struct Solution quadratic_equation(float a, float b, float c) {
  struct Solution solution;

  // напиши меня!
  solution.n_solutions = -1;  // удали меня!
  solution.x1 = a * b * c;    // удали меня!
  solution.x2 = a * b * c;    // удали меня!

  return solution;
}

int main(void) {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  struct Solution solution;

  solution = quadratic_equation(1, 2, -3);
  ASSERT_INT(2, ==, solution.n_solutions);
  ASSERT_FLOAT_EQUAL(-3.0, solution.x1, EPSILON);
  ASSERT_FLOAT_EQUAL(1.0, solution.x2, EPSILON);

  solution = quadratic_equation(3, 4, 1);
  ASSERT_INT(2, ==, solution.n_solutions);
  ASSERT_FLOAT_EQUAL(-1.0, solution.x1, EPSILON);
  ASSERT_FLOAT_EQUAL(-1.0 / 3.0, solution.x2, EPSILON);

  solution = quadratic_equation(1, 0, -9);
  ASSERT_INT(2, ==, solution.n_solutions);
  ASSERT_FLOAT_EQUAL(-3.0, solution.x1, EPSILON);
  ASSERT_FLOAT_EQUAL(3.0, solution.x2, EPSILON);

  solution = quadratic_equation(1, -4, 4);
  ASSERT_INT(1, ==, solution.n_solutions);
  ASSERT_FLOAT_EQUAL(2.0, solution.x1, EPSILON);
  ASSERT_FLOAT_EQUAL(2.0, solution.x2, EPSILON);

  solution = quadratic_equation(1, 1, 3);
  ASSERT_INT(0, ==, solution.n_solutions);

  solution = quadratic_equation(0, 2, 1);
  ASSERT_INT(1, ==, solution.n_solutions);
  ASSERT_FLOAT_EQUAL(-0.5, solution.x1, EPSILON);
  ASSERT_FLOAT_EQUAL(-0.5, solution.x2, EPSILON);

  return 0;
}
