#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintLecture(const string& title, int duration) {
  cout << "Title: " << title << ", duration: " << duration << endl;
}

void PrintLectureWithAuthor(const string& title, int duration,
                            const string& author) {
  cout << "Title: " << title << ", duration: " << duration
       << ", author: " << author << endl;
}

void PrintLectures(const vector<string>& titles, const vector<int>& durations

) {
  assert(titles.size() == durations.size());

  for (int i = 0; i < titles.size(); i++) {
    PrintLecture(titles[i], durations[i]);
  }
}

void PrintLecturesWithAuthor(const vector<string>& titles,
                             const vector<int>& durations,
                             const vector<string>& authors) {
  assert(titles.size() == durations.size());
  assert(titles.size() == authors.size());

  for (int i = 0; i < titles.size(); i++) {
    PrintLectureWithAuthor(titles[i], durations[i], authors[i]);
  }
}

int main() {
  PrintLecture("C Structs", 120);
  PrintLecture("C++ Classes", 120);

  PrintLectures({"hello", "world"}, {60, 100});

  PrintLecturesWithAuthor({"aaaa", "bbb"}, {60, 100}, {"007", "006"});

  return 0;
}
