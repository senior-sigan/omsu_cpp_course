#include <stdio.h>  // подключаем библиотеку для работы с вводом-выводом

#include "test.h"

#define N 10  // фиксируем размер массива, как константу

struct Statistics {
  float average;  // среднее значение для массива
  float min;      // минимальный элемент массива
  float max;      // максимальный элемент массива
};

// calculate_stats - считает статистики для массива array размера N.
// Возвращает экземпляр структуры Statistics
struct Statistics calculate_stats(float array[N]) {
  struct Statistics stats;
  // Напиши меня!

  stats.average = array[0];  // удали меня
  stats.min = array[0];      // удали меня
  stats.max = array[0];      // удали меня

  return stats;
}

// cli_interface запускает взаимодействие с пользователем через
// Command Line Interface.
void cli_interface() {
  // TODO: запросите у пользователя ввести N чисел через консоль.
  // TODO: посчитайте статистики для введеных чисел с функцией calculate_stats.
  // TODO: выведите красиво в консоль статистики
  // Hint: используйте функции printf и scanf
}

void test() {
  // Это тесты. НЕ УДАЛЯЙТЕ ИХ!
  // Преподаватель будет грустить, если вы удалите тесты T_T.
  // Тесты проверяют, что ваш код работает правильно.
  // Если задача решена неправильно,
  // то в консоли вы увидите ошибку и пояснение.
  // Сдавайте лабу, когда устраните все ошибки в тестах.
  // Если возникли трудности, то попросите преподавателя вам помочь ^_^.

  {
    float arr[N] = {9, 5, 4, 2, 3, 8, 1, 7, 6, 0};
    struct Statistics stats = calculate_stats(arr);
    ASSERT_FLOAT_EQUAL(0, stats.min, EPSILON);
    ASSERT_FLOAT_EQUAL(9, stats.max, EPSILON);
    ASSERT_FLOAT_EQUAL(4.5, stats.average, EPSILON);
  }

  {
    float arr[N] = {83.63762547116762, 59.7404308793394,   88.56366146285735,
                    94.95738795228912, 35.91895308410527,  66.31052703948284,
                    74.8657942792011,  16.718124733641883, 13.607911539449347,
                    22.978433790876608};
    struct Statistics stats = calculate_stats(arr);
    ASSERT_FLOAT_EQUAL(13.607911539449347, stats.min, EPSILON);
    ASSERT_FLOAT_EQUAL(94.95738795228912, stats.max, EPSILON);
    ASSERT_FLOAT_EQUAL(55.72988502324106, stats.average, EPSILON);
  }
}

int main(void) {
  // Ничего не меняйте в этой функции.
  test();
  cli_interface();
  return 0;
}
