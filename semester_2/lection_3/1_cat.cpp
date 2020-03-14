#include <iostream>
#include <string>

using namespace std;

class ITag {
  virtual ~ITag() = default;
};

class Food {
 public:
  int healing_power = 0;
  const string name = "Food";

  Food(int hp, const string& name) : healing_power(hp), name(name) {}
};

class Wiskas : public Food {
 public:
  Wiskas(int hp) : Food(hp, "Wiskas") {}
};

class Fish : public Food {
 public:
  Fish(int hp) : Food(hp, "Fish") {}
};

class Animal {
 public:
  Animal() {
    cout << "New Animal" << endl;
  }
  virtual void Eat(const Food& f) = 0;
  virtual void MakeSound() const {
    cout << "SILENCE" << endl;
  }
  virtual ~Animal() {
    cout << "Destroy Animal" << endl;
  };
};

class Cat : public Animal {
 public:
  Cat() {
    cout << "New Cat" << endl;
  }
  ~Cat() {
    cout << "Destroy Cat" << endl;
  }

  void MakeSound() const {
    cout << "Nya" << endl;
  }

  void Eat(const Food& f) {
    cout << "Cat eats " << f.name << ". " << f.healing_power << "hp." << endl;
  }
};

class Dog : public Animal {
 public:
  void MakeSound() const {
    cout << "Bark" << endl;
  }

  void Eat(const Food& f) {
    cout << "Dog eats " << f.name << ". " << f.healing_power << "hp." << endl;
  }
};

void Feeder(Animal& a, Food& f) {
  a.Eat(f);
}

void Sounder(Animal& a) {
  // cout << "DANGER!!" << endl;
  // Cat* c = static_cast<Cat*>(&a);
  // c->MakeSound();
  // cout << "FUF proneslo" << endl;
  a.MakeSound();
}

void test1() {
  Wiskas w(42);
  Fish f(10);
  Cat c;
  Dog d;

  // Food* f1 = new Wiskas(42);

  // c.Nya();
  c.MakeSound();
  Sounder(c);

  Feeder(c, w);
  Feeder(c, f);
  // c.Eat(w);
  // c.Eat(f);

  // d.Bark();
  d.MakeSound();
  Sounder(d);
  // d.Eat(f);
  // d.Eat(w);
  Feeder(d, f);
  Feeder(d, w);
}

int main() {
  // test1();

  Animal* a = new Cat();
  // a->Test();
  delete a;
}
