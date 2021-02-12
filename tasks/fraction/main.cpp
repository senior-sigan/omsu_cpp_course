#include <iostream>
#include <sstream>
#include <stdexcept>

#include "fraction.h"
#include "test.h"

/**
 * Этот файл трогать не нужно.
 * Тут просто куча тестов.
 * Можете добавить свои, но удалять эти нельзя.
 *
 * Ваше решение должно быть в файле fraction.h
 *
 */

void TestInvariant() {
  {
    Fraction f;
    ASSERT_EQ(f.Numerator(), 0, "numerator must be zero");
    ASSERT_EQ(f.Denominator(), 1, "denominator must be one");
  }
  {
    // non-const getters
    Fraction f(13, 17);
    ASSERT_EQ(f.Numerator(), 13, "numerator getter");
    ASSERT_EQ(f.Denominator(), 17, "denominator getter");
  }
  {
    // const getters
    const Fraction f(1, 2);
    ASSERT_EQ(f.Numerator(), 1, "numerator getter");
    ASSERT_EQ(f.Denominator(), 2, "denominator getter");
  }
  {
    const Fraction f(1, -2);
    ASSERT_EQ(f.Numerator(), -1, "numerator must be negative");
    ASSERT_EQ(f.Denominator(), 2, "denominator must be positive");
  }
  {
    const Fraction f(3, 9);
    ASSERT_EQ(f.Numerator(), 1, "numerator must be optimized");
    ASSERT_EQ(f.Denominator(), 3, "denominator must be optimized");
  }

  {
    const Fraction f(0, 10);
    ASSERT_EQ(f.Numerator(), 0, "numerator must be zero");
    ASSERT_EQ(f.Denominator(), 1, "denominator must be one");
  }

  {
    try {
      const Fraction f(3, 0);
      ASSERT(false,
             "Конструктор должен выбросить исключение std::logic_error, если "
             "знаменатель ноль");
    } catch (std::logic_error& err) {
      // nothing to do. OK!
      ASSERT(true, "Поймали исключение - успех!");
    }
  }
}

void TestComparisonOperators() {
  ASSERT(Fraction(1, 3) < Fraction(1, 2), "1/3 < 1/2");
  ASSERT(Fraction(1, 2) > Fraction(1, 3), "1/2 > 1/3");
  ASSERT(Fraction(2, 4) > Fraction(1, 3), "1/2 > 1/3");
  ASSERT(Fraction(1, 2) == Fraction(2, 4), "1/2 == 2/4");
  ASSERT(Fraction(1, 2) != Fraction(2, 1), "1/2 != 2/1");
}

void TestSum() {
  ASSERT_EQ(Fraction(1, 2) + Fraction(1, 2), Fraction(1, 1), "1/2 + 1/2 == 1/1");
  ASSERT_EQ(Fraction(1, 3) + Fraction(1, 2), Fraction(5, 6), "1/2 + 1/3 == 5/6");
  ASSERT_EQ(Fraction(3, -9) + Fraction(-1, -3), Fraction(0, 1), "-3/9 + 1/3 == 0");

  {
    Fraction sum = Fraction(1, 2) + Fraction(1, 3);
    ASSERT_EQ(sum, Fraction(5, 6), "1/2 + 1/3 == 5/6");
  }
}

void TestSub() {
  ASSERT_EQ(Fraction(3, 9) - Fraction(1, 3), Fraction(0, 1), "3/9 - 1/3 == 0/1");
  ASSERT_EQ(Fraction(1, -3) - Fraction(1, 2), Fraction(-5, 6), "-1/2 - 1/3 == -5/6");
}

void TestMul() {
  ASSERT_EQ(Fraction(3, 9) * Fraction(1, 3), Fraction(1, 9), "3/9 * 1/3 == 1/9");
  ASSERT_EQ(Fraction(1, -3) * Fraction(1, 2), Fraction(-1, 6), "-1/2 - 1/3 == -5/6");
  ASSERT_EQ(Fraction(3, 2) * Fraction(4, 6), Fraction(1, 1), "3/2 * 4/6 == 1/1");
}

void TestCastToDouble() {
  ASSERT_EQ_FLOAT(static_cast<double>(Fraction(1, 2)), 0.5, "1/2 == 0.5");
  {
    double x = Fraction(1, 2);
    ASSERT_EQ_FLOAT(x, 0.5, "1/2 == 0.5");
  }
}

void TestInputStreamOperator() {
  Fraction f1;
  Fraction f2;
  std::stringstream ss("1 2 3 6");
  ss >> f1 >> f2;
  ASSERT_EQ(Fraction(1, 2), f1, "1 2 input as 1/2");
  ASSERT_EQ(Fraction(1, 2), f1, "3 6 input as 1/2");
}

void TestOutputStreamOperator() {
  {
    Fraction f(1, 5);
    std::stringstream ss;
    ss << f;
    ASSERT_EQ("1/5", ss.str(), "Fraction(1, 5) prints like 1/5");
  }

  {
    Fraction f;
    std::stringstream ss;
    ss << f;
    ASSERT_EQ("0/1", ss.str(), "Fraction() prints like 0/1");
  }

  {
    Fraction f(2, -4);
    std::stringstream ss;
    ss << f;
    ASSERT_EQ("-1/2", ss.str(), "Fraction(2, -4) prints like -1/2");
  }
}

int main() {
  SETUP_TESTS();

  RUN_TEST(TestInvariant);
  RUN_TEST(TestComparisonOperators);
  RUN_TEST(TestSum);
  RUN_TEST(TestSub);
  RUN_TEST(TestMul);
  RUN_TEST(TestCastToDouble);
  RUN_TEST(TestInputStreamOperator);
  RUN_TEST(TestOutputStreamOperator);
  return 0;
}
