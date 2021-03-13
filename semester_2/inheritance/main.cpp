#include <iostream>
#include <string>

using namespace std;

class Food {
 public:
  int hp = -1;
  string type = "__food__";
};

class Fish : public Food {
 public:
  Fish() {
    hp = 42;
    type = "fish";
  }
};

class Meat : public Food {
 public:
  Meat() {
    hp = 60;
    type = "meat";
  }
};

//
class Apple : public Food {
 public:
  Apple() {
    hp = 100500;
    type = "apple";
  }
};
//

class Animal {
  //  protected:
  //   string type = "__animal__";

 public:
  const string type;

  Animal(const string& type_ = "__animal__") : type(type_) {
    cout << "NEW ANIMAL" << endl;
  }

  void Eat(const Food& food) {
    std::cout << type << " eat " << food.type << " hp=" << food.hp << std::endl;
  }

  // virtual void Sound() const {
  //   cout << "__silence__" << endl;
  // }
  virtual void Sound() const = 0;

  virtual ~Animal() {
    cout << "DEL ANIMAL" << endl;
  }
};

class Cat : public Animal {
 public:
  Cat() : Animal("cat") {
    cout << "NEW CAT" << endl;
  }

  ~Cat() {
    cout << "DEL CAT" << endl;
  }

  void Sound() const override {
    std::cout << "Mew" << std::endl;
  }
};

class Dog : public Animal {
 public:
  Dog() : Animal("dog") {
    cout << "NEW DOG" << endl;
  }
  ~Dog() {
    cout << "DEL DOG" << endl;
  }
  void Sound() const override {
    std::cout << "Auf" << std::endl;
  }
};

class Parrot : public Animal {
 private:
  string name;

 public:
  Parrot(const string& name_) : Animal("parrot"), name(name_) {}
  void Sound() const override {
    std::cout << name << " is good" << std::endl;
  }
};

void Feed(Animal& animal, const Food& food) {
  animal.Sound();
  // animal.type += "_";
  animal.Eat(food);
}

int main() {
  Fish fish;
  Meat meat;
  {
    Parrot parrot("Kesha");
    parrot.Sound();
    Feed(parrot, meat);
  }
  {
    Animal* cat = new Cat();
    // Cat cat;
    cat->Sound();
    Feed(*cat, fish);
    Feed(*cat, meat);
    Feed(*cat, Apple());
    delete cat;
  }
  cout << "====" << endl;
  {
    Dog d;
    Animal& dog = d;
    dog.Sound();
    Feed(dog, fish);
    Feed(dog, meat);
    Feed(dog, Apple());
  }

  return 0;
}
