/*
 * Простая библиотека тестирования для Си
 * Не надо менять этот файл, он хороший.
 *
 * Пример использования:
 *   ASSERT_INT(42, ==, 42);
 *   ASSERT_INT(3, >, -1);
 *   ASSERT_DOUBLE_EQUAL(3.14, 3.1399999999, EPSILON);
 */
#include <stdio.h>   // подключаем printf
#include <string.h>  // подключаем сравнение строк

#define EPSILON \
  0.0000001  // точность по-умолчанию для сравнения числе с плавающей точкой

#define ASSERT_ANY(T, fmt, expected, op, actual)                            \
  do {                                                                      \
    const T expected_ = (expected);                                         \
    const T actual_ = (actual);                                             \
    if (!(expected_ op actual_)) {                                          \
      printf("ERROR> %s:%d: expected %s %s %s, got %" fmt " %s %" fmt "\n", \
             __FILE__, __LINE__, #expected, #op, #actual, expected_, #op,   \
             actual_);                                                      \
    }                                                                       \
  } while (0)

#define ASSERT_UINT(expected, op, actual) \
  ASSERT_ANY(unsigned int, "u", expected, op, actual)

#define ASSERT_INT(expected, op, actual) \
  ASSERT_ANY(int, "d", expected, op, actual)

#define ASSERT_LONG(expected, op, actual) \
  ASSERT_ANY(long, "ld", expected, op, actual)

#define ASSERT_ULONG(expected, op, actual) \
  ASSERT_ANY(unsigned long, "ld", expected, op, actual)

#define ASSERT_CHAR(expected, op, actual) \
  ASSERT_ANY(char, "c", expected, op, actual)

#define ASSERT_UCHAR(expected, op, actual) \
  ASSERT_ANY(unsigned char, "d", expected, op, actual)

#define ASSERT_TRUE(actual)                                               \
  do {                                                                    \
    if (!(actual)) {                                                      \
      printf("ERROR> %s:%d: assertion failed: " #actual " is not true\n", \
             __FILE__, __LINE__);                                         \
    }                                                                     \
  } while (0)

#define ASSERT_FALSE(actual)                                               \
  do {                                                                     \
    if (!!(actual)) {                                                      \
      printf("ERROR> %s:%d: assertion failed: " #actual " is not false\n", \
             __FILE__, __LINE__);                                          \
    }                                                                      \
  } while (0)

#define ASSERT_ALMOST_EQUAL(T, fmt, expected, actual, precision)            \
  do {                                                                      \
    const T expected_ = (expected);                                         \
    const T actual_ = (actual);                                             \
    const T precision_ = (precision);                                       \
    const T diff = expected_ - actual_;                                     \
    if ((diff >= 0 && diff > precision_) || (-diff > precision_)) {         \
      printf("ERROR> %s:%d: expected %s == %s, got %" fmt " == %" fmt "\n", \
             __FILE__, __LINE__, #expected, #actual, expected_, actual_);   \
    }                                                                       \
  } while (0)

#define ASSERT_FLOAT_EQUAL(expected, actual, precision) \
  ASSERT_ALMOST_EQUAL(float, "f", expected, actual, precision)

#define ASSERT_DOUBLE_EQUAL(expected, actual, precision) \
  ASSERT_ALMOST_EQUAL(double, "f", expected, actual, precision)

#define ASSERT_STR_EQUAL(expected, actual)                                \
  do {                                                                    \
    const char* expected_ = expected;                                     \
    const char* actual_ = actual;                                         \
    if (strcmp(expected_, actual_) != 0) {                                \
      printf("ERROR> %s:%d: expected %s == %s, got %s == %s\n", __FILE__, \
             __LINE__, #expected, #actual, expected_, actual_);           \
    }                                                                     \
  } while (0)
