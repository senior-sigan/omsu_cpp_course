#include <stdio.h>

struct Animal {
  const char* name;
  void (*say)(struct Animal*);
};

// struct AnimalDummy {
//   const char* name;
//   int type;
// };

// void AnimalSay(struct AnimalDummy* animal) {
//   if (animal->type == 0) {
//     // cat
//   } else if (animal->type == 1) {
//     // dog
//   } else {
//     // error
//   }
// }

// struct Animal {
//   const char* name;

//   virtual void say() = 0;
// }

void cat_say(struct Animal* this) {
  printf("Nya %s", this->name);
}

void dog_say(struct Animal* this) {
  printf("Woof %s", this->name);
}

struct Animal NewCat(const char* name) {
  struct Animal cat;
  cat.name = name;
  cat.say = cat_say;
  return cat;
}

struct Animal NewDog(const char* name) {
  struct Animal dog;
  dog.name = name;
  dog.say = dog_say;
  return dog;
}

void play_with_animal(struct Animal* animal) {
  animal->say(animal);
}

int main() {
  struct Animal cat = NewCat("Neko");
  struct Animal dog = NewDog("Doge");

  play_with_animal(&cat);
  printf("\n");
  play_with_animal(&dog);

  return 0;
}
