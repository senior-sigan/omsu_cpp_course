#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Lecture {
  string Author;
  string Title;
  int Duration;
};

void PrintLecture(const Lecture& lecture) {
  cout << "Title: " << lecture.Title << ", duration: " << lecture.Duration
       << ", author: " << lecture.Author << endl;
}

void PrintCourse(const vector<Lecture>& course) {
  for (auto& lecture : course) {
    PrintLecture(lecture);
  }
}

Lecture GetCurrentLecture() {
  return {"Hi", "I'm from function", 17};
}

int main() {
  // Создаем структуру на стеке и заполняем ее поля
  Lecture l1;
  l1.Author = "Ilya";
  l1.Title = "C++";
  l1.Duration = 120;
  PrintLecture(l1);

  // Объявление и инициализация всех полей сразу
  Lecture l2 = {"Bogachenko", "Assembly", 120};
  PrintLecture(l2);

  // Создание экземпляра на месте (временный-объект, темпорал)
  PrintLecture({"OMG", "COOL", 42});

  // Пример создание экземпляра в функции
  PrintLecture(GetCurrentLecture());

  // Создание на куче
  Lecture* lptr = new Lecture{"HIP", "K-POP", 777};
  PrintLecture(*lptr);
  delete lptr;

  return 0;
}
