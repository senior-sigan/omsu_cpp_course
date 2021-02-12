#pragma once

#include <iostream>
#include <stdexcept>  // для std::logic_error

/**
 * Алгоритм Евклида.
 * Находит наибольший общий делитель для двух чисел.
 *
 * Пример: gcd(3, 6) == 3
 *
 * @param a
 * @param b
 * @return int наибольший общий делитель
 */
int gcd(int a, int b);

class Fraction {
 private:
  // private можно не писать, так как по умолчанию поля и методы класса
  // приватные здесь я написал, чтобы явно обозначить приватную секцию класса
  int numerator_;    // числитель
  int denominator_;  // знаменатель

 public:
  // далее идут публичные поля и методы класса

  /**
   * Конструирует экземпляр Дроби.
   *
   * Инвариант:
   * - Числитель - целое число.
   * - Знаменатель - целое число строго больше 0.
   * - Если знаменатель 0, тогда выбрасывать исключение logic_error.
   * - Если дробь отрицательная, то отрицательным может быть только числитель.
   * Знаменатель всегда положительный!
   * - Если дробь равна 0, то числитель равен 0, а знаменатель 1.
   * - Дробь несократима (алгоритм Евклида)
   *
   * @param numerator числитель дроби
   * @param denominator знаменатель дроби
   */
  Fraction(int numerator, int denominator);

  /**
   * TODO: Оператор кастования в double
   *
   * ```
   * Fraction f(1, 2);
   * std::cout << static_cast<double>(f);
   * // печатает 0.5
   * ```
   *
   * @return double представление дроби в виде числа с плавающей точкой
   */
  operator double() const;

  /**
   * TODO: Функция для read-only доступа к числителю
   * Такие функции называют геттерами
   *
   * @return int
   */
  // TODO: напиши меня! ??? Numerator() ???

  /**
   * TODO: Функция для read-only доступа к знаменателю.
   * Такие функции называют геттерами
   *
   * @return int
   */
  // TODO: напиши меня! ??? Denominator() ???
};

/**
 * Далее определим все операторы для дроби ВНЕ самого класса Fraction.
 * Это интересно по нескольким причинам:
 * - Показать что с++ так можно!
 * - В других языках это называют extention-function, надо знать
 * - Показать явно lhs - left-hand-side и right-hand-side операнды
 * - Иногда так удобнее :)
 */

/**
 * Оператор сравнения на равенство двух дробей
 *
 * Пример использования
 * ```
 * if (Fraction(1, 2) == Fraction(2, 4)) {}
 * ```
 *
 * @param lhs левый операнд
 * @param rhs правый операнд
 * @return true если дроби равны
 * @return false если дроби не равны
 */
bool operator==(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор сравнения на НЕ_равенство двух дробей
 *
 * Кстати, `a != b` эквивалентно `!(a==b)`.
 *
 * @param lhs левый операнд
 * @param rhs правый операнд
 * @return true если дроби не равны
 * @return false если дроби равны
 */
bool operator!=(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор сравнение "Меньше" дробей
 *
 * @param lhs
 * @param rhs
 * @return true если lhs < rhs
 * @return false
 */
bool operator<(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор сравнение "Больше" двух дробей
 *
 * @param lhs
 * @param rhs
 * @return true если lhs > rhs
 * @return false
 */
bool operator>(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор сложения двух дробей.
 *
 * ```
 * Fraction a = Fraction(1, 2) + Fraction(1, 3);
 * assert(a == Fraction(5, 6));
 * ```
 *
 * @param lhs левый операнд
 * @param rhs правый операнд
 * @return Fraction - новый экземпляр правильно дроби, полученной из суммы
 * предыдущих
 */
Fraction operator+(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор вычитания одной дроби из другой
 *
 * @param lhs
 * @param rhs
 * @return Fraction
 */
Fraction operator-(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор умножения двух дробей
 *
 * @param lhs
 * @param rhs
 * @return Fraction
 */
Fraction operator*(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор деления одной дроби на другую
 *
 * @param lhs
 * @param rhs
 * @return Fraction
 */
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

/**
 * Оператор вывода В поток дроби.
 * Используется, чтобы красиво напечатать в консоль дробь.
 * Формат вывода: Числитель/Знаменатель.
 *
 * ```
 * std::cout << Fraction(2, 4) << " " << Fraction(1, 3);
 * // выведет "1/2 1/3"
 * ```
 *
 * @param stream поток вывода, например std::cout
 * @param fraction константная ссылка на дробь, которую нужно напечатать
 * @return std::ostream& ссылка на поток, чтобы можно было стакать вызовы <<
 */
std::ostream& operator<<(std::ostream& stream, const Fraction& fraction) {
  // Тут всё готово. Вам ничего не нужно здесь менять.
  stream << fraction.Numerator() << "/" << fraction.Denominator();
  return stream;
}

/**
 * Оператор ввода из потока дроби.
 * Используется, чтобы считать из консоли.
 * Формат ввода "Числитель Знаменатель"
 *
 *
 * @param stream поток ввода, например std::cin
 * @param fraction ссылка на дробь, которую надо будет "подменить" новосозданной
 * @return std::istream& ссылка на поток, чтобы стакать вызовы
 */
std::istream& operator>>(std::istream& stream, Fraction& fraction);
