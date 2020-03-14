/**
 * Наследование в С++ это способ выразить связь между классами.
 * Что один объект является другим (яблоко является фрутом).
 *
 * Пусть есть мир, в котором есть животные и фрукты. Животные могут есть фрукты.
 * Реализуем первый вариант - есть яблоки и апельсины и кошка, которая их есть.
 **/

#include <iostream>

using namespace std;

struct Apple {  // структура Яблоко
  int health = 10;
};
struct Orange {  // структура Апельсин
  int health = 5;
};
class Cat {  // создаём класс Кошка
 public:
  void Meow() const {  // кошка может мяукать
    cout << "meow! ";
  }
  void Eat(const Apple& a) {  // кошка может есть яблоко
    cout << "Cat eats apple. " << a.health << "hp." << endl;
  }

  // void Eat(const Orange& o) { // кошка может есть апельсин
  //   cout << "Cat eats orange. " << o.health << "hp." << endl;
  // }
};

class Dog;  // TODO: implement

class Fruit;  // TODO: create abstract class and inherit objects from it

class Animal;  // TODO: implement

void DoMeal(Animal& a, Fruit& f) {
  // a.Eat(f); // TODO: implement
  // a.type += "*"; // TODO: should fail
}

int main() {
  Cat c;
  c.Meow();
  Apple a;
  c.Eat(a);
  Orange o;
  // c.Eat(o); // ERROR!
  return 0;
}
